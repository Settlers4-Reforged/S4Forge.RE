#include "CVehicle.h"

// Definitions for class CVehicle

// address=[0x1351ab0]
// Decompiled from int __thiscall CVehicle::CurrentTask(CVehicle *this)
int  CVehicle::CurrentTask(void)const {
  
  return *((unsigned __int8 *)this + 107);
}


// address=[0x153a430]
// Decompiled from void __thiscall CVehicle::CountCargo(CVehicle *this, struct ICargoCounter *a2)
void  CVehicle::CountCargo(class ICargoCounter & a2) {
  
  ;
}


// address=[0x153fda0]
// Decompiled from int __thiscall CVehicle::DeleteSelectable(CVehicle *this)
void  CVehicle::DeleteSelectable(void) {
  
  return IEntity::ClearFlagBits(this, EntityFlag_Selectable);
}


// address=[0x153fe70]
// Decompiled from _DWORD *__thiscall CVehicle::SetSelectable(CVehicle *this)
void  CVehicle::SetSelectable(void) {
  
  return IEntity::SetFlagBits(this, EntityFlag_Selectable);
}


// address=[0x159e900]
// Decompiled from int __thiscall CVehicle::GetMeetingPointXY(void *this, int a2, int a3)
int const  CVehicle::GetMeetingPointXY(enum OBJ_TYPE a2, int a3) {
  
  return IEntity::PackedXY(this);
}


// address=[0x15a3c70]
// Decompiled from int __thiscall CVehicle::Loading(CVehicle *this)
int  CVehicle::Loading(void)const {
  
  return 1;
}


// address=[0x15a3c80]
// Decompiled from char __thiscall CVehicle::PostLoadInit(CVehicle *this)
void  CVehicle::PostLoadInit(void) {
  
  unsigned int v1; // eax
  int v2; // eax
  int v3; // eax
  unsigned int v5; // [esp-4h] [ebp-8h]

  IEntity::PostLoadInit();
  v5 = *((unsigned __int16 *)this + 6);
  v1 = IEntity::Race(this);
  *((_DWORD *)this + 25) = IVehicleInfoMgr::VehicleProperties(v1, v5);
  (*(void (__thiscall **)(CVehicle *))(*(_DWORD *)this + 76))(this);
  v2 = IEntity::ObjType((unsigned __int8 *)this);
  if ( v2 != 2 )
    return v2;
  v3 = IEntity::PackedXY(this);
  LOBYTE(v2) = CWater::PlaceShip(v3);
  return v2;
}


// address=[0x15a3ce0]
// Decompiled from int __thiscall CVehicle::AddToWarMap(CVehicle *this)
void  CVehicle::AddToWarMap(void) {
  
  int result; // eax

  result = IEntity::FlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
  if ( result )
    return CWarMap::AddEntity(this);
  return result;
}


// address=[0x15a3d10]
// Decompiled from void __thiscall CVehicle::GoodIsComming(CVehicle *this, int a2, int a3)
void  CVehicle::GoodIsComming(int a2, int a3) {
  
  ;
}


// address=[0x15a3d20]
// Decompiled from void __thiscall CVehicle::EntityOrderCanceled(CVehicle *this, int a2)
void  CVehicle::EntityOrderCanceled(int a2) {
  
  ;
}


// address=[0x15a3d30]
// Decompiled from void __thiscall CVehicle::EntityEnter(CVehicle *this, int a2)
void  CVehicle::EntityEnter(int a2) {
  
  ;
}


// address=[0x15a3d40]
// Decompiled from void __thiscall CVehicle::GoodArrived(CVehicle *this, int a2, int a3)
void  CVehicle::GoodArrived(int a2, int a3) {
  
  ;
}


// address=[0x15a3d50]
// Decompiled from void __thiscall CVehicle::SupplyCanceled(CVehicle *this, int a2, int a3)
void  CVehicle::SupplyCanceled(int a2, int a3) {
  
  ;
}


// address=[0x15a3d60]
// Decompiled from int __thiscall CVehicle::Delete(CVehicle *this)
void  CVehicle::Delete(void) {
  
  int v1; // eax
  int LastLogicUpdateTick; // eax
  int v3; // eax
  int v5; // [esp-8h] [ebp-3Ch]
  int v6; // [esp-4h] [ebp-38h]
  _BYTE v7[24]; // [esp+4h] [ebp-30h] BYREF
  const struct CEntityEvent *v8; // [esp+1Ch] [ebp-18h]
  const struct CEntityEvent *v9; // [esp+20h] [ebp-14h]
  CPaneContainer *v10; // [esp+24h] [ebp-10h]
  int v11; // [esp+30h] [ebp-4h]

  v10 = this;
  CWarMap::RemoveEntity(this);
  if ( *((int *)v10 + 6) > 0 )
  {
    (*(void (__thiscall **)(CPaneContainer *, _DWORD))(*(_DWORD *)v10 + 200))(v10, *((_DWORD *)v10 + 6));
    *((_DWORD *)v10 + 6) = 0;
  }
  v5 = IAnimatedEntity::AttackerPlayerId();
  v1 = IEntity::EntityId((unsigned __int16 *)v10);
  v9 = CEntityEvent::CEntityEvent((CEntityEvent *)v7, 9u, 0, v1, v5, 0);
  v8 = v9;
  v11 = 0;
  CObserverList::NotifyAndDetachAllObservers((CPaneContainer *)((char *)v10 + 156), v9);
  v11 = -1;
  CEntityEvent::~CEntityEvent(v7);
  v6 = IEntity::ID();
  LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(v10);
  CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v6);
  v3 = IEntity::ID();
  CVehicleMgr::CheckOutVehicle((CVehicleMgr *)&g_cVehicleMgr, v3);
  IEntity::ID();
  IEntity::OwnerId((unsigned __int8 *)v10);
  return (*(int (__cdecl **)(int))(*(_DWORD *)g_pAI + 44))(23);
}


// address=[0x15a3e80]
// Decompiled from int __thiscall CVehicle::FireMissile(CVehicle *this, int a2, int a3)
void  CVehicle::FireMissile(int a2, int a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int result; // eax
  int v10; // eax
  int v11; // [esp-10h] [ebp-50h]
  int v12; // [esp-10h] [ebp-50h]
  struct IEntity *v13; // [esp+0h] [ebp-40h]
  int v14; // [esp+Ch] [ebp-34h]
  int v15; // [esp+10h] [ebp-30h]
  int v16; // [esp+14h] [ebp-2Ch]
  int v17; // [esp+1Ch] [ebp-24h]
  int v18; // [esp+20h] [ebp-20h]
  int v19; // [esp+24h] [ebp-1Ch]
  int v20; // [esp+28h] [ebp-18h]
  int v21; // [esp+2Ch] [ebp-14h]
  int v22; // [esp+30h] [ebp-10h]
  int v23; // [esp+34h] [ebp-Ch]
  int v24; // [esp+38h] [ebp-8h]
  int v25; // [esp+38h] [ebp-8h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 778, "_iTargetId > 0") == 1 )
    __debugbreak();
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a3)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 779, "g_cWorld.InWorldPackedXY( _iDestinationXY )") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::Race(this) == 1 )
  {
    if ( IEntity::Type((unsigned __int16 *)this) == 4 )
    {
      v19 = CLogic::Effects((DWORD *)g_pLogic);
      v11 = Y16X16::UnpackXFast(a3);
      v5 = Y16X16::UnpackXFast(a3);
      v23 = (*(int (__thiscall **)(int, int, _DWORD, int, int, int, _DWORD, int))(*(_DWORD *)v19 + 16))(
              v19,
              23,
              0,
              v5,
              v11,
              1,
              0,
              1);
    }
    else
    {
      v20 = CLogic::Effects((DWORD *)g_pLogic);
      v4 = IEntity::PackedXY(this);
      v23 = (*(int (__thiscall **)(int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v20 + 24))(
              v20,
              *(_DWORD *)(*((_DWORD *)this + 25) + 60),
              v4,
              a3,
              1,
              0,
              0);
    }
  }
  else
  {
    v21 = CLogic::Effects((DWORD *)g_pLogic);
    v3 = IEntity::PackedXY(this);
    v23 = (*(int (__thiscall **)(int, _DWORD, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v21 + 24))(
            v21,
            *(_DWORD *)(*((_DWORD *)this + 25) + 60),
            v3,
            a3,
            1,
            0,
            0);
  }
  if ( *(_DWORD *)(*((_DWORD *)this + 25) + 64) )
  {
    v18 = CLogic::Effects((DWORD *)g_pLogic);
    v12 = Y16X16::UnpackYFast(a3);
    v6 = Y16X16::UnpackXFast(a3);
    (*(void (__thiscall **)(int, _DWORD, _DWORD, int, int, int, _DWORD, int))(*(_DWORD *)v18 + 16))(
      v18,
      *(_DWORD *)(*((_DWORD *)this + 25) + 64),
      *(_DWORD *)(*((_DWORD *)this + 25) + 68),
      v6,
      v12,
      v23 + 1,
      0,
      1);
  }
  v13 = CMapObjectMgr::Entity(a2);
  v24 = *(_DWORD *)(*((_DWORD *)this + 25) + 56);
  v22 = IEntity::OwnerId((unsigned __int8 *)this);
  v7 = IEntity::PackedXY(this);
  v8 = CWorldManager::Index(v7);
  v15 = ITiling::OwnerId(v8);
  v14 = CAlliances::AllianceId(v22);
  if ( v14 == CAlliances::AllianceId(v15) )
    v17 = CStatistic::DefenceStrength256((CStatistic *)&g_cStatistic, v22);
  else
    v17 = CStatistic::OffenceStrength256((CStatistic *)&g_cStatistic, v22);
  v25 = ((v17 * v24 + 127) >> 8 == 0) + ((v17 * v24 + 127) >> 8);
  result = IEntity::FlagBits(v13, (EntityFlag)((char *)&loc_1FFFFFF + 1));
  if ( !result )
    return result;
  v16 = CLogic::FutureEvents(g_pLogic);
  v10 = IEntity::OwnerId((unsigned __int8 *)this);
  return (*(int (__thiscall **)(int, int, int, int, int, int))(*(_DWORD *)v16 + 12))(v16, 2, v23 + 1, a2, v25, v10);
}


// address=[0x15a4130]
// Decompiled from char __thiscall CVehicle::Update(CVehicle *this)
void  CVehicle::Update(void) {
  
  unsigned int v1; // eax
  unsigned int v3; // [esp+4h] [ebp-14h]
  int TickCounter; // [esp+8h] [ebp-10h]
  char v5; // [esp+Ch] [ebp-Ch]
  unsigned int v6; // [esp+10h] [ebp-8h]

  TickCounter = CStateGame::GetTickCounter(g_pGame);
  LOBYTE(v1) = (_BYTE)this;
  v6 = TickCounter - *((_DWORD *)this + 11);
  if ( !v6 )
    return v1;
  *((_DWORD *)this + 11) = TickCounter;
  if ( (unsigned __int8)CVehicle::IsTurning(this) )
  {
    v1 = CVehicle::TurnVehicle(this, v6);
    v6 = v1;
    if ( !v1 )
      return v1;
  }
  LOBYTE(v1) = (_BYTE)this;
  v5 = *((_BYTE *)this + 107);
  if ( v5 == 6 )
    goto LABEL_7;
  if ( v5 != 16 )
  {
    if ( v5 != 17 )
      return v1;
LABEL_7:
    LOBYTE(v1) = CVehicle::IsMoving(this);
    if ( !(_BYTE)v1 )
      return v1;
    if ( !*((_BYTE *)this + 109) && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 893, "m_uCycleFrames > 0") == 1 )
      __debugbreak();
    if ( (*((_BYTE *)this + 104) & 8) != 0
      && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 894, "( m_uWalkResult & WALK_RESULT_FLAG_DONT_MOVE ) == 0") == 1 )
    {
      __debugbreak();
    }
    if ( (*((_DWORD *)this + 5) & 0x40000) != 0 )
    {
      *((_BYTE *)this + 108) = (v6 + *((unsigned __int8 *)this + 108))
                             % (2 * (unsigned int)*((unsigned __int8 *)this + 109));
      *((_BYTE *)this + 36) = *((unsigned __int8 *)this + 108) / 2;
    }
    else
    {
      *((_BYTE *)this + 36) = (v6 + *((unsigned __int8 *)this + 36)) % *((unsigned __int8 *)this + 109);
    }
    if ( !*((_BYTE *)this + 69) )
      BBSupportTracePrintF(0, "CVehicle::Update(): m_uDistance == 0!");
    if ( !*((_BYTE *)this + 110) && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 917, "m_uWalkSteps > 0") == 1 )
      __debugbreak();
    if ( *((_BYTE *)this + 110) )
      v3 = *((unsigned __int8 *)this + 110);
    else
      v3 = 1;
    LOBYTE(v1) = (unsigned __int8)IMovingEntity::DecDistance(this, (v6 << 8) / v3);
    return v1;
  }
  if ( !*((_BYTE *)this + 109) && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 927, "m_uCycleFrames > 0") == 1 )
    __debugbreak();
  LOBYTE(v1) = (_BYTE)this;
  *((_BYTE *)this + 36) = (v6 + *((unsigned __int8 *)this + 36)) % *((unsigned __int8 *)this + 109);
  return v1;
}


// address=[0x15a4340]
// Decompiled from int __thiscall CVehicle::LogicUpdate(CVehicle *this)
void  CVehicle::LogicUpdate(void) {
  
  int v1; // eax

  CVehicle::Update(this);
  if ( IEntity::FlagBits(this, (EntityFlag)&dword_F29144[220079]) )
  {
    if ( *((unsigned __int16 *)this + 62) < (int)*((unsigned __int16 *)this + 63) )
    {
      return IAnimatedEntity::RegisterForLogicUpdate(16);
    }
    else
    {
      v1 = IEntity::ID();
      CTrace::Print("Vehicle %u is complete done", v1);
      return (*(int (__thiscall **)(CVehicle *))(*(_DWORD *)this + 160))(this);
    }
  }
  else
  {
    *((_BYTE *)this + 104) = 8;
    *((_BYTE *)this + 105) = 0;
    *((_BYTE *)this + 69) = 0;
    CVehicle::ClearCallTakeJob();
    IAnimatedEntity::ProcessAllEvents(this);
    if ( (unsigned __int8)CVehicle::CallTakeJob() )
      return (*(int (__thiscall **)(CVehicle *))(*(_DWORD *)this + 188))(this);
    else
      return (*(int (__thiscall **)(CVehicle *))(*(_DWORD *)this + 144))(this);
  }
}


// address=[0x15a4400]
// Decompiled from void __thiscall CVehicle::VehicleLogicUpdate(CVehicle *this)
void  CVehicle::VehicleLogicUpdate(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  struct CWalking *v5; // [esp+0h] [ebp-10h]
  struct CWalking *v6; // [esp+4h] [ebp-Ch]
  char v7; // [esp+8h] [ebp-8h]

  v7 = *((_BYTE *)this + 107);
  if ( v7 == 6 )
  {
    v5 = IMovingEntity::Walking(this);
    v3 = IEntity::PackedXY(this);
    v4 = (*(int (__thiscall **)(struct CWalking *, int))(*(_DWORD *)v5 + 12))(v5, v3);
    CVehicle::WalkDirAndRegister(this, v4, 1);
  }
  else if ( v7 == 17 )
  {
    v6 = IMovingEntity::Walking(this);
    v1 = IEntity::PackedXY(this);
    v2 = (*(int (__thiscall **)(struct CWalking *, int, _DWORD))(*(_DWORD *)v6 + 16))(v6, v1, 0);
    CVehicle::WalkDirAndRegister(this, v2, 0);
  }
  else if ( BBSupportDbgReportF(
              1,
              "MapObjects\\Vehicle.cpp",
              1485,
              "CVehicle::VehicleLogicUpdate(): Invalid task %u!",
              *((unsigned __int8 *)this + 107)) == 1 )
  {
    __debugbreak();
  }
}


// address=[0x15a44b0]
// Decompiled from bool __thiscall CVehicle::IsUnEmployed(CVehicle *this)
bool  CVehicle::IsUnEmployed(void)const {
  
  return (*((_BYTE *)this + 107) == 17 || !*((_BYTE *)this + 107))
      && IEntity::FlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
}


// address=[0x15a4500]
// Decompiled from CVehicle *__thiscall CVehicle::IncreaseAmmo(CVehicle *this, int a2)
void  CVehicle::IncreaseAmmo(int a2) {
  
  CVehicle *result; // eax
  int v3; // [esp+4h] [ebp-10h]

  if ( a2 <= 0 )
    return result;
  if ( a2 + (unsigned int)*((unsigned __int8 *)this + 111) > *(_DWORD *)(*((_DWORD *)this + 25) + 84) )
    v3 = *(_DWORD *)(*((_DWORD *)this + 25) + 84);
  else
    LOBYTE(v3) = a2 + *((_BYTE *)this + 111);
  result = this;
  *((_BYTE *)this + 111) = v3;
  return result;
}


// address=[0x15a4560]
// Decompiled from int __thiscall CVehicle::BuildingProgress(CVehicle *this)
int  CVehicle::BuildingProgress(void) {
  
  int v2; // [esp+0h] [ebp-8h]

  *((float *)this + 34) = (float)(*((unsigned __int16 *)this + 63) + *((unsigned __int16 *)this + 62)) / 100.0;
  if ( *((float *)this + 34) == 0.0 )
    *((float *)this + 34) = FLOAT_1_0;
  v2 = (int)(float)(100.0
                  - (float)((float)(*((unsigned __int16 *)this + 63) - *((unsigned __int16 *)this + 62))
                          / *((float *)this + 34)));
  if ( v2 > 100 )
    v2 = 100;
  if ( v2 < 0 )
    return 0;
  return v2;
}


// address=[0x15a4610]
// Decompiled from int __thiscall CVehicle::InitBuildingSite(CVehicle *this)
void  CVehicle::InitBuildingSite(void) {
  
  unsigned int v1; // eax
  const struct SVehicleProperties *v2; // eax
  int result; // eax
  unsigned int v4; // [esp-4h] [ebp-Ch]

  IEntity::ClearFlagBits(this, (EntityFlag)((char *)&loc_1FFFFFF + 1));
  IEntity::SetFlagBits(this, (EntityFlag)&dword_F29144[220143]);
  *((_BYTE *)this + 120) = 0;
  *((_BYTE *)this + 121) = 0;
  *((_BYTE *)this + 122) = 0;
  *((_BYTE *)this + 123) = 0;
  *((_WORD *)this + 65) = 0;
  *((_WORD *)this + 63) = 0;
  *((_WORD *)this + 62) = 0;
  *((_WORD *)this + 66) = 0;
  *((_WORD *)this + 64) = 0;
  v4 = IEntity::Type((unsigned __int16 *)this);
  v1 = IEntity::Race(this);
  v2 = IVehicleInfoMgr::VehicleProperties(v1, v4);
  *((_BYTE *)this + 120) = *(_BYTE *)v2;
  *((_BYTE *)this + 121) = *((_BYTE *)this + 120);
  *((_BYTE *)this + 122) = *((_BYTE *)v2 + 4);
  *((_BYTE *)this + 123) = *((_BYTE *)this + 122);
  *((_WORD *)this + 65) = 1;
  *((_WORD *)this + 63) = *((_WORD *)this + 65) * (*((unsigned __int8 *)this + 122) + *((unsigned __int8 *)this + 120));
  result = 65534 / *((unsigned __int16 *)this + 63);
  *((_WORD *)this + 64) = result;
  return result;
}


// address=[0x15a4730]
// Decompiled from int __thiscall CVehicle::OnBuildReady(int this)
void  CVehicle::OnBuildReady(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // esi
  int result; // eax
  int v6; // eax
  int LocalPlayerId; // eax
  int v8; // [esp-10h] [ebp-28h]
  int v9; // [esp-Ch] [ebp-24h]
  int v10; // [esp-8h] [ebp-20h]
  int v11; // [esp-8h] [ebp-20h]
  int v12; // [esp-8h] [ebp-20h]
  int v13; // [esp-4h] [ebp-1Ch]
  int v14; // [esp-4h] [ebp-1Ch]
  int v15; // [esp-4h] [ebp-1Ch]
  int v16; // [esp+8h] [ebp-10h]
  int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]

  v16 = IEntity::OwnerId((unsigned __int8 *)this);
  v17 = IEntity::Type((unsigned __int16 *)this);
  if ( !IEntity::FlagBits((_DWORD *)this, EntityFlag_Birth)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 477, "FlagBits(ENTITY_FLAG_BIRTH) != 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits((_DWORD *)this, EntityFlag_Ready)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 478, "FlagBits(ENTITY_FLAG_READY) == 0") == 1 )
  {
    __debugbreak();
  }
  v13 = IEntity::EntityId((unsigned __int16 *)this);
  v10 = IEntity::Type((unsigned __int16 *)this);
  v1 = IEntity::OwnerId((unsigned __int8 *)this);
  CVehicleMgr::DetachVehicle((CVehicleMgr *)&g_cVehicleMgr, v1, v10, v13);
  IEntity::ClearFlagBits((_DWORD *)this, (EntityFlag)&dword_F29144[220079]);
  if ( word_4158D1C[18 * v16 + 1 + 3 * v17] )
    --word_4158D1C[18 * v16 + 1 + 3 * v17];
  ++word_4158D1C[18 * v16 + 2 + 3 * v17];
  IEntity::SetFlagBits((_DWORD *)this, *(EntityFlag *)(*(_DWORD *)(this + 100) + 40));
  IEntity::SetFlagBits((_DWORD *)this, (EntityFlag)&byte_20300FD[3]);
  v14 = IEntity::EntityId((unsigned __int16 *)this);
  v11 = IEntity::Type((unsigned __int16 *)this);
  v2 = IEntity::OwnerId((unsigned __int8 *)this);
  CVehicleMgr::AttachVehicle((CVehicleMgr *)&g_cVehicleMgr, v2, v11, v14);
  CWarMap::AddEntity((CPropertySet *)this);
  (*(void (__thiscall **)(int))(*(_DWORD *)this + 188))(this);
  v12 = IEntity::Type((unsigned __int16 *)this);
  v3 = IEntity::OwnerId((unsigned __int8 *)this);
  CStatistic::AddProducedVehicle((CStatistic *)&g_cStatistic, v3, v12, 1);
  v4 = IEntity::OwnerId((unsigned __int8 *)this);
  result = CPlayerManager::GetLocalPlayerId();
  if ( v4 != result )
    return result;
  v18 = 0;
  result = IEntity::Type((unsigned __int16 *)this);
  switch ( result )
  {
    case 1:
      v18 = 1963;
      break;
    case 2:
      v18 = 1916;
      break;
    case 3:
      v18 = 1925;
      break;
    case 4:
      result = IEntity::Race((_BYTE *)this);
      if ( result )
      {
        result = IEntity::Race((_BYTE *)this);
        if ( result == 1 )
        {
          v18 = 1962;
        }
        else
        {
          result = IEntity::Race((_BYTE *)this);
          if ( result == 2 )
          {
            v18 = 1924;
          }
          else
          {
            result = IEntity::Race((_BYTE *)this);
            if ( result == 4 )
              v18 = 290;
            else
              v18 = 1911;
          }
        }
      }
      else
      {
        v18 = 1911;
      }
      break;
    default:
      v15 = IEntity::Type((unsigned __int16 *)this);
      v6 = IEntity::Race((_BYTE *)this);
      result = CTrace::Print(
                 "Workshopbuildingrole: Text message for this vehicle Race %u, Type %u not implemented",
                 v6,
                 v15);
      break;
  }
  if ( !v18 )
    return result;
  v9 = IEntity::Y((void *)this);
  v8 = IEntity::X((_DWORD *)this);
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  return CTextMsgHandler::AddTextMsg(v18, LocalPlayerId, v8, v9, 0, 0);
}


// address=[0x15a4a20]
// Decompiled from char __thiscall CVehicle::NeedForBuildingMaterial(CVehicle *this, int a2)
bool  CVehicle::NeedForBuildingMaterial(int a2) {
  
  if ( a2 == 7 )
  {
    if ( *((_BYTE *)this + 121) )
      return 1;
  }
  else if ( a2 == 20 && *((_BYTE *)this + 123) )
  {
    return 1;
  }
  return 0;
}


// address=[0x15a4a70]
// Decompiled from CVehicle *__thiscall CVehicle::AddBuildingMaterial(CVehicle *this, CVehicle *a2)
void  CVehicle::AddBuildingMaterial(int a2) {
  
  CVehicle *result; // eax

  result = a2;
  if ( a2 == (CVehicle *)7 )
  {
    if ( !*((_BYTE *)this + 121) && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 437, "m_uBoardsNeed > 0") == 1 )
      __debugbreak();
    --*((_BYTE *)this + 121);
    result = this;
    ++*((_WORD *)this + 62);
  }
  else if ( a2 == (CVehicle *)20 )
  {
    if ( !*((_BYTE *)this + 123) && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 446, "m_uIronNeed > 0") == 1 )
      __debugbreak();
    --*((_BYTE *)this + 123);
    result = this;
    ++*((_WORD *)this + 62);
  }
  return result;
}


// address=[0x15a4b30]
// Decompiled from void __thiscall CVehicle::Attach(CVehicle *this, int a2)
void  CVehicle::Attach(int a2) {
  
  int v2; // eax

  v2 = IEntity::EntityId((unsigned __int16 *)this);
  CObserverList::Attach((CVehicle *)((char *)this + 156), v2, a2);
}


// address=[0x15a4b60]
// Decompiled from int __thiscall CVehicle::Detach(CVehicle *this, int a2)
void  CVehicle::Detach(int a2) {
  
  CVehicle::DetachWithoutNotify(this, a2);
  return (*(int (__thiscall **)(CVehicle *, int))(*(_DWORD *)this + 192))(this, a2);
}


// address=[0x15a4b90]
// Decompiled from int __thiscall CVehicle::Notify(CVehicle *this, const struct CEntityEvent *a2)
void  CVehicle::Notify(class CEntityEvent const & a2)const {
  
  return CObserverList::NotifyAllObservers((char *)this + 156, (int)a2);
}


// address=[0x15a4bb0]
// Decompiled from void __thiscall CVehicle::Decrease(CVehicle *this, int a2)
void  CVehicle::Decrease(int a2) {
  
  int v2; // eax
  int v3; // [esp+0h] [ebp-1Ch]
  int v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+Ch] [ebp-10h]
  int v6; // [esp+10h] [ebp-Ch]
  int v7; // [esp+14h] [ebp-8h]

  if ( a2 > 0 )
  {
    v7 = *(_DWORD *)(*((_DWORD *)this + 25) + 52);
    if ( a2 <= v7 )
      v6 = 1;
    else
      v6 = a2 - v7;
    if ( v6 <= 1 )
      v5 = 1;
    else
      v5 = v6 / 2;
    v3 = IEntity::X(this);
    v4 = IEntity::Y(this);
    IEntity::Decrease((int)this, v5);
    if ( !(*(int (__thiscall **)(CVehicle *))(*(_DWORD *)this + 40))(this) )
    {
      v2 = CLogic::Effects((DWORD *)g_pLogic);
      (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v2 + 16))(
        v2,
        63,
        91,
        v3,
        v4,
        0,
        0,
        0);
    }
  }
}


// address=[0x15a4c80]
// Decompiled from int __thiscall CVehicle::GetGroupFlags(unsigned __int16 *this)
int  CVehicle::GetGroupFlags(void)const {
  
  return this[57];
}


// address=[0x15a4ca0]
// Decompiled from int __thiscall CVehicle::SetGroupFlagBits(CVehicle *this, unsigned int a2)
int  CVehicle::SetGroupFlagBits(int a2) {
  
  if ( a2 >= 0x10000
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1568, "(_iFlagBits >= 0) && (_iFlagBits <= 0xFFFF)") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)this + 57) |= a2;
  return *((unsigned __int16 *)this + 57);
}


// address=[0x15a4d00]
// Decompiled from int __thiscall CVehicle::ClearGroupFlagBits(CVehicle *this, unsigned int a2)
int  CVehicle::ClearGroupFlagBits(int a2) {
  
  if ( a2 >= 0x10000
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1575, "(_iFlagBits >= 0) && (_iFlagBits <= 0xFFFF)") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)this + 57) &= ~(_WORD)a2;
  return *((unsigned __int16 *)this + 57);
}


// address=[0x15a7a40]
// Decompiled from void __thiscall CVehicle::FillDialog(CVehicle *this, bool a2)
void  CVehicle::FillDialog(bool a2) {
  
  ;
}


// address=[0x153a460]
// Decompiled from int __thiscall CVehicle::GetCurrentTaskPtr(CVehicle *this)
class CEntityTask *  CVehicle::GetCurrentTaskPtr(void) {
  
  if ( *((_BYTE *)this + 112) )
    return std::vector<CEntityTask>::operator[](*((unsigned __int8 *)this + 112) - 1);
  else
    return 0;
}


// address=[0x153a530]
// Decompiled from bool __thiscall CVehicle::IsTurning(CVehicle *this)
bool  CVehicle::IsTurning(void)const {
  
  return *((_BYTE *)this + 105) != 0;
}


// address=[0x153a620]
// Decompiled from int __thiscall CVehicle::TurnDirEx(CVehicle *this)
unsigned int  CVehicle::TurnDirEx(void)const {
  
  return *((_BYTE *)this + 106) & 0x7F;
}


// address=[0x153fe00]
// Decompiled from bool __thiscall CVehicle::ReadyToFire(CVehicle *this, unsigned int a2)
bool  CVehicle::ReadyToFire(unsigned int a2)const {
  
  return a2 >= *((_DWORD *)this + 29);
}


// address=[0x153fe40]
// Decompiled from int __thiscall CVehicle::RegisterNewTask(CVehicle *this, char a2, int a3)
void  CVehicle::RegisterNewTask(unsigned int a2, unsigned int a3) {
  
  *((_BYTE *)this + 107) = a2;
  return IAnimatedEntity::RegisterForLogicUpdate(a3);
}


// address=[0x153fe90]
// Decompiled from int __thiscall CVehicle::TurnCounter(CVehicle *this)
unsigned int  CVehicle::TurnCounter(void)const {
  
  return *((unsigned __int8 *)this + 105);
}


// address=[0x15a4d60]
// Decompiled from CVehicle *__thiscall CVehicle::CVehicle(  CVehicle *this,  int a2,  int a3,  int a4,  int a5,  WORD a6,  unsigned int a7,  bool a8)
 CVehicle::CVehicle(int a2, int a3, int a4, int a5, int a6, int a7, bool a8) {
  
  void *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v13; // [esp+4h] [ebp-20h] BYREF
  int v14; // [esp+8h] [ebp-1Ch]
  unsigned int v15; // [esp+Ch] [ebp-18h]
  int v16; // [esp+10h] [ebp-14h]
  int v18; // [esp+20h] [ebp-4h]

  IMovingEntity::IMovingEntity((IMovingEntity *)this, a5);
  v18 = 0;
  *(_DWORD *)this = &CVehicle::_vftable_;
  *((_WORD *)this + 57) = 0;
  *((_DWORD *)this + 34) = 0;
  std::vector<CEntityTask>::vector<CEntityTask>();
  CObserverList::CObserverList((char *)this + 156);
  LOBYTE(v18) = 2;
  if ( !CWorldManager::InInnerWorld1(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 110, "g_cWorld.InInnerWorld1(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( !CPlayerManager::ValidUsedPlayerId(a4)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 111, "g_cPlayerMgr.ValidUsedPlayerId(_iOwnerId)") == 1 )
  {
    __debugbreak();
  }
  v8 = (void *)CPlayerManager::PlayerInfo(a4);
  v16 = CPlayerInfo::Race(v8);
  *((_WORD *)this + 6) = a6;
  *((_DWORD *)this + 25) = IVehicleInfoMgr::VehicleProperties(v16, *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 10) = *(_BYTE *)(*((_DWORD *)this + 25) + 8);
  IEntity::SetOwnerId((IEntity *)this, a4);
  IEntity::SetRace((IEntity *)this, v16);
  v15 = a7;
  if ( a7 == -1 )
    v15 = CStateGame::Rand(g_pGame) % 6u;
  v9 = Y16X16::PackXYFast(a2, a3);
  IMovingEntity::SetPositionAndDir((IMovingEntity *)this, v9, v15);
  IMovingEntity::SetDisplacementCosts(10);
  if ( a8 )
  {
    CVehicle::InitBuildingSite(this);
    *((_WORD *)this + 19) = CGfxManager::GetVehicleFirstJob(
                              (CGfxManager *)g_pGfxManager,
                              v16,
                              *((unsigned __int16 *)this + 6));
    *((_BYTE *)this + 109) = CGfxManager::GetVehicleFrameCount(
                               (CGfxManager *)g_pGfxManager,
                               v16,
                               *((unsigned __int16 *)this + 19));
    if ( !*((_BYTE *)this + 109) && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 139, "m_uCycleFrames > 0") == 1 )
      __debugbreak();
    IAnimatedEntity::RegisterForLogicUpdate(16);
  }
  else
  {
    IEntity::SetFlagBits(this, *(EntityFlag *)(*((_DWORD *)this + 25) + 40));
    IEntity::SetFlagBits(this, (EntityFlag)&byte_20300FD[3]);
  }
  *((_BYTE *)this + 69) = 0;
  *((_BYTE *)this + 33) = *(_BYTE *)(*((_DWORD *)this + 25) + 48);
  *((_WORD *)this + 19) = CGfxManager::GetVehicleFirstJob(
                            (CGfxManager *)g_pGfxManager,
                            v16,
                            *((unsigned __int16 *)this + 6));
  *((_BYTE *)this + 109) = CGfxManager::GetVehicleFrameCount(
                             (CGfxManager *)g_pGfxManager,
                             v16,
                             *((unsigned __int16 *)this + 19));
  if ( !*((_BYTE *)this + 109) && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 161, "m_uCycleFrames > 0") == 1 )
    __debugbreak();
  IEntity::SetFlagBits(this, *(EntityFlag *)(*((_DWORD *)this + 25) + 16));
  v10 = IEntity::OwnerId((IEntity *)this);
  v11 = CWalking::Create(*(_DWORD *)(*((_DWORD *)this + 25) + 20), v10);
  std::auto_ptr<CWalking>::auto_ptr<CWalking>(&v13, v11);
  LOBYTE(v18) = 3;
  std::auto_ptr<CWalking>::operator=(&v13);
  v14 = std::auto_ptr<CWalking>::operator->((_DWORD *)this + 20);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v14 + 8))(v14, -1, 0);
  *((_BYTE *)this + 104) = 8;
  *((_BYTE *)this + 105) = 0;
  *((_BYTE *)this + 106) = 0;
  *((_BYTE *)this + 107) = 0;
  *((_BYTE *)this + 108) = 0;
  *((_BYTE *)this + 110) = *(_BYTE *)(*((_DWORD *)this + 25) + 44);
  if ( !*((_BYTE *)this + 110) && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 181, "m_uWalkSteps > 0") == 1 )
    __debugbreak();
  if ( *((unsigned __int8 *)this + 110) >= 0x20u
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 182, "m_uWalkSteps < 32") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 111) = 0;
  *((_BYTE *)this + 112) = 0;
  *((_BYTE *)this + 113) = 0;
  *((_DWORD *)this + 29) = 0;
  std::vector<CEntityTask>::clear();
  LOBYTE(v18) = 2;
  std::auto_ptr<CWalking>::~auto_ptr<CWalking>(&v13);
  return this;
}


// address=[0x15a5160]
// Decompiled from void __thiscall CVehicle::~CVehicle(CVehicle *this)
 CVehicle::~CVehicle(void) {
  
  IMovingEntity *v2; // [esp+0h] [ebp-4h]

  *(_DWORD *)this = &CVehicle::_vftable_;
  CObserverList::~CObserverList((CVehicle *)((char *)this + 156));
  std::vector<CEntityTask>::~vector<CEntityTask>(this);
  IMovingEntity::~IMovingEntity(v2);
}


// address=[0x15a51a0]
// Decompiled from _DWORD *__thiscall CVehicle::CVehicle(_DWORD *this, int a2)
 CVehicle::CVehicle(std::istream & a2) {
  
  int v2; // eax
  unsigned int v4; // [esp+4h] [ebp-20h] BYREF
  unsigned int i; // [esp+Ch] [ebp-18h]
  unsigned int v6; // [esp+10h] [ebp-14h] BYREF
  _DWORD *v7; // [esp+14h] [ebp-10h]
  int v8; // [esp+20h] [ebp-4h]

  v7 = this;
  IMovingEntity::IMovingEntity(this, a2);
  v8 = 0;
  *v7 = &CVehicle::_vftable_;
  std::vector<CEntityTask>::vector<CEntityTask>();
  CObserverList::CObserverList(a2);
  LOBYTE(v8) = 2;
  operator^<unsigned int>(a2, &v6);
  if ( v6 )
  {
    operator^<unsigned char>(a2, v7 + 26);
    operator^<unsigned char>(a2, (char *)v7 + 105);
    operator^<unsigned char>(a2, (char *)v7 + 106);
    operator^<unsigned char>(a2, (char *)v7 + 107);
    operator^<unsigned char>(a2, v7 + 27);
    operator^<unsigned char>(a2, (char *)v7 + 109);
    operator^<unsigned char>(a2, (char *)v7 + 110);
    operator^<unsigned char>(a2, (char *)v7 + 111);
    operator^<unsigned char>(a2, v7 + 28);
    operator^<unsigned char>(a2, (char *)v7 + 113);
    operator^<unsigned int>(a2, v7 + 29);
    operator^<bool>(a2, &CVehicle::m_bCallTakeJob);
    operator^<unsigned char>(a2, v7 + 30);
    operator^<unsigned char>(a2, (char *)v7 + 121);
    operator^<unsigned char>(a2, (char *)v7 + 122);
    operator^<unsigned char>(a2, (char *)v7 + 123);
    operator^<unsigned short>(a2, v7 + 31);
    operator^<unsigned short>(a2, (char *)v7 + 126);
    operator^<unsigned short>(a2, v7 + 32);
    operator^<unsigned short>(a2, (char *)v7 + 130);
    operator^<unsigned short>(a2, v7 + 33);
    operator^<float>(a2, v7 + 34);
    operator^<unsigned char>(a2, (char *)v7 + 69);
    operator^<unsigned int>(a2, &v4);
    for ( i = 0; i < v4; ++i )
    {
      v2 = CEntityTask::Load(a2);
      std::vector<CEntityTask>::push_back(v2);
    }
  }
  if ( v6 >= 2 )
    operator^<unsigned short>(a2, (char *)v7 + 114);
  return v7;
}


// address=[0x15a54a0]
// Decompiled from int __thiscall CVehicle::Store(IMovingEntity *this, struct std::ostream *a1)
void  CVehicle::Store(std::ostream & a2) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-40h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-34h] BYREF
  std::_Iterator_base12 *v5; // [esp+1Ch] [ebp-28h]
  std::_Iterator_base12 *v6; // [esp+20h] [ebp-24h]
  int v7; // [esp+24h] [ebp-20h] BYREF
  int v8; // [esp+28h] [ebp-1Ch] BYREF
  int v9; // [esp+2Ch] [ebp-18h]
  IMovingEntity *v10; // [esp+30h] [ebp-14h]
  char v11; // [esp+37h] [ebp-Dh]
  int v12; // [esp+40h] [ebp-4h]

  v10 = this;
  IMovingEntity::Store(this, a1);
  CObserverList::Store(&v10[1].unk_40, a1);
  v8 = 2;
  operator^<unsigned int>(a1, &v8);
  operator^<unsigned char>(a1, (BYTE *)&v10[1].m_nType);
  operator^<unsigned char>(a1, (BYTE *)&v10[1].m_nType + 1);
  operator^<unsigned char>(a1, &v10[1].unk_e);
  operator^<unsigned char>(a1, &v10[1].unk_f);
  operator^<unsigned char>(a1, (BYTE *)&v10[1].m_psAIEntityInfo);
  operator^<unsigned char>(a1, (BYTE *)&v10[1].m_psAIEntityInfo + 1);
  operator^<unsigned char>(a1, (BYTE *)&v10[1].m_psAIEntityInfo + 2);
  operator^<unsigned char>(a1, (BYTE *)&v10[1].m_psAIEntityInfo + 3);
  operator^<unsigned char>(a1, (BYTE *)&v10[1].m_iFlags);
  operator^<unsigned char>(a1, &v10[1].?);
  operator^<unsigned int>(a1, (int *)&v10[1].m_uPackedXY);
  operator^<bool>(a1, &CVehicle::m_bCallTakeJob);
  operator^<unsigned char>(a1, (BYTE *)&v10[1].m_warMapNode);
  operator^<unsigned char>(a1, &v10[1].m_warMapNode.unk_1d);
  operator^<unsigned char>(a1, (BYTE *)&v10[1].m_warMapNode.next);
  operator^<unsigned char>(a1, (BYTE *)&v10[1].m_warMapNode.next + 1);
  operator^<unsigned short>(a1, (WORD *)&v10[1].m_packedTribePlayer);
  operator^<unsigned short>(a1, (WORD *)&v10[1].pad_22);
  operator^<unsigned short>(a1, (WORD *)&v10[1].m_cFrame);
  operator^<unsigned short>(a1, &v10[1].m_wJobPart);
  operator^<unsigned short>(a1, &v10[1].m_wPrevEntity);
  operator^<float>(a1, &v10[1].m_uLastUpdateTick);
  operator^<unsigned char>(a1, &v10->unk_45);
  v7 = std::vector<CEntityTask>::size(&v10[1].m_uLastLogicUpdate);
  operator^<unsigned int>(a1, &v7);
  std::vector<CEntityTask>::begin(v4);
  v12 = 0;
  while ( 1 )
  {
    v6 = (std::_Iterator_base12 *)std::vector<CEntityTask>::end(v3);
    v5 = v6;
    LOBYTE(v12) = 1;
    v11 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>::operator!=(v6);
    LOBYTE(v12) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>(v3);
    if ( !v11 )
      break;
    v9 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>::operator->(v4);
    (*(void (__thiscall **)(int, struct std::ostream *))(*(_DWORD *)v9 + 4))(v9, a1);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>::operator++(v4);
  }
  v12 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<CEntityTask>>>(v4);
  return operator^<unsigned short>(a1, (WORD *)&v10[1].?);
}


// address=[0x15a57a0]
// Decompiled from void __thiscall CVehicle::GetTurnGfxInfo(CVehicle *this)
void  CVehicle::GetTurnGfxInfo(void) {
  
  unsigned int v1; // [esp+0h] [ebp-20h]
  unsigned int v2; // [esp+10h] [ebp-10h]
  int v3; // [esp+14h] [ebp-Ch]
  int v4; // [esp+18h] [ebp-8h]

  v1 = IEntity::Race(this);
  v4 = CVehicle::TurnDirEx(this);
  v3 = dword_37BEC10[5 * v4];
  if ( v3 )
    v2 = *(_DWORD *)(*((_DWORD *)this + 25) + 32) + v3 - 1;
  else
    v2 = *(_DWORD *)(*((_DWORD *)this + 25) + 28);
  CGfxManager::GetVehicleGfxInfo(
    (CGfxManager *)g_pGfxManager,
    (struct SGfxObjectInfo *)&IEntity::m_sGfxInfo,
    v1,
    v2,
    dword_37BEC14[5 * v4],
    dword_37BEC18[5 * v4],
    0,
    0);
  dword_40FE25C = 0;
}


// address=[0x15a5850]
// Decompiled from unsigned int __thiscall CVehicle::InitTurn(CVehicle *this, int a2)
unsigned int  CVehicle::InitTurn(int a2) {
  
  int v3; // [esp+0h] [ebp-24h]
  int v4; // [esp+4h] [ebp-20h]
  int v5; // [esp+10h] [ebp-14h]
  unsigned int v6; // [esp+14h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-8h]
  unsigned int v9; // [esp+1Ch] [ebp-8h]
  bool v10; // [esp+23h] [ebp-1h]

  v4 = *((char *)this + 68);
  v5 = a2 - v4;
  if ( a2 == v4 )
  {
    *((_BYTE *)this + 105) = 0;
    return 0;
  }
  else
  {
    *((_BYTE *)this + 68) = a2;
    if ( v5 <= 0 )
      v10 = v5 < -3;
    else
      v10 = v5 <= 3;
    v3 = g_sVehicleDirInfos[a2];
    v8 = g_sVehicleDirInfos[v4];
    if ( v10 )
    {
      v9 = (v8 + 1) % 0x10u;
      *((_BYTE *)this + 106) = v9 | 0x80;
    }
    else
    {
      v9 = (v8 + 15) % 0x10u;
      *((_BYTE *)this + 106) = v9;
    }
    v6 = j__abs(v9 - v3);
    if ( v6 > 8 )
      v6 = 16 - v6;
    *((_BYTE *)this + 105) = v6;
    return v6;
  }
}


// address=[0x15a5960]
// Decompiled from int __thiscall CVehicle::TurnVehicle(CVehicle *this, unsigned int a2)
unsigned int  CVehicle::TurnVehicle(unsigned int a2) {
  
  int v3; // [esp+10h] [ebp-10h]
  unsigned int v4; // [esp+14h] [ebp-Ch]

  if ( a2 > *((unsigned __int8 *)this + 105) )
    v4 = *((unsigned __int8 *)this + 105);
  else
    v4 = a2;
  *((_BYTE *)this + 105) -= v4;
  if ( (*((_BYTE *)this + 106) & 0x80) != 0 )
    v3 = v4;
  else
    v3 = -v4;
  *((_BYTE *)this + 106) = *((_BYTE *)this + 106) & 0x80 | (((*((_BYTE *)this + 106) & 0x7Fu) + v3 + 16) % 0x10);
  return a2 - v4;
}


// address=[0x15a5a00]
// Decompiled from int __thiscall CVehicle::TakeJobPart(CVehicle *this, unsigned int a2)
void  CVehicle::TakeJobPart(unsigned int a2) {
  
  unsigned int v2; // eax
  int result; // eax

  v2 = IEntity::Race(this);
  *((_WORD *)this + 19) = a2;
  *((_BYTE *)this + 36) = 0;
  *((_BYTE *)this + 108) = 0;
  *((_BYTE *)this + 109) = CGfxManager::GetVehicleFrameCount((CGfxManager *)g_pGfxManager, v2, a2);
  result = *((unsigned __int8 *)this + 109);
  if ( *((_BYTE *)this + 109) )
    return result;
  result = BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1084, "m_uCycleFrames > 0");
  if ( result == 1 )
    __debugbreak();
  return result;
}


// address=[0x15a5a80]
// Decompiled from char __thiscall CVehicle::NewDestination(CVehicle *this, int a2, int a3, char a4)
bool  CVehicle::NewDestination(int a2, int a3, int a4) {
  
  CEntityTask *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // esi
  CEntityTask *v9; // eax
  CEntityTask *v10; // eax
  CEntityTask *v11; // eax
  unsigned __int8 v12; // al
  CEntityTask *v13; // eax
  unsigned int v14; // esi
  _BYTE v15[24]; // [esp+4h] [ebp-B8h] BYREF
  _BYTE v16[24]; // [esp+1Ch] [ebp-A0h] BYREF
  _BYTE v17[24]; // [esp+34h] [ebp-88h] BYREF
  _BYTE v18[24]; // [esp+4Ch] [ebp-70h] BYREF
  _BYTE v19[24]; // [esp+64h] [ebp-58h] BYREF
  _BYTE v20[32]; // [esp+7Ch] [ebp-40h] BYREF
  int v21; // [esp+9Ch] [ebp-20h]
  unsigned int v22; // [esp+A0h] [ebp-1Ch]
  struct IEntity *v23; // [esp+A4h] [ebp-18h] BYREF
  int v24; // [esp+A8h] [ebp-14h]
  int v25; // [esp+ACh] [ebp-10h]
  unsigned int VehicleFrameCount; // [esp+B0h] [ebp-Ch]
  unsigned int v27; // [esp+B4h] [ebp-8h]
  unsigned __int8 *v28; // [esp+B8h] [ebp-4h]

  v28 = (unsigned __int8 *)this;
  v27 = *(_DWORD *)(*((_DWORD *)this + 25) + 24);
  v22 = IEntity::Race(this);
  VehicleFrameCount = CGfxManager::GetVehicleFrameCount((CGfxManager *)g_pGfxManager, v22, v27);
  if ( (a4 & 1) != 0 )
  {
    if ( !v28[113] )
    {
      if ( (a4 & 2) == 0 )
      {
        std::vector<CEntityTask>::clear();
        v28[112] = 0;
      }
      v11 = CEntityTask::CEntityTask((CEntityTask *)v16, 8, v27, -1, -1, -1, VehicleFrameCount, -1, 1, 1, 0, 0, 0, 0);
      std::vector<CEntityTask>::push_back(v11);
      v12 = std::vector<CEntityTask>::size(v28 + 140);
      v28[113] = v12;
    }
    v13 = CEntityTask::CEntityTask((CEntityTask *)v15, 8, v27, a2, a3, -1, VehicleFrameCount, -1, 1, 1, 0, 0, 0, 0);
    std::vector<CEntityTask>::push_back(v13);
  }
  else
  {
    if ( (a4 & 2) != 0 )
    {
      if ( v28[113] )
        return 0;
    }
    else
    {
      std::vector<CEntityTask>::clear();
      v28[112] = 0;
      v28[113] = 0;
    }
    if ( (a4 & 4) != 0 )
      v24 = 6;
    else
      v24 = 7;
    v21 = v24;
    if ( (a4 & 0x10) != 0 )
    {
      if ( (a4 & 4) != 0
        && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1277, "( _iFlags & COMMAND_FLAG_GOTO ) == 0") == 1 )
      {
        __debugbreak();
      }
      v5 = CEntityTask::CEntityTask((CEntityTask *)v19, 36, v27, 0, 0, -1, VehicleFrameCount, -1, 1, 1, 0, 0, 0, 0);
      std::vector<CEntityTask>::push_back(v5);
    }
    else
    {
      v25 = 0;
      if ( v28[10] == 2 && (a4 & 4) != 0 )
      {
        v6 = IEntity::OwnerId(v28);
        v7 = CAlliances::PlayerBit(v6);
        CWarriorEntitySpiralWalk::CWarriorEntitySpiralWalk((CWarriorEntitySpiralWalk *)v20, a2, a3, 10, v7, 3072);
        while ( CWarriorEntitySpiralWalk::NextEntity((CWarriorEntitySpiralWalk *)v20, &v23) )
        {
          v8 = IEntity::ID();
          if ( v8 != IEntity::ID() )
          {
            v25 = IEntity::ID();
            break;
          }
        }
      }
      if ( v25 )
      {
        v10 = CEntityTask::CEntityTask((CEntityTask *)v17, 10, v27, 0, 0, -1, VehicleFrameCount, -1, 1, 1, 0, v25, 0, 0);
        std::vector<CEntityTask>::push_back(v10);
      }
      else
      {
        v9 = CEntityTask::CEntityTask((CEntityTask *)v18, v21, v27, a2, a3, -1, VehicleFrameCount, -1, 1, 1, 0, 0, 0, 0);
        std::vector<CEntityTask>::push_back(v9);
      }
    }
  }
  if ( !std::vector<CEntityTask>::size(v28 + 140)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1403, "m_vTasks.size() > 0") == 1 )
  {
    __debugbreak();
  }
  v14 = v28[112];
  if ( v14 > std::vector<CEntityTask>::size(v28 + 140)
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1404, "m_uCurrentTaskIdx1 <= m_vTasks.size()") == 1 )
  {
    __debugbreak();
  }
  if ( v28[112] )
    return 0;
  v28[112] = 1;
  return 1;
}


// address=[0x15a5dc0]
// Decompiled from int __thiscall CVehicle::GetNextJob(CVehicle *this)
void  CVehicle::GetNextJob(void) {
  
  unsigned int v1; // esi

  v1 = *((unsigned __int8 *)this + 112);
  if ( v1 < std::vector<CEntityTask>::size((char *)this + 140) )
  {
    ++*((_BYTE *)this + 112);
  }
  else
  {
    *((_BYTE *)this + 112) = *((_BYTE *)this + 113);
    if ( !*((_BYTE *)this + 113) )
      std::vector<CEntityTask>::clear();
  }
  return (*(int (__thiscall **)(CVehicle *))(*(_DWORD *)this + 188))(this);
}


// address=[0x15a5e30]
// Decompiled from void __thiscall CVehicle::DetachWithoutNotify(CVehicle *this, int a2)
void  CVehicle::DetachWithoutNotify(int a2) {
  
  CObserverList::Detach((CVehicle *)((char *)this + 156), a2);
}


// address=[0x15a5e50]
// Decompiled from CVehicle *__thiscall CVehicle::SetReadyToFireTick(CVehicle *this, unsigned int a2)
void  CVehicle::SetReadyToFireTick(unsigned int a2) {
  
  CVehicle *result; // eax

  result = this;
  *((_DWORD *)this + 29) = *(_DWORD *)(*((_DWORD *)this + 25) + 76) + a2;
  return result;
}


// address=[0x15a5e70]
// Decompiled from bool __thiscall CVehicle::EnoughAmmo(CVehicle *this)
bool  CVehicle::EnoughAmmo(void)const {
  
  return *((_BYTE *)this + 111) != 0;
}


// address=[0x15a5ea0]
// Decompiled from int __thiscall CVehicle::AmmoAmount(CVehicle *this)
unsigned int  CVehicle::AmmoAmount(void)const {
  
  return *((unsigned __int8 *)this + 111);
}


// address=[0x15a5ec0]
// Decompiled from CVehicle *__thiscall CVehicle::DecreaseAmmo(CVehicle *this)
void  CVehicle::DecreaseAmmo(void) {
  
  CVehicle *result; // eax

  result = this;
  if ( !*((_BYTE *)this + 111) )
    return result;
  result = this;
  --*((_BYTE *)this + 111);
  return result;
}


// address=[0x15a5ef0]
// Decompiled from int __thiscall CVehicle::AttackTarget(CVehicle *this, int a2)
void  CVehicle::AttackTarget(int a2) {
  
  Y16X16 *v2; // eax
  unsigned int TickCounter; // eax
  int v5; // [esp-4h] [ebp-24h]
  unsigned int v6; // [esp+0h] [ebp-20h]
  int v7; // [esp+4h] [ebp-1Ch]
  int v8; // [esp+8h] [ebp-18h]
  int v9; // [esp+10h] [ebp-10h]
  int v10; // [esp+14h] [ebp-Ch]
  struct IEntity *v11; // [esp+18h] [ebp-8h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1096, "_iTargetId != 0") == 1 )
    __debugbreak();
  v11 = CMapObjectMgr::Entity(a2);
  if ( !IEntity::WarriorType()
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1100, "rTargetEntity.WarriorType() != WARRIOR_TYPE_NONE") == 1 )
  {
    __debugbreak();
  }
  if ( !IEntity::FlagBits(v11, (EntityFlag)((char *)&loc_1FFFFFF + 1))
    && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1101, "rTargetEntity.FlagBits( ENTITY_FLAG_READY ) != 0") == 1 )
  {
    __debugbreak();
  }
  v5 = IEntity::PackedXY(v11);
  v2 = (Y16X16 *)IEntity::PackedXY(this);
  v9 = Y16X16::DirectionFast(v2, v5);
  v6 = *(_DWORD *)(*((_DWORD *)this + 25) + 72) + CVehicle::InitTurn(this, v9);
  v7 = IEntity::ID();
  v8 = IEntity::PackedXY(v11);
  v10 = CLogic::FutureEvents(g_pLogic);
  (*(void (__thiscall **)(int, int, unsigned int, int, int, int))(*(_DWORD *)v10 + 12))(v10, 6, v6, v7, a2, v8);
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  CVehicle::SetReadyToFireTick(this, TickCounter);
  return (*(int (__thiscall **)(CVehicle *))(*(_DWORD *)this + 212))(this);
}


// address=[0x15a6040]
// Decompiled from void __thiscall CVehicle::WalkDirAndRegister(CVehicle *this, int a2, bool a3)
void  CVehicle::WalkDirAndRegister(int a2, bool a3) {
  
  int v3; // eax
  unsigned int v4; // [esp+Ch] [ebp-10h]
  unsigned int v5; // [esp+10h] [ebp-Ch]

  (*(void (__thiscall **)(CVehicle *, int))(*(_DWORD *)this + 216))(this, a2);
  if ( (*((_BYTE *)this + 104) & 0x70) != 0 && a3 )
  {
    CVehicle::GetNextJob(this);
  }
  else
  {
    if ( *((_BYTE *)this + 107) == 17 )
      v5 = 17;
    else
      v5 = 6;
    v4 = *(_DWORD *)(*((_DWORD *)this + 25) + 24);
    if ( (*((_BYTE *)this + 104) & 0xFu) >= 6 )
    {
      if ( (*((_BYTE *)this + 104) & 8) == 0
        && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1158, "( m_uWalkResult & WALK_RESULT_FLAG_DONT_MOVE ) != 0") == 1 )
      {
        __debugbreak();
      }
      if ( *((_BYTE *)this + 105)
        && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1159, "( m_uTurnCounter == 0 )") == 1 )
      {
        __debugbreak();
      }
      CVehicle::RegisterNewTaskAndTakeJobPartIfNecessary(this, v5, 1u, v4);
    }
    else
    {
      if ( (*((_BYTE *)this + 104) & 8) != 0
        && BBSupportDbgReport(2, "MapObjects\\Vehicle.cpp", 1150, "( m_uWalkResult & WALK_RESULT_FLAG_DONT_MOVE ) == 0") == 1 )
      {
        __debugbreak();
      }
      v3 = CVehicle::TurnCounter(this);
      CVehicle::RegisterNewTaskAndTakeJobPartIfNecessary(this, v5, *((unsigned __int8 *)this + 110) + v3, v4);
    }
  }
}


// address=[0x15a61a0]
// Decompiled from CVehicle *__thiscall CVehicle::InitCommonTaskValues(CVehicle *this, const struct CEntityTask *a2)
void  CVehicle::InitCommonTaskValues(class CEntityTask const * a2) {
  
  CVehicle *result; // eax

  if ( a2 )
  {
    if ( *((char *)a2 + 6) >= 0 )
      *((_BYTE *)this + 68) = *((_BYTE *)a2 + 6);
    if ( *((_BYTE *)a2 + 20) )
      IEntity::SetFlagBits(this, EntityFlag_Visible);
    else
      IEntity::ClearFlagBits(this, EntityFlag_Visible);
    *((_BYTE *)this + 107) = *((_BYTE *)a2 + 4);
    CVehicle::TakeJobPart(this, *((unsigned __int16 *)a2 + 7));
  }
  else
  {
    IEntity::SetFlagBits(this, EntityFlag_Visible);
    *((_BYTE *)this + 107) = 17;
    CVehicle::TakeJobPart(this, *(_DWORD *)(*((_DWORD *)this + 25) + 24));
  }
  *((_BYTE *)this + 104) = 8;
  *((_BYTE *)this + 105) = 0;
  result = this;
  *((_BYTE *)this + 69) = 0;
  return result;
}


// address=[0x15a6250]
// Decompiled from void __thiscall CVehicle::ConvertEventIntoGoal(CVehicle *this, struct CEntityEvent *a2)
void  CVehicle::ConvertEventIntoGoal(class CEntityEvent * a2) {
  
  char v2; // al
  char v3; // al
  int v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+4h] [ebp-10h]
  int v7; // [esp+10h] [ebp-4h]

  v7 = *((_DWORD *)a2 + 1);
  if ( v7 == 13 )
  {
    v2 = CVehicle::NewDestination(this, *((_DWORD *)a2 + 4), *((_DWORD *)a2 + 5), *((_DWORD *)a2 + 3));
    CVehicle::NotifyCallTakeJob(v2);
  }
  else if ( v7 == 17 && *((_DWORD *)a2 + 2) == 13 )
  {
    v4 = Y16X16::UnpackXFast(*((_DWORD *)a2 + 4));
    v5 = Y16X16::UnpackYFast(*((_DWORD *)a2 + 4));
    v3 = CVehicle::NewDestination(this, v4, v5, *((_DWORD *)a2 + 3));
    CVehicle::NotifyCallTakeJob(v3);
  }
}


// address=[0x15a6300]
// Decompiled from int __thiscall CVehicle::MoveTo(CVehicle *this, int a2, int a3, int a4)
void  CVehicle::MoveTo(int a2, int a3, int a4) {
  
  int v4; // eax
  _BYTE v6[24]; // [esp+4h] [ebp-30h] BYREF
  CEntityEvent *v7; // [esp+1Ch] [ebp-18h]
  CEntityEvent *v8; // [esp+20h] [ebp-14h]
  CVehicle *v9; // [esp+24h] [ebp-10h]
  int v10; // [esp+30h] [ebp-4h]

  v9 = this;
  v4 = Y16X16::PackXYFast(a2, a3);
  v8 = CEntityEvent::CEntityEvent((CEntityEvent *)v6, 0x11u, 13, 0, v4, 0);
  v7 = v8;
  v10 = 0;
  (*(void (__thiscall **)(CVehicle *, CEntityEvent *))(*(_DWORD *)v9 + 80))(v9, v8);
  v10 = -1;
  return CEntityEvent::~CEntityEvent(v6);
}


// address=[0x15a7a20]
// Decompiled from char CVehicle::CallTakeJob()
bool __cdecl CVehicle::CallTakeJob(void) {
  
  return CVehicle::m_bCallTakeJob;
}


// address=[0x15a7a30]
// Decompiled from void CVehicle::ClearCallTakeJob()
void __cdecl CVehicle::ClearCallTakeJob(void) {
  
  CVehicle::m_bCallTakeJob = 0;
}


// address=[0x15a7ae0]
// Decompiled from bool __thiscall CVehicle::IsMoving(CVehicle *this)
bool  CVehicle::IsMoving(void)const {
  
  return (*((_BYTE *)this + 104) & 8) == 0;
}


// address=[0x15a7b20]
// Decompiled from int __cdecl CVehicle::NotifyCallTakeJob(bool a1)
void __cdecl CVehicle::NotifyCallTakeJob(bool a1) {
  
  int result; // eax

  result = a1 | (unsigned __int8)CVehicle::m_bCallTakeJob;
  CVehicle::m_bCallTakeJob |= a1;
  return result;
}


// address=[0x15a7b40]
// Decompiled from void __thiscall CVehicle::RegisterNewTaskAndTakeJobPartIfNecessary(CVehicle *this, char a2, int a3, unsigned int a4)
void  CVehicle::RegisterNewTaskAndTakeJobPartIfNecessary(unsigned int a2, unsigned int a3, unsigned int a4) {
  
  CVehicle::RegisterNewTask(this, a2, a3);
  CVehicle::TakeJobPartIfNecessary(this, a4);
}


// address=[0x15a7be0]
// Decompiled from CVehicle *__thiscall CVehicle::TakeJobPartIfNecessary(CVehicle *this, unsigned int a2)
void  CVehicle::TakeJobPartIfNecessary(unsigned int a2) {
  
  CVehicle *result; // eax

  result = this;
  if ( *((unsigned __int16 *)this + 19) != a2 )
    return (CVehicle *)CVehicle::TakeJobPart(this, a2);
  return result;
}


// address=[0x4158cfe]
// [Decompilation failed for static bool CVehicle::m_bCallTakeJob]

// address=[0x153a570]
// Decompiled from void __thiscall CVehicle::NotifyDetach(CVehicle *this, int a2)
void  CVehicle::NotifyDetach(int a2) {
  
  ;
}


