#ifndef CAIAGENTSQUADS_H
#define CAIAGENTSQUADS_H

class CAIAgentSquads : public CAINormalSectorAgent {
public:
    // address=[0x13071b0]
     CAIAgentSquads(void);

    // address=[0x13071e0]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x1309360]
    virtual  ~CAIAgentSquads(void);

protected:
    // address=[0x13088d0]
    void  SimpleSquadManagement(enum T_AI_WARRIOR_TYPE,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x1308b30]
    void  AssociateTaskForcesToSquads(enum T_AI_TASK_FORCE_CLASS);

};


#endif // CAIAGENTSQUADS_H
