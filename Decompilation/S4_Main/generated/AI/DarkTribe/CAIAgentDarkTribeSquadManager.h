#ifndef CAIAGENTDARKTRIBESQUADMANAGER_H
#define CAIAGENTDARKTRIBESQUADMANAGER_H

class CAIAgentDarkTribeSquadManager : public CAIDarkTribeSectorAgent {
public:
    // address=[0x1302430]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x1322ea0]
     CAIAgentDarkTribeSquadManager(void);

    // address=[0x1322fa0]
    virtual  ~CAIAgentDarkTribeSquadManager(void);

protected:
    // address=[0x1302940]
    void  SimpleSquadManagement(enum T_AI_WARRIOR_TYPE,enum T_AI_TASK_FORCE_TYPE,int);

    // address=[0x1302bb0]
    void  AssociateSquads(enum T_AI_TASK_FORCE_CLASS);

    // address=[0x1302cb0]
    void  CheckSettlers(int,enum T_AI_WARRIOR_TYPE);

};


#endif // CAIAGENTDARKTRIBESQUADMANAGER_H
