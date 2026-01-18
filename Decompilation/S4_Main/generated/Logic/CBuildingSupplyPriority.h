#ifndef CBUILDINGSUPPLYPRIORITY_H
#define CBUILDINGSUPPLYPRIORITY_H

#include "defines.h"

class CBuildingSupplyPriority : public CPersistence {
public:
    // address=[0x13fff00]
    static class CPersistence * __cdecl New(std::istream & a1);

    // address=[0x140aae0]
     CBuildingSupplyPriority(std::istream & a2);

    // address=[0x140aca0]
    virtual void  Store(std::ostream & a2);

    // address=[0x140aea0]
     CBuildingSupplyPriority(int a2);

    // address=[0x140af60]
    int  GetPriority(enum BUILDING_TYPES a2, enum PILE_TYPES a3);

    // address=[0x140b0f0]
    int  GetNumberOfSupplyBuildings(enum PILE_TYPES a2, struct SDistributionInfo * const a3);

    // address=[0x140b280]
    int  GetNumberOfSupplyBuildings(enum PILE_TYPES a2);

    // address=[0x140b3d0]
    void  ChangePriority(enum PILE_TYPES a2, struct SDistributionInfo * const a3);

    // address=[0x140b590]
    void  ChangePriority(enum PILE_TYPES a2, enum BUILDING_TYPES a3, int a4);

    // address=[0x1417110]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14380c0]
     ~CBuildingSupplyPriority(void);

    // address=[0x3d8948c]
    static unsigned long m_iClassID;

private:
    // address=[0x140b740]
    void  CreateRomanPriorities(void);

    // address=[0x140bbe0]
    void  CreateVikingPriorities(void);

    // address=[0x140c1f0]
    void  CreateMayaPriorities(void);

    // address=[0x140c790]
    void  CreateTrojanPriorities(void);

    // address=[0x140cd60]
    void  CreateAllRacesPriorities(void);

    // address=[0x3efe5e0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_COAL_WEAPONSMITH;

    // address=[0x3efe600]
    static class TStaticConfigIntArray<6> m_iDefault_SP_COAL_TOOLSMITH;

    // address=[0x3efe620]
    static class TStaticConfigIntArray<6> m_iDefault_SP_COAL_IRONMELT;

    // address=[0x3efe640]
    static class TStaticConfigIntArray<6> m_iDefault_SP_COAL_GOLDMELT;

    // address=[0x3efe660]
    static class TStaticConfigIntArray<6> m_iDefault_SP_COAL_AMMOMAKERHUT;

    // address=[0x3efe680]
    static class TStaticConfigIntArray<6> m_iDefault_SP_IRONBAR_WEAPONSMITH;

    // address=[0x3efe6a0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_IRONBAR_TOOLSMITH;

    // address=[0x3efe6c0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_IRONBAR_SHIPYARD;

    // address=[0x3efe6e0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_IRONBAR_VEHICLEHALL;

    // address=[0x3efe700]
    static class TStaticConfigIntArray<6> m_iDefault_SP_LOG_AMMOMAKERHUT;

    // address=[0x3efe720]
    static class TStaticConfigIntArray<6> m_iDefault_SP_LOG_CHARCOALMAKER;

    // address=[0x3efe740]
    static class TStaticConfigIntArray<6> m_iDefault_SP_LOG_SAWMILL;

    // address=[0x3efe760]
    static class TStaticConfigIntArray<6> m_iDefault_SP_GRAIN_ANIMALRANCH;

    // address=[0x3efe780]
    static class TStaticConfigIntArray<6> m_iDefault_SP_GRAIN_DONKEYFARM;

    // address=[0x3efe7a0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_GRAIN_MILL;

    // address=[0x3efe7c0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_WATER_BAKERY;

    // address=[0x3efe7e0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_WATER_ANIMALFARM;

    // address=[0x3efe800]
    static class TStaticConfigIntArray<6> m_iDefault_SP_WATER_DONKEYFARM;

    // address=[0x3efe820]
    static class TStaticConfigIntArray<6> m_iDefault_SP_WATER_MEADMAKERHUT;

    // address=[0x3efe840]
    static class TStaticConfigIntArray<6> m_iDefault_SP_WATER_TEQUILAMAKERHUT;

    // address=[0x3efe860]
    static class TStaticConfigIntArray<6> m_iDefault_SP_BREAD_COALMINE;

    // address=[0x3efe880]
    static class TStaticConfigIntArray<6> m_iDefault_SP_BREAD_GOLDMINE;

    // address=[0x3efe8a0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_BREAD_IRONMINE;

    // address=[0x3efe8c0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_BREAD_SULFURMINE;

    // address=[0x3efe8e0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_BREAD_STONEMINE;

    // address=[0x3efe900]
    static class TStaticConfigIntArray<6> m_iDefault_SP_MEAT_COALMINE;

    // address=[0x3efe920]
    static class TStaticConfigIntArray<6> m_iDefault_SP_MEAT_GOLDMINE;

    // address=[0x3efe940]
    static class TStaticConfigIntArray<6> m_iDefault_SP_MEAT_IRONMINE;

    // address=[0x3efe960]
    static class TStaticConfigIntArray<6> m_iDefault_SP_MEAT_SULFURMINE;

    // address=[0x3efe980]
    static class TStaticConfigIntArray<6> m_iDefault_SP_MEAT_STONEMINE;

    // address=[0x3efe9a0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_FISH_COALMINE;

    // address=[0x3efe9c0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_FISH_GOLDMINE;

    // address=[0x3efe9e0]
    static class TStaticConfigIntArray<6> m_iDefault_SP_FISH_IRONMINE;

    // address=[0x3efea00]
    static class TStaticConfigIntArray<6> m_iDefault_SP_FISH_SULFURMINE;

    // address=[0x3efea20]
    static class TStaticConfigIntArray<6> m_iDefault_SP_FISH_STONEMINE;

};


#endif // CBUILDINGSUPPLYPRIORITY_H
