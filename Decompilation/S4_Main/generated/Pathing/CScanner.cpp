#if FALSE
#include "CScanner.h"

// Definitions for class CScanner

// address=[0x1301390]
// Decompiled from bool __cdecl CScanner::FindNearestEnemyTowerInSector(  struct SFindNearestResult *a1,  unsigned int a2,  unsigned int a3,  int a4,  int iPlayerId)
bool __cdecl CScanner::FindNearestEnemyTowerInSector(struct SFindNearestResult & a1, int a2, int a3, int a4, int iPlayerId) {
  
  int v6; // [esp+0h] [ebp-4h]

  if ( !CAlliances::IsValidUsedPlayerId(iPlayerId)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Pathing\\Scanner.h",
         377,
         "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  v6 = CAlliances::PlayerEnemyBits(iPlayerId);
  return CScanner::FindNearestTowerInSector(a1, a2, a3, a4, v6);
}


// address=[0x13065f0]
// Decompiled from int __cdecl CScanner::FindNearestOwnTowerInSector(unsigned int a1, unsigned int a2, int a3, int _iPlayerId)
int __cdecl CScanner::FindNearestOwnTowerInSector(int a1, int a2, int a3, int _iPlayerId) {
  
  struct SFindNearestResult v5; // [esp+0h] [ebp-Ch] BYREF
  int v6; // [esp+8h] [ebp-4h]

  if ( !CAlliances::IsValidUsedPlayerId(_iPlayerId)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Pathing\\Scanner.h",
         391,
         "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  v6 = CAlliances::PlayerBit(_iPlayerId);
  CScanner::FindNearestTowerInSector(&v5, a1, a2, a3, v6);
  return v5.m_iNearestFoundId;
}


// address=[0x15df090]
// Decompiled from char __cdecl CScanner::CheckIfAEnemyUnitMayBeInRange(unsigned int _iX, unsigned int _iY, int _iRadius, int _iPlayerId)
bool __cdecl CScanner::CheckIfAEnemyUnitMayBeInRange(int _iX, int _iY, int _iRadius, int _iPlayerId) {
  
  const struct CVWList::SVW *v4; // eax
  int m_iV; // [esp+0h] [ebp-F4h]
  int iAllianceId; // [esp+8h] [ebp-ECh]
  int i; // [esp+Ch] [ebp-E8h]
  CVWList v9; // [esp+10h] [ebp-E4h] BYREF

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 461, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( _iRadius <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 462, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( !CAlliances::IsValidUsedPlayerId(_iPlayerId)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 463, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  iAllianceId = CAlliances::AllianceId(_iPlayerId);
  CVWList::CVWList(&v9, _iX, _iY, _iRadius);
  for ( i = 0; i < CVWList::Size(&v9); ++i )
  {
    m_iV = CVWList::operator[](&v9, i)->m_iV;
    v4 = CVWList::operator[](&v9, i);
    if ( CInfluMap::EnemyValueVW(m_iV, v4->m_iW, iAllianceId) > 0 )
      return 1;
  }
  return 0;
}


// address=[0x15df200]
// Decompiled from int __cdecl CScanner::CountCiviliansAndFindNearestInSector(  unsigned int _iX,  unsigned int _iY,  int _iRadius,  int a4,  int *a5)
int __cdecl CScanner::CountCiviliansAndFindNearestInSector(int _iX, int _iY, int _iRadius, int a4, int * a5) {
  
  const struct CVWList::SVW *v5; // eax
  char v6; // al
  int v7; // eax
  CWarMapNode *v8; // eax
  int v10; // [esp-4h] [ebp-11Ch]
  int v11; // [esp+4h] [ebp-114h]
  int v12; // [esp+8h] [ebp-110h]
  int m_iV; // [esp+Ch] [ebp-10Ch]
  int iSmallestDistance; // [esp+14h] [ebp-104h]
  int iDistance; // [esp+18h] [ebp-100h]
  int iSectorId; // [esp+1Ch] [ebp-FCh]
  int iNearestXY; // [esp+20h] [ebp-F8h]
  int j; // [esp+24h] [ebp-F4h]
  int iResult; // [esp+28h] [ebp-F0h]
  int i; // [esp+2Ch] [ebp-ECh]
  IEntity *v21; // [esp+30h] [ebp-E8h]
  CVWList v22; // [esp+34h] [ebp-E4h] BYREF

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 817, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( _iRadius <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 818, "_iRadius > 0") == 1 )
    __debugbreak();
  iResult = 0;
  iSectorId = CWorldManager::SectorId(_iX, _iY);
  iNearestXY = -1;
  iSmallestDistance = 0x4000;
  if ( iSectorId > 0 )
  {
    CVWList::CVWList(&v22, _iX, _iY, _iRadius);
    for ( i = 0; i < CVWList::Size(&v22); ++i )
    {
      m_iV = CVWList::operator[](&v22, i)->m_iV;
      v5 = CVWList::operator[](&v22, i);
      for ( j = CWarMap::FirstEntityIdVW(0, m_iV, v5->m_iW); j; j = CWarMapNode::Next(v8) )
      {
        v21 = CMapObjectMgr::Entity(j);
        if ( IEntity::WarriorType(v21) == AI_WARRIOR_TYPE_NONE
          && IEntity::FlagBits(v21, ENTITY_FLAG_Ready|ENTITY_FLAG_Visible) == (ENTITY_FLAG_Ready|ENTITY_FLAG_Visible) )
        {
          v6 = IEntity::OwnerId(v21);
          if ( (a4 & CAlliances::PlayerBit(v6)) != 0 )
          {
            v11 = IEntity::X(v21);
            v12 = IEntity::Y(v21);
            if ( CWorldManager::SectorId(v11, v12) == iSectorId )
            {
              ++iResult;
              v10 = IEntity::Y(v21) - _iY;
              v7 = IEntity::X(v21);
              iDistance = Grid::Distance(v7 - _iX, v10);
              if ( iDistance < iSmallestDistance )
              {
                iSmallestDistance = iDistance;
                iNearestXY = IEntity::PackedXY(v21);
              }
            }
          }
        }
        v8 = IEntity::WarMapNode(v21);
      }
    }
  }
  if ( a5 )
    *a5 = iNearestXY;
  if ( iResult
    && iNearestXY < 0
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 880, "(iResult == 0) || (iNearestXY >= 0)") == 1 )
  {
    __debugbreak();
  }
  return iResult;
}


// address=[0x15df4f0]
// Decompiled from void __cdecl CScanner::CountFighters(  struct SCountFightersResult *a1,  unsigned int _iX,  unsigned int _iY,  int _iRadius,  int _iPlayerId)
void __cdecl CScanner::CountFighters(struct SCountFightersResult & a1, int _iX, int _iY, int _iRadius, int _iPlayerId) {
  
  const struct CVWList::SVW *v5; // eax
  int iEntityX; // eax
  char iOwnerId; // al
  CWarMapNode *v8; // eax
  int iEntityY; // [esp-4h] [ebp-158h]
  int iTotal; // [esp+14h] [ebp-140h] MAPDST
  int bIsOwners; // [esp+1Ch] [ebp-138h]
  int iAllyBits; // [esp+20h] [ebp-134h]
  int m_iV; // [esp+28h] [ebp-12Ch]
  BOOL bIsEnemy; // [esp+30h] [ebp-124h]
  BOOL bNotBowman; // [esp+34h] [ebp-120h]
  int iEntityWarriorType; // [esp+38h] [ebp-11Ch]
  int iEntityXY; // [esp+44h] [ebp-110h]
  int j; // [esp+48h] [ebp-10Ch]
  IEntity *iEntity; // [esp+50h] [ebp-104h]
  int i; // [esp+54h] [ebp-100h]
  CVWList v23; // [esp+58h] [ebp-FCh] BYREF
  int iSearchValues[6]; // [esp+138h] [ebp-1Ch] BYREF

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 892, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( _iRadius <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 893, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( !CAlliances::IsValidUsedPlayerId(_iPlayerId)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 894, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  CVWList::CVWList(&v23, _iX, _iY, _iRadius);
  iAllyBits = CAlliances::PlayerAllyBits(_iPlayerId);
  memset(iSearchValues, 0, sizeof(iSearchValues));
  for ( i = 0; i < CVWList::Size(&v23); ++i )
  {
    m_iV = CVWList::operator[](&v23, i)->m_iV;
    v5 = CVWList::operator[](&v23, i);
    for ( j = CWarMap::FirstEntityIdVW(0, m_iV, v5->m_iW); j; j = CWarMapNode::Next(v8) )
    {
      iEntity = CMapObjectMgr::Entity(j);
      iEntityWarriorType = 1 << IEntity::WarriorType(iEntity);
      if ( (iEntityWarriorType & 0x3C) != 0 )
      {
        iEntityXY = IEntity::PackedXY(iEntity);
        iEntityY = Y16X16::UnpackYFast(iEntityXY) - _iY;
        iEntityX = Y16X16::UnpackXFast(iEntityXY);
        if ( Grid::DistanceInline(iEntityX - _iX, iEntityY) <= _iRadius )
        {
          bIsOwners = IEntity::OwnerId(iEntity) == _iPlayerId;
          iOwnerId = IEntity::OwnerId(iEntity);
          bIsEnemy = (iAllyBits & CAlliances::PlayerBit(iOwnerId)) == 0;
          bNotBowman = iEntityWarriorType != 8; // 1 << AI_WARRIOR_TYPE_BOWMAN = 8
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
      v8 = IEntity::WarMapNode(iEntity);
    }
  }
  iTotal = iSearchValues[1] + iSearchValues[0];
  a1->m_uOwnedBowmen = iSearchValues[0];
  a1->m_uOwnedSoldiers = iTotal;
  iTotal = iSearchValues[3] + iSearchValues[2];
  a1->m_uAllyBowmen = iSearchValues[2];
  a1->m_uAllySoldiers = iTotal;
  iTotal = iSearchValues[5] + iSearchValues[4];
  a1->m_uEnemyBowmen = iSearchValues[4];
  a1->m_uEnemySoldiers = iTotal;
}


// address=[0x15df900]
// Decompiled from struct SEvalFightersResult *__cdecl CScanner::EvaluateFighters(  struct SEvalFightersResult *a1,  unsigned int _iX,  unsigned int _iY,  int a4,  int a5)
void __cdecl CScanner::EvaluateFighters(struct SEvalFightersResult & a1, int _iX, int _iY, int a4, int a5) {
  
  const struct CVWList::SVW *v5; // eax
  char v6; // al
  CWarMapNode *v7; // eax
  struct SEvalFightersResult *result; // eax
  unsigned int v9; // [esp+8h] [ebp-154h]
  int iAllyMask; // [esp+Ch] [ebp-150h]
  int v11; // [esp+14h] [ebp-148h]
  int m_iV; // [esp+20h] [ebp-13Ch]
  int iAdjInflu; // [esp+28h] [ebp-134h]
  int iInfluValue; // [esp+2Ch] [ebp-130h]
  BOOL bIsOwn; // [esp+30h] [ebp-12Ch]
  BOOL bIsEnemy; // [esp+34h] [ebp-128h]
  int v17; // [esp+40h] [ebp-11Ch]
  int v18; // [esp+44h] [ebp-118h]
  int iSectorId; // [esp+48h] [ebp-114h]
  int j; // [esp+4Ch] [ebp-110h]
  int v21; // [esp+50h] [ebp-10Ch]
  unsigned int uIdx; // [esp+54h] [ebp-108h]
  int i; // [esp+58h] [ebp-104h]
  IEntity *v24; // [esp+5Ch] [ebp-100h]
  CVWList cVWList; // [esp+60h] [ebp-FCh] BYREF
  int iInfluences[3]; // [esp+140h] [ebp-1Ch] BYREF
  int iUnitCount[3]; // [esp+14Ch] [ebp-10h] BYREF

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 963, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a4 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 964, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( !CAlliances::IsValidUsedPlayerId(a5)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 965, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  iSectorId = CWorldManager::SectorId(_iX, _iY);
  if ( !iSectorId && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 969, "iSectorId != 0") == 1 )
    __debugbreak();
  CVWList::CVWList(&cVWList, _iX, _iY, a4);
  iAllyMask = CAlliances::PlayerAllyBits(a5);
  memset(iUnitCount, 0, sizeof(iUnitCount));
  memset(iInfluences, 0, sizeof(iInfluences));
  for ( i = 0; i < CVWList::Size(&cVWList); ++i )
  {
    m_iV = CVWList::operator[](&cVWList, i)->m_iV;
    v5 = CVWList::operator[](&cVWList, i);
    for ( j = CWarMap::FirstEntityIdVW(0, m_iV, v5->m_iW); j; j = CWarMapNode::Next(v7) )
    {
      v24 = CMapObjectMgr::Entity(j);
      if ( ((1 << IEntity::WarriorType(v24)) & 60) != 0 )
      {
        v17 = IEntity::X(v24);
        v18 = IEntity::Y(v24);
        v11 = CWorldManager::Index(v17, v18);
        if ( ITiling::SectorId(v11) == iSectorId )
        {
          v21 = Grid::DistanceInline(v17 - _iX, v18 - _iY);
          if ( v21 <= a4 )
          {
            bIsOwn = IEntity::OwnerId(v24) == a5;
            v6 = IEntity::OwnerId(v24);
            bIsEnemy = (iAllyMask & CAlliances::PlayerBit(v6)) == 0;
            if ( bIsOwn && bIsEnemy && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1011, "!(uIsOwn && uIsEnemy)") == 1 )
              __debugbreak();
            // 0 = ally
            // 1 = own
            // 2 = enemy
            uIdx = bIsOwn + 2 * bIsEnemy;
            if ( uIdx >= 3 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1015, "uIdx < 3") == 1 )
              __debugbreak();
            ++iUnitCount[uIdx];
            v9 = IEntity::Type(v24);
            iInfluValue = 16 * CWarMap::SettlerInfluValue(v9);
            if ( v21 > 12 )
              iAdjInflu = iInfluValue / v21;
            else
              iAdjInflu = iInfluValue;
            iInfluences[uIdx] += iAdjInflu;
          }
        }
      }
      v7 = IEntity::WarMapNode(v24);
    }
  }
  a1->m_iAlliedUnits = iUnitCount[0];
  a1->m_iOwnUnits = iUnitCount[1];
  a1->m_iEnemyUnits = iUnitCount[2];
  a1->m_iAllyValue = iInfluences[0];
  a1->m_iOwnValue = iInfluences[1];
  result = a1;
  a1->m_iEnemyValue = iInfluences[2];
  return result;
}


// address=[0x15dfdc0]
// Decompiled from void __cdecl CScanner::EvaluateTowers(  struct SEvalTowersResult *arg0,  unsigned int _iX,  unsigned int _iY,  int _iRadius,  int _iPlayerId)
void __cdecl CScanner::EvaluateTowers(struct SEvalTowersResult & arg0, int _iX, int _iY, int _iRadius, int _iPlayerId) {
  
  const struct CVWList::SVW *v5; // eax
  unsigned __int16 iBuildingXY; // ax
  int v7; // eax
  unsigned __int16 *v8; // eax
  CWarMapNode *rWarMapNode; // eax
  unsigned int v10; // [esp+4h] [ebp-1B0h]
  int iInhabitantCount; // [esp+8h] [ebp-1ACh]
  int iPlayerAllyBits; // [esp+10h] [ebp-1A4h]
  int iBuildingWorldIndex; // [esp+14h] [ebp-1A0h]
  int m_iV; // [esp+1Ch] [ebp-198h]
  int iOwner; // [esp+24h] [ebp-190h]
  BOOL bIsEnemy; // [esp+2Ch] [ebp-188h]
  void **pBuildingRole; // [esp+34h] [ebp-180h]
  int iBuildingType; // [esp+38h] [ebp-17Ch]
  T_AI_WARRIOR_TYPE v19; // [esp+40h] [ebp-174h]
  int iInfluence; // [esp+44h] [ebp-170h]
  int iStationedInfluence; // [esp+48h] [ebp-16Ch]
  char *rInhabitants; // [esp+50h] [ebp-164h]
  int iBuildingX; // [esp+58h] [ebp-15Ch]
  int iBuildingY; // [esp+5Ch] [ebp-158h]
  int iSectorId; // [esp+60h] [ebp-154h]
  IEntity *v26; // [esp+64h] [ebp-150h]
  int iStationedSwordmen; // [esp+68h] [ebp-14Ch]
  int iStationedBowmen; // [esp+6Ch] [ebp-148h]
  int iInlineDistance; // [esp+70h] [ebp-144h]
  IEntity *v30; // [esp+74h] [ebp-140h]
  int iTowerScore; // [esp+78h] [ebp-13Ch]
  int a1; // [esp+7Ch] [ebp-138h]
  int j; // [esp+80h] [ebp-134h]
  int iStationedScore; // [esp+84h] [ebp-130h]
  int i; // [esp+88h] [ebp-12Ch]
  IEntity *rBuildingEntity; // [esp+8Ch] [ebp-128h]
  unsigned int uIdx; // [esp+90h] [ebp-124h]
  CVWList cVWList; // [esp+94h] [ebp-120h] BYREF
  _DWORD aStationedSwordmen[3]; // [esp+174h] [ebp-40h] BYREF
  _DWORD aTowerCount[3]; // [esp+180h] [ebp-34h] BYREF
  _DWORD aTowerScores[3]; // [esp+18Ch] [ebp-28h] BYREF
  _DWORD aStationedScore[3]; // [esp+198h] [ebp-1Ch] BYREF
  _DWORD aStationedBowmen[3]; // [esp+1A4h] [ebp-10h] BYREF

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1049, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( _iRadius <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1050, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( !CAlliances::IsValidUsedPlayerId(_iPlayerId)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1051, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  iSectorId = CWorldManager::SectorId(_iX, _iY);
  if ( !iSectorId && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1055, "iSectorId != 0") == 1 )
    __debugbreak();
  CVWList::CVWList(&cVWList, _iX, _iY, _iRadius);
  iPlayerAllyBits = CAlliances::PlayerAllyBits(_iPlayerId);
  memset(aTowerCount, 0, sizeof(aTowerCount));
  memset(aTowerScores, 0, sizeof(aTowerScores));
  memset(aStationedSwordmen, 0, sizeof(aStationedSwordmen));
  memset(aStationedBowmen, 0, sizeof(aStationedBowmen));
  memset(aStationedScore, 0, sizeof(aStationedScore));
  for ( i = 0; i < CVWList::Size(&cVWList); ++i )
  {
    m_iV = CVWList::operator[](&cVWList, i)->m_iV;
    v5 = CVWList::operator[](&cVWList, i);
    for ( a1 = CWarMap::FirstEntityIdVW(2, m_iV, v5->m_iW); a1; a1 = CWarMapNode::Next(rWarMapNode) )
    {
      v26 = CMapObjectMgr::Entity(a1);
      if ( IEntity::WarriorType(v26) == AI_WARRIOR_TYPE_TOWER_BUILDING )
      {
        if ( IEntity::ObjType(v26) != BUILDING_OBJ
          && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1084, "rEntity.ObjType() == BUILDING_OBJ") == 1 )
        {
          __debugbreak();
        }
        rBuildingEntity = (IEntity *)CBuildingMgr::operator[](a1);
        iBuildingXY = CBuilding::EnsignPackedXY(rBuildingEntity);
        iBuildingX = Y16X16::UnpackXFast(iBuildingXY);
        v7 = CBuilding::EnsignPackedXY(rBuildingEntity);
        iBuildingY = Y16X16::UnpackYFast(v7);
        iBuildingWorldIndex = CWorldManager::Index(iBuildingX, iBuildingY);
        if ( ITiling::SectorId(iBuildingWorldIndex) == iSectorId )
        {
          iInlineDistance = Grid::DistanceInline(iBuildingX - _iX, iBuildingY - _iY);
          if ( iInlineDistance <= _iRadius )
          {
            iOwner = IEntity::OwnerId(rBuildingEntity);
            bIsEnemy = (iPlayerAllyBits & CAlliances::PlayerBit(iOwner)) == 0;
            if ( iOwner == _iPlayerId
              && bIsEnemy
              && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1105, "!(uIsOwn && uIsEnemy)") == 1 )
            {
              __debugbreak();
            }
            // 0 == Ally
            // 1 == Owner (Owner == PlayerId = 1)
            // 2 == Enemy
            uIdx = (iOwner == _iPlayerId) + 2 * bIsEnemy;
            if ( uIdx >= 3 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1109, "uIdx < 3") == 1 )
              __debugbreak();
            ++aTowerCount[uIdx];
            iTowerScore = 1;
            iBuildingType = IEntity::Type(rBuildingEntity);
            if ( iBuildingType == BUILDING_GUARDTOWERBIG )
            {
              iTowerScore = 2;
            }
            else if ( iBuildingType == BUILDING_CASTLE )
            {
              iTowerScore = 4;
            }
            aTowerScores[uIdx] += iTowerScore;
            if ( IEntity::FlagBits(rBuildingEntity, ENTITY_FLAG_Ready) )
            {
              pBuildingRole = (void **)CBuilding::Role(rBuildingEntity);
              if ( !j____RTDynamicCast(
                      pBuildingRole,
                      0,
                      &IBuildingRole__RTTI_Type_Descriptor_,
                      &CMilitaryBuildingRole__RTTI_Type_Descriptor_,
                      0)
                && BBSupportDbgReport(
                     2,
                     "Pathing\\Scanner.cpp",
                     1132,
                     "dynamic_cast<const CMilitaryBuildingRole*>(pBuildingRole) != 0") == 1 )
              {
                __debugbreak();
              }
              rInhabitants = CMilitaryBuildingRole::Inhabitants((char *)pBuildingRole);
              iInhabitantCount = std::vector<unsigned short>::size(rInhabitants);
              iStationedBowmen = 0;
              iStationedSwordmen = 0;
              iStationedScore = 0;
              for ( j = 0; j < iInhabitantCount; ++j )
              {
                v8 = std::vector<unsigned short>::operator[](j);
                if ( *v8 )
                {
                  v30 = CMapObjectMgr::Entity(*v8);
                  if ( IEntity::ObjType(v30) != SETTLER_OBJ
                    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1154, "rInhabitant.ObjType() == SETTLER_OBJ") == 1 )
                  {
                    __debugbreak();
                  }
                  v10 = IEntity::Type(v30);
                  v19 = IEntity::WarriorType(v30);
                  iStationedInfluence = 16 * CWarMap::SettlerInfluValue(v10);
                  if ( iInlineDistance > 12 )
                    iInfluence = iStationedInfluence / iInlineDistance;
                  else
                    iInfluence = iStationedInfluence;
                  if ( v19 == AI_WARRIOR_TYPE_BOWMAN )
                  {
                    ++iStationedBowmen;
                    iStationedScore += 2 * iInfluence;
                  }
                  else if ( v19 == AI_WARRIOR_TYPE_SWORDMAN )
                  {
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
      rWarMapNode = IEntity::WarMapNode(v26);
    }
  }
  arg0->m_iEnemyStationedBowmen = aStationedBowmen[2];
  arg0->m_iEnemyStationedSwordmen = aStationedSwordmen[2];
  arg0->m_iEnemyTowerCount = aTowerCount[2];
  arg0->m_iEnemyEvalScore = aStationedScore[2] + aTowerScores[2];
}


// address=[0x15e0530]
// Decompiled from bool __cdecl CScanner::FindNearestTowerInSector(  struct SFindNearestResult *arg0,  unsigned int iX,  unsigned int iY,  int _iRadius,  int a5)
bool __cdecl CScanner::FindNearestTowerInSector(struct SFindNearestResult & arg0, int iX, int iY, int _iRadius, int a5) {
  
  const struct CVWList::SVW *v5; // eax
  CWarMapNode *rWarMapNode; // eax
  char v8; // [esp+0h] [ebp-124h]
  int m_iV; // [esp+4h] [ebp-120h]
  int iDistance; // [esp+10h] [ebp-114h]
  int iBuildingX; // [esp+14h] [ebp-110h]
  int iBuildingY; // [esp+18h] [ebp-10Ch]
  int iSectorId; // [esp+1Ch] [ebp-108h]
  int iTowerSectorId; // [esp+20h] [ebp-104h]
  struct SFindNearestResult v15; // [esp+24h] [ebp-100h]
  int a1; // [esp+2Ch] [ebp-F8h]
  int i; // [esp+30h] [ebp-F4h]
  IEntity *v18; // [esp+34h] [ebp-F0h]
  bool v19; // [esp+3Ch] [ebp-E8h]
  CVWList cVWList; // [esp+40h] [ebp-E4h] BYREF

  v15.m_iNearestFoundId = 0;
  if ( !CWorldManager::InWorld(iX, iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1207, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( _iRadius <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1208, "_iRadius > 0") == 1 )
    __debugbreak();
  iSectorId = CWorldManager::SectorId(iX, iY);
  if ( !iSectorId && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1212, "iSectorId != 0") == 1 )
    __debugbreak();
  CVWList::CVWList(&cVWList, iX, iY, _iRadius);
  v15.m_iDistance = 0x4000;
  for ( i = 0; i < CVWList::Size(&cVWList); ++i )
  {
    m_iV = CVWList::operator[](&cVWList, i)->m_iV;
    v5 = CVWList::operator[](&cVWList, i);
    for ( a1 = CWarMap::FirstEntityIdVW(2, m_iV, v5->m_iW); a1; a1 = CWarMapNode::Next(rWarMapNode) )
    {
      v18 = (IEntity *)CBuildingMgr::operator[](a1);
      v19 = IEntity::FlagBits(v18, ENTITY_FLAG_Ready) != 0;
      if ( IEntity::WarriorType(v18) == AI_WARRIOR_TYPE_TOWER_BUILDING && v19 )
      {
        v8 = IEntity::OwnerId(v18);
        if ( (a5 & CAlliances::PlayerBit(v8)) != 0 )
        {
          iBuildingX = CBuilding::EnsignX(v18);
          iBuildingY = CBuilding::EnsignY(v18);
          iTowerSectorId = CWorldManager::SectorId(iBuildingX, iBuildingY);
          if ( !iTowerSectorId && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1244, "iTowerSectorId != 0") == 1 )
            __debugbreak();
          if ( iTowerSectorId == iSectorId )
          {
            iDistance = Grid::Distance(iBuildingX - iX, iBuildingY - iY);
            if ( iDistance < v15.m_iDistance )
              v15 = (struct SFindNearestResult)__PAIR64__(iDistance, a1);
          }
        }
      }
      rWarMapNode = IEntity::WarMapNode(v18);
    }
  }
  *arg0 = v15;
  return v15.m_iNearestFoundId > 0;
}


// address=[0x15e08a0]
// Decompiled from int __cdecl CScanner::FindNearestFighter(  unsigned int _iX,  unsigned int _iY,  int _iRadius,  int _iFighterSearchMask,  int _iOwnerBitMask)
int __cdecl CScanner::FindNearestFighter(int _iX, int _iY, int _iRadius, int _iFighterSearchMask, int _iOwnerBitMask) {
  
  const struct CVWList::SVW *v5; // eax
  char iOwnerId; // al
  int iEntityX; // eax
  CWarMapNode *v8; // eax
  int iEntityYDistance; // [esp-4h] [ebp-114h]
  int m_iV; // [esp+8h] [ebp-108h]
  int iEntityDistanceInline; // [esp+10h] [ebp-100h]
  int iFoundFighter; // [esp+14h] [ebp-FCh]
  int iSmallestDistance; // [esp+18h] [ebp-F8h]
  int j; // [esp+1Ch] [ebp-F4h]
  int iEntityXY; // [esp+20h] [ebp-F0h]
  IEntity *rEntity; // [esp+24h] [ebp-ECh]
  int i; // [esp+28h] [ebp-E8h]
  CVWList cVWList; // [esp+2Ch] [ebp-E4h] BYREF

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 489, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( _iRadius <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 490, "_iRadius > 0") == 1 )
    __debugbreak();
  CVWList::CVWList(&cVWList, _iX, _iY, _iRadius);
  iSmallestDistance = 0x4000;
  iFoundFighter = -1;
  for ( i = 0; i < CVWList::Size(&cVWList); ++i )
  {
    m_iV = CVWList::operator[](&cVWList, i)->m_iV;
    v5 = CVWList::operator[](&cVWList, i);
    for ( j = CWarMap::FirstEntityIdVW(0, m_iV, v5->m_iW); j; j = CWarMapNode::Next(v8) )
    {
      rEntity = CMapObjectMgr::Entity(j);
      if ( (_iFighterSearchMask & (1 << IEntity::WarriorType(rEntity))) != 0 )
      {
        iOwnerId = IEntity::OwnerId(rEntity);
        if ( (_iOwnerBitMask & CAlliances::PlayerBit(iOwnerId)) != 0 )
        {
          iEntityXY = IEntity::PackedXY(rEntity);
          iEntityYDistance = Y16X16::UnpackYFast(iEntityXY) - _iY;
          iEntityX = Y16X16::UnpackXFast(iEntityXY);
          iEntityDistanceInline = Grid::DistanceInline(iEntityX - _iX, iEntityYDistance);
          if ( iEntityDistanceInline < iSmallestDistance )
          {
            iSmallestDistance = iEntityDistanceInline;
            iFoundFighter = iEntityXY;
          }
        }
      }
      v8 = IEntity::WarMapNode(rEntity);
    }
  }
  if ( iSmallestDistance > _iRadius )
    return -1;
  return iFoundFighter;
}


// address=[0x15e0af0]
// Decompiled from int __cdecl CScanner::FindNearestAnimal(unsigned int _iX, unsigned int _iY, int a3, bool a4, int a5)
int __cdecl CScanner::FindNearestAnimal(int _iX, int _iY, int a3, bool a4, int a5) {
  
  const struct CVWList::SVW *v5; // eax
  int v6; // eax
  unsigned int v7; // eax
  int v8; // eax
  CWarMapNode *v9; // eax
  int v11; // [esp-4h] [ebp-10Ch]
  int v12; // [esp-4h] [ebp-10Ch]
  int m_iV; // [esp+0h] [ebp-108h]
  int v14; // [esp+8h] [ebp-100h]
  int v15; // [esp+Ch] [ebp-FCh]
  int v16; // [esp+10h] [ebp-F8h]
  int j; // [esp+14h] [ebp-F4h]
  IEntity *v18; // [esp+18h] [ebp-F0h]
  int v19; // [esp+1Ch] [ebp-ECh]
  int i; // [esp+20h] [ebp-E8h]
  CVWList v21; // [esp+24h] [ebp-E4h] BYREF

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 547, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 548, "_iRadius > 0") == 1 )
    __debugbreak();
  CVWList::CVWList(&v21, _iX, _iY, a3);
  v16 = 0x4000;
  v15 = -1;
  for ( i = 0; i < CVWList::Size(&v21); ++i )
  {
    m_iV = CVWList::operator[](&v21, i)->m_iV;
    v5 = CVWList::operator[](&v21, i);
    for ( j = CWarMap::FirstEntityIdVW(3, m_iV, v5->m_iW); j; j = CWarMapNode::Next(v9) )
    {
      v18 = CMapObjectMgr::Entity(j);
      v19 = IEntity::PackedXY(v18);
      v11 = Y16X16::UnpackYFast(v19);
      v6 = Y16X16::UnpackXFast(v19);
      if ( CWorldManager::EcoSectorId(v6, v11) == a5 )
      {
        if ( !a4 || (v7 = IEntity::Type(v18), CAnimalMgr::IsHuntable((CAnimalMgr *)&g_cAnimalMgr, v7)) )
        {
          v12 = Y16X16::UnpackYFast(v19) - _iY;
          v8 = Y16X16::UnpackXFast(v19);
          v14 = Grid::DistanceInline(v8 - _iX, v12);
          if ( v14 < v16 )
          {
            v16 = v14;
            v15 = v19;
          }
        }
      }
      v9 = IEntity::WarMapNode(v18);
    }
  }
  if ( v16 > a3 )
    return -1;
  return v15;
}


// address=[0x15e0d40]
// Decompiled from int __cdecl CScanner::FindNearestEnemyBowman(unsigned int a1, unsigned int a2, int a3, int a4)
int __cdecl CScanner::FindNearestEnemyBowman(int a1, int a2, int a3, int a4) {
  
  int v4; // eax

  v4 = CAlliances::PlayerEnemyBits(a4);
  return CScanner::FindNearestFighter(a1, a2, a3, 8, v4);// 1 << BOWMAN
}


// address=[0x15e0d70]
// Decompiled from int __cdecl CScanner::FindNearestEnemySwordsman(unsigned int a1, unsigned int a2, int a3, int a4)
int __cdecl CScanner::FindNearestEnemySwordsman(int a1, int a2, int a3, int a4) {
  
  int v4; // eax

  v4 = CAlliances::PlayerEnemyBits(a4);
  return CScanner::FindNearestFighter(a1, a2, a3, 4, v4);// 1 << SWORDMAN
}


// address=[0x15e0da0]
// Decompiled from int __cdecl CScanner::FindNearestEnemyFighter(unsigned int a1, unsigned int a2, int a3, int a4)
int __cdecl CScanner::FindNearestEnemyFighter(int a1, int a2, int a3, int a4) {
  
  int v4; // eax

  v4 = CAlliances::PlayerEnemyBits(a4);
  return CScanner::FindNearestFighter(a1, a2, a3, 60, v4);// Yes
}


// address=[0x15e0dd0]
// Decompiled from int __cdecl CScanner::FindNearestOwnFighter(unsigned int a1, unsigned int a2, int a3, char a4)
int __cdecl CScanner::FindNearestOwnFighter(int a1, int a2, int a3, int a4) {
  
  int v4; // eax

  v4 = CAlliances::PlayerBit(a4);
  return CScanner::FindNearestFighter(a1, a2, a3, 60, v4);
}


// address=[0x15e0e00]
// Decompiled from int __cdecl CScanner::FindNearestAllyFighter(unsigned int a1, unsigned int a2, int a3, int a4)
int __cdecl CScanner::FindNearestAllyFighter(int a1, int a2, int a3, int a4) {
  
  int v4; // eax

  v4 = CAlliances::PlayerAllyBits(a4);
  return CScanner::FindNearestFighter(a1, a2, a3, 60, v4);
}


// address=[0x15e0e30]
// Decompiled from int __cdecl CScanner::CountSettlers(  unsigned int _iX,  unsigned int _iY,  int _iRadius,  int *_pPlayerIds,  int *_pSettlerTypes,  int _iSectorId,  int _iLimit)
int __cdecl CScanner::CountSettlers(int _iX, int _iY, int _iRadius, int const * _pPlayerIds, int const * _pSettlerTypes, int _iSectorId, int _iLimit) {
  
  IEntity *v7; // eax
  CTile *v8; // eax
  IEntity *rEntity; // eax
  int v11; // [esp+4h] [ebp-28h]
  int v12; // [esp+8h] [ebp-24h]
  int v13; // [esp+10h] [ebp-1Ch]
  int v14; // [esp+14h] [ebp-18h]
  int v15; // [esp+18h] [ebp-14h]
  int *i; // [esp+1Ch] [ebp-10h]
  int *j; // [esp+20h] [ebp-Ch]
  int k; // [esp+24h] [ebp-8h]
  int iCount; // [esp+28h] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1277, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( _iRadius <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1278, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( _iSectorId < 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1279, "_iSectorId >= 0") == 1 )
    __debugbreak();
  if ( !_pPlayerIds && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1280, "_pPlayerIds != 0") == 1 )
    __debugbreak();
  if ( !_pSettlerTypes && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1281, "_pSettlerTypes != 0") == 1 )
    __debugbreak();
  if ( _iLimit <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1282, "_iLimit > 0") == 1 )
    __debugbreak();
  iCount = 0;
  for ( i = _pPlayerIds; *i; ++i )
  {
    for ( j = _pSettlerTypes; *j; ++j )
    {
      for ( k = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, *i, *j); k; k = IAnimatedEntity::Next(rEntity) )
      {
        v7 = CMapObjectMgr::Entity(k);
        v15 = IEntity::PackedXY(v7);
        v13 = Y16X16::UnpackXFast(v15);
        v14 = Y16X16::UnpackYFast(v15);
        if ( Grid::DistanceInline(v13 - _iX, v14 - _iY) <= _iRadius )
        {
          v12 = CWorldManager::Index(v13, v14);
          v11 = ITiling::NormalTileId(v12);
          v8 = ITiling::Tile(v11);
          if ( CTile::SectorId(v8) == _iSectorId && ++iCount >= _iLimit )
            return iCount;
        }
        rEntity = CMapObjectMgr::MovingEntity(k);
      }
    }
  }
  return iCount + 1;
}


// address=[0x15e1070]
// Decompiled from int __cdecl CScanner::IsNearMyLand(int _iPlayerId, unsigned int _iX, unsigned int _iY)
int __cdecl CScanner::IsNearMyLand(int _iPlayerId, int _iX, int _iY) {
  
  int v4; // eax
  int v5; // eax
  int y; // [esp+4h] [ebp-50h]
  int x; // [esp+8h] [ebp-4Ch]
  int v8; // [esp+14h] [ebp-40h]
  int v9; // [esp+24h] [ebp-30h]
  int v10; // [esp+28h] [ebp-2Ch]
  int v11; // [esp+2Ch] [ebp-28h]
  unsigned int iMapWidth; // [esp+30h] [ebp-24h]
  int k; // [esp+34h] [ebp-20h]
  int v14; // [esp+38h] [ebp-1Ch]
  unsigned int v15; // [esp+3Ch] [ebp-18h]
  int v16; // [esp+40h] [ebp-14h]
  int i; // [esp+44h] [ebp-10h]
  int j; // [esp+48h] [ebp-Ch]
  int v19; // [esp+50h] [ebp-4h]
  int v20; // [esp+50h] [ebp-4h]
  int v21; // [esp+50h] [ebp-4h]

  if ( !CAlliances::IsValidUsedPlayerId(_iPlayerId)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1339, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1340, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  iMapWidth = CWorldManager::Width();
  v8 = CWorldManager::Index(_iX, _iY);
  if ( ITiling::OwnerId(v8) == _iPlayerId )
    return 0;
  v9 = COwnerMap::OwnerBit(_iPlayerId);
  v10 = Squares::XYToVW(_iX);
  v11 = Squares::XYToVW(_iY);
  if ( (v9 & COwnerMap::OwnerBits9VW(v10, v11)) == 0 )
    return -1;
  if ( (v9 & COwnerMap::OwnerBits1VW(v10, v11)) == 0 && Grid::InQuadrat((_iX & 0xF) - 4, (_iY & 0xF) - 4, 8u) )
    return -1;
  if ( _iY - 4 < iMapWidth - 8 && _iX - 4 < iMapWidth - 8 )
  {
    for ( i = 0; i < 6; ++i )
    {
      v16 = CWorldManager::NeighborRelIndex(i);
      v19 = v16 + v16 + v8;
      if ( ITiling::OwnerId(v16 + v8) == _iPlayerId )
        return 1;
      v4 = ITiling::OwnerId(v19);
      v20 = v16 + v19;
      if ( v4 == _iPlayerId )
        return 1;
      v5 = ITiling::OwnerId(v20);
      v21 = v16 + v20;
      if ( v5 == _iPlayerId )
        return 1;
      if ( ITiling::OwnerId(v21) == _iPlayerId )
        return 1;
    }
  }
  else
  {
    for ( j = 0; j < 6; ++j )
    {
      x = g_sNeighborPoints[j].x;
      y = g_sNeighborPoints[j].y;
      v14 = _iX;
      v15 = _iY;
      for ( k = 0; k < 4; ++k )
      {
        v14 += x;
        v15 += y;
        if ( !Grid::InQuadrat(v14, v15, iMapWidth) )
          break;
        if ( ITiling::OwnerId(v14 + iMapWidth * v15) == _iPlayerId )
          return 1;
      }
    }
  }
  return -1;
}


// address=[0x15e13a0]
// Decompiled from char __cdecl CScanner::FindNearestPlayerLand(int a1, int *a2, int *a3)
bool __cdecl CScanner::FindNearestPlayerLand(int a1, int & a2, int & a3) {
  
  _DWORD v4[4]; // [esp+0h] [ebp-2Ch] BYREF
  int v5; // [esp+10h] [ebp-1Ch]
  int v6; // [esp+14h] [ebp-18h]
  int v7; // [esp+18h] [ebp-14h] BYREF
  int v8; // [esp+1Ch] [ebp-10h] BYREF
  int v9; // [esp+20h] [ebp-Ch]
  int v10; // [esp+24h] [ebp-8h]
  char v11; // [esp+2Bh] [ebp-1h]

  v11 = 0;
  v9 = CWorldManager::SectorId(*a2, *a3);
  if ( v9 <= 0 )
    return v11;
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v4, *a2, *a3, 50);
  while ( CSpiralWalk::NextXY(v4, &v8, &v7) )
  {
    v10 = CWorldManager::Index(v8, v7);
    v6 = ITiling::SectorId(v10);
    v5 = ITiling::OwnerId(v10);
    if ( v6 == v9 && v5 == a1 )
    {
      *a2 = v8;
      *a3 = v7;
      return 1;
    }
  }
  return v11;
}


// address=[0x15e1460]
// Decompiled from char __cdecl CScanner::FindAnyEnemyFighter(unsigned int _iX, unsigned int _iY, int _iRadius, int a4, int a5)
bool __cdecl CScanner::FindAnyEnemyFighter(int _iX, int _iY, int _iRadius, int a4, int a5) {
  
  char v6; // al
  int v7; // eax
  CWarMapNode *v8; // eax
  int v9; // [esp-4h] [ebp-114h]
  int v10; // [esp+8h] [ebp-108h]
  int v11; // [esp+10h] [ebp-100h]
  int m_iV; // [esp+14h] [ebp-FCh]
  int m_iW; // [esp+18h] [ebp-F8h]
  int v14; // [esp+1Ch] [ebp-F4h]
  int j; // [esp+20h] [ebp-F0h]
  IEntity *v16; // [esp+24h] [ebp-ECh]
  int i; // [esp+28h] [ebp-E8h]
  CVWList v18; // [esp+2Ch] [ebp-E4h] BYREF

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 603, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( _iRadius <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 604, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( !CAlliances::IsValidUsedPlayerId(a5)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 605, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  v14 = CAlliances::AllianceId(a5);
  v10 = CAlliances::PlayerEnemyBits(a5);
  if ( _iRadius <= 16 && !CInfluMap::EnemyValueXY(_iX, _iY, v14) )
    return 0;
  CVWList::CVWList(&v18, _iX, _iY, _iRadius);
  for ( i = 0; i < CVWList::Size(&v18); ++i )
  {
    m_iV = CVWList::operator[](&v18, i)->m_iV;
    m_iW = CVWList::operator[](&v18, i)->m_iW;
    if ( CInfluMap::EnemyValueVW(m_iV, m_iW, v14) >= 16 )
    {
      for ( j = CWarMap::FirstEntityIdVW(0, m_iV, m_iW); j; j = CWarMapNode::Next(v8) )
      {
        v16 = CMapObjectMgr::Entity(j);
        v6 = IEntity::OwnerId(v16);
        if ( (v10 & CAlliances::PlayerBit(v6)) != 0 && (a4 & (1 << IEntity::WarriorType(v16))) != 0 )
        {
          v11 = IEntity::PackedXY(v16);
          v9 = Y16X16::UnpackYFast(v11) - _iY;
          v7 = Y16X16::UnpackXFast(v11);
          if ( Grid::DistanceInline(v7 - _iX, v9) <= _iRadius )
            return 1;
        }
        v8 = IEntity::WarMapNode(v16);
      }
    }
  }
  return 0;
}


// address=[0x15e1710]
// Decompiled from char __cdecl CScanner::FindAnySettlerOrVehicle(unsigned int _iX, unsigned int _iY, int _iRadius, int _iPlayerId)
bool __cdecl CScanner::FindAnySettlerOrVehicle(int _iX, int _iY, int _iRadius, int _iPlayerId) {
  
  int v4; // eax
  CWarMapNode *v6; // eax
  int v7; // eax
  CWarMapNode *v8; // eax
  int v9; // [esp-4h] [ebp-114h]
  int v10; // [esp-4h] [ebp-114h]
  int v11; // [esp+8h] [ebp-108h]
  int m_iV; // [esp+Ch] [ebp-104h]
  int m_iW; // [esp+10h] [ebp-100h]
  int v14; // [esp+14h] [ebp-FCh]
  int k; // [esp+18h] [ebp-F8h]
  IEntity *v16; // [esp+1Ch] [ebp-F4h]
  int j; // [esp+20h] [ebp-F0h]
  IEntity *v18; // [esp+24h] [ebp-ECh]
  int i; // [esp+28h] [ebp-E8h]
  CVWList cVWList; // [esp+2Ch] [ebp-E4h] BYREF

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 666, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( _iRadius <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 667, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( !CAlliances::IsValidUsedPlayerId(_iPlayerId)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 668, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  CVWList::CVWList(&cVWList, _iX, _iY, _iRadius);
  for ( i = 0; i < CVWList::Size(&cVWList); ++i )
  {
    m_iV = CVWList::operator[](&cVWList, i)->m_iV;
    m_iW = CVWList::operator[](&cVWList, i)->m_iW;
    for ( j = CWarMap::FirstEntityIdVW(0, m_iV, m_iW); j; j = CWarMapNode::Next(v6) )
    {
      v18 = CMapObjectMgr::Entity(j);
      if ( IEntity::OwnerId(v18) == _iPlayerId )
      {
        v14 = IEntity::PackedXY(v18);
        v9 = Y16X16::UnpackYFast(v14) - _iY;
        v4 = Y16X16::UnpackXFast(v14);
        if ( Grid::DistanceInline(v4 - _iX, v9) <= _iRadius )
          return 1;
      }
      v6 = IEntity::WarMapNode(v18);
    }
    for ( k = CWarMap::FirstEntityIdVW(1, m_iV, m_iW); k; k = CWarMapNode::Next(v8) )
    {
      v16 = CMapObjectMgr::Entity(k);
      if ( IEntity::OwnerId(v16) == _iPlayerId )
      {
        v11 = IEntity::PackedXY(v16);
        v10 = Y16X16::UnpackYFast(v11) - _iY;
        v7 = Y16X16::UnpackXFast(v11);
        if ( Grid::DistanceInline(v7 - _iX, v10) <= _iRadius )
          return 1;
      }
      v8 = IEntity::WarMapNode(v16);
    }
  }
  return 0;
}


// address=[0x15e19d0]
// Decompiled from char __cdecl CScanner::IsAreaCompletelyOwned(unsigned int _iX, unsigned int _iY, int _iRadius, int _iPlayerId)
bool __cdecl CScanner::IsAreaCompletelyOwned(int _iX, int _iY, int _iRadius, int _iPlayerId) {
  
  _DWORD v5[4]; // [esp+0h] [ebp-34h] BYREF
  int v6; // [esp+10h] [ebp-24h]
  int v7; // [esp+14h] [ebp-20h] BYREF
  int v8; // [esp+18h] [ebp-1Ch] BYREF
  BOOL v9; // [esp+1Ch] [ebp-18h]
  BOOL v10; // [esp+20h] [ebp-14h]
  int v11; // [esp+24h] [ebp-10h]
  BOOL v12; // [esp+28h] [ebp-Ch]
  BOOL v13; // [esp+2Ch] [ebp-8h]
  bool IsWater; // [esp+33h] [ebp-1h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1448, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v13 = _iRadius >= 0;
  v12 = _iRadius < 75;
  if ( (!v12 || !v13)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1449, "(_iRadius >= 0) & (_iRadius < SPIRAL_RADIUS_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( !CAlliances::IsValidUsedPlayerId(_iPlayerId)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1450, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v5, _iX, _iY, _iRadius);
  while ( CSpiralWalk::NextXY(v5, &v7, &v8) )
  {
    v11 = CWorldManager::Index(v7, v8);
    IsWater = CWorldManager::IsWater(v11);
    v6 = ITiling::OwnerId(v11);
    v10 = !IsWater;
    v9 = v6 != _iPlayerId;
    if ( v9 && v10 )
      return 0;
  }
  return 1;
}


// address=[0x15e1b40]
// Decompiled from char __cdecl CScanner::IsAreaCompletelyGreen(unsigned int _iX, unsigned int _iY, int _iRadius)
bool __cdecl CScanner::IsAreaCompletelyGreen(int _iX, int _iY, int _iRadius) {
  
  _DWORD v4[4]; // [esp+0h] [ebp-24h] BYREF
  int v5; // [esp+10h] [ebp-14h]
  int v6; // [esp+14h] [ebp-10h] BYREF
  int v7; // [esp+18h] [ebp-Ch] BYREF
  BOOL v8; // [esp+1Ch] [ebp-8h]
  BOOL v9; // [esp+20h] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1479, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v9 = _iRadius >= 0;
  v8 = _iRadius < 75;
  if ( (!v8 || !v9)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1480, "(_iRadius >= 0) & (_iRadius < SPIRAL_RADIUS_MAX)") == 1 )
  {
    __debugbreak();
  }
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v4, _iX, _iY, _iRadius);
  while ( CSpiralWalk::NextXY(v4, &v6, &v7) )
  {
    v5 = CWorldManager::Index(v6, v7);
    if ( CWorldManager::FlagBits(v5, 4u) )
      return 0;
  }
  return 1;
}


// address=[0x15e1c30]
// Decompiled from char __cdecl CScanner::IsAreaCompletelyDarkLand(unsigned int _iX, unsigned int _iY, int _iRadius)
bool __cdecl CScanner::IsAreaCompletelyDarkLand(int _iX, int _iY, int _iRadius) {
  
  _DWORD v4[4]; // [esp+0h] [ebp-24h] BYREF
  int v5; // [esp+10h] [ebp-14h]
  int v6; // [esp+14h] [ebp-10h] BYREF
  int v7; // [esp+18h] [ebp-Ch] BYREF
  BOOL v8; // [esp+1Ch] [ebp-8h]
  BOOL v9; // [esp+20h] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1507, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v9 = _iRadius >= 0;
  v8 = _iRadius < 75;
  if ( (!v8 || !v9)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1508, "(_iRadius >= 0) & (_iRadius < SPIRAL_RADIUS_MAX)") == 1 )
  {
    __debugbreak();
  }
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v4, _iX, _iY, _iRadius);
  while ( CSpiralWalk::NextXY(v4, &v6, &v7) )
  {
    v5 = CWorldManager::Index(v6, v7);
    if ( !CWorldManager::FlagBits(v5, 4u) )
      return 0;
  }
  return 1;
}


#endif // Already implemented
