
#ifndef ROLES_H
#define ROLES_H

#include "DefineTransformers.h"

#define ROLES                  \
    X(1, CARRIER_ROLE)         \
    X(2, DIGGER_ROLE)          \
    X(3, BUILDER_ROLE)         \
    X(4, HOUSE_WORKER_ROLE)    \
    X(5, FREE_WORKER_ROLE)     \
    X(6, PLANTER_ROLE)         \
    X(7, SOLDIER_ROLE)         \
    X(8, HUNTER_ROLE)          \
    X(9, PRIEST_ROLE)          \
    X(10, SABOTEUR_ROLE)       \
    X(11, PIONEER_ROLE)        \
    X(12, GEOLOGIST_ROLE)      \
    X(13, GARDENER_ROLE)       \
    X(14, DARK_GARDENER_ROLE)  \
    X(15, MUSHROOMFARMER_ROLE) \
    X(16, SHAMAN_ROLE)         \
    X(17, SLAVE_ROLE)          \
    X(18, FLEE_ROLE)           \
    X(19, THIEF_ROLE)          \
    X(20, DONKEY_ROLE)         \
    X(21, DOOR_ROLE)           \
    X(22, TOWER_SOLDIER_ROLE)  \
    X(23, SQUAD_LEADER_ROLE)   \
    X(24, HJB_ROLE)

#define OBSERVER_TARGETS                                                 \
    X(0, OBSERVER_TARGET_PRIMARY)                                        \
    X(1, OBSERVER_TARGET_SECONDARY) /*SECONDARY naming is just a guess*/ \
    X(2, OBSERVER_TARGET_PILE_SRC)                                       \
    X(3, OBSERVER_TARGET_PILE_SRC_2)                                     \
    X(4, OBSERVER_TARGET_PILE_SRC_3)

#define X TO_ENUM

enum T_S4_ROLE {
    ROLES
};

enum T_OBSERVER_TARGET {
    OBSERVER_TARGETS
};

#undef X

#endif // ROLES_H
