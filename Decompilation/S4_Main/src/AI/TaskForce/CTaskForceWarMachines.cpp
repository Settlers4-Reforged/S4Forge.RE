#include "CTaskForceWarMachines.h"

#include "AI/CAIEntityInfo.h"
#include "AI/IAIEnvironment.h"
#include "CBB/CBBSupport.h"
#include "World/helper.h"


// Definitions for class CTaskForceWarMachines

// address=[0x132a200]
// Decompiled from CTaskForceWarMachines *__thiscall CTaskForceWarMachines::CTaskForceWarMachines(  CTaskForceWarMachines *this,  int a2,  int a3,  int a4)
CTaskForceWarMachines::CTaskForceWarMachines(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4) : ::CAITaskForceEx(a2, AI_TASK_FORCE_CLASS_WARMACHINES, a3, a4) {}


// address=[0x132a2e0]
// Decompiled from void __thiscall CTaskForceWarMachines::~CTaskForceWarMachines(CTaskForceWarMachines *this)
CTaskForceWarMachines::~CTaskForceWarMachines(void) = default;


// address=[0x132c940]
// Decompiled from char __thiscall CTaskForceWarMachines::IsAddEntityOk(CTaskForceWarMachines *this, int a2)
bool CTaskForceWarMachines::IsAddEntityOk(int a2) {
  if(IAIEnvironment::EntityWarriorType(a2) == 8) {
    if(this->NumberOfEntities() >= 1) {
      IAIEnvironment::DbgTracePrintF("CTaskForceWarMachines::IsAddEntityOk(): Entity limit reached!");
      return 0;
    } else {
      return 1;
    }
  } else {
    IAIEnvironment::DbgTracePrintF("CTaskForceWarMachines::IsAddEntityOk(): Entity %i is not a war machine!", a2);
    return 0;
  }
}


// address=[0x132c9a0]
// Decompiled from void __thiscall CTaskForceWarMachines::InitWarMachineWalk(CTaskForceWarMachines *this, bool a2)
void CTaskForceWarMachines::InitWarMachineWalk(bool a2) {
  // eax
  // eax
  // [esp+0h] [ebp-14h]
  // [esp+4h] [ebp-10h]
  // [esp+8h] [ebp-Ch]
  // [esp+Ch] [ebp-8h]

  CAIEntityInfo *pEntity = this->FirstEntity();
  if(pEntity) {
    int v4 = pEntity->EntityId();
    if((int) this->WaypointXY() > 0) {
      DWORD v2 = this->WaypointXY();
      int   v5 = Y16X16::UnpackXFast(v2);
      DWORD v3 = this->WaypointXY();
      int   v6 = Y16X16::UnpackYFast(v3);
      IAIEnvironment::MovingEntitySendMoveCommand(v4, v5, v6, a2);
    }
  }
}


// address=[0x132ca20]
// Decompiled from int __thiscall CTaskForceWarMachines::CatapultSectorId(CTaskForceWarMachines *this)
int CTaskForceWarMachines::CatapultSectorId(void) const {
  int v2; // [esp+0h] [ebp-18h] BYREF
  int v3; // [esp+4h] [ebp-14h] BYREF
  // [esp+Ch] [ebp-Ch]
  // [esp+10h] [ebp-8h]
  // [esp+14h] [ebp-4h]

  int            v5 = 0;
  CAIEntityInfo *pEntity = this->FirstEntity();
  if(!pEntity)
    return v5;
  int iEntityId = pEntity->EntityId();
  BB_ASSERT(iEntityId > 0)
  IAIEnvironment::EntityGetPosition(iEntityId, v2, v3);
  return IAIEnvironment::WorldCatapultSectorId(v2, v3);
}


// address=[0x132caa0]
// Decompiled from int __thiscall CTaskForceWarMachines::CalculateBuildingDestination(CTaskForceWarMachines *this, int a2)
int CTaskForceWarMachines::CalculateBuildingDestination(int a2) {
  int v3; // [esp+0h] [ebp-14h] BYREF
  int v4; // [esp+4h] [ebp-10h] BYREF
  // [esp+Ch] [ebp-8h]
  // [esp+10h] [ebp-4h]

  if(a2 <= 0)
    return -1;
  int v7 = this->CatapultSectorId();
  if(v7 <= 0)
    return -1;
  IAIEnvironment::BuildingGetEnsignPosition(a2, v3, v4);
  return IAIEnvironment::FindNearestCatapultSectorPosition(v7, v3, v4, 15);
}


// address=[0x132cb00]
// Decompiled from void __thiscall CTaskForceWarMachines::CheckBuildingDestination(CTaskForceWarMachines *this)
void CTaskForceWarMachines::CheckBuildingDestination(void) {
  // eax
  // eax
  // [esp+0h] [ebp-10h]
  // [esp+4h] [ebp-Ch]
  // [esp+8h] [ebp-8h]

  BB_ASSERT(GoalIsEntity())
  int v3 = this->CmdGoal();
  if(v3 > 0) {
    int iCatapultSectorId = this->CatapultSectorId();
    BB_ASSERT(iCatapultSectorId > 0)

    int v4 = 0;
    if(this->DestinationXY() > 0) {
      int v1 = this->DestinationXY();
      v4 = IAIEnvironment::WorldCatapultSectorIdPackedXY(v1);
    }
    if(iCatapultSectorId != v4) {
      int v2 = this->CalculateBuildingDestination(v3);
      this->SetDestinationXY(v2);
    }
  }
}


// address=[0x132cbd0]
// Decompiled from void __thiscall CTaskForceWarMachines::Execute(CTaskForceWarMachines *this)
void CTaskForceWarMachines::Execute(void) {
  DWORD          v1; // esi
  int            iEntityId; // [esp+Ch] [ebp-14h]
  CAIEntityInfo *pEntity; // [esp+10h] [ebp-10h]
  // [esp+18h] [ebp-8h]

  this->SetWaitCounter(8u);
  int v4 = 0;
  while(2) {
    if(v4 >= 10) {
      BB_REPORT("CTaskForceWarMachines::Execute(): Endless loop detected!")
    } else {
      switch(this->State()) {
        case 0:
        case 100:
          return;
        case 101:
          pEntity = this->FirstEntity();
          if(!pEntity)
            return;
          iEntityId = pEntity->EntityId();
          BB_ASSERT(iEntityId > 0)

          if(IAIEnvironment::MovingEntityWalkingState(iEntityId) >= 64)
            return;
          this->SetState(103);
          goto LABEL_2;
        case 102:
          this->FindWaypoints();
          this->InitWarMachineWalk(0);
          this->SetWaitCounter(0x20u);
          this->SetState(101);
          return;
        case 103:
          v1 = this->WaypointXY();
          if(v1 == this->DestinationXY()) {
            this->InitWarMachineWalk(1);
            this->ClearWaypoints();
            this->ActivateNextState();
          LABEL_2:
            ++v4;
            continue;
          }
          this->PopWaypoint();
          if(!this->WaypointAvailable()) {
            this->CheckBuildingDestination();
            this->FindWaypoints();
          }
          if(!this->WaypointAvailable()) {
            this->ActivateNextState();
            goto LABEL_2;
          }
          this->InitWarMachineWalk(0);
          break;
        default:
          BB_REPORT("CTaskForceWarMachines::Execute(): Invalid state!")
          this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_1, 0, 0);
          return;
      }
    }
    break;
  }
}


