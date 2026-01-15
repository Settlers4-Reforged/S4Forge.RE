#include "CVehicleProductionInfo.h"

// Definitions for class CVehicleProductionInfo

// address=[0x1454a20]
// Decompiled from CVehicleProductionInfo *__thiscall CVehicleProductionInfo::CVehicleProductionInfo(CVehicleProductionInfo *this)
 CVehicleProductionInfo::CVehicleProductionInfo(void) {
  
  CBuildingInfo::CBuildingInfo(this);
  *(_DWORD *)this = &CVehicleProductionInfo::_vftable_;
  return this;
}


// address=[0x1454eb0]
// Decompiled from int __thiscall CVehicleProductionInfo::Size(CVehicleProductionInfo *this)
unsigned int  CVehicleProductionInfo::Size(void)const {
  
  return 40;
}


