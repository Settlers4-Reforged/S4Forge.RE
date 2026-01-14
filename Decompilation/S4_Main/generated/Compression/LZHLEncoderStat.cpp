#include "all_headers.h"

// Definitions for class LZHLEncoderStat

// address=[0x2f2aa40]
// Decompiled from LZHLEncoderStat *__thiscall LZHLEncoderStat::LZHLEncoderStat(LZHLEncoderStat *this)
 LZHLEncoderStat::LZHLEncoderStat(void) {
  
  HuffStat::HuffStat(this);
  *((_DWORD *)this + 1) = 4096;
  *((_DWORD *)this + 2) = operator new[](0x448u);
  qmemcpy(*((void **)this + 2), &LZHLEncoderStat::symbolTable0, 0x448u);
  return this;
}


// address=[0x2f2aad0]
// Decompiled from int __thiscall LZHLEncoderStat::~LZHLEncoderStat(void **this)
 LZHLEncoderStat::~LZHLEncoderStat(void) {
  
  operator delete[](this[2]);
  return HuffStat::~HuffStat(this);
}


// address=[0x2f2ab00]
// Decompiled from void __thiscall LZHLEncoderStat::calcStat(LZHLEncoderStat *this, int *a2)
void  LZHLEncoderStat::calcStat(int *) {
  
  int v2; // esi
  int SortedTmp; // [esp+10h] [ebp-4BCh]
  int v4; // [esp+14h] [ebp-4B8h]
  int v5; // [esp+18h] [ebp-4B4h]
  int v6; // [esp+20h] [ebp-4ACh]
  int v7; // [esp+24h] [ebp-4A8h]
  int v8; // [esp+30h] [ebp-49Ch]
  int v9; // [esp+34h] [ebp-498h]
  int v10; // [esp+38h] [ebp-494h]
  int v11; // [esp+3Ch] [ebp-490h]
  int v12; // [esp+40h] [ebp-48Ch]
  int v13; // [esp+44h] [ebp-488h]
  int v15; // [esp+4Ch] [ebp-480h]
  int v16; // [esp+50h] [ebp-47Ch]
  int jj; // [esp+54h] [ebp-478h]
  int v18; // [esp+58h] [ebp-474h]
  int i; // [esp+5Ch] [ebp-470h]
  int v20; // [esp+60h] [ebp-46Ch]
  int n; // [esp+64h] [ebp-468h]
  int m; // [esp+68h] [ebp-464h]
  int v23; // [esp+6Ch] [ebp-460h]
  int v24; // [esp+70h] [ebp-45Ch]
  int j; // [esp+74h] [ebp-458h]
  int k; // [esp+78h] [ebp-454h]
  int ii; // [esp+78h] [ebp-454h]
  int v28; // [esp+7Ch] [ebp-450h]
  int v29; // [esp+7Ch] [ebp-450h]
  _WORD v30[548]; // [esp+80h] [ebp-44Ch] BYREF

  SortedTmp = HuffStat::makeSortedTmp(this, (struct HuffStatTmpStruct *)v30);
  *((_DWORD *)this + 1) = 4096;
  v28 = 0;
  v10 = 0;
  for ( i = 0; i < 14; ++i )
  {
    v11 = (SortedTmp - v10) / (16 - i);
    v20 = 0;
    v16 = 0;
    v24 = 0;
    for ( j = 0; ; ++j )
    {
      v8 = 0;
      v12 = 1 << j;
      if ( (1 << j) + v20 + v28 > 274 )
      {
        v12 = 274 - v28;
        v8 = 1;
      }
      while ( v20 < v12 )
        v24 += (__int16)v30[2 * v20++ + 1 + 2 * v28];
      if ( v8 || j >= 8 || v24 > v11 )
        break;
      v16 = v24;
    }
    if ( j && (v2 = j__abs(v16 - v11), v2 <= j__abs(v24 - v11)) )
      --j;
    else
      v16 = v24;
    LZHLEncoderStat::_addGroup(a2, i, j);
    v10 += v16;
    v28 += 1 << j;
  }
  v9 = 0;
  v6 = 0;
  v7 = 0x7FFFFFFF;
  v23 = 0;
  v18 = 0;
  v15 = 0;
  for ( k = v28; k < 274; ++k )
    v15 += (__int16)v30[2 * k + 1];
  for ( m = 0; (1 << m) + v23 + v28 <= 274; ++m )
  {
    while ( v23 < 1 << m )
      v18 += (__int16)v30[2 * v23++ + 1 + 2 * v28];
    for ( n = 0; 1 << n < 274 - (v23 + v28); ++n )
      ;
    if ( v15 < v18 && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 200, "left >= nn") == 1 )
      __debugbreak();
    if ( m <= 8 && n <= 8 )
    {
      if ( n * (v15 - v18) + m * v18 >= v7 )
        break;
      v7 = n * (v15 - v18) + m * v18;
      v9 = m;
      v6 = n;
    }
  }
  LZHLEncoderStat::_addGroup(a2, 14, v9);
  LZHLEncoderStat::_addGroup(a2, 15, v6);
  v29 = 0;
  for ( ii = 0; ii < 16; ++ii )
  {
    v13 = a2[ii];
    if ( 1 << v13 >= 274 - v29 )
      v5 = 274 - v29;
    else
      v5 = 1 << v13;
    for ( jj = 0; jj < v5; ++jj )
    {
      v4 = (__int16)v30[2 * jj + 2 * v29];
      *(_WORD *)(*((_DWORD *)this + 2) + 4 * v4) = v13 + 4;
      *(_WORD *)(*((_DWORD *)this + 2) + 4 * v4 + 2) = jj | ((_WORD)ii << v13);
    }
    v29 += 1 << v13;
  }
}


// address=[0x3e2d390]
// [Decompilation failed for static struct LZHLEncoderStat::Symbol * LZHLEncoderStat::symbolTable0]

// address=[0x2f2c360]
// Decompiled from int __cdecl LZHLEncoderStat::_addGroup(int *a1, int a2, int a3)
static void __cdecl LZHLEncoderStat::_addGroup(int *,int,int) {
  
  int result; // eax

  if ( a3 > 8 && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 126, "nBits <= 8") == 1 )
    __debugbreak();
  while ( a2 > 0 && a3 < a1[a2 - 1] )
  {
    a1[a2] = a1[a2 - 1];
    --a2;
  }
  result = a2;
  a1[a2] = a3;
  return result;
}


