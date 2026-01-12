#include "CFilterCustomer.h"

// Definitions for class CFilterCustomer

// address=[0x2f589d0]
// Decompiled from CFilterCustomer *__thiscall CFilterCustomer::CFilterCustomer(
        CFilterCustomer *this,
        CSchedule **a2,
        struct CProductivityControll *a3)

 CFilterCustomer::CFilterCustomer(class CProductivityControll *,class CProductivityControll *) {
  
  IFilterEntry::IFilterEntry(this);
  *(_DWORD *)this = &CFilterCustomer::_vftable_;
  *((_DWORD *)this + 3) = CSchedule::CalcDistance(a2[10], a2[17], *((_DWORD *)a3 + 17));
  *((_DWORD *)this + 4) = a2;
  *((_DWORD *)this + 4) = a3;
  return this;
}


// address=[0x2f58a60]
// Decompiled from void __thiscall CFilterCustomer::~CFilterCustomer(CFilterCustomer *this)

 CFilterCustomer::~CFilterCustomer(void) {
  
  *(_DWORD *)this = &CFilterCustomer::_vftable_;
  IFilterEntry::~IFilterEntry(this);
}


// address=[0x2f58a80]
// Decompiled from double __thiscall CFilterCustomer::GetFilterValue(CFilterCustomer *this)

float  CFilterCustomer::GetFilterValue(void) {
  
  return (float)(1000 - *((_DWORD *)this + 3));
}


