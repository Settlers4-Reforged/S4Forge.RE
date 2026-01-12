#include "CAIAgentSquads.h"

// Definitions for class CAIAgentSquads

// address=[0x13071b0]
// Decompiled from CAIAgentSquads *__thiscall CAIAgentSquads::CAIAgentSquads(CAIAgentSquads *this)
 CAIAgentSquads::CAIAgentSquads(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, "squad management");
  *(_DWORD *)this = &CAIAgentSquads::_vftable_;
  return this;
}


// address=[0x13071e0]
// Decompiled from unsigned int __thiscall CAIAgentSquads::Execute(CAIAgentSquads *this, unsigned int a2, unsigned int a3)
unsigned int  CAIAgentSquads::Execute(unsigned int,unsigned int) {
  
  pairNode *v3; // eax
  CAIGoal *v4; // eax
  CAIGoal *v5; // eax
  CAIGoal *v6; // eax
  CAIGoal *v7; // eax
  int v8; // eax
  _DWORD *v9; // eax
  int v10; // esi
  int v11; // eax
  pairNode *v12; // eax
  pairNode *v13; // eax
  pairNode *v14; // eax
  pairNode *v15; // eax
  CAITaskForceGroup *v17; // eax
  struct CAIDefenceGoal *v18; // eax
  int v19; // eax
  struct IEntity *v20; // eax
  int v21; // esi
  int v22; // esi
  int v23; // esi
  unsigned int v24; // esi
  struct CAIDefenceGoal *v25; // eax
  void *v26; // eax
  int v27; // eax
  struct CAINormalSectorAI *v28; // eax
  CAIPlayerAI *v29; // eax
  struct CAINormalSectorAI *v30; // eax
  int v31; // eax
  pairNode *v32; // eax
  int v33; // esi
  pairNode *v34; // eax
  int v35; // [esp-Ch] [ebp-5D0h]
  int v36; // [esp-8h] [ebp-5CCh]
  int v37; // [esp+28h] [ebp-59Ch]
  int v38; // [esp+2Ch] [ebp-598h]
  int v39; // [esp+30h] [ebp-594h]
  int v40; // [esp+38h] [ebp-58Ch]
  struct CAITaskForce *v41; // [esp+3Ch] [ebp-588h]
  int v42; // [esp+40h] [ebp-584h]
  int v43; // [esp+44h] [ebp-580h]
  int v44; // [esp+54h] [ebp-570h]
  struct CAITaskForce *TaskForceGroupMemberOfSameClass; // [esp+58h] [ebp-56Ch]
  char *v46; // [esp+74h] [ebp-550h]
  unsigned int v47; // [esp+78h] [ebp-54Ch]
  int v48; // [esp+80h] [ebp-544h]
  const int *v49; // [esp+88h] [ebp-53Ch]
  int Value; // [esp+8Ch] [ebp-538h]
  int v51; // [esp+90h] [ebp-534h]
  int v52; // [esp+98h] [ebp-52Ch]
  int v53; // [esp+9Ch] [ebp-528h]
  int v54; // [esp+A0h] [ebp-524h]
  int v55; // [esp+A8h] [ebp-51Ch]
  signed int v56; // [esp+B0h] [ebp-514h]
  signed int v57; // [esp+B4h] [ebp-510h]
  int v58; // [esp+B8h] [ebp-50Ch]
  int v59; // [esp+BCh] [ebp-508h]
  signed int v60; // [esp+C0h] [ebp-504h]
  int v61; // [esp+C4h] [ebp-500h]
  int v62; // [esp+C8h] [ebp-4FCh]
  _BYTE *v63; // [esp+E0h] [ebp-4E4h]
  int v64; // [esp+E4h] [ebp-4E0h]
  int v65; // [esp+E8h] [ebp-4DCh]
  int v66; // [esp+ECh] [ebp-4D8h]
  int v67; // [esp+F0h] [ebp-4D4h]
  int v68; // [esp+F4h] [ebp-4D0h]
  struct CAIDefenceGoal *v69; // [esp+F8h] [ebp-4CCh]
  int v70; // [esp+FCh] [ebp-4C8h]
  int v71; // [esp+104h] [ebp-4C0h]
  int v72; // [esp+108h] [ebp-4BCh]
  int v73; // [esp+10Ch] [ebp-4B8h]
  int v74; // [esp+110h] [ebp-4B4h]
  int v75; // [esp+114h] [ebp-4B0h]
  void *v76; // [esp+118h] [ebp-4ACh]
  int v77; // [esp+120h] [ebp-4A4h]
  int v78; // [esp+124h] [ebp-4A0h]
  int v79; // [esp+128h] [ebp-49Ch]
  struct CAITaskForce *TaskForce; // [esp+12Ch] [ebp-498h]
  int UnprotectedGoalIdx; // [esp+130h] [ebp-494h]
  int v82; // [esp+138h] [ebp-48Ch]
  int v83; // [esp+13Ch] [ebp-488h]
  int v84; // [esp+140h] [ebp-484h]
  int v85; // [esp+144h] [ebp-480h]
  int v86; // [esp+14Ch] [ebp-478h]
  int v87; // [esp+154h] [ebp-470h]
  int v88; // [esp+158h] [ebp-46Ch]
  int mm; // [esp+15Ch] [ebp-468h]
  int v90; // [esp+160h] [ebp-464h]
  struct CAIDefenceGoal *v91; // [esp+164h] [ebp-460h]
  int v92; // [esp+168h] [ebp-45Ch]
  struct CAIDefenceGoal *v93; // [esp+16Ch] [ebp-458h]
  CMFCToolBarButton *v94; // [esp+170h] [ebp-454h]
  int v95; // [esp+174h] [ebp-450h]
  int v96; // [esp+178h] [ebp-44Ch]
  int m; // [esp+17Ch] [ebp-448h]
  int i; // [esp+180h] [ebp-444h]
  int v99; // [esp+184h] [ebp-440h]
  int v100; // [esp+188h] [ebp-43Ch]
  CMFCToolBarButton *v101; // [esp+18Ch] [ebp-438h]
  int jj; // [esp+190h] [ebp-434h]
  int ii; // [esp+194h] [ebp-430h]
  struct CAIDefenceGoal *v104; // [esp+198h] [ebp-42Ch]
  struct CAITaskForce *v105; // [esp+19Ch] [ebp-428h]
  int j; // [esp+1A0h] [ebp-424h]
  int v108; // [esp+1A8h] [ebp-41Ch]
  int v109; // [esp+1ACh] [ebp-418h]
  int kk; // [esp+1B0h] [ebp-414h]
  int v111; // [esp+1B4h] [ebp-410h]
  int v112; // [esp+1B8h] [ebp-40Ch]
  int v113; // [esp+1B8h] [ebp-40Ch]
  int v114; // [esp+1BCh] [ebp-408h]
  int v115; // [esp+1C0h] [ebp-404h]
  int v116; // [esp+1C4h] [ebp-400h]
  unsigned int v117; // [esp+1C8h] [ebp-3FCh]
  int v118; // [esp+1CCh] [ebp-3F8h]
  int v119; // [esp+1D0h] [ebp-3F4h]
  int v120; // [esp+1D4h] [ebp-3F0h]
  int v121; // [esp+1D8h] [ebp-3ECh]
  pairNode *n; // [esp+1DCh] [ebp-3E8h]
  int v123; // [esp+1E0h] [ebp-3E4h]
  int v124; // [esp+1E4h] [ebp-3E0h]
  unsigned int v125; // [esp+1E8h] [ebp-3DCh]
  bool v126; // [esp+1EEh] [ebp-3D6h]
  bool v127; // [esp+1EFh] [ebp-3D5h]
  bool v128; // [esp+1F2h] [ebp-3D2h]
  bool v129; // [esp+1F3h] [ebp-3D1h]
  pairNode *k; // [esp+1F4h] [ebp-3D0h]
  struct CAINormalSectorAI *v131; // [esp+1F8h] [ebp-3CCh]
  _BYTE v132[964]; // [esp+1FCh] [ebp-3C8h] BYREF

  v131 = CAINormalSectorAgent::SectorAI(this);
  v3 = (pairNode *)CAISectorAI::PlayerAI(v131);
  v108 = CAIPlayerAI::PlayerId(v3);
  CAIGoalCache::DeleteInvalidGoals((struct CAINormalSectorAI *)((char *)v131 + 264));
  CAIGoalCache::DeleteInvalidGoals((struct CAINormalSectorAI *)((char *)v131 + 660));
  CAIDefenceGoals::CAIDefenceGoals((CAIDefenceGoals *)v132);
  v43 = CAIGoalCache::NumberOfCachedGoals((struct CAINormalSectorAI *)((char *)v131 + 264));
  for ( i = 0; i < v43; ++i )
  {
    v4 = CAIGoalCache::Goal((struct CAINormalSectorAI *)((char *)v131 + 264), i);
    v74 = CAIGoal::EntityId(v4);
    v5 = CAIGoalCache::Goal((struct CAINormalSectorAI *)((char *)v131 + 264), i);
    v75 = CAIGoal::Value(v5);
    v76 = IAIEnvironment::EntityGetEntityInfoTower(v74)[4];
    if ( (int)v76 > 0 || v75 > 0 )
      CAIDefenceGoals::Insert((CAIDefenceGoals *)v132, v74, 0x80000000, v75, v76);
  }
  for ( j = 0; j < CAIGoalCache::NumberOfCachedGoals((struct CAINormalSectorAI *)((char *)v131 + 660)); ++j )
  {
    v6 = CAIGoalCache::Goal((struct CAINormalSectorAI *)((char *)v131 + 660), j);
    v35 = CAIGoal::Value(v6);
    v7 = CAIGoalCache::Goal((struct CAINormalSectorAI *)((char *)v131 + 660), j);
    v8 = CAIGoal::EntityId(v7);
    CAIDefenceGoals::Insert((CAIDefenceGoals *)v132, v8, v35, 0x80000000, 0);
  }
  v9 = (_DWORD *)CAISectorAI::TaskForceGroup(v131);
  v65 = CAITaskForceGroup::NumberOfTaskForcesOfType(v9, 5);
  v10 = CStaticConfigVarInt::operator int(&unk_3E8DE18);
  v119 = v65 * CStaticConfigVarInt::operator int(&unk_3E8DE24) + v10;
  v116 = 0;
  v79 = 0;
  v70 = 0;
  v73 = 0;
  v71 = 999999;
  v82 = 0;
  v105 = 0;
  v123 = 0;
  v115 = 0;
  v85 = 0;
  v84 = 0;
  v83 = 0;
  v77 = 0;
  v11 = CAISectorAI::TaskForceGroup(v131);
  for ( k = (pairNode *)CAITaskForceGroup::FirstTaskForce(v11, 2); k; k = TaskForceGroupMemberOfSameClass )
  {
    TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(k);
    if ( CAITaskForce::Type(k) != 5 )
      continue;
    v120 = CAITaskForce::NumberOfEntities(k);
    if ( v120 <= 0 )
      goto LABEL_26;
    v88 = CAITaskForce::GoalEntityId(k);
    v86 = -1;
    if ( v88 > 0 )
      v86 = CAIDefenceGoals::SetFlagBitsId((CAIDefenceGoals *)v132, v88, 1);
    if ( v86 < 0 )
    {
      (*(void (__thiscall **)(pairNode *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)k + 32))(k, 0, 0, 0);
      CAISectorAI::MoveFightersToReservoir(v131, k);
      --v116;
LABEL_26:
      (*(void (__thiscall **)(pairNode *, int))(*(_DWORD *)k + 8))(k, 1);
      continue;
    }
    *((_DWORD *)CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, v86) + 4) = k;
    ++v116;
    v73 += v120;
    v85 += (*(int (__thiscall **)(pairNode *, int))(*(_DWORD *)k + 16))(k, 2);
    v84 += (*(int (__thiscall **)(pairNode *, int))(*(_DWORD *)k + 16))(k, 3);
    v83 += (*(int (__thiscall **)(pairNode *, int))(*(_DWORD *)k + 16))(k, 4);
    v72 = (*(int (__thiscall **)(pairNode *, int))(*(_DWORD *)k + 16))(k, 5);
    v77 += v72;
    if ( v72 <= 0 )
      ++v79;
    if ( v71 > v120 )
      v71 = v120;
    if ( v82 < v120 )
    {
      v105 = k;
      v82 = v120;
    }
    if ( v120 < v119 )
    {
      ++v115;
      v123 += v119 - v120;
    }
    v70 += v88 == 0;
  }
  v92 = CAIDefenceGoals::NumberOfGoals((CAIDefenceGoals *)v132);
  v111 = 0;
  v68 = 0;
  v90 = 0;
  for ( m = 0; m < v92; ++m )
  {
    v69 = CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, m);
    v127 = (*((_BYTE *)v69 + 2) & 1) == 0;
    v126 = *((_DWORD *)v69 + 3) > 0;
    v111 += v127;
    v68 += v126;
    v90 += v126 && v127;
  }
  v12 = (pairNode *)CAISectorAI::Reservoir(v131, 2);
  v67 = CAITaskForce::NumberOfEntities(v12);
  v13 = (pairNode *)CAISectorAI::Reservoir(v131, 3);
  v66 = CAITaskForce::NumberOfEntities(v13);
  v14 = (pairNode *)CAISectorAI::Reservoir(v131, 4);
  v44 = CAITaskForce::NumberOfEntities(v14);
  v15 = (pairNode *)CAISectorAI::Reservoir(v131, 5);
  v52 = CAITaskForce::NumberOfEntities(v15);
  v109 = v67 + v85;
  v100 = v66 + v84;
  v53 = v44 + v83;
  v124 = v66 + v67;
  if ( v66 + v67 < v119 && v82 > 2 * v119 && v111 > 0 && v105 )
  {
    CAISectorAI::MoveFightersToReservoir(v131, v105);
    (*(void (__thiscall **)(struct CAITaskForce *, int))(*(_DWORD *)v105 + 8))(v105, 1);
    return CAIAgent::ExecuteResult(5u, 0);
  }
  else
  {
    v96 = v119;
    if ( !v65 )
    {
      if ( v123 && BBSupportDbgReport(2, "AI\\AI_AgentsSquads.cpp", 404, "iTotalNumberOfInsufficientFighters == 0") == 1 )
        __debugbreak();
      if ( v124 > 0 )
      {
        if ( v119 > v124 )
          v64 = v66 + v67;
        else
          v64 = v119;
        v96 = v64;
      }
    }
    if ( v124 - v123 >= v96 && v111 > 0 )
    {
      v17 = (CAITaskForceGroup *)CAISectorAI::TaskForceGroup(v131);
      TaskForce = CAITaskForceGroup::CreateTaskForce(v17, 5);
      UnprotectedGoalIdx = CAIDefenceGoals::NextUnprotectedGoalIdx((CAIDefenceGoals *)v132, 0);
      v18 = CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, UnprotectedGoalIdx);
      (*(void (__thiscall **)(struct CAITaskForce *, int, _DWORD, _DWORD))(*(_DWORD *)TaskForce + 32))(
        TaskForce,
        2,
        *(unsigned __int16 *)v18,
        0);
      v123 += v119;
      ++v115;
      v63 = (char *)CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, UnprotectedGoalIdx) + 2;
      *v63 |= 2u;
      *((_DWORD *)CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, UnprotectedGoalIdx) + 4) = TaskForce;
    }
    if ( ((v124 > 0) & (v123 == 0) & (CAIAgentEvalDefence::EvaluationCounter((struct CAINormalSectorAI *)((char *)v131 + 2884)) >= 2)) != 0 )
    {
      v123 = v66 + v67;
      v115 = v116;
      v119 = 99999;
    }
    if ( v124 > 0 && v115 > 0 )
    {
      v95 = IAIEnvironment::ClipMin(v123, v124) / v115;
      if ( v95 > 0 )
      {
        if ( v95 > CStaticConfigVarInt::operator int(&unk_3E8DE30) )
          v95 = CStaticConfigVarInt::operator int(&unk_3E8DE30);
        v19 = CAISectorAI::TaskForceGroup(v131);
        for ( n = (pairNode *)CAITaskForceGroup::FirstTaskForce(v19, 2); n; n = v41 )
        {
          v41 = CAITaskForce::NextTaskForceGroupMemberOfSameClass(n);
          if ( CAITaskForce::Type(n) == 5 && CAITaskForce::NumberOfEntities(n) < v119 )
          {
            v62 = CAITaskForce::GoalEntityId(n);
            v20 = CMapObjectMgr::Entity(v62);
            v42 = IEntity::PackedXY(v20);
            CAISectorAI::AutoRecruitFightersForSquad(v131, n, v42, v95);
            (*(void (__thiscall **)(pairNode *, int, int, _DWORD))(*(_DWORD *)n + 32))(n, 2, v62, 0);
          }
        }
      }
    }
    v121 = -1;
    v114 = -1;
    if ( v90 <= 0 )
    {
      v58 = 0x7FFFFFFF;
      for ( ii = 0; ii < v92; ++ii )
      {
        v93 = CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, ii);
        if ( (*((_BYTE *)v93 + 2) & 3) != 0 )
        {
          v94 = (CMFCToolBarButton *)*((_DWORD *)v93 + 4);
          if ( !v94 && BBSupportDbgReport(2, "AI\\AI_AgentsSquads.cpp", 544, "pTaskForce != 0") == 1 )
            __debugbreak();
          if ( v94 )
          {
            if ( CAITaskForce::Status(v94) == 4 )
            {
              v21 = CAITaskForce::StatusTimeStamp(v94);
              if ( (unsigned int)(v21 - IAIEnvironment::TickCounter()) > 0x4B )
              {
                v22 = *((_DWORD *)v93 + 1) + *((_DWORD *)v93 + 2);
                v59 = (unsigned __int8)(IAIEnvironment::Rand() + v22);
                if ( v58 >= v59 )
                {
                  v58 = v59;
                  v121 = ii;
                }
              }
            }
          }
        }
      }
      if ( v121 >= 0 )
      {
        v40 = *(unsigned __int16 *)CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, v121);
        v38 = IAIEnvironment::EntityPackedPosition(v40);
        v56 = 0x80000000;
        for ( jj = 0; jj < v92; ++jj )
        {
          v91 = CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, jj);
          if ( (*((_BYTE *)v91 + 2) & 3) == 0 )
          {
            v39 = IAIEnvironment::EntityPackedPosition(*(unsigned __int16 *)v91);
            if ( (int)IAIEnvironment::GridDistancePackedXY(v38, v39) < 100 )
            {
              v23 = *((_DWORD *)v91 + 1) + *((_DWORD *)v91 + 2);
              v57 = (unsigned __int8)(IAIEnvironment::Rand() + v23);
              if ( v56 < v57 )
              {
                v56 = v57;
                v114 = jj;
              }
            }
          }
        }
      }
    }
    else
    {
      v61 = 0x7FFFFFFF;
      v60 = 0x80000000;
      for ( kk = 0; kk < v92; ++kk )
      {
        v104 = CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, kk);
        if ( (*((_BYTE *)v104 + 2) & 3) != 0 )
        {
          if ( v61 >= *((_DWORD *)v104 + 3) )
          {
            v61 = *((_DWORD *)v104 + 3);
            v121 = kk;
          }
        }
        else if ( v60 < *((_DWORD *)v104 + 2) )
        {
          v60 = *((_DWORD *)v104 + 2);
          v114 = kk;
        }
      }
    }
    if ( v121 >= 0 && v114 >= 0 && v121 != v114 )
    {
      v101 = (CMFCToolBarButton *)*((_DWORD *)CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, v121) + 4);
      if ( v101 )
      {
        v129 = v90 > 0;
        if ( v90 <= 0 )
        {
          v55 = CAITaskForce::Status(v101);
          if ( v55 != 2 )
          {
            if ( v55 == 4 )
            {
              v24 = CAITaskForce::StatusTimeStamp(v101) + 75;
              v129 = v24 < IAIEnvironment::TickCounter();
            }
            else
            {
              v129 = 1;
            }
          }
        }
        if ( v129 )
        {
          v37 = *((_DWORD *)CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, v121) + 3);
          if ( *((_DWORD *)CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, v114) + 3) >= 2 * v37 )
          {
            v25 = CAIDefenceGoals::Goal((CAIDefenceGoals *)v132, v114);
            (*(void (__thiscall **)(CMFCToolBarButton *, int, _DWORD, _DWORD))(*(_DWORD *)v101 + 32))(
              v101,
              2,
              *(unsigned __int16 *)v25,
              0);
          }
        }
      }
    }
    CAIAgentSquads::SimpleSquadManagement(this, 6, 8, 2);
    CAIAgentSquads::AssociateTaskForcesToSquads(this, 3);
    v99 = v52 + v77 + v53 + v100 + v109;
    v54 = 0;
    if ( v99 > 0 )
      v54 = (int)(float)((float)((float)dword_3E95228[22 * v108] * (float)dword_3E95224[22 * v108]) / (float)v99);
    CAIAgentAttack::SetOwnFighterNumberAndValue((struct CAINormalSectorAI *)((char *)v131 + 2804), v99, v54);
    CAIGoalCache::DeleteInvalidGoals((struct CAINormalSectorAI *)((char *)v131 + 1452));
    CAIGoalCache::DeleteInvalidGoals((struct CAINormalSectorAI *)((char *)v131 + 1056));
    CAIGoalCache::DeleteInvalidGoals((struct CAINormalSectorAI *)((char *)v131 + 1848));
    v118 = 0;
    v112 = v109 - 2 * v100;
    if ( v112 >= 0 )
    {
      if ( v112 <= 12 )
      {
        if ( v112 <= 6 )
          v125 = 12;
        else
          v125 = 4;
        v117 = 12;
      }
      else
      {
        v125 = 0;
        v117 = 16;
      }
    }
    else
    {
      v113 = 2 * v100 - v109;
      if ( v113 <= 12 )
      {
        v125 = 12;
        if ( v113 <= 6 )
          v117 = 12;
        else
          v117 = 4;
      }
      else
      {
        v125 = 16;
        v117 = 0;
      }
    }
    v26 = (void *)CAIPlayersScriptVars::operator[](v108);
    if ( CAIPlayerScriptVars::DifficultyLevel(v26) != 1 && v109 > 10 && v53 < (v100 + v109) / 8 )
      v118 = (IAIEnvironment::Rand() & 3) + 1;
    v47 = IAIEnvironment::Clip((v79 - v52) / 2, 0, 2);
    v51 = v100 + v109;
    v78 = j__abs(v109 - 2 * v100);
    if ( v109 > 15 && v100 > 10 && (v78 <= 30 || v51 > 120) && (v78 <= 45 || v51 > 240) && v78 <= 60 )
    {
      v128 = 0;
      Value = CAIPlayersScriptVars::GetValue(g_cAIPlayersScriptVars, v108, 5);
      if ( Value > 0 && v99 > Value )
      {
        v48 = CAIPlayersScriptVars::GetValue(g_cAIPlayersScriptVars, v108, 6);
        if ( v48 <= 0 )
        {
          v128 = 1;
        }
        else
        {
          v27 = IAIEnvironment::AlliancesAllianceId(v108);
          v49 = IAIEnvironment::AlliancesEnemyPlayerIds(v27);
          v87 = 0;
          for ( mm = 0; v49[mm]; ++mm )
          {
            v46 = (char *)&g_cAIPlayerEvaluations + 88 * v49[mm];
            v87 += *((_DWORD *)v46 + 4) + *((_DWORD *)v46 + 13);
          }
          v128 = v99 > v48 * v87 / 100;
        }
      }
      if ( v128 )
      {
        v125 = 0;
        v117 = 0;
        v118 = 0;
      }
    }
    v28 = CAINormalSectorAgent::SectorAI(this);
    v29 = (CAIPlayerAI *)CAISectorAI::PlayerAI(v28);
    if ( !CAIPlayerAI::Race(v29) )
    {
      v30 = CAINormalSectorAgent::SectorAI(this);
      CAIAgentRecruitment::SetUniqueFighterRecruitment((struct CAINormalSectorAI *)((char *)v30 + 3204), v118);
      if ( v118 > 0 )
      {
        v125 += v118;
        v118 = 0;
      }
    }
    v36 = CAIEvent::Pack(v118, v47);
    v31 = CAIEvent::Pack(v125, v117);
    CAINormalSectorAI::PostAIEventToAllEcoSectorAIs(v131, 30, v31, v36, 0);
    v32 = (pairNode *)CAISectorAI::Reservoir(v131, 2);
    v33 = CAITaskForce::NumberOfEntities(v32);
    v34 = (pairNode *)CAISectorAI::Reservoir(v131, 3);
    if ( CAITaskForce::NumberOfEntities(v34) + v33 <= 10 )
      return CAIAgent::ExecuteResult(0, 0);
    else
      return CAIAgent::ExecuteResult(0xAu, 0);
  }
}


// address=[0x1309360]
// Decompiled from void __thiscall CAIAgentSquads::~CAIAgentSquads(CAIAgentSquads *this)
 CAIAgentSquads::~CAIAgentSquads(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


// address=[0x13088d0]
// Decompiled from struct CAITaskForce *__thiscall CAIAgentSquads::SimpleSquadManagement(  CAINormalSectorAgent *this,  int a2,  int a3,  int a4)
void  CAIAgentSquads::SimpleSquadManagement(enum T_AI_WARRIOR_TYPE,enum T_AI_TASK_FORCE_TYPE,int) {
  
  struct CAINormalSectorAI *v4; // eax
  struct CAINormalSectorAI *v5; // eax
  struct CAINormalSectorAI *v6; // eax
  int v7; // eax
  struct CAITaskForce *result; // eax
  struct CAINormalSectorAI *v9; // eax
  CAITaskForceGroup *v10; // eax
  int v11; // [esp+0h] [ebp-38h]
  int v12; // [esp+4h] [ebp-34h]
  int v13; // [esp+Ch] [ebp-2Ch]
  int v14; // [esp+10h] [ebp-28h]
  int v15; // [esp+18h] [ebp-20h]
  int v16; // [esp+24h] [ebp-14h]
  int v17; // [esp+28h] [ebp-10h]
  int Entity; // [esp+30h] [ebp-8h]
  pairNode *TaskForce; // [esp+34h] [ebp-4h]

  if ( (a2 != 6 || a3 != 8)
    && BBSupportDbgReport(
         2,
         "AI\\AI_AgentsSquads.cpp",
         52,
         "((_tReservoir == AI_WARRIOR_TYPE_PRIEST) && (_tTaskForceType == AI_TASK_FORCE_TYPE_PRIESTS))") == 1 )
  {
    __debugbreak();
  }
  if ( a4 <= 0 && BBSupportDbgReport(2, "AI\\AI_AgentsSquads.cpp", 54, "_iScheduledTaskForceSize > 0") == 1 )
    __debugbreak();
  v16 = CAITaskForces::TaskForceClass(a3);
  v4 = CAINormalSectorAgent::SectorAI(this);
  CAISectorAI::DeleteEmptyTaskForces(v4, v16);
  v5 = CAINormalSectorAgent::SectorAI(this);
  v17 = CAISectorAI::Reservoir(v5, a2);
  if ( !v17 && BBSupportDbgReport(2, "AI\\AI_AgentsSquads.cpp", 62, "pReservoir != 0") == 1 )
    __debugbreak();
  Entity = CAITaskForce::FirstEntity(v17);
  v6 = CAINormalSectorAgent::SectorAI(this);
  v7 = CAISectorAI::TaskForceGroup(v6);
  result = (struct CAITaskForce *)CAITaskForceGroup::FirstTaskForce(v7, v16);
  TaskForce = result;
LABEL_12:
  while ( TaskForce != 0 && Entity != 0 )
  {
    while ( TaskForce )
    {
      if ( CAITaskForce::Type(TaskForce) == a3 && CAITaskForce::NumberOfEntities(TaskForce) < a4 )
      {
        v15 = CAITaskForce::AssociatedTaskForce(TaskForce);
        if ( !v15 || CAITaskForce::Type(v15) == 5 )
        {
          v13 = CAIEntityInfo::Next(Entity);
          v14 = CAIEntityInfo::EntityId(Entity);
          result = (struct CAITaskForce *)CAITaskForce::AddEntity(TaskForce, v14, 0);
          Entity = v13;
          goto LABEL_12;
        }
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
      v9 = CAINormalSectorAgent::SectorAI(this);
      v10 = (CAITaskForceGroup *)CAISectorAI::TaskForceGroup(v9);
      TaskForce = CAITaskForceGroup::CreateTaskForce(v10, a3);
    }
    if ( !TaskForce && BBSupportDbgReport(2, "AI\\AI_AgentsSquads.cpp", 109, "pTaskForce != 0") == 1 )
      __debugbreak();
    if ( CAITaskForce::NumberOfEntities(TaskForce) >= a4
      && BBSupportDbgReport(
           2,
           "AI\\AI_AgentsSquads.cpp",
           110,
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


// address=[0x1308b30]
// Decompiled from struct CAITaskForce *__thiscall CAIAgentSquads::AssociateTaskForcesToSquads(CAINormalSectorAgent *this, int a2)
void  CAIAgentSquads::AssociateTaskForcesToSquads(enum T_AI_TASK_FORCE_CLASS) {
  
  struct CAINormalSectorAI *v2; // eax
  int v3; // eax
  struct CAINormalSectorAI *v4; // eax
  int v5; // eax
  struct CAITaskForce *result; // eax
  CAITaskForce *v8; // [esp+Ch] [ebp-Ch]
  CAITaskForce *TaskForce; // [esp+10h] [ebp-8h]
  bool v10; // [esp+17h] [ebp-1h]

  v2 = CAINormalSectorAgent::SectorAI(this);
  v3 = CAISectorAI::TaskForceGroup(v2);
  TaskForce = (CAITaskForce *)CAITaskForceGroup::FirstTaskForce(v3, a2);
  v4 = CAINormalSectorAgent::SectorAI(this);
  v5 = CAISectorAI::TaskForceGroup(v4);
  result = (struct CAITaskForce *)CAITaskForceGroup::FirstTaskForce(v5, 2);
  v8 = result;
  do
  {
    while ( TaskForce )
    {
      result = (struct CAITaskForce *)CAITaskForce::AssociatedTaskForce(TaskForce);
      if ( !result )
        break;
      result = CAITaskForce::NextTaskForceGroupMemberOfSameClass(TaskForce);
      TaskForce = result;
    }
    while ( v8 )
    {
      if ( CAITaskForce::Type(v8) == 5 )
      {
        result = (struct CAITaskForce *)CAITaskForce::AssociatedTaskForce(v8);
        if ( !result )
          break;
      }
      result = CAITaskForce::NextTaskForceGroupMemberOfSameClass(v8);
      v8 = result;
    }
    v10 = v8 != 0 && TaskForce != 0;
    if ( v10 )
    {
      if ( CAITaskForce::AssociatedTaskForce(TaskForce)
        && BBSupportDbgReport(2, "AI\\AI_AgentsSquads.cpp", 159, "pTaskForce->AssociatedTaskForce() == 0") == 1 )
      {
        __debugbreak();
      }
      if ( CAITaskForce::AssociatedTaskForce(v8) )
      {
        if ( BBSupportDbgReport(2, "AI\\AI_AgentsSquads.cpp", 160, "pSquad->AssociatedTaskForce() == 0") == 1 )
          __debugbreak();
      }
      CAITaskForce::SetAssociatedTaskForce(TaskForce, v8);
      result = (struct CAITaskForce *)(*(int (__thiscall **)(CAITaskForce *, int, int, _DWORD))(*(_DWORD *)TaskForce + 32))(
                                        TaskForce,
                                        6,
                                        -1,
                                        0);
    }
  }
  while ( v10 );
  return result;
}


