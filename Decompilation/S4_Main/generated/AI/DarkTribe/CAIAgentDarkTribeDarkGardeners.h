#ifndef CAIAGENTDARKTRIBEDARKGARDENERS_H
#define CAIAGENTDARKTRIBEDARKGARDENERS_H

#include "defines.h"

class CAIAgentDarkTribeDarkGardeners : public CAIDarkTribeSectorAgent {
public:
    // address=[0x1301980]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

    // address=[0x1322d70]
     CAIAgentDarkTribeDarkGardeners(void);

    // address=[0x1322ee0]
    virtual  ~CAIAgentDarkTribeDarkGardeners(void);

};


#endif // CAIAGENTDARKTRIBEDARKGARDENERS_H
