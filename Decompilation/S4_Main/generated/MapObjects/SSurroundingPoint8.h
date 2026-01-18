#ifndef SSURROUNDINGPOINT8_H
#define SSURROUNDINGPOINT8_H

#include "defines.h"

class SSurroundingPoint8 {
public:
    // address=[0x132ee80]
    int  X(void)const;

    // address=[0x132eea0]
    int  Y(void)const;

    // address=[0x15ddca0]
    struct SPoint8 const &  Point(void)const;

    // address=[0x15ddcc0]
    int  Radius(void)const;

};


#endif // SSURROUNDINGPOINT8_H
