#include "all_headers.h"

// Definitions for class CStateAOBriefing

// address=[0x149d9d0]
// Decompiled from CStateAOBriefing *__cdecl CStateAOBriefing::DynamicCreateFunc(int a1)
static class CGameState * __cdecl CStateAOBriefing::DynamicCreateFunc(void *) {
  
  CStateAOBriefing *C; // [esp+Ch] [ebp-10h]

  C = (CStateAOBriefing *)operator new(0x10u);
  if ( C )
    return CStateAOBriefing::CStateAOBriefing(C, a1);
  else
    return 0;
}


// address=[0x149da50]
// Decompiled from CStateAOBriefing *__thiscall CStateAOBriefing::CStateAOBriefing(CStateAOBriefing *this, int a2)
 CStateAOBriefing::CStateAOBriefing(void *) {
  
  const char *v2; // eax
  char *v3; // eax
  const wchar_t *v4; // eax
  const char *v5; // eax
  int v7; // [esp-4h] [ebp-248h]
  const wchar_t *v8; // [esp+Ch] [ebp-238h]
  char v10[28]; // [esp+18h] [ebp-22Ch] BYREF
  char Buffer[512]; // [esp+34h] [ebp-210h] BYREF
  int v12; // [esp+240h] [ebp-4h]

  CGuiGameState::CGuiGameState(this);
  v12 = 0;
  *(_DWORD *)this = &CStateAOBriefing::_vftable_;
  CSoundManager::StopMusic(g_pSoundManager);
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pAddOn, 7, (int)GuiDlgAOBriefingProc);
  *((_DWORD *)this + 1) = (unsigned __int16)a2;
  *((_DWORD *)this + 2) = HIWORD(a2);
  *((_BYTE *)this + 12) = 0;
  if ( *((int *)this + 1) >= 25
    && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 281, "m_iCampaignType < CAMPAIGN_MAX") == 1 )
  {
    __debugbreak();
  }
  switch ( *((_DWORD *)this + 1) )
  {
    case 0xB:
    case 0xC:
    case 0xD:
      if ( *((int *)this + 2) >= 4
        && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 294, "m_iLevel < AO_CAMPAIGN_RMV_COUNT") == 1 )
      {
        __debugbreak();
      }
      byte_402C9F4 = 1;
      break;
    case 0xE:
      if ( *((int *)this + 2) >= 4
        && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 306, "m_iLevel < AO_CAMPAIGN_SETTLE_COUNT") == 1 )
      {
        __debugbreak();
      }
      byte_402C9F4 = 1;
      break;
    case 0xF:
      if ( *((int *)this + 2) >= 12
        && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 300, "m_iLevel < AO_CAMPAIGN_TROJAN_COUNT") == 1 )
      {
        __debugbreak();
      }
      byte_402C9F4 = 1;
      break;
    case 0x10:
      if ( *((int *)this + 2) >= 1
        && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 286, "m_iLevel < AO_BONUS_COUNT") == 1 )
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
    CStateAOBriefing::InitBriefingTexts(*((_DWORD *)this + 1), *((_DWORD *)this + 2));
  }
  else
  {
    std::string::operator=(g_pGameType + 884);
    std::string::operator=(g_pGameType + 912);
    std::string::operator=(g_pGameType + 940);
    std::string::operator=(g_pGameType + 968);
  }
  CGuiGameState::SetupGui(
    this,
    L"Menu\\GUISetStartscreens.dat",
    10,
    (bool (__cdecl *)(int, int, int))GuiDlgAOBriefingProc,
    7);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  if ( !*((_DWORD *)this + 1) )
    return this;
  if ( CGameSettings::GetLanguage() == 1 )
    v8 = (const wchar_t *)&unk_373AE8C;
  else
    v8 = L"EN";
  v7 = *((_DWORD *)this + 2) + 1;
  v2 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)((char *)&unk_402C7F8 + 28 * *((_DWORD *)this + 1) - 308));
  j___snwprintf(Buffer, 0xFFu, v2, v8, v7);
  std::wstring::wstring(v10);
  LOBYTE(v12) = 1;
  if ( (*(unsigned __int8 (__thiscall **)(void *, char *, char *, int))(*(_DWORD *)g_pCDDrive + 8))(
         g_pCDDrive,
         v10,
         Buffer,
         3145744) )
  {
    v4 = (const wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v10);
    if ( !CSoundManager::PlaySoundFile((CSoundManager *)g_pSoundManager, v4, 100, 64) )
    {
      v5 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v10);
      BBSupportTracePrintF(0, "Unable to play briefing file %s", v5);
    }
    LOBYTE(v12) = 0;
    std::wstring::~wstring(v10);
  }
  else
  {
    v3 = g_pStringEngine->GetString(g_pStringEngine, 388);
    std::string::operator=(&g_iMessageBoxStringID, v3);
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 10);
    IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgMainMessageBoxProc);
    LOBYTE(v12) = 0;
    std::wstring::~wstring(v10);
  }
  return this;
}


// address=[0x149dea0]
// Decompiled from void __thiscall CStateAOBriefing::~CStateAOBriefing(CStateAOBriefing *this)
 CStateAOBriefing::~CStateAOBriefing(void) {
  
  *(_DWORD *)this = &CStateAOBriefing::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 7);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x149df00]
// Decompiled from char __thiscall CStateAOBriefing::Perform(CStateAOBriefing *this)
bool  CStateAOBriefing::Perform(void) {
  
  DWORD v2; // esi
  int Instance; // [esp+14h] [ebp-8h]

  Instance = UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) )
  {
    CSoundManager::StopMusic(g_pSoundManager);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    if ( !byte_402C9F4
      && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 643, "g_cBriefingSettings.m_bIsCampaign") == 1 )
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
      case 0xB:
        CGameStateHandler::Switch((int)CStateAOCampaignRoman::DynamicCreateFunc, 0);
        break;
      case 0xC:
        CGameStateHandler::Switch((int)CStateAOCampaignViking::DynamicCreateFunc, 0);
        break;
      case 0xD:
        CGameStateHandler::Switch((int)CStateAOCampaignMayan::DynamicCreateFunc, 0);
        break;
      case 0xE:
        CGameStateHandler::Switch((int)CStateAOCampaignsSettle::DynamicCreateFunc, 0);
        break;
      case 0xF:
        CGameStateHandler::Switch((int)CStateAOCampaignTrojan::DynamicCreateFunc, 0);
        break;
      case 0x10:
        CGameStateHandler::Switch((int)CStateAOCampaigns::DynamicCreateFunc, 0);
        break;
      default:
        return 1;
    }
    return 1;
  }
  else
  {
    if ( dword_402C8F4 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_402C8F4);
      if ( dword_402C8F4 == -1 )
      {
        dword_402C8F0 = timeGetTime();
        j___Init_thread_footer(&dword_402C8F4);
      }
    }
    v2 = dword_402C8F0 + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_402C8F0 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x149e0f0]
// Decompiled from bool __thiscall CStateAOBriefing::OnEvent(CStateAOBriefing *this, struct CEvn_Event *a2)
bool  CStateAOBriefing::OnEvent(class CEvn_Event &) {
  
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
  unsigned int v47; // [esp+6Ch] [ebp-270h]
  char v48; // [esp+71h] [ebp-26Bh]
  char v49; // [esp+72h] [ebp-26Ah]
  char MapData; // [esp+73h] [ebp-269h]
  CGuiGameState *v51; // [esp+74h] [ebp-268h]
  char v52; // [esp+7Ah] [ebp-262h]
  char v53; // [esp+7Bh] [ebp-261h]
  _BYTE v54[28]; // [esp+7Ch] [ebp-260h] BYREF
  _DWORD v55[6]; // [esp+98h] [ebp-244h] BYREF
  char v56[28]; // [esp+B0h] [ebp-22Ch] BYREF
  char Buffer[512]; // [esp+CCh] [ebp-210h] BYREF
  int v58; // [esp+2D8h] [ebp-4h]

  v51 = this;
  v47 = *((_DWORD *)a2 + 1);
  if ( v47 <= 0x78 )
  {
    switch ( v47 )
    {
      case 0x78u:
        *((_BYTE *)v51 + 12) = 0;
        return 1;
      case 0xBu:
        if ( (unsigned __int16)*((_DWORD *)a2 + 2) == 27 )
        {
          v37 = CEvn_Event::CEvn_Event((CEvn_Event *)v55, 0x1F55u, 0, 0, 0);
          v58 = 0;
          IEventEngine::SendAMessage(g_pEvnEngine, v37);
          v58 = -1;
          CEvn_Event::~CEvn_Event(v55);
          return 1;
        }
        break;
      case 0x72u:
        v45 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 20);
        CGuiGameState::SetupExtraGui(g_pAddOn, 7, (int)GuiDlgAOBriefingProc);
        CGuiGameState::SetupGui(
          v51,
          L"Menu\\GUISetStartscreens.dat",
          10,
          (bool (__cdecl *)(int, int, int))GuiDlgAOBriefingProc,
          7);
        return 1;
    }
    return CGuiGameState::OnEvent(v51, a2);
  }
  if ( v47 == 8021 )
  {
    CSoundManager::StopMusic(g_pSoundManager);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    if ( !byte_402C9F4
      && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 411, "g_cBriefingSettings.m_bIsCampaign") == 1 )
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
      case 0xB:
        CGameStateHandler::Switch((int)CStateAOCampaignRoman::DynamicCreateFunc, 0);
        break;
      case 0xC:
        CGameStateHandler::Switch((int)CStateAOCampaignViking::DynamicCreateFunc, 0);
        break;
      case 0xD:
        CGameStateHandler::Switch((int)CStateAOCampaignMayan::DynamicCreateFunc, 0);
        break;
      case 0xE:
        CGameStateHandler::Switch((int)CStateAOCampaignsSettle::DynamicCreateFunc, 0);
        break;
      case 0xF:
        CGameStateHandler::Switch((int)CStateAOCampaignTrojan::DynamicCreateFunc, 0);
        break;
      case 0x10:
        CGameStateHandler::Switch((int)CStateAOCampaigns::DynamicCreateFunc, 0);
        break;
      default:
        return 1;
    }
    return 1;
  }
  else
  {
    if ( v47 != 8022 )
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
      v4 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)((char *)&unk_402C750
                                                                   + 28 * *((_DWORD *)v51 + 1)
                                                                   - 308));
      j___snwprintf(Buffer, 0xFFu, v4, v22);
      std::wstring::wstring(v56);
      v58 = 2;
      if ( (*(unsigned __int8 (__thiscall **)(void *, char *, char *, int))(*(_DWORD *)g_pCDDrive + 8))(
             g_pCDDrive,
             v56,
             Buffer,
             3145744) )
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
          && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 553, "g_pGameType->IsCampaignMap()") == 1 )
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
        *(_DWORD *)(g_pGameType + 188) = INetworkEngine::GetLocalIP((INetworkEngine *)g_pNetworkEngine);
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
        v5 = g_pStringEngine->GetString(g_pStringEngine, 388);
        std::string::operator=(&g_iMessageBoxStringID, v5);
        v53 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 7);
        if ( !g_pAddOn && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 537, "g_pAddOn") == 1 )
          __debugbreak();
        (*(void (__thiscall **)(int, _DWORD, char (__cdecl *)(int, int, int)))(*(_DWORD *)g_pAddOn + 12))(
          g_pAddOn,
          0,
          GuiDlgMainscreenProc);
        v53 = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgMainMessageBoxProc);
        if ( !v53 && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 540, "bRet") == 1 )
          __debugbreak();
        BBSupportTracePrintF(3, "Add On Map '%s' not found!", Buffer);
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
      IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 7);
      if ( !g_pAddOn && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 502, "g_pAddOn") == 1 )
        __debugbreak();
      (*(void (__thiscall **)(int, int, bool (__cdecl *)(int, int, int)))(*(_DWORD *)g_pAddOn + 12))(
        g_pAddOn,
        20,
        GuiDlgMainMessageBoxProc);
      CGameStateHandler::Switch((int)CStateMessageBox::DynamicCreateFunc, 2398);
      return 1;
    }
  }
}


// address=[0x149e9b0]
// Decompiled from void *__cdecl CStateAOBriefing::InitBriefingTexts(int a1, int a2)
static void __cdecl CStateAOBriefing::InitBriefingTexts(int,int) {
  
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

  if ( (!a1 || a1 >= 25)
    && BBSupportDbgReport(
         2,
         "main\\states\\StateAOBriefing.cpp",
         706,
         "( _iCampaignType ) && ( _iCampaignType < CAMPAIGN_MAX )") == 1 )
  {
    __debugbreak();
  }
  switch ( a1 )
  {
    case 11:
    case 12:
    case 13:
      if ( a2 >= 4
        && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 719, "_iLevel < AO_CAMPAIGN_RMV_COUNT") == 1 )
      {
        __debugbreak();
      }
      byte_402C9F4 = 1;
      break;
    case 14:
      if ( a2 >= 4
        && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 731, "_iLevel < AO_CAMPAIGN_SETTLE_COUNT") == 1 )
      {
        __debugbreak();
      }
      byte_402C9F4 = 1;
      break;
    case 15:
      if ( a2 >= 12
        && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 725, "_iLevel < AO_CAMPAIGN_TROJAN_COUNT") == 1 )
      {
        __debugbreak();
      }
      byte_402C9F4 = 1;
      break;
    case 16:
      if ( a2 >= 1 && BBSupportDbgReport(2, "main\\states\\StateAOBriefing.cpp", 711, "_iLevel < AO_BONUS_COUNT") == 1 )
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
    case 11:
      v2 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89CD0[a2]);
      std::string::operator=(&unk_402C9B4, v2);
      v3 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89CE0[a2]);
      std::string::operator=(&unk_402C998, v3);
      v4 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89CF0[a2]);
      std::string::operator=(&unk_402C9D0, v4);
      v5 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89D00[a2]);
      result = std::string::operator=(&unk_402C97C, v5);
      break;
    case 12:
      v7 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89D10[a2]);
      std::string::operator=(&unk_402C9B4, v7);
      v8 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89D20[a2]);
      std::string::operator=(&unk_402C998, v8);
      v9 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89D30[a2]);
      std::string::operator=(&unk_402C9D0, v9);
      v10 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89D40[a2]);
      result = std::string::operator=(&unk_402C97C, v10);
      break;
    case 13:
      v11 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89D50[a2]);
      std::string::operator=(&unk_402C9B4, v11);
      v12 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89D60[a2]);
      std::string::operator=(&unk_402C998, v12);
      v13 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89D70[a2]);
      std::string::operator=(&unk_402C9D0, v13);
      v14 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89D80[a2]);
      result = std::string::operator=(&unk_402C97C, v14);
      break;
    case 14:
      v19 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89E50[a2]);
      std::string::operator=(&unk_402C9B4, v19);
      v20 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89E60[a2]);
      std::string::operator=(&unk_402C998, v20);
      v21 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89E70[a2]);
      std::string::operator=(&unk_402C9D0, v21);
      v22 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89E80[a2]);
      result = std::string::operator=(&unk_402C97C, v22);
      break;
    case 15:
      v15 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89D90[a2]);
      std::string::operator=(&unk_402C9B4, v15);
      v16 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89DC0[a2]);
      std::string::operator=(&unk_402C998, v16);
      v17 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89DF0[a2]);
      std::string::operator=(&unk_402C9D0, v17);
      v18 = g_pStringEngine->GetString(g_pStringEngine, dword_3D89E20[a2]);
      result = std::string::operator=(&unk_402C97C, v18);
      break;
    default:
      result = (void *)BBSupportDbgReportF(
                         2,
                         "main\\states\\StateAOBriefing.cpp",
                         793,
                         "Invalid CampaignType during CStateAOBriefing::InitBriefingTexts init!");
      if ( result == (void *)1 )
        __debugbreak();
      break;
  }
  return result;
}


// address=[0x149f4f0]
// Decompiled from char __thiscall CStateAOBriefing::CanProcessInvites(CStateAOBriefing *this)
bool  CStateAOBriefing::CanProcessInvites(void) {
  
  return 0;
}


