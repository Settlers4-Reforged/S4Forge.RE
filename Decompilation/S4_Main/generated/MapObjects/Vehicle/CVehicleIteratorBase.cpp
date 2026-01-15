#include "CVehicleIteratorBase.h"

// Definitions for class CVehicleIteratorBase

// address=[0x1317500]
// Decompiled from int __thiscall CVehicleIteratorBase::VehicleId(CVehicleIteratorBase *this)
int  CVehicleIteratorBase::VehicleId(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x1317520]
// Decompiled from int __thiscall CVehicleIteratorBase::VehicleType(CVehicleIteratorBase *this)
int  CVehicleIteratorBase::VehicleType(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x1317400]
// Decompiled from CVehicleIteratorBase *__thiscall CVehicleIteratorBase::Init(CVehicleIteratorBase *this, int a2)
void  CVehicleIteratorBase::Init(int) {
  
  CVehicleIteratorBase *result; // eax

  result = this;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = 0;
  return result;
}


// address=[0x1317540]
// Decompiled from bool __thiscall CVehicleIteratorBase::VehicleValid(CVehicleIteratorBase *this, int a2)
bool  CVehicleIteratorBase::VehicleValid(int) {
  
  struct IEntity *v2; // eax
  bool v4; // [esp+4h] [ebp-4h]

  v4 = 1;
  if ( !a2 )
    return v4;
  v2 = CMapObjectMgr::Entity(a2);
  if ( ((unsigned int)&loc_3000000 & IEntity::Flags(v2)) == 0 )
    return 0;
  return v4;
}


