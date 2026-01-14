#include "all_headers.h"

// Definitions for class CWaterFlags

// address=[0x1351d70]
// Decompiled from int __cdecl CWaterFlags::WaterFlags(int a1)
static int __cdecl CWaterFlags::WaterFlags(int) {
  
  return *(unsigned __int16 *)(CWaterFlags::m_pWaterFlagsLayer + 2 * a1);
}


// address=[0x14dff20]
// Decompiled from bool __cdecl CWaterFlags::IsBlockedWater(int a1)
static bool __cdecl CWaterFlags::IsBlockedWater(int) {
  
  return (*(_WORD *)(CWaterFlags::m_pWaterFlagsLayer + 2 * a1) & 0xC300) != 49152;
}


// address=[0x14dfff0]
// Decompiled from bool __cdecl CWaterFlags::IsWater(int a1)
static bool __cdecl CWaterFlags::IsWater(int) {
  
  return *(unsigned __int16 *)(CWaterFlags::m_pWaterFlagsLayer + 2 * a1) >= 0xC000u;
}


// address=[0x14e0080]
// Decompiled from int __cdecl CWaterFlags::WaterFlagsGetDistanceToNearestShip(char a1)
static int __cdecl CWaterFlags::WaterFlagsGetDistanceToNearestShip(int) {
  
  if ( (a1 & 0xF) != 0 )
    return 10 - (a1 & 0xF);
  else
    return -1;
}


// address=[0x14eb310]
// Decompiled from int __cdecl CWaterFlags::ClearWaterFlagBitRepelling(int a1)
static void __cdecl CWaterFlags::ClearWaterFlagBitRepelling(int) {
  
  int result; // eax

  result = a1;
  *(_WORD *)(CWaterFlags::m_pWaterFlagsLayer + 2 * a1) &= ~0x1000u;
  return result;
}


// address=[0x14fdea0]
// Decompiled from bool __cdecl CWaterFlags::WaterFlagsIsFreeWater(__int16 a1)
static bool __cdecl CWaterFlags::WaterFlagsIsFreeWater(int) {
  
  return (a1 & 0xCB00) == 49152;
}


// address=[0x15067a0]
// Decompiled from int __cdecl CWaterFlags::SetWaterFlagBitRepelling(int a1)
static void __cdecl CWaterFlags::SetWaterFlagBitRepelling(int) {
  
  int result; // eax

  result = a1;
  *(_WORD *)(CWaterFlags::m_pWaterFlagsLayer + 2 * a1) |= 0x1000u;
  return result;
}


// address=[0x15f48a0]
// Decompiled from bool __cdecl CWaterFlags::IsFreeWater(int a1)
static bool __cdecl CWaterFlags::IsFreeWater(int) {
  
  return (*(_WORD *)(CWaterFlags::m_pWaterFlagsLayer + 2 * a1) & 0xCB00) == 49152;
}


// address=[0x15fe810]
// Decompiled from bool __cdecl CWaterFlags::WaterFlagsValid(int a1)
static bool __cdecl CWaterFlags::WaterFlagsValid(int) {
  
  return a1 >= 49152;
}


// address=[0x15f42f0]
// Decompiled from int __cdecl CWaterFlags::ClearWaterFlagBits(int a1, __int16 a2)
static void __cdecl CWaterFlags::ClearWaterFlagBits(int,int) {
  
  int result; // eax

  result = CWaterFlags::m_pWaterFlagsLayer;
  *(_WORD *)(CWaterFlags::m_pWaterFlagsLayer + 2 * a1) &= ~a2;
  return result;
}


// address=[0x15f58d0]
// Decompiled from int __cdecl CWaterFlags::SetWaterFlagBits(int a1, __int16 a2)
static void __cdecl CWaterFlags::SetWaterFlagBits(int,int) {
  
  int result; // eax

  result = a1;
  *(_WORD *)(CWaterFlags::m_pWaterFlagsLayer + 2 * a1) |= a2;
  return result;
}


// address=[0x15fcd50]
// Decompiled from int __cdecl CWaterFlags::Init(unsigned __int16 *a1)
static void __cdecl CWaterFlags::Init(unsigned short *) {
  
  int result; // eax

  if ( !a1 && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 736, "_pWaterFlagsLayer != 0") == 1 )
    __debugbreak();
  CWaterFlags::Done();
  CWaterFlags::m_pWaterFlagsLayer = (int)a1;
  result = CWaterFlagsEx::CalcWaterFlags();
  CWaterFlags::m_iInitialized = 1;
  return result;
}


// address=[0x15fcdc0]
// Decompiled from void CWaterFlags::Done()
static void __cdecl CWaterFlags::Done(void) {
  
  CWaterFlags::m_iInitialized = 0;
  CWaterFlags::m_pWaterFlagsLayer = 0;
}


// address=[0x15fcde0]
// Decompiled from void __cdecl CWaterFlags::PlaceShip(int a1)
static void __cdecl CWaterFlags::PlaceShip(int) {
  
  unsigned int v1; // [esp+4h] [ebp-1Ch]
  __int16 v2; // [esp+8h] [ebp-18h]
  int v3; // [esp+Ch] [ebp-14h]
  int v4; // [esp+10h] [ebp-10h]
  int v5; // [esp+14h] [ebp-Ch]
  int v6; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]

  if ( !CWaterFlags::m_iInitialized && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 769, "m_iInitialized") == 1 )
    __debugbreak();
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a1)
    && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 770, "g_cWorld.InWorldPackedXY(_iXY)") == 1 )
  {
    __debugbreak();
  }
  v5 = CWorldManager::Index(a1);
  if ( CWorldManager::IsWater(v5) )
  {
    if ( (CWaterFlags::WaterFlags(v5) & 0x800) != 0
      && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 781, "(WaterFlags(iWorldIdx) & WATER_FLAG_SHIP) == 0") == 1 )
    {
      __debugbreak();
    }
    CWaterFlags::SetWaterFlagBits(v5, 2048);
    for ( i = 0; i < 271; ++i )
    {
      v1 = v5 + CWorldManager::SurroundingHexPointRelIndex(i);
      if ( CWorldManager::InWorld(v1) )
      {
        v6 = CWaterFlags::WaterFlags(v1);
        if ( CWaterFlags::WaterFlagsValid(v6) )
        {
          v4 = 10 - (unsigned __int8)byte_37D8D92[4 * i];
          v3 = v6 & 0xF;
          if ( v4 < v3 )
          {
            if ( v4 < (v6 & 0xF0) >> 4 )
              v2 = (unsigned __int8)v6;
            else
              v2 = v3 | (16 * v4);
          }
          else
          {
            v2 = v4 | (16 * v3);
          }
          CWaterFlags::SetWaterFlags(v1, v2 | v6 & 0xFF00);
        }
      }
    }
  }
  else if ( BBSupportDbgReport(1, "Pathing\\WaterFlags.cpp", 776, "CWaterFlags::PlaceShip(): World index is not water!") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x15fcfc0]
// Decompiled from int __cdecl CWaterFlags::RemoveShip(int a1)
static void __cdecl CWaterFlags::RemoveShip(int) {
  
  int result; // eax
  int v2; // eax
  int v3; // eax
  int v4; // [esp-4h] [ebp-C0h]
  __int16 v5; // [esp+0h] [ebp-BCh]
  int v6; // [esp+4h] [ebp-B8h]
  unsigned int v7; // [esp+8h] [ebp-B4h]
  int v8; // [esp+Ch] [ebp-B0h]
  int i; // [esp+10h] [ebp-ACh]
  _BYTE v10[164]; // [esp+14h] [ebp-A8h] BYREF

  if ( !CWaterFlags::m_iInitialized && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 828, "m_iInitialized") == 1 )
    __debugbreak();
  if ( !(unsigned __int8)CWorldManager::InWorldPackedXY(a1)
    && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 829, "g_cWorld.InWorldPackedXY(_iXY)") == 1 )
  {
    __debugbreak();
  }
  v8 = CWorldManager::Index(a1);
  if ( CWorldManager::IsWater(v8) )
  {
    if ( (CWaterFlags::WaterFlags(v8) & 0x800) == 0
      && BBSupportDbgReport(2, "Pathing\\WaterFlags.cpp", 840, "(WaterFlags(iWorldIdx) & WATER_FLAG_SHIP) != 0") == 1 )
    {
      __debugbreak();
    }
    CShipList::CShipList((CShipList *)v10, a1);
    result = CWaterFlags::ClearWaterFlagBits(v8, 2048);
    for ( i = 0; i < 271; ++i )
    {
      v7 = v8 + CWorldManager::SurroundingHexPointRelIndex(i);
      if ( CWorldManager::InWorld(v7) )
      {
        v6 = CWaterFlags::WaterFlags(v7);
        if ( CWaterFlags::WaterFlagsValid(v6) )
        {
          v4 = SSurroundingPoint8::Y(&g_sSurroundingHexPoints8[4 * i]);
          v2 = SSurroundingPoint8::X(&g_sSurroundingHexPoints8[4 * i]);
          v3 = Y16X16::PackXYFast(v2, v4);
          v5 = CShipList::Nearest((CShipList *)v10, a1 + v3);
          CWaterFlags::SetWaterFlags(v7, v5 | v6 & 0xFF00);
        }
      }
      result = i + 1;
    }
  }
  else
  {
    result = BBSupportDbgReport(
               1,
               "Pathing\\WaterFlags.cpp",
               835,
               "CWaterFlags::RemoveShip(): World index is not water!");
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


// address=[0x15fe7a0]
// Decompiled from int __cdecl CWaterFlags::SetWaterFlags(int a1, __int16 a2)
static void __cdecl CWaterFlags::SetWaterFlags(int,int) {
  
  int result; // eax

  result = a1;
  *(_WORD *)(CWaterFlags::m_pWaterFlagsLayer + 2 * a1) = a2;
  return result;
}


// address=[0x4617aa4]
// [Decompilation failed for static int CWaterFlags::m_iInitialized]

// address=[0x4617aa8]
// [Decompilation failed for static unsigned short * CWaterFlags::m_pWaterFlagsLayer]

