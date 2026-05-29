#ifndef ICARGOCOUNTER_H
#define ICARGOCOUNTER_H

#include "defines.h"

class ICargoCounter {
public:
    // address=[0x160d960]
    ICargoCounter(void);

    virtual void CountEntity(int a2, int _iCargoType) = 0;
};


#endif // ICARGOCOUNTER_H
