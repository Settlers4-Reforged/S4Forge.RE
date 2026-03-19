#if FALSE
#include "CVWList.h"

// Definitions for class CVWList

// address=[0x1334ec0]
// Decompiled from CVWList *__thiscall CVWList::CVWList(CVWList *this, unsigned int iX, unsigned int iY, unsigned int iRadius)
 CVWList::CVWList(int iX, int iY, int iRadius) {
  
  CVWList::CalculateOverlappingSquares(this, iX, iY, iRadius);
  return this;
}


// address=[0x1335b10]
// Decompiled from const struct CVWList::SVW *__thiscall CVWList::operator[](CVWList *this, int a2)
struct CVWList::SVW const &  CVWList::operator[](int a2)const {
  
  return &this->m_aVW[a2];
}


// address=[0x1336840]
// Decompiled from int __thiscall CVWList::Size(CVWList *this)
int  CVWList::Size(void)const {
  
  return this->m_iSize;
}


// address=[0x15de830]
// Decompiled from void __thiscall CVWList::CalculateOverlappingSquares(  CVWList *this,  unsigned int _iX,  unsigned int _iY,  unsigned int _iRadius)
void  CVWList::CalculateOverlappingSquares(int _iX, int _iY, int _iRadius) {
  
  int iV; // [esp+8h] [ebp-18h]
  int iW; // [esp+Ch] [ebp-14h]
  int v6; // [esp+10h] [ebp-10h] BYREF
  int j; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 161, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( _iRadius > 0x20 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 162, "(_iRadius >=0) && (_iRadius <= 32)") == 1 )
    __debugbreak();
  iV = Squares::XYToVW(_iX);
  iW = Squares::XYToVW(_iY);
  v6 = sub_15E1D20(iV, iW);
  for ( i = -2; i <= 2; ++i )
  {
    for ( j = -2; j <= 2; ++j )
    {
      if ( sub_15E1E40(&v6, j, i, _iX & 0xF, _iY & 0xF, _iRadius) )
        CVWList::PushEx(this, &v6, j + iV, i + iW);
    }
  }
  this->m_iSize = v6 & 0x1F;
  this->m_aVW[this->m_iSize].m_iV = -1;
  this->m_aVW[this->m_iSize].m_iW = -1;
}


// address=[0x15e2cf0]
// Decompiled from void __thiscall CVWList::PushEx(CVWList *this, int *a2, int a3, int a4)
void  CVWList::PushEx(int & a2, int a3, int a4) {
  
  this->m_aVW[*a2 & 0x1F].m_iV = a3;
  this->m_aVW[(*a2)++ & 0x1F].m_iW = a4;
}


#endif // Already implemented
