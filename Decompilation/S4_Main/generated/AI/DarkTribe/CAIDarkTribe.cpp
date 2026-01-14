#include "all_headers.h"

// Definitions for class CAIDarkTribe

// address=[0x132fad0]
// Decompiled from CAIDarkTribe *__thiscall CAIDarkTribe::CAIDarkTribe(CAIDarkTribe *this, int a2)
 CAIDarkTribe::CAIDarkTribe(int) {
  
  int v2; // ecx
  Squares *v3; // eax
  int v4; // edx
  Squares *v5; // eax

  IAIDarkTribeEcoAI::IAIDarkTribeEcoAI(this);
  *(_DWORD *)this = CAIDarkTribe::_vftable_;
  CAIDarkTribe::SAIDTUD::SAIDTUD((CAIDarkTribe *)((char *)this + 40));
  memset((char *)this + 4, 0, 0x24u);
  v3 = (Squares *)CWorldManager::Width(v2);
  *((_DWORD *)this + 2) = Squares::XYToVW(v3);
  v5 = (Squares *)CWorldManager::Height(this, v4);
  *((_DWORD *)this + 3) = Squares::XYToVW(v5);
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 8) = 1;
  g_pAIDarkTribe = (int)this;
  CAIDarkTribe::InitDarkTribeElements(this);
  return this;
}


// address=[0x132fba0]
// Decompiled from void __thiscall CAIDarkTribe::~CAIDarkTribe(CAIDarkTribe *this)
 CAIDarkTribe::~CAIDarkTribe(void) {
  
  *(_DWORD *)this = CAIDarkTribe::_vftable_;
  CAIDarkTribe::UnInitDarkTribeElements(this);
  g_pAIDarkTribe = 0;
  CAIDarkTribe::SAIDTUD::~SAIDTUD((CAIDarkTribe *)((char *)this + 40));
}


// address=[0x132fc00]
// Decompiled from int CAIDarkTribe::CreateInstance()
static class CAIDarkTribe * __cdecl CAIDarkTribe::CreateInstance(int) {
  
  std::bad_function_call *v2; // [esp+Ch] [ebp-10h]

  v2 = (std::bad_function_call *)operator new(0x4084u);
  if ( v2 )
    return CAIDarkTribe::CAIDarkTribe(v2);
  else
    return 0;
}


// address=[0x132fc80]
// Decompiled from CAIDarkTribe *__thiscall CAIDarkTribe::Release(CAIDarkTribe *this)
void  CAIDarkTribe::Release(void) {
  
  CAIDarkTribe *result; // eax

  result = this;
  if ( this )
    return (CAIDarkTribe *)CAIDarkTribe::`scalar deleting destructor'(this, 1u);
  return result;
}


// address=[0x132fcc0]
// Decompiled from bool __thiscall CAIDarkTribe::Execute(CAIDarkTribe *this)
void  CAIDarkTribe::Execute(void) {
  
  CAIDarkTribe::CheckManakopterHallExists(this);
  CAIDarkTribe::CheckSendGardenerPositions(this);
  return CAIDarkTribe::CheckBuildingGrids(this);
}


// address=[0x132fcf0]
// Decompiled from Y16X16 *__thiscall CAIDarkTribe::GetNearGardenerWorkPosition(CAIDarkTribe *this, Y16X16 *a2)
int  CAIDarkTribe::GetNearGardenerWorkPosition(int) {
  
  signed int NrLandConversionPositions; // eax
  unsigned int v3; // eax
  signed int NrBorderElements; // eax
  unsigned int v5; // eax
  _BYTE v7[16]; // [esp+4h] [ebp-6Ch] BYREF
  Y16X16 *v8; // [esp+14h] [ebp-5Ch]
  int BorderElementListIndex; // [esp+18h] [ebp-58h]
  const struct CAIResourceData *v10; // [esp+1Ch] [ebp-54h]
  const struct CAIResourceData *v11; // [esp+20h] [ebp-50h]
  Y16X16 *v12; // [esp+24h] [ebp-4Ch]
  Y16X16 *BorderElement; // [esp+28h] [ebp-48h]
  Squares *v14; // [esp+2Ch] [ebp-44h] BYREF
  Squares *v15; // [esp+30h] [ebp-40h] BYREF
  unsigned int j; // [esp+34h] [ebp-3Ch]
  int v17; // [esp+38h] [ebp-38h]
  int v18; // [esp+3Ch] [ebp-34h]
  Y16X16 *v19; // [esp+40h] [ebp-30h]
  int v20; // [esp+44h] [ebp-2Ch] BYREF
  int v21; // [esp+48h] [ebp-28h] BYREF
  Squares *v22; // [esp+4Ch] [ebp-24h] BYREF
  Squares *v23; // [esp+50h] [ebp-20h] BYREF
  Y16X16 *LandConversionPosition; // [esp+54h] [ebp-1Ch]
  CAIDarkTribe *v25; // [esp+58h] [ebp-18h]
  signed int i; // [esp+5Ch] [ebp-14h]
  char WorkingPosition; // [esp+62h] [ebp-Eh]
  char v28; // [esp+63h] [ebp-Dh]
  int v29; // [esp+6Ch] [ebp-4h]

  v25 = this;
  std::vector<int>::vector<int>(v7);
  v29 = 0;
  v28 = 0;
  v19 = 0;
  std::vector<int>::clear();
  Y16X16::UnpackXYFast(a2, &v14, (int *)&v15);
  v17 = Squares::XYToVW(v14);
  v18 = Squares::XYToVW(v15);
  v12 = (Y16X16 *)Y16X16::PackXYFast(v17, v18);
  BorderElementListIndex = CAIDarkTribe::GetBorderElementListIndex(v25, v12);
  if ( BorderElementListIndex != -1 )
  {
    for ( i = 0; ; ++i )
    {
      NrLandConversionPositions = CAIDarkTribe::GetNrLandConversionPositions(v25);
      if ( i >= NrLandConversionPositions )
        break;
      LandConversionPosition = (Y16X16 *)CAIDarkTribe::GetLandConversionPosition(v25, i);
      Y16X16::UnpackXYFast(LandConversionPosition, &v22, (int *)&v23);
      v20 = Squares::XYToVW(v22);
      v21 = Squares::XYToVW(v23);
      BorderElement = (Y16X16 *)Y16X16::PackXYFast(v20, v21);
      if ( BorderElement == v12 && CAIDarkTribe::IsAdjacent(v25, v14, v15, v22, v23) )
      {
        v19 = LandConversionPosition;
        v28 = 1;
        break;
      }
    }
  }
  if ( !v28 )
  {
    v11 = CAIResourceMap::ResourceDataVW(v17, v18);
    if ( CAIDarkTribe::GetChangeableLandAmount(v25, v11) )
    {
      WorkingPosition = CAIDarkTribe::GetWorkingPosition(v17, v18, v11, v7);
      if ( WorkingPosition )
      {
        for ( i = 0; ; ++i )
        {
          v3 = std::vector<int>::size(v7);
          if ( i >= v3 )
            break;
          LandConversionPosition = *(Y16X16 **)std::vector<int>::operator[](i);
          Y16X16::UnpackXYFast(LandConversionPosition, &v22, (int *)&v23);
          if ( CAIDarkTribe::IsAdjacent(v25, v14, v15, v22, v23) )
          {
            v19 = LandConversionPosition;
            v28 = 1;
            break;
          }
        }
      }
    }
  }
  if ( !v28 )
  {
    for ( i = 0; ; ++i )
    {
      NrBorderElements = CAIDarkTribe::GetNrBorderElements(v25);
      if ( i >= NrBorderElements )
        break;
      BorderElement = (Y16X16 *)CAIDarkTribe::GetBorderElement(v25, i);
      Y16X16::UnpackXYFast(BorderElement, &v20, &v21);
      if ( CAIDarkTribe::IsAdjacent(v25, v17, v18, v20, v21) )
      {
        v10 = CAIResourceMap::ResourceDataVW(v20, v21);
        if ( CAIDarkTribe::GetChangeableLandAmount(v25, v10) )
        {
          WorkingPosition = CAIDarkTribe::GetWorkingPosition(v20, v21, v10, v7);
          if ( WorkingPosition )
          {
            for ( j = 0; ; ++j )
            {
              v5 = std::vector<int>::size(v7);
              if ( j >= v5 )
                break;
              LandConversionPosition = *(Y16X16 **)std::vector<int>::operator[](j);
              Y16X16::UnpackXYFast(LandConversionPosition, &v22, (int *)&v23);
              if ( CAIDarkTribe::IsAdjacent(v25, v14, v15, v22, v23) )
              {
                v19 = LandConversionPosition;
                v28 = 1;
                break;
              }
            }
            if ( !v28 )
            {
              v19 = *(Y16X16 **)std::vector<int>::operator[](0);
              v28 = 1;
              break;
            }
          }
        }
      }
    }
  }
  v8 = v19;
  v29 = -1;
  std::vector<int>::~vector<int>();
  return v8;
}


// address=[0x1330090]
// Decompiled from int __thiscall CAIDarkTribe::GetNextGardenerWorkPosition(CAIDarkTribe *this)
int  CAIDarkTribe::GetNextGardenerWorkPosition(void) {
  
  int LandConversionPosition; // [esp+0h] [ebp-8h]

  LandConversionPosition = 0;
  if ( !CAIDarkTribe::GetNrLandConversionPositions(this) )
    return LandConversionPosition;
  LandConversionPosition = CAIDarkTribe::GetLandConversionPosition(this, 0);
  CAIDarkTribe::RemoveLandConversionPosition(this, LandConversionPosition);
  if ( (int)CAIDarkTribe::GetNrLandConversionPositions(this) < 10 )
    *((_BYTE *)this + 36) = 1;
  return LandConversionPosition;
}


// address=[0x13300e0]
// Decompiled from bool __thiscall CAIDarkTribe::IsBuildingPositionAvailable(CAIDarkTribe *this, int a2)
bool  CAIDarkTribe::IsBuildingPositionAvailable(enum BUILDING_TYPES) {
  
  return a2 == 49 && (int)CAIDarkTribe::GetNrBuildingGrids(this) > 0;
}


// address=[0x1330120]
// Decompiled from bool __thiscall CAIDarkTribe::InvokeBuilding(char *this, unsigned int a2)
bool  CAIDarkTribe::InvokeBuilding(enum BUILDING_TYPES) {
  
  unsigned int NextBuildingPosition; // [esp+8h] [ebp-38h]
  _BYTE v5[32]; // [esp+10h] [ebp-30h] BYREF
  int v6; // [esp+3Ch] [ebp-4h]

  NextBuildingPosition = 0;
  if ( a2 == 49 )
    NextBuildingPosition = CAIDarkTribe::GetNextBuildingPosition((CAIDarkTribe *)this);
  if ( !NextBuildingPosition )
    return NextBuildingPosition != 0;
  CEvn_Logic::CEvn_Logic((CEvn_Logic *)v5, 0x13A1u, a2, NextBuildingPosition, this[4], 0, 0);
  v6 = 0;
  INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v5);
  v6 = -1;
  CEvn_Logic::~CEvn_Logic(v5);
  return NextBuildingPosition != 0;
}


// address=[0x13301f0]
// Decompiled from void __thiscall CAIDarkTribe::UpdateLandChangement(CAIDarkTribe *this, Squares *a2, Squares *a3, bool a4)
void  CAIDarkTribe::UpdateLandChangement(int,int,bool) {
  
  const struct CAIResourceData *v4; // [esp+0h] [ebp-24h]
  _DWORD *v5; // [esp+8h] [ebp-1Ch]
  int v6; // [esp+Ch] [ebp-18h]
  int v7; // [esp+10h] [ebp-14h]
  int v8; // [esp+14h] [ebp-10h]
  int BorderElementListIndex; // [esp+18h] [ebp-Ch]
  int v10; // [esp+1Ch] [ebp-8h]

  v6 = Squares::XYToVW(a2);
  v7 = Squares::XYToVW(a3);
  v10 = Y16X16::PackXYFast(v6, v7);
  v8 = Y16X16::PackXYFast((int)a2, (int)a3);
  if ( CAIDarkTribe::GetLandConversionPositionIndex(this, v8) != -1 )
  {
    CAIDarkTribe::RemoveLandConversionPosition(this, v8);
    if ( (int)CAIDarkTribe::GetNrLandConversionPositions(this) < 10 )
      *((_BYTE *)this + 36) = 1;
  }
  if ( !CAIDarkTribe::IsInBorderElementList(this, v10) )
    goto LABEL_10;
  BorderElementListIndex = CAIDarkTribe::GetBorderElementListIndex(this, v10);
  if ( BorderElementListIndex == -1
    && BBSupportDbgReport(2, "Ai\\Dark Tribe\\CAI_DarkTribe.cpp", 182, "iIndex != AI_DT_UNKNOWN_ELEMENT") == 1 )
  {
    __debugbreak();
  }
  v4 = CAIResourceMap::ResourceDataVW(v6, v7);
  v5 = (_DWORD *)std::vector<int>::operator[](BorderElementListIndex);
  ++*v5;
  if ( *(int *)std::vector<int>::operator[](BorderElementListIndex) > 16 || !CAIDarkTribe::HasChangeableLand(this, v4) )
LABEL_10:
    CAIDarkTribe::UpdateDarkTribeElement(this, v10, a4);
}


// address=[0x1330350]
// Decompiled from int __thiscall CAIDarkTribe::IsGardenerPosition(CAIDarkTribe *this, int a2, int a3)
int  CAIDarkTribe::IsGardenerPosition(int,int) {
  
  return 0;
}


// address=[0x1330360]
// Decompiled from BOOL __thiscall CAIDarkTribe::IsBuildedPosition(CAIDarkTribe *this, Squares *a2, Squares *a3)
int  CAIDarkTribe::IsBuildedPosition(int,int) {
  
  int *OccupiedElement; // eax
  int v4; // edx
  _BYTE v6[8]; // [esp+0h] [ebp-28h] BYREF
  int v7; // [esp+8h] [ebp-20h] BYREF
  int v8; // [esp+Ch] [ebp-1Ch]
  int v9; // [esp+10h] [ebp-18h]
  int v10; // [esp+14h] [ebp-14h]
  int OccupiedElementListIndex; // [esp+1Ch] [ebp-Ch]
  int v13; // [esp+20h] [ebp-8h]
  CAIDarkTribe *v14; // [esp+24h] [ebp-4h]

  v14 = this;
  SAIDTOCCUPIEDELEMENT::SAIDTOCCUPIEDELEMENT((SAIDTOCCUPIEDELEMENT *)&v7, 0, 0);
  v9 = Squares::XYToVW(a2);
  v10 = Squares::XYToVW(a3);
  v13 = Y16X16::PackXYFast(v9, v10);
  if ( !CAIDarkTribe::IsInOccupiedElementList(v14, v13) )
    return 0;
  OccupiedElementListIndex = CAIDarkTribe::GetOccupiedElementListIndex(v14, v13);
  if ( OccupiedElementListIndex == -1 )
    return 0;
  OccupiedElement = (int *)CAIDarkTribe::GetOccupiedElement(v14, v6, OccupiedElementListIndex);
  v4 = OccupiedElement[1];
  v7 = *OccupiedElement;
  v8 = v4;
  return (__int16)v4 == 1 || (__int16)v8 == 2;
}


// address=[0x1330420]
// Decompiled from int __thiscall CAIDarkTribe::IsBuildingPosition(CAIDarkTribe *this, Squares *a2, Squares *a3)
int  CAIDarkTribe::IsBuildingPosition(int,int) {
  
  int v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]

  v5 = Squares::XYToVW(a2);
  v6 = Squares::XYToVW(a3);
  v4 = Y16X16::PackXYFast(v5, v6);
  if ( CAIDarkTribe::IsInBuildingGridList(this, v4) )
    return v5 + v6 * *((_DWORD *)this + 2);
  else
    return 0;
}


// address=[0x1330490]
// Decompiled from int __thiscall CAIDarkTribe::IsOccupiedPosition(CAIDarkTribe *this, Squares *a2, Squares *a3)
int  CAIDarkTribe::IsOccupiedPosition(int,int) {
  
  int v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]

  v5 = Squares::XYToVW(a2);
  v6 = Squares::XYToVW(a3);
  v4 = Y16X16::PackXYFast(v5, v6);
  if ( CAIDarkTribe::IsInOccupiedElementList(this, v4) )
    return v5 + v6 * *((_DWORD *)this + 2);
  else
    return 0;
}


// address=[0x1330500]
// Decompiled from int __thiscall CAIDarkTribe::IsBorderPosition(CAIDarkTribe *this, Squares *a2, Squares *a3)
int  CAIDarkTribe::IsBorderPosition(int,int) {
  
  int v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  int v6; // [esp+8h] [ebp-8h]

  v5 = Squares::XYToVW(a2);
  v6 = Squares::XYToVW(a3);
  v4 = Y16X16::PackXYFast(v5, v6);
  if ( CAIDarkTribe::IsInBorderElementList(this, v4) )
    return v5 + v6 * *((_DWORD *)this + 2);
  else
    return 0;
}


// address=[0x1330570]
// Decompiled from BOOL __thiscall CAIDarkTribe::IsReservedMushroomPosition(CAIDarkTribe *this, Squares *a2, Squares *a3)
int  CAIDarkTribe::IsReservedMushroomPosition(int,int) {
  
  _DWORD *OccupiedElement; // eax
  int v4; // edx
  _BYTE v6[8]; // [esp+0h] [ebp-28h] BYREF
  _DWORD v7[2]; // [esp+8h] [ebp-20h] BYREF
  int v8; // [esp+10h] [ebp-18h]
  int v9; // [esp+14h] [ebp-14h]
  int OccupiedElementListIndex; // [esp+1Ch] [ebp-Ch]
  int v11; // [esp+20h] [ebp-8h]
  CAIDarkTribe *v12; // [esp+24h] [ebp-4h]

  v12 = this;
  SAIDTOCCUPIEDELEMENT::SAIDTOCCUPIEDELEMENT((SAIDTOCCUPIEDELEMENT *)v7, 0, 0);
  v8 = Squares::XYToVW(a2);
  v9 = Squares::XYToVW(a3);
  v11 = Y16X16::PackXYFast(v8, v9);
  if ( !CAIDarkTribe::IsInOccupiedElementList(v12, v11) )
    return 0;
  OccupiedElementListIndex = CAIDarkTribe::GetOccupiedElementListIndex(v12, v11);
  if ( OccupiedElementListIndex == -1 )
    return 0;
  OccupiedElement = (_DWORD *)CAIDarkTribe::GetOccupiedElement(v12, v6, OccupiedElementListIndex);
  v4 = OccupiedElement[1];
  v7[0] = *OccupiedElement;
  v7[1] = v4;
  return (__int16)v4 == 4;
}


// address=[0x1330620]
// Decompiled from unsigned __int8 *__thiscall CAIDarkTribe::InitDarkTribeElements(CAIDarkTribe *this)
void  CAIDarkTribe::InitDarkTribeElements(void) {
  
  unsigned __int8 *result; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int *OccupiedElement; // eax
  int v6; // edx
  int v7; // eax
  Y16X16 *v8; // eax
  int *v9; // eax
  int v10; // edx
  int v11; // eax
  int *v12; // eax
  int v13; // edx
  _BYTE v14[8]; // [esp+0h] [ebp-44h] BYREF
  _BYTE v15[8]; // [esp+8h] [ebp-3Ch] BYREF
  _BYTE v16[8]; // [esp+10h] [ebp-34h] BYREF
  int v17; // [esp+18h] [ebp-2Ch] BYREF
  __int16 v18; // [esp+1Ch] [ebp-28h]
  __int16 v19; // [esp+1Eh] [ebp-26h]
  int v20; // [esp+20h] [ebp-24h]
  Squares *v21; // [esp+24h] [ebp-20h] BYREF
  Squares *v22; // [esp+28h] [ebp-1Ch] BYREF
  unsigned __int8 *BuildingPtr; // [esp+2Ch] [ebp-18h]
  int j; // [esp+30h] [ebp-14h]
  int i; // [esp+34h] [ebp-10h]
  int FirstBuildingId; // [esp+38h] [ebp-Ch]
  int OccupiedElementListIndex; // [esp+3Ch] [ebp-8h]
  CAIDarkTribe *v28; // [esp+40h] [ebp-4h]

  v28 = this;
  SAIDTOCCUPIEDELEMENT::SAIDTOCCUPIEDELEMENT((SAIDTOCCUPIEDELEMENT *)&v17, 0, 0);
  CAIDarkTribe::UnInitDarkTribeElements(v28);
  FirstBuildingId = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)v28 + 1), 50);
  if ( !FirstBuildingId )
    FirstBuildingId = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)v28 + 1), 51);
  if ( !FirstBuildingId && BBSupportDbgReport(2, "Ai\\Dark Tribe\\CAI_DarkTribe.cpp", 594, "iBuildingID") == 1 )
    __debugbreak();
  result = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, FirstBuildingId);
  BuildingPtr = result;
  if ( !result )
    return result;
  for ( i = 0; i < *((_DWORD *)v28 + 3); ++i )
  {
    for ( j = 0; j < *((_DWORD *)v28 + 2); ++j )
    {
      v20 = Y16X16::PackXYFast(j, i);
      CAIDarkTribe::AddToElementList(v28, v20);
    }
  }
  v2 = IEntity::PackedXY(BuildingPtr);
  *((_DWORD *)v28 + 5) = v2;
  Y16X16::UnpackXYFast(*((Y16X16 **)v28 + 5), &v22, (int *)&v21);
  v22 = (Squares *)Squares::XYToVW(v22);
  v21 = (Squares *)Squares::XYToVW(v21);
  v3 = Y16X16::PackXYFast((int)v22, (int)v21);
  *((_DWORD *)v28 + 4) = v3;
  v4 = CBuilding::EnsignWorldIdx(BuildingPtr);
  *((_DWORD *)v28 + 6) = v4;
  OccupiedElementListIndex = CAIDarkTribe::GetOccupiedElementListIndex(v28, *((_DWORD *)v28 + 4));
  if ( OccupiedElementListIndex == -1
    && BBSupportDbgReport(2, "Ai\\Dark Tribe\\CAI_DarkTribe.cpp", 621, "iIndex != AI_DT_UNKNOWN_ELEMENT") == 1 )
  {
    __debugbreak();
  }
  OccupiedElement = (int *)CAIDarkTribe::GetOccupiedElement(v28, v16, OccupiedElementListIndex);
  v6 = *OccupiedElement;
  v7 = OccupiedElement[1];
  v17 = v6;
  v19 = HIWORD(v7);
  v18 = 2;
  CAIDarkTribe::ReplaceOccupiedElement(v28, OccupiedElementListIndex, (const struct SAIDTOCCUPIEDELEMENT *)&v17);
  for ( FirstBuildingId = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)v28 + 1), 49);
        FirstBuildingId;
        FirstBuildingId = IAnimatedEntity::Next(BuildingPtr) )
  {
    BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, FirstBuildingId);
    v8 = (Y16X16 *)IEntity::PackedXY(BuildingPtr);
    Y16X16::UnpackXYFast(v8, &v22, (int *)&v21);
    j = Squares::XYToVW(v22);
    i = Squares::XYToVW(v21);
    v20 = Y16X16::PackXYFast(j, i);
    OccupiedElementListIndex = CAIDarkTribe::GetOccupiedElementListIndex(v28, v20);
    if ( OccupiedElementListIndex == -1
      && BBSupportDbgReport(2, "Ai\\Dark Tribe\\CAI_DarkTribe.cpp", 643, "iIndex != AI_DT_UNKNOWN_ELEMENT") == 1 )
    {
      __debugbreak();
    }
    v9 = (int *)CAIDarkTribe::GetOccupiedElement(v28, v15, OccupiedElementListIndex);
    v10 = *v9;
    v11 = v9[1];
    v17 = v10;
    v19 = HIWORD(v11);
    v18 = 2;
    CAIDarkTribe::ReplaceOccupiedElement(v28, OccupiedElementListIndex, (const struct SAIDTOCCUPIEDELEMENT *)&v17);
    v20 = Y16X16::PackXYFast(j, i + 1);
    OccupiedElementListIndex = CAIDarkTribe::GetOccupiedElementListIndex(v28, v20);
    if ( OccupiedElementListIndex != -1 )
    {
      v12 = (int *)CAIDarkTribe::GetOccupiedElement(v28, v14, OccupiedElementListIndex);
      v13 = v12[1];
      v17 = *v12;
      v19 = HIWORD(v13);
      v18 = 4;
      CAIDarkTribe::ReplaceOccupiedElement(v28, OccupiedElementListIndex, (const struct SAIDTOCCUPIEDELEMENT *)&v17);
    }
  }
  result = (unsigned __int8 *)v28;
  *((_BYTE *)v28 + 36) = 1;
  return result;
}


// address=[0x1330940]
// Decompiled from void __thiscall CAIDarkTribe::UnInitDarkTribeElements(CAIDarkTribe *this)
void  CAIDarkTribe::UnInitDarkTribeElements(void) {
  
  int v2; // [esp+0h] [ebp-4h]

  memset((char *)this + 40, 0, 0x2000u);
  std::vector<SAIDTOCCUPIEDELEMENT>::clear(this);
  std::vector<int>::clear();
  std::vector<int>::clear();
  CAIVWVector::Clear((CAIVWVector *)(v2 + 8308));
}


// address=[0x13309a0]
// Decompiled from void __thiscall CAIDarkTribe::UpdateDarkTribeElement(CAIDarkTribe *this, Y16X16 *a2, bool a3)
void  CAIDarkTribe::UpdateDarkTribeElement(int,bool) {
  
  int *OccupiedElement; // eax
  int v4; // edx
  int *v5; // eax
  int v6; // edx
  int *v7; // eax
  int v8; // edx
  int *v9; // eax
  int v10; // edx
  _BYTE v11[8]; // [esp+0h] [ebp-5Ch] BYREF
  _BYTE v12[8]; // [esp+8h] [ebp-54h] BYREF
  _BYTE v13[8]; // [esp+10h] [ebp-4Ch] BYREF
  _BYTE v14[8]; // [esp+18h] [ebp-44h] BYREF
  int v15; // [esp+20h] [ebp-3Ch] BYREF
  int v16; // [esp+24h] [ebp-38h]
  int v17; // [esp+28h] [ebp-34h]
  int v18; // [esp+2Ch] [ebp-30h]
  int v19; // [esp+30h] [ebp-2Ch] BYREF
  CAIResourceData *v20; // [esp+34h] [ebp-28h]
  int v21; // [esp+38h] [ebp-24h]
  int OccupiedElementListIndex; // [esp+3Ch] [ebp-20h]
  int v23; // [esp+40h] [ebp-1Ch]
  int v24; // [esp+44h] [ebp-18h]
  int i; // [esp+48h] [ebp-14h]
  int v26; // [esp+4Ch] [ebp-10h] BYREF
  int v27; // [esp+50h] [ebp-Ch] BYREF
  int BorderElementInWorkListIndex; // [esp+54h] [ebp-8h]
  CAIDarkTribe *v29; // [esp+58h] [ebp-4h]

  v29 = this;
  SAIDTOCCUPIEDELEMENT::SAIDTOCCUPIEDELEMENT((SAIDTOCCUPIEDELEMENT *)&v15, 0, 0);
  Y16X16::UnpackXYFast(a2, &v26, &v27);
  if ( v26 >= 0 && v26 < *((_DWORD *)v29 + 2) && v27 >= 0 && v27 < *((_DWORD *)v29 + 3) )
  {
    v20 = CAIResourceMap::ResourceDataVW(v26, v27);
    if ( a3 )
    {
      if ( !CAIDarkTribe::IsInOccupiedElementList(v29, a2) )
        CAIDarkTribe::AddToElementList(v29, a2);
      if ( !CAIDarkTribe::IsInBorderElementInWorkList(v29, a2) )
        std::vector<int>::push_back(&a2);
      if ( !CAIDarkTribe::IsInBorderElementList(v29, a2) )
      {
        std::vector<int>::push_back(&a2);
        v19 = 0;
        std::vector<int>::push_back(&v19);
      }
      if ( !CAIDarkTribe::HasChangeableLand(v29, v20) )
      {
        *((_BYTE *)v29 + 37) = 1;
        for ( i = 0; i < 6; ++i )
        {
          v23 = g_sNeighborPoints[2 * i] + v26;
          v24 = dword_37D8C0C[2 * i] + v27;
          if ( v24 >= 0 && v24 <= *((_DWORD *)v29 + 3) && v23 >= 0 && v23 <= *((_DWORD *)v29 + 2) )
          {
            if ( (*(unsigned __int8 (__thiscall **)(void *, int, int, int, int))(*(_DWORD *)g_pTiling + 32))(
                   g_pTiling,
                   v26,
                   v27,
                   v23,
                   v24) )
            {
              v18 = Y16X16::PackXYFast(v23, v24);
              CAIDarkTribe::AddToElementList(v29, v18);
            }
          }
        }
        if ( CAIDarkTribe::IsInBorderElementInWorkList(v29, a2) )
        {
          BorderElementInWorkListIndex = CAIDarkTribe::GetBorderElementInWorkListIndex(v29, a2);
          CAIDarkTribe::RemoveBorderElementInWork(v29, BorderElementInWorkListIndex);
        }
        if ( CAIDarkTribe::IsInBorderElementList(v29, a2) )
        {
          BorderElementInWorkListIndex = CAIDarkTribe::GetBorderElementListIndex(v29, a2);
          CAIDarkTribe::RemoveBorderElement(v29, BorderElementInWorkListIndex);
        }
        OccupiedElementListIndex = CAIDarkTribe::GetOccupiedElementListIndex(v29, a2);
        v17 = Y16X16::PackXYFast(v26, v27 + 1);
        v21 = CAIDarkTribe::GetOccupiedElementListIndex(v29, v17);
        if ( v21 == -1 )
        {
          OccupiedElement = (int *)CAIDarkTribe::GetOccupiedElement(v29, v14, OccupiedElementListIndex);
          v4 = OccupiedElement[1];
          v15 = *OccupiedElement;
          HIWORD(v16) = HIWORD(v4);
          LOWORD(v16) = v4 & 0xFFFA | 4;
        }
        else
        {
          v5 = (int *)CAIDarkTribe::GetOccupiedElement(v29, v13, v21);
          v6 = v5[1];
          v15 = *v5;
          v16 = v6;
          if ( (v6 & 4) != 0 )
          {
            v7 = (int *)CAIDarkTribe::GetOccupiedElement(v29, v12, OccupiedElementListIndex);
            v8 = v7[1];
            v15 = *v7;
            HIWORD(v16) = HIWORD(v8);
            LOWORD(v16) = v8 & 0xFFFA | 1;
          }
          else if ( (v16 & 1) == 0 )
          {
            LOWORD(v16) = v16 | 4;
            LOWORD(v16) = v16 & 0xFFFE;
            v9 = (int *)CAIDarkTribe::GetOccupiedElement(v29, v11, OccupiedElementListIndex);
            v10 = v9[1];
            v15 = *v9;
            HIWORD(v16) = HIWORD(v10);
            LOWORD(v16) = v10 & 0xFFFA | 1;
          }
        }
      }
    }
    else if ( CAIDarkTribe::IsInOccupiedElementList(v29, a2) && !CAIResourceData::GroundInfo1(v20, 0) )
    {
      BorderElementInWorkListIndex = CAIDarkTribe::GetOccupiedElementListIndex(v29, a2);
      CAIDarkTribe::RemoveOccupiedElement(v29, BorderElementInWorkListIndex);
      BorderElementInWorkListIndex = CAIDarkTribe::GetBorderElementListIndex(v29, a2);
      CAIDarkTribe::RemoveBorderElement(v29, BorderElementInWorkListIndex);
      BorderElementInWorkListIndex = CAIDarkTribe::GetBorderElementInWorkListIndex(v29, a2);
      CAIDarkTribe::RemoveBorderElementInWork(v29, BorderElementInWorkListIndex);
      CAIDarkTribe::AddToElementList(v29, a2);
      *((_BYTE *)v29 + 37) = 1;
    }
  }
}


// address=[0x1330d60]
// Decompiled from void __thiscall CAIDarkTribe::AddToElementList(CAIDarkTribe *this, Y16X16 *a2)
void  CAIDarkTribe::AddToElementList(int) {
  
  Y16X16 **OccupiedElement; // eax
  Y16X16 *v3; // edx
  Y16X16 *v4; // eax
  int *v5; // eax
  int v6; // edx
  int *v7; // eax
  int v8; // edx
  char v9[8]; // [esp+0h] [ebp-60h] BYREF
  char v10[8]; // [esp+8h] [ebp-58h] BYREF
  char v11[8]; // [esp+10h] [ebp-50h] BYREF
  int v12; // [esp+18h] [ebp-48h] BYREF
  int v13; // [esp+1Ch] [ebp-44h]
  int v14; // [esp+20h] [ebp-40h] BYREF
  int v15; // [esp+24h] [ebp-3Ch]
  Y16X16 *v16; // [esp+28h] [ebp-38h] BYREF
  Y16X16 *v17; // [esp+2Ch] [ebp-34h]
  int v18; // [esp+30h] [ebp-30h] BYREF
  int v19; // [esp+34h] [ebp-2Ch]
  int v20; // [esp+38h] [ebp-28h]
  int v21; // [esp+3Ch] [ebp-24h] BYREF
  int v22; // [esp+40h] [ebp-20h]
  int v23; // [esp+44h] [ebp-1Ch]
  CAIResourceData *v24; // [esp+48h] [ebp-18h]
  int OccupiedElementListIndex; // [esp+4Ch] [ebp-14h]
  int v26; // [esp+50h] [ebp-10h] BYREF
  int v27; // [esp+54h] [ebp-Ch] BYREF
  CAIDarkTribe *v28; // [esp+58h] [ebp-8h]
  bool v29; // [esp+5Ch] [ebp-4h]
  bool v30; // [esp+5Dh] [ebp-3h]
  bool v31; // [esp+5Eh] [ebp-2h]
  bool v32; // [esp+5Fh] [ebp-1h]

  v28 = this;
  SAIDTOCCUPIEDELEMENT::SAIDTOCCUPIEDELEMENT((SAIDTOCCUPIEDELEMENT *)&v14, 0, 0);
  SAIDTOCCUPIEDELEMENT::SAIDTOCCUPIEDELEMENT((SAIDTOCCUPIEDELEMENT *)&v12, 0, 0);
  SAIDTOCCUPIEDELEMENT::SAIDTOCCUPIEDELEMENT((SAIDTOCCUPIEDELEMENT *)&v16, 0, 0);
  Y16X16::UnpackXYFast(a2, &v26, &v27);
  if ( v26 >= 0 && v26 < *((_DWORD *)v28 + 2) && v27 >= 0 && v27 < *((_DWORD *)v28 + 3) )
  {
    v24 = CAIResourceMap::ResourceDataVW(v26, v27);
    if ( CAIResourceData::GroundInfo1(v24, 0) )
    {
      if ( !CAIDarkTribe::IsInOccupiedElementList(v28, a2) )
      {
        LOWORD(v17) = 0;
        v16 = a2;
        CAIDarkTribe::PushNewOccupiedElement(v28, (const struct SAIDTOCCUPIEDELEMENT *)&v16);
      }
      if ( CAIDarkTribe::HasChangeableLand(v28, v24) )
      {
        if ( !CAIDarkTribe::IsInBorderElementList(v28, a2) )
        {
          std::vector<int>::push_back(&a2);
          v21 = 0;
          std::vector<int>::push_back(&v21);
        }
        if ( !CAIDarkTribe::IsInBorderElementInWorkList(v28, a2) )
          std::vector<int>::push_back(&a2);
      }
      else
      {
        OccupiedElementListIndex = CAIDarkTribe::GetOccupiedElementListIndex(v28, a2);
        if ( OccupiedElementListIndex != -1 )
        {
          OccupiedElement = (Y16X16 **)CAIDarkTribe::GetOccupiedElement(v28, v11, OccupiedElementListIndex);
          v3 = *OccupiedElement;
          v4 = OccupiedElement[1];
          v16 = v3;
          v17 = v4;
          if ( !(_WORD)v4 )
          {
            v30 = 0;
            if ( v27 > 0 )
            {
              v20 = Y16X16::PackXYFast(v26, v27 - 1);
              v23 = CAIDarkTribe::GetOccupiedElementListIndex(v28, v20);
              if ( v23 != -1 )
              {
                v5 = (int *)CAIDarkTribe::GetOccupiedElement(v28, v10, v23);
                v6 = v5[1];
                v14 = *v5;
                v15 = v6;
                v32 = (__int16)v6 == 1 || (__int16)v15 == 2;
                v30 = v32;
              }
            }
            v29 = 0;
            if ( v27 < *((_DWORD *)v28 + 3) )
            {
              v19 = Y16X16::PackXYFast(v26, v27 + 1);
              v22 = CAIDarkTribe::GetOccupiedElementListIndex(v28, v19);
              if ( v22 != -1 )
              {
                v7 = (int *)CAIDarkTribe::GetOccupiedElement(v28, v9, v22);
                v8 = v7[1];
                v12 = *v7;
                v13 = v8;
                v31 = (__int16)v8 == 1 || (__int16)v13 == 2;
                v29 = v31;
              }
            }
            if ( v30 )
            {
              LOWORD(v17) = 4;
              CAIDarkTribe::ReplaceOccupiedElement(
                v28,
                OccupiedElementListIndex,
                (const struct SAIDTOCCUPIEDELEMENT *)&v16);
            }
            else if ( !v29 )
            {
              LOWORD(v17) = 1;
              CAIDarkTribe::ReplaceOccupiedElement(
                v28,
                OccupiedElementListIndex,
                (const struct SAIDTOCCUPIEDELEMENT *)&v16);
              CAIVWVector::PushBack((CAIDarkTribe *)((char *)v28 + 8308), v16);
            }
          }
        }
      }
    }
    else if ( CAIDarkTribe::IsPureDarkLandAround(v28, v26, v27) && CAIDarkTribe::HasChangeableLand(v28, v24) )
    {
      if ( !CAIDarkTribe::IsInBorderElementList(v28, a2) )
      {
        std::vector<int>::push_back(&a2);
        v18 = 0;
        std::vector<int>::push_back(&v18);
      }
      if ( !CAIDarkTribe::IsInBorderElementInWorkList(v28, a2) )
        std::vector<int>::push_back(&a2);
    }
  }
}


// address=[0x13310b0]
// Decompiled from int __thiscall CAIDarkTribe::PushNewOccupiedElement(CAIDarkTribe *this, const struct SAIDTOCCUPIEDELEMENT *a2)
void  CAIDarkTribe::PushNewOccupiedElement(struct SAIDTOCCUPIEDELEMENT const &) {
  
  int result; // eax
  Grid *v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-8h]

  if ( *((_WORD *)a2 + 2)
    && BBSupportDbgReport(2, "Ai\\Dark Tribe\\CAI_DarkTribe.cpp", 975, "_rNewElement.m_iFlags == AI_DT_FLAG_UNDEFINED") == 1 )
  {
    __debugbreak();
  }
  if ( CAIDarkTribe::IsInOccupiedElementList(this, *(_DWORD *)a2)
    && BBSupportDbgReport(
         2,
         "Ai\\Dark Tribe\\CAI_DarkTribe.cpp",
         976,
         "!IsInOccupiedElementList(_rNewElement.m_iPackedVW)") == 1 )
  {
    __debugbreak();
  }
  v5 = std::vector<SAIDTOCCUPIEDELEMENT>::size((char *)this + 8232);
  std::vector<SAIDTOCCUPIEDELEMENT>::push_back(a2);
  if ( *(_DWORD *)std::vector<SAIDTOCCUPIEDELEMENT>::operator[](v5) != *(_DWORD *)a2
    && BBSupportDbgReport(
         2,
         "Ai\\Dark Tribe\\CAI_DarkTribe.cpp",
         982,
         "m_sUnInitializedVars.vuOccupiedElements[iNewIndex].m_iPackedVW == _rNewElement.m_iPackedVW") == 1 )
  {
    __debugbreak();
  }
  v3 = (Grid *)Y16X16::UnpackXFast(*(_DWORD *)a2);
  v4 = Y16X16::UnpackYFast(*(_DWORD *)a2);
  if ( !Grid::InQuadrat(v3, v4, 64)
    && BBSupportDbgReport(
         2,
         "Ai\\Dark Tribe\\CAI_DarkTribe.cpp",
         987,
         "Grid::InQuadrat(iV, iW, Squares::SQUARE_GRID_MAX_V_W)") == 1 )
  {
    __debugbreak();
  }
  result = v5 + 1;
  *((_WORD *)this + 64 * v4 + (_DWORD)v3 + 20) = v5 + 1;
  return result;
}


// address=[0x1331200]
// Decompiled from char __thiscall CAIDarkTribe::ReplaceOccupiedElement(CAIDarkTribe *this, int a2, const struct SAIDTOCCUPIEDELEMENT *a3)
bool  CAIDarkTribe::ReplaceOccupiedElement(int,struct SAIDTOCCUPIEDELEMENT const &) {
  
  int v4; // [esp+0h] [ebp-18h]
  int v5; // [esp+4h] [ebp-14h]
  Grid *v6; // [esp+8h] [ebp-10h]
  int v7; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]

  if ( a2 < 0 || a2 >= CAIDarkTribe::GetNrOccupiedElements(this) )
    return 0;
  v8 = std::vector<SAIDTOCCUPIEDELEMENT>::operator[](a2);
  v4 = Y16X16::UnpackXFast(*(_DWORD *)v8);
  v5 = Y16X16::UnpackYFast(*(_DWORD *)v8);
  if ( *((unsigned __int16 *)this + 64 * v5 + v4 + 20) != a2 + 1
    && BBSupportDbgReport(
         2,
         "Ai\\Dark Tribe\\CAI_DarkTribe.cpp",
         1009,
         "m_sUnInitializedVars.m_uOccupiedElementsIndices[iOldW][iOldV] == 1 + _iIndex") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)this + 64 * v5 + v4 + 20) = 0;
  *(_WORD *)(v8 + 4) = *((_WORD *)a3 + 2);
  *(_DWORD *)v8 = *(_DWORD *)a3;
  v6 = (Grid *)Y16X16::UnpackXFast(*(_DWORD *)a3);
  v7 = Y16X16::UnpackYFast(*(_DWORD *)a3);
  if ( !Grid::InQuadrat(v6, v7, 64)
    && BBSupportDbgReport(
         2,
         "Ai\\Dark Tribe\\CAI_DarkTribe.cpp",
         1019,
         "Grid::InQuadrat(iNewV, iNewW, Squares::SQUARE_GRID_MAX_V_W)") == 1 )
  {
    __debugbreak();
  }
  if ( *((_WORD *)this + 64 * v7 + (_DWORD)v6 + 20) )
  {
    if ( BBSupportDbgReport(
           2,
           "Ai\\Dark Tribe\\CAI_DarkTribe.cpp",
           1020,
           "m_sUnInitializedVars.m_uOccupiedElementsIndices[iNewW][iNewV] == 0") == 1 )
      __debugbreak();
  }
  *((_WORD *)this + 64 * v7 + (_DWORD)v6 + 20) = a2 + 1;
  return 1;
}


// address=[0x1331380]
// Decompiled from char __thiscall CAIDarkTribe::RemoveOccupiedElement(CAIDarkTribe *this, int a2)
void  CAIDarkTribe::RemoveOccupiedElement(int) {
  
  int NrOccupiedElements; // eax
  int *v3; // eax
  int v4; // edx
  int v6[2]; // [esp+0h] [ebp-1Ch] BYREF
  int v7; // [esp+8h] [ebp-14h]
  int v8; // [esp+Ch] [ebp-10h]
  int v9; // [esp+10h] [ebp-Ch]
  int v10; // [esp+14h] [ebp-8h]
  CAIDarkTribe *v11; // [esp+18h] [ebp-4h]

  v11 = this;
  NrOccupiedElements = CAIDarkTribe::GetNrOccupiedElements(this);
  v9 = NrOccupiedElements;
  if ( a2 < 0 )
    return NrOccupiedElements;
  LOBYTE(NrOccupiedElements) = a2;
  if ( a2 >= v9 )
    return NrOccupiedElements;
  v10 = v9 - 1;
  v3 = (int *)std::vector<SAIDTOCCUPIEDELEMENT>::operator[](v9 - 1);
  v4 = v3[1];
  v6[0] = *v3;
  v6[1] = v4;
  v7 = Y16X16::UnpackXFast(v6[0]);
  v8 = Y16X16::UnpackYFast(v6[0]);
  if ( *((unsigned __int16 *)v11 + 64 * v8 + v7 + 20) != v9
    && BBSupportDbgReport(
         2,
         "Ai\\Dark Tribe\\CAI_DarkTribe.cpp",
         1047,
         "m_sUnInitializedVars.m_uOccupiedElementsIndices[iLastW][iLastV] == 1 + iLastIndex") == 1 )
  {
    __debugbreak();
  }
  *((_WORD *)v11 + 64 * v8 + v7 + 20) = 0;
  LOBYTE(NrOccupiedElements) = std::vector<SAIDTOCCUPIEDELEMENT>::pop_back((char *)v11 + 8232);
  if ( a2 < v10 )
    LOBYTE(NrOccupiedElements) = CAIDarkTribe::ReplaceOccupiedElement(v11, a2, (const struct SAIDTOCCUPIEDELEMENT *)v6);
  return NrOccupiedElements;
}


// address=[0x1331470]
// Decompiled from bool __thiscall CAIDarkTribe::IsInOccupiedElementList(CAIDarkTribe *this, int a2)
bool  CAIDarkTribe::IsInOccupiedElementList(int) {
  
  return CAIDarkTribe::GetOccupiedElementListIndex(this, a2) != -1;
}


// address=[0x13314a0]
// Decompiled from int __thiscall CAIDarkTribe::GetOccupiedElementListIndex(CAIDarkTribe *this, int a2)
int  CAIDarkTribe::GetOccupiedElementListIndex(int) {
  
  Grid *v4; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  v4 = (Grid *)Y16X16::UnpackXFast(a2);
  v5 = Y16X16::UnpackYFast(a2);
  if ( !Grid::InQuadrat(v4, v5, 64)
    && BBSupportDbgReport(
         2,
         "Ai\\Dark Tribe\\CAI_DarkTribe.cpp",
         1076,
         "Grid::InQuadrat(iV, iW, Squares::SQUARE_GRID_MAX_V_W)") == 1 )
  {
    __debugbreak();
  }
  return *((unsigned __int16 *)this + 64 * v5 + (_DWORD)v4 + 20) - 1;
}


// address=[0x1331520]
// Decompiled from void __thiscall CAIDarkTribe::RemoveBorderElement(CAIDarkTribe *this, int a2)
void  CAIDarkTribe::RemoveBorderElement(int) {
  
  int NrBorderElements; // eax
  _DWORD *v3; // esi
  int v4; // eax
  _DWORD *v5; // esi
  int v6; // [esp+4h] [ebp-8h]

  if ( a2 >= 0 && a2 < CAIDarkTribe::GetNrBorderElements(this) )
  {
    v6 = *(_DWORD *)std::vector<int>::operator[](a2);
    CAIDarkTribe::CleanLandConversionPositionsOfGrid(this, v6);
    NrBorderElements = CAIDarkTribe::GetNrBorderElements(this);
    v3 = (_DWORD *)std::vector<int>::operator[](NrBorderElements - 1);
    *(_DWORD *)std::vector<int>::operator[](a2) = *v3;
    std::vector<int>::pop_back((char *)this + 8248);
    v4 = std::vector<int>::size((char *)this + 8264);
    v5 = (_DWORD *)std::vector<int>::operator[](v4 - 1);
    *(_DWORD *)std::vector<int>::operator[](a2) = *v5;
    std::vector<int>::pop_back((char *)this + 8264);
  }
}


// address=[0x1331600]
// Decompiled from int __thiscall CAIDarkTribe::GetBorderElementListIndex(CAIDarkTribe *this, int a2)
int  CAIDarkTribe::GetBorderElementListIndex(int)const {
  
  int NrBorderElements; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  NrBorderElements = CAIDarkTribe::GetNrBorderElements(this);
  for ( i = 0; i < NrBorderElements; ++i )
  {
    if ( CAIDarkTribe::GetBorderElement(this, i) == a2 )
      return i;
  }
  return -1;
}


// address=[0x1331650]
// Decompiled from void __thiscall CAIDarkTribe::RemoveBorderElementInWork(CAIDarkTribe *this, int a2)
void  CAIDarkTribe::RemoveBorderElementInWork(int) {
  
  int NrBorderElementsInWork; // eax
  _DWORD *v3; // esi

  if ( a2 >= 0 && a2 < CAIDarkTribe::GetNrBorderElementsInWork(this) )
  {
    NrBorderElementsInWork = CAIDarkTribe::GetNrBorderElementsInWork(this);
    v3 = (_DWORD *)std::vector<int>::operator[](NrBorderElementsInWork - 1);
    *(_DWORD *)std::vector<int>::operator[](a2) = *v3;
    std::vector<int>::pop_back((char *)this + 8280);
  }
}


// address=[0x13316c0]
// Decompiled from int __thiscall CAIDarkTribe::GetBorderElementInWorkListIndex(CAIDarkTribe *this, int a2)
int  CAIDarkTribe::GetBorderElementInWorkListIndex(int)const {
  
  int NrBorderElementsInWork; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  NrBorderElementsInWork = CAIDarkTribe::GetNrBorderElementsInWork(this);
  for ( i = 0; i < NrBorderElementsInWork; ++i )
  {
    if ( CAIDarkTribe::GetBorderElementInWork(this, i) == a2 )
      return i;
  }
  return -1;
}


// address=[0x1331710]
// Decompiled from int __thiscall CAIDarkTribe::GetLandConversionPosition(CAIDarkTribe *this, int a2)
int  CAIDarkTribe::GetLandConversionPosition(int)const {
  
  _BYTE v3[12]; // [esp+4h] [ebp-48h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-3Ch] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-30h] BYREF
  int v6; // [esp+28h] [ebp-24h]
  int v7; // [esp+2Ch] [ebp-20h]
  int v8; // [esp+30h] [ebp-1Ch]
  int v9; // [esp+34h] [ebp-18h]
  CAIDarkTribe *v10; // [esp+38h] [ebp-14h]
  int v11; // [esp+3Ch] [ebp-10h]
  int v12; // [esp+48h] [ebp-4h]

  v10 = this;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>(v5);
  v12 = 0;
  if ( a2 >= 0 && a2 < CAIDarkTribe::GetNrLandConversionPositions(v10) )
  {
    v11 = 0;
    v8 = std::list<int>::begin(v4);
    v7 = v8;
    LOBYTE(v12) = 1;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>::operator=(v8);
    LOBYTE(v12) = 0;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>(v4);
    while ( v11 < a2 )
    {
      std::_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>::operator++(v3, 0);
      std::_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>(v3);
      ++v11;
    }
    v6 = *(_DWORD *)std::_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>::operator*(v5);
    v12 = -1;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>(v5);
    return v6;
  }
  else
  {
    v9 = 0;
    v12 = -1;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<int>>>(v5);
    return v9;
  }
}


// address=[0x1331810]
// Decompiled from int __thiscall CAIDarkTribe::GetLandConversionPositionIndex(CAIDarkTribe *this, int a2)
int  CAIDarkTribe::GetLandConversionPositionIndex(int)const {
  
  int NrLandConversionPositions; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  NrLandConversionPositions = CAIDarkTribe::GetNrLandConversionPositions(this);
  for ( i = 0; i < NrLandConversionPositions; ++i )
  {
    if ( CAIDarkTribe::GetLandConversionPosition(this, i) == a2 )
      return i;
  }
  return -1;
}


// address=[0x1331860]
// Decompiled from int __thiscall CAIDarkTribe::CleanLandConversionPositionsOfGrid(CAIDarkTribe *this, int a2)
void  CAIDarkTribe::CleanLandConversionPositionsOfGrid(int) {
  
  int result; // eax
  Squares *v3; // eax
  Squares *v4; // eax
  int v5; // eax
  int v6; // [esp-4h] [ebp-18h]
  int NrLandConversionPositions; // [esp+4h] [ebp-10h]
  int LandConversionPosition; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]

  result = CAIDarkTribe::GetNrLandConversionPositions(this);
  NrLandConversionPositions = result;
  for ( i = 0; i < NrLandConversionPositions; ++i )
  {
    LandConversionPosition = CAIDarkTribe::GetLandConversionPosition(this, i);
    v3 = (Squares *)Y16X16::UnpackYFast(LandConversionPosition);
    v6 = Squares::XYToVW(v3);
    v4 = (Squares *)Y16X16::UnpackXFast(LandConversionPosition);
    v5 = Squares::XYToVW(v4);
    if ( Y16X16::PackXYFast(v5, v6) == a2 )
    {
      CAIDarkTribe::RemoveLandConversionPosition(this, LandConversionPosition);
      NrLandConversionPositions = CAIDarkTribe::GetNrLandConversionPositions(this);
      if ( NrLandConversionPositions < 10 )
        *((_BYTE *)this + 36) = 1;
      --i;
    }
    result = i + 1;
  }
  return result;
}


// address=[0x1331920]
// Decompiled from int __thiscall CAIDarkTribe::CheckSendGardenerPositions(CAIDarkTribe *this)
void  CAIDarkTribe::CheckSendGardenerPositions(void) {
  
  unsigned int v1; // eax
  _BYTE v3[16]; // [esp+4h] [ebp-48h] BYREF
  _BYTE v4[4]; // [esp+14h] [ebp-38h] BYREF
  int v5; // [esp+18h] [ebp-34h] BYREF
  Y16X16 *BorderElementInWork; // [esp+1Ch] [ebp-30h]
  int v7; // [esp+20h] [ebp-2Ch] BYREF
  int v8; // [esp+24h] [ebp-28h] BYREF
  const struct CAIResourceData *v9; // [esp+28h] [ebp-24h]
  Y16X16 *v10; // [esp+2Ch] [ebp-20h] BYREF
  unsigned int i; // [esp+30h] [ebp-1Ch]
  int NextCurrentUsedInWorkElementIndex; // [esp+34h] [ebp-18h]
  CAIDarkTribe *v13; // [esp+38h] [ebp-14h]
  char v15; // [esp+3Fh] [ebp-Dh]
  int v16; // [esp+48h] [ebp-4h]

  v13 = this;
  std::vector<int>::vector<int>(v3);
  v16 = 0;
  if ( *((_BYTE *)v13 + 36) )
  {
    *((_BYTE *)v13 + 36) = 0;
    if ( (unsigned int)std::list<int>::size((char *)v13 + 8296) < 0x14 )
    {
      v15 = 1;
      NextCurrentUsedInWorkElementIndex = CAIDarkTribe::GetNextCurrentUsedInWorkElementIndex(v13);
      while ( (unsigned int)std::list<int>::size((char *)v13 + 8296) < 0x14
           && NextCurrentUsedInWorkElementIndex != -1
           && v15 )
      {
        v15 = 0;
        BorderElementInWork = (Y16X16 *)CAIDarkTribe::GetBorderElementInWork(v13, NextCurrentUsedInWorkElementIndex);
        Y16X16::UnpackXYFast(BorderElementInWork, &v7, &v8);
        v9 = CAIResourceMap::ResourceDataVW(v7, v8);
        if ( CAIDarkTribe::GetChangeableLandAmount(v13, v9) )
        {
          if ( (unsigned __int8)CAIDarkTribe::GetWorkingPosition(v7, v8, v9, v3) )
          {
            for ( i = 0; ; ++i )
            {
              v1 = std::vector<int>::size(v3);
              if ( i >= v1 )
                break;
              v10 = *(Y16X16 **)std::vector<int>::operator[](i);
              if ( !CAIDarkTribe::IsInLandConversionPositionsList(v13, v10) )
              {
                Y16X16::UnpackXYFast(v10, v4, &v5);
                std::list<int>::push_back(&v10);
                v15 = 1;
                break;
              }
            }
          }
        }
        else
        {
          CAIDarkTribe::RemoveBorderElementInWork(v13, NextCurrentUsedInWorkElementIndex);
        }
        if ( v15 )
          NextCurrentUsedInWorkElementIndex = CAIDarkTribe::GetNextCurrentUsedInWorkElementIndex(v13);
        else
          NextCurrentUsedInWorkElementIndex = -1;
      }
    }
  }
  v16 = -1;
  return std::vector<int>::~vector<int>();
}


// address=[0x1331b10]
// Decompiled from int __thiscall CAIDarkTribe::GetNextCurrentUsedInWorkElementIndex(CAIDarkTribe *this)
int  CAIDarkTribe::GetNextCurrentUsedInWorkElementIndex(void) {
  
  Grid *v2; // [esp+0h] [ebp-38h]
  int v3; // [esp+4h] [ebp-34h]
  int v4; // [esp+8h] [ebp-30h]
  Grid *v5; // [esp+10h] [ebp-28h]
  int v6; // [esp+14h] [ebp-24h]
  int v7; // [esp+18h] [ebp-20h]
  int v8; // [esp+1Ch] [ebp-1Ch]
  int v9; // [esp+20h] [ebp-18h]
  int v10; // [esp+24h] [ebp-14h]
  int v11; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  int BorderElementInWork; // [esp+30h] [ebp-8h]
  int v14; // [esp+30h] [ebp-8h]

  if ( !CAIDarkTribe::GetNrBorderElementsInWork(this) )
    return -1;
  v10 = Y16X16::UnpackXFast(*((_DWORD *)this + 4));
  v11 = Y16X16::UnpackYFast(*((_DWORD *)this + 4));
  v4 = *((_DWORD *)this + 7);
  CAIDarkTribe::IncreaseNextCurrentUsedInWorkElementIndex(this);
  do
  {
    BorderElementInWork = CAIDarkTribe::GetBorderElementInWork(this, *((_DWORD *)this + 7));
    v5 = (Grid *)Y16X16::UnpackXFast(BorderElementInWork);
    v6 = Y16X16::UnpackYFast(BorderElementInWork);
    if ( Grid::Distance(v5, v6, v10, v11) <= *((_DWORD *)this + 8) )
      return *((_DWORD *)this + 7);
    CAIDarkTribe::IncreaseNextCurrentUsedInWorkElementIndex(this);
  }
  while ( *((_DWORD *)this + 7) != v4 || (int)++*((_DWORD *)this + 8) < 100 );
  v7 = -1;
  v8 = 0xFFFF;
  for ( i = 0; i < CAIDarkTribe::GetNrBorderElementsInWork(this); ++i )
  {
    v14 = CAIDarkTribe::GetBorderElementInWork(this, i);
    v2 = (Grid *)Y16X16::UnpackXFast(v14);
    v3 = Y16X16::UnpackYFast(v14);
    v9 = Grid::Distance(v2, v3, v10, v11);
    if ( v9 < v8 )
    {
      v8 = v9;
      v7 = i;
    }
  }
  return v7;
}


// address=[0x1331c90]
// Decompiled from bool __thiscall CAIDarkTribe::GetWorkingPosition(CAIDarkTribe *this, Squares *a2, Squares *a3, int a4, int a5)
bool  CAIDarkTribe::GetWorkingPosition(int,int,class CAIResourceData const &,class std::vector<int,class std::allocator<int> > &) {
  
  int v6; // [esp+0h] [ebp-2Ch] BYREF
  int v7; // [esp+4h] [ebp-28h] BYREF
  CAIDarkTribe *v8; // [esp+8h] [ebp-24h]
  int v9; // [esp+Ch] [ebp-20h]
  int v10; // [esp+10h] [ebp-1Ch]
  int v11; // [esp+14h] [ebp-18h]
  int v12; // [esp+18h] [ebp-14h]
  int v13; // [esp+1Ch] [ebp-10h]
  int v14; // [esp+20h] [ebp-Ch]
  int v15; // [esp+24h] [ebp-8h]

  v8 = this;
  std::vector<int>::clear();
  v9 = Squares::VWToXY(a2);
  v10 = Squares::VWToXY(a3);
  v13 = 0;
  v15 = v10;
  while ( v13 < 16 )
  {
    v12 = 0;
    v14 = v9;
    while ( v12 < 16 )
    {
      if ( !CWorldManager::FlagBits(v14, v15, 4u) && !CWorldManager::FlagBits(v14, v15, 1u) )
      {
        v11 = CAIDarkTribe::CountAdjacentDarkLand(v8, v14, v15);
        if ( v11 > 4 )
        {
          v7 = Y16X16::PackXYFast(v14, v15);
          std::vector<int>::push_back(&v7);
        }
      }
      ++v12;
      ++v14;
    }
    ++v13;
    ++v15;
  }
  v13 = 0;
  v15 = v10;
  while ( v13 < 16 )
  {
    v12 = 0;
    v14 = v9;
    while ( v12 < 16 )
    {
      if ( !CWorldManager::FlagBits(v14, v15, 4u) && !CWorldManager::FlagBits(v14, v15, 1u) )
      {
        v11 = CAIDarkTribe::CountAdjacentDarkLand(v8, v14, v15);
        if ( v11 )
        {
          v6 = Y16X16::PackXYFast(v14, v15);
          std::vector<int>::push_back(&v6);
        }
      }
      ++v12;
      ++v14;
    }
    ++v13;
    ++v15;
  }
  return std::vector<int>::size(a5) != 0;
}


// address=[0x1331e60]
// Decompiled from int __thiscall CAIDarkTribe::GetNextBuildingPosition(CAIDarkTribe *this)
int  CAIDarkTribe::GetNextBuildingPosition(void) {
  
  int NrBuildingGrids; // eax
  int v3; // eax
  int v4; // eax
  int v5; // [esp-8h] [ebp-50h]
  int v6; // [esp-4h] [ebp-4Ch]
  int v7; // [esp-4h] [ebp-4Ch]
  char *BoundingBoxInfo; // [esp+8h] [ebp-40h]
  const struct CAIResourceData *v9; // [esp+Ch] [ebp-3Ch]
  int v10; // [esp+10h] [ebp-38h]
  int v11; // [esp+14h] [ebp-34h]
  int v12; // [esp+18h] [ebp-30h] BYREF
  int v13; // [esp+1Ch] [ebp-2Ch] BYREF
  int v14; // [esp+20h] [ebp-28h]
  int v15; // [esp+24h] [ebp-24h]
  Y16X16 *BuildingGrid; // [esp+28h] [ebp-20h]
  Squares *v17; // [esp+2Ch] [ebp-1Ch] BYREF
  Squares *v18; // [esp+30h] [ebp-18h] BYREF
  int v19; // [esp+34h] [ebp-14h]
  int i; // [esp+38h] [ebp-10h]
  Squares *j; // [esp+3Ch] [ebp-Ch] BYREF
  CAIDarkTribe *v22; // [esp+40h] [ebp-8h]
  Squares *k; // [esp+44h] [ebp-4h] BYREF

  v22 = this;
  if ( !(*(unsigned __int8 (__thiscall **)(CAIDarkTribe *, int))(*(_DWORD *)this + 16))(this, 49) )
    return 0;
  Y16X16::UnpackXYFast(*((Y16X16 **)v22 + 4), &v12, &v13);
  v14 = 0xFFFF;
  v19 = -1;
  for ( i = 0; ; ++i )
  {
    NrBuildingGrids = CAIDarkTribe::GetNrBuildingGrids(v22);
    if ( i >= NrBuildingGrids )
      break;
    BuildingGrid = (Y16X16 *)CAIDarkTribe::GetBuildingGrid(v22, i);
    Y16X16::UnpackXYFast(BuildingGrid, &k, (int *)&j);
    v6 = Squares::VWToXY(j);
    v3 = Squares::VWToXY(k);
    v10 = Y16X16::PackXYFast(v3, v6);
    if ( !CBuildingMgr::IsPositionNearMKHPosition((CBuildingMgr *)g_cBuildingMgr, v10, *((_DWORD *)v22 + 1)) )
    {
      v9 = CAIResourceMap::ResourceDataVW(k, j);
      if ( !CAIDarkTribe::HasChangeableLand(v22, v9) )
      {
        v15 = Grid::Distance(k, j, v12, v13);
        if ( v15 < v14 )
        {
          v14 = v15;
          v19 = i;
        }
      }
    }
  }
  if ( v19 == -1 )
    return 0;
  Y16X16::UnpackXYFast(*((Y16X16 **)v22 + 5), &v12, &v13);
  v11 = CWorldManager::SectorId(*((_DWORD *)v22 + 6));
  if ( v11 <= 0 && BBSupportDbgReport(2, "Ai\\Dark Tribe\\CAI_DarkTribe.cpp", 1540, "iCenterSectorId > 0") == 1 )
    __debugbreak();
  BuildingGrid = (Y16X16 *)CAIDarkTribe::GetBuildingGrid(v22, v19);
  CAIDarkTribe::RemoveBuildingGrid(v22, v19);
  Y16X16::UnpackXYFast(BuildingGrid, &v17, (int *)&v18);
  v17 = (Squares *)Squares::VWToXY(v17);
  v18 = (Squares *)Squares::VWToXY(v18);
  v4 = CAIEcoSpecialBuildingInfos::TheObject(3, 49);
  BoundingBoxInfo = (char *)CAIEcoSpecialBuildingInfos::GetBoundingBoxInfo(v4, v5, v7);
  for ( j = v18; (int)j < (int)((char *)v18 + 16); j = (Squares *)((char *)j + 1) )
  {
    for ( k = v17; (int)k < (int)((char *)v17 + 16); k = (Squares *)((char *)k + 1) )
    {
      if ( CWorldManager::ResourceAmount((int)k, (int)j, 112) || CWorldManager::ResourceAmount((int)k, (int)j, 96) )
      {
        k = (Squares *)((char *)k - *BoundingBoxInfo);
      }
      else if ( CWorldManager::SectorId((int)k, (int)j) == v11
             && (int)CBuildingMgr::CheckForBuild((CBuildingMgr *)g_cBuildingMgr, k, j, *((_DWORD *)v22 + 1), 49, 0) > 0
             && (*(unsigned __int8 (__thiscall **)(void *, _DWORD, Squares *, Squares *))(*(_DWORD *)g_pDarkTribe + 20))(
                  g_pDarkTribe,
                  *((_DWORD *)v22 + 1),
                  k,
                  j)
             && CAIDarkTribe::CheckOtherBuildingPositions(v22, k, j) )
      {
        return Y16X16::PackXYFast((int)k, (int)j);
      }
    }
  }
  return 0;
}


// address=[0x1332170]
// Decompiled from char __thiscall CAIDarkTribe::CheckBuildingGrids(CAIDarkTribe *this)
bool  CAIDarkTribe::CheckBuildingGrids(void) {
  
  int OccupiedElement; // eax
  int v3; // edx
  int *v4; // eax
  int v5; // edx
  int v6; // eax
  int *v7; // eax
  int v8; // edx
  int v9; // eax
  _BYTE v10[8]; // [esp+0h] [ebp-5Ch] BYREF
  _BYTE v11[8]; // [esp+8h] [ebp-54h] BYREF
  _BYTE v12[8]; // [esp+10h] [ebp-4Ch] BYREF
  int v13; // [esp+18h] [ebp-44h] BYREF
  int v14; // [esp+1Ch] [ebp-40h]
  int v15; // [esp+20h] [ebp-3Ch] BYREF
  int v16; // [esp+24h] [ebp-38h]
  Y16X16 *v17; // [esp+28h] [ebp-34h] BYREF
  int v18; // [esp+2Ch] [ebp-30h]
  int v19; // [esp+30h] [ebp-2Ch]
  int v20; // [esp+34h] [ebp-28h]
  int NrOccupiedElements; // [esp+38h] [ebp-24h]
  int v22; // [esp+3Ch] [ebp-20h]
  int v23; // [esp+40h] [ebp-1Ch] BYREF
  int OccupiedElementListIndex; // [esp+44h] [ebp-18h]
  int v25; // [esp+48h] [ebp-14h] BYREF
  int i; // [esp+4Ch] [ebp-10h]
  CAIDarkTribe *v27; // [esp+50h] [ebp-Ch]
  bool v28; // [esp+57h] [ebp-5h]
  bool v29; // [esp+58h] [ebp-4h]
  bool v30; // [esp+59h] [ebp-3h]
  bool v31; // [esp+5Ah] [ebp-2h]
  char v32; // [esp+5Bh] [ebp-1h]

  v27 = this;
  SAIDTOCCUPIEDELEMENT::SAIDTOCCUPIEDELEMENT((SAIDTOCCUPIEDELEMENT *)&v17, 0, 0);
  SAIDTOCCUPIEDELEMENT::SAIDTOCCUPIEDELEMENT((SAIDTOCCUPIEDELEMENT *)&v15, 0, 0);
  SAIDTOCCUPIEDELEMENT::SAIDTOCCUPIEDELEMENT((SAIDTOCCUPIEDELEMENT *)&v13, 0, 0);
  if ( !*((_BYTE *)v27 + 37) )
    return 0;
  *((_BYTE *)v27 + 37) = 0;
  NrOccupiedElements = CAIDarkTribe::GetNrOccupiedElements(v27);
  v32 = 0;
  for ( i = 0; i < NrOccupiedElements; ++i )
  {
    OccupiedElement = CAIDarkTribe::GetOccupiedElement(v27, v12, i);
    v3 = *(_DWORD *)(OccupiedElement + 4);
    v17 = *(Y16X16 **)OccupiedElement;
    v18 = v3;
    Y16X16::UnpackXYFast(v17, &v23, &v25);
    if ( (_WORD)v18 )
    {
      if ( (__int16)v18 == 1 && !CAIDarkTribe::IsInBuildingGridList(v27, v17) )
        CAIVWVector::PushBack((CAIDarkTribe *)((char *)v27 + 8308), v17);
    }
    else if ( !CAIDarkTribe::IsInBorderElementList(v27, v17) )
    {
      v29 = 0;
      if ( v25 > 0 )
      {
        v20 = Y16X16::PackXYFast(v23, v25 - 1);
        OccupiedElementListIndex = CAIDarkTribe::GetOccupiedElementListIndex(v27, v20);
        if ( OccupiedElementListIndex != -1 )
        {
          v4 = (int *)CAIDarkTribe::GetOccupiedElement(v27, v11, OccupiedElementListIndex);
          v5 = *v4;
          v6 = v4[1];
          v15 = v5;
          v16 = v6;
          v31 = (__int16)v6 == 1 || (__int16)v16 == 2;
          v29 = v31;
        }
      }
      v28 = 0;
      if ( v25 < *((_DWORD *)v27 + 3) )
      {
        v19 = Y16X16::PackXYFast(v23, v25 + 1);
        v22 = CAIDarkTribe::GetOccupiedElementListIndex(v27, v19);
        if ( v22 != -1 )
        {
          v7 = (int *)CAIDarkTribe::GetOccupiedElement(v27, v10, v22);
          v8 = *v7;
          v9 = v7[1];
          v13 = v8;
          v14 = v9;
          v30 = (__int16)v9 == 1 || (__int16)v14 == 2;
          v28 = v30;
        }
      }
      if ( v29 )
      {
        LOWORD(v18) = 4;
        CAIDarkTribe::ReplaceOccupiedElement(v27, i, (const struct SAIDTOCCUPIEDELEMENT *)&v17);
        v32 = 1;
      }
      else if ( !v28 )
      {
        LOWORD(v18) = 1;
        CAIDarkTribe::ReplaceOccupiedElement(v27, i, (const struct SAIDTOCCUPIEDELEMENT *)&v17);
        CAIVWVector::PushBack((CAIDarkTribe *)((char *)v27 + 8308), v17);
        v32 = 1;
      }
    }
  }
  return v32;
}


// address=[0x13323c0]
// Decompiled from char __thiscall CAIDarkTribe::CheckOtherBuildingPositions(CAIDarkTribe *this, int a2, int a3)
bool  CAIDarkTribe::CheckOtherBuildingPositions(int,int) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  struct CPtrList *v7; // eax
  CPropertySet *v8; // [esp+8h] [ebp-110h]
  int v9; // [esp+10h] [ebp-108h]
  _BYTE v10[4]; // [esp+14h] [ebp-104h] BYREF
  int v11; // [esp+18h] [ebp-100h]
  int v12; // [esp+1Ch] [ebp-FCh]
  int v13; // [esp+20h] [ebp-F8h]
  int v14; // [esp+24h] [ebp-F4h]
  _DWORD *v15; // [esp+28h] [ebp-F0h]
  int j; // [esp+2Ch] [ebp-ECh]
  int i; // [esp+30h] [ebp-E8h]
  _BYTE v18[224]; // [esp+34h] [ebp-E4h] BYREF

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "Ai\\Dark Tribe\\CAI_DarkTribe.cpp", 1698, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  CTmpEntitiesRef::CTmpEntitiesRef((CTmpEntitiesRef *)v10);
  CVWList::CVWList((CVWList *)v18, a2, a3, 22);
  for ( i = 0; ; ++i )
  {
    v3 = CVWList::Size((CVWList *)v18);
    if ( i >= v3 )
      break;
    v11 = *(_DWORD *)CVWList::operator[](i);
    v12 = *(_DWORD *)(CVWList::operator[](i) + 4);
    for ( j = CWarMap::FirstEntityIdVW(2, v11, v12); j; j = CWarMapNode::Next(v7) )
    {
      v8 = (CPropertySet *)CTmpEntitiesRef::operator[](j);
      v15 = (_DWORD *)CBuildingMgr::operator[](j);
      v4 = CBuilding::EnsignPackedXY(v15);
      v13 = Y16X16::UnpackXFast(v4);
      v5 = CBuilding::EnsignPackedXY(v15);
      v14 = Y16X16::UnpackYFast(v5);
      v9 = CWorldManager::Index(v13, v14);
      ITiling::SectorId(v9);
      if ( (int)Grid::DistanceInline((Grid *)(v13 - a2), v14 - a3) <= 22 )
        return 0;
      v7 = IEntity::WarMapNode(v8);
    }
  }
  return 1;
}


// address=[0x13325c0]
// Decompiled from char __thiscall CAIDarkTribe::IsPureDarkLandAround(CAIDarkTribe *this, int a2, int a3)
bool  CAIDarkTribe::IsPureDarkLandAround(int,int) {
  
  CAIResourceData *v4; // [esp+0h] [ebp-14h]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < 6; ++i )
  {
    v6 = g_sNeighborPoints[2 * i] + a2;
    v7 = dword_37D8C0C[2 * i] + a3;
    if ( v7 >= 0 && v7 <= *((_DWORD *)this + 3) && v6 >= 0 && v6 <= *((_DWORD *)this + 2) )
    {
      v4 = CAIResourceMap::ResourceDataVW(v6, v7);
      if ( !CAIDarkTribe::HasChangeableLand(this, v4) )
      {
        if ( CAIResourceData::GroundInfo1(v4, 0) )
          return 1;
      }
    }
  }
  return 0;
}


// address=[0x1332670]
// Decompiled from bool __thiscall CAIDarkTribe::HasChangeableLand(CAIDarkTribe *this, const struct CAIResourceData *a2)
bool  CAIDarkTribe::HasChangeableLand(class CAIResourceData const &) {
  
  if ( (CAIResourceData::Flags1(a2) & 1) == 0 )
    return 0;
  return CAIResourceData::GroundInfo1(a2, 1)
      || CAIResourceData::GroundInfo1(a2, 2)
      || CAIResourceData::GroundInfo1(a2, 3);
}


// address=[0x13326d0]
// Decompiled from int __thiscall CAIDarkTribe::GetChangeableLandAmount(CAIDarkTribe *this, const struct CAIResourceData *a2)
int  CAIDarkTribe::GetChangeableLandAmount(class CAIResourceData const &) {
  
  int v2; // esi
  int v3; // esi

  v2 = CAIResourceData::GroundInfo1(a2, 1);
  v3 = CAIResourceData::GroundInfo1(a2, 2) + v2;
  return v3 + CAIResourceData::GroundInfo1(a2, 3);
}


// address=[0x1332710]
// Decompiled from int __thiscall CAIDarkTribe::CountAdjacentDarkLand(CAIDarkTribe *this, int a2, int a3)
int  CAIDarkTribe::CountAdjacentDarkLand(int,int) {
  
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v6 = 0;
  for ( i = 0; i < 6; ++i )
  {
    v4 = g_sNeighborPoints[2 * i] + a2;
    v5 = dword_37D8C0C[2 * i] + a3;
    if ( (unsigned __int8)CWorldManager::InWorld(v4, v5) )
    {
      if ( CWorldManager::FlagBits(v4, v5, 4u) )
        ++v6;
    }
  }
  return v6;
}


// address=[0x13327a0]
// Decompiled from char __thiscall CAIDarkTribe::IsAdjacent(CAIDarkTribe *this, int a2, int a3, int a4, int a5)
bool  CAIDarkTribe::IsAdjacent(int,int,int,int) {
  
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 6; ++i )
  {
    if ( g_sNeighborPoints[2 * i] + a2 == a4 && dword_37D8C0C[2 * i] + a3 == a5 )
      return 1;
  }
  return 0;
}


// address=[0x1332800]
// Decompiled from void __thiscall CAIDarkTribe::CheckManakopterHallExists(CAIDarkTribe *this)
void  CAIDarkTribe::CheckManakopterHallExists(void) {
  
  signed int TimeSinceHallDestruction; // esi
  unsigned int ValidManakopterHallPosition; // [esp+8h] [ebp-38h]
  _BYTE v4[32]; // [esp+10h] [ebp-30h] BYREF
  int v5; // [esp+3Ch] [ebp-4h]

  if ( CBuildingMgr::PlayerUsesManakopterHalls((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 1))
    && !CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, *((_DWORD *)this + 1), 80) )
  {
    TimeSinceHallDestruction = CBuildingMgr::GetTimeSinceHallDestruction(
                                 (CBuildingMgr *)g_cBuildingMgr,
                                 *((_DWORD *)this + 1));
    if ( TimeSinceHallDestruction > CAIPlayersScriptVars::GetValue(g_cAIPlayersScriptVars, *((_DWORD *)this + 1), 19) )
    {
      ValidManakopterHallPosition = CBuildingMgr::GetValidManakopterHallPosition(
                                      (CBuildingMgr *)g_cBuildingMgr,
                                      *((_DWORD *)this + 1));
      if ( ValidManakopterHallPosition )
      {
        CEvn_Logic::CEvn_Logic(
          (CEvn_Logic *)v4,
          0x13A1u,
          0x50u,
          ValidManakopterHallPosition,
          *((_BYTE *)this + 4),
          0,
          0);
        v5 = 0;
        INetworkEngine::SendNetMessage((INetworkEngine *)g_pNetworkEngine, (struct CEvn_Logic *)v4);
        v5 = -1;
        CEvn_Logic::~CEvn_Logic(v4);
      }
    }
  }
}


// address=[0x1335fa0]
// Decompiled from int __thiscall CAIDarkTribe::GetBorderElement(CAIDarkTribe *this, int a2)
int  CAIDarkTribe::GetBorderElement(int)const {
  
  if ( a2 >= 0 && a2 < CAIDarkTribe::GetNrBorderElements(this) )
    return *(_DWORD *)std::vector<int>::operator[](a2);
  else
    return 0;
}


// address=[0x1335ff0]
// Decompiled from int __thiscall CAIDarkTribe::GetBorderElementInWork(CAIDarkTribe *this, int a2)
int  CAIDarkTribe::GetBorderElementInWork(int)const {
  
  if ( a2 >= 0 && a2 < CAIDarkTribe::GetNrBorderElementsInWork(this) )
    return *(_DWORD *)std::vector<int>::operator[](a2);
  else
    return 0;
}


// address=[0x1336040]
// Decompiled from int __thiscall CAIDarkTribe::GetBuildingGrid(CAIDarkTribe *this, int a2)
int  CAIDarkTribe::GetBuildingGrid(int)const {
  
  return CAIVWVector::At((CAIDarkTribe *)((char *)this + 8308), a2);
}


// address=[0x1336070]
// Decompiled from int __thiscall CAIDarkTribe::GetBuildingGridIndex(CAIDarkTribe *this, int a2)
int  CAIDarkTribe::GetBuildingGridIndex(int)const {
  
  return CAIVWVector::Index((CAIDarkTribe *)((char *)this + 8308), a2);
}


// address=[0x13360a0]
// Decompiled from int __thiscall CAIDarkTribe::GetNrBorderElements(CAIDarkTribe *this)
int  CAIDarkTribe::GetNrBorderElements(void)const {
  
  return std::vector<int>::size((char *)this + 8248);
}


// address=[0x13360c0]
// Decompiled from int __thiscall CAIDarkTribe::GetNrBorderElementsInWork(CAIDarkTribe *this)
int  CAIDarkTribe::GetNrBorderElementsInWork(void)const {
  
  return std::vector<int>::size((char *)this + 8280);
}


// address=[0x13360e0]
// Decompiled from int __thiscall CAIDarkTribe::GetNrBuildingGrids(CAIDarkTribe *this)
int  CAIDarkTribe::GetNrBuildingGrids(void)const {
  
  return CAIVWVector::Size((CAIDarkTribe *)((char *)this + 8308));
}


// address=[0x1336100]
// Decompiled from int __thiscall CAIDarkTribe::GetNrLandConversionPositions(CAIDarkTribe *this)
int  CAIDarkTribe::GetNrLandConversionPositions(void)const {
  
  return std::list<int>::size((char *)this + 8296);
}


// address=[0x1336120]
// Decompiled from int __thiscall CAIDarkTribe::GetNrOccupiedElements(CAIDarkTribe *this)
int  CAIDarkTribe::GetNrOccupiedElements(void)const {
  
  return std::vector<SAIDTOCCUPIEDELEMENT>::size((char *)this + 8232);
}


// address=[0x1336140]
// Decompiled from SAIDTOCCUPIEDELEMENT *__thiscall CAIDarkTribe::GetOccupiedElement(CAIDarkTribe *this, SAIDTOCCUPIEDELEMENT *a2, int a3)
struct SAIDTOCCUPIEDELEMENT  CAIDarkTribe::GetOccupiedElement(int)const {
  
  _DWORD *v4; // eax
  int v5; // edx

  if ( a3 >= 0 && a3 < CAIDarkTribe::GetNrOccupiedElements(this) )
  {
    v4 = (_DWORD *)std::vector<SAIDTOCCUPIEDELEMENT>::operator[](a3);
    v5 = v4[1];
    *(_DWORD *)a2 = *v4;
    *((_DWORD *)a2 + 1) = v5;
    return a2;
  }
  else
  {
    SAIDTOCCUPIEDELEMENT::SAIDTOCCUPIEDELEMENT(a2, 0, 0);
    return a2;
  }
}


// address=[0x13361f0]
// Decompiled from int __thiscall CAIDarkTribe::IncreaseNextCurrentUsedInWorkElementIndex(CAIDarkTribe *this)
void  CAIDarkTribe::IncreaseNextCurrentUsedInWorkElementIndex(void) {
  
  int result; // eax

  ++*((_DWORD *)this + 7);
  result = CAIDarkTribe::GetNrBorderElementsInWork(this);
  if ( *((_DWORD *)this + 7) >= result )
    *((_DWORD *)this + 7) = 0;
  return result;
}


// address=[0x13362e0]
// Decompiled from bool __thiscall CAIDarkTribe::IsInBorderElementInWorkList(CAIDarkTribe *this, int a2)
bool  CAIDarkTribe::IsInBorderElementInWorkList(int)const {
  
  return CAIDarkTribe::GetBorderElementInWorkListIndex(this, a2) != -1;
}


// address=[0x1336320]
// Decompiled from bool __thiscall CAIDarkTribe::IsInBorderElementList(CAIDarkTribe *this, int a2)
bool  CAIDarkTribe::IsInBorderElementList(int)const {
  
  return CAIDarkTribe::GetBorderElementListIndex(this, a2) != -1;
}


// address=[0x1336360]
// Decompiled from bool __thiscall CAIDarkTribe::IsInBuildingGridList(CAIDarkTribe *this, int a2)
bool  CAIDarkTribe::IsInBuildingGridList(int)const {
  
  return CAIDarkTribe::GetBuildingGridIndex(this, a2) != -1;
}


// address=[0x13363a0]
// Decompiled from bool __thiscall CAIDarkTribe::IsInLandConversionPositionsList(CAIDarkTribe *this, int a2)
bool  CAIDarkTribe::IsInLandConversionPositionsList(int)const {
  
  return CAIDarkTribe::GetLandConversionPositionIndex(this, a2) != -1;
}


// address=[0x1336750]
// Decompiled from void __thiscall CAIDarkTribe::RemoveBuildingGrid(CAIDarkTribe *this, int a2)
void  CAIDarkTribe::RemoveBuildingGrid(int) {
  
  CAIVWVector::Remove((CAIDarkTribe *)((char *)this + 8308), a2);
}


// address=[0x1336780]
// Decompiled from int __thiscall CAIDarkTribe::RemoveLandConversionPosition(CAIDarkTribe *this, int a2)
void  CAIDarkTribe::RemoveLandConversionPosition(int) {
  
  int result; // eax

  result = CAIDarkTribe::GetNrLandConversionPositions(this);
  if ( result )
    return std::list<int>::remove(&a2);
  return result;
}


