#include "all_headers.h"

// Definitions for class CInfluMap

// address=[0x1306520]
// Decompiled from int __cdecl CInfluMap::EnemyValueVW(int a1, int a2, int a3)
static int __cdecl CInfluMap::EnemyValueVW(int,int,int) {
  
  return CInfluMap::m_uValues[576 * a2 + 576 + 9 * a1] - CInfluMap::m_uValues[576 * a2 + 576 + 9 * a1 + a3];
}


// address=[0x1306580]
// Decompiled from int __cdecl CInfluMap::EnemyValueXY(Squares *a1, Squares *a2, int a3)
static int __cdecl CInfluMap::EnemyValueXY(int,int,int) {
  
  int v3; // eax
  int v5; // [esp-8h] [ebp-8h]

  v5 = Squares::XYToVW(a2);
  v3 = Squares::XYToVW(a1);
  return CInfluMap::EnemyValueVW(v3, v5, a3);
}


// address=[0x130e900]
// Decompiled from int __cdecl CInfluMap::AllyValueVW(int a1, int a2, int a3)
static int __cdecl CInfluMap::AllyValueVW(int,int,int) {
  
  return CInfluMap::m_uValues[576 * a2 + 576 + 9 * a1 + a3];
}


// address=[0x13231c0]
// Decompiled from int __cdecl CInfluMap::AllyValueXY(Squares *a1, Squares *a2, int a3)
static int __cdecl CInfluMap::AllyValueXY(int,int,int) {
  
  int v3; // esi

  v3 = 576 * (Squares::XYToVW(a2) + 1);
  return CInfluMap::m_uValues[9 * Squares::XYToVW(a1) + v3 + a3];
}


// address=[0x15ddd70]
// Decompiled from void *CInfluMap::Init()
static void __cdecl CInfluMap::Init(void) {
  
  void *result; // eax

  result = memset(CInfluMap::m_uValues, 0, 0x12900u);
  CInfluMap::m_iInitialized = 1;
  return result;
}


// address=[0x15ddda0]
// Decompiled from void CInfluMap::Done()
static void __cdecl CInfluMap::Done(void) {
  
  CInfluMap::m_iInitialized = 0;
}


// address=[0x15dddb0]
// Decompiled from void __cdecl CInfluMap::ModifyInfluenceMapVW(int a1, int a2, int a3, int Number)
static void __cdecl CInfluMap::ModifyInfluenceMapVW(int,int,int,int) {
  
  int v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  if ( !CInfluMap::m_iInitialized && BBSupportDbgReport(2, "Pathing\\InfluMap.cpp", 84, "m_iInitialized") == 1 )
    __debugbreak();
  if ( (a3 < 1 || a3 > 8)
    && BBSupportDbgReport(2, "Pathing\\InfluMap.cpp", 85, "(_iPlayerId >= PLAYER_FIRST) && (_iPlayerId <= PLAYER_LAST)") == 1 )
  {
    __debugbreak();
  }
  v5 = CAlliances::AllianceId(a3);
  if ( !v5 && BBSupportDbgReport(2, "Pathing\\InfluMap.cpp", 89, "iAllianceId != ALLIANCE_NO_ALLIANCE") == 1 )
    __debugbreak();
  if ( j__abs(Number) < 2 )
    v4 = Number;
  else
    v4 = 8 * Number;
  CInfluMap::ModifyValueVW(a1, a2, v5, v4);
  CInfluMap::ModifyValueVW(a1, a2 - 1, v5, Number);
  CInfluMap::ModifyValueVW(a1, a2 + 1, v5, Number);
  if ( a1 > 0 )
  {
    CInfluMap::ModifyValueVW(a1 - 1, a2 - 1, v5, Number);
    CInfluMap::ModifyValueVW(a1 - 1, a2, v5, Number);
    CInfluMap::ModifyValueVW(a1 - 1, a2 + 1, v5, Number);
  }
  if ( a1 < 63 )
  {
    CInfluMap::ModifyValueVW(a1 + 1, a2 - 1, v5, Number);
    CInfluMap::ModifyValueVW(a1 + 1, a2, v5, Number);
    CInfluMap::ModifyValueVW(a1 + 1, a2 + 1, v5, Number);
  }
}


// address=[0x41799ec]
// [Decompilation failed for static int CInfluMap::m_iInitialized]

// address=[0x41799f0]
// [Decompilation failed for static unsigned short (* CInfluMap::m_uValues)[64][9]]

// address=[0x15ddff0]
// Decompiled from unsigned __int16 *__cdecl CInfluMap::ModifyValueVW(int a1, int a2, int a3, __int16 a4)
static void __cdecl CInfluMap::ModifyValueVW(int,int,int,int) {
  
  unsigned __int16 *result; // eax

  CInfluMap::m_uValues[576 * a2 + 576 + 9 * a1] += a4;
  result = &CInfluMap::m_uValues[576 * a2 + 576 + 9 * a1];
  result[a3] += a4;
  return result;
}


