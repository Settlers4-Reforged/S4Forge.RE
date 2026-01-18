#include "CAIAgentGardeners.h"

// Definitions for class CAIAgentGardeners

// address=[0x1304230]
// Decompiled from unsigned int __thiscall CAIAgentGardeners::Execute(CAIAgentGardeners *this, unsigned int a2, unsigned int a3)
unsigned int  CAIAgentGardeners::Execute(unsigned int a2, unsigned int a3) {
  
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1325a70]
// Decompiled from CAIAgentGardeners *__thiscall CAIAgentGardeners::CAIAgentGardeners(CAIAgentGardeners *this)
 CAIAgentGardeners::CAIAgentGardeners(void) {
  
  CAINormalSectorAgent::CAINormalSectorAgent(this, string__27);
  *(_DWORD *)this = &CAIAgentGardeners::_vftable_;
  return this;
}


// address=[0x1325c50]
// Decompiled from void __thiscall CAIAgentGardeners::~CAIAgentGardeners(CAIAgentGardeners *this)
 CAIAgentGardeners::~CAIAgentGardeners(void) {
  
  CAINormalSectorAgent::~CAINormalSectorAgent(this);
}


