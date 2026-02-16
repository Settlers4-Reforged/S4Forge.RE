#ifndef SPOINT_H
#define SPOINT_H

#include "defines.h"

class SPoint {
    typedef SPoint SPoint8;

public:
    // address=[0x15ddb00]
    SPoint &operator=(SPoint8 const & a2);

    // address=[0x15ddb40]
    bool  operator==(SPoint const & a2)const;

    // address=[0x15ddbb0]
    int  operator*(SPoint const & a2)const;

    // address=[0x15ddce0]
    int  X(void)const;

    // address=[0x15ddd00]
    int  Y(void)const;

    // address=[0x15ddd20]
    SPoint &  Zero(void);

    // Type information members
public:
    int x;
    int y;

};


#endif // SPOINT_H
