#ifndef CSETTLERSPIRALWALK_H
#define CSETTLERSPIRALWALK_H

#include "defines.h"

class CSettlerSpiralWalk {
public:
    // address=[0x1470530]
     CSettlerSpiralWalk(int a2, int a3, int a4);

    // address=[0x1470940]
    int  CurrentX(void)const;

    // address=[0x1470960]
    int  CurrentY(void)const;

    // address=[0x1513a40]
    bool  NextSettlerId(int & a2);

};


#endif // CSETTLERSPIRALWALK_H
