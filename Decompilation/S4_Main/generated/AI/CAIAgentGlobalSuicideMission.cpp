#include "CAIAgentGlobalSuicideMission.h"

// Definitions for class CAIAgentGlobalSuicideMission

// address=[0x1306b70]
// Decompiled from unsigned int __thiscall CAIAgentGlobalSuicideMission::Execute(  CAIAgentGlobalSuicideMission *this,  unsigned int a2,  unsigned int a3)
unsigned int  CAIAgentGlobalSuicideMission::Execute(unsigned int a2, unsigned int a3) {
  
  unsigned int v3; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  unsigned int v8; // eax
  int v9; // [esp+0h] [ebp-34h] BYREF
  int v10; // [esp+4h] [ebp-30h]
  int v11; // [esp+8h] [ebp-2Ch]
  int v12; // [esp+Ch] [ebp-28h] BYREF
  int v13; // [esp+10h] [ebp-24h] BYREF
  pairNode *v14; // [esp+14h] [ebp-20h]
  CAIAgent *v15; // [esp+18h] [ebp-1Ch]
  int v16; // [esp+1Ch] [ebp-18h]
  struct _Cnd_internal_imp_t *v17; // [esp+20h] [ebp-14h] BYREF
  struct _Mtx_internal_imp_t *v18; // [esp+24h] [ebp-10h] BYREF
  CUserToolsManager *v19; // [esp+28h] [ebp-Ch]
  int NearestBuildingInSector; // [esp+2Ch] [ebp-8h]
  bool v21; // [esp+31h] [ebp-3h]
  char v22; // [esp+32h] [ebp-2h]
  bool v23; // [esp+33h] [ebp-1h]

  v15 = this;
  v14 = (pairNode *)CAIAgentPlayerBase::PlayerAI(this);
  v19 = (pairNode *)((char *)v14 + 572);
  if ( CAITaskForce::NumberOfEntities((pairNode *)((char *)v14 + 572)) > 0 )
  {
    v22 = 0;
    CAITaskForce::GetPositionOfFirstEntity(v19, (int *)&v17, (int *)&v18);
    v11 = IAIEnvironment::WorldSectorId((int)v17, (int)v18);
    NearestBuildingInSector = 0;
    v16 = 0x4000;
    v23 = CAITaskForce::Command(v19) == 4 && CAITaskForce::IsGoalValid(v19, 1);
    v21 = v23;
    if ( v23 )
    {
      NearestBuildingInSector = CAITaskForce::CmdGoal(v19);
      if ( NearestBuildingInSector <= 0 && BBSupportDbgReport(2, "AI\\AI_AgentsPlayer.cpp", 113, "iGoalId > 0") == 1 )
        __debugbreak();
      if ( IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(NearestBuildingInSector, 12) )
      {
        IAIEnvironment::BuildingGetEnsignPosition(NearestBuildingInSector, &v12, &v13);
        v16 = IAIEnvironment::GridDistance(v12 - (_DWORD)v17, v13 - (_DWORD)v18);
      }
    }
    if ( v16 > 10 )
    {
      v5 = CAIPlayerAI::PlayerId(v14);
      if ( CScanner::FindNearestEnemyTowerInSector((struct SFindNearestResult *)&v9, v17, v18, 32, v5) )
      {
        if ( v9 <= 0 && BBSupportDbgReport(2, "AI\\AI_AgentsPlayer.cpp", 132, "sResult.m_iEntityId > 0") == 1 )
          __debugbreak();
        if ( !IAIEnvironment::EntityIsAliveAndOfGivenWarriorType(v9, 12)
          && BBSupportDbgReport(
               2,
               "AI\\AI_AgentsPlayer.cpp",
               133,
               "g_pAIEnv->EntityIsAliveAndOfGivenWarriorType(sResult.m_iEntityId, AI_WARRIOR_TYPE_TOWER_BUILDING)") == 1 )
        {
          __debugbreak();
        }
        if ( v10 < v16 - 10 )
        {
          NearestBuildingInSector = v9;
          v16 = v10;
        }
      }
    }
    if ( NearestBuildingInSector <= 0 )
    {
      v22 = 1;
      NearestBuildingInSector = CAIAgentGlobalSuicideMission::FindNearestBuildingInSector(1, 46, v17, v18);
      if ( !NearestBuildingInSector )
      {
        NearestBuildingInSector = CAIAgentGlobalSuicideMission::FindNearestBuildingInSector(1, 47, v17, v18);
        if ( !NearestBuildingInSector )
          NearestBuildingInSector = CAIAgentGlobalSuicideMission::FindNearestBuildingInSector(1, 48, v17, v18);
      }
    }
    if ( NearestBuildingInSector <= 0 )
    {
      v7 = IAIEnvironment::PackXYFast(v17, v18);
      (*(void (__thiscall **)(CUserToolsManager *, int, int, _DWORD))(*(_DWORD *)v19 + 32))(v19, 1, v7, 0);
    }
    else if ( CAITaskForce::Command(v19) != 4
           || (v6 = CAITaskForce::CmdGoal(v19), v6 != NearestBuildingInSector)
           || ((unsigned int)&unk_4000000 & CAITaskForce::Flags(v19)) != 0
           || a2 >= CAITaskForce::CmdTimeStamp(v19) + 1000 )
    {
      (*(void (__thiscall **)(CUserToolsManager *, int, int, _DWORD))(*(_DWORD *)v19 + 32))(
        v19,
        4,
        NearestBuildingInSector,
        0);
    }
    if ( v22 )
    {
      v8 = CAIAgent::DefaultExecutionDelay(v15);
      return CAIAgent::ExecuteResult(10 * v8, 0x200u);
    }
    else
    {
      return CAIAgent::ExecuteResult(0, 0);
    }
  }
  else
  {
    v3 = CAIAgent::DefaultExecutionDelay(v15);
    return CAIAgent::ExecuteResult(10 * v3, 1u);
  }
}


// address=[0x1306e40]
// Decompiled from int __thiscall CAIAgentGlobalSuicideMission::Load(CAIAgentGlobalSuicideMission *this, struct IS4Chunk *a2)
void  CAIAgentGlobalSuicideMission::Load(class IS4Chunk & a2) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516273664);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  CAIAgent::Load(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516273662);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516273663);
}


// address=[0x1306ea0]
// Decompiled from int __thiscall CAIAgentGlobalSuicideMission::Save(CAIAgentGlobalSuicideMission *this, struct IS4Chunk *a2)
void  CAIAgentGlobalSuicideMission::Save(class IS4Chunk & a2) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516273664);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  CAIAgent::Save(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516273662);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516273663);
}


// address=[0x1319160]
// Decompiled from CAIAgentGlobalSuicideMission *__thiscall CAIAgentGlobalSuicideMission::CAIAgentGlobalSuicideMission(  CAIAgentGlobalSuicideMission *this,  const char *a2)
 CAIAgentGlobalSuicideMission::CAIAgentGlobalSuicideMission(char const * a2) {
  
  CAIAgentPlayerBase::CAIAgentPlayerBase(this, a2);
  *(_DWORD *)this = &CAIAgentGlobalSuicideMission::_vftable_;
  return this;
}


// address=[0x1319260]
// Decompiled from void __thiscall CAIAgentGlobalSuicideMission::~CAIAgentGlobalSuicideMission(CAIAgentGlobalSuicideMission *this)
 CAIAgentGlobalSuicideMission::~CAIAgentGlobalSuicideMission(void) {
  
  CAIAgentPlayerBase::~CAIAgentPlayerBase(this);
}


// address=[0x1306f00]
// Decompiled from int __cdecl CAIAgentGlobalSuicideMission::FindNearestBuildingInSector(  int a1,  int a2,  struct _Cnd_internal_imp_t *a3,  struct _Mtx_internal_imp_t *a4)
int __cdecl CAIAgentGlobalSuicideMission::FindNearestBuildingInSector(int a1, int a2, int a3, int a4) {
  
  int v5; // [esp+0h] [ebp-24h]
  int v6; // [esp+4h] [ebp-20h]
  int v7; // [esp+8h] [ebp-1Ch]
  int v8; // [esp+Ch] [ebp-18h]
  int v9; // [esp+10h] [ebp-14h]
  struct _Cnd_internal_imp_t *v10; // [esp+14h] [ebp-10h]
  struct _Mtx_internal_imp_t *v11; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  _DWORD *v13; // [esp+20h] [ebp-4h]

  v7 = 0;
  v8 = 0x4000;
  v5 = IAIEnvironment::WorldSectorId((int)a3, (int)a4);
  for ( i = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, a1, a2); i; i = IAnimatedEntity::Next(v13) )
  {
    v13 = (_DWORD *)CBuildingMgr::operator[](i);
    v10 = (struct _Cnd_internal_imp_t *)CBuilding::EnsignX(v13);
    v11 = (struct _Mtx_internal_imp_t *)CBuilding::EnsignY(v13);
    v6 = IAIEnvironment::WorldSectorId((int)v10, (int)v11);
    if ( IEntity::FlagBits(v13, (EntityFlag)((char *)&loc_1FFFFFF + 1)) && v6 == v5 )
    {
      v9 = IAIEnvironment::GridDistance(v10 - a3, v11 - a4);
      if ( v9 < v8 )
      {
        v7 = i;
        v8 = v9;
      }
    }
  }
  return v7;
}


