#include "CAIBuildingEnsignPositionIterator.h"

// Definitions for class CAIBuildingEnsignPositionIterator

// address=[0x130d390]
// Decompiled from CAIBuildingEnsignPositionIterator *__thiscall CAIBuildingEnsignPositionIterator::CAIBuildingEnsignPositionIterator(
        CAIBuildingEnsignPositionIterator *this,
        int a2,
        int a3)

 CAIBuildingEnsignPositionIterator::CAIBuildingEnsignPositionIterator(int,int) {
  
  *(_DWORD *)this = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, a2, a3);
  return this;
}


// address=[0x130d3c0]
// Decompiled from char __thiscall CAIBuildingEnsignPositionIterator::NextXY(CAIBuildingEnsignPositionIterator *this, int *a2, int *a3)

bool  CAIBuildingEnsignPositionIterator::NextXY(int &,int &) {
  
  Y16X16 *v3; // eax
  unsigned __int8 *BuildingPtr; // [esp+0h] [ebp-8h]

  if ( *(int *)this <= 0 )
    return 0;
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *(_DWORD *)this);
  *(_DWORD *)this = IAnimatedEntity::Next(BuildingPtr);
  v3 = (Y16X16 *)CBuilding::EnsignPackedXY(BuildingPtr);
  Y16X16::UnpackXYFast(v3, a2, a3, (int *)BuildingPtr);
  return 1;
}


// address=[0x130d420]
// Decompiled from // public: bool __thiscall CAIBuildingEnsignPositionIterator::NextWorldIdx(int &)
char __thiscall CAIBuildingEnsignPositionIterator::NextWorldIdx(int *this, _DWORD *a2)

bool  CAIBuildingEnsignPositionIterator::NextWorldIdx(int &) {
  
  unsigned __int8 *BuildingPtr; // [esp+0h] [ebp-8h]

  if ( *this <= 0 )
    return 0;
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *this);
  *this = IAnimatedEntity::Next(BuildingPtr);
  *a2 = CBuilding::EnsignWorldIdx(BuildingPtr);
  return 1;
}


