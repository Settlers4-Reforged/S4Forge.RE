#include "CInterfaceD3D.h"

// Definitions for class CInterfaceD3D

// address=[0x2f5f250]
// Decompiled from HRESULT __thiscall CInterfaceD3D::BlitCursor(CInterfaceD3D *this)
void  CInterfaceD3D::BlitCursor(void) {
  
  HRESULT result; // eax
  int v2; // [esp+0h] [ebp-8h]

  v2 = CFixCursor::Show((CFixCursor *)&this[1].m_sClipper1.m_vChar.uC, this->FinalRenderSurface);
  if ( v2 )
  {
    WriteError(v2, "BlitMoveCursor");
  }
  result = CFixCursor::Show((CFixCursor *)&this[1].m_sViewport.dwY, this->FinalRenderSurface);
  HIBYTE(this[1].m_sClipper1.m_vChar.u8) = 1;
  if ( result )
  {
    return WriteError(result, "BlitZoomCursor");
  }
  return result;
}


// address=[0x2f5f390]
// Decompiled from bool __thiscall CInterfaceD3D::HasCameraWindowSurface(CInterfaceD3D *this)
bool  CInterfaceD3D::HasCameraWindowSurface(void)const {
  
  return this->m_pCameraWindowSurface != 0;
}


// address=[0x2f62860]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::CInterfaceD3D(CInterfaceD3D *this)
 CInterfaceD3D::CInterfaceD3D(void) {
  
  unsigned int i; // [esp+4h] [ebp-14h]
  int j; // [esp+4h] [ebp-14h]
  int k; // [esp+4h] [ebp-14h]

  SurfaceClipper::SurfaceClipper(&this->m_sClipper1);
  SurfaceClipper::SurfaceClipper(&this->m_sMinimapClipper);
  CFixCursor::CFixCursor((CFixCursor *)&this[1].m_sClipper1.m_vChar.uC);
  CFixCursor::CFixCursor((CFixCursor *)&this[1].m_sViewport.dwY);
  this[1].m_sClipper1.m_vChar.u4 = 2000;
  HIBYTE(this[1].m_sClipper1.m_vChar.u8) = 0;
  BYTE2(this[1].m_sClipper1.m_vChar.u8) = 0;
  BYTE1(this[1].m_sClipper1.m_vChar.u8) = 0;
  this[1].m_sClipper1.m_pClipper = 0;
  this->m_uCacheSurfaceCount = 0;
  LOBYTE(this[1].m_sClipper1.m_vChar.u8) = 0;
  this[1].m_pDDraw = 0;
  this[1].field_0 = 0;
  memset(this->field_71E, 0, sizeof(this->field_71E));
  this->m_bInitHardware = 0;
  this->m_bInitSoftware = 0;
  this->m_bGfxEngineRebuilded = 1;
  g_uGfxMode = 0;
  for ( i = 0;
        i < 14;
        ++i )
  {
    this->m_pGuiSurfaces[i] = 0;
  }
  CInterfaceD3D::InitTexturedLandscapeModule(this);
  this->m_pDDraw = 0;
  this->m_pDDraw7 = 0;
  this->m_pZoomCursorSurface = 0;
  this->m_pMoveCursorSurface = 0;
  this->field_68 = 0;
  this->MiniMapAreaSurface = 0;
  this->MiniMapSurface = 0;
  this->LandscapeSurface = 0;
  this->m_pCameraWindowSurface = 0;
  this->LandscapeSurface2 = 0;
  this->FinalRenderSurface = 0;
  this->PrimarySurface = 0;
  this->m_pIDirect3D7 = 0;
  this->LandscapeDevice = 0;
  this->m_pObjectDevice = 0;
  this->field_0 = 0;
  for ( j = 0;
        j < 2;
        ++j )
  {
    this->ObjectTextureTable[j] = 0;
    this->ObjectTextureSystemMemoryTable[j] = 0;
    this->CCachePageManager[j] = 0;
  }
  for ( k = 0;
        k < 180;
        ++k )
  {
    this->m_pCacheSurfaces[k] = 0;
    this->m_pCacheManagers[k] = 0;
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

  for ( i = 179;
        i >= 0;
        --i )
  {
    if ( this->m_pCacheManagers[i] )
    {
      if ( CCachePageManager::IsVideoSurfaceLocked((CCachePageManager *)this->m_pCacheManagers[i]) )
      {
        CCachePageManager::UnlockVideoSurface((CCachePageManager *)this->m_pCacheManagers[i]);
      }
      if ( CCachePageManager::IsSourceSurfaceLocked((CCachePageManager *)this->m_pCacheManagers[i]) )
      {
        CCachePageManager::UnlockSourceSurface((CCachePageManager *)this->m_pCacheManagers[i]);
      }
      v2 = (CCachePageManager *)this->m_pCacheManagers[i];
      if ( v2 )
      {
        delete v2;
      }
      this->m_pCacheManagers[i] = 0;
    }
    if ( this->m_pCacheSurfaces[i] )
    {
      (*(void (__stdcall **)(DWORD))(*(_DWORD *)this->m_pCacheSurfaces[i] + 8))(this->m_pCacheSurfaces[i]);
      this->m_pCacheSurfaces[i] = 0;
    }
  }
  for ( j = 1;
        j >= 0;
        --j )
  {
    if ( this->CCachePageManager[j] )
    {
      if ( CCachePageManager::IsVideoSurfaceLocked((CCachePageManager *)this->CCachePageManager[j]) )
      {
        CCachePageManager::UnlockVideoSurface((CCachePageManager *)this->CCachePageManager[j]);
      }
      if ( CCachePageManager::IsSourceSurfaceLocked((CCachePageManager *)this->CCachePageManager[j]) )
      {
        CCachePageManager::UnlockSourceSurface((CCachePageManager *)this->CCachePageManager[j]);
      }
      v1 = (CUploadCachePageManager *)this->CCachePageManager[j];
      if ( v1 )
      {
        delete v1;
      }
      this->CCachePageManager[j] = 0;
    }
    if ( this->ObjectTextureSystemMemoryTable[j] )
    {
      ((void (__thiscall *)(CSurfaceV7 *))this->ObjectTextureSystemMemoryTable[j]->Release)(this->ObjectTextureSystemMemoryTable[j]);
      v14 = this->ObjectTextureSystemMemoryTable[j];
      if ( v14 )
      {
        ((void (__thiscall *)(CSurfaceV7 *, int))v14->dtor)(v14, 1);
      }
      this->ObjectTextureSystemMemoryTable[j] = 0;
    }
    if ( this->ObjectTextureTable[j] )
    {
      ((void (__thiscall *)(CSurfaceV7 *))this->ObjectTextureTable[j]->Release)(this->ObjectTextureTable[j]);
      v13 = this->ObjectTextureTable[j];
      if ( v13 )
      {
        ((void (__thiscall *)(CSurfaceV7 *, int))v13->dtor)(v13, 1);
      }
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
    SetClassLongA(MEMORY[0x3E2E268], -12, s_hCursor);
    SetCursor((HCURSOR)s_hCursor);
    s_hCursor = 0;
  }
  SurfaceClipper::ReleaseClipper((SurfaceClipper *)&this->m_sClipper1);
  SurfaceClipper::ReleaseClipper((SurfaceClipper *)&this->m_sMinimapClipper);
  if ( g_pSoftwareTexturePages )
  {
    operator delete[]((void *)g_pSoftwareTexturePages);
    g_pSoftwareTexturePages = 0;
    for ( k = 0;
          k < 44;
          ++k )
    {
      g_pTextureTable[k] = 0;
    }
  }
  for ( m = 43;
        m >= 0;
        --m )
  {
    if ( this->LandscapeTextureTable[m] )
    {
      ((void (__thiscall *)(CSurfaceV7 *))this->LandscapeTextureTable[m]->Release)(this->LandscapeTextureTable[m]);
      v12 = this->LandscapeTextureTable[m];
      if ( v12 )
      {
        ((void (__thiscall *)(CSurfaceV7 *, int))v12->dtor)(v12, 1);
      }
      this->LandscapeTextureTable[m] = 0;
    }
    g_pTextureTable[m] = 0;
  }
  for ( n = 14;
        n >= 0;
        --n )
  {
    if ( this->m_pGuiSurfaces[n] )
    {
      (*(void (__thiscall **)(DWORD))(*(_DWORD *)this->m_pGuiSurfaces[n] + 4))(this->m_pGuiSurfaces[n]);
      v11 = (void (__thiscall ***)(_DWORD, int))this->m_pGuiSurfaces[n];
      if ( v11 )
      {
        (**v11)(v11, 1);
      }
      this->m_pGuiSurfaces[n] = 0;
    }
  }
  SurfaceClipper::ReleaseClipper((SurfaceClipper *)&this->m_sClipper1);
  SurfaceClipper::ReleaseClipper((SurfaceClipper *)&this->m_sMinimapClipper);
  if ( this->m_pObjectDevice )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)this->m_pObjectDevice + 8))(this->m_pObjectDevice);
  }
  if ( this->LandscapeDevice )
  {
    this->LandscapeDevice->lpVtbl->Release(this->LandscapeDevice);
  }
  if ( this->m_pZoomCursorSurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->m_pZoomCursorSurface->Release)(this->m_pZoomCursorSurface);
    ZoomCursorSurface = this->m_pZoomCursorSurface;
    if ( ZoomCursorSurface )
    {
      ((void (__thiscall *)(CSurfaceV7 *, int))ZoomCursorSurface->dtor)(ZoomCursorSurface, 1);
    }
    this->m_pZoomCursorSurface = 0;
  }
  if ( this->m_pMoveCursorSurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->m_pMoveCursorSurface->Release)(this->m_pMoveCursorSurface);
    MoveCursorSurface = this->m_pMoveCursorSurface;
    if ( MoveCursorSurface )
    {
      ((void (__thiscall *)(CSurfaceV7 *, int))MoveCursorSurface->dtor)(MoveCursorSurface, 1);
    }
    this->m_pMoveCursorSurface = 0;
  }
  if ( this->LandscapeSurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->LandscapeSurface->Release)(this->LandscapeSurface);
    LandscapeSurface = this->LandscapeSurface;
    if ( LandscapeSurface )
    {
      ((void (__thiscall *)(CSurfaceV7 *, int))LandscapeSurface->dtor)(LandscapeSurface, 1);
    }
    this->LandscapeSurface = 0;
  }
  CInterfaceD3D::DestroyCameraWindowSurface(this);
  if ( this->FinalRenderSurface )
  {
    if ( !((unsigned __int8 (__thiscall *)(CSurfaceV7 *))this->FinalRenderSurface->j_?IsBackBufferReference@CSurfaceV7@@UAE_NXZ)(this->FinalRenderSurface) )
    {
      ((void (__thiscall *)(CSurfaceV7 *))this->FinalRenderSurface->Release)(this->FinalRenderSurface);
    }
    FinalRenderSurface = this->FinalRenderSurface;
    if ( FinalRenderSurface )
    {
      ((void (__thiscall *)(CSurfaceV7 *, int))FinalRenderSurface->dtor)(FinalRenderSurface, 1);
    }
    this->FinalRenderSurface = 0;
  }
  if ( this->MiniMapSurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->MiniMapSurface->Release)(this->MiniMapSurface);
    MiniMapSurface = this->MiniMapSurface;
    if ( MiniMapSurface )
    {
      ((void (__thiscall *)(CSurfaceV7 *, int))MiniMapSurface->dtor)(MiniMapSurface, 1);
    }
    this->MiniMapSurface = 0;
  }
  if ( this->MiniMapAreaSurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->MiniMapAreaSurface->Release)(this->MiniMapAreaSurface);
    MiniMapAreaSurface = this->MiniMapAreaSurface;
    if ( MiniMapAreaSurface )
    {
      ((void (__thiscall *)(CSurfaceV7 *, int))MiniMapAreaSurface->dtor)(MiniMapAreaSurface, 1);
    }
    this->MiniMapAreaSurface = 0;
  }
  if ( this->PrimarySurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->PrimarySurface->Release)(this->PrimarySurface);
    PrimarySurface = this->PrimarySurface;
    if ( PrimarySurface )
    {
      ((void (__thiscall *)(CSurfaceV7 *, int))PrimarySurface->dtor)(PrimarySurface, 1);
    }
    this->PrimarySurface = 0;
  }
  if ( this->field_68 )
  {
    v3 = (void (__thiscall ***)(_DWORD, int))this->field_68;
    if ( v3 )
    {
      (**v3)(v3, 1);
    }
    this->field_68 = 0;
  }
  if ( this->m_pDDraw7 )
  {
    this->m_pDDraw7->lpVtbl->Release(this->m_pDDraw7);
  }
  if ( this->m_pIDirect3D7 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)this->m_pIDirect3D7 + 8))(this->m_pIDirect3D7);
  }
  this->m_pDDraw = 0;
  this->m_pDDraw7 = 0;
  this->m_pIDirect3D7 = 0;
  this->LandscapeDevice = 0;
  this->m_pObjectDevice = 0;
  CInterfaceD3D::DeleteEngineData(this);
  BBSupportTracePrintF(1, "GFX ENGINE: DD interface successfully destroyed!");
  SurfaceClipper::~SurfaceClipper((SurfaceClipper *)&this->m_sMinimapClipper);
  SurfaceClipper::~SurfaceClipper((SurfaceClipper *)&this->m_sClipper1);
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
  int Clipper; // eax
  int v10; // [esp-10h] [ebp-78h]
  int v11; // [esp-10h] [ebp-78h]
  int HardwareLandscapeEngine; // [esp-8h] [ebp-70h]
  BOOL v14; // [esp+8h] [ebp-60h]
  IDirectDraw7 *v15; // [esp+Ch] [ebp-5Ch]
  IDirectDraw7 *v16; // [esp+14h] [ebp-54h]
  IDirectDraw7 *v17; // [esp+1Ch] [ebp-4Ch]
  IDirectDraw7 *v18; // [esp+2Ch] [ebp-3Ch]
  IDirectDraw7 *m_pDDraw7; // [esp+3Ch] [ebp-2Ch]
  IDirectDraw7 *m_pDDraw; // [esp+44h] [ebp-24h] MAPDST
  HRESULT (__stdcall *DirectDrawCreateEx)(GUID *, LPVOID *, const IID *const, IUnknown *); // [esp+4Ch] [ebp-1Ch]
  HMODULE hModule; // [esp+50h] [ebp-18h]
  int i; // [esp+58h] [ebp-10h]
  int v24; // [esp+5Ch] [ebp-Ch]
  int v25; // [esp+5Ch] [ebp-Ch]
  int v26; // [esp+5Ch] [ebp-Ch]
  CSurfaceV7 *v27; // [esp+5Ch] [ebp-Ch]
  int v28; // [esp+5Ch] [ebp-Ch]
  CSurfaceV7 *v29; // [esp+5Ch] [ebp-Ch]
  CSurfaceV7 *v30; // [esp+5Ch] [ebp-Ch]
  CSurfaceV7 *v31; // [esp+5Ch] [ebp-Ch]
  CSurfaceV7 *v32; // [esp+5Ch] [ebp-Ch]
  int v33; // [esp+5Ch] [ebp-Ch]
  int v34; // [esp+5Ch] [ebp-Ch]
  CSurfaceV7 *v35; // [esp+5Ch] [ebp-Ch]
  CSurfaceV7 *v36; // [esp+5Ch] [ebp-Ch]
  HRESULT inited; // [esp+5Ch] [ebp-Ch]
  HRESULT v38; // [esp+5Ch] [ebp-Ch]
  int v39; // [esp+5Ch] [ebp-Ch]
  int v40; // [esp+5Ch] [ebp-Ch]
  char v42; // [esp+67h] [ebp-1h] BYREF

  BBSupportTracePrintF(1, "GFX ENGINE: Begin common init. Mode: Interface 7.");
  if ( this->m_bInitHardware || this->m_bInitSoftware )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT COMMON: Engine is already initialized!");
    return 1;
  }
  BYTE1(this[1].m_sClipper1.m_vChar.u8) = SGfxRenderConfiguration::IsHQTextureSet(&GfxEngineSetup);
  BYTE2(this[1].m_sClipper1.m_vChar.u8) = !SGfxRenderConfiguration::IsForceBlit(&GfxEngineSetup);
  if ( s_hCursor )
  {
    SetClassLongA(GfxEngineSetup.m_hWnd, -12, s_hCursor);
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
  for ( i = 0;
        i < 36;
        ++i )
  {
    if ( !s_hCursorHandles[i] )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Couldn't create cursors!");
      return 0;
    }
  }
  g_bForceMiniMapRefresh = 1;
  this->field_68 = (int)CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
  if ( !this->field_68 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
    return 0;
  }
  if ( g_pDirectDraw )
  {
    this->m_pDDraw = g_pDirectDraw;
  }
  else
  {
    hModule = GetModuleHandleA("DDRAW");
    if ( !hModule )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Direct Draw is not accessible!");
      return 0;
    }
    DirectDrawCreateEx = (HRESULT (__stdcall *)(GUID *, LPVOID *, const IID *const, IUnknown *))GetProcAddress(hModule, "DirectDrawCreateEx");
    if ( !DirectDrawCreateEx )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: DirectDrawCreateEx not found! Interface 7 or higher not available!");
      return 0;
    }
    v24 = DirectDrawCreateEx(0, (LPVOID *)&this->m_pDDraw, &IID_IDirectDraw7, 0);
    if ( v24 )
    {
      WriteError(v24, "CreateDirectDrawObject");
      return 0;
    }
    g_pDirectDraw = this->m_pDDraw;
  }
  v25 = this->m_pDDraw->lpVtbl->QueryInterface(this->m_pDDraw, &IID_IDirectDraw7, (LPVOID *)&this->m_pDDraw7);
  if ( v25 )
  {
    WriteError(v25, "QueryInterface");
    return 0;
  }
  else
  {
    v26 = this->m_pDDraw7->lpVtbl->SetCooperativeLevel(this->m_pDDraw7, GfxEngineSetup.m_hWnd, 8);
    if ( v26 )
    {
      WriteError(v26, "SetCooperativeLevel");
      return 0;
    }
    else
    {
      this->PrimarySurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
      if ( this->PrimarySurface )
      {
        if ( GfxEngineSetup.m_bD3DInterface )
        {
          m_pDDraw = this->m_pDDraw;
        }
        else
        {
          m_pDDraw = this->m_pDDraw7;
        }
        v2 = j__abs(g_uGfxMode == 1);
        v27 = this->PrimarySurface->CreateSurface(this->PrimarySurface, m_pDDraw, GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight, 1, 0, 0, v2, 1, 0, 0);
        if ( v27 )
        {
          WriteError((int)v27, "CreatePrimarySurface");
          return 0;
        }
        else
        {
          v28 = ((int (__thiscall *)(CSurfaceV7 *, char *))this->PrimarySurface->GetPixelFormat)(this->PrimarySurface, &v42);
          if ( v28 )
          {
            WriteError(v28, "RetrievePixelFormatFromPrimarySurface");
            return 0;
          }
          else
          {
            if ( v42 )
            {
              g_uGfxMode = 1;
            }
            else
            {
              g_uGfxMode = 2;
            }
            this->m_pMoveCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
            if ( this->m_pMoveCursorSurface )
            {
              if ( GfxEngineSetup.m_bD3DInterface )
              {
                m_pDDraw7 = this->m_pDDraw;
              }
              else
              {
                m_pDDraw7 = this->m_pDDraw7;
              }
              v3 = j__abs(g_uGfxMode == 1);
              v29 = this->m_pMoveCursorSurface->CreateSurface(this->m_pMoveCursorSurface, m_pDDraw7, 32, 32, 1, 0, 0, v3, 0, 0, 0);
              if ( v29 )
              {
                WriteError((int)v29, "CreateMoveCursorSurface");
                return 0;
              }
              else
              {
                if ( g_uGfxMode == 1 )
                {
                  CFixCursor::SetSurfacePtr((CFixCursor *)&this[1].m_sClipper1.m_vChar.uC, 0x73u, this->m_pMoveCursorSurface, g_sColorKeyMagenta555);
                }
                else
                {
                  CFixCursor::SetSurfacePtr((CFixCursor *)&this[1].m_sClipper1.m_vChar.uC, 0x73u, this->m_pMoveCursorSurface, g_sColorKeyMagenta565);
                }
                if ( g_uGfxMode == 1 )
                {
                  this->m_pMoveCursorSurface->SetColorKey(this->m_pMoveCursorSurface, 8, &g_sColorKeyMagenta555);
                }
                else
                {
                  this->m_pMoveCursorSurface->SetColorKey(this->m_pMoveCursorSurface, 8, &g_sColorKeyMagenta565);
                }
                this->m_pZoomCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
                if ( this->m_pZoomCursorSurface )
                {
                  if ( GfxEngineSetup.m_bD3DInterface )
                  {
                    v18 = this->m_pDDraw;
                  }
                  else
                  {
                    v18 = this->m_pDDraw7;
                  }
                  v4 = j__abs(g_uGfxMode == 1);
                  v30 = this->m_pZoomCursorSurface->CreateSurface(this->m_pZoomCursorSurface, v18, 32, 32, 1, 0, 0, v4, 0, 0, 0);
                  if ( v30 )
                  {
                    WriteError((int)v30, "CreateZoomCursorSurface");
                    return 0;
                  }
                  else
                  {
                    if ( g_uGfxMode == 1 )
                    {
                      CFixCursor::SetSurfacePtr((CFixCursor *)&this[1].m_sViewport.dwY, 0x74u, this->m_pZoomCursorSurface, g_sColorKeyMagenta555);
                    }
                    else
                    {
                      CFixCursor::SetSurfacePtr((CFixCursor *)&this[1].m_sViewport.dwY, 0x74u, this->m_pZoomCursorSurface, g_sColorKeyMagenta565);
                    }
                    if ( g_uGfxMode == 1 )
                    {
                      this->m_pZoomCursorSurface->SetColorKey(this->m_pZoomCursorSurface, 8, &g_sColorKeyMagenta555);
                    }
                    else
                    {
                      this->m_pZoomCursorSurface->SetColorKey(this->m_pZoomCursorSurface, 8, &g_sColorKeyMagenta565);
                    }
                    this->MiniMapSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
                    if ( this->MiniMapSurface )
                    {
                      if ( GfxEngineSetup.m_bD3DInterface )
                      {
                        v17 = this->m_pDDraw;
                      }
                      else
                      {
                        v17 = this->m_pDDraw7;
                      }
                      v5 = j__abs(g_uGfxMode == 1);
                      v31 = this->MiniMapSurface->CreateSurface(this->MiniMapSurface, v17, 240, 160, 1, 0, 0, v5, 0, 0, 0);
                      if ( v31 )
                      {
                        WriteError((int)v31, "CreateMiniMapSurface");
                        return 0;
                      }
                      else
                      {
                        this->MiniMapSurface->ClearSurface(this->MiniMapSurface, 0);
                        this->MiniMapSurface->SetColorKey(this->MiniMapSurface, 8, (int *)&g_sColorKeyBlack);
                        this->MiniMapAreaSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
                        if ( this->MiniMapAreaSurface )
                        {
                          if ( GfxEngineSetup.m_bD3DInterface )
                          {
                            v16 = this->m_pDDraw;
                          }
                          else
                          {
                            v16 = this->m_pDDraw7;
                          }
                          v6 = j__abs(g_uGfxMode == 1);
                          v32 = this->MiniMapAreaSurface->CreateSurface(this->MiniMapAreaSurface, v16, 240, 160, 1, 0, 0, v6, 0, 0, 0);
                          if ( v32 )
                          {
                            WriteError((int)v32, "CreateMiniMapAreaSurface");
                            return 0;
                          }
                          else
                          {
                            v33 = this->MiniMapAreaSurface->ClearSurface(this->MiniMapAreaSurface, 0);
                            if ( v33 )
                            {
                              WriteError(v33, "ClearMiniMapSurface");
                            }
                            v34 = ((int (__thiscall *)(CSurfaceV7 *, int, void *))this->MiniMapAreaSurface->SetColorKey)(this->MiniMapAreaSurface, 8, &g_sColorKeyBlack);
                            if ( v34 )
                            {
                              WriteError(v34, "SetMiniMapColorKey");
                            }
                            BBSupportTracePrintF(1, "GFX ENGINE: Size of render surface: %d x %d", GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight);
                            this->LandscapeSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
                            if ( this->LandscapeSurface )
                            {
                              if ( GfxEngineSetup.m_bD3DInterface )
                              {
                                v15 = this->m_pDDraw;
                              }
                              else
                              {
                                v15 = this->m_pDDraw7;
                              }
                              v10 = j__abs(g_uGfxMode == 1);
                              IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
                              v35 = this->LandscapeSurface->CreateSurface(this->LandscapeSurface, v15, GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight, 1, IsHardwareLandscapeEngine, 0, v10, 0, 0, 0);
                              if ( v35 )
                              {
                                WriteError((int)v35, "CreateLandscapeSurface");
                                return 0;
                              }
                              else
                              {
                                this->LandscapeSurface2 = this->LandscapeSurface;
                                this->FinalRenderSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
                                if ( this->FinalRenderSurface )
                                {
                                  v14 = g_uGfxMode == 1;
                                  if ( GfxEngineSetup.m_bD3DInterface )
                                  {
                                    m_pDDraw = this->m_pDDraw;
                                  }
                                  else
                                  {
                                    m_pDDraw = this->m_pDDraw7;
                                  }
                                  HardwareLandscapeEngine = (unsigned __int8)SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
                                  v11 = j__abs(v14);
                                  HardwareLandscapeEngine2 = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
                                  v36 = this->FinalRenderSurface->CreateSurface(this->FinalRenderSurface, m_pDDraw, GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight, 1, HardwareLandscapeEngine2, 0, v11, 0, HardwareLandscapeEngine, 0);
                                  if ( v36 )
                                  {
                                    WriteError((int)v36, "CreateFinalRenderSurface");
                                    return 0;
                                  }
                                  else
                                  {
                                    inited = SurfaceClipper::InitClipper(&this->m_sClipper1, this->m_pDDraw7);
                                    if ( inited )
                                    {
                                      WriteError(inited, "CreateClipper1");
                                      return 0;
                                    }
                                    else
                                    {
                                      v38 = SurfaceClipper::InitClipper(&this->m_sMinimapClipper, this->m_pDDraw7);
                                      if ( v38 )
                                      {
                                        WriteError(v38, "Create Minimap Clipper");
                                        return 0;
                                      }
                                      else
                                      {
                                        v39 = SurfaceClipper::SetClipWindow(&this->m_sClipper1, GfxEngineSetup.m_hWnd);
                                        if ( v39 )
                                        {
                                          WriteError(v39, "AssignClipper1");
                                          return 0;
                                        }
                                        else
                                        {
                                          Clipper = SurfaceClipper::GetClipper(&this->m_sClipper1);
                                          v40 = this->PrimarySurface->SetClipper(this->PrimarySurface, Clipper);
                                          if ( v40 )
                                          {
                                            WriteError(v40, "SetClipper1");
                                            return 0;
                                          }
                                          else
                                          {
                                            g_pDestSizeTable = (int)g_iDestSizeTable;
                                            g_pZoomGradient = &g_iZoomGradient;
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
  int Clipper; // eax
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
  IDirectDraw7 *m_pDDraw; // [esp+44h] [ebp-18h]
  int Number; // [esp+48h] [ebp-14h]
  int i; // [esp+4Ch] [ebp-10h]
  HRESULT inited; // [esp+50h] [ebp-Ch]
  CInterfaceD3D *v34; // [esp+54h] [ebp-8h]
  char v35; // [esp+5Bh] [ebp-1h] BYREF

  v34 = this;
  BBSupportTracePrintF(1, "GFX ENGINE: Begin common init. Mode: Interface 3.");
  if ( v34->m_bInitHardware || v34->m_bInitSoftware )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT COMMON: Engine is already initialized!");
    return 1;
  }
  BYTE1(v34[1].m_sClipper1.m_vChar.u8) = SGfxRenderConfiguration::IsHQTextureSet(&GfxEngineSetup);
  BYTE2(v34[1].m_sClipper1.m_vChar.u8) = 0;
  if ( s_hCursor )
  {
    SetClassLongA(GfxEngineSetup.m_hWnd, -12, s_hCursor);
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
  for ( i = 0;
        i < 36;
        ++i )
  {
    if ( !s_hCursorHandles[i] )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Couldn't create cursors!");
      return 0;
    }
  }
  g_bForceMiniMapRefresh = 1;
  v34->field_68 = (int)CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
  if ( !v34->field_68 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
    return 0;
  }
  if ( g_pDirectDraw )
  {
    v34->m_pDDraw = g_pDirectDraw;
  }
  else
  {
    inited = DirectDrawCreate(0, (LPDIRECTDRAW *)&v34->m_pDDraw, 0);
    if ( inited )
    {
      WriteError(inited, "CreateDirectDrawObject");
      return 0;
    }
    g_pDirectDraw = v34->m_pDDraw;
  }
  inited = v34->m_pDDraw->lpVtbl->SetCooperativeLevel(v34->m_pDDraw, GfxEngineSetup.m_hWnd, 8);
  if ( inited )
  {
    WriteError(inited, "SetCooperativeLevel");
    return 0;
  }
  else
  {
    v34->PrimarySurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
    if ( v34->PrimarySurface )
    {
      Number = g_uGfxMode == 1;
      if ( GfxEngineSetup.m_bD3DInterface )
      {
        m_pDDraw = v34->m_pDDraw;
      }
      else
      {
        m_pDDraw = v34->m_pDDraw7;
      }
      v2 = j__abs(Number);
      inited = (HRESULT)v34->PrimarySurface->CreateSurface(v34->PrimarySurface, m_pDDraw, GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight, 1, 0, 0, v2, 1, 0, 0);
      if ( inited )
      {
        WriteError(inited, "CreatePrimarySurface");
        return 0;
      }
      else
      {
        inited = v34->PrimarySurface->GetBitDepth(v34->PrimarySurface, &v13);
        if ( inited )
        {
          WriteError(inited, "RetrieveBitDepth");
          return 0;
        }
        else if ( v13 == 16 )
        {
          inited = ((int (__thiscall *)(CSurfaceV7 *, char *))v34->PrimarySurface->GetPixelFormat)(v34->PrimarySurface, &v35);
          if ( inited )
          {
            WriteError(inited, "RetrievePixelFormatFromPrimarySurface");
            return 0;
          }
          else
          {
            if ( v35 )
            {
              g_uGfxMode = 1;
            }
            else
            {
              g_uGfxMode = 2;
            }
            v34->m_pMoveCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
            if ( v34->m_pMoveCursorSurface )
            {
              v29 = g_uGfxMode == 1;
              if ( GfxEngineSetup.m_bD3DInterface )
              {
                DDraw7 = v34->m_pDDraw;
              }
              else
              {
                DDraw7 = v34->m_pDDraw7;
              }
              v3 = j__abs(v29);
              inited = (HRESULT)v34->m_pMoveCursorSurface->CreateSurface(v34->m_pMoveCursorSurface, DDraw7, 32, 32, 1, 0, 0, v3, 0, 0, 0);
              if ( inited )
              {
                WriteError(inited, "CreateMoveCursorSurface");
                return 0;
              }
              else
              {
                if ( g_uGfxMode == 1 )
                {
                  v27 = g_sColorKeyMagenta555;
                }
                else
                {
                  v27 = g_sColorKeyMagenta565;
                }
                CFixCursor::SetSurfacePtr((CFixCursor *)&v34[1].m_sClipper1.m_vChar.uC, 0x73u, v34->m_pMoveCursorSurface, v27);
                if ( g_uGfxMode == 1 )
                {
                  v26 = &g_sColorKeyMagenta555;
                }
                else
                {
                  v26 = &g_sColorKeyMagenta565;
                }
                v34->m_pMoveCursorSurface->SetColorKey(v34->m_pMoveCursorSurface, 8, v26);
                v34->m_pZoomCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
                if ( v34->m_pZoomCursorSurface )
                {
                  v25 = g_uGfxMode == 1;
                  if ( GfxEngineSetup.m_bD3DInterface )
                  {
                    v24 = v34->m_pDDraw;
                  }
                  else
                  {
                    v24 = v34->m_pDDraw7;
                  }
                  v4 = j__abs(v25);
                  inited = (HRESULT)v34->m_pZoomCursorSurface->CreateSurface(v34->m_pZoomCursorSurface, v24, 32, 32, 1, 0, 0, v4, 0, 0, 0);
                  if ( inited )
                  {
                    WriteError(inited, "CreationZoomCursorSurface");
                    return 0;
                  }
                  else
                  {
                    if ( g_uGfxMode == 1 )
                    {
                      v23 = g_sColorKeyMagenta555;
                    }
                    else
                    {
                      v23 = g_sColorKeyMagenta565;
                    }
                    CFixCursor::SetSurfacePtr((CFixCursor *)&v34[1].m_sViewport.dwY, 0x74u, v34->m_pZoomCursorSurface, v23);
                    if ( g_uGfxMode == 1 )
                    {
                      v22 = &g_sColorKeyMagenta555;
                    }
                    else
                    {
                      v22 = &g_sColorKeyMagenta565;
                    }
                    v34->m_pZoomCursorSurface->SetColorKey(v34->m_pZoomCursorSurface, 8, v22);
                    v34->MiniMapSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
                    if ( v34->MiniMapSurface )
                    {
                      v21 = g_uGfxMode == 1;
                      if ( GfxEngineSetup.m_bD3DInterface )
                      {
                        v20 = v34->m_pDDraw;
                      }
                      else
                      {
                        v20 = v34->m_pDDraw7;
                      }
                      v5 = j__abs(v21);
                      inited = (HRESULT)v34->MiniMapSurface->CreateSurface(v34->MiniMapSurface, v20, 240, 160, 1, 0, 0, v5, 0, 0, 0);
                      if ( inited )
                      {
                        WriteError(inited, "CreateMiniMapSurface");
                        return 0;
                      }
                      else
                      {
                        v34->MiniMapSurface->ClearSurface(v34->MiniMapSurface, 0);
                        v34->MiniMapSurface->SetColorKey(v34->MiniMapSurface, 8, (int *)&g_sColorKeyBlack);
                        v34->MiniMapAreaSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
                        if ( v34->MiniMapAreaSurface )
                        {
                          v19 = g_uGfxMode == 1;
                          if ( GfxEngineSetup.m_bD3DInterface )
                          {
                            v18 = v34->m_pDDraw;
                          }
                          else
                          {
                            v18 = v34->m_pDDraw7;
                          }
                          v6 = j__abs(v19);
                          inited = (HRESULT)v34->MiniMapAreaSurface->CreateSurface(v34->MiniMapAreaSurface, v18, 240, 160, 1, 0, 0, v6, 0, 0, 0);
                          if ( inited )
                          {
                            WriteError(inited, "CreateMiniMapAreaSurface");
                            return 0;
                          }
                          else
                          {
                            inited = v34->MiniMapAreaSurface->ClearSurface(v34->MiniMapAreaSurface, 0);
                            if ( inited )
                            {
                              WriteError(inited, "ClearMiniMapSurface");
                            }
                            inited = ((int (__thiscall *)(CSurfaceV7 *, int, void *))v34->MiniMapAreaSurface->SetColorKey)(v34->MiniMapAreaSurface, 8, &g_sColorKeyBlack);
                            if ( inited )
                            {
                              WriteError(inited, "SetMiniMapColorKey");
                            }
                            BBSupportTracePrintF(1, "GFX ENGINE: Size of render surface: %d x %d", GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight);
                            v34->LandscapeSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
                            if ( v34->LandscapeSurface )
                            {
                              v17 = g_uGfxMode == 1;
                              if ( GfxEngineSetup.m_bD3DInterface )
                              {
                                v16 = v34->m_pDDraw;
                              }
                              else
                              {
                                v16 = v34->m_pDDraw7;
                              }
                              v10 = j__abs(v17);
                              IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
                              inited = (HRESULT)v34->LandscapeSurface->CreateSurface(v34->LandscapeSurface, v16, GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight, 1, IsHardwareLandscapeEngine, 0, v10, 0, 0, 0);
                              if ( inited )
                              {
                                WriteError(inited, "CreateLandscapeSurface");
                                return 0;
                              }
                              else
                              {
                                v34->LandscapeSurface2 = v34->LandscapeSurface;
                                v34->FinalRenderSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
                                if ( v34->FinalRenderSurface )
                                {
                                  v15 = g_uGfxMode == 1;
                                  if ( GfxEngineSetup.m_bD3DInterface )
                                  {
                                    v14 = v34->m_pDDraw;
                                  }
                                  else
                                  {
                                    v14 = v34->m_pDDraw7;
                                  }
                                  v12 = (unsigned __int8)SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
                                  v11 = j__abs(v15);
                                  v8 = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
                                  inited = (HRESULT)v34->FinalRenderSurface->CreateSurface(v34->FinalRenderSurface, v14, GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight, 1, v8, 0, v11, 0, v12, 0);
                                  if ( inited )
                                  {
                                    WriteError(inited, "CreateFinalRenderSurface");
                                    return 0;
                                  }
                                  else
                                  {
                                    inited = SurfaceClipper::InitClipper(&v34->m_sClipper1, v34->m_pDDraw);
                                    if ( inited )
                                    {
                                      WriteError(inited, "CreateClipper1");
                                      return 0;
                                    }
                                    else
                                    {
                                      inited = SurfaceClipper::InitClipper(&v34->m_sMinimapClipper, v34->m_pDDraw);
                                      if ( inited )
                                      {
                                        WriteError(inited, "Create Minimap Clipper");
                                        return 0;
                                      }
                                      else
                                      {
                                        inited = SurfaceClipper::SetClipWindow(&v34->m_sClipper1, GfxEngineSetup.m_hWnd);
                                        if ( inited )
                                        {
                                          WriteError(inited, "AssignClipper1");
                                          return 0;
                                        }
                                        else
                                        {
                                          Clipper = SurfaceClipper::GetClipper(&v34->m_sClipper1);
                                          inited = v34->PrimarySurface->SetClipper(v34->PrimarySurface, Clipper);
                                          if ( inited )
                                          {
                                            WriteError(inited, "SetClipper1");
                                            return 0;
                                          }
                                          else
                                          {
                                            g_pDestSizeTable = (int)g_iDestSizeTable;
                                            g_pZoomGradient = &g_iZoomGradient;
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
  IDirectDrawSurface7 *v3; // eax
  IDirectDrawSurface7 *v4; // eax
  struct IDirectDrawSurface7 *v5; // eax
  struct IDirectDrawSurface7 *v6; // eax
  int GradientFormat; // eax
  struct IDirectDrawSurface7 *v8; // eax
  struct IDirectDrawSurface7 *v9; // [esp+ACh] [ebp-170h]
  struct IDirect3DDevice7 *m_pObjectDevice; // [esp+B0h] [ebp-16Ch]
  DWORD v11; // [esp+C0h] [ebp-15Ch] BYREF
  struct CCachePageManager *v13; // [esp+C8h] [ebp-154h]
  CCachePageManager *v14; // [esp+CCh] [ebp-150h]
  BOOL v15; // [esp+D0h] [ebp-14Ch]
  CCachePageManager *v16; // [esp+D4h] [ebp-148h] MAPDST
  void *C; // [esp+D8h] [ebp-144h]
  DWORD v18; // [esp+DCh] [ebp-140h]
  DWORD v19; // [esp+E0h] [ebp-13Ch]
  IDirectDraw7 *v20; // [esp+E4h] [ebp-138h]
  IDirectDraw7 *m_pDDraw7; // [esp+E8h] [ebp-134h]
  IDirectDraw7 *m_pDDraw; // [esp+ECh] [ebp-130h]
  int Number; // [esp+F0h] [ebp-12Ch]
  int uAvailableVidMemory; // [esp+F4h] [ebp-128h] BYREF
  int v25; // [esp+F8h] [ebp-124h]
  int v26; // [esp+FCh] [ebp-120h]
  int v27; // [esp+100h] [ebp-11Ch]
  bool v28; // [esp+107h] [ebp-115h]
  int i; // [esp+108h] [ebp-114h]
  void *v30; // [esp+10Ch] [ebp-110h]
  HRESULT v31; // [esp+10Ch] [ebp-110h] SPLIT
  DDSURFACEDESC2 v33; // [esp+114h] [ebp-108h] BYREF
  DDSCAPS2 v34; // [esp+1FCh] [ebp-20h] BYREF
  int exceptionBlock; // [esp+218h] [ebp-4h]

  BBSupportTracePrintF(1, "GFX ENGINE: Begin hardware init.");
  if ( this->m_bInitHardware || this->m_bInitSoftware )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT HARDWARE: Engine is already initialized!");
    return 1;
  }
  CHeightAndTypeTable::InitShadeTables((CHeightAndTypeTable *)g_cHeightAndTypeTable);
  v30 = (void *)this->m_pDDraw7->lpVtbl->QueryInterface(this->m_pDDraw7, &IID_IDirect3D7, (LPVOID *)&this->m_pIDirect3D7);
  if ( v30 )
  {
    WriteError((int)v30, "QueryD3DInterface");
    return 0;
  }
  CInterfaceD3D::AllocateEngineData(D3DObjectPtr, 256);
  v26 = 256;
  if ( !BYTE1(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) && SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup) )
  {
    v26 /= 2;
  }
  CInterfaceD3D::PreCalcTextureVertices(this, v26);
  for ( i = 0;
        i < 44;
        ++i )
  {
    this->LandscapeTextureTable[i] = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
    if ( !this->LandscapeTextureTable[i] )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
      return 0;
    }
    Number = g_uGfxMode == 1;
    if ( GfxEngineSetup.m_bD3DInterface )
    {
      m_pDDraw = this->m_pDDraw;
    }
    else
    {
      m_pDDraw = this->m_pDDraw7;
    }
    v2 = j__abs(Number);
    v31 = (HRESULT)this->LandscapeTextureTable[i]->CreateSurface(this->LandscapeTextureTable[i], m_pDDraw, v26, v26, 1, 1, 1, v2, 0, 0, 0);
    if ( v31 )
    {
      WriteError(v31, "CreateLandscapeTextureSurface");
      return 0;
    }
  }
  if ( g_bHardwareObjectEnabled )
  {
    for ( i = 0;
          i < 2;
          ++i )
    {
      this->ObjectTextureTable[i] = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
      if ( !this->ObjectTextureTable[i] )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
      }
      if ( GfxEngineSetup.m_bD3DInterface )
      {
        m_pDDraw7 = this->m_pDDraw;
      }
      else
      {
        m_pDDraw7 = this->m_pDDraw7;
      }
      v31 = (HRESULT)this->ObjectTextureTable[i]->CreateSurface(this->ObjectTextureTable[i], m_pDDraw7, 512, 512, 1, 0, 1, 2, 0, 0, 0);
      if ( v31 )
      {
        WriteError(v31, "CreateObjectTextureSurface");
        return 0;
      }
    }
    for ( i = 0;
          i < 2;
          ++i )
    {
      this->ObjectTextureSystemMemoryTable[i] = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
      if ( !this->ObjectTextureSystemMemoryTable[i] )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
      }
      if ( GfxEngineSetup.m_bD3DInterface )
      {
        v20 = this->m_pDDraw;
      }
      else
      {
        v20 = this->m_pDDraw7;
      }
      v31 = (HRESULT)this->ObjectTextureSystemMemoryTable[i]->CreateSurface(this->ObjectTextureSystemMemoryTable[i], v20, 512, 512, 0, 0, 1, 2, 0, 0, 0);
      if ( v31 )
      {
        WriteError(v31, "CreateObjectTextureSystemMemory");
        return 0;
      }
    }
  }
  v3 = this->LandscapeSurface->GetSurfacePtr(this->LandscapeSurface);
  v31 = ((int (__stdcall *)(IDirect3D7 *, GUID *, IDirectDrawSurface7 *))this->m_pIDirect3D7->CreateDevice)(this->m_pIDirect3D7, &IID_IDirect3DHALDevice, v3);// Goes to null the device probably
  if ( v31 )
  {
    WriteError(v31, "CreateLandscapeRenderDevice");
    return 0;
  }
  v4 = this->FinalRenderSurface->GetSurfacePtr(this->FinalRenderSurface);
  v31 = ((int (__stdcall *)(IDirect3D7 *, GUID *, IDirectDrawSurface7 *))this->m_pIDirect3D7->CreateDevice)(this->m_pIDirect3D7, &IID_IDirect3DHALDevice, v4);
  if ( v31 )
  {
    WriteError(v31, "CreateObjectRenderDevice");
    return 0;
  }
  this->m_sViewport.dwX = 0;
  this->m_sViewport.dwY = 0;
  this->m_sViewport.dwWidth = GfxEngineSetup.m_uWidth;
  this->m_sViewport.dwHeight = GfxEngineSetup.m_uHeight;
  this->m_sViewport.dvMinZ = 0.0;
  this->m_sViewport.dvMaxZ = FLOAT_1_0;
  v31 = this->LandscapeDevice->SetViewport(this->LandscapeDevice, &this->m_sViewport);
  if ( v31 )
  {
    WriteError(v31, "SetLandscapeViewport");
    return 0;
  }
  v31 = this->m_pObjectDevice->SetViewport(this->m_pObjectDevice, &this->m_sViewport);
  if ( v31 )
  {
    WriteError(v31, "SetObjectViewport");
    return 0;
  }
  v5 = this->LandscapeTextureTable[0]->GetSurfacePtr(this->LandscapeTextureTable[0]);
  v31 = this->LandscapeDevice->SetTexture(this->LandscapeDevice, 0, v5);
  if ( v31 )
  {
    WriteError(v31, "SetDefaultLandscapeTexture");
    return 0;
  }
  v31 = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_CULLMODE, 1);
  if ( v31 )
  {
    WriteError(v31, "SetCulling");
    return 0;
  }
  v31 = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_TEXTUREPERSPECTIVE, 0);
  if ( v31 )
  {
    WriteError(v31, "SetTextureCorrecture");
    return 0;
  }
  v31 = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_ZENABLE, 0);
  if ( v31 )
  {
    WriteError(v31, "DisableZBuffer");
    return 0;
  }
  v31 = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_LOCALVIEWER, 0);
  if ( v31 )
  {
    WriteError(v31, "DisableCameraView");
    return 0;
  }
  v31 = this->LandscapeDevice->SetTextureStageState(this->LandscapeDevice, 0, D3DTSS_ADDRESS, 1);
  if ( v31 )
  {
    WriteError(v31, "SetTextureAdressMode");
    return 0;
  }
  v31 = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_SHADEMODE, 2);
  if ( v31 )
  {
    WriteError(v31, "SetLandscapeShading");
    return 0;
  }
  v31 = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_SPECULARENABLE, 1);
  if ( v31 )
  {
    WriteError(v31, "SetLandscapeLighting");
    return 0;
  }
  if ( g_bHardwareObjectEnabled )
  {
    InitRenderStates();
    v6 = this->ObjectTextureTable[0]->GetSurfacePtr(this->ObjectTextureTable[0]);
    v31 = this->m_pObjectDevice->SetTexture(this->m_pObjectDevice, 0, v6);
    if ( v31 )
    {
      WriteError(v31, "SetDefaultObjectTexture");
      return 0;
    }
    v31 = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_SHADEMODE, 1);
    if ( v31 )
    {
      WriteError(v31, "SetObjectShading");
      return 0;
    }
    v31 = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_SPECULARENABLE, 0);
    if ( v31 )
    {
      WriteError(v31, "SetObjectLighting");
      return 0;
    }
    v31 = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_ALPHABLENDENABLE, 1);
    if ( v31 )
    {
      WriteError(v31, "EnableAlphaBlending");
      return 0;
    }
    v31 = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_SRCBLEND, 5);
    if ( v31 )
    {
      WriteError(v31, "SetSourceBlend");
      return 0;
    }
    v31 = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_DESTBLEND, 6);
    if ( v31 )
    {
      WriteError(v31, "SetDestBlend");
      return 0;
    }
    if ( SGfxRenderConfiguration::IsFiltering(&GfxEngineSetup) )
    {
      v19 = 2;
    }
    else
    {
      v19 = 1;
    }
    v31 = this->m_pObjectDevice->SetTextureStageState(this->m_pObjectDevice, 0, D3DTSS_MAGFILTER, v19);
    if ( v31 )
    {
      WriteError(v31, "SetObjectFiltering");
      return 0;
    }
    if ( SGfxRenderConfiguration::IsFiltering(&GfxEngineSetup) )
    {
      v18 = 2;
    }
    else
    {
      v18 = 1;
    }
    v31 = this->m_pObjectDevice->SetTextureStageState(this->m_pObjectDevice, 0, D3DTSS_MINFILTER, v18);
    if ( v31 )
    {
      WriteError(v31, "SetObjectFiltering");
      return 0;
    }
    CCacheManager::Reset((CCacheManager *)&g_cCacheManager);
    for ( i = 0;
          i < 8;
          ++i )
    {
      CColorGradient::SetupGradients(&g_cColorGradient, i, g_cColorGradient.m_vPlayerColors[i + 1], 2);
    }
    g_pfBlitSettler = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitSettlerHardware;
    g_pfBlitObject = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitObjectHardware;
    g_pfBlitVehicle = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitVehicleHardware;
    g_pfBlitBuilding = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))BlitBuildingHardware;
    g_pfBlitBorderstone = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitBorderstoneHardware;
    g_pfBlitAccessoryIcon = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitAccessoryIconHardware;
    g_pfBlitWave = BlitWaveHardware;
  }
  else
  {
    for ( i = 0;
          i < 8;
          ++i )
    {
      GradientFormat = CInterfaceD3D::GetGradientFormat(this);
      CColorGradient::SetupGradients(&g_cColorGradient, i, g_cColorGradient.m_vPlayerColors[i + 1], GradientFormat);
    }
    g_pfBlitSettler = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitSettler;
    g_pfBlitObject = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitObject;
    g_pfBlitVehicle = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitVehicle;
    g_pfBlitBuilding = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))BlitBuilding;
    g_pfBlitBorderstone = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitBorderstone;
    g_pfBlitAccessoryIcon = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitAccessoryIcon;
    g_pfBlitWave = BlitWave;
  }
  if ( g_bHardwareObjectEnabled )
  {
    for ( i = 0;
          i < 2;
          ++i )
    {
      C = operator new(0x9A4u);
      exceptionBlock = 0;
      if ( C )
      {
        m_pObjectDevice = this->m_pObjectDevice;
        v9 = this->ObjectTextureSystemMemoryTable[i]->GetSurfacePtr(this->ObjectTextureSystemMemoryTable[i]);
        v8 = this->ObjectTextureTable[i]->GetSurfacePtr(this->ObjectTextureTable[i]);
        v16 = (CCachePageManager *)CUploadCachePageManager::CUploadCachePageManager((CUploadCachePageManager *)C, v8, v9, m_pObjectDevice);
      }
      else
      {
        v16 = 0;
      }
      exceptionBlock = -1;
      this->CCachePageManager[i] = v16;
      if ( !this->CCachePageManager[i] )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: No memory to create PictureManager");
        return 0;
      }
    }
    CCachePageManager::SetCurrentZoomFactor(this->CCachePageManager[0], g_fZoomFactor);
    memset(&v34, 0, sizeof(v34));
    v34.dwCaps = 4096;
    v27 = this->m_pDDraw7->lpVtbl->GetAvailableVidMem(this->m_pDDraw7, &v34, &v11, (LPDWORD)&uAvailableVidMemory);
    if ( v27 )
    {
      WriteError(v27, "GetVideoMemory");
      return 0;
    }
    v25 = uAvailableVidMemory;
    BBSupportTracePrintF(1, "GFX ENGINE: Available vid mem for cache is %d", uAvailableVidMemory);
    v25 -= 1100000;
    v25 -= 50000;
    this->m_uCacheSurfaceCount = 0;
    if ( v25 > 0 )
    {
      CSurfaceDescription::CSurfaceDescription((CSurfaceDescription *)&v33);
      v33.dwFlags = 4103;
      v33.ddsCaps.dwCaps = 20480;
      v33.dwWidth = 512;
      v33.dwHeight = 512;
      *(_QWORD *)&v33.ddpfPixelFormat.dwFlags = 65LL;
      *(_QWORD *)&v33.ddpfPixelFormat.dwRGBBitCount = 0xF0000000010LL;
      *(_QWORD *)&v33.ddpfPixelFormat.dwGBitMask = 0xF000000F0LL;
      v33.ddpfPixelFormat.dwRGBAlphaBitMask = 61440;
      v15 = uAvailableVidMemory != 1674288;
      v28 = uAvailableVidMemory != 1674288;
      for ( this->m_uCacheSurfaceCount = j__abs(v15);
            v28 && this->m_uCacheSurfaceCount < 180;
            ++this->m_uCacheSurfaceCount )
      {
        v27 = this->m_pDDraw7->lpVtbl->CreateSurface(this->m_pDDraw7, &v33, &this->m_pCacheSurfaces[this->m_uCacheSurfaceCount], 0);
        v28 = 1;
        if ( v27 )
        {
          if ( v27 == DDERR_OUTOFVIDEOMEMORY )
          {
            BBSupportTracePrintF(1, "GFX ENGINE: %d cache surfaces created. Running out of video mem!", this->m_uCacheSurfaceCount);
            break;
          }
          WriteError(v27, "CreateCacheSurfaces");
          return 0;
        }
        v27 = this->m_pDDraw7->lpVtbl->GetAvailableVidMem(this->m_pDDraw7, &v34, &v11, (LPDWORD)&uAvailableVidMemory);
        if ( v27 )
        {
          WriteError(v27, "GetVideoMemory");
          return 0;
        }
        if ( uAvailableVidMemory == 1674288 )
        {
          v28 = 0;
        }
        v14 = (CCachePageManager *)operator new(0x824u);
        exceptionBlock = 1;
        if ( v14 )
        {
          v13 = CCachePageManager::CCachePageManager(v14, this->m_pCacheSurfaces[this->m_uCacheSurfaceCount], 0, this->m_pObjectDevice);
        }
        else
        {
          v13 = 0;
        }
        exceptionBlock = -1;
        this->m_pCacheManagers[this->m_uCacheSurfaceCount] = v13;
        if ( !this->m_pCacheManagers[this->m_uCacheSurfaceCount] )
        {
          BBSupportTracePrintF(1, "GFX ENGINE: Out of memory while creating CacheManager");
          return 0;
        }
      }
    }
    g_iZoomGradient = g_iVertexSize / 24;
    g_iZoomInit = -65536;
    if ( D3DObjectPtr->CCachePageManager[0] )
    {
      CCachePageManager::SetCurrentZoomFactor(D3DObjectPtr->CCachePageManager[0], g_fZoomFactor);
    }
  }
  D3DObjectPtr->m_bInitHardware = 1;
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
  if ( this->m_bInitHardware || this->m_bInitSoftware )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT SOFTWARE: Engine is already initialized!");
    return 1;
  }
  else
  {
    if ( g_uGfxMode == 1 )
    {
      j__TRI_init_engine(1365);
    }
    else
    {
      j__TRI_init_engine(1381);
    }
    CHeightAndTypeTable::InitShadeTables((CHeightAndTypeTable *)g_cHeightAndTypeTable);
    CInterfaceD3D::AllocateEngineData(D3DObjectPtr, 256);
    g_pSoftwareTexturePages = (int)operator new[](0x2C0000u);
    if ( g_pSoftwareTexturePages )
    {
      for ( i = 0;
            i < 44;
            ++i )
      {
        g_pTextureTable[i] = g_pSoftwareTexturePages + (i << 16);
      }
      CInterfaceD3D::InitTexturePtr(this);
      for ( j = 0;
            j < 8;
            ++j )
      {
        GradientFormat = CInterfaceD3D::GetGradientFormat(this);
        CColorGradient::SetupGradients(&g_cColorGradient, j, MEMORY[0x468D2C8][j + 1].m_iR, MEMORY[0x468D2C8][j + 1].m_iG, MEMORY[0x468D2C8][j + 1].m_iB, GradientFormat);
      }
      CInterfaceD3D::PreCalcTextureVertices(this, 256);
      g_pfBlitSettler = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitSettler;
      g_pfBlitObject = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitObject;
      g_pfBlitVehicle = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitVehicle;
      g_pfBlitBuilding = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))BlitBuilding;
      g_pfBlitBorderstone = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitBorderstone;
      g_pfBlitAccessoryIcon = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitAccessoryIcon;
      g_pfBlitWave = BlitWave;
      this->m_bInitSoftware = 1;
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
bool  CInterfaceD3D::BlitSurfaceToDIB(struct HWND__ * hWnd, struct HBITMAP__ * h) {
  
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
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 2)");
    }
    hdc = GetDC(hWnd);
    CompatibleDC = CreateCompatibleDC(hdc);
    SelectObject(CompatibleDC, h);
    if ( !BitBlt(CompatibleDC, 0, 0, MEMORY[0x3E2E26C], MEMORY[0x3E2E270], hdcSrc, 0, 0, (DWORD)&dword_C20408[163590]) )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 3)");
    }
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
  if ( SGfxRenderConfiguration::IsEditorMode(&GfxEngineSetup) )
  {
    if ( this->m_pGuiSurfaces[0] && this->PrimarySurface )
    {
      v11.left = GfxEngineSetup.m_uX;
      v11.top = GfxEngineSetup.m_uY;
      v11.right = GfxEngineSetup.m_uWidth + GfxEngineSetup.m_uX;
      v11.bottom = GfxEngineSetup.m_uHeight + GfxEngineSetup.m_uY;
      BlitStructPtr = CBlitFX::GetBlitStructPtr((CBlitFX *)&g_cBlitFX);
      v6 = this->PrimarySurface->Blt(this->PrimarySurface, &v11, this->m_pGuiSurfaces[0], 0, 512, (struct _DDBLTFX *)BlitStructPtr);
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
      D3DObjectPtr->PrimarySurface->GetSurfaceSize(D3DObjectPtr->PrimarySurface, &surfaceWidth, &surfaceHeight);
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
        v7 = CInterfaceD3D::SetCustomClipper(this, &this->m_sMinimapClipper);
        if ( v7 )
        {
          WriteError(v7, "SetClipper2");
          return 0;
        }
        v7 = D3DObjectPtr->PrimarySurface->Blt(D3DObjectPtr->PrimarySurface, (struct tagRECT *)&v16, D3DObjectPtr->MiniMapSurface, (struct tagRECT *)&v12, 0x8000, 0);
        if ( !v7 )
        {
          v7 = D3DObjectPtr->PrimarySurface->Blt(D3DObjectPtr->PrimarySurface, (struct tagRECT *)&v16, D3DObjectPtr->MiniMapAreaSurface, (struct tagRECT *)&v12, 0x8000, 0);
        }
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
    v10.left = GfxEngineSetup.m_uX;
    v10.top = GfxEngineSetup.m_uY;
    v10.right = GfxEngineSetup.m_uWidth + GfxEngineSetup.m_uX;
    v10.bottom = GfxEngineSetup.m_uHeight + GfxEngineSetup.m_uY;
    v3 = CBlitFX::GetBlitStructPtr((CBlitFX *)&g_cBlitFX);
    v6 = this->PrimarySurface->Blt(this->PrimarySurface, &v10, this->FinalRenderSurface, 0, 512, (struct _DDBLTFX *)v3);
  }
  switch ( v6 )
  {
    case 0:
      return 1;
    case -2005532222:
      v6 = this->PrimarySurface->Restore(this->PrimarySurface);
      if ( v6 )
      {
        WriteError(v6, "RestorePrimarySurface");
      }
      if ( v6 == -2005532085 )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: Stop rendering because of inaccessability of primary surface!");
        LOBYTE(this[1].m_sClipper1.m_vChar.u8) = 1;
      }
      break;
    case -2005532447:
      WriteError(-2005532447, "Exclusive mode down! Stop rendering...");
      LOBYTE(this[1].m_sClipper1.m_vChar.u8) = 1;
      break;
    default:
      WriteError(v6, "PrimarySurfaceBlit");
      break;
  }
  return 0;
}


// address=[0x2f66d00]
// Decompiled from BOOL __stdcall CInterfaceD3D::BlitDIBToSurface(HWND hWnd, int a2, int cy, int a4)
void  CInterfaceD3D::BlitDIBToSurface(struct HWND__ * hWnd, int a2, int cy, struct IDirectDrawSurface4 * a4) {
  
  HDC hdc; // [esp+8h] [ebp-Ch]
  HDC v6; // [esp+Ch] [ebp-8h] BYREF
  HDC hdcSrc; // [esp+10h] [ebp-4h]

  (*(void (__stdcall **)(int, HDC *))(*(_DWORD *)a4 + 68))(a4, &v6);
  hdc = GetDC(hWnd);
  hdcSrc = CreateCompatibleDC(hdc);
  SelectObject(hdcSrc, h);
  if ( !BitBlt(v6, 0, 0, a2, cy, hdcSrc, 0, 0, (DWORD)&dword_C20408[163590]) )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Blit to Surface failed!");
  }
  (*(void (__thiscall **)(int, int, HDC))(*(_DWORD *)a4 + 104))(a4, a4, v6);
  ReleaseDC(hWnd, hdc);
  return DeleteDC(hdcSrc);
}


// address=[0x2f66dc0]
// Decompiled from int __thiscall CInterfaceD3D::GetGradientFormat(CInterfaceD3D *this)
int  CInterfaceD3D::GetGradientFormat(void) {
  
  if ( this->m_bInitHardware )
  {
    return 2;
  }
  else
  {
    return g_uGfxMode == 1;
  }
}


// address=[0x2f66e00]
// Decompiled from int __stdcall CInterfaceD3D::EnumModesCallback(struct _DDSURFACEDESC2 *a1, void *a2)
long __stdcall CInterfaceD3D::EnumModesCallback(struct _DDSURFACEDESC2 * a1, void * a2) {
  
  if ( !a1 )
  {
    return 0;
  }
  if ( a1->ddpfPixelFormat.dwRGBBitCount <= 0x10 )
  {
    return 1;
  }
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
// Decompiled from int __stdcall CInterfaceD3D::EnumModesCallbackOld(_DWORD *a1, int a2)
long __stdcall CInterfaceD3D::EnumModesCallbackOld(struct _DDSURFACEDESC * a1, void * a2) {
  
  if ( !a1 )
  {
    return 0;
  }
  if ( a1[21] <= 0x10u )
  {
    return 1;
  }
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
  if ( !SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup) )
  {
    BYTE1(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
  }
  if ( !D3DObjectPtr )
  {
    return 1;
  }
  v4 = g_uGfxMode == 1;
  IsHQTextureSet = BYTE1(D3DObjectPtr[1].m_sClipper1.m_vChar.u8);
  IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
  if ( !ReadTextureBitmapSet(IsHardwareLandscapeEngine, IsHQTextureSet, v4, 44) )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: Error while loading texture set!");
    return 0;
  }
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup) )
  {
    return 1;
  }
  BBSupportTracePrintF(1, "GFX ENGINE: Begin set up luminance tables.");
  for ( i = 0;
        i < 44;
        ++i )
  {
    j__TRI_calculate_LUT_from_palette((int)&g_uColorPalettes + 768 * i, g_pLuminanceTablesStart + (i << 11));
  }
  BBSupportTracePrintF(1, "GFX ENGINE: End set up luminance tables.");
  return 1;
}


// address=[0x2f67190]
// Decompiled from void __thiscall CInterfaceD3D::SetupViewport(CInterfaceD3D *this, int a2, int a3, int a4, int a5)
void  CInterfaceD3D::SetupViewport(int a2, int a3, int a4, int a5) {
  
  HRESULT v5; // [esp+0h] [ebp-8h]
  int v6; // [esp+0h] [ebp-8h]

  this->m_sViewport = a2;
  this->? = a3;
  this->? = a4;
  this->? = a5;
  if ( this->LandscapeDevice )
  {
    v5 = this->LandscapeDevice->lpVtbl->GetBltStatus(this->LandscapeDevice, (DWORD)&this->m_sViewport);
    if ( v5 )
    {
      WriteError(v5, "SetLandscapeViewport");
    }
    else if ( this->m_pObjectDevice )
    {
      v6 = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)this->m_pObjectDevice + 52))(this->m_pObjectDevice, &this->m_sViewport);
      if ( v6 )
      {
        WriteError(v6, "SetObjectViewport");
      }
    }
  }
}


// address=[0x2f67250]
// Decompiled from int __thiscall CInterfaceD3D::SetCustomClipper(CInterfaceD3D *this, struct SurfaceClipper *a2)
long  CInterfaceD3D::SetCustomClipper(class SurfaceClipper & a2) {
  
  struct IDirectDrawClipper *Clipper; // eax

  if ( !SurfaceClipper::GetClipper(a2) )
  {
    j___wassert(L"clipper.GetClipper() != nullptr", L"MainGfxManager.cpp", 0x90Fu);
  }
  Clipper = SurfaceClipper::GetClipper(a2);
  return (*(int (__thiscall **)(_DWORD, struct IDirectDrawClipper *))(**((_DWORD **)this + 25) + 68))(*((_DWORD *)this + 25), Clipper);
}


// address=[0x2f672a0]
// Decompiled from int __thiscall CInterfaceD3D::ClearCustomClipper(CInterfaceD3D *this)
long  CInterfaceD3D::ClearCustomClipper(void) {
  
  struct IDirectDrawClipper *Clipper; // eax

  Clipper = SurfaceClipper::GetClipper((SurfaceClipper *)&this->m_sClipper1);
  return ((int (__thiscall *)(CSurfaceV7 *, struct IDirectDrawClipper *))this->FinalRenderSurface->SetClipper)(this->FinalRenderSurface, Clipper);
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
  {
    return result;
  }
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
  if ( this[1].m_pDDraw )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 0", this[1].m_pDDraw);
  }
  else
  {
    v2 = this->LandscapeDevice->BeginScene(this->LandscapeDevice);
    if ( v2 )
    {
      WriteError(v2, "BeginLandscapeScene");
    }
    ++this[1].m_pDDraw;
  }
  return v2;
}


// address=[0x2f673e0]
// Decompiled from int __thiscall CInterfaceD3D::EndLandscapeScene(CInterfaceD3D *this)
long  CInterfaceD3D::EndLandscapeScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  if ( (int)this[1].m_pDDraw > 1 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 1", this[1].m_pDDraw);
  }
  v2 = this->LandscapeDevice->EndScene(this->LandscapeDevice);
  if ( v2 )
  {
    WriteError(v2, "EndLandscapeScene");
  }
  --this[1].m_pDDraw;
  return v2;
}


// address=[0x2f67460]
// Decompiled from int __thiscall CInterfaceD3D::BeginObjectScene(CInterfaceD3D *this)
long  CInterfaceD3D::BeginObjectScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = -1;
  if ( this[1].field_0 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: ObjectScene Lockcounter is %d instead of 0", this[1].field_0);
  }
  else
  {
    v2 = this->m_pObjectDevice->BeginScene(this->m_pObjectDevice);
    if ( v2 )
    {
      WriteError(v2, "BeginObjectScene");
    }
    ++this[1].field_0;
  }
  return v2;
}


// address=[0x2f674f0]
// Decompiled from int __thiscall CInterfaceD3D::EndObjectScene(CInterfaceD3D *this)
long  CInterfaceD3D::EndObjectScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  if ( (int)this[1].field_0 > 1 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 1", this[1].field_0);
  }
  v2 = this->m_pObjectDevice->EndScene(this->m_pObjectDevice);
  if ( v2 )
  {
    WriteError(v2, "EndObjectScene");
  }
  --this[1].field_0;
  return v2;
}


// address=[0x2f67570]
// Decompiled from char __thiscall CInterfaceD3D::CreateCameraWindowSurface(CInterfaceD3D *this, int a2, int a3)
bool  CInterfaceD3D::CreateCameraWindowSurface(int a2, int a3) {
  
  unsigned __int8 IsHardwareLandscapeEngine; // al
  int v5; // [esp-10h] [ebp-20h]
  CSurfaceV7 *v6; // [esp+0h] [ebp-10h]
  IDirectDraw7 *m_pDDraw; // [esp+4h] [ebp-Ch]

  CInterfaceD3D::DestroyCameraWindowSurface(this);
  this->m_pCameraWindowSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
  if ( this->m_pCameraWindowSurface )
  {
    if ( GfxEngineSetup.m_bD3DInterface )
    {
      m_pDDraw = this->m_pDDraw;
    }
    else
    {
      m_pDDraw = this->m_pDDraw7;
    }
    v5 = j__abs(g_uGfxMode == 1);
    IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
    v6 = this->m_pCameraWindowSurface->CreateSurface(this->m_pCameraWindowSurface, m_pDDraw, a2, a3, 1, IsHardwareLandscapeEngine, 0, v5, 0, 0, 0);
    if ( v6 )
    {
      WriteError((int)v6, "CreateLandscapeSurface");
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
  if ( !this->m_pCameraWindowSurface )
  {
    return result;
  }
  if ( this->LandscapeSurface2 == (CSurfaceV7 *)this->m_pCameraWindowSurface )
  {
    j___wassert(L"m_pCurrentLandScapeRenderTarget != m_pLandscapeCameraRenderSurface", L"MainGfxManager.cpp", 0x9D2u);
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)this->m_pCameraWindowSurface + 4))(this->m_pCameraWindowSurface);
  result = (CInterfaceD3D *)this->m_pCameraWindowSurface;
  if ( result )
  {
    result = (CInterfaceD3D *)(**(int (__thiscall ***)(int, int))this->m_pCameraWindowSurface)(this->m_pCameraWindowSurface, 1);
  }
  this->m_pCameraWindowSurface = 0;
  return result;
}


// address=[0x2f676f0]
// Decompiled from int __thiscall CInterfaceD3D::SwitchLandscapeRenderTarget(CInterfaceD3D *this, bool a2)
long  CInterfaceD3D::SwitchLandscapeRenderTarget(bool a2) {
  
  int v3; // [esp+0h] [ebp-10h]
  CSurfaceV7 *LandscapeSurface; // [esp+4h] [ebp-Ch]

  if ( a2 )
  {
    LandscapeSurface = (CSurfaceV7 *)this->m_pCameraWindowSurface;
  }
  else
  {
    LandscapeSurface = this->LandscapeSurface;
  }
  if ( !LandscapeSurface )
  {
    j___wassert(L"renderTarget != nullptr", L"MainGfxManager.cpp", 0x9DDu);
  }
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup) )
  {
    v3 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDrawSurface7 *))LandscapeSurface->j_?SetAsRenderTarget@CSurfaceV7@@UAEJPAUIDirect3DDevice7@@@Z)(LandscapeSurface, this->LandscapeDevice);
    if ( v3 < 0 )
    {
      return v3;
    }
  }
  this->LandscapeSurface2 = LandscapeSurface;
  return 0;
}


// address=[0x2f74fc0]
// Decompiled from int __thiscall CInterfaceD3D::GetGuiMemorySize(CInterfaceD3D *this)
int  CInterfaceD3D::GetGuiMemorySize(void) {
  
  return (int)this[1].m_sClipper1.m_pClipper;
}


// address=[0x2f74fe0]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::SetGuiMemorySize(CInterfaceD3D *this, int a2)
void  CInterfaceD3D::SetGuiMemorySize(int a2) {
  
  CInterfaceD3D *result; // eax

  result = this;
  this[1].m_sClipper1.m_pClipper = (LPDIRECTDRAWCLIPPER)a2;
  return result;
}


// address=[0x2f81fe0]
// Decompiled from void __thiscall CInterfaceD3D::InitTexturedLandscapeModule(CInterfaceD3D *this)
void  CInterfaceD3D::InitTexturedLandscapeModule(void) {
  
  int i; // [esp+4h] [ebp-4h]
  int j; // [esp+4h] [ebp-4h]

  for ( i = 0;
        i < 44;
        ++i )
  {
    g_pTextureTable[i] = 0;
  }
  g_iLastUsedPage = 0;
  for ( j = 0;
        j < 44;
        ++j )
  {
    this->LandscapeTextureTable[j] = 0;
  }
}


// address=[0x2f82050]
// Decompiled from int __thiscall CInterfaceD3D::PreCalcTextureVertices(CInterfaceD3D *this, int a2)
void  CInterfaceD3D::PreCalcTextureVertices(int a2) {
  
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
  {
    v3 = 0.0;
  }
  for ( i = 0;
        i < 4;
        ++i )
  {
    for ( j = 0;
          j < 4;
          ++j )
    {
      for ( k = 0;
            k < 6;
            ++k )
      {
        _vec_ctor_no(v7, 0x20u, 3u, (void *(__thiscall *)(void *))_D3DTLVERTEX::_D3DTLVERTEX);
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
// Decompiled from int __thiscall CInterfaceD3D::InitTexturePtr(CInterfaceD3D *this)
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
void  CInterfaceD3D::CalcTilingVerticesType1(int a2) {
  
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
void  CInterfaceD3D::CalcTilingVerticesType2(int a2) {
  
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
int  CInterfaceD3D::AllocateEngineData(int a2) {
  
  void *v3; // [esp+10h] [ebp-20h]
  void *v4; // [esp+18h] [ebp-18h]
  signed int i; // [esp+1Ch] [ebp-14h]

  if ( this->field_0 )
  {
    CInterfaceD3D::DeleteEngineData(this);
  }
  v4 = operator new[](32 * a2);
  if ( v4 )
  {
    _vec_ctor_no(v4, 0x20u, a2, (void *(__thiscall *)(void *))_D3DTLVERTEX::_D3DTLVERTEX);
    v3 = v4;
  }
  else
  {
    v3 = 0;
  }
  this->field_0 = v3;
  if ( !this->field_0 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: Not enough memory to allocate vertices");
    return 0;
  }
  for ( i = 0;
        i < a2;
        ++i )
  {
    *(float *)(this->field_0 + 32 * i + 8) = FLOAT_0_89999998;
    *(float *)(this->field_0 + 32 * i + 12) = FLOAT_0_5;
  }
  if ( this->field_0 )
  {
    g_pVertexMax = this->field_0 + 7680;
  }
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup) )
  {
    return 1;
  }
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
// Decompiled from int __thiscall CInterfaceD3D::ChangeCurrentTexturePage(CInterfaceD3D *this, int a2)
void  CInterfaceD3D::ChangeCurrentTexturePage(int a2) {
  
  int result; // eax
  struct IDirectDrawSurface7 *v3; // eax

  result = a2;
  if ( a2 == g_iLastUsedPage )
  {
    return result;
  }
  CInterfaceD3D::RenderScene(this, byte_4696877);
  g_iLastUsedPage = a2;
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup) )
  {
    v3 = (struct IDirectDrawSurface7 *)((int (__thiscall *)(CSurfaceV7 *))this->LandscapeTextureTable[g_iLastUsedPage]->GetSurfacePtr)(this->LandscapeTextureTable[g_iLastUsedPage]);
    return this->LandscapeDevice->lpVtbl->UpdateOverlayZOrder(this->LandscapeDevice, 0, v3);
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
void  CInterfaceD3D::RenderScene(bool a2) {
  
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
        for ( i = (float *)this->field_0;
              (unsigned int)i < g_pVertex;
              i += 24 )
        {
          *i = (float)dword_3E2E284 + *i;
          i[1] = (float)dword_3E2E288 + i[1];
          i[8] = (float)dword_3E2E284 + i[8];
          i[9] = (float)dword_3E2E288 + i[9];
          i[16] = (float)dword_3E2E284 + i[16];
          i[17] = (float)dword_3E2E288 + i[17];
        }
      }
      result = (CInterfaceD3D *)((int (__stdcall *)(IDirectDrawSurface7 *, int, int, _DWORD, int, _DWORD))this->LandscapeDevice->lpVtbl->Lock)(this->LandscapeDevice, 4, 452, this->field_0, (g_pVertex - this->field_0) >> 5, 0);
      if ( result )
      {
        WriteError(result, "DrawPrimitive");
        g_bRenderSuccess = 0;
      }
    }
  }
  else
  {
    for ( j = this->field_0;
          j < g_pVertex;
          j += 96 )
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
int  CInterfaceD3D::IsInterface7Available(bool & a2, struct HWND__ * a3) {
  
  int v4; // eax
  int v5; // eax
  int v6; // [esp+10h] [ebp-2A8h]
  int v7; // [esp+14h] [ebp-2A4h] BYREF
  int v8; // [esp+18h] [ebp-2A0h] BYREF
  HRESULT (__stdcall *DirectDrawCreateEx)(GUID *, LPVOID *, const IID *const, IUnknown *); // [esp+1Ch] [ebp-29Ch]
  BOOL v10; // [esp+20h] [ebp-298h]
  int v11; // [esp+24h] [ebp-294h] BYREF
  IDirectDraw7 *m_pDDraw; // [esp+28h] [ebp-290h]
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
      DirectDrawCreateEx = (HRESULT (__stdcall *)(GUID *, LPVOID *, const IID *const, IUnknown *))GetProcAddress(hModule, "DirectDrawCreateEx");
      v13 = DirectDrawCreateEx;
      if ( DirectDrawCreateEx )
      {
        v22 = v13(0, (LPVOID *)&v23->m_pDDraw, &IID_IDirectDraw7, 0);
        if ( v22 )
        {
          WriteError(v22, "CreateDirectDrawObject");
          return 3;
        }
        else
        {
          g_pDirectDraw = (LPDIRECTDRAW *)v23->m_pDDraw;
          v22 = v23->m_pDDraw->lpVtbl->QueryInterface(v23->m_pDDraw, &IID_IDirectDraw7, (LPVOID *)&v23->m_pDDraw7);
          if ( v22 )
          {
            CInterfaceD3D::CleanUpCheckObjects(v23);
            WriteError(v22, "QueryInterface");
            return 4;
          }
          else
          {
            v22 = v23->m_pDDraw7->lpVtbl->GetDeviceIdentifier(v23->m_pDDraw7, (LPDDDEVICEIDENTIFIER2)byte_46C7940, 1);
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
            v22 = v23->m_pDDraw7->lpVtbl->SetCooperativeLevel(v23->m_pDDraw7, a3, 8);
            if ( v22 )
            {
              CInterfaceD3D::CleanUpCheckObjects(v23);
              WriteError(v22, "SetCooperativeLevel");
              return 5;
            }
            else
            {
              v22 = v23->m_pDDraw7->lpVtbl->QueryInterface(v23->m_pDDraw7, &IID_IDirect3D7, (LPVOID *)&v23->m_pIDirect3D7);
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
                  if ( MEMORY[0x3E2E262] )
                  {
                    m_pDDraw = v23->m_pDDraw;
                  }
                  else
                  {
                    m_pDDraw = v23->m_pDDraw7;
                  }
                  v22 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD))v23->PrimarySurface->CreateSurface)(v23->PrimarySurface, m_pDDraw, 0, 0, 1, 0, 0, 0, 1, 0, 0);
                  if ( v22 )
                  {
                    CInterfaceD3D::CleanUpCheckObjects(v23);
                    WriteError(v22, "CreatePrimarySurface");
                    return 8;
                  }
                  else
                  {
                    v22 = ((int (__thiscall *)(CSurfaceV7 *, unsigned __int8 *))v23->PrimarySurface->GetPixelFormat)(v23->PrimarySurface, &v21);
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
                        v22 = (*(int (__thiscall **)(int, IDirectDraw7 *, int, int, int, int, _DWORD, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v23->field_68 + 48))(v23->field_68, v23->m_pDDraw7, 32, 32, 1, 1, 0, v4, 0, 0, 0);
                        if ( v22 )
                        {
                          CInterfaceD3D::CleanUpCheckObjects(v23);
                          WriteError(v22, "CreateTestSurface");
                          return 7;
                        }
                        else
                        {
                          v11 = 16;
                          v22 = ((int (__thiscall *)(CSurfaceV7 *, int *))v23->PrimarySurface->GetBitDepth)(v23->PrimarySurface, &v11);
                          if ( v22 )
                          {
                            CInterfaceD3D::CleanUpCheckObjects(v23);
                            WriteError(v22, "GetBitDepthWhileCapChecking");
                            return 12;
                          }
                          else
                          {
                            v22 = ((int (__thiscall *)(CSurfaceV7 *, int *, int *))v23->PrimarySurface->GetSurfaceSize)(v23->PrimarySurface, &v8, &v7);
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
                              v22 = v23->m_pDDraw->lpVtbl->GetCaps(v23->m_pDDraw, (LPDDCAPS)&v24, 0);
                              if ( v22 )
                              {
                                CInterfaceD3D::CleanUpCheckObjects(v23);
                                WriteError(v22, "GetCapabilities");
                                return 11;
                              }
                              else if ( (unsigned __int8)sub_2F8BE40(v26, v6, &dword_760B60[65960], 0) )
                              {
                                if ( (v25 & 0x40) != 0 && ((unsigned int)&s_iMsgTracer2.m_aMessages[15456] & v25) != 0 || (v27 & 0x40) != 0 && ((unsigned int)&s_iMsgTracer2.m_aMessages[15456] & v27) != 0 )
                                {
                                  if ( (v25 & 0x400000) != 0 )
                                  {
                                    v5 = (*(int (__thiscall **)(int, IDirectDrawSurface7 **))(*(_DWORD *)v23->field_68 + 72))(v23->field_68, &v23->LandscapeDevice);
                                    v22 = (*(int (__stdcall **)(int, GUID *, int))(*(_DWORD *)v23->m_pIDirect3D7 + 16))(v23->m_pIDirect3D7, &IID_IDirect3DHALDevice, v5);
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
                                      v22 = v23->LandscapeDevice->lpVtbl->AddAttachedSurface(v23->LandscapeDevice, (LPDIRECTDRAWSURFACE7)v28);
                                      if ( v22 )
                                      {
                                        CInterfaceD3D::CleanUpCheckObjects(v23);
                                        WriteError(v22, "Get3dCaps");
                                        return 17;
                                      }
                                      else if ( (v28[0] & 0x200) != 0 && (v28[0] & 0x400) != 0 && (v30 & 0x400) != 0 && v31 <= 0x80 && v32 <= 0x80 && v33 >= 0x100 )
                                      {
                                        v10 = v33 >= 0x200;
                                        *a2 = v10;
                                        if ( dword_46C7D4C == 15623 )
                                        {
                                          *a2 = 0;
                                          BBSupportTracePrintF(1, "GFX ENGINE: No HWO rendering with permedia2 chipset!");
                                        }
                                        dword_3E2E320 = v33;
                                        if ( (v29 & 4) != 0 )
                                        {
                                          v17 = 0;
                                          v18 = 0;
                                          v19 = 0;
                                          v20 = 0;
                                          v22 = ((int (__stdcall *)(IDirectDrawSurface7 *, int (__stdcall *)(struct _DDPIXELFORMAT *, _BYTE *), char *))v23->LandscapeDevice->lpVtbl->AddOverlayDirtyRect)(v23->LandscapeDevice, D3DEnumPixelFormatsCallback, &v17);
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
                                              BBSupportTracePrintF(1, "GFX ENGINE: The needed 4444 format are not supported by the hardware!");
                                            }
                                            if ( dword_46C7D4C == 35362 || dword_46C7D4C == 35347 || dword_46C7D4C == 37122 )
                                            {
                                              *a2 = 0;
                                              CInterfaceD3D::CleanUpCheckObjects(v23);
                                              BBSupportTracePrintF(1, "GFX ENGINE: Savage chipset detected!");
                                              return 26;
                                            }
                                            else
                                            {
                                              if ( v23->LandscapeDevice )
                                              {
                                                v23->LandscapeDevice->lpVtbl->Release(v23->LandscapeDevice);
                                                v23->LandscapeDevice = 0;
                                              }
                                              if ( v23->PrimarySurface )
                                              {
                                                ((void (__thiscall *)(CSurfaceV7 *))v23->PrimarySurface->Release)(v23->PrimarySurface);
                                                PrimarySurface = v23->PrimarySurface;
                                                if ( PrimarySurface )
                                                {
                                                  ((void (__thiscall *)(CSurfaceV7 *, int))PrimarySurface->dtor)(PrimarySurface, 1);
                                                }
                                                v23->PrimarySurface = 0;
                                              }
                                              if ( v23->field_68 )
                                              {
                                                (*(void (__thiscall **)(int))(*(_DWORD *)v23->field_68 + 4))(v23->field_68);
                                                v15 = (void (__thiscall ***)(_DWORD, int))v23->field_68;
                                                if ( v15 )
                                                {
                                                  (**v15)(v15, 1);
                                                }
                                                v23->field_68 = 0;
                                              }
                                              if ( v23->m_pIDirect3D7 )
                                              {
                                                (*(void (__stdcall **)(int))(*(_DWORD *)v23->m_pIDirect3D7 + 8))(v23->m_pIDirect3D7);
                                                v23->m_pIDirect3D7 = 0;
                                              }
                                              if ( !v23->m_pDDraw7 )
                                              {
                                                return 0;
                                              }
                                              v23->m_pDDraw7->lpVtbl->Release(v23->m_pDDraw7);
                                              v23->m_pDDraw7 = 0;
                                              return 0;
                                            }
                                          }
                                          else
                                          {
                                            CInterfaceD3D::CleanUpCheckObjects(v23);
                                            *a2 = 0;
                                            BBSupportTracePrintF(1, "GFX ENGINE: The needed texture formats are not supported by the hardware!");
                                            return 21;
                                          }
                                        }
                                        else
                                        {
                                          CInterfaceD3D::CleanUpCheckObjects(v23);
                                          BBSupportTracePrintF(1, "GFX ENGINE: Needed alpha blend capabilities for hardware rendering unsupported!");
                                          return 19;
                                        }
                                      }
                                      else
                                      {
                                        CInterfaceD3D::CleanUpCheckObjects(v23);
                                        BBSupportTracePrintF(1, "GFX ENGINE: A needed basic capability for the hardware renderer is unsupported!");
                                        return 18;
                                      }
                                    }
                                  }
                                  else
                                  {
                                    CInterfaceD3D::CleanUpCheckObjects(v23);
                                    BBSupportTracePrintF(1, "GFX ENGINE: Color keying is not in all needed blit modes available!");
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
int  CInterfaceD3D::IsInterface3Available(struct HWND__ * a2) {
  
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
    v11 = DirectDrawCreate(0, (LPDIRECTDRAW *)&v12->m_pDDraw, 0);
    if ( v11 )
    {
      WriteError(v11, "CreateDirectDrawObject");
      return 3;
    }
    else
    {
      g_pDirectDraw = (int)v12->m_pDDraw;
      v11 = v12->m_pDDraw->lpVtbl->SetCooperativeLevel(v12->m_pDDraw, a2, 8);
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
          v11 = ((int (__thiscall *)(CSurfaceV7 *, IDirectDraw7 *, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD))v12->PrimarySurface->CreateSurface)(v12->PrimarySurface, v12->m_pDDraw, 0, 0, 1, 0, 0, 0, 1, 0, 0);
          if ( v11 )
          {
            CInterfaceD3D::CleanUpCheckObjects(v12);
            WriteError(v11, "CreatePrimarySurface");
            return 8;
          }
          else
          {
            v11 = ((int (__thiscall *)(CSurfaceV7 *, unsigned __int8 *))v12->PrimarySurface->GetPixelFormat)(v12->PrimarySurface, &v10);
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
                v11 = (*(int (__thiscall **)(int, IDirectDraw7 *, int, int, int, int, _DWORD, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12->field_68 + 48))(v12->field_68, v12->m_pDDraw, 32, 32, 1, 1, 0, v3, 0, 0, 0);
                if ( v11 )
                {
                  CInterfaceD3D::CleanUpCheckObjects(v12);
                  WriteError(v11, "CreateTestSurface");
                  return 7;
                }
                else
                {
                  v7 = 16;
                  v11 = ((int (__thiscall *)(CSurfaceV7 *, int *))v12->PrimarySurface->GetBitDepth)(v12->PrimarySurface, &v7);
                  if ( v11 )
                  {
                    CInterfaceD3D::CleanUpCheckObjects(v12);
                    WriteError(v11, "GetBitDepthWhileCapChecking");
                    return 12;
                  }
                  else
                  {
                    v11 = ((int (__thiscall *)(CSurfaceV7 *, int *, int *))v12->PrimarySurface->GetSurfaceSize)(v12->PrimarySurface, &v6, &v5);
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
                      v11 = v12->m_pDDraw->lpVtbl->GetCaps(v12->m_pDDraw, (LPDDCAPS)&v13, 0);
                      if ( v11 )
                      {
                        CInterfaceD3D::CleanUpCheckObjects(v12);
                        WriteError(v11, "GetCapabilities");
                        return 11;
                      }
                      else if ( (unsigned __int8)sub_2F8BE40(v15, v4, 4000000, 0) )
                      {
                        if ( (v14 & 0x40) != 0 && ((unsigned int)&MEMORY[0x4000000] & v14) != 0 || (v16 & 0x40) != 0 && ((unsigned int)&MEMORY[0x4000000] & v16) != 0 )
                        {
                          if ( (v14 & 0x400000) != 0 )
                          {
                            if ( v12->LandscapeDevice )
                            {
                              v12->LandscapeDevice->lpVtbl->Release(v12->LandscapeDevice);
                              v12->LandscapeDevice = 0;
                            }
                            if ( v12->PrimarySurface )
                            {
                              ((void (__thiscall *)(CSurfaceV7 *))v12->PrimarySurface->Release)(v12->PrimarySurface);
                              PrimarySurface = v12->PrimarySurface;
                              if ( PrimarySurface )
                              {
                                ((void (__thiscall *)(CSurfaceV7 *, int))PrimarySurface->dtor)(PrimarySurface, 1);
                              }
                              v12->PrimarySurface = 0;
                            }
                            if ( v12->field_68 )
                            {
                              (*(void (__thiscall **)(int))(*(_DWORD *)v12->field_68 + 4))(v12->field_68);
                              v8 = (void (__thiscall ***)(_DWORD, int))v12->field_68;
                              if ( v8 )
                              {
                                (**v8)(v8, 1);
                              }
                              v12->field_68 = 0;
                            }
                            if ( v12->m_pIDirect3D7 )
                            {
                              (*(void (__stdcall **)(int))(*(_DWORD *)v12->m_pIDirect3D7 + 8))(v12->m_pIDirect3D7);
                              v12->m_pIDirect3D7 = 0;
                            }
                            if ( !v12->m_pDDraw7 )
                            {
                              return 0;
                            }
                            v12->m_pDDraw7->lpVtbl->Release(v12->m_pDDraw7);
                            v12->m_pDDraw7 = 0;
                            return 0;
                          }
                          else
                          {
                            CInterfaceD3D::CleanUpCheckObjects(v12);
                            BBSupportTracePrintF(1, "GFX ENGINE: Color keying is not in all needed blit modes available!");
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
// Decompiled from char __thiscall CInterfaceD3D::CanCreateEngine(_DWORD *this, bool a2)
bool  CInterfaceD3D::CanCreateEngine(bool a2) {
  
  int v3; // eax
  int v5; // [esp+14h] [ebp-14h]
  CSurfaceV7 *SurfacePtr; // [esp+24h] [ebp-4h]

  SurfacePtr = CSurface::CreateSurfacePtr(a2);
  if ( SurfacePtr )
  {
    v3 = j__abs(g_uGfxMode == 1);
    v5 = ((int (__thiscall *)(CSurfaceV7 *, _DWORD, int, int, int, int, _DWORD, int, _DWORD, _DWORD, _DWORD))SurfacePtr->CreateSurface)(SurfacePtr, this[1], 32, 32, 1, 1, 0, v3, 0, 0, 0);
    if ( v5 )
    {
      WriteError(v5, "CanRebuildEngine");
      ((void (__thiscall *)(CSurfaceV7 *, int))SurfacePtr->dtor)(SurfacePtr, 1);
      return 0;
    }
    else
    {
      ((void (__thiscall *)(CSurfaceV7 *))SurfacePtr->Release)(SurfacePtr);
      ((void (__thiscall *)(CSurfaceV7 *, int))SurfacePtr->dtor)(SurfacePtr, 1);
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

  if ( this->LandscapeDevice )
  {
    this->LandscapeDevice->lpVtbl->Release(this->LandscapeDevice);
    this->LandscapeDevice = 0;
  }
  if ( this->PrimarySurface )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->PrimarySurface->Release)(this->PrimarySurface);
    if ( this->PrimarySurface )
    {
      ((void (__thiscall *)(CSurfaceV7 *, int))this->PrimarySurface->dtor)(this->PrimarySurface, 1);
    }
    this->PrimarySurface = 0;
  }
  if ( this->field_68 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)this->field_68 + 4))(this->field_68);
    if ( this->field_68 )
    {
      (**(void (__thiscall ***)(int, int))this->field_68)(this->field_68, 1);
    }
    this->field_68 = 0;
  }
  if ( this->m_pIDirect3D7 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)this->m_pIDirect3D7 + 8))(this->m_pIDirect3D7);
    this->m_pIDirect3D7 = 0;
  }
  if ( this->m_pDDraw7 )
  {
    this->m_pDDraw7->lpVtbl->Release(this->m_pDDraw7);
    this->m_pDDraw7 = 0;
  }
  result = this;
  if ( !this->m_pDDraw )
  {
    return result;
  }
  result = (CInterfaceD3D *)this->m_pDDraw->lpVtbl->Release(this->m_pDDraw);
  this->m_pDDraw = 0;
  g_pDirectDraw = 0;
  return result;
}


// address=[0x2f996f0]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::DecreaseCacheRetrys(CInterfaceD3D *this)
void  CInterfaceD3D::DecreaseCacheRetrys(void) {
  
  CInterfaceD3D *result; // eax

  result = this;
  --this[1].m_sClipper1.m_vChar.u4;
  return result;
}


// address=[0x2f99720]
// Decompiled from int __thiscall CInterfaceD3D::GetCacheRetrys(CInterfaceD3D *this)
int  CInterfaceD3D::GetCacheRetrys(void) {
  
  return this[1].m_sClipper1.m_vChar.u4;
}


