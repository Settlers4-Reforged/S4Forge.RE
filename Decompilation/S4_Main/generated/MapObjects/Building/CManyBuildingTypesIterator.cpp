#include "CManyBuildingTypesIterator.h"

// Definitions for class CManyBuildingTypesIterator

// address=[0x1315b40]
// Decompiled from int __thiscall CManyBuildingTypesIterator::Init(CBuildingIteratorBase *this, int a2, int a3, int a4)
void  CManyBuildingTypesIterator::Init(int a2, int a3, int a4) {
  
  int result; // eax

  if ( a4 == 0 )
  {
    a4 = a3;
  }
  CBuildingIteratorBase::Init(this, 0);
  *((_DWORD *)this + 2) = a2;
  *((_DWORD *)this + 3) = a3;
  result = a4;
  *((_DWORD *)this + 4) = a4;
  return result;
}


// address=[0x1315b80]
// Decompiled from int __thiscall CManyBuildingTypesIterator::FirstBuilding(CBuildingIteratorBase *this)
int  CManyBuildingTypesIterator::FirstBuilding(void) {
  
  bool v2; // [esp+0h] [ebp-8h]

  this->m_iBuildingType = *((_DWORD *)this + 3);
  this->m_iBuildingId = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 2), *((_DWORD *)this + 3));
  v2 = this->m_iBuildingId != 0;
  if ( (v2 & CBuildingIteratorBase::BuildingValid(this, this->m_iBuildingId)) != 0 )
  {
    return this->m_iBuildingId;
  }
  else
  {
    return CManyBuildingTypesIterator::NextBuilding((CManyBuildingTypesIterator *)this);
  }
}


// address=[0x1315c00]
// Decompiled from int __thiscall CManyBuildingTypesIterator::NextBuilding(CBuildingIteratorBase *this)
int  CManyBuildingTypesIterator::NextBuilding(void) {
  
  int v1; // eax
  int FirstBuildingId; // [esp+0h] [ebp-8h]

  FirstBuildingId = this->m_iBuildingId;
  do
  {
    if ( FirstBuildingId != 0 )
    {
      v1 = ((int (__stdcall *)(int))CBuildingMgr::operator[])(FirstBuildingId);
      FirstBuildingId = IAnimatedEntity::Next(v1);
    }
    while ( FirstBuildingId == 0 )
    {
      if ( ++this->m_iBuildingType > *((_DWORD *)this + 4) )
      {
        this->m_iBuildingId = 0;
        return 0;
      }
      FirstBuildingId = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 2), this->m_iBuildingType);
    }
  }
  while ( !CBuildingIteratorBase::BuildingValid(this, FirstBuildingId) );
  this->m_iBuildingId = FirstBuildingId;
  return FirstBuildingId;
}


// address=[0x1315ca0]
// Decompiled from int __thiscall CManyBuildingTypesIterator::NextBuildingIfCurrentIsNotValid(CManyBuildingTypesIterator *this)
int  CManyBuildingTypesIterator::NextBuildingIfCurrentIsNotValid(void) {
  
  if ( CBuildingIteratorBase::BuildingValid((CBuildingIteratorBase *)this, *((_DWORD *)this + 1)) )
  {
    return *((_DWORD *)this + 1);
  }
  else
  {
    return CManyBuildingTypesIterator::NextBuilding(this);
  }
}


// address=[0x13171f0]
// Decompiled from CManyBuildingTypesIterator *__thiscall CManyBuildingTypesIterator::CManyBuildingTypesIterator(CManyBuildingTypesIterator *this)
 CManyBuildingTypesIterator::CManyBuildingTypesIterator(void) {
  
  return this;
}


