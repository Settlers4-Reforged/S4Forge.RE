#include "CVehicleLoadInfo.h"

// Definitions for class CVehicleLoadInfo

// address=[0x14549f0]
// Decompiled from CVehicleLoadInfo *__thiscall CVehicleLoadInfo::CVehicleLoadInfo(CVehicleLoadInfo *this)

 CVehicleLoadInfo::CVehicleLoadInfo(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CVehicleLoadInfo::_vftable_;
  return this;
}


// address=[0x1454e90]
// Decompiled from int __thiscall CVehicleLoadInfo::Size(CVehicleLoadInfo *this)

unsigned int  CVehicleLoadInfo::Size(void)const {
  
  return 260;
}


