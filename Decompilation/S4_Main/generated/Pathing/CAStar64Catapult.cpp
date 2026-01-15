#include "CAStar64Catapult.h"

// Definitions for class CAStar64Catapult

// address=[0x15d3ea0]
// Decompiled from bool __cdecl CAStar64Catapult::IsNotBlocked(int a1)
static bool __cdecl CAStar64Catapult::IsNotBlocked(int) {
  
  return (unsigned int)(CWorldManager::CatapultTileId(a1) - 1) < 0xBFFF;
}


// address=[0x15d3ee0]
// Decompiled from int __cdecl CAStar64Catapult::MoveCosts(int a1, int a2)
static int __cdecl CAStar64Catapult::MoveCosts(int,int) {
  
  int v3; // [esp+4h] [ebp-14h]
  int v4; // [esp+8h] [ebp-10h]
  int i; // [esp+10h] [ebp-8h]
  int v6; // [esp+14h] [ebp-4h]

  v6 = 0;
  if ( a2 >= 7 )
    return v6 + 16;
  for ( i = 0; i < 7; ++i )
  {
    v3 = a1 + CWorldManager::SurroundingHexPointRelIndex(i);
    v6 += (unsigned int)(CWorldManager::MapObjectId(v3) - 1) <= 6;
  }
  if ( v6 <= 0 )
    return v6 + 16;
  if ( v6 < 3 )
    v4 = 8 * v6 + 24;
  else
    v4 = 48;
  v6 = v4;
  if ( a2 >= 5 )
    v6 = v4 - 16;
  return v6 + 16;
}


// address=[0x15d5ec0]
// Decompiled from CAStar64Catapult *__thiscall CAStar64Catapult::CAStar64Catapult(CAStar64Catapult *this)
 CAStar64Catapult::CAStar64Catapult(void) {
  
  CAStar64::CAStar64(this);
  *(_DWORD *)this = &CAStar64Catapult::_vftable_;
  return this;
}


// address=[0x15d3e70]
// Decompiled from char __thiscall CAStar64Catapult::InitFindPath(CAStar64Catapult *this)
bool  CAStar64Catapult::InitFindPath(void) {
  
  dword_415C76C = (int (__cdecl *)(_DWORD))j_CAStar64Catapult::IsNotBlocked;
  dword_415C770 = j_CAStar64Catapult::MoveCosts;
  return 1;
}


