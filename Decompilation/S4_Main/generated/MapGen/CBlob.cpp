#include "CBlob.h"

// Definitions for class CBlob

// address=[0x2fc88f0]
// Decompiled from _DWORD *__thiscall CBlob::CBlob(_DWORD *this)
 CBlob::CBlob(void) {
  
  *this = CBlob::_vftable_;
  return this;
}


// address=[0x2fc8910]
// Decompiled from CBlob *__thiscall CBlob::CBlob(CBlob *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8, struct CCheckLayer *a9)
 CBlob::CBlob(int a2, int a3, int a4, int a5, int a6, int a7, int a8, class CCheckLayer * a9) {
  
  DWORD v10; // [esp+4h] [ebp-Ch]
  DWORD v11; // [esp+8h] [ebp-8h]

  this->__vftable = (CBlob_vtbl *)&CBlob::_vftable_;
  this->m_pCheckLayer = a9;
  CCheckLayer::clear(this->m_pCheckLayer);
  this->m_iU1 = a6;
  this->m_iU2 = a7;
  this->m_iWorldSize = a8;
  v11 = 0;
  v10 = 0;
  if ( a2 <= this->m_iU2 )
  {
    v11 = CRandom16::Rand(g_pRand) % (this->m_iU2 / 2) - this->m_iU2 / 4;
    this->m_iMinX = this->m_iU2;
  }
  else
  {
    this->m_iMinX = a2;
  }
  if ( a3 <= this->m_iU2 )
  {
    v10 = CRandom16::Rand(g_pRand) % (this->m_iU2 / 2) - this->m_iU2 / 4;
    this->m_iMinY = this->m_iU2;
  }
  else
  {
    this->m_iMinY = a3;
  }
  if ( a4 >= this->m_iWorldSize - this->m_iU2 )
  {
    v11 = CRandom16::Rand(g_pRand) % (this->m_iU2 / 2) - this->m_iU2 / 4;
    this->m_iMaxX = this->m_iWorldSize - this->m_iU2;
  }
  else
  {
    this->m_iMaxX = a4;
  }
  if ( a5 >= this->m_iWorldSize - this->m_iU2 )
  {
    v10 = CRandom16::Rand(g_pRand) % (this->m_iU2 / 2) - this->m_iU2 / 4;
    this->m_iMaxY = this->m_iWorldSize - this->m_iU2;
  }
  else
  {
    this->m_iMaxY = a5;
  }
  this->m_iMinX += v11;
  this->m_iMinY += v10;
  this->m_iMaxX += v11;
  this->m_iMaxY += v10;
  if ( this->m_iMaxY >= this->m_iWorldSize && BBSupportDbgReport(2, "Blob.cpp", 71, "m_iMaxY < m_iWorldSize") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_iMaxX >= this->m_iWorldSize && BBSupportDbgReport(2, "Blob.cpp", 72, "m_iMaxX < m_iWorldSize") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_iMinY <= 0 && BBSupportDbgReport(2, "Blob.cpp", 73, "m_iMinY > 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_iMinX <= 0 && BBSupportDbgReport(2, "Blob.cpp", 74, "m_iMinX > 0") == 1 )
  {
    __debugbreak();
  }
  this->m_iU3 = this->m_iMinX - 10;
  this->m_iU4 = this->m_iMinY - 10;
  return this;
}


// address=[0x2fc8be0]
// Decompiled from void __thiscall CBlob::drawBlob(CBlob *this)
void  CBlob::drawBlob(void) {
  
  int v1; // eax
  int v2; // [esp-4h] [ebp-4Ch]
  int NextDirection; // [esp+0h] [ebp-48h]
  int iStartY; // [esp+4h] [ebp-44h]
  int iStartX; // [esp+8h] [ebp-40h]
  int i; // [esp+Ch] [ebp-3Ch]
  int iEndY; // [esp+10h] [ebp-38h]
  int iEndX; // [esp+14h] [ebp-34h]
  int iCurrentY; // [esp+18h] [ebp-30h]
  int iCurrentX; // [esp+1Ch] [ebp-2Ch]
  int m_iMinY; // [esp+24h] [ebp-24h]
  _DWORD v13[3]; // [esp+28h] [ebp-20h]
  int v14; // [esp+34h] [ebp-14h]
  _DWORD v15[3]; // [esp+38h] [ebp-10h]

  if ( this->m_iMaxX - this->m_iMinX >= 14 && this->m_iMaxY - this->m_iMinY >= 14 )
  {
    v14 = this->m_iMinX + (this->m_iMaxX - this->m_iMinX) / 2;
    v15[0] = this->m_iMinX;
    v15[1] = this->m_iMinX + (this->m_iMaxX - this->m_iMinX) / 2;
    v15[2] = this->m_iMaxX;
    m_iMinY = this->m_iMinY;
    v13[0] = this->m_iMinY + (this->m_iMaxY - this->m_iMinY) / 2;
    v13[1] = this->m_iMaxY;
    v13[2] = this->m_iMinY + (this->m_iMaxY - this->m_iMinY) / 2;
    for ( i = 0;
          i < 4;
          ++i )
    {
      iStartX = v15[i - 1];
      iStartY = v13[i - 1];
      if ( i == 3 )
      {
        iEndX = v14;
        iEndY = m_iMinY;
      }
      else
      {
        iEndX = v15[i];
        iEndY = v13[i];
      }
      iCurrentX = v15[i - 1];
      iCurrentY = v13[i - 1];
      if ( (iEndX >= this->m_iWorldSize || iEndX <= 0) && BBSupportDbgReport(2, "Blob.cpp", 128, "iEndX < m_iWorldSize && iEndX > 0") == 1 )
      {
        __debugbreak();
      }
      if ( (iEndY >= this->m_iWorldSize || iEndY <= 0) && BBSupportDbgReport(2, "Blob.cpp", 129, "iEndY < m_iWorldSize && iEndY > 0") == 1 )
      {
        __debugbreak();
      }
      if ( (iStartX <= 0 || iStartX >= this->m_iWorldSize) && BBSupportDbgReport(2, "Blob.cpp", 130, "iStartX > 0 && iStartX < m_iWorldSize") == 1 )
      {
        __debugbreak();
      }
      if ( (iStartY <= 0 || iStartY >= this->m_iWorldSize) && BBSupportDbgReport(2, "Blob.cpp", 131, "iStartY > 0 && iStartY < m_iWorldSize") == 1 )
      {
        __debugbreak();
      }
      while ( iCurrentX != iEndX || iCurrentY != iEndY )
      {
        v2 = j__abs(iEndY - iCurrentY);
        v1 = j__abs(iEndX - iCurrentX);
        NextDirection = CBlob::getNextDirection(this, v1, v2);
        switch ( NextDirection )
        {
          case 1:
            if ( iEndX > iCurrentX && iCurrentX < this->m_iWorldSize - 1 )
            {
              ++iCurrentX;
            }
            if ( iEndX < iCurrentX && iCurrentX > 0 )
            {
              --iCurrentX;
            }
            break;
          case 2:
            if ( iEndX >= iCurrentX || iEndY <= iCurrentY || iCurrentY >= this->m_iWorldSize - 1 )
            {
              if ( iEndX < iCurrentX || iEndY < iCurrentY || iCurrentX >= this->m_iWorldSize - 1 || iCurrentY >= this->m_iWorldSize - 1 )
              {
                if ( iEndX <= iCurrentX || iEndY >= iCurrentY || iCurrentY <= 0 )
                {
                  if ( iEndX <= iCurrentX && iEndY <= iCurrentY && iCurrentX > 0 && iCurrentY > 0 )
                  {
                    --iCurrentX;
                    --iCurrentY;
                  }
                }
                else
                {
                  --iCurrentY;
                }
              }
              else
              {
                ++iCurrentX;
                ++iCurrentY;
              }
            }
            else
            {
              ++iCurrentY;
            }
            break;
          case 3:
            if ( iEndX > iCurrentX || iEndY < iCurrentY || iCurrentX <= 0 )
            {
              if ( iEndX <= iCurrentX || iEndY <= iCurrentY || iCurrentY >= this->m_iWorldSize - 1 )
              {
                if ( iEndX < iCurrentX || iEndY > iCurrentY || iCurrentX >= this->m_iWorldSize - 1 )
                {
                  if ( iEndX < iCurrentX && iEndY < iCurrentY && iCurrentY > 0 )
                  {
                    --iCurrentY;
                  }
                }
                else
                {
                  ++iCurrentX;
                }
              }
              else
              {
                ++iCurrentY;
              }
            }
            else
            {
              --iCurrentX;
            }
            break;
        }
        if ( iCurrentX >= this->m_iWorldSize && BBSupportDbgReport(2, "Blob.cpp", 195, "iCurrentX < m_iWorldSize") == 1 )
        {
          __debugbreak();
        }
        if ( iCurrentX <= 0 && BBSupportDbgReport(2, "Blob.cpp", 196, "iCurrentX > 0") == 1 )
        {
          __debugbreak();
        }
        if ( iCurrentY >= this->m_iWorldSize && BBSupportDbgReport(2, "Blob.cpp", 197, "iCurrentY < m_iWorldSize") == 1 )
        {
          __debugbreak();
        }
        if ( iCurrentY <= 0 && BBSupportDbgReport(2, "Blob.cpp", 198, "iCurrentY > 0") == 1 )
        {
          __debugbreak();
        }
        this->processPoint(this, iCurrentX, iCurrentY);
      }
    }
    this->fillBlob(this, this->m_iMinX + (this->m_iMaxX - this->m_iMinX) / 2, this->m_iMinY + (this->m_iMaxY - this->m_iMinY) / 2);
  }
}


// address=[0x2fc9100]
// Decompiled from void __thiscall CBlob::fillBlob(CBlob *this, int a2, int a3)
void  CBlob::fillBlob(int a2, int a3) {
  
  _DWORD v3[2]; // [esp+0h] [ebp-830h] BYREF
  int iSize; // [esp+8h] [ebp-828h]
  int iCurrentX; // [esp+Ch] [ebp-824h]
  int iCurrentY; // [esp+10h] [ebp-820h]
  int i; // [esp+14h] [ebp-81Ch]
  int v8; // [esp+18h] [ebp-818h] BYREF
  int v9; // [esp+1Ch] [ebp-814h]
  _DWORD v11[514]; // [esp+24h] [ebp-80Ch] BYREF

  iSize = this->m_iWorldSize * this->m_iWorldSize;
  TStaticFIFO<int,512>::TStaticFIFO<int,512>(v11);
  v3[0] = a2 + this->m_iWorldSize * a3;
  TStaticFIFO<int,512>::Push(v11, v3);
  this->processFillPoint(this, a2, a3);
  while ( !(unsigned __int8)TStaticFIFO<int,512>::Empty(v11) )
  {
    v9 = *(_DWORD *)TStaticFIFO<int,512>::Top(v11);
    TStaticFIFO<int,512>::Pop(v11);
    for ( i = 0;
          i < 6;
          ++i )
    {
      v8 = 0;
      v3[1] = i;
      switch ( i )
      {
        case 0:
          if ( v9 - this->m_iWorldSize - 1 >= 0 )
          {
            v8 = v9 - this->m_iWorldSize - 1;
          }
          break;
        case 1:
          if ( v9 - this->m_iWorldSize >= 0 )
          {
            v8 = v9 - this->m_iWorldSize;
          }
          break;
        case 2:
          if ( v9 - 1 >= 0 )
          {
            v8 = v9 - 1;
          }
          break;
        case 3:
          if ( v9 + 1 < iSize )
          {
            v8 = v9 + 1;
          }
          break;
        case 4:
          if ( this->m_iWorldSize + v9 < iSize )
          {
            v8 = this->m_iWorldSize + v9;
          }
          break;
        case 5:
          if ( v9 + this->m_iWorldSize + 1 < iSize )
          {
            v8 = v9 + this->m_iWorldSize + 1;
          }
          break;
        default:
          break;
      }
      iCurrentX = v8 % this->m_iWorldSize;
      iCurrentY = v8 / this->m_iWorldSize;
      if ( iCurrentX >= this->m_iWorldSize && BBSupportDbgReport(2, "Blob.cpp", 262, "iCurrentX < m_iWorldSize") == 1 )
      {
        __debugbreak();
      }
      if ( iCurrentX <= 0 && BBSupportDbgReport(2, "Blob.cpp", 263, "iCurrentX > 0") == 1 )
      {
        __debugbreak();
      }
      if ( iCurrentY >= this->m_iWorldSize && BBSupportDbgReport(2, "Blob.cpp", 264, "iCurrentY < m_iWorldSize") == 1 )
      {
        __debugbreak();
      }
      if ( iCurrentY <= 0 && BBSupportDbgReport(2, "Blob.cpp", 265, "iCurrentY > 0") == 1 )
      {
        __debugbreak();
      }
      if ( !CCheckLayer::getPoint(this->m_pCheckLayer, iCurrentX - this->m_iU3, iCurrentY - this->m_iU4) )
      {
        TStaticFIFO<int,512>::Push(v11, &v8);
        this->processFillPoint(this, iCurrentX, iCurrentY);
      }
    }
  }
}


// address=[0x2fc9490]
// Decompiled from int __thiscall CBlob::getNextDirection(CBlob *this, int a2, int a3)
int  CBlob::getNextDirection(int a2, int a3) {
  
  signed int v4; // [esp+Ch] [ebp-Ch]
  int v5; // [esp+10h] [ebp-8h]
  int v6; // [esp+14h] [ebp-4h]

  v4 = CRandom16::Rand(g_pRand) % 0x64;
  if ( a2 >= a3 )
  {
    v6 = (int)abs(80.0 - (float)((float)((float)a3 / (float)a2) * 100.0));
  }
  else
  {
    v6 = (int)abs(80.0 - (float)((float)((float)a2 / (float)a3) * 100.0));
  }
  if ( v6 >= 40 )
  {
    v5 = (80 - v6) / 3;
  }
  else
  {
    v5 = v6 + 10;
  }
  if ( v4 >= 0 && v4 < v5 )
  {
    return 1;
  }
  if ( v4 >= v5 && v4 < v6 + v5 )
  {
    return 2;
  }
  if ( v4 < v6 + v5 || v4 >= 100 )
  {
    return -1;
  }
  return 3;
}


// address=[0x2fc95d0]
// Decompiled from void __thiscall CBlob::processPoint(CBlob *this, int _iX, int _iY)
void  CBlob::processPoint(int _iX, int _iY) {
  
  CCheckLayer::setPoint(this->m_pCheckLayer, _iX - this->m_iU3, _iY - this->m_iU4, 1);
}


