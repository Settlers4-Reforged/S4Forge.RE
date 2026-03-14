#include "CAIAgent.h"

// Definitions for class CAIAgent

#include "CAIScheduler.h"
#include "CBB/CBBSupport.h"
#include "../LoadSave/IS4Chunk.h"

// address=[0x12fd090]
// Decompiled from unsigned int __cdecl CAIAgent::ExecuteResult(unsigned int a1, unsigned int a2)
unsigned int __cdecl CAIAgent::ExecuteResult(unsigned int a1, unsigned int a2) {
  return a2 | (a1 << 12);
}


// address=[0x12fd530]
// Decompiled from void __thiscall CAIAgent::ProcessEvent(CAIAgent *this, const struct CAIEvent *a2)
void CAIAgent::ProcessEvent(class CAIEvent const &a2) {}


// address=[0x12fd7e0]
// Decompiled from void __thiscall CAIAgent::UpdateScheduleTimeIfLess(CAIAgent *this, unsigned int _uScheduleTime)
void CAIAgent::UpdateScheduleTimeIfLess(unsigned int _uScheduleTime) {
  if(_uScheduleTime < this->m_uScheduleTime && this->m_pScheduler != 0)
    this->m_pScheduler->UpdateAgentScheduleTime(*this, _uScheduleTime);
}


// address=[0x12fee10]
// Decompiled from CAIAgent *__thiscall CAIAgent::CAIAgent(CAIAgent *this, const char *a2)
CAIAgent::CAIAgent(char const *a2) {
  this->m_spName = a2;
  this->m_uScheduleTime = 0;
  this->m_uDefaultExecutionDelay = 0;
  this->dwordC = 0;
  this->dword10 = 0;
  this->m_pScheduler = 0;
  this->m_pPrevAgent = 0;
  this->m_pNextAgent = 0;
}


// address=[0x12fee80]
// Decompiled from int __thiscall CAIAgent::~CAIAgent(CAIAgent *this)
CAIAgent::~CAIAgent(void) {
  if(this->m_pScheduler)
    this->m_pScheduler->RemoveAgent(*this);
  if(this->m_pScheduler && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 53, "m_pScheduler == 0") == 1)
    __debugbreak();
  if(this->m_pPrevAgent && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 54, "m_pPrevAgent == 0") == 1)
    __debugbreak();
  if(this->m_pNextAgent && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 55, "m_pNextAgent == 0") == 1)
    __debugbreak();
}


// address=[0x12fef50]
// Decompiled from void __thiscall CAIAgent::Load(CAIAgent *this, struct IS4Chunk *a2)
void CAIAgent::Load(IS4Chunk &a2) {
  // [esp+4h] [ebp-4h]
  a2.LoadSignature(-1516306176);
  a2.LoadUnsigned32(1, 1);
  a2.LoadSignature(-1516306174);
  unsigned int uScheduleTime = a2.LoadUnsigned32();
  if(this->m_pScheduler) {
    if(uScheduleTime)
      this->UpdateScheduleTime(uScheduleTime);
  } else if(uScheduleTime && BBSupportDbgReport(2, "AI\\AI_Agents.cpp", 86, "uScheduleTime == 0") == 1) {
    __debugbreak();
  }
  a2.LoadSignature(-1516306175);
}


// address=[0x12ff000]
// Decompiled from void __thiscall CAIAgent::Save(CAIAgent *this, struct IS4Chunk *a2)
void CAIAgent::Save(IS4Chunk &a2) {
  DWORD uScheduleTime; // [esp+4h] [ebp-8h]
  a2.SaveSignature(-1516306176);
  a2.SaveUnsigned32(1);
  a2.SaveSignature(-1516306174);
  if(this->m_pScheduler)
    uScheduleTime = this->m_uScheduleTime;
  else
    uScheduleTime = 0;
  a2.SaveUnsigned32(uScheduleTime);
  a2.SaveSignature(-1516306175);
}


// address=[0x12ff9c0]
// Decompiled from void __thiscall CAIAgent::UpdateScheduleTime(CAIAgent *this, unsigned int a2)
void CAIAgent::UpdateScheduleTime(unsigned int a2) {
  if(this->m_pScheduler)
    this->m_pScheduler->UpdateAgentScheduleTime(*this, a2);
}


// address=[0x13064e0]
// Decompiled from int __thiscall CAIAgent::DefaultExecutionDelay(CAIAgent *this)
unsigned int CAIAgent::DefaultExecutionDelay(void) const {
  return this->m_uDefaultExecutionDelay;
}


