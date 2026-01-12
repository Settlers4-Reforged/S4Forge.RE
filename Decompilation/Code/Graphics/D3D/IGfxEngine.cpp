#include "IGfxEngine.h"

// Definitions for class IGfxEngine

// address=[0x2f5a390]
// Decompiled from IGfxEngine *__thiscall IGfxEngine::IGfxEngine(IGfxEngine *this)
 IGfxEngine::IGfxEngine(void) {
  
  *((_BYTE *)this + 33) = 0;
  std::unique_ptr<SurfaceClipper>::unique_ptr<SurfaceClipper>();
  *((_DWORD *)this + 3) = -1;
  *((_DWORD *)this + 1) = -1;
  *(_DWORD *)this = -1;
  *((_DWORD *)this + 2) = 0;
  g_bExclusive = 0;
  g_pDirectDraw = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_BYTE *)this + 20) = 0;
  *((_BYTE *)this + 21) = 0;
  *((_BYTE *)this + 22) = 0;
  *((_BYTE *)this + 23) = 0;
  BBSupportTracePrintF(1, "GFX ENGINE: Engine object successfully created.");
  return this;
}


// address=[0x2f5a460]
// Decompiled from int __thiscall IGfxEngine::~IGfxEngine(IGfxEngine *this)
 IGfxEngine::~IGfxEngine(void) {
  
  DeleteEngine();
  if ( g_pDirectDraw )
  {
    (*(void (__stdcall **)(int, HWND, int))(*(_DWORD *)g_pDirectDraw + 80))(g_pDirectDraw, hWnd, 8);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)g_pDirectDraw + 8))(g_pDirectDraw, g_pDirectDraw);
    g_pDirectDraw = 0;
  }
  BBSupportTracePrintF(1, "GFX ENGINE: Engine object successfully destroyed.");
  return std::unique_ptr<SurfaceClipper>::~unique_ptr<SurfaceClipper>((char *)this + 36);
}


// address=[0x2f5a500]
// Decompiled from int __thiscall IGfxEngine::SetWindowPosition(IGfxEngine *this, int a2, int a3)
void  IGfxEngine::SetWindowPosition(int,int) {
  
  int result; // eax

  result = a2;
  WindowPositionX = a2;
  WindowPositionY = a3;
  return result;
}


// address=[0x2f5a520]
// Decompiled from unsigned int *__thiscall IGfxEngine::SetTickCounterAdress(IGfxEngine *this, unsigned int *a2)
void  IGfxEngine::SetTickCounterAdress(unsigned int *) {
  
  unsigned int *result; // eax

  result = a2;
  g_pTickCounter = (int)a2;
  return result;
}


// address=[0x2f5a540]
// Decompiled from char __stdcall IGfxEngine::SetTemporaryText(char *Str, int a2, int a3, int a4, int a5, COLORREF a6)
bool  IGfxEngine::SetTemporaryText(char *,int,int,int,int,int) {
  
  if ( Str )
  {
    if ( j__strlen(Str) > 0xFF )
      return 0;
    j__strcpy_0(&g_cTextTmp, Str);
    g_iTextTmpWidth = a4;
    g_iTextTmpHeight = a5;
    g_iTextTmpPosX = a2;
    g_iTextTmpPosY = a3;
    g_iTextTmpColor = a6;
  }
  else
  {
    g_cTextTmp = 0;
  }
  return 1;
}


// address=[0x2f5a5e0]
// Decompiled from void __thiscall IGfxEngine::SetTriangleSize(IGfxEngine *this, int a2)
void  IGfxEngine::SetTriangleSize(int) {
  
  if ( *(_DWORD *)this != a2 && a2 >= 0x20000 && a2 <= (int)&dword_B0F0F0[213956] )
  {
    *(_DWORD *)this = a2;
    dword_3E2E28C = a2;
    *(float *)&g_fVertexSize = (float)a2;
    IGfxEngine::SetCameraMode(this, -1);
    *(float *)&dword_3E2E2F4 = (float)dword_3E2E28C / 1572864.0;
    g_iZoomGradient = dword_3E2E28C / 24;
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
          *(float *)&dword_3E2E2F4);
    }
  }
}


// address=[0x2f5a6d0]
// Decompiled from char __thiscall IGfxEngine::SetScrollOffsets(IGfxEngine *this, int a2, int a3)
void  IGfxEngine::SetScrollOffsets(int,int) {
  
  dword_3E2E2A8 = (a2 << 15) / (dword_3E2E28C / 2);
  dword_3E2E2AC = (a3 << 15) / (dword_3E2E290 / 2);
  dword_3E2E2B0 = ((a2 << 15) % (dword_3E2E28C / 2)) >> 15;
  dword_3E2E2B4 = ((a3 << 15) % (dword_3E2E290 / 2)) >> 15;
  byte_3E2E302 = 1;
  SetMiniMapAreaSize();
  return MarkCurrentArea();
}


// address=[0x2f5a770]
// Decompiled from int __thiscall IGfxEngine::SetCameraMode(IGfxEngine *this, int a2)
void  IGfxEngine::SetCameraMode(int) {
  
  int result; // eax

  if ( a2 >= 0 )
  {
    result = a2;
    g_iCameraMode = a2;
  }
  if ( g_iCameraMode == 1 )
  {
    result = dword_3E2E28C / 2;
    dword_3E2E290 = dword_3E2E28C / 2;
  }
  else
  {
    dword_3E2E290 = dword_3E2E28C;
  }
  byte_3E2E2FE = 1;
  byte_3E2E2FF = 1;
  return result;
}


// address=[0x2f5a7d0]
// Decompiled from unsigned int __thiscall IGfxEngine::SetGfxLayerAccess(IGfxEngine *this, size_t a2, struct T_GFX_MAP_ELEMENT *a3)
void  IGfxEngine::SetGfxLayerAccess(int,struct T_GFX_MAP_ELEMENT *) {
  
  unsigned int NewValue; // [esp+4h] [ebp-4h]

  Size = a2;
  dword_3E2E2A0 = (int)a3;
  byte_3E2E2FE = 1;
  byte_3E2E2FF = 1;
  SetCrossingSystemMapAccess(a2, a3);
  NewValue = j___controlfp(0x300u, 0x300u);
  CalcMaxHeights(a3, a2);
  SetMiniMapGradient();
  CalcMaxTimeStamps();
  return j___controlfp(NewValue, 0x300u);
}


// address=[0x2f5a860]
// Decompiled from char __stdcall IGfxEngine::SetPlayerColor(unsigned int a1, int *a2)
bool  IGfxEngine::SetPlayerColor(int,struct SGfxColor &) {
  
  int *v3; // ecx
  int GradientFormat; // eax

  if ( a1 >= 8 )
    return 0;
  v3 = &dword_468D2C8[3 * a1 + 3];
  *v3 = *a2;
  v3[1] = a2[1];
  v3[2] = a2[2];
  if ( !D3DObjectPtr )
    return 1;
  GradientFormat = CInterfaceD3D::GetGradientFormat(D3DObjectPtr);
  CColorGradient::SetupGradients(&g_cColorGradient, a1, *a2, a2[1], a2[2], GradientFormat);
  return 1;
}


// address=[0x2f5a8e0]
// Decompiled from char __thiscall IGfxEngine::GetPlayerColor(IGfxEngine *this, unsigned int a2, struct SGfxColor *a3)
bool  IGfxEngine::GetPlayerColor(int,struct SGfxColor &) {
  
  int *v4; // ecx

  if ( a2 >= 8 )
    return 0;
  v4 = &dword_468D2C8[3 * a2 + 3];
  *(_DWORD *)a3 = *v4;
  *((_DWORD *)a3 + 1) = v4[1];
  *((_DWORD *)a3 + 2) = v4[2];
  return 1;
}


// address=[0x2f5a930]
// Decompiled from unsigned __int16 *__thiscall IGfxEngine::SetObjectLayerAccess(  IGfxEngine *this,  struct SGfxObjectInfo *(__cdecl *a2)(unsigned int, int),  unsigned __int16 *a3,  unsigned __int16 *a4)
void  IGfxEngine::SetObjectLayerAccess(struct SGfxObjectInfo * (__cdecl*)(unsigned int,int),unsigned short *,unsigned short *) {
  
  unsigned __int16 *result; // eax

  result = a3;
  dword_3E2E2E8 = (int)a3;
  dword_3E2E2EC = (int)a4;
  g_pfGetGfxObjectInfo = (int (__cdecl *)(_DWORD, _DWORD))a2;
  return result;
}


// address=[0x2f5a960]
// Decompiled from int (__cdecl *__thiscall IGfxEngine::SetOwnerIDCallback(IGfxEngine *this, int (__cdecl *a2)(int)))(int)
void  IGfxEngine::SetOwnerIDCallback(int (__cdecl*)(int)) {
  
  int (__cdecl *result)(int); // eax

  result = a2;
  g_pfGetOwnerID = a2;
  return result;
}


// address=[0x2f5a980]
// Decompiled from char __thiscall IGfxEngine::PutLandscapeObject(IGfxEngine *this, int a2, int a3, int a4)
bool  IGfxEngine::PutLandscapeObject(int,void *,void *) {
  
  if ( *((_DWORD *)this + 3) == -1 )
  {
    if ( a2 == g_iWaveIndices[0] )
    {
      *((_DWORD *)this + 3) = 0;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[0];
    }
    else if ( a2 == g_iWaveIndices[1] )
    {
      *((_DWORD *)this + 3) = 1;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[1];
    }
    else if ( a2 == g_iWaveIndices[2] )
    {
      *((_DWORD *)this + 3) = 2;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[2];
    }
    else if ( a2 == g_iWaveIndices[3] )
    {
      *((_DWORD *)this + 3) = 3;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[3];
    }
    else if ( a2 == g_iWaveIndices[4] )
    {
      *((_DWORD *)this + 3) = 4;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[4];
    }
    else if ( a2 == g_iWaveIndices[5] )
    {
      *((_DWORD *)this + 3) = 5;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[5];
    }
    else if ( a2 == g_iWaveIndices[6] )
    {
      *((_DWORD *)this + 3) = 6;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[6];
    }
    else if ( a2 == g_iWaveIndices[7] )
    {
      *((_DWORD *)this + 3) = 7;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[7];
    }
    else if ( a2 == g_iWaveIndices[8] )
    {
      *((_DWORD *)this + 3) = 8;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[8];
    }
    else if ( a2 == g_iWaveIndices[9] )
    {
      *((_DWORD *)this + 3) = 9;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[9];
    }
    else if ( a2 == g_iWaveIndices[10] )
    {
      *((_DWORD *)this + 3) = 10;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[10];
    }
    else if ( a2 == g_iWaveIndices[11] )
    {
      *((_DWORD *)this + 3) = 11;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[11];
    }
    else if ( a2 == g_iWaveIndices[12] )
    {
      *((_DWORD *)this + 3) = 12;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[12];
    }
    else if ( a2 == g_iWaveIndices[13] )
    {
      *((_DWORD *)this + 3) = 13;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[13];
    }
    else if ( a2 == g_iWaveIndices[14] )
    {
      *((_DWORD *)this + 3) = 14;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[14];
    }
    else if ( a2 == g_iWaveIndices[15] )
    {
      *((_DWORD *)this + 3) = 15;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[15];
    }
    else if ( a2 == g_iWaveIndices[16] )
    {
      *((_DWORD *)this + 3) = 16;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[16];
    }
    else if ( a2 == g_iWaveIndices[17] )
    {
      *((_DWORD *)this + 3) = 17;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uWaveFrames[17];
    }
    else if ( a2 == g_iBorderstoneIndices )
    {
      *((_DWORD *)this + 3) = 1000;
      *((_DWORD *)this + 4) = (unsigned __int8)g_uBorderstoneFrames;
    }
  }
  if ( *((_DWORD *)this + 3) == 1000 )
  {
    g_pBorderstonePalette = a4;
    dword_468A1D4[(unsigned __int8)g_uBorderstoneFrames - (*((_DWORD *)this + 4))--] = a3;
    g_pBorderstoneGfx = a3;
    if ( !*((_DWORD *)this + 4) )
      *((_DWORD *)this + 3) = -1;
  }
  else if ( *((int *)this + 3) >= 0 )
  {
    g_pWavePalettes[*((_DWORD *)this + 3)] = a4;
    g_pWaveGfx[(unsigned __int8)g_uWaveFrames[*((_DWORD *)this + 3)]
             + 20 * *((_DWORD *)this + 3)
             - (*((_DWORD *)this + 4))--] = a3;
    if ( !*((_DWORD *)this + 4) )
      *((_DWORD *)this + 3) = -1;
  }
  return 1;
}


// address=[0x2f5ae60]
// Decompiled from void *(__cdecl *__thiscall IGfxEngine::SetReloadCallback(  IGfxEngine *this,  void *(__cdecl *a2)(int, bool, bool)))(int, bool, bool)
void  IGfxEngine::SetReloadCallback(void * (__cdecl*)(int,bool,bool)) {
  
  void *(__cdecl *result)(int, bool, bool); // eax

  result = a2;
  g_pfForceReload = (int)a2;
  return result;
}


// address=[0x2f5ae80]
// Decompiled from void *__stdcall IGfxEngine::SetGfxObject(void *Src)
void  IGfxEngine::SetGfxObject(struct SGfxObject *) {
  
  void *result; // eax

  if ( Src )
    return j__memcpy(&g_sGfxObjectCursorBuilding, Src, 0x2E0u);
  g_sGfxObjectCursorBuilding = -65535;
  return result;
}


// address=[0x2f5aec0]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave1(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave1(int,int) {
  
  int result; // eax

  g_uWaveFrames[0] = a3;
  result = 4;
  g_iWaveIndices[0] = a2;
  return result;
}


// address=[0x2f5aef0]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave2(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave2(int,int) {
  
  int result; // eax

  g_uWaveFrames[1] = a3;
  result = a2;
  g_iWaveIndices[1] = a2;
  return result;
}


// address=[0x2f5af20]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave3(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave3(int,int) {
  
  int result; // eax

  g_uWaveFrames[2] = a3;
  result = a2;
  g_iWaveIndices[2] = a2;
  return result;
}


// address=[0x2f5af50]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave4(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave4(int,int) {
  
  int result; // eax

  g_uWaveFrames[3] = a3;
  result = 4;
  g_iWaveIndices[3] = a2;
  return result;
}


// address=[0x2f5af80]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave5(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave5(int,int) {
  
  int result; // eax

  g_uWaveFrames[4] = a3;
  result = a2;
  g_iWaveIndices[4] = a2;
  return result;
}


// address=[0x2f5afb0]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave6(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave6(int,int) {
  
  int result; // eax

  g_uWaveFrames[5] = a3;
  result = 4;
  g_iWaveIndices[5] = a2;
  return result;
}


// address=[0x2f5afe0]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave7(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave7(int,int) {
  
  int result; // eax

  g_uWaveFrames[6] = a3;
  result = 4;
  g_iWaveIndices[6] = a2;
  return result;
}


// address=[0x2f5b010]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave8(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave8(int,int) {
  
  int result; // eax

  g_uWaveFrames[7] = a3;
  result = 4;
  g_iWaveIndices[7] = a2;
  return result;
}


// address=[0x2f5b040]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave9(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave9(int,int) {
  
  int result; // eax

  g_uWaveFrames[8] = a3;
  result = a2;
  g_iWaveIndices[8] = a2;
  return result;
}


// address=[0x2f5b070]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave10(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave10(int,int) {
  
  int result; // eax

  g_uWaveFrames[9] = a3;
  result = 4;
  g_iWaveIndices[9] = a2;
  return result;
}


// address=[0x2f5b0a0]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave11(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave11(int,int) {
  
  int result; // eax

  g_uWaveFrames[10] = a3;
  result = 4;
  g_iWaveIndices[10] = a2;
  return result;
}


// address=[0x2f5b0d0]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave12(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave12(int,int) {
  
  int result; // eax

  g_uWaveFrames[11] = a3;
  result = 4;
  g_iWaveIndices[11] = a2;
  return result;
}


// address=[0x2f5b100]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave13(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave13(int,int) {
  
  int result; // eax

  g_uWaveFrames[12] = a3;
  result = 4;
  g_iWaveIndices[12] = a2;
  return result;
}


// address=[0x2f5b130]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave14(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave14(int,int) {
  
  int result; // eax

  g_uWaveFrames[13] = a3;
  result = 4;
  g_iWaveIndices[13] = a2;
  return result;
}


// address=[0x2f5b160]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave15(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave15(int,int) {
  
  int result; // eax

  g_uWaveFrames[14] = a3;
  result = 4;
  g_iWaveIndices[14] = a2;
  return result;
}


// address=[0x2f5b190]
// Decompiled from int __thiscall IGfxEngine::SetIndexWave16(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexWave16(int,int) {
  
  int result; // eax

  g_uWaveFrames[15] = a3;
  result = 4;
  g_iWaveIndices[15] = a2;
  return result;
}


// address=[0x2f5b1c0]
// Decompiled from int __stdcall IGfxEngine::SetIndexWave17(int a1, char a2)
void  IGfxEngine::SetIndexWave17(int,int) {
  
  int result; // eax

  g_uWaveFrames[16] = a2;
  result = a1;
  g_iWaveIndices[16] = a1;
  return result;
}


// address=[0x2f5b1f0]
// Decompiled from int __stdcall IGfxEngine::SetIndexWave18(int a1, char a2)
void  IGfxEngine::SetIndexWave18(int,int) {
  
  int result; // eax

  g_uWaveFrames[17] = a2;
  result = 4;
  g_iWaveIndices[17] = a1;
  return result;
}


// address=[0x2f5b220]
// Decompiled from char __thiscall IGfxEngine::SetIndexBorderstone(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::SetIndexBorderstone(int,int) {
  
  char result; // al

  result = a3;
  g_uBorderstoneFrames = a3;
  g_iBorderstoneIndices = a2;
  return result;
}


// address=[0x2f5b240]
// Decompiled from char __thiscall IGfxEngine::EnableMiniMap(IGfxEngine *this, char a2, int a3, int a4, HWND a5)
bool  IGfxEngine::EnableMiniMap(bool,int,int,struct HWND__ *) {
  
  int v6; // [esp+4h] [ebp-4h]

  byte_3E2E301 = a2;
  dword_3E2E304 = a3;
  dword_3E2E308 = a4;
  dword_3E2E2E4 = (int)a5;
  if ( D3DObjectPtr
    && SurfaceClipper::GetClipper((SurfaceClipper *)&D3DObjectPtr->MinimapClipper)
    && (v6 = SurfaceClipper::SetClipWindow((SurfaceClipper *)&D3DObjectPtr->MinimapClipper, a5)) != 0 )
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
// Decompiled from struct SGfxColor *(__cdecl *__thiscall IGfxEngine::SetMiniMapColorCallback(  IGfxEngine *this,  struct SGfxColor *(__cdecl *a2)(unsigned int)))(unsigned int)
void  IGfxEngine::SetMiniMapColorCallback(struct SGfxColor * (__cdecl*)(unsigned int)) {
  
  struct SGfxColor *(__cdecl *result)(unsigned int); // eax

  result = a2;
  g_pfGetGfxMiniMapColor = (int)a2;
  return result;
}


// address=[0x2f5b310]
// Decompiled from char __thiscall IGfxEngine::EnableCameraWindow(IGfxEngine *this, char a2, int a3, int a4, int a5, int a6)
bool  IGfxEngine::EnableCameraWindow(bool,int,int,int,int) {
  
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
// Decompiled from int __thiscall IGfxEngine::SetCameraViewPosition(IGfxEngine *this, int a2, int a3)
void  IGfxEngine::SetCameraViewPosition(int,int) {
  
  int result; // eax

  dword_3E2E2C4 = (a2 << 15) / (dword_3E2E294 / 2);
  dword_3E2E2C8 = (a3 << 15) / (dword_3E2E298 / 2);
  dword_3E2E2CC = ((a2 << 15) % (dword_3E2E294 / 2)) >> 15;
  result = (a3 << 15) / (dword_3E2E298 / 2);
  dword_3E2E2D0 = ((a3 << 15) % (dword_3E2E298 / 2)) >> 15;
  byte_3E2E303 = 1;
  return result;
}


// address=[0x2f5b420]
// Decompiled from void __thiscall IGfxEngine::SetCameraTriangleSize(IGfxEngine *this, int a2)
void  IGfxEngine::SetCameraTriangleSize(int) {
  
  if ( *((_DWORD *)this + 1) != a2 && a2 >= 0x20000 && a2 <= (int)&dword_B0F0F0[213956] )
  {
    *((_DWORD *)this + 1) = a2;
    dword_3E2E294 = a2;
    *(float *)&g_fCamVertexSize = (float)a2;
    if ( g_iCameraMode == 1 )
      dword_3E2E298 = dword_3E2E294 / 2;
    else
      dword_3E2E298 = dword_3E2E294;
    byte_3E2E2FE = 1;
    *(float *)&dword_3E2E2F8 = (float)dword_3E2E294 / 1572864.0;
    g_iCamZoomGradient = dword_3E2E294 / 24;
    g_iZoomInit = -65536;
    InitCamGradientTable();
  }
}


// address=[0x2f5b4e0]
// Decompiled from int __thiscall IGfxEngine::GetRenderHeight(IGfxEngine *this, int a2)
int  IGfxEngine::GetRenderHeight(int) {
  
  return (int)(float)((float)((float)a2 * 0.051562499) * *(float *)&g_fCamVertexSize) >> 16;
}


// address=[0x2f5b510]
// Decompiled from void (__cdecl *__thiscall IGfxEngine::SetIconCallbacks(  IGfxEngine *this,  void (__cdecl *a2)(int),  unsigned __int8 (__cdecl *a3)(int)))(int)
void  IGfxEngine::SetIconCallbacks(void (__cdecl*)(int),unsigned char (__cdecl*)(int)) {
  
  void (__cdecl *result)(int); // eax

  result = a2;
  g_pfSetNumberOfNextLine = (int (__cdecl *)(_DWORD))a2;
  g_pfGetIconObjectByX = (int (__cdecl *)(_DWORD))a3;
  return result;
}


// address=[0x2f5b530]
// Decompiled from char __thiscall IGfxEngine::PutAccessoryIcon(IGfxEngine *this, unsigned int a2, int a3, int a4)
bool  IGfxEngine::PutAccessoryIcon(int,void *,void *) {
  
  if ( a2 >= 0x100 )
    return 0;
  g_pIconGfx[a2] = a3;
  g_pIconPalette = a4;
  return 1;
}


// address=[0x2f5b570]
// Decompiled from char __thiscall IGfxEngine::InitEngine(  int this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  int a8,  int a9,  int a10,  char a11,  _DWORD *a12,  _DWORD *a13,  _DWORD *a14)
bool  IGfxEngine::InitEngine(struct SGfxRenderConfiguration,bool,int &,int &,int &) {
  
  *(_BYTE *)(this + 21) = a11;
  *a14 = 27;
  CheckConfiguration((struct SGfxRenderConfiguration *)&a2);
  qmemcpy(&GfxEngineSetup, &a2, 0x24u);
  if ( BYTE2(a2) )
  {
    *(_DWORD *)(this + 24) = 23;
    *a13 = 23;
    *(_BYTE *)(this + 22) = 0;
  }
  else
  {
    *(_BYTE *)(this + 22) = IGfxEngine::IsHardwareRenderingAvailable((IGfxEngine *)this);
    *a13 = *(_DWORD *)(this + 24);
  }
  if ( *(_BYTE *)(this + 21) )
  {
    *(_BYTE *)(this + 23) = IGfxEngine::IsSoftwareRenderingAvailable((IGfxEngine *)this);
    *a12 = *(_DWORD *)(this + 28);
  }
  else
  {
    *(_DWORD *)(this + 28) = 22;
    *a12 = 22;
    *(_BYTE *)(this + 23) = 0;
  }
  if ( *(_BYTE *)(this + 23) )
    BBSupportTracePrintF(1, "GFX ENGINE: Check setup: Software-rendering is possible.");
  else
    BBSupportTracePrintF(1, "GFX ENGINE: Check setup: Software-rendering is not possible.");
  if ( *(_BYTE *)(this + 22) )
    BBSupportTracePrintF(1, "GFX ENGINE: Check setup: Hardware-rendering is possible.");
  else
    BBSupportTracePrintF(1, "GFX ENGINE: Check setup: Hardware-rendering is not possible.");
  if ( *(_BYTE *)(this + 22) || *(_BYTE *)(this + 23) )
  {
    byte_3E2E2FF = 1;
    if ( (unsigned __int8)SGfxRenderConfiguration::IsHardwareObjectEngine(&a2) && *(_BYTE *)(this + 32) )
    {
      byte_3E2E30E = 1;
      BBSupportTracePrintF(1, "GFX ENGINE: Hardware object rendering enabled.");
    }
    else
    {
      byte_3E2E30E = 0;
      BBSupportTracePrintF(1, "GFX ENGINE: Hardware object rendering disabled.");
    }
    if ( *(_BYTE *)(this + 32) )
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Check setup: Hardware object rendering is possible.");
      *a14 = 0;
    }
    else
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Check setup: Hardware object rendering is not possible.");
      *a14 = 27;
    }
    SetMiniMapAreaSize();
    if ( Initialize() )
    {
      if ( !*(_DWORD *)(this + 24) || !*(_DWORD *)(this + 28) )
        *(_BYTE *)(this + 20) = 1;
      if ( (!SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&a2) || *(_BYTE *)(this + 22))
        && (SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&a2) || *(_BYTE *)(this + 23)) )
      {
        return IGfxEngine::SetRenderEnvironment((IGfxEngine *)this);
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
// Decompiled from char __thiscall IGfxEngine::RebuildRenderEnvironment(  IGfxEngine *this,  __int16 a2,  int a3,  int a4,  int a5,  int a6,  int a7,  int a8,  int a9,  int a10)
bool  IGfxEngine::RebuildRenderEnvironment(struct SGfxRenderConfiguration) {
  
  if ( !*((_BYTE *)this + 20) )
    return 0;
  if ( (unsigned __int8)SGfxRenderConfiguration::IsHardwareObjectEngine(&a2) && *((_BYTE *)this + 32) )
  {
    byte_3E2E30E = 1;
    BBSupportTracePrintF(1, "GFX ENGINE: Hardware object rendering enabled.");
  }
  else
  {
    byte_3E2E30E = 0;
    BBSupportTracePrintF(1, "GFX ENGINE: Hardware object rendering disabled.");
  }
  CheckConfiguration((struct SGfxRenderConfiguration *)&a2);
  if ( HIBYTE(a2) )
  {
    dword_3E2E2A0 = 0;
    dword_3E2E2E8 = 0;
    dword_3E2E2EC = 0;
    Src = 0;
    SetCrossingSystemMapAccess(0, 0);
  }
  if ( (!SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&a2) || *((_BYTE *)this + 22))
    && (SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&a2) || *((_BYTE *)this + 23)) )
  {
    qmemcpy(&GfxEngineSetup, &a2, 0x24u);
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
bool  IGfxEngine::RenderFrame(bool,bool) {
  
  struct SurfaceClipper *v4; // eax
  bool v5; // al
  _BYTE v6[100]; // [esp+2Ch] [ebp-D4h] BYREF
  DWORD v7; // [esp+90h] [ebp-70h]
  DWORD TickCount; // [esp+94h] [ebp-6Ch]
  int v9; // [esp+98h] [ebp-68h]
  int v10; // [esp+A0h] [ebp-60h]
  int v11; // [esp+A4h] [ebp-5Ch]
  BOOL v12; // [esp+A8h] [ebp-58h]
  int v13; // [esp+ACh] [ebp-54h]
  int v14; // [esp+B0h] [ebp-50h]
  int v15; // [esp+B4h] [ebp-4Ch]
  int v16; // [esp+B8h] [ebp-48h]
  BOOL v17; // [esp+BCh] [ebp-44h]
  IGfxEngine *v18; // [esp+C0h] [ebp-40h]
  bool v19; // [esp+C5h] [ebp-3Bh]
  bool v20; // [esp+C6h] [ebp-3Ah]
  bool v21; // [esp+C7h] [ebp-39h]
  int v22; // [esp+C8h] [ebp-38h] BYREF
  _DWORD v23[4]; // [esp+CCh] [ebp-34h] BYREF
  _DWORD v24[2]; // [esp+DCh] [ebp-24h] BYREF
  int v25; // [esp+E4h] [ebp-1Ch]
  int v26; // [esp+E8h] [ebp-18h]
  int v27; // [esp+ECh] [ebp-14h] BYREF
  int v28; // [esp+F0h] [ebp-10h]
  int v29; // [esp+F4h] [ebp-Ch]
  int v30; // [esp+F8h] [ebp-8h]

  v18 = this;
  v22 = 1;
  if ( IsIconic(hWnd) )
  {
    byte_4689BD9 = 1;
    D3DObjectPtr->field_740 = 1;
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
      D3DObjectPtr->field_723 = 1;
    }
    if ( --g_iRefreshWaitFrames )
      return 1;
  }
  if ( D3DObjectPtr->field_740 )
  {
    if ( IGfxEngine::SetRenderEnvironment(v18) )
    {
      D3DObjectPtr->field_740 = 0;
      byte_3E2E2FE = 1;
      byte_3E2E2FF = 1;
      D3DObjectPtr->field_723 = 1;
      return 1;
    }
    else
    {
      BBSupportTracePrintF(0, "GFX ENGINE: Problem while reinitializing the renderer!");
      D3DObjectPtr->field_740 = 1;
      return 0;
    }
  }
  else if ( byte_3E2E261 )
  {
    if ( D3DObjectPtr->FinalRenderSurface )
    {
      CBlitFX::CBlitFX((CBlitFX *)v6);
      v21 = dword_3E2E2B8 == 1;
      CBlitFX::SetFillColor((CBlitFX *)v6, 0, 0, 0, dword_3E2E2B8 == 1);
      v22 = ((int (__thiscall *)(CSurfaceV7 *, _BYTE *))D3DObjectPtr->FinalRenderSurface->ClearSurface)(
              D3DObjectPtr->FinalRenderSurface,
              v6);
      if ( v22 >= 0 )
      {
        if ( (unsigned __int8)std::operator!=<SurfaceClipper,std::default_delete<SurfaceClipper>>((char *)v18 + 36, 0)
          && (v4 = (struct SurfaceClipper *)std::unique_ptr<SurfaceClipper>::operator*((char *)v18 + 36),
              v22 = CInterfaceD3D::SetCustomClipper(D3DObjectPtr, v4),
              v22 < 0) )
        {
          BBSupportTracePrintF(0, "GFX ENGINE: Failed to assign GUI clipper!");
          D3DObjectPtr->field_740 = 1;
          return 1;
        }
        else if ( AddGuiPatches() )
        {
          v22 = CInterfaceD3D::ClearCustomClipper(D3DObjectPtr);
          if ( v22 >= 0 )
            return 1;
          BBSupportTracePrintF(0, "GFX ENGINE: Failed to clear GUI clipper!");
          D3DObjectPtr->field_740 = 1;
          return 1;
        }
        else
        {
          D3DObjectPtr->field_740 = 1;
          return 1;
        }
      }
      else
      {
        BBSupportTracePrintF(0, "GFX ENGINE: Failed to clear final render surface!");
        D3DObjectPtr->field_740 = 1;
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
      v22 = DrawTexturedLandscape(dword_3E2E2A8, dword_3E2E2AC);
      a3 = 1;
    }
    if ( !v22 )
    {
      WriteError(0, "RenderLandscape");
      D3DObjectPtr->field_740 = 1;
      return 1;
    }
    byte_3E2E302 = 0;
    byte_3E2E2FF = 0;
    if ( byte_3E2E300 )
    {
      v22 = DrawTexturedLandscapeDelta(dword_3E2E2A8, dword_3E2E2AC);
      a3 = 1;
    }
    if ( !v22 )
    {
      WriteError(0, "RenderLandscapeDelta");
      D3DObjectPtr->field_740 = 1;
      return 1;
    }
    byte_3E2E300 = 0;
    dword_3E2E314 = 2000;
    dword_3E2E318 = -1;
    if ( !SGfxRenderConfiguration::IsEditorMode((SGfxRenderConfiguration *)&GfxEngineSetup) || a3 )
    {
      v22 = ((int (__thiscall *)(CSurfaceV7 *, _DWORD, CSurfaceV7 *, _DWORD, _DWORD, _DWORD))D3DObjectPtr->FinalRenderSurface->Blt)(
              D3DObjectPtr->FinalRenderSurface,
              0,
              D3DObjectPtr->LandscapeSurface,
              0,
              0,
              0);
      if ( v22 )
      {
        WriteError(v22, "BlitLandscapeSurfaceToFinal");
        D3DObjectPtr->field_740 = 1;
        return 0;
      }
      D3DObjectPtr->field_743 = 1;
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
      if ( dword_3E2E2D4 < OutputWidth && dword_3E2E2D8 < OutputHeight )
      {
        v22 = CInterfaceD3D::SwitchLandscapeRenderTarget(D3DObjectPtr, 1);
        if ( v22 < 0 )
        {
          WriteError(v22, "RenderCamWindow");
          D3DObjectPtr->field_740 = 1;
          return 0;
        }
        v9 = g_fVertexSize;
        g_fVertexSize = g_fCamVertexSize;
        v5 = DrawCameraLandscape(dword_3E2E2C4, dword_3E2E2C8);
        v22 = v5;
        g_fVertexSize = v9;
        if ( !v5 )
        {
          WriteError(v22, "RenderCamWindow");
          D3DObjectPtr->field_740 = 1;
          return 0;
        }
        v22 = CInterfaceD3D::SwitchLandscapeRenderTarget(D3DObjectPtr, 0);
        if ( v22 < 0 )
        {
          WriteError(v22, "RenderCamWindow");
          D3DObjectPtr->field_740 = 1;
          return 0;
        }
        v23[0] = dword_3E2E2D4;
        v23[1] = dword_3E2E2D8;
        if ( dword_3E2E2DC >= OutputWidth - dword_3E2E2D4 )
          v16 = OutputWidth - dword_3E2E2D4;
        else
          v16 = dword_3E2E2DC;
        v13 = v16;
        if ( dword_3E2E2E0 >= OutputHeight - dword_3E2E2D8 )
          v15 = OutputHeight - dword_3E2E2D8;
        else
          v15 = dword_3E2E2E0;
        v14 = v15;
        v23[2] = dword_3E2E2D4 + v13;
        v23[3] = dword_3E2E2D8 + v15;
        v22 = ((int (__thiscall *)(CSurfaceV7 *, _DWORD *, int, _DWORD, _DWORD, _DWORD))D3DObjectPtr->FinalRenderSurface->Blt)(
                D3DObjectPtr->FinalRenderSurface,
                v23,
                D3DObjectPtr->field_5C,
                0,
                0,
                0);
        if ( v22 )
        {
          WriteError(v22, "BlitCameraSurfaceToBuffer");
          D3DObjectPtr->field_740 = 1;
          return 0;
        }
        byte_3E2E303 = 0;
        byte_3E2E2FE = 0;
        CInterfaceD3D::SetupViewport(D3DObjectPtr, dword_3E2E2D4, dword_3E2E2D8, v13, v14);
        EnableCamRenderSettings(1);
        if ( D3DObjectPtr && D3DObjectPtr->CCachePageManager[0] )
          CCachePageManager::SetCurrentZoomFactor(
            (CCachePageManager *)D3DObjectPtr->CCachePageManager[0],
            *(float *)&dword_3E2E2F4);
        RenderObjectLayer(1);
        if ( D3DObjectPtr && D3DObjectPtr->CCachePageManager[0] )
          CCachePageManager::SetCurrentZoomFactor(
            (CCachePageManager *)D3DObjectPtr->CCachePageManager[0],
            *(float *)&dword_3E2E2F8);
        EnableCamRenderSettings(0);
        CInterfaceD3D::SetupViewport(D3DObjectPtr, 0, 0, OutputWidth, OutputHeight);
      }
    }
    if ( byte_3E2E30E && dword_3E2E310 )
    {
      if ( dword_3E2E310 == -1 )
      {
        CInterfaceD3D::BeginObjectScene(D3DObjectPtr);
        CCachePageManager::ShowPageContent((CCachePageManager *)D3DObjectPtr->CCachePageManager[0], &v22);
        CInterfaceD3D::EndObjectScene(D3DObjectPtr);
        if ( v22 )
          WriteError(v22, "ShowCachePage");
      }
      if ( dword_3E2E310 == -2 )
      {
        CInterfaceD3D::BeginObjectScene(D3DObjectPtr);
        CCachePageManager::ShowPageContent((CCachePageManager *)D3DObjectPtr->CCachePageManager[1], &v22);
        CInterfaceD3D::EndObjectScene(D3DObjectPtr);
        if ( v22 )
          WriteError(v22, "ShowCachePage");
      }
      if ( dword_3E2E310 > 0 && dword_3E2E310 < D3DObjectPtr->field_448 )
      {
        CInterfaceD3D::BeginObjectScene(D3DObjectPtr);
        CCachePageManager::ShowPageContent((CCachePageManager *)D3DObjectPtr->field_44C[dword_3E2E310], &v22);
        CInterfaceD3D::EndObjectScene(D3DObjectPtr);
        if ( v22 )
          WriteError(v22, "ShowCachePage");
      }
    }
    v7 = GetTickCount() - TickCount;
    AddDebugStrings(v7);
    if ( !byte_3E2E301 )
      goto LABEL_106;
    v12 = ((int (__thiscall *)(CSurfaceV7 *))D3DObjectPtr->MiniMapSurface->j_?IsLost@CSurfaceV7@@UAEJXZ)(D3DObjectPtr->MiniMapSurface) == -2005532222
       || ((int (__thiscall *)(CSurfaceV7 *))D3DObjectPtr->MiniMapAreaSurface->j_?IsLost@CSurfaceV7@@UAEJXZ)(D3DObjectPtr->MiniMapAreaSurface) == -2005532222;
    v20 = v12;
    if ( byte_3E2E30C || v20 )
    {
      if ( v20 )
      {
        D3DObjectPtr->field_740 = 1;
        return 1;
      }
      byte_3E2E30C = 0;
      DrawCompleteMiniMap();
      MarkCurrentArea();
    }
    DrawMiniMapObjectLayer();
    DrawMiniMapLandscapeLayer();
    GetNextLayer();
    v27 = g_sMiniMapRect;
    v28 = dword_4689B90;
    v29 = dword_4689B94;
    v30 = dword_4689B98;
    v24[0] = g_sMiniMapSize;
    v24[1] = dword_3E2E240;
    v25 = dword_3E2E244;
    v26 = dword_3E2E248;
    if ( SGfxRenderConfiguration::IsEditorMode((SGfxRenderConfiguration *)&GfxEngineSetup) )
      goto LABEL_106;
    if ( v28 <= OutputHeight || v27 <= OutputWidth )
    {
      if ( v30 > OutputHeight )
      {
        v11 = v30 - OutputHeight;
        v30 = OutputHeight;
        v26 -= v11;
      }
      if ( v29 > OutputWidth )
      {
        v10 = v29 - OutputWidth;
        v29 = OutputWidth;
        v25 -= v10;
      }
      v22 = ((int (__thiscall *)(CSurfaceV7 *, int *, CSurfaceV7 *, _DWORD *, int, _DWORD))D3DObjectPtr->FinalRenderSurface->Blt)(
              D3DObjectPtr->FinalRenderSurface,
              &v27,
              D3DObjectPtr->MiniMapSurface,
              v24,
              0x8000,
              0);
      if ( !v22 )
        v22 = ((int (__thiscall *)(CSurfaceV7 *, int *, CSurfaceV7 *, _DWORD *, int, _DWORD))D3DObjectPtr->FinalRenderSurface->Blt)(
                D3DObjectPtr->FinalRenderSurface,
                &v27,
                D3DObjectPtr->MiniMapAreaSurface,
                v24,
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
        D3DObjectPtr->field_740 = 1;
      return v22 == 0;
    }
  }
}


// address=[0x2f5c400]
// Decompiled from int __stdcall IGfxEngine::BlitFrameToDIB(HGDIOBJ h)
bool  IGfxEngine::BlitFrameToDIB(struct HBITMAP__ *) {
  
  return BlitRenderedSurfaceToDIB(hWnd, h);
}


// address=[0x2f5c420]
// Decompiled from void IGfxEngine::ForceMiniMapRefresh()
void  IGfxEngine::ForceMiniMapRefresh(void) {
  
  byte_3E2E30C = 1;
}


// address=[0x2f5c440]
// Decompiled from struct tagRECT *__thiscall IGfxEngine::DrawRectangle(IGfxEngine *this, struct tagRECT *a2, __int16 a3)
void  IGfxEngine::DrawRectangle(struct tagRECT *,unsigned short) {
  
  struct tagRECT *result; // eax

  result = a2;
  Src = a2;
  word_3E2E2FC = a3;
  return result;
}


// address=[0x2f5c460]
// Decompiled from char __thiscall IGfxEngine::EnableIconLayer(IGfxEngine *this, char a2)
void  IGfxEngine::EnableIconLayer(bool) {
  
  char result; // al

  result = a2;
  byte_3E2E30D = a2;
  return result;
}


// address=[0x2f5c480]
// Decompiled from int __thiscall IGfxEngine::UpdateWorldPosition(IGfxEngine *this, __int64 a2)
void  IGfxEngine::UpdateWorldPosition(int,int) {
  
  int result; // eax
  int v3; // [esp+4h] [ebp-4h]

  if ( !dword_3E2E2A0 )
    return result;
  result = HIDWORD(a2) | a2;
  if ( (int)(HIDWORD(a2) | a2) < 0 || (int)a2 >= (int)Size || SHIDWORD(a2) >= (int)Size )
    return result;
  v3 = a2 + Size * HIDWORD(a2);
  RefreshShading(v3, 0);
  if ( *(unsigned __int8 *)(dword_3E2E2A0 + 4 * v3) > (int)(unsigned __int8)g_uMaxYTable[HIDWORD(a2)] )
    g_uMaxYTable[HIDWORD(a2)] = *(_BYTE *)(dword_3E2E2A0 + 4 * v3);
  result = HIDWORD(a2);
  if ( SHIDWORD(a2) < dword_3E2E314 )
    dword_3E2E314 = HIDWORD(a2);
  if ( SHIDWORD(a2) > dword_3E2E318 )
  {
    result = HIDWORD(a2);
    dword_3E2E318 = HIDWORD(a2);
  }
  byte_3E2E300 = 1;
  return result;
}


// address=[0x2f5c540]
// Decompiled from size_t __thiscall IGfxEngine::UpdateWorldPosition(IGfxEngine *this, int a2)
void  IGfxEngine::UpdateWorldPosition(int) {
  
  size_t result; // eax
  int v3; // [esp+4h] [ebp-4h]

  if ( !dword_3E2E2A0 )
    return result;
  if ( a2 < 0 )
    return result;
  result = Size * Size;
  if ( a2 >= (int)(Size * Size) )
    return result;
  RefreshShading(a2, 0);
  v3 = a2 / (int)Size;
  if ( *(unsigned __int8 *)(dword_3E2E2A0 + 4 * a2) > (int)(unsigned __int8)g_uMaxYTable[a2 / (int)Size] )
    g_uMaxYTable[v3] = *(_BYTE *)(dword_3E2E2A0 + 4 * a2);
  result = v3;
  if ( v3 < dword_3E2E314 )
    dword_3E2E314 = v3;
  if ( v3 > dword_3E2E318 )
  {
    result = v3;
    dword_3E2E318 = v3;
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
// Decompiled from float *__thiscall IGfxEngine::ConvertMapPositionToWorldScreenOffsets(  IGfxEngine *this,  __int64 a2,  float *a3,  float *a4)
void  IGfxEngine::ConvertMapPositionToWorldScreenOffsets(int,int,float &,float &) {
  
  float *result; // eax
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  if ( (int)(HIDWORD(a2) | a2) >= 0 && (int)a2 < (int)Size && SHIDWORD(a2) < (int)Size && dword_3E2E2A0 )
    v5 = CalcStaticHeightOffset(*(unsigned __int8 *)(dword_3E2E2A0 + 4 * (a2 + Size * HIDWORD(a2))));
  result = a4;
  *a4 = (float)((float)SHIDWORD(a2) * (float)(24.0 / 2.0)) - (float)v5;
  *a3 = (float)((float)(int)a2 - (float)((float)SHIDWORD(a2) / 2.0)) * 24.0;
  return result;
}


// address=[0x2f5c6d0]
// Decompiled from int __stdcall IGfxEngine::ConvertMapPositionToWorldScreenOffsets_0(__int64 a1, _DWORD *a2, _DWORD *a3)
void  IGfxEngine::ConvertMapPositionToWorldScreenOffsets(int,int,int &,int &) {
  
  int result; // eax
  int v4; // [esp+8h] [ebp-4h]

  v4 = 0;
  if ( (int)(HIDWORD(a1) | a1) >= 0 && (int)a1 < (int)Size && SHIDWORD(a1) < (int)Size && dword_3E2E2A0 )
    v4 = CalcStaticHeightOffsetInt(*(unsigned __int8 *)(dword_3E2E2A0 + 4 * (a1 + Size * HIDWORD(a1))));
  *a3 = 12 * HIDWORD(a1) - v4;
  result = 24 * (a1 - SHIDWORD(a1) / 2);
  *a2 = result;
  return result;
}


// address=[0x2f5c760]
// Decompiled from bool __thiscall IGfxEngine::CanChangeGround(IGfxEngine *this, int a2, int a3, int a4)
bool  IGfxEngine::CanChangeGround(int,int,int) {
  
  return dword_3E2E2A0 && CheckField(a2, a3, a2 + Size * a3, a4);
}


// address=[0x2f5c7a0]
// Decompiled from void __thiscall IGfxEngine::SetDarkLand(IGfxEngine *this, int a2, int a3, bool a4)
void  IGfxEngine::SetDarkLand(int,int,bool) {
  
  int v4; // [esp+4h] [ebp-8h] BYREF
  int v5; // [esp+8h] [ebp-4h] BYREF

  if ( dword_3E2E2A0 )
  {
    SetDarkLandFlag(a2, a3, a4, &v5, &v4);
    if ( v5 < dword_3E2E314 )
      dword_3E2E314 = v5;
    if ( v4 > dword_3E2E318 )
      dword_3E2E318 = v4;
    byte_3E2E300 = 1;
  }
}


// address=[0x2f5c810]
// Decompiled from int __thiscall IGfxEngine::SetFoggingFadingStep(IGfxEngine *this, int a2)
void  IGfxEngine::SetFoggingFadingStep(int) {
  
  int result; // eax
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]

  result = a2;
  g_iFogFadeStep = a2;
  g_iFadeYBorder = -50000;
  if ( a2 == dword_4689BDC )
    return result;
  if ( dword_3E2E24C >= dword_3E2E314 )
    v4 = dword_3E2E314;
  else
    v4 = dword_3E2E24C;
  dword_3E2E314 = v4;
  if ( dword_3E2E250 <= dword_3E2E318 )
    v3 = dword_3E2E318;
  else
    v3 = dword_3E2E250;
  result = v3;
  dword_3E2E318 = v3;
  dword_4689BDC = a2;
  byte_3E2E300 = 1;
  return result;
}


// address=[0x2f5c8a0]
// Decompiled from int __thiscall IGfxEngine::SetFoggingUpdateMode(IGfxEngine *this, int a2)
void  IGfxEngine::SetFoggingUpdateMode(int) {
  
  int result; // eax

  result = a2;
  g_iFadeYBorder = a2;
  g_iFogFadeStep = 15;
  return result;
}


// address=[0x2f5c8c0]
// Decompiled from int __thiscall IGfxEngine::SetFoggingRange(IGfxEngine *this, int a2, int a3)
void  IGfxEngine::SetFoggingRange(int,int) {
  
  int result; // eax
  int v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  result = a2;
  dword_3E2E24C = a2;
  dword_3E2E250 = a3;
  if ( a3 >= 0 )
  {
    if ( dword_3E2E24C >= dword_3E2E314 )
      v5 = dword_3E2E314;
    else
      v5 = dword_3E2E24C;
    dword_3E2E314 = v5;
    if ( dword_3E2E250 <= dword_3E2E318 )
      v4 = dword_3E2E318;
    else
      v4 = dword_3E2E250;
    result = v4;
    dword_3E2E318 = v4;
  }
  else
  {
    dword_3E2E24C = 2000;
    dword_3E2E250 = -1;
  }
  return result;
}


// address=[0x2f5c950]
// Decompiled from bool __thiscall IGfxEngine::IsInitialized(IGfxEngine *this)
bool  IGfxEngine::IsInitialized(void) {
  
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup) )
    return HardwareIsRunning();
  else
    return SoftwareIsRunning();
}


// address=[0x2f5c980]
// Decompiled from char __thiscall IGfxEngine::IsHardwareEngine(_BYTE *this)
bool  IGfxEngine::IsHardwareEngine(void) {
  
  if ( this[20] )
    return SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup);
  else
    return 0;
}


// address=[0x2f5c9b0]
// Decompiled from char __thiscall IGfxEngine::Use4444Palettes(IGfxEngine *this)
bool  IGfxEngine::Use4444Palettes(void) {
  
  if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup) )
    return byte_3E2E30E;
  else
    return 0;
}


// address=[0x2f5c9e0]
// Decompiled from char __thiscall IGfxEngine::IsGuiMode(IGfxEngine *this)
bool  IGfxEngine::IsGuiMode(void) {
  
  return byte_3E2E261;
}


// address=[0x2f5c9f0]
// Decompiled from char __thiscall IGfxEngine::IsGfxEngineRebuilded(IGfxEngine *this)
bool  IGfxEngine::IsGfxEngineRebuilded(void) {
  
  if ( !D3DObjectPtr )
    return 1;
  if ( !D3DObjectPtr->field_723 )
    return 0;
  D3DObjectPtr->field_723 = 0;
  return 1;
}


// address=[0x2f5ca30]
// Decompiled from int __thiscall IGfxEngine::GetGfxMode(IGfxEngine *this)
int  IGfxEngine::GetGfxMode(void) {
  
  return dword_3E2E2B8;
}


// address=[0x2f5ca40]
// Decompiled from int __cdecl IGfxEngine::ConvertRgbToHicol(int a1, int a2, int a3)
static unsigned short __cdecl IGfxEngine::ConvertRgbToHicol(int,int,int) {
  
  int v3; // eax

  if ( dword_3E2E2B8 == 1 )
    v3 = 32 * (unsigned __int16)(int)(float)((float)a2 * 0.12156863)
       + ((unsigned __int16)(int)(float)((float)a1 * 0.12156863) << 10);
  else
    v3 = 32 * (unsigned __int16)(int)(float)((float)a2 * 0.24705882)
       + ((unsigned __int16)(int)(float)((float)a1 * 0.12156863) << 11);
  return (unsigned __int16)(int)(float)((float)a3 * 0.12156863) + v3;
}


// address=[0x2f5cae0]
// Decompiled from int __thiscall IGfxEngine::GetOutputWidth(IGfxEngine *this)
int  IGfxEngine::GetOutputWidth(void) {
  
  return OutputWidth;
}


// address=[0x2f5caf0]
// Decompiled from int __thiscall IGfxEngine::GetOutputHeight(IGfxEngine *this)
int  IGfxEngine::GetOutputHeight(void) {
  
  return OutputHeight;
}


// address=[0x2f5cb00]
// Decompiled from int __thiscall IGfxEngine::GetClosestMapPoint(void *this, int a2, int a3)
int  IGfxEngine::GetClosestMapPoint(int,int) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  int v5[2]; // [esp+4h] [ebp-8h] BYREF

  v5[1] = (int)this;
  return SearchMapPoint(a2, a3, &v4, v5, 0);
}


// address=[0x2f5cb30]
// Decompiled from int __thiscall IGfxEngine::GetClosestMapPoint(IGfxEngine *this, int a2, int a3, int *a4, int *a5)
int  IGfxEngine::GetClosestMapPoint(int,int,int &,int &) {
  
  return SearchMapPoint(a2, a3, a4, a5, 0);
}


// address=[0x2f5cb60]
// Decompiled from int __stdcall IGfxEngine::GetClosestMapPointOutsideMap(int a1, int a2, int *a3, int *a4)
int  IGfxEngine::GetClosestMapPointOutsideMap(int,int,int &,int &) {
  
  return SearchMapPoint(a1, a2, a3, a4, 1);
}


// address=[0x2f5cb90]
// Decompiled from int __cdecl IGfxEngine::GetScreenOffsetsByMapIndices(__int64 a1, int *a2, int *a3)
static int __cdecl IGfxEngine::GetScreenOffsetsByMapIndices(int,int,int &,int &) {
  
  if ( (int)(HIDWORD(a1) | a1) < 0 || (int)a1 >= (int)Size || SHIDWORD(a1) >= (int)Size )
    return 0;
  ConvertMapIndexToScreenPosition(a1, HIDWORD(a1), a2, a3);
  if ( (*a3 | *a2) < 0 || *a2 >= OutputWidth || *a3 >= OutputHeight )
    return 1;
  else
    return 3;
}


// address=[0x2f5cc10]
// Decompiled from int __cdecl IGfxEngine::GetScreenOffsetsByMapIndices_0(int a1, int *a2, int *a3)
static int __cdecl IGfxEngine::GetScreenOffsetsByMapIndices(int,int &,int &) {
  
  if ( a1 < 0 || a1 >= (int)(Size * Size) )
    return 0;
  ConvertMapIndexToScreenPosition(a1 % (int)Size, a1 / (int)Size, a2, a3);
  if ( (*a3 | *a2) < 0 || *a2 >= OutputWidth || *a3 >= OutputHeight )
    return 1;
  else
    return 3;
}


// address=[0x2f5cca0]
// Decompiled from double __thiscall IGfxEngine::GetCurrentZoomFactor(IGfxEngine *this)
float  IGfxEngine::GetCurrentZoomFactor(void) {
  
  return *(float *)&dword_3E2E2F4;
}


// address=[0x2f5ccc0]
// Decompiled from int __thiscall IGfxEngine::ShowCachePage(IGfxEngine *this, int a2, char a3)
void  IGfxEngine::ShowCachePage(int,int) {
  
  int result; // eax

  dword_3E2E310 = a2;
  byte_3E2E324 = (a3 & 1) != 0;
  result = a3 & 2;
  byte_3E2E325 = (a3 & 2) != 0;
  return result;
}


// address=[0x2f5cd20]
// Decompiled from int __thiscall IGfxEngine::SetWidthOfLeftGuiBorder(IGfxEngine *this, int a2)
void  IGfxEngine::SetWidthOfLeftGuiBorder(int) {
  
  int result; // eax

  result = a2;
  dword_3E2E2BC = a2;
  return result;
}


// address=[0x2f5f850]
// Decompiled from IGfxEngine *__thiscall IGfxEngine::LockCursorShape(IGfxEngine *this, bool a2)
void  IGfxEngine::LockCursorShape(bool) {
  
  IGfxEngine *result; // eax

  result = this;
  *((_BYTE *)this + 33) = a2;
  return result;
}


// address=[0x2f5f870]
// Decompiled from IGfxEngine *__thiscall IGfxEngine::SetCursorShape(IGfxEngine *this, bool a2, unsigned int a3)
void  IGfxEngine::SetCursorShape(bool,int) {
  
  IGfxEngine *result; // eax

  result = this;
  if ( *((_BYTE *)this + 33) || a3 >= 0x24 )
    return result;
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
  SetClassLongA(hWnd, -12, (LONG)s_hCursorHandles[a3]);
  result = (IGfxEngine *)a3;
  s_iCurrentCursor = a3;
  return result;
}


// address=[0x2f5f950]
// Decompiled from void __thiscall IGfxEngine::FixCursor(IGfxEngine *this, bool a2, bool a3)
void  IGfxEngine::FixCursor(bool,bool) {
  
  int CursorShape; // eax
  struct tagPOINT Point; // [esp+0h] [ebp-Ch] BYREF
  IGfxEngine *v5; // [esp+8h] [ebp-4h]

  v5 = this;
  if ( D3DObjectPtr && (!s_bCursorIsFixed || !a2) && (s_bCursorIsFixed || a2) )
  {
    if ( a2 )
    {
      GetCursorPos(&Point);
      ScreenToClient(hWnd, &Point);
      if ( a3 )
        CFixCursor::SetFixCursor((CFixCursor *)&D3DObjectPtr->ZoomCursor, Point.x, Point.y, 1);
      else
        CFixCursor::SetFixCursor((CFixCursor *)&D3DObjectPtr->MoveCursor, Point.x, Point.y, 1);
      CursorShape = IGfxEngine::GetCursorShape(v5);
      *((_DWORD *)v5 + 2) = CursorShape;
      IGfxEngine::SetCursorShape(v5, 0, *((_DWORD *)v5 + 2));
      s_bCursorIsFixed = 1;
    }
    else
    {
      IGfxEngine::SetCursorShape(v5, 1, *((_DWORD *)v5 + 2));
      CFixCursor::SetFixCursor((CFixCursor *)&D3DObjectPtr->MoveCursor, 0, 0, 0);
      CFixCursor::SetFixCursor((CFixCursor *)&D3DObjectPtr->ZoomCursor, 0, 0, 0);
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
bool  IGfxEngine::IsResolutionPossible(int) {
  
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
      if ( D3DObjectPtr->DDraw || D3DObjectPtr->field_71D || D3DObjectPtr->field_71C )
      {
        v10[0] = 380;
        v8 = D3DObjectPtr->DDraw->lpVtbl->GetCaps(D3DObjectPtr->DDraw, (LPDDCAPS)v10, 0);
        if ( v8 )
        {
          WriteError(v8, "GetCapabilities");
          LOBYTE(v2) = 0;
        }
        else
        {
          v6 = 16;
          v8 = ((int (__thiscall *)(CSurfaceV7 *, int *))D3DObjectPtr->PrimarySurface->j_?GetBitDepth@CSurfaceV7@@UAEJAAH@Z)(
                 D3DObjectPtr->PrimarySurface,
                 &v6);
          v9 = v10[15];
          if ( v8 )
          {
            WriteError(v8, "GetBitDepthWhileResChecking");
            LOBYTE(v2) = 0;
          }
          else
          {
            v8 = ((int (__thiscall *)(CSurfaceV7 *, _DWORD *, int *))D3DObjectPtr->PrimarySurface->GetSurfaceSize)(
                   D3DObjectPtr->PrimarySurface,
                   v5,
                   &v4);
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
              if ( D3DObjectPtr->field_71D )
              {
                if ( D3DObjectPtr->IsHQTextureSet )
                  v9 -= (unsigned int)&dword_5C4000[8576];
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
                  v7 = (int)&dword_420320[98104];
                  break;
                case 3u:
                  v7 = (int)&dword_760B60[32040];
                  break;
                default:
                  v7 = (int)&dword_AA0EA0[93784];
                  break;
              }
              v9 -= v7;
              if ( v9 >= 0xC350 )
              {
                if ( byte_3E2E262 )
                {
                  WriteError(v8, "Cannot use DD3");
                  LOBYTE(v2) = 0;
                }
                else
                {
                  v8 = D3DObjectPtr->DDraw7->lpVtbl->EnumDisplayModes(
                         D3DObjectPtr->DDraw7,
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
// Decompiled from char __thiscall IGfxEngine::CheckRenderConfiguration(  _BYTE *this,  char a2,  int a3,  int a4,  int a5,  int a6,  int a7,  int a8,  int a9,  int a10)
bool  IGfxEngine::CheckRenderConfiguration(struct SGfxRenderConfiguration) {
  
  int v11; // [esp+4h] [ebp-19Ch] BYREF
  int v12; // [esp+8h] [ebp-198h] BYREF
  int v13; // [esp+Ch] [ebp-194h] BYREF
  _BYTE *v14; // [esp+10h] [ebp-190h]
  int v15; // [esp+14h] [ebp-18Ch]
  unsigned __int64 v16; // [esp+18h] [ebp-188h]
  _DWORD v17[95]; // [esp+20h] [ebp-180h] BYREF

  v14 = this;
  CheckConfiguration((struct SGfxRenderConfiguration *)&a2);
  if ( (!SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&a2) || v14[22])
    && (SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&a2) || v14[23]) )
  {
    if ( D3DObjectPtr )
    {
      if ( D3DObjectPtr->DDraw || D3DObjectPtr->field_71D || D3DObjectPtr->field_71C )
      {
        v17[0] = 380;
        v15 = D3DObjectPtr->DDraw->lpVtbl->GetCaps(D3DObjectPtr->DDraw, (LPDDCAPS)v17, 0);
        if ( v15 )
        {
          WriteError(v15, "GetCapabilities");
          return 0;
        }
        else
        {
          v13 = 16;
          v15 = ((int (__thiscall *)(CSurfaceV7 *, int *))D3DObjectPtr->PrimarySurface->j_?GetBitDepth@CSurfaceV7@@UAEJAAH@Z)(
                  D3DObjectPtr->PrimarySurface,
                  &v13);
          v16 = v17[15];
          if ( v15 )
          {
            WriteError(v15, "GetBitDepthWhileResChecking");
            return 0;
          }
          else
          {
            v15 = ((int (__thiscall *)(CSurfaceV7 *, int *, int *))D3DObjectPtr->PrimarySurface->GetSurfaceSize)(
                    D3DObjectPtr->PrimarySurface,
                    &v12,
                    &v11);
            if ( v15 )
            {
              WriteError(v15, "GetSurfaceSizeWhileResChecking");
              return 0;
            }
            else
            {
              v16 += v11 * v12 * (v13 / 8);
              v16 -= 810000LL;
              v16 -= 155000LL;
              if ( D3DObjectPtr->field_71D )
              {
                if ( D3DObjectPtr->IsHQTextureSet )
                  v16 -= (unsigned int)&dword_5C4000[8576];
                else
                  v16 -= 1520000LL;
              }
              v16 -= 6 * a6 * a5;
              if ( v16 >= 0xC350 )
              {
                if ( byte_3E2E262 )
                {
                  WriteError(v15, "Cannot use DD3");
                  return 0;
                }
                else
                {
                  v15 = D3DObjectPtr->DDraw7->lpVtbl->EnumDisplayModes(
                          D3DObjectPtr->DDraw7,
                          2,
                          0,
                          0,
                          CInterfaceD3D::EnumModesCallback);
                  if ( v15 )
                  {
                    WriteError(v15, "EnumeratingDisplayModes");
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
// Decompiled from bool __thiscall IGfxEngine::ShowFrame(IGfxEngine *this)
bool  IGfxEngine::ShowFrame(void) {
  
  if ( IsIconic(hWnd) )
    return 1;
  if ( g_iRefreshWaitFrames )
    return 1;
  if ( D3DObjectPtr )
  {
    return !*((_BYTE *)D3DObjectPtr + 1856) && CInterfaceD3D::BlitSurfaceToWindow(D3DObjectPtr);
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Call to ShowFrame without initializing the engine!");
    return 0;
  }
}


// address=[0x2f60260]
// Decompiled from char __thiscall IGfxEngine::SolidColorFillGuiSurface(  IGfxEngine *this,  unsigned int a2,  unsigned __int8 a3,  unsigned __int8 a4,  unsigned __int8 a5)
bool  IGfxEngine::SolidColorFillGuiSurface(int,unsigned char,unsigned char,unsigned char) {
  
  int v6; // [esp+8h] [ebp-14h]

  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( !D3DObjectPtr->field_138[a2] )
    return 0;
  if ( dword_468A558 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_468A558);
    if ( dword_468A558 == -1 )
    {
      CBlitFX::CBlitFX((CBlitFX *)&unk_468A4E0);
      j___Init_thread_footer(&dword_468A558);
    }
  }
  CBlitFX::SetFillColor((CBlitFX *)&unk_468A4E0, a3, a4, a5, dword_3E2E2B8 == 1);
  v6 = (*(int (__thiscall **)(DWORD, void *))(*(_DWORD *)D3DObjectPtr->field_138[a2] + 20))(
         D3DObjectPtr->field_138[a2],
         &unk_468A4E0);
  if ( !v6 )
    return 1;
  WriteError(v6, "SetGuiSurfaceSolidColor");
  return 0;
}


// address=[0x2f603b0]
// Decompiled from char __thiscall IGfxEngine::SolidColorFillGuiSurface(  IGfxEngine *this,  unsigned int a2,  unsigned __int8 a3,  unsigned __int8 a4,  unsigned __int8 a5,  struct tagRECT a6)
bool  IGfxEngine::SolidColorFillGuiSurface(int,unsigned char,unsigned char,unsigned char,struct tagRECT) {
  
  int v7; // [esp+8h] [ebp-14h]

  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( !D3DObjectPtr->field_138[a2] )
    return 0;
  if ( dword_468A5D8 > *(_DWORD *)(*((_DWORD *)NtCurrentTeb()->ThreadLocalStoragePointer + _tls_index) + 20296) )
  {
    j___Init_thread_header(&dword_468A5D8);
    if ( dword_468A5D8 == -1 )
    {
      CBlitFX::CBlitFX((CBlitFX *)&unk_468A560);
      j___Init_thread_footer(&dword_468A5D8);
    }
  }
  CBlitFX::SetFillColor((CBlitFX *)&unk_468A560, a3, a4, a5, dword_3E2E2B8 == 1);
  v7 = (*(int (__thiscall **)(DWORD, LONG, LONG, LONG, LONG, void *))(*(_DWORD *)D3DObjectPtr->field_138[a2] + 16))(
         D3DObjectPtr->field_138[a2],
         a6.left,
         a6.top,
         a6.right,
         a6.bottom,
         &unk_468A560);
  if ( !v7 )
    return 1;
  WriteError(v7, "SetGuiSurfaceSolidColor");
  return 0;
}


// address=[0x2f699c0]
// Decompiled from char __thiscall IGfxEngine::RenderObject(void *this, int a2, int a3, int a4, int a5, int a6)
bool  IGfxEngine::RenderObject(int,int,struct SGfxObjectInfo *,int,int) {
  
  int v7; // [esp+4h] [ebp-14h]
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
      v11 = ((int (__thiscall *)(CSurfaceV7 *, int *, int *, int))D3DObjectPtr->FinalRenderSurface->Lock)(
              D3DObjectPtr->FinalRenderSurface,
              &dword_468DD10,
              &dword_468DD0C,
              1);
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
      v11 = ((int (__thiscall *)(CSurfaceV7 *, void *))D3DObjectPtr->FinalRenderSurface->Unlock)(
              D3DObjectPtr->FinalRenderSurface,
              this);
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
    v7 = dword_3E2E2F4;
    if ( a5 != 256 )
    {
      *(_DWORD *)g_pZoomGradient *= a5 / 256;
      *(float *)&dword_3E2E2F4 = (float)(a5 / 256) * *(float *)&dword_3E2E2F4;
    }
    g_pRenderAdress = dword_468DD0C;
    g_pBeginOfRenderBuffer = dword_468DD0C;
    g_iRenderPitch = dword_468DD10;
    g_iScanlineLength = 2 * OutputWidth;
    g_pEndOfRenderBuffer = 2 * OutputWidth + dword_468DD0C + dword_468DD10 * (OutputHeight - 1);
    IGfxEngine::GetScreenOffsetsByMapIndices(a2, a3, &v9, &v10);
    if ( *(_DWORD *)a4 )
    {
      if ( *(_BYTE *)(a4 + 712) == 1 )
        BlitSettler(255, v9 << 16, v10 << 16, (struct SGfxObjectInfo *)a4);
      else
        BlitObject(255, v9 << 16, v10 << 16, (struct SGfxObjectInfo *)a4);
      *(_DWORD *)g_pZoomGradient = v8;
      dword_3E2E2F4 = v7;
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
// Decompiled from char __thiscall IGfxEngine::RenderResource(void *this, int a2, int a3, int a4, int a5, int a6, int a7)
bool  IGfxEngine::RenderResource(int,int,void *,void *,void *,int) {
  
  int v8; // [esp+4h] [ebp-2E8h]
  int v9; // [esp+8h] [ebp-2E4h]
  int v10; // [esp+Ch] [ebp-2E0h] BYREF
  int v11; // [esp+10h] [ebp-2DCh] BYREF
  int v12; // [esp+14h] [ebp-2D8h]
  int v13; // [esp+18h] [ebp-2D4h] BYREF
  int v14; // [esp+1Ch] [ebp-2D0h]
  char v15; // [esp+2Eh] [ebp-2BEh]
  char v16; // [esp+2E2h] [ebp-Ah]

  if ( a7 == 1 )
  {
    if ( !byte_468DD08 && D3DObjectPtr->FinalRenderSurface )
    {
      v12 = ((int (__thiscall *)(CSurfaceV7 *, int *, int *, int))D3DObjectPtr->FinalRenderSurface->Lock)(
              D3DObjectPtr->FinalRenderSurface,
              &dword_468DD04,
              &dword_468DD00,
              1);
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
      v12 = ((int (__thiscall *)(CSurfaceV7 *, void *))D3DObjectPtr->FinalRenderSurface->Unlock)(
              D3DObjectPtr->FinalRenderSurface,
              this);
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
    v9 = *(_DWORD *)g_pZoomGradient;
    v8 = dword_3E2E2F4;
    *(_DWORD *)g_pZoomGradient = (int)(float)((float)*(int *)g_pZoomGradient * 0.75);
    *(float *)&dword_3E2E2F4 = *(float *)&dword_3E2E2F4 * 0.75;
    g_pRenderAdress = dword_468DD00;
    g_pBeginOfRenderBuffer = dword_468DD00;
    g_iRenderPitch = dword_468DD04;
    g_iScanlineLength = 2 * OutputWidth;
    g_pEndOfRenderBuffer = 2 * OutputWidth + dword_468DD00 + dword_468DD04 * (OutputHeight - 1);
    IGfxEngine::GetScreenOffsetsByMapIndices(a2, a3, &v10, &v11);
    v16 = 1;
    v14 = a4;
    v13 = a5;
    v15 = 0;
    BlitObject(255, v10 << 16, v11 << 16, (struct SGfxObjectInfo *)&v13);
    v14 = g_pIconPalette;
    v13 = a6;
    BlitObject(
      255,
      (v10 + (int)(float)(5.0 * *(float *)&dword_3E2E2F4)) << 16,
      v11 << 16,
      (struct SGfxObjectInfo *)&v13);
    *(_DWORD *)g_pZoomGradient = v9;
    dword_3E2E2F4 = v8;
    return 1;
  }
  else
  {
    return 0;
  }
}


// address=[0x2f69ec0]
// Decompiled from struct IGfxEffects *__thiscall IGfxEngine::SetEffectSystemInterfacePtr(IGfxEngine *this, struct IGfxEffects *a2)
void  IGfxEngine::SetEffectSystemInterfacePtr(class IGfxEffects *) {
  
  struct IGfxEffects *result; // eax

  result = a2;
  s_pEffectSystem = (int)a2;
  return result;
}


// address=[0x2f72f10]
// Decompiled from int (__cdecl *__thiscall IGfxEngine::EnableDebugValueCallback(IGfxEngine *this, int (__cdecl *a2)(int, int)))(int, int)
void  IGfxEngine::EnableDebugValueCallback(int (__cdecl*)(int,int)) {
  
  int (__cdecl *result)(int, int); // eax

  result = a2;
  dword_468DF98 = (int)a2;
  return result;
}


// address=[0x2f72f30]
// Decompiled from char *(__cdecl *__thiscall IGfxEngine::EnableDebugStringCallback(IGfxEngine *this, char *(__cdecl *a2)()))()
void  IGfxEngine::EnableDebugStringCallback(char * (__cdecl*)(void)) {
  
  char *(__cdecl *result)(); // eax

  result = a2;
  dword_468DF9C = (int)a2;
  return result;
}


// address=[0x2f72f50]
// Decompiled from int __thiscall IGfxEngine::CreateGuiSurface(  IGfxEngine *this,  unsigned int a2,  struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *a3)
int  IGfxEngine::CreateGuiSurface(int,struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *) {
  
  int v4; // eax
  int v5; // [esp+18h] [ebp-1Ch]
  IDirectDraw7 *DDraw; // [esp+1Ch] [ebp-18h]
  int v7; // [esp+24h] [ebp-10h]
  void (__thiscall ***v8)(_DWORD, int); // [esp+28h] [ebp-Ch]
  int v9; // [esp+2Ch] [ebp-8h]
  unsigned int i; // [esp+30h] [ebp-4h]

  if ( !D3DObjectPtr )
    return -1;
  if ( D3DObjectPtr->field_740 )
    return -1;
  if ( !*((_BYTE *)this + 20) && !D3DObjectPtr->field_71D && !D3DObjectPtr->field_71C )
    BBSupportTracePrintF(0, "GFX ENGINE: Call to CreateGuiSurface without initializing the engine before!");
  if ( a2 >= 0xE )
    return -1;
  if ( D3DObjectPtr->field_138[a2] )
    return -1;
  D3DObjectPtr->field_138[a2] = (DWORD)CSurface::CreateSurfacePtr(byte_3E2E262);
  if ( D3DObjectPtr->field_138[a2] )
  {
    if ( byte_3E2E262 )
      DDraw = D3DObjectPtr->DDraw;
    else
      DDraw = D3DObjectPtr->DDraw7;
    v4 = j__abs(dword_3E2E2B8 == 1);
    v5 = (*(int (__thiscall **)(DWORD, IDirectDraw7 *, _DWORD, _DWORD, int, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)D3DObjectPtr->field_138[a2] + 48))(
           D3DObjectPtr->field_138[a2],
           DDraw,
           *(_DWORD *)a3,
           *((_DWORD *)a3 + 1),
           1,
           0,
           0,
           v4,
           0,
           0,
           0);
    if ( v5 )
    {
      v8 = (void (__thiscall ***)(_DWORD, int))D3DObjectPtr->field_138[a2];
      if ( v8 )
        (**v8)(v8, 1);
      D3DObjectPtr->field_138[a2] = 0;
      WriteError(v5, "CreateGuiSurface:");
      return -1;
    }
    else
    {
      byte_468E2E8[a2] = 0;
      qmemcpy(&dword_468DFA0[7 * a2], a3, 0x1Cu);
      ClipGuiSurface(a2);
      v9 = 0;
      v7 = 0;
      for ( i = 0; i < 0xE; ++i )
      {
        if ( D3DObjectPtr->field_138[i] )
        {
          ++v7;
          v9 += 2 * dword_468DFA4[7 * i] * dword_468DFA0[7 * i];
        }
      }
      if ( CInterfaceD3D::GetGuiMemorySize(D3DObjectPtr) >= v9 )
        return a2;
      CInterfaceD3D::SetGuiMemorySize(D3DObjectPtr, v9);
      BBSupportTracePrintF(
        0,
        "GFX ENGINE: New max size reached: Surfaces currently used by gui: %d Used vid-mem: %d",
        v7,
        v9);
      return a2;
    }
  }
  else
  {
    BBSupportTracePrintF(0, "GFX ENGINE: Not enough memory to create surface object!");
    return -1;
  }
}


// address=[0x2f73220]
// Decompiled from int __thiscall IGfxEngine::CreateGuiSurface(IGfxEngine *this, struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *a2)
int  IGfxEngine::CreateGuiSurface(struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *) {
  
  int v3; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  if ( !D3DObjectPtr )
    return -1;
  v3 = -1;
  for ( i = 0; i < 0xE; ++i )
  {
    if ( !D3DObjectPtr->field_138[i] )
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
bool  IGfxEngine::DestroyGuiSurface(int) {
  
  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( D3DObjectPtr->field_740 )
    return 0;
  if ( !D3DObjectPtr->field_138[a2] )
    return 0;
  (*(void (__thiscall **)(DWORD, IGfxEngine *))(*(_DWORD *)D3DObjectPtr->field_138[a2] + 4))(
    D3DObjectPtr->field_138[a2],
    this);
  if ( D3DObjectPtr->field_138[a2] )
    (**(void (__thiscall ***)(DWORD, int))D3DObjectPtr->field_138[a2])(D3DObjectPtr->field_138[a2], 1);
  D3DObjectPtr->field_138[a2] = 0;
  byte_468E2E8[a2] = 0;
  return 1;
}


// address=[0x2f73390]
// Decompiled from char __thiscall IGfxEngine::SetVisibilityOfGuiSurface(IGfxEngine *this, unsigned int a2, char a3)
bool  IGfxEngine::SetVisibilityOfGuiSurface(int,bool) {
  
  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( D3DObjectPtr->field_740 )
    return 0;
  if ( !D3DObjectPtr->field_138[a2] )
    return 0;
  byte_468E2E8[a2] = a3;
  return 1;
}


// address=[0x2f733f0]
// Decompiled from char __thiscall IGfxEngine::SetGuiSurfaceDestinationPosition(IGfxEngine *this, unsigned int a2, int a3, int a4)
bool  IGfxEngine::SetGuiSurfaceDestinationPosition(int,int,int) {
  
  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( !D3DObjectPtr->field_138[a2] )
    return 0;
  OffsetRect((LPRECT)&dword_468DFA0[7 * a2 + 2], a3 - dword_468DFA0[7 * a2 + 2], a4 - dword_468DFA0[7 * a2 + 3]);
  ClipGuiSurface(a2);
  return 1;
}


// address=[0x2f73480]
// Decompiled from char __thiscall IGfxEngine::SetGuiSurfaceDestinationRect(IGfxEngine *this, unsigned int a2, const struct tagRECT *a3)
bool  IGfxEngine::SetGuiSurfaceDestinationRect(int,struct tagRECT const &) {
  
  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( !D3DObjectPtr->field_138[a2] )
    return 0;
  *(struct tagRECT *)((char *)&unk_468DFA8 + 28 * a2) = *a3;
  ClipGuiSurface(a2);
  return 1;
}


// address=[0x2f734f0]
// Decompiled from char __stdcall IGfxEngine::GetGuiSurfaceDestinationRect(unsigned int a1, _DWORD *a2)
bool  IGfxEngine::GetGuiSurfaceDestinationRect(int,struct tagRECT &) {
  
  _DWORD *v3; // ecx

  if ( !D3DObjectPtr || a1 >= 0xE )
    return 0;
  if ( D3DObjectPtr->field_740 )
    return 0;
  if ( !D3DObjectPtr->field_138[a1] )
    return 0;
  v3 = (_DWORD *)((char *)&unk_468DFA8 + 28 * a1);
  *a2 = *v3;
  a2[1] = v3[1];
  a2[2] = v3[2];
  a2[3] = v3[3];
  return 1;
}


// address=[0x2f73570]
// Decompiled from char __thiscall IGfxEngine::GetGuiSurfaceDescription(  IGfxEngine *this,  unsigned int a2,  struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *a3)
bool  IGfxEngine::GetGuiSurfaceDescription(int,struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION &) {
  
  if ( a2 >= 0xE )
    return 0;
  if ( !D3DObjectPtr->field_138[a2] )
    return 0;
  qmemcpy(a3, &dword_468DFA0[7 * a2], 0x1Cu);
  return 1;
}


// address=[0x2f735c0]
// Decompiled from int __thiscall IGfxEngine::BeginWriteToSurface(IGfxEngine *this, unsigned int a2, unsigned int *a3)
unsigned short *  IGfxEngine::BeginWriteToSurface(int,unsigned int &) {
  
  int v4; // [esp+8h] [ebp-Ch] BYREF
  int v5; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( D3DObjectPtr->field_740 )
    return 0;
  if ( !D3DObjectPtr->field_138[a2] )
    return 0;
  if ( (*(int (__thiscall **)(DWORD))(*(_DWORD *)D3DObjectPtr->field_138[a2] + 12))(D3DObjectPtr->field_138[a2]) == -2005532222 )
  {
    for ( i = 0; i < 0xE; ++i )
    {
      if ( D3DObjectPtr->field_138[i] )
      {
        if ( (*(int (__thiscall **)(DWORD))(*(_DWORD *)D3DObjectPtr->field_138[i] + 12))(D3DObjectPtr->field_138[i]) == -2005532222 )
        {
          v5 = (*(int (__thiscall **)(DWORD))(*(_DWORD *)D3DObjectPtr->field_138[i] + 8))(D3DObjectPtr->field_138[i]);
          if ( v5 )
          {
            WriteError(v5, "RestoreGuiSurface");
            BBSupportTracePrintF(0, "GFX ENGINE: Problem with gui surfaces! Stop rendering...");
            D3DObjectPtr->field_740 = 1;
            return 0;
          }
        }
      }
    }
    D3DObjectPtr->field_723 = 1;
  }
  v5 = (*(int (__thiscall **)(DWORD, unsigned int *, int *, int))(*(_DWORD *)D3DObjectPtr->field_138[a2] + 32))(
         D3DObjectPtr->field_138[a2],
         a3,
         &v4,
         1);
  if ( v5 )
    return 0;
  else
    return v4;
}


// address=[0x2f73770]
// Decompiled from char __thiscall IGfxEngine::EndWriteToSurface(IGfxEngine *this, unsigned int a2)
bool  IGfxEngine::EndWriteToSurface(int) {
  
  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( D3DObjectPtr->field_740 )
    return 0;
  if ( !D3DObjectPtr->field_138[a2] )
    return 0;
  (*(void (__thiscall **)(DWORD, IGfxEngine *))(*(_DWORD *)D3DObjectPtr->field_138[a2] + 36))(
    D3DObjectPtr->field_138[a2],
    this);
  return 1;
}


// address=[0x2f737f0]
// Decompiled from char __thiscall IGfxEngine::GetGuiSurfaceDC(IGfxEngine *this, unsigned int a2, HDC *a3)
bool  IGfxEngine::GetGuiSurfaceDC(int,struct HDC__ * *) {
  
  int v4; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( D3DObjectPtr->field_740 )
    return 0;
  if ( !D3DObjectPtr->field_138[a2] )
    return 0;
  if ( (*(int (__thiscall **)(DWORD, IGfxEngine *))(*(_DWORD *)D3DObjectPtr->field_138[a2] + 12))(
         D3DObjectPtr->field_138[a2],
         this) == -2005532222 )
  {
    for ( i = 0; i < 0xE; ++i )
    {
      if ( D3DObjectPtr->field_138[i] )
      {
        if ( (*(int (__thiscall **)(DWORD))(*(_DWORD *)D3DObjectPtr->field_138[i] + 12))(D3DObjectPtr->field_138[i]) == -2005532222 )
        {
          v4 = (*(int (__thiscall **)(DWORD))(*(_DWORD *)D3DObjectPtr->field_138[i] + 8))(D3DObjectPtr->field_138[i]);
          if ( v4 )
          {
            WriteError(v4, "RestoreGuiSurface");
            BBSupportTracePrintF(0, "GFX ENGINE: Problem with gui surfaces! Stop rendering...");
            D3DObjectPtr->field_740 = 1;
            return 0;
          }
        }
      }
    }
    D3DObjectPtr->field_723 = 1;
  }
  (*(void (__thiscall **)(DWORD, HDC *))(*(_DWORD *)D3DObjectPtr->field_138[a2] + 40))(D3DObjectPtr->field_138[a2], a3);
  return 1;
}


// address=[0x2f73980]
// Decompiled from bool __thiscall IGfxEngine::ReleaseGuiSurfaceDC(IGfxEngine *this, unsigned int a2, HDC a3)
bool  IGfxEngine::ReleaseGuiSurfaceDC(int,struct HDC__ *) {
  
  if ( !D3DObjectPtr || a2 >= 0xE )
    return 0;
  if ( D3DObjectPtr->field_740 )
    return 0;
  if ( D3DObjectPtr->field_138[a2] )
    return (*(int (__thiscall **)(DWORD, HDC))(*(_DWORD *)D3DObjectPtr->field_138[a2] + 44))(
             D3DObjectPtr->field_138[a2],
             a3) == 0;
  return 0;
}


// address=[0x2f73a10]
// Decompiled from char __thiscall IGfxEngine::SetGuiSurfaceClipRect(char *this, void *Src)
bool  IGfxEngine::SetGuiSurfaceClipRect(struct tagRECT const &) {
  
  SurfaceClipper *v3; // eax
  SurfaceClipper *v4; // eax
  struct IDirectDraw7 *DDraw; // [esp-4h] [ebp-14h]
  char v6[4]; // [esp+0h] [ebp-10h] BYREF
  int v7; // [esp+4h] [ebp-Ch]
  char *v8; // [esp+8h] [ebp-8h]
  int inited; // [esp+Ch] [ebp-4h]

  v8 = this;
  if ( !D3DObjectPtr || D3DObjectPtr->field_740 )
    return 0;
  v7 = ((int (__cdecl *)(char *))std::make_unique<SurfaceClipper,>)(v6);
  std::unique_ptr<SurfaceClipper>::operator=(v7);
  std::unique_ptr<SurfaceClipper>::~unique_ptr<SurfaceClipper>(v6);
  if ( byte_3E2E262 )
    DDraw = D3DObjectPtr->DDraw;
  else
    DDraw = D3DObjectPtr->DDraw7;
  std::unique_ptr<SurfaceClipper>::operator->((std::condition_variable *)(v8 + 36));
  inited = SurfaceClipper::InitClipper(v3, DDraw);
  if ( inited >= 0 )
  {
    std::unique_ptr<SurfaceClipper>::operator->((std::condition_variable *)(v8 + 36));
    inited = SurfaceClipper::SetClipRect(Src);
    if ( inited >= 0 )
    {
      return 1;
    }
    else
    {
      WriteError(inited, "SetClipListToRect");
      std::unique_ptr<SurfaceClipper>::operator->((std::condition_variable *)(v8 + 36));
      SurfaceClipper::ReleaseClipper(v4);
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
// Decompiled from int __thiscall IGfxEngine::ClearGuiSurfaceClipRect(IGfxEngine *this)
void  IGfxEngine::ClearGuiSurfaceClipRect(void) {
  
  return std::unique_ptr<SurfaceClipper>::reset(0);
}


// address=[0x2f5cd40]
// Decompiled from bool __thiscall IGfxEngine::IsHardwareRenderingAvailable(IGfxEngine *this)
bool  IGfxEngine::IsHardwareRenderingAvailable(void) {
  
  int IsInterface7Available; // eax
  HWND v3[9]; // [esp+Ch] [ebp-74h] BYREF
  _DWORD v4[9]; // [esp+30h] [ebp-50h] BYREF
  void *v5; // [esp+54h] [ebp-2Ch]
  CInterfaceD3D *v6; // [esp+58h] [ebp-28h]
  CInterfaceD3D *v7; // [esp+5Ch] [ebp-24h]
  CInterfaceD3D *v8; // [esp+64h] [ebp-1Ch]
  CInterfaceD3D *v9; // [esp+68h] [ebp-18h]
  void *C; // [esp+6Ch] [ebp-14h]
  IGfxEngine *v11; // [esp+70h] [ebp-10h]
  int v12; // [esp+7Ch] [ebp-4h]

  v11 = this;
  if ( D3DObjectPtr && (D3DObjectPtr->field_71D || D3DObjectPtr->field_71C) )
    return 0;
  qmemcpy(v3, &GfxEngineSetup, sizeof(v3));
  LOWORD(v4[0]) = 1;
  BYTE2(v4[0]) = 0;
  v4[1] = 2;
  v4[2] = 0;
  v4[3] = v3[3];
  v4[4] = v3[4];
  memset(&v4[5], 0, 16);
  qmemcpy(&GfxEngineSetup, v4, 0x24u);
  if ( D3DObjectPtr
    || ((C = operator new(0x794u), v12 = 0, !C) ? (v9 = 0) : (v9 = CInterfaceD3D::CInterfaceD3D((CInterfaceD3D *)C)),
        v7 = v9,
        v12 = -1,
        (D3DObjectPtr = v9) != 0) )
  {
    IsInterface7Available = CInterfaceD3D::IsInterface7Available(D3DObjectPtr, (bool *)v11 + 32, v3[2]);
    *((_DWORD *)v11 + 6) = IsInterface7Available;
    v6 = D3DObjectPtr;
    v8 = D3DObjectPtr;
    if ( D3DObjectPtr )
      v5 = CInterfaceD3D::`scalar deleting destructor'(v8, 1u);
    else
      v5 = 0;
    D3DObjectPtr = 0;
    qmemcpy(&GfxEngineSetup, v3, 0x24u);
    return *((_DWORD *)v11 + 6) == 0;
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: GFX ENGINE: Couldn't create gfx engine interface object!");
    qmemcpy(&GfxEngineSetup, v3, 0x24u);
    return 0;
  }
}


// address=[0x2f5cf10]
// Decompiled from bool __thiscall IGfxEngine::IsSoftwareRenderingAvailable(IGfxEngine *this)
bool  IGfxEngine::IsSoftwareRenderingAvailable(void) {
  
  int IsInterface3Available; // eax
  HWND v3[9]; // [esp+Ch] [ebp-74h] BYREF
  _DWORD v4[9]; // [esp+30h] [ebp-50h] BYREF
  void *v5; // [esp+54h] [ebp-2Ch]
  CInterfaceD3D *v6; // [esp+58h] [ebp-28h]
  CInterfaceD3D *v7; // [esp+5Ch] [ebp-24h]
  CInterfaceD3D *v8; // [esp+64h] [ebp-1Ch]
  CInterfaceD3D *v9; // [esp+68h] [ebp-18h]
  void *C; // [esp+6Ch] [ebp-14h]
  IGfxEngine *v11; // [esp+70h] [ebp-10h]
  int v12; // [esp+7Ch] [ebp-4h]

  v11 = this;
  if ( D3DObjectPtr && (D3DObjectPtr->field_71D || D3DObjectPtr->field_71C) )
    return 0;
  qmemcpy(v3, &GfxEngineSetup, sizeof(v3));
  LOWORD(v4[0]) = 0;
  BYTE2(v4[0]) = 0;
  v4[1] = 2;
  v4[2] = 0;
  v4[3] = v3[3];
  v4[4] = v3[4];
  memset(&v4[5], 0, 16);
  qmemcpy(&GfxEngineSetup, v4, 0x24u);
  if ( D3DObjectPtr
    || ((C = operator new(0x794u), v12 = 0, !C) ? (v9 = 0) : (v9 = CInterfaceD3D::CInterfaceD3D((CInterfaceD3D *)C)),
        v7 = v9,
        v12 = -1,
        (D3DObjectPtr = v9) != 0) )
  {
    if ( g_pDirectDraw )
    {
      *((_DWORD *)v11 + 7) = 0;
    }
    else
    {
      IsInterface3Available = CInterfaceD3D::IsInterface3Available(D3DObjectPtr, v3[2]);
      *((_DWORD *)v11 + 7) = IsInterface3Available;
    }
    v6 = D3DObjectPtr;
    v8 = D3DObjectPtr;
    if ( D3DObjectPtr )
      v5 = CInterfaceD3D::`scalar deleting destructor'(v8, 1u);
    else
      v5 = 0;
    D3DObjectPtr = 0;
    qmemcpy(&GfxEngineSetup, v3, 0x24u);
    return *((_DWORD *)v11 + 7) == 0;
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: GFX ENGINE: Couldn't create gfx engine interface object!");
    qmemcpy(&GfxEngineSetup, v3, 0x24u);
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
    CInterfaceD3D::`scalar deleting destructor'(D3DObjectPtr, 1u);
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
    if ( byte_3E2E262 )
      inited = CInterfaceD3D::InitCommonV3(D3DObjectPtr);
    else
      inited = CInterfaceD3D::InitCommon(D3DObjectPtr);
    IGfxEngine::SetCameraTriangleSize(this, 1572864);
    if ( !inited )
      return 0;
    if ( byte_3E2E261 )
      return 1;
    if ( SGfxRenderConfiguration::IsHardwareLandscapeEngine((SGfxRenderConfiguration *)&GfxEngineSetup) )
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


