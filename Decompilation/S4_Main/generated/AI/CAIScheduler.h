#ifndef CAISCHEDULER_H
#define CAISCHEDULER_H

class CAIScheduler : public CAIAgent {
public:
    // address=[0x12ff090]
     CAIScheduler(void);

    // address=[0x12ff0d0]
    virtual  ~CAIScheduler(void);

    // address=[0x12ff120]
    void  AddAgent(class CAIAgent &,unsigned int,unsigned int,unsigned int);

    // address=[0x12ff180]
    void  RemoveAgent(class CAIAgent &);

    // address=[0x12ff1d0]
    void  RemoveAllAgents(void);

    // address=[0x12ff200]
    void  UpdateAgentScheduleTime(class CAIAgent &,unsigned int);

    // address=[0x12ff270]
    virtual unsigned int  Execute(unsigned int,unsigned int);

private:
    // address=[0x12ff400]
    void  AddAgentEx(class CAIAgent *);

    // address=[0x12ff580]
    void  RemoveAgentEx(class CAIAgent *);

};


#endif // CAISCHEDULER_H
