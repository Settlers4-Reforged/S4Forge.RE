#include "LZHLCompressor.h"

// Definitions for class LZHLCompressor

// address=[0x2f02850]
// Decompiled from unsigned int __cdecl LZHLCompressor::calcMaxBuf(unsigned int a1)
static unsigned int __cdecl LZHLCompressor::calcMaxBuf(unsigned int) {
  
  return LZHLEncoder::calcMaxBuf(a1);
}


// address=[0x2f29650]
// Decompiled from LZHLCompressor *__thiscall LZHLCompressor::LZHLCompressor(LZHLCompressor *this)
 LZHLCompressor::LZHLCompressor(void) {
  
  int i; // [esp+Ch] [ebp-14h]

  LZBuffer::LZBuffer(this);
  LZHLEncoderStat::LZHLEncoderStat((LZHLCompressor *)((char *)this + 8));
  *((_DWORD *)this + 5) = operator new[](0x10000u);
  for ( i = 0; i < 0x8000; ++i )
    *(_WORD *)(*((_DWORD *)this + 5) + 2 * i) = -1;
  return this;
}


// address=[0x2f29710]
// Decompiled from void __thiscall LZHLCompressor::~LZHLCompressor(void **this)
 LZHLCompressor::~LZHLCompressor(void) {
  
  operator delete[](this[5]);
  LZHLEncoderStat::~LZHLEncoderStat((LZHLEncoderStat *)(this + 2));
  LZBuffer::~LZBuffer((LZBuffer *)this);
}


// address=[0x2f29750]
// Decompiled from unsigned int __thiscall LZHLCompressor::compress(int this, unsigned __int8 *a2, unsigned __int8 *Src, unsigned int a4)
unsigned int  LZHLCompressor::compress(unsigned char *,unsigned char const *,unsigned int) {
  
  signed int v4; // eax
  signed int v5; // eax
  int v6; // eax
  int v7; // eax
  signed int v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // eax
  _BYTE v14[28]; // [esp+Ch] [ebp-C4h] BYREF
  unsigned int v15; // [esp+28h] [ebp-A8h]
  signed int v16; // [esp+2Ch] [ebp-A4h]
  unsigned int v17; // [esp+30h] [ebp-A0h]
  int v18; // [esp+34h] [ebp-9Ch]
  signed int v19; // [esp+38h] [ebp-98h]
  signed int v20; // [esp+3Ch] [ebp-94h]
  int v21; // [esp+40h] [ebp-90h]
  unsigned __int8 *v22; // [esp+44h] [ebp-8Ch]
  size_t v23; // [esp+48h] [ebp-88h]
  int v24; // [esp+4Ch] [ebp-84h]
  size_t v25; // [esp+50h] [ebp-80h]
  size_t v26; // [esp+54h] [ebp-7Ch]
  size_t v27; // [esp+58h] [ebp-78h]
  size_t v28; // [esp+5Ch] [ebp-74h]
  size_t v29; // [esp+60h] [ebp-70h]
  signed int v30; // [esp+64h] [ebp-6Ch]
  unsigned int v31; // [esp+68h] [ebp-68h]
  size_t v32; // [esp+6Ch] [ebp-64h]
  int v33; // [esp+70h] [ebp-60h]
  int v34; // [esp+74h] [ebp-5Ch]
  int v35; // [esp+78h] [ebp-58h]
  unsigned int v36; // [esp+7Ch] [ebp-54h]
  size_t v37; // [esp+80h] [ebp-50h]
  int v38; // [esp+84h] [ebp-4Ch]
  unsigned __int8 *v39; // [esp+88h] [ebp-48h]
  signed int v40; // [esp+8Ch] [ebp-44h]
  int v41; // [esp+90h] [ebp-40h]
  signed int i; // [esp+94h] [ebp-3Ch]
  unsigned __int8 v43; // [esp+9Bh] [ebp-35h]
  unsigned __int8 *v44; // [esp+9Ch] [ebp-34h]
  int v45; // [esp+A0h] [ebp-30h]
  int j; // [esp+A4h] [ebp-2Ch]
  size_t v47; // [esp+A8h] [ebp-28h]
  int v48; // [esp+ACh] [ebp-24h]
  size_t v49; // [esp+B0h] [ebp-20h]
  unsigned int updated; // [esp+B4h] [ebp-1Ch]
  LZHLCompressor *v51; // [esp+B8h] [ebp-18h]
  size_t v52; // [esp+BCh] [ebp-14h]
  signed int v53; // [esp+C0h] [ebp-10h]
  int v54; // [esp+CCh] [ebp-4h]

  v51 = (LZHLCompressor *)this;
  LZHLEncoder::LZHLEncoder((LZHLEncoder *)v14, (struct LZHLEncoderStat *)(this + 8), a2);
  v54 = 0;
  v44 = &Src[a4];
  updated = 0;
  if ( a4 >= 5 )
  {
    v22 = Src + 5;
    v39 = Src;
    while ( v39 < v22 )
    {
      updated ^= *v39++;
      updated = __ROL4__(updated, 5);
    }
  }
LABEL_5:
  while ( 1 )
  {
    v49 = v44 - Src;
    if ( v44 - Src < 5 )
      break;
    v53 = 0;
    if ( (int)(v49 - 5) >= 64 )
      v37 = 64;
    else
      v37 = v49 - 5;
    v16 = v37;
    v47 = 0;
    v38 = 0;
    while ( 1 )
    {
      v36 = (214013 * updated + 2531011) >> 17;
      v48 = *(unsigned __int16 *)(*((_DWORD *)v51 + 5) + 2 * v36);
      v45 = LZBuffer::_wrap(*((_DWORD *)v51 + 1));
      *(_WORD *)(*((_DWORD *)v51 + 5) + 2 * v36) = v45;
      v52 = 0;
      if ( v48 != 0xFFFF && v48 != v45 )
      {
        v4 = LZBuffer::_distance(v45 - v48);
        if ( v4 >= (int)(v49 - v53) )
          v35 = v49 - v53;
        else
          v35 = LZBuffer::_distance(v45 - v48);
        if ( v35 >= 521 )
        {
          v33 = 521;
        }
        else
        {
          v5 = LZBuffer::_distance(v45 - v48);
          if ( v5 >= (int)(v49 - v53) )
            v34 = v49 - v53;
          else
            v34 = LZBuffer::_distance(v45 - v48);
          v33 = v34;
        }
        v21 = v33;
        v52 = LZBuffer::_nMatch(v51, v48, &Src[v53], v33);
        v6 = LZBuffer::_wrap(v52 + v48);
        if ( v6 == v45 )
        {
          if ( !v52 && BBSupportDbgReport(2, "Source\\compression\\lz.cpp", 194, "matchLen != 0") == 1 )
            __debugbreak();
          if ( (int)(521 - v52) >= (int)(v49 - v53 - v52) )
            v32 = v49 - v53 - v52;
          else
            v32 = 521 - v52;
          v20 = v32;
          for ( i = 0; i < v20 && Src[i + v53] == Src[v52 + i + v53]; ++i )
            ;
          v52 += i;
        }
        if ( (int)v52 >= 3 )
        {
          v31 = (int)(521 - v52) >= v53 ? v53 : 521 - v52;
          v40 = v31;
          v41 = LZBuffer::_distance(*((_DWORD *)v51 + 1) - v48);
          v30 = v40 >= (int)(v41 - v52) ? v41 - v52 : v40;
          if ( v30 >= 0x10000 - v41 )
          {
            v28 = 0x10000 - v41;
          }
          else
          {
            v29 = v40 >= (int)(v41 - v52) ? v41 - v52 : v40;
            v28 = v29;
          }
          v40 = v28;
          for ( j = 0; j < v40; ++j )
          {
            v7 = LZBuffer::_wrap(v48 - j - 1);
            if ( *(unsigned __int8 *)(*(_DWORD *)v51 + v7) != Src[v53 - j - 1] )
              break;
          }
          if ( j > 0 )
          {
            if ( (int)(j + v52) < 4
              && BBSupportDbgReport(2, "Source\\compression\\lz.cpp", 221, "matchLen + xtraMatch >= LZMIN") == 1 )
            {
              __debugbreak();
            }
            v8 = j + v52;
            if ( v8 > LZBuffer::_distance(*((_DWORD *)v51 + 1) - v48)
              && BBSupportDbgReport(
                   2,
                   "Source\\compression\\lz.cpp",
                   222,
                   "matchLen + xtraMatch <= _distance(bufPos - hashPos)") == 1 )
            {
              __debugbreak();
            }
            v53 -= j;
            *((_DWORD *)v51 + 1) -= j;
            v48 -= j;
            v52 += j;
            v45 = LZBuffer::_wrap(*((_DWORD *)v51 + 1));
            updated = _calcHash(&Src[v53]);
            v38 = 1;
          }
        }
      }
      if ( (int)v47 >= 4 )
      {
        if ( (int)v52 <= (int)v47 )
        {
          v53 = v19;
          *((_DWORD *)v51 + 1) = v18;
          updated = v17;
          updated = v17 ^ __ROL4__(Src[v53], 25);
          updated ^= Src[v53 + 5];
          updated = __ROL4__(updated, 5);
          v10 = LZBuffer::_distance(*((_DWORD *)v51 + 1) - v24);
          LZHLEncoder::putMatch((LZHLEncoder *)v14, Src, v53, v47 - 4, v10);
          if ( (int)(v47 - 2) >= v44 - &Src[v53 + 2] )
            v26 = v44 - &Src[v53 + 2];
          else
            v26 = v47 - 2;
          updated = LZHLCompressor::_updateTable(v51, updated, &Src[v53 + 1], *((_DWORD *)v51 + 1) + 2, v26);
          LZBuffer::_toBuf(&Src[v53], v47);
          Src += v47 + v53;
        }
        else
        {
          v9 = LZBuffer::_distance(v45 - v48);
          LZHLEncoder::putMatch((LZHLEncoder *)v14, Src, v53, v52 - 4, v9);
          if ( (int)(v52 - 1) >= v44 - &Src[v53 + 1] )
            v27 = v44 - &Src[v53 + 1];
          else
            v27 = v52 - 1;
          updated = LZHLCompressor::_updateTable(v51, updated, &Src[v53], *((_DWORD *)v51 + 1) + 1, v27);
          LZBuffer::_toBuf(&Src[v53], v52);
          Src += v52 + v53;
        }
        goto LABEL_5;
      }
      if ( (int)v52 >= 4 )
      {
        if ( v38 )
        {
          v11 = LZBuffer::_distance(v45 - v48);
          LZHLEncoder::putMatch((LZHLEncoder *)v14, Src, v53, v52 - 4, v11);
          if ( (int)(v52 - 1) >= v44 - &Src[v53 + 1] )
            v25 = v44 - &Src[v53 + 1];
          else
            v25 = v52 - 1;
          updated = LZHLCompressor::_updateTable(v51, updated, &Src[v53], *((_DWORD *)v51 + 1) + 1, v25);
          LZBuffer::_toBuf(&Src[v53], v52);
          Src += v52 + v53;
          goto LABEL_5;
        }
        v47 = v52;
        v24 = v48;
        v19 = v53;
        v18 = *((_DWORD *)v51 + 1);
        v17 = updated;
      }
      if ( v38 && BBSupportDbgReport(2, "Source\\compression\\lz.cpp", 290, "!lazyForceMatch") == 1 )
        __debugbreak();
      if ( v53 + 1 > v16 )
        break;
      updated ^= __ROL4__(Src[v53], 25);
      updated ^= Src[v53 + 5];
      updated = __ROL4__(updated, 5);
      v43 = Src[v53];
      LZBuffer::_toBuf(v51, v43);
      ++v53;
    }
    if ( (int)v47 < 4 )
    {
      if ( v53 + 5 >= (int)v49 && (int)v49 <= 64 )
      {
        LZBuffer::_toBuf(&Src[v53], v49 - v53);
        v53 = v49;
      }
      LZHLEncoder::putRaw((LZHLEncoder *)v14, Src, v53);
      Src += v53;
    }
    else
    {
      v12 = LZBuffer::_distance(*((_DWORD *)v51 + 1) - v24);
      LZHLEncoder::putMatch((LZHLEncoder *)v14, Src, v53, v47 - 4, v12);
      if ( (int)(v47 - 1) >= v44 - &Src[v53 + 1] )
        v23 = v44 - &Src[v53 + 1];
      else
        v23 = v47 - 1;
      updated = LZHLCompressor::_updateTable(v51, updated, &Src[v53], *((_DWORD *)v51 + 1) + 1, v23);
      LZBuffer::_toBuf(&Src[v53], v47);
      Src += v47 + v53;
    }
  }
  if ( v49 )
  {
    LZBuffer::_toBuf(Src, v49);
    LZHLEncoder::putRaw((LZHLEncoder *)v14, Src, v49);
  }
  v15 = LZHLEncoder::flush((LZHLEncoder *)v14);
  v54 = -1;
  LZHLEncoder::~LZHLEncoder((LZHLEncoder *)v14);
  return v15;
}


// address=[0x2f2a790]
// Decompiled from int __thiscall LZHLCompressor::_updateTable(  LZHLCompressor *this,  unsigned int a2,  const unsigned __int8 *a3,  unsigned int a4,  int a5)
unsigned long  LZHLCompressor::_updateTable(unsigned long,unsigned char const *,unsigned long,int) {
  
  const unsigned __int8 *j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]
  int v9; // [esp+18h] [ebp+8h]
  int v10; // [esp+18h] [ebp+8h]
  int v11; // [esp+18h] [ebp+8h]
  const unsigned __int8 *v12; // [esp+1Ch] [ebp+Ch]

  if ( a5 <= 0 )
    return 0;
  if ( a5 <= 1024 )
  {
    v11 = __ROL4__(a2 ^ __ROL4__(*a3, 25) ^ a3[5], 5);
    v12 = a3 + 1;
    for ( i = 0; i < a5; ++i )
    {
      *(_WORD *)(*((_DWORD *)this + 5) + 2 * ((unsigned int)(214013 * v11 + 2531011) >> 17)) = LZBuffer::_wrap(i + a4);
      v11 = __ROL4__(v11 ^ __ROL4__(v12[i], 25) ^ v12[i + 5], 5);
    }
    return v11;
  }
  else
  {
    v9 = 0;
    for ( j = &a3[a5 + 1]; j < &a3[a5 + 6]; ++j )
    {
      v10 = v9 ^ *j;
      v9 = __ROL4__(v10, 5);
    }
    return v9;
  }
}


