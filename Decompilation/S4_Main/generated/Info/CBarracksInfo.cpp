#if FALSE
#include "CBarracksInfo.h"

// Definitions for class CBarracksInfo

// address=[0x1454470]
// Decompiled from CBarracksInfo *__thiscall CBarracksInfo::CBarracksInfo(CBarracksInfo *this)
 CBarracksInfo::CBarracksInfo(void) {
  
  CBuildingInfo::CBuildingInfo(this);
  this->__vftable = (CInfoExchange_vtbl *)&CBarracksInfo::_vftable_;
  return this;
}


// address=[0x1454b10]
// Decompiled from int __thiscall CBarracksInfo::Size(CBarracksInfo *this)
unsigned int  CBarracksInfo::Size(void)const {
  
  return 0x20;
}


#endif // Already implemented
