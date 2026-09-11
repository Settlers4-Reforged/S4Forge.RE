#include "CAIAgentEvalDefence.h"

// Definitions for class CAIAgentEvalDefence

// address=[0x13045a0]
// Decompiled from CAIAgentEvalDefence *__thiscall CAIAgentEvalDefence::CAIAgentEvalDefence(CAIAgentEvalDefence *this)
 CAIAgentEvalDefence::CAIAgentEvalDefence(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent((CAINormalSectorAgent *)this, "defence evaluation");
  *(_DWORD *)this = &CAIAgentEvalDefence::_vftable_;
  *((_DWORD *)this + 10) = 0;
  return this;
}


// address=[0x13045d0]
// Decompiled from unsigned int __thiscall CAIAgentEvalDefence::Execute(CAINormalSectorAgent *this, unsigned int a2, unsigned int a3)
unsigned int  CAIAgentEvalDefence::Execute(unsigned int a2, unsigned int a3) {
  
  CAIScheduler **v3; // eax

  v3 = (CAIScheduler **)CAINormalSectorAgent::SectorAI(this);
  CAINormalSectorAI::EvaluateNextOwnMilitaryBuilding(v3);
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1304600]
// Decompiled from int __thiscall CAIAgentEvalDefence::Load(CAIAgent *this, struct IS4Chunk *a2)
void  CAIAgentEvalDefence::Load(class IS4Chunk & a2) {
  
  ((void (__thiscall *)(struct IS4Chunk *, int))a2->LoadSignature)(a2, -1516285952);
  ((void (__thiscall *)(struct IS4Chunk *, int, int))a2->LoadUnsigned32)(a2, 1, 1);
  CAIAgent::Load(this, a2);
  ((void (__thiscall *)(struct IS4Chunk *, int))a2->LoadSignature)(a2, -1516285950);
  *((_DWORD *)this + 10) = a2->LoadUnsigned32_(a2);
  return ((int (__thiscall *)(struct IS4Chunk *, int))a2->LoadSignature)(a2, -1516285951);
}


// address=[0x1304680]
// Decompiled from int __thiscall CAIAgentEvalDefence::Save(CAIAgent *this, struct IS4Chunk *a2)
void  CAIAgentEvalDefence::Save(class IS4Chunk & a2) {
  
  ((void (__thiscall *)(struct IS4Chunk *, int))a2->SaveSignature)(a2, -1516285952);
  ((void (__thiscall *)(struct IS4Chunk *, int))a2->SaveUnsigned32)(a2, 1);
  CAIAgent::Save(this, a2);
  ((void (__thiscall *)(struct IS4Chunk *, int))a2->SaveSignature)(a2, -1516285950);
  ((void (__thiscall *)(struct IS4Chunk *, _DWORD))a2->SaveUnsigned32)(a2, *((_DWORD *)this + 10));
  return ((int (__thiscall *)(struct IS4Chunk *, int))a2->SaveSignature)(a2, -1516285951);
}


// address=[0x1306280]
// Decompiled from void __thiscall CAIAgentEvalDefence::~CAIAgentEvalDefence(CAIScheduler **this)
 CAIAgentEvalDefence::~CAIAgentEvalDefence(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


// address=[0x1309520]
// Decompiled from int __thiscall CAIAgentEvalDefence::EvaluationCounter(CAIAgentEvalDefence *this)
int  CAIAgentEvalDefence::EvaluationCounter(void)const {
  
  return *((_DWORD *)this + 10);
}


