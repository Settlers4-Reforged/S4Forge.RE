#include "CStateLobbyGameSettings.h"

// Definitions for class CStateLobbyGameSettings

// address=[0x14b7f10]
// Decompiled from int __cdecl sub_18B7F10(int a1)
static class CGameState * __cdecl CStateLobbyGameSettings::DynamicCreateFunc(void *) {
  
  if ( operator new(0xAF9Cu) )
    return CStateLobbyGameSettings::CStateLobbyGameSettings(a1);
  else
    return 0;
}


// address=[0x14b7f90]
// Decompiled from CStateLobbyGameSettings *__thiscall CStateLobbyGameSettings::CStateLobbyGameSettings(  CStateLobbyGameSettings *this,  int a2)
 CStateLobbyGameSettings::CStateLobbyGameSettings(void *) {
  
  const WCHAR *v2; // eax
  const char *v3; // eax
  const WCHAR *v5; // [esp-8h] [ebp-140h]
  const char *v6; // [esp-4h] [ebp-13Ch]
  int v7; // [esp+4h] [ebp-134h]
  int Instance; // [esp+10h] [ebp-128h]
  char v9[4]; // [esp+18h] [ebp-120h]
  int i; // [esp+1Ch] [ebp-11Ch]
  _BYTE v12[28]; // [esp+28h] [ebp-110h] BYREF
  _BYTE v13[28]; // [esp+44h] [ebp-F4h] BYREF
  wchar_t Buffer[100]; // [esp+60h] [ebp-D8h] BYREF
  int v15; // [esp+134h] [ebp-4h]

  CGuiGameState::CGuiGameState(this);
  v15 = 0;
  *(_DWORD *)this = &CStateLobbyGameSettings::_vftable_;
  _vec_ctor(
    (char *)this + 4,
    0x844u,
    8u,
    CLanLobbyGameSettings::SPlayerEntry::SPlayerEntry,
    (void (__thiscall *)(void *))CLanLobbyGameSettings::SPlayerEntry::~SPlayerEntry);
  _vec_ctor((char *)this + 16944, 0x1Cu, 0x3E8u, std::wstring::wstring, std::wstring::~wstring);
  LOBYTE(v15) = 2;
  if ( (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) )
  {
    Instance = UPlay::UPlayManager::GetInstance();
    (*(void (__thiscall **)(int, int))(*(_DWORD *)Instance + 52))(Instance, 2);
  }
  *((_BYTE *)this + 16932) = a2 != 0;
  *((_BYTE *)this + 16933) = 0;
  for ( i = 0; i < 8; ++i )
  {
    *((_BYTE *)this + i + 44948) = 0;
    if ( g_pGameType
      && (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType)
      && (unsigned __int8)CGameType::IsHost(g_pGameType)
      && i
      && (*(_DWORD *)(g_pGameType + 4 * i + 116) != 2 && *(_DWORD *)(g_pGameType + 4 * i + 116) != 3
       || *(_DWORD *)(g_pGameType + 4 * i + 404) != 3) )
    {
      *(_BYTE *)(i + g_pGameType + 998) = 1;
    }
  }
  if ( (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) && CGameType::GetLocalSlot(g_pGameType) >= 0 )
    *(_DWORD *)(g_pGameType + 4 * CGameType::GetLocalSlot(g_pGameType) + 224) = 0;
  v7 = CGameType::ConvertMapNameToMPGameName((char *)g_pGameType, (int)v12);
  LOBYTE(v15) = 3;
  CStateLobbyGameSettings::CreateLobbyGameInfo(&g_cLobbyGameInfo, v7);
  LOBYTE(v15) = 2;
  std::wstring::~wstring(v12);
  *((_DWORD *)this + 4235) = CGameType::GetLocalSlot(g_pGameType);
  if ( *(_DWORD *)(g_pGameType + 864) == 3 && !(unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType) )
    CStateLobbyGameSettings::CreateRandomGoods(this);
  CGfxManager::DisableGfxFile((CGfxManager *)g_pGfxManager, 1);
  CStateLobbyGameSettings::CopyDefaultUserFlags();
  CStateLobbyGameSettings::CompileUserFlags();
  if ( !(unsigned __int8)CStateLobbyGameSettings::ReadUserflagFiles() )
  {
    IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
    CTrace::Print("Display Error-Dialog (No Userflags found)");
    CGameStateHandler::Switch((int)CStateMessageBox::DynamicCreateFunc, 2398);
    return this;
  }
  if ( !CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 1u, 8, 1, 0xFFFFFFFF) )
  {
    std::wstring::wstring(v13);
    LOBYTE(v15) = 4;
    *(_DWORD *)v9 = 0;
    while ( *(int *)v9 < 8 )
    {
      swprintf((char *)Buffer, (char *)L"\\HerFig_%d.png", v9[0]);
      std::wstring::operator=(v13, (wchar_t *)L"Logo\\Current");
      std::wstring::operator+=(v13, Buffer);
      v5 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v13);
      v2 = (const WCHAR *)std::wstring::c_str((CStateLobbyGameSettings *)((char *)this + 28 * *(_DWORD *)v9 + 16944));
      if ( !CopyFileW(v2, v5, 0) )
      {
        IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
        v6 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v13);
        v3 = (const char *)std::wstring::c_str((CStateLobbyGameSettings *)((char *)this + 28 * *(_DWORD *)v9 + 16944));
        CTrace::Print("::CopyFile() %s -> %s failed!", v3, v6);
        CGameStateHandler::Switch((int)CStateMessageBox::DynamicCreateFunc, 2398);
        LOBYTE(v15) = 2;
        std::wstring::~wstring(v13);
        return this;
      }
      ++*(_DWORD *)v9;
    }
    if ( CStateLobbyGameSettings::CompileUserFlags() )
    {
      IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
      CTrace::Print("Display Error-Dialog (No RTCompiler-Error)");
      CGameStateHandler::Switch((int)CStateMessageBox::DynamicCreateFunc, 2398);
      LOBYTE(v15) = 2;
      std::wstring::~wstring(v13);
      return this;
    }
    if ( !CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 1u, 8, 1, 0xFFFFFFFF) )
    {
      IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
      CTrace::Print("Display Error-Dialog (Userflags compile error)");
      CGameStateHandler::Switch((int)CStateMessageBox::DynamicCreateFunc, 2398);
      LOBYTE(v15) = 2;
      std::wstring::~wstring(v13);
      return this;
    }
    LOBYTE(v15) = 2;
    std::wstring::~wstring(v13);
  }
  CStateLobbyGameSettings::UpdatePlayerList(this, 0);
  CStateLobbyGameSettings::SetupGUI(this);
  CStateLobbyGameSettings::UserflagChanged(this, 0, 0);
  CStateLobbyGameSettings::PaintMap(this);
  if ( !byte_4030854 )
    IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  return this;
}


// address=[0x14b84f0]
// Decompiled from void __thiscall CStateLobbyGameSettings::~CStateLobbyGameSettings(CStateLobbyGameSettings *this)
 CStateLobbyGameSettings::~CStateLobbyGameSettings(void) {
  
  bool v2; // [esp+Bh] [ebp-Dh]

  *(_DWORD *)this = &CStateLobbyGameSettings::_vftable_;
  if ( byte_4030853 && byte_40308A0 )
    CStateLobbyGameSettings::UserflagChanged(this, 0, 0);
  v2 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 11236));
  CStateLobbyGameSettings::ClearFlagnameList(this);
  if ( !v2 && BBSupportDbgReport(2, "main\\states\\StateLobbyGameSettings.cpp", 303, "bRet") == 1 )
    __debugbreak();
  `eh vector destructor iterator'((char *)this + 16944, 0x1Cu, 0x3E8u, std::wstring::~wstring);
  `eh vector destructor iterator'(
    (char *)this + 4,
    0x844u,
    8u,
    (void (__thiscall *)(void *))CLanLobbyGameSettings::SPlayerEntry::~SPlayerEntry);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14b85e0]
// Decompiled from char __thiscall CStateLobbyGameSettings::Perform(CStateLobbyGameSettings *this)
bool  CStateLobbyGameSettings::Perform(void) {
  
  OnlineManager *Instance; // eax
  char *v2; // eax
  DWORD v4; // esi
  int i; // [esp+1Ch] [ebp-Ch]
  char v7; // [esp+25h] [ebp-3h]
  char v8; // [esp+26h] [ebp-2h]
  char v9; // [esp+27h] [ebp-1h]

  if ( g_pGameType
    && (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType)
    && (Instance = (OnlineManager *)OnlineManager::GetInstance(), OnlineManager::GetAndClearOnlineError(Instance)) )
  {
    byte_40308A0 = 0;
    v2 = g_pStringEngine->GetString(g_pStringEngine, 2503);
    CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, (int)v2);
    CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
    if ( g_pNetworkEngine )
      (**(void (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
    g_pNetworkEngine = 0;
    if ( !g_pGameType )
      return 1;
    delete (CGameType *)g_pGameType;
    g_pGameType = 0;
    return 1;
  }
  else
  {
    if ( dword_40308E8 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_40308E8);
      if ( dword_40308E8 == -1 )
      {
        dword_40308E4 = timeGetTime();
        j___Init_thread_footer(&dword_40308E8);
      }
    }
    v4 = dword_40308E4 + 30;
    if ( v4 < timeGetTime() )
    {
      dword_40308E4 = timeGetTime();
      IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
      IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
      IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    }
    v9 = 0;
    for ( i = 0; i < 8; ++i )
    {
      if ( *((_BYTE *)this + i + 44948) )
      {
        if ( !byte_4030853 )
          CStateLobbyGameSettings::UserflagChanged(this, -1, -1);
        v9 = 1;
        *((_BYTE *)this + i + 44948) = 0;
      }
    }
    v8 = 0;
    if ( g_pNetworkEngine && INetworkEngine::StormDidEnterSession((INetworkEngine *)g_pNetworkEngine) )
    {
      v8 = 1;
      INetworkEngine::StormResetEnterSessionFlag((INetworkEngine *)g_pNetworkEngine);
    }
    if ( v9 || v8 )
    {
      CLanLobby::RedrawPlayerList();
      IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
      IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
      IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    }
    if ( g_pNetworkEngine )
      INetworkEngine::CheckForMsg((INetworkEngine *)g_pNetworkEngine);
    if ( !g_pGameType )
      return 1;
    v7 = CStateLobbyGameSettings::CheckReady(this);
    if ( v7 != byte_40308A1 )
    {
      byte_40308A1 = v7;
      (*(void (__thiscall **)(CStateLobbyGameSettings *, int))(*(_DWORD *)this + 16))(this, 1);
    }
    CStateLobbyGameSettings::SetBackButtonState(this);
    return 1;
  }
}


// address=[0x14b8890]
// Decompiled from char __thiscall CStateLobbyGameSettings::OnEvent(CStateLobbyGameSettings *this, struct CEvn_Event *a2)
bool  CStateLobbyGameSettings::OnEvent(class CEvn_Event &) {
  
  char result; // al
  void *v3; // eax
  void *v4; // eax
  OnlineManager *v5; // eax
  const wchar_t *v6; // eax
  OnlineManager *v7; // eax
  OnlineManager *v8; // eax
  size_t v9; // eax
  _Cnd_internal_imp_t *AIName; // [esp+10h] [ebp-390h]
  void *v11; // [esp+14h] [ebp-38Ch]
  CEvn_Event *v12; // [esp+28h] [ebp-378h]
  bool v13; // [esp+3Ch] [ebp-364h]
  int v15; // [esp+44h] [ebp-35Ch]
  int v16; // [esp+48h] [ebp-358h]
  int v17; // [esp+4Ch] [ebp-354h]
  int v18; // [esp+50h] [ebp-350h]
  char *Str; // [esp+54h] [ebp-34Ch]
  size_t v20; // [esp+58h] [ebp-348h]
  int Instance; // [esp+5Ch] [ebp-344h]
  int v22; // [esp+64h] [ebp-33Ch]
  int i; // [esp+68h] [ebp-338h]
  unsigned int event; // [esp+70h] [ebp-330h]
  int wparam; // [esp+80h] [ebp-320h]
  wchar_t Destination[32]; // [esp+84h] [ebp-31Ch] BYREF
  int v28; // [esp+C5h] [ebp-2DBh]
  char v29; // [esp+E2h] [ebp-2BEh]
  _BYTE v30[28]; // [esp+ECh] [ebp-2B4h] BYREF
  _BYTE v31[28]; // [esp+108h] [ebp-298h] BYREF
  CEvn_Event v32; // [esp+124h] [ebp-27Ch] BYREF
  _DWORD v33[3]; // [esp+13Ch] [ebp-264h] BYREF
  _DWORD Src[3]; // [esp+148h] [ebp-258h] BYREF
  _DWORD v35[3]; // [esp+154h] [ebp-24Ch] BYREF
  _DWORD v36[3]; // [esp+160h] [ebp-240h] BYREF
  _DWORD v37[3]; // [esp+16Ch] [ebp-234h] BYREF
  _DWORD v38[3]; // [esp+178h] [ebp-228h] BYREF
  _DWORD v39[3]; // [esp+184h] [ebp-21Ch] BYREF
  wchar_t Dest[256]; // [esp+190h] [ebp-210h] BYREF
  int v41; // [esp+39Ch] [ebp-4h]

  event = a2->event;
  if ( event > 0xFA1 )
  {
    if ( event == 8024 )
    {
      v39[0] = a2->wparam;
      v39[1] = 9;
      v39[2] = a2->lparam;
      CLanLobby::ChangeData(v39);
      return 1;
    }
    else
    {
      return CGuiGameState::OnEvent(this, a2);
    }
  }
  else if ( event == 4001 )
  {
    CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2495);
    CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
    return 1;
  }
  else
  {
    switch ( event )
    {
      case 0xDu:
        if ( a2->wparam == 27 )
        {
          if ( !byte_4030854 )
          {
            v12 = CEvn_Event::CEvn_Event(&v32, 0x4Du, 0, 0, 0);
            v41 = 0;
            IEventEngine::SendAMessage(g_pEvnEngine, v12);
            v41 = -1;
            CEvn_Event::~CEvn_Event(&v32);
          }
          result = 1;
        }
        else
        {
          result = 1;
        }
        break;
      case 0x18u:
        v11 = std::string::string(v30, (char *)byte_3745C42);
        v13 = (unsigned __int8)std::operator!=<char>(g_pGameType + 884, v11)
           && *(_DWORD *)(g_pGameType + 692) == 1
           && (!dword_403191C || dword_403191C == 2)
           && *(_DWORD *)(g_pGameType + 864) != 3;
        std::string::~string(v30);
        if ( v13 )
        {
          CGameStateHandler::Switch((int)CStateBriefing::DynamicCreateFunc, 0);
        }
        else
        {
          IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
          IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
          std::string::operator=(g_pGameType + 968);
          CGameStateHandler::Switch((int)CStateGame::DynamicCreateFunc, 0);
        }
        result = 1;
        break;
      case 0x26u:
        Str = (char *)a2->wparam;
        v9 = j__strlen(Str);
        v20 = j__mbstowcs(Dest, Str, v9);
        if ( v20 >= 256 )
          j____report_rangecheckfailure();
        Dest[v20] = 0;
        CLanLobby::Communicate(1050, Dest);
        result = 1;
        break;
      case 0x4Du:
        Instance = UPlay::UPlayManager::GetInstance();
        (*(void (__thiscall **)(int, int))(*(_DWORD *)Instance + 52))(Instance, 1);
        if ( g_pGameType
          && (unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType)
          && (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) )
        {
          byte_40308A0 = 0;
          v3 = (void *)OnlineManager::GetInstance();
          OnlineManager::LeaveSession(v3);
          CGameStateHandler::Switch((int)CStateLoadGame::DynamicCreateFunc, 3);
        }
        else
        {
          byte_40308A0 = 0;
          if ( *((_BYTE *)this + 16932) )
          {
            v4 = (void *)OnlineManager::GetInstance();
            OnlineManager::LeaveSession(v4);
            if ( *((_BYTE *)this + 16933) )
            {
              CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 1);
            }
            else if ( g_pGameType )
            {
              dword_403191C = *(_BYTE *)(g_pGameType + 732) == 0;
              CGameStateHandler::Switch(
                (int)CStateLobbyMapSettings::DynamicCreateFunc,
                *(_BYTE *)(g_pGameType + 732) == 0);
            }
          }
          else
          {
            CLanLobby::Communicate(1049, 0);
            CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 1);
          }
          *((_BYTE *)this + 16933) = 0;
        }
        if ( g_pNetworkEngine )
          (**(void (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
        g_pNetworkEngine = 0;
        if ( g_pGameType )
        {
          delete (CGameType *)g_pGameType;
          g_pGameType = 0;
        }
        result = 1;
        break;
      case 0x4Eu:
        if ( *((_BYTE *)this + 16932) )
        {
          IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
          CStateLobbyGameSettings::SetRandomRaces(this);
          CLanLobby::Communicate(1029, 0);
          v5 = (OnlineManager *)OnlineManager::GetInstance();
          OnlineManager::SetJoinAndDiscoveryOverride(v5, 1);
        }
        result = 1;
        break;
      case 0x50u:
        if ( a2->wparam )
        {
          IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
          IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
        }
        else
        {
          IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
          IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 1);
        }
        result = 1;
        break;
      case 0x51u:
        v33[0] = a2->wparam;
        v33[1] = -1;
        v33[2] = a2->lparam;
        CLanLobby::ChangeSlots(v33);
        result = 1;
        break;
      case 0x52u:
        v36[0] = a2->lparam;
        v36[1] = 2;
        if ( a2->wparam )
          v18 = 7;
        else
          v18 = 6;
        v36[2] = v18;
        CLanLobby::ChangeData(v36);
        result = 1;
        break;
      case 0x53u:
        v38[0] = a2->lparam;
        v38[1] = 1;
        if ( a2->wparam )
          v16 = 7;
        else
          v16 = 6;
        v38[2] = v16;
        CLanLobby::ChangeData(v38);
        result = 1;
        break;
      case 0x54u:
        v35[0] = a2->lparam;
        v35[1] = 0;
        if ( a2->wparam )
          v17 = 7;
        else
          v17 = 6;
        v35[2] = v17;
        CLanLobby::ChangeData(v35);
        result = 1;
        break;
      case 0x55u:
        Src[0] = a2->lparam;
        Src[1] = 4;
        if ( a2->wparam )
          v15 = 7;
        else
          v15 = 6;
        Src[2] = v15;
        CLanLobby::ChangeData(Src);
        result = 1;
        break;
      case 0x56u:
        v37[0] = (char)CPlayerManager::GetLocalSlot();
        v37[1] = 5;
        v37[2] = a2->wparam;
        CLanLobby::ChangeData(v37);
        result = 1;
        break;
      case 0x57u:
        wparam = a2->wparam;
        if ( *(_BYTE *)(wparam + g_pGameType + 998) )
        {
          if ( *(_BYTE *)(wparam + g_pGameType + 440)
            || *(_DWORD *)(g_pGameType + 4 * wparam + 116) == 2
            || *(_DWORD *)(g_pGameType + 4 * wparam + 116) == 3
            || (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) && *(_BYTE *)(wparam + g_pGameType + 1007) )
          {
            if ( ++*(_DWORD *)(g_pGameType + 4 * wparam + 116) == 4 )
            {
              if ( (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) )
                *(_DWORD *)(g_pGameType + 4 * wparam + 116) = 0;
              else
                *(_DWORD *)(g_pGameType + 4 * wparam + 116) = 2;
            }
            if ( *(_DWORD *)(g_pGameType + 4 * wparam + 116) == 2 )
            {
              v28 = -1;
              v29 = *(_BYTE *)(g_pGameType + 696);
              AIName = (_Cnd_internal_imp_t *)CGameSettings::GetAIName((int)v31, wparam);
              v6 = (const wchar_t *)std::wstring::c_str(AIName);
              j__wcscpy(Destination, v6);
              std::wstring::~wstring(v31);
              CLanLobby::ConnectPlayer(Destination, wparam);
            }
            else if ( !*(_DWORD *)(g_pGameType + 4 * wparam + 116) )
            {
              CLanLobby::DisconnectPlayerPeerId(0xFFFFFFFF, wparam);
            }
          }
          if ( (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) )
          {
            v22 = 0;
            for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
            {
              if ( *(_DWORD *)(g_pGameType + 4 * i + 116) == 1 && *(_DWORD *)(g_pGameType + 4 * i + 224) == -1 )
                ++v22;
            }
            v7 = (OnlineManager *)OnlineManager::GetInstance();
            OnlineManager::SetJoinAndDiscoveryOverride(v7, v22 == 0);
            if ( v22 )
            {
              v8 = (OnlineManager *)OnlineManager::GetInstance();
              OnlineManager::SetFreeSlotCount(v8, v22);
            }
          }
          byte_403088C = CStateLobbyGameSettings::CheckContinue(this);
        }
        else if ( *(_DWORD *)(g_pGameType + 4 * wparam + 116) == 2 )
        {
          *(_DWORD *)(g_pGameType + 4 * wparam + 116) = 3;
        }
        else if ( *(_DWORD *)(g_pGameType + 4 * wparam + 116) == 3 )
        {
          *(_DWORD *)(g_pGameType + 4 * wparam + 116) = 2;
        }
        CLanLobby::RedrawPlayerList();
        result = 1;
        break;
      case 0x58u:
        CLanLobby::Communicate(1053, (void *)a2->wparam);
        result = 1;
        break;
      case 0x78u:
        CStateLobbyGameSettings::PaintMap(this);
        result = 1;
        break;
      default:
        return CGuiGameState::OnEvent(this, a2);
    }
  }
  return result;
}


// address=[0x14b9490]
// Decompiled from void __thiscall CStateLobbyGameSettings::UpdatePlayerList(CStateLobbyGameSettings *this, bool a2)
void  CStateLobbyGameSettings::UpdatePlayerList(bool) {
  
  OnlineManager *Instance; // eax
  void *v3; // [esp+4h] [ebp-70h]
  void *PlayerName; // [esp+8h] [ebp-6Ch]
  bool v5; // [esp+1Ch] [ebp-58h]
  int i; // [esp+20h] [ebp-54h]
  int m; // [esp+24h] [ebp-50h]
  char v8; // [esp+2Bh] [ebp-49h]
  int LocalSlot; // [esp+2Ch] [ebp-48h]
  int j; // [esp+34h] [ebp-40h]
  signed int k; // [esp+34h] [ebp-40h]
  _BYTE v13[28]; // [esp+38h] [ebp-3Ch] BYREF
  _BYTE v14[28]; // [esp+54h] [ebp-20h] BYREF

  LocalSlot = -1;
  if ( g_pGameType )
  {
    if ( (unsigned __int8)CGameType::IsWebGame(g_pGameType) )
    {
      for ( i = 0; i < 8; ++i )
      {
        Instance = (OnlineManager *)OnlineManager::GetInstance();
        if ( OnlineManager::GetLocalPeerId(Instance) == *(_DWORD *)(g_pGameType + 4 * i + 224) )
        {
          LocalSlot = i;
          break;
        }
      }
    }
    else
    {
      LocalSlot = (char)CPlayerManager::GetLocalSlot();
    }
    *(_DWORD *)(g_pGameType + 620) = 0;
    v8 = 0;
    for ( j = 0; j < *(_DWORD *)(g_pGameType + 852); ++j )
    {
      if ( *(_DWORD *)(g_pGameType + 4 * j + 452) != 6 )
        v8 = 1;
    }
    for ( k = 0; k < *(_DWORD *)(g_pGameType + 852); ++k )
    {
      *((_BYTE *)this + 2116 * k + 4) = *(_BYTE *)(k + g_pGameType + 440);
      if ( !*((_BYTE *)this + 2116 * k + 4) )
        ++*(_DWORD *)(g_pGameType + 620);
      PlayerName = CGameType::GetPlayerName((void *)g_pGameType, v14, k);
      std::wstring::operator=(PlayerName);
      std::wstring::~wstring(v14);
      *((_DWORD *)this + 529 * k + 10) = *(_DWORD *)(g_pGameType + 4 * k + 332);
      if ( *(_DWORD *)(g_pGameType + 4 * k + 116) == 1 )
      {
        if ( *(_DWORD *)(g_pGameType + 4 * k + 624) >= (unsigned int)CStaticConfigVarInt::operator int(&g_iPingGood) )
        {
          if ( *(_DWORD *)(g_pGameType + 4 * k + 624) >= (unsigned int)CStaticConfigVarInt::operator int(&g_iPingAverage) )
            *((_DWORD *)this + 529 * k + 14) = 2;
          else
            *((_DWORD *)this + 529 * k + 14) = 1;
        }
        else
        {
          *((_DWORD *)this + 529 * k + 14) = 0;
        }
      }
      else
      {
        *((_DWORD *)this + 529 * k + 14) = 0;
      }
      *((_DWORD *)this + 529 * k + 16) = *(_DWORD *)(g_pGameType + 4 * k + 116);
      if ( v8 )
        *((_DWORD *)this + 529 * k + 11) = *(_DWORD *)(g_pGameType + 4 * k + 404);
      *((_DWORD *)this + 529 * k + 13) = *(_DWORD *)(g_pGameType + 4 * k + 488);
      *((_DWORD *)this + 529 * k + 15) = *(_DWORD *)(g_pGameType + 4 * k + 452);
      *((_DWORD *)this + 529 * k + 2) = *(_DWORD *)(g_pGameType + 4 * k + 152);
      *((_BYTE *)this + 2116 * k + 68) = 0;
      if ( (unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType) )
      {
        if ( (unsigned __int8)CGameType::IsHost(g_pGameType) )
          *((_BYTE *)this + 2116 * k + 2117) = *(_BYTE *)(k + g_pGameType + 998);
        else
          *((_BYTE *)this + 2116 * k + 2117) = 0;
      }
      else
      {
        v5 = *(_BYTE *)(k + g_pGameType + 998)
          || *(_DWORD *)(g_pGameType + 4 * k + 116) == 2
          || *(_DWORD *)(g_pGameType + 4 * k + 116) == 3;
        *((_BYTE *)this + 2116 * k + 2117) = v5;
      }
      if ( *((_DWORD *)this + 529 * k + 12) != *(_DWORD *)(g_pGameType + 4 * k + 368) )
      {
        *((_DWORD *)this + 529 * k + 12) = *(_DWORD *)(g_pGameType + 4 * k + 368);
        *((_BYTE *)this + k + 44948) = 1;
      }
      if ( k == LocalSlot )
        byte_40308A0 = *((_DWORD *)this + 529 * k + 15) == 6;
    }
    if ( LocalSlot != -1 )
    {
      dword_403087C = *(_DWORD *)(g_pGameType + 4 * LocalSlot + 332);
      dword_4030888 = *(_DWORD *)(g_pGameType + 4 * LocalSlot + 368);
      dword_4030880 = *(_DWORD *)(g_pGameType + 4 * LocalSlot + 404);
      dword_4030884 = *(_DWORD *)(g_pGameType + 4 * LocalSlot + 152);
      if ( *((_BYTE *)this + 16932) )
        *((_BYTE *)this + 2116 * LocalSlot + 68) = 1;
      byte_4030850 = *(_BYTE *)(LocalSlot + g_pGameType + 1007) == 0;
    }
    dword_4030840 = *(_DWORD *)(g_pGameType + 620);
    dword_403084C = *(_DWORD *)(g_pGameType + 56);
    v3 = (void *)INetworkEngine::ConvertIPAddress((int)v13, *(_DWORD *)(g_pGameType + 68));
    std::string::operator=(&unk_4030804, v3);
    std::string::~string(v13);
    dword_4030844 = *(_DWORD *)(g_pGameType + 112);
    dword_4030848 = *(_DWORD *)(g_pGameType + 112);
    byte_403088D = CGameType::IsLadderGame(g_pGameType);
    byte_4030851 = *(_BYTE *)(g_pGameType + 875) == 0;
    dword_403083C = (int)this + 4;
    std::wstring::operator=(g_pGameType);
    std::string::operator=(&unk_4030820, "Conflict Mode");
    byte_4030855 = *(_BYTE *)(g_pGameType + 560);
    for ( m = 0; m < 8; ++m )
    {
      dword_4030858[m] = *(_DWORD *)(g_pGameType + 4 * m + 368);
      if ( LocalSlot == m )
        dword_4030878 = *(_DWORD *)(g_pGameType + 4 * m + 368);
    }
    if ( *((_BYTE *)this + 16932) )
      byte_403088C = CStateLobbyGameSettings::CheckContinue(this);
    byte_40308A2 = *(_DWORD *)(g_pGameType + 4 * LocalSlot + 452) == 6;
    CStateLobbyGameSettings::SetBackButtonState(this);
    if ( a2 )
    {
      GuiDlgMainGameSettingstUpdate();
      if ( IGfxEngine::GetCursorShape(g_pGfxEngine) == 4
        && byte_4030854
        && !*(_DWORD *)(g_pGameType + 4 * (char)CPlayerManager::GetLocalSlot() + 452) )
      {
        IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
      }
    }
  }
}


// address=[0x14b9b30]
// Decompiled from int __stdcall CStateLobbyGameSettings::PrintChatLine(wchar_t *String, wchar_t *Source)
void  CStateLobbyGameSettings::PrintChatLine(unsigned short const *,unsigned short const *) {
  
  size_t v2; // eax
  size_t v3; // eax
  size_t v5; // [esp+8h] [ebp-310h]
  size_t v6; // [esp+Ch] [ebp-30Ch]
  char Buffer[256]; // [esp+14h] [ebp-304h] BYREF
  char v8[256]; // [esp+114h] [ebp-204h] BYREF
  char Dest[256]; // [esp+214h] [ebp-104h] BYREF

  memset(Dest, 0, sizeof(Dest));
  v2 = j__wcslen(String);
  v6 = j__wcstombs(Dest, String, v2);
  if ( v6 >= 0x100 )
    j____report_rangecheckfailure();
  Dest[v6] = 0;
  v3 = j__wcslen(Source);
  v5 = j__wcstombs(v8, Source, v3);
  if ( v5 >= 0x100 )
    j____report_rangecheckfailure();
  v8[v5] = 0;
  if ( Dest[12] )
    strcpy(&Dest[12], ".");
  j__sprintf(Buffer, "%s: %s", Dest, v8);
  return GuiDlgMainGameSettingsAddChatline(Buffer);
}


// address=[0x14b9ca0]
// Decompiled from int CStateLobbyGameSettings::CompileUserFlags()
static int __cdecl CStateLobbyGameSettings::CompileUserFlags(void) {
  
  int v1; // eax
  const char *v2; // eax
  const WCHAR *v3; // eax
  const char *v4; // eax
  const WCHAR *v5; // eax
  const char *v6; // eax
  const WCHAR *v7; // eax
  const char *v8; // eax
  const WCHAR *v9; // eax
  const char *v10; // eax
  const WCHAR *v11; // eax
  const char *v12; // eax
  const WCHAR *v13; // eax
  const char *v14; // eax
  const WCHAR *v15; // [esp-8h] [ebp-3D0h]
  const char *v16; // [esp-4h] [ebp-3CCh]
  int v17; // [esp+8h] [ebp-3C0h]
  int v18; // [esp+10h] [ebp-3B8h]
  int v19; // [esp+18h] [ebp-3B0h]
  char v20; // [esp+1Eh] [ebp-3AAh]
  char v21; // [esp+1Fh] [ebp-3A9h]
  int i; // [esp+20h] [ebp-3A8h]
  int j; // [esp+20h] [ebp-3A8h]
  int v24; // [esp+20h] [ebp-3A8h]
  char v25[88]; // [esp+24h] [ebp-3A4h] BYREF
  _BYTE v26[28]; // [esp+7Ch] [ebp-34Ch] BYREF
  _BYTE v27[28]; // [esp+98h] [ebp-330h] BYREF
  _BYTE v28[28]; // [esp+B4h] [ebp-314h] BYREF
  _BYTE v29[28]; // [esp+D0h] [ebp-2F8h] BYREF
  _BYTE v30[28]; // [esp+ECh] [ebp-2DCh] BYREF
  _BYTE v31[28]; // [esp+108h] [ebp-2C0h] BYREF
  _BYTE v32[28]; // [esp+124h] [ebp-2A4h] BYREF
  _BYTE v33[28]; // [esp+140h] [ebp-288h] BYREF
  _BYTE v34[12]; // [esp+15Ch] [ebp-26Ch] BYREF
  _DWORD v35[7]; // [esp+168h] [ebp-260h] BYREF
  _BYTE v36[28]; // [esp+184h] [ebp-244h] BYREF
  _BYTE v37[28]; // [esp+1A0h] [ebp-228h] BYREF
  _BYTE v38[28]; // [esp+1BCh] [ebp-20Ch] BYREF
  _BYTE v39[28]; // [esp+1D8h] [ebp-1F0h] BYREF
  _BYTE v40[28]; // [esp+1F4h] [ebp-1D4h] BYREF
  _BYTE v41[28]; // [esp+210h] [ebp-1B8h] BYREF
  _BYTE v42[28]; // [esp+22Ch] [ebp-19Ch] BYREF
  _BYTE v43[28]; // [esp+248h] [ebp-180h] BYREF
  _BYTE v44[28]; // [esp+264h] [ebp-164h] BYREF
  _BYTE v45[28]; // [esp+280h] [ebp-148h] BYREF
  char v46[24]; // [esp+29Ch] [ebp-12Ch] BYREF
  char Buffer[260]; // [esp+2B4h] [ebp-114h] BYREF
  int v48; // [esp+3C4h] [ebp-4h]

  std::wstring::wstring(v35, (wchar_t *)L".gfx");
  v48 = 0;
  std::wstring::wstring(v36, (wchar_t *)L".gil");
  LOBYTE(v48) = 1;
  std::wstring::wstring(v37, (wchar_t *)L".p24");
  LOBYTE(v48) = 2;
  std::wstring::wstring(v38, (wchar_t *)L".p25");
  LOBYTE(v48) = 3;
  std::wstring::wstring(v39, (wchar_t *)L".p26");
  LOBYTE(v48) = 4;
  std::wstring::wstring(v40, (wchar_t *)L".p44");
  LOBYTE(v48) = 5;
  std::wstring::wstring(v41, (wchar_t *)L".p45");
  LOBYTE(v48) = 6;
  std::wstring::wstring(v42, (wchar_t *)L".p46");
  LOBYTE(v48) = 7;
  std::wstring::wstring(v43, (wchar_t *)L".pi2");
  LOBYTE(v48) = 8;
  std::wstring::wstring(v44, (wchar_t *)L".pi4");
  LOBYTE(v48) = 9;
  std::wstring::wstring(v45, (wchar_t *)&word_3746928);
  v48 = 10;
  if ( (**(int (__thiscall ***)(int, const wchar_t *))g_pRTComp)(g_pRTComp, L"Logo\\Current") )
  {
    BBSupportTracePrintF(3, "RTComp: Could not set Working Path!");
    v48 = -1;
    `eh vector destructor iterator'(v35, 0x1Cu, 0xBu, std::wstring::~wstring);
    return -6;
  }
  else
  {
    for ( i = 0; i < 8; ++i )
    {
      IGfxEngine::GetPlayerColor((IGfxEngine *)g_pGfxEngine, i, (struct SGfxColor *)v34);
      v46[3 * i] = v34[0];
      v46[3 * i + 1] = v34[4];
      v46[3 * i + 2] = v34[8];
    }
    (*(void (__thiscall **)(int, char *))(*(_DWORD *)g_pRTComp + 4))(g_pRTComp, v46);
    std::wstring::wstring(v30, (wchar_t *)L"Logo\\Current");
    LOBYTE(v48) = 11;
    std::wstring::operator+=(v30, (wchar_t *)L"\\1");
    std::wstring::wstring(v29, (wchar_t *)L"\\GFX\\1");
    LOBYTE(v48) = 12;
    v19 = (*(int (__thiscall **)(int, int))(*(_DWORD *)g_pRTComp + 8))(g_pRTComp, 8);
    if ( v19 )
    {
      j__sprintf(Buffer, "RTComp Reported Error %d!", v19);
      BBSupportTracePrintF(3, Buffer);
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v25);
      LOBYTE(v48) = 13;
      v1 = (*(int (__thiscall **)(int))(*(_DWORD *)g_pRTComp + 12))(g_pRTComp);
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
        v28,
        v1);
      LOBYTE(v48) = 14;
      v2 = (const char *)std::string::c_str(v28);
      j__sprintf(Buffer, "RTComp Error loading file %s!", v2);
      BBSupportTracePrintF(3, Buffer);
      for ( j = 0; ; ++j )
      {
        v18 = std::wstring::wstring(v27, (wchar_t *)&word_37469DC);
        v21 = std::operator!=<wchar_t>(&v35[7 * j], v18);
        std::wstring::~wstring(v27);
        if ( !v21 )
          break;
        std::operator+<wchar_t>(v32, v30, &v35[7 * j]);
        LOBYTE(v48) = 15;
        v3 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v32);
        if ( !SetFileAttributesW(v3, 0x80u) )
        {
          v4 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v32);
          CTrace::Print("::SetFileAttributes() at file %s failed!", v4);
        }
        v5 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v32);
        if ( !DeleteFileW(v5) )
        {
          v6 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v32);
          CTrace::Print("::DeleteFile() at file %s failed!", v6);
        }
        LOBYTE(v48) = 14;
        std::wstring::~wstring(v32);
      }
      LOBYTE(v48) = 13;
      std::string::~string(v28);
      LOBYTE(v48) = 12;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v25);
      LOBYTE(v48) = 11;
      std::wstring::~wstring(v29);
      LOBYTE(v48) = 10;
      std::wstring::~wstring(v30);
      v48 = -1;
      `eh vector destructor iterator'(v35, 0x1Cu, 0xBu, std::wstring::~wstring);
      return -7;
    }
    else
    {
      v24 = 0;
      while ( 1 )
      {
        v17 = std::wstring::wstring(v26, (wchar_t *)&word_3746A60);
        v20 = std::operator!=<wchar_t>(&v35[7 * v24], v17);
        std::wstring::~wstring(v26);
        if ( !v20 )
          break;
        std::operator+<wchar_t>(v33, v30, &v35[7 * v24]);
        LOBYTE(v48) = 16;
        std::operator+<wchar_t>(v31, v29, &v35[7 * v24]);
        LOBYTE(v48) = 17;
        v7 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v31);
        if ( !SetFileAttributesW(v7, 0x80u) )
        {
          v8 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v31);
          CTrace::Print("::SetFileAttributes() at file %s failed!", v8);
        }
        v15 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v31);
        v9 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v33);
        if ( !CopyFileW(v9, v15, 0) )
        {
          v16 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v31);
          v10 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v33);
          CTrace::Print("::CopyFile() %s -> %s failed!", v10, v16);
        }
        v11 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v33);
        if ( !SetFileAttributesW(v11, 0x80u) )
        {
          v12 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v33);
          CTrace::Print("::SetFileAttributes() at file %s failed!", v12);
        }
        v13 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v33);
        if ( !DeleteFileW(v13) )
        {
          v14 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v33);
          CTrace::Print("::DeleteFile() at file %s failed!", v14);
        }
        ++v24;
        LOBYTE(v48) = 16;
        std::wstring::~wstring(v31);
        LOBYTE(v48) = 12;
        std::wstring::~wstring(v33);
      }
      LOBYTE(v48) = 11;
      std::wstring::~wstring(v29);
      LOBYTE(v48) = 10;
      std::wstring::~wstring(v30);
      v48 = -1;
      `eh vector destructor iterator'(v35, 0x1Cu, 0xBu, std::wstring::~wstring);
      return 0;
    }
  }
}


// address=[0x14ba340]
// Decompiled from char CStateLobbyGameSettings::CopyDefaultUserFlags()
static bool __cdecl CStateLobbyGameSettings::CopyDefaultUserFlags(void) {
  
  const WCHAR *v0; // eax
  const char *v1; // eax
  const WCHAR *v2; // eax
  const char *v3; // eax
  const WCHAR *v5; // [esp-8h] [ebp-1C8h]
  const char *v6; // [esp-4h] [ebp-1C4h]
  int v7; // [esp+4h] [ebp-1BCh]
  _BYTE v8[28]; // [esp+Ch] [ebp-1B4h] BYREF
  _BYTE v9[28]; // [esp+28h] [ebp-198h] BYREF
  _BYTE v10[28]; // [esp+44h] [ebp-17Ch] BYREF
  _BYTE v11[28]; // [esp+60h] [ebp-160h] BYREF
  _DWORD v12[7]; // [esp+7Ch] [ebp-144h] BYREF
  _BYTE v13[28]; // [esp+98h] [ebp-128h] BYREF
  _BYTE v14[28]; // [esp+B4h] [ebp-10Ch] BYREF
  _BYTE v15[28]; // [esp+D0h] [ebp-F0h] BYREF
  _BYTE v16[28]; // [esp+ECh] [ebp-D4h] BYREF
  _BYTE v17[28]; // [esp+108h] [ebp-B8h] BYREF
  _BYTE v18[28]; // [esp+124h] [ebp-9Ch] BYREF
  _BYTE v19[28]; // [esp+140h] [ebp-80h] BYREF
  _BYTE v20[28]; // [esp+15Ch] [ebp-64h] BYREF
  _BYTE v21[28]; // [esp+178h] [ebp-48h] BYREF
  _BYTE v22[28]; // [esp+194h] [ebp-2Ch] BYREF
  int v23; // [esp+1BCh] [ebp-4h]

  CGfxManager::DisableGfxFile((CGfxManager *)g_pGfxManager, 1);
  std::wstring::wstring(v12, (wchar_t *)L".gfx");
  v23 = 0;
  std::wstring::wstring(v13, (wchar_t *)L".gil");
  LOBYTE(v23) = 1;
  std::wstring::wstring(v14, (wchar_t *)L".p24");
  LOBYTE(v23) = 2;
  std::wstring::wstring(v15, (wchar_t *)L".p25");
  LOBYTE(v23) = 3;
  std::wstring::wstring(v16, (wchar_t *)L".p26");
  LOBYTE(v23) = 4;
  std::wstring::wstring(v17, (wchar_t *)L".p44");
  LOBYTE(v23) = 5;
  std::wstring::wstring(v18, (wchar_t *)L".p45");
  LOBYTE(v23) = 6;
  std::wstring::wstring(v19, (wchar_t *)L".p46");
  LOBYTE(v23) = 7;
  std::wstring::wstring(v20, (wchar_t *)L".pi2");
  LOBYTE(v23) = 8;
  std::wstring::wstring(v21, (wchar_t *)L".pi4");
  LOBYTE(v23) = 9;
  std::wstring::wstring(v22, (wchar_t *)&word_3746B90);
  v23 = 10;
  std::wstring::wstring(v8, (wchar_t *)L"GFX\\35");
  LOBYTE(v23) = 11;
  std::wstring::wstring(v9, (wchar_t *)L"GFX\\1");
  LOBYTE(v23) = 12;
  v7 = 0;
  while ( std::wstring::size(&v12[7 * v7]) )
  {
    std::operator+<wchar_t>(v10, v8, &v12[7 * v7]);
    LOBYTE(v23) = 13;
    std::operator+<wchar_t>(v11, v9, &v12[7 * v7]);
    LOBYTE(v23) = 14;
    v0 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v11);
    if ( !SetFileAttributesW(v0, 0x80u) )
    {
      v1 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v11);
      CTrace::Print("::SetFileAttributes() at file %s failed!", v1);
    }
    v5 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v11);
    v2 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v10);
    if ( !CopyFileW(v2, v5, 0) )
    {
      v6 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v11);
      v3 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v10);
      CTrace::Print("::CopyFile() %s -> %s failed!", v3, v6);
      LOBYTE(v23) = 13;
      std::wstring::~wstring(v11);
      LOBYTE(v23) = 12;
      std::wstring::~wstring(v10);
      LOBYTE(v23) = 11;
      std::wstring::~wstring(v9);
      LOBYTE(v23) = 10;
      std::wstring::~wstring(v8);
      v23 = -1;
      `eh vector destructor iterator'(v12, 0x1Cu, 0xBu, std::wstring::~wstring);
      return 0;
    }
    ++v7;
    LOBYTE(v23) = 13;
    std::wstring::~wstring(v11);
    LOBYTE(v23) = 12;
    std::wstring::~wstring(v10);
  }
  LOBYTE(v23) = 11;
  std::wstring::~wstring(v9);
  LOBYTE(v23) = 10;
  std::wstring::~wstring(v8);
  v23 = -1;
  `eh vector destructor iterator'(v12, 0x1Cu, 0xBu, std::wstring::~wstring);
  return 1;
}


// address=[0x14ba670]
// Decompiled from int __cdecl CStateLobbyGameSettings::DrawMap(  unsigned __int16 *a1,  unsigned __int16 *a2,  unsigned int a3,  int a4,  int a5)
static void __cdecl CStateLobbyGameSettings::DrawMap(unsigned short *,unsigned short *,unsigned int,int,int) {
  
  int result; // eax
  int v6; // [esp+1Ch] [ebp-31Ch]
  int v7; // [esp+20h] [ebp-318h]
  int v8; // [esp+24h] [ebp-314h]
  int v9; // [esp+28h] [ebp-310h]
  int v10; // [esp+2Ch] [ebp-30Ch]
  float v11; // [esp+30h] [ebp-308h]
  float v12; // [esp+34h] [ebp-304h]
  float v13; // [esp+34h] [ebp-304h]
  unsigned __int16 v14; // [esp+38h] [ebp-300h]
  int i; // [esp+3Ch] [ebp-2FCh]
  bool v16; // [esp+43h] [ebp-2F5h]
  unsigned __int8 *v17; // [esp+44h] [ebp-2F4h]
  unsigned __int16 v18; // [esp+48h] [ebp-2F0h]
  unsigned __int16 *v19; // [esp+50h] [ebp-2E8h]
  int m; // [esp+54h] [ebp-2E4h]
  int j; // [esp+58h] [ebp-2E0h]
  int k; // [esp+58h] [ebp-2E0h]
  int n; // [esp+5Ch] [ebp-2DCh]
  unsigned __int8 v24; // [esp+63h] [ebp-2D5h]
  _DWORD v25[180]; // [esp+64h] [ebp-2D4h] BYREF

  v16 = IGfxEngine::GetGfxMode((IGfxEngine *)g_pGfxEngine) == 1;
  for ( i = 3; i < 157; ++i )
  {
    for ( j = 3; j < 157; ++j )
    {
      v11 = (float)a5 / 160.0;
      v12 = (float)a4 / 160.0;
      if ( v16 )
      {
        v14 = a1[a4 * (int)(float)((float)i * v11) + (int)(float)((float)j * v12)];
      }
      else
      {
        v18 = a1[a4 * (int)(float)((float)i * v11) + (int)(float)((float)j * v12)];
        v14 = v18 & 0xF | ((((int)v18 >> 5) & 0xF) << 6) | ((((int)v18 >> 10) & 0xF) << 11);
      }
      a2[((a3 * i) >> 1) + j + (160 - i) / 2] = v14;
    }
  }
  v13 = 160.0 / (float)*(int *)(g_pGameType + 56);
  if ( *(_DWORD *)(g_pGameType + 112) )
    v7 = *(_DWORD *)(g_pGameType + 112);
  else
    v7 = *(_DWORD *)(g_pGameType + 852);
  for ( k = 0; ; ++k )
  {
    result = k;
    if ( k >= v7 )
      break;
    v6 = (int)(float)((float)*(int *)(g_pGameType + 4 * k + 296) * v13);
    v8 = (int)(float)((float)*(int *)(g_pGameType + 4 * k + 260) * v13) + (160 - v6) / 2;
    CGfxManager::GetAccessoryGfxInfo((CGfxManager *)g_pGfxManager, (struct SGfxObjectInfo *)v25, k + 52);
    v19 = (unsigned __int16 *)v25[0];
    v17 = (unsigned __int8 *)(v25[0] + 12);
    for ( m = 0; m < v19[1]; ++m )
    {
      for ( n = 0; n < *v19; ++n )
      {
        v24 = *v17++;
        if ( v24 )
        {
          if ( v24 == 1 )
          {
            v9 = *v17++;
            if ( !v9 )
              break;
            m += (v9 - 1) / *v19;
            n += (v9 - 1) % *v19;
            if ( n >= *v19 )
            {
              ++m;
              n -= *v19;
            }
          }
          else
          {
            a2[((a3 * (m + v6 - (__int16)v19[3])) >> 1) + v8 - (__int16)v19[2] + n] = *(_WORD *)(v25[1] + 2 * v24);
          }
        }
        else
        {
          v10 = *v17++;
          if ( !v10 )
            break;
          m += (v10 - 1) / *v19;
          n += (v10 - 1) % *v19;
          if ( n >= *v19 )
          {
            ++m;
            n -= *v19;
          }
        }
      }
    }
  }
  return result;
}


// address=[0x14babf0]
// Decompiled from void __thiscall CStateLobbyGameSettings::PaintMap(_DWORD *this)
void  CStateLobbyGameSettings::PaintMap(void) {
  
  _DWORD *v1; // [esp+0h] [ebp-24h]
  unsigned int v2; // [esp+4h] [ebp-20h] BYREF
  int v3; // [esp+8h] [ebp-1Ch] BYREF
  char v4; // [esp+Eh] [ebp-16h]
  char v5; // [esp+Fh] [ebp-15h]
  char v6[16]; // [esp+10h] [ebp-14h] BYREF

  v1 = this;
  if ( g_pGameType )
  {
    v5 = (*(int (__thiscall **)(void *, int, _DWORD))(*(_DWORD *)g_pRandomMaps + 32))(
           g_pRandomMaps,
           g_pGameType + 28,
           0);
    v4 = *(_BYTE *)(g_pGameType + 696);
    if ( v5 )
    {
      if ( v4 )
      {
        *(_DWORD *)(g_pGameType + 1016) = 0;
        *(_DWORD *)(g_pGameType + 1020) = 0;
        *(_DWORD *)(g_pGameType + 1024) = 0;
      }
      else
      {
        *(_DWORD *)(g_pGameType + 1016) = (*(int (__thiscall **)(void *, _DWORD *))(*(_DWORD *)g_pRandomMaps + 56))(
                                            g_pRandomMaps,
                                            v1);
        *(_DWORD *)(g_pGameType + 1020) = 160;
        *(_DWORD *)(g_pGameType + 1024) = 160;
      }
    }
    if ( *(_DWORD *)(g_pGameType + 1016) )
    {
      v3 = 0;
      v2 = 0;
      IGuiEngine::LockOwnerImage(
        (IGuiEngine *)g_pGUIEngine,
        v1[11236],
        2246,
        (struct SGuiRect *)v6,
        (unsigned __int16 **)&v3,
        &v2);
      if ( v3 )
      {
        CStateLobbyGameSettings::DrawMap(
          *(unsigned __int16 **)(g_pGameType + 1016),
          (unsigned __int16 *)v3,
          v2,
          *(_DWORD *)(g_pGameType + 1020),
          *(_DWORD *)(g_pGameType + 1024));
        IGuiEngine::UnlockOwnerImage((IGuiEngine *)g_pGUIEngine, v1[11236], 2246);
      }
    }
    if ( v5 )
    {
      *(_DWORD *)(g_pGameType + 1016) = 0;
      *(_DWORD *)(g_pGameType + 1020) = 0;
      *(_DWORD *)(g_pGameType + 1024) = 0;
    }
  }
}


// address=[0x14badb0]
// Decompiled from int __thiscall CStateLobbyGameSettings::TransitionToHost(CStateLobbyGameSettings *this)
void  CStateLobbyGameSettings::TransitionToHost(void) {
  
  bool v2; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  *((_BYTE *)this + 16932) = 1;
  *((_BYTE *)this + 16933) = 1;
  CGameType::SetHost((CGameType *)g_pGameType, 1);
  for ( i = 0; i < 8; ++i )
  {
    v2 = *(_BYTE *)(i + g_pGameType + 440)
      || *(_DWORD *)(g_pGameType + 4 * i + 116) == 2
      || *(_DWORD *)(g_pGameType + 4 * i + 116) == 3;
    *(_BYTE *)(i + g_pGameType + 998) = v2;
  }
  return (*(int (__thiscall **)(CStateLobbyGameSettings *, int))(*(_DWORD *)this + 16))(this, 1);
}


// address=[0x14bae60]
// Decompiled from int __thiscall CStateLobbyGameSettings::CreateLobbyGameInfo(_BYTE *this, int a2, int a3)
void  CStateLobbyGameSettings::CreateLobbyGameInfo(class CLanLobbyGameSettings &,std::wstring &) {
  
  *(_BYTE *)(a2 + 140) = CGameType::IsWebGame(g_pGameType);
  std::wstring::operator=(a3);
  *(_BYTE *)(a2 + 138) = this[16932];
  *(_DWORD *)(a2 + 116) = this + 4;
  std::wstring::operator=(g_pGameType);
  std::string::operator=((void *)(a2 + 88), "Conflict Mode");
  *(_BYTE *)(a2 + 217) = 1;
  *(_BYTE *)(a2 + 216) = 0;
  *(_BYTE *)(a2 + 219) = CGameType::IsSaveGame((void *)g_pGameType);
  *(_BYTE *)(a2 + 139) = *(_BYTE *)(g_pGameType + 732) == 0;
  *(_BYTE *)(a2 + 137) = *(_BYTE *)(g_pGameType + 875) == 0;
  *(_DWORD *)(a2 + 128) = *(_DWORD *)(g_pGameType + 112);
  return (*(int (__thiscall **)(_BYTE *, _DWORD))(*(_DWORD *)this + 16))(this, 0);
}


// address=[0x14baf80]
// Decompiled from char __thiscall CStateLobbyGameSettings::CreateRandomGoods(CStateLobbyGameSettings *this)
void  CStateLobbyGameSettings::CreateRandomGoods(void) {
  
  int v1; // eax
  int i; // [esp+4h] [ebp-4h]

  LOBYTE(v1) = CGameType::IsSaveGame((void *)g_pGameType);
  if ( (_BYTE)v1 )
  {
    v1 = BBSupportDbgReport(2, "main\\states\\StateLobbyGameSettings.cpp", 1701, "!g_pGameType->IsSaveGame()");
    if ( v1 == 1 )
      __debugbreak();
  }
  for ( i = 0; i < 7; ++i )
  {
    while ( 1 )
    {
      if ( *(_BYTE *)(i + g_pGameType + 784) )
      {
        if ( *(_BYTE *)(i + g_pGameType + 784) != 1
          && *(_BYTE *)(i + g_pGameType + 784) != 2
          && *(_BYTE *)(i + g_pGameType + 784) != 6
          && *(_BYTE *)(i + g_pGameType + 784) != 13
          && *(_BYTE *)(i + g_pGameType + 784) != 23
          && *(_BYTE *)(i + g_pGameType + 784) != 26
          && *(_BYTE *)(i + g_pGameType + 784) != 30
          && *(_BYTE *)(i + g_pGameType + 784) != 39
          && *(_BYTE *)(i + g_pGameType + 784) != 40
          && *(_BYTE *)(i + g_pGameType + 784) != 35
          && *(_BYTE *)(i + g_pGameType + 784) != 19
          && *(_BYTE *)(i + g_pGameType + 784) != 17
          && *(_BYTE *)(i + g_pGameType + 784) != 5
          && *(_BYTE *)(i + g_pGameType + 784) != 37
          && *(_BYTE *)(i + g_pGameType + 784) != 38
          && *(_BYTE *)(i + g_pGameType + 784) != 41
          && *(_BYTE *)(i + g_pGameType + 784) != 42 )
        {
          LOBYTE(v1) = CStateLobbyGameSettings::CheckDoubleEconomyGood(this, i);
          if ( !(_BYTE)v1 )
            break;
        }
      }
      *(_BYTE *)(i + g_pGameType + 784) = j__rand() % 43;
    }
  }
  return v1;
}


// address=[0x14bb1c0]
// Decompiled from char __thiscall CStateLobbyGameSettings::CheckDoubleEconomyGood(CStateLobbyGameSettings *this, int a2)
bool  CStateLobbyGameSettings::CheckDoubleEconomyGood(int) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < a2; ++i )
  {
    if ( *(unsigned __int8 *)(i + g_pGameType + 784) == *(unsigned __int8 *)(a2 + g_pGameType + 784) )
      return 1;
  }
  return 0;
}


// address=[0x14bb220]
// Decompiled from bool __thiscall CStateLobbyGameSettings::ReadUserflagFiles(CStateLobbyGameSettings *this)
bool  CStateLobbyGameSettings::ReadUserflagFiles(void) {
  
  const wchar_t *v1; // eax
  _DWORD *v2; // eax
  unsigned __int8 v3; // al
  int v5; // [esp+8h] [ebp-2B4h] BYREF
  int v6; // [esp+Ch] [ebp-2B0h] BYREF
  _DWORD v7[2]; // [esp+10h] [ebp-2ACh] BYREF
  BOOL v8; // [esp+18h] [ebp-2A4h]
  intptr_t FindHandle; // [esp+1Ch] [ebp-2A0h]
  CStateLobbyGameSettings *v10; // [esp+20h] [ebp-29Ch]
  bool v11; // [esp+27h] [ebp-295h]
  struct _wfinddata64i32_t FindData; // [esp+28h] [ebp-294h] BYREF
  _BYTE v13[28]; // [esp+258h] [ebp-64h] BYREF
  _BYTE v14[28]; // [esp+274h] [ebp-48h] BYREF
  _BYTE v15[28]; // [esp+290h] [ebp-2Ch] BYREF
  int v16; // [esp+2B8h] [ebp-4h]

  v10 = this;
  *((_DWORD *)this + 4234) = 0;
  std::wstring::wstring(v13, (wchar_t *)L"Logo\\");
  v16 = 0;
  std::wstring::wstring((int)v13);
  LOBYTE(v16) = 1;
  std::wstring::operator+=(v14, (wchar_t *)L"*");
  std::wstring::operator+=(v14, (wchar_t *)L".PNG");
  v1 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v14);
  FindHandle = j___wfindfirst64i32(v1, &FindData);
  if ( FindHandle != -1 )
  {
    do
    {
      std::wstring::wstring((int)v13);
      LOBYTE(v16) = 2;
      std::wstring::operator+=(v15, FindData.name);
      v2 = std::wstring::c_str((_Cnd_internal_imp_t *)v15);
      v3 = (*(int (__thiscall **)(int, _DWORD *, _DWORD *, int *, int *))(*(_DWORD *)g_pRTComp + 16))(
             g_pRTComp,
             v2,
             v7,
             &v6,
             &v5);
      v7[1] = v3;
      if ( v3 && v7[0] == 20 && v6 == 20 && v5 == 24 )
      {
        std::wstring::operator=((int)v15);
        ++*((_DWORD *)v10 + 4234);
      }
      LOBYTE(v16) = 1;
      std::wstring::~wstring(v15);
    }
    while ( j___wfindnext64i32(FindHandle, &FindData) != -1 && *((int *)v10 + 4234) < 1000 );
  }
  if ( FindHandle != -1 )
    j___findclose(FindHandle);
  v8 = *((_DWORD *)v10 + 4234) >= 8;
  v11 = v8;
  LOBYTE(v16) = 0;
  std::wstring::~wstring(v14);
  v16 = -1;
  std::wstring::~wstring(v13);
  return v11;
}


// address=[0x14bb450]
// Decompiled from CStateLobbyGameSettings *__thiscall CStateLobbyGameSettings::ClearFlagnameList(CStateLobbyGameSettings *this)
void  CStateLobbyGameSettings::ClearFlagnameList(void) {
  
  CStateLobbyGameSettings *result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 1000; ++i )
    std::wstring::operator=((char *)this + 28 * i + 16944, (wchar_t *)&word_3746B20);
  result = this;
  *((_DWORD *)this + 4234) = 0;
  return result;
}


// address=[0x14bb4a0]
// Decompiled from int __thiscall CStateLobbyGameSettings::SetupGUI(CStateLobbyGameSettings *this)
void  CStateLobbyGameSettings::SetupGUI(void) {
  
  int result; // eax
  unsigned __int8 v2; // [esp+7h] [ebp-1h]

  if ( byte_4030853 )
    *((_DWORD *)this + 11236) = 4;
  else
    *((_DWORD *)this + 11236) = 19;
  dword_403089C = *((_DWORD *)this + 11236);
  v2 = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, *((_DWORD *)this + 11236), GuiDlgMainGameSettingsProc);
  result = v2;
  if ( v2 )
    return result;
  result = BBSupportDbgReport(2, "main\\states\\StateLobbyGameSettings.cpp", 1224, "bRet");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x14bb540]
// Decompiled from bool __thiscall CStateLobbyGameSettings::CheckContinue(CStateLobbyGameSettings *this)
bool  CStateLobbyGameSettings::CheckContinue(void) {
  
  int v2; // [esp+4h] [ebp-Ch]
  unsigned int v3; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v3 = 0;
  v2 = 0;
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
  {
    if ( *(_BYTE *)(i + g_pGameType + 440) && *(_DWORD *)(g_pGameType + 4 * i + 116) )
      return 0;
    ++v2;
    if ( byte_4030853 && !*(_BYTE *)(i + g_pGameType + 440) && *(_DWORD *)(dword_403083C + 2116 * i + 56) != 6 )
      return 0;
    if ( *(_DWORD *)(g_pGameType + 4 * i + 116) == 1 )
      ++v3;
  }
  return !(unsigned __int8)CGameType::IsLadderGame(g_pGameType) || v3 >= *(_DWORD *)(g_pGameType + 112);
}


// address=[0x14bb630]
// Decompiled from char __thiscall CStateLobbyGameSettings::CheckReady(CStateLobbyGameSettings *this)
bool  CStateLobbyGameSettings::CheckReady(void) {
  
  int LocalSlot; // [esp+18h] [ebp-18h]
  void *v3; // [esp+1Ch] [ebp-14h]
  int v4; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  unsigned int j; // [esp+28h] [ebp-8h]
  unsigned int k; // [esp+28h] [ebp-8h]

  LocalSlot = (char)CPlayerManager::GetLocalSlot();
  if ( !CGameType::IsMapLoaded((CGameType *)g_pGameType) && !byte_40308A3 )
    return 0;
  if ( *(_DWORD *)(g_pGameType + 4 * LocalSlot + 452) == 6 )
    return 1;
  for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
  {
    if ( i != LocalSlot
      && *(_DWORD *)(g_pGameType + 4 * i + 332) == *(_DWORD *)(g_pGameType + 4 * LocalSlot + 332)
      && !*(_BYTE *)(i + g_pGameType + 440) )
    {
      return 0;
    }
  }
  if ( *(_DWORD *)(g_pGameType + 864) != 3 )
    return 1;
  v3 = operator new[](4 * *(_DWORD *)(g_pGameType + 72));
  memset(v3, 0, 4 * *(_DWORD *)(g_pGameType + 72));
  for ( j = 0; j < *(_DWORD *)(g_pGameType + 112); ++j )
  {
    v4 = *(_DWORD *)(g_pGameType + 4 * j + 152);
    if ( !*(_BYTE *)(j + g_pGameType + 440) )
    {
      if ( (v4 < 0 || (unsigned int)v4 >= *(_DWORD *)(g_pGameType + 72))
        && BBSupportDbgReport(
             2,
             "main\\states\\StateLobbyGameSettings.cpp",
             1312,
             "iCurrentAlliance>= 0 && iCurrentAlliance< g_pGameType->m_uiNumberAlliances") == 1 )
      {
        __debugbreak();
      }
      if ( v4 >= 0 && (unsigned int)v4 < *(_DWORD *)(g_pGameType + 72) )
        ++*((_DWORD *)v3 + v4);
    }
  }
  for ( k = 0; k < *(_DWORD *)(g_pGameType + 72); ++k )
  {
    if ( *((int *)v3 + k) <= 0 )
    {
      operator delete(v3);
      return 0;
    }
  }
  operator delete(v3);
  return 1;
}


// address=[0x14bb870]
// Decompiled from int __thiscall CStateLobbyGameSettings::SetBackButtonState(CStateLobbyGameSettings *this)
void  CStateLobbyGameSettings::SetBackButtonState(void) {
  
  int result; // eax

  if ( (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType)
    && (result = CGameType::IsSaveGame((void *)g_pGameType), (_BYTE)result) )
  {
    byte_40308A4 = 1;
  }
  else
  {
    result = 2116 * (char)CPlayerManager::GetLocalSlot(this);
    byte_40308A4 = *(_DWORD *)(dword_403083C + result + 56) != 6;
  }
  return result;
}


// address=[0x14bb8f0]
// Decompiled from void __thiscall CStateLobbyGameSettings::UserflagChanged(CStateLobbyGameSettings *this, int a2, int a3)
void  CStateLobbyGameSettings::UserflagChanged(int,int) {
  
  const WCHAR *v3; // eax
  const char *v4; // eax
  const WCHAR *v5; // eax
  const char *v6; // eax
  const WCHAR *v7; // [esp-8h] [ebp-10Ch]
  const WCHAR *v8; // [esp-8h] [ebp-10Ch]
  const char *v9; // [esp-4h] [ebp-108h]
  const char *v10; // [esp-4h] [ebp-108h]
  char v11[4]; // [esp+4h] [ebp-100h]
  char v13[4]; // [esp+Ch] [ebp-F8h]
  char v14[28]; // [esp+10h] [ebp-F4h] BYREF
  wchar_t Buffer[100]; // [esp+2Ch] [ebp-D8h] BYREF
  int v16; // [esp+100h] [ebp-4h]

  CGfxManager::DisableGfxFile((CGfxManager *)g_pGfxManager, 1);
  std::wstring::wstring(v14);
  v16 = 0;
  if ( g_pGameType )
  {
    if ( g_pNetworkEngine )
    {
      *(_DWORD *)v11 = (char)CPlayerManager::GetLocalSlot();
      if ( g_pGameType )
      {
        if ( a2 < 0 || a3 < 0 )
        {
          swprintf((char *)Buffer, (char *)L"\\HerFig_%d.png", v11[0]);
          std::wstring::operator=(v14, (wchar_t *)L"Logo\\Current");
          std::wstring::operator+=(v14, Buffer);
          v8 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v14);
          v5 = (const WCHAR *)std::wstring::c_str((CStateLobbyGameSettings *)((char *)this
                                                                            + 28
                                                                            * *(_DWORD *)(g_pGameType
                                                                                        + 4 * *(_DWORD *)v11
                                                                                        + 368)
                                                                            + 16944));
          if ( !CopyFileW(v5, v8, 0) )
          {
            v10 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v14);
            v6 = (const char *)std::wstring::c_str((CStateLobbyGameSettings *)((char *)this
                                                                             + 28
                                                                             * *(_DWORD *)(g_pGameType
                                                                                         + 4 * *(_DWORD *)v11
                                                                                         + 368)
                                                                             + 16944));
            CTrace::Print("::CopyFile() %s -> %s failed!", v6, v10);
          }
        }
        else
        {
          *(_DWORD *)v13 = 0;
          while ( *(int *)v13 < 8 )
          {
            swprintf((char *)Buffer, (char *)L"\\HerFig_%d.png", v13[0]);
            std::wstring::operator=(v14, (wchar_t *)L"Logo\\Current");
            std::wstring::operator+=(v14, Buffer);
            v7 = (const WCHAR *)std::wstring::c_str((_Cnd_internal_imp_t *)v14);
            v3 = (const WCHAR *)std::wstring::c_str((CStateLobbyGameSettings *)((char *)this
                                                                              + 28
                                                                              * *(_DWORD *)(g_pGameType
                                                                                          + 4 * *(_DWORD *)v13
                                                                                          + 368)
                                                                              + 16944));
            if ( !CopyFileW(v3, v7, 0) )
            {
              v9 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v14);
              v4 = (const char *)std::wstring::c_str((CStateLobbyGameSettings *)((char *)this
                                                                               + 28
                                                                               * *(_DWORD *)(g_pGameType
                                                                                           + 4 * *(_DWORD *)v13
                                                                                           + 368)
                                                                               + 16944));
              CTrace::Print("::CopyFile() %s -> %s failed!", v4, v9);
            }
            ++*(_DWORD *)v13;
          }
        }
        if ( CStateLobbyGameSettings::CompileUserFlags() )
          CTrace::Print("Display Error-Dialog (No RTCompiler-Error)");
        if ( !CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 1u, 8, 1, 0xFFFFFFFF) )
          CTrace::Print("Display Error-Dialog (Userflags compile error)");
      }
    }
  }
  v16 = -1;
  std::wstring::~wstring(v14);
}


// address=[0x14bbbc0]
// Decompiled from CStateLobbyGameSettings *__thiscall CStateLobbyGameSettings::SetRandomRaces(CStateLobbyGameSettings *this)
void  CStateLobbyGameSettings::SetRandomRaces(void) {
  
  CStateLobbyGameSettings *result; // eax
  int i; // [esp+4h] [ebp-4h]

  if ( !*((_BYTE *)this + 16932)
    && BBSupportDbgReport(2, "main\\states\\StateLobbyGameSettings.cpp", 685, "m_bHost") == 1 )
  {
    __debugbreak();
  }
  result = this;
  if ( *((_BYTE *)this + 16932) )
  {
    for ( i = 0; ; ++i )
    {
      result = (CStateLobbyGameSettings *)g_pGameType;
      if ( i >= *(_DWORD *)(g_pGameType + 852) )
        break;
      if ( *(_DWORD *)(g_pGameType + 4 * i + 404) == 5 )
      {
        if ( (*(_BYTE *)(g_pGameType + 560) & 1) != 0
          && ((*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)g_pAddOn + 4))(g_pAddOn)
           || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)g_pMissionCD2 + 4))(g_pMissionCD2)
           || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)g_pMissionCD3 + 4))(g_pMissionCD3)) )
        {
          *(_DWORD *)(g_pGameType + 4 * i + 404) = j__rand() & 3;
          if ( *(_DWORD *)(g_pGameType + 4 * i + 404) == 3 )
            *(_DWORD *)(g_pGameType + 4 * i + 404) = 4;
        }
        else
        {
          *(_DWORD *)(g_pGameType + 4 * i + 404) = j__rand() % 3;
        }
      }
    }
  }
  return result;
}


