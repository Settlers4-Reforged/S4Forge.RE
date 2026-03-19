#ifndef CAITASKFORCEPRIESTSMAYA_H
#define CAITASKFORCEPRIESTSMAYA_H

#include "CAITaskForcePriests.h"
#include "defines.h"
#include "AI/CAIConfigInt.h"

class CAITaskForcePriestsMaya : public CAITaskForcePriests {
public:
    // address=[0x132bbf0]
    virtual int ChooseMilitarySpell(struct SCountFightersResult const &_rFighterCount, int a3);

    // address=[0x132bd00]
    virtual int ChooseMilitarySpellDestination(int a2, int _iX, int _iY, int a5);

    // address=[0x132e4e0]
    CAITaskForcePriestsMaya(int a2, enum T_AI_TASK_FORCE_TYPE a3, int a4);

    // address=[0x132e630]
    virtual ~CAITaskForcePriestsMaya(void);

protected:
    // address=[0x3ECD008]
    CAIConfigInt s_sConfigMayaMilitarySpellChanceAttack{"MayaMilitarySpellChanceAttack", 5};
    // address=[0x3ECD014]
    CAIConfigInt s_sConfigMayaMilitarySpellChanceDefence{"MayaMilitarySpellChanceDefence", 5};
    // address=[0x3ECD02C]
    CAIConfigInt s_sConfigMayaMilitarySpellChanceNone{"MayaMilitarySpellChanceNone", 5};
    // address=[0x3ECD020]
    CAIConfigInt s_sConfigMayaMilitarySpellChanceSoldier{"MayaMilitarySpellChanceSoldier", 5};
};


#endif // CAITASKFORCEPRIESTSMAYA_H
