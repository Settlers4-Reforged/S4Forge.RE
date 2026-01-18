#ifndef CPLAYERMAGICDATA_H
#define CPLAYERMAGICDATA_H

#include "defines.h"

class CPlayerMagicData {
public:
    // address=[0x1470ae0]
    int  ManaAmount(void)const;

    // address=[0x1470b70]
    int  MaxNumberOfBigTemples(void)const;

    // address=[0x1470db0]
    int  SpellCategoryCost(int a2)const;

    // address=[0x1470de0]
    int  SpellCategoryCounter(int a2)const;

    // address=[0x1470e30]
    int  TotalAmountOfCollectedMana(void)const;

protected:
    // address=[0x1470920]
    void  ClearManaAmountChangedFlag(void);

    // address=[0x1470b00]
    bool  ManaAmountChanged(void)const;

    // address=[0x1470b40]
    void  MarkMaxSpellCastNumbersAsInvalid(void);

    // address=[0x1470b90]
    int  MaxSpellCastNumber(int a2)const;

    // address=[0x1470c90]
    void  SetManaAmount(int a2);

    // address=[0x1470cd0]
    void  SetManaAmountChangedFlag(void);

    // address=[0x1470cf0]
    void  SetMaxSpellCastNumber(int a2, int a3);

    // address=[0x1470d10]
    void  SetSpellCategoryCost(int a2, int a3);

    // address=[0x1470d40]
    void  SetSpellCategoryCounter(int a2, int a3);

    // address=[0x1470d80]
    void  SetTotalAmountOfCollectedMana(int a2);

    // address=[0x14731d0]
    void  Clear(void);

    // address=[0x1474cd0]
    void  SetMaxNumberOfBigTemples(int a2);

};


#endif // CPLAYERMAGICDATA_H
