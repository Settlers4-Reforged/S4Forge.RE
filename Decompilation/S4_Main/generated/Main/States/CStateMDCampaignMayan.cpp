#include "CStateMDCampaignMayan.h"

// Definitions for class CStateMDCampaignMayan

// address=[0x14c65f0]
// Decompiled from CStateMDCampaignMayan *__cdecl CStateMDCampaignMayan::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateMDCampaignMayan::DynamicCreateFunc(void * a1) {
  
  CStateMDCampaignMayan *C; // [esp+Ch] [ebp-10h]

  C = (CStateMDCampaignMayan *)operator new(4u);
  if ( C )
    return CStateMDCampaignMayan::CStateMDCampaignMayan(C, a1);
  else
    return 0;
}


// address=[0x14c6670]
// Decompiled from CStateMDCampaignMayan *__thiscall CStateMDCampaignMayan::CStateMDCampaignMayan(CStateMDCampaignMayan *this, void *a2)
 CStateMDCampaignMayan::CStateMDCampaignMayan(void * a2) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateMDCampaignMayan::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pMissionCD, 2, (int)GuiDlgMDCampaignMayanProc);
  g_cCampaignSettings = 15;
  dword_402CBBC[7] = CGameSettings::GetCampaignStatus(7);
  dword_402CBBC[7] = 5;
  CGuiGameState::OpenDialog(this, 2, GuiDlgMDCampaignMayanProc);
  return this;
}


// address=[0x14c6730]
// Decompiled from void __thiscall CStateMDCampaignMayan::~CStateMDCampaignMayan(CStateMDCampaignMayan *this)
 CStateMDCampaignMayan::~CStateMDCampaignMayan(void) {
  
  *(_DWORD *)this = &CStateMDCampaignMayan::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 2);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14c6790]
// Decompiled from char __thiscall CStateMDCampaignMayan::Perform(CStateMDCampaignMayan *this)
bool  CStateMDCampaignMayan::Perform(void) {
  
  DWORD v2; // esi
  int Instance; // [esp+8h] [ebp-4h]

  Instance = UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) )
  {
    CGameStateHandler::Switch((int)CStateMDCampaigns::DynamicCreateFunc, 1);
    return 1;
  }
  else
  {
    if ( dword_4031F58 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_4031F58);
      if ( dword_4031F58 == -1 )
      {
        dword_4031F54 = timeGetTime();
        j___Init_thread_footer(&dword_4031F58);
      }
    }
    v2 = dword_4031F54 + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_4031F54 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14c6870]
// Decompiled from char __thiscall CStateMDCampaignMayan::OnEvent(CStateMDCampaignMayan *this, struct CEvn_Event *a2)
bool  CStateMDCampaignMayan::OnEvent(class CEvn_Event & a2) {
  
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
        v3 = CEvn_Event::CEvn_Event(&v5, 0x1B63u, 0, 0, 0);
        v6 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v3);
        v6 = -1;
        CEvn_Event::~CEvn_Event(&v5);
        return 1;
      }
      break;
    case 7010:
      CGameStateHandler::Switch((int)CStateMDBriefing::DynamicCreateFunc, (a2->wparam << 16) | 7);
      return 1;
    case 7011:
      CGameStateHandler::Switch((int)CStateMDCampaigns::DynamicCreateFunc, 1);
      return 1;
  }
  return CGuiGameState::OnEvent(this, a2);
}


// address=[0x14c6ab0]
// Decompiled from char __thiscall CStateMDCampaignMayan::CanProcessInvites(CStateMDCampaignMayan *this)
bool  CStateMDCampaignMayan::CanProcessInvites(void) {
  
  return 0;
}


