#include "CSettlerProductionInfo.h"

// Definitions for class CSettlerProductionInfo

// address=[0x1454830]
// Decompiled from CSettlerProductionInfo *__thiscall CSettlerProductionInfo::CSettlerProductionInfo(CSettlerProductionInfo *this)
 CSettlerProductionInfo::CSettlerProductionInfo(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CSettlerProductionInfo::_vftable_;
  return this;
}


// address=[0x1454d70]
// Decompiled from int __thiscall CSettlerProductionInfo::Size(CSettlerProductionInfo *this)
unsigned int  CSettlerProductionInfo::Size(void)const {
  
  return 160;
}


