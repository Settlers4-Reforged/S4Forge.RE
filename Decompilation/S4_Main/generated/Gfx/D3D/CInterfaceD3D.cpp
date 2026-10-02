#if FALSE
#include "CInterfaceD3D.h"

// Definitions for class CInterfaceD3D

// address=[0x2f5f250]
// Decompiled from void __thiscall CInterfaceD3D::BlitCursor(CInterfaceD3D *this)
void  CInterfaceD3D::BlitCursor(void) {
  
  HRESULT v1; // [esp+0h] [ebp-8h]
  HRESULT v2; // [esp+0h] [ebp-8h]

  v1 = CFixCursor::Show(&this->m_cMoveCursor, this->m_pFinalRenderSurface);
  if ( v1 != 0 )
  {
    WriteError(v1, "BlitMoveCursor");
  }
  v2 = CFixCursor::Show(&this->m_cZoomCursor, this->m_pFinalRenderSurface);
  this->m_bRefreshTextureSurfaces = 1;
  if ( v2 != 0 )
  {
    WriteError(v2, "BlitZoomCursor");
  }
}


// address=[0x2f5f390]
// Decompiled from bool __thiscall CInterfaceD3D::HasCameraWindowSurface(CInterfaceD3D *this)
bool  CInterfaceD3D::HasCameraWindowSurface(void)const {
  
  return this->m_pLandscapeCameraRenderSurface != nullptr;
}


// address=[0x2f62860]
// Decompiled from CInterfaceD3D *__thiscall CInterfaceD3D::CInterfaceD3D(CInterfaceD3D *this)
 CInterfaceD3D::CInterfaceD3D(void) {
  
  unsigned int i; // [esp+4h] [ebp-14h]
  int j; // [esp+4h] [ebp-14h]
  int k; // [esp+4h] [ebp-14h]

  SurfaceClipper::SurfaceClipper(&this->m_sClipper1);
  SurfaceClipper::SurfaceClipper(&this->m_sMinimapClipper);
  CFixCursor::CFixCursor(&this->m_cMoveCursor);
  CFixCursor::CFixCursor((CFixCursor *)((char *)&this->?.m_pSurface + 3));
  this->m_iCacheRetries = 2000;
  this->m_bRefreshTextureSurfaces = 0;
  this->m_bForceBlt = 0;
  this->m_bHiTextureQuality = 0;
  this->m_iGuiSurfaceSize = 0;
  this->m_iNumberOfCachedSurfaces = 0;
  this->m_bDisableRendering = 0;
  this->m_iLandscapeSceneLock = 0;
  this->m_iObjectSceneLock = 0;
  memset(this->m_bAvailableResolutions, 0, sizeof(this->m_bAvailableResolutions));
  this->m_bHardwareRuns = 0;
  this->m_bSoftwareRuns = 0;
  this->m_bEngineWasRebuilded = 1;
  GfxEngineSetup.iCurrentGfxMode = 0;
  for ( i = 0;
        i < 14;
        ++i )
  {
    this->m_pDDGuiSurfaces[i] = nullptr;
  }
  CInterfaceD3D::InitTexturedLandscapeModule(this);
  this->m_pDDraw = nullptr;
  this->m_pDDraw7 = nullptr;
  this->m_pZoomCursorSurface = nullptr;
  this->m_pMoveCursorSurface = nullptr;
  this->m_pTmpSurface = nullptr;
  this->m_pMiniMapAreaSurface = nullptr;
  this->m_pMiniMapSurface = nullptr;
  this->m_pLandscapeSurface = nullptr;
  this->m_pLandscapeCameraRenderSurface = nullptr;
  this->m_pCurrentLandScapeRenderTarget = nullptr;
  this->m_pFinalRenderSurface = nullptr;
  this->m_pPrimarySurface = nullptr;
  this->m_pIDirect3D7 = nullptr;
  this->LandscapeDevice = nullptr;
  this->m_pObjectDevice = nullptr;
  this->D3DVertexPtr = nullptr;
  for ( j = 0;
        j < 2;
        ++j )
  {
    this->m_pDDObjectSurfacePtr[j] = nullptr;
    this->m_pDDSourceObjectSurfacePtr[j] = nullptr;
    this->m_pcPictureManager[j] = nullptr;
  }
  for ( k = 0;
        k < 180;
        ++k )
  {
    this->m_pCacheSurfaces[k] = nullptr;
    this->m_pCacheManagers[k] = nullptr;
  }
  BBSupportTracePrintF(1, "GFX ENGINE: DD interface successfully created!");
  return this;
}


// address=[0x2f62b00]
// Decompiled from int __thiscall CInterfaceD3D::~CInterfaceD3D(CInterfaceD3D *this)
 CInterfaceD3D::~CInterfaceD3D(void) {
  
  CUploadCachePageManager *v2; // [esp+7Ch] [ebp-50h]
  CCachePageManager *v3; // [esp+80h] [ebp-4Ch]
  CSurface *m_pTmpSurface; // [esp+84h] [ebp-48h]
  CSurface *m_pPrimarySurface; // [esp+88h] [ebp-44h]
  CSurface *m_pMiniMapAreaSurface; // [esp+8Ch] [ebp-40h]
  CSurface *m_pMiniMapSurface; // [esp+90h] [ebp-3Ch]
  CSurface *m_pFinalRenderSurface; // [esp+94h] [ebp-38h]
  CSurface *m_pLandscapeSurface; // [esp+98h] [ebp-34h]
  CSurface *m_pMoveCursorSurface; // [esp+9Ch] [ebp-30h]
  CSurface *m_pZoomCursorSurface; // [esp+A0h] [ebp-2Ch]
  CSurface *v12; // [esp+A4h] [ebp-28h]
  CSurface *v13; // [esp+A8h] [ebp-24h]
  CSurface *v14; // [esp+ACh] [ebp-20h]
  CSurface *v15; // [esp+B0h] [ebp-1Ch]
  int k; // [esp+B4h] [ebp-18h]
  int i; // [esp+B8h] [ebp-14h]
  int j; // [esp+B8h] [ebp-14h]
  int m; // [esp+B8h] [ebp-14h]
  int n; // [esp+B8h] [ebp-14h]

  for ( i = 179;
        i >= 0;
        --i )
  {
    if ( this->m_pCacheManagers[i] != nullptr )
    {
      if ( CCachePageManager::IsVideoSurfaceLocked(this->m_pCacheManagers[i]) != 0 )
      {
        CCachePageManager::UnlockVideoSurface(this->m_pCacheManagers[i]);
      }
      if ( CCachePageManager::IsSourceSurfaceLocked(this->m_pCacheManagers[i]) != 0 )
      {
        CCachePageManager::UnlockSourceSurface(this->m_pCacheManagers[i]);
      }
      v3 = this->m_pCacheManagers[i];
      if ( v3 != nullptr )
      {
        delete v3;
      }
      this->m_pCacheManagers[i] = nullptr;
    }
    if ( this->m_pCacheSurfaces[i] != nullptr )
    {
      this->m_pCacheSurfaces[i]->lpVtbl->Release(this->m_pCacheSurfaces[i]);
      this->m_pCacheSurfaces[i] = nullptr;
    }
  }
  for ( j = 1;
        j >= 0;
        --j )
  {
    if ( this->m_pcPictureManager[j] != nullptr )
    {
      if ( CCachePageManager::IsVideoSurfaceLocked(this->m_pcPictureManager[j]) != 0 )
      {
        CCachePageManager::UnlockVideoSurface(this->m_pcPictureManager[j]);
      }
      if ( CCachePageManager::IsSourceSurfaceLocked(this->m_pcPictureManager[j]) != 0 )
      {
        CCachePageManager::UnlockSourceSurface(this->m_pcPictureManager[j]);
      }
      v2 = this->m_pcPictureManager[j];
      if ( v2 != nullptr )
      {
        delete v2;
      }
      this->m_pcPictureManager[j] = nullptr;
    }
    if ( this->m_pDDSourceObjectSurfacePtr[j] != nullptr )
    {
      this->m_pDDSourceObjectSurfacePtr[j]->Release(this->m_pDDSourceObjectSurfacePtr[j]);
      v15 = this->m_pDDSourceObjectSurfacePtr[j];
      if ( v15 != nullptr )
      {
        v15->dtor(v15, 1);
      }
      this->m_pDDSourceObjectSurfacePtr[j] = nullptr;
    }
    if ( this->m_pDDObjectSurfacePtr[j] != nullptr )
    {
      this->m_pDDObjectSurfacePtr[j]->Release(this->m_pDDObjectSurfacePtr[j]);
      v14 = this->m_pDDObjectSurfacePtr[j];
      if ( v14 != nullptr )
      {
        v14->dtor(v14, 1);
      }
      this->m_pDDObjectSurfacePtr[j] = nullptr;
    }
  }
  if ( s_bCursorIsFixed != 0 )
  {
    ClipCursor(nullptr);
    s_bCursorIsFixed = 0;
  }
  if ( s_bCursorIsVisible == 0 )
  {
    ShowCursor(true);
    s_bCursorIsVisible = 1;
  }
  if ( s_hCursor != nullptr )
  {
    SetClassLongA(GfxEngineSetup.sRenderSetup.m_hWnd, -12, (LONG)s_hCursor);
    SetCursor(s_hCursor);
    s_hCursor = nullptr;
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
    if ( this->m_pDDTextureSurfaces[m] != nullptr )
    {
      this->m_pDDTextureSurfaces[m]->Release(this->m_pDDTextureSurfaces[m]);
      v13 = this->m_pDDTextureSurfaces[m];
      if ( v13 != nullptr )
      {
        v13->dtor(v13, 1);
      }
      this->m_pDDTextureSurfaces[m] = nullptr;
    }
    g_pTextureTable[m] = 0;
  }
  for ( n = 14;
        n >= 0;
        --n )
  {
    if ( this->m_pDDGuiSurfaces[n] != nullptr )
    {
      this->m_pDDGuiSurfaces[n]->Release(this->m_pDDGuiSurfaces[n]);
      v12 = this->m_pDDGuiSurfaces[n];
      if ( v12 != nullptr )
      {
        v12->dtor(v12, 1);
      }
      this->m_pDDGuiSurfaces[n] = nullptr;
    }
  }
  SurfaceClipper::ReleaseClipper(&this->m_sClipper1);
  SurfaceClipper::ReleaseClipper(&this->m_sMinimapClipper);
  if ( this->m_pObjectDevice != nullptr )
  {
    this->m_pObjectDevice->Release(this->m_pObjectDevice);
  }
  if ( this->LandscapeDevice != nullptr )
  {
    this->LandscapeDevice->Release(this->LandscapeDevice);
  }
  if ( this->m_pZoomCursorSurface != nullptr )
  {
    this->m_pZoomCursorSurface->Release(this->m_pZoomCursorSurface);
    m_pZoomCursorSurface = this->m_pZoomCursorSurface;
    if ( m_pZoomCursorSurface != nullptr )
    {
      m_pZoomCursorSurface->dtor(m_pZoomCursorSurface, 1);
    }
    this->m_pZoomCursorSurface = nullptr;
  }
  if ( this->m_pMoveCursorSurface != nullptr )
  {
    this->m_pMoveCursorSurface->Release(this->m_pMoveCursorSurface);
    m_pMoveCursorSurface = this->m_pMoveCursorSurface;
    if ( m_pMoveCursorSurface != nullptr )
    {
      m_pMoveCursorSurface->dtor(m_pMoveCursorSurface, 1);
    }
    this->m_pMoveCursorSurface = nullptr;
  }
  if ( this->m_pLandscapeSurface != nullptr )
  {
    this->m_pLandscapeSurface->Release(this->m_pLandscapeSurface);
    m_pLandscapeSurface = this->m_pLandscapeSurface;
    if ( m_pLandscapeSurface != nullptr )
    {
      m_pLandscapeSurface->dtor(m_pLandscapeSurface, 1);
    }
    this->m_pLandscapeSurface = nullptr;
  }
  CInterfaceD3D::DestroyCameraWindowSurface(this);
  if ( this->m_pFinalRenderSurface != nullptr )
  {
    if ( ((unsigned __int8 (__thiscall *)(CSurface *))this->m_pFinalRenderSurface->j_?IsBackBufferReference@CSurfaceV7@@UAE_NXZ)(this->m_pFinalRenderSurface) == 0 )
    {
      this->m_pFinalRenderSurface->Release(this->m_pFinalRenderSurface);
    }
    m_pFinalRenderSurface = this->m_pFinalRenderSurface;
    if ( m_pFinalRenderSurface != nullptr )
    {
      m_pFinalRenderSurface->dtor(m_pFinalRenderSurface, 1);
    }
    this->m_pFinalRenderSurface = nullptr;
  }
  if ( this->m_pMiniMapSurface != nullptr )
  {
    this->m_pMiniMapSurface->Release(this->m_pMiniMapSurface);
    m_pMiniMapSurface = this->m_pMiniMapSurface;
    if ( m_pMiniMapSurface != nullptr )
    {
      m_pMiniMapSurface->dtor(m_pMiniMapSurface, 1);
    }
    this->m_pMiniMapSurface = nullptr;
  }
  if ( this->m_pMiniMapAreaSurface != nullptr )
  {
    this->m_pMiniMapAreaSurface->Release(this->m_pMiniMapAreaSurface);
    m_pMiniMapAreaSurface = this->m_pMiniMapAreaSurface;
    if ( m_pMiniMapAreaSurface != nullptr )
    {
      m_pMiniMapAreaSurface->dtor(m_pMiniMapAreaSurface, 1);
    }
    this->m_pMiniMapAreaSurface = nullptr;
  }
  if ( this->m_pPrimarySurface != nullptr )
  {
    this->m_pPrimarySurface->Release(this->m_pPrimarySurface);
    m_pPrimarySurface = this->m_pPrimarySurface;
    if ( m_pPrimarySurface != nullptr )
    {
      m_pPrimarySurface->dtor(m_pPrimarySurface, 1);
    }
    this->m_pPrimarySurface = nullptr;
  }
  if ( this->m_pTmpSurface != nullptr )
  {
    m_pTmpSurface = this->m_pTmpSurface;
    if ( m_pTmpSurface != nullptr )
    {
      m_pTmpSurface->dtor(m_pTmpSurface, 1);
    }
    this->m_pTmpSurface = nullptr;
  }
  if ( this->m_pDDraw7 != nullptr )
  {
    this->m_pDDraw7->lpVtbl->Release(this->m_pDDraw7);
  }
  if ( this->m_pIDirect3D7 != nullptr )
  {
    this->m_pIDirect3D7->Release(this->m_pIDirect3D7);
  }
  this->m_pDDraw = nullptr;
  this->m_pDDraw7 = nullptr;
  this->m_pIDirect3D7 = nullptr;
  this->LandscapeDevice = nullptr;
  this->m_pObjectDevice = nullptr;
  CInterfaceD3D::DeleteEngineData(this);
  BBSupportTracePrintF(1, "GFX ENGINE: DD interface successfully destroyed!");
  SurfaceClipper::~SurfaceClipper(&this->m_sMinimapClipper);
  return SurfaceClipper::~SurfaceClipper(&this->m_sClipper1);
}


// address=[0x2f63450]
// Decompiled from char __thiscall CInterfaceD3D::InitCommon(CInterfaceD3D *this)
bool  CInterfaceD3D::InitCommon(void) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  bool IsHardwareLandscapeEngine; // al
  bool HardwareLandscapeEngine2; // al
  int Clipper; // eax
  int v10; // [esp-10h] [ebp-78h]
  int v11; // [esp-10h] [ebp-78h]
  BOOL HardwareLandscapeEngine; // [esp-8h] [ebp-70h]
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
  HRESULT hResult; // [esp+5Ch] [ebp-Ch] MAPDST
  unsigned __int8 v42; // [esp+67h] [ebp-1h] BYREF

  BBSupportTracePrintF(1, "GFX ENGINE: Begin common init. Mode: Interface 7.");
  if ( this->m_bHardwareRuns != 0 || this->m_bSoftwareRuns != 0 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT COMMON: Engine is already initialized!");
    return 1;
  }
  this->m_bHiTextureQuality = SGfxRenderConfiguration::IsHQTextureSet(&GfxEngineSetup.sRenderSetup);
  this->m_bForceBlt = !SGfxRenderConfiguration::IsForceBlit(&GfxEngineSetup.sRenderSetup);
  if ( s_hCursor != nullptr )
  {
    SetClassLongA(GfxEngineSetup.sRenderSetup.m_hWnd, -12, (LONG)s_hCursor);
    SetCursor(s_hCursor);
    s_hCursor = nullptr;
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
  hResult = this->m_pDDraw->lpVtbl->QueryInterface(this->m_pDDraw, &IID_IDirectDraw7, (LPVOID *)&this->m_pDDraw7);
  if ( hResult != 0 )
  {
    WriteError(hResult, "QueryInterface");
    return 0;
  }
  else
  {
    hResult = this->m_pDDraw7->lpVtbl->SetCooperativeLevel(this->m_pDDraw7, GfxEngineSetup.sRenderSetup.m_hWnd, 8);
    if ( hResult != 0 )
    {
      WriteError(hResult, "SetCooperativeLevel");
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
        hResult = this->m_pPrimarySurface->CreateSurface(this->m_pPrimarySurface, m_pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, 0, 0, v2, 1, 0, 0);
        if ( hResult != 0 )
        {
          WriteError(hResult, "CreatePrimarySurface");
          return 0;
        }
        else
        {
          hResult = this->m_pPrimarySurface->GetPixelFormat(this->m_pPrimarySurface, &v42);
          if ( hResult != 0 )
          {
            WriteError(hResult, "RetrievePixelFormatFromPrimarySurface");
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
              hResult = this->m_pMoveCursorSurface->CreateSurface(this->m_pMoveCursorSurface, m_pDDraw7, 32, 32, 1, 0, 0, v3, 0, 0, 0);
              if ( hResult != 0 )
              {
                WriteError(hResult, "CreateMoveCursorSurface");
                return 0;
              }
              else
              {
                if ( GfxEngineSetup.iCurrentGfxMode == 1 )
                {
                  CFixCursor::SetSurfacePtr(&this->m_cMoveCursor, 0x73u, this->m_pMoveCursorSurface, g_sColorKeyMagenta555.dwColorSpaceLowValue);
                }
                else
                {
                  CFixCursor::SetSurfacePtr(&this->m_cMoveCursor, 0x73u, this->m_pMoveCursorSurface, g_sColorKeyMagenta565.dwColorSpaceLowValue);
                }
                if ( GfxEngineSetup.iCurrentGfxMode == 1 )
                {
                  this->m_pMoveCursorSurface->SetColorKey(this->m_pMoveCursorSurface, 8, &g_sColorKeyMagenta555);
                }
                else
                {
                  this->m_pMoveCursorSurface->SetColorKey(this->m_pMoveCursorSurface, 8, &g_sColorKeyMagenta565);
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
                  hResult = this->m_pZoomCursorSurface->CreateSurface(this->m_pZoomCursorSurface, v18, 32, 32, 1, 0, 0, v4, 0, 0, 0);
                  if ( hResult != 0 )
                  {
                    WriteError(hResult, "CreateZoomCursorSurface");
                    return 0;
                  }
                  else
                  {
                    if ( GfxEngineSetup.iCurrentGfxMode == 1 )
                    {
                      CFixCursor::SetSurfacePtr((CFixCursor *)((char *)&this->?.m_pSurface + 3), 0x74u, this->m_pZoomCursorSurface, g_sColorKeyMagenta555.dwColorSpaceLowValue);
                    }
                    else
                    {
                      CFixCursor::SetSurfacePtr((CFixCursor *)((char *)&this->?.m_pSurface + 3), 0x74u, this->m_pZoomCursorSurface, g_sColorKeyMagenta565.dwColorSpaceLowValue);
                    }
                    if ( GfxEngineSetup.iCurrentGfxMode == 1 )
                    {
                      this->m_pZoomCursorSurface->SetColorKey(this->m_pZoomCursorSurface, 8, &g_sColorKeyMagenta555);
                    }
                    else
                    {
                      this->m_pZoomCursorSurface->SetColorKey(this->m_pZoomCursorSurface, 8, &g_sColorKeyMagenta565);
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
                      hResult = this->m_pMiniMapSurface->CreateSurface(this->m_pMiniMapSurface, v17, 240, 160, 1, 0, 0, v5, 0, 0, 0);
                      if ( hResult != 0 )
                      {
                        WriteError(hResult, "CreateMiniMapSurface");
                        return 0;
                      }
                      else
                      {
                        this->m_pMiniMapSurface->ClearSurface(this->m_pMiniMapSurface, nullptr);
                        this->m_pMiniMapSurface->SetColorKey(this->m_pMiniMapSurface, 8, &g_sColorKeyBlack);
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
                          hResult = this->m_pMiniMapAreaSurface->CreateSurface(this->m_pMiniMapAreaSurface, v16, 240, 160, 1, 0, 0, v6, 0, 0, 0);
                          if ( hResult != 0 )
                          {
                            WriteError(hResult, "CreateMiniMapAreaSurface");
                            return 0;
                          }
                          else
                          {
                            hResult = this->m_pMiniMapAreaSurface->ClearSurface(this->m_pMiniMapAreaSurface, nullptr);
                            if ( hResult != 0 )
                            {
                              WriteError(hResult, "ClearMiniMapSurface");
                            }
                            hResult = ((int (__thiscall *)(CSurface *, int, DDCOLORKEY *))this->m_pMiniMapAreaSurface->SetColorKey)(this->m_pMiniMapAreaSurface, 8, &g_sColorKeyBlack);
                            if ( hResult != 0 )
                            {
                              WriteError(hResult, "SetMiniMapColorKey");
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
                              hResult = this->m_pLandscapeSurface->CreateSurface(this->m_pLandscapeSurface, v15, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, IsHardwareLandscapeEngine, 0, v10, 0, 0, 0);
                              if ( hResult != 0 )
                              {
                                WriteError(hResult, "CreateLandscapeSurface");
                                return 0;
                              }
                              else
                              {
                                this->m_pCurrentLandScapeRenderTarget = this->m_pLandscapeSurface;
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
                                  HardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup);
                                  v11 = j__abs(v14);
                                  HardwareLandscapeEngine2 = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup);
                                  hResult = this->m_pFinalRenderSurface->CreateSurface(this->m_pFinalRenderSurface, m_pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, HardwareLandscapeEngine2, 0, v11, 0, HardwareLandscapeEngine, 0);
                                  if ( hResult != 0 )
                                  {
                                    WriteError(hResult, "CreateFinalRenderSurface");
                                    return 0;
                                  }
                                  else
                                  {
                                    hResult = SurfaceClipper::InitClipper(&this->m_sClipper1, this->m_pDDraw7);
                                    if ( hResult != 0 )
                                    {
                                      WriteError(hResult, "CreateClipper1");
                                      return 0;
                                    }
                                    else
                                    {
                                      hResult = SurfaceClipper::InitClipper(&this->m_sMinimapClipper, this->m_pDDraw7);
                                      if ( hResult != 0 )
                                      {
                                        WriteError(hResult, "Create Minimap Clipper");
                                        return 0;
                                      }
                                      else
                                      {
                                        hResult = SurfaceClipper::SetClipWindow(&this->m_sClipper1, (HWND *)GfxEngineSetup.sRenderSetup.m_hWnd);
                                        if ( hResult != 0 )
                                        {
                                          WriteError(hResult, "AssignClipper1");
                                          return 0;
                                        }
                                        else
                                        {
                                          Clipper = SurfaceClipper::GetClipper(&this->m_sClipper1);
                                          hResult = this->m_pPrimarySurface->SetClipper(this->m_pPrimarySurface, Clipper);
                                          if ( hResult != 0 )
                                          {
                                            WriteError(hResult, "SetClipper1");
                                            return 0;
                                          }
                                          else
                                          {
                                            g_pDestSizeTable = g_iDestSizeTable;
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
  bool IsHardwareLandscapeEngine; // al
  bool v8; // al
  int Clipper; // eax
  int v10; // [esp-10h] [ebp-6Ch]
  int v11; // [esp-10h] [ebp-6Ch]
  BOOL v12; // [esp-8h] [ebp-64h]
  int v13; // [esp+0h] [ebp-5Ch] BYREF
  int v15; // [esp+8h] [ebp-54h]
  int v17; // [esp+10h] [ebp-4Ch]
  int v19; // [esp+18h] [ebp-44h]
  int v21; // [esp+20h] [ebp-3Ch]
  DWORD iColorKeyValue; // [esp+28h] [ebp-34h]
  IDirectDraw7 *pDDraw; // [esp+2Ch] [ebp-30h] MAPDST
  int v25; // [esp+30h] [ebp-2Ch]
  DDCOLORKEY *pColorKeyMagenta; // [esp+34h] [ebp-28h] MAPDST
  DWORD dwColorSpaceLowValue; // [esp+38h] [ebp-24h]
  IDirectDraw7 *m_pDDraw7; // [esp+3Ch] [ebp-20h]
  int v29; // [esp+40h] [ebp-1Ch]
  IDirectDraw7 *m_pDDraw; // [esp+44h] [ebp-18h]
  int Number; // [esp+48h] [ebp-14h]
  int i; // [esp+4Ch] [ebp-10h]
  HRESULT hResult; // [esp+50h] [ebp-Ch]
  char v35; // [esp+5Bh] [ebp-1h] BYREF

  BBSupportTracePrintF(1, "GFX ENGINE: Begin common init. Mode: Interface 3.");
  if ( this->m_bHardwareRuns != 0 || this->m_bSoftwareRuns != 0 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT COMMON: Engine is already initialized!");
    return 1;
  }
  this->m_bHiTextureQuality = SGfxRenderConfiguration::IsHQTextureSet(&GfxEngineSetup.sRenderSetup);
  this->m_bForceBlt = 0;
  if ( s_hCursor != nullptr )
  {
    SetClassLongA(GfxEngineSetup.sRenderSetup.m_hWnd, -12, (LONG)s_hCursor);
    SetCursor(s_hCursor);
    s_hCursor = nullptr;
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
    hResult = DirectDrawCreate(nullptr, (LPDIRECTDRAW *)&this->m_pDDraw, nullptr);
    if ( hResult != 0 )
    {
      WriteError(hResult, "CreateDirectDrawObject");
      return 0;
    }
    g_pDirectDraw = this->m_pDDraw;
  }
  hResult = this->m_pDDraw->lpVtbl->SetCooperativeLevel(this->m_pDDraw, GfxEngineSetup.sRenderSetup.m_hWnd, 8);
  if ( hResult != 0 )
  {
    WriteError(hResult, "SetCooperativeLevel");
    return 0;
  }
  else
  {
    this->m_pPrimarySurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
    if ( this->m_pPrimarySurface != nullptr )
    {
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
      hResult = this->m_pPrimarySurface->CreateSurface(this->m_pPrimarySurface, m_pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, 0, 0, v2, 1, 0, 0);
      if ( hResult != 0 )
      {
        WriteError(hResult, "CreatePrimarySurface");
        return 0;
      }
      else
      {
        hResult = this->m_pPrimarySurface->GetBitDepth((CSurfaceV7 *)this->m_pPrimarySurface, &v13);
        if ( hResult != 0 )
        {
          WriteError(hResult, "RetrieveBitDepth");
          return 0;
        }
        else if ( v13 == 16 )
        {
          hResult = this->m_pPrimarySurface->GetPixelFormat(this->m_pPrimarySurface, (unsigned __int8 *)&v35);
          if ( hResult != 0 )
          {
            WriteError(hResult, "RetrievePixelFormatFromPrimarySurface");
            return 0;
          }
          else
          {
            if ( v35 != 0 )
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
              v29 = GfxEngineSetup.iCurrentGfxMode == 1;
              if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
              {
                m_pDDraw7 = this->m_pDDraw;
              }
              else
              {
                m_pDDraw7 = this->m_pDDraw7;
              }
              v3 = j__abs(v29);
              hResult = this->m_pMoveCursorSurface->CreateSurface(this->m_pMoveCursorSurface, m_pDDraw7, 32, 32, 1, 0, 0, v3, 0, 0, 0);
              if ( hResult != 0 )
              {
                WriteError(hResult, "CreateMoveCursorSurface");
                return 0;
              }
              else
              {
                if ( GfxEngineSetup.iCurrentGfxMode == 1 )
                {
                  dwColorSpaceLowValue = g_sColorKeyMagenta555.dwColorSpaceLowValue;
                }
                else
                {
                  dwColorSpaceLowValue = g_sColorKeyMagenta565.dwColorSpaceLowValue;
                }
                CFixCursor::SetSurfacePtr(&this->m_cMoveCursor, 0x73u, this->m_pMoveCursorSurface, dwColorSpaceLowValue);
                if ( GfxEngineSetup.iCurrentGfxMode == 1 )
                {
                  pColorKeyMagenta = &g_sColorKeyMagenta555;
                }
                else
                {
                  pColorKeyMagenta = &g_sColorKeyMagenta565;
                }
                this->m_pMoveCursorSurface->SetColorKey(this->m_pMoveCursorSurface, 8, pColorKeyMagenta);
                this->m_pZoomCursorSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
                if ( this->m_pZoomCursorSurface != nullptr )
                {
                  v25 = GfxEngineSetup.iCurrentGfxMode == 1;
                  if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
                  {
                    pDDraw = this->m_pDDraw;
                  }
                  else
                  {
                    pDDraw = this->m_pDDraw7;
                  }
                  v4 = j__abs(v25);
                  hResult = this->m_pZoomCursorSurface->CreateSurface(this->m_pZoomCursorSurface, pDDraw, 32, 32, 1, 0, 0, v4, 0, 0, 0);
                  if ( hResult != 0 )
                  {
                    WriteError(hResult, "CreationZoomCursorSurface");
                    return 0;
                  }
                  else
                  {
                    if ( GfxEngineSetup.iCurrentGfxMode == 1 )
                    {
                      iColorKeyValue = g_sColorKeyMagenta555.dwColorSpaceLowValue;
                    }
                    else
                    {
                      iColorKeyValue = g_sColorKeyMagenta565.dwColorSpaceLowValue;
                    }
                    CFixCursor::SetSurfacePtr((CFixCursor *)((char *)&this->?.m_pSurface + 3), 0x74u, this->m_pZoomCursorSurface, iColorKeyValue);
                    if ( GfxEngineSetup.iCurrentGfxMode == 1 )
                    {
                      pColorKeyMagenta = &g_sColorKeyMagenta555;
                    }
                    else
                    {
                      pColorKeyMagenta = &g_sColorKeyMagenta565;
                    }
                    this->m_pZoomCursorSurface->SetColorKey(this->m_pZoomCursorSurface, 8, pColorKeyMagenta);
                    this->m_pMiniMapSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
                    if ( this->m_pMiniMapSurface != nullptr )
                    {
                      v21 = GfxEngineSetup.iCurrentGfxMode == 1;
                      if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
                      {
                        pDDraw = this->m_pDDraw;
                      }
                      else
                      {
                        pDDraw = this->m_pDDraw7;
                      }
                      v5 = j__abs(v21);
                      hResult = this->m_pMiniMapSurface->CreateSurface(this->m_pMiniMapSurface, pDDraw, 240, 160, 1, 0, 0, v5, 0, 0, 0);
                      if ( hResult != 0 )
                      {
                        WriteError(hResult, "CreateMiniMapSurface");
                        return 0;
                      }
                      else
                      {
                        this->m_pMiniMapSurface->ClearSurface(this->m_pMiniMapSurface, nullptr);
                        this->m_pMiniMapSurface->SetColorKey(this->m_pMiniMapSurface, 8, &g_sColorKeyBlack);
                        this->m_pMiniMapAreaSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
                        if ( this->m_pMiniMapAreaSurface != nullptr )
                        {
                          v19 = GfxEngineSetup.iCurrentGfxMode == 1;
                          if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
                          {
                            pDDraw = this->m_pDDraw;
                          }
                          else
                          {
                            pDDraw = this->m_pDDraw7;
                          }
                          v6 = j__abs(v19);
                          hResult = this->m_pMiniMapAreaSurface->CreateSurface(this->m_pMiniMapAreaSurface, pDDraw, 240, 160, 1, 0, 0, v6, 0, 0, 0);
                          if ( hResult != 0 )
                          {
                            WriteError(hResult, "CreateMiniMapAreaSurface");
                            return 0;
                          }
                          else
                          {
                            hResult = this->m_pMiniMapAreaSurface->ClearSurface(this->m_pMiniMapAreaSurface, nullptr);
                            if ( hResult != 0 )
                            {
                              WriteError(hResult, "ClearMiniMapSurface");
                            }
                            hResult = ((int (__thiscall *)(CSurface *, int, DDCOLORKEY *))this->m_pMiniMapAreaSurface->SetColorKey)(this->m_pMiniMapAreaSurface, 8, &g_sColorKeyBlack);
                            if ( hResult != 0 )
                            {
                              WriteError(hResult, "SetMiniMapColorKey");
                            }
                            BBSupportTracePrintF(1, "GFX ENGINE: Size of render surface: %d x %d", GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight);
                            this->m_pLandscapeSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
                            if ( this->m_pLandscapeSurface != nullptr )
                            {
                              v17 = GfxEngineSetup.iCurrentGfxMode == 1;
                              if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
                              {
                                pDDraw = this->m_pDDraw;
                              }
                              else
                              {
                                pDDraw = this->m_pDDraw7;
                              }
                              v10 = j__abs(v17);
                              IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup);
                              hResult = this->m_pLandscapeSurface->CreateSurface(this->m_pLandscapeSurface, pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, IsHardwareLandscapeEngine, 0, v10, 0, 0, 0);
                              if ( hResult != 0 )
                              {
                                WriteError(hResult, "CreateLandscapeSurface");
                                return 0;
                              }
                              else
                              {
                                this->m_pCurrentLandScapeRenderTarget = this->m_pLandscapeSurface;
                                this->m_pFinalRenderSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
                                if ( this->m_pFinalRenderSurface != nullptr )
                                {
                                  v15 = GfxEngineSetup.iCurrentGfxMode == 1;
                                  if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
                                  {
                                    pDDraw = this->m_pDDraw;
                                  }
                                  else
                                  {
                                    pDDraw = this->m_pDDraw7;
                                  }
                                  v12 = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup);
                                  v11 = j__abs(v15);
                                  v8 = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup);
                                  hResult = this->m_pFinalRenderSurface->CreateSurface(this->m_pFinalRenderSurface, pDDraw, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, 1, v8, 0, v11, 0, v12, 0);
                                  if ( hResult != 0 )
                                  {
                                    WriteError(hResult, "CreateFinalRenderSurface");
                                    return 0;
                                  }
                                  else
                                  {
                                    hResult = SurfaceClipper::InitClipper(&this->m_sClipper1, this->m_pDDraw);
                                    if ( hResult != 0 )
                                    {
                                      WriteError(hResult, "CreateClipper1");
                                      return 0;
                                    }
                                    else
                                    {
                                      hResult = SurfaceClipper::InitClipper(&this->m_sMinimapClipper, this->m_pDDraw);
                                      if ( hResult != 0 )
                                      {
                                        WriteError(hResult, "Create Minimap Clipper");
                                        return 0;
                                      }
                                      else
                                      {
                                        hResult = SurfaceClipper::SetClipWindow(&this->m_sClipper1, (HWND *)GfxEngineSetup.sRenderSetup.m_hWnd);
                                        if ( hResult != 0 )
                                        {
                                          WriteError(hResult, "AssignClipper1");
                                          return 0;
                                        }
                                        else
                                        {
                                          Clipper = SurfaceClipper::GetClipper(&this->m_sClipper1);
                                          hResult = this->m_pPrimarySurface->SetClipper((CSurfaceV7 *)this->m_pPrimarySurface, Clipper);
                                          if ( hResult != 0 )
                                          {
                                            WriteError(hResult, "SetClipper1");
                                            return 0;
                                          }
                                          else
                                          {
                                            g_pDestSizeTable = g_iDestSizeTable;
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
  IDirectDrawSurface7 *pLandscapeSurface; // eax
  IDirectDrawSurface7 *pFinalRenderSurface; // eax
  struct IDirectDrawSurface7 *pDefaultLandscapeTexture; // eax
  struct IDirectDrawSurface7 *pDefaultObjectTexture; // eax
  int GradientFormat; // eax
  IDirectDrawSurface7 *v8; // eax
  IDirectDrawSurface7 *v9; // [esp+ACh] [ebp-170h]
  IDirect3DDevice7 *pObjectDevice; // [esp+B0h] [ebp-16Ch]
  IDirect3DDevice7 **v11; // [esp+B4h] [ebp-168h]
  IDirect3DDevice7 **v12; // [esp+B4h] [ebp-168h]
  DWORD v13; // [esp+C0h] [ebp-15Ch] BYREF
  CCachePageManager *pCacheManager; // [esp+C8h] [ebp-154h]
  CCachePageManager *v16; // [esp+CCh] [ebp-150h]
  BOOL v17; // [esp+D0h] [ebp-14Ch]
  CUploadCachePageManager *pUploadCachePageManager; // [esp+D4h] [ebp-148h] MAPDST
  void *C; // [esp+D8h] [ebp-144h]
  DWORD iFilterSetting; // [esp+E0h] [ebp-13Ch] MAPDST
  IDirectDraw7 *pDDraw; // [esp+ECh] [ebp-130h] MAPDST
  int Number; // [esp+F0h] [ebp-12Ch]
  int uAvailableVidMemory; // [esp+F4h] [ebp-128h] BYREF
  int v27; // [esp+F8h] [ebp-124h]
  int v28; // [esp+FCh] [ebp-120h]
  bool v30; // [esp+107h] [ebp-115h]
  int i; // [esp+108h] [ebp-114h]
  HRESULT hResult; // [esp+10Ch] [ebp-110h] MAPDST
  CSurfaceDescription v35; // [esp+114h] [ebp-108h] BYREF
  DDSCAPS2 sCaps; // [esp+1FCh] [ebp-20h] BYREF
  int exceptionBlock; // [esp+218h] [ebp-4h]

  BBSupportTracePrintF(1, "GFX ENGINE: Begin hardware init.");
  if ( this->m_bHardwareRuns != 0 || this->m_bSoftwareRuns != 0 )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: INIT HARDWARE: Engine is already initialized!");
    return 1;
  }
  CHeightAndTypeTable::InitShadeTables(&g_cHeightAndTypeTable);
  hResult = this->m_pDDraw7->lpVtbl->QueryInterface(this->m_pDDraw7, &IID_IDirect3D7, (LPVOID *)&this->m_pIDirect3D7);
  if ( hResult != 0 )
  {
    WriteError(hResult, "QueryD3DInterface");
    return 0;
  }
  CInterfaceD3D::AllocateEngineData(D3DObjectPtr, 256);
  v28 = 256;
  if ( D3DObjectPtr->m_bHiTextureQuality == 0 && SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup) )
  {
    v28 /= 2;
  }
  CInterfaceD3D::PreCalcTextureVertices(this, v28);
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
      pDDraw = this->m_pDDraw;
    }
    else
    {
      pDDraw = this->m_pDDraw7;
    }
    v2 = j__abs(Number);
    hResult = this->m_pDDTextureSurfaces[i]->CreateSurface(this->m_pDDTextureSurfaces[i], pDDraw, v28, v28, 1, 1, 1, v2, 0, 0, 0);
    if ( hResult != 0 )
    {
      WriteError(hResult, "CreateLandscapeTextureSurface");
      return 0;
    }
  }
  if ( GfxEngineSetup.bHardwareObjects != 0 )
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
        pDDraw = this->m_pDDraw;
      }
      else
      {
        pDDraw = this->m_pDDraw7;
      }
      hResult = this->m_pDDObjectSurfacePtr[i]->CreateSurface(this->m_pDDObjectSurfacePtr[i], pDDraw, 512, 512, 1, 0, 1, 2, 0, 0, 0);
      if ( hResult != 0 )
      {
        WriteError(hResult, "CreateObjectTextureSurface");
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
        pDDraw = this->m_pDDraw;
      }
      else
      {
        pDDraw = this->m_pDDraw7;
      }
      hResult = this->m_pDDSourceObjectSurfacePtr[i]->CreateSurface(this->m_pDDSourceObjectSurfacePtr[i], pDDraw, 512, 512, 0, 0, 1, 2, 0, 0, 0);
      if ( hResult != 0 )
      {
        WriteError(hResult, "CreateObjectTextureSystemMemory");
        return 0;
      }
    }
  }
  pLandscapeSurface = this->m_pLandscapeSurface->GetSurfacePtr(this->m_pLandscapeSurface);
  hResult = this->m_pIDirect3D7->CreateDevice(this->m_pIDirect3D7, &IID_IDirect3DHALDevice, pLandscapeSurface, v11);// LandscapeDevice
  if ( hResult != 0 )
  {
    WriteError(hResult, "CreateLandscapeRenderDevice");
    return 0;
  }
  pFinalRenderSurface = this->m_pFinalRenderSurface->GetSurfacePtr(this->m_pFinalRenderSurface);
  hResult = this->m_pIDirect3D7->CreateDevice(this->m_pIDirect3D7, &IID_IDirect3DHALDevice, pFinalRenderSurface, v12);// m_pObjectDevice
  if ( hResult != 0 )
  {
    WriteError(hResult, "CreateObjectRenderDevice");
    return 0;
  }
  this->m_sViewport.dwX = 0;
  this->m_sViewport.dwY = 0;
  this->m_sViewport.dwWidth = GfxEngineSetup.sRenderSetup.m_uWidth;
  this->m_sViewport.dwHeight = GfxEngineSetup.sRenderSetup.m_uHeight;
  this->m_sViewport.dvMinZ = 0.0;
  this->m_sViewport.dvMaxZ = 1.0;
  hResult = this->LandscapeDevice->SetViewport(this->LandscapeDevice, &this->m_sViewport);
  if ( hResult != 0 )
  {
    WriteError(hResult, "SetLandscapeViewport");
    return 0;
  }
  hResult = this->m_pObjectDevice->SetViewport(this->m_pObjectDevice, &this->m_sViewport);
  if ( hResult != 0 )
  {
    WriteError(hResult, "SetObjectViewport");
    return 0;
  }
  pDefaultLandscapeTexture = this->m_pDDTextureSurfaces[0]->GetSurfacePtr(this->m_pDDTextureSurfaces[0]);
  hResult = this->LandscapeDevice->SetTexture(this->LandscapeDevice, 0, pDefaultLandscapeTexture);
  if ( hResult != 0 )
  {
    WriteError(hResult, "SetDefaultLandscapeTexture");
    return 0;
  }
  hResult = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_CULLMODE, 1);
  if ( hResult != 0 )
  {
    WriteError(hResult, "SetCulling");
    return 0;
  }
  hResult = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_TEXTUREPERSPECTIVE, 0);
  if ( hResult != 0 )
  {
    WriteError(hResult, "SetTextureCorrecture");
    return 0;
  }
  hResult = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_ZENABLE, 0);
  if ( hResult != 0 )
  {
    WriteError(hResult, "DisableZBuffer");
    return 0;
  }
  hResult = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_LOCALVIEWER, 0);
  if ( hResult != 0 )
  {
    WriteError(hResult, "DisableCameraView");
    return 0;
  }
  hResult = this->LandscapeDevice->SetTextureStageState(this->LandscapeDevice, 0, D3DTSS_ADDRESS, 1);
  if ( hResult != 0 )
  {
    WriteError(hResult, "SetTextureAdressMode");
    return 0;
  }
  hResult = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_SHADEMODE, 2);
  if ( hResult != 0 )
  {
    WriteError(hResult, "SetLandscapeShading");
    return 0;
  }
  hResult = this->LandscapeDevice->SetRenderState(this->LandscapeDevice, D3DRENDERSTATE_SPECULARENABLE, 1);
  if ( hResult != 0 )
  {
    WriteError(hResult, "SetLandscapeLighting");
    return 0;
  }
  if ( GfxEngineSetup.bHardwareObjects != 0 )
  {
    InitRenderStates();
    pDefaultObjectTexture = this->m_pDDObjectSurfacePtr[0]->GetSurfacePtr(this->m_pDDObjectSurfacePtr[0]);
    hResult = this->m_pObjectDevice->SetTexture(this->m_pObjectDevice, 0, pDefaultObjectTexture);
    if ( hResult != 0 )
    {
      WriteError(hResult, "SetDefaultObjectTexture");
      return 0;
    }
    hResult = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_SHADEMODE, 1);
    if ( hResult != 0 )
    {
      WriteError(hResult, "SetObjectShading");
      return 0;
    }
    hResult = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_SPECULARENABLE, 0);
    if ( hResult != 0 )
    {
      WriteError(hResult, "SetObjectLighting");
      return 0;
    }
    hResult = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_ALPHABLENDENABLE, 1);
    if ( hResult != 0 )
    {
      WriteError(hResult, "EnableAlphaBlending");
      return 0;
    }
    hResult = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_SRCBLEND, 5);
    if ( hResult != 0 )
    {
      WriteError(hResult, "SetSourceBlend");
      return 0;
    }
    hResult = this->m_pObjectDevice->SetRenderState(this->m_pObjectDevice, D3DRENDERSTATE_DESTBLEND, 6);
    if ( hResult != 0 )
    {
      WriteError(hResult, "SetDestBlend");
      return 0;
    }
    if ( SGfxRenderConfiguration::IsFiltering(&GfxEngineSetup.sRenderSetup) )
    {
      iFilterSetting = D3DFILTER_LINEAR;
    }
    else
    {
      iFilterSetting = D3DFILTER_NEAREST;
    }
    hResult = this->m_pObjectDevice->SetTextureStageState(this->m_pObjectDevice, 0, D3DTSS_MAGFILTER, iFilterSetting);
    if ( hResult != 0 )
    {
      WriteError(hResult, "SetObjectFiltering");
      return 0;
    }
    if ( SGfxRenderConfiguration::IsFiltering(&GfxEngineSetup.sRenderSetup) )
    {
      iFilterSetting = D3DFILTER_LINEAR;
    }
    else
    {
      iFilterSetting = D3DFILTER_NEAREST;
    }
    hResult = this->m_pObjectDevice->SetTextureStageState(this->m_pObjectDevice, 0, D3DTSS_MINFILTER, iFilterSetting);
    if ( hResult != 0 )
    {
      WriteError(hResult, "SetObjectFiltering");
      return 0;
    }
    CCacheManager::Reset(&g_cCacheManager);
    for ( i = 0;
          i < 8;
          ++i )
    {
      CColorGradient::SetupGradients(&g_cColorGradient, i, g_cColorGradient.m_vPlayerColors[i + 1], 2);
    }
    g_pfBlitSettler = BlitSettlerHardware;
    g_pfBlitObject = BlitObjectHardware;
    g_pfBlitVehicle = BlitVehicleHardware;
    g_pfBlitBuilding = BlitBuildingHardware;
    g_pfBlitBorderstone = BlitBorderstoneHardware;
    g_pfBlitAccessoryIcon = BlitAccessoryIconHardware;
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
    g_pfBlitSettler = BlitSettler;
    g_pfBlitObject = BlitObject;
    g_pfBlitVehicle = BlitVehicle;
    g_pfBlitBuilding = BlitBuilding;
    g_pfBlitBorderstone = BlitBorderstone;
    g_pfBlitAccessoryIcon = BlitAccessoryIcon;
    g_pfBlitWave = BlitWave;
  }
  if ( GfxEngineSetup.bHardwareObjects != 0 )
  {
    for ( i = 0;
          i < 2;
          ++i )
    {
      C = operator new(0x9A4u);
      exceptionBlock = 0;
      if ( C != nullptr )
      {
        pObjectDevice = this->m_pObjectDevice;
        v9 = this->m_pDDSourceObjectSurfacePtr[i]->GetSurfacePtr(this->m_pDDSourceObjectSurfacePtr[i]);
        v8 = this->m_pDDObjectSurfacePtr[i]->GetSurfacePtr(this->m_pDDObjectSurfacePtr[i]);
        pUploadCachePageManager = CUploadCachePageManager::CUploadCachePageManager((CUploadCachePageManager *)C, v8, v9, pObjectDevice);
      }
      else
      {
        pUploadCachePageManager = nullptr;
      }
      exceptionBlock = -1;
      this->m_pcPictureManager[i] = pUploadCachePageManager;
      if ( this->m_pcPictureManager[i] == nullptr )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: No memory to create PictureManager");
        return 0;
      }
    }
    CCachePageManager::SetCurrentZoomFactor(this->m_pcPictureManager[0], GfxEngineSetup.fZoomFactor);
    memset(&sCaps, 0, sizeof(sCaps));
    sCaps.dwCaps = DDSCAPS_TEXTURE;
    hResult = this->m_pDDraw7->lpVtbl->GetAvailableVidMem(this->m_pDDraw7, &sCaps, &v13, (LPDWORD)&uAvailableVidMemory);
    if ( hResult != 0 )
    {
      WriteError(hResult, "GetVideoMemory");
      return 0;
    }
    v27 = uAvailableVidMemory;
    BBSupportTracePrintF(1, "GFX ENGINE: Available vid mem for cache is %d", uAvailableVidMemory);
    v27 -= 1100000;
    v27 -= 50000;
    this->m_iNumberOfCachedSurfaces = 0;
    if ( v27 > 0 )
    {
      CSurfaceDescription::CSurfaceDescription(&v35);
      v35.m_sSurfaceDescription.dwFlags = 4103;
      v35.m_sSurfaceDescription.ddsCaps.dwCaps = 20480;
      v35.m_sSurfaceDescription.dwWidth = 512;
      v35.m_sSurfaceDescription.dwHeight = 512;
      *(_QWORD *)&v35.m_sSurfaceDescription.ddpfPixelFormat.dwFlags = 65;
      *(_QWORD *)&v35.m_sSurfaceDescription.ddpfPixelFormat.dwRGBBitCount = 0xF0000000010LL;
      *(_QWORD *)&v35.m_sSurfaceDescription.ddpfPixelFormat.dwGBitMask = 0xF000000F0LL;
      v35.m_sSurfaceDescription.ddpfPixelFormat.dwRGBAlphaBitMask = 61440;
      v17 = uAvailableVidMemory != 1674288;
      v30 = uAvailableVidMemory != 1674288;
      for ( this->m_iNumberOfCachedSurfaces = j__abs(v17);
            v30 && this->m_iNumberOfCachedSurfaces < 180;
            ++this->m_iNumberOfCachedSurfaces )
      {
        hResult = this->m_pDDraw7->lpVtbl->CreateSurface(this->m_pDDraw7, (LPDDSURFACEDESC2)&v35, &this->m_pCacheSurfaces[this->m_iNumberOfCachedSurfaces], nullptr);
        v30 = true;
        if ( hResult != 0 )
        {
          if ( hResult == DDERR_OUTOFVIDEOMEMORY )
          {
            BBSupportTracePrintF(1, "GFX ENGINE: %d cache surfaces created. Running out of video mem!", this->m_iNumberOfCachedSurfaces);
            break;
          }
          WriteError(hResult, "CreateCacheSurfaces");
          return 0;
        }
        hResult = this->m_pDDraw7->lpVtbl->GetAvailableVidMem(this->m_pDDraw7, &sCaps, &v13, (LPDWORD)&uAvailableVidMemory);
        if ( hResult != 0 )
        {
          WriteError(hResult, "GetVideoMemory");
          return 0;
        }
        if ( uAvailableVidMemory == 1674288 )
        {
          v30 = false;
        }
        v16 = (CCachePageManager *)operator new(0x824u);
        exceptionBlock = 1;
        if ( v16 != nullptr )
        {
          pCacheManager = CCachePageManager::CCachePageManager(v16, this->m_pCacheSurfaces[this->m_iNumberOfCachedSurfaces], nullptr, this->m_pObjectDevice);
        }
        else
        {
          pCacheManager = nullptr;
        }
        exceptionBlock = -1;
        this->m_pCacheManagers[this->m_iNumberOfCachedSurfaces] = pCacheManager;
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
    if ( GfxEngineSetup.iCurrentGfxMode == 1 )
    {
      j__TRI_init_engine(1365);
    }
    else
    {
      j__TRI_init_engine(1381);
    }
    CHeightAndTypeTable::InitShadeTables(&g_cHeightAndTypeTable);
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
        CColorGradient::SetupGradients(&g_cColorGradient, j, g_cColorGradient.m_vPlayerColors[j + 1], GradientFormat);
      }
      CInterfaceD3D::PreCalcTextureVertices(this, 256);
      g_pfBlitSettler = BlitSettler;
      g_pfBlitObject = BlitObject;
      g_pfBlitVehicle = BlitVehicle;
      g_pfBlitBuilding = BlitBuilding;
      g_pfBlitBorderstone = BlitBorderstone;
      g_pfBlitAccessoryIcon = BlitAccessoryIcon;
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
// Decompiled from char __thiscall CInterfaceD3D::BlitSurfaceToDIB(CInterfaceD3D *this, HWND hWnd, HGDIOBJ h)
bool  CInterfaceD3D::BlitSurfaceToDIB(struct HWND__ * hWnd, struct HBITMAP__ * h) {
  
  HDC hdc; // [esp+4h] [ebp-14h]
  HDC hdcSrc; // [esp+8h] [ebp-10h] BYREF
  HRESULT hResult; // [esp+Ch] [ebp-Ch]
  HDC CompatibleDC; // [esp+10h] [ebp-8h]

  hResult = this->m_pFinalRenderSurface->GetDC(this->m_pFinalRenderSurface, &hdcSrc);
  if ( hResult == DDERR_SURFACELOST )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 1)");
    return 0;
  }
  else
  {
    if ( hResult != 0 )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 2)");
    }
    hdc = GetDC(hWnd);
    CompatibleDC = CreateCompatibleDC(hdc);
    SelectObject(CompatibleDC, h);
    if ( !BitBlt(CompatibleDC, 0, 0, GfxEngineSetup.sRenderSetup.m_uWidth, GfxEngineSetup.sRenderSetup.m_uHeight, hdcSrc, 0, 0, SRCCOPY) )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Blit to DIB failed! (Case 3)");
    }
    this->m_pFinalRenderSurface->ReleaseDC(this->m_pFinalRenderSurface, hdcSrc);
    ReleaseDC(hWnd, hdc);
    DeleteDC(CompatibleDC);
    return 1;
  }
}


// address=[0x2f668c0]
// Decompiled from char __thiscall CInterfaceD3D::BlitSurfaceToWindow(CInterfaceD3D *this)
bool  CInterfaceD3D::BlitSurfaceToWindow(void) {
  
  _DDBLTFX *BlitStructPtr; // eax
  _DDBLTFX *v3; // eax
  int surfaceWidth; // [esp+0h] [ebp-5Ch] BYREF
  int surfaceHeight; // [esp+4h] [ebp-58h] BYREF
  HRESULT hResult; // [esp+Ch] [ebp-50h] MAPDST
  int v8; // [esp+10h] [ebp-4Ch]
  tagRECT v10; // [esp+18h] [ebp-44h] BYREF
  tagRECT v11; // [esp+28h] [ebp-34h] BYREF
  tagRECT sMiniMapSize; // [esp+38h] [ebp-24h] BYREF
  tagRECT sMiniMapRect; // [esp+48h] [ebp-14h] BYREF

  hResult = 0;
  if ( SGfxRenderConfiguration::IsEditorMode(&GfxEngineSetup.sRenderSetup) )
  {
    if ( this->m_pDDGuiSurfaces[0] != nullptr && this->m_pPrimarySurface != nullptr )
    {
      v11.left = GfxEngineSetup.sRenderSetup.m_uX;
      v11.top = GfxEngineSetup.sRenderSetup.m_uY;
      v11.right = GfxEngineSetup.sRenderSetup.m_uWidth + GfxEngineSetup.sRenderSetup.m_uX;
      v11.bottom = GfxEngineSetup.sRenderSetup.m_uHeight + GfxEngineSetup.sRenderSetup.m_uY;
      BlitStructPtr = CBlitFX::GetBlitStructPtr(&g_cBlitFX);
      hResult = this->m_pPrimarySurface->Blt(this->m_pPrimarySurface, &v11, this->m_pDDGuiSurfaces[0], nullptr, 512, BlitStructPtr);
    }
    if ( GfxEngineSetup.bDrawMiniMap != 0 && this->m_pMiniMapAreaSurface != nullptr && this->m_pPrimarySurface != nullptr )
    {
      hResult = -1;
      sMiniMapRect = g_sMiniMapRect;
      sMiniMapSize = g_sMiniMapSize;
      D3DObjectPtr->m_pPrimarySurface->GetSurfaceSize(D3DObjectPtr->m_pPrimarySurface, &surfaceWidth, &surfaceHeight);
      sMiniMapSize.right -= sMiniMapSize.left;
      sMiniMapSize.bottom -= sMiniMapSize.top;
      sMiniMapSize.left = 0;
      sMiniMapSize.top = 0;
      if ( sMiniMapRect.bottom > surfaceHeight )
      {
        v8 = sMiniMapRect.bottom - surfaceHeight;
        sMiniMapRect.bottom = surfaceHeight;
        sMiniMapSize.bottom -= v8;
      }
      if ( sMiniMapRect.right > surfaceWidth )
      {
        v8 = sMiniMapRect.right - surfaceWidth;
        sMiniMapRect.right = surfaceWidth;
        sMiniMapSize.right -= v8;
      }
      if ( sMiniMapRect.top < 0 )
      {
        v8 = abs(sMiniMapRect.top);
        sMiniMapRect.top += v8;
        sMiniMapSize.top += v8;
      }
      if ( sMiniMapRect.left < 0 )
      {
        v8 = abs(sMiniMapRect.left);
        sMiniMapRect.left += v8;
        sMiniMapSize.left += v8;
      }
      if ( sMiniMapRect.top <= surfaceHeight || sMiniMapRect.left <= surfaceWidth )
      {
        hResult = CInterfaceD3D::SetCustomClipper(this, &this->m_sMinimapClipper);
        if ( hResult != 0 )
        {
          WriteError(hResult, "SetClipper2");
          return 0;
        }
        hResult = D3DObjectPtr->m_pPrimarySurface->Blt(D3DObjectPtr->m_pPrimarySurface, &sMiniMapRect, D3DObjectPtr->m_pMiniMapSurface, &sMiniMapSize, 0x8000, nullptr);
        if ( hResult == 0 )
        {
          hResult = D3DObjectPtr->m_pPrimarySurface->Blt(D3DObjectPtr->m_pPrimarySurface, &sMiniMapRect, D3DObjectPtr->m_pMiniMapAreaSurface, &sMiniMapSize, 0x8000, nullptr);
        }
      }
      hResult = CInterfaceD3D::ClearCustomClipper(this);
      if ( hResult != 0 )
      {
        WriteError(hResult, "SetClipper1");
        return 0;
      }
    }
  }
  else if ( this->m_pFinalRenderSurface != nullptr && this->m_pPrimarySurface != nullptr )
  {
    v10.left = GfxEngineSetup.sRenderSetup.m_uX;
    v10.top = GfxEngineSetup.sRenderSetup.m_uY;
    v10.right = GfxEngineSetup.sRenderSetup.m_uWidth + GfxEngineSetup.sRenderSetup.m_uX;
    v10.bottom = GfxEngineSetup.sRenderSetup.m_uHeight + GfxEngineSetup.sRenderSetup.m_uY;
    v3 = CBlitFX::GetBlitStructPtr(&g_cBlitFX);
    hResult = this->m_pPrimarySurface->Blt(this->m_pPrimarySurface, &v10, this->m_pFinalRenderSurface, nullptr, 512, v3);
  }
  switch ( hResult )
  {
    case 0:
      return 1;
    case -2005532222:
      hResult = this->m_pPrimarySurface->Restore((CSurfaceV7 *)this->m_pPrimarySurface);
      if ( hResult != 0 )
      {
        WriteError(hResult, "RestorePrimarySurface");
      }
      if ( hResult == -2005532085 )
      {
        BBSupportTracePrintF(1, "GFX ENGINE: Stop rendering because of inaccessability of primary surface!");
        this->m_bDisableRendering = 1;
      }
      break;
    case -2005532447:
      WriteError(DDERR_NOEXCLUSIVEMODE, "Exclusive mode down! Stop rendering...");
      this->m_bDisableRendering = 1;
      break;
    default:
      WriteError(hResult, "PrimarySurfaceBlit");
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
  
  if ( this->m_bHardwareRuns != 0 )
  {
    return 2;
  }
  else
  {
    return GfxEngineSetup.iCurrentGfxMode == 1;
  }
}


// address=[0x2f66e00]
// Decompiled from int __stdcall CInterfaceD3D::EnumModesCallback(struct _DDSURFACEDESC2 *a1, void *a2)
long __stdcall CInterfaceD3D::EnumModesCallback(struct _DDSURFACEDESC2 * a1, void * a2) {
  
  if ( a1 == nullptr )
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
// Decompiled from int __stdcall CInterfaceD3D::EnumModesCallbackOld(_DDSURFACEDESC *a1, int a2)
long __stdcall CInterfaceD3D::EnumModesCallbackOld(struct _DDSURFACEDESC * a1, void * a2) {
  
  if ( a1 == nullptr )
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


// address=[0x2f67080]
// Decompiled from char __thiscall CInterfaceD3D::LoadTexturePageContents(CInterfaceD3D *this)
bool  CInterfaceD3D::LoadTexturePageContents(void) {
  
  bool IsHardwareLandscapeEngine; // al
  char m_bHiTextureQuality; // [esp-Ch] [ebp-18h]
  bool v4; // [esp-8h] [ebp-14h]
  int i; // [esp+4h] [ebp-8h]

  BBSupportTracePrintF(1, "GFX ENGINE: Read in all texture pages...");
  if ( !SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup) )
  {
    D3DObjectPtr->m_bHiTextureQuality = 1;
  }
  if ( D3DObjectPtr == nullptr )
  {
    return 1;
  }
  v4 = GfxEngineSetup.iCurrentGfxMode == 1;
  m_bHiTextureQuality = D3DObjectPtr->m_bHiTextureQuality;
  IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup);
  if ( ReadTextureBitmapSet(IsHardwareLandscapeEngine, m_bHiTextureQuality, v4, 44) == 0 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: Error while loading texture set!");
    return 0;
  }
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup) )
  {
    return 1;
  }
  BBSupportTracePrintF(1, "GFX ENGINE: Begin set up luminance tables.");
  for ( i = 0;
        i < 44;
        ++i )
  {
    j__TRI_calculate_LUT_from_palette(g_uColorPalettes[i], &g_pLuminanceTablesStart[2048 * i]);
  }
  BBSupportTracePrintF(1, "GFX ENGINE: End set up luminance tables.");
  return 1;
}


// address=[0x2f67190]
// Decompiled from void __thiscall CInterfaceD3D::SetupViewport(CInterfaceD3D *this, DWORD a2, DWORD a3, DWORD a4, DWORD a5)
void  CInterfaceD3D::SetupViewport(int a2, int a3, int a4, int a5) {
  
  int v5; // [esp+0h] [ebp-8h]
  int v6; // [esp+0h] [ebp-8h]

  this->m_sViewport.dwX = a2;
  this->m_sViewport.dwY = a3;
  this->m_sViewport.dwWidth = a4;
  this->m_sViewport.dwHeight = a5;
  if ( this->LandscapeDevice != nullptr )
  {
    v5 = this->LandscapeDevice->SetViewport(this->LandscapeDevice, &this->m_sViewport);
    if ( v5 != 0 )
    {
      WriteError(v5, "SetLandscapeViewport");
    }
    else if ( this->m_pObjectDevice != nullptr )
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
  
  int Clipper; // eax

  if ( SurfaceClipper::GetClipper(a2) == 0 )
  {
    j___wassert(L"clipper.GetClipper() != nullptr", L"MainGfxManager.cpp", 0x90Fu);
  }
  Clipper = SurfaceClipper::GetClipper(a2);
  return this->m_pFinalRenderSurface->SetClipper(this->m_pFinalRenderSurface, Clipper);
}


// address=[0x2f672a0]
// Decompiled from int __thiscall CInterfaceD3D::ClearCustomClipper(CInterfaceD3D *this)
long  CInterfaceD3D::ClearCustomClipper(void) {
  
  int Clipper; // eax

  Clipper = SurfaceClipper::GetClipper(&this->m_sClipper1);
  return this->m_pFinalRenderSurface->SetClipper(this->m_pFinalRenderSurface, Clipper);
}


// address=[0x2f672d0]
// Decompiled from void __thiscall CInterfaceD3D::DeleteEngineData(CInterfaceD3D *this)
void  CInterfaceD3D::DeleteEngineData(void) {
  
  if ( this->D3DVertexPtr != nullptr )
  {
    operator delete[](this->D3DVertexPtr);
    this->D3DVertexPtr = nullptr;
    g_pVertexMax = nullptr;
    g_pVertex = nullptr;
  }
  if ( g_pLuminanceTablesMemory != nullptr )
  {
    operator delete[](g_pLuminanceTablesMemory);
    g_pLuminanceTablesMemory = nullptr;
    g_pLuminanceTablesStart = nullptr;
  }
}


// address=[0x2f67350]
// Decompiled from int __thiscall CInterfaceD3D::BeginLandscapeScene(CInterfaceD3D *this)
long  CInterfaceD3D::BeginLandscapeScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = -1;
  if ( this->m_iLandscapeSceneLock != 0 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 0", this->m_iLandscapeSceneLock);
  }
  else
  {
    v2 = this->LandscapeDevice->BeginScene(this->LandscapeDevice);
    if ( v2 != 0 )
    {
      WriteError(v2, "BeginLandscapeScene");
    }
    ++this->m_iLandscapeSceneLock;
  }
  return v2;
}


// address=[0x2f673e0]
// Decompiled from int __thiscall CInterfaceD3D::EndLandscapeScene(CInterfaceD3D *this)
long  CInterfaceD3D::EndLandscapeScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  if ( this->m_iLandscapeSceneLock > 1 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 1", this->m_iLandscapeSceneLock);
  }
  v2 = this->LandscapeDevice->EndScene(this->LandscapeDevice);
  if ( v2 != 0 )
  {
    WriteError(v2, "EndLandscapeScene");
  }
  --this->m_iLandscapeSceneLock;
  return v2;
}


// address=[0x2f67460]
// Decompiled from int __thiscall CInterfaceD3D::BeginObjectScene(CInterfaceD3D *this)
long  CInterfaceD3D::BeginObjectScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  v2 = -1;
  if ( this->m_iObjectSceneLock != 0 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: ObjectScene Lockcounter is %d instead of 0", this->m_iObjectSceneLock);
  }
  else
  {
    v2 = this->m_pObjectDevice->BeginScene(this->m_pObjectDevice);
    if ( v2 != 0 )
    {
      WriteError(v2, "BeginObjectScene");
    }
    ++this->m_iObjectSceneLock;
  }
  return v2;
}


// address=[0x2f674f0]
// Decompiled from int __thiscall CInterfaceD3D::EndObjectScene(CInterfaceD3D *this)
long  CInterfaceD3D::EndObjectScene(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  if ( this->m_iObjectSceneLock > 1 )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: WARNING: LandscapeScene Lockcounter is %d instead of 1", this->m_iObjectSceneLock);
  }
  v2 = this->m_pObjectDevice->EndScene(this->m_pObjectDevice);
  if ( v2 != 0 )
  {
    WriteError(v2, "EndObjectScene");
  }
  --this->m_iObjectSceneLock;
  return v2;
}


// address=[0x2f67570]
// Decompiled from char __thiscall CInterfaceD3D::CreateCameraWindowSurface(CInterfaceD3D *this, int a2, int a3)
bool  CInterfaceD3D::CreateCameraWindowSurface(int a2, int a3) {
  
  bool IsHardwareLandscapeEngine; // al
  int v5; // [esp-10h] [ebp-20h]
  int hResult; // [esp+0h] [ebp-10h]
  IDirectDraw7 *pDDraw; // [esp+4h] [ebp-Ch]

  CInterfaceD3D::DestroyCameraWindowSurface(this);
  this->m_pLandscapeCameraRenderSurface = CSurface::CreateSurfacePtr(GfxEngineSetup.sRenderSetup.m_bUseDD3Interface);
  if ( this->m_pLandscapeCameraRenderSurface != nullptr )
  {
    if ( GfxEngineSetup.sRenderSetup.m_bUseDD3Interface )
    {
      pDDraw = this->m_pDDraw;
    }
    else
    {
      pDDraw = this->m_pDDraw7;
    }
    v5 = j__abs(GfxEngineSetup.iCurrentGfxMode == 1);
    IsHardwareLandscapeEngine = SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup);
    hResult = this->m_pLandscapeCameraRenderSurface->CreateSurface(this->m_pLandscapeCameraRenderSurface, pDDraw, a2, a3, 1, IsHardwareLandscapeEngine, 0, v5, 0, 0, 0);
    if ( hResult != 0 )
    {
      WriteError(hResult, "CreateLandscapeSurface");
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
// Decompiled from void __thiscall CInterfaceD3D::DestroyCameraWindowSurface(CInterfaceD3D *this)
void  CInterfaceD3D::DestroyCameraWindowSurface(void) {
  
  if ( this->m_pLandscapeCameraRenderSurface != nullptr )
  {
    if ( this->m_pCurrentLandScapeRenderTarget == this->m_pLandscapeCameraRenderSurface )
    {
      j___wassert(L"m_pCurrentLandScapeRenderTarget != m_pLandscapeCameraRenderSurface", L"MainGfxManager.cpp", 0x9D2u);
    }
    this->m_pLandscapeCameraRenderSurface->Release(this->m_pLandscapeCameraRenderSurface);
    if ( this->m_pLandscapeCameraRenderSurface != nullptr )
    {
      this->m_pLandscapeCameraRenderSurface->dtor(this->m_pLandscapeCameraRenderSurface, 1);
    }
    this->m_pLandscapeCameraRenderSurface = nullptr;
  }
}


// address=[0x2f676f0]
// Decompiled from int __thiscall CInterfaceD3D::SwitchLandscapeRenderTarget(CInterfaceD3D *this, bool a2)
long  CInterfaceD3D::SwitchLandscapeRenderTarget(bool a2) {
  
  int hResult; // [esp+0h] [ebp-10h]
  CSurface *renderTarget; // [esp+4h] [ebp-Ch]

  if ( a2 )
  {
    renderTarget = this->m_pLandscapeCameraRenderSurface;
  }
  else
  {
    renderTarget = this->m_pLandscapeSurface;
  }
  if ( renderTarget == nullptr )
  {
    j___wassert(L"renderTarget != nullptr", L"MainGfxManager.cpp", 0x9DDu);
  }
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup) )
  {
    hResult = renderTarget->SetAsRenderTarget(renderTarget, this->LandscapeDevice);
    if ( hResult < 0 )
    {
      return hResult;
    }
  }
  this->m_pCurrentLandScapeRenderTarget = renderTarget;
  return 0;
}


// address=[0x2f74fc0]
// Decompiled from int __thiscall CInterfaceD3D::GetGuiMemorySize(CInterfaceD3D *this)
int  CInterfaceD3D::GetGuiMemorySize(void) {
  
  return this->m_iGuiSurfaceSize;
}


// address=[0x2f74fe0]
// Decompiled from void __thiscall CInterfaceD3D::SetGuiMemorySize(CInterfaceD3D *this, int a2)
void  CInterfaceD3D::SetGuiMemorySize(int a2) {
  
  this->m_iGuiSurfaceSize = a2;
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
    this->m_pDDTextureSurfaces[j] = nullptr;
  }
}


// address=[0x2f82050]
// Decompiled from void __thiscall CInterfaceD3D::PreCalcTextureVertices(CInterfaceD3D *this, int a2)
void  CInterfaceD3D::PreCalcTextureVertices(int a2) {
  
  float fOffset; // [esp+10h] [ebp-74h]
  int k; // [esp+14h] [ebp-70h]
  int i; // [esp+18h] [ebp-6Ch]
  int j; // [esp+1Ch] [ebp-68h]
  D3DTLVERTEX a1[3]; // [esp+20h] [ebp-64h] BYREF

  fOffset = 0.001953125;
  if ( !SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup) )
  {
    fOffset = 0.0;
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
        _vec_ctor_no(a1, 0x20u, 3u, (void *(__thiscall *)(void *))_D3DTLVERTEX::_D3DTLVERTEX);
        sub_2F7BC20(a1, (float)j, (float)i, k);
        PatternTripleVertices[j][i][k].tu1 = a1[0].tu + fOffset;
        PatternTripleVertices[j][i][k].tv1 = a1[0].tv + fOffset;
        PatternTripleVertices[j][i][k].tu2 = a1[1].tu + fOffset;
        PatternTripleVertices[j][i][k].tv2 = a1[1].tv + fOffset;
        PatternTripleVertices[j][i][k].tu3 = a1[2].tu + fOffset;
        PatternTripleVertices[j][i][k].tv3 = a1[2].tv + fOffset;
      }
    }
  }
}


// address=[0x2f82260]
// Decompiled from int __thiscall CInterfaceD3D::InitTexturePtr(CInterfaceD3D *this)
void  CInterfaceD3D::InitTexturePtr(void) {
  
  g_iLastUsedPage = 0;
  CurrentTexturePagePtr = g_pTextureTable[0];
  *(_DWORD *)j__TRI_palette_LUT = g_pLuminanceTablesStart;
  return 0;
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
// Decompiled from void __thiscall CInterfaceD3D::CalcTilingVerticesType2(CInterfaceD3D *this, int _LandscapeType)
void  CInterfaceD3D::CalcTilingVerticesType2(int _LandscapeType) {
  
  float v2; // [esp+4h] [ebp-8h]
  float v3; // [esp+8h] [ebp-4h]

  CInterfaceD3D::ChangeCurrentTexturePage(this, s_iDarkTribeElement + TEXTURE_PAGE_MAP[_LandscapeType]);
  v3 = g_fPatternSuboffsetX + 0.1875;
  v2 = g_fPatternSuboffsetX;
  if ( (float)(g_fPatternSuboffsetX + 0.1875) > 1.0 )
  {
    if ( g_bHalfLine != 0 )
    {
      v3 = v3 - 1.0;
      v2 = g_fPatternSuboffsetX - 1.0;
    }
    else
    {
      v3 = flt_3E2E708 + 1.0;
      g_bSplitTriangle = 1;
    }
  }
  g_pVertex->tu = v3;
  g_pVertex->tv = g_fPatternSuboffsetY;
  ++g_pVertex;
  g_pVertex->tu = v2 + 0.125;
  g_pVertex->tv = g_fPatternSuboffsetY + 0.125;
  ++g_pVertex;
  g_pVertex->tu = v2 + 0.0625;
  g_pVertex->tv = g_fPatternSuboffsetY;
  g_pVertex -= 2;
}


// address=[0x2f82540]
// Decompiled from int __thiscall CInterfaceD3D::AllocateEngineData(CInterfaceD3D *this, signed int _iVertexCount)
int  CInterfaceD3D::AllocateEngineData(int _iVertexCount) {
  
  _D3DTLVERTEX *v3; // [esp+10h] [ebp-20h]
  _D3DTLVERTEX *v4; // [esp+18h] [ebp-18h]
  signed int i; // [esp+1Ch] [ebp-14h]

  if ( this->D3DVertexPtr != nullptr )
  {
    CInterfaceD3D::DeleteEngineData(this);
  }
  v4 = (_D3DTLVERTEX *)operator new[](32 * _iVertexCount);
  if ( v4 != nullptr )
  {
    _vec_ctor_no(v4, 0x20u, _iVertexCount, (void *(__thiscall *)(void *))_D3DTLVERTEX::_D3DTLVERTEX);
    v3 = v4;
  }
  else
  {
    v3 = nullptr;
  }
  this->D3DVertexPtr = v3;
  if ( this->D3DVertexPtr == nullptr )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: Not enough memory to allocate vertices");
    return 0;
  }
  for ( i = 0;
        i < _iVertexCount;
        ++i )
  {
    this->D3DVertexPtr[i].sz = 0.89999998;
    this->D3DVertexPtr[i].rhw = 0.5;
  }
  if ( this->D3DVertexPtr != nullptr )
  {
    g_pVertexMax = this->D3DVertexPtr + 240;    // Why even bother with _iVertexCount, if it's hardcoded to 240 here?
  }
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup) )
  {
    return 1;
  }
  g_pLuminanceTablesMemory = (unsigned __int8 *)operator new[](0x16800u);
  if ( g_pLuminanceTablesMemory == nullptr )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: Not enough memory to allocate luminance tables!");
    g_pLuminanceTablesStart = nullptr;
    return 0;
  }
  g_pLuminanceTablesStart = (unsigned __int8 *)((unsigned int)(g_pLuminanceTablesMemory + 2047) & 0xFFFFF800);
  return 1;
}


// address=[0x2f85f40]
// Decompiled from void __thiscall CInterfaceD3D::ChangeCurrentTexturePage(CInterfaceD3D *this, int a2)
void  CInterfaceD3D::ChangeCurrentTexturePage(int a2) {
  
  struct IDirectDrawSurface7 *v2; // eax

  if ( a2 != g_iLastUsedPage )
  {
    CInterfaceD3D::RenderScene(this, s_bDirtyVertexBuffer);
    g_iLastUsedPage = a2;
    if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup) )
    {
      v2 = this->m_pDDTextureSurfaces[g_iLastUsedPage]->GetSurfacePtr(this->m_pDDTextureSurfaces[g_iLastUsedPage]);
      this->LandscapeDevice->SetTexture(this->LandscapeDevice, 0, v2);
    }
    else
    {
      CurrentTexturePagePtr = g_pTextureTable[g_iLastUsedPage];
      *(_DWORD *)j__TRI_palette_LUT = &g_pLuminanceTablesStart[2048 * g_iLastUsedPage];
    }
  }
}


// address=[0x2f860c0]
// Decompiled from CSurface *__thiscall CInterfaceD3D::GetLandscapeRenderTargetSurface(CInterfaceD3D *this)
class CSurface *  CInterfaceD3D::GetLandscapeRenderTargetSurface(void) {
  
  return this->m_pCurrentLandScapeRenderTarget;
}


// address=[0x2f86180]
// Decompiled from void __thiscall CInterfaceD3D::RenderScene(CInterfaceD3D *this, bool _bCleanVertexBuffer)
void  CInterfaceD3D::RenderScene(bool _bCleanVertexBuffer) {
  
  int v2; // [esp+0h] [ebp-10h]
  _D3DTLVERTEX *pVertex; // [esp+4h] [ebp-Ch]
  _D3DTLVERTEX *i; // [esp+Ch] [ebp-4h]

  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup.sRenderSetup) )
  {
    if ( g_pVertex - this->D3DVertexPtr > 0 )
    {
      if ( _bCleanVertexBuffer )
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
  IDirectDrawSurface7 *v5; // eax
  IDirect3DDevice7 **v6; // [esp+0h] [ebp-2B8h]
  int v7; // [esp+10h] [ebp-2A8h]
  int v8; // [esp+14h] [ebp-2A4h] BYREF
  int v9; // [esp+18h] [ebp-2A0h] BYREF
  HRESULT (__stdcall *DirectDrawCreateEx)(GUID *, LPVOID *, const IID *const, IUnknown *); // [esp+1Ch] [ebp-29Ch] MAPDST
  BOOL v11; // [esp+20h] [ebp-298h]
  int v12; // [esp+24h] [ebp-294h] BYREF
  IDirectDraw7 *pDDraw; // [esp+28h] [ebp-290h]
  HMODULE hModule; // [esp+30h] [ebp-288h]
  CSurface *m_pTmpSurface; // [esp+34h] [ebp-284h]
  CSurface *m_pPrimarySurface; // [esp+38h] [ebp-280h]
  STextureFormats vPixelFormats; // [esp+3Ch] [ebp-27Ch] BYREF
  unsigned __int8 v19; // [esp+43h] [ebp-275h] BYREF
  HRESULT hResult; // [esp+44h] [ebp-274h]
  DDCAPS v22; // [esp+4Ch] [ebp-26Ch] BYREF
  D3DDEVICEDESC7 sHardwareCapabilitys; // [esp+1C8h] [ebp-F0h] BYREF

  *_rSuccess = false;
  s_bDeviceIdentified = 0;
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
              s_bDeviceIdentified = 1;
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
                    pDDraw = this->m_pDDraw;
                  }
                  else
                  {
                    pDDraw = this->m_pDDraw7;
                  }
                  hResult = this->m_pPrimarySurface->CreateSurface(this->m_pPrimarySurface, pDDraw, 0, 0, 1, 0, 0, 0, 1, 0, 0);
                  if ( hResult != 0 )
                  {
                    CInterfaceD3D::CleanUpCheckObjects(this);
                    WriteError(hResult, "CreatePrimarySurface");
                    return 8;
                  }
                  else
                  {
                    hResult = this->m_pPrimarySurface->GetPixelFormat(this->m_pPrimarySurface, &v19);
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
                        v4 = j__abs(v19);
                        hResult = this->m_pTmpSurface->CreateSurface(this->m_pTmpSurface, this->m_pDDraw7, 32, 32, 1, 1, 0, v4, 0, 0, 0);
                        if ( hResult != 0 )
                        {
                          CInterfaceD3D::CleanUpCheckObjects(this);
                          WriteError(hResult, "CreateTestSurface");
                          return 7;
                        }
                        else
                        {
                          v12 = 16;
                          hResult = this->m_pPrimarySurface->GetBitDepth((CSurfaceV7 *)this->m_pPrimarySurface, &v12);
                          if ( hResult != 0 )
                          {
                            CInterfaceD3D::CleanUpCheckObjects(this);
                            WriteError(hResult, "GetBitDepthWhileCapChecking");
                            return 12;
                          }
                          else
                          {
                            hResult = this->m_pPrimarySurface->GetSurfaceSize(this->m_pPrimarySurface, &v9, &v8);
                            if ( hResult != 0 )
                            {
                              CInterfaceD3D::CleanUpCheckObjects(this);
                              WriteError(hResult, "GetSurfaceSizeWhileCapChecking");
                              return 11;
                            }
                            else
                            {
                              v7 = v12 / 8 * v8 * v9;
                              v22.dwSize = 380;
                              hResult = this->m_pDDraw->lpVtbl->GetCaps(this->m_pDDraw, &v22, nullptr);
                              if ( hResult != 0 )
                              {
                                CInterfaceD3D::CleanUpCheckObjects(this);
                                WriteError(hResult, "GetCapabilities");
                                return 11;
                              }
                              else if ( !sub_2F8BE40(v22.dwVidMemTotal, v7, 0x7A1200u) )
                              {
                                CInterfaceD3D::CleanUpCheckObjects(this);
                                BBSupportTracePrintF(1, "GFX ENGINE: Not enough video memory available!");
                                return 13;
                              }
                              else if ( ((v22.dwCaps & 0x40) == 0 || (v22.dwCaps & 0x4000000) == 0) && ((v22.dwNLVBCaps & 0x40) == 0 || (v22.dwNLVBCaps & 0x4000000) == 0) )
                              {
                                CInterfaceD3D::CleanUpCheckObjects(this);
                                BBSupportTracePrintF(1, "GFX ENGINE: Needed blit capabilities are not supported!");
                                return 14;
                              }
                              else if ( (v22.dwCaps & 0x400000) == 0 )
                              {
                                CInterfaceD3D::CleanUpCheckObjects(this);
                                BBSupportTracePrintF(1, "GFX ENGINE: Color keying is not in all needed blit modes available!");
                                return 15;
                              }
                              else
                              {
                                v5 = this->m_pTmpSurface->GetSurfacePtr(this->m_pTmpSurface);
                                hResult = this->m_pIDirect3D7->CreateDevice(this->m_pIDirect3D7, &IID_IDirect3DHALDevice, v5, v6);// v6 = CInterfaceD3D.LandscapeDevice
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
                                    v11 = sHardwareCapabilitys.dwMaxTextureWidth >= 0x200;
                                    *_rSuccess = v11;
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
                                            this->m_pPrimarySurface->Release(this->m_pPrimarySurface);
                                            m_pPrimarySurface = this->m_pPrimarySurface;
                                            if ( m_pPrimarySurface != nullptr )
                                            {
                                              m_pPrimarySurface->dtor(m_pPrimarySurface, 1);
                                            }
                                            this->m_pPrimarySurface = nullptr;
                                          }
                                          if ( this->m_pTmpSurface != nullptr )
                                          {
                                            this->m_pTmpSurface->Release(this->m_pTmpSurface);
                                            m_pTmpSurface = this->m_pTmpSurface;
                                            if ( m_pTmpSurface != nullptr )
                                            {
                                              m_pTmpSurface->dtor(m_pTmpSurface, 1);
                                            }
                                            this->m_pTmpSurface = nullptr;
                                          }
                                          if ( this->m_pIDirect3D7 != nullptr )
                                          {
                                            this->m_pIDirect3D7->Release(this->m_pIDirect3D7);
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
  CSurface *m_pTmpSurface; // [esp+20h] [ebp-194h]
  CSurface *m_pPrimarySurface; // [esp+24h] [ebp-190h]
  unsigned __int8 v10; // [esp+2Bh] [ebp-189h] BYREF
  HRESULT v11; // [esp+2Ch] [ebp-188h]
  DDCAPS v13; // [esp+34h] [ebp-180h] BYREF

  s_bDeviceIdentified = 0;
  if ( g_pDirectDraw != nullptr )
  {
    BBSupportTracePrintF(1, "GFX ENGINE: DirectDraw already loaded");
    return 3;
  }
  else
  {
    v11 = DirectDrawCreate(nullptr, (LPDIRECTDRAW *)&this->m_pDDraw, nullptr);
    if ( v11 != 0 )
    {
      WriteError(v11, "CreateDirectDrawObject");
      return 3;
    }
    else
    {
      g_pDirectDraw = this->m_pDDraw;
      v11 = this->m_pDDraw->lpVtbl->SetCooperativeLevel(this->m_pDDraw, a2, 8);
      if ( v11 != 0 )
      {
        CInterfaceD3D::CleanUpCheckObjects(this);
        WriteError(v11, "SetCooperativeLevel");
        return 5;
      }
      else
      {
        this->m_pPrimarySurface = CSurface::CreateSurfacePtr(true);
        if ( this->m_pPrimarySurface != nullptr )
        {
          v11 = this->m_pPrimarySurface->CreateSurface(this->m_pPrimarySurface, this->m_pDDraw, 0, 0, 1, 0, 0, 0, 1, 0, 0);
          if ( v11 != 0 )
          {
            CInterfaceD3D::CleanUpCheckObjects(this);
            WriteError(v11, "CreatePrimarySurface");
            return 8;
          }
          else
          {
            v11 = this->m_pPrimarySurface->GetPixelFormat(this->m_pPrimarySurface, &v10);
            if ( v11 != 0 )
            {
              CInterfaceD3D::CleanUpCheckObjects(this);
              WriteError(v11, "RetrievePixelFormatFromPrimarySurface");
              return 9;
            }
            else
            {
              this->m_pTmpSurface = CSurface::CreateSurfacePtr(true);
              if ( this->m_pTmpSurface != nullptr )
              {
                v3 = j__abs(v10);
                v11 = this->m_pTmpSurface->CreateSurface(this->m_pTmpSurface, this->m_pDDraw, 32, 32, 1, 1, 0, v3, 0, 0, 0);
                if ( v11 != 0 )
                {
                  CInterfaceD3D::CleanUpCheckObjects(this);
                  WriteError(v11, "CreateTestSurface");
                  return 7;
                }
                else
                {
                  v7 = 16;
                  v11 = this->m_pPrimarySurface->GetBitDepth(this->m_pPrimarySurface, &v7);
                  if ( v11 != 0 )
                  {
                    CInterfaceD3D::CleanUpCheckObjects(this);
                    WriteError(v11, "GetBitDepthWhileCapChecking");
                    return 12;
                  }
                  else
                  {
                    v11 = this->m_pPrimarySurface->GetSurfaceSize(this->m_pPrimarySurface, &v6, &v5);
                    if ( v11 != 0 )
                    {
                      CInterfaceD3D::CleanUpCheckObjects(this);
                      WriteError(v11, "GetSurfaceSizeWhileCapChecking");
                      return 12;
                    }
                    else
                    {
                      v4 = v7 / 8 * v5 * v6;
                      v13.dwSize = 380;
                      v11 = this->m_pDDraw->lpVtbl->GetCaps(this->m_pDDraw, &v13, nullptr);
                      if ( v11 != 0 )
                      {
                        CInterfaceD3D::CleanUpCheckObjects(this);
                        WriteError(v11, "GetCapabilities");
                        return 11;
                      }
                      else if ( sub_2F8BE40(v13.dwVidMemTotal, v4, 0x3D0900u) )
                      {
                        if ( (v13.dwCaps & 0x40) != 0 && (v13.dwCaps & 0x4000000) != 0 || (v13.dwNLVBCaps & 0x40) != 0 && (v13.dwNLVBCaps & 0x4000000) != 0 )
                        {
                          if ( (v13.dwCaps & 0x400000) != 0 )
                          {
                            if ( this->LandscapeDevice != nullptr )
                            {
                              this->LandscapeDevice->Release(this->LandscapeDevice);
                              this->LandscapeDevice = nullptr;
                            }
                            if ( this->m_pPrimarySurface != nullptr )
                            {
                              this->m_pPrimarySurface->Release(this->m_pPrimarySurface);
                              m_pPrimarySurface = this->m_pPrimarySurface;
                              if ( m_pPrimarySurface != nullptr )
                              {
                                m_pPrimarySurface->dtor(m_pPrimarySurface, 1);
                              }
                              this->m_pPrimarySurface = nullptr;
                            }
                            if ( this->m_pTmpSurface != nullptr )
                            {
                              this->m_pTmpSurface->Release(this->m_pTmpSurface);
                              m_pTmpSurface = this->m_pTmpSurface;
                              if ( m_pTmpSurface != nullptr )
                              {
                                m_pTmpSurface->dtor(m_pTmpSurface, 1);
                              }
                              this->m_pTmpSurface = nullptr;
                            }
                            if ( this->m_pIDirect3D7 != nullptr )
                            {
                              this->m_pIDirect3D7->Release(this->m_pIDirect3D7);
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
                          else
                          {
                            CInterfaceD3D::CleanUpCheckObjects(this);
                            BBSupportTracePrintF(1, "GFX ENGINE: Color keying is not in all needed blit modes available!");
                            return 15;
                          }
                        }
                        else
                        {
                          CInterfaceD3D::CleanUpCheckObjects(this);
                          BBSupportTracePrintF(1, "GFX ENGINE: Needed blit capabilities are not supported!");
                          return 14;
                        }
                      }
                      else
                      {
                        CInterfaceD3D::CleanUpCheckObjects(this);
                        BBSupportTracePrintF(1, "GFX ENGINE: Not enough video memory available!");
                        return 13;
                      }
                    }
                  }
                }
              }
              else
              {
                CInterfaceD3D::CleanUpCheckObjects(this);
                BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
                return 10;
              }
            }
          }
        }
        else
        {
          CInterfaceD3D::CleanUpCheckObjects(this);
          BBSupportTracePrintF(1, "GFX ENGINE: Not enough memory to create surface object!");
          return 10;
        }
      }
    }
  }
}


// address=[0x2f8bba0]
// Decompiled from char __thiscall CInterfaceD3D::CanCreateEngine(CInterfaceD3D *this, bool a2)
bool  CInterfaceD3D::CanCreateEngine(bool a2) {
  
  int v3; // eax
  int v5; // [esp+14h] [ebp-14h]
  CSurfaceV7 *pSurface; // [esp+24h] [ebp-4h]

  pSurface = CSurface::CreateSurfacePtr(a2);
  if ( pSurface != nullptr )
  {
    v3 = j__abs(GfxEngineSetup.iCurrentGfxMode == 1);
    v5 = pSurface->CreateSurface(pSurface, this->m_pDDraw, 32, 32, 1, 1, 0, v3, 0, 0, 0);
    if ( v5 != 0 )
    {
      WriteError(v5, "CanRebuildEngine");
      pSurface->dtor(pSurface, 1);
      return 0;
    }
    else
    {
      pSurface->Release(pSurface);
      pSurface->dtor(pSurface, 1);
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
// Decompiled from void __thiscall CInterfaceD3D::CleanUpCheckObjects(CInterfaceD3D *this)
void  CInterfaceD3D::CleanUpCheckObjects(void) {
  
  if ( this->LandscapeDevice != nullptr )
  {
    this->LandscapeDevice->Release(this->LandscapeDevice);
    this->LandscapeDevice = nullptr;
  }
  if ( this->m_pPrimarySurface != nullptr )
  {
    this->m_pPrimarySurface->Release(this->m_pPrimarySurface);
    if ( this->m_pPrimarySurface != nullptr )
    {
      this->m_pPrimarySurface->dtor(this->m_pPrimarySurface, 1);
    }
    this->m_pPrimarySurface = nullptr;
  }
  if ( this->m_pTmpSurface != nullptr )
  {
    this->m_pTmpSurface->Release(this->m_pTmpSurface);
    if ( this->m_pTmpSurface != nullptr )
    {
      this->m_pTmpSurface->dtor(this->m_pTmpSurface, 1);
    }
    this->m_pTmpSurface = nullptr;
  }
  if ( this->m_pIDirect3D7 != nullptr )
  {
    this->m_pIDirect3D7->Release(this->m_pIDirect3D7);
    this->m_pIDirect3D7 = nullptr;
  }
  if ( this->m_pDDraw7 != nullptr )
  {
    this->m_pDDraw7->lpVtbl->Release(this->m_pDDraw7);
    this->m_pDDraw7 = nullptr;
  }
  if ( this->m_pDDraw != nullptr )
  {
    this->m_pDDraw->lpVtbl->Release(this->m_pDDraw);
    this->m_pDDraw = nullptr;
    g_pDirectDraw = nullptr;
  }
}


// address=[0x2f996f0]
// Decompiled from void __thiscall CInterfaceD3D::DecreaseCacheRetrys(CInterfaceD3D *this)
void  CInterfaceD3D::DecreaseCacheRetrys(void) {
  
  --this->m_iCacheRetries;
}


// address=[0x2f99720]
// Decompiled from int __thiscall CInterfaceD3D::GetCacheRetrys(CInterfaceD3D *this)
int  CInterfaceD3D::GetCacheRetrys(void) {
  
  return this->m_iCacheRetries;
}


#endif // Already implemented
