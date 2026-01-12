#include "CVehicleIterator.h"

// Definitions for class CVehicleIterator

// address=[0x15aa510]
// Decompiled from int __thiscall CVehicleIterator::FirstVehicle(CVehicleIterator *this)

class CVehicle *  CVehicleIterator::FirstVehicle(void) {
  
  int FirstVehicleId; // [esp+0h] [ebp-Ch]
  void **v3; // [esp+4h] [ebp-8h]

  if ( (*(int *)this <= 0 || *(int *)this >= 9)
    && BBSupportDbgReport(2, "MapObjects\\VehicleMgr.cpp", 1122, "(m_iPlayerId > 0) && (m_iPlayerId < PLAYER_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( (*((int *)this + 1) <= 0 || *((int *)this + 1) >= 6)
    && BBSupportDbgReport(
         2,
         "MapObjects\\VehicleMgr.cpp",
         1123,
         "(m_iVehicleType > 0) && (m_iVehicleType < VEHICLE_MAX)") == 1 )
  {
    __debugbreak();
  }
  FirstVehicleId = CVehicleMgr::GetFirstVehicleId((CVehicleMgr *)&g_cVehicleMgr, *(_DWORD *)this, *((_DWORD *)this + 1));
  v3 = (void **)CMapObjectMgr::EntityPtr(FirstVehicleId);
  if ( v3
    && !j____RTDynamicCast(v3, 0, &IEntity__RTTI_Type_Descriptor_, &CVehicle__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\VehicleMgr.cpp",
         1129,
         "(pFirstEntity == 0) || (dynamic_cast<CVehicle*>(pFirstEntity) != 0)") == 1 )
  {
    __debugbreak();
  }
  *((_DWORD *)this + 2) = v3;
  if ( !CVehicleIterator::IsEntityNullOrValid(*((struct IEntity **)this + 2)) )
    *((_DWORD *)this + 2) = CVehicleIterator::NextVehicle(this);
  return *((_DWORD *)this + 2);
}


// address=[0x15aad90]
// Decompiled from int __thiscall CVehicleIterator::NextVehicle(CVehicleIterator *this)

class CVehicle *  CVehicleIterator::NextVehicle(void) {
  
  do
    *((_DWORD *)this + 2) = CVehicleIterator::NextVehicleEx(this, *((struct CVehicle **)this + 2));
  while ( !CVehicleIterator::IsEntityNullOrValid(*((struct IEntity **)this + 2)) );
  return *((_DWORD *)this + 2);
}


// address=[0x160d920]
// Decompiled from CVehicleIterator *__thiscall CVehicleIterator::CVehicleIterator(CVehicleIterator *this, int a2, int a3)

 CVehicleIterator::CVehicleIterator(int,int) {
  
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = 0;
  return this;
}


// address=[0x15aad50]
// Decompiled from bool __cdecl CVehicleIterator::IsEntityNullOrValid(struct IEntity *a1)

static bool __cdecl CVehicleIterator::IsEntityNullOrValid(class IEntity *) {
  
  return !a1 || IEntity::FlagBits(a1, (EntityFlag)&loc_3000000);
}


// address=[0x15aade0]
// Decompiled from void **__thiscall CVehicleIterator::NextVehicleEx(CVehicleIterator *this, struct CVehicle *a2)

class CVehicle *  CVehicleIterator::NextVehicleEx(class CVehicle *) {
  
  int v3; // eax
  void **v4; // [esp+4h] [ebp-4h]

  if ( !a2 )
    return 0;
  v3 = IAnimatedEntity::Next(a2);
  v4 = (void **)CMapObjectMgr::EntityPtr(v3);
  if ( v4
    && !j____RTDynamicCast(v4, 0, &IEntity__RTTI_Type_Descriptor_, &CVehicle__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\VehicleMgr.h",
         218,
         "(pNextEntity == 0) || (dynamic_cast<CVehicle*>(pNextEntity) != 0)") == 1 )
  {
    __debugbreak();
  }
  return v4;
}


