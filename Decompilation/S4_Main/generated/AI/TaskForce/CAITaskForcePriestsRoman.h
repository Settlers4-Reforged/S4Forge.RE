#ifndef CAITASKFORCEPRIESTSROMAN_H
#define CAITASKFORCEPRIESTSROMAN_H

#include "defines.h"

class CAITaskForcePriestsRoman : public CAITaskForcePriests {
public:
    // address=[0x132b8b0]
    virtual int  ChooseMilitarySpell(struct SCountFightersResult const & a2, int a3);

    // address=[0x132b980]
    virtual int  ChooseMilitarySpellDestination(int a2, int a3, int a4, int a5);

    // address=[0x132e520]
     CAITaskForcePriestsRoman(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x132e650]
    virtual  ~CAITaskForcePriestsRoman(void);

};


#endif // CAITASKFORCEPRIESTSROMAN_H
