#ifndef CGAMEHOST_H
#define CGAMEHOST_H

#include "defines.h"

#include "CClientList.h"
#include "CConfigManager/Var/CStaticConfigVarInt.h"
#include "Defines/Players.h"
#include "Logic/CFsm.h"
#include "Logic/Events/IEventHandler.h"

struct SGameInfo {
    int m_iHostAddress;
    bool m_bMapAvailable;
    int m_iStartTime;
    WORD m_uU0;
    BYTE m_uU1;
    wchar_t m_swpGameName[32];
    wchar_t m_swpMapName[256];
    int m_iMapCRC;
    int m_iFileSize;
    bool m_bU2;
    int m_iPlayerCount;
    int m_iMaxPlayerCount;
    int m_iU0;
    int m_iGameId;
    int m_iSavegameId;
    bool m_iIsSaveGame;
    int m_uTickCounter;
    bool m_bU3;
    bool m_bIsAutosave;
    int m_uXXX;
    unsigned __int64 m_uSessionId;
    wchar_t m_swpRandomMapFileName[256];
};

static_assert(sizeof(SGameInfo) == 0x488, "SGameInfo has wrong size!");

// address=[0x415B888]
extern CStaticConfigVarInt g_iHostWaitAfterLobbyForClientsTimeout;
// address=[0x415B870]
extern CStaticConfigVarInt g_iNetAfterLobbyConnectTimeout;
// address=[0x415B804]
extern CStaticConfigVarInt g_iNetClientTimeOut;
// address=[0x415B87C]
extern CStaticConfigVarInt g_iNetClientWaitingStartTick;
// address=[0x415B828]
extern CStaticConfigVarInt g_iNetReceiverPort;
// address=[0x415B810]
extern CStaticConfigVarInt g_iNetSearchHostRetries;
// address=[0x415B81C]
extern CStaticConfigVarInt g_iNetSenderPort;
// address=[0x415B864]
extern CStaticConfigVarInt g_iNetworkTimeDelta;
// address=[0x415B858]
extern CStaticConfigVarInt g_iNotReadyGameStartTimeout;
// address=[0x415B84C]
extern CStaticConfigVarInt g_iNotReadyKickDelay;
// address=[0x415B840]
extern CStaticConfigVarInt g_iNotReadyWarnAgainDelay;
// address=[0x415B834]
extern CStaticConfigVarInt g_iNotReadyWarnDelay;
// address=[0x415B8AC]
extern CStaticConfigVarInt g_iPingAverage;
// address=[0x415B8A0]
extern CStaticConfigVarInt g_iPingGood;
// address=[0x415B894]
extern CStaticConfigVarInt g_iResendTimeout;
// address=[0x415B8B8]
extern CStaticConfigVarInt g_iSaveingTimeout;

// address=[0x415AD78]
extern CStaticConfigVarInt g_iProductID;

// address=[0x04030852]
extern bool g_bIsHost;
// address=[0x04030720]
extern std::wstring g_swPlayerName;
// address=[0x04030718]
extern int g_iLanLobbyNr; // TODO: move to lobby state!

class CSimpleNet;
class CGameHost : public IEventHandler {
  public:
    // address=[0x14aab10]
    unsigned int GetBytesPerSecond(void);

    // address=[0x15b4e60]
    bool AllSend(void);

    // address=[0x15b51a0]
    bool StartNewCycle(bool a2);

    // address=[0x15b5360]
    int GetValidTick(void);

    // address=[0x15b5380]
    int GetVirtualTick(void);

    // address=[0x15b53a0]
    bool RegisterMsgStacks(class CMsgStacks *a2);

    // address=[0x15b53d0]
    bool InitAsClient(unsigned int a2);

    // address=[0x15b5440]
    bool InitAsHost(unsigned int a2);

    // address=[0x15b54b0]
    CGameHost(bool arg0);

    // address=[0x15b5ed0]
    virtual ~CGameHost(void);

    // address=[0x15b60d0]
    bool PushMsg(class CNet_Event &_rMsg);

    // address=[0x15b6190]
    void PushAsyncMsg(class CNet_Event &_rEvent, unsigned char _iPlayerMap);

    // address=[0x15b63b0]
    class CNet_Event PopMsg(void);

    // address=[0x15b63f0]
    long GetLocalIP(void);

    // address=[0x15b6420]
    unsigned short GetMessageLength(void);

    // address=[0x15b6450]
    void GameInitalized(void);

    // address=[0x15b64f0]
    void ContinueSearchForHost(void);

    // address=[0x15b6510]
    bool Run(void);

    // address=[0x15b6c60]
    bool StartIniFileGame(wchar_t const *Source);

    // address=[0x15b88c0]
    void PingClients(void);

    // address=[0x15b8990]
    void DeliverSimpleMessage(void);

    // address=[0x15b8d70]
    std::string ConvertIPAddress(unsigned int _uIp);

    // address=[0x15b8de0]
    bool RemovePlayerPeerId(unsigned int a2);

    // address=[0x15b9000]
    bool IsLocalIP(unsigned int a2);

    // address=[0x15b9040]
    bool OnEndGame(int a2);

    // address=[0x15b9050]
    void OnEndSaving(int a2);

    // address=[0x15b9080]
    void StormJoinSessionSucceeded(void);

    // address=[0x15b91b0]
    void StormHost_NewPlayerMessage(unsigned int a1, std::wstring &a2, int a3);

    // address=[0x15b9210]
    void StormClientLeavesMyGame(unsigned int a2);

    // address=[0x15b9280]
    void PromoteToHost(void);

    // address=[0x15b9300]
    void OnQuickMatched(bool a2);

    // address=[0x15b9330]
    void OnQuickMatchedHosted(void);

    // address=[0x15b9500]
    void OnJoinedFromOnlineFlow(void);

  protected:
    // address=[0x15b9860]
    virtual void FillHandlersArray(void);

  private:
    // address=[0x15b9cd0]
    bool OnHostWait(void *a2);

    // address=[0x15b9ce0]
    bool OnClientRun(void);

    // address=[0x15b9d20]
    void OnHostRun(void);

    // address=[0x15b9da0]
    bool InitHostNetwork(void *a2);

    // address=[0x15b9dc0]
    bool InitClientNetwork(void *a2);

    // address=[0x15b9df0]
    bool ErrorState(void *a2);

    // address=[0x15b9e70]
    void ProcessPlayerData(struct SLobbyPlayerData &_rLobbyPlayerData);

    // address=[0x15ba130]
    void SendPlayerData(unsigned int _iFinal);

    // address=[0x15ba420]
    void SendToAll(unsigned int a2, short *_pvData0, unsigned int _uiDataLength0, short *_pvData1, unsigned int _uiDataLength1, bool a7);

    // address=[0x15ba650]
    void SendToHost(unsigned int a2, short *_pvData0, unsigned int _uiDataLength0, short *_pvData1, unsigned int _uiDataLength1, bool a7);

    // address=[0x15ba860]
    bool AddGame(struct SGameInfo &a2);

    // address=[0x15baa20]
    void ValidateGameList(void);

    // address=[0x15baba0]
    unsigned int GetLocalID(void);

    // address=[0x15bac30]
    int GetSlot(unsigned int a2);

    // address=[0x15bacb0]
    void NotifyClients(unsigned int a2);

    // address=[0x15bb0e0]
    bool IsExclusiveColor(int a2);

    // address=[0x15bb160]
    bool HostChoseMap(void *a2);

    // address=[0x15bb380]
    bool QuickMatchChoseMap(void *a1);

    // address=[0x15bb3b0]
    bool InviteAccepted(void *a2);

    // address=[0x15bb430]
    bool StartState(void *a1);

    // address=[0x15bb440]
    bool SearchHost(void *a2);

    // address=[0x15bb5b0]
    bool ClientSearchesGameHost(void *a2);

    // address=[0x15bb880]
    bool ClientReceivesGameInfo(void *Src);

    // address=[0x15bba10]
    bool ClientLoginHost(void *arg0);

    // address=[0x15bbdf0]
    bool ClientJoins(void *Src);

    // address=[0x15bc010]
    bool ClientWrongVersion(void *a1);

    // address=[0x15bc040]
    bool ClientWrongVersionAfterLobby(void *a1);

    // address=[0x15bc070]
    bool ClientReceivePlayerData(void *Src);

    // address=[0x15bc320]
    bool ClientReceivePlayerPing(void *Src);

    // address=[0x15bc370]
    bool ClientLobbyPrepare(void *a2);

    // address=[0x15bc3a0]
    bool ResendPlayerData(void *a2);

    // address=[0x15bc3c0]
    bool ResendPlayerPing(void *a2);

    // address=[0x15bc450]
    bool HostPressedStart(void *a2);

    // address=[0x15bc560]
    bool InitGameStruct(void *Src);

    // address=[0x15bc680]
    bool ResendFinalPData(void *a2);

    // address=[0x15bc720]
    bool ChatLine(void *pChatLine);

    // address=[0x15bc7c0]
    bool GameAlreadyFull(void *a1);

    // address=[0x15bc7f0]
    bool SendMapToClient(void *_iClient);

    // address=[0x15bce20]
    bool ClientReceiveMap(void *_pMessage);

    // address=[0x15bd220]
    bool ClientLeavesMyGame(void *a2);

    // address=[0x15bd290]
    bool PerformLeaveGame(void *a2);

    // address=[0x15bd2b0]
    bool SendChatLine(void *pChatLine);

    // address=[0x15bd420]
    bool UserDataChange(void *a2);

    // address=[0x15bd980]
    bool KickClient(void *a2);

    // address=[0x15bda30]
    bool WereKicked(void *a2);

    // address=[0x15bda70]
    bool UserChangeSlots(void *a2);

    // address=[0x15bde60]
    bool InitHostAfterLobby(void *a2);

    // address=[0x15bde90]
    bool InitClientAfterLobby(void *a2);

    // address=[0x15bdec0]
    bool WaitingForGameConnect(void *Src);

    // address=[0x15be220]
    bool HostInitGame(void *a2);

    // address=[0x15be3c0]
    bool HostStartTick(void *a2);

    // address=[0x15be460]
    bool RegClientConnect(void *a2);

    // address=[0x15be750]
    bool WereConnectedForGame(void *a1);

    // address=[0x15be760]
    bool ClientStartingGame(void *a2);

    // address=[0x15be8b0]
    bool ClientGameInited(void *a1);

    // address=[0x15be8e0]
    bool ClientStartTick(void *a2);

    // address=[0x15be980]
    bool HostGameInited(void *a2);

    // address=[0x15beaf0]
    bool GameSyncMsgGot(void *a2);

    // address=[0x15beba0]
    bool GameSync0MsgGot(void *a2);

    // address=[0x15bec60]
    bool GameInGameMsgGot(void *pMsg);

    // address=[0x15bed50]
    bool GameAsyncMsgGot(void *Src);

    // address=[0x15bee60]
    bool AmIStillAlive(void *a2);

    // address=[0x15bef30]
    bool HeIsStillAlive(void *a1);

    // address=[0x15bef60]
    bool GameInGamePackedGot(void *a2);

    // address=[0x15bf0e0]
    bool IsValidSaveGame(struct SGameInfo &sGameInfo);

    // address=[0x15c4970]
    bool DoNothing(void *a1);

    // Type information members
  public:
    bool m_bHost;
    bool m_bClient;
    bool m_bIsOnlineGame;
    CFsm *m_pFSM;
    CClientList *m_pClientList;
    CMsgStacks *m_pMsgStacks;
    int m_iInitTime;
    int m_iSearchForHostStopped;
    int m_iHostRun;
    int m_iLastPingTime;
    int m_iLastLoginTick;
    int m_iLoginAttempts;
    int m_iStartTickSignalTick;
    int m_iInitGameStartTick;
    int m_iNotReadyTimeoutTick;
    bool m_bInitFinished;
    int dword40;
    BYTE *m_pMapDownloadData;
    BYTE *m_pMapDownloadBlocks;
    bool m_bMapBeingDownloaded;
    bool m_bHasSentMap;
    int m_iMapDownloadBlocksArrived;
    DWORD m_iMapDownloadLastBlock;
    int m_iMapUploadSentChunks[MAX_PLAYER];
    int m_iMapUploadChunks[MAX_PLAYER];
    char *m_pMapUploadBuffer[MAX_PLAYER];
    int m_iMapUpload;
    int dwordBC;
    int m_iReadyTime;
    CSimpleNet *m_pSimpleNet;
    int m_iSyncA[MAX_PLAYER];
    int m_iSyncB[MAX_PLAYER];
    bool m_bHasError;
    std::list<SGameInfo> m_vGameInfos;
    std::list<CNet_Event> m_vNetEvents;

#pragma pack(1)
    struct {
        unsigned short m_iId;
        _DWORD m_uFlags;
        BYTE m_uPlayerMap;
        unsigned int m_uTick;
        _BYTE m_vMessages[961];
    } m_sBuffer;
    static_assert(sizeof(m_sBuffer) == 0x3cc, "CGameHost::m_sBuffer has incorrect size");

    struct SMessage;
    struct SSimpleMessage;
    struct SSearchMessage;
    struct SJoinMessage;
    struct SPingMessage;
    struct SChatLineMessage;
    struct SMapMessage;
    struct SChangeMessage;
    struct SSyncMessage;
    struct SSync0Message;
    struct SMessageBuffer;
    struct SMapDownloadBlock;
};

#endif // CGAMEHOST_H
