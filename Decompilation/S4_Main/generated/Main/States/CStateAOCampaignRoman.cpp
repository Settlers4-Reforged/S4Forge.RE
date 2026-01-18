#include "CStateAOCampaignRoman.h"

// Definitions for class CStateAOCampaignRoman

// address=[0x149fec0]
// Decompiled from CStateAOCampaignRoman *__cdecl CStateAOCampaignRoman::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateAOCampaignRoman::DynamicCreateFunc(void * a1) {
  
  CStateAOCampaignRoman *C; // [esp+Ch] [ebp-10h]

  C = (CStateAOCampaignRoman *)operator new(4u);
  if ( C )
    return CStateAOCampaignRoman::CStateAOCampaignRoman(C, a1);
  else
    return 0;
}


// address=[0x149ff40]
// Decompiled from CStateAOCampaignRoman *__thiscall CStateAOCampaignRoman::CStateAOCampaignRoman(CStateAOCampaignRoman *this, void *a2)
 CStateAOCampaignRoman::CStateAOCampaignRoman(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateAOCampaignRoman::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pAddOn, 1, (int)GuiDlgAOCampaignRomanProc);
  g_cCampaignSettings = 18;
  dword_402CBBC[11] = CGameSettings::GetCampaignStatus(11);
  dword_402CBBC[11] = 5;
  CGuiGameState::OpenDialog(this, 1, GuiDlgAOCampaignRomanProc);
  return this;
}


// address=[0x14a0000]
// Decompiled from void __thiscall CStateAOCampaignRoman::~CStateAOCampaignRoman(CStateAOCampaignRoman *this)
 CStateAOCampaignRoman::~CStateAOCampaignRoman(void) {
  
  *(_DWORD *)this = &CStateAOCampaignRoman::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 1);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a0060]
// Decompiled from char __thiscall CStateAOCampaignRoman::Perform(CStateAOCampaignRoman *this)
bool  CStateAOCampaignRoman::Perform(void) {
  
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
    if ( dword_402C90C > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_402C90C);
      if ( dword_402C90C == -1 )
      {
        dword_402C908 = timeGetTime();
        j___Init_thread_footer(&dword_402C90C);
      }
    }
    v2 = dword_402C908 + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_402C908 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14a0140]
// Decompiled from char __thiscall CStateAOCampaignRoman::OnEvent(CStateAOCampaignRoman *this, struct CEvn_Event *a2)
bool  CStateAOCampaignRoman::OnEvent(class CEvn_Event & a2) {
  
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
    case 8009:
      CGameStateHandler::Switch((int)CStateAOBriefing::DynamicCreateFunc, (a2->wparam << 16) | 0xB);
      return 1;
    case 8010:
      CGameStateHandler::Switch((int)CStateAOCampaigns::DynamicCreateFunc, 1);
      return 1;
  }
  return CGuiGameState::OnEvent(this, a2);
}


// address=[0x14a0380]
// Decompiled from char __thiscall CStateAOCampaignRoman::CanProcessInvites(CStateAOCampaignRoman *this)
bool  CStateAOCampaignRoman::CanProcessInvites(void) {
  
  return 0;
}


