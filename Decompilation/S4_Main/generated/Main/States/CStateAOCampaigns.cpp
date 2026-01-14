#include "all_headers.h"

// Definitions for class CStateAOCampaigns

// address=[0x14a0390]
// Decompiled from CStateAOCampaigns *__cdecl CStateAOCampaigns::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateAOCampaigns::DynamicCreateFunc(void *) {
  
  CStateAOCampaigns *C; // [esp+Ch] [ebp-10h]

  C = (CStateAOCampaigns *)operator new(4u);
  if ( C )
    return CStateAOCampaigns::CStateAOCampaigns(C, a1);
  else
    return 0;
}


// address=[0x14a0410]
// Decompiled from CStateAOCampaigns *__thiscall CStateAOCampaigns::CStateAOCampaigns(CStateAOCampaigns *this, void *a2)
 CStateAOCampaigns::CStateAOCampaigns(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateAOCampaigns::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pAddOn, 0, (int)GuiDlgAOCampaignsProc);
  CGuiGameState::OpenDialog(this, 0, GuiDlgAOCampaignsProc);
  return this;
}


// address=[0x14a04a0]
// Decompiled from void __thiscall CStateAOCampaigns::~CStateAOCampaigns(CStateAOCampaigns *this)
 CStateAOCampaigns::~CStateAOCampaigns(void) {
  
  *(_DWORD *)this = &CStateAOCampaigns::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a0500]
// Decompiled from char __thiscall CStateAOCampaigns::Perform(CStateAOCampaigns *this)
bool  CStateAOCampaigns::Perform(void) {
  
  DWORD v2; // esi
  int Instance; // [esp+8h] [ebp-4h]

  Instance = UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) )
  {
    if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
      CGameSettings::SetAIDifficulty(dword_4031CFC);
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
    if ( !g_pAddOn && BBSupportDbgReport(2, "main\\states\\StateAOCampaigns.cpp", 190, "g_pAddOn") == 1 )
      __debugbreak();
    (*(void (__thiscall **)(int, _DWORD, char (__cdecl *)(int, int, int)))(*(_DWORD *)g_pAddOn + 12))(
      g_pAddOn,
      0,
      GuiDlgMainscreenProc);
    CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
    return 1;
  }
  else
  {
    if ( dword_402C914 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_402C914);
      if ( dword_402C914 == -1 )
      {
        dword_402C910 = timeGetTime();
        j___Init_thread_footer(&dword_402C914);
      }
    }
    v2 = dword_402C910 + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_402C910 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14a0650]
// Decompiled from char __thiscall CStateAOCampaigns::OnEvent(CStateAOCampaigns *this, struct CEvn_Event *a2)
bool  CStateAOCampaigns::OnEvent(class CEvn_Event &) {
  
  char result; // al
  CEvn_Event *v3; // [esp+8h] [ebp-38h]
  unsigned int event; // [esp+14h] [ebp-2Ch]
  CEvn_Event v5; // [esp+18h] [ebp-28h] BYREF
  int v6; // [esp+3Ch] [ebp-4h]

  event = a2->event;
  if ( event > 0x1F42 )
  {
    switch ( event )
    {
      case 0x1F43u:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateAOCampaignRoman::DynamicCreateFunc, 0);
        result = 1;
        break;
      case 0x1F44u:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateAOCampaignMayan::DynamicCreateFunc, 0);
        result = 1;
        break;
      case 0x1F45u:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateAOCampaignViking::DynamicCreateFunc, 0);
        result = 1;
        break;
      case 0x1F46u:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateAOCampaignTrojan::DynamicCreateFunc, 0);
        result = 1;
        break;
      case 0x1F51u:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateAOCampaignsSettle::DynamicCreateFunc, 0);
        result = 1;
        break;
      default:
        return CGuiGameState::OnEvent(this, a2);
    }
  }
  else if ( event == 8002 )
  {
    if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
      CGameSettings::SetAIDifficulty(dword_4031CFC);
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
    if ( !g_pAddOn && BBSupportDbgReport(2, "main\\states\\StateAOCampaigns.cpp", 109, "g_pAddOn") == 1 )
      __debugbreak();
    (*(void (__thiscall **)(int, _DWORD, char (__cdecl *)(int, int, int)))(*(_DWORD *)g_pAddOn + 12))(
      g_pAddOn,
      0,
      GuiDlgMainscreenProc);
    CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
    return 1;
  }
  else if ( event == 11 && (unsigned __int16)a2->wparam == 27 )
  {
    v3 = CEvn_Event::CEvn_Event(&v5, 0x1F42u, 0, 0, 0);
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


// address=[0x14a0aa0]
// Decompiled from char __thiscall CStateAOCampaigns::CanProcessInvites(CStateAOCampaigns *this)
bool  CStateAOCampaigns::CanProcessInvites(void) {
  
  return 0;
}


