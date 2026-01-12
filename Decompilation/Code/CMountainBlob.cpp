#include "CMountainBlob.h"

// Definitions for class CMountainBlob

// address=[0x2fc9ac0]
// Decompiled from CMountainBlob *__thiscall CMountainBlob::CMountainBlob(
        CMountainBlob *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        struct CCheckLayer *a8)

 CMountainBlob::CMountainBlob(int,int,int,int,int,int,class CCheckLayer *) {
  
  CHeightBlob::CHeightBlob(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = CMountainBlob::_vftable_;
  return this;
}


// address=[0x2fc9b00]
// Decompiled from CMountainBlob *__thiscall CMountainBlob::processFillPoint(CMountainBlob *this, int a2, int a3)

void  CMountainBlob::processFillPoint(int,int) {
  
  CMountainBlob *result; // eax
  int v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]

  v5 = 0;
  v4 = 255;
  while ( v5 < 6 )
  {
    if ( v4 > *(unsigned __int8 *)(g_pMapElement
                                 + 4
                                 * (*((_DWORD *)this + 3) * (*((_DWORD *)this + v5 + 17) + a3)
                                  + *((_DWORD *)this + v5 + 11)
                                  + a2)) )
    {
      if ( CCheckLayer::getPoint(
             *((CCheckLayer **)this + 8),
             *((_DWORD *)this + v5 + 11) + a2 - *((_DWORD *)this + 9),
             *((_DWORD *)this + v5 + 17) + a3 - *((_DWORD *)this + 10)) )
      {
        v4 = *(unsigned __int8 *)(g_pMapElement
                                + 4
                                * (*((_DWORD *)this + 3) * (*((_DWORD *)this + v5 + 17) + a3)
                                 + *((_DWORD *)this + v5 + 11)
                                 + a2));
      }
    }
    ++v5;
  }
  if ( v4 >= 250 )
    *(_BYTE *)(g_pMapElement + 4 * (a2 + *((_DWORD *)this + 3) * a3)) = v4;
  else
    *(_BYTE *)(g_pMapElement + 4 * (a2 + *((_DWORD *)this + 3) * a3)) = v4
                                                                      + CRandom16::Rand((CRandom16 *)g_pRand) % 2
                                                                      + 3;
  result = this;
  if ( *(unsigned __int8 *)(g_pMapElement + 4 * (a2 + *((_DWORD *)this + 3) * a3)) >= (int)(unsigned __int8)g_uSnowLimit )
    *(_BYTE *)(g_pMapElement + 4 * (a2 + *((_DWORD *)this + 3) * a3) + 1) = 0x80;
  else
    *(_BYTE *)(g_pMapElement + 4 * (a2 + *((_DWORD *)this + 3) * a3) + 1) = 32;
  return result;
}


// address=[0x2fc9c90]
// Decompiled from int __thiscall CMountainBlob::processPoint(CCheckLayer **this, int a2, int a3)

void  CMountainBlob::processPoint(int,int) {
  
  if ( *(_BYTE *)(g_pMapElement + 4 * (a2 + (_DWORD)this[3] * a3) + 1) != 16
    && *(_BYTE *)(g_pMapElement + 4 * (a2 + (_DWORD)this[3] * a3) + 1) != 7 )
  {
    return CCheckLayer::setPoint(this[8], a2 - (_DWORD)this[9], a3 - (_DWORD)this[10], 1u);
  }
  *(_BYTE *)(g_pMapElement + 4 * (a2 + (_DWORD)this[3] * a3) + 1) = 16;
  *(_BYTE *)(g_pMapElement + 4 * (a2 + (_DWORD)this[3] * a3)) += 5;
  return CCheckLayer::setPoint(this[8], a2 - (_DWORD)this[9], a3 - (_DWORD)this[10], 1u);
}


