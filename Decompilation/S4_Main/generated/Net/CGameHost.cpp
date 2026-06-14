#if FALSE
#include "CGameHost.h"

// Definitions for class CGameHost

// address=[0x14aab10]
// Decompiled from int __thiscall CGameHost::GetBytesPerSecond(CGameHost *this)
unsigned int  CGameHost::GetBytesPerSecond(void) {
  
  if ( this->m_pSimpleNet )
    return this->m_pSimpleNet->GetBytesPerSecond(this->m_pSimpleNet);
  else
    return 0;
}


// address=[0x15b4e60]
// Decompiled from char __thiscall CGameHost::AllSend(CGameHost *this)
bool  CGameHost::AllSend(void) {
  
  int v2; // eax
  int iOwner; // esi
  int CurrentTickCounter; // eax
  char v5; // [esp-8h] [ebp-2Ch]
  char v6; // [esp-8h] [ebp-2Ch]
  CGameHost::SSync0Message sSync0Msg; // [esp+4h] [ebp-20h] BYREF
  int LocalPlayerId; // [esp+Ch] [ebp-18h]
  int iCurrentTick; // [esp+10h] [ebp-14h]
  int iMessagesInBuffer; // [esp+14h] [ebp-10h]
  BYTE *pMessageBufferPtr; // [esp+18h] [ebp-Ch]
  CNet_Event *evn; // [esp+1Ch] [ebp-8h]

  if ( !this->m_pMsgStacks && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3738, "m_pMsgStacks") == 1 )
    __debugbreak();
  if ( !this->m_pClientList && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3739, "m_pClientList") == 1 )
    __debugbreak();
  if ( (COMMUNICATION_TICK_VALUE & IEventEngine::GetCurrentTickCounter(g_pEvnEngine)) != 0 )
    return 1;
  if ( std::list<CNet_Event>::size(&this->m_vNetEvents) )
  {
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    this->m_sBuffer.m_uPlayerMap = (LocalPlayerId - 1) & 0xF | this->m_sBuffer.m_uPlayerMap & 0xF0;
    this->m_sBuffer.m_iId = 1054;
    this->m_sBuffer.m_uTick = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    iMessagesInBuffer = 0;
    pMessageBufferPtr = this->m_sBuffer.m_vMessages;
    while ( std::list<CNet_Event>::size(&this->m_vNetEvents) )
    {
      evn = std::list<CNet_Event>::front(&this->m_vNetEvents);
      iOwner = evn->m_iOwner;
      if ( iOwner != CPlayerManager::GetLocalPlayerId()
        && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3774, "evn.m_iOwner == g_cPlayerMgr.GetLocalPlayerId()") == 1 )
      {
        __debugbreak();
      }
      if ( evn->m_iData
        && (&pMessageBufferPtr[evn->m_iDataSize] >= &this->m_sBuffer.m_vMessages[949] || iMessagesInBuffer == 15) )
      {
        break;
      }
      evn->m_iTick = this->m_sBuffer.m_uTick;
      CMsgStacks::PushMsg(this->m_pMsgStacks, evn);
      evn->m_iOwner = 0;
      evn->m_iUnknown = 0;
      evn->m_iMsgNr = 0;
      evn->unk_15 = 0;
      evn->unk_16 = 0;
      evn->unk_17 = 0;
      memcpy(pMessageBufferPtr, evn, 0x20u);
      pMessageBufferPtr += 32;
      if ( evn->m_iData )
      {
        if ( !evn->m_iDataSize && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3805, "evn.m_iDataSize") == 1 )
          __debugbreak();
        memcpy(pMessageBufferPtr, evn->m_iData, evn->m_iDataSize);
        pMessageBufferPtr += evn->m_iDataSize;
        evn->m_iData = 0;
      }
      std::list<CNet_Event>::pop_front(&this->m_vNetEvents);
      ++iMessagesInBuffer;
    }
    this->m_sBuffer.m_uFlags = iMessagesInBuffer & 0xF | this->m_sBuffer.m_uFlags & 0xFFFFFFF0;
    v6 = CPlayerManager::GetLocalPlayerId() - 1;
    CurrentTickCounter = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    CMsgStacks::SetNumberOfExpectedMsgs(this->m_pMsgStacks, CurrentTickCounter, v6, iMessagesInBuffer);
    if ( this->m_bIsOnlineGame )
      CGameHost::SendToAll(this, 1054, &this->m_sBuffer, pMessageBufferPtr - (BYTE *)&this->m_sBuffer, 0, 0, 1u);
  }
  else
  {
    sSync0Msg.m_iPlayerId = CPlayerManager::GetLocalPlayerId();
    iCurrentTick = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    sSync0Msg.m_iCurrentTick = iCurrentTick;
    if ( this->m_bIsOnlineGame )
      CGameHost::SendToAll(this, 1055, &sSync0Msg, 5u, 0, 0, 1u);
    v5 = CPlayerManager::GetLocalPlayerId() - 1;
    v2 = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    CMsgStacks::SetNumberOfExpectedMsgs(this->m_pMsgStacks, v2, v5, 0);
  }
  return 1;
}


// address=[0x15b51a0]
// Decompiled from char __thiscall CGameHost::StartNewCycle(CGameHost *this, bool a2)
bool  CGameHost::StartNewCycle(bool a2) {
  
  int ValidTick; // esi
  int v3; // esi
  int v5; // esi
  int v6; // eax
  int v7; // [esp+4h] [ebp-8h] BYREF

  if ( !this->m_pMsgStacks && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3271, "m_pMsgStacks") == 1 )
    __debugbreak();
  if ( !this->m_pMsgStacks )
    return 0;
  if ( this->m_bIsOnlineGame )
  {
    ValidTick = CMsgStacks::GetValidTick(this->m_pMsgStacks);
    v3 = CMsgStacks::Getdt(this->m_pMsgStacks) + ValidTick;
    if ( v3 > CMsgStacks::GetVirtualTick(this->m_pMsgStacks) )
    {
LABEL_7:
      CGameHost::AllSend(this);
      CMsgStacks::AdvanceVirtualTick(this->m_pMsgStacks);
      this->dword40 = 0;
      return 0;
    }
  }
  else
  {
    v5 = CMsgStacks::GetValidTick(this->m_pMsgStacks) + 1;
    if ( v5 >= CMsgStacks::GetVirtualTick(this->m_pMsgStacks) )
      goto LABEL_7;
  }
  if ( (COMMUNICATION_TICK_VALUE & CMsgStacks::GetValidTick(this->m_pMsgStacks)) != 0
    && this->m_bIsOnlineGame
    && (v7 = 0,
        v6 = CGameHost::GetValidTick(this),
        !CMsgStacks::IsMsgStackValid(this->m_pMsgStacks, v6 + 1, (unsigned int *)&v7)) )
  {
    CGameHost::NotifyClients(this, v7);
    return 0;
  }
  else if ( CMsgStacks::IsEmpty(this->m_pMsgStacks, 0) )
  {
    if ( !a2 )
      return 1;
    CMsgStacks::TriggerTime(this->m_pMsgStacks);
    CMsgStacks::AdvanceValidTick(this->m_pMsgStacks);
    CMsgStacks::AdvanceVirtualTick(this->m_pMsgStacks);
    this->dword40 = 0;
    return 1;
  }
  else
  {
    if ( BBSupportDbgReport(
           1,
           "Net\\GameHost.cpp",
           3316,
           "Internal Error (N0) occured! Aborting...\nInterner Fehler (N0) aufgetreten. Das Programm wird beendet!") == 1 )
      __debugbreak();
    return 0;
  }
}


// address=[0x15b5360]
// Decompiled from int __thiscall CGameHost::GetValidTick(CGameHost *this)
int  CGameHost::GetValidTick(void) {
  
  return CMsgStacks::GetValidTick(this->m_pMsgStacks);
}


// address=[0x15b5380]
// Decompiled from int __thiscall CGameHost::GetVirtualTick(CGameHost *this)
int  CGameHost::GetVirtualTick(void) {
  
  return CMsgStacks::GetVirtualTick(this->m_pMsgStacks);
}


// address=[0x15b53a0]
// Decompiled from char __thiscall CGameHost::RegisterMsgStacks(CGameHost *this, struct CMsgStacks *a2)
bool  CGameHost::RegisterMsgStacks(class CMsgStacks * a2) {
  
  if ( this->m_pMsgStacks )
    return 0;
  this->m_pMsgStacks = a2;
  return 1;
}


// address=[0x15b53d0]
// Decompiled from char __thiscall CGameHost::InitAsClient(CGameHost *this, unsigned int a2)
bool  CGameHost::InitAsClient(unsigned int a2) {
  
  if ( !this->m_pFSM && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3237, "m_pFsm") == 1 )
    __debugbreak();
  if ( a2 )
    CFsm::Control(this->m_pFSM, 1016, 0);
  else
    CFsm::Control(this->m_pFSM, 1008, 0);
  return 1;
}


// address=[0x15b5440]
// Decompiled from char __thiscall CGameHost::InitAsHost(CGameHost *this, unsigned int a2)
bool  CGameHost::InitAsHost(unsigned int a2) {
  
  if ( !this->m_pFSM && BBSupportDbgReport(2, "Net\\GameHost.cpp", 589, "m_pFsm") == 1 )
    __debugbreak();
  if ( a2 )
    CFsm::Control(this->m_pFSM, 1012, 0);
  else
    CFsm::Control(this->m_pFSM, 1007, 0);
  return 1;
}


// address=[0x15b54b0]
// Decompiled from CGameHost *__thiscall CGameHost::CGameHost(CGameHost *this, byte arg0)
 CGameHost::CGameHost(bool arg0) {
  
  char *v2; // eax
  std::string *v4; // [esp+4h] [ebp-50h]
  CClientList *v5; // [esp+14h] [ebp-40h]
  CDaoIndexFieldInfo *v6; // [esp+18h] [ebp-3Ch]
  CFsm *v7; // [esp+1Ch] [ebp-38h]
  CFsm *C; // [esp+20h] [ebp-34h]
  _BYTE v10[28]; // [esp+28h] [ebp-2Ch] BYREF
  int v11; // [esp+50h] [ebp-4h]

  IEventHandler::IEventHandler(this, 2000);
  v11 = 0;
  this->__vftable = (CGameHost_vtbl *)&CGameHost::_vftable_;
  this->m_bHost = 0;
  this->m_bClient = 0;
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
  this->m_bMapBeingDownloaded = 0;
  this->m_bHasSentMap = 0;
  this->m_iMapDownloadBlocksArrived = 0;
  this->m_iMapUpload = 0;
  this->dwordBC = 0;
  this->m_iReadyTime = 0;
  this->m_pSimpleNet = 0;
  std::list<SGameInfo>::list<SGameInfo>(&this->m_vGameInfos);
  std::list<CNet_Event>::list<CNet_Event>(&this->m_vNetEvents);
  memset(this->m_iMapUploadSentChunks, 0, sizeof(this->m_iMapUploadSentChunks));
  memset(this->m_iMapUploadChunks, 0, sizeof(this->m_iMapUploadChunks));
  memset(this->m_pMapUploadBuffer, 0, sizeof(this->m_pMapUploadBuffer));
  memset(this->m_iSyncA, 0, sizeof(this->m_iSyncA));
  memset(this->m_iSyncB, 0, sizeof(this->m_iSyncB));
  memset(&this->m_sBuffer, 0, 971u);
  CGameHost::FillHandlersArray(this);
  C = (CFsm *)operator new(0x1Cu);
  LOBYTE(v11) = 3;
  if ( C )
    v7 = (CFsm *)CFsm::CFsm(C, this, 1500, 34);
  else
    v7 = 0;
  LOBYTE(v11) = 2;
  this->m_pFSM = v7;
  CFsm::DefineTransition(this->m_pFSM, 34, 1, 1007, InitHostNetwork);
  CFsm::DefineTransition(this->m_pFSM, 54, 1, 1007, InitHostNetwork);
  CFsm::DefineTransition(this->m_pFSM, 2, 70, 1060, InviteAccepted);
  CFsm::DefineTransition(this->m_pFSM, 4, 70, 1060, InviteAccepted);
  CFsm::DefineTransition(this->m_pFSM, 55, 70, 1060, InviteAccepted);
  CFsm::DefineTransition(this->m_pFSM, 70, 40, 1024, ClientLoginHost);
  CFsm::DefineTransition(this->m_pFSM, 70, 5, 1057, ClientLobbyPrepare);
  CFsm::DefineTransition(this->m_pFSM, 1, 1, 1051, HostChoseMap);
  CFsm::DefineTransition(this->m_pFSM, 1, 69, 1059, QuickMatchChoseMap);
  CFsm::DefineTransition(this->m_pFSM, 1, 1, 1000, DoNothing);
  CFsm::DefineTransition(this->m_pFSM, 1, 3, 1009, OnHostWait);
  CFsm::DefineTransition(this->m_pFSM, 69, 3, 1009, OnHostWait);
  CFsm::DefineTransition(this->m_pFSM, 69, 40, 1024, ClientLoginHost);
  CFsm::DefineTransition(this->m_pFSM, 69, 5, 1057, ClientLobbyPrepare);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1000, ClientSearchesGameHost);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1001, DoNothing);
  CFsm::DefineTransition(this->m_pFSM, 5, 3, 1058, DoNothing);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1023, ClientJoins);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1027, ResendPlayerData);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1035, ResendPlayerPing);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1036, ChatLine);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1050, SendChatLine);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1047, ClientLeavesMyGame);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1052, UserDataChange);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1053, KickClient);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1056, UserChangeSlots);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1042, SendMapToClient);
  CFsm::DefineTransition(this->m_pFSM, 3, 3, 1029, HostPressedStart);
  CFsm::DefineTransition(this->m_pFSM, 3, 15, 1030, ResendFinalPData);
  CFsm::DefineTransition(this->m_pFSM, 15, 15, 1012, DoNothing);
  CFsm::DefineTransition(this->m_pFSM, 34, 2, 1008, InitClientNetwork);
  CFsm::DefineTransition(this->m_pFSM, 54, 2, 1008, InitClientNetwork);
  CFsm::DefineTransition(this->m_pFSM, 2, 55, 1010, DoNothing);
  CFsm::DefineTransition(this->m_pFSM, 55, 4, 1046, SearchHost);
  CFsm::DefineTransition(this->m_pFSM, 55, 40, 1024, ClientLoginHost);
  CFsm::DefineTransition(this->m_pFSM, 4, 4, 1022, ClientReceivesGameInfo);
  CFsm::DefineTransition(this->m_pFSM, 4, 4, 1046, SearchHost);
  CFsm::DefineTransition(this->m_pFSM, 4, 40, 1024, ClientLoginHost);
  CFsm::DefineTransition(this->m_pFSM, 40, 5, 1025, ClientLobbyPrepare);
  CFsm::DefineTransition(this->m_pFSM, 40, 5, 1057, ClientLobbyPrepare);
  CFsm::DefineTransition(this->m_pFSM, 40, 40, 1022, DoNothing);
  CFsm::DefineTransition(this->m_pFSM, 40, 4, 1038, GameAlreadyFull);
  CFsm::DefineTransition(this->m_pFSM, 40, 4, 1048, ClientWrongVersion);
  CFsm::DefineTransition(this->m_pFSM, 5, 5, 1026, ClientReceivePlayerData);
  CFsm::DefineTransition(this->m_pFSM, 5, 5, 1034, ClientReceivePlayerPing);
  CFsm::DefineTransition(this->m_pFSM, 5, 5, 1036, ChatLine);
  CFsm::DefineTransition(this->m_pFSM, 5, 5, 1049, PerformLeaveGame);
  CFsm::DefineTransition(this->m_pFSM, 5, 5, 1050, SendChatLine);
  CFsm::DefineTransition(this->m_pFSM, 5, 5, 1053, WereKicked);
  CFsm::DefineTransition(this->m_pFSM, 5, 5, 1043, ClientReceiveMap);
  CFsm::DefineTransition(this->m_pFSM, 5, 20, 1032, InitGameStruct);
  CFsm::DefineTransition(this->m_pFSM, 20, 20, 1032, InitGameStruct);
  CFsm::DefineTransition(this->m_pFSM, 34, 14, 1012, InitHostAfterLobby);
  CFsm::DefineTransition(this->m_pFSM, 14, 15, 1009, WaitingForGameConnect);
  CFsm::DefineTransition(this->m_pFSM, 15, 15, 1013, WaitingForGameConnect);
  CFsm::DefineTransition(this->m_pFSM, 15, 18, 1014, HostInitGame);
  CFsm::DefineTransition(this->m_pFSM, 18, 30, 1020, HostGameInited);
  CFsm::DefineTransition(this->m_pFSM, 18, 18, 1018, HostGameInited);
  CFsm::DefineTransition(this->m_pFSM, 30, 30, 1018, HostGameInited);
  CFsm::DefineTransition(this->m_pFSM, 30, 30, 1039, GameAsyncMsgGot);
  CFsm::DefineTransition(this->m_pFSM, 30, 17, 1015, HostStartTick);
  CFsm::DefineTransition(this->m_pFSM, 34, 20, 1016, InitClientAfterLobby);
  CFsm::DefineTransition(this->m_pFSM, 20, 10, 1031, RegClientConnect);
  CFsm::DefineTransition(this->m_pFSM, 20, 10, 1010, RegClientConnect);
  CFsm::DefineTransition(this->m_pFSM, 10, 10, 1048, ClientWrongVersionAfterLobby);
  CFsm::DefineTransition(this->m_pFSM, 10, 10, 1045, RegClientConnect);
  CFsm::DefineTransition(this->m_pFSM, 10, 11, 1033, WereConnectedForGame);
  CFsm::DefineTransition(this->m_pFSM, 11, 25, 1017, ClientStartingGame);
  CFsm::DefineTransition(this->m_pFSM, 25, 27, 1020, ClientGameInited);
  CFsm::DefineTransition(this->m_pFSM, 27, 17, 1019, ClientStartTick);
  CFsm::DefineTransition(this->m_pFSM, 27, 17, 1040, ClientStartTick);
  CFsm::DefineTransition(this->m_pFSM, 27, 27, 1039, GameAsyncMsgGot);
  CFsm::DefineTransition(this->m_pFSM, 17, 17, 1021, GameInGameMsgGot);
  CFsm::DefineTransition(this->m_pFSM, 17, 17, 1005, GameSyncMsgGot);
  CFsm::DefineTransition(this->m_pFSM, 17, 17, 1055, GameSync0MsgGot);
  CFsm::DefineTransition(this->m_pFSM, 17, 17, 1039, GameAsyncMsgGot);
  CFsm::DefineTransition(this->m_pFSM, 17, 17, 1040, AmIStillAlive);
  CFsm::DefineTransition(this->m_pFSM, 17, 17, 1041, HeIsStillAlive);
  CFsm::DefineTransition(this->m_pFSM, 17, 17, 1054, GameInGamePackedGot);
  CLanLobby::SetGameHost(this);
  this->m_iInitTime = 0;
  v6 = (CDaoIndexFieldInfo *)operator new(0x14u);
  LOBYTE(v11) = 4;
  if ( v6 )
    v5 = (CClientList *)CClientList::CClientList(v6);
  else
    v5 = 0;
  LOBYTE(v11) = 2;
  this->m_pClientList = v5;
  if ( !this->m_bIsOnlineGame )
    goto LABEL_12;
  this->m_pSimpleNet = CreateSimpleNet();
  if ( this->m_pSimpleNet )
  {
    if ( this->m_pSimpleNet->WasError(this->m_pSimpleNet) )
    {
      v4 = this->m_pSimpleNet->GetLastErrorString(this->m_pSimpleNet, v10);
      LOBYTE(v11) = 5;
      v2 = std::string::c_str(v4);
      BBSupportTracePrintF(3, "GameHost.cpp: %s!", v2);
      LOBYTE(v11) = 2;
      std::string::~string(v10);
      this->m_bHasError = 1;
      return this;
    }
LABEL_12:
    this->m_bHasError = 0;
    return this;
  }
  BBSupportTracePrint(3, "GameHost.cpp: Error initializing Network!");
  this->m_bHasError = 1;
  return this;
}


// address=[0x15b5ed0]
// Decompiled from int __thiscall CGameHost::~CGameHost(CGameHost *this)
 CGameHost::~CGameHost(void) {
  
  CFsm *m_pFSM; // [esp+28h] [ebp-20h]
  CClientList *m_pClientList; // [esp+2Ch] [ebp-1Ch]
  CMsgStacks *m_pMsgStacks; // [esp+30h] [ebp-18h]
  int i; // [esp+34h] [ebp-14h]

  this->__vftable = (CGameHost_vtbl *)&CGameHost::_vftable_;
  if ( this->m_pMsgStacks )
  {
    m_pMsgStacks = this->m_pMsgStacks;
    if ( m_pMsgStacks )
      (**(void (__thiscall ***)(CMsgStacks *, int))m_pMsgStacks)(m_pMsgStacks, 1);
    this->m_pMsgStacks = 0;
  }
  if ( this->m_pClientList )
  {
    m_pClientList = this->m_pClientList;
    if ( m_pClientList )
      ((void (__thiscall *)(CClientList *, int))m_pClientList->vftable->j_??_ECClientList@@UAEPAXI@Z)(m_pClientList, 1);
    this->m_pClientList = 0;
  }
  if ( this->m_pFSM )
  {
    m_pFSM = this->m_pFSM;
    if ( m_pFSM )
      delete m_pFSM;
    this->m_pFSM = 0;
  }
  if ( this->m_pMapDownloadBlocks )
  {
    operator delete[](this->m_pMapDownloadBlocks);
    this->m_pMapDownloadBlocks = 0;
  }
  if ( this->m_pMapDownloadData )
  {
    operator delete[](this->m_pMapDownloadData);
    this->m_pMapDownloadData = 0;
  }
  if ( this->m_pSimpleNet )
  {
    this->m_pSimpleNet->Delete(this->m_pSimpleNet);
    this->m_pSimpleNet = 0;
  }
  for ( i = 0; i < 8; ++i )
  {
    if ( this->m_pMapUploadBuffer[i] )
    {
      operator delete((void *)this->m_pMapUploadBuffer[i]);
      this->m_pMapUploadBuffer[i] = 0;
    }
  }
  std::list<CNet_Event>::~list<CNet_Event>();
  std::list<SGameInfo>::~list<SGameInfo>();
  return IEventHandler::~IEventHandler((void **)&this->__vftable);
}


// address=[0x15b60d0]
// Decompiled from char __thiscall CGameHost::PushMsg(CGameHost *this, struct CNet_Event *_rMsg)
bool  CGameHost::PushMsg(class CNet_Event & _rMsg) {
  
  int m_iOwner; // esi

  if ( _rMsg->m_iData
    && !_rMsg->m_iDataSize
    && BBSupportDbgReportF(
         2,
         "Net\\GameHost.cpp",
         3859,
         "Fatal: m_iData set, but m_iDataSize == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1 )
  {
    __debugbreak();
  }
  if ( CPlayerManager::IsAI(_rMsg->m_iOwner) )
    return CMsgStacks::PushMsg(this->m_pMsgStacks, _rMsg);
  m_iOwner = _rMsg->m_iOwner;
  if ( m_iOwner != CPlayerManager::GetLocalPlayerId()
    && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3865, "_rMsg.m_iOwner == g_cPlayerMgr.GetLocalPlayerId()") == 1 )
  {
    __debugbreak();
  }
  std::list<CNet_Event>::push_back(_rMsg);
  return 1;
}


// address=[0x15b6190]
// Decompiled from void __thiscall CGameHost::PushAsyncMsg(CGameHost *this, CNet_Event *_rEvent, unsigned __int8 _iPlayerMap)
void  CGameHost::PushAsyncMsg(class CNet_Event & _rEvent, unsigned char _iPlayerMap) {
  
  uint iPeerId; // eax
  uint iIp; // [esp-18h] [ebp-458h]
  size_t iMessageSize; // [esp-Ch] [ebp-44Ch]
  int i; // [esp+8h] [ebp-438h]
  CGameHost::SMessage sMessage; // [esp+Ch] [ebp-434h] BYREF
  CEvn_Logic v9; // [esp+410h] [ebp-30h] BYREF
  int exceptionBlock; // [esp+43Ch] [ebp-4h]

  CTrace::Print("GameHost.cpp: Sending Async Msg to those Players: %x", _iPlayerMap);
  if ( this->m_bIsOnlineGame && !CPlayerManager::IsAI(_rEvent->m_iOwner) )
  {
    for ( i = 1; i <= CPlayerManager::LastPlayerId(); ++i )
    {
      if ( !CPlayerManager::IsAI(i) && CPlayerManager::GetLocalPlayerId() != i && ((1 << (i - 1)) & _iPlayerMap) != 0 )
      {
        sMessage.m_iId = 1039;
        memcpy(&sMessage.m_cEvent, _rEvent, sizeof(sMessage.m_cEvent));
        memcpy(sMessage.m_iData, _rEvent->m_iData, _rEvent->m_iDataSize);
        iMessageSize = _rEvent->m_iDataSize + 34;
        iIp = CPlayerManager::IP(i);
        iPeerId = CPlayerManager::PeerId(i);
        this->m_pSimpleNet->PushMessage(this->m_pSimpleNet, iPeerId, iIp, 3105u, &sMessage, iMessageSize, 1, 1);
        CTrace::Print("GameHost.cpp: Delivering Async Msg to Owner %d!", i);
      }
    }
  }
  if ( (_iPlayerMap & (1 << (CPlayerManager::GetLocalPlayerId() - 1))) != 0 )
  {
    CEvn_Logic::CEvn_Logic(
      &v9,
      _rEvent->m_iEventId,
      _rEvent->m_wParam,
      _rEvent->m_lParam,
      _rEvent->m_iOwner,
      (uint)_rEvent->m_iData,
      _rEvent->m_iDataSize);
    exceptionBlock = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, &v9);
    exceptionBlock = -1;
    CEvn_Logic::~CEvn_Logic(&v9);
  }
}


// address=[0x15b63b0]
// Decompiled from int __thiscall CGameHost::PopMsg(CGameHost *this, int a2)
class CNet_Event  CGameHost::PopMsg(void a2) {
  
  CMsgStacks::PopMsg(this->m_pMsgStacks, a2);
  return a2;
}


// address=[0x15b63f0]
// Decompiled from int __thiscall CGameHost::GetLocalIP(CGameHost *this)
long  CGameHost::GetLocalIP(void) {
  
  return this->m_pSimpleNet->GetCurrentLocalIPLong(this->m_pSimpleNet);
}


// address=[0x15b6420]
// Decompiled from int __thiscall CGameHost::GetMessageLength(CGameHost *this)
unsigned short  CGameHost::GetMessageLength(void) {
  
  return this->m_pSimpleNet->GetLastDataLength(this->m_pSimpleNet, this) - 2;
}


// address=[0x15b6450]
// Decompiled from void __thiscall CGameHost::GameInitalized(CGameHost *this)
void  CGameHost::GameInitalized(void) {
  
  CEvn_Event v1; // [esp+8h] [ebp-28h] BYREF
  int v2; // [esp+2Ch] [ebp-4h]

  if ( this->m_bIsOnlineGame )
  {
    CFsm::Control(this->m_pFSM, 1020, 0);
  }
  else
  {
    CEvn_Event::CEvn_Event(&v1, 0x19u, 0, 0, 0);
    v2 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, &v1);
    v2 = -1;
    CEvn_Event::~CEvn_Event(&v1);
  }
}


// address=[0x15b64f0]
// Decompiled from void __thiscall CGameHost::ContinueSearchForHost(CGameHost *this)
void  CGameHost::ContinueSearchForHost(void) {
  
  this->m_iSearchForHostStopped = 0;
}


// address=[0x15b6510]
// Decompiled from char __thiscall CGameHost::Run(CGameHost *this)
bool  CGameHost::Run(void) {
  
  char *v1; // eax
  OnlineManager *Instance; // eax
  int v3; // eax
  uint v4; // eax
  const char *v5; // eax
  uint CurrentTickCounter; // eax
  const char *v7; // eax
  DWORD v8; // esi
  DWORD v9; // esi
  DWORD v10; // esi
  DWORD v11; // esi
  int Size; // esi
  DWORD v13; // esi
  struct CEvn_Event *v15; // [esp+18h] [ebp-9A8h]
  std::string *v16; // [esp+20h] [ebp-9A0h]
  float v17; // [esp+28h] [ebp-998h]
  unsigned int i; // [esp+2Ch] [ebp-994h]
  _BYTE v20[32]; // [esp+36h] [ebp-98Ah] BYREF
  __int16 v21; // [esp+438h] [ebp-588h]
  _BYTE v22[32]; // [esp+43Ah] [ebp-586h] BYREF
  _BYTE v23[28]; // [esp+83Ch] [ebp-184h] BYREF
  CEvn_Event v24; // [esp+858h] [ebp-168h] BYREF
  CNet_Event v25; // [esp+870h] [ebp-150h] BYREF
  CNet_Event Src; // [esp+890h] [ebp-130h] BYREF
  CHAR OutputString[256]; // [esp+8B0h] [ebp-110h] BYREF
  int v28; // [esp+9BCh] [ebp-4h]

  if ( !this->m_pFSM || !this->m_bHost && !this->m_bClient )
    return 1;
  CGameHost::DeliverSimpleMessage(this);
  if ( !this->m_pSimpleNet->Run(this->m_pSimpleNet) )
  {
    v16 = this->m_pSimpleNet->GetLastErrorString(this->m_pSimpleNet, v23);
    v28 = 0;
    v1 = std::string::c_str(v16);
    CTrace::Print("GameHost.cpp: %s!", v1);
    v28 = -1;
    std::string::~string(v23);
  }
  if ( this->m_bHost )
  {
    for ( i = 0; i < g_pGameType->m_iActualPlayerCount; ++i )
    {
      if ( g_pGameType->m_sPlayerPeerId[i] != -1 )
      {
        Instance = (OnlineManager *)OnlineManager::GetInstance();
        if ( !OnlineManager::IsInSession(Instance)
          || (v3 = StormManager::GetInstance(), g_pGameType->m_sPlayerPeerId[i] != StormManager::GetLocalPeerId(v3)) )
        {
          if ( this->m_iSyncB[i] > 20 )
          {
            v17 = (float)this->m_iSyncA[i] / (float)this->m_iSyncB[i];
            sprintf(OutputString, "fAverageSync %f\n", v17);
            OutputDebugStringA(OutputString);
            if ( v17 >= 3.0 )
            {
              if ( v17 > (float)(CMsgStacks::GetNumberOfStacks((pairNode *)this->m_pMsgStacks) / 2 + 1) )
              {
                CurrentTickCounter = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
                CNet_Event::CNet_Event(&v25, 0xFA7u, 0x23u, 0, 0, 0, 0, CurrentTickCounter);
                v28 = 2;
                memcpy(v20, &v25, sizeof(v20));
                v7 = this->m_pSimpleNet->GetIPString(this->m_pSimpleNet, g_pGameType->m_uiIPPlayer[i]);
                CTrace::Print("GameHost.cpp: Restrain player index %u, IP %s!", i, v7);
                v28 = -1;
                CNet_Event::~CNet_Event(&v25);
              }
            }
            else
            {
              v4 = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
              CNet_Event::CNet_Event(&Src, 0xFA7u, 0xFFFFFFDD, 0, 0, 0, 0, v4);
              v28 = 1;
              v21 = 1039;
              memcpy(v22, &Src, sizeof(v22));
              v5 = this->m_pSimpleNet->GetIPString(this->m_pSimpleNet, g_pGameType->m_uiIPPlayer[i]);
              CTrace::Print("GameHost.cpp: Boosting player index %u, IP %s!", i, v5);
              v28 = -1;
              CNet_Event::~CNet_Event(&Src);
            }
            this->m_iSyncB[i] = 0;
            this->m_iSyncA[i] = 0;
          }
        }
      }
    }
  }
  if ( CFsm::CurrentState(this->m_pFSM) == 10 )
  {
    if ( !this->m_iLastLoginTick )
      this->m_iLastLoginTick = timeGetTime();
    v8 = this->m_iLastLoginTick + 1000;
    if ( v8 < timeGetTime() )
    {
      CFsm::Control(this->m_pFSM, 1045, (void *)1);
      ++this->m_iLoginAttempts;
      CTrace::Print("GameHost.cpp: Resending login after lobby request!");
      this->m_iLastLoginTick = timeGetTime();
      if ( this->m_iLoginAttempts > (unsigned int)(CStaticConfigVarInt::operator int(&g_iNetAfterLobbyConnectTimeout)
                                                 / 1000) )
      {
        CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, (void *)2408);
        CGameStateHandler::Switch(CStateMainMenu::DynamicCreateFunc, 0);
      }
    }
  }
  if ( CFsm::CurrentState(this->m_pFSM) == 40 )
  {
    v9 = this->m_iNotReadyTimeoutTick + CStaticConfigVarInt::operator int(&g_iNotReadyGameStartTimeout);
    if ( v9 < timeGetTime() )
    {
      v15 = CEvn_Event::CEvn_Event(&v24, 0xFA1u, 0, 0, 0);
      v28 = 3;
      IEventEngine::SendAMessage(g_pEvnEngine, v15);
      v28 = -1;
      CEvn_Event::~CEvn_Event(&v24);
      this->m_iNotReadyTimeoutTick = timeGetTime();
    }
  }
  if ( (CFsm::CurrentState(this->m_pFSM) == 30 || CFsm::CurrentState(this->m_pFSM) == 18) && this->m_iInitTime )
  {
    if ( CGameType::GetNumberHumanPlayers(g_pGameType) <= 1 )
    {
      CFsm::Control(this->m_pFSM, 1015, 0);
    }
    else
    {
      v10 = this->m_iInitTime + CStaticConfigVarInt::operator int(&g_iNotReadyGameStartTimeout);
      if ( v10 < timeGetTime() )
      {
        CTrace::Print("GameHost.cpp: One or more clients r not ready for game. Starting it due to timeout!");
        CFsm::Control(this->m_pFSM, 1015, 0);
      }
    }
  }
  if ( CFsm::CurrentState(this->m_pFSM) == 27 )
  {
    if ( !this->m_iStartTickSignalTick )
      this->m_iStartTickSignalTick = timeGetTime();
    v11 = this->m_iStartTickSignalTick + CStaticConfigVarInt::operator int(&g_iNetClientWaitingStartTick);
    if ( v11 < timeGetTime() )
    {
      CTrace::Print("GameHost.cpp: No start tick signal from host got. Starting due to timeout!");
      CFsm::Control(this->m_pFSM, 1019, 0);
    }
  }
  if ( CFsm::CurrentState(this->m_pFSM) == 15 )
  {
    if ( !this->m_iInitGameStartTick )
      this->m_iInitGameStartTick = timeGetTime();
    Size = CClientList::GetSize(this->m_pClientList);
    if ( Size == CGameType::HumanPlayers(g_pGameType) - 1 )
    {
      CFsm::Control(this->m_pFSM, 1014, 0);
    }
    else
    {
      v13 = this->m_iInitGameStartTick + CStaticConfigVarInt::operator int(&g_iHostWaitAfterLobbyForClientsTimeout);
      if ( v13 < timeGetTime() )
      {
        CTrace::Print("GameHost.cpp: One or more clients missing after lobby. Initing game due to timeout!");
        CFsm::Control(this->m_pFSM, 1014, 0);
      }
    }
  }
  if ( this->m_bClient )
    CGameHost::OnClientRun(this);
  else
    CGameHost::OnHostRun(this);
  return 0;
}


// address=[0x15b6c60]
// Decompiled from char __thiscall CGameHost::StartIniFileGame(CGameHost *this, wchar_t *Source)
bool  CGameHost::StartIniFileGame(wchar_t const * Source) {
  
  void *v2; // esp
  wchar_t *v3; // eax
  wchar_t *v4; // eax
  int v5; // eax
  size_t v6; // eax
  size_t v7; // eax
  size_t v8; // eax
  size_t v9; // eax
  int LocalSlot; // eax
  const char *v11; // eax
  size_t v12; // eax
  wchar_t *v13; // eax
  wchar_t *v14; // eax
  std::wstring v16; // [esp-50h] [ebp-1CB4h] BYREF
  BOOL v17; // [esp-34h] [ebp-1C98h]
  int v18; // [esp-30h] [ebp-1C94h]
  std::string v19; // [esp-2Ch] [ebp-1C90h] BYREF
  std::string v20; // [esp-2Ch] [ebp-1C90h] SPLIT BYREF
  int v21; // [esp-10h] [ebp-1C74h] BYREF
  CClassNetGameIniBuffer v22; // [esp+0h] [ebp-1C64h] BYREF
  void *v23; // [esp+8h] [ebp-1C5Ch]
  std::string *v24; // [esp+Ch] [ebp-1C58h]
  struct std::string *v25; // [esp+10h] [ebp-1C54h]
  std::string *v26; // [esp+14h] [ebp-1C50h]
  void *v27; // [esp+18h] [ebp-1C4Ch]
  std::wstring *v28; // [esp+1Ch] [ebp-1C48h]
  int iGameId; // [esp+20h] [ebp-1C44h]
  std::wstring *a2; // [esp+24h] [ebp-1C40h]
  int v31; // [esp+28h] [ebp-1C3Ch]
  std::wstring *v32; // [esp+2Ch] [ebp-1C38h]
  std::wstring *a1; // [esp+30h] [ebp-1C34h]
  void *v34; // [esp+34h] [ebp-1C30h]
  int iLadderGame; // [esp+38h] [ebp-1C2Ch]
  int iClanGame; // [esp+3Ch] [ebp-1C28h]
  int v37; // [esp+40h] [ebp-1C24h]
  int m_iActualPlayerCount; // [esp+44h] [ebp-1C20h]
  size_t v39; // [esp+48h] [ebp-1C1Ch]
  int v40; // [esp+4Ch] [ebp-1C18h]
  size_t v41; // [esp+50h] [ebp-1C14h]
  size_t Size; // [esp+54h] [ebp-1C10h]
  signed int v43; // [esp+58h] [ebp-1C0Ch]
  BOOL v44; // [esp+5Ch] [ebp-1C08h]
  BOOL v45; // [esp+60h] [ebp-1C04h]
  BOOL v46; // [esp+64h] [ebp-1C00h]
  DWORD v47; // [esp+68h] [ebp-1BFCh]
  int v48; // [esp+6Ch] [ebp-1BF8h]
  int v49; // [esp+70h] [ebp-1BF4h]
  size_t ElementSize; // [esp+74h] [ebp-1BF0h]
  int iPlayerCount; // [esp+78h] [ebp-1BECh]
  unsigned int iSaveGame; // [esp+7Ch] [ebp-1BE8h]
  int iProductId; // [esp+80h] [ebp-1BE4h]
  int j; // [esp+84h] [ebp-1BE0h]
  char v55; // [esp+88h] [ebp-1BDCh]
  char v56; // [esp+89h] [ebp-1BDBh]
  char MapData; // [esp+8Ah] [ebp-1BDAh]
  bool v58; // [esp+8Bh] [ebp-1BD9h]
  int IntValue; // [esp+8Ch] [ebp-1BD8h]
  char *EndPtr; // [esp+90h] [ebp-1BD4h] BYREF
  bool bIsLadderGame; // [esp+97h] [ebp-1BCDh]
  CGameHost *pGameHost; // [esp+98h] [ebp-1BCCh]
  bool bIsClanGame; // [esp+9Fh] [ebp-1BC5h]
  void *Buffer; // [esp+A0h] [ebp-1BC4h]
  _BYTE *v65; // [esp+A4h] [ebp-1BC0h]
  signed int i; // [esp+A8h] [ebp-1BBCh]
  char *pStrFind; // [esp+ACh] [ebp-1BB8h]
  struct CGameChunkGeneral sGeneralInfo; // [esp+B0h] [ebp-1BB4h] BYREF
  struct SGameInfo sGameInfo; // [esp+A18h] [ebp-124Ch] BYREF
  char v70[88]; // [esp+EA0h] [ebp-DC4h] BYREF
  std::wstring v71; // [esp+EF8h] [ebp-D6Ch] BYREF
  std::wstring v72; // [esp+F14h] [ebp-D50h] BYREF
  CFile v73; // [esp+F30h] [ebp-D34h] BYREF
  std::wstring v74; // [esp+F78h] [ebp-CECh] BYREF
  std::wstring swSaveFilePath; // [esp+F94h] [ebp-CD0h] BYREF
  std::wstring v76; // [esp+FB0h] [ebp-CB4h] BYREF
  std::wstring swGameName; // [esp+FCCh] [ebp-C98h] BYREF
  std::wstring swMapName; // [esp+FE8h] [ebp-C7Ch] BYREF
  std::wstring swMPGameName; // [esp+1004h] [ebp-C60h] BYREF
  std::wstring v80[9]; // [esp+1020h] [ebp-C44h] BYREF
  _DWORD v81[9]; // [esp+111Ch] [ebp-B48h] BYREF
  wchar_t Ext[256]; // [esp+1140h] [ebp-B24h] BYREF
  wchar_t v83[256]; // [esp+1340h] [ebp-924h] BYREF
  wchar_t Dir[256]; // [esp+1540h] [ebp-724h] BYREF
  _BYTE v85[256]; // [esp+1740h] [ebp-524h] BYREF
  WCHAR Filename[260]; // [esp+1840h] [ebp-424h] BYREF
  wchar_t swpGameName[256]; // [esp+1A48h] [ebp-21Ch] BYREF
  wchar_t swpPlayerIp[256]; // [esp+1A48h] [ebp-21Ch] SPLIT BYREF
  wchar_t Drive[4]; // [esp+1C48h] [ebp-1Ch] BYREF
  int *v90; // [esp+1C54h] [ebp-10h]
  int exceptionBlock; // [esp+1C60h] [ebp-4h]

  v2 = alloca(7252);
  v90 = &v21;
  pGameHost = this;
  GetModuleFileNameW(0, Filename, 0x208u);
  j___wsplitpath(Filename, Drive, Dir, v83, Ext);
  GetCurrentDirectoryW(0x200u, Dir);
  MyWStrNCopy(Filename, Dir, 0x208u);
  j__wcscat(Filename, asc_37C7ED4);
  j__wcscat(Filename, Source);
  CFile::CFile(&v73);
  exceptionBlock = 1;
  v32 = (std::wstring *)std::wstring::wstring(&v72, Filename);
  a1 = v32;
  LOBYTE(exceptionBlock) = 2;
  CFile::Open(&v73, v32, CFile_TEXT|CFile_READ, UNUSED_ARG(), UNUSED_ARG());
  LOBYTE(exceptionBlock) = 1;
  std::wstring::~wstring(&v72);
  exceptionBlock = 0;
  ElementSize = CFile::Size(&v73);
  Size = ElementSize + 128;
  v34 = operator new[](ElementSize + 128);
  Buffer = v34;
  memset(v34, 0, Size);
  CFile::Read(&v73, Buffer, ElementSize, 1u, UNUSED_ARG(), UNUSED_ARG());
  CFile::Close(&v73, UNUSED_ARG(), UNUSED_ARG());
  CClassNetGameIniBuffer::CClassNetGameIniBuffer(&v22, (const char *)Buffer, ElementSize);
  pStrFind = 0;
  v65 = 0;
  pStrFind = (char *)strstr((char *)Buffer, "GameID=");
  if ( !pStrFind )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <GameID>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1289, aErrorI1Reading) == 1 )
      __debugbreak();
  }
  iGameId = j__strtol(pStrFind + 7, &EndPtr, 10);
  pStrFind = (char *)strstr((char *)Buffer, "GameName=");
  if ( !pStrFind )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <GameName>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1299, aErrorI2Reading) == 1 )
      __debugbreak();
  }
  pStrFind += 9;
  v65 = (_BYTE *)strstr(pStrFind, "\n");
  if ( !v65 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <GameName>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1306, aErrorI3Reading) == 1 )
      __debugbreak();
  }
  i = j__mbstowcs(swpGameName, pStrFind, v65 - pStrFind);
  swpGameName[i] = 0;
  memcpy(v85, pStrFind, v65 - pStrFind);
  v43 = i;
  if ( (unsigned int)i >= 0x100 )
    report_rangecheckfailure();
  v85[v43] = 0;
  std::wstring::wstring(&swGameName, swpGameName);
  LOBYTE(exceptionBlock) = 4;
  pStrFind = (char *)strstr((char *)Buffer, "SaveGame=");
  if ( !pStrFind )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <SaveGame>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1326, aErrorI2Reading_0) == 1 )
      __debugbreak();
  }
  iSaveGame = j__strtol(pStrFind + 9, &EndPtr, 10);
  v44 = iSaveGame == 1;
  v58 = iSaveGame == 1;
  if ( iSaveGame >= 2 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed! invalid SaveGameTag %d", iSaveGame);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1333, aErrorI9bReadin) == 1 )
      __debugbreak();
  }
  g_pGameType->m_bIsSaveGame = v58;
  bIsLadderGame = 0;
  bIsClanGame = 0;
  pStrFind = (char *)strstr((char *)Buffer, "IsLadderGame=");
  if ( pStrFind )
  {
    iLadderGame = j__strtol(pStrFind + 13, &EndPtr, 10);
    v45 = iLadderGame == 1;
    bIsLadderGame = iLadderGame == 1;
  }
  pStrFind = (char *)strstr((char *)Buffer, "IsClanGame=");
  if ( pStrFind )
  {
    iClanGame = j__strtol(pStrFind + 11, &EndPtr, 10);
    v46 = iClanGame == 1;
    bIsClanGame = iClanGame == 1;
  }
  std::wstring::wstring(&swMapName);
  LOBYTE(exceptionBlock) = 5;
  pStrFind = (char *)strstr((char *)Buffer, "MapName=");
  if ( !pStrFind )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <MapName>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1377, aErrorI4Reading) == 1 )
      __debugbreak();
  }
  pStrFind += 8;
  v65 = (_BYTE *)strstr(pStrFind, "\n");
  if ( !v65 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <MapName>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1384, aErrorI5Reading) == 1 )
      __debugbreak();
  }
  *v65 = 0;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v70);
  LOBYTE(exceptionBlock) = 6;
  a2 = (std::wstring *)std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
                         (int)&v71,
                         pStrFind);
  std::wstring::operator=(&swMapName, a2);
  std::wstring::~wstring(&v71);
  *v65 = 10;
  if ( CGameType::IsSaveGame(g_pGameType) )
  {
    CGameType::ConvertMapNameToMPGameName(&swMPGameName, &swMapName);
    LOBYTE(exceptionBlock) = 7;
    std::wstring::operator+=(&swMPGameName, (wchar_t *)L".sav");
    CGameChunkGeneral::CGameChunkGeneral(&sGeneralInfo);
    v3 = std::wstring::c_str(&swMPGameName);
    if ( !CGameRun::LoadGeneralInfo(v3, &sGeneralInfo) )
    {
      v4 = std::wstring::c_str(&swMPGameName);
      CTrace::Print(
        "GameHost.cpp: Internet game ini file malformed after phase <MapName>, can't load %s!",
        (const char *)v4);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1415, aTheDesiredMapF) == 1 )
        __debugbreak();
    }
    SaveFilePath::BuildSaveFilePath(&swSaveFilePath, (int)&swMPGameName);
    LOBYTE(exceptionBlock) = 8;
    CGameRun::FillGameType(&swSaveFilePath, g_pGameType, &sGeneralInfo);
    LOBYTE(exceptionBlock) = 7;
    std::wstring::~wstring(&swSaveFilePath);
    LOBYTE(exceptionBlock) = 6;
    std::wstring::~wstring(&swMPGameName);
  }
  else
  {
    std::wstring::operator=(&g_pGameType->m_swMapName, &swMapName);
    v19.m_uU1C = bIsClanGame;
    v19.m_uU18 = bIsLadderGame;
    v19.m_uU14 = -1;
    v19.m_uU10 = -1;
    v19.m_uUC = 0;
    v19.m_uU8 = 1;
    v19.m_uU4 = 1;
    v18 = 0;
    v17 = 0;
    v28 = &v16;
    v27 = std::wstring::wstring(&v16, &g_pGameType->m_swMapName);
    MapData = CGameType::LoadMapData(
                g_pGameType,
                v16,
                v17,
                v18,
                v19.m_uU4,
                v19.m_uU8,
                v19.m_uUC,
                v19.m_uU10,
                v19.m_uU14,
                v19.m_uU18,
                v19.m_uU1C);
    v56 = MapData;
    if ( !MapData && BBSupportDbgReport(1, "Net\\GameHost.cpp", 1400, aTheDesiredMapF_0) == 1 )
      __debugbreak();
    std::wstring::operator=(&g_pGameType->m_swGameName, &swGameName);
  }
  LOBYTE(exceptionBlock) = 5;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v70);
  LOBYTE(exceptionBlock) = 4;
  std::wstring::~wstring(&swMapName);
  CGameType::SetLadderGame(g_pGameType, bIsLadderGame);
  CGameType::SetClanGame(g_pGameType, bIsClanGame);
  pStrFind = (char *)strstr(pStrFind, "ProductID=");
  if ( !pStrFind )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <ProductID>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1433, aErrorI6Reading) == 1 )
      __debugbreak();
  }
  iProductId = (unsigned __int8)j__strtol(pStrFind + 10, &EndPtr, 10);
  v5 = CStaticConfigVarInt::operator int((CStaticConfigVarInt *)&g_iProductID);
  if ( iProductId != v5 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase! Wrong Product ID %d!", iProductId);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1443, aErrorI7Reading) == 1 )
      __debugbreak();
  }
  pStrFind = (char *)strstr((char *)Buffer, "GameMode=");
  if ( !pStrFind )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <GameMode>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1452, aErrorI8bReadin) == 1 )
      __debugbreak();
  }
  g_pGameType->m_iMode = j__strtol(pStrFind + 9, &EndPtr, 10);
  if ( (int)g_pGameType->m_iMode <= 0 || (int)g_pGameType->m_iMode >= 6 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed! invalid game mode %d", g_pGameType->m_iMode);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1459, aErrorI9bReadin_0) == 1 )
      __debugbreak();
  }
  pStrFind = (char *)strstr((char *)Buffer, "Resources=");
  if ( !pStrFind )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <Resources>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1468, aErrorI8cReadin) == 1 )
      __debugbreak();
  }
  g_pGameType->m_iStartResources = j__strtol(pStrFind + 10, &EndPtr, 10) + 1;
  if ( g_pGameType->m_iStartResources < 1 || g_pGameType->m_iStartResources > 3 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed! invalid game mode %d", g_pGameType->m_iMode);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1475, aErrorI9cReadin) == 1 )
      __debugbreak();
  }
  pStrFind = (char *)strstr((char *)Buffer, "NumberOfTeams=");
  if ( !pStrFind )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <NumOfTeams>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1484, aErrorI8aReadin) == 1 )
      __debugbreak();
  }
  if ( g_pGameType->m_iMode != 2 )
    g_pGameType->m_uiNumberAlliances = j__strtol(pStrFind + 14, &EndPtr, 10);
  if ( g_pGameType->m_uiNumberAlliances < 2u || g_pGameType->m_uiNumberAlliances > 8u )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed! Too many Teams %d", g_pGameType->m_uiNumberAlliances);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1496, aErrorI9aReadin) == 1 )
      __debugbreak();
  }
  pStrFind = (char *)strstr((char *)Buffer, "NumberOfPlayers=");
  if ( !pStrFind )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <NumberOfPlayers>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1505, aErrorI8Reading) == 1 )
      __debugbreak();
  }
  iPlayerCount = j__strtol(pStrFind + 16, &EndPtr, 10);
  if ( !CGameType::IsSaveGame(g_pGameType) && (bIsClanGame || g_pGameType->m_bMapFlagU2 && g_pGameType->m_bMapFlagU1) )
    g_pGameType->m_iActualPlayerCount = iPlayerCount;
  else
    g_pGameType->m_iActualPlayerCount = g_pGameType->m_iMapMaxNumPlayers;
  if ( g_pGameType->m_iMode != 2 )
    g_pGameType->m_iMapMaxNumPlayers = g_pGameType->m_iActualPlayerCount;
  if ( g_pGameType->m_iActualPlayerCount < 2u || g_pGameType->m_iActualPlayerCount > 8u )
  {
    CTrace::Print(
      "GameHost.cpp: Internet game ini file malformed! Too many players %d",
      g_pGameType->m_iActualPlayerCount);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1534, aErrorI9Reading) == 1 )
      __debugbreak();
  }
  pStrFind = (char *)strstr((char *)Buffer, "IsTrojan=");
  if ( pStrFind )
  {
    v37 = j__strtol(pStrFind + 9, &EndPtr, 10);
    g_pGameType->m_uExtraFlags |= v37;
    g_uiExtrasAllowed = g_pGameType->m_uExtraFlags;
  }
  _vec_ctor(
    (char *)v80,
    0x1Cu,
    9u,
    (void (__thiscall *)(void *))std::wstring::wstring,
    (void (__thiscall *)(void *))std::wstring::~wstring);
  LOBYTE(exceptionBlock) = 9;
  memset(v81, 0, sizeof(v81));
  for ( i = 0; i < iPlayerCount; ++i )
  {
    sprintf((char *const)swpPlayerIp, "PlayerIP%d=", i);
    pStrFind = (char *)strstr((char *)Buffer, (char *)swpPlayerIp);
    if ( !pStrFind )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerIP%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1568, aErrorI10Readin) == 1 )
        __debugbreak();
    }
    v65 = (_BYTE *)strstr(pStrFind, "\n");
    if ( !v65 )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <PlayerIP%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1574, aErrorI11Readin) == 1 )
        __debugbreak();
    }
    *v65 = 0;
    v6 = strlen("PlayerIP%d=");
    v26 = &v19;
    v25 = std::string::string(&v20, &pStrFind[v6 - 1]);
    v31 = pGameHost->m_pSimpleNet->GetIPLong(pGameHost->m_pSimpleNet, v20);
    v47 = v31;
    v81[i] = v31;
    if ( !CGameType::IsSaveGame(g_pGameType) )
      g_pGameType->m_uiIPPlayer[i] = v47;
    *v65 = 10;
    sprintf((char *const)swpPlayerIp, "PlayerName%d=", i);
    pStrFind = (char *)strstr((char *)Buffer, (char *)swpPlayerIp);
    if ( !pStrFind )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerName%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1593, aErrorI12Readin) == 1 )
        __debugbreak();
    }
    v65 = (_BYTE *)strstr(pStrFind, "\n");
    if ( !v65 )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <PlayerName%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1599, aErrorI13Readin) == 1 )
        __debugbreak();
    }
    v20.m_uU1C = v65 - &pStrFind[strlen("PlayerName%d=") - 1];
    v7 = strlen("PlayerName%d=");
    v41 = j__mbstowcs(swpPlayerIp, &pStrFind[v7 - 1], v20.m_uU1C);
    swpPlayerIp[v41] = 0;
    std::wstring::wstring(&v76, swpPlayerIp);
    LOBYTE(exceptionBlock) = 10;
    std::wstring::operator=(&v80[i], &v76);
    sprintf((char *const)swpPlayerIp, "PlayerID%d=", i);
    pStrFind = (char *)strstr((char *)Buffer, (char *)swpPlayerIp);
    if ( !pStrFind )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerID%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1615, aErrorI20Readin) == 1 )
        __debugbreak();
    }
    v20.m_uU1C = 10;
    v20.m_uU18 = (int)&EndPtr;
    v8 = strlen("PlayerID%d=");
    v40 = j__strtol(&pStrFind[v8 - 1], &EndPtr, 10);
    g_pGameType->m_sPlayerPeerId[i] = v40;
    if ( g_pGameType->m_sPlayerTeam[i] >= g_pGameType->m_uiNumberAlliances )
      g_pGameType->m_sPlayerTeam[i] = (unsigned int)i % g_pGameType->m_uiNumberAlliances;
    if ( CGameType::IsClanGame(g_pGameType) )
    {
      sprintf((char *const)swpPlayerIp, "ClanShortcut%d=", i);
      pStrFind = (char *)strstr((char *)Buffer, (char *)swpPlayerIp);
      if ( !pStrFind )
      {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerIP%d>!", i);
        if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1633, aErrorI10Readin_0) == 1 )
          __debugbreak();
      }
      v65 = (_BYTE *)strstr(pStrFind, "\n");
      if ( !v65 )
      {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <PlayerIP%d>!", i);
        if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1639, aErrorI11Readin_0) == 1 )
          __debugbreak();
      }
      v20.m_uU1C = v65 - &pStrFind[strlen("ClanShortcut%d=") - 1];
      v9 = strlen("ClanShortcut%d=");
      v39 = j__mbstowcs(swpPlayerIp, &pStrFind[v9 - 1], v20.m_uU1C);
      swpPlayerIp[v39] = 0;
      std::wstring::wstring(&v74, swpPlayerIp);
      LOBYTE(exceptionBlock) = 11;
      CGameType::SetPlayerClanShortcut(g_pGameType, i, &v74);
      LOBYTE(exceptionBlock) = 10;
      std::wstring::~wstring(&v74);
    }
    LOBYTE(exceptionBlock) = 9;
    std::wstring::~wstring(&v76);
  }
  IntValue = CClassNetGameIniBuffer::GetIntValue((char *)&v22, "LocalPlayerSlot=", -1);
  if ( IntValue >= 8 )
    IntValue = -1;
  if ( IntValue < 0 )
  {
    for ( i = 0; i < iPlayerCount; ++i )
    {
      if ( pGameHost->m_pSimpleNet->IsLocalIP(pGameHost->m_pSimpleNet, v81[i]) )
      {
        IntValue = i;
        break;
      }
    }
  }
  else
  {
    pGameHost->m_pSimpleNet->SetAdditionalLocalAddress(pGameHost->m_pSimpleNet, v81[IntValue]);
  }
  if ( IntValue >= 0 && std::wstring::length(&v80[IntValue]) )
  {
    v24 = &v20;
    v23 = std::wstring::wstring((std::wstring *)&v20, &v80[IntValue]);
    CGameSettings::SetPlayerName((std::wstring)v20);
  }
  g_pGameType->m_iHostAddress = v81[0];
  if ( !IntValue )
  {
    CGameType::SetHost(g_pGameType, 1);
    if ( CGameType::IsSaveGame(g_pGameType) )
    {
      LocalSlot = CGameType::GetLocalSlot(g_pGameType);
      g_pGameType->m_uiIPPlayer[LocalSlot] = v81[0];
    }
  }
  if ( g_pGameType->m_iMode == 2 )
    g_pGameType->m_iActualPlayerCount = g_pGameType->m_iMapMaxNumPlayers;
  pStrFind = (char *)strstr((char *)Buffer, "SessionID=");
  if ( !pStrFind )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <SessionID>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1705, aErrorI14Readin) == 1 )
      __debugbreak();
  }
  v65 = (_BYTE *)strstr(pStrFind, "\n");
  if ( !v65 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <SessionID>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1711, aErrorI15Readin) == 1 )
      __debugbreak();
  }
  *v65 = 0;
  std::string::operator=(&g_pGameType->m_sSessionId, pStrFind + 10);
  *v65 = 10;
  pStrFind = (char *)strstr((char *)Buffer, "ProcedureServer=");
  if ( !pStrFind )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <ProcedureServer>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1723, aErrorI16Readin) == 1 )
      __debugbreak();
  }
  v65 = (_BYTE *)strstr(pStrFind, "\n");
  if ( !v65 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <ProcedureServer>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1729, aErrorI17Readin) == 1 )
      __debugbreak();
  }
  *v65 = 0;
  std::string::operator=(&g_pGameType->m_sProcedureServer, pStrFind + 16);
  *v65 = 10;
  pStrFind = (char *)strstr((char *)Buffer, "ProcedureServerPort=");
  if ( !pStrFind )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <g_szProcServerPort>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1739, aErrorI18Readin) == 1 )
      __debugbreak();
  }
  v65 = (_BYTE *)strstr(pStrFind, "\n");
  if ( !v65 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <g_szProcServerPort>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1745, aErrorI19Readin) == 1 )
      __debugbreak();
  }
  *v65 = 0;
  g_pGameType->m_iProcedureServerPort = j__strtol(pStrFind + 20, &EndPtr, 10);
  *v65 = 10;
  v11 = pGameHost->m_pSimpleNet->GetIPString(pGameHost->m_pSimpleNet, g_pGameType->m_iHostAddress);
  CTrace::Print("GameHost.cpp: Host is %s", v11);
  g_pGameType->m_iHumanPlayers = 0;
  if ( CGameType::IsClanGame(g_pGameType) )
    g_pGameType->m_bMapFlagU1 = 0;
  m_iActualPlayerCount = g_pGameType->m_iActualPlayerCount;
  for ( j = 0; j < m_iActualPlayerCount; ++j )
  {
    sprintf((char *const)swpPlayerIp, "PlayerTeam%d=", j);
    pStrFind = (char *)strstr((char *)Buffer, (char *)swpPlayerIp);
    if ( pStrFind )
    {
      v21 = 10;
      v20.m_uU1C = (int)&EndPtr;
      v12 = strlen((const char *)swpPlayerIp);
      v48 = j__strtol(&pStrFind[v12], &EndPtr, 10);
      if ( v48 >= 0 )
        g_pGameType->m_sPlayerTeam[j] = v48;
    }
  }
  for ( i = 0; (unsigned int)i < g_pGameType->m_iActualPlayerCount; ++i )
  {
    if ( g_pGameType->m_bDarkTribe[i] )
      g_pGameType->m_sPlayerRaces[i] = 0;
    if ( !g_pGameType->m_sPlayerType[i] )
      ++g_pGameType->m_iHumanPlayers;
  }
  g_pGameType->m_iGameType = 2;
  CGameType::SetWebGame(g_pGameType, 1);
  if ( pGameHost->m_pSimpleNet->IsLocalIP(pGameHost->m_pSimpleNet, g_pGameType->m_iHostAddress) )
  {
    pGameHost->m_bClient = 0;
    pGameHost->m_bHost = 1;
    CFsm::Control(pGameHost->m_pFSM, 1007, 0);
    CFsm::Control(pGameHost->m_pFSM, 1051, 0);
  }
  else
  {
    Sleep(0x7D0u);
    memset(&sGameInfo, 0, sizeof(sGameInfo));
    sGameInfo.m_bMapAvailable = 1;
    sGameInfo.m_bU2 = 0;
    sGameInfo.m_iMapCRC = g_pGameType->m_iMapCRC;
    sGameInfo.m_iPlayerCount = g_pGameType->m_iActualPlayerCount;
    v20.m_uU1C = 512;
    v13 = std::wstring::c_str(&g_pGameType->m_swMapName);
    MyWStrNCopy(sGameInfo.m_swpMapName, v13, v20.m_uU1C);
    sGameInfo.m_iMaxPlayerCount = g_pGameType->m_iActualPlayerCount;
    sGameInfo.m_iFileSize = g_pGameType->m_iFileSize;
    sGameInfo.m_iStartTime = timeGetTime();
    v20.m_uU1C = 64;
    v14 = std::wstring::c_str(&g_pGameType->m_swGameName);
    MyWStrNCopy(sGameInfo.m_swpGameName, v14, v20.m_uU1C);
    sGameInfo.m_iHostAddress = g_pGameType->m_iHostAddress;
    sGameInfo.m_iIsSaveGame = CGameType::IsSaveGame(g_pGameType);
    sGameInfo.m_bIsAutosave = g_pGameType->bIsAutosave;
    sGameInfo.m_uTickCounter = g_pGameType->m_uiTickCounter;
    sGameInfo.m_iGameId = CGameType::GetMultiPlayerGameID(g_pGameType);
    sGameInfo.m_iSavegameId = CGameType::GetMPSavegameID(g_pGameType);
    CGameHost::AddGame(pGameHost, &sGameInfo);
    pGameHost->m_bClient = 1;
    pGameHost->m_bHost = 0;
    CFsm::Control(pGameHost->m_pFSM, 1008, 0);
    CFsm::Control(pGameHost->m_pFSM, 1024, 0);
  }
  v49 = CStateLobbyGameSettings::CompileUserFlags();
  if ( v49 && BBSupportDbgReportF(2, "Net\\GameHost.cpp", 1862, "CompileUserFlags() reported error %d!", v49) == 1 )
    __debugbreak();
  if ( BBSupportDbgReport(2, "Net\\GameHost.cpp", 1864, "false") == 1 )// Breakpoints not working bud?
    __debugbreak();
  v55 = 1;
  LOBYTE(exceptionBlock) = 4;
  `eh vector destructor iterator'(v80, 0x1Cu, 9u, (void (__thiscall *)(void *))std::wstring::~wstring);
  LOBYTE(exceptionBlock) = 0;
  std::wstring::~wstring(&swGameName);
  exceptionBlock = -1;
  CFile::~CFile(&v73);
  return v55;
}


// address=[0x15b88c0]
// Decompiled from void __thiscall CGameHost::PingClients(CGameHost *this)
void  CGameHost::PingClients(void) {
  
  DWORD v1; // esi
  int Size; // eax
  CGameHost::SSimpleMessage sPingMessage; // [esp+4h] [ebp-1Ch] BYREF
  uint PlayerPeerId; // [esp+Ch] [ebp-14h]
  uint PlayerIP; // [esp+10h] [ebp-10h]
  DWORD Time; // [esp+14h] [ebp-Ch]
  signed int i; // [esp+18h] [ebp-8h]

  if ( !this->m_iLastPingTime || (v1 = this->m_iLastPingTime + 1000, v1 < timeGetTime()) )
  {
    Time = timeGetTime();
    sPingMessage.m_iId = 3;
    sPingMessage.m_iTick = Time;
    for ( i = 0; ; ++i )
    {
      Size = CClientList::GetSize(this->m_pClientList);
      if ( i >= Size )
        break;
      PlayerIP = CClientList::GetPlayerIP(this->m_pClientList, i);
      PlayerPeerId = CClientList::GetPlayerPeerId(this->m_pClientList, i);
      this->m_pSimpleNet->PushMessage(this->m_pSimpleNet, PlayerPeerId, PlayerIP, 3105, &sPingMessage, 6, 0, 1);
    }
    this->m_iLastPingTime = timeGetTime();
  }
}


// address=[0x15b8990]
// Decompiled from void __thiscall CGameHost::DeliverSimpleMessage(CGameHost *this)
void  CGameHost::DeliverSimpleMessage(void) {
  
  char *v1; // eax
  OnlineManager *Instance; // eax
  int v3; // eax
  int LocalPeerId; // esi
  uint iLastIP; // eax
  int _iLastPeerId; // eax
  DWORD Time; // eax
  OnlineManager *v8; // eax
  storm::SimpleSessionHandler **v9; // eax
  int HostPeerId; // eax
  u_short v11; // [esp+0h] [ebp-68h]
  void *v12; // [esp+4h] [ebp-64h]
  uint iMessageSize; // [esp+8h] [ebp-60h] BYREF
  std::string *v15; // [esp+10h] [ebp-58h]
  std::string *v16; // [esp+14h] [ebp-54h]
  int v18; // [esp+1Ch] [ebp-4Ch]
  int iReadMessages; // [esp+20h] [ebp-48h]
  int index; // [esp+24h] [ebp-44h]
  CGameHost::SSimpleMessage *pMessage; // [esp+28h] [ebp-40h] MAPDST BYREF
  uint iPeerId; // [esp+2Ch] [ebp-3Ch] BYREF
  unsigned int i; // [esp+30h] [ebp-38h]
  ushort iId; // [esp+38h] [ebp-30h]
  _BYTE v26[28]; // [esp+3Ch] [ebp-2Ch] BYREF
  int v27; // [esp+64h] [ebp-4h]

  iReadMessages = 0;
  while ( this->m_pSimpleNet->IsMessage(this->m_pSimpleNet, -1) )
  {
    ++iReadMessages;
    if ( !this->m_pSimpleNet->PopMessage(this->m_pSimpleNet, (void **)&pMessage, &iMessageSize, &iPeerId) )
    {
      v16 = this->m_pSimpleNet->GetLastErrorString(this->m_pSimpleNet, v26);
      v15 = v16;
      v27 = 0;
      v1 = std::string::c_str(v16);
      CTrace::Print("Gamehost.cpp: PopMessage() failed with error %s!", v1);
      v27 = -1;
      std::string::~string(v26);
      return;
    }
    if ( pMessage )
    {
      Instance = (OnlineManager *)OnlineManager::GetInstance();
      if ( OnlineManager::IsInSession(Instance)
        && (v3 = StormManager::GetInstance(),
            LocalPeerId = StormManager::GetLocalPeerId(v3),
            LocalPeerId == this->m_pSimpleNet->GetLastSenderPeerId(this->m_pSimpleNet)) )
      {
        CTrace::Print("CGameHost.cpp: Msg from localhost ignored!");
      }
      else
      {
        iId = pMessage->m_iId;
        v18 = iId;
        if ( iId == 3 )
        {
          if ( CClientList::ContainsPeerId(this->m_pClientList, iPeerId) )
          {
            pMessage->m_iId = 4;
            iLastIP = this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet);
            this->m_pSimpleNet->PushMessage(
              this->m_pSimpleNet,
              iPeerId,
              iLastIP,
              v11,                              // 0xC21
              v12,                              // pMessage
              iMessageSize,                     // 6
              (char)pMessage,                   // 0
              (char)v15);                       // 1
            if ( CFsm::CurrentState(this->m_pFSM) == 5 )
              this->m_iLastPingTime = timeGetTime();
          }
        }
        else if ( v18 == 4 )
        {
          for ( i = 0; i < g_pGameType->m_iActualPlayerCount; ++i )
          {
            _iLastPeerId = this->m_pSimpleNet->GetLastSenderPeerId(this->m_pSimpleNet);
            if ( g_pGameType->m_sPlayerPeerId[i] == _iLastPeerId )
            {
              g_pGameType->m_sPlayerAckDelta[i] = timeGetTime() - pMessage->m_iTick;
              CLanLobby::RedrawPlayerList();
              index = CClientList::GetClientIndexPerPeerId(this->m_pClientList, iPeerId);
              if ( index < 0 )
                j___wassert(L"index >= 0", L"Net\\GameHost.cpp", 0x440u);
              Time = timeGetTime();
              CClientList::SetClientLastAck(this->m_pClientList, index, Time);
            }
          }
        }
        else if ( iId >= 1000u && iId < 1061u )
        {
          if ( iId == 1000
            || iId == 1001
            || iId == 1013
            || iId == 1022
            || iId == 1023
            || iId == 1038
            || iId == 1032
            || iId == 3
            || CClientList::ContainsPeerId(this->m_pClientList, iPeerId)
            || (v8 = (OnlineManager *)OnlineManager::GetInstance(), OnlineManager::IsInSession(v8))
            && (v9 = (storm::SimpleSessionHandler **)StormManager::GetInstance(),
                HostPeerId = StormManager::GetHostPeerId(v9),
                iPeerId == HostPeerId) )
          {
            if ( iId != 1000 || !this->m_bClient && CFsm::CurrentState(this->m_pFSM) != 17 )
              CFsm::Control(this->m_pFSM, iId, &pMessage->m_iTick);
          }
        }
      }
    }
  }
}


// address=[0x15b8d70]
// Decompiled from std::string *__thiscall CGameHost::ConvertIPAddress(CGameHost *this, std::string *_rIp, ULONG _iAddress)
std::string  CGameHost::ConvertIPAddress(unsigned int _rIp) {
  
  char *v3; // eax

  if ( this->m_pSimpleNet )
  {
    v3 = (char *)this->m_pSimpleNet->GetIPString(this->m_pSimpleNet, _iAddress);
    std::string::string(_rIp, v3);
  }
  else
  {
    std::string::string(_rIp, "Unknown");
  }
  return _rIp;
}


// address=[0x15b8de0]
// Decompiled from char __thiscall CGameHost::RemovePlayerPeerId(CGameHost *this, unsigned int a2)
bool  CGameHost::RemovePlayerPeerId(unsigned int a2) {
  
  int Instance; // eax
  int ValidTick; // eax
  struct CEvn_Event *v5; // [esp+4h] [ebp-40h]
  DWORD v6; // [esp+Ch] [ebp-38h]
  char v8; // [esp+17h] [ebp-2Dh]
  unsigned int i; // [esp+18h] [ebp-2Ch]
  int j; // [esp+18h] [ebp-2Ch]
  CEvn_Event v11; // [esp+1Ch] [ebp-28h] BYREF
  int v12; // [esp+40h] [ebp-4h]

  v8 = 0;
  Instance = StormManager::GetInstance();
  if ( StormManager::GetLocalPeerId(Instance) == a2 )
    return 0;
  for ( i = 0; i < g_pGameType->m_iActualPlayerCount; ++i )
  {
    if ( g_pGameType->m_sPlayerPeerId[i] == a2 )
    {
      v8 = 1;
      break;
    }
  }
  if ( !v8 )
    return 0;
  CMsgStacks::ClearAndValidate(this->m_pMsgStacks, i);
  CMsgStacks::SetStackAI(i, 1);
  if ( CGameSettings::GetAIDifficulty() )
    v6 = 3;
  else
    v6 = 2;
  g_pGameType->m_sPlayerType[i] = v6;
  g_pGameType->m_sPlayerValidTicks[i] = CGameHost::GetValidTick(this);
  ValidTick = CGameHost::GetValidTick(this);
  CTrace::Print("GameHost.cpp: Message stack index#%d set to AI in Tick %d!", i, ValidTick);
  if ( !CClientList::RemoveClientPeerId(this->m_pClientList, g_pGameType->m_sPlayerPeerId[i]) )
    CTrace::Print("GameHost.cpp: Player index#%d could not be removed from client list!", i);
  for ( j = 1; j <= CPlayerManager::LastPlayerId() && CPlayerManager::PeerId(j) != a2; ++j )
    ;
  if ( j > CPlayerManager::LastPlayerId()
    && BBSupportDbgReportF(2, "Net\\GameHost.cpp", 3577, "Player could not be set to AI!") == 1 )
  {
    __debugbreak();
  }
  CTrace::Print("GameHost.cpp: Dropping player index#%d", j - 1);
  v5 = CEvn_Event::CEvn_Event(&v11, 57u, j, 0, 0);
  v12 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v5);
  v12 = -1;
  CEvn_Event::~CEvn_Event(&v11);
  return 1;
}


// address=[0x15b9000]
// Decompiled from unsigned __int8 __thiscall CGameHost::IsLocalIP(CGameHost *this, int a2)
bool  CGameHost::IsLocalIP(unsigned int a2) {
  
  if ( this->m_pSimpleNet )
    return this->m_pSimpleNet->IsLocalIP(this->m_pSimpleNet, a2);
  else
    return 1;
}


// address=[0x15b9040]
// Decompiled from char __thiscall CGameHost::OnEndGame(CGameHost *this, int a2)
bool  CGameHost::OnEndGame(int a2) {
  
  return 1;
}


// address=[0x15b9050]
// Decompiled from void __thiscall CGameHost::OnEndSaving(CGameHost *this, int a2)
void  CGameHost::OnEndSaving(int a2) {
  
  CMsgStacks::OnEndSaving(this->m_pMsgStacks, g_pGameType->m_iActualPlayerCount, a2);
}


// address=[0x15b9080]
// Decompiled from void __thiscall CGameHost::StormJoinSessionSucceeded(CGameHost *this)
void  CGameHost::StormJoinSessionSucceeded(void) {
  
  storm::SimpleSessionHandler **Instance; // eax
  wchar_t *v2; // eax
  void *v3; // eax
  char *v4; // [esp-8h] [ebp-74h]
  void *v5; // [esp+4h] [ebp-68h]
  std::wstring *PlayerName; // [esp+Ch] [ebp-60h]
  int HostPeerId; // [esp+1Ch] [ebp-50h]
  int LocalSlot; // [esp+20h] [ebp-4Ch]
  std::wstring v10; // [esp+24h] [ebp-48h] BYREF
  _BYTE v11[28]; // [esp+40h] [ebp-2Ch] BYREF
  int v12; // [esp+68h] [ebp-4h]

  OutputDebugStringA("JoinSessionSucceeded\n");
  Instance = (storm::SimpleSessionHandler **)StormManager::GetInstance();
  HostPeerId = StormManager::GetHostPeerId(Instance);
  CClientList::Add(this->m_pClientList, 0, 0, HostPeerId);
  if ( g_pGameType->m_bIsSaveGame )
    LocalSlot = CGameType::GetLocalSlot(g_pGameType);
  else
    LocalSlot = -1;
  PlayerName = (std::wstring *)CGameSettings::GetPlayerName((int)&v10);
  v12 = 0;
  v2 = std::wstring::c_str(PlayerName);
  v5 = storm::CStringConvertToUtf8(v11, (int)v2);
  LOBYTE(v12) = 1;
  v4 = (char *)std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str(v5);
  v3 = (void *)OnlineManager::GetInstance();
  OnlineManager::SendUnicastPlayerMessage(v3, HostPeerId, v4, (const struct storm::StormPlayerMessage *)LocalSlot);
  LOBYTE(v12) = 0;
  std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::~basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>(v11);
  v12 = -1;
  std::wstring::~wstring(&v10);
  CFsm::GenerateEvent(this->m_pFSM, 1057, 0);
}


// address=[0x15b91b0]
// Decompiled from int __stdcall CGameHost::StormHost_NewPlayerMessage(CGameHost *a1, std::wstring *a2, int a3)
void  CGameHost::StormHost_NewPlayerMessage(unsigned int a1, std::wstring & a2, int a3) {
  
  wchar_t *v3; // eax
  wchar_t Destination[32]; // [esp+4h] [ebp-6Ch] BYREF
  CGameHost *v6; // [esp+45h] [ebp-2Bh]
  char m_bIsSaveGame; // [esp+62h] [ebp-Eh]
  char v8; // [esp+68h] [ebp-8h]

  v6 = a1;
  v3 = std::wstring::c_str(a2);
  wcscpy(Destination, v3);
  m_bIsSaveGame = g_pGameType->m_bIsSaveGame;
  v8 = a3;
  return CGameHost::ClientJoins(Destination);
}


// address=[0x15b9210]
// Decompiled from int __thiscall CGameHost::StormClientLeavesMyGame(CGameHost *this, unsigned int a2)
void  CGameHost::StormClientLeavesMyGame(unsigned int a2) {
  
  storm::SimpleSessionHandler **Instance; // eax

  Instance = (storm::SimpleSessionHandler **)StormManager::GetInstance();
  if ( a2 == StormManager::GetHostPeerId(Instance) )
    CTrace::Print("GameHost.cpp: Host has left session!");
  CLanLobby::DisconnectPlayerPeerId(a2, -1);
  if ( !CClientList::RemoveClientPeerId(this->m_pClientList, a2) )
    CTrace::Print("GameHost.cpp: Unable to removed client!");
  return CLanLobby::RedrawPlayerList();
}


// address=[0x15b9280]
// Decompiled from int __thiscall CGameHost::PromoteToHost(CGameHost *this)
void  CGameHost::PromoteToHost(void) {
  
  struct CGameState *CurrentState; // eax
  CStateLobbyGameSettings *pLobbyState; // [esp+0h] [ebp-8h]

  this->m_bHost = 1;
  this->m_bClient = 0;
  g_bIsHost = 1;
  CurrentState = CGameStateHandler::GetCurrentState();
  pLobbyState = (CStateLobbyGameSettings *)j____RTDynamicCast(
                                             (void **)&CurrentState->__vftable,
                                             0,
                                             &CGameState__RTTI_Type_Descriptor_,
                                             &CStateLobbyGameSettings__RTTI_Type_Descriptor_,
                                             0);
  if ( !pLobbyState )
    return CTrace::Print("GameHost.cpp: We are new Host!!!");
  CStateLobbyGameSettings::TransitionToHost(pLobbyState);
  CFsm::Control(this->m_pFSM, 1058, 0);
  GuiDlgMainGameSettingstUpdate();
  return CTrace::Print("GameHost.cpp: We are new Host!!!");
}


// address=[0x15b9300]
// Decompiled from void __thiscall CGameHost::OnQuickMatched(CGameHost *this, bool a2)
void  CGameHost::OnQuickMatched(bool a2) {
  
  if ( a2 )
    CGameHost::OnQuickMatchedHosted(this);
  else
    CGameHost::OnJoinedFromOnlineFlow(this);
}


// address=[0x15b9330]
// Decompiled from void __thiscall CGameHost::OnQuickMatchedHosted(CGameHost *this)
void  CGameHost::OnQuickMatchedHosted(void) {
  
  wchar_t *v1; // eax
  wchar_t *v2; // eax
  std::wstring *v3; // [esp+0h] [ebp-B4h]
  std::wstring *PlayerName; // [esp+4h] [ebp-B0h]
  unsigned int i; // [esp+Ch] [ebp-A8h]
  std::wstring v7; // [esp+10h] [ebp-A4h] BYREF
  std::wstring v8; // [esp+2Ch] [ebp-88h] BYREF
  wchar_t Destination[31]; // [esp+48h] [ebp-6Ch] BYREF
  __int16 v10; // [esp+86h] [ebp-2Eh]
  int v11; // [esp+89h] [ebp-2Bh]
  char v12; // [esp+ACh] [ebp-8h]

  v12 = -1;
  if ( !CGameType::IsSaveGame(g_pGameType) || !CGameType::IsMultiplayerGame(g_pGameType) )
  {
    PlayerName = (std::wstring *)CGameSettings::GetPlayerName((int)&v8);
    v1 = std::wstring::c_str(PlayerName);
    wcsncpy(Destination, v1, 0x1Fu);
    std::wstring::~wstring(&v8);
    v10 = 0;
    v11 = 0;
    g_pGameType->m_sPlayerType[0] = 1;
    CLanLobby::ConnectPlayer(Destination, -1);
  }
  for ( i = 1; i < g_pGameType->m_iActualPlayerCount; ++i )
  {
    if ( g_pGameType->m_sPlayerType[i] == 2
      || g_pGameType->m_sPlayerType[i] == 3
      || g_pGameType->m_bPlayerSlotEmpty[i] && !this->m_bIsOnlineGame )
    {
      v11 = -1;
      v3 = CGameType::GetPlayerName(g_pGameType, &v7, i);
      v2 = std::wstring::c_str(v3);
      wcsncpy(Destination, v2, 0x1Fu);
      std::wstring::~wstring(&v7);
      v10 = 0;
      CLanLobby::ConnectPlayer(Destination, i);
    }
  }
  CFsm::GenerateEvent(this->m_pFSM, 1009, 0);
}


// address=[0x15b9500]
// Decompiled from int __thiscall CGameHost::OnJoinedFromOnlineFlow(CGameHost *this)
void  CGameHost::OnJoinedFromOnlineFlow(void) {
  
  StormManager *Instance; // eax
  wchar_t *v2; // eax
  wchar_t *v3; // eax
  void *v4; // eax
  wchar_t *v5; // eax
  wchar_t *v6; // eax
  std::wstring v8; // [esp-40h] [ebp-F4h] BYREF
  BOOL v9; // [esp-24h] [ebp-D8h]
  int v10; // [esp-20h] [ebp-D4h]
  int v11; // [esp-1Ch] [ebp-D0h] OVERLAPPED BYREF
  int v12; // [esp-18h] [ebp-CCh]
  int v13; // [esp-14h] [ebp-C8h]
  DWORD v14; // [esp-10h] [ebp-C4h]
  int v15; // [esp-Ch] [ebp-C0h]
  BOOL v16; // [esp-8h] [ebp-BCh]
  _DWORD *v17; // [esp-4h] [ebp-B8h]
  int v18; // [esp+4h] [ebp-B0h]
  std::wstring *v19; // [esp+8h] [ebp-ACh]
  void *v20; // [esp+Ch] [ebp-A8h]
  int *v21; // [esp+10h] [ebp-A4h]
  void *v23; // [esp+18h] [ebp-9Ch]
  void *v24; // [esp+1Ch] [ebp-98h]
  CGameType *v25; // [esp+20h] [ebp-94h]
  void *v26; // [esp+24h] [ebp-90h]
  CGameType *v27; // [esp+28h] [ebp-8Ch]
  INetworkEngine *v28; // [esp+2Ch] [ebp-88h]
  BOOL v29; // [esp+30h] [ebp-84h]
  CGameType *v30; // [esp+34h] [ebp-80h]
  void *v31; // [esp+38h] [ebp-7Ch]
  CGameType *v32; // [esp+3Ch] [ebp-78h]
  INetworkEngine *v33; // [esp+40h] [ebp-74h]
  void *C; // [esp+44h] [ebp-70h]
  CDaoIndexFieldInfo *CurrentSession; // [esp+48h] [ebp-6Ch]
  char v37[28]; // [esp+50h] [ebp-64h] BYREF
  _BYTE v38[28]; // [esp+6Ch] [ebp-48h] BYREF
  _BYTE v39[28]; // [esp+88h] [ebp-2Ch] BYREF
  int v40; // [esp+B0h] [ebp-4h]

  Instance = (StormManager *)StormManager::GetInstance();
  CurrentSession = StormManager::GetCurrentSession(Instance);
  v21 = &v11;
  v20 = std::wstring::wstring((std::wstring *)&v11, &g_swPlayerName);
  CGameSettings::SetPlayerName(*(std::wstring *)&v11);
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>();
  v40 = 0;
  GameSessionDescriptor::GetMapName((int)v38);
  if ( !g_pNetworkEngine )
  {
    C = operator new(0x18u);
    LOBYTE(v40) = 1;
    if ( C )
      v33 = INetworkEngine::INetworkEngine((INetworkEngine *)C, 1);
    else
      v33 = 0;
    v28 = v33;
    LOBYTE(v40) = 0;
    g_pNetworkEngine = v33;
    INetworkEngine::Start(0, 0, 0, 0);
  }
  v17 = 0;
  v16 = 0;
  v15 = -1;
  v14 = -1;
  v13 = 0;
  v12 = 1;
  v11 = 1;
  v10 = 0;
  v9 = 0;
  v2 = (wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(v38);
  v19 = &v8;
  v18 = std::wstring::wstring(&v8, v2);
  if ( !CGameType::LoadMapData(g_pGameType, v8, v9, v10, v11, v12, v13, v14, v15, v16, (bool)v17) )
  {
    v27 = g_pGameType;
    v32 = g_pGameType;
    if ( g_pGameType )
      v26 = delete v32;
    else
      v26 = 0;
    v31 = operator new(0x620u);
    LOBYTE(v40) = 2;
    if ( v31 )
      v30 = CGameType::CGameType((CGameType *)v31);
    else
      v30 = 0;
    v25 = v30;
    LOBYTE(v40) = 0;
    g_pGameType = v30;
    v3 = (wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(v38);
    std::wstring::operator=(&g_pGameType->m_swMapName, v3);
    g_pGameType->m_bAIActive = 0;
  }
  storm::echo::SessionDescriptor::GetSessionName(CurrentSession);
  v17 = std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str(v4);
  v24 = (void *)storm::CStringConvertToUtf16(v37);
  v23 = v24;
  LOBYTE(v40) = 3;
  v5 = (wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(v24);
  std::wstring::operator=(&g_pGameType->m_swGameName, v5);
  LOBYTE(v40) = 0;
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>();
  g_pGameType->m_iGameType = 2;
  g_pGameType->m_iCampaignType = 0;
  g_pGameType->m_iActualPlayerCount = GameSessionDescriptor::GetPeerCount(CurrentSession);
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>();
  LOBYTE(v40) = 4;
  GameSessionDescriptor::GetSaveFile(v39);
  v29 = std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::length(v39) != 0;
  g_pGameType->m_bIsSaveGame = v29;
  g_pGameType->bIsAutosave = 0;
  if ( g_pGameType->m_bIsSaveGame )
  {
    v6 = (wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(v39);
    std::wstring::operator=(&g_pGameType->m_swSaveFile, v6);
    if ( g_pGameType->bIsAutosave )
      std::wstring::operator+=(&g_pGameType->m_swSaveFile, (wchar_t *)L"_autoSave");
    std::wstring::operator+=(&g_pGameType->m_swSaveFile, (wchar_t *)L".sav");
  }
  CLanLobby::Communicate(1024, (void *)g_iLanLobbyNr);
  LOBYTE(v40) = 0;
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>();
  v40 = -1;
  return std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>();
}


// address=[0x15b9860]
// Decompiled from void __thiscall CGameHost::FillHandlersArray(CGameHost *this)
void  CGameHost::FillHandlersArray(void) {
  
  *((_DWORD *)this->m_pHandlers + 34) = CGameHost::StartState;
  *((_DWORD *)this->m_pHandlers + 1) = CGameHost::InitHostNetwork;
  *((_DWORD *)this->m_pHandlers + 2) = CGameHost::InitClientNetwork;
  *((_DWORD *)this->m_pHandlers + 3) = CGameHost::OnHostWait;
  *((_DWORD *)this->m_pHandlers + 4) = CGameHost::SearchHost;
  *((_DWORD *)this->m_pHandlers + 16) = CGameHost::WaitingForGameConnect;
  *((_DWORD *)this->m_pHandlers + 18) = CGameHost::HostInitGame;
  *((_DWORD *)this->m_pHandlers + 19) = CGameHost::HostStartTick;
  *((_DWORD *)this->m_pHandlers + 23) = CGameHost::RegClientConnect;
  *((_DWORD *)this->m_pHandlers + 24) = CGameHost::WereConnectedForGame;
  *((_DWORD *)this->m_pHandlers + 26) = CGameHost::ClientStartingGame;
  *((_DWORD *)this->m_pHandlers + 28) = CGameHost::ClientGameInited;
  *((_DWORD *)this->m_pHandlers + 29) = CGameHost::ClientStartTick;
  *((_DWORD *)this->m_pHandlers + 31) = CGameHost::HostGameInited;
  *((_DWORD *)this->m_pHandlers + 32) = CGameHost::GameSyncMsgGot;
  *((_DWORD *)this->m_pHandlers + 33) = CGameHost::GameInGameMsgGot;
  *this->m_pHandlers = (char (__thiscall *)(IEventHandler *, void *))CGameHost::ErrorState;
  *((_DWORD *)this->m_pHandlers + 36) = CGameHost::DoNothing;
  *((_DWORD *)this->m_pHandlers + 35) = CGameHost::ClientSearchesGameHost;
  *((_DWORD *)this->m_pHandlers + 38) = CGameHost::ClientReceivesGameInfo;
  *((_DWORD *)this->m_pHandlers + 40) = CGameHost::ClientLoginHost;
  *((_DWORD *)this->m_pHandlers + 39) = CGameHost::ClientJoins;
  *((_DWORD *)this->m_pHandlers + 42) = CGameHost::ClientReceivePlayerData;
  *((_DWORD *)this->m_pHandlers + 43) = CGameHost::ClientReceivePlayerPing;
  *((_DWORD *)this->m_pHandlers + 41) = CGameHost::ClientLobbyPrepare;
  *((_DWORD *)this->m_pHandlers + 6) = CGameHost::ResendPlayerData;
  *((_DWORD *)this->m_pHandlers + 44) = CGameHost::ResendPlayerPing;
  *((_DWORD *)this->m_pHandlers + 7) = CGameHost::InitGameStruct;
  *((_DWORD *)this->m_pHandlers + 8) = CGameHost::HostPressedStart;
  *((_DWORD *)this->m_pHandlers + 9) = CGameHost::ResendFinalPData;
  *((_DWORD *)this->m_pHandlers + 45) = CGameHost::ChatLine;
  *((_DWORD *)this->m_pHandlers + 46) = CGameHost::GameAlreadyFull;
  *((_DWORD *)this->m_pHandlers + 47) = CGameHost::GameAsyncMsgGot;
  *((_DWORD *)this->m_pHandlers + 48) = CGameHost::AmIStillAlive;
  *((_DWORD *)this->m_pHandlers + 49) = CGameHost::HeIsStillAlive;
  *((_DWORD *)this->m_pHandlers + 50) = CGameHost::InitHostAfterLobby;
  *((_DWORD *)this->m_pHandlers + 51) = CGameHost::InitClientAfterLobby;
  *((_DWORD *)this->m_pHandlers + 52) = CGameHost::SendMapToClient;
  *((_DWORD *)this->m_pHandlers + 53) = CGameHost::ClientReceiveMap;
  *((_DWORD *)this->m_pHandlers + 56) = CGameHost::ClientLeavesMyGame;
  *((_DWORD *)this->m_pHandlers + 57) = CGameHost::ClientWrongVersion;
  *((_DWORD *)this->m_pHandlers + 58) = CGameHost::ClientWrongVersionAfterLobby;
  *((_DWORD *)this->m_pHandlers + 59) = CGameHost::PerformLeaveGame;
  *((_DWORD *)this->m_pHandlers + 61) = CGameHost::SendChatLine;
  *((_DWORD *)this->m_pHandlers + 60) = CGameHost::HostChoseMap;
  *((_DWORD *)this->m_pHandlers + 68) = CGameHost::QuickMatchChoseMap;
  *((_DWORD *)this->m_pHandlers + 71) = CGameHost::InviteAccepted;
  *((_DWORD *)this->m_pHandlers + 62) = CGameHost::UserDataChange;
  *((_DWORD *)this->m_pHandlers + 63) = CGameHost::KickClient;
  *((_DWORD *)this->m_pHandlers + 64) = CGameHost::WereKicked;
  *((_DWORD *)this->m_pHandlers + 65) = CGameHost::GameInGamePackedGot;
  *((_DWORD *)this->m_pHandlers + 66) = CGameHost::GameSync0MsgGot;
  *((_DWORD *)this->m_pHandlers + 67) = CGameHost::UserChangeSlots;
}


// address=[0x15b9cd0]
// Decompiled from char __thiscall CGameHost::OnHostWait(CGameHost *this, void *a2)
bool  CGameHost::OnHostWait(void * a2) {
  
  return 1;
}


// address=[0x15b9ce0]
// Decompiled from char __thiscall CGameHost::OnClientRun(CGameHost *this)
bool  CGameHost::OnClientRun(void) {
  
  if ( !this->m_pFSM || CFsm::CurrentState(this->m_pFSM) != 5 || this->m_iLastPingTime )
    return 1;
  this->m_iLastPingTime = timeGetTime();
  return 1;
}


// address=[0x15b9d20]
// Decompiled from void __thiscall CGameHost::OnHostRun(CGameHost *this)
void  CGameHost::OnHostRun(void) {
  
  DWORD v1; // esi

  if ( CFsm::CurrentState(this->m_pFSM) == 3 )
  {
    CGameHost::PingClients(this);
    v1 = this->m_iHostRun + 8000;
    if ( v1 < timeGetTime() )
      CFsm::Control(this->m_pFSM, 1035, 0);
    CFsm::Control(this->m_pFSM, 1061, 0);
    if ( this->m_iMapUpload )
      CFsm::Control(this->m_pFSM, 1042, 0);
  }
}


// address=[0x15b9da0]
// Decompiled from char __thiscall CGameHost::InitHostNetwork(CGameHost *this, void *a2)
bool  CGameHost::InitHostNetwork(void * a2) {
  
  this->m_bHost = 1;
  return 1;
}


// address=[0x15b9dc0]
// Decompiled from char __thiscall CGameHost::InitClientNetwork(CGameHost *this, void *a2)
bool  CGameHost::InitClientNetwork(void * a2) {
  
  this->m_bClient = 1;
  CFsm::GenerateEvent(this->m_pFSM, 1010, 0);
  return 1;
}


// address=[0x15b9df0]
// Decompiled from char __thiscall CGameHost::ErrorState(CGameHost *this, int a2)
bool  CGameHost::ErrorState(void * a2) {
  
  ULONG v2; // eax
  int v3; // eax
  const char *v5; // [esp+0h] [ebp-8h]

  if ( this->m_pSimpleNet )
  {
    v2 = this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet);
    v5 = this->m_pSimpleNet->GetIPString(this->m_pSimpleNet, v2);
  }
  else
  {
    v5 = 0;
  }
  v3 = CFsm::CurrentState(this->m_pFSM);
  CTrace::Print("GameHost.cpp: FSM Internal Error. Last State:%d, Event:%d (%s?)", v3, a2, v5);
  return 1;
}


// address=[0x15b9e70]
// Decompiled from void __stdcall CGameHost::ProcessPlayerData(struct SLobbyPlayerData *a1)
void  CGameHost::ProcessPlayerData(struct SLobbyPlayerData & a1) {
  
  struct CGameState *CurrentState; // eax
  std::wstring *v2; // [esp+8h] [ebp-60h]
  std::wstring *v3; // [esp+10h] [ebp-58h]
  _DWORD *v4; // [esp+18h] [ebp-50h]
  char v5; // [esp+1Fh] [ebp-49h]
  std::wstring v6; // [esp+20h] [ebp-48h] BYREF
  std::wstring v7; // [esp+3Ch] [ebp-2Ch] BYREF
  int v8; // [esp+64h] [ebp-4h]

  v5 = 0;
  g_pGameType->m_iHumanPlayers = a1->m_iHumanPlayers;
  if ( g_pGameType->m_iActualPlayerCount != a1->m_iPlayerCount )
  {
    g_pGameType->m_iActualPlayerCount = a1->m_iPlayerCount;
    v5 = 1;
  }
  v3 = (std::wstring *)std::wstring::wstring(&v7, a1->m_swpPlayerName);
  v8 = 0;
  CGameType::SetPlayerName(g_pGameType, a1->m_iPlayerId, v3);
  v8 = -1;
  std::wstring::~wstring(&v7);
  v2 = (std::wstring *)std::wstring::wstring(&v6, a1->m_swpPlayerClan);
  v8 = 1;
  CGameType::SetPlayerClanShortcut(g_pGameType, a1->m_iPlayerId, v2);
  v8 = -1;
  std::wstring::~wstring(&v6);
  g_pGameType->m_sPlayerTeam[a1->m_iPlayerId] = a1->m_iTeam;
  g_pGameType->m_sPlayerColor[a1->m_iPlayerId] = a1->m_iColor;
  g_pGameType->m_sPlayerSlot8[a1->m_iPlayerId] = a1->m_iSlot8;
  g_pGameType->m_uiIPPlayer[a1->m_iPlayerId] = a1->m_iIp;
  g_pGameType->m_sPlayerPeerId[a1->m_iPlayerId] = a1->m_iPeerId;
  g_pGameType->m_sPlayerRaces[a1->m_iPlayerId] = a1->m_iRace;
  g_pGameType->m_sPlayerType[a1->m_iPlayerId] = a1->m_iType;
  g_pGameType->m_sPlayerExclusiveColor[a1->m_iPlayerId] = a1->m_iSlot10;
  g_pGameType->m_sPlayerMapUploadStarted[a1->m_iPlayerId] = a1->m_iSlot11;
  g_pGameType->m_iStartResources = a1->m_iStartResources;
  g_pGameType->m_iMode = a1->m_iMode;
  g_pGameType->m_uExtraFlags = a1->m_uExtraFlags;
  g_pGameType->m_sPlayerSlot15[a1->m_iPlayerId] = a1->m_iSlot15;
  g_pGameType->m_iNetworkTimeDelta = a1->m_iNetworkTimeDelta;
  CGameType::SetMultiPlayerGameID(g_pGameType, a1->m_iGameId);
  memcpy(g_pGameType->m_pEconomyGoodsArray, a1->m_pEconomyGoodsArray, sizeof(g_pGameType->m_pEconomyGoodsArray));
  CLanLobby::RedrawPlayerList();
  if ( v5 )
  {
    CurrentState = CGameStateHandler::GetCurrentState();
    v4 = (_DWORD *)j____RTDynamicCast(
                     (void **)&CurrentState->__vftable,
                     0,
                     &CGameState__RTTI_Type_Descriptor_,
                     &CStateLobbyGameSettings__RTTI_Type_Descriptor_,
                     0);
    if ( v4 )
      CStateLobbyGameSettings::PaintMap(v4);
  }
}


// address=[0x15ba130]
// Decompiled from void __thiscall CGameHost::SendPlayerData(CGameHost *this, int _iFinal)
void  CGameHost::SendPlayerData(unsigned int _iFinal) {
  
  std::wstring *RealPlayerName; // eax
  wchar_t *v3; // eax
  wchar_t *v4; // eax
  std::wstring *PlayerClanShortcut; // [esp+8h] [ebp-B8h]
  unsigned __int8 v7; // [esp+17h] [ebp-A9h]
  signed int i; // [esp+18h] [ebp-A8h]
  std::wstring v9; // [esp+1Ch] [ebp-A4h] BYREF
  SLobbyPlayerData Src; // [esp+38h] [ebp-88h] BYREF
  int v11; // [esp+BCh] [ebp-4h]

  for ( i = 0; i < g_pGameType->m_iMapMaxNumPlayers; ++i )
  {
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
    RealPlayerName = CGameType::GetRealPlayerName(g_pGameType, i);
    v3 = std::wstring::c_str(RealPlayerName);
    MyWStrNCopy(Src.m_swpPlayerName, v3, 64u);
    PlayerClanShortcut = CGameType::GetPlayerClanShortcut(g_pGameType, &v9, i);
    v11 = 0;
    v4 = std::wstring::c_str(PlayerClanShortcut);
    MyWStrNCopy(Src.m_swpPlayerClan, v4, 12u);
    v11 = -1;
    std::wstring::~wstring(&v9);
    Src.m_iStartResources = g_pGameType->m_iStartResources;
    memcpy(Src.m_pEconomyGoodsArray, g_pGameType->m_pEconomyGoodsArray, sizeof(Src.m_pEconomyGoodsArray));
    Src.m_iMode = g_pGameType->m_iMode;
    Src.m_uExtraFlags = g_pGameType->m_uExtraFlags;
    Src.m_iSlot15 = g_pGameType->m_sPlayerSlot15[i];
    Src.m_iNetworkTimeDelta = g_pGameType->m_iNetworkTimeDelta;
    Src.m_iGameId = CGameType::GetMultiPlayerGameID(g_pGameType);
    v7 = _iFinal != 0;
    if ( _iFinal )
      CGameHost::SendToAll(this, 1032, &Src, 0x77u, 0, 0, v7);
    else
      CGameHost::SendToAll(this, 1026, &Src, 0x77u, 0, 0, v7);
  }
}


// address=[0x15ba420]
// Decompiled from void __thiscall CGameHost::SendToAll(  CGameHost *this,  int a2,  void *_pvData0,  size_t _uiDataLength0,  void *_pvData1,  size_t _uiDataLength1,  char a7)
void  CGameHost::SendToAll(unsigned int a2, short * _pvData0, unsigned int _uiDataLength0, short * _pvData1, unsigned int _uiDataLength1, bool a7) {
  
  uint PlayerPeerId; // eax
  uint PlayerIP; // [esp-18h] [ebp-42Ch]
  signed int i; // [esp+0h] [ebp-414h]
  char v11; // [esp+Bh] [ebp-409h]
  CGameHost::SMessage v12; // [esp+Ch] [ebp-408h] BYREF

  if ( _pvData0
    && !_uiDataLength0
    && BBSupportDbgReportF(
         2,
         "Net\\GameHost.cpp",
         4618,
         "Fatal: _pvData0 set, but _uiDataLength0 == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1 )
  {
    __debugbreak();
  }
  if ( _pvData1
    && !_uiDataLength1
    && BBSupportDbgReportF(
         2,
         "Net\\GameHost.cpp",
         4622,
         "Fatal: _pvData1 set, but _uiDataLength1 == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_bIsOnlineGame )
  {
    for ( i = 0; i < CClientList::GetSize(this->m_pClientList); ++i )
    {
      v12.m_iId = a2;
      if ( _pvData0 )
      {
        memcpy(&v12.m_cEvent, _pvData0, _uiDataLength0);
      }
      else if ( _uiDataLength0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4637, "!_uiDataLength0") == 1 )
      {
        __debugbreak();
      }
      if ( _pvData1 )
      {
        if ( !_pvData0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4642, "_pvData0") == 1 )
          __debugbreak();
        memcpy((char *)&v12.m_cEvent + _uiDataLength0, _pvData1, _uiDataLength1);
      }
      else if ( _uiDataLength1 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4647, "!_uiDataLength1") == 1 )
      {
        __debugbreak();
      }
      v11 = 1;
      if ( a2 == 1055 || a2 == 3 || a2 == 1040 )
        v11 = 0;
      PlayerIP = CClientList::GetPlayerIP(this->m_pClientList, i);
      PlayerPeerId = CClientList::GetPlayerPeerId(this->m_pClientList, i);
      this->m_pSimpleNet->PushMessage(
        this->m_pSimpleNet,
        PlayerPeerId,                           // peer id
        PlayerIP,                               // ip
        3105u,                                  // receiver?
        &v12,                                   // pData
        _uiDataLength0 + _uiDataLength1 + 2,    // length
        a7,                                     // resend
        v11);                                   // compress
    }
  }
}


// address=[0x15ba650]
// Decompiled from void __thiscall CGameHost::SendToHost(  CGameHost *this,  int a2,  void *_pvData0,  size_t _uiDataLength0,  void *_pvData1,  size_t _uiDataLength1,  char a7)
void  CGameHost::SendToHost(unsigned int a2, short * _pvData0, unsigned int _uiDataLength0, short * _pvData1, unsigned int _uiDataLength1, bool a7) {
  
  storm::SimpleSessionHandler **Instance; // eax
  uint HostPeerId; // eax
  uint iHostAddress; // [esp-18h] [ebp-428h]
  char v11; // [esp+7h] [ebp-409h]
  CGameHost::SMessage v12; // [esp+8h] [ebp-408h] BYREF

  if ( _pvData0
    && !_uiDataLength0
    && BBSupportDbgReportF(
         2,
         "Net\\GameHost.cpp",
         4673,
         "Fatal: _pvData0 set, but _uiDataLength0 == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1 )
  {
    __debugbreak();
  }
  if ( _pvData1
    && !_uiDataLength1
    && BBSupportDbgReportF(
         2,
         "Net\\GameHost.cpp",
         4677,
         "Fatal: _pvData1 set, but _uiDataLength1 == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1 )
  {
    __debugbreak();
  }
  v12.m_iId = a2;
  if ( _pvData0 )
  {
    memcpy(&v12.m_cEvent, _pvData0, _uiDataLength0);
  }
  else if ( _uiDataLength0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4687, "!_uiDataLength0") == 1 )
  {
    __debugbreak();
  }
  if ( _pvData1 )
  {
    if ( !_pvData0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4692, "_pvData0") == 1 )
      __debugbreak();
    memcpy((char *)&v12.m_cEvent + _uiDataLength0, _pvData1, _uiDataLength1);
  }
  else if ( _uiDataLength1 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4697, "!_uiDataLength1") == 1 )
  {
    __debugbreak();
  }
  v11 = 1;
  if ( a2 == 1055 || a2 == 3 || a2 == 1040 )
    v11 = 0;
  if ( !this->m_pSimpleNet && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4709, "m_pSimpleNet!=NULL") == 1 )
    __debugbreak();
  if ( this->m_pSimpleNet )
  {
    iHostAddress = g_pGameType->m_iHostAddress;
    Instance = (storm::SimpleSessionHandler **)StormManager::GetInstance();
    HostPeerId = StormManager::GetHostPeerId(Instance);
    this->m_pSimpleNet->PushMessage(
      this->m_pSimpleNet,
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
bool  CGameHost::AddGame(struct SGameInfo & a2) {
  
  int v3; // [esp-10h] [ebp-8Ch] BYREF
  int v4; // [esp-Ch] [ebp-88h] BYREF
  int v5; // [esp-8h] [ebp-84h]
  struct SGameInfo *v6; // [esp-4h] [ebp-80h]
  _BYTE v7[12]; // [esp+4h] [ebp-78h] BYREF
  _BYTE v8[12]; // [esp+10h] [ebp-6Ch] BYREF
  _BYTE v9[12]; // [esp+1Ch] [ebp-60h] BYREF
  _BYTE v10[12]; // [esp+28h] [ebp-54h] BYREF
  std::_Iterator_base12 *v11[10]; // [esp+34h] [ebp-48h] BYREF
  std::_Iterator_base12 *v12; // [esp+5Ch] [ebp-20h]
  SGameInfo *v14; // [esp+64h] [ebp-18h]
  char v16; // [esp+6Eh] [ebp-Eh]
  char v17; // [esp+6Fh] [ebp-Dh]
  int v18; // [esp+78h] [ebp-4h]

  if ( !CGameHost::IsValidSaveGame(this, a2) )
    return 1;
  std::list<SGameInfo>::begin(&this->m_vGameInfos, (int)v11);
  v18 = 0;
  while ( 1 )
  {
    v12 = (std::_Iterator_base12 *)std::list<SGameInfo>::end(v9);
    v11[9] = v12;
    LOBYTE(v18) = 1;
    v17 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator!=(v12);
    LOBYTE(v18) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v9);
    if ( !v17 )
      break;
    v14 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v11);
    if ( LODWORD(v14->m_uSessionId) == LODWORD(a2->m_uSessionId)
      && HIDWORD(v14->m_uSessionId) == HIDWORD(a2->m_uSessionId) )
    {
      v6 = a2;
      v11[8] = (std::_Iterator_base12 *)&v3;
      v11[7] = (std::_Iterator_base12 *)std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>((struct std::_Iterator_base12 *)v11);
      v11[6] = (std::_Iterator_base12 *)std::list<SGameInfo>::insert(v8, v3, v4, v5, v6);
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v8);
      v11[5] = (std::_Iterator_base12 *)&v4;
      v11[4] = (std::_Iterator_base12 *)std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>((struct std::_Iterator_base12 *)v11);
      v11[3] = (std::_Iterator_base12 *)std::list<SGameInfo>::erase(v7, v4, v5, v6);
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v7);
      CLanLobby::RedrawGameList();
      v16 = 1;
      v18 = -1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v11);
      return v16;
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator++(v10, 0);
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v10);
  }
  std::list<SGameInfo>::push_back(a2);
  CLanLobby::RedrawGameList();
  v18 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v11);
  return 1;
}


// address=[0x15baa20]
// Decompiled from int __thiscall CGameHost::ValidateGameList(CGameHost *this)
void  CGameHost::ValidateGameList(void) {
  
  char v2; // [esp-1Ch] [ebp-A8h] BYREF
  int v3; // [esp-18h] [ebp-A4h] BYREF
  int v4; // [esp-14h] [ebp-A0h]
  int v5; // [esp-10h] [ebp-9Ch] BYREF
  int v6; // [esp-Ch] [ebp-98h] BYREF
  int v7; // [esp-8h] [ebp-94h]
  int v8; // [esp-4h] [ebp-90h]
  _BYTE v9[12]; // [esp+4h] [ebp-88h] BYREF
  _BYTE v10[12]; // [esp+10h] [ebp-7Ch] BYREF
  _BYTE v11[12]; // [esp+1Ch] [ebp-70h] BYREF
  _BYTE v12[12]; // [esp+28h] [ebp-64h] BYREF
  int v13; // [esp+34h] [ebp-58h]
  int v14; // [esp+38h] [ebp-54h]
  int *v15; // [esp+3Ch] [ebp-50h]
  int v16; // [esp+40h] [ebp-4Ch]
  int *v17; // [esp+44h] [ebp-48h]
  int v18; // [esp+48h] [ebp-44h]
  int v19; // [esp+4Ch] [ebp-40h]
  char *v20; // [esp+50h] [ebp-3Ch]
  int v21; // [esp+54h] [ebp-38h]
  int *v22; // [esp+58h] [ebp-34h]
  int v23; // [esp+5Ch] [ebp-30h] BYREF
  int v24; // [esp+60h] [ebp-2Ch]
  int v25; // [esp+64h] [ebp-28h]
  int v26; // [esp+68h] [ebp-24h]
  std::_Iterator_base12 *v27; // [esp+6Ch] [ebp-20h]
  std::_Iterator_base12 *v28; // [esp+70h] [ebp-1Ch]
  DWORD Time; // [esp+74h] [ebp-18h] BYREF
  char v31; // [esp+7Fh] [ebp-Dh]
  int v32; // [esp+88h] [ebp-4h]

  Time = timeGetTime();
  v8 = *std::_Iterator_base12::operator=(&v23, &Time);
  v22 = &v5;
  v21 = std::list<SGameInfo>::end(&v5);
  v20 = &v2;
  v19 = std::list<SGameInfo>::begin(&this->m_vGameInfos, (int)&v2);// (unsigned int)(a2->m_iStartTime + 6000) < Time;
  v18 = std::remove_if<std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>,_lambda_a570ae9d9b6327d9fce7c622bf5e21bb_>(
          (int)v12,
          v2,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8);
  v32 = 0;
  v28 = (std::_Iterator_base12 *)std::list<SGameInfo>::end(v11);
  v27 = v28;
  LOBYTE(v32) = 1;
  v31 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator!=(v28);
  LOBYTE(v32) = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v11);
  if ( v31 )
  {
    v26 = std::list<SGameInfo>::end(v9);
    v25 = v26;
    LOBYTE(v32) = 2;
    v17 = &v6;
    v24 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v26);
    v16 = v24;
    LOBYTE(v32) = 3;
    v15 = &v3;
    v14 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>((struct std::_Iterator_base12 *)v12);
    LOBYTE(v32) = 2;
    v13 = std::list<SGameInfo>::erase(v10, v3, v4, v5, v6, v7, v8);
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v10);
    LOBYTE(v32) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v9);
    CLanLobby::RedrawGameList();
  }
  v32 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v12);
}


// address=[0x15baba0]
// Decompiled from int __thiscall CGameHost::GetLocalID(CGameHost *this)
unsigned int  CGameHost::GetLocalID(void) {
  
  int Instance; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < g_pGameType->m_iMapMaxNumPlayers; ++i )
  {
    Instance = StormManager::GetInstance();
    if ( StormManager::GetLocalPeerId(Instance) == g_pGameType->m_sPlayerPeerId[i] )
      return i;
  }
  if ( BBSupportDbgReportF(2, "Net\\GameHost.cpp", 2969, "No local ID found !!!") == 1 )
    __debugbreak();
  return -1;
}


// address=[0x15bac30]
// Decompiled from int __thiscall CGameHost::GetSlot(CGameHost *this, unsigned int a2)
int  CGameHost::GetSlot(unsigned int a2) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    if ( g_pGameType->m_uiIPPlayer[i] == a2 )
      return i;
  }
  if ( BBSupportDbgReportF(2, "Net\\GameHost.cpp", 4736, "Player IP not found in g_pGameType!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x15bacb0]
// Decompiled from void __thiscall CGameHost::NotifyClients(CGameHost *this, int a2)
void  CGameHost::NotifyClients(unsigned int a2) {
  
  uint ValidTick; // eax
  unsigned int v3; // eax
  wchar_t *v4; // eax
  wchar_t *v5; // eax
  size_t v6; // [esp-4h] [ebp-F0h]
  size_t v7; // [esp+8h] [ebp-E4h]
  std::wstring *v8; // [esp+Ch] [ebp-E0h]
  std::wstring *PlayerName; // [esp+10h] [ebp-DCh]
  struct CEvn_Event *v10; // [esp+18h] [ebp-D4h]
  struct CEvn_Logic *v11; // [esp+20h] [ebp-CCh]
  DWORD v12; // [esp+28h] [ebp-C4h]
  int LastMsgTime; // [esp+30h] [ebp-BCh]
  signed int a3; // [esp+34h] [ebp-B8h]
  int i; // [esp+38h] [ebp-B4h]
  unsigned int a2a; // [esp+40h] [ebp-ACh]
  char v18; // [esp+47h] [ebp-A5h]
  CEvn_Logic v19; // [esp+48h] [ebp-A4h] BYREF
  std::wstring v20; // [esp+68h] [ebp-84h] BYREF
  std::wstring v21; // [esp+84h] [ebp-68h] BYREF
  CEvn_Event v22; // [esp+A0h] [ebp-4Ch] BYREF
  char Dest[36]; // [esp+B8h] [ebp-34h] BYREF
  int v24; // [esp+E8h] [ebp-4h]

  v18 = 0;
  a3 = timeGetTime();
  for ( a2a = 0; a2a < g_pGameType->m_iActualPlayerCount; ++a2a )
  {
    if ( (a2 & (1 << a2a)) != 0 && a2a != CGameHost::GetLocalID(this) )
    {
      LastMsgTime = CMsgStacks::GetLastMsgTime(this->m_pMsgStacks, a2a);
      if ( LastMsgTime )
      {
        if ( LastMsgTime + CStaticConfigVarInt::operator int(&g_iNotReadyKickDelay) >= a3 )
        {
          if ( LastMsgTime + CStaticConfigVarInt::operator int(&g_iNotReadyWarnDelay) < a3
            && (!this->m_iReadyTime
             || this->m_iReadyTime + CStaticConfigVarInt::operator int(&g_iNotReadyWarnAgainDelay) < (unsigned int)a3) )
          {
            CTrace::Print("CGameHost.cpp: Waiting for Player index#%d !", a2a);
            this->m_iReadyTime = a3;
            PlayerName = CGameType::GetPlayerName(g_pGameType, &v20, a2a);
            v24 = 2;
            v4 = std::wstring::c_str(PlayerName);
            v6 = wcslen(v4);
            v8 = CGameType::GetPlayerName(g_pGameType, &v21, a2a);
            v5 = std::wstring::c_str(v8);
            v7 = j__wcstombs(Dest, v5, v6);
            std::wstring::~wstring(&v21);
            v24 = -1;
            std::wstring::~wstring(&v20);
            if ( v7 >= 0x21 )
              report_rangecheckfailure();
            Dest[v7] = 0;
            CTextMsgHandler::AddTextMsg(GUI_SYS_WAIT_FOR_PLAYER, a2a + 1, 0, 1, Dest);
            v18 = 1;
          }
        }
        else
        {
          CTrace::Print("GameHost.cpp: Kicking player index#%d!", a2a);
          v12 = g_pGameType->m_sPlayerPeerId[a2a];
          for ( i = 1; i <= CPlayerManager::LastPlayerId() && CPlayerManager::PeerId(i) != v12; ++i )
            ;
          CGameHost::RemovePlayerPeerId(this, g_pGameType->m_sPlayerPeerId[a2a]);
          ValidTick = CGameHost::GetValidTick(this);
          v11 = CEvn_Logic::CEvn_Logic(&v19, 0xFA9u, i, ValidTick, i, 0, 0);
          v24 = 0;
          INetworkEngine::SendAsyncNetMessage(g_pNetworkEngine, v11, 255);
          v24 = -1;
          CEvn_Logic::~CEvn_Logic(&v19);
          v3 = CGameHost::GetValidTick(this);
          v10 = CEvn_Event::CEvn_Event(&v22, 0xFA9u, i, v3, 0);
          v24 = 1;
          IEventEngine::SendAMessage(g_pEvnEngine, v10);
          v24 = -1;
          CEvn_Event::~CEvn_Event(&v22);
          v18 = 1;
        }
      }
      else
      {
        CMsgStacks::SetLastMsgTime(this->m_pMsgStacks, a2a, a3, 0);
      }
    }
  }
  if ( v18 )
    CGameHost::SendToAll(this, 1040, 0, 0, 0, 0, 0);
}


// address=[0x15bb0e0]
// Decompiled from char __thiscall CGameHost::IsExclusiveColor(CGameHost *this, int a2)
bool  CGameHost::IsExclusiveColor(int a2) {
  
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < g_pGameType->m_iMapMaxNumPlayers; ++i )
  {
    if ( i != a2
      && g_pGameType->m_sPlayerColor[i] == g_pGameType->m_sPlayerColor[a2]
      && !g_pGameType->m_sPlayerExclusiveColor[i] )
    {
      return 0;
    }
  }
  return 1;
}


// address=[0x15bb160]
// Decompiled from char __thiscall CGameHost::HostChoseMap(CGameHost *this, int a2)
bool  CGameHost::HostChoseMap(void * a2) {
  
  wchar_t *v2; // eax
  wchar_t *v3; // eax
  OnlineManager *Instance; // eax
  struct CGameType *v6; // [esp-4h] [ebp-C0h]
  std::wstring *v7; // [esp+0h] [ebp-BCh]
  std::wstring *PlayerName; // [esp+4h] [ebp-B8h]
  unsigned int i; // [esp+14h] [ebp-A8h]
  std::wstring v11; // [esp+18h] [ebp-A4h] BYREF
  std::wstring v12; // [esp+34h] [ebp-88h] BYREF
  wchar_t Destination[32]; // [esp+50h] [ebp-6Ch] BYREF
  int v14; // [esp+91h] [ebp-2Bh]
  char v15; // [esp+B4h] [ebp-8h]

  v15 = -1;
  if ( !CGameType::IsSaveGame(g_pGameType) || !CGameType::IsMultiplayerGame(g_pGameType) )
  {
    PlayerName = (std::wstring *)CGameSettings::GetPlayerName((int)&v12);
    v2 = std::wstring::c_str(PlayerName);
    wcsncpy(Destination, v2, 0x1Fu);
    std::wstring::~wstring(&v12);
    Destination[31] = 0;
    v14 = 0;
    g_pGameType->m_sPlayerType[0] = 1;
    CLanLobby::ConnectPlayer(Destination, -1);
  }
  for ( i = 1; i < g_pGameType->m_iActualPlayerCount; ++i )
  {
    if ( g_pGameType->m_sPlayerType[i] == 2
      || g_pGameType->m_sPlayerType[i] == 3
      || g_pGameType->m_bPlayerSlotEmpty[i] && !this->m_bIsOnlineGame )
    {
      v14 = -1;
      v7 = CGameType::GetPlayerName(g_pGameType, &v11, i);
      v3 = std::wstring::c_str(v7);
      wcsncpy(Destination, v3, 0x1Fu);
      std::wstring::~wstring(&v11);
      Destination[31] = 0;
      CLanLobby::ConnectPlayer(Destination, i);
    }
  }
  if ( CGameType::IsMultiplayerGame(g_pGameType) )
  {
    v6 = g_pGameType;
    Instance = (OnlineManager *)OnlineManager::GetInstance();
    OnlineManager::CreateSession(Instance, v6);
  }
  CFsm::GenerateEvent(this->m_pFSM, 1009, 0);
  return 1;
}


// address=[0x15bb380]
// Decompiled from char __stdcall CGameHost::QuickMatchChoseMap(int a1)
bool  CGameHost::QuickMatchChoseMap(void * a1) {
  
  CGameType *v2; // [esp-4h] [ebp-8h]

  v2 = g_pGameType;
  OnlineManager::GetInstance();
  OnlineManager::QuickMatch((int)v2);
  return 1;
}


// address=[0x15bb3b0]
// Decompiled from char __thiscall CGameHost::InviteAccepted(CGameHost *this, void *a2)
bool  CGameHost::InviteAccepted(void * a2) {
  
  OnlineManager *Instance; // eax
  void *v3; // eax
  OnlineManager *v5; // eax
  OnlineManager *v6; // eax
  unsigned __int64 v7; // [esp+0h] [ebp-10h] BYREF
  int v9; // [esp+Ch] [ebp-4h]

  v7 = (int)a2;
  Instance = (OnlineManager *)OnlineManager::GetInstance();
  if ( OnlineManager::IsInSession(Instance) )
  {
    v3 = (void *)OnlineManager::GetInstance();
    OnlineManager::LeaveSession(v3);
    v9 = UPlay::UPlayManager::GetInstance();
    (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)v9 + 44))(v9, v7, HIDWORD(v7));
  }
  else
  {
    v5 = (OnlineManager *)OnlineManager::GetInstance();
    OnlineManager::SetInviteFlow(v5, 1);
    v6 = (OnlineManager *)OnlineManager::GetInstance();
    OnlineManager::JoinSession(v6, &v7);
  }
  return 1;
}


// address=[0x15bb430]
// Decompiled from char __stdcall CGameHost::StartState(int a1)
bool  CGameHost::StartState(void * a1) {
  
  return 0;
}


// address=[0x15bb440]
// Decompiled from char __thiscall CGameHost::SearchHost(CGameHost *this, int a2)
bool  CGameHost::SearchHost(void * a2) {
  
  void *Instance; // eax
  int v3; // eax
  _BYTE v5[12]; // [esp+Ch] [ebp-4C8h] BYREF
  _BYTE v6[12]; // [esp+18h] [ebp-4BCh] BYREF
  _DWORD v7[3]; // [esp+24h] [ebp-4B0h] BYREF
  _BYTE *v9; // [esp+34h] [ebp-4A0h]
  char v10; // [esp+3Bh] [ebp-499h]
  struct SGameInfo sGameInfo; // [esp+3Ch] [ebp-498h] BYREF
  int v12; // [esp+4D0h] [ebp-4h]

  CTrace::Print("Start searching Host .... ");
  std::list<SGameInfo>::list<SGameInfo>(v6);
  v12 = 0;
  Instance = (void *)OnlineManager::GetInstance();
  OnlineManager::UpdateDiscoveredSessions(Instance, (int)v6);
  v9 = v6;
  std::list<SGameInfo>::begin(v6, (int)v7);
  LOBYTE(v12) = 1;
  std::list<SGameInfo>::end(v5);
  LOBYTE(v12) = 2;
  while ( (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator!=((std::_Iterator_base12 *)v5) )
  {
    qmemcpy(
      &sGameInfo,
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v7),
      sizeof(sGameInfo));
    sGameInfo.m_iStartTime = timeGetTime();
    CGameHost::AddGame(this, &sGameInfo);
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator++(v7);
  }
  LOBYTE(v12) = 1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v5);
  LOBYTE(v12) = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v7);
  CGameHost::ValidateGameList();
  v3 = OnlineManager::GetInstance();
  OnlineManager::SearchForSessions(v3);
  v10 = 1;
  v12 = -1;
  std::list<SGameInfo>::~list<SGameInfo>();
  return v10;
}


// address=[0x15bb5b0]
// Decompiled from char __thiscall CGameHost::ClientSearchesGameHost(CGameHost *this, int a2)
bool  CGameHost::ClientSearchesGameHost(void * a2) {
  
  wchar_t *v2; // eax
  wchar_t *v3; // eax
  uint v4; // eax
  u_short v6; // [esp+0h] [ebp-478h]
  BOOL v7; // [esp+8h] [ebp-470h]
  char v9; // [esp+10h] [ebp-468h]
  CGameHost::SSearchMessage sMsg; // [esp+18h] [ebp-460h] BYREF
  FilePaths::PathSplitResult a1; // [esp+41Ch] [ebp-5Ch] BYREF
  int v12; // [esp+474h] [ebp-4h]

  memset(&sMsg, 0, sizeof(sMsg));
  sMsg.m_iMessageId = 1022;
  sMsg.m_uByte261 = g_pGameType->byte261;
  sMsg.m_iHumanPlayers = g_pGameType->m_iHumanPlayers;
  sMsg.m_iMapCRC = g_pGameType->m_iMapCRC;
  sMsg.m_iActualPlayerCount = g_pGameType->m_iActualPlayerCount;
  sMsg.m_iFileSize = g_pGameType->m_iFileSize;
  v7 = std::string::length(&g_pGameType->std__string298) != 0;
  sMsg.m_iLenString298 = v7;
  sMsg.m_bIsSaveGame = g_pGameType->m_bIsSaveGame;
  sMsg.bIsAutosave = g_pGameType->bIsAutosave;
  sMsg.m_uiTickCounter = g_pGameType->m_uiTickCounter;
  sMsg.m_iMultiPlayerGameId = CGameType::GetMultiPlayerGameID(g_pGameType);
  sMsg.m_iMPSavegameId = CGameType::GetMPSavegameID(g_pGameType);
  sMsg.m_bIsSaveGame = CGameType::IsSaveGame(g_pGameType);
  sMsg.m_uExtraFlags = g_pGameType->m_uExtraFlags;
  v2 = std::wstring::c_str(&g_pGameType->m_swGameName);
  MyWStrNCopy(sMsg.m_swpGameName, v2, 0x40u);
  FilePaths::SplitPath(&a1, &g_pGameType->m_swMapName);
  v12 = 0;
  v3 = std::wstring::c_str(&a1.m_swpDirectoryName);
  MyWStrNCopy(sMsg.m_swpMapName, v3, 512u);
  this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet);
  v4 = this->m_pSimpleNet->GetLastSenderPeerId(this->m_pSimpleNet);
  this->m_pSimpleNet->PushMessage(this->m_pSimpleNet, v4, 1u, v6, &a1, v7, (char)this, v9);
  v12 = -1;
  FilePaths::PathSplitResult::~PathSplitResult(&a1);
  return 1;
}


// address=[0x15bb880]
// Decompiled from char __thiscall CGameHost::ClientReceivesGameInfo(CGameHost *this, void *Src)
bool  CGameHost::ClientReceivesGameInfo(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  wchar_t *v3; // eax
  int iMapCRC; // [esp-4h] [ebp-508h]
  std::wstring *a2; // [esp+4h] [ebp-500h]
  _Cnd_internal_imp_t *v7; // [esp+Ch] [ebp-4F8h]
  struct SGameInfo sGameInfo; // [esp+18h] [ebp-4ECh] BYREF
  std::wstring v10; // [esp+4A0h] [ebp-64h] BYREF
  std::wstring v11; // [esp+4BCh] [ebp-48h] BYREF
  std::wstring v12; // [esp+4D8h] [ebp-2Ch] BYREF
  int v13; // [esp+500h] [ebp-4h]

  if ( (unsigned __int16)CGameHost::GetMessageLength(this) != 1144 )
    return 1;
  sGameInfo.m_iHostAddress = this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet);
  MessageLength = CGameHost::GetMessageLength(this);
  memcpy(sGameInfo.m_swpGameName, Src, MessageLength);
  v7 = (_Cnd_internal_imp_t *)std::wstring::wstring(&v11, sGameInfo.m_swpMapName);
  v13 = 0;
  MapFilePaths::GetFilePathForMapName((int)&v12, v7);
  LOBYTE(v13) = 2;
  std::wstring::~wstring(&v11);
  v3 = std::wstring::c_str(&v12);
  MyWStrNCopy(sGameInfo.m_swpMapName, v3, 0x200u);
  iMapCRC = sGameInfo.m_iMapCRC;
  a2 = (std::wstring *)std::wstring::wstring(&v10, sGameInfo.m_swpMapName);
  LOBYTE(v13) = 3;
  sGameInfo.m_bMapAvailable = CGameType::IsMapAvailable(g_pGameType, a2, iMapCRC);
  LOBYTE(v13) = 2;
  std::wstring::~wstring(&v10);
  sGameInfo.m_iStartTime = timeGetTime();
  CGameHost::AddGame(this, &sGameInfo);
  v13 = -1;
  std::wstring::~wstring(&v12);
  return 1;
}


// address=[0x15bba10]
// Decompiled from char __thiscall CGameHost::ClientLoginHost(CGameHost *this, void *arg0)
bool  CGameHost::ClientLoginHost(void * arg0) {
  
  int Instance; // eax
  int v3; // eax
  StormManager *v4; // eax
  wchar_t *v5; // eax
  wchar_t *v6; // eax
  OnlineManager *v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned __int64 *p_m_uSessionId; // [esp-4h] [ebp-1368h]
  _BYTE v12[12]; // [esp+4h] [ebp-1360h] BYREF
  _BYTE v13[12]; // [esp+10h] [ebp-1354h] BYREF
  std::wstring *v14[3]; // [esp+1Ch] [ebp-1348h] BYREF
  std::wstring *a2; // [esp+28h] [ebp-133Ch]
  int v16; // [esp+2Ch] [ebp-1338h]
  std::_Iterator_base12 *v17; // [esp+30h] [ebp-1334h]
  std::_Iterator_base12 *v18; // [esp+34h] [ebp-1330h]
  GameSessionDescriptor *CurrentSession; // [esp+38h] [ebp-132Ch]
  int v20; // [esp+3Ch] [ebp-1328h]
  SGameInfo *v21; // [esp+40h] [ebp-1324h]
  char v22; // [esp+46h] [ebp-131Eh]
  char v23; // [esp+47h] [ebp-131Dh]
  struct CGameChunkGeneral v25; // [esp+4Ch] [ebp-1318h] BYREF
  struct CGameChunkGeneral v26; // [esp+9B4h] [ebp-9B0h] BYREF
  std::wstring v27; // [esp+131Ch] [ebp-48h] BYREF
  std::wstring v28; // [esp+1338h] [ebp-2Ch] BYREF
  int v29; // [esp+1360h] [ebp-4h]

  std::wstring::wstring(&v28);
  v29 = 0;
  Instance = OnlineManager::GetInstance();
  if ( (unsigned __int8)OnlineManager::IsQuickMatchFlow(Instance)
    || (v3 = OnlineManager::GetInstance(), (unsigned __int8)OnlineManager::IsInviteFlow(v3)) )
  {
    v4 = (StormManager *)StormManager::GetInstance();
    CurrentSession = StormManager::GetCurrentSession(v4);
    g_pGameType->m_iActualPlayerCount = GameSessionDescriptor::GetPeerCount(CurrentSession);
    g_pGameType->m_uiTickCounter = GameSessionDescriptor::GetTickCount(CurrentSession);
    this->m_bHost = 0;
    this->m_bClient = 1;
    std::wstring::operator=(&v28, &g_pGameType->m_swSaveFile);
    CGameChunkGeneral::CGameChunkGeneral(&v26);
    g_pRandomMaps->AdjustRandomMapFileName(g_pRandomMaps, &v28);
    v5 = std::wstring::c_str(&v28);
    CGameRun::LoadGeneralInfo(v5, &v26);
    while ( CClientList::GetSize(this->m_pClientList) )
      CClientList::RemoveClientAt(0);
    CGameType::SetLocalSlot(g_pGameType, v26.m_cLocalSlot);
  }
  else
  {
    v16 = (int)arg0;
    v20 = 0;
    std::list<SGameInfo>::begin(&this->m_vGameInfos, (int)v14);
    LOBYTE(v29) = 1;
    while ( 1 )
    {
      v18 = (std::_Iterator_base12 *)std::list<SGameInfo>::end(v12);
      v17 = v18;
      LOBYTE(v29) = 2;
      v23 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator!=(v18);
      LOBYTE(v29) = 1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v12);
      if ( !v23 || v20 == v16 )
        break;
      ++v20;
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator++(v13, 0);
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v13);
    }
    v21 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v14);
    g_pGameType->m_iActualPlayerCount = v21->m_iPlayerCount;
    g_pGameType->m_iFileSize = v21->m_iFileSize;
    g_pGameType->m_uiTickCounter = v21->m_uTickCounter;
    a2 = (std::wstring *)std::wstring::wstring(&v27, v21->m_swpRandomMapFileName);
    std::wstring::operator=(&v28, a2);
    std::wstring::~wstring(&v27);
    if ( v21->m_bIsAutosave )
      std::wstring::operator+=(&v28, (wchar_t *)L"_autoSave");
    std::wstring::operator+=(&v28, (wchar_t *)L".sav");
    CGameChunkGeneral::CGameChunkGeneral(&v25);
    g_pRandomMaps->AdjustRandomMapFileName(g_pRandomMaps, &v28);
    v6 = std::wstring::c_str(&v28);
    CGameRun::LoadGeneralInfo(v6, &v25);
    CGameType::SetLocalSlot(g_pGameType, v25.m_cLocalSlot);
    while ( CClientList::GetSize(this->m_pClientList) )
      CClientList::RemoveClientAt(0);
    p_m_uSessionId = &v21->m_uSessionId;
    v7 = (OnlineManager *)OnlineManager::GetInstance();
    OnlineManager::JoinSession(v7, p_m_uSessionId);
    LOBYTE(v29) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v14);
  }
  this->m_iNotReadyTimeoutTick = timeGetTime();
  v8 = OnlineManager::GetInstance();
  if ( (unsigned __int8)OnlineManager::IsQuickMatchFlow(v8)
    || (v9 = OnlineManager::GetInstance(), (unsigned __int8)OnlineManager::IsInviteFlow(v9)) )
  {
    CGameHost::StormJoinSessionSucceeded(this);
  }
  v22 = 1;
  v29 = -1;
  std::wstring::~wstring(&v28);
  return v22;
}


// address=[0x15bbdf0]
// Decompiled from char __thiscall CGameHost::ClientJoins(CGameHost *this, void *Src)
bool  CGameHost::ClientJoins(void * Src) {
  
  int _uIp; // eax
  int uPlayerId; // [esp-8h] [ebp-90h]
  signed int v5; // [esp+4h] [ebp-84h]
  int iLocalSlotID; // [esp+8h] [ebp-80h]
  unsigned int j; // [esp+Ch] [ebp-7Ch]
  DWORD _uPeerId; // [esp+10h] [ebp-78h]
  int i; // [esp+14h] [ebp-74h]
  CGameHost::SJoinMessage sMsg; // [esp+1Ch] [ebp-6Ch] BYREF

  memcpy(&sMsg, Src, sizeof(sMsg));
  _uPeerId = sMsg.m_iPeerId;
  if ( CClientList::ContainsPeerId(this->m_pClientList, sMsg.m_iPeerId) )
    return 1;
  if ( CGameType::IsSaveGame(g_pGameType) )
  {
    if ( !CLanLobby::ConnectPlayer(&sMsg, sMsg.m_iRequestedSlot) )
      return 1;
  }
  else
  {
    v5 = -1;
    if ( CGameType::IsWebGame(g_pGameType) )
    {
      v5 = 8;
      for ( i = 0; i < 8; ++i )
      {
        if ( g_pGameType->m_sPlayerPeerId[i] == sMsg.m_iPeerId )
        {
          v5 = i;
          break;
        }
      }
    }
    if ( v5 == 8 || !CLanLobby::ConnectPlayer(&sMsg, v5) )
      return 1;
  }
  if ( !CClientList::ContainsPeerId(this->m_pClientList, _uPeerId) )
  {
    uPlayerId = CClientList::CreateNewPlayerID(this->m_pClientList);
    _uIp = this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet);
    CClientList::Add(this->m_pClientList, _uIp, uPlayerId, _uPeerId);
  }
  iLocalSlotID = -1;
  for ( j = 0; j < g_pGameType->m_iActualPlayerCount && iLocalSlotID == -1; ++j )
  {
    if ( g_pGameType->m_sPlayerPeerId[j] == _uPeerId )
      iLocalSlotID = j;
  }
  if ( iLocalSlotID < 0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2508, "iLocalSlotID >=0") == 1 )
    __debugbreak();
  if ( iLocalSlotID >= 0 )
    g_pGameType->m_bPlayerSlotEmpty[iLocalSlotID] = 0;
  CLanLobby::RedrawPlayerList();
  CFsm::Control(this->m_pFSM, 1035, 0);
  return 1;
}


// address=[0x15bc010]
// Decompiled from char __stdcall CGameHost::ClientWrongVersion(int a1)
bool  CGameHost::ClientWrongVersion(void * a1) {
  
  CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, (void *)0x96C);
  CGameStateHandler::Switch(CStateLobbyConnect::DynamicCreateFunc, 0);
  return 1;
}


// address=[0x15bc040]
// Decompiled from char __stdcall CGameHost::ClientWrongVersionAfterLobby(int a1)
bool  CGameHost::ClientWrongVersionAfterLobby(void * a1) {
  
  CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, (void *)0x96E);
  CGameStateHandler::Switch(CStateMainMenu::DynamicCreateFunc, 0);
  return 1;
}


// address=[0x15bc070]
// Decompiled from char __thiscall CGameHost::ClientReceivePlayerData(CGameHost *this, void *Src)
bool  CGameHost::ClientReceivePlayerData(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  struct CEvn_Event *v4; // [esp+Ch] [ebp-ACh]
  struct SLobbyPlayerData sPlayerData; // [esp+18h] [ebp-A0h] BYREF
  CEvn_Event v7; // [esp+90h] [ebp-28h] BYREF
  int v8; // [esp+B4h] [ebp-4h]

  MessageLength = CGameHost::GetMessageLength(this);
  memcpy(&sPlayerData, Src, MessageLength);
  if ( sPlayerData.m_iFinal
    && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2685, "data.m_iFinal == PLAYERDATA_UPDATE") == 1 )
  {
    __debugbreak();
  }
  CGameHost::ProcessPlayerData(&sPlayerData);
  if ( this->m_bHasSentMap )
    return 1;
  if ( !CGameType::IsMapAvailable(g_pGameType, &g_pGameType->m_swMapName, g_pGameType->m_iMapCRC)
    && !CGameType::IsSaveGame(g_pGameType)
    && !this->m_bMapBeingDownloaded )
  {
    CGameHost::SendToHost(1042, 0, 0, 0, 0, 1);
    v4 = CEvn_Event::CEvn_Event(&v7, 80u, 1u, 0, 0);
    v8 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v4);
    v8 = -1;
    CEvn_Event::~CEvn_Event(&v7);
    if ( this->m_bMapBeingDownloaded && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2699, "!m_bMapBeingDownloaded") == 1 )
      __debugbreak();
    this->m_iMapDownloadLastBlock = g_pGameType->m_iFileSize / 0x300u;
    if ( g_pGameType->m_iFileSize % 0x300u )
      ++this->m_iMapDownloadLastBlock;
    this->m_pMapDownloadBlocks = (BYTE *)operator new[](this->m_iMapDownloadLastBlock);
    memset(this->m_pMapDownloadBlocks, 0, this->m_iMapDownloadLastBlock);
    this->m_pMapDownloadData = (BYTE *)operator new[](g_pGameType->m_iFileSize);
    this->m_iMapDownloadBlocksArrived = 0;
    this->m_bMapBeingDownloaded = 1;
    CTrace::Print(
      "GameHost.cpp: Map download scheduled. Waiting for %d bytes in %d blocks.!",
      g_pGameType->m_iFileSize,
      this->m_iMapDownloadLastBlock);
  }
  this->m_bHasSentMap = 1;
  return 1;
}


// address=[0x15bc320]
// Decompiled from char __thiscall CGameHost::ClientReceivePlayerPing(CGameHost *this, void *Src)
bool  CGameHost::ClientReceivePlayerPing(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  unsigned __int8 v4; // [esp+0h] [ebp-Ch] BYREF
  DWORD v5; // [esp+1h] [ebp-Bh]

  MessageLength = CGameHost::GetMessageLength(this);
  memcpy(&v4, Src, MessageLength);
  g_pGameType->m_sPlayerAckDelta[v4] = v5;
  CLanLobby::RedrawPlayerList();
  return 1;
}


// address=[0x15bc370]
// Decompiled from char __thiscall CGameHost::ClientLobbyPrepare(void *this, int a2)
bool  CGameHost::ClientLobbyPrepare(void * a2) {
  
  int savedregs; // [esp+4h] [ebp+0h]

  std::list<SGameInfo>::clear((int)this, savedregs);
  CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateLobbyGameSettings::DynamicCreateFunc, 0);
  return 0;
}


// address=[0x15bc3a0]
// Decompiled from char __thiscall CGameHost::ResendPlayerData(void *this, int a2)
bool  CGameHost::ResendPlayerData(void * a2) {
  
  CGameHost::SendPlayerData(this, 0);
  return 1;
}


// address=[0x15bc3c0]
// Decompiled from char __thiscall CGameHost::ResendPlayerPing(CGameHost *this, int a2)
bool  CGameHost::ResendPlayerPing(void * a2) {
  
  CGameHost::SPingMessage Src; // [esp+0h] [ebp-10h] BYREF
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < g_pGameType->m_iMapMaxNumPlayers; ++i )
  {
    memset(&Src, 0, sizeof(Src));
    Src.m_iPlayerId = i;
    Src.m_iDelta = g_pGameType->m_sPlayerAckDelta[i];
    CGameHost::SendToAll(this, 1034, &Src, 5u, 0, 0, 1u);
  }
  this->m_iHostRun = timeGetTime();
  return 1;
}


// address=[0x15bc450]
// Decompiled from char __thiscall CGameHost::HostPressedStart(CGameHost *this, int a2)
bool  CGameHost::HostPressedStart(void * a2) {
  
  int MultiPlayerGameID; // eax
  DWORD v4; // [esp-10h] [ebp-41Ch]
  int v5; // [esp-Ch] [ebp-418h]
  DWORD v6; // [esp-4h] [ebp-410h]
  int i; // [esp+4h] [ebp-408h]
  char Buffer[1024]; // [esp+8h] [ebp-404h] BYREF

  CFsm::GenerateEvent(this->m_pFSM, 1030, 0);
  if ( !CGameType::IsWebGame(g_pGameType) || CGameType::IsSaveGame(g_pGameType) )
    return 0;
  for ( i = 0; g_pGameType->m_uiIPPlayer[i] != g_pGameType->m_iHostAddress; ++i )
    ;
  v6 = g_pGameType->m_sPlayerColor[i];
  v5 = g_pGameType->m_sPlayerRaces[i];
  v4 = g_pGameType->m_sPlayerPeerId[i];
  MultiPlayerGameID = CGameType::GetMultiPlayerGameID(g_pGameType);
  sprintf(
    Buffer,
    "{ ? = CALL proc_addtogame_playerclan( %d, %d, %d, 1, '%s', %d, '' ) }",
    MultiPlayerGameID,
    v4,
    v5,
    "Team",
    v6);
  return 0;
}


// address=[0x15bc560]
// Decompiled from char __thiscall CGameHost::InitGameStruct(CGameHost *this, void *Src)
bool  CGameHost::InitGameStruct(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  struct SLobbyPlayerData sPlayerData; // [esp+4h] [ebp-7Ch] BYREF

  if ( !this->dwordBC )
  {
    CTrace::Print("GameHost.cpp: Clearing client list...");
    while ( CClientList::GetSize(this->m_pClientList) )
      CClientList::RemoveClientAt(0);
  }
  if ( Src )
  {
    MessageLength = CGameHost::GetMessageLength(this);
    memcpy(&sPlayerData, Src, MessageLength);
    if ( sPlayerData.m_iFinal != 1
      && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3163, "data.m_iFinal == PLAYERDATA_FINAL") == 1 )
    {
      __debugbreak();
    }
    if ( sPlayerData.m_iFinal == 1 )
    {
      CGameHost::ProcessPlayerData(&sPlayerData);
      g_pGameType->m_iHumanPlayers = sPlayerData.m_iHumanPlayers;
      g_pGameType->m_iActualPlayerCount = sPlayerData.m_iPlayerCount;
      ++this->dwordBC;
    }
  }
  if ( this->dwordBC == g_pGameType->m_iActualPlayerCount )
    CFsm::GenerateEvent(this->m_pFSM, 1031, 0);
  return 1;
}


// address=[0x15bc680]
// Decompiled from char __thiscall CGameHost::ResendFinalPData(CGameHost *this, int a2)
bool  CGameHost::ResendFinalPData(void * a2) {
  
  if ( this->m_bIsOnlineGame )
  {
    CGameHost::SendPlayerData(this, 1);
    while ( CClientList::GetSize(this->m_pClientList) )
      CClientList::RemoveClientAt(0);
    if ( CClientList::GetSize(this->m_pClientList)
      && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3124, "!m_pClientList->GetSize()") == 1 )
    {
      __debugbreak();
    }
    CFsm::GenerateEvent(this->m_pFSM, 1012, 0);
  }
  else
  {
    CFsm::GenerateEvent(this->m_pFSM, 1013, 0);
  }
  return 1;
}


// address=[0x15bc720]
// Decompiled from char __thiscall CGameHost::ChatLine(CGameHost *this, void *Src)
bool  CGameHost::ChatLine(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  CGameHost::SChatLineMessage sMsg; // [esp+4h] [ebp-104h] BYREF

  MessageLength = CGameHost::GetMessageLength(this);
  memcpy(&sMsg, Src, MessageLength);
  if ( this->m_bHost )
    CGameHost::SendToAll(this, 1036, &sMsg, 0x100u, 0, 0, 1u);
  CLanLobby::PrintChatLine(sMsg.m_swpName, sMsg.m_swpChatLine);
  return 1;
}


// address=[0x15bc7c0]
// Decompiled from char __stdcall CGameHost::GameAlreadyFull(int a1)
bool  CGameHost::GameAlreadyFull(void * a1) {
  
  CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, (void *)0x96A);
  CGameStateHandler::Switch(CStateLobbyConnect::DynamicCreateFunc, 0);
  return 1;
}


// address=[0x15bc7f0]
// Decompiled from char __thiscall CGameHost::SendMapToClient(CGameHost *this, int _iClient)
bool  CGameHost::SendMapToClient(void * _iClient) {
  
  struct CEvn_Event *v4; // [esp+8h] [ebp-4E0h]
  uint iPeerId; // [esp+14h] [ebp-4D4h]
  unsigned int iIp; // [esp+18h] [ebp-4D0h] MAPDST
  struct CEvn_Event *v7; // [esp+1Ch] [ebp-4CCh]
  unsigned int iChunkOffset; // [esp+2Ch] [ebp-4BCh]
  int iSlot; // [esp+38h] [ebp-4B0h] MAPDST
  CGameHost::SMapMessage sMessage; // [esp+40h] [ebp-4A8h] BYREF
  CFile cMapFile; // [esp+444h] [ebp-A4h] BYREF
  CEvn_Event v14; // [esp+48Ch] [ebp-5Ch] BYREF
  CEvn_Event v15; // [esp+4A4h] [ebp-44h] BYREF
  std::wstring a1; // [esp+4BCh] [ebp-2Ch] BYREF
  int v17; // [esp+4E4h] [ebp-4h]

  if ( _iClient )
  {
    iIp = this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet);
    iSlot = CGameHost::GetSlot(this, iIp);
    if ( this->m_pMapUploadBuffer[iSlot] )
    {
      return 1;
    }
    else
    {
      this->m_pMapUploadBuffer[iSlot] = (char *)operator new[](g_pGameType->m_iFileSize);
      std::wstring::wstring(&a1, &g_pGameType->m_swMapName);
      v17 = 0;
      CFile::CFile(&cMapFile);
      LOBYTE(v17) = 1;
      CFile::Open(&cMapFile, &a1, CFile_BINARY|CFile_READ, UNUSED_ARG(), UNUSED_ARG());
      CFile::Read(&cMapFile, this->m_pMapUploadBuffer[iSlot], g_pGameType->m_iFileSize, 1u, UNUSED_ARG(), UNUSED_ARG());
      CFile::Close(&cMapFile, UNUSED_ARG(), UNUSED_ARG());
      if ( ++this->m_iMapUpload == 1 )
      {
        v7 = CEvn_Event::CEvn_Event(&v15, 80u, 1u, 0, 0);
        LOBYTE(v17) = 2;
        IEventEngine::SendAMessage(g_pEvnEngine, v7);
        LOBYTE(v17) = 1;
        CEvn_Event::~CEvn_Event(&v15);
      }
      if ( this->m_iMapUpload >= 7
        && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2749, "m_iMapUpload < MAX_PLAYER - 1") == 1 )
      {
        __debugbreak();
      }
      this->m_iMapUploadChunks[iSlot] = g_pGameType->m_iFileSize / 0x300u;
      if ( g_pGameType->m_iFileSize % 0x300u )
        ++this->m_iMapUploadChunks[iSlot];
      g_pGameType->m_sPlayerMapUploadStarted[iSlot] = 1;
      LOBYTE(v17) = 0;
      CFile::~CFile(&cMapFile);
      v17 = -1;
      std::wstring::~wstring(&a1);
      return 1;
    }
  }
  else
  {
    for ( iSlot = 0; iSlot < 8; ++iSlot )
    {
      if ( this->m_pMapUploadBuffer[iSlot] )
      {
        if ( g_pGameType->m_uiIPPlayer[iSlot] == this->m_pSimpleNet->GetCurrentLocalIPLong(this->m_pSimpleNet)
          && BBSupportDbgReport(
               2,
               "Net\\GameHost.cpp",
               2766,
               "g_pGameType->m_uiIPPlayer[ iSlot ] != m_pSimpleNet->GetCurrentLocalIPLong()") == 1 )
        {
          __debugbreak();
        }
        sMessage.m_iId = 1043;
        iIp = this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet);
        iPeerId = this->m_pSimpleNet->GetLastSenderPeerId(this->m_pSimpleNet);
        if ( this->m_iMapUploadSentChunks[iSlot] >= this->m_iMapUploadChunks[iSlot] )
        {
          if ( this->m_pMapUploadBuffer[iSlot] )
          {
            operator delete(this->m_pMapUploadBuffer[iSlot]);
            this->m_pMapUploadBuffer[iSlot] = 0;
          }
          this->m_iMapUploadSentChunks[iSlot] = 0;
          if ( !--this->m_iMapUpload )
          {
            v4 = CEvn_Event::CEvn_Event(&v14, 0x50u, 0, 0, 0);
            v17 = 3;
            IEventEngine::SendAMessage(g_pEvnEngine, v4);
            v17 = -1;
            CEvn_Event::~CEvn_Event(&v14);
          }
          if ( this->m_iMapUpload < 0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2804, "m_iMapUpload >= 0") == 1 )
            __debugbreak();
          g_pGameType->m_sPlayerMapUploadStarted[iSlot] = 0;
        }
        else
        {
          sMessage.m_iChunkId = this->m_iMapUploadSentChunks[iSlot];
          iChunkOffset = 0x300 * this->m_iMapUploadSentChunks[iSlot];
          if ( iChunkOffset + 0x300 <= g_pGameType->m_iFileSize )
            memcpy(sMessage.m_iMapData, &this->m_pMapUploadBuffer[iSlot][iChunkOffset], 0x300u);
          else
            memcpy(
              sMessage.m_iMapData,
              &this->m_pMapUploadBuffer[iSlot][iChunkOffset],
              g_pGameType->m_iFileSize - iChunkOffset);
          this->m_pSimpleNet->PushMessage(this->m_pSimpleNet, iPeerId, iIp, 3105, &sMessage, 774, 1, 1);
          CTrace::Print("GameHost.cpp: Map block sent. Block %d!", sMessage.m_iChunkId);
          ++this->m_iMapUploadSentChunks[iSlot];
        }
      }
    }
    return 1;
  }
}


// address=[0x15bce20]
// Decompiled from char __thiscall CGameHost::ClientReceiveMap(struct CGameHost *this, void *_pMessage)
bool  CGameHost::ClientReceiveMap(void * _pMessage) {
  
  unsigned __int16 MessageLength; // ax
  bool bIsWebGame; // si MAPDST
  unsigned __int16 v5; // ax
  std::wstring v7; // [esp-40h] [ebp-71Ch] BYREF
  BOOL v8; // [esp-24h] [ebp-700h]
  int m_iHostAddress; // [esp-20h] [ebp-6FCh]
  int v10; // [esp-1Ch] [ebp-6F8h]
  int v11; // [esp-18h] [ebp-6F4h]
  int v12; // [esp-14h] [ebp-6F0h]
  DWORD v13; // [esp-10h] [ebp-6ECh]
  int v14; // [esp-Ch] [ebp-6E8h]
  int __; // [esp-8h] [ebp-6E4h]
  int bIsLadder; // [esp-8h] [ebp-6E4h] SPLIT
  int bIsClan; // [esp-4h] [ebp-6E0h]
  void *v18; // [esp+8h] [ebp-6D4h]
  std::wstring *v19; // [esp+Ch] [ebp-6D0h]
  struct CEvn_Event *v20; // [esp+10h] [ebp-6CCh]
  struct CEvn_Event *v21; // [esp+14h] [ebp-6C8h]
  struct CEvn_Event *v22; // [esp+18h] [ebp-6C4h]
  struct CEvn_Event *v23; // [esp+1Ch] [ebp-6C0h]
  void *m_pMapDownloadData; // [esp+20h] [ebp-6BCh]
  void *C; // [esp+24h] [ebp-6B8h]
  size_t Size; // [esp+28h] [ebp-6B4h]
  CGameHost::SMapDownloadBlock pBlock; // [esp+30h] [ebp-6ACh] BYREF
  CGameHost::SMapDownloadBlock v29; // [esp+334h] [ebp-3A8h] BYREF
  CFile v30; // [esp+638h] [ebp-A4h] BYREF
  CEvn_Event v31; // [esp+680h] [ebp-5Ch] BYREF
  CEvn_Event v32; // [esp+698h] [ebp-44h] BYREF
  std::wstring swMapName; // [esp+6B0h] [ebp-2Ch] BYREF
  int v34; // [esp+6D8h] [ebp-4h]

  if ( this->m_bMapBeingDownloaded )
  {
    MessageLength = CGameHost::GetMessageLength(this);
    memcpy(&pBlock, _pMessage, MessageLength);  // MessageLength <= sizeof(CGameHost::SMapDownloadBlock)
    if ( !this->m_pMapDownloadBlocks[pBlock.m_iId] )
    {
      Size = pBlock.m_iId == this->m_iMapDownloadLastBlock - 1 ? g_pGameType->m_iFileSize % 768u : 768;
      memcpy(&this->m_pMapDownloadData[768 * pBlock.m_iId], pBlock.m_vData, Size);
      this->m_pMapDownloadBlocks[pBlock.m_iId] = 1;
      CTrace::Print(
        "GameHost.cpp: Map block arrived. Got block %d, count is %d/%d!",
        pBlock.m_iId,
        ++this->m_iMapDownloadBlocksArrived,
        this->m_iMapDownloadLastBlock);
      if ( this->m_iMapDownloadLastBlock == this->m_iMapDownloadBlocksArrived )
      {
        this->m_bMapBeingDownloaded = 0;
        std::wstring::wstring(&swMapName, &g_pGameType->m_swMapName);
        v34 = 0;
        CFile::CFile(&v30);
        LOBYTE(v34) = 1;
        CFile::Open(&v30, &swMapName, CFile_BINARY|CFile_WRITE, UNUSED_ARG(), UNUSED_ARG());
        bIsClan = 0;
        __ = (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h";
        CFile::Write(&v30, this->m_pMapDownloadData, g_pGameType->m_iFileSize, 1, UNUSED_ARG(), UNUSED_ARG());
        CFile::Close(&v30, UNUSED_ARG(), UNUSED_ARG());
        C = this->m_pMapDownloadBlocks;
        operator delete[](C);
        this->m_pMapDownloadBlocks = 0;
        m_pMapDownloadData = this->m_pMapDownloadData;
        operator delete[](m_pMapDownloadData);
        this->m_pMapDownloadData = 0;
        if ( CGameType::IsMapAvailable(g_pGameType, &g_pGameType->m_swMapName, g_pGameType->m_iMapCRC) )
        {
          v21 = CEvn_Event::CEvn_Event(&v31, 80u, 0, 0, 0);
          v20 = v21;
          LOBYTE(v34) = 3;
          IEventEngine::SendAMessage(g_pEvnEngine, v21);
          LOBYTE(v34) = 1;
          CEvn_Event::~CEvn_Event(&v31);
          CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, (void *)2416);// The host has a different map
          CGameStateHandler::Switch(CStateLobbyConnect::DynamicCreateFunc, 0);
        }
        else
        {
          bIsWebGame = CGameType::IsWebGame(g_pGameType);
          LOBYTE(bIsClan) = CGameType::IsClanGame(g_pGameType) & bIsWebGame;
          bIsClan = (unsigned __int8)bIsClan;
          bIsWebGame = CGameType::IsWebGame(g_pGameType);
          LOBYTE(bIsLadder) = CGameType::IsLadderGame(g_pGameType) & bIsWebGame;
          bIsLadder = (unsigned __int8)bIsLadder;
          v14 = -1;
          v13 = -1;
          v12 = 0;
          v11 = 1;
          v10 = 1;
          m_iHostAddress = g_pGameType->m_iHostAddress;
          v8 = 0;
          v19 = &v7;
          v18 = std::wstring::wstring(&v7, &g_pGameType->m_swMapName);
          CGameType::LoadMapData(g_pGameType, v7, v8, m_iHostAddress, v10, v11, v12, v13, v14, bIsLadder, bIsClan);
          CLanLobby::RedrawMap();
          v23 = CEvn_Event::CEvn_Event(&v32, 0x50u, 0, 0, 0);
          v22 = v23;
          LOBYTE(v34) = 2;
          IEventEngine::SendAMessage(g_pEvnEngine, v23);
          LOBYTE(v34) = 1;
          CEvn_Event::~CEvn_Event(&v32);
        }
        LOBYTE(v34) = 0;
        CFile::~CFile(&v30);
        v34 = -1;
        std::wstring::~wstring(&swMapName);
      }
    }
  }
  else
  {
    v5 = CGameHost::GetMessageLength(this);
    memcpy(&v29, _pMessage, v5);
    CTrace::Print("GameHost.cpp: Mapdata block %d without request got !!", v29.m_iId);
  }
  return 1;
}


// address=[0x15bd220]
// Decompiled from char __thiscall CGameHost::ClientLeavesMyGame(CGameHost *this, int a2)
bool  CGameHost::ClientLeavesMyGame(void * a2) {
  
  int v3; // [esp+0h] [ebp-8h]

  v3 = this->m_pSimpleNet->GetLastSenderPeerId(this->m_pSimpleNet);
  CLanLobby::DisconnectPlayerPeerId(v3, -1);
  if ( !CClientList::RemoveClientPeerId(this->m_pClientList, v3) )
    CTrace::Print("GameHost.cpp: Unable to removed client!");
  CLanLobby::RedrawPlayerList();
  return 1;
}


// address=[0x15bd290]
// Decompiled from char __thiscall CGameHost::PerformLeaveGame(void *this, int a2)
bool  CGameHost::PerformLeaveGame(void * a2) {
  
  void *Instance; // eax

  Instance = (void *)OnlineManager::GetInstance();
  OnlineManager::LeaveSession(Instance);
  return 1;
}


// address=[0x15bd2b0]
// Decompiled from char __thiscall CGameHost::SendChatLine(CGameHost *this, wchar_t *pChatLine)
bool  CGameHost::SendChatLine(void * pChatLine) {
  
  wchar_t *v2; // eax
  wchar_t *v3; // eax
  std::wstring *v5; // [esp+4h] [ebp-15Ch]
  std::wstring *PlayerName; // [esp+Ch] [ebp-154h]
  CGameHost::SChatLineMessage Src; // [esp+18h] [ebp-148h] BYREF
  std::wstring v9; // [esp+118h] [ebp-48h] BYREF
  std::wstring v10; // [esp+134h] [ebp-2Ch] BYREF
  int v11; // [esp+15Ch] [ebp-4h]

  memset(&Src, 0, sizeof(Src));
  MyWStrNCopy(Src.m_swpChatLine, pChatLine, 192u);
  PlayerName = (std::wstring *)CGameSettings::GetPlayerName((int)&v10);
  v11 = 0;
  v2 = std::wstring::c_str(PlayerName);
  MyWStrNCopy(Src.m_swpName, v2, 64u);
  v11 = -1;
  std::wstring::~wstring(&v10);
  if ( this->m_bHost )
  {
    CGameHost::SendToAll(this, 1036, &Src, 256u, 0, 0, 1u);
    v5 = (std::wstring *)CGameSettings::GetPlayerName((int)&v9);
    v11 = 1;
    v3 = std::wstring::c_str(v5);
    CLanLobby::PrintChatLine(v3, pChatLine);
    v11 = -1;
    std::wstring::~wstring(&v9);
  }
  else
  {
    CGameHost::SendToHost(1036, &Src, 256u, 0, 0, 1);
  }
  return 1;
}


// address=[0x15bd420]
// Decompiled from char __thiscall CGameHost::UserDataChange(CGameHost *this, CGameHost::SChangeMessage *a2)
bool  CGameHost::UserDataChange(void * a2) {
  
  int v4; // [esp+8h] [ebp-14h]
  DWORD v5; // [esp+Ch] [ebp-10h]
  int i; // [esp+14h] [ebp-8h]

  switch ( a2->m_iType )
  {
    case 0:
      do
      {
        if ( a2->m_iTarget == 6 )
        {
          if ( --g_pGameType->m_sPlayerColor[a2->m_iSlot] == -1 )
            g_pGameType->m_sPlayerColor[a2->m_iSlot] = 7;
        }
        else if ( ++g_pGameType->m_sPlayerColor[a2->m_iSlot] == 8 )
        {
          g_pGameType->m_sPlayerColor[a2->m_iSlot] = 0;
        }
      }
      while ( !CGameHost::IsExclusiveColor(this, a2->m_iSlot) );
      break;
    case 1:
      if ( g_pGameType->m_bDarkTribe[a2->m_iSlot] )
      {
        if ( a2->m_iTarget == 6 )
        {
          if ( g_pGameType->m_sPlayerRaces[a2->m_iSlot] )
            --g_pGameType->m_sPlayerRaces[a2->m_iSlot];
          else
            g_pGameType->m_sPlayerRaces[a2->m_iSlot] = 5;
          while ( g_pGameType->m_sPlayerRaces[a2->m_iSlot] == 3
               || g_pGameType->m_sPlayerRaces[a2->m_iSlot] == 4 && (g_uiExtrasAllowed & 1) == 0 )
            --g_pGameType->m_sPlayerRaces[a2->m_iSlot];
        }
        else
        {
          if ( g_pGameType->m_sPlayerRaces[a2->m_iSlot] == 5 )
            g_pGameType->m_sPlayerRaces[a2->m_iSlot] = 0;
          else
            ++g_pGameType->m_sPlayerRaces[a2->m_iSlot];
          while ( g_pGameType->m_sPlayerRaces[a2->m_iSlot] == 3
               || g_pGameType->m_sPlayerRaces[a2->m_iSlot] == 4 && (g_uiExtrasAllowed & 1) == 0 )
          {
            if ( ++g_pGameType->m_sPlayerRaces[a2->m_iSlot] == 6 )
              g_pGameType->m_sPlayerRaces[a2->m_iSlot] = 0;
          }
        }
      }
      break;
    case 2:
      if ( a2->m_iTarget == 6 )
      {
        if ( --g_pGameType->m_sPlayerTeam[a2->m_iSlot] == -1 )
          g_pGameType->m_sPlayerTeam[a2->m_iSlot] = g_pGameType->m_uiNumberAlliances - 1;
      }
      else if ( a2->m_iTarget == 7 && ++g_pGameType->m_sPlayerTeam[a2->m_iSlot] == g_pGameType->m_uiNumberAlliances )
      {
        g_pGameType->m_sPlayerTeam[a2->m_iSlot] = 0;
      }
      break;
    case 4:
      if ( a2->m_iTarget == 6 )
      {
        if ( --g_pGameType->m_sPlayerSlot8[a2->m_iSlot] == -1 )
          g_pGameType->m_sPlayerSlot8[a2->m_iSlot] = 7;
      }
      else if ( ++g_pGameType->m_sPlayerSlot8[a2->m_iSlot] == 8 )
      {
        g_pGameType->m_sPlayerSlot8[a2->m_iSlot] = 0;
      }
      break;
    case 5:
      if ( a2->m_iTarget )
        v5 = 6;
      else
        v5 = 0;
      g_pGameType->m_sPlayerMapUploadStarted[a2->m_iSlot] = v5;
      break;
    case 9:
      v4 = 0;
      for ( i = 0; i < 8; ++i )
      {
        if ( g_pGameType->m_sPlayerSlot15[i] == a2->m_iSlot )
          v4 = i;
      }
      if ( a2->m_iSlot == a2->m_iTarget )
      {
        g_pGameType->m_sPlayerSlot15[v4] = -1;
        g_pGameType->m_sPlayerSlot15[a2->m_iSlot] = -1;
      }
      else
      {
        g_pGameType->m_sPlayerSlot15[a2->m_iSlot] = a2->m_iTarget;
      }
      break;
    default:
      CTrace::Print("GameHost: Invalid Change Type %d from Slot %d!", a2->m_iType, a2->m_iSlot);
      break;
  }
  CLanLobby::RedrawPlayerList();
  return 1;
}


// address=[0x15bd980]
// Decompiled from char __thiscall CGameHost::KickClient(CGameHost *this, int a2)
bool  CGameHost::KickClient(void * a2) {
  
  DWORD v4; // [esp+4h] [ebp-Ch]
  __int16 v5; // [esp+Ch] [ebp-4h] BYREF

  v4 = g_pGameType->m_sPlayerPeerId[a2];
  CLanLobby::DisconnectPlayerPeerId(v4, -1);
  CClientList::RemoveClientPeerId(this->m_pClientList, v4);
  g_pGameType->m_bPlayerSlotEmpty[a2] = 1;
  v5 = 1053;
  this->m_pSimpleNet->PushMessage(this->m_pSimpleNet, v4, g_pGameType->m_uiIPPlayer[a2], 3105, &v5, 2, 0, 1);
  CLanLobby::RedrawPlayerList();
  return 1;
}


// address=[0x15bda30]
// Decompiled from char __thiscall CGameHost::WereKicked(CGameHost *this, int a2)
bool  CGameHost::WereKicked(void * a2) {
  
  void *Instance; // eax

  Instance = (void *)OnlineManager::GetInstance();
  OnlineManager::LeaveSession(Instance);
  CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, (void *)0x9BE);
  CGameStateHandler::Switch(CStateLobbyConnect::DynamicCreateFunc, 0);
  return 1;
}


// address=[0x15bda70]
// Decompiled from char __thiscall CGameHost::UserChangeSlots(CGameHost *this, CGameHost::SChangeMessage *a2)
bool  CGameHost::UserChangeSlots(void * a2) {
  
  std::wstring *RealPlayerName; // eax
  std::wstring *v3; // eax
  DWORD iAckDelta; // [esp+Ch] [ebp-94h]
  DWORD iMapUpload; // [esp+10h] [ebp-90h]
  DWORD iColor; // [esp+14h] [ebp-8Ch]
  DWORD iPeerId; // [esp+18h] [ebp-88h]
  DWORD iIP; // [esp+1Ch] [ebp-84h]
  DWORD iType; // [esp+20h] [ebp-80h]
  std::wstring *PlayerClanShortcut; // [esp+24h] [ebp-7Ch]
  BYTE iEmptySlot; // [esp+32h] [ebp-6Eh]
  BYTE iExclusiveColor; // [esp+33h] [ebp-6Dh]
  int iTarget; // [esp+34h] [ebp-6Ch]
  int iSlot; // [esp+38h] [ebp-68h]
  std::wstring v16; // [esp+3Ch] [ebp-64h] BYREF
  std::wstring v17; // [esp+58h] [ebp-48h] BYREF
  std::wstring v18; // [esp+74h] [ebp-2Ch] BYREF
  int v19; // [esp+9Ch] [ebp-4h]

  iSlot = a2->m_iSlot;
  iTarget = a2->m_iTarget;
  if ( a2->m_iSlot >= 0 && iTarget >= 0 )
  {
    if ( iTarget == CGameType::GetLocalSlot(g_pGameType) )
      CGameType::ChangeLocalSlot(g_pGameType, iSlot);
    if ( iSlot == CGameType::GetLocalSlot(g_pGameType) )
      CGameType::ChangeLocalSlot(g_pGameType, iTarget);
    iType = g_pGameType->m_sPlayerType[iSlot];
    iIP = g_pGameType->m_uiIPPlayer[iSlot];
    iPeerId = g_pGameType->m_sPlayerPeerId[iSlot];
    iColor = g_pGameType->m_sPlayerColor[iSlot];
    iExclusiveColor = g_pGameType->m_sPlayerExclusiveColor[iSlot];
    iMapUpload = g_pGameType->m_sPlayerMapUploadStarted[iSlot];
    iAckDelta = g_pGameType->m_sPlayerAckDelta[iSlot];
    iEmptySlot = g_pGameType->m_bPlayerSlotEmpty[iSlot];
    RealPlayerName = CGameType::GetRealPlayerName(g_pGameType, iSlot);
    std::wstring::wstring(&v17, RealPlayerName);
    v19 = 0;
    CGameType::GetPlayerClanShortcut(g_pGameType, &v18, iSlot);
    LOBYTE(v19) = 1;
    g_pGameType->m_sPlayerType[iSlot] = g_pGameType->m_sPlayerType[iTarget];
    g_pGameType->m_uiIPPlayer[iSlot] = g_pGameType->m_uiIPPlayer[iTarget];
    g_pGameType->m_sPlayerPeerId[iSlot] = g_pGameType->m_sPlayerPeerId[iTarget];
    g_pGameType->m_sPlayerColor[iSlot] = g_pGameType->m_sPlayerColor[iTarget];
    g_pGameType->m_sPlayerExclusiveColor[iSlot] = g_pGameType->m_sPlayerExclusiveColor[iTarget];
    g_pGameType->m_sPlayerMapUploadStarted[iSlot] = g_pGameType->m_sPlayerMapUploadStarted[iTarget];
    g_pGameType->m_sPlayerAckDelta[iSlot] = g_pGameType->m_sPlayerAckDelta[iTarget];
    g_pGameType->m_bPlayerSlotEmpty[iSlot] = g_pGameType->m_bPlayerSlotEmpty[iTarget];
    g_pGameType->m_sPlayerSlot15[iSlot] = -1;
    v3 = CGameType::GetRealPlayerName(g_pGameType, iTarget);
    CGameType::SetPlayerName(g_pGameType, iSlot, v3);
    PlayerClanShortcut = CGameType::GetPlayerClanShortcut(g_pGameType, &v16, iTarget);
    LOBYTE(v19) = 2;
    CGameType::SetPlayerClanShortcut(g_pGameType, iSlot, PlayerClanShortcut);
    LOBYTE(v19) = 1;
    std::wstring::~wstring(&v16);
    g_pGameType->m_sPlayerType[iTarget] = iType;
    g_pGameType->m_uiIPPlayer[iTarget] = iIP;
    g_pGameType->m_sPlayerPeerId[iTarget] = iPeerId;
    g_pGameType->m_sPlayerColor[iTarget] = iColor;
    g_pGameType->m_sPlayerExclusiveColor[iTarget] = iExclusiveColor;
    g_pGameType->m_sPlayerMapUploadStarted[iTarget] = iMapUpload;
    g_pGameType->m_sPlayerAckDelta[iTarget] = iAckDelta;
    g_pGameType->m_bPlayerSlotEmpty[iTarget] = iEmptySlot;
    g_pGameType->m_sPlayerSlot15[iTarget] = -1;
    CGameType::SetPlayerName(g_pGameType, iTarget, &v17);
    CGameType::SetPlayerClanShortcut(g_pGameType, iTarget, &v18);
    LOBYTE(v19) = 0;
    std::wstring::~wstring(&v18);
    v19 = -1;
    std::wstring::~wstring(&v17);
  }
  CLanLobby::RedrawPlayerList();
  return 1;
}


// address=[0x15bde60]
// Decompiled from char __thiscall CGameHost::InitHostAfterLobby(CGameHost *this, int a2)
bool  CGameHost::InitHostAfterLobby(void * a2) {
  
  this->m_bHost = 1;
  CFsm::GenerateEvent(this->m_pFSM, 1009, 0);
  return 1;
}


// address=[0x15bde90]
// Decompiled from char __thiscall CGameHost::InitClientAfterLobby(CGameHost *this, int a2)
bool  CGameHost::InitClientAfterLobby(void * a2) {
  
  this->m_bClient = 1;
  CFsm::GenerateEvent(this->m_pFSM, 1010, 0);
  return 1;
}


// address=[0x15bdec0]
// Decompiled from char __thiscall CGameHost::WaitingForGameConnect(CGameHost *this, void *Src)
bool  CGameHost::WaitingForGameConnect(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  int v3; // eax
  uint v4; // eax
  int MultiPlayerGameID; // eax
  int Size; // esi
  DWORD v8; // [esp-10h] [ebp-49Ch]
  int v9; // [esp-Ch] [ebp-498h]
  DWORD v10; // [esp-4h] [ebp-490h]
  int v11; // [esp+0h] [ebp-48Ch]
  int v12; // [esp+4h] [ebp-488h]
  uint iLastSenderPeerId_1; // [esp+8h] [ebp-484h]
  int iLastSenderPeerId; // [esp+8h] [ebp-484h]
  unsigned int i; // [esp+Ch] [ebp-480h]
  char v16; // [esp+10h] [ebp-47Ch]
  int j; // [esp+10h] [ebp-47Ch]
  char v18; // [esp+17h] [ebp-475h]
  CGameHost::SJoinMessage sMsg; // [esp+20h] [ebp-46Ch] BYREF
  char Buffer[1024]; // [esp+88h] [ebp-404h] BYREF

  if ( this->m_bIsOnlineGame )
  {
    if ( Src )
    {
      iLastSenderPeerId_1 = this->m_pSimpleNet->GetLastSenderPeerId(this->m_pSimpleNet);
      MessageLength = CGameHost::GetMessageLength(this);
      memcpy(&sMsg, Src, MessageLength);
      if ( sMsg.m_iVersionConfig != g_iConfigVersion )
        CTrace::Print("GameHost: Config files CRC mismatch!");
      if ( sMsg.m_iVersionScript != g_iScriptVersion )
        CTrace::Print("GameHost: Script files CRC mismatch!");
      if ( sMsg.m_iVersionGfx != g_iGfxVersion )
        CTrace::Print("GameHost: Gfx index files CRC mismatch!");
      if ( CClientList::ContainsPeerId(this->m_pClientList, iLastSenderPeerId_1) )
      {
        CTrace::Print("CGameHost: RegConnect for Peer already got !!");
      }
      else
      {
        v18 = 0;
        for ( i = 0; i < g_pGameType->m_iActualPlayerCount; ++i )
        {
          if ( g_pGameType->m_sPlayerPeerId[i] == iLastSenderPeerId_1 )
          {
            v18 = 1;
            break;
          }
        }
        if ( v18 )
        {
          v3 = this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet);
          CClientList::Add(this->m_pClientList, v3, v11, v12);// v3, i, iLastSenderPeerId
          v4 = this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet);
          this->m_pSimpleNet->PushMessage(
            this->m_pSimpleNet,
            iLastSenderPeerId_1,
            v4,
            1u,                                 // 0xc21
            (void *)1,                          // 0x409
            iLastSenderPeerId_1,                // 2
            i,                                  // 1
            v16);                               // 1
          for ( j = 0; j < 9 && g_pGameType->m_sPlayerPeerId[j] != iLastSenderPeerId; ++j )
            ;
          if ( j == 8 )
            j = 0;
          v10 = g_pGameType->m_sPlayerColor[j];
          v9 = g_pGameType->m_sPlayerRaces[j];
          v8 = g_pGameType->m_sPlayerPeerId[j];
          MultiPlayerGameID = CGameType::GetMultiPlayerGameID(g_pGameType);
          sprintf(
            Buffer,
            "{ ? = CALL proc_addtogame_playerclan( %d, %d, %d, 0, '%s', %d, '' ) }",
            MultiPlayerGameID,
            v8,
            v9,
            "Team",
            v10);
        }
      }
      Size = CClientList::GetSize(this->m_pClientList);
      if ( Size == CGameType::HumanPlayers(g_pGameType) - 1 )
        CFsm::GenerateEvent(this->m_pFSM, 1014, 0);
    }
  }
  else
  {
    CFsm::GenerateEvent(this->m_pFSM, 1014, 0);
  }
  return 1;
}


// address=[0x15be220]
// Decompiled from char __thiscall CGameHost::HostInitGame(CGameHost *this, void *a2)
bool  CGameHost::HostInitGame(void * a2) {
  
  CMsgStacks *v3; // [esp+8h] [ebp-40h]
  CMsgStacks *C; // [esp+Ch] [ebp-3Ch]
  int i; // [esp+10h] [ebp-38h]
  unsigned int j; // [esp+18h] [ebp-30h]
  CEvn_Event v8; // [esp+20h] [ebp-28h] BYREF
  int v9; // [esp+44h] [ebp-4h]

  if ( this->m_bIsOnlineGame )
  {
    for ( i = 0; i < CClientList::GetSize(this->m_pClientList); ++i )
      CGameHost::SendToAll(this, 1017, 0, 0, 0, 0, 1u);
  }
  C = (CMsgStacks *)operator new(0x65Cu);
  v9 = 0;
  if ( C )
    v3 = CMsgStacks::CMsgStacks(
           C,
           g_pGameType->m_iActualPlayerCount,
           g_pGameType->m_iNetworkTimeDelta / 0x47u,
           g_pGameType->m_uiTickCounter);
  else
    v3 = 0;
  v9 = -1;
  this->m_pMsgStacks = v3;
  for ( j = 0; j < g_pGameType->m_iActualPlayerCount; ++j )
  {
    if ( g_pGameType->m_sPlayerType[j] == 2 || g_pGameType->m_sPlayerType[j] == 3 )
      CMsgStacks::SetStackAI(j, 1);
  }
  CEvn_Event::CEvn_Event(&v8, 0x18u, (unsigned int)&g_pGameType, 0, 0);
  v9 = 1;
  IEventEngine::SendAMessage(g_pEvnEngine, &v8);
  v9 = -1;
  CEvn_Event::~CEvn_Event(&v8);
  return 1;
}


// address=[0x15be3c0]
// Decompiled from char __thiscall CGameHost::HostStartTick(CGameHost *this, int a2)
bool  CGameHost::HostStartTick(void * a2) {
  
  CEvn_Event v3; // [esp+Ch] [ebp-28h] BYREF
  int v4; // [esp+30h] [ebp-4h]

  this->m_pSimpleNet->RemoveAllResendMsgs(this->m_pSimpleNet);
  CEvn_Event::CEvn_Event(&v3, 0x19u, 0, 0, 0);
  v4 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v3);
  v4 = -1;
  CEvn_Event::~CEvn_Event(&v3);
  return 1;
}


// address=[0x15be460]
// Decompiled from char __thiscall CGameHost::RegClientConnect(CGameHost *this, int a2)
bool  CGameHost::RegClientConnect(void * a2) {
  
  int Instance; // eax
  wchar_t *v3; // eax
  int v5; // eax
  const char *v6; // eax
  int m_iHostAddress; // [esp+0h] [ebp-98h]
  std::wstring *PlayerName; // [esp+4h] [ebp-94h]
  int i; // [esp+Ch] [ebp-8Ch]
  int j; // [esp+Ch] [ebp-8Ch]
  std::wstring v12; // [esp+10h] [ebp-88h] BYREF
  CGameHost::SJoinMessage Destination; // [esp+2Ch] [ebp-6Ch] BYREF

  if ( a2 == 1 )
  {
    Destination.m_bU0 = 1;
    Instance = StormManager::GetInstance();
    Destination.m_iPeerId = StormManager::GetLocalPeerId(Instance);
    Destination.m_iVersionMS = g_iFileVersionMS;
    Destination.m_iVersionLS = g_iFileVersionLS;
    Destination.m_iVersionConfig = g_iConfigVersion;
    Destination.m_iVersionScript = g_iScriptVersion;
    Destination.m_iVersionGfx = g_iGfxVersion;
    Destination.m_bIsWebGame = CGameType::IsWebGame(g_pGameType);
    PlayerName = (std::wstring *)CGameSettings::GetPlayerName((int)&v12);
    v3 = std::wstring::c_str(PlayerName);
    wcsncpy(Destination.m_swPlayerName, v3, 31u);
    std::wstring::~wstring(&v12);
    Destination.field_3E = 0;
    CGameHost::SendToHost(1013, &Destination, 0x65u, 0, 0, 1);
    return 1;
  }
  else
  {
    m_iHostAddress = g_pGameType->m_iHostAddress;
    if ( this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet) )
    {
      g_pGameType->m_iHostAddress = this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet);
      for ( i = 0; i < 9; ++i )
      {
        if ( g_pGameType->m_uiIPPlayer[i] == m_iHostAddress )
          g_pGameType->m_uiIPPlayer[i] = this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet);
      }
    }
    if ( CClientList::GetSize(this->m_pClientList)
      && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4254, "m_pClientList->GetSize() == 0") == 1 )
    {
      __debugbreak();
    }
    CTrace::Print("GameHost.cpp: Filling client list !!");
    for ( j = 0; j < 9; ++j )
    {
      if ( g_pGameType->m_sPlayerPeerId[j] != -1 )
      {
        v5 = StormManager::GetInstance();
        if ( g_pGameType->m_sPlayerPeerId[j] != StormManager::GetLocalPeerId(v5) )
        {
          CClientList::Add(this->m_pClientList, g_pGameType->m_uiIPPlayer[j], j, g_pGameType->m_sPlayerPeerId[j]);
          v6 = this->m_pSimpleNet->GetIPString(this->m_pSimpleNet, g_pGameType->m_uiIPPlayer[j]);
          CTrace::Print("GameHost.cpp: Adding client %s to list !", v6);
        }
      }
    }
    return 1;
  }
}


// address=[0x15be750]
// Decompiled from char __stdcall CGameHost::WereConnectedForGame(int a1)
bool  CGameHost::WereConnectedForGame(void * a1) {
  
  return 1;
}


// address=[0x15be760]
// Decompiled from char __thiscall CGameHost::ClientStartingGame(CGameHost *this, int a2)
bool  CGameHost::ClientStartingGame(void * a2) {
  
  CMsgStacks *v4; // [esp+Ch] [ebp-38h]
  CMsgStacks *C; // [esp+10h] [ebp-34h]
  unsigned int i; // [esp+14h] [ebp-30h]
  CEvn_Event v7; // [esp+1Ch] [ebp-28h] BYREF
  int v8; // [esp+40h] [ebp-4h]

  C = (CMsgStacks *)operator new(1628u);
  v8 = 0;
  if ( C )
    v4 = CMsgStacks::CMsgStacks(
           C,
           g_pGameType->m_iActualPlayerCount,
           g_pGameType->m_iNetworkTimeDelta / 0x47u,
           g_pGameType->m_uiTickCounter);
  else
    v4 = 0;
  v8 = -1;
  this->m_pMsgStacks = v4;
  for ( i = 0; i < g_pGameType->m_iActualPlayerCount; ++i )
  {
    if ( g_pGameType->m_sPlayerType[i] == 2 || g_pGameType->m_sPlayerType[i] == 3 )
      CMsgStacks::SetStackAI(i, 1);
  }
  CEvn_Event::CEvn_Event(&v7, 0x18u, (unsigned int)&g_pGameType, 0, 0);
  v8 = 1;
  IEventEngine::SendAMessage(g_pEvnEngine, &v7);
  v8 = -1;
  CEvn_Event::~CEvn_Event(&v7);
  return 1;
}


// address=[0x15be8b0]
// Decompiled from char __stdcall CGameHost::ClientGameInited(int a1)
bool  CGameHost::ClientGameInited(void * a1) {
  
  CGameHost::SendToHost(1018, 0, 0, 0, 0, 1);
  return 1;
}


// address=[0x15be8e0]
// Decompiled from char __thiscall CGameHost::ClientStartTick(CGameHost *this, int a2)
bool  CGameHost::ClientStartTick(void * a2) {
  
  CEvn_Event v3; // [esp+Ch] [ebp-28h] BYREF
  int v4; // [esp+30h] [ebp-4h]

  this->m_pSimpleNet->RemoveAllResendMsgs(this->m_pSimpleNet);
  CEvn_Event::CEvn_Event(&v3, 0x19u, 0, 0, 0);
  v4 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v3);
  v4 = -1;
  CEvn_Event::~CEvn_Event(&v3);
  return 1;
}


// address=[0x15be980]
// Decompiled from char __thiscall CGameHost::HostGameInited(CGameHost *this, int a2)
bool  CGameHost::HostGameInited(void * a2) {
  
  int v2; // eax
  unsigned int v4; // [esp+4h] [ebp-10h]
  unsigned int i; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]
  unsigned int v7; // [esp+Ch] [ebp-8h]

  if ( !this->m_iInitTime )
    this->m_iInitTime = timeGetTime();
  if ( a2 )
  {
    v2 = this->m_pSimpleNet->GetLastSenderPeerId(this->m_pSimpleNet);
    CClientList::SetClientReadyFromPeerId(this->m_pClientList, v2, 1);
  }
  else
  {
    this->m_bInitFinished = 1;
    CTrace::Print("CGameHost.cpp: Game init finished!");
  }
  if ( CClientList::AllClientsReady(this->m_pClientList) )
  {
    if ( this->m_bInitFinished )
    {
      CTrace::Print("CGameHost.cpp: Everyone's finished with game init... Now start 1st tick!");
      CGameHost::SendToAll(this, 1019, 0, 0, 0, 0, 1u);
      v6 = 0;
      v4 = 0;
      for ( i = 0; i < g_pGameType->m_iActualPlayerCount; ++i )
      {
        if ( g_pGameType->m_sPlayerType[i] == 1 )
        {
          v4 += g_pGameType->m_sPlayerAckDelta[i];
          ++v6;
        }
      }
      v7 = v6 - 1;
      if ( v7 )
        CTrace::Print("GameHost.cpp: Sleeping for %d ms to get in semi sync state!", v4 / v7);
      CFsm::GenerateEvent(this->m_pFSM, 1015, 0);
    }
    else
    {
      CTrace::Print("CGameHost.cpp: Everyone's but host (me) finished with game init... !");
    }
    return 1;
  }
  else
  {
    CTrace::Print("CGameHost.cpp: Not all clients finished with game init... !");
    return 1;
  }
}


// address=[0x15beaf0]
// Decompiled from char __thiscall CGameHost::GameSyncMsgGot(CGameHost *this, CGameHost::SSyncMessage *a2)
bool  CGameHost::GameSyncMsgGot(void * a2) {
  
  unsigned int v2; // esi
  int m_iCurrentTick; // edi

  CMsgStacks::SetNumberOfExpectedMsgs(
    this->m_pMsgStacks,
    a2->m_iCurrentTick,
    (a2->m_iSyncData >> 4) & 0xF,
    a2->m_iSyncData & 0xF);
  v2 = (a2->m_iSyncData >> 4) & 0xF;
  m_iCurrentTick = a2->m_iCurrentTick;
  this->m_iSyncA[v2] += m_iCurrentTick - CGameHost::GetValidTick(this);
  ++this->m_iSyncB[(a2->m_iSyncData >> 4) & 0xF];
  return 1;
}


// address=[0x15beba0]
// Decompiled from char __thiscall CGameHost::GameSync0MsgGot(CGameHost *this, CGameHost::SSync0Message *a2)
bool  CGameHost::GameSync0MsgGot(void * a2) {
  
  int m_iPlayerId; // esi
  int m_iCurrentTick; // edi

  if ( CMsgStacks::IsSizeAlreadySet(&this->m_pMsgStacks->__vftable, a2->m_iCurrentTick, a2->m_iPlayerId - 1) )
    return 1;
  CMsgStacks::SetNumberOfExpectedMsgs(this->m_pMsgStacks, a2->m_iCurrentTick, a2->m_iPlayerId - 1, 0);
  m_iPlayerId = (unsigned __int8)a2->m_iPlayerId;
  m_iCurrentTick = a2->m_iCurrentTick;
  *((_DWORD *)&this->m_pSimpleNet + m_iPlayerId) += m_iCurrentTick - CGameHost::GetValidTick(this);
  ++this->m_iSyncA[(unsigned __int8)a2->m_iPlayerId + 7];
  return 1;
}


// address=[0x15bec60]
// Decompiled from char __thiscall CGameHost::GameInGameMsgGot(CGameHost *this, void *Src)
bool  CGameHost::GameInGameMsgGot(void * Src) {
  
  unsigned __int16 MessageLength; // ax

  MessageLength = CGameHost::GetMessageLength(this);
  memcpy(&s_sInGameMsg, Src, MessageLength);
  if ( s_sInGameMsg.m_iData )
  {
    if ( s_sInGameMsg.m_iDataSize >= 0x400u
      && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4470, "pEvent->m_iDataSize < MSG_BUFFER_SIZE") == 1 )
    {
      __debugbreak();
    }
    s_sInGameMsg.m_iData = (BYTE *)operator new[](s_sInGameMsg.m_iDataSize);
    memcpy(s_sInGameMsg.m_iData, &unk_415ADB8, s_sInGameMsg.m_iDataSize);
  }
  if ( !CMsgStacks::IsInStack(this->m_pMsgStacks, &s_sInGameMsg)
    || CMsgStacks::IsStackAI(this->m_pMsgStacks, s_sInGameMsg.m_iOwner - 1) )
  {
    CMsgStacks::PushMsg(this->m_pMsgStacks, &s_sInGameMsg);
  }
  return 1;
}


// address=[0x15bed50]
// Decompiled from char __thiscall CGameHost::GameAsyncMsgGot(CGameHost *this, void *Src)
bool  CGameHost::GameAsyncMsgGot(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  CEvn_Logic v4; // [esp+10h] [ebp-30h] BYREF
  int v5; // [esp+3Ch] [ebp-4h]

  MessageLength = CGameHost::GetMessageLength(this);
  memcpy(&s_sAsyncMsg, Src, MessageLength);
  if ( s_sAsyncMsg.m_iData )
  {
    if ( s_sAsyncMsg.m_iDataSize >= 0x400u
      && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4556, "pEvent->m_iDataSize < MSG_BUFFER_SIZE") == 1 )
    {
      __debugbreak();
    }
    s_sAsyncMsg.m_iData = (BYTE *)s_sAsyncMsgBuffer;
  }
  CEvn_Logic::CEvn_Logic(
    &v4,
    s_sAsyncMsg.m_iEventId,
    s_sAsyncMsg.m_wParam,
    s_sAsyncMsg.m_lParam,
    s_sAsyncMsg.m_iOwner,
    (uint)s_sAsyncMsg.m_iData,
    s_sAsyncMsg.m_iDataSize);
  v5 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v4);
  v5 = -1;
  CEvn_Logic::~CEvn_Logic(&v4);
  return 1;
}


// address=[0x15bee60]
// Decompiled from char __thiscall CGameHost::AmIStillAlive(CGameHost *this, int a2)
bool  CGameHost::AmIStillAlive(void * a2) {
  
  uint v2; // eax
  uint Src; // [esp+0h] [ebp-410h] BYREF
  CGameHost::SSimpleMessage v6; // [esp+8h] [ebp-408h] OVERLAPPED BYREF
  char v7; // [esp+10h] [ebp-400h]
  char v8; // [esp+14h] [ebp-3FCh]

  v6.m_iId = 1041;
  Src = CPlayerManager::GetLocalPlayerId() - 1;
  memcpy(&v6.m_iTick, &Src, sizeof(v6.m_iTick));
  this->m_pSimpleNet->GetLastSenderIP(this->m_pSimpleNet);
  v2 = this->m_pSimpleNet->GetLastSenderPeerId(this->m_pSimpleNet);
  this->m_pSimpleNet->PushMessage(
    this->m_pSimpleNet,
    v2,
    Src,
    (u_short)this,
    *(void **)&v6.m_iId,
    *(size_t *)((char *)&v6.m_iTick + 2),
    v7,
    v8);                                        // peer, ip, c21h, v6, 6, 0, 1
  return 1;
}


// address=[0x15bef30]
// Decompiled from char __thiscall CGameHost::HeIsStillAlive(CGameHost *this, char *a2)
bool  CGameHost::HeIsStillAlive(void * a2) {
  
  DWORD Time; // eax

  Time = timeGetTime();
  CMsgStacks::SetLastMsgTime(this->m_pMsgStacks, *a2, Time, 1);
  return 1;
}


// address=[0x15bef60]
// Decompiled from char __thiscall CGameHost::GameInGamePackedGot(CGameHost *this, CGameHost::SMessageBuffer *a2)
bool  CGameHost::GameInGamePackedGot(void * a2) {
  
  int iPackCount; // [esp+4h] [ebp-1Ch]
  uint m_uTick; // [esp+8h] [ebp-18h]
  char *pPackedBuffer; // [esp+10h] [ebp-10h]
  int v6; // [esp+14h] [ebp-Ch]
  struct CNet_Event *v8; // [esp+1Ch] [ebp-4h]

  v6 = (a2->m_uPlayerMap & 0xF) + 1;
  m_uTick = a2->m_uTick;
  iPackCount = a2->m_uFlags & 0xF;
  pPackedBuffer = a2->m_vMessages;
  if ( (unsigned __int8)CMsgStacks::IsSizeAlreadySet(m_uTick, a2->m_uPlayerMap & 0xF) )
    return 1;
  CMsgStacks::SetNumberOfExpectedMsgs(this->m_pMsgStacks, m_uTick, v6 - 1, iPackCount);
  *((_DWORD *)&this->m_pSimpleNet + v6) += m_uTick - CGameHost::GetValidTick(this);// SyncA
  ++this->m_iSyncA[v6 + 7];                     // SyncB
  while ( iPackCount )
  {
    v8 = (struct CNet_Event *)pPackedBuffer;
    pPackedBuffer += 32;                        // sizeof(CNet_Event *)
    v8->m_iTick = m_uTick;
    v8->m_iOwner = v6;
    if ( v8->m_iDataSize )
    {
      v8->m_iData = (BYTE *)operator new[](v8->m_iDataSize);
      memcpy(v8->m_iData, pPackedBuffer, v8->m_iDataSize);
      pPackedBuffer += v8->m_iDataSize;
    }
    if ( !CMsgStacks::IsStackAI(this->m_pMsgStacks, v8->m_iOwner - 1) )
      CMsgStacks::PushMsg(this->m_pMsgStacks, v8);
    --iPackCount;
  }
  return 1;
}


// address=[0x15bf0e0]
// Decompiled from bool __thiscall CGameHost::IsValidSaveGame(CGameHost *this, struct SGameInfo *a2)
bool  CGameHost::IsValidSaveGame(struct SGameInfo & a2) {
  
  wchar_t *v2; // eax
  bool v4; // [esp+Fh] [ebp-995h]
  struct CGameChunkGeneral v5; // [esp+10h] [ebp-994h] BYREF
  std::wstring v6; // [esp+978h] [ebp-2Ch] BYREF
  int v7; // [esp+9A0h] [ebp-4h]

  if ( !a2->m_iIsSaveGame )
    return 1;
  std::wstring::wstring(&v6, a2->m_swpRandomMapFileName);
  v7 = 0;
  g_pRandomMaps->AdjustRandomMapFileName(g_pRandomMaps, &v6);
  if ( a2->m_bIsAutosave )
    std::wstring::operator+=(&v6, (wchar_t *)L"_autoSave");
  std::wstring::operator+=(&v6, (wchar_t *)L".sav");
  CGameChunkGeneral::CGameChunkGeneral(&v5);
  v2 = std::wstring::c_str(&v6);
  if ( CGameRun::LoadGeneralInfo(v2, &v5) )
  {
    v4 = v5.m_uSavegameId == a2->m_iSavegameId;
    v7 = -1;
    std::wstring::~wstring(&v6);
    return v4;
  }
  else
  {
    v7 = -1;
    std::wstring::~wstring(&v6);
    return 0;
  }
}


// address=[0x15c4970]
// Decompiled from char __stdcall CGameHost::DoNothing(int a1)
bool  CGameHost::DoNothing(void * a1) {
  
  return 1;
}


#endif // Already implemented
