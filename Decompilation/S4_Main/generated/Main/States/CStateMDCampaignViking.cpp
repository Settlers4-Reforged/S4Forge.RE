#include "CStateMDCampaignViking.h"

// Definitions for class CStateMDCampaignViking

// address=[0x14c7c10]
// Decompiled from CStateMDCampaignViking *__cdecl CStateMDCampaignViking::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateMDCampaignViking::DynamicCreateFunc(void * a1) {
  
  CStateMDCampaignViking *C; // [esp+Ch] [ebp-10h]

  C = (CStateMDCampaignViking *)operator new(4u);
  if ( C != 0 )
  {
    return CStateMDCampaignViking::CStateMDCampaignViking(C, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14c7c90]
// Decompiled from CStateMDCampaignViking *__thiscall CStateMDCampaignViking::CStateMDCampaignViking(CStateMDCampaignViking *this, void *a2)
 CStateMDCampaignViking::CStateMDCampaignViking(void * a2) {
  
  CGuiGameState::CGuiGameState((CGuiGameState *)this);
  *(_DWORD *)this = &CStateMDCampaignViking::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui((int)g_pMissionCD, 3, (int)GuiDlgMDCampaignVikingProc);
  g_cCampaignSettings = 16;
  dword_402CBBC[6] = CGameSettings::GetCampaignStatus(6);
  dword_402CBBC[6] = 5;
  CGuiGameState::OpenDialog((CGuiGameState *)this, 3, (bool (__cdecl *)(int, int, int))GuiDlgMDCampaignVikingProc);
  return this;
}


// address=[0x14c7d50]
// Decompiled from void __thiscall CStateMDCampaignViking::~CStateMDCampaignViking(CGuiGameState *this)
 CStateMDCampaignViking::~CStateMDCampaignViking(void) {
  
  this->__vftable = (CGuiGameState_vtbl *)&CStateMDCampaignViking::_vftable_;
  IGuiEngine::CloseDialog(g_pGUIEngine, 3);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14c7db0]
// Decompiled from char __thiscall CStateMDCampaignViking::Perform(CStateMDCampaignViking *this)
bool  CStateMDCampaignViking::Perform(void) {
  
  DWORD v2; // esi
  int Instance; // [esp+8h] [ebp-4h]

  Instance = (int)UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) != 0 )
  {
    CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateMDCampaigns::DynamicCreateFunc, (void *)1);
    return 1;
  }
  else
  {
    if ( dword_4031F78 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_4031F78);
      if ( dword_4031F78 == -1 )
      {
        dword_4031F74 = timeGetTime();
        j___Init_thread_footer(&dword_4031F78);
      }
    }
    v2 = dword_4031F74 + 30;
    if ( v2 < timeGetTime() )
    {
      dword_4031F74 = timeGetTime();
      IGuiEngine::RenderGui(g_pGUIEngine);
      IGfxEngine::RenderFrame(g_pGfxEngine, 0, 0);
      IGfxEngine::ShowFrame(g_pGfxEngine);
    }
    return 1;
  }
}


// address=[0x14c7e90]
// Decompiled from char __thiscall CStateMDCampaignViking::OnEvent(CGuiGameState *this, struct CEvn_Event *a2)
bool  CStateMDCampaignViking::OnEvent(class CEvn_Event & a2) {
  
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
        v3 = CEvn_Event::CEvn_Event(&v5, 0x1B65u, 0, 0, 0);
        v6 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v3);
        v6 = -1;
        CEvn_Event::~CEvn_Event(&v5);
        return 1;
      }
      break;
    case 7012:
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateMDBriefing::DynamicCreateFunc, (void *)((a2->m_wParam << 16) | 6));
      return 1;
    case 7013:
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateMDCampaigns::DynamicCreateFunc, (void *)1);
      return 1;
    default:
      break;
  }
  return CGuiGameState::OnEvent(this, a2);
}


// address=[0x14c80d0]
// Decompiled from char __thiscall CStateMDCampaignViking::CanProcessInvites(CStateMDCampaignViking *this)
bool  CStateMDCampaignViking::CanProcessInvites(void) {
  
  return 0;
}


