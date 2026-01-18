#include "CGenericBuildingIterator.h"

// Definitions for class CGenericBuildingIterator

// address=[0x1315ce0]
// Decompiled from char __thiscall CGenericBuildingIterator::Init(CGenericBuildingIterator *this, int a2, int a3, int a4)
bool  CGenericBuildingIterator::Init(int a2, int a3, int a4) {
  
  CBuildingIteratorBase::Init((CGenericBuildingIterator *)((char *)this + 20), 0);
  if ( CPlayerIterator::Init(this, a2) )
  {
    if ( !a4 )
      a4 = a3;
    *((_DWORD *)this + 7) = a3;
    *((_DWORD *)this + 8) = a4;
    return 1;
  }
  else
  {
    *((_DWORD *)this + 7) = 0;
    *((_DWORD *)this + 8) = 0;
    return 0;
  }
}


// address=[0x1315d50]
// Decompiled from int __thiscall CGenericBuildingIterator::FirstBuilding(CGenericBuildingIterator *this)
int  CGenericBuildingIterator::FirstBuilding(void) {
  
  int v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  if ( CPlayerIterator::FirstPlayer(this) )
  {
    *((_DWORD *)this + 5) = *((_DWORD *)this + 7);
    v3 = CBuildingIteratorBase::BuildingType((CGenericBuildingIterator *)((char *)this + 20));
    v2 = CPlayerIterator::PlayerId(this);
    *((_DWORD *)this + 6) = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, v2, v3);
    if ( *((_DWORD *)this + 6) )
      return *((_DWORD *)this + 6);
    else
      return CGenericBuildingIterator::NextBuilding(this);
  }
  else
  {
    *((_DWORD *)this + 5) = 0;
    *((_DWORD *)this + 6) = 0;
    return 0;
  }
}


// address=[0x1315dd0]
// Decompiled from int __thiscall CGenericBuildingIterator::NextBuilding(CGenericBuildingIterator *this)
int  CGenericBuildingIterator::NextBuilding(void) {
  
  int v1; // eax
  int v3; // eax
  _DWORD *v4; // eax
  int v5; // [esp-4h] [ebp-8h]

  do
  {
    if ( *((_DWORD *)this + 6) )
    {
      v1 = CBuildingMgr::operator[](*((_DWORD *)this + 6));
      *((_DWORD *)this + 6) = IAnimatedEntity::Next(v1);
    }
    while ( !*((_DWORD *)this + 6) )
    {
      if ( ++*((_DWORD *)this + 5) > *((_DWORD *)this + 8) )
      {
        if ( !CPlayerIterator::NextPlayer(this) )
          return 0;
        *((_DWORD *)this + 5) = *((_DWORD *)this + 7);
      }
      v5 = CBuildingIteratorBase::BuildingType((CGenericBuildingIterator *)((char *)this + 20));
      v3 = CPlayerIterator::PlayerId(this);
      *((_DWORD *)this + 6) = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, v3, v5);
    }
    v4 = (_DWORD *)CBuildingMgr::operator[](*((_DWORD *)this + 6));
  }
  while ( ((unsigned int)&unk_4000000 & IEntity::Flags(v4)) != 0 );
  return *((_DWORD *)this + 6);
}


// address=[0x1315ea0]
// Decompiled from int __thiscall CGenericBuildingIterator::NextBuildingIfCurrentIsNotValid(_DWORD *this)
int  CGenericBuildingIterator::NextBuildingIfCurrentIsNotValid(void) {
  
  if ( CBuildingIteratorBase::BuildingValid((CBuildingIteratorBase *)(this + 5), this[6]) )
    return this[6];
  else
    return CGenericBuildingIterator::NextBuilding((CGenericBuildingIterator *)this);
}


// address=[0x1315ee0]
// Decompiled from int __thiscall CGenericBuildingIterator::NextBuildingOrFirstIfCurrentIsEndOfList(CGenericBuildingIterator *this)
int  CGenericBuildingIterator::NextBuildingOrFirstIfCurrentIsEndOfList(void) {
  
  if ( *((_DWORD *)this + 6) )
    return CGenericBuildingIterator::NextBuilding(this);
  else
    return CGenericBuildingIterator::FirstBuilding(this);
}


// address=[0x1317190]
// Decompiled from CGenericBuildingIterator *__thiscall CGenericBuildingIterator::CGenericBuildingIterator(CGenericBuildingIterator *this)
 CGenericBuildingIterator::CGenericBuildingIterator(void) {
  
  CPlayerIterator::CPlayerIterator(this);
  return this;
}


