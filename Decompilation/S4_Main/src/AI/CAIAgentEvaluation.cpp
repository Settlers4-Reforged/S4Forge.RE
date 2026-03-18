#include "CAIAgentEvaluation.h"

#include <Debug/IMessageTracer.h>

#include "CAIPlayerEvaluations.h"
#include "AI/IAIEnvironment.h"
#include "CBB/CBBSupport.h"

// Definitions for class CAIAgentEvaluation

// address=[0x1303a40]
// Decompiled from CAIAgentEvaluation *__thiscall CAIAgentEvaluation::CAIAgentEvaluation(  CAIAgentEvaluation *this,  struct CAIPlayerEvaluations *a2)
CAIAgentEvaluation::CAIAgentEvaluation(class CAIPlayerEvaluations &a2) : CAIAgent("player evaluation"), m_pAIPlayerEvaluations(a2) {
  this->m_iCurrentPlayerId = 1;
}


// address=[0x1303a80]
// Decompiled from unsigned int __thiscall CAIAgentEvaluation::Execute(CAIAgentEvaluation *this, unsigned int a2, unsigned int a3)
unsigned int CAIAgentEvaluation::Execute(unsigned int a2, unsigned int a3) {
  if(this->m_iCurrentPlayerId < 1
     && BBSupportDbgReport(2, "AI\\AI_AgentsEx.cpp", 43, "m_iCurrentPlayerId >= PLAYER_FIRST") == 1) {
    __debugbreak();
  }
  if(this->m_iCurrentPlayerId > 8
     && BBSupportDbgReport(2, "AI\\AI_AgentsEx.cpp", 44, "m_iCurrentPlayerId <= PLAYER_LAST") == 1) {
    __debugbreak();
  }
  ++this->m_iCurrentPlayerId;
  if(this->m_iCurrentPlayerId > IAIEnvironment::AlliancesLastPlayerId())
    this->m_iCurrentPlayerId = 1;
  if(this->m_iCurrentPlayerId < 1
     && BBSupportDbgReport(2, "AI\\AI_AgentsEx.cpp", 55, "m_iCurrentPlayerId >= PLAYER_FIRST") == 1) {
    __debugbreak();
  }
  if(this->m_iCurrentPlayerId > 8
     && BBSupportDbgReport(2, "AI\\AI_AgentsEx.cpp", 56, "m_iCurrentPlayerId <= PLAYER_LAST") == 1) {
    __debugbreak();
  }
  this->m_pAIPlayerEvaluations.EvaluatePlayer(this->m_iCurrentPlayerId);
  g_pMsgTracer2->PushFormatedInts("Evaluating player %i", this->m_iCurrentPlayerId);
  return CAIAgent::ExecuteResult(0, 0);
}


// address=[0x1303be0]
// Decompiled from void __thiscall CAIAgentEvaluation::~CAIAgentEvaluation(CAIAgentEvaluation *this)
CAIAgentEvaluation::~CAIAgentEvaluation(void) = default;


// address=[0x1314030]
// Decompiled from void __thiscall CAIAgentEvaluation::Init(CAIAgentEvaluation *this)
void CAIAgentEvaluation::Init(void) {
  this->m_iCurrentPlayerId = 1;
}


