#include "CAIAgentDarkTribeSquadManager.h"

// Definitions for class CAIAgentDarkTribeSquadManager

// address=[0x1302430]
// Decompiled from unsigned int __thiscall CAIAgentDarkTribeSquadManager::Execute(  CAIAgentDarkTribeSquadManager *this,  unsigned int a2,  unsigned int a3)
unsigned int  CAIAgentDarkTribeSquadManager::Execute(unsigned int,unsigned int) {
  
  struct CAIDarkTribeSectorAI *v3; // eax
  struct CAIDarkTribeSectorAI *v4; // eax
  struct CAIDarkTribeSectorAI *v5; // eax
  struct CAIDarkTribeSectorAI *v6; // eax
  int v7; // eax
  struct CAIDarkTribeSectorAI *v8; // eax
  _DWORD *v9; // eax
  struct CAIDarkTribeSectorAI *v10; // eax
  _DWORD *v11; // eax
  struct CAIDarkTribeSectorAI *v12; // eax
  CAITaskForceGroup *v13; // eax
  struct CAIDarkTribeSectorAI *v14; // eax
  struct CAIDarkTribeSectorAI *v15; // eax
  struct CAIDarkTribeSectorAI *v16; // eax
  struct CAIDarkTribeSectorAI *v17; // eax
  int v18; // eax
  struct CAIDarkTribeSectorAI *v19; // eax
  struct CAIDarkTribeSectorAI *v20; // eax
  struct CAIDarkTribeSectorAI *v21; // eax
  pairNode *v22; // eax
  int v23; // eax
  CAIPlayerScriptVars *v24; // eax
  struct CAIDarkTribeSectorAI *v25; // eax
  int v26; // eax
  unsigned int v27; // esi
  CAIDarkTribeSectorAI *v28; // eax
  int v29; // eax
  int v31; // [esp-Ch] [ebp-84h]
  int v32; // [esp-Ch] [ebp-84h]
  CDockState *TaskForceGroupMemberOfSameClass; // [esp+4h] [ebp-74h]
  int v34; // [esp+8h] [ebp-70h] BYREF
  int v35; // [esp+Ch] [ebp-6Ch] BYREF
  int v36; // [esp+10h] [ebp-68h]
  int v37; // [esp+14h] [ebp-64h]
  int v38; // [esp+18h] [ebp-60h]
  int v39; // [esp+1Ch] [ebp-5Ch]
  int v40; // [esp+20h] [ebp-58h]
  int v41; // [esp+24h] [ebp-54h]
  int v42; // [esp+28h] [ebp-50h]
  int v43; // [esp+2Ch] [ebp-4Ch] BYREF
  int v44; // [esp+30h] [ebp-48h] BYREF
  int v45; // [esp+34h] [ebp-44h]
  int Entity; // [esp+38h] [ebp-40h]
  int v47; // [esp+3Ch] [ebp-3Ch]
  int v48; // [esp+40h] [ebp-38h]
  pairNode *v49; // [esp+44h] [ebp-34h]
  pairNode *v50; // [esp+48h] [ebp-30h]
  int v51; // [esp+4Ch] [ebp-2Ch]
  pairNode *TaskForce; // [esp+50h] [ebp-28h]
  int v53; // [esp+54h] [ebp-24h]
  int v54; // [esp+58h] [ebp-20h]
  int v55; // [esp+5Ch] [ebp-1Ch]
  pairNode *v56; // [esp+60h] [ebp-18h]
  int v57; // [esp+64h] [ebp-14h]
  pairNode *i; // [esp+68h] [ebp-10h]
  int v59; // [esp+6Ch] [ebp-Ch]
  CDockState *j; // [esp+70h] [ebp-8h]
  CAIDarkTribeSectorAgent *v61; // [esp+74h] [ebp-4h]

  v61 = this;
  if ( *((_DWORD *)this + 10) == 1 )
  {
    CAIAgentDarkTribeSquadManager::CheckSettlers(v61, 29, 2);
  }
  else
  {
    switch ( *((_DWORD *)v61 + 10) )
    {
      case 3:
        CAIAgentDarkTribeSquadManager::CheckSettlers(v61, 32, 3);
        break;
      case 5:
        CAIAgentDarkTribeSquadManager::CheckSettlers(v61, 52, 7);
        break;
      case 6:
        CAIAgentDarkTribeSquadManager::CheckSettlers(v61, 54, 4);
        break;
    }
  }
  *((_DWORD *)v61 + 10) = ((unsigned __int8)*((_DWORD *)v61 + 10) + 1) & 7;
  CAIAgentDarkTribeSquadManager::SimpleSquadManagement(v61, 7, 11, 3);
  CAIAgentDarkTribeSquadManager::SimpleSquadManagement(v61, 4, 12, 3);
  CAIAgentDarkTribeSquadManager::SimpleSquadManagement(v61, 9, 13, 1);
  v3 = CAIDarkTribeSectorAgent::SectorAI(v61);
  CAISectorAI::DeleteEmptyTaskForces(v3, 2);
  v4 = CAIDarkTribeSectorAgent::SectorAI(v61);
  v50 = (pairNode *)CAISectorAI::Reservoir(v4, 2);
  v5 = CAIDarkTribeSectorAgent::SectorAI(v61);
  v49 = (pairNode *)CAISectorAI::Reservoir(v5, 3);
  if ( !v50 && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 496, "pReservoirSwordsman != 0") == 1 )
    __debugbreak();
  if ( !v49 && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 497, "pReservoirBowman != 0") == 1 )
    __debugbreak();
  v42 = CAITaskForce::NumberOfEntities(v50);
  v41 = CAITaskForce::NumberOfEntities(v49);
  v40 = v41 + v42;
  if ( v41 + v42 > 0 )
  {
    v57 = 0;
    v55 = 0;
    v54 = 0;
    v53 = 0;
    v48 = 0x10000;
    v47 = 0;
    v56 = 0;
    v6 = CAIDarkTribeSectorAgent::SectorAI(v61);
    v7 = CAISectorAI::TaskForceGroup(v6);
    for ( i = (pairNode *)CAITaskForceGroup::FirstTaskForce(v7, 2);
          i;
          i = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i) )
    {
      v59 = CAITaskForce::NumberOfEntities(i);
      if ( v59 <= 0 && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 524, "iSquadSize > 0") == 1 )
        __debugbreak();
      ++v57;
      v55 += v59;
      if ( CAITaskForce::Type(i) == 2 )
      {
        ++v54;
        v53 += v57;
        if ( v59 < v48 )
        {
          v48 = v59;
          v56 = i;
        }
        if ( v59 > v47 )
          v47 = v59;
      }
    }
    v8 = CAIDarkTribeSectorAgent::SectorAI(v61);
    v9 = (_DWORD *)CAISectorAI::TaskForceGroup(v8);
    v38 = CAITaskForceGroup::NumberOfTaskForcesOfClass(v9, 6);
    v10 = CAIDarkTribeSectorAgent::SectorAI(v61);
    v11 = (_DWORD *)CAISectorAI::TaskForceGroup(v10);
    v39 = CAITaskForceGroup::NumberOfTaskForcesOfClass(v11, 7);
    v37 = v38 + v39 + 1;
    if ( v57 >= v37 )
    {
      if ( v56 )
      {
        Entity = CAITaskForce::FirstEntity(v56);
        if ( !Entity && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 582, "pEntityInfo != 0") == 1 )
          __debugbreak();
        v18 = CAIEntityInfo::EntityId(Entity);
        v45 = IAIEnvironment::EntityPackedPosition(v18);
        v19 = CAIDarkTribeSectorAgent::SectorAI(v61);
        CAISectorAI::RecruitFightersForSquad(v19, v56, v45, 2, 10);
        v20 = CAIDarkTribeSectorAgent::SectorAI(v61);
        CAISectorAI::RecruitFightersForSquad(v20, v56, v45, 3, 5);
      }
    }
    else
    {
      v12 = CAIDarkTribeSectorAgent::SectorAI(v61);
      v13 = (CAITaskForceGroup *)CAISectorAI::TaskForceGroup(v12);
      TaskForce = CAITaskForceGroup::CreateTaskForce(v13, 2);
      v14 = CAIDarkTribeSectorAgent::SectorAI(v61);
      v31 = CAISectorAI::BasePackedXY(v14);
      v15 = CAIDarkTribeSectorAgent::SectorAI(v61);
      CAISectorAI::RecruitFightersForSquad(v15, TaskForce, v31, 2, 10);
      v16 = CAIDarkTribeSectorAgent::SectorAI(v61);
      v32 = CAISectorAI::BasePackedXY(v16);
      v17 = CAIDarkTribeSectorAgent::SectorAI(v61);
      CAISectorAI::RecruitFightersForSquad(v17, TaskForce, v32, 3, 5);
      v51 = CAITaskForce::NumberOfEntities(TaskForce);
      if ( v51 <= 0 && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 568, "iNewSquadSize > 0") == 1 )
        __debugbreak();
      ++v57;
      v55 += v51;
      ++v54;
      v53 += v51;
    }
  }
  v21 = CAIDarkTribeSectorAgent::SectorAI(v61);
  v22 = (pairNode *)CAISectorAI::PlayerAI(v21);
  v23 = CAIPlayerAI::PlayerId(v22);
  v24 = (CAIPlayerScriptVars *)CAIPlayersScriptVars::operator[](v23);
  v36 = CAIPlayerScriptVars::Flags(v24);
  if ( (v36 & 0x40000000) != 0 )
    return CAIAgent::ExecuteResult(0, 0);
  CAIAgentDarkTribeSquadManager::AssociateSquads(v61, 6);
  CAIAgentDarkTribeSquadManager::AssociateSquads(v61, 7);
  v25 = CAIDarkTribeSectorAgent::SectorAI(v61);
  v26 = CAISectorAI::TaskForceGroup(v25);
  for ( j = (CDockState *)CAITaskForceGroup::FirstTaskForce(v26, 2); j; j = TaskForceGroupMemberOfSameClass )
  {
    TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(j);
    if ( !CAITaskForce::AssociatedTaskForce(j) )
    {
      v27 = CAITaskForce::CmdTimeStamp(j);
      if ( v27 + IAIEnvironment::Rand() % 0x200u + 500 <= a2 && CAITaskForce::GetPositionOfFirstEntity(j, &v35, &v34) )
      {
        v43 = v35;
        v44 = v34;
        v28 = CAIDarkTribeSectorAgent::SectorAI(v61);
        if ( CAIDarkTribeSectorAI::FindMushroomFarm(v28, &v43, &v44, 15, 50) )
        {
          v29 = IAIEnvironment::PackXYFast(v43, v44);
          (*(void (__thiscall **)(CDockState *, int, int, _DWORD))(*(_DWORD *)j + 32))(j, 1, v29, 0);
        }
      }
    }
  }
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1322ea0]
// Decompiled from CAIAgentDarkTribeSquadManager *__thiscall CAIAgentDarkTribeSquadManager::CAIAgentDarkTribeSquadManager(  CAIAgentDarkTribeSquadManager *this)
 CAIAgentDarkTribeSquadManager::CAIAgentDarkTribeSquadManager(void) {
  
  CAIDarkTribeSectorAgent::CAIDarkTribeSectorAgent(this, "dark tribe squad manager");
  *(_DWORD *)this = &CAIAgentDarkTribeSquadManager::_vftable_;
  *((_DWORD *)this + 10) = 0;
  return this;
}


// address=[0x1322fa0]
// Decompiled from void __thiscall CAIAgentDarkTribeSquadManager::~CAIAgentDarkTribeSquadManager(CAIAgentDarkTribeSquadManager *this)
 CAIAgentDarkTribeSquadManager::~CAIAgentDarkTribeSquadManager(void) {
  
  CAIDarkTribeSectorAgent::~CAIDarkTribeSectorAgent(this);
}


// address=[0x1302940]
// Decompiled from struct CAITaskForce *__thiscall CAIAgentDarkTribeSquadManager::SimpleSquadManagement(  CAIDarkTribeSectorAgent *this,  int a2,  int a3,  int a4)
void  CAIAgentDarkTribeSquadManager::SimpleSquadManagement(enum T_AI_WARRIOR_TYPE a2, enum T_AI_TASK_FORCE_TYPE a3, int a4) {
  
  struct CAIDarkTribeSectorAI *v4; // eax
  struct CAIDarkTribeSectorAI *v5; // eax
  struct CAIDarkTribeSectorAI *v6; // eax
  int v7; // eax
  struct CAITaskForce *result; // eax
  struct CAIDarkTribeSectorAI *v9; // eax
  CAITaskForceGroup *v10; // eax
  int v11; // [esp+0h] [ebp-34h]
  int v12; // [esp+4h] [ebp-30h]
  int v13; // [esp+Ch] [ebp-28h]
  int v14; // [esp+10h] [ebp-24h]
  int v15; // [esp+20h] [ebp-14h]
  int v16; // [esp+24h] [ebp-10h]
  int Entity; // [esp+2Ch] [ebp-8h]
  CUserToolsManager *TaskForce; // [esp+30h] [ebp-4h]

  if ( (a2 != 7 || a3 != 11)
    && (a2 != 4 || a3 != 12)
    && (a2 != 9 || a3 != 13)
    && BBSupportDbgReport(
         2,
         "AI\\AI_AgentsDark.cpp",
         292,
         "((_tReservoir == AI_WARRIOR_TYPE_MISC_UNIT) && (_tTaskForceType == AI_TASK_FORCE_TYPE_DARK_GARDENERS)) || ((_tR"
         "eservoir == AI_WARRIOR_TYPE_FIGHTER_UNIQUE) && (_tTaskForceType == AI_TASK_FORCE_TYPE_SHAMANS)) || ((_tReservoi"
         "r == AI_WARRIOR_TYPE_VEHICLE_MISC) && (_tTaskForceType == AI_TASK_FORCE_TYPE_MANAKOPTERS))") == 1 )
  {
    __debugbreak();
  }
  if ( a4 <= 0 && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 294, "_iScheduledTaskForceSize > 0") == 1 )
    __debugbreak();
  v15 = CAITaskForces::TaskForceClass(a3);
  v4 = CAIDarkTribeSectorAgent::SectorAI(this);
  CAISectorAI::DeleteEmptyTaskForces(v4, v15);
  v5 = CAIDarkTribeSectorAgent::SectorAI(this);
  v16 = CAISectorAI::Reservoir(v5, a2);
  if ( !v16 && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 302, "pReservoir != 0") == 1 )
    __debugbreak();
  Entity = CAITaskForce::FirstEntity(v16);
  v6 = CAIDarkTribeSectorAgent::SectorAI(this);
  v7 = CAISectorAI::TaskForceGroup(v6);
  result = (struct CAITaskForce *)CAITaskForceGroup::FirstTaskForce(v7, v15);
  TaskForce = result;
LABEL_16:
  while ( TaskForce != 0 && Entity != 0 )
  {
    while ( TaskForce )
    {
      if ( CAITaskForce::Type(TaskForce) == a3
        && CAITaskForce::NumberOfEntities(TaskForce) < a4
        && (CAITaskForce::Flags(TaskForce) & 0x20000000) == 0 )
      {
        v13 = CAIEntityInfo::Next(Entity);
        v14 = CAIEntityInfo::EntityId(Entity);
        result = (struct CAITaskForce *)CAITaskForce::AddEntity(TaskForce, v14, 0);
        Entity = v13;
        goto LABEL_16;
      }
      result = CAITaskForce::NextTaskForceGroupMemberOfSameClass(TaskForce);
      TaskForce = result;
    }
  }
  while ( Entity )
  {
    v11 = CAIEntityInfo::Next(Entity);
    if ( !TaskForce || CAITaskForce::NumberOfEntities(TaskForce) >= a4 )
    {
      v9 = CAIDarkTribeSectorAgent::SectorAI(this);
      v10 = (CAITaskForceGroup *)CAISectorAI::TaskForceGroup(v9);
      TaskForce = CAITaskForceGroup::CreateTaskForce(v10, a3);
    }
    if ( !TaskForce && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 349, "pTaskForce != 0") == 1 )
      __debugbreak();
    if ( CAITaskForce::NumberOfEntities(TaskForce) >= a4
      && BBSupportDbgReport(
           2,
           "AI\\AI_AgentsDark.cpp",
           350,
           "pTaskForce->NumberOfEntities() < _iScheduledTaskForceSize") == 1 )
    {
      __debugbreak();
    }
    v12 = CAIEntityInfo::EntityId(Entity);
    result = (struct CAITaskForce *)CAITaskForce::AddEntity(TaskForce, v12, 0);
    Entity = v11;
  }
  return result;
}


// address=[0x1302bb0]
// Decompiled from struct CAITaskForce *__thiscall CAIAgentDarkTribeSquadManager::AssociateSquads(CAIDarkTribeSectorAgent *this, int a2)
void  CAIAgentDarkTribeSquadManager::AssociateSquads(enum T_AI_TASK_FORCE_CLASS a2) {
  
  struct CAIDarkTribeSectorAI *v2; // eax
  int v3; // eax
  struct CAIDarkTribeSectorAI *v4; // eax
  int v5; // eax
  struct CAITaskForce *result; // eax
  CUserToolsManager *TaskForce; // [esp+Ch] [ebp-Ch]
  CAITaskForce *i; // [esp+10h] [ebp-8h]

  v2 = CAIDarkTribeSectorAgent::SectorAI(this);
  v3 = CAISectorAI::TaskForceGroup(v2);
  TaskForce = (CUserToolsManager *)CAITaskForceGroup::FirstTaskForce(v3, a2);
  v4 = CAIDarkTribeSectorAgent::SectorAI(this);
  v5 = CAISectorAI::TaskForceGroup(v4);
  result = (struct CAITaskForce *)CAITaskForceGroup::FirstTaskForce(v5, 2);
  for ( i = result;
        ;
        result = (struct CAITaskForce *)(*(int (__thiscall **)(CAITaskForce *, int, int, _DWORD))(*(_DWORD *)i + 32))(
                                          i,
                                          6,
                                          -1,
                                          0) )
  {
    while ( TaskForce )
    {
      if ( !CAITaskForce::AssociatedTaskForce(TaskForce) )
      {
        result = (struct CAITaskForce *)(CAITaskForce::Flags(TaskForce) & 0x20000000);
        if ( !result )
          break;
      }
      result = CAITaskForce::NextTaskForceGroupMemberOfSameClass(TaskForce);
      TaskForce = result;
    }
    while ( i )
    {
      result = (struct CAITaskForce *)CAITaskForce::AssociatedTaskForce(i);
      if ( !result )
        break;
      result = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
      i = result;
    }
    if ( i == 0 || TaskForce == 0 )
      break;
    CAITaskForce::SetAssociatedTaskForce(i, TaskForce);
  }
  return result;
}


// address=[0x1302cb0]
// Decompiled from void *__thiscall CAIAgentDarkTribeSquadManager::CheckSettlers(CAIDarkTribeSectorAgent *this, int a2, int a3)
void  CAIAgentDarkTribeSquadManager::CheckSettlers(int a2, enum T_AI_WARRIOR_TYPE a3) {
  
  struct CAIDarkTribeSectorAI *v3; // eax
  pairNode *v4; // eax
  struct CAIDarkTribeSectorAI *v5; // eax
  void *result; // eax
  _BYTE v7[12]; // [esp+0h] [ebp-2Ch] BYREF
  int v8; // [esp+Ch] [ebp-20h]
  int v9; // [esp+10h] [ebp-1Ch]
  int EntityInfo; // [esp+14h] [ebp-18h]
  int v11; // [esp+18h] [ebp-14h]
  CAIDarkTribeSectorAgent *v12; // [esp+1Ch] [ebp-10h]
  void *v13; // [esp+20h] [ebp-Ch]
  int v14; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  v12 = this;
  v3 = CAIDarkTribeSectorAgent::SectorAI(this);
  v4 = (pairNode *)CAISectorAI::PlayerAI(v3);
  v8 = CAIPlayerAI::PlayerId(v4);
  v5 = CAIDarkTribeSectorAgent::SectorAI(v12);
  result = (void *)CAISectorAI::Reservoir(v5, a3);
  v13 = result;
  if ( !result )
  {
    result = (void *)BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 421, "pReservoir != 0");
    if ( result == (void *)1 )
      __debugbreak();
  }
  if ( !v13 )
    return result;
  COneSettlerTypeIterator::COneSettlerTypeIterator((COneSettlerTypeIterator *)v7, v8, a2);
  v14 = 0;
  v11 = 0;
  v9 = 0;
  result = (void *)COneSettlerTypeIterator::FirstSettler((COneSettlerTypeIterator *)v7);
  for ( i = (int)result; i; i = (int)result )
  {
    if ( ++v14 >= 10000 )
      break;
    ++v11;
    EntityInfo = IAIEnvironment::EntityGetEntityInfo(i, 0);
    if ( !EntityInfo || !CAIEntityInfo::TaskForce(EntityInfo) )
    {
      ++v9;
      CAITaskForce::AddEntity(v13, i, 0);
    }
    result = (void *)COneSettlerTypeIterator::NextSettler((COneSettlerTypeIterator *)v7);
  }
  return result;
}


