#include "CStateAOSplash.h"

// Definitions for class CStateAOSplash

// address=[0x14a1980]
// Decompiled from CStateAOSplash *__cdecl CStateAOSplash::DynamicCreateFunc(int a1)
class CGameState * __cdecl CStateAOSplash::DynamicCreateFunc(void * a1) {
  
  CStateAOSplash *C; // [esp+Ch] [ebp-10h]

  C = (CStateAOSplash *)operator new(4u);
  if ( C != 0 )
  {
    return CStateAOSplash::CStateAOSplash(C, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14a1a00]
// Decompiled from CStateAOSplash *__thiscall CStateAOSplash::CStateAOSplash(CStateAOSplash *this, int a2)
 CStateAOSplash::CStateAOSplash(void * a2) {
  
  CGuiGameState::CGuiGameState((CGuiGameState *)this);
  *(_DWORD *)this = &CStateAOSplash::_vftable_;
  g_iAOSplashType = a2;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupGuiWithExtra((CGuiGameState *)this, L"Menu\\GUISetStartscreens.dat", 8, (bool (__cdecl *)(int, int, int))GuiDlgAOSplashProc, g_pAddOn);
  IGfxEngine::SetCursorShape(g_pGfxEngine, 1, 0);
  return this;
}


// address=[0x14a1aa0]
// Decompiled from void __thiscall CStateAOSplash::~CStateAOSplash(CGuiGameState *this)
 CStateAOSplash::~CStateAOSplash(void) {
  
  this->__vftable = (CGuiGameState_vtbl *)&CStateAOSplash::_vftable_;
  IGuiEngine::EnableEventInput(g_pGUIEngine, 1);
  if ( !IGuiEngine::CloseDialog(g_pGUIEngine, 8) && BBSupportDbgReport(2, "main\\states\\stateaosplash.cpp", 73, "bRet") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a1b30]
// Decompiled from char __thiscall CStateAOSplash::Perform(CStateAOSplash *this)
bool  CStateAOSplash::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_402C938 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_402C938);
    if ( dword_402C938 == -1 )
    {
      dword_402C934 = timeGetTime();
      j___Init_thread_footer(&dword_402C938);
    }
  }
  v1 = dword_402C934 + 30;
  if ( v1 < timeGetTime() )
  {
    dword_402C934 = timeGetTime();
    IGuiEngine::RenderGui(g_pGUIEngine);
    IGfxEngine::RenderFrame(g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame(g_pGfxEngine);
  }
  return 1;
}


// address=[0x14a1bd0]
// Decompiled from char __thiscall CStateAOSplash::OnEvent(CGuiGameState *this, struct CEvn_Event *a2)
bool  CStateAOSplash::OnEvent(class CEvn_Event & a2) {
  
  int event; // [esp+8h] [ebp-4h]

  event = a2->m_iEventId;
  if ( event == 11 )
  {
    if ( (unsigned __int16)a2->m_wParam == 27 )
    {
      g_bGuiSplashInitDone = 0;
      CSoundManager::StopMusic(g_pSoundManager);
      CSoundManager::StopSounds(g_pSoundManager);
      CGameStateHandler::Next();
      return 1;
    }
  }
  else if ( event == 8023 )
  {
    CGameStateHandler::Next();
    return 1;
  }
  return CGuiGameState::OnEvent(this, a2);
}


