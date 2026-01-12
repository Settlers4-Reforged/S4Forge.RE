#include "CGUIWrapper.h"

// Definitions for class CGUIWrapper

// address=[0x13d8780]
// Decompiled from void *CGUIWrapper::GetInstance()

static class CGUIWrapper * __cdecl CGUIWrapper::GetInstance(void) {
  
  if ( dword_3EFD61C <= *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
    return &unk_3EFD618;
  j___Init_thread_header(&dword_3EFD61C);
  if ( dword_3EFD61C != -1 )
    return &unk_3EFD618;
  CGUIWrapper::CGUIWrapper((Replicator *)&unk_3EFD618);
  j___Init_thread_footer(&dword_3EFD61C);
  return &unk_3EFD618;
}


// address=[0x13d8810]
// Decompiled from CGUIWrapper *__thiscall CGUIWrapper::ReleaseGUIGFXFile(CGUIWrapper *this)

void  CGUIWrapper::ReleaseGUIGFXFile(void) {
  
  CGUIWrapper *result; // eax

  result = this;
  *(_DWORD *)this = -1;
  return result;
}


// address=[0x13d8830]
// Decompiled from char __thiscall CGUIWrapper::RebuildGuiEngineWithGfxFile(
        CGUIWrapper *this,
        unsigned int a2,
        int a3,
        int a4,
        bool (__cdecl *a5)(int, int, int))

bool  CGUIWrapper::RebuildGuiEngineWithGfxFile(unsigned int,void *,int,bool (__cdecl*)(int,int,int)) {
  
  int Language; // eax
  int DialogsRenderOffsetX; // [esp+18h] [ebp-2Ch]
  int DialogsRenderOffsetY; // [esp+1Ch] [ebp-28h]
  float DialogsRenderScaleX; // [esp+20h] [ebp-24h]
  float DialogsRenderScaleY; // [esp+24h] [ebp-20h]
  IGuiEngine *v11; // [esp+28h] [ebp-1Ch]
  IGuiEngine *C; // [esp+2Ch] [ebp-18h]

  if ( !g_pGfxManager )
    return 0;
  if ( !g_pGfxEngine )
    return 0;
  DialogsRenderOffsetX = 0;
  DialogsRenderOffsetY = 0;
  DialogsRenderScaleX = 0.0;
  DialogsRenderScaleY = 0.0;
  if ( g_pGUIEngine )
  {
    DialogsRenderOffsetX = IGuiEngine::GetDialogsRenderOffsetX((IGuiEngine *)g_pGUIEngine);
    DialogsRenderOffsetY = IGuiEngine::GetDialogsRenderOffsetY((IGuiEngine *)g_pGUIEngine);
    DialogsRenderScaleX = IGuiEngine::GetDialogsRenderScaleX((IGuiEngine *)g_pGUIEngine);
    DialogsRenderScaleY = IGuiEngine::GetDialogsRenderScaleY((IGuiEngine *)g_pGUIEngine);
    if ( g_pGUIEngine )
      IGuiEngine::`scalar deleting destructor'((IGuiEngine *)g_pGUIEngine, 1u);
    if ( CGfxManager::IsGfxFileEnabled((CGfxManager *)g_pGfxManager, *(_DWORD *)this) )
      CGfxManager::DisableGfxFile((CGfxManager *)g_pGfxManager, *(_DWORD *)this);
  }
  CGfxManager::EnableGfxFile((CGfxManager *)g_pGfxManager, a2, 9, 1, 0xFFFFFFFF);
  C = (IGuiEngine *)operator new(0x10u);
  if ( C )
    v11 = IGuiEngine::IGuiEngine(C);
  else
    v11 = 0;
  g_pGUIEngine = (int)v11;
  if ( !v11 )
    return 0;
  Language = CGameSettings::GetLanguage();
  if ( !IGuiEngine::Init(
          (IGuiEngine *)g_pGUIEngine,
          (struct IGfxEngine *)g_pGfxEngine,
          (struct CGfxManager *)g_pGfxManager,
          a3,
          a4,
          a5,
          Language) )
    return 0;
  IGuiEngine::CloseDialog((IGuiEngine *)g_pGUIEngine, a4);
  IGuiEngine::SetDialogsRenderOffset(
    (IGuiEngine *)g_pGUIEngine,
    DialogsRenderOffsetX,
    DialogsRenderOffsetY,
    DialogsRenderScaleX,
    DialogsRenderScaleY);
  *(_DWORD *)this = a2;
  return 1;
}


// address=[0x13d8a20]
// Decompiled from int __thiscall CGUIWrapper::GetActiveGUIGFXFile(CGUIWrapper *this)

unsigned int  CGUIWrapper::GetActiveGUIGFXFile(void) {
  
  if ( g_pGfxManager )
    return *(_DWORD *)this;
  *(_DWORD *)this = -1;
  return -1;
}


// address=[0x13d8a50]
// Decompiled from CGUIWrapper *__thiscall CGUIWrapper::CGUIWrapper(CGUIWrapper *this)

 CGUIWrapper::CGUIWrapper(void) {
  
  *(_DWORD *)this = -1;
  return this;
}


