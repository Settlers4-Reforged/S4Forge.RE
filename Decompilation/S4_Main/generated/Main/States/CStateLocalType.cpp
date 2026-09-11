#include "CStateLocalType.h"

// Definitions for class CStateLocalType

// address=[0x14c1100]
// Decompiled from CStateLocalType *__cdecl CStateLocalType::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateLocalType::DynamicCreateFunc(void * a1) {
  
  CStateLocalType *C; // [esp+Ch] [ebp-10h]

  C = (CStateLocalType *)operator new(4u);
  if ( C != 0 )
  {
    return CStateLocalType::CStateLocalType(C, a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14c1180]
// Decompiled from CStateLocalType *__thiscall CStateLocalType::CStateLocalType(CStateLocalType *this, void *a2)
 CStateLocalType::CStateLocalType(void * a2) {
  
  CGuiGameState::CGuiGameState((CGuiGameState *)this);
  *(_DWORD *)this = &CStateLocalType::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  s_uAIDifficulty = CGameSettings::GetAIDifficulty();
  CGuiGameState::OpenDialog((CGuiGameState *)this, 7, (bool (__cdecl *)(int, int, int))GuiDlgMainLocalTypeProc);
  return this;
}


// address=[0x14c1200]
// Decompiled from void __thiscall CStateLocalType::~CStateLocalType(CGuiGameState *this)
 CStateLocalType::~CStateLocalType(void) {
  
  this->__vftable = (CGuiGameState_vtbl *)&CStateLocalType::_vftable_;
  if ( !IGuiEngine::CloseDialog(g_pGUIEngine, 7) && BBSupportDbgReport(2, "main\\states\\StateLocalType.cpp", 61, (const char *)&dword_374C518[1]) == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14c1280]
// Decompiled from char __thiscall CStateLocalType::Perform(CStateLocalType *this)
bool  CStateLocalType::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_4031D08 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_4031D08);
    if ( dword_4031D08 == -1 )
    {
      dword_4031D04 = timeGetTime();
      j___Init_thread_footer(&dword_4031D08);
    }
  }
  v1 = dword_4031D04 + 30;
  if ( v1 < timeGetTime() )
  {
    dword_4031D04 = timeGetTime();
    IGuiEngine::RenderGui(g_pGUIEngine);
    IGfxEngine::RenderFrame(g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame(g_pGfxEngine);
  }
  return 1;
}


// address=[0x14c1320]
// Decompiled from char __thiscall CStateLocalType::OnEvent(CGuiGameState *this, struct CEvn_Event *a2)
bool  CStateLocalType::OnEvent(class CEvn_Event & a2) {
  
  char result; // al
  CEvn_Event *v3; // [esp+8h] [ebp-38h]
  CEvn_Event v4; // [esp+18h] [ebp-28h] BYREF
  int v5; // [esp+3Ch] [ebp-4h]

  switch ( a2->m_iEventId )
  {
    case 0xD:
      if ( a2->m_wParam == 27 )
      {
        v3 = CEvn_Event::CEvn_Event(&v4, 0x63u, 0, 0, 0);
        v5 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v3);
        v5 = -1;
        CEvn_Event::~CEvn_Event(&v4);
      }
      result = 1;
      break;
    case 0x60:
      if ( s_uAIDifficulty != CGameSettings::GetAIDifficulty() )
      {
        CGameSettings::SetAIDifficulty(s_uAIDifficulty);
      }
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateCampaignDark::DynamicCreateFunc, 0);
      result = 1;
      break;
    case 0x61:
      if ( s_uAIDifficulty != CGameSettings::GetAIDifficulty() )
      {
        CGameSettings::SetAIDifficulty(s_uAIDifficulty);
      }
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateCampaign3X3::DynamicCreateFunc, 0);
      result = 1;
      break;
    case 0x62:
      if ( s_uAIDifficulty != CGameSettings::GetAIDifficulty() )
      {
        CGameSettings::SetAIDifficulty(s_uAIDifficulty);
      }
      dword_403191C = 0;
      CGameStateHandler::Switch((struct CGameState *(__cdecl *)(void *))CStateLobbyMapSettings::DynamicCreateFunc, 0);
      result = 1;
      break;
    case 0x63:
      if ( s_uAIDifficulty != CGameSettings::GetAIDifficulty() )
      {
        CGameSettings::SetAIDifficulty(s_uAIDifficulty);
      }
      CGameStateHandler::Switch(CStateMainMenu::DynamicCreateFunc, 0);
      result = 1;
      break;
    default:
      result = CGuiGameState::OnEvent(this, a2);
      break;
  }
  return result;
}


