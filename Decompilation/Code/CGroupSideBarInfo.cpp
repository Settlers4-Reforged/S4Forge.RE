#include "CGroupSideBarInfo.h"

// Definitions for class CGroupSideBarInfo

// address=[0x1454650]
// Decompiled from CGroupSideBarInfo *__thiscall CGroupSideBarInfo::CGroupSideBarInfo(CGroupSideBarInfo *this)
 CGroupSideBarInfo::CGroupSideBarInfo(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CGroupSideBarInfo::_vftable_;
  return this;
}


// address=[0x1454c30]
// Decompiled from int __thiscall CGroupSideBarInfo::Size(CGroupSideBarInfo *this)
unsigned int  CGroupSideBarInfo::Size(void)const {
  
  return 44;
}


