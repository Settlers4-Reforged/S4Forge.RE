#include "CLandBlob.h"

// Definitions for class CLandBlob

// address=[0x2fc9de0]
// Decompiled from CLandBlob *__thiscall CLandBlob::CLandBlob(  CLandBlob *this,  int a2,  int a3,  int a4,  int a5,  bool a6,  int a7,  int a8,  int a9,  struct CCheckLayer *a10)
 CLandBlob::CLandBlob(int a2, int a3, int a4, int a5, bool a6, int a7, int a8, int a9, class CCheckLayer * a10) {
  
  CBlob::CBlob(this, a2, a3, a4, a5, a7, a8, a9, a10);
  *(_DWORD *)this = CLandBlob::_vftable_;
  *((_BYTE *)this + 60) = a6;
  *((_DWORD *)this + 11) = (*((_DWORD *)this + 7) - *((_DWORD *)this + 5) + *((_DWORD *)this + 6)
                                                                          - *((_DWORD *)this + 4))
                         / 2;
  *((float *)this + 14) = 20.0 / (float)*((int *)this + 11);
  *((_DWORD *)this + 12) = *((_DWORD *)this + 4) + (*((_DWORD *)this + 6) - *((_DWORD *)this + 4)) / 2;
  *((_DWORD *)this + 13) = *((_DWORD *)this + 5) + (*((_DWORD *)this + 7) - *((_DWORD *)this + 5)) / 2;
  return this;
}


// address=[0x2fc9eb0]
// Decompiled from int __thiscall CLandBlob::processPoint(CCheckLayer **this, int a2, int a3)
void  CLandBlob::processPoint(int a2, int a3) {
  
  int result; // eax

  CCheckLayer::setPoint(this[8], a2 - (_DWORD)this[9], a3 - (_DWORD)this[10], 1u);
  if ( (CCheckLayer *)*(unsigned __int8 *)(g_pMapElement + 4 * (a2 + (_DWORD)this[3] * a3) + 1) != this[1] )
    *(_BYTE *)(g_pMapElement + 4 * (a2 + (_DWORD)this[3] * a3) + 1) = *((_BYTE *)this + 4);
  result = g_pMapElement;
  ++*(_BYTE *)(g_pMapElement + 4 * (a2 + (_DWORD)this[3] * a3));
  return result;
}


// address=[0x2fc9f50]
// Decompiled from int __thiscall CLandBlob::processFillPoint(CCheckLayer **this, int a2, int a3)
void  CLandBlob::processFillPoint(int a2, int a3) {
  
  int result; // eax
  int v4; // esi
  int v5; // esi
  float v6; // xmm0_4
  float v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+14h] [ebp-8h]

  CCheckLayer::setPoint(this[8], a2 - (_DWORD)this[9], a3 - (_DWORD)this[10], 1u);
  if ( (CCheckLayer *)*(unsigned __int8 *)(g_pMapElement + 4 * (a2 + (_DWORD)this[3] * a3) + 1) != this[1] )
    *(_BYTE *)(g_pMapElement + 4 * (a2 + (_DWORD)this[3] * a3) + 1) = *((_BYTE *)this + 4);
  result = *((unsigned __int8 *)this + 60);
  if ( !*((_BYTE *)this + 60) )
    return result;
  v4 = j__abs(a2 - (_DWORD)this[12]);
  v8 = j__abs(a3 - (_DWORD)this[13]) + v4;
  if ( (float)((float)v8 * *((float *)this + 14)) < 20.0 )
  {
    v5 = a2 + (_DWORD)this[3] * a3;
    v7 = 20.0 - (float)((float)v8 * *((float *)this + 14));
    v6 = (double)(CRandom16::Rand((CRandom16 *)g_pRand) % 3) + 0.0;
    result = a2 + (_DWORD)this[3] * a3;
    *(_BYTE *)(g_pMapElement + 4 * result) = (int)(float)((float)*(unsigned __int8 *)(g_pMapElement + 4 * v5)
                                                        + (float)(v7 + v6));
  }
  else
  {
    result = *(unsigned __int8 *)(g_pMapElement + 4 * (a2 + (_DWORD)this[3] * a3)) + 1;
    *(_BYTE *)(g_pMapElement + 4 * (a2 + (_DWORD)this[3] * a3)) = result;
  }
  return result;
}


