#include "all_headers.h"

// Definitions for class CStateCredits

// address=[0x14a3fb0]
// Decompiled from CStateCredits *__cdecl CStateCredits::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateCredits::DynamicCreateFunc(void *) {
  
  CStateCredits *C; // [esp+Ch] [ebp-10h]

  C = (CStateCredits *)operator new(4u);
  if ( C )
    return CStateCredits::CStateCredits(C, a1);
  else
    return 0;
}


// address=[0x14a4160]
// Decompiled from CStateCredits *__thiscall CStateCredits::CStateCredits(CStateCredits *this, void *a2)
 CStateCredits::CStateCredits(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateCredits::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CStateCredits::SetupGUI(this);
  IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
  return this;
}


// address=[0x14a41e0]
// Decompiled from void __thiscall CStateCredits::~CStateCredits(CStateCredits *this)
 CStateCredits::~CStateCredits(void) {
  
  *(_DWORD *)this = &CStateCredits::_vftable_;
  IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 1);
  if ( g_pSoundManager )
    CSoundManager::StopMusic(g_pSoundManager);
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 15)
    && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 90, "bRet") == 1 )
  {
    __debugbreak();
  }
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 16)
    && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 92, "bRet") == 1 )
  {
    __debugbreak();
  }
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 17)
    && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 94, "bRet") == 1 )
  {
    __debugbreak();
  }
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 14)
    && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 96, "bRet") == 1 )
  {
    __debugbreak();
  }
  sub_14A45D0();
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a4330]
// Decompiled from char __thiscall CStateCredits::Perform(CStateCredits *this)
bool  CStateCredits::Perform(void) {
  
  signed int Time; // [esp+4h] [ebp-4h]

  if ( !byte_402CC48 )
  {
    UpdateGuiDlgMainCredits();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    byte_402CC48 = 1;
  }
  Time = timeGetTime();
  if ( !byte_402CC48 || dword_402CC44 >= Time )
    return 1;
  dword_402CC44 = Time + 15;
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  byte_402CC48 = 0;
  return 1;
}


// address=[0x14a43b0]
// Decompiled from char __thiscall CStateCredits::OnEvent(CStateCredits *this, struct CEvn_Event *a2)
bool  CStateCredits::OnEvent(class CEvn_Event &) {
  
  char result; // al
  CEvn_Event *v4; // [esp+8h] [ebp-58h]
  CEvn_Event *v5; // [esp+14h] [ebp-4Ch]
  CEvn_Event v6; // [esp+20h] [ebp-40h] BYREF
  CEvn_Event v7; // [esp+38h] [ebp-28h] BYREF
  int v8; // [esp+5Ch] [ebp-4h]

  switch ( a2->event )
  {
    case 3:
      sub_14A4570();
      goto CStateCredits__OnEvent___def_18A4401;
    case 8:
    case 0xA:
      v5 = CEvn_Event::CEvn_Event(&v7, 0x6Du, 0, 0, 0);
      v8 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v5);
      v8 = -1;
      CEvn_Event::~CEvn_Event(&v7);
      return 1;
    case 0xB:
      if ( (unsigned __int16)a2->wparam != 27 )
        goto CStateCredits__OnEvent___def_18A4401;
      v4 = CEvn_Event::CEvn_Event(&v6, 0x6Du, 0, 0, 0);
      v8 = 1;
      IEventEngine::SendAMessage(g_pEvnEngine, v4);
      v8 = -1;
      CEvn_Event::~CEvn_Event(&v6);
      result = 1;
      break;
    case 0x6D:
      CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
      return 1;
    default:
CStateCredits__OnEvent___def_18A4401:
      result = CGuiGameState::OnEvent(this, a2);
      break;
  }
  return result;
}


// address=[0x14a4030]
// Decompiled from int __thiscall CStateCredits::SetupGUI(CStateCredits *this)
void  CStateCredits::SetupGUI(void) {
  
  if ( g_pSoundManager )
  {
    CSoundManager::StopMusic(g_pSoundManager);
    CSoundManager::PlayBackgroundMusic(5, 5, 0);
  }
  if ( !IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 14, GuiDlgMainCreditsProc)
    && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 206, "bRet") == 1 )
  {
    __debugbreak();
  }
  if ( !IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 17, GuiDlgMainCreditsPaperProc)
    && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 208, "bRet") == 1 )
  {
    __debugbreak();
  }
  if ( !IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 16, GuiDlgMainCreditsTopProc)
    && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 210, "bRet") == 1 )
  {
    __debugbreak();
  }
  if ( !IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 15, GuiDlgMainCreditsBottomProc)
    && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 212, "bRet") == 1 )
  {
    __debugbreak();
  }
  return sub_14A4570(0, this);
}


