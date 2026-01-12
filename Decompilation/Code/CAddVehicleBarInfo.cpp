#include "CAddVehicleBarInfo.h"

// Definitions for class CAddVehicleBarInfo

// address=[0x1454440]
// Decompiled from CAddVehicleBarInfo *__thiscall CAddVehicleBarInfo::CAddVehicleBarInfo(CAddVehicleBarInfo *this)
 CAddVehicleBarInfo::CAddVehicleBarInfo(void) {
  
  CInfoExchange::CInfoExchange(this);
  *(_DWORD *)this = &CAddVehicleBarInfo::_vftable_;
  return this;
}


// address=[0x1454af0]
// Decompiled from int __thiscall CAddVehicleBarInfo::Size(CAddVehicleBarInfo *this)
unsigned int  CAddVehicleBarInfo::Size(void)const {
  
  return 20;
}


