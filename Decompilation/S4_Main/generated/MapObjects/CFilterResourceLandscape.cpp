#include "CFilterResourceLandscape.h"

// Definitions for class CFilterResourceLandscape

// address=[0x2f527d0]
// Decompiled from CFilterResourceLandscape *__thiscall CFilterResourceLandscape::CFilterResourceLandscape(  CFilterResourceLandscape *this,  int a2,  int a3,  int a4,  int a5,  int a6)
 CFilterResourceLandscape::CFilterResourceLandscape(int,int,int,int,int) {
  
  IFilterEntry::IFilterEntry(this);
  *(_DWORD *)this = &CFilterResourceLandscape::_vftable_;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = a3;
  *((_DWORD *)this + 5) = a4;
  *((_DWORD *)this + 6) = a5;
  *((_DWORD *)this + 7) = a6;
  return this;
}


// address=[0x2f52820]
// Decompiled from void __thiscall CFilterResourceLandscape::~CFilterResourceLandscape(CFilterResourceLandscape *this)
 CFilterResourceLandscape::~CFilterResourceLandscape(void) {
  
  *(_DWORD *)this = &CFilterResourceLandscape::_vftable_;
  IFilterEntry::~IFilterEntry(this);
}


// address=[0x2f52840]
// Decompiled from double __thiscall CFilterResourceLandscape::GetFilterValue(CFilterResourceLandscape *this)
float  CFilterResourceLandscape::GetFilterValue(void) {
  
  return (float)(*((_DWORD *)this + 5) + 1000 - 3 * *((_DWORD *)this + 7));
}


