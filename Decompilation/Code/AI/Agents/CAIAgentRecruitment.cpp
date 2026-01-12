#include "CAIAgentRecruitment.h"

// Definitions for class CAIAgentRecruitment

// address=[0x1305510]
// Decompiled from CAIAgentRecruitment *__thiscall CAIAgentRecruitment::CAIAgentRecruitment(CAIAgentRecruitment *this)

 CAIAgentRecruitment::CAIAgentRecruitment(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, "recruitment");
  *(_DWORD *)this = &CAIAgentRecruitment::_vftable_;
  *((_DWORD *)this + 10) = 0;
  return this;
}


// address=[0x1305540]
// Decompiled from unsigned int __thiscall CAIAgentRecruitment::Execute(CAIAgentRecruitment *this, unsigned int a2, unsigned int a3)

unsigned int  CAIAgentRecruitment::Execute(unsigned int,unsigned int) {
  
  struct CAINormalSectorAI *v3; // eax
  pairNode *v4; // eax
  struct CAINormalSectorAI *v5; // eax
  CAIPlayerAI *v6; // eax
  CAISectorAI *v7; // eax
  void *v8; // eax
  int v10; // [esp+0h] [ebp-28h]
  int v11; // [esp+4h] [ebp-24h]
  int v12; // [esp+8h] [ebp-20h]
  int v14; // [esp+1Ch] [ebp-Ch]
  int FirstBuildingId; // [esp+20h] [ebp-8h]
  bool v16; // [esp+27h] [ebp-1h]

  v3 = CAINormalSectorAgent::SectorAI(this);
  v4 = (pairNode *)CAISectorAI::PlayerAI(v3);
  v14 = CAIPlayerAI::PlayerId(v4);
  v5 = CAINormalSectorAgent::SectorAI(this);
  v6 = (CAIPlayerAI *)CAISectorAI::PlayerAI(v5);
  v10 = CAIPlayerAI::Race(v6);
  v7 = CAINormalSectorAgent::SectorAI(this);
  v12 = CAISectorAI::SectorId(v7);
  v8 = (void *)CAIPlayersScriptVars::operator[](v14);
  v11 = CAIPlayerScriptVars::DifficultyLevel(v8);
  FirstBuildingId = IAIEnvironment::BuildingGetFirstBuildingId(v14, 24);
  v16 = (IAIEnvironment::Rand() & 1) != 0;
  while ( FirstBuildingId > 0 )
  {
    if ( IAIEnvironment::BuildingIsReadyAndInSector(FirstBuildingId, v12) )
    {
      IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, -1, 0);
      IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 29, 12);
      IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 32, 12);
      IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 44, 12);
      if ( v11 != 1 )
      {
        if ( v16 )
        {
          IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 30, 2);
          IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 33, 8);
          IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 34, 8);
        }
        else
        {
          IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 30, 8);
          IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 31, 8);
          IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 33, 2);
        }
        switch ( v10 )
        {
          case 0:
            if ( *((int *)this + 10) > 0 )
            {
              IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 35, 1);
              IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 36, 1);
              IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 37, 1);
            }
            break;
          case 1:
            IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 38, 12);
            IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 39, 4);
            break;
          case 2:
            IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 41, 12);
            IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 42, 4);
            break;
          case 4:
            IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 61, 12);
            IAIEnvironment::EventSendSettlerProductionMsg(v14, FirstBuildingId, 62, 4);
            break;
          default:
            break;
        }
      }
      v16 = !v16;
    }
    FirstBuildingId = IAIEnvironment::BuildingGetNextBuildingOfSameType(FirstBuildingId);
  }
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x13062e0]
// Decompiled from void __thiscall CAIAgentRecruitment::~CAIAgentRecruitment(CAIAgentRecruitment *this)

 CAIAgentRecruitment::~CAIAgentRecruitment(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


// address=[0x1309670]
// Decompiled from CAIAgentRecruitment *__thiscall CAIAgentRecruitment::SetUniqueFighterRecruitment(CAIAgentRecruitment *this, int a2)

void  CAIAgentRecruitment::SetUniqueFighterRecruitment(int) {
  
  CAIAgentRecruitment *result; // eax

  result = this;
  *((_DWORD *)this + 10) = a2;
  return result;
}


