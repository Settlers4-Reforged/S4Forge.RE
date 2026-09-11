#include "CStateAOCampaignMayan.h"

// Definitions for class CStateAOCampaignMayan

// address=[0x149f9f0]
// Decompiled from CStateAOCampaignMayan *__cdecl CStateAOCampaignMayan::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateAOCampaignMayan::DynamicCreateFunc(void * a1) {
  
  CStateAOCampaignMayan *C; // [esp+Ch] [ebp-10h]

  C = (CStateAOCampaignMayan *)operator new(4u);
  if ( C != 0 )
  {
    return CStateAOCampaignMayan::CStateAOCampaignMayan(C, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x149fa70]
// Decompiled from CStateAOCampaignMayan *__thiscall CStateAOCampaignMayan::CStateAOCampaignMayan(CStateAOCampaignMayan *this, void *a2)
 CStateAOCampaignMayan::CStateAOCampaignMayan(void * a2) {
  
  CGuiGameState::CGuiGameState((CGuiGameState *)this);
  *(_DWORD *)this = &CStateAOCampaignMayan::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui((int)g_pAddOn, 3, (int)GuiDlgAOCampaignMayanProc);
  g_cCampaignSettings = 19;
  dword_402CBBC[13] = CGameSettings::GetCampaignStatus(13);
  dword_402CBBC[13] = 5;
  CGuiGameState::OpenDialog((CGuiGameState *)this, 3, (bool (__cdecl *)(int, int, int))GuiDlgAOCampaignMayanProc);
  return this;
}


// address=[0x149fb30]
// Decompiled from void __thiscall CStateAOCampaignMayan::~CStateAOCampaignMayan(CGuiGameState *this)
 CStateAOCampaignMayan::~CStateAOCampaignMayan(void) {
  
  this->__vftable = (CGuiGameState_vtbl *)&CStateAOCampaignMayan::_vftable_;
  IGuiEngine::CloseDialog(g_pGUIEngine, 3);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x149fb90]
// Decompiled from char __thiscall CStateAOCampaignMayan::Perform(CStateAOCampaignMayan *this)
bool  CStateAOCampaignMayan::Perform(void) {
  
  DWORD v2; // esi
  int Instance; // [esp+8h] [ebp-4h]

  Instance = (int)UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) != 0 )
  {
    CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateAOCampaigns::DynamicCreateFunc, (void *)1);
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
    if ( v2 < timeGetTime() )
    {
      dword_402C900 = timeGetTime();
      IGuiEngine::RenderGui(g_pGUIEngine);
      IGfxEngine::RenderFrame(g_pGfxEngine, 0, 0);
      IGfxEngine::ShowFrame(g_pGfxEngine);
    }
    return 1;
  }
}


// address=[0x149fc70]
// Decompiled from char __thiscall CStateAOCampaignMayan::OnEvent(CGuiGameState *this, struct CEvn_Event *a2)
bool  CStateAOCampaignMayan::OnEvent(class CEvn_Event & a2) {
  
  CEvn_Event *v3; // [esp+Ch] [ebp-38h]
  int event; // [esp+18h] [ebp-2Ch]
  CEvn_Event v5; // [esp+1Ch] [ebp-28h] BYREF
  int v6; // [esp+40h] [ebp-4h]

  event = a2->m_iEventId;
  switch ( event )
  {
    case 11:
      if ( (unsigned __int16)a2->m_wParam == 27 )
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
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateAOBriefing::DynamicCreateFunc, (void *)((a2->m_wParam << 16) | 0xD));
      return 1;
    case 8012:
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateAOCampaigns::DynamicCreateFunc, (void *)1);
      return 1;
    default:
      break;
  }
  return CGuiGameState::OnEvent(this, a2);
}


// address=[0x149feb0]
// Decompiled from char __thiscall CStateAOCampaignMayan::CanProcessInvites(CStateAOCampaignMayan *this)
bool  CStateAOCampaignMayan::CanProcessInvites(void) {
  
  return 0;
}


