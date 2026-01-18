#ifndef CAIAGENTTOWEROCCUPATION_H
#define CAIAGENTTOWEROCCUPATION_H

#include "defines.h"

class CAIAgentTowerOccupation : public CAINormalSectorAgent {
public:
    // address=[0x1303df0]
    virtual unsigned int  Execute(unsigned int a2, unsigned int a3);

    // address=[0x1325b60]
     CAIAgentTowerOccupation(void);

    // address=[0x1325cf0]
    virtual  ~CAIAgentTowerOccupation(void);

};


#endif // CAIAGENTTOWEROCCUPATION_H
