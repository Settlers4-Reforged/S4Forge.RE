#include "CAITaskForceSquad.h"

// Definitions for class CAITaskForceSquad

// address=[0x13192f0]
// Decompiled from void __thiscall CAITaskForceSquad::~CAITaskForceSquad(CAITaskForceSquad *this)

 CAITaskForceSquad::~CAITaskForceSquad(void) {
  
  *(_DWORD *)this = CAITaskForceSquad::_vftable_;
  CAITaskForceEx::~CAITaskForceEx(this);
}


// address=[0x132bfc0]
// Decompiled from _DWORD *__thiscall CAITaskForceSquad::CAITaskForceSquad(_DWORD *this, int a2, int a3, int a4)

 CAITaskForceSquad::CAITaskForceSquad(int,enum T_AI_TASK_FORCE_TYPE,int) {
  
  CAITaskForceEx::CAITaskForceEx(this, a2, 2, a3, a4);
  *this = CAITaskForceSquad::_vftable_;
  this[24] = 0;
  this[25] = 0;
  this[26] = 0;
  this[27] = 0;
  return this;
}


// address=[0x132c020]
// Decompiled from char __thiscall CAITaskForceSquad::Execute(CAITaskForceSquad *this)

void  CAITaskForceSquad::Execute(void) {
  
  int Entity; // eax
  int v2; // eax
  int v4; // [esp+0h] [ebp-34h]
  int v5; // [esp+4h] [ebp-30h]
  int v6; // [esp+8h] [ebp-2Ch]
  int v7; // [esp+Ch] [ebp-28h]
  int v8; // [esp+10h] [ebp-24h]
  int v9; // [esp+18h] [ebp-1Ch]
  int v10; // [esp+1Ch] [ebp-18h]
  int v11; // [esp+24h] [ebp-10h]
  int v12; // [esp+28h] [ebp-Ch]
  char v14; // [esp+33h] [ebp-1h]

  CAITaskForce::SetWaitCounter(this, 1u);
  switch ( CAITaskForce::State(this) )
  {
    case 1:
      if ( !CAITaskForce::GoalIsEntity(this)
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1446, "GoalIsEntity()") == 1 )
      {
        __debugbreak();
      }
      v10 = CAITaskForce::CmdGoal(this);
      if ( !IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(v10, 12) )
        goto LABEL_7;
      v8 = IAIEnvironment::BuildingPackedEnsignPosition(v10);
      (*(void (__thiscall **)(CAITaskForceSquad *, int))(*(_DWORD *)this + 44))(this, v8);
      CAITaskForce::SetStateEx(this, 102, 2);
      LOBYTE(Entity) = CAITaskForceEx::Execute(this);
      break;
    case 2:
      CAITaskForce::SetStatus(this, 4);
      CAITaskForce::SetStateEx(this, 1, 0);
      LOBYTE(Entity) = CAITaskForce::SetWaitCounter(this, 0x28u);
      break;
    case 3:
      if ( !CAITaskForce::GoalIsEntity(this)
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1478, "GoalIsEntity()") == 1 )
      {
        __debugbreak();
      }
      v9 = CAITaskForce::CmdGoal(this);
      if ( IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(v9, 12) )
      {
        v7 = IAIEnvironment::BuildingPackedEnsignPosition(v9);
        (*(void (__thiscall **)(CAITaskForceSquad *, int))(*(_DWORD *)this + 44))(this, v7);
        CAITaskForce::SetStateEx(this, 102, 4);
        LOBYTE(Entity) = CAITaskForceEx::Execute(this);
      }
      else
      {
LABEL_7:
        LOBYTE(Entity) = CAITaskForce::SetNewStatusAndState(this, 1, 0, 0);
      }
      break;
    case 4:
      if ( !CAITaskForce::GoalIsEntity(this)
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1501, "GoalIsEntity()") == 1 )
      {
        __debugbreak();
      }
      v6 = CAITaskForce::CmdGoal(this);
      if ( IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(v6, 12) )
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
      LOBYTE(Entity) = CAITaskForce::SetWaitCounter(this, 0x14u);
      break;
    case 107:
      Entity = CAITaskForce::FirstEntity(this);
      v12 = Entity;
      if ( Entity )
      {
        Entity = CAITaskForce::CmdGoal(this);
        if ( Entity > 0 )
        {
          while ( v12 )
          {
            v5 = CAIEntityInfo::EntityId(v12);
            v2 = CAITaskForce::CmdGoal(this);
            IAIEnvironment::EntityEnterManakopter(v5, v2);
            v12 = CAIEntityInfo::Next(v12);
          }
          LOBYTE(Entity) = CAITaskForce::SetNewStatusAndState(this, 9, 108, 0);
        }
      }
      break;
    case 108:
      Entity = CAITaskForce::FirstEntity(this);
      v11 = Entity;
      v14 = 1;
      if ( Entity )
      {
        Entity = CAITaskForce::CmdGoal(this);
        if ( Entity > 0 )
        {
          while ( v11 )
          {
            v4 = CAIEntityInfo::EntityId(v11);
            if ( (IAIEnvironment::EntityFlags(v4) & 0x8000) == 0 )
              v14 = 0;
            Entity = CAIEntityInfo::Next(v11);
            v11 = Entity;
          }
          if ( v14 )
            LOBYTE(Entity) = CAITaskForce::SetStatus(this, 8);
        }
      }
      break;
    default:
      LOBYTE(Entity) = CAITaskForceEx::Execute(this);
      break;
  }
  return Entity;
}


// address=[0x132c3c0]
// Decompiled from char __thiscall CAITaskForceSquad::NewCommand(CAITaskForceSquad *this, unsigned int a2, int a3, int a4)

bool  CAITaskForceSquad::NewCommand(int,int,int) {
  
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
      (*(void (__thiscall **)(CAITaskForceSquad *, int))(*(_DWORD *)this + 44))(this, a3);
      CAITaskForce::SetNewStatusAndState(this, 2, 102, 0);
      result = 1;
      break;
    case 2u:
      if ( !IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(a3, 12)
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
      if ( !IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(a3, 12)
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
// Decompiled from int __thiscall CAITaskForceSquad::AddEntity(_DWORD *this, CAIEntityInfo *a2, int a3)

enum CAITaskForce::T_RESULT  CAITaskForceSquad::AddEntity(class CAIEntityInfo *,enum CAITaskForce::T_POSITION) {
  
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]

  v5 = CAITaskForce::AddEntity(this, a2, a3);
  if ( v5 != 3 )
    return v5;
  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1182, "_pEntityInfo != 0") == 1 )
    __debugbreak();
  v4 = CAIEntityInfo::EntityId(a2);
  switch ( IAIEnvironment::EntityWarriorType(v4) )
  {
    case 2u:
      ++this[24];
      break;
    case 3u:
      ++this[25];
      break;
    case 4u:
      ++this[26];
      break;
    case 5u:
      ++this[27];
      break;
    default:
      return v5;
  }
  return v5;
}


// address=[0x132c660]
// Decompiled from int __thiscall CAITaskForceSquad::RemoveEntity(int *this, _DWORD *a2)

enum CAITaskForce::T_RESULT  CAITaskForceSquad::RemoveEntity(class CAIEntityInfo *) {
  
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
    case 2u:
      if ( --this[24] < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1246, "m_iNumberOfSwordsmen >= 0") == 1 )
        __debugbreak();
      break;
    case 3u:
      if ( --this[25] < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1255, "m_iNumberOfBowmen >= 0") == 1 )
        __debugbreak();
      break;
    case 4u:
      if ( --this[26] < 0
        && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1264, "m_iNumberOfUniqueFighters >= 0") == 1 )
      {
        __debugbreak();
      }
      break;
    case 5u:
      if ( --this[27] < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1273, "m_iNumberOfSquadleaders >= 0") == 1 )
        __debugbreak();
      break;
    default:
      return v4;
  }
  return v4;
}


// address=[0x132c7f0]
// Decompiled from CAITaskForceSquad *__thiscall CAITaskForceSquad::RemoveAllEntities(CAITaskForceSquad *this)

void  CAITaskForceSquad::RemoveAllEntities(void) {
  
  CAITaskForceSquad *result; // eax

  CAITaskForce::RemoveAllEntities(this);
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  result = this;
  *((_DWORD *)this + 27) = 0;
  return result;
}


// address=[0x132c830]
// Decompiled from int __thiscall CAITaskForceSquad::NumberOfEntities(int *this, int a2)

int  CAITaskForceSquad::NumberOfEntities(enum T_AI_WARRIOR_TYPE)const {
  
  int result; // eax

  switch ( a2 )
  {
    case 2:
      if ( this[24] < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1138, "m_iNumberOfSwordsmen >= 0") == 1 )
        __debugbreak();
      result = this[24];
      break;
    case 3:
      if ( this[25] < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1145, "m_iNumberOfBowmen >= 0") == 1 )
        __debugbreak();
      result = this[25];
      break;
    case 4:
      if ( this[26] < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1152, "m_iNumberOfUniqueFighters >= 0") == 1 )
        __debugbreak();
      result = this[26];
      break;
    case 5:
      if ( this[27] < 0 && BBSupportDbgReport(2, "AI\\AI_TaskForcesEx.cpp", 1159, "m_iNumberOfSquadleaders >= 0") == 1 )
        __debugbreak();
      result = this[27];
      break;
    default:
      result = -1;
      break;
  }
  return result;
}


