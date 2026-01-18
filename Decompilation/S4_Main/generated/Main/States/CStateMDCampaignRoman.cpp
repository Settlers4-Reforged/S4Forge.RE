#include "CStateMDCampaignRoman.h"

// Definitions for class CStateMDCampaignRoman

// address=[0x14c6ac0]
// Decompiled from CStateMDCampaignRoman *__cdecl CStateMDCampaignRoman::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateMDCampaignRoman::DynamicCreateFunc(void * a1) {
  
  CStateMDCampaignRoman *C; // [esp+Ch] [ebp-10h]

  C = (CStateMDCampaignRoman *)operator new(4u);
  if ( C )
    return CStateMDCampaignRoman::CStateMDCampaignRoman(C, a1);
  else
    return 0;
}


// address=[0x14c6b40]
// Decompiled from CStateMDCampaignRoman *__thiscall CStateMDCampaignRoman::CStateMDCampaignRoman(CStateMDCampaignRoman *this, void *a2)
 CStateMDCampaignRoman::CStateMDCampaignRoman(void * a2) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateMDCampaignRoman::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pMissionCD, 1, (int)GuiDlgMDCampaignRomanProc);
  g_cCampaignSettings = 14;
  dword_402CBBC[5] = CGameSettings::GetCampaignStatus(5);
  dword_402CBBC[5] = 5;
  CGuiGameState::OpenDialog(this, 1, GuiDlgMDCampaignRomanProc);
  return this;
}


// address=[0x14c6c00]
// Decompiled from void __thiscall CStateMDCampaignRoman::~CStateMDCampaignRoman(CStateMDCampaignRoman *this)
 CStateMDCampaignRoman::~CStateMDCampaignRoman(void) {
  
  *(_DWORD *)this = &CStateMDCampaignRoman::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 1);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14c6c60]
// Decompiled from char __thiscall CStateMDCampaignRoman::Perform(CStateMDCampaignRoman *this)
bool  CStateMDCampaignRoman::Perform(void) {
  
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
    if ( dword_4031F60 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_4031F60);
      if ( dword_4031F60 == -1 )
      {
        dword_4031F5C = timeGetTime();
        j___Init_thread_footer(&dword_4031F60);
      }
    }
    v2 = dword_4031F5C + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_4031F5C = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14c6d40]
// Decompiled from char __thiscall CStateMDCampaignRoman::OnEvent(CStateMDCampaignRoman *this, struct CEvn_Event *a2)
bool  CStateMDCampaignRoman::OnEvent(class CEvn_Event & a2) {
  
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
        v3 = CEvn_Event::CEvn_Event(&v5, 0x1B61u, 0, 0, 0);
        v6 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v3);
        v6 = -1;
        CEvn_Event::~CEvn_Event(&v5);
        return 1;
      }
      break;
    case 7008:
      CGameStateHandler::Switch((int)CStateMDBriefing::DynamicCreateFunc, (a2->wparam << 16) | 5);
      return 1;
    case 7009:
      CGameStateHandler::Switch((int)CStateMDCampaigns::DynamicCreateFunc, 1);
      return 1;
  }
  return CGuiGameState::OnEvent(this, a2);
}


// address=[0x14c6f80]
// Decompiled from char __thiscall CStateMDCampaignRoman::CanProcessInvites(CStateMDCampaignRoman *this)
bool  CStateMDCampaignRoman::CanProcessInvites(void) {
  
  return 0;
}


