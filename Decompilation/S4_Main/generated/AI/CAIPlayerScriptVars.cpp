#if FALSE
#include "CAIPlayerScriptVars.h"

// Definitions for class CAIPlayerScriptVars

// address=[0x12fcaf0]
// Decompiled from int __thiscall CAIPlayerScriptVars::operator[](CAIPlayerScriptVars *this, unsigned int _tVarIndex)
int  CAIPlayerScriptVars::operator[](enum T_AI_PLAYER_SCRIPT_VAR_INDEX _tVarIndex)const {
  
  if ( _tVarIndex > 22
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_Script.h",
         107,
         "static_cast<unsigned int>(_tVarIndex) <= AI_PLAYER_SCRIPT_VAR_LAST") == 1 )
  {
    __debugbreak();
  }
  return this->m_pActiveVars->m_iVars[_tVarIndex];
}


// address=[0x1303840]
// Decompiled from int __thiscall CAIPlayerScriptVars::Flags(CAIPlayerScriptVars *this)
int  CAIPlayerScriptVars::Flags(void)const {
  
  return this->m_iFlags;
}


// address=[0x1306500]
// Decompiled from int __thiscall CAIPlayerScriptVars::DifficultyLevel(CAIPlayerScriptVars *this)
enum T_AI_DIFFICULTY_LEVEL  CAIPlayerScriptVars::DifficultyLevel(void)const {
  
  return this->m_iDifficultyLevel;
}


// address=[0x1309800]
// Decompiled from void __thiscall CAIPlayerScriptVars::SetDifficultyLevel(CAIPlayerScriptVars *this, int _tDifficultyLevel)
void  CAIPlayerScriptVars::SetDifficultyLevel(enum T_AI_DIFFICULTY_LEVEL _tDifficultyLevel) {
  
  if ( (unsigned int)_tDifficultyLevel > 3
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_Script.h",
         138,
         "static_cast<unsigned int>(_tDifficultyLevel) <= AI_DIFFICULTY_LEVEL_LAST") == 1 )
  {
    __debugbreak();
  }
  this->m_iDifficultyLevel = _tDifficultyLevel;
  this->m_pActiveVars = &this->m_vVars[_tDifficultyLevel];
}


// address=[0x131cad0]
// Decompiled from void __thiscall CAIPlayerScriptVars::Init(CAIPlayerScriptVars *this)
void  CAIPlayerScriptVars::Init(void) {
  
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  CAIPlayerScriptVars::SetDifficultyLevel(this, 2);
  this->m_iFlags = 0;
  for ( i = 0; i <= 3; ++i )
  {
    for ( j = 0; j <= 22; ++j )
      this->m_vVars[i].m_iVars[j] = s_iDefaultScriptVars[i][j];
  }
}


// address=[0x131cb50]
// Decompiled from void __thiscall CAIPlayerScriptVars::Load(CAIPlayerScriptVars *this, struct IS4Chunk *rChunk)
void  CAIPlayerScriptVars::Load(class IS4Chunk & rChunk) {
  
  signed int iAvailableVars; // [esp+4h] [ebp-18h]
  int iFlags; // [esp+8h] [ebp-14h]
  int iDifficultyLevel; // [esp+Ch] [ebp-10h]
  int i; // [esp+14h] [ebp-8h]
  int j; // [esp+18h] [ebp-4h]

  iDifficultyLevel = rChunk->LoadUnsigned32(0, 3);
  iFlags = rChunk->LoadUnsigned32_(rChunk);
  CAIPlayerScriptVars::SetDifficultyLevel(this, iDifficultyLevel);
  CAIPlayerScriptVars::SetFlags(this, iFlags);
  iAvailableVars = rChunk->LoadUnsigned32(0, 22);
  for ( i = 0; i <= 3; ++i )
  {
    for ( j = 0; j <= iAvailableVars; ++j )
      this->m_vVars[i].m_iVars[j] = rChunk->LoadUnsigned32_(rChunk);
    while ( j <= 22 )
    {
      this->m_vVars[i].m_iVars[j] = s_iDefaultScriptVars[i][j];
      ++j;
    }
  }
}


// address=[0x131cc40]
// Decompiled from void __thiscall CAIPlayerScriptVars::Save(CAIPlayerScriptVars *this, struct IS4Chunk *a2)
void  CAIPlayerScriptVars::Save(class IS4Chunk & a2) {
  
  int j; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  a2->SaveUnsigned32(this->m_iDifficultyLevel);
  a2->SaveUnsigned32(this->m_iFlags);
  a2->SaveUnsigned32(22);
  for ( i = 0; i <= 3; ++i )
  {
    for ( j = 0; j <= 22; ++j )
      a2->SaveUnsigned32(this->m_vVars[i].m_iVars[j]);
  }
}


// address=[0x131ed70]
// Decompiled from void __thiscall CAIPlayerScriptVars::SetFlags(CAIPlayerScriptVars *this, int _iFlags)
void  CAIPlayerScriptVars::SetFlags(int _iFlags) {
  
  this->m_iFlags = _iFlags;
}


#endif // Already implemented
