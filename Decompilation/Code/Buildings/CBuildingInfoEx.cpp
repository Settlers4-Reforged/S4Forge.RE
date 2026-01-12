#include "CBuildingInfoEx.h"

// Definitions for class CBuildingInfoEx

// address=[0x14544d0]
// Decompiled from CBuildingInfoEx *__thiscall CBuildingInfoEx::CBuildingInfoEx(CBuildingInfoEx *this)
 CBuildingInfoEx::CBuildingInfoEx(void) {
  
  CBuildingInfo::CBuildingInfo(this);
  *(_DWORD *)this = &CBuildingInfoEx::_vftable_;
  return this;
}


// address=[0x1454b30]
// Decompiled from int __thiscall CBuildingInfoEx::Size(CBuildingInfoEx *this)
unsigned int  CBuildingInfoEx::Size(void)const {
  
  return 20;
}


