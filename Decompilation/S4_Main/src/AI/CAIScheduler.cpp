#include "CAIScheduler.h"

#include "CBB/CBBSupport.h"
#include "CAIAgent.h"

// Definitions for class CAIScheduler

// address=[0x12ff090]
// Decompiled from CAIScheduler *__thiscall CAIScheduler::CAIScheduler(CAIScheduler *this)
CAIScheduler::CAIScheduler(void) : CAIAgent("Scheduler") {
  this->m_iNumberOfAgents = 0;
  this->m_pFirstAgent = nullptr;
}


// address=[0x12ff0d0]
// Decompiled from void __thiscall CAIScheduler::~CAIScheduler(CAIScheduler *this)
CAIScheduler::~CAIScheduler(void) {
  this->RemoveAllAgents();
}


// address=[0x12ff120]
// Decompiled from void __thiscall CAIScheduler::AddAgent(  CAIScheduler *this,  CAIAgent *_rAgent,  int _uDefaultExecutionDelay,  int a4,  int a5)
void CAIScheduler::AddAgent(class CAIAgent &_rAgent, unsigned int _uDefaultExecutionDelay, unsigned int a4, unsigned int a5) {
  if(_rAgent.m_pScheduler)
    _rAgent.m_pScheduler->RemoveAgent(_rAgent);
  _rAgent.m_uScheduleTime = 0;
  _rAgent.m_uDefaultExecutionDelay = _uDefaultExecutionDelay;
  _rAgent.dwordC = a4;
  _rAgent.dword10 = a5;
  this->AddAgentEx(&_rAgent);
}


// address=[0x12ff180]
// Decompiled from void __thiscall CAIScheduler::RemoveAgent(CAIScheduler *this, struct CAIAgent *a2)
void CAIScheduler::RemoveAgent(class CAIAgent &a2) {
  if(a2.m_pScheduler == this) {
    this->RemoveAgentEx(&a2);
  } else if(BBSupportDbgReport(1, "AI\\AI_Agents.cpp", 238, "CAIScheduler::RemoveAgent(): Agent not in list!") == 1) {
    __debugbreak();
  }
}


// address=[0x12ff1d0]
// Decompiled from CAIScheduler *__thiscall CAIScheduler::RemoveAllAgents(struct CAIAgent **this)
void CAIScheduler::RemoveAllAgents(void) {
  while(this->m_pFirstAgent)
    this->RemoveAgent(*this->m_pFirstAgent);
}


// address=[0x12ff200]
// Decompiled from void __thiscall CAIScheduler::UpdateAgentScheduleTime(  CAIScheduler *this,  struct CAIAgent *_rParent,  unsigned int _uScheduleTime)
void CAIScheduler::UpdateAgentScheduleTime(class CAIAgent &_rParent, unsigned int _uScheduleTime) {
  if(_rParent.m_pScheduler == this) {
    if(_rParent.m_uScheduleTime != _uScheduleTime) {
      this->RemoveAgentEx(&_rParent);
      _rParent.m_uScheduleTime = _uScheduleTime;
      this->AddAgentEx(&_rParent);
    }
  } else if(BBSupportDbgReport(1, "AI\\AI_Agents.cpp", 314, "CAIScheduler::UpdateAgentExecutionDelay(): Invalid agent!") == 1) {
    __debugbreak();
  }
}


// address=[0x12ff270]
// Decompiled from unsigned int __thiscall CAIScheduler::Execute(CAIScheduler *this, unsigned int a2, unsigned int a3)
unsigned int CAIScheduler::Execute(unsigned int a2, unsigned int a3) {
  unsigned int v4; // [esp+0h] [ebp-1Ch]
  // [esp+4h] [ebp-18h]
  // [esp+8h] [ebp-14h]
  // [esp+Ch] [ebp-10h]
  // [esp+10h] [ebp-Ch]

  unsigned int v6 = 1;
  while(this->m_pFirstAgent && this->m_pFirstAgent->m_uScheduleTime <= a2 && this->m_pFirstAgent->dwordC <= a3) {
    v4 = m_pFirstAgent->Execute(a2, a3);
    int          iExecutionDelay = v4 >> 12;
    unsigned int dwordC = v4 & 0xFFF;
    if(!(v4 >> 12))
      iExecutionDelay = m_pFirstAgent->m_uDefaultExecutionDelay;
    if(!iExecutionDelay)
      iExecutionDelay = 1;
    if((v4 & 0xFFF) == 0)
      dwordC = m_pFirstAgent->dwordC; // Can't quite tell what dwordc is supposed to do here...
    if(!dwordC)
      dwordC = 1;
    this->RemoveAgentEx(m_pFirstAgent);
    m_pFirstAgent->m_uScheduleTime = iExecutionDelay + a2;
    this->AddAgentEx(m_pFirstAgent);
    if(dwordC >= a3)
      a3 = 0;
    else
      a3 -= dwordC;
    v6 += dwordC;
  }
  if(v6 > 0xFFF)
    v6 = 4095;
  if(!this->m_pFirstAgent)
    return CAIAgent::ExecuteResult(0xFFFFFu, v6);
  unsigned int uScheduleTime = this->m_pFirstAgent->m_uScheduleTime;
  if(uScheduleTime > a2) {
    if(uScheduleTime - a2 > 0xFFFFF)
      uScheduleTime = a2 + 0xFFFFF;
  } else {
    uScheduleTime = a2 + 1;
  }
  this->m_uScheduleTime = uScheduleTime;
  return CAIAgent::ExecuteResult(uScheduleTime - a2, v6);
}


// address=[0x12ff400]
// Decompiled from void __thiscall CAIScheduler::AddAgentEx(CAIScheduler *this, struct CAIAgent *a2)
void CAIScheduler::AddAgentEx(class CAIAgent *a2) {
  // [esp+4h] [ebp-10h]
  // [esp+Ch] [ebp-8h]
  CAIAgent *pNextAgent; // [esp+10h] [ebp-4h]

  if(!a2 && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 174, "_pAgent != 0") == 1)
    __debugbreak();
  if(a2->m_pScheduler && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 175, "_pAgent->m_pScheduler == 0") == 1)
    __debugbreak();

  unsigned int uScheduleTime = a2->m_uScheduleTime;
  CAIAgent *   pPrevAgent = 0;
  for(pNextAgent = this->m_pFirstAgent;
      pNextAgent && uScheduleTime >= pNextAgent->m_uScheduleTime && (uScheduleTime != pNextAgent->m_uScheduleTime || a2->dword10 < pNextAgent->dword10);
      pNextAgent = pNextAgent->m_pNextAgent) {
    pPrevAgent = pNextAgent;
  }
  a2->m_pPrevAgent = pPrevAgent;
  a2->m_pNextAgent = pNextAgent;
  a2->m_pScheduler = this;

  if(pPrevAgent
     && pPrevAgent->m_pNextAgent != pNextAgent
     && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 203, "(pPrevAgent == 0) || (pPrevAgent->m_pNextAgent == pNextAgent)") == 1) {
    __debugbreak();
  }
  if(pNextAgent
     && pNextAgent->m_pPrevAgent != pPrevAgent
     && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 204, "(pNextAgent == 0) || (pNextAgent->m_pPrevAgent == pPrevAgent)") == 1) {
    __debugbreak();
  }
  if(pPrevAgent)
    pPrevAgent->m_pNextAgent = a2;
  else
    this->m_pFirstAgent = a2;
  if(pNextAgent)
    pNextAgent->m_pPrevAgent = a2;
  ++this->m_iNumberOfAgents;
}


// address=[0x12ff580]
// Decompiled from void __thiscall CAIScheduler::RemoveAgentEx(CAIScheduler *this, struct CAIAgent *_pAgent)
void CAIScheduler::RemoveAgentEx(class CAIAgent *_pAgent) {
  if(!_pAgent && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 249, "_pAgent != 0") == 1)
    __debugbreak();
  if(_pAgent->m_pScheduler != this
     && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 250, "_pAgent->m_pScheduler == this") == 1) {
    __debugbreak();
  }
  if(_pAgent->m_pPrevAgent) {
    if(_pAgent->m_pPrevAgent->m_pNextAgent != _pAgent
       && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 254, "_pAgent->m_pPrevAgent->m_pNextAgent == _pAgent") == 1) {
      __debugbreak();
    }
    _pAgent->m_pPrevAgent->m_pNextAgent = _pAgent->m_pNextAgent;
  } else {
    if(this->m_pFirstAgent != _pAgent
       && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 260, "m_pFirstAgent == _pAgent") == 1) {
      __debugbreak();
    }
    this->m_pFirstAgent = _pAgent->m_pNextAgent;
  }
  if(_pAgent->m_pNextAgent) {
    if(_pAgent->m_pNextAgent->m_pPrevAgent != _pAgent
       && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 267, "_pAgent->m_pNextAgent->m_pPrevAgent == _pAgent") == 1) {
      __debugbreak();
    }
    _pAgent->m_pNextAgent->m_pPrevAgent = _pAgent->m_pPrevAgent;
  }
  _pAgent->m_pPrevAgent = nullptr;
  _pAgent->m_pNextAgent = nullptr;
  _pAgent->m_pScheduler = nullptr;
  if(--this->m_iNumberOfAgents < 0 && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 278, "m_iNumberOfAgents >= 0") == 1)
    __debugbreak();
}


