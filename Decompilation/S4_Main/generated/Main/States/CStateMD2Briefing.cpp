#include "all_headers.h"

// Definitions for class CStateMD2Briefing

// address=[0x14c30d0]
// Decompiled from CStateMD2Briefing *__cdecl CStateMD2Briefing::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateMD2Briefing::DynamicCreateFunc(void *) {
  
  CStateMD2Briefing *C; // [esp+Ch] [ebp-10h]

  C = (CStateMD2Briefing *)operator new(0x10u);
  if ( C )
    return CStateMD2Briefing::CStateMD2Briefing(C, a1);
  else
    return 0;
}


// address=[0x14c3150]
// Decompiled from CStateMD2Briefing *__thiscall CStateMD2Briefing::CStateMD2Briefing(CStateMD2Briefing *this, void *a2)
 CStateMD2Briefing::CStateMD2Briefing(void *) {
  
  int v3; // [esp+4h] [ebp-14h]

  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateMD2Briefing::_vftable_;
  CSoundManager::StopMusic(g_pSoundManager);
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pMissionCD2, 1, (int)GuiDlgMD2BriefingProc);
  *((_DWORD *)this + 1) = (unsigned __int16)a2;
  *((_DWORD *)this + 2) = HIWORD(a2);
  *((_BYTE *)this + 12) = 0;
  if ( *((int *)this + 1) >= 25
    && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 209, "m_iCampaignType < CAMPAIGN_MAX") == 1 )
  {
    __debugbreak();
  }
  v3 = *((_DWORD *)this + 1);
  if ( v3 < 17 || v3 > 20 )
  {
    byte_402C9F4 = 0;
  }
  else
  {
    if ( *((int *)this + 2) >= 5
      && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 217, "m_iLevel < MD2_CAMPAIGN_RMVT_COUNT") == 1 )
    {
      __debugbreak();
    }
    byte_402C9F4 = 1;
  }
  byte_402C9F5 = 0;
  if ( byte_402C9F4 )
  {
    CStateMD2Briefing::InitBriefingTexts(*((_DWORD *)this + 1), *((_DWORD *)this + 2));
  }
  else
  {
    std::string::operator=(g_pGameType + 884);
    std::string::operator=(g_pGameType + 912);
    std::string::operator=(g_pGameType + 940);
    std::string::operator=(g_pGameType + 968);
  }
  CGuiGameState::OpenDialog(this, 1, GuiDlgMD2BriefingProc);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  return this;
}


// address=[0x14c3320]
// Decompiled from void __thiscall CStateMD2Briefing::~CStateMD2Briefing(CStateMD2Briefing *this)
 CStateMD2Briefing::~CStateMD2Briefing(void) {
  
  *(_DWORD *)this = &CStateMD2Briefing::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 1);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14c3380]
// Decompiled from char __thiscall CStateMD2Briefing::Perform(CStateMD2Briefing *this)
bool  CStateMD2Briefing::Perform(void) {
  
  char result; // al
  DWORD v2; // esi
  int Instance; // [esp+14h] [ebp-8h]

  Instance = UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) )
  {
    CSoundManager::StopMusic(g_pSoundManager);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    if ( !byte_402C9F4
      && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 522, "g_cBriefingSettings.m_bIsCampaign") == 1 )
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
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
        CGameStateHandler::Switch((int)CStateMD2Campaigns::DynamicCreateFunc, 0);
        result = 1;
        break;
      default:
        result = 1;
        break;
    }
  }
  else
  {
    if ( dword_4031E30 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_4031E30);
      if ( dword_4031E30 == -1 )
      {
        dword_4031E2C = timeGetTime();
        j___Init_thread_footer(&dword_4031E30);
      }
    }
    v2 = dword_4031E2C + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_4031E2C = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
  return result;
}


// address=[0x14c3560]
// Decompiled from char __thiscall CStateMD2Briefing::OnEvent(CStateMD2Briefing *this, struct CEvn_Event *a2)
bool  CStateMD2Briefing::OnEvent(class CEvn_Event &) {
  
  char result; // al
  CGUIWrapper *Instance; // eax
  const char *v4; // eax
  char *v5; // eax
  OnlineManager *v6; // eax
  char v7; // [esp-40h] [ebp-320h] BYREF
  int v8; // [esp-3Ch] [ebp-31Ch]
  int v9; // [esp-38h] [ebp-318h]
  int v10; // [esp-34h] [ebp-314h]
  int v11; // [esp-30h] [ebp-310h]
  int v12; // [esp-2Ch] [ebp-30Ch]
  int v13; // [esp-28h] [ebp-308h]
  int v14; // [esp-24h] [ebp-304h]
  int v15; // [esp-20h] [ebp-300h]
  int v16; // [esp-1Ch] [ebp-2FCh]
  int v17; // [esp-18h] [ebp-2F8h]
  int v18; // [esp-14h] [ebp-2F4h]
  int v19; // [esp-10h] [ebp-2F0h]
  int v20; // [esp-Ch] [ebp-2ECh]
  int v21; // [esp-8h] [ebp-2E8h]
  int v22; // [esp-4h] [ebp-2E4h]
  int v23; // [esp+0h] [ebp-2E0h]
  int v24; // [esp+4h] [ebp-2DCh]
  char *v25; // [esp+8h] [ebp-2D8h]
  int v26; // [esp+Ch] [ebp-2D4h]
  int wparam; // [esp+10h] [ebp-2D0h]
  CEvn_Event *v28; // [esp+14h] [ebp-2CCh]
  int v29; // [esp+20h] [ebp-2C0h]
  int PlayerName; // [esp+24h] [ebp-2BCh]
  INetworkEngine *v31; // [esp+28h] [ebp-2B8h]
  int v32; // [esp+2Ch] [ebp-2B4h]
  int v33; // [esp+30h] [ebp-2B0h]
  void *v34; // [esp+34h] [ebp-2ACh]
  int v35; // [esp+38h] [ebp-2A8h]
  CGameType *v36; // [esp+3Ch] [ebp-2A4h]
  void *v37; // [esp+40h] [ebp-2A0h]
  int v38; // [esp+44h] [ebp-29Ch]
  INetworkEngine *v39; // [esp+48h] [ebp-298h]
  void *v40; // [esp+4Ch] [ebp-294h]
  int v41; // [esp+50h] [ebp-290h]
  CGameType *v42; // [esp+54h] [ebp-28Ch]
  void *C; // [esp+58h] [ebp-288h]
  int v44; // [esp+5Ch] [ebp-284h]
  int (__thiscall ***v45)(_DWORD, int); // [esp+60h] [ebp-280h]
  bool v46; // [esp+67h] [ebp-279h]
  int i; // [esp+68h] [ebp-278h]
  unsigned int event; // [esp+70h] [ebp-270h]
  char v49; // [esp+75h] [ebp-26Bh]
  char v50; // [esp+76h] [ebp-26Ah]
  char MapData; // [esp+77h] [ebp-269h]
  CGuiGameState *v52; // [esp+78h] [ebp-268h]
  char v53; // [esp+7Eh] [ebp-262h]
  char v54; // [esp+7Fh] [ebp-261h]
  _BYTE v55[28]; // [esp+80h] [ebp-260h] BYREF
  CEvn_Event v56; // [esp+9Ch] [ebp-244h] BYREF
  char v57[28]; // [esp+B4h] [ebp-22Ch] BYREF
  char Buffer[512]; // [esp+D0h] [ebp-210h] BYREF
  int v59; // [esp+2DCh] [ebp-4h]

  v52 = this;
  event = a2->event;
  if ( event <= 0x78 )
  {
    switch ( event )
    {
      case 0x78u:
        *((_BYTE *)v52 + 12) = 0;
        return 1;
      case 0xBu:
        if ( (unsigned __int16)a2->wparam == 27 )
        {
          v28 = CEvn_Event::CEvn_Event(&v56, 0x2330u, 0, 0, 0);
          v59 = 0;
          IEventEngine::SendAMessage(g_pEvnEngine, v28);
          v59 = -1;
          CEvn_Event::~CEvn_Event(&v56);
          return 1;
        }
        break;
      case 0x72u:
        v46 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 20);
        CGuiGameState::SetupExtraGui(g_pMissionCD2, 1, (int)GuiDlgMD2BriefingProc);
        CGuiGameState::OpenDialog(v52, 1, GuiDlgMD2BriefingProc);
        return 1;
    }
    return CGuiGameState::OnEvent(v52, a2);
  }
  if ( event == 9008 )
  {
    CSoundManager::StopMusic(g_pSoundManager);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    if ( !byte_402C9F4
      && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 291, "g_cBriefingSettings.m_bIsCampaign") == 1 )
    {
      __debugbreak();
    }
    if ( g_pGameType )
    {
      v38 = g_pGameType;
      v44 = g_pGameType;
      v37 = CGameType::`scalar deleting destructor'((CGameType *)g_pGameType, 1u);
      g_pGameType = 0;
    }
    wparam = a2->wparam;
    switch ( *((_DWORD *)v52 + 1) )
    {
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
        CGameStateHandler::Switch((int)CStateMD2Campaigns::DynamicCreateFunc, 0);
        result = 1;
        break;
      default:
        result = 1;
        break;
    }
  }
  else
  {
    if ( event != 9009 )
      return CGuiGameState::OnEvent(v52, a2);
    Instance = (CGUIWrapper *)CGUIWrapper::GetInstance(v23);
    CGUIWrapper::ReleaseGUIGFXFile(Instance);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
    CGfxManager::DisableGfxFile((CGfxManager *)g_pGfxManager, 1);
    if ( (unsigned __int8)CStateLobbyGameSettings::CopyDefaultUserFlags() )
    {
      CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, 1u, 8, 1, 0xFFFFFFFF);
      C = operator new(0x620u);
      v59 = 1;
      if ( C )
        v42 = CGameType::CGameType((CGameType *)C);
      else
        v42 = 0;
      v36 = v42;
      v59 = -1;
      g_pGameType = (int)v42;
      v53 = 0;
      v26 = 256;
      v22 = *((_DWORD *)v52 + 2) + 1;
      v4 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)((char *)&unk_4031D98
                                                                   + 28 * *((_DWORD *)v52 + 1)
                                                                   - 476));
      j___snwprintf(Buffer, 0xFFu, v4, v22);
      std::wstring::wstring(v57);
      v59 = 2;
      if ( (*(unsigned __int8 (__thiscall **)(void *, char *, char *, int))(*(_DWORD *)g_pCDDrive + 8))(
             g_pCDDrive,
             v57,
             Buffer,
             3145792) )
      {
        v22 = 0;
        v21 = 0;
        v20 = *((_DWORD *)v52 + 1);
        v19 = dword_4031CFC;
        v18 = 0;
        v17 = 1;
        v16 = 0;
        v15 = 0;
        v14 = 1;
        v25 = &v7;
        v24 = std::wstring::wstring((int)v57);
        MapData = CGameType::LoadMapData(v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21, v22);
        v53 = MapData;
      }
      if ( v53 )
      {
        if ( !CGameType::IsCampaignMap((CGameType *)g_pGameType)
          && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 432, "g_pGameType->IsCampaignMap()") == 1 )
        {
          __debugbreak();
        }
        IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
        if ( g_pNetworkEngine )
        {
          v33 = g_pNetworkEngine;
          v45 = (int (__thiscall ***)(_DWORD, int))g_pNetworkEngine;
          v32 = (**v45)(v45, 1);
          g_pNetworkEngine = 0;
        }
        v40 = operator new(0x18u);
        LOBYTE(v59) = 3;
        if ( v40 )
          v39 = INetworkEngine::INetworkEngine((INetworkEngine *)v40, 0);
        else
          v39 = 0;
        v31 = v39;
        LOBYTE(v59) = 2;
        g_pNetworkEngine = (int)v39;
        *(_DWORD *)(g_pGameType + 112) = *(_DWORD *)(g_pGameType + 852);
        *(_DWORD *)(g_pGameType + 188) = INetworkEngine::GetLocalIP((CGameHost **)g_pNetworkEngine);
        v6 = (OnlineManager *)OnlineManager::GetInstance();
        *(_DWORD *)(g_pGameType + 224) = OnlineManager::GetLocalPeerId(v6);
        PlayerName = CGameSettings::GetPlayerName((int)v55);
        v29 = PlayerName;
        LOBYTE(v59) = 4;
        CGameType::SetPlayerName(0, PlayerName);
        LOBYTE(v59) = 2;
        std::wstring::~wstring(v55);
        *(_DWORD *)(g_pGameType + 740) = *((_DWORD *)v52 + 1);
        *(_DWORD *)(g_pGameType + 744) = *((_DWORD *)v52 + 2);
        *(_DWORD *)(g_pGameType + 692) = 3;
        for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
          *(_BYTE *)(i + g_pGameType + 440) = 0;
        INetworkEngine::Start(1, 1, *(_DWORD *)(g_pGameType + 852), 0);
        CGameStateHandler::Switch((int)CStateGame::DynamicCreateFunc, 0);
        v49 = 1;
        v59 = -1;
        std::wstring::~wstring(v57);
        return v49;
      }
      else
      {
        v5 = g_pStringEngine->GetString(g_pStringEngine, 2731);
        std::string::operator=(&g_iMessageBoxStringID, v5);
        v54 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 1);
        if ( !g_pMissionCD2 && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 416, "g_pMissionCD2") == 1 )
          __debugbreak();
        (*(void (__thiscall **)(int, _DWORD, char (__cdecl *)(int, int, int)))(*(_DWORD *)g_pMissionCD2 + 12))(
          g_pMissionCD2,
          0,
          GuiDlgMainscreenProc);
        v54 = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgMainMessageBoxProc);
        if ( !v54 && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 419, "bRet") == 1 )
          __debugbreak();
        BBSupportTracePrintF(3, "MissionCD2 Map '%s' not found!", Buffer);
        IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
        if ( g_pGameType )
        {
          v35 = g_pGameType;
          v41 = g_pGameType;
          v34 = CGameType::`scalar deleting destructor'((CGameType *)g_pGameType, 1u);
          g_pGameType = 0;
        }
        v50 = 1;
        v59 = -1;
        std::wstring::~wstring(v57);
        return v50;
      }
    }
    else
    {
      IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 1);
      if ( !g_pMissionCD2 && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 381, "g_pMissionCD2") == 1 )
        __debugbreak();
      (*(void (__thiscall **)(int, int, bool (__cdecl *)(int, int, int)))(*(_DWORD *)g_pMissionCD2 + 12))(
        g_pMissionCD2,
        20,
        GuiDlgMainMessageBoxProc);
      CGameStateHandler::Switch((int)CStateMessageBox::DynamicCreateFunc, 2398);
      return 1;
    }
  }
  return result;
}


// address=[0x14c3e10]
// Decompiled from void *__cdecl CStateMD2Briefing::InitBriefingTexts(int a1, int a2)
static void __cdecl CStateMD2Briefing::InitBriefingTexts(int,int) {
  
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
         "main\\states\\StateMD2Briefing.cpp",
         581,
         "( _iCampaignType ) && ( _iCampaignType < CAMPAIGN_MAX )") == 1 )
  {
    __debugbreak();
  }
  if ( a1 >= 17 && a1 <= 20 )
  {
    if ( a2 >= 5
      && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 589, "_iLevel < MD2_CAMPAIGN_RMVT_COUNT") == 1 )
    {
      __debugbreak();
    }
    byte_402C9F4 = 1;
  }
  dword_402C9F0 = a2;
  dword_402C9EC = a1;
  switch ( a1 )
  {
    case 17:
      v2 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A310[a2]);
      std::string::operator=(&unk_402C9B4, v2);
      v3 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A324[a2]);
      std::string::operator=(&unk_402C998, v3);
      v4 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A338[a2]);
      std::string::operator=(&unk_402C9D0, v4);
      v5 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A34C[a2]);
      result = std::string::operator=(&unk_402C97C, v5);
      break;
    case 18:
      v7 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A360[a2]);
      std::string::operator=(&unk_402C9B4, v7);
      v8 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A374[a2]);
      std::string::operator=(&unk_402C998, v8);
      v9 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A388[a2]);
      std::string::operator=(&unk_402C9D0, v9);
      v10 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A39C[a2]);
      result = std::string::operator=(&unk_402C97C, v10);
      break;
    case 19:
      v11 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A3B0[a2]);
      std::string::operator=(&unk_402C9B4, v11);
      v12 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A3C4[a2]);
      std::string::operator=(&unk_402C998, v12);
      v13 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A3D8[a2]);
      std::string::operator=(&unk_402C9D0, v13);
      v14 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A3EC[a2]);
      result = std::string::operator=(&unk_402C97C, v14);
      break;
    case 20:
      v15 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A400[a2]);
      std::string::operator=(&unk_402C9B4, v15);
      v16 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A414[a2]);
      std::string::operator=(&unk_402C998, v16);
      v17 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A428[a2]);
      std::string::operator=(&unk_402C9D0, v17);
      v18 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A43C[a2]);
      result = std::string::operator=(&unk_402C97C, v18);
      break;
    default:
      result = (void *)BBSupportDbgReportF(
                         2,
                         "main\\states\\StateMD2Briefing.cpp",
                         634,
                         "Invalid CampaignType during CStateMD2Briefing::InitBriefingTexts init!");
      if ( result == (void *)1 )
        __debugbreak();
      break;
  }
  return result;
}


// address=[0x14c4600]
// Decompiled from char __thiscall CStateMD2Briefing::CanProcessInvites(CStateMD2Briefing *this)
bool  CStateMD2Briefing::CanProcessInvites(void) {
  
  return 0;
}


