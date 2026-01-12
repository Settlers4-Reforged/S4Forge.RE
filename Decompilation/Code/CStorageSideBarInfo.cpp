#include "CStorageSideBarInfo.h"

// Definitions for class CStorageSideBarInfo

// address=[0x1454950]
// Decompiled from CStorageSideBarInfo *__thiscall CStorageSideBarInfo::CStorageSideBarInfo(CStorageSideBarInfo *this)

 CStorageSideBarInfo::CStorageSideBarInfo(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CStorageSideBarInfo::_vftable_;
  return this;
}


// address=[0x1454e30]
// Decompiled from int __thiscall CStorageSideBarInfo::Size(CStorageSideBarInfo *this)

unsigned int  CStorageSideBarInfo::Size(void)const {
  
  return 96;
}


