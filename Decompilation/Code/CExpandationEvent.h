#ifndef CEXPANDATIONEVENT_H
#define CEXPANDATIONEVENT_H

class CExpandationEvent : public IScheduleEntry {
public:
    // address=[0x2f51d40]
     CExpandationEvent(int,int,int);

    // address=[0x2f51de0]
     CExpandationEvent(int,class CSchedule *);

    // address=[0x2f520f0]
    virtual  ~CExpandationEvent(void);

    // address=[0x2f52180]
    virtual bool  IsShooting(void);

    // address=[0x2f52680]
    virtual bool  action(void);

    // address=[0x2f52730]
    virtual bool  IsAlive(void);

    // address=[0x2f52740]
    virtual bool  WaitFor(void);

};


#endif // CEXPANDATIONEVENT_H
