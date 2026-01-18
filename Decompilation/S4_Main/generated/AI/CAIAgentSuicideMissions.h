#ifndef CAIAGENTSUICIDEMISSIONS_H
#define CAIAGENTSUICIDEMISSIONS_H

#include "defines.h"

class CAIAgentSuicideMissions : public CAINormalSectorAgent {
public:
    // address=[0x1303ee0]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

    // address=[0x1325b00]
     CAIAgentSuicideMissions(void);

    // address=[0x1325cb0]
    virtual  ~CAIAgentSuicideMissions(void);

};


#endif // CAIAGENTSUICIDEMISSIONS_H
