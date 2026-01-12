#include "CSoldierInfo.h"

// Definitions for class CSoldierInfo

// address=[0x14548c0]
// Decompiled from CSoldierInfo *__thiscall CSoldierInfo::CSoldierInfo(CSoldierInfo *this)

 CSoldierInfo::CSoldierInfo(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CSoldierInfo::_vftable_;
  return this;
}


// address=[0x1454dd0]
// Decompiled from int __thiscall CSoldierInfo::Size(CSoldierInfo *this)

unsigned int  CSoldierInfo::Size(void)const {
  
  return 152;
}


