#ifndef CMANYBUILDINGTYPESITERATOR_H
#define CMANYBUILDINGTYPESITERATOR_H

#include "defines.h"

class CManyBuildingTypesIterator {
public:
    // address=[0x1315b40]
    void  Init(int a2, int a3, int a4);

    // address=[0x1315b80]
    int  FirstBuilding(void);

    // address=[0x1315c00]
    int  NextBuilding(void);

    // address=[0x1315ca0]
    int  NextBuildingIfCurrentIsNotValid(void);

    // address=[0x13171f0]
     CManyBuildingTypesIterator(void);

};


#endif // CMANYBUILDINGTYPESITERATOR_H
