#include "CStateCampaign3X3.h"

// Definitions for class CStateCampaign3X3

// address=[0x14a3560]
// Decompiled from CStateCampaign3X3 *__cdecl CStateCampaign3X3::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateCampaign3X3::DynamicCreateFunc(void * a1) {
  
  CStateCampaign3X3 *C; // [esp+Ch] [ebp-10h]

  C = (CStateCampaign3X3 *)operator new(4u);
  if ( C )
    return CStateCampaign3X3::CStateCampaign3X3(C, a1);
  else
    return 0;
}


// address=[0x14a35e0]
// Decompiled from CStateCampaign3X3 *__thiscall CStateCampaign3X3::CStateCampaign3X3(CStateCampaign3X3 *this, void *a2)
 CStateCampaign3X3::CStateCampaign3X3(void * a2) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateCampaign3X3::_vftable_;
  g_cCampaignSettings = 8;
  dword_402CBBC[1] = CGameSettings::GetCampaignStatus(1);
  dword_402CBBC[2] = CGameSettings::GetCampaignStatus(2);
  dword_402CBBC[3] = CGameSettings::GetCampaignStatus(3);
  dword_402CBBC[1] = 2;
  dword_402CBBC[2] = 2;
  dword_402CBBC[3] = 2;
  CGuiGameState::OpenDialog(this, 8, GuiDlgMain3x3CampaignProc);
  return this;
}


// address=[0x14a36d0]
// Decompiled from void __thiscall CStateCampaign3X3::~CStateCampaign3X3(CStateCampaign3X3 *this)
 CStateCampaign3X3::~CStateCampaign3X3(void) {
  
  *(_DWORD *)this = &CStateCampaign3X3::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 8)
    && BBSupportDbgReport(2, "main\\states\\StateCampaign3X3.cpp", 72, "bRet") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a3750]
// Decompiled from char __thiscall CStateCampaign3X3::Perform(CStateCampaign3X3 *this)
bool  CStateCampaign3X3::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_402CC38 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_402CC38);
    if ( dword_402CC38 == -1 )
    {
      dword_402CC34 = timeGetTime();
      j___Init_thread_footer(&dword_402CC38);
    }
  }
  v1 = dword_402CC34 + 30;
  if ( v1 >= timeGetTime() )
    return 1;
  dword_402CC34 = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14a37f0]
// Decompiled from char __thiscall CStateCampaign3X3::OnEvent(CStateCampaign3X3 *this, struct CEvn_Event *a2)
bool  CStateCampaign3X3::OnEvent(class CEvn_Event & a2) {
  
  CEvn_Event *v3; // [esp+Ch] [ebp-40h]
  int lparam; // [esp+18h] [ebp-34h]
  int event; // [esp+1Ch] [ebp-30h]
  int v6; // [esp+20h] [ebp-2Ch]
  CEvn_Event v7; // [esp+24h] [ebp-28h] BYREF
  int v8; // [esp+48h] [ebp-4h]

  event = a2->event;
  if ( event == 11 )
  {
    if ( (unsigned __int16)a2->wparam != 27 )
      return CGuiGameState::OnEvent(this, a2);
    v3 = CEvn_Event::CEvn_Event(&v7, 0x67u, 0, 0, 0);
    v8 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v3);
    v8 = -1;
    CEvn_Event::~CEvn_Event(&v7);
    return 1;
  }
  if ( event != 102 )
  {
    if ( event != 103 )
      return CGuiGameState::OnEvent(this, a2);
    CGameStateHandler::Switch((int)CStateLocalType::DynamicCreateFunc, 0);
    return 1;
  }
  v6 = 1;
  lparam = a2->lparam;
  if ( lparam )
  {
    if ( lparam == 1 )
    {
      v6 = 2;
    }
    else if ( lparam == 2 )
    {
      v6 = 3;
    }
    else if ( BBSupportDbgReportF(
                2,
                "main\\states\\StateCampaign3X3.cpp",
                130,
                "Unkown Race for Camapaign %d",
                a2->lparam) == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    v6 = 1;
  }
  CGameStateHandler::Switch((int)CStateBriefing::DynamicCreateFunc, v6 | (a2->wparam << 16));
  return 1;
}


