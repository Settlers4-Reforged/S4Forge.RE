#ifndef CAIBUILDINGENSIGNPOSITIONITERATOR_H
#define CAIBUILDINGENSIGNPOSITIONITERATOR_H

#include "defines.h"

class CAIBuildingEnsignPositionIterator {
public:
    // address=[0x130d390]
     CAIBuildingEnsignPositionIterator(int a2, int a3);

    // address=[0x130d3c0]
    bool  NextXY(int & a2, int & a3);

    // address=[0x130d420]
    bool  NextWorldIdx(int & a2);

};


#endif // CAIBUILDINGENSIGNPOSITIONITERATOR_H
