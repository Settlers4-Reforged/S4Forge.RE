#ifndef CGENERICSETTLERITERATOR_H
#define CGENERICSETTLERITERATOR_H

#include "defines.h"

class CGenericSettlerIterator {
public:
    // address=[0x1315360]
    bool  Init(int a2, int a3, int a4);

    // address=[0x13153d0]
    int  FirstSettler(void);

    // address=[0x1315450]
    int  NextSettler(void);

    // address=[0x1315520]
    int  NextSettlerIfCurrentIsNotValid(void);

    // address=[0x1315560]
    int  NextSettlerOrFirstIfCurrentIsEndOfList(void);

    // address=[0x13171b0]
     CGenericSettlerIterator(void);

};


#endif // CGENERICSETTLERITERATOR_H
