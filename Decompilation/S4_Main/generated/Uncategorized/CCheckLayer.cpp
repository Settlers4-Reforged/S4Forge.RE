#include "CCheckLayer.h"

// Definitions for class CCheckLayer

// address=[0x2fc85d0]
// Decompiled from CCheckLayer *__thiscall CCheckLayer::CCheckLayer(CCheckLayer *this, int a2)
 CCheckLayer::CCheckLayer(int a2) {
  
  this->m_iWidth = a2;
  this->m_iHeight = a2;
  this->m_vLayer = (__int16 *)operator new[](2 * this->m_iHeight * this->m_iWidth);
  return this;
}


// address=[0x2fc8630]
// Decompiled from int __thiscall CCheckLayer::~CCheckLayer(void **this)
 CCheckLayer::~CCheckLayer(void) {
  
  return operator delete[](*this);
}


// address=[0x2fc8660]
// Decompiled from __int16 __thiscall CCheckLayer::getPoint(CCheckLayer *this, int a2, int a3)
unsigned short  CCheckLayer::getPoint(int a2, int a3) {
  
  if ( a2 >= *((_DWORD *)this + 1) && BBSupportDbgReport(2, "CCheckLayer.cpp", 35, "_iX < m_iSizeX") == 1 )
  {
    __debugbreak();
  }
  if ( a2 < 0 && BBSupportDbgReport(2, "CCheckLayer.cpp", 36, "_iX >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= *((_DWORD *)this + 2) && BBSupportDbgReport(2, "CCheckLayer.cpp", 37, "_iY < m_iSizeY") == 1 )
  {
    __debugbreak();
  }
  if ( a3 < 0 && BBSupportDbgReport(2, "CCheckLayer.cpp", 38, "_iY >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( a2 >= *((_DWORD *)this + 1) || a2 < 0 || a3 >= *((_DWORD *)this + 2) || a3 < 0 )
  {
    return 0;
  }
  else
  {
    return *(_WORD *)(*(_DWORD *)this + 2 * (a2 + *((_DWORD *)this + 1) * a3));
  }
}


// address=[0x2fc8740]
// Decompiled from void __thiscall CCheckLayer::setPoint(CCheckLayer *this, int _iX, int _iY, __int16 a4)
void  CCheckLayer::setPoint(int _iX, int _iY, unsigned short a4) {
  
  if ( _iX >= this->m_iWidth && BBSupportDbgReport(2, "CCheckLayer.cpp", 59, "_iX < m_iSizeX") == 1 )
  {
    __debugbreak();
  }
  if ( _iX < 0 && BBSupportDbgReport(2, "CCheckLayer.cpp", 60, "_iX >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iY >= this->m_iHeight && BBSupportDbgReport(2, "CCheckLayer.cpp", 61, "_iY < m_iSizeY") == 1 )
  {
    __debugbreak();
  }
  if ( _iY < 0 && BBSupportDbgReport(2, "CCheckLayer.cpp", 62, "_iY >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( _iX < this->m_iWidth && _iX >= 0 && _iY < this->m_iHeight && _iY >= 0 )
  {
    this->m_vLayer[_iX + this->m_iWidth * _iY] = a4;
  }
}


// address=[0x2fc8820]
// Decompiled from void *__thiscall CCheckLayer::clear(CCheckLayer *this)
void  CCheckLayer::clear(void) {
  
  return memset(this->m_vLayer, 0, 2 * this->m_iHeight * this->m_iWidth);
}


