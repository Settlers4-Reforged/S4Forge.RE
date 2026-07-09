#ifndef CAIPLAYERSSCRIPTVARS_H
#define CAIPLAYERSSCRIPTVARS_H

#include "CAIPlayerScriptVars.h"
#include "defines.h"

extern class CAIPlayersScriptVars g_cAIPlayersScriptVars;

class CAIPlayersScriptVars {
  public:
    // address=[0x12fcb40]
    CAIPlayerScriptVars const &operator[](int _iPlayerId);

    // address=[0x13038b0]
    int GetValue(int _iPlayerId, enum T_AI_PLAYER_SCRIPT_VAR_INDEX a3);

    // address=[0x1309870]
    void SetDifficultyLevel(int a2, enum T_AI_DIFFICULTY_LEVEL a3);

    // address=[0x131cce0]
    void Init(void);

    // address=[0x131cd20]
    void Load(class IS4Chunk &rChunk);

    // address=[0x131cdb0]
    void Save(class IS4Chunk &rChunk);

    // address=[0x131ebc0]
    void ClearFlagBits(int _iPlayer, int _iFlags);

    // address=[0x131ecf0]
    void SetFlagBits(int _iPlayer, int _iFlags);

    // address=[0x131ed90]
    void SetOrClearFlagBits(int iPlayer, int _iFlags, bool _bSet);

    // address=[0x131eef0]
    void SetValue(int _iPlayer, enum T_AI_PLAYER_SCRIPT_VAR_INDEX _iScriptVar, int _iValueDiff1, int _iValueDiff2, int _iValueDiff3);

    // Type information members
  public:
    CAIPlayerScriptVars m_vPlayers[9];
};

#endif // CAIPLAYERSSCRIPTVARS_H
