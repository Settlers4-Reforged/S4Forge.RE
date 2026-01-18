#ifndef CAIAGENTSQUADS_H
#define CAIAGENTSQUADS_H

#include "defines.h"

class CAIAgentSquads : public CAINormalSectorAgent {
public:
    // address=[0x13071b0]
     CAIAgentSquads(void);

    // address=[0x13071e0]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

    // address=[0x1309360]
    virtual  ~CAIAgentSquads(void);

protected:
    // address=[0x13088d0]
    void  SimpleSquadManagement(enum T_AI_WARRIOR_TYPE a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x1308b30]
    void  AssociateTaskForcesToSquads(enum T_AI_TASK_FORCE_CLASS a2);

};


#endif // CAIAGENTSQUADS_H
