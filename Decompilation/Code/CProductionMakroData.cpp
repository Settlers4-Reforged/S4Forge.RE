#include "CProductionMakroData.h"

// Definitions for class CProductionMakroData

// address=[0x2f567f0]
// Decompiled from CProductionMakroData *__thiscall CProductionMakroData::CProductionMakroData(CProductionMakroData *this)
 CProductionMakroData::CProductionMakroData(void) {
  
  std::vector<SMakroEntry>::vector<SMakroEntry>();
  return this;
}


// address=[0x2f56810]
// Decompiled from _DWORD *__thiscall CProductionMakroData::CProductionMakroData(  _DWORD *this,  CDynList **a2,  int a3,  int a4,  int a5,  int a6)
 CProductionMakroData::CProductionMakroData(class CSchedule *,int,enum BUILDING_TYPES,struct SBuildId *,struct SBuildId *) {
  
  struct CDynListEntry *ProductivityControll; // [esp+8h] [ebp-20h]
  int v8; // [esp+Ch] [ebp-1Ch]
  int NearestInputBuildings; // [esp+10h] [ebp-18h]
  int i; // [esp+14h] [ebp-14h]
  int j; // [esp+14h] [ebp-14h]
  int k; // [esp+14h] [ebp-14h]

  std::vector<SMakroEntry>::vector<SMakroEntry>();
  this[125] = a4;
  this[124] = a3;
  NearestInputBuildings = 0;
  v8 = 0;
  for ( i = 0; i < 20; ++i )
  {
    j__memset(&this[2 * i], 0, 8u);
    j__memset(&this[2 * i + 40], 0, 8u);
    j__memset(&this[2 * i + 80], 0, 8u);
  }
  this[127] = 0;
  if ( !this[125] )
    return this;
  for ( j = 0; *(_DWORD *)(a6 + 8 * j); ++j )
  {
    ProductivityControll = CSchedule::GetProductivityControll(a2, *(_DWORD *)(a6 + 8 * j), *(_DWORD *)(a6 + 8 * j + 4));
    if ( ProductivityControll )
      this[127] += CProductivityControll::CalcPotentialOutput(ProductivityControll);
  }
  CSchedule::CopyMakroBuildings(this, a6, 20);
  for ( k = 0; this[2 * k]; ++k )
  {
    NearestInputBuildings = CSchedule::GetNearestInputBuildings(a2, this[2 * k], this[2 * k + 1], 0, (int)(this + 40));
    if ( !NearestInputBuildings )
      NearestInputBuildings = -1;
    v8 = CSchedule::GetNearestInputBuildings(a2, this[2 * k], this[2 * k + 1], 1, (int)(this + 80));
    if ( !v8 )
      v8 = -1;
  }
  this[128] = this[127];
  if ( this[128] > NearestInputBuildings && NearestInputBuildings != -1 )
    this[128] = NearestInputBuildings;
  if ( this[128] > v8 && v8 != -1 )
    this[128] = v8;
  return this;
}


// address=[0x2f56a70]
// Decompiled from int __thiscall CProductionMakroData::~CProductionMakroData(CProductionMakroData *this)
 CProductionMakroData::~CProductionMakroData(void) {
  
  return std::vector<SMakroEntry>::~vector<SMakroEntry>();
}


// address=[0x2f56a90]
// Decompiled from CProductionMakroData *__thiscall CProductionMakroData::GetBuildArray(CProductionMakroData *this)
struct SBuildId *  CProductionMakroData::GetBuildArray(void) {
  
  return this;
}


