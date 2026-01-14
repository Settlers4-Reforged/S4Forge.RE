#include "all_headers.h"

// Definitions for class CRiver

// address=[0x2fcb5a0]
// Decompiled from CRiver *__thiscall CRiver::CRiver(CRiver *this, int a2, int a3)
 CRiver::CRiver(int,int) {
  
  int v4; // [esp+8h] [ebp-18h] BYREF
  int v5; // [esp+Ch] [ebp-14h] BYREF
  int Size; // [esp+10h] [ebp-10h]
  int Border; // [esp+14h] [ebp-Ch]
  CRiver *v8; // [esp+18h] [ebp-8h]
  bool v9; // [esp+1Fh] [ebp-1h]

  v8 = this;
  *((_DWORD *)this + 1) = operator new[](8u);
  *((_DWORD *)v8 + 2) = operator new[](8u);
  *(_DWORD *)v8 = 2;
  v4 = a2;
  v5 = a3;
  Size = CGrid::getSize((CGrid *)g_pFeatureGrid);
  v9 = 0;
  if ( a2 && a2 != Size - 2 && a3 && a3 != Size - 2 )
    v9 = !CFeatureGrid::findNearestElement((CFeatureGrid *)g_pFeatureGrid, &v4, &v5, 0, 0);
  if ( v9 )
  {
    *(_DWORD *)v8 = 0;
  }
  else
  {
    Border = CRiver::findBorder(
               v8,
               (int)(float)((float)((float)((float)v4 * *(float *)&g_fScaleFactor) + 50.0) + *(float *)&g_fScaleFactor),
               (int)(float)((float)((float)((float)v5 * *(float *)&g_fScaleFactor) + 50.0) + *(float *)&g_fScaleFactor));
    if ( Border == -1 )
    {
      *(_DWORD *)v8 = 0;
    }
    else
    {
      *(_DWORD *)(*((_DWORD *)v8 + 1) + 4) = Border % g_iWorldSize;
      *(_DWORD *)(*((_DWORD *)v8 + 2) + 4) = Border / g_iWorldSize;
      **((_DWORD **)v8 + 1) = (int)(float)((float)((float)((float)a2 * *(float *)&g_fScaleFactor) + 50.0)
                                         + *(float *)&g_fScaleFactor);
      **((_DWORD **)v8 + 2) = (int)(float)((float)((float)((float)a3 * *(float *)&g_fScaleFactor) + 50.0)
                                         + *(float *)&g_fScaleFactor);
    }
  }
  return v8;
}


// address=[0x2fcb760]
// Decompiled from CRiver *__thiscall CRiver::CRiver(CRiver *this, int a2, int a3, int a4)
 CRiver::CRiver(int,int,int) {
  
  int Border; // eax
  int Size; // [esp+Ch] [ebp-18h]
  int i; // [esp+10h] [ebp-14h]
  int v9; // [esp+18h] [ebp-Ch] BYREF
  int v10; // [esp+1Ch] [ebp-8h] BYREF
  char v11; // [esp+23h] [ebp-1h]

  *((_DWORD *)this + 1) = operator new[](4 * a4);
  *((_DWORD *)this + 2) = operator new[](4 * a4);
  *(_DWORD *)this = a4;
  v10 = a2;
  v9 = a3;
  if ( CFeatureGrid::findNearestElement((CFeatureGrid *)g_pFeatureGrid, &v10, &v9, 0, 0) )
  {
    Size = CGrid::getSize((CGrid *)g_pFeatureGrid);
    Border = CRiver::findBorder(
               this,
               (int)(float)((float)((float)((float)v10 * *(float *)&g_fScaleFactor) + 50.0)
                          + (float)(*(float *)&g_fScaleFactor / 2.0)),
               (int)(float)((float)((float)((float)v9 * *(float *)&g_fScaleFactor) + 50.0)
                          + (float)(*(float *)&g_fScaleFactor / 2.0)));
    *(_DWORD *)(*((_DWORD *)this + 1) + 4 * *(_DWORD *)this - 4) = Border % g_iWorldSize;
    *(_DWORD *)(*((_DWORD *)this + 2) + 4 * *(_DWORD *)this - 4) = Border / g_iWorldSize;
    if ( CGrid::getElement((CGrid *)g_pFeatureGrid, v10, v9) == 1 )
      CGrid::setElement((CGrid *)g_pFeatureGrid, v10, v9, 103);
    for ( i = *(_DWORD *)this - 2; i >= 0; --i )
    {
      v11 = 0;
      if ( (v10 < 0 || v10 >= Size)
        && BBSupportDbgReport(2, "River.cpp", 69, "iCurX >= 0 && iCurX < iFeatureGridSize") == 1 )
      {
        __debugbreak();
      }
      if ( (v9 < 0 || v9 >= Size)
        && BBSupportDbgReport(2, "River.cpp", 70, "iCurY >= 0 && iCurY < iFeatureGridSize") == 1 )
      {
        __debugbreak();
      }
      if ( i >= a4 && BBSupportDbgReport(2, "River.cpp", 71, "iRiverPoint >= 0 && iRiverPoint < _iRiverLength") == 1 )
        __debugbreak();
      if ( !v11
        && v10 + 1 < Size
        && CGrid::getElement((CGrid *)g_pFeatureGrid, v10 + 1, v9)
        && CGrid::getElement((CGrid *)g_pFeatureGrid, v10 + 1, v9) != 102
        && CGrid::getElement((CGrid *)g_pFeatureGrid, v10 + 1, v9) != 106 )
      {
        ++v10;
        v11 = 1;
      }
      if ( !v11
        && v9 + 1 < Size
        && CGrid::getElement((CGrid *)g_pFeatureGrid, v10, v9 + 1)
        && CGrid::getElement((CGrid *)g_pFeatureGrid, v10, v9 + 1) != 102
        && CGrid::getElement((CGrid *)g_pFeatureGrid, v10, v9 + 1) != 106 )
      {
        ++v9;
        v11 = 1;
      }
      if ( !v11
        && v10 - 1 > 0
        && CGrid::getElement((CGrid *)g_pFeatureGrid, v10 - 1, v9)
        && CGrid::getElement((CGrid *)g_pFeatureGrid, v10 - 1, v9) != 102
        && CGrid::getElement((CGrid *)g_pFeatureGrid, v10 - 1, v9) != 106 )
      {
        --v10;
        v11 = 1;
      }
      if ( !v11
        && v9 - 1 > 0
        && CGrid::getElement((CGrid *)g_pFeatureGrid, v10, v9 - 1)
        && CGrid::getElement((CGrid *)g_pFeatureGrid, v10, v9 - 1) != 102
        && CGrid::getElement((CGrid *)g_pFeatureGrid, v10, v9 - 1) != 106 )
      {
        --v9;
        v11 = 1;
      }
      if ( CGrid::getElement((CGrid *)g_pFeatureGrid, v10, v9) == 1 )
        CGrid::setElement((CGrid *)g_pFeatureGrid, v10, v9, 103);
      *(_DWORD *)(*((_DWORD *)this + 1) + 4 * i) = (int)(float)((float)((float)((float)v10 * *(float *)&g_fScaleFactor)
                                                                      + 50.0)
                                                              + (float)(*(float *)&g_fScaleFactor / 2.0));
      *(_DWORD *)(*((_DWORD *)this + 2) + 4 * i) = (int)(float)((float)((float)((float)v9 * *(float *)&g_fScaleFactor)
                                                                      + 50.0)
                                                              + (float)(*(float *)&g_fScaleFactor / 2.0));
      if ( !v11 )
        *(_DWORD *)this = 0;
    }
  }
  else
  {
    *(_DWORD *)this = 0;
  }
  return this;
}


// address=[0x2fcbbf0]
// Decompiled from int __thiscall CRiver::~CRiver(void **this)
 CRiver::~CRiver(void) {
  
  operator delete[](this[1]);
  return operator delete[](this[2]);
}


// address=[0x2fcbc30]
// Decompiled from int __thiscall CRiver::drawRiver(CRiver *this)
void  CRiver::drawRiver(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < *(_DWORD *)this - 1; ++i )
  {
    CRiver::drawRiverPart(
      this,
      *(_DWORD *)(*((_DWORD *)this + 1) + 4 * i),
      *(_DWORD *)(*((_DWORD *)this + 2) + 4 * i),
      *(_DWORD *)(*((_DWORD *)this + 1) + 4 * i + 4),
      *(_DWORD *)(*((_DWORD *)this + 2) + 4 * i + 4));
    result = i + 1;
  }
  return result;
}


// address=[0x2fcbca0]
// Decompiled from void __thiscall CRiver::drawRiverPart(CRiver *this, __int64 a2, int a3, int a4)
void  CRiver::drawRiverPart(int,int,int,int) {
  
  double X; // xmm0_8
  double v5; // [esp+10h] [ebp-ACh]
  double v6; // [esp+20h] [ebp-9Ch]
  double v7; // [esp+28h] [ebp-94h]
  double v8; // [esp+30h] [ebp-8Ch]
  __int64 v9; // [esp+50h] [ebp-6Ch]
  int v10; // [esp+58h] [ebp-64h]
  int v11; // [esp+5Ch] [ebp-60h]
  int v12; // [esp+64h] [ebp-58h]
  int k; // [esp+68h] [ebp-54h]
  int v14; // [esp+6Ch] [ebp-50h]
  int v15; // [esp+70h] [ebp-4Ch]
  int v16; // [esp+74h] [ebp-48h]
  char v17; // [esp+7Bh] [ebp-41h]
  __int64 v18; // [esp+7Ch] [ebp-40h]
  int i; // [esp+84h] [ebp-38h]
  int j; // [esp+84h] [ebp-38h]
  _DWORD v21[6]; // [esp+88h] [ebp-34h]
  _DWORD v22[6]; // [esp+A0h] [ebp-1Ch]

  v22[0] = -1;
  v22[1] = 0;
  v22[2] = 1;
  v22[3] = 1;
  v22[4] = 0;
  v22[5] = -1;
  v21[0] = 0;
  v21[1] = 1;
  v21[2] = 1;
  v21[3] = 0;
  v21[4] = -1;
  v21[5] = -1;
  v18 = a2;
  v8 = pow<int,int>(a3 - (int)a2, 2);
  v7 = pow<int,int>(a4 - HIDWORD(a2), 2);
  v6 = sqrt(v8 + v7);
  v12 = 0;
  v14 = 0;
  if ( (a3 >= g_iWorldSize || a3 <= 0)
    && BBSupportDbgReport(2, "River.cpp", 161, "_iEndX < g_iWorldSize && _iEndX > 0") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 >= g_iWorldSize || a4 <= 0)
    && BBSupportDbgReport(2, "River.cpp", 162, "_iEndY < g_iWorldSize && _iEndY > 0") == 1 )
  {
    __debugbreak();
  }
  if ( ((int)a2 <= 0 || (int)a2 >= g_iWorldSize)
    && BBSupportDbgReport(2, "River.cpp", 163, "_iStartX > 0 && _iStartX < g_iWorldSize") == 1 )
  {
    __debugbreak();
  }
  if ( (SHIDWORD(a2) <= 0 || SHIDWORD(a2) >= g_iWorldSize)
    && BBSupportDbgReport(2, "River.cpp", 164, "_iStartY > 0 && _iStartY < g_iWorldSize") == 1 )
  {
    __debugbreak();
  }
  v16 = 0;
  v17 = 0;
  v15 = 1048567;
  while ( v15 > 3 )
  {
    v15 = 1048567;
    for ( i = 0; i < 6; ++i )
    {
      v5 = pow<int,int>(a3 - (int)v18 - v22[i], 2);
      X = v5 + pow<int,int>(a4 - HIDWORD(v18) - v21[i], 2);
      v10 = (int)sqrt(X);
      if ( v10 < v15 )
      {
        v15 = v10;
        if ( !v14 )
          v16 = i;
      }
    }
    if ( !(CRandom16::Rand((CRandom16 *)g_pRand) % 4) && !v14 && v15 > 8 )
    {
      if ( ++v16 == -1 )
        v16 = 5;
      if ( v16 == 6 )
        v16 = 0;
      v14 = 3;
    }
    if ( v15 < (int)(v6 / 4.0) * (3 - v12) )
      ++v12;
    if ( *(_BYTE *)(g_pMapElement + 4 * (v18 + g_iWorldSize * HIDWORD(v18)) + 1) != 16 || v17 )
    {
      v17 = 0;
    }
    else
    {
      *(_BYTE *)(g_pMapElement + 4 * (v18 + g_iWorldSize * HIDWORD(v18)) + 1) = v12 + 96;
      *(_BYTE *)(g_pEditorLayer + 4 * (v18 + g_iWorldSize * HIDWORD(v18)) + 3) = CRandom16::Rand((CRandom16 *)g_pRand)
                                                                               % (unsigned __int8)g_uResourceWealth;
    }
    v9 = v18;
    LODWORD(v18) = v22[v16] + v18;
    HIDWORD(v18) += v21[v16];
    if ( v14 )
    {
      if ( v14 % 2 )
      {
        if ( --v16 == -1 )
          v16 = 5;
      }
      --v14;
    }
    for ( j = 0; j < 6; ++j )
    {
      v11 = *(_BYTE *)(g_pMapElement + 4 * (g_iWorldSize * (v21[j] + HIDWORD(v18)) + v22[j] + v18) + 1) & 0xF0;
      if ( (v11 == 48
         || v11 == 64
         || v11 == 16
         || *(_BYTE *)(g_pMapElement + 4 * (g_iWorldSize * (v21[j] + HIDWORD(v18)) + v22[j] + v18) + 1) == 8)
        && *(_BYTE *)(g_pMapElement + 4 * (g_iWorldSize * (v21[j] + HIDWORD(v18)) + v22[j] + v18) + 1) != 16
        && *(_BYTE *)(g_pMapElement + 4 * (g_iWorldSize * (v21[j] + HIDWORD(v18)) + v22[j] + v18) + 1) != 17 )
      {
        for ( k = 0; k < 6; ++k )
        {
          if ( !*(_BYTE *)(g_pMapElement
                         + 4 * (g_iWorldSize * (v22[k] + v21[j] + HIDWORD(v18)) + v22[k] + v22[j] + v18)
                         + 1) )
          {
            v15 = 0;
            *(_BYTE *)(g_pMapElement + 4 * (v9 + g_iWorldSize * HIDWORD(v9)) + 1) = 99;
            *(_BYTE *)(g_pMapElement + 4 * (v18 + g_iWorldSize * HIDWORD(v18)) + 1) = 16;
          }
        }
        *(_BYTE *)(g_pMapElement + 4 * (g_iWorldSize * (v21[j] + HIDWORD(v18)) + v22[j] + v18) + 1) = 16;
      }
      if ( !*(_BYTE *)(g_pMapElement + 4 * (g_iWorldSize * (v21[j] + HIDWORD(v18)) + v22[j] + v18) + 1) )
      {
        *(_BYTE *)(g_pMapElement + 4 * (v18 + g_iWorldSize * HIDWORD(v18)) + 1) = 99;
        v15 = 0;
      }
      if ( *(_BYTE *)(g_pMapElement + 4 * (g_iWorldSize * (v21[j] + HIDWORD(v18)) + v22[j] + v18) + 1) == 17 )
        v17 = 1;
    }
    if ( (int)v18 >= g_iWorldSize && BBSupportDbgReport(2, "River.cpp", 286, "iCurrentX < g_iWorldSize") == 1 )
      __debugbreak();
    if ( (int)v18 <= 0 && BBSupportDbgReport(2, "River.cpp", 287, "iCurrentX > 0") == 1 )
      __debugbreak();
    if ( SHIDWORD(v18) >= g_iWorldSize && BBSupportDbgReport(2, "River.cpp", 288, "iCurrentY < g_iWorldSize") == 1 )
      __debugbreak();
    if ( SHIDWORD(v18) <= 0 && BBSupportDbgReport(2, "River.cpp", 289, "iCurrentY > 0") == 1 )
      __debugbreak();
  }
  MakeRiverMouth(v18, HIDWORD(v18));
}


// address=[0x2fcc380]
// Decompiled from int __thiscall CRiver::findBorder(CRiver *this, int a2, int a3)
int  CRiver::findBorder(int,int) {
  
  _DWORD v4[2]; // [esp+4h] [ebp-1028h] BYREF
  int i; // [esp+Ch] [ebp-1020h]
  size_t Size; // [esp+10h] [ebp-101Ch]
  void *Block; // [esp+14h] [ebp-1018h]
  int v8; // [esp+18h] [ebp-1014h] BYREF
  int v9; // [esp+1Ch] [ebp-1010h]
  _BYTE v10[4104]; // [esp+20h] [ebp-100Ch] BYREF

  Size = g_iWorldSize * g_iWorldSize;
  TStaticFIFO<int,1024>::TStaticFIFO<int,1024>(v10);
  Block = j__malloc(Size);
  memset(Block, 0, Size);
  v4[0] = a2 + g_iWorldSize * a3;
  TStaticFIFO<int,1024>::Push(v4);
  *((_BYTE *)Block + a2 + g_iWorldSize * a3) = 1;
  while ( !(unsigned __int8)TStaticFIFO<int,1024>::Empty(v10) )
  {
    v9 = *(_DWORD *)TStaticFIFO<int,1024>::Top(v10);
    TStaticFIFO<int,1024>::Pop(v10);
    for ( i = 0; i < 6; ++i )
    {
      v8 = 0;
      v4[1] = i;
      switch ( i )
      {
        case 0:
          if ( v9 - g_iWorldSize - 1 >= 0 )
            v8 = v9 - g_iWorldSize - 1;
          break;
        case 1:
          if ( v9 - g_iWorldSize >= 0 )
            v8 = v9 - g_iWorldSize;
          break;
        case 2:
          if ( v9 - 1 >= 0 )
            v8 = v9 - 1;
          break;
        case 3:
          if ( v9 + 1 < (int)Size )
            v8 = v9 + 1;
          break;
        case 4:
          if ( g_iWorldSize + v9 < (int)Size )
            v8 = g_iWorldSize + v9;
          break;
        case 5:
          if ( v9 + g_iWorldSize + 1 < (int)Size )
            v8 = v9 + g_iWorldSize + 1;
          break;
        default:
          break;
      }
      if ( !*((_BYTE *)Block + v8) )
      {
        TStaticFIFO<int,1024>::Push(&v8);
        *((_BYTE *)Block + v8) = 1;
        if ( !*(_BYTE *)(g_pMapElement + 4 * v8 + 1) )
        {
          j__free(Block);
          return v8;
        }
      }
    }
  }
  j__free(Block);
  return -1;
}


