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
  
  Grid *v0; // eax
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
  const char *v17; // eax
  const char *v18; // eax
  int v20; // [esp-4h] [ebp-1100h]
  const struct SPoint *v21; // [esp+0h] [ebp-10FCh]
  const struct SPoint *v22; // [esp+0h] [ebp-10FCh]
  const struct SPoint *v23; // [esp+0h] [ebp-10FCh]
  _BYTE v24[24]; // [esp+10h] [ebp-10ECh] BYREF
  _DWORD v25[2]; // [esp+28h] [ebp-10D4h] BYREF
  Y16X16 *v26; // [esp+30h] [ebp-10CCh]
  Y16X16 *v27; // [esp+34h] [ebp-10C8h]
  _DWORD v28[2]; // [esp+38h] [ebp-10C4h] BYREF
  int n; // [esp+40h] [ebp-10BCh]
  int m; // [esp+44h] [ebp-10B8h]
  int k; // [esp+48h] [ebp-10B4h]
  int v32; // [esp+4Ch] [ebp-10B0h]
  int v33; // [esp+50h] [ebp-10ACh]
  Grid *v34; // [esp+54h] [ebp-10A8h]
  int v35; // [esp+58h] [ebp-10A4h]
  Grid *v36; // [esp+5Ch] [ebp-10A0h]
  int v37; // [esp+60h] [ebp-109Ch]
  int v38; // [esp+64h] [ebp-1098h]
  int v39; // [esp+68h] [ebp-1094h]
  int j; // [esp+6Ch] [ebp-1090h]
  int i; // [esp+70h] [ebp-108Ch]
  int v42; // [esp+74h] [ebp-1088h]
  _DWORD v43[1056]; // [esp+78h] [ebp-1084h]

  for ( i = 0; i < 6; ++i )
  {
    if ( SPoint::operator*(&g_sNeighborPoints[2 * i], &g_sNeighborOrthos[2 * i])
      && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1433, "g_sNeighborPoints[i] * g_sNeighborOrthos[i] == 0") == 1 )
    {
      __debugbreak();
    }
    if ( !SPoint::operator==(&dword_37D8C70[2 * i], &g_sNeighborPoints[2 * i])
      && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1434, "g_sSurroundingHexPoints[1 + i] == g_sNeighborPoints[i]") == 1 )
    {
      __debugbreak();
    }
    v20 = SPoint::Y((SPoint *)&g_sNeighborPoints[2 * i]);
    v0 = (Grid *)SPoint::X((SPoint *)&g_sNeighborPoints[2 * i]);
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
  SPoint::Zero((_Stl_critical_section *)v25);
  if ( !SPoint::operator==(g_sSurroundingHexPoints, v25)
    && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1446, "g_sSurroundingHexPoints[0] == sZero") == 1 )
  {
    __debugbreak();
  }
  v27 = (Y16X16 *)Y16X16::PackXYFast(15, 15);
  for ( j = 0; j < 721; ++j )
  {
    v1 = (char *)SSurroundingPoint8::Point((SSurroundingPoint8 *)&g_sSurroundingHexPoints8[4 * j]);
    SPoint::operator=(v28, v1);
    if ( j < 37
      && !SPoint::operator==(&g_sSurroundingHexPoints[2 * j], v28)
      && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1461, "g_sSurroundingHexPoints[i] == sPoint") == 1 )
    {
      __debugbreak();
    }
    v36 = (Grid *)SPoint::X((SPoint *)v28);
    v37 = SPoint::Y((SPoint *)v28);
    v26 = (Y16X16 *)Y16X16::PackXYFast((int)v36 + 15, v37 + 15);
    v42 = SSurroundingPoint8::Radius((SSurroundingPoint8 *)&g_sSurroundingHexPoints8[4 * j]);
    if ( j )
    {
      if ( v42 <= 0 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1481, "iRadius > 0") == 1 )
        __debugbreak();
      v2 = SurroundingHexPointsCount(v42 - 1);
      if ( j < v2
        && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1482, "i >= SurroundingHexPointsCount(iRadius - 1)") == 1 )
      {
        __debugbreak();
      }
      v3 = SurroundingHexPointsCount(v42);
      if ( j >= v3 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1483, "i < SurroundingHexPointsCount(iRadius)") == 1 )
        __debugbreak();
    }
    else if ( v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1477, "iRadius == 0") == 1 )
    {
      __debugbreak();
    }
    v4 = Grid::Distance(v36, v37);
    if ( v4 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1486, "Distance(iDX, iDY) == iRadius") == 1 )
      __debugbreak();
    v5 = Grid::Distance((Grid *)v28, v21);
    if ( v5 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1488, "Distance(sPoint ) == iRadius") == 1 )
      __debugbreak();
    v6 = Grid::Distance(0, 0, v36, v37);
    if ( v6 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1490, "Distance(0, 0, iDX, iDY) == iRadius") == 1 )
      __debugbreak();
    v7 = Grid::Distance(v36, v37, 0, 0);
    if ( v7 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1492, "Distance(iDX, iDY, 0, 0) == iRadius") == 1 )
      __debugbreak();
    v8 = Grid::Distance((Grid *)v25, (const struct SPoint *)v28, v22);
    if ( v8 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1494, "Distance(sZero, sPoint ) == iRadius") == 1 )
      __debugbreak();
    v9 = Grid::Distance((Grid *)v28, (const struct SPoint *)v25, v23);
    if ( v9 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1496, "Distance(sPoint, sZero ) == iRadius") == 1 )
      __debugbreak();
    v10 = Y16X16::DistanceFast(v27, v26);
    if ( v10 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1499, "DistanceFast(iXY0, iXY1) == iRadius") == 1 )
      __debugbreak();
    v11 = Y16X16::DistanceFast(v26, v27);
    if ( v11 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1500, "DistanceFast(iXY1, iXY0) == iRadius") == 1 )
      __debugbreak();
    v12 = sub_15DCAA0(v36, v37);
    if ( v12 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1502, "Distance2(iDX, iDY) == iRadius") == 1 )
      __debugbreak();
    v13 = sub_15DCB10(0, 0, v36, v37);
    if ( v13 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1503, "Distance2a(0, 0, iDX, iDY) == iRadius") == 1 )
      __debugbreak();
    v14 = sub_15DCB10(v36, v37, 0, 0);
    if ( v14 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1504, "Distance2a(iDX, iDY, 0, 0) == iRadius") == 1 )
      __debugbreak();
    v15 = sub_15DCBA0(0, 0, v36, v37);
    if ( v15 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1505, "Distance2b(0, 0, iDX, iDY) == iRadius") == 1 )
      __debugbreak();
    v16 = sub_15DCBA0(v36, v37, 0, 0);
    if ( v16 != v42 && BBSupportDbgReport(2, "Pathing\\Grid.cpp", 1506, "Distance2b(iDX, iDY, 0, 0) == iRadius") == 1 )
      __debugbreak();
  }
  CPerformanceCounter::CPerformanceCounter((CPerformanceCounter *)v24);
  for ( k = 0; k < 1056; ++k )
    v43[k] = j__rand() - 0x3FFF;
  CPerformanceCounter::Start((CPerformanceCounter *)v24);
  for ( m = 0; m < 20000; ++m )
  {
    v39 = m & 0x3FF;
    v34 = (Grid *)v43[v39];
    v35 = v43[v39 + 1];
    dword_41799E0 = Grid::Distance(v34, v35);
    v34 = (Grid *)v43[v39 + 2];
    v35 = v43[v39 + 3];
    dword_41799E0 = Grid::Distance(v34, v35);
    v34 = (Grid *)v43[v39 + 4];
    v35 = v43[v39 + 5];
    dword_41799E0 = Grid::Distance(v34, v35);
    v34 = (Grid *)v43[v39 + 6];
    v35 = v43[v39 + 7];
    dword_41799E0 = Grid::Distance(v34, v35);
    v34 = (Grid *)v43[v39 + 8];
    v35 = v43[v39 + 9];
    dword_41799E0 = Grid::Distance(v34, v35);
  }
  CPerformanceCounter::Measure((CPerformanceCounter *)v24);
  v17 = CPerformanceCounter::TimeMsStr((CPerformanceCounter *)v24, 0, 3);
  CTrace::Print("Distance test: %s ms", v17);
  CPerformanceCounter::Start((CPerformanceCounter *)v24);
  for ( n = 0; n < 20000; ++n )
  {
    v38 = n & 0x3FF;
    v32 = v43[v38];
    v33 = v43[v38 + 1];
    dword_41799E0 = sub_15DCAA0(v32, v33);
    v32 = v43[v38 + 2];
    v33 = v43[v38 + 3];
    dword_41799E0 = sub_15DCAA0(v32, v33);
    v32 = v43[v38 + 4];
    v33 = v43[v38 + 5];
    dword_41799E0 = sub_15DCAA0(v32, v33);
    v32 = v43[v38 + 6];
    v33 = v43[v38 + 7];
    dword_41799E0 = sub_15DCAA0(v32, v33);
    v32 = v43[v38 + 8];
    v33 = v43[v38 + 9];
    dword_41799E0 = sub_15DCAA0(v32, v33);
  }
  CPerformanceCounter::Measure((CPerformanceCounter *)v24);
  v18 = CPerformanceCounter::TimeMsStr((CPerformanceCounter *)v24, 0, 3);
  return CTrace::Print("Distance2 test: %s ms", v18);
}


