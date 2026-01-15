#include "CStateAOCampaignTrojan.h"

// Definitions for class CStateAOCampaignTrojan

// address=[0x14a0fc0]
// Decompiled from CStateAOCampaignTrojan *__cdecl CStateAOCampaignTrojan::DynamicCreateFunc(void *a1)
static class CGameState * __cdecl CStateAOCampaignTrojan::DynamicCreateFunc(void *) {
  
  CStateAOCampaignTrojan *C; // [esp+Ch] [ebp-10h]

  C = (CStateAOCampaignTrojan *)operator new(4u);
  if ( C )
    return CStateAOCampaignTrojan::CStateAOCampaignTrojan(C, a1);
  else
    return 0;
}


// address=[0x14a1040]
// Decompiled from CStateAOCampaignTrojan *__thiscall CStateAOCampaignTrojan::CStateAOCampaignTrojan(  CStateAOCampaignTrojan *this,  void *a2)
 CStateAOCampaignTrojan::CStateAOCampaignTrojan(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateAOCampaignTrojan::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupExtraGui(g_pAddOn, 5, (int)GuiDlgAOCampaignTrojanProc);
  g_cCampaignSettings = 21;
  dword_402CBBC[15] = CGameSettings::GetCampaignStatus(15);
  dword_402CBBC[15] = 12;
  CGuiGameState::OpenDialog(this, 5, GuiDlgAOCampaignTrojanProc);
  return this;
}


// address=[0x14a1100]
// Decompiled from void __thiscall CStateAOCampaignTrojan::~CStateAOCampaignTrojan(CStateAOCampaignTrojan *this)
 CStateAOCampaignTrojan::~CStateAOCampaignTrojan(void) {
  
  *(_DWORD *)this = &CStateAOCampaignTrojan::_vftable_;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 5);
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a1160]
// Decompiled from char __thiscall CStateAOCampaignTrojan::Perform(CStateAOCampaignTrojan *this)
bool  CStateAOCampaignTrojan::Perform(void) {
  
  DWORD v2; // esi
  int Instance; // [esp+8h] [ebp-4h]

  Instance = UPlay::UPlayManager::GetInstance();
  if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)Instance + 36))(Instance) )
  {
    CGameStateHandler::Switch((int)CStateAOCampaigns::DynamicCreateFunc, 1);
    return 1;
  }
  else
  {
    if ( dword_402C924 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    {
      j___Init_thread_header(&dword_402C924);
      if ( dword_402C924 == -1 )
      {
        dword_402C920 = timeGetTime();
        j___Init_thread_footer(&dword_402C924);
      }
    }
    v2 = dword_402C920 + 30;
    if ( v2 >= timeGetTime() )
      return 1;
    dword_402C920 = timeGetTime();
    IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
    IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
    IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
    return 1;
  }
}


// address=[0x14a1240]
// Decompiled from char __thiscall CStateAOCampaignTrojan::OnEvent(CStateAOCampaignTrojan *this, struct CEvn_Event *a2)
bool  CStateAOCampaignTrojan::OnEvent(class CEvn_Event &) {
  
  CEvn_Event *v3; // [esp+8h] [ebp-3Ch]
  int wparam; // [esp+14h] [ebp-30h]
  int event; // [esp+18h] [ebp-2Ch]
  CEvn_Event v6; // [esp+1Ch] [ebp-28h] BYREF
  int v7; // [esp+40h] [ebp-4h]

  event = a2->event;
  if ( event == 11 )
  {
    if ( (unsigned __int16)a2->wparam != 27 )
      return CGuiGameState::OnEvent(this, a2);
    v3 = CEvn_Event::CEvn_Event(&v6, 0x1F50u, 0, 0, 0);
    v7 = 0;
    IEventEngine::SendAMessage(g_pEvnEngine, v3);
    v7 = -1;
    CEvn_Event::~CEvn_Event(&v6);
    return 1;
  }
  if ( event != 8015 )
  {
    if ( event != 8016 )
      return CGuiGameState::OnEvent(this, a2);
    CGameStateHandler::Switch((int)CStateAOCampaigns::DynamicCreateFunc, 1);
    return 1;
  }
  wparam = a2->wparam;
  if ( !wparam )
  {
    if ( (unsigned __int8)CGameSettings::GetShowVideos() )
      CGameStateHandler::Queue((int)CStateVideo::DynamicCreateFunc, 8);
  }
  CGameStateHandler::Switch((int)CStateAOBriefing::DynamicCreateFunc, (wparam << 16) | 0xF);
  return 1;
}


// address=[0x14a14a0]
// Decompiled from char __thiscall CStateAOCampaignTrojan::CanProcessInvites(CStateAOCampaignTrojan *this)
bool  CStateAOCampaignTrojan::CanProcessInvites(void) {
  
  return 0;
}


