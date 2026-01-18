#include "CStateTutorial.h"

// Definitions for class CStateTutorial

// address=[0x14cadc0]
// Decompiled from CStateTutorial *__cdecl CStateTutorial::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateTutorial::DynamicCreateFunc(void * a1) {
  
  CStateTutorial *C; // [esp+Ch] [ebp-10h]

  C = (CStateTutorial *)operator new(4u);
  if ( C )
    return CStateTutorial::CStateTutorial(C, a1);
  else
    return 0;
}


// address=[0x14cae40]
// Decompiled from CStateTutorial *__thiscall CStateTutorial::CStateTutorial(CStateTutorial *this, void *a2)
 CStateTutorial::CStateTutorial(void *) {
  
  CGuiGameState::CGuiGameState(this);
  *(_DWORD *)this = &CStateTutorial::_vftable_;
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  g_cTutorialStatus = 9;
  dword_40320BC = CGameSettings::GetTutorialStatus();
  CGuiGameState::OpenDialog(this, 11, GuiDlgMainTutorialProc);
  return this;
}


// address=[0x14caed0]
// Decompiled from void __thiscall CStateTutorial::~CStateTutorial(CStateTutorial *this)
 CStateTutorial::~CStateTutorial(void) {
  
  *(_DWORD *)this = &CStateTutorial::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 11)
    && BBSupportDbgReport(2, "main\\states\\StateTutorial.cpp", 76, "bRet") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14caf50]
// Decompiled from char __thiscall CStateTutorial::Perform(CStateTutorial *this)
bool  CStateTutorial::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_4032128 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_4032128);
    if ( dword_4032128 == -1 )
    {
      dword_4032124 = timeGetTime();
      j___Init_thread_footer(&dword_4032128);
    }
  }
  v1 = dword_4032124 + 30;
  if ( v1 >= timeGetTime() )
    return 1;
  dword_4032124 = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14caff0]
// Decompiled from char __thiscall CStateTutorial::OnEvent(CStateTutorial *this, struct CEvn_Event *a2)
bool  CStateTutorial::OnEvent(class CEvn_Event & a2) {
  
  char result; // al
  char *v3; // eax
  char *v4; // eax
  OnlineManager *Instance; // eax
  char v6; // [esp-40h] [ebp-2C0h] BYREF
  int v7; // [esp-3Ch] [ebp-2BCh]
  int v8; // [esp-38h] [ebp-2B8h]
  int v9; // [esp-34h] [ebp-2B4h]
  int v10; // [esp-30h] [ebp-2B0h]
  int v11; // [esp-2Ch] [ebp-2ACh]
  int v12; // [esp-28h] [ebp-2A8h]
  int v13; // [esp-24h] [ebp-2A4h]
  int v14; // [esp-20h] [ebp-2A0h]
  int v15; // [esp-1Ch] [ebp-29Ch]
  int v16; // [esp-18h] [ebp-298h]
  int v17; // [esp-14h] [ebp-294h]
  int v18; // [esp-10h] [ebp-290h]
  int v19; // [esp-Ch] [ebp-28Ch]
  int v20; // [esp-8h] [ebp-288h]
  int v21; // [esp-4h] [ebp-284h]
  int v22; // [esp+4h] [ebp-27Ch]
  char *v23; // [esp+8h] [ebp-278h]
  INetworkEngine *v24; // [esp+Ch] [ebp-274h]
  int v25; // [esp+10h] [ebp-270h]
  int v26; // [esp+14h] [ebp-26Ch]
  CGameType *v27; // [esp+18h] [ebp-268h]
  CEvn_Event *v28; // [esp+1Ch] [ebp-264h]
  CGuiGameState *v29; // [esp+28h] [ebp-258h]
  INetworkEngine *v30; // [esp+2Ch] [ebp-254h]
  void *v31; // [esp+30h] [ebp-250h]
  CGameType *v32; // [esp+34h] [ebp-24Ch]
  void *C; // [esp+38h] [ebp-248h]
  int (__thiscall ***v34)(_DWORD, int); // [esp+3Ch] [ebp-244h]
  bool v35; // [esp+43h] [ebp-23Dh]
  unsigned int i; // [esp+44h] [ebp-23Ch]
  int v37; // [esp+48h] [ebp-238h]
  char v38; // [esp+4Dh] [ebp-233h]
  char MapData; // [esp+4Eh] [ebp-232h]
  char v40; // [esp+4Fh] [ebp-231h]
  CEvn_Event v41; // [esp+50h] [ebp-230h] BYREF
  wchar_t Buffer[260]; // [esp+68h] [ebp-218h] BYREF
  int v43; // [esp+27Ch] [ebp-4h]

  v29 = this;
  v37 = a2->event - 13;
  switch ( v37 )
  {
    case 0:
      if ( a2->wparam == 27 )
      {
        v28 = CEvn_Event::CEvn_Event(&v41, 0x69u, 0, 0, 0);
        v43 = 0;
        IEventEngine::SendAMessage(g_pEvnEngine, v28);
        v43 = -1;
        CEvn_Event::~CEvn_Event(&v41);
      }
      result = 1;
      break;
    case 91:
      if ( a2->wparam >= 0xCu
        && BBSupportDbgReport(
             2,
             "main\\states\\StateTutorial.cpp",
             116,
             "_rEvent.m_wParam < TUTORIAL_COUNT && _rEvent.m_wParam >= 0") == 1 )
      {
        __debugbreak();
      }
      v21 = a2->wparam + 1;
      v3 = (char *)std::wstring::c_str((_Cnd_internal_imp_t *)&unk_40320F4);
      swprintf((char *)Buffer, v3, v21);
      C = operator new(0x620u);
      v43 = 1;
      if ( C )
        v32 = CGameType::CGameType((CGameType *)C);
      else
        v32 = 0;
      v27 = v32;
      v43 = -1;
      g_pGameType = (int)v32;
      v21 = 0;
      v20 = 0;
      v19 = -1;
      v18 = -1;
      v17 = 0;
      v16 = 1;
      v15 = 0;
      v14 = 0;
      v13 = 1;
      v23 = &v6;
      v22 = std::wstring::wstring(&v6, Buffer);
      MapData = CGameType::LoadMapData(v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19, v20, v21);
      v38 = MapData;
      if ( MapData )
      {
        IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 4);
        IGuiEngine::EnableEventInput((IGuiEngine *)g_pGUIEngine, 0);
        if ( (unsigned __int8)CStateLobbyGameSettings::CopyDefaultUserFlags() )
        {
          if ( g_pNetworkEngine )
          {
            v26 = g_pNetworkEngine;
            v34 = (int (__thiscall ***)(_DWORD, int))g_pNetworkEngine;
            v25 = (**v34)(v34, 1);
            g_pNetworkEngine = 0;
          }
          v31 = operator new(0x18u);
          v43 = 2;
          if ( v31 )
            v30 = INetworkEngine::INetworkEngine((INetworkEngine *)v31, 0);
          else
            v30 = 0;
          v24 = v30;
          v43 = -1;
          g_pNetworkEngine = (int)v30;
          *(_DWORD *)(g_pGameType + 112) = *(_DWORD *)(g_pGameType + 852);
          for ( i = 0; i < *(_DWORD *)(g_pGameType + 112); ++i )
            *(_BYTE *)(i + g_pGameType + 440) = 0;
          *(_DWORD *)(g_pGameType + 188) = INetworkEngine::GetLocalIP((CGameHost **)g_pNetworkEngine);
          Instance = (OnlineManager *)OnlineManager::GetInstance();
          *(_DWORD *)(g_pGameType + 224) = OnlineManager::GetLocalPeerId(Instance);
          *(_DWORD *)(g_pGameType + 692) = 4;
          INetworkEngine::Start(1, 1, *(_DWORD *)(g_pGameType + 112), 0);
          CGameStateHandler::Switch((int)CStateGame::DynamicCreateFunc, 0);
          result = 1;
        }
        else
        {
          CGameStateHandler::Switch((int)CStateMessageBox::DynamicCreateFunc, 2398);
          result = 1;
        }
      }
      else
      {
        v4 = g_pStringEngine->GetString(g_pStringEngine, 2406);
        std::string::operator=(&g_iMessageBoxStringID, v4);
        v40 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 11);
        v40 = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 20, GuiDlgMainMessageBoxProc);
        if ( !v40 && BBSupportDbgReport(2, "main\\states\\StateTutorial.cpp", 128, "bRet") == 1 )
          __debugbreak();
        BBSupportTracePrintF(3, "Tutorial Map '%s' not found!", (const char *)Buffer);
        result = 1;
      }
      break;
    case 92:
      CGameStateHandler::Switch((int)CStateMainMenu::DynamicCreateFunc, 0);
      result = 1;
      break;
    case 101:
      v35 = IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 20);
      CGuiGameState::OpenDialog(v29, 11, GuiDlgMainTutorialProc);
      result = 1;
      break;
    default:
      result = CGuiGameState::OnEvent(v29, a2);
      break;
  }
  return result;
}


