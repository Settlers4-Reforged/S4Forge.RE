#include "CAIEcoSpecialBuildingInfos.h"

// Definitions for class CAIEcoSpecialBuildingInfos

// address=[0x133a1d0]
// Decompiled from CAIEcoSpecialBuildingInfos *__thiscall CAIEcoSpecialBuildingInfos::CAIEcoSpecialBuildingInfos(
        CAIEcoSpecialBuildingInfos *this)

 CAIEcoSpecialBuildingInfos::CAIEcoSpecialBuildingInfos(void) {
  
  if ( CAIEcoSpecialBuildingInfos::pSingleInstance
    && BBSupportDbgReport(
         2,
         "Ai\\EcoManager\\CAIEcoSpecialBuildingInfos.cpp",
         40,
         "!CAIEcoSpecialBuildingInfos::pSingleInstance") == 1 )
  {
    __debugbreak();
  }
  CAIEcoSpecialBuildingInfos::pSingleInstance = (int)this;
  CAIEcoSpecialBuildingInfos::InitBoundingBoxes(this);
  CAIEcoSpecialBuildingInfos::InitBlockingBitCount(this);
  CAIEcoSpecialBuildingInfos::InitBuildResources(this);
  return this;
}


// address=[0x133a230]
// Decompiled from void __thiscall CAIEcoSpecialBuildingInfos::~CAIEcoSpecialBuildingInfos(AFX_GLOBAL_DATA *this)

 CAIEcoSpecialBuildingInfos::~CAIEcoSpecialBuildingInfos(void) {
  
  CAIEcoSpecialBuildingInfos::pSingleInstance = 0;
}


// address=[0x133a250]
// Decompiled from int CAIEcoSpecialBuildingInfos::TheObject()

static class CAIEcoSpecialBuildingInfos * __cdecl CAIEcoSpecialBuildingInfos::TheObject(void) {
  
  CAIEcoSpecialBuildingInfos *C; // [esp+Ch] [ebp-10h]

  if ( CAIEcoSpecialBuildingInfos::pSingleInstance )
    return CAIEcoSpecialBuildingInfos::pSingleInstance;
  C = (CAIEcoSpecialBuildingInfos *)operator new(0x1038u);
  if ( C )
    CAIEcoSpecialBuildingInfos::CAIEcoSpecialBuildingInfos(C);
  return CAIEcoSpecialBuildingInfos::pSingleInstance;
}


// address=[0x133a2d0]
// Decompiled from int __thiscall CAIEcoSpecialBuildingInfos::GetBoundingBoxInfo(void *this, int a2, int a3)

struct SAIESBIBoundingInfos const *  CAIEcoSpecialBuildingInfos::GetBoundingBoxInfo(int,enum BUILDING_TYPES) {
  
  if ( a2 < 5 )
    return (int)this + 415 * a2 + 5 * a3;
  else
    return 0;
}


// address=[0x133a300]
// Decompiled from int __thiscall CAIEcoSpecialBuildingInfos::GetBlockingBitAmount(unsigned __int16 *this, int a2, int a3)

int  CAIEcoSpecialBuildingInfos::GetBlockingBitAmount(int,enum BUILDING_TYPES) {
  
  if ( a2 < 5 )
    return this[83 * a2 + 1038 + a3];
  else
    return 0;
}


// address=[0x133a330]
// Decompiled from int __thiscall CAIEcoSpecialBuildingInfos::GetNrNeededBoards(unsigned __int8 *this, int a2, int a3)

int  CAIEcoSpecialBuildingInfos::GetNrNeededBoards(int,enum BUILDING_TYPES) {
  
  if ( a2 < 5 )
    return this[83 * a2 + 2906 + a3];
  else
    return 0;
}


// address=[0x133a360]
// Decompiled from int __thiscall CAIEcoSpecialBuildingInfos::GetNrNeededStones(unsigned __int8 *this, int a2, int a3)

int  CAIEcoSpecialBuildingInfos::GetNrNeededStones(int,enum BUILDING_TYPES) {
  
  if ( a2 < 5 )
    return this[83 * a2 + 3321 + a3];
  else
    return 0;
}


// address=[0x133a390]
// Decompiled from int __thiscall CAIEcoSpecialBuildingInfos::GetNrNeededGold(unsigned __int8 *this, int a2, int a3)

int  CAIEcoSpecialBuildingInfos::GetNrNeededGold(int,enum BUILDING_TYPES) {
  
  if ( a2 < 5 )
    return this[83 * a2 + 3736 + a3];
  else
    return 0;
}


// address=[0x133a3c0]
// Decompiled from void __thiscall CAIEcoSpecialBuildingInfos::InitBoundingBoxes(CAIEcoSpecialBuildingInfos *this)

void  CAIEcoSpecialBuildingInfos::InitBoundingBoxes(void) {
  
  _BYTE *BuildingInfo; // [esp+0h] [ebp-10h]
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 5; ++i )
  {
    for ( j = 1; j < 83; ++j )
    {
      BuildingInfo = (_BYTE *)CBuildingInfoMgr::GetBuildingInfo(i, j);
      *((_BYTE *)this + 415 * i + 5 * j) = BuildingInfo[52];
      *((_BYTE *)this + 415 * i + 5 * j + 1) = BuildingInfo[53];
      *((_BYTE *)this + 415 * i + 5 * j + 2) = BuildingInfo[54];
      *((_BYTE *)this + 415 * i + 5 * j + 3) = BuildingInfo[55];
      *((_BYTE *)this + 415 * i + 5 * j + 4) = BuildingInfo[56];
    }
  }
}


// address=[0x133a4a0]
// Decompiled from int __thiscall CAIEcoSpecialBuildingInfos::InitBlockingBitCount(CAIEcoSpecialBuildingInfos *this)

void  CAIEcoSpecialBuildingInfos::InitBlockingBitCount(void) {
  
  _DWORD *v1; // eax
  _BYTE v3[12]; // [esp+4h] [ebp-5Ch] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-50h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-44h] BYREF
  CAIEcoSpecialBuildingInfos *v6; // [esp+28h] [ebp-38h]
  std::_Iterator_base12 *v7; // [esp+2Ch] [ebp-34h]
  std::_Iterator_base12 *v8; // [esp+30h] [ebp-30h]
  int v9; // [esp+34h] [ebp-2Ch]
  int v10; // [esp+38h] [ebp-28h]
  int BuildingInfo; // [esp+3Ch] [ebp-24h]
  int v12; // [esp+40h] [ebp-20h]
  int k; // [esp+44h] [ebp-1Ch]
  int j; // [esp+48h] [ebp-18h]
  int i; // [esp+4Ch] [ebp-14h]
  char v16; // [esp+53h] [ebp-Dh]
  int v17; // [esp+5Ch] [ebp-4h]

  v6 = this;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v5);
  v17 = 0;
  for ( i = 0; i < 5; ++i )
  {
    for ( j = 1; j < 83; ++j )
    {
      BuildingInfo = CBuildingInfoMgr::GetBuildingInfo(i, j);
      v12 = 0;
      v10 = std::vector<unsigned int>::begin(v4);
      v9 = v10;
      LOBYTE(v17) = 1;
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v10);
      LOBYTE(v17) = 0;
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v4);
      while ( 1 )
      {
        v8 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(v3);
        v7 = v8;
        LOBYTE(v17) = 2;
        v16 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v8);
        LOBYTE(v17) = 0;
        std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v3);
        if ( !v16 )
          break;
        if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v5) )
        {
          for ( k = 31; k >= 0; --k )
          {
            v1 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v5);
            if ( (*v1 & (1 << k)) != 0 )
              ++v12;
          }
        }
        std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v5);
      }
      *((_WORD *)v6 + 83 * i + j + 1038) = v12;
    }
  }
  v17 = -1;
  return std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v5);
}


// address=[0x133a640]
// Decompiled from void __thiscall CAIEcoSpecialBuildingInfos::InitBuildResources(CAIEcoSpecialBuildingInfos *this)

void  CAIEcoSpecialBuildingInfos::InitBuildResources(void) {
  
  _BYTE *BuildingInfo; // [esp+0h] [ebp-10h]
  int j; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 5; ++i )
  {
    for ( j = 1; j < 83; ++j )
    {
      BuildingInfo = (_BYTE *)CBuildingInfoMgr::GetBuildingInfo(i, j);
      *((_BYTE *)this + 83 * i + j + 2906) = BuildingInfo[3];
      *((_BYTE *)this + 83 * i + j + 3321) = BuildingInfo[2];
      *((_BYTE *)this + 83 * i + j + 3736) = BuildingInfo[4];
    }
  }
}


// address=[0x3ecd4b4]
// [Decompilation failed for static class CAIEcoSpecialBuildingInfos * CAIEcoSpecialBuildingInfos::pSingleInstance]

