#ifndef CAIPLAYERSCRIPTVARS_H
#define CAIPLAYERSCRIPTVARS_H

#include "defines.h"

class CAIPlayerScriptVars {
public:
    // address=[0x12fcaf0]
    int  operator[](enum T_AI_PLAYER_SCRIPT_VAR_INDEX _tVarIndex)const;

    // address=[0x1303840]
    int  Flags(void)const;

    // address=[0x1306500]
    enum T_AI_DIFFICULTY_LEVEL  DifficultyLevel(void)const;

protected:
    // address=[0x1309800]
    void  SetDifficultyLevel(enum T_AI_DIFFICULTY_LEVEL _tDifficultyLevel);

    // address=[0x131cad0]
    void  Init(void);

    // address=[0x131cb50]
    void  Load(class IS4Chunk & rChunk);

    // address=[0x131cc40]
    void  Save(class IS4Chunk & a2);

    // address=[0x131ed70]
    void  SetFlags(int _iFlags);

    // Type information members
public:
    int m_iDifficultyLevel;
    int m_iFlags;
    CAIPlayerScriptVars::SDifficultyVars * m_pActiveVars;
    CAIPlayerScriptVars::SDifficultyVars[4] m_vVars;

};


#endif // CAIPLAYERSCRIPTVARS_H
