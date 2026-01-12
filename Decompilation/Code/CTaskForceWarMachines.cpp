#include "CTaskForceWarMachines.h"

// Definitions for class CTaskForceWarMachines

// address=[0x132a200]
// Decompiled from _DWORD *__thiscall CTaskForceWarMachines::CTaskForceWarMachines(_DWORD *this, int a2, int a3, int a4)

 CTaskForceWarMachines::CTaskForceWarMachines(int,enum T_AI_TASK_FORCE_TYPE,int) {
  
  CAITaskForceEx::CAITaskForceEx(this, a2, 4, a3, a4);
  *this = CTaskForceWarMachines::_vftable_;
  return this;
}


// address=[0x132a2e0]
// Decompiled from void __thiscall CTaskForceWarMachines::~CTaskForceWarMachines(CTaskForceWarMachines *this)

 CTaskForceWarMachines::~CTaskForceWarMachines(void) {
  
  CAITaskForceEx::~CAITaskForceEx(this);
}


// address=[0x132c940]
// Decompiled from char __thiscall CTaskForceWarMachines::IsAddEntityOk(CTaskForceWarMachines *this, int a2)

bool  CTaskForceWarMachines::IsAddEntityOk(int) {
  
  if ( IAIEnvironment::EntityWarriorType(a2) == 8 )
  {
    if ( CAITaskForce::NumberOfEntities(this) >= 1 )
    {
      IAIEnvironment::DbgTracePrintF("CTaskForceWarMachines::IsAddEntityOk(): Entity limit reached!");
      return 0;
    }
    else
    {
      return 1;
    }
  }
  else
  {
    IAIEnvironment::DbgTracePrintF("CTaskForceWarMachines::IsAddEntityOk(): Entity %i is not a war machine!", a2);
    return 0;
  }
}


// address=[0x132c9a0]
// Decompiled from int __thiscall CTaskForceWarMachines::InitWarMachineWalk(CTaskForceWarMachines *this, bool a2)

void  CTaskForceWarMachines::InitWarMachineWalk(bool) {
  
  int result; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-14h]
  int v6; // [esp+4h] [ebp-10h]
  int v7; // [esp+8h] [ebp-Ch]

  result = CAITaskForce::FirstEntity(this);
  if ( !result )
    return result;
  v5 = CAIEntityInfo::EntityId(result);
  result = CAITaskForceEx::WaypointXY(this);
  if ( result <= 0 )
    return result;
  v3 = CAITaskForceEx::WaypointXY(this);
  v6 = Y16X16::UnpackXFast(v3);
  v4 = CAITaskForceEx::WaypointXY(this);
  v7 = Y16X16::UnpackYFast(v4);
  return IAIEnvironment::MovingEntitySendMoveCommand(v5, v6, v7, a2);
}


// address=[0x132ca20]
// Decompiled from int __thiscall CTaskForceWarMachines::CatapultSectorId(CTaskForceWarMachines *this)

int  CTaskForceWarMachines::CatapultSectorId(void)const {
  
  struct _Cnd_internal_imp_t *v2; // [esp+0h] [ebp-18h] BYREF
  struct _Mtx_internal_imp_t *v3[2]; // [esp+4h] [ebp-14h] BYREF
  int v4; // [esp+Ch] [ebp-Ch]
  int v5; // [esp+10h] [ebp-8h]
  int Entity; // [esp+14h] [ebp-4h]

  v3[1] = this;
  v4 = 0;
  Entity = CAITaskForce::FirstEntity(this);
  if ( !Entity )
    return v4;
  v5 = CAIEntityInfo::EntityId(Entity);
  if ( v5 <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 2305, "iEntityId > 0") == 1 )
    __debugbreak();
  IAIEnvironment::EntityGetPosition(v5, (int *)&v2, (int *)v3);
  return IAIEnvironment::WorldCatapultSectorId(v2, v3[0]);
}


// address=[0x132caa0]
// Decompiled from int __thiscall CTaskForceWarMachines::CalculateBuildingDestination(CTaskForceWarMachines *this, int a2)

int  CTaskForceWarMachines::CalculateBuildingDestination(int) {
  
  int v3; // [esp+0h] [ebp-14h] BYREF
  int v4; // [esp+4h] [ebp-10h] BYREF
  CTaskForceWarMachines *v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  v5 = this;
  v6 = -1;
  if ( a2 <= 0 )
    return v6;
  v7 = CTaskForceWarMachines::CatapultSectorId(v5);
  if ( v7 <= 0 )
    return v6;
  IAIEnvironment::BuildingGetEnsignPosition(a2, &v3, &v4);
  return IAIEnvironment::FindNearestCatapultSectorPosition(v7, v3, v4, 15);
}


// address=[0x132cb00]
// Decompiled from int __thiscall CTaskForceWarMachines::CheckBuildingDestination(CTaskForceWarMachines *this)

void  CTaskForceWarMachines::CheckBuildingDestination(void) {
  
  int result; // eax
  struct _iobuf *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-10h]
  int v6; // [esp+4h] [ebp-Ch]
  int v7; // [esp+8h] [ebp-8h]

  if ( !CAITaskForce::GoalIsEntity(this)
    && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 2325, "GoalIsEntity()") == 1 )
  {
    __debugbreak();
  }
  result = CAITaskForce::CmdGoal(this);
  v5 = result;
  if ( result <= 0 )
    return result;
  v7 = CTaskForceWarMachines::CatapultSectorId(this);
  if ( v7 <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 2333, "iCatapultSectorId > 0") == 1 )
    __debugbreak();
  v6 = 0;
  if ( (int)CAITaskForceEx::DestinationXY(this) > 0 )
  {
    v2 = (struct _iobuf *)CAITaskForceEx::DestinationXY(this);
    IAIEnvironment::WorldCatapultSectorIdPackedXY(v2);
    v6 = v3;
  }
  result = v7;
  if ( v7 == v6 )
    return result;
  v4 = CTaskForceWarMachines::CalculateBuildingDestination(this, v5);
  return (*(int (__thiscall **)(CTaskForceWarMachines *, int))(*(_DWORD *)this + 44))(this, v4);
}


// address=[0x132cbd0]
// Decompiled from int __thiscall CTaskForceWarMachines::Execute(CTaskForceWarMachines *this)

void  CTaskForceWarMachines::Execute(void) {
  
  int result; // eax
  int v2; // esi
  int v3; // [esp+Ch] [ebp-14h]
  int v4; // [esp+18h] [ebp-8h]

  CAITaskForce::SetWaitCounter(this, 8u);
  v4 = 0;
  while ( 2 )
  {
    if ( v4 >= 10 )
    {
      if ( BBSupportDbgReport(
             1,
             "AI\\AI_TaskForcesEx.cpp",
             2455,
             "CTaskForceWarMachines::Execute(): Endless loop detected!") == 1 )
        __debugbreak();
      return 0;
    }
    else
    {
      result = CAITaskForce::State(this);
      switch ( result )
      {
        case 0:
        case 100:
          return result;
        case 101:
          result = CAITaskForce::FirstEntity(this);
          if ( !result )
            return result;
          v3 = CAIEntityInfo::EntityId(result);
          if ( v3 <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 2388, "iEntityId > 0") == 1 )
            __debugbreak();
          result = IAIEnvironment::MovingEntityWalkingState(v3);
          if ( result >= 64 )
            return result;
          CAITaskForce::SetState(this, 103);
          goto LABEL_2;
        case 102:
          CAITaskForceEx::FindWaypoints(this);
          CTaskForceWarMachines::InitWarMachineWalk(this, 0);
          CAITaskForce::SetWaitCounter(this, 0x20u);
          return (int)CAITaskForce::SetState(this, 101);
        case 103:
          v2 = CAITaskForceEx::WaypointXY(this);
          if ( v2 == CAITaskForceEx::DestinationXY(this) )
          {
            CTaskForceWarMachines::InitWarMachineWalk(this, 1);
            CAITaskForceEx::ClearWaypoints(this);
            CAITaskForce::ActivateNextState(this);
LABEL_2:
            ++v4;
            continue;
          }
          CAITaskForceEx::PopWaypoint(this);
          if ( !CAITaskForceEx::WaypointAvailable(this) )
          {
            CTaskForceWarMachines::CheckBuildingDestination(this);
            CAITaskForceEx::FindWaypoints(this);
          }
          if ( !CAITaskForceEx::WaypointAvailable(this) )
          {
            CAITaskForce::ActivateNextState(this);
            goto LABEL_2;
          }
          result = CTaskForceWarMachines::InitWarMachineWalk(this, 0);
          break;
        default:
          if ( BBSupportDbgReport(
                 1,
                 "AI\\AI_TaskForcesEx.cpp",
                 2446,
                 "CTaskForceWarMachines::Execute(): Invalid state!") == 1 )
            __debugbreak();
          return CAITaskForce::SetNewStatusAndState(this, 1, 0, 0);
      }
    }
    return result;
  }
}


