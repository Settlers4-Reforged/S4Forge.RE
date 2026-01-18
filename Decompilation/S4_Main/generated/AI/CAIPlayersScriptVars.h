#ifndef CAIPLAYERSSCRIPTVARS_H
#define CAIPLAYERSSCRIPTVARS_H

#include "defines.h"

class CAIPlayersScriptVars {
public:
    // address=[0x12fcb40]
    class CAIPlayerScriptVars const &  operator[](int a2);

    // address=[0x13038b0]
    int  GetValue(int a2, enum T_AI_PLAYER_SCRIPT_VAR_INDEX a3);

    // address=[0x1309870]
    void  SetDifficultyLevel(int a2, enum T_AI_DIFFICULTY_LEVEL a3);

    // address=[0x131cce0]
    void  Init(void);

    // address=[0x131cd20]
    void  Load(class IS4Chunk & a2);

    // address=[0x131cdb0]
    void  Save(class IS4Chunk & a2);

    // address=[0x131ebc0]
    void  ClearFlagBits(int a2, int a3);

    // address=[0x131ecf0]
    void  SetFlagBits(int a2, int a3);

    // address=[0x131ed90]
    void  SetOrClearFlagBits(int a2, int a3, bool a4);

    // address=[0x131eef0]
    void  SetValue(int a2, enum T_AI_PLAYER_SCRIPT_VAR_INDEX a3, int a4, int a5, int a6);

};


#endif // CAIPLAYERSSCRIPTVARS_H
