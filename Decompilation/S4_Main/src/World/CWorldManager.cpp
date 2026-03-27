#include "CWorldManager.h"

#include "helper.h"
#include "CBB/CBBSupport.h"
#include "Defines/AI.h"
#include "Defines/Buildings.h"
#include "Defines/Object.h"
#include "Defines/Players.h"
#include "Defines/World.h"
#include "LoadSave/CMapFile.h"
#include "MapObjects/IEntity.h"
#include "MapObjects/CMapObjectMgr.h"
#include "MapObjects/T_GFX_MAP_ELEMENT.h"
#include "Pathing/CTile.h"
#include "Pathing/ITiling.h"

// Definitions for class CWorldManager

CWorldManager g_cWorld{};

// address=[0x12fd0f0]
// Decompiled from int __cdecl CWorldManager::FlagBits(int a1, unsigned __int8 a2)
unsigned int __cdecl CWorldManager::FlagBits(int a1, unsigned int a2) {
  return a2 & CWorldManager::m_cFlagMap.m_pData[a1];
}


// address=[0x12fd2d0]
// Decompiled from bool __cdecl CWorldManager::InWorld(unsigned int _iX, unsigned int _iY)
bool __cdecl CWorldManager::InWorld(int _iX, int _iY) {
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]

  if(_iX < CWorldManager::m_iWidthHeight)
    v4 = -1;
  else
    v4 = 0;
  if(_iY < CWorldManager::m_iWidthHeight)
    v3 = -1;
  else
    v3 = 0;
  return (v3 & v4) != 0;
}


// address=[0x12fd350]
// Decompiled from int __cdecl CWorldManager::Index(int x, int y)
int __cdecl CWorldManager::Index(int x, int y) {
  return x + CWorldManager::m_iWidthHeight * y;
}


// address=[0x12fd440]
// Decompiled from int __cdecl CWorldManager::NormalTileId(int a1)
int __cdecl CWorldManager::NormalTileId(int a1) {
  return *&CWorldManager::m_cNormalTileIdMap.m_pData[a1];
}


// address=[0x12fd4a0]
// Decompiled from int __cdecl CWorldManager::ObjectId(int _iX, int _iY)
int __cdecl CWorldManager::ObjectId(int _iX, int _iY) {
  return *&CWorldManager::m_cDecoObjectMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY];
}


// address=[0x12fd620]
// Decompiled from int __cdecl CWorldManager::SectorId(int _iTileId)
int __cdecl CWorldManager::SectorId(int _iTileId) {
  return ITiling::Tile(CWorldManager::NormalTileId(_iTileId)).SectorId();
}


// address=[0x1306950]
// Decompiled from int __cdecl CWorldManager::SectorId(int _iX, int _iY)
int __cdecl CWorldManager::SectorId(int _iX, int _iY) {
  int iTileId = CWorldManager::Index(_iX, _iY);
  return ITiling::Tile(CWorldManager::NormalTileId(iTileId)).SectorId();
}


// address=[0x130eff0]
// Decompiled from int __cdecl CWorldManager::Ground(int _iIndex)
int __cdecl CWorldManager::Ground(int _iIndex) {
  return CWorldManager::m_cRenderMap.m_pData[_iIndex].m_uGroundType;
}


// address=[0x130f080]
// Decompiled from bool __cdecl CWorldManager::InWorldPackedXY(int _iXY)
bool __cdecl CWorldManager::InWorldPackedXY(int _iXY) {
  // eax
  // [esp-4h] [ebp-4h]

  unsigned int iY = Y16X16::UnpackYFast(_iXY);
  unsigned int iX = Y16X16::UnpackXFast(_iXY);
  return CWorldManager::InWorld(iX, iY);
}


// address=[0x130f0b0]
// Decompiled from bool __cdecl CWorldManager::IsBlockedLand(int a1)
bool __cdecl CWorldManager::IsBlockedLand(int a1) {
  return (CWorldManager::m_cFlagMap.m_pData[a1] & 1) != 0;
}


// address=[0x130f1f0]
// Decompiled from int __cdecl CWorldManager::NeighborRelIndex(int a1)
int __cdecl CWorldManager::NeighborRelIndex(int a1) {
  return CWorldManager::m_cNeighborRelIndices[a1];
}


// address=[0x130f3c0]
// Decompiled from int __cdecl CWorldManager::SettlerId(int a1, int a2)
int __cdecl CWorldManager::SettlerId(int a1, int a2) {
  if(CWorldManager::m_cMapObjectMap.m_pData[a1 + CWorldManager::m_iWidthHeight * a2])
    return CWorldManager::CheckSettlerId(CWorldManager::m_cMapObjectMap.m_pData[a1 + CWorldManager::m_iWidthHeight * a2]);
  else
    return 0;
}


// address=[0x130f540]
// Decompiled from int CWorldManager::Width()
int __cdecl CWorldManager::Width(void) {
  return CWorldManager::m_iWidthHeight;
}


// address=[0x131c950]
// Decompiled from int __cdecl CWorldManager::Flags(int a1)
unsigned int __cdecl CWorldManager::Flags(int a1) {
  return CWorldManager::m_cFlagMap.m_pData[a1];
}


// address=[0x131c970]
// Decompiled from int __cdecl CWorldManager::GroundHeight(int a1)
int __cdecl CWorldManager::GroundHeight(int a1) {
  return CWorldManager::m_cRenderMap.m_pData[a1].m_uGroundHeight;
}


// address=[0x131c9b0]
// Decompiled from int CWorldManager::Height()
int __cdecl CWorldManager::Height(void) {
  return CWorldManager::m_iWidthHeight;
}


// address=[0x131c9c0]
// Decompiled from int __cdecl CWorldManager::Resource(int a1)
int __cdecl CWorldManager::Resource(int a1) {
  return CWorldManager::m_cResourceMap.m_pData[a1];
}


// address=[0x1326db0]
// Decompiled from int __cdecl CWorldManager::EcoSectorId(int _iX, int _iY)
int __cdecl CWorldManager::EcoSectorId(int _iX, int _iY) {
  // eax
  CTile *v3; // eax
  // [esp+0h] [ebp-4h]

  int v2 = CWorldManager::Index(_iX, _iY);
  int v5 = CWorldManager::NormalTileId(v2);
  return ITiling::Tile(v5).EcoSectorId();
}


// address=[0x1335f70]
// Decompiled from int __cdecl CWorldManager::FlagBits(int _iX, int _iY, unsigned __int8 _iFlags)
unsigned int __cdecl CWorldManager::FlagBits(int _iX, int _iY, unsigned int _iFlags) {
  return _iFlags & CWorldManager::m_cFlagMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY];
}


// address=[0x13367c0]
// Decompiled from int __cdecl CWorldManager::ResourceAmount(int _iX, int _iY, int _iResourceType)
int __cdecl CWorldManager::ResourceAmount(int _iX, int _iY, int _iResourceType) {
  // [esp+4h] [ebp-4h]

  unsigned __int8 v5 = CWorldManager::m_cResourceMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY];
  if((v5 & 0xF0) == _iResourceType)
    return v5 & 0xF;
  else
    return 0;
}


// address=[0x1346600]
// Decompiled from int __cdecl CWorldManager::BuildingId(int _iX, int _iY)
int __cdecl CWorldManager::BuildingId(int _iX, int _iY) {
  if(CWorldManager::m_cMapObjectMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY])
    return CWorldManager::CheckBuildingId(CWorldManager::m_cMapObjectMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY]);
  else
    return 0;
}


// address=[0x1346660]
// Decompiled from int __cdecl CWorldManager::EcoSectorId(int _iTileId)
int __cdecl CWorldManager::EcoSectorId(int _iTileId) {
  CTile *v1; // eax
  // [esp+0h] [ebp-4h]

  int v3 = CWorldManager::NormalTileId(_iTileId);
  return ITiling::Tile(v3).EcoSectorId();
}


// address=[0x1346760]
// Decompiled from int __cdecl CWorldManager::Ground(int _iX, int _iY)
int __cdecl CWorldManager::Ground(int _iX, int _iY) {
  return CWorldManager::m_cRenderMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY].m_uGroundType;
}


// address=[0x1351a40]
// Decompiled from int __cdecl CWorldManager::BuildingId(int _iTileId)
int __cdecl CWorldManager::BuildingId(int _iTileId) {
  if(CWorldManager::m_cMapObjectMap.m_pData[_iTileId])
    return CWorldManager::CheckBuildingId(CWorldManager::m_cMapObjectMap.m_pData[_iTileId]);
  else
    return 0;
}


// address=[0x1351b70]
// Decompiled from int __cdecl CWorldManager::MapObjectId(int _iTileId)
int __cdecl CWorldManager::MapObjectId(int _iTileId) {
  return CWorldManager::m_cMapObjectMap.m_pData[_iTileId];
}


// address=[0x1351b90]
// Decompiled from int __cdecl CWorldManager::MapObjectId(int _iX, int _iY)
int __cdecl CWorldManager::MapObjectId(int _iX, int _iY) {
  return CWorldManager::m_cMapObjectMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY];
}


// address=[0x1351bc0]
// Decompiled from int __cdecl CWorldManager::MoveCostsBits(int _iTileId)
int __cdecl CWorldManager::MoveCostsBits(int _iTileId) {
  return CWorldManager::m_cWalkCount5MoveCost3Map.m_pData[_iTileId] & 0b111;
}


// address=[0x1351be0]
// Decompiled from int __cdecl CWorldManager::MoveCount(int _iTileId)
int __cdecl CWorldManager::MoveCount(int _iTileId) {
  return (CWorldManager::m_cWalkCount5MoveCost3Map.m_pData[_iTileId] & 0b11111000) >> 3;
}


// address=[0x1351c90]
// Decompiled from int __cdecl CWorldManager::ObjectId(int _iTileId)
int __cdecl CWorldManager::ObjectId(int _iTileId) {
  return CWorldManager::m_cDecoObjectMap.m_pData[_iTileId];
}


// address=[0x1351cb0]
// Decompiled from int __cdecl CWorldManager::OccupyingEntityId(int _iTileId)
int __cdecl CWorldManager::OccupyingEntityId(int _iTileId) {
  if(CWorldManager::FlagBits(_iTileId, 1u))
    return 0;
  else
    return CWorldManager::MapObjectId(_iTileId);
}


// address=[0x1351d00]
// Decompiled from int __cdecl CWorldManager::OccupyingEntityId(int _iX, int _iY)
int __cdecl CWorldManager::OccupyingEntityId(int _iX, int _iY) {
  return CWorldManager::OccupyingEntityId(_iX + CWorldManager::m_iWidthHeight * _iY);
}


// address=[0x141d7b0]
// Decompiled from int __cdecl CWorldManager::ClearFlagBits(int _iX, int _iY, char _uMask)
void __cdecl CWorldManager::ClearFlagBits(int _iX, int _iY, unsigned int _uMask) {
  // eax
  BB_ASSERT((_uMask & FLAG_BLOCKED_LAND) == 0);
  CWorldManager::m_cFlagMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY] &= ~_uMask;
}


// address=[0x141d830]
// Decompiled from unsigned __int8 *__cdecl CWorldManager::ClearFlagBits(int _iTileId, char _uMask)
void __cdecl CWorldManager::ClearFlagBits(int _iTileId, unsigned int _uMask) {
  // eax
  BB_ASSERT((_uMask & FLAG_BLOCKED_LAND) == 0);
  CWorldManager::m_cFlagMap.m_pData[_iTileId] &= ~_uMask;
}


// address=[0x141d8d0]
// Decompiled from bool __cdecl CWorldManager::InInnerWorld16(int _iX, int _iY)
bool __cdecl CWorldManager::InInnerWorld16(int _iX, int _iY) {
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]
  // [esp+18h] [ebp+Ch]

  unsigned int _iYa = _iY - 16;
  if(_iX - 16 < (unsigned int) (CWorldManager::m_iWidthHeight - 32))
    v4 = -1;
  else
    v4 = 0;
  if(_iYa < CWorldManager::m_iWidthHeight - 32)
    v3 = -1;
  else
    v3 = 0;
  return (v3 & v4) != 0;
}


// address=[0x141d9d0]
// Decompiled from bool __cdecl CWorldManager::IsWater(int _iTileId)
bool __cdecl CWorldManager::IsWater(int _iTileId) {
  return CLandscapeProperties::IsWater(CWorldManager::m_cRenderMap.m_pData[_iTileId + 1]);
}


// address=[0x141da40]
// Decompiled from unsigned __int8 *__cdecl CWorldManager::SetFlagBits(int _iX, int _iY, char _uMask)
void __cdecl CWorldManager::SetFlagBits(int _iX, int _iY, unsigned int _uMask) {
  // eax
  BB_ASSERT((_uMask & FLAG_BLOCKED_LAND) == 0);
  CWorldManager::m_cFlagMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY] |= _uMask;
}


// address=[0x141dac0]
// Decompiled from unsigned int __cdecl CWorldManager::SetFlagBits(int _iTileId, unsigned int _uMask)
void __cdecl CWorldManager::SetFlagBits(int _iTileId, unsigned int _uMask) {
  // eax
  BB_ASSERT((_uMask & FLAG_BLOCKED_LAND) == 0);
  CWorldManager::m_cFlagMap.m_pData[_iTileId] |= _uMask;
}


// address=[0x141dba0]
// Decompiled from int __cdecl CWorldManager::X(int _iTileId)
int __cdecl CWorldManager::X(int _iTileId) {
  return _iTileId % CWorldManager::m_iWidthHeight;
}


// address=[0x141dbc0]
// Decompiled from int __cdecl CWorldManager::Y(int _iTileId)
int __cdecl CWorldManager::Y(int _iTileId) {
  return _iTileId / CWorldManager::m_iWidthHeight;
}


// address=[0x1439bd0]
// Decompiled from int __cdecl CWorldManager::Index(int _iXY)
int __cdecl CWorldManager::Index(int _iXY) {
  return Y16X16::UnpackXFast(_iXY) + CWorldManager::m_iWidthHeight * Y16X16::UnpackYFast(_iXY);
}


// address=[0x1447770]
// Decompiled from int __cdecl CWorldManager::PileId(int _iTileId)
int __cdecl CWorldManager::PileId(int _iTileId) {
  if(CWorldManager::m_cDecoObjectMap.m_pData[_iTileId])
    return CWorldManager::CheckPileId(CWorldManager::m_cDecoObjectMap.m_pData[_iTileId]);
  else
    return 0;
}


// address=[0x1447860]
// Decompiled from int __cdecl CWorldManager::SettlerId(int _iTileId)
int __cdecl CWorldManager::SettlerId(int _iTileId) {
  if(CWorldManager::m_cMapObjectMap.m_pData[_iTileId])
    return CWorldManager::CheckSettlerId(CWorldManager::m_cMapObjectMap.m_pData[_iTileId]);
  else
    return 0;
}


// address=[0x1452a70]
// Decompiled from int __cdecl CWorldManager::OwnerId(int _iX, int _iY)
int __cdecl CWorldManager::OwnerId(int _iX, int _iY) {
  // eax
  CTile *v3; // eax
  // [esp+0h] [ebp-4h]

  int v2 = CWorldManager::Index(_iX, _iY);
  int v5 = CWorldManager::NormalTileId(v2);
  return ITiling::Tile(v5).OwnerId();
}


// address=[0x1460470]
// Decompiled from unsigned int CWorldManager::ClearHelperObject()
void __cdecl CWorldManager::ClearHelperObject(void) {
  CWorldManager::m_pHelpObjectMap.Clear();
}


// address=[0x14605e0]
// Decompiled from int __cdecl CWorldManager::GetHelperObject(unsigned int a1, int a2)
int __cdecl CWorldManager::GetHelperObject(int a1, int a2) {
  return CWorldManager::m_pHelpObjectMap.Get(a1, a2);
}


// address=[0x1460a20]
// Decompiled from int __cdecl CWorldManager::SetHelperObject(unsigned int a1, int a2, char a3)
void __cdecl CWorldManager::SetHelperObject(int a1, int a2, int a3) {
  CWorldManager::m_pHelpObjectMap.Set(a1, a2, &a3);
}


// address=[0x146aea0]
// Decompiled from int __cdecl CWorldManager::ResourceAmount(int _iX, int _iY)
int __cdecl CWorldManager::ResourceAmount(int _iX, int _iY) {
  // [esp+4h] [ebp-4h]

  unsigned __int8 v4 = CWorldManager::m_cResourceMap.m_pData[_iX];
  if((v4 & 0xF0) == _iY)
    return v4 & 0xF;
  else
    return 0;
}


// address=[0x146aef0]
// Decompiled from int __cdecl CWorldManager::ResourceType(int _iTileId)
int __cdecl CWorldManager::ResourceType(int _iTileId) {
  return CWorldManager::m_cResourceMap.m_pData[_iTileId] & 0xF0;
}


// address=[0x146af10]
// Decompiled from void __cdecl CWorldManager::SetObjectId(int _iTileId, __int16 _iObjectId)
void __cdecl CWorldManager::SetObjectId(int _iTileId, int _iObjectId) {
  *&CWorldManager::m_cDecoObjectMap.m_pData[_iTileId] = _iObjectId;
}


// address=[0x146af30]
// Decompiled from void __cdecl CWorldManager::SetResource(int _iTileId, int _iResourceType, int _iAmount)
void __cdecl CWorldManager::SetResource(int _iTileId, int _iResourceType, int _iAmount) {
  CWorldManager::m_cResourceMap.m_pData[_iTileId] = _iAmount | _iResourceType;
}


// address=[0x1470bb0]
// Decompiled from int __cdecl CWorldManager::PileId(int _iX, int _iY)
int __cdecl CWorldManager::PileId(int _iX, int _iY) {
  if(CWorldManager::m_cDecoObjectMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY])
    return CWorldManager::CheckPileId(CWorldManager::m_cDecoObjectMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY]);
  else
    return 0;
}


// address=[0x1470e10]
// Decompiled from int __cdecl CWorldManager::SurroundingHexPointRelIndex(int _iTileId)
int __cdecl CWorldManager::SurroundingHexPointRelIndex(int _iTileId) {
  return CSurroundingHexPointsIndices::operator[](CWorldManager::m_cSurroundingHexPointsIndices, _iTileId);
}


// address=[0x1486fb0]
// Decompiled from int __cdecl CWorldManager::GroundHeight(int _iX, int _iY)
int __cdecl CWorldManager::GroundHeight(int _iX, int _iY) {
  return CWorldManager::m_cRenderMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY].m_uGroundHeight;
}


// address=[0x14aabe0]
// Decompiled from unsigned __int8 *CWorldManager::GetDecoObjectPtr()
unsigned short * __cdecl CWorldManager::GetDecoObjectPtr(void) {
  return CWorldManager::m_cDecoObjectMap.m_pData;
}


// address=[0x14aac20]
// Decompiled from struct T_GFX_MAP_ELEMENT *CWorldManager::GetLandscapePtr()
struct T_GFX_MAP_ELEMENT * __cdecl CWorldManager::GetLandscapePtr(void) {
  return CWorldManager::m_cRenderMap.m_pData;
}


// address=[0x14aac30]
// Decompiled from WORD *CWorldManager::GetMapObjectPtr()
unsigned short * __cdecl CWorldManager::GetMapObjectPtr(void) {
  return CWorldManager::m_cMapObjectMap.m_pData;
}


// address=[0x14d87f0]
// Decompiled from void __cdecl CWorldManager::SetMapObjectId(int _iTileId, WORD _iObjectId)
void __cdecl CWorldManager::SetMapObjectId(int _iTileId, int _iObjectId) {
  CWorldManager::m_cMapObjectMap.m_pData[_iTileId] = _iObjectId;
}


// address=[0x14d8870]
// Decompiled from int __cdecl CWorldManager::SetSettlerId(int _iTileId, __int16 _iObjectId)
void __cdecl CWorldManager::SetSettlerId(int _iTileId, int _iObjectId) {
  return CWorldManager::SetMapObjectId(_iTileId, _iObjectId);
}


// address=[0x14dfef0]
// Decompiled from bool __cdecl CWorldManager::InWorld(unsigned int _iTileId)
bool __cdecl CWorldManager::InWorld(int _iTileId) {
  return _iTileId < CWorldManager::m_iWorldIdxMax;
}


// address=[0x14dff70]
// Decompiled from bool __cdecl CWorldManager::IsPositionFreeForSettler(int _iTileId)
bool __cdecl CWorldManager::IsPositionFreeForSettler(int _iTileId) {
  return (CWorldManager::m_cFlagMap.m_pData[_iTileId] & FLAG_BLOCKED_LAND) == 0
         && !CWorldManager::m_cMapObjectMap.m_pData[_iTileId];
}


// address=[0x14dffc0]
// Decompiled from bool __cdecl CWorldManager::IsPositionFreeForSettler(int _iX, int _iY)
bool __cdecl CWorldManager::IsPositionFreeForSettler(int _iX, int _iY) {
  return CWorldManager::IsPositionFreeForSettler(_iX + CWorldManager::m_iWidthHeight * _iY);
}


// address=[0x14e3040]
// Decompiled from void __cdecl CWorldManager::SetMapObjectId(int x, int y, WORD id)
void __cdecl CWorldManager::SetMapObjectId(int x, int y, int id) {
  CWorldManager::m_cMapObjectMap.m_pData[x + CWorldManager::m_iWidthHeight * y] = id;
}


// address=[0x14e3070]
// Decompiled from int __cdecl CWorldManager::SetSettlerId(int x, int y, __int16 id)
void __cdecl CWorldManager::SetSettlerId(int x, int y, int id) {
  return CWorldManager::SetMapObjectId(x, y, id);
}


// address=[0x14e6880]
// Decompiled from void __cdecl CWorldManager::SetMoveCostsBits(int _iTileId, char _iCost)
void __cdecl CWorldManager::SetMoveCostsBits(int _iTileId, int _iCost) {
  CWorldManager::m_cWalkCount5MoveCost3Map.m_pData[_iTileId] = _iCost & 0b111 | CWorldManager::m_cWalkCount5MoveCost3Map.m_pData[_iTileId] & 0b11111000;
}


// address=[0x14eb2e0]
// Decompiled from int __cdecl CWorldManager::ClearBlockedPosition(int a1, int a2)
void __cdecl CWorldManager::ClearBlockedPosition(int a1, int a2) {
  return g_pTiling->ClearBlockedLand(a1, a2);
}


// address=[0x14eb6f0]
// Decompiled from int __cdecl CWorldManager::SetBlockedPosition(int a1, int a2)
void __cdecl CWorldManager::SetBlockedPosition(int a1, int a2) {
  return g_pTiling->SetBlockedLand(a1, a2);
}


// address=[0x14eb720]
// Decompiled from void __cdecl CWorldManager::SetMoveCount(int _iTileId, char _iCount)
void __cdecl CWorldManager::SetMoveCount(int _iTileId, int _iCount) {
  CWorldManager::m_cWalkCount5MoveCost3Map.m_pData[_iTileId] = (_iCount << 3) | CWorldManager::m_cWalkCount5MoveCost3Map.m_pData[_iTileId] & 0b111;
}


// address=[0x14eb750]
// Decompiled from int __cdecl CWorldManager::SetOwnerId(int a1, int a2, int a3)
void __cdecl CWorldManager::SetOwnerId(int a1, int a2, int a3) {
  return g_pTiling->ChangeOwner(a1, a2, a3);
}


// address=[0x14fd2d0]
// Decompiled from void __cdecl CWorldManager::DecreaseGroundHeight(int _iX, int _iY)
void __cdecl CWorldManager::DecreaseGroundHeight(int _iX, int _iY) {
  CWorldManager::m_cRenderMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY].m_uGroundHeight--;
}


// address=[0x14fd770]
// Decompiled from void __cdecl CWorldManager::IncreaseGroundHeight(int _iX, int _iY)
void __cdecl CWorldManager::IncreaseGroundHeight(int _iX, int _iY) {
  CWorldManager::m_cRenderMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY].m_uGroundHeight++;
}


// address=[0x14fd7c0]
// Decompiled from bool __cdecl CWorldManager::IsWater(int _iX, int _iY)
bool __cdecl CWorldManager::IsWater(int _iX, int _iY) {
  return CLandscapeProperties::IsWater(CWorldManager::m_cRenderMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY].m_uGroundType);
}


// address=[0x14fdd70]
// Decompiled from int __cdecl CWorldManager::OwnerId(int _iTileId)
int __cdecl CWorldManager::OwnerId(int _iTileId) {
  CTile *v1; // eax
  // [esp+0h] [ebp-4h]

  int v3 = CWorldManager::NormalTileId(_iTileId);
  return ITiling::Tile(v3).OwnerId();
}


// address=[0x1506770]
// Decompiled from void __cdecl CWorldManager::SetObjectId(int _iX, int _iY, __int16 _iObjectId)
void __cdecl CWorldManager::SetObjectId(int _iX, int _iY, int _iObjectId) {
  CWorldManager::m_cDecoObjectMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY] = _iObjectId;
}


// address=[0x1516110]
// Decompiled from void __cdecl CWorldManager::SetResource(int _iX, int _iY, int _iResourceType, int _iAmount)
void __cdecl CWorldManager::SetResource(int _iX, int _iY, int _iResourceType, int _iAmount) {
  CWorldManager::m_cResourceMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY] = _iAmount | _iResourceType;
}


// address=[0x151aa50]
// Decompiled from bool __cdecl CWorldManager::InInnerWorld2(int _iX, int _iY)
bool __cdecl CWorldManager::InInnerWorld2(int _iX, int _iY) {
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]
  // [esp+18h] [ebp+Ch]

  unsigned int _iYa = _iY - 2;
  if(_iX - 2 < (unsigned int) (CWorldManager::m_iWidthHeight - 4))
    v4 = -1;
  else
    v4 = 0;
  if(_iYa < CWorldManager::m_iWidthHeight - 4)
    v3 = -1;
  else
    v3 = 0;
  return (v3 & v4) != 0;
}


// address=[0x151ab00]
// Decompiled from int __cdecl CWorldManager::ResourceType(int _iX, int _iY)
int __cdecl CWorldManager::ResourceType(int _iX, int _iY) {
  return CWorldManager::m_cResourceMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY] & 0xF0;
}


// address=[0x151ab30]
// Decompiled from int __cdecl CWorldManager::ShadingGradient(int a1)
int __cdecl CWorldManager::ShadingGradient(int _iTileId) {
  return CWorldManager::m_cRenderMap.m_pData[_iTileId].GetGradient();
}


// address=[0x1575b60]
// Decompiled from int __cdecl CWorldManager::CatapultTileId(int _iX, int _iY)
int __cdecl CWorldManager::CatapultTileId(int _iX, int _iY) {
  return CWorldManager::m_cCatapultTileIdMap.m_pData[_iX + CWorldManager::m_iWidthHeight * _iY];
}


// address=[0x15a7a50]
// Decompiled from bool __cdecl CWorldManager::InInnerWorld1(int _iX, int _iY)
bool __cdecl CWorldManager::InInnerWorld1(int _iX, int _iY) {
  int v3; // [esp+4h] [ebp-8h]
  int v4; // [esp+8h] [ebp-4h]
  // [esp+18h] [ebp+Ch]

  unsigned int _iYa = _iY - 1;
  if(_iX - 1 < (unsigned int) (CWorldManager::m_iWidthHeight - 2))
    v4 = -1;
  else
    v4 = 0;
  if(_iYa < CWorldManager::m_iWidthHeight - 2)
    v3 = -1;
  else
    v3 = 0;
  return (v3 & v4) != 0;
}


// address=[0x15d6110]
// Decompiled from int __cdecl CWorldManager::CatapultTileId(int _iTileId)
int __cdecl CWorldManager::CatapultTileId(int _iTileId) {
  return CWorldManager::m_cCatapultTileIdMap.m_pData[_iTileId];
}


// address=[0x15fe660]
// Decompiled from bool __cdecl CWorldManager::IsBlockedWater(int _iTileId)
bool __cdecl CWorldManager::IsBlockedWater(int _iTileId) {
  return (CWorldManager::m_cFlagMap.m_pData[_iTileId] & FLAG_BLOCKED_WATER) != 0;
}


// address=[0x16a2580]
// Decompiled from CWorldManager *__thiscall CWorldManager::CWorldManager(CWorldManager *this)
CWorldManager::CWorldManager(void) {
  CWorldManager::m_iWidthHeight = 0;
  CWorldManager::m_iWorldIdxMax = 0;
  CWorldManager::m_pHelpObjectMap = 0;
}


// address=[0x16a25c0]
// Decompiled from int __thiscall CWorldManager::~CWorldManager(CWorldManager *this)
CWorldManager::~CWorldManager(void) {
  CWorldManager::Destruct();
}


// address=[0x16a2610]
// Decompiled from void CWorldManager::Destruct()
void __cdecl CWorldManager::Destruct(void) {
  CWorldManager::m_iWidthHeight = 0;
  CWorldManager::m_iWorldIdxMax = 0;
  CWorldManager::m_cNormalTileIdMap.Done();
  CWorldManager::m_cCatapultTileIdMap.Done();
  CWorldManager::m_cRenderMap.Done();
  CWorldManager::m_cFlagMap.Done();
  CWorldManager::m_cMapObjectMap.Done();
  CWorldManager::m_cDecoObjectMap.Done();
  CWorldManager::m_cResourceMap.Done();
  CWorldManager::m_cWalkCount5MoveCost3Map.Done();
  CWorldManager::m_cFogMap.Done();
  if(CWorldManager::m_pHelpObjectMap) {
    delete m_pHelpObjectMap;
    CWorldManager::m_pHelpObjectMap = 0;
  }
}


// address=[0x16a26d0]
// Decompiled from char __cdecl CWorldManager::LoadMap(struct S4::CMapFile *a1, int _iWidth)
bool __cdecl CWorldManager::LoadMap(class S4::CMapFile &a1, int _iWidth) {
  // ax
  ; // [esp+8h] [ebp-14h] BYREF
  // [esp+Ch] [ebp-10h]
  // [esp+18h] [ebp-4h]

  CWorldManager::Construct(_iWidth);
  TMap<unsigned char> mOwnerMap{};
  mOwnerMap.Init(CWorldManager::m_iWidthHeight);
  mOwnerMap.LoadMap(a1, 0xD2u, CWorldManager::m_iWidthHeight);
  for(int i = 0; i < CWorldManager::m_iWorldIdxMax; ++i) {
    int v2 = ITiling::OwnerPseudoTileId(mOwnerMap.m_pData[i]);
    CWorldManager::StartUpOwner(i, v2);
  }
  mOwnerMap.Done();

  memset(CWorldManager::m_cCatapultTileIdMap.m_pData, 0, 2 * CWorldManager::m_iWorldIdxMax);
  CWorldManager::m_cRenderMap.LoadMap(a1, 200u, CWorldManager::m_iWidthHeight);
  CWorldManager::m_cFlagMap.LoadMap(a1, 205u, CWorldManager::m_iWidthHeight);
  CWorldManager::m_cMapObjectMap.LoadMap(a1, 202u, CWorldManager::m_iWidthHeight);
  CWorldManager::m_cDecoObjectMap.LoadMap(a1, 201u, CWorldManager::m_iWidthHeight);
  CWorldManager::m_cResourceMap.LoadMap(a1, 207u, CWorldManager::m_iWidthHeight);
  CWorldManager::m_cWalkCount5MoveCost3Map.LoadMap(a1, 209u, CWorldManager::m_iWidthHeight);
  CWorldManager::m_pHelpObjectMap.LoadMap(a1, 204u);
  g_pTiling->Init(
    _iWidth,
    CWorldManager::m_cRenderMap.m_pData,
    CWorldManager::m_cFlagMap.m_pData,
    CWorldManager::m_cNormalTileIdMap.m_pData,
    CWorldManager::m_cCatapultTileIdMap.m_pData,
    CWorldManager::m_cFogMap.m_pData,
    0);
  return 1;
}


// address=[0x16a28b0]
// Decompiled from char __cdecl CWorldManager::SaveMap(struct S4::CMapFile *_pMapFile)
bool __cdecl CWorldManager::SaveMap(class S4::CMapFile &_pMapFile) {
  // eax
  CTile *v2; // eax

  TMap<unsigned char> mOwnerMap{};
  mOwnerMap.Init(CWorldManager::m_iWidthHeight);
  for(int i = 0; i < CWorldManager::m_iWorldIdxMax; ++i) {
    int v1 = CWorldManager::NormalTileId(i);
    mOwnerMap.m_pData[i] = ITiling::Tile(v1).OwnerId();
  }
  mOwnerMap.SaveMap(_pMapFile, 0xD2u, CWorldManager::m_iWidthHeight);

  CWorldManager::m_cRenderMap.SaveMap(_pMapFile, 0xC8, CWorldManager::m_iWidthHeight);
  CWorldManager::m_cFlagMap.SaveMap(_pMapFile, 0xCDu, CWorldManager::m_iWidthHeight);
  CWorldManager::m_cMapObjectMap.SaveMap(_pMapFile, 0xCA, CWorldManager::m_iWidthHeight);
  CWorldManager::m_cDecoObjectMap.SaveMap(_pMapFile, 0xC9, CWorldManager::m_iWidthHeight);
  CWorldManager::m_cResourceMap.SaveMap(_pMapFile, 0xCFu, CWorldManager::m_iWidthHeight);
  CWorldManager::m_cWalkCount5MoveCost3Map.SaveMap(
    _pMapFile,
    0xD1u,
    CWorldManager::m_iWidthHeight);
  CWorldManager::m_pHelpObjectMap.SaveMap(_pMapFile, 204);
  return 1;
}

struct SGroundData {
  uint8_t m_iObjectType;
  uint8_t m_iOwner;
  uint8_t m_iOccupied;
  uint8_t m_iResource;
};


// address=[0x16a2a20]
// Decompiled from void __cdecl CWorldManager::LoadGfxData(struct S4::CMapFile *a1, unsigned __int16 a2, int _iWidth)
void __cdecl CWorldManager::LoadGfxData(class S4::CMapFile &a1, int a2, int _iWidth) {
  __int16 iOwner; // ax
  // [esp+0h] [ebp-30h]
  int v5; // [esp+4h] [ebp-2Ch] BYREF
  int v6; // [esp+8h] [ebp-28h] BYREF
  int iX; // [esp+14h] [ebp-1Ch] MAPDST
  // [esp+18h] [ebp-18h] MAPDST
  // [esp+1Ch] [ebp-14h]
  int iY; // [esp+20h] [ebp-10h]
  // [esp+24h] [ebp-Ch]
  // [esp+28h] [ebp-8h]
  // [esp+2Fh] [ebp-1h]

  CWorldManager::Construct(_iWidth);
  T_GFX_MAP_ELEMENT const *pGfxMapElements = 0;
  SGroundData const *      pMapElements = 0;

  v6 = 0;
  pGfxMapElements = reinterpret_cast<T_GFX_MAP_ELEMENT const *>(a1.LoadChunk(a2, 0, v6, 0));
  v5 = 0;
  pMapElements = (SGroundData *) a1.LoadChunk(6u, 0, v5, 0);
  BB_ASSERT(pGfxMapElements != nullptr)
  BB_ASSERT(pMapElements != nullptr)

  SGroundData const *pMapElementsStart = pMapElements;
  int                iTileId = 0;
  for(iY = 0; iY < _iWidth; ++iY) {
    for(iX = 0; iX < _iWidth; ++iX) {
      *&CWorldManager::m_cRenderMap.m_pData[iTileId] = *pGfxMapElements;
      if(CWorldManager::IsWater(iTileId))
        iOwner = ITiling::OwnerPseudoTileId(0);
      else
        iOwner = ITiling::OwnerPseudoTileId(pMapElements->m_iOwner);
      CWorldManager::StartUpOwner(iTileId, iOwner);
      uint8_t iOccupied = pMapElements->m_iOccupied;
      if((pGfxMapElements->m_uGradient & 0x40) != 0)
        iOccupied |= 4u;
      if((iOccupied & 2) != 0) {
        CWorldManager::SetMoveCostsBits(iTileId, 7);
      } else if(pGfxMapElements->m_uGroundType == GROUND_GRASS_DUSTY) {
        CWorldManager::SetMoveCostsBits(iTileId, 1);
      } else if(pGfxMapElements->m_uGroundType == GROUND_GRASS_PAVEMENT) {
        CWorldManager::SetMoveCostsBits(iTileId, 0);
        CWorldManager::SetMoveCount(iTileId, 15);
      } else {
        CWorldManager::SetMoveCostsBits(iTileId, 2);
      }
      CWorldManager::m_cFlagMap.m_pData[iTileId] = iOccupied;
      ++pMapElements;
      ++pGfxMapElements;
      ++iTileId;
    }
  }
  g_pTiling->Init(
    _iWidth,
    CWorldManager::m_cRenderMap.m_pData,
    CWorldManager::m_cFlagMap.m_pData,
    CWorldManager::m_cNormalTileIdMap.m_pData,
    CWorldManager::m_cCatapultTileIdMap.m_pData,
    CWorldManager::m_cFogMap.m_pData,
    1);
  a1.CloseChunk(a2, 0);
  pMapElements = pMapElementsStart;
  for(iY = 0; iY < _iWidth; ++iY) {
    for(iX = 0; iX < _iWidth; ++iX) {
      int iObjectID = pMapElements->m_iObjectType;
      if(iObjectID
         && iObjectID != OBJECT_WHEAT1
         && iObjectID != OBJECT_WHEAT2
         && iObjectID != OBJECT_GRAPE
         && iObjectID != OBJECT_AGAVE) {
        g_cDecoObjMgr.AddDecoObjWithoutFlags(iX, iY, iObjectID, 0, 1);
      }
      if(pMapElements->m_iResource)
        CWorldManager::SetResource(iX, iY, pMapElements->m_iResource & 0xF0, pMapElements->m_iResource & 0xF);
      ++pMapElements;
    }
  }
  a1.CloseChunk(6u, 0);
}


// address=[0x16a2d60]
// Decompiled from void __cdecl CWorldManager::IncreaseWalkCount(int _iTileId)
void __cdecl CWorldManager::IncreaseWalkCount(int _iTileId) {
  // eax
  // eax
  // [esp-8h] [ebp-10h]
  // [esp-8h] [ebp-10h]
  // [esp+4h] [ebp-4h]

  if((CWorldManager::Ground(_iTileId) & 0xF0) == GROUND_GRASS) {
    int v5 = CWorldManager::MoveCount(_iTileId);
    if(v5 < 248) {
      CWorldManager::SetMoveCount(_iTileId, v5 + 1);
      if(CWorldManager::MoveCount(_iTileId) == 10) {
        CWorldManager::SetMoveCostsBits(_iTileId, 1);
        int v3 = CWorldManager::Y(_iTileId);
        int v1 = CWorldManager::X(_iTileId);
        if(g_pGfxEngine->CanChangeGround(v1, v3, GROUND_GRASS_DUSTY)) {
          CWorldManager::SetGroundTypeOnly(_iTileId, GROUND_GRASS_DUSTY);
          g_pGfxEngine->UpdateWorldPosition(_iTileId);
        }
      }
      if(CWorldManager::MoveCount(_iTileId) == 15) {
        CWorldManager::SetMoveCostsBits(_iTileId, 0);
        int v4 = CWorldManager::Y(_iTileId);
        int v2 = CWorldManager::X(_iTileId);
        if(g_pGfxEngine->CanChangeGround(v2, v4, GROUND_GRASS_PAVEMENT)) {
          CWorldManager::SetGroundTypeOnly(_iTileId, GROUND_GRASS_PAVEMENT);
          g_pGfxEngine->UpdateWorldPosition(_iTileId);
        }
      }
    }
  }
}


// address=[0x16a2e90]
// Decompiled from void __cdecl CWorldManager::DecreaseWalkCount(int _iTileId)
void __cdecl CWorldManager::DecreaseWalkCount(int _iTileId) {
  // eax
  // eax
  // [esp-8h] [ebp-10h]
  // [esp-8h] [ebp-10h]
  // [esp+4h] [ebp-4h]

  if((CWorldManager::Ground(_iTileId) & 0xF0) == GROUND_GRASS) {
    int v5 = CWorldManager::MoveCount(_iTileId);
    if(v5 > 0) {
      CWorldManager::SetMoveCount(_iTileId, v5 - 1);
      if(CWorldManager::MoveCount(_iTileId) == 10) {
        CWorldManager::SetMoveCostsBits(_iTileId, 1);
        int v3 = CWorldManager::Y(_iTileId);
        int v1 = CWorldManager::X(_iTileId);
        if(g_pGfxEngine->CanChangeGround(v1, v3, GROUND_GRASS_DUSTY)) {
          CWorldManager::SetGroundTypeOnly(_iTileId, 0x1Cu);
          g_pGfxEngine->UpdateWorldPosition(_iTileId);
        }
      }
      if(CWorldManager::MoveCount(_iTileId) == 6) {
        CWorldManager::SetMoveCostsBits(_iTileId, 2);
        int v4 = CWorldManager::Y(_iTileId);
        int v2 = CWorldManager::X(_iTileId);
        if(g_pGfxEngine->CanChangeGround(v2, v4, GROUND_GRASS)) {
          CWorldManager::SetGroundTypeOnly(_iTileId, GROUND_GRASS);
          g_pGfxEngine->UpdateWorldPosition(_iTileId);
        }
      }
    }
  }
}


// address=[0x16a2fc0]
// Decompiled from void __cdecl CWorldManager::SetPileId(int _iTileId, int _iPileId)
void __cdecl CWorldManager::SetPileId(int _iTileId, int _iPileId) {
  CWorldManager::m_cDecoObjectMap.m_pData[_iTileId] = _iPileId;
  if(_iPileId <= 0) {
    CWorldManager::SetMoveCostsBits(_iTileId, 2);
    CWorldManager::ClearFlagBits(_iTileId, FLAG_BLOCKED_WATER);
  } else {
    CWorldManager::SetMoveCostsBits(_iTileId, 7);
    CWorldManager::SetFlagBits(_iTileId, FLAG_BLOCKED_WATER);
  }
}


// address=[0x16a3020]
// Decompiled from int __cdecl CWorldManager::CheckBlockable(int _iX, int _iY)
int __cdecl CWorldManager::CheckBlockable(int _iX, int _iY) {
  // [esp+4h] [ebp-Ch]
  // [esp+8h] [ebp-8h]
  // [esp+Ch] [ebp-4h]

  BB_ASSERT(CWorldManager::InInnerWorld2(_iX, _iY));

  int v4 = CWorldManager::Index(_iX, _iY);
  if(CWorldManager::MapObjectId(v4))
    return 0;
  for(int i = 1; i < 7; ++i) {
    int v3 = v4 + CWorldManager::SurroundingHexPointRelIndex(i);
    if((unsigned int) (CWorldManager::MapObjectId(v3) - 1) <= 5)
      return 0;
  }
  return 1;
}


// address=[0x16a30e0]
// Decompiled from void __cdecl CWorldManager::SetGround(int _iX, int _iY, int _iGroundType)
void __cdecl CWorldManager::SetGround(int _iX, int _iY, int _iGroundType) {
  // [esp+0h] [ebp-4h]

  int iTileId = CWorldManager::Index(_iX, _iY);
  CWorldManager::SetGroundTypeOnly(iTileId, _iGroundType);
  if(s_cLandscapeProperties.IsBlockedLand(_iGroundType)) {
    g_pTiling->SetBlockedLand(_iX, _iY, iTileId);
  } else {
    g_pTiling->ClearBlockedLand(_iX, _iY, iTileId);
    CWorldManager::SetMoveCostsBits(2, 2);
  }
}


// address=[0x16a3170]
// Decompiled from void __cdecl CWorldManager::SetOwner(unsigned int _iX, unsigned int _iY)
void __cdecl CWorldManager::SetOwner(int _iX, int _iY) {
  int          v2; // eax
  int          v3; // esi
  int          v4; // eax
  CTile *      v5; // eax
  int          v6; // [esp+24h] [ebp-1C76Ch]
  int          v7; // [esp+44h] [ebp-1C74Ch]
  int          v8; // [esp+48h] [ebp-1C748h]
  int          v9; // [esp+4Ch] [ebp-1C744h]
  int          v10; // [esp+50h] [ebp-1C740h]
  signed int   v11; // [esp+58h] [ebp-1C738h]
  unsigned int v12; // [esp+5Ch] [ebp-1C734h]
  bool         v13; // [esp+64h] [ebp-1C72Ch]
  char         v14; // [esp+68h] [ebp-1C728h]
  int          v15; // [esp+7Ch] [ebp-1C714h]
  int          v16; // [esp+80h] [ebp-1C710h]
  int          v17; // [esp+84h] [ebp-1C70Ch]
  signed int   v18; // [esp+8Ch] [ebp-1C704h]
  unsigned int v19; // [esp+90h] [ebp-1C700h]
  signed int   v20; // [esp+94h] [ebp-1C6FCh]
  unsigned int v21; // [esp+98h] [ebp-1C6F8h]
  int          v22; // [esp+A4h] [ebp-1C6ECh] BYREF
  int          iWorldIdx; // [esp+A8h] [ebp-1C6E8h]
  int          v24; // [esp+ACh] [ebp-1C6E4h]
  unsigned int v25; // [esp+B0h] [ebp-1C6E0h]
  unsigned int v26; // [esp+B4h] [ebp-1C6DCh]
  int          v27; // [esp+B8h] [ebp-1C6D8h]
  int          v28; // [esp+BCh] [ebp-1C6D4h]
  int          v29; // [esp+C0h] [ebp-1C6D0h]
  int          v30; // [esp+C4h] [ebp-1C6CCh]
  int          v31; // [esp+D0h] [ebp-1C6C0h]
  int          v32; // [esp+D4h] [ebp-1C6BCh]
  int          iEntityOwnerId; // [esp+D8h] [ebp-1C6B8h]
  int          v34; // [esp+DCh] [ebp-1C6B4h]
  int          v35; // [esp+E0h] [ebp-1C6B0h] BYREF
  int          a1; // [esp+E4h] [ebp-1C6ACh]
  int          v37; // [esp+E8h] [ebp-1C6A8h]
  int          iOffsetIndex; // [esp+F0h] [ebp-1C6A0h]
  int          v39; // [esp+F4h] [ebp-1C69Ch]

  int          v41; // [esp+104h] [ebp-1C68Ch]
  int          v42; // [esp+108h] [ebp-1C688h]
  signed int   j; // [esp+10Ch] [ebp-1C684h]
  int          v44; // [esp+110h] [ebp-1C680h]
  unsigned int v45; // [esp+114h] [ebp-1C67Ch]
  int          i; // [esp+118h] [ebp-1C678h]
  signed int   k; // [esp+11Ch] [ebp-1C674h]
  int          iOwnerId; // [esp+120h] [ebp-1C670h]
  unsigned int v49; // [esp+124h] [ebp-1C66Ch]
  int          iDY; // [esp+128h] [ebp-1C668h] OVERLAPPED
  int          iDX; // [esp+12Ch] [ebp-1C664h]
  _BYTE        v52[112211]; // [esp+1138h] [ebp-1B658h] BYREF

  BB_ASSERT(CWorldManager::InWorld(_iX, _iY))
  BB_ASSERT(CSpiralOffsets::MaxGridDistance(MAX_INFLU_RADIUS) <= MAX_INFLU_DIST)
  memset(v52, 0, sizeof(v52));
  v31 = 0;
  v39 = 0;
  if(_iX - 100 < 1)
    v12 = 1 - _iX;
  else
    v12 = -100;
  if(_iX + 100 > CWorldManager::Width() - 2)
    v11 = CWorldManager::Width() - 2 - _iX;
  else
    v11 = 100;
  if(_iY - 100 < 1)
    v26 = 1 - _iY;
  else
    v26 = -100;
  v24 = v26;
  if(_iY + 100 > CWorldManager::Height() - 2)
    v25 = CWorldManager::Height() - 2 - _iY;
  else
    v25 = 100;
  v9 = v25;
  v34 = CWorldManager::Index(_iX, v24 + _iY);
  for(iDY = v24; iDY <= v9; ++iDY) {
    for(iDX = v12; iDX <= v11; ++iDX) {
      iWorldIdx = iDX + v34;
      BB_ASSERT(CWorldManager::InInnerWorld1(_iX + iDX, _iY + iDY))
      BB_ASSERT(CWorldManager::Index(iDX + _iX, iDY + _iY) == iWorldIdx);
      a1 = CWorldManager::BuildingId(iWorldIdx);
      if(a1) {
        IEntity &rBuilding = CBuildingMgr[a1];
        v35 = 0;
        v22 = 0;
        if(rBuilding.HaveInhabitant()) {
          CWorldManager::GetBuildingInfluenceInfo(rBuilding.Type(), v35, v22);
        }
        if(v35 > 0) {
          v3 = v22 + 50;
          if(v3 >= Grid::Distance(iDX, iDY)) {
            iOwnerId = rBuilding.OwnerId();

            BB_ASSERT((iOwnerId >= PLAYER_FIRST) && (iOwnerId <= PLAYER_LAST))
            if(!iDY && !iDX) {
              // I dont know why, but this just does... nothing?
              v31 = rBuilding.EnsignPackedXY();
              v39 = rBuilding.OwnerId();
            }
            if(Grid::InQuadrat(iDX + 50, iDY + 50, 0x65u)) {
              v52[1111 * iDY + 56100 + 11 * iDX] = -1;
              v52[1111 * iDY + 56100 + 11 * iDX + iOwnerId] = -1;
              v52[1111 * iDY + 56110 + 11 * iDX] = iOwnerId;
            }

            v8 = iDX + 50;
            v7 = iDY + 50;
            for(i = 1; i <= v35; ++i) {
              v44 = v8 + CSpiralOffsets::DeltaX(i);
              v45 = v7 + CSpiralOffsets::DeltaY(i);
              if(Grid::InQuadrat(v44, v45, 0x65u)) {
                v49 = v52[1111 * v45 + 11 * v44 + iOwnerId];
                v4 = CSpiralOffsets::Radius(i);
                v49 += 50 - v4;
                if(v49 > 0xFE)
                  v49 = 254;
                v52[1111 * v45 + 11 * v44 + iOwnerId] = v49;
                if(v49 > v52[1111 * v45 + 11 * v44]) {
                  v52[1111 * v45 + 11 * v44] = v49;
                  v52[1111 * v45 + 10 + 11 * v44] = iOwnerId;
                }
              }
            }
          }
        }
      }
    }
    v34 += CWorldManager::Width();
  }
  if(_iX - 50 < 1)
    v21 = 1 - _iX;
  else
    v21 = -50;
  if(_iX + 50 > CWorldManager::Width() - 2)
    v20 = CWorldManager::Width() - 2 - _iX;
  else
    v20 = 50;
  if(_iY - 50 < 1)
    v19 = 1 - _iY;
  else
    v19 = -50;
  if(_iY + 50 > CWorldManager::Height() - 2)
    v18 = CWorldManager::Height() - 2 - _iY;
  else
    v18 = 50;
  v32 = CWorldManager::Index(_iX, v19 + _iY);
  for(iDY = v19; iDY <= v18; ++iDY) {
    for(iDX = v21; iDX <= v20; ++k) {
      BB_ASSERT(CWorldManager::InInnerWorld1(_iX + iDX, _iY + iDY))
      BB_ASSERT(CWorldManager::Index(iDX + _iX, iDY + _iY) == iWorldIdx);

      v16 = ITiling::NormalTileId(iDX + v32);
      iEntityOwnerId = ITiling::Tile(v16).OwnerId();
      if(v16 < 10)
        v15 = 192;
      else
        v15 = 128;
      iEntityOwnerId |= v15;
      v52[1111 * iDY + 56109 + 11 * k] = iEntityOwnerId;
    }
    v32 += CWorldManager::Width();
  }

  for(iOffsetIndex = 0; iOffsetIndex <= CSpiralOffsets::Last(40); ++iOffsetIndex) {
    iDX = CSpiralOffsets::DeltaX(iOffsetIndex);
    iDY = CSpiralOffsets::DeltaY(iOffsetIndex);
    BB_ASSERT((iDX >= -MAX_INFLU_DIST) && (iDX <= MAX_INFLU_DIST))
    BB_ASSERT((iDY >= -MAX_INFLU_DIST) && (iDY <= MAX_INFLU_DIST))

    v14 = v52[1111 * iDY + 56109 + 11 * iDX];
    if(v14 < 0) {
      v37 = v14 & 0x3F;
      v30 = v52[1111 * iDY + 56110 + 11 * iDX] & 0x3F;
      v28 = iDX + _iX;
      v29 = iDY + _iY;
      v27 = CWorldManager::Index(iDX + _iX, iDY + _iY);
      if(v30) {
        CWorldManager::SetFlagBits(v27, 0x80u);
        if((!v37 || !v52[1111 * iDY + 56100 + 11 * iDX + v37]) && v37 != v30) {
          v13 = v37 != 0;
          if(CWorldManager::FlagBits(v27, 8u) != 0 && v13)
            g_cBuildingMgr.DestroyBuilding(v28, v29, 0);
          CWorldManager::SetOwnerId(v28, v29, v30);
        }
      } else {
        CWorldManager::ClearFlagBits(v27, 128);
      }
    }
  }
}


// address=[0x16a4060]
// Decompiled from void __cdecl CWorldManager::SetTowerBits(unsigned int _iX, unsigned int _iY, int *a3, int a4)
void __cdecl CWorldManager::SetTowerBits(int _iX, int _iY, int a3, int a4) {
  int v4; // [esp+4h] [ebp-18h] BYREF
  // [esp+8h] [ebp-14h]
  // [esp+Ch] [ebp-10h]
  // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h] BYREF
  // [esp+18h] [ebp-4h]

  BB_ASSERT(CWorldManager::InWorld(_iX, _iY))

  v8 = 0;
  v4 = 0;
  CWorldManager::GetBuildingInfluenceInfo(a3, v8, v4);
  if(v8 > 0) {
    for(int i = 0; i <= v8; ++i) {
      unsigned int v6 = _iX + CSpiralOffsets::DeltaX(i);
      unsigned int v7 = _iY + CSpiralOffsets::DeltaY(i);
      if(CWorldManager::InWorld(v6, v7)) {
        int v5 = CWorldManager::Index(v6, v7);
        if(ITiling::OwnerId(v5) == a4)
          CWorldManager::SetFlagBits(v5, 0x80u);
      }
    }
  }
}


// address=[0x16a4170]
// Decompiled from void __cdecl CWorldManager::TraceLine(int a1, int a2, int a3, int a4)
void __cdecl CWorldManager::TraceLine(int a1, int a2, int a3, int a4) {
  // [esp+0h] [ebp-24h]
  // [esp+4h] [ebp-20h]
  // [esp+8h] [ebp-1Ch]
  // [esp+Ch] [ebp-18h]
  // [esp+10h] [ebp-14h]
  // [esp+14h] [ebp-10h]
  // [esp+18h] [ebp-Ch]
  // [esp+18h] [ebp-Ch]
  // [esp+18h] [ebp-Ch]
  // [esp+18h] [ebp-Ch]
  // [esp+1Ch] [ebp-8h]
  // [esp+1Ch] [ebp-8h]
  // [esp+1Ch] [ebp-8h]
  // [esp+1Ch] [ebp-8h]
  // [esp+20h] [ebp-4h]
  // [esp+20h] [ebp-4h]
  // [esp+20h] [ebp-4h]
  // [esp+20h] [ebp-4h]

  int v5 = a1;
  int v4 = a3;
  int v8 = a2;
  int v6 = a4;
  if(a3 < a1) {
    v5 = a3;
    v4 = a1;
    v8 = a4;
    v6 = a2;
  }
  int v7 = v4 - v5;
  int v9 = v6 - v8;
  if(v6 - v8 < 0)
    v9 = v8 - v6;
  if(v9 >= v7 || v6 < v8) {
    if(v9 < v7 || v6 < v8) {
      if(v9 >= v7 || v6 >= v8) {
        int          v21 = -(v9 >> 1);
        unsigned int v13 = v4;
        for(int i = v6; i <= v8; ++i) {
          CWorldManager::SetHelperObject(v13, i, 17);
          v21 += v7;
          if(v21 >= 0) {
            --v13;
            v21 -= v9;
          }
        }
      } else {
        int v20 = -(v7 >> 1);
        int v16 = v8;
        for(signed int j = v5; j <= v4; ++j) {
          CWorldManager::SetHelperObject(j, v16, 17);
          v20 += v9;
          if(v20 >= 0) {
            --v16;
            v20 -= v7;
          }
        }
      }
    } else {
      int          v19 = -(v9 >> 1);
      unsigned int v11 = v5;
      for(int k = v8; k <= v6; ++k) {
        CWorldManager::SetHelperObject(v11, k, 17);
        v19 += v7;
        if(v19 >= 0) {
          ++v11;
          v19 -= v9;
        }
      }
    }
  } else {
    int v18 = -(v7 >> 1);
    int v14 = v8;
    for(signed int m = v5; m <= v4; ++m) {
      CWorldManager::SetHelperObject(m, v14, 17);
      v18 += v9;
      if(v18 >= 0) {
        ++v14;
        v18 -= v7;
      }
    }
  }
}


// address=[0x16a4380]
// Decompiled from struct SGfxColor *__cdecl CWorldManager::GetMiniMapColor(int _iTileId)
struct SGfxColor * __cdecl CWorldManager::GetMiniMapColor(unsigned int _iTileId) {
  int v1; // eax
  int v3; // eax
  int v4; // [esp-8h] [ebp-14h]
  // [esp-4h] [ebp-10h]
  // [esp-4h] [ebp-10h]
  // [esp+0h] [ebp-Ch]
  // [esp+4h] [ebp-8h]
  // [esp+8h] [ebp-4h]

  int v8 = CWorldManager::MapObjectId(_iTileId);
  if(v8 > 0) {
    IEntity *pEntity = CMapObjectMgr::EntityPtr(v8);
    if(pEntity) {
      if(pEntity->OwnerId() > 0) {
        if(pEntity->FlagBits(EntityFlag_Ownerless)) {
          int LocalPlayerId = CPlayerManager::GetLocalPlayerId();
          if(CMinimapHandler::GetObjectColor(pEntity->ObjType(), &CWorldManager::m_sMinimapColorBuffer, 0, LocalPlayerId))
            return &CWorldManager::m_sMinimapColorBuffer;
        } else {
          if(CMinimapHandler::GetObjectColor(pEntity->ObjType(), &CWorldManager::m_sMinimapColorBuffer, pEntity->WarriorType(), pEntity->OwnerId()))
            return &CWorldManager::m_sMinimapColorBuffer;
        }
      }
    }
  }
  if(!CMinimapHandler::IsEcoSectorEnabled())
    return 0;
  int v7 = ITiling::OwnerId(_iTileId);
  if(v7 <= 0)
    return 0;
  CMinimapHandler::GetEcoSectorColor(v7, &CWorldManager::m_sMinimapColorBuffer);
  return &CWorldManager::m_sMinimapColorBuffer;
}


// address=[0x16a4480]
// Decompiled from void __cdecl CWorldManager::WorldSetNumberOfNextLine(int a1)
void __cdecl CWorldManager::WorldSetNumberOfNextLine(int a1) {
  TSparseMap<unsigned char>::SetNewLine(CWorldManager::m_pHelpObjectMap, a1);
}


// address=[0x16a44a0]
// Decompiled from char __cdecl CWorldManager::WorldGetIconObjectByX(unsigned int a1)
unsigned char __cdecl CWorldManager::WorldGetIconObjectByX(int a1) {
  return TSparseMap<unsigned char>::GetByX(CWorldManager::m_pHelpObjectMap, a1);
}


// address=[0x16a44c0]
// Decompiled from int __cdecl CWorldManager::WorldOwnerId(int _iTileId)
int __cdecl CWorldManager::WorldOwnerId(int _iTileId) {
  int          v1 = ITiling::NormalTileId(_iTileId);
  CTile const &v2 = ITiling::Tile(v1);
  return v2.OwnerId();
}


// address=[0x16a44f0]
// Decompiled from int __cdecl CWorldManager::WorldOwnerIdColor(int _iTileId)
int __cdecl CWorldManager::WorldOwnerIdColor(int _iTileId) {
  int          v1 = ITiling::NormalTileId(_iTileId);
  CTile const &v2 = ITiling::Tile(v1);
  int          v3 = v2.OwnerId();
  return CPlayerManager::Color(v3) + 1;
}


// address=[0x16a4520]
// Decompiled from void __cdecl CWorldManager::Construct(int _iWidthHeight)
void __cdecl CWorldManager::Construct(int _iWidthHeight) {
  BB_ASSERT(_iWidthHeight > 0)
  BB_ASSERT(_iWidthHeight <= 1024)

  CWorldManager::m_iWidthHeight = _iWidthHeight;
  CWorldManager::m_iWorldIdxMax = _iWidthHeight * _iWidthHeight;
  CWorldManager::m_cNeighborRelIndices.Init(_iWidthHeight);
  CWorldManager::m_cSurroundingHexPointsIndices.Init(CWorldManager::m_iWidthHeight);
  CWorldManager::m_cNormalTileIdMap.Init(CWorldManager::m_iWidthHeight);
  CWorldManager::m_cCatapultTileIdMap.Init(CWorldManager::m_iWidthHeight);
  CWorldManager::m_cRenderMap.Init(CWorldManager::m_iWidthHeight);
  CWorldManager::m_cFlagMap.Init(CWorldManager::m_iWidthHeight);
  CWorldManager::m_cMapObjectMap.Init(CWorldManager::m_iWidthHeight);
  CWorldManager::m_cDecoObjectMap.Init(CWorldManager::m_iWidthHeight);
  CWorldManager::m_cResourceMap.Init(CWorldManager::m_iWidthHeight);
  CWorldManager::m_cWalkCount5MoveCost3Map.Init(CWorldManager::m_iWidthHeight);
  CWorldManager::m_cFogMap.Init(CWorldManager::m_iWidthHeight);
  if(CWorldManager::m_pHelpObjectMap)
    delete CWorldManager::m_pHelpObjectMap;

  CWorldManager::m_pHelpObjectMap = new TSparseMap<unsigned char>(CWorldManager::m_iWidthHeight,
                                                                  CWorldManager::m_iWidthHeight,
                                                                  0);
}


// address=[0x16a46f0]
// Decompiled from void __cdecl CWorldManager::SetGroundInit(int a1, int a2)
void __cdecl CWorldManager::SetGroundInit(int a1, int a2) {
  CWorldManager::SetGroundTypeOnly(a1, a2);
  if(s_cLandscapeProperties.IsBlockedLand(a2))
    CWorldManager::SetBlockedLandEx(a1);
  else
    CWorldManager::ClearBlockedLandEx(a1);
  if(s_cLandscapeProperties.IsSlowType(a2))
    CWorldManager::SetMoveCostsBits(a1, 3);
  else
    CWorldManager::SetMoveCostsBits(a1, 2);
  if(a2 == GROUND_GRASS_DUSTY || a2 == GROUND_GRASS_PAVEMENT)
    CWorldManager::SetMoveCostsBits(a1, 0);
}


// address=[0x16a4790]
// Decompiled from void __cdecl CWorldManager::GetBuildingInfluenceInfo(int *a1, int *a2, int *a3)
void __cdecl CWorldManager::GetBuildingInfluenceInfo(int a1, int &a2, int &a3) {
  if(a1 == BUILDING_GUARDTOWERSMALL) {
    a2 = 3499;
    a3 = 37;
  } else if(a1 == BUILDING_GUARDTOWERBIG) {
    a2 = 3999;
    a3 = 40;
  } else if(a1 == BUILDING_CASTLE) {
    a2 = 4999;
    a3 = 44;
  } else {
    a2 = 0;
    a3 = 0;
  }
}


// address=[0x16a4800]
// Decompiled from int __cdecl CWorldManager::CheckSettlerId(int a1)
int __cdecl CWorldManager::CheckSettlerId(int a1) {
  // [esp+4h] [ebp-4h]

  IEntity *pEntity = CMapObjectMgr::EntityPtr(a1);
  if(pEntity && pEntity->ObjType() == SETTLER_OBJ)
    return a1;
  else
    return 0;
}


// address=[0x16a4840]
// Decompiled from int __cdecl CWorldManager::CheckBuildingId(int a1)
int __cdecl CWorldManager::CheckBuildingId(int a1) {
  // [esp+4h] [ebp-4h]

  IEntity *pEntity = CMapObjectMgr::EntityPtr(a1);
  if(pEntity && pEntity->ObjType() == BUILDING_OBJ)
    return a1;
  else
    return 0;
}


// address=[0x16a4880]
// Decompiled from int __cdecl CWorldManager::CheckPileId(int a1)
int __cdecl CWorldManager::CheckPileId(int a1) {
  // [esp+4h] [ebp-4h]

  IEntity *pEntity = CMapObjectMgr::EntityPtr(a1);
  if(pEntity && pEntity->ObjType() == PILE_OBJ)
    return a1;
  else
    return 0;
}


// address=[0x16a6b40]
// Decompiled from void __cdecl CWorldManager::ClearBlockedLandEx(int a1)
void __cdecl CWorldManager::ClearBlockedLandEx(int a1) {
  CWorldManager::ClearFlagBits(a1, 1);
}


// address=[0x16a7880]
// Decompiled from void __cdecl CWorldManager::SetBlockedLandEx(int a1)
void __cdecl CWorldManager::SetBlockedLandEx(int a1) {
  CWorldManager::SetFlagBits(a1, 1u);
}


// address=[0x16a78a0]
// Decompiled from void __cdecl CWorldManager::SetGroundTypeOnly(int a1, unsigned __int8 a2)
void __cdecl CWorldManager::SetGroundTypeOnly(int a1, int a2) {
  CWorldManager::m_cRenderMap.m_pData[a1 + 1] = *reinterpret_cast<T_GFX_MAP_ELEMENT *>(&a2);
}


// address=[0x16a78e0]
// Decompiled from void __cdecl CWorldManager::StartUpOwner(int a1, __int16 a2)
void __cdecl CWorldManager::StartUpOwner(int a1, int a2) {
  CWorldManager::m_cNormalTileIdMap.m_pData[a1] = a2;
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
