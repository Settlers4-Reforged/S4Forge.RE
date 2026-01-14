#include "all_headers.h"

// Definitions for class CStateMDCampaigns

// address=[0x14c6f90]
// Decompiled from CStateMDCampaigns *__cdecl CStateMDCampaigns::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateMDCampaigns::DynamicCreateFunc(void *) {
  
  CStateMDCampaigns *C; // [esp+Ch] [ebp-10h]

  C = (CStateMDCampaigns *)operator new(4u);
  if ( C )
    return CStateMDCampaigns::CStateMDCampaigns(C, a1);
  else
    return 0;
}


// address=[0x14c7010]
// Decompiled from CStateMDCampaigns *__thiscall CStateMDCampaigns::CStateMDCampaigns(CStateMDCampaigns *this, void *a2)
 CStateMDCampaigns::CStateMDCampaigns(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateMDCampaigns::_vftable_;
  dword_402CBBC[10] = CGameSettings::GetCampaignStatus(10);
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pMissionCD, 0, (int)GuiDlgMDCampaignsProc);
  CGuiGameState::OpenDialog(this, 0, GuiDlgMDCampaignsProc);
  return this;
}


// address=[0x14c70b0]
// Decompiled from void __thiscall CStateMDCampaigns::~CStateMDCampaigns(CStateMDCampaigns *this)
 CStateMDCampaigns::~CStateMDCampaigns(void) {
  
  *(_DWORD *)this = &CStateMDCampaigns::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14c7110]
// Decompiled from char __thiscall CStateMDCampaigns::Perform(CStateMDCampaigns *this)
bool  CStateMDCampaigns::Perform(void) {
  
  DWORD v2; // esi
  int Instance; // [esp+8h] [ebp-4h]

  Instance = UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) )
  {
    if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
      CGameSettings::SetAIDifficulty(dword_4031CFC);
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
    if ( !g_pMissionCD && BBSupportDbgReport(2, "main\\States\\StateMDCampaigns.cpp", 176, "g_pMissionCD") == 1 )
      __debugbreak();
    (*(void (__thiscall **)(int, _DWORD, char (__cdecl *)(int, int, int)))(*(_DWORD *)g_pMissionCD + 12))(
      g_pMissionCD,
      0,
      GuiDlgMainscreenProc);
    CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
    return 1;
  }
  else
  {
    if ( dword_4031F68 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_4031F68);
      if ( dword_4031F68 == -1 )
      {
        dword_4031F64 = timeGetTime();
        j___Init_thread_footer(&dword_4031F68);
      }
    }
    v2 = dword_4031F64 + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_4031F64 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14c7260]
// Decompiled from char __thiscall CStateMDCampaigns::OnEvent(CStateMDCampaigns *this, struct CEvn_Event *a2)
bool  CStateMDCampaigns::OnEvent(class CEvn_Event &) {
  
  char result; // al
  CEvn_Event *v3; // [esp+8h] [ebp-38h]
  unsigned int event; // [esp+14h] [ebp-2Ch]
  CEvn_Event v5; // [esp+18h] [ebp-28h] BYREF
  int v6; // [esp+3Ch] [ebp-4h]

  event = a2->event;
  if ( event > 0x1B5A )
  {
    switch ( event )
    {
      case 0x1B5Bu:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateMDCampaignRoman::DynamicCreateFunc, 0);
        result = 1;
        break;
      case 0x1B5Cu:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateMDCampaignMayan::DynamicCreateFunc, 0);
        result = 1;
        break;
      case 0x1B5Du:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateMDCampaignViking::DynamicCreateFunc, 0);
        result = 1;
        break;
      case 0x1B5Eu:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateMDBriefing::DynamicCreateFunc, 10);
        result = 1;
        break;
      case 0x1B5Fu:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateMDCampaignsEcoConflict::DynamicCreateFunc, 0);
        result = 1;
        break;
      default:
        return CGuiGameState::OnEvent(this, a2);
    }
  }
  else if ( event == 7002 )
  {
    if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
      CGameSettings::SetAIDifficulty(dword_4031CFC);
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
    if ( !g_pMissionCD
      && BBSupportDbgReport(2, "main\\States\\StateMDCampaigns.cpp", 107, (const char *)&dword_37534F8[1]) == 1 )
    {
      __debugbreak();
    }
    (*(void (__thiscall **)(int, _DWORD, char (__cdecl *)(int, int, int)))(*(_DWORD *)g_pMissionCD + 12))(
      g_pMissionCD,
      0,
      GuiDlgMainscreenProc);
    CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
    return 1;
  }
  else if ( event == 11 && (unsigned __int16)a2->wparam == 27 )
  {
    v3 = CEvn_Event::CEvn_Event(&v5, 0x1B5Au, 0, 0, 0);
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


// address=[0x14c76a0]
// Decompiled from char __thiscall CStateMDCampaigns::CanProcessInvites(CStateMDCampaigns *this)
bool  CStateMDCampaigns::CanProcessInvites(void) {
  
  return 0;
}


