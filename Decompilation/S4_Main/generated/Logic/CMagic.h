#ifndef CMAGIC_H
#define CMAGIC_H

class CMagic {
public:
    // address=[0x146af50]
    static void __cdecl InitPlayerMagicData(int);

    // address=[0x146b040]
    static void __cdecl InitMagicData(void);

    // address=[0x146b080]
    static int __cdecl CastSpell(int,int,int,int,int,int);

    // address=[0x146b580]
    static int __cdecl CheckManaForCastSpell(int,int,int);

    // address=[0x146b650]
    static int __cdecl GetSpellRange(int,int);

    // address=[0x146b6f0]
    static int __cdecl GetCurrentManaAmount(int);

    // address=[0x146b750]
    static int __cdecl GetCurrentSpellCategoryCost(int,int);

    // address=[0x146b800]
    static int __cdecl GetCurrentSpellCategoryCounter(int,int);

    // address=[0x146b8a0]
    static int __cdecl CalculatePossibleNumberOfCastSpell(int,int,int);

    // address=[0x146bb70]
    static void __cdecl GetConvertGoodInfo(int,int &,int &);

    // address=[0x146bbe0]
    static void __cdecl IncreaseManaByDonation(int);

    // address=[0x146bc80]
    static void __cdecl IncreaseManaByBigTemple(int);

    // address=[0x146bd20]
    static int __cdecl TotalAmountOfCollectedMana(int);

    // address=[0x146bd90]
    static void __cdecl DecreaseManaAfterWarmachineShot(int);

    // address=[0x146bdd0]
    static void __cdecl IncreaseMana(int,int);

    // address=[0x146be70]
    static void __cdecl DecreaseMana(int,int);

    // address=[0x146bf30]
    static bool __cdecl CheckAndDecreaseMana(int,int);

    // address=[0x146bff0]
    static void __cdecl DbgPrint(int);

    // address=[0x146c220]
    static int __cdecl MagicGetSpellRange(int,int);

protected:
    // address=[0x146c320]
    static void __cdecl ExecuteCastSpell(unsigned int,unsigned int,unsigned int);

};


#endif // CMAGIC_H
