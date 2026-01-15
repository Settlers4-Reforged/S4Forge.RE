#include "CFilterNearCustomer.h"

// Definitions for class CFilterNearCustomer

// address=[0x2f58ab0]
// Decompiled from IFilterEntry *__thiscall CFilterNearCustomer::CFilterNearCustomer(IFilterEntry *this, int a2, int a3, int a4, int a5)
 CFilterNearCustomer::CFilterNearCustomer(int,int,enum T_BUILD_LEVEL,int) {
  
  IFilterEntry::IFilterEntry(this);
  *(_DWORD *)this = &CFilterNearCustomer::_vftable_;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = a3;
  *((_DWORD *)this + 5) = a4;
  *((_DWORD *)this + 6) = a5;
  return this;
}


// address=[0x2f58b00]
// Decompiled from double __thiscall CFilterNearCustomer::GetFilterValue(CFilterNearCustomer *this)
float  CFilterNearCustomer::GetFilterValue(void) {
  
  return (float)(1000 - *((_DWORD *)this + 3));
}


// address=[0x2f5a090]
// Decompiled from void __thiscall CFilterNearCustomer::~CFilterNearCustomer(CFilterNearCustomer *this)
 CFilterNearCustomer::~CFilterNearCustomer(void) {
  
  *(_DWORD *)this = &CFilterNearCustomer::_vftable_;
  IFilterEntry::~IFilterEntry(this);
}


