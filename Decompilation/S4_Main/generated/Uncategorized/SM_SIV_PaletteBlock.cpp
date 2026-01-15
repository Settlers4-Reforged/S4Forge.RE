#include "SM_SIV_PaletteBlock.h"

// Definitions for class SM_SIV_PaletteBlock

// address=[0x2fd2a20]
// Decompiled from SM_SIV_PaletteBlock *__thiscall SM_SIV_PaletteBlock::SM_SIV_PaletteBlock(SM_SIV_PaletteBlock *this, int a2, bool a3)
 SM_SIV_PaletteBlock::SM_SIV_PaletteBlock(int,bool) {
  
  memset(this, 0, 0x1005u);
  *(_DWORD *)this = a2;
  *((_BYTE *)this + 4) = a3;
  return this;
}


// address=[0x2fd2a60]
// Decompiled from void __thiscall SM_SIV_PaletteBlock::~SM_SIV_PaletteBlock(SM_SIV_PaletteBlock *this)
 SM_SIV_PaletteBlock::~SM_SIV_PaletteBlock(void) {
  
  ;
}


// address=[0x2fd2a70]
// Decompiled from int __thiscall SM_SIV_PaletteBlock::FillPalette(  _BYTE *this,  int a2,  _DWORD *a3,  unsigned __int8 a4,  unsigned __int16 a5)
int  SM_SIV_PaletteBlock::FillPalette(enum SM_SIV_PALETTETYPE,unsigned char * * const,unsigned char,unsigned short) {
  
  unsigned int v5; // eax
  int v6; // esi
  _BYTE v8[16]; // [esp+Ch] [ebp-44h] BYREF
  int v9; // [esp+1Ch] [ebp-34h]
  unsigned int j; // [esp+20h] [ebp-30h]
  _DWORD *v11; // [esp+24h] [ebp-2Ch]
  unsigned __int16 v12; // [esp+28h] [ebp-28h]
  unsigned __int16 v13; // [esp+2Ch] [ebp-24h]
  unsigned __int16 v14; // [esp+30h] [ebp-20h]
  unsigned __int16 v15; // [esp+34h] [ebp-1Ch]
  unsigned __int16 i; // [esp+38h] [ebp-18h]
  char v17; // [esp+3Fh] [ebp-11h]
  unsigned __int8 v18; // [esp+40h] [ebp-10h]
  unsigned __int8 v19; // [esp+41h] [ebp-Fh]
  unsigned __int8 v20; // [esp+42h] [ebp-Eh]
  unsigned __int8 v21; // [esp+43h] [ebp-Dh]
  int v22; // [esp+4Ch] [ebp-4h]

  v11 = this;
  if ( this[4] )
  {
    for ( i = 0; i < (int)a5; ++i )
    {
      v19 = *(_BYTE *)(*a3 + i);
      v20 = *(_BYTE *)(a3[1] + i);
      v21 = *(_BYTE *)(a3[2] + i);
      v18 = *(_BYTE *)(a3[3] + i);
      if ( !*v11 )
      {
        v14 = SM_SIV_PaletteBlock::Convert565(v19, v20, v21, 0.5);
        v15 = SM_SIV_PaletteBlock::Convert565(v19, v20, v21, 1.0);
      }
      if ( *v11 == 1 )
      {
        v14 = SM_SIV_PaletteBlock::Convert555(v19, v20, v21, 0.5);
        v15 = SM_SIV_PaletteBlock::Convert555(v19, v20, v21, 1.0);
      }
      if ( *v11 == 2 )
      {
        v14 = SM_SIV_PaletteBlock::Convert4444(v19, v20, v21, v18, 0.5);
        v15 = SM_SIV_PaletteBlock::Convert4444(v19, v20, v21, v18, 1.0);
      }
      *(_WORD *)((char *)&v11[128 * a2 + 1] + 2 * i + 2 * a4 + 1) = v15;
      *(_WORD *)((char *)&v11[128 * a2 + 257] + 2 * i + 2 * a4 + 1) = v14;
    }
  }
  else
  {
    for ( i = 0; i < (int)a5; ++i )
    {
      v19 = *(_BYTE *)(*a3 + i);
      v20 = *(_BYTE *)(a3[1] + i);
      v21 = *(_BYTE *)(a3[2] + i);
      v18 = *(_BYTE *)(a3[3] + i);
      if ( !*v11 )
      {
        v14 = SM_SIV_PaletteBlock::Convert565(v19, v20, v21, 0.44999999);
        v15 = SM_SIV_PaletteBlock::Convert565(v19, v20, v21, 0.69999999);
        v12 = SM_SIV_PaletteBlock::Convert565(v19, v20, v21, 0.85000002);
        v13 = SM_SIV_PaletteBlock::Convert565(v19, v20, v21, 1.0);
      }
      if ( *v11 == 1 )
      {
        v14 = SM_SIV_PaletteBlock::Convert555(v19, v20, v21, 0.44999999);
        v15 = SM_SIV_PaletteBlock::Convert555(v19, v20, v21, 0.69999999);
        v12 = SM_SIV_PaletteBlock::Convert555(v19, v20, v21, 0.85000002);
        v13 = SM_SIV_PaletteBlock::Convert555(v19, v20, v21, 1.0);
      }
      if ( *v11 == 2 )
      {
        v14 = SM_SIV_PaletteBlock::Convert4444(v19, v20, v21, v18, 0.44999999);
        v15 = SM_SIV_PaletteBlock::Convert4444(v19, v20, v21, v18, 0.69999999);
        v12 = SM_SIV_PaletteBlock::Convert4444(v19, v20, v21, v18, 0.85000002);
        v13 = SM_SIV_PaletteBlock::Convert4444(v19, v20, v21, v18, 1.0);
      }
      *(_WORD *)((char *)&v11[128 * a2 + 1] + 2 * i + 2 * a4 + 1) = v13;
      *(_WORD *)((char *)&v11[128 * a2 + 257] + 2 * i + 2 * a4 + 1) = v12;
      *(_WORD *)((char *)&v11[128 * a2 + 513] + 2 * i + 2 * a4 + 1) = v15;
      *(_WORD *)((char *)&v11[128 * a2 + 769] + 2 * i + 2 * a4 + 1) = v14;
    }
  }
  std::vector<unsigned short>::vector<unsigned short>(v8);
  v22 = 0;
  for ( i = 0; i < 0x100u; ++i )
  {
    v17 = 0;
    for ( j = 0; ; ++j )
    {
      v5 = std::vector<unsigned short>::size(v8);
      if ( j >= v5 )
        break;
      v6 = *(unsigned __int16 *)((char *)&v11[128 * a2 + 1] + 2 * i + 2 * a4 + 1);
      if ( v6 == *(unsigned __int16 *)std::vector<unsigned short>::operator[](v8, j) )
      {
        v17 = 1;
        break;
      }
    }
    if ( !v17 )
      std::vector<unsigned short>::push_back((char *)&v11[128 * a2 + 1] + 2 * i + 2 * a4 + 1);
  }
  v9 = std::vector<unsigned short>::size(v8);
  v22 = -1;
  std::vector<unsigned short>::~vector<unsigned short>(v8);
  return v9;
}


// address=[0x2fd30f0]
// Decompiled from int __thiscall SM_SIV_PaletteBlock::Save(_BYTE *this, FILE *a2, FILE *Stream, int Buffer, char a5, char a6)
unsigned int  SM_SIV_PaletteBlock::Save(struct _iobuf *,struct _iobuf *,unsigned int,bool,bool) {
  
  unsigned int v8; // [esp+4h] [ebp-14h]
  unsigned int v9; // [esp+8h] [ebp-10h]
  int v10; // [esp+Ch] [ebp-Ch]
  unsigned int j; // [esp+10h] [ebp-8h]
  unsigned int i; // [esp+14h] [ebp-4h]

  if ( Stream )
    j__fwrite(&Buffer, 4u, 1u, Stream);
  if ( this[4] )
    v9 = 2;
  else
    v9 = 4;
  v8 = 2;
  if ( a5 && a6 )
    v8 = 1;
  v10 = Buffer;
  for ( i = 0; i < v9; ++i )
  {
    for ( j = 0; j < v8; ++j )
    {
      j__fwrite(&this[1024 * i + 5 + 512 * j], 0x200u, 1u, a2);
      if ( Stream )
        v10 += 512;
    }
  }
  return v10;
}


// address=[0x2fd33c0]
// Decompiled from unsigned int __cdecl SM_SIV_PaletteBlock::Convert4444(  unsigned int a1,  unsigned int a2,  unsigned int a3,  unsigned int a4,  float a5)
static unsigned short __cdecl SM_SIV_PaletteBlock::Convert4444(unsigned int,unsigned int,unsigned int,unsigned int,float) {
  
  float v5; // xmm0_4
  unsigned int v6; // eax
  float v7; // xmm0_4
  unsigned int v8; // eax
  float v9; // xmm0_4

  v5 = (double)(a1 >> 4) + 0.0;
  v6 = ((int)(float)(v5 * a5) << 8) + (a4 >> 4 << 12);
  v7 = (double)(a2 >> 4) + 0.0;
  v8 = 16 * (int)(float)(v7 * a5) + v6;
  v9 = (double)(a3 >> 4) + 0.0;
  return (int)(float)(v9 * a5) + v8;
}


// address=[0x2fd34a0]
// Decompiled from int __cdecl SM_SIV_PaletteBlock::Convert555(unsigned int a1, unsigned int a2, unsigned int a3, float a4)
static unsigned short __cdecl SM_SIV_PaletteBlock::Convert555(unsigned int,unsigned int,unsigned int,float) {
  
  float v4; // xmm0_4
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  float v8; // xmm0_4

  v4 = (double)(a1 >> 3) + 0.0;
  v5 = (int)(float)(v4 * a4) << 10;
  v6 = (double)(a2 >> 3) + 0.0;
  v7 = 32 * (int)(float)(v6 * a4) + v5;
  v8 = (double)(a3 >> 3) + 0.0;
  return (int)(float)(v8 * a4) + v7;
}


// address=[0x2fd3570]
// Decompiled from int __cdecl SM_SIV_PaletteBlock::Convert565(unsigned int a1, unsigned int a2, unsigned int a3, float a4)
static unsigned short __cdecl SM_SIV_PaletteBlock::Convert565(unsigned int,unsigned int,unsigned int,float) {
  
  float v4; // xmm0_4
  int v5; // eax
  float v6; // xmm0_4
  int v7; // eax
  float v8; // xmm0_4

  v4 = (double)(a1 >> 3) + 0.0;
  v5 = (int)(float)(v4 * a4) << 11;
  v6 = (double)(a2 >> 2) + 0.0;
  v7 = 32 * (int)(float)(v6 * a4) + v5;
  v8 = (double)(a3 >> 3) + 0.0;
  return (int)(float)(v8 * a4) + v7;
}


