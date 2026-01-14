#include "all_headers.h"

// Definitions for class CAIAgentPlayerBase

// address=[0x1306b10]
// Decompiled from CAIAgentPlayerBase *__thiscall CAIAgentPlayerBase::AttachPlayerAI(CAIAgentPlayerBase *this, struct CAIPlayerAI *a2)
void  CAIAgentPlayerBase::AttachPlayerAI(class CAIPlayerAI *) {
  
  CAIAgentPlayerBase *result; // eax

  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_AgentsPlayer.cpp", 27, "_pPlayerAI != 0") == 1 )
    __debugbreak();
  if ( *((_DWORD *)this + 9) && BBSupportDbgReport(2, "AI\\AI_AgentsPlayer.cpp", 28, "m_pPlayerAI == 0") == 1 )
    __debugbreak();
  result = this;
  *((_DWORD *)this + 9) = a2;
  return result;
}


// address=[0x1307170]
// Decompiled from int __thiscall CAIAgentPlayerBase::PlayerAI(CAIAgentPlayerBase *this)
class CAIPlayerAI *  CAIAgentPlayerBase::PlayerAI(void)const {
  
  return *((_DWORD *)this + 9);
}


// address=[0x1319190]
// Decompiled from CAIAgentPlayerBase *__thiscall CAIAgentPlayerBase::CAIAgentPlayerBase(CAIAgentPlayerBase *this, const char *a2)
 CAIAgentPlayerBase::CAIAgentPlayerBase(char const *) {
  
  CAIAgent::CAIAgent(this, a2);
  *(_DWORD *)this = &CAIAgentPlayerBase::_vftable_;
  *((_DWORD *)this + 9) = 0;
  return this;
}


// address=[0x1319280]
// Decompiled from void __thiscall CAIAgentPlayerBase::~CAIAgentPlayerBase(CAIAgentPlayerBase *this)
 CAIAgentPlayerBase::~CAIAgentPlayerBase(void) {
  
  CAIAgent::~CAIAgent(this);
}


