#ifndef CAITASKFORCEPRIESTSROMAN_H
#define CAITASKFORCEPRIESTSROMAN_H

#include "CAITaskForcePriests.h"
#include "defines.h"
#include "AI/CAIConfigInt.h"

class CAITaskForcePriestsRoman : public CAITaskForcePriests {
public:
    // address=[0x132b8b0]
    virtual int ChooseMilitarySpell(struct SCountFightersResult const &a2, int a3);

    // address=[0x132b980]
    virtual int ChooseMilitarySpellDestination(int a2, int _iX, int _iY, int a5);

    // address=[0x132e520]
    CAITaskForcePriestsRoman(int iOwnerId, enum T_AI_TASK_FORCE_TYPE tType, int iFlags);

    // address=[0x132e650]
    virtual ~CAITaskForcePriestsRoman(void);

private:
    // address=[0x3ECCF9C]
    CAIConfigInt s_cAIConfigRomanMilitarySpellChanceAttack{"RomanMilitarySpellChanceAttack", 5};
    // address=[0x3ECCFA8]
    CAIConfigInt s_cAIConfigRomanMilitarySpellChanceDefence{"RomanMilitarySpellChanceDefence", 5};
    // address=[0x3ECCFC0]
    CAIConfigInt s_cAIConfigRomanMilitarySpellChanceNone{"RomanMilitarySpellChanceNone", 5};
    // address=[0x3ECCFB4]
    CAIConfigInt s_cAIConfigRomanMilitarySpellChanceSoldier{"RomanMilitarySpellChanceSoldier", 5};
};


#endif // CAITASKFORCEPRIESTSROMAN_H
