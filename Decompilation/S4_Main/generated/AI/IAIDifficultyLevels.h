#ifndef IAIDIFFICULTYLEVELS_H
#define IAIDIFFICULTYLEVELS_H

#include "defines.h"

class IAIDifficultyLevels {
public:
    // address=[0x1309710]
    static enum T_AI_DIFFICULTY_LEVEL __cdecl GetDifficultyLevel(int a1);

    // address=[0x1309780]
    void  SetDifficultyLevel(int a1, enum T_AI_DIFFICULTY_LEVEL a2);

};


#endif // IAIDIFFICULTYLEVELS_H
