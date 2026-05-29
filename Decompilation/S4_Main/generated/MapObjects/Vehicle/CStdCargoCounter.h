#ifndef CSTDCARGOCOUNTER_H
#define CSTDCARGOCOUNTER_H

#include "defines.h"

class CStdCargoCounter : public ICargoCounter {
public:
    // address=[0x15a3ad0]
    void  Clear(void);

    // address=[0x15a3af0]
    virtual void  CountEntity(int a2, int _iCargoType);

    // address=[0x160d8f0]
     CStdCargoCounter(void);

    // Type information members
public:
    int[10] m_aCounters;

};


#endif // CSTDCARGOCOUNTER_H
