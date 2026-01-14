#ifndef CAIPLAYERSSCRIPTVARS_H
#define CAIPLAYERSSCRIPTVARS_H

class CAIPlayersScriptVars {
public:
    // address=[0x12fcb40]
    class CAIPlayerScriptVars const &  operator[](int);

    // address=[0x13038b0]
    int  GetValue(int,enum T_AI_PLAYER_SCRIPT_VAR_INDEX);

    // address=[0x1309870]
    void  SetDifficultyLevel(int,enum T_AI_DIFFICULTY_LEVEL);

    // address=[0x131cce0]
    void  Init(void);

    // address=[0x131cd20]
    void  Load(class IS4Chunk &);

    // address=[0x131cdb0]
    void  Save(class IS4Chunk &);

    // address=[0x131ebc0]
    void  ClearFlagBits(int,int);

    // address=[0x131ecf0]
    void  SetFlagBits(int,int);

    // address=[0x131ed90]
    void  SetOrClearFlagBits(int,int,bool);

    // address=[0x131eef0]
    void  SetValue(int,enum T_AI_PLAYER_SCRIPT_VAR_INDEX,int,int,int);

};


#endif // CAIPLAYERSSCRIPTVARS_H
