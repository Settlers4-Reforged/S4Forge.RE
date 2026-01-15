#include "CStateLobbyLoadMP.h"

// Definitions for class CStateLobbyLoadMP

// address=[0x14bce60]
// Decompiled from CStateLobbyLoadMP *__cdecl CStateLobbyLoadMP::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateLobbyLoadMP::DynamicCreateFunc(void *) {
  
  CStateLobbyLoadMP *C; // [esp+Ch] [ebp-10h]

  C = (CStateLobbyLoadMP *)operator new(0xAFA0u);
  if ( C )
    return CStateLobbyLoadMP::CStateLobbyLoadMP(C, a1);
  else
    return 0;
}


// address=[0x14bcee0]
// Decompiled from CStateLobbyLoadMP *__thiscall CStateLobbyLoadMP::CStateLobbyLoadMP(CStateLobbyLoadMP *this, int a2)
 CStateLobbyLoadMP::CStateLobbyLoadMP(void *) {
  
  int v3; // [esp+4h] [ebp-38h]
  _BYTE v5[28]; // [esp+10h] [ebp-2Ch] BYREF
  int v6; // [esp+38h] [ebp-4h]

  CStateLobbyGameSettings::CStateLobbyGameSettings(a2);
  v6 = 0;
  *(_DWORD *)this = &CStateLobbyLoadMP::_vftable_;
  *((_BYTE *)this + 44956) = 0;
  CStateLobbyLoadMP::UpdateGameTypeData(this);
  v3 = CGameType::ConvertMapNameToMPGameName((char *)g_pGameType, (int)v5);
  LOBYTE(v6) = 1;
  CStateLobbyLoadMP::CreateLobbyGameInfo(&g_cLobbyGameInfo, v3);
  LOBYTE(v6) = 0;
  std::wstring::~wstring(v5);
  return this;
}


// address=[0x14bcfa0]
// Decompiled from void __thiscall CStateLobbyLoadMP::~CStateLobbyLoadMP(CStateLobbyLoadMP *this)
 CStateLobbyLoadMP::~CStateLobbyLoadMP(void) {
  
  *(_DWORD *)this = &CStateLobbyLoadMP::_vftable_;
  CStateLobbyGameSettings::~CStateLobbyGameSettings(this);
}


// address=[0x14bcfc0]
// Decompiled from char __thiscall CStateLobbyLoadMP::Perform(CStateLobbyLoadMP *this)
bool  CStateLobbyLoadMP::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_4030934 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_4030934);
    if ( dword_4030934 == -1 )
    {
      dword_4030930 = timeGetTime();
      j___Init_thread_footer(&dword_4030934);
    }
  }
  v1 = dword_4030930 + 30;
  if ( v1 < timeGetTime() )
  {
    dword_4030930 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  }
  if ( !g_pNetworkEngine )
    return 1;
  INetworkEngine::CheckForMsg((INetworkEngine *)g_pNetworkEngine);
  if ( !INetworkEngine::StormDidEnterSession((INetworkEngine *)g_pNetworkEngine) )
    return 1;
  CStateLobbyLoadMP::UpdateGameTypeData(this);
  (*(void (__thiscall **)(CStateLobbyLoadMP *, int))(*(_DWORD *)this + 16))(this, 1);
  INetworkEngine::StormResetEnterSessionFlag((INetworkEngine *)g_pNetworkEngine);
  return 1;
}


// address=[0x14bd0b0]
// Decompiled from char __thiscall CStateLobbyLoadMP::OnEvent(CStateLobbyLoadMP *this, struct CEvn_Event *a2)
bool  CStateLobbyLoadMP::OnEvent(class CEvn_Event &) {
  
  return CStateLobbyGameSettings::OnEvent(this, a2);
}


// address=[0x14bd0d0]
// Decompiled from void __thiscall CStateLobbyLoadMP::CreateLobbyGameInfo(_BYTE *this, int a2, int a3)
void  CStateLobbyLoadMP::CreateLobbyGameInfo(class CLanLobbyGameSettings &,std::wstring &) {
  
  void *v3; // [esp+0h] [ebp-2Ch]
  unsigned int i; // [esp+4h] [ebp-28h]
  _BYTE v6[28]; // [esp+Ch] [ebp-20h] BYREF

  CStateLobbyGameSettings::CreateLobbyGameInfo(a2, a3);
  *(_BYTE *)(a2 + 217) = 1;
  *(_BYTE *)(a2 + 216) = 0;
  *(_BYTE *)(a2 + 137) = 1;
  *(_BYTE *)(a2 + 136) = 1;
  *(_DWORD *)(a2 + 120) = 1;
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
    *(_BYTE *)(*(_DWORD *)(a2 + 116) + 2116 * i) = 1;
  *(_BYTE *)(*(_DWORD *)(a2 + 116) + 2116 * CGameType::GetLocalSlot(g_pGameType)) = 0;
  if ( this[16932] )
    this[2116 * CGameType::GetLocalSlot(g_pGameType) + 68] = 1;
  v3 = (void *)INetworkEngine::ConvertIPAddress((int)v6, *(_DWORD *)(g_pGameType + 68));
  std::string::operator=((void *)(a2 + 60), v3);
  std::string::~string(v6);
  (*(void (__thiscall **)(_BYTE *, int))(*(_DWORD *)this + 16))(this, 1);
  GuiDlgMainGameSettingstUpdate();
}


// address=[0x14bd200]
// Decompiled from int __thiscall CStateLobbyLoadMP::UpdateGameTypeData(CStateLobbyLoadMP *this)
void  CStateLobbyLoadMP::UpdateGameTypeData(void) {
  
  OnlineManager *Instance; // eax
  int LocalPeerId; // esi
  int result; // eax
  int AIName; // [esp+Ch] [ebp-38h]
  unsigned int i; // [esp+14h] [ebp-30h]
  _BYTE v6[28]; // [esp+18h] [ebp-2Ch] BYREF
  int v7; // [esp+40h] [ebp-4h]

  if ( !g_pGameType && BBSupportDbgReport(2, "main\\States\\StateLobbyLoadMP.cpp", 129, "g_pGameType!=NULL") == 1 )
    __debugbreak();
  if ( *(_BYTE *)(g_pGameType + 732)
    && BBSupportDbgReport(2, "main\\States\\StateLobbyLoadMP.cpp", 130, "!g_pGameType->m_bLocalGame") == 1 )
  {
    __debugbreak();
  }
  if ( !*(_BYTE *)(g_pGameType + 696)
    && BBSupportDbgReport(2, "main\\States\\StateLobbyLoadMP.cpp", 131, "g_pGameType->m_bSavedGame") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CGameType::IsWebGame(g_pGameType) )
  {
    CGameType::SetHost((CGameType *)g_pGameType, 1);
    *(_DWORD *)(g_pGameType + 68) = INetworkEngine::GetLocalIP((CGameHost **)g_pNetworkEngine);
    memset((void *)(g_pGameType + 188), 0, 0x24u);
    *(_DWORD *)(g_pGameType + 4 * CGameType::GetLocalSlot(g_pGameType) + 188) = *(_DWORD *)(g_pGameType + 68);
    memset((void *)(g_pGameType + 224), -1, 0x24u);
    Instance = (OnlineManager *)OnlineManager::GetInstance();
    LocalPeerId = OnlineManager::GetLocalPeerId(Instance);
    *(_DWORD *)(g_pGameType + 4 * CGameType::GetLocalSlot(g_pGameType) + 224) = LocalPeerId;
  }
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
  {
    if ( *(_DWORD *)(g_pGameType + 4 * i + 116) == 2 || *(_DWORD *)(g_pGameType + 4 * i + 116) == 3 )
      *(_DWORD *)(g_pGameType + 4 * i + 452) = 6;
    else
      *(_DWORD *)(g_pGameType + 4 * i + 452) = 0;
    if ( (unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType) )
    {
      if ( *(_DWORD *)(g_pGameType + 4 * i + 116) == 2 || *(_DWORD *)(g_pGameType + 4 * i + 116) == 3 )
      {
        AIName = CGameSettings::GetAIName((int)v6, i);
        v7 = 0;
        CGameType::SetPlayerName(i, AIName);
        v7 = -1;
        std::wstring::~wstring(v6);
      }
      else
      {
        *(_BYTE *)(i + g_pGameType + 440) = 1;
      }
    }
    else
    {
      *(_DWORD *)(g_pGameType + 4 * i + 116) = 1;
    }
    if ( (unsigned __int8)CGameType::IsHost(g_pGameType)
      && (*(_DWORD *)(g_pGameType + 4 * i + 116) != 2 && *(_DWORD *)(g_pGameType + 4 * i + 116) != 3
       || *(_DWORD *)(g_pGameType + 4 * i + 404) != 3) )
    {
      *(_BYTE *)(i + g_pGameType + 998) = 1;
    }
  }
  *(_BYTE *)(g_pGameType + 609) = 0;
  result = CGameType::GetLocalSlot(g_pGameType);
  *(_BYTE *)(g_pGameType + result + 440) = 0;
  return result;
}


