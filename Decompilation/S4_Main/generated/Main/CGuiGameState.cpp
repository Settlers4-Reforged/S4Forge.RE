#include "CGuiGameState.h"

// Definitions for class CGuiGameState

// address=[0x1372120]
// Decompiled from int __thiscall CGuiGameState::OnEvent(CGuiGameState *this, struct CEvn_Event *a2)
bool  CGuiGameState::OnEvent(class CEvn_Event &) {
  
  if ( a2->event == 3 )
    CGuiGameState::AlignDialogsInScreenCenter(this);
  return CGameState::OnEvent((int)a2);
}


// address=[0x149f3e0]
// Decompiled from CGuiGameState *__thiscall CGuiGameState::CGuiGameState(CGuiGameState *this)
 CGuiGameState::CGuiGameState(void) {
  
  CGameState::CGameState(this);
  *(_DWORD *)this = &CGuiGameState::_vftable_;
  return this;
}


// address=[0x149f410]
// Decompiled from void __thiscall CGuiGameState::~CGuiGameState(CGuiGameState *this)
 CGuiGameState::~CGuiGameState(void) {
  
  CGameState::~CGameState(this);
}


// address=[0x1372150]
// Decompiled from char __thiscall CGuiGameState::EnsureGfxEngineIsInGuiMode(void *this)
void  CGuiGameState::EnsureGfxEngineIsInGuiMode(void) {
  
  char result; // al

  if ( !g_pGfxEngine )
    return CGameStateHandler::RebuildGfxEngine(1);
  result = IGfxEngine::IsGuiMode(g_pGfxEngine, this);
  if ( !result )
    return CGameStateHandler::RebuildGfxEngine(1);
  return result;
}


// address=[0x1372180]
// Decompiled from void __thiscall CGuiGameState::SetupGui(  CGuiGameState *this,  wchar_t *FileName,  int a3,  bool (__cdecl *a4)(int, int, int),  int a5)
void  CGuiGameState::SetupGui(wchar_t const *,int,bool (__cdecl*)(int,int,int),int) {
  
  sub_1372640(FileName);
  if ( g_pGUIEngine )
  {
    if ( !IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, a5, a4)
      && BBSupportDbgReport(2, "Main\\States\\GuiGameState.cpp", 68, "bRet") == 1 )
    {
      __debugbreak();
    }
  }
  else if ( !CGuiGameState::InitGuiEngine(this, (char *)g_pDialogData, a3, a4) )
  {
    MessageBoxA(g_hWnd, "Error initializing User Interface!\nFehler beim Erstellen des User Interfaces!", "S4", 0x30u);
    j__exit(0);
  }
  CGuiGameState::AlignDialogsInScreenCenter(this);
}


// address=[0x1372230]
// Decompiled from void __thiscall CGuiGameState::SetupGuiWithExtra(  CGuiGameState *this,  wchar_t *FileName,  int a3,  bool (__cdecl *a4)(int, int, int),  struct IExtraCD *a5)
void  CGuiGameState::SetupGuiWithExtra(wchar_t const *,int,bool (__cdecl*)(int,int,int),class IExtraCD *) {
  
  sub_1372640(FileName);
  if ( g_pGUIEngine )
  {
    (*(void (__thiscall **)(struct IExtraCD *, int, bool (__cdecl *)(int, int, int)))(*(_DWORD *)a5 + 8))(a5, a3, a4);
    if ( !IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, a3, a4)
      && BBSupportDbgReport(2, "Main\\States\\GuiGameState.cpp", 94, "bRet") == 1 )
    {
      __debugbreak();
    }
  }
  else if ( !CGuiGameState::InitGuiEngine(this, (char *)g_pDialogData, a3, a4) )
  {
    MessageBoxA(g_hWnd, "Error initializing User Interface!\nFehler beim Erstellen des User Interfaces!", "S4", 0x30u);
    j__exit(0);
  }
  CGuiGameState::AlignDialogsInScreenCenter(this);
}


// address=[0x13722f0]
// Decompiled from void __thiscall CGuiGameState::SetupExtraGui(  CGuiGameState *this,  struct IExtraCD *a2,  int a3,  bool (__cdecl *a4)(int, int, int))
void  CGuiGameState::SetupExtraGui(class IExtraCD *,int,bool (__cdecl*)(int,int,int)) {
  
  CGuiGameState *v5; // [esp+0h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "Main\\States\\GuiGameState.cpp", 126, "addon") == 1 )
    __debugbreak();
  (*(void (__thiscall **)(struct IExtraCD *, int, bool (__cdecl *)(int, int, int)))(*(_DWORD *)a2 + 8))(a2, a3, a4);
  if ( !(unsigned __int8)IGfxEngine::IsGuiMode(g_pGfxEngine, this)
    && BBSupportDbgReportF(2, "Main\\States\\GuiGameState.cpp", 130, "GfxEngine not in GUI Mode after GFX switch!") == 1 )
  {
    __debugbreak();
  }
  CGuiGameState::AlignDialogsInScreenCenter(v5);
}


// address=[0x1372380]
// Decompiled from char __thiscall CGuiGameState::OpenDialog(CGuiGameState *this, int a2, bool (__cdecl *a3)(int, int, int))
bool  CGuiGameState::OpenDialog(int,bool (__cdecl*)(int,int,int)) {
  
  char v4; // [esp+7h] [ebp-1h]

  v4 = IGuiEngine::OpenDialog((IGuiEngine *)g_pGUIEngine, a2, a3);
  if ( !v4 && BBSupportDbgReport(2, "Main\\States\\GuiGameState.cpp", 138, "bRet") == 1 )
    __debugbreak();
  return v4;
}


// address=[0x14a3530]
// Decompiled from void __thiscall CGuiGameState::SetupGui(CGuiGameState *this, wchar_t *a2, int a3, bool (__cdecl *a4)(int, int, int))
void  CGuiGameState::SetupGui(wchar_t const *,int,bool (__cdecl*)(int,int,int)) {
  
  CGuiGameState::SetupGui(this, a2, a3, a4, a3);
}


// address=[0x13723d0]
// Decompiled from char __thiscall CGuiGameState::InitGuiEngine(CGuiGameState *this, char *a2, int a3, bool (__cdecl *a4)(int, int, int))
bool  CGuiGameState::InitGuiEngine(char *,int,bool (__cdecl*)(int,int,int)) {
  
  int Language; // eax
  IGuiEngine *v6; // [esp+Ch] [ebp-14h]
  IGuiEngine *C; // [esp+10h] [ebp-10h]

  if ( g_pGUIEngine )
    return 0;
  if ( GetGuiInterfaceVersion() == 120 )
  {
    C = (IGuiEngine *)operator new(0x10u);
    if ( C )
      v6 = IGuiEngine::IGuiEngine(C);
    else
      v6 = 0;
    g_pGUIEngine = (int)v6;
    Language = CGameSettings::GetLanguage();
    IGuiEngine::Init(
      (IGuiEngine *)g_pGUIEngine,
      (struct IGfxEngine *)g_pGfxEngine,
      (struct CGfxManager *)g_pGfxManager,
      (int)a2,
      a3,
      a4,
      Language);
    return 1;
  }
  else
  {
    MessageBoxA(g_hWnd, "Wrong version of GUI engine!", "Error:", 0x30u);
    CTrace::Print("Wrong version of GUI engine!");
    return 0;
  }
}


// address=[0x13724c0]
// Decompiled from void __thiscall CGuiGameState::AlignDialogsInScreenCenter(CGuiGameState *this)
void  CGuiGameState::AlignDialogsInScreenCenter(void) {
  
  int v1; // [esp+10h] [ebp-28h]
  int v2; // [esp+14h] [ebp-24h]
  float v3; // [esp+18h] [ebp-20h]
  float v4; // [esp+1Ch] [ebp-1Ch]
  float v5; // [esp+28h] [ebp-10h]
  int v6; // [esp+2Ch] [ebp-Ch]
  int OutputHeight; // [esp+30h] [ebp-8h]

  if ( !g_pGfxEngine && BBSupportDbgReport(2, "Main\\States\\GuiGameState.cpp", 145, "g_pGfxEngine != nullptr") == 1 )
    __debugbreak();
  if ( g_pGfxEngine )
  {
    if ( !g_pGUIEngine && BBSupportDbgReport(2, "Main\\States\\GuiGameState.cpp", 149, "g_pGUIEngine != nullptr") == 1 )
      __debugbreak();
    if ( g_pGUIEngine )
    {
      v5 = (float)*(&g_pResolutions + 2) / (float)*(&g_pResolutions + 3);
      IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
      OutputHeight = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
      v6 = (int)(float)((float)OutputHeight * v5);
      v3 = (float)v6 / (float)*(&g_pResolutions + 2);
      v4 = (float)OutputHeight / (float)*(&g_pResolutions + 3);
      v1 = (int)((double)(IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine) - v6) * 0.5);
      v2 = (int)((double)(IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine) - OutputHeight) * 0.5);
      IGuiEngine::SetDialogsRenderOffset((IGuiEngine *)g_pGUIEngine, v1, v2, v3, v4);
    }
  }
}


