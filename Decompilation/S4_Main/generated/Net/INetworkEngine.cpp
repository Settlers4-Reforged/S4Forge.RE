#include "INetworkEngine.h"

// Definitions for class INetworkEngine

// address=[0x13a4250]
// Decompiled from char __thiscall INetworkEngine::StormDidEnterSession(INetworkEngine *this)
bool  INetworkEngine::StormDidEnterSession(void)const {
  
  return *((_BYTE *)this + 7);
}


// address=[0x1486f50]
// Decompiled from int __thiscall INetworkEngine::GetVirtualTick(CGameHost **this)
int  INetworkEngine::GetVirtualTick(void) {
  
  return CGameHost::GetVirtualTick(this[2]);
}


// address=[0x149f500]
// Decompiled from char *__thiscall INetworkEngine::GetLocalIP(CGameHost **this)
long  INetworkEngine::GetLocalIP(void) {
  
  if ( *((_BYTE *)this + 12) )
    return (char *)CGameHost::GetLocalIP(this[2]);
  else
    return (char *)&dword_F29144[220110] + 3;
}


// address=[0x14aaa40]
// Decompiled from char __thiscall INetworkEngine::EndTick(INetworkEngine *this)
bool  INetworkEngine::EndTick(void) {
  
  char result; // al

  result = CGameHost::AllSend(*((_DWORD **)this + 2));
  *((_BYTE *)this + 6) = 0;
  return result;
}


// address=[0x14aaa70]
// Decompiled from void __thiscall INetworkEngine::GameInitalized(CGameHost **this)
void  INetworkEngine::GameInitalized(void) {
  
  CGameHost::GameInitalized(this[2]);
}


// address=[0x14aab60]
// Decompiled from unsigned int __thiscall INetworkEngine::GetBytesPerSecond(CGameHost **this)
unsigned int  INetworkEngine::GetBytesPerSecond(void) {
  
  return CGameHost::GetBytesPerSecond(this[2]);
}


// address=[0x14aada0]
// Decompiled from int __thiscall INetworkEngine::GetValidTick(void **this)
int  INetworkEngine::GetValidTick(void) {
  
  return CGameHost::GetValidTick(this[2]);
}


// address=[0x14aae30]
// Decompiled from char __thiscall INetworkEngine::IsHost(INetworkEngine *this)
bool  INetworkEngine::IsHost(void) {
  
  return *((_BYTE *)this + 4);
}


// address=[0x14ab0d0]
// Decompiled from char __thiscall INetworkEngine::StartNewTick(CGameHost **this, bool a2)
bool  INetworkEngine::StartNewTick(bool a2) {
  
  char started; // [esp+7h] [ebp-1h]

  started = CGameHost::StartNewCycle(this[2], a2);
  if ( a2 )
    *((_BYTE *)this + 6) = started;
  return started;
}


// address=[0x14b46a0]
// Decompiled from int __stdcall INetworkEngine::ConvertIPAddress(int a1, int a2)
std::string  INetworkEngine::ConvertIPAddress(unsigned int a2) {
  
  CGameHost::ConvertIPAddress(a1, a2);
  return a1;
}


// address=[0x14b46f0]
// Decompiled from bool __thiscall INetworkEngine::EndGame(CGameHost **this, int a2)
bool  INetworkEngine::EndGame(int a2) {
  
  return CGameHost::OnEndGame(this[2], a2);
}


// address=[0x14b4760]
// Decompiled from bool __thiscall INetworkEngine::KickPlayerPeerId(CGameHost **this, unsigned int a2)
bool  INetworkEngine::KickPlayerPeerId(unsigned int a2) {
  
  return CGameHost::RemovePlayerPeerId(this[2], a2);
}


// address=[0x14b4860]
// Decompiled from bool __thiscall INetworkEngine::RemovePlayerPeerId(CGameHost **this, unsigned int a2)
bool  INetworkEngine::RemovePlayerPeerId(unsigned int a2) {
  
  return CGameHost::RemovePlayerPeerId(this[2], a2);
}


// address=[0x14bce40]
// Decompiled from INetworkEngine *__thiscall INetworkEngine::StormResetEnterSessionFlag(INetworkEngine *this)
void  INetworkEngine::StormResetEnterSessionFlag(void) {
  
  INetworkEngine *result; // eax

  result = this;
  *((_BYTE *)this + 7) = 0;
  return result;
}


// address=[0x15c8460]
// Decompiled from INetworkEngine *__thiscall INetworkEngine::INetworkEngine(INetworkEngine *this, bool a2)
 INetworkEngine::INetworkEngine(bool a2) {
  
  *(_DWORD *)this = &INetworkEngine::_vftable_;
  *((_BYTE *)this + 4) = 0;
  *((_BYTE *)this + 5) = 0;
  *((_BYTE *)this + 6) = 0;
  *((_BYTE *)this + 7) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_BYTE *)this + 12) = a2;
  *((_DWORD *)this + 4) = CStaticConfigVarInt::operator int(&g_iNetSenderPort);
  *((_DWORD *)this + 5) = CStaticConfigVarInt::operator int(&g_iNetReceiverPort);
  return this;
}


// address=[0x15c84d0]
// Decompiled from INetworkEngine *__thiscall INetworkEngine::~INetworkEngine(INetworkEngine *this)
 INetworkEngine::~INetworkEngine(void) {
  
  INetworkEngine *result; // eax

  result = this;
  *(_DWORD *)this = &INetworkEngine::_vftable_;
  if ( !*((_DWORD *)this + 2) )
    return result;
  (***((void (__thiscall ****)(_DWORD, int))this + 2))(*((_DWORD *)this + 2), 1);
  result = this;
  *((_DWORD *)this + 2) = 0;
  return result;
}


// address=[0x15c8530]
// Decompiled from char __thiscall INetworkEngine::SendNetMessage(INetworkEngine *this, struct CEvn_Logic *a2)
bool  INetworkEngine::SendNetMessage(class CEvn_Logic & a2) {
  
  _BYTE v4[32]; // [esp+Ch] [ebp-30h] BYREF
  int v5; // [esp+38h] [ebp-4h]

  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "INetworkEngine::SendNetMessage(): msg %u, owner %i, wparam 0x%08x, wparam 0x%08x.",
    *((_DWORD *)a2 + 1),
    *((unsigned __int8 *)a2 + 30),
    *((_DWORD *)a2 + 2),
    *((_DWORD *)a2 + 3));
  if ( !*((_BYTE *)a2 + 30) && BBSupportDbgReport(2, "Net\\INetworkEngine.cpp", 205, "_pMessage.m_iOwner") == 1 )
    __debugbreak();
  if ( !*((_BYTE *)this + 6) && BBSupportDbgReport(2, "Net\\INetworkEngine.cpp", 206, "m_bTickOpen") == 1 )
    __debugbreak();
  if ( !CPlayerManager::IsAlive(*((unsigned __int8 *)a2 + 30)) && *((_DWORD *)a2 + 1) != 4002 )
    return 1;
  CNet_Event::CNet_Event(
    (CNet_Event *)v4,
    *((_DWORD *)a2 + 1),
    *((_DWORD *)a2 + 2),
    *((_DWORD *)a2 + 3),
    *((_BYTE *)a2 + 30),
    *((_DWORD *)a2 + 6),
    *((_WORD *)a2 + 14),
    *((_DWORD *)a2 + 4));
  v5 = 0;
  INetworkEngine::PushMsg(this, (struct CNet_Event *)v4);
  v5 = -1;
  CNet_Event::~CNet_Event((CNet_Event *)v4);
  return 1;
}


// address=[0x15c8690]
// Decompiled from char __thiscall INetworkEngine::SendNetMessage(  INetworkEngine *this,  unsigned int a2,  unsigned int a3,  unsigned int a4,  int a5)
bool  INetworkEngine::SendNetMessage(unsigned int a2, unsigned int a3, unsigned int a4, int a5) {
  
  unsigned int CurrentTickCounter; // [esp+8h] [ebp-38h]
  _BYTE v8[32]; // [esp+10h] [ebp-30h] BYREF
  int v9; // [esp+3Ch] [ebp-4h]

  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "INetworkEngine::SendNetMessage(): msg %u, owner %i, wparam 0x%08x, wparam 0x%08x.",
    a2,
    a5,
    a3,
    a4);
  if ( a5 <= 0 && BBSupportDbgReport(2, "Net\\INetworkEngine.cpp", 155, "_iOwnerId > 0") == 1 )
    __debugbreak();
  if ( !*((_BYTE *)this + 6) && BBSupportDbgReport(2, "Net\\INetworkEngine.cpp", 156, "m_bTickOpen") == 1 )
    __debugbreak();
  if ( !CPlayerManager::IsAlive(a5) && a2 != 4002 )
    return 1;
  if ( g_pEvnEngine )
  {
    CurrentTickCounter = IEventEngine::GetCurrentTickCounter(g_pEvnEngine);
    CNet_Event::CNet_Event((CNet_Event *)v8, a2, a3, a4, a5, 0, 0, CurrentTickCounter);
  }
  else
  {
    CNet_Event::CNet_Event((CNet_Event *)v8, a2, a3, a4, a5, 0, 0, 0);
  }
  v9 = 0;
  INetworkEngine::PushMsg(this, (struct CNet_Event *)v8);
  v9 = -1;
  CNet_Event::~CNet_Event((CNet_Event *)v8);
  return 1;
}


// address=[0x15c87e0]
// Decompiled from char __thiscall INetworkEngine::SendAsyncNetMessage(INetworkEngine *this, struct CEvn_Logic *a2, char a3)
bool  INetworkEngine::SendAsyncNetMessage(class CEvn_Logic & a2, unsigned char a3) {
  
  _BYTE Src[32]; // [esp+Ch] [ebp-30h] BYREF
  int v5; // [esp+38h] [ebp-4h]

  CNet_Event::CNet_Event(
    (CNet_Event *)Src,
    *((_DWORD *)a2 + 1),
    *((_DWORD *)a2 + 2),
    *((_DWORD *)a2 + 3),
    *((_BYTE *)a2 + 30),
    *((_DWORD *)a2 + 6),
    *((_WORD *)a2 + 14),
    *((_DWORD *)a2 + 4));
  v5 = 0;
  INetworkEngine::PushAsyncMsg(Src, a3);
  v5 = -1;
  CNet_Event::~CNet_Event((CNet_Event *)Src);
  return 1;
}


// address=[0x15c8890]
// Decompiled from char __thiscall INetworkEngine::DeliverNetMessages(INetworkEngine *this)
bool  INetworkEngine::DeliverNetMessages(void) {
  
  _BYTE v3[4]; // [esp+8h] [ebp-50h] BYREF
  unsigned int v4; // [esp+Ch] [ebp-4Ch]
  unsigned int v5; // [esp+10h] [ebp-48h]
  unsigned int v6; // [esp+14h] [ebp-44h]
  int v7; // [esp+18h] [ebp-40h]
  unsigned int v8; // [esp+20h] [ebp-38h]
  unsigned __int16 v9; // [esp+24h] [ebp-34h]
  char v10; // [esp+26h] [ebp-32h]
  _DWORD v11[8]; // [esp+28h] [ebp-30h] BYREF
  int v12; // [esp+54h] [ebp-4h]

  if ( *((_BYTE *)this + 12) )
  {
    while ( INetworkEngine::CheckForMsg(this) )
      ;
  }
  while ( 1 )
  {
    INetworkEngine::PopMsg(this, v3);
    v12 = 0;
    if ( !v10 )
      break;
    CEvn_Logic::CEvn_Logic((CEvn_Logic *)v11, v4, v5, v6, v10, v8, v9);
    LOBYTE(v12) = 1;
    v11[4] = v7;
    IEventEngine::SendAMessage(g_pEvnEngine, v11);
    LOBYTE(v12) = 0;
    CEvn_Logic::~CEvn_Logic(v11);
    v12 = -1;
    CNet_Event::~CNet_Event((CNet_Event *)v3);
  }
  v12 = -1;
  CNet_Event::~CNet_Event((CNet_Event *)v3);
  return 1;
}


// address=[0x15c8990]
// Decompiled from bool __thiscall INetworkEngine::CheckForMsg(INetworkEngine *this)
bool  INetworkEngine::CheckForMsg(void) {
  
  return !*((_BYTE *)this + 12) || !*((_DWORD *)this + 2) || CGameHost::Run(*((CGameHost **)this + 2));
}


// address=[0x15c89c0]
// Decompiled from char __thiscall INetworkEngine::Start(int this, char a2, unsigned int a3, int a4, wchar_t *Source)
bool  INetworkEngine::Start(bool a2, unsigned int a3, unsigned int a4, wchar_t const * Source) {
  
  struct CMsgStacks *v6; // [esp+10h] [ebp-20h]
  int v7; // [esp+18h] [ebp-18h]
  void *C; // [esp+1Ch] [ebp-14h]

  if ( *(_BYTE *)(this + 5) && BBSupportDbgReport(2, "Net\\INetworkEngine.cpp", 83, "!m_bStarted") == 1 )
    __debugbreak();
  *(_BYTE *)(this + 4) = a2;
  if ( !*(_DWORD *)(this + 8) )
  {
    C = operator new(0x4F0u);
    if ( C )
      v7 = CGameHost::CGameHost((int)C, *(_BYTE *)(this + 12));
    else
      v7 = 0;
    *(_DWORD *)(this + 8) = v7;
  }
  if ( Source )
  {
    CGameHost::StartIniFileGame(Source);
    *(_BYTE *)(this + 4) = CGameType::IsHost(g_pGameType);
    if ( !(unsigned __int8)CGameType::IsWebGame(g_pGameType)
      && BBSupportDbgReport(2, "Net\\INetworkEngine.cpp", 106, "g_pGameType->IsWebGame()") == 1 )
    {
      __debugbreak();
    }
    if ( !(unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType)
      && BBSupportDbgReport(2, "Net\\INetworkEngine.cpp", 107, "g_pGameType->IsMultiplayerGame()") == 1 )
    {
      __debugbreak();
    }
    return 1;
  }
  else
  {
    if ( *(_BYTE *)(this + 12) || !a4 )
    {
      if ( *(_BYTE *)(this + 4) )
        CGameHost::InitAsHost(*(CGameHost **)(this + 8), a3);
      else
        CGameHost::InitAsClient(*(CGameHost **)(this + 8), a3);
    }
    else
    {
      if ( operator new(0x65Cu) )
        v6 = (struct CMsgStacks *)CMsgStacks::CMsgStacks(a4, 0, *(_DWORD *)(g_pGameType + 700));
      else
        v6 = 0;
      CGameHost::RegisterMsgStacks(*(CGameHost **)(this + 8), v6);
    }
    return 1;
  }
}


// address=[0x15c8bf0]
// Decompiled from CGameHost *__thiscall INetworkEngine::ContinueSearchForHost(CGameHost **this)
void  INetworkEngine::ContinueSearchForHost(void) {
  
  return CGameHost::ContinueSearchForHost(this[2]);
}


// address=[0x15c8c10]
// Decompiled from void __thiscall INetworkEngine::OnEndSaving(INetworkEngine *this)
void  INetworkEngine::OnEndSaving(void) {
  
  int v1; // eax

  if ( !*((_DWORD *)this + 2) && BBSupportDbgReport(2, "Net\\INetworkEngine.cpp", 305, "m_pGameHost != NULL") == 1 )
    __debugbreak();
  if ( *((_DWORD *)this + 2) )
  {
    v1 = CStaticConfigVarInt::operator int(&g_iSaveingTimeout);
    CGameHost::OnEndSaving(*((CGameHost **)this + 2), v1);
  }
}


// address=[0x15c8c70]
// Decompiled from void __thiscall INetworkEngine::StormJoinSessionSucceeded(INetworkEngine *this)
void  INetworkEngine::StormJoinSessionSucceeded(void) {
  
  if ( !*((_DWORD *)this + 2) && BBSupportDbgReport(2, "Net\\INetworkEngine.cpp", 314, "m_pGameHost != NULL") == 1 )
    __debugbreak();
  CGameHost::StormJoinSessionSucceeded(*((CGameHost **)this + 2));
}


// address=[0x15c8cb0]
// Decompiled from int __thiscall INetworkEngine::StormHost_NewPlayerMessage(_DWORD *this, int a2, int a3, char a4)
void  INetworkEngine::StormHost_NewPlayerMessage(unsigned int a2, std::wstring & a3, int a4) {
  
  if ( !this[2] && BBSupportDbgReport(2, "Net\\INetworkEngine.cpp", 320, "m_pGameHost != NULL") == 1 )
    __debugbreak();
  return CGameHost::StormHost_NewPlayerMessage(a2, a3, a4);
}


// address=[0x15c8d00]
// Decompiled from void __thiscall INetworkEngine::StormOnPeerGone(CGameHost **this, unsigned int a2)
void  INetworkEngine::StormOnPeerGone(unsigned int a2) {
  
  CGameHost::StormClientLeavesMyGame(this[2], a2);
}


// address=[0x15c8d20]
// Decompiled from void __thiscall INetworkEngine::StormOnHost(CGameHost **this)
void  INetworkEngine::StormOnHost(void) {
  
  std::wstring::operator=((int)&unk_4030720);
  std::wstring::operator=((int)&unk_40307CC);
  CGameHost::PromoteToHost(this[2]);
}


// address=[0x15c8d60]
// Decompiled from void __thiscall INetworkEngine::OnQuickMatched(CGameHost **this, bool a2)
void  INetworkEngine::OnQuickMatched(bool a2) {
  
  CGameHost::OnQuickMatched(this[2], a2);
}


// address=[0x15c8d80]
// Decompiled from void __thiscall INetworkEngine::OnJoinedFromInvite(CGameHost **this)
void  INetworkEngine::OnJoinedFromInvite(void) {
  
  CGameHost::OnJoinedFromOnlineFlow(this[2]);
}


// address=[0x16227a0]
// Decompiled from INetworkEngine *__thiscall INetworkEngine::StormEnteredSession(INetworkEngine *this)
void  INetworkEngine::StormEnteredSession(void) {
  
  INetworkEngine *result; // eax

  result = this;
  *((_BYTE *)this + 7) = 1;
  return result;
}


// address=[0x15c9030]
// Decompiled from int __thiscall INetworkEngine::PopMsg(_DWORD *this, int a2)
class CNet_Event  INetworkEngine::PopMsg(void a2) {
  
  CGameHost::PopMsg(this[2], a2);
  return a2;
}


// address=[0x15c9070]
// Decompiled from int __stdcall INetworkEngine::PushAsyncMsg(void *Src, char a2)
void  INetworkEngine::PushAsyncMsg(class CNet_Event & Src, unsigned char a2) {
  
  return CGameHost::PushAsyncMsg(Src, a2);
}


// address=[0x15c90a0]
// Decompiled from bool __thiscall INetworkEngine::PushMsg(CGameHost **this, struct CNet_Event *a2)
bool  INetworkEngine::PushMsg(class CNet_Event & a2) {
  
  return CGameHost::PushMsg(this[2], a2);
}


