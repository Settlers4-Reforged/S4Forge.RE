#include "CGoodDistributionInfo.h"

// Definitions for class CGoodDistributionInfo

// address=[0x14151e0]
// Decompiled from CGoodDistributionInfo *__thiscall CGoodDistributionInfo::CGoodDistributionInfo(CGoodDistributionInfo *this)
 CGoodDistributionInfo::CGoodDistributionInfo(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CGoodDistributionInfo::_vftable_;
  *((_BYTE *)this + 56) = 0;
  *((_DWORD *)this + 16) = -1;
  return this;
}


// address=[0x1417170]
// Decompiled from int __thiscall CGoodDistributionInfo::Size(CGoodDistributionInfo *this)
unsigned int  CGoodDistributionInfo::Size(void)const {
  
  return 68;
}


