#include "CCheckLayer.h"

// Definitions for class CCheckLayer

// address=[0x2fc85d0]
// Decompiled from CCheckLayer *__thiscall CCheckLayer::CCheckLayer(CCheckLayer *this, int a2)

 CCheckLayer::CCheckLayer(int) {
  
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 2) = a2;
  *(_DWORD *)this = operator new[](2 * *((_DWORD *)this + 2) * *((_DWORD *)this + 1));
  return this;
}


// address=[0x2fc8630]
// Decompiled from int __thiscall CCheckLayer::~CCheckLayer(void **this)

 CCheckLayer::~CCheckLayer(void) {
  
  return operator delete[](*this);
}


// address=[0x2fc8660]
// Decompiled from __int16 __thiscall CCheckLayer::getPoint(CCheckLayer *this, int a2, int a3)

unsigned short  CCheckLayer::getPoint(int,int) {
  
  if ( a2 >= *((_DWORD *)this + 1) && BBSupportDbgReport(2, "CCheckLayer.cpp", 35, "_iX < m_iSizeX") == 1 )
    __debugbreak();
  if ( a2 < 0 && BBSupportDbgReport(2, "CCheckLayer.cpp", 36, "_iX >= 0") == 1 )
    __debugbreak();
  if ( a3 >= *((_DWORD *)this + 2) && BBSupportDbgReport(2, "CCheckLayer.cpp", 37, "_iY < m_iSizeY") == 1 )
    __debugbreak();
  if ( a3 < 0 && BBSupportDbgReport(2, "CCheckLayer.cpp", 38, "_iY >= 0") == 1 )
    __debugbreak();
  if ( a2 >= *((_DWORD *)this + 1) || a2 < 0 || a3 >= *((_DWORD *)this + 2) || a3 < 0 )
    return 0;
  else
    return *(_WORD *)(*(_DWORD *)this + 2 * (a2 + *((_DWORD *)this + 1) * a3));
}


// address=[0x2fc8740]
// Decompiled from int __thiscall CCheckLayer::setPoint(CCheckLayer *this, int a2, int a3, unsigned __int16 a4)

void  CCheckLayer::setPoint(int,int,unsigned short) {
  
  int result; // eax

  if ( a2 >= *((_DWORD *)this + 1) && BBSupportDbgReport(2, "CCheckLayer.cpp", 59, "_iX < m_iSizeX") == 1 )
    __debugbreak();
  if ( a2 < 0 && BBSupportDbgReport(2, "CCheckLayer.cpp", 60, "_iX >= 0") == 1 )
    __debugbreak();
  if ( a3 >= *((_DWORD *)this + 2) && BBSupportDbgReport(2, "CCheckLayer.cpp", 61, "_iY < m_iSizeY") == 1 )
    __debugbreak();
  if ( a3 < 0 && BBSupportDbgReport(2, "CCheckLayer.cpp", 62, "_iY >= 0") == 1 )
    __debugbreak();
  result = a2;
  if ( a2 >= *((_DWORD *)this + 1) || a2 < 0 || a3 >= *((_DWORD *)this + 2) || a3 < 0 )
    return result;
  result = *(_DWORD *)this;
  *(_WORD *)(*(_DWORD *)this + 2 * (a2 + *((_DWORD *)this + 1) * a3)) = a4;
  return result;
}


// address=[0x2fc8820]
// Decompiled from void *__thiscall CCheckLayer::clear(void **this)

void  CCheckLayer::clear(void) {
  
  return j__memset(*this, 0, 2 * (_DWORD)this[2] * (_DWORD)this[1]);
}


