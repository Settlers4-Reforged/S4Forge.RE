#include "CBuildingIteratorBase.h"

// Definitions for class CBuildingIteratorBase

// address=[0x1317300]
// Decompiled from int __thiscall CBuildingIteratorBase::BuildingId(CBuildingIteratorBase *this)
int  CBuildingIteratorBase::BuildingId(void)const {
  
  return this->m_iBuildingId;
}


// address=[0x1317320]
// Decompiled from int __thiscall CBuildingIteratorBase::BuildingType(CBuildingIteratorBase *this)
int  CBuildingIteratorBase::BuildingType(void)const {
  
  return this->m_iBuildingType;
}


// address=[0x1317340]
// Decompiled from bool __thiscall CBuildingIteratorBase::BuildingValid(CBuildingIteratorBase *this, int a2)
bool  CBuildingIteratorBase::BuildingValid(int a2) {
  
  struct IEntity *v2; // eax
  bool v4; // [esp+4h] [ebp-4h]

  v4 = 1;
  if ( !a2 )
  {
    return v4;
  }
  v2 = CMapObjectMgr::Entity(a2);
  if ( (IEntity::Flags(v2) & ENTITY_FLAG_AliveMask) == 0 )
  {
    return 0;
  }
  return v4;
}


// address=[0x13173a0]
// Decompiled from void __thiscall CBuildingIteratorBase::Init(CBuildingIteratorBase *this, int a2)
void  CBuildingIteratorBase::Init(int a2) {
  
  this->m_iBuildingType = a2;
  this->m_iBuildingId = 0;
}


