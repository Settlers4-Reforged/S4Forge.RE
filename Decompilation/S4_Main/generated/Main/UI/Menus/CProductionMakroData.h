#ifndef CPRODUCTIONMAKRODATA_H
#define CPRODUCTIONMAKRODATA_H

#include "defines.h"

class CProductionMakroData {
public:
    // address=[0x2f567f0]
     CProductionMakroData(void);

    // address=[0x2f56810]
     CProductionMakroData(class CSchedule * a2, int a3, enum BUILDING_TYPES a4, struct SBuildId * a5, struct SBuildId * a6);

    // address=[0x2f56a70]
     ~CProductionMakroData(void);

    // address=[0x2f56a90]
    struct SBuildId *  GetBuildArray(void);

};


#endif // CPRODUCTIONMAKRODATA_H
