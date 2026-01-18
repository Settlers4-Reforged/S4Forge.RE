#ifndef CMANYVEHICLETYPESITERATOR_H
#define CMANYVEHICLETYPESITERATOR_H

#include "defines.h"

class CManyVehicleTypesIterator {
public:
    // address=[0x1315680]
    void  Init(int a2, int a3, int a4);

    // address=[0x13156c0]
    int  FirstVehicle(void);

    // address=[0x1315740]
    int  NextVehicle(void);

    // address=[0x13157e0]
    int  NextVehicleIfCurrentIsNotValid(void);

    // address=[0x1317230]
     CManyVehicleTypesIterator(void);

};


#endif // CMANYVEHICLETYPESITERATOR_H
