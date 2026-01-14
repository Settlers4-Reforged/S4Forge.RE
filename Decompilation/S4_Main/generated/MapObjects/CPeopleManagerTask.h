#ifndef CPEOPLEMANAGERTASK_H
#define CPEOPLEMANAGERTASK_H

class CPeopleManagerTask : public IScheduleEntry {
public:
    // address=[0x2f56aa0]
     CPeopleManagerTask(void);

    // address=[0x2f56b00]
    virtual  ~CPeopleManagerTask(void);

    // address=[0x2f56b20]
    virtual bool  IsShooting(void);

    // address=[0x2f56d00]
    virtual bool  action(void);

    // address=[0x2f56e10]
    virtual bool  IsAlive(void);

    // address=[0x2f56e20]
    virtual bool  WaitFor(void);

    // address=[0x2f56f70]
    int  GetNeededCarierSettler(void);

    // address=[0x2f57010]
    int  GetNeededBuildingSettler(int);

    // address=[0x2f57060]
    bool  DestroyResidenceBuildings(void);

    // address=[0x2f57310]
    void  SetMinimumCarrier(void);

    // address=[0x2f573f0]
    bool  ExistNotEmptyResidence(void);

};


#endif // CPEOPLEMANAGERTASK_H
