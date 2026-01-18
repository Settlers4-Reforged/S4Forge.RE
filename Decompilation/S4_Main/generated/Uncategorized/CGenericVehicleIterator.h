#ifndef CGENERICVEHICLEITERATOR_H
#define CGENERICVEHICLEITERATOR_H

#include "defines.h"

class CGenericVehicleIterator {
public:
    // address=[0x1315820]
    bool  Init(int a2, int a3, int a4);

    // address=[0x1315890]
    int  FirstVehicle(void);

    // address=[0x1315910]
    int  NextVehicle(void);

    // address=[0x13159e0]
    int  NextVehicleIfCurrentIsNotValid(void);

    // address=[0x1315a20]
    int  NextVehicleOrFirstIfCurrentIsEndOfList(void);

    // address=[0x13171d0]
     CGenericVehicleIterator(void);

};


#endif // CGENERICVEHICLEITERATOR_H
