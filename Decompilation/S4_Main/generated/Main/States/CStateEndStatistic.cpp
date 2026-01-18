#include "CStateEndStatistic.h"

// Definitions for class CStateEndStatistic

// address=[0x14a4c30]
// Decompiled from CStateEndStatistic *__cdecl CStateEndStatistic::DynamicCreateFunc(void *a1)
class CGameState * __cdecl CStateEndStatistic::DynamicCreateFunc(void * a1) {
  
  CStateEndStatistic *C; // [esp+Ch] [ebp-10h]

  C = (CStateEndStatistic *)operator new(4u);
  if ( C )
    return CStateEndStatistic::CStateEndStatistic(C, a1);
  else
    return 0;
}


// address=[0x14a4cb0]
// Decompiled from CStateEndStatistic *__thiscall CStateEndStatistic::CStateEndStatistic(CStateEndStatistic *this, void *a2)
 CStateEndStatistic::CStateEndStatistic(void *) {
  
  wchar_t *v2; // eax
  int Instance; // [esp+4h] [ebp-34h]
  _BYTE v6[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v7; // [esp+34h] [ebp-4h]

  CGuiGameState::CGuiGameState(this);
  v7 = 0;
  *(_DWORD *)this = &CStateEndStatistic::_vftable_;
  Instance = UPlay::UPlayManager::GetInstance();
  (*(void (__thiscall **)(int, int))(*(_DWORD *)Instance + 52))(Instance, 1);
  CGuiGameState::EnsureGfxEngineIsInGuiMode(this);
  CGuiGameState::SetupGui(this, (const wchar_t *)&dword_373E218[1], 13, GuiDlgMainStatisticProc);
  IGfxEngine::SetCursorShape((IGfxEngine *)g_pGfxEngine, 1, 0);
  std::wstring::wstring(v6);
  LOBYTE(v7) = 1;
  if ( (*(unsigned __int8 (__thiscall **)(void *, _BYTE *, const wchar_t *, int))(*(_DWORD *)g_pCDDrive + 8))(
         g_pCDDrive,
         v6,
         L"Snd\\Romans*.mp3",
         131073) )
  {
    v2 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v6);
    CSoundManager::PlayBackgroundMusic(5, 4, v2);
  }
  else
  {
    CSoundManager::StopMusic(g_pSoundManager);
  }
  LOBYTE(v7) = 0;
  std::wstring::~wstring(v6);
  return this;
}


// address=[0x14a4dc0]
// Decompiled from void __thiscall CStateEndStatistic::~CStateEndStatistic(CStateEndStatistic *this)
 CStateEndStatistic::~CStateEndStatistic(void) {
  
  *(_DWORD *)this = &CStateEndStatistic::_vftable_;
  if ( !IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 13)
    && BBSupportDbgReport(2, "main\\States\\StateEndStatistic.cpp", 91, "bRet") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::~CGuiGameState(this);
}


// address=[0x14a4e40]
// Decompiled from char __thiscall CStateEndStatistic::Perform(CStateEndStatistic *this)
bool  CStateEndStatistic::Perform(void) {
  
  DWORD v1; // esi

  if ( dword_402CC5C > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_402CC5C);
    if ( dword_402CC5C == -1 )
    {
      dword_402CC58 = timeGetTime();
      j___Init_thread_footer(&dword_402CC5C);
    }
  }
  v1 = dword_402CC58 + 30;
  if ( v1 >= timeGetTime() )
    return 1;
  dword_402CC58 = timeGetTime();
  IGuiEngine::RenderGui((IGuiEngine *)g_pGUIEngine);
  IGfxEngine::RenderFrame((IGfxEngine *)g_pGfxEngine, 0, 0);
  IGfxEngine::ShowFrame((IGfxEngine *)g_pGfxEngine);
  return 1;
}


// address=[0x14a4ee0]
// Decompiled from char __thiscall CStateEndStatistic::OnEvent(CStateEndStatistic *this, struct CEvn_Event *a2)
bool  CStateEndStatistic::OnEvent(class CEvn_Event & a2) {
  
  char result; // al
  CEvn_Event *v3; // [esp+8h] [ebp-7Ch]
  CEvn_Event *v4; // [esp+10h] [ebp-74h]
  CEvn_Event *v5; // [esp+1Ch] [ebp-68h]
  CEvn_Event v6; // [esp+2Ch] [ebp-58h] BYREF
  CEvn_Event v7; // [esp+44h] [ebp-40h] BYREF
  CEvn_Event v8; // [esp+5Ch] [ebp-28h] BYREF
  int v9; // [esp+80h] [ebp-4h]

  switch ( a2->event )
  {
    case 0xB:
      if ( (unsigned __int16)a2->wparam != 27 )
        goto CStateEndStatistic__OnEvent___def_18A4F31;
      v5 = CEvn_Event::CEvn_Event(&v8, 0x5Du, 0, 0, 0);
      v9 = 0;
      IEventEngine::SendAMessage(g_pEvnEngine, v5);
      v9 = -1;
      CEvn_Event::~CEvn_Event(&v8);
      result = 1;
      break;
    case 0xD:
      if ( a2->wparam == 27 )
      {
        if ( iScreenFlag == 1 )
        {
          v4 = CEvn_Event::CEvn_Event(&v7, 0x75u, 0, 0, 0);
          v9 = 1;
          IEventEngine::SendAMessage(g_pEvnEngine, v4);
          v9 = -1;
          CEvn_Event::~CEvn_Event(&v7);
        }
        else
        {
          v3 = CEvn_Event::CEvn_Event(&v6, 0x74u, 0, 0, 0);
          v9 = 2;
          IEventEngine::SendAMessage(g_pEvnEngine, v3);
          v9 = -1;
          CEvn_Event::~CEvn_Event(&v6);
        }
        result = 1;
      }
      else
      {
        result = 1;
      }
      break;
    case 0x73:
      IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 13);
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 21, GuiDlgMainDetailStatisticProc);
      UpdateGuiDlgMainDetailStatistic(a2->wparam);
      iScreenFlag = 1;
      result = 1;
      break;
    case 0x74:
      CGameStateHandler::Next();
      result = 1;
      break;
    case 0x75:
      IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, 21);
      IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, 13, GuiDlgMainStatisticProc);
      iScreenFlag = 0;
      result = 1;
      break;
    default:
CStateEndStatistic__OnEvent___def_18A4F31:
      result = CGuiGameState::OnEvent(this, a2);
      break;
  }
  return result;
}


