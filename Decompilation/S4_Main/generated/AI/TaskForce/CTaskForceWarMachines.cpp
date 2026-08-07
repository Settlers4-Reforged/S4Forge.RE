#if FALSE
#include "CTaskForceWarMachines.h"

// Definitions for class CTaskForceWarMachines

// address=[0x132a200]
// Decompiled from CTaskForceWarMachines *__thiscall CTaskForceWarMachines::CTaskForceWarMachines(CTaskForceWarMachines *this, int a2, int a3, int a4)
 CTaskForceWarMachines::CTaskForceWarMachines(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4) {
  
  CAITaskForceEx::CAITaskForceEx(this, a2, 4, a3, a4);
  this->__vftable = (CAITaskForceEx_vtbl *)CTaskForceWarMachines::_vftable_;
  return this;
}


// address=[0x132a2e0]
// Decompiled from void __thiscall CTaskForceWarMachines::~CTaskForceWarMachines(CTaskForceWarMachines *this)
 CTaskForceWarMachines::~CTaskForceWarMachines(void) {
  
  CAITaskForceEx::~CAITaskForceEx(this);
}


// address=[0x132c940]
// Decompiled from char __thiscall CTaskForceWarMachines::IsAddEntityOk(CTaskForceWarMachines *this, int a2)
bool  CTaskForceWarMachines::IsAddEntityOk(int a2) {
  
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
// Decompiled from void __thiscall CTaskForceWarMachines::InitWarMachineWalk(CTaskForceWarMachines *this, bool a2)
void  CTaskForceWarMachines::InitWarMachineWalk(bool a2) {
  
  DWORD v2; // eax
  DWORD v3; // eax
  int v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  CAIEntityInfo *Entity; // [esp+Ch] [ebp-8h]

  Entity = CAITaskForce::FirstEntity(this);
  if ( Entity )
  {
    v4 = CAIEntityInfo::EntityId(Entity);
    if ( (int)CAITaskForceEx::WaypointXY(this) > 0 )
    {
      v2 = CAITaskForceEx::WaypointXY(this);
      v5 = Y16X16::UnpackXFast(v2);
      v3 = CAITaskForceEx::WaypointXY(this);
      v6 = Y16X16::UnpackYFast(v3);
      IAIEnvironment::MovingEntitySendMoveCommand(v4, v5, v6, a2);
    }
  }
}


// address=[0x132ca20]
// Decompiled from int __thiscall CTaskForceWarMachines::CatapultSectorId(CTaskForceWarMachines *this)
int  CTaskForceWarMachines::CatapultSectorId(void)const {
  
  int v2; // [esp+0h] [ebp-18h] BYREF
  int v3; // [esp+4h] [ebp-14h] BYREF
  int v5; // [esp+Ch] [ebp-Ch]
  int iEntityId; // [esp+10h] [ebp-8h]
  CAIEntityInfo *Entity; // [esp+14h] [ebp-4h]

  v5 = 0;
  Entity = CAITaskForce::FirstEntity(this);
  if ( !Entity )
  {
    return v5;
  }
  iEntityId = CAIEntityInfo::EntityId(Entity);
  if ( iEntityId <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 2305, "iEntityId > 0") == 1 )
  {
    __debugbreak();
  }
  IAIEnvironment::EntityGetPosition(iEntityId, &v2, &v3);
  return IAIEnvironment::WorldCatapultSectorId(v2, v3);
}


// address=[0x132caa0]
// Decompiled from int __thiscall CTaskForceWarMachines::CalculateBuildingDestination(CTaskForceWarMachines *this, int a2)
int  CTaskForceWarMachines::CalculateBuildingDestination(int a2) {
  
  int v3; // [esp+0h] [ebp-14h] BYREF
  int v4; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  v6 = -1;
  if ( a2 <= 0 )
  {
    return v6;
  }
  v7 = CTaskForceWarMachines::CatapultSectorId(this);
  if ( v7 <= 0 )
  {
    return v6;
  }
  IAIEnvironment::BuildingGetEnsignPosition(a2, &v3, &v4);
  return IAIEnvironment::FindNearestCatapultSectorPosition(v7, v3, v4, 15);
}


// address=[0x132cb00]
// Decompiled from void __thiscall CTaskForceWarMachines::CheckBuildingDestination(CTaskForceWarMachines *this)
void  CTaskForceWarMachines::CheckBuildingDestination(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int iCatapultSectorId; // [esp+8h] [ebp-8h]

  if ( !CAITaskForce::GoalIsEntity(this) && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 2325, "GoalIsEntity()") == 1 )
  {
    __debugbreak();
  }
  v3 = CAITaskForce::CmdGoal(this);
  if ( v3 > 0 )
  {
    iCatapultSectorId = CTaskForceWarMachines::CatapultSectorId(this);
    if ( iCatapultSectorId <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 2333, "iCatapultSectorId > 0") == 1 )
    {
      __debugbreak();
    }
    v4 = 0;
    if ( CAITaskForceEx::DestinationXY(this) > 0 )
    {
      v1 = CAITaskForceEx::DestinationXY(this);
      v4 = IAIEnvironment::WorldCatapultSectorIdPackedXY(v1);
    }
    if ( iCatapultSectorId != v4 )
    {
      v2 = CTaskForceWarMachines::CalculateBuildingDestination(this, v3);
      this->SetDestinationXY(this, v2);
    }
  }
}


// address=[0x132cbd0]
// Decompiled from void __thiscall CTaskForceWarMachines::Execute(CTaskForceWarMachines *this)
void  CTaskForceWarMachines::Execute(void) {
  
  DWORD v1; // esi
  int iEntityId; // [esp+Ch] [ebp-14h]
  CAIEntityInfo *Entity; // [esp+10h] [ebp-10h]
  int v4; // [esp+18h] [ebp-8h]

  CAITaskForce::SetWaitCounter(this, 8u);
  v4 = 0;
  while ( 2 )
  {
    if ( v4 >= 10 )
    {
      if ( BBSupportDbgReport(1, "AI\\AI_TaskForcesEx.cpp", 2455, "CTaskForceWarMachines::Execute(): Endless loop detected!") == 1 )
      {
        __debugbreak();
      }
    }
    else
    {
      switch ( CAITaskForce::State(this) )
      {
        case 0:
        case 100:
          return;
        case 101:
          Entity = CAITaskForce::FirstEntity(this);
          if ( !Entity )
          {
            return;
          }
          iEntityId = CAIEntityInfo::EntityId(Entity);
          if ( iEntityId <= 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 2388, "iEntityId > 0") == 1 )
          {
            __debugbreak();
          }
          if ( IAIEnvironment::MovingEntityWalkingState(iEntityId) >= 64 )
          {
            return;
          }
          CAITaskForce::SetState(this, 103);
          goto LABEL_2;
        case 102:
          CAITaskForceEx::FindWaypoints(this);
          CTaskForceWarMachines::InitWarMachineWalk(this, 0);
          CAITaskForce::SetWaitCounter(this, 0x20u);
          CAITaskForce::SetState(this, 101);
          return;
        case 103:
          v1 = CAITaskForceEx::WaypointXY(this);
          if ( v1 == CAITaskForceEx::DestinationXY(this) )
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
          CTaskForceWarMachines::InitWarMachineWalk(this, 0);
          break;
        default:
          if ( BBSupportDbgReport(1, "AI\\AI_TaskForcesEx.cpp", 2446, "CTaskForceWarMachines::Execute(): Invalid state!") == 1 )
          {
            __debugbreak();
          }
          CAITaskForce::SetNewStatusAndState(this, 1, 0, 0);
          return;
      }
    }
    break;
  }
}


#endif // Already implemented
