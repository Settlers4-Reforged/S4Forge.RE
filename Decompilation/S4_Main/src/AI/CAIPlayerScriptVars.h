#ifndef CAIPLAYERSCRIPTVARS_H
#define CAIPLAYERSCRIPTVARS_H

#include "CAIConfigIntEx.h"
#include "Defines/AI.h"
#include "defines.h"

extern int s_iDefaultScriptVars[4][23];
extern struct SPlayerScriptVar s_sDefaultScriptVars[23];

class CAIPlayerScriptVars {
  public:
    // address=[0x12fcaf0]
    int operator[](T_AI_PLAYER_SCRIPT_VAR_INDEX _tVarIndex) const;

    // address=[0x1303840]
    int Flags(void) const;

    // address=[0x1306500]
    T_AI_DIFFICULTY_LEVEL DifficultyLevel(void) const;

  protected:
    friend class CAIPlayersScriptVars;

    // address=[0x1309800]
    void SetDifficultyLevel(T_AI_DIFFICULTY_LEVEL _tDifficultyLevel);

    // address=[0x131cad0]
    void Init(void);

    // address=[0x131cb50]
    void Load(class IS4Chunk &rChunk);

    // address=[0x131cc40]
    void Save(class IS4Chunk &a2);

    // address=[0x131ed70]
    void SetFlags(int _iFlags);

    // Type information members
  public:
    struct SDifficultyVars {
        int m_iVars[23];
    };

    T_AI_DIFFICULTY_LEVEL m_iDifficultyLevel;
    int m_iFlags;
    SDifficultyVars *m_pActiveVars;
    SDifficultyVars m_vVars[4];
};

struct SPlayerScriptVar {
    CAIConfigIntEx *m_pConfig;
    int m_iMin;
    int m_iMax;
};

#endif // CAIPLAYERSCRIPTVARS_H
