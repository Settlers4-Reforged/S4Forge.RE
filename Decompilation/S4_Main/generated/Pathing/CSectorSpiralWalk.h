#ifndef CSECTORSPIRALWALK_H
#define CSECTORSPIRALWALK_H

#include "defines.h"

class CSectorSpiralWalk {
public:
    // address=[0x13061f0]
     CSectorSpiralWalk(int a2, int a3, int a4, int a5);

    // address=[0x1306790]
    bool  NextXY(int & a2, int & a3);

};


#endif // CSECTORSPIRALWALK_H
