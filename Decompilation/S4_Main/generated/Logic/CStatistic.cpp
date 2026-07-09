#if FALSE
#include "CStatistic.h"

// Definitions for class CStatistic

// address=[0x13adcc0]
// Decompiled from int __thiscall CStatistic::DefenceStrength100Max(CStatistic *this, int a2)
int  CStatistic::DefenceStrength100Max(int a2)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\Statistic.h",
         365,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return (100 * this->m_sPlayerStats[a2].m_iDefenceStrength100) >> 8;
}


// address=[0x13add30]
// Decompiled from DWORD __thiscall CStatistic::GetDontShowLastNPlayers(CStatistic *this)
int  CStatistic::GetDontShowLastNPlayers(void) {
  
  return this->m_iDontShowLastNPlayers;
}


// address=[0x13add50]
// Decompiled from int __thiscall CStatistic::OffenceStrength100Max(CStatistic *this, int _iPlayerId)
int  CStatistic::OffenceStrength100Max(int _iPlayerId)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\Statistic.h",
         381,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return (100 * this->m_sPlayerStats[_iPlayerId].m_iOffenceStrength100) >> 8;
}


// address=[0x1475d60]
// Decompiled from CStatistic *__thiscall CStatistic::CStatistic(CStatistic *this)
 CStatistic::CStatistic(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  this->__vftable = (IS4ChunkObject_vtbl *)CStatistic::_vftable_;
  CStatistic::Clear(this);
  return this;
}


// address=[0x1475d90]
// Decompiled from void *__thiscall CStatistic::Clear(CStatistic *this)
void  CStatistic::Clear(void) {
  
  void *result; // eax

  result = memset(this->m_sPlayerStats, 0, sizeof(this->m_sPlayerStats));
  this->m_iDontShowLastNPlayers = 0;
  return result;
}


// address=[0x1475dc0]
// Decompiled from void __thiscall CStatistic::Init(CStatistic *this)
void  CStatistic::Init(void) {
  
  CStatistic::Clear(this);
  CStatistic::CalcPlayerOffenceStrengthBaseValues(this);
  CStatistic::CalculateFightingStrengths(this);
}


// address=[0x1475df0]
// Decompiled from void __thiscall CStatistic::Update(CStatistic *this)
void  CStatistic::Update(void) {
  
  int i; // [esp+4h] [ebp-4h]

  CStatistic::CalculateLandSize(this);
  CStatistic::CalculateMana(this);
  CStatistic::CalculateFightingStrengths(this);
  if ( (int)g_pGameType->m_iTeamWon > 0 && !CStatistic::m_bWonStateSaved )
  {
    CStatistic::m_bWonStateSaved = 1;
    for ( i = 0; i < 9; ++i )
      memcpy(
        this->m_sPlayerStats[i].m_iWinGoods,
        this->m_sPlayerStats[i].m_iNrOfGood,
        sizeof(this->m_sPlayerStats[i].m_iWinGoods));
  }
}


// address=[0x1475e80]
// Decompiled from void __thiscall CStatistic::Update(CStatistic *this, struct CStatistic *a2)
void  CStatistic::Update(class CStatistic & a2) {
  
  CStatistic::Update(a2);
  memcpy(this->m_sPlayerStats, a2->m_sPlayerStats, 0x9A6Cu);
}


// address=[0x1475ed0]
// Decompiled from void __thiscall CStatistic::Load(CStatistic *this, struct IS4Chunk *a2)
void  CStatistic::Load(class IS4Chunk & a2) {
  
  unsigned int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  unsigned int uStructSize; // [esp+Ch] [ebp-4h]

  CStatistic::Clear(this);
  a2->LoadSignature(762231707);
  v3 = a2->LoadUnsigned32(3, 4);
  if ( v3 == 3 )
    uStructSize = 4388;
  else
    uStructSize = a2->LoadUnsigned32(0, 4392);
  if ( uStructSize > 0x1128
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 118, "uStructSize <= sizeof(SPlayerStatistic)") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0; i < 9; ++i )
    a2->Load(&this->m_sPlayerStats[i], uStructSize);
  if ( v3 >= 4 )
    a2->LoadSignature(762231803);
}


// address=[0x1475fc0]
// Decompiled from void __thiscall CStatistic::Save(CStatistic *this, struct IS4Chunk *a2)
void  CStatistic::Save(class IS4Chunk & a2) {
  
  CStatistic::Update(this);
  a2->SaveSignature(762231707);
  a2->SaveUnsigned32(4);
  a2->SaveUnsigned32(4392);
  a2->Save(this->m_sPlayerStats, 0x9A68u);
  a2->SaveSignature(762231803);
}


// address=[0x1476040]
// Decompiled from void __thiscall CStatistic::DecSettler(CStatistic *this, int _iPlayerId, S4_SETTLER_ENUM _iSettlerType)
void  CStatistic::DecSettler(int _iPlayerId, int _iSettlerType) {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 328, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerType <= SETTLER_NO_SETTLER || _iSettlerType >= SETTLER_MAX)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 329, "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_sPlayerStats[_iPlayerId].m_iNrOfSettler[_iSettlerType] <= 0
    && BBSupportDbgReport(
         2,
         "Logic\\Statistic.cpp",
         331,
         "m_sPlayerStats[_iPlayerId].m_iNrOfSettler[_iSettlerType] > 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_sPlayerStats[_iPlayerId].m_iTotalNrOfSettler <= 0
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 332, "m_sPlayerStats[_iPlayerId].m_iTotalNrOfSettler > 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_sPlayerStats[_iPlayerId].m_iNrOfSettler[_iSettlerType] > 0 )
    --this->m_sPlayerStats[_iPlayerId].m_iNrOfSettler[_iSettlerType];
  if ( this->m_sPlayerStats[_iPlayerId].m_iTotalNrOfSettler > 0 )
    --this->m_sPlayerStats[_iPlayerId].m_iTotalNrOfSettler;
  switch ( CSettlerMgr::SettlerWarriorType(_iSettlerType) )
  {
    case 0:
      if ( this->m_sPlayerStats[_iPlayerId].m_iNrOfCivilian <= 0
        && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 369, "m_sPlayerStats[_iPlayerId].m_iNrOfCivilian > 0") == 1 )
      {
        __debugbreak();
      }
      if ( this->m_sPlayerStats[_iPlayerId].m_iNrOfCivilian > 0 )
        --this->m_sPlayerStats[_iPlayerId].m_iNrOfCivilian;
      break;
    case 1:
    case 6:
    case 7:
    case 14:
      return;
    default:
      if ( this->m_sPlayerStats[_iPlayerId].m_iNrOfSoldier <= 0
        && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 380, "m_sPlayerStats[_iPlayerId].m_iNrOfSoldier > 0") == 1 )
      {
        __debugbreak();
      }
      if ( this->m_sPlayerStats[_iPlayerId].m_iNrOfSoldier > 0 )
        --this->m_sPlayerStats[_iPlayerId].m_iNrOfSoldier;
      break;
  }
}


// address=[0x14762c0]
// Decompiled from void __thiscall CStatistic::AddSettler(CStatistic *this, int a2, S4_SETTLER_ENUM _iSettlerType)
void  CStatistic::AddSettler(int a2, int _iSettlerType) {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 283, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerType <= SETTLER_NO_SETTLER || _iSettlerType >= SETTLER_MAX)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 284, "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  ++this->m_sPlayerStats[a2].m_iNrOfSettler[_iSettlerType];
  ++this->m_sPlayerStats[a2].m_iTotalNrOfSettler;
  switch ( CSettlerMgr::SettlerWarriorType(_iSettlerType) )
  {
    case 0:
      ++this->m_sPlayerStats[a2].m_iNrOfCivilian;
      break;
    case 1:
    case 6:
    case 7:
    case 14:
      return;
    default:
      ++this->m_sPlayerStats[a2].m_iNrOfSoldier;
      break;
  }
}


// address=[0x1476410]
// Decompiled from int __thiscall CStatistic::GetSettler(CStatistic *this, int _iPlayerId, int _iSettlerType)
int  CStatistic::GetSettler(int _iPlayerId, int _iSettlerType)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 398, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerType <= 0 || _iSettlerType >= 67)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 399, "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfSettler[_iSettlerType];
}


// address=[0x1476490]
// Decompiled from int __thiscall CStatistic::GetTotalSettler(CStatistic *this, int a2)
int  CStatistic::GetTotalSettler(int a2)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 412, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[a2].m_iTotalOfSettler[SETTLER_CARRIER];
}


// address=[0x14764f0]
// Decompiled from int __thiscall CStatistic::GetCivilian(CStatistic *this, int a2)
int  CStatistic::GetCivilian(int a2)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 467, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[a2].m_iNrOfCivilian;
}


// address=[0x1476540]
// Decompiled from int __thiscall CStatistic::GetSoldiers(CStatistic *this, int _iPlayerId)
int  CStatistic::GetSoldiers(int _iPlayerId)const {
  
  int v4; // [esp+8h] [ebp-Ch]
  int v5; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 480, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  v5 = 0;
  for ( i = 0; i < 67; ++i )
  {
    v4 = CSettlerMgr::SettlerWarriorType(i);
    if ( v4 > 0 && v4 <= 6 )
      v5 += this->m_sPlayerStats[_iPlayerId].m_iTotalOfSettler[i];
  }
  return v5;
}


// address=[0x14765e0]
// Decompiled from int __thiscall CStatistic::GetNrOfSoldiers(CStatistic *this, int a2)
int  CStatistic::GetNrOfSoldiers(int a2)const {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 512, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[a2].m_iNrOfSoldier;
}


// address=[0x1476630]
// Decompiled from void __thiscall CStatistic::AddProducedSettler(CStatistic *this, int a2, int _iSettlerType)
void  CStatistic::AddProducedSettler(int a2, int _iSettlerType) {
  
  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 426, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerType <= 0 || _iSettlerType >= 67)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 427, "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  ++this->m_sPlayerStats[a2].m_iTotalOfSettler[_iSettlerType];
  ++this->m_sPlayerStats[a2].m_iProducedSettlers;
}


// address=[0x14766f0]
// Decompiled from int __thiscall CStatistic::GetProducedSettler(CStatistic *this, int _iPlayerId, int _iSettlerType)
int  CStatistic::GetProducedSettler(int _iPlayerId, int _iSettlerType)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 441, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iSettlerType <= 0 || _iSettlerType >= 67)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 442, "(_iSettlerType > 0) && (_iSettlerType < SETTLER_MAX)") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iTotalOfSettler[_iSettlerType];
}


// address=[0x1476770]
// Decompiled from int __thiscall CStatistic::GetTotalProducedSettler(CStatistic *this, int _iPlayerId)
int  CStatistic::GetTotalProducedSettler(int _iPlayerId)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 454, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iProducedSettlers;
}


// address=[0x14767c0]
// Decompiled from int __thiscall CStatistic::GetBuildingProductivity(CStatistic *this, int _iPlayerId, int _iBuildingType)
int  CStatistic::GetBuildingProductivity(int _iPlayerId, int _iBuildingType)const {
  
  return this->m_sPlayerStats[_iPlayerId].m_iBuildingProductivity[_iBuildingType];
}


// address=[0x14767f0]
// Decompiled from void __thiscall CStatistic::AddBuilding(CStatistic *this, int a2, int a3, int a4)
void  CStatistic::AddBuilding(int a2, int a3, int a4) {
  
  DWORD v4; // eax

  this->m_sPlayerStats[a2].m_iNrOfBuilding[a3] += a4;
  this->m_sPlayerStats[a2].m_iTotalOfBuilding += a4;
  v4 = CPlayerManager::Race(a2);
  CStatistic::UpdateFightingStrength(this, a2, v4, a3, a4);
}


// address=[0x1476880]
// Decompiled from void __thiscall CStatistic::DecBuilding(CStatistic *this, int _iPlayerId, S4_BUILDING_ENUM _iBuildingType, int a4)
void  CStatistic::DecBuilding(int _iPlayerId, int _iBuildingType, int a4) {
  
  DWORD v4; // eax

  BBSupportTracePrintF(0, "CStatistic::DecBuilding(%i, %i, %i) called.", _iPlayerId, _iBuildingType, a4);
  if ( this->m_sPlayerStats[_iPlayerId].m_iNrOfBuilding[_iBuildingType] < a4
    && BBSupportDbgReport(
         2,
         "Logic\\Statistic.cpp",
         555,
         "m_sPlayerStats[ _iPlayerId ].m_iNrOfBuildings[ _iBuildingType ] >= _iAmount") == 1 )
  {
    __debugbreak();
  }
  this->m_sPlayerStats[_iPlayerId].m_iTotalOfBuilding -= a4;
  this->m_sPlayerStats[_iPlayerId].m_iNrOfBuilding[_iBuildingType] -= a4;
  v4 = CPlayerManager::Race(_iPlayerId);
  CStatistic::UpdateFightingStrength(this, _iPlayerId, v4, _iBuildingType, -a4);
}


// address=[0x1476960]
// Decompiled from int __thiscall CStatistic::GetBuildings(CStatistic *this, int _iPlayerId, int _iBuildingType)
int  CStatistic::GetBuildings(int _iPlayerId, int _iBuildingType)const {
  
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfBuilding[_iBuildingType];
}


// address=[0x1476990]
// Decompiled from void __thiscall CStatistic::AddProducedBuilding(CStatistic *this, int a2, int a3, int a4)
void  CStatistic::AddProducedBuilding(int a2, int a3, int a4) {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 610, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 >= 83 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 611, "_iBuilding < BUILDING_MAX") == 1 )
    __debugbreak();
  this->m_sPlayerStats[a2].m_iNrOfProducedBuilding[a3] += a4;
  this->m_sPlayerStats[a2].m_iProducedBuildings += a4;
}


// address=[0x1476a50]
// Decompiled from int __thiscall CStatistic::GetProducedBuildings(CStatistic *this, int _iPlayerId, int _iBuilding)
int  CStatistic::GetProducedBuildings(int _iPlayerId, int _iBuilding)const {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 624, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iBuilding >= 83 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 625, "_iBuilding < BUILDING_MAX") == 1 )
    __debugbreak();
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedBuilding[_iBuilding];
}


// address=[0x1476ad0]
// Decompiled from int __thiscall CStatistic::GetTotalBuildings(CStatistic *this, int a2)
int  CStatistic::GetTotalBuildings(int a2)const {
  
  return this->m_sPlayerStats[a2].m_iTotalOfBuilding;
}


// address=[0x1476af0]
// Decompiled from int __thiscall CStatistic::GetTotalProducedBuildings(CStatistic *this, int a2)
int  CStatistic::GetTotalProducedBuildings(int a2)const {
  
  return this->m_sPlayerStats[a2].m_iProducedBuildings;
}


// address=[0x1476b10]
// Decompiled from int __thiscall CStatistic::GetTotalBuildingsOfType(CStatistic *this, int _iPlayerId, int _iBuilding)
int  CStatistic::GetTotalBuildingsOfType(int _iPlayerId, int _iBuilding)const {
  
  int Buildings; // esi

  Buildings = CStatistic::GetBuildings(this, _iPlayerId, _iBuilding);
  return Buildings + CStatistic::GetConstructions(this, _iPlayerId, _iBuilding);
}


// address=[0x1476b50]
// Decompiled from void __thiscall CStatistic::AddCaptureBuilding(CStatistic *this, int _iPlayer, int _iTarget, int _iBuilding)
void  CStatistic::AddCaptureBuilding(int _iPlayer, int _iTarget, int _iBuilding) {
  
  ++this->m_sPlayerStats[_iPlayer].m_iNrOfCapturedBuilding[_iBuilding];
  ++this->m_sPlayerStats[_iTarget].m_iNrOfLostBuilding[_iBuilding];
}


// address=[0x1476bd0]
// Decompiled from int __thiscall CStatistic::GetCapturedTowers(CStatistic *this, int _iPlayer)
int  CStatistic::GetCapturedTowers(int _iPlayer) {
  
  if ( (_iPlayer <= 0 || _iPlayer >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1584, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayer].m_iNrOfCapturedBuilding[48]
       + this->m_sPlayerStats[_iPlayer].m_iNrOfCapturedBuilding[47]
       + this->m_sPlayerStats[_iPlayer].m_iNrOfCapturedBuilding[46];
}


// address=[0x1476c70]
// Decompiled from int __thiscall CStatistic::GetLossesTowers(CStatistic *this, int a2)
int  CStatistic::GetLossesTowers(int a2) {
  
  return this->m_sPlayerStats[a2].m_iNrOfLostBuilding[BUILDING_CASTLE]
       + this->m_sPlayerStats[a2].m_iNrOfLostBuilding[BUILDING_GUARDTOWERBIG]
       + this->m_sPlayerStats[a2].m_iNrOfLostBuilding[BUILDING_GUARDTOWERSMALL];
}


// address=[0x1476ce0]
// Decompiled from void __thiscall CStatistic::AddConstruction(CStatistic *this, int _iPlayerId, int _iBuildingType, int _iCount)
void  CStatistic::AddConstruction(int _iPlayerId, int _iBuildingType, int _iCount) {
  
  this->m_sPlayerStats[_iPlayerId].m_iNrOfBuildingSites[_iBuildingType] += _iCount;
  this->m_sPlayerStats[_iPlayerId].m_iTotalBuildingSites += _iCount;
}


// address=[0x1476d50]
// Decompiled from void __thiscall CStatistic::DecConstruction(CStatistic *this, int _iPlayerId, int _iBuildingType, int a4)
void  CStatistic::DecConstruction(int _iPlayerId, int _iBuildingType, int a4) {
  
  if ( this->m_sPlayerStats[_iPlayerId].m_iNrOfBuildingSites[_iBuildingType] < a4
    && BBSupportDbgReport(
         2,
         "Logic\\Statistic.cpp",
         661,
         "m_sPlayerStats[ _iPlayerId ].m_iNrOfBuildingSites[ _iBuildingType ] >= _iAmount") == 1 )
  {
    __debugbreak();
  }
  this->m_sPlayerStats[_iPlayerId].m_iNrOfBuildingSites[_iBuildingType] -= a4;
  this->m_sPlayerStats[_iPlayerId].m_iTotalBuildingSites -= a4;
}


// address=[0x1476e00]
// Decompiled from int __thiscall CStatistic::GetTotalBuildingsUnderConstruction(CStatistic *this, int a2)
int  CStatistic::GetTotalBuildingsUnderConstruction(int a2)const {
  
  return this->m_sPlayerStats[a2].m_iTotalBuildingSites;
}


// address=[0x1476e20]
// Decompiled from int __thiscall CStatistic::GetConstructions(CStatistic *this, int _iPlayerId, int _iBuildingType)
int  CStatistic::GetConstructions(int _iPlayerId, int _iBuildingType)const {
  
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfBuildingSites[_iBuildingType];
}


// address=[0x1476e50]
// Decompiled from void __thiscall CStatistic::ChangeResidenceNeed(CStatistic *this, int _iPlayerId, int _iCount)
void  CStatistic::ChangeResidenceNeed(int _iPlayerId, int _iCount) {
  
  this->m_sPlayerStats[_iPlayerId].m_iResidenceNeed += _iCount;
}


// address=[0x1476e90]
// Decompiled from int __thiscall CStatistic::GetResidenceNeed(CStatistic *this, int a2)
int  CStatistic::GetResidenceNeed(int a2)const {
  
  return this->m_sPlayerStats[a2].m_iNrOfSettler[1];
}


// address=[0x1476ec0]
// Decompiled from void __thiscall CStatistic::ChangeResidenceSpace(CStatistic *this, int a2, int a3)
void  CStatistic::ChangeResidenceSpace(int a2, int a3) {
  
  this->m_sPlayerStats[a2].m_iResidenceSpace += a3;
}


// address=[0x1476f00]
// Decompiled from int __thiscall CStatistic::GetResidenceSpace(CStatistic *this, int _iPlayerId)
int  CStatistic::GetResidenceSpace(int _iPlayerId)const {
  
  return CEcoSectorMgr::GetNrOfCurrentTotalBeds((CEcoSectorMgr *)g_cESMgr, _iPlayerId);
}


// address=[0x1476f20]
// Decompiled from void __thiscall CStatistic::AddGood(CStatistic *this, int _iPlayerId, S4_GOOD_ENUM _iGood, int a4)
void  CStatistic::AddGood(int _iPlayerId, int _iGood, int a4) {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 162, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iGood >= GOOD_MAX && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 163, "_iGood < GOOD_MAX") == 1 )
    __debugbreak();
  this->m_sPlayerStats[_iPlayerId].m_iNrOfGood[_iGood] += a4;
  this->m_sPlayerStats[_iPlayerId].m_iTotalGoods += a4;
  if ( !CStatistic::m_bWonStateSaved )
    this->m_sPlayerStats[_iPlayerId].m_iWinGoods[_iGood] = this->m_sPlayerStats[_iPlayerId].m_iNrOfGood[_iGood];
}


// address=[0x1477020]
// Decompiled from void __thiscall CStatistic::DecGood(CStatistic *this, int _iPlayerId, int _iGood, int _iCount)
void  CStatistic::DecGood(int _iPlayerId, int _iGood, int _iCount) {
  
  int v4; // [esp+0h] [ebp-8h]

  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 183, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iGood >= 43 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 184, "_iGood < GOOD_MAX") == 1 )
    __debugbreak();
  v4 = _iCount;
  if ( this->m_sPlayerStats[_iPlayerId].m_iNrOfGood[_iGood] < _iCount )
    v4 = this->m_sPlayerStats[_iPlayerId].m_iNrOfGood[_iGood];
  this->m_sPlayerStats[_iPlayerId].m_iNrOfGood[_iGood] -= v4;
  this->m_sPlayerStats[_iPlayerId].m_iTotalGoods -= v4;
}


// address=[0x1477120]
// Decompiled from int __thiscall CStatistic::GetGood(CStatistic *this, int _iPlayerId, int _iGood)
int  CStatistic::GetGood(int _iPlayerId, int _iGood)const {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 202, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iGood >= 43 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 203, "_iGood < GOOD_MAX") == 1 )
    __debugbreak();
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfGood[_iGood];
}


// address=[0x14771a0]
// Decompiled from int __thiscall CStatistic::GetWinGood(CStatistic *this, int _iPlayerId, int _iGood)
int  CStatistic::GetWinGood(int _iPlayerId, int _iGood)const {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 210, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iGood >= 43 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 211, "_iGood < GOOD_MAX") == 1 )
    __debugbreak();
  return this->m_sPlayerStats[_iPlayerId].m_iWinGoods[_iGood];
}


// address=[0x1477220]
// Decompiled from int __thiscall CStatistic::GetTotalGood(CStatistic *this, int _iPlayerId)
int  CStatistic::GetTotalGood(int _iPlayerId)const {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 223, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iTotalGoods;
}


// address=[0x1477270]
// Decompiled from void __thiscall CStatistic::AddProducedGoods(CStatistic *this, int _iPlayerId, int _iGood, int _iCount)
void  CStatistic::AddProducedGoods(int _iPlayerId, int _iGood, int _iCount) {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 235, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iGood >= 43 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 236, "_iGood < GOOD_MAX") == 1 )
    __debugbreak();
  this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[_iGood] += _iCount;
  this->m_sPlayerStats[_iPlayerId].m_iTotalProducedGoods += _iCount;
}


// address=[0x1477330]
// Decompiled from int __thiscall CStatistic::GetProducedGoods(CStatistic *this, int _iPlayerId, int _iGood)
int  CStatistic::GetProducedGoods(int _iPlayerId, int _iGood)const {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 249, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iGood >= 43 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 250, "_iGood < GOOD_MAX") == 1 )
    __debugbreak();
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[_iGood];
}


// address=[0x14773b0]
// Decompiled from int __thiscall CStatistic::GetTotalProducedGood(CStatistic *this, int _iPlayerId)
int  CStatistic::GetTotalProducedGood(int _iPlayerId)const {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 263, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iTotalProducedGoods;
}


// address=[0x1477400]
// Decompiled from void __thiscall CStatistic::AddVehicle(CStatistic *this, int _iPlayerId, int _iVehicleType, int _iCount)
void  CStatistic::AddVehicle(int _iPlayerId, int _iVehicleType, int _iCount) {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 759, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iVehicleType >= 6 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 760, "_iVehicleType < VEHICLE_MAX") == 1 )
    __debugbreak();
  this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicle[_iVehicleType] += _iCount;
  this->m_sPlayerStats[_iPlayerId].m_iTotalVehicles += _iCount;
}


// address=[0x14774c0]
// Decompiled from void __thiscall CStatistic::DecVehicle(CStatistic *this, int _iPlayerId, int _iVehicleType, int _iCount)
void  CStatistic::DecVehicle(int _iPlayerId, int _iVehicleType, int _iCount) {
  
  int v4; // [esp+0h] [ebp-8h]

  v4 = _iCount;
  if ( this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicle[_iVehicleType] < _iCount )
    v4 = this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicle[_iVehicleType];
  this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicle[_iVehicleType] -= v4;
  this->m_sPlayerStats[_iPlayerId].m_iTotalVehicles -= v4;
}


// address=[0x1477570]
// Decompiled from int __thiscall CStatistic::GetVehicle(CStatistic *this, int a2, int a3)
int  CStatistic::GetVehicle(int a2, int a3)const {
  
  return this->m_sPlayerStats[a2].m_iNrOfVehicle[a3];
}


// address=[0x14775a0]
// Decompiled from int __thiscall CStatistic::GetTotalVehicle(CStatistic *this, int _iPlayerId)
int  CStatistic::GetTotalVehicle(int _iPlayerId)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 803, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iTotalVehicles;
}


// address=[0x14775f0]
// Decompiled from void __thiscall CStatistic::AddProducedVehicle(CStatistic *this, int _iPlayerId, int _iVehicleType, int _iCount)
void  CStatistic::AddProducedVehicle(int _iPlayerId, int _iVehicleType, int _iCount) {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 817, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iVehicleType <= 0 || _iVehicleType >= 6)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 818, "(_iVehicleType > 0) && (_iVehicleType < VEHICLE_MAX)") == 1 )
  {
    __debugbreak();
  }
  this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedVehicle[_iVehicleType] += _iCount;
  this->m_sPlayerStats[_iPlayerId].m_iTotalProducedVehicles += _iCount;
}


// address=[0x14776b0]
// Decompiled from int __thiscall CStatistic::GetProducedVehicle(CStatistic *this, int _iPlayerId, int _iVehicleType)
int  CStatistic::GetProducedVehicle(int _iPlayerId, int _iVehicleType)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 831, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iVehicleType <= 0 || _iVehicleType >= 6)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 832, "(_iVehicleType > 0) && (_iVehicleType < VEHICLE_MAX)") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedVehicle[_iVehicleType];
}


// address=[0x1477730]
// Decompiled from int __thiscall CStatistic::GetTotalProducedVehicled(CStatistic *this, int _iPlayerId)
int  CStatistic::GetTotalProducedVehicled(int _iPlayerId)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 845, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iTotalProducedVehicles;
}


// address=[0x1477780]
// Decompiled from int __thiscall CStatistic::GetMana(CStatistic *this, int _iPlayerId)
int  CStatistic::GetMana(int _iPlayerId)const {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1104, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iMana;
}


// address=[0x14777d0]
// Decompiled from int __thiscall CStatistic::GetProducedMana(CStatistic *this, int a2)
int  CStatistic::GetProducedMana(int a2)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1116, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[a2].m_iProducedMana;
}


// address=[0x1477820]
// Decompiled from void __thiscall CStatistic::IncKillsOfType(CStatistic *this, int _iPlayerId, int _iSettlerType)
void  CStatistic::IncKillsOfType(int _iPlayerId, int _iSettlerType) {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 863, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( _iSettlerType <= 0 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 864, "_iSettlerType > 0") == 1 )
    __debugbreak();
  if ( _iSettlerType < 67 )
  {
    ++this->m_sPlayerStats[_iPlayerId].m_iNrOfKill[_iSettlerType];
    ++this->m_sPlayerStats[_iPlayerId].m_iTotalKills;
  }
}


// address=[0x14778e0]
// Decompiled from int __thiscall CStatistic::GetKillsOfType(CStatistic *this, int _iPlayerId, int _iSettlerType)
int  CStatistic::GetKillsOfType(int _iPlayerId, int _iSettlerType)const {
  
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfKill[_iSettlerType];
}


// address=[0x1477910]
// Decompiled from int __thiscall CStatistic::GetKills(CStatistic *this, int _iPlayerId)
int  CStatistic::GetKills(int _iPlayerId)const {
  
  return this->m_sPlayerStats[_iPlayerId].m_iTotalKills;
}


// address=[0x1477930]
// Decompiled from void __thiscall CStatistic::IncLossesOfType(CStatistic *this, int _iPlayerId, int _iSettlerType)
void  CStatistic::IncLossesOfType(int _iPlayerId, int _iSettlerType) {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 899, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( _iSettlerType <= 0 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 900, "_iSettlerType > 0") == 1 )
    __debugbreak();
  if ( _iSettlerType < 67 )
  {
    ++this->m_sPlayerStats[_iPlayerId].m_iNrOfLoss[_iSettlerType];
    ++this->m_sPlayerStats[_iPlayerId].m_iTotalLosses;
  }
}


// address=[0x14779f0]
// Decompiled from int __thiscall CStatistic::GetLossesOfType(CStatistic *this, int _iPlayerId, int _iSettlerType)
int  CStatistic::GetLossesOfType(int _iPlayerId, int _iSettlerType)const {
  
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfLoss[_iSettlerType];
}


// address=[0x1477a20]
// Decompiled from int __thiscall CStatistic::GetLosses(CStatistic *this, int _iPlayerId)
int  CStatistic::GetLosses(int _iPlayerId)const {
  
  return this->m_sPlayerStats[_iPlayerId].m_iTotalLosses;
}


// address=[0x1477a40]
// Decompiled from void __thiscall CStatistic::IncKillsVehicleOfType(CStatistic *this, int _iPlayerId, int _iVehicleType)
void  CStatistic::IncKillsVehicleOfType(int _iPlayerId, int _iVehicleType) {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 962, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iVehicleType <= 0 || _iVehicleType >= 6)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 963, "(_iVehicleType > 0) && (_iVehicleType < VEHICLE_MAX)") == 1 )
  {
    __debugbreak();
  }
  ++this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicleKill[_iVehicleType];
  ++this->m_sPlayerStats[_iPlayerId].m_iTotalVehicleKills;
}


// address=[0x1477b00]
// Decompiled from int __thiscall CStatistic::GetKillsVehicleOfType(CStatistic *this, int _iPlayerId, int _iVehicleType)
int  CStatistic::GetKillsVehicleOfType(int _iPlayerId, int _iVehicleType)const {
  
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicleKill[_iVehicleType];
}


// address=[0x1477b30]
// Decompiled from int __thiscall CStatistic::GetKillsVehicle(CStatistic *this, int _iPlayerId)
int  CStatistic::GetKillsVehicle(int _iPlayerId)const {
  
  return this->m_sPlayerStats[_iPlayerId].m_iTotalVehicleKills;
}


// address=[0x1477b50]
// Decompiled from void __thiscall CStatistic::IncLossesVehicleOfType(CStatistic *this, int _iPlayerId, int _iVehicleType)
void  CStatistic::IncLossesVehicleOfType(int _iPlayerId, int _iVehicleType) {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 996, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( (_iVehicleType <= 0 || _iVehicleType >= 6)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 997, "(_iVehicleType > 0) && (_iVehicleType < VEHICLE_MAX)") == 1 )
  {
    __debugbreak();
  }
  ++this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicleLoss[_iVehicleType];
  ++this->m_sPlayerStats[_iPlayerId].m_iTotalVehicleLosses;
}


// address=[0x1477c10]
// Decompiled from int __thiscall CStatistic::GetLossesVehicleOfType(CStatistic *this, int _iPlayerId, int _iVehicleType)
int  CStatistic::GetLossesVehicleOfType(int _iPlayerId, int _iVehicleType)const {
  
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfVehicleLoss[_iVehicleType];
}


// address=[0x1477c40]
// Decompiled from int __thiscall CStatistic::GetLossesVehicle(CStatistic *this, int _iPlayerId)
int  CStatistic::GetLossesVehicle(int _iPlayerId)const {
  
  return this->m_sPlayerStats[_iPlayerId].m_iTotalVehicleLosses;
}


// address=[0x1477c60]
// Decompiled from void __thiscall CStatistic::IncBuildingLosses(CStatistic *this, int _iPlayerId)
void  CStatistic::IncBuildingLosses(int _iPlayerId) {
  
  ++this->m_sPlayerStats[_iPlayerId].m_iTotalBuildingLosses;
}


// address=[0x1477ca0]
// Decompiled from int __thiscall CStatistic::GetBuildingLosses(CStatistic *this, int _iPlayerId)
int  CStatistic::GetBuildingLosses(int _iPlayerId) {
  
  return this->m_sPlayerStats[_iPlayerId].m_iTotalBuildingLosses;
}


// address=[0x1477cc0]
// Decompiled from void __thiscall CStatistic::DecLandSize(CStatistic *this, int a2, int a3)
void  CStatistic::DecLandSize(int a2, int a3) {
  
  ;
}


// address=[0x1477cd0]
// Decompiled from void __thiscall CStatistic::IncLandSize(CStatistic *this, int a2, int a3)
void  CStatistic::IncLandSize(int a2, int a3) {
  
  ;
}


// address=[0x1477ce0]
// Decompiled from int __thiscall CStatistic::GetLandSize(CStatistic *this, int a2)
int  CStatistic::GetLandSize(int a2)const {
  
  return this->m_sPlayerStats[a2].m_iLandSize;
}


// address=[0x1477d00]
// Decompiled from int __thiscall CStatistic::GetMaxLandSize(CStatistic *this, int a2)
int  CStatistic::GetMaxLandSize(int a2)const {
  
  return this->m_sPlayerStats[a2].m_iMaxLandSize;
}


// address=[0x1477d20]
// Decompiled from int __thiscall CStatistic::GetLandSizePercent(CStatistic *this, int a2)
int  CStatistic::GetLandSizePercent(int a2) {
  
  CStatistic::CalculateLandSize(this);
  return this->m_sPlayerStats[a2].m_iLandSize;
}


// address=[0x1477d50]
// Decompiled from void __thiscall CStatistic::SetOffenceStrength100(CStatistic *this, int a2, int a3)
void  CStatistic::SetOffenceStrength100(int a2, int a3) {
  
  int iOffenceStrengthBase256; // [esp+8h] [ebp-4h]

  if ( (a2 < 1 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1150, "_iPlayerId >= 1 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a2 >= 1 && a2 < 9 )
  {
    iOffenceStrengthBase256 = 0;
    if ( a3 > 0 )
    {
      iOffenceStrengthBase256 = (a3 << 8) / 100;
      if ( iOffenceStrengthBase256 >= this->m_sPlayerStats[a2].m_iOffenceStrengthBase256 )
      {
        if ( iOffenceStrengthBase256 > 384 )
          iOffenceStrengthBase256 = 384;
      }
      else
      {
        iOffenceStrengthBase256 = this->m_sPlayerStats[a2].m_iOffenceStrengthBase256;
      }
    }
    this->m_sPlayerStats[a2].m_iOffenceStrength100_2 = iOffenceStrengthBase256;
    CStatistic::SPlayerStatistic::CalculateFightingStrength(&this->m_sPlayerStats[a2], a2);
  }
}


// address=[0x1477e10]
// Decompiled from int __thiscall CStatistic::UsedBuildingMaterial(CStatistic *this, int _iPlayerId)
int  CStatistic::UsedBuildingMaterial(int _iPlayerId)const {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1129, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iTotalUsedBuildingMaterial;
}


// address=[0x1477e60]
// Decompiled from int __thiscall CStatistic::GetTotalTowers(CStatistic *this, int _iPlayerId)
int  CStatistic::GetTotalTowers(int _iPlayerId) {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1523, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedBuilding[BUILDING_CASTLE]
       + this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedBuilding[BUILDING_GUARDTOWERBIG]
       + this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedBuilding[BUILDING_GUARDTOWERSMALL];
}


// address=[0x1477f00]
// Decompiled from int __thiscall CStatistic::GetTotalMineProduction(CStatistic *this, int a2)
int  CStatistic::GetTotalMineProduction(int a2) {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1535, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[a2].m_iNrOfProducedGoods[GOOD_IRONORE]
       + this->m_sPlayerStats[a2].m_iNrOfProducedGoods[GOOD_SULFUR]
       + this->m_sPlayerStats[a2].m_iNrOfProducedGoods[GOOD_GOLDORE]
       + this->m_sPlayerStats[a2].m_iNrOfProducedGoods[GOOD_COAL];
}


// address=[0x1477fb0]
// Decompiled from int __thiscall CStatistic::GetTotalFood(CStatistic *this, int _iPlayerId)
int  CStatistic::GetTotalFood(int _iPlayerId) {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1548, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[GOOD_MEAT]
       + this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[GOOD_FISH]
       + this->m_sPlayerStats[_iPlayerId].m_iNrOfProducedGoods[GOOD_BREAD];
}


// address=[0x1478050]
// Decompiled from void __thiscall CStatistic::SetPlayerExitTime(CStatistic *this, int _iPlayerId, int _iExitTime)
void  CStatistic::SetPlayerExitTime(int _iPlayerId, unsigned int _iExitTime) {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1560, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  this->m_sPlayerStats[_iPlayerId].m_iExitTime = _iExitTime;
}


// address=[0x14780a0]
// Decompiled from int __thiscall CStatistic::GetPlayerExitTime(CStatistic *this, int _iPlayerId)
unsigned int  CStatistic::GetPlayerExitTime(int _iPlayerId) {
  
  if ( (_iPlayerId <= 0 || _iPlayerId >= 9)
    && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1570, "_iPlayerId > 0 && _iPlayerId < PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iExitTime;
}


// address=[0x14780f0]
// Decompiled from void __thiscall CStatistic::UpdateStartStatistic(CStatistic *this)
void  CStatistic::UpdateStartStatistic(void) {
  
  int n; // [esp+4h] [ebp-18h]
  int m; // [esp+8h] [ebp-14h]
  int k; // [esp+Ch] [ebp-10h]
  int j; // [esp+10h] [ebp-Ch]
  int i; // [esp+18h] [ebp-4h]

  for ( i = 1; i <= 8; ++i )
  {
    for ( j = 0; j < SETTLER_MAX; ++j )
    {
      this->m_sPlayerStats[i].m_iTotalOfSettler[j] = this->m_sPlayerStats[i].m_iNrOfSettler[j];
      this->m_sPlayerStats[i].m_iProducedSettlers += this->m_sPlayerStats[i].m_iNrOfSettler[j];
    }
    for ( k = 0; k < BUILDING_MAX; ++k )
    {
      this->m_sPlayerStats[i].m_iNrOfProducedBuilding[k] = this->m_sPlayerStats[i].m_iNrOfBuilding[k];
      this->m_sPlayerStats[i].m_iProducedBuildings += this->m_sPlayerStats[i].m_iNrOfBuilding[k];
    }
    for ( m = 0; m < 6; ++m )
    {
      this->m_sPlayerStats[i].m_iNrOfProducedVehicle[m] = this->m_sPlayerStats[i].m_iNrOfVehicle[m];
      this->m_sPlayerStats[i].m_iTotalProducedVehicles += this->m_sPlayerStats[i].m_iNrOfVehicle[m];
    }
    for ( n = 0; n < GOOD_MAX; ++n )
    {
      this->m_sPlayerStats[i].m_iNrOfProducedGoods[n] = this->m_sPlayerStats[i].m_iNrOfGood[n];
      this->m_sPlayerStats[i].m_iTotalProducedGoods += this->m_sPlayerStats[i].m_iNrOfGood[n];
    }
  }
}


// address=[0x1478330]
// Decompiled from _DWORD *__thiscall CStatistic::FillExtraInfo(CStatistic *this)
void  CStatistic::FillExtraInfo(void) {
  
  int v1; // esi
  int Good; // esi
  int v3; // esi
  int v4; // esi
  int v5; // esi
  int v6; // esi
  int v7; // esi
  int NumberOfSettlers; // esi
  int v9; // esi
  int v10; // esi
  int v11; // esi
  int v12; // esi
  int v13; // esi
  int v14; // esi
  int v15; // esi
  int v16; // esi
  int v17; // esi
  int v18; // esi
  int v19; // esi
  int v20; // esi
  int v21; // esi
  int v22; // esi
  int v23; // esi
  int v24; // esi
  int v25; // esi
  int v27; // [esp+Ch] [ebp-48h]
  DWORD v28; // [esp+10h] [ebp-44h]
  int i; // [esp+14h] [ebp-40h]
  CPlayerGameData *v30; // [esp+18h] [ebp-3Ch]
  CEcoSector *EcoSectorPtr; // [esp+1Ch] [ebp-38h]
  int a1; // [esp+28h] [ebp-2Ch]
  CEvn_Event v34; // [esp+2Ch] [ebp-28h] BYREF
  int v35; // [esp+50h] [ebp-4h]

  g_cExtendedMenuInfo.Clear(&g_cExtendedMenuInfo);
  a1 = CPlayerManager::GetLocalPlayerId();
  v28 = 0;
  v30 = CPlayerManager::PlayerGameData(a1);
  CPlayerGameData::ResetIterator(v30);
  for ( i = CPlayerGameData::GetNextEcoSectorId(v30); i; i = CPlayerGameData::GetNextEcoSectorId(v30) )
  {
    EcoSectorPtr = (CEcoSector *)CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, i);
    if ( EcoSectorPtr && CEcoSector::Owner(EcoSectorPtr) == a1 )
    {
      v1 = CEcoSector::NrOfSettler(EcoSectorPtr, SETTLER_CARRIER);
      v27 = v1 - CEcoSector::MinCarrier(EcoSectorPtr);
      if ( v27 > 0 )
        v28 += v27;
    }
  }
  g_cExtendedMenuInfo.m_uCarriers = v28;
  g_cExtendedMenuInfo.m_uNrTotalBeds = CEcoSectorMgr::GetNrOfCurrentTotalBeds((CEcoSectorMgr *)g_cESMgr, a1);
  g_cExtendedMenuInfo.m_uGoodsBoards = CStatistic::GetGood(this, a1, GOOD_BOARD);
  g_cExtendedMenuInfo.m_uGoodsStone = CStatistic::GetGood(this, a1, GOOD_STONE);
  g_cExtendedMenuInfo.m_uGoodsGoldbars = CStatistic::GetGood(this, a1, GOOD_GOLDBAR);
  Good = CStatistic::GetGood(this, a1, GOOD_BOW);
  v3 = CStatistic::GetGood(this, a1, GOOD_SWORD) + Good;
  v4 = CStatistic::GetGood(this, a1, GOOD_BATTLEAXE) + v3;
  v5 = CStatistic::GetGood(this, a1, GOOD_BLOWGUN) + v4;
  g_cExtendedMenuInfo.m_uGoodsWeapons = CStatistic::GetGood(this, a1, GOOD_BACKPACKCATAPULT) + v5;
  v6 = CStatistic::GetGood(this, a1, GOOD_BREAD);
  v7 = CStatistic::GetGood(this, a1, GOOD_MEAT) + v6;
  g_cExtendedMenuInfo.m_uGoodsFood = CStatistic::GetGood(this, a1, GOOD_FISH) + v7;
  NumberOfSettlers = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_SWORDSMAN_01);
  v9 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_SWORDSMAN_02) + NumberOfSettlers;
  v10 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_SWORDSMAN_03) + v9;
  v11 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_BOWMAN_01) + v10;
  v12 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_BOWMAN_02) + v11;
  v13 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_BOWMAN_03) + v12;
  v14 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_AXEWARRIOR_01) + v13;
  v15 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_AXEWARRIOR_02) + v14;
  v16 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_AXEWARRIOR_03) + v15;
  v17 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_BLOWGUNWARRIOR_01) + v16;
  v18 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_BLOWGUNWARRIOR_02) + v17;
  v19 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_BLOWGUNWARRIOR_03) + v18;
  v20 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_MEDIC_01) + v19;
  v21 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_MEDIC_02) + v20;
  v22 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_MEDIC_03) + v21;
  v23 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_BACKPACKCATAPULTIST_01) + v22;
  v24 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_BACKPACKCATAPULTIST_02) + v23;
  v25 = CSettlerMgr::GetNumberOfSettlers((CSettlerMgr *)g_cSettlerMgr, a1, SETTLER_BACKPACKCATAPULTIST_03) + v24;
  g_cExtendedMenuInfo.m_uSoldierCount = CSettlerMgr::GetNumberOfSettlers(
                                          (CSettlerMgr *)g_cSettlerMgr,
                                          a1,
                                          SETTLER_SQUADLEADER)
                                      + v25;
  g_cExtendedMenuInfo.m_uOffenseStrength = CStatistic::OffenceStrength100(this, a1);
  g_cExtendedMenuInfo.m_uDefenceStrength = CStatistic::DefenceStrength100(this, a1);
  g_cExtendedMenuInfo.m_uMana = CStatistic::GetMana(this, a1);
  g_cExtendedMenuInfo.m_iUnknown = 0x25;
  CEvn_Event::CEvn_Event(&v34, 0x25Cu, 0, (unsigned int)&g_cExtendedMenuInfo, 0);
  v35 = 0;
  if ( !g_pEvnEngine && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1701, "g_pEvnEngine != NULL") == 1 )
    __debugbreak();
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v34);
  v35 = -1;
  return CEvn_Event::~CEvn_Event(&v34);
}


// address=[0x1478720]
// Decompiled from void CStatistic::FillEconomyGameMenu(struct CInfoExchange *a1, bool a2, bool a3)
void __cdecl CStatistic::FillEconomyGameMenu(class CInfoExchange * a1, bool a2, bool a3) {
  
  struct CEvn_Event *v3; // [esp+8h] [ebp-40h]
  DWORD v4; // [esp+14h] [ebp-34h]
  int j; // [esp+18h] [ebp-30h]
  int i; // [esp+1Ch] [ebp-2Ch]
  CEvn_Event v7; // [esp+20h] [ebp-28h] BYREF
  int v8; // [esp+44h] [ebp-4h]

  CInfoExchange::Clear(&g_cEconomyGameInfo);
  g_cEconomyGameInfo.m_iUnknown = 36;
  for ( i = 0; i < 7; ++i )
  {
    v4 = (unsigned __int8)CGameData::GetEconomyGoodsArray(g_pGameData)[i];
    g_cEconomyGameInfo.m_sStats[i].m_uEconomyGood = v4;
    for ( j = 1; j <= CPlayerManager::LastPlayerId(); ++j )
    {
      if ( CAlliances::AllianceId(j) == 1 )
        g_cEconomyGameInfo.m_sStats[i].m_uWinGoodsAllies += CStatistic::GetWinGood(&g_cStatistic, j, v4);
      else
        g_cEconomyGameInfo.m_sStats[i].m_uWinGoodsOther += CStatistic::GetWinGood(&g_cStatistic, j, v4);
    }
  }
  v3 = CEvn_Event::CEvn_Event(&v7, 0x25Au, 0, (unsigned int)&g_cEconomyGameInfo, 0);
  v8 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, v3);
  v8 = -1;
  CEvn_Event::~CEvn_Event(&v7);
}


// address=[0x1478890]
// Decompiled from void __thiscall CStatistic::FreezeEcoStatistic(CStatistic *this)
void  CStatistic::FreezeEcoStatistic(void) {
  
  int i; // [esp+4h] [ebp-4h]

  if ( !CStatistic::m_bWonStateSaved )
  {
    CStatistic::m_bWonStateSaved = 1;
    for ( i = 0; i < 9; ++i )
      memcpy(
        this->m_sPlayerStats[i].m_iWinGoods,
        this->m_sPlayerStats[i].m_iNrOfGood,
        sizeof(this->m_sPlayerStats[i].m_iWinGoods));
  }
}


// address=[0x147a280]
// Decompiled from int __thiscall CStatistic::DefenceStrength100(CStatistic *this, int _iPlayerId)
int  CStatistic::DefenceStrength100(int _iPlayerId)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\Statistic.h",
         357,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return (100 * this->m_sPlayerStats[_iPlayerId].m_iEffectiveDefenceStrength256) >> 8;
}


// address=[0x147a3b0]
// Decompiled from int __thiscall CStatistic::OffenceStrength100(CStatistic *this, int _iPlayerId)
int  CStatistic::OffenceStrength100(int _iPlayerId)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\Statistic.h",
         371,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return (100 * this->m_sPlayerStats[_iPlayerId].m_iEffectiveOffenceStrength256) >> 8;
}


// address=[0x14aa6b0]
// Decompiled from CStatistic *__thiscall CStatistic::CStatistic(CStatistic *this, CStatistic *a2)
 CStatistic::CStatistic(class CStatistic const & a2) {
  
  IS4ChunkObject::IS4ChunkObject(this, a2);
  this->__vftable = (IS4ChunkObject_vtbl *)CStatistic::_vftable_;
  memcpy(this->m_sPlayerStats, a2->m_sPlayerStats, 0x9A6Cu);
  return this;
}


// address=[0x1592160]
// Decompiled from int __thiscall CStatistic::DefenceStrength256(CStatistic *this, int _iPlayerId)
int  CStatistic::DefenceStrength256(int _iPlayerId)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\Statistic.h",
         387,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iEffectiveDefenceStrength256;
}


// address=[0x1592220]
// Decompiled from int __thiscall CStatistic::OffenceStrength256(CStatistic *this, int _iPlayerId)
int  CStatistic::OffenceStrength256(int _iPlayerId)const {
  
  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Logic\\Statistic.h",
         395,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  return this->m_sPlayerStats[_iPlayerId].m_iEffectiveOffenceStrength256;
}


// address=[0x160db70]
// Decompiled from void __thiscall CStatistic::SetDontShowLastNPlayers(CStatistic *this, DWORD _iPlayers)
void  CStatistic::SetDontShowLastNPlayers(int _iPlayers) {
  
  this->m_iDontShowLastNPlayers = _iPlayers;
}


// address=[0x1478900]
// Decompiled from void __thiscall CStatistic::CalcPlayerOffenceStrengthBaseValues(CStatistic *this)
void  CStatistic::CalcPlayerOffenceStrengthBaseValues(void) {
  
  int iOffenceStrengthBase256; // [esp+4h] [ebp-10h]
  int iNumberOfPlayers; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  iNumberOfPlayers = CPlayerManager::NumberOfPlayers();
  if ( iNumberOfPlayers <= 0 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1373, "iNumberOfPlayers > 0") == 1 )
    __debugbreak();
  if ( iNumberOfPlayers > 0 )
  {
    iOffenceStrengthBase256 = 768 / (iNumberOfPlayers + 4);
    if ( iOffenceStrengthBase256 <= 0
      && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1383, "iOffenceStrengthBase256 > 0") == 1 )
    {
      __debugbreak();
    }
    for ( i = 1; i < iNumberOfPlayers + 1; ++i )
    {
      if ( CPlayerManager::Race(i) == 3 )
        this->m_sPlayerStats[i].m_iOffenceStrengthBase256 = 256;
      else
        this->m_sPlayerStats[i].m_iOffenceStrengthBase256 = iOffenceStrengthBase256;
      CStatistic::SPlayerStatistic::CalculateFightingStrength(&this->m_sPlayerStats[i], i);
    }
  }
}


// address=[0x1478a00]
// Decompiled from void __thiscall CStatistic::UpdateFightingStrength(  CStatistic *this,  int _iPlayerId,  unsigned int _iRace,  S4_BUILDING_ENUM _iBuildingType,  int a5)
void  CStatistic::UpdateFightingStrength(int _iPlayerId, int _iRace, int _iBuildingType, int a5) {
  
  CBuildingInfoMgr::SBuildingInfos *BuildingInfo; // [esp+10h] [ebp-8h]

  if ( (_iPlayerId < 1 || _iPlayerId > 8)
    && BBSupportDbgReport(
         2,
         "Logic\\Statistic.cpp",
         1411,
         "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  if ( _iRace > 4 && BBSupportDbgReport(2, "Logic\\Statistic.cpp", 1412, "(_iRace >= 0) && (_iRace < RACE_MAX)") == 1 )
    __debugbreak();
  if ( (_iBuildingType <= BUILDING_NO_BUILDING || _iBuildingType >= BUILDING_MAX)
    && BBSupportDbgReport(
         2,
         "Logic\\Statistic.cpp",
         1413,
         "(_iBuildingType > BUILDING_NO_BUILDING) && (_iBuildingType < BUILDING_MAX)") == 1 )
  {
    __debugbreak();
  }
  BuildingInfo = CBuildingInfoMgr::GetBuildingInfo(_iRace, _iBuildingType);
  if ( _iBuildingType < BUILDING_EYECATCHER01 || _iBuildingType > BUILDING_EYECATCHER12 )
    CStatistic::SPlayerStatistic::UpdateFightingStrength(
      &this->m_sPlayerStats[_iPlayerId],
      _iPlayerId,
      BuildingInfo->m_iBoards * a5,
      BuildingInfo->m_iStone * a5,
      BuildingInfo->m_iGold * a5,
      0);
  else
    CStatistic::SPlayerStatistic::UpdateFightingStrength(
      &this->m_sPlayerStats[_iPlayerId],
      _iPlayerId,
      BuildingInfo->m_iBoards * a5,
      BuildingInfo->m_iStone * a5,
      BuildingInfo->m_iGold * a5,
      1);
}


// address=[0x1478b20]
// Decompiled from void __thiscall CStatistic::CalculateFightingStrengths(CStatistic *this)
void  CStatistic::CalculateFightingStrengths(void) {
  
  int PlayerId; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  PlayerId = CPlayerManager::LastPlayerId();
  for ( i = 1; i <= PlayerId; ++i )
    CStatistic::SPlayerStatistic::CalculateFightingStrength(&this->m_sPlayerStats[i], i);
}


// address=[0x1478b70]
// Decompiled from void __thiscall CStatistic::CalculateLandSize(CStatistic *this)
void  CStatistic::CalculateLandSize(void) {
  
  int v1; // esi
  int PlayerId; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  PlayerId = CPlayerManager::LastPlayerId();
  for ( i = 1; i <= PlayerId; ++i )
  {
    this->m_sPlayerStats[i].m_iLandSize = g_pTiling->NumberOfOwnedLandElements(g_pTiling, i);
    v1 = 100 * this->m_sPlayerStats[i].m_iLandSize;
    this->m_sPlayerStats[i].m_iLandSize = v1 / g_pTiling->NumberOfLandElements(g_pTiling);
    this->m_sPlayerStats[i].m_iMaxLandSize = *(_DWORD *)std::max<long>(
                                                          &this->m_sPlayerStats[i].m_iMaxLandSize,
                                                          &this->m_sPlayerStats[i].m_iLandSize);
  }
}


// address=[0x1478c50]
// Decompiled from void __thiscall CStatistic::CalculateMana(CStatistic *this)
void  CStatistic::CalculateMana(void) {
  
  int PlayerId; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  PlayerId = CPlayerManager::LastPlayerId();
  for ( i = 1; i <= PlayerId; ++i )
  {
    this->m_sPlayerStats[i].m_iMana = CMagic::GetCurrentManaAmount(i);
    this->m_sPlayerStats[i].m_iProducedMana = CMagic::TotalAmountOfCollectedMana(i);
  }
}


// address=[0x3f20320]
// [Decompilation failed for static bool CStatistic::m_bWonStateSaved]

#endif // Already implemented
