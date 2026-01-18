#ifndef CAIPLAYERSCRIPTVARS_H
#define CAIPLAYERSCRIPTVARS_H

#include "defines.h"

class CAIPlayerScriptVars {
public:
    // address=[0x12fcaf0]
    int  operator[](enum T_AI_PLAYER_SCRIPT_VAR_INDEX a2)const;

    // address=[0x1303840]
    int  Flags(void)const;

    // address=[0x1306500]
    enum T_AI_DIFFICULTY_LEVEL  DifficultyLevel(void)const;

protected:
    // address=[0x1309800]
    void  SetDifficultyLevel(enum T_AI_DIFFICULTY_LEVEL a2);

    // address=[0x131cad0]
    void  Init(void);

    // address=[0x131cb50]
    void  Load(class IS4Chunk & a2);

    // address=[0x131cc40]
    void  Save(class IS4Chunk & a2);

    // address=[0x131ed70]
    void  SetFlags(int a2);

};


#endif // CAIPLAYERSCRIPTVARS_H
