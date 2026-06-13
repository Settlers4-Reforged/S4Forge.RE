#ifndef GAME_H
#define GAME_H

#include "DefineTransformers.h"

#define GAMETYPES               \
    X(0, GAMETYPE_NONE)         \
    X(1, GAMETYPE_SINGLEPLAYER) \
    X(2, GAMETYPE_MULTIPLAYER)  \
    X(3, GAMETYPE_CAMPAIGN)     \
    X(4, GAMETYPE_TUTORIAL)     \
    X(5, GAMETYPE_MAX)

#define MAP_MODES          \
    X(0, MODE_NONE)        \
    X(1, MODE_CONFLICT)    \
    X(2, MODE_COOP)        \
    X(3, MODE_NOT_FOUND_3) \
    X(4, MODE_NOT_FOUND_4) \
    X(5, MODE_NOT_FOUND_5) \
    X(6, MODE_NOT_FOUND_6)

#define X TO_ENUM

enum T_S4_GAMETYPE {
    GAMETYPES
};

enum T_S4_MODE {
    MAP_MODES MODE_MAX
};

#undef X

#endif // GAME_H
