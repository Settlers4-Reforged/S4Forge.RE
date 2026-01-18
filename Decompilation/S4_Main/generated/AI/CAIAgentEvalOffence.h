#ifndef CAIAGENTEVALOFFENCE_H
#define CAIAGENTEVALOFFENCE_H

#include "defines.h"

class CAIAgentEvalOffence : public CAINormalSectorAgent {
public:
    // address=[0x1304700]
    virtual unsigned int  Execute(unsigned int,unsigned int);

    // address=[0x1325a40]
     CAIAgentEvalOffence(void);

    // address=[0x1325c30]
    virtual  ~CAIAgentEvalOffence(void);

};


#endif // CAIAGENTEVALOFFENCE_H
