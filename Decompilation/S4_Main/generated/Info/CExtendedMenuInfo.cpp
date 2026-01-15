#include "CExtendedMenuInfo.h"

// Definitions for class CExtendedMenuInfo

// address=[0x1454560]
// Decompiled from CExtendedMenuInfo *__thiscall CExtendedMenuInfo::CExtendedMenuInfo(CExtendedMenuInfo *this)
 CExtendedMenuInfo::CExtendedMenuInfo(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CExtendedMenuInfo::_vftable_;
  return this;
}


// address=[0x1454b90]
// Decompiled from int __thiscall CExtendedMenuInfo::Size(CExtendedMenuInfo *this)
unsigned int  CExtendedMenuInfo::Size(void)const {
  
  return 52;
}


