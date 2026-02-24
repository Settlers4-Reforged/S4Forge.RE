#include "CStateMD2Briefing.h"

// Definitions for class CStateMD2Briefing

// address=[0x14c30d0]
// Decompiled from CStateMD2Briefing *__cdecl CStateMD2Briefing::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateMD2Briefing::DynamicCreateFunc(void * a1) {
  
  CStateMD2Briefing *C; // [esp+Ch] [ebp-10h]

  C = (CStateMD2Briefing *)operator new(0x10u);
  if ( C )
    return CStateMD2Briefing::CStateMD2Briefing(C, a1);
  else
    return 0;
}


// address=[0x14c3150]
// Decompiled from CStateMD2Briefing *__thiscall CStateMD2Briefing::CStateMD2Briefing(CStateMD2Briefing *this, void *a2)
 CStateMD2Briefing::CStateMD2Briefing(void * a2) {
  
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
      delete (CGameType *)g_pGameType;
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
bool  CStateMD2Briefing::OnEvent(class CEvn_Event & a2) {
  
  char result; // al
  CGUIWrapper *Instance; // eax
  const char *v4; // eax
  char *v5; // eax
  OnlineManager *v6; // eax
  int v7[7]; // [esp-40h] [ebp-320h] BYREF
  BOOL v8; // [esp-24h] [ebp-304h]
  int v9; // [esp-20h] [ebp-300h]
  int v10; // [esp-1Ch] [ebp-2FCh]
  int v11; // [esp-18h] [ebp-2F8h]
  int v12; // [esp-14h] [ebp-2F4h]
  int v13; // [esp-10h] [ebp-2F0h]
  int v14; // [esp-Ch] [ebp-2ECh]
  int v15; // [esp-8h] [ebp-2E8h]
  int v16; // [esp-4h] [ebp-2E4h]
  void *v17; // [esp+4h] [ebp-2DCh]
  int *v18; // [esp+8h] [ebp-2D8h]
  int v19; // [esp+Ch] [ebp-2D4h]
  int m_wParam; // [esp+10h] [ebp-2D0h]
  CEvn_Event *v21; // [esp+14h] [ebp-2CCh]
  int v22; // [esp+20h] [ebp-2C0h]
  int PlayerName; // [esp+24h] [ebp-2BCh]
  INetworkEngine *v24; // [esp+28h] [ebp-2B8h]
  int v25; // [esp+2Ch] [ebp-2B4h]
  int v26; // [esp+30h] [ebp-2B0h]
  void *v27; // [esp+34h] [ebp-2ACh]
  int v28; // [esp+38h] [ebp-2A8h]
  CGameType *v29; // [esp+3Ch] [ebp-2A4h]
  void *v30; // [esp+40h] [ebp-2A0h]
  int v31; // [esp+44h] [ebp-29Ch]
  INetworkEngine *v32; // [esp+48h] [ebp-298h]
  void *v33; // [esp+4Ch] [ebp-294h]
  int v34; // [esp+50h] [ebp-290h]
  CGameType *v35; // [esp+54h] [ebp-28Ch]
  void *C; // [esp+58h] [ebp-288h]
  int v37; // [esp+5Ch] [ebp-284h]
  int (__thiscall ***v38)(_DWORD, int); // [esp+60h] [ebp-280h]
  char v39; // [esp+67h] [ebp-279h]
  int i; // [esp+68h] [ebp-278h]
  unsigned int m_iEventId; // [esp+70h] [ebp-270h]
  char v42; // [esp+75h] [ebp-26Bh]
  char v43; // [esp+76h] [ebp-26Ah]
  char MapData; // [esp+77h] [ebp-269h]
  CGuiGameState *v45; // [esp+78h] [ebp-268h]
  char v46; // [esp+7Eh] [ebp-262h]
  char v47; // [esp+7Fh] [ebp-261h]
  _BYTE v48[28]; // [esp+80h] [ebp-260h] BYREF
  CEvn_Event v49; // [esp+9Ch] [ebp-244h] BYREF
  char v50[28]; // [esp+B4h] [ebp-22Ch] BYREF
  char Buffer[512]; // [esp+D0h] [ebp-210h] BYREF
  int v52; // [esp+2DCh] [ebp-4h]

  v45 = this;
  m_iEventId = a2->m_iEventId;
  if ( m_iEventId <= 0x78 )
  {
    switch ( m_iEventId )
    {
      case 0x78u:
        *((_BYTE *)v45 + 12) = 0;
        return 1;
      case 0xBu:
        if ( (unsigned __int16)a2->m_wParam == 27 )
        {
          v21 = CEvn_Event::CEvn_Event(&v49, 0x2330u, 0, 0, 0);
          v52 = 0;
          IEventEngine::SendAMessage(g_pEvnEngine, v21);
          v52 = -1;
          CEvn_Event::~CEvn_Event(&v49);
          return 1;
        }
        break;
      case 0x72u:
        v39 = IGuiEngine::CloseDialog(g_pGUIEngine, 20);
        CGuiGameState::SetupExtraGui(g_pMissionCD2, 1, (int)GuiDlgMD2BriefingProc);
        CGuiGameState::OpenDialog(v45, 1, (bool (__cdecl *)(int, int, int))GuiDlgMD2BriefingProc);
        return 1;
    }
    return CGuiGameState::OnEvent(v45, a2);
  }
  if ( m_iEventId == 9008 )
  {
    CSoundManager::StopMusic((CSoundManager *)g_pSoundManager);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    if ( !byte_402C9F4
      && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 291, "g_cBriefingSettings.m_bIsCampaign") == 1 )
    {
      __debugbreak();
    }
    if ( g_pGameType )
    {
      v31 = g_pGameType;
      v37 = g_pGameType;
      v30 = delete (CGameType *)g_pGameType;
      g_pGameType = 0;
    }
    m_wParam = a2->m_wParam;
    switch ( *((_DWORD *)v45 + 1) )
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
    if ( m_iEventId != 9009 )
      return CGuiGameState::OnEvent(v45, a2);
    Instance = (CGUIWrapper *)CGUIWrapper::GetInstance();
    CGUIWrapper::ReleaseGUIGFXFile(Instance);
    CSoundManager::StopSounds((CSoundManager *)g_pSoundManager);
    IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 4u);
    CGfxManager::DisableGfxFile(g_pGfxManager, 1);
    if ( (unsigned __int8)CStateLobbyGameSettings::CopyDefaultUserFlags() )
    {
      CGfxManager::EnableGfxFile(g_pGfxManager, 1u, 8, 1, 0xFFFFFFFF);
      C = operator new(0x620u);
      v52 = 1;
      if ( C )
        v35 = CGameType::CGameType((CGameType *)C);
      else
        v35 = 0;
      v29 = v35;
      v52 = -1;
      g_pGameType = (int)v35;
      v46 = 0;
      v19 = 256;
      v16 = *((_DWORD *)v45 + 2) + 1;
      v4 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)((char *)&stru_4031D98
                                                                   + 28 * *((_DWORD *)v45 + 1)
                                                                   - 476));
      snwprintf(Buffer, 0xFFu, v4, v16);
      std::wstring::wstring(v50);
      v52 = 2;
      if ( g_pCDDrive->GetCDPath(g_pCDDrive, v50, Buffer, 0x300040) )
      {
        v16 = 0;
        v15 = 0;
        v14 = *((_DWORD *)v45 + 1);
        v13 = dword_4031CFC;
        v12 = 0;
        v11 = 1;
        v10 = 0;
        v9 = 0;
        v8 = 1;
        v18 = v7;
        v17 = std::wstring::wstring(v7, v50);
        MapData = CGameType::LoadMapData(
                    (CGameType *)g_pGameType,
                    v7[0],
                    v7[1],
                    v7[2],
                    v7[3],
                    v7[4],
                    v7[5],
                    v7[6],
                    v8,
                    v9,
                    v10,
                    v11,
                    v12,
                    v13,
                    v14,
                    v15,
                    v16);
        v46 = MapData;
      }
      if ( v46 )
      {
        if ( !CGameType::IsCampaignMap((CGameType *)g_pGameType)
          && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 432, "g_pGameType->IsCampaignMap()") == 1 )
        {
          __debugbreak();
        }
        IGuiEngine::EnableEventInput(g_pGUIEngine, 0);
        if ( g_pNetworkEngine )
        {
          v26 = g_pNetworkEngine;
          v38 = (int (__thiscall ***)(_DWORD, int))g_pNetworkEngine;
          v25 = (**v38)(v38, 1);
          g_pNetworkEngine = 0;
        }
        v33 = operator new(0x18u);
        LOBYTE(v52) = 3;
        if ( v33 )
          v32 = INetworkEngine::INetworkEngine((INetworkEngine *)v33, 0);
        else
          v32 = 0;
        v24 = v32;
        LOBYTE(v52) = 2;
        g_pNetworkEngine = (int)v32;
        *(_DWORD *)(g_pGameType + 112) = *(_DWORD *)(g_pGameType + 852);
        *(_DWORD *)(g_pGameType + 188) = INetworkEngine::GetLocalIP((CGameHost **)g_pNetworkEngine);
        v6 = (OnlineManager *)OnlineManager::GetInstance();
        *(_DWORD *)(g_pGameType + 224) = OnlineManager::GetLocalPeerId(v6);
        PlayerName = CGameSettings::GetPlayerName((int)v48);
        v22 = PlayerName;
        LOBYTE(v52) = 4;
        CGameType::SetPlayerName(0, PlayerName);
        LOBYTE(v52) = 2;
        std::wstring::~wstring(v48);
        *(_DWORD *)(g_pGameType + 740) = *((_DWORD *)v45 + 1);
        *(_DWORD *)(g_pGameType + 744) = *((_DWORD *)v45 + 2);
        *(_DWORD *)(g_pGameType + 692) = 3;
        for ( i = 0; i < *(_DWORD *)(g_pGameType + 852); ++i )
          *(_BYTE *)(i + g_pGameType + 440) = 0;
        INetworkEngine::Start(1, 1, *(_DWORD *)(g_pGameType + 852), 0);
        CGameStateHandler::Switch((int)CStateGame::DynamicCreateFunc, 0);
        v42 = 1;
        v52 = -1;
        std::wstring::~wstring(v50);
        return v42;
      }
      else
      {
        v5 = g_pStringEngine->GetString(g_pStringEngine, 2731);
        std::string::operator=(&g_iMessageBoxStringID, v5);
        v47 = IGuiEngine::CloseDialog(g_pGUIEngine, 1);
        if ( !g_pMissionCD2 && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 416, "g_pMissionCD2") == 1 )
          __debugbreak();
        (*(void (__thiscall **)(int, _DWORD, char (__cdecl *)(int, int, int)))(*(_DWORD *)g_pMissionCD2 + 12))(
          g_pMissionCD2,
          0,
          GuiDlgMainscreenProc);
        v47 = IGuiEngine::OpenDialog(g_pGUIEngine, 20, (bool (__cdecl *)(int, int, int))GuiDlgMainMessageBoxProc);
        if ( !v47 && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 419, "bRet") == 1 )
          __debugbreak();
        BBSupportTracePrintF(3, "MissionCD2 Map '%s' not found!", Buffer);
        IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 0);
        if ( g_pGameType )
        {
          v28 = g_pGameType;
          v34 = g_pGameType;
          v27 = delete (CGameType *)g_pGameType;
          g_pGameType = 0;
        }
        v43 = 1;
        v52 = -1;
        std::wstring::~wstring(v50);
        return v43;
      }
    }
    else
    {
      IGuiEngine::CloseDialog(g_pGUIEngine, 1);
      if ( !g_pMissionCD2 && BBSupportDbgReport(2, "main\\states\\StateMD2Briefing.cpp", 381, "g_pMissionCD2") == 1 )
        __debugbreak();
      (*(void (__thiscall **)(int, int, char (__cdecl *)(int, unsigned int, int)))(*(_DWORD *)g_pMissionCD2 + 12))(
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
void __cdecl CStateMD2Briefing::InitBriefingTexts(int a1, int a2) {
  
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
      std::string::operator=(&stru_402C9B4, v2);
      v3 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A324[a2]);
      std::string::operator=(&unk_402C998, v3);
      v4 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A338[a2]);
      std::string::operator=(&stru_402C9D0, v4);
      v5 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A34C[a2]);
      result = std::string::operator=(&unk_402C97C, v5);
      break;
    case 18:
      v7 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A360[a2]);
      std::string::operator=(&stru_402C9B4, v7);
      v8 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A374[a2]);
      std::string::operator=(&unk_402C998, v8);
      v9 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A388[a2]);
      std::string::operator=(&stru_402C9D0, v9);
      v10 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A39C[a2]);
      result = std::string::operator=(&unk_402C97C, v10);
      break;
    case 19:
      v11 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A3B0[a2]);
      std::string::operator=(&stru_402C9B4, v11);
      v12 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A3C4[a2]);
      std::string::operator=(&unk_402C998, v12);
      v13 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A3D8[a2]);
      std::string::operator=(&stru_402C9D0, v13);
      v14 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A3EC[a2]);
      result = std::string::operator=(&unk_402C97C, v14);
      break;
    case 20:
      v15 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A400[a2]);
      std::string::operator=(&stru_402C9B4, v15);
      v16 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A414[a2]);
      std::string::operator=(&unk_402C998, v16);
      v17 = g_pStringEngine->GetString(g_pStringEngine, dword_3D8A428[a2]);
      std::string::operator=(&stru_402C9D0, v17);
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


