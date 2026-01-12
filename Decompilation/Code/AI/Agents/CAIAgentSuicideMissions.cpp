#include "CAIAgentSuicideMissions.h"

// Definitions for class CAIAgentSuicideMissions

// address=[0x1303ee0]
// Decompiled from unsigned int __thiscall CAIAgentSuicideMissions::Execute(
        CAIAgentSuicideMissions *this,
        unsigned int a2,
        unsigned int a3)

unsigned int  CAIAgentSuicideMissions::Execute(unsigned int,unsigned int) {
  
  struct CAINormalSectorAI *v3; // eax
  _DWORD *v4; // eax
  unsigned int v5; // eax
  struct CAINormalSectorAI *v7; // eax
  int v8; // eax
  CAINormalSectorAI *v9; // eax
  struct CAITaskForce *TaskForceGroupMemberOfSameClass; // [esp+0h] [ebp-28h]
  int TargetForSuicideMission; // [esp+1Ch] [ebp-Ch]
  CUserToolsManager *i; // [esp+24h] [ebp-4h]

  v3 = CAINormalSectorAgent::SectorAI(this);
  v4 = (_DWORD *)CAISectorAI::TaskForceGroup(v3);
  if ( CAITaskForceGroup::NumberOfTaskForcesOfType(v4, 4) )
  {
    v7 = CAINormalSectorAgent::SectorAI(this);
    v8 = CAISectorAI::TaskForceGroup(v7);
    for ( i = (CUserToolsManager *)CAITaskForceGroup::FirstTaskForce(v8, 2); i; i = TaskForceGroupMemberOfSameClass )
    {
      TaskForceGroupMemberOfSameClass = CAITaskForce::NextTaskForceGroupMemberOfSameClass(i);
      if ( CAITaskForce::Type(i) == 4 )
      {
        if ( CAITaskForce::NumberOfEntities(i) )
        {
          CAINormalSectorAgent::SectorAI(this);
          TargetForSuicideMission = CAINormalSectorAI::FindTargetForSuicideMission(i);
          if ( TargetForSuicideMission <= 0 )
          {
            v9 = CAINormalSectorAgent::SectorAI(this);
            CAINormalSectorAI::MoveSquadHome(v9, i);
          }
          else if ( CAITaskForce::Command(i) != 4
                 || CAITaskForce::CmdGoal(i) != TargetForSuicideMission
                 || ((unsigned int)&unk_4000000 & CAITaskForce::Flags(i)) != 0
                 || a2 >= CAITaskForce::CmdTimeStamp(i) + 1000 )
          {
            (*(void (__thiscall **)(CUserToolsManager *, int, int, _DWORD))(*(_DWORD *)i + 32))(
              i,
              4,
              TargetForSuicideMission,
              0);
          }
        }
        else
        {
          (*(void (__thiscall **)(CUserToolsManager *, int))(*(_DWORD *)i + 8))(i, 1);
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


// address=[0x1325b00]
// Decompiled from CAIAgentSuicideMissions *__thiscall CAIAgentSuicideMissions::CAIAgentSuicideMissions(CAIAgentSuicideMissions *this)

 CAIAgentSuicideMissions::CAIAgentSuicideMissions(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, string__26);
  *(_DWORD *)this = &CAIAgentSuicideMissions::_vftable_;
  return this;
}


// address=[0x1325cb0]
// Decompiled from void __thiscall CAIAgentSuicideMissions::~CAIAgentSuicideMissions(CAIAgentSuicideMissions *this)

 CAIAgentSuicideMissions::~CAIAgentSuicideMissions(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


