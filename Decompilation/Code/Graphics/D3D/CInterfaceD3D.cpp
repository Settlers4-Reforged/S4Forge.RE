#include "CInterfaceD3D.h"

// Definitions for class CInterfaceD3D

// address=[0x2f5f250]
// Decompiled from void __thiscall CInterfaceD3D::BlitCursor(CInterfaceD3D *this)

void  CInterfaceD3D::BlitCursor(void) {
  
  int v1; // [esp+0h] [ebp-8h]
  int v2; // [esp+0h] [ebp-8h]

  v1 = CFixCursor::Show((CFixCursor *)&this->MoveCursor, (struct CSurface *)this->FinalRenderSurface);
  if ( v1 )
    WriteError(v1, "BlitMoveCursor");
  v2 = CFixCursor::Show((CFixCursor *)&this->ZoomCursor, (struct CSurface *)this->FinalRenderSurface);
  this->field_743 = 1;
  if ( v2 )
    WriteError(v2, "BlitZoomCursor");
}


// address=[0x2f5f390]
// Decompiled from bool __thiscall CInterfaceD3D::HasCameraWindowSurface(CInterfaceD3D *this)

bool  CInterfaceD3D::HasCameraWindowSurface(void)const {
  
  return this->field_5C != 0;
}


// address=[0x2f62860]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::CInterfaceD3D(CInterfaceD3D *this)

 CInterfaceD3D::CInterfaceD3D(void) {
  
  unsigned int i; // [esp+4h] [ebp-14h]
  int j; // [esp+4h] [ebp-14h]
  int k; // [esp+4h] [ebp-14h]

  SurfaceClipper::SurfaceClipper((SurfaceClipper *)&this->Clipper1);
  SurfaceClipper::SurfaceClipper((SurfaceClipper *)&this->MinimapClipper);
  CFixCursor::CFixCursor((CFixCursor *)&this->MoveCursor);
  CFixCursor::CFixCursor((CFixCursor *)&this->ZoomCursor);
  this->field_73C = 2000;
  this->field_743 = 0;
  this->IsForceBlit = 0;
  this->IsHQTextureSet = 0;
  this->field_734 = 0;
  this->field_448 = 0;
  this->field_740 = 0;
  this->field_730 = 0;
  this->field_72C = 0;
  j__memset(this->field_71E, 0, sizeof(this->field_71E));
  this->field_71D = 0;
  this->field_71C = 0;
  this->field_723 = 1;
  dword_3E2E2B8 = 0;
  for ( i = 0; i < 14; ++i )
    this->field_138[i] = 0;
  CInterfaceD3D::InitTexturedLandscapeModule(this);
  this->DDraw = 0;
  this->DDraw7 = 0;
  this->ZoomCursorSurface = 0;
  this->MoveCursorSurface = 0;
  this->field_68 = 0;
  this->MiniMapAreaSurface = 0;
  this->MiniMapSurface = 0;
  this->LandscapeSurface = 0;
  this->field_5C = 0;
  this->LandscapeSurface2 = 0;
  this->FinalRenderSurface = 0;
  this->PrimarySurface = 0;
  this->LandscapeRenderDevice = 0;
  this->LandscapeSurfacePtr = 0;
  this->field_38 = 0;
  this->field_0 = 0;
  for ( j = 0; j < 2; ++j )
  {
    this->LandscapeTextureTable[j + 44] = 0;
    this->LandscapeTextureTable[j + 46] = 0;
    this->CCachePageManager[j] = 0;
  }
  for ( k = 0; k < 180; ++k )
  {
    this->field_178[k] = 0;
    this->field_44C[k] = 0;
  }
  BBSupportTracePrintF(1, "GFX ENGINE: DD interface successfully created!");
  return this;
}


// address=[0x2f62b00]
// Decompiled from void __thiscall CInterfaceD3D::~CInterfaceD3D(CInterfaceD3D *this)

 CInterfaceD3D::~CInterfaceD3D(void) {
  
  CUploadCachePageManager *v1; // [esp+7Ch] [ebp-50h]
  CCachePageManager *v2; // [esp+80h] [ebp-4Ch]
  void (__thiscall ***v3)(_DWORD, int); // [esp+84h] [ebp-48h]
  CSurfaceV7 *PrimarySurface; // [esp+88h] [ebp-44h]
  CSurfaceV7 *MiniMapAreaSurface; // [esp+8Ch] [ebp-40h]
  CSurfaceV7 *MiniMapSurface; // [esp+90h] [ebp-3Ch]
  CSurfaceV7 *FinalRenderSurface; // [esp+94h] [ebp-38h]
  CSurfaceV7 *LandscapeSurface; // [esp+98h] [ebp-34h]
  CSurfaceV7 *MoveCursorSurface; // [esp+9Ch] [ebp-30h]
  CSurfaceV7 *ZoomCursorSurface; // [esp+A0h] [ebp-2Ch]
  void (__thiscall ***v11)(_DWORD, int); // [esp+A4h] [ebp-28h]
  CSurfaceV7 *v12; // [esp+A8h] [ebp-24h]
  CSurfaceV7 *v13; // [esp+ACh] [ebp-20h]
  CSurfaceV7 *v14; // [esp+B0h] [ebp-1Ch]
  int k; // [esp+B4h] [ebp-18h]
  int i; // [esp+B8h] [ebp-14h]
  int j; // [esp+B8h] [ebp-14h]
  int m; // [esp+B8h] [ebp-14h]
  int n; // [esp+B8h] [ebp-14h]

  for ( i = 179; i >= 0; --i )
  {
    if ( this->field_44C[i] )
    {
      if ( CCachePageManager::IsVideoSurfaceLocked((CCachePageManager *)this->field_44C[i]) )
        CCachePageManager::UnlockVideoSurface((CCachePageManager *)this->field_44C[i]);
      if ( CCachePageManager::IsSourceSurfaceLocked((CCachePageManager *)this->field_44C[i]) )
        CCachePageManager::UnlockSourceSurface((CCachePageManager *)this->field_44C[i]);
      v2 = (CCachePageManager *)this->field_44C[i];
      if ( v2 )
        CCachePageManager::`scalar deleting destructor'(v2, 1u);
      this->field_44C[i] = 0;
    }
    if ( this->field_178[i] )
    {
      (*(void (__stdcall **)(DWORD))(*(_DWORD *)this->field_178[i] + 8))(this->field_178[i]);
      this->field_178[i] = 0;
    }
  }
  for ( j = 1; j >= 0; --j )
  {
    if ( this->CCachePageManager[j] )
    {
      if ( CCachePageManager::IsVideoSurfaceLocked((CCachePageManager *)this->CCachePageManager[j]) )
        CCachePageManager::UnlockVideoSurface((CCachePageManager *)this->CCachePageManager[j]);
      if ( CCachePageManager::IsSourceSurfaceLocked((CCachePageManager *)this->CCachePageManager[j]) )
        CCachePageManager::UnlockSourceSurface((CCachePageManager *)this->CCachePageManager[j]);
      v1 = (CUploadCachePageManager *)this->CCachePageManager[j];
      if ( v1 )
        CUploadCachePageManager::`scalar deleting destructor'(v1, 1u);
      this->CCachePageManager[j] = 0;
    }
    if ( this->ObjectTextureSystemMemoryTable[j] )
    {
      ((void (__thiscall *)(CSurfaceV7 *))this->ObjectTextureSystemMemoryTable[j]->j_?Release@CSurfaceV7@@UAEXXZ)(this->ObjectTextureSystemMemoryTable[j]);
      v14 = this->ObjectTextureSystemMemoryTable[j];
      if ( v14 )
        ((void (__thiscall *)(CSurfaceV7 *, int))v14->j_??_GCSurfaceV7@@UAEPAXI@Z)(v14, 1);
      this->ObjectTextureSystemMemoryTable[j] = 0;
    }
    if ( this->ObjectTextureTable[j] )
    {
      ((void (__thiscall *)(CSurfaceV7 *))this->ObjectTextureTable[j]->j_?Release@CSurfaceV7@@UAEXXZ)(this->ObjectTextureTable[j]);
      v13 = this->ObjectTextureTable[j];
      if ( v13 )
        ((void (__thiscall *)(CSurfaceV7 *, int))v13->j_??_GCSurfaceV7@@UAEPAXI@Z)(v13, 1);
      this->ObjectTextureTable[j] = 0;
    }
  }
  if ( s_bCursorIsFixed )
  {
    ClipCursor(0);
    s_bCursorIsFixed = 0;
  }
  if ( !s_bCursorIsVisible )
  {
    ShowCursor(1);
    s_bCursorIsVisible = 1;
  }
  if ( s_hCursor )
  {
    SetClassLongA(hWnd, -12, s_hCursor);
    SetCursor((HCURSOR)s_hCursor);
    s_hCursor = 0;
  }
  SurfaceClipper::ReleaseClipper((SurfaceClipper *)&this->Clipper1);
  SurfaceClipper::ReleaseClipper((SurfaceClipper *)&this->MinimapClipper);
  if ( g_pSoftwareTexturePages )
  {
    operator delete[]((void *)g_pSoftwareTexturePages);
    g_pSoftwareTexturePages = 0;
    for ( k = 0; k < 44; ++k )
      g_pTextureTable[k] = 0;
  }
  for ( m = 43; m >= 0; --m )
  {
    if ( this->LandscapeTextureTable[m] )
    {
      ((void (__thiscall *)(CSurfaceV7 *))this->LandscapeTextureTable[m]->j_?Release@CSurfaceV7@@UAEXXZ)(this->LandscapeTextureTable[m]);
      v12 = this->LandscapeTextureTable[m];
      if ( v12 )
        ((void (__thiscall *)(CSurfaceV7 *, int))v12->j_??_GCSurfaceV7@@UAEPAXI@Z)(v12, 1);
      this->LandscapeTextureTable[m] = 0;
    }
    g_pTextureTable[m] = 0;
  }
  for ( n = 14; n >= 0; --n )
  {
    if ( this->field_138[n] )
    {
      (*(void (__thiscall **)(DWORD))(*(_DWORD *)this->field_138[n] + 4))(this->field_138[n]);
      v11 = (void (__thiscall ***)(_DWORD, int))this->field_138[n];
      if ( v11 )
        (**v11)(v11, 1);
      this->field_138[n] = 0;
    }
  }
  SurfaceClipper::ReleaseClipper((SurfaceClipper *)&this->Clipper1);
  SurfaceClipper::ReleaseClipper((SurfaceClipper *)&this->MinimapClipper);
  if ( this->field_38 )
    (*(void (__stdcall **)(int))(*(_DWORD *)this->field_38 + 8))(this->field_38);
  if ( this->LandscapeSurfacePtr )
    this->LandscapeSurfacePtr->lpVtbl->Release(this->LandscapeSurfacePtr);
  if ( this->ZoomCursorSurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->ZoomCursorSurface->j_?Release@CSurfaceV7@@UAEXXZ)(this->ZoomCursorSurface);
    ZoomCursorSurface = this->ZoomCursorSurface;
    if ( ZoomCursorSurface )
      ((void (__thiscall *)(CSurfaceV7 *, int))ZoomCursorSurface->j_??_GCSurfaceV7@@UAEPAXI@Z)(ZoomCursorSurface, 1);
    this->ZoomCursorSurface = 0;
  }
  if ( this->MoveCursorSurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->MoveCursorSurface->j_?Release@CSurfaceV7@@UAEXXZ)(this->MoveCursorSurface);
    MoveCursorSurface = this->MoveCursorSurface;
    if ( MoveCursorSurface )
      ((void (__thiscall *)(CSurfaceV7 *, int))MoveCursorSurface->j_??_GCSurfaceV7@@UAEPAXI@Z)(MoveCursorSurface, 1);
    this->MoveCursorSurface = 0;
  }
  if ( this->LandscapeSurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->LandscapeSurface->j_?Release@CSurfaceV7@@UAEXXZ)(this->LandscapeSurface);
    LandscapeSurface = this->LandscapeSurface;
    if ( LandscapeSurface )
      ((void (__thiscall *)(CSurfaceV7 *, int))LandscapeSurface->j_??_GCSurfaceV7@@UAEPAXI@Z)(LandscapeSurface, 1);
    this->LandscapeSurface = 0;
  }
  CInterfaceD3D::DestroyCameraWindowSurface(this);
  if ( this->FinalRenderSurface )
  {
    if ( !((unsigned __int8 (__thiscall *)(CSurfaceV7 *))this->FinalRenderSurface->j_?IsBackBufferReference@CSurfaceV7@@UAE_NXZ)(this->FinalRenderSurface) )
      ((void (__thiscall *)(CSurfaceV7 *))this->FinalRenderSurface->j_?Release@CSurfaceV7@@UAEXXZ)(this->FinalRenderSurface);
    FinalRenderSurface = this->FinalRenderSurface;
    if ( FinalRenderSurface )
      ((void (__thiscall *)(CSurfaceV7 *, int))FinalRenderSurface->j_??_GCSurfaceV7@@UAEPAXI@Z)(FinalRenderSurface, 1);
    this->FinalRenderSurface = 0;
  }
  if ( this->MiniMapSurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->MiniMapSurface->j_?Release@CSurfaceV7@@UAEXXZ)(this->MiniMapSurface);
    MiniMapSurface = this->MiniMapSurface;
    if ( MiniMapSurface )
      ((void (__thiscall *)(CSurfaceV7 *, int))MiniMapSurface->j_??_GCSurfaceV7@@UAEPAXI@Z)(MiniMapSurface, 1);
    this->MiniMapSurface = 0;
  }
  if ( this->MiniMapAreaSurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->MiniMapAreaSurface->j_?Release@CSurfaceV7@@UAEXXZ)(this->MiniMapAreaSurface);
    MiniMapAreaSurface = this->MiniMapAreaSurface;
    if ( MiniMapAreaSurface )
      ((void (__thiscall *)(CSurfaceV7 *, int))MiniMapAreaSurface->j_??_GCSurfaceV7@@UAEPAXI@Z)(MiniMapAreaSurface, 1);
    this->MiniMapAreaSurface = 0;
  }
  if ( this->PrimarySurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->PrimarySurface->j_?Release@CSurfaceV7@@UAEXXZ)(this->PrimarySurface);
    PrimarySurface = this->PrimarySurface;
    if ( PrimarySurface )
      ((void (__thiscall *)(CSurfaceV7 *, int))PrimarySurface->j_??_GCSurfaceV7@@UAEPAXI@Z)(PrimarySurface, 1);
    this->PrimarySurface = 0;
  }
  if ( this->field_68 )
  {
    v3 = (void (__thiscall ***)(_DWORD, int))this->field_68;
    if ( v3 )
      (**v3)(v3, 1);
    this->field_68 = 0;
  }
  if ( this->DDraw7 )
    this->DDraw7->lpVtbl->Release(this->DDraw7);
  if ( this->LandscapeRenderDevice )
    (*(void (__stdcall **)(int))(*(_DWORD *)this->LandscapeRenderDevice + 8))(this->LandscapeRenderDevice);
  this->DDraw = 0;
  this->DDraw7 = 0;
  this->LandscapeRenderDevice = 0;
  this->LandscapeSurfacePtr = 0;
  this->field_38 = 0;
  CInterfaceD3D::DeleteEngineData(this);
  BBSupportTracePrintF(1, "GFX ENGINE: DD interface successfully destroyed!");
  SurfaceClipper::~SurfaceClipper((SurfaceClipper *)&this->MinimapClipper);
  SurfaceClipper::~SurfaceClipper((SurfaceClipper *)&this->Clipper1);
}


// address=[0x2f63450]
// Decompiled from char __thiscall CInterfaceD3D::InitCommon(CInterfaceD3D *this)

bool  CInterfaceD3D::InitCommon(void) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned __int8 IsHardwareLandscapeEngine; // al
  unsigned __int8 HardwareLandscapeEngine2; // al
  struct IDirectDrawClipper *Clipper; // eax
  int v10; // [esp-10h] [ebp-78h]
  int v11; // [esp-10h] [ebp-78h]
  int HardwareLandscapeEngine; // [esp-8h] [ebp-70h]
  BOOL v14; // [esp+8h] [ebp-60h]
  IDirectDraw7 *v15; // [esp+Ch] [ebp-5Ch]
  IDirectDraw7 *v16; // [esp+14h] [ebp-54h]
  IDirectDraw7 *v17; // [esp+1Ch] [ebp-4Ch]
  IDirectDraw7 *v18; // [esp+2Ch] [ebp-3Ch]
  IDirectDraw7 *DDraw7; // [esp+3Ch] [ebp-2Ch]
  IDirectDraw7 *DDraw; // [esp+44h] [ebp-24h] MAPDST
  HRESULT (__stdcall *DirectDrawCreateEx)(GUID *, LPVOID *, const IID *const, IUnknown *); // [esp+4Ch] [ebp-1Ch]
  HMODULE hModule; // [esp+50h] [ebp-18h]
  int i; // [esp+58h] [ebp-10h]
  HRESULT v24; // [esp+5Ch] [ebp-Ch]
  HRESULT v25; // [esp+5Ch] [ebp-Ch]
  HRESULT v26; // [esp+5Ch] [ebp-Ch]
  int v27; // [esp+5Ch] [ebp-Ch]
  int v28; // [esp+5Ch] [ebp-Ch]
  int v29; // [esp+5Ch] [ebp-Ch]
  int v30; // [esp+5Ch] [ebp-Ch]
  int v31; // [esp+5Ch] [ebp-Ch]
  int v32; // [esp+5Ch] [ebp-Ch]
  int v33; // [esp+5Ch] [ebp-Ch]
  int v34; // [esp+5Ch] [ebp-Ch]
  int v35; // [esp+5Ch] [ebp-Ch]
  int v36; // [esp+5Ch] [ebp-Ch]
  int inited; // [esp+5Ch] [ebp-Ch]
  int v38; // [esp+5Ch] [ebp-Ch]
  int v39; // [esp+5Ch] [ebp-Ch]
  int v40; // [esp+5Ch] [ebp-Ch]
  char v42; // [esp+67h] [ebp-1h] BYREF

  BBSupportTracePrintF(1, "GFX ENGINE: Begin common init. Mode: Interface 7.");
  if ( this->field_71D || this->field_71C )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT COMMON: Engine is already initialized!");
    return 1;
  }
  this->IsHQTextureSet = SGfxRenderConfiguration::IsHQTextureSet((SGfxRenderConfiguration *)&GfxEngineSetup);
  this->IsForceBlit = !SGfxRenderConfiguration::IsForceBlit((SGfxRenderConfiguration *)&GfxEngineSetup);
  if ( s_hCursor )
  {
    SetClassLongA(hWnd, -12, s_hCursor);
    SetCursor((HCURSOR)s_hCursor);
    s_hCursor = 0;
  }
  s_bCursorIsVisible = 1;
  s_bCursorIsFixed = 0;
  s_iCurrentCursor = -1;
  s_hCursorHandles[0] = LoadCursorA(g_hInstance, (LPCSTR)0x65);
  s_hCursorHandles[1] = LoadCursorA(g_hInstance, (LPCSTR)0x66);
  s_hCursorHandles[2] = LoadCursorA(g_hInstance, (LPCSTR)0x6D);
  s_hCursorHandles[3] = LoadCursorA(g_hInstance, (LPCSTR)0x6E);
  s_hCursorHandles[4] = LoadCursorA(g_hInstance, (LPCSTR)0x6F);
  s_hCursorHandles[5] = LoadCursorA(g_hInstance, (LPCSTR)0x70);
  s_hCursorHandles[6] = LoadCursorA(g_hInstance, (LPCSTR)0x71);
  s_hCursorHandles[7] = LoadCursorA(g_hInstance, (LPCSTR)0x72);
  s_hCursorHandles[8] = LoadCursorA(g_hInstance, (LPCSTR)0x77);
  s_hCursorHandles[9] = LoadCursorA(g_hInstance, (LPCSTR)0x78);
  s_hCursorHandles[10] = LoadCursorA(g_hInstance, (LPCSTR)0x79);
  s_hCursorHandles[11] = LoadCursorA(g_hInstance, (LPCSTR)0x7A);
  s_hCursorHandles[12] = LoadCursorA(g_hInstance, (LPCSTR)0x7B);
  s_hCursorHandles[13] = LoadCursorA(g_hInstance, (LPCSTR)0x7C);
  s_hCursorHandles[14] = LoadCursorA(g_hInstance, (LPCSTR)0x7D);
  s_hCursorHandles[15] = LoadCursorA(g_hInstance, (LPCSTR)0x7E);
  s_hCursorHandles[16] = LoadCursorA(g_hInstance, (LPCSTR)0x7F);
  s_hCursorHandles[17] = LoadCursorA(g_hInstance, (LPCSTR)0x80);
  s_hCursorHandles[18] = LoadCursorA(g_hInstance, (LPCSTR)0x81);
  s_hCursorHandles[19] = LoadCursorA(g_hInstance, (LPCSTR)0x82);
  s_hCursorHandles[20] = LoadCursorA(g_hInstance, (LPCSTR)0x83);
  s_hCursorHandles[21] = LoadCursorA(g_hInstance, (LPCSTR)0x84);
  s_hCursorHandles[22] = LoadCursorA(g_hInstance, (LPCSTR)0x85);
  s_hCursorHandles[23] = LoadCursorA(g_hInstance, (LPCSTR)0x86);
  s_hCursorHandles[24] = LoadCursorA(g_hInstance, (LPCSTR)0x87);
  s_hCursorHandles[25] = LoadCursorA(g_hInstance, (LPCSTR)0x88);
  s_hCursorHandles[26] = LoadCursorA(g_hInstance, (LPCSTR)0x89);
  s_hCursorHandles[27] = LoadCursorA(g_hInstance, (LPCSTR)0x8B);
  s_hCursorHandles[28] = LoadCursorA(g_hInstance, (LPCSTR)0x8C);
  s_hCursorHandles[29] = LoadCursorA(g_hInstance, (LPCSTR)0x8D);
  s_hCursorHandles[30] = LoadCursorA(g_hInstance, (LPCSTR)0x8E);
  s_hCursorHandles[31] = LoadCursorA(g_hInstance, (LPCSTR)0x8F);
  s_hCursorHandles[32] = LoadCursorA(g_hInstance, (LPCSTR)0x90);
  s_hCursorHandles[33] = LoadCursorA(g_hInstance, (LPCSTR)0x91);
  s_hCursorHandles[34] = LoadCursorA(g_hInstance, (LPCSTR)0x92);
  s_hCursorHandles[35] = LoadCursorA(g_hInstance, (LPCSTR)0x93);
  for ( i = 0; i < 36; ++i )
  {
    if ( !s_hCursorHandles[i] )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Couldn't create cursors!");
      return 0;
    }
  }
  byte_3E2E30C = 1;
  this->field_68 = (int)CSurface::CreateSurfacePtr(byte_3E2E262);
  if ( !this->field_68 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
    return 0;
  }
  if ( g_pDirectDraw )
  {
    this->DDraw = (IDirectDraw7 *)g_pDirectDraw;
  }
  else
  {
    hModule = GetModuleHandleA("DDRAW");
    if ( !hModule )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Direct Draw is not accessible!");
      return 0;
    }
    DirectDrawCreateEx = (HRESULT (__stdcall *)(GUID *, LPVOID *, const IID *const, IUnknown *))GetProcAddress(
                                                                                                  hModule,
                                                                                                  "DirectDrawCreateEx");
    if ( !DirectDrawCreateEx )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: DirectDrawCreateEx not found! Interface 7 or higher not available!");
      return 0;
    }
    v24 = DirectDrawCreateEx(0, (LPVOID *)&this->DDraw, &IID_IDirectDraw7, 0);
    if ( v24 )
    {
      WriteError(v24, "CreateDirectDrawObject");
      return 0;
    }
    g_pDirectDraw = (int)this->DDraw;
  }
  v25 = this->DDraw->lpVtbl->QueryInterface(this->DDraw, &IID_IDirectDraw7, (LPVOID *)&this->DDraw7);
  if ( v25 )
  {
    WriteError(v25, "QueryInterface");
    return 0;
  }
  else
  {
    v26 = this->DDraw7->lpVtbl->SetCooperativeLevel(this->DDraw7, hWnd, 8);
    if ( v26 )
    {
      WriteError(v26, "SetCooperativeLevel");
      return 0;
    }
    else
    {
      this->PrimarySurface = CSurface::CreateSurfacePtr(byte_3E2E262);
      if ( this->PrimarySurface )
      {
        if ( byte_3E2E262 )
          DDraw = this->DDraw;
        else
          DDraw = this->DDraw7;
        v2 = j__abs(dword_3E2E2B8 == 1);
        v27 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, int, _DWORD, _DWORD))this->PrimarySurface->CreateSurface)(
                this->PrimarySurface,
                DDraw,
                OutputWidth,
                OutputHeight,
                1,
                0,
                0,
                v2,
                1,
                0,
                0);
        if ( v27 )
        {
          WriteError(v27, "CreatePrimarySurface");
          return 0;
        }
        else
        {
          v28 = ((int (__thiscall *)(CSurfaceV7 *, char *))this->PrimarySurface->GetPixelFormat)(
                  this->PrimarySurface,
                  &v42);
          if ( v28 )
          {
            WriteError(v28, "RetrievePixelFormatFromPrimarySurface");
            return 0;
          }
          else
          {
            if ( v42 )
              dword_3E2E2B8 = 1;
            else
              dword_3E2E2B8 = 2;
            this->MoveCursorSurface = CSurface::CreateSurfacePtr(byte_3E2E262);
            if ( this->MoveCursorSurface )
            {
              if ( byte_3E2E262 )
                DDraw7 = this->DDraw;
              else
                DDraw7 = this->DDraw7;
              v3 = j__abs(dword_3E2E2B8 == 1);
              v29 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))this->MoveCursorSurface->CreateSurface)(
                      this->MoveCursorSurface,
                      DDraw7,
                      32,
                      32,
                      1,
                      0,
                      0,
                      v3,
                      0,
                      0,
                      0);
              if ( v29 )
              {
                WriteError(v29, "CreateMoveCursorSurface");
                return 0;
              }
              else
              {
                if ( dword_3E2E2B8 == 1 )
                  CFixCursor::SetSurfacePtr(
                    (CFixCursor *)&this->MoveCursor,
                    0x73u,
                    (struct CSurface *)this->MoveCursorSurface,
                    g_sColorKeyMagenta555);
                else
                  CFixCursor::SetSurfacePtr(
                    (CFixCursor *)&this->MoveCursor,
                    0x73u,
                    (struct CSurface *)this->MoveCursorSurface,
                    g_sColorKeyMagenta565);
                if ( dword_3E2E2B8 == 1 )
                  ((void (__thiscall *)(CSurfaceV7 *, int, int *))this->MoveCursorSurface->SetColorKey)(
                    this->MoveCursorSurface,
                    8,
                    &g_sColorKeyMagenta555);
                else
                  ((void (__thiscall *)(CSurfaceV7 *, int, int *))this->MoveCursorSurface->SetColorKey)(
                    this->MoveCursorSurface,
                    8,
                    &g_sColorKeyMagenta565);
                this->ZoomCursorSurface = CSurface::CreateSurfacePtr(byte_3E2E262);
                if ( this->ZoomCursorSurface )
                {
                  if ( byte_3E2E262 )
                    v18 = this->DDraw;
                  else
                    v18 = this->DDraw7;
                  v4 = j__abs(dword_3E2E2B8 == 1);
                  v30 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))this->ZoomCursorSurface->CreateSurface)(
                          this->ZoomCursorSurface,
                          v18,
                          32,
                          32,
                          1,
                          0,
                          0,
                          v4,
                          0,
                          0,
                          0);
                  if ( v30 )
                  {
                    WriteError(v30, "CreateZoomCursorSurface");
                    return 0;
                  }
                  else
                  {
                    if ( dword_3E2E2B8 == 1 )
                      CFixCursor::SetSurfacePtr(
                        (CFixCursor *)&this->ZoomCursor,
                        0x74u,
                        (struct CSurface *)this->ZoomCursorSurface,
                        g_sColorKeyMagenta555);
                    else
                      CFixCursor::SetSurfacePtr(
                        (CFixCursor *)&this->ZoomCursor,
                        0x74u,
                        (struct CSurface *)this->ZoomCursorSurface,
                        g_sColorKeyMagenta565);
                    if ( dword_3E2E2B8 == 1 )
                      ((void (__thiscall *)(CSurfaceV7 *, int, int *))this->ZoomCursorSurface->SetColorKey)(
                        this->ZoomCursorSurface,
                        8,
                        &g_sColorKeyMagenta555);
                    else
                      ((void (__thiscall *)(CSurfaceV7 *, int, int *))this->ZoomCursorSurface->SetColorKey)(
                        this->ZoomCursorSurface,
                        8,
                        &g_sColorKeyMagenta565);
                    this->MiniMapSurface = CSurface::CreateSurfacePtr(byte_3E2E262);
                    if ( this->MiniMapSurface )
                    {
                      if ( byte_3E2E262 )
                        v17 = this->DDraw;
                      else
                        v17 = this->DDraw7;
                      v5 = j__abs(dword_3E2E2B8 == 1);
                      v31 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))this->MiniMapSurface->CreateSurface)(
                              this->MiniMapSurface,
                              v17,
                              240,
                              160,
                              1,
                              0,
                              0,
                              v5,
                              0,
                              0,
                              0);
                      if ( v31 )
                      {
                        WriteError(v31, "CreateMiniMapSurface");
                        return 0;
                      }
                      else
                      {
                        ((void (__thiscall *)(CSurfaceV7 *, _DWORD))this->MiniMapSurface->ClearSurface)(
                          this->MiniMapSurface,
                          0);
                        ((void (__thiscall *)(CSurfaceV7 *, int, void *))this->MiniMapSurface->SetColorKey)(
                          this->MiniMapSurface,
                          8,
                          &g_sColorKeyBlack);
                        this->MiniMapAreaSurface = CSurface::CreateSurfacePtr(byte_3E2E262);
                        if ( this->MiniMapAreaSurface )
                        {
                          if ( byte_3E2E262 )
                            v16 = this->DDraw;
                          else
                            v16 = this->DDraw7;
                          v6 = j__abs(dword_3E2E2B8 == 1);
                          v32 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))this->MiniMapAreaSurface->CreateSurface)(
                                  this->MiniMapAreaSurface,
                                  v16,
                                  240,
                                  160,
                                  1,
                                  0,
                                  0,
                                  v6,
                                  0,
                                  0,
                                  0);
                          if ( v32 )
                          {
                            WriteError(v32, "CreateMiniMapAreaSurface");
                            return 0;
                          }
                          else
                          {
                            v33 = ((int (__thiscall *)(CSurfaceV7 *, _DWORD))this->MiniMapAreaSurface->ClearSurface)(
                                    this->MiniMapAreaSurface,
                                    0);
                            if ( v33 )
                              WriteError(v33, "ClearMiniMapSurface");
                            v34 = ((int (__thiscall *)(CSurfaceV7 *, int, void *))this->MiniMapAreaSurface->SetColorKey)(
                                    this->MiniMapAreaSurface,
                                    8,
                                    &g_sColorKeyBlack);
                            if ( v34 )
                              WriteError(v34, "SetMiniMapColorKey");
                            BBSupportTracePrintF(
                              1,
                              "GFX ENGINE: Size of render surface: %d x %d",
                              OutputWidth,
                              OutputHeight);
                            this->LandscapeSurface = CSurface::CreateSurfacePtr(byte_3E2E262);
                            if ( this->LandscapeSurface )
                            {
                              if ( byte_3E2E262 )
                                v15 = this->DDraw;
                              else
                                v15 = this->DDraw7;
                              v10 = j__abs(dword_3E2E2B8 == 1);
                              IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup);
                              v35 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))this->LandscapeSurface->CreateSurface)(
                                      this->LandscapeSurface,
                                      v15,
                                      OutputWidth,
                                      OutputHeight,
                                      1,
                                      IsHardwareLandscapeEngine,
                                      0,
                                      v10,
                                      0,
                                      0,
                                      0);
                              if ( v35 )
                              {
                                WriteError(v35, "CreateLandscapeSurface");
                                return 0;
                              }
                              else
                              {
                                this->LandscapeSurface2 = (int)this->LandscapeSurface;
                                this->FinalRenderSurface = CSurface::CreateSurfacePtr(byte_3E2E262);
                                if ( this->FinalRenderSurface )
                                {
                                  v14 = dword_3E2E2B8 == 1;
                                  if ( byte_3E2E262 )
                                    DDraw = this->DDraw;
                                  else
                                    DDraw = this->DDraw7;
                                  HardwareLandscapeEngine = (unsigned __int8)SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup);
                                  v11 = j__abs(v14);
                                  HardwareLandscapeEngine2 = SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup);
                                  v36 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, int, _DWORD))this->FinalRenderSurface->CreateSurface)(
                                          this->FinalRenderSurface,
                                          DDraw,
                                          OutputWidth,
                                          OutputHeight,
                                          1,
                                          HardwareLandscapeEngine2,
                                          0,
                                          v11,
                                          0,
                                          HardwareLandscapeEngine,
                                          0);
                                  if ( v36 )
                                  {
                                    WriteError(v36, "CreateFinalRenderSurface");
                                    return 0;
                                  }
                                  else
                                  {
                                    inited = SurfaceClipper::InitClipper(
                                               (SurfaceClipper *)&this->Clipper1,
                                               this->DDraw7);
                                    if ( inited )
                                    {
                                      WriteError(inited, "CreateClipper1");
                                      return 0;
                                    }
                                    else
                                    {
                                      v38 = SurfaceClipper::InitClipper(
                                              (SurfaceClipper *)&this->MinimapClipper,
                                              this->DDraw7);
                                      if ( v38 )
                                      {
                                        WriteError(v38, "Create Minimap Clipper");
                                        return 0;
                                      }
                                      else
                                      {
                                        v39 = SurfaceClipper::SetClipWindow((SurfaceClipper *)&this->Clipper1, hWnd);
                                        if ( v39 )
                                        {
                                          WriteError(v39, "AssignClipper1");
                                          return 0;
                                        }
                                        else
                                        {
                                          Clipper = SurfaceClipper::GetClipper((SurfaceClipper *)&this->Clipper1);
                                          v40 = ((int (__thiscall *)(CSurfaceV7 *, struct IDirectDrawClipper *))this->PrimarySurface->SetClipper)(
                                                  this->PrimarySurface,
                                                  Clipper);
                                          if ( v40 )
                                          {
                                            WriteError(v40, "SetClipper1");
                                            return 0;
                                          }
                                          else
                                          {
                                            g_pDestSizeTable = (int)&g_iDestSizeTable;
                                            g_pZoomGradient = (int)&g_iZoomGradient;
                                            BBSupportTracePrintF(1, "GFX ENGINE: Common init ok.");
                                            return 1;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                                else
                                {
                                  BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                                  return 0;
                                }
                              }
                            }
                            else
                            {
                              BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                              return 0;
                            }
                          }
                        }
                        else
                        {
                          BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                          return 0;
                        }
                      }
                    }
                    else
                    {
                      BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                      return 0;
                    }
                  }
                }
                else
                {
                  BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                  return 0;
                }
              }
            }
            else
            {
              BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
              return 0;
            }
          }
        }
      }
      else
      {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
      }
    }
  }
}


// address=[0x2f643e0]
// Decompiled from char __thiscall CInterfaceD3D::InitCommonV3(CInterfaceD3D *this)

bool  CInterfaceD3D::InitCommonV3(void) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned __int8 IsHardwareLandscapeEngine; // al
  unsigned __int8 v8; // al
  struct IDirectDrawClipper *Clipper; // eax
  int v10; // [esp-10h] [ebp-6Ch]
  int v11; // [esp-10h] [ebp-6Ch]
  int v12; // [esp-8h] [ebp-64h]
  int v13; // [esp+0h] [ebp-5Ch] BYREF
  IDirectDraw7 *v14; // [esp+4h] [ebp-58h]
  int v15; // [esp+8h] [ebp-54h]
  IDirectDraw7 *v16; // [esp+Ch] [ebp-50h]
  int v17; // [esp+10h] [ebp-4Ch]
  IDirectDraw7 *v18; // [esp+14h] [ebp-48h]
  int v19; // [esp+18h] [ebp-44h]
  IDirectDraw7 *v20; // [esp+1Ch] [ebp-40h]
  int v21; // [esp+20h] [ebp-3Ch]
  int *v22; // [esp+24h] [ebp-38h]
  int v23; // [esp+28h] [ebp-34h]
  IDirectDraw7 *v24; // [esp+2Ch] [ebp-30h]
  int v25; // [esp+30h] [ebp-2Ch]
  int *v26; // [esp+34h] [ebp-28h]
  int v27; // [esp+38h] [ebp-24h]
  IDirectDraw7 *DDraw7; // [esp+3Ch] [ebp-20h]
  int v29; // [esp+40h] [ebp-1Ch]
  IDirectDraw7 *DDraw; // [esp+44h] [ebp-18h]
  int Number; // [esp+48h] [ebp-14h]
  int i; // [esp+4Ch] [ebp-10h]
  HRESULT inited; // [esp+50h] [ebp-Ch]
  CInterfaceD3D *v34; // [esp+54h] [ebp-8h]
  char v35; // [esp+5Bh] [ebp-1h] BYREF

  v34 = this;
  BBSupportTracePrintF(1, "GFX ENGINE: Begin common init. Mode: Interface 3.");
  if ( v34->field_71D || v34->field_71C )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT COMMON: Engine is already initialized!");
    return 1;
  }
  v34->IsHQTextureSet = SGfxRenderConfiguration::IsHQTextureSet((SGfxRenderConfiguration *)&GfxEngineSetup);
  v34->IsForceBlit = 0;
  if ( s_hCursor )
  {
    SetClassLongA(hWnd, -12, s_hCursor);
    SetCursor((HCURSOR)s_hCursor);
    s_hCursor = 0;
  }
  s_bCursorIsVisible = 1;
  s_bCursorIsFixed = 0;
  s_iCurrentCursor = -1;
  s_hCursorHandles[0] = LoadCursorA(g_hInstance, (LPCSTR)0x65);
  s_hCursorHandles[1] = LoadCursorA(g_hInstance, (LPCSTR)0x66);
  s_hCursorHandles[2] = LoadCursorA(g_hInstance, (LPCSTR)0x6D);
  s_hCursorHandles[3] = LoadCursorA(g_hInstance, (LPCSTR)0x6E);
  s_hCursorHandles[4] = LoadCursorA(g_hInstance, (LPCSTR)0x6F);
  s_hCursorHandles[5] = LoadCursorA(g_hInstance, (LPCSTR)0x70);
  s_hCursorHandles[6] = LoadCursorA(g_hInstance, (LPCSTR)0x71);
  s_hCursorHandles[7] = LoadCursorA(g_hInstance, (LPCSTR)0x72);
  s_hCursorHandles[8] = LoadCursorA(g_hInstance, (LPCSTR)0x77);
  s_hCursorHandles[9] = LoadCursorA(g_hInstance, (LPCSTR)0x78);
  s_hCursorHandles[10] = LoadCursorA(g_hInstance, (LPCSTR)0x79);
  s_hCursorHandles[11] = LoadCursorA(g_hInstance, (LPCSTR)0x7A);
  s_hCursorHandles[12] = LoadCursorA(g_hInstance, (LPCSTR)0x7B);
  s_hCursorHandles[13] = LoadCursorA(g_hInstance, (LPCSTR)0x7C);
  s_hCursorHandles[14] = LoadCursorA(g_hInstance, (LPCSTR)0x7D);
  s_hCursorHandles[15] = LoadCursorA(g_hInstance, (LPCSTR)0x7E);
  s_hCursorHandles[16] = LoadCursorA(g_hInstance, (LPCSTR)0x7F);
  s_hCursorHandles[17] = LoadCursorA(g_hInstance, (LPCSTR)0x80);
  s_hCursorHandles[18] = LoadCursorA(g_hInstance, (LPCSTR)0x81);
  s_hCursorHandles[19] = LoadCursorA(g_hInstance, (LPCSTR)0x82);
  s_hCursorHandles[20] = LoadCursorA(g_hInstance, (LPCSTR)0x83);
  s_hCursorHandles[21] = LoadCursorA(g_hInstance, (LPCSTR)0x84);
  s_hCursorHandles[22] = LoadCursorA(g_hInstance, (LPCSTR)0x85);
  s_hCursorHandles[23] = LoadCursorA(g_hInstance, (LPCSTR)0x86);
  s_hCursorHandles[24] = LoadCursorA(g_hInstance, (LPCSTR)0x87);
  s_hCursorHandles[25] = LoadCursorA(g_hInstance, (LPCSTR)0x88);
  s_hCursorHandles[26] = LoadCursorA(g_hInstance, (LPCSTR)0x89);
  s_hCursorHandles[27] = LoadCursorA(g_hInstance, (LPCSTR)0x8B);
  s_hCursorHandles[28] = LoadCursorA(g_hInstance, (LPCSTR)0x8C);
  s_hCursorHandles[29] = LoadCursorA(g_hInstance, (LPCSTR)0x8D);
  s_hCursorHandles[30] = LoadCursorA(g_hInstance, (LPCSTR)0x8E);
  s_hCursorHandles[31] = LoadCursorA(g_hInstance, (LPCSTR)0x8F);
  s_hCursorHandles[32] = LoadCursorA(g_hInstance, (LPCSTR)0x90);
  s_hCursorHandles[33] = LoadCursorA(g_hInstance, (LPCSTR)0x91);
  s_hCursorHandles[34] = LoadCursorA(g_hInstance, (LPCSTR)0x92);
  s_hCursorHandles[35] = LoadCursorA(g_hInstance, (LPCSTR)0x93);
  for ( i = 0; i < 36; ++i )
  {
    if ( !s_hCursorHandles[i] )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Couldn't create cursors!");
      return 0;
    }
  }
  byte_3E2E30C = 1;
  v34->field_68 = (int)CSurface::CreateSurfacePtr(byte_3E2E262);
  if ( !v34->field_68 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
    return 0;
  }
  if ( g_pDirectDraw )
  {
    v34->DDraw = (IDirectDraw7 *)g_pDirectDraw;
  }
  else
  {
    inited = DirectDrawCreate(0, (LPDIRECTDRAW *)&v34->DDraw, 0);
    if ( inited )
    {
      WriteError(inited, "CreateDirectDrawObject");
      return 0;
    }
    g_pDirectDraw = (int)v34->DDraw;
  }
  inited = v34->DDraw->lpVtbl->SetCooperativeLevel(v34->DDraw, hWnd, 8);
  if ( inited )
  {
    WriteError(inited, "SetCooperativeLevel");
    return 0;
  }
  else
  {
    v34->PrimarySurface = CSurface::CreateSurfacePtr(byte_3E2E262);
    if ( v34->PrimarySurface )
    {
      Number = dword_3E2E2B8 == 1;
      if ( byte_3E2E262 )
        DDraw = v34->DDraw;
      else
        DDraw = v34->DDraw7;
      v2 = j__abs(Number);
      inited = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, int, _DWORD, _DWORD))v34->PrimarySurface->CreateSurface)(
                 v34->PrimarySurface,
                 DDraw,
                 OutputWidth,
                 OutputHeight,
                 1,
                 0,
                 0,
                 v2,
                 1,
                 0,
                 0);
      if ( inited )
      {
        WriteError(inited, "CreatePrimarySurface");
        return 0;
      }
      else
      {
        inited = ((int (__thiscall *)(CSurfaceV7 *, int *))v34->PrimarySurface->j_?GetBitDepth@CSurfaceV7@@UAEJAAH@Z)(
                   v34->PrimarySurface,
                   &v13);
        if ( inited )
        {
          WriteError(inited, "RetrieveBitDepth");
          return 0;
        }
        else if ( v13 == 16 )
        {
          inited = ((int (__thiscall *)(CSurfaceV7 *, char *))v34->PrimarySurface->GetPixelFormat)(
                     v34->PrimarySurface,
                     &v35);
          if ( inited )
          {
            WriteError(inited, "RetrievePixelFormatFromPrimarySurface");
            return 0;
          }
          else
          {
            if ( v35 )
              dword_3E2E2B8 = 1;
            else
              dword_3E2E2B8 = 2;
            v34->MoveCursorSurface = CSurface::CreateSurfacePtr(byte_3E2E262);
            if ( v34->MoveCursorSurface )
            {
              v29 = dword_3E2E2B8 == 1;
              if ( byte_3E2E262 )
                DDraw7 = v34->DDraw;
              else
                DDraw7 = v34->DDraw7;
              v3 = j__abs(v29);
              inited = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))v34->MoveCursorSurface->CreateSurface)(
                         v34->MoveCursorSurface,
                         DDraw7,
                         32,
                         32,
                         1,
                         0,
                         0,
                         v3,
                         0,
                         0,
                         0);
              if ( inited )
              {
                WriteError(inited, "CreateMoveCursorSurface");
                return 0;
              }
              else
              {
                if ( dword_3E2E2B8 == 1 )
                  v27 = g_sColorKeyMagenta555;
                else
                  v27 = g_sColorKeyMagenta565;
                CFixCursor::SetSurfacePtr(
                  (CFixCursor *)&v34->MoveCursor,
                  0x73u,
                  (struct CSurface *)v34->MoveCursorSurface,
                  v27);
                if ( dword_3E2E2B8 == 1 )
                  v26 = &g_sColorKeyMagenta555;
                else
                  v26 = &g_sColorKeyMagenta565;
                ((void (__thiscall *)(CSurfaceV7 *, int, int *))v34->MoveCursorSurface->SetColorKey)(
                  v34->MoveCursorSurface,
                  8,
                  v26);
                v34->ZoomCursorSurface = CSurface::CreateSurfacePtr(byte_3E2E262);
                if ( v34->ZoomCursorSurface )
                {
                  v25 = dword_3E2E2B8 == 1;
                  if ( byte_3E2E262 )
                    v24 = v34->DDraw;
                  else
                    v24 = v34->DDraw7;
                  v4 = j__abs(v25);
                  inited = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))v34->ZoomCursorSurface->CreateSurface)(
                             v34->ZoomCursorSurface,
                             v24,
                             32,
                             32,
                             1,
                             0,
                             0,
                             v4,
                             0,
                             0,
                             0);
                  if ( inited )
                  {
                    WriteError(inited, "CreationZoomCursorSurface");
                    return 0;
                  }
                  else
                  {
                    if ( dword_3E2E2B8 == 1 )
                      v23 = g_sColorKeyMagenta555;
                    else
                      v23 = g_sColorKeyMagenta565;
                    CFixCursor::SetSurfacePtr(
                      (CFixCursor *)&v34->ZoomCursor,
                      0x74u,
                      (struct CSurface *)v34->ZoomCursorSurface,
                      v23);
                    if ( dword_3E2E2B8 == 1 )
                      v22 = &g_sColorKeyMagenta555;
                    else
                      v22 = &g_sColorKeyMagenta565;
                    ((void (__thiscall *)(CSurfaceV7 *, int, int *))v34->ZoomCursorSurface->SetColorKey)(
                      v34->ZoomCursorSurface,
                      8,
                      v22);
                    v34->MiniMapSurface = CSurface::CreateSurfacePtr(byte_3E2E262);
                    if ( v34->MiniMapSurface )
                    {
                      v21 = dword_3E2E2B8 == 1;
                      if ( byte_3E2E262 )
                        v20 = v34->DDraw;
                      else
                        v20 = v34->DDraw7;
                      v5 = j__abs(v21);
                      inited = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))v34->MiniMapSurface->CreateSurface)(
                                 v34->MiniMapSurface,
                                 v20,
                                 240,
                                 160,
                                 1,
                                 0,
                                 0,
                                 v5,
                                 0,
                                 0,
                                 0);
                      if ( inited )
                      {
                        WriteError(inited, "CreateMiniMapSurface");
                        return 0;
                      }
                      else
                      {
                        ((void (__thiscall *)(CSurfaceV7 *, _DWORD))v34->MiniMapSurface->ClearSurface)(
                          v34->MiniMapSurface,
                          0);
                        ((void (__thiscall *)(CSurfaceV7 *, int, void *))v34->MiniMapSurface->SetColorKey)(
                          v34->MiniMapSurface,
                          8,
                          &g_sColorKeyBlack);
                        v34->MiniMapAreaSurface = CSurface::CreateSurfacePtr(byte_3E2E262);
                        if ( v34->MiniMapAreaSurface )
                        {
                          v19 = dword_3E2E2B8 == 1;
                          if ( byte_3E2E262 )
                            v18 = v34->DDraw;
                          else
                            v18 = v34->DDraw7;
                          v6 = j__abs(v19);
                          inited = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))v34->MiniMapAreaSurface->CreateSurface)(
                                     v34->MiniMapAreaSurface,
                                     v18,
                                     240,
                                     160,
                                     1,
                                     0,
                                     0,
                                     v6,
                                     0,
                                     0,
                                     0);
                          if ( inited )
                          {
                            WriteError(inited, "CreateMiniMapAreaSurface");
                            return 0;
                          }
                          else
                          {
                            inited = ((int (__thiscall *)(CSurfaceV7 *, _DWORD))v34->MiniMapAreaSurface->ClearSurface)(
                                       v34->MiniMapAreaSurface,
                                       0);
                            if ( inited )
                              WriteError(inited, "ClearMiniMapSurface");
                            inited = ((int (__thiscall *)(CSurfaceV7 *, int, void *))v34->MiniMapAreaSurface->SetColorKey)(
                                       v34->MiniMapAreaSurface,
                                       8,
                                       &g_sColorKeyBlack);
                            if ( inited )
                              WriteError(inited, "SetMiniMapColorKey");
                            BBSupportTracePrintF(
                              1,
                              "GFX ENGINE: Size of render surface: %d x %d",
                              OutputWidth,
                              OutputHeight);
                            v34->LandscapeSurface = CSurface::CreateSurfacePtr(byte_3E2E262);
                            if ( v34->LandscapeSurface )
                            {
                              v17 = dword_3E2E2B8 == 1;
                              if ( byte_3E2E262 )
                                v16 = v34->DDraw;
                              else
                                v16 = v34->DDraw7;
                              v10 = j__abs(v17);
                              IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup);
                              inited = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))v34->LandscapeSurface->CreateSurface)(
                                         v34->LandscapeSurface,
                                         v16,
                                         OutputWidth,
                                         OutputHeight,
                                         1,
                                         IsHardwareLandscapeEngine,
                                         0,
                                         v10,
                                         0,
                                         0,
                                         0);
                              if ( inited )
                              {
                                WriteError(inited, "CreateLandscapeSurface");
                                return 0;
                              }
                              else
                              {
                                v34->LandscapeSurface2 = v34->LandscapeSurface;
                                v34->FinalRenderSurface = CSurface::CreateSurfacePtr(byte_3E2E262);
                                if ( v34->FinalRenderSurface )
                                {
                                  v15 = dword_3E2E2B8 == 1;
                                  if ( byte_3E2E262 )
                                    v14 = v34->DDraw;
                                  else
                                    v14 = v34->DDraw7;
                                  v12 = (unsigned __int8)SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup);
                                  v11 = j__abs(v15);
                                  v8 = SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup);
                                  inited = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, int, _DWORD))v34->FinalRenderSurface->CreateSurface)(
                                             v34->FinalRenderSurface,
                                             v14,
                                             OutputWidth,
                                             OutputHeight,
                                             1,
                                             v8,
                                             0,
                                             v11,
                                             0,
                                             v12,
                                             0);
                                  if ( inited )
                                  {
                                    WriteError(inited, "CreateFinalRenderSurface");
                                    return 0;
                                  }
                                  else
                                  {
                                    inited = SurfaceClipper::InitClipper((SurfaceClipper *)&v34->Clipper1, v34->DDraw);
                                    if ( inited )
                                    {
                                      WriteError(inited, "CreateClipper1");
                                      return 0;
                                    }
                                    else
                                    {
                                      inited = SurfaceClipper::InitClipper(
                                                 (SurfaceClipper *)&v34->MinimapClipper,
                                                 v34->DDraw);
                                      if ( inited )
                                      {
                                        WriteError(inited, "Create Minimap Clipper");
                                        return 0;
                                      }
                                      else
                                      {
                                        inited = SurfaceClipper::SetClipWindow((SurfaceClipper *)&v34->Clipper1, hWnd);
                                        if ( inited )
                                        {
                                          WriteError(inited, "AssignClipper1");
                                          return 0;
                                        }
                                        else
                                        {
                                          Clipper = SurfaceClipper::GetClipper((SurfaceClipper *)&v34->Clipper1);
                                          inited = ((int (__thiscall *)(CSurfaceV7 *, struct IDirectDrawClipper *))v34->PrimarySurface->SetClipper)(
                                                     v34->PrimarySurface,
                                                     Clipper);
                                          if ( inited )
                                          {
                                            WriteError(inited, "SetClipper1");
                                            return 0;
                                          }
                                          else
                                          {
                                            g_pDestSizeTable = (int)g_iDestSizeTable;
                                            g_pZoomGradient = (int)&g_iZoomGradient;
                                            BBSupportTracePrintF(1, "GFX ENGINE: Common init ok.");
                                            return 1;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                                else
                                {
                                  BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                                  return 0;
                                }
                              }
                            }
                            else
                            {
                              BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                              return 0;
                            }
                          }
                        }
                        else
                        {
                          BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                          return 0;
                        }
                      }
                    }
                    else
                    {
                      BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                      return 0;
                    }
                  }
                }
                else
                {
                  BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                  return 0;
                }
              }
            }
            else
            {
              BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
              return 0;
            }
          }
        }
        else
        {
          BBSupportTracePrintF(1, "GFX ENGINE: Primary surface is not 16 bit! Please switch your desktop to HiColor!");
          return 0;
        }
      }
    }
    else
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
      return 0;
    }
  }
}


// address=[0x2f65300]
// Decompiled from char __thiscall CInterfaceD3D::InitHardware(CInterfaceD3D *this)

bool  CInterfaceD3D::InitHardware(void) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int GradientFormat; // eax
  struct IDirectDrawSurface7 *v8; // eax
  struct IDirectDrawSurface7 *v9; // [esp+ACh] [ebp-170h]
  struct IDirect3DDevice7 *v10; // [esp+B0h] [ebp-16Ch]
  _BYTE v11[4]; // [esp+C0h] [ebp-15Ch] BYREF
  CUploadCachePageManager *v12; // [esp+C4h] [ebp-158h]
  CCachePageManager *v13; // [esp+C8h] [ebp-154h]
  void *v14; // [esp+CCh] [ebp-150h]
  BOOL v15; // [esp+D0h] [ebp-14Ch]
  CUploadCachePageManager *v16; // [esp+D4h] [ebp-148h]
  void *C; // [esp+D8h] [ebp-144h]
  int v18; // [esp+DCh] [ebp-140h]
  int v19; // [esp+E0h] [ebp-13Ch]
  IDirectDraw7 *v20; // [esp+E4h] [ebp-138h]
  IDirectDraw7 *DDraw7; // [esp+E8h] [ebp-134h]
  IDirectDraw7 *DDraw; // [esp+ECh] [ebp-130h]
  int Number; // [esp+F0h] [ebp-12Ch]
  int v24; // [esp+F4h] [ebp-128h] BYREF
  int v25; // [esp+F8h] [ebp-124h]
  int v26; // [esp+FCh] [ebp-120h]
  HRESULT v27; // [esp+100h] [ebp-11Ch]
  bool v28; // [esp+107h] [ebp-115h]
  int i; // [esp+108h] [ebp-114h]
  int v30; // [esp+10Ch] [ebp-110h]
  _BYTE v32[4]; // [esp+114h] [ebp-108h] BYREF
  int v33; // [esp+118h] [ebp-104h]
  int v34; // [esp+11Ch] [ebp-100h]
  int v35; // [esp+120h] [ebp-FCh]
  int v36; // [esp+160h] [ebp-BCh]
  int v37; // [esp+164h] [ebp-B8h]
  int v38; // [esp+168h] [ebp-B4h]
  int v39; // [esp+16Ch] [ebp-B0h]
  int v40; // [esp+170h] [ebp-ACh]
  int v41; // [esp+174h] [ebp-A8h]
  int v42; // [esp+178h] [ebp-A4h]
  int v43; // [esp+17Ch] [ebp-A0h]
  _DWORD v44[4]; // [esp+1FCh] [ebp-20h] BYREF
  int v45; // [esp+218h] [ebp-4h]

  BBSupportTracePrintF(1, "GFX ENGINE: Begin hardware init.");
  if ( this->field_71D || this->field_71C )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT HARDWARE: Engine is already initialized!");
    return 1;
  }
  CHeightAndTypeTable::InitShadeTables((CHeightAndTypeTable *)g_cHeightAndTypeTable);
  v30 = this->DDraw7->lpVtbl->QueryInterface(this->DDraw7, &IID_IDirect3D7, (LPVOID *)&this->LandscapeRenderDevice);
  if ( v30 )
  {
    WriteError(v30, "QueryD3DInterface");
    return 0;
  }
  CInterfaceD3D::AllocateEngineData(D3DObjectPtr, 256);
  v26 = 256;
  if ( !D3DObjectPtr->IsHQTextureSet
    && SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup) )
  {
    v26 /= 2;
  }
  CInterfaceD3D::PreCalcTextureVertices(this, v26);
  for ( i = 0; i < 44; ++i )
  {
    this->LandscapeTextureTable[i] = CSurface::CreateSurfacePtr(byte_3E2E262);
    if ( !this->LandscapeTextureTable[i] )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
      return 0;
    }
    Number = dword_3E2E2B8 == 1;
    if ( byte_3E2E262 )
      DDraw = this->DDraw;
    else
      DDraw = this->DDraw7;
    v2 = j__abs(Number);
    v30 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, int, int, int, _DWORD, _DWORD, _DWORD))this->LandscapeTextureTable[i]->CreateSurface)(
            this->LandscapeTextureTable[i],
            DDraw,
            v26,
            v26,
            1,
            1,
            1,
            v2,
            0,
            0,
            0);
    if ( v30 )
    {
      WriteError(v30, "CreateLandscapeTextureSurface");
      return 0;
    }
  }
  if ( byte_3E2E30E )
  {
    for ( i = 0; i < 2; ++i )
    {
      this->ObjectTextureTable[i] = CSurface::CreateSurfacePtr(byte_3E2E262);
      if ( !this->ObjectTextureTable[i] )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
      }
      if ( byte_3E2E262 )
        DDraw7 = this->DDraw;
      else
        DDraw7 = this->DDraw7;
      v30 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, int, _DWORD, int, int, _DWORD, _DWORD, _DWORD))this->ObjectTextureTable[i]->CreateSurface)(
              this->ObjectTextureTable[i],
              DDraw7,
              512,
              512,
              1,
              0,
              1,
              2,
              0,
              0,
              0);
      if ( v30 )
      {
        WriteError(v30, "CreateObjectTextureSurface");
        return 0;
      }
    }
    for ( i = 0; i < 2; ++i )
    {
      this->ObjectTextureSystemMemoryTable[i] = CSurface::CreateSurfacePtr(byte_3E2E262);
      if ( !this->ObjectTextureSystemMemoryTable[i] )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
      }
      if ( byte_3E2E262 )
        v20 = this->DDraw;
      else
        v20 = this->DDraw7;
      v30 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, int, int, _DWORD, _DWORD, int, int, _DWORD, _DWORD, _DWORD))this->ObjectTextureSystemMemoryTable[i]->CreateSurface)(
              this->ObjectTextureSystemMemoryTable[i],
              v20,
              512,
              512,
              0,
              0,
              1,
              2,
              0,
              0,
              0);
      if ( v30 )
      {
        WriteError(v30, "CreateObjectTextureSystemMemory");
        return 0;
      }
    }
  }
  v3 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDrawSurface7 **))this->LandscapeSurface->GetSurfacePtr)(
         this->LandscapeSurface,
         &this->LandscapeSurfacePtr);
  v30 = (*(int (__stdcall **)(int, GUID *, int))(*(_DWORD *)this->LandscapeRenderDevice + 16))(
          this->LandscapeRenderDevice,
          &IID_IDirect3DHALDevice,
          v3);
  if ( v30 )
  {
    WriteError(v30, "CreateLandscapeRenderDevice");
    return 0;
  }
  v4 = ((int (__thiscall *)(CSurfaceV7 *, int *))this->FinalRenderSurface->GetSurfacePtr)(
         this->FinalRenderSurface,
         &this->field_38);
  v30 = (*(int (__stdcall **)(int, GUID *, int))(*(_DWORD *)this->LandscapeRenderDevice + 16))(
          this->LandscapeRenderDevice,
          &IID_IDirect3DHALDevice,
          v4);
  if ( v30 )
  {
    WriteError(v30, "CreateObjectRenderDevice");
    return 0;
  }
  this->field_3C = 0;
  this->field_40 = 0;
  this->field_44 = OutputWidth;
  this->field_48 = OutputHeight;
  this->field_4C = 0;
  this->field_50 = FLOAT_1_0;
  v30 = this->LandscapeSurfacePtr->lpVtbl->GetBltStatus(this->LandscapeSurfacePtr, (DWORD)&this->field_3C);
  if ( v30 )
  {
    WriteError(v30, "SetLandscapeViewport");
    return 0;
  }
  v30 = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)this->field_38 + 52))(this->field_38, &this->field_3C);
  if ( v30 )
  {
    WriteError(v30, "SetObjectViewport");
    return 0;
  }
  v5 = ((int (__thiscall *)(CSurfaceV7 *))this->LandscapeTextureTable[0]->GetSurfacePtr)(this->LandscapeTextureTable[0]);
  v30 = this->LandscapeSurfacePtr->lpVtbl->UpdateOverlayZOrder(this->LandscapeSurfacePtr, 0, (LPDIRECTDRAWSURFACE7)v5);
  if ( v30 )
  {
    WriteError(v30, "SetDefaultLandscapeTexture");
    return 0;
  }
  v30 = ((int (__stdcall *)(IDirectDrawSurface7 *, int, int))this->LandscapeSurfacePtr->lpVtbl->GetPalette)(
          this->LandscapeSurfacePtr,
          22,
          1);
  if ( v30 )
  {
    WriteError(v30, "SetCulling");
    return 0;
  }
  v30 = ((int (__stdcall *)(IDirectDrawSurface7 *, int, _DWORD))this->LandscapeSurfacePtr->lpVtbl->GetPalette)(
          this->LandscapeSurfacePtr,
          4,
          0);
  if ( v30 )
  {
    WriteError(v30, "SetTextureCorrecture");
    return 0;
  }
  v30 = ((int (__stdcall *)(IDirectDrawSurface7 *, int, _DWORD))this->LandscapeSurfacePtr->lpVtbl->GetPalette)(
          this->LandscapeSurfacePtr,
          7,
          0);
  if ( v30 )
  {
    WriteError(v30, "DisableZBuffer");
    return 0;
  }
  v30 = ((int (__stdcall *)(IDirectDrawSurface7 *, int, _DWORD))this->LandscapeSurfacePtr->lpVtbl->GetPalette)(
          this->LandscapeSurfacePtr,
          142,
          0);
  if ( v30 )
  {
    WriteError(v30, "DisableCameraView");
    return 0;
  }
  v30 = ((int (__stdcall *)(IDirectDrawSurface7 *, _DWORD, int, int))this->LandscapeSurfacePtr->lpVtbl->PageLock)(
          this->LandscapeSurfacePtr,
          0,
          12,
          1);
  if ( v30 )
  {
    WriteError(v30, "SetTextureAdressMode");
    return 0;
  }
  v30 = ((int (__stdcall *)(IDirectDrawSurface7 *, int, int))this->LandscapeSurfacePtr->lpVtbl->GetPalette)(
          this->LandscapeSurfacePtr,
          9,
          2);
  if ( v30 )
  {
    WriteError(v30, "SetLandscapeShading");
    return 0;
  }
  v30 = ((int (__stdcall *)(IDirectDrawSurface7 *, int, int))this->LandscapeSurfacePtr->lpVtbl->GetPalette)(
          this->LandscapeSurfacePtr,
          29,
          1);
  if ( v30 )
  {
    WriteError(v30, "SetLandscapeLighting");
    return 0;
  }
  if ( byte_3E2E30E )
  {
    InitRenderStates();
    v6 = ((int (__thiscall *)(CSurfaceV7 *))this->ObjectTextureTable[0]->GetSurfacePtr)(this->ObjectTextureTable[0]);
    v30 = (*(int (__stdcall **)(int, _DWORD, int))(*(_DWORD *)this->field_38 + 140))(this->field_38, 0, v6);
    if ( v30 )
    {
      WriteError(v30, "SetDefaultObjectTexture");
      return 0;
    }
    v30 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this->field_38 + 80))(this->field_38, 9, 1);
    if ( v30 )
    {
      WriteError(v30, "SetObjectShading");
      return 0;
    }
    v30 = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)this->field_38 + 80))(this->field_38, 29, 0);
    if ( v30 )
    {
      WriteError(v30, "SetObjectLighting");
      return 0;
    }
    v30 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this->field_38 + 80))(this->field_38, 27, 1);
    if ( v30 )
    {
      WriteError(v30, "EnableAlphaBlending");
      return 0;
    }
    v30 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this->field_38 + 80))(this->field_38, 19, 5);
    if ( v30 )
    {
      WriteError(v30, "SetSourceBlend");
      return 0;
    }
    v30 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)this->field_38 + 80))(this->field_38, 20, 6);
    if ( v30 )
    {
      WriteError(v30, "SetDestBlend");
      return 0;
    }
    if ( SGfxRenderConfiguration::IsFiltering((SGfxRenderConfiguration *)&GfxEngineSetup) )
      v19 = 2;
    else
      v19 = 1;
    v30 = (*(int (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)this->field_38 + 148))(this->field_38, 0, 16, v19);
    if ( v30 )
    {
      WriteError(v30, "SetObjectFiltering");
      return 0;
    }
    if ( SGfxRenderConfiguration::IsFiltering((SGfxRenderConfiguration *)&GfxEngineSetup) )
      v18 = 2;
    else
      v18 = 1;
    v30 = (*(int (__stdcall **)(int, _DWORD, int, int))(*(_DWORD *)this->field_38 + 148))(this->field_38, 0, 17, v18);
    if ( v30 )
    {
      WriteError(v30, "SetObjectFiltering");
      return 0;
    }
    CCacheManager::Reset((CCacheManager *)&g_cCacheManager);
    for ( i = 0; i < 8; ++i )
      CColorGradient::SetupGradients(
        &g_cColorGradient,
        i,
        dword_468D2C8[3 * i + 3],
        dword_468D2C8[3 * i + 4],
        dword_468D2C8[3 * i + 5],
        2);
    g_pfBlitSettler = (int)BlitSettlerHardware;
    g_pfBlitObject = (int)BlitObjectHardware;
    g_pfBlitVehicle = (int)BlitVehicleHardware;
    g_pfBlitBuilding = (int)BlitBuildingHardware;
    g_pfBlitBorderstone = (int)BlitBorderstoneHardware;
    g_pfBlitAccessoryIcon = (int)BlitAccessoryIconHardware;
    g_pfBlitWave = (int)BlitWaveHardware;
  }
  else
  {
    for ( i = 0; i < 8; ++i )
    {
      GradientFormat = CInterfaceD3D::GetGradientFormat(this);
      CColorGradient::SetupGradients(
        &g_cColorGradient,
        i,
        dword_468D2C8[3 * i + 3],
        dword_468D2C8[3 * i + 4],
        dword_468D2C8[3 * i + 5],
        GradientFormat);
    }
    g_pfBlitSettler = (int)BlitSettler;
    g_pfBlitObject = (int)BlitObject;
    g_pfBlitVehicle = (int)BlitVehicle;
    g_pfBlitBuilding = (int)BlitBuilding;
    g_pfBlitBorderstone = (int)BlitBorderstone;
    g_pfBlitAccessoryIcon = (int)BlitAccessoryIcon;
    g_pfBlitWave = (int)BlitWave;
  }
  if ( byte_3E2E30E )
  {
    for ( i = 0; i < 2; ++i )
    {
      C = operator new(0x9A4u);
      v45 = 0;
      if ( C )
      {
        v10 = (struct IDirect3DDevice7 *)this->field_38;
        v9 = (struct IDirectDrawSurface7 *)((int (__thiscall *)(CSurfaceV7 *))this->ObjectTextureSystemMemoryTable[i]->GetSurfacePtr)(this->ObjectTextureSystemMemoryTable[i]);
        v8 = (struct IDirectDrawSurface7 *)((int (__thiscall *)(CSurfaceV7 *))this->ObjectTextureTable[i]->GetSurfacePtr)(this->ObjectTextureTable[i]);
        v16 = CUploadCachePageManager::CUploadCachePageManager((CUploadCachePageManager *)C, v8, v9, v10);
      }
      else
      {
        v16 = 0;
      }
      v12 = v16;
      v45 = -1;
      this->CCachePageManager[i] = (DWORD)v16;
      if ( !this->CCachePageManager[i] )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: No memory to create PictureManager");
        return 0;
      }
    }
    CCachePageManager::SetCurrentZoomFactor((CCachePageManager *)this->CCachePageManager[0], *(float *)&dword_3E2E2F4);
    j__memset(v44, 0, sizeof(v44));
    v44[0] = 4096;
    v27 = this->DDraw7->lpVtbl->GetAvailableVidMem(this->DDraw7, (LPDDSCAPS2)v44, (LPDWORD)v11, (LPDWORD)&v24);
    if ( v27 )
    {
      WriteError(v27, "GetVideoMemory");
      return 0;
    }
    v25 = v24;
    BBSupportTracePrintF(1, "GFX ENGINE: Available vid mem for cache is %d", v24);
    v25 -= 1100000;
    v25 -= 50000;
    this->field_448 = 0;
    if ( v25 > 0 )
    {
      CSurfaceDescription::CSurfaceDescription((CSurfaceDescription *)v32);
      v33 = 4103;
      v43 = 20480;
      v35 = 512;
      v34 = 512;
      v36 = 65;
      v37 = 0;
      v38 = 16;
      v39 = 3840;
      v40 = 240;
      v41 = 15;
      v42 = 61440;
      v15 = v24 != 1674288;
      v28 = v24 != 1674288;
      for ( this->field_448 = j__abs(v15); v28 && this->field_448 < 180; ++this->field_448 )
      {
        v27 = this->DDraw7->lpVtbl->CreateSurface(
                this->DDraw7,
                (LPDDSURFACEDESC2)v32,
                (LPDIRECTDRAWSURFACE7 *)&this->field_178[this->field_448],
                0);
        v28 = 1;
        if ( v27 )
        {
          if ( v27 == -2005532292 )
          {
            BBSupportTracePrintF(1, "GFX ENGINE: %d cache surfaces created. Running out of video mem!", this->field_448);
            break;
          }
          WriteError(v27, "CreateCacheSurfaces");
          return 0;
        }
        v27 = this->DDraw7->lpVtbl->GetAvailableVidMem(this->DDraw7, (LPDDSCAPS2)v44, (LPDWORD)v11, (LPDWORD)&v24);
        if ( v27 )
        {
          WriteError(v27, "GetVideoMemory");
          return 0;
        }
        if ( v24 == 1674288 )
          v28 = 0;
        v14 = operator new(0x824u);
        v45 = 1;
        if ( v14 )
          v13 = CCachePageManager::CCachePageManager(
                  (CCachePageManager *)v14,
                  (struct IDirectDrawSurface7 *)this->field_178[this->field_448],
                  0,
                  (struct IDirect3DDevice7 *)this->field_38);
        else
          v13 = 0;
        v45 = -1;
        this->field_44C[this->field_448] = (DWORD)v13;
        if ( !this->field_44C[this->field_448] )
        {
          BBSupportTracePrintF(1, "GFX ENGINE: Out of memory while creating CacheManager");
          return 0;
        }
      }
    }
    g_iZoomGradient = dword_3E2E28C / 24;
    g_iZoomInit = -65536;
    if ( D3DObjectPtr->CCachePageManager[0] )
      CCachePageManager::SetCurrentZoomFactor(
        (CCachePageManager *)D3DObjectPtr->CCachePageManager[0],
        *(float *)&dword_3E2E2F4);
  }
  D3DObjectPtr->field_71D = 1;
  BBSupportTracePrintF(1, "GFX ENGINE: Hardware init ok.");
  return 1;
}


// address=[0x2f665f0]
// Decompiled from char __thiscall CInterfaceD3D::InitSoftware(CInterfaceD3D *this)

bool  CInterfaceD3D::InitSoftware(void) {
  
  int GradientFormat; // eax
  int i; // [esp+8h] [ebp-4h]
  int j; // [esp+8h] [ebp-4h]

  BBSupportTracePrintF(1, "GFX ENGINE: Begin software init.");
  if ( *((_BYTE *)this + 1821) || *((_BYTE *)this + 1820) )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT SOFTWARE: Engine is already initialized!");
    return 1;
  }
  else
  {
    if ( dword_3E2E2B8 == 1 )
      j__TRI_init_engine(1365);
    else
      j__TRI_init_engine(1381);
    CHeightAndTypeTable::InitShadeTables((CHeightAndTypeTable *)g_cHeightAndTypeTable);
    CInterfaceD3D::AllocateEngineData(D3DObjectPtr, 256);
    g_pSoftwareTexturePages = (int)operator new[](0x2C0000u);
    if ( g_pSoftwareTexturePages )
    {
      for ( i = 0; i < 44; ++i )
        g_pTextureTable[i] = g_pSoftwareTexturePages + (i << 16);
      CInterfaceD3D::InitTexturePtr(this);
      for ( j = 0; j < 8; ++j )
      {
        GradientFormat = CInterfaceD3D::GetGradientFormat(this);
        CColorGradient::SetupGradients(
          &g_cColorGradient,
          j,
          dword_468D2C8[3 * j + 3],
          dword_468D2C8[3 * j + 4],
          dword_468D2C8[3 * j + 5],
          GradientFormat);
      }
      CInterfaceD3D::PreCalcTextureVertices(this, 256);
      g_pfBlitSettler = (int)BlitSettler;
      g_pfBlitObject = (int)BlitObject;
      g_pfBlitVehicle = (int)BlitVehicle;
      g_pfBlitBuilding = (int)BlitBuilding;
      g_pfBlitBorderstone = (int)BlitBorderstone;
      g_pfBlitAccessoryIcon = (int)BlitAccessoryIcon;
      g_pfBlitWave = (int)BlitWave;
      *((_BYTE *)this + 1820) = 1;
      BBSupportTracePrintF(1, "GFX ENGINE: Software init ok.");
      return 1;
    }
    else
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Out of memory while allocating texture pages in system memory.");
      return 0;
    }
  }
}


// address=[0x2f667c0]
// Decompiled from char __thiscall CInterfaceD3D::BlitSurfaceToDIB(_DWORD **this, HWND hWnd, HGDIOBJ h)

bool  CInterfaceD3D::BlitSurfaceToDIB(struct HWND__ *,struct HBITMAP__ *) {
  
  HDC hdc; // [esp+4h] [ebp-14h]
  HDC hdcSrc; // [esp+8h] [ebp-10h] BYREF
  int v6; // [esp+Ch] [ebp-Ch]
  HDC CompatibleDC; // [esp+10h] [ebp-8h]
  _DWORD **v8; // [esp+14h] [ebp-4h]

  v8 = this;
  v6 = (*(int (__thiscall **)(_DWORD *, HDC *))(*this[25] + 40))(this[25], &hdcSrc);
  if ( v6 == -2005532222 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 1)");
    return 0;
  }
  else
  {
    if ( v6 )
      BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 2)");
    hdc = GetDC(hWnd);
    CompatibleDC = CreateCompatibleDC(hdc);
    SelectObject(CompatibleDC, h);
    if ( !BitBlt(CompatibleDC, 0, 0, OutputWidth, OutputHeight, hdcSrc, 0, 0, (DWORD)&dword_C20408[163590]) )
      BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 3)");
    (*(void (__thiscall **)(_DWORD *, HDC))(*v8[25] + 44))(v8[25], hdcSrc);
    ReleaseDC(hWnd, hdc);
    DeleteDC(CompatibleDC);
    return 1;
  }
}


// address=[0x2f668c0]
// Decompiled from char __thiscall CInterfaceD3D::BlitSurfaceToWindow(CInterfaceD3D *this)

bool  CInterfaceD3D::BlitSurfaceToWindow(void) {
  
  CBlitFX *BlitStructPtr; // eax
  CBlitFX *v3; // eax
  int surfaceWidth; // [esp+0h] [ebp-5Ch] BYREF
  int surfaceHeight; // [esp+4h] [ebp-58h] BYREF
  int v6; // [esp+8h] [ebp-54h]
  int v7; // [esp+Ch] [ebp-50h]
  int v8; // [esp+10h] [ebp-4Ch]
  tagRECT v10; // [esp+18h] [ebp-44h] BYREF
  tagRECT v11; // [esp+28h] [ebp-34h] BYREF
  int v12; // [esp+38h] [ebp-24h] BYREF
  int v13; // [esp+3Ch] [ebp-20h]
  int v14; // [esp+40h] [ebp-1Ch]
  int v15; // [esp+44h] [ebp-18h]
  int v16; // [esp+48h] [ebp-14h] BYREF
  int v17; // [esp+4Ch] [ebp-10h]
  int v18; // [esp+50h] [ebp-Ch]
  int v19; // [esp+54h] [ebp-8h]

  v6 = 0;
  if ( SGfxRenderConfiguration::IsEditorMode((SGfxRenderConfiguration *)&GfxEngineSetup) )
  {
    if ( this->field_138[0] && this->PrimarySurface )
    {
      v11.left = WindowPositionX;
      v11.top = WindowPositionY;
      v11.right = OutputWidth + WindowPositionX;
      v11.bottom = OutputHeight + WindowPositionY;
      BlitStructPtr = CBlitFX::GetBlitStructPtr((CBlitFX *)&g_cBlitFX);
      v6 = ((int (__thiscall *)(CSurfaceV7 *, tagRECT *, DWORD, _DWORD, int, CBlitFX *))this->PrimarySurface->Blt)(
             this->PrimarySurface,
             &v11,
             this->field_138[0],
             0,
             512,
             BlitStructPtr);
    }
    if ( byte_3E2E301 && this->MiniMapAreaSurface && this->PrimarySurface )
    {
      v7 = -1;
      v16 = g_sMiniMapRect;
      v17 = dword_4689B90;
      v18 = dword_4689B94;
      v19 = dword_4689B98;
      v12 = g_sMiniMapSize;
      v13 = dword_3E2E240;
      v14 = dword_3E2E244;
      v15 = dword_3E2E248;
      ((void (__thiscall *)(CSurfaceV7 *, int *, int *))D3DObjectPtr->PrimarySurface->GetSurfaceSize)(
        D3DObjectPtr->PrimarySurface,
        &surfaceWidth,
        &surfaceHeight);
      v14 -= v12;
      v15 -= v13;
      v12 = 0;
      v13 = 0;
      if ( v19 > surfaceHeight )
      {
        v8 = v19 - surfaceHeight;
        v19 = surfaceHeight;
        v15 -= v8;
      }
      if ( v18 > surfaceWidth )
      {
        v8 = v18 - surfaceWidth;
        v18 = surfaceWidth;
        v14 -= v8;
      }
      if ( v17 < 0 )
      {
        v8 = abs(v17);
        v17 += v8;
        v13 += v8;
      }
      if ( v16 < 0 )
      {
        v8 = abs(v16);
        v16 += v8;
        v12 += v8;
      }
      if ( v17 <= surfaceHeight || v16 <= surfaceWidth )
      {
        v7 = CInterfaceD3D::SetCustomClipper(this, (struct SurfaceClipper *)&this->MinimapClipper);
        if ( v7 )
        {
          WriteError(v7, "SetClipper2");
          return 0;
        }
        v7 = ((int (__thiscall *)(CSurfaceV7 *, int *, CSurfaceV7 *, int *, int, _DWORD))D3DObjectPtr->PrimarySurface->Blt)(
               D3DObjectPtr->PrimarySurface,
               &v16,
               D3DObjectPtr->MiniMapSurface,
               &v12,
               0x8000,
               0);
        if ( !v7 )
          v7 = ((int (__thiscall *)(CSurfaceV7 *, int *, CSurfaceV7 *, int *, int, _DWORD))D3DObjectPtr->PrimarySurface->Blt)(
                 D3DObjectPtr->PrimarySurface,
                 &v16,
                 D3DObjectPtr->MiniMapAreaSurface,
                 &v12,
                 0x8000,
                 0);
      }
      v7 = CInterfaceD3D::ClearCustomClipper(this);
      if ( v7 )
      {
        WriteError(v7, "SetClipper1");
        return 0;
      }
    }
  }
  else if ( this->FinalRenderSurface && this->PrimarySurface )
  {
    v10.left = WindowPositionX;
    v10.top = WindowPositionY;
    v10.right = OutputWidth + WindowPositionX;
    v10.bottom = OutputHeight + WindowPositionY;
    v3 = CBlitFX::GetBlitStructPtr((CBlitFX *)&g_cBlitFX);
    v6 = ((int (__thiscall *)(CSurfaceV7 *, tagRECT *, CSurfaceV7 *, _DWORD, int, CBlitFX *))this->PrimarySurface->Blt)(
           this->PrimarySurface,
           &v10,
           this->FinalRenderSurface,
           0,
           512,
           v3);
  }
  switch ( v6 )
  {
    case 0:
      return 1;
    case -2005532222:
      v6 = ((int (__thiscall *)(CSurfaceV7 *))this->PrimarySurface->Restore)(this->PrimarySurface);
      if ( v6 )
        WriteError(v6, "RestorePrimarySurface");
      if ( v6 == -2005532085 )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: Stop rendering because of inaccessability of primary surface!");
        this->field_740 = 1;
      }
      break;
    case -2005532447:
      WriteError(-2005532447, "Exclusive mode down! Stop rendering...");
      this->field_740 = 1;
      break;
    default:
      WriteError(v6, "PrimarySurfaceBlit");
      break;
  }
  return 0;
}


// address=[0x2f66d00]
// Decompiled from // public: void __thiscall CInterfaceD3D::BlitDIBToSurface(struct HWND__ *,int,int,struct IDirectDrawSurface4 *)
BOOL __stdcall CInterfaceD3D::BlitDIBToSurface(HWND hWnd, int a2, int cy, int a4)

void  CInterfaceD3D::BlitDIBToSurface(struct HWND__ *,int,int,struct IDirectDrawSurface4 *) {
  
  HDC hdc; // [esp+8h] [ebp-Ch]
  HDC v6; // [esp+Ch] [ebp-8h] BYREF
  HDC hdcSrc; // [esp+10h] [ebp-4h]

  (*(void (__stdcall **)(int, HDC *))(*(_DWORD *)a4 + 68))(a4, &v6);
  hdc = GetDC(hWnd);
  hdcSrc = CreateCompatibleDC(hdc);
  SelectObject(hdcSrc, h);
  if ( !BitBlt(v6, 0, 0, a2, cy, hdcSrc, 0, 0, (DWORD)&dword_C20408[163590]) )
    BBSupportTracePrintF(1, "GFX ENGINE: Blit to Surface failed!");
  (*(void (__thiscall **)(int, int, HDC))(*(_DWORD *)a4 + 104))(a4, a4, v6);
  ReleaseDC(hWnd, hdc);
  return DeleteDC(hdcSrc);
}


// address=[0x2f66dc0]
// Decompiled from int __thiscall CInterfaceD3D::GetGradientFormat(CInterfaceD3D *this)

int  CInterfaceD3D::GetGradientFormat(void) {
  
  if ( this->field_71D )
    return 2;
  else
    return dword_3E2E2B8 == 1;
}


// address=[0x2f66e00]
// Decompiled from int __stdcall CInterfaceD3D::EnumModesCallback(struct _DDSURFACEDESC2 *a1, void *a2)

static long __stdcall CInterfaceD3D::EnumModesCallback(struct _DDSURFACEDESC2 *,void *) {
  
  if ( !a1 )
    return 0;
  if ( a1->ddpfPixelFormat.dwRGBBitCount <= 0x10 )
    return 1;
  if ( a1->dwWidth == 640 && a1->dwHeight == 480 )
  {
    D3DObjectPtr->field_71E[0] = 1;
    return 1;
  }
  else if ( a1->dwWidth == 800 && a1->dwHeight == 600 )
  {
    D3DObjectPtr->field_71E[1] = 1;
    return 1;
  }
  else if ( a1->dwWidth == 1024 && a1->dwHeight == 768 )
  {
    D3DObjectPtr->field_71E[2] = 1;
    return 1;
  }
  else if ( a1->dwWidth == 1280 && a1->dwHeight == 1024 )
  {
    D3DObjectPtr->field_71E[3] = 1;
    return 1;
  }
  else if ( a1->dwWidth == 1600 && a1->dwHeight == 1200 )
  {
    D3DObjectPtr->field_71E[4] = 1;
    return 1;
  }
  else
  {
    return 1;
  }
}


// address=[0x2f66f40]
// Decompiled from // public: static long __stdcall CInterfaceD3D::EnumModesCallbackOld(struct _DDSURFACEDESC *,void *)
int __stdcall CInterfaceD3D::EnumModesCallbackOld(_DWORD *a1, int a2)

static long __stdcall CInterfaceD3D::EnumModesCallbackOld(struct _DDSURFACEDESC *,void *) {
  
  if ( !a1 )
    return 0;
  if ( a1[21] <= 0x10u )
    return 1;
  if ( a1[3] == 640 && a1[2] == 480 )
  {
    D3DObjectPtr->field_71E[0] = 1;
    return 1;
  }
  else if ( a1[3] == 800 && a1[2] == 600 )
  {
    D3DObjectPtr->field_71E[1] = 1;
    return 1;
  }
  else if ( a1[3] == 1024 && a1[2] == 768 )
  {
    D3DObjectPtr->field_71E[2] = 1;
    return 1;
  }
  else if ( a1[3] == 1280 && a1[2] == 1024 )
  {
    D3DObjectPtr->field_71E[3] = 1;
    return 1;
  }
  else if ( a1[3] == 1600 && a1[2] == 1200 )
  {
    D3DObjectPtr->field_71E[4] = 1;
    return 1;
  }
  else
  {
    return 1;
  }
}


// address=[0x2f67080]
// Decompiled from char __thiscall CInterfaceD3D::LoadTexturePageContents(CInterfaceD3D *this)

bool  CInterfaceD3D::LoadTexturePageContents(void) {
  
  char IsHardwareLandscapeEngine; // al
  char IsHQTextureSet; // [esp-Ch] [ebp-18h]
  bool v4; // [esp-8h] [ebp-14h]
  int i; // [esp+4h] [ebp-8h]

  BBSupportTracePrintF(1, "GFX ENGINE: Read in all texture pages...");
  if ( !SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup) )
    D3DObjectPtr->IsHQTextureSet = 1;
  if ( !D3DObjectPtr )
    return 1;
  v4 = dword_3E2E2B8 == 1;
  IsHQTextureSet = D3DObjectPtr->IsHQTextureSet;
  IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup);
  if ( !ReadTextureBitmapSet(IsHardwareLandscapeEngine, IsHQTextureSet, v4, 44) )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: Error while loading texture set!");
    return 0;
  }
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup) )
    return 1;
  BBSupportTracePrintF(1, "GFX ENGINE: Begin set up luminance tables.");
  for ( i = 0; i < 44; ++i )
    j__TRI_calculate_LUT_from_palette((char *)&g_uColorPalettes + 768 * i, g_pLuminanceTablesStart + (i << 11));
  BBSupportTracePrintF(1, "GFX ENGINE: End set up luminance tables.");
  return 1;
}


// address=[0x2f67190]
// Decompiled from void __thiscall CInterfaceD3D::SetupViewport(CInterfaceD3D *this, int a2, int a3, int a4, int a5)

void  CInterfaceD3D::SetupViewport(int,int,int,int) {
  
  HRESULT v5; // [esp+0h] [ebp-8h]
  int v6; // [esp+0h] [ebp-8h]

  this->field_3C = a2;
  this->field_40 = a3;
  this->field_44 = a4;
  this->field_48 = a5;
  if ( this->LandscapeSurfacePtr )
  {
    v5 = this->LandscapeSurfacePtr->lpVtbl->GetBltStatus(this->LandscapeSurfacePtr, (DWORD)&this->field_3C);
    if ( v5 )
    {
      WriteError(v5, "SetLandscapeViewport");
    }
    else if ( this->field_38 )
    {
      v6 = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)this->field_38 + 52))(this->field_38, &this->field_3C);
      if ( v6 )
        WriteError(v6, "SetObjectViewport");
    }
  }
}


// address=[0x2f67250]
// Decompiled from int __thiscall CInterfaceD3D::SetCustomClipper(CInterfaceD3D *this, struct SurfaceClipper *a2)

long  CInterfaceD3D::SetCustomClipper(class SurfaceClipper &) {
  
  struct IDirectDrawClipper *Clipper; // eax

  if ( !SurfaceClipper::GetClipper(a2) )
    j___wassert(L"clipper.GetClipper() != nullptr", L"MainGfxManager.cpp", 0x90Fu);
  Clipper = SurfaceClipper::GetClipper(a2);
  return (*(int (__thiscall **)(_DWORD, struct IDirectDrawClipper *))(**((_DWORD **)this + 25) + 68))(
           *((_DWORD *)this + 25),
           Clipper);
}


// address=[0x2f672a0]
// Decompiled from int __thiscall CInterfaceD3D::ClearCustomClipper(CInterfaceD3D *this)

long  CInterfaceD3D::ClearCustomClipper(void) {
  
  struct IDirectDrawClipper *Clipper; // eax

  Clipper = SurfaceClipper::GetClipper((SurfaceClipper *)&this->Clipper1);
  return ((int (__thiscall *)(CSurfaceV7 *, struct IDirectDrawClipper *))this->FinalRenderSurface->SetClipper)(
           this->FinalRenderSurface,
           Clipper);
}


// address=[0x2f672d0]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::DeleteEngineData(CInterfaceD3D *this)

void  CInterfaceD3D::DeleteEngineData(void) {
  
  CInterfaceD3D *result; // eax

  result = this;
  if ( this->field_0 )
  {
    result = (CInterfaceD3D *)operator delete[]((void *)this->field_0);
    this->field_0 = 0;
    g_pVertexMax = 0;
    g_pVertex = 0;
  }
  if ( !g_pLuminanceTablesMemory )
    return result;
  result = (CInterfaceD3D *)operator delete[]((void *)g_pLuminanceTablesMemory);
  g_pLuminanceTablesMemory = 0;
  g_pLuminanceTablesStart = 0;
  return result;
}


// address=[0x2f67350]
// Decompiled from int __thiscall CInterfaceD3D::BeginLandscapeScene(CInterfaceD3D *this)

long  CInterfaceD3D::BeginLandscapeScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = -1;
  if ( this->field_730 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 0", this->field_730);
  }
  else
  {
    v2 = ((int (__stdcall *)(IDirectDrawSurface7 *))this->LandscapeSurfacePtr->lpVtbl->Blt)(this->LandscapeSurfacePtr);
    if ( v2 )
      WriteError(v2, "BeginLandscapeScene");
    ++this->field_730;
  }
  return v2;
}


// address=[0x2f673e0]
// Decompiled from int __thiscall CInterfaceD3D::EndLandscapeScene(CInterfaceD3D *this)

long  CInterfaceD3D::EndLandscapeScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  if ( this->field_730 > 1 )
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 1", this->field_730);
  v2 = ((int (__stdcall *)(IDirectDrawSurface7 *))this->LandscapeSurfacePtr->lpVtbl->BltBatch)(this->LandscapeSurfacePtr);
  if ( v2 )
    WriteError(v2, "EndLandscapeScene");
  --this->field_730;
  return v2;
}


// address=[0x2f67460]
// Decompiled from int __thiscall CInterfaceD3D::BeginObjectScene(CInterfaceD3D *this)

long  CInterfaceD3D::BeginObjectScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = -1;
  if ( this->field_72C )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: ObjectScene Lockcounter is %d instead of 0", this->field_72C);
  }
  else
  {
    v2 = (*(int (__stdcall **)(int))(*(_DWORD *)this->field_38 + 20))(this->field_38);
    if ( v2 )
      WriteError(v2, "BeginObjectScene");
    ++this->field_72C;
  }
  return v2;
}


// address=[0x2f674f0]
// Decompiled from int __thiscall CInterfaceD3D::EndObjectScene(CInterfaceD3D *this)

long  CInterfaceD3D::EndObjectScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  if ( this->field_72C > 1 )
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 1", this->field_72C);
  v2 = (*(int (__stdcall **)(int))(*(_DWORD *)this->field_38 + 24))(this->field_38);
  if ( v2 )
    WriteError(v2, "EndObjectScene");
  --this->field_72C;
  return v2;
}


// address=[0x2f67570]
// Decompiled from char __thiscall CInterfaceD3D::CreateCameraWindowSurface(CInterfaceD3D *this, int a2, int a3)

bool  CInterfaceD3D::CreateCameraWindowSurface(int,int) {
  
  unsigned __int8 IsHardwareLandscapeEngine; // al
  int v5; // [esp-10h] [ebp-20h]
  int v6; // [esp+0h] [ebp-10h]
  IDirectDraw7 *DDraw; // [esp+4h] [ebp-Ch]

  CInterfaceD3D::DestroyCameraWindowSurface(this);
  this->field_5C = (int)CSurface::CreateSurfacePtr(byte_3E2E262);
  if ( this->field_5C )
  {
    if ( byte_3E2E262 )
      DDraw = this->DDraw;
    else
      DDraw = this->DDraw7;
    v5 = j__abs(dword_3E2E2B8 == 1);
    IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup);
    v6 = (*(int (__thiscall **)(int, IDirectDraw7 *, int, int, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this->field_5C + 48))(
           this->field_5C,
           DDraw,
           a2,
           a3,
           1,
           IsHardwareLandscapeEngine,
           0,
           v5,
           0,
           0,
           0);
    if ( v6 )
    {
      WriteError(v6, "CreateLandscapeSurface");
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
    return 0;
  }
}


// address=[0x2f67660]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::DestroyCameraWindowSurface(CInterfaceD3D *this)

void  CInterfaceD3D::DestroyCameraWindowSurface(void) {
  
  CInterfaceD3D *result; // eax

  result = this;
  if ( !this->field_5C )
    return result;
  if ( this->LandscapeSurface2 == (CSurfaceV7 *)this->field_5C )
    j___wassert(L"m_pCurrentLandScapeRenderTarget != m_pLandscapeCameraRenderSurface", L"MainGfxManager.cpp", 0x9D2u);
  (*(void (__thiscall **)(int))(*(_DWORD *)this->field_5C + 4))(this->field_5C);
  result = (CInterfaceD3D *)this->field_5C;
  if ( result )
    result = (CInterfaceD3D *)(**(int (__thiscall ***)(int, int))this->field_5C)(this->field_5C, 1);
  this->field_5C = 0;
  return result;
}


// address=[0x2f676f0]
// Decompiled from int __thiscall CInterfaceD3D::SwitchLandscapeRenderTarget(CInterfaceD3D *this, bool a2)

long  CInterfaceD3D::SwitchLandscapeRenderTarget(bool) {
  
  int v3; // [esp+0h] [ebp-10h]
  CSurfaceV7 *LandscapeSurface; // [esp+4h] [ebp-Ch]

  if ( a2 )
    LandscapeSurface = (CSurfaceV7 *)this->field_5C;
  else
    LandscapeSurface = this->LandscapeSurface;
  if ( !LandscapeSurface )
    j___wassert(L"renderTarget != nullptr", L"MainGfxManager.cpp", 0x9DDu);
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup) )
  {
    v3 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDrawSurface7 *))LandscapeSurface->j_?SetAsRenderTarget@CSurfaceV7@@UAEJPAUIDirect3DDevice7@@@Z)(
           LandscapeSurface,
           this->LandscapeSurfacePtr);
    if ( v3 < 0 )
      return v3;
  }
  this->LandscapeSurface2 = LandscapeSurface;
  return 0;
}


// address=[0x2f74fc0]
// Decompiled from int __thiscall CInterfaceD3D::GetGuiMemorySize(CInterfaceD3D *this)

int  CInterfaceD3D::GetGuiMemorySize(void) {
  
  return this->field_734;
}


// address=[0x2f74fe0]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::SetGuiMemorySize(CInterfaceD3D *this, int a2)

void  CInterfaceD3D::SetGuiMemorySize(int) {
  
  CInterfaceD3D *result; // eax

  result = this;
  this->field_734 = a2;
  return result;
}


// address=[0x2f81fe0]
// Decompiled from int __thiscall CInterfaceD3D::InitTexturedLandscapeModule(CInterfaceD3D *this)

void  CInterfaceD3D::InitTexturedLandscapeModule(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]
  int j; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 44; ++i )
  {
    g_pTextureTable[i] = 0;
    result = i + 1;
  }
  g_iLastUsedPage = 0;
  for ( j = 0; j < 44; ++j )
  {
    result = j;
    this->LandscapeTextureTable[j] = 0;
  }
  return result;
}


// address=[0x2f82050]
// Decompiled from int __thiscall CInterfaceD3D::PreCalcTextureVertices(CInterfaceD3D *this, int a2)

void  CInterfaceD3D::PreCalcTextureVertices(int) {
  
  int result; // eax
  float v3; // [esp+10h] [ebp-74h]
  int k; // [esp+14h] [ebp-70h]
  int i; // [esp+18h] [ebp-6Ch]
  int j; // [esp+1Ch] [ebp-68h]
  _BYTE v7[24]; // [esp+20h] [ebp-64h] BYREF
  float v8; // [esp+38h] [ebp-4Ch]
  float v9; // [esp+3Ch] [ebp-48h]
  float v10; // [esp+58h] [ebp-2Ch]
  float v11; // [esp+5Ch] [ebp-28h]
  float v12; // [esp+78h] [ebp-Ch]
  float v13; // [esp+7Ch] [ebp-8h]

  v3 = FLOAT_0_001953125;
  result = (unsigned __int8)SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup);
  if ( !(_BYTE)result )
    v3 = 0.0;
  for ( i = 0; i < 4; ++i )
  {
    for ( j = 0; j < 4; ++j )
    {
      for ( k = 0; k < 6; ++k )
      {
        `vector constructor iterator'(v7, 0x20u, 3u, (void *(__thiscall *)(void *))_D3DTLVERTEX::_D3DTLVERTEX);
        ((void (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))sub_2F7BC20)(v7, (float)j, (float)i, k);
        PatternTripleVertices[144 * j + 36 * i + 6 * k] = v8 + v3;
        PatternTripleVertices[144 * j + 1 + 36 * i + 6 * k] = v9 + v3;
        PatternTripleVertices[144 * j + 2 + 36 * i + 6 * k] = v10 + v3;
        PatternTripleVertices[144 * j + 3 + 36 * i + 6 * k] = v11 + v3;
        PatternTripleVertices[144 * j + 4 + 36 * i + 6 * k] = v12 + v3;
        PatternTripleVertices[144 * j + 5 + 36 * i + 6 * k] = v13 + v3;
        result = k + 1;
      }
    }
  }
  return result;
}


// address=[0x2f82260]
// Decompiled from // write access to const memory has been detected, the output may be wrong!
int __thiscall CInterfaceD3D::InitTexturePtr(CInterfaceD3D *this)

void  CInterfaceD3D::InitTexturePtr(void) {
  
  int result; // eax

  g_iLastUsedPage = 0;
  result = 0;
  CurrentTexturePagePtr = g_pTextureTable[0];
  j__TRI_palette_LUT = g_pLuminanceTablesStart;
  return result;
}


// address=[0x2f822a0]
// Decompiled from int __thiscall CInterfaceD3D::CalcTilingVerticesType1(CInterfaceD3D *this, int a2)

void  CInterfaceD3D::CalcTilingVerticesType1(int) {
  
  int result; // eax
  float v3; // [esp+4h] [ebp-4h]

  CInterfaceD3D::ChangeCurrentTexturePage(this, s_iDarkTribeElement + byte_3ACD240[a2]);
  v3 = *(float *)&g_fPatternSuboffsetX;
  if ( (float)(*(float *)&g_fPatternSuboffsetX + 0.125) <= 1.0 )
  {
    *(float *)(g_pVertex + 24) = *(float *)&g_fPatternSuboffsetX + 0.125;
  }
  else if ( g_bHalfLine )
  {
    *(float *)(g_pVertex + 24) = *(float *)&dword_3E2E708 + 1.0;
    g_bSplitTriangle = 1;
  }
  else
  {
    *(float *)(g_pVertex + 24) = *(float *)&g_fPatternSuboffsetX + 0.125;
  }
  *(float *)(g_pVertex + 28) = *(float *)&g_fPatternSuboffsetY + 0.125;
  g_pVertex += 32;
  *(float *)(g_pVertex + 24) = v3;
  *(float *)(g_pVertex + 28) = *(float *)&g_fPatternSuboffsetY + 0.125;
  g_pVertex += 32;
  *(float *)(g_pVertex + 24) = v3 + 0.0625;
  result = g_pVertex;
  *(_DWORD *)(g_pVertex + 28) = g_fPatternSuboffsetY;
  g_pVertex -= 64;
  return result;
}


// address=[0x2f823f0]
// Decompiled from int __thiscall CInterfaceD3D::CalcTilingVerticesType2(CInterfaceD3D *this, int a2)

void  CInterfaceD3D::CalcTilingVerticesType2(int) {
  
  int result; // eax
  float v3; // [esp+4h] [ebp-8h]
  float v4; // [esp+8h] [ebp-4h]

  CInterfaceD3D::ChangeCurrentTexturePage(this, s_iDarkTribeElement + byte_3ACD240[a2]);
  v4 = *(float *)&g_fPatternSuboffsetX + 0.1875;
  v3 = *(float *)&g_fPatternSuboffsetX;
  if ( (float)(*(float *)&g_fPatternSuboffsetX + 0.1875) > 1.0 )
  {
    if ( g_bHalfLine )
    {
      v4 = v4 - 1.0;
      v3 = *(float *)&g_fPatternSuboffsetX - 1.0;
    }
    else
    {
      v4 = *(float *)&dword_3E2E708 + 1.0;
      g_bSplitTriangle = 1;
    }
  }
  *(float *)(g_pVertex + 24) = v4;
  *(_DWORD *)(g_pVertex + 28) = g_fPatternSuboffsetY;
  g_pVertex += 32;
  *(float *)(g_pVertex + 24) = v3 + 0.125;
  *(float *)(g_pVertex + 28) = *(float *)&g_fPatternSuboffsetY + 0.125;
  g_pVertex += 32;
  result = g_pVertex;
  *(float *)(g_pVertex + 24) = v3 + 0.0625;
  *(_DWORD *)(g_pVertex + 28) = g_fPatternSuboffsetY;
  g_pVertex -= 64;
  return result;
}


// address=[0x2f82540]
// Decompiled from int __thiscall CInterfaceD3D::AllocateEngineData(CInterfaceD3D *this, signed int a2)

int  CInterfaceD3D::AllocateEngineData(int) {
  
  void *v3; // [esp+10h] [ebp-20h]
  void *v4; // [esp+18h] [ebp-18h]
  signed int i; // [esp+1Ch] [ebp-14h]

  if ( *(_DWORD *)this )
    CInterfaceD3D::DeleteEngineData(this);
  v4 = operator new[](32 * a2);
  if ( v4 )
  {
    `vector constructor iterator'(v4, 0x20u, a2, (void *(__thiscall *)(void *))_D3DTLVERTEX::_D3DTLVERTEX);
    v3 = v4;
  }
  else
  {
    v3 = 0;
  }
  *(_DWORD *)this = v3;
  if ( !*(_DWORD *)this )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: Not enough memory to allocate vertices");
    return 0;
  }
  for ( i = 0; i < a2; ++i )
  {
    *(float *)(*(_DWORD *)this + 32 * i + 8) = FLOAT_0_89999998;
    *(float *)(*(_DWORD *)this + 32 * i + 12) = FLOAT_0_5;
  }
  if ( *(_DWORD *)this )
    g_pVertexMax = *(_DWORD *)this + 7680;
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup) )
    return 1;
  g_pLuminanceTablesMemory = (int)operator new[](0x16800u);
  if ( !g_pLuminanceTablesMemory )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: Not enough memory to allocate luminance tables!");
    g_pLuminanceTablesStart = 0;
    return 0;
  }
  g_pLuminanceTablesStart = (g_pLuminanceTablesMemory + 2047) & 0xFFFFF800;
  return 1;
}


// address=[0x2f85f40]
// Decompiled from // write access to const memory has been detected, the output may be wrong!
int __thiscall CInterfaceD3D::ChangeCurrentTexturePage(CInterfaceD3D *this, int a2)

void  CInterfaceD3D::ChangeCurrentTexturePage(int) {
  
  int result; // eax
  struct IDirectDrawSurface7 *v3; // eax

  result = a2;
  if ( a2 == g_iLastUsedPage )
    return result;
  CInterfaceD3D::RenderScene(this, byte_4696877);
  g_iLastUsedPage = a2;
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup) )
  {
    v3 = (struct IDirectDrawSurface7 *)((int (__thiscall *)(CSurfaceV7 *))this->LandscapeTextureTable[g_iLastUsedPage]->GetSurfacePtr)(this->LandscapeTextureTable[g_iLastUsedPage]);
    return this->LandscapeSurfacePtr->lpVtbl->UpdateOverlayZOrder(this->LandscapeSurfacePtr, 0, v3);
  }
  else
  {
    CurrentTexturePagePtr = g_pTextureTable[g_iLastUsedPage];
    result = g_pLuminanceTablesStart + (g_iLastUsedPage << 11);
    j__TRI_palette_LUT = result;
  }
  return result;
}


// address=[0x2f860c0]
// Decompiled from CSurfaceV7 *__thiscall CInterfaceD3D::GetLandscapeRenderTargetSurface(CInterfaceD3D *this)

class CSurface *  CInterfaceD3D::GetLandscapeRenderTargetSurface(void) {
  
  return this->LandscapeSurface2;
}


// address=[0x2f86180]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::RenderScene(CInterfaceD3D *this, bool a2)

void  CInterfaceD3D::RenderScene(bool) {
  
  CInterfaceD3D *result; // eax
  unsigned int j; // [esp+4h] [ebp-Ch]
  float *i; // [esp+Ch] [ebp-4h]

  result = (CInterfaceD3D *)(unsigned __int8)SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup);
  if ( (_BYTE)result )
  {
    result = this;
    if ( (g_pVertex - this->field_0) >> 5 > 0 )
    {
      if ( a2 )
      {
        for ( i = (float *)this->field_0; (unsigned int)i < g_pVertex; i += 24 )
        {
          *i = (float)dword_3E2E284 + *i;
          i[1] = (float)dword_3E2E288 + i[1];
          i[8] = (float)dword_3E2E284 + i[8];
          i[9] = (float)dword_3E2E288 + i[9];
          i[16] = (float)dword_3E2E284 + i[16];
          i[17] = (float)dword_3E2E288 + i[17];
        }
      }
      result = (CInterfaceD3D *)((int (__stdcall *)(IDirectDrawSurface7 *, int, int, _DWORD, int, _DWORD))this->LandscapeSurfacePtr->lpVtbl->Lock)(
                                  this->LandscapeSurfacePtr,
                                  4,
                                  452,
                                  this->field_0,
                                  (g_pVertex - this->field_0) >> 5,
                                  0);
      if ( result )
      {
        WriteError(result, "DrawPrimitive");
        g_bRenderSuccess = 0;
      }
    }
  }
  else
  {
    for ( j = this->field_0; j < g_pVertex; j += 96 )
    {
      j__TRI_draw_triangle(j, j + 32, j + 64, CurrentTexturePagePtr, 8);
      result = (CInterfaceD3D *)(j + 96);
    }
  }
  g_pVertex = this->field_0;
  return result;
}


// address=[0x2f8a910]
// Decompiled from int __thiscall CInterfaceD3D::IsInterface7Available(CInterfaceD3D *this, bool *a2, HWND a3)

int  CInterfaceD3D::IsInterface7Available(bool &,struct HWND__ *) {
  
  int v4; // eax
  int v5; // eax
  int v6; // [esp+10h] [ebp-2A8h]
  int v7; // [esp+14h] [ebp-2A4h] BYREF
  int v8; // [esp+18h] [ebp-2A0h] BYREF
  HRESULT (__stdcall *DirectDrawCreateEx)(GUID *, LPVOID *, const IID *const, IUnknown *); // [esp+1Ch] [ebp-29Ch]
  BOOL v10; // [esp+20h] [ebp-298h]
  int v11; // [esp+24h] [ebp-294h] BYREF
  IDirectDraw7 *DDraw; // [esp+28h] [ebp-290h]
  HRESULT (__stdcall *v13)(GUID *, LPVOID *, const IID *const, IUnknown *); // [esp+2Ch] [ebp-28Ch]
  HMODULE hModule; // [esp+30h] [ebp-288h]
  void (__thiscall ***v15)(_DWORD, int); // [esp+34h] [ebp-284h]
  CSurfaceV7 *PrimarySurface; // [esp+38h] [ebp-280h]
  char v17; // [esp+3Ch] [ebp-27Ch] BYREF
  char v18; // [esp+3Dh] [ebp-27Bh]
  char v19; // [esp+3Eh] [ebp-27Ah]
  char v20; // [esp+3Fh] [ebp-279h]
  unsigned __int8 v21; // [esp+43h] [ebp-275h] BYREF
  int v22; // [esp+44h] [ebp-274h]
  CInterfaceD3D *v23; // [esp+48h] [ebp-270h]
  int v24; // [esp+4Ch] [ebp-26Ch] BYREF
  int v25; // [esp+50h] [ebp-268h]
  int v26; // [esp+88h] [ebp-230h]
  int v27; // [esp+188h] [ebp-130h]
  _DWORD v28[20]; // [esp+1C8h] [ebp-F0h] BYREF
  int v29; // [esp+218h] [ebp-A0h]
  int v30; // [esp+23Ch] [ebp-7Ch]
  unsigned int v31; // [esp+244h] [ebp-74h]
  unsigned int v32; // [esp+248h] [ebp-70h]
  unsigned int v33; // [esp+24Ch] [ebp-6Ch]

  v23 = this;
  *a2 = 0;
  byte_46C7938 = 0;
  if ( g_pDirectDraw )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: DirectDraw already loaded");
    return 3;
  }
  else
  {
    hModule = GetModuleHandleA("DDRAW");
    if ( hModule )
    {
      DirectDrawCreateEx = (HRESULT (__stdcall *)(GUID *, LPVOID *, const IID *const, IUnknown *))GetProcAddress(
                                                                                                    hModule,
                                                                                                    "DirectDrawCreateEx");
      v13 = DirectDrawCreateEx;
      if ( DirectDrawCreateEx )
      {
        v22 = v13(0, (LPVOID *)&v23->DDraw, &IID_IDirectDraw7, 0);
        if ( v22 )
        {
          WriteError(v22, "CreateDirectDrawObject");
          return 3;
        }
        else
        {
          g_pDirectDraw = (int)v23->DDraw;
          v22 = v23->DDraw->lpVtbl->QueryInterface(v23->DDraw, &IID_IDirectDraw7, (LPVOID *)&v23->DDraw7);
          if ( v22 )
          {
            CInterfaceD3D::CleanUpCheckObjects(v23);
            WriteError(v22, "QueryInterface");
            return 4;
          }
          else
          {
            v22 = v23->DDraw7->lpVtbl->GetDeviceIdentifier(v23->DDraw7, (LPDDDEVICEIDENTIFIER2)byte_46C7940, 1);
            if ( !v22 )
            {
              BBSupportTracePrintF(1, "GFX ENGINE: ---------------GfxAdapter Info---------------");
              BBSupportTracePrintF(1, "GFX ENGINE: ");
              BBSupportTracePrintF(1, "GFX ENGINE: Driver          : %s", byte_46C7940);
              BBSupportTracePrintF(1, "GFX ENGINE: Description     : %s", byte_46C7B40);
              BBSupportTracePrintF(1, "GFX ENGINE: DriverVersion   : %d", dword_46C7D40);
              BBSupportTracePrintF(1, "GFX ENGINE: Manufactorer    : %d", dword_46C7D48);
              BBSupportTracePrintF(1, "GFX ENGINE: Chipset         : %d", dword_46C7D4C);
              BBSupportTracePrintF(1, "GFX ENGINE: ChipsetRevision : %d", dword_46C7D54);
              BBSupportTracePrintF(1, "GFX ENGINE: BoardRevision   : %d", dword_46C7D50);
              BBSupportTracePrintF(1, "GFX ENGINE: Certification   : %d", dword_46C7D68);
              BBSupportTracePrintF(1, "GFX ENGINE: ");
              BBSupportTracePrintF(1, "GFX ENGINE: ---------------------------------------------");
              byte_46C7938 = 1;
            }
            v22 = v23->DDraw7->lpVtbl->SetCooperativeLevel(v23->DDraw7, a3, 8);
            if ( v22 )
            {
              CInterfaceD3D::CleanUpCheckObjects(v23);
              WriteError(v22, "SetCooperativeLevel");
              return 5;
            }
            else
            {
              v22 = v23->DDraw7->lpVtbl->QueryInterface(
                      v23->DDraw7,
                      &IID_IDirect3D7,
                      (LPVOID *)&v23->LandscapeRenderDevice);
              if ( v22 )
              {
                CInterfaceD3D::CleanUpCheckObjects(v23);
                WriteError(v22, "QueryD3DInterface");
                return 6;
              }
              else
              {
                v23->PrimarySurface = CSurface::CreateSurfacePtr(0);
                if ( v23->PrimarySurface )
                {
                  if ( byte_3E2E262 )
                    DDraw = v23->DDraw;
                  else
                    DDraw = v23->DDraw7;
                  v22 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD))v23->PrimarySurface->CreateSurface)(
                          v23->PrimarySurface,
                          DDraw,
                          0,
                          0,
                          1,
                          0,
                          0,
                          0,
                          1,
                          0,
                          0);
                  if ( v22 )
                  {
                    CInterfaceD3D::CleanUpCheckObjects(v23);
                    WriteError(v22, "CreatePrimarySurface");
                    return 8;
                  }
                  else
                  {
                    v22 = ((int (__thiscall *)(CSurfaceV7 *, unsigned __int8 *))v23->PrimarySurface->GetPixelFormat)(
                            v23->PrimarySurface,
                            &v21);
                    if ( v22 )
                    {
                      CInterfaceD3D::CleanUpCheckObjects(v23);
                      WriteError(v22, "RetrievePixelFormatFromPrimarySurface");
                      return 9;
                    }
                    else
                    {
                      v23->field_68 = (int)CSurface::CreateSurfacePtr(0);
                      if ( v23->field_68 )
                      {
                        v4 = j__abs(v21);
                        v22 = (*(int (__thiscall **)(int, IDirectDraw7 *, int, int, int, int, _DWORD, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v23->field_68 + 48))(
                                v23->field_68,
                                v23->DDraw7,
                                32,
                                32,
                                1,
                                1,
                                0,
                                v4,
                                0,
                                0,
                                0);
                        if ( v22 )
                        {
                          CInterfaceD3D::CleanUpCheckObjects(v23);
                          WriteError(v22, "CreateTestSurface");
                          return 7;
                        }
                        else
                        {
                          v11 = 16;
                          v22 = ((int (__thiscall *)(CSurfaceV7 *, int *))v23->PrimarySurface->j_?GetBitDepth@CSurfaceV7@@UAEJAAH@Z)(
                                  v23->PrimarySurface,
                                  &v11);
                          if ( v22 )
                          {
                            CInterfaceD3D::CleanUpCheckObjects(v23);
                            WriteError(v22, "GetBitDepthWhileCapChecking");
                            return 12;
                          }
                          else
                          {
                            v22 = ((int (__thiscall *)(CSurfaceV7 *, int *, int *))v23->PrimarySurface->GetSurfaceSize)(
                                    v23->PrimarySurface,
                                    &v8,
                                    &v7);
                            if ( v22 )
                            {
                              CInterfaceD3D::CleanUpCheckObjects(v23);
                              WriteError(v22, "GetSurfaceSizeWhileCapChecking");
                              return 11;
                            }
                            else
                            {
                              v6 = v11 / 8 * v7 * v8;
                              v24 = 380;
                              v22 = v23->DDraw->lpVtbl->GetCaps(v23->DDraw, (LPDDCAPS)&v24, 0);
                              if ( v22 )
                              {
                                CInterfaceD3D::CleanUpCheckObjects(v23);
                                WriteError(v22, "GetCapabilities");
                                return 11;
                              }
                              else if ( (unsigned __int8)sub_2F8BE40(v26, v6, &dword_760B60[65960], 0) )
                              {
                                if ( (v25 & 0x40) != 0 && ((unsigned int)&unk_4000000 & v25) != 0
                                  || (v27 & 0x40) != 0 && ((unsigned int)&unk_4000000 & v27) != 0 )
                                {
                                  if ( (v25 & 0x400000) != 0 )
                                  {
                                    v5 = (*(int (__thiscall **)(int, IDirectDrawSurface7 **))(*(_DWORD *)v23->field_68
                                                                                            + 72))(
                                           v23->field_68,
                                           &v23->LandscapeSurfacePtr);
                                    v22 = (*(int (__stdcall **)(int, GUID *, int))(*(_DWORD *)v23->LandscapeRenderDevice
                                                                                 + 16))(
                                            v23->LandscapeRenderDevice,
                                            &IID_IDirect3DHALDevice,
                                            v5);
                                    if ( v22 )
                                    {
                                      CInterfaceD3D::CleanUpCheckObjects(v23);
                                      WriteError(v22, "CreateCheckDevice");
                                      return 16;
                                    }
                                    else
                                    {
                                      v28[15] = 56;
                                      v28[1] = 56;
                                      v22 = v23->LandscapeSurfacePtr->lpVtbl->AddAttachedSurface(
                                              v23->LandscapeSurfacePtr,
                                              (LPDIRECTDRAWSURFACE7)v28);
                                      if ( v22 )
                                      {
                                        CInterfaceD3D::CleanUpCheckObjects(v23);
                                        WriteError(v22, "Get3dCaps");
                                        return 17;
                                      }
                                      else if ( (v28[0] & 0x200) != 0
                                             && (v28[0] & 0x400) != 0
                                             && (v30 & 0x400) != 0
                                             && v31 <= 0x80
                                             && v32 <= 0x80
                                             && v33 >= 0x100 )
                                      {
                                        v10 = v33 >= 0x200;
                                        *a2 = v10;
                                        if ( dword_46C7D4C == 15623 )
                                        {
                                          *a2 = 0;
                                          BBSupportTracePrintF(
                                            1,
                                            "GFX ENGINE: No HWO rendering with permedia2 chipset!");
                                        }
                                        dword_3E2E320 = v33;
                                        if ( (v29 & 4) != 0 )
                                        {
                                          v17 = 0;
                                          v18 = 0;
                                          v19 = 0;
                                          v20 = 0;
                                          v22 = ((int (__stdcall *)(IDirectDrawSurface7 *, int (__stdcall *)(struct _DDPIXELFORMAT *, void *), char *))v23->LandscapeSurfacePtr->lpVtbl->AddOverlayDirtyRect)(
                                                  v23->LandscapeSurfacePtr,
                                                  D3DEnumPixelFormatsCallback,
                                                  &v17);
                                          if ( v22 )
                                          {
                                            CInterfaceD3D::CleanUpCheckObjects(v23);
                                            *a2 = 0;
                                            WriteError(v22, "EnumerateTextureFormats");
                                            return 20;
                                          }
                                          else if ( v17 || v18 )
                                          {
                                            if ( !v19 )
                                            {
                                              *a2 = 0;
                                              BBSupportTracePrintF(
                                                1,
                                                "GFX ENGINE: The needed 4444 format are not supported by the hardware!");
                                            }
                                            if ( dword_46C7D4C == 35362
                                              || dword_46C7D4C == 35347
                                              || dword_46C7D4C == 37122 )
                                            {
                                              *a2 = 0;
                                              CInterfaceD3D::CleanUpCheckObjects(v23);
                                              BBSupportTracePrintF(1, "GFX ENGINE: Savage chipset detected!");
                                              return 26;
                                            }
                                            else
                                            {
                                              if ( v23->LandscapeSurfacePtr )
                                              {
                                                v23->LandscapeSurfacePtr->lpVtbl->Release(v23->LandscapeSurfacePtr);
                                                v23->LandscapeSurfacePtr = 0;
                                              }
                                              if ( v23->PrimarySurface )
                                              {
                                                ((void (__thiscall *)(CSurfaceV7 *))v23->PrimarySurface->j_?Release@CSurfaceV7@@UAEXXZ)(v23->PrimarySurface);
                                                PrimarySurface = v23->PrimarySurface;
                                                if ( PrimarySurface )
                                                  ((void (__thiscall *)(CSurfaceV7 *, int))PrimarySurface->j_??_GCSurfaceV7@@UAEPAXI@Z)(
                                                    PrimarySurface,
                                                    1);
                                                v23->PrimarySurface = 0;
                                              }
                                              if ( v23->field_68 )
                                              {
                                                (*(void (__thiscall **)(int))(*(_DWORD *)v23->field_68 + 4))(v23->field_68);
                                                v15 = (void (__thiscall ***)(_DWORD, int))v23->field_68;
                                                if ( v15 )
                                                  (**v15)(v15, 1);
                                                v23->field_68 = 0;
                                              }
                                              if ( v23->LandscapeRenderDevice )
                                              {
                                                (*(void (__stdcall **)(int))(*(_DWORD *)v23->LandscapeRenderDevice + 8))(v23->LandscapeRenderDevice);
                                                v23->LandscapeRenderDevice = 0;
                                              }
                                              if ( !v23->DDraw7 )
                                                return 0;
                                              v23->DDraw7->lpVtbl->Release(v23->DDraw7);
                                              v23->DDraw7 = 0;
                                              return 0;
                                            }
                                          }
                                          else
                                          {
                                            CInterfaceD3D::CleanUpCheckObjects(v23);
                                            *a2 = 0;
                                            BBSupportTracePrintF(
                                              1,
                                              "GFX ENGINE: The needed texture formats are not supported by the hardware!");
                                            return 21;
                                          }
                                        }
                                        else
                                        {
                                          CInterfaceD3D::CleanUpCheckObjects(v23);
                                          BBSupportTracePrintF(
                                            1,
                                            "GFX ENGINE: Needed alpha blend capabilities for hardware rendering unsupported!");
                                          return 19;
                                        }
                                      }
                                      else
                                      {
                                        CInterfaceD3D::CleanUpCheckObjects(v23);
                                        BBSupportTracePrintF(
                                          1,
                                          "GFX ENGINE: A needed basic capability for the hardware renderer is unsupported!");
                                        return 18;
                                      }
                                    }
                                  }
                                  else
                                  {
                                    CInterfaceD3D::CleanUpCheckObjects(v23);
                                    BBSupportTracePrintF(
                                      1,
                                      "GFX ENGINE: Color keying is not in all needed blit modes available!");
                                    return 15;
                                  }
                                }
                                else
                                {
                                  CInterfaceD3D::CleanUpCheckObjects(v23);
                                  BBSupportTracePrintF(1, "GFX ENGINE: Needed blit capabilities are not supported!");
                                  return 14;
                                }
                              }
                              else
                              {
                                CInterfaceD3D::CleanUpCheckObjects(v23);
                                BBSupportTracePrintF(1, "GFX ENGINE: Not enough video memory available!");
                                return 13;
                              }
                            }
                          }
                        }
                      }
                      else
                      {
                        CInterfaceD3D::CleanUpCheckObjects(v23);
                        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                        return 10;
                      }
                    }
                  }
                }
                else
                {
                  CInterfaceD3D::CleanUpCheckObjects(v23);
                  BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                  return 7;
                }
              }
            }
          }
        }
      }
      else
      {
        BBSupportTracePrintF(1, "GFX ENGINE: DirectDrawCreateEx not found! Interface 7 or higher not available!");
        return 2;
      }
    }
    else
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Direct Draw is not accessible!");
      return 1;
    }
  }
}


// address=[0x2f8b530]
// Decompiled from int __thiscall CInterfaceD3D::IsInterface3Available(CInterfaceD3D *this, HWND a2)

int  CInterfaceD3D::IsInterface3Available(struct HWND__ *) {
  
  int v3; // eax
  int v4; // [esp+10h] [ebp-1A4h]
  int v5; // [esp+14h] [ebp-1A0h] BYREF
  int v6; // [esp+18h] [ebp-19Ch] BYREF
  int v7; // [esp+1Ch] [ebp-198h] BYREF
  void (__thiscall ***v8)(_DWORD, int); // [esp+20h] [ebp-194h]
  CSurfaceV7 *PrimarySurface; // [esp+24h] [ebp-190h]
  unsigned __int8 v10; // [esp+2Bh] [ebp-189h] BYREF
  HRESULT v11; // [esp+2Ch] [ebp-188h]
  CInterfaceD3D *v12; // [esp+30h] [ebp-184h]
  int v13; // [esp+34h] [ebp-180h] BYREF
  int v14; // [esp+38h] [ebp-17Ch]
  int v15; // [esp+70h] [ebp-144h]
  int v16; // [esp+170h] [ebp-44h]

  v12 = this;
  byte_46C7938 = 0;
  if ( g_pDirectDraw )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: DirectDraw already loaded");
    return 3;
  }
  else
  {
    v11 = DirectDrawCreate(0, (LPDIRECTDRAW *)&v12->DDraw, 0);
    if ( v11 )
    {
      WriteError(v11, "CreateDirectDrawObject");
      return 3;
    }
    else
    {
      g_pDirectDraw = (int)v12->DDraw;
      v11 = v12->DDraw->lpVtbl->SetCooperativeLevel(v12->DDraw, a2, 8);
      if ( v11 )
      {
        CInterfaceD3D::CleanUpCheckObjects(v12);
        WriteError(v11, "SetCooperativeLevel");
        return 5;
      }
      else
      {
        v12->PrimarySurface = CSurface::CreateSurfacePtr(1);
        if ( v12->PrimarySurface )
        {
          v11 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD))v12->PrimarySurface->CreateSurface)(
                  v12->PrimarySurface,
                  v12->DDraw,
                  0,
                  0,
                  1,
                  0,
                  0,
                  0,
                  1,
                  0,
                  0);
          if ( v11 )
          {
            CInterfaceD3D::CleanUpCheckObjects(v12);
            WriteError(v11, "CreatePrimarySurface");
            return 8;
          }
          else
          {
            v11 = ((int (__thiscall *)(CSurfaceV7 *, unsigned __int8 *))v12->PrimarySurface->GetPixelFormat)(
                    v12->PrimarySurface,
                    &v10);
            if ( v11 )
            {
              CInterfaceD3D::CleanUpCheckObjects(v12);
              WriteError(v11, "RetrievePixelFormatFromPrimarySurface");
              return 9;
            }
            else
            {
              v12->field_68 = (int)CSurface::CreateSurfacePtr(1);
              if ( v12->field_68 )
              {
                v3 = j__abs(v10);
                v11 = (*(int (__thiscall **)(int, IDirectDraw7 *, int, int, int, int, _DWORD, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12->field_68 + 48))(
                        v12->field_68,
                        v12->DDraw,
                        32,
                        32,
                        1,
                        1,
                        0,
                        v3,
                        0,
                        0,
                        0);
                if ( v11 )
                {
                  CInterfaceD3D::CleanUpCheckObjects(v12);
                  WriteError(v11, "CreateTestSurface");
                  return 7;
                }
                else
                {
                  v7 = 16;
                  v11 = ((int (__thiscall *)(CSurfaceV7 *, int *))v12->PrimarySurface->j_?GetBitDepth@CSurfaceV7@@UAEJAAH@Z)(
                          v12->PrimarySurface,
                          &v7);
                  if ( v11 )
                  {
                    CInterfaceD3D::CleanUpCheckObjects(v12);
                    WriteError(v11, "GetBitDepthWhileCapChecking");
                    return 12;
                  }
                  else
                  {
                    v11 = ((int (__thiscall *)(CSurfaceV7 *, int *, int *))v12->PrimarySurface->GetSurfaceSize)(
                            v12->PrimarySurface,
                            &v6,
                            &v5);
                    if ( v11 )
                    {
                      CInterfaceD3D::CleanUpCheckObjects(v12);
                      WriteError(v11, "GetSurfaceSizeWhileCapChecking");
                      return 12;
                    }
                    else
                    {
                      v4 = v7 / 8 * v5 * v6;
                      v13 = 380;
                      v11 = v12->DDraw->lpVtbl->GetCaps(v12->DDraw, (LPDDCAPS)&v13, 0);
                      if ( v11 )
                      {
                        CInterfaceD3D::CleanUpCheckObjects(v12);
                        WriteError(v11, "GetCapabilities");
                        return 11;
                      }
                      else if ( (unsigned __int8)sub_2F8BE40(v15, v4, 4000000, 0) )
                      {
                        if ( (v14 & 0x40) != 0 && ((unsigned int)&unk_4000000 & v14) != 0
                          || (v16 & 0x40) != 0 && ((unsigned int)&unk_4000000 & v16) != 0 )
                        {
                          if ( (v14 & 0x400000) != 0 )
                          {
                            if ( v12->LandscapeSurfacePtr )
                            {
                              v12->LandscapeSurfacePtr->lpVtbl->Release(v12->LandscapeSurfacePtr);
                              v12->LandscapeSurfacePtr = 0;
                            }
                            if ( v12->PrimarySurface )
                            {
                              ((void (__thiscall *)(CSurfaceV7 *))v12->PrimarySurface->j_?Release@CSurfaceV7@@UAEXXZ)(v12->PrimarySurface);
                              PrimarySurface = v12->PrimarySurface;
                              if ( PrimarySurface )
                                ((void (__thiscall *)(CSurfaceV7 *, int))PrimarySurface->j_??_GCSurfaceV7@@UAEPAXI@Z)(
                                  PrimarySurface,
                                  1);
                              v12->PrimarySurface = 0;
                            }
                            if ( v12->field_68 )
                            {
                              (*(void (__thiscall **)(int))(*(_DWORD *)v12->field_68 + 4))(v12->field_68);
                              v8 = (void (__thiscall ***)(_DWORD, int))v12->field_68;
                              if ( v8 )
                                (**v8)(v8, 1);
                              v12->field_68 = 0;
                            }
                            if ( v12->LandscapeRenderDevice )
                            {
                              (*(void (__stdcall **)(int))(*(_DWORD *)v12->LandscapeRenderDevice + 8))(v12->LandscapeRenderDevice);
                              v12->LandscapeRenderDevice = 0;
                            }
                            if ( !v12->DDraw7 )
                              return 0;
                            v12->DDraw7->lpVtbl->Release(v12->DDraw7);
                            v12->DDraw7 = 0;
                            return 0;
                          }
                          else
                          {
                            CInterfaceD3D::CleanUpCheckObjects(v12);
                            BBSupportTracePrintF(
                              1,
                              "GFX ENGINE: Color keying is not in all needed blit modes available!");
                            return 15;
                          }
                        }
                        else
                        {
                          CInterfaceD3D::CleanUpCheckObjects(v12);
                          BBSupportTracePrintF(1, "GFX ENGINE: Needed blit capabilities are not supported!");
                          return 14;
                        }
                      }
                      else
                      {
                        CInterfaceD3D::CleanUpCheckObjects(v12);
                        BBSupportTracePrintF(1, "GFX ENGINE: Not enough video memory available!");
                        return 13;
                      }
                    }
                  }
                }
              }
              else
              {
                CInterfaceD3D::CleanUpCheckObjects(v12);
                BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                return 10;
              }
            }
          }
        }
        else
        {
          CInterfaceD3D::CleanUpCheckObjects(v12);
          BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
          return 10;
        }
      }
    }
  }
}


// address=[0x2f8bba0]
// Decompiled from // public: bool __thiscall CInterfaceD3D::CanCreateEngine(bool)
char __thiscall CInterfaceD3D::CanCreateEngine(_DWORD *this, bool a2)

bool  CInterfaceD3D::CanCreateEngine(bool) {
  
  int v3; // eax
  int v5; // [esp+14h] [ebp-14h]
  CSurfaceV7 *SurfacePtr; // [esp+24h] [ebp-4h]

  SurfacePtr = CSurface::CreateSurfacePtr(a2);
  if ( SurfacePtr )
  {
    v3 = j__abs(dword_3E2E2B8 == 1);
    v5 = ((int (__thiscall *)(CSurfaceV7 *, _DWORD, int, int, int, int, _DWORD, int, _DWORD, _DWORD, _DWORD))SurfacePtr->CreateSurface)(
           SurfacePtr,
           this[1],
           32,
           32,
           1,
           1,
           0,
           v3,
           0,
           0,
           0);
    if ( v5 )
    {
      WriteError(v5, "CanRebuildEngine");
      ((void (__thiscall *)(CSurfaceV7 *, int))SurfacePtr->j_??_GCSurfaceV7@@UAEPAXI@Z)(SurfacePtr, 1);
      return 0;
    }
    else
    {
      ((void (__thiscall *)(CSurfaceV7 *))SurfacePtr->j_?Release@CSurfaceV7@@UAEXXZ)(SurfacePtr);
      ((void (__thiscall *)(CSurfaceV7 *, int))SurfacePtr->j_??_GCSurfaceV7@@UAEPAXI@Z)(SurfacePtr, 1);
      return 1;
    }
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
    return 0;
  }
}


// address=[0x2f8bcc0]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::CleanUpCheckObjects(CInterfaceD3D *this)

void  CInterfaceD3D::CleanUpCheckObjects(void) {
  
  CInterfaceD3D *result; // eax

  if ( this->LandscapeSurfacePtr )
  {
    this->LandscapeSurfacePtr->lpVtbl->Release(this->LandscapeSurfacePtr);
    this->LandscapeSurfacePtr = 0;
  }
  if ( this->PrimarySurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->PrimarySurface->j_?Release@CSurfaceV7@@UAEXXZ)(this->PrimarySurface);
    if ( this->PrimarySurface )
      ((void (__thiscall *)(CSurfaceV7 *, int))this->PrimarySurface->j_??_GCSurfaceV7@@UAEPAXI@Z)(
        this->PrimarySurface,
        1);
    this->PrimarySurface = 0;
  }
  if ( this->field_68 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)this->field_68 + 4))(this->field_68);
    if ( this->field_68 )
      (**(void (__thiscall ***)(int, int))this->field_68)(this->field_68, 1);
    this->field_68 = 0;
  }
  if ( this->LandscapeRenderDevice )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)this->LandscapeRenderDevice + 8))(this->LandscapeRenderDevice);
    this->LandscapeRenderDevice = 0;
  }
  if ( this->DDraw7 )
  {
    this->DDraw7->lpVtbl->Release(this->DDraw7);
    this->DDraw7 = 0;
  }
  result = this;
  if ( !this->DDraw )
    return result;
  result = (CInterfaceD3D *)this->DDraw->lpVtbl->Release(this->DDraw);
  this->DDraw = 0;
  g_pDirectDraw = 0;
  return result;
}


// address=[0x2f996f0]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::DecreaseCacheRetrys(CInterfaceD3D *this)

void  CInterfaceD3D::DecreaseCacheRetrys(void) {
  
  CInterfaceD3D *result; // eax

  result = this;
  --this->field_73C;
  return result;
}


// address=[0x2f99720]
// Decompiled from int __thiscall CInterfaceD3D::GetCacheRetrys(CInterfaceD3D *this)

int  CInterfaceD3D::GetCacheRetrys(void) {
  
  return this->field_73C;
}


