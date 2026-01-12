#include "LZHLDecompressor.h"

// Definitions for class LZHLDecompressor

// address=[0x2f2b540]
// Decompiled from LZHLDecompressor *__thiscall LZHLDecompressor::LZHLDecompressor(LZHLDecompressor *this)
 LZHLDecompressor::LZHLDecompressor(void) {
  
  LZBuffer::LZBuffer(this);
  LZHLDecoderStat::LZHLDecoderStat((LZHLDecompressor *)((char *)this + 8));
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 36) = 0;
  return this;
}


// address=[0x2f2b5c0]
// Decompiled from void __thiscall LZHLDecompressor::~LZHLDecompressor(void **this)
 LZHLDecompressor::~LZHLDecompressor(void) {
  
  LZHLDecoderStat::~LZHLDecoderStat(this + 2);
  LZBuffer::~LZBuffer((LZBuffer *)this);
}


// address=[0x2f2b5e0]
// Decompiled from int __thiscall LZHLDecompressor::decompress(_DWORD *this, char *Src, _DWORD *a3, unsigned int a4, _DWORD *a5)
int  LZHLDecompressor::decompress(unsigned char *,unsigned int *,unsigned char const *,unsigned int *) {
  
  int v6; // [esp+4h] [ebp-4B0h]
  char *v7; // [esp+8h] [ebp-4ACh]
  int v8; // [esp+Ch] [ebp-4A8h]
  char *v9; // [esp+10h] [ebp-4A4h]
  int v10; // [esp+14h] [ebp-4A0h]
  int v11; // [esp+1Ch] [ebp-498h]
  int v12; // [esp+20h] [ebp-494h]
  int v13; // [esp+24h] [ebp-490h]
  int v14; // [esp+2Ch] [ebp-488h]
  int v15; // [esp+30h] [ebp-484h]
  int v16; // [esp+34h] [ebp-480h]
  int v17; // [esp+38h] [ebp-47Ch]
  int v18; // [esp+40h] [ebp-474h]
  int v19; // [esp+44h] [ebp-470h]
  int k; // [esp+48h] [ebp-46Ch]
  signed int v21; // [esp+4Ch] [ebp-468h]
  unsigned int v22; // [esp+50h] [ebp-464h]
  int v23; // [esp+54h] [ebp-460h]
  int v24; // [esp+54h] [ebp-460h]
  int i; // [esp+58h] [ebp-45Ch]
  int j; // [esp+58h] [ebp-45Ch]
  int v27; // [esp+5Ch] [ebp-458h]
  size_t v28; // [esp+60h] [ebp-454h]
  int v29; // [esp+60h] [ebp-454h]
  _WORD v31[548]; // [esp+68h] [ebp-44Ch] BYREF

  v7 = Src;
  v6 = a4;
  v22 = *a5 + a4;
  v9 = &Src[*a3];
  this[37] = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v16 = LZHLDecompressor::_get(this, &a4, v22, 4);
        if ( v16 < 0 )
          return 0;
        v23 = this[2 * v16 + 3];
        if ( v23 )
        {
          if ( v23 > 8 && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 430, "nBits <= 8") == 1 )
            __debugbreak();
          v15 = LZHLDecompressor::_get(this, &a4, v22, v23);
          if ( v15 < 0 )
            return 0;
          v14 = v15 + this[2 * v16 + 4];
          if ( v14 >= 274 )
            return 0;
          v27 = *(__int16 *)(this[35] + 2 * v14);
        }
        else
        {
          v27 = *(__int16 *)(this[35] + 2 * this[2 * v16 + 4]);
        }
        if ( v27 >= 274 && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 440, "symbol < NHUFFSYMBOLS") == 1 )
          __debugbreak();
        ++*(_WORD *)(this[2] + 2 * v27);
        if ( v27 >= 256 )
          break;
        if ( Src >= v9 )
          return 0;
        *Src++ = v27;
        LZBuffer::_toBuf((LZBuffer *)this, v27);
      }
      if ( v27 != 272 )
        break;
      HuffStat::makeSortedTmp((HuffStat *)(this + 2), (struct HuffStatTmpStruct *)v31);
      for ( i = 0; i < 274; ++i )
        *(_WORD *)(this[35] + 2 * i) = v31[2 * i];
      v19 = 0;
      v18 = 0;
      for ( j = 0; j < 16; ++j )
      {
        v17 = 0;
        while ( !LZHLDecompressor::_get(this, &a4, v22, 1) )
          ++v17;
        v19 += v17;
        this[2 * j + 3] = v19;
        this[2 * j + 4] = v18;
        v18 += 1 << v19;
      }
      if ( v18 >= 529 && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 475, "pos < NHUFFSYMBOLS + 255") == 1 )
        __debugbreak();
    }
    if ( v27 == 273 )
      break;
    if ( v27 >= 264 )
    {
      v13 = LZHLDecompressor::_get(this, &a4, v22, aGhijklmnopqrst[2 * v27]);
      if ( v13 < 0 )
        return 0;
      v10 = v13 + aGhijklmnopqrst[2 * v27 + 1];
    }
    else
    {
      v10 = v27 - 256;
    }
    v12 = LZHLDecompressor::_get(this, &a4, v22, 3);
    if ( v12 < 0 )
      return 0;
    v24 = dword_3E2E1D8[2 * v12] + 9;
    v28 = 0;
    if ( v24 > 16 && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 523, "nBits <= 16") == 1 )
      __debugbreak();
    if ( v24 > 8 )
    {
      v24 -= 8;
      v28 = LZHLDecompressor::_get(this, &a4, v22, 8) << v24;
    }
    if ( v24 > 8 && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 529, "nBits <= 8") == 1 )
      __debugbreak();
    v11 = LZHLDecompressor::_get(this, &a4, v22, v24);
    if ( v11 < 0 )
      return 0;
    v29 = (v11 | v28) + (dword_3E2E1D8[2 * v12 + 1] << 9);
    if ( (unsigned int)v29 >= 0x10000
      && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 536, "disp >= 0 && disp < LZBUFSIZE") == 1 )
    {
      __debugbreak();
    }
    v21 = v10 + 4;
    if ( &Src[v10 + 4] > v9 )
      return 0;
    v8 = this[1] - v29;
    if ( v21 >= v29 )
    {
      LZBuffer::_bufCpy(Src, v8, v29);
      for ( k = 0; k < v21 - v29; ++k )
        Src[v29 + k] = Src[k];
    }
    else
    {
      LZBuffer::_bufCpy(Src, v8, v21);
    }
    LZBuffer::_toBuf(Src, v21);
    Src += v21;
  }
  if ( a3 )
    *a3 -= Src - v7;
  if ( a5 )
    *a5 -= a4 - v6;
  return 1;
}


// address=[0x2f2c4f0]
// Decompiled from int __thiscall sub_332C4F0(_DWORD *this, unsigned int *a2, unsigned int a3, int a4)
int  LZHLDecompressor::_get(unsigned char const * &,unsigned char const *,int) {
  
  int v5; // [esp+0h] [ebp-8h]

  if ( a4 > 8 && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 392, "n <= 8") == 1 )
    __debugbreak();
  if ( this[37] < a4 )
  {
    if ( *a2 >= a3 )
    {
      this[37] = 0;
      return -1;
    }
    this[36] |= *(unsigned __int8 *)(*a2)++ << (24 - *((_BYTE *)this + 148));
    this[37] += 8;
  }
  v5 = this[36] >> (32 - a4);
  this[36] <<= a4;
  this[37] -= a4;
  return v5;
}


