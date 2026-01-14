#include "all_headers.h"

// Definitions for class CManyVehicleTypesIterator

// address=[0x1315680]
// Decompiled from int __thiscall CManyVehicleTypesIterator::Init(CManyVehicleTypesIterator *this, int a2, int a3, int a4)
void  CManyVehicleTypesIterator::Init(int,int,int) {
  
  int result; // eax

  if ( !a4 )
    a4 = a3;
  CVehicleIteratorBase::Init(this, 0);
  *((_DWORD *)this + 2) = a2;
  *((_DWORD *)this + 3) = a3;
  result = a4;
  *((_DWORD *)this + 4) = a4;
  return result;
}


// address=[0x13156c0]
// Decompiled from int __thiscall CManyVehicleTypesIterator::FirstVehicle(CManyVehicleTypesIterator *this)
int  CManyVehicleTypesIterator::FirstVehicle(void) {
  
  bool v2; // [esp+0h] [ebp-8h]

  *(_DWORD *)this = *((_DWORD *)this + 3);
  *((_DWORD *)this + 1) = CVehicleMgr::GetFirstVehicleId(
                            (CVehicleMgr *)&g_cVehicleMgr,
                            *((_DWORD *)this + 2),
                            *((_DWORD *)this + 3));
  v2 = *((_DWORD *)this + 1) != 0;
  if ( (v2 & CVehicleIteratorBase::VehicleValid(this, *((_DWORD *)this + 1))) != 0 )
    return *((_DWORD *)this + 1);
  else
    return CManyVehicleTypesIterator::NextVehicle(this);
}


// address=[0x1315740]
// Decompiled from int __thiscall CManyVehicleTypesIterator::NextVehicle(CManyVehicleTypesIterator *this)
int  CManyVehicleTypesIterator::NextVehicle(void) {
  
  int v1; // eax
  int i; // [esp+0h] [ebp-8h]

  i = *((_DWORD *)this + 1);
  do
  {
    v1 = CVehicleMgr::operator[](i);
    for ( i = IAnimatedEntity::Next(v1);
          !i;
          i = CVehicleMgr::GetFirstVehicleId((CVehicleMgr *)&g_cVehicleMgr, *((_DWORD *)this + 2), *(_DWORD *)this) )
    {
      if ( ++*(_DWORD *)this > *((_DWORD *)this + 4) )
      {
        *((_DWORD *)this + 1) = 0;
        return 0;
      }
    }
  }
  while ( !CVehicleIteratorBase::VehicleValid(this, i) );
  *((_DWORD *)this + 1) = i;
  return i;
}


// address=[0x13157e0]
// Decompiled from int __thiscall CManyVehicleTypesIterator::NextVehicleIfCurrentIsNotValid(CManyVehicleTypesIterator *this)
int  CManyVehicleTypesIterator::NextVehicleIfCurrentIsNotValid(void) {
  
  if ( CVehicleIteratorBase::VehicleValid(this, *((_DWORD *)this + 1)) )
    return *((_DWORD *)this + 1);
  else
    return CManyVehicleTypesIterator::NextVehicle(this);
}


// address=[0x1317230]
// Decompiled from CManyVehicleTypesIterator *__thiscall CManyVehicleTypesIterator::CManyVehicleTypesIterator(  CManyVehicleTypesIterator *this)
 CManyVehicleTypesIterator::CManyVehicleTypesIterator(void) {
  
  return this;
}


