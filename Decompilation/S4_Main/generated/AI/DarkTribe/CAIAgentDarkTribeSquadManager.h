#ifndef CAIAGENTDARKTRIBESQUADMANAGER_H
#define CAIAGENTDARKTRIBESQUADMANAGER_H

#include "defines.h"

class CAIAgentDarkTribeSquadManager : public CAIDarkTribeSectorAgent {
public:
    // address=[0x1302430]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

    // address=[0x1322ea0]
     CAIAgentDarkTribeSquadManager(void);

    // address=[0x1322fa0]
    virtual  ~CAIAgentDarkTribeSquadManager(void);

protected:
    // address=[0x1302940]
    void  SimpleSquadManagement(enum T_AI_WARRIOR_TYPE a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x1302bb0]
    void  AssociateSquads(enum T_AI_TASK_FORCE_CLASS a2);

    // address=[0x1302cb0]
    void  CheckSettlers(int a2, enum T_AI_WARRIOR_TYPE a3);

};


#endif // CAIAGENTDARKTRIBESQUADMANAGER_H
