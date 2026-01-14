#ifndef CEXPANDATIONMANAGERTASK_H
#define CEXPANDATIONMANAGERTASK_H

class CExpandationManagerTask : public IScheduleEntry {
public:
    // address=[0x2f51910]
     CExpandationManagerTask(void);

    // address=[0x2f51a10]
    virtual  ~CExpandationManagerTask(void);

    // address=[0x2f51a50]
    bool  GetExpandationPermission(class CExpandationEvent *);

    // address=[0x2f51af0]
    bool  IsBorderElement(int,int);

    // address=[0x2f51b60]
    virtual bool  IsShooting(void);

    // address=[0x2f51d10]
    virtual bool  action(void);

    // address=[0x2f51d20]
    virtual bool  IsAlive(void);

    // address=[0x2f51d30]
    virtual bool  WaitFor(void);

};


#endif // CEXPANDATIONMANAGERTASK_H
