#include "CGameHost.h"

// Definitions for class CGameHost

// address=[0x14aab10]
// Decompiled from int __thiscall CGameHost::GetBytesPerSecond(CGameHost *this)

unsigned int  CGameHost::GetBytesPerSecond(void) {
  
  if ( *((_DWORD *)this + 49) )
    return (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 49) + 52))(*((_DWORD *)this + 49));
  else
    return 0;
}


// address=[0x15b4e60]
// Decompiled from char __thiscall CGameHost::AllSend(_DWORD *this)

bool  CGameHost::AllSend(void) {
  
  int v2; // eax
  int v3; // esi
  int CurrentTickCounter; // eax
  char v5; // [esp-8h] [ebp-2Ch]
  char v6; // [esp-8h] [ebp-2Ch]
  unsigned __int8 v7; // [esp-4h] [ebp-28h]
  unsigned __int8 v8; // [esp-4h] [ebp-28h]
  int v9; // [esp+0h] [ebp-24h]
  int v10; // [esp+0h] [ebp-24h]
  int v11; // [esp+0h] [ebp-24h]
  int v12; // [esp+0h] [ebp-24h]
  int v13; // [esp+4h] [ebp-20h] BYREF
  char v14; // [esp+8h] [ebp-1Ch]
  int LocalPlayerId; // [esp+Ch] [ebp-18h]
  int v16; // [esp+10h] [ebp-14h]
  int v17; // [esp+14h] [ebp-10h]
  void *v18; // [esp+18h] [ebp-Ch]
  void *Src; // [esp+1Ch] [ebp-8h]
  _DWORD *v20; // [esp+20h] [ebp-4h]

  v20 = this;
  if ( !this[5] && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3738, "m_pMsgStacks") == 1 )
    __debugbreak();
  if ( !v20[4] && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3739, "m_pClientList") == 1 )
    __debugbreak();
  if ( (COMMUNICATION_TICK_VALUE & IEventEngine::GetCurrentTickCounter(g_pEvnEngine)) != 0 )
    return 1;
  if ( std::list<CNet_Event>::size(v20 + 70) )
  {
    LocalPlayerId = CPlayerManager::GetLocalPlayerId(v9);
    *((_BYTE *)v20 + 298) = (LocalPlayerId - 1) & 0xF | *((_BYTE *)v20 + 298) & 0xF0;
    *((_WORD *)v20 + 146) = 1054;
    *(_DWORD *)((char *)v20 + 299) = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    v17 = 0;
    v18 = (char *)v20 + 303;
    while ( std::list<CNet_Event>::size(v20 + 70) )
    {
      Src = (void *)std::list<CNet_Event>::front(v10, v13);
      v3 = *((unsigned __int8 *)Src + 30);
      if ( v3 != CPlayerManager::GetLocalPlayerId(v11)
        && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3774, "evn.m_iOwner == g_cPlayerMgr.GetLocalPlayerId()") == 1 )
      {
        __debugbreak();
      }
      if ( *((_DWORD *)Src + 6) && ((char *)v18 + *((unsigned __int16 *)Src + 14) >= (char *)(v20 + 313) || v17 == 15) )
        break;
      *((_DWORD *)Src + 4) = *(_DWORD *)((char *)v20 + 299);
      CMsgStacks::PushMsg((CMsgStacks *)v20[5], (struct CNet_Event *)Src);
      *((_BYTE *)Src + 30) = 0;
      *((_BYTE *)Src + 31) = 0;
      *((_BYTE *)Src + 20) = 0;
      *((_BYTE *)Src + 21) = 0;
      *((_BYTE *)Src + 22) = 0;
      *((_BYTE *)Src + 23) = 0;
      j__memcpy(v18, Src, 0x20u);
      v18 = (char *)v18 + 32;
      if ( *((_DWORD *)Src + 6) )
      {
        if ( !*((_WORD *)Src + 14) && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3805, "evn.m_iDataSize") == 1 )
          __debugbreak();
        j__memcpy(v18, *((const void **)Src + 6), *((unsigned __int16 *)Src + 14));
        v18 = (char *)v18 + *((unsigned __int16 *)Src + 14);
        *((_DWORD *)Src + 6) = 0;
      }
      std::list<CNet_Event>::pop_front(v12, v13);
      ++v17;
    }
    *(_DWORD *)((char *)v20 + 294) = v17 & 0xF | *(_DWORD *)((char *)v20 + 294) & 0xFFFFFFF0;
    v6 = CPlayerManager::GetLocalPlayerId((unsigned __int8)v17) - 1;
    CurrentTickCounter = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    CMsgStacks::SetNumberOfExpectedMsgs((_DWORD *)v20[5], CurrentTickCounter, v6, v8);
    if ( *((_BYTE *)v20 + 10) )
      CGameHost::SendToAll((int)v20, 1054, v20 + 73, (_BYTE *)v18 - (_BYTE *)(v20 + 73), 0, 0, 1u);
  }
  else
  {
    v14 = CPlayerManager::GetLocalPlayerId(v9);
    v16 = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    v13 = v16;
    if ( *((_BYTE *)v20 + 10) )
      CGameHost::SendToAll((int)v20, 1055, &v13, 5u, 0, 0, 1u);
    v5 = CPlayerManager::GetLocalPlayerId(0) - 1;
    v2 = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    CMsgStacks::SetNumberOfExpectedMsgs((_DWORD *)v20[5], v2, v5, v7);
  }
  return 1;
}


// address=[0x15b51a0]
// Decompiled from char __thiscall CGameHost::StartNewCycle(CGameHost *this, bool a2)

bool  CGameHost::StartNewCycle(bool) {
  
  int ValidTick; // esi
  int v3; // esi
  int v5; // esi
  int v6; // eax
  int v7; // [esp+4h] [ebp-8h] BYREF
  _DWORD *v8; // [esp+8h] [ebp-4h]

  v8 = this;
  if ( !*((_DWORD *)this + 5) && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3271, "m_pMsgStacks") == 1 )
    __debugbreak();
  if ( !v8[5] )
    return 0;
  if ( *((_BYTE *)v8 + 10) )
  {
    ValidTick = CMsgStacks::GetValidTick((void *)v8[5]);
    v3 = CMsgStacks::Getdt((CMsgStacks *)v8[5]) + ValidTick;
    if ( v3 > CMsgStacks::GetVirtualTick((CMsgStacks *)v8[5]) )
    {
LABEL_7:
      CGameHost::AllSend(v8);
      CMsgStacks::AdvanceVirtualTick((CMsgStacks *)v8[5]);
      v8[16] = 0;
      return 0;
    }
  }
  else
  {
    v5 = CMsgStacks::GetValidTick((void *)v8[5]) + 1;
    if ( v5 >= CMsgStacks::GetVirtualTick((CMsgStacks *)v8[5]) )
      goto LABEL_7;
  }
  if ( (COMMUNICATION_TICK_VALUE & CMsgStacks::GetValidTick((void *)v8[5])) != 0
    && *((_BYTE *)v8 + 10)
    && (v7 = 0,
        v6 = CGameHost::GetValidTick(v8),
        !CMsgStacks::IsMsgStackValid((CMsgStacks *)v8[5], v6 + 1, (unsigned int *)&v7)) )
  {
    CGameHost::NotifyClients(v8, v7);
    return 0;
  }
  else if ( CMsgStacks::IsEmpty((CMsgStacks *)v8[5], 0) )
  {
    if ( !a2 )
      return 1;
    CMsgStacks::TriggerTime((CMsgStacks *)v8[5]);
    CMsgStacks::AdvanceValidTick((CMsgStacks *)v8[5]);
    CMsgStacks::AdvanceVirtualTick((CMsgStacks *)v8[5]);
    v8[16] = 0;
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

bool  CGameHost::RegisterMsgStacks(class CMsgStacks *) {
  
  if ( *((_DWORD *)this + 5) )
    return 0;
  *((_DWORD *)this + 5) = a2;
  return 1;
}


// address=[0x15b53d0]
// Decompiled from char __thiscall CGameHost::InitAsClient(CGameHost *this, unsigned int a2)

bool  CGameHost::InitAsClient(unsigned int) {
  
  if ( !*((_DWORD *)this + 3) && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3237, "m_pFsm") == 1 )
    __debugbreak();
  if ( a2 )
    CFsm::Control(*((CFsm **)this + 3), 1016, 0);
  else
    CFsm::Control(*((CFsm **)this + 3), 1008, 0);
  return 1;
}


// address=[0x15b5440]
// Decompiled from char __thiscall CGameHost::InitAsHost(CGameHost *this, unsigned int a2)

bool  CGameHost::InitAsHost(unsigned int) {
  
  if ( !*((_DWORD *)this + 3) && BBSupportDbgReport(2, "Net\\GameHost.cpp", 589, "m_pFsm") == 1 )
    __debugbreak();
  if ( a2 )
    CFsm::Control(*((CFsm **)this + 3), 1012, 0);
  else
    CFsm::Control(*((CFsm **)this + 3), 1007, 0);
  return 1;
}


// address=[0x15b54b0]
// Decompiled from CGameHost *__thiscall CGameHost::CGameHost(CGameHost *this, char a2)

 CGameHost::CGameHost(bool) {
  
  const char *v2; // eax
  void *v4; // [esp+4h] [ebp-50h]
  CDaoIndexFieldInfo *v5; // [esp+14h] [ebp-40h]
  CDaoIndexFieldInfo *v6; // [esp+18h] [ebp-3Ch]
  CFsm *v7; // [esp+1Ch] [ebp-38h]
  CFsm *C; // [esp+20h] [ebp-34h]
  _BYTE v10[28]; // [esp+28h] [ebp-2Ch] BYREF
  int v11; // [esp+50h] [ebp-4h]

  IEventHandler::IEventHandler(this, 2000);
  v11 = 0;
  *(_DWORD *)this = &CGameHost::_vftable_;
  *((_BYTE *)this + 8) = 0;
  *((_BYTE *)this + 9) = 0;
  *((_BYTE *)this + 10) = a2;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_BYTE *)this + 60) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_BYTE *)this + 76) = 0;
  *((_BYTE *)this + 77) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 46) = 0;
  *((_DWORD *)this + 47) = 0;
  *((_DWORD *)this + 48) = 0;
  *((_DWORD *)this + 49) = 0;
  std::list<SGameInfo>::list<SGameInfo>((char *)this + 268);
  std::list<CNet_Event>::list<CNet_Event>((char *)this + 280);
  j__memset((char *)this + 88, 0, 0x20u);
  j__memset((char *)this + 120, 0, 0x20u);
  j__memset((char *)this + 152, 0, 0x20u);
  j__memset((char *)this + 200, 0, 0x20u);
  j__memset((char *)this + 232, 0, 0x20u);
  j__memset((char *)this + 292, 0, 0x3CBu);
  CGameHost::FillHandlersArray(this);
  C = (CFsm *)operator new(0x1Cu);
  LOBYTE(v11) = 3;
  if ( C )
    v7 = CFsm::CFsm(C, this, 1500, 34);
  else
    v7 = 0;
  LOBYTE(v11) = 2;
  *((_DWORD *)this + 3) = v7;
  CFsm::DefineTransition(*((CFsm **)this + 3), 34, 1, 1007, 1);
  CFsm::DefineTransition(*((CFsm **)this + 3), 54, 1, 1007, 1);
  CFsm::DefineTransition(*((CFsm **)this + 3), 2, 70, 1060, 71);
  CFsm::DefineTransition(*((CFsm **)this + 3), 4, 70, 1060, 71);
  CFsm::DefineTransition(*((CFsm **)this + 3), 55, 70, 1060, 71);
  CFsm::DefineTransition(*((CFsm **)this + 3), 70, 40, 1024, 40);
  CFsm::DefineTransition(*((CFsm **)this + 3), 70, 5, 1057, 41);
  CFsm::DefineTransition(*((CFsm **)this + 3), 1, 1, 1051, 60);
  CFsm::DefineTransition(*((CFsm **)this + 3), 1, 69, 1059, 68);
  CFsm::DefineTransition(*((CFsm **)this + 3), 1, 1, 1000, 36);
  CFsm::DefineTransition(*((CFsm **)this + 3), 1, 3, 1009, 3);
  CFsm::DefineTransition(*((CFsm **)this + 3), 69, 3, 1009, 3);
  CFsm::DefineTransition(*((CFsm **)this + 3), 69, 40, 1024, 40);
  CFsm::DefineTransition(*((CFsm **)this + 3), 69, 5, 1057, 41);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1000, 35);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1001, 36);
  CFsm::DefineTransition(*((CFsm **)this + 3), 5, 3, 1058, 36);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1023, 39);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1027, 6);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1035, 44);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1036, 45);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1050, 61);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1047, 56);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1052, 62);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1053, 63);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1056, 67);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1042, 52);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 3, 1029, 8);
  CFsm::DefineTransition(*((CFsm **)this + 3), 3, 15, 1030, 9);
  CFsm::DefineTransition(*((CFsm **)this + 3), 15, 15, 1012, 36);
  CFsm::DefineTransition(*((CFsm **)this + 3), 34, 2, 1008, 2);
  CFsm::DefineTransition(*((CFsm **)this + 3), 54, 2, 1008, 2);
  CFsm::DefineTransition(*((CFsm **)this + 3), 2, 55, 1010, 36);
  CFsm::DefineTransition(*((CFsm **)this + 3), 55, 4, 1046, 4);
  CFsm::DefineTransition(*((CFsm **)this + 3), 55, 40, 1024, 40);
  CFsm::DefineTransition(*((CFsm **)this + 3), 4, 4, 1022, 38);
  CFsm::DefineTransition(*((CFsm **)this + 3), 4, 4, 1046, 4);
  CFsm::DefineTransition(*((CFsm **)this + 3), 4, 40, 1024, 40);
  CFsm::DefineTransition(*((CFsm **)this + 3), 40, 5, 1025, 41);
  CFsm::DefineTransition(*((CFsm **)this + 3), 40, 5, 1057, 41);
  CFsm::DefineTransition(*((CFsm **)this + 3), 40, 40, 1022, 36);
  CFsm::DefineTransition(*((CFsm **)this + 3), 40, 4, 1038, 46);
  CFsm::DefineTransition(*((CFsm **)this + 3), 40, 4, 1048, 57);
  CFsm::DefineTransition(*((CFsm **)this + 3), 5, 5, 1026, 42);
  CFsm::DefineTransition(*((CFsm **)this + 3), 5, 5, 1034, 43);
  CFsm::DefineTransition(*((CFsm **)this + 3), 5, 5, 1036, 45);
  CFsm::DefineTransition(*((CFsm **)this + 3), 5, 5, 1049, 59);
  CFsm::DefineTransition(*((CFsm **)this + 3), 5, 5, 1050, 61);
  CFsm::DefineTransition(*((CFsm **)this + 3), 5, 5, 1053, 64);
  CFsm::DefineTransition(*((CFsm **)this + 3), 5, 5, 1043, 53);
  CFsm::DefineTransition(*((CFsm **)this + 3), 5, 20, 1032, 7);
  CFsm::DefineTransition(*((CFsm **)this + 3), 20, 20, 1032, 7);
  CFsm::DefineTransition(*((CFsm **)this + 3), 34, 14, 1012, 50);
  CFsm::DefineTransition(*((CFsm **)this + 3), 14, 15, 1009, 16);
  CFsm::DefineTransition(*((CFsm **)this + 3), 15, 15, 1013, 16);
  CFsm::DefineTransition(*((CFsm **)this + 3), 15, 18, 1014, 18);
  CFsm::DefineTransition(*((CFsm **)this + 3), 18, 30, 1020, 31);
  CFsm::DefineTransition(*((CFsm **)this + 3), 18, 18, 1018, 31);
  CFsm::DefineTransition(*((CFsm **)this + 3), 30, 30, 1018, 31);
  CFsm::DefineTransition(*((CFsm **)this + 3), 30, 30, 1039, 47);
  CFsm::DefineTransition(*((CFsm **)this + 3), 30, 17, 1015, 19);
  CFsm::DefineTransition(*((CFsm **)this + 3), 34, 20, 1016, 51);
  CFsm::DefineTransition(*((CFsm **)this + 3), 20, 10, 1031, 23);
  CFsm::DefineTransition(*((CFsm **)this + 3), 20, 10, 1010, 23);
  CFsm::DefineTransition(*((CFsm **)this + 3), 10, 10, 1048, 58);
  CFsm::DefineTransition(*((CFsm **)this + 3), 10, 10, 1045, 23);
  CFsm::DefineTransition(*((CFsm **)this + 3), 10, 11, 1033, 24);
  CFsm::DefineTransition(*((CFsm **)this + 3), 11, 25, 1017, 26);
  CFsm::DefineTransition(*((CFsm **)this + 3), 25, 27, 1020, 28);
  CFsm::DefineTransition(*((CFsm **)this + 3), 27, 17, 1019, 29);
  CFsm::DefineTransition(*((CFsm **)this + 3), 27, 17, 1040, 29);
  CFsm::DefineTransition(*((CFsm **)this + 3), 27, 27, 1039, 47);
  CFsm::DefineTransition(*((CFsm **)this + 3), 17, 17, 1021, 33);
  CFsm::DefineTransition(*((CFsm **)this + 3), 17, 17, 1005, 32);
  CFsm::DefineTransition(*((CFsm **)this + 3), 17, 17, 1055, 66);
  CFsm::DefineTransition(*((CFsm **)this + 3), 17, 17, 1039, 47);
  CFsm::DefineTransition(*((CFsm **)this + 3), 17, 17, 1040, 48);
  CFsm::DefineTransition(*((CFsm **)this + 3), 17, 17, 1041, 49);
  CFsm::DefineTransition(*((CFsm **)this + 3), 17, 17, 1054, 65);
  CLanLobby::SetGameHost(this);
  *((_DWORD *)this + 6) = 0;
  v6 = (CDaoIndexFieldInfo *)operator new(0x14u);
  LOBYTE(v11) = 4;
  if ( v6 )
    v5 = CClientList::CClientList(v6);
  else
    v5 = 0;
  LOBYTE(v11) = 2;
  *((_DWORD *)this + 4) = v5;
  if ( !*((_BYTE *)this + 10) )
    goto LABEL_12;
  *((_DWORD *)this + 49) = CreateSimpleNet();
  if ( *((_DWORD *)this + 49) )
  {
    if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 49) + 4))(*((_DWORD *)this + 49)) )
    {
      v4 = (void *)(*(int (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)this + 49) + 8))(*((_DWORD *)this + 49), v10);
      LOBYTE(v11) = 5;
      v2 = (const char *)std::string::c_str(v4);
      BBSupportTracePrintF(3, "GameHost.cpp: %s!", v2);
      LOBYTE(v11) = 2;
      std::string::~string(v10);
      *((_BYTE *)this + 264) = 1;
      return this;
    }
LABEL_12:
    *((_BYTE *)this + 264) = 0;
    return this;
  }
  BBSupportTracePrint(3, "GameHost.cpp: Error initializing Network!");
  *((_BYTE *)this + 264) = 1;
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
      CFsm::`scalar deleting destructor'(v1, 1u);
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
// Decompiled from bool __thiscall CGameHost::PushMsg(CMsgStacks **this, struct CNet_Event *a2)

bool  CGameHost::PushMsg(class CNet_Event &) {
  
  int v2; // esi
  int v4; // [esp+0h] [ebp-8h]

  if ( *((_DWORD *)a2 + 6)
    && !*((_WORD *)a2 + 14)
    && BBSupportDbgReportF(
         2,
         "Net\\GameHost.cpp",
         3859,
         "Fatal: m_iData set, but m_iDataSize == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1 )
  {
    __debugbreak();
  }
  if ( CPlayerManager::IsAI(*((unsigned __int8 *)a2 + 30)) )
    return CMsgStacks::PushMsg(this[5], a2);
  v2 = *((unsigned __int8 *)a2 + 30);
  if ( v2 != CPlayerManager::GetLocalPlayerId(v4)
    && BBSupportDbgReport(2, "Net\\GameHost.cpp", 3865, "_rMsg.m_iOwner == g_cPlayerMgr.GetLocalPlayerId()") == 1 )
  {
    __debugbreak();
  }
  std::list<CNet_Event>::push_back(a2);
  return 1;
}


// address=[0x15b6190]
// Decompiled from void __thiscall CGameHost::PushAsyncMsg(int this, unsigned __int16 *Src, unsigned __int8 a3)

void  CGameHost::PushAsyncMsg(class CNet_Event &,unsigned char) {
  
  int v3; // eax
  int v4; // [esp-18h] [ebp-458h]
  int v5; // [esp-Ch] [ebp-44Ch]
  int v6; // [esp+0h] [ebp-440h]
  int i; // [esp+8h] [ebp-438h]
  __int16 v9; // [esp+Ch] [ebp-434h] BYREF
  _BYTE v10[32]; // [esp+Eh] [ebp-432h] BYREF
  _BYTE v11[994]; // [esp+2Eh] [ebp-412h] BYREF
  _DWORD v12[8]; // [esp+410h] [ebp-30h] BYREF
  int v13; // [esp+43Ch] [ebp-4h]

  CTrace::Print("GameHost.cpp: Sending Async Msg to those Players: %x", a3);
  if ( *(_BYTE *)(this + 10) && !CPlayerManager::IsAI(*((unsigned __int8 *)Src + 30)) )
  {
    for ( i = 1; i <= CPlayerManager::LastPlayerId(); ++i )
    {
      if ( !CPlayerManager::IsAI(i) && CPlayerManager::GetLocalPlayerId(v6) != i && ((1 << (i - 1)) & a3) != 0 )
      {
        v9 = 1039;
        j__memcpy(v10, Src, sizeof(v10));
        j__memcpy(v11, *((const void **)Src + 6), Src[14]);
        v5 = Src[14] + 34;
        v4 = CPlayerManager::IP(i);
        v3 = CPlayerManager::PeerId(i);
        (*(void (__thiscall **)(_DWORD, int, int, int, __int16 *, int, int, int))(**(_DWORD **)(this + 196) + 32))(
          *(_DWORD *)(this + 196),
          v3,
          v4,
          3105,
          &v9,
          v5,
          1,
          1);
        CTrace::Print("GameHost.cpp: Delivering Async Msg to Owner %d!", i);
      }
    }
  }
  if ( (a3 & (1 << (CPlayerManager::GetLocalPlayerId(v6) - 1))) != 0 )
  {
    CEvn_Logic::CEvn_Logic(
      (CEvn_Logic *)v12,
      *((_DWORD *)Src + 1),
      *((_DWORD *)Src + 2),
      *((_DWORD *)Src + 3),
      *((_BYTE *)Src + 30),
      *((_DWORD *)Src + 6),
      Src[14]);
    v13 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v12);
    v13 = -1;
    CEvn_Logic::~CEvn_Logic(v12);
  }
}


// address=[0x15b63b0]
// Decompiled from int __thiscall CGameHost::PopMsg(_DWORD *this, int a2)

class CNet_Event  CGameHost::PopMsg(void) {
  
  CMsgStacks::PopMsg(this[5], a2);
  return a2;
}


// address=[0x15b63f0]
// Decompiled from int __thiscall CGameHost::GetLocalIP(CGameHost *this)

long  CGameHost::GetLocalIP(void) {
  
  return (*(int (__thiscall **)(_DWORD, CGameHost *))(**((_DWORD **)this + 49) + 16))(*((_DWORD *)this + 49), this);
}


// address=[0x15b6420]
// Decompiled from int __thiscall sub_19B6420(_DWORD **this)

unsigned short  CGameHost::GetMessageLength(void) {
  
  return (*(int (__thiscall **)(_DWORD *, _DWORD **))(*this[49] + 44))(this[49], this) - 2;
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
  
  const char *v1; // eax
  OnlineManager *Instance; // eax
  int v3; // eax
  unsigned int v4; // eax
  const char *v5; // eax
  unsigned int CurrentTickCounter; // eax
  const char *v7; // eax
  DWORD v8; // esi
  DWORD v9; // esi
  DWORD v10; // esi
  DWORD v11; // esi
  int v12; // eax
  DWORD v13; // esi
  CEvn_Event *v15; // [esp+18h] [ebp-9A8h]
  void *v16; // [esp+20h] [ebp-9A0h]
  float v17; // [esp+28h] [ebp-998h]
  unsigned int i; // [esp+2Ch] [ebp-994h]
  _BYTE v20[32]; // [esp+36h] [ebp-98Ah] BYREF
  __int16 v21; // [esp+438h] [ebp-588h]
  _BYTE v22[32]; // [esp+43Ah] [ebp-586h] BYREF
  _BYTE v23[28]; // [esp+83Ch] [ebp-184h] BYREF
  _DWORD v24[6]; // [esp+858h] [ebp-168h] BYREF
  _BYTE v25[32]; // [esp+870h] [ebp-150h] BYREF
  CHAR Src[32]; // [esp+890h] [ebp-130h] BYREF
  CHAR OutputString[256]; // [esp+8B0h] [ebp-110h] BYREF
  int v28; // [esp+9BCh] [ebp-4h]

  if ( !*((_DWORD *)this + 3) || !*((_BYTE *)this + 8) && !*((_BYTE *)this + 9) )
    return 1;
  CGameHost::DeliverSimpleMessage(this);
  if ( !(*(unsigned __int8 (__thiscall **)(_DWORD))(**((_DWORD **)this + 49) + 20))(*((_DWORD *)this + 49)) )
  {
    v16 = (void *)(*(int (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)this + 49) + 8))(*((_DWORD *)this + 49), v23);
    v28 = 0;
    v1 = (const char *)std::string::c_str(v16);
    CTrace::Print("GameHost.cpp: %s!", v1);
    v28 = -1;
    std::string::~string(v23);
  }
  if ( *((_BYTE *)this + 8) )
  {
    for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
    {
      if ( *(_DWORD *)(g_pGameType + 4 * i + 224) != -1 )
      {
        Instance = (OnlineManager *)OnlineManager::GetInstance();
        if ( !OnlineManager::IsInSession(Instance)
          || (v3 = StormManager::GetInstance(),
              *(_DWORD *)(g_pGameType + 4 * i + 224) != StormManager::GetLocalPeerId(v3)) )
        {
          if ( *((int *)this + i + 58) > 20 )
          {
            v17 = (float)*((int *)this + i + 50) / (float)*((int *)this + i + 58);
            j__sprintf(OutputString, "fAverageSync %f\n", v17);
            OutputDebugStringA(OutputString);
            if ( v17 >= 3.0 )
            {
              if ( v17 > (float)(CMsgStacks::GetNumberOfStacks(*((pairNode **)this + 5)) / 2 + 1) )
              {
                CurrentTickCounter = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
                CNet_Event::CNet_Event((CNet_Event *)v25, 0xFA7u, 0x23u, 0, 0, 0, 0, CurrentTickCounter);
                v28 = 2;
                j__memcpy(v20, v25, sizeof(v20));
                v7 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this + 49) + 48))(
                                     *((_DWORD *)this + 49),
                                     *(_DWORD *)(g_pGameType + 4 * i + 188));
                CTrace::Print("GameHost.cpp: Restrain player index %u, IP %s!", i, v7);
                v28 = -1;
                CNet_Event::~CNet_Event((CNet_Event *)v25);
              }
            }
            else
            {
              v4 = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
              CNet_Event::CNet_Event((CNet_Event *)Src, 0xFA7u, 0xFFFFFFDD, 0, 0, 0, 0, v4);
              v28 = 1;
              v21 = 1039;
              j__memcpy(v22, Src, sizeof(v22));
              v5 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)this + 49) + 48))(
                                   *((_DWORD *)this + 49),
                                   *(_DWORD *)(g_pGameType + 4 * i + 188));
              CTrace::Print("GameHost.cpp: Boosting player index %u, IP %s!", i, v5);
              v28 = -1;
              CNet_Event::~CNet_Event((CNet_Event *)Src);
            }
            *((_DWORD *)this + i + 58) = 0;
            *((_DWORD *)this + i + 50) = 0;
          }
        }
      }
    }
  }
  if ( CFsm::CurrentState(*((CFsm **)this + 3)) == 10 )
  {
    if ( !*((_DWORD *)this + 10) )
      *((_DWORD *)this + 10) = timeGetTime();
    v8 = *((_DWORD *)this + 10) + 1000;
    if ( v8 < timeGetTime() )
    {
      CFsm::Control(*((CFsm **)this + 3), 1045, (void *)1);
      ++*((_DWORD *)this + 11);
      CTrace::Print("GameHost.cpp: Resending login after lobby request!");
      *((_DWORD *)this + 10) = timeGetTime();
      if ( *((_DWORD *)this + 11) > (unsigned int)(CStaticConfigVarInt::operator int(&g_iNetAfterLobbyConnectTimeout)
                                                 / 1000) )
      {
        CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2408);
        CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
      }
    }
  }
  if ( CFsm::CurrentState(*((CFsm **)this + 3)) == 40 )
  {
    v9 = *((_DWORD *)this + 14) + CStaticConfigVarInt::operator int(&g_iNotReadyGameStartTimeout);
    if ( v9 < timeGetTime() )
    {
      v15 = CEvn_Event::CEvn_Event((CEvn_Event *)v24, 0xFA1u, 0, 0, 0);
      v28 = 3;
      IEventEngine::SendAMessage(g_pEvnEngine, v15);
      v28 = -1;
      CEvn_Event::~CEvn_Event(v24);
      *((_DWORD *)this + 14) = timeGetTime();
    }
  }
  if ( (CFsm::CurrentState(*((CFsm **)this + 3)) == 30 || CFsm::CurrentState(*((CFsm **)this + 3)) == 18)
    && *((_DWORD *)this + 6) )
  {
    if ( (int)CGameType::GetNumberHumanPlayers((CGameType *)g_pGameType) <= 1 )
    {
      CFsm::Control(*((CFsm **)this + 3), 1015, 0);
    }
    else
    {
      v10 = *((_DWORD *)this + 6) + CStaticConfigVarInt::operator int(&g_iNotReadyGameStartTimeout);
      if ( v10 < timeGetTime() )
      {
        CTrace::Print("GameHost.cpp: One or more clients r not ready for game. Starting it due to timeout!");
        CFsm::Control(*((CFsm **)this + 3), 1015, 0);
      }
    }
  }
  if ( CFsm::CurrentState(*((CFsm **)this + 3)) == 27 )
  {
    if ( !*((_DWORD *)this + 12) )
      *((_DWORD *)this + 12) = timeGetTime();
    v11 = *((_DWORD *)this + 12) + CStaticConfigVarInt::operator int(&g_iNetClientWaitingStartTick);
    if ( v11 < timeGetTime() )
    {
      CTrace::Print("GameHost.cpp: No start tick signal from host got. Starting due to timeout!");
      CFsm::Control(*((CFsm **)this + 3), 1019, 0);
    }
  }
  if ( CFsm::CurrentState(*((CFsm **)this + 3)) == 15 )
  {
    if ( !*((_DWORD *)this + 13) )
      *((_DWORD *)this + 13) = timeGetTime();
    CClientList::GetSize(*((CDaoIndexFieldInfo **)this + 4));
    if ( v12 == CGameType::HumanPlayers((CGameType *)g_pGameType) - 1 )
    {
      CFsm::Control(*((CFsm **)this + 3), 1014, 0);
    }
    else
    {
      v13 = *((_DWORD *)this + 13) + CStaticConfigVarInt::operator int(&g_iHostWaitAfterLobbyForClientsTimeout);
      if ( v13 < timeGetTime() )
      {
        CTrace::Print("GameHost.cpp: One or more clients missing after lobby. Initing game due to timeout!");
        CFsm::Control(*((CFsm **)this + 3), 1014, 0);
      }
    }
  }
  if ( *((_BYTE *)this + 9) )
    CGameHost::OnClientRun(this);
  else
    CGameHost::OnHostRun(this);
  return 0;
}


// address=[0x15b6c60]
// Decompiled from char __thiscall CGameHost::StartIniFileGame(CGameHost *this, wchar_t *Source)

bool  CGameHost::StartIniFileGame(wchar_t const *) {
  
  void *v2; // esp
  const wchar_t *v3; // eax
  const char *v4; // eax
  int v5; // eax
  size_t v6; // eax
  size_t v7; // eax
  size_t v8; // eax
  size_t v9; // eax
  int LocalSlot; // eax
  const char *v11; // eax
  size_t v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  char v16; // [esp-50h] [ebp-1CB4h] BYREF
  int v17; // [esp-4Ch] [ebp-1CB0h]
  int v18; // [esp-48h] [ebp-1CACh]
  int v19; // [esp-44h] [ebp-1CA8h]
  int v20; // [esp-40h] [ebp-1CA4h]
  int v21; // [esp-3Ch] [ebp-1CA0h]
  int v22; // [esp-38h] [ebp-1C9Ch]
  int v23; // [esp-34h] [ebp-1C98h]
  int v24; // [esp-30h] [ebp-1C94h]
  int v25; // [esp-2Ch] [ebp-1C90h] BYREF
  int v26; // [esp-28h] [ebp-1C8Ch]
  int v27; // [esp-24h] [ebp-1C88h]
  int v28; // [esp-20h] [ebp-1C84h]
  int v29; // [esp-1Ch] [ebp-1C80h]
  char **p_EndPtr; // [esp-18h] [ebp-1C7Ch]
  size_t v31; // [esp-14h] [ebp-1C78h]
  int v32; // [esp-10h] [ebp-1C74h] BYREF
  _BYTE v33[8]; // [esp+0h] [ebp-1C64h] BYREF
  int v34; // [esp+8h] [ebp-1C5Ch]
  int *v35; // [esp+Ch] [ebp-1C58h]
  void *v36; // [esp+10h] [ebp-1C54h]
  int *v37; // [esp+14h] [ebp-1C50h]
  int v38; // [esp+18h] [ebp-1C4Ch]
  char *v39; // [esp+1Ch] [ebp-1C48h]
  int v40; // [esp+20h] [ebp-1C44h]
  int v41; // [esp+24h] [ebp-1C40h]
  int v42; // [esp+28h] [ebp-1C3Ch]
  int v43; // [esp+2Ch] [ebp-1C38h]
  int v44; // [esp+30h] [ebp-1C34h]
  void *v45; // [esp+34h] [ebp-1C30h]
  int v46; // [esp+38h] [ebp-1C2Ch]
  int v47; // [esp+3Ch] [ebp-1C28h]
  int v48; // [esp+40h] [ebp-1C24h]
  int v49; // [esp+44h] [ebp-1C20h]
  size_t v50; // [esp+48h] [ebp-1C1Ch]
  int v51; // [esp+4Ch] [ebp-1C18h]
  size_t v52; // [esp+50h] [ebp-1C14h]
  size_t Size; // [esp+54h] [ebp-1C10h]
  size_t v54; // [esp+58h] [ebp-1C0Ch]
  BOOL v55; // [esp+5Ch] [ebp-1C08h]
  BOOL v56; // [esp+60h] [ebp-1C04h]
  BOOL v57; // [esp+64h] [ebp-1C00h]
  int v58; // [esp+68h] [ebp-1BFCh]
  int v59; // [esp+6Ch] [ebp-1BF8h]
  int v60; // [esp+70h] [ebp-1BF4h]
  size_t ElementSize; // [esp+74h] [ebp-1BF0h]
  int v62; // [esp+78h] [ebp-1BECh]
  unsigned int v63; // [esp+7Ch] [ebp-1BE8h]
  int v64; // [esp+80h] [ebp-1BE4h]
  int j; // [esp+84h] [ebp-1BE0h]
  char v66; // [esp+88h] [ebp-1BDCh]
  char v67; // [esp+89h] [ebp-1BDBh]
  char MapData; // [esp+8Ah] [ebp-1BDAh]
  bool v69; // [esp+8Bh] [ebp-1BD9h]
  int IntValue; // [esp+8Ch] [ebp-1BD8h]
  char *EndPtr; // [esp+90h] [ebp-1BD4h] BYREF
  bool v72; // [esp+97h] [ebp-1BCDh]
  CGameHost *v73; // [esp+98h] [ebp-1BCCh]
  bool v74; // [esp+9Fh] [ebp-1BC5h]
  void *Buffer; // [esp+A0h] [ebp-1BC4h]
  _BYTE *v76; // [esp+A4h] [ebp-1BC0h]
  size_t i; // [esp+A8h] [ebp-1BBCh]
  char *Str; // [esp+ACh] [ebp-1BB8h]
  _BYTE v79[2408]; // [esp+B0h] [ebp-1BB4h] BYREF
  _DWORD v80[290]; // [esp+A18h] [ebp-124Ch] BYREF
  char v81[88]; // [esp+EA0h] [ebp-DC4h] BYREF
  int v82[7]; // [esp+EF8h] [ebp-D6Ch] BYREF
  _BYTE v83[28]; // [esp+F14h] [ebp-D50h] BYREF
  _BYTE v84[72]; // [esp+F30h] [ebp-D34h] BYREF
  _BYTE v85[28]; // [esp+F78h] [ebp-CECh] BYREF
  _BYTE v86[28]; // [esp+F94h] [ebp-CD0h] BYREF
  _BYTE v87[28]; // [esp+FB0h] [ebp-CB4h] BYREF
  _BYTE v88[28]; // [esp+FCCh] [ebp-C98h] BYREF
  _BYTE v89[28]; // [esp+FE8h] [ebp-C7Ch] BYREF
  _BYTE v90[28]; // [esp+1004h] [ebp-C60h] BYREF
  _DWORD v91[63]; // [esp+1020h] [ebp-C44h] BYREF
  _DWORD v92[9]; // [esp+111Ch] [ebp-B48h] BYREF
  wchar_t Ext[256]; // [esp+1140h] [ebp-B24h] BYREF
  wchar_t v94[256]; // [esp+1340h] [ebp-924h] BYREF
  wchar_t Dir[256]; // [esp+1540h] [ebp-724h] BYREF
  _BYTE v96[256]; // [esp+1740h] [ebp-524h] BYREF
  WCHAR Filename[260]; // [esp+1840h] [ebp-424h] BYREF
  wchar_t Dest[256]; // [esp+1A48h] [ebp-21Ch] BYREF
  wchar_t Drive[4]; // [esp+1C48h] [ebp-1Ch] BYREF
  int *v100; // [esp+1C54h] [ebp-10h]
  int v101; // [esp+1C60h] [ebp-4h]

  v2 = alloca(7252);
  v100 = &v32;
  v73 = this;
  GetModuleFileNameW(0, Filename, 0x208u);
  j___wsplitpath(Filename, Drive, Dir, v94, Ext);
  GetCurrentDirectoryW(0x200u, Dir);
  MyWStrNCopy((int)Filename, (int)Dir, 520);
  j__wcscat(Filename, asc_37C7ED4);
  j__wcscat(Filename, Source);
  CFile::CFile((CFile *)v84);
  v101 = 1;
  v43 = std::wstring::wstring(v83, Filename);
  v44 = v43;
  LOBYTE(v101) = 2;
  CFile::Open(v43, 5, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
  LOBYTE(v101) = 1;
  std::wstring::~wstring(v83);
  v101 = 0;
  ElementSize = CFile::Size(v84);
  Size = ElementSize + 128;
  v45 = operator new[](ElementSize + 128);
  Buffer = v45;
  j__memset(v45, 0, Size);
  CFile::Read(Buffer, ElementSize, 1u, (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
  CFile::Close((CFile *)v84, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
  CClassNetGameIniBuffer::CClassNetGameIniBuffer((CClassNetGameIniBuffer *)v33, (const char *)Buffer, ElementSize);
  Str = 0;
  v76 = 0;
  Str = (char *)strstr((char *)Buffer, "GameID=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <GameID>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1289, aErrorI1Reading) == 1 )
      __debugbreak();
  }
  v40 = j__strtol(Str + 7, &EndPtr, 10);
  Str = (char *)strstr((char *)Buffer, "GameName=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <GameName>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1299, aErrorI2Reading) == 1 )
      __debugbreak();
  }
  Str += 9;
  v76 = (_BYTE *)strstr(Str, "\n");
  if ( !v76 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <GameName>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1306, aErrorI3Reading) == 1 )
      __debugbreak();
  }
  i = j__mbstowcs(Dest, Str, v76 - Str);
  Dest[i] = 0;
  j__memcpy(v96, Str, v76 - Str);
  v54 = i;
  if ( i >= 0x100 )
    j____report_rangecheckfailure();
  v96[v54] = 0;
  std::wstring::wstring(v88, Dest);
  LOBYTE(v101) = 4;
  Str = (char *)strstr((char *)Buffer, "SaveGame=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <SaveGame>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1326, aErrorI2Reading_0) == 1 )
      __debugbreak();
  }
  v63 = j__strtol(Str + 9, &EndPtr, 10);
  v55 = v63 == 1;
  v69 = v63 == 1;
  if ( v63 >= 2 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed! invalid SaveGameTag %d", v63);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1333, aErrorI9bReadin) == 1 )
      __debugbreak();
  }
  *(_BYTE *)(g_pGameType + 696) = v69;
  v72 = 0;
  v74 = 0;
  Str = (char *)strstr((char *)Buffer, "IsLadderGame=");
  if ( Str )
  {
    v46 = j__strtol(Str + 13, &EndPtr, 10);
    v56 = v46 == 1;
    v72 = v46 == 1;
  }
  Str = (char *)strstr((char *)Buffer, "IsClanGame=");
  if ( Str )
  {
    v47 = j__strtol(Str + 11, &EndPtr, 10);
    v57 = v47 == 1;
    v74 = v47 == 1;
  }
  std::wstring::wstring(v89);
  LOBYTE(v101) = 5;
  Str = (char *)strstr((char *)Buffer, "MapName=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <MapName>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1377, aErrorI4Reading) == 1 )
      __debugbreak();
  }
  Str += 8;
  v76 = (_BYTE *)strstr(Str, "\n");
  if ( !v76 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <MapName>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1384, aErrorI5Reading) == 1 )
      __debugbreak();
  }
  *v76 = 0;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v81);
  LOBYTE(v101) = 6;
  v41 = std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
          (int)v82,
          Str);
  std::wstring::operator=(v41);
  std::wstring::~wstring(v82);
  *v76 = 10;
  if ( (unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType) )
  {
    CGameType::ConvertMapNameToMPGameName(v90, v89);
    LOBYTE(v101) = 7;
    std::wstring::operator+=((wchar_t *)L".sav");
    CGameChunkGeneral::CGameChunkGeneral(v79);
    v3 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v90);
    if ( !CGameRun::LoadGeneralInfo(v3, (struct CGameChunkGeneral *)v79) )
    {
      v4 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v90);
      CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <MapName>, can't load %s!", v4);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1415, aTheDesiredMapF) == 1 )
        __debugbreak();
    }
    SaveFilePath::BuildSaveFilePath(v86, (int)v90);
    LOBYTE(v101) = 8;
    CGameRun::FillGameType(v86, g_pGameType, v79);
    LOBYTE(v101) = 7;
    std::wstring::~wstring(v86);
    LOBYTE(v101) = 6;
    std::wstring::~wstring(v90);
  }
  else
  {
    std::wstring::operator=((int)v89);
    v31 = v74;
    p_EndPtr = (char **)v72;
    v29 = -1;
    v28 = -1;
    v27 = 0;
    v26 = 1;
    v25 = 1;
    v24 = 0;
    v23 = 0;
    v39 = &v16;
    v38 = std::wstring::wstring(g_pGameType + 28);
    MapData = CGameType::LoadMapData(
                v16,
                v17,
                v18,
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
                (char)p_EndPtr,
                v31);
    v67 = MapData;
    if ( !MapData && BBSupportDbgReport(1, "Net\\GameHost.cpp", 1400, aTheDesiredMapF_0) == 1 )
      __debugbreak();
    std::wstring::operator=((int)v88);
  }
  LOBYTE(v101) = 5;
  std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v81);
  LOBYTE(v101) = 4;
  std::wstring::~wstring(v89);
  CGameType::SetLadderGame((CGameType *)g_pGameType, v72);
  CGameType::SetClanGame((CGameType *)g_pGameType, v74);
  Str = (char *)strstr(Str, "ProductID=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <ProductID>!");
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1433, aErrorI6Reading) == 1 )
      __debugbreak();
  }
  v64 = (unsigned __int8)j__strtol(Str + 10, &EndPtr, 10);
  v5 = CStaticConfigVarInt::operator int(&unk_415AD78);
  if ( v64 != v5 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase! Wrong Product ID %d!", v64);
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
  *(_DWORD *)(g_pGameType + 864) = j__strtol(Str + 9, &EndPtr, 10);
  if ( *(int *)(g_pGameType + 864) <= 0 || *(int *)(g_pGameType + 864) >= 6 )
  {
    CTrace::Print(
      "GameHost.cpp: Internet game ini file malformed! invalid game mode %d",
      *(_DWORD *)(g_pGameType + 864));
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
  *(_DWORD *)(g_pGameType + 64) = j__strtol(Str + 10, &EndPtr, 10) + 1;
  if ( *(int *)(g_pGameType + 64) < 1 || *(int *)(g_pGameType + 64) > 3 )
  {
    CTrace::Print(
      "GameHost.cpp: Internet game ini file malformed! invalid game mode %d",
      *(_DWORD *)(g_pGameType + 864));
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
  if ( *(_DWORD *)(g_pGameType + 864) != 2 )
    *(_DWORD *)(g_pGameType + 72) = j__strtol(Str + 14, &EndPtr, 10);
  if ( *(_DWORD *)(g_pGameType + 72) < 2u || *(_DWORD *)(g_pGameType + 72) > 8u )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed! Too many Teams %d", *(_DWORD *)(g_pGameType + 72));
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
  v62 = j__strtol(Str + 16, &EndPtr, 10);
  if ( !(unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType)
    && (v74 || *(_BYTE *)(g_pGameType + 876) && *(_BYTE *)(g_pGameType + 875)) )
  {
    *(_DWORD *)(g_pGameType + 112) = v62;
  }
  else
  {
    *(_DWORD *)(g_pGameType + 112) = *(_DWORD *)(g_pGameType + 852);
  }
  if ( *(_DWORD *)(g_pGameType + 864) != 2 )
    *(_DWORD *)(g_pGameType + 852) = *(_DWORD *)(g_pGameType + 112);
  if ( *(_DWORD *)(g_pGameType + 112) < 2u || *(_DWORD *)(g_pGameType + 112) > 8u )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed! Too many players %d", *(_DWORD *)(g_pGameType + 112));
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1534, aErrorI9Reading) == 1 )
      __debugbreak();
  }
  Str = (char *)strstr((char *)Buffer, "IsTrojan=");
  if ( Str )
  {
    v48 = j__strtol(Str + 9, &EndPtr, 10);
    *(_BYTE *)(g_pGameType + 560) |= v48;
    g_uiExtrasAllowed = *(_BYTE *)(g_pGameType + 560);
  }
  `eh vector constructor iterator'(v91, 0x1Cu, 9u, std::wstring::wstring, std::wstring::~wstring);
  LOBYTE(v101) = 9;
  j__memset(v92, 0, sizeof(v92));
  for ( i = 0; (int)i < v62; ++i )
  {
    j__sprintf((char *const)Dest, "PlayerIP%d=", i);
    Str = (char *)strstr((char *)Buffer, (char *)Dest);
    if ( !Str )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerIP%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1568, aErrorI10Readin) == 1 )
        __debugbreak();
    }
    v76 = (_BYTE *)strstr(Str, "\n");
    if ( !v76 )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <PlayerIP%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1574, aErrorI11Readin) == 1 )
        __debugbreak();
    }
    *v76 = 0;
    v6 = j__strlen("PlayerIP%d=");
    v37 = &v25;
    v36 = std::string::string(&v25, &Str[v6 - 1]);
    v42 = (*(int (__thiscall **)(_DWORD, int, int, int, int, int, char **, size_t))(**((_DWORD **)v73 + 49) + 68))(
            *((_DWORD *)v73 + 49),
            v25,
            v26,
            v27,
            v28,
            v29,
            p_EndPtr,
            v31);
    v58 = v42;
    v92[i] = v42;
    if ( !(unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType) )
      *(_DWORD *)(g_pGameType + 4 * i + 188) = v58;
    *v76 = 10;
    j__sprintf((char *const)Dest, "PlayerName%d=", i);
    Str = (char *)strstr((char *)Buffer, (char *)Dest);
    if ( !Str )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerName%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1593, aErrorI12Readin) == 1 )
        __debugbreak();
    }
    v76 = (_BYTE *)strstr(Str, "\n");
    if ( !v76 )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <PlayerName%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1599, aErrorI13Readin) == 1 )
        __debugbreak();
    }
    v31 = v76 - &Str[j__strlen("PlayerName%d=") - 1];
    v7 = j__strlen("PlayerName%d=");
    v52 = j__mbstowcs(Dest, &Str[v7 - 1], v31);
    Dest[v52] = 0;
    std::wstring::wstring(v87, Dest);
    LOBYTE(v101) = 10;
    std::wstring::operator=((int)v87);
    j__sprintf((char *const)Dest, "PlayerID%d=", i);
    Str = (char *)strstr((char *)Buffer, (char *)Dest);
    if ( !Str )
    {
      CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerID%d>!", i);
      if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1615, aErrorI20Readin) == 1 )
        __debugbreak();
    }
    v31 = 10;
    p_EndPtr = &EndPtr;
    v8 = j__strlen("PlayerID%d=");
    v51 = j__strtol(&Str[v8 - 1], &EndPtr, 10);
    *(_DWORD *)(g_pGameType + 4 * i + 224) = v51;
    if ( *(_DWORD *)(g_pGameType + 4 * i + 152) >= *(_DWORD *)(g_pGameType + 72) )
      *(_DWORD *)(g_pGameType + 4 * i + 152) = i % *(_DWORD *)(g_pGameType + 72);
    if ( (unsigned __int8)CGameType::IsClanGame(g_pGameType) )
    {
      j__sprintf((char *const)Dest, "ClanShortcut%d=", i);
      Str = (char *)strstr((char *)Buffer, (char *)Dest);
      if ( !Str )
      {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <PlayerIP%d>!", i);
        if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1633, aErrorI10Readin_0) == 1 )
          __debugbreak();
      }
      v76 = (_BYTE *)strstr(Str, "\n");
      if ( !v76 )
      {
        CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <PlayerIP%d>!", i);
        if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1639, aErrorI11Readin_0) == 1 )
          __debugbreak();
      }
      v31 = v76 - &Str[j__strlen("ClanShortcut%d=") - 1];
      v9 = j__strlen("ClanShortcut%d=");
      v50 = j__mbstowcs(Dest, &Str[v9 - 1], v31);
      Dest[v50] = 0;
      std::wstring::wstring(v85, Dest);
      LOBYTE(v101) = 11;
      CGameType::SetPlayerClanShortcut(i, v85);
      LOBYTE(v101) = 10;
      std::wstring::~wstring(v85);
    }
    LOBYTE(v101) = 9;
    std::wstring::~wstring(v87);
  }
  IntValue = CClassNetGameIniBuffer::GetIntValue("LocalPlayerSlot=", -1);
  if ( IntValue >= 8 )
    IntValue = -1;
  if ( IntValue < 0 )
  {
    for ( i = 0; (int)i < v62; ++i )
    {
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)v73 + 49) + 64))(
             *((_DWORD *)v73 + 49),
             v92[i]) )
      {
        IntValue = i;
        break;
      }
    }
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)v73 + 49) + 72))(*((_DWORD *)v73 + 49), v92[IntValue]);
  }
  if ( IntValue >= 0 && std::wstring::length(&v91[7 * IntValue]) )
  {
    v35 = &v25;
    v34 = std::wstring::wstring((int)&v91[7 * IntValue]);
    CGameSettings::SetPlayerName(v25, v26);
  }
  *(_DWORD *)(g_pGameType + 68) = v92[0];
  if ( !IntValue )
  {
    CGameType::SetHost((CGameType *)g_pGameType, 1);
    if ( (unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType) )
    {
      LocalSlot = CGameType::GetLocalSlot(g_pGameType);
      *(_DWORD *)(g_pGameType + 4 * LocalSlot + 188) = v92[0];
    }
  }
  if ( *(_DWORD *)(g_pGameType + 864) == 2 )
    *(_DWORD *)(g_pGameType + 112) = *(_DWORD *)(g_pGameType + 852);
  Str = (char *)strstr((char *)Buffer, "SessionID=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <SessionID>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1705, aErrorI14Readin) == 1 )
      __debugbreak();
  }
  v76 = (_BYTE *)strstr(Str, "\n");
  if ( !v76 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <SessionID>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1711, aErrorI15Readin) == 1 )
      __debugbreak();
  }
  *v76 = 0;
  std::string::operator=((void *)(g_pGameType + 792), Str + 10);
  *v76 = 10;
  Str = (char *)strstr((char *)Buffer, "ProcedureServer=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <ProcedureServer>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1723, aErrorI16Readin) == 1 )
      __debugbreak();
  }
  v76 = (_BYTE *)strstr(Str, "\n");
  if ( !v76 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <ProcedureServer>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1729, aErrorI17Readin) == 1 )
      __debugbreak();
  }
  *v76 = 0;
  std::string::operator=((void *)(g_pGameType + 820), Str + 16);
  *v76 = 10;
  Str = (char *)strstr((char *)Buffer, "ProcedureServerPort=");
  if ( !Str )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed in phase <g_szProcServerPort>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1739, aErrorI18Readin) == 1 )
      __debugbreak();
  }
  v76 = (_BYTE *)strstr(Str, "\n");
  if ( !v76 )
  {
    CTrace::Print("GameHost.cpp: Internet game ini file malformed after phase <g_szProcServerPort>!", i);
    if ( BBSupportDbgReport(1, "Net\\GameHost.cpp", 1745, aErrorI19Readin) == 1 )
      __debugbreak();
  }
  *v76 = 0;
  *(_WORD *)(g_pGameType + 848) = j__strtol(Str + 20, &EndPtr, 10);
  *v76 = 10;
  v11 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD, int))(**((_DWORD **)v73 + 49) + 48))(
                        *((_DWORD *)v73 + 49),
                        *(_DWORD *)(g_pGameType + 68),
                        v32);
  CTrace::Print("GameHost.cpp: Host is %s", v11);
  *(_DWORD *)(g_pGameType + 620) = 0;
  if ( (unsigned __int8)CGameType::IsClanGame(g_pGameType) )
    *(_BYTE *)(g_pGameType + 875) = 0;
  v49 = *(_DWORD *)(g_pGameType + 112);
  for ( j = 0; j < v49; ++j )
  {
    j__sprintf((char *const)Dest, "PlayerTeam%d=", j);
    Str = (char *)strstr((char *)Buffer, (char *)Dest);
    if ( Str )
    {
      v32 = 10;
      v31 = (size_t)&EndPtr;
      v12 = j__strlen((const char *)Dest);
      v59 = j__strtol(&Str[v12], &EndPtr, 10);
      if ( v59 >= 0 )
        *(_DWORD *)(g_pGameType + 4 * j + 152) = v59;
    }
  }
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
  {
    if ( *(_BYTE *)(i + g_pGameType + 1007) )
      *(_DWORD *)(g_pGameType + 4 * i + 404) = 0;
    if ( !*(_DWORD *)(g_pGameType + 4 * i + 116) )
      ++*(_DWORD *)(g_pGameType + 620);
  }
  *(_DWORD *)(g_pGameType + 692) = 2;
  CGameType::SetWebGame((CGameType *)g_pGameType, 1);
  if ( (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD))(**((_DWORD **)v73 + 49) + 64))(
         *((_DWORD *)v73 + 49),
         *(_DWORD *)(g_pGameType + 68)) )
  {
    *((_BYTE *)v73 + 9) = 0;
    *((_BYTE *)v73 + 8) = 1;
    CFsm::Control(*((CFsm **)v73 + 3), 1007, 0);
    CFsm::Control(*((CFsm **)v73 + 3), 1051, 0);
  }
  else
  {
    Sleep(0x7D0u);
    j__memset(v80, 0, sizeof(v80));
    LOBYTE(v80[1]) = 1;
    LOBYTE(v80[150]) = 0;
    v80[148] = *(_DWORD *)(g_pGameType + 616);
    v80[151] = *(_DWORD *)(g_pGameType + 112);
    v31 = 512;
    v13 = std::wstring::c_str((_Cnd_internal_imp_t *)(g_pGameType + 28));
    MyWStrNCopy((int)&v80[20], (int)v13, v31);
    v80[152] = *(_DWORD *)(g_pGameType + 112);
    v80[149] = *(_DWORD *)(g_pGameType + 856);
    v80[2] = timeGetTime();
    v31 = 64;
    v14 = std::wstring::c_str((_Cnd_internal_imp_t *)g_pGameType);
    MyWStrNCopy((int)&v80[4], (int)v14, v31);
    v80[0] = *(_DWORD *)(g_pGameType + 68);
    LOBYTE(v80[156]) = CGameType::IsSaveGame((void *)g_pGameType);
    BYTE1(v80[158]) = *(_BYTE *)(g_pGameType + 697);
    v80[157] = *(_DWORD *)(g_pGameType + 700);
    v80[154] = CGameType::GetMultiPlayerGameID(g_pGameType);
    v80[155] = CGameType::GetMPSavegameID(g_pGameType);
    CGameHost::AddGame(v73, (struct SGameInfo *)v80);
    *((_BYTE *)v73 + 9) = 1;
    *((_BYTE *)v73 + 8) = 0;
    CFsm::Control(*((CFsm **)v73 + 3), 1008, 0);
    CFsm::Control(*((CFsm **)v73 + 3), 1024, 0);
  }
  v60 = CStateLobbyGameSettings::CompileUserFlags();
  if ( v60 && BBSupportDbgReportF(2, "Net\\GameHost.cpp", 1862, "CompileUserFlags() reported error %d!", v60) == 1 )
    __debugbreak();
  if ( BBSupportDbgReport(2, "Net\\GameHost.cpp", 1864, "false") == 1 )
    __debugbreak();
  v66 = 1;
  LOBYTE(v101) = 4;
  `eh vector destructor iterator'(v91, 0x1Cu, 9u, std::wstring::~wstring);
  LOBYTE(v101) = 0;
  std::wstring::~wstring(v88);
  v101 = -1;
  CFile::~CFile();
  return v66;
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
  
  const char *v1; // eax
  OnlineManager *Instance; // eax
  int v3; // eax
  int LocalPeerId; // esi
  int v5; // eax
  int v6; // eax
  DWORD Time; // eax
  OnlineManager *v8; // eax
  int v9; // eax
  int HostPeerId; // eax
  _BYTE v11[4]; // [esp+8h] [ebp-60h] BYREF
  unsigned __int16 *v12; // [esp+Ch] [ebp-5Ch]
  void *v13; // [esp+10h] [ebp-58h]
  void *v14; // [esp+14h] [ebp-54h]
  unsigned __int16 *v15; // [esp+18h] [ebp-50h]
  int v16; // [esp+1Ch] [ebp-4Ch]
  int v17; // [esp+20h] [ebp-48h]
  signed int ClientIndexPerPeerId; // [esp+24h] [ebp-44h]
  unsigned __int16 *v19; // [esp+28h] [ebp-40h] BYREF
  unsigned int v20; // [esp+2Ch] [ebp-3Ch] BYREF
  unsigned int i; // [esp+30h] [ebp-38h]
  unsigned __int16 v23; // [esp+38h] [ebp-30h]
  _BYTE v24[28]; // [esp+3Ch] [ebp-2Ch] BYREF
  int v25; // [esp+64h] [ebp-4h]

  v17 = 0;
  while ( (*(unsigned __int8 (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 49) + 24))(*((_DWORD *)this + 49), -1) )
  {
    ++v17;
    if ( !(*(unsigned __int8 (__thiscall **)(_DWORD, unsigned __int16 **, _BYTE *, unsigned int *))(**((_DWORD **)this + 49)
                                                                                                  + 28))(
            *((_DWORD *)this + 49),
            &v19,
            v11,
            &v20) )
    {
      v14 = (void *)(*(int (__thiscall **)(_DWORD, _BYTE *))(**((_DWORD **)this + 49) + 8))(*((_DWORD *)this + 49), v24);
      v13 = v14;
      v25 = 0;
      v1 = (const char *)std::string::c_str(v14);
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
            LocalPeerId == (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 49) + 40))(*((_DWORD *)this + 49))) )
      {
        CTrace::Print("CGameHost.cpp: Msg from localhost ignored!");
      }
      else
      {
        v23 = *v19;
        v16 = v23;
        if ( v23 == 3 )
        {
          if ( CClientList::ContainsPeerId(*((CClientList **)this + 4), v20) )
          {
            v15 = v19;
            *v19 = 4;
            v5 = (*(int (__thiscall **)(_DWORD, int, unsigned __int16 *, int, _DWORD, int))(**((_DWORD **)this + 49) + 36))(
                   *((_DWORD *)this + 49),
                   3105,
                   v15,
                   6,
                   0,
                   1);
            (*(void (__thiscall **)(_DWORD, unsigned int, int))(**((_DWORD **)this + 49) + 32))(
              *((_DWORD *)this + 49),
              v20,
              v5);
            if ( CFsm::CurrentState(*((CFsm **)this + 3)) == 5 )
              *((_DWORD *)this + 9) = timeGetTime();
          }
        }
        else if ( v16 == 4 )
        {
          v12 = v19;
          for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
          {
            v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 49) + 40))(*((_DWORD *)this + 49));
            if ( *(_DWORD *)(g_pGameType + 4 * i + 224) == v6 )
            {
              *(_DWORD *)(g_pGameType + 4 * i + 624) = timeGetTime() - *(_DWORD *)(v12 + 1);
              CLanLobby::RedrawPlayerList();
              ClientIndexPerPeerId = CClientList::GetClientIndexPerPeerId(*((CClientList **)this + 4), v20);
              if ( ClientIndexPerPeerId < 0 )
                j___wassert(L"index >= 0", L"Net\\GameHost.cpp", 0x440u);
              Time = timeGetTime();
              CClientList::SetClientLastAck(*((CClientList **)this + 4), ClientIndexPerPeerId, Time);
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
            || CClientList::ContainsPeerId(*((CClientList **)this + 4), v20)
            || (v8 = (OnlineManager *)OnlineManager::GetInstance(), OnlineManager::IsInSession(v8))
            && (v9 = StormManager::GetInstance(), HostPeerId = StormManager::GetHostPeerId(v9), v20 == HostPeerId) )
          {
            if ( v23 != 1000 || !*((_BYTE *)this + 9) && CFsm::CurrentState(*((CFsm **)this + 3)) != 17 )
              CFsm::Control(*((CFsm **)this + 3), v23, v19 + 1);
          }
        }
      }
    }
  }
}


// address=[0x15b8d70]
// Decompiled from void *__thiscall CGameHost::ConvertIPAddress(_DWORD **this, void *a2, int a3)

std::string  CGameHost::ConvertIPAddress(unsigned int) {
  
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

bool  CGameHost::RemovePlayerPeerId(unsigned int) {
  
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
// Decompiled from // public: bool __thiscall CGameHost::IsLocalIP(unsigned int)
char __thiscall CGameHost::IsLocalIP(_DWORD **this, int a2)

bool  CGameHost::IsLocalIP(unsigned int) {
  
  if ( this[49] )
    return (*(int (__thiscall **)(_DWORD *, int))(*this[49] + 64))(this[49], a2);
  else
    return 1;
}


// address=[0x15b9040]
// Decompiled from char __thiscall CGameHost::OnEndGame(CGameHost *this, int a2)

bool  CGameHost::OnEndGame(int) {
  
  return 1;
}


// address=[0x15b9050]
// Decompiled from void __thiscall CGameHost::OnEndSaving(CMsgStacks **this, int a2)

void  CGameHost::OnEndSaving(int) {
  
  CMsgStacks::OnEndSaving(this[5], *(_DWORD *)(g_pGameType + 112), a2);
}


// address=[0x15b9080]
// Decompiled from _DWORD *__thiscall CGameHost::StormJoinSessionSucceeded(CClientList **this)

void  CGameHost::StormJoinSessionSucceeded(void) {
  
  storm::SimpleSessionHandler **Instance; // eax
  _DWORD *v2; // eax
  void *v3; // eax
  char *v5; // [esp-8h] [ebp-74h]
  void *v6; // [esp+4h] [ebp-68h]
  _Cnd_internal_imp_t *PlayerName; // [esp+Ch] [ebp-60h]
  unsigned int HostPeerId; // [esp+1Ch] [ebp-50h]
  int LocalSlot; // [esp+20h] [ebp-4Ch]
  _BYTE v11[28]; // [esp+24h] [ebp-48h] BYREF
  _BYTE v12[28]; // [esp+40h] [ebp-2Ch] BYREF
  int v13; // [esp+68h] [ebp-4h]

  OutputDebugStringA("JoinSessionSucceeded\n");
  Instance = (storm::SimpleSessionHandler **)StormManager::GetInstance();
  HostPeerId = StormManager::GetHostPeerId(Instance);
  CClientList::Add(this[4], 0, 0, HostPeerId);
  if ( *(_BYTE *)(g_pGameType + 696) )
    LocalSlot = CGameType::GetLocalSlot(g_pGameType);
  else
    LocalSlot = -1;
  PlayerName = (_Cnd_internal_imp_t *)CGameSettings::GetPlayerName((int)v11);
  v13 = 0;
  v2 = std::wstring::c_str(PlayerName);
  v6 = storm::CStringConvertToUtf8(v12, (int)v2);
  LOBYTE(v13) = 1;
  v5 = (char *)std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str(v6);
  v3 = (void *)OnlineManager::GetInstance();
  OnlineManager::SendUnicastPlayerMessage(v3, HostPeerId, v5, (const struct storm::StormPlayerMessage *)LocalSlot);
  LOBYTE(v13) = 0;
  std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::~basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>(v12);
  v13 = -1;
  std::wstring::~wstring(v11);
  return CFsm::GenerateEvent(1057, 0);
}


// address=[0x15b91b0]
// Decompiled from int __stdcall CGameHost::StormHost_NewPlayerMessage(int a1, _Cnd_internal_imp_t *a2, char a3)

void  CGameHost::StormHost_NewPlayerMessage(unsigned int,std::wstring &,int) {
  
  const wchar_t *v3; // eax
  wchar_t Destination[32]; // [esp+4h] [ebp-6Ch] BYREF
  int v6; // [esp+45h] [ebp-2Bh]
  char v7; // [esp+62h] [ebp-Eh]
  char v8; // [esp+68h] [ebp-8h]

  v6 = a1;
  v3 = (const wchar_t *)std::wstring::c_str(a2);
  j__wcscpy(Destination, v3);
  v7 = *(_BYTE *)(g_pGameType + 696);
  v8 = a3;
  return CGameHost::ClientJoins(Destination);
}


// address=[0x15b9210]
// Decompiled from int __thiscall CGameHost::StormClientLeavesMyGame(CClientList **this, unsigned int a2)

void  CGameHost::StormClientLeavesMyGame(unsigned int) {
  
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

void  CGameHost::OnQuickMatched(bool) {
  
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
    j__wcsncpy(Destination, v1, 0x1Fu);
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
      j__wcsncpy(Destination, v2, 0x1Fu);
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
  int v4; // eax
  wchar_t *v5; // eax
  wchar_t *v6; // eax
  char v8; // [esp-40h] [ebp-F4h] BYREF
  int v9; // [esp-3Ch] [ebp-F0h]
  int v10; // [esp-38h] [ebp-ECh]
  int v11; // [esp-34h] [ebp-E8h]
  int v12; // [esp-30h] [ebp-E4h]
  int v13; // [esp-2Ch] [ebp-E0h]
  int v14; // [esp-28h] [ebp-DCh]
  char v15; // [esp-24h] [ebp-D8h]
  int v16; // [esp-20h] [ebp-D4h]
  int v17; // [esp-1Ch] [ebp-D0h] BYREF
  int v18; // [esp-18h] [ebp-CCh]
  int v19; // [esp-14h] [ebp-C8h]
  int v20; // [esp-10h] [ebp-C4h]
  int v21; // [esp-Ch] [ebp-C0h]
  int v22; // [esp-8h] [ebp-BCh]
  int v23; // [esp-4h] [ebp-B8h]
  int v24; // [esp+0h] [ebp-B4h]
  int v25; // [esp+4h] [ebp-B0h]
  char *v26; // [esp+8h] [ebp-ACh]
  int v27; // [esp+Ch] [ebp-A8h]
  int *v28; // [esp+10h] [ebp-A4h]
  CGameHost *v29; // [esp+14h] [ebp-A0h]
  int v30; // [esp+18h] [ebp-9Ch]
  int v31; // [esp+1Ch] [ebp-98h]
  CGameType *v32; // [esp+20h] [ebp-94h]
  void *v33; // [esp+24h] [ebp-90h]
  int v34; // [esp+28h] [ebp-8Ch]
  INetworkEngine *v35; // [esp+2Ch] [ebp-88h]
  BOOL v36; // [esp+30h] [ebp-84h]
  CGameType *v37; // [esp+34h] [ebp-80h]
  void *v38; // [esp+38h] [ebp-7Ch]
  CGameType *v39; // [esp+3Ch] [ebp-78h]
  INetworkEngine *v40; // [esp+40h] [ebp-74h]
  void *C; // [esp+44h] [ebp-70h]
  CDaoIndexFieldInfo *CurrentSession; // [esp+48h] [ebp-6Ch]
  int v43; // [esp+4Ch] [ebp-68h]
  _BYTE v44[28]; // [esp+50h] [ebp-64h] BYREF
  _BYTE v45[28]; // [esp+6Ch] [ebp-48h] BYREF
  _BYTE v46[28]; // [esp+88h] [ebp-2Ch] BYREF
  int v47; // [esp+B0h] [ebp-4h]

  v29 = this;
  Instance = StormManager::GetInstance();
  CurrentSession = (CDaoIndexFieldInfo *)StormManager::GetCurrentSession(Instance);
  v28 = &v17;
  v27 = std::wstring::wstring((int)&unk_4030720);
  CGameSettings::SetPlayerName(v17, v18);
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
    v24,
    v25);
  v47 = 0;
  GameSessionDescriptor::GetMapName(v45);
  if ( !g_pNetworkEngine )
  {
    C = operator new(0x18u);
    LOBYTE(v47) = 1;
    if ( C )
      v40 = INetworkEngine::INetworkEngine((INetworkEngine *)C, 1);
    else
      v40 = 0;
    v35 = v40;
    LOBYTE(v47) = 0;
    g_pNetworkEngine = (int)v40;
    INetworkEngine::Start(0, 0, 0, 0);
  }
  v23 = 0;
  v22 = 0;
  v21 = -1;
  v20 = -1;
  v19 = 0;
  v18 = 1;
  v17 = 1;
  v2 = (wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(0, 0);
  v26 = &v8;
  v25 = std::wstring::wstring(&v8, v2);
  HIBYTE(v43) = CGameType::LoadMapData(v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22, v23);
  if ( !HIBYTE(v43) )
  {
    v34 = g_pGameType;
    v39 = (CGameType *)g_pGameType;
    if ( g_pGameType )
      v33 = CGameType::`scalar deleting destructor'(v39, 1u);
    else
      v33 = 0;
    v38 = operator new(0x620u);
    LOBYTE(v47) = 2;
    if ( v38 )
      v37 = CGameType::CGameType((CGameType *)v38);
    else
      v37 = 0;
    v32 = v37;
    LOBYTE(v47) = 0;
    g_pGameType = (int)v37;
    v3 = (wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(
                      v24,
                      v25);
    std::wstring::operator=((void *)(g_pGameType + 28), v3);
    *(_BYTE *)(g_pGameType + 732) = 0;
  }
  storm::echo::SessionDescriptor::GetSessionName(CurrentSession);
  v4 = std::basic_string<char,std::char_traits<char>,storm::Allocator<char,1092620295>>::c_str(v24, v25);
  v31 = ((int (__cdecl *)(_BYTE *, int, int, int, char *, int, int *, CGameHost *, int, int, CGameType *, void *, int, INetworkEngine *, BOOL, CGameType *, void *, CGameType *, INetworkEngine *, void *, CDaoIndexFieldInfo *, int))storm::CStringConvertToUtf16)(
          v44,
          v4,
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
          v36,
          v37,
          v38,
          v39,
          v40,
          C,
          CurrentSession,
          v43);
  v30 = v31;
  LOBYTE(v47) = 3;
  v5 = (wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(
                    v24,
                    v25);
  std::wstring::operator=((void *)g_pGameType, v5);
  LOBYTE(v47) = 0;
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
    v24,
    v25);
  *(_DWORD *)(g_pGameType + 692) = 2;
  *(_DWORD *)(g_pGameType + 740) = 0;
  *(_DWORD *)(g_pGameType + 112) = GameSessionDescriptor::GetPeerCount(CurrentSession);
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
    v24,
    v25);
  LOBYTE(v47) = 4;
  GameSessionDescriptor::GetSaveFile(v46);
  v36 = std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::length(v46) != 0;
  *(_BYTE *)(g_pGameType + 696) = v36;
  *(_BYTE *)(g_pGameType + 697) = 0;
  if ( *(_BYTE *)(g_pGameType + 696) )
  {
    v6 = (wchar_t *)std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::c_str(
                      v24,
                      v25);
    std::wstring::operator=((void *)(g_pGameType + 704), v6);
    if ( *(_BYTE *)(g_pGameType + 697) )
      std::wstring::operator+=((void *)(g_pGameType + 704), (wchar_t *)L"_autoSave");
    std::wstring::operator+=((void *)(g_pGameType + 704), (wchar_t *)L".sav");
  }
  CLanLobby::Communicate(1024, (void *)dword_4030718);
  LOBYTE(v47) = 0;
  std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
    v24,
    v25);
  v47 = -1;
  return std::basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>::~basic_string<wchar_t,std::char_traits<wchar_t>,storm::Allocator<wchar_t,1092620295>>(
           v24,
           v25);
}


// address=[0x15b9860]
// Decompiled from int __thiscall sub_19B9860(_DWORD *this)

void  CGameHost::FillHandlersArray(void) {
  
  int result; // eax

  *(_DWORD *)(this[1] + 0x88) = CGameHost::StartState;
  *(_DWORD *)(this[1] + 4) = CGameHost::InitHostNetwork;
  *(_DWORD *)(this[1] + 8) = CGameHost::InitClientNetwork;
  *(_DWORD *)(this[1] + 12) = CGameHost::OnHostWait;
  *(_DWORD *)(this[1] + 16) = CGameHost::SearchHost;
  *(_DWORD *)(this[1] + 0x40) = CGameHost::WaitingForGameConnect;
  *(_DWORD *)(this[1] + 72) = CGameHost::HostInitGame;
  *(_DWORD *)(this[1] + 76) = CGameHost::HostStartTick;
  *(_DWORD *)(this[1] + 92) = CGameHost::RegClientConnect;
  *(_DWORD *)(this[1] + 96) = CGameHost::WereConnectedForGame;
  *(_DWORD *)(this[1] + 0x68) = CGameHost::ClientStartingGame;
  *(_DWORD *)(this[1] + 112) = CGameHost::ClientGameInited;
  *(_DWORD *)(this[1] + 116) = CGameHost::ClientStartTick;
  *(_DWORD *)(this[1] + 0x7C) = CGameHost::HostGameInited;
  *(_DWORD *)(this[1] + 0x80) = CGameHost::GameSyncMsgGot;
  *(_DWORD *)(this[1] + 132) = CGameHost::GameInGameMsgGot;
  *(_DWORD *)this[1] = CGameHost::ErrorState;
  *(_DWORD *)(this[1] + 144) = CGameHost::DoNothing;
  *(_DWORD *)(this[1] + 140) = CGameHost::ClientSearchesGameHost;
  *(_DWORD *)(this[1] + 152) = CGameHost::ClientReceivesGameInfo;
  *(_DWORD *)(this[1] + 160) = CGameHost::ClientLoginHost;
  *(_DWORD *)(this[1] + 156) = CGameHost::ClientJoins;
  *(_DWORD *)(this[1] + 0xA8) = CGameHost::ClientReceivePlayerData;
  *(_DWORD *)(this[1] + 172) = CGameHost::ClientReceivePlayerPing;
  *(_DWORD *)(this[1] + 164) = CGameHost::ClientLobbyPrepare;
  *(_DWORD *)(this[1] + 24) = CGameHost::ResendPlayerData;
  *(_DWORD *)(this[1] + 176) = CGameHost::ResendPlayerPing;
  *(_DWORD *)(this[1] + 28) = CGameHost::InitGameStruct;
  *(_DWORD *)(this[1] + 32) = CGameHost::HostPressedStart;
  *(_DWORD *)(this[1] + 0x24) = CGameHost::ResendFinalPData;
  *(_DWORD *)(this[1] + 0xB4) = CGameHost::ChatLine;
  *(_DWORD *)(this[1] + 0xB8) = CGameHost::GameAlreadyFull;
  *(_DWORD *)(this[1] + 0xBC) = CGameHost::GameAsyncMsgGot;
  *(_DWORD *)(this[1] + 192) = CGameHost::AmIStillAlive;
  *(_DWORD *)(this[1] + 196) = CGameHost::HeIsStillAlive;
  *(_DWORD *)(this[1] + 200) = CGameHost::InitHostAfterLobby;
  *(_DWORD *)(this[1] + 204) = CGameHost::InitClientAfterLobby;
  *(_DWORD *)(this[1] + 208) = CGameHost::SendMapToClient;
  *(_DWORD *)(this[1] + 212) = CGameHost::ClientReceiveMap;
  *(_DWORD *)(this[1] + 224) = CGameHost::ClientLeavesMyGame;
  *(_DWORD *)(this[1] + 228) = CGameHost::ClientWrongVersion;
  *(_DWORD *)(this[1] + 232) = CGameHost::ClientWrongVersionAfterLobby;
  *(_DWORD *)(this[1] + 236) = CGameHost::PerformLeaveGame;
  *(_DWORD *)(this[1] + 244) = CGameHost::SendChatLine;
  *(_DWORD *)(this[1] + 240) = CGameHost::HostChoseMap;
  *(_DWORD *)(this[1] + 272) = CGameHost::QuickMatchChoseMap;
  *(_DWORD *)(this[1] + 284) = CGameHost::InviteAccepted;
  *(_DWORD *)(this[1] + 0xF8) = CGameHost::UserDataChange;
  *(_DWORD *)(this[1] + 0xFC) = CGameHost::KickClient;
  *(_DWORD *)(this[1] + 256) = CGameHost::WereKicked;
  *(_DWORD *)(this[1] + 260) = CGameHost::GameInGamePackedGot;
  *(_DWORD *)(this[1] + 264) = CGameHost::GameSync0MsgGot;
  result = this[1];
  *(_DWORD *)(result + 268) = CGameHost::UserChangeSlots;
  return result;
}


// address=[0x15b9cd0]
// Decompiled from char __thiscall CGameHost::OnHostWait(CGameHost *this, void *a2)

bool  CGameHost::OnHostWait(void *) {
  
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

bool  CGameHost::InitHostNetwork(void *) {
  
  *((_BYTE *)this + 8) = 1;
  return 1;
}


// address=[0x15b9dc0]
// Decompiled from char __thiscall CGameHost::InitClientNetwork(CGameHost *this, void *a2)

bool  CGameHost::InitClientNetwork(void *) {
  
  *((_BYTE *)this + 9) = 1;
  CFsm::GenerateEvent(1010, 0);
  return 1;
}


// address=[0x15b9df0]
// Decompiled from char __thiscall CGameHost::ErrorState(int this, int a2)

bool  CGameHost::ErrorState(void *) {
  
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

void  CGameHost::ProcessPlayerData(struct SLobbyPlayerData &) {
  
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
  j__memcpy((void *)(g_pGameType + 784), (const void *)(a1 + 98), 7u);
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

void  CGameHost::SendPlayerData(unsigned int) {
  
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
    j__memset(Src, 0, 0x77u);
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
    j__memcpy(&Src[98], (const void *)(g_pGameType + 784), 7u);
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
// Decompiled from void __thiscall CGameHost::SendToAll(int this, int a2, void *Src, size_t Size, void *a5, size_t a6, char a7)

void  CGameHost::SendToAll(unsigned int,short *,unsigned int,short *,unsigned int,bool) {
  
  int v7; // eax
  unsigned int PlayerPeerId; // eax
  int PlayerIP; // [esp-18h] [ebp-42Ch]
  int i; // [esp+0h] [ebp-414h]
  unsigned __int8 v12; // [esp+Bh] [ebp-409h]
  __int16 v13; // [esp+Ch] [ebp-408h] BYREF
  _BYTE v14[1026]; // [esp+Eh] [ebp-406h] BYREF

  if ( Src
    && !Size
    && BBSupportDbgReportF(
         2,
         "Net\\GameHost.cpp",
         4618,
         "Fatal: _pvData0 set, but _uiDataLength0 == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1 )
  {
    __debugbreak();
  }
  if ( a5
    && !a6
    && BBSupportDbgReportF(
         2,
         "Net\\GameHost.cpp",
         4622,
         "Fatal: _pvData1 set, but _uiDataLength1 == 0. Did you intend to use m_iData as 32-bit data value instead of ptr?") == 1 )
  {
    __debugbreak();
  }
  if ( *(_BYTE *)(this + 10) )
  {
    for ( i = 0; ; ++i )
    {
      CClientList::GetSize(*(CDaoIndexFieldInfo **)(this + 16));
      if ( i >= v7 )
        break;
      v13 = a2;
      if ( Src )
      {
        j__memcpy(v14, Src, Size);
      }
      else if ( Size && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4637, "!_uiDataLength0") == 1 )
      {
        __debugbreak();
      }
      if ( a5 )
      {
        if ( !Src && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4642, "_pvData0") == 1 )
          __debugbreak();
        j__memcpy(&v14[Size], a5, a6);
      }
      else if ( a6 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4647, "!_uiDataLength1") == 1 )
      {
        __debugbreak();
      }
      v12 = 1;
      if ( a2 == 1055 || a2 == 3 || a2 == 1040 )
        v12 = 0;
      PlayerIP = CClientList::GetPlayerIP(*(CClientList **)(this + 16), i);
      PlayerPeerId = CClientList::GetPlayerPeerId(*(CClientList **)(this + 16), i);
      (*(void (__thiscall **)(_DWORD, unsigned int, int, int, __int16 *, size_t, _DWORD, _DWORD))(**(_DWORD **)(this + 196)
                                                                                                + 32))(
        *(_DWORD *)(this + 196),
        PlayerPeerId,
        PlayerIP,
        3105,
        &v13,
        Size + a6 + 2,
        (unsigned __int8)a7,
        v12);
    }
  }
}


// address=[0x15ba650]
// Decompiled from _DWORD *__thiscall CGameHost::SendToHost(_DWORD *this, int a2, void *Src, size_t Size, void *a5, size_t a6, char a7)

void  CGameHost::SendToHost(unsigned int,short *,unsigned int,short *,unsigned int,bool) {
  
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
    j__memcpy(v14, Src, Size);
  }
  else if ( Size && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4687, "!_uiDataLength0") == 1 )
  {
    __debugbreak();
  }
  if ( a5 )
  {
    if ( !Src && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4692, "_pvData0") == 1 )
      __debugbreak();
    j__memcpy(&v14[Size], a5, a6);
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

bool  CGameHost::AddGame(struct SGameInfo &) {
  
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

int  CGameHost::GetSlot(unsigned int) {
  
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

void  CGameHost::NotifyClients(unsigned int) {
  
  unsigned int ValidTick; // eax
  unsigned int v3; // eax
  const wchar_t *v4; // eax
  const wchar_t *v5; // eax
  size_t v6; // [esp-4h] [ebp-F0h]
  size_t v7; // [esp+8h] [ebp-E4h]
  _Cnd_internal_imp_t *v8; // [esp+Ch] [ebp-E0h]
  _Cnd_internal_imp_t *PlayerName; // [esp+10h] [ebp-DCh]
  CEvn_Event *v10; // [esp+18h] [ebp-D4h]
  struct CEvn_Logic *v11; // [esp+20h] [ebp-CCh]
  int v12; // [esp+28h] [ebp-C4h]
  unsigned int LastMsgTime; // [esp+30h] [ebp-BCh]
  signed int Time; // [esp+34h] [ebp-B8h]
  int j; // [esp+38h] [ebp-B4h]
  unsigned int i; // [esp+40h] [ebp-ACh]
  char v18; // [esp+47h] [ebp-A5h]
  _BYTE v19[32]; // [esp+48h] [ebp-A4h] BYREF
  _BYTE v20[28]; // [esp+68h] [ebp-84h] BYREF
  _BYTE v21[28]; // [esp+84h] [ebp-68h] BYREF
  CEvn_Event v22; // [esp+A0h] [ebp-4Ch] BYREF
  char Dest[36]; // [esp+B8h] [ebp-34h] BYREF
  int v24; // [esp+E8h] [ebp-4h]

  v18 = 0;
  Time = timeGetTime();
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
  {
    if ( (a2 & (1 << i)) != 0 && i != CGameHost::GetLocalID(this) )
    {
      LastMsgTime = CMsgStacks::GetLastMsgTime(*((CMsgStacks **)this + 5), i);
      if ( LastMsgTime )
      {
        if ( (int)(LastMsgTime + CStaticConfigVarInt::operator int(&g_iNotReadyKickDelay)) >= Time )
        {
          if ( (int)(LastMsgTime + CStaticConfigVarInt::operator int(&g_iNotReadyWarnDelay)) < Time
            && (!*((_DWORD *)this + 48)
             || *((_DWORD *)this + 48) + CStaticConfigVarInt::operator int(&g_iNotReadyWarnAgainDelay) < (unsigned int)Time) )
          {
            CTrace::Print("CGameHost.cpp: Waiting for Player index#%d !", i);
            *((_DWORD *)this + 48) = Time;
            PlayerName = (_Cnd_internal_imp_t *)CGameType::GetPlayerName((void *)g_pGameType, v20, i);
            v24 = 2;
            v4 = (const wchar_t *)std::wstring::c_str(PlayerName);
            v6 = j__wcslen(v4);
            v8 = (_Cnd_internal_imp_t *)CGameType::GetPlayerName((void *)g_pGameType, v21, i);
            v5 = (const wchar_t *)std::wstring::c_str(v8);
            v7 = j__wcstombs(Dest, v5, v6);
            std::wstring::~wstring(v21);
            v24 = -1;
            std::wstring::~wstring(v20);
            if ( v7 >= 0x21 )
              j____report_rangecheckfailure();
            Dest[v7] = 0;
            CTextMsgHandler::AddTextMsg(2261, i + 1, 0, 1, Dest);
            v18 = 1;
          }
        }
        else
        {
          CTrace::Print("GameHost.cpp: Kicking player index#%d!", i);
          v12 = *(_DWORD *)(g_pGameType + 4 * i + 224);
          for ( j = 1; j <= CPlayerManager::LastPlayerId() && CPlayerManager::PeerId(j) != v12; ++j )
            ;
          CGameHost::RemovePlayerPeerId(this, *(_DWORD *)(g_pGameType + 4 * i + 224));
          ValidTick = CGameHost::GetValidTick(this);
          v11 = CEvn_Logic::CEvn_Logic((CEvn_Logic *)v19, 0xFA9u, j, ValidTick, j, 0, 0);
          v24 = 0;
          INetworkEngine::SendAsyncNetMessage((INetworkEngine *)g_pNetworkEngine, v11, 255);
          v24 = -1;
          CEvn_Logic::~CEvn_Logic(v19);
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

bool  CGameHost::IsExclusiveColor(int) {
  
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

bool  CGameHost::HostChoseMap(void *) {
  
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
    j__wcsncpy(Destination, v2, 0x1Fu);
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
      j__wcsncpy(Destination, v3, 0x1Fu);
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

bool  CGameHost::QuickMatchChoseMap(void *) {
  
  int v2; // [esp-4h] [ebp-8h]

  v2 = g_pGameType;
  OnlineManager::GetInstance();
  OnlineManager::QuickMatch(v2);
  return 1;
}


// address=[0x15bb3b0]
// Decompiled from char __thiscall CGameHost::InviteAccepted(CGameHost *this, int a2)

bool  CGameHost::InviteAccepted(void *) {
  
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

bool  CGameHost::StartState(void *) {
  
  return 0;
}


// address=[0x15bb440]
// Decompiled from char __thiscall SearchHost(void *this, int a2)

bool  CGameHost::SearchHost(void *) {
  
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

bool  CGameHost::ClientSearchesGameHost(void *) {
  
  _DWORD *v2; // eax
  _DWORD *v3; // eax
  int v4; // eax
  int v5; // eax
  _WORD v8[514]; // [esp+18h] [ebp-460h] BYREF
  _BYTE v9[44]; // [esp+41Ch] [ebp-5Ch] BYREF
  int v10; // [esp+448h] [ebp-30h] BYREF
  int v11; // [esp+474h] [ebp-4h]

  j__memset(v8, 0, 0x402u);
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

bool  CGameHost::ClientReceivesGameInfo(void *) {
  
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
  j__memcpy(v12, Src, MessageLength);
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
// Decompiled from char __thiscall CGameHost::ClientLoginHost(CGameHost *this, int a2)

bool  CGameHost::ClientLoginHost(void *) {
  
  int Instance; // eax
  int v3; // eax
  int v4; // eax
  const wchar_t *v5; // eax
  int v6; // eax
  const wchar_t *v7; // eax
  int v8; // eax
  OnlineManager *v9; // eax
  int v10; // eax
  int v11; // eax
  unsigned __int64 *v13; // [esp-4h] [ebp-1368h]
  _BYTE v14[12]; // [esp+4h] [ebp-1360h] BYREF
  _BYTE v15[12]; // [esp+10h] [ebp-1354h] BYREF
  _BYTE v16[12]; // [esp+1Ch] [ebp-1348h] BYREF
  int v17; // [esp+28h] [ebp-133Ch]
  int v18; // [esp+2Ch] [ebp-1338h]
  std::_Iterator_base12 *v19; // [esp+30h] [ebp-1334h]
  std::_Iterator_base12 *v20; // [esp+34h] [ebp-1330h]
  int CurrentSession; // [esp+38h] [ebp-132Ch]
  int v22; // [esp+3Ch] [ebp-1328h]
  int v23; // [esp+40h] [ebp-1324h]
  char v24; // [esp+46h] [ebp-131Eh]
  char v25; // [esp+47h] [ebp-131Dh]
  CGameHost *v26; // [esp+48h] [ebp-131Ch]
  _BYTE v27[2408]; // [esp+4Ch] [ebp-1318h] BYREF
  _BYTE v28[2408]; // [esp+9B4h] [ebp-9B0h] BYREF
  _BYTE v29[28]; // [esp+131Ch] [ebp-48h] BYREF
  _BYTE v30[28]; // [esp+1338h] [ebp-2Ch] BYREF
  int v31; // [esp+1360h] [ebp-4h]

  v26 = this;
  std::wstring::wstring(v30);
  v31 = 0;
  Instance = OnlineManager::GetInstance();
  if ( (unsigned __int8)OnlineManager::IsQuickMatchFlow(Instance)
    || (v3 = OnlineManager::GetInstance(), (unsigned __int8)OnlineManager::IsInviteFlow(v3)) )
  {
    v4 = StormManager::GetInstance();
    CurrentSession = StormManager::GetCurrentSession(v4);
    *(_DWORD *)(g_pGameType + 112) = GameSessionDescriptor::GetPeerCount(CurrentSession);
    *(_DWORD *)(g_pGameType + 700) = GameSessionDescriptor::GetTickCount(CurrentSession);
    *((_BYTE *)v26 + 8) = 0;
    *((_BYTE *)v26 + 9) = 1;
    std::wstring::operator=(g_pGameType + 704);
    CGameChunkGeneral::CGameChunkGeneral(v28);
    (*(void (__thiscall **)(void *, _BYTE *))(*(_DWORD *)g_pRandomMaps + 52))(g_pRandomMaps, v30);
    v5 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v30);
    CGameRun::LoadGeneralInfo(v5, (struct CGameChunkGeneral *)v28);
    while ( 1 )
    {
      CClientList::GetSize(*((CDaoIndexFieldInfo **)v26 + 4));
      if ( !v6 )
        break;
      CClientList::RemoveClientAt(0);
    }
    CGameType::SetLocalSlot((CGameType *)g_pGameType, v28[2364]);
  }
  else
  {
    v18 = a2;
    v22 = 0;
    std::list<SGameInfo>::begin(v16);
    LOBYTE(v31) = 1;
    while ( 1 )
    {
      v20 = (std::_Iterator_base12 *)std::list<SGameInfo>::end(v14);
      v19 = v20;
      LOBYTE(v31) = 2;
      v25 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator!=(v20);
      LOBYTE(v31) = 1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v14);
      if ( !v25 || v22 == v18 )
        break;
      ++v22;
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator++(v15, 0);
      std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v15);
    }
    v23 = std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::operator*(v16);
    *(_DWORD *)(g_pGameType + 112) = *(_DWORD *)(v23 + 604);
    *(_DWORD *)(g_pGameType + 856) = *(_DWORD *)(v23 + 596);
    *(_DWORD *)(g_pGameType + 700) = *(_DWORD *)(v23 + 628);
    v17 = std::wstring::wstring(v29, (wchar_t *)(v23 + 648));
    std::wstring::operator=(v17);
    std::wstring::~wstring(v29);
    if ( *(_BYTE *)(v23 + 633) )
      std::wstring::operator+=(v30, (wchar_t *)L"_autoSave");
    std::wstring::operator+=(v30, (wchar_t *)L".sav");
    CGameChunkGeneral::CGameChunkGeneral(v27);
    (*(void (__thiscall **)(void *, _BYTE *))(*(_DWORD *)g_pRandomMaps + 52))(g_pRandomMaps, v30);
    v7 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v30);
    CGameRun::LoadGeneralInfo(v7, (struct CGameChunkGeneral *)v27);
    CGameType::SetLocalSlot((CGameType *)g_pGameType, v27[2364]);
    while ( 1 )
    {
      CClientList::GetSize(*((CDaoIndexFieldInfo **)v26 + 4));
      if ( !v8 )
        break;
      CClientList::RemoveClientAt(0);
    }
    v13 = (unsigned __int64 *)(v23 + 640);
    v9 = (OnlineManager *)OnlineManager::GetInstance();
    OnlineManager::JoinSession(v9, v13);
    LOBYTE(v31) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>::~_List_iterator<std::_List_val<std::_List_simple_types<SGameInfo>>>(v16);
  }
  *((_DWORD *)v26 + 14) = timeGetTime();
  v10 = OnlineManager::GetInstance();
  if ( (unsigned __int8)OnlineManager::IsQuickMatchFlow(v10)
    || (v11 = OnlineManager::GetInstance(), (unsigned __int8)OnlineManager::IsInviteFlow(v11)) )
  {
    CGameHost::StormJoinSessionSucceeded(v26);
  }
  v24 = 1;
  v31 = -1;
  std::wstring::~wstring(v30);
  return v24;
}


// address=[0x15bbdf0]
// Decompiled from char __thiscall CGameHost::ClientJoins(int this, void *Src)

bool  CGameHost::ClientJoins(void *) {
  
  unsigned int v3; // eax
  int NewPlayerID; // [esp-8h] [ebp-90h]
  int v5; // [esp+4h] [ebp-84h]
  int v6; // [esp+8h] [ebp-80h]
  unsigned int j; // [esp+Ch] [ebp-7Ch]
  unsigned int v8; // [esp+10h] [ebp-78h]
  int i; // [esp+14h] [ebp-74h]
  wchar_t v11[52]; // [esp+1Ch] [ebp-6Ch] BYREF

  j__memcpy(v11, Src, 0x65u);
  v8 = *(_DWORD *)((char *)&v11[32] + 1);
  if ( CClientList::ContainsPeerId(*(CClientList **)(this + 16), *(unsigned int *)((char *)&v11[32] + 1)) )
    return 1;
  if ( (unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType) )
  {
    if ( !CLanLobby::ConnectPlayer(v11, SLOBYTE(v11[50])) )
      return 1;
  }
  else
  {
    v5 = -1;
    if ( (unsigned __int8)CGameType::IsWebGame(g_pGameType) )
    {
      v5 = 8;
      for ( i = 0; i < 8; ++i )
      {
        if ( *(_DWORD *)(g_pGameType + 4 * i + 224) == *(_DWORD *)((char *)&v11[32] + 1) )
        {
          v5 = i;
          break;
        }
      }
    }
    if ( v5 == 8 || !CLanLobby::ConnectPlayer(v11, v5) )
      return 1;
  }
  if ( !CClientList::ContainsPeerId(*(CClientList **)(this + 16), v8) )
  {
    NewPlayerID = CClientList::CreateNewPlayerID(*(_DWORD *)(this + 16));
    v3 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 36))(*(_DWORD *)(this + 196));
    CClientList::Add(*(CClientList **)(this + 16), v3, NewPlayerID, v8);
  }
  v6 = -1;
  for ( j = 0; j < *(_DWORD *)(g_pGameType + 112) && v6 == -1; ++j )
  {
    if ( *(_DWORD *)(g_pGameType + 4 * j + 224) == v8 )
      v6 = j;
  }
  if ( v6 < 0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2508, "iLocalSlotID >=0") == 1 )
    __debugbreak();
  if ( v6 >= 0 )
    *(_BYTE *)(v6 + g_pGameType + 998) = 0;
  CLanLobby::RedrawPlayerList();
  CFsm::Control(*(CFsm **)(this + 12), 1035, 0);
  return 1;
}


// address=[0x15bc010]
// Decompiled from char __stdcall sub_19BC010(int a1)

bool  CGameHost::ClientWrongVersion(void *) {
  
  CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2412);
  CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 0);
  return 1;
}


// address=[0x15bc040]
// Decompiled from char __stdcall sub_19BC040(int a1)

bool  CGameHost::ClientWrongVersionAfterLobby(void *) {
  
  CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2414);
  CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
  return 1;
}


// address=[0x15bc070]
// Decompiled from char __thiscall CGameHost::ClientReceivePlayerData(int this, void *Src)

bool  CGameHost::ClientReceivePlayerData(void *) {
  
  unsigned __int16 MessageLength; // ax
  CEvn_Event *v4; // [esp+Ch] [ebp-ACh]
  _BYTE v6[120]; // [esp+18h] [ebp-A0h] BYREF
  CEvn_Event v7; // [esp+90h] [ebp-28h] BYREF
  int v8; // [esp+B4h] [ebp-4h]

  MessageLength = CGameHost::GetMessageLength((void *)this);
  j__memcpy(v6, Src, MessageLength);
  if ( v6[0] && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2685, "data.m_iFinal == PLAYERDATA_UPDATE") == 1 )
    __debugbreak();
  CGameHost::ProcessPlayerData((int)v6);
  if ( *(_BYTE *)(this + 77) )
    return 1;
  if ( !(unsigned __int8)CGameType::IsMapAvailable(g_pGameType + 28, *(_DWORD *)(g_pGameType + 616))
    && !(unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType)
    && !*(_BYTE *)(this + 76) )
  {
    CGameHost::SendToHost(1042, 0, 0, 0, 0, 1);
    v4 = CEvn_Event::CEvn_Event(&v7, 0x50u, 1u, 0, 0);
    v8 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v4);
    v8 = -1;
    CEvn_Event::~CEvn_Event(&v7);
    if ( *(_BYTE *)(this + 76) && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2699, "!m_bMapBeingDownloaded") == 1 )
      __debugbreak();
    *(_DWORD *)(this + 84) = *(_DWORD *)(g_pGameType + 856) / 0x300u;
    if ( *(_DWORD *)(g_pGameType + 856) % 0x300u )
      ++*(_DWORD *)(this + 84);
    *(_DWORD *)(this + 72) = operator new[](*(_DWORD *)(this + 84));
    j__memset(*(void **)(this + 72), 0, *(_DWORD *)(this + 84));
    *(_DWORD *)(this + 68) = operator new[](*(_DWORD *)(g_pGameType + 856));
    *(_DWORD *)(this + 80) = 0;
    *(_BYTE *)(this + 76) = 1;
    CTrace::Print(
      "GameHost.cpp: Map download scheduled. Waiting for %d bytes in %d blocks.!",
      *(_DWORD *)(g_pGameType + 856),
      *(_DWORD *)(this + 84));
  }
  *(_BYTE *)(this + 77) = 1;
  return 1;
}


// address=[0x15bc320]
// Decompiled from char __thiscall CGameHost::ClientReceivePlayerPing(void *this, void *Src)

bool  CGameHost::ClientReceivePlayerPing(void *) {
  
  unsigned __int16 MessageLength; // ax
  unsigned __int8 v4; // [esp+0h] [ebp-Ch] BYREF
  int v5; // [esp+1h] [ebp-Bh]
  void *v6; // [esp+8h] [ebp-4h]

  v6 = this;
  MessageLength = CGameHost::GetMessageLength(this);
  j__memcpy(&v4, Src, MessageLength);
  *(_DWORD *)(g_pGameType + 4 * v4 + 624) = v5;
  CLanLobby::RedrawPlayerList();
  return 1;
}


// address=[0x15bc370]
// Decompiled from char __thiscall sub_19BC370(void *this, int a2)

bool  CGameHost::ClientLobbyPrepare(void *) {
  
  std::list<SGameInfo>::clear(this);
  CGameStateHandler::Switch(CStateLobbyGameSettings::DynamicCreateFunc, 0);
  return 0;
}


// address=[0x15bc3a0]
// Decompiled from char __thiscall CGameHost::ResendPlayerData(void *this, int a2)

bool  CGameHost::ResendPlayerData(void *) {
  
  CGameHost::SendPlayerData(this, 0);
  return 1;
}


// address=[0x15bc3c0]
// Decompiled from char __thiscall CGameHost::ResendPlayerPing(_DWORD *this, int a2)

bool  CGameHost::ResendPlayerPing(void *) {
  
  _BYTE Src[8]; // [esp+0h] [ebp-10h] BYREF
  _DWORD *v4; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v4 = this;
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
  {
    j__memset(Src, 0, 5u);
    Src[0] = i;
    *(_DWORD *)&Src[1] = *(_DWORD *)(g_pGameType + 4 * i + 624);
    CGameHost::SendToAll((int)v4, 1034, Src, 5u, 0, 0, 1u);
  }
  v4[8] = timeGetTime();
  return 1;
}


// address=[0x15bc450]
// Decompiled from char __stdcall CGameHost::HostPressedStart(int a1)

bool  CGameHost::HostPressedStart(void *) {
  
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
  j__sprintf(
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

bool  CGameHost::InitGameStruct(void *) {
  
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
    j__memcpy(v6, Src, v3);
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

bool  CGameHost::ResendFinalPData(void *) {
  
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

bool  CGameHost::ChatLine(void *) {
  
  unsigned __int16 MessageLength; // ax
  wchar_t String[32]; // [esp+4h] [ebp-104h] BYREF
  wchar_t Source[96]; // [esp+44h] [ebp-C4h] BYREF

  MessageLength = CGameHost::GetMessageLength(this);
  j__memcpy(String, Src, MessageLength);
  if ( this[8] )
    CGameHost::SendToAll((int)this, 1036, String, 0x100u, 0, 0, 1u);
  CLanLobby::PrintChatLine(String, Source);
  return 1;
}


// address=[0x15bc7c0]
// Decompiled from char __stdcall sub_19BC7C0(int a1)

bool  CGameHost::GameAlreadyFull(void *) {
  
  CGameStateHandler::Queue(CStateMessageBox::DynamicCreateFunc, 2410);
  CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 0);
  return 1;
}


// address=[0x15bc7f0]
// Decompiled from char __thiscall CGameHost::SendMapToClient(int this, int a2)

bool  CGameHost::SendMapToClient(void *) {
  
  unsigned int v2; // eax
  CEvn_Event *v4; // [esp+8h] [ebp-4E0h]
  int v5; // [esp+14h] [ebp-4D4h]
  int v6; // [esp+18h] [ebp-4D0h]
  CEvn_Event *v7; // [esp+1Ch] [ebp-4CCh]
  int v8; // [esp+2Ch] [ebp-4BCh]
  int Slot; // [esp+30h] [ebp-4B8h]
  int i; // [esp+38h] [ebp-4B0h]
  __int16 v12; // [esp+40h] [ebp-4A8h] BYREF
  int v13; // [esp+42h] [ebp-4A6h]
  _BYTE v14[1022]; // [esp+46h] [ebp-4A2h] BYREF
  _BYTE v15[72]; // [esp+444h] [ebp-A4h] BYREF
  CEvn_Event v16; // [esp+48Ch] [ebp-5Ch] BYREF
  CEvn_Event v17; // [esp+4A4h] [ebp-44h] BYREF
  int v18[7]; // [esp+4BCh] [ebp-2Ch] BYREF
  int v19; // [esp+4E4h] [ebp-4h]

  if ( a2 )
  {
    v2 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 36))(*(_DWORD *)(this + 196));
    Slot = CGameHost::GetSlot((CGameHost *)this, v2);
    if ( *(_DWORD *)(this + 4 * Slot + 152) )
    {
      return 1;
    }
    else
    {
      *(_DWORD *)(this + 4 * Slot + 152) = operator new[](*(_DWORD *)(g_pGameType + 856));
      std::wstring::wstring(g_pGameType + 28);
      v19 = 0;
      CFile::CFile((CFile *)v15);
      LOBYTE(v19) = 1;
      CFile::Open((int)v18, 6, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
      CFile::Read(
        *(void **)(this + 4 * Slot + 152),
        *(_DWORD *)(g_pGameType + 856),
        1u,
        (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h",
        0);
      CFile::Close((CFile *)v15, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
      if ( ++*(_DWORD *)(this + 184) == 1 )
      {
        v7 = CEvn_Event::CEvn_Event(&v17, 0x50u, 1u, 0, 0);
        LOBYTE(v19) = 2;
        IEventEngine::SendAMessage(g_pEvnEngine, v7);
        LOBYTE(v19) = 1;
        CEvn_Event::~CEvn_Event(&v17);
      }
      if ( *(int *)(this + 184) >= 7
        && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2749, "m_iMapUpload < MAX_PLAYER - 1") == 1 )
      {
        __debugbreak();
      }
      *(_DWORD *)(this + 4 * Slot + 120) = *(_DWORD *)(g_pGameType + 856) / 0x300u;
      if ( *(_DWORD *)(g_pGameType + 856) % 0x300u )
        ++*(_DWORD *)(this + 4 * Slot + 120);
      *(_DWORD *)(g_pGameType + 4 * Slot + 452) = 1;
      LOBYTE(v19) = 0;
      CFile::~CFile();
      v19 = -1;
      std::wstring::~wstring(v18);
      return 1;
    }
  }
  else
  {
    for ( i = 0; i < 8; ++i )
    {
      if ( *(_DWORD *)(this + 4 * i + 0x98) )
      {
        if ( *(_DWORD *)(g_pGameType + 4 * i + 188) == (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 16))(*(_DWORD *)(this + 196))
          && BBSupportDbgReport(
               2,
               "Net\\GameHost.cpp",
               2766,
               "g_pGameType->m_uiIPPlayer[ iSlot ] != m_pSimpleNet->GetCurrentLocalIPLong()") == 1 )
        {
          __debugbreak();
        }
        v12 = 1043;
        v6 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 36))(*(_DWORD *)(this + 196));
        v5 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 40))(*(_DWORD *)(this + 196));
        if ( *(_DWORD *)(this + 4 * i + 88) >= *(_DWORD *)(this + 4 * i + 120) )
        {
          if ( *(_DWORD *)(this + 4 * i + 152) )
          {
            operator delete(*(void **)(this + 4 * i + 152));
            *(_DWORD *)(this + 4 * i + 152) = 0;
          }
          *(_DWORD *)(this + 4 * i + 88) = 0;
          if ( !--*(_DWORD *)(this + 184) )
          {
            v4 = CEvn_Event::CEvn_Event(&v16, 0x50u, 0, 0, 0);
            v19 = 3;
            IEventEngine::SendAMessage(g_pEvnEngine, v4);
            v19 = -1;
            CEvn_Event::~CEvn_Event(&v16);
          }
          if ( *(int *)(this + 184) < 0 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 2804, "m_iMapUpload >= 0") == 1 )
            __debugbreak();
          *(_DWORD *)(g_pGameType + 4 * i + 452) = 0;
        }
        else
        {
          v13 = *(_DWORD *)(this + 4 * i + 88);
          v8 = 768 * *(_DWORD *)(this + 4 * i + 88);
          if ( (unsigned int)(v8 + 768) <= *(_DWORD *)(g_pGameType + 856) )
            j__memcpy(v14, (const void *)(v8 + *(_DWORD *)(this + 4 * i + 152)), 0x300u);
          else
            j__memcpy(v14, (const void *)(v8 + *(_DWORD *)(this + 4 * i + 152)), *(_DWORD *)(g_pGameType + 856) - v8);
          (*(void (__thiscall **)(_DWORD, int, int, int, __int16 *, int, int, int))(**(_DWORD **)(this + 196) + 32))(
            *(_DWORD *)(this + 196),
            v5,
            v6,
            3105,
            &v12,
            774,
            1,
            1);
          CTrace::Print("GameHost.cpp: Map block sent. Block %d!", v13);
          ++*(_DWORD *)(this + 4 * i + 88);
        }
      }
    }
    return 1;
  }
}


// address=[0x15bce20]
// Decompiled from char __thiscall CGameHost::ClientReceiveMap(void **this, void *Src)

bool  CGameHost::ClientReceiveMap(void *) {
  
  unsigned __int16 MessageLength; // ax
  char IsWebGame; // si
  char v4; // si
  unsigned __int16 v5; // ax
  char v7; // [esp-40h] [ebp-71Ch] BYREF
  int v8; // [esp-3Ch] [ebp-718h]
  int v9; // [esp-38h] [ebp-714h]
  int v10; // [esp-34h] [ebp-710h]
  int v11; // [esp-30h] [ebp-70Ch]
  int v12; // [esp-2Ch] [ebp-708h]
  int v13; // [esp-28h] [ebp-704h]
  int v14; // [esp-24h] [ebp-700h]
  int v15; // [esp-20h] [ebp-6FCh]
  int v16; // [esp-1Ch] [ebp-6F8h]
  int v17; // [esp-18h] [ebp-6F4h]
  int v18; // [esp-14h] [ebp-6F0h]
  int v19; // [esp-10h] [ebp-6ECh]
  int v20; // [esp-Ch] [ebp-6E8h]
  int v21; // [esp-8h] [ebp-6E4h]
  int v22; // [esp-4h] [ebp-6E0h]
  int v23; // [esp+8h] [ebp-6D4h]
  char *v24; // [esp+Ch] [ebp-6D0h]
  CEvn_Event *v25; // [esp+10h] [ebp-6CCh]
  CEvn_Event *v26; // [esp+14h] [ebp-6C8h]
  CEvn_Event *v27; // [esp+18h] [ebp-6C4h]
  CEvn_Event *v28; // [esp+1Ch] [ebp-6C0h]
  void *v29; // [esp+20h] [ebp-6BCh]
  void *C; // [esp+24h] [ebp-6B8h]
  size_t Size; // [esp+28h] [ebp-6B4h]
  void **v32; // [esp+2Ch] [ebp-6B0h]
  _BYTE *v33; // [esp+30h] [ebp-6ACh] BYREF
  _BYTE v34[768]; // [esp+34h] [ebp-6A8h] BYREF
  _DWORD v35[193]; // [esp+334h] [ebp-3A8h] BYREF
  _BYTE v36[72]; // [esp+638h] [ebp-A4h] BYREF
  CEvn_Event v37; // [esp+680h] [ebp-5Ch] BYREF
  CEvn_Event v38; // [esp+698h] [ebp-44h] BYREF
  int v39[7]; // [esp+6B0h] [ebp-2Ch] BYREF
  int v40; // [esp+6D8h] [ebp-4h]

  v32 = this;
  if ( *((_BYTE *)this + 76) )
  {
    MessageLength = CGameHost::GetMessageLength(v32);
    j__memcpy(&v33, Src, MessageLength);
    if ( !v33[(_DWORD)v32[18]] )
    {
      Size = v33 == (char *)v32[21] - 1 ? *(_DWORD *)(g_pGameType + 856) % 0x300u : 768;
      j__memcpy((char *)v32[17] + 768 * (_DWORD)v33, v34, Size);
      v33[(_DWORD)v32[18]] = 1;
      v32[20] = (char *)v32[20] + 1;
      CTrace::Print("GameHost.cpp: Map block arrived. Got block %d, count is %d/%d!", v33, v32[20], v32[21]);
      if ( v32[21] == v32[20] )
      {
        *((_BYTE *)v32 + 76) = 0;
        std::wstring::wstring(g_pGameType + 28);
        v40 = 0;
        CFile::CFile((CFile *)v36);
        LOBYTE(v40) = 1;
        CFile::Open((int)v39, 10, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
        CFile::Write(
          v32[17],
          *(_DWORD *)(g_pGameType + 856),
          1u,
          (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h",
          0);
        CFile::Close((CFile *)v36, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
        C = v32[18];
        operator delete[](C);
        v32[18] = 0;
        v29 = v32[17];
        operator delete[](v29);
        v32[17] = 0;
        if ( (unsigned __int8)CGameType::IsMapAvailable(g_pGameType + 28, *(_DWORD *)(g_pGameType + 616)) )
        {
          v26 = CEvn_Event::CEvn_Event(&v37, 0x50u, 0, 0, 0);
          v25 = v26;
          LOBYTE(v40) = 3;
          IEventEngine::SendAMessage(g_pEvnEngine, v26);
          LOBYTE(v40) = 1;
          CEvn_Event::~CEvn_Event(&v37);
          CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2416);
          CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 0);
        }
        else
        {
          IsWebGame = CGameType::IsWebGame(g_pGameType);
          LOBYTE(v22) = CGameType::IsClanGame(g_pGameType) & IsWebGame;
          v22 = (unsigned __int8)v22;
          v4 = CGameType::IsWebGame(g_pGameType);
          LOBYTE(v21) = CGameType::IsLadderGame(g_pGameType) & v4;
          v21 = (unsigned __int8)v21;
          v20 = -1;
          v19 = -1;
          v18 = 0;
          v17 = 1;
          v16 = 1;
          v15 = *(_DWORD *)(g_pGameType + 68);
          v14 = 0;
          v24 = &v7;
          v23 = std::wstring::wstring(g_pGameType + 28);
          CGameType::LoadMapData(v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22);
          CLanLobby::RedrawMap();
          v28 = CEvn_Event::CEvn_Event(&v38, 0x50u, 0, 0, 0);
          v27 = v28;
          LOBYTE(v40) = 2;
          IEventEngine::SendAMessage(g_pEvnEngine, v28);
          LOBYTE(v40) = 1;
          CEvn_Event::~CEvn_Event(&v38);
        }
        LOBYTE(v40) = 0;
        CFile::~CFile();
        v40 = -1;
        std::wstring::~wstring(v39);
      }
    }
  }
  else
  {
    v5 = CGameHost::GetMessageLength(v32);
    j__memcpy(v35, Src, v5);
    CTrace::Print("GameHost.cpp: Mapdata block %d without request got !!", v35[0]);
  }
  return 1;
}


// address=[0x15bd220]
// Decompiled from char __thiscall RemoveClient(_DWORD **this, int a2)

bool  CGameHost::ClientLeavesMyGame(void *) {
  
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

bool  CGameHost::PerformLeaveGame(void *) {
  
  int v2; // eax

  v2 = OnlineManager::GetInstance(this);
  OnlineManager::LeaveSession(v2);
  return 1;
}


// address=[0x15bd2b0]
// Decompiled from char __thiscall CGameHost::SendChatLine(_BYTE *this, wchar_t *Source)

bool  CGameHost::SendChatLine(void *) {
  
  _DWORD *v2; // eax
  wchar_t *v3; // eax
  _Cnd_internal_imp_t *v5; // [esp+4h] [ebp-15Ch]
  _Cnd_internal_imp_t *PlayerName; // [esp+Ch] [ebp-154h]
  _BYTE Src[256]; // [esp+18h] [ebp-148h] BYREF
  _BYTE v9[28]; // [esp+118h] [ebp-48h] BYREF
  _BYTE v10[28]; // [esp+134h] [ebp-2Ch] BYREF
  int v11; // [esp+15Ch] [ebp-4h]

  j__memset(Src, 0, sizeof(Src));
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

bool  CGameHost::UserDataChange(void *) {
  
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

bool  CGameHost::KickClient(void *) {
  
  unsigned int v4; // [esp+4h] [ebp-Ch]
  __int16 v5; // [esp+Ch] [ebp-4h] BYREF

  v4 = *(_DWORD *)(g_pGameType + 4 * a2 + 224);
  CLanLobby::DisconnectPlayerPeerId(v4, -1);
  CClientList::RemoveClientPeerId((CClientList *)this[4], v4);
  *(_BYTE *)(a2 + g_pGameType + 998) = 1;
  v5 = 1053;
  (*(void (__thiscall **)(_DWORD *, unsigned int, _DWORD, int, __int16 *, int, _DWORD, int))(*this[49] + 32))(
    this[49],
    v4,
    *(_DWORD *)(g_pGameType + 4 * a2 + 188),
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

bool  CGameHost::WereKicked(void *) {
  
  void *v2; // eax

  v2 = (void *)OnlineManager::GetInstance((int)this);
  OnlineManager::LeaveSession(v2);
  CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2494);
  CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 0);
  return 1;
}


// address=[0x15bda70]
// Decompiled from char __thiscall CGameHost::UserChangeSlots(CGameHost *this, unsigned int *a2)

bool  CGameHost::UserChangeSlots(void *) {
  
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

bool  CGameHost::InitHostAfterLobby(void *) {
  
  this[8] = 1;
  CFsm::GenerateEvent(1009, 0);
  return 1;
}


// address=[0x15bde90]
// Decompiled from char __thiscall sub_19BDE90(_BYTE *this, int a2)

bool  CGameHost::InitClientAfterLobby(void *) {
  
  this[9] = 1;
  CFsm::GenerateEvent(1010, 0);
  return 1;
}


// address=[0x15bdec0]
// Decompiled from char __thiscall CGameHost::WaitingForGameConnect(_BYTE *this, void *Src)

bool  CGameHost::WaitingForGameConnect(void *) {
  
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
      j__memcpy(v18, Src, MessageLength);
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
          j__sprintf(
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

bool  CGameHost::HostInitGame(void *) {
  
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
// Decompiled from // bad sp value at call has been detected, the output may be wrong!
char __thiscall sub_19BE3C0(_DWORD **this, int a2)

bool  CGameHost::HostStartTick(void *) {
  
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

bool  CGameHost::RegClientConnect(void *) {
  
  int Instance; // eax
  const wchar_t *v3; // eax
  int v5; // eax
  int v6; // eax
  const char *v7; // eax
  int v8; // [esp+0h] [ebp-98h]
  _Cnd_internal_imp_t *PlayerName; // [esp+4h] [ebp-94h]
  int i; // [esp+Ch] [ebp-8Ch]
  int j; // [esp+Ch] [ebp-8Ch]
  _BYTE v13[28]; // [esp+10h] [ebp-88h] BYREF
  wchar_t Destination[32]; // [esp+2Ch] [ebp-6Ch] BYREF
  char v15; // [esp+6Ch] [ebp-2Ch]
  int LocalPeerId; // [esp+6Dh] [ebp-2Bh]
  int v17; // [esp+71h] [ebp-27h]
  int v18; // [esp+75h] [ebp-23h]
  int v19; // [esp+79h] [ebp-1Fh]
  int v20; // [esp+7Dh] [ebp-1Bh]
  int v21; // [esp+81h] [ebp-17h]
  char IsWebGame; // [esp+89h] [ebp-Fh]

  if ( a2 == 1 )
  {
    v15 = 1;
    Instance = StormManager::GetInstance();
    LocalPeerId = StormManager::GetLocalPeerId(Instance);
    v17 = g_iFileVersionMS;
    v18 = g_iFileVersionLS;
    v19 = g_iConfigVersion;
    v20 = g_iScriptVersion;
    v21 = g_iGfxVersion;
    IsWebGame = CGameType::IsWebGame(g_pGameType);
    PlayerName = (_Cnd_internal_imp_t *)CGameSettings::GetPlayerName((int)v13);
    v3 = (const wchar_t *)std::wstring::c_str(PlayerName);
    j__wcsncpy(Destination, v3, 0x1Fu);
    std::wstring::~wstring(v13);
    Destination[31] = 0;
    CGameHost::SendToHost(1013, Destination, 0x65u, 0, 0, 1);
    return 1;
  }
  else
  {
    v8 = *(_DWORD *)(g_pGameType + 68);
    if ( (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 36))(*(_DWORD *)(this + 196)) )
    {
      *(_DWORD *)(g_pGameType + 68) = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 36))(*(_DWORD *)(this + 196));
      for ( i = 0; i < 9; ++i )
      {
        if ( *(_DWORD *)(g_pGameType + 4 * i + 188) == v8 )
          *(_DWORD *)(g_pGameType + 4 * i + 188) = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(this + 196) + 36))(*(_DWORD *)(this + 196));
      }
    }
    CClientList::GetSize(*(CDaoIndexFieldInfo **)(this + 16));
    if ( v5 && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4254, "m_pClientList->GetSize() == 0") == 1 )
      __debugbreak();
    CTrace::Print("GameHost.cpp: Filling client list !!");
    for ( j = 0; j < 9; ++j )
    {
      if ( *(_DWORD *)(g_pGameType + 4 * j + 224) != -1 )
      {
        v6 = StormManager::GetInstance();
        if ( *(_DWORD *)(g_pGameType + 4 * j + 224) != StormManager::GetLocalPeerId(v6) )
        {
          CClientList::Add(*(CClientList **)(this + 16), *(_DWORD *)(g_pGameType + 4 * j + 188));
          v7 = (const char *)(*(int (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 196) + 48))(
                               *(_DWORD *)(this + 196),
                               *(_DWORD *)(g_pGameType + 4 * j + 188));
          CTrace::Print("GameHost.cpp: Adding client %s to list !", v7);
        }
      }
    }
    return 1;
  }
}


// address=[0x15be750]
// Decompiled from char __stdcall sub_19BE750(int a1)

bool  CGameHost::WereConnectedForGame(void *) {
  
  return 1;
}


// address=[0x15be760]
// Decompiled from char __thiscall CGameHost::ClientStartingGame(_DWORD *this, int a2)

bool  CGameHost::ClientStartingGame(void *) {
  
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

bool  CGameHost::ClientGameInited(void *) {
  
  CGameHost::SendToHost(1018, 0, 0, 0, 0, 1);
  return 1;
}


// address=[0x15be8e0]
// Decompiled from // bad sp value at call has been detected, the output may be wrong!
char __thiscall sub_19BE8E0(_DWORD **this, int a2)

bool  CGameHost::ClientStartTick(void *) {
  
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

bool  CGameHost::HostGameInited(void *) {
  
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

bool  CGameHost::GameSyncMsgGot(void *) {
  
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

bool  CGameHost::GameSync0MsgGot(void *) {
  
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

bool  CGameHost::GameInGameMsgGot(void *) {
  
  unsigned __int16 MessageLength; // ax

  MessageLength = CGameHost::GetMessageLength(this);
  j__memcpy(&unk_415AD98, Src, MessageLength);
  if ( *((_DWORD *)&unk_415AD98 + 6) )
  {
    if ( *((unsigned __int16 *)&unk_415AD98 + 14) >= 0x400u
      && BBSupportDbgReport(2, "Net\\GameHost.cpp", 4470, "pEvent->m_iDataSize < MSG_BUFFER_SIZE") == 1 )
    {
      __debugbreak();
    }
    *((_DWORD *)&unk_415AD98 + 6) = operator new[](*((unsigned __int16 *)&unk_415AD98 + 14));
    j__memcpy(*((void **)&unk_415AD98 + 6), &unk_415ADB8, *((unsigned __int16 *)&unk_415AD98 + 14));
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

bool  CGameHost::GameAsyncMsgGot(void *) {
  
  unsigned __int16 MessageLength; // ax
  _DWORD v4[8]; // [esp+10h] [ebp-30h] BYREF
  int v5; // [esp+3Ch] [ebp-4h]

  MessageLength = CGameHost::GetMessageLength(this);
  j__memcpy(&unk_415B290, Src, MessageLength);
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

bool  CGameHost::AmIStillAlive(void *) {
  
  int v2; // eax
  int v3; // eax
  int Src; // [esp+0h] [ebp-410h] BYREF
  _DWORD **v6; // [esp+4h] [ebp-40Ch]
  __int16 v7; // [esp+8h] [ebp-408h] BYREF
  char v8[1026]; // [esp+Ah] [ebp-406h] BYREF

  v6 = this;
  v7 = 1041;
  Src = CPlayerManager::GetLocalPlayerId() - 1;
  j__memcpy(v8, &Src, 4u);
  v2 = (*(int (__thiscall **)(_DWORD *, int, __int16 *, int, _DWORD, int))(*v6[49] + 36))(v6[49], 3105, &v7, 6, 0, 1);
  v3 = (*(int (__thiscall **)(_DWORD *, int))(*v6[49] + 40))(v6[49], v2);
  (*(void (__thiscall **)(_DWORD *, int))(*v6[49] + 32))(v6[49], v3);
  return 1;
}


// address=[0x15bef30]
// Decompiled from char __stdcall sub_19BEF30(char *a1)

bool  CGameHost::HeIsStillAlive(void *) {
  
  DWORD Time; // eax

  Time = timeGetTime();
  CMsgStacks::SetLastMsgTime(*a1, Time, 1);
  return 1;
}


// address=[0x15bef60]
// Decompiled from char __thiscall CGameHost::GameInGamePackedGot(_DWORD *this, int a2)

bool  CGameHost::GameInGamePackedGot(void *) {
  
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
      j__memcpy(*((void **)v8 + 6), Src, *((unsigned __int16 *)v8 + 14));
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

bool  CGameHost::IsValidSaveGame(struct SGameInfo &) {
  
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

bool  CGameHost::DoNothing(void *) {
  
  return 1;
}


