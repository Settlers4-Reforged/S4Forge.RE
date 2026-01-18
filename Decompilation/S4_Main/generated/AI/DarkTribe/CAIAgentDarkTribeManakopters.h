#ifndef CAIAGENTDARKTRIBEMANAKOPTERS_H
#define CAIAGENTDARKTRIBEMANAKOPTERS_H

#include "defines.h"

class CAIAgentDarkTribeManakopters : public CAIDarkTribeSectorAgent {
public:
    // address=[0x1322de0]
     CAIAgentDarkTribeManakopters(void);

    // address=[0x1322f20]
    virtual  ~CAIAgentDarkTribeManakopters(void);

    // address=[0x1323220]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

};


#endif // CAIAGENTDARKTRIBEMANAKOPTERS_H
