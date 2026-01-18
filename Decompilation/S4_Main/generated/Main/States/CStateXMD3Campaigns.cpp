#include "CStateXMD3Campaigns.h"

// Definitions for class CStateXMD3Campaigns

// address=[0x14cdf60]
// Decompiled from CStateXMD3Campaigns *__cdecl CStateXMD3Campaigns::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateXMD3Campaigns::DynamicCreateFunc(void * a1) {
  
  CStateXMD3Campaigns *C; // [esp+Ch] [ebp-10h]

  C = (CStateXMD3Campaigns *)operator new(4u);
  if ( C )
    return CStateXMD3Campaigns::CStateXMD3Campaigns(C, a1);
  else
    return 0;
}


// address=[0x14cdfe0]
// Decompiled from CStateXMD3Campaigns *__thiscall CStateXMD3Campaigns::CStateXMD3Campaigns(CStateXMD3Campaigns *this, void *a2)
 CStateXMD3Campaigns::CStateXMD3Campaigns(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateXMD3Campaigns::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pMissionCD3, 0, (int)GuiDlgXMD3CampaignsProc);
  g_cCampaignSettings = 25;
  dword_402CBBC[21] = CGameSettings::GetCampaignStatus(21);
  dword_402CBBC[23] = CGameSettings::GetCampaignStatus(23);
  dword_402CBBC[22] = CGameSettings::GetCampaignStatus(22);
  dword_402CBBC[24] = CGameSettings::GetCampaignStatus(24);
  dword_402CBBC[21] = 4;
  dword_402CBBC[23] = 4;
  dword_402CBBC[22] = 4;
  dword_402CBBC[24] = 4;
  CGuiGameState::OpenDialog(this, 0, GuiDlgXMD3CampaignsProc);
  return this;
}


// address=[0x14ce120]
// Decompiled from void __thiscall CStateXMD3Campaigns::~CStateXMD3Campaigns(CStateXMD3Campaigns *this)
 CStateXMD3Campaigns::~CStateXMD3Campaigns(void) {
  
  *(_DWORD *)this = &CStateXMD3Campaigns::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14ce180]
// Decompiled from char __thiscall CStateXMD3Campaigns::Perform(CStateXMD3Campaigns *this)
bool  CStateXMD3Campaigns::Perform(void) {
  
  DWORD v2; // esi
  int Instance; // [esp+8h] [ebp-4h]

  Instance = UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) )
  {
    IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
    if ( !g_pMissionCD3 && BBSupportDbgReport(2, "main\\states\\statexmd3campaigns.cpp", 185, "g_pMissionCD3") == 1 )
      __debugbreak();
    (*(void (__thiscall **)(int, _DWORD, char (__cdecl *)(int, int, int)))(*(_DWORD *)g_pMissionCD3 + 12))(
      g_pMissionCD3,
      0,
      GuiDlgMainscreenProc);
    CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
    return 1;
  }
  else
  {
    if ( dword_4032210 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_4032210);
      if ( dword_4032210 == -1 )
      {
        dword_403220C = timeGetTime();
        j___Init_thread_footer(&dword_4032210);
      }
    }
    v2 = dword_403220C + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_403220C = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14ce2b0]
// Decompiled from char __thiscall CStateXMD3Campaigns::OnEvent(CStateXMD3Campaigns *this, struct CEvn_Event *a2)
bool  CStateXMD3Campaigns::OnEvent(class CEvn_Event & a2) {
  
  char result; // al
  CEvn_Event *v3; // [esp+18h] [ebp-38h]
  unsigned int event; // [esp+24h] [ebp-2Ch]
  CEvn_Event v5; // [esp+28h] [ebp-28h] BYREF
  int v6; // [esp+4Ch] [ebp-4h]

  event = a2->event;
  if ( event > 0x251E )
  {
    switch ( event )
    {
      case 0x251Fu:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateXMD3Briefing::DynamicCreateFunc, (a2->wparam << 16) | 0x16);
        result = 1;
        break;
      case 0x2520u:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateXMD3Briefing::DynamicCreateFunc, (a2->wparam << 16) | 0x17);
        result = 1;
        break;
      case 0x2521u:
        if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
          CGameSettings::SetAIDifficulty(dword_4031CFC);
        CGameStateHandler::Switch((int)CStateXMD3Briefing::DynamicCreateFunc, (a2->wparam << 16) | 0x18);
        result = 1;
        break;
      case 0x2522u:
        IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 0);
        if ( !g_pMissionCD3
          && BBSupportDbgReport(2, "main\\states\\statexmd3campaigns.cpp", 117, (const char *)&dword_375A5B0[1]) == 1 )
        {
          __debugbreak();
        }
        (*(void (__thiscall **)(int, _DWORD, char (__cdecl *)(int, int, int)))(*(_DWORD *)g_pMissionCD3 + 12))(
          g_pMissionCD3,
          0,
          GuiDlgMainscreenProc);
        CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
        result = 1;
        break;
      default:
        return CGuiGameState::OnEvent(this, a2);
    }
  }
  else if ( event == 9502 )
  {
    if ( dword_4031CFC != CGameSettings::GetAIDifficulty() )
      CGameSettings::SetAIDifficulty(dword_4031CFC);
    CGameStateHandler::Switch((int)CStateXMD3Briefing::DynamicCreateFunc, (a2->wparam << 16) | 0x15);
    return 1;
  }
  else if ( event == 11 && (unsigned __int16)a2->wparam == 27 )
  {
    v3 = CEvn_Event::CEvn_Event(&v5, 0x2522u, 0, 0, 0);
    v6 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v3);
    v6 = -1;
    CEvn_Event::~CEvn_Event(&v5);
    return 1;
  }
  else
  {
    return CGuiGameState::OnEvent(this, a2);
  }
  return result;
}


// address=[0x14ce6f0]
// Decompiled from char __thiscall CStateXMD3Campaigns::CanProcessInvites(CStateXMD3Campaigns *this)
bool  CStateXMD3Campaigns::CanProcessInvites(void) {
  
  return 0;
}


