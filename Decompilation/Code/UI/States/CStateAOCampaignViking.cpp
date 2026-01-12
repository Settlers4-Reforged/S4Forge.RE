#include "CStateAOCampaignViking.h"

// Definitions for class CStateAOCampaignViking

// address=[0x14a14b0]
// Decompiled from CStateAOCampaignViking *__cdecl CStateAOCampaignViking::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateAOCampaignViking::DynamicCreateFunc(void *) {
  
  CStateAOCampaignViking *C; // [esp+Ch] [ebp-10h]

  C = (CStateAOCampaignViking *)operator new(4u);
  if ( C )
    return CStateAOCampaignViking::CStateAOCampaignViking(C, a1);
  else
    return 0;
}


// address=[0x14a1530]
// Decompiled from CStateAOCampaignViking *__thiscall CStateAOCampaignViking::CStateAOCampaignViking(  CStateAOCampaignViking *this,  void *a2)
 CStateAOCampaignViking::CStateAOCampaignViking(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateAOCampaignViking::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pAddOn, 2, (int)GuiDlgAOCampaignVikingProc);
  g_cCampaignSettings = 20;
  dword_402CBBC[12] = CGameSettings::GetCampaignStatus(12);
  dword_402CBBC[12] = 5;
  CGuiGameState::OpenDialog(this, 2, GuiDlgAOCampaignVikingProc);
  return this;
}


// address=[0x14a15f0]
// Decompiled from void __thiscall CStateAOCampaignViking::~CStateAOCampaignViking(CStateAOCampaignViking *this)
 CStateAOCampaignViking::~CStateAOCampaignViking(void) {
  
  *(_DWORD *)this = &CStateAOCampaignViking::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 2);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a1650]
// Decompiled from char __thiscall CStateAOCampaignViking::Perform(CStateAOCampaignViking *this)
bool  CStateAOCampaignViking::Perform(void) {
  
  DWORD v2; // esi
  int Instance; // [esp+8h] [ebp-4h]

  Instance = UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) )
  {
    CGameStateHandler::Switch((int)CStateAOCampaigns::DynamicCreateFunc, 1);
    return 1;
  }
  else
  {
    if ( dword_402C92C > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_402C92C);
      if ( dword_402C92C == -1 )
      {
        dword_402C928 = timeGetTime();
        j___Init_thread_footer(&dword_402C92C);
      }
    }
    v2 = dword_402C928 + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_402C928 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14a1730]
// Decompiled from char __thiscall CStateAOCampaignViking::OnEvent(CStateAOCampaignViking *this, struct CEvn_Event *a2)
bool  CStateAOCampaignViking::OnEvent(class CEvn_Event &) {
  
  CEvn_Event *v3; // [esp+Ch] [ebp-38h]
  int event; // [esp+18h] [ebp-2Ch]
  CEvn_Event v5; // [esp+1Ch] [ebp-28h] BYREF
  int v6; // [esp+40h] [ebp-4h]

  event = a2->event;
  switch ( event )
  {
    case 11:
      if ( (unsigned __int16)a2->wparam == 27 )
      {
        v3 = CEvn_Event::CEvn_Event(&v5, 0x1F4Eu, 0, 0, 0);
        v6 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v3);
        v6 = -1;
        CEvn_Event::~CEvn_Event(&v5);
        return 1;
      }
      break;
    case 8013:
      CGameStateHandler::Switch((int)CStateAOBriefing::DynamicCreateFunc, (a2->wparam << 16) | 0xC);
      return 1;
    case 8014:
      CGameStateHandler::Switch((int)CStateAOCampaigns::DynamicCreateFunc, 1);
      return 1;
  }
  return CGuiGameState::OnEvent(this, a2);
}


// address=[0x14a1970]
// Decompiled from char __thiscall CStateAOCampaignViking::CanProcessInvites(CStateAOCampaignViking *this)
bool  CStateAOCampaignViking::CanProcessInvites(void) {
  
  return 0;
}


