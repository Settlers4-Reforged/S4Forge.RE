#ifndef RACES_H
#define RACES_H

#include "DefineTransformers.h"

const char *s_spRaceNames[] = {
    "ROMAN",
    "VIKING",
    "MAYA",
    "DARK",
    "TROJAN",
};

#define RACES \
X(0, RACE_ROMAN) \
X(1, RACE_VIKING) \
X(2, RACE_MAYA) \
X(3, RACE_DARK) \
X(4, RACE_TROJAN)


#define X TO_ENUM

enum T_S4_RACE {
    RACE_FIRST = 0,
    RACES
    RACE_MAX
};
#undef X

#endif //RACES_H
