#include "all_headers.h"

// Definitions for class CStateMDBriefing

// address=[0x14c4dc0]
// Decompiled from CStateMDBriefing *__cdecl CStateMDBriefing::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateMDBriefing::DynamicCreateFunc(void *) {
  
  CStateMDBriefing *C; // [esp+Ch] [ebp-10h]

  C = (CStateMDBriefing *)operator new(0x10u);
  if ( C )
    return CStateMDBriefing::CStateMDBriefing(C, a1);
  else
    return 0;
}


// address=[0x14c4e40]
// Decompiled from CStateMDBriefing *__thiscall CStateMDBriefing::CStateMDBriefing(CStateMDBriefing *this, void *a2)
 CStateMDBriefing::CStateMDBriefing(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateMDBriefing::_vftable_;
  CSoundManager::StopMusic(g_pSoundManager);
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pMissionCD, 5, (int)GuiDlgMDBriefingProc);
  *((_DWORD *)this + 1) = (unsigned __int16)a2;
  *((_DWORD *)this + 2) = HIWORD(a2);
  *((_BYTE *)this + 12) = 0;
  if ( *((int *)this + 1) >= 25
    && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 232, "m_iCampaignType < CAMPAIGN_MAX") == 1 )
  {
    __debugbreak();
  }
  switch ( *((_DWORD *)this + 1) )
  {
    case 5:
    case 6:
    case 7:
      if ( *((int *)this + 2) >= 5
        && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 245, "m_iLevel < MD_CAMPAIGN_RMV_COUNT") == 1 )
      {
        __debugbreak();
      }
      byte_402C9F4 = 1;
      break;
    case 8:
    case 9:
      if ( *((int *)this + 2) >= 3
        && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 252, "m_iLevel < MD_CAMPAIGN_ECOCONFLICT_COUNT") == 1 )
      {
        __debugbreak();
      }
      byte_402C9F4 = 1;
      break;
    case 0xA:
      if ( *((int *)this + 2) >= 1
        && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 237, "m_iLevel < MD_BONUS_COUNT") == 1 )
      {
        __debugbreak();
      }
      byte_402C9F4 = 1;
      break;
    default:
      byte_402C9F4 = 0;
      break;
  }
  byte_402C9F5 = 0;
  if ( byte_402C9F4 )
  {
    CStateMDBriefing::InitBriefingTexts(*((_DWORD *)this + 1), *((_DWORD *)this + 2));
  }
  else
  {
    std::string::operator=(g_pGameType + 884);
    std::string::operator=(g_pGameType + 912);
    std::string::operator=(g_pGameType + 940);
    std::string::operator=(g_pGameType + 968);
  }
  CGuiGameState::OpenDialog(this, 5, GuiDlgMDBriefingProc);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  return this;
}


// address=[0x14c5090]
// Decompiled from void __thiscall CStateMDBriefing::~CStateMDBriefing(CStateMDBriefing *this)
 CStateMDBriefing::~CStateMDBriefing(void) {
  
  *(_DWORD *)this = &CStateMDBriefing::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 5);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14c50f0]
// Decompiled from char __thiscall CStateMDBriefing::Perform(CStateMDBriefing *this)
bool  CStateMDBriefing::Perform(void) {
  
  DWORD v2; // esi
  int Instance; // [esp+14h] [ebp-8h]

  Instance = UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) )
  {
    CSoundManager::StopMusic(g_pSoundManager);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    if ( !byte_402C9F4
      && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 554, "g_cBriefingSettings.m_bIsCampaign") == 1 )
    {
      __debugbreak();
    }
    if ( g_pGameType )
    {
      CGameType::`scalar deleting destructor'((CGameType *)g_pGameType, 1u);
      g_pGameType = 0;
    }
    switch ( *((_DWORD *)this + 1) )
    {
      case 5:
        CGameStateHandler::Switch((int)CStateMDCampaignRoman::DynamicCreateFunc, 0);
        break;
      case 6:
        CGameStateHandler::Switch((int)CStateMDCampaignViking::DynamicCreateFunc, 0);
        break;
      case 7:
        CGameStateHandler::Switch((int)CStateMDCampaignMayan::DynamicCreateFunc, 0);
        break;
      case 8:
      case 9:
        CGameStateHandler::Switch((int)CStateMDCampaignsEcoConflict::DynamicCreateFunc, 0);
        break;
      case 0xA:
        CGameStateHandler::Switch((int)CStateMDCampaigns::DynamicCreateFunc, 0);
        break;
      default:
        return 1;
    }
    return 1;
  }
  else
  {
    if ( dword_4031F50 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_4031F50);
      if ( dword_4031F50 == -1 )
      {
        dword_4031F4C = timeGetTime();
        j___Init_thread_footer(&dword_4031F50);
      }
    }
    v2 = dword_4031F4C + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_4031F4C = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14c52d0]
// Decompiled from char __thiscall CStateMDBriefing::OnEvent(CStateMDBriefing *this, struct CEvn_Event *a2)
bool  CStateMDBriefing::OnEvent(class CEvn_Event &) {
  
  CGUIWrapper *Instance; // eax
  const char *v4; // eax
  char *v5; // eax
  OnlineManager *v6; // eax
  char v7; // [esp-40h] [ebp-31Ch] BYREF
  int v8; // [esp-3Ch] [ebp-318h]
  int v9; // [esp-38h] [ebp-314h]
  int v10; // [esp-34h] [ebp-310h]
  int v11; // [esp-30h] [ebp-30Ch]
  int v12; // [esp-2Ch] [ebp-308h]
  int v13; // [esp-28h] [ebp-304h]
  int v14; // [esp-24h] [ebp-300h]
  int v15; // [esp-20h] [ebp-2FCh]
  int v16; // [esp-1Ch] [ebp-2F8h]
  int v17; // [esp-18h] [ebp-2F4h]
  int v18; // [esp-14h] [ebp-2F0h]
  int v19; // [esp-10h] [ebp-2ECh]
  int v20; // [esp-Ch] [ebp-2E8h]
  int v21; // [esp-8h] [ebp-2E4h]
  int v22; // [esp-4h] [ebp-2E0h]
  int v23; // [esp+0h] [ebp-2DCh]
  int v24; // [esp+4h] [ebp-2D8h]
  char *v25; // [esp+8h] [ebp-2D4h]
  int v26; // [esp+Ch] [ebp-2D0h]
  int v27; // [esp+18h] [ebp-2C4h]
  int PlayerName; // [esp+1Ch] [ebp-2C0h]
  INetworkEngine *v29; // [esp+20h] [ebp-2BCh]
  int v30; // [esp+24h] [ebp-2B8h]
  int v31; // [esp+28h] [ebp-2B4h]
  void *v32; // [esp+2Ch] [ebp-2B0h]
  int v33; // [esp+30h] [ebp-2ACh]
  CGameType *v34; // [esp+34h] [ebp-2A8h]
  void *v35; // [esp+38h] [ebp-2A4h]
  int v36; // [esp+3Ch] [ebp-2A0h]
  CEvn_Event *v37; // [esp+40h] [ebp-29Ch]
  void *v38; // [esp+44h] [ebp-298h]
  INetworkEngine *v39; // [esp+48h] [ebp-294h]
  int v40; // [esp+4Ch] [ebp-290h]
  CGameType *v41; // [esp+50h] [ebp-28Ch]
  void *C; // [esp+54h] [ebp-288h]
  int v43; // [esp+58h] [ebp-284h]
  int (__thiscall ***v44)(_DWORD, int); // [esp+5Ch] [ebp-280h]
  bool v45; // [esp+63h] [ebp-279h]
  int i; // [esp+64h] [ebp-278h]
  unsigned int event; // [esp+6Ch] [ebp-270h]
  char v48; // [esp+71h] [ebp-26Bh]
  char v49; // [esp+72h] [ebp-26Ah]
  char MapData; // [esp+73h] [ebp-269h]
  CGuiGameState *v51; // [esp+74h] [ebp-268h]
  char v52; // [esp+7Ah] [ebp-262h]
  char v53; // [esp+7Bh] [ebp-261h]
  _BYTE v54[28]; // [esp+7Ch] [ebp-260h] BYREF
  CEvn_Event v55; // [esp+98h] [ebp-244h] BYREF
  char v56[28]; // [esp+B0h] [ebp-22Ch] BYREF
  char Buffer[512]; // [esp+CCh] [ebp-210h] BYREF
  int v58; // [esp+2D8h] [ebp-4h]

  v51 = this;
  event = a2->event;
  if ( event <= 0x78 )
  {
    switch ( event )
    {
      case 0x78u:
        *((_BYTE *)v51 + 12) = 0;
        return 1;
      case 0xBu:
        if ( (unsigned __int16)a2->wparam == 27 )
        {
          v37 = CEvn_Event::CEvn_Event(&v55, 0x1B75u, 0, 0, 0);
          v58 = 0;
          IEventEngine::SendAMessage(g_pEvnEngine, v37);
          v58 = -1;
          CEvn_Event::~CEvn_Event(&v55);
          return 1;
        }
        break;
      case 0x72u:
        v45 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 20);
        CGuiGameState::SetupExtraGui(g_pMissionCD, 5, (int)GuiDlgMDBriefingProc);
        CGuiGameState::OpenDialog(v51, 5, GuiDlgMDBriefingProc);
        return 1;
    }
    return CGuiGameState::OnEvent(v51, a2);
  }
  if ( event == 7029 )
  {
    CSoundManager::StopMusic(g_pSoundManager);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    if ( !byte_402C9F4
      && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 326, "g_cBriefingSettings.m_bIsCampaign") == 1 )
    {
      __debugbreak();
    }
    if ( g_pGameType )
    {
      v36 = g_pGameType;
      v43 = g_pGameType;
      v35 = CGameType::`scalar deleting destructor'((CGameType *)g_pGameType, 1u);
      g_pGameType = 0;
    }
    switch ( *((_DWORD *)v51 + 1) )
    {
      case 5:
        CGameStateHandler::Switch((int)CStateMDCampaignRoman::DynamicCreateFunc, 0);
        break;
      case 6:
        CGameStateHandler::Switch((int)CStateMDCampaignViking::DynamicCreateFunc, 0);
        break;
      case 7:
        CGameStateHandler::Switch((int)CStateMDCampaignMayan::DynamicCreateFunc, 0);
        break;
      case 8:
      case 9:
        CGameStateHandler::Switch((int)CStateMDCampaignsEcoConflict::DynamicCreateFunc, 0);
        break;
      case 0xA:
        CGameStateHandler::Switch((int)CStateMDCampaigns::DynamicCreateFunc, 0);
        break;
      default:
        return 1;
    }
    return 1;
  }
  else
  {
    if ( event != 7030 )
      return CGuiGameState::OnEvent(v51, a2);
    Instance = (CGUIWrapper *)CGUIWrapper::GetInstance(v23);
    CGUIWrapper::ReleaseGUIGFXFile(Instance);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
    CGfxManager::DisableGfxFile((CGfxManager *)g_pGfxManager, 1);
    if ( (unsigned __int8)CStateLobbyGameSettings::CopyDefaultUserFlags() )
    {
      CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 1u, 8, 1, 0xFFFFFFFF);
      C = operator new(0x620u);
      v58 = 1;
      if ( C )
        v41 = CGameType::CGameType((CGameType *)C);
      else
        v41 = 0;
      v34 = v41;
      v58 = -1;
      g_pGameType = (int)v41;
      v52 = 0;
      v26 = 256;
      v22 = *((_DWORD *)v51 + 2) + 1;
      v4 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)((char *)&unk_4031E78
                                                                   + 28 * *((_DWORD *)v51 + 1)
                                                                   - 140));
      j___snwprintf(Buffer, 0xFFu, v4, v22);
      std::wstring::wstring(v56);
      v58 = 2;
      if ( (*(unsigned __int8 (__thiscall **)(void *, char *, char *, int))(*(_DWORD *)g_pCDDrive + 8))(
             g_pCDDrive,
             v56,
             Buffer,
             3145736) )
      {
        v22 = 0;
        v21 = 0;
        v20 = *((_DWORD *)v51 + 1);
        v19 = dword_4031CFC;
        v18 = 0;
        v17 = 1;
        v16 = 0;
        v15 = 0;
        v14 = 1;
        v25 = &v7;
        v24 = std::wstring::wstring((int)v56);
        MapData = CGameType::LoadMapData(v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22);
        v52 = MapData;
      }
      if ( v52 )
      {
        if ( !CGameType::IsCampaignMap((CGameType *)g_pGameType)
          && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 464, "g_pGameType->IsCampaignMap()") == 1 )
        {
          __debugbreak();
        }
        IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
        if ( g_pNetworkEngine )
        {
          v31 = g_pNetworkEngine;
          v44 = (int (__thiscall ***)(_DWORD, int))g_pNetworkEngine;
          v30 = (**v44)(v44, 1);
          g_pNetworkEngine = 0;
        }
        v38 = operator new(0x18u);
        LOBYTE(v58) = 3;
        if ( v38 )
          v39 = INetworkEngine::INetworkEngine((INetworkEngine *)v38, 0);
        else
          v39 = 0;
        v29 = v39;
        LOBYTE(v58) = 2;
        g_pNetworkEngine = (int)v39;
        *(_DWORD *)(g_pGameType + 112) = *(_DWORD *)(g_pGameType + 852);
        *(_DWORD *)(g_pGameType + 188) = INetworkEngine::GetLocalIP((CGameHost **)g_pNetworkEngine);
        v6 = (OnlineManager *)OnlineManager::GetInstance();
        *(_DWORD *)(g_pGameType + 224) = OnlineManager::GetLocalPeerId(v6);
        PlayerName = CGameSettings::GetPlayerName((int)v54);
        v27 = PlayerName;
        LOBYTE(v58) = 4;
        CGameType::SetPlayerName(0, PlayerName);
        LOBYTE(v58) = 2;
        std::wstring::~wstring(v54);
        *(_DWORD *)(g_pGameType + 740) = *((_DWORD *)v51 + 1);
        *(_DWORD *)(g_pGameType + 744) = *((_DWORD *)v51 + 2);
        *(_DWORD *)(g_pGameType + 692) = 3;
        for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
          *(_BYTE *)(i + g_pGameType + 440) = 0;
        INetworkEngine::Start(1, 1, *(_DWORD *)(g_pGameType + 852), 0);
        CGameStateHandler::Switch((int)CStateGame::DynamicCreateFunc, 0);
        v48 = 1;
        v58 = -1;
        std::wstring::~wstring(v56);
        return v48;
      }
      else
      {
        v5 = g_pStringEngine->GetString(g_pStringEngine, 3291);
        std::string::operator=(&g_iMessageBoxStringID, v5);
        v53 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 5);
        if ( !g_pMissionCD && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 448, "g_pMissionCD") == 1 )
          __debugbreak();
        (*(void (__thiscall **)(int, _DWORD, char (__cdecl *)(int, int, int)))(*(_DWORD *)g_pMissionCD + 12))(
          g_pMissionCD,
          0,
          GuiDlgMainscreenProc);
        v53 = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgMainMessageBoxProc);
        if ( !v53 && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 451, "bRet") == 1 )
          __debugbreak();
        BBSupportTracePrintF(3, "MissionCD Map '%s' not found!", Buffer);
        IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
        if ( g_pGameType )
        {
          v33 = g_pGameType;
          v40 = g_pGameType;
          v32 = CGameType::`scalar deleting destructor'((CGameType *)g_pGameType, 1u);
          g_pGameType = 0;
        }
        v49 = 1;
        v58 = -1;
        std::wstring::~wstring(v56);
        return v49;
      }
    }
    else
    {
      IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 5);
      if ( !g_pMissionCD && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 413, "g_pMissionCD") == 1 )
        __debugbreak();
      (*(void (__thiscall **)(int, int, bool (__cdecl *)(int, int, int)))(*(_DWORD *)g_pMissionCD + 12))(
        g_pMissionCD,
        20,
        GuiDlgMainMessageBoxProc);
      CGameStateHandler::Switch((int)CStateMessageBox::DynamicCreateFunc, 2398);
      return 1;
    }
  }
}


// address=[0x14c5b70]
// Decompiled from void *__cdecl CStateMDBriefing::InitBriefingTexts(int a1, int a2)
static void __cdecl CStateMDBriefing::InitBriefingTexts(int,int) {
  
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
  char *v19; // eax
  char *v20; // eax
  char *v21; // eax
  char *v22; // eax
  char *v23; // eax
  char *v24; // eax
  char *v25; // eax
  char *v26; // eax

  if ( (!a1 || a1 >= 25)
    && BBSupportDbgReport(
         2,
         "main\\States\\StateMDBriefing.cpp",
         611,
         "( _iCampaignType ) && ( _iCampaignType < CAMPAIGN_MAX )") == 1 )
  {
    __debugbreak();
  }
  switch ( a1 )
  {
    case 5:
    case 6:
    case 7:
      if ( a2 >= 5
        && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 624, "_iLevel < MD_CAMPAIGN_RMV_COUNT") == 1 )
      {
        __debugbreak();
      }
      byte_402C9F4 = 1;
      break;
    case 8:
    case 9:
      if ( a2 >= 3
        && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 631, "_iLevel < MD_CAMPAIGN_ECOCONFLICT_COUNT") == 1 )
      {
        __debugbreak();
      }
      byte_402C9F4 = 1;
      break;
    case 10:
      if ( a2 >= 1 && BBSupportDbgReport(2, "main\\States\\StateMDBriefing.cpp", 616, "_iLevel < MD_BONUS_COUNT") == 1 )
        __debugbreak();
      byte_402C9F4 = 1;
      break;
    default:
      break;
  }
  dword_402C9F0 = a2;
  dword_402C9EC = a1;
  switch ( a1 )
  {
    case 5:
      v2 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A490[a2]);
      std::string::operator=(&unk_402C9B4, v2);
      v3 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A4A4[a2]);
      std::string::operator=(&unk_402C998, v3);
      v4 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A4B8[a2]);
      std::string::operator=(&unk_402C9D0, v4);
      v5 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A4CC[a2]);
      result = std::string::operator=(&unk_402C97C, v5);
      break;
    case 6:
      v7 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A4E0[a2]);
      std::string::operator=(&unk_402C9B4, v7);
      v8 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A4F4[a2]);
      std::string::operator=(&unk_402C998, v8);
      v9 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A508[a2]);
      std::string::operator=(&unk_402C9D0, v9);
      v10 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A51C[a2]);
      result = std::string::operator=(&unk_402C97C, v10);
      break;
    case 7:
      v11 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A530[a2]);
      std::string::operator=(&unk_402C9B4, v11);
      v12 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A544[a2]);
      std::string::operator=(&unk_402C998, v12);
      v13 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A558[a2]);
      std::string::operator=(&unk_402C9D0, v13);
      v14 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A56C[a2]);
      result = std::string::operator=(&unk_402C97C, v14);
      break;
    case 8:
      v15 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A580[a2]);
      std::string::operator=(&unk_402C9B4, v15);
      v16 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A58C[a2]);
      std::string::operator=(&unk_402C998, v16);
      v17 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A598[a2]);
      std::string::operator=(&unk_402C9D0, v17);
      v18 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A5A4[a2]);
      result = std::string::operator=(&unk_402C97C, v18);
      break;
    case 9:
      v19 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A5B0[a2]);
      std::string::operator=(&unk_402C9B4, v19);
      v20 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A5BC[a2]);
      std::string::operator=(&unk_402C998, v20);
      v21 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A5C8[a2]);
      std::string::operator=(&unk_402C9D0, v21);
      v22 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A5D4[a2]);
      result = std::string::operator=(&unk_402C97C, v22);
      break;
    case 10:
      v23 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A5E0[a2]);
      std::string::operator=(&unk_402C9B4, v23);
      v24 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A5E4[a2]);
      std::string::operator=(&unk_402C998, v24);
      v25 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A5E8[a2]);
      std::string::operator=(&unk_402C9D0, v25);
      v26 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A5EC[a2]);
      result = std::string::operator=(&unk_402C97C, v26);
      break;
    default:
      result = (void *)BBSupportDbgReportF(
                         2,
                         "main\\States\\StateMDBriefing.cpp",
                         692,
                         "Invalid CampaignType during CStateMDBriefing::InitBriefingTexts init!");
      if ( result == (void *)1 )
        __debugbreak();
      break;
  }
  return result;
}


// address=[0x14c65e0]
// Decompiled from char __thiscall CStateMDBriefing::CanProcessInvites(CStateMDBriefing *this)
bool  CStateMDBriefing::CanProcessInvites(void) {
  
  return 0;
}


