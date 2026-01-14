#include "all_headers.h"

// Definitions for class CAIAgentDarkTribeManakopters

// address=[0x1322de0]
// Decompiled from CAIAgentDarkTribeManakopters *__thiscall CAIAgentDarkTribeManakopters::CAIAgentDarkTribeManakopters(  CAIAgentDarkTribeManakopters *this)
 CAIAgentDarkTribeManakopters::CAIAgentDarkTribeManakopters(void) {
  
  CAIDarkTribeSectorAgent::CAIDarkTribeSectorAgent(this, "manakopters");
  *(_DWORD *)this = &CAIAgentDarkTribeManakopters::_vftable_;
  return this;
}


// address=[0x1322f20]
// Decompiled from void __thiscall CAIAgentDarkTribeManakopters::~CAIAgentDarkTribeManakopters(CAIAgentDarkTribeManakopters *this)
 CAIAgentDarkTribeManakopters::~CAIAgentDarkTribeManakopters(void) {
  
  CAIDarkTribeSectorAgent::~CAIDarkTribeSectorAgent(this);
}


// address=[0x1323220]
// Decompiled from int __thiscall CAIAgentDarkTribeManakopters::Execute(  CAIAgentDarkTribeManakopters *this,  unsigned int a2,  unsigned int a3)
unsigned int  CAIAgentDarkTribeManakopters::Execute(unsigned int,unsigned int) {
  
  return 1;
}


