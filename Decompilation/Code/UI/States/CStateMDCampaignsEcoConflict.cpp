#include "CStateMDCampaignsEcoConflict.h"

// Definitions for class CStateMDCampaignsEcoConflict

// address=[0x14c76b0]
// Decompiled from CStateMDCampaignsEcoConflict *__cdecl CStateMDCampaignsEcoConflict::DynamicCreateFunc(void *a1)

static class CGameState * __cdecl CStateMDCampaignsEcoConflict::DynamicCreateFunc(void *) {
  
  CStateMDCampaignsEcoConflict *C; // [esp+Ch] [ebp-10h]

  C = (CStateMDCampaignsEcoConflict *)operator new(4u);
  if ( C )
    return CStateMDCampaignsEcoConflict::CStateMDCampaignsEcoConflict(C, a1);
  else
    return 0;
}


// address=[0x14c7730]
// Decompiled from CStateMDCampaignsEcoConflict *__thiscall CStateMDCampaignsEcoConflict::CStateMDCampaignsEcoConflict(
        CStateMDCampaignsEcoConflict *this,
        void *a2)

 CStateMDCampaignsEcoConflict::CStateMDCampaignsEcoConflict(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateMDCampaignsEcoConflict::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pMissionCD, 4, (int)GuiDlgMDCampaignsEcoConflictProc);
  g_cCampaignSettings = 17;
  dword_402CBBC[8] = CGameSettings::GetCampaignStatus(8);
  dword_402CBBC[8] = 3;
  dword_402CBBC[9] = CGameSettings::GetCampaignStatus(9);
  dword_402CBBC[9] = 3;
  CGuiGameState::OpenDialog(this, 4, GuiDlgMDCampaignsEcoConflictProc);
  return this;
}


// address=[0x14c7820]
// Decompiled from void __thiscall CStateMDCampaignsEcoConflict::~CStateMDCampaignsEcoConflict(CStateMDCampaignsEcoConflict *this)

 CStateMDCampaignsEcoConflict::~CStateMDCampaignsEcoConflict(void) {
  
  *(_DWORD *)this = &CStateMDCampaignsEcoConflict::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 4);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14c7880]
// Decompiled from char __thiscall CStateMDCampaignsEcoConflict::Perform(CStateMDCampaignsEcoConflict *this)

bool  CStateMDCampaignsEcoConflict::Perform(void) {
  
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
    if ( dword_4031F70 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_4031F70);
      if ( dword_4031F70 == -1 )
      {
        dword_4031F6C = timeGetTime();
        j___Init_thread_footer(&dword_4031F70);
      }
    }
    v2 = dword_4031F6C + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_4031F6C = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14c7960]
// Decompiled from char __thiscall CStateMDCampaignsEcoConflict::OnEvent(CStateMDCampaignsEcoConflict *this, struct CEvn_Event *a2)

bool  CStateMDCampaignsEcoConflict::OnEvent(class CEvn_Event &) {
  
  CEvn_Event *v3; // [esp+10h] [ebp-38h]
  unsigned int event; // [esp+1Ch] [ebp-2Ch]
  CEvn_Event v5; // [esp+20h] [ebp-28h] BYREF
  int v6; // [esp+44h] [ebp-4h]

  event = a2->event;
  if ( event > 0x1B67 )
  {
    if ( event == 7016 )
    {
      CGameStateHandler::Switch((int)CStateMDCampaigns::DynamicCreateFunc, 1);
      return 1;
    }
  }
  else
  {
    switch ( event )
    {
      case 0x1B67u:
        CGameStateHandler::Switch((int)CStateMDBriefing::DynamicCreateFunc, (a2->wparam << 16) | 9);
        return 1;
      case 0xBu:
        if ( (unsigned __int16)a2->wparam == 27 )
        {
          v3 = CEvn_Event::CEvn_Event(&v5, 0x1B68u, 0, 0, 0);
          v6 = 0;
          IEventEngine::SendAMessage(g_pEvnEngine, v3);
          v6 = -1;
          CEvn_Event::~CEvn_Event(&v5);
          return 1;
        }
        break;
      case 0x1B66u:
        CGameStateHandler::Switch((int)CStateMDBriefing::DynamicCreateFunc, (a2->wparam << 16) | 8);
        return 1;
    }
  }
  return CGuiGameState::OnEvent(this, a2);
}


// address=[0x14c7c00]
// Decompiled from // Microsoft VisualC 14/net runtime
char __thiscall CStateMDCampaignsEcoConflict::CanProcessInvites(CStateMDCampaignsEcoConflict *this)

bool  CStateMDCampaignsEcoConflict::CanProcessInvites(void) {
  
  return 0;
}


