#include "CGenericVehicleIterator.h"

// Definitions for class CGenericVehicleIterator

// address=[0x1315820]
// Decompiled from char __thiscall CGenericVehicleIterator::Init(CGenericVehicleIterator *this, int a2, int a3, int a4)
bool  CGenericVehicleIterator::Init(int a2, int a3, int a4) {
  
  CVehicleIteratorBase::Init((CGenericVehicleIterator *)((char *)this + 20), 0);
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


// address=[0x1315890]
// Decompiled from int __thiscall CGenericVehicleIterator::FirstVehicle(CGenericVehicleIterator *this)
int  CGenericVehicleIterator::FirstVehicle(void) {
  
  int v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  if ( CPlayerIterator::FirstPlayer(this) )
  {
    *((_DWORD *)this + 5) = *((_DWORD *)this + 7);
    v3 = CVehicleIteratorBase::VehicleType((CGenericVehicleIterator *)((char *)this + 20));
    v2 = CPlayerIterator::PlayerId(this);
    *((_DWORD *)this + 6) = CVehicleMgr::GetFirstVehicleId((CVehicleMgr *)&g_cVehicleMgr, v2, v3);
    if ( *((_DWORD *)this + 6) )
      return *((_DWORD *)this + 6);
    else
      return CGenericVehicleIterator::NextVehicle(this);
  }
  else
  {
    *((_DWORD *)this + 5) = 0;
    *((_DWORD *)this + 6) = 0;
    return 0;
  }
}


// address=[0x1315910]
// Decompiled from int __thiscall CGenericVehicleIterator::NextVehicle(CGenericVehicleIterator *this)
int  CGenericVehicleIterator::NextVehicle(void) {
  
  int v1; // eax
  int v3; // eax
  _DWORD *v4; // eax
  int v5; // [esp-4h] [ebp-8h]

  do
  {
    v1 = CVehicleMgr::operator[](*((_DWORD *)this + 6));
    for ( *((_DWORD *)this + 6) = IAnimatedEntity::Next(v1);
          !*((_DWORD *)this + 6);
          *((_DWORD *)this + 6) = CVehicleMgr::GetFirstVehicleId((CVehicleMgr *)&g_cVehicleMgr, v3, v5) )
    {
      if ( ++*((_DWORD *)this + 5) > *((_DWORD *)this + 8) )
      {
        if ( !CPlayerIterator::NextPlayer(this) )
          return 0;
        *((_DWORD *)this + 5) = *((_DWORD *)this + 7);
      }
      v5 = CVehicleIteratorBase::VehicleType((CGenericVehicleIterator *)((char *)this + 20));
      v3 = CPlayerIterator::PlayerId(this);
    }
    v4 = (_DWORD *)CVehicleMgr::operator[](*((_DWORD *)this + 6));
  }
  while ( ((unsigned int)&unk_4000000 & IEntity::Flags(v4)) != 0 );
  return *((_DWORD *)this + 6);
}


// address=[0x13159e0]
// Decompiled from int __thiscall CGenericVehicleIterator::NextVehicleIfCurrentIsNotValid(_DWORD *this)
int  CGenericVehicleIterator::NextVehicleIfCurrentIsNotValid(void) {
  
  if ( CVehicleIteratorBase::VehicleValid((CVehicleIteratorBase *)(this + 5), this[6]) )
    return this[6];
  else
    return CGenericVehicleIterator::NextVehicle((CGenericVehicleIterator *)this);
}


// address=[0x1315a20]
// Decompiled from int __thiscall CGenericVehicleIterator::NextVehicleOrFirstIfCurrentIsEndOfList(CGenericVehicleIterator *this)
int  CGenericVehicleIterator::NextVehicleOrFirstIfCurrentIsEndOfList(void) {
  
  if ( *((_DWORD *)this + 6) )
    return CGenericVehicleIterator::NextVehicle(this);
  else
    return CGenericVehicleIterator::FirstVehicle(this);
}


// address=[0x13171d0]
// Decompiled from CGenericVehicleIterator *__thiscall CGenericVehicleIterator::CGenericVehicleIterator(CGenericVehicleIterator *this)
 CGenericVehicleIterator::CGenericVehicleIterator(void) {
  
  CPlayerIterator::CPlayerIterator(this);
  return this;
}


