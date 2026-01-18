#ifndef CAIAGENTEVALDEFENCE_H
#define CAIAGENTEVALDEFENCE_H

#include "defines.h"

class CAIAgentEvalDefence : public CAINormalSectorAgent {
public:
    // address=[0x13045a0]
     CAIAgentEvalDefence(void);

    // address=[0x13045d0]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

    // address=[0x1304600]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x1304680]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x1306280]
    virtual  ~CAIAgentEvalDefence(void);

    // address=[0x1309520]
    int  EvaluationCounter(void)const;

};


#endif // CAIAGENTEVALDEFENCE_H
