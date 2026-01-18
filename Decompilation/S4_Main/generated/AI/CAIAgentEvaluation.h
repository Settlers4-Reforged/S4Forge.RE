#ifndef CAIAGENTEVALUATION_H
#define CAIAGENTEVALUATION_H

#include "defines.h"

class CAIAgentEvaluation : public CAIAgent {
public:
    // address=[0x1303a40]
     CAIAgentEvaluation(class CAIPlayerEvaluations & a2);

    // address=[0x1303a80]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

    // address=[0x1303be0]
    virtual  ~CAIAgentEvaluation(void);

    // address=[0x1314030]
    void  Init(void);

};


#endif // CAIAGENTEVALUATION_H
