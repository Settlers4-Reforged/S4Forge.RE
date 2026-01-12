#include "CWeaponSideBarInfo.h"

// Definitions for class CWeaponSideBarInfo

// address=[0x1454a50]
// Decompiled from CWeaponSideBarInfo *__thiscall CWeaponSideBarInfo::CWeaponSideBarInfo(CWeaponSideBarInfo *this)

 CWeaponSideBarInfo::CWeaponSideBarInfo(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CWeaponSideBarInfo::_vftable_;
  return this;
}


// address=[0x1454ed0]
// Decompiled from int __thiscall CWeaponSideBarInfo::Size(CWeaponSideBarInfo *this)

unsigned int  CWeaponSideBarInfo::Size(void)const {
  
  return 60;
}


