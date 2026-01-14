#include "all_headers.h"

// Definitions for class CBlob

// address=[0x2fc88f0]
// Decompiled from _DWORD *__thiscall CBlob::CBlob(_DWORD *this)
 CBlob::CBlob(void) {
  
  *this = CBlob::_vftable_;
  return this;
}


// address=[0x2fc8910]
// Decompiled from CBlob *__thiscall CBlob::CBlob(  CBlob *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  int a8,  struct CCheckLayer *a9)
 CBlob::CBlob(int,int,int,int,int,int,int,class CCheckLayer *) {
  
  unsigned int v10; // [esp+4h] [ebp-Ch]
  unsigned int v11; // [esp+8h] [ebp-8h]

  *(_DWORD *)this = CBlob::_vftable_;
  *((_DWORD *)this + 8) = a9;
  CCheckLayer::clear(*((void ***)this + 8));
  *((_DWORD *)this + 1) = a6;
  *((_DWORD *)this + 2) = a7;
  *((_DWORD *)this + 3) = a8;
  v11 = 0;
  v10 = 0;
  if ( a2 <= *((_DWORD *)this + 2) )
  {
    v11 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) / 2) - *((_DWORD *)this + 2) / 4;
    *((_DWORD *)this + 4) = *((_DWORD *)this + 2);
  }
  else
  {
    *((_DWORD *)this + 4) = a2;
  }
  if ( a3 <= *((_DWORD *)this + 2) )
  {
    v10 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) / 2) - *((_DWORD *)this + 2) / 4;
    *((_DWORD *)this + 5) = *((_DWORD *)this + 2);
  }
  else
  {
    *((_DWORD *)this + 5) = a3;
  }
  if ( a4 >= *((_DWORD *)this + 3) - *((_DWORD *)this + 2) )
  {
    v11 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) / 2) - *((_DWORD *)this + 2) / 4;
    *((_DWORD *)this + 6) = *((_DWORD *)this + 3) - *((_DWORD *)this + 2);
  }
  else
  {
    *((_DWORD *)this + 6) = a4;
  }
  if ( a5 >= *((_DWORD *)this + 3) - *((_DWORD *)this + 2) )
  {
    v10 = CRandom16::Rand((CRandom16 *)g_pRand) % (*((_DWORD *)this + 2) / 2) - *((_DWORD *)this + 2) / 4;
    *((_DWORD *)this + 7) = *((_DWORD *)this + 3) - *((_DWORD *)this + 2);
  }
  else
  {
    *((_DWORD *)this + 7) = a5;
  }
  *((_DWORD *)this + 4) += v11;
  *((_DWORD *)this + 5) += v10;
  *((_DWORD *)this + 6) += v11;
  *((_DWORD *)this + 7) += v10;
  if ( *((_DWORD *)this + 7) >= *((_DWORD *)this + 3)
    && BBSupportDbgReport(2, "Blob.cpp", 71, "m_iMaxY < m_iWorldSize") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + 6) >= *((_DWORD *)this + 3)
    && BBSupportDbgReport(2, "Blob.cpp", 72, "m_iMaxX < m_iWorldSize") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + 5) <= 0 && BBSupportDbgReport(2, "Blob.cpp", 73, "m_iMinY > 0") == 1 )
    __debugbreak();
  if ( *((int *)this + 4) <= 0 && BBSupportDbgReport(2, "Blob.cpp", 74, "m_iMinX > 0") == 1 )
    __debugbreak();
  *((_DWORD *)this + 9) = *((_DWORD *)this + 4) - 10;
  *((_DWORD *)this + 10) = *((_DWORD *)this + 5) - 10;
  return this;
}


// address=[0x2fc8be0]
// Decompiled from CBlob *__thiscall CBlob::drawBlob(CBlob *this)
void  CBlob::drawBlob(void) {
  
  CBlob *result; // eax
  int v2; // eax
  int v3; // [esp-4h] [ebp-4Ch]
  int NextDirection; // [esp+0h] [ebp-48h]
  int v5; // [esp+4h] [ebp-44h]
  int v6; // [esp+8h] [ebp-40h]
  int i; // [esp+Ch] [ebp-3Ch]
  int v8; // [esp+10h] [ebp-38h]
  int v9; // [esp+14h] [ebp-34h]
  int v10; // [esp+18h] [ebp-30h]
  int v11; // [esp+1Ch] [ebp-2Ch]
  int v13; // [esp+24h] [ebp-24h]
  _DWORD v14[3]; // [esp+28h] [ebp-20h]
  int v15; // [esp+34h] [ebp-14h]
  _DWORD v16[3]; // [esp+38h] [ebp-10h]

  result = this;
  if ( *((_DWORD *)this + 6) - *((_DWORD *)this + 4) < 14 )
    return result;
  result = this;
  if ( *((_DWORD *)this + 7) - *((_DWORD *)this + 5) < 14 )
    return result;
  v15 = *((_DWORD *)this + 4) + (*((_DWORD *)this + 6) - *((_DWORD *)this + 4)) / 2;
  v16[0] = *((_DWORD *)this + 4);
  v16[1] = *((_DWORD *)this + 4) + (*((_DWORD *)this + 6) - *((_DWORD *)this + 4)) / 2;
  v16[2] = *((_DWORD *)this + 6);
  v13 = *((_DWORD *)this + 5);
  v14[0] = *((_DWORD *)this + 5) + (*((_DWORD *)this + 7) - *((_DWORD *)this + 5)) / 2;
  v14[1] = *((_DWORD *)this + 7);
  v14[2] = *((_DWORD *)this + 5) + (*((_DWORD *)this + 7) - *((_DWORD *)this + 5)) / 2;
  for ( i = 0; i < 4; ++i )
  {
    v6 = v16[i - 1];
    v5 = v14[i - 1];
    if ( i == 3 )
    {
      v9 = v15;
      v8 = v13;
    }
    else
    {
      v9 = v16[i];
      v8 = v14[i];
    }
    v11 = v16[i - 1];
    v10 = v14[i - 1];
    if ( (v9 >= *((_DWORD *)this + 3) || v9 <= 0)
      && BBSupportDbgReport(2, "Blob.cpp", 128, "iEndX < m_iWorldSize && iEndX > 0") == 1 )
    {
      __debugbreak();
    }
    if ( (v8 >= *((_DWORD *)this + 3) || v8 <= 0)
      && BBSupportDbgReport(2, "Blob.cpp", 129, "iEndY < m_iWorldSize && iEndY > 0") == 1 )
    {
      __debugbreak();
    }
    if ( (v6 <= 0 || v6 >= *((_DWORD *)this + 3))
      && BBSupportDbgReport(2, "Blob.cpp", 130, "iStartX > 0 && iStartX < m_iWorldSize") == 1 )
    {
      __debugbreak();
    }
    if ( (v5 <= 0 || v5 >= *((_DWORD *)this + 3))
      && BBSupportDbgReport(2, "Blob.cpp", 131, "iStartY > 0 && iStartY < m_iWorldSize") == 1 )
    {
      __debugbreak();
    }
    while ( v11 != v9 || v10 != v8 )
    {
      v3 = j__abs(v8 - v10);
      v2 = j__abs(v9 - v11);
      NextDirection = CBlob::getNextDirection(this, v2, v3);
      switch ( NextDirection )
      {
        case 1:
          if ( v9 > v11 && v11 < *((_DWORD *)this + 3) - 1 )
            ++v11;
          if ( v9 < v11 && v11 > 0 )
            --v11;
          break;
        case 2:
          if ( v9 >= v11 || v8 <= v10 || v10 >= *((_DWORD *)this + 3) - 1 )
          {
            if ( v9 < v11 || v8 < v10 || v11 >= *((_DWORD *)this + 3) - 1 || v10 >= *((_DWORD *)this + 3) - 1 )
            {
              if ( v9 <= v11 || v8 >= v10 || v10 <= 0 )
              {
                if ( v9 <= v11 && v8 <= v10 && v11 > 0 && v10 > 0 )
                {
                  --v11;
                  --v10;
                }
              }
              else
              {
                --v10;
              }
            }
            else
            {
              ++v11;
              ++v10;
            }
          }
          else
          {
            ++v10;
          }
          break;
        case 3:
          if ( v9 > v11 || v8 < v10 || v11 <= 0 )
          {
            if ( v9 <= v11 || v8 <= v10 || v10 >= *((_DWORD *)this + 3) - 1 )
            {
              if ( v9 < v11 || v8 > v10 || v11 >= *((_DWORD *)this + 3) - 1 )
              {
                if ( v9 < v11 && v8 < v10 && v10 > 0 )
                  --v10;
              }
              else
              {
                ++v11;
              }
            }
            else
            {
              ++v10;
            }
          }
          else
          {
            --v11;
          }
          break;
      }
      if ( v11 >= *((_DWORD *)this + 3) && BBSupportDbgReport(2, "Blob.cpp", 195, "iCurrentX < m_iWorldSize") == 1 )
        __debugbreak();
      if ( v11 <= 0 && BBSupportDbgReport(2, "Blob.cpp", 196, "iCurrentX > 0") == 1 )
        __debugbreak();
      if ( v10 >= *((_DWORD *)this + 3) && BBSupportDbgReport(2, "Blob.cpp", 197, "iCurrentY < m_iWorldSize") == 1 )
        __debugbreak();
      if ( v10 <= 0 && BBSupportDbgReport(2, "Blob.cpp", 198, "iCurrentY > 0") == 1 )
        __debugbreak();
      (*(void (__thiscall **)(CBlob *, int, int))(*(_DWORD *)this + 4))(this, v11, v10);
    }
  }
  return (CBlob *)(**(int (__thiscall ***)(CBlob *, int, int))this)(
                    this,
                    *((_DWORD *)this + 4) + (*((_DWORD *)this + 6) - *((_DWORD *)this + 4)) / 2,
                    *((_DWORD *)this + 5) + (*((_DWORD *)this + 7) - *((_DWORD *)this + 5)) / 2);
}


// address=[0x2fc9100]
// Decompiled from int __thiscall CBlob::fillBlob(CBlob *this, int a2, int a3)
void  CBlob::fillBlob(int,int) {
  
  int result; // eax
  _DWORD v4[2]; // [esp+0h] [ebp-830h] BYREF
  int v5; // [esp+8h] [ebp-828h]
  int v6; // [esp+Ch] [ebp-824h]
  int v7; // [esp+10h] [ebp-820h]
  int i; // [esp+14h] [ebp-81Ch]
  int v9; // [esp+18h] [ebp-818h] BYREF
  int v10; // [esp+1Ch] [ebp-814h]
  CBlob *v11; // [esp+20h] [ebp-810h]
  _BYTE v12[2056]; // [esp+24h] [ebp-80Ch] BYREF

  v11 = this;
  v5 = *((_DWORD *)this + 3) * *((_DWORD *)this + 3);
  TStaticFIFO<int,512>::TStaticFIFO<int,512>(v12);
  v4[0] = a2 + *((_DWORD *)v11 + 3) * a3;
  TStaticFIFO<int,512>::Push(v4);
  (*(void (__thiscall **)(CBlob *, int, int))(*(_DWORD *)v11 + 8))(v11, a2, a3);
  while ( 1 )
  {
    result = (unsigned __int8)TStaticFIFO<int,512>::Empty(v12);
    if ( (_BYTE)result )
      return result;
    v10 = *(_DWORD *)TStaticFIFO<int,512>::Top(v12);
    TStaticFIFO<int,512>::Pop(v12);
    for ( i = 0; i < 6; ++i )
    {
      v9 = 0;
      v4[1] = i;
      switch ( i )
      {
        case 0:
          if ( v10 - *((_DWORD *)v11 + 3) - 1 >= 0 )
            v9 = v10 - *((_DWORD *)v11 + 3) - 1;
          break;
        case 1:
          if ( v10 - *((_DWORD *)v11 + 3) >= 0 )
            v9 = v10 - *((_DWORD *)v11 + 3);
          break;
        case 2:
          if ( v10 - 1 >= 0 )
            v9 = v10 - 1;
          break;
        case 3:
          if ( v10 + 1 < v5 )
            v9 = v10 + 1;
          break;
        case 4:
          if ( *((_DWORD *)v11 + 3) + v10 < v5 )
            v9 = *((_DWORD *)v11 + 3) + v10;
          break;
        case 5:
          if ( v10 + *((_DWORD *)v11 + 3) + 1 < v5 )
            v9 = v10 + *((_DWORD *)v11 + 3) + 1;
          break;
        default:
          break;
      }
      v6 = v9 % *((_DWORD *)v11 + 3);
      v7 = v9 / *((_DWORD *)v11 + 3);
      if ( v6 >= *((_DWORD *)v11 + 3) && BBSupportDbgReport(2, "Blob.cpp", 262, "iCurrentX < m_iWorldSize") == 1 )
        __debugbreak();
      if ( v6 <= 0 && BBSupportDbgReport(2, "Blob.cpp", 263, "iCurrentX > 0") == 1 )
        __debugbreak();
      if ( v7 >= *((_DWORD *)v11 + 3) && BBSupportDbgReport(2, "Blob.cpp", 264, "iCurrentY < m_iWorldSize") == 1 )
        __debugbreak();
      if ( v7 <= 0 && BBSupportDbgReport(2, "Blob.cpp", 265, "iCurrentY > 0") == 1 )
        __debugbreak();
      if ( !CCheckLayer::getPoint(*((CCheckLayer **)v11 + 8), v6 - *((_DWORD *)v11 + 9), v7 - *((_DWORD *)v11 + 10)) )
      {
        TStaticFIFO<int,512>::Push(&v9);
        (*(void (__thiscall **)(CBlob *, int, int))(*(_DWORD *)v11 + 8))(v11, v6, v7);
      }
    }
  }
}


// address=[0x2fc9490]
// Decompiled from int __thiscall CBlob::getNextDirection(CBlob *this, int a2, int a3)
int  CBlob::getNextDirection(int,int) {
  
  signed int v4; // [esp+Ch] [ebp-Ch]
  int v5; // [esp+10h] [ebp-8h]
  int v6; // [esp+14h] [ebp-4h]

  v4 = CRandom16::Rand((CRandom16 *)g_pRand) % 0x64;
  if ( a2 >= a3 )
    v6 = (int)abs(80.0 - (float)((float)((float)a3 / (float)a2) * 100.0));
  else
    v6 = (int)abs(80.0 - (float)((float)((float)a2 / (float)a3) * 100.0));
  if ( v6 >= 40 )
    v5 = (80 - v6) / 3;
  else
    v5 = v6 + 10;
  if ( v4 >= 0 && v4 < v5 )
    return 1;
  if ( v4 >= v5 && v4 < v6 + v5 )
    return 2;
  if ( v4 < v6 + v5 || v4 >= 100 )
    return -1;
  return 3;
}


// address=[0x2fc95d0]
// Decompiled from int __thiscall CBlob::processPoint(CCheckLayer **this, int a2, int a3)
void  CBlob::processPoint(int,int) {
  
  return CCheckLayer::setPoint(this[8], a2 - (_DWORD)this[9], a3 - (_DWORD)this[10], 1u);
}


