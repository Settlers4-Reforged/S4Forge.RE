#include "CStateMessageBox.h"

// Definitions for class CStateMessageBox

// address=[0x14ca410]
// Decompiled from CStateMessageBox *__cdecl CStateMessageBox::DynamicCreateFunc(void *a1)

static class CGameState * __cdecl CStateMessageBox::DynamicCreateFunc(void *) {
  
  CStateMessageBox *C; // [esp+Ch] [ebp-10h]

  C = (CStateMessageBox *)operator new(4u);
  if ( C )
    return CStateMessageBox::CStateMessageBox(C, a1);
  else
    return 0;
}


// address=[0x14ca490]
// Decompiled from CStateMessageBox *__thiscall CStateMessageBox::CStateMessageBox(CStateMessageBox *this, int Str)

 CStateMessageBox::CStateMessageBox(void *) {
  
  char *v2; // eax

  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateMessageBox::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  if ( Str >= 3837 )
  {
    std::string::operator=(&g_iMessageBoxStringID, (char *)Str);
  }
  else
  {
    v2 = g_pStringEngine->GetString(g_pStringEngine, Str);
    std::string::operator=(&g_iMessageBoxStringID, v2);
  }
  CGuiGameState::SetupGui(this, L"Menu\\GUISetStartscreens.dat", 20, GuiDlgMainMessageBoxProc);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  return this;
}


// address=[0x14ca560]
// Decompiled from void __thiscall CStateMessageBox::~CStateMessageBox(CStateMessageBox *this)

 CStateMessageBox::~CStateMessageBox(void) {
  
  *(_DWORD *)this = &CStateMessageBox::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 20)
    && BBSupportDbgReport(2, "main\\States\\StateMessageBox.cpp", 75, "bRet") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14ca5e0]
// Decompiled from char __thiscall CStateMessageBox::Perform(CStateMessageBox *this)

bool  CStateMessageBox::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_40320A8 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_40320A8);
    if ( dword_40320A8 == -1 )
    {
      dword_40320A4 = timeGetTime();
      j___Init_thread_footer(&dword_40320A8);
    }
  }
  v1 = dword_40320A4 + 30;
  if ( v1 >= timeGetTime() )
    return 1;
  dword_40320A4 = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14ca680]
// Decompiled from char __thiscall CStateMessageBox::OnEvent(CStateMessageBox *this, struct CEvn_Event *a2)

bool  CStateMessageBox::OnEvent(class CEvn_Event &) {
  
  CEvn_Event *v3; // [esp+8h] [ebp-38h]
  int wparam; // [esp+10h] [ebp-30h]
  int event; // [esp+14h] [ebp-2Ch]
  CEvn_Event v6; // [esp+18h] [ebp-28h] BYREF
  int v7; // [esp+3Ch] [ebp-4h]

  event = a2->event;
  if ( event == 11 )
  {
    wparam = (unsigned __int16)a2->wparam;
    if ( wparam == 27 || wparam == 32 )
    {
      v3 = CEvn_Event::CEvn_Event(&v6, 0x72u, 0, 0, 0);
      v7 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v3);
      v7 = -1;
      CEvn_Event::~CEvn_Event(&v6);
      return 1;
    }
  }
  else if ( event == 114 )
  {
    CGameStateHandler::Next();
    return 1;
  }
  return CGuiGameState::OnEvent(this, a2);
}


