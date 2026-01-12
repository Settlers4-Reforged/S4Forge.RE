#include "CAStar64Normal.h"

// Definitions for class CAStar64Normal

// address=[0x15d3ce0]
// Decompiled from bool __cdecl CAStar64Normal::IsNotBlocked(int a1)

static bool __cdecl CAStar64Normal::IsNotBlocked(int) {
  
  return (unsigned __int8)CWorldManager::IsBlockedLand(a1) == 0;
}


// address=[0x15d3d10]
// Decompiled from int __cdecl CAStar64Normal::MoveCosts(int a1, int a2)

static int __cdecl CAStar64Normal::MoveCosts(int,int) {
  
  int v2; // esi

  if ( a2 >= 7 || !CWorldManager::SettlerId(a1) )
    return CAStar64::WorldMoveCostsNoRoad(a1);
  v2 = CAStar64::WorldMoveCostsNoRoad(a1);
  return v2 + CAStar64::SettlerDisplacementCosts(a1, a2);
}


// address=[0x15d5ef0]
// Decompiled from CAStar64Normal *__thiscall CAStar64Normal::CAStar64Normal(CAStar64Normal *this)

 CAStar64Normal::CAStar64Normal(void) {
  
  CAStar64::CAStar64(this);
  *(_DWORD *)this = &CAStar64Normal::_vftable_;
  return this;
}


// address=[0x15d3cb0]
// Decompiled from char __thiscall CAStar64Normal::InitFindPath(CAStar64Normal *this)

bool  CAStar64Normal::InitFindPath(void) {
  
  dword_415C76C = (int (__cdecl *)(_DWORD))CAStar64Normal::IsNotBlocked;
  dword_415C770 = CAStar64Normal::MoveCosts;
  return 1;
}


