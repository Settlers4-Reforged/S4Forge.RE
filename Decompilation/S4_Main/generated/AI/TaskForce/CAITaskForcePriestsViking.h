#ifndef CAITASKFORCEPRIESTSVIKING_H
#define CAITASKFORCEPRIESTSVIKING_H

#include "defines.h"

class CAITaskForcePriestsViking : public CAITaskForcePriests {
public:
    // address=[0x132ba20]
    virtual int  ChooseMilitarySpell(struct SCountFightersResult const & a2, int a3);

    // address=[0x132bb20]
    virtual int  ChooseMilitarySpellDestination(int a2, int a3, int a4, int a5);

    // address=[0x132e5a0]
     CAITaskForcePriestsViking(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x132e690]
    virtual  ~CAITaskForcePriestsViking(void);

};


#endif // CAITASKFORCEPRIESTSVIKING_H
