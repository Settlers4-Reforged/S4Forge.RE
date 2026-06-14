#include "CGameHost.h"

#include "CBB/CBBSupport.h"
#include "CClassNetGameIniBuffer.h"
#include "CMsgStacks.h"
#include "CSimpleNet.h"
#include "Debug/CTrace.h"
#include "Defines/Game.h"
#include "Defines/Translations.h"
#include "File/CFile.h"
#include "File/FilePaths.h"
#include "File/MapFilePaths.h"
#include "File/PathSplitResult.h"
#include "Framework.h"
#include "LoadSave/CGameChunkGeneral.h"
#include "Logic/Events/CNet_Event.h"
#include "Logic/Events/IEventEngine.h"
#include "Main/CGameSettings.h"
#include "Main/CGameStateHandler.h"
#include "Main/Players/CPlayerManager.h"
#include "OnlineManager.h"

// Definitions for class CGameHost

#pragma pack(1)
struct SSync0Message {
    unsigned int m_iCurrentTick;
    char m_iPlayerId;
};
static_assert(sizeof(SSync0Message) == 5, "SSync0Message has incorrect size");

#pragma pack(1)
struct CGameHost::SMessage {
    unsigned short m_iId;
    CNet_Event m_cEvent;
    BYTE m_iData[994];

    SMessage() : m_cEvent(0, 0, 0, 0, 0, 0, 0) {
        m_iId = 0;
        memset(m_iData, 0, sizeof(m_iData));
    }
};
static_assert(sizeof(CGameHost::SMessage) == 0x404, "CGameHost::SMessage has incorrect size");

#pragma pack(1)
struct CGameHost::SSimpleMessage {
    unsigned short m_iId;
    int m_iTick;
};
static_assert(sizeof(CGameHost::SSimpleMessage) == 6, "CGameHost::SSimpleMessage has incorrect size");

#pragma pack(1)
struct CGameHost::SSearchMessage {
    __int16 m_iMessageId;
    wchar_t m_swpGameName[32];
    wchar_t m_swpMapName[256];
    DWORD m_iMapCRC;
    DWORD m_iFileSize;
    _BYTE m_uByte261;
    _BYTE gap_24B[3];
    DWORD m_iActualPlayerCount;
    DWORD m_iHumanPlayers;
    BYTE m_iLenString298;
    _BYTE gap_257[3];
    DWORD m_iMultiPlayerGameId;
    DWORD m_iMPSavegameId;
    bool m_bIsSaveGame;
    _BYTE gap_263[3];
    DWORD m_uiTickCounter;
    BYTE m_uExtraFlags;
    bool bIsAutosave;
    _BYTE gap_26C[406];
};
static_assert(sizeof(CGameHost::SSearchMessage) == 0x402, "CGameHost::SSearchMessage has incorrect size");

#pragma pack(1)
struct CGameHost::SJoinMessage {
    wchar_t m_swPlayerName[31];
    WORD field_3E;
    BYTE m_bU0;
    DWORD m_iPeerId;
    DWORD m_iVersionMS;
    DWORD m_iVersionLS;
    DWORD m_iVersionConfig;
    DWORD m_iVersionScript;
    DWORD m_iVersionGfx;
    _BYTE gap_59[4];
    bool m_bIsWebGame;
    bool m_bDownloadMap;
    BYTE field_5F;
    BYTE field_60;
    _BYTE gap_61[3];
    char m_iRequestedSlot;
};
static_assert(sizeof(CGameHost::SJoinMessage) == 0x65, "CGameHost::SJoinMessage has incorrect size");

#pragma pack(1)
struct CGameHost::SPingMessage {
    char m_iPlayerId;
    int m_iDelta;
};
static_assert(sizeof(CGameHost::SPingMessage) == 5, "CGameHost::SPingMessage has incorrect size");

#pragma pack(1)
struct CGameHost::SChatLineMessage {
    wchar_t m_swpName[32];
    wchar_t m_swpChatLine[96];
};
static_assert(sizeof(CGameHost::SChatLineMessage) == 0x100, "CGameHost::SChatLineMessage has incorrect size");

#pragma pack(1)
struct CGameHost::SMapMessage {
    unsigned short m_iId;
    int m_iChunkId;
    BYTE m_iMapData[1022];
};
static_assert(sizeof(CGameHost::SMapMessage) == 0x404, "CGameHost::SMapMessage has incorrect size");

#pragma pack(1)
struct CGameHost::SChangeMessage {
    int m_iSlot;
    int m_iType;
    int m_iTarget;
};
static_assert(sizeof(CGameHost::SChangeMessage) == 0xC, "CGameHost::SChangeMessage has incorrect size");

#pragma pack(1)
struct CGameHost::SSyncMessage {
    int m_iCurrentTick;
    unsigned int m_iSyncData; // (m_iSyncData >> 4) & 0xF is player id and m_iSyncData & 0xF is expected msg count
};
static_assert(sizeof(CGameHost::SSyncMessage) == 8, "CGameHost::SSyncMessage has incorrect size");

#pragma pack(1)
struct CGameHost::SSync0Message {
    int m_iCurrentTick;
    char m_iPlayerId;
};
static_assert(sizeof(CGameHost::SSync0Message) == 5, "CGameHost::SSync0Message has incorrect size");

#pragma pack(1)
struct CGameHost::SMessageBuffer {
    unsigned short m_iId;
    _DWORD m_uFlags;
    BYTE m_uPlayerMap;
    unsigned int m_uTick;
    _BYTE m_vMessages[961];
};
static_assert(sizeof(CGameHost::SMessageBuffer) == 0x3cc, "CGameHost::SMessageBuffer has incorrect size");

#pragma pack(1)
struct CGameHost::SMapDownloadBlock {
    int m_iId;
    BYTE m_vData[768];
};
static_assert(sizeof(CGameHost::SMapDownloadBlock) == 0x304, "CGameHost::SMapDownloadBlock has incorrect size");

// address=[0x415B888]
CStaticConfigVarInt g_iHostWaitAfterLobbyForClientsTimeout{ "NETWORK", "HostWaitAfterLobbyForClientsTimeout", 45000 };
// address=[0x415B870]
CStaticConfigVarInt g_iNetAfterLobbyConnectTimeout{ "NETWORK", "AfterLobbyConnectTimeout", 45000 };
// address=[0x415B804]
CStaticConfigVarInt g_iNetClientTimeOut{ "NETWORK", "ClientTimeOut", 12000 };
// address=[0x415B87C]
CStaticConfigVarInt g_iNetClientWaitingStartTick{ "NETWORK", "ClientWaitingStartTickTimeout", 45000 };
// address=[0x415B828]
CStaticConfigVarInt g_iNetReceiverPort{ "NETWORK", "ReceiverPort", 3000 };
// address=[0x415B810]
CStaticConfigVarInt g_iNetSearchHostRetries{ "NETWORK", "SearchHostRetries", 1 };
// address=[0x415B81C]
CStaticConfigVarInt g_iNetSenderPort{ "NETWORK", "SenderPort", 3000 };
// address=[0x415B864]
CStaticConfigVarInt g_iNetworkTimeDelta{ "NETWORK", "NetworkTimeDelta", 800 };
// address=[0x415B858]
CStaticConfigVarInt g_iNotReadyGameStartTimeout{ "NETWORK", "NotReadyGameStartTimeout", 45000 };
// address=[0x415B84C]
CStaticConfigVarInt g_iNotReadyKickDelay{ "NETWORK", "NotReadyKickDelay", 20000 };
// address=[0x415B840]
CStaticConfigVarInt g_iNotReadyWarnAgainDelay{ "NETWORK", "NotReadyWarnAgainDelay", 2500 };
// address=[0x415B834]
CStaticConfigVarInt g_iNotReadyWarnDelay{ "NETWORK", "NotReadyWarnDelay", 6000 };
// address=[0x415B8AC]
CStaticConfigVarInt g_iPingAverage{ "NETWORK", "PingAverage", 750 };
// address=[0x415B8A0]
CStaticConfigVarInt g_iPingGood{ "NETWORK", "PingGood", 250 };
// address=[0x415B894]
CStaticConfigVarInt g_iResendTimeout{ "NETWORK", "ResendTimeout", 4000 };
// address=[0x415B8B8]
CStaticConfigVarInt g_iSaveingTimeout{ "NETWORK", "SaveingTimeout", 30000 };
// address=[0x415AD78]
CStaticConfigVarInt g_iProductID{ "GENERAL", "ProductID", 3 };

// address=[0x04030720]
std::wstring g_swPlayerName;

// address=[0x14aab10]
// Decompiled from int __thiscall CGameHost::GetBytesPerSecond(CGameHost *this)
unsigned int CGameHost::GetBytesPerSecond(void) {

    if(this->m_pSimpleNet)
        return this->m_pSimpleNet->GetBytesPerSecond();
    else
        return 0;
}

// address=[0x15b4e60]
// Decompiled from char __thiscall CGameHost::AllSend(CGameHost *this)
bool CGameHost::AllSend(void) {
    int iCurrentTick;        // [esp+10h] [ebp-14h] MAPDST BYREF
                             // [esp+14h] [ebp-10h]
    BYTE *pMessageBufferPtr; // [esp+18h] [ebp-Ch]

    BB_ASSERT(m_pMsgStacks)
    BB_ASSERT(m_pClientList)

    if((COMMUNICATION_TICK_VALUE & g_pEvnEngine->GetCurrentTickCounter()) != 0)
        return true;
    if(!this->m_vNetEvents.size()) {
        SSync0Message sSync0Msg{};
        sSync0Msg.m_iPlayerId = CPlayerManager::GetLocalPlayerId();
        sSync0Msg.m_iCurrentTick = g_pEvnEngine->GetCurrentTickCounter();
        if(this->m_bIsOnlineGame)
            CGameHost::SendToAll(1055, reinterpret_cast<short *>(&sSync0Msg), sizeof(sSync0Msg), 0, 0, true);
        this->m_pMsgStacks->SetNumberOfExpectedMsgs(g_pEvnEngine->GetCurrentTickCounter(), CPlayerManager::GetLocalPlayerId() - 1, 0);
        return true;
    }

    int LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    this->m_sBuffer.m_uPlayerMap = (LocalPlayerId - 1) & 0xF | this->m_sBuffer.m_uPlayerMap & 0xF0;
    this->m_sBuffer.m_iId = 1054;
    this->m_sBuffer.m_uTick = g_pEvnEngine->GetCurrentTickCounter();
    int iMessagesInBuffer = 0;
    pMessageBufferPtr = this->m_sBuffer.m_vMessages;
    while(this->m_vNetEvents.size()) {
        CNet_Event &evn = this->m_vNetEvents.front();
        int iOwner = evn.m_iOwner;
        BB_ASSERT(evn.m_iOwner == g_cPlayerMgr.GetLocalPlayerId())
        if(evn.m_iData && (&pMessageBufferPtr[evn.m_iDataSize] >= &this->m_sBuffer.m_vMessages[949] || iMessagesInBuffer == 15)) {
            break;
        }
        evn.m_iTick = this->m_sBuffer.m_uTick;
        this->m_pMsgStacks->PushMsg(evn);
        evn.m_iOwner = 0;
        evn.m_iUnknown = 0;
        evn.m_iMsgNr = 0;
        evn.unk_15 = 0;
        evn.unk_16 = 0;
        evn.unk_17 = 0;
        memcpy(pMessageBufferPtr, &evn, sizeof(CNet_Event)); // TODO: this copies the vtable pointer...
        static_assert(sizeof(CNet_Event) == 0x20u, "CNet_Event has incorrect size");
        pMessageBufferPtr += 32;
        if(evn.m_iData) {
            BB_ASSERT(evn.m_iDataSize);
            memcpy(pMessageBufferPtr, evn.m_iData, evn.m_iDataSize);
            pMessageBufferPtr += evn.m_iDataSize;
            evn.m_iData = 0;
        }
        this->m_vNetEvents.pop_front();
        ++iMessagesInBuffer;
    }
    this->m_sBuffer.m_uFlags = iMessagesInBuffer & 0xF | this->m_sBuffer.m_uFlags & 0xFFFFFFF0;
    char v6 = CPlayerManager::GetLocalPlayerId() - 1;
    int CurrentTickCounter = g_pEvnEngine->GetCurrentTickCounter();
    this->m_pMsgStacks->SetNumberOfExpectedMsgs(CurrentTickCounter, v6, iMessagesInBuffer);
    if(this->m_bIsOnlineGame)
        CGameHost::SendToAll(1054, reinterpret_cast<short *>(&this->m_sBuffer), pMessageBufferPtr - reinterpret_cast<BYTE *>(&this->m_sBuffer), nullptr, 0, true);
    return true;
}

// address=[0x15b51a0]
// Decompiled from char __thiscall CGameHost::StartNewCycle(CGameHost *this, bool a2)
bool CGameHost::StartNewCycle(bool a2) {

    int ValidTick;   // esi
    int v3;          // esi
    int v5;          // esi
    int v6;          // eax
    unsigned int v7; // [esp+4h] [ebp-8h] BYREF

    BB_ASSERT(m_pMsgStacks)
    if(!this->m_pMsgStacks)
        return false;
    if(this->m_bIsOnlineGame) {
        ValidTick = this->m_pMsgStacks->GetValidTick();
        v3 = this->m_pMsgStacks->Getdt() + ValidTick;
        if(v3 > this->m_pMsgStacks->GetVirtualTick()) {
        LABEL_7:
            CGameHost::AllSend();
            this->m_pMsgStacks->AdvanceVirtualTick();
            this->dword40 = 0;
            return false;
        }
    } else {
        v5 = this->m_pMsgStacks->GetValidTick() + 1;
        if(v5 >= this->m_pMsgStacks->GetVirtualTick())
            goto LABEL_7;
    }
    if((COMMUNICATION_TICK_VALUE & this->m_pMsgStacks->GetValidTick()) != 0 && this->m_bIsOnlineGame && (v7 = 0, v6 = CGameHost::GetValidTick(), !this->m_pMsgStacks->IsMsgStackValid(v6 + 1, v7))) {
        CGameHost::NotifyClients(v7);
        return false;
    }
    if(!this->m_pMsgStacks->IsEmpty(0)) {
        BB_REPORT("Internal Error (N0) occured! Aborting...\nInterner Fehler (N0) aufgetreten. Das Programm wird beendet!")
        return false;
    }

    if(!a2)
        return true;

    this->m_pMsgStacks->TriggerTime();
    this->m_pMsgStacks->AdvanceValidTick();
    this->m_pMsgStacks->AdvanceVirtualTick();
    this->dword40 = 0;
    return true;
}

// address=[0x15b5360]
// Decompiled from int __thiscall CGameHost::GetValidTick(CGameHost *this)
int CGameHost::GetValidTick(void) {

    return this->m_pMsgStacks->GetValidTick();
}

// address=[0x15b5380]
// Decompiled from int __thiscall CGameHost::GetVirtualTick(CGameHost *this)
int CGameHost::GetVirtualTick(void) {

    return this->m_pMsgStacks->GetVirtualTick();
}

// address=[0x15b53a0]
// Decompiled from char __thiscall CGameHost::RegisterMsgStacks(CGameHost *this, struct CMsgStacks *a2)
bool CGameHost::RegisterMsgStacks(class CMsgStacks *a2) {

    if(this->m_pMsgStacks)
        return false;
    this->m_pMsgStacks = a2;
    return true;
}

// address=[0x15b53d0]
// Decompiled from char __thiscall CGameHost::InitAsClient(CGameHost *this, unsigned int a2)
bool CGameHost::InitAsClient(unsigned int a2) {

    BB_ASSERT(this->m_pFSM)

    if(a2)
        this->m_pFSM->Control(1016, 0);
    else
        this->m_pFSM->Control(1008, 0);
    return true;
}

// address=[0x15b5440]
// Decompiled from char __thiscall CGameHost::InitAsHost(CGameHost *this, unsigned int a2)
bool CGameHost::InitAsHost(unsigned int a2) {
    BB_ASSERT(this->m_pFSM)
    if(a2)
        this->m_pFSM->Control(1012, 0);
    else
        this->m_pFSM->Control(1007, 0);
    return true;
}

// address=[0x15b54b0]
// Decompiled from CGameHost *__thiscall CGameHost::CGameHost(CGameHost *this, byte arg0)
CGameHost::CGameHost(bool arg0) : IEventHandler(2000), m_vGameInfos(), m_vNetEvents() {

    char *v2;        // eax
    std::string *v4; // [esp+4h] [ebp-50h]
    _BYTE v10[28];   // [esp+28h] [ebp-2Ch] BYREF
    int v11;         // [esp+50h] [ebp-4h]

    v11 = 0;

    this->m_bHost = false;
    this->m_bClient = false;
    this->m_bIsOnlineGame = arg0;
    this->m_pFSM = 0;
    this->m_pClientList = 0;
    this->m_pMsgStacks = 0;
    this->m_iLastPingTime = 0;
    this->m_iLastLoginTick = 0;
    this->m_iLoginAttempts = 0;
    this->m_iStartTickSignalTick = 0;
    this->m_iInitGameStartTick = 0;
    this->m_bInitFinished = 0;
    this->dword40 = 0;
    this->m_pMapDownloadData = 0;
    this->m_pMapDownloadBlocks = 0;
    this->m_bMapBeingDownloaded = false;
    this->m_bHasSentMap = false;
    this->m_iMapDownloadBlocksArrived = 0;
    this->m_iMapUpload = 0;
    this->dwordBC = 0;
    this->m_iReadyTime = 0;
    this->m_pSimpleNet = 0;
    memset(this->m_iMapUploadSentChunks, 0, sizeof(this->m_iMapUploadSentChunks));
    memset(this->m_iMapUploadChunks, 0, sizeof(this->m_iMapUploadChunks));
    memset(this->m_pMapUploadBuffer, 0, sizeof(this->m_pMapUploadBuffer));
    memset(this->m_iSyncA, 0, sizeof(this->m_iSyncA));
    memset(this->m_iSyncB, 0, sizeof(this->m_iSyncB));
    memset(&this->m_sBuffer, 0, 971u);
    CGameHost::FillHandlersArray();
    this->m_pFSM = new CFsm(this, 1500, 34);
    this->m_pFSM->DefineTransition(34, 1, 1007, T_HOST_HANDLERS::InitHostNetwork);
    this->m_pFSM->DefineTransition(54, 1, 1007, T_HOST_HANDLERS::InitHostNetwork);
    this->m_pFSM->DefineTransition(2, 70, 1060, T_HOST_HANDLERS::InviteAccepted);
    this->m_pFSM->DefineTransition(4, 70, 1060, T_HOST_HANDLERS::InviteAccepted);
    this->m_pFSM->DefineTransition(55, 70, 1060, T_HOST_HANDLERS::InviteAccepted);
    this->m_pFSM->DefineTransition(70, 40, 1024, T_HOST_HANDLERS::ClientLoginHost);
    this->m_pFSM->DefineTransition(70, 5, 1057, T_HOST_HANDLERS::ClientLobbyPrepare);
    this->m_pFSM->DefineTransition(1, 1, 1051, T_HOST_HANDLERS::HostChoseMap);
    this->m_pFSM->DefineTransition(1, 69, 1059, T_HOST_HANDLERS::QuickMatchChoseMap);
    this->m_pFSM->DefineTransition(1, 1, 1000, T_HOST_HANDLERS::DoNothing);
    this->m_pFSM->DefineTransition(1, 3, 1009, T_HOST_HANDLERS::OnHostWait);
    this->m_pFSM->DefineTransition(69, 3, 1009, T_HOST_HANDLERS::OnHostWait);
    this->m_pFSM->DefineTransition(69, 40, 1024, T_HOST_HANDLERS::ClientLoginHost);
    this->m_pFSM->DefineTransition(69, 5, 1057, T_HOST_HANDLERS::ClientLobbyPrepare);
    this->m_pFSM->DefineTransition(3, 3, 1000, T_HOST_HANDLERS::ClientSearchesGameHost);
    this->m_pFSM->DefineTransition(3, 3, 1001, T_HOST_HANDLERS::DoNothing);
    this->m_pFSM->DefineTransition(5, 3, 1058, T_HOST_HANDLERS::DoNothing);
    this->m_pFSM->DefineTransition(3, 3, 1023, T_HOST_HANDLERS::ClientJoins);
    this->m_pFSM->DefineTransition(3, 3, 1027, T_HOST_HANDLERS::ResendPlayerData);
    this->m_pFSM->DefineTransition(3, 3, 1035, T_HOST_HANDLERS::ResendPlayerPing);
    this->m_pFSM->DefineTransition(3, 3, 1036, T_HOST_HANDLERS::ChatLine);
    this->m_pFSM->DefineTransition(3, 3, 1050, T_HOST_HANDLERS::SendChatLine);
    this->m_pFSM->DefineTransition(3, 3, 1047, T_HOST_HANDLERS::ClientLeavesMyGame);
    this->m_pFSM->DefineTransition(3, 3, 1052, T_HOST_HANDLERS::UserDataChange);
    this->m_pFSM->DefineTransition(3, 3, 1053, T_HOST_HANDLERS::KickClient);
    this->m_pFSM->DefineTransition(3, 3, 1056, T_HOST_HANDLERS::UserChangeSlots);
    this->m_pFSM->DefineTransition(3, 3, 1042, T_HOST_HANDLERS::SendMapToClient);
    this->m_pFSM->DefineTransition(3, 3, 1029, T_HOST_HANDLERS::HostPressedStart);
    this->m_pFSM->DefineTransition(3, 15, 1030, T_HOST_HANDLERS::ResendFinalPData);
    this->m_pFSM->DefineTransition(15, 15, 1012, T_HOST_HANDLERS::DoNothing);
    this->m_pFSM->DefineTransition(34, 2, 1008, T_HOST_HANDLERS::InitClientNetwork);
    this->m_pFSM->DefineTransition(54, 2, 1008, T_HOST_HANDLERS::InitClientNetwork);
    this->m_pFSM->DefineTransition(2, 55, 1010, T_HOST_HANDLERS::DoNothing);
    this->m_pFSM->DefineTransition(55, 4, 1046, T_HOST_HANDLERS::SearchHost);
    this->m_pFSM->DefineTransition(55, 40, 1024, T_HOST_HANDLERS::ClientLoginHost);
    this->m_pFSM->DefineTransition(4, 4, 1022, T_HOST_HANDLERS::ClientReceivesGameInfo);
    this->m_pFSM->DefineTransition(4, 4, 1046, T_HOST_HANDLERS::SearchHost);
    this->m_pFSM->DefineTransition(4, 40, 1024, T_HOST_HANDLERS::ClientLoginHost);
    this->m_pFSM->DefineTransition(40, 5, 1025, T_HOST_HANDLERS::ClientLobbyPrepare);
    this->m_pFSM->DefineTransition(40, 5, 1057, T_HOST_HANDLERS::ClientLobbyPrepare);
    this->m_pFSM->DefineTransition(40, 40, 1022, T_HOST_HANDLERS::DoNothing);
    this->m_pFSM->DefineTransition(40, 4, 1038, T_HOST_HANDLERS::GameAlreadyFull);
    this->m_pFSM->DefineTransition(40, 4, 1048, T_HOST_HANDLERS::ClientWrongVersion);
    this->m_pFSM->DefineTransition(5, 5, 1026, T_HOST_HANDLERS::ClientReceivePlayerData);
    this->m_pFSM->DefineTransition(5, 5, 1034, T_HOST_HANDLERS::ClientReceivePlayerPing);
    this->m_pFSM->DefineTransition(5, 5, 1036, T_HOST_HANDLERS::ChatLine);
    this->m_pFSM->DefineTransition(5, 5, 1049, T_HOST_HANDLERS::PerformLeaveGame);
    this->m_pFSM->DefineTransition(5, 5, 1050, T_HOST_HANDLERS::SendChatLine);
    this->m_pFSM->DefineTransition(5, 5, 1053, T_HOST_HANDLERS::WereKicked);
    this->m_pFSM->DefineTransition(5, 5, 1043, T_HOST_HANDLERS::ClientReceiveMap);
    this->m_pFSM->DefineTransition(5, 20, 1032, T_HOST_HANDLERS::InitGameStruct);
    this->m_pFSM->DefineTransition(20, 20, 1032, T_HOST_HANDLERS::InitGameStruct);
    this->m_pFSM->DefineTransition(34, 14, 1012, T_HOST_HANDLERS::InitHostAfterLobby);
    this->m_pFSM->DefineTransition(14, 15, 1009, T_HOST_HANDLERS::WaitingForGameConnect);
    this->m_pFSM->DefineTransition(15, 15, 1013, T_HOST_HANDLERS::WaitingForGameConnect);
    this->m_pFSM->DefineTransition(15, 18, 1014, T_HOST_HANDLERS::HostInitGame);
    this->m_pFSM->DefineTransition(18, 30, 1020, T_HOST_HANDLERS::HostGameInited);
    this->m_pFSM->DefineTransition(18, 18, 1018, T_HOST_HANDLERS::HostGameInited);
    this->m_pFSM->DefineTransition(30, 30, 1018, T_HOST_HANDLERS::HostGameInited);
    this->m_pFSM->DefineTransition(30, 30, 1039, T_HOST_HANDLERS::GameAsyncMsgGot);
    this->m_pFSM->DefineTransition(30, 17, 1015, T_HOST_HANDLERS::HostStartTick);
    this->m_pFSM->DefineTransition(34, 20, 1016, T_HOST_HANDLERS::InitClientAfterLobby);
    this->m_pFSM->DefineTransition(20, 10, 1031, T_HOST_HANDLERS::RegClientConnect);
    this->m_pFSM->DefineTransition(20, 10, 1010, T_HOST_HANDLERS::RegClientConnect);
    this->m_pFSM->DefineTransition(10, 10, 1048, T_HOST_HANDLERS::ClientWrongVersionAfterLobby);
    this->m_pFSM->DefineTransition(10, 10, 1045, T_HOST_HANDLERS::RegClientConnect);
    this->m_pFSM->DefineTransition(10, 11, 1033, T_HOST_HANDLERS::WereConnectedForGame);
    this->m_pFSM->DefineTransition(11, 25, 1017, T_HOST_HANDLERS::ClientStartingGame);
    this->m_pFSM->DefineTransition(25, 27, 1020, T_HOST_HANDLERS::ClientGameInited);
    this->m_pFSM->DefineTransition(27, 17, 1019, T_HOST_HANDLERS::ClientStartTick);
    this->m_pFSM->DefineTransition(27, 17, 1040, T_HOST_HANDLERS::ClientStartTick);
    this->m_pFSM->DefineTransition(27, 27, 1039, T_HOST_HANDLERS::GameAsyncMsgGot);
    this->m_pFSM->DefineTransition(17, 17, 1021, T_HOST_HANDLERS::GameInGameMsgGot);
    this->m_pFSM->DefineTransition(17, 17, 1005, T_HOST_HANDLERS::GameSyncMsgGot);
    this->m_pFSM->DefineTransition(17, 17, 1055, T_HOST_HANDLERS::GameSync0MsgGot);
    this->m_pFSM->DefineTransition(17, 17, 1039, T_HOST_HANDLERS::GameAsyncMsgGot);
    this->m_pFSM->DefineTransition(17, 17, 1040, T_HOST_HANDLERS::AmIStillAlive);
    this->m_pFSM->DefineTransition(17, 17, 1041, T_HOST_HANDLERS::HeIsStillAlive);
    this->m_pFSM->DefineTransition(17, 17, 1054, T_HOST_HANDLERS::GameInGamePackedGot);

    CLanLobby::SetGameHost(this);

    this->m_iInitTime = 0;
    this->m_pClientList = new CClientList();
    this->m_bHasError = false;
    if(!this->m_bIsOnlineGame)
        return;

    this->m_pSimpleNet = CreateSimpleNet();
    if(this->m_pSimpleNet) {
        if(this->m_pSimpleNet->WasError()) {
            BBSupportTracePrintF(3, "GameHost.cpp: %s!", this->m_pSimpleNet->GetLastErrorString().c_str());
            this->m_bHasError = true;
            return;
        }
    }

    BBSupportTracePrint(3, "GameHost.cpp: Error initializing Network!");
    this->m_bHasError = true;
}

// address=[0x15b5ed0]
// Decompiled from int __thiscall CGameHost::~CGameHost(CGameHost *this)
CGameHost::~CGameHost(void) {
    delete this->m_pMsgStacks;
    this->m_pMsgStacks = 0;

    delete this->m_pClientList;
    this->m_pClientList = 0;

    delete this->m_pFSM;
    this->m_pFSM = 0;

    delete[] this->m_pMapDownloadBlocks;
    this->m_pMapDownloadBlocks = 0;

    delete[] this->m_pMapDownloadData;
    this->m_pMapDownloadData = 0;

    if(this->m_pSimpleNet) {
        this->m_pSimpleNet->Delete(); // TODO: refactor
        this->m_pSimpleNet = 0;
    }
    for(int i = 0; i < 8; ++i) {
        delete[] this->m_pMapUploadBuffer[i];
        this->m_pMapUploadBuffer[i] = 0;
    }
}

// address=[0x15b60d0]
// Decompiled from char __thiscall CGameHost::PushMsg(CGameHost *this, struct CNet_Event *_rMsg)
bool CGameHost::PushMsg(class CNet_Event &_rMsg) {
    if(_rMsg.m_iData && !_rMsg.m_iDataSize)
        BB_REPORT("Fatal: m_iData set, but m_iDataSize == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?")

    if(CPlayerManager::IsAI(_rMsg.m_iOwner))
        return this->m_pMsgStacks->PushMsg(_rMsg);

    BB_ASSERT(_rMsg.m_iOwner == g_cPlayerMgr.GetLocalPlayerId())

    this->m_vNetEvents.push_back(_rMsg);
    return true;
}

// address=[0x15b6190]
// Decompiled from void __thiscall CGameHost::PushAsyncMsg(CGameHost *this, CNet_Event *_rEvent, unsigned __int8 _iPlayerMap)
void CGameHost::PushAsyncMsg(class CNet_Event &_rEvent, unsigned char _iPlayerMap) {

    // eax
    // [esp-18h] [ebp-458h]
    // [esp-Ch] [ebp-44Ch]
    // [esp+8h] [ebp-438h]
    ; // [esp+Ch] [ebp-434h] BYREF

    CTrace::Print("GameHost.cpp: Sending Async Msg to those Players: %x", _iPlayerMap);
    if(this->m_bIsOnlineGame && !CPlayerManager::IsAI(_rEvent.m_iOwner)) {
        for(int i = 1; i <= CPlayerManager::LastPlayerId(); ++i) {
            if(!CPlayerManager::IsAI(i) && CPlayerManager::GetLocalPlayerId() != i && ((1 << (i - 1)) & _iPlayerMap) != 0) {
                CGameHost::SMessage sMessage{};
                sMessage.m_iId = 1039;
                memcpy(&sMessage.m_cEvent, &_rEvent, sizeof(sMessage.m_cEvent));
                memcpy(sMessage.m_iData, _rEvent.m_iData, _rEvent.m_iDataSize);
                size_t iMessageSize = _rEvent.m_iDataSize + 34;
                unsigned int iIp = CPlayerManager::IP(i);
                unsigned int iPeerId = CPlayerManager::PeerId(i);
                this->m_pSimpleNet->PushMessage(iPeerId, iIp, 3105u, &sMessage, iMessageSize, 1, 1);
                CTrace::Print("GameHost.cpp: Delivering Async Msg to Owner %d!", i);
            }
        }
    }
    if((_iPlayerMap & (1 << (CPlayerManager::GetLocalPlayerId() - 1))) != 0) {
        CEvn_Logic v9 = CEvn_Logic(
            _rEvent.m_iEventId,
            _rEvent.m_wParam,
            _rEvent.m_lParam,
            _rEvent.m_iOwner,
            reinterpret_cast<unsigned int>(_rEvent.m_iData),
            _rEvent.m_iDataSize);

        g_pEvnEngine->SendAMessage(v9);
    }
}

// address=[0x15b63b0]
// Decompiled from int __thiscall CGameHost::PopMsg(CGameHost *this, int a2)
class CNet_Event CGameHost::PopMsg(void) {
    return this->m_pMsgStacks->PopMsg();
}

// address=[0x15b63f0]
// Decompiled from int __thiscall CGameHost::GetLocalIP(CGameHost *this)
long CGameHost::GetLocalIP(void) {
    return this->m_pSimpleNet->GetCurrentLocalIPLong();
}

// address=[0x15b6420]
// Decompiled from int __thiscall CGameHost::GetMessageLength(CGameHost *this)
unsigned short CGameHost::GetMessageLength(void) {
    return this->m_pSimpleNet->GetLastDataLength() - 2;
}

// address=[0x15b6450]
// Decompiled from void __thiscall CGameHost::GameInitalized(CGameHost *this)
void CGameHost::GameInitalized(void) {
    if(this->m_bIsOnlineGame) {
        this->m_pFSM->Control(1020, 0);
    } else {
        CEvn_Event v1(0x19u, 0, 0, 0);
        g_pEvnEngine->SendAMessage(v1);
    }
}

// address=[0x15b64f0]
// Decompiled from void __thiscall CGameHost::ContinueSearchForHost(CGameHost *this)
void CGameHost::ContinueSearchForHost(void) {
    this->m_iSearchForHostStopped = 0;
}

// address=[0x15b6510]
// Decompiled from char __thiscall CGameHost::Run(CGameHost *this)
bool CGameHost::Run(void) {

    char *v1;               // eax
                            // eax
                            // eax
    std::string *v16;       // [esp+20h] [ebp-9A0h]
    _BYTE v20[32];          // [esp+36h] [ebp-98Ah] BYREF
    _BYTE v22[32];          // [esp+43Ah] [ebp-586h] BYREF
    _BYTE v23[28];          // [esp+83Ch] [ebp-184h] BYREF
    CHAR OutputString[256]; // [esp+8B0h] [ebp-110h] BYREF

    if(!this->m_pFSM || !this->m_bHost && !this->m_bClient)
        return true;
    CGameHost::DeliverSimpleMessage();
    if(!this->m_pSimpleNet->Run()) {
        CTrace::Print("GameHost.cpp: %s!", this->m_pSimpleNet->GetLastErrorString().c_str());
    }
    if(this->m_bHost) {
        for(unsigned int i = 0; i < g_pGameType->m_iActualPlayerCount; ++i) {
            if(g_pGameType->m_sPlayerPeerId[i] == -1)
                continue;
            OnlineManager *pOnlineManager = (OnlineManager *)OnlineManager::GetInstance();
            if(pOnlineManager->IsInSession() && g_pGameType->m_sPlayerPeerId[i] == -1) // TODO: -1 was StormManager::GetLocalPeerId(v3)
                continue;

            if(this->m_iSyncB[i] <= 20)
                continue;

            float fAverageSync = static_cast<float>(this->m_iSyncA[i]) / static_cast<float>(this->m_iSyncB[i]);
            sprintf(OutputString, "fAverageSync %f\n", fAverageSync);
            OutputDebugStringA(OutputString);
            if(fAverageSync >= 3.0) {
                if(fAverageSync > this->m_pMsgStacks->GetNumberOfStacks() / 2.0f + 1) {
                    CNet_Event cEvent(0xFA7u, 0x23u, 0, 0, 0, 0, g_pEvnEngine->GetCurrentTickCounter());
                    // Network event id is 1039
                    memcpy(v20, &cEvent, sizeof(v20)); // is also size of cEvent
                    CTrace::Print("GameHost.cpp: Restrain player index %u, IP %s!", i, this->m_pSimpleNet->GetIPString(g_pGameType->m_uiIPPlayer[i]));
                    // TODO: probably removed in HE
                }
            } else {
                CNet_Event cEvent(0xFA7u, 0xFFFFFFDD, 0, 0, 0, 0, g_pEvnEngine->GetCurrentTickCounter());
                memcpy(v22, &cEvent, sizeof(v22));
                CTrace::Print("GameHost.cpp: Boosting player index %u, IP %s!", i, this->m_pSimpleNet->GetIPString(this->m_pSimpleNet, g_pGameType->m_uiIPPlayer[i]));
                // TODO: probably removed in HE
            }
            this->m_iSyncB[i] = 0;
            this->m_iSyncA[i] = 0;
        }
    }
    if(this->m_pFSM->CurrentState() == 10) {
        if(!this->m_iLastLoginTick)
            this->m_iLastLoginTick = timeGetTime();
        DWORD iNextLoginTick = this->m_iLastLoginTick + 1000;
        if(iNextLoginTick < timeGetTime()) {
            this->m_pFSM->Control(1045, reinterpret_cast<void *>(1));
            ++this->m_iLoginAttempts;
            CTrace::Print("GameHost.cpp: Resending login after lobby request!");
            this->m_iLastLoginTick = timeGetTime();
            if(this->m_iLoginAttempts > g_iNetAfterLobbyConnectTimeout / 1000u) {
                CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, reinterpret_cast<void *>(2408));
                CGameStateHandler::Switch(CStateMainMenu::DynamicCreateFunc, nullptr);
            }
        }
    }
    if(this->m_pFSM->CurrentState() == 40) {
        DWORD v9 = this->m_iNotReadyTimeoutTick + g_iNotReadyGameStartTimeout;
        if(v9 < timeGetTime()) {
            CEvn_Event cEvent = CEvn_Event(0xFA1u, 0, 0, 0);
            g_pEvnEngine->SendAMessage(cEvent);
            this->m_iNotReadyTimeoutTick = timeGetTime();
        }
    }
    if((this->m_pFSM->CurrentState() == 30 || this->m_pFSM->CurrentState() == 18) && this->m_iInitTime) {
        if(g_pGameType->GetNumberHumanPlayers() <= 1) {
            this->m_pFSM->Control(1015, 0);
        } else {
            DWORD v10 = this->m_iInitTime + g_iNotReadyGameStartTimeout;
            if(v10 < timeGetTime()) {
                CTrace::Print("GameHost.cpp: One or more clients r not ready for game. Starting it due to timeout!");
                this->m_pFSM->Control(1015, 0);
            }
        }
    }
    if(this->m_pFSM->CurrentState() == 27) {
        if(!this->m_iStartTickSignalTick)
            this->m_iStartTickSignalTick = timeGetTime();
        DWORD v11 = this->m_iStartTickSignalTick + g_iNetClientWaitingStartTick;
        if(v11 < timeGetTime()) {
            CTrace::Print("GameHost.cpp: No start tick signal from host got. Starting due to timeout!");
            this->m_pFSM->Control(1019, 0);
        }
    }
    if(this->m_pFSM->CurrentState() == 15) {
        if(!this->m_iInitGameStartTick)
            this->m_iInitGameStartTick = timeGetTime();
        int Size = this->m_pClientList->GetSize();
        if(Size == g_pGameType->HumanPlayers() - 1) {
            this->m_pFSM->Control(1014, 0);
        } else {
            DWORD v13 = this->m_iInitGameStartTick + g_iHostWaitAfterLobbyForClientsTimeout;
            if(v13 < timeGetTime()) {
                CTrace::Print("GameHost.cpp: One or more clients missing after lobby. Initing game due to timeout!");
                this->m_pFSM->Control(1014, 0);
            }
        }
    }
    if(this->m_bClient)
        CGameHost::OnClientRun();
    else
        CGameHost::OnHostRun();
    return false;
}

// address=[0x014971C0]
wchar_t *__cdecl MyWStrNCopy(wchar_t *_swpDst, wchar_t const *_swpSrc, unsigned int _uSize) {
    // [esp+Ch] [ebp-4h]
    // [esp+20h] [ebp+10h]

    if(_uSize == 0 || _swpDst == 0)
        return _swpDst;
    unsigned int v5 = _uSize - 1;
    unsigned int v4 = 0;
    if(*_swpSrc) {
        while(v4 < v5 && _swpSrc[v4]) {
            _swpDst[v4] = _swpSrc[v4];
            ++v4;
        }
    }
    _swpDst[v4] = 0;
    return _swpDst;
}

#define READ_ERROR(stage) "Error (" stage ") reading internet game description file! File seems to be damaged!\n"                           \
                          "Please try again!\n\n\n"                                                                                         \
                          "Fehler (" stage ") beim Einlesen der Internetspiel-Verbindungsdatei. Die Datei ist möglicherweise beschädigt!\n" \
                          "Bitte versuchen Sie es erneut!"

// address=[0x15b6c60]
// Decompiled from char __thiscall CGameHost::StartIniFileGame(CGameHost *this, wchar_t *Source)
bool CGameHost::StartIniFileGame(wchar_t const *Source) {
    // TODO: replace with c++ std::string and views...
    wchar_t Filename[260];
    GetModuleFileNameW(nullptr, Filename, sizeof(Filename));
    wchar_t Drive[4];
    wchar_t Dir[256];
    wchar_t Ext[256];
    _wsplitpath(Filename, Drive, Dir, nullptr, Ext);
    GetCurrentDirectoryW(0x200u, Dir); // NOTE: why even bother with _wsplitpath?
    MyWStrNCopy(Filename, Dir, sizeof(Filename));
    wcscat(Filename, L"/");
    wcscat(Filename, Source);

    CFile cFile{};
    cFile.Open(Filename, CFile::CFile_TEXT | CFile::CFile_READ, CFileLog);

    unsigned int uFileSize = cFile.Size();
    char *pBuffer = new char[uFileSize + 128];
    memset(pBuffer, 0, sizeof(pBuffer));

    cFile.Read(pBuffer, uFileSize, 1, CFileLog);
    cFile.Close(CFileLog);

    CClassNetGameIniBuffer cIni(pBuffer, sizeof(pBuffer));

    int iGameId = cIni.GetIntValue("GameID", -1);
    if(iGameId == -1) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <GameID>!");
        BB_REPORT(READ_ERROR("I1"))
    }

    wchar_t swpGameName[256]; // [esp+1A48h] [ebp-21Ch] BYREF
    int iFoundAt = cIni.GetWStringValue("GameName", swpGameName);
    if(iFoundAt == -1) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <GameName>!");
        BB_REPORT(READ_ERROR("I2"))
    }
    std::wstring swGameName = swpGameName;
    // I3 was skipped, due to new WStringValue
    int iSaveGame = cIni.GetIntValue("SaveGame", -1);
    bool bIsSaveGame = iSaveGame == 1;
    if(iSaveGame == -1) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <SaveGame>!");
        BB_REPORT(READ_ERROR("I2"))
    }
    g_pGameType->m_bIsSaveGame = bIsSaveGame;

    bool bIsLadderGame = cIni.GetIntValue("IsLadderGame", -1) == 1;
    bool bIsClanGame = cIni.GetIntValue("IsClanGame", -1) == 1;

    wchar_t swpMapName[256];
    iFoundAt = cIni.GetWStringValue("MapName", swpMapName);
    if(iFoundAt == -1) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <MapName>!");
        BB_REPORT(READ_ERROR("I3"))
    }
    std::wstring swMapName = swpMapName;

    if(g_pGameType->IsSaveGame()) {
        std::wstring swMPGameName;
        CGameType::ConvertMapNameToMPGameName(&swMPGameName, &swMapName);
        swMPGameName += L".sav";
        CGameChunkGeneral sGeneralInfo{};
        if(!CGameRun::LoadGeneralInfo(swMPGameName.c_str(), sGeneralInfo)) {
            CTrace::Print(
                "GameHost.cpp: Internet game ini file malformed after phase <MapName>, can't load %s!",
                swMPGameName.c_str());

            BB_REPORT("The desired map file could not be loaded!\n"
                      "Die gewünschte Karte konnte nicht geladen werden!")
        }
        std::wstring swSaveFilePath;
        SaveFilePath::BuildSaveFilePath(&swSaveFilePath, &swMPGameName);
        CGameRun::FillGameType(&swSaveFilePath, g_pGameType, &sGeneralInfo);
    } else {
        g_pGameType->m_swMapName = swMapName;
        if(!g_pGameType->LoadMapData(
               g_pGameType->m_swMapName,
               0,
               0,
               1,
               1,
               0,
               -1,
               -1,
               bIsLadderGame,
               bIsClanGame)) {
            BB_REPORT("The desired map file could not be loaded!\n"
                      "Die gewünschte Karte konnte nicht geladen werden!")
        }
        g_pGameType->m_swGameName = swGameName;
    }

    g_pGameType->SetLadderGame(bIsLadderGame);
    g_pGameType->SetClanGame(bIsClanGame);

    int iProductId = cIni.GetIntValue("ProductId", -1);
    if(iProductId == -1) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <ProductID>!");
        BB_REPORT(READ_ERROR("I6"))
    }
    if(iProductId != g_iProductID) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase! Wrong Product ID %d!", iProductId);
        BB_REPORT(READ_ERROR("I7"))
    }
    g_pGameType->m_iMode = cIni.GetIntValue("GameMode", -1);
    if(g_pGameType->m_iMode == -1) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <GameMode>!");
        BB_REPORT(READ_ERROR("I8B"))
    }
    if(g_pGameType->m_iMode <= MODE_NONE || g_pGameType->m_iMode >= MODE_MAX) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed! invalid game mode %d!", g_pGameType->m_iMode);
        BB_REPORT(READ_ERROR("I9B"))
    }

    g_pGameType->m_iStartResources = cIni.GetIntValue("Resources", -1) + 1;
    if(g_pGameType->m_iStartResources == -1) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <Resources>!");
        BB_REPORT(READ_ERROR("I8C"))
    }
    if(g_pGameType->m_iStartResources < 1 || g_pGameType->m_iStartResources > 3) {
        // NOTE: previously an incorrect log format, fixed here...
        CTrace::Print("GameHost.cpp: Internet game ini file malformed! invalid start resources %d!", g_pGameType->m_iStartResources);
        BB_REPORT(READ_ERROR("I9C"))
    }

    int iTeams = cIni.GetIntValue("NumberOfTeams", -1);
    if(iTeams == -1) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <NumOfTeams>!");
        BB_REPORT(READ_ERROR("I8A"))
    }
    if(g_pGameType->m_iMode != MODE_COOP)
        g_pGameType->m_uiNumberAlliances = iTeams;
    if(g_pGameType->m_uiNumberAlliances < 2u || g_pGameType->m_uiNumberAlliances > 8u) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed! Too many Teams %d", g_pGameType->m_uiNumberAlliances);
        BB_REPORT(READ_ERROR("I9A"))
    }

    int iPlayerCount = cIni.GetIntValue("NumberOfPlayers", -1);
    if(iPlayerCount == -1) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <NumberOfPlayers>!");
        BB_REPORT(READ_ERROR("I8"))
    }
    if(!g_pGameType->IsSaveGame() && (bIsClanGame || g_pGameType->byte36C && g_pGameType->byte36B))
        g_pGameType->m_iActualPlayerCount = iPlayerCount;
    else
        g_pGameType->m_iActualPlayerCount = g_pGameType->m_iMapMaxNumPlayers;
    if(g_pGameType->m_iMode != MODE_COOP)
        g_pGameType->m_iMapMaxNumPlayers = g_pGameType->m_iActualPlayerCount;
    if(g_pGameType->m_iActualPlayerCount < 2u || g_pGameType->m_iActualPlayerCount > MAX_PLAYER) {
        CTrace::Print(
            "GameHost.cpp: Internet game ini file malformed! Too many players %d",
            g_pGameType->m_iActualPlayerCount);
        BB_REPORT(READ_ERROR("I9"))
    }
    int iIsTrojan = cIni.GetIntValue("IsTronJan", -1);
    if(iIsTrojan != -1) {
        g_pGameType->m_uExtraFlags |= iIsTrojan;
        g_uiExtrasAllowed = g_pGameType->m_uExtraFlags;
    }

    std::wstring vPlayerNames[MAX_PLAYER + 1];
    unsigned int vIPs[MAX_PLAYER + 1];
    for(int i = 0; i < iPlayerCount; ++i) {
        char swpPlayerKey[512];
        sprintf(swpPlayerKey, "PlayerIP%d", i);

        char spPlayerBuffer[512];
        wchar_t swpPlayerBuffer[256];
        iFoundAt = cIni.GetStringValue(swpPlayerKey, spPlayerBuffer);
        if(iFoundAt == -1) {
            CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerIP%d>!", i);
            BB_REPORT(READ_ERROR("I10"))
        }

        vIPs[i] = this->m_pSimpleNet->GetIPLong(spPlayerBuffer);
        if(!g_pGameType->IsSaveGame())
            g_pGameType->m_uiIPPlayer[i] = vIPs[i];

        sprintf(swpPlayerKey, "PlayerName%d", i);
        iFoundAt = cIni.GetWStringValue(swpPlayerKey, swpPlayerBuffer);
        if(iFoundAt == -1) {
            CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerID%d>!", i);
            BB_REPORT(READ_ERROR("I20"))
        }
        vPlayerNames[i] = swpPlayerBuffer;

        sprintf(swpPlayerKey, "PlayerID%d", i);
        g_pGameType->m_sPlayerPeerId[i] = cIni.GetIntValue(swpPlayerKey, -1);
        if(g_pGameType->m_sPlayerTeam[i] >= g_pGameType->m_uiNumberAlliances)
            g_pGameType->m_sPlayerTeam[i] = static_cast<unsigned int>(i) % g_pGameType->m_uiNumberAlliances;

        if(g_pGameType->IsClanGame()) {
            sprintf(swpPlayerKey, "ClanShortcut%d=", i);
            iFoundAt = cIni.GetWStringValue(swpPlayerKey, swpPlayerBuffer);
            if(iFoundAt == -1) {
                CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerIP%d>!", i);
                BB_REPORT(READ_ERROR("I10"))
            }
            g_pGameType->SetPlayerClanShortcut(i, swpPlayerBuffer);
        }
    }

    int iLocalSlot = cIni.GetIntValue("LocalSlot", -1);
    if(iLocalSlot >= MAX_PLAYER)
        iLocalSlot = -1;
    if(iLocalSlot < 0) {
        for(int i = 0; i < iPlayerCount; ++i) {
            if(this->m_pSimpleNet->IsLocalIP(vIPs[i])) {
                iLocalSlot = i;
                break;
            }
        }
    } else {
        this->m_pSimpleNet->SetAdditionalLocalAddress(vIPs[iLocalSlot]);
    }

    if(iLocalSlot >= 0 && vPlayerNames[iLocalSlot].length() > 0) {
        CGameSettings::SetPlayerName(vPlayerNames[iLocalSlot]);
    }

    g_pGameType->m_iHostAddress = vIPs[0];
    if(iLocalSlot == 0) {
        g_pGameType->SetHost(true);
        if(g_pGameType->IsSaveGame()) {
            g_pGameType->m_uiIPPlayer[g_pGameType->GetLocalSlot()] = vIPs[0];
        }
    }

    if(g_pGameType->m_iMode == MODE_COOP)
        g_pGameType->m_iActualPlayerCount = g_pGameType->m_iMapMaxNumPlayers;
    char spSessionId[256];
    iFoundAt = cIni.GetStringValue("SessionID", spSessionId);
    if(iFoundAt == -1) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <SessionID>!");
        BB_REPORT(READ_ERROR("I14"))
    }
    g_pGameType->m_sSessionId = spSessionId;

    char spProcServer[512];
    iFoundAt = cIni.GetStringValue("ProcedureServer", spProcServer);
    if(iFoundAt == -1) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <ProcedureServer>!");
        BB_REPORT(READ_ERROR("I16"))
    }
    g_pGameType->m_sProcedureServer = spProcServer;
    int iProcPort = cIni.GetIntValue("ProcedureServerPort", -1);
    if(iProcPort == -1) {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <ProcedureServerPort>!");
        BB_REPORT(READ_ERROR("I17"))
    }
    g_pGameType->m_iProcedureServerPort = iProcPort;

    CTrace::Print("GameHost.cpp: Host is %s", this->m_pSimpleNet->GetIPString(g_pGameType->m_iHostAddress));
    g_pGameType->m_iHumanPlayers = 0;
    if(g_pGameType->IsClanGame())
        g_pGameType->byte36B = 0;
    for(int j = 0; j < g_pGameType->m_iActualPlayerCount; ++j) {
        char swpPlayerKey[512];
        sprintf(swpPlayerKey, "PlayerTeam%d=", j);
        int iPlayerTeam = cIni.GetIntValue(swpPlayerKey, -1);
        if(iPlayerTeam >= 0) {
            g_pGameType->m_sPlayerTeam[j] = iPlayerTeam;
        }
    }

    for(int i = 0; i < g_pGameType->m_iActualPlayerCount; ++i) {
        if(g_pGameType->field_3EF[i])
            g_pGameType->m_sPlayerRaces[i] = 0;
        if(!g_pGameType->m_sPlayerType[i])
            ++g_pGameType->m_iHumanPlayers;
    }

    g_pGameType->m_iGameType = 2;
    g_pGameType->SetWebGame(true);
    if(this->m_pSimpleNet->IsLocalIP(g_pGameType->m_iHostAddress)) {
        pGameHost->m_bClient = false;
        pGameHost->m_bHost = true;
        this->m_pFSM->Control(1007, 0);
        this->m_pFSM->Control(1051, 0);
    } else {
        Sleep(0x7D0u);
        struct SGameInfo sGameInfo{};
        memset(&sGameInfo, 0, sizeof(sGameInfo));
        sGameInfo.m_bMapAvailable = 1;
        sGameInfo.m_bU2 = 0;
        sGameInfo.m_iMapCRC = g_pGameType->m_iMapCRC;
        sGameInfo.m_iPlayerCount = g_pGameType->m_iActualPlayerCount;
        MyWStrNCopy(sGameInfo.m_swpMapName, g_pGameType->m_swMapName.c_str(), 512);
        sGameInfo.m_iMaxPlayerCount = g_pGameType->m_iActualPlayerCount;
        sGameInfo.m_iFileSize = g_pGameType->m_iFileSize;
        sGameInfo.m_iStartTime = timeGetTime();
        MyWStrNCopy(sGameInfo.m_swpGameName, g_pGameType->m_swGameName, 64);
        sGameInfo.m_iHostAddress = g_pGameType->m_iHostAddress;
        sGameInfo.m_iIsSaveGame = g_pGameType->IsSaveGame();
        sGameInfo.m_bIsAutosave = g_pGameType->bIsAutosave;
        sGameInfo.m_uTickCounter = g_pGameType->m_uiTickCounter;
        sGameInfo.m_iGameId = g_pGameType->GetMultiPlayerGameID();
        sGameInfo.m_iSavegameId = g_pGameType->GetMPSavegameID();
        this->AddGame(sGameInfo);
        this->m_bClient = true;
        this->m_bHost = false;
        this->m_pFSM->Control(1008, 0);
        this->m_pFSM->Control(1024, 0);
    }

    int iFlagsError = CStateLobbyGameSettings::CompileUserFlags();
    if(iFlagsError) {
        BB_REPORTF("CompileUserFlags() reported error %d!", iFlagsError)
    }

    BB_ASSERT(false) // dont ask...
}

// address=[0x15b88c0]
// Decompiled from void __thiscall CGameHost::PingClients(CGameHost *this)
void CGameHost::PingClients(void) {
    DWORD v1; // esi

    if(!this->m_iLastPingTime || (v1 = this->m_iLastPingTime + 1000, v1 < timeGetTime())) {
        DWORD Time = timeGetTime();
        CGameHost::SSimpleMessage sPingMessage{}; // [esp+4h] [ebp-1Ch] BYREF
        sPingMessage.m_iId = 3;
        sPingMessage.m_iTick = Time;
        for(signed int i = 0;; ++i) {
            int Size = this->m_pClientList->GetSize();
            if(i >= Size)
                break;
            unsigned int PlayerIP = this->m_pClientList->GetPlayerIP(i);
            unsigned int PlayerPeerId = this->m_pClientList->GetPlayerPeerId(i);
            this->m_pSimpleNet->PushMessage(PlayerPeerId, PlayerIP, 3105, &sPingMessage, 6, 0, 1);
        }
        this->m_iLastPingTime = timeGetTime();
    }
}

// address=[0x15b8990]
// Decompiled from void __thiscall CGameHost::DeliverSimpleMessage(CGameHost *this)
void CGameHost::DeliverSimpleMessage(void) {
    int v3;                    // eax
    int LocalPeerId;           // esi
    OnlineManager *v8;         // eax
    int HostPeerId;            // eax
    unsigned int iMessageSize; // [esp+8h] [ebp-60h] BYREF
    unsigned int iPeerId;      // [esp+2Ch] [ebp-3Ch] BYREF
    _BYTE v26[28];             // [esp+3Ch] [ebp-2Ch] BYREF
                               // [esp+64h] [ebp-4h]

    int iReadMessages = 0;
    while(this->m_pSimpleNet->IsMessage(-1)) {
        ++iReadMessages;
        void *pMessage;
        if(!this->m_pSimpleNet->PopMessage(pMessage, iMessageSize, iPeerId)) {
            CTrace::Print("Gamehost.cpp: PopMessage() failed with error %s!", this->m_pSimpleNet->GetLastErrorString().c_str());
            return;
        }
        if(pMessage) {
            OnlineManager *Instance = OnlineManager::GetInstance();
            if(Instance->IsInSession() && (v3 = StormManager::GetInstance(),
                                           LocalPeerId = StormManager::GetLocalPeerId(v3),
                                           LocalPeerId == this->m_pSimpleNet->GetLastSenderPeerId())) {
                CTrace::Print("CGameHost.cpp: Msg from localhost ignored!");
            } else {
                CGameHost::SSimpleMessage *sMessage = static_cast<SSimpleMessage *>(pMessage);
                unsigned short iId = sMessage->m_iId;
                if(iId == 3) {
                    if(this->m_pClientList->ContainsPeerId(iPeerId)) {
                        sMessage->m_iId = 4;
                        unsigned int iLastIP = this->m_pSimpleNet->GetLastSenderIP();
                        this->m_pSimpleNet->PushMessage(
                            iPeerId,
                            iLastIP,
                            0xC21,             // 0xC21
                            pMessage,          // pMessage
                            sizeof(*sMessage), // 6
                            false,             // 0
                            true);             // 1
                        static_assert(sizeof(*sMessage) == 6, "sizeof(sMessage) != 6");
                        if(this->m_pFSM->CurrentState() == 5)
                            this->m_iLastPingTime = timeGetTime();
                    }
                } else if(iId == 4) {
                    for(unsigned int i = 0; i < g_pGameType->m_iActualPlayerCount; ++i) {
                        int _iLastPeerId = this->m_pSimpleNet->GetLastSenderPeerId();
                        if(g_pGameType->m_sPlayerPeerId[i] == _iLastPeerId) {
                            g_pGameType->m_sPlayerAckDelta[i] = timeGetTime() - sMessage->m_iTick;
                            CLanLobby::RedrawPlayerList();
                            int index = this->m_pClientList->GetClientIndexPerPeerId(iPeerId);
                            BB_ASSERT(index >= 0)
                            this->m_pClientList->SetClientLastAck(index, timeGetTime());
                        }
                    }
                } else if(iId >= 1000u && iId < 1061u) {
                    if(iId == 1000 || iId == 1001 || iId == 1013 || iId == 1022 || iId == 1023 || iId == 1038 || iId == 1032 || iId == 3 ||
                       this->m_pClientList->ContainsPeerId(iPeerId) || (v8 = OnlineManager::GetInstance(), v8->IsInSession()) && (HostPeerId = StormManager::GetInstance()->GetHostPeerId(), iPeerId == HostPeerId)) {
                        if(iId != 1000 || !this->m_bClient && this->m_pFSM->CurrentState() != 17)
                            this->m_pFSM->Control(iId, &sMessage->m_iTick);
                    }
                }
            }
        }
    }
}

// address=[0x15b8d70]
// Decompiled from std::string *__thiscall CGameHost::ConvertIPAddress(CGameHost *this, std::string *_rIp, ULONG _iAddress)
std::string CGameHost::ConvertIPAddress(unsigned int _uIp) {
    if(this->m_pSimpleNet) {
        return this->m_pSimpleNet->GetIPString(_uIp);
    }

    return "Unknown";
}

// address=[0x15b8de0]
// Decompiled from char __thiscall CGameHost::RemovePlayerPeerId(CGameHost *this, unsigned int a2)
bool CGameHost::RemovePlayerPeerId(unsigned int a2) {

    // eax
    // eax
    // [esp+4h] [ebp-40h]
    DWORD v6;       // [esp+Ch] [ebp-38h]
                    // [esp+17h] [ebp-2Dh]
    unsigned int i; // [esp+18h] [ebp-2Ch]
    int j;          // [esp+18h] [ebp-2Ch]

    char v8 = 0;
    if(StormManager::GetInstance()->GetLocalPeerId() == a2)
        return false;
    for(i = 0; i < g_pGameType->m_iActualPlayerCount; ++i) {
        if(g_pGameType->m_sPlayerPeerId[i] == a2) {
            v8 = 1;
            break;
        }
    }
    if(!v8)
        return false;
    this->m_pMsgStacks->ClearAndValidate(i);
    this->m_pMsgStacks->SetStackAI(i, 1);
    if(CGameSettings::GetAIDifficulty())
        v6 = 3;
    else
        v6 = 2;
    g_pGameType->m_sPlayerType[i] = v6;
    g_pGameType->m_sPlayerValidTicks[i] = CGameHost::GetValidTick();
    int ValidTick = CGameHost::GetValidTick();
    CTrace::Print("GameHost.cpp: Message stack index#%d set to AI in Tick %d!", i, ValidTick);
    if(!CClientList::RemoveClientPeerId(this->m_pClientList, g_pGameType->m_sPlayerPeerId[i]))
        CTrace::Print("GameHost.cpp: Player index#%d could not be removed from client list!", i);
    for(j = 1; j <= CPlayerManager::LastPlayerId() && CPlayerManager::PeerId(j) != a2; ++j)
        ;
    if(j > CPlayerManager::LastPlayerId() && BBSupportDbgReportF(2, "Net\\GameHost.cpp", 3577, "Player could not be set to AI!") == 1) {
        __debugbreak();
    }
    CTrace::Print("GameHost.cpp: Dropping player index#%d", j - 1);
    struct CEvn_Event v11(57u, j, 0, 0);
    g_pEvnEngine->SendAMessage(v11);
    return true;
}

// address=[0x15b9000]
// Decompiled from unsigned __int8 __thiscall CGameHost::IsLocalIP(CGameHost *this, int a2)
bool CGameHost::IsLocalIP(unsigned int a2) {

    if(this->m_pSimpleNet)
        return this->m_pSimpleNet->IsLocalIP(a2);
    else
        return true;
}

// address=[0x15b9040]
// Decompiled from char __thiscall CGameHost::OnEndGame(CGameHost *this, int a2)
bool CGameHost::OnEndGame(int a2) {

    return true;
}

// address=[0x15b9050]
// Decompiled from void __thiscall CGameHost::OnEndSaving(CGameHost *this, int a2)
void CGameHost::OnEndSaving(int a2) {

    CMsgStacks::OnEndSaving(this->m_pMsgStacks, g_pGameType->m_iActualPlayerCount, a2);
}

// address=[0x15b9080]
// Decompiled from void __thiscall CGameHost::StormJoinSessionSucceeded(CGameHost *this)
void CGameHost::StormJoinSessionSucceeded(void) {

    // eax
    // eax
    // eax
    // [esp-8h] [ebp-74h]
    // [esp+4h] [ebp-68h]
    // [esp+Ch] [ebp-60h]
    // [esp+1Ch] [ebp-50h]
    int LocalSlot;    // [esp+20h] [ebp-4Ch]
    std::wstring v10; // [esp+24h] [ebp-48h] BYREF
    _BYTE v11[28];    // [esp+40h] [ebp-2Ch] BYREF
                      // [esp+68h] [ebp-4h]

    OutputDebugStringA("JoinSessionSucceeded\n");
    storm::SimpleSessionHandler **Instance = (storm::SimpleSessionHandler **)StormManager::GetInstance();
    int HostPeerId = StormManager::GetHostPeerId(Instance);
    this->m_pClientList->Add(0, 0, HostPeerId);
    if(g_pGameType->m_bIsSaveGame)
        LocalSlot = g_pGameType->GetLocalSlot();
    else
        LocalSlot = -1;
    std::wstring swPlayerName = CGameSettings::GetPlayerName();
    // int v12 = 0;
    // wchar_t *v2 = std::wstring::c_str(PlayerName);
    // void *v5 = storm::CStringConvertToUtf8(v11, (int)v2);
    // LOBYTE(v12) = 1;
    // char *v4 = (char *)std::basic_string<char, std::char_traits<char>, storm::Allocator<char, 1092620295>>::c_str(v5);
    OnlineManager *v3 = OnlineManager::GetInstance();
    v3->SendUnicastPlayerMessage(HostPeerId, swPlayerName.c_str(), (const struct storm::StormPlayerMessage *)LocalSlot);

    this->m_pFSM->GenerateEvent(1057, 0);
}

// address=[0x15b91b0]
// Decompiled from int __stdcall CGameHost::StormHost_NewPlayerMessage(CGameHost *a1, std::wstring *a2, int a3)
void CGameHost::StormHost_NewPlayerMessage(unsigned int a1, std::wstring &a2, int a3) {
    wchar_t Destination[32]; // [esp+4h] [ebp-6Ch] BYREF
    wcscpy(Destination, a2.c_str());
    char m_bIsSaveGame = g_pGameType->m_bIsSaveGame;
    char v8 = a3;
    CGameHost::ClientJoins(Destination);
}

// address=[0x15b9210]
// Decompiled from int __thiscall CGameHost::StormClientLeavesMyGame(CGameHost *this, unsigned int a2)
void CGameHost::StormClientLeavesMyGame(unsigned int a2) {

    if(a2 == StormManager::GetInstance()->GetHostPeerId(Instance))
        CTrace::Print("GameHost.cpp: Host has left session!");
    CLanLobby::DisconnectPlayerPeerId(a2, -1);
    if(!this->m_pClientList->RemoveClientPeerId(a2))
        CTrace::Print("GameHost.cpp: Unable to removed client!");
    CLanLobby::RedrawPlayerList();
}

// address=[0x04030852]
bool g_bIsHost;

// address=[0x15b9280]
// Decompiled from int __thiscall CGameHost::PromoteToHost(CGameHost *this)
void CGameHost::PromoteToHost(void) {

    // eax
    // [esp+0h] [ebp-8h]

    this->m_bHost = true;
    this->m_bClient = false;
    g_bIsHost = 1;
    struct CGameState *pCurrentState = CGameStateHandler::GetCurrentState();
    CStateLobbyGameSettings *pLobbyState = dynamic_cast<CStateLobbyGameSettings *>(pCurrentState);
    if(!pLobbyState)
        return CTrace::Print("GameHost.cpp: We are new Host!!!");
    CStateLobbyGameSettings::TransitionToHost(pLobbyState);
    this->m_pFSM->Control(1058, 0);
    GuiDlgMainGameSettingstUpdate();
    CTrace::Print("GameHost.cpp: We are new Host!!!");
}

// address=[0x15b9300]
// Decompiled from void __thiscall CGameHost::OnQuickMatched(CGameHost *this, bool a2)
void CGameHost::OnQuickMatched(bool a2) {
    if(a2)
        CGameHost::OnQuickMatchedHosted();
    else
        CGameHost::OnJoinedFromOnlineFlow();
}

// address=[0x15b9330]
// Decompiled from void __thiscall CGameHost::OnQuickMatchedHosted(CGameHost *this)
void CGameHost::OnQuickMatchedHosted(void) {
    std::wstring v7;           // [esp+10h] [ebp-A4h] BYREF
    std::wstring v8;           // [esp+2Ch] [ebp-88h] BYREF
    wchar_t swpPlayerName[31]; // [esp+48h] [ebp-6Ch] BYREF
    __int16 v10;               // [esp+86h] [ebp-2Eh]
    int v11;                   // [esp+89h] [ebp-2Bh]
                               // [esp+ACh] [ebp-8h]

    char v12 = -1;
    if(!g_pGameType->IsSaveGame() || !g_pGameType->IsMultiplayerGame()) {
        wcsncpy(swpPlayerName, CGameSettings::GetPlayerName().c_str(), 0x1Fu);
        g_pGameType->m_sPlayerType[0] = 1;
        CLanLobby::ConnectPlayer(swpPlayerName, -1);
    }
    for(unsigned int i = 1; i < g_pGameType->m_iActualPlayerCount; ++i) {
        if(g_pGameType->m_sPlayerType[i] == 2 || g_pGameType->m_sPlayerType[i] == 3 || g_pGameType->m_bPlayerSlotEmpty[i] && !this->m_bIsOnlineGame) {
            wcsncpy(swpPlayerName, g_pGameType->GetPlayerName(i).c_str(), 0x1Fu);
            CLanLobby::ConnectPlayer(swpPlayerName, i);
        }
    }
    this->m_pFSM->GenerateEvent(1009, 0);
}

// address=[0x15b9500]
// Decompiled from int __thiscall CGameHost::OnJoinedFromOnlineFlow(CGameHost *this)
void CGameHost::OnJoinedFromOnlineFlow(void) {
    bool v9;       // [esp-24h] [ebp-D8h]
    int v10;       // [esp-20h] [ebp-D4h]
    _BYTE v39[28]; // [esp+6Ch] [ebp-48h] BYREF
    _BYTE v40[28]; // [esp+88h] [ebp-2Ch] BYREF

    CGameSettings::SetPlayerName(g_swPlayerName);

    int v41 = 0;
    std::wstring swMapName;
    GameSessionDescriptor::GetMapName(v39);
    if(!g_pNetworkEngine) {
        g_pNetworkEngine = new INetworkEngine(1);
        g_pNetworkEngine->Start(0, 0, 0, 0);
    }
    _DWORD *v17 = 0;
    BOOL v16 = 0;
    int v15 = -1;
    DWORD v14 = -1;
    int v13 = 0;
    int v12 = 1;
    int v11 = 1;

    if(!g_pGameType->LoadMapData(swMapName, v9, v10, v11, v12, v13, v14, v15, v16, (bool)v17)) {
        delete g_pGameType;
        g_pGameType = new CGameType();
        g_pGameType->m_swMapName = swMapName;
        g_pGameType->m_bAIActive = 0;
    }
    std::wstring swSessionName;
    storm::echo::SessionDescriptor::GetSessionName(CurrentSession);

    g_pGameType->m_swGameName = swSessionName;
    g_pGameType->m_iGameType = 2;
    g_pGameType->m_iCampaignType = 0;
    g_pGameType->m_iActualPlayerCount = GameSessionDescriptor::GetPeerCount(CurrentSession);

    std::wstring swSaveFile;
    GameSessionDescriptor::GetSaveFile(v40);
    g_pGameType->m_bIsSaveGame = !swSaveFile.empty();
    g_pGameType->bIsAutosave = 0;
    if(g_pGameType->m_bIsSaveGame) {
        g_pGameType->m_swSaveFile = swSaveFile;
        if(g_pGameType->bIsAutosave)
            g_pGameType->m_swSaveFile += L"_autoSave";
        g_pGameType->m_swSaveFile += L".sav";
    }
    CLanLobby::Communicate(1024, g_iLanLobbyNr);
}

// address=[0x15b9860]
// Decompiled from void __thiscall CGameHost::FillHandlersArray(CGameHost *this)
void CGameHost::FillHandlersArray(void) {
    this->m_pHandlers[T_HOST_HANDLERS::StartState /*34*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::StartState);
    this->m_pHandlers[T_HOST_HANDLERS::InitHostNetwork /*1*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::InitHostNetwork);
    this->m_pHandlers[T_HOST_HANDLERS::InitClientNetwork /*2*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::InitClientNetwork);
    this->m_pHandlers[T_HOST_HANDLERS::OnHostWait /*3*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::OnHostWait);
    this->m_pHandlers[T_HOST_HANDLERS::SearchHost /*4*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::SearchHost);
    this->m_pHandlers[T_HOST_HANDLERS::WaitingForGameConnect /*16*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::WaitingForGameConnect);
    this->m_pHandlers[T_HOST_HANDLERS::HostInitGame /*18*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::HostInitGame);
    this->m_pHandlers[T_HOST_HANDLERS::HostStartTick /*19*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::HostStartTick);
    this->m_pHandlers[T_HOST_HANDLERS::RegClientConnect /*23*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::RegClientConnect);
    this->m_pHandlers[T_HOST_HANDLERS::WereConnectedForGame /*24*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::WereConnectedForGame);
    this->m_pHandlers[T_HOST_HANDLERS::ClientStartingGame /*26*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientStartingGame);
    this->m_pHandlers[T_HOST_HANDLERS::ClientGameInited /*28*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientGameInited);
    this->m_pHandlers[T_HOST_HANDLERS::ClientStartTick /*29*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientStartTick);
    this->m_pHandlers[T_HOST_HANDLERS::HostGameInited /*31*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::HostGameInited);
    this->m_pHandlers[T_HOST_HANDLERS::GameSyncMsgGot /*32*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::GameSyncMsgGot);
    this->m_pHandlers[T_HOST_HANDLERS::GameInGameMsgGot /*33*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::GameInGameMsgGot);
    this->m_pHandlers[T_HOST_HANDLERS::ErrorState /*0*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ErrorState);
    this->m_pHandlers[T_HOST_HANDLERS::DoNothing /*36*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::DoNothing);
    this->m_pHandlers[T_HOST_HANDLERS::ClientSearchesGameHost /*35*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientSearchesGameHost);
    this->m_pHandlers[T_HOST_HANDLERS::ClientReceivesGameInfo /*38*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientReceivesGameInfo);
    this->m_pHandlers[T_HOST_HANDLERS::ClientLoginHost /*40*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientLoginHost);
    this->m_pHandlers[T_HOST_HANDLERS::ClientJoins /*39*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientJoins);
    this->m_pHandlers[T_HOST_HANDLERS::ClientReceivePlayerData /*42*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientReceivePlayerData);
    this->m_pHandlers[T_HOST_HANDLERS::ClientReceivePlayerPing /*43*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientReceivePlayerPing);
    this->m_pHandlers[T_HOST_HANDLERS::ClientLobbyPrepare /*41*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientLobbyPrepare);
    this->m_pHandlers[T_HOST_HANDLERS::ResendPlayerData /*6*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ResendPlayerData);
    this->m_pHandlers[T_HOST_HANDLERS::ResendPlayerPing /*44*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ResendPlayerPing);
    this->m_pHandlers[T_HOST_HANDLERS::InitGameStruct /*7*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::InitGameStruct);
    this->m_pHandlers[T_HOST_HANDLERS::HostPressedStart /*8*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::HostPressedStart);
    this->m_pHandlers[T_HOST_HANDLERS::ResendFinalPData /*9*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ResendFinalPData);
    this->m_pHandlers[T_HOST_HANDLERS::ChatLine /*45*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ChatLine);
    this->m_pHandlers[T_HOST_HANDLERS::GameAlreadyFull /*46*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::GameAlreadyFull);
    this->m_pHandlers[T_HOST_HANDLERS::GameAsyncMsgGot /*47*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::GameAsyncMsgGot);
    this->m_pHandlers[T_HOST_HANDLERS::AmIStillAlive /*48*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::AmIStillAlive);
    this->m_pHandlers[T_HOST_HANDLERS::HeIsStillAlive /*49*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::HeIsStillAlive);
    this->m_pHandlers[T_HOST_HANDLERS::InitHostAfterLobby /*50*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::InitHostAfterLobby);
    this->m_pHandlers[T_HOST_HANDLERS::InitClientAfterLobby /*51*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::InitClientAfterLobby);
    this->m_pHandlers[T_HOST_HANDLERS::SendMapToClient /*52*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::SendMapToClient);
    this->m_pHandlers[T_HOST_HANDLERS::ClientReceiveMap /*53*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientReceiveMap);
    this->m_pHandlers[T_HOST_HANDLERS::ClientLeavesMyGame /*56*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientLeavesMyGame);
    this->m_pHandlers[T_HOST_HANDLERS::ClientWrongVersion /*57*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientWrongVersion);
    this->m_pHandlers[T_HOST_HANDLERS::ClientWrongVersionAfterLobby /*58*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::ClientWrongVersionAfterLobby);
    this->m_pHandlers[T_HOST_HANDLERS::PerformLeaveGame /*59*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::PerformLeaveGame);
    this->m_pHandlers[T_HOST_HANDLERS::SendChatLine /*61*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::SendChatLine);
    this->m_pHandlers[T_HOST_HANDLERS::HostChoseMap /*60*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::HostChoseMap);
    this->m_pHandlers[T_HOST_HANDLERS::QuickMatchChoseMap /*68*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::QuickMatchChoseMap);
    this->m_pHandlers[T_HOST_HANDLERS::InviteAccepted /*71*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::InviteAccepted);
    this->m_pHandlers[T_HOST_HANDLERS::UserDataChange /*62*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::UserDataChange);
    this->m_pHandlers[T_HOST_HANDLERS::KickClient /*63*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::KickClient);
    this->m_pHandlers[T_HOST_HANDLERS::WereKicked /*64*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::WereKicked);
    this->m_pHandlers[T_HOST_HANDLERS::GameInGamePackedGot /*65*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::GameInGamePackedGot);
    this->m_pHandlers[T_HOST_HANDLERS::GameSync0MsgGot /*66*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::GameSync0MsgGot);
    this->m_pHandlers[T_HOST_HANDLERS::UserChangeSlots /*67*/] = reinterpret_cast<EventHandlerFunc>(&CGameHost::UserChangeSlots);
}

// address=[0x15b9cd0]
// Decompiled from char __thiscall CGameHost::OnHostWait(CGameHost *this, void *a2)
bool CGameHost::OnHostWait(void *a2) {

    return true;
}

// address=[0x15b9ce0]
// Decompiled from char __thiscall CGameHost::OnClientRun(CGameHost *this)
bool CGameHost::OnClientRun(void) {
    if(!this->m_pFSM || this->m_pFSM->CurrentState() != 5 || this->m_iLastPingTime)
        return true;
    this->m_iLastPingTime = timeGetTime();
    return true;
}

// address=[0x15b9d20]
// Decompiled from void __thiscall CGameHost::OnHostRun(CGameHost *this)
void CGameHost::OnHostRun(void) {
    if(this->m_pFSM->CurrentState() == 3) {
        CGameHost::PingClients();
        DWORD v1 = this->m_iHostRun + 8000;
        if(v1 < timeGetTime())
            this->m_pFSM->Control(1035, 0);
        this->m_pFSM->Control(1061, 0);
        if(this->m_iMapUpload)
            this->m_pFSM->Control(1042, 0);
    }
}

// address=[0x15b9da0]
// Decompiled from char __thiscall CGameHost::InitHostNetwork(CGameHost *this, void *a2)
bool CGameHost::InitHostNetwork(void *a2) {
    this->m_bHost = true;
    return true;
}

// address=[0x15b9dc0]
// Decompiled from char __thiscall CGameHost::InitClientNetwork(CGameHost *this, void *a2)
bool CGameHost::InitClientNetwork(void *a2) {
    this->m_bClient = true;
    this->m_pFSM->GenerateEvent(1010, 0);
    return true;
}

// address=[0x15b9df0]
// Decompiled from char __thiscall CGameHost::ErrorState(CGameHost *this, int a2)
bool CGameHost::ErrorState(void *a2) {

    // eax
    // eax
    const char *v5; // [esp+0h] [ebp-8h]

    if(this->m_pSimpleNet) {
        ULONG v2 = this->m_pSimpleNet->GetLastSenderIP();
        v5 = this->m_pSimpleNet->GetIPString(v2);
    } else {
        v5 = 0;
    }

    CTrace::Print("GameHost.cpp: FSM Internal Error. Last State:%d, Event:%d (%s?)", this->m_pFSM->CurrentState(), a2, v5);
    return true;
}

#pragma pack(1)
struct SLobbyPlayerData {
    _BYTE m_iFinal;
    unsigned __int8 m_iHumanPlayers;
    unsigned __int8 m_iPlayerCount;
    unsigned __int8 m_iPlayerId;
    char m_uU0;
    wchar_t m_swpPlayerName[32];
    wchar_t m_swpPlayerClan[6];
    DWORD m_iIp;
    _DWORD m_iPeerId;
    unsigned __int8 m_iRace;
    unsigned __int8 m_iColor;
    unsigned __int8 m_iSlot8;
    unsigned __int8 m_iTeam;
    unsigned __int8 m_iType;
    _BYTE m_iSlot10;
    unsigned __int8 m_iSlot11;
    unsigned __int8 m_iStartResources;
    unsigned __int8 m_iMode;
    char m_pEconomyGoodsArray[7];
    _DWORD m_iSlot15;
    unsigned __int16 m_iNetworkTimeDelta;
    _DWORD m_iGameId;
    DWORD m_uExtraFlags;
};

static_assert(sizeof(SLobbyPlayerData) == 0x77, "sizeof(SLobbyPlayerData) != 0x77");

// address=[0x15b9e70]
// Decompiled from void __stdcall CGameHost::ProcessPlayerData(struct SLobbyPlayerData *a1)
void CGameHost::ProcessPlayerData(SLobbyPlayerData &_rLobbyPlayerData) {
    std::wstring v6; // [esp+20h] [ebp-48h] BYREF
    std::wstring v7; // [esp+3Ch] [ebp-2Ch] BYREF

    char v5 = 0;
    g_pGameType->m_iHumanPlayers = _rLobbyPlayerData.m_iHumanPlayers;
    if(g_pGameType->m_iActualPlayerCount != _rLobbyPlayerData.m_iPlayerCount) {
        g_pGameType->m_iActualPlayerCount = _rLobbyPlayerData.m_iPlayerCount;
        v5 = 1;
    }

    g_pGameType->SetPlayerName(_rLobbyPlayerData.m_iPlayerId, _rLobbyPlayerData.m_swpPlayerName);
    g_pGameType->SetPlayerClanShortcut(_rLobbyPlayerData.m_iPlayerId, _rLobbyPlayerData.m_swpPlayerClan);
    g_pGameType->m_sPlayerTeam[_rLobbyPlayerData.m_iPlayerId] = _rLobbyPlayerData.m_iTeam;
    g_pGameType->m_sPlayerColor[_rLobbyPlayerData.m_iPlayerId] = _rLobbyPlayerData.m_iColor;
    g_pGameType->m_sPlayerSlot8[_rLobbyPlayerData.m_iPlayerId] = _rLobbyPlayerData.m_iSlot8;
    g_pGameType->m_uiIPPlayer[_rLobbyPlayerData.m_iPlayerId] = _rLobbyPlayerData.m_iIp;
    g_pGameType->m_sPlayerPeerId[_rLobbyPlayerData.m_iPlayerId] = _rLobbyPlayerData.m_iPeerId;
    g_pGameType->m_sPlayerRaces[_rLobbyPlayerData.m_iPlayerId] = _rLobbyPlayerData.m_iRace;
    g_pGameType->m_sPlayerType[_rLobbyPlayerData.m_iPlayerId] = _rLobbyPlayerData.m_iType;
    g_pGameType->m_sPlayerExclusiveColor[_rLobbyPlayerData.m_iPlayerId] = _rLobbyPlayerData.m_iSlot10;
    g_pGameType->m_sPlayerMapUploadStarted[_rLobbyPlayerData.m_iPlayerId] = _rLobbyPlayerData.m_iSlot11;
    g_pGameType->m_iStartResources = _rLobbyPlayerData.m_iStartResources;
    g_pGameType->m_iMode = _rLobbyPlayerData.m_iMode;
    g_pGameType->m_uExtraFlags = _rLobbyPlayerData.m_uExtraFlags;
    g_pGameType->m_sPlayerSlot15[_rLobbyPlayerData.m_iPlayerId] = _rLobbyPlayerData.m_iSlot15;
    g_pGameType->m_iNetworkTimeDelta = _rLobbyPlayerData.m_iNetworkTimeDelta;
    g_pGameType->SetMultiPlayerGameID(_rLobbyPlayerData.m_iGameId);
    memcpy(g_pGameType->m_pEconomyGoodsArray, _rLobbyPlayerData.m_pEconomyGoodsArray, sizeof(g_pGameType->m_pEconomyGoodsArray));
    CLanLobby::RedrawPlayerList();
    if(v5) {
        struct CGameState *pCurrentState = CGameStateHandler::GetCurrentState();
        CStateLobbyGameSettings *pLobbyState = dynamic_cast<CStateLobbyGameSettings *>(pCurrentState);
        if(pLobbyState)
            pLobbyState->PaintMap();
    }
}

// address=[0x15ba130]
// Decompiled from void __thiscall CGameHost::SendPlayerData(CGameHost *this, int _iFinal)
void CGameHost::SendPlayerData(unsigned int _iFinal) {
    std::wstring v9; // [esp+1Ch] [ebp-A4h] BYREF

    for(signed int i = 0; i < g_pGameType->m_iMapMaxNumPlayers; ++i) {
        SLobbyPlayerData Src{}; // [esp+38h] [ebp-88h] BYREF
        memset(&Src, 0, sizeof(Src));
        Src.m_iHumanPlayers = g_pGameType->m_iHumanPlayers;
        Src.m_iPlayerCount = g_pGameType->m_iActualPlayerCount;
        Src.m_iPlayerId = i;
        Src.m_iFinal = _iFinal;
        Src.m_iColor = g_pGameType->m_sPlayerColor[i];
        Src.m_iSlot8 = g_pGameType->m_sPlayerSlot8[i];
        Src.m_iTeam = g_pGameType->m_sPlayerTeam[i];
        Src.m_iIp = g_pGameType->m_uiIPPlayer[i];
        Src.m_iPeerId = g_pGameType->m_sPlayerPeerId[i];
        Src.m_iRace = g_pGameType->m_sPlayerRaces[i];
        Src.m_iType = g_pGameType->m_sPlayerType[i];
        Src.m_iSlot10 = g_pGameType->m_sPlayerExclusiveColor[i];
        Src.m_iSlot11 = g_pGameType->m_sPlayerMapUploadStarted[i];

        MyWStrNCopy(Src.m_swpPlayerName, g_pGameType->GetRealPlayerName(i).c_str(), 64u);
        MyWStrNCopy(Src.m_swpPlayerClan, g_pGameType->GetPlayerClanShortcut(i).c_str(), 12u);
        Src.m_iStartResources = g_pGameType->m_iStartResources;
        memcpy(Src.m_pEconomyGoodsArray, g_pGameType->m_pEconomyGoodsArray, sizeof(Src.m_pEconomyGoodsArray));
        Src.m_iMode = g_pGameType->m_iMode;
        Src.m_uExtraFlags = g_pGameType->m_uExtraFlags;
        Src.m_iSlot15 = g_pGameType->m_sPlayerSlot15[i];
        Src.m_iNetworkTimeDelta = g_pGameType->m_iNetworkTimeDelta;
        Src.m_iGameId = g_pGameType->GetMultiPlayerGameID();
        unsigned __int8 v7 = _iFinal != 0;
        if(_iFinal)
            CGameHost::SendToAll(1032, reinterpret_cast<short *>(&Src), sizeof(Src), 0, 0, v7);
        else
            CGameHost::SendToAll(1026, reinterpret_cast<short *>(&Src), sizeof(Src), 0, 0, v7);
        static_assert(sizeof(SLobbyPlayerData) == 0x77, "sizeof(SLobbyPlayerData) != 0x77");
    }
}

// address=[0x15ba420]
// Decompiled from void __thiscall CGameHost::SendToAll(  CGameHost *this,  int a2,  void *_pvData0,  size_t _uiDataLength0,  void *_pvData1,  size_t _uiDataLength1,  char a7)
void CGameHost::SendToAll(unsigned int a2, short *_pvData0, unsigned int _uiDataLength0, short *_pvData1, unsigned int _uiDataLength1, bool a7) {

    // eax
    // [esp-18h] [ebp-42Ch]
    // [esp+0h] [ebp-414h]
    // [esp+Bh] [ebp-409h]
    CGameHost::SMessage v12; // [esp+Ch] [ebp-408h] BYREF

    if(_pvData0 && !_uiDataLength0 && BBSupportDbgReportF(2, "Net\\GameHost.cpp", 4618, "Fatal: _pvData0 set, but _uiDataLength0 == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1) {
        __debugbreak();
    }
    if(_pvData1 && !_uiDataLength1 && BBSupportDbgReportF(2, "Net\\GameHost.cpp", 4622, "Fatal: _pvData1 set, but _uiDataLength1 == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1) {
        __debugbreak();
    }
    if(this->m_bIsOnlineGame) {
        for(signed int i = 0; i < this->m_pClientList->GetSize(); ++i) {
            v12.m_iId = a2;
            if(_pvData0) {
                memcpy(&v12.m_cEvent, _pvData0, _uiDataLength0);
            } else if(_uiDataLength0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4637, "!_uiDataLength0") == 1) {
                __debugbreak();
            }
            if(_pvData1) {
                if(!_pvData0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4642, "_pvData0") == 1)
                    __debugbreak();
                memcpy((char *)&v12.m_cEvent + _uiDataLength0, _pvData1, _uiDataLength1);
            } else if(_uiDataLength1 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4647, "!_uiDataLength1") == 1) {
                __debugbreak();
            }
            char v11 = 1;
            if(a2 == 1055 || a2 == 3 || a2 == 1040)
                v11 = 0;
            this->m_pSimpleNet->PushMessage(
                this->m_pClientList->GetPlayerPeerId(i), // peer id
                this->m_pClientList->GetPlayerIP(i),     // ip
                3105u,                                   // receiver?
                &v12,                                    // pData
                _uiDataLength0 + _uiDataLength1 + 2,     // length
                a7,                                      // resend
                v11);                                    // compress
        }
    }
}

// address=[0x15ba650]
// Decompiled from void __thiscall CGameHost::SendToHost(  CGameHost *this,  int a2,  void *_pvData0,  size_t _uiDataLength0,  void *_pvData1,  size_t _uiDataLength1,  char a7)
void CGameHost::SendToHost(unsigned int a2, short *_pvData0, unsigned int _uiDataLength0, short *_pvData1, unsigned int _uiDataLength1, bool a7) {

    // eax
    // eax
    // [esp-18h] [ebp-428h]
    // [esp+7h] [ebp-409h]
    CGameHost::SMessage v12; // [esp+8h] [ebp-408h] BYREF

    if(_pvData0 && !_uiDataLength0 && BBSupportDbgReportF(2, "Net\\GameHost.cpp", 4673, "Fatal: _pvData0 set, but _uiDataLength0 == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1) {
        __debugbreak();
    }
    if(_pvData1 && !_uiDataLength1 && BBSupportDbgReportF(2, "Net\\GameHost.cpp", 4677, "Fatal: _pvData1 set, but _uiDataLength1 == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1) {
        __debugbreak();
    }
    v12.m_iId = a2;
    if(_pvData0) {
        memcpy(&v12.m_cEvent, _pvData0, _uiDataLength0);
    } else if(_uiDataLength0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4687, "!_uiDataLength0") == 1) {
        __debugbreak();
    }
    if(_pvData1) {
        if(!_pvData0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4692, "_pvData0") == 1)
            __debugbreak();
        memcpy((char *)&v12.m_cEvent + _uiDataLength0, _pvData1, _uiDataLength1);
    } else if(_uiDataLength1 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4697, "!_uiDataLength1") == 1) {
        __debugbreak();
    }
    char v11 = 1;
    if(a2 == 1055 || a2 == 3 || a2 == 1040)
        v11 = 0;
    if(!this->m_pSimpleNet && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4709, "m_pSimpleNet!=NULL") == 1)
        __debugbreak();
    if(this->m_pSimpleNet) {
        unsigned int iHostAddress = g_pGameType->m_iHostAddress;
        storm::SimpleSessionHandler **Instance = (storm::SimpleSessionHandler **)StormManager::GetInstance();
        unsigned int HostPeerId = StormManager::GetHostPeerId(Instance);
        this->m_pSimpleNet->PushMessage(
            HostPeerId,
            iHostAddress,
            3105,
            &v12,
            _uiDataLength0 + _uiDataLength1 + 2,
            a7,
            v11);
    }
}

// address=[0x15ba860]
// Decompiled from char __thiscall CGameHost::AddGame(CGameHost *this, struct SGameInfo *a2)
bool CGameHost::AddGame(SGameInfo &a2) {

    int v3;                         // [esp-10h] [ebp-8Ch] BYREF
    int v4;                         // [esp-Ch] [ebp-88h] BYREF
    int v5;                         // [esp-8h] [ebp-84h]
    struct SGameInfo *v6;           // [esp-4h] [ebp-80h]
    _BYTE v7[12];                   // [esp+4h] [ebp-78h] BYREF
    _BYTE v8[12];                   // [esp+10h] [ebp-6Ch] BYREF
    _BYTE v9[12];                   // [esp+1Ch] [ebp-60h] BYREF
    _BYTE v10[12];                  // [esp+28h] [ebp-54h] BYREF
    std::_Iterator_base12 *v11[10]; // [esp+34h] [ebp-48h] BYREF
                                    // [esp+5Ch] [ebp-20h]
    SGameInfo *v14;                 // [esp+64h] [ebp-18h]
                                    // [esp+6Eh] [ebp-Eh]
                                    // [esp+6Fh] [ebp-Dh]
                                    // [esp+78h] [ebp-4h]

    if(!CGameHost::IsValidSaveGame(a2))
        return true;

    for(auto rIt = this->m_vGameInfos.begin(); rIt != this->m_vGameInfos.end(); ++rIt) {
        auto &rGame = *rIt;
        if(rGame.m_uSessionId == a2.m_uSessionId) {
            rIt = this->m_vGameInfos.erase(rIt);
            this->m_vGameInfos.insert(rIt, a2);
            CLanLobby::RedrawGameList();
            return true;
        }
    }

    this->m_vGameInfos.push_back(a2);
    CLanLobby::RedrawGameList();
    return true;
}

// address=[0x15baa20]
// Decompiled from int __thiscall CGameHost::ValidateGameList(CGameHost *this)
void CGameHost::ValidateGameList(void) {

    int uTime = timeGetTime();
    auto rNewEnd = std::remove_if(this->m_vGameInfos.begin(), this->m_vGameInfos.end(), [uTime](const SGameInfo &gameInfo) {
        return static_cast<unsigned int>(gameInfo.m_iStartTime + 6000) < uTime;
    });

    if(rNewEnd != this->m_vGameInfos.end()) {
        this->m_vGameInfos.erase(rNewEnd, this->m_vGameInfos.end());
        CLanLobby::RedrawGameList();
    }
}

// address=[0x15baba0]
// Decompiled from int __thiscall CGameHost::GetLocalID(CGameHost *this)
unsigned int CGameHost::GetLocalID(void) {

    // eax
    // [esp+4h] [ebp-4h]

    for(int i = 0; i < g_pGameType->m_iMapMaxNumPlayers; ++i) {
        int Instance = StormManager::GetInstance();
        if(StormManager::GetLocalPeerId(Instance) == g_pGameType->m_sPlayerPeerId[i])
            return i;
    }
    BB_REPORT("No local ID found !!!")
    return -1;
}

// address=[0x15bac30]
// Decompiled from int __thiscall CGameHost::GetSlot(CGameHost *this, unsigned int a2)
int CGameHost::GetSlot(unsigned int a2) {
    for(int i = 0; i < 8; ++i) {
        if(g_pGameType->m_uiIPPlayer[i] == a2)
            return i;
    }
    BB_REPORT("Player IP not found in g_pGameType!");
    return 0;
}

// address=[0x15bacb0]
// Decompiled from void __thiscall CGameHost::NotifyClients(CGameHost *this, int a2)
void CGameHost::NotifyClients(unsigned int a2) {
    char bSendToAll = 0;
    signed int Time = timeGetTime();
    for(unsigned int i = 0; i < g_pGameType->m_iActualPlayerCount; ++i) {
        if((a2 & (1 << i)) != 0 && i != CGameHost::GetLocalID()) {
            int iLastMsgTime = this->m_pMsgStacks->GetLastMsgTime(i);
            if(iLastMsgTime) {
                if(iLastMsgTime + g_iNotReadyKickDelay >= Time) {
                    if(iLastMsgTime + g_iNotReadyWarnDelay >= Time || this->m_iReadyTime && this->m_iReadyTime + g_iNotReadyWarnAgainDelay >= static_cast<unsigned int>(Time)) {
                        continue;
                    }

                    char Dest[36]; // [esp+B8h] [ebp-34h] BYREF
                    CTrace::Print("CGameHost.cpp: Waiting for Player index#%d !", i);
                    this->m_iReadyTime = Time;
                    size_t v7 = wcstombs(Dest, g_pGameType->GetPlayerName(i).c_str(), wcslen(g_pGameType->GetPlayerName(i).c_str()));
                    Dest[v7] = 0;
                    CTextMsgHandler::AddTextMsg(GUI_SYS_WAIT_FOR_PLAYER, i + 1, 0, 1, Dest);
                    bSendToAll = 1;
                } else {
                    CTrace::Print("GameHost.cpp: Kicking player index#%d!", i);
                    DWORD v12 = g_pGameType->m_sPlayerPeerId[i];
                    int j;
                    for(j = 1; j <= CPlayerManager::LastPlayerId() && CPlayerManager::PeerId(j) != v12; ++j)
                        ;
                    CGameHost::RemovePlayerPeerId(this, g_pGameType->m_sPlayerPeerId[i]);
                    CEvn_Logic v11 = CEvn_Logic(0xFA9u, j, GetValidTick(), j, 0, 0);
                    g_pNetworkEngine->SendAsyncNetMessage(v11, 255);
                    CEvn_Event v10 = CEvn_Event(0xFA9u, j, GetValidTick(), 0);
                    g_pEvnEngine->SendAMessage(v10);

                    bSendToAll = 1;
                }
            } else {
                this->m_pMsgStacks->SetLastMsgTime(i, Time, 0);
            }
        }
    }
    if(bSendToAll)
        CGameHost::SendToAll(1040, 0, 0, 0, 0, 0);
}

// address=[0x15bb0e0]
// Decompiled from char __thiscall CGameHost::IsExclusiveColor(CGameHost *this, int a2)
bool CGameHost::IsExclusiveColor(int a2) {
    for(int i = 0; i < g_pGameType->m_iMapMaxNumPlayers; ++i) {
        if(i != a2 && g_pGameType->m_sPlayerColor[i] == g_pGameType->m_sPlayerColor[a2] && !g_pGameType->m_sPlayerExclusiveColor[i]) {
            return false;
        }
    }
    return true;
}

// address=[0x15bb160]
// Decompiled from char __thiscall CGameHost::HostChoseMap(CGameHost *this, int a2)
bool CGameHost::HostChoseMap(void *) {
    std::wstring v11;        // [esp+18h] [ebp-A4h] BYREF
    std::wstring v12;        // [esp+34h] [ebp-88h] BYREF
    wchar_t Destination[32]; // [esp+50h] [ebp-6Ch] BYREF
                             // [esp+8Eh] [ebp-2Eh]
    int v15;                 // [esp+91h] [ebp-2Bh]
                             // [esp+B4h] [ebp-8h]

    char v16 = -1;
    if(!g_pGameType->IsSaveGame() || !g_pGameType->IsMultiplayerGame()) {
        wcsncpy(Destination, CGameSettings::GetPlayerName().c_str(), 0x1Fu);
        Destination[31] = 0;
        g_pGameType->m_sPlayerType[0] = 1;
        CLanLobby::ConnectPlayer(Destination, -1);
    }
    for(unsigned int i = 1; i < g_pGameType->m_iActualPlayerCount; ++i) {
        if(g_pGameType->m_sPlayerType[i] == 2 || g_pGameType->m_sPlayerType[i] == 3 || g_pGameType->m_bPlayerSlotEmpty[i] && !this->m_bIsOnlineGame) {
            wcsncpy(Destination, g_pGameType->GetPlayerName(i), 0x1Fu);
            Destination[31] = 0;

            __int16 v14 = 0;
            CLanLobby::ConnectPlayer(Destination, i);
        }
    }
    if(g_pGameType->IsMultiplayerGame()) {
        OnlineManager::GetInstance()->CreateSession(g_pGameType);
    }
    this->m_pFSM->GenerateEvent(1009, 0);
    return true;
}

// address=[0x15bb380]
// Decompiled from char __stdcall CGameHost::QuickMatchChoseMap(int a1)
bool CGameHost::QuickMatchChoseMap(void *a1) {
    OnlineManager::GetInstance()->QuickMatch(g_pGameType);
    return true;
}

// address=[0x15bb3b0]
// Decompiled from char __thiscall CGameHost::InviteAccepted(CGameHost *this, void *a2)
bool CGameHost::InviteAccepted(void *a2) {

    // eax
    // eax
    // eax
    // eax
    // [esp+0h] [ebp-10h] BYREF
    // [esp+Ch] [ebp-4h]

    unsigned __int64 v7 = (int)a2;
    OnlineManager *pManager = (OnlineManager *)OnlineManager::GetInstance();
    if(pManager->IsInSession()) {
        pManager->LeaveSession();
        // int v9 = UPlay::UPlayManager::GetInstance();
        //(*(void(__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v9 + 44))(v9, v7, HIDWORD(v7));
    } else {
        pManager->SetInviteFlow(1);
        unsigned long long *session = static_cast<unsigned long long *>(a2);
        pManager->JoinSession(*session);
    }
    return true;
}

// address=[0x15bb430]
// Decompiled from char __stdcall CGameHost::StartState(int a1)
bool CGameHost::StartState(void *a1) {
    return false;
}

// address=[0x15bb440]
// Decompiled from char __thiscall CGameHost::SearchHost(CGameHost *this, int a2)
bool CGameHost::SearchHost(void *a2) {
    CTrace::Print("Start searching Host .... ");
    std::list<SGameInfo> lNewSession{};
    OnlineManager::GetInstance()->UpdateDiscoveredSessions(lNewSession);
    for(auto sGameInfo : lNewSession) {
        sGameInfo.m_iStartTime = timeGetTime();
        this->AddGame(sGameInfo);
    }

    CGameHost::ValidateGameList();
    OnlineManager::GetInstance()->SearchForSessions();
}

// address=[0x15bb5b0]
// Decompiled from char __thiscall CGameHost::ClientSearchesGameHost(CGameHost *this, int a2)
bool CGameHost::ClientSearchesGameHost(void *a2) {
    CGameHost::SSearchMessage sMsg{};
    memset(&sMsg, 0, sizeof(sMsg));
    sMsg.m_iMessageId = 1022;
    sMsg.m_uByte261 = g_pGameType->byte261;
    sMsg.m_iHumanPlayers = g_pGameType->m_iHumanPlayers;
    sMsg.m_iMapCRC = g_pGameType->m_iMapCRC;
    sMsg.m_iActualPlayerCount = g_pGameType->m_iActualPlayerCount;
    sMsg.m_iFileSize = g_pGameType->m_iFileSize;
    sMsg.m_iLenString298 = g_pGameType->std__string298.length() != 0;
    sMsg.m_bIsSaveGame = g_pGameType->m_bIsSaveGame;
    sMsg.bIsAutosave = g_pGameType->bIsAutosave;
    sMsg.m_uiTickCounter = g_pGameType->m_uiTickCounter;
    sMsg.m_iMultiPlayerGameId = g_pGameType->GetMultiPlayerGameID();
    sMsg.m_iMPSavegameId = g_pGameType->GetMPSavegameID();
    sMsg.m_bIsSaveGame = g_pGameType->IsSaveGame();
    sMsg.m_uExtraFlags = g_pGameType->m_uExtraFlags;
    MyWStrNCopy(sMsg.m_swpGameName, g_pGameType->m_swGameName.c_str(), 0x40u);
    FilePaths::PathSplitResult a1; // [esp+41Ch] [ebp-5Ch] BYREF
    FilePaths::SplitPath(&a1, &g_pGameType->m_swMapName);
    MyWStrNCopy(sMsg.m_swpMapName, a1.m_swpDirectoryName.c_str(), 512u);
    this->m_pSimpleNet->PushMessage(
        this->m_pSimpleNet->GetLastSenderPeerId(),
        this->m_pSimpleNet->GetLastSenderIP(),
        3105,
        &sMsg,
        1146, // NOTE: I don't know where the 1146 size comes from... The msg is of size 0x402 and the stack does not give more space
        0,
        1);
    return 1;
}

// address=[0x15bb880]
// Decompiled from char __thiscall CGameHost::ClientReceivesGameInfo(CGameHost *this, void *Src)
bool CGameHost::ClientReceivesGameInfo(void *Src) {

    // ax
    wchar_t *v3;                // eax
                                // [esp-4h] [ebp-508h]
                                // [esp+4h] [ebp-500h]
                                // [esp+Ch] [ebp-4F8h]
    struct SGameInfo sGameInfo; // [esp+18h] [ebp-4ECh] BYREF
    std::wstring v10;           // [esp+4A0h] [ebp-64h] BYREF
    std::wstring v11;           // [esp+4BCh] [ebp-48h] BYREF
    std::wstring v12;           // [esp+4D8h] [ebp-2Ch] BYREF
                                // [esp+500h] [ebp-4h]

    if(GetMessageLength() != sizeof(SGameInfo) - 0x10)
        return true;
    static_assert(sizeof(SGameInfo) - 0x10 == 1144, "sizeof(SGameInfo) - 0x10  != 1144");

    sGameInfo.m_iHostAddress = this->m_pSimpleNet->GetLastSenderIP();
    unsigned __int16 MessageLength = this->GetMessageLength();
    memcpy(&sGameInfo + 0x10, Src, MessageLength);
    MyWStrNCopy(sGameInfo.m_swpMapName, MapFilePaths::GetFilePathForMapName(sGameInfo.m_swpMapName).c_str(), sizeof(sGameInfo.m_swpMapName));
    static_assert(sizeof(sGameInfo.m_swpMapName) == 0x200, "sizeof(sGameInfo.m_swpMapName) != 0x200u");
    int iMapCRC = sGameInfo.m_iMapCRC;
    sGameInfo.m_bMapAvailable = g_pGameType->IsMapAvailable(sGameInfo.m_swpMapName, iMapCRC);
    sGameInfo.m_iStartTime = timeGetTime();
    CGameHost::AddGame(sGameInfo);
    return true;
}

// address=[0x15bba10]
// Decompiled from char __thiscall CGameHost::ClientLoginHost(CGameHost *this, int arg0)
bool CGameHost::ClientLoginHost(void *arg0) {

    int v29 = 0;
    if(OnlineManager::GetInstance()->IsQuickMatchFlow() || OnlineManager::GetInstance()->IsInviteFlow()) {
        // StormManager *v4 = (StormManager *)StormManager::GetInstance();
        // GameSessionDescriptor *CurrentSession = StormManager::GetCurrentSession(v4);
        // g_pGameType->m_iActualPlayerCount = GameSessionDescriptor::GetPeerCount(CurrentSession);
        // g_pGameType->m_uiTickCounter = GameSessionDescriptor::GetTickCount(CurrentSession);
        this->m_bHost = false;
        this->m_bClient = true;

        CGameChunkGeneral v26{};
        g_pRandomMaps->AdjustRandomMapFileName(g_pGameType->m_swSaveFile);
        CGameRun::LoadGeneralInfo(g_pGameType->m_swSaveFile.c_str(), &v26);
        while(this->m_pClientList->GetSize())
            this->m_pClientList->RemoveClientAt(0);
        g_pGameType->SetLocalSlot(v26.m_cLocalSlot);
    } else {
        int iHostGameIndex = reinterpret_cast<int>(arg0);
        SGameInfo &rHostGame = *this->m_vGameInfos.end();

        int i = 0;
        for(auto &rGame : this->m_vGameInfos) {
            if(i == iHostGameIndex) {
                rHostGame = rGame;
                break;
            }
            ++i;
        }
        g_pGameType->m_iActualPlayerCount = rHostGame.m_iPlayerCount;
        g_pGameType->m_iFileSize = rHostGame.m_iFileSize;
        g_pGameType->m_uiTickCounter = rHostGame.m_uTickCounter;

        std::wstring swRandomMapFileName = rHostGame.m_swpRandomMapFileName;
        if(rHostGame.m_bIsAutosave)
            swRandomMapFileName += L"_autoSave";
        swRandomMapFileName += L".sav";
        CGameChunkGeneral v25{};
        g_pRandomMaps->AdjustRandomMapFileName(swRandomMapFileName);
        CGameRun::LoadGeneralInfo(swRandomMapFileName.c_str(), &v25);
        g_pGameType->SetLocalSlot(v25.m_cLocalSlot);
        while(this->m_pClientList->GetSize())
            this->m_pClientList->RemoveClientAt(0);
        OnlineManager::GetInstance()->JoinSession(rHostGame.m_uSessionId);
    }
    this->m_iNotReadyTimeoutTick = timeGetTime();
    if(OnlineManager::GetInstance()->IsQuickMatchFlow() || OnlineManager::GetInstance()->IsInviteFlow()) {
        this->StormJoinSessionSucceeded();
    }

    return true;
}

// address=[0x15bbdf0]
// Decompiled from char __thiscall CGameHost::ClientJoins(CGameHost *this, void *Src)
bool CGameHost::ClientJoins(void *Src) {
    // eax
    // [esp-8h] [ebp-90h]
    // [esp+4h] [ebp-84h]
    // [esp+8h] [ebp-80h]
    // [esp+Ch] [ebp-7Ch]
    // [esp+10h] [ebp-78h]
    // [esp+14h] [ebp-74h]
    CGameHost::SJoinMessage sMsg; // [esp+1Ch] [ebp-6Ch] BYREF

    memcpy(&sMsg, Src, sizeof(sMsg));
    DWORD _uPeerId = sMsg.m_iPeerId;
    if(this->m_pClientList->ContainsPeerId(sMsg.m_iPeerId))
        return 1;

    if(g_pGameType->IsSaveGame()) {
        if(!CLanLobby::ConnectPlayer(&sMsg, sMsg.m_iRequestedSlot))
            return 1;
    } else {
        signed int v5 = -1;
        if(g_pGameType->IsWebGame()) {
            v5 = 8;
            for(int i = 0; i < 8; ++i) {
                if(g_pGameType->m_sPlayerPeerId[i] == sMsg.m_iPeerId) {
                    v5 = i;
                    break;
                }
            }
        }
        if(v5 == 8 || !CLanLobby::ConnectPlayer(&sMsg, v5))
            return 1;
    }

    if(!this->m_pClientList->ContainsPeerId(_uPeerId)) {
        int uPlayerId = this->m_pClientList->CreateNewPlayerID();
        int _uIp = this->m_pSimpleNet->GetLastSenderIP();
        this->m_pClientList->Add(_uIp, uPlayerId, _uPeerId);
    }
    int iLocalSlotID = -1;
    for(unsigned int j = 0; j < g_pGameType->m_iActualPlayerCount && iLocalSlotID == -1; ++j) {
        if(g_pGameType->m_sPlayerPeerId[j] == _uPeerId)
            iLocalSlotID = j;
    }
    BB_ASSERT(iLocalSlotID >= 0)

    if(iLocalSlotID >= 0)
        g_pGameType->m_bPlayerSlotEmpty[iLocalSlotID] = 0;
    CLanLobby::RedrawPlayerList();
    this->m_pFSM->Control(1035, 0);
    return 1;
}

// address=[0x15bc010]
// Decompiled from char __stdcall CGameHost::ClientWrongVersion(int a1)
bool CGameHost::ClientWrongVersion(void *) {
    CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, reinterpret_cast<void *>(0x96C));
    CGameStateHandler::Switch(CStateLobbyConnect::DynamicCreateFunc, 0);
    return true;
}

// address=[0x15bc040]
// Decompiled from char __stdcall CGameHost::ClientWrongVersionAfterLobby(int a1)
bool CGameHost::ClientWrongVersionAfterLobby(void *) {
    CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, reinterpret_cast<void *>(0x96E));
    CGameStateHandler::Switch(CStateMainMenu::DynamicCreateFunc, 0);
    return true;
}

// address=[0x15bc070]
// Decompiled from char __thiscall CGameHost::ClientReceivePlayerData(CGameHost *this, void *Src)
bool CGameHost::ClientReceivePlayerData(void *Src) {

    // ax
    // [esp+Ch] [ebp-ACh]
    struct SLobbyPlayerData sPlayerData; // [esp+18h] [ebp-A0h] BYREF

    unsigned __int16 MessageLength = CGameHost::GetMessageLength();
    memcpy(&sPlayerData, Src, MessageLength);
    BB_ASSERT(sPlayerData.m_iFinal == PLAYERDATA_UPDATE)

    CGameHost::ProcessPlayerData(sPlayerData);
    if(this->m_bHasSentMap)
        return true;
    if(!g_pGameType->IsMapAvailable(&g_pGameType->m_swMapName, g_pGameType->m_iMapCRC) && !g_pGameType->IsSaveGame() && !this->m_bMapBeingDownloaded) {
        CGameHost::SendToHost(1042, 0, 0, 0, 0, true);
        CEvn_Event sEvent(80u, 1u, 0, 0);
        g_pEvnEngine->SendAMessage(sEvent);

        BB_ASSERT(!m_bMapBeingDownloaded)

        this->m_iMapDownloadLastBlock = g_pGameType->m_iFileSize / 0x300u;
        if(g_pGameType->m_iFileSize % 0x300u)
            ++this->m_iMapDownloadLastBlock;
        this->m_pMapDownloadBlocks = new BYTE[this->m_iMapDownloadLastBlock];
        memset(this->m_pMapDownloadBlocks, 0, this->m_iMapDownloadLastBlock);
        this->m_pMapDownloadData = new BYTE[g_pGameType->m_iFileSize];
        this->m_iMapDownloadBlocksArrived = 0;
        this->m_bMapBeingDownloaded = true;
        CTrace::Print(
            "GameHost.cpp: Map download scheduled. Waiting for %d bytes in %d blocks.!",
            g_pGameType->m_iFileSize,
            this->m_iMapDownloadLastBlock);
    }
    this->m_bHasSentMap = true;
    return true;
}

// address=[0x15bc320]
// Decompiled from char __thiscall CGameHost::ClientReceivePlayerPing(CGameHost *this, void *Src)
bool CGameHost::ClientReceivePlayerPing(void *Src) {

    // ax
    unsigned __int8 v4; // [esp+0h] [ebp-Ch] BYREF
    DWORD v5;           // [esp+1h] [ebp-Bh]

    unsigned __int16 MessageLength = CGameHost::GetMessageLength();
    memcpy(&v4, Src, MessageLength);
    g_pGameType->m_sPlayerAckDelta[v4] = v5;
    CLanLobby::RedrawPlayerList();
    return true;
}

// address=[0x15bc370]
// Decompiled from char __thiscall CGameHost::ClientLobbyPrepare(void *this, int a2)
bool CGameHost::ClientLobbyPrepare(void *a2) {
    this->m_vGameInfos.clear();
    CGameStateHandler::Switch(CStateLobbyGameSettings::DynamicCreateFunc, 0);
    return false;
}

// address=[0x15bc3a0]
// Decompiled from char __thiscall CGameHost::ResendPlayerData(void *this, int a2)
bool CGameHost::ResendPlayerData(void *a2) {
    CGameHost::SendPlayerData(0);
    return true;
}

// address=[0x15bc3c0]
// Decompiled from char __thiscall CGameHost::ResendPlayerPing(CGameHost *this, int a2)
bool CGameHost::ResendPlayerPing(void *a2) {
    CGameHost::SPingMessage Src;
    for(int i = 0; i < g_pGameType->m_iMapMaxNumPlayers; ++i) {
        memset(&Src, 0, sizeof(Src));
        Src.m_iPlayerId = i;
        Src.m_iDelta = g_pGameType->m_sPlayerAckDelta[i];
        CGameHost::SendToAll(1034, reinterpret_cast<short *>(&Src), sizeof(Src), 0, 0, true);
    }
    this->m_iHostRun = timeGetTime();
    return true;
}

// address=[0x15bc450]
// Decompiled from char __thiscall CGameHost::HostPressedStart(CGameHost *this, int a2)
bool CGameHost::HostPressedStart(void *a2) {

    // eax
    // [esp-10h] [ebp-41Ch]
    // [esp-Ch] [ebp-418h]
    // [esp-4h] [ebp-410h]
    int i;             // [esp+4h] [ebp-408h]
    char Buffer[1024]; // [esp+8h] [ebp-404h] BYREF

    this->m_pFSM->GenerateEvent(1030, 0);
    if(!g_pGameType->IsWebGame() || g_pGameType->IsSaveGame())
        return false;
    for(i = 0; g_pGameType->m_uiIPPlayer[i] != g_pGameType->m_iHostAddress; ++i)
        ;

    sprintf(
        Buffer,
        "{ ? = CALL proc_addtogame_playerclan( %d, %d, %d, 1, '%s', %d, '' ) }",
        g_pGameType->GetMultiPlayerGameID(),
        g_pGameType->m_sPlayerPeerId[i],
        g_pGameType->m_sPlayerRaces[i],
        "Team",
        g_pGameType->m_sPlayerColor[i]);
    return false;
}

// address=[0x15bc560]
// Decompiled from char __thiscall CGameHost::InitGameStruct(CGameHost *this, void *Src)
bool CGameHost::InitGameStruct(void *Src) {

    // ax
    struct SLobbyPlayerData sPlayerData; // [esp+4h] [ebp-7Ch] BYREF

    if(!this->dwordBC) {
        CTrace::Print("GameHost.cpp: Clearing client list...");
        while(this->m_pClientList->GetSize())
            this->m_pClientList->RemoveClientAt(0);
    }
    if(Src) {
        unsigned __int16 MessageLength = CGameHost::GetMessageLength();
        memcpy(&sPlayerData, Src, MessageLength);
        BB_ASSERT(sPlayerData.m_iFinal == PLAYERDATA_FINAL)
        if(sPlayerData.m_iFinal == 1) {
            CGameHost::ProcessPlayerData(sPlayerData);
            g_pGameType->m_iHumanPlayers = sPlayerData.m_iHumanPlayers;
            g_pGameType->m_iActualPlayerCount = sPlayerData.m_iPlayerCount;
            ++this->dwordBC;
        }
    }
    if(this->dwordBC == g_pGameType->m_iActualPlayerCount)
        this->m_pFSM->GenerateEvent(1031, 0);
    return true;
}

// address=[0x15bc680]
// Decompiled from char __thiscall CGameHost::ResendFinalPData(CGameHost *this, int a2)
bool CGameHost::ResendFinalPData(void *a2) {

    if(this->m_bIsOnlineGame) {
        CGameHost::SendPlayerData(1);
        while(this->m_pClientList->GetSize())
            this->m_pClientList->RemoveClientAt(0);
        BB_ASSERT(!m_pClientList->GetSize())

        this->m_pFSM->GenerateEvent(1012, 0);
    } else {
        this->m_pFSM->GenerateEvent(1013, 0);
    }
    return true;
}

// address=[0x15bc720]
// Decompiled from char __thiscall CGameHost::ChatLine(CGameHost *this, void *Src)
bool CGameHost::ChatLine(void *pChatLine) {
    CGameHost::SChatLineMessage sMsg; // [esp+4h] [ebp-104h] BYREF
    unsigned __int16 uMessageLength = CGameHost::GetMessageLength();
    memcpy(&sMsg, pChatLine, uMessageLength);
    if(this->m_bHost)
        CGameHost::SendToAll(1036, reinterpret_cast<short *>(&sMsg), 0x100u, 0, 0, 1u);
    CLanLobby::PrintChatLine(sMsg.m_swpName, sMsg.m_swpChatLine);
    return 1;
}

// address=[0x15bc7c0]
// Decompiled from char __stdcall CGameHost::GameAlreadyFull(int a1)
bool CGameHost::GameAlreadyFull(void *) {
    CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, (void *)0x96A);
    CGameStateHandler::Switch(CStateLobbyConnect::DynamicCreateFunc, 0);
    return true;
}

// address=[0x15bc7f0]
// Decompiled from char __thiscall CGameHost::SendMapToClient(CGameHost *this, int _iClient)
bool CGameHost::SendMapToClient(void *_iClient) {
    unsigned int iIp;                // [esp+18h] [ebp-4D0h] MAPDST
    int iSlot;                       // [esp+38h] [ebp-4B0h] MAPDST
    CGameHost::SMapMessage sMessage; // [esp+40h] [ebp-4A8h] BYREF
    std::wstring a1;                 // [esp+4BCh] [ebp-2Ch] BYREF

    if(!_iClient) {
        for(iSlot = 0; iSlot < 8; ++iSlot) {
            if(!this->m_pMapUploadBuffer[iSlot])
                continue;

            BB_ASSERT(g_pGameType->m_uiIPPlayer[iSlot] != m_pSimpleNet->GetCurrentLocalIPLong())

            sMessage.m_iId = 1043;
            iIp = this->m_pSimpleNet->GetLastSenderIP();
            unsigned int iPeerId = this->m_pSimpleNet->GetLastSenderPeerId();
            if(this->m_iMapUploadSentChunks[iSlot] >= this->m_iMapUploadChunks[iSlot]) {
                if(this->m_pMapUploadBuffer[iSlot]) {
                    operator delete(this->m_pMapUploadBuffer[iSlot]);
                    this->m_pMapUploadBuffer[iSlot] = 0;
                }
                this->m_iMapUploadSentChunks[iSlot] = 0;
                if(!--this->m_iMapUpload) {
                    CEvn_Event sEvent(0x50u, 0, 0, 0);
                    g_pEvnEngine->SendAMessage(sEvent);
                }

                BB_ASSERT(m_iMapUpload >= 0)

                g_pGameType->m_sPlayerMapUploadStarted[iSlot] = 0;
            } else {
                sMessage.m_iChunkId = this->m_iMapUploadSentChunks[iSlot];
                unsigned int iChunkOffset = MAP_UPLOAD_CHUNK_SIZE * this->m_iMapUploadSentChunks[iSlot];
                if(iChunkOffset + MAP_UPLOAD_CHUNK_SIZE <= g_pGameType->m_iFileSize)
                    memcpy(sMessage.m_iMapData, &this->m_pMapUploadBuffer[iSlot][iChunkOffset], MAP_UPLOAD_CHUNK_SIZE);
                else
                    memcpy(
                        sMessage.m_iMapData,
                        &this->m_pMapUploadBuffer[iSlot][iChunkOffset],
                        g_pGameType->m_iFileSize - iChunkOffset);

                this->m_pSimpleNet->PushMessage(iPeerId, iIp, 3105, &sMessage, 774, 1, 1);
                CTrace::Print("GameHost.cpp: Map block sent. Block %d!", sMessage.m_iChunkId);
                ++this->m_iMapUploadSentChunks[iSlot];
            }
        }

        return true;
    }

    iIp = this->m_pSimpleNet->GetLastSenderIP();
    iSlot = CGameHost::GetSlot(iIp);
    if(this->m_pMapUploadBuffer[iSlot]) {
        return true;
    }

    this->m_pMapUploadBuffer[iSlot] = (char *)operator new[](g_pGameType->m_iFileSize);
    CFile cMapFile{};
    cMapFile.Open(g_pGameType->m_swMapName, CFile::CFile_BINARY | CFile::CFile_READ, CFileLog);
    cMapFile.Read(this->m_pMapUploadBuffer[iSlot], g_pGameType->m_iFileSize, 1u, CFileLog);
    cMapFile.Close(CFileLog);
    if(++this->m_iMapUpload == 1) {
        CEvn_Event sEvent(80u, 1u, 0, 0);
        g_pEvnEngine->SendAMessage(sEvent);
    }

    BB_ASSERT(m_iMapUpload < MAX_PLAYER - 1)
    this->m_iMapUploadChunks[iSlot] = g_pGameType->m_iFileSize / MAP_UPLOAD_CHUNK_SIZE;
    if(g_pGameType->m_iFileSize % MAP_UPLOAD_CHUNK_SIZE)
        ++this->m_iMapUploadChunks[iSlot];
    g_pGameType->m_sPlayerMapUploadStarted[iSlot] = 1;

    return true;
}

// address=[0x15bce20]
// Decompiled from char __thiscall CGameHost::ClientReceiveMap(struct CGameHost *this, void *_pMessage)
bool CGameHost::ClientReceiveMap(void *_pMessage) {
    if(!this->m_bMapBeingDownloaded) {
        CGameHost::SMapDownloadBlock v29{}; // [esp+334h] [ebp-3A8h] BYREF
        memcpy(&v29, _pMessage, CGameHost::GetMessageLength());
        CTrace::Print("GameHost.cpp: Mapdata block %d without request got !!", v29.m_iId);
        return true;
    }

    CGameHost::SMapDownloadBlock pBlock{};                     // [esp+30h] [ebp-6ACh] BYREF
    memcpy(&pBlock, _pMessage, CGameHost::GetMessageLength()); // MessageLength <= sizeof(CGameHost::SMapDownloadBlock)
    if(this->m_pMapDownloadBlocks[pBlock.m_iId]) {
        return true;
    }

    size_t Size = pBlock.m_iId == this->m_iMapDownloadLastBlock - 1 ? g_pGameType->m_iFileSize % 768u : 768;
    memcpy(&this->m_pMapDownloadData[768 * pBlock.m_iId], pBlock.m_vData, Size);
    this->m_pMapDownloadBlocks[pBlock.m_iId] = 1;
    CTrace::Print(
        "GameHost.cpp: Map block arrived. Got block %d, count is %d/%d!",
        pBlock.m_iId,
        ++this->m_iMapDownloadBlocksArrived,
        this->m_iMapDownloadLastBlock);
    if(this->m_iMapDownloadLastBlock == this->m_iMapDownloadBlocksArrived) {
        this->m_bMapBeingDownloaded = false;

        CFile cFile{};
        cFile.Open(g_pGameType->m_swMapName, CFile::CFile_BINARY | CFile::CFile_WRITE, CFileLog);

        cFile.Write(this->m_pMapDownloadData, g_pGameType->m_iFileSize, 1, CFileLog);
        cFile.Close(CFileLog);
        void *C = this->m_pMapDownloadBlocks;
        operator delete[](C);
        this->m_pMapDownloadBlocks = 0;
        void *m_pMapDownloadData = this->m_pMapDownloadData;
        operator delete[](m_pMapDownloadData);
        this->m_pMapDownloadData = 0;
        if(g_pGameType->IsMapAvailable(&g_pGameType->m_swMapName, g_pGameType->m_iMapCRC)) {
            struct CEvn_Event cEvent(80u, 0, 0, 0);
            g_pEvnEngine->SendAMessage(cEvent);
            CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, reinterpret_cast<void *>(2416)); // The host has a different map
            CGameStateHandler::Switch(CStateLobbyConnect::DynamicCreateFunc, 0);
        } else {
            bool bIsWebGame = g_pGameType->IsWebGame();
            bool bIsClan = g_pGameType->IsClanGame() & bIsWebGame;
            bool bIsLadder = g_pGameType->IsLadderGame() & bIsWebGame;
            g_pGameType->LoadMapData(g_pGameType->m_swMapName, 0, g_pGameType->m_iHostAddress, 1, 1, 0, -1, -1, bIsLadder, bIsClan);
            CLanLobby::RedrawMap();
            struct CEvn_Event cEvent(0x50u, 0, 0, 0);
            g_pEvnEngine->SendAMessage(cEvent);
        }
    }
    return true;
}

// address=[0x15bd220]
// Decompiled from char __thiscall CGameHost::ClientLeavesMyGame(CGameHost *this, int a2)
bool CGameHost::ClientLeavesMyGame(void *a2) {

    // [esp+0h] [ebp-8h]

    int v3 = this->m_pSimpleNet->GetLastSenderPeerId();
    CLanLobby::DisconnectPlayerPeerId(v3, -1);
    if(!this->m_pClientList->RemoveClientPeerId(v3))
        CTrace::Print("GameHost.cpp: Unable to removed client!");
    CLanLobby::RedrawPlayerList();
    return true;
}

// address=[0x15bd290]
// Decompiled from char __thiscall CGameHost::PerformLeaveGame(void *this, int a2)
bool CGameHost::PerformLeaveGame(void *a2) {
    OnlineManager::GetInstance()->LeaveSession();
    return true;
}

// address=[0x15bd2b0]
// Decompiled from char __thiscall CGameHost::SendChatLine(CGameHost *this, wchar_t *Source)
bool CGameHost::SendChatLine(void *pChatLine) {
    wchar_t *v2;                      // eax
    wchar_t *v3;                      // eax
    CGameHost::SChatLineMessage sMsg; // [esp+18h] [ebp-148h] BYREF

    memset(&sMsg, 0, sizeof(sMsg));
    MyWStrNCopy(sMsg.m_swpChatLine, static_cast<wchar_t const *>(pChatLine), sizeof(sMsg.m_swpChatLine));
    MyWStrNCopy(sMsg.m_swpName, CGameSettings::GetPlayerName().c_str(), sizeof(sMsg.m_swpName));
    static_assert(sizeof(sMsg.m_swpChatLine) == 192u, "sizeof(sMsg.m_swpChatLine) != 192u");
    static_assert(sizeof(sMsg.m_swpName) == 64u, "sizeof(sMsg.m_swpName) != 64u");

    if(this->m_bHost) {
        CGameHost::SendToAll(1036, reinterpret_cast<short *>(&sMsg), 256u, 0, 0, 1u);
        CLanLobby::PrintChatLine(CGameSettings::GetPlayerName().c_str(), pChatLine);
    } else {
        CGameHost::SendToHost(1036, reinterpret_cast<short *>(&sMsg), 256u, 0, 0, 1);
    }
    return 1;
}

// address=[0x15bd420]
// Decompiled from char __thiscall CGameHost::UserDataChange(CGameHost *this, CGameHost::SChangeMessage *a2)
bool CGameHost::UserDataChange(void *pChange) {

    int v4;   // [esp+8h] [ebp-14h]
    DWORD v5; // [esp+Ch] [ebp-10h]
    int i;    // [esp+14h] [ebp-8h]
    CGameHost::SChangeMessage *a2 = static_cast<CGameHost::SChangeMessage *>(pChange);

    switch(a2->m_iType) {
    case 0:
        do {
            if(a2->m_iTarget == 6) {
                if(--g_pGameType->m_sPlayerColor[a2->m_iSlot] == -1)
                    g_pGameType->m_sPlayerColor[a2->m_iSlot] = 7;
            } else if(++g_pGameType->m_sPlayerColor[a2->m_iSlot] == 8) {
                g_pGameType->m_sPlayerColor[a2->m_iSlot] = 0;
            }
        } while(!CGameHost::IsExclusiveColor(a2->m_iSlot));
        break;
    case 1:
        if(g_pGameType->field_3EF[a2->m_iSlot]) {
            if(a2->m_iTarget == 6) {
                if(g_pGameType->m_sPlayerRaces[a2->m_iSlot])
                    --g_pGameType->m_sPlayerRaces[a2->m_iSlot];
                else
                    g_pGameType->m_sPlayerRaces[a2->m_iSlot] = 5;
                while(g_pGameType->m_sPlayerRaces[a2->m_iSlot] == 3 || g_pGameType->m_sPlayerRaces[a2->m_iSlot] == 4 && (g_uiExtrasAllowed & 1) == 0)
                    --g_pGameType->m_sPlayerRaces[a2->m_iSlot];
            } else {
                if(g_pGameType->m_sPlayerRaces[a2->m_iSlot] == 5)
                    g_pGameType->m_sPlayerRaces[a2->m_iSlot] = 0;
                else
                    ++g_pGameType->m_sPlayerRaces[a2->m_iSlot];
                while(g_pGameType->m_sPlayerRaces[a2->m_iSlot] == 3 || g_pGameType->m_sPlayerRaces[a2->m_iSlot] == 4 && (g_uiExtrasAllowed & 1) == 0) {
                    if(++g_pGameType->m_sPlayerRaces[a2->m_iSlot] == 6)
                        g_pGameType->m_sPlayerRaces[a2->m_iSlot] = 0;
                }
            }
        }
        break;
    case 2:
        if(a2->m_iTarget == 6) {
            if(--g_pGameType->m_sPlayerTeam[a2->m_iSlot] == -1)
                g_pGameType->m_sPlayerTeam[a2->m_iSlot] = g_pGameType->m_uiNumberAlliances - 1;
        } else if(a2->m_iTarget == 7 && ++g_pGameType->m_sPlayerTeam[a2->m_iSlot] == g_pGameType->m_uiNumberAlliances) {
            g_pGameType->m_sPlayerTeam[a2->m_iSlot] = 0;
        }
        break;
    case 4:
        if(a2->m_iTarget == 6) {
            if(--g_pGameType->m_sPlayerSlot8[a2->m_iSlot] == -1)
                g_pGameType->m_sPlayerSlot8[a2->m_iSlot] = 7;
        } else if(++g_pGameType->m_sPlayerSlot8[a2->m_iSlot] == 8) {
            g_pGameType->m_sPlayerSlot8[a2->m_iSlot] = 0;
        }
        break;
    case 5:
        if(a2->m_iTarget)
            v5 = 6;
        else
            v5 = 0;
        g_pGameType->m_sPlayerMapUploadStarted[a2->m_iSlot] = v5;
        break;
    case 9:
        v4 = 0;
        for(i = 0; i < 8; ++i) {
            if(g_pGameType->m_sPlayerSlot15[i] == a2->m_iSlot)
                v4 = i;
        }
        if(a2->m_iSlot == a2->m_iTarget) {
            g_pGameType->m_sPlayerSlot15[v4] = -1;
            g_pGameType->m_sPlayerSlot15[a2->m_iSlot] = -1;
        } else {
            g_pGameType->m_sPlayerSlot15[a2->m_iSlot] = a2->m_iTarget;
        }
        break;
    default:
        CTrace::Print("GameHost: Invalid Change Type %d from Slot %d!", a2->m_iType, a2->m_iSlot);
        break;
    }
    CLanLobby::RedrawPlayerList();
    return true;
}

// address=[0x15bd980]
// Decompiled from char __thiscall CGameHost::KickClient(CGameHost *this, int a2)
bool CGameHost::KickClient(void *a2) {

    DWORD v4; // [esp+4h] [ebp-Ch]

    v4 = g_pGameType->m_sPlayerPeerId[a2];
    CLanLobby::DisconnectPlayerPeerId(v4, -1);
    this->m_pClientList->RemoveClientPeerId(v4);
    g_pGameType->m_bPlayerSlotEmpty[a2] = 1;
    __int16 v5 = 1053;
    this->m_pSimpleNet->PushMessage(v4, g_pGameType->m_uiIPPlayer[a2], 3105, &v5, 2, 0, 1);
    CLanLobby::RedrawPlayerList();
    return true;
}

// address=[0x15bda30]
// Decompiled from char __thiscall CGameHost::WereKicked(CGameHost *this, int a2)
bool CGameHost::WereKicked(void *a2) {
    OnlineManager::GetInstance()->LeaveSession();
    CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, reinterpret_cast<void *>(0x9BE));
    CGameStateHandler::Switch(CStateLobbyConnect::DynamicCreateFunc, 0);
    return true;
}

// address=[0x15bda70]
// Decompiled from char __thiscall CGameHost::UserChangeSlots(CGameHost *this, unsigned int *a2)
bool CGameHost::UserChangeSlots(void *pMessage) {
    CGameHost::SChangeMessage *pChangeMessage = static_cast<CGameHost::SChangeMessage *>(pMessage);
    int iSlot = pChangeMessage->m_iSlot;
    int iTarget = pChangeMessage->m_iTarget;
    if(pChangeMessage->m_iSlot >= 0 && iTarget >= 0) {
        if(iTarget == g_pGameType->GetLocalSlot())
            g_pGameType->ChangeLocalSlot(iSlot);
        if(iSlot == g_pGameType->GetLocalSlot())
            g_pGameType->ChangeLocalSlot(iTarget);

        DWORD iType = g_pGameType->m_sPlayerType[iSlot];
        DWORD iIP = g_pGameType->m_uiIPPlayer[iSlot];
        DWORD iPeerId = g_pGameType->m_sPlayerPeerId[iSlot];
        DWORD iColor = g_pGameType->m_sPlayerColor[iSlot];
        BYTE iExclusiveColor = g_pGameType->m_sPlayerExclusiveColor[iSlot];
        DWORD iMapUpload = g_pGameType->m_sPlayerMapUploadStarted[iSlot];
        DWORD iAckDelta = g_pGameType->m_sPlayerAckDelta[iSlot];
        BYTE iEmptySlot = g_pGameType->m_bPlayerSlotEmpty[iSlot];
        std::wstring swName = g_pGameType->GetRealPlayerName(iSlot);
        std::wstring swClan = g_pGameType->GetPlayerClanShortcut(iSlot);

        g_pGameType->m_sPlayerType[iSlot] = g_pGameType->m_sPlayerType[iTarget];
        g_pGameType->m_uiIPPlayer[iSlot] = g_pGameType->m_uiIPPlayer[iTarget];
        g_pGameType->m_sPlayerPeerId[iSlot] = g_pGameType->m_sPlayerPeerId[iTarget];
        g_pGameType->m_sPlayerColor[iSlot] = g_pGameType->m_sPlayerColor[iTarget];
        g_pGameType->m_sPlayerExclusiveColor[iSlot] = g_pGameType->m_sPlayerExclusiveColor[iTarget];
        g_pGameType->m_sPlayerMapUploadStarted[iSlot] = g_pGameType->m_sPlayerMapUploadStarted[iTarget];
        g_pGameType->m_sPlayerAckDelta[iSlot] = g_pGameType->m_sPlayerAckDelta[iTarget];
        g_pGameType->m_bPlayerSlotEmpty[iSlot] = g_pGameType->m_bPlayerSlotEmpty[iTarget];
        g_pGameType->m_sPlayerSlot15[iSlot] = -1;
        g_pGameType->SetPlayerName(iSlot, g_pGameType->GetRealPlayerName(iTarget));
        g_pGameType->SetPlayerClanShortcut(iSlot, g_pGameType->GetPlayerClanShortcut(iTarget));

        g_pGameType->m_sPlayerType[iTarget] = iType;
        g_pGameType->m_uiIPPlayer[iTarget] = iIP;
        g_pGameType->m_sPlayerPeerId[iTarget] = iPeerId;
        g_pGameType->m_sPlayerColor[iTarget] = iColor;
        g_pGameType->m_sPlayerExclusiveColor[iTarget] = iExclusiveColor;
        g_pGameType->m_sPlayerMapUploadStarted[iTarget] = iMapUpload;
        g_pGameType->m_sPlayerAckDelta[iTarget] = iAckDelta;
        g_pGameType->m_bPlayerSlotEmpty[iTarget] = iEmptySlot;
        g_pGameType->m_sPlayerSlot15[iTarget] = -1;
        g_pGameType->SetPlayerName(iTarget, swName);
        g_pGameType->SetPlayerClanShortcut(iTarget, swClan);
    }
    CLanLobby::RedrawPlayerList();
    return 1;
}

// address=[0x15bde60]
// Decompiled from char __thiscall CGameHost::InitHostAfterLobby(CGameHost *this, int a2)
bool CGameHost::InitHostAfterLobby(void *a2) {
    this->m_bHost = true;
    this->m_pFSM->GenerateEvent(1009, 0);
    return true;
}

// address=[0x15bde90]
// Decompiled from char __thiscall CGameHost::InitClientAfterLobby(CGameHost *this, int a2)
bool CGameHost::InitClientAfterLobby(void *a2) {
    this->m_bClient = true;
    this->m_pFSM->GenerateEvent(1010, 0);
    return true;
}

// address=[0x15bdec0]
// Decompiled from char __thiscall CGameHost::WaitingForGameConnect(CGameHost *this, void *Src)
bool CGameHost::WaitingForGameConnect(void *Src) {
    int v11;                      // [esp+0h] [ebp-48Ch]
    int v12;                      // [esp+4h] [ebp-488h]
    unsigned int i;               // [esp+Ch] [ebp-480h]
    char v16;                     // [esp+10h] [ebp-47Ch]
    int j;                        // [esp+10h] [ebp-47Ch]
                                  // [esp+17h] [ebp-475h]
    CGameHost::SJoinMessage sMsg; // [esp+20h] [ebp-46Ch] BYREF
    char Buffer[1024];            // [esp+88h] [ebp-404h] BYREF

    if(!this->m_bIsOnlineGame) {
        this->m_pFSM->GenerateEvent(1014, 0);
        return true;
    }
    if(!Src) {
        return true;
    }

    unsigned int iLastSenderPeerId = this->m_pSimpleNet->GetLastSenderPeerId();
    memcpy(&sMsg, Src, CGameHost::GetMessageLength());
    if(sMsg.m_iVersionConfig != g_iConfigVersion)
        CTrace::Print("GameHost: Config files CRC mismatch!");
    if(sMsg.m_iVersionScript != g_iScriptVersion)
        CTrace::Print("GameHost: Script files CRC mismatch!");
    if(sMsg.m_iVersionGfx != g_iGfxVersion)
        CTrace::Print("GameHost: Gfx index files CRC mismatch!");
    if(this->m_pClientList->ContainsPeerId(iLastSenderPeerId)) {
        CTrace::Print("CGameHost: RegConnect for Peer already got !!");
    } else {
        char v18 = 0;
        for(i = 0; i < g_pGameType->m_iActualPlayerCount; ++i) {
            if(g_pGameType->m_sPlayerPeerId[i] == iLastSenderPeerId) {
                v18 = 1;
                break;
            }
        }
        if(v18) {
            this->m_pClientList->Add(this->m_pSimpleNet->GetLastSenderIP(), i, iLastSenderPeerId);
            unsigned int v4 = this->m_pSimpleNet->GetLastSenderIP();
            this->m_pSimpleNet->PushMessage(
                iLastSenderPeerId,
                v4,
                0xc21,                           // 0xc21
                reinterpret_cast<void *>(0x409), // 0x409
                2,                               // 2
                1,                               // 1
                1);                              // 1
            for(j = 0; j < 9 && g_pGameType->m_sPlayerPeerId[j] != iLastSenderPeerId; ++j)
                ;
            if(j == 8)
                j = 0;

            sprintf(
                Buffer,
                "{ ? = CALL proc_addtogame_playerclan( %d, %d, %d, 0, '%s', %d, '' ) }",
                g_pGameType->GetMultiPlayerGameID(),
                g_pGameType->m_sPlayerPeerId[j],
                g_pGameType->m_sPlayerRaces[j],
                "Team",
                g_pGameType->m_sPlayerColor[j]);
        }
    }
    int Size = this->m_pClientList->GetSize();
    if(Size == g_pGameType->HumanPlayers() - 1)
        this->m_pFSM->GenerateEvent(1014, 0);
    return 1;
}

// address=[0x15be220]
// Decompiled from char __thiscall CGameHost::HostInitGame(CGameHost *this, void *a2)
bool CGameHost::HostInitGame(void *a2) {
    if(this->m_bIsOnlineGame) {
        for(int i = 0; i < this->m_pClientList->GetSize(); ++i)
            CGameHost::SendToAll(1017, 0, 0, 0, 0, 1u);
    }

    this->m_pMsgStacks = new CMsgStacks(
        g_pGameType->m_iActualPlayerCount,
        g_pGameType->m_iNetworkTimeDelta / 0x47u,
        g_pGameType->m_uiTickCounter);
    ;
    for(unsigned int j = 0; j < g_pGameType->m_iActualPlayerCount; ++j) {
        if(g_pGameType->m_sPlayerType[j] == 2 || g_pGameType->m_sPlayerType[j] == 3)
            this->m_pMsgStacks->SetStackAI(j, 1);
    }
    CEvn_Event cEvent(0x18u, static_cast<unsigned int>(&g_pGameType), 0, 0); // NOTE: probably more like the address of m_swGameName
    g_pEvnEngine->SendAMessage(cEvent);
    return true;
}

// address=[0x15be3c0]
// Decompiled from char __thiscall CGameHost::HostStartTick(CGameHost *this, int a2)
bool CGameHost::HostStartTick(void *a2) {
    this->m_pSimpleNet->RemoveAllResendMsgs();
    CEvn_Event cEvent(0x19u, 0, 0, 0);
    g_pEvnEngine->SendAMessage(cEvent);
    return true;
}

// address=[0x15be460]
// Decompiled from char __thiscall CGameHost::RegClientConnect(CGameHost *this, int a2)
bool CGameHost::RegClientConnect(void *a2) {

    int iMsg = reinterpret_cast<int>(a2);
    if(iMsg == 1) {
        CGameHost::SJoinMessage sMsg; // [esp+2Ch] [ebp-6Ch] BYREF
        sMsg.m_bU0 = 1;
        // int Instance = StormManager::GetInstance();
        // Destination.m_iPeerId = StormManager::GetLocalPeerId(Instance);
        sMsg.m_iVersionMS = g_iFileVersionMS;
        sMsg.m_iVersionLS = g_iFileVersionLS;
        sMsg.m_iVersionConfig = g_iConfigVersion;
        sMsg.m_iVersionScript = g_iScriptVersion;
        sMsg.m_iVersionGfx = g_iGfxVersion;
        sMsg.m_bIsWebGame = g_pGameType->IsWebGame();
        wcsncpy(sMsg.m_swPlayerName, CGameSettings::GetPlayerName().c_str(), 31u);
        sMsg.field_3E = 0;
        CGameHost::SendToHost(1013, reinterpret_cast<short *>(&sMsg), 0x65u, 0, 0, true);
        return true;
    } else {
        int m_iHostAddress = g_pGameType->m_iHostAddress;
        if(this->m_pSimpleNet->GetLastSenderIP()) {
            g_pGameType->m_iHostAddress = this->m_pSimpleNet->GetLastSenderIP();
            for(int i = 0; i < 9; ++i) {
                if(g_pGameType->m_uiIPPlayer[i] == m_iHostAddress)
                    g_pGameType->m_uiIPPlayer[i] = this->m_pSimpleNet->GetLastSenderIP();
            }
        }
        BB_ASSERT(m_pClientList->GetSize() == 0)

        CTrace::Print("GameHost.cpp: Filling client list !!");
        for(int j = 0; j < 9; ++j) {
            if(g_pGameType->m_sPlayerPeerId[j] != -1) {
                if(g_pGameType->m_sPlayerPeerId[j] != StormManager::GetInstance()->GetLocalPeerId()) {
                    CClientList::Add(this->m_pClientList, g_pGameType->m_uiIPPlayer[j], j, g_pGameType->m_sPlayerPeerId[j]);
                    CTrace::Print("GameHost.cpp: Adding client %s to list !", this->m_pSimpleNet->GetIPString(g_pGameType->m_uiIPPlayer[j]));
                }
            }
        }
        return true;
    }
}

// address=[0x15be750]
// Decompiled from char __stdcall CGameHost::WereConnectedForGame(int a1)
bool CGameHost::WereConnectedForGame(void *a1) {
    return true;
}

// address=[0x15be760]
// Decompiled from char __thiscall CGameHost::ClientStartingGame(CGameHost *this, int a2)
bool CGameHost::ClientStartingGame(void *a2) {
    this->m_pMsgStacks = new CMsgStacks(
        g_pGameType->m_iActualPlayerCount,
        g_pGameType->m_iNetworkTimeDelta / 0x47u,
        g_pGameType->m_uiTickCounter);
    ;
    for(unsigned int i = 0; i < g_pGameType->m_iActualPlayerCount; ++i) {
        if(g_pGameType->m_sPlayerType[i] == 2 || g_pGameType->m_sPlayerType[i] == 3)
            this->m_pMsgStacks->SetStackAI(i, 1);
    }
    CEvn_Event v7(0x18u, static_cast<unsigned int>(&g_pGameType), 0, 0); // NOTE: probably more like the address of m_swGameName
    g_pEvnEngine->SendAMessage(v7);
    return true;
}

// address=[0x15be8b0]
// Decompiled from char __stdcall CGameHost::ClientGameInited(int a1)
bool CGameHost::ClientGameInited(void *a1) {
    CGameHost::SendToHost(1018, 0, 0, 0, 0, true);
    return true;
}

// address=[0x15be8e0]
// Decompiled from char __thiscall CGameHost::ClientStartTick(CGameHost *this, int a2)
bool CGameHost::ClientStartTick(void *a2) {
    this->m_pSimpleNet->RemoveAllResendMsgs();
    CEvn_Event v3(0x19u, 0, 0, 0);
    g_pEvnEngine->SendAMessage(v3);
    return true;
}

// address=[0x15be980]
// Decompiled from char __thiscall CGameHost::HostGameInited(CGameHost *this, int a2)
bool CGameHost::HostGameInited(void *a2) {
    if(!this->m_iInitTime)
        this->m_iInitTime = timeGetTime();
    if(a2) {
        int v2 = this->m_pSimpleNet->GetLastSenderPeerId();
        this->m_pClientList->SetClientReadyFromPeerId(v2, 1);
    } else {
        this->m_bInitFinished = true;
        CTrace::Print("CGameHost.cpp: Game init finished!");
    }
    if(this->m_pClientList->AllClientsReady()) {
        if(this->m_bInitFinished) {
            CTrace::Print("CGameHost.cpp: Everyone's finished with game init... Now start 1st tick!");
            CGameHost::SendToAll(1019, 0, 0, 0, 0, 1u);
            int v6 = 0;
            unsigned int v4 = 0;
            for(unsigned int i = 0; i < g_pGameType->m_iActualPlayerCount; ++i) {
                if(g_pGameType->m_sPlayerType[i] == 1) {
                    v4 += g_pGameType->m_sPlayerAckDelta[i];
                    ++v6;
                }
            }
            unsigned int v7 = v6 - 1;
            if(v7)
                CTrace::Print("GameHost.cpp: Sleeping for %d ms to get in semi sync state!", v4 / v7);
            this->m_pFSM->GenerateEvent(1015, 0);
        } else {
            CTrace::Print("CGameHost.cpp: Everyone's but host (me) finished with game init... !");
        }
        return true;
    } else {
        CTrace::Print("CGameHost.cpp: Not all clients finished with game init... !");
        return true;
    }
}

// address=[]
// Decompiled from char __thiscall CGameHost::GameSyncMsgGot(CGameHost *this, int *a2)
bool CGameHost::GameSyncMsgGot(void *pMsg) {
    // esi
    int m_iCurrentTick; // edi

    CGameHost::SSyncMessage *a2 = static_cast<CGameHost::SSyncMessage *>(pMsg);
    unsigned int iPlayerId = (a2->m_iSyncData >> 4) & 0xF;

    this->m_pMsgStacks->SetNumberOfExpectedMsgs(
        a2->m_iCurrentTick,
        iPlayerId,
        a2->m_iSyncData & 0xF);
    this->m_iSyncA[iPlayerId] += a2->m_iCurrentTick - CGameHost::GetValidTick();
    ++this->m_iSyncB[iPlayerId];
    return 1;
}

// address=[0x15beba0]
// Decompiled from char __thiscall CGameHost::GameSync0MsgGot(CGameHost *this, int *a2)
bool CGameHost::GameSync0MsgGot(void *pMsg) {
    int m_iPlayerId;    // esi
    int m_iCurrentTick; // edi

    CGameHost::SSync0Message *a2 = static_cast<CGameHost::SSync0Message *>(pMsg);

    if(this->m_pMsgStacks->IsSizeAlreadySet(a2->m_iCurrentTick, a2->m_iPlayerId - 1))
        return 1;
    this->m_pMsgStacks->SetNumberOfExpectedMsgs(a2->m_iCurrentTick, a2->m_iPlayerId - 1, 0);
    this->m_iSyncA[a2->m_iPlayerId - 1] += a2->m_iCurrentTick - CGameHost::GetValidTick();
    ++this->m_iSyncB[a2->m_iPlayerId - 1];
    return 1;
}

struct {
    CNet_Event cEvent{ 0, 0, 0, 0, 0, 0, 0 };
    BYTE vBuffer[MSG_BUFFER_SIZE];
} s_sInGameMsg, s_sAsyncMsg;

// address=[0x15bec60]
// Decompiled from char __thiscall CGameHost::GameInGameMsgGot(CGameHost *this, void *Src)
bool CGameHost::GameInGameMsgGot(void *pMsg) {
    memcpy(&s_sInGameMsg, pMsg, CGameHost::GetMessageLength());

    CNet_Event *pEvent = &s_sInGameMsg.cEvent;
    if(pEvent->m_iData) {
        BB_ASSERT(pEvent->m_iDataSize < MSG_BUFFER_SIZE)
        pEvent->m_iData = new BYTE[pEvent->m_iDataSize];
        memcpy(pEvent->m_iData, s_sInGameMsg.vBuffer, pEvent->m_iDataSize);
    }
    if(!this->m_pMsgStacks->IsInStack(s_sInGameMsg.cEvent) || this->m_pMsgStacks->IsStackAI(pEvent->m_iOwner - 1)) {
        this->m_pMsgStacks->PushMsg(s_sInGameMsg.cEvent);
    }
    return true;
}

// address=[0x15bed50]
// Decompiled from char __thiscall CGameHost::GameAsyncMsgGot(CGameHost *this, void *Src)
bool CGameHost::GameAsyncMsgGot(void *Src) {
    memcpy(&s_sAsyncMsg, Src, CGameHost::GetMessageLength());
    CNet_Event *pEvent = &s_sInGameMsg.cEvent;
    if(pEvent->m_iData) {
        BB_ASSERT(pEvent->m_iDataSize < MSG_BUFFER_SIZE)
        pEvent->m_iData = s_sAsyncMsg.vBuffer;
    }
    CEvn_Logic v4(
        pEvent->m_iEventId,
        pEvent->m_wParam,
        pEvent->m_lParam,
        pEvent->m_iOwner,
        reinterpret_cast<unsigned int>(pEvent->m_iData),
        pEvent->m_iDataSize);

    g_pEvnEngine->SendAMessage(v4);
    return true;
}

// address=[0x15bee60]
// Decompiled from char __thiscall CGameHost::AmIStillAlive(CGameHost *this, int a2)
bool CGameHost::AmIStillAlive(void *) {
    CGameHost::SSimpleMessage sMsg;
    sMsg.m_iId = 1041;
    unsigned int Src = CPlayerManager::GetLocalPlayerId() - 1;
    memcpy(&sMsg.m_iTick, &Src, sizeof(int)); // huh?!

    this->m_pSimpleNet->PushMessage(
        this->m_pSimpleNet->GetLastSenderPeerId(),
        this->m_pSimpleNet->GetLastSenderIP(),
        0xc21,
        &sMsg,
        6,
        0,
        1); // peer, ip, c21h, v6, 6, 0, 1

    return true;
}

// address=[0x15bef30]
// Decompiled from char __stdcall CGameHost::HeIsStillAlive(char *a1)
bool CGameHost::HeIsStillAlive(void *a1) {
    this->m_pMsgStacks->SetLastMsgTime(*static_cast<char *>(a1), timeGetTime(), 1);
    return true;
}

// address=[0x15bef60]
// Decompiled from char __thiscall CGameHost::GameInGamePackedGot(CGameHost *this, CGameHost::SMessageBuffer *a2)
bool CGameHost::GameInGamePackedGot(void *pMsg) {
    CGameHost::SMessageBuffer *a2 = static_cast<CGameHost::SMessageBuffer *>(pMsg);

    int iPlayerId = (a2->m_uPlayerMap & 0xF) + 1;
    int iPackCount = a2->m_uFlags & 0xF;
    unsigned char *pPackedBuffer = a2->m_vMessages;
    if(this->m_pMsgStacks->IsSizeAlreadySet(a2->m_uTick, a2->m_uPlayerMap & 0xF))
        return true;
    this->m_pMsgStacks->SetNumberOfExpectedMsgs(a2->m_uTick, iPlayerId - 1, iPackCount);
    this->m_iSyncA[iPlayerId - 1] += a2->m_uTick - CGameHost::GetValidTick(); // SyncA
    ++this->m_iSyncB[iPlayerId - 1];                                          // SyncB

    while(iPackCount) {
        struct CNet_Event *v8 = (struct CNet_Event *)pPackedBuffer;
        pPackedBuffer += 32; // sizeof(CNet_Event *)
        v8->m_iTick = a2->m_uTick;
        v8->m_iOwner = iPlayerId;
        if(v8->m_iDataSize) {
            v8->m_iData = (BYTE *)operator new[](v8->m_iDataSize);
            memcpy(v8->m_iData, pPackedBuffer, v8->m_iDataSize);
            pPackedBuffer += v8->m_iDataSize;
        }
        if(!this->m_pMsgStacks->IsStackAI(v8->m_iOwner - 1))
            this->m_pMsgStacks->PushMsg(*v8);
        --iPackCount;
    }
    return true;
}

// address=[0x15bf0e0]
// Decompiled from bool __thiscall CGameHost::IsValidSaveGame(CGameHost *this, struct SGameInfo *a2)
bool CGameHost::IsValidSaveGame(struct SGameInfo &sGameInfo) {
    if(!sGameInfo.m_iIsSaveGame)
        return true;

    std::wstring swMapFileName = sGameInfo.m_swpRandomMapFileName;
    g_pRandomMaps->AdjustRandomMapFileName(g_pRandomMaps, swMapFileName);
    if(sGameInfo.m_bIsAutosave)
        swMapFileName += L"_autoSave";
    swMapFileName += L".sav";
    CGameChunkGeneral v5{};
    if(!CGameRun::LoadGeneralInfo(swMapFileName.c_str(), &v5)) {
        return false;
    }

    return v5.m_uSavegameId == sGameInfo.m_iSavegameId;
}

// address=[0x15c4970]
// Decompiled from char __stdcall CGameHost::DoNothing(int a1)
bool CGameHost::DoNothing(void *a1) {
    return true;
}
