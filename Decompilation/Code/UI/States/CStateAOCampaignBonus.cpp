#include "CStateAOCampaignBonus.h"

// Definitions for class CStateAOCampaignBonus

// address=[0x149f580]
// Decompiled from CStateAOCampaignBonus *__cdecl CStateAOCampaignBonus::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateAOCampaignBonus::DynamicCreateFunc(void *) {
  
  CStateAOCampaignBonus *C; // [esp+Ch] [ebp-10h]

  C = (CStateAOCampaignBonus *)operator new(4u);
  if ( C )
    return CStateAOCampaignBonus::CStateAOCampaignBonus(C, a1);
  else
    return 0;
}


// address=[0x149f600]
// Decompiled from CStateAOCampaignBonus *__thiscall CStateAOCampaignBonus::CStateAOCampaignBonus(CStateAOCampaignBonus *this, void *a2)
 CStateAOCampaignBonus::CStateAOCampaignBonus(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateAOCampaignBonus::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pAddOn, 6, (int)GuiDlgAOCampaignBonusProc);
  g_cCampaignSettings = 23;
  dword_402CBBC[16] = CGameSettings::GetCampaignStatus(16);
  dword_402CBBC[16] = 5;
  CGuiGameState::OpenDialog(this, 6, GuiDlgAOCampaignBonusProc);
  return this;
}


// address=[0x149f6c0]
// Decompiled from void __thiscall CStateAOCampaignBonus::~CStateAOCampaignBonus(CStateAOCampaignBonus *this)
 CStateAOCampaignBonus::~CStateAOCampaignBonus(void) {
  
  *(_DWORD *)this = &CStateAOCampaignBonus::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 6);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x149f720]
// Decompiled from char __thiscall CStateAOCampaignBonus::Perform(CStateAOCampaignBonus *this)
bool  CStateAOCampaignBonus::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_402C8FC > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_402C8FC);
    if ( dword_402C8FC == -1 )
    {
      dword_402C8F8 = timeGetTime();
      j___Init_thread_footer(&dword_402C8FC);
    }
  }
  v1 = dword_402C8F8 + 30;
  if ( v1 >= timeGetTime() )
    return 1;
  dword_402C8F8 = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x149f7c0]
// Decompiled from char __thiscall CStateAOCampaignBonus::OnEvent(CStateAOCampaignBonus *this, struct CEvn_Event *a2)
bool  CStateAOCampaignBonus::OnEvent(class CEvn_Event &) {
  
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
        v3 = CEvn_Event::CEvn_Event(&v5, 0x1F4Au, 0, 0, 0);
        v6 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v3);
        v6 = -1;
        CEvn_Event::~CEvn_Event(&v5);
        return 1;
      }
      break;
    case 8019:
      CGameStateHandler::Switch((int)CStateAOBriefing::DynamicCreateFunc, (a2->wparam << 16) | 0x10);
      return 1;
    case 8020:
      CGameStateHandler::Switch((int)CStateAOCampaigns::DynamicCreateFunc, 1);
      return 1;
  }
  return CGuiGameState::OnEvent(this, a2);
}


