#include "CAIAgentEvalOffence.h"

// Definitions for class CAIAgentEvalOffence

// address=[0x1304700]
// Decompiled from unsigned int __thiscall CAIAgentEvalOffence::Execute(CAIAgentEvalOffence *this, unsigned int a2, unsigned int a3)

unsigned int  CAIAgentEvalOffence::Execute(unsigned int,unsigned int) {
  
  CAINormalSectorAI *v3; // eax

  v3 = CAINormalSectorAgent::SectorAI(this);
  CAINormalSectorAI::EvaluateNextEnemyMilitaryBuilding(v3);
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1325a40]
// Decompiled from CAIAgentEvalOffence *__thiscall CAIAgentEvalOffence::CAIAgentEvalOffence(CAIAgentEvalOffence *this)

 CAIAgentEvalOffence::CAIAgentEvalOffence(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, "offence evaluation");
  *(_DWORD *)this = &CAIAgentEvalOffence::_vftable_;
  return this;
}


// address=[0x1325c30]
// Decompiled from void __thiscall CAIAgentEvalOffence::~CAIAgentEvalOffence(CAIAgentEvalOffence *this)

 CAIAgentEvalOffence::~CAIAgentEvalOffence(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


