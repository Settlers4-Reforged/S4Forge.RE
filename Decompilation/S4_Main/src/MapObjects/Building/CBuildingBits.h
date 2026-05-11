#ifndef CBUILDINGBITS_H
#define CBUILDINGBITS_H

#include "defines.h"

class CBuildingBits {
public:
    // address=[0x14f1a80]
    void PrintToTraceFile(unsigned int a2);

    // address=[0x14f3590]
    CBuildingBits(void);

    // Type information members
public:
    BYTE m_iBits[80][80];
};


#endif // CBUILDINGBITS_H
