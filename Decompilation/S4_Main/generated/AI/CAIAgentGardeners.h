#ifndef CAIAGENTGARDENERS_H
#define CAIAGENTGARDENERS_H

#include "defines.h"

class CAIAgentGardeners : public CAINormalSectorAgent {
public:
    // address=[0x1304230]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

    // address=[0x1325a70]
     CAIAgentGardeners(void);

    // address=[0x1325c50]
    virtual  ~CAIAgentGardeners(void);

};


#endif // CAIAGENTGARDENERS_H
