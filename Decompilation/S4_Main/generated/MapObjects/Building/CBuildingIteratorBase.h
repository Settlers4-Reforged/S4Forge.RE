#ifndef CBUILDINGITERATORBASE_H
#define CBUILDINGITERATORBASE_H

#include "defines.h"

class CBuildingIteratorBase {
public:
    // address=[0x1317300]
    int  BuildingId(void)const;

    // address=[0x1317320]
    int  BuildingType(void)const;

protected:
    // address=[0x1317340]
    bool  BuildingValid(int a2);

    // address=[0x13173a0]
    void  Init(int a2);

};


#endif // CBUILDINGITERATORBASE_H
