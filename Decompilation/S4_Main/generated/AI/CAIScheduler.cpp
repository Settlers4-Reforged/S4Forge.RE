#if FALSE
#include "CAIScheduler.h"

// Definitions for class CAIScheduler

// address=[0x12ff090]
// Decompiled from CAIScheduler *__thiscall CAIScheduler::CAIScheduler(CAIScheduler *this)
 CAIScheduler::CAIScheduler(void) {
  
  CAIAgent::CAIAgent(this, "Scheduler");
  this->__vftable = (CAIScheduler_vtbl *)&CAIScheduler::_vftable_;
  this->m_iNumberOfAgents = 0;
  this->m_pFirstAgent = 0;
  return this;
}


// address=[0x12ff0d0]
// Decompiled from void __thiscall CAIScheduler::~CAIScheduler(CAIScheduler *this)
 CAIScheduler::~CAIScheduler(void) {
  
  *(_DWORD *)this = &CAIScheduler::_vftable_;
  CAIScheduler::RemoveAllAgents(this);
  CAIAgent::~CAIAgent(this);
}


// address=[0x12ff120]
// Decompiled from void __thiscall CAIScheduler::AddAgent(CAIScheduler *this, CAIAgent *_rAgent, int _uDefaultExecutionDelay, int a4, int a5)
void  CAIScheduler::AddAgent(class CAIAgent & _rAgent, unsigned int _uDefaultExecutionDelay, unsigned int a4, unsigned int a5) {
  
  if ( _rAgent->m_pScheduler )
  {
    CAIScheduler::RemoveAgent(_rAgent->m_pScheduler, _rAgent);
  }
  _rAgent->m_uScheduleTime = 0;
  _rAgent->m_uDefaultExecutionDelay = _uDefaultExecutionDelay;
  _rAgent->dwordC = a4;
  _rAgent->dword10 = a5;
  CAIScheduler::AddAgentEx(this, _rAgent);
}


// address=[0x12ff180]
// Decompiled from void __thiscall CAIScheduler::RemoveAgent(CAIScheduler *this, struct CAIAgent *a2)
void  CAIScheduler::RemoveAgent(class CAIAgent & a2) {
  
  if ( a2->m_pScheduler == this )
  {
    CAIScheduler::RemoveAgentEx(this, a2);
  }
  else if ( BBSupportDbgReport(1, "AI\\AI_Agents.cpp", 238, "CAIScheduler::RemoveAgent(): Agent not in list!") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x12ff1d0]
// Decompiled from void __thiscall CAIScheduler::RemoveAllAgents(CAIScheduler *this)
void  CAIScheduler::RemoveAllAgents(void) {
  
  while ( this->m_pFirstAgent )
  {
    CAIScheduler::RemoveAgent(this, this->m_pFirstAgent);
  }
}


// address=[0x12ff200]
// Decompiled from void __thiscall CAIScheduler::UpdateAgentScheduleTime(CAIScheduler *this, struct CAIAgent *_rParent, unsigned int _uScheduleTime)
void  CAIScheduler::UpdateAgentScheduleTime(class CAIAgent & _rParent, unsigned int _uScheduleTime) {
  
  if ( _rParent->m_pScheduler == this )
  {
    if ( _rParent->m_uScheduleTime != _uScheduleTime )
    {
      CAIScheduler::RemoveAgentEx(this, _rParent);
      _rParent->m_uScheduleTime = _uScheduleTime;
      CAIScheduler::AddAgentEx(this, _rParent);
    }
  }
  else if ( BBSupportDbgReport(1, "AI\\AI_Agents.cpp", 314, "CAIScheduler::UpdateAgentExecutionDelay(): Invalid agent!") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x12ff270]
// Decompiled from unsigned int __thiscall CAIScheduler::Execute(CAIScheduler *this, unsigned int a2, unsigned int a3)
unsigned int  CAIScheduler::Execute(unsigned int a2, unsigned int a3) {
  
  unsigned int v4; // [esp+0h] [ebp-1Ch]
  int m_uDefaultExecutionDelay; // [esp+4h] [ebp-18h]
  unsigned int v6; // [esp+8h] [ebp-14h]
  unsigned int m_uScheduleTime; // [esp+Ch] [ebp-10h]
  unsigned int dwordC; // [esp+10h] [ebp-Ch]
  CAIAgent *m_pFirstAgent; // [esp+14h] [ebp-8h]

  v6 = 1;
  while ( this->m_pFirstAgent && this->m_pFirstAgent->m_uScheduleTime <= a2 && this->m_pFirstAgent->dwordC <= a3 )
  {
    m_pFirstAgent = this->m_pFirstAgent;
    v4 = m_pFirstAgent->Execute(m_pFirstAgent, a2, a3);
    m_uDefaultExecutionDelay = v4 >> 12;
    dwordC = v4 & 0xFFF;
    if ( !(v4 >> 12) )
    {
      m_uDefaultExecutionDelay = m_pFirstAgent->m_uDefaultExecutionDelay;
    }
    if ( !m_uDefaultExecutionDelay )
    {
      m_uDefaultExecutionDelay = 1;
    }
    if ( (v4 & 0xFFF) == 0 )
    {
      dwordC = m_pFirstAgent->dwordC;
    }
    if ( !dwordC )
    {
      dwordC = 1;
    }
    CAIScheduler::RemoveAgentEx(this, m_pFirstAgent);
    m_pFirstAgent->m_uScheduleTime = m_uDefaultExecutionDelay + a2;
    CAIScheduler::AddAgentEx(this, m_pFirstAgent);
    if ( dwordC >= a3 )
    {
      a3 = 0;
    }
    else
    {
      a3 -= dwordC;
    }
    v6 += dwordC;
  }
  if ( v6 > 0xFFF )
  {
    v6 = 4095;
  }
  if ( !this->m_pFirstAgent )
  {
    return CAIAgent::ExecuteResult(0xFFFFFu, v6);
  }
  m_uScheduleTime = this->m_pFirstAgent->m_uScheduleTime;
  if ( m_uScheduleTime > a2 )
  {
    if ( m_uScheduleTime - a2 > 0xFFFFF )
    {
      m_uScheduleTime = a2 + 0xFFFFF;
    }
  }
  else
  {
    m_uScheduleTime = a2 + 1;
  }
  this->m_uScheduleTime = m_uScheduleTime;
  return CAIAgent::ExecuteResult(m_uScheduleTime - a2, v6);
}


// address=[0x12ff400]
// Decompiled from void __thiscall CAIScheduler::AddAgentEx(CAIScheduler *this, struct CAIAgent *a2)
void  CAIScheduler::AddAgentEx(class CAIAgent * a2) {
  
  unsigned int dword4; // [esp+4h] [ebp-10h]
  CAIAgent *v4; // [esp+Ch] [ebp-8h]
  CAIAgent *i; // [esp+10h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 174, "_pAgent != 0") == 1 )
  {
    __debugbreak();
  }
  if ( a2->m_pScheduler && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 175, "_pAgent->m_pScheduler == 0") == 1 )
  {
    __debugbreak();
  }
  dword4 = a2->m_uScheduleTime;
  v4 = 0;
  for ( i = this->m_pFirstAgent;
        i && dword4 >= i->m_uScheduleTime && (dword4 != i->m_uScheduleTime || a2->dword10 < i->dword10);
        i = i->m_pNextAgent )
  {
    v4 = i;
  }
  a2->m_pPrevAgent = v4;
  a2->m_pNextAgent = i;
  a2->m_pScheduler = this;
  if ( v4 && v4->m_pNextAgent != i && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 203, "(pPrevAgent == 0) || (pPrevAgent->m_pNextAgent == pNextAgent)") == 1 )
  {
    __debugbreak();
  }
  if ( i && i->m_pPrevAgent != v4 && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 204, "(pNextAgent == 0) || (pNextAgent->m_pPrevAgent == pPrevAgent)") == 1 )
  {
    __debugbreak();
  }
  if ( v4 )
  {
    v4->m_pNextAgent = a2;
  }
  else
  {
    this->m_pFirstAgent = a2;
  }
  if ( i )
  {
    i->m_pPrevAgent = a2;
  }
  ++this->m_iNumberOfAgents;
}


// address=[0x12ff580]
// Decompiled from void __thiscall CAIScheduler::RemoveAgentEx(CAIScheduler *this, struct CAIAgent *_pAgent)
void  CAIScheduler::RemoveAgentEx(class CAIAgent * _pAgent) {
  
  if ( !_pAgent && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 249, "_pAgent != 0") == 1 )
  {
    __debugbreak();
  }
  if ( _pAgent->m_pScheduler != this && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 250, "_pAgent->m_pScheduler == this") == 1 )
  {
    __debugbreak();
  }
  if ( _pAgent->m_pPrevAgent )
  {
    if ( _pAgent->m_pPrevAgent->m_pNextAgent != _pAgent && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 254, "_pAgent->m_pPrevAgent->m_pNextAgent == _pAgent") == 1 )
    {
      __debugbreak();
    }
    _pAgent->m_pPrevAgent->m_pNextAgent = _pAgent->m_pNextAgent;
  }
  else
  {
    if ( this->m_pFirstAgent != _pAgent && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 260, "m_pFirstAgent == _pAgent") == 1 )
    {
      __debugbreak();
    }
    this->m_pFirstAgent = _pAgent->m_pNextAgent;
  }
  if ( _pAgent->m_pNextAgent )
  {
    if ( _pAgent->m_pNextAgent->m_pPrevAgent != _pAgent && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 267, "_pAgent->m_pNextAgent->m_pPrevAgent == _pAgent") == 1 )
    {
      __debugbreak();
    }
    _pAgent->m_pNextAgent->m_pPrevAgent = _pAgent->m_pPrevAgent;
  }
  _pAgent->m_pPrevAgent = 0;
  _pAgent->m_pNextAgent = 0;
  _pAgent->m_pScheduler = 0;
  if ( --this->m_iNumberOfAgents < 0 && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 278, "m_iNumberOfAgents >= 0") == 1 )
  {
    __debugbreak();
  }
}


#endif // Already implemented
