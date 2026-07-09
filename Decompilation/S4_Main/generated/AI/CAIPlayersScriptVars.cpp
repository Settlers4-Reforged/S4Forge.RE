#if FALSE
#include "CAIPlayersScriptVars.h"

// Definitions for class CAIPlayersScriptVars

// address=[0x12fcb40]
// Decompiled from CAIPlayerScriptVars *__thiscall CAIPlayersScriptVars::operator[](CAIPlayersScriptVars *this, unsigned int _iPlayerId)
class CAIPlayerScriptVars const &  CAIPlayersScriptVars::operator[](int _iPlayerId) {
  
  if ( _iPlayerId >= 9
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_Script.h",
         173,
         "static_cast<unsigned int>(_iPlayerId) < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return &this->m_vPlayers[_iPlayerId];
}


// address=[0x13038b0]
// Decompiled from int __thiscall CAIPlayersScriptVars::GetValue(CAIPlayersScriptVars *this, int _iPlayerId, int a3)
int  CAIPlayersScriptVars::GetValue(int _iPlayerId, enum T_AI_PLAYER_SCRIPT_VAR_INDEX a3) {
  
  if ( (_iPlayerId >= 9 || _iPlayerId < 0)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\ai\\AI_Script.h",
         229,
         "(_iPlayerId >= 0) & (_iPlayerId < PLAYER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return this->m_vPlayers[_iPlayerId].m_pActiveVars->m_iVars[a3];
}


// address=[0x1309870]
// Decompiled from void __thiscall CAIPlayersScriptVars::SetDifficultyLevel(CAIPlayersScriptVars *this, int a2, int a3)
void  CAIPlayersScriptVars::SetDifficultyLevel(int a2, enum T_AI_DIFFICULTY_LEVEL a3) {
  
  if ( a2 <= 8 && a2 >= 1 )
    CAIPlayerScriptVars::SetDifficultyLevel(&this->m_vPlayers[a2], a3);
}


// address=[0x131cce0]
// Decompiled from void __thiscall CAIPlayersScriptVars::Init(CAIPlayersScriptVars *this)
void  CAIPlayersScriptVars::Init(void) {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 9; ++i )
    CAIPlayerScriptVars::Init(&this->m_vPlayers[i]);
}


// address=[0x131cd20]
// Decompiled from void __thiscall CAIPlayersScriptVars::Load(CAIPlayersScriptVars *this, struct IS4Chunk *rChunk)
void  CAIPlayersScriptVars::Load(class IS4Chunk & rChunk) {
  
  signed int v2; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  rChunk->LoadSignature(-1516865760);
  v2 = rChunk->LoadUnsigned32(0, 9);
  for ( i = 0; i < v2; ++i )
    CAIPlayerScriptVars::Load(&this->m_vPlayers[i], rChunk);
  while ( i < 9 )
    CAIPlayerScriptVars::Init(&this->m_vPlayers[i++]);
}


// address=[0x131cdb0]
// Decompiled from void __thiscall CAIPlayersScriptVars::Save(CAIPlayersScriptVars *this, struct IS4Chunk *rChunk)
void  CAIPlayersScriptVars::Save(class IS4Chunk & rChunk) {
  
  int i; // [esp+4h] [ebp-4h]

  rChunk->SaveSignature(-1516865760);
  rChunk->SaveUnsigned32(9);
  for ( i = 0; i < 9; ++i )
    CAIPlayerScriptVars::Save(&this->m_vPlayers[i], rChunk);
}


// address=[0x131ebc0]
// Decompiled from void __thiscall CAIPlayersScriptVars::ClearFlagBits(CAIPlayersScriptVars *this, int _iPlayer, int _iFlags)
void  CAIPlayersScriptVars::ClearFlagBits(int _iPlayer, int _iFlags) {
  
  if ( _iPlayer <= 8 && _iPlayer >= 1 )
    this->m_vPlayers[_iPlayer].m_iFlags &= ~_iFlags;
}


// address=[0x131ecf0]
// Decompiled from void __thiscall CAIPlayersScriptVars::SetFlagBits(CAIPlayersScriptVars *this, int _iPlayer, int _iFlags)
void  CAIPlayersScriptVars::SetFlagBits(int _iPlayer, int _iFlags) {
  
  if ( _iPlayer <= 8 && _iPlayer >= 1 )
    this->m_vPlayers[_iPlayer].m_iFlags |= _iFlags;
}


// address=[0x131ed90]
// Decompiled from void __thiscall CAIPlayersScriptVars::SetOrClearFlagBits(  CAIPlayersScriptVars *this,  int iPlayer,  int _iFlags,  bool _bSet)
void  CAIPlayersScriptVars::SetOrClearFlagBits(int iPlayer, int _iFlags, bool _bSet) {
  
  if ( iPlayer <= 8 && iPlayer >= 1 )
  {
    if ( _bSet )
      this->m_vPlayers[iPlayer].m_iFlags |= _iFlags;
    else
      this->m_vPlayers[iPlayer].m_iFlags &= ~_iFlags;
  }
}


// address=[0x131eef0]
// Decompiled from void __thiscall CAIPlayersScriptVars::SetValue(  CAIPlayersScriptVars *this,  int _iPlayer,  int _iScriptVar,  int _iValueDiff1,  int _iValueDiff2,  int _iValueDiff3)
void  CAIPlayersScriptVars::SetValue(int _iPlayer, enum T_AI_PLAYER_SCRIPT_VAR_INDEX _iScriptVar, int _iValueDiff1, int _iValueDiff2, int _iValueDiff3) {
  
  if ( _iPlayer <= 8 && _iPlayer >= 1 )
  {
    this->m_vPlayers[_iPlayer].m_vVars[1].m_iVars[_iScriptVar] = _iValueDiff1;
    this->m_vPlayers[_iPlayer].m_vVars[2].m_iVars[_iScriptVar] = _iValueDiff2;
    this->m_vPlayers[_iPlayer].m_vVars[3].m_iVars[_iScriptVar] = _iValueDiff3;
  }
}


#endif // Already implemented
