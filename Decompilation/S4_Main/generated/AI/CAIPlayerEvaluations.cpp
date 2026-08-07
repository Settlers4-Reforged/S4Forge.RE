#if FALSE
#include "CAIPlayerEvaluations.h"

// Definitions for class CAIPlayerEvaluations

// address=[0x1303c50]
// Decompiled from void __thiscall CAIPlayerEvaluations::EvaluatePlayer(CAIPlayerEvaluations *this, DWORD a2)
void  CAIPlayerEvaluations::EvaluatePlayer(int a2) {
  
  CAIPlayerEvaluation::EvaluatePlayer(&this->m_sPlayerEvaluations[a2], a2);
}


// address=[0x1311500]
// Decompiled from int __thiscall CAIPlayerEvaluations::Clear(CAIPlayerEvaluations *this)
void  CAIPlayerEvaluations::Clear(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0;
        i < 9;
        ++i )
  {
    CAIPlayerEvaluation::Clear(&this->m_sPlayerEvaluations[i]);
    result = i + 1;
  }
  return result;
}


// address=[0x1311540]
// Decompiled from void __thiscall CAIPlayerEvaluations::EvaluateAllPlayers(CAIPlayerEvaluations *this)
void  CAIPlayerEvaluations::EvaluateAllPlayers(void) {
  
  int PlayerId; // [esp+0h] [ebp-Ch]
  signed int i; // [esp+8h] [ebp-4h]

  CAIPlayerEvaluations::Clear(this);
  PlayerId = IAIEnvironment::AlliancesLastPlayerId();
  for ( i = 1;
        i <= PlayerId;
        ++i )
  {
    CAIPlayerEvaluations::EvaluatePlayer(this, i);
  }
}


// address=[0x1311590]
// Decompiled from void __thiscall CAIPlayerEvaluations::DbgPrint(CAIPlayerEvaluation *this)
void  CAIPlayerEvaluations::DbgPrint(void) {
  
  int PlayerId; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  PlayerId = IAIEnvironment::AlliancesLastPlayerId();
  for ( i = 1;
        i <= PlayerId;
        ++i )
  {
    IAIEnvironment::DbgTracePrintF(byte_367348D);
    IAIEnvironment::DbgTracePrintF("Player %i evaluation...", i);
    CAIPlayerEvaluation::DbgPrint(&this[i]);
  }
}


#endif // Already implemented
