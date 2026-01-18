#ifndef CAITASKFORCEPRIESTSTROJAN_H
#define CAITASKFORCEPRIESTSTROJAN_H

#include "defines.h"

class CAITaskForcePriestsTrojan : public CAITaskForcePriests {
public:
    // address=[0x132be00]
    virtual int  ChooseMilitarySpell(struct SCountFightersResult const & a2, int a3);

    // address=[0x132bf10]
    virtual int  ChooseMilitarySpellDestination(int a2, int a3, int a4, int a5);

    // address=[0x132e560]
     CAITaskForcePriestsTrojan(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x132e670]
    virtual  ~CAITaskForcePriestsTrojan(void);

};


#endif // CAITASKFORCEPRIESTSTROJAN_H
