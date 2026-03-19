#include "CAITaskForceSquad.h"

#include "AI/CAIEntityInfo.h"
#include "AI/IAIEnvironment.h"
#include "CBB/CBBSupport.h"
#include "MapObjects/IEntity.h"

// Definitions for class CAITaskForceSquad

// address=[0x13192f0]
// Decompiled from void __thiscall CAITaskForceSquad::~CAITaskForceSquad(CAITaskForceSquad *this)
CAITaskForceSquad::~CAITaskForceSquad(void) = default;


// address=[0x132bfc0]
// Decompiled from CAITaskForceSquad *__thiscall CAITaskForceSquad::CAITaskForceSquad(CAITaskForceSquad *this, int a2, int a3, int a4)
CAITaskForceSquad::CAITaskForceSquad(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4) : CAITaskForceEx(a2, AI_TASK_FORCE_CLASS_SQUAD, a3, a4) {
  this->m_iNumberOfSwordsmen = 0;
  this->m_iNumberOfBowmen = 0;
  this->m_iNumberOfUniqueFighters = 0;
  this->m_iNumberOfSquadleaders = 0;
}


// address=[0x132c020]
// Decompiled from void __thiscall CAITaskForceSquad::Execute(CAITaskForceSquad *this)
void CAITaskForceSquad::Execute(void) {
  int            v4; // [esp+8h] [ebp-2Ch]
  int            iCmdGoal; // [esp+1Ch] [ebp-18h]
  CAIEntityInfo *pEntity; // [esp+28h] [ebp-Ch]
  char           v12; // [esp+33h] [ebp-1h]

  this->SetWaitCounter(1u);
  switch(this->State()) {
    case 1:
      BB_ASSERT(this->GoalIsEntity())
      iCmdGoal = this->CmdGoal();
      if(!IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(iCmdGoal, AI_WARRIOR_TYPE_TOWER_BUILDING))
        goto LABEL_7;

      this->SetDestinationXY(IAIEnvironment::BuildingPackedEnsignPosition(iCmdGoal));
      this->SetStateEx(102, 2);
      this->Execute();
      break;
    case 2:
      this->SetStatus(TASK_FORCE_STATUS_UNKNOWN_4);
      this->SetStateEx(1, 0);
      this->SetWaitCounter(0x28u);
      break;
    case 3:
      BB_ASSERT(this->GoalIsEntity())

      iCmdGoal = this->CmdGoal();
      if(IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(iCmdGoal, AI_WARRIOR_TYPE_TOWER_BUILDING)) {
        this->SetDestinationXY(IAIEnvironment::BuildingPackedEnsignPosition(iCmdGoal));
        this->SetStateEx(102, 4);
        this->Execute();
      } else {
      LABEL_7:
        this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_1, 0, 0);
      }
      break;
    case 4:
      BB_ASSERT(this->GoalIsEntity())
      v4 = this->CmdGoal();
      if(IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(v4, AI_WARRIOR_TYPE_TOWER_BUILDING)) {
        this->SetStatus(TASK_FORCE_STATUS_UNKNOWN_3);
        this->SetWaitCounter(0x14u);
      } else {
        this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_1, 0, 0);
      }
      goto LABEL_21;
    case 6:
    LABEL_21:
      this->SetStatus(TASK_FORCE_STATUS_UNKNOWN_5);
      this->SetWaitCounter(0x14u);
      break;
    case 107:
      pEntity = this->FirstEntity();
      if(pEntity && this->CmdGoal() > 0) {
        while(pEntity) {
          IAIEnvironment::EntityEnterManakopter(pEntity->EntityId(), this->CmdGoal());
          pEntity = pEntity->Next();
        }
        this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_9, 108, 0);
      }
      break;
    case 108:
      pEntity = this->FirstEntity();
      v12 = 1;
      if(pEntity && this->CmdGoal() > 0) {
        while(pEntity) {
          if((IAIEnvironment::EntityFlags(pEntity->EntityId()) & EntityFlag_OnBoard) == 0)
            v12 = 0;
          pEntity = pEntity->Next();
        }
        if(v12)
          this->SetStatus(TASK_FORCE_STATUS_UNKNOWN_8);
      }
      break;
    default:
      this->Execute();
      break;
  }
}


// address=[0x132c3c0]
// Decompiled from char __thiscall CAITaskForceSquad::NewCommand(CAITaskForceSquad *this, unsigned int a2, int a3, int a4)
bool CAITaskForceSquad::NewCommand(int a2, int _iEntityIdOrPackedXY, int a4) {
  bool SneakUpPosition; // [esp+Bh] [ebp-1h]

  this->SetCommandAndClearStuff(a2, _iEntityIdOrPackedXY, a4);
  switch(a2) {
    case 0u:
      return true;
    case 1u:
      this->MarkGoalAsPosition();
      this->SetDestinationXY(_iEntityIdOrPackedXY);
      this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_2, 102, 0);
      return true;
    case 2u:
      BB_ASSERT(IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(_iEntityIdOrPackedXY, AI_WARRIOR_TYPE_TOWER_BUILDING))
      // if(!IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(a3, AI_WARRIOR_TYPE_TOWER_BUILDING)
      //    && BBSupportDbgReport(
      //      2,
      //      "AI\\AI_TaskForcesEx.cpp",
      //      1329,
      //      "g_pAIEnv->EntityIsAliveAndOfGivenWarriorType(_iEntityIdOrPackedXY, AI_WARRIOR_TYPE_TOWER_BUILDING)") == 1) {
      //   __debugbreak();
      // }
      this->MarkGoalAsEntity();
      this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_2, 1, 0);
      return true;
    case 3u:
      this->MarkGoalAsPosition();
      SneakUpPosition = this->FindSneakUpPosition();
      if(SneakUpPosition)
        this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_2, 102, 6);
      return SneakUpPosition;
    case 4u:
      BB_ASSERT(IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(_iEntityIdOrPackedXY, AI_WARRIOR_TYPE_TOWER_BUILDING))
      // if(!IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(_iEntityIdOrPackedXY, AI_WARRIOR_TYPE_TOWER_BUILDING)
      //    && BBSupportDbgReport(
      //      2,
      //      "AI\\AI_TaskForcesEx.cpp",
      //      1361,
      //      "g_pAIEnv->EntityIsAliveAndOfGivenWarriorType(_iEntityIdOrPackedXY, AI_WARRIOR_TYPE_TOWER_BUILDING)") == 1) {
      //   __debugbreak();
      // }
      this->MarkGoalAsEntity();
      this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_1, 3, 0);
      return true;
    case 6u:
      this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_7, 106, 0);
      return true;
    case 0xAu:
      this->SetNewStatusAndState(TASK_FORCE_STATUS_UNKNOWN_2, 107, 0);
      return true;
    default:
      BB_REPORT("CAITaskForceSquad::NewCommand(): Invalid command!");
      return false;
  }
}


// address=[0x132c580]
// Decompiled from int __thiscall CAITaskForceSquad::AddEntity(CAITaskForceSquad *this, CAIEntityInfo *_pEntityInfo, int a3)
enum T_RESULT CAITaskForceSquad::AddEntity(class CAIEntityInfo *_pEntityInfo, enum CAITaskForce::T_POSITION a3) {
  T_RESULT tAddResult = CAITaskForceEx::AddEntity(_pEntityInfo, a3);
  if(tAddResult != RESULT_ADDED)
    return tAddResult;

  BB_ASSERT(_pEntityInfo != nullptr)

  switch(IAIEnvironment::EntityWarriorType(_pEntityInfo->EntityId())) {
    case AI_WARRIOR_TYPE_SWORDMAN:
      ++this->m_iNumberOfSwordsmen;
      break;
    case AI_WARRIOR_TYPE_BOWMAN:
      ++this->m_iNumberOfBowmen;
      break;
    case AI_WARRIOR_TYPE_FIGHTER_UNIQUE:
      ++this->m_iNumberOfUniqueFighters;
      break;
    case AI_WARRIOR_TYPE_SQUAD_LEADER:
      ++this->m_iNumberOfSquadleaders;
      break;
    default:
      BB_REPORT("CAITaskForceSquad::AddEntity(): Invalid warrior type!");
      return RESULT_ADDED;
  }
  return RESULT_ADDED;
}


// address=[0x132c660]
// Decompiled from int __thiscall CAITaskForceSquad::RemoveEntity(CAITaskForceSquad *this, struct CAIEntityInfo *a2)
enum T_RESULT CAITaskForceSquad::RemoveEntity(class CAIEntityInfo *_pEntityInfo) {
  // [esp+4h] [ebp-10h]
  // [esp+8h] [ebp-Ch]

  T_RESULT tRemoveResult = CAITaskForceEx::RemoveEntity(_pEntityInfo);
  if(tRemoveResult != RESULT_REMOVED)
    return tRemoveResult;
  BB_ASSERT(_pEntityInfo != nullptr)
  // if(!a2 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1234, "_pEntityInfo != 0") == 1)
  //   __debugbreak();

  switch(IAIEnvironment::EntityWarriorType(_pEntityInfo->EntityId())) {
    case AI_WARRIOR_TYPE_SWORDMAN:
      this->m_iNumberOfSwordsmen--;
      BB_ASSERT(this->m_iNumberOfSwordsmen >= 0);
      break;
    case AI_WARRIOR_TYPE_BOWMAN:
      this->m_iNumberOfBowmen--;
      BB_ASSERT(this->m_iNumberOfBowmen >= 0);
      break;
    case AI_WARRIOR_TYPE_FIGHTER_UNIQUE:
      this->m_iNumberOfUniqueFighters--;
      BB_ASSERT(this->m_iNumberOfUniqueFighters >= 0);
      break;
    case AI_WARRIOR_TYPE_SQUAD_LEADER:
      this->m_iNumberOfSquadleaders--;
      BB_ASSERT(this->m_iNumberOfSquadleaders >= 0);
      break;
    default:
      BB_REPORT("CAITaskForceSquad::RemoveEntity(): Invalid warrior type!");
      return RESULT_REMOVED;
  }
  return RESULT_REMOVED;
}


// address=[0x132c7f0]
// Decompiled from CAITaskForceSquad *__thiscall CAITaskForceSquad::RemoveAllEntities(CAITaskForceSquad *this)
void CAITaskForceSquad::RemoveAllEntities(void) {
  CAITaskForceEx::RemoveAllEntities();
  this->m_iNumberOfSwordsmen = 0;
  this->m_iNumberOfBowmen = 0;
  this->m_iNumberOfUniqueFighters = 0;
  this->m_iNumberOfSquadleaders = 0;
}


// address=[0x132c830]
// Decompiled from int __thiscall CAITaskForceSquad::NumberOfEntities(int *this, int a2)
int CAITaskForceSquad::NumberOfEntities(enum T_AI_WARRIOR_TYPE a2) const {
  switch(a2) {
    case AI_WARRIOR_TYPE_SWORDMAN:
      BB_ASSERT(this->m_iNumberOfSwordsmen >= 0);
      return this->m_iNumberOfSwordsmen;
    case AI_WARRIOR_TYPE_BOWMAN:
      BB_ASSERT(this->m_iNumberOfBowmen >= 0);
      return this->m_iNumberOfBowmen;
    case AI_WARRIOR_TYPE_FIGHTER_UNIQUE:
      BB_ASSERT(this->m_iNumberOfUniqueFighters >= 0);
      return this->m_iNumberOfUniqueFighters;
    case AI_WARRIOR_TYPE_SQUAD_LEADER:
      BB_ASSERT(this->m_iNumberOfSquadleaders >= 0);
      return this->m_iNumberOfSquadleaders;
    default:
      BB_REPORT("CAITaskForceSquad::NumberOfEntities(): Invalid warrior type!");
      return -1;
  }
}

