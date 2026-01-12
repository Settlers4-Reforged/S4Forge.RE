#include "CAIAgent.h"

// Definitions for class CAIAgent

// address=[0x12fd090]
// Decompiled from unsigned int __cdecl CAIAgent::ExecuteResult(unsigned int a1, unsigned int a2)

static unsigned int __cdecl CAIAgent::ExecuteResult(unsigned int,unsigned int) {
  
  return a2 | (a1 << 12);
}


// address=[0x12fd530]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall CAIAgent::ProcessEvent(CAIAgent *this, const struct CAIEvent *a2)

void  CAIAgent::ProcessEvent(class CAIEvent const &) {
  
  ;
}


// address=[0x12fd7e0]
// Decompiled from void __thiscall CAIAgent::UpdateScheduleTimeIfLess(CAIScheduler **this, unsigned int a2)

void  CAIAgent::UpdateScheduleTimeIfLess(unsigned int) {
  
  if ( a2 < (unsigned int)this[1] && this[5] != 0 )
    CAIScheduler::UpdateAgentScheduleTime(this[5], (struct CAIAgent *)this, a2);
}


// address=[0x12fee10]
// Decompiled from CAIAgent *__thiscall CAIAgent::CAIAgent(CAIAgent *this, const char *a2)

 CAIAgent::CAIAgent(char const *) {
  
  *(_DWORD *)this = &CAIAgent::_vftable_;
  *((_DWORD *)this + 8) = a2;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  return this;
}


// address=[0x12fee80]
// Decompiled from int __thiscall CAIAgent::~CAIAgent(CAIScheduler **this)

 CAIAgent::~CAIAgent(void) {
  
  *this = (CAIScheduler *)&CAIAgent::_vftable_;
  if ( this[5] )
    CAIScheduler::RemoveAgent(this[5], (struct CAIAgent *)this);
  if ( this[5] && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 53, "m_pScheduler == 0") == 1 )
    __debugbreak();
  if ( this[6] && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 54, "m_pPrevAgent == 0") == 1 )
    __debugbreak();
  if ( this[7] && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 55, "m_pNextAgent == 0") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x12fef50]
// Decompiled from int __thiscall CAIAgent::Load(CAIAgent *this, struct IS4Chunk *a2)

void  CAIAgent::Load(class IS4Chunk &) {
  
  unsigned int v4; // [esp+4h] [ebp-4h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516306176);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 4))(a2, 1, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516306174);
  v4 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  if ( *((_DWORD *)this + 5) )
  {
    if ( v4 )
      CAIAgent::UpdateScheduleTime(this, v4);
  }
  else if ( v4 && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 86, "uScheduleTime == 0") == 1 )
  {
    __debugbreak();
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516306175);
}


// address=[0x12ff000]
// Decompiled from int __thiscall CAIAgent::Save(CAIAgent *this, struct IS4Chunk *a2)

void  CAIAgent::Save(class IS4Chunk &) {
  
  int v3; // [esp+4h] [ebp-8h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516306176);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516306174);
  if ( *((_DWORD *)this + 5) )
    v3 = *((_DWORD *)this + 1);
  else
    v3 = 0;
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v3);
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516306175);
}


// address=[0x12ff9c0]
// Decompiled from void __thiscall CAIAgent::UpdateScheduleTime(CAIScheduler **this, unsigned int a2)

void  CAIAgent::UpdateScheduleTime(unsigned int) {
  
  if ( this[5] )
    CAIScheduler::UpdateAgentScheduleTime(this[5], (struct CAIAgent *)this, a2);
}


// address=[0x13064e0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CAIAgent::DefaultExecutionDelay(CAIAgent *this)

unsigned int  CAIAgent::DefaultExecutionDelay(void)const {
  
  return *((_DWORD *)this + 2);
}


