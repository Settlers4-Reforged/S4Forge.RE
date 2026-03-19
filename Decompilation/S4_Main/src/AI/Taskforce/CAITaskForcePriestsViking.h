#ifndef CAITASKFORCEPRIESTSVIKING_H
#define CAITASKFORCEPRIESTSVIKING_H

#include "CAITaskForcePriests.h"
#include "defines.h"
#include "AI/CAIConfigInt.h"

class CAITaskForcePriestsViking : public CAITaskForcePriests {
public:
    // address=[0x132ba20]
    virtual int ChooseMilitarySpell(struct SCountFightersResult const &a2, int a3);

    // address=[0x132bb20]
    virtual int ChooseMilitarySpellDestination(int a2, int a3, int a4, int a5);

    // address=[0x132e5a0]
    CAITaskForcePriestsViking(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x132e690]
    virtual ~CAITaskForcePriestsViking(void);

private:
    // address=[0x3ECCFCC]
    CAIConfigInt s_cAIConfigVikingMilitarySpellChanceAttack{"VikingMilitarySpellChanceAttack", 5};
    // address=[0x3ECCFD8]
    CAIConfigInt s_cAIConfigVikingMilitarySpellChanceDefence{"VikingMilitarySpellChanceDefence", 5};
    // address=[0x3ECCFF0]
    CAIConfigInt s_cAIConfigVikingMilitarySpellChanceNone{"VikingMilitarySpellChanceNone", 5};
    // address=[0x3ECCFE4]
    CAIConfigInt s_cAIConfigVikingMilitarySpellChanceSoldier{"VikingMilitarySpellChanceSoldier", 5};
    // address=[0x3ECCFFC]
    CAIConfigInt s_cAIConfigVikingMilitarySpellThorsHammer{"VikingMilitarySpellThorsHammer", 15};
};


#endif // CAITASKFORCEPRIESTSVIKING_H
