#ifndef CAITASKFORCEPRIESTSMAYA_H
#define CAITASKFORCEPRIESTSMAYA_H

#include "defines.h"

class CAITaskForcePriestsMaya : public CAITaskForcePriests {
public:
    // address=[0x132bbf0]
    virtual int  ChooseMilitarySpell(struct SCountFightersResult const & a2, int a3);

    // address=[0x132bd00]
    virtual int  ChooseMilitarySpellDestination(int a2, int a3, int a4, int a5);

    // address=[0x132e4e0]
     CAITaskForcePriestsMaya(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x132e630]
    virtual  ~CAITaskForcePriestsMaya(void);

};


#endif // CAITASKFORCEPRIESTSMAYA_H
