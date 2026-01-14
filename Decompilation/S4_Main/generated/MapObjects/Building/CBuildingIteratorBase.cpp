#include "all_headers.h"

// Definitions for class CBuildingIteratorBase

// address=[0x1317300]
// Decompiled from int __thiscall CBuildingIteratorBase::BuildingId(CBuildingIteratorBase *this)
int  CBuildingIteratorBase::BuildingId(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x1317320]
// Decompiled from int __thiscall CBuildingIteratorBase::BuildingType(CBuildingIteratorBase *this)
int  CBuildingIteratorBase::BuildingType(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x1317340]
// Decompiled from bool __thiscall CBuildingIteratorBase::BuildingValid(CBuildingIteratorBase *this, int a2)
bool  CBuildingIteratorBase::BuildingValid(int) {
  
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


// address=[0x13173a0]
// Decompiled from CBuildingIteratorBase *__thiscall CBuildingIteratorBase::Init(CBuildingIteratorBase *this, int a2)
void  CBuildingIteratorBase::Init(int) {
  
  CBuildingIteratorBase *result; // eax

  result = this;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = 0;
  return result;
}


