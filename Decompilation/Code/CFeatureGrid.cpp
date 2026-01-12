#include "CFeatureGrid.h"

// Definitions for class CFeatureGrid

// address=[0x2fc5180]
// Decompiled from void __thiscall CFeatureGrid::~CFeatureGrid(CFeatureGrid *this)
 CFeatureGrid::~CFeatureGrid(void) {
  
  CGrid::~CGrid(this);
}


// address=[0x2fc6a40]
// Decompiled from CFeatureGrid *__thiscall CFeatureGrid::CFeatureGrid(CFeatureGrid *this, int a2)
 CFeatureGrid::CFeatureGrid(int) {
  
  CGrid::CGrid(this, a2);
  *((_DWORD *)this + 5) = -1;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 1;
  *((_DWORD *)this + 8) = 1;
  *((_DWORD *)this + 9) = 1;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = -1;
  *((_DWORD *)this + 12) = -1;
  *((_DWORD *)this + 13) = -1;
  *((_DWORD *)this + 14) = -1;
  *((_DWORD *)this + 15) = -1;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 1;
  *((_DWORD *)this + 18) = 1;
  *((_DWORD *)this + 19) = 1;
  *((_DWORD *)this + 20) = 0;
  return this;
}


// address=[0x2fc6b90]
// Decompiled from int __thiscall CFeatureGrid::initGrid(CFeatureGrid *this)
void  CFeatureGrid::initGrid(void) {
  
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  int v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  int v11; // esi
  int result; // eax
  unsigned int v13; // [esp+4h] [ebp-B4h]
  unsigned int v14; // [esp+8h] [ebp-B0h]
  unsigned int v15; // [esp+Ch] [ebp-ACh] BYREF
  unsigned int v16; // [esp+10h] [ebp-A8h] BYREF
  unsigned int v17; // [esp+14h] [ebp-A4h] BYREF
  unsigned int v18; // [esp+18h] [ebp-A0h] BYREF
  unsigned int v19; // [esp+1Ch] [ebp-9Ch]
  unsigned int v20; // [esp+20h] [ebp-98h]
  unsigned int v21; // [esp+24h] [ebp-94h]
  int v22; // [esp+28h] [ebp-90h]
  int v23; // [esp+2Ch] [ebp-8Ch]
  int jj; // [esp+30h] [ebp-88h]
  int v25; // [esp+34h] [ebp-84h] BYREF
  int v26; // [esp+38h] [ebp-80h] BYREF
  int n; // [esp+3Ch] [ebp-7Ch]
  int k; // [esp+40h] [ebp-78h]
  unsigned int v29; // [esp+44h] [ebp-74h]
  unsigned int v30; // [esp+48h] [ebp-70h] BYREF
  unsigned int v31; // [esp+4Ch] [ebp-6Ch] BYREF
  int m; // [esp+50h] [ebp-68h]
  int Size; // [esp+54h] [ebp-64h]
  int v34; // [esp+58h] [ebp-60h] BYREF
  int v35; // [esp+5Ch] [ebp-5Ch] BYREF
  int v36; // [esp+60h] [ebp-58h] BYREF
  int v37; // [esp+64h] [ebp-54h] BYREF
  unsigned int v38; // [esp+68h] [ebp-50h]
  int v39; // [esp+6Ch] [ebp-4Ch] BYREF
  int v40; // [esp+70h] [ebp-48h] BYREF
  int v41; // [esp+74h] [ebp-44h] BYREF
  int v42; // [esp+78h] [ebp-40h] BYREF
  char v43; // [esp+7Dh] [ebp-3Bh]
  char v44; // [esp+7Eh] [ebp-3Ah]
  char v45; // [esp+7Fh] [ebp-39h]
  int v46; // [esp+80h] [ebp-38h]
  int v47; // [esp+84h] [ebp-34h]
  int v48; // [esp+88h] [ebp-30h]
  char v49; // [esp+8Fh] [ebp-29h]
  int v50; // [esp+90h] [ebp-28h] BYREF
  int v51; // [esp+94h] [ebp-24h] BYREF
  unsigned int v52; // [esp+98h] [ebp-20h]
  unsigned int v53; // [esp+9Ch] [ebp-1Ch]
  int j; // [esp+A0h] [ebp-18h]
  int i; // [esp+A4h] [ebp-14h]
  int ii; // [esp+A8h] [ebp-10h]
  unsigned int v57; // [esp+ACh] [ebp-Ch]
  char v58; // [esp+B3h] [ebp-5h]
  CFeatureGrid *v59; // [esp+B4h] [ebp-4h]

  v59 = this;
  v48 = 0;
  Size = CGrid::getSize((CGrid *)(g_pBasicGrid + 4));
  for ( i = 0; i < Size; ++i )
  {
    for ( j = 0; j < Size; ++j )
    {
      if ( CGrid::getElement((CGrid *)(g_pBasicGrid + 4), j, i) == 1 )
      {
        v38 = 100;
        if ( j + 1 >= Size || j - 1 < 0 || i + 1 >= Size || i - 1 < 0 )
        {
          v38 = CRandom16::Rand((CRandom16 *)g_pRand) % 6;
        }
        else if ( !CGrid::getElement((CGrid *)(g_pBasicGrid + 4), j + 1, i)
               || !CGrid::getElement((CGrid *)(g_pBasicGrid + 4), j - 1, i)
               || !CGrid::getElement((CGrid *)(g_pBasicGrid + 4), j, i + 1)
               || !CGrid::getElement((CGrid *)(g_pBasicGrid + 4), j, i - 1) )
        {
          v38 = CRandom16::Rand((CRandom16 *)g_pRand) % 6;
        }
        if ( v38 )
        {
          *(_BYTE *)(*(_DWORD *)v59 + 2 * *((_DWORD *)v59 + 1) * i + 2 * j) = 1;
          ++v48;
        }
        if ( v38 != 1 )
        {
          *(_BYTE *)(*(_DWORD *)v59 + 2 * *((_DWORD *)v59 + 1) * i + 2 * j + 1) = 1;
          ++v48;
        }
        if ( v38 != 2 )
        {
          *(_BYTE *)(*(_DWORD *)v59 + *((_DWORD *)v59 + 1) * (2 * i + 1) + 2 * j) = 1;
          ++v48;
        }
        if ( v38 != 3 )
        {
          *(_BYTE *)(*(_DWORD *)v59 + *((_DWORD *)v59 + 1) * (2 * i + 1) + 2 * j + 1) = 1;
          ++v48;
        }
        if ( *((_DWORD *)v59 + 1) * (2 * i + 1) + 2 * j + 1 >= *((_DWORD *)v59 + 1) * *((_DWORD *)v59 + 1)
          && BBSupportDbgReport(2, "FeatureGrid.cpp", 93, "( x * 2 + ( y * 2 + 1 ) * m_iSize + 1 ) < m_iSize * m_iSize") == 1 )
        {
          __debugbreak();
        }
      }
      if ( CGrid::getElement((CGrid *)(g_pBasicGrid + 4), j, i) == 101 )
      {
        *(_BYTE *)(*(_DWORD *)v59 + 2 * *((_DWORD *)v59 + 1) * i + 2 * j) = 101;
        *(_BYTE *)(*(_DWORD *)v59 + 2 * *((_DWORD *)v59 + 1) * i + 2 * j + 1) = 101;
        *(_BYTE *)(*(_DWORD *)v59 + *((_DWORD *)v59 + 1) * (2 * i + 1) + 2 * j) = 101;
        *(_BYTE *)(*(_DWORD *)v59 + *((_DWORD *)v59 + 1) * (2 * i + 1) + 2 * j + 1) = 101;
      }
    }
  }
  v48 -= (unsigned __int8)g_iNumPlayers;
  *((_DWORD *)v59 + 2) = (int)(float)((float)v48 * 0.15000001);
  *((_DWORD *)v59 + 3) = (int)(float)((float)v48 * 0.5);
  *((_DWORD *)v59 + 4) = (int)(float)((float)v48 * 0.15000001);
  if ( (g_iFlags & 2) != 0 || (g_iFlags & 1) != 0 )
  {
    *((_DWORD *)v59 + 3) += (unsigned __int8)g_iNumPlayers / 2;
    *((_DWORD *)v59 + 4) += (unsigned __int8)g_iNumPlayers / 2;
  }
  if ( (g_iFlags & 2) != 0 && (g_iFlags & 1) != 0 )
  {
    *((_DWORD *)v59 + 3) += (unsigned __int8)g_iNumPlayers / 4;
    *((_DWORD *)v59 + 4) += (unsigned __int8)g_iNumPlayers / 4;
  }
  for ( k = 0; k < *((_DWORD *)v59 + 2); ++k )
  {
    v1 = CRandom16::Rand((CRandom16 *)g_pRand);
    v31 = v1 % *((_DWORD *)v59 + 1);
    v2 = CRandom16::Rand((CRandom16 *)g_pRand);
    v30 = v2 % *((_DWORD *)v59 + 1);
    for ( m = 0; !CFeatureGrid::findNearestElement(v59, (int *)&v31, (int *)&v30, 1, 1) && m < 5; ++m )
    {
      v3 = CRandom16::Rand((CRandom16 *)g_pRand);
      v31 = v3 % *((_DWORD *)v59 + 1);
      v4 = CRandom16::Rand((CRandom16 *)g_pRand);
      v30 = v4 % *((_DWORD *)v59 + 1);
    }
    if ( m < 5 )
    {
      *(_BYTE *)(*(_DWORD *)v59 + v31 + *((_DWORD *)v59 + 1) * v30) = 102;
      v46 = v31;
      v47 = v30;
      for ( n = 1; n < 2; ++n )
      {
        v58 = 0;
        if ( (v46 < 0 || v46 >= *((_DWORD *)v59 + 1))
          && BBSupportDbgReport(2, "FeatureGrid.cpp", 155, "iCurX >= 0 && iCurX < m_iSize") == 1 )
        {
          __debugbreak();
        }
        if ( (v47 < 0 || v47 >= *((_DWORD *)v59 + 1))
          && BBSupportDbgReport(2, "FeatureGrid.cpp", 156, "iCurY >= 0 && iCurY < m_iSize") == 1 )
        {
          __debugbreak();
        }
        if ( !v58
          && v46 + 1 < *((_DWORD *)v59 + 1)
          && *(_BYTE *)(*(_DWORD *)v59 + v46 + *((_DWORD *)v59 + 1) * v47 + 1) == 1 )
        {
          ++v46;
          v58 = 1;
        }
        if ( !v58
          && v47 + 1 < *((_DWORD *)v59 + 1)
          && *(_BYTE *)(*(_DWORD *)v59 + v46 + *((_DWORD *)v59 + 1) * (v47 + 1)) == 1 )
        {
          ++v47;
          v58 = 1;
        }
        if ( !v58 && v46 - 1 > 0 && *(_BYTE *)(*(_DWORD *)v59 + v46 + *((_DWORD *)v59 + 1) * v47 - 1) == 1 )
        {
          --v46;
          v58 = 1;
        }
        if ( !v58 && v47 - 1 > 0 && *(_BYTE *)(*(_DWORD *)v59 + v46 + *((_DWORD *)v59 + 1) * (v47 - 1)) == 1 )
        {
          --v47;
          v58 = 1;
        }
        *(_BYTE *)(*(_DWORD *)v59 + v46 + *((_DWORD *)v59 + 1) * v47) = 102;
      }
    }
  }
  for ( ii = 0; ii < (unsigned __int8)g_iNumPlayers; ++ii )
  {
    v50 = 0;
    v51 = 0;
    CPlayerData::getStartPos_Basic(*(CPlayerData **)(g_pPlayerData + 4 * ii), &v50, &v51);
    v50 *= 2;
    v51 *= 2;
    v25 = v50;
    v26 = v51;
    v49 = 0;
    if ( CFeatureGrid::findNearestElement((CFeatureGrid *)g_pFeatureGrid, &v25, &v26, 102, 1) )
    {
      v5 = j__abs(v25 - v50);
      if ( j__abs(v26 - v51) + v5 <= 2 )
        CPlayerData::setNearestMountain(*(CPlayerData **)(g_pPlayerData + 4 * ii), v25, v26);
      else
        v49 = 1;
    }
    else
    {
      v49 = 1;
    }
    if ( v49 )
    {
      v29 = CRandom16::Rand((CRandom16 *)g_pRand) % 8;
      if ( (int)(v29 + 1) <= 7 )
      {
        v57 = v29 + 1;
        v19 = v29 + 1;
      }
      else
      {
        v57 = 0;
        v19 = 0;
      }
      v57 = v19;
      v45 = 0;
      if ( !v50 )
        v50 = 1;
      if ( v50 == *((_DWORD *)v59 + 1) - 1 )
        --v50;
      if ( !v51 )
        v51 = 1;
      if ( v51 == *((_DWORD *)v59 + 1) - 1 )
        --v51;
      while ( v57 != v29 && !v45 )
      {
        if ( (g_iFlags & 1) != 0 && (g_iFlags & 2) != 0 && v57 == 4 && v29 != 5 )
          ++v57;
        if ( *((_DWORD *)v59 + v57 + 5) + v50 >= 0
          && *((_DWORD *)v59 + v57 + 5) + v50 < *((_DWORD *)v59 + 1)
          && *((_DWORD *)v59 + v57 + 13) + v51 >= 0
          && *((_DWORD *)v59 + v57 + 13) + v51 < *((_DWORD *)v59 + 1)
          && *(_BYTE *)(*(_DWORD *)v59
                      + *((_DWORD *)v59 + 1) * (*((_DWORD *)v59 + v57 + 13) + v51)
                      + *((_DWORD *)v59 + v57 + 5)
                      + v50) != 101 )
        {
          v45 = 1;
          *(_BYTE *)(*(_DWORD *)v59
                   + *((_DWORD *)v59 + 1) * (*((_DWORD *)v59 + v57 + 13) + v51)
                   + *((_DWORD *)v59 + v57 + 5)
                   + v50) = 102;
          CPlayerData::setNearestMountain(
            *(CPlayerData **)(g_pPlayerData + 4 * ii),
            *((_DWORD *)v59 + v57 + 5) + v50,
            *((_DWORD *)v59 + v57 + 13) + v51);
        }
        if ( ++v57 == 8 )
          v57 = 0;
      }
    }
  }
  v23 = 0;
  v22 = 0;
  for ( jj = 0; jj < v48; ++jj )
  {
    if ( v23 <= *((_DWORD *)v59 + 3) )
    {
      v6 = CRandom16::Rand((CRandom16 *)g_pRand);
      v17 = v6 % *((_DWORD *)v59 + 1);
      v7 = CRandom16::Rand((CRandom16 *)g_pRand);
      v18 = v7 % *((_DWORD *)v59 + 1);
      if ( CFeatureGrid::findNearestElement(v59, (int *)&v17, (int *)&v18, 1, 0) )
      {
        *(_BYTE *)(*(_DWORD *)v59 + v17 + *((_DWORD *)v59 + 1) * v18) = 104;
        ++v23;
      }
    }
    if ( v22 <= *((_DWORD *)v59 + 4) )
    {
      v8 = CRandom16::Rand((CRandom16 *)g_pRand);
      v15 = v8 % *((_DWORD *)v59 + 1);
      v9 = CRandom16::Rand((CRandom16 *)g_pRand);
      v16 = v9 % *((_DWORD *)v59 + 1);
      if ( CFeatureGrid::findNearestElement(v59, (int *)&v15, (int *)&v16, 1, 0) )
      {
        *(_BYTE *)(*(_DWORD *)v59 + v15 + *((_DWORD *)v59 + 1) * v16) = 105;
        ++v22;
      }
    }
  }
  for ( ii = 0; ii < (unsigned __int8)g_iNumPlayers; ++ii )
  {
    v10 = CRandom16::Rand((CRandom16 *)g_pRand);
    v21 = v10 % 3 + 3;
    if ( (int)(v10 % 3 + 4) <= 7 )
    {
      v52 = v21 + 1;
      v14 = v21 + 1;
    }
    else
    {
      v52 = 0;
      v14 = 0;
    }
    v52 = v14;
    v40 = 0;
    v39 = 0;
    CPlayerData::getStartPos_Basic(*(CPlayerData **)(g_pPlayerData + 4 * ii), &v40, &v39);
    v40 *= 2;
    v39 *= 2;
    v44 = 0;
    while ( v52 != v21 && !v44 )
    {
      if ( *((_DWORD *)v59 + v52 + 5) + v40 >= 0
        && *((_DWORD *)v59 + v52 + 5) + v40 < *((_DWORD *)v59 + 1)
        && *((_DWORD *)v59 + v52 + 13) + v39 >= 0
        && *((_DWORD *)v59 + v52 + 13) + v39 < *((_DWORD *)v59 + 1)
        && *(_BYTE *)(*(_DWORD *)v59
                    + *((_DWORD *)v59 + 1) * (*((_DWORD *)v59 + v52 + 13) + v39)
                    + *((_DWORD *)v59 + v52 + 5)
                    + v40) == 101 )
      {
        *(_BYTE *)(*(_DWORD *)v59
                 + *((_DWORD *)v59 + 1) * (*((_DWORD *)v59 + v52 + 13) + v39)
                 + *((_DWORD *)v59 + v52 + 5)
                 + v40) = 104;
        v44 = 1;
      }
      if ( ++v52 == 8 )
        v52 = 0;
    }
  }
  for ( ii = 0; ii < (unsigned __int8)g_iNumPlayers; ++ii )
  {
    v37 = 0;
    v36 = 0;
    CPlayerData::getStartPos_Basic(*(CPlayerData **)(g_pPlayerData + 4 * ii), &v37, &v36);
    v37 *= 2;
    v36 *= 2;
    v34 = v37;
    v35 = v36;
    if ( !CFeatureGrid::findNearestElement(v59, &v34, &v35, 1, 1)
      || (v11 = j__abs(v34 - v37), j__abs(v35 - v36) + v11 > 3) )
    {
      v34 = v37;
      v35 = v36;
      CFeatureGrid::findNearestElement(v59, &v34, &v35, 0, 0);
    }
    *(_BYTE *)(*(_DWORD *)v59 + v34 + *((_DWORD *)v59 + 1) * v35) = 106;
  }
  for ( ii = 0; ; ++ii )
  {
    result = (unsigned __int8)g_iNumPlayers;
    if ( ii >= (unsigned __int8)g_iNumPlayers )
      break;
    v20 = CRandom16::Rand((CRandom16 *)g_pRand) % 8;
    if ( (int)(v20 + 1) <= 7 )
    {
      v53 = v20 + 1;
      v13 = v20 + 1;
    }
    else
    {
      v53 = 0;
      v13 = 0;
    }
    v53 = v13;
    v42 = 0;
    v41 = 0;
    CPlayerData::getStartPos_Basic(*(CPlayerData **)(g_pPlayerData + 4 * ii), &v42, &v41);
    v42 *= 2;
    v41 *= 2;
    v43 = 0;
    while ( v53 != v20 && !v43 )
    {
      if ( *((_DWORD *)v59 + v53 + 5) + v42 >= 0
        && *((_DWORD *)v59 + v53 + 5) + v42 < *((_DWORD *)v59 + 1)
        && *((_DWORD *)v59 + v53 + 13) + v41 >= 0
        && *((_DWORD *)v59 + v53 + 13) + v41 < *((_DWORD *)v59 + 1)
        && (*(_BYTE *)(*(_DWORD *)v59
                     + *((_DWORD *)v59 + 1) * (*((_DWORD *)v59 + v53 + 13) + v41)
                     + *((_DWORD *)v59 + v53 + 5)
                     + v42) == 1
         || *(_BYTE *)(*(_DWORD *)v59
                     + *((_DWORD *)v59 + 1) * (*((_DWORD *)v59 + v53 + 13) + v41)
                     + *((_DWORD *)v59 + v53 + 5)
                     + v42) == 101) )
      {
        *(_BYTE *)(*(_DWORD *)v59
                 + *((_DWORD *)v59 + 1) * (*((_DWORD *)v59 + v53 + 13) + v41)
                 + *((_DWORD *)v59 + v53 + 5)
                 + v42) = 105;
        v43 = 1;
      }
      if ( ++v53 == 8 )
        v53 = 0;
    }
  }
  return result;
}


// address=[0x2fc7a70]
// Decompiled from char __thiscall CFeatureGrid::findNearestElement(CFeatureGrid *this, int *a2, int *a3, int a4, bool a5)
bool  CFeatureGrid::findNearestElement(int &,int &,int,bool) {
  
  int v5; // esi
  int v6; // esi
  int v8; // [esp+Ch] [ebp-444h]
  int v9; // [esp+10h] [ebp-440h] BYREF
  int v10; // [esp+14h] [ebp-43Ch] BYREF
  void *v11; // [esp+18h] [ebp-438h]
  int v12; // [esp+1Ch] [ebp-434h]
  int v13; // [esp+20h] [ebp-430h]
  size_t Size; // [esp+24h] [ebp-42Ch]
  int v15; // [esp+28h] [ebp-428h]
  int v16; // [esp+2Ch] [ebp-424h]
  int i; // [esp+30h] [ebp-420h]
  void *v18; // [esp+34h] [ebp-41Ch]
  CFeatureGrid *v19; // [esp+38h] [ebp-418h]
  int v20; // [esp+3Ch] [ebp-414h]
  int v21; // [esp+40h] [ebp-410h]
  _BYTE v22[1032]; // [esp+44h] [ebp-40Ch] BYREF

  v19 = this;
  v21 = *a2;
  v20 = *a3;
  v16 = 1024;
  v15 = 1024;
  Size = *((_DWORD *)this + 1) * *((_DWORD *)this + 1);
  v11 = operator new[](Size);
  v18 = v11;
  memset(v11, 0, Size);
  TStaticFIFO<int,256>::TStaticFIFO<int,256>(v22);
  v10 = v21 + *((_DWORD *)v19 + 1) * v20;
  TStaticFIFO<int,256>::Push(&v10);
  *((_BYTE *)v18 + v21 + *((_DWORD *)v19 + 1) * v20) = 1;
  while ( !(unsigned __int8)TStaticFIFO<int,256>::Empty(v22) )
  {
    v13 = *(_DWORD *)TStaticFIFO<int,256>::Top(v22);
    TStaticFIFO<int,256>::Pop(v22);
    for ( i = 0; i < 8; ++i )
    {
      v21 = v13 % *((_DWORD *)v19 + 1);
      v20 = v13 / *((_DWORD *)v19 + 1);
      v12 = i;
      switch ( i )
      {
        case 0:
          if ( v21 - 1 >= 0 && v20 - 1 >= 0 )
          {
            --v21;
            --v20;
          }
          break;
        case 1:
          if ( v20 - 1 >= 0 )
            --v20;
          break;
        case 2:
          if ( v21 + 1 < *((_DWORD *)v19 + 1) && v20 - 1 >= 0 )
          {
            ++v21;
            --v20;
          }
          break;
        case 3:
          if ( v21 - 1 >= 0 )
            --v21;
          break;
        case 4:
          if ( v21 + 1 < *((_DWORD *)v19 + 1) )
            ++v21;
          break;
        case 5:
          if ( v20 + 1 < *((_DWORD *)v19 + 1) )
            ++v20;
          break;
        case 6:
          if ( v21 + 1 < *((_DWORD *)v19 + 1) && v20 + 1 < *((_DWORD *)v19 + 1) )
          {
            ++v21;
            ++v20;
          }
          break;
        case 7:
          if ( v21 - 1 >= 0 && v20 + 1 < *((_DWORD *)v19 + 1) )
          {
            --v21;
            ++v20;
          }
          break;
        default:
          break;
      }
      if ( !*((_BYTE *)v18 + v21 + *((_DWORD *)v19 + 1) * v20) )
      {
        if ( v21 >= *((_DWORD *)v19 + 1) && BBSupportDbgReport(2, "FeatureGrid.cpp", 499, "iCurrentX < m_iSize") == 1 )
          __debugbreak();
        if ( v21 < 0 && BBSupportDbgReport(2, "FeatureGrid.cpp", 500, "iCurrentX >= 0") == 1 )
          __debugbreak();
        if ( v20 >= *((_DWORD *)v19 + 1) && BBSupportDbgReport(2, "FeatureGrid.cpp", 501, "iCurrentY < m_iSize") == 1 )
          __debugbreak();
        if ( v20 < 0 && BBSupportDbgReport(2, "FeatureGrid.cpp", 502, "iCurrentY >= 0") == 1 )
          __debugbreak();
        *((_BYTE *)v18 + v21 + *((_DWORD *)v19 + 1) * v20) = 1;
        if ( !a5 || *(_BYTE *)(*(_DWORD *)v19 + v21 + *((_DWORD *)v19 + 1) * v20) )
        {
          v9 = v21 + *((_DWORD *)v19 + 1) * v20;
          TStaticFIFO<int,256>::Push(&v9);
          if ( *(unsigned __int8 *)(*(_DWORD *)v19 + v21 + *((_DWORD *)v19 + 1) * v20) == a4 )
          {
            v5 = j__abs(v21 - *a2);
            v8 = j__abs(v20 - *a3) + v5;
            v6 = j__abs(v16 - *a2);
            if ( v8 < j__abs(v15 - *a3) + v6 )
            {
              v16 = v21;
              v15 = v20;
            }
          }
        }
      }
    }
  }
  operator delete[](v18);
  if ( v16 == 1024 && v15 == 1024 )
    return 0;
  *a2 = v16;
  *a3 = v15;
  return 1;
}


