#include "CAIAgentPlayerBase.h"

#include "CBB/CBBSupport.h"

// Definitions for class CAIAgentPlayerBase

// address=[0x1306b10]
// Decompiled from void __thiscall CAIAgentPlayerBase::AttachPlayerAI(CAIAgentPlayerBase *this, struct CAIPlayerAI *_pPlayerAI)
void CAIAgentPlayerBase::AttachPlayerAI(class CAIPlayerAI *_pPlayerAI) {
  if(!_pPlayerAI && BBSupportDbgReport(2, "AI\\AI_AgentsPlayer.cpp", 27, "_pPlayerAI != 0") == 1)
    __debugbreak();
  if(this->m_pPlayerAI && BBSupportDbgReport(2, "AI\\AI_AgentsPlayer.cpp", 28, "m_pPlayerAI == 0") == 1)
    __debugbreak();
  this->m_pPlayerAI = _pPlayerAI;
}


// address=[0x1307170]
// Decompiled from struct CAIPlayerAI *__thiscall CAIAgentPlayerBase::PlayerAI(CAIAgentPlayerBase *this)
class CAIPlayerAI *CAIAgentPlayerBase::PlayerAI(void) const {
  return this->m_pPlayerAI;
}


// address=[0x1319190]
// Decompiled from CAIAgentPlayerBase *__thiscall CAIAgentPlayerBase::CAIAgentPlayerBase(CAIAgentPlayerBase *this, const char *a2)
CAIAgentPlayerBase::CAIAgentPlayerBase(char const *a2) : CAIAgent(a2), m_pPlayerAI(nullptr) {}


// address=[0x1319280]
// Decompiled from void __thiscall CAIAgentPlayerBase::~CAIAgentPlayerBase(CAIAgentPlayerBase *this)
CAIAgentPlayerBase::~CAIAgentPlayerBase(void) = default;


