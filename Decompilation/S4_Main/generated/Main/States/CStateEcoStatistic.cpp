#include "all_headers.h"

// Definitions for class CStateEcoStatistic

// address=[0x14a47b0]
// Decompiled from CStateEcoStatistic *__cdecl CStateEcoStatistic::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateEcoStatistic::DynamicCreateFunc(void *) {
  
  CStateEcoStatistic *C; // [esp+Ch] [ebp-10h]

  C = (CStateEcoStatistic *)operator new(4u);
  if ( C )
    return CStateEcoStatistic::CStateEcoStatistic(C, a1);
  else
    return 0;
}


// address=[0x14a4830]
// Decompiled from CStateEcoStatistic *__thiscall CStateEcoStatistic::CStateEcoStatistic(CStateEcoStatistic *this, void *a2)
 CStateEcoStatistic::CStateEcoStatistic(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateEcoStatistic::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupGui(this, (const wchar_t *)&dword_373E188[1], 22, GuiDlgMainStatisticEcoProc);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  return this;
}


// address=[0x14a48c0]
// Decompiled from void __thiscall CStateEcoStatistic::~CStateEcoStatistic(CStateEcoStatistic *this)
 CStateEcoStatistic::~CStateEcoStatistic(void) {
  
  *(_DWORD *)this = &CStateEcoStatistic::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 22)
    && BBSupportDbgReport(2, "main\\States\\StateEcoStatistic.cpp", 62, "bRet") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a4940]
// Decompiled from char __thiscall CStateEcoStatistic::Perform(CStateEcoStatistic *this)
bool  CStateEcoStatistic::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_402CC50 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_402CC50);
    if ( dword_402CC50 == -1 )
    {
      dword_402CC4C = timeGetTime();
      j___Init_thread_footer(&dword_402CC50);
    }
  }
  v1 = dword_402CC4C + 30;
  if ( v1 >= timeGetTime() )
    return 1;
  dword_402CC4C = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14a49e0]
// Decompiled from char __thiscall CStateEcoStatistic::OnEvent(CStateEcoStatistic *this, struct CEvn_Event *a2)
bool  CStateEcoStatistic::OnEvent(class CEvn_Event &) {
  
  CEvn_Event *v3; // [esp+8h] [ebp-5Ch]
  CEvn_Event *v4; // [esp+14h] [ebp-50h]
  int event; // [esp+20h] [ebp-44h]
  CEvn_Event v6; // [esp+24h] [ebp-40h] BYREF
  CEvn_Event v7; // [esp+3Ch] [ebp-28h] BYREF
  int v8; // [esp+60h] [ebp-4h]

  event = a2->event;
  if ( event == 11 )
  {
    if ( (unsigned __int16)a2->wparam != 27 )
      return CGuiGameState::OnEvent(this, a2);
    v4 = CEvn_Event::CEvn_Event(&v7, 0x5Du, 0, 0, 0);
    v8 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v4);
    v8 = -1;
    CEvn_Event::~CEvn_Event(&v7);
    return 1;
  }
  if ( event != 13 )
  {
    if ( event != 119 )
      return CGuiGameState::OnEvent(this, a2);
    CGameStateHandler::Next();
    return 1;
  }
  if ( a2->wparam != 27 )
    return 1;
  v3 = CEvn_Event::CEvn_Event(&v6, 0x77u, 0, 0, 0);
  v8 = 1;
  IEventEngine::SendAMessage(g_pEvnEngine, v3);
  v8 = -1;
  CEvn_Event::~CEvn_Event(&v6);
  return 1;
}


