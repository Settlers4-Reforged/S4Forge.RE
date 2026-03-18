#if FALSE
#include "CAIPlayerEvaluation.h"

// Definitions for class CAIPlayerEvaluation

// address=[0x1310d40]
// Decompiled from void __thiscall CAIPlayerEvaluation::Clear(CAIPlayerEvaluation *this)
void  CAIPlayerEvaluation::Clear(void) {
  
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
void  CAIPlayerEvaluation::EvaluatePlayer(int a2) {
  
  DWORD Seed; // eax
  DWORD NumberOfRandCalls; // [esp-4h] [ebp-8h]

  this->m_uAITick = IAIEnvironment::TickCounter();
  NumberOfRandCalls = CRandom16::GetNumberOfRandCalls((CRandom16 *)&g_pGameData->m_sRandom);
  Seed = CRandom16::GetSeed((CRandom16 *)&g_pGameData->m_sRandom);
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "==> Evaluation: AI_tick %u, seed 0x%08x, counter %u",
    this->m_uAITick,
    Seed,
    NumberOfRandCalls);
  CAIPlayerEvaluation::EvaluateGoods(this, a2);
  CAIPlayerEvaluation::EvaluateWarriors(this, a2);
  CAIPlayerEvaluation::EvaluateBuildings(this, a2);
}


// address=[0x1310ea0]
// Decompiled from void __thiscall CAIPlayerEvaluation::DbgPrint(CAIPlayerEvaluation *this)
void  CAIPlayerEvaluation::DbgPrint(void) {
  
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
void  CAIPlayerEvaluation::EvaluateGoods(int a2) {
  
  int iRace; // [esp+0h] [ebp-Ch]

  iRace = IAIEnvironment::PlayerRace(a2);
  this->m_uSwordCount = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, GOOD_SWORD);
  this->m_uBowCount = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, GOOD_BOW);
  switch ( iRace )
  {
    case 1:
      this->m_uSpecialWeaponCount = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, GOOD_BATTLEAXE);
      break;
    case 2:
      this->m_uSpecialWeaponCount = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, GOOD_BLOWGUN);
      break;
    case 4:
      this->m_uSpecialWeaponCount = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, GOOD_BACKPACKCATAPULT);
      break;
    default:
      this->m_uSpecialWeaponCount = 0;
      break;
  }
  this->m_uTotalWeaponCount = this->m_uSpecialWeaponCount + this->m_uBowCount + this->m_uSwordCount;
  this->m_uGoldCount = CStatistic::GetGood((CStatistic *)&g_cStatistic, a2, GOOD_GOLDBAR);
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "CAIPlayerEvaluation(Goods): Player %i: %i %i %i %i",
    a2,
    this->m_uSwordCount,
    this->m_uBowCount,
    this->m_uSpecialWeaponCount,
    this->m_uGoldCount);
}


// address=[0x1311060]
// Decompiled from void __thiscall CAIPlayerEvaluation::EvaluateWarriors(CAIPlayerEvaluation *this, int _iPlayerId)
void  CAIPlayerEvaluation::EvaluateWarriors(int _iPlayerId) {
  
  DWORD uFighterNumberEx; // [esp+0h] [ebp-7Ch]
  int uFighterValueEx; // [esp+4h] [ebp-78h]
  DWORD uFighterValue; // [esp+8h] [ebp-74h]
  DWORD uFighterNumber; // [esp+Ch] [ebp-70h]
  int uLeaderValue; // [esp+10h] [ebp-6Ch]
  DWORD NumberOfOfferedSettlers; // [esp+14h] [ebp-68h]
  DWORD uNumberOfSettlers; // [esp+18h] [ebp-64h]
  DWORD iEvalType; // [esp+28h] [ebp-54h] MAPDST
  DWORD j; // [esp+2Ch] [ebp-50h]
  DWORD i; // [esp+30h] [ebp-4Ch]
  _DWORD aSettlerWeights[16]; // [esp+38h] [ebp-44h] BYREF

  memset(aSettlerWeights, 0, sizeof(aSettlerWeights));
  for ( i = 0; s_sAISettlerEvalWeights[i].m_iType; ++i )
  {
    uNumberOfSettlers = IAIEnvironment::SettlerGetNumberOfSettlers(_iPlayerId, s_sAISettlerEvalWeights[i].m_iType);
    iEvalType = s_sAISettlerEvalWeights[i].m_iEvalType;
    IMessageTracer::PushFormatedInts(
      g_pMsgTracer2,
      "SettlerEvals %i, Eval type %i number: %i",
      i,
      iEvalType,
      uNumberOfSettlers);
    aSettlerWeights[2 * iEvalType] += uNumberOfSettlers;
    aSettlerWeights[2 * iEvalType + 1] += s_sAISettlerEvalWeights[i].m_iWeight * uNumberOfSettlers;
  }
  for ( j = 0; s_sAIOfferedSettlerEvalWeights[j].m_iType; ++j )
  {
    NumberOfOfferedSettlers = CSettlerMgr::GetNumberOfOfferedSettlers(
                                (CSettlerMgr *)g_cSettlerMgr,
                                _iPlayerId,
                                s_sAIOfferedSettlerEvalWeights[j].m_iType);
    iEvalType = s_sAIOfferedSettlerEvalWeights[j].m_iEvalType;
    IMessageTracer::PushFormatedInts(
      g_pMsgTracer2,
      "SettlerEvalsEx %i, Eval type %i number: %i",
      j,
      iEvalType,
      NumberOfOfferedSettlers);
    aSettlerWeights[2 * iEvalType] += NumberOfOfferedSettlers;
    aSettlerWeights[2 * iEvalType + 1] += s_sAIOfferedSettlerEvalWeights[j].m_iWeight * NumberOfOfferedSettlers;
  }
  uFighterNumber = aSettlerWeights[10] + aSettlerWeights[8] + aSettlerWeights[6];
  uFighterValue = aSettlerWeights[11] + aSettlerWeights[9] + aSettlerWeights[7];
  uLeaderValue = aSettlerWeights[13];
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "FighterNumber %i, FighterValue %i, LeaderValue %i.",
    uFighterNumber,
    uFighterValue,
    aSettlerWeights[13]);
  this->m_uOfferedSwordmen = aSettlerWeights[2];
  this->m_uOfferedBowmen = aSettlerWeights[4];
  this->m_uTotalSwordmen = aSettlerWeights[6];
  this->m_uTotalBowmen = aSettlerWeights[8];
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "OfferedSwordmen %i, OfferedBowmen %i, TotalSwordmen %i, TotalBowmen %i.",
    this->m_uOfferedSwordmen,
    this->m_uOfferedBowmen,
    this->m_uTotalSwordmen,
    this->m_uTotalBowmen);
  this->m_uSpecialistsCount = aSettlerWeights[10];
  this->m_uLeadersCount = aSettlerWeights[12];
  this->m_uPriestsCount = aSettlerWeights[14];
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "SpecialistsNumber %i, LeadersNumber %i, PriestsNumber %i",
    this->m_uSpecialistsCount,
    this->m_uLeadersCount,
    this->m_uPriestsCount);
  this->m_uTotalUnitCount = this->m_uPriestsCount + this->m_uLeadersCount + uFighterNumber;
  this->m_uTotalFighterCount = uLeaderValue + uFighterValue;
  uFighterNumberEx = aSettlerWeights[10] + aSettlerWeights[4] + aSettlerWeights[2];// Specialist + Bowmen + Swordmen
  uFighterValueEx = aSettlerWeights[11] + aSettlerWeights[5] + aSettlerWeights[3];
  this->m_uTotalUnitCountEx = this->m_uPriestsCount + this->m_uLeadersCount + uFighterNumberEx;
  this->m_uTotalUnitValueEx = uLeaderValue + uFighterValueEx;
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "FighterNumberEx %i, FighterValueEx %i",
    uFighterNumberEx,
    uFighterValueEx);
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "CAIPlayerEvaluation(MilUnits): Player %i: %i %i %i %i",
    _iPlayerId,
    this->m_uTotalUnitCount,
    this->m_uTotalFighterCount,
    this->m_uTotalUnitCountEx,
    this->m_uTotalUnitValueEx);
}


// address=[0x1311400]
// Decompiled from void __thiscall CAIPlayerEvaluation::EvaluateBuildings(CAIPlayerEvaluation *this, DWORD a2)
void  CAIPlayerEvaluation::EvaluateBuildings(int a2) {
  
  int NumberOfBuildings; // [esp+0h] [ebp-18h]
  int uTotalWarBuildingValue; // [esp+4h] [ebp-14h]
  int uTotalWarBuildingCount; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]

  uTotalWarBuildingCount = 0;
  uTotalWarBuildingValue = 0;
  i = 0;
  this->m_uSmallTowerCount = IAIEnvironment::BuildingGetNumberOfBuildings(a2, BUILDING_GUARDTOWERSMALL, 2u);
  this->m_uBigTowerCount = IAIEnvironment::BuildingGetNumberOfBuildings(a2, BUILDING_GUARDTOWERBIG, 2u);
  this->m_uCastleCount = IAIEnvironment::BuildingGetNumberOfBuildings(a2, BUILDING_CASTLE, 2u);
  while ( s_sAIBuildingEvalWeights[i].m_iType )
  {
    NumberOfBuildings = IAIEnvironment::BuildingGetNumberOfBuildings(a2, s_sAIBuildingEvalWeights[i].m_iType, 2u);
    uTotalWarBuildingCount += NumberOfBuildings;
    uTotalWarBuildingValue += NumberOfBuildings * s_sAIBuildingEvalWeights[i++].m_iWeight;
  }
  this->m_uTotalWarBuildingCount = uTotalWarBuildingCount;
  this->m_uTotalWarBuildingValue = uTotalWarBuildingValue;
  IMessageTracer::PushFormatedInts(
    g_pMsgTracer2,
    "CAIPlayerEvaluation(MilBuildings): Player %i: %i %i",
    a2,
    this->m_uTotalWarBuildingCount,
    this->m_uTotalWarBuildingValue);
}


#endif // Already implemented
