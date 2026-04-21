#include "CWalkingShip.h"

#include "CWaterFlags.h"
#include "World/CWorldManager.h"
#include "CBB/CBBSupport.h"
#include "Defines/Walking.h"
#include "MapObjects/SSurroundingPoint8.h"
#include "World/helper.h"

// Definitions for class CWalkingShip

// address=[0x15f9850]
// Decompiled from CWalkingShip *__thiscall CWalkingShip::CWalkingShip(CWalkingShip *this)
CWalkingShip::CWalkingShip(void) : CWalkingBase(WALKING_TYPE_SHIP, 0) {
  this->m_sData.m_iEntityFlags |= 0x100u;
}


// address=[0x15fafb0]
// Decompiled from CWalking *__thiscall CWalkingShip::~CWalkingShip(CWalkingShip *this)
CWalkingShip::~CWalkingShip(void) = default;


// address=[0x15fb270]
// Decompiled from int CWalkingShip::GetWalkingType()
enum T_WALKING_TYPE const CWalkingShip::GetWalkingType(void) {
  return WALKING_TYPE_SHIP;
}


// address=[0x15f9890]
// Decompiled from bool __thiscall CWalkingShip::IsNotBlocked(CWalkingShip *this, int a2)
bool CWalkingShip::IsNotBlocked(int a2) {
  return !CWaterFlags::IsBlockedWater(a2);
}


// address=[0x15f98d0]
// Decompiled from bool __thiscall CWalkingShip::IsNotOccupied(CWalkingShip *this, int a2)
bool CWalkingShip::IsNotOccupied(int a2) {
  return (CWaterFlags::WaterFlags(a2) & 0x800) == 0;
}


// address=[0x15f9910]
// Decompiled from char __thiscall CWalkingShip::FindPathAStar64(CWalkingShip *this, int a2, int a3, struct CDirCache *a4)
bool CWalkingShip::FindPathAStar64(int a2, int a3, class CDirCache &a4) {
  // [esp+5h] [ebp-3h]

  bool bRemoved = CWater::RemoveShip(a2);
  BB_ASSERT(bRemoved)
  char Path = g_cAStar64Ship->FindPath(a2, a3, a4);
  bool bPlaced = CWater::PlaceShip(a2);
  BB_ASSERT(bPlaced)
  return Path;
}


// address=[0x15f99b0]
// Decompiled from int __thiscall CWalkingShip::IdleWalk(CWalkingShip *this, int a2, int a3)
int CWalkingShip::IdleWalk(int _iXY, int a3) {
  _DWORD v39[7]; // [esp+9Ch] [ebp-20h]

  int v24 = 0;
  int v25 = 0;
  int v28 = 10;
  int v27 = 0;
  int v23 = CWorldManager::Index(_iXY);
  for(int i = 0; i < 6; ++i) {
    int     v4 = v23 + CWorldManager::NeighborRelIndex(i);
    __int16 v26 = CWaterFlags::WaterFlags(v4);
    if((v26 & 0x300) != 0) {
      v39[i] = 11;
      ++v25;
    } else {
      v24 += (v26 & 0x800) != 0;
      int v30 = (v26 & 0xF0) >> 4;
      v39[i] = v30;
      if(v30 < v28)
        v28 = (v26 & 0xF0) >> 4;
      if(v30 > v27)
        v27 = (v26 & 0xF0) >> 4;
    }
  }
  v39[6] = v39[0];
  unsigned __int8 v33 = 0;
  bool            v34 = 0;
  if(v28 >= v27 || v27 <= 0) {
    if((CWaterFlags::WaterFlags(v23) & 0x1000) != 0)
      v34 = v24 + v25 < 6;
  } else {
    v33 = 1;
  }
  if(v34) {
    int v11 = CWorldManager::Index(_iXY);
    int v12 = this->SectorId(v11);
    if((this->m_sData.m_uFlags & 0x20000) == 0)
      this->m_sData.m_iIdleWalkToXY = -1;
    this->m_sData.m_uFlags &= ~0x20000u;
    if(CWorldManager::InWorldPackedXY(this->m_sData.m_iIdleWalkToXY)) {
      int v10 = CWorldManager::Index(this->m_sData.m_iIdleWalkToXY);
      int v18 = this->SectorId(v10);
      if((CWaterFlags::WaterFlags(v23) & 0x1000) != 0 || v18 <= 0 || v12 != v18)
        this->m_sData.m_iIdleWalkToXY = -1;
    } else {
      this->m_sData.m_iIdleWalkToXY = -1;
    }
    if(this->m_sData.m_iIdleWalkToXY < 0) {
      int iX = Y16X16::UnpackXFast(_iXY);
      int iY = Y16X16::UnpackYFast(_iXY);
      int v20 = -1;
      int v14 = -1;
      for(int j = 0; j < SurroundingHexPointsCount(15); ++j) {
        int iSurroundingX = iX + g_sSurroundingHexPoints8[j].X();
        int iSurroundingY = iY + g_sSurroundingHexPoints8[j].Y();
        if(CWorldManager::InWorld(iSurroundingX, iSurroundingY)) {
          int v17 = CWorldManager::Index(iSurroundingX, iSurroundingY);
          if(this->SectorId(v17) == v12) {
            __int16 v16 = CWaterFlags::WaterFlags(v17);
            if((v16 & 0x1000) == 0) {
              int DistanceToNearestShip = CWaterFlags::WaterFlagsGetDistanceToNearestShip(v16);
              if(DistanceToNearestShip == -1 || DistanceToNearestShip > 4) {
                v20 = iSurroundingX;
                v14 = iSurroundingY;
                break;
              }
            }
          }
        }
      }
      if(v20 < 0)
        return 8;
      this->m_sData.m_iIdleWalkToXY = Y16X16::PackXYFast(v20, v14);
    }
    int v19 = Y16X16::DirectionFast(_iXY, this->m_sData.m_iIdleWalkToXY);
    int v7 = Y16X16::UnpackXFast(_iXY);
    int v6 = Y16X16::UnpackYFast(_iXY);
    int v5 = CWorldManager::Index(g_sNeighborPoints[v19].x + v7, g_sNeighborPoints[v19].y + v6);
    if(this->IsNotBlocked(v5)) {
      this->m_sData.m_uFlags |= 0x20000u;
      return v19;
    }
  } else {
    this->m_sData.m_iIdleWalkToXY = -1;
  }
  if(v34 | v33) {
    unsigned int v31 = 0;
    BOOL         v13 = v39[5] == v28;
    for(int k = 0; k < 6; ++k) {
      if(v39[k] == v28) {
        v31 += v13 + (v39[k + 1] == 0) + 1;
        v39[k] = v31;
      } else {
        v39[k] = -1;
        v13 = 0;
      }
    }
    signed int v32 = g_pGame->Rand() % v31;
    for(int m = 0; m < 6; ++m) {
      if(v32 < v39[m])
        return m;
    }
  }
  this->m_sData.m_iIdleWalkToXY = -1;
  return 8;
}


