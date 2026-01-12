#include "CAStar64Worker.h"

// Definitions for class CAStar64Worker

// address=[0x15d3dc0]
// Decompiled from bool __cdecl CAStar64Worker::IsNotBlocked(int a1)

static bool __cdecl CAStar64Worker::IsNotBlocked(int) {
  
  CTile *v1; // eax
  int v3; // [esp+4h] [ebp-4h]

  v3 = ITiling::NormalTileId(a1);
  if ( v3 < 10 )
    return 0;
  v1 = (CTile *)ITiling::Tile(v3);
  return CAStar64Worker::m_iEcoSectorId == CTile::EcoSectorId(v1);
}


// address=[0x15d3e20]
// Decompiled from int __cdecl CAStar64Worker::MoveCosts(int a1, int a2)

static int __cdecl CAStar64Worker::MoveCosts(int,int) {
  
  int v2; // esi

  if ( a2 >= 7 || !CWorldManager::SettlerId(a1) )
    return CAStar64::WorldMoveCosts(a1);
  v2 = CAStar64::WorldMoveCosts(a1);
  return v2 + CAStar64::SettlerDisplacementCosts(a1, a2);
}


// address=[0x15d5f50]
// Decompiled from CAStar64Worker *__thiscall CAStar64Worker::CAStar64Worker(CAStar64Worker *this)

 CAStar64Worker::CAStar64Worker(void) {
  
  CAStar64Normal::CAStar64Normal(this);
  *(_DWORD *)this = &CAStar64Worker::_vftable_;
  return this;
}


// address=[0x15d3d60]
// Decompiled from bool __thiscall CAStar64Worker::InitFindPath(CAStar64Worker *this)

bool  CAStar64Worker::InitFindPath(void) {
  
  int v1; // eax

  dword_415C76C = (int (__cdecl *)(_DWORD))CAStar64Worker::IsNotBlocked;
  dword_415C770 = CAStar64Worker::MoveCosts;
  v1 = CY6R1X6::WorldIdx(dword_4174BC4);
  CAStar64Worker::m_iEcoSectorId = CWorldManager::EcoSectorId(dword_4174BC0 + v1);
  return CAStar64Worker::m_iEcoSectorId != 0;
}


// address=[0x415c774]
// [Decompilation failed for static int CAStar64Worker::m_iEcoSectorId]

