#include "CFerryLoadInfo.h"

// Definitions for class CFerryLoadInfo

// address=[0x14545c0]
// Decompiled from CFerryLoadInfo *__thiscall CFerryLoadInfo::CFerryLoadInfo(CFerryLoadInfo *this)

 CFerryLoadInfo::CFerryLoadInfo(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CFerryLoadInfo::_vftable_;
  return this;
}


// address=[0x1454bd0]
// Decompiled from int __thiscall CFerryLoadInfo::Size(CFerryLoadInfo *this)

unsigned int  CFerryLoadInfo::Size(void)const {
  
  return 56;
}


