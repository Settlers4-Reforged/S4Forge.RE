#include "CTransportShip.h"

// Definitions for class CTransportShip

// address=[0x1402520]
// Decompiled from int __cdecl CTransportShip::New(int a1)
class CPersistence * __cdecl CTransportShip::New(std::istream & a1) {
  
  if ( CTransportShip::operator new(0x12Cu) )
    return CTransportShip::CTransportShip(a1);
  else
    return 0;
}


// address=[0x152bdd0]
// Decompiled from int __thiscall CTransportShip::GetTradingState(CMFCBaseTabCtrl *this)
enum CTransportShip::TIntTraderState  CTransportShip::GetTradingState(void) {
  
  return *((_DWORD *)this + 73);
}


// address=[0x152be30]
// Decompiled from char __thiscall CTransportShip::IsNeutralTrader(CTransportShip *this)
bool  CTransportShip::IsNeutralTrader(void) {
  
  return *((_BYTE *)this + 193);
}


// address=[0x152beb0]
// Decompiled from CTransportShip *__thiscall CTransportShip::MemHomePosition(CTransportShip *this)
void  CTransportShip::MemHomePosition(void) {
  
  CTransportShip *result; // eax

  result = this;
  *((_DWORD *)this + 45) = *((_DWORD *)this + 6);
  return result;
}


// address=[0x159e950]
// Decompiled from _DWORD *__thiscall CTransportShip::FillDialog(CTransportShip *this, bool a2)
void  CTransportShip::FillDialog(bool a2) {
  
  unsigned int v3; // [esp+4h] [ebp-34h]
  int i; // [esp+Ch] [ebp-2Ch]
  CEvn_Event v5; // [esp+10h] [ebp-28h] BYREF
  int v6; // [esp+34h] [ebp-4h]

  byte_3F1E881 = 0;
  for ( i = 0; i < 8; ++i )
  {
    dword_3F1E790[3 * i] = *((_DWORD *)this + 3 * i + 49);
    dword_3F1E794[3 * i] = *((_DWORD *)this + 3 * i + 50);
  }
  dword_3F1E78C = 22;
  v3 = 604;
  if ( !a2 )
    v3 = 602;
  CEvn_Event::CEvn_Event(&v5, v3, 0, (unsigned int)&g_cVehicleLoadInfo, 0);
  v6 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v5);
  v6 = -1;
  return CEvn_Event::~CEvn_Event(&v5);
}


// address=[0x159ea50]
// Decompiled from int __thiscall CTransportShip::GetGoodAmount(CTransportShip *this, int a2)
int  CTransportShip::GetGoodAmount(int a2) {
  
  int v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < 8; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 49) == a2 )
      v3 += *((_DWORD *)this + 3 * i + 50);
  }
  return v3;
}


// address=[0x159eab0]
// Decompiled from int __thiscall CTransportShip::AddGood(CTransportShip *this, int a2, int a3)
int  CTransportShip::AddGood(int a2, int a3) {
  
  int v4; // [esp+0h] [ebp-18h]
  int v5; // [esp+4h] [ebp-14h]
  int i; // [esp+14h] [ebp-4h]
  int j; // [esp+14h] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 49) == a2 && *((_DWORD *)this + 3 * i + 50) != 8 )
    {
      if ( 8 - *((_DWORD *)this + 3 * i + 50) >= a3 )
        v5 = a3;
      else
        v5 = 8 - *((_DWORD *)this + 3 * i + 50);
      *((_DWORD *)this + 3 * i + 50) += v5;
      a3 -= v5;
    }
  }
  if ( a3 )
  {
    for ( j = 0; j < 8; ++j )
    {
      if ( !*((_DWORD *)this + 3 * j + 49) && a3 )
      {
        if ( a3 <= 8 )
          v4 = a3;
        else
          v4 = 8;
        *((_DWORD *)this + 3 * j + 50) += v4;
        *((_DWORD *)this + 3 * j + 49) = a2;
        a3 -= v4;
      }
    }
  }
  if ( IEntity::FlagBits(this, (EntityFlag)0x400u) )
    (*(void (__thiscall **)(CTransportShip *, int))(*(_DWORD *)this + 148))(this, 1);
  return a3;
}


// address=[0x159ec10]
// Decompiled from int __thiscall CTransportShip::RemoveGood(CTransportShip *this, int a2, int a3)
int  CTransportShip::RemoveGood(int a2, int a3) {
  
  int v4; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 49) == a2 )
    {
      if ( *((_DWORD *)this + 3 * i + 50) >= a3 )
        v4 = a3;
      else
        v4 = *((_DWORD *)this + 3 * i + 50);
      *((_DWORD *)this + 3 * i + 50) -= v4;
      if ( !*((_DWORD *)this + 3 * i + 50) )
        *((_DWORD *)this + 3 * i + 49) = 0;
      a3 -= v4;
    }
  }
  if ( IEntity::FlagBits(this, (EntityFlag)0x400u) )
    (*(void (__thiscall **)(CTransportShip *, int))(*(_DWORD *)this + 148))(this, 1);
  return a3;
}


// address=[0x159ed00]
// Decompiled from char __thiscall CTransportShip::IsSpaceAvailable(CTransportShip *this, int a2)
bool  CTransportShip::IsSpaceAvailable(int a2) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    if ( !*((_DWORD *)this + 3 * i + 49) )
      return 1;
    if ( *((_DWORD *)this + 3 * i + 49) == a2 && 8 - *((_DWORD *)this + 3 * i + 50) > 0 )
      return 1;
  }
  return 0;
}


// address=[0x159ed70]
// Decompiled from int __thiscall CTransportShip::GetAvailableSpace(CTransportShip *this, int a2)
int  CTransportShip::GetAvailableSpace(int a2) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  v3 = 0;
  for ( i = 0; i < 8; ++i )
  {
    if ( *((_DWORD *)this + 3 * i + 49) == a2 && 8 - *((_DWORD *)this + 3 * i + 50) > 0 )
      v3 += 8 - *((_DWORD *)this + 3 * i + 50);
  }
  return v3;
}


// address=[0x159edf0]
// Decompiled from int __thiscall CTransportShip::GetAvailableSpace(CTransportShip *this)
int  CTransportShip::GetAvailableSpace(void) {
  
  int v2; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < 8; ++i )
  {
    if ( !*((_DWORD *)this + 3 * i + 49) )
      v2 += 8;
  }
  return v2;
}


// address=[0x159ee40]
// Decompiled from char __thiscall CTransportShip::IsFull(CTransportShip *this)
bool  CTransportShip::IsFull(void) {
  
  int v2; // [esp+0h] [ebp-14h]
  int v3; // [esp+4h] [ebp-10h]
  int j; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( CTransportShip::IsNeutralTrader(this) )
  {
    v3 = 0;
    v2 = 0;
    for ( i = 0; i < 8; ++i )
    {
      if ( *((int *)this + 3 * i + 50) > 0 )
        ++v2;
      v3 += *((_DWORD *)this + 3 * i + 50);
      if ( v3 >= 16 || v2 >= 2 )
        return 1;
    }
    return 0;
  }
  else
  {
    for ( j = 0; j < 8; ++j )
    {
      if ( !*((_DWORD *)this + 3 * j + 49) )
        return 0;
      if ( 8 - *((_DWORD *)this + 3 * j + 50) > 0 )
        return 0;
    }
    return 1;
  }
}


// address=[0x159ef20]
// Decompiled from bool __thiscall CTransportShip::HasLoadedSomething(CTransportShip *this)
bool  CTransportShip::HasLoadedSomething(void) {
  
  int i; // [esp+4h] [ebp-8h]
  bool v3; // [esp+Bh] [ebp-1h]

  v3 = 0;
  for ( i = 0; i < 8 && !v3; ++i )
    v3 = *((_DWORD *)this + 3 * i + 50) != 0;
  return v3;
}


// address=[0x159ef70]
// Decompiled from char __thiscall CTransportShip::HasLoadGood(int *this, int a2)
bool  CTransportShip::HasLoadGood(enum PILE_TYPES a2) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 8; ++i )
  {
    if ( this[3 * i + 50] > 0 && this[3 * i + 49] == a2 )
      return 1;
  }
  return 0;
}


// address=[0x159efd0]
// Decompiled from CTransportShip *__thiscall CTransportShip::SetTargetHarbourID(CTransportShip *this, int a2)
void  CTransportShip::SetTargetHarbourID(int a2) {
  
  CTransportShip *result; // eax

  result = this;
  *((_DWORD *)this + 43) = a2;
  return result;
}


// address=[0x159eff0]
// Decompiled from int __thiscall CTransportShip::GetTargetHarbourID(CTransportShip *this)
int  CTransportShip::GetTargetHarbourID(void) {
  
  return *((_DWORD *)this + 43);
}


// address=[0x159f010]
// Decompiled from void __thiscall CTransportShip::TargetHarbourDestroyed(CTransportShip *this)
void  CTransportShip::TargetHarbourDestroyed(void) {
  
  int v1; // eax
  int v2; // eax
  bool IsNeutralTrader; // [esp-4h] [ebp-1Ch]
  CTradingBuildingRole *v4; // [esp+0h] [ebp-18h]
  int v5; // [esp+4h] [ebp-14h]
  CTradingBuildingRole *v6; // [esp+8h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+Ch] [ebp-Ch]
  unsigned __int8 *v8; // [esp+10h] [ebp-8h]

  if ( *((_DWORD *)this + 43) )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 43));
    v6 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
    v1 = IEntity::ID();
    CTradingBuildingRole::UnregisterIncomingTrader(v6, v1, 1);
  }
  CTransportShip::SetTargetHarbourID(this, 0);
  if ( *((_DWORD *)this + 44) )
  {
    v8 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 44));
    if ( v8 )
    {
      v5 = *((_DWORD *)this + 44);
      CTransportShip::SetDepartHarbourID(this, 0);
      CTransportShip::SetTargetHarbourID(this, v5);
      v4 = (CTradingBuildingRole *)CBuilding::Role(v8);
      IsNeutralTrader = CTransportShip::IsNeutralTrader(this);
      v2 = IEntity::ID();
      CTradingBuildingRole::RegisterIncomingTrader(v4, v2, 1, IsNeutralTrader);
      CTransportShip::MoveToTarget(this);
    }
    else
    {
      CTransportShip::SetFree(this);
      CTransportShip::SetJobType(this, 0);
      CTransportShip::TryToGoHome(this);
    }
  }
  else
  {
    CTransportShip::SetJobType(this, 0);
    CTransportShip::TryToGoHome(this);
  }
}


// address=[0x159f120]
// Decompiled from CTransportShip *__thiscall CTransportShip::SetDepartHarbourID(CTransportShip *this, int a2)
void  CTransportShip::SetDepartHarbourID(int a2) {
  
  CTransportShip *result; // eax

  result = this;
  *((_DWORD *)this + 44) = a2;
  return result;
}


// address=[0x159f140]
// Decompiled from int __thiscall CTransportShip::GetDepartHarbourID(CTransportShip *this)
int  CTransportShip::GetDepartHarbourID(void) {
  
  return *((_DWORD *)this + 44);
}


// address=[0x159f160]
// Decompiled from void __thiscall CTransportShip::DepartHarbourDestroyed(CTransportShip *this)
void  CTransportShip::DepartHarbourDestroyed(void) {
  
  int v1; // eax
  CTradingBuildingRole *v2; // [esp+0h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+4h] [ebp-Ch]
  int v4; // [esp+8h] [ebp-8h]

  v4 = *((_DWORD *)this + 44);
  CTransportShip::SetDepartHarbourID(this, 0);
  if ( *((_BYTE *)this + 184) )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v4);
    v2 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
    v1 = IEntity::ID();
    CTradingBuildingRole::UnregisterIncomingTrader(v2, v1, 1);
    CTransportShip::SetJobType(this, 0);
    CTransportShip::TryToGoHome(this);
  }
}


// address=[0x159f1e0]
// Decompiled from void __thiscall CTransportShip::DestroyShip(CTransportShip *this)
void  CTransportShip::DestroyShip(void) {
  
  ;
}


// address=[0x159f1f0]
// Decompiled from void __thiscall CTransportShip::ShipArrived(CTransportShip *this)
void  CTransportShip::ShipArrived(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  CTradingBuildingRole *v4; // [esp+0h] [ebp-14h]
  CTradingBuildingRole *v5; // [esp+4h] [ebp-10h]
  CTradingBuildingRole *v6; // [esp+8h] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+Ch] [ebp-8h]
  unsigned __int8 *v8; // [esp+Ch] [ebp-8h]
  unsigned __int8 *v9; // [esp+Ch] [ebp-8h]

  if ( *((_BYTE *)this + 184) )
  {
    if ( *((_DWORD *)this + 44) )
    {
      BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 44));
      if ( BuildingPtr )
      {
        v6 = (CTradingBuildingRole *)CBuilding::Role(BuildingPtr);
        v1 = IEntity::ID();
        CTradingBuildingRole::VehicleArrived(v6, v1, 1);
      }
    }
  }
  if ( *((_BYTE *)this + 185) )
  {
    if ( *((_DWORD *)this + 43) )
    {
      v8 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 43));
      if ( v8 )
      {
        v5 = (CTradingBuildingRole *)CBuilding::Role(v8);
        v2 = IEntity::ID();
        CTradingBuildingRole::VehicleArrived(v5, v2, 1);
      }
    }
    if ( *((_DWORD *)this + 44) )
    {
      v9 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 44));
      if ( v9 )
      {
        if ( IEntity::Type((unsigned __int16 *)v9) != 32
          && BBSupportDbgReport(2, "MapObjects\\Ship\\TransportShip.cpp", 743, "pBuilding->Type() == BUILDING_PORT") == 1 )
        {
          __debugbreak();
        }
        v4 = (CTradingBuildingRole *)CBuilding::Role(v9);
        v3 = IEntity::ID();
        CTradingBuildingRole::VehicleArrivedAtTarget(v4, v3, 1);
      }
    }
  }
  if ( *((_BYTE *)this + 296) )
  {
    *((_BYTE *)this + 296) = 0;
    CTransportShip::SetFree(this);
  }
}


// address=[0x159f340]
// Decompiled from CTransportShip *__thiscall CTransportShip::MoveToTarget(CTransportShip *this)
void  CTransportShip::MoveToTarget(void) {
  
  CTransportShip *result; // eax
  Y16X16 *WorkingAreaPackedXY; // eax
  int v3; // [esp+0h] [ebp-10h] BYREF
  int v4; // [esp+4h] [ebp-Ch] BYREF
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-8h]
  CTransportShip *v6; // [esp+Ch] [ebp-4h]

  v6 = this;
  result = this;
  if ( !*((_DWORD *)this + 43) )
    return result;
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)v6 + 43));
  if ( !BuildingPtr && BBSupportDbgReport(2, "MapObjects\\Ship\\TransportShip.cpp", 771, "pTargetBuilding") == 1 )
    __debugbreak();
  WorkingAreaPackedXY = (Y16X16 *)CBuilding::GetWorkingAreaPackedXY(BuildingPtr);
  Y16X16::UnpackXYFast(WorkingAreaPackedXY, &v3, &v4);
  CTransportShip::SetGoToSource(v6, 0);
  CTransportShip::SetGoToTarget(v6, 1);
  return (CTransportShip *)CVehicle::MoveTo(v6, v3, v4, 0);
}


// address=[0x159f3e0]
// Decompiled from void __thiscall CTransportShip::SetFree(CTransportShip *this)
void  CTransportShip::SetFree(void) {
  
  if ( CTransportShip::HasLoadedSomething(this) )
    CTransportShip::DropGoods(this);
}


// address=[0x159f410]
// Decompiled from int __thiscall CTransportShip::DropGoods(CTransportShip *this)
void  CTransportShip::DropGoods(void) {
  
  int GoodAmount; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < 43; ++i )
  {
    GoodAmount = CTransportShip::GetGoodAmount(this, i);
    if ( GoodAmount )
      CTransportShip::RemoveGood(this, i, GoodAmount);
  }
  return IEntity::ClearFlagBits(this, VulnerableMask);
}


// address=[0x159f470]
// Decompiled from CTransportShip *__thiscall CTransportShip::TryToGoHome(Y16X16 **this)
void  CTransportShip::TryToGoHome(void) {
  
  CTransportShip *result; // eax
  int v2; // [esp+0h] [ebp-Ch] BYREF
  int v3; // [esp+4h] [ebp-8h] BYREF
  Y16X16 **v4; // [esp+8h] [ebp-4h]

  v4 = this;
  Y16X16::UnpackXYFast(this[45], &v2, &v3);
  CTransportShip::SetFree((CTransportShip *)v4);
  CVehicle::MoveTo((CVehicle *)v4, v2, v3, 0);
  CTransportShip::SetGoToSource((CTransportShip *)v4, 0);
  CTransportShip::SetGoToTarget((CTransportShip *)v4, 0);
  CTransportShip::SetTargetHarbourID((CTransportShip *)v4, 0);
  CTransportShip::SetDepartHarbourID((CTransportShip *)v4, 0);
  result = (CTransportShip *)v4;
  *((_BYTE *)v4 + 296) = 1;
  return result;
}


// address=[0x159f4f0]
// Decompiled from _DWORD *__thiscall CTransportShip::GoToHomeTradingBuilding(CTransportShip *this)
void  CTransportShip::GoToHomeTradingBuilding(void) {
  
  unsigned __int8 *BuildingPtr; // eax
  unsigned __int8 *v2; // eax
  _DWORD *result; // eax
  int v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+8h] [ebp-Ch] BYREF
  Y16X16 *v7; // [esp+Ch] [ebp-8h]
  CTransportShip *v8; // [esp+10h] [ebp-4h]

  v8 = this;
  v7 = (Y16X16 *)*((_DWORD *)this + 45);
  if ( *((_DWORD *)this + 73) == 1 && *((_DWORD *)v8 + 44) )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)v8 + 44));
    v7 = (Y16X16 *)CBuilding::EnsignPackedXY(BuildingPtr);
  }
  if ( *((_DWORD *)v8 + 73) == 2 && *((_DWORD *)v8 + 43) )
  {
    v2 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)v8 + 43));
    v7 = (Y16X16 *)CBuilding::EnsignPackedXY(v2);
  }
  Y16X16::UnpackXYFast(v7, &v5, &v6);
  CVehicle::MoveTo(v8, v5, v6, 0);
  v4 = *((_DWORD *)v8 + 44);
  *((_DWORD *)v8 + 44) = *((_DWORD *)v8 + 43);
  *((_DWORD *)v8 + 43) = v4;
  result = CTransportShip::ClearNeutralTraderStatus(v8);
  *((_BYTE *)v8 + 296) = 1;
  return result;
}


// address=[0x159f5e0]
// Decompiled from unsigned __int8 *__thiscall CTransportShip::SetHomeID(CTransportShip *this, unsigned int a2)
void  CTransportShip::SetHomeID(int a2) {
  
  unsigned __int8 *result; // eax
  unsigned __int8 *v4; // [esp+4h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Ship\\TransportShip.cpp", 812, "_iHomeBuildingID!=0") == 1 )
    __debugbreak();
  if ( !CMapObjectMgr::ValidEntityId(a2)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Ship\\TransportShip.cpp",
         813,
         "g_pMapObjectMgr->ValidEntityId(_iHomeBuildingID)") == 1 )
  {
    __debugbreak();
  }
  result = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2);
  v4 = result;
  if ( !result )
  {
    result = (unsigned __int8 *)BBSupportDbgReport(2, "MapObjects\\Ship\\TransportShip.cpp", 815, "pBuilding!=NULL");
    if ( result == (unsigned __int8 *)1 )
      __debugbreak();
  }
  if ( !v4 )
    return result;
  result = (unsigned __int8 *)CBuilding::EnsignPackedXY(v4);
  *((_DWORD *)this + 45) = result;
  return result;
}


// address=[0x159f6a0]
// Decompiled from CTransportShip *__thiscall CTransportShip::SetJobType(CTransportShip *this, int a2)
void  CTransportShip::SetJobType(int a2) {
  
  CTransportShip *result; // eax

  result = this;
  *((_DWORD *)this + 47) = a2;
  return result;
}


// address=[0x159f6c0]
// Decompiled from int __thiscall CTransportShip::GetJobType(CTransportShip *this)
int  CTransportShip::GetJobType(void) {
  
  return *((_DWORD *)this + 47);
}


// address=[0x159f6e0]
// Decompiled from CTransportShip *__thiscall CTransportShip::SetGoToSource(CTransportShip *this, bool a2)
void  CTransportShip::SetGoToSource(bool a2) {
  
  CTransportShip *result; // eax

  result = this;
  *((_BYTE *)this + 184) = a2;
  return result;
}


// address=[0x159f700]
// Decompiled from CTransportShip *__thiscall CTransportShip::SetGoToTarget(CTransportShip *this, bool a2)
void  CTransportShip::SetGoToTarget(bool a2) {
  
  CTransportShip *result; // eax

  result = this;
  *((_BYTE *)this + 185) = a2;
  return result;
}


// address=[0x159f720]
// Decompiled from CTransportShip *__thiscall CTransportShip::VehicleLogicUpdate(CTransportShip *this)
void  CTransportShip::VehicleLogicUpdate(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  CTransportShip *result; // eax
  int v6; // [esp+0h] [ebp-18h]
  int v7; // [esp+0h] [ebp-18h]
  int v8; // [esp+4h] [ebp-14h]
  unsigned int TickCounter; // [esp+8h] [ebp-10h]
  int v10; // [esp+Ch] [ebp-Ch]
  char v11; // [esp+10h] [ebp-8h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  if ( CShip::FULL_UPDATE_DELAY + *((_DWORD *)this + 42) < TickCounter )
  {
    v10 = CShip::RepairBuildingInRange(this);
    if ( v10 )
      CShip::RepairAt(this, v10);
    *((_DWORD *)this + 42) = TickCounter;
  }
  if ( IEntity::FlagBits(this, (EntityFlag)0x400u) )
    (*(void (__thiscall **)(CTransportShip *, int))(*(_DWORD *)this + 148))(this, 1);
  v11 = *((_BYTE *)this + 107);
  switch ( v11 )
  {
    case 6:
      *((_BYTE *)this + 192) = *((_BYTE *)this + 107);
      v7 = std::auto_ptr<CWalking>::operator->(v6);
      v3 = IEntity::PackedXY(this);
      v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 12))(v7, v3);
      CVehicle::WalkDirAndRegister(this, v4, 1);
      break;
    case 17:
      if ( CTransportShip::GetJobType(this) != 3 && CTransportShip::GetJobType(this) != 4 )
      {
        v8 = std::auto_ptr<CWalking>::operator->(v6);
        v1 = IEntity::PackedXY(this);
        v2 = (*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v8 + 16))(v8, v1, 0);
        CVehicle::WalkDirAndRegister(this, v2, 0);
      }
      break;
    case 27:
      CVehicle::GetNextJob(this);
      break;
  }
  if ( *((unsigned __int8 *)this + 107) != *((unsigned __int8 *)this + 192) && *((_BYTE *)this + 192) == 6 )
    CTransportShip::ShipArrived(this);
  if ( (*((_BYTE *)this + 104) & 0x40) != 0 )
    CTransportShip::TargetHarbourDestroyed(this);
  result = this;
  *((_BYTE *)this + 192) = *((_BYTE *)this + 107);
  return result;
}


// address=[0x159f8b0]
// Decompiled from void __thiscall CTransportShip::ConvertEventIntoGoal(CTransportShip *this, struct CEntityEvent *a2)
void  CTransportShip::ConvertEventIntoGoal(class CEntityEvent * a2) {
  
  if ( *((_DWORD *)a2 + 1) == 9 || *((_DWORD *)a2 + 1) == 7 )
  {
    if ( *((_DWORD *)a2 + 3) == *((_DWORD *)this + 43) )
      CTransportShip::TargetHarbourDestroyed(this);
    if ( *((_DWORD *)a2 + 3) == *((_DWORD *)this + 44) )
      CTransportShip::DepartHarbourDestroyed(this);
  }
  CVehicle::ConvertEventIntoGoal(this, a2);
}


// address=[0x159f910]
// Decompiled from CTransportShip *__thiscall CTransportShip::TakeJob(CTransportShip *this)
void  CTransportShip::TakeJob(void) {
  
  CTransportShip *result; // eax

  CShip::TakeJob(this);
  result = this;
  *((_BYTE *)this + 192) = *((_BYTE *)this + 107);
  return result;
}


// address=[0x159f940]
// Decompiled from void *__thiscall CTransportShip::GetGfxInfos(CTransportShip *this)
struct SGfxObjectInfo *  CTransportShip::GetGfxInfos(void) {
  
  CShip::GetGfxInfos((int)this);
  if ( IEntity::FlagBits(this, (EntityFlag)0x400u) )
    byte_40FE264 = CShip::GetHealthDisplayID(this);
  return &IEntity::m_sGfxInfo;
}


// address=[0x159f980]
// Decompiled from CTransportShip *__thiscall CTransportShip::SetNeutralTraderStatus(CTransportShip *this, bool a2)
void  CTransportShip::SetNeutralTraderStatus(bool a2) {
  
  CTransportShip *result; // eax

  *((_BYTE *)this + 193) = a2;
  if ( a2 )
  {
    IEntity::ClearFlagBits(this, VulnerableMask);
    result = this;
    if ( !*((_DWORD *)this + 73) || *((_DWORD *)this + 73) == 2 )
    {
      *((_DWORD *)this + 73) = 1;
      result = this;
      *((_BYTE *)this + 193) = a2;
      return result;
    }
    if ( *((_DWORD *)this + 73) == 1 )
    {
      result = this;
      *((_DWORD *)this + 73) = 2;
      *((_BYTE *)this + 193) = a2;
      return result;
    }
  }
  else
  {
    result = this;
    *((_DWORD *)this + 73) = 0;
  }
  *((_BYTE *)this + 193) = a2;
  return result;
}


// address=[0x159fa30]
// Decompiled from _DWORD *__thiscall CTransportShip::ClearNeutralTraderStatus(CTransportShip *this)
void  CTransportShip::ClearNeutralTraderStatus(void) {
  
  *((_BYTE *)this + 193) = 0;
  *((_DWORD *)this + 73) = 0;
  return IEntity::SetFlagBits(this, VulnerableMask);
}


// address=[0x159fa60]
// Decompiled from unsigned int __cdecl CTransportShip::operator new(unsigned int a1)
void * __cdecl CTransportShip::operator new(unsigned int a1) {
  
  return CVehicleMgr::Alloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x159fa80]
// Decompiled from void __cdecl CTransportShip::operator delete(void *a1)
void __cdecl CTransportShip::operator delete(void * a1) {
  
  CVehicleMgr::Dealloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x159fac0]
// Decompiled from char *__thiscall CTransportShip::CTransportShip(char *this, int a2)
 CTransportShip::CTransportShip(std::istream & a2) {
  
  int v3; // [esp+4h] [ebp-34h] BYREF
  int v4; // [esp+8h] [ebp-30h] BYREF
  int v5; // [esp+Ch] [ebp-2Ch] BYREF
  _DWORD pExceptionObject[2]; // [esp+10h] [ebp-28h] BYREF
  int m; // [esp+18h] [ebp-20h]
  int k; // [esp+1Ch] [ebp-1Ch]
  int j; // [esp+20h] [ebp-18h]
  int i; // [esp+24h] [ebp-14h]
  char *v11; // [esp+28h] [ebp-10h]
  int v12; // [esp+34h] [ebp-4h]

  v11 = this;
  CShip::CShip(a2);
  v12 = 0;
  *(_DWORD *)v11 = &CTransportShip::_vftable_;
  v11[193] = 0;
  *((_DWORD *)v11 + 73) = 0;
  v11[296] = 0;
  operator^<unsigned int>(a2, &v5);
  pExceptionObject[1] = v5 - 1;
  switch ( v5 )
  {
    case 1:
      operator^<int>(a2, (int)(v11 + 172));
      operator^<int>(a2, (int)(v11 + 176));
      operator^<int>(a2, (int)(v11 + 180));
      operator^<bool>(a2, v11 + 184);
      operator^<bool>(a2, v11 + 185);
      operator^<int>(a2, (int)(v11 + 188));
      operator^<unsigned char>(a2, v11 + 192);
      for ( i = 0; i < 8; ++i )
      {
        operator^<int>(a2, (int)&v11[12 * i + 200]);
        operator^<int>(a2, (int)&v11[12 * i + 204]);
        operator^<int>(a2, (int)&v11[12 * i + 196]);
      }
      break;
    case 2:
      operator^<int>(a2, (int)(v11 + 172));
      operator^<int>(a2, (int)(v11 + 176));
      operator^<int>(a2, (int)(v11 + 180));
      operator^<bool>(a2, v11 + 184);
      operator^<bool>(a2, v11 + 185);
      operator^<int>(a2, (int)(v11 + 188));
      operator^<unsigned char>(a2, v11 + 192);
      for ( j = 0; j < 8; ++j )
      {
        operator^<int>(a2, (int)&v11[12 * j + 200]);
        operator^<int>(a2, (int)&v11[12 * j + 204]);
        operator^<int>(a2, (int)&v11[12 * j + 196]);
      }
      operator^<bool>(a2, v11 + 193);
      break;
    case 3:
      operator^<int>(a2, (int)(v11 + 172));
      operator^<int>(a2, (int)(v11 + 176));
      operator^<int>(a2, (int)(v11 + 180));
      operator^<bool>(a2, v11 + 184);
      operator^<bool>(a2, v11 + 185);
      operator^<int>(a2, (int)(v11 + 188));
      operator^<unsigned char>(a2, v11 + 192);
      for ( k = 0; k < 8; ++k )
      {
        operator^<int>(a2, (int)&v11[12 * k + 200]);
        operator^<int>(a2, (int)&v11[12 * k + 204]);
        operator^<int>(a2, (int)&v11[12 * k + 196]);
      }
      operator^<bool>(a2, v11 + 193);
      operator^<int>(a2, (int)&v4);
      *((_DWORD *)v11 + 73) = v4;
      break;
    case 4:
      operator^<int>(a2, (int)(v11 + 172));
      operator^<int>(a2, (int)(v11 + 176));
      operator^<int>(a2, (int)(v11 + 180));
      operator^<bool>(a2, v11 + 184);
      operator^<bool>(a2, v11 + 185);
      operator^<int>(a2, (int)(v11 + 188));
      operator^<unsigned char>(a2, v11 + 192);
      for ( m = 0; m < 8; ++m )
      {
        operator^<int>(a2, (int)&v11[12 * m + 200]);
        operator^<int>(a2, (int)&v11[12 * m + 204]);
        operator^<int>(a2, (int)&v11[12 * m + 196]);
      }
      operator^<bool>(a2, v11 + 193);
      operator^<int>(a2, (int)&v3);
      *((_DWORD *)v11 + 73) = v3;
      operator^<bool>(a2, v11 + 296);
      break;
    default:
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CTransportShip");
      pExceptionObject[0] = 0;
      CS4InvalidMapException::CS4InvalidMapException(pExceptionObject);
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  return v11;
}


// address=[0x15a0060]
// Decompiled from int __thiscall CTransportShip::Store(int *this, struct std::ostream *a2)
void  CTransportShip::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-10h] BYREF
  int v4; // [esp+4h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-8h]
  int *v6; // [esp+Ch] [ebp-4h]

  v6 = this;
  CShip::Store(a2);
  v4 = 4;
  operator^<unsigned int>(a2, &v4);
  operator^<int>((int)a2, v6 + 43);
  operator^<int>((int)a2, v6 + 44);
  operator^<int>((int)a2, v6 + 45);
  operator^<bool>((int)a2, (int)(v6 + 46));
  operator^<bool>((int)a2, (int)v6 + 185);
  operator^<int>((int)a2, v6 + 47);
  operator^<unsigned char>(a2, (int)(v6 + 48));
  for ( i = 0; i < 8; ++i )
  {
    operator^<int>((int)a2, &v6[3 * i + 50]);
    operator^<int>((int)a2, &v6[3 * i + 51]);
    operator^<int>((int)a2, &v6[3 * i + 49]);
  }
  operator^<bool>((int)a2, (int)v6 + 193);
  v3 = v6[73];
  operator^<int>((int)a2, &v3);
  return operator^<bool>((int)a2, (int)(v6 + 74));
}


// address=[0x15a09c0]
// Decompiled from int __thiscall CTransportShip::ClassID(CTransportShip *this)
unsigned long  CTransportShip::ClassID(void)const {
  
  return CTransportShip::m_iClassID;
}


// address=[0x3d8bfdc]
// [Decompilation failed for static unsigned long CTransportShip::m_iClassID]

// address=[0x15a01e0]
// Decompiled from CTransportShip *__thiscall CTransportShip::CTransportShip(  CTransportShip *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  bool a8)
 CTransportShip::CTransportShip(int a2, int a3, int a4, int a5, int a6, int a7, bool a8) {
  
  int i; // [esp+0h] [ebp-8h]

  CShip::CShip(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CTransportShip::_vftable_;
  *((_BYTE *)this + 193) = 0;
  *((_DWORD *)this + 73) = 0;
  *((_BYTE *)this + 296) = 0;
  *((_BYTE *)this + 192) = *((_BYTE *)this + 107);
  for ( i = 0; i < 8; ++i )
  {
    *((_DWORD *)this + 3 * i + 49) = 0;
    *((_DWORD *)this + 3 * i + 50) = 0;
  }
  *((_DWORD *)this + 44) = 0;
  *((_DWORD *)this + 43) = 0;
  *((_DWORD *)this + 47) = 0;
  *((_BYTE *)this + 184) = 0;
  *((_BYTE *)this + 185) = 0;
  return this;
}


// address=[0x15a02d0]
// Decompiled from void __thiscall CTransportShip::~CTransportShip(CTransportShip *this)
 CTransportShip::~CTransportShip(void) {
  
  *(_DWORD *)this = &CTransportShip::_vftable_;
  CShip::~CShip(this);
}


