#include "CScanner.h"

#include "CAlliances.h"
#include "CVWList.h"
#include "ITiling.h"
#include "CTile.h"
#include "CBB/CBBSupport.h"
#include "Defines/AI.h"
#include "Defines/Buildings.h"
#include "Defines/Object.h"
#include "MapObjects/CMapObjectMgr.h"
#include "MapObjects/IEntity.h"
#include "World/CWorldManager.h"
#include "World/helper.h"

// Definitions for class CScanner

// address=[0x1301390]
// Decompiled from bool __cdecl CScanner::FindNearestEnemyTowerInSector(  struct SFindNearestResult *a1,  int a2,  int a3,  int a4,  int iPlayerId)
bool __cdecl CScanner::FindNearestEnemyTowerInSector(struct SFindNearestResult &a1, int a2, int a3, int a4, int _iPlayerId) {
  BB_ASSERT(g_cAlliances.IsValidUsedPlayerId(_iPlayerId))
  return FindNearestTowerInSector(a1, a2, a3, a4, CAlliances::PlayerEnemyBits(_iPlayerId));
}


// address=[0x13065f0]
// Decompiled from int __cdecl CScanner::FindNearestOwnTowerInSector(int a1, int a2, int a3, int _iPlayerId)
int __cdecl CScanner::FindNearestOwnTowerInSector(int a1, int a2, int a3, int _iPlayerId) {
  BB_ASSERT(g_cAlliances.IsValidUsedPlayerId(_iPlayerId))
  SFindNearestResult v5{}; // [esp+0h] [ebp-Ch] BYREF
  CScanner::FindNearestTowerInSector(v5, a1, a2, a3, CAlliances::PlayerBit(_iPlayerId));
  return v5.m_iNearestFoundId;
}


// address=[0x15df090]
// Decompiled from char __cdecl CScanner::CheckIfAEnemyUnitMayBeInRange(unsigned int _iX, unsigned int _iY, int _iRadius, int _iPlayerId)
bool __cdecl CScanner::CheckIfAEnemyUnitMayBeInRange(int _iX, int _iY, int _iRadius, int _iPlayerId) {
  if(!CWorldManager::InWorld(_iX, _iY)
     && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 461, "g_cWorld.InWorld(_iX, _iY)") == 1) {
    __debugbreak();
  }
  if(_iRadius <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 462, "_iRadius > 0") == 1)
    __debugbreak();
  if(!CAlliances::IsValidUsedPlayerId(_iPlayerId)
     && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 463, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1) { // BB_ASSERT(g_cAlliances.IsValidUsedPlayerId(_iPlayerId))
    __debugbreak();
  }
  int     iAllianceId = CAlliances::AllianceId(_iPlayerId);
  CVWList cVWList{_iX, _iY, _iRadius};
  for(int i = 0; i < cVWList.Size(); ++i) {
    if(CInfluMap::EnemyValueVW(cVWList[i].m_iV, cVWList[i].m_iW, iAllianceId) > 0)
      return 1;
  }
  return 0;
}


// address=[0x15df200]
// Decompiled from int __cdecl CScanner::CountCiviliansAndFindNearestInSector(  unsigned int _iX,  unsigned int _iY,  int _iRadius,  int a4,  int *a5)
int __cdecl CScanner::CountCiviliansAndFindNearestInSector(int _iX, int _iY, int _iRadius, int a4, int *a5) {
  const struct CVWList::SVW *v5; // eax
  // al
  // eax
  CWarMapNode *v8; // eax
  // [esp-4h] [ebp-11Ch]
  // [esp+4h] [ebp-114h]
  // [esp+8h] [ebp-110h]
  // [esp+Ch] [ebp-10Ch]
  // [esp+14h] [ebp-104h]
  // [esp+18h] [ebp-100h]
  // [esp+1Ch] [ebp-FCh]
  // [esp+20h] [ebp-F8h]
  // [esp+24h] [ebp-F4h]
  // [esp+28h] [ebp-F0h]
  // [esp+2Ch] [ebp-ECh]
  BB_ASSERT(CWorldManager::InWorld(_iX, _iY))
  BB_ASSERT(_iRadius > 0)
  int iResult = 0;
  int v16 = CWorldManager::SectorId(_iX, _iY);
  int iNearestXY = -1;
  int v14 = 0x4000;
  if(v16 > 0) {
    CVWList cVWList{_iX, _iY, _iRadius};
    for(int i = 0; i < cVWList.Size(); ++i) {
      for(int j = CWarMap::FirstEntityIdVW(0, cVWList[i].m_iV, cVWList[i].m_iW); j; j = CWarMapNode::Next(v8)) {
        IEntity &rEntity = CMapObjectMgr::Entity(j);
        if(!rEntity.WarriorType()
           && rEntity.FlagBits(ENTITY_FLAG_Ready | ENTITY_FLAG_Visible) == (ENTITY_FLAG_Ready | ENTITY_FLAG_Visible)) {
          char v6 = rEntity.OwnerId();
          if((a4 & CAlliances::PlayerBit(v6)) != 0) {
            int v11 = rEntity.X();
            int v12 = rEntity.Y();
            if(CWorldManager::SectorId(v11, v12) == v16) {
              ++iResult;
              int v10 = rEntity.Y() - _iY;
              int v7 = rEntity.X();
              int v15 = Grid::Distance(v7 - _iX, v10);
              if(v15 < v14) {
                v14 = v15;
                iNearestXY = rEntity.PackedXY();
              }
            }
          }
        }
        v8 = rEntity.WarMapNode();
      }
    }
  }
  if(a5)
    *a5 = iNearestXY;

  BB_ASSERT((iResult == 0) || (iNearestXY >= 0))
  return iResult;
}


// address=[0x15df4f0]
// Decompiled from void __cdecl CScanner::CountFighters(  struct SCountFightersResult *a1,  unsigned int _iX,  unsigned int _iY,  int _iRadius,  int _iPlayerId)
void __cdecl CScanner::CountFighters(struct SCountFightersResult &a1, int _iX, int _iY, int _iRadius, int _iPlayerId) {
  const struct CVWList::SVW *v5; // eax
  // eax
  // al
  CWarMapNode *v8; // eax
  // [esp-4h] [ebp-158h]
  // [esp+14h] [ebp-140h] MAPDST
  // [esp+1Ch] [ebp-138h]
  // [esp+20h] [ebp-134h]
  // [esp+28h] [ebp-12Ch]
  // [esp+30h] [ebp-124h]
  // [esp+34h] [ebp-120h]
  // [esp+38h] [ebp-11Ch]
  // [esp+44h] [ebp-110h]
  // [esp+48h] [ebp-10Ch]

  // [esp+54h] [ebp-100h]
  int iSearchValues[6]; // [esp+138h] [ebp-1Ch] BYREF

  BB_ASSERT(CWorldManager::InWorld(_iX, _iY))
  BB_ASSERT(_iRadius > 0)
  BB_ASSERT(CAlliances::IsValidUsedPlayerId(_iPlayerId))

  CVWList cVWList{_iX, _iY, _iRadius};
  int     iAllyBits = CAlliances::PlayerAllyBits(_iPlayerId);
  memset(iSearchValues, 0, sizeof(iSearchValues));
  for(int i = 0; i < cVWList.Size(); ++i) {
    for(int j = CWarMap::FirstEntityIdVW(0, cVWList[i].m_iV, cVWList[i].m_iW); j; j = CWarMapNode::Next(v8)) {
      IEntity &rEntity = CMapObjectMgr::Entity(j);
      int      iEntityWarriorType = 1 << rEntity.WarriorType();
      if((iEntityWarriorType & 0x3C) != 0) {
        int iEntityXY = rEntity.PackedXY();
        int iEntityY = Y16X16::UnpackYFast(iEntityXY) - _iY;
        int iEntityX = Y16X16::UnpackXFast(iEntityXY);
        if(Grid::DistanceInline(iEntityX - _iX, iEntityY) <= _iRadius) {
          int  bIsOwners = rEntity.OwnerId() == _iPlayerId;
          char iOwnerId = rEntity.OwnerId();
          BOOL bIsEnemy = (iAllyBits & CAlliances::PlayerBit(iOwnerId)) == 0;
          BOOL bNotBowman = iEntityWarriorType != 8; // 1 << AI_WARRIOR_TYPE_BOWMAN = 8
          iSearchValues[bNotBowman] += bIsOwners;
          ++iSearchValues[2 * bIsEnemy + 2 + bNotBowman];
          // 0 = bowmen         - owner
          // 1 = rest           - owner

          // 2 = bowmen         - ally
          // 3 = rest           - ally

          // 4 = bowmen         - enemy
          // 5 = rest           - enemy
        }
      }
      v8 = rEntity.WarMapNode();
    }
  }
  int iTotal = iSearchValues[1] + iSearchValues[0];
  a1.m_uOwnedBowmen = iSearchValues[0];
  a1.m_uOwnedSoldiers = iTotal;
  iTotal = iSearchValues[3] + iSearchValues[2];
  a1.m_uAllyBowmen = iSearchValues[2];
  a1.m_uAllySoldiers = iTotal;
  iTotal = iSearchValues[5] + iSearchValues[4];
  a1.m_uEnemyBowmen = iSearchValues[4];
  a1.m_uEnemySoldiers = iTotal;
}


// address=[0x15df900]
// Decompiled from struct SEvalFightersResult *__cdecl CScanner::EvaluateFighters(  struct SEvalFightersResult *a1,  unsigned int _iX,  unsigned int _iY,  int a4,  int a5)
void __cdecl CScanner::EvaluateFighters(struct SEvalFightersResult &_rResults, int _iX, int _iY, int _iRadius, int _iPlayerId) {
  CWarMapNode *pWarMapNode; // eax
  int          v11; // [esp+14h] [ebp-148h]
  int          m_iV; // [esp+20h] [ebp-13Ch]
  int          iAdjInflu; // [esp+28h] [ebp-134h]
  int          iInfluences[3]; // [esp+140h] [ebp-1Ch] BYREF
  int          iUnitCount[3]; // [esp+14Ch] [ebp-10h] BYREF

  BB_ASSERT(CWorldManager::InWorld(_iX, _iY));
  // if(!CWorldManager::InWorld(_iX, _iY)
  //    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 963, "g_cWorld.InWorld(_iX, _iY)") == 1) {
  //   __debugbreak();
  // }
  BB_ASSERT(_iRadius > 0);
  BB_ASSERT(CAlliances::IsValidUsedPlayerId(_iPlayerId));
  // if(!CAlliances::IsValidUsedPlayerId(a5)
  //    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 965, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1) { // BB_ASSERT(g_cAlliances.IsValidUsedPlayerId(_iPlayerId))
  //   __debugbreak();
  // }
  int iSectorId = CWorldManager::SectorId(_iX, _iY);
  BB_ASSERT(iSectorId != 0);

  CVWList cVWList{_iX, _iY, _iRadius};
  int     iAllyMask = CAlliances::PlayerAllyBits(_iPlayerId);
  memset(iUnitCount, 0, sizeof(iUnitCount));
  memset(iInfluences, 0, sizeof(iInfluences));
  for(int i = 0; i < cVWList.Size(); ++i) {
    for(int j = CWarMap::FirstEntityIdVW(0, cVWList[i].m_iV, cVWList[i].m_iW); j; j = pWarMapNode->Next()) {
      IEntity &rEntity = CMapObjectMgr::Entity(j);
      if(((1 << rEntity.WarriorType()) & AI_WARRIOR_TYPE_SOLDIER_MASK) != 0) { // Check to see if Soldier
        int iEntityX = rEntity.X();
        int iEntityY = rEntity.Y();

        if(ITiling::SectorId(CWorldManager::Index(iEntityX, iEntityY)) == iSectorId) {
          int iInlineDistance = Grid::DistanceInline(iEntityX - _iX, iEntityY - _iY);
          if(iInlineDistance <= _iRadius) {
            bool bIsOwn = rEntity.OwnerId() == _iPlayerId;
            char v6 = rEntity.OwnerId();
            bool bIsEnemy = (iAllyMask & CAlliances::PlayerBit(v6)) == 0;
            BB_ASSERT(!(bIsOwn && bIsEnemy))

            // 0 = ally
            // 1 = own
            // 2 = enemy
            unsigned int uIdx = bIsOwn + 2 * bIsEnemy;
            BB_ASSERT(uIdx < 3);

            ++iUnitCount[uIdx];

            int iInfluValue = 16 * CWarMap::SettlerInfluValue(rEntity.Type());
            if(iInlineDistance > 12)
              iAdjInflu = iInfluValue / iInlineDistance;
            else
              iAdjInflu = iInfluValue;
            iInfluences[uIdx] += iAdjInflu;
          }
        }
      }
      pWarMapNode = rEntity.WarMapNode();
    }
  }
  _rResults.m_iAlliedUnits = iUnitCount[0];
  _rResults.m_iOwnUnits = iUnitCount[1];
  _rResults.m_iEnemyUnits = iUnitCount[2];

  _rResults.m_iAllyValue = iInfluences[0];
  _rResults.m_iOwnValue = iInfluences[1];
  _rResults.m_iEnemyValue = iInfluences[2];
}


// address=[0x15dfdc0]
// Decompiled from void __cdecl CScanner::EvaluateTowers(  struct SEvalTowersResult *arg0,  unsigned int _iX,  unsigned int _iY,  int _iRadius,  int _iPlayerId)
void __cdecl CScanner::EvaluateTowers(struct SEvalTowersResult &arg0, int _iX, int _iY, int _iRadius, int _iPlayerId) {
  unsigned __int16 *v8; // eax
  CWarMapNode *     rWarMapNode; // eax
  T_AI_WARRIOR_TYPE v19; // [esp+40h] [ebp-174h]
  int               iInfluence; // [esp+44h] [ebp-170h]
  _DWORD            aStationedSwordmen[3]; // [esp+174h] [ebp-40h] BYREF
  _DWORD            aTowerCount[3]; // [esp+180h] [ebp-34h] BYREF
  _DWORD            aTowerScores[3]; // [esp+18Ch] [ebp-28h] BYREF
  _DWORD            aStationedScore[3]; // [esp+198h] [ebp-1Ch] BYREF
  _DWORD            aStationedBowmen[3]; // [esp+1A4h] [ebp-10h] BYREF
  BB_ASSERT(CWorldManager::InWorld(_iX, _iY));
  // if(!CWorldManager::InWorld(_iX, _iY)
  //    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 963, "g_cWorld.InWorld(_iX, _iY)") == 1) {
  //   __debugbreak();
  // }
  BB_ASSERT(_iRadius > 0);
  BB_ASSERT(CAlliances::IsValidUsedPlayerId(_iPlayerId));
  // if(!CAlliances::IsValidUsedPlayerId(a5)
  //    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 965, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1) { // BB_ASSERT(g_cAlliances.IsValidUsedPlayerId(_iPlayerId))
  //   __debugbreak();
  // }
  int iSectorId = CWorldManager::SectorId(_iX, _iY);
  BB_ASSERT(iSectorId != 0);

  CVWList cVWList{_iX, _iY, _iRadius};
  int     iPlayerAllyBits = CAlliances::PlayerAllyBits(_iPlayerId);
  memset(aTowerCount, 0, sizeof(aTowerCount));
  memset(aTowerScores, 0, sizeof(aTowerScores));
  memset(aStationedSwordmen, 0, sizeof(aStationedSwordmen));
  memset(aStationedBowmen, 0, sizeof(aStationedBowmen));
  memset(aStationedScore, 0, sizeof(aStationedScore));
  for(int i = 0; i < cVWList.Size(); ++i) {
    for(int a1 = CWarMap::FirstEntityIdVW(2, cVWList[i].m_iV, cVWList[i].m_iW); a1; a1 = CWarMapNode::Next(rWarMapNode)) {
      IEntity &rEntity = CMapObjectMgr::Entity(a1);
      if(rEntity.WarriorType() == AI_WARRIOR_TYPE_TOWER_BUILDING) {
        BB_ASSERT(rEntity.ObjType() == BUILDING_OBJ)
        if(rEntity.ObjType() != BUILDING_OBJ
           && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1084, "rEntity.ObjType() == BUILDING_OBJ") == 1) {
          __debugbreak();
        }
        CBuilding &      rBuildingEntity = CBuildingMgr::operator[](a1);
        unsigned __int16 iBuildingXY = rBuildingEntity.EnsignPackedXY();
        int              iBuildingX = Y16X16::UnpackXFast(iBuildingXY);

        int iBuildingY = Y16X16::UnpackYFast(rBuildingEntity.EnsignPackedXY());
        int iBuildingWorldIndex = CWorldManager::Index(iBuildingX, iBuildingY);
        if(ITiling::SectorId(iBuildingWorldIndex) == iSectorId) {
          int iInlineDistance = Grid::DistanceInline(iBuildingX - _iX, iBuildingY - _iY);
          if(iInlineDistance <= _iRadius) {
            int  iOwner = rBuildingEntity.OwnerId();
            BOOL bIsEnemy = (iPlayerAllyBits & CAlliances::PlayerBit(iOwner)) == 0;
            if(iOwner == _iPlayerId
               && bIsEnemy
               && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1105, "!(uIsOwn && uIsEnemy)") == 1) {
              __debugbreak();
            }
            // 0 == Ally
            // 1 == Owner (Owner == PlayerId = 1)
            // 2 == Enemy
            unsigned int uIdx = (iOwner == _iPlayerId) + 2 * bIsEnemy;
            if(uIdx >= 3 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1109, "uIdx < 3") == 1)
              __debugbreak();
            ++aTowerCount[uIdx];
            int iTowerScore = 1;
            int iBuildingType = rBuildingEntity.Type();
            if(iBuildingType == BUILDING_GUARDTOWERBIG) {
              iTowerScore = 2;
            } else if(iBuildingType == BUILDING_CASTLE) {
              iTowerScore = 4;
            }
            aTowerScores[uIdx] += iTowerScore;
            if(rBuildingEntity.FlagBits(ENTITY_FLAG_Ready)) {
              IBuildingRole *pBuildingRole = (void **) rBuildingEntity.Role();
              if(!j____RTDynamicCast(
                   pBuildingRole,
                   0,
                   &IBuildingRole__RTTI_Type_Descriptor_,
                   &CMilitaryBuildingRole__RTTI_Type_Descriptor_,
                   0)
                 && BBSupportDbgReport(
                   2,
                   "Pathing\\Scanner.cpp",
                   1132,
                   "dynamic_cast<const CMilitaryBuildingRole*>(pBuildingRole) != 0") == 1) {
                __debugbreak();
              }
              char *rInhabitants = CMilitaryBuildingRole::Inhabitants((char *) pBuildingRole);
              int   iInhabitantCount = std::vector<unsigned short>::size(rInhabitants);
              int   iStationedBowmen = 0;
              int   iStationedSwordmen = 0;
              int   iStationedScore = 0;
              for(int j = 0; j < iInhabitantCount; ++j) {
                v8 = std::vector<unsigned short>::operator[](j);
                if(*v8) {
                  IEntity &rInhabitant = CMapObjectMgr::Entity(*v8);
                  if(rInhabitant.ObjType() != SETTLER_OBJ
                     && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1154, "rInhabitant.ObjType() == SETTLER_OBJ") == 1) {
                    __debugbreak();
                  }
                  unsigned int v10 = rInhabitant.Type();
                  v19 = static_cast<T_AI_WARRIOR_TYPE>(rInhabitant.WarriorType());
                  int iStationedInfluence = 16 * CWarMap::SettlerInfluValue(v10);
                  if(iInlineDistance > 12)
                    iInfluence = iStationedInfluence / iInlineDistance;
                  else
                    iInfluence = iStationedInfluence;
                  if(v19 == AI_WARRIOR_TYPE_BOWMAN) {
                    ++iStationedBowmen;
                    iStationedScore += 2 * iInfluence;
                  } else if(v19 == AI_WARRIOR_TYPE_SWORDMAN) {
                    ++iStationedSwordmen;
                    iStationedScore += iInfluence;
                  }
                }
              }
              aStationedBowmen[uIdx] += iStationedBowmen;
              aStationedSwordmen[uIdx] += iStationedSwordmen;
              aStationedScore[uIdx] += iStationedScore;
            }
          }
        }
      }
      rWarMapNode = rEntity.WarMapNode();
    }
  }
  arg0.m_iEnemyStationedBowmen = aStationedBowmen[2];
  arg0.m_iEnemyStationedSwordmen = aStationedSwordmen[2];
  arg0.m_iEnemyTowerCount = aTowerCount[2];
  arg0.m_iEnemyEvalScore = aStationedScore[2] + aTowerScores[2];
}


// address=[0x15e0530]
// Decompiled from bool __cdecl CScanner::FindNearestTowerInSector(  struct SFindNearestResult *arg0,  unsigned int iX,  unsigned int iY,  int _iRadius,  int a5)
bool __cdecl CScanner::FindNearestTowerInSector(struct SFindNearestResult &_rResult, int iX, int iY, int _iRadius, int a5) {
  BB_ASSERT(CWorldManager::InWorld(iX, iY))
  BB_ASSERT(_iRadius > 0)
  int iSectorId = CWorldManager::SectorId(iX, iY);
  BB_ASSERT(iSectorId != 0)

  CVWList cVWList{iX, iY, _iRadius};

  _rResult.m_iNearestFoundId = 0;
  _rResult.m_iDistance = 0x4000;
  CWarMapNode *pWarMapNode; // eax
  for(int i = 0; i < cVWList.Size(); ++i) {
    for(int iEntityId = CWarMap::FirstEntityIdVW(2, cVWList[i].m_iV, cVWList[i].m_iW); iEntityId; iEntityId = pWarMapNode->Next()) {
      IEntity &v18 = CBuildingMgr[iEntityId];
      if(v18.WarriorType() == AI_WARRIOR_TYPE_TOWER_BUILDING && v18.FlagBits(ENTITY_FLAG_Ready) != 0) {
        char v8 = v18.OwnerId();
        if((a5 & CAlliances::PlayerBit(v8)) != 0) {
          int iBuildingX = v18.EnsignX();
          int iBuildingY = v18.EnsignY();
          int iTowerSectorId = CWorldManager::SectorId(iBuildingX, iBuildingY);
          if(!iTowerSectorId && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1244, "iTowerSectorId != 0") == 1)
            __debugbreak();
          if(iTowerSectorId == iSectorId) {
            int iDistance = Grid::Distance(iBuildingX - iX, iBuildingY - iY);
            if(iDistance < _rResult.m_iDistance) {
              //arg0 = (struct SFindNearestResult) __PAIR64__(iDistance, a1);
              _rResult.m_iDistance = iDistance;
              _rResult.m_iNearestFoundId = iEntityId;
            }
          }
        }
      }
      pWarMapNode = v18.WarMapNode();
    }
  }

  return _rResult.m_iNearestFoundId > 0;
}


// address=[0x15e08a0]
// Decompiled from int __cdecl CScanner::FindNearestFighter(  unsigned int _iX,  unsigned int _iY,  int _iRadius,  int _iFighterSearchMask,  int _iOwnerBitMask)
int __cdecl CScanner::FindNearestFighter(int _iX, int _iY, int _iRadius, int _iFighterSearchMask, int _iOwnerBitMask) {
  BB_ASSERT(CWorldManager::InWorld(_iX, _iY))
  BB_ASSERT(_iRadius > 0)

  int          iSmallestDistance = 0x4000;
  int          iFoundFighter = -1;
  CWarMapNode *pWarMapNode; // eax

  CVWList cVWList{_iX, _iY, _iRadius};
  for(int i = 0; i < cVWList.Size(); ++i) {
    for(int j = CWarMap::FirstEntityIdVW(0, cVWList[i].m_iV, cVWList[i].m_iW); j; j = pWarMapNode->Next()) {
      IEntity &rEntity = CMapObjectMgr::Entity(j);
      if((_iFighterSearchMask & (1 << rEntity.WarriorType())) != 0) {
        int iOwnerId = rEntity.OwnerId();
        if((_iOwnerBitMask & CAlliances::PlayerBit(iOwnerId)) != 0) {
          int iEntityXY = rEntity.PackedXY();
          int iEntityYDistance = Y16X16::UnpackYFast(iEntityXY) - _iY;
          int iEntityX = Y16X16::UnpackXFast(iEntityXY);
          int iEntityDistanceInline = Grid::DistanceInline(iEntityX - _iX, iEntityYDistance);
          if(iEntityDistanceInline < iSmallestDistance) {
            iSmallestDistance = iEntityDistanceInline;
            iFoundFighter = iEntityXY;
          }
        }
      }
      pWarMapNode = rEntity.WarMapNode();
    }
  }
  if(iSmallestDistance > _iRadius)
    return -1;
  return iFoundFighter;
}


// address=[0x15e0af0]
// Decompiled from int __cdecl CScanner::FindNearestAnimal(unsigned int _iX, unsigned int _iY, int a3, bool a4, int a5)
int __cdecl CScanner::FindNearestAnimal(int _iX, int _iY, int _iRadius, bool a4, int a5) {
  const struct CVWList::SVW *v5; // eax
  // eax
  unsigned int v7; // eax
  // eax
  CWarMapNode *pWarMapNode; // eax
  // [esp-4h] [ebp-10Ch]
  // [esp-4h] [ebp-10Ch]
  // [esp+0h] [ebp-108h]
  // [esp+8h] [ebp-100h]
  // [esp+Ch] [ebp-FCh]
  // [esp+10h] [ebp-F8h]
  // [esp+14h] [ebp-F4h]

  // [esp+1Ch] [ebp-ECh]
  // [esp+20h] [ebp-E8h]


  BB_ASSERT(CWorldManager::InWorld(_iX, _iY))
  BB_ASSERT(_iRadius > 0)

  int v16 = 0x4000;
  int v15 = -1;

  CVWList cVWList{_iX, _iY, _iRadius};
  for(int i = 0; i < cVWList.Size(); ++i) {
    for(int j = CWarMap::FirstEntityIdVW(3, cVWList[i].m_iV, cVWList[i].m_iW); j; j = pWarMapNode->Next()) {
      IEntity &rEntity = CMapObjectMgr::Entity(j);
      int      v19 = rEntity.PackedXY();
      int      v11 = Y16X16::UnpackYFast(v19);
      int      v6 = Y16X16::UnpackXFast(v19);
      if(CWorldManager::EcoSectorId(v6, v11) == a5) {
        if(!a4 || g_cAnimalMgr->IsHuntable(rEntity.Type())) {
          int v12 = Y16X16::UnpackYFast(v19) - _iY;
          int v8 = Y16X16::UnpackXFast(v19);
          int v14 = Grid::DistanceInline(v8 - _iX, v12);
          if(v14 < v16) {
            v16 = v14;
            v15 = v19;
          }
        }
      }
      pWarMapNode = rEntity.WarMapNode();
    }
  }
  if(v16 > _iRadius)
    return -1;
  return v15;
}


// address=[0x15e0d40]
// Decompiled from int __cdecl CScanner::FindNearestEnemyBowman(unsigned int a1, unsigned int a2, int a3, int a4)
int __cdecl CScanner::FindNearestEnemyBowman(int _iY, int _iX, int _iRadius, int _iPlayerId) {
  // eax

  int v4 = CAlliances::PlayerEnemyBits(_iPlayerId);
  return FindNearestFighter(_iY, _iX, _iRadius, 8, v4);// 1 << BOWMAN
}


// address=[0x15e0d70]
// Decompiled from int __cdecl CScanner::FindNearestEnemySwordsman(unsigned int a1, unsigned int a2, int a3, int a4)
int __cdecl CScanner::FindNearestEnemySwordsman(int _iX, int _iY, int _iRadius, int _iPlayerId) {
  // eax

  int v4 = CAlliances::PlayerEnemyBits(_iPlayerId);
  return FindNearestFighter(_iX, _iY, _iRadius, 4, v4);// 1 << SWORDMAN
}


// address=[0x15e0da0]
// Decompiled from int __cdecl CScanner::FindNearestEnemyFighter(unsigned int a1, unsigned int a2, int a3, int a4)
int __cdecl CScanner::FindNearestEnemyFighter(int _iX, int _iY, int _iRadius, int _iPlayerId) {
  // eax

  int v4 = CAlliances::PlayerEnemyBits(_iPlayerId);
  return FindNearestFighter(_iX, _iY, _iRadius, 60, v4);// Yes
}


// address=[0x15e0dd0]
// Decompiled from int __cdecl CScanner::FindNearestOwnFighter(unsigned int a1, unsigned int a2, int a3, char a4)
int __cdecl CScanner::FindNearestOwnFighter(int _iX, int _iY, int _iRadius, int _iPlayerId) {
  // eax

  int v4 = CAlliances::PlayerBit(_iPlayerId);
  return FindNearestFighter(_iX, _iY, _iRadius, 60, v4);
}


// address=[0x15e0e00]
// Decompiled from int __cdecl CScanner::FindNearestAllyFighter(unsigned int a1, unsigned int a2, int a3, int a4)
int __cdecl CScanner::FindNearestAllyFighter(int a1, int a2, int a3, int a4) {
  // eax

  int v4 = CAlliances::PlayerAllyBits(a4);
  return FindNearestFighter(a1, a2, a3, 60, v4);
}


// address=[0x15e0e30]
// Decompiled from int __cdecl CScanner::CountSettlers(  unsigned int _iX,  unsigned int _iY,  int _iRadius,  int *_pPlayerIds,  int *_pSettlerTypes,  int _iSectorId,  int _iLimit)
int __cdecl CScanner::CountSettlers(int _iX, int _iY, int _iRadius, int const *_pPlayerIds, int const *_pSettlerTypes, int _iSectorId, int _iLimit) {
  IEntity *v7; // eax
  CTile *  v8; // eax
  ; // eax

  BB_ASSERT(g_cWorld.InWorld(_iX, _iY));
  BB_ASSERT(_iRadius > 0);
  BB_ASSERT(_iSectorId >= 0);
  BB_ASSERT(_pPlayerIds != 0);
  BB_ASSERT(_pSettlerTypes != 0);
  BB_ASSERT(_iLimit > 0);

  int iCount = 0;

  for(int const *i = _pPlayerIds; *i; ++i) {
    for(int const *j = _pSettlerTypes; *j; ++j) {
      IMovingEntity *pEntity;
      for(int k = g_cSettlerMgr->GetFirstSettlerId(*i, *j); k; k = pEntity->Next()) {
        int v15 = CMapObjectMgr::Entity(k).PackedXY();
        int v13 = Y16X16::UnpackXFast(v15);
        int v14 = Y16X16::UnpackYFast(v15);
        if(Grid::DistanceInline(v13 - _iX, v14 - _iY) <= _iRadius) {
          int v12 = CWorldManager::Index(v13, v14);
          int v11 = ITiling::NormalTileId(v12);
          if(ITiling::Tile(v11).SectorId() == _iSectorId && ++iCount >= _iLimit)
            return iCount;
        }
        pEntity = &CMapObjectMgr::MovingEntity(k);
      }
    }
  }
  return iCount + 1;
}


// address=[0x15e1070]
// Decompiled from int __cdecl CScanner::IsNearMyLand(int _iPlayerId, unsigned int _iX, unsigned int _iY)
int __cdecl CScanner::IsNearMyLand(int _iPlayerId, int _iX, int _iY) {
  // eax
  // eax
  // [esp+4h] [ebp-50h]
  // [esp+8h] [ebp-4Ch]
  // [esp+14h] [ebp-40h]
  // [esp+24h] [ebp-30h]
  // [esp+28h] [ebp-2Ch]
  // [esp+2Ch] [ebp-28h]
  // [esp+30h] [ebp-24h]
  // [esp+34h] [ebp-20h]
  // [esp+38h] [ebp-1Ch]
  // [esp+3Ch] [ebp-18h]
  // [esp+40h] [ebp-14h]
  // [esp+44h] [ebp-10h]
  // [esp+48h] [ebp-Ch]
  // [esp+50h] [ebp-4h]
  // [esp+50h] [ebp-4h]
  // [esp+50h] [ebp-4h]

  BB_ASSERT(g_cAlliances.IsValidUsedPlayerId(_iPlayerId))
  BB_ASSERT(g_cWorld.InWorld(_iX, _iY));

  unsigned int iMapWidth = CWorldManager::Width();
  int          v8 = CWorldManager::Index(_iX, _iY);
  if(ITiling::OwnerId(v8) == _iPlayerId)
    return 0;
  int v9 = COwnerMap::OwnerBit(_iPlayerId);
  int v10 = Squares::XYToVW(_iX);
  int v11 = Squares::XYToVW(_iY);
  if((v9 & COwnerMap::OwnerBits9VW(v10, v11)) == 0)
    return -1;
  if((v9 & COwnerMap::OwnerBits1VW(v10, v11)) == 0 && Grid::InQuadrat((_iX & 0xF) - 4, (_iY & 0xF) - 4, 8u))
    return -1;
  if(_iY - 4 < iMapWidth - 8 && _iX - 4 < iMapWidth - 8) {
    for(int i = 0; i < 6; ++i) {
      int v16 = CWorldManager::NeighborRelIndex(i);
      int v19 = v16 + v16 + v8;
      if(ITiling::OwnerId(v16 + v8) == _iPlayerId)
        return 1;
      int v4 = ITiling::OwnerId(v19);
      int v20 = v16 + v19;
      if(v4 == _iPlayerId)
        return 1;
      int v5 = ITiling::OwnerId(v20);
      int v21 = v16 + v20;
      if(v5 == _iPlayerId)
        return 1;
      if(ITiling::OwnerId(v21) == _iPlayerId)
        return 1;
    }
  } else {
    for(int j = 0; j < 6; ++j) {
      int          x = g_sNeighborPoints[j].x;
      int          y = g_sNeighborPoints[j].y;
      int          v14 = _iX;
      unsigned int v15 = _iY;
      for(int k = 0; k < 4; ++k) {
        v14 += x;
        v15 += y;
        if(!Grid::InQuadrat(v14, v15, iMapWidth))
          break;
        if(ITiling::OwnerId(v14 + iMapWidth * v15) == _iPlayerId)
          return 1;
      }
    }
  }
  return -1;
}


// address=[0x15e13a0]
// Decompiled from char __cdecl CScanner::FindNearestPlayerLand(int a1, int *a2, int *a3)
bool __cdecl CScanner::FindNearestPlayerLand(int _iOwnerId, int &_rX, int &_rY) {
  int iSectorId = CWorldManager::SectorId(_rX, _rY);
  if(iSectorId <= 0)
    return 0;
  CSpiralWalk v4(_rX, _rY, 50);

  int iY; // [esp+18h] [ebp-14h] BYREF
  int iX; // [esp+1Ch] [ebp-10h] BYREF
  while(v4.NextXY(&iX, &iY)) {
    int iIdx = CWorldManager::Index(iX, iY);
    if(ITiling::SectorId(iIdx) == iSectorId && ITiling::OwnerId(iIdx) == _iOwnerId) {
      _rX = iX;
      _rY = iY;
      return 1;
    }
  }
  return 0;
}


// address=[0x15e1460]
// Decompiled from char __cdecl CScanner::FindAnyEnemyFighter(unsigned int _iX, unsigned int _iY, int _iRadius, int a4, int a5)
bool __cdecl CScanner::FindAnyEnemyFighter(int _iX, int _iY, int _iRadius, int a4, int a5) {
  CWarMapNode *pWarMapNode; // eax

  BB_ASSERT(CWorldManager::InWorld(_iX, _iY))
  BB_ASSERT(_iRadius > 0)
  BB_ASSERT(CAlliances::IsValidUsedPlayerId(a5))

  int v14 = CAlliances::AllianceId(a5);
  int v10 = CAlliances::PlayerEnemyBits(a5);
  if(_iRadius <= 16 && !CInfluMap::EnemyValueXY(_iX, _iY, v14))
    return 0;

  CVWList cVWList{_iX, _iY, _iRadius};
  for(int i = 0; i < cVWList.Size(); ++i) {
    if(CInfluMap::EnemyValueVW(cVWList[i].m_iV, cVWList[i].m_iW, v14) >= 16) {
      for(int j = CWarMap::FirstEntityIdVW(0, cVWList[i].m_iV, cVWList[i].m_iW); j; j = CWarMapNode::Next(pWarMapNode)) {
        IEntity &rEntity = CMapObjectMgr::Entity(j);

        if((v10 & CAlliances::PlayerBit(rEntity.OwnerId())) != 0 && (a4 & (1 << rEntity.WarriorType())) != 0) {
          int v11 = rEntity.PackedXY();
          int v9 = Y16X16::UnpackYFast(v11) - _iY;
          int v7 = Y16X16::UnpackXFast(v11);
          if(Grid::DistanceInline(v7 - _iX, v9) <= _iRadius)
            return 1;
        }
        pWarMapNode = rEntity.WarMapNode();
      }
    }
  }
  return 0;
}


// address=[0x15e1710]
// Decompiled from char __cdecl CScanner::FindAnySettlerOrVehicle(unsigned int _iX, unsigned int _iY, int _iRadius, int _iPlayerId)
bool __cdecl CScanner::FindAnySettlerOrVehicle(int _iX, int _iY, int _iRadius, int _iPlayerId) {
  CWarMapNode *pWarMapNode; // eax


  if(!CWorldManager::InWorld(_iX, _iY)
     && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 666, "g_cWorld.InWorld(_iX, _iY)") == 1) {
    __debugbreak();
  }
  if(_iRadius <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 667, "_iRadius > 0") == 1)
    __debugbreak();
  if(!CAlliances::IsValidUsedPlayerId(_iPlayerId)
     && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 668, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1) { // BB_ASSERT(g_cAlliances.IsValidUsedPlayerId(_iPlayerId))
    __debugbreak();
  }
  CVWList cVWList{_iX, _iY, _iRadius};
  for(int i = 0; i < cVWList.Size(); ++i) {
    for(int j = CWarMap::FirstEntityIdVW(0, cVWList[i].m_iV, cVWList[i].m_iW); j; j = CWarMapNode::Next(pWarMapNode)) {
      IEntity &rEntity = CMapObjectMgr::Entity(j);
      if(rEntity.OwnerId() == _iPlayerId) {
        int v14 = rEntity.PackedXY();
        int v9 = Y16X16::UnpackYFast(v14) - _iY;
        int v4 = Y16X16::UnpackXFast(v14);
        if(Grid::DistanceInline(v4 - _iX, v9) <= _iRadius)
          return 1;
      }
      pWarMapNode = rEntity.WarMapNode();
    }
    for(int k = CWarMap::FirstEntityIdVW(1, cVWList[i].m_iV, cVWList[i].m_iW); k; k = CWarMapNode::Next(pWarMapNode)) {
      IEntity &rEntity = CMapObjectMgr::Entity(k);
      if(rEntity.OwnerId() == _iPlayerId) {
        int v11 = rEntity.PackedXY();
        int v10 = Y16X16::UnpackYFast(v11) - _iY;
        int v7 = Y16X16::UnpackXFast(v11);
        if(Grid::DistanceInline(v7 - _iX, v10) <= _iRadius)
          return 1;
      }
      pWarMapNode = rEntity.WarMapNode();
    }
  }
  return 0;
}


// address=[0x15e19d0]
// Decompiled from char __cdecl CScanner::IsAreaCompletelyOwned(unsigned int _iX, unsigned int _iY, int _iRadius, int _iPlayerId)
bool __cdecl CScanner::IsAreaCompletelyOwned(int _iX, int _iY, int _iRadius, int _iPlayerId) {
  int iX; // [esp+14h] [ebp-20h] BYREF
  int iY; // [esp+18h] [ebp-1Ch] BYREF
  BB_ASSERT(CWorldManager::InWorld(_iX, _iY))
  BB_ASSERT((_iRadius >= 0) & (_iRadius < SPIRAL_RADIUS_MAX)) /* SPIRAL_RADIUS_MAX = 75 */
  BB_ASSERT(g_cAlliances.IsValidUsedPlayerId(_iPlayerId))

  CSpiralWalk v5{_iX, _iY, _iRadius};
  while(v5.NextXY(&iX, &iY)) {
    int v11 = CWorldManager::Index(iX, iY);
    if(ITiling::OwnerId(v11) != _iPlayerId && !CWorldManager::IsWater(v11))
      return 0;
  }
  return 1;
}


// address=[0x15e1b40]
// Decompiled from char __cdecl CScanner::IsAreaCompletelyGreen(unsigned int _iX, unsigned int _iY, int _iRadius)
bool __cdecl CScanner::IsAreaCompletelyGreen(int _iX, int _iY, int _iRadius) {
  int v6; // [esp+14h] [ebp-10h] BYREF
  int v7; // [esp+18h] [ebp-Ch] BYREF

  BB_ASSERT(CWorldManager::InWorld(_iX, _iY))
  if(!CWorldManager::InWorld(_iX, _iY)
     && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1479, "g_cWorld.InWorld(_iX, _iY)") == 1) {
    __debugbreak();
  }
  BB_ASSERT((_iRadius >= 0) & (_iRadius < SPIRAL_RADIUS_MAX));

  CSpiralWalk v4{_iX, _iY, _iRadius};
  while(v4.NextXY(&v6, &v7)) {
    int v5 = CWorldManager::Index(v6, v7);
    if(CWorldManager::FlagBits(v5, 4u))
      return 0;
  }
  return 1;
}


// address=[0x15e1c30]
// Decompiled from char __cdecl CScanner::IsAreaCompletelyDarkLand(unsigned int _iX, unsigned int _iY, int _iRadius)
bool __cdecl CScanner::IsAreaCompletelyDarkLand(int _iX, int _iY, int _iRadius) {
  int v6; // [esp+14h] [ebp-10h] BYREF
  int v7; // [esp+18h] [ebp-Ch] BYREF

  BB_ASSERT(CWorldManager::InWorld(_iX, _iY))

  BOOL v9 = _iRadius >= 0;
  BOOL v8 = _iRadius < 75;
  BB_ASSERT((_iRadius >= 0) & (_iRadius < SPIRAL_RADIUS_MAX));
  CSpiralWalk v4{_iX, _iY, _iRadius};
  while(v4.NextXY(&v6, &v7)) {
    int v5 = CWorldManager::Index(v6, v7);
    if(!CWorldManager::FlagBits(v5, 4u))
      return 0;
  }
  return 1;
}


