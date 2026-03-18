#include "CVWList.h"

#include "CBB/CBBSupport.h"
#include "World/helper.h"

// Definitions for class CVWList

// address=[0x1334ec0]
// Decompiled from CVWList *__thiscall CVWList::CVWList(CVWList *this, unsigned int iX, unsigned int iY, unsigned int iRadius)
CVWList::CVWList(int iX, int iY, int iRadius) {
  this->CalculateOverlappingSquares(iX, iY, iRadius);
}


// address=[0x1335b10]
// Decompiled from const struct CVWList::SVW *__thiscall CVWList::operator[](CVWList *this, int a2)
CVWList::SVW const &CVWList::operator[](int a2) const {
  return this->m_aVW[a2];
}


// address=[0x1336840]
// Decompiled from int __thiscall CVWList::Size(CVWList *this)
int CVWList::Size(void) const {
  return this->m_iSize;
}

int __cdecl sub_15E1D20(int a1, int a2) {
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  int v5; // [esp+8h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-Ch]
  // [esp+10h] [ebp-8h]
  // [esp+14h] [ebp-4h]

  int v7 = CWorldManager::Width() >> 4;
  int v8 = 0;
  if(a1 > 1) {
    if(a1 >= v7 - 2) {
      if(a1 == v7 - 2)
        v5 = 0x21084200;
      else
        v5 = 0x318C6300;
      v8 = v5;
    }
  } else {
    if(a1 == 1)
      v6 = 34636832;
    else
      v6 = 0x6318C60;
    v8 = v6;
  }
  if(a2 > 1) {
    if(a2 >= v7 - 2) {
      if(a2 == v7 - 2)
        v3 = 0x3E000000;
      else
        v3 = 0x3FF00000;
      return v3 | v8;
    }
  } else {
    if(a2 == 1)
      v4 = 0x3E0;
    else
      v4 = 0x7FE0;
    return v4 | v8;
  }
  return v8;
}

bool __cdecl sub_15E1DF0(int &a1, int a2, bool a3) {
  int v4; // [esp+4h] [ebp-4h]

  if(a3)
    v4 = 0;
  else
    v4 = a2;
  a1 |= v4;
  return (a2 & a1) == 0;
}

bool __cdecl sub_15E1E40(int &a1, int a2, int a3, int a4, int a5, int a6) {
  int v7; // [esp+8h] [ebp-14h]
  int v8; // [esp+Ch] [ebp-10h]
  // [esp+1Bh] [ebp-1h]

  if(a2) {
    int v10;
    if(a2 < 0)
      v10 = 16 * a2 + 15;
    else
      v10 = 16 * a2;
    v7 = v10;
  } else {
    v7 = a4;
  }
  if(a3) {
    int v9;
    if(a3 < 0)
      v9 = 16 * a3 + 15;
    else
      v9 = 16 * a3;
    v8 = v9;
  } else {
    v8 = a5;
  }
  bool v11 = Grid::Distance(v7 - a4, v8 - a5) <= a6;
  return sub_15E1DF0(a1, 32 << (a2 + 5 * (a3 + 2) + 2), v11);
}

// address=[0x15de830]
// Decompiled from void __thiscall CVWList::CalculateOverlappingSquares(  CVWList *this,  unsigned int _iX,  unsigned int _iY,  unsigned int _iRadius)
void CVWList::CalculateOverlappingSquares(int _iX, int _iY, int _iRadius) {
  // [esp+8h] [ebp-18h]
  // [esp+Ch] [ebp-14h]
  int v6; // [esp+10h] [ebp-10h] BYREF
  // [esp+14h] [ebp-Ch]
  // [esp+18h] [ebp-8h]

  if(!CWorldManager::InWorld(_iX, _iY)
     && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 161, "g_cWorld.InWorld(_iX, _iY)") == 1) {
    __debugbreak();
  }
  if(_iRadius > 0x20 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 162, "(_iRadius >=0) && (_iRadius <= 32)") == 1)
    __debugbreak();
  int iV = Squares::XYToVW(_iX);
  int iW = Squares::XYToVW(_iY);
  v6 = sub_15E1D20(iV, iW);
  for(int i = -2; i <= 2; ++i) {
    for(int j = -2; j <= 2; ++j) {
      if(sub_15E1E40(v6, j, i, _iX & 0xF, _iY & 0xF, _iRadius))
        this->PushEx(v6, j + iV, i + iW);
    }
  }
  this->m_iSize = v6 & 0x1F;
  this->m_aVW[this->m_iSize].m_iV = -1;
  this->m_aVW[this->m_iSize].m_iW = -1;
}


// address=[0x15e2cf0]
// Decompiled from void __thiscall CVWList::PushEx(CVWList *this, int *a2, int a3, int a4)
void CVWList::PushEx(int &a2, int a3, int a4) {
  this->m_aVW[a2 & 0x1F].m_iV = a3;
  this->m_aVW[a2++ & 0x1F].m_iW = a4;
}


