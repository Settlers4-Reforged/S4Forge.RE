#ifndef CMAGIC_H
#define CMAGIC_H

#include "defines.h"

class CMagic {
public:
    // address=[0x146af50]
    static void __cdecl InitPlayerMagicData(int a1);

    // address=[0x146b040]
    static void __cdecl InitMagicData(void);

    // address=[0x146b080]
    static int __cdecl CastSpell(int a1, int a2, int a3, int a4, int a5, int a6);

    // address=[0x146b580]
    static int __cdecl CheckManaForCastSpell(int a1, int a2, int a3);

    // address=[0x146b650]
    static int __cdecl GetSpellRange(int a1, int a2);

    // address=[0x146b6f0]
    static int __cdecl GetCurrentManaAmount(int a1);

    // address=[0x146b750]
    static int __cdecl GetCurrentSpellCategoryCost(int a1, int a2);

    // address=[0x146b800]
    static int __cdecl GetCurrentSpellCategoryCounter(int a1, int a2);

    // address=[0x146b8a0]
    static int __cdecl CalculatePossibleNumberOfCastSpell(int a1, int a2, int a3);

    // address=[0x146bb70]
    static void __cdecl GetConvertGoodInfo(int a1, int & a2, int & a3);

    // address=[0x146bbe0]
    static void __cdecl IncreaseManaByDonation(int a1);

    // address=[0x146bc80]
    static void __cdecl IncreaseManaByBigTemple(int a1);

    // address=[0x146bd20]
    static int __cdecl TotalAmountOfCollectedMana(int a1);

    // address=[0x146bd90]
    static void __cdecl DecreaseManaAfterWarmachineShot(int a1);

    // address=[0x146bdd0]
    static void __cdecl IncreaseMana(int a1, int a2);

    // address=[0x146be70]
    static void __cdecl DecreaseMana(int a1, int a2);

    // address=[0x146bf30]
    static bool __cdecl CheckAndDecreaseMana(int a1, int a2);

    // address=[0x146bff0]
    static void __cdecl DbgPrint(int a1);

    // address=[0x146c220]
    static int __cdecl MagicGetSpellRange(int a1, int a2);

protected:
    // address=[0x146c320]
    static void __cdecl ExecuteCastSpell(unsigned int a1, unsigned int a2, unsigned int a3);

};


#endif // CMAGIC_H
