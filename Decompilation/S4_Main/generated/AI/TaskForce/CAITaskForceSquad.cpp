#if FALSE
#include "CAITaskForceSquad.h"

// Definitions for class CAITaskForceSquad

// address=[0x13192f0]
// Decompiled from void __thiscall CAITaskForceSquad::~CAITaskForceSquad(CAITaskForceSquad *this)
 CAITaskForceSquad::~CAITaskForceSquad(void) {
  
  *(_DWORD *)this = CAITaskForceSquad::_vftable_;
  CAITaskForceEx::~CAITaskForceEx(this);
}


// address=[0x132bfc0]
// Decompiled from CAITaskForceSquad *__thiscall CAITaskForceSquad::CAITaskForceSquad(CAITaskForceSquad *this, int a2, int a3, int a4)
 CAITaskForceSquad::CAITaskForceSquad(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4) {
  
  CAITaskForceEx::CAITaskForceEx(this, a2, 2, a3, a4);
  this->__vftable = (CAITaskForceEx_vtbl *)CAITaskForceSquad::_vftable_;
  this->m_iNumberOfSwordsmen = 0;
  this->m_iNumberOfBowmen = 0;
  this->m_iNumberOfUniqueFighters = 0;
  this->m_iNumberOfSquadleaders = 0;
  return this;
}


// address=[0x132c020]
// Decompiled from void __thiscall CAITaskForceSquad::Execute(CAITaskForceSquad *this)
void  CAITaskForceSquad::Execute(void) {
  
  int v1; // eax
  int v2; // [esp+0h] [ebp-34h]
  int v3; // [esp+4h] [ebp-30h]
  int v4; // [esp+8h] [ebp-2Ch]
  int v5; // [esp+Ch] [ebp-28h]
  int v6; // [esp+10h] [ebp-24h]
  int v7; // [esp+18h] [ebp-1Ch]
  int v8; // [esp+1Ch] [ebp-18h]
  CAIEntityInfo *v9; // [esp+24h] [ebp-10h]
  CAIEntityInfo *Entity; // [esp+28h] [ebp-Ch]
  char v12; // [esp+33h] [ebp-1h]

  CAITaskForce::SetWaitCounter(this, 1u);
  switch ( CAITaskForce::State(this) )
  {
    case 1:
      if ( !CAITaskForce::GoalIsEntity(this)
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1446, "GoalIsEntity()") == 1 )
      {
        __debugbreak();
      }
      v8 = CAITaskForce::CmdGoal(this);
      if ( !IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(v8, AI_WARRIOR_TYPE_TOWER_BUILDING) )
        goto LABEL_7;
      v6 = IAIEnvironment::BuildingPackedEnsignPosition(v8);
      this->SetDestinationXY(this, v6);
      CAITaskForce::SetStateEx(this, 102, 2);
      CAITaskForceEx::Execute(this);
      break;
    case 2:
      CAITaskForce::SetStatus(this, 4);
      CAITaskForce::SetStateEx(this, 1, 0);
      CAITaskForce::SetWaitCounter(this, 0x28u);
      break;
    case 3:
      if ( !CAITaskForce::GoalIsEntity(this)
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1478, "GoalIsEntity()") == 1 )
      {
        __debugbreak();
      }
      v7 = CAITaskForce::CmdGoal(this);
      if ( IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(v7, AI_WARRIOR_TYPE_TOWER_BUILDING) )
      {
        v5 = IAIEnvironment::BuildingPackedEnsignPosition(v7);
        this->SetDestinationXY(this, v5);
        CAITaskForce::SetStateEx(this, 102, 4);
        CAITaskForceEx::Execute(this);
      }
      else
      {
LABEL_7:
        CAITaskForce::SetNewStatusAndState(this, 1, 0, 0);
      }
      break;
    case 4:
      if ( !CAITaskForce::GoalIsEntity(this)
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1501, "GoalIsEntity()") == 1 )
      {
        __debugbreak();
      }
      v4 = CAITaskForce::CmdGoal(this);
      if ( IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(v4, AI_WARRIOR_TYPE_TOWER_BUILDING) )
      {
        CAITaskForce::SetStatus(this, 3);
        CAITaskForce::SetWaitCounter(this, 0x14u);
      }
      else
      {
        CAITaskForce::SetNewStatusAndState(this, 1, 0, 0);
      }
      goto LABEL_21;
    case 6:
LABEL_21:
      CAITaskForce::SetStatus(this, 5);
      CAITaskForce::SetWaitCounter(this, 0x14u);
      break;
    case 107:
      Entity = CAITaskForce::FirstEntity(this);
      if ( Entity && CAITaskForce::CmdGoal(this) > 0 )
      {
        while ( Entity )
        {
          v3 = CAIEntityInfo::EntityId(Entity);
          v1 = CAITaskForce::CmdGoal(this);
          IAIEnvironment::EntityEnterManakopter(v3, v1);
          Entity = CAIEntityInfo::Next(Entity);
        }
        CAITaskForce::SetNewStatusAndState(this, 9, 108, 0);
      }
      break;
    case 108:
      v9 = CAITaskForce::FirstEntity(this);
      v12 = 1;
      if ( v9 && CAITaskForce::CmdGoal(this) > 0 )
      {
        while ( v9 )
        {
          v2 = CAIEntityInfo::EntityId(v9);
          if ( (IAIEnvironment::EntityFlags(v2) & ENTITY_FLAG_ON_BOARD) == 0 )
            v12 = 0;
          v9 = CAIEntityInfo::Next(v9);
        }
        if ( v12 )
          CAITaskForce::SetStatus(this, 8);
      }
      break;
    default:
      CAITaskForceEx::Execute(this);
      break;
  }
}


// address=[0x132c3c0]
// Decompiled from char __thiscall CAITaskForceSquad::NewCommand(CAITaskForceSquad *this, unsigned int a2, int a3, int a4)
bool  CAITaskForceSquad::NewCommand(int a2, int a3, int a4) {
  
  char result; // al
  char SneakUpPosition; // [esp+Bh] [ebp-1h]

  CAITaskForceEx::SetCommandAndClearStuff(this, a2, a3, a4);
  switch ( a2 )
  {
    case 0u:
      result = 1;
      break;
    case 1u:
      CAITaskForce::MarkGoalAsPosition(this);
      this->SetDestinationXY(this, a3);
      CAITaskForce::SetNewStatusAndState(this, 2, 102, 0);
      result = 1;
      break;
    case 2u:
      if ( !IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(a3, AI_WARRIOR_TYPE_TOWER_BUILDING)
        && BBSupportDbgReport(
             2,
             "AI\\AI_TaskForcesEx.cpp",
             1329,
             "g_pAIEnv->EntityIsAliveAndOfGivenWarriorType(_iEntityIdOrPackedXY, AI_WARRIOR_TYPE_TOWER_BUILDING)") == 1 )
      {
        __debugbreak();
      }
      CAITaskForce::MarkGoalAsEntity(this);
      CAITaskForce::SetNewStatusAndState(this, 2, 1, 0);
      result = 1;
      break;
    case 3u:
      CAITaskForce::MarkGoalAsPosition(this);
      SneakUpPosition = CAITaskForceEx::FindSneakUpPosition(this);
      if ( SneakUpPosition )
        CAITaskForce::SetNewStatusAndState(this, 2, 102, 6);
      result = SneakUpPosition;
      break;
    case 4u:
      if ( !IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(a3, AI_WARRIOR_TYPE_TOWER_BUILDING)
        && BBSupportDbgReport(
             2,
             "AI\\AI_TaskForcesEx.cpp",
             1361,
             "g_pAIEnv->EntityIsAliveAndOfGivenWarriorType(_iEntityIdOrPackedXY, AI_WARRIOR_TYPE_TOWER_BUILDING)") == 1 )
      {
        __debugbreak();
      }
      CAITaskForce::MarkGoalAsEntity(this);
      CAITaskForce::SetNewStatusAndState(this, 1, 3, 0);
      result = 1;
      break;
    case 6u:
      CAITaskForce::SetNewStatusAndState(this, 7, 106, 0);
      result = 1;
      break;
    case 0xAu:
      CAITaskForce::SetNewStatusAndState(this, 2, 107, 0);
      result = 1;
      break;
    default:
      if ( BBSupportDbgReport(1, "AI\\AI_TaskForcesEx.cpp", 1383, "CAITaskForceSquad::NewCommand(): Invalid command!") == 1 )
        __debugbreak();
      result = 0;
      break;
  }
  return result;
}


// address=[0x132c580]
// Decompiled from int __thiscall CAITaskForceSquad::AddEntity(CAITaskForceSquad *this, CAIEntityInfo *_pEntityInfo, int a3)
enum CAITaskForce::T_RESULT  CAITaskForceSquad::AddEntity(class CAIEntityInfo * _pEntityInfo, enum CAITaskForce::T_POSITION a3) {
  
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]

  v5 = CAITaskForce::AddEntity(this, _pEntityInfo, a3);
  if ( v5 != 3 )
    return v5;
  if ( !_pEntityInfo && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1182, "_pEntityInfo != 0") == 1 )
    __debugbreak();
  v4 = CAIEntityInfo::EntityId(_pEntityInfo);
  switch ( IAIEnvironment::EntityWarriorType(v4) )
  {
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
      return v5;
  }
  return v5;
}


// address=[0x132c660]
// Decompiled from int __thiscall CAITaskForceSquad::RemoveEntity(CAITaskForceSquad *this, struct CAIEntityInfo *a2)
enum CAITaskForce::T_RESULT  CAITaskForceSquad::RemoveEntity(class CAIEntityInfo * a2) {
  
  int v3; // [esp+4h] [ebp-10h]
  int v4; // [esp+8h] [ebp-Ch]

  v4 = CAITaskForce::RemoveEntity(this, a2);
  if ( v4 != 4 )
    return v4;
  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1234, "_pEntityInfo != 0") == 1 )
    __debugbreak();
  v3 = CAIEntityInfo::EntityId(a2);
  switch ( IAIEnvironment::EntityWarriorType(v3) )
  {
    case 2:
      if ( --this->m_iNumberOfSwordsmen < 0
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1246, "m_iNumberOfSwordsmen >= 0") == 1 )
      {
        __debugbreak();
      }
      break;
    case 3:
      if ( --this->m_iNumberOfBowmen < 0
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1255, "m_iNumberOfBowmen >= 0") == 1 )
      {
        __debugbreak();
      }
      break;
    case 4:
      if ( --this->m_iNumberOfUniqueFighters < 0
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1264, "m_iNumberOfUniqueFighters >= 0") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5:
      if ( --this->m_iNumberOfSquadleaders < 0
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1273, "m_iNumberOfSquadleaders >= 0") == 1 )
      {
        __debugbreak();
      }
      break;
    default:
      return v4;
  }
  return v4;
}


// address=[0x132c7f0]
// Decompiled from void __thiscall CAITaskForceSquad::RemoveAllEntities(CAITaskForceSquad *this)
void  CAITaskForceSquad::RemoveAllEntities(void) {
  
  CAITaskForce::RemoveAllEntities(this);
  this->m_iNumberOfSwordsmen = 0;
  this->m_iNumberOfBowmen = 0;
  this->m_iNumberOfUniqueFighters = 0;
  this->m_iNumberOfSquadleaders = 0;
}


// address=[0x132c830]
// Decompiled from int __thiscall CAITaskForceSquad::NumberOfEntities(CAITaskForceSquad *this, T_AI_WARRIOR_TYPE a2)
int  CAITaskForceSquad::NumberOfEntities(enum T_AI_WARRIOR_TYPE a2)const {
  
  int result; // eax

  switch ( a2 )
  {
    case AI_WARRIOR_TYPE_SWORDMAN:
      if ( this->m_iNumberOfSwordsmen < 0
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1138, "m_iNumberOfSwordsmen >= 0") == 1 )
      {
        __debugbreak();
      }
      result = this->m_iNumberOfSwordsmen;
      break;
    case AI_WARRIOR_TYPE_BOWMAN:
      if ( this->m_iNumberOfBowmen < 0
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1145, "m_iNumberOfBowmen >= 0") == 1 )
      {
        __debugbreak();
      }
      result = this->m_iNumberOfBowmen;
      break;
    case AI_WARRIOR_TYPE_FIGHTER_UNIQUE:
      if ( this->m_iNumberOfUniqueFighters < 0
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1152, "m_iNumberOfUniqueFighters >= 0") == 1 )
      {
        __debugbreak();
      }
      result = this->m_iNumberOfUniqueFighters;
      break;
    case AI_WARRIOR_TYPE_SQUAD_LEADER:
      if ( this->m_iNumberOfSquadleaders < 0
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1159, "m_iNumberOfSquadleaders >= 0") == 1 )
      {
        __debugbreak();
      }
      result = this->m_iNumberOfSquadleaders;
      break;
    default:
      result = -1;
      break;
  }
  return result;
}


#endif // Already implemented
