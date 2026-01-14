#ifndef CMAGICSPELL_H
#define CMAGICSPELL_H

class CMagicSpell {
public:
    // address=[0x146c970]
    int  SettlerFlagBitChange(int,int,int,int,enum SIV_SOUNDS);

    // address=[0x146cac0]
    int  SpellDoNothing(void);

    // address=[0x146cad0]
    int  SpellDivinePresent(void);

    // address=[0x146ce20]
    int  SpellConvertGood(void);

    // address=[0x146d010]
    int  SpellConvertTerrain(void);

    // address=[0x146d220]
    int  SpellFoodMoreFish(void);

    // address=[0x146d460]
    int  SpellDefenceShield(void);

    // address=[0x146d4b0]
    int  SpellAttackLightningBolt(void);

    // address=[0x146d650]
    int  SpellSoldierConvertBarbarians(void);

    // address=[0x146d870]
    int  SpellSpecialMoreResources(void);

    // address=[0x146dae0]
    int  SpellFoodMoreGame(void);

    // address=[0x146dc80]
    int  SpellDefenceFreezeFoes(void);

    // address=[0x146dcd0]
    int  SpellAttackBloodlust(void);

    // address=[0x146dd20]
    int  SpellSoldierFear(void);

    // address=[0x146dd70]
    int  SpellSpecialThorsHammer(void);

    // address=[0x146deb0]
    int  SpellFoodFasterCrops(void);

    // address=[0x146e020]
    int  SpellDefenceBanFoes(void);

    // address=[0x146e350]
    int  SpellAttackPunishBowmen(void);

    // address=[0x146e440]
    int  SpellSoldierRevaluation(void);

    // address=[0x146e740]
    int  SpellSpecialRainOfStone(void);

    // address=[0x146e940]
    int  SpellWitherPlants(void);

    // address=[0x146e9f0]
    int  SpellTeleportPiles(void);

    // address=[0x146ebc0]
    int  SpellFoodRestockMines(void);

    // address=[0x146ed10]
    int  SpellDefenceFortifyDoors(void);

    // address=[0x146ee70]
    int  SpellAttackInvisibility(void);

    // address=[0x146eea0]
    int  SpellSoldierPacify(void);

    // address=[0x146f100]
    int  SpellSpecialOracle(void);

    // address=[0x146f170]
    static void __cdecl ShowSpellEffect(int,int,int,int);

    // address=[0x14704b0]
     CMagicSpell(int,int,int,int,int,int,int,int,int);

    // address=[0x14708b0]
    int  CastSpell(int,int);

    // address=[0x14709e0]
    static void __cdecl InvisibleKill(class IEntity *);

protected:
    // address=[0x36b72d8]
    static int ( *(* CMagicSpell::m_pSpellFuncs)[8])(void);

};


#endif // CMAGICSPELL_H
