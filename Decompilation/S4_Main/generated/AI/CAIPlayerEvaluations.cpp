#include "all_headers.h"

// Definitions for class CAIPlayerEvaluations

// address=[0x1303c50]
// Decompiled from void __thiscall CAIPlayerEvaluations::EvaluatePlayer(CAIPlayerEvaluations *this, int a2)
void  CAIPlayerEvaluations::EvaluatePlayer(int) {
  
  CAIPlayerEvaluation::EvaluatePlayer((CAIPlayerEvaluations *)((char *)this + 88 * a2), a2);
}


// address=[0x1311500]
// Decompiled from int __thiscall CAIPlayerEvaluations::Clear(CAIPlayerEvaluations *this)
void  CAIPlayerEvaluations::Clear(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 9; ++i )
  {
    CAIPlayerEvaluation::Clear((CAIPlayerEvaluations *)((char *)this + 88 * i));
    result = i + 1;
  }
  return result;
}


// address=[0x1311540]
// Decompiled from int __thiscall CAIPlayerEvaluations::EvaluateAllPlayers(CAIPlayerEvaluations *this)
void  CAIPlayerEvaluations::EvaluateAllPlayers(void) {
  
  int result; // eax
  int v2; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  CAIPlayerEvaluations::Clear(this);
  result = IAIEnvironment::AlliancesLastPlayerId();
  v2 = result;
  for ( i = 1; i <= v2; ++i )
  {
    CAIPlayerEvaluations::EvaluatePlayer(this, i);
    result = i + 1;
  }
  return result;
}


// address=[0x1311590]
// Decompiled from int __thiscall CAIPlayerEvaluations::DbgPrint(char *this)
void  CAIPlayerEvaluations::DbgPrint(void) {
  
  int result; // eax
  int v3; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  result = IAIEnvironment::AlliancesLastPlayerId();
  v3 = result;
  for ( i = 1; i <= v3; ++i )
  {
    IAIEnvironment::DbgTracePrintF(byte_367348D);
    IAIEnvironment::DbgTracePrintF("Player %i evaluation...", i);
    CAIPlayerEvaluation::DbgPrint((CAIPlayerEvaluation *)&this[88 * i]);
    result = i + 1;
  }
  return result;
}


