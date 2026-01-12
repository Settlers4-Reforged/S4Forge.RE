#include "CStateMainMenu.h"

// Definitions for class CStateMainMenu

// address=[0x14c16a0]
// Decompiled from CStateMainMenu *__cdecl CStateMainMenu::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateMainMenu::DynamicCreateFunc(void *) {
  
  CStateMainMenu *C; // [esp+Ch] [ebp-10h]

  C = (CStateMainMenu *)operator new(0x14u);
  if ( C )
    return CStateMainMenu::CStateMainMenu(C, a1);
  else
    return 0;
}


// address=[0x14c1740]
// Decompiled from char __cdecl CStateMainMenu::PreLoadGame(char a1)
static bool __cdecl CStateMainMenu::PreLoadGame(std::wstring) {
  
  OnlineManager *Instance; // eax
  char IsMultiplayerGame; // al
  _DWORD v4[10]; // [esp+0h] [ebp-E88h] BYREF
  _BYTE v5[4]; // [esp+2Ch] [ebp-E5Ch] BYREF
  struct CGameChunkGeneral *v6; // [esp+30h] [ebp-E58h]
  int v7; // [esp+34h] [ebp-E54h]
  INetworkEngine *v8; // [esp+38h] [ebp-E50h]
  void *v9; // [esp+3Ch] [ebp-E4Ch]
  BOOL v10; // [esp+40h] [ebp-E48h]
  CGameType *v11; // [esp+44h] [ebp-E44h]
  void *C; // [esp+48h] [ebp-E40h]
  int v13; // [esp+4Ch] [ebp-E3Ch]
  int (__thiscall ***v14)(_DWORD, int); // [esp+50h] [ebp-E38h]
  char v15; // [esp+55h] [ebp-E33h]
  char v16[1324]; // [esp+58h] [ebp-E30h] BYREF
  char Str[1084]; // [esp+584h] [ebp-904h] BYREF
  _BYTE v18[1176]; // [esp+9C0h] [ebp-4C8h] BYREF
  _BYTE v19[28]; // [esp+E58h] [ebp-30h] BYREF
  _DWORD *v20; // [esp+E78h] [ebp-10h]
  int v21; // [esp+E84h] [ebp-4h]

  v20 = v4;
  v21 = 0;
  CGameChunkGeneral::CGameChunkGeneral(v16);
  v6 = (struct CGameChunkGeneral *)v16;
  CGfxManager::DisableGfxFile((CGfxManager *)g_pGfxManager, 1);
  v7 = SaveFilePath::BuildSaveFilePathWithExtension(v19, &a1);
  std::wstring::operator=(v7);
  std::wstring::~wstring(v19);
  S4::CMapFile::CMapFile((CHandleMap *)v18, 0);
  LOBYTE(v21) = 1;
  CUserLogoChunk::CUserLogoChunk((CUserLogoChunk *)v5);
  LOBYTE(v21) = 2;
  S4::CMapFile::Open((S4::CMapFile *)v18, (int)&a1, 1, 1);
  CGameRun::LoadGeneralInfo((struct S4::CMapFile *)v18, v6);
  S4::CMapFile::LoadChunkObject(v18, 136, 0, (int)v5, 0);
  S4::CMapFile::Close((S4::CMapFile *)v18);
  v21 = 1;
  if ( g_pGameType )
  {
    v4[9] = g_pGameType;
    v13 = g_pGameType;
    v4[8] = CGameType::`scalar deleting destructor'((CGameType *)g_pGameType, 1u);
    g_pGameType = 0;
  }
  C = operator new(0x620u);
  LOBYTE(v21) = 4;
  if ( C )
    v11 = CGameType::CGameType((CGameType *)C);
  else
    v11 = 0;
  v4[7] = v11;
  LOBYTE(v21) = 1;
  g_pGameType = (int)v11;
  CGameRun::FillGameType(&a1, v11, v16);
  *(_BYTE *)(g_pGameType + 696) = 1;
  v10 = std::wstring::find((wchar_t *)L"_autoSave", 0) != -1;
  *(_BYTE *)(g_pGameType + 697) = v10;
  Instance = (OnlineManager *)OnlineManager::GetInstance();
  OnlineManager::SetPrivate(Instance, 0);
  std::string::operator=(&unk_402C9B4, Str);
  if ( g_pNetworkEngine )
  {
    v4[6] = g_pNetworkEngine;
    v14 = (int (__thiscall ***)(_DWORD, int))g_pNetworkEngine;
    v4[5] = (**v14)(v14, 1);
    g_pNetworkEngine = 0;
  }
  v9 = operator new(0x18u);
  LOBYTE(v21) = 5;
  if ( v9 )
  {
    IsMultiplayerGame = CGameType::IsMultiplayerGame(g_pGameType);
    v8 = INetworkEngine::INetworkEngine((INetworkEngine *)v9, IsMultiplayerGame);
  }
  else
  {
    v8 = 0;
  }
  v4[4] = v8;
  LOBYTE(v21) = 1;
  g_pNetworkEngine = (int)v8;
  if ( (unsigned __int8)CGameType::IsMultiplayerGame(g_pGameType) )
  {
    INetworkEngine::Start(1, 0, 0, 0);
    CGameType::SetHost((CGameType *)g_pGameType, 1);
    CGameStateHandler::Switch((int)CStateLobbyLoadMP::DynamicCreateFunc, 1);
    CLanLobby::Communicate(1051, 0);
  }
  else
  {
    INetworkEngine::Start(1, 1, *(_DWORD *)(g_pGameType + 112), 0);
    CGameStateHandler::Switch((int)CStateGame::DynamicCreateFunc, 0);
  }
  v15 = 1;
  LOBYTE(v21) = 0;
  S4::CMapFile::~CMapFile((CHandleMap *)v18);
  v21 = -1;
  std::wstring::~wstring(&a1);
  return v15;
}


// address=[0x14c1bc0]
// Decompiled from CStateMainMenu *__thiscall CStateMainMenu::CStateMainMenu(CStateMainMenu *this, void *a2)
 CStateMainMenu::CStateMainMenu(void *) {
  
  size_t v2; // eax
  size_t v3; // eax
  unsigned __int8 IsHost; // al
  unsigned __int8 v5; // al
  wchar_t *v6; // eax
  _DWORD v8[5]; // [esp+0h] [ebp-ECh] BYREF
  void *v9; // [esp+14h] [ebp-D8h]
  int v10; // [esp+18h] [ebp-D4h]
  int v11; // [esp+1Ch] [ebp-D0h]
  CGameType *v12; // [esp+20h] [ebp-CCh]
  int v13; // [esp+24h] [ebp-C8h]
  INetworkEngine *v14; // [esp+28h] [ebp-C4h]
  void *v15; // [esp+2Ch] [ebp-C0h]
  void *Buffer; // [esp+30h] [ebp-BCh]
  CGameType *v17; // [esp+34h] [ebp-B8h]
  void *C; // [esp+38h] [ebp-B4h]
  int v19; // [esp+3Ch] [ebp-B0h]
  int SoundFXVolume; // [esp+40h] [ebp-ACh]
  int MusicVolume; // [esp+44h] [ebp-A8h]
  int v22; // [esp+48h] [ebp-A4h]
  int Instance; // [esp+4Ch] [ebp-A0h]
  char v24; // [esp+53h] [ebp-99h]
  _BYTE *v25; // [esp+54h] [ebp-98h]
  _BYTE v26[28]; // [esp+58h] [ebp-94h] BYREF
  _BYTE v27[72]; // [esp+74h] [ebp-78h] BYREF
  _BYTE v28[28]; // [esp+BCh] [ebp-30h] BYREF
  _DWORD *v29; // [esp+DCh] [ebp-10h]
  int v30; // [esp+E8h] [ebp-4h]

  v29 = v8;
  v25 = this;
  CGuiGameState::CGuiGameState(this);
  v30 = 0;
  *(_DWORD *)v25 = &CStateMainMenu::_vftable_;
  v25[16] = 0;
  Instance = UPlay::UPlayManager::GetInstance();
  (*(void (__thiscall **)(int))(*(_DWORD *)Instance + 60))(Instance);
  v22 = UPlay::UPlayManager::GetInstance();
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v22 + 52))(v22, 1);
  *((_DWORD *)v25 + 3) = 0;
  if ( g_pSoundManager )
  {
    if ( CGameSettings::GetMusicOn() )
      MusicVolume = CGameSettings::GetMusicVolume();
    else
      MusicVolume = 0;
    CSoundManager::SetMusicVolume((CSoundManager *)g_pSoundManager, MusicVolume);
    if ( CGameSettings::GetSoundFxOn() )
      SoundFXVolume = CGameSettings::GetSoundFXVolume();
    else
      SoundFXVolume = 0;
    CSoundManager::SetSoundVolume((CSoundManager *)g_pSoundManager, SoundFXVolume);
  }
  *((_DWORD *)v25 + 1) = a2;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(v25);
  CStateMainMenu::SetupGUI((CStateMainMenu *)v25);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  v19 = *((_DWORD *)v25 + 1);
  switch ( v19 )
  {
    case 0:
      goto LABEL_46;
    case 1:
      CGameStateHandler::Switch((int)CStateCampaignDark::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 2:
      CGameStateHandler::Switch((int)CStateCampaign3X3::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 3:
      CGameStateHandler::Switch((int)CStateTutorial::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 5:
      C = operator new(0x620u);
      LOBYTE(v30) = 1;
      if ( C )
        v17 = CGameType::CGameType((CGameType *)C);
      else
        v17 = 0;
      v12 = v17;
      LOBYTE(v30) = 0;
      g_pGameType = (int)v17;
      v24 = 0;
      CFile::CFile((CFile *)v27);
      LOBYTE(v30) = 3;
      v11 = std::wstring::wstring(v26, (wchar_t *)L"netgame.ini");
      v10 = v11;
      LOBYTE(v30) = 4;
      CFile::Open(v11, 5, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
      LOBYTE(v30) = 3;
      std::wstring::~wstring(v26);
      v30 = 2;
      v2 = CFile::Size(v27);
      v9 = operator new[](v2);
      Buffer = v9;
      v3 = CFile::Size(v27);
      CFile::Read(Buffer, v3, 1u, (int)"d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
      CFile::Close((CFile *)v27, "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\include\\File.h", 0);
      if ( strstr((char *)Buffer, "LocalPlayerCreator=true") )
        v24 = 1;
      v15 = operator new(0x18u);
      LOBYTE(v30) = 6;
      if ( v15 )
        v14 = INetworkEngine::INetworkEngine((INetworkEngine *)v15, 1);
      else
        v14 = 0;
      v8[4] = v14;
      LOBYTE(v30) = 2;
      g_pNetworkEngine = (int)v14;
      if ( (unsigned __int8)INetworkEngine::Start(v24, 0, 0, (wchar_t *)L"netgame.ini") )
      {
        if ( (unsigned __int8)CGameType::IsSaveGame((void *)g_pGameType) )
        {
          (*(void (__thiscall **)(void *))(*(_DWORD *)g_pRandomMaps + 4))(g_pRandomMaps);
          IsHost = INetworkEngine::IsHost((INetworkEngine *)g_pNetworkEngine);
          CGameStateHandler::Switch((int)CStateLobbyLoadMP::DynamicCreateFunc, IsHost);
          LOBYTE(v30) = 0;
          CFile::~CFile();
        }
        else
        {
          if ( INetworkEngine::IsHost((INetworkEngine *)g_pNetworkEngine) )
            CLanLobby::Communicate(1051, (void *)1);
          else
            IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
          v5 = INetworkEngine::IsHost((INetworkEngine *)g_pNetworkEngine);
          CGameStateHandler::Switch((int)CStateLobbyGameSettings::DynamicCreateFunc, v5);
          LOBYTE(v30) = 0;
          CFile::~CFile();
        }
LABEL_46:
        std::wstring::wstring(v28);
        LOBYTE(v30) = 7;
        if ( (*(unsigned __int8 (__thiscall **)(void *, _BYTE *, const wchar_t *, int))(*(_DWORD *)g_pCDDrive + 8))(
               g_pCDDrive,
               v28,
               L"Snd\\Romans*.mp3",
               131073) )
        {
          v6 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v28);
          CSoundManager::PlayBackgroundMusic(5, 4, v6);
        }
        else
        {
          CSoundManager::StopMusic(g_pSoundManager);
        }
        v25[8] = 0;
        LOBYTE(v30) = 0;
        std::wstring::~wstring(v28);
      }
      else
      {
        CTrace::Print("GameHost: Unrecoverable network error while starting network for multiplayer webgame!");
        CGameStateHandler::Queue((int)CStateMessageBox::DynamicCreateFunc, 2402);
        CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
        LOBYTE(v30) = 0;
        CFile::~CFile();
      }
      return (CStateMainMenu *)v25;
    case 6:
      CGameStateHandler::Switch((int)CStateMDCampaignRoman::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 7:
      CGameStateHandler::Switch((int)CStateMDCampaignMayan::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 8:
      CGameStateHandler::Switch((int)CStateMDCampaignViking::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 9:
      CGameStateHandler::Switch((int)CStateMDCampaignsEcoConflict::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 10:
      CGameStateHandler::Switch((int)CStateMDRandomMapParameters::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 11:
      CGameStateHandler::Switch((int)CStateAOCampaignRoman::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 12:
      CGameStateHandler::Switch((int)CStateAOCampaignMayan::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 13:
      CGameStateHandler::Switch((int)CStateAOCampaignViking::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 14:
      CGameStateHandler::Switch((int)CStateAOCampaignTrojan::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 15:
      CGameStateHandler::Switch((int)CStateAOCampaignsSettle::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 16:
      CGameStateHandler::Switch((int)CStateMD2Campaigns::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 17:
      CGameStateHandler::Switch((int)CStateXMD3Campaigns::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 18:
      v25[16] = 1;
      CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 0);
      goto LABEL_46;
    case 19:
      v13 = UPlay::UPlayManager::GetInstance();
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v13 + 36))(v13) )
        CGameStateHandler::Next();
      else
        *((_DWORD *)v25 + 1) = 0;
      goto LABEL_46;
    default:
      CTrace::Print("MainMenu: Unknown Command!!");
      goto LABEL_46;
  }
}


// address=[0x14c22a0]
// Decompiled from void __thiscall CStateMainMenu::~CStateMainMenu(CStateMainMenu *this)
 CStateMainMenu::~CStateMainMenu(void) {
  
  *(_DWORD *)this = &CStateMainMenu::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0)
    && BBSupportDbgReport(2, "main\\states\\StateMainMenu.cpp", 340, "bRet") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14c2320]
// Decompiled from char __thiscall CStateMainMenu::Perform(CStateMainMenu *this)
bool  CStateMainMenu::Perform(void) {
  
  DWORD v2; // esi
  int Instance; // [esp+4h] [ebp-8h]

  Instance = UPlay::UPlayManager::GetInstance();
  if ( !(*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) || *((_BYTE *)this + 16) )
  {
    if ( *((_DWORD *)this + 1) )
      return *((_BYTE *)this + 8) == 0;
    if ( dword_4031D58 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_4031D58);
      if ( dword_4031D58 == -1 )
      {
        dword_4031D54 = timeGetTime();
        j___Init_thread_footer(&dword_4031D58);
      }
    }
    v2 = dword_4031D54 + 30;
    if ( v2 >= timeGetTime() )
      return *((_BYTE *)this + 8) == 0;
    dword_4031D54 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return *((_BYTE *)this + 8) == 0;
  }
  else
  {
    *((_BYTE *)this + 16) = 1;
    CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 0);
    return 1;
  }
}


// address=[0x14c2420]
// Decompiled from char __thiscall CStateMainMenu::OnEvent(CStateMainMenu *this, struct CEvn_Event *a2)
bool  CStateMainMenu::OnEvent(class CEvn_Event &) {
  
  char result; // al
  OnlineManager *Instance; // eax
  char v4; // [esp-38h] [ebp-8Ch] BYREF
  int v5; // [esp-34h] [ebp-88h]
  int v6; // [esp-30h] [ebp-84h]
  int v7; // [esp-2Ch] [ebp-80h]
  int v8; // [esp-28h] [ebp-7Ch]
  int v9; // [esp-24h] [ebp-78h]
  int v10; // [esp-20h] [ebp-74h]
  char v11[32]; // [esp-1Ch] [ebp-70h] BYREF
  int TipsURL; // [esp+4h] [ebp-50h]
  char *v13; // [esp+8h] [ebp-4Ch]
  void *v14; // [esp+Ch] [ebp-48h]
  void *v15; // [esp+10h] [ebp-44h]
  int ManualURL; // [esp+14h] [ebp-40h]
  char *v17; // [esp+18h] [ebp-3Ch]
  void *v18; // [esp+1Ch] [ebp-38h]
  void *v19; // [esp+20h] [ebp-34h]
  void *v20; // [esp+24h] [ebp-30h]
  void *v21; // [esp+28h] [ebp-2Ch]
  int v22; // [esp+2Ch] [ebp-28h]
  int wparam; // [esp+30h] [ebp-24h]
  int Language; // [esp+34h] [ebp-20h]
  CGuiGameState *v25; // [esp+38h] [ebp-1Ch]
  unsigned int event; // [esp+3Ch] [ebp-18h]
  bool v27; // [esp+41h] [ebp-13h]
  char v29; // [esp+44h] [ebp-10h]
  bool v30; // [esp+46h] [ebp-Eh]
  bool v31; // [esp+47h] [ebp-Dh]
  int v32; // [esp+50h] [ebp-4h]

  v25 = this;
  event = a2->event;
  if ( event > 0x1B59 )
  {
    switch ( event )
    {
      case 0x1F41u:
        CGameStateHandler::Switch((int)CStateAOCampaigns::DynamicCreateFunc, 1);
        return 1;
      case 0x2329u:
        CGameStateHandler::Switch((int)CStateMD2Campaigns::DynamicCreateFunc, 1);
        return 1;
      case 0x251Du:
        CGameStateHandler::Switch((int)CStateXMD3Campaigns::DynamicCreateFunc, 1);
        return 1;
      default:
        return CGuiGameState::OnEvent(v25, a2);
    }
  }
  else if ( event == 7001 )
  {
    CGameStateHandler::Switch((int)CStateMDCampaigns::DynamicCreateFunc, 1);
    return 1;
  }
  else
  {
    event -= 13;
    switch ( event )
    {
      case 0u:
        wparam = a2->wparam;
        v31 = (a2->lparam & 0xC) == 12;
        v30 = v31;
        if ( *((int *)v25 + 3) < 2 )
        {
          if ( wparam == 2 && v30 )
            ++*((_DWORD *)v25 + 3);
          else
            *((_DWORD *)v25 + 3) = 0;
        }
        v22 = a2->wparam;
        if ( v22 == 3 && *((_DWORD *)v25 + 3) == 2 && v30 )
        {
          if ( (*(unsigned __int8 (__thiscall **)(void *, _DWORD))(*(_DWORD *)g_pInstallationInfo + 16))(
                 g_pInstallationInfo,
                 0) )
          {
            MessageBoxA(g_hWnd, "Check successful.", "Installation check", 0x40u);
          }
          else
          {
            MessageBoxA(g_hWnd, "Check failed!", "Installation check", 0x30u);
          }
        }
        result = 1;
        break;
      case 0x1Eu:
        CGameStateHandler::Switch((int)CStateLocalType::DynamicCreateFunc, 0);
        result = 1;
        break;
      case 0x1Fu:
        Instance = (OnlineManager *)OnlineManager::GetInstance();
        if ( OnlineManager::IsLoggedIn(Instance) )
        {
          if ( CDebugInfo::IsNetworkAvailable() )
          {
            CGameStateHandler::Switch((int)CStateLobbyConnect::DynamicCreateFunc, 1);
            result = 1;
          }
          else
          {
            std::string::operator=(&g_iMessageBoxStringID, aNetzwerkfehler);
            IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
            if ( !IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgMainMessageBoxProc)
              && BBSupportDbgReport(2, "main\\states\\StateMainMenu.cpp", 441, "bRet") == 1 )
            {
              __debugbreak();
            }
            result = 1;
          }
        }
        else
        {
          Language = CGameSettings::GetLanguage();
          if ( Language == 1 )
          {
            std::string::operator=(&g_iMessageBoxStringID, aDieUbisoftServ);
          }
          else if ( Language == 2 )
          {
            std::string::operator=(&g_iMessageBoxStringID, aLesServicesUbi);
          }
          else
          {
            std::string::operator=(
              &g_iMessageBoxStringID,
              "The Ubisoft services are not available.Please try again later.");
          }
          IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
          IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgMainMessageBoxProc);
          result = 1;
        }
        break;
      case 0x20u:
        CGameStateHandler::Switch((int)CStateSlideshow::DynamicCreateFunc, 1);
        return CGuiGameState::OnEvent(v25, a2);
      case 0x21u:
        CGameStateHandler::Switch((int)CStateLoadType::DynamicCreateFunc, 1);
        result = 1;
        break;
      case 0x22u:
        CGameStateHandler::Switch((int)CStateTutorial::DynamicCreateFunc, 1);
        result = 1;
        break;
      case 0x24u:
        CGameStateHandler::Switch((int)CStateCredits::DynamicCreateFunc, 1);
        result = 1;
        break;
      case 0x25u:
        v19 = v11;
        v21 = std::string::string(v11, (char *)&byte_374C9A5);
        v18 = v21;
        v32 = 0;
        v17 = &v4;
        ManualURL = CGameSettings::GetManualURL((int)&v4);
        v32 = -1;
        if ( !CGameStateHandler::ShowHTMLPage(v4, v5, v6, v7, v8, v9, v10, v11[0]) )
        {
          v29 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
          v29 = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgMainMessageBoxProc);
          if ( !v29 && BBSupportDbgReport(2, "main\\states\\StateMainMenu.cpp", 468, "bRet") == 1 )
            __debugbreak();
        }
        result = 1;
        break;
      case 0x26u:
        v15 = v11;
        v20 = std::string::string(v11, (char *)byte_374C9A6);
        v14 = v20;
        v32 = 1;
        v13 = &v4;
        TipsURL = CGameSettings::GetTipsURL((int)&v4);
        v32 = -1;
        CGameStateHandler::ShowHTMLPage(v4, v5, v6, v7, v8, v9, v10, v11[0]);
        result = 1;
        break;
      case 0x65u:
        v27 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 20);
        CStateMainMenu::SetupGUI(v25);
        result = 1;
        break;
      default:
        return CGuiGameState::OnEvent(v25, a2);
    }
  }
  return result;
}


// address=[0x14c2e20]
// Decompiled from char __thiscall CStateMainMenu::CanProcessInvites(CStateMainMenu *this)
bool  CStateMainMenu::CanProcessInvites(void) {
  
  return 0;
}


// address=[0x14c1720]
// Decompiled from void __thiscall CStateMainMenu::SetupGUI(CStateMainMenu *this)
void  CStateMainMenu::SetupGUI(void) {
  
  CGuiGameState::SetupGui(
    this,
    L"Menu\\GUISetStartscreens.dat",
    0,
    (bool (__cdecl *)(int, int, int))GuiDlgMainscreenProc);
}


