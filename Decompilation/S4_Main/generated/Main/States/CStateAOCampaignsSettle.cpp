#include "all_headers.h"

// Definitions for class CStateAOCampaignsSettle

// address=[0x14a0af0]
// Decompiled from CStateAOCampaignsSettle *__cdecl CStateAOCampaignsSettle::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateAOCampaignsSettle::DynamicCreateFunc(void *) {
  
  CStateAOCampaignsSettle *C; // [esp+Ch] [ebp-10h]

  C = (CStateAOCampaignsSettle *)operator new(4u);
  if ( C )
    return CStateAOCampaignsSettle::CStateAOCampaignsSettle(C, a1);
  else
    return 0;
}


// address=[0x14a0b70]
// Decompiled from CStateAOCampaignsSettle *__thiscall CStateAOCampaignsSettle::CStateAOCampaignsSettle(  CStateAOCampaignsSettle *this,  void *a2)
 CStateAOCampaignsSettle::CStateAOCampaignsSettle(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateAOCampaignsSettle::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pAddOn, 4, (int)GuiDlgAOCampaignsSettleProc);
  g_cCampaignSettings = 22;
  dword_402CBBC[14] = CGameSettings::GetCampaignStatus(14);
  dword_402CBBC[14] = 4;
  CGuiGameState::OpenDialog(this, 4, GuiDlgAOCampaignsSettleProc);
  return this;
}


// address=[0x14a0c30]
// Decompiled from void __thiscall CStateAOCampaignsSettle::~CStateAOCampaignsSettle(CStateAOCampaignsSettle *this)
 CStateAOCampaignsSettle::~CStateAOCampaignsSettle(void) {
  
  *(_DWORD *)this = &CStateAOCampaignsSettle::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 4);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a0c90]
// Decompiled from char __thiscall CStateAOCampaignsSettle::Perform(CStateAOCampaignsSettle *this)
bool  CStateAOCampaignsSettle::Perform(void) {
  
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
    if ( dword_402C91C > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_402C91C);
      if ( dword_402C91C == -1 )
      {
        dword_402C918 = timeGetTime();
        j___Init_thread_footer(&dword_402C91C);
      }
    }
    v2 = dword_402C918 + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_402C918 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14a0d70]
// Decompiled from char __thiscall CStateAOCampaignsSettle::OnEvent(CStateAOCampaignsSettle *this, struct CEvn_Event *a2)
bool  CStateAOCampaignsSettle::OnEvent(class CEvn_Event &) {
  
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
        v3 = CEvn_Event::CEvn_Event(&v5, 0x1F52u, 0, 0, 0);
        v6 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v3);
        v6 = -1;
        CEvn_Event::~CEvn_Event(&v5);
        return 1;
      }
      break;
    case 8007:
      CGameStateHandler::Switch((int)CStateAOBriefing::DynamicCreateFunc, (a2->wparam << 16) | 0xE);
      return 1;
    case 8018:
      CGameStateHandler::Switch((int)CStateAOCampaigns::DynamicCreateFunc, 1);
      return 1;
  }
  return CGuiGameState::OnEvent(this, a2);
}


// address=[0x14a0fb0]
// Decompiled from char __thiscall CStateAOCampaignsSettle::CanProcessInvites(CStateAOCampaignsSettle *this)
bool  CStateAOCampaignsSettle::CanProcessInvites(void) {
  
  return 0;
}


