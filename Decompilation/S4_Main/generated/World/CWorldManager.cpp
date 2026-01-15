#include "CWorldManager.h"

// Definitions for class CWorldManager

// address=[0x12fd0f0]
// Decompiled from int __cdecl CWorldManager::FlagBits(int a1, unsigned __int8 a2)
static unsigned int __cdecl CWorldManager::FlagBits(int,unsigned int) {
  
  return a2 & *(_BYTE *)(a1 + CWorldManager::m_cFlagMap);
}


// address=[0x12fd2d0]
// Decompiled from bool __cdecl sub_16FD2D0(unsigned int a1, unsigned int a2)
static bool __cdecl CWorldManager::InWorld(int,int) {
  
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]

  if ( a1 < CWorldManager::m_iWidthHeight )
    v4 = -1;
  else
    v4 = 0;
  if ( a2 < CWorldManager::m_iWidthHeight )
    v3 = -1;
  else
    v3 = 0;
  return (v3 & v4) != 0;
}


// address=[0x12fd350]
// Decompiled from int __cdecl CWorldManager::Index(int x, int y)
static int __cdecl CWorldManager::Index(int,int) {
  
  return x + CWorldManager::m_iWidthHeight * y;
}


// address=[0x12fd440]
// Decompiled from int __cdecl CWorldManager::NormalTileId(int a1)
static int __cdecl CWorldManager::NormalTileId(int) {
  
  return *(unsigned __int16 *)(CWorldManager::m_cNormalTileIdMap + 2 * a1);
}


// address=[0x12fd4a0]
// Decompiled from int __cdecl CWorldManager::ObjectId(int a1, int a2)
static int __cdecl CWorldManager::ObjectId(int,int) {
  
  return *(unsigned __int16 *)(CWorldManager::m_cDecoObjectMap + 2 * (a1 + CWorldManager::m_iWidthHeight * a2));
}


// address=[0x12fd620]
// Decompiled from int __cdecl CWorldManager::SectorId(int a1)
static int __cdecl CWorldManager::SectorId(int) {
  
  CTile *v1; // eax
  int v3; // [esp+0h] [ebp-4h]

  v3 = CWorldManager::NormalTileId(a1);
  v1 = (CTile *)ITiling::Tile(v3);
  return CTile::SectorId(v1);
}


// address=[0x1306950]
// Decompiled from int __cdecl CWorldManager::SectorId(int a1, int a2)
static int __cdecl CWorldManager::SectorId(int,int) {
  
  int v2; // eax
  CTile *v3; // eax
  int v5; // [esp+0h] [ebp-4h]

  v2 = CWorldManager::Index(a1, a2);
  v5 = CWorldManager::NormalTileId(v2);
  v3 = (CTile *)ITiling::Tile(v5);
  return CTile::SectorId(v3);
}


// address=[0x130eff0]
// Decompiled from int __cdecl CWorldManager::Ground(int a1)
static int __cdecl CWorldManager::Ground(int) {
  
  return *(unsigned __int8 *)(CWorldManager::m_cRenderMap + 4 * a1 + 1);
}


// address=[0x130f080]
// Decompiled from bool __cdecl CWorldManager::InWorldPackedXY(int a1)
static bool __cdecl CWorldManager::InWorldPackedXY(int) {
  
  int v1; // eax
  int v3; // [esp-4h] [ebp-4h]

  v3 = Y16X16::UnpackYFast(a1);
  v1 = Y16X16::UnpackXFast(a1);
  return CWorldManager::InWorld(v1, v3);
}


// address=[0x130f0b0]
// Decompiled from bool __cdecl CWorldManager::IsBlockedLand(int a1)
static bool __cdecl CWorldManager::IsBlockedLand(int) {
  
  return (*(_BYTE *)(a1 + CWorldManager::m_cFlagMap) & 1) != 0;
}


// address=[0x130f1f0]
// Decompiled from int __cdecl CWorldManager::NeighborRelIndex(int a1)
static int __cdecl CWorldManager::NeighborRelIndex(int) {
  
  return CWorldManager::m_cNeighborRelIndices[a1];
}


// address=[0x130f3c0]
// Decompiled from int __cdecl CWorldManager::SettlerId(int a1, int a2)
static int __cdecl CWorldManager::SettlerId(int,int) {
  
  if ( CWorldManager::m_cMapObjectMap[a1 + CWorldManager::m_iWidthHeight * a2] )
    return CWorldManager::CheckSettlerId(CWorldManager::m_cMapObjectMap[a1 + CWorldManager::m_iWidthHeight * a2]);
  else
    return 0;
}


// address=[0x130f540]
// Decompiled from int CWorldManager::Width()
static int __cdecl CWorldManager::Width(void) {
  
  return CWorldManager::m_iWidthHeight;
}


// address=[0x131c950]
// Decompiled from int __cdecl CWorldManager::Flags(int a1)
static unsigned int __cdecl CWorldManager::Flags(int) {
  
  return *(unsigned __int8 *)(a1 + CWorldManager::m_cFlagMap);
}


// address=[0x131c970]
// Decompiled from int __cdecl CWorldManager::GroundHeight(int a1)
static int __cdecl CWorldManager::GroundHeight(int) {
  
  return *(unsigned __int8 *)(CWorldManager::m_cRenderMap + 4 * a1);
}


// address=[0x131c9b0]
// Decompiled from int CWorldManager::Height()
static int __cdecl CWorldManager::Height(void) {
  
  return CWorldManager::m_iWidthHeight;
}


// address=[0x131c9c0]
// Decompiled from int __cdecl CWorldManager::Resource(int a1)
static int __cdecl CWorldManager::Resource(int) {
  
  return *(unsigned __int8 *)(a1 + CWorldManager::m_cResourceMap);
}


// address=[0x1326db0]
// Decompiled from int __cdecl CWorldManager::EcoSectorId(int a1, int a2)
static int __cdecl CWorldManager::EcoSectorId(int,int) {
  
  int v2; // eax
  CTile *v3; // eax
  int v5; // [esp+0h] [ebp-4h]

  v2 = CWorldManager::Index(a1, a2);
  v5 = CWorldManager::NormalTileId(v2);
  v3 = (CTile *)ITiling::Tile(v5);
  return CTile::EcoSectorId(v3);
}


// address=[0x1335f70]
// Decompiled from int __cdecl CWorldManager::FlagBits_0(int a1, int a2, unsigned __int8 a3)
static unsigned int __cdecl CWorldManager::FlagBits(int,int,unsigned int) {
  
  return a3 & *(_BYTE *)(CWorldManager::m_cFlagMap + a1 + CWorldManager::m_iWidthHeight * a2);
}


// address=[0x13367c0]
// Decompiled from int __cdecl CWorldManager::ResourceAmount(int a1, int a2, int a3)
static int __cdecl CWorldManager::ResourceAmount(int,int,int) {
  
  char v5; // [esp+4h] [ebp-4h]

  v5 = *(_BYTE *)(CWorldManager::m_cResourceMap + a1 + CWorldManager::m_iWidthHeight * a2);
  if ( (v5 & 0xF0) == a3 )
    return v5 & 0xF;
  else
    return 0;
}


// address=[0x1346600]
// Decompiled from int __cdecl CWorldManager::BuildingId(int a1, int a2)
static int __cdecl CWorldManager::BuildingId(int,int) {
  
  if ( CWorldManager::m_cMapObjectMap[a1 + CWorldManager::m_iWidthHeight * a2] )
    return CWorldManager::CheckBuildingId(CWorldManager::m_cMapObjectMap[a1 + CWorldManager::m_iWidthHeight * a2]);
  else
    return 0;
}


// address=[0x1346660]
// Decompiled from int __cdecl CWorldManager::EcoSectorId(int a1)
static int __cdecl CWorldManager::EcoSectorId(int) {
  
  CTile *v1; // eax
  int v3; // [esp+0h] [ebp-4h]

  v3 = CWorldManager::NormalTileId(a1);
  v1 = (CTile *)ITiling::Tile(v3);
  return CTile::EcoSectorId(v1);
}


// address=[0x1346760]
// Decompiled from int __cdecl CWorldManager::Ground(int a1, int a2)
static int __cdecl CWorldManager::Ground(int,int) {
  
  return *(unsigned __int8 *)(CWorldManager::m_cRenderMap + 4 * (a1 + CWorldManager::m_iWidthHeight * a2) + 1);
}


// address=[0x1351a40]
// Decompiled from int __cdecl CWorldManager::BuildingId(int a1)
static int __cdecl CWorldManager::BuildingId(int) {
  
  if ( CWorldManager::m_cMapObjectMap[a1] )
    return CWorldManager::CheckBuildingId(CWorldManager::m_cMapObjectMap[a1]);
  else
    return 0;
}


// address=[0x1351b70]
// Decompiled from int __cdecl CWorldManager::MapObjectId(int a1)
static int __cdecl CWorldManager::MapObjectId(int) {
  
  return CWorldManager::m_cMapObjectMap[a1];
}


// address=[0x1351b90]
// Decompiled from int __cdecl CWorldManager::MapObjectId(int a1, int a2)
static int __cdecl CWorldManager::MapObjectId(int,int) {
  
  return CWorldManager::m_cMapObjectMap[a1 + CWorldManager::m_iWidthHeight * a2];
}


// address=[0x1351bc0]
// Decompiled from int __cdecl CWorldManager::MoveCostsBits(int a1)
static int __cdecl CWorldManager::MoveCostsBits(int) {
  
  return *(_BYTE *)(a1 + CWorldManager::m_cWalkCount5MoveCost3Map) & 7;
}


// address=[0x1351be0]
// Decompiled from int __cdecl CWorldManager::MoveCount(int a1)
static int __cdecl CWorldManager::MoveCount(int) {
  
  return (*(_BYTE *)(a1 + CWorldManager::m_cWalkCount5MoveCost3Map) & 0xF8) >> 3;
}


// address=[0x1351c90]
// Decompiled from int __cdecl CWorldManager::ObjectId(int a1)
static int __cdecl CWorldManager::ObjectId(int) {
  
  return *(unsigned __int16 *)(CWorldManager::m_cDecoObjectMap + 2 * a1);
}


// address=[0x1351cb0]
// Decompiled from int __cdecl CWorldManager::OccupyingEntityId(int a1)
static int __cdecl CWorldManager::OccupyingEntityId(int) {
  
  if ( CWorldManager::FlagBits(a1, 1u) )
    return 0;
  else
    return CWorldManager::MapObjectId(a1);
}


// address=[0x1351d00]
// Decompiled from int __cdecl CWorldManager::OccupyingEntityId(int a1, int a2)
static int __cdecl CWorldManager::OccupyingEntityId(int,int) {
  
  return CWorldManager::OccupyingEntityId(a1 + CWorldManager::m_iWidthHeight * a2);
}


// address=[0x141d7b0]
// Decompiled from int __cdecl CWorldManager::ClearFlagBits(int a1, int a2, char a3)
static void __cdecl CWorldManager::ClearFlagBits(int,int,unsigned int) {
  
  int result; // eax

  if ( (a3 & 1) != 0
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\World\\World.h",
         584,
         "(_uMask & FLAG_BLOCKED_LAND) == 0") == 1 )
  {
    __debugbreak();
  }
  result = a1 + CWorldManager::m_iWidthHeight * a2;
  *(_BYTE *)(CWorldManager::m_cFlagMap + result) &= ~a3;
  return result;
}


// address=[0x141d830]
// Decompiled from int __cdecl CWorldManager::ClearFlagBits(int a1, char a2)
static void __cdecl CWorldManager::ClearFlagBits(int,unsigned int) {
  
  int result; // eax

  if ( (a2 & 1) != 0
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\World\\World.h",
         572,
         "(_uMask & FLAG_BLOCKED_LAND) == 0") == 1 )
  {
    __debugbreak();
  }
  result = a1 + CWorldManager::m_cFlagMap;
  *(_BYTE *)(a1 + CWorldManager::m_cFlagMap) &= ~a2;
  return result;
}


// address=[0x141d8d0]
// Decompiled from bool __cdecl CWorldManager::InInnerWorld16(int a1, int a2)
static bool __cdecl CWorldManager::InInnerWorld16(int,int) {
  
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]
  unsigned int v5; // [esp+18h] [ebp+Ch]

  v5 = a2 - 16;
  if ( a1 - 16 < (unsigned int)(CWorldManager::m_iWidthHeight - 32) )
    v4 = -1;
  else
    v4 = 0;
  if ( v5 < CWorldManager::m_iWidthHeight - 32 )
    v3 = -1;
  else
    v3 = 0;
  return (v3 & v4) != 0;
}


// address=[0x141d9d0]
// Decompiled from bool __cdecl CWorldManager::IsWater(int a1)
static bool __cdecl CWorldManager::IsWater(int) {
  
  return CLandscapeProperties::IsWater(*(unsigned __int8 *)(CWorldManager::m_cRenderMap + 4 * a1 + 1));
}


// address=[0x141da40]
// Decompiled from int __cdecl CWorldManager::SetFlagBits(int a1, int a2, char a3)
static void __cdecl CWorldManager::SetFlagBits(int,int,unsigned int) {
  
  int result; // eax

  if ( (a3 & 1) != 0
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\World\\World.h",
         560,
         "(_uMask & FLAG_BLOCKED_LAND) == 0") == 1 )
  {
    __debugbreak();
  }
  result = CWorldManager::m_cFlagMap;
  *(_BYTE *)(CWorldManager::m_cFlagMap + a1 + CWorldManager::m_iWidthHeight * a2) |= a3;
  return result;
}


// address=[0x141dac0]
// Decompiled from unsigned int __cdecl CWorldManager::SetFlagBits(int a1, unsigned int a2)
static void __cdecl CWorldManager::SetFlagBits(int,unsigned int) {
  
  unsigned int result; // eax

  if ( (a2 & 1) != 0
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\World\\World.h",
         548,
         "(_uMask & FLAG_BLOCKED_LAND) == 0") == 1 )
  {
    __debugbreak();
  }
  result = a2 | *(unsigned __int8 *)(a1 + CWorldManager::m_cFlagMap);
  *(_BYTE *)(a1 + CWorldManager::m_cFlagMap) = result;
  return result;
}


// address=[0x141dba0]
// Decompiled from int __cdecl CWorldManager::X(int a1)
static int __cdecl CWorldManager::X(int) {
  
  return a1 % CWorldManager::m_iWidthHeight;
}


// address=[0x141dbc0]
// Decompiled from int __cdecl CWorldManager::Y(int a1)
static int __cdecl CWorldManager::Y(int) {
  
  return a1 / CWorldManager::m_iWidthHeight;
}


// address=[0x1439bd0]
// Decompiled from int __cdecl CWorldManager::Index(int a1)
static int __cdecl CWorldManager::Index(int) {
  
  int v1; // esi

  v1 = Y16X16::UnpackXFast(a1);
  return v1 + CWorldManager::m_iWidthHeight * Y16X16::UnpackYFast(a1);
}


// address=[0x1447770]
// Decompiled from int __cdecl CWorldManager::PileId(int a1)
static int __cdecl CWorldManager::PileId(int) {
  
  if ( *(_WORD *)(CWorldManager::m_cDecoObjectMap + 2 * a1) )
    return CWorldManager::CheckPileId(*(unsigned __int16 *)(CWorldManager::m_cDecoObjectMap + 2 * a1));
  else
    return 0;
}


// address=[0x1447860]
// Decompiled from int __cdecl CWorldManager::SettlerId(int a1)
static int __cdecl CWorldManager::SettlerId(int) {
  
  if ( CWorldManager::m_cMapObjectMap[a1] )
    return CWorldManager::CheckSettlerId(CWorldManager::m_cMapObjectMap[a1]);
  else
    return 0;
}


// address=[0x1452a70]
// Decompiled from int __cdecl CWorldManager::OwnerId(int a1, int a2)
static int __cdecl CWorldManager::OwnerId(int,int) {
  
  int v2; // eax
  CTile *v3; // eax
  int v5; // [esp+0h] [ebp-4h]

  v2 = CWorldManager::Index(a1, a2);
  v5 = CWorldManager::NormalTileId(v2);
  v3 = (CTile *)ITiling::Tile(v5);
  return CTile::OwnerId(v3);
}


// address=[0x1460470]
// Decompiled from int CWorldManager::ClearHelperObject()
static void __cdecl CWorldManager::ClearHelperObject(void) {
  
  return TSparseMap<unsigned char>::Clear(CWorldManager::m_pHelpObjectMap);
}


// address=[0x14605e0]
// Decompiled from int __cdecl CWorldManager::GetHelperObject(int a1, int a2)
static int __cdecl CWorldManager::GetHelperObject(int,int) {
  
  return (unsigned __int8)TSparseMap<unsigned char>::Get(a1, a2);
}


// address=[0x1460a20]
// Decompiled from int __cdecl CWorldManager::SetHelperObject(int a1, int a2, char a3)
static void __cdecl CWorldManager::SetHelperObject(int,int,int) {
  
  char v4; // [esp+3h] [ebp-1h] BYREF

  v4 = a3;
  return TSparseMap<unsigned char>::Set(a1, a2, &v4);
}


// address=[0x146aea0]
// Decompiled from int __cdecl CWorldManager::ResourceAmount(int a1, int a2)
static int __cdecl CWorldManager::ResourceAmount(int,int) {
  
  char v4; // [esp+4h] [ebp-4h]

  v4 = *(_BYTE *)(a1 + CWorldManager::m_cResourceMap);
  if ( (v4 & 0xF0) == a2 )
    return v4 & 0xF;
  else
    return 0;
}


// address=[0x146aef0]
// Decompiled from int __cdecl CWorldManager::ResourceType(int a1)
static int __cdecl CWorldManager::ResourceType(int) {
  
  return *(_BYTE *)(a1 + CWorldManager::m_cResourceMap) & 0xF0;
}


// address=[0x146af10]
// Decompiled from int __cdecl CWorldManager::SetObjectId(int a1, __int16 a2)
static void __cdecl CWorldManager::SetObjectId(int,int) {
  
  int result; // eax

  result = a1;
  *(_WORD *)(CWorldManager::m_cDecoObjectMap + 2 * a1) = a2;
  return result;
}


// address=[0x146af30]
// Decompiled from int __cdecl CWorldManager::SetResource(int a1, int a2, int a3)
static void __cdecl CWorldManager::SetResource(int,int,int) {
  
  int result; // eax

  result = a3 | a2;
  *(_BYTE *)(a1 + CWorldManager::m_cResourceMap) = a3 | a2;
  return result;
}


// address=[0x1470bb0]
// Decompiled from int __cdecl CWorldManager::PileId(int a1, int a2)
static int __cdecl CWorldManager::PileId(int,int) {
  
  if ( *(_WORD *)(CWorldManager::m_cDecoObjectMap + 2 * (a1 + CWorldManager::m_iWidthHeight * a2)) )
    return CWorldManager::CheckPileId(*(unsigned __int16 *)(CWorldManager::m_cDecoObjectMap
                                                          + 2 * (a1 + CWorldManager::m_iWidthHeight * a2)));
  else
    return 0;
}


// address=[0x1470e10]
// Decompiled from int __cdecl CWorldManager::SurroundingHexPointRelIndex(int a1)
static int __cdecl CWorldManager::SurroundingHexPointRelIndex(int) {
  
  return CSurroundingHexPointsIndices::operator[](a1);
}


// address=[0x1486fb0]
// Decompiled from int __cdecl CWorldManager::GroundHeight(int a1, int a2)
static int __cdecl CWorldManager::GroundHeight(int,int) {
  
  return *(unsigned __int8 *)(CWorldManager::m_cRenderMap + 4 * (a1 + CWorldManager::m_iWidthHeight * a2));
}


// address=[0x14aabe0]
// Decompiled from int CWorldManager::GetDecoObjectPtr()
static unsigned short * __cdecl CWorldManager::GetDecoObjectPtr(void) {
  
  return CWorldManager::m_cDecoObjectMap;
}


// address=[0x14aac20]
// Decompiled from int CWorldManager::GetLandscapePtr()
static struct T_GFX_MAP_ELEMENT * __cdecl CWorldManager::GetLandscapePtr(void) {
  
  return CWorldManager::m_cRenderMap;
}


// address=[0x14aac30]
// Decompiled from WORD *CWorldManager::GetMapObjectPtr()
static unsigned short * __cdecl CWorldManager::GetMapObjectPtr(void) {
  
  return CWorldManager::m_cMapObjectMap;
}


// address=[0x14d87f0]
// Decompiled from int __cdecl CWorldManager::SetMapObjectId(int a1, WORD a2)
static void __cdecl CWorldManager::SetMapObjectId(int,int) {
  
  int result; // eax

  result = a1;
  CWorldManager::m_cMapObjectMap[a1] = a2;
  return result;
}


// address=[0x14d8870]
// Decompiled from int __cdecl CWorldManager::SetSettlerId(int a1, __int16 a2)
static void __cdecl CWorldManager::SetSettlerId(int,int) {
  
  return CWorldManager::SetMapObjectId(a1, a2);
}


// address=[0x14dfef0]
// Decompiled from bool __cdecl CWorldManager::InWorld(unsigned int a1)
static bool __cdecl CWorldManager::InWorld(int) {
  
  return a1 < CWorldManager::m_iWorldIdxMax;
}


// address=[0x14dff70]
// Decompiled from bool __cdecl CWorldManager::IsPositionFreeForSettler(int a1)
static bool __cdecl CWorldManager::IsPositionFreeForSettler(int) {
  
  return (*(_BYTE *)(a1 + CWorldManager::m_cFlagMap) & 1) == 0 && !CWorldManager::m_cMapObjectMap[a1];
}


// address=[0x14dffc0]
// Decompiled from bool __cdecl CWorldManager::IsPositionFreeForSettler(int a1, int a2)
static bool __cdecl CWorldManager::IsPositionFreeForSettler(int,int) {
  
  return CWorldManager::IsPositionFreeForSettler(a1 + CWorldManager::m_iWidthHeight * a2);
}


// address=[0x14e3040]
// Decompiled from int __cdecl CWorldManager::SetMapObjectId(int x, int y, WORD id)
static void __cdecl CWorldManager::SetMapObjectId(int,int,int) {
  
  int result; // eax

  result = x + CWorldManager::m_iWidthHeight * y;
  CWorldManager::m_cMapObjectMap[result] = id;
  return result;
}


// address=[0x14e3070]
// Decompiled from int __cdecl CWorldManager::SetSettlerId(int x, int y, __int16 id)
static void __cdecl CWorldManager::SetSettlerId(int,int,int) {
  
  return CWorldManager::SetMapObjectId(x, y, id);
}


// address=[0x14e6880]
// Decompiled from int __cdecl CWorldManager::SetMoveCostsBits(int a1, char a2)
static void __cdecl CWorldManager::SetMoveCostsBits(int,int) {
  
  int result; // eax

  result = a1 + CWorldManager::m_cWalkCount5MoveCost3Map;
  *(_BYTE *)(a1 + CWorldManager::m_cWalkCount5MoveCost3Map) = a2 & 7 | *(_BYTE *)(a1
                                                                                + CWorldManager::m_cWalkCount5MoveCost3Map) & 0xF8;
  return result;
}


// address=[0x14eb2e0]
// Decompiled from int __cdecl CWorldManager::ClearBlockedPosition(int a1, int a2)
static void __cdecl CWorldManager::ClearBlockedPosition(int,int) {
  
  return (*(int (__thiscall **)(void *, int, int))(*(_DWORD *)g_pTiling + 20))(g_pTiling, a1, a2);
}


// address=[0x14eb6f0]
// Decompiled from int __cdecl CWorldManager::SetBlockedPosition(int a1, int a2)
static void __cdecl CWorldManager::SetBlockedPosition(int,int) {
  
  return (*(int (__thiscall **)(void *, int, int))(*(_DWORD *)g_pTiling + 12))(g_pTiling, a1, a2);
}


// address=[0x14eb720]
// Decompiled from int __cdecl CWorldManager::SetMoveCount(int a1, char a2)
static void __cdecl CWorldManager::SetMoveCount(int,int) {
  
  int result; // eax

  result = a1 + CWorldManager::m_cWalkCount5MoveCost3Map;
  *(_BYTE *)(a1 + CWorldManager::m_cWalkCount5MoveCost3Map) = (8 * a2) | *(_BYTE *)(a1
                                                                                  + CWorldManager::m_cWalkCount5MoveCost3Map) & 7;
  return result;
}


// address=[0x14eb750]
// Decompiled from int __cdecl CWorldManager::SetOwnerId(int a1, int a2, int a3)
static void __cdecl CWorldManager::SetOwnerId(int,int,int) {
  
  return (*(int (__thiscall **)(void *, int, int, int))(*(_DWORD *)g_pTiling + 28))(g_pTiling, a1, a2, a3);
}


// address=[0x14fd2d0]
// Decompiled from int __cdecl CWorldManager::DecreaseGroundHeight(int a1, int a2)
static void __cdecl CWorldManager::DecreaseGroundHeight(int,int) {
  
  int result; // eax

  result = a1 + CWorldManager::m_iWidthHeight * a2;
  --*(_BYTE *)(CWorldManager::m_cRenderMap + 4 * result);
  return result;
}


// address=[0x14fd770]
// Decompiled from int __cdecl CWorldManager::IncreaseGroundHeight(int a1, int a2)
static void __cdecl CWorldManager::IncreaseGroundHeight(int,int) {
  
  int result; // eax

  result = a1 + CWorldManager::m_iWidthHeight * a2;
  ++*(_BYTE *)(CWorldManager::m_cRenderMap + 4 * result);
  return result;
}


// address=[0x14fd7c0]
// Decompiled from bool __cdecl CWorldManager::IsWater(int a1, int a2)
static bool __cdecl CWorldManager::IsWater(int,int) {
  
  return CLandscapeProperties::IsWater(*(unsigned __int8 *)(CWorldManager::m_cRenderMap
                                                          + 4 * (a1 + CWorldManager::m_iWidthHeight * a2)
                                                          + 1));
}


// address=[0x14fdd70]
// Decompiled from int __cdecl CWorldManager::OwnerId(int a1)
static int __cdecl CWorldManager::OwnerId(int) {
  
  CTile *v1; // eax
  int v3; // [esp+0h] [ebp-4h]

  v3 = CWorldManager::NormalTileId(a1);
  v1 = (CTile *)ITiling::Tile(v3);
  return CTile::OwnerId(v1);
}


// address=[0x1506770]
// Decompiled from int __cdecl CWorldManager::SetObjectId(int a1, int a2, __int16 a3)
static void __cdecl CWorldManager::SetObjectId(int,int,int) {
  
  int result; // eax

  result = a1 + CWorldManager::m_iWidthHeight * a2;
  *(_WORD *)(CWorldManager::m_cDecoObjectMap + 2 * result) = a3;
  return result;
}


// address=[0x1516110]
// Decompiled from int __cdecl CWorldManager::SetResource(int a1, int a2, int a3, int a4)
static void __cdecl CWorldManager::SetResource(int,int,int,int) {
  
  int result; // eax

  result = a4 | a3;
  *(_BYTE *)(CWorldManager::m_cResourceMap + a1 + CWorldManager::m_iWidthHeight * a2) = a4 | a3;
  return result;
}


// address=[0x151aa50]
// Decompiled from bool __cdecl CWorldManager::InInnerWorld2(int a1, int a2)
static bool __cdecl CWorldManager::InInnerWorld2(int,int) {
  
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]
  unsigned int v5; // [esp+18h] [ebp+Ch]

  v5 = a2 - 2;
  if ( a1 - 2 < (unsigned int)(CWorldManager::m_iWidthHeight - 4) )
    v4 = -1;
  else
    v4 = 0;
  if ( v5 < CWorldManager::m_iWidthHeight - 4 )
    v3 = -1;
  else
    v3 = 0;
  return (v3 & v4) != 0;
}


// address=[0x151ab00]
// Decompiled from int __cdecl CWorldManager::ResourceType(int a1, int a2)
static int __cdecl CWorldManager::ResourceType(int,int) {
  
  return *(_BYTE *)(CWorldManager::m_cResourceMap + a1 + CWorldManager::m_iWidthHeight * a2) & 0xF0;
}


// address=[0x151ab30]
// Decompiled from int __cdecl CWorldManager::ShadingGradient(int a1)
static int __cdecl CWorldManager::ShadingGradient(int) {
  
  return T_GFX_MAP_ELEMENT::GetGradient((T_GFX_MAP_ELEMENT *)(CWorldManager::m_cRenderMap + 4 * a1));
}


// address=[0x1575b60]
// Decompiled from int __cdecl CWorldManager::CatapultTileId(int a1, int a2)
static int __cdecl CWorldManager::CatapultTileId(int,int) {
  
  return *((unsigned __int16 *)CWorldManager::m_cCatapultTileIdMap + a1 + CWorldManager::m_iWidthHeight * a2);
}


// address=[0x15a7a50]
// Decompiled from bool __cdecl CWorldManager::InInnerWorld1(int a1, int a2)
static bool __cdecl CWorldManager::InInnerWorld1(int,int) {
  
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]
  unsigned int v5; // [esp+18h] [ebp+Ch]

  v5 = a2 - 1;
  if ( a1 - 1 < (unsigned int)(CWorldManager::m_iWidthHeight - 2) )
    v4 = -1;
  else
    v4 = 0;
  if ( v5 < CWorldManager::m_iWidthHeight - 2 )
    v3 = -1;
  else
    v3 = 0;
  return (v3 & v4) != 0;
}


// address=[0x15d6110]
// Decompiled from int __cdecl CWorldManager::CatapultTileId(int a1)
static int __cdecl CWorldManager::CatapultTileId(int) {
  
  return *((unsigned __int16 *)CWorldManager::m_cCatapultTileIdMap + a1);
}


// address=[0x15fe660]
// Decompiled from bool __cdecl CWorldManager::IsBlockedWater(int a1)
static bool __cdecl CWorldManager::IsBlockedWater(int) {
  
  return (*(_BYTE *)(a1 + CWorldManager::m_cFlagMap) & 2) != 0;
}


// address=[0x16a2580]
// Decompiled from CWorldManager *__thiscall CWorldManager::CWorldManager(CWorldManager *this)
 CWorldManager::CWorldManager(void) {
  
  *(_DWORD *)this = &CWorldManager::_vftable_;
  CWorldManager::m_iWidthHeight = 0;
  CWorldManager::m_iWorldIdxMax = 0;
  CWorldManager::m_pHelpObjectMap = 0;
  return this;
}


// address=[0x16a25c0]
// Decompiled from int __thiscall CWorldManager::~CWorldManager(CWorldManager *this)
 CWorldManager::~CWorldManager(void) {
  
  *(_DWORD *)this = &CWorldManager::_vftable_;
  return CWorldManager::Destruct();
}


// address=[0x16a2610]
// Decompiled from void *CWorldManager::Destruct()
static void __cdecl CWorldManager::Destruct(void) {
  
  void *result; // eax

  CWorldManager::m_iWidthHeight = 0;
  CWorldManager::m_iWorldIdxMax = 0;
  TMap<unsigned short>::Done(&CWorldManager::m_cNormalTileIdMap);
  TMap<unsigned short>::Done(&CWorldManager::m_cCatapultTileIdMap);
  TMap<T_GFX_MAP_ELEMENT>::Done(&CWorldManager::m_cRenderMap);
  TMap<unsigned char>::Done(&CWorldManager::m_cFlagMap);
  TMap<unsigned short>::Done(&CWorldManager::m_cMapObjectMap);
  TMap<unsigned short>::Done(&CWorldManager::m_cDecoObjectMap);
  TMap<unsigned char>::Done(&CWorldManager::m_cResourceMap);
  TMap<unsigned char>::Done(&CWorldManager::m_cWalkCount5MoveCost3Map);
  result = (void *)TMap<unsigned char>::Done(&CWorldManager::m_cFogMap);
  if ( !CWorldManager::m_pHelpObjectMap )
    return result;
  result = TSparseMap<unsigned char>::`scalar deleting destructor'(
             (Concurrency::details::_Condition_variable *)CWorldManager::m_pHelpObjectMap,
             1u);
  CWorldManager::m_pHelpObjectMap = 0;
  return result;
}


// address=[0x16a26d0]
// Decompiled from char __cdecl CWorldManager::LoadMap(struct S4::CMapFile *a1, int a2)
static bool __cdecl CWorldManager::LoadMap(class S4::CMapFile &,int) {
  
  __int16 v2; // ax
  unsigned __int8 *v4; // [esp+8h] [ebp-14h] BYREF
  int i; // [esp+Ch] [ebp-10h]
  int v6; // [esp+18h] [ebp-4h]

  CWorldManager::Construct(a2);
  TMap<unsigned char>::TMap<unsigned char>(&v4);
  v6 = 0;
  TMap<unsigned char>::Init(CWorldManager::m_iWidthHeight);
  TMap<unsigned char>::LoadMap((void **)&v4, a1, 0xD2u, CWorldManager::m_iWidthHeight);
  for ( i = 0; i < CWorldManager::m_iWorldIdxMax; ++i )
  {
    v2 = ITiling::OwnerPseudoTileId(v4[i]);
    CWorldManager::StartUpOwner(i, v2);
  }
  TMap<unsigned char>::Done(&v4);
  v6 = -1;
  TMap<unsigned char>::~TMap<unsigned char>();
  memset(CWorldManager::m_cCatapultTileIdMap, 0, 2 * CWorldManager::m_iWorldIdxMax);
  TMap<T_GFX_MAP_ELEMENT>::LoadMap(a1, 200, CWorldManager::m_iWidthHeight);
  TMap<unsigned char>::LoadMap((void **)&CWorldManager::m_cFlagMap, a1, 0xCDu, CWorldManager::m_iWidthHeight);
  TMap<unsigned short>::LoadMap((void **)&CWorldManager::m_cMapObjectMap, a1, 0xCAu, CWorldManager::m_iWidthHeight);
  TMap<unsigned short>::LoadMap((void **)&CWorldManager::m_cDecoObjectMap, a1, 0xC9u, CWorldManager::m_iWidthHeight);
  TMap<unsigned char>::LoadMap((void **)&CWorldManager::m_cResourceMap, a1, 0xCFu, CWorldManager::m_iWidthHeight);
  TMap<unsigned char>::LoadMap(
    (void **)&CWorldManager::m_cWalkCount5MoveCost3Map,
    a1,
    0xD1u,
    CWorldManager::m_iWidthHeight);
  TSparseMap<unsigned char>::LoadMap((void *)CWorldManager::m_pHelpObjectMap, a1, 0xCCu);
  (**(void (__cdecl ***)(int))g_pTiling)(a2);
  return 1;
}


// address=[0x16a28b0]
// Decompiled from char __cdecl CWorldManager::SaveMap(struct S4::CMapFile *a1)
static bool __cdecl CWorldManager::SaveMap(class S4::CMapFile &) {
  
  int v1; // eax
  CTile *v2; // eax
  char v3; // al
  int v5; // [esp+4h] [ebp-14h] BYREF
  int i; // [esp+8h] [ebp-10h]
  int v7; // [esp+14h] [ebp-4h]

  TMap<unsigned char>::TMap<unsigned char>(&v5);
  v7 = 0;
  TMap<unsigned char>::Init(CWorldManager::m_iWidthHeight);
  for ( i = 0; i < CWorldManager::m_iWorldIdxMax; ++i )
  {
    v1 = CWorldManager::NormalTileId(i);
    v2 = (CTile *)ITiling::Tile(v1);
    v3 = CTile::OwnerId(v2);
    *(_BYTE *)(i + v5) = v3;
  }
  TMap<unsigned char>::SaveMap(a1, 210, CWorldManager::m_iWidthHeight);
  v7 = -1;
  TMap<unsigned char>::~TMap<unsigned char>();
  TMap<T_GFX_MAP_ELEMENT>::SaveMap(a1, 200, CWorldManager::m_iWidthHeight);
  TMap<unsigned char>::SaveMap(a1, 205, CWorldManager::m_iWidthHeight);
  TMap<unsigned short>::SaveMap(a1, 202, CWorldManager::m_iWidthHeight);
  TMap<unsigned short>::SaveMap(a1, 201, CWorldManager::m_iWidthHeight);
  TMap<unsigned char>::SaveMap(a1, 207, CWorldManager::m_iWidthHeight);
  TMap<unsigned char>::SaveMap(a1, 209, CWorldManager::m_iWidthHeight);
  TSparseMap<unsigned char>::SaveMap(a1, 204);
  return 1;
}


// address=[0x16a2a20]
// Decompiled from void __cdecl CWorldManager::LoadGfxData(struct S4::CMapFile *a1, unsigned __int16 a2, int a3)
static void __cdecl CWorldManager::LoadGfxData(class S4::CMapFile &,int,int) {
  
  __int16 v3; // ax
  unsigned __int8 *v4; // [esp+0h] [ebp-30h]
  int v5; // [esp+4h] [ebp-2Ch] BYREF
  int v6; // [esp+8h] [ebp-28h] BYREF
  int j; // [esp+Ch] [ebp-24h]
  _DWORD *v8; // [esp+10h] [ebp-20h]
  int k; // [esp+14h] [ebp-1Ch]
  _DWORD *v10; // [esp+18h] [ebp-18h]
  int v11; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  int v13; // [esp+24h] [ebp-Ch]
  unsigned __int8 *v14; // [esp+28h] [ebp-8h]
  unsigned __int8 v15; // [esp+2Fh] [ebp-1h]

  CWorldManager::Construct(a3);
  v10 = 0;
  v14 = 0;
  v6 = 0;
  v10 = S4::CMapFile::LoadChunk(a1, a2, 0, &v6, 0);
  v5 = 0;
  v14 = (unsigned __int8 *)S4::CMapFile::LoadChunk(a1, 6u, 0, &v5, 0);
  if ( !v10 && BBSupportDbgReport(2, "World\\World.cpp", 878, "pGfxMapElements != NULL") == 1 )
    __debugbreak();
  if ( !v14 && BBSupportDbgReport(2, "World\\World.cpp", 879, "pMapElements != NULL") == 1 )
    __debugbreak();
  v4 = v14;
  v13 = 0;
  for ( i = 0; i < a3; ++i )
  {
    for ( j = 0; j < a3; ++j )
    {
      v8 = v10;
      *(_DWORD *)(CWorldManager::m_cRenderMap + 4 * v13) = *v10;
      if ( CWorldManager::IsWater(v13) )
        v3 = ITiling::OwnerPseudoTileId(0);
      else
        v3 = ITiling::OwnerPseudoTileId(v14[1]);
      CWorldManager::StartUpOwner(v13, v3);
      v15 = v14[2];
      if ( (*((_BYTE *)v8 + 2) & 0x40) != 0 )
        v15 |= 4u;
      if ( (v15 & 2) != 0 )
      {
        CWorldManager::SetMoveCostsBits(v13, 7);
      }
      else if ( *((_BYTE *)v8 + 1) == 28 )
      {
        CWorldManager::SetMoveCostsBits(v13, 1);
      }
      else if ( *((_BYTE *)v8 + 1) == 29 )
      {
        CWorldManager::SetMoveCostsBits(v13, 0);
        CWorldManager::SetMoveCount(v13, 15);
      }
      else
      {
        CWorldManager::SetMoveCostsBits(v13, 2);
      }
      *(_BYTE *)(v13 + CWorldManager::m_cFlagMap) = v15;
      v14 += 4;
      ++v10;
      ++v13;
    }
  }
  (**(void (__thiscall ***)(void *, int, int, int, int, void *, int, int))g_pTiling)(
    g_pTiling,
    a3,
    CWorldManager::m_cRenderMap,
    CWorldManager::m_cFlagMap,
    CWorldManager::m_cNormalTileIdMap,
    CWorldManager::m_cCatapultTileIdMap,
    CWorldManager::m_cFogMap,
    1);
  S4::CMapFile::CloseChunk(a1, a2, 0);
  v14 = v4;
  for ( i = 0; i < a3; ++i )
  {
    for ( k = 0; k < a3; ++k )
    {
      v11 = *v14;
      if ( v11 && v11 != 209 && v11 != 210 && v11 != 162 && v11 != 211 )
        CDecoObjMgr::AddDecoObjWithoutFlags(&g_cDecoObjMgr, k, i, v11, 0, 1);
      if ( v14[3] )
        CWorldManager::SetResource(k, i, v14[3] & 0xF0, v14[3] & 0xF);
      v14 += 4;
    }
  }
  S4::CMapFile::CloseChunk(a1, 6u, 0);
}


// address=[0x16a2d60]
// Decompiled from void __cdecl CWorldManager::IncreaseWalkCount(int a1)
static void __cdecl CWorldManager::IncreaseWalkCount(int) {
  
  int v1; // eax
  int v2; // eax
  int v3; // [esp-8h] [ebp-10h]
  int v4; // [esp-8h] [ebp-10h]
  int v5; // [esp+4h] [ebp-4h]

  if ( (CWorldManager::Ground(a1) & 0xF0) == 0x10 )
  {
    v5 = CWorldManager::MoveCount(a1);
    if ( v5 < 248 )
    {
      CWorldManager::SetMoveCount(a1, v5 + 1);
      if ( CWorldManager::MoveCount(a1) == 10 )
      {
        CWorldManager::SetMoveCostsBits(a1, 1);
        v3 = CWorldManager::Y(a1);
        v1 = CWorldManager::X(a1);
        if ( IGfxEngine::CanChangeGround((IGfxEngine *)g_pGfxEngine, v1, v3, 28) )
        {
          CWorldManager::SetGroundTypeOnly(a1, 28);
          IGfxEngine::UpdateWorldPosition((IGfxEngine *)g_pGfxEngine, a1);
        }
      }
      if ( CWorldManager::MoveCount(a1) == 15 )
      {
        CWorldManager::SetMoveCostsBits(a1, 0);
        v4 = CWorldManager::Y(a1);
        v2 = CWorldManager::X(a1);
        if ( IGfxEngine::CanChangeGround((IGfxEngine *)g_pGfxEngine, v2, v4, 29) )
        {
          CWorldManager::SetGroundTypeOnly(a1, 29);
          IGfxEngine::UpdateWorldPosition((IGfxEngine *)g_pGfxEngine, a1);
        }
      }
    }
  }
}


// address=[0x16a2e90]
// Decompiled from void __cdecl CWorldManager::DecreaseWalkCount(int a1)
static void __cdecl CWorldManager::DecreaseWalkCount(int) {
  
  int v1; // eax
  int v2; // eax
  int v3; // [esp-8h] [ebp-10h]
  int v4; // [esp-8h] [ebp-10h]
  int v5; // [esp+4h] [ebp-4h]

  if ( (CWorldManager::Ground(a1) & 0xF0) == 0x10 )
  {
    v5 = CWorldManager::MoveCount(a1);
    if ( v5 > 0 )
    {
      CWorldManager::SetMoveCount(a1, v5 - 1);
      if ( CWorldManager::MoveCount(a1) == 10 )
      {
        CWorldManager::SetMoveCostsBits(a1, 1);
        v3 = CWorldManager::Y(a1);
        v1 = CWorldManager::X(a1);
        if ( IGfxEngine::CanChangeGround((IGfxEngine *)g_pGfxEngine, v1, v3, 28) )
        {
          CWorldManager::SetGroundTypeOnly(a1, 28);
          IGfxEngine::UpdateWorldPosition((IGfxEngine *)g_pGfxEngine, a1);
        }
      }
      if ( CWorldManager::MoveCount(a1) == 6 )
      {
        CWorldManager::SetMoveCostsBits(a1, 2);
        v4 = CWorldManager::Y(a1);
        v2 = CWorldManager::X(a1);
        if ( IGfxEngine::CanChangeGround((IGfxEngine *)g_pGfxEngine, v2, v4, 16) )
        {
          CWorldManager::SetGroundTypeOnly(a1, 16);
          IGfxEngine::UpdateWorldPosition((IGfxEngine *)g_pGfxEngine, a1);
        }
      }
    }
  }
}


// address=[0x16a2fc0]
// Decompiled from unsigned int __cdecl CWorldManager::SetPileId(int a1, int a2)
static void __cdecl CWorldManager::SetPileId(int,int) {
  
  *(_WORD *)(CWorldManager::m_cDecoObjectMap + 2 * a1) = a2;
  if ( a2 <= 0 )
  {
    CWorldManager::SetMoveCostsBits(a1, 2);
    return CWorldManager::ClearFlagBits(a1, 2);
  }
  else
  {
    CWorldManager::SetMoveCostsBits(a1, 7);
    return CWorldManager::SetFlagBits(a1, 2u);
  }
}


// address=[0x16a3020]
// Decompiled from int __cdecl CWorldManager::CheckBlockable(int a1, int a2)
static int __cdecl CWorldManager::CheckBlockable(int,int) {
  
  int v3; // [esp+4h] [ebp-Ch]
  int v4; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  if ( !CWorldManager::InInnerWorld2(a1, a2)
    && BBSupportDbgReport(2, "World\\World.cpp", 1013, "InInnerWorld2(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v4 = CWorldManager::Index(a1, a2);
  if ( CWorldManager::MapObjectId(v4) )
    return 0;
  for ( i = 1; i < 7; ++i )
  {
    v3 = v4 + CWorldManager::SurroundingHexPointRelIndex(i);
    if ( (unsigned int)(CWorldManager::MapObjectId(v3) - 1) <= 5 )
      return 0;
  }
  return 1;
}


// address=[0x16a30e0]
// Decompiled from int __cdecl CWorldManager::SetGround(int a1, int a2, int a3)
static void __cdecl CWorldManager::SetGround(int,int,int) {
  
  int v4; // [esp+0h] [ebp-4h]

  v4 = CWorldManager::Index(a1, a2);
  CWorldManager::SetGroundTypeOnly(v4, a3);
  if ( CLandscapeProperties::IsBlockedLand((CLandscapeProperties *)&g_cLandscapeProperties, a3) )
    return (*(int (__thiscall **)(void *, int, int, int))(*(_DWORD *)g_pTiling + 12))(g_pTiling, a1, a2, v4);
  (*(void (__thiscall **)(void *, int, int, int))(*(_DWORD *)g_pTiling + 20))(g_pTiling, a1, a2, v4);
  return CWorldManager::SetMoveCostsBits(2, 2);
}


// address=[0x16a3170]
// Decompiled from int __cdecl CWorldManager::SetOwner(int a1, int a2)
static void __cdecl CWorldManager::SetOwner(int,int) {
  
  int v2; // ecx
  int v3; // edx
  int v4; // ecx
  int v5; // ecx
  int v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  int v13; // ecx
  CTile *v14; // eax
  int v15; // eax
  int result; // eax
  _BYTE *v17; // ecx
  int v18; // [esp+24h] [ebp-1C76Ch]
  int v19; // [esp+44h] [ebp-1C74Ch]
  int v20; // [esp+48h] [ebp-1C748h]
  int v21; // [esp+4Ch] [ebp-1C744h]
  int v22; // [esp+50h] [ebp-1C740h]
  int v23; // [esp+58h] [ebp-1C738h]
  int v24; // [esp+5Ch] [ebp-1C734h]
  bool v25; // [esp+64h] [ebp-1C72Ch]
  char v26; // [esp+68h] [ebp-1C728h]
  int v27; // [esp+7Ch] [ebp-1C714h]
  int v28; // [esp+80h] [ebp-1C710h]
  int v29; // [esp+84h] [ebp-1C70Ch]
  int v30; // [esp+8Ch] [ebp-1C704h]
  int v31; // [esp+90h] [ebp-1C700h]
  int v32; // [esp+94h] [ebp-1C6FCh]
  int v33; // [esp+98h] [ebp-1C6F8h]
  int v34; // [esp+A4h] [ebp-1C6ECh] BYREF
  int v35; // [esp+A8h] [ebp-1C6E8h]
  int v36; // [esp+ACh] [ebp-1C6E4h]
  int v37; // [esp+B0h] [ebp-1C6E0h]
  int v38; // [esp+B4h] [ebp-1C6DCh]
  int v39; // [esp+B8h] [ebp-1C6D8h]
  int v40; // [esp+BCh] [ebp-1C6D4h]
  int v41; // [esp+C0h] [ebp-1C6D0h]
  int v42; // [esp+C4h] [ebp-1C6CCh]
  int v43; // [esp+D0h] [ebp-1C6C0h]
  int v44; // [esp+D4h] [ebp-1C6BCh]
  int v45; // [esp+D8h] [ebp-1C6B8h]
  int v46; // [esp+DCh] [ebp-1C6B4h]
  int v47; // [esp+E0h] [ebp-1C6B0h] BYREF
  int v48; // [esp+E4h] [ebp-1C6ACh]
  int v49; // [esp+E8h] [ebp-1C6A8h]
  int m; // [esp+F0h] [ebp-1C6A0h]
  int v51; // [esp+F4h] [ebp-1C69Ch]
  unsigned __int16 *v52; // [esp+100h] [ebp-1C690h]
  int v53; // [esp+104h] [ebp-1C68Ch]
  int v54; // [esp+108h] [ebp-1C688h]
  int j; // [esp+10Ch] [ebp-1C684h]
  Grid *v56; // [esp+110h] [ebp-1C680h]
  int v57; // [esp+114h] [ebp-1C67Ch]
  int i; // [esp+118h] [ebp-1C678h]
  int k; // [esp+11Ch] [ebp-1C674h]
  int v60; // [esp+120h] [ebp-1C670h]
  unsigned int v61; // [esp+124h] [ebp-1C66Ch]
  __int64 v62; // [esp+128h] [ebp-1C668h]
  _BYTE v63[112211]; // [esp+1138h] [ebp-1B658h] BYREF

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "World\\World.cpp", 447, "InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( CSpiralOffsets::MaxGridDistance(40) > 50
    && BBSupportDbgReport(
         2,
         "World\\World.cpp",
         459,
         "g_cSpiralOffsets.MaxGridDistance(MAX_INFLU_RADIUS) <= MAX_INFLU_DIST") == 1 )
  {
    __debugbreak();
  }
  memset(v63, 0, sizeof(v63));
  v43 = 0;
  v51 = 0;
  if ( a1 - 100 < 1 )
    v24 = 1 - a1;
  else
    v24 = -100;
  if ( a1 + 100 > CWorldManager::Width(v24) - 2 )
    v23 = CWorldManager::Width(v2) - 2 - a1;
  else
    v23 = 100;
  if ( a2 - 100 < 1 )
  {
    v2 = 1 - a2;
    v38 = 1 - a2;
  }
  else
  {
    v38 = -100;
  }
  v36 = v38;
  if ( a2 + 100 > CWorldManager::Height(v2, v38) - 2 )
    v37 = CWorldManager::Height(v4, v3) - 2 - a2;
  else
    v37 = 100;
  v21 = v37;
  v46 = CWorldManager::Index(a1, v36 + a2);
  LODWORD(v62) = v36;
  while ( (int)v62 <= v21 )
  {
    HIDWORD(v62) = v24;
    while ( SHIDWORD(v62) <= v23 )
    {
      v35 = HIDWORD(v62) + v46;
      if ( !CWorldManager::InInnerWorld1(HIDWORD(v62) + a1, v62 + a2)
        && BBSupportDbgReport(2, "World\\World.cpp", 497, "InInnerWorld1(_iX + iDX, _iY + iDY)") == 1 )
      {
        __debugbreak();
      }
      v6 = CWorldManager::Index(HIDWORD(v62) + a1, v62 + a2);
      if ( v6 != v35 && BBSupportDbgReport(2, "World\\World.cpp", 498, "Index(_iX + iDX, _iY + iDY) == iWorldIdx") == 1 )
        __debugbreak();
      v48 = CWorldManager::BuildingId(v35);
      if ( v48 )
      {
        v52 = (unsigned __int16 *)CBuildingMgr::operator[](v48);
        v47 = 0;
        v34 = 0;
        if ( (unsigned __int8)CBuilding::HaveInhabitant() )
        {
          v22 = IEntity::Type(v52);
          CWorldManager::GetBuildingInfluenceInfo(v22, &v47, &v34);
        }
        if ( v47 > 0 )
        {
          v7 = v34 + 50;
          if ( v7 >= Grid::Distance((Grid *)HIDWORD(v62), v62) )
          {
            v60 = IEntity::OwnerId((unsigned __int8 *)v52);
            if ( (v60 > 8 || v60 < 1)
              && BBSupportDbgReport(
                   2,
                   "World\\World.cpp",
                   530,
                   "(iOwnerId >= PLAYER_FIRST) & (iOwnerId <= PLAYER_LAST)") == 1 )
            {
              __debugbreak();
            }
            if ( !v62 )
            {
              v43 = CBuilding::EnsignPackedXY(v52);
              v51 = IEntity::OwnerId((unsigned __int8 *)v52);
            }
            if ( Grid::InQuadrat((Grid *)(HIDWORD(v62) + 50), v62 + 50, 101) )
            {
              v63[1111 * (_DWORD)v62 + 56100 + 11 * HIDWORD(v62)] = -1;
              v63[1111 * (_DWORD)v62 + 56100 + 11 * HIDWORD(v62) + v60] = -1;
              v63[1111 * (_DWORD)v62 + 56110 + 11 * HIDWORD(v62)] = v60;
            }
            v20 = HIDWORD(v62) + 50;
            v19 = v62 + 50;
            for ( i = 1; i <= v47; ++i )
            {
              v56 = (Grid *)(v20 + CSpiralOffsets::DeltaX(i));
              v57 = v19 + CSpiralOffsets::DeltaY(i);
              if ( Grid::InQuadrat(v56, v57, 101) )
              {
                v61 = (unsigned __int8)v63[1111 * v57 + 11 * (_DWORD)v56 + v60];
                v8 = CSpiralOffsets::Radius(i);
                v61 += 50 - v8;
                if ( v61 > 0xFE )
                  v61 = 254;
                v63[1111 * v57 + 11 * (_DWORD)v56 + v60] = v61;
                if ( v61 > (unsigned __int8)v63[1111 * v57 + 11 * (_DWORD)v56] )
                {
                  v63[1111 * v57 + 11 * (_DWORD)v56] = v61;
                  v63[1111 * v57 + 10 + 11 * (_DWORD)v56] = v60;
                }
              }
            }
          }
        }
      }
      v5 = ++HIDWORD(v62);
    }
    v9 = CWorldManager::Width(v5);
    v46 += v9;
    v5 = v62 + 1;
    LODWORD(v62) = v62 + 1;
  }
  if ( a1 - 50 < 1 )
    v33 = 1 - a1;
  else
    v33 = -50;
  if ( a1 + 50 > CWorldManager::Width(v33) - 2 )
    v32 = CWorldManager::Width(v10) - 2 - a1;
  else
    v32 = 50;
  if ( a2 - 50 < 1 )
  {
    v10 = 1 - a2;
    v31 = 1 - a2;
  }
  else
  {
    v31 = -50;
  }
  if ( a2 + 50 > CWorldManager::Height(v10, v31) - 2 )
    v30 = CWorldManager::Height(v12, v11) - 2 - a2;
  else
    v30 = 50;
  v44 = CWorldManager::Index(a1, v31 + a2);
  for ( j = v31; j <= v30; ++j )
  {
    for ( k = v33; k <= v32; ++k )
    {
      v29 = k + v44;
      if ( !CWorldManager::InInnerWorld1(k + a1, j + a2)
        && BBSupportDbgReport(2, "World\\World.cpp", 610, "InInnerWorld1(_iX + iDX, _iY + iDY)") == 1 )
      {
        __debugbreak();
      }
      if ( CWorldManager::Index(k + a1, j + a2) != v29
        && BBSupportDbgReport(2, "World\\World.cpp", 611, "Index(_iX + iDX, _iY + iDY) == iWorldIdx") == 1 )
      {
        __debugbreak();
      }
      v28 = ITiling::NormalTileId(v29);
      v14 = (CTile *)ITiling::Tile(v28);
      v45 = CTile::OwnerId(v14);
      if ( v28 < 10 )
        v27 = 192;
      else
        v27 = 128;
      v45 |= v27;
      v63[1111 * j + 56109 + 11 * k] = v45;
      v13 = k + 1;
    }
    v15 = CWorldManager::Width(v13);
    v44 += v15;
    v13 = j + 1;
  }
  result = CSpiralOffsets::Last(40);
  v18 = result;
  for ( m = 0; m <= v18; ++m )
  {
    v53 = CSpiralOffsets::DeltaX(m);
    v54 = CSpiralOffsets::DeltaY(m);
    if ( (v53 < -50 || v53 > 50)
      && BBSupportDbgReport(2, "World\\World.cpp", 703, "(iDX >= -MAX_INFLU_DIST) && (iDX <= MAX_INFLU_DIST)") == 1 )
    {
      __debugbreak();
    }
    if ( (v54 < -50 || v54 > 50)
      && BBSupportDbgReport(2, "World\\World.cpp", 704, "(iDY >= -MAX_INFLU_DIST) && (iDY <= MAX_INFLU_DIST)") == 1 )
    {
      __debugbreak();
    }
    result = (unsigned __int8)v63[1111 * v54 + 56109 + 11 * v53];
    v26 = v63[1111 * v54 + 56109 + 11 * v53];
    if ( v26 < 0 )
    {
      v49 = v26 & 0x3F;
      v42 = v63[1111 * v54 + 56110 + 11 * v53] & 0x3F;
      v40 = v53 + a1;
      v41 = v54 + a2;
      v39 = CWorldManager::Index(v53 + a1, v54 + a2);
      if ( v42 )
      {
        result = CWorldManager::SetFlagBits(v39, 0x80u);
        if ( !v49 || (v17 = &v63[1111 * v54 + 56100 + 11 * v53], result = (unsigned __int8)v17[v49], !v17[v49]) )
        {
          if ( v49 != v42 )
          {
            v25 = v49 != 0;
            if ( CWorldManager::FlagBits(v39, 8u) != 0 && v25 )
              CBuildingMgr::DestroyBuilding((CBuildingMgr *)g_cBuildingMgr, v40, v41, 0);
            result = CWorldManager::SetOwnerId(v40, v41, v42);
          }
        }
      }
      else
      {
        result = CWorldManager::ClearFlagBits(v39, 128);
      }
    }
  }
  return result;
}


// address=[0x16a4060]
// Decompiled from void __cdecl CWorldManager::SetTowerBits(int a1, int a2, int a3, int a4)
static void __cdecl CWorldManager::SetTowerBits(int,int,int,int) {
  
  int v4; // [esp+4h] [ebp-18h] BYREF
  int v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h] BYREF
  int i; // [esp+18h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "World\\World.cpp", 411, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  v8 = 0;
  v4 = 0;
  CWorldManager::GetBuildingInfluenceInfo(a3, &v8, &v4);
  if ( v8 > 0 )
  {
    for ( i = 0; i <= v8; ++i )
    {
      v6 = a1 + CSpiralOffsets::DeltaX(i);
      v7 = a2 + CSpiralOffsets::DeltaY(i);
      if ( (unsigned __int8)CWorldManager::InWorld(v6, v7) )
      {
        v5 = CWorldManager::Index(v6, v7);
        if ( ITiling::OwnerId(v5) == a4 )
          CWorldManager::SetFlagBits(v5, 0x80u);
      }
    }
  }
}


// address=[0x16a4170]
// Decompiled from void __cdecl CWorldManager::TraceLine(int a1, int a2, int a3, int a4)
static void __cdecl CWorldManager::TraceLine(int,int,int,int) {
  
  int v4; // [esp+0h] [ebp-24h]
  int v5; // [esp+4h] [ebp-20h]
  int v6; // [esp+8h] [ebp-1Ch]
  int v7; // [esp+Ch] [ebp-18h]
  int v8; // [esp+10h] [ebp-14h]
  int v9; // [esp+14h] [ebp-10h]
  int m; // [esp+18h] [ebp-Ch]
  int v11; // [esp+18h] [ebp-Ch]
  int j; // [esp+18h] [ebp-Ch]
  int v13; // [esp+18h] [ebp-Ch]
  int v14; // [esp+1Ch] [ebp-8h]
  int k; // [esp+1Ch] [ebp-8h]
  int v16; // [esp+1Ch] [ebp-8h]
  int i; // [esp+1Ch] [ebp-8h]
  int v18; // [esp+20h] [ebp-4h]
  int v19; // [esp+20h] [ebp-4h]
  int v20; // [esp+20h] [ebp-4h]
  int v21; // [esp+20h] [ebp-4h]

  v5 = a1;
  v4 = a3;
  v8 = a2;
  v6 = a4;
  if ( a3 < a1 )
  {
    v5 = a3;
    v4 = a1;
    v8 = a4;
    v6 = a2;
  }
  v7 = v4 - v5;
  v9 = v6 - v8;
  if ( v6 - v8 < 0 )
    v9 = v8 - v6;
  if ( v9 >= v7 || v6 < v8 )
  {
    if ( v9 < v7 || v6 < v8 )
    {
      if ( v9 >= v7 || v6 >= v8 )
      {
        v21 = -(v9 >> 1);
        v13 = v4;
        for ( i = v6; i <= v8; ++i )
        {
          CWorldManager::SetHelperObject(v13, i, 17);
          v21 += v7;
          if ( v21 >= 0 )
          {
            --v13;
            v21 -= v9;
          }
        }
      }
      else
      {
        v20 = -(v7 >> 1);
        v16 = v8;
        for ( j = v5; j <= v4; ++j )
        {
          CWorldManager::SetHelperObject(j, v16, 17);
          v20 += v9;
          if ( v20 >= 0 )
          {
            --v16;
            v20 -= v7;
          }
        }
      }
    }
    else
    {
      v19 = -(v9 >> 1);
      v11 = v5;
      for ( k = v8; k <= v6; ++k )
      {
        CWorldManager::SetHelperObject(v11, k, 17);
        v19 += v7;
        if ( v19 >= 0 )
        {
          ++v11;
          v19 -= v9;
        }
      }
    }
  }
  else
  {
    v18 = -(v7 >> 1);
    v14 = v8;
    for ( m = v5; m <= v4; ++m )
    {
      CWorldManager::SetHelperObject(m, v14, 17);
      v18 += v9;
      if ( v18 >= 0 )
      {
        ++v14;
        v18 -= v7;
      }
    }
  }
}


// address=[0x16a4380]
// Decompiled from void *__cdecl CWorldManager::GetMiniMapColor(int a1)
static struct SGfxColor * __cdecl CWorldManager::GetMiniMapColor(unsigned int) {
  
  int v1; // eax
  int v3; // eax
  int v4; // [esp-8h] [ebp-14h]
  int LocalPlayerId; // [esp-4h] [ebp-10h]
  int v6; // [esp-4h] [ebp-10h]
  int v7; // [esp+0h] [ebp-Ch]
  int v8; // [esp+4h] [ebp-8h]
  unsigned __int8 *v9; // [esp+8h] [ebp-4h]

  v8 = CWorldManager::MapObjectId(a1);
  if ( v8 > 0 )
  {
    v9 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v8);
    if ( v9 )
    {
      if ( IEntity::OwnerId(v9) > 0 )
      {
        if ( IEntity::FlagBits(v9, (EntityFlag)0x10000000u) )
        {
          LocalPlayerId = CPlayerManager::GetLocalPlayerId();
          v1 = IEntity::ObjType(v9);
          if ( CMinimapHandler::GetObjectColor(v1, (struct SGfxColor *)&unk_462C980, 0, LocalPlayerId) )
            return &unk_462C980;
        }
        else
        {
          v6 = IEntity::OwnerId(v9);
          v4 = IEntity::WarriorType();
          v3 = IEntity::ObjType(v9);
          if ( CMinimapHandler::GetObjectColor(v3, (struct SGfxColor *)&unk_462C980, v4, v6) )
            return &unk_462C980;
        }
      }
    }
  }
  if ( !(unsigned __int8)CMinimapHandler::IsEcoSectorEnabled() )
    return 0;
  v7 = ITiling::OwnerId(a1);
  if ( v7 <= 0 )
    return 0;
  CMinimapHandler::GetEcoSectorColor(v7, (struct SGfxColor *)&unk_462C980);
  return &unk_462C980;
}


// address=[0x16a4480]
// Decompiled from int __cdecl CWorldManager::WorldSetNumberOfNextLine(int a1)
static void __cdecl CWorldManager::WorldSetNumberOfNextLine(int) {
  
  return TSparseMap<unsigned char>::SetNewLine(a1);
}


// address=[0x16a44a0]
// Decompiled from int __cdecl CWorldManager::WorldGetIconObjectByX(int a1)
static unsigned char __cdecl CWorldManager::WorldGetIconObjectByX(int) {
  
  return TSparseMap<unsigned char>::GetByX(a1);
}


// address=[0x16a44c0]
// Decompiled from int __cdecl CWorldManager::WorldOwnerId(int a1)
static int __cdecl CWorldManager::WorldOwnerId(int) {
  
  int v1; // eax
  CTile *v2; // eax

  v1 = ITiling::NormalTileId(a1);
  v2 = (CTile *)ITiling::Tile(v1);
  return CTile::OwnerId(v2);
}


// address=[0x16a44f0]
// Decompiled from int __cdecl CWorldManager::WorldOwnerIdColor(int a1)
static int __cdecl CWorldManager::WorldOwnerIdColor(int) {
  
  int v1; // eax
  CTile *v2; // eax
  int v3; // eax

  v1 = ITiling::NormalTileId(a1);
  v2 = (CTile *)ITiling::Tile(v1);
  v3 = CTile::OwnerId(v2);
  return CPlayerManager::Color(v3) + 1;
}


// address=[0x16a4520]
// Decompiled from void *__cdecl CWorldManager::Construct(int a1)
static void __cdecl CWorldManager::Construct(int) {
  
  void *result; // eax
  int v2; // [esp+10h] [ebp-18h]

  if ( a1 <= 0 && BBSupportDbgReport(2, "World\\World.cpp", 118, "_iWidthHeight > 0") == 1 )
    __debugbreak();
  if ( a1 > 1024 && BBSupportDbgReport(2, "World\\World.cpp", 119, "_iWidthHeight <= 1024") == 1 )
    __debugbreak();
  CWorldManager::m_iWidthHeight = a1;
  CWorldManager::m_iWorldIdxMax = a1 * a1;
  CNeighborRelIndices::Init((CNeighborRelIndices *)CWorldManager::m_cNeighborRelIndices, a1);
  CSurroundingHexPointsIndices::Init(
    (CSurroundingHexPointsIndices *)&CWorldManager::m_cSurroundingHexPointsIndices,
    CWorldManager::m_iWidthHeight);
  TMap<unsigned short>::Init(CWorldManager::m_iWidthHeight);
  TMap<unsigned short>::Init(CWorldManager::m_iWidthHeight);
  TMap<T_GFX_MAP_ELEMENT>::Init(CWorldManager::m_iWidthHeight);
  TMap<unsigned char>::Init(CWorldManager::m_iWidthHeight);
  TMap<unsigned short>::Init(CWorldManager::m_iWidthHeight);
  TMap<unsigned short>::Init(CWorldManager::m_iWidthHeight);
  TMap<unsigned char>::Init(CWorldManager::m_iWidthHeight);
  TMap<unsigned char>::Init(CWorldManager::m_iWidthHeight);
  TMap<unsigned char>::Init(CWorldManager::m_iWidthHeight);
  if ( CWorldManager::m_pHelpObjectMap )
    TSparseMap<unsigned char>::`scalar deleting destructor'(
      (Concurrency::details::_Condition_variable *)CWorldManager::m_pHelpObjectMap,
      1u);
  result = operator new(0x24u);
  if ( result )
  {
    result = (void *)TSparseMap<unsigned char>::TSparseMap<unsigned char>(
                       CWorldManager::m_iWidthHeight,
                       CWorldManager::m_iWidthHeight,
                       0);
    v2 = (int)result;
  }
  else
  {
    v2 = 0;
  }
  CWorldManager::m_pHelpObjectMap = v2;
  return result;
}


// address=[0x16a46f0]
// Decompiled from int __cdecl CWorldManager::SetGroundInit(_Cnd_t a1, int a2)
static void __cdecl CWorldManager::SetGroundInit(int,int) {
  
  int result; // eax

  CWorldManager::SetGroundTypeOnly(a1, a2);
  if ( CLandscapeProperties::IsBlockedLand((CLandscapeProperties *)&g_cLandscapeProperties, a2) )
    CWorldManager::SetBlockedLandEx(a1);
  else
    CWorldManager::ClearBlockedLandEx(a1);
  if ( CLandscapeProperties::IsSlowType((CLandscapeProperties *)&g_cLandscapeProperties, a2) )
    result = CWorldManager::SetMoveCostsBits((int)a1, 3);
  else
    result = CWorldManager::SetMoveCostsBits((int)a1, 2);
  if ( a2 == 28 || a2 == 29 )
    return CWorldManager::SetMoveCostsBits((int)a1, 0);
  return result;
}


// address=[0x16a4790]
// Decompiled from int *__cdecl CWorldManager::GetBuildingInfluenceInfo(int *a1, int *a2, int *a3)
static void __cdecl CWorldManager::GetBuildingInfluenceInfo(int,int &,int &) {
  
  int *result; // eax

  result = a1;
  if ( a1 == (int *)46 )
  {
    *a2 = 3499;
    *a3 = 37;
  }
  else if ( a1 == (int *)47 )
  {
    result = a2;
    *a2 = 3999;
    *a3 = 40;
  }
  else if ( a1 == (int *)48 )
  {
    *a2 = 4999;
    result = a3;
    *a3 = 44;
  }
  else
  {
    *a2 = 0;
    *a3 = 0;
  }
  return result;
}


// address=[0x16a4800]
// Decompiled from int __cdecl CWorldManager::CheckSettlerId(int a1)
static int __cdecl CWorldManager::CheckSettlerId(int) {
  
  unsigned __int8 *v3; // [esp+4h] [ebp-4h]

  v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a1);
  if ( v3 && IEntity::ObjType(v3) == 1 )
    return a1;
  else
    return 0;
}


// address=[0x16a4840]
// Decompiled from int __cdecl CWorldManager::CheckBuildingId(int a1)
static int __cdecl CWorldManager::CheckBuildingId(int) {
  
  unsigned __int8 *v3; // [esp+4h] [ebp-4h]

  v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a1);
  if ( v3 && IEntity::ObjType(v3) == 8 )
    return a1;
  else
    return 0;
}


// address=[0x16a4880]
// Decompiled from int __cdecl CWorldManager::CheckPileId(int a1)
static int __cdecl CWorldManager::CheckPileId(int) {
  
  unsigned __int8 *v3; // [esp+4h] [ebp-4h]

  v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a1);
  if ( v3 && IEntity::ObjType(v3) == 16 )
    return a1;
  else
    return 0;
}


// address=[0x16a6b40]
// Decompiled from int __cdecl CWorldManager::ClearBlockedLandEx(_Cnd_t a1)
static void __cdecl CWorldManager::ClearBlockedLandEx(int) {
  
  return CWorldManager::ClearFlagBits((int)a1, 1);
}


// address=[0x16a7880]
// Decompiled from int __cdecl CWorldManager::SetBlockedLandEx(_Cnd_t a1)
static void __cdecl CWorldManager::SetBlockedLandEx(int) {
  
  return CWorldManager::SetFlagBits((int)a1, 1u);
}


// address=[0x16a78a0]
// Decompiled from int __cdecl CWorldManager::SetGroundTypeOnly(int a1, char a2)
static void __cdecl CWorldManager::SetGroundTypeOnly(int,int) {
  
  int result; // eax

  result = a1;
  *(_BYTE *)(CWorldManager::m_cRenderMap + 4 * a1 + 1) = a2;
  return result;
}


// address=[0x16a78e0]
// Decompiled from int __cdecl CWorldManager::StartUpOwner(int a1, __int16 a2)
static void __cdecl CWorldManager::StartUpOwner(int,int) {
  
  int result; // eax

  result = a1;
  *(_WORD *)(CWorldManager::m_cNormalTileIdMap + 2 * a1) = a2;
  return result;
}


// address=[0x462bcd8]
// [Decompilation failed for static int CWorldManager::m_iWidthHeight]

// address=[0x462bcdc]
// [Decompilation failed for static int CWorldManager::m_iWorldIdxMax]

// address=[0x462bce0]
// [Decompilation failed for static class CNeighborRelIndices CWorldManager::m_cNeighborRelIndices]

// address=[0x462bd10]
// [Decompilation failed for static class CSurroundingHexPointsIndices CWorldManager::m_cSurroundingHexPointsIndices]

// address=[0x462c854]
// [Decompilation failed for static class TSparseMap<unsigned char> * CWorldManager::m_pHelpObjectMap]

// address=[0x462c85c]
// [Decompilation failed for static class TMap<unsigned short> CWorldManager::m_cNormalTileIdMap]

// address=[0x462c960]
// [Decompilation failed for static class TMap<unsigned short> CWorldManager::m_cCatapultTileIdMap]

// address=[0x462c964]
// [Decompilation failed for static class TMap<struct T_GFX_MAP_ELEMENT> CWorldManager::m_cRenderMap]

// address=[0x462c968]
// [Decompilation failed for static class TMap<unsigned char> CWorldManager::m_cFlagMap]

// address=[0x462c96c]
// [Decompilation failed for static class TMap<unsigned short> CWorldManager::m_cMapObjectMap]

// address=[0x462c970]
// [Decompilation failed for static class TMap<unsigned short> CWorldManager::m_cDecoObjectMap]

// address=[0x462c974]
// [Decompilation failed for static class TMap<unsigned char> CWorldManager::m_cResourceMap]

// address=[0x462c978]
// [Decompilation failed for static class TMap<unsigned char> CWorldManager::m_cWalkCount5MoveCost3Map]

// address=[0x462c97c]
// [Decompilation failed for static class TMap<unsigned char> CWorldManager::m_cFogMap]

