#include "CGameHost.h"

// Definitions for class CGameHost

// address=[0x14aab10]
// Decompiled from int __thiscall CGameHost::GetBytesPerSecond(CGameHost *this)
unsigned int  CGameHost::GetBytesPerSecond(void) {
  
  if ( this->m_pSimpleNet )
    return (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this->m_pSimpleNet + 52))(this->m_pSimpleNet);
  else
    return 0;
}


// address=[0x15b4e60]
// Decompiled from char __thiscall CGameHost::AllSend(CGameHost *this)
bool  CGameHost::AllSend(void) {
  
  int v2; // eax
  int v3; // esi
  int CurrentTickCounter; // eax
  char v5; // [esp-8h] [ebp-2Ch]
  char v6; // [esp-8h] [ebp-2Ch]
  int v7; // [esp+4h] [ebp-20h] BYREF
  char v8; // [esp+8h] [ebp-1Ch]
  int LocalPlayerId; // [esp+Ch] [ebp-18h]
  int v10; // [esp+10h] [ebp-14h]
  int v11; // [esp+14h] [ebp-10h]
  void *v12; // [esp+18h] [ebp-Ch]
  void *Src; // [esp+1Ch] [ebp-8h]

  if ( !this->m_pMsgStacks && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3738, "m_pMsgStacks") == 1 )
    __debugbreak();
  if ( !this->m_pClientList && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3739, "m_pClientList") == 1 )
    __debugbreak();
  if ( (COMMUNICATION_TICK_VALUE & IEventEngine::GetCurrentTickCounter(g_pEvnEngine)) != 0 )
    return 1;
  if ( std::list<CNet_Event>::size(&this->m_vNetEvents) )
  {
    LocalPlayerId = CPlayerManager::GetLocalPlayerId();
    this->field_11C[6] = (LocalPlayerId - 1) & 0xF | this->field_11C[6] & 0xF0;
    *(_WORD *)this->field_11C = 1054;
    *(_DWORD *)&this->field_11C[7] = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    v11 = 0;
    v12 = &this->field_11C[11];
    while ( std::list<CNet_Event>::size(&this->m_vNetEvents) )
    {
      Src = (void *)std::list<CNet_Event>::front();
      v3 = *((unsigned __int8 *)Src + 30);
      if ( v3 != CPlayerManager::GetLocalPlayerId()
        && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3774, "evn.m_iOwner == g_cPlayerMgr.GetLocalPlayerId()") == 1 )
      {
        __debugbreak();
      }
      if ( *((_DWORD *)Src + 6) && ((char *)v12 + *((unsigned __int16 *)Src + 14) >= &this->field_11C[960] || v11 == 15) )
        break;
      *((_DWORD *)Src + 4) = *(_DWORD *)&this->field_11C[7];
      CMsgStacks::PushMsg((CMsgStacks *)this->m_pMsgStacks, (struct CNet_Event *)Src);
      *((_BYTE *)Src + 30) = 0;
      *((_BYTE *)Src + 31) = 0;
      *((_BYTE *)Src + 20) = 0;
      *((_BYTE *)Src + 21) = 0;
      *((_BYTE *)Src + 22) = 0;
      *((_BYTE *)Src + 23) = 0;
      memcpy(v12, Src, 0x20u);
      v12 = (char *)v12 + 32;
      if ( *((_DWORD *)Src + 6) )
      {
        if ( !*((_WORD *)Src + 14) && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3805, "evn.m_iDataSize") == 1 )
          __debugbreak();
        memcpy(v12, *((const void **)Src + 6), *((unsigned __int16 *)Src + 14));
        v12 = (char *)v12 + *((unsigned __int16 *)Src + 14);
        *((_DWORD *)Src + 6) = 0;
      }
      std::list<CNet_Event>::pop_front();
      ++v11;
    }
    *(_DWORD *)&this->field_11C[2] = v11 & 0xF | *(_DWORD *)&this->field_11C[2] & 0xFFFFFFF0;
    v6 = CPlayerManager::GetLocalPlayerId() - 1;
    CurrentTickCounter = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    CMsgStacks::SetNumberOfExpectedMsgs((_DWORD *)this->m_pMsgStacks, CurrentTickCounter, v6, v11);
    if ( this->c )
      CGameHost::SendToAll((int)this, 1054, this->field_11C, (_BYTE *)v12 - this->field_11C, 0, 0, 1u);
  }
  else
  {
    v8 = CPlayerManager::GetLocalPlayerId();
    v10 = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    v7 = v10;
    if ( this->c )
      CGameHost::SendToAll((int)this, 1055, &v7, 5u, 0, 0, 1u);
    v5 = CPlayerManager::GetLocalPlayerId() - 1;
    v2 = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    CMsgStacks::SetNumberOfExpectedMsgs((_DWORD *)this->m_pMsgStacks, v2, v5, 0);
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
  if ( this->c )
  {
    ValidTick = CMsgStacks::GetValidTick((_DWORD *)this->m_pMsgStacks);
    v3 = CMsgStacks::Getdt((CMsgStacks *)this->m_pMsgStacks) + ValidTick;
    if ( v3 > CMsgStacks::GetVirtualTick((CMsgStacks *)this->m_pMsgStacks) )
    {
LABEL_7:
      CGameHost::AllSend(this);
      CMsgStacks::AdvanceVirtualTick((CMsgStacks *)this->m_pMsgStacks);
      this->dword40 = 0;
      return 0;
    }
  }
  else
  {
    v5 = CMsgStacks::GetValidTick((_DWORD *)this->m_pMsgStacks) + 1;
    if ( v5 >= CMsgStacks::GetVirtualTick((CMsgStacks *)this->m_pMsgStacks) )
      goto LABEL_7;
  }
  if ( (COMMUNICATION_TICK_VALUE & CMsgStacks::GetValidTick((_DWORD *)this->m_pMsgStacks)) != 0
    && this->c
    && (v7 = 0,
        v6 = CGameHost::GetValidTick(this),
        !CMsgStacks::IsMsgStackValid((CMsgStacks *)this->m_pMsgStacks, v6 + 1, (unsigned int *)&v7)) )
  {
    CGameHost::NotifyClients(this, v7);
    return 0;
  }
  else if ( CMsgStacks::IsEmpty((CMsgStacks *)this->m_pMsgStacks, 0) )
  {
    if ( !a2 )
      return 1;
    CMsgStacks::TriggerTime((CMsgStack **)this->m_pMsgStacks);
    CMsgStacks::AdvanceValidTick((CMsgStacks *)this->m_pMsgStacks);
    CMsgStacks::AdvanceVirtualTick((CMsgStacks *)this->m_pMsgStacks);
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
// Decompiled from int __thiscall sub_19B5360(_DWORD *this)
int  CGameHost::GetValidTick(void) {
  
  return CMsgStacks::GetValidTick(this[5]);
}


// address=[0x15b5380]
// Decompiled from int __thiscall CGameHost::GetVirtualTick(CMsgStacks **this)
int  CGameHost::GetVirtualTick(void) {
  
  return CMsgStacks::GetVirtualTick(this[5]);
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
  this->a = 0;
  this->b = 0;
  this->c = arg0;
  this->m_pFSM = 0;
  this->m_pClientList = 0;
  this->m_pMsgStacks = 0;
  this->dword24 = 0;
  this->dword28 = 0;
  this->dword2C = 0;
  this->dword30 = 0;
  this->dword34 = 0;
  this->gap38[4] = 0;
  this->dword40 = 0;
  this->m_pMapDownloadData = 0;
  this->m_pMapDownloadBlocks = 0;
  this->m_bMapBeingDownloaded = 0;
  this->m_bHasSentMap = 0;
  this->m_iMapDownloadBlocksArrived = 0;
  this->m_iMapUpload = 0;
  this->dwordBC = 0;
  this->dwordC0 = 0;
  this->m_pSimpleNet = 0;
  std::list<SGameInfo>::list<SGameInfo>(&this->m_vGameInfos);
  std::list<CNet_Event>::list<CNet_Event>(&this->m_vNetEvents);
  memset(this->field_58, 0, sizeof(this->field_58));
  memset(this->field_78, 0, sizeof(this->field_78));
  memset(this->field_98, 0, sizeof(this->field_98));
  memset(this->field_C8, 0, sizeof(this->field_C8));
  memset(this->field_E8, 0, sizeof(this->field_E8));
  memset(this->field_11C, 0, sizeof(this->field_11C));
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
  this->dword18 = 0;
  v6 = (CDaoIndexFieldInfo *)operator new(0x14u);
  LOBYTE(v11) = 4;
  if ( v6 )
    v5 = CClientList::CClientList(v6);
  else
    v5 = 0;
  LOBYTE(v11) = 2;
  this->m_pClientList = v5;
  if ( !this->c )
    goto LABEL_12;
  this->m_pSimpleNet = CreateSimpleNet();
  if ( this->m_pSimpleNet )
  {
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)this->m_pSimpleNet + 4))(this->m_pSimpleNet) )
    {
      v4 = (std::string *)(*(int (__thiscall **)(_DWORD, _BYTE *))(*(_DWORD *)this->m_pSimpleNet + 8))(
                            this->m_pSimpleNet,
                            v10);
      LOBYTE(v11) = 5;
      v2 = std::string::c_str(v4);
      BBSupportTracePrintF(3, "GameHost.cpp: %s!", v2);
      LOBYTE(v11) = 2;
      std::string::~string(v10);
      this->field_108 = 1;
      return this;
    }
LABEL_12:
    this->field_108 = 0;
    return this;
  }
  BBSupportTracePrint(3, "GameHost.cpp: Error initializing Network!");
  this->field_108 = 1;
  return this;
}


// address=[0x15b5ed0]
// Decompiled from void __thiscall CGameHost::~CGameHost(CGameHost *this)
 CGameHost::~CGameHost(void) {
  
  CFsm *v1; // [esp+28h] [ebp-20h]
  void (__thiscall ***v2)(_DWORD, int); // [esp+2Ch] [ebp-1Ch]
  void (__thiscall ***v3)(_DWORD, int); // [esp+30h] [ebp-18h]
  int i; // [esp+34h] [ebp-14h]

  *(_DWORD *)this = &CGameHost::_vftable_;
  if ( *((_DWORD *)this + 5) )
  {
    v3 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 5);
    if ( v3 )
      (**v3)(v3, 1);
    *((_DWORD *)this + 5) = 0;
  }
  if ( *((_DWORD *)this + 4) )
  {
    v2 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 4);
    if ( v2 )
      (**v2)(v2, 1);
    *((_DWORD *)this + 4) = 0;
  }
  if ( *((_DWORD *)this + 3) )
  {
    v1 = (CFsm *)*((_DWORD *)this + 3);
    if ( v1 )
      delete v1;
    *((_DWORD *)this + 3) = 0;
  }
  if ( *((_DWORD *)this + 18) )
  {
    operator delete[](*((void **)this + 18));
    *((_DWORD *)this + 18) = 0;
  }
  if ( *((_DWORD *)this + 17) )
  {
    operator delete[](*((void **)this + 17));
    *((_DWORD *)this + 17) = 0;
  }
  if ( *((_DWORD *)this + 49) )
  {
    (***((void (__thiscall ****)(_DWORD))this + 49))(*((_DWORD *)this + 49));
    *((_DWORD *)this + 49) = 0;
  }
  for ( i = 0; i < 8; ++i )
  {
    if ( *((_DWORD *)this + i + 38) )
    {
      operator delete(*((void **)this + i + 38));
      *((_DWORD *)this + i + 38) = 0;
    }
  }
  std::list<CNet_Event>::~list<CNet_Event>();
  std::list<SGameInfo>::~list<SGameInfo>();
  IEventHandler::~IEventHandler(this);
}


// address=[0x15b60d0]
// Decompiled from char __thiscall CGameHost::PushMsg(CMsgStacks **this, struct CNet_Event *a2)
bool  CGameHost::PushMsg(class CNet_Event & a2) {
  
  int m_iOwner; // esi

  if ( a2->m_iData
    && !a2->m_iDataSize
    && BBSupportDbgReportF(
         2,
         "Net\\GameHost.cpp",
         3859,
         "Fatal: m_iData set, but m_iDataSize == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1 )
  {
    __debugbreak();
  }
  if ( CPlayerManager::IsAI(a2->m_iOwner) )
    return CMsgStacks::PushMsg(this[5], a2);
  m_iOwner = a2->m_iOwner;
  if ( m_iOwner != CPlayerManager::GetLocalPlayerId()
    && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3865, "_rMsg.m_iOwner == g_cPlayerMgr.GetLocalPlayerId()") == 1 )
  {
    __debugbreak();
  }
  std::list<CNet_Event>::push_back(a2);
  return 1;
}


// address=[0x15b6190]
// Decompiled from void __thiscall CGameHost::PushAsyncMsg(CGameHost *this, unsigned __int16 *Src, unsigned __int8 a3)
void  CGameHost::PushAsyncMsg(class CNet_Event & Src, unsigned char a3) {
  
  DWORD v3; // eax
  int v4; // [esp-18h] [ebp-458h]
  int v5; // [esp-Ch] [ebp-44Ch]
  int i; // [esp+8h] [ebp-438h]
  __int16 v8; // [esp+Ch] [ebp-434h] BYREF
  _BYTE v9[32]; // [esp+Eh] [ebp-432h] BYREF
  _BYTE v10[994]; // [esp+2Eh] [ebp-412h] BYREF
  CEvn_Logic v11; // [esp+410h] [ebp-30h] BYREF
  int v12; // [esp+43Ch] [ebp-4h]

  CTrace::Print("GameHost.cpp: Sending Async Msg to those Players: %x", a3);
  if ( this->c && !CPlayerManager::IsAI(*((unsigned __int8 *)Src + 30)) )
  {
    for ( i = 1; i <= CPlayerManager::LastPlayerId(); ++i )
    {
      if ( !CPlayerManager::IsAI(i) && CPlayerManager::GetLocalPlayerId() != i && ((1 << (i - 1)) & a3) != 0 )
      {
        v8 = 1039;
        memcpy(v9, Src, sizeof(v9));
        memcpy(v10, *((const void **)Src + 6), Src[14]);
        v5 = Src[14] + 34;
        v4 = CPlayerManager::IP(i);
        v3 = CPlayerManager::PeerId(i);
        (*(void (__thiscall **)(_DWORD, DWORD, int, int, __int16 *, int, int, int))(*(_DWORD *)this->m_pSimpleNet + 32))(
          this->m_pSimpleNet,
          v3,
          v4,
          3105,
          &v8,
          v5,
          1,
          1);
        CTrace::Print("GameHost.cpp: Delivering Async Msg to Owner %d!", i);
      }
    }
  }
  if ( (a3 & (1 << (CPlayerManager::GetLocalPlayerId() - 1))) != 0 )
  {
    CEvn_Logic::CEvn_Logic(
      &v11,
      *((_DWORD *)Src + 1),
      *((_DWORD *)Src + 2),
      *((_DWORD *)Src + 3),
      *((_BYTE *)Src + 30),
      *((_DWORD *)Src + 6),
      Src[14]);
    v12 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, &v11);
    v12 = -1;
    CEvn_Logic::~CEvn_Logic(&v11);
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
  
  return (*(int (__thiscall **)(_DWORD, CGameHost *))(**((_DWORD **)this + 49) + 16))(*((_DWORD *)this + 49), this);
}


// address=[0x15b6420]
// Decompiled from int __thiscall CGameHost::GetMessageLength(CGameHost *this)
unsigned short  CGameHost::GetMessageLength(void) {
  
  return (*(int (__thiscall **)(_DWORD, CGameHost *))(*(_DWORD *)this->m_pSimpleNet + 44))(this->m_pSimpleNet, this) - 2;
}


// address=[0x15b6450]
// Decompiled from _DWORD *__thiscall CGameHost::GameInitalized(CFsm **this)
void  CGameHost::GameInitalized(void) {
  
  CEvn_Event v2; // [esp+8h] [ebp-28h] BYREF
  int v3; // [esp+2Ch] [ebp-4h]

  if ( *((_BYTE *)this + 10) )
    return (_DWORD *)CFsm::Control(this[3], 1020, 0);
  CEvn_Event::CEvn_Event(&v2, 0x19u, 0, 0, 0);
  v3 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v2);
  v3 = -1;
  return CEvn_Event::~CEvn_Event(&v2);
}


// address=[0x15b64f0]
// Decompiled from CGameHost *__thiscall CGameHost::ContinueSearchForHost(CGameHost *this)
void  CGameHost::ContinueSearchForHost(void) {
  
  CGameHost *result; // eax

  result = this;
  *((_DWORD *)this + 7) = 0;
  return result;
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

  if ( !this->m_pFSM || !this->a && !this->b )
    return 1;
  CGameHost::DeliverSimpleMessage(this);
  if ( !(*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)this->m_pSimpleNet + 20))(this->m_pSimpleNet) )
  {
    v16 = (std::string *)(*(int (__thiscall **)(_DWORD, _BYTE *))(*(_DWORD *)this->m_pSimpleNet + 8))(
                           this->m_pSimpleNet,
                           v23);
    v28 = 0;
    v1 = std::string::c_str(v16);
    CTrace::Print("GameHost.cpp: %s!", v1);
    v28 = -1;
    std::string::~string(v23);
  }
  if ( this->a )
  {
    for ( i = 0; i < g_pGameType->m_iActualPlayerCount; ++i )
    {
      if ( g_pGameType->m_sPlayerPeerId[i] != -1 )
      {
        Instance = (OnlineManager *)OnlineManager::GetInstance();
        if ( !OnlineManager::IsInSession(Instance)
          || (v3 = StormManager::GetInstance(), g_pGameType->m_sPlayerPeerId[i] != StormManager::GetLocalPeerId(v3)) )
        {
          if ( (int)this->field_E8[i] > 20 )
          {
            v17 = (float)(int)this->field_C8[i] / (float)(int)this->field_E8[i];
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
                v7 = (const char *)(*(int (__thiscall **)(_DWORD, DWORD))(*(_DWORD *)this->m_pSimpleNet + 48))(
                                     this->m_pSimpleNet,
                                     g_pGameType->m_sPlayerIP[i]);
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
              v5 = (const char *)(*(int (__thiscall **)(_DWORD, DWORD))(*(_DWORD *)this->m_pSimpleNet + 48))(
                                   this->m_pSimpleNet,
                                   g_pGameType->m_sPlayerIP[i]);
              CTrace::Print("GameHost.cpp: Boosting player index %u, IP %s!", i, v5);
              v28 = -1;
              CNet_Event::~CNet_Event(&Src);
            }
            this->field_E8[i] = 0;
            this->field_C8[i] = 0;
          }
        }
      }
    }
  }
  if ( CFsm::CurrentState(this->m_pFSM) == 10 )
  {
    if ( !this->dword28 )
      this->dword28 = timeGetTime();
    v8 = this->dword28 + 1000;
    if ( v8 < timeGetTime() )
    {
      CFsm::Control(this->m_pFSM, 1045, (void *)1);
      ++this->dword2C;
      CTrace::Print("GameHost.cpp: Resending login after lobby request!");
      this->dword28 = timeGetTime();
      if ( this->dword2C > (unsigned int)(CStaticConfigVarInt::operator int(&g_iNetAfterLobbyConnectTimeout) / 1000) )
      {
        CGameStateHandler::Queue(
          (struct CGameState *(__cdecl *)(void *))CStateMessageBox::DynamicCreateFunc,
          (void *)GUI_TRP_SCYTH_TT_EXT);
        CGameStateHandler::Switch(CStateMainMenu::DynamicCreateFunc, 0);
      }
    }
  }
  if ( CFsm::CurrentState(this->m_pFSM) == 40 )
  {
    v9 = *(_DWORD *)this->gap38 + CStaticConfigVarInt::operator int(&g_iNotReadyGameStartTimeout);
    if ( v9 < timeGetTime() )
    {
      v15 = CEvn_Event::CEvn_Event(&v24, 0xFA1u, 0, 0, 0);
      v28 = 3;
      IEventEngine::SendAMessage(g_pEvnEngine, v15);
      v28 = -1;
      CEvn_Event::~CEvn_Event(&v24);
      *(_DWORD *)this->gap38 = timeGetTime();
    }
  }
  if ( (CFsm::CurrentState(this->m_pFSM) == 30 || CFsm::CurrentState(this->m_pFSM) == 18) && this->dword18 )
  {
    if ( CGameType::GetNumberHumanPlayers(g_pGameType) <= 1 )
    {
      CFsm::Control(this->m_pFSM, 1015, 0);
    }
    else
    {
      v10 = this->dword18 + CStaticConfigVarInt::operator int(&g_iNotReadyGameStartTimeout);
      if ( v10 < timeGetTime() )
      {
        CTrace::Print("GameHost.cpp: One or more clients r not ready for game. Starting it due to timeout!");
        CFsm::Control(this->m_pFSM, 1015, 0);
      }
    }
  }
  if ( CFsm::CurrentState(this->m_pFSM) == 27 )
  {
    if ( !this->dword30 )
      this->dword30 = timeGetTime();
    v11 = this->dword30 + CStaticConfigVarInt::operator int(&g_iNetClientWaitingStartTick);
    if ( v11 < timeGetTime() )
    {
      CTrace::Print("GameHost.cpp: No start tick signal from host got. Starting due to timeout!");
      CFsm::Control(this->m_pFSM, 1019, 0);
    }
  }
  if ( CFsm::CurrentState(this->m_pFSM) == 15 )
  {
    if ( !this->dword34 )
      this->dword34 = timeGetTime();
    Size = CClientList::GetSize(this->m_pClientList);
    if ( Size == CGameType::HumanPlayers(g_pGameType) - 1 )
    {
      CFsm::Control(this->m_pFSM, 1014, 0);
    }
    else
    {
      v13 = this->dword34 + CStaticConfigVarInt::operator int(&g_iHostWaitAfterLobbyForClientsTimeout);
      if ( v13 < timeGetTime() )
      {
        CTrace::Print("GameHost.cpp: One or more clients missing after lobby. Initing game due to timeout!");
        CFsm::Control(this->m_pFSM, 1014, 0);
      }
    }
  }
  if ( this->b )
    CGameHost::OnClientRun(this);
  else
    CGameHost::OnHostRun((CFsm **)this);
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
  std::wstring v19; // [esp-2Ch] [ebp-1C90h] BYREF
  int v20; // [esp-10h] [ebp-1C74h] BYREF
  _BYTE v21[8]; // [esp+0h] [ebp-1C64h] BYREF
  void *v22; // [esp+8h] [ebp-1C5Ch]
  std::wstring *v23; // [esp+Ch] [ebp-1C58h]
  struct std::string *v24; // [esp+10h] [ebp-1C54h]
  std::wstring *v25; // [esp+14h] [ebp-1C50h]
  void *v26; // [esp+18h] [ebp-1C4Ch]
  std::wstring *v27; // [esp+1Ch] [ebp-1C48h]
  int v28; // [esp+20h] [ebp-1C44h]
  std::wstring *v29; // [esp+24h] [ebp-1C40h]
  int v30; // [esp+28h] [ebp-1C3Ch]
  std::wstring *v31; // [esp+2Ch] [ebp-1C38h]
  std::wstring *a1; // [esp+30h] [ebp-1C34h]
  void *v33; // [esp+34h] [ebp-1C30h]
  int v34; // [esp+38h] [ebp-1C2Ch]
  int v35; // [esp+3Ch] [ebp-1C28h]
  int v36; // [esp+40h] [ebp-1C24h]
  int m_iActualPlayerCount; // [esp+44h] [ebp-1C20h]
  size_t v38; // [esp+48h] [ebp-1C1Ch]
  int v39; // [esp+4Ch] [ebp-1C18h]
  size_t v40; // [esp+50h] [ebp-1C14h]
  size_t Size; // [esp+54h] [ebp-1C10h]
  signed int v42; // [esp+58h] [ebp-1C0Ch]
  BOOL v43; // [esp+5Ch] [ebp-1C08h]
  BOOL v44; // [esp+60h] [ebp-1C04h]
  BOOL v45; // [esp+64h] [ebp-1C00h]
  DWORD v46; // [esp+68h] [ebp-1BFCh]
  int v47; // [esp+6Ch] [ebp-1BF8h]
  int v48; // [esp+70h] [ebp-1BF4h]
  size_t ElementSize; // [esp+74h] [ebp-1BF0h]
  int v50; // [esp+78h] [ebp-1BECh]
  unsigned int v51; // [esp+7Ch] [ebp-1BE8h]
  int v52; // [esp+80h] [ebp-1BE4h]
  int j; // [esp+84h] [ebp-1BE0h]
  char v54; // [esp+88h] [ebp-1BDCh]
  char v55; // [esp+89h] [ebp-1BDBh]
  char MapData; // [esp+8Ah] [ebp-1BDAh]
  bool v57; // [esp+8Bh] [ebp-1BD9h]
  int IntValue; // [esp+8Ch] [ebp-1BD8h]
  char *EndPtr; // [esp+90h] [ebp-1BD4h] BYREF
  bool v60; // [esp+97h] [ebp-1BCDh]
  CGameHost *v61; // [esp+98h] [ebp-1BCCh]
  bool v62; // [esp+9Fh] [ebp-1BC5h]
  void *Buffer; // [esp+A0h] [ebp-1BC4h]
  _BYTE *v64; // [esp+A4h] [ebp-1BC0h]
  signed int i; // [esp+A8h] [ebp-1BBCh]
  char *Str; // [esp+ACh] [ebp-1BB8h]
  struct CGameChunkGeneral v67; // [esp+B0h] [ebp-1BB4h] BYREF
  _DWORD v68[290]; // [esp+A18h] [ebp-124Ch] BYREF
  char v69[88]; // [esp+EA0h] [ebp-DC4h] BYREF
  std::wstring v70; // [esp+EF8h] [ebp-D6Ch] BYREF
  std::wstring v71; // [esp+F14h] [ebp-D50h] BYREF
  CFile v72; // [esp+F30h] [ebp-D34h] BYREF
  std::wstring v73; // [esp+F78h] [ebp-CECh] BYREF
  std::wstring v74; // [esp+F94h] [ebp-CD0h] BYREF
  std::wstring v75; // [esp+FB0h] [ebp-CB4h] BYREF
  std::wstring v76; // [esp+FCCh] [ebp-C98h] BYREF
  std::wstring a2; // [esp+FE8h] [ebp-C7Ch] BYREF
  std::wstring v78; // [esp+1004h] [ebp-C60h] BYREF
  std::wstring v79[9]; // [esp+1020h] [ebp-C44h] BYREF
  _DWORD v80[9]; // [esp+111Ch] [ebp-B48h] BYREF
  wchar_t Ext[256]; // [esp+1140h] [ebp-B24h] BYREF
  wchar_t v82[256]; // [esp+1340h] [ebp-924h] BYREF
  wchar_t Dir[256]; // [esp+1540h] [ebp-724h] BYREF
  _BYTE v84[256]; // [esp+1740h] [ebp-524h] BYREF
  WCHAR Filename[260]; // [esp+1840h] [ebp-424h] BYREF
  wchar_t Dest[256]; // [esp+1A48h] [ebp-21Ch] BYREF
  wchar_t Drive[4]; // [esp+1C48h] [ebp-1Ch] BYREF
  int *v88; // [esp+1C54h] [ebp-10h]
  int v89; // [esp+1C60h] [ebp-4h]

  v2 = alloca(7252);
  v88 = &v20;
  v61 = this;
  GetModuleFileNameW(0, Filename, 0x208u);
  j___wsplitpath(Filename, Drive, Dir, v82, Ext);
  GetCurrentDirectoryW(0x200u, Dir);
  MyWStrNCopy((int)Filename, (int)Dir, 520);
  j__wcscat(Filename, asc_37C7ED4);
  j__wcscat(Filename, Source);
  CFile::CFile(&v72);
  v89 = 1;
  v31 = (std::wstring *)std::wstring::wstring(&v71, Filename);
  a1 = v31;
  LOBYTE(v89) = 2;
  CFile::Open(&v72, v31, CFile_TEXT|CFile_READ, UNUSED_ARG(), UNUSED_ARG());
  LOBYTE(v89) = 1;
  std::wstring::~wstring(&v71);
  v89 = 0;
  ElementSize = CFile::Size(&v72);
  Size = ElementSize + 128;
  v33 = operator new[](ElementSize + 128);
  Buffer = v33;
  memset(v33, 0, Size);
  CFile::Read(&v72, Buffer, ElementSize, 1u, UNUSED_ARG(), UNUSED_ARG());
  CFile::Close(&v72, UNUSED_ARG(), UNUSED_ARG());
  CClassNetGameIniBuffer::CClassNetGameIniBuffer((CClassNetGameIniBuffer *)v21, (const char *)Buffer, ElementSize);
  Str = 0;
  v64 = 0;
  Str = (char *)strstr((char *)Buffer, "GameID=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <GameID>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1289, aErrorI1Reading) == 1 )
      __debugbreak();
  }
  v28 = j__strtol(Str + 7, &EndPtr, 10);
  Str = (char *)strstr((char *)Buffer, "GameName=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <GameName>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1299, aErrorI2Reading) == 1 )
      __debugbreak();
  }
  Str += 9;
  v64 = (_BYTE *)strstr(Str, "\n");
  if ( !v64 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <GameName>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1306, aErrorI3Reading) == 1 )
      __debugbreak();
  }
  i = j__mbstowcs(Dest, Str, v64 - Str);
  Dest[i] = 0;
  memcpy(v84, Str, v64 - Str);
  v42 = i;
  if ( (unsigned int)i >= 0x100 )
    report_rangecheckfailure();
  v84[v42] = 0;
  std::wstring::wstring(&v76, Dest);
  LOBYTE(v89) = 4;
  Str = (char *)strstr((char *)Buffer, "SaveGame=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <SaveGame>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1326, aErrorI2Reading_0) == 1 )
      __debugbreak();
  }
  v51 = j__strtol(Str + 9, &EndPtr, 10);
  v43 = v51 == 1;
  v57 = v51 == 1;
  if ( v51 >= 2 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed! invalid SaveGameTag %d", v51);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1333, aErrorI9bReadin) == 1 )
      __debugbreak();
  }
  g_pGameType->m_bIsSaveGame = v57;
  v60 = 0;
  v62 = 0;
  Str = (char *)strstr((char *)Buffer, "IsLadderGame=");
  if ( Str )
  {
    v34 = j__strtol(Str + 13, &EndPtr, 10);
    v44 = v34 == 1;
    v60 = v34 == 1;
  }
  Str = (char *)strstr((char *)Buffer, "IsClanGame=");
  if ( Str )
  {
    v35 = j__strtol(Str + 11, &EndPtr, 10);
    v45 = v35 == 1;
    v62 = v35 == 1;
  }
  std::wstring::wstring(&a2);
  LOBYTE(v89) = 5;
  Str = (char *)strstr((char *)Buffer, "MapName=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <MapName>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1377, aErrorI4Reading) == 1 )
      __debugbreak();
  }
  Str += 8;
  v64 = (_BYTE *)strstr(Str, "\n");
  if ( !v64 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <MapName>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1384, aErrorI5Reading) == 1 )
      __debugbreak();
  }
  *v64 = 0;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v69);
  LOBYTE(v89) = 6;
  v29 = (std::wstring *)std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
                          (int)&v70,
                          Str);
  std::wstring::operator=(&a2, v29);
  std::wstring::~wstring(&v70);
  *v64 = 10;
  if ( CGameType::IsSaveGame(g_pGameType) )
  {
    CGameType::ConvertMapNameToMPGameName(&v78, &a2);
    LOBYTE(v89) = 7;
    std::wstring::operator+=(&v78, (wchar_t *)L".sav");
    CGameChunkGeneral::CGameChunkGeneral(&v67);
    v3 = std::wstring::c_str(&v78);
    if ( !CGameRun::LoadGeneralInfo(v3, &v67) )
    {
      v4 = std::wstring::c_str(&v78);
      CTrace::Print(
        "GameHost.cpp: Internet game ini file malformed after phase <MapName>, can't load %s!",
        (const char *)v4);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1415, aTheDesiredMapF) == 1 )
        __debugbreak();
    }
    SaveFilePath::BuildSaveFilePath(&v74, (int)&v78);
    LOBYTE(v89) = 8;
    CGameRun::FillGameType(&v74, g_pGameType, (char *)&v67);
    LOBYTE(v89) = 7;
    std::wstring::~wstring(&v74);
    LOBYTE(v89) = 6;
    std::wstring::~wstring(&v78);
  }
  else
  {
    std::wstring::operator=(&g_pGameType->m_swMapName, &a2);
    v19.m_u[6] = v62;
    v19.m_u[5] = v60;
    v19.m_u[4] = -1;
    v19.m_u[3] = -1;
    v19.m_u[2] = 0;
    v19.m_u[1] = 1;
    v19.m_u[0] = 1;
    v18 = 0;
    v17 = 0;
    v27 = &v16;
    v26 = std::wstring::wstring(&v16, &g_pGameType->m_swMapName);
    MapData = CGameType::LoadMapData(
                g_pGameType,
                v16,
                v17,
                v18,
                v19.m_u[0],
                v19.m_u[1],
                v19.m_u[2],
                v19.m_u[3],
                v19.m_u[4],
                v19.m_u[5],
                v19.m_u[6]);
    v55 = MapData;
    if ( !MapData && BBSupportDbgReport(1, "Net\\GameHost.cpp", 1400, aTheDesiredMapF_0) == 1 )
      __debugbreak();
    std::wstring::operator=(&g_pGameType->string0, &v76);
  }
  LOBYTE(v89) = 5;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v69);
  LOBYTE(v89) = 4;
  std::wstring::~wstring(&a2);
  CGameType::SetLadderGame(g_pGameType, v60);
  CGameType::SetClanGame(g_pGameType, v62);
  Str = (char *)strstr(Str, "ProductID=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <ProductID>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1433, aErrorI6Reading) == 1 )
      __debugbreak();
  }
  v52 = (unsigned __int8)j__strtol(Str + 10, &EndPtr, 10);
  v5 = CStaticConfigVarInt::operator int((CStaticConfigVarInt *)&g_iProductID);
  if ( v52 != v5 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase! Wrong Product ID %d!", v52);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1443, aErrorI7Reading) == 1 )
      __debugbreak();
  }
  Str = (char *)strstr((char *)Buffer, "GameMode=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <GameMode>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1452, aErrorI8bReadin) == 1 )
      __debugbreak();
  }
  g_pGameType->m_iMode = j__strtol(Str + 9, &EndPtr, 10);
  if ( (int)g_pGameType->m_iMode <= 0 || (int)g_pGameType->m_iMode >= 6 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed! invalid game mode %d", g_pGameType->m_iMode);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1459, aErrorI9bReadin_0) == 1 )
      __debugbreak();
  }
  Str = (char *)strstr((char *)Buffer, "Resources=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <Resources>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1468, aErrorI8cReadin) == 1 )
      __debugbreak();
  }
  g_pGameType->m_iStartResources = j__strtol(Str + 10, &EndPtr, 10) + 1;
  if ( g_pGameType->m_iStartResources < 1 || g_pGameType->m_iStartResources > 3 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed! invalid game mode %d", g_pGameType->m_iMode);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1475, aErrorI9cReadin) == 1 )
      __debugbreak();
  }
  Str = (char *)strstr((char *)Buffer, "NumberOfTeams=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <NumOfTeams>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1484, aErrorI8aReadin) == 1 )
      __debugbreak();
  }
  if ( g_pGameType->m_iMode != 2 )
    g_pGameType->m_uiNumberAlliances = j__strtol(Str + 14, &EndPtr, 10);
  if ( g_pGameType->m_uiNumberAlliances < 2u || g_pGameType->m_uiNumberAlliances > 8u )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed! Too many Teams %d", g_pGameType->m_uiNumberAlliances);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1496, aErrorI9aReadin) == 1 )
      __debugbreak();
  }
  Str = (char *)strstr((char *)Buffer, "NumberOfPlayers=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <NumberOfPlayers>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1505, aErrorI8Reading) == 1 )
      __debugbreak();
  }
  v50 = j__strtol(Str + 16, &EndPtr, 10);
  if ( !CGameType::IsSaveGame(g_pGameType) && (v62 || g_pGameType->byte36C && g_pGameType->byte36B) )
    g_pGameType->m_iActualPlayerCount = v50;
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
  Str = (char *)strstr((char *)Buffer, "IsTrojan=");
  if ( Str )
  {
    v36 = j__strtol(Str + 9, &EndPtr, 10);
    g_pGameType->byte230 |= v36;
    g_uiExtrasAllowed = g_pGameType->byte230;
  }
  _vec_ctor(
    (char *)v79,
    0x1Cu,
    9u,
    (void (__thiscall *)(void *))std::wstring::wstring,
    (void (__thiscall *)(void *))std::wstring::~wstring);
  LOBYTE(v89) = 9;
  memset(v80, 0, sizeof(v80));
  for ( i = 0; i < v50; ++i )
  {
    sprintf((char *const)Dest, "PlayerIP%d=", i);
    Str = (char *)strstr((char *)Buffer, (char *)Dest);
    if ( !Str )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerIP%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1568, aErrorI10Readin) == 1 )
        __debugbreak();
    }
    v64 = (_BYTE *)strstr(Str, "\n");
    if ( !v64 )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <PlayerIP%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1574, aErrorI11Readin) == 1 )
        __debugbreak();
    }
    *v64 = 0;
    v6 = strlen("PlayerIP%d=");
    v25 = &v19;
    v24 = std::string::string((std::string *)&v19, &Str[v6 - 1]);
    v30 = (*(int (__thiscall **)(_DWORD, int, int, int, int, int, int, int))(*(_DWORD *)v61->m_pSimpleNet + 68))(
            v61->m_pSimpleNet,
            v19.m_u[0],
            v19.m_u[1],
            v19.m_u[2],
            v19.m_u[3],
            v19.m_u[4],
            v19.m_u[5],
            v19.m_u[6]);
    v46 = v30;
    v80[i] = v30;
    if ( !CGameType::IsSaveGame(g_pGameType) )
      g_pGameType->m_sPlayerIP[i] = v46;
    *v64 = 10;
    sprintf((char *const)Dest, "PlayerName%d=", i);
    Str = (char *)strstr((char *)Buffer, (char *)Dest);
    if ( !Str )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerName%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1593, aErrorI12Readin) == 1 )
        __debugbreak();
    }
    v64 = (_BYTE *)strstr(Str, "\n");
    if ( !v64 )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <PlayerName%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1599, aErrorI13Readin) == 1 )
        __debugbreak();
    }
    v19.m_u[6] = v64 - &Str[strlen("PlayerName%d=") - 1];
    v7 = strlen("PlayerName%d=");
    v40 = j__mbstowcs(Dest, &Str[v7 - 1], v19.m_u[6]);
    Dest[v40] = 0;
    std::wstring::wstring(&v75, Dest);
    LOBYTE(v89) = 10;
    std::wstring::operator=(&v79[i], &v75);
    sprintf((char *const)Dest, "PlayerID%d=", i);
    Str = (char *)strstr((char *)Buffer, (char *)Dest);
    if ( !Str )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerID%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1615, aErrorI20Readin) == 1 )
        __debugbreak();
    }
    v19.m_u[6] = 10;
    v19.m_u[5] = (int)&EndPtr;
    v8 = strlen("PlayerID%d=");
    v39 = j__strtol(&Str[v8 - 1], &EndPtr, 10);
    g_pGameType->m_sPlayerPeerId[i] = v39;
    if ( g_pGameType->m_sPlayerTeam[i] >= g_pGameType->m_uiNumberAlliances )
      g_pGameType->m_sPlayerTeam[i] = (unsigned int)i % g_pGameType->m_uiNumberAlliances;
    if ( CGameType::IsClanGame(g_pGameType) )
    {
      sprintf((char *const)Dest, "ClanShortcut%d=", i);
      Str = (char *)strstr((char *)Buffer, (char *)Dest);
      if ( !Str )
      {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerIP%d>!", i);
        if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1633, aErrorI10Readin_0) == 1 )
          __debugbreak();
      }
      v64 = (_BYTE *)strstr(Str, "\n");
      if ( !v64 )
      {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <PlayerIP%d>!", i);
        if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1639, aErrorI11Readin_0) == 1 )
          __debugbreak();
      }
      v19.m_u[6] = v64 - &Str[strlen("ClanShortcut%d=") - 1];
      v9 = strlen("ClanShortcut%d=");
      v38 = j__mbstowcs(Dest, &Str[v9 - 1], v19.m_u[6]);
      Dest[v38] = 0;
      std::wstring::wstring(&v73, Dest);
      LOBYTE(v89) = 11;
      CGameType::SetPlayerClanShortcut(g_pGameType, i, &v73);
      LOBYTE(v89) = 10;
      std::wstring::~wstring(&v73);
    }
    LOBYTE(v89) = 9;
    std::wstring::~wstring(&v75);
  }
  IntValue = CClassNetGameIniBuffer::GetIntValue("LocalPlayerSlot=", -1);
  if ( IntValue >= 8 )
    IntValue = -1;
  if ( IntValue < 0 )
  {
    for ( i = 0; i < v50; ++i )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v61->m_pSimpleNet + 64))(
             v61->m_pSimpleNet,
             v80[i]) )
      {
        IntValue = i;
        break;
      }
    }
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v61->m_pSimpleNet + 72))(v61->m_pSimpleNet, v80[IntValue]);
  }
  if ( IntValue >= 0 && std::wstring::length(&v79[IntValue]) )
  {
    v23 = &v19;
    v22 = std::wstring::wstring(&v19, &v79[IntValue]);
    CGameSettings::SetPlayerName(v19);
  }
  g_pGameType->dword44 = v80[0];
  if ( !IntValue )
  {
    CGameType::SetHost(g_pGameType, 1);
    if ( CGameType::IsSaveGame(g_pGameType) )
    {
      LocalSlot = CGameType::GetLocalSlot(g_pGameType);
      g_pGameType->m_sPlayerIP[LocalSlot] = v80[0];
    }
  }
  if ( g_pGameType->m_iMode == 2 )
    g_pGameType->m_iActualPlayerCount = g_pGameType->m_iMapMaxNumPlayers;
  Str = (char *)strstr((char *)Buffer, "SessionID=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <SessionID>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1705, aErrorI14Readin) == 1 )
      __debugbreak();
  }
  v64 = (_BYTE *)strstr(Str, "\n");
  if ( !v64 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <SessionID>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1711, aErrorI15Readin) == 1 )
      __debugbreak();
  }
  *v64 = 0;
  std::string::operator=(&g_pGameType->std__string318, Str + 10);
  *v64 = 10;
  Str = (char *)strstr((char *)Buffer, "ProcedureServer=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <ProcedureServer>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1723, aErrorI16Readin) == 1 )
      __debugbreak();
  }
  v64 = (_BYTE *)strstr(Str, "\n");
  if ( !v64 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <ProcedureServer>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1729, aErrorI17Readin) == 1 )
      __debugbreak();
  }
  *v64 = 0;
  std::string::operator=(&g_pGameType->std__string334, Str + 16);
  *v64 = 10;
  Str = (char *)strstr((char *)Buffer, "ProcedureServerPort=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <g_szProcServerPort>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1739, aErrorI18Readin) == 1 )
      __debugbreak();
  }
  v64 = (_BYTE *)strstr(Str, "\n");
  if ( !v64 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <g_szProcServerPort>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1745, aErrorI19Readin) == 1 )
      __debugbreak();
  }
  *v64 = 0;
  g_pGameType->word350 = j__strtol(Str + 20, &EndPtr, 10);
  *v64 = 10;
  v11 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD, int))(*(_DWORD *)v61->m_pSimpleNet + 48))(
                        v61->m_pSimpleNet,
                        g_pGameType->dword44,
                        v20);
  CTrace::Print("GameHost.cpp: Host is %s", v11);
  g_pGameType->dword26C = 0;
  if ( CGameType::IsClanGame(g_pGameType) )
    g_pGameType->byte36B = 0;
  m_iActualPlayerCount = g_pGameType->m_iActualPlayerCount;
  for ( j = 0; j < m_iActualPlayerCount; ++j )
  {
    sprintf((char *const)Dest, "PlayerTeam%d=", j);
    Str = (char *)strstr((char *)Buffer, (char *)Dest);
    if ( Str )
    {
      v20 = 10;
      v19.m_u[6] = (int)&EndPtr;
      v12 = strlen((const char *)Dest);
      v47 = j__strtol(&Str[v12], &EndPtr, 10);
      if ( v47 >= 0 )
        g_pGameType->m_sPlayerTeam[j] = v47;
    }
  }
  for ( i = 0; (unsigned int)i < g_pGameType->m_iActualPlayerCount; ++i )
  {
    if ( g_pGameType->gap3E6[i + 9] )
      g_pGameType->m_sPlayerRaces[i] = 0;
    if ( !g_pGameType->m_sPlayerType[i] )
      ++g_pGameType->dword26C;
  }
  g_pGameType->m_iGameType = 2;
  CGameType::SetWebGame(g_pGameType, 1);
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)v61->m_pSimpleNet + 64))(
         v61->m_pSimpleNet,
         g_pGameType->dword44) )
  {
    v61->b = 0;
    v61->a = 1;
    CFsm::Control(v61->m_pFSM, 1007, 0);
    CFsm::Control(v61->m_pFSM, 1051, 0);
  }
  else
  {
    Sleep(0x7D0u);
    memset(v68, 0, sizeof(v68));
    LOBYTE(v68[1]) = 1;
    LOBYTE(v68[150]) = 0;
    v68[148] = g_pGameType->m_iMapCRC;
    v68[151] = g_pGameType->m_iActualPlayerCount;
    v19.m_u[6] = 512;
    v13 = std::wstring::c_str(&g_pGameType->m_swMapName);
    MyWStrNCopy((int)&v68[20], (int)v13, v19.m_u[6]);
    v68[152] = g_pGameType->m_iActualPlayerCount;
    v68[149] = g_pGameType->m_iFileSize;
    v68[2] = timeGetTime();
    v19.m_u[6] = 64;
    v14 = std::wstring::c_str(&g_pGameType->string0);
    MyWStrNCopy((int)&v68[4], (int)v14, v19.m_u[6]);
    v68[0] = g_pGameType->dword44;
    LOBYTE(v68[156]) = CGameType::IsSaveGame(g_pGameType);
    BYTE1(v68[158]) = g_pGameType->byte2B9;
    v68[157] = g_pGameType->m_uiTickCounter;
    v68[154] = CGameType::GetMultiPlayerGameID(g_pGameType);
    v68[155] = CGameType::GetMPSavegameID(g_pGameType);
    CGameHost::AddGame(v61, (struct SGameInfo *)v68);
    v61->b = 1;
    v61->a = 0;
    CFsm::Control(v61->m_pFSM, 1008, 0);
    CFsm::Control(v61->m_pFSM, 1024, 0);
  }
  v48 = CStateLobbyGameSettings::CompileUserFlags();
  if ( v48 && BBSupportDbgReportF(2, "Net\\GameHost.cpp", 1862, "CompileUserFlags() reported error %d!", v48) == 1 )
    __debugbreak();
  if ( BBSupportDbgReport(2, "Net\\GameHost.cpp", 1864, "false") == 1 )
    __debugbreak();
  v54 = 1;
  LOBYTE(v89) = 4;
  `eh vector destructor iterator'(v79, 0x1Cu, 9u, (void (__thiscall *)(void *))std::wstring::~wstring);
  LOBYTE(v89) = 0;
  std::wstring::~wstring(&v76);
  v89 = -1;
  CFile::~CFile(&v72);
  return v54;
}


// address=[0x15b88c0]
// Decompiled from DWORD __thiscall CGameHost::PingClients(CGameHost *this)
void  CGameHost::PingClients(void) {
  
  unsigned int v1; // esi
  DWORD result; // eax
  int v3; // eax
  __int16 v4; // [esp+4h] [ebp-1Ch] BYREF
  DWORD v5; // [esp+6h] [ebp-1Ah]
  unsigned int PlayerPeerId; // [esp+Ch] [ebp-14h]
  int PlayerIP; // [esp+10h] [ebp-10h]
  DWORD Time; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  CGameHost *v10; // [esp+1Ch] [ebp-4h]

  v10 = this;
  if ( *((_DWORD *)this + 9) )
  {
    v1 = *((_DWORD *)v10 + 9) + 1000;
    result = timeGetTime();
    if ( v1 >= result )
      return result;
  }
  Time = timeGetTime();
  v4 = 3;
  v5 = Time;
  for ( i = 0; ; ++i )
  {
    CClientList::GetSize(*((CDaoIndexFieldInfo **)v10 + 4));
    if ( i >= v3 )
      break;
    PlayerIP = CClientList::GetPlayerIP(*((CClientList **)v10 + 4), i);
    PlayerPeerId = CClientList::GetPlayerPeerId(*((CClientList **)v10 + 4), i);
    (*(void (__thiscall **)(_DWORD, unsigned int, int, int, __int16 *, int, _DWORD, int))(**((_DWORD **)v10 + 49) + 32))(
      *((_DWORD *)v10 + 49),
      PlayerPeerId,
      PlayerIP,
      3105,
      &v4,
      6,
      0,
      1);
  }
  result = timeGetTime();
  *((_DWORD *)v10 + 9) = result;
  return result;
}


// address=[0x15b8990]
// Decompiled from void __thiscall CGameHost::DeliverSimpleMessage(CGameHost *this)
void  CGameHost::DeliverSimpleMessage(void) {
  
  char *v1; // eax
  OnlineManager *Instance; // eax
  int v3; // eax
  int LocalPeerId; // esi
  int v5; // eax
  int v6; // eax
  DWORD Time; // eax
  OnlineManager *v8; // eax
  storm::SimpleSessionHandler **v9; // eax
  int HostPeerId; // eax
  _BYTE v11[4]; // [esp+8h] [ebp-60h] BYREF
  unsigned __int16 *v12; // [esp+Ch] [ebp-5Ch]
  std::string *v13; // [esp+10h] [ebp-58h]
  std::string *v14; // [esp+14h] [ebp-54h]
  unsigned __int16 *v15; // [esp+18h] [ebp-50h]
  int v16; // [esp+1Ch] [ebp-4Ch]
  int v17; // [esp+20h] [ebp-48h]
  int ClientIndexPerPeerId; // [esp+24h] [ebp-44h]
  unsigned __int16 *v19; // [esp+28h] [ebp-40h] BYREF
  int v20; // [esp+2Ch] [ebp-3Ch] BYREF
  unsigned int i; // [esp+30h] [ebp-38h]
  unsigned __int16 v23; // [esp+38h] [ebp-30h]
  _BYTE v24[28]; // [esp+3Ch] [ebp-2Ch] BYREF
  int v25; // [esp+64h] [ebp-4h]

  v17 = 0;
  while ( (*(unsigned __int8 (__thiscall **)(_DWORD, int))(*(_DWORD *)this->m_pSimpleNet + 24))(this->m_pSimpleNet, -1) )
  {
    ++v17;
    if ( !(*(unsigned __int8 (__thiscall **)(_DWORD, unsigned __int16 **, _BYTE *, int *))(*(_DWORD *)this->m_pSimpleNet
                                                                                         + 28))(
            this->m_pSimpleNet,
            &v19,
            v11,
            &v20) )
    {
      v14 = (std::string *)(*(int (__thiscall **)(_DWORD, _BYTE *))(*(_DWORD *)this->m_pSimpleNet + 8))(
                             this->m_pSimpleNet,
                             v24);
      v13 = v14;
      v25 = 0;
      v1 = std::string::c_str(v14);
      CTrace::Print("Gamehost.cpp: PopMessage() failed with error %s!", v1);
      v25 = -1;
      std::string::~string(v24);
      return;
    }
    if ( v19 )
    {
      Instance = (OnlineManager *)OnlineManager::GetInstance();
      if ( OnlineManager::IsInSession(Instance)
        && (v3 = StormManager::GetInstance(),
            LocalPeerId = StormManager::GetLocalPeerId(v3),
            LocalPeerId == (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this->m_pSimpleNet + 40))(this->m_pSimpleNet)) )
      {
        CTrace::Print("CGameHost.cpp: Msg from localhost ignored!");
      }
      else
      {
        v23 = *v19;
        v16 = v23;
        if ( v23 == 3 )
        {
          if ( CClientList::ContainsPeerId((CClientList *)this->m_pClientList, v20) )
          {
            v15 = v19;
            *v19 = 4;
            v5 = (*(int (__thiscall **)(_DWORD, int, unsigned __int16 *, int, _DWORD, int))(*(_DWORD *)this->m_pSimpleNet
                                                                                          + 36))(
                   this->m_pSimpleNet,
                   3105,
                   v15,
                   6,
                   0,
                   1);
            (*(void (__thiscall **)(_DWORD, int, int))(*(_DWORD *)this->m_pSimpleNet + 32))(this->m_pSimpleNet, v20, v5);
            if ( CFsm::CurrentState(this->m_pFSM) == TRY_BUILD_STATE_EX )
              this->dword24 = timeGetTime();
          }
        }
        else if ( v16 == 4 )
        {
          v12 = v19;
          for ( i = 0; i < g_pGameType->m_iActualPlayerCount; ++i )
          {
            v6 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this->m_pSimpleNet + 40))(this->m_pSimpleNet);
            if ( g_pGameType->m_sPlayerPeerId[i] == v6 )
            {
              g_pGameType->m_sPlayerSlot14[i] = timeGetTime() - *(_DWORD *)(v12 + 1);
              CLanLobby::RedrawPlayerList();
              ClientIndexPerPeerId = CClientList::GetClientIndexPerPeerId((CClientList *)this->m_pClientList, v20);
              if ( ClientIndexPerPeerId < 0 )
                j___wassert(L"index >= 0", L"Net\\GameHost.cpp", 0x440u);
              Time = timeGetTime();
              CClientList::SetClientLastAck((CClientList *)this->m_pClientList, ClientIndexPerPeerId, Time);
            }
          }
        }
        else if ( v23 >= 0x3E8u && v23 < 0x425u )
        {
          if ( v23 == 1000
            || v23 == 1001
            || v23 == 1013
            || v23 == 1022
            || v23 == 1023
            || v23 == 1038
            || v23 == 1032
            || v23 == 3
            || CClientList::ContainsPeerId((CClientList *)this->m_pClientList, v20)
            || (v8 = (OnlineManager *)OnlineManager::GetInstance(), OnlineManager::IsInSession(v8))
            && (v9 = (storm::SimpleSessionHandler **)StormManager::GetInstance(),
                HostPeerId = StormManager::GetHostPeerId(v9),
                v20 == HostPeerId) )
          {
            if ( v23 != 1000 || !this->b && CFsm::CurrentState(this->m_pFSM) != 17 )
              CFsm::Control(this->m_pFSM, v23, v19 + 1);
          }
        }
      }
    }
  }
}


// address=[0x15b8d70]
// Decompiled from void *__thiscall CGameHost::ConvertIPAddress(_DWORD **this, void *a2, int a3)
std::string  CGameHost::ConvertIPAddress(unsigned int a2) {
  
  char *v3; // eax

  if ( this[49] )
  {
    v3 = (char *)(*(int (__thiscall **)(_DWORD *, int))(*this[49] + 48))(this[49], a3);
    std::string::string(a2, v3);
  }
  else
  {
    std::string::string(a2, "Unknown");
  }
  return a2;
}


// address=[0x15b8de0]
// Decompiled from char __thiscall CGameHost::RemovePlayerPeerId(CMsgStacks **this, unsigned int a2)
bool  CGameHost::RemovePlayerPeerId(unsigned int a2) {
  
  int Instance; // eax
  int ValidTick; // eax
  CEvn_Event *v5; // [esp+4h] [ebp-40h]
  int v6; // [esp+Ch] [ebp-38h]
  char v8; // [esp+17h] [ebp-2Dh]
  unsigned int i; // [esp+18h] [ebp-2Ch]
  int j; // [esp+18h] [ebp-2Ch]
  CEvn_Event v11; // [esp+1Ch] [ebp-28h] BYREF
  int v12; // [esp+40h] [ebp-4h]

  v8 = 0;
  Instance = StormManager::GetInstance();
  if ( StormManager::GetLocalPeerId(Instance) == a2 )
    return 0;
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
  {
    if ( *(_DWORD *)(g_pGameType + 4 * i + 224) == a2 )
    {
      v8 = 1;
      break;
    }
  }
  if ( !v8 )
    return 0;
  CMsgStacks::ClearAndValidate(this[5], i);
  CMsgStacks::SetStackAI(i, 1);
  if ( CGameSettings::GetAIDifficulty() )
    v6 = 3;
  else
    v6 = 2;
  *(_DWORD *)(g_pGameType + 4 * i + 116) = v6;
  *(_DWORD *)(g_pGameType + 4 * i + 524) = CGameHost::GetValidTick(this);
  ValidTick = CGameHost::GetValidTick(this);
  CTrace::Print("GameHost.cpp: Message stack index#%d set to AI in Tick %d!", i, ValidTick);
  if ( !CClientList::RemoveClientPeerId(this[4], *(_DWORD *)(g_pGameType + 4 * i + 224)) )
    CTrace::Print("GameHost.cpp: Player index#%d could not be removed from client list!", i);
  for ( j = 1; j <= CPlayerManager::LastPlayerId() && CPlayerManager::PeerId(j) != a2; ++j )
    ;
  if ( j > CPlayerManager::LastPlayerId()
    && BBSupportDbgReportF(2, "Net\\GameHost.cpp", 3577, "Player could not be set to AI!") == 1 )
  {
    __debugbreak();
  }
  CTrace::Print("GameHost.cpp: Dropping player index#%d", j - 1);
  v5 = CEvn_Event::CEvn_Event(&v11, 0x39u, j, 0, 0);
  v12 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v5);
  v12 = -1;
  CEvn_Event::~CEvn_Event(&v11);
  return 1;
}


// address=[0x15b9000]
// Decompiled from char __thiscall CGameHost::IsLocalIP(_DWORD **this, int a2)
bool  CGameHost::IsLocalIP(unsigned int a2) {
  
  if ( this[49] )
    return (*(int (__thiscall **)(_DWORD *, int))(*this[49] + 64))(this[49], a2);
  else
    return 1;
}


// address=[0x15b9040]
// Decompiled from char __thiscall CGameHost::OnEndGame(CGameHost *this, int a2)
bool  CGameHost::OnEndGame(int a2) {
  
  return 1;
}


// address=[0x15b9050]
// Decompiled from void __thiscall CGameHost::OnEndSaving(CMsgStacks **this, int a2)
void  CGameHost::OnEndSaving(int a2) {
  
  CMsgStacks::OnEndSaving(this[5], *(_DWORD *)(g_pGameType + 112), a2);
}


// address=[0x15b9080]
// Decompiled from void __thiscall CGameHost::StormJoinSessionSucceeded(CClientList **this)
void  CGameHost::StormJoinSessionSucceeded(void) {
  
  storm::SimpleSessionHandler **Instance; // eax
  wchar_t *v2; // eax
  void *v3; // eax
  char *v4; // [esp-8h] [ebp-74h]
  void *v5; // [esp+4h] [ebp-68h]
  std::wstring *PlayerName; // [esp+Ch] [ebp-60h]
  unsigned int HostPeerId; // [esp+1Ch] [ebp-50h]
  int LocalSlot; // [esp+20h] [ebp-4Ch]
  std::wstring v10; // [esp+24h] [ebp-48h] BYREF
  _BYTE v11[28]; // [esp+40h] [ebp-2Ch] BYREF
  int v12; // [esp+68h] [ebp-4h]

  OutputDebugStringA("JoinSessionSucceeded\n");
  Instance = (storm::SimpleSessionHandler **)StormManager::GetInstance();
  HostPeerId = StormManager::GetHostPeerId(Instance);
  CClientList::Add(this[4], 0, 0, HostPeerId);
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
  CFsm::GenerateEvent((CFsm *)this[3], 1057, 0);
}


// address=[0x15b91b0]
// Decompiled from int __stdcall CGameHost::StormHost_NewPlayerMessage(int a1, _Cnd_internal_imp_t *a2, char a3)
void  CGameHost::StormHost_NewPlayerMessage(unsigned int a1, std::wstring & a2, int a3) {
  
  const wchar_t *v3; // eax
  wchar_t Destination[32]; // [esp+4h] [ebp-6Ch] BYREF
  int v6; // [esp+45h] [ebp-2Bh]
  char v7; // [esp+62h] [ebp-Eh]
  char v8; // [esp+68h] [ebp-8h]

  v6 = a1;
  v3 = (const wchar_t *)std::wstring::c_str(a2);
  wcscpy(Destination, v3);
  v7 = *(_BYTE *)(g_pGameType + 696);
  v8 = a3;
  return CGameHost::ClientJoins(Destination);
}


// address=[0x15b9210]
// Decompiled from int __thiscall CGameHost::StormClientLeavesMyGame(CClientList **this, unsigned int a2)
void  CGameHost::StormClientLeavesMyGame(unsigned int a2) {
  
  int Instance; // eax

  Instance = StormManager::GetInstance();
  if ( a2 == StormManager::GetHostPeerId(Instance) )
    CTrace::Print("GameHost.cpp: Host has left session!");
  CLanLobby::DisconnectPlayerPeerId(a2, -1);
  if ( !CClientList::RemoveClientPeerId(this[4], a2) )
    CTrace::Print("GameHost.cpp: Unable to removed client!");
  return CLanLobby::RedrawPlayerList();
}


// address=[0x15b9280]
// Decompiled from int __thiscall CGameHost::PromoteToHost(CGameHost *this)
void  CGameHost::PromoteToHost(void) {
  
  void **CurrentState; // eax
  CStateLobbyGameSettings *v3; // [esp+0h] [ebp-8h]

  *((_BYTE *)this + 8) = 1;
  *((_BYTE *)this + 9) = 0;
  byte_4030852 = 1;
  CurrentState = (void **)CGameStateHandler::GetCurrentState();
  v3 = (CStateLobbyGameSettings *)j____RTDynamicCast(
                                    CurrentState,
                                    0,
                                    &CGameState__RTTI_Type_Descriptor_,
                                    &CStateLobbyGameSettings__RTTI_Type_Descriptor_,
                                    0);
  if ( !v3 )
    return CTrace::Print("GameHost.cpp: We are new Host!!!");
  CStateLobbyGameSettings::TransitionToHost(v3);
  CFsm::Control(*((CFsm **)this + 3), 1058, 0);
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
// Decompiled from _DWORD *__thiscall CGameHost::OnQuickMatchedHosted(CGameHost *this)
void  CGameHost::OnQuickMatchedHosted(void) {
  
  const wchar_t *v1; // eax
  const wchar_t *v2; // eax
  _Cnd_internal_imp_t *v4; // [esp+0h] [ebp-B4h]
  _Cnd_internal_imp_t *PlayerName; // [esp+4h] [ebp-B0h]
  unsigned int i; // [esp+Ch] [ebp-A8h]
  _BYTE v8[28]; // [esp+10h] [ebp-A4h] BYREF
  _BYTE v9[28]; // [esp+2Ch] [ebp-88h] BYREF
  wchar_t Destination[31]; // [esp+48h] [ebp-6Ch] BYREF
  __int16 v11; // [esp+86h] [ebp-2Eh]
  int v12; // [esp+89h] [ebp-2Bh]
  char v13; // [esp+ACh] [ebp-8h]

  v13 = -1;
  if ( !(unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType)
    || !(unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) )
  {
    PlayerName = (_Cnd_internal_imp_t *)CGameSettings::GetPlayerName((int)v9);
    v1 = (const wchar_t *)std::wstring::c_str(PlayerName);
    wcsncpy(Destination, v1, 0x1Fu);
    std::wstring::~wstring(v9);
    v11 = 0;
    v12 = 0;
    *(_DWORD *)(g_pGameType + 116) = 1;
    CLanLobby::ConnectPlayer(Destination, -1);
  }
  for ( i = 1; i < *(_DWORD *)(g_pGameType + 112); ++i )
  {
    if ( *(_DWORD *)(g_pGameType + 4 * i + 116) == 2
      || *(_DWORD *)(g_pGameType + 4 * i + 116) == 3
      || *(_BYTE *)(i + g_pGameType + 998) && !*((_BYTE *)this + 10) )
    {
      v12 = -1;
      v4 = (_Cnd_internal_imp_t *)CGameType::GetPlayerName((void *)g_pGameType, v8, i);
      v2 = (const wchar_t *)std::wstring::c_str(v4);
      wcsncpy(Destination, v2, 0x1Fu);
      std::wstring::~wstring(v8);
      v11 = 0;
      CLanLobby::ConnectPlayer(Destination, i);
    }
  }
  return CFsm::GenerateEvent(1009, 0);
}


// address=[0x15b9500]
// Decompiled from int __thiscall CGameHost::OnJoinedFromOnlineFlow(CGameHost *this)
void  CGameHost::OnJoinedFromOnlineFlow(void) {
  
  int Instance; // eax
  wchar_t *v2; // eax
  wchar_t *v3; // eax
  void *v4; // eax
  _DWORD *v5; // eax
  wchar_t *v6; // eax
  wchar_t *v7; // eax
  std::wstring v9; // [esp-40h] [ebp-F4h] BYREF
  bool v10; // [esp-24h] [ebp-D8h]
  int v11; // [esp-20h] [ebp-D4h]
  int v12; // [esp-1Ch] [ebp-D0h] OVERLAPPED BYREF
  int v13; // [esp-18h] [ebp-CCh]
  int v14; // [esp-14h] [ebp-C8h]
  DWORD v15; // [esp-10h] [ebp-C4h]
  int v16; // [esp-Ch] [ebp-C0h]
  int v17; // [esp-8h] [ebp-BCh]
  int v18; // [esp-4h] [ebp-B8h]
  int v19; // [esp+0h] [ebp-B4h]
  int v20; // [esp+4h] [ebp-B0h]
  std::wstring *v21; // [esp+8h] [ebp-ACh]
  void *v22; // [esp+Ch] [ebp-A8h]
  int *v23; // [esp+10h] [ebp-A4h]
  CGameHost *v24; // [esp+14h] [ebp-A0h]
  int v25; // [esp+18h] [ebp-9Ch]
  int v26; // [esp+1Ch] [ebp-98h]
  CGameType *v27; // [esp+20h] [ebp-94h]
  void *v28; // [esp+24h] [ebp-90h]
  CGameType *v29; // [esp+28h] [ebp-8Ch]
  INetworkEngine *v30; // [esp+2Ch] [ebp-88h]
  BOOL v31; // [esp+30h] [ebp-84h]
  CGameType *v32; // [esp+34h] [ebp-80h]
  void *v33; // [esp+38h] [ebp-7Ch]
  CGameType *v34; // [esp+3Ch] [ebp-78h]
  INetworkEngine *v35; // [esp+40h] [ebp-74h]
  void *C; // [esp+44h] [ebp-70h]
  CDaoIndexFieldInfo *CurrentSession; // [esp+48h] [ebp-6Ch]
  int v38; // [esp+4Ch] [ebp-68h]
  _BYTE v39[28]; // [esp+50h] [ebp-64h] BYREF
  _BYTE v40[28]; // [esp+6Ch] [ebp-48h] BYREF
  _BYTE v41[28]; // [esp+88h] [ebp-2Ch] BYREF
  int v42; // [esp+B0h] [ebp-4h]

  v24 = this;
  Instance = StormManager::GetInstance();
  CurrentSession = (CDaoIndexFieldInfo *)StormManager::GetCurrentSession(Instance);
  v23 = &v12;
  v22 = std::wstring::wstring((std::wstring *)&v12, &stru_4030720);
  CGameSettings::SetPlayerName(*(std::wstring *)&v12);
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
    v19,
    v20);
  v42 = 0;
  GameSessionDescriptor::GetMapName(v40);
  if ( !g_pNetworkEngine )
  {
    C = operator new(0x18u);
    LOBYTE(v42) = 1;
    if ( C )
      v35 = INetworkEngine::INetworkEngine((INetworkEngine *)C, 1);
    else
      v35 = 0;
    v30 = v35;
    LOBYTE(v42) = 0;
    g_pNetworkEngine = v35;
    INetworkEngine::Start(0, 0, 0, 0);
  }
  v18 = 0;
  v17 = 0;
  v16 = -1;
  v15 = -1;
  v14 = 0;
  v13 = 1;
  v12 = 1;
  v2 = (wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(0, 0);
  v21 = &v9;
  v20 = std::wstring::wstring(&v9, v2);
  HIBYTE(v38) = CGameType::LoadMapData(g_pGameType, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !HIBYTE(v38) )
  {
    v29 = g_pGameType;
    v34 = g_pGameType;
    if ( g_pGameType )
      v28 = delete v34;
    else
      v28 = 0;
    v33 = operator new(0x620u);
    LOBYTE(v42) = 2;
    if ( v33 )
      v32 = CGameType::CGameType((CGameType *)v33);
    else
      v32 = 0;
    v27 = v32;
    LOBYTE(v42) = 0;
    g_pGameType = v32;
    v3 = (wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(
                      v19,
                      v20);
    std::wstring::operator=(&g_pGameType->m_swMapName, v3);
    g_pGameType->m_bAIActive = 0;
  }
  storm::echo::SessionDescriptor::GetSessionName(CurrentSession);
  v5 = std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str(v4);
  v26 = ((int (__cdecl *)(_BYTE *, _DWORD *, int, int, std::wstring *, void *, int *, CGameHost *, int, int, CGameType *, void *, CGameType *, INetworkEngine *, BOOL, CGameType *, void *, CGameType *, INetworkEngine *, void *, CDaoIndexFieldInfo *, int))storm::CStringConvertToUtf16)(
          v39,
          v5,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          C,
          CurrentSession,
          v38);
  v25 = v26;
  LOBYTE(v42) = 3;
  v6 = (wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(
                    v19,
                    v20);
  std::wstring::operator=(g_pGameType, v6);
  LOBYTE(v42) = 0;
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>();
  g_pGameType->m_iGameType = 2;
  g_pGameType->m_iCampaignType = 0;
  g_pGameType->m_iActualPlayerCount = GameSessionDescriptor::GetPeerCount(CurrentSession);
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
    v19,
    v20);
  LOBYTE(v42) = 4;
  GameSessionDescriptor::GetSaveFile(v41);
  v31 = std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::length(v41) != 0;
  g_pGameType->m_bIsSaveGame = v31;
  g_pGameType->byte2B9 = 0;
  if ( g_pGameType->m_bIsSaveGame )
  {
    v7 = (wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(
                      v19,
                      v20);
    std::wstring::operator=(&g_pGameType->m_swSaveFile, v7);
    if ( g_pGameType->byte2B9 )
      std::wstring::operator+=(&g_pGameType->m_swSaveFile, (wchar_t *)L"_autoSave");
    std::wstring::operator+=(&g_pGameType->m_swSaveFile, (wchar_t *)L".sav");
  }
  CLanLobby::Communicate(1024, dword_4030718);
  LOBYTE(v42) = 0;
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>();
  v42 = -1;
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
  
  if ( !*((_DWORD *)this + 3) || CFsm::CurrentState(*((CFsm **)this + 3)) != 5 || *((_DWORD *)this + 9) )
    return 1;
  *((_DWORD *)this + 9) = timeGetTime();
  return 1;
}


// address=[0x15b9d20]
// Decompiled from int __thiscall CGameHost::OnHostRun(CFsm **this)
void  CGameHost::OnHostRun(void) {
  
  int result; // eax
  DWORD v2; // esi

  result = CFsm::CurrentState(this[3]);
  if ( result != 3 )
    return result;
  CGameHost::PingClients((CGameHost *)this);
  v2 = (DWORD)this[8] + 8000;
  if ( v2 < timeGetTime() )
    CFsm::Control(this[3], 1035, 0);
  result = CFsm::Control(this[3], 1061, 0);
  if ( this[46] )
    return CFsm::Control(this[3], 1042, 0);
  return result;
}


// address=[0x15b9da0]
// Decompiled from char __thiscall CGameHost::InitHostNetwork(CGameHost *this, void *a2)
bool  CGameHost::InitHostNetwork(void * a2) {
  
  *((_BYTE *)this + 8) = 1;
  return 1;
}


// address=[0x15b9dc0]
// Decompiled from char __thiscall CGameHost::InitClientNetwork(CGameHost *this, void *a2)
bool  CGameHost::InitClientNetwork(void * a2) {
  
  *((_BYTE *)this + 9) = 1;
  CFsm::GenerateEvent(1010, 0);
  return 1;
}


// address=[0x15b9df0]
// Decompiled from char __thiscall CGameHost::ErrorState(int this, int a2)
bool  CGameHost::ErrorState(void * a2) {
  
  int v2; // eax
  int v3; // eax
  const char *v5; // [esp+0h] [ebp-8h]

  if ( *(_DWORD *)(this + 196) )
  {
    v2 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 36))(*(_DWORD *)(this + 196));
    v5 = (const char *)(*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 196) + 48))(
                         *(_DWORD *)(this + 196),
                         v2);
  }
  else
  {
    v5 = 0;
  }
  v3 = CFsm::CurrentState(*(CFsm **)(this + 12));
  CTrace::Print("GameHost.cpp: FSM Internal Error. Last State:%d, Event:%d (%s?)", v3, a2, v5);
  return 1;
}


// address=[0x15b9e70]
// Decompiled from int __stdcall CGameHost::ProcessPlayerData(int a1)
void  CGameHost::ProcessPlayerData(struct SLobbyPlayerData & a1) {
  
  int result; // eax
  void **CurrentState; // eax
  int v3; // [esp+8h] [ebp-60h]
  int v4; // [esp+10h] [ebp-58h]
  unsigned __int8 v5; // [esp+1Fh] [ebp-49h]
  _BYTE v6[28]; // [esp+20h] [ebp-48h] BYREF
  _BYTE v7[28]; // [esp+3Ch] [ebp-2Ch] BYREF
  int v8; // [esp+64h] [ebp-4h]

  v5 = 0;
  *(_DWORD *)(g_pGameType + 620) = *(unsigned __int8 *)(a1 + 1);
  if ( *(_DWORD *)(g_pGameType + 112) != *(unsigned __int8 *)(a1 + 2) )
  {
    *(_DWORD *)(g_pGameType + 112) = *(unsigned __int8 *)(a1 + 2);
    v5 = 1;
  }
  v4 = std::wstring::wstring(v7, (wchar_t *)(a1 + 5));
  v8 = 0;
  CGameType::SetPlayerName(*(unsigned __int8 *)(a1 + 3), v4);
  v8 = -1;
  std::wstring::~wstring(v7);
  v3 = std::wstring::wstring(v6, (wchar_t *)(a1 + 69));
  v8 = 1;
  CGameType::SetPlayerClanShortcut(*(unsigned __int8 *)(a1 + 3), v3);
  v8 = -1;
  std::wstring::~wstring(v6);
  *(_DWORD *)(g_pGameType + 4 * *(unsigned __int8 *)(a1 + 3) + 152) = *(unsigned __int8 *)(a1 + 92);
  *(_DWORD *)(g_pGameType + 4 * *(unsigned __int8 *)(a1 + 3) + 332) = *(unsigned __int8 *)(a1 + 90);
  *(_DWORD *)(g_pGameType + 4 * *(unsigned __int8 *)(a1 + 3) + 368) = *(unsigned __int8 *)(a1 + 91);
  *(_DWORD *)(g_pGameType + 4 * *(unsigned __int8 *)(a1 + 3) + 188) = *(_DWORD *)(a1 + 81);
  *(_DWORD *)(g_pGameType + 4 * *(unsigned __int8 *)(a1 + 3) + 224) = *(_DWORD *)(a1 + 85);
  *(_DWORD *)(g_pGameType + 4 * *(unsigned __int8 *)(a1 + 3) + 404) = *(unsigned __int8 *)(a1 + 89);
  *(_DWORD *)(g_pGameType + 4 * *(unsigned __int8 *)(a1 + 3) + 116) = *(unsigned __int8 *)(a1 + 93);
  *(_BYTE *)(g_pGameType + *(unsigned __int8 *)(a1 + 3) + 440) = *(_BYTE *)(a1 + 94);
  *(_DWORD *)(g_pGameType + 4 * *(unsigned __int8 *)(a1 + 3) + 452) = *(unsigned __int8 *)(a1 + 95);
  *(_DWORD *)(g_pGameType + 64) = *(unsigned __int8 *)(a1 + 96);
  *(_DWORD *)(g_pGameType + 864) = *(unsigned __int8 *)(a1 + 97);
  *(_BYTE *)(g_pGameType + 560) = *(_BYTE *)(a1 + 115);
  *(_DWORD *)(g_pGameType + 4 * *(unsigned __int8 *)(a1 + 3) + 564) = *(_DWORD *)(a1 + 105);
  *(_DWORD *)(g_pGameType + 660) = *(unsigned __int16 *)(a1 + 109);
  CGameType::SetMultiPlayerGameID((CGameType *)g_pGameType, *(_DWORD *)(a1 + 111));
  memcpy((void *)(g_pGameType + 784), (const void *)(a1 + 98), 7u);
  CLanLobby::RedrawPlayerList();
  result = v5;
  if ( !v5 )
    return result;
  CurrentState = (void **)CGameStateHandler::GetCurrentState();
  result = j____RTDynamicCast(
             CurrentState,
             0,
             &CGameState__RTTI_Type_Descriptor_,
             &CStateLobbyGameSettings__RTTI_Type_Descriptor_,
             0);
  if ( result )
    return CStateLobbyGameSettings::PaintMap((void *)result);
  return result;
}


// address=[0x15ba130]
// Decompiled from int __thiscall CGameHost::SendPlayerData(void *this, int a2)
void  CGameHost::SendPlayerData(unsigned int a2) {
  
  int result; // eax
  _Cnd_internal_imp_t *RealPlayerName; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  _Cnd_internal_imp_t *PlayerClanShortcut; // [esp+8h] [ebp-B8h]
  unsigned __int8 v8; // [esp+17h] [ebp-A9h]
  signed int i; // [esp+18h] [ebp-A8h]
  _BYTE v10[28]; // [esp+1Ch] [ebp-A4h] BYREF
  _BYTE Src[120]; // [esp+38h] [ebp-88h] BYREF
  int v12; // [esp+BCh] [ebp-4h]

  for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
  {
    memset(Src, 0, 0x77u);
    Src[1] = *(_BYTE *)(g_pGameType + 620);
    Src[2] = *(_BYTE *)(g_pGameType + 112);
    Src[3] = i;
    Src[0] = a2;
    Src[90] = *(_BYTE *)(g_pGameType + 4 * i + 332);
    Src[91] = *(_BYTE *)(g_pGameType + 4 * i + 368);
    Src[92] = *(_BYTE *)(g_pGameType + 4 * i + 152);
    *(_DWORD *)&Src[81] = *(_DWORD *)(g_pGameType + 4 * i + 188);
    *(_DWORD *)&Src[85] = *(_DWORD *)(g_pGameType + 4 * i + 224);
    Src[89] = *(_BYTE *)(g_pGameType + 4 * i + 404);
    Src[93] = *(_BYTE *)(g_pGameType + 4 * i + 116);
    Src[94] = *(_BYTE *)(i + g_pGameType + 440);
    Src[95] = *(_BYTE *)(g_pGameType + 4 * i + 452);
    RealPlayerName = (_Cnd_internal_imp_t *)CGameType::GetRealPlayerName((void *)g_pGameType, i);
    v4 = std::wstring::c_str(RealPlayerName);
    MyWStrNCopy((int)&Src[5], (int)v4, 64);
    PlayerClanShortcut = (_Cnd_internal_imp_t *)CGameType::GetPlayerClanShortcut((void *)g_pGameType, v10, i);
    v12 = 0;
    v5 = std::wstring::c_str(PlayerClanShortcut);
    MyWStrNCopy((int)&Src[69], (int)v5, 12);
    v12 = -1;
    std::wstring::~wstring(v10);
    Src[96] = *(_BYTE *)(g_pGameType + 64);
    memcpy(&Src[98], (const void *)(g_pGameType + 784), 7u);
    Src[97] = *(_BYTE *)(g_pGameType + 864);
    *(_DWORD *)&Src[115] = *(unsigned __int8 *)(g_pGameType + 560);
    *(_DWORD *)&Src[105] = *(_DWORD *)(g_pGameType + 4 * i + 564);
    *(_WORD *)&Src[109] = *(_WORD *)(g_pGameType + 660);
    *(_DWORD *)&Src[111] = CGameType::GetMultiPlayerGameID(g_pGameType);
    v8 = a2 != 0;
    if ( a2 )
      CGameHost::SendToAll((int)this, 1032, Src, 0x77u, 0, 0, v8);
    else
      CGameHost::SendToAll((int)this, 1026, Src, 0x77u, 0, 0, v8);
    result = i + 1;
  }
  return result;
}


// address=[0x15ba420]
// Decompiled from void __thiscall CGameHost::SendToAll(  CGameHost *this,  int a2,  void *_pvData0,  size_t _uiDataLength0,  void *_pvData1,  size_t _uiDataLength1,  char a7)
void  CGameHost::SendToAll(unsigned int a2, short * _pvData0, unsigned int _uiDataLength0, short * _pvData1, unsigned int _uiDataLength1, bool a7) {
  
  int PlayerPeerId; // eax
  int PlayerIP; // [esp-18h] [ebp-42Ch]
  int i; // [esp+0h] [ebp-414h]
  unsigned __int8 v11; // [esp+Bh] [ebp-409h]
  __int16 v12; // [esp+Ch] [ebp-408h] BYREF
  _BYTE v13[1026]; // [esp+Eh] [ebp-406h] BYREF

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
  if ( this->c )
  {
    for ( i = 0; i < CClientList::GetSize(this->m_pClientList); ++i )
    {
      v12 = a2;
      if ( _pvData0 )
      {
        memcpy(v13, _pvData0, _uiDataLength0);
      }
      else if ( _uiDataLength0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4637, "!_uiDataLength0") == 1 )
      {
        __debugbreak();
      }
      if ( _pvData1 )
      {
        if ( !_pvData0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4642, "_pvData0") == 1 )
          __debugbreak();
        memcpy(&v13[_uiDataLength0], _pvData1, _uiDataLength1);
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
      (*(void (__thiscall **)(_DWORD, int, int, int, __int16 *, size_t, _DWORD, _DWORD))(*(_DWORD *)this->m_pSimpleNet
                                                                                       + 32))(
        this->m_pSimpleNet,
        PlayerPeerId,
        PlayerIP,
        3105,
        &v12,
        _uiDataLength0 + _uiDataLength1 + 2,
        (unsigned __int8)a7,
        v11);
    }
  }
}


// address=[0x15ba650]
// Decompiled from _DWORD *__thiscall CGameHost::SendToHost(_DWORD *this, int a2, void *Src, size_t Size, void *a5, size_t a6, char a7)
void  CGameHost::SendToHost(unsigned int a2, short * Src, unsigned int Size, short * a5, unsigned int a6, bool a7) {
  
  _DWORD *result; // eax
  int Instance; // eax
  int HostPeerId; // eax
  int v10; // [esp-18h] [ebp-428h]
  unsigned __int8 v12; // [esp+7h] [ebp-409h]
  __int16 v13; // [esp+8h] [ebp-408h] BYREF
  _BYTE v14[1026]; // [esp+Ah] [ebp-406h] BYREF

  if ( Src
    && !Size
    && BBSupportDbgReportF(
         2,
         "Net\\GameHost.cpp",
         4673,
         "Fatal: _pvData0 set, but _uiDataLength0 == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1 )
  {
    __debugbreak();
  }
  if ( a5
    && !a6
    && BBSupportDbgReportF(
         2,
         "Net\\GameHost.cpp",
         4677,
         "Fatal: _pvData1 set, but _uiDataLength1 == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1 )
  {
    __debugbreak();
  }
  v13 = a2;
  if ( Src )
  {
    memcpy(v14, Src, Size);
  }
  else if ( Size && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4687, "!_uiDataLength0") == 1 )
  {
    __debugbreak();
  }
  if ( a5 )
  {
    if ( !Src && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4692, "_pvData0") == 1 )
      __debugbreak();
    memcpy(&v14[Size], a5, a6);
  }
  else if ( a6 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4697, "!_uiDataLength1") == 1 )
  {
    __debugbreak();
  }
  v12 = 1;
  if ( a2 == 1055 || a2 == 3 || a2 == 1040 )
    v12 = 0;
  if ( !this[49] && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4709, "m_pSimpleNet!=NULL") == 1 )
    __debugbreak();
  result = this;
  if ( !this[49] )
    return result;
  v10 = *(_DWORD *)(g_pGameType + 68);
  Instance = StormManager::GetInstance();
  HostPeerId = StormManager::GetHostPeerId(Instance);
  return (_DWORD *)(*(int (__thiscall **)(_DWORD, int, int, int, __int16 *, size_t, _DWORD, _DWORD))(*(_DWORD *)this[49] + 32))(
                     this[49],
                     HostPeerId,
                     v10,
                     3105,
                     &v13,
                     Size + a6 + 2,
                     (unsigned __int8)a7,
                     v12);
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
  _BYTE v11[12]; // [esp+34h] [ebp-48h] BYREF
  int v12; // [esp+40h] [ebp-3Ch]
  int v13; // [esp+44h] [ebp-38h]
  int *v14; // [esp+48h] [ebp-34h]
  int v15; // [esp+4Ch] [ebp-30h]
  int v16; // [esp+50h] [ebp-2Ch]
  int *v17; // [esp+54h] [ebp-28h]
  std::_Iterator_base12 *v18; // [esp+58h] [ebp-24h]
  std::_Iterator_base12 *v19; // [esp+5Ch] [ebp-20h]
  struct SGameInfo *v20; // [esp+60h] [ebp-1Ch]
  int v21; // [esp+64h] [ebp-18h]
  CGameHost *v22; // [esp+68h] [ebp-14h]
  char v23; // [esp+6Eh] [ebp-Eh]
  char v24; // [esp+6Fh] [ebp-Dh]
  int v25; // [esp+78h] [ebp-4h]

  v22 = this;
  if ( !CGameHost::IsValidSaveGame(this, a2) )
    return 1;
  std::list<SGameInfo>::begin(v11);
  v25 = 0;
  while ( 1 )
  {
    v19 = (std::_Iterator_base12 *)std::list<SGameInfo>::end(v9);
    v18 = v19;
    LOBYTE(v25) = 1;
    v24 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator!=(v19);
    LOBYTE(v25) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v9);
    if ( !v24 )
      break;
    v21 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v11);
    v20 = a2;
    if ( *(_DWORD *)(v21 + 640) == *((_DWORD *)a2 + 160) && *(_DWORD *)(v21 + 644) == *((_DWORD *)v20 + 161) )
    {
      v6 = a2;
      v17 = &v3;
      v16 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>((struct std::_Iterator_base12 *)v11);
      v15 = std::list<SGameInfo>::insert(v8, v3, v4, v5, v6);
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v8);
      v14 = &v4;
      v13 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>((struct std::_Iterator_base12 *)v11);
      v12 = std::list<SGameInfo>::erase(v7, v4, v5, v6);
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v7);
      CLanLobby::RedrawGameList();
      v23 = 1;
      v25 = -1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v11);
      return v23;
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator++(v10, 0);
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v10);
  }
  std::list<SGameInfo>::push_back(a2);
  CLanLobby::RedrawGameList();
  v25 = -1;
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
  int v23; // [esp+60h] [ebp-2Ch]
  int v24; // [esp+64h] [ebp-28h]
  int v25; // [esp+68h] [ebp-24h]
  std::_Iterator_base12 *v26; // [esp+6Ch] [ebp-20h]
  std::_Iterator_base12 *v27; // [esp+70h] [ebp-1Ch]
  _DWORD v28[2]; // [esp+74h] [ebp-18h] BYREF
  char v29; // [esp+7Fh] [ebp-Dh]
  int v30; // [esp+88h] [ebp-4h]

  v28[1] = this;
  v28[0] = timeGetTime();
  v8 = *(_DWORD *)std::_Iterator_base12::operator=(v28);
  v22 = &v5;
  v21 = std::list<SGameInfo>::end(&v5);
  v20 = &v2;
  v19 = std::list<SGameInfo>::begin(&v2);
  v18 = std::remove_if<std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>,_lambda_a570ae9d9b6327d9fce7c622bf5e21bb_>(
          v12,
          v2,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8);
  v30 = 0;
  v27 = (std::_Iterator_base12 *)std::list<SGameInfo>::end(v11);
  v26 = v27;
  LOBYTE(v30) = 1;
  v29 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator!=(v27);
  LOBYTE(v30) = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v11);
  if ( v29 )
  {
    v25 = std::list<SGameInfo>::end(v9);
    v24 = v25;
    LOBYTE(v30) = 2;
    v17 = &v6;
    v23 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v25);
    v16 = v23;
    LOBYTE(v30) = 3;
    v15 = &v3;
    v14 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>((struct std::_Iterator_base12 *)v12);
    LOBYTE(v30) = 2;
    v13 = std::list<SGameInfo>::erase(v10, v3, v4, v5, v6, v7, v8);
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v10);
    LOBYTE(v30) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v9);
    CLanLobby::RedrawGameList();
  }
  v30 = -1;
  return std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v12);
}


// address=[0x15baba0]
// Decompiled from int __thiscall CGameHost::GetLocalID(CGameHost *this)
unsigned int  CGameHost::GetLocalID(void) {
  
  int Instance; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
  {
    Instance = StormManager::GetInstance();
    if ( StormManager::GetLocalPeerId(Instance) == *(_DWORD *)(g_pGameType + 4 * i + 224) )
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
    if ( *(_DWORD *)(g_pGameType + 4 * i + 188) == a2 )
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
  signed int Time; // [esp+34h] [ebp-B8h]
  int j; // [esp+38h] [ebp-B4h]
  unsigned int i; // [esp+40h] [ebp-ACh]
  char v18; // [esp+47h] [ebp-A5h]
  CEvn_Logic v19; // [esp+48h] [ebp-A4h] BYREF
  std::wstring v20; // [esp+68h] [ebp-84h] BYREF
  std::wstring v21; // [esp+84h] [ebp-68h] BYREF
  CEvn_Event v22; // [esp+A0h] [ebp-4Ch] BYREF
  char Dest[36]; // [esp+B8h] [ebp-34h] BYREF
  int v24; // [esp+E8h] [ebp-4h]

  v18 = 0;
  Time = timeGetTime();
  for ( i = 0; i < g_pGameType->m_iActualPlayerCount; ++i )
  {
    if ( (a2 & (1 << i)) != 0 && i != CGameHost::GetLocalID(this) )
    {
      LastMsgTime = CMsgStacks::GetLastMsgTime((CMsgStacks *)this->m_pMsgStacks, i);
      if ( LastMsgTime )
      {
        if ( LastMsgTime + CStaticConfigVarInt::operator int(&g_iNotReadyKickDelay) >= Time )
        {
          if ( LastMsgTime + CStaticConfigVarInt::operator int(&g_iNotReadyWarnDelay) < Time
            && (!this->dwordC0
             || this->dwordC0 + CStaticConfigVarInt::operator int(&g_iNotReadyWarnAgainDelay) < (unsigned int)Time) )
          {
            CTrace::Print("CGameHost.cpp: Waiting for Player index#%d !", i);
            this->dwordC0 = Time;
            PlayerName = CGameType::GetPlayerName(g_pGameType, &v20, i);
            v24 = 2;
            v4 = std::wstring::c_str(PlayerName);
            v6 = wcslen(v4);
            v8 = CGameType::GetPlayerName(g_pGameType, &v21, i);
            v5 = std::wstring::c_str(v8);
            v7 = j__wcstombs(Dest, v5, v6);
            std::wstring::~wstring(&v21);
            v24 = -1;
            std::wstring::~wstring(&v20);
            if ( v7 >= 0x21 )
              report_rangecheckfailure();
            Dest[v7] = 0;
            CTextMsgHandler::AddTextMsg(2261, i + 1, 0, 1, Dest);
            v18 = 1;
          }
        }
        else
        {
          CTrace::Print("GameHost.cpp: Kicking player index#%d!", i);
          v12 = g_pGameType->m_sPlayerPeerId[i];
          for ( j = 1; j <= CPlayerManager::LastPlayerId() && CPlayerManager::PeerId(j) != v12; ++j )
            ;
          CGameHost::RemovePlayerPeerId((CMsgStacks **)this, g_pGameType->m_sPlayerPeerId[i]);
          ValidTick = CGameHost::GetValidTick(this);
          v11 = CEvn_Logic::CEvn_Logic(&v19, 0xFA9u, j, ValidTick, j, 0, 0);
          v24 = 0;
          INetworkEngine::SendAsyncNetMessage(g_pNetworkEngine, v11, 255);
          v24 = -1;
          CEvn_Logic::~CEvn_Logic(&v19);
          v3 = CGameHost::GetValidTick(this);
          v10 = CEvn_Event::CEvn_Event(&v22, 0xFA9u, j, v3, 0);
          v24 = 1;
          IEventEngine::SendAMessage(g_pEvnEngine, v10);
          v24 = -1;
          CEvn_Event::~CEvn_Event(&v22);
          v18 = 1;
        }
      }
      else
      {
        CMsgStacks::SetLastMsgTime(i, Time, 0);
      }
    }
  }
  if ( v18 )
    CGameHost::SendToAll((int)this, 1040, 0, 0, 0, 0, 0);
}


// address=[0x15bb0e0]
// Decompiled from char __thiscall CGameHost::IsExclusiveColor(CGameHost *this, int a2)
bool  CGameHost::IsExclusiveColor(int a2) {
  
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
  {
    if ( i != a2
      && *(_DWORD *)(g_pGameType + 4 * i + 332) == *(_DWORD *)(g_pGameType + 4 * a2 + 332)
      && !*(_BYTE *)(i + g_pGameType + 440) )
    {
      return 0;
    }
  }
  return 1;
}


// address=[0x15bb160]
// Decompiled from char __thiscall CGameHost::HostChoseMap(_BYTE *this, int a2)
bool  CGameHost::HostChoseMap(void * a2) {
  
  const wchar_t *v2; // eax
  const wchar_t *v3; // eax
  OnlineManager *Instance; // eax
  struct CGameType *v6; // [esp-4h] [ebp-C0h]
  _Cnd_internal_imp_t *v7; // [esp+0h] [ebp-BCh]
  _Cnd_internal_imp_t *PlayerName; // [esp+4h] [ebp-B8h]
  unsigned int i; // [esp+14h] [ebp-A8h]
  _BYTE v11[28]; // [esp+18h] [ebp-A4h] BYREF
  _BYTE v12[28]; // [esp+34h] [ebp-88h] BYREF
  wchar_t Destination[31]; // [esp+50h] [ebp-6Ch] BYREF
  __int16 v14; // [esp+8Eh] [ebp-2Eh]
  int v15; // [esp+91h] [ebp-2Bh]
  char v16; // [esp+B4h] [ebp-8h]

  v16 = -1;
  if ( !(unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType)
    || !(unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) )
  {
    PlayerName = (_Cnd_internal_imp_t *)CGameSettings::GetPlayerName((int)v12);
    v2 = (const wchar_t *)std::wstring::c_str(PlayerName);
    wcsncpy(Destination, v2, 0x1Fu);
    std::wstring::~wstring(v12);
    v14 = 0;
    v15 = 0;
    *(_DWORD *)(g_pGameType + 116) = 1;
    CLanLobby::ConnectPlayer(Destination, -1);
  }
  for ( i = 1; i < *(_DWORD *)(g_pGameType + 112); ++i )
  {
    if ( *(_DWORD *)(g_pGameType + 4 * i + 116) == 2
      || *(_DWORD *)(g_pGameType + 4 * i + 116) == 3
      || *(_BYTE *)(i + g_pGameType + 998) && !this[10] )
    {
      v15 = -1;
      v7 = (_Cnd_internal_imp_t *)CGameType::GetPlayerName((void *)g_pGameType, v11, i);
      v3 = (const wchar_t *)std::wstring::c_str(v7);
      wcsncpy(Destination, v3, 0x1Fu);
      std::wstring::~wstring(v11);
      v14 = 0;
      CLanLobby::ConnectPlayer(Destination, i);
    }
  }
  if ( (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) )
  {
    v6 = (struct CGameType *)g_pGameType;
    Instance = (OnlineManager *)OnlineManager::GetInstance();
    OnlineManager::CreateSession(Instance, v6);
  }
  CFsm::GenerateEvent(1009, 0);
  return 1;
}


// address=[0x15bb380]
// Decompiled from char __stdcall CGameHost::QuickMatchChoseMap(int a1)
bool  CGameHost::QuickMatchChoseMap(void * a1) {
  
  int v2; // [esp-4h] [ebp-8h]

  v2 = g_pGameType;
  OnlineManager::GetInstance();
  OnlineManager::QuickMatch(v2);
  return 1;
}


// address=[0x15bb3b0]
// Decompiled from char __thiscall CGameHost::InviteAccepted(CGameHost *this, int a2)
bool  CGameHost::InviteAccepted(void * a2) {
  
  OnlineManager *Instance; // eax
  void *v3; // eax
  OnlineManager *v5; // eax
  OnlineManager *v6; // eax
  unsigned __int64 v7; // [esp+0h] [ebp-10h] BYREF
  CGameHost *v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  v8 = this;
  v7 = a2;
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
// Decompiled from char __stdcall sub_19BB430(int a1)
bool  CGameHost::StartState(void * a1) {
  
  return 0;
}


// address=[0x15bb440]
// Decompiled from char __thiscall SearchHost(void *this, int a2)
bool  CGameHost::SearchHost(void * a2) {
  
  int v2; // eax
  _BYTE v4[12]; // [esp+Ch] [ebp-4C8h] BYREF
  _BYTE v5[12]; // [esp+18h] [ebp-4BCh] BYREF
  _BYTE v6[12]; // [esp+24h] [ebp-4B0h] BYREF
  void *v7; // [esp+30h] [ebp-4A4h]
  _BYTE *v8; // [esp+34h] [ebp-4A0h]
  char v9; // [esp+3Bh] [ebp-499h]
  _DWORD v10[290]; // [esp+3Ch] [ebp-498h] BYREF
  int v11; // [esp+4D0h] [ebp-4h]

  v7 = this;
  CTrace::Print("Start searching Host .... ");
  std::list<SGameInfo>::list<SGameInfo>(v5);
  v11 = 0;
  OnlineManager::GetInstance();
  OnlineManager::UpdateDiscoveredSessions(v5);
  v8 = v5;
  std::list<SGameInfo>::begin(v6);
  LOBYTE(v11) = 1;
  std::list<SGameInfo>::end(v4);
  LOBYTE(v11) = 2;
  while ( (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator!=((std::_Iterator_base12 *)v4) )
  {
    qmemcpy(
      v10,
      (const void *)std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v6),
      sizeof(v10));
    v10[2] = timeGetTime();
    CGameHost::AddGame(v10);
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator++(v6);
  }
  LOBYTE(v11) = 1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v4);
  LOBYTE(v11) = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v6);
  CGameHost::ValidateGameList();
  v2 = OnlineManager::GetInstance();
  OnlineManager::SearchForSessions(v2);
  v9 = 1;
  v11 = -1;
  std::list<SGameInfo>::~list<SGameInfo>();
  return v9;
}


// address=[0x15bb5b0]
// Decompiled from char __thiscall CGameHost::ClientSearchesGameHost(_DWORD **this, int a2)
bool  CGameHost::ClientSearchesGameHost(void * a2) {
  
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  int v4; // eax
  int v5; // eax
  _WORD v8[514]; // [esp+18h] [ebp-460h] BYREF
  _BYTE v9[44]; // [esp+41Ch] [ebp-5Ch] BYREF
  int v10; // [esp+448h] [ebp-30h] BYREF
  int v11; // [esp+474h] [ebp-4h]

  memset(v8, 0, 0x402u);
  v8[0] = 1022;
  LOBYTE(v8[293]) = *(_BYTE *)(g_pGameType + 609);
  *(_DWORD *)&v8[297] = *(_DWORD *)(g_pGameType + 620);
  *(_DWORD *)&v8[289] = *(_DWORD *)(g_pGameType + 616);
  *(_DWORD *)&v8[295] = *(_DWORD *)(g_pGameType + 112);
  *(_DWORD *)&v8[291] = *(_DWORD *)(g_pGameType + 856);
  LOBYTE(v8[299]) = std::string::length(g_pGameType + 664) != 0;
  LOBYTE(v8[305]) = *(_BYTE *)(g_pGameType + 696);
  HIBYTE(v8[309]) = *(_BYTE *)(g_pGameType + 697);
  *(_DWORD *)&v8[307] = *(_DWORD *)(g_pGameType + 700);
  *(_DWORD *)&v8[301] = CGameType::GetMultiPlayerGameID(g_pGameType);
  *(_DWORD *)&v8[303] = CGameType::GetMPSavegameID(g_pGameType);
  LOBYTE(v8[305]) = CGameType::IsSaveGame((void *)g_pGameType);
  LOBYTE(v8[309]) = *(_BYTE *)(g_pGameType + 560);
  v2 = std::wstring::c_str((_Cnd_internal_imp_t *)g_pGameType);
  MyWStrNCopy((int)&v8[1], (int)v2, 64);
  FilePaths::SplitPath((int)v9, g_pGameType + 28);
  v11 = 0;
  v3 = std::wstring::c_str((_Cnd_internal_imp_t *)&v10);
  MyWStrNCopy((int)&v8[33], (int)v3, 512);
  v4 = (*(int (__thiscall **)(_DWORD *, int, _WORD *, int, _DWORD))(*this[49] + 36))(this[49], 3105, v8, 1146, 0);
  v5 = (*(int (__thiscall **)(_DWORD *, int))(*this[49] + 40))(this[49], v4);
  (*(void (__thiscall **)(_DWORD *, int))(*this[49] + 32))(this[49], v5);
  v11 = -1;
  FilePaths::PathSplitResult::~PathSplitResult(v9);
  return 1;
}


// address=[0x15bb880]
// Decompiled from char __thiscall CGameHost::ClientReceivesGameInfo(_DWORD **this, void *Src)
bool  CGameHost::ClientReceivesGameInfo(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  _DWORD *v3; // eax
  int v5; // [esp-4h] [ebp-508h]
  int v6; // [esp+4h] [ebp-500h]
  int v7; // [esp+Ch] [ebp-4F8h]
  int v9; // [esp+18h] [ebp-4ECh] BYREF
  char IsMapAvailable; // [esp+1Ch] [ebp-4E8h]
  DWORD Time; // [esp+20h] [ebp-4E4h]
  _BYTE v12[64]; // [esp+28h] [ebp-4DCh] BYREF
  wchar_t String[256]; // [esp+68h] [ebp-49Ch] BYREF
  int v14; // [esp+268h] [ebp-29Ch]
  _BYTE v15[28]; // [esp+4A0h] [ebp-64h] BYREF
  _BYTE v16[28]; // [esp+4BCh] [ebp-48h] BYREF
  _BYTE v17[28]; // [esp+4D8h] [ebp-2Ch] BYREF
  int v18; // [esp+500h] [ebp-4h]

  if ( (unsigned __int16)CGameHost::GetMessageLength(this) != 1144 )
    return 1;
  v9 = (*(int (__thiscall **)(_DWORD *))(*this[49] + 36))(this[49]);
  MessageLength = CGameHost::GetMessageLength(this);
  memcpy(v12, Src, MessageLength);
  v7 = std::wstring::wstring(v16, String);
  v18 = 0;
  MapFilePaths::GetFilePathForMapName(v17, v7);
  LOBYTE(v18) = 2;
  std::wstring::~wstring(v16);
  v3 = std::wstring::c_str((_Cnd_internal_imp_t *)v17);
  MyWStrNCopy((int)String, (int)v3, 512);
  v5 = v14;
  v6 = std::wstring::wstring(v15, String);
  LOBYTE(v18) = 3;
  IsMapAvailable = CGameType::IsMapAvailable(v6, v5);
  LOBYTE(v18) = 2;
  std::wstring::~wstring(v15);
  Time = timeGetTime();
  CGameHost::AddGame((CGameHost *)this, (struct SGameInfo *)&v9);
  v18 = -1;
  std::wstring::~wstring(v17);
  return 1;
}


// address=[0x15bba10]
// Decompiled from char __thiscall CGameHost::ClientLoginHost(CGameHost *this, int arg0)
bool  CGameHost::ClientLoginHost(void * arg0) {
  
  int Instance; // eax
  int v3; // eax
  int v4; // eax
  wchar_t *v5; // eax
  wchar_t *v6; // eax
  OnlineManager *v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned __int64 *v11; // [esp-4h] [ebp-1368h]
  _BYTE v12[12]; // [esp+4h] [ebp-1360h] BYREF
  _BYTE v13[12]; // [esp+10h] [ebp-1354h] BYREF
  _BYTE v14[12]; // [esp+1Ch] [ebp-1348h] BYREF
  std::wstring *a2; // [esp+28h] [ebp-133Ch]
  int v16; // [esp+2Ch] [ebp-1338h]
  std::_Iterator_base12 *v17; // [esp+30h] [ebp-1334h]
  std::_Iterator_base12 *v18; // [esp+34h] [ebp-1330h]
  int CurrentSession; // [esp+38h] [ebp-132Ch]
  int v20; // [esp+3Ch] [ebp-1328h]
  int v21; // [esp+40h] [ebp-1324h]
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
    v4 = StormManager::GetInstance();
    CurrentSession = StormManager::GetCurrentSession(v4);
    g_pGameType->m_iActualPlayerCount = GameSessionDescriptor::GetPeerCount(CurrentSession);
    g_pGameType->m_uiTickCounter = GameSessionDescriptor::GetTickCount(CurrentSession);
    this->a = 0;
    this->b = 1;
    std::wstring::operator=(&v28, &g_pGameType->m_swSaveFile);
    CGameChunkGeneral::CGameChunkGeneral(&v26);
    (*(void (__thiscall **)(void *, std::wstring *))(*(_DWORD *)g_pRandomMaps + 52))(g_pRandomMaps, &v28);
    v5 = std::wstring::c_str(&v28);
    CGameRun::LoadGeneralInfo(v5, &v26);
    while ( CClientList::GetSize(this->m_pClientList) )
      CClientList::RemoveClientAt(0);
    CGameType::SetLocalSlot(g_pGameType, v26.m_cLocalSlot);
  }
  else
  {
    v16 = arg0;
    v20 = 0;
    std::list<SGameInfo>::begin(v14);
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
    g_pGameType->m_iActualPlayerCount = *(_DWORD *)(v21 + 604);
    g_pGameType->m_iFileSize = *(_DWORD *)(v21 + 596);
    g_pGameType->m_uiTickCounter = *(_DWORD *)(v21 + 628);
    a2 = (std::wstring *)std::wstring::wstring(&v27, (wchar_t *)(v21 + 648));
    std::wstring::operator=(&v28, a2);
    std::wstring::~wstring(&v27);
    if ( *(_BYTE *)(v21 + 633) )
      std::wstring::operator+=(&v28, (wchar_t *)L"_autoSave");
    std::wstring::operator+=(&v28, (wchar_t *)L".sav");
    CGameChunkGeneral::CGameChunkGeneral(&v25);
    (*(void (__thiscall **)(void *, std::wstring *))(*(_DWORD *)g_pRandomMaps + 52))(g_pRandomMaps, &v28);
    v6 = std::wstring::c_str(&v28);
    CGameRun::LoadGeneralInfo(v6, &v25);
    CGameType::SetLocalSlot(g_pGameType, v25.m_cLocalSlot);
    while ( CClientList::GetSize(this->m_pClientList) )
      CClientList::RemoveClientAt(0);
    v11 = (unsigned __int64 *)(v21 + 640);
    v7 = (OnlineManager *)OnlineManager::GetInstance();
    OnlineManager::JoinSession(v7, v11);
    LOBYTE(v29) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v14);
  }
  *(_DWORD *)this->gap38 = timeGetTime();
  v8 = OnlineManager::GetInstance();
  if ( (unsigned __int8)OnlineManager::IsQuickMatchFlow(v8)
    || (v9 = OnlineManager::GetInstance(), (unsigned __int8)OnlineManager::IsInviteFlow(v9)) )
  {
    CGameHost::StormJoinSessionSucceeded((CClientList **)this);
  }
  v22 = 1;
  v29 = -1;
  std::wstring::~wstring(&v28);
  return v22;
}


// address=[0x15bbdf0]
// Decompiled from char __thiscall CGameHost::ClientJoins(CGameHost *this, void *Src)
bool  CGameHost::ClientJoins(void * Src) {
  
  int v3; // eax
  int NewPlayerID; // [esp-8h] [ebp-90h]
  signed int v5; // [esp+4h] [ebp-84h]
  int v6; // [esp+8h] [ebp-80h]
  unsigned int j; // [esp+Ch] [ebp-7Ch]
  unsigned int v8; // [esp+10h] [ebp-78h]
  int i; // [esp+14h] [ebp-74h]
  wchar_t v11[52]; // [esp+1Ch] [ebp-6Ch] BYREF

  memcpy(v11, Src, 0x65u);
  v8 = *(_DWORD *)((char *)&v11[32] + 1);
  if ( CClientList::ContainsPeerId(this->m_pClientList, *(int *)((char *)&v11[32] + 1)) )
    return 1;
  if ( CGameType::IsSaveGame(g_pGameType) )
  {
    if ( !CLanLobby::ConnectPlayer(v11, SLOBYTE(v11[50])) )
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
        if ( g_pGameType->m_sPlayerPeerId[i] == *(_DWORD *)((char *)&v11[32] + 1) )
        {
          v5 = i;
          break;
        }
      }
    }
    if ( v5 == 8 || !CLanLobby::ConnectPlayer(v11, v5) )
      return 1;
  }
  if ( !CClientList::ContainsPeerId(this->m_pClientList, v8) )
  {
    NewPlayerID = CClientList::CreateNewPlayerID(this->m_pClientList);
    v3 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this->m_pSimpleNet + 36))(this->m_pSimpleNet);
    CClientList::Add(this->m_pClientList, v3, NewPlayerID, v8);
  }
  v6 = -1;
  for ( j = 0; j < g_pGameType->m_iActualPlayerCount && v6 == -1; ++j )
  {
    if ( g_pGameType->m_sPlayerPeerId[j] == v8 )
      v6 = j;
  }
  if ( v6 < 0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2508, "iLocalSlotID >=0") == 1 )
    __debugbreak();
  if ( v6 >= 0 )
    g_pGameType->gap3E6[v6] = 0;
  CLanLobby::RedrawPlayerList();
  CFsm::Control(this->m_pFSM, 1035, 0);
  return 1;
}


// address=[0x15bc010]
// Decompiled from char __stdcall sub_19BC010(int a1)
bool  CGameHost::ClientWrongVersion(void * a1) {
  
  CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2412);
  CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 0);
  return 1;
}


// address=[0x15bc040]
// Decompiled from char __stdcall sub_19BC040(int a1)
bool  CGameHost::ClientWrongVersionAfterLobby(void * a1) {
  
  CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2414);
  CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
  return 1;
}


// address=[0x15bc070]
// Decompiled from char __thiscall CGameHost::ClientReceivePlayerData(CGameHost *this, void *Src)
bool  CGameHost::ClientReceivePlayerData(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  struct CEvn_Event *v4; // [esp+Ch] [ebp-ACh]
  _BYTE v6[120]; // [esp+18h] [ebp-A0h] BYREF
  CEvn_Event v7; // [esp+90h] [ebp-28h] BYREF
  int v8; // [esp+B4h] [ebp-4h]

  MessageLength = CGameHost::GetMessageLength(this);
  memcpy(v6, Src, MessageLength);
  if ( v6[0] && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2685, "data.m_iFinal == PLAYERDATA_UPDATE") == 1 )
    __debugbreak();
  CGameHost::ProcessPlayerData((int)v6);
  if ( this->m_bHasSentMap )
    return 1;
  if ( !CGameType::IsMapAvailable(g_pGameType, &g_pGameType->m_swMapName, g_pGameType->m_iMapCRC)
    && !CGameType::IsSaveGame(g_pGameType)
    && !this->m_bMapBeingDownloaded )
  {
    CGameHost::SendToHost(1042, 0, 0, 0, 0, 1);
    v4 = CEvn_Event::CEvn_Event(&v7, 0x50u, 1u, 0, 0);
    v8 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v4);
    v8 = -1;
    CEvn_Event::~CEvn_Event(&v7);
    if ( this->m_bMapBeingDownloaded && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2699, "!m_bMapBeingDownloaded") == 1 )
      __debugbreak();
    *(_DWORD *)this->m_iMapDownloadLastBlock = g_pGameType->m_iFileSize / 0x300u;
    if ( g_pGameType->m_iFileSize % 0x300u )
      ++*(_DWORD *)this->m_iMapDownloadLastBlock;
    this->m_pMapDownloadBlocks = operator new[](*(_DWORD *)this->m_iMapDownloadLastBlock);
    memset((void *)this->m_pMapDownloadBlocks, 0, *(_DWORD *)this->m_iMapDownloadLastBlock);
    this->m_pMapDownloadData = operator new[](g_pGameType->m_iFileSize);
    this->m_iMapDownloadBlocksArrived = 0;
    this->m_bMapBeingDownloaded = 1;
    CTrace::Print(
      "GameHost.cpp: Map download scheduled. Waiting for %d bytes in %d blocks.!",
      g_pGameType->m_iFileSize,
      *(_DWORD *)this->m_iMapDownloadLastBlock);
  }
  this->m_bHasSentMap = 1;
  return 1;
}


// address=[0x15bc320]
// Decompiled from char __thiscall CGameHost::ClientReceivePlayerPing(void *this, void *Src)
bool  CGameHost::ClientReceivePlayerPing(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  unsigned __int8 v4; // [esp+0h] [ebp-Ch] BYREF
  int v5; // [esp+1h] [ebp-Bh]
  void *v6; // [esp+8h] [ebp-4h]

  v6 = this;
  MessageLength = CGameHost::GetMessageLength(this);
  memcpy(&v4, Src, MessageLength);
  *(_DWORD *)(g_pGameType + 4 * v4 + 624) = v5;
  CLanLobby::RedrawPlayerList();
  return 1;
}


// address=[0x15bc370]
// Decompiled from char __thiscall sub_19BC370(void *this, int a2)
bool  CGameHost::ClientLobbyPrepare(void * a2) {
  
  std::list<SGameInfo>::clear(this);
  CGameStateHandler::Switch(CStateLobbyGameSettings::DynamicCreateFunc, 0);
  return 0;
}


// address=[0x15bc3a0]
// Decompiled from char __thiscall CGameHost::ResendPlayerData(void *this, int a2)
bool  CGameHost::ResendPlayerData(void * a2) {
  
  CGameHost::SendPlayerData(this, 0);
  return 1;
}


// address=[0x15bc3c0]
// Decompiled from char __thiscall CGameHost::ResendPlayerPing(_DWORD *this, int a2)
bool  CGameHost::ResendPlayerPing(void * a2) {
  
  _BYTE Src[8]; // [esp+0h] [ebp-10h] BYREF
  _DWORD *v4; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v4 = this;
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
  {
    memset(Src, 0, 5u);
    Src[0] = i;
    *(_DWORD *)&Src[1] = *(_DWORD *)(g_pGameType + 4 * i + 624);
    CGameHost::SendToAll((int)v4, 1034, Src, 5u, 0, 0, 1u);
  }
  v4[8] = timeGetTime();
  return 1;
}


// address=[0x15bc450]
// Decompiled from char __stdcall CGameHost::HostPressedStart(int a1)
bool  CGameHost::HostPressedStart(void * a1) {
  
  int MultiPlayerGameID; // eax
  int v3; // [esp-10h] [ebp-41Ch]
  int v4; // [esp-Ch] [ebp-418h]
  int v5; // [esp-4h] [ebp-410h]
  int i; // [esp+4h] [ebp-408h]
  char Buffer[1024]; // [esp+8h] [ebp-404h] BYREF

  CFsm::GenerateEvent(1030, 0);
  if ( !(unsigned __int8)CGameType::IsWebGame(g_pGameType)
    || (unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType) )
  {
    return 0;
  }
  for ( i = 0; *(_DWORD *)(g_pGameType + 4 * i + 188) != *(_DWORD *)(g_pGameType + 68); ++i )
    ;
  v5 = *(_DWORD *)(g_pGameType + 4 * i + 332);
  v4 = *(_DWORD *)(g_pGameType + 4 * i + 404);
  v3 = *(_DWORD *)(g_pGameType + 4 * i + 224);
  MultiPlayerGameID = CGameType::GetMultiPlayerGameID(g_pGameType);
  sprintf(
    Buffer,
    "{ ? = CALL proc_addtogame_playerclan( %d, %d, %d, 1, '%s', %d, '' ) }",
    MultiPlayerGameID,
    v3,
    v4,
    "Team",
    v5);
  return 0;
}


// address=[0x15bc560]
// Decompiled from char __thiscall sub_19BC560(int this, void *Src)
bool  CGameHost::InitGameStruct(void * Src) {
  
  int v2; // eax
  unsigned __int16 v3; // ax
  _BYTE v6[120]; // [esp+4h] [ebp-7Ch] BYREF

  if ( !*(_DWORD *)(this + 188) )
  {
    CTrace::Print("GameHost.cpp: Clearing client list...");
    while ( 1 )
    {
      CClientList::GetSize(*(CDaoIndexFieldInfo **)(this + 16));
      if ( !v2 )
        break;
      CClientList::RemoveClientAt(0);
    }
  }
  if ( Src )
  {
    v3 = CGameHost::GetMessageLength((void *)this);
    memcpy(v6, Src, v3);
    if ( v6[0] != 1
      && BBSupportDbgReport(2, (int)"Net\\GameHost.cpp", 3163, (int)"data.m_iFinal == PLAYERDATA_FINAL") == 1 )
    {
      __debugbreak();
    }
    if ( v6[0] == 1 )
    {
      CGameHost::ProcessPlayerData((int)v6);
      *(_DWORD *)(g_pGameType + 620) = v6[1];
      *(_DWORD *)(g_pGameType + 112) = v6[2];
      ++*(_DWORD *)(this + 188);
    }
  }
  if ( *(_DWORD *)(this + 188) == *(_DWORD *)(g_pGameType + 112) )
    CFsm::GenerateEvent(1031, 0);
  return 1;
}


// address=[0x15bc680]
// Decompiled from char __thiscall sub_19BC680(int this, int a2)
bool  CGameHost::ResendFinalPData(void * a2) {
  
  int v2; // eax
  int v3; // eax

  if ( *(_BYTE *)(this + 10) )
  {
    CGameHost::SendPlayerData((void *)this, 1);
    while ( 1 )
    {
      CClientList::GetSize(*(CDaoIndexFieldInfo **)(this + 16));
      if ( !v2 )
        break;
      CClientList::RemoveClientAt(0);
    }
    CClientList::GetSize(*(CDaoIndexFieldInfo **)(this + 16));
    if ( v3 && BBSupportDbgReport(2, (int)"Net\\GameHost.cpp", 3124, (int)"!m_pClientList->GetSize()") == 1 )
      __debugbreak();
    CFsm::GenerateEvent(1012, 0);
  }
  else
  {
    CFsm::GenerateEvent(1013, 0);
  }
  return 1;
}


// address=[0x15bc720]
// Decompiled from char __thiscall CGameHost::ChatLine(_BYTE *this, void *Src)
bool  CGameHost::ChatLine(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  wchar_t String[32]; // [esp+4h] [ebp-104h] BYREF
  wchar_t Source[96]; // [esp+44h] [ebp-C4h] BYREF

  MessageLength = CGameHost::GetMessageLength(this);
  memcpy(String, Src, MessageLength);
  if ( this[8] )
    CGameHost::SendToAll((int)this, 1036, String, 0x100u, 0, 0, 1u);
  CLanLobby::PrintChatLine(String, Source);
  return 1;
}


// address=[0x15bc7c0]
// Decompiled from char __stdcall sub_19BC7C0(int a1)
bool  CGameHost::GameAlreadyFull(void * a1) {
  
  CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, 2410);
  CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 0);
  return 1;
}


// address=[0x15bc7f0]
// Decompiled from char __thiscall CGameHost::SendMapToClient(CGameHost *this, int _iClient)
bool  CGameHost::SendMapToClient(void * _iClient) {
  
  unsigned int v2; // eax
  struct CEvn_Event *v4; // [esp+8h] [ebp-4E0h]
  int v5; // [esp+14h] [ebp-4D4h]
  int v6; // [esp+18h] [ebp-4D0h]
  struct CEvn_Event *v7; // [esp+1Ch] [ebp-4CCh]
  int v8; // [esp+2Ch] [ebp-4BCh]
  int Slot; // [esp+30h] [ebp-4B8h]
  int iSlot; // [esp+38h] [ebp-4B0h]
  __int16 v12; // [esp+40h] [ebp-4A8h] BYREF
  int v13; // [esp+42h] [ebp-4A6h]
  _BYTE v14[1022]; // [esp+46h] [ebp-4A2h] BYREF
  CFile v15; // [esp+444h] [ebp-A4h] BYREF
  CEvn_Event v16; // [esp+48Ch] [ebp-5Ch] BYREF
  CEvn_Event v17; // [esp+4A4h] [ebp-44h] BYREF
  std::wstring a1; // [esp+4BCh] [ebp-2Ch] BYREF
  int v19; // [esp+4E4h] [ebp-4h]

  if ( _iClient )
  {
    v2 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this->m_pSimpleNet + 36))(this->m_pSimpleNet);
    Slot = CGameHost::GetSlot(this, v2);
    if ( this->field_98[Slot] )
    {
      return 1;
    }
    else
    {
      this->field_98[Slot] = operator new[](g_pGameType->m_iFileSize);
      std::wstring::wstring(&a1, &g_pGameType->m_swMapName);
      v19 = 0;
      CFile::CFile(&v15);
      LOBYTE(v19) = 1;
      CFile::Open(&v15, &a1, CFile_BINARY|CFile_READ, UNUSED_ARG(), UNUSED_ARG());
      CFile::Read(&v15, (void *)this->field_98[Slot], g_pGameType->m_iFileSize, 1u, UNUSED_ARG(), UNUSED_ARG());
      CFile::Close(&v15, UNUSED_ARG(), UNUSED_ARG());
      if ( ++this->m_iMapUpload == 1 )
      {
        v7 = CEvn_Event::CEvn_Event(&v17, 80u, 1u, 0, 0);
        LOBYTE(v19) = 2;
        IEventEngine::SendAMessage(g_pEvnEngine, v7);
        LOBYTE(v19) = 1;
        CEvn_Event::~CEvn_Event(&v17);
      }
      if ( this->m_iMapUpload >= 7
        && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2749, "m_iMapUpload < MAX_PLAYER - 1") == 1 )
      {
        __debugbreak();
      }
      this->field_78[Slot] = g_pGameType->m_iFileSize / 0x300u;
      if ( g_pGameType->m_iFileSize % 0x300u )
        ++this->field_78[Slot];
      g_pGameType->m_sPlayerSlot11[Slot] = 1;
      LOBYTE(v19) = 0;
      CFile::~CFile(&v15);
      v19 = -1;
      std::wstring::~wstring(&a1);
      return 1;
    }
  }
  else
  {
    for ( iSlot = 0; iSlot < 8; ++iSlot )
    {
      if ( this->field_98[iSlot] )
      {
        if ( g_pGameType->m_sPlayerIP[iSlot] == (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this->m_pSimpleNet + 16))(this->m_pSimpleNet)
          && BBSupportDbgReport(
               2,
               "Net\\GameHost.cpp",
               2766,
               "g_pGameType->m_uiIPPlayer[ iSlot ] != m_pSimpleNet->GetCurrentLocalIPLong()") == 1 )
        {
          __debugbreak();
        }
        v12 = 1043;
        v6 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this->m_pSimpleNet + 36))(this->m_pSimpleNet);
        v5 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)this->m_pSimpleNet + 40))(this->m_pSimpleNet);
        if ( this->field_58[iSlot] >= this->field_78[iSlot] )
        {
          if ( this->field_98[iSlot] )
          {
            operator delete((void *)this->field_98[iSlot]);
            this->field_98[iSlot] = 0;
          }
          this->field_58[iSlot] = 0;
          if ( !--this->m_iMapUpload )
          {
            v4 = CEvn_Event::CEvn_Event(&v16, 0x50u, 0, 0, 0);
            v19 = 3;
            IEventEngine::SendAMessage(g_pEvnEngine, v4);
            v19 = -1;
            CEvn_Event::~CEvn_Event(&v16);
          }
          if ( this->m_iMapUpload < 0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2804, "m_iMapUpload >= 0") == 1 )
            __debugbreak();
          g_pGameType->m_sPlayerSlot11[iSlot] = 0;
        }
        else
        {
          v13 = this->field_58[iSlot];
          v8 = 768 * this->field_58[iSlot];
          if ( (unsigned int)(v8 + 768) <= g_pGameType->m_iFileSize )
            memcpy(v14, (const void *)(v8 + this->field_98[iSlot]), 0x300u);
          else
            memcpy(v14, (const void *)(v8 + this->field_98[iSlot]), g_pGameType->m_iFileSize - v8);
          (*(void (__thiscall **)(_DWORD, int, int, int, __int16 *, int, int, int))(*(_DWORD *)this->m_pSimpleNet + 32))(
            this->m_pSimpleNet,
            v5,
            v6,
            3105,
            &v12,
            774,
            1,
            1);
          CTrace::Print("GameHost.cpp: Map block sent. Block %d!", v13);
          ++this->field_58[iSlot];
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
  int dword44; // [esp-20h] [ebp-6FCh]
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
  _DWORD v29[193]; // [esp+334h] [ebp-3A8h] BYREF
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
          dword44 = g_pGameType->dword44;
          v8 = 0;
          v19 = &v7;
          v18 = std::wstring::wstring(&v7, &g_pGameType->m_swMapName);
          CGameType::LoadMapData(g_pGameType, v7, v8, dword44, v10, v11, v12, v13, v14, bIsLadder, bIsClan);
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
    memcpy(v29, _pMessage, v5);
    CTrace::Print("GameHost.cpp: Mapdata block %d without request got !!", v29[0]);
  }
  return 1;
}


// address=[0x15bd220]
// Decompiled from char __thiscall RemoveClient(_DWORD **this, int a2)
bool  CGameHost::ClientLeavesMyGame(void * a2) {
  
  int v3; // [esp+0h] [ebp-8h]

  v3 = (*(int (__thiscall **)(_DWORD *))(*this[49] + 40))(this[49]);
  CLanLobby::DisconnectPlayerPeerId(v3, -1);
  if ( !(unsigned __int8)CClientList::RemoveClientPeerId(v3) )
    CTrace::Print("GameHost.cpp: Unable to removed client!");
  CLanLobby::RedrawPlayerList();
  return 1;
}


// address=[0x15bd290]
// Decompiled from char __thiscall sub_19BD290(void *this, int a2)
bool  CGameHost::PerformLeaveGame(void * a2) {
  
  int v2; // eax

  v2 = OnlineManager::GetInstance(this);
  OnlineManager::LeaveSession(v2);
  return 1;
}


// address=[0x15bd2b0]
// Decompiled from char __thiscall CGameHost::SendChatLine(_BYTE *this, wchar_t *Source)
bool  CGameHost::SendChatLine(void * Source) {
  
  _DWORD *v2; // eax
  wchar_t *v3; // eax
  _Cnd_internal_imp_t *v5; // [esp+4h] [ebp-15Ch]
  _Cnd_internal_imp_t *PlayerName; // [esp+Ch] [ebp-154h]
  _BYTE Src[256]; // [esp+18h] [ebp-148h] BYREF
  _BYTE v9[28]; // [esp+118h] [ebp-48h] BYREF
  _BYTE v10[28]; // [esp+134h] [ebp-2Ch] BYREF
  int v11; // [esp+15Ch] [ebp-4h]

  memset(Src, 0, sizeof(Src));
  MyWStrNCopy((int)&Src[64], (int)Source, 192);
  PlayerName = (_Cnd_internal_imp_t *)CGameSettings::GetPlayerName((int)v10);
  v11 = 0;
  v2 = std::wstring::c_str(PlayerName);
  MyWStrNCopy((int)Src, (int)v2, 64);
  v11 = -1;
  std::wstring::~wstring(v10);
  if ( this[8] )
  {
    CGameHost::SendToAll((int)this, 1036, Src, 0x100u, 0, 0, 1u);
    v5 = (_Cnd_internal_imp_t *)CGameSettings::GetPlayerName((int)v9);
    v11 = 1;
    v3 = (wchar_t *)std::wstring::c_str(v5);
    CLanLobby::PrintChatLine(v3, Source);
    v11 = -1;
    std::wstring::~wstring(v9);
  }
  else
  {
    CGameHost::SendToHost(1036, Src, 0x100u, 0, 0, 1);
  }
  return 1;
}


// address=[0x15bd420]
// Decompiled from char __thiscall CGameHost::UserDataChange(CGameHost *this, int *a2)
bool  CGameHost::UserDataChange(void * a2) {
  
  int v4; // [esp+8h] [ebp-14h]
  int v5; // [esp+Ch] [ebp-10h]
  int i; // [esp+14h] [ebp-8h]

  switch ( a2[1] )
  {
    case 0:
      do
      {
        if ( a2[2] == 6 )
        {
          if ( --*(_DWORD *)(g_pGameType + 4 * *a2 + 332) == -1 )
            *(_DWORD *)(g_pGameType + 4 * *a2 + 332) = 7;
        }
        else if ( ++*(_DWORD *)(g_pGameType + 4 * *a2 + 332) == 8 )
        {
          *(_DWORD *)(g_pGameType + 4 * *a2 + 332) = 0;
        }
      }
      while ( !CGameHost::IsExclusiveColor(this, *a2) );
      break;
    case 1:
      if ( *(_BYTE *)(g_pGameType + *a2 + 1007) )
      {
        if ( a2[2] == 6 )
        {
          if ( *(_DWORD *)(g_pGameType + 4 * *a2 + 404) )
            --*(_DWORD *)(g_pGameType + 4 * *a2 + 404);
          else
            *(_DWORD *)(g_pGameType + 4 * *a2 + 404) = 5;
          while ( *(_DWORD *)(g_pGameType + 4 * *a2 + 404) == 3
               || *(_DWORD *)(g_pGameType + 4 * *a2 + 404) == 4 && (g_uiExtrasAllowed & 1) == 0 )
            --*(_DWORD *)(g_pGameType + 4 * *a2 + 404);
        }
        else
        {
          if ( *(_DWORD *)(g_pGameType + 4 * *a2 + 404) == 5 )
            *(_DWORD *)(g_pGameType + 4 * *a2 + 404) = 0;
          else
            ++*(_DWORD *)(g_pGameType + 4 * *a2 + 404);
          while ( *(_DWORD *)(g_pGameType + 4 * *a2 + 404) == 3
               || *(_DWORD *)(g_pGameType + 4 * *a2 + 404) == 4 && (g_uiExtrasAllowed & 1) == 0 )
          {
            if ( ++*(_DWORD *)(g_pGameType + 4 * *a2 + 404) == 6 )
              *(_DWORD *)(g_pGameType + 4 * *a2 + 404) = 0;
          }
        }
      }
      break;
    case 2:
      if ( a2[2] == 6 )
      {
        if ( --*(_DWORD *)(g_pGameType + 4 * *a2 + 152) == -1 )
          *(_DWORD *)(g_pGameType + 4 * *a2 + 152) = *(_DWORD *)(g_pGameType + 72) - 1;
      }
      else if ( a2[2] == 7 && ++*(_DWORD *)(g_pGameType + 4 * *a2 + 152) == *(_DWORD *)(g_pGameType + 72) )
      {
        *(_DWORD *)(g_pGameType + 4 * *a2 + 152) = 0;
      }
      break;
    case 4:
      if ( a2[2] == 6 )
      {
        if ( --*(_DWORD *)(g_pGameType + 4 * *a2 + 368) == -1 )
          *(_DWORD *)(g_pGameType + 4 * *a2 + 368) = 7;
      }
      else if ( ++*(_DWORD *)(g_pGameType + 4 * *a2 + 368) == 8 )
      {
        *(_DWORD *)(g_pGameType + 4 * *a2 + 368) = 0;
      }
      break;
    case 5:
      if ( a2[2] )
        v5 = 6;
      else
        v5 = 0;
      *(_DWORD *)(g_pGameType + 4 * *a2 + 452) = v5;
      break;
    case 9:
      v4 = 0;
      for ( i = 0; i < 8; ++i )
      {
        if ( *(_DWORD *)(g_pGameType + 4 * i + 564) == *a2 )
          v4 = i;
      }
      if ( *a2 == a2[2] )
      {
        *(_DWORD *)(g_pGameType + 4 * v4 + 564) = -1;
        *(_DWORD *)(g_pGameType + 4 * *a2 + 564) = -1;
      }
      else
      {
        *(_DWORD *)(g_pGameType + 4 * *a2 + 564) = a2[2];
      }
      break;
    default:
      CTrace::Print("GameHost: Invalid Change Type %d from Slot %d!", a2[1], *a2);
      break;
  }
  CLanLobby::RedrawPlayerList();
  return 1;
}


// address=[0x15bd980]
// Decompiled from char __thiscall CGameHost::KickClient(_DWORD **this, int a2)
bool  CGameHost::KickClient(void * a2) {
  
  DWORD v4; // [esp+4h] [ebp-Ch]
  __int16 v5; // [esp+Ch] [ebp-4h] BYREF

  v4 = g_pGameType->m_sPlayerPeerId[a2];
  CLanLobby::DisconnectPlayerPeerId(v4, -1);
  CClientList::RemoveClientPeerId((CClientList *)this[4], v4);
  g_pGameType->gap3E6[a2] = 1;
  v5 = 1053;
  (*(void (__thiscall **)(_DWORD *, DWORD, DWORD, int, __int16 *, int, _DWORD, int))(*this[49] + 32))(
    this[49],
    v4,
    g_pGameType->m_sPlayerIP[a2],
    3105,
    &v5,
    2,
    0,
    1);
  CLanLobby::RedrawPlayerList();
  return 1;
}


// address=[0x15bda30]
// Decompiled from char __thiscall sub_19BDA30(void *this, int a2)
bool  CGameHost::WereKicked(void * a2) {
  
  void *v2; // eax

  v2 = (void *)OnlineManager::GetInstance((int)this);
  OnlineManager::LeaveSession(v2);
  CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2494);
  CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 0);
  return 1;
}


// address=[0x15bda70]
// Decompiled from char __thiscall CGameHost::UserChangeSlots(CGameHost *this, unsigned int *a2)
bool  CGameHost::UserChangeSlots(void * a2) {
  
  int RealPlayerName; // eax
  int v3; // eax
  int v5; // [esp+Ch] [ebp-94h]
  int v6; // [esp+10h] [ebp-90h]
  int v7; // [esp+14h] [ebp-8Ch]
  int v8; // [esp+18h] [ebp-88h]
  int v9; // [esp+1Ch] [ebp-84h]
  int v10; // [esp+20h] [ebp-80h]
  void *PlayerClanShortcut; // [esp+24h] [ebp-7Ch]
  char v12; // [esp+32h] [ebp-6Eh]
  char v13; // [esp+33h] [ebp-6Dh]
  int v14; // [esp+34h] [ebp-6Ch]
  unsigned int v15; // [esp+38h] [ebp-68h]
  _BYTE v16[28]; // [esp+3Ch] [ebp-64h] BYREF
  _BYTE v17[28]; // [esp+58h] [ebp-48h] BYREF
  _BYTE v18[28]; // [esp+74h] [ebp-2Ch] BYREF
  int v19; // [esp+9Ch] [ebp-4h]

  v15 = *a2;
  v14 = a2[2];
  if ( (*a2 & 0x80000000) == 0 && v14 >= 0 )
  {
    if ( v14 == CGameType::GetLocalSlot(g_pGameType) )
      CGameType::ChangeLocalSlot((CGameType *)g_pGameType, v15);
    if ( v15 == CGameType::GetLocalSlot(g_pGameType) )
      CGameType::ChangeLocalSlot((CGameType *)g_pGameType, v14);
    v10 = *(_DWORD *)(g_pGameType + 4 * v15 + 116);
    v9 = *(_DWORD *)(g_pGameType + 4 * v15 + 188);
    v8 = *(_DWORD *)(g_pGameType + 4 * v15 + 224);
    v7 = *(_DWORD *)(g_pGameType + 4 * v15 + 332);
    v13 = *(_BYTE *)(v15 + g_pGameType + 440);
    v6 = *(_DWORD *)(g_pGameType + 4 * v15 + 452);
    v5 = *(_DWORD *)(g_pGameType + 4 * v15 + 624);
    v12 = *(_BYTE *)(v15 + g_pGameType + 998);
    RealPlayerName = CGameType::GetRealPlayerName((void *)g_pGameType, v15);
    std::wstring::wstring(RealPlayerName);
    v19 = 0;
    CGameType::GetPlayerClanShortcut((void *)g_pGameType, v18, v15);
    LOBYTE(v19) = 1;
    *(_DWORD *)(g_pGameType + 4 * v15 + 116) = *(_DWORD *)(g_pGameType + 4 * v14 + 116);
    *(_DWORD *)(g_pGameType + 4 * v15 + 188) = *(_DWORD *)(g_pGameType + 4 * v14 + 188);
    *(_DWORD *)(g_pGameType + 4 * v15 + 224) = *(_DWORD *)(g_pGameType + 4 * v14 + 224);
    *(_DWORD *)(g_pGameType + 4 * v15 + 332) = *(_DWORD *)(g_pGameType + 4 * v14 + 332);
    *(_BYTE *)(v15 + g_pGameType + 440) = *(_BYTE *)(v14 + g_pGameType + 440);
    *(_DWORD *)(g_pGameType + 4 * v15 + 452) = *(_DWORD *)(g_pGameType + 4 * v14 + 452);
    *(_DWORD *)(g_pGameType + 4 * v15 + 624) = *(_DWORD *)(g_pGameType + 4 * v14 + 624);
    *(_BYTE *)(v15 + g_pGameType + 998) = *(_BYTE *)(v14 + g_pGameType + 998);
    *(_DWORD *)(g_pGameType + 4 * v15 + 564) = -1;
    v3 = CGameType::GetRealPlayerName((void *)g_pGameType, v14);
    CGameType::SetPlayerName(v15, v3);
    PlayerClanShortcut = CGameType::GetPlayerClanShortcut((void *)g_pGameType, v16, v14);
    LOBYTE(v19) = 2;
    CGameType::SetPlayerClanShortcut(v15, PlayerClanShortcut);
    LOBYTE(v19) = 1;
    std::wstring::~wstring(v16);
    *(_DWORD *)(g_pGameType + 4 * v14 + 116) = v10;
    *(_DWORD *)(g_pGameType + 4 * v14 + 188) = v9;
    *(_DWORD *)(g_pGameType + 4 * v14 + 224) = v8;
    *(_DWORD *)(g_pGameType + 4 * v14 + 332) = v7;
    *(_BYTE *)(v14 + g_pGameType + 440) = v13;
    *(_DWORD *)(g_pGameType + 4 * v14 + 452) = v6;
    *(_DWORD *)(g_pGameType + 4 * v14 + 624) = v5;
    *(_BYTE *)(v14 + g_pGameType + 998) = v12;
    *(_DWORD *)(g_pGameType + 4 * v14 + 564) = -1;
    CGameType::SetPlayerName(v14, (int)v17);
    CGameType::SetPlayerClanShortcut(v14, v18);
    LOBYTE(v19) = 0;
    std::wstring::~wstring(v18);
    v19 = -1;
    std::wstring::~wstring(v17);
  }
  CLanLobby::RedrawPlayerList();
  return 1;
}


// address=[0x15bde60]
// Decompiled from char __thiscall sub_19BDE60(_BYTE *this, int a2)
bool  CGameHost::InitHostAfterLobby(void * a2) {
  
  this[8] = 1;
  CFsm::GenerateEvent(1009, 0);
  return 1;
}


// address=[0x15bde90]
// Decompiled from char __thiscall sub_19BDE90(_BYTE *this, int a2)
bool  CGameHost::InitClientAfterLobby(void * a2) {
  
  this[9] = 1;
  CFsm::GenerateEvent(1010, 0);
  return 1;
}


// address=[0x15bdec0]
// Decompiled from char __thiscall CGameHost::WaitingForGameConnect(_BYTE *this, void *Src)
bool  CGameHost::WaitingForGameConnect(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  unsigned int v3; // eax
  int v4; // eax
  int MultiPlayerGameID; // eax
  int v6; // eax
  int v8; // [esp-10h] [ebp-49Ch]
  int v9; // [esp-Ch] [ebp-498h]
  int v10; // [esp-4h] [ebp-490h]
  int v11; // [esp+4h] [ebp-488h] BYREF
  unsigned int v12; // [esp+8h] [ebp-484h]
  unsigned int i; // [esp+Ch] [ebp-480h]
  int j; // [esp+10h] [ebp-47Ch]
  char v15; // [esp+17h] [ebp-475h]
  void *v16; // [esp+18h] [ebp-474h]
  char v17; // [esp+1Fh] [ebp-46Dh]
  _BYTE v18[69]; // [esp+20h] [ebp-46Ch] BYREF
  int v19; // [esp+65h] [ebp-427h]
  int v20; // [esp+69h] [ebp-423h]
  int v21; // [esp+6Dh] [ebp-41Fh]
  int v22; // [esp+71h] [ebp-41Bh]
  int v23; // [esp+75h] [ebp-417h]
  char Buffer[1024]; // [esp+88h] [ebp-404h] BYREF

  v16 = this;
  if ( this[10] )
  {
    if ( Src )
    {
      v12 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)v16 + 49) + 40))(*((_DWORD *)v16 + 49));
      MessageLength = CGameHost::GetMessageLength(v16);
      memcpy(v18, Src, MessageLength);
      v17 = 1;
      if ( v19 != g_iFileVersionMS || v20 != g_iFileVersionLS )
        v17 = 0;
      if ( v21 != g_iConfigVersion )
      {
        CTrace::Print("GameHost: Config files CRC mismatch!");
        v17 = 0;
      }
      if ( v22 != g_iScriptVersion )
      {
        CTrace::Print("GameHost: Script files CRC mismatch!");
        v17 = 0;
      }
      if ( v23 != g_iGfxVersion )
      {
        CTrace::Print("GameHost: Gfx index files CRC mismatch!");
        v17 = 0;
      }
      if ( CClientList::ContainsPeerId(*((CClientList **)v16 + 4), v12) )
      {
        CTrace::Print("CGameHost: RegConnect for Peer already got !!");
      }
      else
      {
        v15 = 0;
        for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
        {
          if ( *(_DWORD *)(g_pGameType + 4 * i + 224) == v12 )
          {
            v15 = 1;
            break;
          }
        }
        if ( v15 )
        {
          v3 = (*(int (__thiscall **)(_DWORD, unsigned int, unsigned int))(**((_DWORD **)v16 + 49) + 36))(
                 *((_DWORD *)v16 + 49),
                 i,
                 v12);
          CClientList::Add(*((CClientList **)v16 + 4), v3);
          v11 = 1;
          v4 = (*(int (__thiscall **)(_DWORD, int, int *, int))(**((_DWORD **)v16 + 49) + 36))(
                 *((_DWORD *)v16 + 49),
                 3105,
                 &v11,
                 2);
          (*(void (__thiscall **)(_DWORD, unsigned int, int))(**((_DWORD **)v16 + 49) + 32))(
            *((_DWORD *)v16 + 49),
            v12,
            v4);
          for ( j = 0; j < 9 && *(_DWORD *)(g_pGameType + 4 * j + 224) != v12; ++j )
            ;
          if ( j == 8 )
            j = 0;
          v10 = *(_DWORD *)(g_pGameType + 4 * j + 332);
          v9 = *(_DWORD *)(g_pGameType + 4 * j + 404);
          v8 = *(_DWORD *)(g_pGameType + 4 * j + 224);
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
      CClientList::GetSize(*((CDaoIndexFieldInfo **)v16 + 4));
      if ( v6 == CGameType::HumanPlayers((CGameType *)g_pGameType) - 1 )
        CFsm::GenerateEvent(1014, 0);
    }
  }
  else
  {
    CFsm::GenerateEvent(1014, 0);
  }
  return 1;
}


// address=[0x15be220]
// Decompiled from char __thiscall CGameHost::HostInitGame(int this, int a2)
bool  CGameHost::HostInitGame(void * a2) {
  
  int v2; // eax
  int v4; // [esp+8h] [ebp-40h]
  int i; // [esp+10h] [ebp-38h]
  unsigned int j; // [esp+18h] [ebp-30h]
  CEvn_Event v8; // [esp+20h] [ebp-28h] BYREF
  int v9; // [esp+44h] [ebp-4h]

  if ( *(_BYTE *)(this + 10) )
  {
    for ( i = 0; ; ++i )
    {
      CClientList::GetSize(*(CDaoIndexFieldInfo **)(this + 16));
      if ( i >= v2 )
        break;
      CGameHost::SendToAll(this, 1017, 0, 0, 0, 0, 1u);
    }
  }
  v9 = 0;
  if ( operator new(0x65Cu) )
    v4 = CMsgStacks::CMsgStacks(
           *(_DWORD *)(g_pGameType + 112),
           *(_DWORD *)(g_pGameType + 660) / 0x47u,
           *(_DWORD *)(g_pGameType + 700));
  else
    v4 = 0;
  v9 = -1;
  *(_DWORD *)(this + 20) = v4;
  for ( j = 0; j < *(_DWORD *)(g_pGameType + 112); ++j )
  {
    if ( *(_DWORD *)(g_pGameType + 4 * j + 116) == 2 || *(_DWORD *)(g_pGameType + 4 * j + 116) == 3 )
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
// Decompiled from char __thiscall sub_19BE3C0(_DWORD **this, int a2)
bool  CGameHost::HostStartTick(void * a2) {
  
  _BYTE v3[24]; // [esp+Ch] [ebp-28h] BYREF
  int v4; // [esp+30h] [ebp-4h]

  (*(void (__thiscall **)(_DWORD *))(*this[49] + 60))(this[49]);
  CEvn_Event::CEvn_Event(25, 0, 0, 0);
  v4 = 0;
  IEventEngine::SendAMessage(v3);
  v4 = -1;
  CEvn_Event::~CEvn_Event(v3);
  return 1;
}


// address=[0x15be460]
// Decompiled from char __thiscall CGameHost::RegClientConnect(int this, int a2)
bool  CGameHost::RegClientConnect(void * a2) {
  
  int Instance; // eax
  wchar_t *v3; // eax
  int v5; // eax
  const char *v6; // eax
  int m_uUC; // [esp+0h] [ebp-98h]
  std::wstring *PlayerName; // [esp+4h] [ebp-94h]
  int i; // [esp+Ch] [ebp-8Ch]
  int j; // [esp+Ch] [ebp-8Ch]
  std::wstring v12; // [esp+10h] [ebp-88h] BYREF
  wchar_t Destination[32]; // [esp+2Ch] [ebp-6Ch] BYREF
  char v14; // [esp+6Ch] [ebp-2Ch]
  int LocalPeerId; // [esp+6Dh] [ebp-2Bh]
  int v16; // [esp+71h] [ebp-27h]
  int v17; // [esp+75h] [ebp-23h]
  int v18; // [esp+79h] [ebp-1Fh]
  int v19; // [esp+7Dh] [ebp-1Bh]
  int v20; // [esp+81h] [ebp-17h]
  char IsWebGame; // [esp+89h] [ebp-Fh]

  if ( a2 == 1 )
  {
    v14 = 1;
    Instance = StormManager::GetInstance();
    LocalPeerId = StormManager::GetLocalPeerId(Instance);
    v16 = g_iFileVersionMS;
    v17 = g_iFileVersionLS;
    v18 = g_iConfigVersion;
    v19 = g_iScriptVersion;
    v20 = g_iGfxVersion;
    IsWebGame = CGameType::IsWebGame(g_pGameType);
    PlayerName = (std::wstring *)CGameSettings::GetPlayerName((int)&v12);
    v3 = std::wstring::c_str(PlayerName);
    wcsncpy(Destination, v3, 0x1Fu);
    std::wstring::~wstring(&v12);
    Destination[31] = 0;
    CGameHost::SendToHost(1013, Destination, 0x65u, 0, 0, 1);
    return 1;
  }
  else
  {
    m_uUC = g_pGameType[2].?;
    if ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 36))(*(_DWORD *)(this + 196)) )
    {
      g_pGameType[2].? = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 36))(*(_DWORD *)(this + 196));
      for ( i = 0; i < 9; ++i )
      {
        if ( *(&g_pGameType[6].? + i) == m_uUC )
          *(&g_pGameType[6].? + i) = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 36))(*(_DWORD *)(this + 196));
      }
    }
    if ( CClientList::GetSize(*(CDaoIndexFieldInfo **)(this + 16))
      && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4254, "m_pClientList->GetSize() == 0") == 1 )
    {
      __debugbreak();
    }
    CTrace::Print("GameHost.cpp: Filling client list !!");
    for ( j = 0; j < 9; ++j )
    {
      if ( *(&g_pGameType[8].m_u + j) != -1 )
      {
        v5 = StormManager::GetInstance();
        if ( *(&g_pGameType[8].m_u + j) != StormManager::GetLocalPeerId(v5) )
        {
          CClientList::Add(*(CClientList **)(this + 16), *(&g_pGameType[6].? + j), j, *(&g_pGameType[8].m_u + j));
          v6 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 196) + 48))(
                               *(_DWORD *)(this + 196),
                               *(&g_pGameType[6].? + j));
          CTrace::Print("GameHost.cpp: Adding client %s to list !", v6);
        }
      }
    }
    return 1;
  }
}


// address=[0x15be750]
// Decompiled from char __stdcall sub_19BE750(int a1)
bool  CGameHost::WereConnectedForGame(void * a1) {
  
  return 1;
}


// address=[0x15be760]
// Decompiled from char __thiscall CGameHost::ClientStartingGame(_DWORD *this, int a2)
bool  CGameHost::ClientStartingGame(void * a2) {
  
  int v4; // [esp+Ch] [ebp-38h]
  unsigned int i; // [esp+14h] [ebp-30h]
  CEvn_Event v6; // [esp+1Ch] [ebp-28h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  v7 = 0;
  if ( operator new(1628u) )
    v4 = CMsgStacks::CMsgStacks(
           *(_DWORD *)(g_pGameType + 112),
           *(_DWORD *)(g_pGameType + 660) / 0x47u,
           *(_DWORD *)(g_pGameType + 700));
  else
    v4 = 0;
  v7 = -1;
  this[5] = v4;
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
  {
    if ( *(_DWORD *)(g_pGameType + 4 * i + 116) == 2 || *(_DWORD *)(g_pGameType + 4 * i + 116) == 3 )
      CMsgStacks::SetStackAI(i, 1);
  }
  CEvn_Event::CEvn_Event(&v6, 0x18u, (unsigned int)&g_pGameType, 0, 0);
  v7 = 1;
  IEventEngine::SendAMessage(g_pEvnEngine, &v6);
  v7 = -1;
  CEvn_Event::~CEvn_Event(&v6);
  return 1;
}


// address=[0x15be8b0]
// Decompiled from char __stdcall sub_19BE8B0(int a1)
bool  CGameHost::ClientGameInited(void * a1) {
  
  CGameHost::SendToHost(1018, 0, 0, 0, 0, 1);
  return 1;
}


// address=[0x15be8e0]
// Decompiled from char __thiscall sub_19BE8E0(_DWORD **this, int a2)
bool  CGameHost::ClientStartTick(void * a2) {
  
  _BYTE v3[24]; // [esp+Ch] [ebp-28h] BYREF
  int v4; // [esp+30h] [ebp-4h]

  (*(void (__thiscall **)(_DWORD *))(*this[49] + 60))(this[49]);
  CEvn_Event::CEvn_Event(25, 0, 0, 0);
  v4 = 0;
  IEventEngine::SendAMessage((int)v3);
  v4 = -1;
  CEvn_Event::~CEvn_Event(v3);
  return 1;
}


// address=[0x15be980]
// Decompiled from char __thiscall CGameHost::HostGameInited(int this, int a2)
bool  CGameHost::HostGameInited(void * a2) {
  
  unsigned int v2; // eax
  unsigned int v4; // [esp+4h] [ebp-10h]
  unsigned int i; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]
  unsigned int v7; // [esp+Ch] [ebp-8h]

  if ( !*(_DWORD *)(this + 24) )
    *(_DWORD *)(this + 24) = timeGetTime();
  if ( a2 )
  {
    v2 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 40))(*(_DWORD *)(this + 196));
    CClientList::SetClientReadyFromPeerId(*(CClientList **)(this + 16), v2, 1);
  }
  else
  {
    *(_BYTE *)(this + 60) = 1;
    CTrace::Print("CGameHost.cpp: Game init finished!");
  }
  if ( (unsigned __int8)CClientList::AllClientsReady(*(_DWORD *)(this + 16)) )
  {
    if ( *(_BYTE *)(this + 60) )
    {
      CTrace::Print("CGameHost.cpp: Everyone's finished with game init... Now start 1st tick!");
      CGameHost::SendToAll(this, 1019, 0, 0, 0, 0, 1u);
      v6 = 0;
      v4 = 0;
      for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
      {
        if ( *(_DWORD *)(g_pGameType + 4 * i + 116) == 1 )
        {
          v4 += *(_DWORD *)(g_pGameType + 4 * i + 624);
          ++v6;
        }
      }
      v7 = v6 - 1;
      if ( v7 )
        CTrace::Print("GameHost.cpp: Sleeping for %d ms to get in semi sync state!", v4 / v7);
      CFsm::GenerateEvent(1015, 0);
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
// Decompiled from char __thiscall CGameHost::GameSyncMsgGot(_DWORD *this, int *a2)
bool  CGameHost::GameSyncMsgGot(void * a2) {
  
  int v2; // esi
  int v3; // edi

  CMsgStacks::SetNumberOfExpectedMsgs((_DWORD *)this[5], *a2, ((unsigned int)a2[1] >> 4) & 0xF, a2[1] & 0xF);
  v2 = ((unsigned int)a2[1] >> 4) & 0xF;
  v3 = *a2;
  this[v2 + 50] += v3 - CGameHost::GetValidTick(this);
  ++this[(((unsigned int)a2[1] >> 4) & 0xF) + 58];
  return 1;
}


// address=[0x15beba0]
// Decompiled from char __thiscall CGameHost::GameSync0MsgGot(CGameHost *this, int *a2)
bool  CGameHost::GameSync0MsgGot(void * a2) {
  
  int v3; // esi
  int v4; // edi

  if ( (unsigned __int8)CMsgStacks::IsSizeAlreadySet(*a2, *((_BYTE *)a2 + 4) - 1) )
    return 1;
  CMsgStacks::SetNumberOfExpectedMsgs(*((_DWORD **)this + 5), *a2, *((_BYTE *)a2 + 4) - 1, 0);
  v3 = *((unsigned __int8 *)a2 + 4);
  v4 = *a2;
  *((_DWORD *)this + v3 + 49) += v4 - CGameHost::GetValidTick(this);
  ++*((_DWORD *)this + *((unsigned __int8 *)a2 + 4) + 57);
  return 1;
}


// address=[0x15bec60]
// Decompiled from char __thiscall CGameHost::GameInGameMsgGot(CMsgStacks **this, void *Src)
bool  CGameHost::GameInGameMsgGot(void * Src) {
  
  unsigned __int16 MessageLength; // ax

  MessageLength = CGameHost::GetMessageLength(this);
  memcpy(&unk_415AD98, Src, MessageLength);
  if ( *((_DWORD *)&unk_415AD98 + 6) )
  {
    if ( *((unsigned __int16 *)&unk_415AD98 + 14) >= 0x400u
      && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4470, "pEvent->m_iDataSize < MSG_BUFFER_SIZE") == 1 )
    {
      __debugbreak();
    }
    *((_DWORD *)&unk_415AD98 + 6) = operator new[](*((unsigned __int16 *)&unk_415AD98 + 14));
    memcpy(*((void **)&unk_415AD98 + 6), &unk_415ADB8, *((unsigned __int16 *)&unk_415AD98 + 14));
  }
  if ( !CMsgStacks::IsInStack(this[5], (struct CNet_Event *)&unk_415AD98)
    || CMsgStacks::IsStackAI(this[5], *((unsigned __int8 *)&unk_415AD98 + 30) - 1) )
  {
    CMsgStacks::PushMsg(this[5], (struct CNet_Event *)&unk_415AD98);
  }
  return 1;
}


// address=[0x15bed50]
// Decompiled from char __thiscall CGameHost::GameAsyncMsgGot(void *this, void *Src)
bool  CGameHost::GameAsyncMsgGot(void * Src) {
  
  unsigned __int16 MessageLength; // ax
  _DWORD v4[8]; // [esp+10h] [ebp-30h] BYREF
  int v5; // [esp+3Ch] [ebp-4h]

  MessageLength = CGameHost::GetMessageLength(this);
  memcpy(&unk_415B290, Src, MessageLength);
  if ( *((_DWORD *)&unk_415B290 + 6) )
  {
    if ( *((unsigned __int16 *)&unk_415B290 + 14) >= 0x400u
      && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4556, "pEvent->m_iDataSize < MSG_BUFFER_SIZE") == 1 )
    {
      __debugbreak();
    }
    *((_DWORD *)&unk_415B290 + 6) = &unk_415B2B0;
  }
  CEvn_Logic::CEvn_Logic(
    (CEvn_Logic *)v4,
    *((_DWORD *)&unk_415B290 + 1),
    *((_DWORD *)&unk_415B290 + 2),
    *((_DWORD *)&unk_415B290 + 3),
    *((_BYTE *)&unk_415B290 + 30),
    *((_DWORD *)&unk_415B290 + 6),
    *((_WORD *)&unk_415B290 + 14));
  v5 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v4);
  v5 = -1;
  CEvn_Logic::~CEvn_Logic(v4);
  return 1;
}


// address=[0x15bee60]
// Decompiled from char __thiscall sub_19BEE60(_DWORD **this, int a2)
bool  CGameHost::AmIStillAlive(void * a2) {
  
  int v2; // eax
  int v3; // eax
  int Src; // [esp+0h] [ebp-410h] BYREF
  _DWORD **v6; // [esp+4h] [ebp-40Ch]
  __int16 v7; // [esp+8h] [ebp-408h] BYREF
  char v8[1026]; // [esp+Ah] [ebp-406h] BYREF

  v6 = this;
  v7 = 1041;
  Src = CPlayerManager::GetLocalPlayerId() - 1;
  memcpy(v8, &Src, 4u);
  v2 = (*(int (__thiscall **)(_DWORD *, int, __int16 *, int, _DWORD, int))(*v6[49] + 36))(v6[49], 3105, &v7, 6, 0, 1);
  v3 = (*(int (__thiscall **)(_DWORD *, int))(*v6[49] + 40))(v6[49], v2);
  (*(void (__thiscall **)(_DWORD *, int))(*v6[49] + 32))(v6[49], v3);
  return 1;
}


// address=[0x15bef30]
// Decompiled from char __stdcall sub_19BEF30(char *a1)
bool  CGameHost::HeIsStillAlive(void * a1) {
  
  DWORD Time; // eax

  Time = timeGetTime();
  CMsgStacks::SetLastMsgTime(*a1, Time, 1);
  return 1;
}


// address=[0x15bef60]
// Decompiled from char __thiscall CGameHost::GameInGamePackedGot(_DWORD *this, int a2)
bool  CGameHost::GameInGamePackedGot(void * a2) {
  
  int v3; // [esp+4h] [ebp-1Ch]
  int v4; // [esp+8h] [ebp-18h]
  char *Src; // [esp+10h] [ebp-10h]
  int v6; // [esp+14h] [ebp-Ch]
  char *v8; // [esp+1Ch] [ebp-4h]

  v6 = (*(_BYTE *)(a2 + 6) & 0xF) + 1;
  v4 = *(_DWORD *)(a2 + 7);
  v3 = *(_DWORD *)(a2 + 2) & 0xF;
  Src = (char *)(a2 + 11);
  if ( (unsigned __int8)CMsgStacks::IsSizeAlreadySet(v4, *(_BYTE *)(a2 + 6) & 0xF) )
    return 1;
  CMsgStacks::SetNumberOfExpectedMsgs((_DWORD *)this[5], v4, v6 - 1, v3);
  this[v6 + 49] += v4 - CGameHost::GetValidTick(this);
  ++this[v6 + 57];
  while ( v3 )
  {
    v8 = Src;
    Src += 32;
    *((_DWORD *)v8 + 4) = v4;
    v8[30] = v6;
    if ( *((_WORD *)v8 + 14) )
    {
      *((_DWORD *)v8 + 6) = operator new[](*((unsigned __int16 *)v8 + 14));
      memcpy(*((void **)v8 + 6), Src, *((unsigned __int16 *)v8 + 14));
      Src += *((unsigned __int16 *)v8 + 14);
    }
    if ( !CMsgStacks::IsStackAI((CMsgStacks *)this[5], (unsigned __int8)v8[30] - 1) )
      CMsgStacks::PushMsg((CMsgStacks *)this[5], (struct CNet_Event *)v8);
    --v3;
  }
  return 1;
}


// address=[0x15bf0e0]
// Decompiled from char __thiscall CGameHost::IsValidSaveGame(CGameHost *this, struct SGameInfo *a2)
bool  CGameHost::IsValidSaveGame(struct SGameInfo & a2) {
  
  const wchar_t *v2; // eax
  bool v4; // [esp+Fh] [ebp-995h]
  _BYTE v5[2368]; // [esp+10h] [ebp-994h] BYREF
  int v6; // [esp+950h] [ebp-54h]
  _BYTE v7[28]; // [esp+978h] [ebp-2Ch] BYREF
  int v8; // [esp+9A0h] [ebp-4h]

  if ( !*((_BYTE *)a2 + 624) )
    return 1;
  std::wstring::wstring(v7, (wchar_t *)a2 + 324);
  v8 = 0;
  (*(void (__thiscall **)(void *, _BYTE *))(*(_DWORD *)g_pRandomMaps + 52))(g_pRandomMaps, v7);
  if ( *((_BYTE *)a2 + 633) )
    std::wstring::operator+=(v7, (wchar_t *)L"_autoSave");
  std::wstring::operator+=(v7, (wchar_t *)L".sav");
  CGameChunkGeneral::CGameChunkGeneral(v5);
  v2 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v7);
  if ( CGameRun::LoadGeneralInfo(v2, (struct CGameChunkGeneral *)v5) )
  {
    v4 = v6 == *((_DWORD *)a2 + 155);
    v8 = -1;
    std::wstring::~wstring(v7);
    return v4;
  }
  else
  {
    v8 = -1;
    std::wstring::~wstring(v7);
    return 0;
  }
}


// address=[0x15c4970]
// Decompiled from char __stdcall sub_19C4970(int a1)
bool  CGameHost::DoNothing(void * a1) {
  
  return 1;
}


