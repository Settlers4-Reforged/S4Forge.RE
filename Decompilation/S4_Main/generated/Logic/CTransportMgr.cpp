#include "all_headers.h"

// Definitions for class CTransportMgr

// address=[0x147cd30]
// Decompiled from int __cdecl CTransportMgr::GetNearestEntity(int a1, int a2, int a3, int a4, int a5)
static class IMovingEntity * __cdecl CTransportMgr::GetNearestEntity(int,int,int,int,int) {
  
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  void **v12; // eax
  int v14; // [esp-4h] [ebp-34h]
  int v15; // [esp-4h] [ebp-34h]
  int v16; // [esp+4h] [ebp-2Ch]
  int v17; // [esp+8h] [ebp-28h]
  int v18; // [esp+Ch] [ebp-24h]
  int v20; // [esp+14h] [ebp-1Ch]
  bool v21; // [esp+18h] [ebp-18h]
  int j; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  struct CVehicle *VehiclePtr; // [esp+24h] [ebp-Ch]
  unsigned __int8 *SettlerPtr; // [esp+28h] [ebp-8h]

  v16 = 0;
  v17 = 0xFFFF;
  v5 = Y16X16::PackXYFast(a4, a5);
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(v5)
    && BBSupportDbgReport(2, "Logic\\TransportMgr.cpp", 42, "g_cWorld.InWorldPackedXY( Y16X16::PackXYFast(_iX,_iY) )") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 && BBSupportDbgReport(2, "Logic\\TransportMgr.cpp", 43, "_iOwnerID>0") == 1 )
    __debugbreak();
  if ( a2 <= 0 && BBSupportDbgReport(2, "Logic\\TransportMgr.cpp", 44, "_iEntityType>0") == 1 )
    __debugbreak();
  if ( a1 != 1
    && a1 != 2
    && a1 != 4
    && BBSupportDbgReport(
         2,
         "Logic\\TransportMgr.cpp",
         49,
         "_iEntityObjType == SETTLER_OBJ || _iEntityObjType == SHIP_OBJ || _iEntityObjType == CATAPULT_OBJ") == 1 )
  {
    __debugbreak();
  }
  if ( a1 == 1 )
  {
    for ( i = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, a3, a2); i; i = IAnimatedEntity::Next(SettlerPtr) )
    {
      SettlerPtr = CSettlerMgr::GetSettlerPtr(i);
      if ( !SettlerPtr && BBSupportDbgReport(2, "Logic\\TransportMgr.cpp", 59, "pSettler!= NULL") == 1 )
        __debugbreak();
      v21 = 0;
      if ( SettlerPtr )
      {
        v6 = IEntity::WorldIdx();
        v7 = CWorldManager::SectorId(v6);
        if ( v7 == CWorldManager::SectorId(a4, a5) )
        {
          if ( (*(unsigned __int8 (__thiscall **)(unsigned __int8 *))(*(_DWORD *)SettlerPtr + 116))(SettlerPtr) )
            v21 = 1;
        }
      }
      if ( v21
        && !CSettler::Strike((CSettler *)SettlerPtr)
        && (*(unsigned __int8 (__thiscall **)(unsigned __int8 *))(*(_DWORD *)SettlerPtr + 116))(SettlerPtr) )
      {
        v14 = a5 - IEntity::Y(SettlerPtr);
        v8 = IEntity::X(SettlerPtr);
        v20 = Grid::Distance((Grid *)(a4 - v8), v14);
        if ( v20 < v17 )
        {
          v17 = v20;
          v16 = i;
        }
      }
    }
  }
  else
  {
    for ( j = CVehicleMgr::GetFirstVehicleId((CVehicleMgr *)&g_cVehicleMgr, a3, a2);
          j;
          j = IAnimatedEntity::Next(VehiclePtr) )
    {
      VehiclePtr = CVehicleMgr::GetVehiclePtr(j);
      if ( !VehiclePtr && BBSupportDbgReport(2, "Logic\\TransportMgr.cpp", 95, "pVehicle!= NULL") == 1 )
        __debugbreak();
      if ( VehiclePtr )
      {
        v9 = IEntity::WorldIdx();
        v10 = CWorldManager::SectorId(v9);
        if ( v10 == CWorldManager::SectorId(a4, a5) )
        {
          if ( (*(unsigned __int8 (__thiscall **)(struct CVehicle *))(*(_DWORD *)VehiclePtr + 116))(VehiclePtr) )
          {
            v15 = a5 - IEntity::Y(VehiclePtr);
            v11 = IEntity::X(VehiclePtr);
            v18 = Grid::Distance((Grid *)(a4 - v11), v15);
            if ( v18 < v17 )
            {
              v17 = v18;
              v16 = j;
            }
          }
        }
      }
    }
  }
  if ( v16 <= 0 )
    return 0;
  v12 = (void **)CMapObjectMgr::EntityPtr(v16);
  if ( !j____RTDynamicCast(v12, 0, &IEntity__RTTI_Type_Descriptor_, &IMovingEntity__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(
         2,
         "Logic\\TransportMgr.cpp",
         121,
         "dynamic_cast<IMovingEntity*> ( g_pMapObjectMgr->EntityPtr( sBestFit.EntityID ) )!= NULL") == 1 )
  {
    __debugbreak();
  }
  return CMapObjectMgr::EntityPtr(v16);
}


// address=[0x147d080]
// Decompiled from unsigned __int8 *__cdecl CTransportMgr::GetNearestTransportEntity(  int a1,  int a2,  int a3,  int a4,  int a5,  int a6,  char a7)
static class IMovingEntity * __cdecl CTransportMgr::GetNearestTransportEntity(int,int,int,int,int,int,bool) {
  
  int v8; // eax
  int v9; // eax
  CEcoSector *v10; // eax
  int v11; // [esp+8h] [ebp-20h]
  int NearestSettler; // [esp+10h] [ebp-18h]
  struct IMovingEntity *v13; // [esp+14h] [ebp-14h]
  struct IMovingEntity *NearestEntity; // [esp+18h] [ebp-10h]
  bool v15; // [esp+1Ch] [ebp-Ch]
  int v16; // [esp+20h] [ebp-8h]

  if ( a1 <= 0 && BBSupportDbgReport(2, "Logic\\TransportMgr.cpp", 139, "_iRequestedGoodAmount > 0") == 1 )
    __debugbreak();
  v11 = CWorldManager::SectorId(a3, a4);
  if ( CWorldManager::SectorId(a5, a6) != v11 )
    return (unsigned __int8 *)CTransportMgr::GetNearestEntity(2, 3, a2, a3, a4);
  v8 = CWorldManager::Index(a3, a4);
  v16 = CWorldManager::EcoSectorId(v8);
  v9 = CWorldManager::Index(a5, a6);
  v15 = CWorldManager::EcoSectorId(v9) == v16 && a7;
  if ( a1 >= 16 )
  {
    NearestEntity = CTransportMgr::GetNearestEntity(4, 5, a2, a3, a4);
    if ( NearestEntity )
      return (unsigned __int8 *)NearestEntity;
  }
  if ( a1 >= 7 || !a7 )
  {
    v13 = CTransportMgr::GetNearestEntity(1, 60, a2, a3, a4);
    if ( v13 )
      return (unsigned __int8 *)v13;
  }
  if ( !v15 )
    return 0;
  if ( !v16 )
    return 0;
  v10 = (CEcoSector *)CEcoSectorMgr::operator[](v16);
  NearestSettler = CEcoSector::GetNearestSettler(v10, 1, a3, a4);
  if ( NearestSettler )
    return CSettlerMgr::GetSettlerPtr(NearestSettler);
  return 0;
}


// address=[0x147d210]
// Decompiled from unsigned __int8 *__cdecl CTransportMgr::GetNearestCarrier(int a1, int a2, int a3)
static class CSettler * __cdecl CTransportMgr::GetNearestCarrier(int,int,int) {
  
  int v3; // eax
  int v5; // [esp+0h] [ebp-Ch]
  int NearestSettler; // [esp+4h] [ebp-8h]
  CEcoSector *v7; // [esp+8h] [ebp-4h]

  v3 = CWorldManager::Index(a2, a3);
  v5 = CWorldManager::EcoSectorId(v3);
  if ( v5 <= 0 )
    return 0;
  v7 = (CEcoSector *)CEcoSectorMgr::operator[](v5);
  if ( CEcoSector::Owner(v7) != a1 )
    return 0;
  NearestSettler = CEcoSector::GetNearestSettler(v7, 1, a2, a3);
  if ( !NearestSettler )
    return 0;
  CEcoSector::GetSettlerOutOfOffer(v7, NearestSettler);
  return CSettlerMgr::GetSettlerPtr(NearestSettler);
}


// address=[0x147d2a0]
// Decompiled from unsigned __int8 *__cdecl CTransportMgr::GetVehicleCargoLoader(int a1, int a2, int a3, int a4, int a5, int a6, int *a7)
static class IMovingEntity * __cdecl CTransportMgr::GetVehicleCargoLoader(int,int,int,int,int,int,int &) {
  
  int v8; // eax
  int v9; // eax
  CEcoSector *v10; // eax
  CEcoSector *v11; // [esp+0h] [ebp-20h]
  int v12; // [esp+4h] [ebp-1Ch]
  struct IMovingEntity *NearestEntity; // [esp+Ch] [ebp-14h]
  unsigned __int8 *SettlerPtr; // [esp+10h] [ebp-10h]
  int NearestSettler; // [esp+14h] [ebp-Ch]
  int v16; // [esp+18h] [ebp-8h]

  if ( a1 != 4
    && a1 != 5
    && BBSupportDbgReport(
         2,
         "Logic\\TransportMgr.cpp",
         234,
         "( _iVehicelType == VEHICLE_WARMACHINE ) || ( _iVehicelType == VEHICLE_CART )") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorld(a3, a4)
    && BBSupportDbgReport(2, "Logic\\TransportMgr.cpp", 235, "g_cWorld.InWorld(_iSourceX,_iSourceY)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorld(a5, a6)
    && BBSupportDbgReport(2, "Logic\\TransportMgr.cpp", 236, "g_cWorld.InWorld(_iDestX,_iDestY)") == 1 )
  {
    __debugbreak();
  }
  if ( a1 == 4 && (NearestEntity = CTransportMgr::GetNearestEntity(1, 60, a2, a3, a4)) != 0 )
  {
    *a7 = 8;
    return (unsigned __int8 *)NearestEntity;
  }
  else
  {
    v8 = CWorldManager::Index(a3, a4);
    v16 = CWorldManager::EcoSectorId(v8);
    v9 = CWorldManager::Index(a5, a6);
    v12 = CWorldManager::EcoSectorId(v9);
    if ( v16
      && v12 == v16
      && (v10 = (CEcoSector *)CEcoSectorMgr::operator[](v16),
          (NearestSettler = CEcoSector::GetNearestSettler(v10, 1, a3, a4)) != 0) )
    {
      SettlerPtr = CSettlerMgr::GetSettlerPtr(NearestSettler);
      if ( !SettlerPtr && BBSupportDbgReport(2, "Logic\\TransportMgr.cpp", 263, "pSettler!=NULL") == 1 )
        __debugbreak();
      if ( IEntity::OwnerId(SettlerPtr) != a2
        && BBSupportDbgReport(2, "Logic\\TransportMgr.cpp", 264, "pSettler->OwnerId() == _iOwnerID") == 1 )
      {
        __debugbreak();
      }
      v11 = (CEcoSector *)CEcoSectorMgr::operator[](v12);
      CEcoSector::GetSettlerOutOfOffer(v11, NearestSettler);
      *a7 = 1;
      return SettlerPtr;
    }
    else
    {
      return 0;
    }
  }
}


// address=[0x36bab38]
// [Decompilation failed for static int const CTransportMgr::MIN_DONKEY_AMOUNT]

// address=[0x36bab3c]
// [Decompilation failed for static int const CTransportMgr::MIN_CART_AMOUNT]

