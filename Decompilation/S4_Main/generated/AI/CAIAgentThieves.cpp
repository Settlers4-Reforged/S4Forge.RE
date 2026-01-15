#include "CAIAgentThieves.h"

// Definitions for class CAIAgentThieves

// address=[0x1305810]
// Decompiled from unsigned int __thiscall CAIAgentThieves::Execute(CAIAgentThieves *this, unsigned int a2, unsigned int a3)
unsigned int  CAIAgentThieves::Execute(unsigned int,unsigned int) {
  
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1325b30]
// Decompiled from CAIAgentThieves *__thiscall CAIAgentThieves::CAIAgentThieves(CAIAgentThieves *this)
 CAIAgentThieves::CAIAgentThieves(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, "thieves");
  *(_DWORD *)this = &CAIAgentThieves::_vftable_;
  return this;
}


// address=[0x1325cd0]
// Decompiled from void __thiscall CAIAgentThieves::~CAIAgentThieves(CAIAgentThieves *this)
 CAIAgentThieves::~CAIAgentThieves(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


