#include "CStateCampaignDark.h"

// Definitions for class CStateCampaignDark

// address=[0x14a3ac0]
// Decompiled from CStateCampaignDark *__cdecl CStateCampaignDark::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateCampaignDark::DynamicCreateFunc(void * a1) {
  
  CStateCampaignDark *C; // [esp+Ch] [ebp-10h]

  C = (CStateCampaignDark *)operator new(4u);
  if ( C )
    return CStateCampaignDark::CStateCampaignDark(C, a1);
  else
    return 0;
}


// address=[0x14a3b40]
// Decompiled from CStateCampaignDark *__thiscall CStateCampaignDark::CStateCampaignDark(CStateCampaignDark *this, void *a2)
 CStateCampaignDark::CStateCampaignDark(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateCampaignDark::_vftable_;
  g_cCampaignSettings = 7;
  dword_402CBBC[4] = CGameSettings::GetCampaignStatus(4);
  dword_402CBBC[4] = 11;
  CGuiGameState::OpenDialog(this, 9, GuiDlgMainDarktribeCampaignProc);
  return this;
}


// address=[0x14a3be0]
// Decompiled from void __thiscall CStateCampaignDark::~CStateCampaignDark(CStateCampaignDark *this)
 CStateCampaignDark::~CStateCampaignDark(void) {
  
  *(_DWORD *)this = &CStateCampaignDark::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 9)
    && BBSupportDbgReport(2, "main\\states\\StateCampaignDark.cpp", 65, (const char *)&dword_373DFA8[1]) == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a3c60]
// Decompiled from char __thiscall CStateCampaignDark::Perform(CStateCampaignDark *this)
bool  CStateCampaignDark::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_402CC40 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_402CC40);
    if ( dword_402CC40 == -1 )
    {
      dword_402CC3C = timeGetTime();
      j___Init_thread_footer(&dword_402CC40);
    }
  }
  v1 = dword_402CC3C + 30;
  if ( v1 >= timeGetTime() )
    return 1;
  dword_402CC3C = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14a3d00]
// Decompiled from char __thiscall CStateCampaignDark::OnEvent(CStateCampaignDark *this, struct CEvn_Event *a2)
bool  CStateCampaignDark::OnEvent(class CEvn_Event & a2) {
  
  CEvn_Event *v3; // [esp+8h] [ebp-3Ch]
  int event; // [esp+14h] [ebp-30h]
  int wparam; // [esp+18h] [ebp-2Ch]
  CEvn_Event v6; // [esp+1Ch] [ebp-28h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  event = a2->event;
  if ( event == 11 )
  {
    if ( (unsigned __int16)a2->wparam != 27 )
      return CGuiGameState::OnEvent(this, a2);
    v3 = CEvn_Event::CEvn_Event(&v6, 0x65u, 0, 0, 0);
    v7 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v3);
    v7 = -1;
    CEvn_Event::~CEvn_Event(&v6);
    return 1;
  }
  if ( event != 100 )
  {
    if ( event != 101 )
      return CGuiGameState::OnEvent(this, a2);
    CGameStateHandler::Switch((int)CStateLocalType::DynamicCreateFunc, 0);
    return 1;
  }
  wparam = a2->wparam;
  if ( (unsigned __int8)CGameSettings::GetShowVideos() )
  {
    if ( wparam )
    {
      switch ( wparam )
      {
        case 2:
          CGameStateHandler::Queue((int)CStateVideo::DynamicCreateFunc, 3);
          break;
        case 4:
          CGameStateHandler::Queue((int)CStateVideo::DynamicCreateFunc, 4);
          break;
        case 9:
          CGameStateHandler::Queue((int)CStateVideo::DynamicCreateFunc, 5);
          break;
      }
    }
    else
    {
      CGameStateHandler::Queue((int)CStateVideo::DynamicCreateFunc, 2);
    }
  }
  CGameStateHandler::Switch((int)CStateBriefing::DynamicCreateFunc, (wparam << 16) | 4);
  return 1;
}


