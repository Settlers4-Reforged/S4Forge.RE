#include "CBuildingSiteInfo.h"

// Definitions for class CBuildingSiteInfo

// address=[0x1454500]
// Decompiled from CBuildingSiteInfo *__thiscall CBuildingSiteInfo::CBuildingSiteInfo(CBuildingSiteInfo *this)

 CBuildingSiteInfo::CBuildingSiteInfo(void) {
  
  CBuildingInfo::CBuildingInfo(this);
  *(_DWORD *)this = &CBuildingSiteInfo::_vftable_;
  return this;
}


// address=[0x1454b50]
// Decompiled from int __thiscall CBuildingSiteInfo::Size(CBuildingSiteInfo *this)

unsigned int  CBuildingSiteInfo::Size(void)const {
  
  return 36;
}


