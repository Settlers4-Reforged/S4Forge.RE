#include "CStatistic.h"

#include "CBB/CBBSupport.h"
#include "CPlayerGameData.h"
#include "Defines/Buildings.h"
#include "Defines/Goods.h"
#include "Defines/Players.h"
#include "Defines/Races.h"
#include "Defines/Settlers.h"
#include "Defines/Vehicle.h"
#include "Events/CEvn_Event.h"
#include "Events/IEventEngine.h"
#include "Info/CExtendedMenuInfo.h"
#include "Main/CGameData.h"
#include "Main/CGameType.h"
#include "Main/Players/CPlayerManager.h"
#include "MapObjects/Building/CBuildingInfoMgr.h"
#include "Pathing/CAlliances.h"
#include "Pathing/ITiling.h"

// Definitions for class CStatistic

CStatistic g_cStatistic{};

// address=[0x3F29D98]
CStaticConfigVarInt g_iDbgIgnoreFightingStrength{ "LOGIC", "DbgIgnoreFightingStrength", 0 };
// address=[0x3F29DA4]
CStaticConfigVarInt g_iFightingStrengthDivisor{ "LOGIC", "FightingStrengthDivisor", 1000 };

// address=[0x13adcc0]
// Decompiled from int __thiscall CStatistic::DefenceStrength100Max(CStatistic *this, int a2)
int CStatistic::DefenceStrength100Max(int _iPlayerId) const {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    return (100 * this->m_sPlayerStats[_iPlayerId].m_iDefenceStrength100) >> 8;
}

// address=[0x13add30]
// Decompiled from DWORD __thiscall CStatistic::GetDontShowLastNPlayers(CStatistic *this)
int CStatistic::GetDontShowLastNPlayers(void) {

    return this->m_iDontShowLastNPlayers;
}

// address=[0x13add50]
// Decompiled from int __thiscall CStatistic::OffenceStrength100Max(CStatistic *this, int _iPlayerId)
int CStatistic::OffenceStrength100Max(int _iPlayerId) const {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    return (100 * this->m_sPlayerStats[_iPlayerId].m_iOffenceStrength100) >> 8;
}

// address=[0x1475d60]
// Decompiled from CStatistic *__thiscall CStatistic::CStatistic(CStatistic *this)
CStatistic::CStatistic(void) : IS4ChunkObject() {
    CStatistic::Clear();
}

// address=[0x1475d90]
// Decompiled from void *__thiscall CStatistic::Clear(CStatistic *this)
void CStatistic::Clear(void) {
    memset(this->m_sPlayerStats, 0, sizeof(this->m_sPlayerStats));
    this->m_iDontShowLastNPlayers = 0;
}

// address=[0x1475dc0]
// Decompiled from void __thiscall CStatistic::Init(CStatistic *this)
void CStatistic::Init(void) {
    CStatistic::Clear();
    CStatistic::CalcPlayerOffenceStrengthBaseValues();
    CStatistic::CalculateFightingStrengths();
}

// address=[0x1475df0]
// Decompiled from void __thiscall CStatistic::Update(CStatistic *this)
void CStatistic::Update(void) {
    CStatistic::CalculateLandSize();
    CStatistic::CalculateMana();
    CStatistic::CalculateFightingStrengths();
    if((int)g_pGameType->m_iTeamWon > 0 && !CStatistic::m_bWonStateSaved) {
        CStatistic::m_bWonStateSaved = 1;
        for(int i = 0; i < 9; ++i)
            memcpy(
                this->m_sPlayerStats[i].m_iWinGoods,
                this->m_sPlayerStats[i].m_iNrOfGood,
                sizeof(this->m_sPlayerStats[i].m_iWinGoods));
    }
}

// address=[0x1475e80]
// Decompiled from void __thiscall CStatistic::Update(CStatistic *this, struct CStatistic *a2)
void CStatistic::Update(class CStatistic &a2) {
    a2.Update();
    memcpy(this->m_sPlayerStats, a2.m_sPlayerStats, 0x9A6Cu);
}

// address=[0x1475ed0]
// Decompiled from void __thiscall CStatistic::Load(CStatistic *this, struct IS4Chunk *a2)
void CStatistic::Load(class IS4Chunk &a2) {

    // [esp+4h] [ebp-Ch]
    // [esp+8h] [ebp-8h]
    unsigned int uStructSize; // [esp+Ch] [ebp-4h]

    CStatistic::Clear();
    a2.LoadSignature(762231707);
    unsigned int v3 = a2.LoadUnsigned32(3, 4);
    if(v3 == 3)
        uStructSize = 4388;
    else
        uStructSize = a2.LoadUnsigned32(0, 4392);

    BB_ASSERT(uStructSize <= sizeof(SPlayerStatistic))
    static_assert(sizeof(SPlayerStatistic) == 0x1128, "Size must match with original");

    for(int i = 0; i < PLAYER_MAX; ++i)
        a2.Load(&this->m_sPlayerStats[i], uStructSize);
    if(v3 >= 4)
        a2.LoadSignature(762231803);
}

// address=[0x1475fc0]
// Decompiled from void __thiscall CStatistic::Save(CStatistic *this, struct IS4Chunk *a2)
void CStatistic::Save(class IS4Chunk &a2) {

    CStatistic::Update();
    a2.SaveSignature(762231707);
    a2.SaveUnsigned32(4);
    a2.SaveUnsigned32(4392);
    a2.Save(this->m_sPlayerStats, sizeof(this->m_sPlayerStats));
    static_assert(sizeof(this->m_sPlayerStats) == 0x9A68u, "Size must match with original");
    a2.SaveSignature(762231803);
}

// address=[0x1476040]
// Decompiled from void __thiscall CStatistic::DecSettler(CStatistic *this, int _iPlayerId, S4_SETTLER_ENUM _iSettlerType)
void CStatistic::DecSettler(int _iPlayerId, int _iSettlerType) {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    BB_ASSERT((_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX))
    BB_ASSERT(m_sPlayerStats[_iPlayerId].m_iNrOfSettler[_iSettlerType] > 0)
    BB_ASSERT(m_sPlayerStats[_iPlayerId].m_iTotalNrOfSettler > 0)

    if(this->m_sPlayerStats[_iPlayerId].m_iNrOfSettler[_iSettlerType] > 0)
        --this->m_sPlayerStats[_iPlayerId].m_iNrOfSettler[_iSettlerType];
    if(this->m_sPlayerStats[_iPlayerId].m_iTotalNrOfSettler > 0)
        --this->m_sPlayerStats[_iPlayerId].m_iTotalNrOfSettler;
    switch(CSettlerMgr::SettlerWarriorType(_iSettlerType)) {
    case 0:
        BB_ASSERT(m_sPlayerStats[_iPlayerId].m_iNrOfCivilian > 0)

        if(this->m_sPlayerStats[_iPlayerId].m_iNrOfCivilian > 0)
            --this->m_sPlayerStats[_iPlayerId].m_iNrOfCivilian;
        break;
    case 1:
    case 6:
    case 7:
    case 14:
        return;
    default:
        BB_ASSERT(m_sPlayerStats[_iPlayerId].m_iNrOfSoldier > 0)
        if(this->m_sPlayerStats[_iPlayerId].m_iNrOfSoldier > 0)
            --this->m_sPlayerStats[_iPlayerId].m_iNrOfSoldier;
        break;
    }
}

// address=[0x14762c0]
// Decompiled from void __thiscall CStatistic::AddSettler(CStatistic *this, int a2, S4_SETTLER_ENUM _iSettlerType)
void CStatistic::AddSettler(int _iPlayerId, int _iSettlerType) {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    BB_ASSERT((_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX))

    ++this->m_sPlayerStats[_iPlayerId].m_iNrOfSettler[_iSettlerType];
    ++this->m_sPlayerStats[_iPlayerId].m_iTotalNrOfSettler;
    switch(CSettlerMgr::SettlerWarriorType(_iSettlerType)) {
    case 0:
        ++this->m_sPlayerStats[_iPlayerId].m_iNrOfCivilian;
        break;
    case 1:
    case 6:
    case 7:
    case 14:
        return;
    default:
        ++this->m_sPlayerStats[_iPlayerId].m_iNrOfSoldier;
        break;
    }
}

// address=[0x1476410]
// Decompiled from int __thiscall CStatistic::GetSettler(CStatistic *this, int _iPlayerId, int _iSettlerType)
int CStatistic::GetSettler(int _iPlayerId, int _iSettlerType) const {

    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    BB_ASSERT((_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX))
    return this->m_sPlayerStats[_iPlayerId].m_iNrOfSettler[_iSettlerType];
}

// address=[0x1476490]
// Decompiled from int __thiscall CStatistic::GetTotalSettler(CStatistic *this, int a2)
int CStatistic::GetTotalSettler(int _iPlayerId) const {

    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    return this->m_sPlayerStats[_iPlayerId].m_iTotalOfSettler[SETTLER_CARRIER];
}

// address=[0x14764f0]
// Decompiled from int __thiscall CStatistic::GetCivilian(CStatistic *this, int a2)
int CStatistic::GetCivilian(int _iPlayerId) const {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    return this->m_sPlayerStats[_iPlayerId].m_iNrOfCivilian;
}

// address=[0x1476540]
// Decompiled from int __thiscall CStatistic::GetSoldiers(CStatistic *this, int _iPlayerId)
int CStatistic::GetSoldiers(int _iPlayerId) const {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    int v5 = 0;
    for(int i = 0; i < SETTLER_MAX; ++i) {
        int v4 = CSettlerMgr::SettlerWarriorType(i);
        if(v4 > 0 && v4 <= 6)
            v5 += this->m_sPlayerStats[_iPlayerId].m_iTotalOfSettler[i];
    }
    return v5;
}

// address=[0x14765e0]
// Decompiled from int __thiscall CStatistic::GetNrOfSoldiers(CStatistic *this, int a2)
int CStatistic::GetNrOfSoldiers(int _iPlayerId) const {

    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    return this->m_sPlayerStats[_iPlayerId].m_iNrOfSoldier;
}

// address=[0x1476630]
// Decompiled from void __thiscall CStatistic::AddProducedSettler(CStatistic *this, int a2, int _iSettlerType)
void CStatistic::AddProducedSettler(int _iPlayerId, int _iSettlerType) {

    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    BB_ASSERT((_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX))
    ++this->m_sPlayerStats[_iPlayerId].m_iTotalOfSettler[_iSettlerType];
    ++this->m_sPlayerStats[_iPlayerId].m_iProducedSettlers;
}

// address=[0x14766f0]
// Decompiled from int __thiscall CStatistic::GetProducedSettler(CStatistic *this, int _iPlayerId, int _iSettlerType)
int CStatistic::GetProducedSettler(int _iPlayerId, int _iSettlerType) const {

    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    BB_ASSERT((_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX))
    return this->m_sPlayerStats[_iPlayerId].m_iTotalOfSettler[_iSettlerType];
}

// address=[0x1476770]
// Decompiled from int __thiscall CStatistic::GetTotalProducedSettler(CStatistic *this, int _iPlayerId)
int CStatistic::GetTotalProducedSettler(int _iPlayerId) const {

    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    return this->m_sPlayerStats[_iPlayerId].m_iProducedSettlers;
}

// address=[0x14767c0]
// Decompiled from int __thiscall CStatistic::GetBuildingProductivity(CStatistic *this, int _iPlayerId, int _iBuildingType)
int CStatistic::GetBuildingProductivity(int _iPlayerId, int _iBuildingType) const {
    return this->m_sPlayerStats[_iPlayerId].m_iBuildingProductivity[_iBuildingType];
}

// address=[0x14767f0]
// Decompiled from void __thiscall CStatistic::AddBuilding(CStatistic *this, int a2, int a3, int a4)
void CStatistic::AddBuilding(int a2, int a3, int a4) {
    this->m_sPlayerStats[a2].m_iNrOfBuilding[a3] += a4;
    this->m_sPlayerStats[a2].m_iTotalOfBuilding += a4;
    CStatistic::UpdateFightingStrength(a2, CPlayerManager::Race(a2), a3, a4);
}

// address=[0x1476880]
// Decompiled from void __thiscall CStatistic::DecBuilding(CStatistic *this, int _iPlayerId, S4_BUILDING_ENUM _iBuildingType, int a4)
void CStatistic::DecBuilding(int _iPlayerId, int _iBuildingType, int _iAmount) {
    BBSupportTracePrintF(0, "CStatistic::DecBuilding(%i, %i, %i) called.", _iPlayerId, _iBuildingType, _iAmount);
    BB_ASSERT(m_sPlayerStats[_iPlayerId].m_iNrOfBuilding[_iBuildingType] >= _iAmount)
    this->m_sPlayerStats[_iPlayerId].m_iTotalOfBuilding -= _iAmount;
    this->m_sPlayerStats[_iPlayerId].m_iNrOfBuilding[_iBuildingType] -= _iAmount;
    CStatistic::UpdateFightingStrength(_iPlayerId, CPlayerManager::Race(_iPlayerId), _iBuildingType, -_iAmount);
}

// address=[0x1476960]
// Decompiled from int __thiscall CStatistic::GetBuildings(CStatistic *this, int _iPlayerId, int _iBuildingType)
int CStatistic::GetBuildings(int _iPlayerId, int _iBuildingType) const {

    return this->m_sPlayerStats[_iPlayerId].m_iNrOfBuilding[_iBuildingType];
}

// address=[0x1476990]
// Decompiled from void __thiscall CStatistic::AddProducedBuilding(CStatistic *this, int a2, int a3, int a4)
void CStatistic::AddProducedBuilding(int _iPlayerId, int _iBuilding, int a4) {

    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    BB_ASSERT(_iBuilding < BUILDING_MAX)

    this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedBuilding[_iBuilding] += a4;
    this->m_sPlayerStats[_iPlayerId].m_iProducedBuildings += a4;
}

// address=[0x1476a50]
// Decompiled from int __thiscall CStatistic::GetProducedBuildings(CStatistic *this, int _iPlayerId, int _iBuilding)
int CStatistic::GetProducedBuildings(int _iPlayerId, int _iBuilding) const {

    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    BB_ASSERT(_iBuilding < BUILDING_MAX)

    return this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedBuilding[_iBuilding];
}

// address=[0x1476ad0]
// Decompiled from int __thiscall CStatistic::GetTotalBuildings(CStatistic *this, int a2)
int CStatistic::GetTotalBuildings(int a2) const {

    return this->m_sPlayerStats[a2].m_iTotalOfBuilding;
}

// address=[0x1476af0]
// Decompiled from int __thiscall CStatistic::GetTotalProducedBuildings(CStatistic *this, int a2)
int CStatistic::GetTotalProducedBuildings(int a2) const {

    return this->m_sPlayerStats[a2].m_iProducedBuildings;
}

// address=[0x1476b10]
// Decompiled from int __thiscall CStatistic::GetTotalBuildingsOfType(CStatistic *this, int _iPlayerId, int _iBuilding)
int CStatistic::GetTotalBuildingsOfType(int _iPlayerId, int _iBuilding) const {
    int Buildings = CStatistic::GetBuildings(_iPlayerId, _iBuilding);
    return Buildings + CStatistic::GetConstructions(_iPlayerId, _iBuilding);
}

// address=[0x1476b50]
// Decompiled from void __thiscall CStatistic::AddCaptureBuilding(CStatistic *this, int _iPlayer, int _iTarget, int _iBuilding)
void CStatistic::AddCaptureBuilding(int _iPlayer, int _iTarget, int _iBuilding) {

    ++this->m_sPlayerStats[_iPlayer].m_iNrOfCapturedBuilding[_iBuilding];
    ++this->m_sPlayerStats[_iTarget].m_iNrOfLostBuilding[_iBuilding];
}

// address=[0x1476bd0]
// Decompiled from int __thiscall CStatistic::GetCapturedTowers(CStatistic *this, int _iPlayer)
int CStatistic::GetCapturedTowers(int _iPlayerId) {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    return this->m_sPlayerStats[_iPlayerId].m_iNrOfCapturedBuilding[BUILDING_CASTLE] + this->m_sPlayerStats[_iPlayerId].m_iNrOfCapturedBuilding[BUILDING_GUARDTOWERBIG] + this->m_sPlayerStats[_iPlayerId].m_iNrOfCapturedBuilding[BUILDING_GUARDTOWERSMALL];
}

// address=[0x1476c70]
// Decompiled from int __thiscall CStatistic::GetLossesTowers(CStatistic *this, int a2)
int CStatistic::GetLossesTowers(int a2) {
    return this->m_sPlayerStats[a2].m_iNrOfLostBuilding[BUILDING_CASTLE] + this->m_sPlayerStats[a2].m_iNrOfLostBuilding[BUILDING_GUARDTOWERBIG] + this->m_sPlayerStats[a2].m_iNrOfLostBuilding[BUILDING_GUARDTOWERSMALL];
}

// address=[0x1476ce0]
// Decompiled from void __thiscall CStatistic::AddConstruction(CStatistic *this, int _iPlayerId, int _iBuildingType, int _iCount)
void CStatistic::AddConstruction(int _iPlayerId, int _iBuildingType, int _iCount) {

    this->m_sPlayerStats[_iPlayerId].m_iNrOfBuildingSites[_iBuildingType] += _iCount;
    this->m_sPlayerStats[_iPlayerId].m_iTotalBuildingSites += _iCount;
}

// address=[0x1476d50]
// Decompiled from void __thiscall CStatistic::DecConstruction(CStatistic *this, int _iPlayerId, int _iBuildingType, int a4)
void CStatistic::DecConstruction(int _iPlayerId, int _iBuildingType, int _iAmount) {
    BB_ASSERT(m_sPlayerStats[_iPlayerId].m_iNrOfBuildingSites[_iBuildingType] >= _iAmount)
    this->m_sPlayerStats[_iPlayerId].m_iNrOfBuildingSites[_iBuildingType] -= _iAmount;
    this->m_sPlayerStats[_iPlayerId].m_iTotalBuildingSites -= _iAmount;
}

// address=[0x1476e00]
// Decompiled from int __thiscall CStatistic::GetTotalBuildingsUnderConstruction(_DWORD *this, int a2)
int CStatistic::GetTotalBuildingsUnderConstruction(int a2) const {
    return this->m_sPlayerStats[a2].m_iTotalBuildingSites;
}

// address=[0x1476e20]
// Decompiled from int __thiscall CStatistic::GetConstructions(CStatistic *this, int _iPlayerId, int _iBuildingType)
int CStatistic::GetConstructions(int _iPlayerId, int _iBuildingType) const {
    return this->m_sPlayerStats[_iPlayerId].m_iNrOfBuildingSites[_iBuildingType];
}

// address=[0x1476e50]
// Decompiled from void __thiscall CStatistic::ChangeResidenceNeed(CStatistic *this, int _iPlayerId, int _iCount)
void CStatistic::ChangeResidenceNeed(int _iPlayerId, int _iCount) {
    this->m_sPlayerStats[_iPlayerId].m_iResidenceNeed += _iCount;
}

// address=[0x1476e90]
// Decompiled from int __thiscall CStatistic::GetResidenceNeed(CStatistic *this, int a2)
int CStatistic::GetResidenceNeed(int a2) const {
    return this->m_sPlayerStats[a2].m_iNrOfSettler[1];
}

// address=[0x1476ec0]
// Decompiled from void __thiscall CStatistic::ChangeResidenceSpace(CStatistic *this, int a2, int a3)
void CStatistic::ChangeResidenceSpace(int a2, int a3) {
    this->m_sPlayerStats[a2].m_iResidenceSpace += a3;
}

// address=[0x1476f00]
// Decompiled from int __thiscall CStatistic::GetResidenceSpace(CStatistic *this, int _iPlayerId)
int CStatistic::GetResidenceSpace(int _iPlayerId) const {
    return g_cESMgr->GetNrOfCurrentTotalBeds(_iPlayerId);
}

// address=[0x1476f20]
// Decompiled from void __thiscall CStatistic::AddGood(CStatistic *this, int _iPlayerId, S4_GOOD_ENUM _iGood, int a4)
void CStatistic::AddGood(int _iPlayerId, int _iGood, int a4) {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    BB_ASSERT(_iGood < GOOD_MAX)
    this->m_sPlayerStats[_iPlayerId].m_iNrOfGood[_iGood] += a4;
    this->m_sPlayerStats[_iPlayerId].m_iTotalGoods += a4;
    if(!CStatistic::m_bWonStateSaved)
        this->m_sPlayerStats[_iPlayerId].m_iWinGoods[_iGood] = this->m_sPlayerStats[_iPlayerId].m_iNrOfGood[_iGood];
}

// address=[0x1477020]
// Decompiled from void __thiscall CStatistic::DecGood(CStatistic *this, int _iPlayerId, int _iGood, int _iCount)
void CStatistic::DecGood(int _iPlayerId, int _iGood, int _iCount) {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    BB_ASSERT(_iGood < GOOD_MAX)

    int v4 = _iCount;
    if(this->m_sPlayerStats[_iPlayerId].m_iNrOfGood[_iGood] < _iCount)
        v4 = this->m_sPlayerStats[_iPlayerId].m_iNrOfGood[_iGood];
    this->m_sPlayerStats[_iPlayerId].m_iNrOfGood[_iGood] -= v4;
    this->m_sPlayerStats[_iPlayerId].m_iTotalGoods -= v4;
}

// address=[0x1477120]
// Decompiled from int __thiscall CStatistic::GetGood(CStatistic *this, int _iPlayerId, int _iGood)
int CStatistic::GetGood(int _iPlayerId, int _iGood) const {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    BB_ASSERT(_iGood < GOOD_MAX)

    return this->m_sPlayerStats[_iPlayerId].m_iNrOfGood[_iGood];
}

// address=[0x14771a0]
// Decompiled from int __thiscall CStatistic::GetWinGood(CStatistic *this, int _iPlayerId, int _iGood)
int CStatistic::GetWinGood(int _iPlayerId, int _iGood) const {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    BB_ASSERT(_iGood < GOOD_MAX)

    return this->m_sPlayerStats[_iPlayerId].m_iWinGoods[_iGood];
}

// address=[0x1477220]
// Decompiled from int __thiscall CStatistic::GetTotalGood(CStatistic *this, int _iPlayerId)
int CStatistic::GetTotalGood(int _iPlayerId) const {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    return this->m_sPlayerStats[_iPlayerId].m_iTotalGoods;
}

// address=[0x1477270]
// Decompiled from void __thiscall CStatistic::AddProducedGoods(CStatistic *this, int _iPlayerId, int _iGood, int _iCount)
void CStatistic::AddProducedGoods(int _iPlayerId, int _iGood, int _iCount) {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    BB_ASSERT(_iGood < GOOD_MAX)

    this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[_iGood] += _iCount;
    this->m_sPlayerStats[_iPlayerId].m_iTotalProducedGoods += _iCount;
}

// address=[0x1477330]
// Decompiled from int __thiscall CStatistic::GetProducedGoods(CStatistic *this, int _iPlayerId, int _iGood)
int CStatistic::GetProducedGoods(int _iPlayerId, int _iGood) const {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    BB_ASSERT(_iGood < GOOD_MAX)

    return this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[_iGood];
}

// address=[0x14773b0]
// Decompiled from int __thiscall CStatistic::GetTotalProducedGood(CStatistic *this, int _iPlayerId)
int CStatistic::GetTotalProducedGood(int _iPlayerId) const {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)

    return this->m_sPlayerStats[_iPlayerId].m_iTotalProducedGoods;
}

// address=[0x1477400]
// Decompiled from void __thiscall CStatistic::AddVehicle(CStatistic *this, int _iPlayerId, int _iVehicleType, int _iCount)
void CStatistic::AddVehicle(int _iPlayerId, int _iVehicleType, int _iCount) {

    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    BB_ASSERT(_iVehicleType < VEHICLE_MAX)
    this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicle[_iVehicleType] += _iCount;
    this->m_sPlayerStats[_iPlayerId].m_iTotalVehicles += _iCount;
}

// address=[0x14774c0]
// Decompiled from void __thiscall CStatistic::DecVehicle(CStatistic *this, int _iPlayerId, int _iVehicleType, int _iCount)
void CStatistic::DecVehicle(int _iPlayerId, int _iVehicleType, int _iCount) {
    int v4 = _iCount;
    if(this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicle[_iVehicleType] < _iCount)
        v4 = this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicle[_iVehicleType];
    this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicle[_iVehicleType] -= v4;
    this->m_sPlayerStats[_iPlayerId].m_iTotalVehicles -= v4;
}

// address=[0x1477570]
// Decompiled from int __thiscall CStatistic::GetVehicle(CStatistic *this, int a2, int a3)
int CStatistic::GetVehicle(int a2, int a3) const {
    return this->m_sPlayerStats[a2].m_iNrOfVehicle[a3];
}

// address=[0x14775a0]
// Decompiled from int __thiscall CStatistic::GetTotalVehicle(CStatistic *this, int _iPlayerId)
int CStatistic::GetTotalVehicle(int _iPlayerId) const {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    return this->m_sPlayerStats[_iPlayerId].m_iTotalVehicles;
}

// address=[0x14775f0]
// Decompiled from void __thiscall CStatistic::AddProducedVehicle(CStatistic *this, int _iPlayerId, int _iVehicleType, int _iCount)
void CStatistic::AddProducedVehicle(int _iPlayerId, int _iVehicleType, int _iCount) {

    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    BB_ASSERT((_iVehicleType > 0) && (_iVehicleType < VEHICLE_MAX))

    this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedVehicle[_iVehicleType] += _iCount;
    this->m_sPlayerStats[_iPlayerId].m_iTotalProducedVehicles += _iCount;
}

// address=[0x14776b0]
// Decompiled from int __thiscall CStatistic::GetProducedVehicle(CStatistic *this, int _iPlayerId, int _iVehicleType)
int CStatistic::GetProducedVehicle(int _iPlayerId, int _iVehicleType) const {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    BB_ASSERT((_iVehicleType > 0) && (_iVehicleType < VEHICLE_MAX))

    return this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedVehicle[_iVehicleType];
}

// address=[0x1477730]
// Decompiled from int __thiscall CStatistic::GetTotalProducedVehicled(CStatistic *this, int _iPlayerId)
int CStatistic::GetTotalProducedVehicled(int _iPlayerId) const {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))

    return this->m_sPlayerStats[_iPlayerId].m_iTotalProducedVehicles;
}

// address=[0x1477780]
// Decompiled from int __thiscall CStatistic::GetMana(CStatistic *this, int _iPlayerId)
int CStatistic::GetMana(int _iPlayerId) const {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)

    return this->m_sPlayerStats[_iPlayerId].m_iMana;
}

// address=[0x14777d0]
// Decompiled from int __thiscall CStatistic::GetProducedMana(CStatistic *this, int a2)
int CStatistic::GetProducedMana(int _iPlayerId) const {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    return this->m_sPlayerStats[_iPlayerId].m_iProducedMana;
}

// address=[0x1477820]
// Decompiled from void __thiscall CStatistic::IncKillsOfType(CStatistic *this, int _iPlayerId, int _iSettlerType)
void CStatistic::IncKillsOfType(int _iPlayerId, int _iSettlerType) {

    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    BB_ASSERT(_iSettlerType > 0)

    if(_iSettlerType < SETTLER_MAX) {
        ++this->m_sPlayerStats[_iPlayerId].m_iNrOfKill[_iSettlerType];
        ++this->m_sPlayerStats[_iPlayerId].m_iTotalKills;
    }
}

// address=[0x14778e0]
// Decompiled from int __thiscall CStatistic::GetKillsOfType(CStatistic *this, int _iPlayerId, int _iSettlerType)
int CStatistic::GetKillsOfType(int _iPlayerId, int _iSettlerType) const {

    return this->m_sPlayerStats[_iPlayerId].m_iNrOfKill[_iSettlerType];
}

// address=[0x1477910]
// Decompiled from int __thiscall CStatistic::GetKills(CStatistic *this, int _iPlayerId)
int CStatistic::GetKills(int _iPlayerId) const {

    return this->m_sPlayerStats[_iPlayerId].m_iTotalKills;
}

// address=[0x1477930]
// Decompiled from void __thiscall CStatistic::IncLossesOfType(CStatistic *this, int _iPlayerId, int _iSettlerType)
void CStatistic::IncLossesOfType(int _iPlayerId, int _iSettlerType) {

    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    BB_ASSERT(_iSettlerType > 0)

    if(_iSettlerType < SETTLER_MAX) {
        ++this->m_sPlayerStats[_iPlayerId].m_iNrOfLoss[_iSettlerType];
        ++this->m_sPlayerStats[_iPlayerId].m_iTotalLosses;
    }
}

// address=[0x14779f0]
// Decompiled from int __thiscall CStatistic::GetLossesOfType(CStatistic *this, int _iPlayerId, int _iSettlerType)
int CStatistic::GetLossesOfType(int _iPlayerId, int _iSettlerType) const {
    return this->m_sPlayerStats[_iPlayerId].m_iNrOfLoss[_iSettlerType];
}

// address=[0x1477a20]
// Decompiled from int __thiscall CStatistic::GetLosses(CStatistic *this, int _iPlayerId)
int CStatistic::GetLosses(int _iPlayerId) const {
    return this->m_sPlayerStats[_iPlayerId].m_iTotalLosses;
}

// address=[0x1477a40]
// Decompiled from void __thiscall CStatistic::IncKillsVehicleOfType(CStatistic *this, int _iPlayerId, int _iVehicleType)
void CStatistic::IncKillsVehicleOfType(int _iPlayerId, int _iVehicleType) {

    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    BB_ASSERT((_iVehicleType > 0) && (_iVehicleType < VEHICLE_MAX))

    ++this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicleKill[_iVehicleType];
    ++this->m_sPlayerStats[_iPlayerId].m_iTotalVehicleKills;
}

// address=[0x1477b00]
// Decompiled from int __thiscall CStatistic::GetKillsVehicleOfType(CStatistic *this, int _iPlayerId, int _iVehicleType)
int CStatistic::GetKillsVehicleOfType(int _iPlayerId, int _iVehicleType) const {

    return this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicleKill[_iVehicleType];
}

// address=[0x1477b30]
// Decompiled from int __thiscall CStatistic::GetKillsVehicle(CStatistic *this, int _iPlayerId)
int CStatistic::GetKillsVehicle(int _iPlayerId) const {

    return this->m_sPlayerStats[_iPlayerId].m_iTotalVehicleKills;
}

// address=[0x1477b50]
// Decompiled from void __thiscall CStatistic::IncLossesVehicleOfType(CStatistic *this, int _iPlayerId, int _iVehicleType)
void CStatistic::IncLossesVehicleOfType(int _iPlayerId, int _iVehicleType) {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    BB_ASSERT((_iVehicleType > 0) && (_iVehicleType < VEHICLE_MAX))

    ++this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicleLoss[_iVehicleType];
    ++this->m_sPlayerStats[_iPlayerId].m_iTotalVehicleLosses;
}

// address=[0x1477c10]
// Decompiled from int __thiscall CStatistic::GetLossesVehicleOfType(CStatistic *this, int _iPlayerId, int _iVehicleType)
int CStatistic::GetLossesVehicleOfType(int _iPlayerId, int _iVehicleType) const {

    return this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicleLoss[_iVehicleType];
}

// address=[0x1477c40]
// Decompiled from int __thiscall CStatistic::GetLossesVehicle(CStatistic *this, int _iPlayerId)
int CStatistic::GetLossesVehicle(int _iPlayerId) const {

    return this->m_sPlayerStats[_iPlayerId].m_iTotalVehicleLosses;
}

// address=[0x1477c60]
// Decompiled from void __thiscall CStatistic::IncBuildingLosses(CStatistic *this, int _iPlayerId)
void CStatistic::IncBuildingLosses(int _iPlayerId) {

    ++this->m_sPlayerStats[_iPlayerId].m_iTotalBuildingLosses;
}

// address=[0x1477ca0]
// Decompiled from int __thiscall CStatistic::GetBuildingLosses(CStatistic *this, int _iPlayerId)
int CStatistic::GetBuildingLosses(int _iPlayerId) {

    return this->m_sPlayerStats[_iPlayerId].m_iTotalBuildingLosses;
}

// address=[0x1477cc0]
// Decompiled from void __thiscall CStatistic::DecLandSize(CStatistic *this, int a2, int a3)
void CStatistic::DecLandSize(int a2, int a3) {

    ;
}

// address=[0x1477cd0]
// Decompiled from void __thiscall CStatistic::IncLandSize(CStatistic *this, int a2, int a3)
void CStatistic::IncLandSize(int a2, int a3) {

    ;
}

// address=[0x1477ce0]
// Decompiled from int __thiscall CStatistic::GetLandSize(CStatistic *this, int a2)
int CStatistic::GetLandSize(int a2) const {

    return this->m_sPlayerStats[a2].m_iLandSize;
}

// address=[0x1477d00]
// Decompiled from int __thiscall CStatistic::GetMaxLandSize(CStatistic *this, int a2)
int CStatistic::GetMaxLandSize(int a2) const {

    return this->m_sPlayerStats[a2].m_iMaxLandSize;
}

// address=[0x1477d20]
// Decompiled from int __thiscall CStatistic::GetLandSizePercent(CStatistic *this, int a2)
int CStatistic::GetLandSizePercent(int a2) {
    CStatistic::CalculateLandSize();
    return this->m_sPlayerStats[a2].m_iLandSize;
}

// address=[0x1477d50]
// Decompiled from void __thiscall CStatistic::SetOffenceStrength100(CStatistic *this, int a2, int a3)
void CStatistic::SetOffenceStrength100(int _iPlayerId, int a3) {
    BB_ASSERT(_iPlayerId >= 1 && _iPlayerId < PLAYER_MAX)

    if(_iPlayerId < 1 || _iPlayerId >= PLAYER_MAX)
        return;

    int iOffenceStrengthBase256 = 0;
    if(a3 > 0) {
        iOffenceStrengthBase256 = (a3 << 8) / 100;
        if(iOffenceStrengthBase256 >= this->m_sPlayerStats[_iPlayerId].m_iOffenceStrengthBase256) {
            if(iOffenceStrengthBase256 > 384)
                iOffenceStrengthBase256 = 384;
        } else {
            iOffenceStrengthBase256 = this->m_sPlayerStats[_iPlayerId].m_iOffenceStrengthBase256;
        }
    }
    this->m_sPlayerStats[_iPlayerId].m_iOffenceStrength100_2 = iOffenceStrengthBase256;
    this->m_sPlayerStats[_iPlayerId].CalculateFightingStrength(_iPlayerId);
}

// address=[0x1477e10]
// Decompiled from int __thiscall CStatistic::UsedBuildingMaterial(CStatistic *this, int _iPlayerId)
int CStatistic::UsedBuildingMaterial(int _iPlayerId) const {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)

    return this->m_sPlayerStats[_iPlayerId].m_iTotalUsedBuildingMaterial;
}

// address=[0x1477e60]
// Decompiled from int __thiscall CStatistic::GetTotalTowers(CStatistic *this, int _iPlayerId)
int CStatistic::GetTotalTowers(int _iPlayerId) {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)

    return this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedBuilding[BUILDING_CASTLE] + this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedBuilding[BUILDING_GUARDTOWERBIG] + this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedBuilding[BUILDING_GUARDTOWERSMALL];
}

// address=[0x1477f00]
// Decompiled from int __thiscall CStatistic::GetTotalMineProduction(CStatistic *this, int a2)
int CStatistic::GetTotalMineProduction(int _iPlayerId) {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    return this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[GOOD_IRONORE] + this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[GOOD_SULFUR] + this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[GOOD_GOLDORE] + this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[GOOD_COAL];
}

// address=[0x1477fb0]
// Decompiled from int __thiscall CStatistic::GetTotalFood(CStatistic *this, int _iPlayerId)
int CStatistic::GetTotalFood(int _iPlayerId) {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    return this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[GOOD_MEAT] + this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[GOOD_FISH] + this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[GOOD_BREAD];
}

// address=[0x1478050]
// Decompiled from void __thiscall CStatistic::SetPlayerExitTime(CStatistic *this, int _iPlayerId, int _iExitTime)
void CStatistic::SetPlayerExitTime(int _iPlayerId, unsigned int _iExitTime) {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    this->m_sPlayerStats[_iPlayerId].m_iExitTime = _iExitTime;
}

// address=[0x14780a0]
// Decompiled from int __thiscall CStatistic::GetPlayerExitTime(CStatistic *this, int _iPlayerId)
unsigned int CStatistic::GetPlayerExitTime(int _iPlayerId) {
    BB_ASSERT(_iPlayerId > 0 && _iPlayerId < PLAYER_MAX)
    return this->m_sPlayerStats[_iPlayerId].m_iExitTime;
}

// address=[0x14780f0]
// Decompiled from void __thiscall CStatistic::UpdateStartStatistic(CStatistic *this)
void CStatistic::UpdateStartStatistic(void) {
    for(int i = 1; i <= 8; ++i) {
        for(int j = 0; j < SETTLER_MAX; ++j) {
            this->m_sPlayerStats[i].m_iTotalOfSettler[j] = this->m_sPlayerStats[i].m_iNrOfSettler[j];
            this->m_sPlayerStats[i].m_iProducedSettlers += this->m_sPlayerStats[i].m_iNrOfSettler[j];
        }
        for(int k = 0; k < BUILDING_MAX; ++k) {
            this->m_sPlayerStats[i].m_iNrOfProducedBuilding[k] = this->m_sPlayerStats[i].m_iNrOfBuilding[k];
            this->m_sPlayerStats[i].m_iProducedBuildings += this->m_sPlayerStats[i].m_iNrOfBuilding[k];
        }
        for(int m = 0; m < 6; ++m) {
            this->m_sPlayerStats[i].m_iNrOfProducedVehicle[m] = this->m_sPlayerStats[i].m_iNrOfVehicle[m];
            this->m_sPlayerStats[i].m_iTotalProducedVehicles += this->m_sPlayerStats[i].m_iNrOfVehicle[m];
        }
        for(int n = 0; n < GOOD_MAX; ++n) {
            this->m_sPlayerStats[i].m_iNrOfProducedGoods[n] = this->m_sPlayerStats[i].m_iNrOfGood[n];
            this->m_sPlayerStats[i].m_iTotalProducedGoods += this->m_sPlayerStats[i].m_iNrOfGood[n];
        }
    }
}

// address=[0x1478330]
// Decompiled from _DWORD *__thiscall CStatistic::FillExtraInfo(CStatistic *this)
void CStatistic::FillExtraInfo(void) {
    g_cExtendedMenuInfo.Clear();
    int a1 = CPlayerManager::GetLocalPlayerId();
    DWORD v28 = 0;
    CPlayerGameData &v30 = CPlayerManager::PlayerGameData(a1);
    v30.ResetIterator();
    for(int i = v30.GetNextEcoSectorId(); i; i = v30.GetNextEcoSectorId()) {
        CEcoSector *pEcoSector = g_cESMgr->GetEcoSectorPtr(i);
        if(pEcoSector && pEcoSector->Owner() == a1) {
            int v1 = pEcoSector->NrOfSettler(SETTLER_CARRIER);
            int v27 = v1 - pEcoSector->MinCarrier();
            if(v27 > 0)
                v28 += v27;
        }
    }
    g_cExtendedMenuInfo.m_uCarriers = v28;
    g_cExtendedMenuInfo.m_uNrTotalBeds = g_cESMgr->GetNrOfCurrentTotalBeds(a1);
    g_cExtendedMenuInfo.m_uGoodsBoards = CStatistic::GetGood(a1, GOOD_BOARD);
    g_cExtendedMenuInfo.m_uGoodsStone = CStatistic::GetGood(a1, GOOD_STONE);
    g_cExtendedMenuInfo.m_uGoodsGoldbars = CStatistic::GetGood(a1, GOOD_GOLDBAR);
    int Good = CStatistic::GetGood(a1, GOOD_BOW);
    int v3 = CStatistic::GetGood(a1, GOOD_SWORD) + Good;
    int v4 = CStatistic::GetGood(a1, GOOD_BATTLEAXE) + v3;
    int v5 = CStatistic::GetGood(a1, GOOD_BLOWGUN) + v4;
    g_cExtendedMenuInfo.m_uGoodsWeapons = CStatistic::GetGood(a1, GOOD_BACKPACKCATAPULT) + v5;
    int v6 = CStatistic::GetGood(a1, GOOD_BREAD);
    int v7 = CStatistic::GetGood(a1, GOOD_MEAT) + v6;
    g_cExtendedMenuInfo.m_uGoodsFood = CStatistic::GetGood(a1, GOOD_FISH) + v7;
    int NumberOfSettlers = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_SWORDSMAN_01);
    int v9 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_SWORDSMAN_02) + NumberOfSettlers;
    int v10 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_SWORDSMAN_03) + v9;
    int v11 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_BOWMAN_01) + v10;
    int v12 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_BOWMAN_02) + v11;
    int v13 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_BOWMAN_03) + v12;
    int v14 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_AXEWARRIOR_01) + v13;
    int v15 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_AXEWARRIOR_02) + v14;
    int v16 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_AXEWARRIOR_03) + v15;
    int v17 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_BLOWGUNWARRIOR_01) + v16;
    int v18 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_BLOWGUNWARRIOR_02) + v17;
    int v19 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_BLOWGUNWARRIOR_03) + v18;
    int v20 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_MEDIC_01) + v19;
    int v21 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_MEDIC_02) + v20;
    int v22 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_MEDIC_03) + v21;
    int v23 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_BACKPACKCATAPULTIST_01) + v22;
    int v24 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_BACKPACKCATAPULTIST_02) + v23;
    int v25 = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_BACKPACKCATAPULTIST_03) + v24;
    g_cExtendedMenuInfo.m_uSoldierCount = g_cSettlerMgr->GetNumberOfSettlers(a1, SETTLER_SQUADLEADER) + v25;
    g_cExtendedMenuInfo.m_uOffenseStrength = CStatistic::OffenceStrength100(a1);
    g_cExtendedMenuInfo.m_uDefenceStrength = CStatistic::DefenceStrength100(a1);
    g_cExtendedMenuInfo.m_uMana = CStatistic::GetMana(a1);
    g_cExtendedMenuInfo.m_iUnknown = 0x25;

    BB_ASSERT(g_pEvnEngine != NULL)

    CEvn_Event v34(0x25Cu, 0, reinterpret_cast<unsigned int>(&g_cExtendedMenuInfo), 0);
    if(g_pEvnEngine)
        g_pEvnEngine->SendAMessage(v34);
}

// address=[0x1478720]
// Decompiled from void CStatistic::FillEconomyGameMenu(struct CInfoExchange *a1, bool a2, bool a3)
void __cdecl CStatistic::FillEconomyGameMenu(class CInfoExchange *a1, bool a2, bool a3) {
    g_cEconomyGameInfo->Clear();
    g_cEconomyGameInfo.m_iUnknown = 36;
    for(int i = 0; i < 7; ++i) {
        DWORD v4 = g_pGameData->GetEconomyGoodsArray()[i];
        g_cEconomyGameInfo.m_sStats[i].m_uEconomyGood = v4;
        for(int j = 1; j <= CPlayerManager::LastPlayerId(); ++j) {
            if(CAlliances::AllianceId(j) == 1)
                g_cEconomyGameInfo.m_sStats[i].m_uWinGoodsAllies += g_cStatistic.GetWinGood(j, v4);
            else
                g_cEconomyGameInfo.m_sStats[i].m_uWinGoodsOther += g_cStatistic.GetWinGood(j, v4);
        }
    }
    struct CEvn_Event v7(0x25Au, 0, reinterpret_cast<unsigned int>(&g_cEconomyGameInfo), 0);

    g_pEvnEngine->SendAMessage(v7);
}

// address=[0x1478890]
// Decompiled from void __thiscall CStatistic::FreezeEcoStatistic(CStatistic *this)
void CStatistic::FreezeEcoStatistic(void) {

    // [esp+4h] [ebp-4h]

    if(!CStatistic::m_bWonStateSaved) {
        CStatistic::m_bWonStateSaved = 1;
        for(int i = 0; i < 9; ++i)
            memcpy(
                this->m_sPlayerStats[i].m_iWinGoods,
                this->m_sPlayerStats[i].m_iNrOfGood,
                sizeof(this->m_sPlayerStats[i].m_iWinGoods));
    }
}

// address=[0x147a280]
// Decompiled from int __thiscall CStatistic::DefenceStrength100(CStatistic *this, int _iPlayerId)
int CStatistic::DefenceStrength100(int _iPlayerId) const {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))

    return (100 * this->m_sPlayerStats[_iPlayerId].m_iEffectiveDefenceStrength256) >> 8;
}

// address=[0x147a3b0]
// Decompiled from int __thiscall CStatistic::OffenceStrength100(CStatistic *this, int _iPlayerId)
int CStatistic::OffenceStrength100(int _iPlayerId) const {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    return (100 * this->m_sPlayerStats[_iPlayerId].m_iEffectiveOffenceStrength256) >> 8;
}

// address=[0x14aa6b0]
// Decompiled from CStatistic *__thiscall CStatistic::CStatistic(CStatistic *this, CStatistic *a2)
CStatistic::CStatistic(class CStatistic const &a2) : IS4ChunkObject() {
    memcpy(this->m_sPlayerStats, a2.m_sPlayerStats, sizeof(m_sPlayerStats));
}

// address=[0x1592160]
// Decompiled from int __thiscall CStatistic::DefenceStrength256(CStatistic *this, int _iPlayerId)
int CStatistic::DefenceStrength256(int _iPlayerId) const {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    return this->m_sPlayerStats[_iPlayerId].m_iEffectiveDefenceStrength256;
}

// address=[0x1592220]
// Decompiled from int __thiscall CStatistic::OffenceStrength256(CStatistic *this, int _iPlayerId)
int CStatistic::OffenceStrength256(int _iPlayerId) const {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    return this->m_sPlayerStats[_iPlayerId].m_iEffectiveOffenceStrength256;
}

// address=[0x160db70]
// Decompiled from void __thiscall CStatistic::SetDontShowLastNPlayers(CStatistic *this, DWORD _iPlayers)
void CStatistic::SetDontShowLastNPlayers(int _iPlayers) {

    this->m_iDontShowLastNPlayers = _iPlayers;
}

// address=[0x1478900]
// Decompiled from void __thiscall CStatistic::CalcPlayerOffenceStrengthBaseValues(CStatistic *this)
void CStatistic::CalcPlayerOffenceStrengthBaseValues(void) {

    // [esp+4h] [ebp-10h]
    // [esp+Ch] [ebp-8h]
    // [esp+10h] [ebp-4h]

    int iNumberOfPlayers = CPlayerManager::NumberOfPlayers();
    BB_ASSERT(iNumberOfPlayers > 0)

    if(iNumberOfPlayers > 0) {
        int iOffenceStrengthBase256 = 768 / (iNumberOfPlayers + 4);
        BB_ASSERT(iOffenceStrengthBase256 > 0)

        for(int i = 1; i < iNumberOfPlayers + 1; ++i) {
            if(CPlayerManager::Race(i) == 3)
                this->m_sPlayerStats[i].m_iOffenceStrengthBase256 = 256;
            else
                this->m_sPlayerStats[i].m_iOffenceStrengthBase256 = iOffenceStrengthBase256;
            this->m_sPlayerStats[i].CalculateFightingStrength(i);
        }
    }
}

// address=[0x1478a00]
// Decompiled from void __thiscall CStatistic::UpdateFightingStrength(  CStatistic *this,  int _iPlayerId,  unsigned int _iRace,  S4_BUILDING_ENUM _iBuildingType,  int a5)
void CStatistic::UpdateFightingStrength(int _iPlayerId, int _iRace, int _iBuildingType, int a5) {
    BB_ASSERT((_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST))
    BB_ASSERT((_iRace >= 0) && (_iRace < RACE_MAX))
    BB_ASSERT((_iBuildingType > BUILDING_NO_BUILDING) && (_iBuildingType < BUILDING_MAX))

    CBuildingInfoMgr::SBuildingInfos const &rBuildingInfo = CBuildingInfoMgr::GetBuildingInfo(_iRace, _iBuildingType);
    if(_iBuildingType < BUILDING_EYECATCHER01 || _iBuildingType > BUILDING_EYECATCHER12)
        this->m_sPlayerStats[_iPlayerId].UpdateFightingStrength(
            _iPlayerId,
            rBuildingInfo.m_iBoards * a5,
            rBuildingInfo.m_iStone * a5,
            rBuildingInfo.m_iGold * a5,
            0);
    else
        this->m_sPlayerStats[_iPlayerId].UpdateFightingStrength(
            _iPlayerId,
            rBuildingInfo.m_iBoards * a5,
            rBuildingInfo.m_iStone * a5,
            rBuildingInfo.m_iGold * a5,
            1);
}

// address=[0x1478b20]
// Decompiled from void __thiscall CStatistic::CalculateFightingStrengths(CStatistic *this)
void CStatistic::CalculateFightingStrengths(void) {
    int PlayerId = CPlayerManager::LastPlayerId();
    for(int i = 1; i <= PlayerId; ++i)
        this->m_sPlayerStats[i].CalculateFightingStrength(i);
}

// address=[0x1478b70]
// Decompiled from void __thiscall CStatistic::CalculateLandSize(CStatistic *this)
void CStatistic::CalculateLandSize(void) {

    // esi
    // [esp+4h] [ebp-Ch]
    // [esp+Ch] [ebp-4h]

    int PlayerId = CPlayerManager::LastPlayerId();
    for(int i = 1; i <= PlayerId; ++i) {
        this->m_sPlayerStats[i].m_iLandSize = g_pTiling->NumberOfOwnedLandElements(i);
        int v1 = 100 * this->m_sPlayerStats[i].m_iLandSize;
        this->m_sPlayerStats[i].m_iLandSize = v1 / g_pTiling->NumberOfLandElements();
        this->m_sPlayerStats[i].m_iMaxLandSize = std::max<long>(
            this->m_sPlayerStats[i].m_iMaxLandSize,
            this->m_sPlayerStats[i].m_iLandSize);
    }
}

// address=[0x1478c50]
// Decompiled from void __thiscall CStatistic::CalculateMana(CStatistic *this)
void CStatistic::CalculateMana(void) {
    int iPlayerId = CPlayerManager::LastPlayerId();
    for(int i = 1; i <= iPlayerId; ++i) {
        this->m_sPlayerStats[i].m_iMana = CMagic::GetCurrentManaAmount(i);
        this->m_sPlayerStats[i].m_iProducedMana = CMagic::TotalAmountOfCollectedMana(i);
    }
}

// address=[0x3f20320]
// [Decompilation failed for static bool CStatistic::m_bWonStateSaved]
