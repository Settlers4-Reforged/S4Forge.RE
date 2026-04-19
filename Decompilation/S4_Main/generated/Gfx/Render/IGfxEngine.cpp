#include "IGfxEngine.h"

// Definitions for class IGfxEngine

// address=[0x2f5a390]
// Decompiled from IGfxEngine *__thiscall IGfxEngine::IGfxEngine(IGfxEngine *this)
 IGfxEngine::IGfxEngine(void) {
  
  this->m_bLockCursorShape = 0;
  std::unique_ptr<SurfaceClipper>::unique_ptr<SurfaceClipper>(&this->m_pSurfaceClipper);
  this->m_iWaveIndex = -1;
  this->m_iCameraVertexSize = -1;
  this->m_iVertexSize = -1;
  this->m_uFixedCursorShape = 0;
  g_bExclusive = 0;
  g_pDirectDraw = 0;
  this->m_bV7Available = 0;
  this->m_bV3Available = 0;
  this->m_bNeedsRebuild = 0;
  this->m_bHasCpuMMX = 0;
  this->m_bHardwareRenderingPossible = 0;
  this->m_bSoftwareRenderingPossible = 0;
  BBSupportTracePrintF(1, "GFX ENGINE: Engine object successfully created.");
  return this;
}


// address=[0x2f5a460]
// Decompiled from int __thiscall IGfxEngine::~IGfxEngine(IGfxEngine *this)
 IGfxEngine::~IGfxEngine(void) {
  
  DeleteEngine();
  if ( g_pDirectDraw )
  {
    g_pDirectDraw->lpVtbl->SetCooperativeLevel(g_pDirectDraw, MEMORY[0x3E2E268], 8);
    g_pDirectDraw->lpVtbl->Release(g_pDirectDraw);
    g_pDirectDraw = 0;
  }
  BBSupportTracePrintF(1, "GFX ENGINE: Engine object successfully destroyed.");
  return std::unique_ptr<SurfaceClipper>::~unique_ptr<SurfaceClipper>(&this->m_pSurfaceClipper);
}


// address=[0x2f5a500]
// Decompiled from void __thiscall IGfxEngine::SetWindowPosition(IGfxEngine *this, int a2, int a3)
void  IGfxEngine::SetWindowPosition(int a2, int a3) {
  
  MEMORY[0x3E2E274] = a2;
  MEMORY[0x3E2E278] = a3;
}


// address=[0x2f5a520]
// Decompiled from void __thiscall IGfxEngine::SetTickCounterAdress(IGfxEngine *this, unsigned int *a2)
void  IGfxEngine::SetTickCounterAdress(unsigned int * a2) {
  
  g_pTickCounter = (int)a2;
}


// address=[0x2f5a540]
// Decompiled from char __stdcall IGfxEngine::SetTemporaryText(char *Str, int a2, int a3, int a4, int a5, COLORREF a6)
bool  IGfxEngine::SetTemporaryText(char * Str, int a2, int a3, int a4, int a5, int a6) {
  
  if ( Str )
  {
    if ( strlen(Str) > 0xFF )
      return 0;
    j__strcpy_0(g_cTextTmp, Str);
    g_iTextTmpWidth = a4;
    g_iTextTmpHeight = a5;
    g_iTextTmpPosX = a2;
    g_iTextTmpPosY = a3;
    g_iTextTmpColor = a6;
  }
  else
  {
    g_cTextTmp[0] = 0;
  }
  return 1;
}


// address=[0x2f5a5e0]
// Decompiled from void __thiscall IGfxEngine::SetTriangleSize(IGfxEngine *this, int a2)
void  IGfxEngine::SetTriangleSize(int a2) {
  
  if ( this->m_iVertexSize != a2 && a2 >= 0x20000 && a2 <= 0xBE0000 )
  {
    this->m_iVertexSize = a2;
    g_iVertexSize = a2;
    g_fVertexSize = (float)a2;
    IGfxEngine::SetCameraMode(this, -1);
    g_fZoomFactor = (float)g_iVertexSize / 1572864.0;
    g_iZoomGradient = g_iVertexSize / 24;
    g_iZoomInit = -65536;
    byte_3E2E2FF = 1;
    SetMiniMapAreaSize();
    MarkCurrentArea();
    InitGradientTable();
    if ( D3DObjectPtr )
    {
      if ( D3DObjectPtr->CCachePageManager[0] )
        CCachePageManager::SetCurrentZoomFactor(
          (CCachePageManager *)D3DObjectPtr->CCachePageManager[0],
          SLODWORD(g_fZoomFactor));
    }
  }
}


// address=[0x2f5a6d0]
// Decompiled from char __thiscall IGfxEngine::SetScrollOffsets(IGfxEngine *this, int a2, int a3)
void  IGfxEngine::SetScrollOffsets(int a2, int a3) {
  
  dword_3E2E2A8 = (a2 << 15) / (g_iVertexSize / 2);
  dword_3E2E2AC = (a3 << 15) / (dword_3E2E290 / 2);
  dword_3E2E2B0 = ((a2 << 15) % (g_iVertexSize / 2)) >> 15;
  dword_3E2E2B4 = ((a3 << 15) % (dword_3E2E290 / 2)) >> 15;
  byte_3E2E302 = 1;
  SetMiniMapAreaSize();
  return MarkCurrentArea();
}


// address=[0x2f5a770]
// Decompiled from void __thiscall IGfxEngine::SetCameraMode(IGfxEngine *this, int a2)
void  IGfxEngine::SetCameraMode(int a2) {
  
  if ( a2 >= 0 )
    g_iCameraMode = a2;
  if ( g_iCameraMode == 1 )
    dword_3E2E290 = g_iVertexSize / 2;
  else
    dword_3E2E290 = g_iVertexSize;
  byte_3E2E2FE = 1;
  byte_3E2E2FF = 1;
}


// address=[0x2f5a7d0]
// Decompiled from void __thiscall IGfxEngine::SetGfxLayerAccess(IGfxEngine *this, int _iSize, struct T_GFX_MAP_ELEMENT *a3)
void  IGfxEngine::SetGfxLayerAccess(int _iSize, struct T_GFX_MAP_ELEMENT * a3) {
  
  unsigned int NewValue; // [esp+4h] [ebp-4h]

  Size = _iSize;
  g_pGfxLayer = a3;
  byte_3E2E2FE = 1;
  byte_3E2E2FF = 1;
  SetCrossingSystemMapAccess(_iSize, a3);
  NewValue = _controlfp(0x300u, 0x300u);
  CalcMaxHeights(a3, _iSize);
  SetMiniMapGradient();
  CalcMaxTimeStamps();
  _controlfp(NewValue, 0x300u);
}


// address=[0x2f5a860]
// Decompiled from char __stdcall IGfxEngine::SetPlayerColor(unsigned int a1, struct SGfxColor *a2)
bool  IGfxEngine::SetPlayerColor(int a1, struct SGfxColor & a2) {
  
  int GradientFormat; // eax

  if ( a1 >= 8 )
    return 0;
  g_pPlayerColors[a1 + 1] = *a2;
  if ( !D3DObjectPtr )
    return 1;
  GradientFormat = CInterfaceD3D::GetGradientFormat(D3DObjectPtr);
  CColorGradient::SetupGradients(&g_cColorGradient, a1, a2->m_iR, a2->m_iG, a2->m_iB, GradientFormat);
  return 1;
}


// address=[0x2f5a8e0]
// Decompiled from char __thiscall IGfxEngine::GetPlayerColor(IGfxEngine *this, unsigned int a2, struct SGfxColor *a3)
bool  IGfxEngine::GetPlayerColor(int a2, struct SGfxColor & a3) {
  
  if ( a2 >= 8 )
    return 0;
  *a3 = g_pPlayerColors[a2 + 1];
  return 1;
}


// address=[0x2f5a930]
// Decompiled from void __thiscall IGfxEngine::SetObjectLayerAccess(  IGfxEngine *this,  struct SGfxObjectInfo *(__cdecl *a2)(unsigned int, int),  unsigned __int16 *_pMapObjects,  unsigned __int16 *_pDecoObjects)
void  IGfxEngine::SetObjectLayerAccess(struct SGfxObjectInfo * (__cdecl*)(unsigned int,int) a2, unsigned short * _pMapObjects, unsigned short * _pDecoObjects) {
  
  g_pMapObjects = (int)_pMapObjects;
  g_pDecoObjects = (int)_pDecoObjects;
  g_pfGetGfxObjectInfo = a2;
}


// address=[0x2f5a960]
// Decompiled from void __thiscall IGfxEngine::SetOwnerIDCallback(IGfxEngine *this, int (__cdecl *a2)(int))
void  IGfxEngine::SetOwnerIDCallback(int (__cdecl*)(int) a2) {
  
  g_pfGetOwnerID = a2;
}


// address=[0x2f5a980]
// Decompiled from char __thiscall IGfxEngine::PutLandscapeObject(IGfxEngine *this, int a2, int a3, int a4)
bool  IGfxEngine::PutLandscapeObject(int a2, void * a3, void * a4) {
  
  if ( this->m_iWaveIndex == -1 )
  {
    if ( a2 == g_iWaveIndices[0] )
    {
      this->m_iWaveIndex = 0;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[0];
    }
    else if ( a2 == g_iWaveIndices[1] )
    {
      this->m_iWaveIndex = 1;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[1];
    }
    else if ( a2 == g_iWaveIndices[2] )
    {
      this->m_iWaveIndex = 2;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[2];
    }
    else if ( a2 == g_iWaveIndices[3] )
    {
      this->m_iWaveIndex = 3;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[3];
    }
    else if ( a2 == g_iWaveIndices[4] )
    {
      this->m_iWaveIndex = 4;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[4];
    }
    else if ( a2 == g_iWaveIndices[5] )
    {
      this->m_iWaveIndex = 5;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[5];
    }
    else if ( a2 == g_iWaveIndices[6] )
    {
      this->m_iWaveIndex = 6;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[6];
    }
    else if ( a2 == g_iWaveIndices[7] )
    {
      this->m_iWaveIndex = 7;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[7];
    }
    else if ( a2 == g_iWaveIndices[8] )
    {
      this->m_iWaveIndex = 8;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[8];
    }
    else if ( a2 == g_iWaveIndices[9] )
    {
      this->m_iWaveIndex = 9;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[9];
    }
    else if ( a2 == g_iWaveIndices[10] )
    {
      this->m_iWaveIndex = 10;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[10];
    }
    else if ( a2 == g_iWaveIndices[11] )
    {
      this->m_iWaveIndex = 11;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[11];
    }
    else if ( a2 == g_iWaveIndices[12] )
    {
      this->m_iWaveIndex = 12;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[12];
    }
    else if ( a2 == g_iWaveIndices[13] )
    {
      this->m_iWaveIndex = 13;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[13];
    }
    else if ( a2 == g_iWaveIndices[14] )
    {
      this->m_iWaveIndex = 14;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[14];
    }
    else if ( a2 == g_iWaveIndices[15] )
    {
      this->m_iWaveIndex = 15;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[15];
    }
    else if ( a2 == g_iWaveIndices[16] )
    {
      this->m_iWaveIndex = 16;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[16];
    }
    else if ( a2 == g_iWaveIndices[17] )
    {
      this->m_iWaveIndex = 17;
      this->m_uWaveFrame = (unsigned __int8)g_uWaveFrames[17];
    }
    else if ( a2 == g_iBorderstoneIndices )
    {
      this->m_iWaveIndex = 1000;
      this->m_uWaveFrame = (unsigned __int8)g_uBorderstoneFrames;
    }
  }
  if ( this->m_iWaveIndex == 1000 )
  {
    g_pBorderstonePalette = a4;
    dword_468A1D4[(unsigned __int8)g_uBorderstoneFrames - this->m_uWaveFrame--] = a3;
    g_pBorderstoneGfx[0] = a3;
    if ( !this->m_uWaveFrame )
      this->m_iWaveIndex = -1;
  }
  else if ( this->m_iWaveIndex >= 0 )
  {
    g_pWavePalettes[this->m_iWaveIndex] = a4;
    g_pWaveGfx[(unsigned __int8)g_uWaveFrames[this->m_iWaveIndex] + 20 * this->m_iWaveIndex - this->m_uWaveFrame--] = a3;
    if ( !this->m_uWaveFrame )
      this->m_iWaveIndex = -1;
  }
  return 1;
}


// address=[0x2f5ae60]
// Decompiled from void __thiscall IGfxEngine::SetReloadCallback(IGfxEngine *this, void *(__cdecl *a2)(int, bool, bool))
void  IGfxEngine::SetReloadCallback(void * (__cdecl*)(int,bool,bool) a2) {
  
  g_pfForceReload = a2;
}


// address=[0x2f5ae80]
// Decompiled from void __stdcall IGfxEngine::SetGfxObject(struct SGfxObject *Src)
void  IGfxEngine::SetGfxObject(struct SGfxObject * Src) {
  
  if ( Src )
    memcpy(&g_sGfxObjectCursorBuilding, Src, 0x2E0u);
  else
    g_sGfxObjectCursorBuilding = -65535;
}


// address=[0x2f5aec0]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave1(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave1(int a2, int a3) {
  
  g_uWaveFrames[0] = a3;
  g_iWaveIndices[0] = a2;
}


// address=[0x2f5aef0]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave2(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave2(int a2, int a3) {
  
  g_uWaveFrames[1] = a3;
  g_iWaveIndices[1] = a2;
}


// address=[0x2f5af20]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave3(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave3(int a2, int a3) {
  
  g_uWaveFrames[2] = a3;
  g_iWaveIndices[2] = a2;
}


// address=[0x2f5af50]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave4(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave4(int a2, int a3) {
  
  g_uWaveFrames[3] = a3;
  g_iWaveIndices[3] = a2;
}


// address=[0x2f5af80]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave5(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave5(int a2, int a3) {
  
  g_uWaveFrames[4] = a3;
  g_iWaveIndices[4] = a2;
}


// address=[0x2f5afb0]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave6(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave6(int a2, int a3) {
  
  g_uWaveFrames[5] = a3;
  g_iWaveIndices[5] = a2;
}


// address=[0x2f5afe0]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave7(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave7(int a2, int a3) {
  
  g_uWaveFrames[6] = a3;
  g_iWaveIndices[6] = a2;
}


// address=[0x2f5b010]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave8(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave8(int a2, int a3) {
  
  g_uWaveFrames[7] = a3;
  g_iWaveIndices[7] = a2;
}


// address=[0x2f5b040]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave9(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave9(int a2, int a3) {
  
  g_uWaveFrames[8] = a3;
  g_iWaveIndices[8] = a2;
}


// address=[0x2f5b070]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave10(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave10(int a2, int a3) {
  
  g_uWaveFrames[9] = a3;
  g_iWaveIndices[9] = a2;
}


// address=[0x2f5b0a0]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave11(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave11(int a2, int a3) {
  
  g_uWaveFrames[10] = a3;
  g_iWaveIndices[10] = a2;
}


// address=[0x2f5b0d0]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave12(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave12(int a2, int a3) {
  
  g_uWaveFrames[11] = a3;
  g_iWaveIndices[11] = a2;
}


// address=[0x2f5b100]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave13(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave13(int a2, int a3) {
  
  g_uWaveFrames[12] = a3;
  g_iWaveIndices[12] = a2;
}


// address=[0x2f5b130]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave14(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave14(int a2, int a3) {
  
  g_uWaveFrames[13] = a3;
  g_iWaveIndices[13] = a2;
}


// address=[0x2f5b160]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave15(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave15(int a2, int a3) {
  
  g_uWaveFrames[14] = a3;
  g_iWaveIndices[14] = a2;
}


// address=[0x2f5b190]
// Decompiled from void __thiscall IGfxEngine::SetIndexWave16(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave16(int a2, int a3) {
  
  g_uWaveFrames[15] = a3;
  g_iWaveIndices[15] = a2;
}


// address=[0x2f5b1c0]
// Decompiled from void __stdcall IGfxEngine::SetIndexWave17(int a1, char a2)
void  IGfxEngine::SetIndexWave17(int a1, int a2) {
  
  g_uWaveFrames[16] = a2;
  g_iWaveIndices[16] = a1;
}


// address=[0x2f5b1f0]
// Decompiled from void __stdcall IGfxEngine::SetIndexWave18(int a1, char a2)
void  IGfxEngine::SetIndexWave18(int a1, int a2) {
  
  g_uWaveFrames[17] = a2;
  g_iWaveIndices[17] = a1;
}


// address=[0x2f5b220]
// Decompiled from void __thiscall IGfxEngine::SetIndexBorderstone(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexBorderstone(int a2, int a3) {
  
  g_uBorderstoneFrames = a3;
  g_iBorderstoneIndices = a2;
}


// address=[0x2f5b240]
// Decompiled from char __thiscall IGfxEngine::EnableMiniMap(IGfxEngine *this, char a2, int a3, int a4, HWND a5)
bool  IGfxEngine::EnableMiniMap(bool a2, int a3, int a4, struct HWND__ * a5) {
  
  int v6; // [esp+4h] [ebp-4h]

  byte_3E2E301 = a2;
  dword_3E2E304 = a3;
  dword_3E2E308 = a4;
  dword_3E2E2E4 = (int)a5;
  if ( D3DObjectPtr
    && SurfaceClipper::GetClipper((SurfaceClipper *)&D3DObjectPtr->m_sMinimapClipper)
    && (v6 = SurfaceClipper::SetClipWindow((SurfaceClipper *)&D3DObjectPtr->m_sMinimapClipper, a5)) != 0 )
  {
    WriteError(v6, (char *)&dword_3AC8174[1]);
    return 0;
  }
  else
  {
    g_sMiniMapRect = a3;
    dword_4689B90 = a4;
    dword_4689B94 = a3 + 240;
    dword_4689B98 = a4 + 160;
    return 1;
  }
}


// address=[0x2f5b2f0]
// Decompiled from void __thiscall IGfxEngine::SetMiniMapColorCallback(IGfxEngine *this, struct SGfxColor *(__cdecl *a2)(unsigned int))
void  IGfxEngine::SetMiniMapColorCallback(struct SGfxColor * (__cdecl*)(unsigned int) a2) {
  
  g_pfGetGfxMiniMapColor = a2;
}


// address=[0x2f5b310]
// Decompiled from char __thiscall IGfxEngine::EnableCameraWindow(IGfxEngine *this, char a2, int a3, int a4, int a5, int a6)
bool  IGfxEngine::EnableCameraWindow(bool a2, int a3, int a4, int a5, int a6) {
  
  CInterfaceD3D::DestroyCameraWindowSurface(D3DObjectPtr);
  if ( a2 && !CInterfaceD3D::CreateCameraWindowSurface(D3DObjectPtr, a5, a6) )
    return 0;
  dword_3E2E2D4 = a3;
  dword_3E2E2D8 = a4;
  dword_3E2E2DC = a5;
  dword_3E2E2E0 = a6;
  byte_3E2E327 = a2;
  byte_3E2E2FE = 1;
  return 1;
}


// address=[0x2f5b390]
// Decompiled from void __thiscall IGfxEngine::SetCameraViewPosition(IGfxEngine *this, int a2, int a3)
void  IGfxEngine::SetCameraViewPosition(int a2, int a3) {
  
  dword_3E2E2C4 = (a2 << 15) / (g_iCameraVertexSize / 2);
  dword_3E2E2C8 = (a3 << 15) / (dword_3E2E298 / 2);
  dword_3E2E2CC = ((a2 << 15) % (g_iCameraVertexSize / 2)) >> 15;
  dword_3E2E2D0 = ((a3 << 15) % (dword_3E2E298 / 2)) >> 15;
  byte_3E2E303 = 1;
}


// address=[0x2f5b420]
// Decompiled from void __thiscall IGfxEngine::SetCameraTriangleSize(IGfxEngine *this, int a2)
void  IGfxEngine::SetCameraTriangleSize(int a2) {
  
  if ( this->m_iCameraVertexSize != a2 && a2 >= 0x20000 && a2 <= (int)&dword_B0F0F0[213956] )
  {
    this->m_iCameraVertexSize = a2;
    g_iCameraVertexSize = a2;
    *(float *)&g_fCamVertexSize = (float)a2;
    if ( g_iCameraMode == 1 )
      dword_3E2E298 = g_iCameraVertexSize / 2;
    else
      dword_3E2E298 = g_iCameraVertexSize;
    byte_3E2E2FE = 1;
    g_fCameraZoomFactor = (float)g_iCameraVertexSize / 1572864.0;
    g_iCamZoomGradient = g_iCameraVertexSize / 24;
    g_iZoomInit = -65536;
    InitCamGradientTable();
  }
}


// address=[0x2f5b4e0]
// Decompiled from int __thiscall IGfxEngine::GetRenderHeight(IGfxEngine *this, int a2)
int  IGfxEngine::GetRenderHeight(int a2) {
  
  return (int)(float)((float)((float)a2 * 0.051562499) * *(float *)&g_fCamVertexSize) >> 16;
}


// address=[0x2f5b510]
// Decompiled from void __thiscall IGfxEngine::SetIconCallbacks(  IGfxEngine *this,  void (__cdecl *a2)(int),  unsigned __int8 (__cdecl *a3)(int))
void  IGfxEngine::SetIconCallbacks(void (__cdecl*)(int) a2, unsigned char (__cdecl*)(int) a3) {
  
  g_pfSetNumberOfNextLine = (int (__cdecl *)(_DWORD))a2;
  g_pfGetIconObjectByX = (int (__cdecl *)(_DWORD))a3;
}


// address=[0x2f5b530]
// Decompiled from char __thiscall IGfxEngine::PutAccessoryIcon(IGfxEngine *this, unsigned int a2, int a3, int a4)
bool  IGfxEngine::PutAccessoryIcon(int a2, void * a3, void * a4) {
  
  if ( a2 >= 0x100 )
    return 0;
  g_pIconGfx[a2] = a3;
  g_pIconPalette = a4;
  return 1;
}


// address=[0x2f5b570]
// Decompiled from char __thiscall IGfxEngine::InitEngine(  IGfxEngine *this,  struct SGfxRenderConfiguration a2,  char _bIsMMX,  _DWORD *a4,  _DWORD *a5,  _DWORD *a6)
bool  IGfxEngine::InitEngine(struct SGfxRenderConfiguration a2, bool _bIsMMX, int & a4, int & a5, int & a6) {
  
  this->m_bHasCpuMMX = _bIsMMX;
  *a6 = 27;
  CheckConfiguration(&a2);
  qmemcpy(&GfxEngineSetup, &a2, sizeof(GfxEngineSetup));
  if ( a2.m_bD3DInterface )
  {
    this->m_bV7Available = 0x17;
    *a5 = 23;
    this->m_bHardwareRenderingPossible = 0;
  }
  else
  {
    this->m_bHardwareRenderingPossible = IGfxEngine::IsHardwareRenderingAvailable(this);
    *a5 = this->m_bV7Available;
  }
  if ( this->m_bHasCpuMMX )
  {
    this->m_bSoftwareRenderingPossible = IGfxEngine::IsSoftwareRenderingAvailable(this);
    *a4 = this->m_bV3Available;
  }
  else
  {
    this->m_bV3Available = 0x16;
    *a4 = 22;
    this->m_bSoftwareRenderingPossible = 0;
  }
  if ( this->m_bSoftwareRenderingPossible )
    BBSupportTracePrintF(1, "GFX ENGINE: Check setup: Software-rendering is possible.");
  else
    BBSupportTracePrintF(1, "GFX ENGINE: Check setup: Software-rendering is not possible.");
  if ( this->m_bHardwareRenderingPossible )
    BBSupportTracePrintF(1, "GFX ENGINE: Check setup: Hardware-rendering is possible.");
  else
    BBSupportTracePrintF(1, "GFX ENGINE: Check setup: Hardware-rendering is not possible.");
  if ( this->m_bHardwareRenderingPossible || this->m_bSoftwareRenderingPossible )
  {
    byte_3E2E2FF = 1;
    if ( SGfxRenderConfiguration::IsHardwareObjectEngine(&a2) && this->m_bHardwareObjectPossible )
    {
      g_bHardwareObjectEnabled = 1;
      BBSupportTracePrintF(1, "GFX ENGINE: Hardware object rendering enabled.");
    }
    else
    {
      g_bHardwareObjectEnabled = 0;
      BBSupportTracePrintF(1, "GFX ENGINE: Hardware object rendering disabled.");
    }
    if ( this->m_bHardwareObjectPossible )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Check setup: Hardware object rendering is possible.");
      *a6 = 0;
    }
    else
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Check setup: Hardware object rendering is not possible.");
      *a6 = 27;
    }
    SetMiniMapAreaSize();
    if ( Initialize() )
    {
      if ( !this->m_bV7Available || !this->m_bV3Available )
        this->m_bNeedsRebuild = 1;
      if ( (!SGfxRenderConfiguration::IsHardwareLandscapeEngine(&a2) || this->m_bHardwareRenderingPossible)
        && (SGfxRenderConfiguration::IsHardwareLandscapeEngine(&a2) || this->m_bSoftwareRenderingPossible) )
      {
        return IGfxEngine::SetRenderEnvironment(this);
      }
      else
      {
        BBSupportTracePrintF(1, "GFX ENGINE: The requested render configuration is not available!");
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Check setup: No possible render setup found!");
    return 0;
  }
}


// address=[0x2f5b7c0]
// Decompiled from char __thiscall IGfxEngine::RebuildRenderEnvironment(IGfxEngine *this, struct SGfxRenderConfiguration sConf)
bool  IGfxEngine::RebuildRenderEnvironment(struct SGfxRenderConfiguration sConf) {
  
  if ( !this->m_bNeedsRebuild )
    return 0;
  if ( SGfxRenderConfiguration::IsHardwareObjectEngine(&sConf) && this->m_bHardwareObjectPossible )
  {
    g_bHardwareObjectEnabled = 1;
    BBSupportTracePrintF(1, "GFX ENGINE: Hardware object rendering enabled.");
  }
  else
  {
    g_bHardwareObjectEnabled = 0;
    BBSupportTracePrintF(1, "GFX ENGINE: Hardware object rendering disabled.");
  }
  CheckConfiguration(&sConf);
  if ( sConf.m_bGuiOnly )
  {
    g_pGfxLayer = 0;
    g_pMapObjects = 0;
    g_pDecoObjects = 0;
    g_pRequestedRectangle = 0;
    SetCrossingSystemMapAccess(0, 0);
  }
  if ( (!SGfxRenderConfiguration::IsHardwareLandscapeEngine(&sConf) || this->m_bHardwareRenderingPossible)
    && (SGfxRenderConfiguration::IsHardwareLandscapeEngine(&sConf) || this->m_bSoftwareRenderingPossible) )
  {
    qmemcpy(&GfxEngineSetup, &sConf, sizeof(GfxEngineSetup));
    byte_3E2E2FF = 1;
    SetMiniMapAreaSize();
    return IGfxEngine::SetRenderEnvironment(this);
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: The requested render configuration is not available!");
    return 0;
  }
}


// address=[0x2f5b8e0]
// Decompiled from void *__thiscall IGfxEngine::GetCurrentRenderConfiguration(IGfxEngine *this)
struct SGfxRenderConfiguration const &  IGfxEngine::GetCurrentRenderConfiguration(void)const {
  
  return &GfxEngineSetup;
}


// address=[0x2f5b8f0]
// Decompiled from bool __thiscall IGfxEngine::RenderFrame(IGfxEngine *this, bool a2, char a3)
bool  IGfxEngine::RenderFrame(bool a2, bool a3) {
  
  struct SurfaceClipper *v4; // eax
  unsigned __int8 v5; // al
  CBlitFX v6; // [esp+2Ch] [ebp-D4h] BYREF
  int v7; // [esp+90h] [ebp-70h]
  DWORD TickCount; // [esp+94h] [ebp-6Ch]
  float v9; // [esp+98h] [ebp-68h]
  int v10; // [esp+A0h] [ebp-60h]
  int v11; // [esp+A4h] [ebp-5Ch]
  BOOL v12; // [esp+A8h] [ebp-58h]
  int v13; // [esp+ACh] [ebp-54h]
  int v14; // [esp+B0h] [ebp-50h]
  int v15; // [esp+B4h] [ebp-4Ch]
  int v16; // [esp+B8h] [ebp-48h]
  BOOL v17; // [esp+BCh] [ebp-44h]
  bool v19; // [esp+C5h] [ebp-3Bh]
  bool v20; // [esp+C6h] [ebp-3Ah]
  bool v21; // [esp+C7h] [ebp-39h]
  int v22; // [esp+C8h] [ebp-38h] BYREF
  _DWORD v23[4]; // [esp+CCh] [ebp-34h] BYREF
  DWORD v24; // [esp+DCh] [ebp-24h] BYREF
  int v25; // [esp+E0h] [ebp-20h]
  int v26; // [esp+E4h] [ebp-1Ch]
  int v27; // [esp+E8h] [ebp-18h]
  int v28; // [esp+ECh] [ebp-14h] BYREF
  int v29; // [esp+F0h] [ebp-10h]
  int v30; // [esp+F4h] [ebp-Ch]
  int v31; // [esp+F8h] [ebp-8h]

  v22 = 1;
  if ( IsIconic(GfxEngineSetup.m_hWnd) )
  {
    byte_4689BD9 = 1;
    LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
    return 1;
  }
  if ( !D3DObjectPtr )
  {
    BBSupportTracePrintF(0, "GFX ENGINE: Call to RenderFrame without initializing the engine!");
    return 0;
  }
  if ( g_iRefreshWaitFrames )
  {
    if ( byte_4689BD9 )
    {
      byte_4689BD9 = 0;
      D3DObjectPtr->m_bGfxEngineRebuilded = 1;
    }
    if ( --g_iRefreshWaitFrames )
      return 1;
  }
  if ( LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
  {
    if ( IGfxEngine::SetRenderEnvironment(this) )
    {
      LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 0;
      byte_3E2E2FE = 1;
      byte_3E2E2FF = 1;
      D3DObjectPtr->m_bGfxEngineRebuilded = 1;
      return 1;
    }
    else
    {
      BBSupportTracePrintF(0, "GFX ENGINE: Problem while reinitializing the renderer!");
      LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
      return 0;
    }
  }
  else if ( GfxEngineSetup.m_bGuiOnly )
  {
    if ( D3DObjectPtr->FinalRenderSurface )
    {
      CBlitFX::CBlitFX(&v6);
      v21 = g_uGfxMode == 1;
      CBlitFX::SetFillColor(&v6, 0, 0, 0, g_uGfxMode == 1);
      v22 = D3DObjectPtr->FinalRenderSurface->ClearSurface(D3DObjectPtr->FinalRenderSurface, (_BYTE *)&v6);
      if ( v22 >= 0 )
      {
        if ( (unsigned __int8)std::operator!=<SurfaceClipper,std::default_delete<SurfaceClipper>>(
                                (int)&this->m_pSurfaceClipper,
                                0)
          && (v4 = (struct SurfaceClipper *)std::unique_ptr<SurfaceClipper>::operator*(&this->m_pSurfaceClipper),
              v22 = CInterfaceD3D::SetCustomClipper(D3DObjectPtr, v4),
              v22 < 0) )
        {
          BBSupportTracePrintF(0, "GFX ENGINE: Failed to assign GUI clipper!");
          LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
          return 1;
        }
        else if ( AddGuiPatches() )
        {
          v22 = CInterfaceD3D::ClearCustomClipper(D3DObjectPtr);
          if ( v22 >= 0 )
            return 1;
          BBSupportTracePrintF(0, "GFX ENGINE: Failed to clear GUI clipper!");
          LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
          return 1;
        }
        else
        {
          LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
          return 1;
        }
      }
      else
      {
        BBSupportTracePrintF(0, "GFX ENGINE: Failed to clear final render surface!");
        LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
        return 1;
      }
    }
    else
    {
      return 1;
    }
  }
  else
  {
    TickCount = GetTickCount();
    if ( a2 )
    {
      byte_3E2E2FE = 1;
      byte_3E2E2FF = 1;
    }
    if ( byte_3E2E2FF || byte_3E2E302 )
    {
      v22 = (unsigned __int8)DrawTexturedLandscape(dword_3E2E2A8, dword_3E2E2AC);
      a3 = 1;
    }
    if ( !v22 )
    {
      WriteError(0, "RenderLandscape");
      LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
      return 1;
    }
    byte_3E2E302 = 0;
    byte_3E2E2FF = 0;
    if ( byte_3E2E300 )
    {
      v22 = (unsigned __int8)DrawTexturedLandscapeDelta(dword_3E2E2A8, dword_3E2E2AC);
      a3 = 1;
    }
    if ( !v22 )
    {
      WriteError(0, "RenderLandscapeDelta");
      LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
      return 1;
    }
    byte_3E2E300 = 0;
    dword_3E2E314 = 2000;
    g_iFoggingRange = -1;
    if ( !SGfxRenderConfiguration::IsEditorMode(&GfxEngineSetup) || a3 )
    {
      v22 = D3DObjectPtr->FinalRenderSurface->Blt(
              D3DObjectPtr->FinalRenderSurface,
              0,
              D3DObjectPtr->LandscapeSurface,
              0,
              0,
              0);
      if ( v22 )
      {
        WriteError(v22, "BlitLandscapeSurfaceToFinal");
        LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
        return 0;
      }
      HIBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
      RenderObjectLayer(0);
    }
    v17 = byte_3E2E327
       && CInterfaceD3D::HasCameraWindowSurface(D3DObjectPtr)
       && dword_3E2E2DC > 0
       && D3DObjectPtr->FinalRenderSurface;
    v19 = v17;
    if ( v17 )
    {
      byte_3E2E2FE = 1;
      if ( dword_3E2E2D4 < GfxEngineSetup.m_uWidth && dword_3E2E2D8 < GfxEngineSetup.m_uHeight )
      {
        v22 = CInterfaceD3D::SwitchLandscapeRenderTarget(D3DObjectPtr, 1);
        if ( v22 < 0 )
        {
          WriteError(v22, "RenderCamWindow");
          LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
          return 0;
        }
        v9 = g_fVertexSize;
        LODWORD(g_fVertexSize) = g_fCamVertexSize;
        v5 = DrawCameraLandscape(dword_3E2E2C4, dword_3E2E2C8);
        v22 = v5;
        g_fVertexSize = v9;
        if ( !v5 )
        {
          WriteError(v22, "RenderCamWindow");
          LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
          return 0;
        }
        v22 = CInterfaceD3D::SwitchLandscapeRenderTarget(D3DObjectPtr, 0);
        if ( v22 < 0 )
        {
          WriteError(v22, "RenderCamWindow");
          LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
          return 0;
        }
        v23[0] = dword_3E2E2D4;
        v23[1] = dword_3E2E2D8;
        if ( dword_3E2E2DC >= GfxEngineSetup.m_uWidth - dword_3E2E2D4 )
          v16 = GfxEngineSetup.m_uWidth - dword_3E2E2D4;
        else
          v16 = dword_3E2E2DC;
        v13 = v16;
        if ( dword_3E2E2E0 >= GfxEngineSetup.m_uHeight - dword_3E2E2D8 )
          v15 = GfxEngineSetup.m_uHeight - dword_3E2E2D8;
        else
          v15 = dword_3E2E2E0;
        v14 = v15;
        v23[2] = dword_3E2E2D4 + v13;
        v23[3] = dword_3E2E2D8 + v15;
        v22 = D3DObjectPtr->FinalRenderSurface->Blt(
                D3DObjectPtr->FinalRenderSurface,
                (struct tagRECT *)v23,
                (CSurfaceV7 *)D3DObjectPtr->m_pCameraWindowSurface,
                0,
                0,
                0);
        if ( v22 )
        {
          WriteError(v22, "BlitCameraSurfaceToBuffer");
          LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
          return 0;
        }
        byte_3E2E303 = 0;
        byte_3E2E2FE = 0;
        CInterfaceD3D::SetupViewport(D3DObjectPtr, dword_3E2E2D4, dword_3E2E2D8, v13, v14);
        EnableCamRenderSettings(1);
        if ( D3DObjectPtr && D3DObjectPtr->CCachePageManager[0] )
          ((void (__thiscall *)(CCachePageManager *, int))CCachePageManager::SetCurrentZoomFactor)(
            D3DObjectPtr->CCachePageManager[0],
            SLODWORD(g_fZoomFactor));
        RenderObjectLayer(1);
        if ( D3DObjectPtr && D3DObjectPtr->CCachePageManager[0] )
          ((void (__thiscall *)(CCachePageManager *, int))CCachePageManager::SetCurrentZoomFactor)(
            D3DObjectPtr->CCachePageManager[0],
            SLODWORD(g_fCameraZoomFactor));
        EnableCamRenderSettings(0);
        CInterfaceD3D::SetupViewport(D3DObjectPtr, 0, 0, GfxEngineSetup.m_uWidth, GfxEngineSetup.m_uHeight);
      }
    }
    if ( g_bHardwareObjectEnabled && dword_3E2E310 )
    {
      if ( dword_3E2E310 == -1 )
      {
        CInterfaceD3D::BeginObjectScene(D3DObjectPtr);
        CCachePageManager::ShowPageContent(D3DObjectPtr->CCachePageManager[0], &v22);
        CInterfaceD3D::EndObjectScene(D3DObjectPtr);
        if ( v22 )
          WriteError(v22, "ShowCachePage");
      }
      if ( dword_3E2E310 == -2 )
      {
        CInterfaceD3D::BeginObjectScene(D3DObjectPtr);
        CCachePageManager::ShowPageContent(D3DObjectPtr->CCachePageManager[1], &v22);
        CInterfaceD3D::EndObjectScene(D3DObjectPtr);
        if ( v22 )
          WriteError(v22, "ShowCachePage");
      }
      if ( dword_3E2E310 > 0 && dword_3E2E310 < D3DObjectPtr->m_uCacheSurfaceCount )
      {
        CInterfaceD3D::BeginObjectScene(D3DObjectPtr);
        CCachePageManager::ShowPageContent(D3DObjectPtr->m_pCacheManagers[dword_3E2E310], &v22);
        CInterfaceD3D::EndObjectScene(D3DObjectPtr);
        if ( v22 )
          WriteError(v22, "ShowCachePage");
      }
    }
    v7 = GetTickCount() - TickCount;
    AddDebugStrings(v7);
    if ( !byte_3E2E301 )
      goto LABEL_106;
    v12 = D3DObjectPtr->MiniMapSurface->IsLost(D3DObjectPtr->MiniMapSurface) == -2005532222
       || D3DObjectPtr->MiniMapAreaSurface->IsLost(D3DObjectPtr->MiniMapAreaSurface) == -2005532222;
    v20 = v12;
    if ( g_bForceMiniMapRefresh || v20 )
    {
      if ( v20 )
      {
        LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
        return 1;
      }
      g_bForceMiniMapRefresh = 0;
      DrawCompleteMiniMap();
      MarkCurrentArea();
    }
    DrawMiniMapObjectLayer();
    DrawMiniMapLandscapeLayer();
    GetNextLayer();
    v28 = g_sMiniMapRect;
    v29 = dword_4689B90;
    v30 = dword_4689B94;
    v31 = dword_4689B98;
    v24 = g_sMiniMapSize;
    v25 = dword_3E2E240;
    v26 = dword_3E2E244;
    v27 = dword_3E2E248;
    if ( SGfxRenderConfiguration::IsEditorMode(&GfxEngineSetup) )
      goto LABEL_106;
    if ( v29 <= GfxEngineSetup.m_uHeight || v28 <= GfxEngineSetup.m_uWidth )
    {
      if ( v31 > GfxEngineSetup.m_uHeight )
      {
        v11 = v31 - GfxEngineSetup.m_uHeight;
        v31 = GfxEngineSetup.m_uHeight;
        v27 -= v11;
      }
      if ( v30 > GfxEngineSetup.m_uWidth )
      {
        v10 = v30 - GfxEngineSetup.m_uWidth;
        v30 = GfxEngineSetup.m_uWidth;
        v26 -= v10;
      }
      v22 = D3DObjectPtr->FinalRenderSurface->Blt(
              D3DObjectPtr->FinalRenderSurface,
              (struct tagRECT *)&v28,
              D3DObjectPtr->MiniMapSurface,
              (struct tagRECT *)&v24,
              0x8000,
              0);
      if ( !v22 )
        v22 = D3DObjectPtr->FinalRenderSurface->Blt(
                D3DObjectPtr->FinalRenderSurface,
                (struct tagRECT *)&v28,
                D3DObjectPtr->MiniMapAreaSurface,
                (struct tagRECT *)&v24,
                0x8000,
                0);
    }
    if ( v22 )
    {
      WriteError(v22, "BlitMiniMap");
      return 0;
    }
    else
    {
LABEL_106:
      RenderTmpText();
      CInterfaceD3D::BlitCursor(D3DObjectPtr);
      if ( !AddGuiPatches() )
        LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
      return v22 == 0;
    }
  }
}


// address=[0x2f5c400]
// Decompiled from char __stdcall IGfxEngine::BlitFrameToDIB(HGDIOBJ h)
bool  IGfxEngine::BlitFrameToDIB(struct HBITMAP__ * h) {
  
  return BlitRenderedSurfaceToDIB(MEMORY[0x3E2E268], h);
}


// address=[0x2f5c420]
// Decompiled from void IGfxEngine::ForceMiniMapRefresh()
void  IGfxEngine::ForceMiniMapRefresh(void) {
  
  g_bForceMiniMapRefresh = 1;
}


// address=[0x2f5c440]
// Decompiled from void __thiscall IGfxEngine::DrawRectangle(IGfxEngine *this, struct tagRECT *a2, unsigned __int16 a3)
void  IGfxEngine::DrawRectangle(struct tagRECT * a2, unsigned short a3) {
  
  g_pRequestedRectangle = a2;
  g_uRequestedRectangleColor = a3;
}


// address=[0x2f5c460]
// Decompiled from void __thiscall IGfxEngine::EnableIconLayer(IGfxEngine *this, char a2)
void  IGfxEngine::EnableIconLayer(bool a2) {
  
  g_bIconLayerEnabled = a2;
}


// address=[0x2f5c480]
// Decompiled from void __thiscall IGfxEngine::UpdateWorldPosition(IGfxEngine *this, int a2, int a3)
void  IGfxEngine::UpdateWorldPosition(int a2, int a3) {
  
  int v3; // [esp+4h] [ebp-4h]

  if ( g_pGfxLayer && (a3 | a2) >= 0 && a2 < (int)Size && a3 < (int)Size )
  {
    v3 = a2 + Size * a3;
    RefreshShading(v3, 0);
    if ( g_pGfxLayer[v3].m_uGroundHeight > (int)(unsigned __int8)g_uMaxYTable[a3] )
      g_uMaxYTable[a3] = g_pGfxLayer[v3].m_uGroundHeight;
    if ( a3 < dword_3E2E314 )
      dword_3E2E314 = a3;
    if ( a3 > g_iFoggingRange )
      g_iFoggingRange = a3;
    byte_3E2E300 = 1;
  }
}


// address=[0x2f5c540]
// Decompiled from int __thiscall IGfxEngine::UpdateWorldPosition(IGfxEngine *this, int a2)
void  IGfxEngine::UpdateWorldPosition(int a2) {
  
  int result; // eax
  int v3; // [esp+4h] [ebp-4h]

  if ( !g_pGfxLayer )
    return result;
  if ( a2 < 0 )
    return result;
  result = Size * Size;
  if ( a2 >= (int)(Size * Size) )
    return result;
  RefreshShading(a2, 0);
  v3 = a2 / (int)Size;
  if ( g_pGfxLayer[a2].m_uGroundHeight > (int)(unsigned __int8)g_uMaxYTable[a2 / (int)Size] )
    g_uMaxYTable[v3] = g_pGfxLayer[a2].m_uGroundHeight;
  result = v3;
  if ( v3 < dword_3E2E314 )
    dword_3E2E314 = v3;
  if ( v3 > g_iFoggingRange )
  {
    result = v3;
    g_iFoggingRange = v3;
  }
  byte_3E2E300 = 1;
  return result;
}


// address=[0x2f5c5f0]
// Decompiled from void IGfxEngine::RenderCursor()
void  IGfxEngine::RenderCursor(void) {
  
  if ( D3DObjectPtr )
    CInterfaceD3D::BlitCursor(D3DObjectPtr);
}


// address=[0x2f5c610]
// Decompiled from void __thiscall IGfxEngine::ConvertMapPositionToWorldScreenOffsets(  IGfxEngine *this,  int a2,  int a3,  float *a4,  float *a5)
void  IGfxEngine::ConvertMapPositionToWorldScreenOffsets(int a2, int a3, float & a4, float & a5) {
  
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  if ( (a3 | a2) >= 0 && a2 < (int)Size && a3 < (int)Size && g_pGfxLayer )
    v5 = CalcStaticHeightOffset(g_pGfxLayer[a2 + Size * a3].m_uGroundHeight);
  *a5 = (float)((float)a3 * (float)(24.0 / 2.0)) - (float)v5;
  *a4 = (float)((float)a2 - (float)((float)a3 / 2.0)) * 24.0;
}


// address=[0x2f5c6d0]
// Decompiled from void __stdcall IGfxEngine::ConvertMapPositionToWorldScreenOffsets_0(int a1, int a1_4, int *a2, int *a3)
void  IGfxEngine::ConvertMapPositionToWorldScreenOffsets(int a1, int a2, int & a3, int & a4) {
  
  int v4; // [esp+8h] [ebp-4h]

  v4 = 0;
  if ( (a1_4 | a1) >= 0 && a1 < (int)Size && a1_4 < (int)Size && g_pGfxLayer )
    v4 = CalcStaticHeightOffsetInt(g_pGfxLayer[a1 + Size * a1_4].m_uGroundHeight);
  *a3 = 12 * a1_4 - v4;
  *a2 = 24 * (a1 - a1_4 / 2);
}


// address=[0x2f5c760]
// Decompiled from bool __thiscall IGfxEngine::CanChangeGround(IGfxEngine *this, int a2, int a3, int a4)
bool  IGfxEngine::CanChangeGround(int a2, int a3, int a4) {
  
  return g_pGfxLayer && CheckField(a2, a3, a2 + Size * a3, a4);
}


// address=[0x2f5c7a0]
// Decompiled from void __thiscall IGfxEngine::SetDarkLand(IGfxEngine *this, int a2, int a3, bool a4)
void  IGfxEngine::SetDarkLand(int a2, int a3, bool a4) {
  
  int v4; // [esp+4h] [ebp-8h] BYREF
  int v5; // [esp+8h] [ebp-4h] BYREF

  if ( g_pGfxLayer )
  {
    SetDarkLandFlag(a2, a3, a4, &v5, &v4);
    if ( v5 < dword_3E2E314 )
      dword_3E2E314 = v5;
    if ( v4 > g_iFoggingRange )
      g_iFoggingRange = v4;
    byte_3E2E300 = 1;
  }
}


// address=[0x2f5c810]
// Decompiled from void __thiscall IGfxEngine::SetFoggingFadingStep(IGfxEngine *this, int a2)
void  IGfxEngine::SetFoggingFadingStep(int a2) {
  
  int v2; // [esp+4h] [ebp-8h]
  int v3; // [esp+8h] [ebp-4h]

  g_iFogFadeStep = a2;
  g_iFadeYBorder = -50000;
  if ( a2 != s_iPrevFogFadeStep )
  {
    if ( dword_3E2E24C >= dword_3E2E314 )
      v3 = dword_3E2E314;
    else
      v3 = dword_3E2E24C;
    dword_3E2E314 = v3;
    if ( dword_3E2E250 <= g_iFoggingRange )
      v2 = g_iFoggingRange;
    else
      v2 = dword_3E2E250;
    g_iFoggingRange = v2;
    s_iPrevFogFadeStep = a2;
    byte_3E2E300 = 1;
  }
}


// address=[0x2f5c8a0]
// Decompiled from void __thiscall IGfxEngine::SetFoggingUpdateMode(IGfxEngine *this, int a2)
void  IGfxEngine::SetFoggingUpdateMode(int a2) {
  
  g_iFadeYBorder = a2;
  g_iFogFadeStep = 15;
}


// address=[0x2f5c8c0]
// Decompiled from void __thiscall IGfxEngine::SetFoggingRange(IGfxEngine *this, int a2, int a3)
void  IGfxEngine::SetFoggingRange(int a2, int a3) {
  
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]

  dword_3E2E24C = a2;
  dword_3E2E250 = a3;
  if ( a3 >= 0 )
  {
    if ( dword_3E2E24C >= dword_3E2E314 )
      v4 = dword_3E2E314;
    else
      v4 = dword_3E2E24C;
    dword_3E2E314 = v4;
    if ( dword_3E2E250 <= g_iFoggingRange )
      v3 = g_iFoggingRange;
    else
      v3 = dword_3E2E250;
    g_iFoggingRange = v3;
  }
  else
  {
    dword_3E2E24C = 2000;
    dword_3E2E250 = -1;
  }
}


// address=[0x2f5c950]
// Decompiled from bool __thiscall IGfxEngine::IsInitialized(IGfxEngine *this)
bool  IGfxEngine::IsInitialized(void) {
  
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup) )
    return HardwareIsRunning();
  else
    return SoftwareIsRunning();
}


// address=[0x2f5c980]
// Decompiled from char __thiscall IGfxEngine::IsHardwareEngine(IGfxEngine *this)
bool  IGfxEngine::IsHardwareEngine(void) {
  
  if ( this->m_bNeedsRebuild )
    return SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup);
  else
    return 0;
}


// address=[0x2f5c9b0]
// Decompiled from char __thiscall IGfxEngine::Use4444Palettes(IGfxEngine *this)
bool  IGfxEngine::Use4444Palettes(void) {
  
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup) )
    return g_bHardwareObjectEnabled;
  else
    return 0;
}


// address=[0x2f5c9e0]
// Decompiled from bool __thiscall IGfxEngine::IsGuiMode(IGfxEngine *this)
bool  IGfxEngine::IsGuiMode(void) {
  
  return GfxEngineSetup.m_bGuiOnly;
}


// address=[0x2f5c9f0]
// Decompiled from char __thiscall IGfxEngine::IsGfxEngineRebuilded(IGfxEngine *this)
bool  IGfxEngine::IsGfxEngineRebuilded(void) {
  
  if ( !D3DObjectPtr )
    return 1;
  if ( !D3DObjectPtr->m_bGfxEngineRebuilded )
    return 0;
  D3DObjectPtr->m_bGfxEngineRebuilded = 0;
  return 1;
}


// address=[0x2f5ca30]
// Decompiled from int __thiscall IGfxEngine::GetGfxMode(IGfxEngine *this)
int  IGfxEngine::GetGfxMode(void) {
  
  return g_uGfxMode;
}


// address=[0x2f5ca40]
// Decompiled from unsigned __int16 __cdecl IGfxEngine::ConvertRgbToHicol(int _uR, int _uG, int _uB)
unsigned short __cdecl IGfxEngine::ConvertRgbToHicol(int _uR, int _uG, int _uB) {
  
  __int16 v3; // ax

  if ( g_uGfxMode == 1 )
    v3 = 32 * (int)(float)((float)_uG * 0.12156863) + ((unsigned __int16)(int)(float)((float)_uR * 0.12156863) << 10);
  else
    v3 = 32 * (int)(float)((float)_uG * 0.24705882) + ((unsigned __int16)(int)(float)((float)_uR * 0.12156863) << 11);
  return (int)(float)((float)_uB * 0.12156863) + v3;
}


// address=[0x2f5cae0]
// Decompiled from int __thiscall IGfxEngine::GetOutputWidth(IGfxEngine *this)
int  IGfxEngine::GetOutputWidth(void) {
  
  return GfxEngineSetup.m_uWidth;
}


// address=[0x2f5caf0]
// Decompiled from int __thiscall IGfxEngine::GetOutputHeight(IGfxEngine *this)
int  IGfxEngine::GetOutputHeight(void) {
  
  return GfxEngineSetup.m_uHeight;
}


// address=[0x2f5cb00]
// Decompiled from int __thiscall IGfxEngine::GetClosestMapPoint(IGfxEngine *this, int a2, int a3)
int  IGfxEngine::GetClosestMapPoint(int a2, int a3) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  int v5; // [esp+4h] [ebp-8h] BYREF

  return SearchMapPoint(a2, a3, &v4, &v5, 0);
}


// address=[0x2f5cb30]
// Decompiled from size_t __thiscall IGfxEngine::GetClosestMapPoint(IGfxEngine *this, int a2, int a3, int *a4, int *a5)
int  IGfxEngine::GetClosestMapPoint(int a2, int a3, int & a4, int & a5) {
  
  return SearchMapPoint(a2, a3, a4, a5, 0);
}


// address=[0x2f5cb60]
// Decompiled from size_t __stdcall IGfxEngine::GetClosestMapPointOutsideMap(int a1, int a2, int *a3, int *a4)
int  IGfxEngine::GetClosestMapPointOutsideMap(int a1, int a2, int & a3, int & a4) {
  
  return SearchMapPoint(a1, a2, a3, a4, 1);
}


// address=[0x2f5cb90]
// Decompiled from int __cdecl IGfxEngine::GetScreenOffsetsByMapIndices(int a1, int a2, int *a3, int *a4)
int __cdecl IGfxEngine::GetScreenOffsetsByMapIndices(int a1, int a2, int & a3, int & a4) {
  
  if ( (a2 | a1) < 0 || a1 >= (int)Size || a2 >= (int)Size )
    return 0;
  ConvertMapIndexToScreenPosition(a1, a2, a3, a4);
  if ( (*a4 | *a3) < 0 || *a3 >= GfxEngineSetup.m_uWidth || *a4 >= GfxEngineSetup.m_uHeight )
    return 1;
  else
    return 3;
}


// address=[0x2f5cc10]
// Decompiled from int __cdecl IGfxEngine::GetScreenOffsetsByMapIndices_0(int a1, int *a2, int *a3)
int __cdecl IGfxEngine::GetScreenOffsetsByMapIndices(int a1, int & a2, int & a3) {
  
  if ( a1 < 0 || a1 >= (int)(Size * Size) )
    return 0;
  ConvertMapIndexToScreenPosition(a1 % (int)Size, a1 / (int)Size, a2, a3);
  if ( (*a3 | *a2) < 0 || *a2 >= GfxEngineSetup.m_uWidth || *a3 >= GfxEngineSetup.m_uHeight )
    return 1;
  else
    return 3;
}


// address=[0x2f5cca0]
// Decompiled from double __thiscall IGfxEngine::GetCurrentZoomFactor(IGfxEngine *this)
float  IGfxEngine::GetCurrentZoomFactor(void) {
  
  return g_fZoomFactor;
}


// address=[0x2f5ccc0]
// Decompiled from void __thiscall IGfxEngine::ShowCachePage(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::ShowCachePage(int a2, int a3) {
  
  dword_3E2E310 = a2;
  byte_3E2E324 = (a3 & 1) != 0;
  byte_3E2E325 = (a3 & 2) != 0;
}


// address=[0x2f5cd20]
// Decompiled from void __thiscall IGfxEngine::SetWidthOfLeftGuiBorder(IGfxEngine *this, int a2)
void  IGfxEngine::SetWidthOfLeftGuiBorder(int a2) {
  
  g_uLeftGuiBorderWidth = a2;
}


// address=[0x2f5f850]
// Decompiled from void __thiscall IGfxEngine::LockCursorShape(IGfxEngine *this, bool a2)
void  IGfxEngine::LockCursorShape(bool a2) {
  
  this->m_bLockCursorShape = a2;
}


// address=[0x2f5f870]
// Decompiled from void __thiscall IGfxEngine::SetCursorShape(IGfxEngine *this, bool a2, unsigned int a3)
void  IGfxEngine::SetCursorShape(bool a2, int a3) {
  
  if ( !this->m_bLockCursorShape && a3 < 0x24 )
  {
    if ( a2 )
    {
      if ( !s_bCursorIsVisible )
      {
        ShowCursor(1);
        s_bCursorIsVisible = 1;
      }
    }
    else if ( s_bCursorIsVisible )
    {
      ShowCursor(0);
      s_bCursorIsVisible = 0;
    }
    if ( s_hCursor )
      SetCursor(s_hCursorHandles[a3]);
    else
      s_hCursor = (LONG)SetCursor(s_hCursorHandles[a3]);
    SetClassLongA((HWND)GfxEngineSetup.m_hWnd, GCL_HCURSOR, (LONG)s_hCursorHandles[a3]);
    s_iCurrentCursor = a3;
  }
}


// address=[0x2f5f950]
// Decompiled from void __thiscall IGfxEngine::FixCursor(IGfxEngine *this, bool a2, bool a3)
void  IGfxEngine::FixCursor(bool a2, bool a3) {
  
  int CursorShape; // eax
  struct tagPOINT Point; // [esp+0h] [ebp-Ch] BYREF
  IGfxEngine *v5; // [esp+8h] [ebp-4h]

  v5 = this;
  if ( D3DObjectPtr && (!s_bCursorIsFixed || !a2) && (s_bCursorIsFixed || a2) )
  {
    if ( a2 )
    {
      GetCursorPos(&Point);
      ScreenToClient(GfxEngineSetup.m_hWnd, &Point);
      if ( a3 )
        CFixCursor::SetFixCursor((CFixCursor *)&D3DObjectPtr[1].m_sViewport.dwY, Point.x, Point.y, 1);
      else
        CFixCursor::SetFixCursor((CFixCursor *)&D3DObjectPtr[1].m_sClipper1.m_vChar.uC, Point.x, Point.y, 1);
      CursorShape = IGfxEngine::GetCursorShape(v5);
      v5->m_uFixedCursorShape = CursorShape;
      IGfxEngine::SetCursorShape(v5, 0, v5->m_uFixedCursorShape);
      s_bCursorIsFixed = 1;
    }
    else
    {
      IGfxEngine::SetCursorShape(v5, 1, v5->m_uFixedCursorShape);
      CFixCursor::SetFixCursor((CFixCursor *)&D3DObjectPtr[1].m_sClipper1.m_vChar.uC, 0, 0, 0);
      CFixCursor::SetFixCursor((CFixCursor *)&D3DObjectPtr[1].m_sViewport.dwY, 0, 0, 0);
      s_bCursorIsFixed = 0;
    }
  }
}


// address=[0x2f5fa70]
// Decompiled from int __thiscall IGfxEngine::GetCursorShape(IGfxEngine *this)
int  IGfxEngine::GetCursorShape(void) {
  
  if ( s_iCurrentCursor == -1 )
    s_iCurrentCursor = 0;
  return s_iCurrentCursor;
}


// address=[0x2f5faa0]
// Decompiled from char IGfxEngine::IsCursorVisible()
bool  IGfxEngine::IsCursorVisible(void) {
  
  return s_bCursorIsVisible;
}


// address=[0x2f5fab0]
// Decompiled from char IGfxEngine::IsCursorFixed()
bool  IGfxEngine::IsCursorFixed(void) {
  
  return s_bCursorIsFixed;
}


// address=[0x2f5fac0]
// Decompiled from char __thiscall IGfxEngine::IsResolutionPossible(IGfxEngine *this, unsigned int a2)
bool  IGfxEngine::IsResolutionPossible(int a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-1A0h] BYREF
  _DWORD v5[2]; // [esp+8h] [ebp-19Ch] BYREF
  int v6; // [esp+10h] [ebp-194h] BYREF
  int v7; // [esp+14h] [ebp-190h]
  int v8; // [esp+18h] [ebp-18Ch]
  unsigned __int64 v9; // [esp+1Ch] [ebp-188h]
  _DWORD v10[95]; // [esp+24h] [ebp-180h] BYREF

  if ( a2 <= 4 )
  {
    if ( D3DObjectPtr )
    {
      if ( D3DObjectPtr->m_pDDraw || D3DObjectPtr->m_bInitHardware || D3DObjectPtr->m_bInitSoftware )
      {
        v10[0] = 380;
        v8 = D3DObjectPtr->m_pDDraw->lpVtbl->GetCaps(D3DObjectPtr->m_pDDraw, (LPDDCAPS)v10, 0);
        if ( v8 )
        {
          WriteError(v8, "GetCapabilities");
          LOBYTE(v2) = 0;
        }
        else
        {
          v6 = 16;
          v8 = D3DObjectPtr->PrimarySurface->GetBitDepth(D3DObjectPtr->PrimarySurface, &v6);
          v9 = v10[15];
          if ( v8 )
          {
            WriteError(v8, "GetBitDepthWhileResChecking");
            LOBYTE(v2) = 0;
          }
          else
          {
            v8 = D3DObjectPtr->PrimarySurface->GetSurfaceSize(D3DObjectPtr->PrimarySurface, v5, &v4);
            if ( v8 )
            {
              WriteError(v8, "GetSurfaceSizeWhileResChecking");
              LOBYTE(v2) = 0;
            }
            else
            {
              v9 += v4 * v5[0] * (v6 / 8);
              v9 -= 810000LL;
              v9 -= 155000LL;
              if ( D3DObjectPtr->m_bInitHardware )
              {
                if ( BYTE1(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
                  v9 -= 6080000LL;
                else
                  v9 -= 1520000LL;
              }
              v5[1] = a2;
              switch ( a2 )
              {
                case 0u:
                  v7 = 1843200;
                  break;
                case 1u:
                  v7 = 2880000;
                  break;
                case 2u:
                  v7 = 4718592;
                  break;
                case 3u:
                  v7 = 7864320;
                  break;
                default:
                  v7 = 11520000;
                  break;
              }
              v9 -= v7;
              if ( v9 >= 0xC350 )
              {
                if ( GfxEngineSetup.m_bD3DInterface )
                {
                  WriteError(v8, "Cannot use DD3");
                  LOBYTE(v2) = 0;
                }
                else
                {
                  v8 = D3DObjectPtr->m_pDDraw7->lpVtbl->EnumDisplayModes(
                         D3DObjectPtr->m_pDDraw7,
                         2,
                         0,
                         0,
                         CInterfaceD3D::EnumModesCallback);
                  if ( v8 )
                  {
                    WriteError(v8, "EnumeratingDisplayModes");
                    LOBYTE(v2) = 0;
                  }
                  else
                  {
                    return D3DObjectPtr->field_71E[a2];
                  }
                }
              }
              else
              {
                BBSupportTracePrintF(1, "GFX ENGINE: Not enough video memory for requested mode!");
                LOBYTE(v2) = 0;
              }
            }
          }
        }
      }
      else
      {
        LOBYTE(v2) = 0;
      }
    }
    else
    {
      LOBYTE(v2) = 0;
    }
  }
  else
  {
    LOBYTE(v2) = 0;
  }
  return v2;
}


// address=[0x2f5fe60]
// Decompiled from char __thiscall IGfxEngine::CheckRenderConfiguration(IGfxEngine *this, struct SGfxRenderConfiguration a2)
bool  IGfxEngine::CheckRenderConfiguration(struct SGfxRenderConfiguration a2) {
  
  int v3; // [esp+4h] [ebp-19Ch] BYREF
  int v4; // [esp+8h] [ebp-198h] BYREF
  int v5; // [esp+Ch] [ebp-194h] BYREF
  int v7; // [esp+14h] [ebp-18Ch]
  unsigned __int64 v8; // [esp+18h] [ebp-188h]
  _DWORD v9[95]; // [esp+20h] [ebp-180h] BYREF

  CheckConfiguration(&a2);
  if ( (!SGfxRenderConfiguration::IsHardwareLandscapeEngine(&a2) || this->m_bHardwareRenderingPossible)
    && (SGfxRenderConfiguration::IsHardwareLandscapeEngine(&a2) || this->m_bSoftwareRenderingPossible) )
  {
    if ( D3DObjectPtr )
    {
      if ( D3DObjectPtr->m_pDDraw || D3DObjectPtr->m_bInitHardware || D3DObjectPtr->m_bInitSoftware )
      {
        v9[0] = 380;
        v7 = D3DObjectPtr->m_pDDraw->lpVtbl->GetCaps(D3DObjectPtr->m_pDDraw, (LPDDCAPS)v9, 0);
        if ( v7 )
        {
          WriteError(v7, "GetCapabilities");
          return 0;
        }
        else
        {
          v5 = 16;
          v7 = D3DObjectPtr->PrimarySurface->GetBitDepth(D3DObjectPtr->PrimarySurface, &v5);
          v8 = v9[15];
          if ( v7 )
          {
            WriteError(v7, "GetBitDepthWhileResChecking");
            return 0;
          }
          else
          {
            v7 = D3DObjectPtr->PrimarySurface->GetSurfaceSize(D3DObjectPtr->PrimarySurface, &v4, &v3);
            if ( v7 )
            {
              WriteError(v7, "GetSurfaceSizeWhileResChecking");
              return 0;
            }
            else
            {
              v8 += v3 * v4 * (v5 / 8);
              v8 -= 810000LL;
              v8 -= 155000LL;
              if ( D3DObjectPtr->m_bInitHardware )
              {
                if ( BYTE1(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
                  v8 -= 6080000LL;
                else
                  v8 -= 1520000LL;
              }
              v8 -= 6 * a2.m_uHeight * a2.m_uWidth;
              if ( v8 >= 0xC350 )
              {
                if ( GfxEngineSetup.m_bD3DInterface )
                {
                  WriteError(v7, "Cannot use DD3");
                  return 0;
                }
                else
                {
                  v7 = D3DObjectPtr->m_pDDraw7->lpVtbl->EnumDisplayModes(
                         D3DObjectPtr->m_pDDraw7,
                         2,
                         0,
                         0,
                         CInterfaceD3D::EnumModesCallback);
                  if ( v7 )
                  {
                    WriteError(v7, "EnumeratingDisplayModes");
                    return 0;
                  }
                  else
                  {
                    return 1;
                  }
                }
              }
              else
              {
                BBSupportTracePrintF(1, "GFX ENGINE: Not enough video memory for requested mode!");
                return 0;
              }
            }
          }
        }
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return 0;
    }
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: The requested renderer is not available!");
    return 0;
  }
}


// address=[0x2f601f0]
// Decompiled from char __thiscall IGfxEngine::ShowFrame(IGfxEngine *this)
bool  IGfxEngine::ShowFrame(void) {
  
  if ( IsIconic(GfxEngineSetup.m_hWnd) )
    return 1;
  if ( g_iRefreshWaitFrames )
    return 1;
  if ( D3DObjectPtr )
  {
    if ( LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
      return 0;
    else
      return CInterfaceD3D::BlitSurfaceToWindow(D3DObjectPtr);
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Call to ShowFrame without initializing the engine!");
    return 0;
  }
}


// address=[0x2f60260]
// Decompiled from char __thiscall IGfxEngine::SolidColorFillGuiSurface(  IGfxEngine *this,  int a2,  unsigned __int8 a3,  unsigned __int8 a4,  unsigned __int8 a5)
bool  IGfxEngine::SolidColorFillGuiSurface(int a2, unsigned char a3, unsigned char a4, unsigned char a5) {
  
  int v6; // [esp+8h] [ebp-14h]

  if ( !D3DObjectPtr || (unsigned int)a2 >= 0xE )
    return 0;
  if ( !D3DObjectPtr->m_pGuiSurfaces[a2] )
    return 0;
  if ( dword_468A558 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_468A558);
    if ( dword_468A558 == -1 )
    {
      CBlitFX::CBlitFX(&s_cSolidFillFX);
      j___Init_thread_footer(&dword_468A558);
    }
  }
  CBlitFX::SetFillColor(&s_cSolidFillFX, a3, a4, a5, g_uGfxMode == 1);
  v6 = D3DObjectPtr->m_pGuiSurfaces[a2]->ClearSurface(D3DObjectPtr->m_pGuiSurfaces[a2], (_BYTE *)&s_cSolidFillFX);
  if ( !v6 )
    return 1;
  WriteError(v6, "SetGuiSurfaceSolidColor");
  return 0;
}


// address=[0x2f603b0]
// Decompiled from char __thiscall IGfxEngine::SolidColorFillGuiSurface(  IGfxEngine *this,  unsigned int a2,  unsigned __int8 a3,  unsigned __int8 a4,  unsigned __int8 a5,  struct tagRECT a6)
bool  IGfxEngine::SolidColorFillGuiSurface(int a2, unsigned char a3, unsigned char a4, unsigned char a5, struct tagRECT a6) {
  
  int v7; // [esp+8h] [ebp-14h]

  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( !D3DObjectPtr->m_pGuiSurfaces[a2] )
    return 0;
  if ( dword_468A5D8 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_468A5D8);
    if ( dword_468A5D8 == -1 )
    {
      CBlitFX::CBlitFX(&s_cSolidRectFillFX);
      j___Init_thread_footer(&dword_468A5D8);
    }
  }
  CBlitFX::SetFillColor(&s_cSolidRectFillFX, a3, a4, a5, g_uGfxMode == 1);
  v7 = D3DObjectPtr->m_pGuiSurfaces[a2]->ClearSurface_(
         D3DObjectPtr->m_pGuiSurfaces[a2],
         a6.left,
         a6.top,
         a6.right,
         a6.bottom,
         &s_cSolidRectFillFX);
  if ( !v7 )
    return 1;
  WriteError(v7, "SetGuiSurfaceSolidColor");
  return 0;
}


// address=[0x2f699c0]
// Decompiled from char __thiscall IGfxEngine::RenderObject(IGfxEngine *this, int a2, int a3, struct SGfxObjectInfo *a4, int a5, int a6)
bool  IGfxEngine::RenderObject(int a2, int a3, struct SGfxObjectInfo * a4, int a5, int a6) {
  
  float v7; // [esp+4h] [ebp-14h]
  int v8; // [esp+8h] [ebp-10h]
  int v9; // [esp+Ch] [ebp-Ch] BYREF
  int v10; // [esp+10h] [ebp-8h] BYREF
  int v11; // [esp+14h] [ebp-4h]

  if ( !D3DObjectPtr || !D3DObjectPtr->FinalRenderSurface )
    return 0;
  if ( a6 == 1 )
  {
    if ( byte_468DD14 )
    {
      return 0;
    }
    else
    {
      v11 = D3DObjectPtr->FinalRenderSurface->Lock(D3DObjectPtr->FinalRenderSurface, &dword_468DD10, &dword_468DD0C, 1);
      if ( v11 )
      {
        WriteError(v11, "LockRenderSurfaceForEditor");
        return 0;
      }
      else
      {
        byte_468DD14 = 1;
        return 1;
      }
    }
  }
  else if ( a6 == 2 )
  {
    if ( byte_468DD14 )
    {
      v11 = D3DObjectPtr->FinalRenderSurface->Unlock(D3DObjectPtr->FinalRenderSurface, this);
      if ( v11 )
      {
        WriteError(v11, "UnlockRenderSurfaceForEditor");
        return 0;
      }
      else
      {
        byte_468DD14 = 0;
        AddGuiPatches();
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
  else if ( byte_468DD14 )
  {
    v8 = *(_DWORD *)g_pZoomGradient;
    v7 = g_fZoomFactor;
    if ( a5 != 256 )
    {
      *(_DWORD *)g_pZoomGradient *= a5 / 256;
      g_fZoomFactor = (float)(a5 / 256) * g_fZoomFactor;
    }
    g_pRenderAdress = dword_468DD0C;
    g_pBeginOfRenderBuffer = dword_468DD0C;
    g_iRenderPitch = dword_468DD10;
    g_iScanlineLength = 2 * GfxEngineSetup.m_uWidth;
    g_pEndOfRenderBuffer = 2 * GfxEngineSetup.m_uWidth + dword_468DD0C + dword_468DD10 * (GfxEngineSetup.m_uHeight - 1);
    IGfxEngine::GetScreenOffsetsByMapIndices(a2, a3, &v9, &v10);
    if ( *(_DWORD *)a4 )
    {
      if ( *((_BYTE *)a4 + 712) == 1 )
        BlitSettler(255, v9 << 16, v10 << 16, a4);
      else
        BlitObject(255, v9 << 16, v10 << 16, a4);
      *(_DWORD *)g_pZoomGradient = v8;
      g_fZoomFactor = v7;
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }
}


// address=[0x2f69c10]
// Decompiled from char __thiscall IGfxEngine::RenderResource(IGfxEngine *this, int a2, int a3, void *a4, void *a5, void *a6, int a7)
bool  IGfxEngine::RenderResource(int a2, int a3, void * a4, void * a5, void * a6, int a7) {
  
  float v8; // [esp+4h] [ebp-2E8h]
  int v9; // [esp+8h] [ebp-2E4h]
  int v10; // [esp+Ch] [ebp-2E0h] BYREF
  int v11; // [esp+10h] [ebp-2DCh] BYREF
  int v12; // [esp+14h] [ebp-2D8h]
  void *v13; // [esp+18h] [ebp-2D4h] BYREF
  void *v14; // [esp+1Ch] [ebp-2D0h]
  char v15; // [esp+2Eh] [ebp-2BEh]
  char v16; // [esp+2E2h] [ebp-Ah]

  if ( a7 == 1 )
  {
    if ( !byte_468DD08 && D3DObjectPtr->FinalRenderSurface )
    {
      v12 = D3DObjectPtr->FinalRenderSurface->Lock(D3DObjectPtr->FinalRenderSurface, &dword_468DD04, &dword_468DD00, 1);
      if ( v12 )
      {
        WriteError(v12, "LockRenderSurfaceForResources");
        return 0;
      }
      else
      {
        byte_468DD08 = 1;
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
  else if ( a7 == 2 )
  {
    if ( byte_468DD08 )
    {
      v12 = D3DObjectPtr->FinalRenderSurface->Unlock(D3DObjectPtr->FinalRenderSurface, this);
      if ( v12 )
      {
        WriteError(v12, "UnlockRenderSurfaceForResources");
        return 0;
      }
      else
      {
        byte_468DD08 = 0;
        AddGuiPatches();
        return 1;
      }
    }
    else
    {
      return 0;
    }
  }
  else if ( byte_468DD08 )
  {
    v9 = *g_pZoomGradient;
    v8 = g_fZoomFactor;
    *g_pZoomGradient = (int)(float)((float)*g_pZoomGradient * 0.75);
    g_fZoomFactor = g_fZoomFactor * 0.75;
    g_pRenderAdress = dword_468DD00;
    g_pBeginOfRenderBuffer = dword_468DD00;
    g_iRenderPitch = dword_468DD04;
    g_iScanlineLength = 2 * GfxEngineSetup.m_uWidth;
    g_pEndOfRenderBuffer = 2 * GfxEngineSetup.m_uWidth + dword_468DD00 + dword_468DD04 * (GfxEngineSetup.m_uHeight - 1);
    IGfxEngine::GetScreenOffsetsByMapIndices(a2, a3, &v10, &v11);
    v16 = 1;
    v14 = a4;
    v13 = a5;
    v15 = 0;
    BlitObject(255, v10 << 16, v11 << 16, (struct SGfxObjectInfo *)&v13);
    v14 = (void *)g_pIconPalette;
    v13 = a6;
    BlitObject(255, (v10 + (int)(float)(5.0 * g_fZoomFactor)) << 16, v11 << 16, (struct SGfxObjectInfo *)&v13);
    *g_pZoomGradient = v9;
    g_fZoomFactor = v8;
    return 1;
  }
  else
  {
    return 0;
  }
}


// address=[0x2f69ec0]
// Decompiled from void __thiscall IGfxEngine::SetEffectSystemInterfacePtr(IGfxEngine *this, struct IGfxEffects *a2)
void  IGfxEngine::SetEffectSystemInterfacePtr(class IGfxEffects * a2) {
  
  s_pEffectSystem = a2;
}


// address=[0x2f72f10]
// Decompiled from void __thiscall IGfxEngine::EnableDebugValueCallback(IGfxEngine *this, int (__cdecl *a2)(int, int))
void  IGfxEngine::EnableDebugValueCallback(int (__cdecl*)(int,int) a2) {
  
  s_pfDebugValueCallback = a2;
}


// address=[0x2f72f30]
// Decompiled from void __thiscall IGfxEngine::EnableDebugStringCallback(IGfxEngine *this, char *(__cdecl *a2)())
void  IGfxEngine::EnableDebugStringCallback(char * (__cdecl*)(void) a2) {
  
  s_pfDebugStringCallback = a2;
}


// address=[0x2f72f50]
// Decompiled from unsigned int __thiscall IGfxEngine::CreateGuiSurface(  IGfxEngine *this,  unsigned int _iIndex,  struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *a3)
int  IGfxEngine::CreateGuiSurface(int _iIndex, struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION * a3) {
  
  int v4; // eax
  CSurfaceV7 *pSurface; // [esp+18h] [ebp-1Ch]
  IDirectDraw7 *m_pDDraw; // [esp+1Ch] [ebp-18h]
  int v7; // [esp+24h] [ebp-10h]
  CSurfaceV7 *v8; // [esp+28h] [ebp-Ch]
  int v9; // [esp+2Ch] [ebp-8h]
  unsigned int i; // [esp+30h] [ebp-4h]

  if ( !D3DObjectPtr )
    return -1;
  if ( LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
    return -1;
  if ( !this->m_bNeedsRebuild && !D3DObjectPtr->m_bInitHardware && !D3DObjectPtr->m_bInitSoftware )
    BBSupportTracePrintF(0, "GFX ENGINE: Call to CreateGuiSurface without initializing the engine before!");
  if ( _iIndex >= 14 )
    return -1;
  if ( D3DObjectPtr->m_pGuiSurfaces[_iIndex] )
    return -1;
  D3DObjectPtr->m_pGuiSurfaces[_iIndex] = CSurface::CreateSurfacePtr(GfxEngineSetup.m_bD3DInterface);
  if ( D3DObjectPtr->m_pGuiSurfaces[_iIndex] )
  {
    if ( GfxEngineSetup.m_bD3DInterface )
      m_pDDraw = D3DObjectPtr->m_pDDraw;
    else
      m_pDDraw = D3DObjectPtr->m_pDDraw7;
    v4 = j__abs(g_uGfxMode == 1);
    pSurface = D3DObjectPtr->m_pGuiSurfaces[_iIndex]->CreateSurface(
                 D3DObjectPtr->m_pGuiSurfaces[_iIndex],
                 m_pDDraw,
                 a3->m_uU0,
                 a3->m_uU4,
                 1,
                 0,
                 0,
                 v4,
                 0,
                 0,
                 0);
    if ( pSurface )
    {
      v8 = D3DObjectPtr->m_pGuiSurfaces[_iIndex];
      if ( v8 )
        v8->dtor(v8, 1);
      D3DObjectPtr->m_pGuiSurfaces[_iIndex] = 0;
      WriteError((int)pSurface, "CreateGuiSurface:");
      return -1;
    }
    else
    {
      g_bGuiSurfaceVisible[_iIndex] = 0;
      qmemcpy(&g_pGuiSurfaceDescriptors[_iIndex], a3, sizeof(GFX_ENGINE_GUI_SURFACE_DESCRIPTION));
      ClipGuiSurface(_iIndex);
      v9 = 0;
      v7 = 0;
      for ( i = 0; i < 0xE; ++i )
      {
        if ( D3DObjectPtr->m_pGuiSurfaces[i] )
        {
          ++v7;
          v9 += 2 * stru_468DFA4[i].m_uU0 * g_pGuiSurfaceDescriptors[i].m_uU0;
        }
      }
      if ( CInterfaceD3D::GetGuiMemorySize(D3DObjectPtr) >= v9 )
        return _iIndex;
      CInterfaceD3D::SetGuiMemorySize(D3DObjectPtr, v9);
      BBSupportTracePrintF(
        0,
        "GFX ENGINE: New max size reached: Surfaces currently used by gui: %d Used vid-mem: %d",
        v7,
        v9);
      return _iIndex;
    }
  }
  else
  {
    BBSupportTracePrintF(0, "GFX ENGINE: Not enough memory to create surface object!");
    return -1;
  }
}


// address=[0x2f73220]
// Decompiled from unsigned int __thiscall IGfxEngine::CreateGuiSurface(IGfxEngine *this, struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *a2)
int  IGfxEngine::CreateGuiSurface(struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION * a2) {
  
  signed int v3; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  if ( !D3DObjectPtr )
    return -1;
  v3 = -1;
  for ( i = 0; i < 0xE; ++i )
  {
    if ( !D3DObjectPtr->m_pGuiSurfaces[i] )
    {
      v3 = i;
      break;
    }
  }
  if ( v3 >= 0 )
    return IGfxEngine::CreateGuiSurface(this, v3, a2);
  else
    return -1;
}


// address=[0x2f732a0]
// Decompiled from char __thiscall IGfxEngine::DestroyGuiSurface(IGfxEngine *this, unsigned int a2)
bool  IGfxEngine::DestroyGuiSurface(int a2) {
  
  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
    return 0;
  if ( !D3DObjectPtr->m_pGuiSurfaces[a2] )
    return 0;
  D3DObjectPtr->m_pGuiSurfaces[a2]->Release(D3DObjectPtr->m_pGuiSurfaces[a2], this);
  if ( D3DObjectPtr->m_pGuiSurfaces[a2] )
    D3DObjectPtr->m_pGuiSurfaces[a2]->dtor(D3DObjectPtr->m_pGuiSurfaces[a2], 1);
  D3DObjectPtr->m_pGuiSurfaces[a2] = 0;
  g_bGuiSurfaceVisible[a2] = 0;
  return 1;
}


// address=[0x2f73390]
// Decompiled from char __thiscall IGfxEngine::SetVisibilityOfGuiSurface(IGfxEngine *this, unsigned int a2, char a3)
bool  IGfxEngine::SetVisibilityOfGuiSurface(int a2, bool a3) {
  
  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
    return 0;
  if ( !D3DObjectPtr->m_pGuiSurfaces[a2] )
    return 0;
  g_bGuiSurfaceVisible[a2] = a3;
  return 1;
}


// address=[0x2f733f0]
// Decompiled from char __thiscall IGfxEngine::SetGuiSurfaceDestinationPosition(IGfxEngine *this, unsigned int a2, int a3, int a4)
bool  IGfxEngine::SetGuiSurfaceDestinationPosition(int a2, int a3, int a4) {
  
  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( !D3DObjectPtr->m_pGuiSurfaces[a2] )
    return 0;
  OffsetRect(
    &g_pGuiSurfaceDescriptors[a2].m_sDestinationRect,
    a3 - g_pGuiSurfaceDescriptors[a2].m_sDestinationRect.left,
    a4 - g_pGuiSurfaceDescriptors[a2].m_sDestinationRect.top);
  ClipGuiSurface(a2);
  return 1;
}


// address=[0x2f73480]
// Decompiled from char __thiscall IGfxEngine::SetGuiSurfaceDestinationRect(IGfxEngine *this, unsigned int a2, const struct tagRECT *a3)
bool  IGfxEngine::SetGuiSurfaceDestinationRect(int a2, struct tagRECT const & a3) {
  
  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( !D3DObjectPtr->m_pGuiSurfaces[a2] )
    return 0;
  *(struct tagRECT *)&stru_468DFA4[a2].m_uU4 = *a3;
  ClipGuiSurface(a2);
  return 1;
}


// address=[0x2f734f0]
// Decompiled from bool IGfxEngine::GetGuiSurfaceDestinationRect(int a1, struct tagRECT *a2)
bool  IGfxEngine::GetGuiSurfaceDestinationRect(int a1, struct tagRECT & a2) {
  
  if ( !D3DObjectPtr || (unsigned int)a1 >= 0xE )
    return 0;
  if ( LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
    return 0;
  if ( !D3DObjectPtr->m_pGuiSurfaces[a1] )
    return 0;
  *a2 = *(struct tagRECT *)&stru_468DFA4[a1].m_uU4;
  return 1;
}


// address=[0x2f73570]
// Decompiled from char __thiscall IGfxEngine::GetGuiSurfaceDescription(  IGfxEngine *this,  unsigned int a2,  struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *a3)
bool  IGfxEngine::GetGuiSurfaceDescription(int a2, struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION & a3) {
  
  if ( a2 >= 0xE )
    return 0;
  if ( !D3DObjectPtr->m_pGuiSurfaces[a2] )
    return 0;
  qmemcpy(a3, &g_pGuiSurfaceDescriptors[a2], sizeof(struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION));
  return 1;
}


// address=[0x2f735c0]
// Decompiled from int __thiscall IGfxEngine::BeginWriteToSurface(IGfxEngine *this, unsigned int a2, unsigned int *a3)
unsigned short *  IGfxEngine::BeginWriteToSurface(int a2, unsigned int & a3) {
  
  int v4; // [esp+8h] [ebp-Ch] BYREF
  int v5; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
    return 0;
  if ( !D3DObjectPtr->m_pGuiSurfaces[a2] )
    return 0;
  if ( D3DObjectPtr->m_pGuiSurfaces[a2]->IsLost(D3DObjectPtr->m_pGuiSurfaces[a2]) == -2005532222 )
  {
    for ( i = 0; i < 0xE; ++i )
    {
      if ( D3DObjectPtr->m_pGuiSurfaces[i] )
      {
        if ( D3DObjectPtr->m_pGuiSurfaces[i]->IsLost(D3DObjectPtr->m_pGuiSurfaces[i]) == -2005532222 )
        {
          v5 = D3DObjectPtr->m_pGuiSurfaces[i]->Restore(D3DObjectPtr->m_pGuiSurfaces[i]);
          if ( v5 )
          {
            WriteError(v5, "RestoreGuiSurface");
            BBSupportTracePrintF(0, "GFX ENGINE: Problem with gui surfaces! Stop rendering...");
            LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
            return 0;
          }
        }
      }
    }
    D3DObjectPtr->m_bGfxEngineRebuilded = 1;
  }
  v5 = D3DObjectPtr->m_pGuiSurfaces[a2]->Lock(D3DObjectPtr->m_pGuiSurfaces[a2], (int *)a3, &v4, 1);
  if ( v5 )
    return 0;
  else
    return v4;
}


// address=[0x2f73770]
// Decompiled from char __thiscall IGfxEngine::EndWriteToSurface(IGfxEngine *this, unsigned int a2)
bool  IGfxEngine::EndWriteToSurface(int a2) {
  
  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
    return 0;
  if ( !D3DObjectPtr->m_pGuiSurfaces[a2] )
    return 0;
  ((void (__thiscall *)(CSurfaceV7 *, IGfxEngine *))D3DObjectPtr->m_pGuiSurfaces[a2]->Unlock)(
    D3DObjectPtr->m_pGuiSurfaces[a2],
    this);
  return 1;
}


// address=[0x2f737f0]
// Decompiled from char __thiscall IGfxEngine::GetGuiSurfaceDC(IGfxEngine *this, unsigned int a2, HDC *a3)
bool  IGfxEngine::GetGuiSurfaceDC(int a2, struct HDC__ * * a3) {
  
  int v4; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
    return 0;
  if ( !D3DObjectPtr->m_pGuiSurfaces[a2] )
    return 0;
  if ( D3DObjectPtr->m_pGuiSurfaces[a2]->IsLost(D3DObjectPtr->m_pGuiSurfaces[a2]) == -2005532222 )
  {
    for ( i = 0; i < 0xE; ++i )
    {
      if ( D3DObjectPtr->m_pGuiSurfaces[i] )
      {
        if ( D3DObjectPtr->m_pGuiSurfaces[i]->IsLost(D3DObjectPtr->m_pGuiSurfaces[i]) == -2005532222 )
        {
          v4 = D3DObjectPtr->m_pGuiSurfaces[i]->Restore(D3DObjectPtr->m_pGuiSurfaces[i]);
          if ( v4 )
          {
            WriteError(v4, "RestoreGuiSurface");
            BBSupportTracePrintF(0, "GFX ENGINE: Problem with gui surfaces! Stop rendering...");
            LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) = 1;
            return 0;
          }
        }
      }
    }
    D3DObjectPtr->m_bGfxEngineRebuilded = 1;
  }
  D3DObjectPtr->m_pGuiSurfaces[a2]->GetDC(D3DObjectPtr->m_pGuiSurfaces[a2], a3);
  return 1;
}


// address=[0x2f73980]
// Decompiled from bool __thiscall IGfxEngine::ReleaseGuiSurfaceDC(IGfxEngine *this, unsigned int a2, HDC a3)
bool  IGfxEngine::ReleaseGuiSurfaceDC(int a2, struct HDC__ * a3) {
  
  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
    return 0;
  if ( D3DObjectPtr->m_pGuiSurfaces[a2] )
    return D3DObjectPtr->m_pGuiSurfaces[a2]->ReleaseDC(D3DObjectPtr->m_pGuiSurfaces[a2], a3) == 0;
  return 0;
}


// address=[0x2f73a10]
// Decompiled from char __thiscall IGfxEngine::SetGuiSurfaceClipRect(IGfxEngine *this, const struct tagRECT *_rRect)
bool  IGfxEngine::SetGuiSurfaceClipRect(struct tagRECT const & _rRect) {
  
  SurfaceClipper *v3; // eax
  struct SurfaceClipper *v4; // eax
  SurfaceClipper *v5; // eax
  struct IDirectDraw7 *m_pDDraw; // [esp-4h] [ebp-14h]
  char v7[4]; // [esp+0h] [ebp-10h] BYREF
  int v8; // [esp+4h] [ebp-Ch]
  HRESULT inited; // [esp+Ch] [ebp-4h]

  if ( !D3DObjectPtr || LOBYTE(D3DObjectPtr[1].m_sClipper1.m_vChar.u8) )
    return 0;
  v8 = ((int (__cdecl *)(char *))std::make_unique<SurfaceClipper,>)(v7);
  std::unique_ptr<SurfaceClipper>::operator=(v8);
  std::unique_ptr<SurfaceClipper>::~unique_ptr<SurfaceClipper>(v7);
  if ( GfxEngineSetup.m_bD3DInterface )
    m_pDDraw = D3DObjectPtr->m_pDDraw;
  else
    m_pDDraw = D3DObjectPtr->m_pDDraw7;
  v3 = std::unique_ptr<SurfaceClipper>::operator->(&this->m_pSurfaceClipper);
  inited = SurfaceClipper::InitClipper(v3, m_pDDraw);
  if ( inited >= 0 )
  {
    v4 = std::unique_ptr<SurfaceClipper>::operator->(&this->m_pSurfaceClipper);
    inited = SurfaceClipper::SetClipRect(v4, _rRect);
    if ( inited >= 0 )
    {
      return 1;
    }
    else
    {
      WriteError(inited, "SetClipListToRect");
      v5 = std::unique_ptr<SurfaceClipper>::operator->(&this->m_pSurfaceClipper);
      SurfaceClipper::ReleaseClipper(v5);
      return 0;
    }
  }
  else
  {
    WriteError(inited, "SetGuiSurfaceClipRect");
    return 0;
  }
}


// address=[0x2f73b20]
// Decompiled from _DWORD *__thiscall IGfxEngine::ClearGuiSurfaceClipRect(IGfxEngine *this)
void  IGfxEngine::ClearGuiSurfaceClipRect(void) {
  
  return std::unique_ptr<SurfaceClipper>::reset(&this->m_pSurfaceClipper, 0);
}


// address=[0x2f5cd40]
// Decompiled from bool __thiscall IGfxEngine::IsHardwareRenderingAvailable(IGfxEngine *this)
bool  IGfxEngine::IsHardwareRenderingAvailable(void) {
  
  int IsInterface7Available; // eax
  SGfxRenderConfiguration v3; // [esp+Ch] [ebp-74h] BYREF
  SGfxRenderConfiguration v4; // [esp+30h] [ebp-50h] BYREF
  void *v5; // [esp+54h] [ebp-2Ch]
  CInterfaceD3D *v6; // [esp+58h] [ebp-28h]
  CInterfaceD3D *v7; // [esp+5Ch] [ebp-24h]
  CInterfaceD3D *v8; // [esp+64h] [ebp-1Ch]
  CInterfaceD3D *v9; // [esp+68h] [ebp-18h]
  void *C; // [esp+6Ch] [ebp-14h]
  int v12; // [esp+7Ch] [ebp-4h]

  if ( D3DObjectPtr && (D3DObjectPtr->m_bInitHardware || D3DObjectPtr->m_bInitSoftware) )
    return 0;
  qmemcpy(&v3, &GfxEngineSetup, sizeof(v3));
  *(_WORD *)&v4.m_uUnkConf0 = 1;
  v4.m_bD3DInterface = 0;
  v4.m_uFlags = 2;
  v4.m_hWnd = 0;
  v4.m_uWidth = v3.m_uWidth;
  v4.m_uHeight = v3.m_uHeight;
  memset(&v4.m_uX, 0, 16);
  qmemcpy(&GfxEngineSetup, &v4, sizeof(GfxEngineSetup));
  if ( D3DObjectPtr
    || ((C = operator new(0x794u), v12 = 0, !C) ? (v9 = 0) : (v9 = CInterfaceD3D::CInterfaceD3D((CInterfaceD3D *)C)),
        v7 = v9,
        v12 = -1,
        (D3DObjectPtr = v9) != 0) )
  {
    IsInterface7Available = CInterfaceD3D::IsInterface7Available(
                              D3DObjectPtr,
                              &this->m_bHardwareObjectPossible,
                              v3.m_hWnd);
    this->m_bV7Available = IsInterface7Available;
    v6 = D3DObjectPtr;
    v8 = D3DObjectPtr;
    if ( D3DObjectPtr )
      v5 = delete v8;
    else
      v5 = 0;
    D3DObjectPtr = 0;
    qmemcpy(&GfxEngineSetup, &v3, sizeof(GfxEngineSetup));
    return this->m_bV7Available == 0;
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: GFX ENGINE: Couldn't create gfx engine interface object!");
    qmemcpy(&GfxEngineSetup, &v3, sizeof(GfxEngineSetup));
    return 0;
  }
}


// address=[0x2f5cf10]
// Decompiled from bool __thiscall IGfxEngine::IsSoftwareRenderingAvailable(IGfxEngine *this)
bool  IGfxEngine::IsSoftwareRenderingAvailable(void) {
  
  int IsInterface3Available; // eax
  SGfxRenderConfiguration v3; // [esp+Ch] [ebp-74h] BYREF
  SGfxRenderConfiguration v4; // [esp+30h] [ebp-50h] BYREF
  void *v5; // [esp+54h] [ebp-2Ch]
  CInterfaceD3D *v6; // [esp+58h] [ebp-28h]
  CInterfaceD3D *v7; // [esp+5Ch] [ebp-24h]
  CInterfaceD3D *v8; // [esp+64h] [ebp-1Ch]
  CInterfaceD3D *v9; // [esp+68h] [ebp-18h]
  void *C; // [esp+6Ch] [ebp-14h]
  IGfxEngine *v11; // [esp+70h] [ebp-10h]
  int v12; // [esp+7Ch] [ebp-4h]

  v11 = this;
  if ( D3DObjectPtr && (D3DObjectPtr->m_bInitHardware || D3DObjectPtr->m_bInitSoftware) )
    return 0;
  qmemcpy(&v3, &GfxEngineSetup, sizeof(v3));
  v4.m_uUnkConf0 = 0;
  v4.m_bGuiOnly = 0;
  v4.m_bD3DInterface = 0;
  v4.m_uFlags = 2;
  v4.m_hWnd = 0;
  v4.m_uWidth = v3.m_uWidth;
  v4.m_uHeight = v3.m_uHeight;
  memset(&v4.m_uX, 0, 16);
  qmemcpy(&GfxEngineSetup, &v4, sizeof(GfxEngineSetup));
  if ( D3DObjectPtr
    || ((C = operator new(0x794u), v12 = 0, !C) ? (v9 = 0) : (v9 = CInterfaceD3D::CInterfaceD3D((CInterfaceD3D *)C)),
        v7 = v9,
        v12 = -1,
        (D3DObjectPtr = v9) != 0) )
  {
    if ( g_pDirectDraw )
    {
      v11->m_bV3Available = 0;
    }
    else
    {
      IsInterface3Available = CInterfaceD3D::IsInterface3Available(D3DObjectPtr, v3.m_hWnd);
      v11->m_bV3Available = IsInterface3Available;
    }
    v6 = D3DObjectPtr;
    v8 = D3DObjectPtr;
    if ( D3DObjectPtr )
      v5 = delete v8;
    else
      v5 = 0;
    D3DObjectPtr = 0;
    qmemcpy(&GfxEngineSetup, &v3, sizeof(GfxEngineSetup));
    return v11->m_bV3Available == 0;
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: GFX ENGINE: Couldn't create gfx engine interface object!");
    qmemcpy(&GfxEngineSetup, &v3, sizeof(GfxEngineSetup));
    return 0;
  }
}


// address=[0x2f60510]
// Decompiled from char __thiscall IGfxEngine::SetRenderEnvironment(IGfxEngine *this)
bool  IGfxEngine::SetRenderEnvironment(void) {
  
  CInterfaceD3D *v3; // [esp+14h] [ebp-1Ch]
  CInterfaceD3D *C; // [esp+18h] [ebp-18h]
  char inited; // [esp+23h] [ebp-Dh]
  char v6; // [esp+23h] [ebp-Dh]

  if ( D3DObjectPtr )
  {
    delete D3DObjectPtr;
    C = (CInterfaceD3D *)operator new(0x794u);
    if ( C )
      v3 = CInterfaceD3D::CInterfaceD3D(C);
    else
      v3 = 0;
    D3DObjectPtr = v3;
    if ( !v3 )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Couldn't create gfx engine interface object!");
      return 0;
    }
    if ( GfxEngineSetup.m_bD3DInterface )
      inited = CInterfaceD3D::InitCommonV3(D3DObjectPtr);
    else
      inited = CInterfaceD3D::InitCommon(D3DObjectPtr);
    IGfxEngine::SetCameraTriangleSize(this, 1572864);
    if ( !inited )
      return 0;
    if ( GfxEngineSetup.m_bGuiOnly )
      return 1;
    if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine(&GfxEngineSetup) )
      v6 = CInterfaceD3D::InitHardware(D3DObjectPtr);
    else
      v6 = CInterfaceD3D::InitSoftware(D3DObjectPtr);
    if ( !v6 )
      return 0;
    if ( !CInterfaceD3D::LoadTexturePageContents(D3DObjectPtr) )
      return 0;
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Engine is not initialized!");
  }
  InitGradientTable();
  IGfxEngine::SetCursorShape(this, 1, 0);
  BBSupportTracePrintF(1, "GFX ENGINE: Init complete.");
  return 1;
}


