#ifndef CONESETTLERTYPEITERATOR_H
#define CONESETTLERTYPEITERATOR_H

#include "defines.h"

class COneSettlerTypeIterator {
public:
    // address=[0x13037c0]
     COneSettlerTypeIterator(int a2, int a3);

    // address=[0x13150d0]
    void  Init(int a2, int a3);

    // address=[0x1315100]
    int  FirstSettler(void);

    // address=[0x1315130]
    int  NextSettler(void);

    // address=[0x1315180]
    int  NextSettlerIfCurrentIsNotValid(void);

    // address=[0x1317270]
     COneSettlerTypeIterator(void);

};


#endif // CONESETTLERTYPEITERATOR_H
