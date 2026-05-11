#ifndef RACES_H
#define RACES_H

#include "DefineTransformers.h"

#define RACES \
    X(0, ROMAN) \
    X(1, VIKING) \
    X(2, MAYA) \
    X(3, DARK) \
    X(4, TROJAN)

#define X(id, name) #name
const char *s_spRaceNames[] = {
    RACES
};
#undef X

#define X TO_ENUM

enum T_S4_RACE {
    RACES
};
#undef X

#endif //RACES_H
