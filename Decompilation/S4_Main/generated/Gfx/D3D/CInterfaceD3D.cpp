#include "CInterfaceD3D.h"

// Definitions for class CInterfaceD3D

// address=[0x2f5f250]
// Decompiled from HRESULT __thiscall CInterfaceD3D::BlitCursor(CInterfaceD3D *this)
void  CInterfaceD3D::BlitCursor(void) {
  
  HRESULT result; // eax
  int v2; // [esp+0h] [ebp-8h]

  v2 = CFixCursor::Show((CFixCursor *)((char *)this + 1860), this->m_pFinalRenderSurface);
  if ( v2 != 0 )
  {
    WriteError(v2, "BlitMoveCursor");
  }
  result = CFixCursor::Show((CFixCursor *)((char *)this + 1900), this->m_pFinalRenderSurface);
  *((_BYTE *)this + 1859) = 1;
  if ( result != 0 )
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
  CFixCursor::CFixCursor((CFixCursor *)((char *)this + 1860));
  CFixCursor::CFixCursor((CFixCursor *)((char *)this + 1900));
  *((_DWORD *)this + 463) = 2000;
  *((_BYTE *)this + 1859) = 0;
  *((_BYTE *)this + 1858) = 0;
  *((_BYTE *)this + 1857) = 0;
  *((_DWORD *)this + 461) = 0;
  this->m_iNumberOfCachedSurfaces = 0;
  *((_BYTE *)this + 1856) = 0;
  *((_DWORD *)this + 460) = 0;
  *((_DWORD *)this + 459) = 0;
  memset(this->m_bAvailableResolutions, 0, sizeof(this->m_bAvailableResolutions));
  this->m_bHardwareRuns = 0;
  this->m_bSoftwareRuns = 0;
  this->m_bEngineWasRebuilded = 1;
  MEMORY[0x3E2E2B8] = 0;
  for ( i = 0;
        i < 14;
        ++i )
  {
    this->m_pDDGuiSurfaces[i] = 0;
  }
  CInterfaceD3D::InitTexturedLandscapeModule(this);
  this->m_pDDraw = 0;
  this->m_pDDraw7 = 0;
  this->m_pZoomCursorSurface = 0;
  this->m_pMoveCursorSurface = 0;
  this->m_pTmpSurface = 0;
  this->m_pMiniMapAreaSurface = 0;
  this->m_pMiniMapSurface = 0;
  this->m_pLandscapeSurface = 0;
  this->m_pCameraWindowSurface = 0;
  this->m_pLandscapeSurface2 = 0;
  this->m_pFinalRenderSurface = 0;
  this->m_pPrimarySurface = 0;
  this->m_pIDirect3D7 = 0;
  this->LandscapeDevice = 0;
  this->m_pObjectDevice = 0;
  this->D3DVertexPtr = 0;
  for ( j = 0;
        j < 2;
        ++j )
  {
    this->m_pDDObjectSurfacePtr[j] = 0;
    this->m_pDDSourceObjectSurfacePtr[j] = 0;
    this->m_pcPictureManager[j] = 0;
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
  CSurfaceV7 *v11; // [esp+A4h] [ebp-28h]
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
    if ( this->m_pCacheManagers[i] != 0 )
    {
      if ( CCachePageManager::IsVideoSurfaceLocked(this->m_pCacheManagers[i]) )
      {
        CCachePageManager::UnlockVideoSurface(this->m_pCacheManagers[i]);
      }
      if ( CCachePageManager::IsSourceSurfaceLocked(this->m_pCacheManagers[i]) )
      {
        CCachePageManager::UnlockSourceSurface(this->m_pCacheManagers[i]);
      }
      v2 = this->m_pCacheManagers[i];
      if ( v2 != 0 )
      {
        delete v2;
      }
      this->m_pCacheManagers[i] = 0;
    }
    if ( this->m_pCacheSurfaces[i] != 0 )
    {
      this->m_pCacheSurfaces[i]->lpVtbl->Release(this->m_pCacheSurfaces[i]);
      this->m_pCacheSurfaces[i] = 0;
    }
  }
  for ( j = 1;
        j >= 0;
        --j )
  {
    if ( this->m_pcPictureManager[j] != 0 )
    {
      if ( CCachePageManager::IsVideoSurfaceLocked(this->m_pcPictureManager[j]) )
      {
        CCachePageManager::UnlockVideoSurface(this->m_pcPictureManager[j]);
      }
      if ( CCachePageManager::IsSourceSurfaceLocked(this->m_pcPictureManager[j]) )
      {
        CCachePageManager::UnlockSourceSurface(this->m_pcPictureManager[j]);
      }
      v1 = (CUploadCachePageManager *)this->m_pcPictureManager[j];
      if ( v1 != 0 )
      {
        delete v1;
      }
      this->m_pcPictureManager[j] = 0;
    }
    if ( this->m_pDDSourceObjectSurfacePtr[j] != 0 )
    {
      ((void (__thiscall *)(CSurfaceV7 *))this->m_pDDSourceObjectSurfacePtr[j]->Release)(this->m_pDDSourceObjectSurfacePtr[j]);
      v14 = this->m_pDDSourceObjectSurfacePtr[j];
      if ( v14 != 0 )
      {
        v14->dtor(v14, 1);
      }
      this->m_pDDSourceObjectSurfacePtr[j] = 0;
    }
    if ( this->m_pDDObjectSurfacePtr[j] != 0 )
    {
      ((void (__thiscall *)(CSurfaceV7 *))this->m_pDDObjectSurfacePtr[j]->Release)(this->m_pDDObjectSurfacePtr[j]);
      v13 = this->m_pDDObjectSurfacePtr[j];
      if ( v13 != 0 )
      {
        v13->dtor(v13, 1);
      }
      this->m_pDDObjectSurfacePtr[j] = 0;
    }
  }
  if ( s_bCursorIsFixed != 0 )
  {
    ClipCursor(0);
    s_bCursorIsFixed = 0;
  }
  if ( s_bCursorIsVisible == 0 )
  {
    ShowCursor(1);
    s_bCursorIsVisible = 1;
  }
  if ( s_hCursor != 0 )
  {
    SetClassLongA(GfxEngineSetup.m_hWnd, -12, s_hCursor);
    SetCursor((HCURSOR)s_hCursor);
    s_hCursor = 0;
  }
  SurfaceClipper::ReleaseClipper(&this->m_sClipper1);
  SurfaceClipper::ReleaseClipper(&this->m_sMinimapClipper);
  if ( g_pSoftwareTexturePages != 0 )
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
    if ( this->m_pDDTextureSurfaces[m] != 0 )
    {
      ((void (__thiscall *)(CSurfaceV7 *))this->m_pDDTextureSurfaces[m]->Release)(this->m_pDDTextureSurfaces[m]);
      v12 = this->m_pDDTextureSurfaces[m];
      if ( v12 != 0 )
      {
        v12->dtor(v12, 1);
      }
      this->m_pDDTextureSurfaces[m] = 0;
    }
    g_pTextureTable[m] = 0;
  }
  for ( n = 14;
        n >= 0;
        --n )
  {
    if ( this->m_pDDGuiSurfaces[n] != 0 )
    {
      ((void (__thiscall *)(CSurfaceV7 *))this->m_pDDGuiSurfaces[n]->Release)(this->m_pDDGuiSurfaces[n]);
      v11 = this->m_pDDGuiSurfaces[n];
      if ( v11 != 0 )
      {
        v11->dtor(v11, 1);
      }
      this->m_pDDGuiSurfaces[n] = 0;
    }
  }
  SurfaceClipper::ReleaseClipper(&this->m_sClipper1);
  SurfaceClipper::ReleaseClipper(&this->m_sMinimapClipper);
  if ( this->m_pObjectDevice != 0 )
  {
    this->m_pObjectDevice->Release(this->m_pObjectDevice);
  }
  if ( this->LandscapeDevice != 0 )
  {
    this->LandscapeDevice->Release(this->LandscapeDevice);
  }
  if ( this->m_pZoomCursorSurface != 0 )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->m_pZoomCursorSurface->Release)(this->m_pZoomCursorSurface);
    ZoomCursorSurface = this->m_pZoomCursorSurface;
    if ( ZoomCursorSurface != 0 )
    {
      ZoomCursorSurface->dtor(ZoomCursorSurface, 1);
    }
    this->m_pZoomCursorSurface = 0;
  }
  if ( this->m_pMoveCursorSurface != 0 )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->m_pMoveCursorSurface->Release)(this->m_pMoveCursorSurface);
    MoveCursorSurface = this->m_pMoveCursorSurface;
    if ( MoveCursorSurface != 0 )
    {
      MoveCursorSurface->dtor(MoveCursorSurface, 1);
    }
    this->m_pMoveCursorSurface = 0;
  }
  if ( this->m_pLandscapeSurface != 0 )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->m_pLandscapeSurface->Release)(this->m_pLandscapeSurface);
    LandscapeSurface = this->m_pLandscapeSurface;
    if ( LandscapeSurface != 0 )
    {
      LandscapeSurface->dtor(LandscapeSurface, 1);
    }
    this->m_pLandscapeSurface = 0;
  }
  CInterfaceD3D::DestroyCameraWindowSurface(this);
  if ( this->m_pFinalRenderSurface != 0 )
  {
    if ( ((unsigned __int8 (__thiscall *)(CSurfaceV7 *))this->m_pFinalRenderSurface->j_?IsBackBufferReference@CSurfaceV7@@UAE_NXZ)(this->m_pFinalRenderSurface) == 0 )
    {
      ((void (__thiscall *)(CSurfaceV7 *))this->m_pFinalRenderSurface->Release)(this->m_pFinalRenderSurface);
    }
    FinalRenderSurface = this->m_pFinalRenderSurface;
    if ( FinalRenderSurface != 0 )
    {
      FinalRenderSurface->dtor(FinalRenderSurface, 1);
    }
    this->m_pFinalRenderSurface = 0;
  }
  if ( this->m_pMiniMapSurface != 0 )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->m_pMiniMapSurface->Release)(this->m_pMiniMapSurface);
    MiniMapSurface = this->m_pMiniMapSurface;
    if ( MiniMapSurface != 0 )
    {
      MiniMapSurface->dtor(MiniMapSurface, 1);
    }
    this->m_pMiniMapSurface = 0;
  }
  if ( this->m_pMiniMapAreaSurface != 0 )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->m_pMiniMapAreaSurface->Release)(this->m_pMiniMapAreaSurface);
    MiniMapAreaSurface = this->m_pMiniMapAreaSurface;
    if ( MiniMapAreaSurface != 0 )
    {
      MiniMapAreaSurface->dtor(MiniMapAreaSurface, 1);
    }
    this->m_pMiniMapAreaSurface = 0;
  }
  if ( this->m_pPrimarySurface != 0 )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->m_pPrimarySurface->Release)(this->m_pPrimarySurface);
    PrimarySurface = this->m_pPrimarySurface;
    if ( PrimarySurface != 0 )
    {
      PrimarySurface->dtor(PrimarySurface, 1);
    }
    this->m_pPrimarySurface = 0;
  }
  if ( this->m_pTmpSurface != 0 )
  {
    v3 = (void (__thiscall ***)(_DWORD, int))this->m_pTmpSurface;
    if ( v3 != 0 )
    {
      (**v3)(v3, 1);
    }
    this->m_pTmpSurface = 0;
  }
  if ( this->m_pDDraw7 != 0 )
  {
    this->m_pDDraw7->lpVtbl->Release(this->m_pDDraw7);
  }
  if ( this->m_pIDirect3D7 != 0 )
  {
    ((void (__stdcall *)(IDirect3D7 *))this->m_pIDirect3D7->Release)(this->m_pIDirect3D7);
  }
  this->m_pDDraw = 0;
  this->m_pDDraw7 = 0;
  this->m_pIDirect3D7 = 0;
  this->LandscapeDevice = 0;
  this->m_pObjectDevice = 0;
  CInterfaceD3D::DeleteEngineData(this);
  BBSupportTracePrintF(1, "GFX ENGINE: DD interface successfully destroyed!");
  SurfaceClipper::~SurfaceClipper(&this->m_sMinimapClipper);
  SurfaceClipper::~SurfaceClipper(&this->m_sClipper1);
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
  if ( this->m_bHardwareRuns != 0 || this->m_bSoftwareRuns != 0 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT COMMON: Engine is already initialized!");
    return 1;
  }
  this->m_bHiTextureQuality = SGfxRenderConfiguration::IsHQTextureSet(&GfxEngineSetup.sRenderSetup);
  this->m_bForceBlt = !SGfxRenderConfiguration::IsForceBlit(&GfxEngineSetup.sRenderSetup);
  if ( s_hCursor != 0 )
  {
    SetClassLongA(GfxEngineSetup.sRenderSetup.m_hWnd, -12, s_hCursor);
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
    if ( s_hCursorHandles[i] == nullptr )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Couldn't create cursors!");
      return 0;
    }
  }
  GfxEngineSetup.bMiniMapRefresh = 1;
  this->m_pTmpSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
  if ( this->m_pTmpSurface == nullptr )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
    return 0;
  }
  if ( g_pDirectDraw != nullptr )
  {
    this->m_pDDraw = g_pDirectDraw;
  }
  else
  {
    hModule = GetModuleHandleA("DDRAW");
    if ( hModule == nullptr )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Direct Draw is not accessible!");
      return 0;
    }
    DirectDrawCreateEx = (HRESULT (__stdcall *)(GUID *, LPVOID *, const IID *const, IUnknown *))GetProcAddress(hModule, "DirectDrawCreateEx");
    if ( DirectDrawCreateEx == nullptr )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: DirectDrawCreateEx not found! Interface 7 or higher not available!");
      return 0;
    }
    v24 = DirectDrawCreateEx(nullptr, (LPVOID *)&this->m_pDDraw, &IID_IDirectDraw7, nullptr);
    if ( v24 != 0 )
    {
      WriteError(v24, "CreateDirectDrawObject");
      return 0;
    }
    g_pDirectDraw = this->m_pDDraw;
  }
  v25 = this->m_pDDraw->lpVtbl->QueryInterface(this->m_pDDraw, &IID_IDirectDraw7, (LPVOID *)&this->m_pDDraw7);
  if ( v25 != 0 )
  {
    WriteError(v25, "QueryInterface");
    return 0;
  }
  else
  {
    v26 = this->m_pDDraw7->lpVtbl->SetCooperativeLevel(this->m_pDDraw7, GfxEngineSetup.sRenderSetup.m_hWnd, 8);
    if ( v26 != 0 )
    {
      WriteError(v26, "SetCooperativeLevel");
      return 0;
    }
    else
    {
      this->m_pPrimarySurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
      if ( this->m_pPrimarySurface != nullptr )
      {
        if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
        {
          m_pDDraw = this->m_pDDraw;
        }
        else
        {
          m_pDDraw = this->m_pDDraw7;
        }
        v2 = j__abs(GfxEngineSetup.iCurrentGfxMode == 1);
        v27 = this->m_pPrimarySurface->CreateSurface(this->m_pPrimarySurface, m_pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, 0, 0, v2, 1, 0, 0);
        if ( v27 != nullptr )
        {
          WriteError((int)v27, "CreatePrimarySurface");
          return 0;
        }
        else
        {
          v28 = ((int (__thiscall *)(CSurface *, char *))this->m_pPrimarySurface->GetPixelFormat)(this->m_pPrimarySurface, &v42);
          if ( v28 != 0 )
          {
            WriteError(v28, "RetrievePixelFormatFromPrimarySurface");
            return 0;
          }
          else
          {
            if ( v42 != 0 )
            {
              GfxEngineSetup.iCurrentGfxMode = 1;
            }
            else
            {
              GfxEngineSetup.iCurrentGfxMode = 2;
            }
            this->m_pMoveCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
            if ( this->m_pMoveCursorSurface != nullptr )
            {
              if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
              {
                m_pDDraw7 = this->m_pDDraw;
              }
              else
              {
                m_pDDraw7 = this->m_pDDraw7;
              }
              v3 = j__abs(GfxEngineSetup.iCurrentGfxMode == 1);
              v29 = this->m_pMoveCursorSurface->CreateSurface(this->m_pMoveCursorSurface, m_pDDraw7, 32, 32, 1, 0, 0, v3, 0, 0, 0);
              if ( v29 != nullptr )
              {
                WriteError((int)v29, "CreateMoveCursorSurface");
                return 0;
              }
              else
              {
                if ( GfxEngineSetup.iCurrentGfxMode == 1 )
                {
                  CFixCursor::SetSurfacePtr(&this->m_cMoveCursor, 0x73u, (CSurfaceV7 *)this->m_pMoveCursorSurface, g_sColorKeyMagenta555);
                }
                else
                {
                  CFixCursor::SetSurfacePtr(&this->m_cMoveCursor, 0x73u, (CSurfaceV7 *)this->m_pMoveCursorSurface, g_sColorKeyMagenta565);
                }
                if ( GfxEngineSetup.iCurrentGfxMode == 1 )
                {
                  this->m_pMoveCursorSurface->SetColorKey((CSurfaceV7 *)this->m_pMoveCursorSurface, 8, &g_sColorKeyMagenta555);
                }
                else
                {
                  this->m_pMoveCursorSurface->SetColorKey((CSurfaceV7 *)this->m_pMoveCursorSurface, 8, &g_sColorKeyMagenta565);
                }
                this->m_pZoomCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
                if ( this->m_pZoomCursorSurface != nullptr )
                {
                  if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
                  {
                    v18 = this->m_pDDraw;
                  }
                  else
                  {
                    v18 = this->m_pDDraw7;
                  }
                  v4 = j__abs(GfxEngineSetup.iCurrentGfxMode == 1);
                  v30 = this->m_pZoomCursorSurface->CreateSurface(this->m_pZoomCursorSurface, v18, 32, 32, 1, 0, 0, v4, 0, 0, 0);
                  if ( v30 != nullptr )
                  {
                    WriteError((int)v30, "CreateZoomCursorSurface");
                    return 0;
                  }
                  else
                  {
                    if ( GfxEngineSetup.iCurrentGfxMode == 1 )
                    {
                      CFixCursor::SetSurfacePtr(&this->m_cZoomCursor, 0x74u, (CSurfaceV7 *)this->m_pZoomCursorSurface, g_sColorKeyMagenta555);
                    }
                    else
                    {
                      CFixCursor::SetSurfacePtr(&this->m_cZoomCursor, 0x74u, (CSurfaceV7 *)this->m_pZoomCursorSurface, g_sColorKeyMagenta565);
                    }
                    if ( GfxEngineSetup.iCurrentGfxMode == 1 )
                    {
                      this->m_pZoomCursorSurface->SetColorKey((CSurfaceV7 *)this->m_pZoomCursorSurface, 8, &g_sColorKeyMagenta555);
                    }
                    else
                    {
                      this->m_pZoomCursorSurface->SetColorKey((CSurfaceV7 *)this->m_pZoomCursorSurface, 8, &g_sColorKeyMagenta565);
                    }
                    this->m_pMiniMapSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
                    if ( this->m_pMiniMapSurface != nullptr )
                    {
                      if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
                      {
                        v17 = this->m_pDDraw;
                      }
                      else
                      {
                        v17 = this->m_pDDraw7;
                      }
                      v5 = j__abs(GfxEngineSetup.iCurrentGfxMode == 1);
                      v31 = this->m_pMiniMapSurface->CreateSurface(this->m_pMiniMapSurface, v17, 240, 160, 1, 0, 0, v5, 0, 0, 0);
                      if ( v31 != nullptr )
                      {
                        WriteError((int)v31, "CreateMiniMapSurface");
                        return 0;
                      }
                      else
                      {
                        this->m_pMiniMapSurface->ClearSurface((CSurfaceV7 *)this->m_pMiniMapSurface, nullptr);
                        this->m_pMiniMapSurface->SetColorKey((CSurfaceV7 *)this->m_pMiniMapSurface, 8, (int *)&g_sColorKeyBlack);
                        this->m_pMiniMapAreaSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
                        if ( this->m_pMiniMapAreaSurface != nullptr )
                        {
                          if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
                          {
                            v16 = this->m_pDDraw;
                          }
                          else
                          {
                            v16 = this->m_pDDraw7;
                          }
                          v6 = j__abs(GfxEngineSetup.iCurrentGfxMode == 1);
                          v32 = this->m_pMiniMapAreaSurface->CreateSurface(this->m_pMiniMapAreaSurface, v16, 240, 160, 1, 0, 0, v6, 0, 0, 0);
                          if ( v32 != nullptr )
                          {
                            WriteError((int)v32, "CreateMiniMapAreaSurface");
                            return 0;
                          }
                          else
                          {
                            v33 = this->m_pMiniMapAreaSurface->ClearSurface((CSurfaceV7 *)this->m_pMiniMapAreaSurface, nullptr);
                            if ( v33 != 0 )
                            {
                              WriteError(v33, "ClearMiniMapSurface");
                            }
                            v34 = ((int (__thiscall *)(CSurface *, int, void *))this->m_pMiniMapAreaSurface->SetColorKey)(this->m_pMiniMapAreaSurface, 8, &g_sColorKeyBlack);
                            if ( v34 != 0 )
                            {
                              WriteError(v34, "SetMiniMapColorKey");
                            }
                            BBSupportTracePrintF(1, "GFX ENGINE: Size of render surface: %d x %d", GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight);
                            this->m_pLandscapeSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
                            if ( this->m_pLandscapeSurface != nullptr )
                            {
                              if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
                              {
                                v15 = this->m_pDDraw;
                              }
                              else
                              {
                                v15 = this->m_pDDraw7;
                              }
                              v10 = j__abs(GfxEngineSetup.iCurrentGfxMode == 1);
                              IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup);
                              v35 = this->m_pLandscapeSurface->CreateSurface(this->m_pLandscapeSurface, v15, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, IsHardwareLandscapeEngine, 0, v10, 0, 0, 0);
                              if ( v35 != nullptr )
                              {
                                WriteError((int)v35, "CreateLandscapeSurface");
                                return 0;
                              }
                              else
                              {
                                this->m_pLandscapeSurface2 = this->m_pLandscapeSurface;
                                this->m_pFinalRenderSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
                                if ( this->m_pFinalRenderSurface != nullptr )
                                {
                                  v14 = GfxEngineSetup.iCurrentGfxMode == 1;
                                  if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
                                  {
                                    m_pDDraw = this->m_pDDraw;
                                  }
                                  else
                                  {
                                    m_pDDraw = this->m_pDDraw7;
                                  }
                                  HardwareLandscapeEngine = (unsigned __int8)SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup);
                                  v11 = j__abs(v14);
                                  HardwareLandscapeEngine2 = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup);
                                  v36 = this->m_pFinalRenderSurface->CreateSurface(this->m_pFinalRenderSurface, m_pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, HardwareLandscapeEngine2, 0, v11, 0, HardwareLandscapeEngine, 0);
                                  if ( v36 != nullptr )
                                  {
                                    WriteError((int)v36, "CreateFinalRenderSurface");
                                    return 0;
                                  }
                                  else
                                  {
                                    inited = SurfaceClipper::InitClipper(&this->m_sClipper1, this->m_pDDraw7);
                                    if ( inited != 0 )
                                    {
                                      WriteError(inited, "CreateClipper1");
                                      return 0;
                                    }
                                    else
                                    {
                                      v38 = SurfaceClipper::InitClipper(&this->m_sMinimapClipper, this->m_pDDraw7);
                                      if ( v38 != 0 )
                                      {
                                        WriteError(v38, "Create Minimap Clipper");
                                        return 0;
                                      }
                                      else
                                      {
                                        v39 = SurfaceClipper::SetClipWindow(&this->m_sClipper1, (HWND *)GfxEngineSetup.sRenderSetup.m_hWnd);
                                        if ( v39 != 0 )
                                        {
                                          WriteError(v39, "AssignClipper1");
                                          return 0;
                                        }
                                        else
                                        {
                                          Clipper = SurfaceClipper::GetClipper(&this->m_sClipper1);
                                          v40 = this->m_pPrimarySurface->SetClipper((CSurfaceV7 *)this->m_pPrimarySurface, Clipper);
                                          if ( v40 != 0 )
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
  if ( v34->m_bHardwareRuns != 0 || v34->m_bSoftwareRuns != 0 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT COMMON: Engine is already initialized!");
    return 1;
  }
  BYTE1(v34[1].m_sClipper1.m_vChar.u8) = SGfxRenderConfiguration::IsHQTextureSet(&GfxEngineSetup);
  BYTE2(v34[1].m_sClipper1.m_vChar.u8) = 0;
  if ( s_hCursor != 0 )
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
    if ( s_hCursorHandles[i] == 0 )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Couldn't create cursors!");
      return 0;
    }
  }
  MEMORY[0x3E2E30C] = 1;
  v34->m_pTmpSurface = (int)CSurface::CreateSurfacePtr(GfxEngineSetup.m_bUseDD3Interface);
  if ( v34->m_pTmpSurface == 0 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
    return 0;
  }
  if ( g_pDirectDraw != 0 )
  {
    v34->m_pDDraw = g_pDirectDraw;
  }
  else
  {
    inited = DirectDrawCreate(0, (LPDIRECTDRAW *)&v34->m_pDDraw, 0);
    if ( inited != 0 )
    {
      WriteError(inited, "CreateDirectDrawObject");
      return 0;
    }
    g_pDirectDraw = v34->m_pDDraw;
  }
  inited = v34->m_pDDraw->lpVtbl->SetCooperativeLevel(v34->m_pDDraw, GfxEngineSetup.m_hWnd, 8);
  if ( inited != 0 )
  {
    WriteError(inited, "SetCooperativeLevel");
    return 0;
  }
  else
  {
    v34->m_pPrimarySurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bUseDD3Interface);
    if ( v34->m_pPrimarySurface != 0 )
    {
      Number = MEMORY[0x3E2E2B8] == 1;
      if ( GfxEngineSetup.m_bUseDD3Interface )
      {
        m_pDDraw = v34->m_pDDraw;
      }
      else
      {
        m_pDDraw = v34->m_pDDraw7;
      }
      v2 = j__abs(Number);
      inited = (HRESULT)v34->m_pPrimarySurface->CreateSurface(v34->m_pPrimarySurface, m_pDDraw, GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight, 1, 0, 0, v2, 1, 0, 0);
      if ( inited != 0 )
      {
        WriteError(inited, "CreatePrimarySurface");
        return 0;
      }
      else
      {
        inited = v34->m_pPrimarySurface->GetBitDepth(v34->m_pPrimarySurface, &v13);
        if ( inited != 0 )
        {
          WriteError(inited, "RetrieveBitDepth");
          return 0;
        }
        else if ( v13 == 16 )
        {
          inited = ((int (__thiscall *)(CSurfaceV7 *, char *))v34->m_pPrimarySurface->GetPixelFormat)(v34->m_pPrimarySurface, &v35);
          if ( inited != 0 )
          {
            WriteError(inited, "RetrievePixelFormatFromPrimarySurface");
            return 0;
          }
          else
          {
            if ( v35 != 0 )
            {
              MEMORY[0x3E2E2B8] = 1;
            }
            else
            {
              MEMORY[0x3E2E2B8] = 2;
            }
            v34->m_pMoveCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bUseDD3Interface);
            if ( v34->m_pMoveCursorSurface != 0 )
            {
              v29 = MEMORY[0x3E2E2B8] == 1;
              if ( GfxEngineSetup.m_bUseDD3Interface )
              {
                DDraw7 = v34->m_pDDraw;
              }
              else
              {
                DDraw7 = v34->m_pDDraw7;
              }
              v3 = j__abs(v29);
              inited = (HRESULT)v34->m_pMoveCursorSurface->CreateSurface(v34->m_pMoveCursorSurface, DDraw7, 32, 32, 1, 0, 0, v3, 0, 0, 0);
              if ( inited != 0 )
              {
                WriteError(inited, "CreateMoveCursorSurface");
                return 0;
              }
              else
              {
                if ( MEMORY[0x3E2E2B8] == 1 )
                {
                  v27 = g_sColorKeyMagenta555;
                }
                else
                {
                  v27 = g_sColorKeyMagenta565;
                }
                CFixCursor::SetSurfacePtr((CFixCursor *)&v34[1].m_sClipper1.m_vChar.uC, 0x73u, v34->m_pMoveCursorSurface, v27);
                if ( MEMORY[0x3E2E2B8] == 1 )
                {
                  v26 = &g_sColorKeyMagenta555;
                }
                else
                {
                  v26 = &g_sColorKeyMagenta565;
                }
                v34->m_pMoveCursorSurface->SetColorKey(v34->m_pMoveCursorSurface, 8, v26);
                v34->m_pZoomCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bUseDD3Interface);
                if ( v34->m_pZoomCursorSurface != 0 )
                {
                  v25 = MEMORY[0x3E2E2B8] == 1;
                  if ( GfxEngineSetup.m_bUseDD3Interface )
                  {
                    v24 = v34->m_pDDraw;
                  }
                  else
                  {
                    v24 = v34->m_pDDraw7;
                  }
                  v4 = j__abs(v25);
                  inited = (HRESULT)v34->m_pZoomCursorSurface->CreateSurface(v34->m_pZoomCursorSurface, v24, 32, 32, 1, 0, 0, v4, 0, 0, 0);
                  if ( inited != 0 )
                  {
                    WriteError(inited, "CreationZoomCursorSurface");
                    return 0;
                  }
                  else
                  {
                    if ( MEMORY[0x3E2E2B8] == 1 )
                    {
                      v23 = g_sColorKeyMagenta555;
                    }
                    else
                    {
                      v23 = g_sColorKeyMagenta565;
                    }
                    CFixCursor::SetSurfacePtr((CFixCursor *)&v34[1].m_sViewport.dwY, 0x74u, v34->m_pZoomCursorSurface, v23);
                    if ( MEMORY[0x3E2E2B8] == 1 )
                    {
                      v22 = &g_sColorKeyMagenta555;
                    }
                    else
                    {
                      v22 = &g_sColorKeyMagenta565;
                    }
                    v34->m_pZoomCursorSurface->SetColorKey(v34->m_pZoomCursorSurface, 8, v22);
                    v34->m_pMiniMapSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bUseDD3Interface);
                    if ( v34->m_pMiniMapSurface != 0 )
                    {
                      v21 = MEMORY[0x3E2E2B8] == 1;
                      if ( GfxEngineSetup.m_bUseDD3Interface )
                      {
                        v20 = v34->m_pDDraw;
                      }
                      else
                      {
                        v20 = v34->m_pDDraw7;
                      }
                      v5 = j__abs(v21);
                      inited = (HRESULT)v34->m_pMiniMapSurface->CreateSurface(v34->m_pMiniMapSurface, v20, 240, 160, 1, 0, 0, v5, 0, 0, 0);
                      if ( inited != 0 )
                      {
                        WriteError(inited, "CreateMiniMapSurface");
                        return 0;
                      }
                      else
                      {
                        v34->m_pMiniMapSurface->ClearSurface(v34->m_pMiniMapSurface, 0);
                        v34->m_pMiniMapSurface->SetColorKey(v34->m_pMiniMapSurface, 8, (int *)&g_sColorKeyBlack);
                        v34->m_pMiniMapAreaSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bUseDD3Interface);
                        if ( v34->m_pMiniMapAreaSurface != 0 )
                        {
                          v19 = MEMORY[0x3E2E2B8] == 1;
                          if ( GfxEngineSetup.m_bUseDD3Interface )
                          {
                            v18 = v34->m_pDDraw;
                          }
                          else
                          {
                            v18 = v34->m_pDDraw7;
                          }
                          v6 = j__abs(v19);
                          inited = (HRESULT)v34->m_pMiniMapAreaSurface->CreateSurface(v34->m_pMiniMapAreaSurface, v18, 240, 160, 1, 0, 0, v6, 0, 0, 0);
                          if ( inited != 0 )
                          {
                            WriteError(inited, "CreateMiniMapAreaSurface");
                            return 0;
                          }
                          else
                          {
                            inited = v34->m_pMiniMapAreaSurface->ClearSurface(v34->m_pMiniMapAreaSurface, 0);
                            if ( inited != 0 )
                            {
                              WriteError(inited, "ClearMiniMapSurface");
                            }
                            inited = ((int (__thiscall *)(CSurfaceV7 *, int, void *))v34->m_pMiniMapAreaSurface->SetColorKey)(v34->m_pMiniMapAreaSurface, 8, &g_sColorKeyBlack);
                            if ( inited != 0 )
                            {
                              WriteError(inited, "SetMiniMapColorKey");
                            }
                            BBSupportTracePrintF(1, "GFX ENGINE: Size of render surface: %d x %d", GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight);
                            v34->m_pLandscapeSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bUseDD3Interface);
                            if ( v34->m_pLandscapeSurface != 0 )
                            {
                              v17 = MEMORY[0x3E2E2B8] == 1;
                              if ( GfxEngineSetup.m_bUseDD3Interface )
                              {
                                v16 = v34->m_pDDraw;
                              }
                              else
                              {
                                v16 = v34->m_pDDraw7;
                              }
                              v10 = j__abs(v17);
                              IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
                              inited = (HRESULT)v34->m_pLandscapeSurface->CreateSurface(v34->m_pLandscapeSurface, v16, GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight, 1, IsHardwareLandscapeEngine, 0, v10, 0, 0, 0);
                              if ( inited != 0 )
                              {
                                WriteError(inited, "CreateLandscapeSurface");
                                return 0;
                              }
                              else
                              {
                                v34->m_pLandscapeSurface2 = v34->m_pLandscapeSurface;
                                v34->m_pFinalRenderSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bUseDD3Interface);
                                if ( v34->m_pFinalRenderSurface != 0 )
                                {
                                  v15 = MEMORY[0x3E2E2B8] == 1;
                                  if ( GfxEngineSetup.m_bUseDD3Interface )
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
                                  inited = (HRESULT)v34->m_pFinalRenderSurface->CreateSurface(v34->m_pFinalRenderSurface, v14, GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight, 1, v8, 0, v11, 0, v12, 0);
                                  if ( inited != 0 )
                                  {
                                    WriteError(inited, "CreateFinalRenderSurface");
                                    return 0;
                                  }
                                  else
                                  {
                                    inited = SurfaceClipper::InitClipper(&v34->m_sClipper1, v34->m_pDDraw);
                                    if ( inited != 0 )
                                    {
                                      WriteError(inited, "CreateClipper1");
                                      return 0;
                                    }
                                    else
                                    {
                                      inited = SurfaceClipper::InitClipper(&v34->m_sMinimapClipper, v34->m_pDDraw);
                                      if ( inited != 0 )
                                      {
                                        WriteError(inited, "Create Minimap Clipper");
                                        return 0;
                                      }
                                      else
                                      {
                                        inited = SurfaceClipper::SetClipWindow(&v34->m_sClipper1, GfxEngineSetup.m_hWnd);
                                        if ( inited != 0 )
                                        {
                                          WriteError(inited, "AssignClipper1");
                                          return 0;
                                        }
                                        else
                                        {
                                          Clipper = SurfaceClipper::GetClipper(&v34->m_sClipper1);
                                          inited = v34->m_pPrimarySurface->SetClipper(v34->m_pPrimarySurface, Clipper);
                                          if ( inited != 0 )
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
  IDirectDrawSurface7 *v8; // eax
  IDirectDrawSurface7 *v9; // [esp+ACh] [ebp-170h]
  IDirect3DDevice7 *m_pObjectDevice; // [esp+B0h] [ebp-16Ch]
  DWORD v11; // [esp+C0h] [ebp-15Ch] BYREF
  CCachePageManager *v13; // [esp+C8h] [ebp-154h]
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
  if ( this->m_bHardwareRuns != 0 || this->m_bSoftwareRuns != 0 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT HARDWARE: Engine is already initialized!");
    return 1;
  }
  CHeightAndTypeTable::InitShadeTables((CHeightAndTypeTable *)g_cHeightAndTypeTable);
  v30 = (void *)this->m_pDDraw7->lpVtbl->QueryInterface(this->m_pDDraw7, &IID_IDirect3D7, (LPVOID *)&this->m_pIDirect3D7);
  if ( v30 != nullptr )
  {
    WriteError((int)v30, "QueryD3DInterface");
    return 0;
  }
  CInterfaceD3D::AllocateEngineData(D3DObjectPtr, 256);
  v26 = 256;
  if ( D3DObjectPtr->m_bHiTextureQuality == 0 && SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup) != 0 )
  {
    v26 /= 2;
  }
  CInterfaceD3D::PreCalcTextureVertices(this, v26);
  for ( i = 0;
        i < 44;
        ++i )
  {
    this->m_pDDTextureSurfaces[i] = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if ( this->m_pDDTextureSurfaces[i] == nullptr )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
      return 0;
    }
    Number = GfxEngineSetup.iCurrentGfxMode == 1;
    if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
    {
      m_pDDraw = this->m_pDDraw;
    }
    else
    {
      m_pDDraw = this->m_pDDraw7;
    }
    v2 = j__abs(Number);
    v31 = (HRESULT)this->m_pDDTextureSurfaces[i]->CreateSurface(this->m_pDDTextureSurfaces[i], m_pDDraw, v26, v26, 1, 1, 1, v2, 0, 0, 0);
    if ( v31 != 0 )
    {
      WriteError(v31, "CreateLandscapeTextureSurface");
      return 0;
    }
  }
  if ( MEMORY[0x3E2E30E] != 0 )
  {
    for ( i = 0;
          i < 2;
          ++i )
    {
      this->m_pDDObjectSurfacePtr[i] = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
      if ( this->m_pDDObjectSurfacePtr[i] == nullptr )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
      }
      if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
      {
        m_pDDraw7 = this->m_pDDraw;
      }
      else
      {
        m_pDDraw7 = this->m_pDDraw7;
      }
      v31 = (HRESULT)this->m_pDDObjectSurfacePtr[i]->CreateSurface(this->m_pDDObjectSurfacePtr[i], m_pDDraw7, 512, 512, 1, 0, 1, 2, 0, 0, 0);
      if ( v31 != 0 )
      {
        WriteError(v31, "CreateObjectTextureSurface");
        return 0;
      }
    }
    for ( i = 0;
          i < 2;
          ++i )
    {
      this->m_pDDSourceObjectSurfacePtr[i] = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
      if ( this->m_pDDSourceObjectSurfacePtr[i] == nullptr )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
        return 0;
      }
      if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
      {
        v20 = this->m_pDDraw;
      }
      else
      {
        v20 = this->m_pDDraw7;
      }
      v31 = (HRESULT)this->m_pDDSourceObjectSurfacePtr[i]->CreateSurface(this->m_pDDSourceObjectSurfacePtr[i], v20, 512, 512, 0, 0, 1, 2, 0, 0, 0);
      if ( v31 != 0 )
      {
        WriteError(v31, "CreateObjectTextureSystemMemory");
        return 0;
      }
    }
  }
  v3 = this->m_pLandscapeSurface->GetSurfacePtr((CSurfaceV7 *)this->m_pLandscapeSurface);
  v31 = ((int (__stdcall *)(IDirect3D7 *, GUID *, IDirectDrawSurface7 *))this->m_pIDirect3D7->CreateDevice)(this->m_pIDirect3D7, &IID_IDirect3DHALDevice, v3);// Goes to null the device probably
  if ( v31 != 0 )
  {
    WriteError(v31, "CreateLandscapeRenderDevice");
    return 0;
  }
  v4 = this->m_pFinalRenderSurface->GetSurfacePtr((CSurfaceV7 *)this->m_pFinalRenderSurface);
  v31 = ((int (__stdcall *)(IDirect3D7 *, GUID *, IDirectDrawSurface7 *))this->m_pIDirect3D7->CreateDevice)(this->m_pIDirect3D7, &IID_IDirect3DHALDevice, v4);
  if ( v31 != 0 )
  {
    WriteError(v31, "CreateObjectRenderDevice");
    return 0;
  }
  this->m_sViewport.dwX = 0;
  this->m_sViewport.dwY = 0;
  this->m_sViewport.dwWidth = GfxEngineSetup.sRenderSetup.m_uWidth;
  this->m_sViewport.dwHeight = GfxEngineSetup.sRenderSetup.m_uHeight;
  this->m_sViewport.dvMinZ = 0.0;
  this->m_sViewport.dvMaxZ = 1.0;
  v31 = this->LandscapeDevice->SetViewport(this->LandscapeDevice, &this->m_sViewport);
  if ( v31 != 0 )
  {
    WriteError(v31, "SetLandscapeViewport");
    return 0;
  }
  v31 = this->m_pObjectDevice->SetViewport(this->m_pObjectDevice, &this->m_sViewport);
  if ( v31 != 0 )
  {
    WriteError(v31, "SetObjectViewport");
    return 0;
  }
  v5 = this->m_pDDTextureSurfaces[0]->GetSurfacePtr(this->m_pDDTextureSurfaces[0]);
  v31 = this->LandscapeDevice->SetTexture(this->LandscapeDevice, 0, v5);
  if ( v31 != 0 )
  {
    WriteError(v31, "SetDefaultLandscapeTexture");
    return 0;
  }
  v31 = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_CULLMODE, 1);
  if ( v31 != 0 )
  {
    WriteError(v31, "SetCulling");
    return 0;
  }
  v31 = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_TEXTUREPERSPECTIVE, 0);
  if ( v31 != 0 )
  {
    WriteError(v31, "SetTextureCorrecture");
    return 0;
  }
  v31 = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_ZENABLE, 0);
  if ( v31 != 0 )
  {
    WriteError(v31, "DisableZBuffer");
    return 0;
  }
  v31 = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_LOCALVIEWER, 0);
  if ( v31 != 0 )
  {
    WriteError(v31, "DisableCameraView");
    return 0;
  }
  v31 = this->LandscapeDevice->SetTextureStageState(this->LandscapeDevice, 0, D3DTSS_ADDRESS, 1);
  if ( v31 != 0 )
  {
    WriteError(v31, "SetTextureAdressMode");
    return 0;
  }
  v31 = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_SHADEMODE, 2);
  if ( v31 != 0 )
  {
    WriteError(v31, "SetLandscapeShading");
    return 0;
  }
  v31 = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_SPECULARENABLE, 1);
  if ( v31 != 0 )
  {
    WriteError(v31, "SetLandscapeLighting");
    return 0;
  }
  if ( MEMORY[0x3E2E30E] != 0 )
  {
    InitRenderStates();
    v6 = this->m_pDDObjectSurfacePtr[0]->GetSurfacePtr(this->m_pDDObjectSurfacePtr[0]);
    v31 = this->m_pObjectDevice->SetTexture(this->m_pObjectDevice, 0, v6);
    if ( v31 != 0 )
    {
      WriteError(v31, "SetDefaultObjectTexture");
      return 0;
    }
    v31 = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_SHADEMODE, 1);
    if ( v31 != 0 )
    {
      WriteError(v31, "SetObjectShading");
      return 0;
    }
    v31 = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_SPECULARENABLE, 0);
    if ( v31 != 0 )
    {
      WriteError(v31, "SetObjectLighting");
      return 0;
    }
    v31 = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_ALPHABLENDENABLE, 1);
    if ( v31 != 0 )
    {
      WriteError(v31, "EnableAlphaBlending");
      return 0;
    }
    v31 = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_SRCBLEND, 5);
    if ( v31 != 0 )
    {
      WriteError(v31, "SetSourceBlend");
      return 0;
    }
    v31 = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_DESTBLEND, 6);
    if ( v31 != 0 )
    {
      WriteError(v31, "SetDestBlend");
      return 0;
    }
    if ( SGfxRenderConfiguration::IsFiltering(&GfxEngineSetup.sRenderSetup) )
    {
      v19 = 2;
    }
    else
    {
      v19 = 1;
    }
    v31 = this->m_pObjectDevice->SetTextureStageState(this->m_pObjectDevice, 0, D3DTSS_MAGFILTER, v19);
    if ( v31 != 0 )
    {
      WriteError(v31, "SetObjectFiltering");
      return 0;
    }
    if ( SGfxRenderConfiguration::IsFiltering(&GfxEngineSetup.sRenderSetup) )
    {
      v18 = 2;
    }
    else
    {
      v18 = 1;
    }
    v31 = this->m_pObjectDevice->SetTextureStageState(this->m_pObjectDevice, 0, D3DTSS_MINFILTER, v18);
    if ( v31 != 0 )
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
  if ( MEMORY[0x3E2E30E] != 0 )
  {
    for ( i = 0;
          i < 2;
          ++i )
    {
      C = operator new(0x9A4u);
      exceptionBlock = 0;
      if ( C != nullptr )
      {
        m_pObjectDevice = this->m_pObjectDevice;
        v9 = this->m_pDDSourceObjectSurfacePtr[i]->GetSurfacePtr(this->m_pDDSourceObjectSurfacePtr[i]);
        v8 = this->m_pDDObjectSurfacePtr[i]->GetSurfacePtr(this->m_pDDObjectSurfacePtr[i]);
        v16 = (CCachePageManager *)CUploadCachePageManager::CUploadCachePageManager((CUploadCachePageManager *)C, v8, v9, m_pObjectDevice);
      }
      else
      {
        v16 = nullptr;
      }
      exceptionBlock = -1;
      this->m_pcPictureManager[i] = v16;
      if ( this->m_pcPictureManager[i] == nullptr )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: No memory to create PictureManager");
        return 0;
      }
    }
    CCachePageManager::SetCurrentZoomFactor(this->m_pcPictureManager[0], GfxEngineSetup.fZoomFactor);
    memset(&v34, 0, sizeof(v34));
    v34.dwCaps = 4096;
    v27 = this->m_pDDraw7->lpVtbl->GetAvailableVidMem(this->m_pDDraw7, &v34, &v11, (LPDWORD)&uAvailableVidMemory);
    if ( v27 != 0 )
    {
      WriteError(v27, "GetVideoMemory");
      return 0;
    }
    v25 = uAvailableVidMemory;
    BBSupportTracePrintF(1, "GFX ENGINE: Available vid mem for cache is %d", uAvailableVidMemory);
    v25 -= 1100000;
    v25 -= 50000;
    this->m_iNumberOfCachedSurfaces = 0;
    if ( v25 > 0 )
    {
      CSurfaceDescription::CSurfaceDescription((CSurfaceDescription *)&v33);
      v33.dwFlags = 4103;
      v33.ddsCaps.dwCaps = 20480;
      v33.dwWidth = 512;
      v33.dwHeight = 512;
      *(_QWORD *)&v33.ddpfPixelFormat.dwFlags = 65;
      *(_QWORD *)&v33.ddpfPixelFormat.dwRGBBitCount = 0xF0000000010LL;
      *(_QWORD *)&v33.ddpfPixelFormat.dwGBitMask = 0xF000000F0LL;
      v33.ddpfPixelFormat.dwRGBAlphaBitMask = 61440;
      v15 = uAvailableVidMemory != 1674288;
      v28 = uAvailableVidMemory != 1674288;
      for ( this->m_iNumberOfCachedSurfaces = j__abs(v15);
            v28 && this->m_iNumberOfCachedSurfaces < 180;
            ++this->m_iNumberOfCachedSurfaces )
      {
        v27 = this->m_pDDraw7->lpVtbl->CreateSurface(this->m_pDDraw7, &v33, &this->m_pCacheSurfaces[this->m_iNumberOfCachedSurfaces], nullptr);
        v28 = true;
        if ( v27 != 0 )
        {
          if ( v27 == DDERR_OUTOFVIDEOMEMORY )
          {
            BBSupportTracePrintF(1, "GFX ENGINE: %d cache surfaces created. Running out of video mem!", this->m_iNumberOfCachedSurfaces);
            break;
          }
          WriteError(v27, "CreateCacheSurfaces");
          return 0;
        }
        v27 = this->m_pDDraw7->lpVtbl->GetAvailableVidMem(this->m_pDDraw7, &v34, &v11, (LPDWORD)&uAvailableVidMemory);
        if ( v27 != 0 )
        {
          WriteError(v27, "GetVideoMemory");
          return 0;
        }
        if ( uAvailableVidMemory == 1674288 )
        {
          v28 = false;
        }
        v14 = (CCachePageManager *)operator new(0x824u);
        exceptionBlock = 1;
        if ( v14 != nullptr )
        {
          v13 = CCachePageManager::CCachePageManager(v14, this->m_pCacheSurfaces[this->m_iNumberOfCachedSurfaces], nullptr, this->m_pObjectDevice);
        }
        else
        {
          v13 = nullptr;
        }
        exceptionBlock = -1;
        this->m_pCacheManagers[this->m_iNumberOfCachedSurfaces] = v13;
        if ( this->m_pCacheManagers[this->m_iNumberOfCachedSurfaces] == nullptr )
        {
          BBSupportTracePrintF(1, "GFX ENGINE: Out of memory while creating CacheManager");
          return 0;
        }
      }
    }
    g_iZoomGradient = GfxEngineSetup.iVertexSize / 24;
    g_iZoomInit = -65536;
    if ( D3DObjectPtr->m_pcPictureManager[0] != nullptr )
    {
      CCachePageManager::SetCurrentZoomFactor(D3DObjectPtr->m_pcPictureManager[0], GfxEngineSetup.fZoomFactor);
    }
  }
  D3DObjectPtr->m_bHardwareRuns = 1;
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
  if ( this->m_bHardwareRuns != 0 || this->m_bSoftwareRuns != 0 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT SOFTWARE: Engine is already initialized!");
    return 1;
  }
  else
  {
    if ( MEMORY[0x3E2E2B8] == 1 )
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
    if ( g_pSoftwareTexturePages != 0 )
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
        ((void (__thiscall *)(CColorGradient *, int, int, int, int, int))CColorGradient::SetupGradients)(&g_cColorGradient, j, g_cColorGradient.m_vPlayerColors[j + 1].m_iR, g_cColorGradient.m_vPlayerColors[j + 1].m_iG, g_cColorGradient.m_vPlayerColors[j + 1].m_iB, GradientFormat);
      }
      CInterfaceD3D::PreCalcTextureVertices(this, 256);
      g_pfBlitSettler = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitSettler;
      g_pfBlitObject = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitObject;
      g_pfBlitVehicle = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitVehicle;
      g_pfBlitBuilding = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))BlitBuilding;
      g_pfBlitBorderstone = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitBorderstone;
      g_pfBlitAccessoryIcon = (int (__cdecl *)(_DWORD, _DWORD, _DWORD, _DWORD))BlitAccessoryIcon;
      g_pfBlitWave = BlitWave;
      this->m_bSoftwareRuns = 1;
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
  v6 = (*(int (__thiscall **)(_DWORD, HDC *))(**(this + 25) + 40))(*(this + 25), &hdcSrc);
  if ( v6 == -2005532222 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 1)");
    return 0;
  }
  else
  {
    if ( v6 != 0 )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 2)");
    }
    hdc = GetDC(hWnd);
    CompatibleDC = CreateCompatibleDC(hdc);
    SelectObject(CompatibleDC, h);
    if ( !BitBlt(CompatibleDC, 0, 0, GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight, hdcSrc, 0, 0, (DWORD)&dword_C20408[163590]) )
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
    if ( this->m_pDDGuiSurfaces[0] != 0 && this->m_pPrimarySurface != 0 )
    {
      v11.left = GfxEngineSetup.m_uX;
      v11.top = GfxEngineSetup.m_uY;
      v11.right = GfxEngineSetup.m_uWidth + GfxEngineSetup.m_uX;
      v11.bottom = GfxEngineSetup.m_uHeight + GfxEngineSetup.m_uY;
      BlitStructPtr = CBlitFX::GetBlitStructPtr((CBlitFX *)&g_cBlitFX);
      v6 = this->m_pPrimarySurface->Blt(this->m_pPrimarySurface, &v11, this->m_pDDGuiSurfaces[0], 0, 512, (struct _DDBLTFX *)BlitStructPtr);
    }
    if ( MEMORY[0x3E2E301] != 0 && this->m_pMiniMapAreaSurface != 0 && this->m_pPrimarySurface != 0 )
    {
      v7 = -1;
      v16 = g_sMiniMapRect;
      v17 = MEMORY[0x4689B90];
      v18 = MEMORY[0x4689B94];
      v19 = MEMORY[0x4689B98];
      v12 = g_sMiniMapSize;
      v13 = dword_3E2E240;
      v14 = dword_3E2E244;
      v15 = dword_3E2E248;
      D3DObjectPtr->m_pPrimarySurface->GetSurfaceSize(D3DObjectPtr->m_pPrimarySurface, &surfaceWidth, &surfaceHeight);
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
        if ( v7 != 0 )
        {
          WriteError(v7, "SetClipper2");
          return 0;
        }
        v7 = D3DObjectPtr->m_pPrimarySurface->Blt(D3DObjectPtr->m_pPrimarySurface, (struct tagRECT *)&v16, D3DObjectPtr->m_pMiniMapSurface, (struct tagRECT *)&v12, 0x8000, 0);
        if ( v7 == 0 )
        {
          v7 = D3DObjectPtr->m_pPrimarySurface->Blt(D3DObjectPtr->m_pPrimarySurface, (struct tagRECT *)&v16, D3DObjectPtr->m_pMiniMapAreaSurface, (struct tagRECT *)&v12, 0x8000, 0);
        }
      }
      v7 = CInterfaceD3D::ClearCustomClipper(this);
      if ( v7 != 0 )
      {
        WriteError(v7, "SetClipper1");
        return 0;
      }
    }
  }
  else if ( this->m_pFinalRenderSurface != 0 && this->m_pPrimarySurface != 0 )
  {
    v10.left = GfxEngineSetup.m_uX;
    v10.top = GfxEngineSetup.m_uY;
    v10.right = GfxEngineSetup.m_uWidth + GfxEngineSetup.m_uX;
    v10.bottom = GfxEngineSetup.m_uHeight + GfxEngineSetup.m_uY;
    v3 = CBlitFX::GetBlitStructPtr((CBlitFX *)&g_cBlitFX);
    v6 = this->m_pPrimarySurface->Blt(this->m_pPrimarySurface, &v10, this->m_pFinalRenderSurface, 0, 512, (struct _DDBLTFX *)v3);
  }
  switch ( v6 )
  {
    case 0:
      return 1;
    case -2005532222:
      v6 = this->m_pPrimarySurface->Restore(this->m_pPrimarySurface);
      if ( v6 != 0 )
      {
        WriteError(v6, "RestorePrimarySurface");
      }
      if ( v6 == -2005532085 )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: Stop rendering because of inaccessability of primary surface!");
        *((_BYTE *)this + 1856) = 1;
      }
      break;
    case -2005532447:
      WriteError(-2005532447, "Exclusive mode down! Stop rendering...");
      *((_BYTE *)this + 1856) = 1;
      break;
    default:
      WriteError(v6, "PrimarySurfaceBlit");
      break;
  }
  return 0;
}


// address=[0x2f66d00]
// Decompiled from BOOL __stdcall CInterfaceD3D::BlitDIBToSurface(HWND _hWnd, int _uWidth, int _uHeight, IDirectDrawSurface4 *_pDDSurface)
void  CInterfaceD3D::BlitDIBToSurface(struct HWND__ * _hWnd, int _uWidth, int _uHeight, struct IDirectDrawSurface4 * _pDDSurface) {
  
  HDC hdc; // [esp+8h] [ebp-Ch]
  HDC v6; // [esp+Ch] [ebp-8h] BYREF
  HDC hdcSrc; // [esp+10h] [ebp-4h]

  _pDDSurface->lpVtbl->GetDC(_pDDSurface, &v6);
  hdc = GetDC(_hWnd);
  hdcSrc = CreateCompatibleDC(hdc);
  SelectObject(hdcSrc, GfxEngineSetup.hOutputBitmap);
  if ( !BitBlt(v6, 0, 0, _uWidth, _uHeight, hdcSrc, 0, 0, SRCCOPY) )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Blit to Surface failed!");
  }
  _pDDSurface->lpVtbl->ReleaseDC(_pDDSurface, v6);
  ReleaseDC(_hWnd, hdc);
  return DeleteDC(hdcSrc);
}


// address=[0x2f66dc0]
// Decompiled from int __thiscall CInterfaceD3D::GetGradientFormat(CInterfaceD3D *this)
int  CInterfaceD3D::GetGradientFormat(void) {
  
  if ( this->m_bHardwareRuns )
  {
    return 2;
  }
  else
  {
    return MEMORY[0x3E2E2B8] == 1;
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
    D3DObjectPtr->m_bAvailableResolutions[0] = 1;
    return 1;
  }
  else if ( a1->dwWidth == 800 && a1->dwHeight == 600 )
  {
    D3DObjectPtr->m_bAvailableResolutions[1] = 1;
    return 1;
  }
  else if ( a1->dwWidth == 1024 && a1->dwHeight == 768 )
  {
    D3DObjectPtr->m_bAvailableResolutions[2] = 1;
    return 1;
  }
  else if ( a1->dwWidth == 1280 && a1->dwHeight == 1024 )
  {
    D3DObjectPtr->m_bAvailableResolutions[3] = 1;
    return 1;
  }
  else if ( a1->dwWidth == 1600 && a1->dwHeight == 1200 )
  {
    D3DObjectPtr->m_bAvailableResolutions[4] = 1;
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
    D3DObjectPtr->m_bAvailableResolutions[0] = 1;
    return 1;
  }
  else if ( a1[3] == 800 && a1[2] == 600 )
  {
    D3DObjectPtr->m_bAvailableResolutions[1] = 1;
    return 1;
  }
  else if ( a1[3] == 1024 && a1[2] == 768 )
  {
    D3DObjectPtr->m_bAvailableResolutions[2] = 1;
    return 1;
  }
  else if ( a1[3] == 1280 && a1[2] == 1024 )
  {
    D3DObjectPtr->m_bAvailableResolutions[3] = 1;
    return 1;
  }
  else if ( a1[3] == 1600 && a1[2] == 1200 )
  {
    D3DObjectPtr->m_bAvailableResolutions[4] = 1;
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
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup) == 0 )
  {
    BYTE1(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
  }
  if ( D3DObjectPtr != 0 )
  {
    v4 = MEMORY[0x3E2E2B8] == 1;
    IsHQTextureSet = BYTE1(D3DObjectPtr[1].m_sClipper1.m_vChar.u8);
    IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
    if ( !ReadTextureBitmapSet(IsHardwareLandscapeEngine, IsHQTextureSet, v4, 44) )
    {
      BBSupportTracePrintF(0, "GFX ENGINE: Error while loading texture set!");
      return 0;
    }
    if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup) == 0 )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Begin set up luminance tables.");
      for ( i = 0;
            i < 44;
            ++i )
      {
        j__TRI_calculate_LUT_from_palette((int)&g_uColorPalettes + 768 * i, g_pLuminanceTablesStart + (i << 11));
      }
      BBSupportTracePrintF(1, "GFX ENGINE: End set up luminance tables.");
    }
  }
  return 1;
}


// address=[0x2f67190]
// Decompiled from void __thiscall CInterfaceD3D::SetupViewport(CInterfaceD3D *this, DWORD a2, DWORD a3, DWORD a4, DWORD a5)
void  CInterfaceD3D::SetupViewport(int a2, int a3, int a4, int a5) {
  
  HRESULT v5; // [esp+0h] [ebp-8h]
  int v6; // [esp+0h] [ebp-8h]

  this->m_sViewport.dwX = a2;
  this->m_sViewport.dwY = a3;
  this->m_sViewport.dwWidth = a4;
  this->m_sViewport.dwHeight = a5;
  if ( this->LandscapeDevice != 0 )
  {
    v5 = this->LandscapeDevice->SetViewport(this->LandscapeDevice, &this->m_sViewport);
    if ( v5 != 0 )
    {
      WriteError(v5, "SetLandscapeViewport");
    }
    else if ( this->m_pObjectDevice != 0 )
    {
      v6 = this->m_pObjectDevice->SetViewport(this->m_pObjectDevice, &this->m_sViewport);
      if ( v6 != 0 )
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

  if ( (struct IDirectDrawClipper *)SurfaceClipper::GetClipper(a2) == 0 )
  {
    j___wassert(L"clipper.GetClipper() != nullptr", L"MainGfxManager.cpp", 0x90Fu);
  }
  Clipper = (struct IDirectDrawClipper *)SurfaceClipper::GetClipper(a2);
  return this->m_pFinalRenderSurface->SetClipper(this->m_pFinalRenderSurface, (int)Clipper);
}


// address=[0x2f672a0]
// Decompiled from int __thiscall CInterfaceD3D::ClearCustomClipper(CInterfaceD3D *this)
long  CInterfaceD3D::ClearCustomClipper(void) {
  
  struct IDirectDrawClipper *Clipper; // eax

  Clipper = (struct IDirectDrawClipper *)SurfaceClipper::GetClipper(&this->m_sClipper1);
  return this->m_pFinalRenderSurface->SetClipper(this->m_pFinalRenderSurface, (int)Clipper);
}


// address=[0x2f672d0]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::DeleteEngineData(CInterfaceD3D *this)
void  CInterfaceD3D::DeleteEngineData(void) {
  
  CInterfaceD3D *result; // eax

  result = this;
  if ( this->D3DVertexPtr != 0 )
  {
    result = (CInterfaceD3D *)operator delete[]((void *)this->D3DVertexPtr);
    this->D3DVertexPtr = 0;
    g_pVertexMax = 0;
    g_pVertex = 0;
  }
  if ( g_pLuminanceTablesMemory != 0 )
  {
    result = (CInterfaceD3D *)operator delete[]((void *)g_pLuminanceTablesMemory);
    g_pLuminanceTablesMemory = 0;
    g_pLuminanceTablesStart = 0;
  }
  return result;
}


// address=[0x2f67350]
// Decompiled from int __thiscall CInterfaceD3D::BeginLandscapeScene(CInterfaceD3D *this)
long  CInterfaceD3D::BeginLandscapeScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = -1;
  if ( *((_DWORD *)this + 460) != 0 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 0", *((_DWORD *)this + 460));
  }
  else
  {
    v2 = this->LandscapeDevice->BeginScene(this->LandscapeDevice);
    if ( v2 != 0 )
    {
      WriteError(v2, "BeginLandscapeScene");
    }
    ++*((_DWORD *)this + 460);
  }
  return v2;
}


// address=[0x2f673e0]
// Decompiled from int __thiscall CInterfaceD3D::EndLandscapeScene(CInterfaceD3D *this)
long  CInterfaceD3D::EndLandscapeScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  if ( *((int *)this + 460) > 1 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 1", *((_DWORD *)this + 460));
  }
  v2 = this->LandscapeDevice->EndScene(this->LandscapeDevice);
  if ( v2 != 0 )
  {
    WriteError(v2, "EndLandscapeScene");
  }
  --*((_DWORD *)this + 460);
  return v2;
}


// address=[0x2f67460]
// Decompiled from int __thiscall CInterfaceD3D::BeginObjectScene(CInterfaceD3D *this)
long  CInterfaceD3D::BeginObjectScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = -1;
  if ( *((_DWORD *)this + 459) != 0 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: ObjectScene Lockcounter is %d instead of 0", *((_DWORD *)this + 459));
  }
  else
  {
    v2 = this->m_pObjectDevice->BeginScene(this->m_pObjectDevice);
    if ( v2 != 0 )
    {
      WriteError(v2, "BeginObjectScene");
    }
    ++*((_DWORD *)this + 459);
  }
  return v2;
}


// address=[0x2f674f0]
// Decompiled from int __thiscall CInterfaceD3D::EndObjectScene(CInterfaceD3D *this)
long  CInterfaceD3D::EndObjectScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  if ( *((int *)this + 459) > 1 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 1", *((_DWORD *)this + 459));
  }
  v2 = this->m_pObjectDevice->EndScene(this->m_pObjectDevice);
  if ( v2 != 0 )
  {
    WriteError(v2, "EndObjectScene");
  }
  --*((_DWORD *)this + 459);
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
  this->m_pCameraWindowSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bUseDD3Interface);
  if ( this->m_pCameraWindowSurface != 0 )
  {
    if ( GfxEngineSetup.m_bUseDD3Interface )
    {
      m_pDDraw = this->m_pDDraw;
    }
    else
    {
      m_pDDraw = this->m_pDDraw7;
    }
    v5 = j__abs(MEMORY[0x3E2E2B8] == 1);
    IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
    v6 = this->m_pCameraWindowSurface->CreateSurface(this->m_pCameraWindowSurface, m_pDDraw, a2, a3, 1, IsHardwareLandscapeEngine, 0, v5, 0, 0, 0);
    if ( v6 != 0 )
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
  if ( this->m_pCameraWindowSurface != 0 )
  {
    if ( this->m_pLandscapeSurface2 == this->m_pCameraWindowSurface )
    {
      j___wassert(L"m_pCurrentLandScapeRenderTarget != m_pLandscapeCameraRenderSurface", L"MainGfxManager.cpp", 0x9D2u);
    }
    ((void (__thiscall *)(CSurface *))this->m_pCameraWindowSurface->Release)(this->m_pCameraWindowSurface);
    result = (CInterfaceD3D *)this->m_pCameraWindowSurface;
    if ( result != 0 )
    {
      result = (CInterfaceD3D *)((int (__thiscall *)(CSurface *, int))this->m_pCameraWindowSurface->dtor)(this->m_pCameraWindowSurface, 1);
    }
    this->m_pCameraWindowSurface = 0;
  }
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
    LandscapeSurface = this->m_pLandscapeSurface;
  }
  if ( LandscapeSurface == 0 )
  {
    j___wassert(L"renderTarget != nullptr", L"MainGfxManager.cpp", 0x9DDu);
  }
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup) != 0 )
  {
    v3 = ((int (__thiscall *)(CSurfaceV7 *, IDirect3DDevice7 *))LandscapeSurface->j_?SetAsRenderTarget@CSurfaceV7@@UAEJPAUIDirect3DDevice7@@@Z)(LandscapeSurface, this->LandscapeDevice);
    if ( v3 < 0 )
    {
      return v3;
    }
  }
  this->m_pLandscapeSurface2 = LandscapeSurface;
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
    this->m_pDDTextureSurfaces[j] = 0;
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
  result = (unsigned __int8)SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
  if ( (_BYTE)result == 0 )
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
        sub_2F7BC20((int)v7, COERCE_INT((float)j), COERCE_INT((float)i), k);
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
// Decompiled from void __thiscall CInterfaceD3D::CalcTilingVerticesType1(CInterfaceD3D *this, int _LandscapeType)
void  CInterfaceD3D::CalcTilingVerticesType1(int _LandscapeType) {
  
  float fPatternSuboffsetX; // [esp+4h] [ebp-4h]

  CInterfaceD3D::ChangeCurrentTexturePage(this, s_iDarkTribeElement + TEXTURE_PAGE_MAP[_LandscapeType]);
  fPatternSuboffsetX = g_fPatternSuboffsetX;
  if ( (float)(g_fPatternSuboffsetX + 0.125) <= 1.0 )
  {
    g_pVertex->tu = g_fPatternSuboffsetX + 0.125;
  }
  else if ( g_bHalfLine != 0 )
  {
    g_pVertex->tu = flt_3E2E708 + 1.0;
    g_bSplitTriangle = 1;
  }
  else
  {
    g_pVertex->tu = g_fPatternSuboffsetX + 0.125;
  }
  g_pVertex->tv = g_fPatternSuboffsetY + 0.125;
  ++g_pVertex;
  g_pVertex->tu = fPatternSuboffsetX;
  g_pVertex->tv = g_fPatternSuboffsetY + 0.125;
  ++g_pVertex;
  g_pVertex->tu = fPatternSuboffsetX + 0.0625;
  g_pVertex->tv = g_fPatternSuboffsetY;
  g_pVertex -= 2;
}


// address=[0x2f823f0]
// Decompiled from _D3DTLVERTEX *__thiscall CInterfaceD3D::CalcTilingVerticesType2(CInterfaceD3D *this, int _LandscapeType)
void  CInterfaceD3D::CalcTilingVerticesType2(int _LandscapeType) {
  
  _D3DTLVERTEX *result; // eax
  float v3; // [esp+4h] [ebp-8h]
  float v4; // [esp+8h] [ebp-4h]

  CInterfaceD3D::ChangeCurrentTexturePage(this, s_iDarkTribeElement + TEXTURE_PAGE_MAP[_LandscapeType]);
  v4 = g_fPatternSuboffsetX + 0.1875;
  v3 = g_fPatternSuboffsetX;
  if ( (float)(g_fPatternSuboffsetX + 0.1875) > 1.0 )
  {
    if ( g_bHalfLine != 0 )
    {
      v4 = v4 - 1.0;
      v3 = g_fPatternSuboffsetX - 1.0;
    }
    else
    {
      v4 = flt_3E2E708 + 1.0;
      g_bSplitTriangle = 1;
    }
  }
  g_pVertex->tu = v4;
  g_pVertex->tv = g_fPatternSuboffsetY;
  ++g_pVertex;
  g_pVertex->tu = v3 + 0.125;
  g_pVertex->tv = g_fPatternSuboffsetY + 0.125;
  result = ++g_pVertex;
  g_pVertex->tu = v3 + 0.0625;
  g_pVertex->tv = g_fPatternSuboffsetY;
  g_pVertex -= 2;
  return result;
}


// address=[0x2f82540]
// Decompiled from int __thiscall CInterfaceD3D::AllocateEngineData(CInterfaceD3D *this, signed int a2)
int  CInterfaceD3D::AllocateEngineData(int a2) {
  
  void *v3; // [esp+10h] [ebp-20h]
  void *v4; // [esp+18h] [ebp-18h]
  signed int i; // [esp+1Ch] [ebp-14h]

  if ( this->D3DVertexPtr != 0 )
  {
    CInterfaceD3D::DeleteEngineData(this);
  }
  v4 = operator new[](32 * a2);
  if ( v4 != 0 )
  {
    _vec_ctor_no(v4, 0x20u, a2, (void *(__thiscall *)(void *))_D3DTLVERTEX::_D3DTLVERTEX);
    v3 = v4;
  }
  else
  {
    v3 = 0;
  }
  this->D3DVertexPtr = v3;
  if ( this->D3DVertexPtr == 0 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: Not enough memory to allocate vertices");
    return 0;
  }
  for ( i = 0;
        i < a2;
        ++i )
  {
    *(float *)(this->D3DVertexPtr + 32 * i + 8) = FLOAT_0_89999998;
    *(float *)(this->D3DVertexPtr + 32 * i + 12) = FLOAT_0_5;
  }
  if ( this->D3DVertexPtr != 0 )
  {
    g_pVertexMax = this->D3DVertexPtr + 7680;
  }
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup) == 0 )
  {
    g_pLuminanceTablesMemory = (int)operator new[](0x16800u);
    if ( g_pLuminanceTablesMemory == 0 )
    {
      BBSupportTracePrintF(0, "GFX ENGINE: Not enough memory to allocate luminance tables!");
      g_pLuminanceTablesStart = 0;
      return 0;
    }
    g_pLuminanceTablesStart = (g_pLuminanceTablesMemory + 2047) & 0xFFFFF800;
  }
  return 1;
}


// address=[0x2f85f40]
// Decompiled from void __thiscall CInterfaceD3D::ChangeCurrentTexturePage(CInterfaceD3D *this, int a2)
void  CInterfaceD3D::ChangeCurrentTexturePage(int a2) {
  
  struct IDirectDrawSurface7 *v2; // eax

  if ( a2 != g_iLastUsedPage )
  {
    CInterfaceD3D::RenderScene(this, byte_4696877);
    g_iLastUsedPage = a2;
    if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup) != 0 )
    {
      v2 = this->m_pDDTextureSurfaces[g_iLastUsedPage]->GetSurfacePtr(this->m_pDDTextureSurfaces[g_iLastUsedPage]);
      this->LandscapeDevice->SetTexture(this->LandscapeDevice, 0, v2);
    }
    else
    {
      CurrentTexturePagePtr = g_pTextureTable[g_iLastUsedPage];
      j__TRI_palette_LUT = g_pLuminanceTablesStart + (g_iLastUsedPage << 11);
    }
  }
}


// address=[0x2f860c0]
// Decompiled from CSurfaceV7 *__thiscall CInterfaceD3D::GetLandscapeRenderTargetSurface(CInterfaceD3D *this)
class CSurface *  CInterfaceD3D::GetLandscapeRenderTargetSurface(void) {
  
  return this->m_pLandscapeSurface2;
}


// address=[0x2f86180]
// Decompiled from void __thiscall CInterfaceD3D::RenderScene(CInterfaceD3D *this, bool a2)
void  CInterfaceD3D::RenderScene(bool a2) {
  
  int v2; // [esp+0h] [ebp-10h]
  _D3DTLVERTEX *pVertex; // [esp+4h] [ebp-Ch]
  _D3DTLVERTEX *i; // [esp+Ch] [ebp-4h]

  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup) != 0 )
  {
    if ( g_pVertex - this->D3DVertexPtr > 0 )
    {
      if ( a2 )
      {
        for ( i = this->D3DVertexPtr;
              i < g_pVertex;
              i += 3 )
        {
          i->sx = (float)GfxEngineSetup.iCamFollowX + i->sx;
          i->sy = (float)GfxEngineSetup.iCamFollowY + i->sy;
          i[1].sx = (float)GfxEngineSetup.iCamFollowX + i[1].sx;
          i[1].sy = (float)GfxEngineSetup.iCamFollowY + i[1].sy;
          i[2].sx = (float)GfxEngineSetup.iCamFollowX + i[2].sx;
          i[2].sy = (float)GfxEngineSetup.iCamFollowY + i[2].sy;
        }
      }
      v2 = this->LandscapeDevice->DrawPrimitive(this->LandscapeDevice, D3DPT_TRIANGLELIST, D3DFVF_TLVERTEX, this->D3DVertexPtr, g_pVertex - this->D3DVertexPtr, 0);
      if ( v2 != 0 )
      {
        WriteError(v2, "DrawPrimitive");
        g_bRenderSuccess = 0;
      }
    }
  }
  else
  {
    for ( pVertex = this->D3DVertexPtr;
          pVertex < g_pVertex;
          pVertex += 3 )
    {
      j__TRI_draw_triangle(pVertex, pVertex + 1, pVertex + 2, CurrentTexturePagePtr, 8);
    }
  }
  g_pVertex = this->D3DVertexPtr;
}


// address=[0x2f8a910]
// Decompiled from int __thiscall CInterfaceD3D::IsInterface7Available(CInterfaceD3D *this, bool *_rSuccess, HWND a3)
int  CInterfaceD3D::IsInterface7Available(bool & _rSuccess, struct HWND__ * a3) {
  
  int v4; // eax
  int v5; // eax
  int v6; // [esp+10h] [ebp-2A8h]
  int v7; // [esp+14h] [ebp-2A4h] BYREF
  int v8; // [esp+18h] [ebp-2A0h] BYREF
  HRESULT (__stdcall *DirectDrawCreateEx)(GUID *, LPVOID *, const IID *const, IUnknown *); // [esp+1Ch] [ebp-29Ch] MAPDST
  BOOL v10; // [esp+20h] [ebp-298h]
  int v11; // [esp+24h] [ebp-294h] BYREF
  IDirectDraw7 *m_pDDraw; // [esp+28h] [ebp-290h]
  HMODULE hModule; // [esp+30h] [ebp-288h]
  CSurface *m_pTmpSurface; // [esp+34h] [ebp-284h]
  CSurface *m_pPrimarySurface; // [esp+38h] [ebp-280h]
  STextureFormats vPixelFormats; // [esp+3Ch] [ebp-27Ch] BYREF
  unsigned __int8 v18; // [esp+43h] [ebp-275h] BYREF
  HRESULT hResult; // [esp+44h] [ebp-274h]
  DDCAPS v21; // [esp+4Ch] [ebp-26Ch] BYREF
  D3DDEVICEDESC7 sHardwareCapabilitys; // [esp+1C8h] [ebp-F0h] BYREF

  *_rSuccess = false;
  byte_46C7938 = 0;
  if ( g_pDirectDraw != nullptr )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: DirectDraw already loaded");
    return 3;
  }
  else
  {
    hModule = GetModuleHandleA("DDRAW");
    if ( hModule == nullptr )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Direct Draw is not accessible!");
      return 1;
    }
    else
    {
      DirectDrawCreateEx = (HRESULT (__stdcall *)(GUID *, LPVOID *, const IID *const, IUnknown *))GetProcAddress(hModule, "DirectDrawCreateEx");
      if ( DirectDrawCreateEx == nullptr )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: DirectDrawCreateEx not found! Interface 7 or higher not available!");
        return 2;
      }
      else
      {
        hResult = DirectDrawCreateEx(nullptr, (LPVOID *)&this->m_pDDraw, &IID_IDirectDraw7, nullptr);
        if ( hResult != 0 )
        {
          WriteError(hResult, "CreateDirectDrawObject");
          return 3;
        }
        else
        {
          g_pDirectDraw = this->m_pDDraw;
          hResult = this->m_pDDraw->lpVtbl->QueryInterface(this->m_pDDraw, &IID_IDirectDraw7, (LPVOID *)&this->m_pDDraw7);
          if ( hResult != 0 )
          {
            CInterfaceD3D::CleanUpCheckObjects(this);
            WriteError(hResult, "QueryInterface");
            return 4;
          }
          else
          {
            hResult = this->m_pDDraw7->lpVtbl->GetDeviceIdentifier(this->m_pDDraw7, &s_sDeviceIdentifier, 1);
            if ( hResult == 0 )
            {
              BBSupportTracePrintF(1, "GFX ENGINE: ---------------GfxAdapter Info---------------");
              BBSupportTracePrintF(1, "GFX ENGINE: ");
              BBSupportTracePrintF(1, "GFX ENGINE: Driver          : %s", s_sDeviceIdentifier.szDriver);
              BBSupportTracePrintF(1, "GFX ENGINE: Description     : %s", s_sDeviceIdentifier.szDescription);
              BBSupportTracePrintF(1, "GFX ENGINE: DriverVersion   : %d", s_sDeviceIdentifier.liDriverVersion.LowPart);
              BBSupportTracePrintF(1, "GFX ENGINE: Manufactorer    : %d", s_sDeviceIdentifier.dwVendorId);
              BBSupportTracePrintF(1, "GFX ENGINE: Chipset         : %d", s_sDeviceIdentifier.dwDeviceId);
              BBSupportTracePrintF(1, "GFX ENGINE: ChipsetRevision : %d", s_sDeviceIdentifier.dwRevision);
              BBSupportTracePrintF(1, "GFX ENGINE: BoardRevision   : %d", s_sDeviceIdentifier.dwSubSysId);
              BBSupportTracePrintF(1, "GFX ENGINE: Certification   : %d", s_sDeviceIdentifier.dwWHQLLevel);
              BBSupportTracePrintF(1, "GFX ENGINE: ");
              BBSupportTracePrintF(1, "GFX ENGINE: ---------------------------------------------");
              byte_46C7938 = 1;
            }
            hResult = this->m_pDDraw7->lpVtbl->SetCooperativeLevel(this->m_pDDraw7, a3, 8);
            if ( hResult != 0 )
            {
              CInterfaceD3D::CleanUpCheckObjects(this);
              WriteError(hResult, "SetCooperativeLevel");
              return 5;
            }
            else
            {
              hResult = this->m_pDDraw7->lpVtbl->QueryInterface(this->m_pDDraw7, &IID_IDirect3D7, (LPVOID *)&this->m_pIDirect3D7);
              if ( hResult != 0 )
              {
                CInterfaceD3D::CleanUpCheckObjects(this);
                WriteError(hResult, "QueryD3DInterface");
                return 6;
              }
              else
              {
                this->m_pPrimarySurface = CSurface::CreateSurfacePtr(false);
                if ( this->m_pPrimarySurface == nullptr )
                {
                  CInterfaceD3D::CleanUpCheckObjects(this);
                  BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                  return 7;
                }
                else
                {
                  if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
                  {
                    m_pDDraw = this->m_pDDraw;
                  }
                  else
                  {
                    m_pDDraw = this->m_pDDraw7;
                  }
                  hResult = (HRESULT)this->m_pPrimarySurface->CreateSurface(this->m_pPrimarySurface, m_pDDraw, 0, 0, 1, 0, 0, 0, 1, 0, 0);
                  if ( hResult != 0 )
                  {
                    CInterfaceD3D::CleanUpCheckObjects(this);
                    WriteError(hResult, "CreatePrimarySurface");
                    return 8;
                  }
                  else
                  {
                    hResult = ((int (__thiscall *)(CSurface *, unsigned __int8 *))this->m_pPrimarySurface->GetPixelFormat)(this->m_pPrimarySurface, &v18);
                    if ( hResult != 0 )
                    {
                      CInterfaceD3D::CleanUpCheckObjects(this);
                      WriteError(hResult, "RetrievePixelFormatFromPrimarySurface");
                      return 9;
                    }
                    else
                    {
                      this->m_pTmpSurface = CSurface::CreateSurfacePtr(false);
                      if ( this->m_pTmpSurface == nullptr )
                      {
                        CInterfaceD3D::CleanUpCheckObjects(this);
                        BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                        return 10;
                      }
                      else
                      {
                        v4 = j__abs(v18);
                        hResult = (HRESULT)this->m_pTmpSurface->CreateSurface(this->m_pTmpSurface, this->m_pDDraw7, 32, 32, 1, 1, 0, v4, 0, 0, 0);
                        if ( hResult != 0 )
                        {
                          CInterfaceD3D::CleanUpCheckObjects(this);
                          WriteError(hResult, "CreateTestSurface");
                          return 7;
                        }
                        else
                        {
                          v11 = 16;
                          hResult = this->m_pPrimarySurface->GetBitDepth((CSurfaceV7 *)this->m_pPrimarySurface, &v11);
                          if ( hResult != 0 )
                          {
                            CInterfaceD3D::CleanUpCheckObjects(this);
                            WriteError(hResult, "GetBitDepthWhileCapChecking");
                            return 12;
                          }
                          else
                          {
                            hResult = this->m_pPrimarySurface->GetSurfaceSize((CSurfaceV7 *)this->m_pPrimarySurface, &v8, &v7);
                            if ( hResult != 0 )
                            {
                              CInterfaceD3D::CleanUpCheckObjects(this);
                              WriteError(hResult, "GetSurfaceSizeWhileCapChecking");
                              return 11;
                            }
                            else
                            {
                              v6 = v11 / 8 * v7 * v8;
                              v21.dwSize = 380;
                              hResult = this->m_pDDraw->lpVtbl->GetCaps(this->m_pDDraw, &v21, nullptr);
                              if ( hResult != 0 )
                              {
                                CInterfaceD3D::CleanUpCheckObjects(this);
                                WriteError(hResult, "GetCapabilities");
                                return 11;
                              }
                              else if ( !sub_2F8BE40(v21.dwVidMemTotal, v6, 0x7A1200u) )
                              {
                                CInterfaceD3D::CleanUpCheckObjects(this);
                                BBSupportTracePrintF(1, "GFX ENGINE: Not enough video memory available!");
                                return 13;
                              }
                              else if ( ((v21.dwCaps & 0x40) == 0 || (v21.dwCaps & 0x4000000) == 0) && ((v21.dwNLVBCaps & 0x40) == 0 || (v21.dwNLVBCaps & 0x4000000) == 0) )
                              {
                                CInterfaceD3D::CleanUpCheckObjects(this);
                                BBSupportTracePrintF(1, "GFX ENGINE: Needed blit capabilities are not supported!");
                                return 14;
                              }
                              else if ( (v21.dwCaps & 0x400000) == 0 )
                              {
                                CInterfaceD3D::CleanUpCheckObjects(this);
                                BBSupportTracePrintF(1, "GFX ENGINE: Color keying is not in all needed blit modes available!");
                                return 15;
                              }
                              else
                              {
                                v5 = ((int (__thiscall *)(CSurface *, IDirect3DDevice7 **))this->m_pTmpSurface->GetSurfacePtr)(this->m_pTmpSurface, &this->LandscapeDevice);
                                hResult = ((int (__stdcall *)(IDirect3D7 *, GUID *, int))this->m_pIDirect3D7->CreateDevice)(this->m_pIDirect3D7, &IID_IDirect3DHALDevice, v5);
                                if ( hResult != 0 )
                                {
                                  CInterfaceD3D::CleanUpCheckObjects(this);
                                  WriteError(hResult, "CreateCheckDevice");
                                  return 16;
                                }
                                else
                                {
                                  sHardwareCapabilitys.dpcTriCaps.dwSize = 56;
                                  sHardwareCapabilitys.dpcLineCaps.dwSize = 56;
                                  hResult = this->LandscapeDevice->GetCaps(this->LandscapeDevice, &sHardwareCapabilitys);
                                  if ( hResult != 0 )
                                  {
                                    CInterfaceD3D::CleanUpCheckObjects(this);
                                    WriteError(hResult, "Get3dCaps");
                                    return 17;
                                  }
                                  else if ( (sHardwareCapabilitys.dwDevCaps & 0x200) == 0 || (sHardwareCapabilitys.dwDevCaps & 0x400) == 0 || (sHardwareCapabilitys.dwDeviceRenderBitDepth & 0x400) == 0 || sHardwareCapabilitys.dwMinTextureWidth > 0x80 || sHardwareCapabilitys.dwMinTextureHeight > 0x80 || sHardwareCapabilitys.dwMaxTextureWidth < 0x100 )
                                  {
                                    CInterfaceD3D::CleanUpCheckObjects(this);
                                    BBSupportTracePrintF(1, "GFX ENGINE: A needed basic capability for the hardware renderer is unsupported!");
                                    return 18;
                                  }
                                  else
                                  {
                                    v10 = sHardwareCapabilitys.dwMaxTextureWidth >= 0x200;
                                    *_rSuccess = v10;
                                    if ( s_sDeviceIdentifier.dwDeviceId == 15623 )
                                    {
                                      *_rSuccess = false;
                                      BBSupportTracePrintF(1, "GFX ENGINE: No HWO rendering with permedia2 chipset!");
                                    }
                                    dword_3E2E320 = sHardwareCapabilitys.dwMaxTextureWidth;
                                    if ( (sHardwareCapabilitys.dpcTriCaps.dwDestBlendCaps & 4) == 0 )
                                    {
                                      CInterfaceD3D::CleanUpCheckObjects(this);
                                      BBSupportTracePrintF(1, "GFX ENGINE: Needed alpha blend capabilities for hardware rendering unsupported!");
                                      return 19;
                                    }
                                    else
                                    {
                                      vPixelFormats.b555 = 0;
                                      vPixelFormats.b565 = 0;
                                      vPixelFormats.b4444 = 0;
                                      vPixelFormats.b1555 = 0;
                                      hResult = this->LandscapeDevice->EnumTextureFormats(this->LandscapeDevice, (LPD3DENUMPIXELFORMATSCALLBACK)D3DEnumPixelFormatsCallback, &vPixelFormats);
                                      if ( hResult != 0 )
                                      {
                                        CInterfaceD3D::CleanUpCheckObjects(this);
                                        *_rSuccess = false;
                                        WriteError(hResult, "EnumerateTextureFormats");
                                        return 20;
                                      }
                                      else if ( vPixelFormats.b555 == 0 && vPixelFormats.b565 == 0 )
                                      {
                                        CInterfaceD3D::CleanUpCheckObjects(this);
                                        *_rSuccess = false;
                                        BBSupportTracePrintF(1, "GFX ENGINE: The needed texture formats are not supported by the hardware!");
                                        return 21;
                                      }
                                      else
                                      {
                                        if ( vPixelFormats.b4444 == 0 )
                                        {
                                          *_rSuccess = false;
                                          BBSupportTracePrintF(1, "GFX ENGINE: The needed 4444 format are not supported by the hardware!");
                                        }
                                        if ( s_sDeviceIdentifier.dwDeviceId == 35362 || s_sDeviceIdentifier.dwDeviceId == 35347 || s_sDeviceIdentifier.dwDeviceId == 37122 )
                                        {
                                          *_rSuccess = false;
                                          CInterfaceD3D::CleanUpCheckObjects(this);
                                          BBSupportTracePrintF(1, "GFX ENGINE: Savage chipset detected!");
                                          return 26;
                                        }
                                        else
                                        {
                                          if ( this->LandscapeDevice != nullptr )
                                          {
                                            this->LandscapeDevice->Release(this->LandscapeDevice);
                                            this->LandscapeDevice = nullptr;
                                          }
                                          if ( this->m_pPrimarySurface != nullptr )
                                          {
                                            ((void (__thiscall *)(CSurface *))this->m_pPrimarySurface->Release)(this->m_pPrimarySurface);
                                            m_pPrimarySurface = this->m_pPrimarySurface;
                                            if ( m_pPrimarySurface != nullptr )
                                            {
                                              m_pPrimarySurface->dtor((CSurfaceV7 *)m_pPrimarySurface, 1);
                                            }
                                            this->m_pPrimarySurface = nullptr;
                                          }
                                          if ( this->m_pTmpSurface != nullptr )
                                          {
                                            ((void (__thiscall *)(CSurface *))this->m_pTmpSurface->Release)(this->m_pTmpSurface);
                                            m_pTmpSurface = this->m_pTmpSurface;
                                            if ( m_pTmpSurface != nullptr )
                                            {
                                              m_pTmpSurface->dtor((CSurfaceV7 *)m_pTmpSurface, 1);
                                            }
                                            this->m_pTmpSurface = nullptr;
                                          }
                                          if ( this->m_pIDirect3D7 != nullptr )
                                          {
                                            ((void (__stdcall *)(IDirect3D7 *))this->m_pIDirect3D7->Release)(this->m_pIDirect3D7);
                                            this->m_pIDirect3D7 = nullptr;
                                          }
                                          if ( this->m_pDDraw7 == nullptr )
                                          {
                                            return 0;
                                          }
                                          this->m_pDDraw7->lpVtbl->Release(this->m_pDDraw7);
                                          this->m_pDDraw7 = nullptr;
                                          return 0;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
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
  if ( g_pDirectDraw != 0 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: DirectDraw already loaded");
    return 3;
  }
  else
  {
    v11 = DirectDrawCreate(0, (LPDIRECTDRAW *)&v12->m_pDDraw, 0);
    if ( v11 != 0 )
    {
      WriteError(v11, "CreateDirectDrawObject");
      return 3;
    }
    else
    {
      g_pDirectDraw = v12->m_pDDraw;
      v11 = v12->m_pDDraw->lpVtbl->SetCooperativeLevel(v12->m_pDDraw, a2, 8);
      if ( v11 != 0 )
      {
        CInterfaceD3D::CleanUpCheckObjects(v12);
        WriteError(v11, "SetCooperativeLevel");
        return 5;
      }
      else
      {
        v12->m_pPrimarySurface = CSurface::CreateSurfacePtr(1);
        if ( v12->m_pPrimarySurface != 0 )
        {
          v11 = (HRESULT)v12->m_pPrimarySurface->CreateSurface(v12->m_pPrimarySurface, v12->m_pDDraw, 0, 0, 1, 0, 0, 0, 1, 0, 0);
          if ( v11 != 0 )
          {
            CInterfaceD3D::CleanUpCheckObjects(v12);
            WriteError(v11, "CreatePrimarySurface");
            return 8;
          }
          else
          {
            v11 = ((int (__thiscall *)(CSurfaceV7 *, unsigned __int8 *))v12->m_pPrimarySurface->GetPixelFormat)(v12->m_pPrimarySurface, &v10);
            if ( v11 != 0 )
            {
              CInterfaceD3D::CleanUpCheckObjects(v12);
              WriteError(v11, "RetrievePixelFormatFromPrimarySurface");
              return 9;
            }
            else
            {
              v12->m_pTmpSurface = (int)CSurface::CreateSurfacePtr(1);
              if ( v12->m_pTmpSurface != 0 )
              {
                v3 = j__abs(v10);
                v11 = (*(int (__thiscall **)(int, IDirectDraw7 *, int, int, int, int, _DWORD, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v12->m_pTmpSurface + 48))(v12->m_pTmpSurface, v12->m_pDDraw, 32, 32, 1, 1, 0, v3, 0, 0, 0);
                if ( v11 != 0 )
                {
                  CInterfaceD3D::CleanUpCheckObjects(v12);
                  WriteError(v11, "CreateTestSurface");
                  return 7;
                }
                else
                {
                  v7 = 16;
                  v11 = v12->m_pPrimarySurface->GetBitDepth(v12->m_pPrimarySurface, &v7);
                  if ( v11 != 0 )
                  {
                    CInterfaceD3D::CleanUpCheckObjects(v12);
                    WriteError(v11, "GetBitDepthWhileCapChecking");
                    return 12;
                  }
                  else
                  {
                    v11 = v12->m_pPrimarySurface->GetSurfaceSize(v12->m_pPrimarySurface, &v6, &v5);
                    if ( v11 != 0 )
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
                      if ( v11 != 0 )
                      {
                        CInterfaceD3D::CleanUpCheckObjects(v12);
                        WriteError(v11, "GetCapabilities");
                        return 11;
                      }
                      else if ( (unsigned __int8)sub_2F8BE40(v15, v4, 4000000, 0) != 0 )
                      {
                        if ( (v14 & 0x40) != 0 && ((unsigned int)&s_iMsgTracer2.m_aMessages[15456] & v14) != 0 || (v16 & 0x40) != 0 && ((unsigned int)&s_iMsgTracer2.m_aMessages[15456] & v16) != 0 )
                        {
                          if ( (v14 & 0x400000) != 0 )
                          {
                            if ( v12->LandscapeDevice != 0 )
                            {
                              v12->LandscapeDevice->Release(v12->LandscapeDevice);
                              v12->LandscapeDevice = 0;
                            }
                            if ( v12->m_pPrimarySurface != 0 )
                            {
                              ((void (__thiscall *)(CSurfaceV7 *))v12->m_pPrimarySurface->Release)(v12->m_pPrimarySurface);
                              PrimarySurface = v12->m_pPrimarySurface;
                              if ( PrimarySurface != 0 )
                              {
                                PrimarySurface->dtor(PrimarySurface, 1);
                              }
                              v12->m_pPrimarySurface = 0;
                            }
                            if ( v12->m_pTmpSurface != 0 )
                            {
                              (*(void (__thiscall **)(int))(*(_DWORD *)v12->m_pTmpSurface + 4))(v12->m_pTmpSurface);
                              v8 = (void (__thiscall ***)(_DWORD, int))v12->m_pTmpSurface;
                              if ( v8 != 0 )
                              {
                                (**v8)(v8, 1);
                              }
                              v12->m_pTmpSurface = 0;
                            }
                            if ( v12->m_pIDirect3D7 != 0 )
                            {
                              ((void (__stdcall *)(IDirect3D7 *))v12->m_pIDirect3D7->Release)(v12->m_pIDirect3D7);
                              v12->m_pIDirect3D7 = 0;
                            }
                            if ( v12->m_pDDraw7 != 0 )
                            {
                              v12->m_pDDraw7->lpVtbl->Release(v12->m_pDDraw7);
                              v12->m_pDDraw7 = 0;
                            }
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
// Decompiled from char __thiscall CInterfaceD3D::CanCreateEngine(IDirectDraw7 **this, bool a2)
bool  CInterfaceD3D::CanCreateEngine(bool a2) {
  
  int v3; // eax
  int v5; // [esp+14h] [ebp-14h]
  CSurfaceV7 *SurfacePtr; // [esp+24h] [ebp-4h]

  SurfacePtr = CSurface::CreateSurfacePtr(a2);
  if ( SurfacePtr != 0 )
  {
    v3 = j__abs(MEMORY[0x3E2E2B8] == 1);
    v5 = (int)SurfacePtr->CreateSurface(SurfacePtr, *(this + 1), 32, 32, 1, 1, 0, v3, 0, 0, 0);
    if ( v5 != 0 )
    {
      WriteError(v5, "CanRebuildEngine");
      SurfacePtr->dtor(SurfacePtr, 1);
      return 0;
    }
    else
    {
      ((void (__thiscall *)(CSurfaceV7 *))SurfacePtr->Release)(SurfacePtr);
      SurfacePtr->dtor(SurfacePtr, 1);
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

  if ( this->LandscapeDevice != 0 )
  {
    this->LandscapeDevice->Release(this->LandscapeDevice);
    this->LandscapeDevice = 0;
  }
  if ( this->m_pPrimarySurface != 0 )
  {
    ((void (__thiscall *)(CSurfaceV7 *))this->m_pPrimarySurface->Release)(this->m_pPrimarySurface);
    if ( this->m_pPrimarySurface != 0 )
    {
      this->m_pPrimarySurface->dtor(this->m_pPrimarySurface, 1);
    }
    this->m_pPrimarySurface = 0;
  }
  if ( this->m_pTmpSurface != 0 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)this->m_pTmpSurface + 4))(this->m_pTmpSurface);
    if ( this->m_pTmpSurface != 0 )
    {
      (**(void (__thiscall ***)(int, int))this->m_pTmpSurface)(this->m_pTmpSurface, 1);
    }
    this->m_pTmpSurface = 0;
  }
  if ( this->m_pIDirect3D7 != 0 )
  {
    ((void (__stdcall *)(IDirect3D7 *))this->m_pIDirect3D7->Release)(this->m_pIDirect3D7);
    this->m_pIDirect3D7 = 0;
  }
  if ( this->m_pDDraw7 != 0 )
  {
    this->m_pDDraw7->lpVtbl->Release(this->m_pDDraw7);
    this->m_pDDraw7 = 0;
  }
  result = this;
  if ( this->m_pDDraw != 0 )
  {
    result = (CInterfaceD3D *)this->m_pDDraw->lpVtbl->Release(this->m_pDDraw);
    this->m_pDDraw = 0;
    g_pDirectDraw = 0;
  }
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


