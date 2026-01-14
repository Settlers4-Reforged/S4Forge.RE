#ifndef CMATERIALMANAGERTASK_H
#define CMATERIALMANAGERTASK_H

class CMaterialManagerTask : public IScheduleEntry {
public:
    // address=[0x2f55020]
     CMaterialManagerTask(enum PILE_TYPES,int);

    // address=[0x2f55090]
    virtual  ~CMaterialManagerTask(void);

    // address=[0x2f550b0]
    virtual bool  IsShooting(void);

    // address=[0x2f55110]
    virtual bool  action(void);

    // address=[0x2f55460]
    virtual bool  IsAlive(void);

    // address=[0x2f55470]
    virtual bool  WaitFor(void);

    // address=[0x2f55790]
    int  MinDebitOutput(enum PILE_TYPES);

    // address=[0x2f557e0]
    int  MinCreditOutput(enum PILE_TYPES);

    // address=[0x2f55890]
    bool  IsSingleChainProduction(enum PILE_TYPES);

};


#endif // CMATERIALMANAGERTASK_H
