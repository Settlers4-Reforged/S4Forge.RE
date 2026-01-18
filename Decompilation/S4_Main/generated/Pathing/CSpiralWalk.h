#ifndef CSPIRALWALK_H
#define CSPIRALWALK_H

#include "defines.h"

class CSpiralWalk {
public:
    // address=[0x1306230]
     CSpiralWalk(int a2, int a3, int a4);

    // address=[0x1306800]
    bool  NextXY(int & a2, int & a3);

    // address=[0x1509f30]
    int  CurrentRadius(void)const;

};


#endif // CSPIRALWALK_H
