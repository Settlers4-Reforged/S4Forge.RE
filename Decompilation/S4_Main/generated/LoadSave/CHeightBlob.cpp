#include "all_headers.h"

// Definitions for class CHeightBlob

// address=[0x2fccbb0]
// Decompiled from CHeightBlob *__thiscall CHeightBlob::CHeightBlob(  CHeightBlob *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  struct CCheckLayer *a8)
 CHeightBlob::CHeightBlob(int,int,int,int,int,int,class CCheckLayer *) {
  
  CBlob::CBlob(this, a2, a3, a4, a5, 0, a6, a7, a8);
  *(_DWORD *)this = &CHeightBlob::_vftable_;
  *((_DWORD *)this + 11) = -1;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 1;
  *((_DWORD *)this + 14) = 1;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = -1;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 1;
  *((_DWORD *)this + 19) = 1;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = -1;
  *((_DWORD *)this + 22) = -1;
  return this;
}


// address=[0x2fccce0]
// Decompiled from __int16 __thiscall CHeightBlob::fillBlob(CCheckLayer **this, int a2, int a3)
void  CHeightBlob::fillBlob(int,int) {
  
  int v3; // eax
  int Point; // esi
  int v6; // [esp+8h] [ebp-2Ch]
  char *v7; // [esp+Ch] [ebp-28h]
  int v8; // [esp+10h] [ebp-24h]
  int v9; // [esp+14h] [ebp-20h]
  int i; // [esp+18h] [ebp-1Ch]
  int v11; // [esp+1Ch] [ebp-18h]
  int v12; // [esp+1Ch] [ebp-18h]
  int v13; // [esp+20h] [ebp-14h]
  char v16; // [esp+32h] [ebp-2h]
  char v17; // [esp+33h] [ebp-1h]

  v13 = a2;
  v11 = 0;
  v9 = 1;
  while ( !CCheckLayer::getPoint(
             this[8],
             (int)this[v11 + 11] + a2 - (_DWORD)this[9],
             (int)this[v11 + 17] + a3 - (_DWORD)this[10])
       && a3 > 0 )
  {
    if ( ++v11 == 6 )
    {
      v11 = 0;
      --a3;
    }
  }
  while ( 1 )
  {
    if ( v13 >= (int)this[3] && BBSupportDbgReport(2, "HeightBlob.cpp", 52, "iCurrentPosX < m_iWorldSize") == 1 )
      __debugbreak();
    if ( v13 <= 0 && BBSupportDbgReport(2, "HeightBlob.cpp", 53, "iCurrentPosX > 0") == 1 )
      __debugbreak();
    if ( a3 >= (int)this[3] && BBSupportDbgReport(2, "HeightBlob.cpp", 54, "iCurrentPosY < m_iWorldSize") == 1 )
      __debugbreak();
    if ( a3 <= 0 && BBSupportDbgReport(2, "HeightBlob.cpp", 55, "iCurrentPosY > 0") == 1 )
      __debugbreak();
    LOWORD(v3) = 0;
    v12 = 0;
    v17 = 0;
    v8 = 0;
    while ( 1 )
    {
      if ( v17 )
      {
        LOWORD(v3) = CCheckLayer::getPoint(
                       this[8],
                       (int)this[v12 + 11] + v13 - (_DWORD)this[9],
                       (int)this[v12 + 17] + a3 - (_DWORD)this[10]);
        if ( !(_WORD)v3 )
          break;
      }
      if ( v8 >= 7 )
        break;
      LOWORD(v3) = CCheckLayer::getPoint(
                     this[8],
                     (int)this[v12 + 11] + v13 - (_DWORD)this[9],
                     (int)this[v12 + 17] + a3 - (_DWORD)this[10]);
      if ( (_WORD)v3 )
        v17 = 1;
      if ( v12 == 5 )
        v12 = 0;
      else
        ++v12;
      if ( ++v8 == 7 )
      {
        (*((void (__thiscall **)(CCheckLayer **, int, int))*this + 2))(this, v13, a3);
        LOWORD(v3) = CCheckLayer::setPoint(this[8], v13 - (_DWORD)this[9], a3 - (_DWORD)this[10], v9++);
        i = 6;
        v7 = 0;
        v6 = 0;
        v16 = 0;
        while ( i == 6 && !v16 )
        {
          for ( i = 0; i < 6; ++i )
          {
            LOWORD(v3) = CCheckLayer::getPoint(
                           this[8],
                           (int)this[i + 11] + v13 - (_DWORD)this[9],
                           (int)this[i + 17] + a3 - (_DWORD)this[10]);
            if ( !(_WORD)v3 )
              break;
            Point = (unsigned __int16)CCheckLayer::getPoint(
                                        this[8],
                                        (int)this[i + 11] + v13 - (_DWORD)this[9],
                                        (int)this[i + 17] + a3 - (_DWORD)this[10]);
            v3 = (unsigned __int16)CCheckLayer::getPoint(this[8], v13 - (_DWORD)this[9], a3 - (_DWORD)this[10]) - 1;
            if ( Point == v3 )
            {
              v7 = (char *)this[i + 11] + v13;
              v3 = (int)this[i + 17] + a3;
              v6 = v3;
            }
          }
          if ( i >= 6 )
          {
            v13 = (int)v7;
            a3 = v6;
            LOWORD(v3) = CCheckLayer::getPoint(this[8], v7 - (char *)this[9], v6 - (_DWORD)this[10]);
            v9 = (unsigned __int16)v3;
          }
          else
          {
            v8 = 0;
          }
          if ( v9 == 1 )
            v16 = 1;
        }
      }
    }
    if ( v8 >= 7 )
      break;
    (*((void (__thiscall **)(CCheckLayer **, int, int))*this + 2))(this, v13, a3);
    CCheckLayer::setPoint(this[8], v13 - (_DWORD)this[9], a3 - (_DWORD)this[10], v9++);
    v13 += (int)this[v12 + 11];
    a3 += (int)this[v12 + 17];
  }
  return v3;
}


// address=[0x2fcd100]
// Decompiled from int __thiscall CHeightBlob::processFillPoint(CHeightBlob *this, int a2, int a3)
void  CHeightBlob::processFillPoint(int,int) {
  
  int result; // eax
  int v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]

  result = *(unsigned __int8 *)(g_pMapElement + 4 * (a2 + *((_DWORD *)this + 3) * a3) + 1);
  if ( result != 16 )
    return result;
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
  {
    result = a2 + *((_DWORD *)this + 3) * a3;
    *(_BYTE *)(g_pMapElement + 4 * result) = v4;
  }
  else
  {
    result = g_pMapElement;
    *(_BYTE *)(g_pMapElement + 4 * (a2 + *((_DWORD *)this + 3) * a3)) = v4 + 1;
  }
  return result;
}


