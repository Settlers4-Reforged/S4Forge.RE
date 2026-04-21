#include "CWalkingCatapult.h"

#include "ITiling.h"
#include "CBB/CBBSupport.h"
#include "Defines/Walking.h"
#include "MapObjects/SSurroundingPoint8.h"
#include "World/CWorldManager.h"
#include "World/helper.h"

// Definitions for class CWalkingCatapult

// address=[0x15f91a0]
// Decompiled from CWalkingCatapult *__thiscall CWalkingCatapult::CWalkingCatapult(CWalkingCatapult *this)
CWalkingCatapult::CWalkingCatapult(void) : CWalkingBase(WALKING_TYPE_CATAPULT, 0) {
  this->m_sData.m_iEntityFlags |= 0x200u;
}


// address=[0x15faf70]
// Decompiled from CWalking *__thiscall CWalkingCatapult::~CWalkingCatapult(CWalkingCatapult *this)
CWalkingCatapult::~CWalkingCatapult(void) = default;


// address=[0x15fb240]
// Decompiled from int CWalkingCatapult::GetWalkingType()
enum T_WALKING_TYPE const CWalkingCatapult::GetWalkingType(void) {
  return WALKING_TYPE_CATAPULT;
}


// address=[0x15f91e0]
// Decompiled from bool __thiscall CWalkingCatapult::IsNotBlocked(CWalkingCatapult *this, int a2)
bool CWalkingCatapult::IsNotBlocked(int a2) {
  return static_cast<unsigned int>(CWorldManager::CatapultTileId(a2) - 1) < 0xBFFF;
}


// address=[0x15f9220]
// Decompiled from bool __thiscall CWalkingCatapult::IsNotOccupied(CWalkingCatapult *this, int a2)
bool CWalkingCatapult::IsNotOccupied(int a2) {
  // [esp+4h] [ebp-4h]

  int v3 = CWorldManager::Width();
  if(CWorldManager::OccupyingEntityId(a2))
    return 0;
  if(CWorldManager::OccupyingEntityId(a2 + 1))
    return 0;
  if(CWorldManager::OccupyingEntityId(a2 + v3 + 1))
    return 0;
  if(CWorldManager::OccupyingEntityId(v3 + a2))
    return 0;
  if(CWorldManager::OccupyingEntityId(a2 - 1))
    return 0;
  if(CWorldManager::OccupyingEntityId(a2 - v3 - 1))
    return 0;
  return CWorldManager::OccupyingEntityId(a2 - v3) == 0;
}


// address=[0x15f9300]
// Decompiled from char __thiscall CWalkingCatapult::FindPathAStar64(  CWalkingCatapult *this,  unsigned int a2,  unsigned int a3,  struct CDirCache *a4)
bool CWalkingCatapult::FindPathAStar64(int a2, int a3, class CDirCache &a4) {
  // [esp+4h] [ebp-2Ch]
  // [esp+Ch] [ebp-24h]
  // [esp+14h] [ebp-1Ch]
  // [esp+18h] [ebp-18h]
  // [esp+1Ch] [ebp-14h]
  // [esp+23h] [ebp-Dh]
  _BYTE v11[8]; // [esp+24h] [ebp-Ch]

  int iIndex = CWorldManager::Index(a2);
  for(int i = 0; i < 6; ++i) {
    int iRelIndex = iIndex + CWorldManager::NeighborRelIndex(i);
    if(CWorldManager::MapObjectId(iRelIndex) == i + 1) {
      v11[i] = 1;
      CWorldManager::SetMapObjectId(iRelIndex, 0);
    } else {
      // if((unsigned int) i >= 6)
      //   report_rangecheckfailure();
      v11[i] = 0;
    }
  }
  char bFound = g_cAStar64Catapult->FindPath(a2, a3, a4);
  for(int j = 0; j < 6; ++j) {
    if(v11[j]) {
      int v5 = iIndex + CWorldManager::NeighborRelIndex(j);
      CWorldManager::SetMapObjectId(v5, j + 1);
    }
  }
  return bFound;
}


// address=[0x15f9420]
// Decompiled from int __thiscall CWalkingCatapult::IdleWalk(CWalkingCatapult *this, int a2, int a3)
int CWalkingCatapult::IdleWalk(int _iXY, int a3) {
  // [esp+0h] [ebp-64h]
  // [esp+Ch] [ebp-58h]
  // [esp+10h] [ebp-54h]
  // [esp+14h] [ebp-50h]
  // [esp+18h] [ebp-4Ch]
  // [esp+1Ch] [ebp-48h]
  // [esp+20h] [ebp-44h]
  // [esp+24h] [ebp-40h]
  // [esp+28h] [ebp-3Ch]
  // [esp+30h] [ebp-34h]
  // [esp+34h] [ebp-30h]
  // [esp+38h] [ebp-2Ch]
  // [esp+3Ch] [ebp-28h]
  // [esp+40h] [ebp-24h]
  // [esp+44h] [ebp-20h]
  // [esp+48h] [ebp-1Ch]
  // [esp+4Ch] [ebp-18h]
  // [esp+50h] [ebp-14h]
  // [esp+54h] [ebp-10h]
  // [esp+58h] [ebp-Ch]
  // [esp+62h] [ebp-2h]
  // [esp+63h] [ebp-1h]

  int iCurrentX = Y16X16::UnpackXFast(_iXY);
  int iCurrentY = Y16X16::UnpackYFast(_iXY);
  BB_ASSERT(CWorldManager::InWorld(iCurrentX, iCurrentY));

  if(!CWorldManager::InInnerWorld1(iCurrentX, iCurrentY))
    return 8;
  int  v16 = CWorldManager::Index(iCurrentX, iCurrentY);
  bool v26 = CWorldManager::MoveCostsBits(v16) >= 7;
  if(!v26) {
    for(int i = 0; i < 6; ++i) {
      int v12 = v16 + CWorldManager::NeighborRelIndex(i);
      if(CWorldManager::FlagBits(v12, 8u) && CWorldManager::MoveCostsBits(v12) >= 7) {
        v26 = 1;
        break;
      }
    }
  }
  if(v26) {
    int v9 = this->SectorId(v16);
    if((this->m_sData.m_uFlags & 0x20000) == 0)
      this->m_sData.m_iIdleWalkToXY = -1;
    this->m_sData.m_uFlags &= ~0x20000u;
    if(CWorldManager::InWorldPackedXY(this->m_sData.m_iIdleWalkToXY)) {
      int v11 = CWorldManager::Index(this->m_sData.m_iIdleWalkToXY);
      int v10 = this->SectorId(v11);
      if(CWorldManager::MoveCostsBits(v11) == 7 || v10 <= 0 || v9 != v10)
        this->m_sData.m_iIdleWalkToXY = -1;
    } else {
      this->m_sData.m_iIdleWalkToXY = -1;
    }
    if(this->m_sData.m_iIdleWalkToXY < 0) {
      int iX = Y16X16::UnpackXFast(_iXY);
      int iY = Y16X16::UnpackYFast(_iXY);
      int v13 = -1;
      int v7 = -1;
      for(int j = 0; j < SurroundingHexPointsCount(15); ++j) {
        int iSurroundX = iX + g_sSurroundingHexPoints8[j].X();
        int iSurroundY = iY + g_sSurroundingHexPoints8[j].Y();
        if(CWorldManager::InWorld(iSurroundX, iSurroundY)) {
          int iIdx = CWorldManager::Index(iSurroundX, iSurroundY);
          if(this->SectorId(iIdx) == v9
             && CWorldManager::MoveCostsBits(iIdx) < 7
             && this->IsNotOccupied(iIdx)) {
            char v25 = 1;
            for(int k = 1; k < 19; ++k) {
              int v8 = iIdx + CWorldManager::SurroundingHexPointRelIndex(k);
              if(CWorldManager::FlagBits(v8, 8u) && CWorldManager::MoveCostsBits(v8) >= 7) {
                v25 = 0;
                break;
              }
            }
            if(v25) {
              v13 = iSurroundX;
              v7 = iSurroundY;
              break;
            }
          }
        }
      }
      if(v13 < 0)
        return 8;
      this->m_sData.m_iIdleWalkToXY = Y16X16::PackXYFast(v13, v7);
    }
    int v17 = Y16X16::DirectionFast(_iXY, this->m_sData.m_iIdleWalkToXY);
    int v4 = CWorldManager::Index(g_sNeighborPoints[v17].x + iCurrentX, g_sNeighborPoints[v17].y + iCurrentY);
    if(!this->IsNotBlocked(v4))
      return 8;
    return v17;
  } else {
    this->m_sData.m_iIdleWalkToXY = -1;
    return 8;
  }
}


// address=[0x15f9810]
// Decompiled from int __thiscall CWalkingCatapult::SectorId(CWalkingCatapult *this, int a2)
int CWalkingCatapult::SectorId(int a2) {
  return ITiling::CatapultSectorId(a2);
}


// address=[0x15f9830]
// Decompiled from int __thiscall CWalkingCatapult::TileId(CWalkingCatapult *this, int a2)
int CWalkingCatapult::TileId(int a2) {
  return ITiling::CatapultTileId(a2);
}


