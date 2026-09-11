#include "COneBuildingTypeIterator.h"

// Definitions for class COneBuildingTypeIterator

// address=[0x1315a50]
// Decompiled from int __thiscall COneBuildingTypeIterator::Init(CBuildingIteratorBase *this, int a2, int a3)
void  COneBuildingTypeIterator::Init(int a2, int a3) {
  
  int result; // eax

  CBuildingIteratorBase::Init(this, a3);
  *((_DWORD *)this + 2) = a2;
  return result;
}


// address=[0x1315a80]
// Decompiled from int __thiscall COneBuildingTypeIterator::FirstBuilding(COneBuildingTypeIterator *this)
int  COneBuildingTypeIterator::FirstBuilding(void) {
  
  *((_DWORD *)this + 1) = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 2), *(_DWORD *)this);
  return COneBuildingTypeIterator::NextBuildingIfCurrentIsNotValid(this);
}


// address=[0x1315ab0]
// Decompiled from int __thiscall COneBuildingTypeIterator::NextBuilding(CBuildingIteratorBase *this)
int  COneBuildingTypeIterator::NextBuilding(void) {
  
  bool i; // al
  int v2; // eax
  int v5; // [esp+4h] [ebp-4h]

  v5 = this->m_iBuildingId;
  for ( i = CBuildingIteratorBase::BuildingValid(this, v5);
        !i;
        i = CBuildingIteratorBase::BuildingValid(this, v5) )
  {
    v2 = ((int (__stdcall *)(int))CBuildingMgr::operator[])(v5);
    v5 = IAnimatedEntity::Next(v2);
  }
  this->m_iBuildingId = v5;
  return v5;
}


// address=[0x1315b00]
// Decompiled from int __thiscall COneBuildingTypeIterator::NextBuildingIfCurrentIsNotValid(CBuildingIteratorBase *this)
int  COneBuildingTypeIterator::NextBuildingIfCurrentIsNotValid(void) {
  
  if ( CBuildingIteratorBase::BuildingValid(this, this->m_iBuildingId) )
  {
    return this->m_iBuildingId;
  }
  else
  {
    return COneBuildingTypeIterator::NextBuilding((COneBuildingTypeIterator *)this);
  }
}


// address=[0x1317250]
// Decompiled from COneBuildingTypeIterator *__thiscall COneBuildingTypeIterator::COneBuildingTypeIterator(COneBuildingTypeIterator *this)
 COneBuildingTypeIterator::COneBuildingTypeIterator(void) {
  
  return this;
}


