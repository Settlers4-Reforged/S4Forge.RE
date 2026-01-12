#ifndef IAIDIFFICULTYLEVELS_H
#define IAIDIFFICULTYLEVELS_H

class IAIDifficultyLevels {
public:
    // address=[0x1309710]
    static enum T_AI_DIFFICULTY_LEVEL __cdecl GetDifficultyLevel(int);

    // address=[0x1309780]
    void  SetDifficultyLevel(int,enum T_AI_DIFFICULTY_LEVEL);

};


#endif // IAIDIFFICULTYLEVELS_H
