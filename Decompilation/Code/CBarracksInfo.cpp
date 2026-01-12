#include "CBarracksInfo.h"

// Definitions for class CBarracksInfo

// address=[0x1454470]
// Decompiled from CBarracksInfo *__thiscall CBarracksInfo::CBarracksInfo(CBarracksInfo *this)

 CBarracksInfo::CBarracksInfo(void) {
  
  CBuildingInfo::CBuildingInfo(this);
  *(_DWORD *)this = &CBarracksInfo::_vftable_;
  return this;
}


// address=[0x1454b10]
// Decompiled from int __thiscall CBarracksInfo::Size(CBarracksInfo *this)

unsigned int  CBarracksInfo::Size(void)const {
  
  return 32;
}


