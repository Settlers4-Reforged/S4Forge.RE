#if FALSE
#include "SPlayerStatistic.h"

// Definitions for class SPlayerStatistic

// address=[0x1478cc0]
// Decompiled from void __thiscall CStatistic::SPlayerStatistic::UpdateFightingStrength(CStatistic::SPlayerStatistic *this, int _iPlayerId, int _iBoards, int _iStone, int _iGold, bool _bEyeCatcher)
void  CStatistic::SPlayerStatistic::UpdateFightingStrength(int _iPlayerId, int _iBoards, int _iStone, int _iGold, bool _bEyeCatcher) {
  
  this->m_iTotalUsedBuildingMaterial += _iBoards;
  this->m_iTotalUsedBuildingMaterial += _iStone;
  this->m_iTotalUsedBuildingMaterial += _iGold;
  this->m_iTotalBuiltWood += _iBoards;
  this->m_iTotalBuildStone += _iStone;
  this->m_iTotalBuiltGold += _iGold;
  if ( _bEyeCatcher )
  {
    this->m_iTotalBuiltEyecatcherWood += _iBoards;
    this->m_iTotalBuiltEyecatcherStone += _iStone;
    this->m_iTotalBuiltEyecatcherGold += _iGold;
  }
  CStatistic::SPlayerStatistic::CalculateFightingStrength(this, _iPlayerId);
}


// address=[0x1478da0]
// Decompiled from void __thiscall CStatistic::SPlayerStatistic::CalculateFightingStrength(CStatistic::SPlayerStatistic *this, int _iOwnerId)
void  CStatistic::SPlayerStatistic::CalculateFightingStrength(int _iOwnerId) {
  
  int v2; // [esp+4h] [ebp-6Ch]
  int v3; // [esp+10h] [ebp-60h]
  int iEyecatcher; // [esp+14h] [ebp-5Ch]
  int v5; // [esp+18h] [ebp-58h]
  int iFightingStrengthDivisor; // [esp+1Ch] [ebp-54h]
  int iHighestEyecatcherCount; // [esp+20h] [ebp-50h]
  int v8; // [esp+24h] [ebp-4Ch]
  int i; // [esp+28h] [ebp-48h]
  int iEffectiveOffenceStrength256; // [esp+2Ch] [ebp-44h]
  bool v11; // [esp+33h] [ebp-3Dh]
  int iTemp; // [esp+34h] [ebp-3Ch]
  S4_BUILDING_ENUM vEyecatcherBuildings[12]; // [esp+3Ch] [ebp-34h]

  if ( this->m_iOffenceStrengthBase256 <= 0 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1213, "m_iOffenceStrengthBase256 > 0") == 1 )
  {
    __debugbreak();
  }
  v11 = CStaticConfigVarInt::operator int(&g_iDbgIgnoreFightingStrength) == 1;
  iEffectiveOffenceStrength256 = 256;
  if ( this->m_iOffenceStrength100_2 <= 0 )
  {
    if ( this->m_iOffenceStrengthBase256 != 256 && !v11 )
    {
      if ( g_pGameType && CPlayerManager::IsAI(_iOwnerId) && g_pAI->IsInitialised(g_pAI) && IAIDifficultyLevels::GetDifficultyLevel(_iOwnerId) >= 2 )
      {
        v8 = this->m_iTotalBuildStone + this->m_iTotalBuiltWood + 2 * this->m_iTotalBuiltGold;
        v5 = v8;
      }
      else
      {
        v8 = this->m_iTotalBuildStone + this->m_iTotalBuiltWood + 2 * this->m_iTotalBuiltGold;
        v5 = 2 * (this->m_iTotalBuiltEyecatcherStone + this->m_iTotalBuiltEyecatcherWood + 2 * this->m_iTotalBuiltEyecatcherGold);
      }
      if ( CStaticConfigVarInt::operator int((CStaticConfigVarInt *)&g_iFightingStrengthDivisor) <= 0 )
      {
        iFightingStrengthDivisor = 1000;
      }
      else
      {
        iFightingStrengthDivisor = CStaticConfigVarInt::operator int((CStaticConfigVarInt *)&g_iFightingStrengthDivisor);
      }
      v2 = (((v5 + v8) << 8) + 127) / iFightingStrengthDivisor + this->m_iOffenceStrengthBase256;
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
      iHighestEyecatcherCount = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, _iOwnerId, BUILDING_EYECATCHER01, 1u);
      for ( i = 1;
            i < 12;
            ++i )
      {
        iEyecatcher = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, _iOwnerId, vEyecatcherBuildings[i], 1u);
        if ( iEyecatcher < iHighestEyecatcherCount )
        {
          iHighestEyecatcherCount = iEyecatcher;
        }
      }
      iTemp = v2 + 30 * iHighestEyecatcherCount;
      if ( iTemp > 128 )
      {
        iTemp = (iTemp - 128) / 2 + 128;
        if ( iTemp > 256 )
        {
          iTemp = (iTemp - 256) / 2 + 256;
          if ( iTemp > 320 )
          {
            iTemp = (iTemp - 320) / 2 + 320;
            if ( iTemp > 384 )
            {
              iTemp = 384;
            }
          }
        }
      }
      if ( iTemp <= 0 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1333, "iTemp > 0") == 1 )
      {
        __debugbreak();
      }
      iEffectiveOffenceStrength256 = iTemp;
    }
  }
  else
  {
    iEffectiveOffenceStrength256 = this->m_iOffenceStrength100_2;
  }
  if ( g_pGameData && CGameData::GetMode(g_pGameData) == 3 )
  {
    if ( iEffectiveOffenceStrength256 < 4 )
    {
      v3 = 1;
    }
    else
    {
      v3 = iEffectiveOffenceStrength256 / 4;
    }
    iEffectiveOffenceStrength256 = v3;
  }
  this->m_iEffectiveOffenceStrength256 = iEffectiveOffenceStrength256;
  if ( this->m_iEffectiveOffenceStrength256 <= 0 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1346, "m_iEffectiveOffenceStrength256 > 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_iEffectiveOffenceStrength256 > 384 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1347, "m_iEffectiveOffenceStrength256 <= 384") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_iEffectiveOffenceStrength256 <= 256 )
  {
    this->m_iEffectiveDefenceStrength256 = 256;
  }
  else
  {
    this->m_iEffectiveDefenceStrength256 = (this->m_iEffectiveOffenceStrength256 - 256) / 2 + 256;
  }
  this->m_iDefenceStrength100 = *(_DWORD *)std::max<int>(&this->m_iDefenceStrength100, &this->m_iEffectiveDefenceStrength256);
  this->m_iOffenceStrength100 = *(_DWORD *)std::max<int>(&this->m_iOffenceStrength100, &this->m_iEffectiveOffenceStrength256);
}


#endif // Already implemented
