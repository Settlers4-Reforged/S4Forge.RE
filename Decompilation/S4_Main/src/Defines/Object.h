#ifndef OBJECT_H
#define OBJECT_H

#include "DefineTransformers.h"

#define OBJECT_TYPES \
    X(0, NONE_OBJ) \
    X(1, SETTLER_OBJ) \
    X(2, SHIP_OBJ) \
    X(4, CATAPULT_OBJ) \
    X(8, BUILDING_OBJ) \
    X(16, PILE_OBJ) \
    X(32, UNKNOWN_OBJ) \
    X(64, DECO_OBJ)


#define X TO_ENUM

enum T_SETTLER_OBJ_TYPE {
    OBJECT_TYPES
};

#undef X

#endif //OBJECT_H
