#include "CSmallTempleInfo.h"

// Definitions for class CSmallTempleInfo

// address=[0x1454890]
// Decompiled from CSmallTempleInfo *__thiscall CSmallTempleInfo::CSmallTempleInfo(CSmallTempleInfo *this)

 CSmallTempleInfo::CSmallTempleInfo(void) {
  
  CBuildingInfo::CBuildingInfo(this);
  *(_DWORD *)this = &CSmallTempleInfo::_vftable_;
  return this;
}


// address=[0x1454db0]
// Decompiled from int __thiscall CSmallTempleInfo::Size(CSmallTempleInfo *this)

unsigned int  CSmallTempleInfo::Size(void)const {
  
  return 28;
}


