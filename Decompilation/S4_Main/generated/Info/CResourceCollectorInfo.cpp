#include "all_headers.h"

// Definitions for class CResourceCollectorInfo

// address=[0x14547d0]
// Decompiled from CResourceCollectorInfo *__thiscall CResourceCollectorInfo::CResourceCollectorInfo(CResourceCollectorInfo *this)
 CResourceCollectorInfo::CResourceCollectorInfo(void) {
  
  CBuildingInfo::CBuildingInfo(this);
  *(_DWORD *)this = &CResourceCollectorInfo::_vftable_;
  return this;
}


// address=[0x1454d30]
// Decompiled from int __thiscall CResourceCollectorInfo::Size(CResourceCollectorInfo *this)
unsigned int  CResourceCollectorInfo::Size(void)const {
  
  return 24;
}


