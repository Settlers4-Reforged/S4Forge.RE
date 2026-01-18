#ifndef CAIAGENT_H
#define CAIAGENT_H

#include "defines.h"

class CAIAgent {
public:
    // address=[0x12fd090]
    static unsigned int __cdecl ExecuteResult(unsigned int,unsigned int);

    // address=[0x12fd530]
    virtual void  ProcessEvent(class CAIEvent const &);

    // address=[0x12fd7e0]
    void  UpdateScheduleTimeIfLess(unsigned int a2);

    // address=[0x12fee10]
     CAIAgent(char const *);

    // address=[0x12fee80]
    virtual  ~CAIAgent(void);

    // address=[0x12fef50]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x12ff000]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x12ff9c0]
    void  UpdateScheduleTime(unsigned int a2);

    // address=[0x13064e0]
    unsigned int  DefaultExecutionDelay(void)const;

};


#endif // CAIAGENT_H
