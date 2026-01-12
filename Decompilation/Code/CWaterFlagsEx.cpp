#include "CWaterFlagsEx.h"

// Definitions for class CWaterFlagsEx

// address=[0x15fd780]
// Decompiled from int __cdecl CWaterFlagsEx::BlockRowPrimary(unsigned __int8 *a1, int a2)
static void __cdecl CWaterFlagsEx::BlockRowPrimary(unsigned char *,int) {
  
  int v2; // ecx
  int result; // eax
  unsigned __int8 v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v5 = CWorldManager::Width(v2) + 4;
  for ( i = a2 * v5; ; ++i )
  {
    result = i;
    if ( i > a2 * v5 + v5 - 1 )
      break;
    if ( (a1[i] & 1) != 0 )
      v4 = -59;
    else
      v4 = -62;
    a1[i] = v4;
  }
  return result;
}


// address=[0x15fd7f0]
// Decompiled from int __cdecl CWaterFlagsEx::BlockColPrimary(unsigned __int8 *a1, int a2)
static void __cdecl CWaterFlagsEx::BlockColPrimary(unsigned char *,int) {
  
  int v2; // ecx
  int result; // eax
  int v4; // [esp+8h] [ebp-Ch]
  unsigned __int8 v5; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v4 = CWorldManager::Width(v2) + 4;
  result = a2;
  for ( i = a2; i <= a2 + v4 * (v4 - 1); i += v4 )
  {
    if ( (a1[i] & 1) != 0 )
      v5 = -59;
    else
      v5 = -62;
    a1[i] = v5;
    result = v4 + i;
  }
  return result;
}


// address=[0x15fd870]
// Decompiled from int CWaterFlagsEx::CalcWaterFlags()
static void __cdecl CWaterFlagsEx::CalcWaterFlags(void) {
  
  int v0; // ecx
  int v1; // esi
  int v2; // eax
  const char *v3; // eax
  _BYTE v5[24]; // [esp+4h] [ebp-19Ch] BYREF
  void *C; // [esp+1Ch] [ebp-184h]
  int v7; // [esp+20h] [ebp-180h]
  int v8; // [esp+24h] [ebp-17Ch]
  int v9; // [esp+28h] [ebp-178h]
  int v10; // [esp+2Ch] [ebp-174h]
  int v11; // [esp+30h] [ebp-170h]
  int v12; // [esp+34h] [ebp-16Ch]
  int v13; // [esp+38h] [ebp-168h]
  int v14; // [esp+3Ch] [ebp-164h]
  unsigned __int8 *v15; // [esp+40h] [ebp-160h]
  int v16; // [esp+44h] [ebp-15Ch]
  int v17; // [esp+48h] [ebp-158h]
  int nn; // [esp+4Ch] [ebp-154h]
  int v19; // [esp+50h] [ebp-150h]
  int v20; // [esp+54h] [ebp-14Ch]
  int v21; // [esp+58h] [ebp-148h]
  int v22; // [esp+5Ch] [ebp-144h]
  int i1; // [esp+60h] [ebp-140h]
  int mm; // [esp+64h] [ebp-13Ch]
  int kk; // [esp+68h] [ebp-138h]
  int jj; // [esp+6Ch] [ebp-134h]
  int ii; // [esp+70h] [ebp-130h]
  int n; // [esp+74h] [ebp-12Ch]
  int v29; // [esp+78h] [ebp-128h]
  int m; // [esp+7Ch] [ebp-124h]
  int k; // [esp+80h] [ebp-120h]
  int v32; // [esp+84h] [ebp-11Ch]
  int v33; // [esp+88h] [ebp-118h]
  int i; // [esp+8Ch] [ebp-114h]
  int v35; // [esp+90h] [ebp-110h]
  int v36; // [esp+94h] [ebp-10Ch]
  int v37; // [esp+98h] [ebp-108h]
  int j; // [esp+9Ch] [ebp-104h]
  int v39; // [esp+A0h] [ebp-100h]
  unsigned __int8 *v40; // [esp+A4h] [ebp-FCh]
  _DWORD v41[61]; // [esp+A8h] [ebp-F8h]

  CPerformanceCounter::CPerformanceCounter((CPerformanceCounter *)v5);
  CPerformanceCounter::Start((CPerformanceCounter *)v5);
  v35 = CWorldManager::Width(v0);
  v39 = v35 + 4;
  for ( i = 0; i < 61; ++i )
  {
    v1 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * i]);
    v2 = SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * i]);
    v41[i] = v39 * v2 + v1;
  }
  v15 = (unsigned __int8 *)operator new[](v39 * v39);
  v40 = v15;
  memset(v15, 129, 2 * v39);
  memset(&v40[v39 * (v39 - 2)], 129, 2 * v39);
  v14 = v39 * v39 - 1;
  for ( j = 0; j <= v14; j += v39 )
  {
    v40[j] = -127;
    v40[j + 1] = -127;
    v40[v39 - 2 + j] = -127;
    v40[v39 - 1 + j] = -127;
  }
  v33 = 0;
  for ( k = 0; k < v35; ++k )
  {
    v12 = v39 * (k + 2) + 2;
    for ( m = 0; m < v35; ++m )
    {
      v13 = CWorldManager::Ground(v33);
      if ( CLandscapeProperties::IsWater(v13) )
      {
        v29 = 129;
        if ( CWorldManager::IsBlockedWater(v33) )
          v29 = 197;
      }
      else
      {
        v29 = 66;
        if ( (unsigned __int8)CWorldManager::IsBlockedLand(v33) )
          v29 = 194;
      }
      v40[m + v12] = v29;
      ++v33;
    }
  }
  for ( n = 0; n < v35; ++n )
  {
    v37 = v39 * (n + 2) + 2;
    v10 = v37 + v39 - 5;
    do
    {
      v17 = v40[v37];
      if ( (v17 & 0xE) == 0 )
      {
        for ( ii = 1; ii < 19; ++ii )
        {
          v11 = v41[ii] + v37;
          if ( (v40[v11] & 6) != 0 )
          {
            v40[v37] = v17 | 0x48;
            break;
          }
        }
      }
      ++v37;
    }
    while ( v37 <= v10 );
  }
  for ( jj = 0; jj < v35; ++jj )
  {
    v36 = v39 * (jj + 2) + 2;
    v8 = v36 + v39 - 5;
    do
    {
      v16 = v40[v36];
      if ( (v16 & 0xE) == 0 )
      {
        for ( kk = 1; kk < 19; ++kk )
        {
          v9 = v41[kk] + v36;
          if ( (v40[v9] & 0xE) != 0 )
          {
            v40[v36] = v16 | 0x50;
            break;
          }
        }
      }
      ++v36;
    }
    while ( v36 <= v8 );
  }
  CWaterFlagsEx::BlockRowPrimary(v40, 2);
  CWaterFlagsEx::BlockRowPrimary(v40, 3);
  CWaterFlagsEx::BlockRowPrimary(v40, v39 - 4);
  CWaterFlagsEx::BlockRowPrimary(v40, v39 - 3);
  CWaterFlagsEx::BlockColPrimary(v40, 2);
  CWaterFlagsEx::BlockColPrimary(v40, 3);
  CWaterFlagsEx::BlockColPrimary(v40, v39 - 4);
  CWaterFlagsEx::BlockColPrimary(v40, v39 - 3);
  v19 = 0;
  for ( mm = 0; mm < v35; ++mm )
  {
    v32 = v39 * (mm + 2) + 2;
    for ( nn = 0; nn < v35; ++nn )
    {
      if ( (v40[v32] & 1) != 0 )
      {
        v22 = 49408;
        v21 = v40[v32];
        if ( (v21 & 0x40) != 0 )
        {
          if ( (v21 & 4) != 0 )
          {
            v22 = 49920;
          }
          else if ( (v21 & 0x18) != 0 )
          {
            v20 = 255;
            for ( i1 = 1; i1 < 61; ++i1 )
            {
              v7 = v41[i1] + v32;
              v20 = (unsigned __int8)(v20 & v40[v7]);
            }
            if ( (v20 & 0xC0) == 0 )
              v22 = 50432;
          }
        }
        else
        {
          v22 = 49152;
        }
        CWaterFlags::SetWaterFlags(v19, v22);
      }
      ++v32;
      ++v19;
    }
  }
  C = v40;
  operator delete[](v40);
  CPerformanceCounter::Measure((CPerformanceCounter *)v5);
  v3 = CPerformanceCounter::TimeMsStr((CPerformanceCounter *)v5, 0, 3);
  return CTrace::Print("CWaterFlagsEx::CalcWaterFlags(): %s ms", v3);
}


