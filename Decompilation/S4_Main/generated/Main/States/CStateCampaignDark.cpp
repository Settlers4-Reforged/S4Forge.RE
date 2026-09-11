#include "CStateCampaignDark.h"

// Definitions for class CStateCampaignDark

// address=[0x14a3ac0]
// Decompiled from CStateCampaignDark *__cdecl CStateCampaignDark::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateCampaignDark::DynamicCreateFunc(void * a1) {
  
  CStateCampaignDark *C; // [esp+Ch] [ebp-10h]

  C = (CStateCampaignDark *)operator new(4u);
  if ( C != 0 )
  {
    return CStateCampaignDark::CStateCampaignDark(C, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14a3b40]
// Decompiled from CStateCampaignDark *__thiscall CStateCampaignDark::CStateCampaignDark(CStateCampaignDark *this, void *a2)
 CStateCampaignDark::CStateCampaignDark(void * a2) {
  
  CGuiGameState::CGuiGameState((CGuiGameState *)this);
  *(_DWORD *)this = &CStateCampaignDark::_vftable_;
  g_cCampaignSettings = 7;
  dword_402CBBC[4] = CGameSettings::GetCampaignStatus(4);
  dword_402CBBC[4] = 11;
  CGuiGameState::OpenDialog((CGuiGameState *)this, 9, (bool (__cdecl *)(int, int, int))GuiDlgMainDarktribeCampaignProc);
  return this;
}


// address=[0x14a3be0]
// Decompiled from void __thiscall CStateCampaignDark::~CStateCampaignDark(CGuiGameState *this)
 CStateCampaignDark::~CStateCampaignDark(void) {
  
  this->__vftable = (CGuiGameState_vtbl *)&CStateCampaignDark::_vftable_;
  if ( !IGuiEngine::CloseDialog(g_pGUIEngine, 9) && BBSupportDbgReport(2, "main\\states\\StateCampaignDark.cpp", 65, (const char *)&dword_373DFA8[1]) == 1 )
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
  if ( v1 < timeGetTime() )
  {
    dword_402CC3C = timeGetTime();
    IGuiEngine::RenderGui(g_pGUIEngine);
    IGfxEngine::RenderFrame(g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame(g_pGfxEngine);
  }
  return 1;
}


// address=[0x14a3d00]
// Decompiled from char __thiscall CStateCampaignDark::OnEvent(CGuiGameState *this, struct CEvn_Event *a2)
bool  CStateCampaignDark::OnEvent(class CEvn_Event & a2) {
  
  CEvn_Event *v3; // [esp+8h] [ebp-3Ch]
  int event; // [esp+14h] [ebp-30h]
  int wparam; // [esp+18h] [ebp-2Ch]
  CEvn_Event v6; // [esp+1Ch] [ebp-28h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  event = a2->m_iEventId;
  if ( event == 11 )
  {
    if ( (unsigned __int16)a2->m_wParam == 27 )
    {
      v3 = CEvn_Event::CEvn_Event(&v6, 0x65u, 0, 0, 0);
      v7 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v3);
      v7 = -1;
      CEvn_Event::~CEvn_Event(&v6);
      return 1;
    }
    return CGuiGameState::OnEvent(this, a2);
  }
  if ( event != 100 )
  {
    if ( event == 101 )
    {
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateLocalType::DynamicCreateFunc, 0);
      return 1;
    }
    return CGuiGameState::OnEvent(this, a2);
  }
  wparam = a2->m_wParam;
  if ( (unsigned __int8)CGameSettings::GetShowVideos() != 0 )
  {
    if ( wparam != 0 )
    {
      switch ( wparam )
      {
        case 2:
          CGameStateHandler::Queue((CStateMessageBox *(__cdecl *)(int))CStateVideo::DynamicCreateFunc, (void *)3);
          break;
        case 4:
          CGameStateHandler::Queue((CStateMessageBox *(__cdecl *)(int))CStateVideo::DynamicCreateFunc, (void *)4);
          break;
        case 9:
          CGameStateHandler::Queue((CStateMessageBox *(__cdecl *)(int))CStateVideo::DynamicCreateFunc, (void *)5);
          break;
        default:
          break;
      }
    }
    else
    {
      CGameStateHandler::Queue((CStateMessageBox *(__cdecl *)(int))CStateVideo::DynamicCreateFunc, (void *)2);
    }
  }
  CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateBriefing::DynamicCreateFunc, (void *)((wparam << 16) | 4));
  return 1;
}


