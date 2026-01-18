#ifndef CAIAGENTMOVINGHOME_H
#define CAIAGENTMOVINGHOME_H

#include "defines.h"

class CAIAgentMovingHome : public CAINormalSectorAgent {
public:
    // address=[0x1304050]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

    // address=[0x1325ad0]
     CAIAgentMovingHome(void);

    // address=[0x1325c90]
    virtual  ~CAIAgentMovingHome(void);

};


#endif // CAIAGENTMOVINGHOME_H
