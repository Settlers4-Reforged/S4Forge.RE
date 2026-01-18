#ifndef CRANDOM16_H
#define CRANDOM16_H

#include "defines.h"

class CRandom16 {
public:
    // address=[0x12fd540]
    unsigned int  Rand(void);

    // address=[0x1301600]
    static unsigned int __cdecl PercentValue(unsigned int);

    // address=[0x130a490]
    unsigned int  GetNumberOfRandCalls(void)const;

    // address=[0x1311d70]
    unsigned int  GetSeed(void)const;

    // address=[0x13613b0]
     CRandom16(unsigned int);

};


#endif // CRANDOM16_H
