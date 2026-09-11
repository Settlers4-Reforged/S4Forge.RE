#include "CStateLobbyLoadMP.h"

// Definitions for class CStateLobbyLoadMP

// address=[0x14bce60]
// Decompiled from CStateLobbyLoadMP *__cdecl CStateLobbyLoadMP::DynamicCreateFunc(int a1)
class CGameState * __cdecl CStateLobbyLoadMP::DynamicCreateFunc(void * a1) {
  
  CStateLobbyLoadMP *C; // [esp+Ch] [ebp-10h]

  C = (CStateLobbyLoadMP *)operator new(0xAFA0u);
  if ( C != 0 )
  {
    return CStateLobbyLoadMP::CStateLobbyLoadMP(C, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14bcee0]
// Decompiled from CStateLobbyLoadMP *__thiscall CStateLobbyLoadMP::CStateLobbyLoadMP(CStateLobbyLoadMP *this, int a2)
 CStateLobbyLoadMP::CStateLobbyLoadMP(void * a2) {
  
  int v3; // [esp+4h] [ebp-38h]
  std::wstring v5; // [esp+10h] [ebp-2Ch] BYREF
  int v6; // [esp+38h] [ebp-4h]

  CStateLobbyGameSettings::CStateLobbyGameSettings(a2);
  v6 = 0;
  *(_DWORD *)this = &CStateLobbyLoadMP::_vftable_;
  *((_BYTE *)this + 44956) = 0;
  CStateLobbyLoadMP::UpdateGameTypeData(this);
  v3 = (int)CGameType::ConvertMapNameToMPGameName(g_pGameType, &v5);
  LOBYTE(v6) = 1;
  ((void (__stdcall *)(void *, int))CStateLobbyLoadMP::CreateLobbyGameInfo)(&g_cLobbyGameInfo, v3);
  LOBYTE(v6) = 0;
  std::wstring::~wstring(&v5);
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
    IGuiEngine::RenderGui(g_pGUIEngine);
    IGfxEngine::RenderFrame(g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame(g_pGfxEngine);
  }
  if ( g_pNetworkEngine != 0 )
  {
    INetworkEngine::CheckForMsg((CGameHost **)g_pNetworkEngine);
    if ( INetworkEngine::StormDidEnterSession(g_pNetworkEngine) != 0 )
    {
      CStateLobbyLoadMP::UpdateGameTypeData(this);
      (*(void (__thiscall **)(CStateLobbyLoadMP *, int))(*(_DWORD *)this + 16))(this, 1);
      INetworkEngine::StormResetEnterSessionFlag(g_pNetworkEngine);
    }
  }
  return 1;
}


// address=[0x14bd0b0]
// Decompiled from char __thiscall CStateLobbyLoadMP::OnEvent(CStateLobbyLoadMP *this, struct CEvn_Event *a2)
bool  CStateLobbyLoadMP::OnEvent(class CEvn_Event & a2) {
  
  return CStateLobbyGameSettings::OnEvent(this, a2);
}


// address=[0x14bd0d0]
// Decompiled from void __thiscall CStateLobbyLoadMP::CreateLobbyGameInfo(_BYTE *this, int a2, int a3)
void  CStateLobbyLoadMP::CreateLobbyGameInfo(class CLanLobbyGameSettings & a2, std::wstring & a3) {
  
  void *v3; // [esp+0h] [ebp-2Ch]
  unsigned int i; // [esp+4h] [ebp-28h]
  _BYTE v6[28]; // [esp+Ch] [ebp-20h] BYREF

  ((void (__stdcall *)(int, int))CStateLobbyGameSettings::CreateLobbyGameInfo)(a2, a3);
  *(_BYTE *)(a2 + 217) = 1;
  *(_BYTE *)(a2 + 216) = 0;
  *(_BYTE *)(a2 + 137) = 1;
  *(_BYTE *)(a2 + 136) = 1;
  *(_DWORD *)(a2 + 120) = 1;
  for ( i = 0;
        i < g_pGameType->m_iActualPlayerCount;
        ++i )
  {
    *(_BYTE *)(*(_DWORD *)(a2 + 116) + 2116 * i) = 1;
  }
  *(_BYTE *)(*(_DWORD *)(a2 + 116) + 2116 * CGameType::GetLocalSlot(g_pGameType)) = 0;
  if ( *(this + 16932) != 0 )
  {
    *(this + 2116 * CGameType::GetLocalSlot(g_pGameType) + 68) = 1;
  }
  v3 = (void *)((int (__stdcall *)(int, int))INetworkEngine::ConvertIPAddress)((int)v6, g_pGameType->m_iHostAddress);
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
  std::wstring v6; // [esp+18h] [ebp-2Ch] BYREF
  int v7; // [esp+40h] [ebp-4h]

  if ( g_pGameType == 0 && BBSupportDbgReport(2, "main\\States\\StateLobbyLoadMP.cpp", 129, "g_pGameType!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( g_pGameType->m_bAIActive != 0 && BBSupportDbgReport(2, "main\\States\\StateLobbyLoadMP.cpp", 130, "!g_pGameType->m_bLocalGame") == 1 )
  {
    __debugbreak();
  }
  if ( g_pGameType->m_bIsSaveGame == 0 && BBSupportDbgReport(2, "main\\States\\StateLobbyLoadMP.cpp", 131, "g_pGameType->m_bSavedGame") == 1 )
  {
    __debugbreak();
  }
  if ( CGameType::IsWebGame(g_pGameType) == 0 )
  {
    CGameType::SetHost(g_pGameType, 1);
    g_pGameType->m_iHostAddress = INetworkEngine::GetLocalIP((CGameHost **)g_pNetworkEngine);
    memset(g_pGameType->m_uiIPPlayer, 0, sizeof(g_pGameType->m_uiIPPlayer));
    g_pGameType->m_uiIPPlayer[CGameType::GetLocalSlot(g_pGameType)] = g_pGameType->m_iHostAddress;
    memset(g_pGameType->m_sPlayerPeerId, -1, sizeof(g_pGameType->m_sPlayerPeerId));
    Instance = (OnlineManager *)OnlineManager::GetInstance();
    LocalPeerId = OnlineManager::GetLocalPeerId(Instance);
    g_pGameType->m_sPlayerPeerId[CGameType::GetLocalSlot(g_pGameType)] = LocalPeerId;
  }
  for ( i = 0;
        i < g_pGameType->m_iActualPlayerCount;
        ++i )
  {
    if ( g_pGameType->m_sPlayerType[i] == 2 || g_pGameType->m_sPlayerType[i] == 3 )
    {
      g_pGameType->m_sPlayerMapUploadStarted[i] = 6;
    }
    else
    {
      g_pGameType->m_sPlayerMapUploadStarted[i] = 0;
    }
    if ( CGameType::IsSaveGame(g_pGameType) != 0 )
    {
      if ( g_pGameType->m_sPlayerType[i] == 2 || g_pGameType->m_sPlayerType[i] == 3 )
      {
        AIName = CGameSettings::GetAIName((int)&v6, i);
        v7 = 0;
        ((void (__stdcall *)(unsigned int, int))CGameType::SetPlayerName)(i, AIName);
        v7 = -1;
        std::wstring::~wstring(&v6);
      }
      else
      {
        g_pGameType->m_sPlayerExclusiveColor[i] = 1;
      }
    }
    else
    {
      g_pGameType->m_sPlayerType[i] = 1;
    }
    if ( CGameType::IsHost(g_pGameType) != 0 && (g_pGameType->m_sPlayerType[i] != 2 && g_pGameType->m_sPlayerType[i] != 3 || g_pGameType->m_sPlayerRaces[i] != 3) )
    {
      g_pGameType->m_bPlayerSlotEmpty[i] = 1;
    }
  }
  g_pGameType->byte261 = 0;
  result = CGameType::GetLocalSlot(g_pGameType);
  g_pGameType->m_sPlayerExclusiveColor[result] = 0;
  return result;
}


