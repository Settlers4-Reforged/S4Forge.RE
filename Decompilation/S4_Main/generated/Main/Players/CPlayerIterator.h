#ifndef CPLAYERITERATOR_H
#define CPLAYERITERATOR_H

#include "defines.h"

class CPlayerIterator {
public:
    // address=[0x1314f30]
    bool  Init(int a2);

    // address=[0x1315000]
    int  FirstPlayer(void);

    // address=[0x1315040]
    int  NextPlayer(void);

    // address=[0x13172b0]
     CPlayerIterator(void);

    // address=[0x1317440]
    int  PlayerId(void)const;

};


#endif // CPLAYERITERATOR_H
