#ifndef CSUBPROBLEMSOLVEEVENT_H
#define CSUBPROBLEMSOLVEEVENT_H

class CSubProblemSolveEvent : public IScheduleEntry {
public:
    // address=[0x2f4e360]
     CSubProblemSolveEvent(class CSiedlerAI *,int,int,int,int,int,int,class COptimizeOptions *);

    // address=[0x2f4e470]
    virtual  ~CSubProblemSolveEvent(void);

    // address=[0x2f4e4c0]
    virtual bool  IsShooting(void);

    // address=[0x2f4e550]
    virtual bool  action(void);

    // address=[0x2f4e8b0]
    virtual bool  IsAlive(void);

    // address=[0x2f4e8f0]
    virtual bool  WaitFor(void);

};


#endif // CSUBPROBLEMSOLVEEVENT_H
