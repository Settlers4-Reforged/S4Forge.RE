#include "CResourceUpgradeInfo.h"

// Definitions for class CResourceUpgradeInfo

// address=[0x1454800]
// Decompiled from CResourceUpgradeInfo *__thiscall CResourceUpgradeInfo::CResourceUpgradeInfo(CResourceUpgradeInfo *this)
 CResourceUpgradeInfo::CResourceUpgradeInfo(void) {
  
  CBuildingInfo::CBuildingInfo(this);
  *(_DWORD *)this = &CResourceUpgradeInfo::_vftable_;
  return this;
}


// address=[0x1454d50]
// Decompiled from int __thiscall CResourceUpgradeInfo::Size(CResourceUpgradeInfo *this)
unsigned int  CResourceUpgradeInfo::Size(void)const {
  
  return 52;
}


