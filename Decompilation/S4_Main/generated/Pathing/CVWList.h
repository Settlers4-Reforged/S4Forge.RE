#ifndef CVWLIST_H
#define CVWLIST_H

#include "defines.h"

class CVWList {
public:
    // address=[0x1334ec0]
     CVWList(int a2, int a3, int a4);

    // address=[0x1335b10]
    struct SVW const &  CVWList::operator[](int a2)const;

    // address=[0x1336840]
    int  Size(void)const;

    // address=[0x15de830]
    void  CalculateOverlappingSquares(int a2, int a3, int a4);

protected:
    // address=[0x15e2cf0]
    void  PushEx(int & a2, int a3, int a4);

};


#endif // CVWLIST_H
