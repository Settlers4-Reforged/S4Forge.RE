#include "CAIAgentEvaluation.h"

// Definitions for class CAIAgentEvaluation

// address=[0x1303a40]
// Decompiled from CAIAgentEvaluation *__thiscall CAIAgentEvaluation::CAIAgentEvaluation(  CAIAgentEvaluation *this,  struct CAIPlayerEvaluations *a2)
 CAIAgentEvaluation::CAIAgentEvaluation(class CAIPlayerEvaluations &) {
  
  CAIAgent::CAIAgent(this, "player evaluation");
  *(_DWORD *)this = &CAIAgentEvaluation::_vftable_;
  *((_DWORD *)this + 10) = a2;
  *((_DWORD *)this + 9) = 1;
  return this;
}


// address=[0x1303a80]
// Decompiled from unsigned int __thiscall CAIAgentEvaluation::Execute(CAIAgentEvaluation *this, unsigned int a2, unsigned int a3)
unsigned int  CAIAgentEvaluation::Execute(unsigned int,unsigned int) {
  
  if ( *((int *)this + 9) < 1
    && BBSupportDbgReport(2, "AI\\AI_AgentsEx.cpp", 43, "m_iCurrentPlayerId >= PLAYER_FIRST") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + 9) > 8
    && BBSupportDbgReport(2, "AI\\AI_AgentsEx.cpp", 44, "m_iCurrentPlayerId <= PLAYER_LAST") == 1 )
  {
    __debugbreak();
  }
  ++*((_DWORD *)this + 9);
  if ( *((_DWORD *)this + 9) > IAIEnvironment::AlliancesLastPlayerId() )
    *((_DWORD *)this + 9) = 1;
  if ( *((int *)this + 9) < 1
    && BBSupportDbgReport(2, "AI\\AI_AgentsEx.cpp", 55, "m_iCurrentPlayerId >= PLAYER_FIRST") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + 9) > 8
    && BBSupportDbgReport(2, "AI\\AI_AgentsEx.cpp", 56, "m_iCurrentPlayerId <= PLAYER_LAST") == 1 )
  {
    __debugbreak();
  }
  CAIPlayerEvaluations::EvaluatePlayer(*((CAIPlayerEvaluations **)this + 10), *((_DWORD *)this + 9));
  IMessageTracer::PushFormatedInts(g_pMsgTracer2, aEvaluatingPlay, *((_DWORD *)this + 9));
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1303be0]
// Decompiled from void __thiscall CAIAgentEvaluation::~CAIAgentEvaluation(CAIAgentEvaluation *this)
 CAIAgentEvaluation::~CAIAgentEvaluation(void) {
  
  CAIAgent::~CAIAgent(this);
}


// address=[0x1314030]
// Decompiled from CAIAgentEvaluation *__thiscall CAIAgentEvaluation::Init(CAIAgentEvaluation *this)
void  CAIAgentEvaluation::Init(void) {
  
  CAIAgentEvaluation *result; // eax

  result = this;
  *((_DWORD *)this + 9) = 1;
  return result;
}


