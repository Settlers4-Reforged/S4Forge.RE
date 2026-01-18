#include "LZHLEncoder.h"

// Definitions for class LZHLEncoder

// address=[0x2f02870]
// Decompiled from unsigned int __cdecl LZHLEncoder::calcMaxBuf(unsigned int a1)
unsigned int __cdecl LZHLEncoder::calcMaxBuf(unsigned int a1) {
  
  return a1 + (a1 >> 1) + 32;
}


// address=[0x2f2a390]
// Decompiled from LZHLEncoder *__thiscall LZHLEncoder::LZHLEncoder(LZHLEncoder *this, struct LZHLEncoderStat *a2, unsigned __int8 *a3)
 LZHLEncoder::LZHLEncoder(class LZHLEncoderStat * a2, unsigned char * a3) {
  
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = *(_DWORD *)a2;
  *((_DWORD *)this + 2) = (char *)a2 + 4;
  *((_DWORD *)this + 4) = a3;
  *((_DWORD *)this + 3) = a3;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  return this;
}


// address=[0x2f2a430]
// Decompiled from void __thiscall LZHLEncoder::~LZHLEncoder(LZHLEncoder *this)
 LZHLEncoder::~LZHLEncoder(void) {
  
  ;
}


// address=[0x2f2b0d0]
// Decompiled from int __thiscall LZHLEncoder::flush(LZHLEncoder *this)
unsigned int  LZHLEncoder::flush(void) {
  
  LZHLEncoder::_put(this, 0x111u);
  while ( *((int *)this + 6) > 0 )
  {
    *(_BYTE *)(*((_DWORD *)this + 3))++ = HIBYTE(*((_DWORD *)this + 5));
    *((_DWORD *)this + 6) -= 8;
    *((_DWORD *)this + 5) <<= 8;
  }
  return *((_DWORD *)this + 3) - *((_DWORD *)this + 4);
}


// address=[0x2f2b140]
// Decompiled from const unsigned __int8 *__thiscall LZHLEncoder::putRaw(LZHLEncoder *this, const unsigned __int8 *a2, unsigned int a3)
void  LZHLEncoder::putRaw(unsigned char const * a2, unsigned int a3) {
  
  const unsigned __int8 *result; // eax
  const unsigned __int8 *v5; // [esp+4h] [ebp-4h]

  result = &a2[a3];
  v5 = &a2[a3];
  while ( a2 < v5 )
    LZHLEncoder::_put(this, *a2++);
  return result;
}


// address=[0x2f2b180]
// Decompiled from void __thiscall LZHLEncoder::putMatch(  LZHLEncoder *this,  const unsigned __int8 *a2,  unsigned int a3,  unsigned int a4,  unsigned int a5)
void  LZHLEncoder::putMatch(unsigned char const * a2, unsigned int a3, unsigned int a4, unsigned int a5) {
  
  unsigned int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+10h] [ebp-8h]
  unsigned int v8; // [esp+28h] [ebp+10h]

  if ( a3 > 0x40 && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 266, "nRaw <= maxRaw") == 1 )
    __debugbreak();
  if ( a4 > 0x205 && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 267, "matchOver <= maxMatchOver") == 1 )
    __debugbreak();
  if ( a5 >= 0x10000
    && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 268, "disp >= 0 && disp < LZBUFSIZE") == 1 )
  {
    __debugbreak();
  }
  LZHLEncoder::putRaw(this, a2, a3);
  if ( a4 >= 8 )
  {
    if ( a4 >= 0x26 )
    {
      v8 = a4 - 38;
      LZHLEncoder::_put(this, *((_DWORD *)&unk_3E2DBE0 + 3 * (v8 >> 5)) + 4);
      LZHLEncoder::_putBits(
        this,
        *((_DWORD *)&unk_3E2DBE0 + 3 * (v8 >> 5) + 1) + 4,
        v8 & 0x1F | (16 * *((unsigned __int16 *)&unk_3E2DBE0 + 6 * (v8 >> 5) + 4)));
    }
    else
    {
      LZHLEncoder::_put(
        this,
        *((_WORD *)&unk_3E2DBE0 + 6 * ((a4 - 8) >> 1)),
        *((_DWORD *)&unk_3E2DBE0 + 3 * ((a4 - 8) >> 1) + 1),
        ((_BYTE)a4 - 8) & 1 | *((unsigned __int16 *)&unk_3E2DBE0 + 6 * ((a4 - 8) >> 1) + 4));
    }
  }
  else
  {
    LZHLEncoder::_put(this, a4 + 256);
  }
  v6 = *((_DWORD *)&unk_3E2DCB8 + 2 * (a5 >> 9)) + 9;
  v5 = a5 & 0x1FF | (*((unsigned __int16 *)&unk_3E2DCB8 + 4 * (a5 >> 9) + 2) << 9);
  if ( v6 <= 16 )
  {
    LZHLEncoder::_putBits(this, v6, v5);
  }
  else
  {
    if ( v6 > 32 && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 325, "nBits <= 32") == 1 )
      __debugbreak();
    LZHLEncoder::_putBits(this, v6 - 16, HIWORD(v5));
    LZHLEncoder::_putBits(this, 16, (unsigned __int16)v5);
  }
}


// address=[0x2f2b3a0]
// Decompiled from void __thiscall LZHLEncoder::_callStat(LZHLEncoder *this)
void  LZHLEncoder::_callStat(void) {
  
  int v1; // [esp+0h] [ebp-58h]
  int v2; // [esp+4h] [ebp-54h]
  int v4; // [esp+Ch] [ebp-4Ch]
  int i; // [esp+10h] [ebp-48h]
  int v6[16]; // [esp+14h] [ebp-44h] BYREF

  **((_DWORD **)this + 2) = 2;
  LZHLEncoder::_put(this, 0x110u);
  LZHLEncoderStat::calcStat(*(LZHLEncoderStat **)this, v6);
  v2 = 0;
  for ( i = 0; i < 16; ++i )
  {
    v4 = v6[i];
    if ( (v4 < v2 || v4 > 8)
      && BBSupportDbgReport(2, "Source\\compression\\huff.cpp", 251, "nBits >= lastNBits && nBits <= 8") == 1 )
    {
      __debugbreak();
    }
    v1 = v4 - v2;
    v2 = v4;
    LZHLEncoder::_putBits(this, v1 + 1, 1u);
  }
}


// address=[0x2f2c620]
// Decompiled from void __thiscall LZHLEncoder::_put(LZHLEncoder *this, unsigned __int16 a2)
void  LZHLEncoder::_put(unsigned short a2) {
  
  int v2; // ecx
  __int16 *v3; // [esp+4h] [ebp-8h]

  if ( a2 >= 0x112u
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\source\\compression\\_huff.h",
         159,
         "symbol < NHUFFSYMBOLS") == 1 )
  {
    __debugbreak();
  }
  v2 = **((_DWORD **)this + 2) - 1;
  **((_DWORD **)this + 2) = v2;
  if ( v2 <= 0 )
    LZHLEncoder::_callStat(this);
  ++*(_WORD *)(*((_DWORD *)this + 1) + 2 * a2);
  v3 = (__int16 *)(*(_DWORD *)(*(_DWORD *)this + 8) + 4 * a2);
  if ( *v3 < 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\source\\compression\\_huff.h",
         166,
         "item->nBits >= 0") == 1 )
  {
    __debugbreak();
  }
  LZHLEncoder::_putBits(this, *v3, (unsigned __int16)v3[1]);
}


// address=[0x2f2c730]
// Decompiled from void __thiscall LZHLEncoder::_put(LZHLEncoder *this, unsigned __int16 a2, int a3, unsigned int a4)
void  LZHLEncoder::_put(unsigned short a2, int a3, unsigned long a4) {
  
  int v4; // edx
  __int16 *v5; // [esp+8h] [ebp-8h]

  if ( a2 >= 0x112u
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\source\\compression\\_huff.h",
         173,
         "symbol < NHUFFSYMBOLS") == 1 )
  {
    __debugbreak();
  }
  if ( a3 > 4
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\source\\compression\\_huff.h",
         174,
         "codeBits <= 4") == 1 )
  {
    __debugbreak();
  }
  v4 = **((_DWORD **)this + 2) - 1;
  **((_DWORD **)this + 2) = v4;
  if ( v4 <= 0 )
    LZHLEncoder::_callStat(this);
  ++*(_WORD *)(*((_DWORD *)this + 1) + 2 * a2);
  v5 = (__int16 *)(*(_DWORD *)(*(_DWORD *)this + 8) + 4 * a2);
  if ( *v5 < 0
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\source\\compression\\_huff.h",
         181,
         "item->nBits >= 0") == 1 )
  {
    __debugbreak();
  }
  LZHLEncoder::_putBits(this, a3 + *v5, a4 | ((unsigned __int16)v5[1] << a3));
}


// address=[0x2f2c880]
// Decompiled from LZHLEncoder *__thiscall LZHLEncoder::_putBits(LZHLEncoder *this, int a2, unsigned int a3)
void  LZHLEncoder::_putBits(int a2, unsigned long a3) {
  
  LZHLEncoder *result; // eax

  if ( a2 > 16
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\baselib\\source\\compression\\_huff.h",
         145,
         "codeBits <= 16") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 5) |= a3 << (32 - *((_BYTE *)this + 24) - a2);
  *((_DWORD *)this + 6) += a2;
  result = this;
  if ( *((int *)this + 6) < 16 )
    return result;
  *(_BYTE *)(*((_DWORD *)this + 3))++ = HIBYTE(*((_DWORD *)this + 5));
  *(_BYTE *)(*((_DWORD *)this + 3))++ = BYTE2(*((_DWORD *)this + 5));
  *((_DWORD *)this + 6) -= 16;
  result = this;
  *((_DWORD *)this + 5) <<= 16;
  return result;
}


