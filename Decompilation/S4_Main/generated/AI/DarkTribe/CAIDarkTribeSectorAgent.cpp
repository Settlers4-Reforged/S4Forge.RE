#include "CAIDarkTribeSectorAgent.h"

// Definitions for class CAIDarkTribeSectorAgent

// address=[0x12fc7f0]
// Decompiled from CAIDarkTribeSectorAgent *__thiscall CAIDarkTribeSectorAgent::CAIDarkTribeSectorAgent(  CAIDarkTribeSectorAgent *this,  const char *a2)
 CAIDarkTribeSectorAgent::CAIDarkTribeSectorAgent(char const *) {
  
  CAIAgent::CAIAgent(this, a2);
  *(_DWORD *)this = &CAIDarkTribeSectorAgent::_vftable_;
  *((_DWORD *)this + 9) = 0;
  return this;
}


// address=[0x12fca00]
// Decompiled from void __thiscall CAIDarkTribeSectorAgent::~CAIDarkTribeSectorAgent(CAIDarkTribeSectorAgent *this)
 CAIDarkTribeSectorAgent::~CAIDarkTribeSectorAgent(void) {
  
  CAIAgent::~CAIAgent(this);
}


// address=[0x12fd5c0]
// Decompiled from int __thiscall CAIDarkTribeSectorAgent::SectorAI(CAIDarkTribeSectorAgent *this)
class CAIDarkTribeSectorAI *  CAIDarkTribeSectorAgent::SectorAI(void)const {
  
  return *((_DWORD *)this + 9);
}


// address=[0x1301910]
// Decompiled from CAIDarkTribeSectorAgent *__thiscall CAIDarkTribeSectorAgent::AttachSectorAI(  CAIDarkTribeSectorAgent *this,  struct CAIDarkTribeSectorAI *a2)
void  CAIDarkTribeSectorAgent::AttachSectorAI(class CAIDarkTribeSectorAI *) {
  
  CAIDarkTribeSectorAgent *result; // eax

  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 127, "_pSectorAI != 0") == 1 )
    __debugbreak();
  if ( *((_DWORD *)this + 9) && BBSupportDbgReport(2, "AI\\AI_AgentsDark.cpp", 128, "m_pSectorAI == 0") == 1 )
    __debugbreak();
  result = this;
  *((_DWORD *)this + 9) = a2;
  return result;
}


