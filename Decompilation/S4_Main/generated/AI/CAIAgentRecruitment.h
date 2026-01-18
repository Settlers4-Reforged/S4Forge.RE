#ifndef CAIAGENTRECRUITMENT_H
#define CAIAGENTRECRUITMENT_H

#include "defines.h"

class CAIAgentRecruitment : public CAINormalSectorAgent {
public:
    // address=[0x1305510]
     CAIAgentRecruitment(void);

    // address=[0x1305540]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x13062e0]
    virtual  ~CAIAgentRecruitment(void);

    // address=[0x1309670]
    void  SetUniqueFighterRecruitment(int a2);

};


#endif // CAIAGENTRECRUITMENT_H
