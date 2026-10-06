#include "CStateCredits.h"

// Definitions for class CStateCredits

// address=[0x14a3fb0]
// Decompiled from CStateCredits *__cdecl CStateCredits::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateCredits::DynamicCreateFunc(void * a1) {
  
  CStateCredits *C; // [esp+Ch] [ebp-10h]

  C = (CStateCredits *)operator new(4u);
  if ( C != 0 )
  {
    return CStateCredits::CStateCredits(C, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14a4160]
// Decompiled from CStateCredits *__thiscall CStateCredits::CStateCredits(CStateCredits *this, void *a2)
 CStateCredits::CStateCredits(void * a2) {
  
  CGuiGameState::CGuiGameState((CGuiGameState *)this);
  *(_DWORD *)this = &CStateCredits::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CStateCredits::SetupGUI(this);
  IGuiEngine::EnableEventInput(g_pGUIEngine, 0);
  return this;
}


// address=[0x14a41e0]
// Decompiled from CGameState *__thiscall CStateCredits::~CStateCredits(CGuiGameState *this)
 CStateCredits::~CStateCredits(void) {
  
  this->__vftable = (CGuiGameState_vtbl *)&CStateCredits::_vftable_;
  IGuiEngine::EnableEventInput(g_pGUIEngine, true);
  if ( g_pSoundManager != nullptr )
  {
    CSoundManager::StopMusic(g_pSoundManager);
  }
  if ( IGuiEngine::CloseDialog(g_pGUIEngine, 15) == 0 && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 90, "bRet") == 1 )
  {
    __debugbreak();
  }
  if ( IGuiEngine::CloseDialog(g_pGUIEngine, 16) == 0 && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 92, "bRet") == 1 )
  {
    __debugbreak();
  }
  if ( IGuiEngine::CloseDialog(g_pGUIEngine, 17) == 0 && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 94, "bRet") == 1 )
  {
    __debugbreak();
  }
  if ( IGuiEngine::CloseDialog(g_pGUIEngine, 14) == 0 && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 96, "bRet") == 1 )
  {
    __debugbreak();
  }
  sub_14A45D0();
  return CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a4330]
// Decompiled from char __thiscall CStateCredits::Perform(CStateCredits *this)
bool  CStateCredits::Perform(void) {
  
  signed int Time; // [esp+4h] [ebp-4h]

  if ( byte_402CC48 == 0 )
  {
    UpdateGuiDlgMainCredits();
    IGuiEngine::RenderGui(g_pGUIEngine);
    IGfxEngine::RenderFrame(g_pGfxEngine, 0, 0);
    byte_402CC48 = 1;
  }
  Time = timeGetTime();
  if ( byte_402CC48 != 0 && dword_402CC44 < Time )
  {
    dword_402CC44 = Time + 15;
    IGfxEngine::ShowFrame(g_pGfxEngine);
    byte_402CC48 = 0;
  }
  return 1;
}


// address=[0x14a43b0]
// Decompiled from char __thiscall CStateCredits::OnEvent(CGuiGameState *this, struct CEvn_Event *a2)
bool  CStateCredits::OnEvent(class CEvn_Event & a2) {
  
  char result; // al
  CEvn_Event *v4; // [esp+8h] [ebp-58h]
  CEvn_Event *v5; // [esp+14h] [ebp-4Ch]
  CEvn_Event v6; // [esp+20h] [ebp-40h] BYREF
  CEvn_Event v7; // [esp+38h] [ebp-28h] BYREF
  int v8; // [esp+5Ch] [ebp-4h]

  switch ( a2->m_iEventId )
  {
    case 3:
      ((void (*)(void))sub_14A4570)();
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
      if ( (unsigned __int16)a2->m_wParam != 27 )
      {
        goto CStateCredits__OnEvent___def_18A4401;
      }
      v4 = CEvn_Event::CEvn_Event(&v6, 0x6Du, 0, 0, 0);
      v8 = 1;
      IEventEngine::SendAMessage(g_pEvnEngine, v4);
      v8 = -1;
      CEvn_Event::~CEvn_Event(&v6);
      result = 1;
      break;
    case 0x6D:
      CGameStateHandler::Switch(CStateMainMenu::DynamicCreateFunc, 0);
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
  
  if ( g_pSoundManager != 0 )
  {
    CSoundManager::StopMusic(g_pSoundManager);
    CSoundManager::PlayBackgroundMusic(5, 5, 0);
  }
  if ( IGuiEngine::OpenDialog(g_pGUIEngine, 14, (bool (__cdecl *)(int, int, int))GuiDlgMainCreditsProc) == 0 && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 206, "bRet") == 1 )
  {
    __debugbreak();
  }
  if ( IGuiEngine::OpenDialog(g_pGUIEngine, 17, (bool (__cdecl *)(int, int, int))GuiDlgMainCreditsPaperProc) == 0 && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 208, "bRet") == 1 )
  {
    __debugbreak();
  }
  if ( IGuiEngine::OpenDialog(g_pGUIEngine, 16, (bool (__cdecl *)(int, int, int))GuiDlgMainCreditsTopProc) == 0 && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 210, "bRet") == 1 )
  {
    __debugbreak();
  }
  if ( IGuiEngine::OpenDialog(g_pGUIEngine, 15, (bool (__cdecl *)(int, int, int))GuiDlgMainCreditsBottomProc) == 0 && BBSupportDbgReport(2, "main\\states\\StateCredits.cpp", 212, "bRet") == 1 )
  {
    __debugbreak();
  }
  return ((int (__thiscall *)(_DWORD, CStateCredits *))sub_14A4570)(0, this);
}


