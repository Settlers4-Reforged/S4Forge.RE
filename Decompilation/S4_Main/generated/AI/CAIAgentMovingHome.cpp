#include "CAIAgentMovingHome.h"

// Definitions for class CAIAgentMovingHome

// address=[0x1304050]
// Decompiled from unsigned int __thiscall CAIAgentMovingHome::Execute(CAIAgentMovingHome *this, unsigned int a2, unsigned int a3)
unsigned int  CAIAgentMovingHome::Execute(unsigned int,unsigned int) {
  
  struct CAINormalSectorAI *v3; // eax
  _DWORD *v4; // eax
  unsigned int v5; // eax
  struct CAINormalSectorAI *v7; // eax
  int v8; // eax
  struct CAINormalSectorAI *v9; // eax
  struct _iobuf *v10; // eax
  int v11; // eax
  struct _iobuf *v12; // eax
  int v13; // eax
  CAINormalSectorAI *v14; // eax
  struct CAITaskForce *TaskForceGroupMemberOfSameClass; // [esp+0h] [ebp-3Ch]
  int v16; // [esp+Ch] [ebp-30h]
  int v17; // [esp+14h] [ebp-28h]
  int v18; // [esp+24h] [ebp-18h]
  pairNode *j; // [esp+30h] [ebp-Ch]
  pairNode *i; // [esp+34h] [ebp-8h]
  char v22; // [esp+3Bh] [ebp-1h]

  v3 = CAINormalSectorAgent::SectorAI(this);
  v4 = (_DWORD *)CAISectorAI::TaskForceGroup(v3);
  if ( CAITaskForceGroup::NumberOfTaskForcesOfType(v4, 3) )
  {
    v7 = CAINormalSectorAgent::SectorAI(this);
    v8 = CAISectorAI::TaskForceGroup(v7);
    for ( i = (pairNode *)CAITaskForceGroup::FirstTaskForce(v8, 2); i; i = TaskForceGroupMemberOfSameClass )
    {
      TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
      if ( CAITaskForce::Type(i) == 3 )
      {
        if ( CAITaskForce::NumberOfEntities(i) )
        {
          v9 = CAINormalSectorAgent::SectorAI(this);
          v10 = (struct _iobuf *)CAISectorAI::BasePackedXY(v9);
          IAIEnvironment::WorldEcoSectorIdPackedXY(v10);
          v18 = v11;
          if ( v11 <= 0 && BBSupportDbgReport(2, "AI\\AI_AgentsNormal.cpp", 1323, "iHomeEcoSectorId > 0") == 1 )
            __debugbreak();
          v22 = 1;
          for ( j = (pairNode *)CAITaskForce::LastEntity(i); j; j = (pairNode *)v16 )
          {
            v16 = CAIEntityInfo::Prev(j);
            v17 = CAIEntityInfo::EntityId(j);
            v12 = (struct _iobuf *)IAIEnvironment::EntityPackedPosition(v17);
            IAIEnvironment::WorldEcoSectorIdPackedXY(v12);
            if ( v13 != v18 )
            {
              (*(void (__thiscall **)(pairNode *, pairNode *, int))(*(_DWORD *)i + 20))(i, j, 2);
              v22 = 0;
              break;
            }
          }
          if ( v22 )
          {
            CAITaskForce::ChangeType(i, 5);
            (*(void (__thiscall **)(pairNode *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)i + 32))(i, 0, 0, 0);
          }
          else
          {
            v14 = CAINormalSectorAgent::SectorAI(this);
            CAINormalSectorAI::MoveSquadHome(v14, i);
          }
        }
        else
        {
          (*(void (__thiscall **)(pairNode *, int))(*(_DWORD *)i + 8))(i, 1);
        }
      }
    }
    return CAIAgent::ExecuteResult(0, 0);
  }
  else
  {
    v5 = CAIAgent::DefaultExecutionDelay(this);
    return CAIAgent::ExecuteResult(10 * v5, 1u);
  }
}


// address=[0x1325ad0]
// Decompiled from CAIAgentMovingHome *__thiscall CAIAgentMovingHome::CAIAgentMovingHome(CAIAgentMovingHome *this)
 CAIAgentMovingHome::CAIAgentMovingHome(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, "moving home");
  *(_DWORD *)this = &CAIAgentMovingHome::_vftable_;
  return this;
}


// address=[0x1325c90]
// Decompiled from void __thiscall CAIAgentMovingHome::~CAIAgentMovingHome(CAIAgentMovingHome *this)
 CAIAgentMovingHome::~CAIAgentMovingHome(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


