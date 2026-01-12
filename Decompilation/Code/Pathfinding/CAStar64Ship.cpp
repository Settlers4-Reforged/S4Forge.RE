#include "CAStar64Ship.h"

// Definitions for class CAStar64Ship

// address=[0x15d3fd0]
// Decompiled from bool __cdecl CAStar64Ship::IsNotBlocked(int a1)

static bool __cdecl CAStar64Ship::IsNotBlocked(int) {
  
  return !CWaterFlags::IsBlockedWater(a1);
}


// address=[0x15d4000]
// Decompiled from int __cdecl CAStar64Ship::MoveCosts(int a1, int a2)

static int __cdecl CAStar64Ship::MoveCosts(int,int) {
  
  return (4 << (CWaterFlags::WaterFlags(a1) & 0xF) >> (a2 >= 7)) + 16;
}


// address=[0x15d5f20]
// Decompiled from CAStar64Ship *__thiscall CAStar64Ship::CAStar64Ship(CAStar64Ship *this)

 CAStar64Ship::CAStar64Ship(void) {
  
  CAStar64::CAStar64(this);
  *(_DWORD *)this = &CAStar64Ship::_vftable_;
  return this;
}


// address=[0x15d3fa0]
// Decompiled from char __thiscall CAStar64Ship::InitFindPath(CAStar64Ship *this)

bool  CAStar64Ship::InitFindPath(void) {
  
  dword_415C76C = (int (__cdecl *)(_DWORD))CAStar64Ship::IsNotBlocked;
  dword_415C770 = CAStar64Ship::MoveCosts;
  return 1;
}


