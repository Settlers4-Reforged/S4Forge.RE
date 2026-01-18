#ifndef CAIAGENTDARKTRIBEMANAKOPTERHALLS_H
#define CAIAGENTDARKTRIBEMANAKOPTERHALLS_H

#include "defines.h"

class CAIAgentDarkTribeManakopterHalls : public CAIDarkTribeSectorAgent {
public:
    // address=[0x1302dc0]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x1302f80]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x1303000]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x1322da0]
     CAIAgentDarkTribeManakopterHalls(void);

    // address=[0x1322f00]
    virtual  ~CAIAgentDarkTribeManakopterHalls(void);

};


#endif // CAIAGENTDARKTRIBEMANAKOPTERHALLS_H
