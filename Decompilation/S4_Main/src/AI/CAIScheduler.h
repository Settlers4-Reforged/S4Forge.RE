#ifndef CAISCHEDULER_H
#define CAISCHEDULER_H

#include "CAIAgent.h"
#include "defines.h"

class CAIScheduler : public CAIAgent {
public:
    // address=[0x12ff090]
    CAIScheduler(void);

    // address=[0x12ff0d0]
    virtual ~CAIScheduler(void);

    // address=[0x12ff120]
    void AddAgent(class CAIAgent &_rAgent, unsigned int _uDefaultExecutionDelay, unsigned int a4, unsigned int a5);

    // address=[0x12ff180]
    void RemoveAgent(class CAIAgent &a2);

    // address=[0x12ff1d0]
    void RemoveAllAgents(void);

    // address=[0x12ff200]
    void UpdateAgentScheduleTime(class CAIAgent &_rParent, unsigned int _uScheduleTime);

    // address=[0x12ff270]
    virtual unsigned int Execute(unsigned int a2, unsigned int a3);

private:
    // address=[0x12ff400]
    void AddAgentEx(class CAIAgent *a2);

    // address=[0x12ff580]
    void RemoveAgentEx(class CAIAgent *_pAgent);

    // Type information members
public:
    int       m_iNumberOfAgents;
    CAIAgent *m_pFirstAgent;
};


#endif // CAISCHEDULER_H
