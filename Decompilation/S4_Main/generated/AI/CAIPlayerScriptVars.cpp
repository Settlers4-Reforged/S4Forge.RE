#include "all_headers.h"

// Definitions for class CAIPlayerScriptVars

// address=[0x12fcaf0]
// Decompiled from int __thiscall CAIPlayerScriptVars::operator[](_DWORD *this, unsigned int a2)
int  CAIPlayerScriptVars::operator[](enum T_AI_PLAYER_SCRIPT_VAR_INDEX)const {
  
  if ( a2 > 0x16
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_Script.h",
         107,
         "static_cast<unsigned int>(_tVarIndex) <= AI_PLAYER_SCRIPT_VAR_LAST") == 1 )
  {
    __debugbreak();
  }
  return *(_DWORD *)(this[2] + 4 * a2);
}


// address=[0x1303840]
// Decompiled from int __thiscall CAIPlayerScriptVars::Flags(CAIPlayerScriptVars *this)
int  CAIPlayerScriptVars::Flags(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x1306500]
// Decompiled from int __thiscall CAIPlayerScriptVars::DifficultyLevel(void *this)
enum T_AI_DIFFICULTY_LEVEL  CAIPlayerScriptVars::DifficultyLevel(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x1309800]
// Decompiled from unsigned int *__thiscall CAIPlayerScriptVars::SetDifficultyLevel(unsigned int *this, unsigned int a2)
void  CAIPlayerScriptVars::SetDifficultyLevel(enum T_AI_DIFFICULTY_LEVEL) {
  
  unsigned int *result; // eax

  if ( a2 > 3
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_Script.h",
         138,
         "static_cast<unsigned int>(_tDifficultyLevel) <= AI_DIFFICULTY_LEVEL_LAST") == 1 )
  {
    __debugbreak();
  }
  *this = a2;
  result = this;
  this[2] = (unsigned int)&this[23 * a2 + 3];
  return result;
}


// address=[0x131cad0]
// Decompiled from CAIPlayerScriptVars *__thiscall CAIPlayerScriptVars::Init(CAIPlayerScriptVars *this)
void  CAIPlayerScriptVars::Init(void) {
  
  CAIPlayerScriptVars *result; // eax
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  CAIPlayerScriptVars::SetDifficultyLevel((unsigned int *)this, 2u);
  result = this;
  *((_DWORD *)this + 1) = 0;
  for ( i = 0; i <= 3; ++i )
  {
    for ( j = 0; j <= 22; ++j )
    {
      result = (CAIPlayerScriptVars *)dword_3ECC7C8[23 * i + j];
      *((_DWORD *)this + 23 * i + j + 3) = result;
    }
  }
  return result;
}


// address=[0x131cb50]
// Decompiled from int __thiscall CAIPlayerScriptVars::Load(CAIPlayerScriptVars *this, struct IS4Chunk *a2)
void  CAIPlayerScriptVars::Load(class IS4Chunk &) {
  
  int result; // eax
  int v3; // [esp+4h] [ebp-18h]
  int v4; // [esp+8h] [ebp-14h]
  unsigned int v5; // [esp+Ch] [ebp-10h]
  int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  v5 = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 3);
  v4 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  CAIPlayerScriptVars::SetDifficultyLevel((unsigned int *)this, v5);
  CAIPlayerScriptVars::SetFlags(this, v4);
  result = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, int))(*(_DWORD *)a2 + 4))(a2, 0, 22);
  v3 = result;
  for ( i = 0; i <= 3; ++i )
  {
    for ( j = 0; ; ++j )
    {
      result = j;
      if ( j > v3 )
        break;
      *((_DWORD *)this + 23 * i + j + 3) = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    }
    while ( j <= 22 )
    {
      *((_DWORD *)this + 23 * i + j + 3) = dword_3ECC7C8[23 * i + j];
      result = ++j;
    }
  }
  return result;
}


// address=[0x131cc40]
// Decompiled from int __thiscall CAIPlayerScriptVars::Save(CAIPlayerScriptVars *this, struct IS4Chunk *a2)
void  CAIPlayerScriptVars::Save(class IS4Chunk &) {
  
  int result; // eax
  int j; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *(_DWORD *)this);
  (*(void (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(a2, *((_DWORD *)this + 1));
  result = (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, 22);
  for ( i = 0; i <= 3; ++i )
  {
    for ( j = 0; j <= 22; ++j )
      result = (*(int (__thiscall **)(struct IS4Chunk *, _DWORD))(*(_DWORD *)a2 + 20))(
                 a2,
                 *((_DWORD *)this + 23 * i + j + 3));
  }
  return result;
}


// address=[0x131ed70]
// Decompiled from CAIPlayerScriptVars *__thiscall CAIPlayerScriptVars::SetFlags(CAIPlayerScriptVars *this, int a2)
void  CAIPlayerScriptVars::SetFlags(int) {
  
  CAIPlayerScriptVars *result; // eax

  result = this;
  *((_DWORD *)this + 1) = a2;
  return result;
}


