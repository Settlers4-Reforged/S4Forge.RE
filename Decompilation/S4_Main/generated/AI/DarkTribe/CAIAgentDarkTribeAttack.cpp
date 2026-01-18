#include "CAIAgentDarkTribeAttack.h"

// Definitions for class CAIAgentDarkTribeAttack

// address=[0x12f9ea0]
// Decompiled from CAIAgentDarkTribeAttack *__thiscall CAIAgentDarkTribeAttack::CAIAgentDarkTribeAttack(CAIAgentDarkTribeAttack *this)
 CAIAgentDarkTribeAttack::CAIAgentDarkTribeAttack(void) {
  
  CAIDarkTribeSectorAgent::CAIDarkTribeSectorAgent(this, aDarkAtt);
  *(_DWORD *)this = &CAIAgentDarkTribeAttack::_vftable_;
  CAIAgentDarkTribeAttack::ResetAttackState(this);
  return this;
}


// address=[0x12f9f10]
// Decompiled from unsigned int __thiscall CAIAgentDarkTribeAttack::Execute(  CAIAgentDarkTribeAttack *this,  unsigned int a2,  unsigned int a3)
unsigned int  CAIAgentDarkTribeAttack::Execute(unsigned int a2, unsigned int a3) {
  
  struct CAIDarkTribeSectorAI *v3; // eax
  pairNode *v4; // eax
  struct CAIDarkTribeSectorAI *v6; // eax
  struct CAIDarkTribeSectorAI *v7; // eax
  struct CAIDarkTribeSectorAI *v8; // eax
  struct CAIDarkTribeSectorAI *v9; // eax
  struct CAIDarkTribeSectorAI *v10; // eax
  int v11; // eax
  _BYTE v12[8]; // [esp+0h] [ebp-34h] BYREF
  signed int v13; // [esp+8h] [ebp-2Ch]
  int v14; // [esp+Ch] [ebp-28h]
  int v15; // [esp+10h] [ebp-24h]
  int v16; // [esp+14h] [ebp-20h]
  int v17; // [esp+18h] [ebp-1Ch]
  int v18; // [esp+1Ch] [ebp-18h]
  int v19; // [esp+20h] [ebp-14h]
  int v20; // [esp+24h] [ebp-10h]
  int v21; // [esp+28h] [ebp-Ch]
  void *v22; // [esp+2Ch] [ebp-8h]
  bool v23; // [esp+33h] [ebp-1h]

  v22 = this;
  v3 = CAIDarkTribeSectorAgent::SectorAI(this);
  v4 = (pairNode *)CAISectorAI::PlayerAI(v3);
  v21 = CAIPlayerAI::PlayerId(v4);
  v18 = *((_DWORD *)v22 + 10);
  switch ( v18 )
  {
    case 0:
      CAIPlayersScriptVars::operator[](v21);
      v15 = CAIPlayerScriptVars::operator[](0);
      if ( v15 <= 0 )
        return CAIAgent::ExecuteResult(0, 0);
      CAIPlayersScriptVars::operator[](v21);
      v14 = CAIPlayerScriptVars::operator[](1);
      v13 = IAIEnvironment::MinutesToTicks(v14);
      v17 = IAIEnvironment::TickCounter();
      if ( (unsigned int)v17 <= *((_DWORD *)v22 + 15)
        || v17 <= v13
        || !CAIAgentDarkTribeAttack::ShamanAttackTaskForceAvailable((CAIAgentDarkTribeAttack *)v22) )
      {
        return CAIAgent::ExecuteResult(0, 0);
      }
      CTrace::Print("DarkAttack %i: IDLE -> CHECK", v21);
      CAIAgentDarkTribeAttack::AttackWithShamans((CAIAgentDarkTribeAttack *)v22, 0, 1, 0);
      return CAIAgent::ExecuteResult(0xAu, 0);
    case 1:
      v23 = CAIAgentDarkTribeAttack::ManakopterTaskForceAvailable((CAIAgentDarkTribeAttack *)v22, 0);
      if ( !CAIAgentDarkTribeAttack::ShamanAttackTaskForceAvailable((CAIAgentDarkTribeAttack *)v22) )
        return CAIAgent::ExecuteResult(0, 0);
      v6 = CAIDarkTribeSectorAgent::SectorAI((CAIDarkTribeSectorAgent *)v22);
      *((_DWORD *)v22 + 13) = CAISectorAI::BaseX(v6);
      v7 = CAIDarkTribeSectorAgent::SectorAI((CAIDarkTribeSectorAgent *)v22);
      *((_DWORD *)v22 + 14) = CAISectorAI::BaseY(v7);
      if ( !(**(unsigned __int8 (__thiscall ***)(void *, int, _DWORD, char *, char *, bool))off_3D7A6A8)(
              off_3D7A6A8,
              v21,
              *((_DWORD *)v22 + 11),
              (char *)v22 + 52,
              (char *)v22 + 56,
              v23) )
        return CAIAgent::ExecuteResult(0, 0);
      if ( v23 )
      {
        if ( !(unsigned __int8)CAIAgentDarkTribeAttack::CheckIfShamansAreOnBoard(v22) )
          return CAIAgent::ExecuteResult(0, 0);
        *((_DWORD *)v22 + 16) = CAIAgentDarkTribeAttack::OrderManakopterToPosition((CAIAgentDarkTribeAttack *)v22, 1);
        if ( *((int *)v22 + 16) <= 0 )
          return CAIAgent::ExecuteResult(0, 0);
        CTrace::Print("DarkAttack %i: MK: CHECK -> WAIT", v21);
        *((_DWORD *)v22 + 10) = 2;
        return CAIAgent::ExecuteResult(0, 0);
      }
      else
      {
        if ( (int)CAIAgentDarkTribeAttack::OrderShamanTaskForcesToSneakUpPosition((CAIAgentDarkTribeAttack *)v22) <= 0 )
        {
          CTrace::Print("DarkAttack %i: CHECK aborted attack", v21);
          CAIAgentDarkTribeAttack::RemoveMissionBit((CAIAgentDarkTribeAttack *)v22);
          CAIAgentDarkTribeAttack::ResetAttackState((CAIAgentDarkTribeAttack *)v22);
          return CAIAgent::ExecuteResult(0, 0);
        }
        CTrace::Print("DarkAttack %i: CHECK -> WAIT", v21);
        CAIAgentDarkTribeAttack::SetMissionBit(v22, 3);
        *((_DWORD *)v22 + 10) = 2;
        return CAIAgent::ExecuteResult(0, 0);
      }
    case 2:
      if ( *((int *)v22 + 16) <= 0
        || !CAIAgentDarkTribeAttack::ManakopterTaskForceAvailable((CAIAgentDarkTribeAttack *)v22, 0) )
      {
        v16 = CAIAgentDarkTribeAttack::CheckIfPositionIsReached((CAIAgentDarkTribeAttack *)v22);
        if ( v16 < 0 )
          return CAIAgent::ExecuteResult(0, 0);
        if ( v16 > 0 && CAIAgentDarkTribeAttack::OrderShamanTaskForcesToAttackPosition((CAIAgentDarkTribeAttack *)v22) )
        {
          *((_DWORD *)v22 + 10) = 4;
          CTrace::Print("DarkAttack %i: WAIT -> ATTACK", v21);
        }
        else
        {
          CTrace::Print("DarkAttack %i: WAIT aborted attack", v21);
          CAIAgentDarkTribeAttack::RemoveMissionBit((CAIAgentDarkTribeAttack *)v22);
          CAIAgentDarkTribeAttack::ResetAttackState((CAIAgentDarkTribeAttack *)v22);
        }
        return CAIAgent::ExecuteResult(0, 0);
      }
      if ( !CAIAgentDarkTribeAttack::CheckIfManakopterReachedPosition((CAIAgentDarkTribeAttack *)v22) )
        return CAIAgent::ExecuteResult(0, 0);
      CAIAgentDarkTribeAttack::OrderManakopterUnload((CAIAgentDarkTribeAttack *)v22, 1);
      *((_DWORD *)v22 + 10) = 3;
      CTrace::Print("DarkAttack %i: MK: WAIT -> INIT_ATTACK", v21);
      return CAIAgent::ExecuteResult(0x10u, 0);
    case 3:
      CAIAgentDarkTribeAttack::OrderShamansToImmediateAttack((CAIAgentDarkTribeAttack *)v22);
      CTrace::Print("DarkAttack %i: MK: INIT_ATTACK -> ATTACK", v21);
      *((_DWORD *)v22 + 10) = 4;
      return CAIAgent::ExecuteResult(0, 0);
    case 4:
      if ( *((int *)v22 + 16) > 0
        && CAIAgentDarkTribeAttack::ManakopterTaskForceAvailable((CAIAgentDarkTribeAttack *)v22, 0) )
      {
        if ( CAIAgentDarkTribeAttack::CheckShamanTaskForcesTargets(v22) <= 0 )
        {
          CAIAgentDarkTribeAttack::OrderShamanTaskForcesToManakopter(v22, 0, 1);
          CTrace::Print("DarkAttack %i: MK: ATTACK -> WAIT_FOR_RETURN", v21);
          *((_DWORD *)v22 + 10) = 5;
        }
      }
      else
      {
        *((_DWORD *)v22 + 16) = 0;
        if ( CAIAgentDarkTribeAttack::CheckShamanTaskForcesTargets(v22) <= 0 )
        {
          *((_DWORD *)v22 + 10) = 6;
          CTrace::Print("DarkAttack %i: ATTACK -> RETURN", v21);
        }
      }
      return CAIAgent::ExecuteResult(0, 0);
    case 5:
      if ( *((int *)v22 + 16) <= 0 || !(unsigned __int8)CAIAgentDarkTribeAttack::CheckIfShamansAreOnBoard(v22) )
        return CAIAgent::ExecuteResult(0, 0);
      v8 = CAIDarkTribeSectorAgent::SectorAI((CAIDarkTribeSectorAgent *)v22);
      *((_DWORD *)v22 + 13) = CAISectorAI::BaseX(v8);
      v9 = CAIDarkTribeSectorAgent::SectorAI((CAIDarkTribeSectorAgent *)v22);
      *((_DWORD *)v22 + 14) = CAISectorAI::BaseY(v9);
      if ( CAIAgentDarkTribeAttack::OrderManakopterToPosition((CAIAgentDarkTribeAttack *)v22, 0) )
      {
        *((_DWORD *)v22 + 10) = 6;
        CTrace::Print("DarkAttack %i: MK: WAIT_FOR_RETURN -> RETURN", v21);
      }
      else
      {
        CAIAgentDarkTribeAttack::OrderShamanTaskForcesHome(v22, 10);
        *((_DWORD *)v22 + 10) = 6;
        CTrace::Print("DarkAttack %i: WAIT_FOR_RETURN -> RETURN - FOOT", v21);
      }
      return CAIAgent::ExecuteResult(0, 0);
    case 6:
      if ( *((int *)v22 + 16) <= 0 )
      {
        if ( (int)CAIAgentDarkTribeAttack::CheckIfPositionIsReached((CAIAgentDarkTribeAttack *)v22) >= 0 )
        {
          CTrace::Print("DarkAttack %i: Finished Attack - FOOT", v21);
          CAIAgentDarkTribeAttack::RemoveMissionBit((CAIAgentDarkTribeAttack *)v22);
          CAIAgentDarkTribeAttack::ResetAttackState((CAIAgentDarkTribeAttack *)v22);
        }
      }
      else if ( CAIAgentDarkTribeAttack::CheckIfManakopterReachedPosition((CAIAgentDarkTribeAttack *)v22) )
      {
        CTrace::Print("DarkAttack %i: MK: Finished Attack", v21);
        CAIAgentDarkTribeAttack::OrderManakopterUnload((CAIAgentDarkTribeAttack *)v22, 0);
        *((_DWORD *)v22 + 10) = 7;
        return CAIAgent::ExecuteResult(0x10u, 0);
      }
      return CAIAgent::ExecuteResult(0, 0);
    case 7:
      BBSupportTracePrintF(0, "DarkAttack %i: MK: STATE_RETURN_FINISH", v21);
      CAIAgentDarkTribeAttack::RemoveMissionBit((CAIAgentDarkTribeAttack *)v22);
      CAIAgentDarkTribeAttack::ResetAttackState((CAIAgentDarkTribeAttack *)v22);
      *((_DWORD *)v22 + 13) = 0;
      *((_DWORD *)v22 + 14) = 0;
      v10 = CAIDarkTribeSectorAgent::SectorAI((CAIDarkTribeSectorAgent *)v22);
      v11 = CAISectorAI::TaskForceGroup(v10);
      CAITaskForceClassWalk::CAITaskForceClassWalk(v12, v11, 7);
      while ( (unsigned __int8)CAITaskForceClassWalk::NextTaskForce(v12, 10) )
      {
        v19 = CAITaskForceClassWalk::CurrentTaskForce(v12);
        (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v19 + 32))(v19, 0, 0, 0);
        v20 = CAITaskForce::AssociatedTaskForce(v19);
        if ( v20 )
        {
          CAITaskForce::ChangeType(v20, 2);
          (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v20 + 32))(v20, 6, 0, 0);
        }
      }
      return CAIAgent::ExecuteResult(0, 0);
    default:
      if ( BBSupportDbgReportF(
             1,
             "AI\\AI_AgentDarkAttack.cpp",
             1344,
             "CAIAgentDarkTribeAttack::Execute(): Invalid state %i!",
             *((_DWORD *)v22 + 10)) == 1 )
        __debugbreak();
      CAIAgentDarkTribeAttack::RemoveMissionBit((CAIAgentDarkTribeAttack *)v22);
      CAIAgentDarkTribeAttack::ResetAttackState((CAIAgentDarkTribeAttack *)v22);
      return CAIAgent::ExecuteResult(0, 0);
  }
}


// address=[0x12fa500]
// Decompiled from int __thiscall CAIAgentDarkTribeAttack::Load(CAIAgentDarkTribeAttack *this, struct IS4Chunk *a2)
void  CAIAgentDarkTribeAttack::Load(class IS4Chunk & a2) {
  
  unsigned int v3; // [esp+0h] [ebp-8h]

  CAIAgentDarkTribeAttack::ResetAttackState(this);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516302336);
  v3 = (*(int (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 2);
  CAIAgent::Load(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516302334);
  *((_DWORD *)this + 10) = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 7);
  *((_DWORD *)this + 11) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 12) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 13) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 14) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 16) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  if ( v3 <= 1 )
    *((_DWORD *)this + 15) = 0;
  else
    *((_DWORD *)this + 15) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516302335);
}


// address=[0x12fa610]
// Decompiled from int __thiscall CAIAgentDarkTribeAttack::Save(CAIAgentDarkTribeAttack *this, struct IS4Chunk *a2)
void  CAIAgentDarkTribeAttack::Save(class IS4Chunk & a2) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516302336);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 2);
  CAIAgent::Save(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516302334);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 10));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 11));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 12));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 13));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 14));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 16));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 15));
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516302335);
}


// address=[0x12fa700]
// Decompiled from void __thiscall CAIAgentDarkTribeAttack::AttackWithShamans(CAIAgentDarkTribeAttack *this, int a2, int a3, bool a4)
void  CAIAgentDarkTribeAttack::AttackWithShamans(int a2, int a3, bool a4) {
  
  if ( a3 >= 0 )
  {
    if ( !a3 )
      a3 = 2;
    if ( !a2 )
      a2 = 1;
    if ( !*((_DWORD *)this + 10) && *((_DWORD *)this + 12) < a3 )
    {
      *((_DWORD *)this + 11) = a2;
      *((_DWORD *)this + 12) = a3;
      if ( a4 )
        CAIAgent::UpdateScheduleTimeIfLess(this, 0);
      if ( CAIAgentDarkTribeAttack::ManakopterTaskForceAvailable(this, 0) )
      {
        if ( CAIAgentDarkTribeAttack::OrderShamanTaskForcesToManakopter(this, 1, 0) )
        {
          CAIAgentDarkTribeAttack::SetMissionBit(this, 10);
          *((_DWORD *)this + 10) = 1;
        }
        else
        {
          *((_DWORD *)this + 11) = 0;
          *((_DWORD *)this + 12) = -1;
        }
      }
      else
      {
        *((_DWORD *)this + 10) = 1;
      }
    }
  }
  else
  {
    *((_DWORD *)this + 11) = 0;
    *((_DWORD *)this + 12) = -1;
  }
}


// address=[0x12fc9c0]
// Decompiled from void __thiscall CAIAgentDarkTribeAttack::~CAIAgentDarkTribeAttack(CAIAgentDarkTribeAttack *this)
 CAIAgentDarkTribeAttack::~CAIAgentDarkTribeAttack(void) {
  
  CAIDarkTribeSectorAgent::~CAIDarkTribeSectorAgent(this);
}


// address=[0x12fa7e0]
// Decompiled from CAIAgentDarkTribeAttack *__thiscall CAIAgentDarkTribeAttack::ResetAttackState(CAIAgentDarkTribeAttack *this)
void  CAIAgentDarkTribeAttack::ResetAttackState(void) {
  
  CAIAgentDarkTribeAttack *result; // eax
  pairNode *v2; // eax
  int v3; // esi
  unsigned int v4; // esi
  unsigned int v5; // esi
  int v6; // [esp+4h] [ebp-10h]
  int v7; // [esp+8h] [ebp-Ch]

  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = -1;
  *((_DWORD *)this + 16) = 0;
  result = CAIDarkTribeSectorAgent::SectorAI(this);
  if ( result )
  {
    v2 = (pairNode *)CAISectorAI::PlayerAI(result);
    v7 = CAIPlayerAI::PlayerId(v2);
    CAIPlayersScriptVars::operator[](v7);
    v6 = CAIPlayerScriptVars::operator[](22);
    v3 = IAIEnvironment::TickCounter();
    v4 = IAIEnvironment::MinutesToTicks(v6) + v3;
    v5 = (unsigned __int8)IAIEnvironment::Rand() + v4;
    result = this;
    *((_DWORD *)this + 15) = v5;
  }
  else
  {
    *((_DWORD *)this + 15) = 0;
  }
  return result;
}


// address=[0x12fa890]
// Decompiled from char __thiscall CAIAgentDarkTribeAttack::ShamanAttackTaskForceAvailable(CAIAgentDarkTribeAttack *this)
bool  CAIAgentDarkTribeAttack::ShamanAttackTaskForceAvailable(void)const {
  
  struct CAIDarkTribeSectorAI *v1; // eax
  int v2; // eax
  struct CAITaskForce *TaskForceGroupMemberOfSameClass; // [esp+0h] [ebp-10h]
  pairNode *i; // [esp+Ch] [ebp-4h]

  v1 = CAIDarkTribeSectorAgent::SectorAI(this);
  v2 = CAISectorAI::TaskForceGroup(v1);
  for ( i = (pairNode *)CAITaskForceGroup::FirstTaskForce(v2, 7); i; i = TaskForceGroupMemberOfSameClass )
  {
    TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
    if ( CAITaskForce::NumberOfEntities(i) > 0 && CAITaskForce::AssociatedTaskForce(i) )
      return 1;
  }
  return 0;
}


// address=[0x12fa900]
// Decompiled from char __thiscall CAIAgentDarkTribeAttack::ManakopterTaskForceAvailable(CAIAgentDarkTribeAttack *this, bool a2)
bool  CAIAgentDarkTribeAttack::ManakopterTaskForceAvailable(bool a2)const {
  
  struct CAIDarkTribeSectorAI *v2; // eax
  int v3; // eax
  struct CAITaskForce *TaskForceGroupMemberOfSameClass; // [esp+0h] [ebp-10h]
  pairNode *i; // [esp+Ch] [ebp-4h]

  v2 = CAIDarkTribeSectorAgent::SectorAI(this);
  v3 = CAISectorAI::TaskForceGroup(v2);
  for ( i = (pairNode *)CAITaskForceGroup::FirstTaskForce(v3, 8); i; i = TaskForceGroupMemberOfSameClass )
  {
    TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
    if ( CAITaskForce::NumberOfEntities(i) > 0 )
    {
      if ( !a2 )
        return 1;
      if ( CAITaskForce::Status(i) == 10 )
        return 1;
    }
  }
  return 0;
}


// address=[0x12fa980]
// Decompiled from bool __thiscall CAIAgentDarkTribeAttack::CheckShamanAttackPosition(CAIAgentDarkTribeAttack *this)
bool  CAIAgentDarkTribeAttack::CheckShamanAttackPosition(void) {
  
  struct CAIDarkTribeSectorAI *v1; // eax
  int v3; // [esp+0h] [ebp-8h]

  v1 = CAIDarkTribeSectorAgent::SectorAI(this);
  v3 = CAISectorAI::SectorId(v1);
  return IAIEnvironment::FindNearestSectorPosition((int *)this + 13, (int *)this + 14, v3, 15);
}


// address=[0x12fa9c0]
// Decompiled from int __thiscall CAIAgentDarkTribeAttack::OrderShamanTaskForcesHome(CAIDarkTribeSectorAgent *this, int a2)
void  CAIAgentDarkTribeAttack::OrderShamanTaskForcesHome(enum T_AI_TASK_FORCE_CMD a2) {
  
  struct CAIDarkTribeSectorAI *v2; // eax
  struct CAIDarkTribeSectorAI *v3; // eax
  int v4; // eax
  int result; // eax
  _BYTE v6[8]; // [esp+0h] [ebp-14h] BYREF
  int v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+Ch] [ebp-8h]
  CAIDarkTribeSectorAgent *v9; // [esp+10h] [ebp-4h]

  v9 = this;
  v2 = CAIDarkTribeSectorAgent::SectorAI(this);
  v7 = CAISectorAI::BasePackedXY(v2);
  v3 = CAIDarkTribeSectorAgent::SectorAI(v9);
  v4 = CAISectorAI::TaskForceGroup(v3);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v6, v4, 7);
  while ( 1 )
  {
    result = CAITaskForceClassWalk::NextTaskForce(v6, a2);
    if ( !(_BYTE)result )
      break;
    v8 = CAITaskForceClassWalk::CurrentTaskForce(v6);
    (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v8 + 32))(v8, 7, v7, 0);
  }
  return result;
}


// address=[0x12faa30]
// Decompiled from int __thiscall CAIAgentDarkTribeAttack::OrderShamanTaskForcesToManakopter(  CAIDarkTribeSectorAgent *this,  bool a2,  char a3)
int  CAIAgentDarkTribeAttack::OrderShamanTaskForcesToManakopter(bool a2, bool a3) {
  
  struct CAIDarkTribeSectorAI *v3; // eax
  int v4; // eax
  CUserToolsManager *v5; // eax
  pairNode *v6; // eax
  struct CAIDarkTribeSectorAI *v7; // eax
  pairNode *v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v14; // [esp-Ch] [ebp-5Ch]
  int v15; // [esp-8h] [ebp-58h]
  _BYTE v16[8]; // [esp+0h] [ebp-50h] BYREF
  int v17; // [esp+8h] [ebp-48h]
  IFlyingEntity *ManakopterPtr; // [esp+Ch] [ebp-44h]
  int v19; // [esp+10h] [ebp-40h]
  int EntityInfo; // [esp+14h] [ebp-3Ch]
  int v21; // [esp+18h] [ebp-38h] BYREF
  int v22; // [esp+1Ch] [ebp-34h] BYREF
  int v23; // [esp+20h] [ebp-30h]
  CAIDarkTribeSectorAgent *v24; // [esp+24h] [ebp-2Ch]
  int v25; // [esp+28h] [ebp-28h]
  int v26; // [esp+2Ch] [ebp-24h]
  int v27; // [esp+30h] [ebp-20h]
  int Entity; // [esp+34h] [ebp-1Ch]
  pairNode *v29; // [esp+38h] [ebp-18h]
  int NearestManakopter; // [esp+3Ch] [ebp-14h]
  int v31; // [esp+40h] [ebp-10h]
  pairNode *v32; // [esp+44h] [ebp-Ch]
  CUserToolsManager *v33; // [esp+48h] [ebp-8h]
  char v34; // [esp+4Fh] [ebp-1h]

  v24 = this;
  v26 = 0;
  v3 = CAIDarkTribeSectorAgent::SectorAI(this);
  v4 = CAISectorAI::TaskForceGroup(v3);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v16, v4, 7);
  v33 = 0;
  v25 = 0;
  if ( a3 )
  {
    while ( (unsigned __int8)CAITaskForceClassWalk::NextTaskForce(v16, 12) )
    {
      v5 = (CUserToolsManager *)CAITaskForceClassWalk::CurrentTaskForce(v16);
      if ( (CAITaskForce::Flags(v5) & 0x20000000) != 0 )
        v33 = (CUserToolsManager *)CAITaskForceClassWalk::CurrentTaskForce(v16);
    }
  }
  else
  {
    while ( (unsigned __int8)CAITaskForceClassWalk::NextTaskForce(v16, 12) )
    {
      v29 = (pairNode *)CAITaskForceClassWalk::CurrentTaskForce(v16);
      v31 = CAITaskForce::NumberOfEntities(v29);
      if ( v31 > 0 )
      {
        if ( CAITaskForce::AssociatedTaskForce(v29) )
        {
          v6 = (pairNode *)CAITaskForce::AssociatedTaskForce(v29);
          if ( CAITaskForce::NumberOfEntities(v6) > 0 )
            v31 += 10;
        }
      }
      if ( v31 > v25 )
      {
        v25 = v31;
        v33 = v29;
      }
    }
  }
  if ( !v33 )
    return v26;
  if ( !CAITaskForce::GetPositionOfFirstEntity(v33, &v21, &v22) )
    return v26;
  v15 = v22;
  v14 = v21;
  v7 = CAIDarkTribeSectorAgent::SectorAI(v24);
  v8 = (pairNode *)CAISectorAI::PlayerAI(v7);
  v9 = CAIPlayerAI::PlayerId(v8);
  NearestManakopter = IAIEnvironment::EntityFindNearestManakopter(v9, v14, v15, a2);
  if ( !NearestManakopter )
    return v26;
  v34 = 0;
  if ( a3 )
  {
    EntityInfo = IAIEnvironment::EntityGetEntityInfo(NearestManakopter, 0);
    v19 = CAIEntityInfo::TaskForce(EntityInfo);
    if ( CAITaskForce::Status(v19) == 10 && (CAITaskForce::Flags(v33) & 0x20000000) != 0 )
      v34 = 1;
  }
  else
  {
    if ( (CAITaskForce::Flags(v33) & 0x20000000) != 0
      && BBSupportDbgReport(
           2,
           "AI\\AI_AgentDarkAttack.cpp",
           641,
           "!(pTaskForce->Flags() & AI_TASK_FORCE_FLAG_ON_MISSION )") == 1 )
    {
      __debugbreak();
    }
    v34 = 1;
  }
  ManakopterPtr = CFlyingMgr::GetManakopterPtr((CFlyingMgr *)g_cFlyingMgr, NearestManakopter);
  if ( IFlyingEntity::FlyingFlagBits(ManakopterPtr, 1) )
    v34 = 0;
  if ( !v34 )
    return v26;
  (*(void (__thiscall **)(CUserToolsManager *, int, int, _DWORD))(*(_DWORD *)v33 + 32))(v33, 10, NearestManakopter, 0);
  v32 = (pairNode *)CAITaskForce::AssociatedTaskForce(v33);
  if ( v32 )
  {
    (*(void (__thiscall **)(pairNode *, int, int, _DWORD))(*(_DWORD *)v32 + 32))(v32, 10, NearestManakopter, 0);
    CAITaskForce::ChangeType(v32, 7);
    v23 = CAITaskForce::NumberOfEntities(v32);
    v10 = CStaticConfigVarInt::operator int(&CAIAgentDarkTribeAttack::s_iMaxSoldiersPerTaskForce);
    if ( v23 > v10 )
    {
      Entity = CAITaskForce::FirstEntity(v32);
      v11 = CStaticConfigVarInt::operator int(&CAIAgentDarkTribeAttack::s_iMaxSoldiersPerTaskForce);
      v27 = v23 - v11;
      while ( Entity && v27 > 0 )
      {
        v17 = CAIEntityInfo::Next(Entity);
        v12 = CAIEntityInfo::EntityId(Entity);
        CAITaskForce::RemoveEntity(v32, v12);
        --v27;
        Entity = v17;
      }
    }
  }
  return ++v26;
}


// address=[0x12facf0]
// Decompiled from int __thiscall CAIAgentDarkTribeAttack::OrderShamanTaskForcesToSneakUpPosition(CAIAgentDarkTribeAttack *this)
int  CAIAgentDarkTribeAttack::OrderShamanTaskForcesToSneakUpPosition(void) {
  
  struct CAIDarkTribeSectorAI *v2; // eax
  int v3; // eax
  _BYTE v4[8]; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+8h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  CAIDarkTribeSectorAgent *v8; // [esp+14h] [ebp-4h]

  v8 = this;
  if ( !CAIAgentDarkTribeAttack::CheckShamanAttackPosition(this) )
    return 0;
  v5 = IAIEnvironment::PackXYFast(*((_DWORD *)v8 + 13), *((_DWORD *)v8 + 14));
  v7 = 0;
  v2 = CAIDarkTribeSectorAgent::SectorAI(v8);
  v3 = CAISectorAI::TaskForceGroup(v2);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v4, v3, 7);
  while ( CAITaskForceClassWalk::NextTaskForce((CAITaskForceClassWalk *)v4) )
  {
    v6 = CAITaskForceClassWalk::CurrentTaskForce(v4);
    if ( CAITaskForce::AssociatedTaskForce(v6) )
    {
      (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v6 + 32))(v6, 3, v5, 0);
      if ( ++v7 >= *((_DWORD *)v8 + 12) )
        return v7;
    }
  }
  return v7;
}


// address=[0x12fadb0]
// Decompiled from int __thiscall CAIAgentDarkTribeAttack::OrderShamanTaskForcesToAttackPosition(CAIAgentDarkTribeAttack *this)
int  CAIAgentDarkTribeAttack::OrderShamanTaskForcesToAttackPosition(void) {
  
  struct CAIDarkTribeSectorAI *v2; // eax
  int v3; // eax
  _BYTE v4[8]; // [esp+0h] [ebp-18h] BYREF
  int v5; // [esp+8h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]
  CAIDarkTribeSectorAgent *v8; // [esp+14h] [ebp-4h]

  v8 = this;
  if ( CAIAgentDarkTribeAttack::CheckShamanAttackPosition(this) )
  {
    v5 = IAIEnvironment::PackXYFast(*((_DWORD *)v8 + 13), *((_DWORD *)v8 + 14));
    v7 = 0;
    v2 = CAIDarkTribeSectorAgent::SectorAI(v8);
    v3 = CAISectorAI::TaskForceGroup(v2);
    CAITaskForceClassWalk::CAITaskForceClassWalk(v4, v3, 7);
    while ( (unsigned __int8)CAITaskForceClassWalk::NextTaskForce(v4, 3) )
    {
      ++v7;
      v6 = CAITaskForceClassWalk::CurrentTaskForce(v4);
      (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v6 + 32))(v6, 9, v5, 0);
    }
    return v7;
  }
  else
  {
    CAIAgentDarkTribeAttack::OrderShamanTaskForcesHome(v8, 3);
    return 0;
  }
}


// address=[0x12fae60]
// Decompiled from int __thiscall CAIAgentDarkTribeAttack::OrderManakopterToPosition(CAIAgentDarkTribeAttack *this, bool a2)
int  CAIAgentDarkTribeAttack::OrderManakopterToPosition(bool a2) {
  
  struct CAIDarkTribeSectorAI *v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v8; // [esp+0h] [ebp-84h]
  int v9; // [esp+0h] [ebp-84h]
  struct CAITaskForce *TaskForceGroupMemberOfSameClass; // [esp+4h] [ebp-80h]
  int v11; // [esp+8h] [ebp-7Ch]
  char *v12; // [esp+Ch] [ebp-78h]
  char *v13; // [esp+10h] [ebp-74h]
  struct _Cnd_internal_imp_t *v14; // [esp+14h] [ebp-70h]
  struct _Mtx_internal_imp_t *v15; // [esp+18h] [ebp-6Ch]
  int v16; // [esp+1Ch] [ebp-68h]
  int v17; // [esp+20h] [ebp-64h]
  int v18; // [esp+24h] [ebp-60h]
  int v19; // [esp+28h] [ebp-5Ch]
  int v20; // [esp+2Ch] [ebp-58h]
  CAITaskForce *i; // [esp+34h] [ebp-50h]
  struct _Mtx_internal_imp_t *v23; // [esp+38h] [ebp-4Ch] BYREF
  int v24; // [esp+3Ch] [ebp-48h]
  char *v25; // [esp+40h] [ebp-44h]
  char *v26; // [esp+44h] [ebp-40h]
  int j; // [esp+48h] [ebp-3Ch]
  unsigned int v28; // [esp+4Ch] [ebp-38h]
  int v29; // [esp+50h] [ebp-34h]
  struct _Cnd_internal_imp_t *v30; // [esp+54h] [ebp-30h] BYREF
  int v31; // [esp+58h] [ebp-2Ch]
  char v32; // [esp+5Fh] [ebp-25h]
  _DWORD v33[4]; // [esp+60h] [ebp-24h]
  _DWORD v34[4]; // [esp+70h] [ebp-14h]

  v30 = (struct _Cnd_internal_imp_t *)*((_DWORD *)this + 13);
  v23 = (struct _Mtx_internal_imp_t *)*((_DWORD *)this + 14);
  IAIEnvironment::GetNearestNoneBlockedPosition((int *)&v30, (int *)&v23);
  v24 = IAIEnvironment::WorldSectorId((int)v30, (int)v23);
  if ( v24 <= 0 && BBSupportDbgReport(2, "AI\\AI_AgentDarkAttack.cpp", 434, "iTargetExSectorId > 0") == 1 )
    __debugbreak();
  v19 = 0;
  v2 = CAIDarkTribeSectorAgent::SectorAI(this);
  v3 = CAISectorAI::TaskForceGroup(v2);
  for ( i = (CAITaskForce *)CAITaskForceGroup::FirstTaskForce(v3, 8); i; i = TaskForceGroupMemberOfSameClass )
  {
    TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
    v29 = 0;
    v31 = 0;
    if ( a2 && v24 > 0 )
    {
      v34[0] = -4;
      v34[1] = 2;
      v34[2] = -4;
      v34[3] = 2;
      v33[0] = -2;
      v33[1] = -2;
      v33[2] = 4;
      v33[3] = 4;
      v29 = -(IAIEnvironment::Rand(v8) & 0xF);
      v31 = IAIEnvironment::Rand(v9) & 0xF;
      v13 = (char *)v30 + v29;
      v12 = (char *)v23 + v31;
      v28 = 0;
      v26 = 0;
      v25 = 0;
      v8 = 1000;
      while ( v28 < 0x3E8 )
      {
        v26 = &v13[CSpiralOffsets::DeltaX(v28)];
        v25 = &v12[CSpiralOffsets::DeltaY(v28)];
        v20 = CWorldManager::Index((int)v26, (int)v25);
        if ( (unsigned __int8)CWorldManager::InWorld((int)v26, (int)v25) )
        {
          v4 = CWorldManager::SectorId(v20);
          if ( v4 == v24 && (int)ITiling::CatapultSectorId(v20) > 0 && !CWorldManager::FlagBits(v20, 8u) )
          {
            v32 = 1;
            for ( j = 0; j < 4; ++j )
            {
              v17 = (int)&v26[v34[j]];
              v18 = (int)&v25[v33[j]];
              if ( (unsigned __int8)CWorldManager::InWorld(v17, v18) )
              {
                v16 = CWorldManager::Index(v17, v18);
                v5 = CWorldManager::SectorId(v16);
                if ( v5 != v24 || !ITiling::CatapultSectorId(v16) )
                  v32 = 0;
              }
            }
            if ( v32 )
            {
              v29 = v26 - (char *)v30;
              v31 = v25 - (char *)v23;
              break;
            }
          }
        }
        ++v28;
      }
      if ( v28 >= 0x3E8 )
      {
        v29 = -2;
        v31 = 2;
        v14 = (struct _Cnd_internal_imp_t *)((char *)v30 - 2);
        v15 = (struct _Cnd_internal_imp_t *)((char *)v30 + 2);
        if ( !IAIEnvironment::WorldInWorld((char *)v30 - 2, (char *)v30 + 2)
          || (v6 = IAIEnvironment::WorldSectorId((int)v14, (int)v15), v6 != v24) )
        {
          v29 = 0;
          v31 = 0;
        }
      }
    }
    v11 = IAIEnvironment::PackXYFast((char *)v30 + v29, (char *)v23 + v31);
    (*(void (__thiscall **)(CAITaskForce *, int, int, _DWORD))(*(_DWORD *)i + 32))(i, 1, v11, 0);
    ++v19;
  }
  return v19;
}


// address=[0x12fb1c0]
// Decompiled from int __thiscall CAIAgentDarkTribeAttack::OrderManakopterUnload(CAIAgentDarkTribeAttack *this, bool a2)
int  CAIAgentDarkTribeAttack::OrderManakopterUnload(bool a2) {
  
  struct CAIDarkTribeSectorAI *v2; // eax
  int v3; // eax
  _BYTE v5[8]; // [esp+0h] [ebp-14h] BYREF
  CAIAgentDarkTribeAttack *v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  v6 = this;
  v7 = 0;
  v2 = CAIDarkTribeSectorAgent::SectorAI(this);
  v3 = CAISectorAI::TaskForceGroup(v2);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v5, v3, 8);
  while ( (unsigned __int8)CAITaskForceClassWalk::NextTaskForce(v5, 1) )
  {
    ++v7;
    v8 = CAITaskForceClassWalk::CurrentTaskForce(v5);
    if ( a2 )
      (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v8 + 32))(v8, 12, 0, 0);
    else
      (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v8 + 32))(v8, 11, 0, 0);
  }
  return v7;
}


// address=[0x12fb250]
// Decompiled from int __thiscall CAIAgentDarkTribeAttack::OrderShamansToImmediateAttack(CAIAgentDarkTribeAttack *this)
int  CAIAgentDarkTribeAttack::OrderShamansToImmediateAttack(void) {
  
  struct CAIDarkTribeSectorAI *v1; // eax
  int v2; // eax
  CUserToolsManager *v3; // eax
  int v4; // eax
  _BYTE v6[8]; // [esp+0h] [ebp-1Ch] BYREF
  int v7; // [esp+8h] [ebp-14h]
  int v8; // [esp+Ch] [ebp-10h]
  int v9; // [esp+10h] [ebp-Ch]
  int v10; // [esp+14h] [ebp-8h]
  CAIDarkTribeSectorAgent *v11; // [esp+18h] [ebp-4h]

  v11 = this;
  v9 = 0;
  v7 = IAIEnvironment::PackXYFast(*((_DWORD *)this + 13), *((_DWORD *)this + 14));
  v1 = CAIDarkTribeSectorAgent::SectorAI(v11);
  v2 = CAISectorAI::TaskForceGroup(v1);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v6, v2, 7);
  while ( CAITaskForceClassWalk::NextTaskForce((CAITaskForceClassWalk *)v6) )
  {
    v3 = (CUserToolsManager *)CAITaskForceClassWalk::CurrentTaskForce(v6);
    if ( (CAITaskForce::Flags(v3) & 0x20000000) != 0 )
    {
      ++v9;
      v8 = CAITaskForceClassWalk::CurrentTaskForce(v6);
      (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v8 + 32))(v8, 14, v7, 0);
      v4 = CAITaskForceClassWalk::CurrentTaskForce(v6);
      v10 = CAITaskForce::AssociatedTaskForce(v4);
      if ( v10 )
        (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v10 + 32))(v10, 6, 0, 0);
    }
  }
  return v9;
}


// address=[0x12fb320]
// Decompiled from int __thiscall CAIAgentDarkTribeAttack::CheckIfPositionIsReached(CAIAgentDarkTribeAttack *this)
int  CAIAgentDarkTribeAttack::CheckIfPositionIsReached(void) {
  
  struct CAIDarkTribeSectorAI *v1; // eax
  int v2; // eax
  CUserToolsManager *v3; // eax
  int v4; // eax
  _BYTE v6[8]; // [esp+0h] [ebp-10h] BYREF
  CAIAgentDarkTribeAttack *v7; // [esp+8h] [ebp-8h]
  int v8; // [esp+Ch] [ebp-4h]

  v7 = this;
  v8 = 0;
  v1 = CAIDarkTribeSectorAgent::SectorAI(this);
  v2 = CAISectorAI::TaskForceGroup(v1);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v6, v2, 7);
  while ( CAITaskForceClassWalk::NextTaskForce((CAITaskForceClassWalk *)v6) )
  {
    v3 = (CUserToolsManager *)CAITaskForceClassWalk::CurrentTaskForce(v6);
    if ( (CAITaskForce::Flags(v3) & 0x20000000) != 0 )
    {
      ++v8;
      v4 = CAITaskForceClassWalk::CurrentTaskForce(v6);
      if ( CAITaskForce::Status(v4) == 2 )
        return -1;
    }
  }
  return v8;
}


// address=[0x12fb3a0]
// Decompiled from char __thiscall CAIAgentDarkTribeAttack::CheckIfManakopterReachedPosition(CAIAgentDarkTribeAttack *this)
bool  CAIAgentDarkTribeAttack::CheckIfManakopterReachedPosition(void) {
  
  struct CAIDarkTribeSectorAI *v1; // eax
  int v2; // eax
  _BYTE v4[8]; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+8h] [ebp-8h]
  CAIAgentDarkTribeAttack *v6; // [esp+Ch] [ebp-4h]

  v6 = this;
  v1 = CAIDarkTribeSectorAgent::SectorAI(this);
  v2 = CAISectorAI::TaskForceGroup(v1);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v4, v2, 8);
  while ( (unsigned __int8)CAITaskForceClassWalk::NextTaskForce(v4, 1) )
  {
    v5 = CAITaskForceClassWalk::CurrentTaskForce(v4);
    if ( CAITaskForce::Status(v5) != 1 )
      return 0;
  }
  return 1;
}


// address=[0x12fb400]
// Decompiled from char __thiscall CAIAgentDarkTribeAttack::CheckIfShamansAreOnBoard(CAIAgentDarkTribeAttack *this)
bool  CAIAgentDarkTribeAttack::CheckIfShamansAreOnBoard(void) {
  
  struct CAIDarkTribeSectorAI *v1; // eax
  int v2; // eax
  struct CAIDarkTribeSectorAI *v4; // eax
  int v5; // eax
  _BYTE v6[8]; // [esp+0h] [ebp-20h] BYREF
  _BYTE v7[8]; // [esp+8h] [ebp-18h] BYREF
  CUserToolsManager *v8; // [esp+10h] [ebp-10h]
  CAIDarkTribeSectorAgent *v9; // [esp+14h] [ebp-Ch]
  int v10; // [esp+18h] [ebp-8h]
  CUserToolsManager *v11; // [esp+1Ch] [ebp-4h]

  v9 = this;
  v1 = CAIDarkTribeSectorAgent::SectorAI(this);
  v2 = CAISectorAI::TaskForceGroup(v1);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v7, v2, 7);
  while ( CAITaskForceClassWalk::NextTaskForce((CAITaskForceClassWalk *)v7) )
  {
    v11 = (CUserToolsManager *)CAITaskForceClassWalk::CurrentTaskForce(v7);
    if ( (CAITaskForce::Flags(v11) & 0x20000000) != 0 )
    {
      if ( CAITaskForce::Status(v11) != 8 )
        return 0;
      v10 = CAITaskForce::AssociatedTaskForce(v11);
      if ( v10 )
      {
        if ( CAITaskForce::Status(v10) != 8 )
          return 0;
      }
    }
  }
  v4 = CAIDarkTribeSectorAgent::SectorAI(v9);
  v5 = CAISectorAI::TaskForceGroup(v4);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v6, v5, 2);
  while ( CAITaskForceClassWalk::NextTaskForce((CAITaskForceClassWalk *)v7) )
  {
    v8 = (CUserToolsManager *)CAITaskForceClassWalk::CurrentTaskForce(v7);
    if ( (CAITaskForce::Flags(v8) & 0x20000000) != 0 && CAITaskForce::Status(v8) != 8 )
      return 0;
  }
  return 1;
}


// address=[0x12fb4e0]
// Decompiled from int __thiscall CAIAgentDarkTribeAttack::CheckShamanTaskForcesTargets(void *this)
int  CAIAgentDarkTribeAttack::CheckShamanTaskForcesTargets(void) {
  
  struct CAIDarkTribeSectorAI *v1; // eax
  pairNode *v2; // eax
  struct CAIDarkTribeSectorAI *v3; // eax
  int v4; // eax
  struct CAIDarkTribeSectorAI *v6; // eax
  int v7; // eax
  struct CAIDarkTribeSectorAI *v8; // eax
  int v9; // eax
  unsigned int v10; // esi
  unsigned int v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  int v14; // eax
  int v15; // eax
  struct CAIDarkTribeSectorAI *v16; // eax
  int v17; // [esp+0h] [ebp-5Ch]
  _BYTE v18[8]; // [esp+4h] [ebp-58h] BYREF
  int v19; // [esp+Ch] [ebp-50h]
  int v20; // [esp+10h] [ebp-4Ch]
  unsigned int v22; // [esp+18h] [ebp-44h]
  int v23; // [esp+1Ch] [ebp-40h]
  int v24; // [esp+20h] [ebp-3Ch] BYREF
  int v25; // [esp+24h] [ebp-38h] BYREF
  int MostRequiredGood; // [esp+28h] [ebp-34h]
  int v27; // [esp+2Ch] [ebp-30h]
  int v28; // [esp+30h] [ebp-2Ch]
  int v29; // [esp+34h] [ebp-28h]
  int v30; // [esp+38h] [ebp-24h]
  int FirstBuildingId; // [esp+3Ch] [ebp-20h]
  struct CPile *PilePtr; // [esp+40h] [ebp-1Ch]
  int v33; // [esp+44h] [ebp-18h] BYREF
  int v34; // [esp+48h] [ebp-14h] BYREF
  int v35; // [esp+4Ch] [ebp-10h]
  CDockState *v36; // [esp+50h] [ebp-Ch]
  void *v37; // [esp+54h] [ebp-8h]
  bool PositionOfFirstEntity; // [esp+59h] [ebp-3h]
  char v39; // [esp+5Ah] [ebp-2h]
  char v40; // [esp+5Bh] [ebp-1h]

  v37 = this;
  v1 = CAIDarkTribeSectorAgent::SectorAI((CAIDarkTribeSectorAgent *)this);
  v2 = (pairNode *)CAISectorAI::PlayerAI(v1);
  v30 = CAIPlayerAI::PlayerId(v2);
  v22 = IAIEnvironment::TickCounter();
  v3 = CAIDarkTribeSectorAgent::SectorAI((CAIDarkTribeSectorAgent *)v37);
  v4 = CAISectorAI::TaskForceGroup(v3);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v18, v4, 7);
  v35 = 0;
  if ( !(unsigned __int8)CAIAgentDarkTribeAttack::CheckIfReadyForReturn(v37) )
    goto LABEL_12;
  if ( *((int *)v37 + 16) > 0 && CAIAgentDarkTribeAttack::OrderShamanTaskForcesToManakopter(v37, 0, 1) )
  {
    *((_DWORD *)v37 + 10) = 5;
    return 1;
  }
  if ( CAIAgentDarkTribeAttack::ManakopterTaskForceAvailable((CAIAgentDarkTribeAttack *)v37, 1)
    && (unsigned __int8)CAIAgentDarkTribeAttack::CheckIfShamansAreOnBoard(v37) )
  {
    v6 = CAIDarkTribeSectorAgent::SectorAI((CAIDarkTribeSectorAgent *)v37);
    v7 = CAISectorAI::BaseX(v6);
    *((_DWORD *)v37 + 13) = v7;
    v8 = CAIDarkTribeSectorAgent::SectorAI((CAIDarkTribeSectorAgent *)v37);
    v9 = CAISectorAI::BaseY(v8);
    *((_DWORD *)v37 + 14) = v9;
    CAIAgentDarkTribeAttack::OrderManakopterToPosition((CAIAgentDarkTribeAttack *)v37, 0);
    *((_DWORD *)v37 + 10) = 6;
    return 1;
  }
  if ( !*((_DWORD *)v37 + 16) )
  {
    CAIAgentDarkTribeAttack::OrderShamanTaskForcesHome(v37, 9);
    return v35 - 1;
  }
  if ( CAIAgentDarkTribeAttack::ManakopterTaskForceAvailable((CAIAgentDarkTribeAttack *)v37, 1) )
  {
LABEL_12:
    v29 = 9;
    if ( *((int *)v37 + 16) > 0 )
      v29 = 14;
    while ( (unsigned __int8)CAITaskForceClassWalk::NextTaskForce(v18, v29) )
    {
      ++v35;
      v36 = (CDockState *)CAITaskForceClassWalk::CurrentTaskForce(v18);
      PositionOfFirstEntity = CAITaskForce::GetPositionOfFirstEntity(v36, &v24, &v25);
      if ( !PositionOfFirstEntity && BBSupportDbgReport(2, "AI\\AI_AgentDarkAttack.cpp", 951, "bGetPositionOk") == 1 )
        __debugbreak();
      v39 = 0;
      if ( CAITaskForce::Status(v36) == 2 || *((_DWORD *)v37 + 16) )
      {
        v10 = CAITaskForce::CmdTimeStamp(v36);
        v11 = IAIEnvironment::Rand(v17);
        if ( v10 + v11 % 0x80 + 185 < v22 )
          v39 = 1;
      }
      else
      {
        v39 = 1;
      }
      v28 = CWorldManager::ObjectId(*((_DWORD *)v37 + 13), *((_DWORD *)v37 + 14));
      if ( v28 )
      {
        PilePtr = CPileMgr::GetPilePtr(v28);
        if ( PilePtr )
        {
          if ( (v27 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)PilePtr + 60))(PilePtr), v27 != 20) && v27 != 7
            || !(unsigned __int8)CPile::GoodAvailable(PilePtr) )
          {
            v39 = 1;
          }
        }
      }
      else if ( !(*(int (__thiscall **)(void *, char *, char *, int))(*(_DWORD *)off_3D7A6A8 + 12))(
                   off_3D7A6A8,
                   (char *)v37 + 52,
                   (char *)v37 + 56,
                   2) )
      {
        v39 = 1;
      }
      if ( v39 )
      {
        v33 = v24;
        v34 = v25;
        v40 = 0;
        FirstBuildingId = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, v30, 80);
        if ( FirstBuildingId )
        {
          v12 = (_DWORD *)CBuildingMgr::operator[](FirstBuildingId);
          if ( IEntity::FlagBits(v12, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
          {
            v13 = (_DWORD *)CBuildingMgr::operator[](FirstBuildingId);
            v20 = CBuilding::Role(v13);
            MostRequiredGood = CManakopterHallRole::GetMostRequiredGood(v20);
            if ( MostRequiredGood )
            {
              if ( (*(int (__thiscall **)(void *, int *, int *, int))(*(_DWORD *)off_3D7A6A8 + 8))(
                     off_3D7A6A8,
                     &v33,
                     &v34,
                     MostRequiredGood) )
              {
                v40 = 1;
              }
            }
          }
        }
        if ( !v40 )
          v40 = (*(int (__thiscall **)(void *, int, int, int *, int *))(*(_DWORD *)off_3D7A6A8 + 4))(
                  off_3D7A6A8,
                  v30,
                  32,
                  &v33,
                  &v34);
        if ( !v40 )
        {
          v14 = CAITaskForce::CmdGoal(v36);
          v33 = IAIEnvironment::UnpackXFast(v14);
          v15 = CAITaskForce::CmdGoal(v36);
          v34 = IAIEnvironment::UnpackYFast(v15);
          if ( (int)IAIEnvironment::GridDistance(v33 - v24, v34 - v25) > 8 )
            v40 = (*(int (__thiscall **)(void *, int, int, int *, int *))(*(_DWORD *)off_3D7A6A8 + 4))(
                    off_3D7A6A8,
                    v30,
                    32,
                    &v33,
                    &v34);
        }
        if ( v40 )
        {
          v23 = IAIEnvironment::PackXYFast(v33, v34);
          if ( *((_DWORD *)v37 + 16) )
            (*(void (__thiscall **)(CDockState *, int, int, _DWORD))(*(_DWORD *)v36 + 32))(v36, 14, v23, 0);
          else
            (*(void (__thiscall **)(CDockState *, int, int, _DWORD))(*(_DWORD *)v36 + 32))(v36, 9, v23, 0);
        }
        else
        {
          v16 = CAIDarkTribeSectorAgent::SectorAI((CAIDarkTribeSectorAgent *)v37);
          v19 = CAISectorAI::BasePackedXY(v16);
          if ( *((int *)v37 + 16) > 0
            && CAIAgentDarkTribeAttack::ManakopterTaskForceAvailable((CAIAgentDarkTribeAttack *)v37, 0) )
          {
            CAIAgentDarkTribeAttack::OrderShamanTaskForcesToManakopter(v37, 0, 1);
            *((_DWORD *)v37 + 10) = 5;
          }
          else
          {
            (*(void (__thiscall **)(CDockState *, int, int, _DWORD))(*(_DWORD *)v36 + 32))(v36, 7, v19, 0);
            *((_DWORD *)v37 + 10) = 6;
          }
          --v35;
        }
      }
    }
    return v35;
  }
  else
  {
    CAIAgentDarkTribeAttack::OrderShamanTaskForcesHome(v37, 14);
    return v35 - 1;
  }
}


// address=[0x12fb990]
// Decompiled from char __thiscall CAIAgentDarkTribeAttack::CheckIfReadyForReturn(CAIAgentDarkTribeAttack *this)
bool  CAIAgentDarkTribeAttack::CheckIfReadyForReturn(void) {
  
  struct CAIDarkTribeSectorAI *v1; // eax
  int v2; // eax
  CUserToolsManager *v3; // eax
  int v4; // eax
  _BYTE v6[8]; // [esp+0h] [ebp-Ch] BYREF
  CAIAgentDarkTribeAttack *v7; // [esp+8h] [ebp-4h]

  v7 = this;
  v1 = CAIDarkTribeSectorAgent::SectorAI(this);
  v2 = CAISectorAI::TaskForceGroup(v1);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v6, v2, 7);
  while ( CAITaskForceClassWalk::NextTaskForce((CAITaskForceClassWalk *)v6) )
  {
    v3 = (CUserToolsManager *)CAITaskForceClassWalk::CurrentTaskForce(v6);
    if ( (CAITaskForce::Flags(v3) & 0x20000000) != 0 )
    {
      v4 = CAITaskForceClassWalk::CurrentTaskForce(v6);
      if ( CAITaskForce::Status(v4) != 10 )
        return 0;
    }
  }
  return 1;
}


// address=[0x12fba00]
// Decompiled from int __thiscall CAIAgentDarkTribeAttack::SetMissionBit(CAIDarkTribeSectorAgent *this, int a2)
void  CAIAgentDarkTribeAttack::SetMissionBit(enum T_AI_TASK_FORCE_CMD a2) {
  
  struct CAIDarkTribeSectorAI *v2; // eax
  int v3; // eax
  int result; // eax
  CAITaskForce *v5; // eax
  _BYTE v6[8]; // [esp+0h] [ebp-10h] BYREF
  CAIDarkTribeSectorAgent *v7; // [esp+8h] [ebp-8h]
  CAITaskForce *v8; // [esp+Ch] [ebp-4h]

  v7 = this;
  v2 = CAIDarkTribeSectorAgent::SectorAI(this);
  v3 = CAISectorAI::TaskForceGroup(v2);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v6, v3, 7);
  while ( 1 )
  {
    result = CAITaskForceClassWalk::NextTaskForce(v6, a2);
    if ( !(_BYTE)result )
      break;
    v5 = (CAITaskForce *)CAITaskForceClassWalk::CurrentTaskForce(v6);
    CAITaskForce::SetFlagBit(v5, 0x20000000u);
    v8 = (CAITaskForce *)CAITaskForceClassWalk::CurrentTaskForce(v6);
    if ( v8 )
      CAITaskForce::SetFlagBit(v8, 0x20000000u);
  }
  return result;
}


// address=[0x12fba70]
// Decompiled from BOOL __thiscall CAIAgentDarkTribeAttack::RemoveMissionBit(CAIAgentDarkTribeAttack *this)
void  CAIAgentDarkTribeAttack::RemoveMissionBit(void) {
  
  struct CAIDarkTribeSectorAI *v1; // eax
  int v2; // eax
  BOOL result; // eax
  CAITaskForce *v4; // eax
  int v5; // eax
  _BYTE v6[8]; // [esp+0h] [ebp-10h] BYREF
  CAIAgentDarkTribeAttack *v7; // [esp+8h] [ebp-8h]
  CAITaskForce *v8; // [esp+Ch] [ebp-4h]

  v7 = this;
  v1 = CAIDarkTribeSectorAgent::SectorAI(this);
  v2 = CAISectorAI::TaskForceGroup(v1);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v6, v2, 7);
  while ( 1 )
  {
    result = CAITaskForceClassWalk::NextTaskForce((CAITaskForceClassWalk *)v6);
    if ( !result )
      break;
    v4 = (CAITaskForce *)CAITaskForceClassWalk::CurrentTaskForce(v6);
    CAITaskForce::ClearFlagBit(v4, 0x20000000u);
    v5 = CAITaskForceClassWalk::CurrentTaskForce(v6);
    v8 = (CAITaskForce *)CAITaskForce::AssociatedTaskForce(v5);
    if ( v8 )
      CAITaskForce::ClearFlagBit(v8, 0x20000000u);
  }
  return result;
}


// address=[0x3e8dd50]
// [Decompilation failed for static class CAIConfigInt CAIAgentDarkTribeAttack::s_iMaxSoldiersPerTaskForce]

