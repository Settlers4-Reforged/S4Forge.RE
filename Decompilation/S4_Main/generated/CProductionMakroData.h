#ifndef CPRODUCTIONMAKRODATA_H
#define CPRODUCTIONMAKRODATA_H

class CProductionMakroData {
public:
    // address=[0x2f567f0]
     CProductionMakroData(void);

    // address=[0x2f56810]
     CProductionMakroData(class CSchedule *,int,enum BUILDING_TYPES,struct SBuildId *,struct SBuildId *);

    // address=[0x2f56a70]
     ~CProductionMakroData(void);

    // address=[0x2f56a90]
    struct SBuildId *  GetBuildArray(void);

};


#endif // CPRODUCTIONMAKRODATA_H
