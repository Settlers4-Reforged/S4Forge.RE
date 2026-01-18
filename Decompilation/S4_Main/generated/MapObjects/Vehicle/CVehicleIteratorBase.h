#ifndef CVEHICLEITERATORBASE_H
#define CVEHICLEITERATORBASE_H

#include "defines.h"

class CVehicleIteratorBase {
public:
    // address=[0x1317500]
    int  VehicleId(void)const;

    // address=[0x1317520]
    int  VehicleType(void)const;

protected:
    // address=[0x1317400]
    void  Init(int a2);

    // address=[0x1317540]
    bool  VehicleValid(int a2);

};


#endif // CVEHICLEITERATORBASE_H
