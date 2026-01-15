#include "CAIScheduler.h"

// Definitions for class CAIScheduler

// address=[0x12ff090]
// Decompiled from CAIScheduler *__thiscall CAIScheduler::CAIScheduler(CAIScheduler *this)
 CAIScheduler::CAIScheduler(void) {
  
  CAIAgent::CAIAgent(this, "Scheduler");
  *(_DWORD *)this = &CAIScheduler::_vftable_;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
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
// Decompiled from void __thiscall CAIScheduler::AddAgent(  CAIScheduler *this,  CAIScheduler **a2,  CAIScheduler *a3,  CAIScheduler *a4,  CAIScheduler *a5)
void  CAIScheduler::AddAgent(class CAIAgent &,unsigned int,unsigned int,unsigned int) {
  
  if ( a2[5] )
    CAIScheduler::RemoveAgent(a2[5], (struct CAIAgent *)a2);
  a2[1] = 0;
  a2[2] = a3;
  a2[3] = a4;
  a2[4] = a5;
  CAIScheduler::AddAgentEx(this, (struct CAIAgent *)a2);
}


// address=[0x12ff180]
// Decompiled from void __thiscall CAIScheduler::RemoveAgent(CAIScheduler *this, struct CAIAgent *a2)
void  CAIScheduler::RemoveAgent(class CAIAgent &) {
  
  if ( *((CAIScheduler **)a2 + 5) == this )
  {
    CAIScheduler::RemoveAgentEx(this, a2);
  }
  else if ( BBSupportDbgReport(1, "AI\\AI_Agents.cpp", 238, "CAIScheduler::RemoveAgent(): Agent not in list!") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x12ff1d0]
// Decompiled from CAIScheduler *__thiscall CAIScheduler::RemoveAllAgents(struct CAIAgent **this)
void  CAIScheduler::RemoveAllAgents(void) {
  
  CAIScheduler *result; // eax

  while ( 1 )
  {
    result = (CAIScheduler *)this;
    if ( !this[10] )
      break;
    CAIScheduler::RemoveAgent((CAIScheduler *)this, this[10]);
  }
  return result;
}


// address=[0x12ff200]
// Decompiled from void __thiscall CAIScheduler::UpdateAgentScheduleTime(CAIScheduler *this, struct CAIAgent *a2, unsigned int a3)
void  CAIScheduler::UpdateAgentScheduleTime(class CAIAgent &,unsigned int) {
  
  if ( *((CAIScheduler **)a2 + 5) == this )
  {
    if ( *((_DWORD *)a2 + 1) != a3 )
    {
      CAIScheduler::RemoveAgentEx(this, a2);
      *((_DWORD *)a2 + 1) = a3;
      CAIScheduler::AddAgentEx(this, a2);
    }
  }
  else if ( BBSupportDbgReport(1, "AI\\AI_Agents.cpp", 314, "CAIScheduler::UpdateAgentExecutionDelay(): Invalid agent!") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x12ff270]
// Decompiled from unsigned int __thiscall CAIScheduler::Execute(CAIScheduler *this, unsigned int a2, unsigned int a3)
unsigned int  CAIScheduler::Execute(unsigned int,unsigned int) {
  
  unsigned int v4; // [esp+0h] [ebp-1Ch]
  int v5; // [esp+4h] [ebp-18h]
  unsigned int v6; // [esp+8h] [ebp-14h]
  unsigned int v7; // [esp+Ch] [ebp-10h]
  unsigned int v8; // [esp+10h] [ebp-Ch]
  struct CAIAgent *v9; // [esp+14h] [ebp-8h]

  v6 = 1;
  while ( *((_DWORD *)this + 10)
       && *(_DWORD *)(*((_DWORD *)this + 10) + 4) <= a2
       && *(_DWORD *)(*((_DWORD *)this + 10) + 12) <= a3 )
  {
    v9 = (struct CAIAgent *)*((_DWORD *)this + 10);
    v4 = (*(int (__thiscall **)(struct CAIAgent *, unsigned int, unsigned int))(*(_DWORD *)v9 + 4))(v9, a2, a3);
    v5 = v4 >> 12;
    v8 = v4 & 0xFFF;
    if ( !(v4 >> 12) )
      v5 = *((_DWORD *)v9 + 2);
    if ( !v5 )
      v5 = 1;
    if ( (v4 & 0xFFF) == 0 )
      v8 = *((_DWORD *)v9 + 3);
    if ( !v8 )
      v8 = 1;
    CAIScheduler::RemoveAgentEx(this, v9);
    *((_DWORD *)v9 + 1) = v5 + a2;
    CAIScheduler::AddAgentEx(this, v9);
    if ( v8 >= a3 )
      a3 = 0;
    else
      a3 -= v8;
    v6 += v8;
  }
  if ( v6 > 0xFFF )
    v6 = 4095;
  if ( !*((_DWORD *)this + 10) )
    return CAIAgent::ExecuteResult(0xFFFFFu, v6);
  v7 = *(_DWORD *)(*((_DWORD *)this + 10) + 4);
  if ( v7 > a2 )
  {
    if ( v7 - a2 > 0xFFFFF )
      v7 = a2 + 0xFFFFF;
  }
  else
  {
    v7 = a2 + 1;
  }
  *((_DWORD *)this + 1) = v7;
  return CAIAgent::ExecuteResult(v7 - a2, v6);
}


// address=[0x12ff400]
// Decompiled from CAIScheduler *__thiscall CAIScheduler::AddAgentEx(CAIScheduler *this, struct CAIAgent *a2)
void  CAIScheduler::AddAgentEx(class CAIAgent *) {
  
  CAIScheduler *result; // eax
  unsigned int v3; // [esp+4h] [ebp-10h]
  _DWORD *v5; // [esp+Ch] [ebp-8h]
  _DWORD *i; // [esp+10h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 174, "_pAgent != 0") == 1 )
    __debugbreak();
  if ( *((_DWORD *)a2 + 5) && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 175, "_pAgent->m_pScheduler == 0") == 1 )
    __debugbreak();
  v3 = *((_DWORD *)a2 + 1);
  v5 = 0;
  for ( i = (_DWORD *)*((_DWORD *)this + 10);
        i && v3 >= i[1] && (v3 != i[1] || *((_DWORD *)a2 + 4) < i[4]);
        i = (_DWORD *)i[7] )
  {
    v5 = i;
  }
  *((_DWORD *)a2 + 6) = v5;
  *((_DWORD *)a2 + 7) = i;
  *((_DWORD *)a2 + 5) = this;
  if ( v5
    && (_DWORD *)v5[7] != i
    && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 203, "(pPrevAgent == 0) || (pPrevAgent->m_pNextAgent == pNextAgent)") == 1 )
  {
    __debugbreak();
  }
  if ( i
    && (_DWORD *)i[6] != v5
    && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 204, "(pNextAgent == 0) || (pNextAgent->m_pPrevAgent == pPrevAgent)") == 1 )
  {
    __debugbreak();
  }
  if ( v5 )
    v5[7] = a2;
  else
    *((_DWORD *)this + 10) = a2;
  if ( i )
    i[6] = a2;
  result = this;
  ++*((_DWORD *)this + 9);
  return result;
}


// address=[0x12ff580]
// Decompiled from struct CAIAgent **__thiscall CAIScheduler::RemoveAgentEx(struct CAIAgent **this, struct CAIAgent *a2)
void  CAIScheduler::RemoveAgentEx(class CAIAgent *) {
  
  struct CAIAgent **result; // eax

  if ( !a2 && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 249, "_pAgent != 0") == 1 )
    __debugbreak();
  if ( *((struct CAIAgent ***)a2 + 5) != this
    && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 250, "_pAgent->m_pScheduler == this") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)a2 + 6) )
  {
    if ( *(struct CAIAgent **)(*((_DWORD *)a2 + 6) + 28) != a2
      && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 254, "_pAgent->m_pPrevAgent->m_pNextAgent == _pAgent") == 1 )
    {
      __debugbreak();
    }
    *(_DWORD *)(*((_DWORD *)a2 + 6) + 28) = *((_DWORD *)a2 + 7);
  }
  else
  {
    if ( this[10] != a2 && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 260, "m_pFirstAgent == _pAgent") == 1 )
      __debugbreak();
    this[10] = (struct CAIAgent *)*((_DWORD *)a2 + 7);
  }
  if ( *((_DWORD *)a2 + 7) )
  {
    if ( *(struct CAIAgent **)(*((_DWORD *)a2 + 7) + 24) != a2
      && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 267, "_pAgent->m_pNextAgent->m_pPrevAgent == _pAgent") == 1 )
    {
      __debugbreak();
    }
    *(_DWORD *)(*((_DWORD *)a2 + 7) + 24) = *((_DWORD *)a2 + 6);
  }
  *((_DWORD *)a2 + 6) = 0;
  *((_DWORD *)a2 + 7) = 0;
  *((_DWORD *)a2 + 5) = 0;
  result = this;
  this[9] = (struct CAIAgent *)((char *)this[9] - 1);
  if ( (int)this[9] >= 0 )
    return result;
  result = (struct CAIAgent **)BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 278, "m_iNumberOfAgents >= 0");
  if ( result == (struct CAIAgent **)1 )
    __debugbreak();
  return result;
}


