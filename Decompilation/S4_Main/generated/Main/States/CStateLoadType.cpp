#include "CStateLoadType.h"

// Definitions for class CStateLoadType

// address=[0x14b6480]
// Decompiled from CStateLoadType *__cdecl CStateLoadType::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateLoadType::DynamicCreateFunc(void * a1) {
  
  CStateLoadType *C; // [esp+Ch] [ebp-10h]

  C = (CStateLoadType *)operator new(4u);
  if ( C != 0 )
  {
    return CStateLoadType::CStateLoadType(C, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14b6500]
// Decompiled from CStateLoadType *__thiscall CStateLoadType::CStateLoadType(CStateLoadType *this, void *a2)
 CStateLoadType::CStateLoadType(void * a2) {
  
  CGuiGameState::CGuiGameState((CGuiGameState *)this);
  *(_DWORD *)this = &CStateLoadType::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::OpenDialog((CGuiGameState *)this, 5, (bool (__cdecl *)(int, int, int))GuiDlgMainLoadTypeProc);
  return this;
}


// address=[0x14b6570]
// Decompiled from void __thiscall CStateLoadType::~CStateLoadType(CGuiGameState *this)
 CStateLoadType::~CStateLoadType(void) {
  
  this->__vftable = (CGuiGameState_vtbl *)&CStateLoadType::_vftable_;
  if ( !IGuiEngine::CloseDialog(g_pGUIEngine, 5) && BBSupportDbgReport(2, "main\\states\\StateLoadType.cpp", 57, "bRet") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14b65f0]
// Decompiled from char __thiscall CStateLoadType::Perform(CStateLoadType *this)
bool  CStateLoadType::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_40306D0 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_40306D0);
    if ( dword_40306D0 == -1 )
    {
      dword_40306CC = timeGetTime();
      j___Init_thread_footer(&dword_40306D0);
    }
  }
  v1 = dword_40306CC + 30;
  if ( v1 < timeGetTime() )
  {
    dword_40306CC = timeGetTime();
    IGuiEngine::RenderGui(g_pGUIEngine);
    IGfxEngine::RenderFrame(g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame(g_pGfxEngine);
  }
  return 1;
}


// address=[0x14b6690]
// Decompiled from char __thiscall CStateLoadType::OnEvent(CGuiGameState *this, struct CEvn_Event *a2)
bool  CStateLoadType::OnEvent(class CEvn_Event & a2) {
  
  char result; // al
  CEvn_Event *v3; // [esp+8h] [ebp-38h]
  CEvn_Event v4; // [esp+18h] [ebp-28h] BYREF
  int v5; // [esp+3Ch] [ebp-4h]

  switch ( a2->m_iEventId )
  {
    case 0xB:
      if ( (unsigned __int16)a2->m_wParam != 27 )
      {
        goto CStateLoadType__OnEvent___def_18B66E1;
      }
      v3 = CEvn_Event::CEvn_Event(&v4, 0x5Du, 0, 0, 0);
      v5 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v3);
      v5 = -1;
      CEvn_Event::~CEvn_Event(&v4);
      result = 1;
      break;
    case 0x59:
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateLoadGame::DynamicCreateFunc, 0);
      result = 1;
      break;
    case 0x5A:
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateLoadGame::DynamicCreateFunc, (void *)1);
      result = 1;
      break;
    case 0x5B:
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateLoadGame::DynamicCreateFunc, (void *)2);
      result = 1;
      break;
    case 0x5C:
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateLoadGame::DynamicCreateFunc, (void *)3);
      result = 1;
      break;
    case 0x5D:
      CGameStateHandler::Switch(CStateMainMenu::DynamicCreateFunc, 0);
      result = 1;
      break;
    default:
CStateLoadType__OnEvent___def_18B66E1:
      result = CGuiGameState::OnEvent(this, a2);
      break;
  }
  return result;
}


