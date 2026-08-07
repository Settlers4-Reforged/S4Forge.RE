#include "CAIDarkTribeSectorAgent.h"

// Definitions for class CAIDarkTribeSectorAgent

// address=[0x12fc7f0]
// Decompiled from CAIDarkTribeSectorAgent *__thiscall CAIDarkTribeSectorAgent::CAIDarkTribeSectorAgent(CAIDarkTribeSectorAgent *this, const char *a2)
 CAIDarkTribeSectorAgent::CAIDarkTribeSectorAgent(char const * a2) {
  
  CAIAgent::CAIAgent(this, a2);
  this->__vftable = (CAIAgent_vtbl *)&CAIDarkTribeSectorAgent::_vftable_;
  this->m_pSectorAI = 0;
  return this;
}


// address=[0x12fca00]
// Decompiled from void __thiscall CAIDarkTribeSectorAgent::~CAIDarkTribeSectorAgent(CAIDarkTribeSectorAgent *this)
 CAIDarkTribeSectorAgent::~CAIDarkTribeSectorAgent(void) {
  
  CAIAgent::~CAIAgent(this);
}


// address=[0x12fd5c0]
// Decompiled from struct CAIDarkTribeSectorAI *__thiscall CAIDarkTribeSectorAgent::SectorAI(CAIDarkTribeSectorAgent *this)
class CAIDarkTribeSectorAI *  CAIDarkTribeSectorAgent::SectorAI(void)const {
  
  return this->m_pSectorAI;
}


// address=[0x1301910]
// Decompiled from void __thiscall CAIDarkTribeSectorAgent::AttachSectorAI(CAIDarkTribeSectorAgent *this, struct CAIDarkTribeSectorAI *a2)
void  CAIDarkTribeSectorAgent::AttachSectorAI(class CAIDarkTribeSectorAI * a2) {
  
  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 127, "_pSectorAI != 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_pSectorAI && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 128, "m_pSectorAI == 0") == 1 )
  {
    __debugbreak();
  }
  this->m_pSectorAI = a2;
}


