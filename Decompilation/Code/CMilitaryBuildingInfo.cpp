#include "CMilitaryBuildingInfo.h"

// Definitions for class CMilitaryBuildingInfo

// address=[0x1454710]
// Decompiled from CMilitaryBuildingInfo *__thiscall CMilitaryBuildingInfo::CMilitaryBuildingInfo(CMilitaryBuildingInfo *this)
 CMilitaryBuildingInfo::CMilitaryBuildingInfo(void) {
  
  CBuildingInfo::CBuildingInfo(this);
  *(_DWORD *)this = &CMilitaryBuildingInfo::_vftable_;
  return this;
}


// address=[0x1454cb0]
// Decompiled from int __thiscall CMilitaryBuildingInfo::Size(CMilitaryBuildingInfo *this)
unsigned int  CMilitaryBuildingInfo::Size(void)const {
  
  return 60;
}


