#include "CAIPlayersScriptVars.h"

// Definitions for class CAIPlayersScriptVars

// address=[0x12fcb40]
// Decompiled from char *__thiscall CAIPlayersScriptVars::operator[](char *this, unsigned int a2)
class CAIPlayerScriptVars const &  CAIPlayersScriptVars::operator[](int a2) {
  
  if ( a2 >= 9
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_Script.h",
         173,
         "static_cast<unsigned int>(_iPlayerId) < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return &this[380 * a2];
}


// address=[0x13038b0]
// Decompiled from int __thiscall CAIPlayersScriptVars::GetValue(_DWORD *this, int a2, int a3)
int  CAIPlayersScriptVars::GetValue(int a2, enum T_AI_PLAYER_SCRIPT_VAR_INDEX a3) {
  
  if ( (a2 >= 9 || a2 < 0)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_Script.h",
         229,
         "(_iPlayerId >= 0) & (_iPlayerId < PLAYER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return *(_DWORD *)(this[95 * a2 + 2] + 4 * a3);
}


// address=[0x1309870]
// Decompiled from unsigned int *__thiscall CAIPlayersScriptVars::SetDifficultyLevel(unsigned int *this, int a2, unsigned int a3)
void  CAIPlayersScriptVars::SetDifficultyLevel(int a2, enum T_AI_DIFFICULTY_LEVEL a3) {
  
  unsigned int *result; // eax

  result = (unsigned int *)(a2 <= 8 && a2 >= 1);
  if ( a2 <= 8 && a2 >= 1 )
    return CAIPlayerScriptVars::SetDifficultyLevel(&this[95 * a2], a3);
  return result;
}


// address=[0x131cce0]
// Decompiled from int __thiscall CAIPlayersScriptVars::Init(CAIPlayersScriptVars *this)
void  CAIPlayersScriptVars::Init(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 9; ++i )
  {
    CAIPlayerScriptVars::Init((CAIPlayersScriptVars *)((char *)this + 380 * i));
    result = i + 1;
  }
  return result;
}


// address=[0x131cd20]
// Decompiled from CAIPlayerScriptVars *__thiscall CAIPlayersScriptVars::Load(CAIPlayersScriptVars *this, struct IS4Chunk *a2)
void  CAIPlayersScriptVars::Load(class IS4Chunk & a2) {
  
  CAIPlayerScriptVars *result; // eax
  CAIPlayerScriptVars *v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, -1516865760);
  result = (CAIPlayerScriptVars *)(*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 9);
  v3 = result;
  for ( i = 0; i < (int)v3; ++i )
    result = (CAIPlayerScriptVars *)CAIPlayerScriptVars::Load((CAIPlayersScriptVars *)((char *)this + 380 * i), a2);
  while ( i < 9 )
    result = CAIPlayerScriptVars::Init((CAIPlayersScriptVars *)((char *)this + 380 * i++));
  return result;
}


// address=[0x131cdb0]
// Decompiled from int __thiscall CAIPlayersScriptVars::Save(CAIPlayersScriptVars *this, struct IS4Chunk *a2)
void  CAIPlayersScriptVars::Save(class IS4Chunk & a2) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, -1516865760);
  result = (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 9);
  for ( i = 0; i < 9; ++i )
    result = CAIPlayerScriptVars::Save((CAIPlayersScriptVars *)((char *)this + 380 * i), a2);
  return result;
}


// address=[0x131ebc0]
// Decompiled from CAIPlayersScriptVars *__fastcall CAIPlayersScriptVars::ClearFlagBits(  CAIPlayersScriptVars *this,  int a2,  int a3,  int a4)
void  CAIPlayersScriptVars::ClearFlagBits(int a2, int a3) {
  
  CAIPlayersScriptVars *result; // eax

  result = (CAIPlayersScriptVars *)(a3 <= 8 && a3 >= 1);
  if ( a3 > 8 || a3 < 1 )
    return result;
  result = this;
  *((_DWORD *)this + 95 * a3 + 1) &= ~a4;
  return result;
}


// address=[0x131ecf0]
// Decompiled from int __thiscall CAIPlayersScriptVars::SetFlagBits(CAIPlayersScriptVars *this, int a2, int a3)
void  CAIPlayersScriptVars::SetFlagBits(int a2, int a3) {
  
  int result; // eax

  result = a2 <= 8 && a2 >= 1;
  if ( a2 > 8 || a2 < 1 )
    return result;
  result = a3 | *((_DWORD *)this + 95 * a2 + 1);
  *((_DWORD *)this + 95 * a2 + 1) = result;
  return result;
}


// address=[0x131ed90]
// Decompiled from CAIPlayersScriptVars *__fastcall CAIPlayersScriptVars::SetOrClearFlagBits(  CAIPlayersScriptVars *this,  int a2,  int a3,  int a4,  bool a5)
void  CAIPlayersScriptVars::SetOrClearFlagBits(int a2, int a3, bool a4) {
  
  CAIPlayersScriptVars *result; // eax

  result = (CAIPlayersScriptVars *)(a3 <= 8 && a3 >= 1);
  if ( a3 > 8 || a3 < 1 )
    return result;
  result = this;
  if ( a5 )
    *((_DWORD *)this + 95 * a3 + 1) |= a4;
  else
    *((_DWORD *)this + 95 * a3 + 1) &= ~a4;
  return result;
}


// address=[0x131eef0]
// Decompiled from BOOL __thiscall CAIPlayersScriptVars::SetValue(_DWORD *this, int a2, BOOL a3, int a4, int a5, int a6)
void  CAIPlayersScriptVars::SetValue(int a2, enum T_AI_PLAYER_SCRIPT_VAR_INDEX a3, int a4, int a5, int a6) {
  
  BOOL result; // eax

  result = a2 <= 8 && a2 >= 1;
  if ( a2 > 8 || a2 < 1 )
    return result;
  this[95 * a2 + 26 + a3] = a4;
  this[95 * a2 + 49 + a3] = a5;
  result = a3;
  this[95 * a2 + 72 + a3] = a6;
  return result;
}


