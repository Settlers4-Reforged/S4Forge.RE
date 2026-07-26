#include "SPlayerStatistic.h"

#include "CBB/CBBSupport.h"
#include "Defines/Buildings.h"
#include "Main/CGameData.h"
#include "Main/CGameType.h"
#include "Main/Players/CPlayerManager.h"

// Definitions for class SPlayerStatistic

// address=[0x1478cc0]
// Decompiled from void __thiscall CStatistic::SPlayerStatistic::UpdateFightingStrength(  CStatistic::SPlayerStatistic *this,  int _iPlayerId,  int _iBoards,  int _iStone,  int _iGold,  bool _bEyeCatcher)
void CStatistic::SPlayerStatistic::UpdateFightingStrength(int _iPlayerId, int _iBoards, int _iStone, int _iGold, bool _bEyeCatcher) {

    this->m_iTotalUsedBuildingMaterial += _iBoards;
    this->m_iTotalUsedBuildingMaterial += _iStone;
    this->m_iTotalUsedBuildingMaterial += _iGold;
    this->m_iTotalBuiltWood += _iBoards;
    this->m_iTotalBuildStone += _iStone;
    this->m_iTotalBuiltGold += _iGold;
    if(_bEyeCatcher) {
        this->m_iTotalBuiltEyecatcherWood += _iBoards;
        this->m_iTotalBuiltEyecatcherStone += _iStone;
        this->m_iTotalBuiltEyecatcherGold += _iGold;
    }
    CStatistic::SPlayerStatistic::CalculateFightingStrength(_iPlayerId);
}

// address=[0x1478da0]
// Decompiled from void __thiscall CStatistic::SPlayerStatistic::CalculateFightingStrength(  CStatistic::SPlayerStatistic *this,  int _iOwnerId)
void CStatistic::SPlayerStatistic::CalculateFightingStrength(int _iOwnerId) {

    BB_ASSERT(m_iOffenceStrengthBase256 > 0)
    int iEffectiveOffenceStrength256 = 256;
    if(this->m_iOffenceStrength100_2 <= 0) {
        if(this->m_iOffenceStrengthBase256 != 256 && !g_iDbgIgnoreFightingStrength == 1) {
            S4_BUILDING_ENUM vEyecatcherBuildings[12];
            int iFightingStrengthDivisor;

            int v5;
            int v8;
            if(g_pGameType && CPlayerManager::IsAI(_iOwnerId) && g_pAI->IsInitialised() && IAIDifficultyLevels::GetDifficultyLevel(_iOwnerId) >= 2) {
                v8 = this->m_iTotalBuildStone + this->m_iTotalBuiltWood + 2 * this->m_iTotalBuiltGold;
                v5 = v8;
            } else {
                v8 = this->m_iTotalBuildStone + this->m_iTotalBuiltWood + 2 * this->m_iTotalBuiltGold;
                v5 = 2 * (this->m_iTotalBuiltEyecatcherStone + this->m_iTotalBuiltEyecatcherWood + 2 * this->m_iTotalBuiltEyecatcherGold);
            }
            if(g_iFightingStrengthDivisor <= 0)
                iFightingStrengthDivisor = 1000;
            else
                iFightingStrengthDivisor = g_iFightingStrengthDivisor;
            int v2 = (((v5 + v8) << 8) + 127) / iFightingStrengthDivisor + this->m_iOffenceStrengthBase256;
            vEyecatcherBuildings[0] = BUILDING_EYECATCHER01;
            vEyecatcherBuildings[1] = BUILDING_EYECATCHER02;
            vEyecatcherBuildings[2] = BUILDING_EYECATCHER03;
            vEyecatcherBuildings[3] = BUILDING_EYECATCHER04;
            vEyecatcherBuildings[4] = BUILDING_EYECATCHER05;
            vEyecatcherBuildings[5] = BUILDING_EYECATCHER06;
            vEyecatcherBuildings[6] = BUILDING_EYECATCHER07;
            vEyecatcherBuildings[7] = BUILDING_EYECATCHER08;
            vEyecatcherBuildings[8] = BUILDING_EYECATCHER09;
            vEyecatcherBuildings[9] = BUILDING_EYECATCHER10;
            vEyecatcherBuildings[10] = BUILDING_EYECATCHER11;
            vEyecatcherBuildings[11] = BUILDING_EYECATCHER12;
            int iLowestEyecatcher = g_cBuildingMgr->GetNumberOfBuildings(
                _iOwnerId,
                BUILDING_EYECATCHER01,
                1u);
            for(int i = 1; i < 12; ++i) {
                int iEyecatcher = g_cBuildingMgr->GetNumberOfBuildings(
                    _iOwnerId,
                    vEyecatcherBuildings[i],
                    1u);
                if(iEyecatcher < iLowestEyecatcher)
                    iLowestEyecatcher = iEyecatcher;
            }
            int iTemp = v2 + 30 * iLowestEyecatcher;
            if(iTemp > 128) {
                iTemp = (iTemp - 128) / 2 + 128;
                if(iTemp > 256) {
                    iTemp = (iTemp - 256) / 2 + 256;
                    if(iTemp > 320) {
                        iTemp = (iTemp - 320) / 2 + 320;
                        if(iTemp > 384)
                            iTemp = 384;
                    }
                }
            }
            BB_ASSERT(iTemp > 0)
            iEffectiveOffenceStrength256 = iTemp;
        }
    } else {
        iEffectiveOffenceStrength256 = this->m_iOffenceStrength100_2;
    }
    if(g_pGameData && g_pGameData->GetMode() == 3) {
        iEffectiveOffenceStrength256 = iEffectiveOffenceStrength256 < 4 ? 1 : iEffectiveOffenceStrength256 / 4;
    }
    this->m_iEffectiveOffenceStrength256 = iEffectiveOffenceStrength256;
    BB_ASSERT(m_iEffectiveOffenceStrength256 > 0);
    BB_ASSERT(m_iEffectiveOffenceStrength256 <= 384);

    if(this->m_iEffectiveOffenceStrength256 <= 256)
        this->m_iEffectiveDefenceStrength256 = 256;
    else
        this->m_iEffectiveDefenceStrength256 = (this->m_iEffectiveOffenceStrength256 - 256) / 2 + 256;
    this->m_iDefenceStrength100 = std::max<int>(
        this->m_iDefenceStrength100,
        this->m_iEffectiveDefenceStrength256);
    this->m_iOffenceStrength100 = std::max<int>(
        this->m_iOffenceStrength100,
        this->m_iEffectiveOffenceStrength256);
}
