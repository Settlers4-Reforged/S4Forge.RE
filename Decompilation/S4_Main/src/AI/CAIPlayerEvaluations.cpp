#include "CAIPlayerEvaluations.h"

#include <AI/IAIEnvironment.h>

#include "Defines/Players.h"

// Definitions for class CAIPlayerEvaluations

// address=[0x1303c50]
// Decompiled from void __thiscall CAIPlayerEvaluations::EvaluatePlayer(CAIPlayerEvaluation *this, DWORD a2)
void CAIPlayerEvaluations::EvaluatePlayer(int a2) {
  this->m_sPlayerEvaluations[a2].EvaluatePlayer(a2);
}


// address=[0x1311500]
// Decompiled from int __thiscall CAIPlayerEvaluations::Clear(CAIPlayerEvaluations *this)
void CAIPlayerEvaluations::Clear(void) {
  for(auto &m_sPlayerEvaluation: this->m_sPlayerEvaluations) {
    m_sPlayerEvaluation.Clear();
  }
}


// address=[0x1311540]
// Decompiled from void __thiscall CAIPlayerEvaluations::EvaluateAllPlayers(CAIPlayerEvaluations *this)
void CAIPlayerEvaluations::EvaluateAllPlayers(void) {
  this->Clear();
  int PlayerId = IAIEnvironment::AlliancesLastPlayerId();
  for(signed int i = PLAYER_FIRST; i <= PlayerId; ++i)
    this->EvaluatePlayer(i);
}


// address=[0x1311590]
// Decompiled from void __thiscall CAIPlayerEvaluations::DbgPrint(CAIPlayerEvaluation *this)
void CAIPlayerEvaluations::DbgPrint(void) {
  int PlayerId = IAIEnvironment::AlliancesLastPlayerId();
  for(int i = 1; i <= PlayerId; ++i) {
    IAIEnvironment::DbgTracePrintF("");
    IAIEnvironment::DbgTracePrintF("Player %i evaluation...", i);
    this->m_sPlayerEvaluations[i].DbgPrint();
  }
}


