#include "CDebugGridTest.h"

// Definitions for class CDebugGridTest

// address=[0x15dcbc0]
// Decompiled from CDebugGridTest *__thiscall CDebugGridTest::CDebugGridTest(CDebugGridTest *this)
 CDebugGridTest::CDebugGridTest(void) {
  
  return this;
}


// address=[0x15dcbd0]
// Decompiled from int CDebugGridTest::Test()
void  CDebugGridTest::Test(void) {
  
  int v0; // eax
  char *v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  char *v17; // eax
  char *v18; // eax
  int v20; // [esp-4h] [ebp-1100h]
  LARGE_INTEGER v21[3]; // [esp+10h] [ebp-10ECh] BYREF
  SPoint sZero; // [esp+28h] [ebp-10D4h] BYREF
  Y16X16 *v23; // [esp+30h] [ebp-10CCh]
  Y16X16 *v24; // [esp+34h] [ebp-10C8h]
  SPoint v25; // [esp+38h] [ebp-10C4h] BYREF
  int n; // [esp+40h] [ebp-10BCh]
  int m; // [esp+44h] [ebp-10B8h]
  int k; // [esp+48h] [ebp-10B4h]
  int v29; // [esp+4Ch] [ebp-10B0h]
  int v30; // [esp+50h] [ebp-10ACh]
  int v31; // [esp+54h] [ebp-10A8h]
  int v32; // [esp+58h] [ebp-10A4h]
  int iDX; // [esp+5Ch] [ebp-10A0h]
  int iDY; // [esp+60h] [ebp-109Ch]
  int v35; // [esp+64h] [ebp-1098h]
  int v36; // [esp+68h] [ebp-1094h]
  int j; // [esp+6Ch] [ebp-1090h]
  int i; // [esp+70h] [ebp-108Ch]
  int iRadius; // [esp+74h] [ebp-1088h]
  _DWORD v40[1056]; // [esp+78h] [ebp-1084h]

  for ( i = 0; i < 6; ++i )
  {
    if ( SPoint::operator*(&g_sNeighborPoints[i].x, &g_sNeighborOrthos[i].x)
      && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1433, "g_sNeighborPoints[i] * g_sNeighborOrthos[i] == 0") == 1 )
    {
      __debugbreak();
    }
    if ( !SPoint::operator==(&g_sSurroundingHexPoints[i + 1], &g_sNeighborPoints[i])
      && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1434, "g_sSurroundingHexPoints[1 + i] == g_sNeighborPoints[i]") == 1 )
    {
      __debugbreak();
    }
    v20 = SPoint::Y(&g_sNeighborPoints[i]);
    v0 = SPoint::X(&g_sNeighborPoints[i]);
    if ( Grid::Direction(v0, v20) != i
      && BBSupportDbgReport(
           2,
           "Pathing\\Grid.cpp",
           1435,
           "Direction(g_sNeighborPoints[i].X(), g_sNeighborPoints[i].Y()) == i") == 1 )
    {
      __debugbreak();
    }
  }
  SPoint::Zero(&sZero);
  if ( !SPoint::operator==(g_sSurroundingHexPoints, &sZero)
    && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1446, "g_sSurroundingHexPoints[0] == sZero") == 1 )
  {
    __debugbreak();
  }
  v24 = (Y16X16 *)Y16X16::PackXYFast(15, 15);
  for ( j = 0; j < 721; ++j )
  {
    v1 = (char *)SSurroundingPoint8::Point((SSurroundingPoint8 *)&g_sSurroundingHexPoints8[4 * j]);
    SPoint::operator=(&v25, v1);
    if ( j < 37
      && !SPoint::operator==(&g_sSurroundingHexPoints[j], &v25)
      && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1461, "g_sSurroundingHexPoints[i] == sPoint") == 1 )
    {
      __debugbreak();
    }
    iDX = SPoint::X(&v25);
    iDY = SPoint::Y(&v25);
    v23 = (Y16X16 *)Y16X16::PackXYFast(iDX + 15, iDY + 15);
    iRadius = SSurroundingPoint8::Radius((SSurroundingPoint8 *)&g_sSurroundingHexPoints8[4 * j]);
    if ( j )
    {
      if ( iRadius <= 0 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1481, "iRadius > 0") == 1 )
        __debugbreak();
      v2 = SurroundingHexPointsCount(iRadius - 1);
      if ( j < v2
        && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1482, "i >= SurroundingHexPointsCount(iRadius - 1)") == 1 )
      {
        __debugbreak();
      }
      v3 = SurroundingHexPointsCount(iRadius);
      if ( j >= v3 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1483, "i < SurroundingHexPointsCount(iRadius)") == 1 )
        __debugbreak();
    }
    else if ( iRadius && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1477, "iRadius == 0") == 1 )
    {
      __debugbreak();
    }
    v4 = Grid::Distance(iDX, iDY);
    if ( v4 != iRadius && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1486, "Distance(iDX, iDY) == iRadius") == 1 )
      __debugbreak();
    v5 = Grid::Distance(&v25);
    if ( v5 != iRadius && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1488, "Distance(sPoint ) == iRadius") == 1 )
      __debugbreak();
    v6 = Grid::Distance(0, 0, iDX, iDY);
    if ( v6 != iRadius && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1490, "Distance(0, 0, iDX, iDY) == iRadius") == 1 )
      __debugbreak();
    v7 = Grid::Distance(iDX, iDY, 0, 0);
    if ( v7 != iRadius && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1492, "Distance(iDX, iDY, 0, 0) == iRadius") == 1 )
      __debugbreak();
    v8 = Grid::Distance(&sZero, &v25);
    if ( v8 != iRadius && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1494, "Distance(sZero, sPoint ) == iRadius") == 1 )
      __debugbreak();
    v9 = Grid::Distance(&v25, &sZero);
    if ( v9 != iRadius && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1496, "Distance(sPoint, sZero ) == iRadius") == 1 )
      __debugbreak();
    v10 = Y16X16::DistanceFast(v24, v23);
    if ( v10 != iRadius && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1499, "DistanceFast(iXY0, iXY1) == iRadius") == 1 )
      __debugbreak();
    v11 = Y16X16::DistanceFast(v23, v24);
    if ( v11 != iRadius && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1500, "DistanceFast(iXY1, iXY0) == iRadius") == 1 )
      __debugbreak();
    v12 = Y16X16::Distance2(iDX, iDY);
    if ( v12 != iRadius && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1502, "Distance2(iDX, iDY) == iRadius") == 1 )
      __debugbreak();
    v13 = Y16X16::Distance2a(0, 0, iDX, iDY);
    if ( v13 != iRadius
      && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1503, "Distance2a(0, 0, iDX, iDY) == iRadius") == 1 )
    {
      __debugbreak();
    }
    v14 = Y16X16::Distance2a(iDX, iDY, 0, 0);
    if ( v14 != iRadius
      && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1504, "Distance2a(iDX, iDY, 0, 0) == iRadius") == 1 )
    {
      __debugbreak();
    }
    v15 = Y16X16::Distance2b(0, 0, iDX, iDY);
    if ( v15 != iRadius
      && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1505, "Distance2b(0, 0, iDX, iDY) == iRadius") == 1 )
    {
      __debugbreak();
    }
    v16 = Y16X16::Distance2b(iDX, iDY, 0, 0);
    if ( v16 != iRadius
      && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1506, "Distance2b(iDX, iDY, 0, 0) == iRadius") == 1 )
    {
      __debugbreak();
    }
  }
  CPerformanceCounter::CPerformanceCounter((CPerformanceCounter *)v21);
  for ( k = 0; k < 1056; ++k )
    v40[k] = j__rand() - 0x3FFF;
  CPerformanceCounter::Start(v21);
  for ( m = 0; m < 20000; ++m )
  {
    v36 = m & 0x3FF;
    v31 = v40[v36];
    v32 = v40[v36 + 1];
    dword_41799E0 = Grid::Distance(v31, v32);
    v31 = v40[v36 + 2];
    v32 = v40[v36 + 3];
    dword_41799E0 = Grid::Distance(v31, v32);
    v31 = v40[v36 + 4];
    v32 = v40[v36 + 5];
    dword_41799E0 = Grid::Distance(v31, v32);
    v31 = v40[v36 + 6];
    v32 = v40[v36 + 7];
    dword_41799E0 = Grid::Distance(v31, v32);
    v31 = v40[v36 + 8];
    v32 = v40[v36 + 9];
    dword_41799E0 = Grid::Distance(v31, v32);
  }
  CPerformanceCounter::Measure(v21);
  v17 = CPerformanceCounter::TimeMsStr((CPerformanceCounter *)v21, 0x300000000LL);
  CTrace::Print("Distance test: %s ms", v17);
  CPerformanceCounter::Start(v21);
  for ( n = 0; n < 20000; ++n )
  {
    v35 = n & 0x3FF;
    v29 = v40[v35];
    v30 = v40[v35 + 1];
    dword_41799E0 = Y16X16::Distance2(v29, v30);
    v29 = v40[v35 + 2];
    v30 = v40[v35 + 3];
    dword_41799E0 = Y16X16::Distance2(v29, v30);
    v29 = v40[v35 + 4];
    v30 = v40[v35 + 5];
    dword_41799E0 = Y16X16::Distance2(v29, v30);
    v29 = v40[v35 + 6];
    v30 = v40[v35 + 7];
    dword_41799E0 = Y16X16::Distance2(v29, v30);
    v29 = v40[v35 + 8];
    v30 = v40[v35 + 9];
    dword_41799E0 = Y16X16::Distance2(v29, v30);
  }
  CPerformanceCounter::Measure(v21);
  v18 = CPerformanceCounter::TimeMsStr((CPerformanceCounter *)v21, 0x300000000LL);
  return CTrace::Print("Distance2 test: %s ms", v18);
}


