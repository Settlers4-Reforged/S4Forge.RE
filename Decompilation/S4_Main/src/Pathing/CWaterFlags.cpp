#include "CWaterFlags.h"

#include "CBB/CBBSupport.h"
#include "Defines/World.h"
#include "MapObjects/SSurroundingPoint8.h"
#include "World/CWorldManager.h"
#include "World/helper.h"

// Definitions for class CWaterFlags

// address=[0x1351d70]
// Decompiled from int __cdecl CWaterFlags::WaterFlags(int a1)
int __cdecl CWaterFlags::WaterFlags(int a1) {
  return CWaterFlags::m_pWaterFlagsLayer[a1];
}


// address=[0x14dff20]
// Decompiled from bool __cdecl CWaterFlags::IsBlockedWater(int a1)
bool __cdecl CWaterFlags::IsBlockedWater(int a1) {
  return (CWaterFlags::m_pWaterFlagsLayer[a1] & 0xC300) != 49152;
}


// address=[0x14dfff0]
// Decompiled from bool __cdecl CWaterFlags::IsWater(int a1)
bool __cdecl CWaterFlags::IsWater(int a1) {
  return CWaterFlags::m_pWaterFlagsLayer[a1] >= 0xC000u;
}


// address=[0x14e0080]
// Decompiled from int __cdecl CWaterFlags::WaterFlagsGetDistanceToNearestShip(char a1)
int __cdecl CWaterFlags::WaterFlagsGetDistanceToNearestShip(int a1) {
  if((a1 & 0xF) != 0)
    return 10 - (a1 & 0xF);
  else
    return -1;
}


// address=[0x14eb310]
// Decompiled from int __cdecl CWaterFlags::ClearWaterFlagBitRepelling(int a1)
void __cdecl CWaterFlags::ClearWaterFlagBitRepelling(int a1) {
  CWaterFlags::m_pWaterFlagsLayer[a1] &= ~0x1000u;
}


// address=[0x14fdea0]
// Decompiled from bool __cdecl CWaterFlags::WaterFlagsIsFreeWater(__int16 a1)
bool __cdecl CWaterFlags::WaterFlagsIsFreeWater(int a1) {
  return (a1 & 0xCB00) == 49152;
}


// address=[0x15067a0]
// Decompiled from int __cdecl CWaterFlags::SetWaterFlagBitRepelling(int a1)
void __cdecl CWaterFlags::SetWaterFlagBitRepelling(int a1) {
  CWaterFlags::m_pWaterFlagsLayer[a1] |= 0x1000u;
}


// address=[0x15f48a0]
// Decompiled from bool __cdecl CWaterFlags::IsFreeWater(int a1)
bool __cdecl CWaterFlags::IsFreeWater(int a1) {
  return (CWaterFlags::m_pWaterFlagsLayer[a1] & 0xCB00) == 0xC000;
}


// address=[0x15fe810]
// Decompiled from bool __cdecl CWaterFlags::WaterFlagsValid(int a1)
bool __cdecl CWaterFlags::WaterFlagsValid(int a1) {
  return a1 >= 49152;
}


// address=[0x15f42f0]
// Decompiled from void __cdecl CWaterFlags::ClearWaterFlagBits(int a1, __int16 a2)
void __cdecl CWaterFlags::ClearWaterFlagBits(int a1, int a2) {
  CWaterFlags::m_pWaterFlagsLayer[a1] &= ~a2;
}


// address=[0x15f58d0]
// Decompiled from void __cdecl CWaterFlags::SetWaterFlagBits(int a1, __int16 a2)
void __cdecl CWaterFlags::SetWaterFlagBits(int a1, int a2) {
  CWaterFlags::m_pWaterFlagsLayer[a1] |= a2;
}


// address=[0x15fcd50]
// Decompiled from void __cdecl CWaterFlags::Init(unsigned __int16 *a1)
void __cdecl CWaterFlags::Init(unsigned short *_pWaterFlagsLayer) {
  BB_ASSERT(_pWaterFlagsLayer != 0)
  CWaterFlags::Done();
  CWaterFlags::m_pWaterFlagsLayer = _pWaterFlagsLayer;
  CWaterFlagsEx::CalcWaterFlags();
  CWaterFlags::m_iInitialized = 1;
}


// address=[0x15fcdc0]
// Decompiled from void CWaterFlags::Done()
void __cdecl CWaterFlags::Done(void) {
  CWaterFlags::m_iInitialized = 0;
  CWaterFlags::m_pWaterFlagsLayer = 0;
}


// address=[0x15fcde0]
// Decompiled from void __cdecl CWaterFlags::PlaceShip(int a1)
void __cdecl CWaterFlags::PlaceShip(int _iXY) {
  BB_ASSERT(m_iInitialized)
  BB_ASSERT(g_cWorld.InWorldPackedXY(_iXY))

  int iWorldIdx = CWorldManager::Index(_iXY);
  if(CWorldManager::IsWater(iWorldIdx)) {
    BB_ASSERT((WaterFlags(iWorldIdx) & WATER_FLAG_SHIP) == 0)
    CWaterFlags::SetWaterFlagBits(iWorldIdx, 2048);
    for(int i = 0; i < 271; ++i) {
      int v1 = iWorldIdx + CWorldManager::SurroundingHexPointRelIndex(i);
      if(CWorldManager::InWorld(v1)) {
        int v6 = CWaterFlags::WaterFlags(v1);
        if(CWaterFlags::WaterFlagsValid(v6)) {
          int v4 = 10 - g_sSurroundingHexPoints8[i].m_iRadius;
          int v3 = v6 & 0xF;

          __int16 v2; // [esp+8h] [ebp-18h]
          if(v4 < v3) {
            if(v4 < (v6 & 0xF0) >> 4)
              v2 = v6;
            else
              v2 = v3 | (16 * v4);
          } else {
            v2 = v4 | (16 * v3);
          }
          CWaterFlags::SetWaterFlags(v1, v2 | v6 & 0xFF00);
        }
      }
    }
  } else {
    BB_REPORT("CWaterFlags::PlaceShip(): World index is not water!")
  }
}


// address=[0x15fcfc0]
// Decompiled from int __cdecl CWaterFlags::RemoveShip(int a1)
void __cdecl CWaterFlags::RemoveShip(int _iXY) {
  // eax
  // eax
  // [esp-4h] [ebp-C0h]
  // [esp+0h] [ebp-BCh]
  // [esp+4h] [ebp-B8h]
  // [esp+8h] [ebp-B4h]
  // [esp+Ch] [ebp-B0h]
  // [esp+10h] [ebp-ACh]
  CShipList v10; // [esp+14h] [ebp-A8h] BYREF

  BB_ASSERT(m_iInitialized)
  BB_ASSERT(g_cWorld.InWorldPackedXY(_iXY))

  int iWorldIdx = CWorldManager::Index(_iXY);
  if(CWorldManager::IsWater(iWorldIdx)) {
    BB_ASSERT((WaterFlags(iWorldIdx) & WATER_FLAG_SHIP) != 0)

    v10.CShipList(_iXY);
    CWaterFlags::ClearWaterFlagBits(iWorldIdx, 2048);
    for(int i = 0; i < 271; ++i) {
      unsigned int v7 = iWorldIdx + CWorldManager::SurroundingHexPointRelIndex(i);
      if(CWorldManager::InWorld(v7)) {
        int v6 = CWaterFlags::WaterFlags(v7);
        if(CWaterFlags::WaterFlagsValid(v6)) {
          int v4 = g_sSurroundingHexPoints8[i].Y();
          int v2 = g_sSurroundingHexPoints8[i].X();

          int     v3 = Y16X16::PackXYFast(v2, v4);
          __int16 v5 = v10.Nearest(_iXY + v3);
          CWaterFlags::SetWaterFlags(v7, v5 | v6 & 0xFF00);
        }
      }
    }
  } else {
    BB_REPORT("CWaterFlags::RemoveShip(): World index is not water!")
  }
}


// address=[0x15fe7a0]
// Decompiled from void __cdecl CWaterFlags::SetWaterFlags(int a1, unsigned __int16 a2)
void __cdecl CWaterFlags::SetWaterFlags(int a1, int a2) {
  CWaterFlags::m_pWaterFlagsLayer[a1] = a2;
}


// address=[0x4617aa4]
// [Decompilation failed for static int CWaterFlags::m_iInitialized]

// address=[0x4617aa8]
// [Decompilation failed for static unsigned short * CWaterFlags::m_pWaterFlagsLayer]

