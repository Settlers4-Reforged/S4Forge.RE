#include "all_headers.h"

// Definitions for class CSearchRoutines

// address=[0x15191f0]
// Decompiled from char *__cdecl CSearchRoutines::GetSearchData(int a1)
static struct SSearchData const & __cdecl CSearchRoutines::GetSearchData(int) {
  
  if ( a1 <= 0 || a1 >= 27 )
    return (char *)&g_sSearchData;
  else
    return (char *)&g_sSearchData + 16 * a1;
}


// address=[0x1519220]
// Decompiled from int CSearchRoutines::SearchNoSearch()
static int __cdecl CSearchRoutines::SearchNoSearch(int,int,int) {
  
  return 0;
}


// address=[0x1519230]
// Decompiled from int __cdecl CSearchRoutines::SearchTree(int a1, int a2)
static int __cdecl CSearchRoutines::SearchTree(int,int,int) {
  
  bool IsStaticInstance; // al
  int v4; // eax
  int FreeSlot; // [esp+8h] [ebp-20h]
  CTree *v6; // [esp+10h] [ebp-18h]
  int v7; // [esp+14h] [ebp-14h]
  IDecoObject *v8; // [esp+18h] [ebp-10h]

  if ( CWorldManager::FlagBits(a1, a2, 0x24u) )
    return 0;
  if ( CWorldManager::ResourceType(a1, a2) != 112 )
    return 0;
  v7 = CWorldManager::ObjectId(a1, a2);
  if ( !v7 )
    return 0;
  v8 = (IDecoObject *)CMapObjectMgr::EntityPtr(v7);
  IsStaticInstance = IDecoObject::IsStaticInstance(v8);
  if ( !IsStaticInstance )
  {
    v4 = IEntity::Type((unsigned __int16 *)v8);
    BBSupportTracePrintF(
      0,
      "CSearchRoutines::SearchTree(): Tree %u, X: %u, Y: %u, Type: %u was already dynamic instance!",
      v7,
      a1,
      a2,
      v4);
    return 0;
  }
  FreeSlot = CMapObjectMgr::GetFreeSlot(IsStaticInstance);
  v6 = (CTree *)CTree::operator new(0x50u);
  if ( v6 )
    CTree::CTree(v6, v8, FreeSlot, a1, a2);
  return FreeSlot;
}


// address=[0x1519360]
// Decompiled from int __cdecl CSearchRoutines::SearchTreeSeedPos(int a1, int a2, char a3)
static int __cdecl CSearchRoutines::SearchTreeSeedPos(int,int,int) {
  
  int v4; // [esp+4h] [ebp-24h]
  int v5; // [esp+14h] [ebp-14h]
  int v6; // [esp+18h] [ebp-10h]
  int v7; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  v6 = CWorldManager::Index(a1, a2);
  if ( CWorldManager::MapObjectId(v6) )
    return 0;
  if ( (a3 & 0xF) != 0 )
    v7 = ((unsigned int)CGameData::Rand(g_pGameData) & 3) == 0;
  else
    v7 = dword_378D7E0[(unsigned int)CGameData::Rand(g_pGameData) & 7];
  if ( !CDecoObjMgr::IsAddDecoObjOk((CDecoObjMgr *)&g_cDecoObjMgr, a1, a2, 1, 0, v7) )
    return 0;
  for ( i = 0; i < 7; ++i )
  {
    v4 = v6 + CWorldManager::SurroundingHexPointRelIndex(i);
    v5 = CWorldManager::Ground(v4);
    if ( (v5 & 0xF0) != 0x10 )
      return 0;
    if ( v5 == 29 )
      return 0;
  }
  return -1;
}


// address=[0x1519480]
// Decompiled from int __cdecl CSearchRoutines::SearchTreeSeedPosMaya(int a1, int a2, char a3)
static int __cdecl CSearchRoutines::SearchTreeSeedPosMaya(int,int,int) {
  
  int v4; // [esp+0h] [ebp-28h]
  int v5; // [esp+10h] [ebp-18h]
  int v6; // [esp+14h] [ebp-14h]
  int v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  v7 = CWorldManager::Index(a1, a2);
  if ( CWorldManager::MapObjectId(v7) )
    return 0;
  if ( (a3 & 0xF) != 0 )
    v8 = ((unsigned int)CGameData::Rand(g_pGameData) & 3) == 0;
  else
    v8 = dword_378D7E0[(unsigned int)CGameData::Rand(g_pGameData) & 7];
  if ( !CDecoObjMgr::IsAddDecoObjOk((CDecoObjMgr *)&g_cDecoObjMgr, a1, a2, 1, 0, v8) )
    return 0;
  for ( i = 0; i < 7; ++i )
  {
    v4 = v7 + CWorldManager::SurroundingHexPointRelIndex(i);
    v5 = CWorldManager::Ground(v4);
    v6 = v5 & 0xF0;
    if ( v6 != 16 && v6 != 64 )
      return 0;
    if ( v5 == 29 )
      return 0;
  }
  return -1;
}


// address=[0x15195a0]
// Decompiled from int __cdecl CSearchRoutines::SearchAgave(int a1, int a2)
static int __cdecl CSearchRoutines::SearchAgave(int,int,int) {
  
  bool IsStaticInstance; // al
  CPlant *v4; // [esp+Ch] [ebp-1Ch]
  IDecoObject *v5; // [esp+10h] [ebp-18h]
  unsigned __int8 *v6; // [esp+14h] [ebp-14h]
  int v7; // [esp+18h] [ebp-10h]
  int FreeSlot; // [esp+18h] [ebp-10h]

  v7 = CWorldManager::ObjectId(a1, a2);
  if ( !v7 )
    return 0;
  v6 = (unsigned __int8 *)CMapObjectMgr::Entity(v7);
  if ( IEntity::ObjType(v6) != 32 )
    return 0;
  if ( IEntity::Type((unsigned __int16 *)v6) != 211 )
    return 0;
  if ( !IEntity::FlagBits(v6, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    return 0;
  v5 = (IDecoObject *)CMapObjectMgr::EntityPtr(v7);
  IsStaticInstance = IDecoObject::IsStaticInstance(v5);
  if ( !IsStaticInstance )
    return 0;
  FreeSlot = CMapObjectMgr::GetFreeSlot(IsStaticInstance);
  v4 = (CPlant *)CPlant::operator new(0x50u);
  if ( v4 )
    CPlant::CPlant(v4, v5, FreeSlot, a1, a2);
  return FreeSlot;
}


// address=[0x15196b0]
// Decompiled from int __cdecl CSearchRoutines::SearchAgaveSeedPos(int a1, int a2)
static int __cdecl CSearchRoutines::SearchAgaveSeedPos(int,int,int) {
  
  int v3; // [esp+8h] [ebp-14h]
  int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+14h] [ebp-8h]
  int v6; // [esp+18h] [ebp-4h]
  int v7; // [esp+18h] [ebp-4h]

  v6 = CWorldManager::Index(a1, a2);
  if ( (CWorldManager::Ground(v6) & 0xF0) != 0x40 )
    return 0;
  if ( (int)CSearchRoutines::CalcRawness(v6) > 7 )
    return 0;
  v5 = 0;
  if ( CWorldManager::Ground(v6) == 29 )
    return 0;
  while ( v5 < 7 )
  {
    v3 = a1 + CSpiralOffsets::DeltaX(v5);
    v4 = a2 + CSpiralOffsets::DeltaY(v5);
    v7 = CWorldManager::Index(v3, v4);
    if ( CWorldManager::FlagBits(v7, 0x7Fu) )
      return 0;
    ++v5;
  }
  return -1;
}


// address=[0x15197a0]
// Decompiled from int __cdecl CSearchRoutines::SearchSunflower(int a1, int a2)
static int __cdecl CSearchRoutines::SearchSunflower(int,int,int) {
  
  bool IsStaticInstance; // al
  CPlant *v4; // [esp+Ch] [ebp-1Ch]
  IDecoObject *v5; // [esp+10h] [ebp-18h]
  unsigned __int8 *v6; // [esp+14h] [ebp-14h]
  int v7; // [esp+18h] [ebp-10h]
  int FreeSlot; // [esp+18h] [ebp-10h]

  v7 = CWorldManager::ObjectId(a1, a2);
  if ( !v7 )
    return 0;
  v6 = (unsigned __int8 *)CMapObjectMgr::Entity(v7);
  if ( IEntity::ObjType(v6) != 32 )
    return 0;
  if ( IEntity::Type((unsigned __int16 *)v6) != 255 )
    return 0;
  if ( !IEntity::FlagBits(v6, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    return 0;
  v5 = (IDecoObject *)CMapObjectMgr::EntityPtr(v7);
  IsStaticInstance = IDecoObject::IsStaticInstance(v5);
  if ( !IsStaticInstance )
    return 0;
  FreeSlot = CMapObjectMgr::GetFreeSlot(IsStaticInstance);
  v4 = (CPlant *)CPlant::operator new(0x50u);
  if ( v4 )
    CPlant::CPlant(v4, v5, FreeSlot, a1, a2);
  return FreeSlot;
}


// address=[0x15198b0]
// Decompiled from int __cdecl CSearchRoutines::SearchSunflowerSeedPos(int a1, int a2)
static int __cdecl CSearchRoutines::SearchSunflowerSeedPos(int,int,int) {
  
  int v3; // [esp+8h] [ebp-14h]
  int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+14h] [ebp-8h]
  int v6; // [esp+18h] [ebp-4h]
  int v7; // [esp+18h] [ebp-4h]

  v6 = CWorldManager::Index(a1, a2);
  if ( (CWorldManager::Ground(v6) & 0xF0) != 0x10 )
    return 0;
  if ( (int)CSearchRoutines::CalcRawness(v6) > 7 )
    return 0;
  v5 = 0;
  if ( CWorldManager::Ground(v6) == 29 )
    return 0;
  while ( v5 < 7 )
  {
    v3 = a1 + CSpiralOffsets::DeltaX(v5);
    v4 = a2 + CSpiralOffsets::DeltaY(v5);
    v7 = CWorldManager::Index(v3, v4);
    if ( CWorldManager::FlagBits(v7, 0x7Fu) )
      return 0;
    ++v5;
  }
  return -1;
}


// address=[0x15199a0]
// Decompiled from int __cdecl CSearchRoutines::SearchVine(int a1, int a2)
static int __cdecl CSearchRoutines::SearchVine(int,int,int) {
  
  bool IsStaticInstance; // al
  CPlant *v4; // [esp+Ch] [ebp-1Ch]
  IDecoObject *v5; // [esp+10h] [ebp-18h]
  unsigned __int8 *v6; // [esp+14h] [ebp-14h]
  int v7; // [esp+18h] [ebp-10h]
  int FreeSlot; // [esp+18h] [ebp-10h]

  v7 = CWorldManager::ObjectId(a1, a2);
  if ( !v7 )
    return 0;
  v6 = (unsigned __int8 *)CMapObjectMgr::Entity(v7);
  if ( IEntity::ObjType(v6) != 32 )
    return 0;
  if ( IEntity::Type((unsigned __int16 *)v6) != 162 )
    return 0;
  if ( !IEntity::FlagBits(v6, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    return 0;
  v5 = (IDecoObject *)CMapObjectMgr::EntityPtr(v7);
  IsStaticInstance = IDecoObject::IsStaticInstance(v5);
  if ( !IsStaticInstance )
    return 0;
  FreeSlot = CMapObjectMgr::GetFreeSlot(IsStaticInstance);
  v4 = (CPlant *)CPlant::operator new(0x50u);
  if ( v4 )
    CPlant::CPlant(v4, v5, FreeSlot, a1, a2);
  return FreeSlot;
}


// address=[0x1519ab0]
// Decompiled from int __cdecl CSearchRoutines::SearchVineSeedPos(int a1, int a2)
static int __cdecl CSearchRoutines::SearchVineSeedPos(int,int,int) {
  
  int v3; // [esp+4h] [ebp-18h]
  int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+10h] [ebp-Ch]
  int v6; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  v6 = CWorldManager::Index(a1, a2);
  if ( (CWorldManager::Ground(v6) & 0xF0) != 0x10 )
    return 0;
  if ( (int)CSearchRoutines::CalcRawness(v6) <= 7 )
    return 0;
  if ( CWorldManager::ShadingGradient(v6) < 8 )
    return 0;
  for ( i = 0; i < 7; ++i )
  {
    v4 = a1 + CSpiralOffsets::DeltaX(i);
    v5 = a2 + CSpiralOffsets::DeltaY(i);
    v3 = CWorldManager::Index(v4, v5);
    if ( CWorldManager::FlagBits(v3, 0x7Fu) )
      return 0;
  }
  return -1;
}


// address=[0x1519b90]
// Decompiled from int __cdecl CSearchRoutines::SearchGrain(int a1, int a2)
static int __cdecl CSearchRoutines::SearchGrain(int,int,int) {
  
  bool IsStaticInstance; // al
  CPlant *v4; // [esp+Ch] [ebp-1Ch]
  IDecoObject *v5; // [esp+10h] [ebp-18h]
  unsigned __int8 *v6; // [esp+14h] [ebp-14h]
  int v7; // [esp+18h] [ebp-10h]
  int FreeSlot; // [esp+18h] [ebp-10h]

  v7 = CWorldManager::ObjectId(a1, a2);
  if ( !v7 )
    return 0;
  v6 = (unsigned __int8 *)CMapObjectMgr::Entity(v7);
  if ( IEntity::ObjType(v6) != 32
    || IEntity::Type((unsigned __int16 *)v6) != 209 && IEntity::Type((unsigned __int16 *)v6) != 210 )
  {
    return 0;
  }
  if ( !IEntity::FlagBits(v6, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    return 0;
  v5 = (IDecoObject *)CMapObjectMgr::EntityPtr(v7);
  IsStaticInstance = IDecoObject::IsStaticInstance(v5);
  if ( !IsStaticInstance )
    return 0;
  FreeSlot = CMapObjectMgr::GetFreeSlot(IsStaticInstance);
  v4 = (CPlant *)CPlant::operator new(0x50u);
  if ( v4 )
    CPlant::CPlant(v4, v5, FreeSlot, a1, a2);
  return FreeSlot;
}


// address=[0x1519cb0]
// Decompiled from int __cdecl CSearchRoutines::SearchGrainSeedPos(int a1, int a2)
static int __cdecl CSearchRoutines::SearchGrainSeedPos(int,int,int) {
  
  int v3; // [esp+8h] [ebp-14h]
  int v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+14h] [ebp-8h]
  int v6; // [esp+18h] [ebp-4h]
  int v7; // [esp+18h] [ebp-4h]

  v6 = CWorldManager::Index(a1, a2);
  if ( (CWorldManager::Ground(v6) & 0xF0) != 0x10 )
    return 0;
  if ( (int)CSearchRoutines::CalcRawness(v6) > 7 )
    return 0;
  v5 = 0;
  if ( CWorldManager::Ground(v6) == 64 )
    return 0;
  while ( v5 < 7 )
  {
    v3 = a1 + CSpiralOffsets::DeltaX(v5);
    v4 = a2 + CSpiralOffsets::DeltaY(v5);
    v7 = CWorldManager::Index(v3, v4);
    if ( CWorldManager::FlagBits(v7, 0x7Fu) )
      return 0;
    ++v5;
  }
  return -1;
}


// address=[0x1519da0]
// Decompiled from int __cdecl CSearchRoutines::SearchBeehive(int a1, int a2)
static int __cdecl CSearchRoutines::SearchBeehive(int,int,int) {
  
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+8h] [ebp-8h]
  unsigned __int8 *v5; // [esp+Ch] [ebp-4h]

  v4 = CWorldManager::ObjectId(a1, a2);
  if ( !v4 )
    return 0;
  v3 = CWorldManager::Index(a1, a2);
  if ( CWorldManager::FlagBits(v3, 0x20u) )
    return 0;
  v5 = (unsigned __int8 *)CMapObjectMgr::Entity(v4);
  if ( IEntity::ObjType(v5) != 32 )
    return 0;
  if ( IEntity::Type((unsigned __int16 *)v5) != 217 )
    return 0;
  if ( IEntity::FlagBits(v5, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    return v4;
  return 0;
}


// address=[0x1519e50]
// Decompiled from int __cdecl CSearchRoutines::SearchBeehivePos(int a1, int a2)
static int __cdecl CSearchRoutines::SearchBeehivePos(int,int,int) {
  
  unsigned int v2; // eax

  CWorldManager::Index(a1, a2);
  v2 = (unsigned int)CGameData::Rand(g_pGameData);
  if ( CDecoObjMgr::IsAddDecoObjOk((CDecoObjMgr *)&g_cDecoObjMgr, a1, a2, 217, 0, v2 % 3) )
    return -1;
  else
    return 0;
}


// address=[0x1519eb0]
// Decompiled from int __cdecl CSearchRoutines::SearchMushroom(int a1, int a2)
static int __cdecl CSearchRoutines::SearchMushroom(int,int,int) {
  
  IDecoObject *v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]
  unsigned __int8 *v5; // [esp+8h] [ebp-4h]

  v4 = CWorldManager::ObjectId(a1, a2);
  if ( v4
    && (v5 = (unsigned __int8 *)CMapObjectMgr::Entity(v4), IEntity::ObjType(v5) == 32)
    && (IEntity::Type((unsigned __int16 *)v5) == 212
     || IEntity::Type((unsigned __int16 *)v5) == 213
     || IEntity::Type((unsigned __int16 *)v5) == 214)
    && IEntity::FlagBits(v5, (EntityFlag)((char *)&loc_1FFFFFF + 1))
    && (v3 = (IDecoObject *)CMapObjectMgr::EntityPtr(v4), IDecoObject::IsStaticInstance(v3)) )
  {
    return v4;
  }
  else
  {
    return 0;
  }
}


// address=[0x1519f60]
// Decompiled from int __cdecl CSearchRoutines::SearchMushroomSeedPos(int a1, int a2)
static int __cdecl CSearchRoutines::SearchMushroomSeedPos(int,int,int) {
  
  int v3; // [esp+0h] [ebp-4h]

  v3 = CWorldManager::Index(a1, a2);
  if ( !CWorldManager::FlagBits(v3, 4u) )
    return 0;
  if ( CDecoObjMgr::IsAddDecoObjOk((CDecoObjMgr *)&g_cDecoObjMgr, a1, a2, 212, 0, 0) )
    return -1;
  return 0;
}


// address=[0x1519fc0]
// Decompiled from int __cdecl CSearchRoutines::SearchVenison(int a1, int a2)
static int __cdecl CSearchRoutines::SearchVenison(int,int,int) {
  
  int v2; // eax
  int v4; // [esp+0h] [ebp-8h]
  unsigned __int8 *v5; // [esp+4h] [ebp-4h]

  v4 = CWorldManager::MapObjectId(a1, a2);
  if ( v4
    && (v5 = (unsigned __int8 *)CMapObjectMgr::Entity(v4), IEntity::ObjType(v5) == 128)
    && (v2 = IEntity::Type((unsigned __int16 *)v5), CAnimalMgr::IsHuntable((CAnimalMgr *)&g_cAnimalMgr, v2))
    && IEntity::FlagBits(v5, (EntityFlag)&loc_3000000) )
  {
    return v4;
  }
  else
  {
    return 0;
  }
}


// address=[0x151a040]
// Decompiled from BOOL __cdecl CSearchRoutines::SearchWater(int a1, int a2)
static int __cdecl CSearchRoutines::SearchWater(int,int,int) {
  
  return (CWorldManager::Ground(a1, a2) & 0xF0) == 96;
}


// address=[0x151a070]
// Decompiled from int __cdecl CSearchRoutines::SearchStone(int a1, int a2)
static int __cdecl CSearchRoutines::SearchStone(int,int,int) {
  
  int v3; // eax
  bool IsStaticInstance; // al
  int FreeSlot; // [esp+8h] [ebp-1Ch]
  CStone *v6; // [esp+10h] [ebp-14h]
  IDecoObject *v7; // [esp+14h] [ebp-10h]

  if ( CWorldManager::FlagBits(a1, a2, 4u) )
    return 0;
  if ( CWorldManager::ResourceType(a1, a2) != 96 )
    return 0;
  v3 = CWorldManager::ObjectId(a1, a2);
  v7 = (IDecoObject *)CMapObjectMgr::EntityPtr(v3);
  if ( !v7 && BBSupportDbgReport(2, "MapObjects\\Building\\SearchRoutines.cpp", 483, "pSrcStone") == 1 )
    __debugbreak();
  if ( !v7 )
    return 0;
  IsStaticInstance = IDecoObject::IsStaticInstance(v7);
  if ( !IsStaticInstance )
    return 0;
  FreeSlot = CMapObjectMgr::GetFreeSlot(IsStaticInstance);
  v6 = (CStone *)CStone::operator new(0x48u);
  if ( v6 )
    CStone::CStone(v6, v7, FreeSlot, a1, a2);
  return FreeSlot;
}


// address=[0x151a190]
// Decompiled from int __cdecl CSearchRoutines::SearchFish(int a1, int a2)
static int __cdecl CSearchRoutines::SearchFish(int,int,int) {
  
  const char *v3; // [esp+4h] [ebp-24h]
  int v4; // [esp+8h] [ebp-20h]
  int v5; // [esp+Ch] [ebp-1Ch]
  int v6; // [esp+18h] [ebp-10h]
  int v7; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  if ( !CWorldManager::InInnerWorld2(a1, a2) )
    return 0;
  v4 = CWorldManager::Index(a1, a2);
  for ( i = 0; ; ++i )
  {
    if ( i >= 19 )
      return 0;
    v7 = v4 + CWorldManager::SurroundingHexPointRelIndex(i);
    v5 = CWorldManager::Resource(v7);
    if ( (unsigned int)(v5 - 1) <= 0xE && !CWorldManager::FlagBits(v7, 4u) )
    {
      v6 = CWorldManager::Ground(v7) & 0xF0;
      if ( v6 == 96 || v6 == 0 )
        break;
    }
  }
  v3 = CGameData::Rand(g_pGameData);
  if ( (unsigned int)v3 < CRandom16::PercentValue(0x21u) )
    return -1;
  if ( (v5 <= 0 || v5 > 15)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\SearchRoutines.cpp",
         1106,
         "(iFishAmount > 0) && (iFishAmount <= RESOURCE_AMOUNT_MASK)") == 1 )
  {
    __debugbreak();
  }
  CWorldManager::SetResource(v7, 0, v5 - 1);
  return 1;
}


// address=[0x151a300]
// Decompiled from int __cdecl CSearchRoutines::SearchGold(int a1, int a2)
static int __cdecl CSearchRoutines::SearchGold(int,int,int) {
  
  if ( CWorldManager::ResourceType(a1, a2) == 16 )
    return -1;
  else
    return 0;
}


// address=[0x151a330]
// Decompiled from int __cdecl CSearchRoutines::SearchCoal(int a1, int a2)
static int __cdecl CSearchRoutines::SearchCoal(int,int,int) {
  
  if ( CWorldManager::ResourceType(a1, a2) == 16 )
    return -1;
  else
    return 0;
}


// address=[0x151a360]
// Decompiled from int __cdecl CSearchRoutines::SearchIron(int a1, int a2)
static int __cdecl CSearchRoutines::SearchIron(int,int,int) {
  
  if ( CWorldManager::ResourceType(a1, a2) == 32 )
    return -1;
  else
    return 0;
}


// address=[0x151a390]
// Decompiled from int __cdecl CSearchRoutines::SearchSulfur(int a1, int a2)
static int __cdecl CSearchRoutines::SearchSulfur(int,int,int) {
  
  if ( CWorldManager::ResourceType(a1, a2) == 64 )
    return -1;
  else
    return 0;
}


// address=[0x151a3c0]
// Decompiled from int __cdecl CSearchRoutines::SearchGranit(int a1, int a2)
static int __cdecl CSearchRoutines::SearchGranit(int,int,int) {
  
  if ( CWorldManager::ResourceType(a1, a2) == 80 )
    return -1;
  else
    return 0;
}


// address=[0x151a3f0]
// Decompiled from int __cdecl CSearchRoutines::SearchDarkLand(int a1, int a2)
static int __cdecl CSearchRoutines::SearchDarkLand(int,int,int) {
  
  int v3; // [esp+0h] [ebp-4h]

  v3 = CWorldManager::Index(a1, a2);
  if ( CWorldManager::FlagBits(v3, 4u) )
    return -1;
  else
    return 0;
}


// address=[0x151a430]
// Decompiled from int __cdecl CSearchRoutines::SearchGreenLand(int a1, int a2)
static int __cdecl CSearchRoutines::SearchGreenLand(int,int,int) {
  
  int v3; // [esp+0h] [ebp-4h]

  v3 = CWorldManager::Index(a1, a2);
  if ( CWorldManager::FlagBits(v3, 4u) )
    return 0;
  else
    return -1;
}


// address=[0x151a470]
// Decompiled from int __cdecl CSearchRoutines::CalcRawness(int a1)
static int __cdecl CSearchRoutines::CalcRawness(int) {
  
  int v1; // ecx
  int v2; // esi
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  int v11; // [esp+Ch] [ebp-10h]
  int v12; // [esp+10h] [ebp-Ch]
  int v13; // [esp+14h] [ebp-8h]
  int v14; // [esp+18h] [ebp-4h]

  v14 = CWorldManager::Width(v1);
  v2 = CWorldManager::GroundHeight(a1 - 1);
  v3 = CWorldManager::GroundHeight(a1 + 1);
  v12 = j__abs(v2 - v3);
  v4 = CWorldManager::GroundHeight(a1 - v14);
  v5 = CWorldManager::GroundHeight(v14 + a1);
  v11 = j__abs(v4 - v5);
  v6 = CWorldManager::GroundHeight(a1 - v14 - 1);
  v7 = CWorldManager::GroundHeight(a1 + v14 + 1);
  v13 = j__abs(v6 - v7);
  if ( v12 < v11 )
  {
    if ( v11 < v13 )
      return v13;
    else
      return v11;
  }
  else if ( v12 < v13 )
  {
    return v13;
  }
  else
  {
    return v12;
  }
}


