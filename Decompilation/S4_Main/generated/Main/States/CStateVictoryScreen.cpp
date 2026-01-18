#include "CStateVictoryScreen.h"

// Definitions for class CStateVictoryScreen

// address=[0x14cb770]
// Decompiled from CStateVictoryScreen *__cdecl CStateVictoryScreen::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateVictoryScreen::DynamicCreateFunc(void * a1) {
  
  CStateVictoryScreen *C; // [esp+Ch] [ebp-10h]

  C = (CStateVictoryScreen *)operator new(4u);
  if ( C )
    return CStateVictoryScreen::CStateVictoryScreen(C, a1);
  else
    return 0;
}


// address=[0x14cb7f0]
// Decompiled from CStateVictoryScreen *__thiscall CStateVictoryScreen::CStateVictoryScreen(CStateVictoryScreen *this, int a2)
 CStateVictoryScreen::CStateVictoryScreen(void * a2) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateVictoryScreen::_vftable_;
  g_iVictoryScreenCampaignType = a2;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupGui(this, L"Menu\\GUISetStartscreens.dat", 12, GuiDlgMainSplashProc);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
  return this;
}


// address=[0x14cb890]
// Decompiled from void __thiscall CStateVictoryScreen::~CStateVictoryScreen(CStateVictoryScreen *this)
 CStateVictoryScreen::~CStateVictoryScreen(void) {
  
  *(_DWORD *)this = &CStateVictoryScreen::_vftable_;
  IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 1);
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 12)
    && BBSupportDbgReport(2, "main\\States\\StateVictoryScreen.cpp", 70, "bRet") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14cb920]
// Decompiled from char __thiscall CStateVictoryScreen::Perform(CStateVictoryScreen *this)
bool  CStateVictoryScreen::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_4032134 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_4032134);
    if ( dword_4032134 == -1 )
    {
      dword_4032130 = timeGetTime();
      j___Init_thread_footer(&dword_4032134);
    }
  }
  v1 = dword_4032130 + 30;
  if ( v1 >= timeGetTime() )
    return 1;
  dword_4032130 = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14cb9c0]
// Decompiled from char __thiscall CStateVictoryScreen::OnEvent(CStateVictoryScreen *this, struct CEvn_Event *a2)
bool  CStateVictoryScreen::OnEvent(class CEvn_Event & a2) {
  
  int event; // [esp+4h] [ebp-4h]

  event = a2->event;
  if ( event != 8 && event != 10 && event != 11 )
    return CGuiGameState::OnEvent(this, a2);
  CGameStateHandler::Next();
  return 1;
}


