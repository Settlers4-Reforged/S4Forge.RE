#ifndef CAIAGENTDARKTRIBEMUSHROOMFARMS_H
#define CAIAGENTDARKTRIBEMUSHROOMFARMS_H

#include "defines.h"

class CAIAgentDarkTribeMushroomFarms : public CAIDarkTribeSectorAgent {
public:
    // address=[0x1301d60]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

    // address=[0x1322e10]
     CAIAgentDarkTribeMushroomFarms(void);

    // address=[0x1322f40]
    virtual  ~CAIAgentDarkTribeMushroomFarms(void);

};


#endif // CAIAGENTDARKTRIBEMUSHROOMFARMS_H
