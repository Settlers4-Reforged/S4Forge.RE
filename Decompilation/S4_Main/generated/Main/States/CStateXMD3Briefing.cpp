#include "CStateXMD3Briefing.h"

// Definitions for class CStateXMD3Briefing

// address=[0x14cca70]
// Decompiled from CStateXMD3Briefing *__cdecl CStateXMD3Briefing::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateXMD3Briefing::DynamicCreateFunc(void * a1) {
  
  CStateXMD3Briefing *C; // [esp+Ch] [ebp-10h]

  C = (CStateXMD3Briefing *)operator new(0x10u);
  if ( C )
    return CStateXMD3Briefing::CStateXMD3Briefing(C, a1);
  else
    return 0;
}


// address=[0x14ccbd0]
// Decompiled from CStateXMD3Briefing *__thiscall CStateXMD3Briefing::CStateXMD3Briefing(CStateXMD3Briefing *this, void *a2)
 CStateXMD3Briefing::CStateXMD3Briefing(void * a2) {
  
  wchar_t *v2; // eax
  wchar_t *v3; // eax
  wchar_t *v4; // eax
  char *v5; // eax
  std::wstring v7; // [esp-40h] [ebp-2A0h] BYREF
  BOOL bAIActive; // [esp-24h] [ebp-284h]
  int v9; // [esp-20h] [ebp-280h]
  int v10; // [esp-1Ch] [ebp-27Ch]
  int v11; // [esp-18h] [ebp-278h]
  int iSetupIndex; // [esp-14h] [ebp-274h]
  DWORD iAIDifficulty; // [esp-10h] [ebp-270h]
  int v14; // [esp-Ch] [ebp-26Ch]
  BOOL bIsLadderGame; // [esp-8h] [ebp-268h]
  int bIsClanGame; // [esp-4h] [ebp-264h]
  void *v17; // [esp+4h] [ebp-25Ch]
  std::wstring *v18; // [esp+8h] [ebp-258h]
  int v19; // [esp+Ch] [ebp-254h]
  void *v20; // [esp+10h] [ebp-250h]
  CGameType *v21; // [esp+14h] [ebp-24Ch]
  CGameType *v22; // [esp+18h] [ebp-248h]
  CGameType *v23; // [esp+1Ch] [ebp-244h]
  CGameType *v24; // [esp+20h] [ebp-240h]
  void *C; // [esp+24h] [ebp-23Ch]
  int v26; // [esp+28h] [ebp-238h]
  char MapData; // [esp+2Dh] [ebp-233h]
  char v28; // [esp+2Eh] [ebp-232h]
  char v29; // [esp+2Fh] [ebp-231h]
  int *v30; // [esp+30h] [ebp-230h]
  std::wstring v31; // [esp+34h] [ebp-22Ch] BYREF
  char Buffer[512]; // [esp+50h] [ebp-210h] BYREF
  int v33; // [esp+25Ch] [ebp-4h]

  v30 = (int *)this;
  CGuiGameState::CGuiGameState(this);
  v33 = 0;
  *v30 = (int)&CStateXMD3Briefing::_vftable_;
  CSoundManager::StopMusic(g_pSoundManager);
  CGuiGameState::EnsureGfxEngineIsInGuiMode(v30);
  CGuiGameState::SetupExtraGui((int)g_pMissionCD3, 1, (int)GuiDlgXMD3BriefingProc);
  v30[1] = (unsigned __int16)a2;
  v30[2] = HIWORD(a2);
  *((_BYTE *)v30 + 12) = 0;
  if ( v30[1] >= 25
    && BBSupportDbgReport(2, "main\\states\\statexmd3briefing.cpp", 193, "m_iCampaignType < CAMPAIGN_MAX") == 1 )
  {
    __debugbreak();
  }
  v26 = v30[1];
  if ( v26 < 21 || v26 > 24 )
  {
    byte_402C9F4 = 0;
  }
  else
  {
    if ( v30[2] >= 4
      && BBSupportDbgReport(2, "main\\states\\statexmd3briefing.cpp", 201, "m_iLevel < XMD3_CAMPAIGN_RMVT_COUNT") == 1 )
    {
      __debugbreak();
    }
    byte_402C9F4 = 1;
  }
  byte_402C9F5 = 0;
  if ( byte_402C9F4 )
  {
    CStateXMD3Briefing::InitBriefingTexts(v30[1], v30[2]);
  }
  else
  {
    std::string::operator=(&stru_402C998, &g_pGameType->m_sDesciptionText3);
    std::string::operator=(&stru_402C9D0, &g_pGameType->m_sDesciptionText0);
    std::string::operator=(&stru_402C97C, &g_pGameType->m_sDesciptionText1);
    std::string::operator=(&stru_402C9B4, &g_pGameType->m_sDesciptionText2);
  }
  CGuiGameState::OpenDialog((CGuiGameState *)v30, 1, (bool (__cdecl *)(int, int, int))GuiDlgXMD3BriefingProc);
  IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 0);
  C = operator new(0x620u);
  LOBYTE(v33) = 1;
  if ( C )
    v24 = CGameType::CGameType((CGameType *)C);
  else
    v24 = 0;
  v22 = v24;
  LOBYTE(v33) = 0;
  g_pGameType = v24;
  v29 = 0;
  v19 = 256;
  bIsClanGame = v30[2] + 1;
  v2 = std::wstring::c_str(&stru_4032170 + v30[1] - 21);
  snwprintf(Buffer, 0xFFu, (const char *const)v2, bIsClanGame);
  std::wstring::wstring(&v31);
  LOBYTE(v33) = 2;
  if ( g_pCDDrive->GetCDPath(g_pCDDrive, (char *)&v31, Buffer, 3145984) )
  {
    bIsClanGame = 0;
    bIsLadderGame = 0;
    v14 = v30[1];
    iAIDifficulty = s_uAIDifficulty;
    iSetupIndex = 0;
    v11 = 0;
    v10 = 1;
    v9 = 0;
    bAIActive = 1;
    v18 = &v7;
    v17 = std::wstring::wstring(&v7, &v31);
    MapData = CGameType::LoadMapData(
                g_pGameType,
                v7,
                bAIActive,
                v9,
                v10,
                v11,
                iSetupIndex,
                iAIDifficulty,
                v14,
                bIsLadderGame,
                bIsClanGame);
    v29 = MapData;
    BBSupportTracePrintF(1, "GetCDPath success: ");
    v3 = std::wstring::c_str(&v31);
    BBSupportTracePrint(1, v3);
  }
  else
  {
    BBSupportTracePrintF(1, "GetCDPath failure: ");
    v4 = std::wstring::c_str(&v31);
    BBSupportTracePrint(1, v4);
  }
  if ( !v29 )
  {
    v5 = g_pStringEngine->GetString(g_pStringEngine, 3785);
    std::string::operator=(&g_iMessageBoxStringID, v5);
    v28 = IGuiEngine::CloseDialog(g_pGUIEngine, 1);
    if ( !g_pMissionCD3 && BBSupportDbgReport(2, "main\\states\\statexmd3briefing.cpp", 266, "g_pMissionCD3") == 1 )
      __debugbreak();
    ((void (__thiscall *)(CMissionCD3 *, _DWORD, char (__cdecl *)(int, int, int)))g_pMissionCD3->j_?EnsureMainGUI@CExtraCD@@UAEXHP6A_NHHH@Z@Z)(
      g_pMissionCD3,
      0,
      GuiDlgMainscreenProc);
    v28 = IGuiEngine::OpenDialog(g_pGUIEngine, 20, (bool (__cdecl *)(int, int, int))GuiDlgMainMessageBoxProc);
    if ( !v28 && BBSupportDbgReport(2, "main\\states\\statexmd3briefing.cpp", 269, "bRet") == 1 )
      __debugbreak();
    BBSupportTracePrintF(3, "MissionCD3 Map '%s' not found!", Buffer);
    IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 0);
    if ( g_pGameType )
    {
      v21 = g_pGameType;
      v23 = g_pGameType;
      v20 = delete g_pGameType;
      g_pGameType = 0;
    }
  }
  LOBYTE(v33) = 0;
  std::wstring::~wstring(&v31);
  return (CStateXMD3Briefing *)v30;
}


// address=[0x14cd0b0]
// Decompiled from void __thiscall CStateXMD3Briefing::~CStateXMD3Briefing(CStateXMD3Briefing *this)
 CStateXMD3Briefing::~CStateXMD3Briefing(void) {
  
  *(_DWORD *)this = &CStateXMD3Briefing::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 1);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14cd110]
// Decompiled from char __thiscall CStateXMD3Briefing::Perform(CStateXMD3Briefing *this)
bool  CStateXMD3Briefing::Perform(void) {
  
  DWORD v2; // esi
  int v4; // [esp+10h] [ebp-Ch]
  int Instance; // [esp+18h] [ebp-4h]

  Instance = UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) )
  {
    CSoundManager::StopMusic(g_pSoundManager);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    if ( !byte_402C9F4
      && BBSupportDbgReport(2, "main\\states\\statexmd3briefing.cpp", 548, "g_cBriefingSettings.m_bIsCampaign") == 1 )
    {
      __debugbreak();
    }
    if ( g_pGameType )
      delete (CGameType *)g_pGameType;
    g_pGameType = 0;
    v4 = *((_DWORD *)this + 1);
    if ( v4 < 21 || v4 > 24 )
    {
      return 1;
    }
    else
    {
      CGameStateHandler::Switch((int)CStateXMD3Campaigns::DynamicCreateFunc, 0);
      return 1;
    }
  }
  else
  {
    if ( dword_4032208 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_4032208);
      if ( dword_4032208 == -1 )
      {
        dword_4032204 = timeGetTime();
        j___Init_thread_footer(&dword_4032208);
      }
    }
    v2 = dword_4032204 + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_4032204 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14cd280]
// Decompiled from char __thiscall CStateXMD3Briefing::OnEvent(CStateXMD3Briefing *this, struct CEvn_Event *a2)
bool  CStateXMD3Briefing::OnEvent(class CEvn_Event & a2) {
  
  CGUIWrapper *Instance; // eax
  OnlineManager *v4; // eax
  int PlayerName; // [esp+8h] [ebp-90h]
  CEvn_Event *v6; // [esp+24h] [ebp-74h]
  INetworkEngine *v7; // [esp+30h] [ebp-68h]
  INetworkEngine *C; // [esp+34h] [ebp-64h]
  int v9; // [esp+38h] [ebp-60h]
  int i; // [esp+48h] [ebp-50h]
  unsigned int event; // [esp+4Ch] [ebp-4Ch]
  _BYTE v13[28]; // [esp+54h] [ebp-44h] BYREF
  CEvn_Event v14; // [esp+70h] [ebp-28h] BYREF
  int v15; // [esp+94h] [ebp-4h]

  event = a2->m_iEventId;
  if ( event <= 0x78 )
  {
    switch ( event )
    {
      case 0x78u:
        *((_BYTE *)this + 12) = 0;
        return 1;
      case 0xBu:
        if ( (unsigned __int16)a2->m_wParam == 27 )
        {
          v6 = CEvn_Event::CEvn_Event(&v14, 0x2523u, 0, 0, 0);
          v15 = 0;
          IEventEngine::SendAMessage(g_pEvnEngine, v6);
          v15 = -1;
          CEvn_Event::~CEvn_Event(&v14);
          return 1;
        }
        break;
      case 0x72u:
        IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 20);
        CGuiGameState::SetupExtraGui(g_pMissionCD3, 1, (int)GuiDlgXMD3BriefingProc);
        CGuiGameState::OpenDialog(this, 1, GuiDlgXMD3BriefingProc);
        return 1;
    }
    return CGuiGameState::OnEvent(this, a2);
  }
  if ( event == 9507 )
  {
    CSoundManager::StopMusic(g_pSoundManager);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    if ( !byte_402C9F4
      && BBSupportDbgReport(2, "main\\states\\statexmd3briefing.cpp", 327, "g_cBriefingSettings.m_bIsCampaign") == 1 )
    {
      __debugbreak();
    }
    if ( g_pGameType )
      delete (CGameType *)g_pGameType;
    g_pGameType = 0;
    v9 = *((_DWORD *)this + 1);
    if ( v9 < 21 || v9 > 24 )
    {
      return 1;
    }
    else
    {
      CGameStateHandler::Switch((int)CStateXMD3Campaigns::DynamicCreateFunc, 0);
      return 1;
    }
  }
  else
  {
    if ( event != 9508 )
      return CGuiGameState::OnEvent(this, a2);
    Instance = (CGUIWrapper *)CGUIWrapper::GetInstance();
    CGUIWrapper::ReleaseGUIGFXFile(Instance);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
    CGfxManager::DisableGfxFile((CGfxManager *)g_pGfxManager, 1);
    if ( (unsigned __int8)CStateLobbyGameSettings::CopyDefaultUserFlags() )
    {
      CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 1u, 8, 1, 0xFFFFFFFF);
      if ( !g_pGameType && BBSupportDbgReport(2, "main\\states\\statexmd3briefing.cpp", 406, "g_pGameType") == 1 )
        __debugbreak();
      if ( !CGameType::IsCampaignMap((CGameType *)g_pGameType)
        && BBSupportDbgReport(2, "main\\states\\statexmd3briefing.cpp", 450, "g_pGameType->IsCampaignMap()") == 1 )
      {
        __debugbreak();
      }
      IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
      if ( g_pNetworkEngine )
      {
        (**(void (__thiscall ***)(int, int))g_pNetworkEngine)(g_pNetworkEngine, 1);
        g_pNetworkEngine = 0;
      }
      C = (INetworkEngine *)operator new(0x18u);
      v15 = 1;
      if ( C )
        v7 = INetworkEngine::INetworkEngine(C, 0);
      else
        v7 = 0;
      v15 = -1;
      g_pNetworkEngine = (int)v7;
      *(_DWORD *)(g_pGameType + 112) = *(_DWORD *)(g_pGameType + 852);
      *(_DWORD *)(g_pGameType + 188) = INetworkEngine::GetLocalIP((CGameHost **)g_pNetworkEngine);
      v4 = (OnlineManager *)OnlineManager::GetInstance();
      *(_DWORD *)(g_pGameType + 224) = OnlineManager::GetLocalPeerId(v4);
      PlayerName = CGameSettings::GetPlayerName((int)v13);
      v15 = 2;
      CGameType::SetPlayerName(0, PlayerName);
      v15 = -1;
      std::wstring::~wstring(v13);
      *(_DWORD *)(g_pGameType + 740) = *((_DWORD *)this + 1);
      *(_DWORD *)(g_pGameType + 744) = *((_DWORD *)this + 2);
      *(_DWORD *)(g_pGameType + 692) = 3;
      for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
        *(_BYTE *)(i + g_pGameType + 440) = 0;
      INetworkEngine::Start(1, 1, *(_DWORD *)(g_pGameType + 852), 0);
      CGameStateHandler::Switch((int)CStateGame::DynamicCreateFunc, 0);
      return 1;
    }
    else
    {
      IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 1);
      if ( !g_pMissionCD3 && BBSupportDbgReport(2, "main\\states\\statexmd3briefing.cpp", 397, "g_pMissionCD3") == 1 )
        __debugbreak();
      (*(void (__thiscall **)(int, int, bool (__cdecl *)(int, int, int)))(*(_DWORD *)g_pMissionCD3 + 12))(
        g_pMissionCD3,
        20,
        GuiDlgMainMessageBoxProc);
      CGameStateHandler::Switch((int)CStateMessageBox::DynamicCreateFunc, 2398);
      return 1;
    }
  }
}


// address=[0x14cd770]
// Decompiled from void *__cdecl CStateXMD3Briefing::InitBriefingTexts(int a1, int a2)
void __cdecl CStateXMD3Briefing::InitBriefingTexts(int a1, int a2) {
  
  char *v2; // eax
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  void *result; // eax
  char *v7; // eax
  char *v8; // eax
  char *v9; // eax
  char *v10; // eax
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  char *v15; // eax
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax

  if ( (!a1 || a1 >= 25)
    && BBSupportDbgReport(
         2,
         "main\\states\\statexmd3briefing.cpp",
         641,
         "( _iCampaignType ) && ( _iCampaignType < CAMPAIGN_MAX )") == 1 )
  {
    __debugbreak();
  }
  if ( a1 >= 21 && a1 <= 24 )
  {
    if ( a2 >= 4
      && BBSupportDbgReport(2, "main\\states\\statexmd3briefing.cpp", 649, "_iLevel < XMD3_CAMPAIGN_RMVT_COUNT") == 1 )
    {
      __debugbreak();
    }
    byte_402C9F4 = 1;
  }
  dword_402C9F0 = a2;
  dword_402C9EC = a1;
  switch ( a1 )
  {
    case 21:
      v2 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A6D8[a2]);
      std::string::operator=(&stru_402C9B4, v2);
      v3 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A6E8[a2]);
      std::string::operator=(&stru_402C998, v3);
      v4 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A6F8[a2]);
      std::string::operator=(&stru_402C9D0, v4);
      v5 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A708[a2]);
      result = std::string::operator=(&stru_402C97C, v5);
      break;
    case 22:
      v7 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A718[a2]);
      std::string::operator=(&stru_402C9B4, v7);
      v8 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A728[a2]);
      std::string::operator=(&stru_402C998, v8);
      v9 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A738[a2]);
      std::string::operator=(&stru_402C9D0, v9);
      v10 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A748[a2]);
      result = std::string::operator=(&stru_402C97C, v10);
      break;
    case 23:
      v11 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A758[a2]);
      std::string::operator=(&stru_402C9B4, v11);
      v12 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A768[a2]);
      std::string::operator=(&stru_402C998, v12);
      v13 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A778[a2]);
      std::string::operator=(&stru_402C9D0, v13);
      v14 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A788[a2]);
      result = std::string::operator=(&stru_402C97C, v14);
      break;
    case 24:
      v15 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A798[a2]);
      std::string::operator=(&stru_402C9B4, v15);
      v16 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A7A8[a2]);
      std::string::operator=(&stru_402C998, v16);
      v17 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A7B8[a2]);
      std::string::operator=(&stru_402C9D0, v17);
      v18 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A7C8[a2]);
      result = std::string::operator=(&stru_402C97C, v18);
      break;
    default:
      result = (void *)BBSupportDbgReportF(
                         2,
                         "main\\states\\statexmd3briefing.cpp",
                         694,
                         "Invalid CampaignType during CStateXMD3Briefing::InitBriefingTexts init!");
      if ( result == (void *)1 )
        __debugbreak();
      break;
  }
  return result;
}


// address=[0x14cdf50]
// Decompiled from char __thiscall CStateXMD3Briefing::CanProcessInvites(CStateXMD3Briefing *this)
bool  CStateXMD3Briefing::CanProcessInvites(void) {
  
  return 0;
}


// address=[0x14ccaf0]
// Decompiled from char __stdcall CStateXMD3Briefing::PaintMap(char a1)
void  CStateXMD3Briefing::PaintMap(bool a1) {
  
  char result; // al
  unsigned int v2; // [esp+4h] [ebp-1Ch] BYREF
  unsigned __int16 *v3; // [esp+8h] [ebp-18h] BYREF
  _BYTE v4[16]; // [esp+Ch] [ebp-14h] BYREF

  result = a1;
  if ( !a1 )
    return IGuiEngine::EraseOwnerImage((IGuiEngine *)g_pGUIEngine, 1, 2926);
  if ( !g_pGameType || !*(_DWORD *)(g_pGameType + 1016) )
    return result;
  v3 = 0;
  v2 = 0;
  result = IGuiEngine::LockOwnerImage((IGuiEngine *)g_pGUIEngine, 1, 2926, (struct SGuiRect *)v4, &v3, &v2);
  if ( !v3 )
    return result;
  CStateLobbyGameSettings::DrawMap(
    *(unsigned __int16 **)(g_pGameType + 1016),
    v3,
    v2,
    *(_DWORD *)(g_pGameType + 1020),
    *(_DWORD *)(g_pGameType + 1024));
  return IGuiEngine::UnlockOwnerImage((IGuiEngine *)g_pGUIEngine, 1, 2926);
}


