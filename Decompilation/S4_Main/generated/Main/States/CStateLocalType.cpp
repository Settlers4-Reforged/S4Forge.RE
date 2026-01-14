#include "all_headers.h"

// Definitions for class CStateLocalType

// address=[0x14c1100]
// Decompiled from CStateLocalType *__cdecl CStateLocalType::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateLocalType::DynamicCreateFunc(void *) {
  
  CStateLocalType *C; // [esp+Ch] [ebp-10h]

  C = (CStateLocalType *)operator new(4u);
  if ( C )
    return CStateLocalType::CStateLocalType(C, a1);
  else
    return 0;
}


// address=[0x14c1180]
// Decompiled from CStateLocalType *__thiscall CStateLocalType::CStateLocalType(CStateLocalType *this, void *a2)
 CStateLocalType::CStateLocalType(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateLocalType::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  dword_4031CFC = CGameSettings::GetAIDifficulty();
  CGuiGameState::OpenDialog(this, 7, GuiDlgMainLocalTypeProc);
  return this;
}


// address=[0x14c1200]
// Decompiled from void __thiscall CStateLocalType::~CStateLocalType(CStateLocalType *this)
 CStateLocalType::~CStateLocalType(void) {
  
  *(_DWORD *)this = &CStateLocalType::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 7)
    && BBSupportDbgReport(2, "main\\states\\StateLocalType.cpp", 61, (const char *)&dword_374C518[1]) == 1 )
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
  if ( v1 >= timeGetTime() )
    return 1;
  dword_4031D04 = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14c1320]
// Decompiled from char __thiscall CStateLocalType::OnEvent(CStateLocalType *this, struct CEvn_Event *a2)
bool  CStateLocalType::OnEvent(class CEvn_Event &) {
  
  char result; // al
  CEvn_Event *v3; // [esp+8h] [ebp-38h]
  CEvn_Event v4; // [esp+18h] [ebp-28h] BYREF
  int v5; // [esp+3Ch] [ebp-4h]

  switch ( a2->event )
  {
    case 0xD:
      if ( a2->wparam == 27 )
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
      if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
        CGameSettings::SetAIDifficulty(dword_4031CFC);
      CGameStateHandler::Switch((int)CStateCampaignDark::DynamicCreateFunc, 0);
      result = 1;
      break;
    case 0x61:
      if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
        CGameSettings::SetAIDifficulty(dword_4031CFC);
      CGameStateHandler::Switch((int)CStateCampaign3X3::DynamicCreateFunc, 0);
      result = 1;
      break;
    case 0x62:
      if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
        CGameSettings::SetAIDifficulty(dword_4031CFC);
      dword_403191C = 0;
      CGameStateHandler::Switch((int)CStateLobbyMapSettings::DynamicCreateFunc, 0);
      result = 1;
      break;
    case 0x63:
      if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
        CGameSettings::SetAIDifficulty(dword_4031CFC);
      CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
      result = 1;
      break;
    default:
      result = CGuiGameState::OnEvent(this, a2);
      break;
  }
  return result;
}


