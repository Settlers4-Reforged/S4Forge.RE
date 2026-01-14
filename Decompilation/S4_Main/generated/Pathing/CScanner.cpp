#include "all_headers.h"

// Definitions for class CScanner

// address=[0x1301390]
// Decompiled from bool __cdecl CScanner::FindNearestEnemyTowerInSector(struct SFindNearestResult *a1, int a2, int a3, int a4, int a5)
static bool __cdecl CScanner::FindNearestEnemyTowerInSector(struct SFindNearestResult &,int,int,int,int) {
  
  int v6; // [esp+0h] [ebp-4h]

  if ( !CAlliances::IsValidUsedPlayerId(a5)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Pathing\\Scanner.h",
         377,
         "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  v6 = CAlliances::PlayerEnemyBits(a5);
  return CScanner::FindNearestTowerInSector(a1, a2, a3, a4, v6);
}


// address=[0x13065f0]
// Decompiled from int __cdecl CScanner::FindNearestOwnTowerInSector(int a1, int a2, int a3, int a4)
static int __cdecl CScanner::FindNearestOwnTowerInSector(int,int,int,int) {
  
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int v6; // [esp+8h] [ebp-4h]

  if ( !CAlliances::IsValidUsedPlayerId(a4)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Pathing\\Scanner.h",
         391,
         "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  v6 = CAlliances::PlayerBit(a4);
  CScanner::FindNearestTowerInSector((struct SFindNearestResult *)&v5, a1, a2, a3, v6);
  return v5;
}


// address=[0x15df090]
// Decompiled from char __cdecl CScanner::CheckIfAEnemyUnitMayBeInRange(int a1, int a2, int a3, int a4)
static bool __cdecl CScanner::CheckIfAEnemyUnitMayBeInRange(int,int,int,int) {
  
  int v4; // eax
  int v6; // [esp+0h] [ebp-F4h]
  int v7; // [esp+8h] [ebp-ECh]
  int i; // [esp+Ch] [ebp-E8h]
  _BYTE v9[224]; // [esp+10h] [ebp-E4h] BYREF

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 461, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 462, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( !CAlliances::IsValidUsedPlayerId(a4)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 463, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  v7 = CAlliances::AllianceId(a4);
  CVWList::CVWList((CVWList *)v9, a1, a2, a3);
  for ( i = 0; i < CVWList::Size((CVWList *)v9); ++i )
  {
    v6 = *(_DWORD *)CVWList::operator[](i);
    v4 = CVWList::operator[](i);
    if ( (int)CInfluMap::EnemyValueVW(v6, *(_DWORD *)(v4 + 4), v7) > 0 )
      return 1;
  }
  return 0;
}


// address=[0x15df200]
// Decompiled from int __cdecl CScanner::CountCiviliansAndFindNearestInSector(int a1, int a2, int a3, int a4, int *a5)
static int __cdecl CScanner::CountCiviliansAndFindNearestInSector(int,int,int,int,int *) {
  
  int v5; // eax
  int v6; // eax
  int v7; // eax
  struct CPtrList *v8; // eax
  int v10; // [esp-4h] [ebp-11Ch]
  int v11; // [esp+4h] [ebp-114h]
  int v12; // [esp+8h] [ebp-110h]
  int v13; // [esp+Ch] [ebp-10Ch]
  int v14; // [esp+14h] [ebp-104h]
  int v15; // [esp+18h] [ebp-100h]
  int v16; // [esp+1Ch] [ebp-FCh]
  int v17; // [esp+20h] [ebp-F8h]
  int j; // [esp+24h] [ebp-F4h]
  int v19; // [esp+28h] [ebp-F0h]
  int i; // [esp+2Ch] [ebp-ECh]
  unsigned __int8 *v21; // [esp+30h] [ebp-E8h]
  _BYTE v22[224]; // [esp+34h] [ebp-E4h] BYREF

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 817, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 818, "_iRadius > 0") == 1 )
    __debugbreak();
  v19 = 0;
  v16 = CWorldManager::SectorId(a1, a2);
  v17 = -1;
  v14 = 0x4000;
  if ( v16 > 0 )
  {
    CVWList::CVWList((CVWList *)v22, a1, a2, a3);
    for ( i = 0; i < CVWList::Size((CVWList *)v22); ++i )
    {
      v13 = *(_DWORD *)CVWList::operator[](i);
      v5 = CVWList::operator[](i);
      for ( j = CWarMap::FirstEntityIdVW(0, v13, *(_DWORD *)(v5 + 4)); j; j = CWarMapNode::Next(v8) )
      {
        v21 = (unsigned __int8 *)CMapObjectMgr::Entity(j);
        if ( !IEntity::WarriorType()
          && (char *)IEntity::FlagBits(v21, (EntityFlag)&byte_20000CA[54]) == &byte_20000CA[54] )
        {
          v6 = IEntity::OwnerId(v21);
          if ( (a4 & CAlliances::PlayerBit(v6)) != 0 )
          {
            v11 = IEntity::X(v21);
            v12 = IEntity::Y(v21);
            if ( CWorldManager::SectorId(v11, v12) == v16 )
            {
              ++v19;
              v10 = IEntity::Y(v21) - a2;
              v7 = IEntity::X(v21);
              v15 = Grid::Distance((Grid *)(v7 - a1), v10);
              if ( v15 < v14 )
              {
                v14 = v15;
                v17 = IEntity::PackedXY(v21);
              }
            }
          }
        }
        v8 = IEntity::WarMapNode((CPropertySet *)v21);
      }
    }
  }
  if ( a5 )
    *a5 = v17;
  if ( v19 && v17 < 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 880, "(iResult == 0) || (iNearestXY >= 0)") == 1 )
    __debugbreak();
  return v19;
}


// address=[0x15df4f0]
// Decompiled from int __cdecl CScanner::CountFighters(struct SCountFightersResult *a1, int a2, int a3, int a4, int a5)
static void __cdecl CScanner::CountFighters(struct SCountFightersResult &,int,int,int,int) {
  
  int v5; // eax
  int v6; // eax
  int v7; // eax
  struct CPtrList *v8; // eax
  int result; // eax
  int v10; // [esp-4h] [ebp-158h]
  int v11; // [esp+4h] [ebp-150h]
  int v12; // [esp+Ch] [ebp-148h]
  int v13; // [esp+14h] [ebp-140h]
  int v14; // [esp+1Ch] [ebp-138h]
  int v15; // [esp+20h] [ebp-134h]
  int v16; // [esp+28h] [ebp-12Ch]
  BOOL v17; // [esp+30h] [ebp-124h]
  BOOL v18; // [esp+34h] [ebp-120h]
  int v19; // [esp+38h] [ebp-11Ch]
  int v20; // [esp+44h] [ebp-110h]
  int j; // [esp+48h] [ebp-10Ch]
  unsigned __int8 *v22; // [esp+50h] [ebp-104h]
  int i; // [esp+54h] [ebp-100h]
  _BYTE v24[224]; // [esp+58h] [ebp-FCh] BYREF
  int v25; // [esp+138h] [ebp-1Ch]
  int v26; // [esp+13Ch] [ebp-18h]
  int v27; // [esp+140h] [ebp-14h]
  int v28; // [esp+144h] [ebp-10h]
  int v29; // [esp+148h] [ebp-Ch]
  int v30; // [esp+14Ch] [ebp-8h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 892, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a4 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 893, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( !CAlliances::IsValidUsedPlayerId(a5)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 894, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  CVWList::CVWList((CVWList *)v24, a2, a3, a4);
  v15 = CAlliances::PlayerAllyBits(a5);
  v25 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  for ( i = 0; i < CVWList::Size((CVWList *)v24); ++i )
  {
    v16 = *(_DWORD *)CVWList::operator[](i);
    v5 = CVWList::operator[](i);
    for ( j = CWarMap::FirstEntityIdVW(0, v16, *(_DWORD *)(v5 + 4)); j; j = CWarMapNode::Next(v8) )
    {
      v22 = (unsigned __int8 *)CMapObjectMgr::Entity(j);
      v19 = 1 << IEntity::WarriorType();
      if ( (v19 & 0x3C) != 0 )
      {
        v20 = IEntity::PackedXY(v22);
        v10 = Y16X16::UnpackYFast(v20) - a3;
        v6 = Y16X16::UnpackXFast(v20);
        if ( Grid::DistanceInline((Grid *)(v6 - a2), v10) <= a4 )
        {
          v14 = IEntity::OwnerId(v22) == a5;
          v7 = IEntity::OwnerId(v22);
          v17 = (v15 & CAlliances::PlayerBit(v7)) == 0;
          v18 = v19 != 8;
          *(&v25 + v18) += v14;
          ++*(&v25 + 2 * v17 + v18 + 2);
        }
      }
      v8 = IEntity::WarMapNode((CPropertySet *)v22);
    }
  }
  v13 = v26 + v25;
  *(_DWORD *)a1 = v25;
  *((_DWORD *)a1 + 1) = v13;
  v12 = v28 + v27;
  *((_DWORD *)a1 + 2) = v27;
  *((_DWORD *)a1 + 3) = v12;
  v11 = v30 + v29;
  *((_DWORD *)a1 + 4) = v29;
  result = v11;
  *((_DWORD *)a1 + 5) = v11;
  return result;
}


// address=[0x15df900]
// Decompiled from struct SEvalFightersResult *__cdecl CScanner::EvaluateFighters(  struct SEvalFightersResult *a1,  int a2,  int a3,  int a4,  int a5)
static void __cdecl CScanner::EvaluateFighters(struct SEvalFightersResult &,int,int,int,int) {
  
  int v5; // eax
  int v6; // eax
  struct CPtrList *v7; // eax
  struct SEvalFightersResult *result; // eax
  int v9; // [esp+8h] [ebp-154h]
  int v10; // [esp+Ch] [ebp-150h]
  int v11; // [esp+14h] [ebp-148h]
  int v12; // [esp+20h] [ebp-13Ch]
  int v13; // [esp+28h] [ebp-134h]
  int v14; // [esp+2Ch] [ebp-130h]
  BOOL v15; // [esp+30h] [ebp-12Ch]
  BOOL v16; // [esp+34h] [ebp-128h]
  int v17; // [esp+40h] [ebp-11Ch]
  int v18; // [esp+44h] [ebp-118h]
  int v19; // [esp+48h] [ebp-114h]
  int j; // [esp+4Ch] [ebp-110h]
  int v21; // [esp+50h] [ebp-10Ch]
  unsigned int v22; // [esp+54h] [ebp-108h]
  int i; // [esp+58h] [ebp-104h]
  CPropertySet *v24; // [esp+5Ch] [ebp-100h]
  _BYTE v25[224]; // [esp+60h] [ebp-FCh] BYREF
  int v26; // [esp+140h] [ebp-1Ch]
  int v27; // [esp+144h] [ebp-18h]
  int v28; // [esp+148h] [ebp-14h]
  int v29; // [esp+14Ch] [ebp-10h]
  int v30; // [esp+150h] [ebp-Ch]
  int v31; // [esp+154h] [ebp-8h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
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
  v19 = CWorldManager::SectorId(a2, a3);
  if ( !v19 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 969, "iSectorId != 0") == 1 )
    __debugbreak();
  CVWList::CVWList((CVWList *)v25, a2, a3, a4);
  v10 = CAlliances::PlayerAllyBits(a5);
  v29 = 0;
  v30 = 0;
  v31 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  for ( i = 0; i < CVWList::Size((CVWList *)v25); ++i )
  {
    v12 = *(_DWORD *)CVWList::operator[](i);
    v5 = CVWList::operator[](i);
    for ( j = CWarMap::FirstEntityIdVW(0, v12, *(_DWORD *)(v5 + 4)); j; j = CWarMapNode::Next(v7) )
    {
      v24 = (CPropertySet *)CMapObjectMgr::Entity(j);
      if ( ((1 << IEntity::WarriorType()) & 0x3C) != 0 )
      {
        v17 = IEntity::X(v24);
        v18 = IEntity::Y(v24);
        v11 = CWorldManager::Index(v17, v18);
        if ( ITiling::SectorId(v11) == v19 )
        {
          v21 = Grid::DistanceInline((Grid *)(v17 - a2), v18 - a3);
          if ( v21 <= a4 )
          {
            v15 = IEntity::OwnerId((unsigned __int8 *)v24) == a5;
            v6 = IEntity::OwnerId((unsigned __int8 *)v24);
            v16 = (v10 & CAlliances::PlayerBit(v6)) == 0;
            if ( v15 && v16 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1011, "!(uIsOwn && uIsEnemy)") == 1 )
              __debugbreak();
            v22 = v15 + 2 * v16;
            if ( v22 >= 3 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1015, "uIdx < 3") == 1 )
              __debugbreak();
            ++*(&v29 + v22);
            v9 = IEntity::Type((unsigned __int16 *)v24);
            v14 = 16 * CWarMap::SettlerInfluValue(v9);
            if ( v21 > 12 )
              v13 = v14 / v21;
            else
              v13 = v14;
            *(&v26 + v22) += v13;
          }
        }
      }
      v7 = IEntity::WarMapNode(v24);
    }
  }
  *((_DWORD *)a1 + 1) = v29;
  *(_DWORD *)a1 = v30;
  *((_DWORD *)a1 + 2) = v31;
  *((_DWORD *)a1 + 4) = v26;
  *((_DWORD *)a1 + 3) = v27;
  result = a1;
  *((_DWORD *)a1 + 5) = v28;
  return result;
}


// address=[0x15dfdc0]
// Decompiled from int __cdecl CScanner::EvaluateTowers(struct SEvalTowersResult *a1, int a2, int a3, int a4, int a5)
static void __cdecl CScanner::EvaluateTowers(struct SEvalTowersResult &,int,int,int,int) {
  
  int v5; // eax
  int v6; // eax
  _WORD *v7; // eax
  struct CPtrList *v8; // eax
  int result; // eax
  int v10; // [esp+0h] [ebp-1B4h]
  int v11; // [esp+4h] [ebp-1B0h]
  int v12; // [esp+8h] [ebp-1ACh]
  int v13; // [esp+10h] [ebp-1A4h]
  int v14; // [esp+14h] [ebp-1A0h]
  int v15; // [esp+1Ch] [ebp-198h]
  int v16; // [esp+20h] [ebp-194h]
  int v17; // [esp+24h] [ebp-190h]
  BOOL v18; // [esp+2Ch] [ebp-188h]
  void **v19; // [esp+34h] [ebp-180h]
  int v20; // [esp+38h] [ebp-17Ch]
  int v21; // [esp+40h] [ebp-174h]
  int v22; // [esp+44h] [ebp-170h]
  int v23; // [esp+48h] [ebp-16Ch]
  int v24; // [esp+50h] [ebp-164h]
  int v25; // [esp+58h] [ebp-15Ch]
  int v26; // [esp+5Ch] [ebp-158h]
  int v27; // [esp+60h] [ebp-154h]
  unsigned __int8 *v28; // [esp+64h] [ebp-150h]
  int v29; // [esp+68h] [ebp-14Ch]
  int v30; // [esp+6Ch] [ebp-148h]
  int v31; // [esp+70h] [ebp-144h]
  unsigned __int8 *v32; // [esp+74h] [ebp-140h]
  int v33; // [esp+78h] [ebp-13Ch]
  int j; // [esp+7Ch] [ebp-138h]
  int k; // [esp+80h] [ebp-134h]
  int v36; // [esp+84h] [ebp-130h]
  int i; // [esp+88h] [ebp-12Ch]
  unsigned __int8 *v38; // [esp+8Ch] [ebp-128h]
  unsigned int v39; // [esp+90h] [ebp-124h]
  _BYTE v40[224]; // [esp+94h] [ebp-120h] BYREF
  _DWORD v41[2]; // [esp+174h] [ebp-40h]
  int v42; // [esp+17Ch] [ebp-38h]
  _DWORD v43[2]; // [esp+180h] [ebp-34h]
  int v44; // [esp+188h] [ebp-2Ch]
  _DWORD v45[2]; // [esp+18Ch] [ebp-28h]
  int v46; // [esp+194h] [ebp-20h]
  _DWORD v47[2]; // [esp+198h] [ebp-1Ch]
  int v48; // [esp+1A0h] [ebp-14h]
  _DWORD v49[2]; // [esp+1A4h] [ebp-10h]
  int v50; // [esp+1ACh] [ebp-8h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1049, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a4 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1050, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( !CAlliances::IsValidUsedPlayerId(a5)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1051, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  v27 = CWorldManager::SectorId(a2, a3);
  if ( !v27 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1055, "iSectorId != 0") == 1 )
    __debugbreak();
  CVWList::CVWList((CVWList *)v40, a2, a3, a4);
  v13 = CAlliances::PlayerAllyBits(a5);
  v43[0] = 0;
  v43[1] = 0;
  v44 = 0;
  v45[0] = 0;
  v45[1] = 0;
  v46 = 0;
  v41[0] = 0;
  v41[1] = 0;
  v42 = 0;
  v49[0] = 0;
  v49[1] = 0;
  v50 = 0;
  v47[0] = 0;
  v47[1] = 0;
  v48 = 0;
  for ( i = 0; i < CVWList::Size((CVWList *)v40); ++i )
  {
    v15 = *(_DWORD *)CVWList::operator[](i);
    v16 = *(_DWORD *)(CVWList::operator[](i) + 4);
    for ( j = CWarMap::FirstEntityIdVW(2, v15, v16); j; j = CWarMapNode::Next(v8) )
    {
      v28 = (unsigned __int8 *)CMapObjectMgr::Entity(j);
      if ( IEntity::WarriorType() == 12 )
      {
        if ( IEntity::ObjType(v28) != 8
          && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1084, "rEntity.ObjType() == BUILDING_OBJ") == 1 )
        {
          __debugbreak();
        }
        v38 = (unsigned __int8 *)CBuildingMgr::operator[](j);
        v5 = CBuilding::EnsignPackedXY(v38);
        v25 = Y16X16::UnpackXFast(v5);
        v6 = CBuilding::EnsignPackedXY(v38);
        v26 = Y16X16::UnpackYFast(v6);
        v14 = CWorldManager::Index(v25, v26);
        v10 = ITiling::SectorId(v14);
        if ( v10 == v27 )
        {
          v31 = Grid::DistanceInline((Grid *)(v25 - a2), v26 - a3);
          if ( v31 <= a4 )
          {
            v17 = IEntity::OwnerId(v38);
            v18 = (v13 & CAlliances::PlayerBit(v17)) == 0;
            if ( v17 == a5 && v18 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1105, "!(uIsOwn && uIsEnemy)") == 1 )
              __debugbreak();
            v39 = (v17 == a5) + 2 * v18;
            if ( v39 >= 3 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1109, "uIdx < 3") == 1 )
              __debugbreak();
            ++v43[v39];
            v33 = 1;
            v20 = IEntity::Type((unsigned __int16 *)v38);
            if ( v20 == 47 )
            {
              v33 = 2;
            }
            else if ( v20 == 48 )
            {
              v33 = 4;
            }
            v45[v39] += v33;
            if ( IEntity::FlagBits(v38, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
            {
              v19 = (void **)CBuilding::Role(v38);
              if ( !j____RTDynamicCast(
                      v19,
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
              v24 = CMilitaryBuildingRole::Inhabitants(v19, v10);
              v12 = std::vector<unsigned short>::size(v24);
              v30 = 0;
              v29 = 0;
              v36 = 0;
              for ( k = 0; k < v12; ++k )
              {
                v7 = (_WORD *)std::vector<unsigned short>::operator[](k);
                if ( *v7 )
                {
                  v32 = (unsigned __int8 *)CMapObjectMgr::Entity((unsigned __int16)*v7);
                  if ( IEntity::ObjType(v32) != 1
                    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1154, "rInhabitant.ObjType() == SETTLER_OBJ") == 1 )
                  {
                    __debugbreak();
                  }
                  v11 = IEntity::Type((unsigned __int16 *)v32);
                  v21 = IEntity::WarriorType();
                  v23 = 16 * CWarMap::SettlerInfluValue(v11);
                  if ( v31 > 12 )
                    v22 = v23 / v31;
                  else
                    v22 = v23;
                  if ( v21 == 3 )
                  {
                    ++v30;
                    v36 += 2 * v22;
                  }
                  else if ( v21 == 2 )
                  {
                    ++v29;
                    v36 += v22;
                  }
                }
              }
              v49[v39] += v30;
              v41[v39] += v29;
              v47[v39] += v36;
            }
          }
        }
      }
      v8 = IEntity::WarMapNode((CPropertySet *)v28);
    }
  }
  *((_DWORD *)a1 + 2) = v50;
  *((_DWORD *)a1 + 1) = v42;
  *(_DWORD *)a1 = v44;
  result = 8;
  *((_DWORD *)a1 + 3) = v48 + v46;
  return result;
}


// address=[0x15e0530]
// Decompiled from bool __cdecl CScanner::FindNearestTowerInSector(struct SFindNearestResult *a1, int a2, int a3, int a4, int a5)
static bool __cdecl CScanner::FindNearestTowerInSector(struct SFindNearestResult &,int,int,int,int) {
  
  int v5; // eax
  struct CPtrList *v6; // eax
  int v8; // [esp+0h] [ebp-124h]
  int v9; // [esp+4h] [ebp-120h]
  int v10; // [esp+10h] [ebp-114h]
  int v11; // [esp+14h] [ebp-110h]
  int v12; // [esp+18h] [ebp-10Ch]
  int v13; // [esp+1Ch] [ebp-108h]
  int v14; // [esp+20h] [ebp-104h]
  int v15; // [esp+24h] [ebp-100h]
  int v16; // [esp+28h] [ebp-FCh]
  int j; // [esp+2Ch] [ebp-F8h]
  int i; // [esp+30h] [ebp-F4h]
  CPropertySet *v19; // [esp+34h] [ebp-F0h]
  bool v20; // [esp+3Ch] [ebp-E8h]
  _BYTE v21[224]; // [esp+40h] [ebp-E4h] BYREF

  v15 = 0;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1207, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a4 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1208, "_iRadius > 0") == 1 )
    __debugbreak();
  v13 = CWorldManager::SectorId(a2, a3);
  if ( !v13 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1212, "iSectorId != 0") == 1 )
    __debugbreak();
  CVWList::CVWList((CVWList *)v21, a2, a3, a4);
  v16 = 0x4000;
  for ( i = 0; i < CVWList::Size((CVWList *)v21); ++i )
  {
    v9 = *(_DWORD *)CVWList::operator[](i);
    v5 = CVWList::operator[](i);
    for ( j = CWarMap::FirstEntityIdVW(2, v9, *(_DWORD *)(v5 + 4)); j; j = CWarMapNode::Next(v6) )
    {
      v19 = (CPropertySet *)CBuildingMgr::operator[](j);
      v20 = IEntity::FlagBits(v19, (EntityFlag)((char *)&loc_1FFFFFF + 1)) != 0;
      if ( IEntity::WarriorType() == 12 && v20 )
      {
        v8 = IEntity::OwnerId((unsigned __int8 *)v19);
        if ( (a5 & CAlliances::PlayerBit(v8)) != 0 )
        {
          v11 = CBuilding::EnsignX(v19);
          v12 = CBuilding::EnsignY(v19);
          v14 = CWorldManager::SectorId(v11, v12);
          if ( !v14 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1244, "iTowerSectorId != 0") == 1 )
            __debugbreak();
          if ( v14 == v13 )
          {
            v10 = Grid::Distance((Grid *)(v11 - a2), v12 - a3);
            if ( v10 < v16 )
            {
              v16 = v10;
              v15 = j;
            }
          }
        }
      }
      v6 = IEntity::WarMapNode(v19);
    }
  }
  *(_DWORD *)a1 = v15;
  *((_DWORD *)a1 + 1) = v16;
  return v15 > 0;
}


// address=[0x15e08a0]
// Decompiled from int __cdecl CScanner::FindNearestFighter(int a1, int a2, int a3, int a4, int a5)
static int __cdecl CScanner::FindNearestFighter(int,int,int,int,int) {
  
  int v5; // eax
  int v6; // eax
  int v7; // eax
  struct CPtrList *v8; // eax
  int v10; // [esp-4h] [ebp-114h]
  int v11; // [esp+8h] [ebp-108h]
  int v12; // [esp+10h] [ebp-100h]
  int v13; // [esp+14h] [ebp-FCh]
  int v14; // [esp+18h] [ebp-F8h]
  int j; // [esp+1Ch] [ebp-F4h]
  int v16; // [esp+20h] [ebp-F0h]
  unsigned __int8 *v17; // [esp+24h] [ebp-ECh]
  int i; // [esp+28h] [ebp-E8h]
  _BYTE v19[224]; // [esp+2Ch] [ebp-E4h] BYREF

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 489, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 490, "_iRadius > 0") == 1 )
    __debugbreak();
  CVWList::CVWList((CVWList *)v19, a1, a2, a3);
  v14 = 0x4000;
  v13 = -1;
  for ( i = 0; i < CVWList::Size((CVWList *)v19); ++i )
  {
    v11 = *(_DWORD *)CVWList::operator[](i);
    v5 = CVWList::operator[](i);
    for ( j = CWarMap::FirstEntityIdVW(0, v11, *(_DWORD *)(v5 + 4)); j; j = CWarMapNode::Next(v8) )
    {
      v17 = (unsigned __int8 *)CMapObjectMgr::Entity(j);
      if ( (a4 & (1 << IEntity::WarriorType())) != 0 )
      {
        v6 = IEntity::OwnerId(v17);
        if ( (a5 & CAlliances::PlayerBit(v6)) != 0 )
        {
          v16 = IEntity::PackedXY(v17);
          v10 = Y16X16::UnpackYFast(v16) - a2;
          v7 = Y16X16::UnpackXFast(v16);
          v12 = Grid::DistanceInline((Grid *)(v7 - a1), v10);
          if ( v12 < v14 )
          {
            v14 = v12;
            v13 = v16;
          }
        }
      }
      v8 = IEntity::WarMapNode((CPropertySet *)v17);
    }
  }
  if ( v14 > a3 )
    return -1;
  return v13;
}


// address=[0x15e0af0]
// Decompiled from int __cdecl CScanner::FindNearestAnimal(int a1, int a2, int a3, bool a4, int a5)
static int __cdecl CScanner::FindNearestAnimal(int,int,int,bool,int) {
  
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  struct CPtrList *v9; // eax
  int v11; // [esp-4h] [ebp-10Ch]
  int v12; // [esp-4h] [ebp-10Ch]
  int v13; // [esp+0h] [ebp-108h]
  int v14; // [esp+8h] [ebp-100h]
  int v15; // [esp+Ch] [ebp-FCh]
  int v16; // [esp+10h] [ebp-F8h]
  int j; // [esp+14h] [ebp-F4h]
  unsigned __int16 *v18; // [esp+18h] [ebp-F0h]
  int v19; // [esp+1Ch] [ebp-ECh]
  int i; // [esp+20h] [ebp-E8h]
  _BYTE v21[224]; // [esp+24h] [ebp-E4h] BYREF

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 547, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 548, "_iRadius > 0") == 1 )
    __debugbreak();
  CVWList::CVWList((CVWList *)v21, a1, a2, a3);
  v16 = 0x4000;
  v15 = -1;
  for ( i = 0; i < CVWList::Size((CVWList *)v21); ++i )
  {
    v13 = *(_DWORD *)CVWList::operator[](i);
    v5 = CVWList::operator[](i);
    for ( j = CWarMap::FirstEntityIdVW(3, v13, *(_DWORD *)(v5 + 4)); j; j = CWarMapNode::Next(v9) )
    {
      v18 = (unsigned __int16 *)CMapObjectMgr::Entity(j);
      v19 = IEntity::PackedXY(v18);
      v11 = Y16X16::UnpackYFast(v19);
      v6 = Y16X16::UnpackXFast(v19);
      if ( CWorldManager::EcoSectorId(v6, v11) == a5 )
      {
        if ( !a4 || (v7 = IEntity::Type(v18), CAnimalMgr::IsHuntable((CAnimalMgr *)&g_cAnimalMgr, v7)) )
        {
          v12 = Y16X16::UnpackYFast(v19) - a2;
          v8 = Y16X16::UnpackXFast(v19);
          v14 = Grid::DistanceInline((Grid *)(v8 - a1), v12);
          if ( v14 < v16 )
          {
            v16 = v14;
            v15 = v19;
          }
        }
      }
      v9 = IEntity::WarMapNode((CPropertySet *)v18);
    }
  }
  if ( v16 > a3 )
    return -1;
  return v15;
}


// address=[0x15e0d40]
// Decompiled from int __cdecl CScanner::FindNearestEnemyBowman(int a1, int a2, int a3, int a4)
static int __cdecl CScanner::FindNearestEnemyBowman(int,int,int,int) {
  
  int v4; // eax

  v4 = CAlliances::PlayerEnemyBits(a4);
  return CScanner::FindNearestFighter(a1, a2, a3, 8, v4);
}


// address=[0x15e0d70]
// Decompiled from int __cdecl CScanner::FindNearestEnemySwordsman(int a1, int a2, int a3, int a4)
static int __cdecl CScanner::FindNearestEnemySwordsman(int,int,int,int) {
  
  int v4; // eax

  v4 = CAlliances::PlayerEnemyBits(a4);
  return CScanner::FindNearestFighter(a1, a2, a3, 4, v4);
}


// address=[0x15e0da0]
// Decompiled from int __cdecl CScanner::FindNearestEnemyFighter(int a1, int a2, int a3, int a4)
static int __cdecl CScanner::FindNearestEnemyFighter(int,int,int,int) {
  
  int v4; // eax

  v4 = CAlliances::PlayerEnemyBits(a4);
  return CScanner::FindNearestFighter(a1, a2, a3, 60, v4);
}


// address=[0x15e0dd0]
// Decompiled from int __cdecl CScanner::FindNearestOwnFighter(int a1, int a2, int a3, int a4)
static int __cdecl CScanner::FindNearestOwnFighter(int,int,int,int) {
  
  int v4; // eax

  v4 = CAlliances::PlayerBit(a4);
  return CScanner::FindNearestFighter(a1, a2, a3, 60, v4);
}


// address=[0x15e0e00]
// Decompiled from int __cdecl CScanner::FindNearestAllyFighter(int a1, int a2, int a3, int a4)
static int __cdecl CScanner::FindNearestAllyFighter(int,int,int,int) {
  
  int v4; // eax

  v4 = CAlliances::PlayerAllyBits(a4);
  return CScanner::FindNearestFighter(a1, a2, a3, 60, v4);
}


// address=[0x15e0e30]
// Decompiled from int __cdecl CScanner::CountSettlers(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5, int a6, int a7)
static int __cdecl CScanner::CountSettlers(int,int,int,int const *,int const *,int,int) {
  
  struct IEntity *v7; // eax
  CTile *v8; // eax
  void **v10; // eax
  int v11; // [esp+4h] [ebp-28h]
  int v12; // [esp+8h] [ebp-24h]
  int v13; // [esp+10h] [ebp-1Ch]
  int v14; // [esp+14h] [ebp-18h]
  int v15; // [esp+18h] [ebp-14h]
  _DWORD *i; // [esp+1Ch] [ebp-10h]
  _DWORD *j; // [esp+20h] [ebp-Ch]
  int k; // [esp+24h] [ebp-8h]
  int v19; // [esp+28h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1277, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1278, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( a6 < 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1279, "_iSectorId >= 0") == 1 )
    __debugbreak();
  if ( !a4 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1280, "_pPlayerIds != 0") == 1 )
    __debugbreak();
  if ( !a5 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1281, "_pSettlerTypes != 0") == 1 )
    __debugbreak();
  if ( a7 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1282, "_iLimit > 0") == 1 )
    __debugbreak();
  v19 = 0;
  for ( i = a4; *i; ++i )
  {
    for ( j = a5; *j; ++j )
    {
      for ( k = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, *i, *j); k; k = IAnimatedEntity::Next(v10) )
      {
        v7 = CMapObjectMgr::Entity(k);
        v15 = IEntity::PackedXY(v7);
        v13 = Y16X16::UnpackXFast(v15);
        v14 = Y16X16::UnpackYFast(v15);
        if ( Grid::DistanceInline((Grid *)(v13 - a1), v14 - a2) <= a3 )
        {
          v12 = CWorldManager::Index(v13, v14);
          v11 = ITiling::NormalTileId(v12);
          v8 = (CTile *)ITiling::Tile(v11);
          if ( CTile::SectorId(v8) == a6 && ++v19 >= a7 )
            return v19;
        }
        v10 = CMapObjectMgr::MovingEntity(k);
      }
    }
  }
  return v19 + 1;
}


// address=[0x15e1070]
// Decompiled from int __cdecl CScanner::IsNearMyLand(int a1, int a2, int a3)
static int __cdecl CScanner::IsNearMyLand(int,int,int) {
  
  int v3; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // [esp+4h] [ebp-50h]
  int v8; // [esp+8h] [ebp-4Ch]
  int v9; // [esp+14h] [ebp-40h]
  int v10; // [esp+24h] [ebp-30h]
  int v11; // [esp+28h] [ebp-2Ch]
  int v12; // [esp+2Ch] [ebp-28h]
  int v13; // [esp+30h] [ebp-24h]
  int k; // [esp+34h] [ebp-20h]
  Grid *v15; // [esp+38h] [ebp-1Ch]
  int v16; // [esp+3Ch] [ebp-18h]
  int v17; // [esp+40h] [ebp-14h]
  int i; // [esp+44h] [ebp-10h]
  int j; // [esp+48h] [ebp-Ch]
  int v20; // [esp+50h] [ebp-4h]
  int v21; // [esp+50h] [ebp-4h]
  int v22; // [esp+50h] [ebp-4h]

  if ( !CAlliances::IsValidUsedPlayerId(a1)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1339, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1340, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v13 = CWorldManager::Width(v3);
  v9 = CWorldManager::Index(a2, a3);
  if ( ITiling::OwnerId(v9) == a1 )
    return 0;
  v10 = COwnerMap::OwnerBit(a1);
  v11 = Squares::XYToVW((Squares *)a2);
  v12 = Squares::XYToVW((Squares *)a3);
  if ( (v10 & COwnerMap::OwnerBits9VW(v11, v12)) == 0 )
    return -1;
  if ( (v10 & COwnerMap::OwnerBits1VW(v11, v12)) == 0 && Grid::InQuadrat((Grid *)((a2 & 0xF) - 4), (a3 & 0xF) - 4, 8) )
    return -1;
  if ( a3 - 4 < (unsigned int)(v13 - 8) && a2 - 4 < (unsigned int)(v13 - 8) )
  {
    for ( i = 0; i < 6; ++i )
    {
      v17 = CWorldManager::NeighborRelIndex(i);
      v20 = v17 + v17 + v9;
      if ( ITiling::OwnerId(v17 + v9) == a1 )
        return 1;
      v5 = ITiling::OwnerId(v20);
      v21 = v17 + v20;
      if ( v5 == a1 )
        return 1;
      v6 = ITiling::OwnerId(v21);
      v22 = v17 + v21;
      if ( v6 == a1 )
        return 1;
      if ( ITiling::OwnerId(v22) == a1 )
        return 1;
    }
  }
  else
  {
    for ( j = 0; j < 6; ++j )
    {
      v8 = g_sNeighborPoints[2 * j];
      v7 = dword_37D8C0C[2 * j];
      v15 = (Grid *)a2;
      v16 = a3;
      for ( k = 0; k < 4; ++k )
      {
        v15 = (Grid *)((char *)v15 + v8);
        v16 += v7;
        if ( !Grid::InQuadrat(v15, v16, v13) )
          break;
        if ( ITiling::OwnerId((char *)v15 + v13 * v16) == a1 )
          return 1;
      }
    }
  }
  return -1;
}


// address=[0x15e13a0]
// Decompiled from char __cdecl CScanner::FindNearestPlayerLand(int a1, int *a2, int *a3)
static bool __cdecl CScanner::FindNearestPlayerLand(int,int &,int &) {
  
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
// Decompiled from char __cdecl CScanner::FindAnyEnemyFighter(int a1, int a2, int a3, int a4, int a5)
static bool __cdecl CScanner::FindAnyEnemyFighter(int,int,int,int,int) {
  
  int v6; // eax
  int v7; // eax
  struct CPtrList *v8; // eax
  int v9; // [esp-4h] [ebp-114h]
  int v10; // [esp+8h] [ebp-108h]
  int v11; // [esp+10h] [ebp-100h]
  int v12; // [esp+14h] [ebp-FCh]
  int v13; // [esp+18h] [ebp-F8h]
  int v14; // [esp+1Ch] [ebp-F4h]
  int j; // [esp+20h] [ebp-F0h]
  unsigned __int8 *v16; // [esp+24h] [ebp-ECh]
  int i; // [esp+28h] [ebp-E8h]
  _BYTE v18[224]; // [esp+2Ch] [ebp-E4h] BYREF

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 603, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 604, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( !CAlliances::IsValidUsedPlayerId(a5)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 605, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  v14 = CAlliances::AllianceId(a5);
  v10 = CAlliances::PlayerEnemyBits(a5);
  if ( a3 <= 16 && !CInfluMap::EnemyValueXY(a1, a2, v14) )
    return 0;
  CVWList::CVWList((CVWList *)v18, a1, a2, a3);
  for ( i = 0; i < CVWList::Size((CVWList *)v18); ++i )
  {
    v12 = *(_DWORD *)CVWList::operator[](i);
    v13 = *(_DWORD *)(CVWList::operator[](i) + 4);
    if ( (int)CInfluMap::EnemyValueVW(v12, v13, v14) >= 16 )
    {
      for ( j = CWarMap::FirstEntityIdVW(0, v12, v13); j; j = CWarMapNode::Next(v8) )
      {
        v16 = (unsigned __int8 *)CMapObjectMgr::Entity(j);
        v6 = IEntity::OwnerId(v16);
        if ( (v10 & CAlliances::PlayerBit(v6)) != 0 && (a4 & (1 << IEntity::WarriorType())) != 0 )
        {
          v11 = IEntity::PackedXY(v16);
          v9 = Y16X16::UnpackYFast(v11) - a2;
          v7 = Y16X16::UnpackXFast(v11);
          if ( Grid::DistanceInline((Grid *)(v7 - a1), v9) <= a3 )
            return 1;
        }
        v8 = IEntity::WarMapNode((CPropertySet *)v16);
      }
    }
  }
  return 0;
}


// address=[0x15e1710]
// Decompiled from char __cdecl CScanner::FindAnySettlerOrVehicle(int a1, int a2, int a3, int a4)
static bool __cdecl CScanner::FindAnySettlerOrVehicle(int,int,int,int) {
  
  int v4; // eax
  struct CPtrList *v6; // eax
  int v7; // eax
  struct CPtrList *v8; // eax
  int v9; // [esp-4h] [ebp-114h]
  int v10; // [esp-4h] [ebp-114h]
  int v11; // [esp+8h] [ebp-108h]
  int v12; // [esp+Ch] [ebp-104h]
  int v13; // [esp+10h] [ebp-100h]
  int v14; // [esp+14h] [ebp-FCh]
  int k; // [esp+18h] [ebp-F8h]
  unsigned __int8 *v16; // [esp+1Ch] [ebp-F4h]
  int j; // [esp+20h] [ebp-F0h]
  unsigned __int8 *v18; // [esp+24h] [ebp-ECh]
  int i; // [esp+28h] [ebp-E8h]
  _BYTE v20[224]; // [esp+2Ch] [ebp-E4h] BYREF

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 666, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 667, "_iRadius > 0") == 1 )
    __debugbreak();
  if ( !CAlliances::IsValidUsedPlayerId(a4)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 668, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  CVWList::CVWList((CVWList *)v20, a1, a2, a3);
  for ( i = 0; i < CVWList::Size((CVWList *)v20); ++i )
  {
    v12 = *(_DWORD *)CVWList::operator[](i);
    v13 = *(_DWORD *)(CVWList::operator[](i) + 4);
    for ( j = CWarMap::FirstEntityIdVW(0, v12, v13); j; j = CWarMapNode::Next(v6) )
    {
      v18 = (unsigned __int8 *)CMapObjectMgr::Entity(j);
      if ( IEntity::OwnerId(v18) == a4 )
      {
        v14 = IEntity::PackedXY(v18);
        v9 = Y16X16::UnpackYFast(v14) - a2;
        v4 = Y16X16::UnpackXFast(v14);
        if ( Grid::DistanceInline((Grid *)(v4 - a1), v9) <= a3 )
          return 1;
      }
      v6 = IEntity::WarMapNode((CPropertySet *)v18);
    }
    for ( k = CWarMap::FirstEntityIdVW(1, v12, v13); k; k = CWarMapNode::Next(v8) )
    {
      v16 = (unsigned __int8 *)CMapObjectMgr::Entity(k);
      if ( IEntity::OwnerId(v16) == a4 )
      {
        v11 = IEntity::PackedXY(v16);
        v10 = Y16X16::UnpackYFast(v11) - a2;
        v7 = Y16X16::UnpackXFast(v11);
        if ( Grid::DistanceInline((Grid *)(v7 - a1), v10) <= a3 )
          return 1;
      }
      v8 = IEntity::WarMapNode((CPropertySet *)v16);
    }
  }
  return 0;
}


// address=[0x15e19d0]
// Decompiled from char __cdecl CScanner::IsAreaCompletelyOwned(int a1, int a2, int a3, int a4)
static bool __cdecl CScanner::IsAreaCompletelyOwned(int,int,int,int) {
  
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

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1448, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v13 = a3 >= 0;
  v12 = a3 < 75;
  if ( (!v12 || !v13)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1449, "(_iRadius >= 0) & (_iRadius < SPIRAL_RADIUS_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( !CAlliances::IsValidUsedPlayerId(a4)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1450, "g_cAlliances.IsValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v5, a1, a2, a3);
  while ( CSpiralWalk::NextXY(v5, &v7, &v8) )
  {
    v11 = CWorldManager::Index(v7, v8);
    IsWater = CWorldManager::IsWater(v11);
    v6 = ITiling::OwnerId(v11);
    v10 = !IsWater;
    v9 = v6 != a4;
    if ( v9 && v10 )
      return 0;
  }
  return 1;
}


// address=[0x15e1b40]
// Decompiled from char __cdecl CScanner::IsAreaCompletelyGreen(int a1, int a2, int a3)
static bool __cdecl CScanner::IsAreaCompletelyGreen(int,int,int) {
  
  _DWORD v4[4]; // [esp+0h] [ebp-24h] BYREF
  int v5; // [esp+10h] [ebp-14h]
  int v6; // [esp+14h] [ebp-10h] BYREF
  int v7; // [esp+18h] [ebp-Ch] BYREF
  BOOL v8; // [esp+1Ch] [ebp-8h]
  BOOL v9; // [esp+20h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1479, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v9 = a3 >= 0;
  v8 = a3 < 75;
  if ( (!v8 || !v9)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1480, "(_iRadius >= 0) & (_iRadius < SPIRAL_RADIUS_MAX)") == 1 )
  {
    __debugbreak();
  }
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v4, a1, a2, a3);
  while ( CSpiralWalk::NextXY(v4, &v6, &v7) )
  {
    v5 = CWorldManager::Index(v6, v7);
    if ( CWorldManager::FlagBits(v5, 4u) )
      return 0;
  }
  return 1;
}


// address=[0x15e1c30]
// Decompiled from char __cdecl CScanner::IsAreaCompletelyDarkLand(int a1, int a2, int a3)
static bool __cdecl CScanner::IsAreaCompletelyDarkLand(int,int,int) {
  
  _DWORD v4[4]; // [esp+0h] [ebp-24h] BYREF
  int v5; // [esp+10h] [ebp-14h]
  int v6; // [esp+14h] [ebp-10h] BYREF
  int v7; // [esp+18h] [ebp-Ch] BYREF
  BOOL v8; // [esp+1Ch] [ebp-8h]
  BOOL v9; // [esp+20h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1507, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v9 = a3 >= 0;
  v8 = a3 < 75;
  if ( (!v8 || !v9)
    && BBSupportDbgReport(2, "Pathing\\Scanner.cpp", 1508, "(_iRadius >= 0) & (_iRadius < SPIRAL_RADIUS_MAX)") == 1 )
  {
    __debugbreak();
  }
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v4, a1, a2, a3);
  while ( CSpiralWalk::NextXY(v4, &v6, &v7) )
  {
    v5 = CWorldManager::Index(v6, v7);
    if ( !CWorldManager::FlagBits(v5, 4u) )
      return 0;
  }
  return 1;
}


