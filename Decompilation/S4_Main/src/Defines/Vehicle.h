#ifndef VEHICLE_H
#define VEHICLE_H

#include "DefineTransformers.h"

#define VEHICLES \
    X(6, VEHICLE_MAX)

#define X TO_ENUM

enum T_s4_VEHICLE {
    VEHICLES
};

#undef X

#endif // VEHICLE_H
