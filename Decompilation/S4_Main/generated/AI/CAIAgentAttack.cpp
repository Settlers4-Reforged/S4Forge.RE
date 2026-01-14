#include "all_headers.h"

// Definitions for class CAIAgentAttack

// address=[0x12ffa00]
// Decompiled from CAIAgentAttack *__thiscall CAIAgentAttack::CAIAgentAttack(CAIAgentAttack *this)
 CAIAgentAttack::CAIAgentAttack(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, "attack");
  *(_DWORD *)this = &CAIAgentAttack::_vftable_;
  CAIAgentAttack::ResetAttackState(this);
  return this;
}


// address=[0x12ffa70]
// Decompiled from unsigned int __thiscall CAIAgentAttack::Execute(CAIAgentAttack *this, unsigned int a2, unsigned int a3)
unsigned int  CAIAgentAttack::Execute(unsigned int,unsigned int) {
  
  struct CAINormalSectorAI *v3; // eax
  pairNode *v4; // eax
  unsigned int v5; // esi
  unsigned int v6; // eax
  __int16 v8; // ax
  unsigned int v9; // [esp+Ch] [ebp-2Ch]
  int v10; // [esp+10h] [ebp-28h]
  int v11; // [esp+14h] [ebp-24h]
  int v12; // [esp+1Ch] [ebp-1Ch]
  int v13; // [esp+20h] [ebp-18h]
  unsigned int v14; // [esp+24h] [ebp-14h]
  int v15; // [esp+30h] [ebp-8h]

  v3 = CAINormalSectorAgent::SectorAI(this);
  v4 = (pairNode *)CAISectorAI::PlayerAI(v3);
  v15 = CAIPlayerAI::PlayerId(v4);
  switch ( *((_DWORD *)this + 10) )
  {
    case 0:
      CAIPlayersScriptVars::operator[](v15);
      v12 = CAIPlayerScriptVars::operator[](0);
      if ( v12 <= 0 )
        return CAIAgent::ExecuteResult(0, 0);
      CAIPlayersScriptVars::operator[](v15);
      v10 = CAIPlayerScriptVars::operator[](1);
      v9 = IAIEnvironment::MinutesToTicks(v10);
      v14 = IAIEnvironment::TickCounter();
      if ( v14 <= *((_DWORD *)this + 13) || v14 <= v9 )
        return CAIAgent::ExecuteResult(0, 0);
      if ( (unsigned int)IAIEnvironment::Rand() < *((_DWORD *)this + 14)
        && ((v5 = IAIEnvironment::Rand(),
             CAIPlayersScriptVars::operator[](v15),
             v6 = CAIPlayerScriptVars::operator[](2),
             v5 >= CRandom16::PercentValue(v6))
          ? (v13 = 2)
          : (v13 = 1),
            (v13 == 1 || v12 > 1)
         && CAIAgentAttack::CheckStrengthAndFindAnyTarget(this, 0, v13)
         && CAIAgentAttack::OrderSquadsToSneakUpPosition(this, v13 == 1)) )
      {
        *((_DWORD *)this + 10) = 1;
        return CAIAgent::ExecuteResult(0, 0);
      }
      else
      {
        if ( *((_DWORD *)this + 14) < CRandom16::PercentValue(0x10u) )
          *((_DWORD *)this + 14) += CRandom16::PercentValue(2u);
        v8 = IAIEnvironment::Rand();
        return CAIAgent::ExecuteResult((v8 & 0x100) + 512, 0);
      }
    case 1:
      if ( !CAIAgentAttack::CheckCurrentTarget(this, 1) )
        goto LABEL_23;
      v11 = CAIAgentAttack::CheckIfSneakUpPositionIsReached(this);
      if ( !v11 )
        goto LABEL_23;
      if ( v11 > 0 )
        *((_DWORD *)this + 10) = 3;
      return CAIAgent::ExecuteResult(0, 0);
    case 2:
      CAIAgentAttack::CheckCurrentTarget(this, 1);
      if ( (int)CAIAgentAttack::CheckSquadTargets(this) > 0 )
        return CAIAgent::ExecuteResult(0, 0);
      CAIAgentAttack::OrderSquadsHome(this, 4);
      CAIAgentAttack::ResetAttackState(this);
      return CAIAgent::ExecuteResult(0, 0);
    case 3:
      if ( CAIAgentAttack::CheckCurrentTarget(this, 1) && (int)CAIAgentAttack::OrderSquadsToAttack(this) > 0 )
      {
        *((_DWORD *)this + 10) = 2;
      }
      else
      {
LABEL_23:
        CAIAgentAttack::OrderSquadsHome(this, 3);
        CAIAgentAttack::ResetAttackState(this);
      }
      return CAIAgent::ExecuteResult(0, 0);
    default:
      if ( BBSupportDbgReportF(
             1,
             "AI\\AI_AgentsAttack.cpp",
             783,
             "CAIAgentAttack::Execute(): Invalid state %i!",
             *((_DWORD *)this + 10)) == 1 )
        __debugbreak();
      CAIAgentAttack::ResetAttackState(this);
      return CAIAgent::ExecuteResult(0, 0);
  }
}


// address=[0x12ffd40]
// Decompiled from int __thiscall CAIAgentAttack::Load(CAIAgentAttack *this, struct IS4Chunk *a2)
void  CAIAgentAttack::Load(class IS4Chunk &) {
  
  CAIAgentAttack::ResetAttackState(this);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516290048);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  CAIAgent::Load(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516290046);
  *((_DWORD *)this + 10) = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 3);
  *((_DWORD *)this + 11) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 12) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 13) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 14) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 15) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 16) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 17) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 18) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  *((_DWORD *)this + 19) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516290047);
}


// address=[0x12ffe70]
// Decompiled from int __thiscall CAIAgentAttack::Save(CAIAgentAttack *this, struct IS4Chunk *a2)
void  CAIAgentAttack::Save(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516290048);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  CAIAgent::Save(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516290046);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 10));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 11));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 12));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 13));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 14));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 15));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 16));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 17));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 18));
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 19));
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516290047);
}


// address=[0x12fffa0]
// Decompiled from int __thiscall CAIAgentAttack::SetOwnFighterNumberAndValue(CAIAgentAttack *this, int a2, int a3)
void  CAIAgentAttack::SetOwnFighterNumberAndValue(int,int) {
  
  int result; // eax

  *((_DWORD *)this + 11) = a2;
  result = a3;
  *((_DWORD *)this + 12) = a3;
  return result;
}


// address=[0x12fffc0]
// Decompiled from char __thiscall CAIAgentAttack::AttackNow(CAIAgentAttack *this, int a2, int a3)
bool  CAIAgentAttack::AttackNow(int,int) {
  
  struct CAINormalSectorAI *v4; // eax
  pairNode *v5; // eax
  int v6; // eax

  if ( a2 && !IAIEnvironment::AlliancesIsValidUsedPlayerId(a2) )
    return 0;
  if ( a2 )
  {
    v4 = CAINormalSectorAgent::SectorAI(this);
    v5 = (pairNode *)CAISectorAI::PlayerAI(v4);
    v6 = CAIPlayerAI::PlayerId(v5);
    if ( IAIEnvironment::AlliancesAllied(v6, a2) )
      return 0;
  }
  if ( *((_DWORD *)this + 10)
    || !CAIAgentAttack::CheckStrengthAndFindAnyTarget(this, a2, 0)
    || !CAIAgentAttack::OrderSquadsToSneakUpPosition(this, a3) )
  {
    return 0;
  }
  *((_DWORD *)this + 10) = 1;
  CAIAgent::UpdateScheduleTime(this, 0);
  return 1;
}


// address=[0x1301020]
// Decompiled from void __thiscall CAIAgentAttack::~CAIAgentAttack(CAIAgentAttack *this)
 CAIAgentAttack::~CAIAgentAttack(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


// address=[0x1300070]
// Decompiled from void __thiscall CAIAgentAttack::ResetAttackState(CAIAgentAttack *this)
void  CAIAgentAttack::ResetAttackState(void) {
  
  int v1; // esi

  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  v1 = IAIEnvironment::TickCounter();
  *((_DWORD *)this + 13) = v1 + (IAIEnvironment::Rand() & 0x7F) + 512;
  *((_DWORD *)this + 14) = CRandom16::PercentValue(2u);
  CAIAgentAttack::ResetAttackTarget(this);
}


// address=[0x13000d0]
// Decompiled from CAIAgentAttack *__thiscall CAIAgentAttack::ResetAttackTarget(CAIAgentAttack *this)
void  CAIAgentAttack::ResetAttackTarget(void) {
  
  CAIAgentAttack *result; // eax

  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 17) = 0;
  result = this;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  return result;
}


// address=[0x1300110]
// Decompiled from char __thiscall CAIAgentAttack::SetAttackTarget(CAIAgentAttack *this, int a2)
bool  CAIAgentAttack::SetAttackTarget(int) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  v3 = IAIEnvironment::EntityUniqueId(a2);
  v4 = IAIEnvironment::BuildingPackedEnsignPosition(a2);
  if ( v3 <= 0 || v4 <= 0 )
  {
    CAIAgentAttack::ResetAttackTarget(this);
    return 0;
  }
  else
  {
    *((_DWORD *)this + 15) = a2;
    *((_DWORD *)this + 16) = v3;
    *((_DWORD *)this + 17) = IAIEnvironment::EntityOwnerId(a2);
    *((_DWORD *)this + 18) = IAIEnvironment::UnpackXFast(v4);
    *((_DWORD *)this + 19) = IAIEnvironment::UnpackYFast(v4);
    return 1;
  }
}


// address=[0x13001b0]
// Decompiled from bool __thiscall CAIAgentAttack::CheckAttackPosition(int *this)
bool  CAIAgentAttack::CheckAttackPosition(void) {
  
  CAISectorAI *v1; // eax
  int v3; // [esp+0h] [ebp-Ch]
  bool NearestSectorPosition; // [esp+Bh] [ebp-1h]

  v1 = CAINormalSectorAgent::SectorAI((CAINormalSectorAgent *)this);
  v3 = CAISectorAI::SectorId(v1);
  NearestSectorPosition = IAIEnvironment::FindNearestSectorPosition(this + 18, this + 19, v3, 15);
  if ( NearestSectorPosition )
    return NearestSectorPosition;
  this[18] = 0;
  this[19] = 0;
  return NearestSectorPosition;
}


// address=[0x1300210]
// Decompiled from int __thiscall CAIAgentAttack::OrderSquadsToAttack(CAIAgentAttack *this)
int  CAIAgentAttack::OrderSquadsToAttack(void) {
  
  struct CAINormalSectorAI *v1; // eax
  int v2; // eax
  _BYTE v4[8]; // [esp+0h] [ebp-14h] BYREF
  int v5; // [esp+8h] [ebp-Ch]
  CAIAgentAttack *v6; // [esp+Ch] [ebp-8h]
  int v7; // [esp+10h] [ebp-4h]

  v6 = this;
  v7 = 0;
  v1 = CAINormalSectorAgent::SectorAI(this);
  v2 = CAISectorAI::TaskForceGroup(v1);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v4, v2, 2);
  while ( (unsigned __int8)CAITaskForceClassWalk::NextTaskForce(v4, 3) )
  {
    ++v7;
    v5 = CAITaskForceClassWalk::CurrentTaskForce(v4);
    (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)v5 + 32))(v5, 4, *((_DWORD *)v6 + 15), 0);
  }
  return v7;
}


// address=[0x1300280]
// Decompiled from int __thiscall CAIAgentAttack::OrderSquadsHome(CAINormalSectorAgent *this, int a2)
void  CAIAgentAttack::OrderSquadsHome(enum T_AI_TASK_FORCE_CMD) {
  
  struct CAINormalSectorAI *v2; // eax
  struct CAINormalSectorAI *v3; // eax
  int v4; // eax
  int result; // eax
  CAINormalSectorAI *v6; // eax
  struct CAITaskForce *v7; // [esp-4h] [ebp-14h]
  _BYTE v8[8]; // [esp+0h] [ebp-10h] BYREF
  int v9; // [esp+8h] [ebp-8h]
  CAINormalSectorAgent *v10; // [esp+Ch] [ebp-4h]

  v10 = this;
  v2 = CAINormalSectorAgent::SectorAI(this);
  v9 = CAISectorAI::BasePackedXY(v2);
  v3 = CAINormalSectorAgent::SectorAI(v10);
  v4 = CAISectorAI::TaskForceGroup(v3);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v8, v4, 2);
  while ( 1 )
  {
    result = CAITaskForceClassWalk::NextTaskForce(v8, a2);
    if ( !(_BYTE)result )
      break;
    v7 = (struct CAITaskForce *)CAITaskForceClassWalk::CurrentTaskForce(v8);
    v6 = CAINormalSectorAgent::SectorAI(v10);
    CAINormalSectorAI::MoveSquadHome(v6, v7);
  }
  return result;
}


// address=[0x13002f0]
// Decompiled from bool __stdcall CAIAgentAttack::CheckSquadTarget(CAITaskForce *a1)
bool  CAIAgentAttack::CheckSquadTarget(class CAITaskForce *) {
  
  int v2; // [esp+4h] [ebp-8h]
  int v3; // [esp+8h] [ebp-4h]

  v2 = CAITaskForce::GoalEntityId(a1);
  v3 = CAITaskForce::GoalUniqueId(a1);
  return IAIEnvironment::EntityIsAliveAndHasGivenUniqueId(v2, v3);
}


// address=[0x1300330]
// Decompiled from int __thiscall CAIAgentAttack::CheckIfSneakUpPositionIsReached(CAIAgentAttack *this)
int  CAIAgentAttack::CheckIfSneakUpPositionIsReached(void) {
  
  struct CAINormalSectorAI *v1; // eax
  int v2; // eax
  int v3; // eax
  _BYTE v5[8]; // [esp+0h] [ebp-10h] BYREF
  CAIAgentAttack *v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  v6 = this;
  v7 = 0;
  v1 = CAINormalSectorAgent::SectorAI(this);
  v2 = CAISectorAI::TaskForceGroup(v1);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v5, v2, 2);
  while ( (unsigned __int8)CAITaskForceClassWalk::NextTaskForce(v5, 3) )
  {
    ++v7;
    v3 = CAITaskForceClassWalk::CurrentTaskForce(v5);
    if ( CAITaskForce::Status(v3) == 2 )
      return -1;
  }
  return v7;
}


// address=[0x13003a0]
// Decompiled from bool __thiscall CAIAgentAttack::CheckCurrentTarget(CAIAgentAttack *this, bool a2)
bool  CAIAgentAttack::CheckCurrentTarget(bool) {
  
  struct CAINormalSectorAI *v2; // eax
  pairNode *v3; // eax
  int v4; // eax
  int v6; // [esp-4h] [ebp-10h]
  bool HasGivenUniqueId; // [esp+Bh] [ebp-1h]

  HasGivenUniqueId = IAIEnvironment::EntityIsAliveAndHasGivenUniqueId(*((_DWORD *)this + 15), *((_DWORD *)this + 16));
  if ( HasGivenUniqueId )
  {
    v6 = IAIEnvironment::EntityOwnerId(*((_DWORD *)this + 15));
    v2 = CAINormalSectorAgent::SectorAI(this);
    v3 = (pairNode *)CAISectorAI::PlayerAI(v2);
    v4 = CAIPlayerAI::PlayerId(v3);
    HasGivenUniqueId = !IAIEnvironment::AlliancesAllied(v4, v6);
  }
  if ( HasGivenUniqueId )
    return HasGivenUniqueId;
  if ( a2 )
    return CAIAgentAttack::CheckStrengthAndFindAnyTarget(this, *((_DWORD *)this + 17), 0);
  else
    CAIAgentAttack::ResetAttackTarget(this);
  return HasGivenUniqueId;
}


// address=[0x1300450]
// Decompiled from int __thiscall CAIAgentAttack::CheckSquadTargets(CAIAgentAttack *this)
int  CAIAgentAttack::CheckSquadTargets(void) {
  
  struct CAINormalSectorAI *v1; // eax
  pairNode *v2; // eax
  struct CAINormalSectorAI *v3; // eax
  int v4; // eax
  CAINormalSectorAI *v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  unsigned int v8; // eax
  CAINormalSectorAI *v9; // eax
  CUserToolsManager *v11; // [esp-4h] [ebp-38h]
  CUserToolsManager *v12; // [esp-4h] [ebp-38h]
  _BYTE v13[8]; // [esp+4h] [ebp-30h] BYREF
  int v14; // [esp+Ch] [ebp-28h] BYREF
  int v15[2]; // [esp+10h] [ebp-24h] BYREF
  int v16; // [esp+18h] [ebp-1Ch]
  unsigned int v17; // [esp+1Ch] [ebp-18h]
  int v18; // [esp+20h] [ebp-14h]
  int v19; // [esp+24h] [ebp-10h] BYREF
  CAIAgentAttack *v20; // [esp+28h] [ebp-Ch]
  CUserToolsManager *v21; // [esp+2Ch] [ebp-8h]
  bool PositionOfFirstEntity; // [esp+32h] [ebp-2h]
  char v23; // [esp+33h] [ebp-1h]

  v20 = this;
  v1 = CAINormalSectorAgent::SectorAI(this);
  v2 = (pairNode *)CAISectorAI::PlayerAI(v1);
  v15[1] = CAIPlayerAI::PlayerId(v2);
  v17 = IAIEnvironment::TickCounter();
  v3 = CAINormalSectorAgent::SectorAI(v20);
  v4 = CAISectorAI::TaskForceGroup(v3);
  CAITaskForceClassWalk::CAITaskForceClassWalk(v13, v4, 2);
  v18 = 0;
  while ( (unsigned __int8)CAITaskForceClassWalk::NextTaskForce(v13, 4) )
  {
    v21 = (CUserToolsManager *)CAITaskForceClassWalk::CurrentTaskForce(v13);
    v16 = (*(int (__thiscall **)(CUserToolsManager *, int))(*(_DWORD *)v21 + 16))(v21, 2);
    if ( v16 > 0 )
    {
      ++v18;
      PositionOfFirstEntity = CAITaskForce::GetPositionOfFirstEntity(v21, &v14, v15);
      if ( !PositionOfFirstEntity && BBSupportDbgReport(2, "AI\\AI_AgentsAttack.cpp", 619, "bGetPositionOk") == 1 )
        __debugbreak();
      v23 = 0;
      if ( CAITaskForce::Status(v21) == 2 )
      {
        v6 = CAITaskForce::CmdTimeStamp(v21);
        if ( v6 + IAIEnvironment::Rand() % 0x80u + 185 < v17 )
          v23 = 1;
      }
      else
      {
        v23 = 1;
      }
      if ( v23 )
      {
        v19 = 0;
        if ( !CAIAgentAttack::FindNearTarget(v20, v21, 32, &v19) )
          v19 = *((_DWORD *)v20 + 15);
        if ( v19 <= 0 )
        {
          v12 = v21;
          v9 = CAINormalSectorAgent::SectorAI(v20);
          CAINormalSectorAI::MoveSquadHome(v9, v12);
          --v18;
        }
        else if ( CAITaskForce::Command(v21) != 4
               || (v7 = CAITaskForce::CmdGoal(v21), v7 != v19)
               || ((unsigned int)&unk_4000000 & CAITaskForce::Flags(v21)) != 0
               || (v8 = CAITaskForce::CmdTimeStamp(v21), v17 >= v8 + 1000) )
        {
          (*(void (__thiscall **)(CUserToolsManager *, int, int, _DWORD))(*(_DWORD *)v21 + 32))(v21, 4, v19, 0);
        }
      }
    }
    else
    {
      v11 = v21;
      v5 = CAINormalSectorAgent::SectorAI(v20);
      CAINormalSectorAI::MoveSquadHome(v5, v11);
    }
  }
  return v18;
}


// address=[0x1300630]
// Decompiled from bool __fastcall CAIAgentAttack::FindNearTarget(CAIAgentAttack *this, int a2, struct CAITaskForce *a3, int a4, int *a5)
bool  CAIAgentAttack::FindNearTarget(class CAITaskForce *,int,int &) {
  
  int v6; // eax
  _DWORD v7[3]; // [esp+0h] [ebp-18h] BYREF
  int v8; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF

  v7[2] = this;
  *a5 = 0;
  if ( !CAITaskForce::GetPositionOfFirstEntity(a3, &v8, &v9) )
    return 0;
  v6 = CAITaskForce::OwnerId(a3);
  if ( !CScanner::FindNearestEnemyTowerInSector((struct SFindNearestResult *)v7, v8, v9, 32, v6) )
    return *a5 > 0;
  if ( v7[0] <= 0 && BBSupportDbgReport(2, "AI\\AI_AgentsAttack.cpp", 576, "sResult.m_iEntityId > 0") == 1 )
    __debugbreak();
  *a5 = v7[0];
  return *a5 > 0;
}


// address=[0x13006e0]
// Decompiled from char __thiscall CAIAgentAttack::CheckStrengthAndFindAnyTarget(CAIAgentAttack *this, int a2, int a3)
bool  CAIAgentAttack::CheckStrengthAndFindAnyTarget(int,int) {
  
  pairNode *v3; // eax
  CAIGoal *v4; // eax
  CAIGoal *v5; // eax
  int v7; // [esp+4h] [ebp-3Ch]
  int v8; // [esp+Ch] [ebp-34h]
  int v9; // [esp+10h] [ebp-30h]
  int v10; // [esp+14h] [ebp-2Ch]
  int v11; // [esp+18h] [ebp-28h]
  int v12; // [esp+1Ch] [ebp-24h]
  int v13; // [esp+20h] [ebp-20h]
  struct CAINormalSectorAI *v14; // [esp+24h] [ebp-1Ch]
  int v15; // [esp+28h] [ebp-18h]
  CAIGoalCache *v16; // [esp+2Ch] [ebp-14h]
  int v17; // [esp+30h] [ebp-10h]
  int v18; // [esp+34h] [ebp-Ch]
  int i; // [esp+3Ch] [ebp-4h]

  IMessageTracer::PushFormatedInts(
    g_pMsgTracer,
    "CAIAgentAttack::CheckStrengthAndFindAnyTarget(): TargetPlayerId %u, Mode %u",
    a2,
    a3);
  CAIAgentAttack::ResetAttackTarget(this);
  if ( !a3 || *((int *)this + 11) >= 15 )
  {
    v14 = CAINormalSectorAgent::SectorAI(this);
    v16 = (struct CAINormalSectorAI *)((char *)v14 + 1452);
    v10 = CAIGoalCache::NumberOfCachedGoals((struct CAINormalSectorAI *)((char *)v14 + 1452));
    if ( v10 > 0 )
    {
      v3 = (pairNode *)CAISectorAI::PlayerAI(v14);
      v12 = CAIPlayerAI::PlayerId(v3);
      v17 = IAIEnvironment::AlliancesPlayerAllyBits(v12);
      if ( a2 > 0 )
        v17 = ~IAIEnvironment::AlliancesPlayerBit(a2);
      v15 = *((_DWORD *)this + 12);
      if ( a3 > 0 )
      {
        if ( a3 == 1 )
          v13 = 3;
        else
          v13 = 4;
        CAIPlayersScriptVars::operator[](v12);
        v11 = CAIPlayerScriptVars::operator[](v13);
        if ( v11 > 0 )
          v15 = 100 * v15 / v11;
      }
      for ( i = 0; i < v10; ++i )
      {
        v4 = CAIGoalCache::Goal(v16, i);
        v18 = CAIGoal::EntityId(v4);
        v5 = CAIGoalCache::Goal(v16, i);
        v7 = CAIGoal::UniqueId(v5);
        if ( IAIEnvironment::EntityUniqueId(v18) == v7 )
        {
          v9 = IAIEnvironment::EntityOwnerId(v18);
          v8 = IAIEnvironment::AlliancesPlayerBit(v9);
          if ( (v17 & v8) == 0 )
          {
            if ( a3 > 0 && v15 <= dword_3E95220[22 * v9] )
            {
              v17 |= v8;
            }
            else if ( CAIAgentAttack::SetAttackTarget(this, v18) )
            {
              IMessageTracer::PushFormatedInts(
                g_pMsgTracer,
                "CAIAgentAttack::CheckStrengthAndFindAnyTarget(): Attack target %u",
                v18);
              return 1;
            }
          }
        }
      }
    }
  }
  IMessageTracer::PushStaticText(g_pMsgTracer, aCaiagentattack_2);
  return 0;
}


// address=[0x13008d0]
// Decompiled from bool __thiscall CAIAgentAttack::OrderSquadsToSneakUpPosition(CAIAgentAttack *this, int a2)
bool  CAIAgentAttack::OrderSquadsToSneakUpPosition(int) {
  
  CAITaskForce *v3; // [esp+0h] [ebp-1D8h] BYREF
  int *v5; // [esp+8h] [ebp-1D0h]
  CAITaskForce *TaskForceGroupMemberOfSameClass; // [esp+Ch] [ebp-1CCh]
  struct CAINormalSectorAI *v7; // [esp+10h] [ebp-1C8h]
  int v8; // [esp+18h] [ebp-1C0h]
  _DWORD *v9; // [esp+1Ch] [ebp-1BCh]
  int v10; // [esp+20h] [ebp-1B8h]
  CAINormalSectorAgent *v11; // [esp+24h] [ebp-1B4h]
  int v12; // [esp+28h] [ebp-1B0h]
  int v13; // [esp+2Ch] [ebp-1ACh]
  CAITaskForce *i; // [esp+30h] [ebp-1A8h]
  int v15; // [esp+34h] [ebp-1A4h]
  _BYTE v16[412]; // [esp+38h] [ebp-1A0h] BYREF

  v11 = this;
  v8 = IAIEnvironment::PackXYFast(*((_DWORD *)this + 18), *((_DWORD *)this + 19));
  if ( v8 <= 0 )
    return 0;
  v7 = CAINormalSectorAgent::SectorAI(v11);
  v9 = (_DWORD *)CAISectorAI::TaskForceGroup(v7);
  v10 = CAITaskForceGroup::NumberOfTaskForcesOfType(v9, 5);
  v15 = v10 - v10 / 5 - 1;
  if ( a2 <= 0 )
  {
    if ( a2 < 0 )
      v15 = IAIEnvironment::ClipMax(v15, a2 + v10);
  }
  else
  {
    v15 = IAIEnvironment::ClipMax(v15, a2);
  }
  if ( v15 <= 0 )
    return 0;
  if ( v15 > 50 )
    v15 = 50;
  TPriorityQueue<SSquadValue,51>::TPriorityQueue<SSquadValue,51>(v16);
  for ( i = (CAITaskForce *)CAITaskForceGroup::FirstTaskForce(v9, 2); i; i = TaskForceGroupMemberOfSameClass )
  {
    TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
    if ( CAITaskForce::Type(i) == 5 )
    {
      v3 = i;
      if ( (*(int (__thiscall **)(CAITaskForce *, int))(*(_DWORD *)i + 16))(i, 2) )
        TPriorityQueue<SSquadValue,51>::Push(&v3);
    }
  }
  v12 = 0;
  while ( !(unsigned __int8)TPriorityQueue<SSquadValue,51>::Empty(v16) && v12 < v15 )
  {
    v5 = (int *)TPriorityQueue<SSquadValue,51>::Top(v16);
    v13 = *v5;
    if ( v13 )
    {
      CAITaskForce::ChangeType(v13, 6);
      (*(void (__thiscall **)(int, int, int, _DWORD))(*(_DWORD *)v13 + 32))(v13, 3, v8, 0);
      ++v12;
    }
    TPriorityQueue<SSquadValue,51>::Pop(v16);
  }
  return v12 > 0;
}


