#include "CResourceFilter.h"

// Definitions for class CResourceFilter

// address=[0x2f56770]
// Decompiled from CResourceFilter *__thiscall CResourceFilter::CResourceFilter(CResourceFilter *this, int a2, int a3, int a4)
 CResourceFilter::CResourceFilter(int,int,int) {
  
  IFilterEntry::IFilterEntry(this);
  *(_DWORD *)this = &CResourceFilter::_vftable_;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = a3;
  *((_DWORD *)this + 5) = a4;
  return this;
}


// address=[0x2f567b0]
// Decompiled from void __thiscall CResourceFilter::~CResourceFilter(CResourceFilter *this)
 CResourceFilter::~CResourceFilter(void) {
  
  *(_DWORD *)this = &CResourceFilter::_vftable_;
  IFilterEntry::~IFilterEntry(this);
}


// address=[0x2f567d0]
// Decompiled from double __thiscall CResourceFilter::GetFilterValue(CResourceFilter *this)
float  CResourceFilter::GetFilterValue(void) {
  
  return (float)*((int *)this + 5);
}


