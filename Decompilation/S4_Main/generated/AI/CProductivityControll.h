#ifndef CPRODUCTIVITYCONTROLL_H
#define CPRODUCTIVITYCONTROLL_H

#include "defines.h"

class CProductivityControll : public IScheduleEntry {
public:
    // address=[0x2f57570]
     CProductivityControll(void);

    // address=[0x2f575b0]
     CProductivityControll(struct SBuildId a2, enum BUILDING_TYPES a3, int a4, int a5);

    // address=[0x2f57630]
     CProductivityControll(int a2, enum T_BUILD_LEVEL a3, enum BUILDING_TYPES a4, int a5, int a6);

    // address=[0x2f57770]
    virtual  ~CProductivityControll(void);

    // address=[0x2f57790]
    virtual bool  IsShooting(void);

    // address=[0x2f57f90]
    virtual bool  action(void);

    // address=[0x2f58410]
    virtual bool  IsAlive(void);

    // address=[0x2f58470]
    virtual bool  WaitFor(void);

    // address=[0x2f58500]
    int  CalcPotentialOutput(void);

    // address=[0x2f58610]
    bool  PileDistribution(void);

    // address=[0x2f588c0]
    enum BUILDING_TYPES  GetFoodBuilding(enum BUILDING_TYPES a1);

    // address=[0x2f58930]
    bool  CheckProductivity(void);

};


#endif // CPRODUCTIVITYCONTROLL_H
