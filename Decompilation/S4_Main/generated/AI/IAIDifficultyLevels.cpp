#include "IAIDifficultyLevels.h"

// Definitions for class IAIDifficultyLevels

// address=[0x1309710]
// Decompiled from int __cdecl IAIDifficultyLevels::GetDifficultyLevel(int a1)
enum T_AI_DIFFICULTY_LEVEL __cdecl IAIDifficultyLevels::GetDifficultyLevel(int a1) {
  
  int v1; // ecx
  void *v2; // eax
  int v4; // [esp+0h] [ebp-4h]

  if ( !(*(unsigned __int8 (__thiscall **)(void *, int, int))(*(_DWORD *)g_pAI + 40))(g_pAI, a1, v1) )
    return 0;
  v2 = (void *)CAIPlayersScriptVars::operator[](a1);
  v4 = CAIPlayerScriptVars::DifficultyLevel(v2);
  if ( !v4
    && BBSupportDbgReport(2, (int)"AI\\AI_DifficultyLevel.cpp", 32, (int)"tDifficultyLevel != AI_DIFFICULTY_LEVEL_NONE") == 1 )
  {
    __debugbreak();
  }
  return v4;
}


// address=[0x1309780]
// Decompiled from unsigned int *__stdcall IAIDifficultyLevels::SetDifficultyLevel(int a1, unsigned int a2)
void  IAIDifficultyLevels::SetDifficultyLevel(int a1, enum T_AI_DIFFICULTY_LEVEL a2) {
  
  unsigned int *result; // eax

  if ( !a2 && BBSupportDbgReport(2, aAiAiDifficulty_0, 50, "_tDifficultyLevel != AI_DIFFICULTY_LEVEL_NONE") == 1 )
    __debugbreak();
  result = 0;
  if ( a2 )
    return CAIPlayersScriptVars::SetDifficultyLevel(g_cAIPlayersScriptVars, a1, a2);
  return result;
}


