#ifndef ANIMALS_H
#define ANIMALS_H

#include "DefineTransformers.h"

#define ANIMALS \
    X(0, ANIMAL_NO_ANIMAL) \
    X(1, ANIMAL_BOAR) \
    X(2, ANIMAL_DARKBUG) \
    X(3, ANIMAL_DARKBUGBIG) \
    X(4, ANIMAL_DEERFE) \
    X(5, ANIMAL_DEERMA) \
    X(6, ANIMAL_FOX) \
    X(7, ANIMAL_CHICKEN) \
    X(8, ANIMAL_JAGUAR) \
    X(9, ANIMAL_RABBIT) \
    X(10, ANIMAL_DOLPHIN) \
    X(11, ANIMAL_NESSY) \
    X(12, ANIMAL_SHARK) \
    X(13, ANIMAL_WILDBEAR) \
    X(14, ANIMAL_WOLF) \
    X(15, ANIMAL_FISH) \
    X(16, ANIMAL_RABBIT2) \
    X(17, ANIMAL_BULL)

#define X TO_ENUM

enum T_S4_ANIMAL {
    ANIMALS
};
#undef X

#define X TO_PAIR
SConfigTypeString s_sAnimalDefines[] = {
    ANIMALS
};
#undef X


#endif //ANIMALS_H
