#include "CQuickScan.h"

// Definitions for class CQuickScan

// address=[0x1305850]
// Decompiled from CQuickScan *__thiscall CQuickScan::CQuickScan(CQuickScan *this, int a2, int a3, unsigned int a4, unsigned int a5)
 CQuickScan::CQuickScan(int a2, int a3, unsigned int a4, unsigned int a5) {
  
  int v5; // eax

  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  if ( a5 >= 0x4B )
    v5 = CSpiralOffsets::Last(74);
  else
    v5 = CSpiralOffsets::Last(a5);
  *((_DWORD *)this + 2) = v5;
  if ( a4 >= 0x4B && BBSupportDbgReport(2, "AI\\AI_AgentsNormal.cpp", 69, "_uRadiusFirst < SPIRAL_RADIUS_MAX") == 1 )
    __debugbreak();
  if ( a5 >= 0x4B && BBSupportDbgReport(2, "AI\\AI_AgentsNormal.cpp", 70, "_uRadiusLast < SPIRAL_RADIUS_MAX") == 1 )
    __debugbreak();
  *((_DWORD *)this + 3) = CSpiralOffsets::First(a4);
  return this;
}


// address=[0x1305900]
// Decompiled from _DWORD *__thiscall sub_1705900(_DWORD *this, int a2, unsigned int a3, unsigned int a4)
 CQuickScan::CQuickScan(int a2, unsigned int a3, unsigned int a4) {
  
  int v4; // eax

  *this = IAIEnvironment::UnpackXFast(a2);
  this[1] = IAIEnvironment::UnpackYFast(a2);
  if ( a4 >= 0x4B )
    v4 = CSpiralOffsets::Last(74);
  else
    v4 = CSpiralOffsets::Last(a4);
  this[2] = v4;
  if ( a3 >= 0x4B && BBSupportDbgReport(2, "AI\\AI_AgentsNormal.cpp", 83, "_uRadiusFirst < SPIRAL_RADIUS_MAX") == 1 )
    __debugbreak();
  if ( a4 >= 0x4B && BBSupportDbgReport(2, "AI\\AI_AgentsNormal.cpp", 84, "_uRadiusLast < SPIRAL_RADIUS_MAX") == 1 )
    __debugbreak();
  this[3] = CSpiralOffsets::First(a3);
  return this;
}


// address=[0x13059c0]
// Decompiled from char __thiscall CQuickScan::NextPosition(CQuickScan *this, int *a2, int *a3)
bool  CQuickScan::NextPosition(int & a2, int & a3) {
  
  int v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-4h]

  v7 = *((_DWORD *)this + 3);
  while ( v7 <= *((_DWORD *)this + 2) )
  {
    v5 = *(_DWORD *)this + CSpiralOffsets::DeltaX(v7);
    v4 = *((_DWORD *)this + 1) + CSpiralOffsets::DeltaY(v7);
    v7 += (v7 >> 5) + 1;
    if ( IAIEnvironment::WorldInWorld(v5, v4) )
    {
      *a2 = v5;
      *a3 = v4;
      *((_DWORD *)this + 3) = v7;
      return 1;
    }
  }
  *((_DWORD *)this + 3) = v7;
  *a2 = 0;
  *a3 = 0;
  return 0;
}


// address=[0x1306470]
// Decompiled from int __thiscall CQuickScan::CenterSectorId(CQuickScan *this)
int  CQuickScan::CenterSectorId(void)const {
  
  return IAIEnvironment::WorldSectorId(*(_DWORD *)this, *((_DWORD *)this + 1));
}


