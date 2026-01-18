#ifndef CAIENEMYSETTLERINSECTORITERATOR_H
#define CAIENEMYSETTLERINSECTORITERATOR_H

#include "defines.h"

class CAIEnemySettlerInSectorIterator {
public:
    // address=[0x130d470]
     CAIEnemySettlerInSectorIterator(int a2, int a3, int a4);

    // address=[0x130d5e0]
    bool  NextEnemySettler(int & a2);

};


#endif // CAIENEMYSETTLERINSECTORITERATOR_H
