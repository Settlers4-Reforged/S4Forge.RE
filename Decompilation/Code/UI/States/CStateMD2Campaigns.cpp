#include "CStateMD2Campaigns.h"

// Definitions for class CStateMD2Campaigns

// address=[0x14c4610]
// Decompiled from CStateMD2Campaigns *__cdecl CStateMD2Campaigns::DynamicCreateFunc(void *a1)

static class CGameState * __cdecl CStateMD2Campaigns::DynamicCreateFunc(void *) {
  
  CStateMD2Campaigns *C; // [esp+Ch] [ebp-10h]

  C = (CStateMD2Campaigns *)operator new(4u);
  if ( C )
    return CStateMD2Campaigns::CStateMD2Campaigns(C, a1);
  else
    return 0;
}


// address=[0x14c4690]
// Decompiled from CStateMD2Campaigns *__thiscall CStateMD2Campaigns::CStateMD2Campaigns(CStateMD2Campaigns *this, void *a2)

 CStateMD2Campaigns::CStateMD2Campaigns(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateMD2Campaigns::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pMissionCD2, 0, (int)GuiDlgMD2CampaignsProc);
  g_cCampaignSettings = 24;
  dword_402CBBC[17] = CGameSettings::GetCampaignStatus(17);
  dword_402CBBC[19] = CGameSettings::GetCampaignStatus(19);
  dword_402CBBC[18] = CGameSettings::GetCampaignStatus(18);
  dword_402CBBC[20] = CGameSettings::GetCampaignStatus(20);
  dword_402CBBC[17] = 5;
  dword_402CBBC[19] = 5;
  dword_402CBBC[18] = 5;
  dword_402CBBC[20] = 5;
  CGuiGameState::OpenDialog(this, 0, GuiDlgMD2CampaignsProc);
  return this;
}


// address=[0x14c47d0]
// Decompiled from void __thiscall CStateMD2Campaigns::~CStateMD2Campaigns(CStateMD2Campaigns *this)

 CStateMD2Campaigns::~CStateMD2Campaigns(void) {
  
  *(_DWORD *)this = &CStateMD2Campaigns::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14c4830]
// Decompiled from char __thiscall CStateMD2Campaigns::Perform(CStateMD2Campaigns *this)

bool  CStateMD2Campaigns::Perform(void) {
  
  DWORD v2; // esi
  int Instance; // [esp+8h] [ebp-4h]

  Instance = UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
    if ( !g_pMissionCD2 && BBSupportDbgReport(2, "main\\states\\StateMD2Campaigns.cpp", 182, "g_pMissionCD2") == 1 )
      __debugbreak();
    (*(void (__thiscall **)(int, _DWORD, char (__cdecl *)(int, int, int)))(*(_DWORD *)g_pMissionCD2 + 12))(
      g_pMissionCD2,
      0,
      GuiDlgMainscreenProc);
    CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
    return 1;
  }
  else
  {
    if ( dword_4031E38 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_4031E38);
      if ( dword_4031E38 == -1 )
      {
        dword_4031E34 = timeGetTime();
        j___Init_thread_footer(&dword_4031E38);
      }
    }
    v2 = dword_4031E34 + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_4031E34 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14c4960]
// Decompiled from char __thiscall CStateMD2Campaigns::OnEvent(CStateMD2Campaigns *this, struct CEvn_Event *a2)

bool  CStateMD2Campaigns::OnEvent(class CEvn_Event &) {
  
  char result; // al
  CEvn_Event *v3; // [esp+18h] [ebp-38h]
  unsigned int event; // [esp+24h] [ebp-2Ch]
  CEvn_Event v5; // [esp+28h] [ebp-28h] BYREF
  int v6; // [esp+4Ch] [ebp-4h]

  event = a2->event;
  if ( event > 0x232A )
  {
    switch ( event )
    {
      case 0x232Bu:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateMD2Briefing::DynamicCreateFunc, (a2->wparam << 16) | 0x12);
        result = 1;
        break;
      case 0x232Cu:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateMD2Briefing::DynamicCreateFunc, (a2->wparam << 16) | 0x13);
        result = 1;
        break;
      case 0x232Du:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateMD2Briefing::DynamicCreateFunc, (a2->wparam << 16) | 0x14);
        result = 1;
        break;
      case 0x232Fu:
        IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
        if ( !g_pMissionCD2
          && BBSupportDbgReport(2, "main\\states\\StateMD2Campaigns.cpp", 114, (const char *)&dword_3750EB0[1]) == 1 )
        {
          __debugbreak();
        }
        (*(void (__thiscall **)(int, _DWORD, char (__cdecl *)(int, int, int)))(*(_DWORD *)g_pMissionCD2 + 12))(
          g_pMissionCD2,
          0,
          GuiDlgMainscreenProc);
        CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
        result = 1;
        break;
      default:
        return CGuiGameState::OnEvent(this, a2);
    }
  }
  else if ( event == 9002 )
  {
    if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
      CGameSettings::SetAIDifficulty(dword_4031CFC);
    CGameStateHandler::Switch((int)CStateMD2Briefing::DynamicCreateFunc, (a2->wparam << 16) | 0x11);
    return 1;
  }
  else if ( event == 11 && (unsigned __int16)a2->wparam == 27 )
  {
    v3 = CEvn_Event::CEvn_Event(&v5, 0x232Fu, 0, 0, 0);
    v6 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v3);
    v6 = -1;
    CEvn_Event::~CEvn_Event(&v5);
    return 1;
  }
  else
  {
    return CGuiGameState::OnEvent(this, a2);
  }
  return result;
}


// address=[0x14c4db0]
// Decompiled from // Microsoft VisualC 14/net runtime
char __thiscall CStateMD2Campaigns::CanProcessInvites(CStateMD2Campaigns *this)

bool  CStateMD2Campaigns::CanProcessInvites(void) {
  
  return 0;
}


