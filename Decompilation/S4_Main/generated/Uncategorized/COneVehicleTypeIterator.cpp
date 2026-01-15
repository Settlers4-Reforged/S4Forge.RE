#include "COneVehicleTypeIterator.h"

// Definitions for class COneVehicleTypeIterator

// address=[0x1315590]
// Decompiled from int __thiscall COneVehicleTypeIterator::Init(COneVehicleTypeIterator *this, int a2, int a3)
void  COneVehicleTypeIterator::Init(int,int) {
  
  int result; // eax

  CVehicleIteratorBase::Init(this, a3);
  *((_DWORD *)this + 2) = a2;
  return result;
}


// address=[0x13155c0]
// Decompiled from int __thiscall COneVehicleTypeIterator::FirstVehicle(COneVehicleTypeIterator *this)
int  COneVehicleTypeIterator::FirstVehicle(void) {
  
  *((_DWORD *)this + 1) = CVehicleMgr::GetFirstVehicleId(
                            (CVehicleMgr *)&g_cVehicleMgr,
                            *((_DWORD *)this + 2),
                            *(_DWORD *)this);
  return COneVehicleTypeIterator::NextVehicleIfCurrentIsNotValid(this);
}


// address=[0x13155f0]
// Decompiled from int __thiscall COneVehicleTypeIterator::NextVehicle(COneVehicleTypeIterator *this)
int  COneVehicleTypeIterator::NextVehicle(void) {
  
  int v1; // eax
  int v3; // [esp+0h] [ebp-8h]

  do
  {
    v1 = CVehicleMgr::operator[](*((_DWORD *)this + 1));
    v3 = IAnimatedEntity::Next(v1);
  }
  while ( !CVehicleIteratorBase::VehicleValid(this, v3) );
  *((_DWORD *)this + 1) = v3;
  return v3;
}


// address=[0x1315640]
// Decompiled from int __thiscall COneVehicleTypeIterator::NextVehicleIfCurrentIsNotValid(COneVehicleTypeIterator *this)
int  COneVehicleTypeIterator::NextVehicleIfCurrentIsNotValid(void) {
  
  if ( CVehicleIteratorBase::VehicleValid(this, *((_DWORD *)this + 1)) )
    return *((_DWORD *)this + 1);
  else
    return COneVehicleTypeIterator::NextVehicle(this);
}


// address=[0x1317290]
// Decompiled from COneVehicleTypeIterator *__thiscall COneVehicleTypeIterator::COneVehicleTypeIterator(COneVehicleTypeIterator *this)
 COneVehicleTypeIterator::COneVehicleTypeIterator(void) {
  
  return this;
}


