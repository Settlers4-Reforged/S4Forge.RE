#include "CStorageInfo.h"

// Definitions for class CStorageInfo

// address=[0x1454920]
// Decompiled from CStorageInfo *__thiscall CStorageInfo::CStorageInfo(CStorageInfo *this)

 CStorageInfo::CStorageInfo(void) {
  
  CBuildingInfo::CBuildingInfo(this);
  *(_DWORD *)this = &CStorageInfo::_vftable_;
  return this;
}


// address=[0x1454e10]
// Decompiled from int __thiscall CStorageInfo::Size(CStorageInfo *this)

unsigned int  CStorageInfo::Size(void)const {
  
  return 40;
}


