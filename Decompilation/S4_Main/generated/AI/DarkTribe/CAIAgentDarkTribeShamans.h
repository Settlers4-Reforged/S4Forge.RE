#ifndef CAIAGENTDARKTRIBESHAMANS_H
#define CAIAGENTDARKTRIBESHAMANS_H

#include "defines.h"

class CAIAgentDarkTribeShamans : public CAIDarkTribeSectorAgent {
public:
    // address=[0x13022a0]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

    // address=[0x1322e70]
     CAIAgentDarkTribeShamans(void);

    // address=[0x1322f80]
    virtual  ~CAIAgentDarkTribeShamans(void);

};


#endif // CAIAGENTDARKTRIBESHAMANS_H
