#ifndef CMATERIALMANAGERTASK_H
#define CMATERIALMANAGERTASK_H

#include "defines.h"

class CMaterialManagerTask : public IScheduleEntry {
public:
    // address=[0x2f55020]
     CMaterialManagerTask(enum PILE_TYPES a2, int a3);

    // address=[0x2f55090]
    virtual  ~CMaterialManagerTask(void);

    // address=[0x2f550b0]
    virtual bool  IsShooting(void);

    // address=[0x2f55110]
    virtual bool  action(void a2);

    // address=[0x2f55460]
    virtual bool  IsAlive(void);

    // address=[0x2f55470]
    virtual bool  WaitFor(void);

    // address=[0x2f55790]
    int  MinDebitOutput(enum PILE_TYPES a2);

    // address=[0x2f557e0]
    int  MinCreditOutput(enum PILE_TYPES a2);

    // address=[0x2f55890]
    bool  IsSingleChainProduction(enum PILE_TYPES a1);

};


#endif // CMATERIALMANAGERTASK_H
