#include "CAIPlayerEvaluation.h"

#include "AI/IAIEnvironment.h"
#include "Debug/IMessageTracer.h"

#include "Defines/Buildings.h"
#include "Defines/Goods.h"
#include "Defines/Settlers.h"
#include "Logic/CStatistic.h"
#include "Main/CGameData.h"
#include "MapObjects/Settler/CSettlerMgr.h"

// Definitions for class CAIPlayerEvaluation

// address=[0x1310d40]
// Decompiled from void __thiscall CAIPlayerEvaluation::Clear(CAIPlayerEvaluation *this)
void CAIPlayerEvaluation::Clear(void) {
    this->m_uAITick = 0;
    this->m_uSwordCount = 0;
    this->m_uBowCount = 0;
    this->m_uSpecialWeaponCount = 0;
    this->m_uTotalWeaponCount = 0;
    this->m_uGoldCount = 0;
    this->m_uOfferedSwordmen = 0;
    this->m_uOfferedBowmen = 0;
    this->m_uTotalSwordmen = 0;
    this->m_uTotalBowmen = 0;
    this->m_uSpecialistsCount = 0;
    this->m_uLeadersCount = 0;
    this->m_uPriestsCount = 0;
    this->m_uTotalUnitCount = 0;
    this->m_uTotalFighterCount = 0;
    this->m_uTotalUnitCountEx = 0;
    this->m_uTotalUnitValueEx = 0;
    this->m_uSmallTowerCount = 0;
    this->m_uBigTowerCount = 0;
    this->m_uCastleCount = 0;
    this->m_uTotalWarBuildingCount = 0;
    this->m_uTotalWarBuildingValue = 0;
}

// address=[0x1310e30]
// Decompiled from void __thiscall CAIPlayerEvaluation::EvaluatePlayer(CAIPlayerEvaluation *this, DWORD a2)
void CAIPlayerEvaluation::EvaluatePlayer(int a2) {
    this->m_uAITick = IAIEnvironment::TickCounter();
    DWORD NumberOfRandCalls = g_pGameData->m_sRandom.GetNumberOfRandCalls();
    DWORD Seed = g_pGameData->m_sRandom.GetSeed();
    g_pMsgTracer2->PushFormatedInts(
        "==> Evaluation: AI_tick %u, seed 0x%08x, counter %u",
        this->m_uAITick,
        Seed,
        NumberOfRandCalls);
    this->EvaluateGoods(a2);
    this->EvaluateWarriors(a2);
    this->EvaluateBuildings(a2);
}

// address=[0x1310ea0]
// Decompiled from void __thiscall CAIPlayerEvaluation::DbgPrint(CAIPlayerEvaluation *this)
void CAIPlayerEvaluation::DbgPrint(void) {
    IAIEnvironment::DbgTracePrintF(
        "F-S/B/U/L, P:      %5i, %5i, %5i, %5i, %5i",
        this->m_uTotalSwordmen,
        this->m_uTotalBowmen,
        this->m_uSpecialistsCount,
        this->m_uLeadersCount,
        this->m_uPriestsCount);
    IAIEnvironment::DbgTracePrintF("Units (Value):     %5i, %5i", this->m_uTotalUnitCount, this->m_uTotalFighterCount);
    IAIEnvironment::DbgTracePrintF(
        "Towers & castles:  %5i, %5i, %5i",
        this->m_uSmallTowerCount,
        this->m_uBigTowerCount,
        this->m_uCastleCount);
    IAIEnvironment::DbgTracePrintF(
        "Buildings (Value): %5i, %5i",
        this->m_uTotalWarBuildingCount,
        this->m_uTotalWarBuildingValue);
}

// address=[0x1310f40]
// Decompiled from void __thiscall CAIPlayerEvaluation::EvaluateGoods(CAIPlayerEvaluation *this, int a2)
void CAIPlayerEvaluation::EvaluateGoods(int a2) {
    int iRace = IAIEnvironment::PlayerRace(a2);
    this->m_uSwordCount = g_cStatistic.GetGood(a2, GOOD_SWORD);
    this->m_uBowCount = g_cStatistic.GetGood(a2, GOOD_BOW);
    switch(iRace) {
    case 1:
        this->m_uSpecialWeaponCount = g_cStatistic.GetGood(a2, GOOD_BATTLEAXE);
        break;
    case 2:
        this->m_uSpecialWeaponCount = g_cStatistic.GetGood(a2, GOOD_BLOWGUN);
        break;
    case 4:
        this->m_uSpecialWeaponCount = g_cStatistic.GetGood(a2, GOOD_BACKPACKCATAPULT);
        break;
    default:
        this->m_uSpecialWeaponCount = 0;
        break;
    }
    this->m_uTotalWeaponCount = this->m_uSpecialWeaponCount + this->m_uBowCount + this->m_uSwordCount;
    this->m_uGoldCount = g_cStatistic.GetGood(a2, GOOD_GOLDBAR);
    g_pMsgTracer2->PushFormatedInts(
        "CAIPlayerEvaluation(Goods): Player %i: %i %i %i %i",
        a2,
        this->m_uSwordCount,
        this->m_uBowCount,
        this->m_uSpecialWeaponCount,
        this->m_uGoldCount);
}

struct SAISettlerEvalWeight {
    S4_SETTLER_ENUM m_iType;
    int m_iEvalType;
    int m_iWeight;
};

// address=[0x03D7A218]
SAISettlerEvalWeight s_sAISettlerEvalWeights[] = {
    { SETTLER_SWORDSMAN_01, 3, 2 },           // 0
    { SETTLER_SWORDSMAN_02, 3, 3 },           // 1
    { SETTLER_SWORDSMAN_03, 3, 4 },           // 2
    { SETTLER_BOWMAN_01, 4, 2 },              // 3
    { SETTLER_BOWMAN_02, 4, 3 },              // 4
    { SETTLER_BOWMAN_03, 4, 4 },              // 5
    { SETTLER_MEDIC_01, 5, 3 },               // 6
    { SETTLER_MEDIC_02, 5, 4 },               // 7
    { SETTLER_MEDIC_03, 5, 5 },               // 8
    { SETTLER_AXEWARRIOR_01, 5, 3 },          // 9
    { SETTLER_AXEWARRIOR_02, 5, 4 },          // 10
    { SETTLER_AXEWARRIOR_03, 5, 5 },          // 11
    { SETTLER_BLOWGUNWARRIOR_01, 5, 3 },      // 12
    { SETTLER_BLOWGUNWARRIOR_02, 5, 4 },      // 13
    { SETTLER_BLOWGUNWARRIOR_03, 5, 5 },      // 14
    { SETTLER_SQUADLEADER, 6, 0xA },          // 15
    { SETTLER_PRIEST, 7, 0 },                 // 16
    { SETTLER_BACKPACKCATAPULTIST_01, 5, 3 }, // 17
    { SETTLER_BACKPACKCATAPULTIST_02, 5, 4 }, // 18
    { SETTLER_BACKPACKCATAPULTIST_03, 5, 5 }, // 19
    {}
};

// address=[0x03D7A318]
SAISettlerEvalWeight s_sAIOfferedSettlerEvalWeights[] = {
    { SETTLER_SWORDSMAN_01, 1, 2 }, // 0
    { SETTLER_SWORDSMAN_02, 1, 3 }, // 1
    { SETTLER_SWORDSMAN_03, 1, 4 }, // 2
    { SETTLER_BOWMAN_01, 2, 2 },    // 3
    { SETTLER_BOWMAN_02, 2, 3 },    // 4
    { SETTLER_BOWMAN_03, 2, 4 },    // 5
    {}
};

// address=[0x1311060]
// Decompiled from void __thiscall CAIPlayerEvaluation::EvaluateWarriors(CAIPlayerEvaluation *this, int _iPlayerId)

void CAIPlayerEvaluation::EvaluateWarriors(int _iPlayerId) {
    int aSettlerWeights[16] = {};

    int iEvalType = 0;
    for(DWORD i = 0; s_sAISettlerEvalWeights[i].m_iType; ++i) {
        int iNumberOfSettlers = IAIEnvironment::SettlerGetNumberOfSettlers(_iPlayerId, s_sAISettlerEvalWeights[i].m_iType);
        iEvalType = s_sAISettlerEvalWeights[i].m_iEvalType;
        g_pMsgTracer2->PushFormatedInts(
            "SettlerEvals %i, Eval type %i number: %i",
            i,
            iEvalType,
            iNumberOfSettlers);
        aSettlerWeights[2 * iEvalType] += iNumberOfSettlers;
        aSettlerWeights[2 * iEvalType + 1] += s_sAISettlerEvalWeights[i].m_iWeight * iNumberOfSettlers;
    }
    for(DWORD j = 0; s_sAIOfferedSettlerEvalWeights[j].m_iType; ++j) {
        int iNumberOfOfferedSettlers = g_cSettlerMgr.GetNumberOfOfferedSettlers(
            _iPlayerId,
            s_sAIOfferedSettlerEvalWeights[j].m_iType);
        iEvalType = s_sAIOfferedSettlerEvalWeights[j].m_iEvalType;
        g_pMsgTracer2->PushFormatedInts(
            "SettlerEvalsEx %i, Eval type %i number: %i",
            j,
            iEvalType,
            iNumberOfOfferedSettlers);
        aSettlerWeights[2 * iEvalType] += iNumberOfOfferedSettlers;
        aSettlerWeights[2 * iEvalType + 1] += s_sAIOfferedSettlerEvalWeights[j].m_iWeight * iNumberOfOfferedSettlers;
    }
    int iFighterNumber = aSettlerWeights[10] + aSettlerWeights[8] + aSettlerWeights[6];
    int iFighterValue = aSettlerWeights[11] + aSettlerWeights[9] + aSettlerWeights[7];
    int uLeaderValue = aSettlerWeights[13];
    g_pMsgTracer2->PushFormatedInts(
        "FighterNumber %i, FighterValue %i, LeaderValue %i.",
        iFighterNumber,
        iFighterValue,
        aSettlerWeights[13]);
    this->m_uOfferedSwordmen = aSettlerWeights[2];
    this->m_uOfferedBowmen = aSettlerWeights[4];
    this->m_uTotalSwordmen = aSettlerWeights[6];
    this->m_uTotalBowmen = aSettlerWeights[8];
    g_pMsgTracer2->PushFormatedInts(
        "OfferedSwordmen %i, OfferedBowmen %i, TotalSwordmen %i, TotalBowmen %i.",
        this->m_uOfferedSwordmen,
        this->m_uOfferedBowmen,
        this->m_uTotalSwordmen,
        this->m_uTotalBowmen);
    this->m_uSpecialistsCount = aSettlerWeights[10];
    this->m_uLeadersCount = aSettlerWeights[12];
    this->m_uPriestsCount = aSettlerWeights[14];
    g_pMsgTracer2->PushFormatedInts(
        "SpecialistsNumber %i, LeadersNumber %i, PriestsNumber %i",
        this->m_uSpecialistsCount,
        this->m_uLeadersCount,
        this->m_uPriestsCount);
    this->m_uTotalUnitCount = this->m_uPriestsCount + this->m_uLeadersCount + iFighterNumber;
    this->m_uTotalFighterCount = uLeaderValue + iFighterValue;
    DWORD uFighterNumberEx = aSettlerWeights[10] + aSettlerWeights[4] + aSettlerWeights[2]; // Specialist + Bowmen + Swordmen
    int uFighterValueEx = aSettlerWeights[11] + aSettlerWeights[5] + aSettlerWeights[3];
    this->m_uTotalUnitCountEx = this->m_uPriestsCount + this->m_uLeadersCount + uFighterNumberEx;
    this->m_uTotalUnitValueEx = uLeaderValue + uFighterValueEx;
    g_pMsgTracer2->PushFormatedInts(
        "FighterNumberEx %i, FighterValueEx %i",
        uFighterNumberEx,
        uFighterValueEx);
    g_pMsgTracer2->PushFormatedInts(
        "CAIPlayerEvaluation(MilUnits): Player %i: %i %i %i %i",
        _iPlayerId,
        this->m_uTotalUnitCount,
        this->m_uTotalFighterCount,
        this->m_uTotalUnitCountEx,
        this->m_uTotalUnitValueEx);
}

struct SAIBuildingEvalWeight {
    S4_BUILDING_ENUM m_iType;
    int m_iWeight;
};

SAIBuildingEvalWeight s_sAIBuildingEvalWeights[4] = {
    { BUILDING_GUARDTOWERSMALL, 1 },
    { BUILDING_GUARDTOWERBIG, 2 },
    { BUILDING_CASTLE, 4 },
    {}
};

// address=[0x1311400]
// Decompiled from void __thiscall CAIPlayerEvaluation::EvaluateBuildings(CAIPlayerEvaluation *this, DWORD a2)
void CAIPlayerEvaluation::EvaluateBuildings(int a2) {
    // [esp+0h] [ebp-18h]
    // [esp+4h] [ebp-14h]
    // [esp+8h] [ebp-10h]
    // [esp+10h] [ebp-8h]

    int uTotalWarBuildingCount = 0;
    int uTotalWarBuildingValue = 0;
    int i = 0;
    this->m_uSmallTowerCount = IAIEnvironment::BuildingGetNumberOfBuildings(a2, 0x2E, 2u);
    this->m_uBigTowerCount = IAIEnvironment::BuildingGetNumberOfBuildings(a2, 0x2F, 2u);
    this->m_uCastleCount = IAIEnvironment::BuildingGetNumberOfBuildings(a2, 0x30, 2u);
    while(s_sAIBuildingEvalWeights[i].m_iType) {
        int NumberOfBuildings = IAIEnvironment::BuildingGetNumberOfBuildings(a2, s_sAIBuildingEvalWeights[i].m_iType, 2u);
        uTotalWarBuildingCount += NumberOfBuildings;
        uTotalWarBuildingValue += NumberOfBuildings * s_sAIBuildingEvalWeights[i++].m_iWeight;
    }
    this->m_uTotalWarBuildingCount = uTotalWarBuildingCount;
    this->m_uTotalWarBuildingValue = uTotalWarBuildingValue;
    g_pMsgTracer2->PushFormatedInts(
        "CAIPlayerEvaluation(MilBuildings): Player %i: %i %i",
        a2,
        this->m_uTotalWarBuildingCount,
        this->m_uTotalWarBuildingValue);
}
