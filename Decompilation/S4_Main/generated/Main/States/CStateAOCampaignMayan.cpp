#include "all_headers.h"

// Definitions for class CStateAOCampaignMayan

// address=[0x149f9f0]
// Decompiled from CStateAOCampaignMayan *__cdecl CStateAOCampaignMayan::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateAOCampaignMayan::DynamicCreateFunc(void *) {
  
  CStateAOCampaignMayan *C; // [esp+Ch] [ebp-10h]

  C = (CStateAOCampaignMayan *)operator new(4u);
  if ( C )
    return CStateAOCampaignMayan::CStateAOCampaignMayan(C, a1);
  else
    return 0;
}


// address=[0x149fa70]
// Decompiled from CStateAOCampaignMayan *__thiscall CStateAOCampaignMayan::CStateAOCampaignMayan(CStateAOCampaignMayan *this, void *a2)
 CStateAOCampaignMayan::CStateAOCampaignMayan(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateAOCampaignMayan::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pAddOn, 3, (int)GuiDlgAOCampaignMayanProc);
  g_cCampaignSettings = 19;
  dword_402CBBC[13] = CGameSettings::GetCampaignStatus(13);
  dword_402CBBC[13] = 5;
  CGuiGameState::OpenDialog(this, 3, GuiDlgAOCampaignMayanProc);
  return this;
}


// address=[0x149fb30]
// Decompiled from void __thiscall CStateAOCampaignMayan::~CStateAOCampaignMayan(CStateAOCampaignMayan *this)
 CStateAOCampaignMayan::~CStateAOCampaignMayan(void) {
  
  *(_DWORD *)this = &CStateAOCampaignMayan::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 3);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x149fb90]
// Decompiled from char __thiscall CStateAOCampaignMayan::Perform(CStateAOCampaignMayan *this)
bool  CStateAOCampaignMayan::Perform(void) {
  
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
    if ( dword_402C904 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_402C904);
      if ( dword_402C904 == -1 )
      {
        dword_402C900 = timeGetTime();
        j___Init_thread_footer(&dword_402C904);
      }
    }
    v2 = dword_402C900 + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_402C900 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x149fc70]
// Decompiled from char __thiscall CStateAOCampaignMayan::OnEvent(CStateAOCampaignMayan *this, struct CEvn_Event *a2)
bool  CStateAOCampaignMayan::OnEvent(class CEvn_Event &) {
  
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
        v3 = CEvn_Event::CEvn_Event(&v5, 0x1F4Cu, 0, 0, 0);
        v6 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v3);
        v6 = -1;
        CEvn_Event::~CEvn_Event(&v5);
        return 1;
      }
      break;
    case 8011:
      CGameStateHandler::Switch((int)CStateAOBriefing::DynamicCreateFunc, (a2->wparam << 16) | 0xD);
      return 1;
    case 8012:
      CGameStateHandler::Switch((int)CStateAOCampaigns::DynamicCreateFunc, 1);
      return 1;
  }
  return CGuiGameState::OnEvent(this, a2);
}


// address=[0x149feb0]
// Decompiled from char __thiscall CStateAOCampaignMayan::CanProcessInvites(CStateAOCampaignMayan *this)
bool  CStateAOCampaignMayan::CanProcessInvites(void) {
  
  return 0;
}


