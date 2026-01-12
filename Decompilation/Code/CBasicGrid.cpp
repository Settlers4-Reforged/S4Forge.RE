#include "CBasicGrid.h"

// Definitions for class CBasicGrid

// address=[0x2fc5160]
// Decompiled from void __thiscall CBasicGrid::~CBasicGrid(CBasicGrid *this)
 CBasicGrid::~CBasicGrid(void) {
  
  CGrid::~CGrid((CBasicGrid *)((char *)this + 4));
}


// address=[0x2fc56e0]
// Decompiled from CBasicGrid *__thiscall CBasicGrid::CBasicGrid(CBasicGrid *this, int a2, int a3)
 CBasicGrid::CBasicGrid(int,int) {
  
  CGrid::CGrid((CBasicGrid *)((char *)this + 4), a2);
  *(_DWORD *)this = &CBasicGrid::_vftable_;
  *((_DWORD *)this + 3) = a3;
  return this;
}


// address=[0x2fc5720]
// Decompiled from int __thiscall CBasicGrid::initGrid(CBasicGrid *this)
void  CBasicGrid::initGrid(void) {
  
  int v1; // esi
  int v2; // esi
  int v3; // esi
  int v4; // esi
  unsigned int v5; // eax
  int result; // eax
  double v7; // [esp+4h] [ebp-98h]
  double v8; // [esp+Ch] [ebp-90h]
  int v9; // [esp+1Ch] [ebp-80h]
  int v10; // [esp+20h] [ebp-7Ch]
  int v11; // [esp+2Ch] [ebp-70h]
  int n; // [esp+30h] [ebp-6Ch]
  int v13; // [esp+34h] [ebp-68h]
  int v14; // [esp+38h] [ebp-64h] BYREF
  int v15; // [esp+3Ch] [ebp-60h] BYREF
  int v16; // [esp+40h] [ebp-5Ch]
  int v17; // [esp+44h] [ebp-58h] BYREF
  int v18; // [esp+48h] [ebp-54h] BYREF
  int v19; // [esp+4Ch] [ebp-50h]
  int v20; // [esp+50h] [ebp-4Ch]
  int v21; // [esp+54h] [ebp-48h]
  int m; // [esp+58h] [ebp-44h]
  int k; // [esp+5Ch] [ebp-40h]
  int v24; // [esp+60h] [ebp-3Ch]
  int v25; // [esp+64h] [ebp-38h]
  int v26; // [esp+68h] [ebp-34h]
  int v27; // [esp+6Ch] [ebp-30h]
  int v28; // [esp+70h] [ebp-2Ch]
  int v29; // [esp+74h] [ebp-28h]
  int v30; // [esp+78h] [ebp-24h]
  int v31; // [esp+7Ch] [ebp-20h]
  int i; // [esp+80h] [ebp-1Ch]
  void *v33; // [esp+84h] [ebp-18h]
  void *v34; // [esp+88h] [ebp-14h]
  unsigned int v35; // [esp+8Ch] [ebp-10h]
  unsigned int v36; // [esp+90h] [ebp-Ch]
  CBasicGrid *v37; // [esp+94h] [ebp-8h]
  int j; // [esp+98h] [ebp-4h]

  v37 = this;
  v35 = CRandom16::Rand((CRandom16 *)g_pRand) % *((_DWORD *)this + 2);
  v36 = CRandom16::Rand((CRandom16 *)g_pRand) % *((_DWORD *)v37 + 2);
  *(_BYTE *)(*((_DWORD *)v37 + 1) + v35 + *((_DWORD *)v37 + 2) * v36) = 101;
  CPlayerData::setStartPos_Basic(*(CPlayerData **)g_pPlayerData, v35, v36);
  v19 = *((_DWORD *)v37 + 2);
  v34 = operator new[](4 * *((_DWORD *)v37 + 2));
  j__memset(v34, 0, 4 * *((_DWORD *)v37 + 2));
  v33 = operator new[](4 * *((_DWORD *)v37 + 2));
  j__memset(v33, 0, 4 * *((_DWORD *)v37 + 2));
  for ( i = 1; i < (unsigned __int8)g_iNumPlayers; ++i )
  {
    v8 = pow<int,int>(v19, 3);
    *((_DWORD *)v34 + v35) = (int)((double)*((int *)v34 + v35) + v8);
    v7 = pow<int,int>(v19, 3);
    *((_DWORD *)v33 + v36) = (int)((double)*((int *)v33 + v36) + v7);
    for ( j = 1; j < *((_DWORD *)v37 + 2); ++j )
    {
      v24 = (int)pow<int,int>(v19 - j, 3);
      if ( (int)(v35 - j) >= 0 )
        *((_DWORD *)v34 + v35 - j) += v24;
      if ( (signed int)(j + v35) < *((_DWORD *)v37 + 2) )
        *((_DWORD *)v34 + j + v35) += v24;
      if ( (int)(v36 - j) >= 0 )
        *((_DWORD *)v33 + v36 - j) += v24;
      if ( (signed int)(j + v36) < *((_DWORD *)v37 + 2) )
        *((_DWORD *)v33 + j + v36) += v24;
    }
    v31 = 0;
    v30 = 0;
    for ( j = 1; j < *((_DWORD *)v37 + 2); ++j )
    {
      if ( *((_DWORD *)v34 + v31) > *((_DWORD *)v34 + j) )
        v31 = j;
      if ( *((_DWORD *)v33 + v30) > *((_DWORD *)v33 + j) )
        v30 = j;
    }
    v35 = v31;
    v36 = v30;
    CPlayerData::setStartPos_Basic(*(CPlayerData **)(g_pPlayerData + 4 * i), v31, v30);
    v21 = 0;
    v10 = (int)((double)*((int *)v34 + v35) * 0.4);
    v9 = (int)((double)*((int *)v33 + v36) * 0.4);
    for ( j = 0; j < *((_DWORD *)v37 + 2); ++j )
    {
      if ( j != v35 && v10 + *((_DWORD *)v34 + v35) > *((_DWORD *)v34 + j) )
      {
        v16 = 2 * *((_DWORD *)v37 + 2);
        v27 = 2 * *((_DWORD *)v37 + 2);
        for ( k = 0; k < i; ++k )
        {
          v18 = 0;
          v17 = 0;
          CPlayerData::getStartPos_Basic(*(CPlayerData **)(g_pPlayerData + 4 * k), &v18, &v17);
          v1 = j__abs(v18 - v35);
          v28 = j__abs(v17 - v36) + v1;
          if ( v28 < v16 )
            v16 = v28;
          v2 = j__abs(v18 - j);
          v28 = j__abs(v17 - v36) + v2;
          if ( v28 < v27 )
            v27 = v28;
        }
        if ( v27 > v16 && v27 > v21 )
        {
          v31 = j;
          v21 = v27;
        }
      }
    }
    if ( v31 != v35 )
      v35 = v31;
    for ( j = 0; j < *((_DWORD *)v37 + 2); ++j )
    {
      if ( j != v36 && v9 + *((_DWORD *)v33 + v36) > *((_DWORD *)v33 + j) )
      {
        v13 = 2 * *((_DWORD *)v37 + 2);
        v25 = v13;
        for ( m = 0; m < i; ++m )
        {
          v15 = 0;
          v14 = 0;
          CPlayerData::getStartPos_Basic(*(CPlayerData **)(g_pPlayerData + 4 * m), &v15, &v14);
          v3 = j__abs(v15 - v35);
          v26 = j__abs(v14 - v36) + v3;
          if ( v26 < v13 )
            v13 = v26;
          v4 = j__abs(v15 - v35);
          v26 = j__abs(v14 - j) + v4;
          if ( v26 < v25 )
            v25 = v26;
        }
        if ( v25 > v13 && v25 > v21 )
        {
          v30 = j;
          v21 = v25;
        }
      }
    }
    if ( v30 != v36 )
      v36 = v30;
    *(_BYTE *)(*((_DWORD *)v37 + 1) + v35 + *((_DWORD *)v37 + 2) * v36) = 101;
    CPlayerData::setStartPos_Basic(*(CPlayerData **)(g_pPlayerData + 4 * i), v35, v36);
  }
  operator delete[](v34);
  operator delete[](v33);
  v20 = *((_DWORD *)v37 + 2) * *((_DWORD *)v37 + 2);
  v11 = (int)(float)((float)((float)v20 * (float)((float)*((int *)v37 + 3) / 100.0))
                   - (float)(unsigned __int8)g_iNumPlayers);
  for ( n = 0; n < v11; ++n )
  {
    v5 = CRandom16::Rand((CRandom16 *)g_pRand);
    v29 = v5 % v20;
    while ( *(_BYTE *)(*((_DWORD *)v37 + 1) + v29) )
    {
      if ( ++v29 >= v20 )
        v29 = 0;
    }
    *(_BYTE *)(*((_DWORD *)v37 + 1) + v29) = 1;
  }
  result = v11;
  if ( v11 <= v20 )
    return result;
  result = BBSupportDbgReport(2, "BasicGrid.cpp", 220, "iLandMass <= iGridSize");
  if ( result == 1 )
    __debugbreak();
  return result;
}


