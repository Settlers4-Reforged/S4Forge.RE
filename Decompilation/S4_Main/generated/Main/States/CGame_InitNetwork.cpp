#include "all_headers.h"

// Definitions for class CGame_InitNetwork

// address=[0x15c7f60]
// Decompiled from CGame_InitNetwork *__cdecl CGame_InitNetwork::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CGame_InitNetwork::DynamicCreateFunc(void *) {
  
  CGame_InitNetwork *C; // [esp+Ch] [ebp-10h]

  C = (CGame_InitNetwork *)operator new(4u);
  if ( C )
    return CGame_InitNetwork::CGame_InitNetwork(C, a1);
  else
    return 0;
}


// address=[0x15c7fe0]
// Decompiled from CGame_InitNetwork *__thiscall CGame_InitNetwork::CGame_InitNetwork(CGame_InitNetwork *this, wchar_t *a2)
 CGame_InitNetwork::CGame_InitNetwork(void *) {
  
  int v3; // [esp+8h] [ebp-A4h]
  void *v4; // [esp+Ch] [ebp-A0h]
  void *v5; // [esp+14h] [ebp-98h]
  INetworkEngine *v6; // [esp+28h] [ebp-84h]
  INetworkEngine *v7; // [esp+2Ch] [ebp-80h]
  INetworkEngine *v8; // [esp+30h] [ebp-7Ch]
  INetworkEngine *v9; // [esp+34h] [ebp-78h]
  CGameType *v10; // [esp+38h] [ebp-74h]
  CGameType *C; // [esp+3Ch] [ebp-70h]
  char v13; // [esp+45h] [ebp-67h]
  _BYTE v14[28]; // [esp+48h] [ebp-64h] BYREF
  _BYTE v15[28]; // [esp+64h] [ebp-48h] BYREF
  _BYTE v16[28]; // [esp+80h] [ebp-2Ch] BYREF
  int v17; // [esp+A8h] [ebp-4h]

  CGameState::CGameState(this);
  v17 = 0;
  *(_DWORD *)this = &CGame_InitNetwork::_vftable_;
  if ( a2 )
  {
    if ( !g_pGameType )
    {
      C = (CGameType *)operator new(0x620u);
      LOBYTE(v17) = 1;
      if ( C )
        v10 = CGameType::CGameType(C);
      else
        v10 = 0;
      LOBYTE(v17) = 0;
      g_pGameType = (int)v10;
    }
    v9 = (INetworkEngine *)operator new(0x18u);
    LOBYTE(v17) = 2;
    if ( v9 )
      v8 = INetworkEngine::INetworkEngine(v9, 1);
    else
      v8 = 0;
    LOBYTE(v17) = 0;
    g_pNetworkEngine = (int)v8;
    INetworkEngine::Start(1, 0, 0, a2);
  }
  else
  {
    v5 = std::string::string(v14, "normal");
    LOBYTE(v17) = 3;
    v4 = std::string::string(v15, "normal");
    LOBYTE(v17) = 4;
    v3 = ((int (__thiscall *)(CConfigManager *, _BYTE *, const char *, const char *, void *))g_pCfgMgr->GetStringValue)(
           g_pCfgMgr,
           v16,
           "COMMANDLINE",
           "gamemode",
           v4);
    v13 = std::operator==<char>(v3, v5);
    std::string::~string(v16);
    LOBYTE(v17) = 3;
    std::string::~string(v15);
    LOBYTE(v17) = 0;
    std::string::~string(v14);
    if ( v13 )
    {
      v7 = (INetworkEngine *)operator new(0x18u);
      LOBYTE(v17) = 5;
      if ( v7 )
        v6 = INetworkEngine::INetworkEngine(v7, (bool)a2);
      else
        v6 = 0;
      LOBYTE(v17) = 0;
      g_pNetworkEngine = (int)v6;
      INetworkEngine::Start(1, 0, 0, 0);
    }
  }
  return this;
}


// address=[0x15c8280]
// Decompiled from void __thiscall CGame_InitNetwork::~CGame_InitNetwork(CGame_InitNetwork *this)
 CGame_InitNetwork::~CGame_InitNetwork(void) {
  
  *(_DWORD *)this = &CGame_InitNetwork::_vftable_;
  CGameState::~CGameState(this);
}


// address=[0x15c82a0]
// Decompiled from char __thiscall CGame_InitNetwork::Perform(CGame_InitNetwork *this)
bool  CGame_InitNetwork::Perform(void) {
  
  if ( ++dword_415B7C8 > 1000 )
  {
    dword_415B7C8 = 0;
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  }
  if ( g_pNetworkEngine )
    INetworkEngine::CheckForMsg((INetworkEngine *)g_pNetworkEngine);
  return 1;
}


// address=[0x15c82f0]
// Decompiled from char __thiscall CGame_InitNetwork::OnEvent(CGame_InitNetwork *this, struct CEvn_Event *a2)
bool  CGame_InitNetwork::OnEvent(class CEvn_Event &) {
  
  if ( a2->event == 4001 )
    return 1;
  if ( a2->event != 24 )
    return 0;
  CGameStateHandler::Switch((int)CStateGame::DynamicCreateFunc, 0);
  return 1;
}


