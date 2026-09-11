#include "CVehicleInfo.h"

// Definitions for class CVehicleInfo

// address=[0x14549c0]
// Decompiled from CVehicleInfo *__thiscall CVehicleInfo::CVehicleInfo(CVehicleInfo *this)
 CVehicleInfo::CVehicleInfo(void) {
  
  CInfoExchange::CInfoExchange((CInfoExchange *)this);
  *(_DWORD *)this->gap_0 = &CVehicleInfo::_vftable_;
  return this;
}


// address=[0x1454e70]
// Decompiled from int __thiscall CVehicleInfo::Size(CVehicleInfo *this)
unsigned int  CVehicleInfo::Size(void)const {
  
  return 32;
}


