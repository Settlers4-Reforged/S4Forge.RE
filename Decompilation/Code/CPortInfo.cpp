#include "CPortInfo.h"

// Definitions for class CPortInfo

// address=[0x14547a0]
// Decompiled from CPortInfo *__thiscall CPortInfo::CPortInfo(CPortInfo *this)

 CPortInfo::CPortInfo(void) {
  
  CBuildingInfo::CBuildingInfo(this);
  *(_DWORD *)this = &CPortInfo::_vftable_;
  return this;
}


// address=[0x1454d10]
// Decompiled from int __thiscall CPortInfo::Size(CPortInfo *this)

unsigned int  CPortInfo::Size(void)const {
  
  return 52;
}


