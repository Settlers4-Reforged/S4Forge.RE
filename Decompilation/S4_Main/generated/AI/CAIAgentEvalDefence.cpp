#include "all_headers.h"

// Definitions for class CAIAgentEvalDefence

// address=[0x13045a0]
// Decompiled from CAIAgentEvalDefence *__thiscall CAIAgentEvalDefence::CAIAgentEvalDefence(CAIAgentEvalDefence *this)
 CAIAgentEvalDefence::CAIAgentEvalDefence(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, "defence evaluation");
  *(_DWORD *)this = &CAIAgentEvalDefence::_vftable_;
  *((_DWORD *)this + 10) = 0;
  return this;
}


// address=[0x13045d0]
// Decompiled from unsigned int __thiscall CAIAgentEvalDefence::Execute(CAIAgentEvalDefence *this, unsigned int a2, unsigned int a3)
unsigned int  CAIAgentEvalDefence::Execute(unsigned int,unsigned int) {
  
  CAINormalSectorAI *v3; // eax

  v3 = CAINormalSectorAgent::SectorAI(this);
  CAINormalSectorAI::EvaluateNextOwnMilitaryBuilding(v3);
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1304600]
// Decompiled from int __thiscall CAIAgentEvalDefence::Load(CAIAgentEvalDefence *this, struct IS4Chunk *a2)
void  CAIAgentEvalDefence::Load(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516285952);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  CAIAgent::Load(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516285950);
  *((_DWORD *)this + 10) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516285951);
}


// address=[0x1304680]
// Decompiled from int __thiscall CAIAgentEvalDefence::Save(CAIAgentEvalDefence *this, struct IS4Chunk *a2)
void  CAIAgentEvalDefence::Save(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516285952);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  CAIAgent::Save(this, a2);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516285950);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 10));
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516285951);
}


// address=[0x1306280]
// Decompiled from void __thiscall CAIAgentEvalDefence::~CAIAgentEvalDefence(CAIAgentEvalDefence *this)
 CAIAgentEvalDefence::~CAIAgentEvalDefence(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


// address=[0x1309520]
// Decompiled from int __thiscall CAIAgentEvalDefence::EvaluationCounter(CAIAgentEvalDefence *this)
int  CAIAgentEvalDefence::EvaluationCounter(void)const {
  
  return *((_DWORD *)this + 10);
}


