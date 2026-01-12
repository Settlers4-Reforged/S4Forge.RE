#include "CDarkTribe.h"

// Definitions for class CDarkTribe

// address=[0x141bad0]
// Decompiled from int __thiscall CDarkTribe::OrderMushroomFarmer(void *this, int a2)

int  CDarkTribe::OrderMushroomFarmer(int) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  _BYTE v6[24]; // [esp+4h] [ebp-4Ch] BYREF
  int v7; // [esp+1Ch] [ebp-34h]
  int v8; // [esp+20h] [ebp-30h]
  _DWORD v9[2]; // [esp+24h] [ebp-2Ch] BYREF
  int v10; // [esp+2Ch] [ebp-24h] BYREF
  int v11; // [esp+30h] [ebp-20h]
  int v12; // [esp+34h] [ebp-1Ch]
  int v13; // [esp+38h] [ebp-18h]
  int v14; // [esp+3Ch] [ebp-14h]
  unsigned __int8 *BuildingPtr; // [esp+40h] [ebp-10h]
  int v16; // [esp+4Ch] [ebp-4h]

  v9[1] = this;
  BuildingPtr = (unsigned __int8 *)CBuildingMgr::GetBuildingPtr(a2);
  if ( BuildingPtr && IEntity::Type((unsigned __int16 *)BuildingPtr) == 49 )
  {
    if ( !IEntity::FlagBits(BuildingPtr, 0x2000000)
      && BBSupportDbgReport(2, (int)"Logic\\DarkTribe.cpp", 284, (int)"pBuilding->FlagBits(ENTITY_FLAG_READY) != 0") == 1 )
    {
      __debugbreak();
    }
    v3 = IEntity::OwnerId(BuildingPtr);
    if ( (unsigned __int8)CDarkTribe::GetDarkTempleIfReady(v3, &v10, v9) )
    {
      v4 = CBuilding::EnsignWorldIdx(BuildingPtr);
      v12 = CWorldManager::SectorId(v4);
      v5 = CBuilding::EnsignWorldIdx(v10);
      v11 = CWorldManager::SectorId(v5);
      if ( v12 <= 0 && BBSupportDbgReport(2, (int)"Logic\\DarkTribe.cpp", 297, (int)"iMushroomFarmSectorId > 0") == 1 )
        __debugbreak();
      if ( v11 <= 0 && BBSupportDbgReport(2, (int)"Logic\\DarkTribe.cpp", 298, (int)"iDarkTempleSectorId > 0") == 1 )
        __debugbreak();
      if ( v12 == v11 )
      {
        v13 = CDarkTempleRole::ProduceMushroomFarmer(v10);
        if ( v13 > 0 )
        {
          v14 = CSettlerMgr::operator[](v13);
          CSettler::AttachToBuilding(a2);
          v8 = CEntityEvent::CEntityEvent(1, 0, a2, 0, 0);
          v7 = v8;
          v16 = 0;
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v14 + 80))(v14, v8);
          v16 = -1;
          CEntityEvent::~CEntityEvent(v6);
          return v13;
        }
        else
        {
          return 0;
        }
      }
      else
      {
        return 0;
      }
    }
    else
    {
      return -1;
    }
  }
  else
  {
    if ( BBSupportDbgReportF(
           1,
           "Logic\\DarkTribe.cpp",
           279,
           "CDarkTribe::OrderMushroomFarmer(): Invalid building id %i",
           a2) == 1 )
      __debugbreak();
    return -1;
  }
}


// address=[0x141bcc0]
// Decompiled from int __thiscall CDarkTribe::OrderSettlerToDarkTemple(CDarkTribe *this, int a2, bool a3)

int  CDarkTribe::OrderSettlerToDarkTemple(int,bool) {
  
  _BYTE v4[24]; // [esp+4h] [ebp-40h] BYREF
  CEntityEvent *v5; // [esp+1Ch] [ebp-28h]
  CEntityEvent *v6; // [esp+20h] [ebp-24h]
  int v7; // [esp+24h] [ebp-20h]
  int v8; // [esp+28h] [ebp-1Ch]
  unsigned __int16 *v9; // [esp+2Ch] [ebp-18h]
  CDarkTribe *v10; // [esp+30h] [ebp-14h]
  unsigned __int8 *SettlerPtr; // [esp+34h] [ebp-10h]
  int v12; // [esp+40h] [ebp-4h]

  v10 = this;
  SettlerPtr = CSettlerMgr::GetSettlerPtr(a2);
  if ( !SettlerPtr )
    return -1;
  if ( IEntity::Race(SettlerPtr) != 3
    && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 339, "pSettler->Race() == RACE_DARK") == 1 )
  {
    __debugbreak();
  }
  v7 = IEntity::OwnerId(SettlerPtr);
  v9 = (unsigned __int16 *)(*(int (__thiscall **)(CDarkTribe *, int))(*(_DWORD *)v10 + 24))(v10, v7);
  if ( v9 )
  {
    v8 = IEntity::EntityId(v9);
    CSettler::AttachToBuilding((CSettler *)SettlerPtr, v8);
    v6 = CEntityEvent::CEntityEvent((CEntityEvent *)v4, 2u, 0, v8, a3, 0);
    v5 = v6;
    v12 = 0;
    (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)SettlerPtr + 80))(SettlerPtr, v6);
    v12 = -1;
    CEntityEvent::~CEntityEvent(v4);
    return 1;
  }
  else
  {
    CSettler::TakeWaitList(SettlerPtr);
    return 0;
  }
}


// address=[0x141bde0]
// Decompiled from void __thiscall CDarkTribe::AssociateServantWithMushroomFarm(CDarkTribe *this, int a2)

void  CDarkTribe::AssociateServantWithMushroomFarm(int) {
  
  int MushroomFarmForServant; // [esp+0h] [ebp-Ch]
  unsigned __int8 *SettlerPtr; // [esp+4h] [ebp-8h]

  SettlerPtr = CSettlerMgr::GetSettlerPtr(a2);
  if ( SettlerPtr
    && !IEntity::FlagBits(SettlerPtr, (EntityFlag)&unk_4000000)
    && IEntity::Type((unsigned __int16 *)SettlerPtr) == 55 )
  {
    MushroomFarmForServant = CDarkTribe::FindMushroomFarmForServant(this, a2);
    if ( MushroomFarmForServant <= 0 )
      (*(void (__thiscall **)(CDarkTribe *, int, _DWORD))(*(_DWORD *)this + 4))(this, a2, 0);
    else
      CDarkTribe::OrderServantToMushroomFarm(this, a2, MushroomFarmForServant);
  }
  else
  {
    CMapObjectMgr::DbgPrintEntity(g_pMapObjectMgr, a2, 0, 0);
    if ( BBSupportDbgReportF(
           1,
           "Logic\\DarkTribe.cpp",
           379,
           "CDarkTribe::AssociateServantWithMushroomFarm: Invalid settler id %i",
           a2) == 1 )
      __debugbreak();
  }
}


// address=[0x141bea0]
// Decompiled from unsigned __int8 *__thiscall CDarkTribe::GetDarkTempleIfReady(CDarkTribe *this, int a2)

class CBuilding *  CDarkTribe::GetDarkTempleIfReady(int) {
  
  int DarkTempleId; // [esp+0h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+Ch] [ebp-4h]

  DarkTempleId = CDarkTribe::GetDarkTempleId(this, a2);
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, DarkTempleId);
  if ( !BuildingPtr )
    return 0;
  if ( IEntity::FlagBits(BuildingPtr, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    return BuildingPtr;
  else
    return 0;
}


// address=[0x141cb10]
// Decompiled from unsigned int __thiscall CDarkTribe::ChangePositionOrSurroundingToDarkLand(CDarkTribe *this, int a2, int a3, bool a4)

void  CDarkTribe::ChangePositionOrSurroundingToDarkLand(int,int,bool) {
  
  unsigned int result; // eax
  int v5; // eax
  int v7; // [esp+8h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2 - 3, a3 - 3)
    && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 403, "g_cWorld.InWorld( _iX - 3, _iY - 3 )") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorld(a2 + 3, a3 + 3)
    && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 404, "g_cWorld.InWorld( _iX + 3, _iY + 3 )") == 1 )
  {
    __debugbreak();
  }
  if ( a4 )
    v7 = 7;
  else
    v7 = 1;
  result = v7;
  for ( i = 0; i < v7; ++i )
  {
    if ( i > 0 && i != 6 )
    {
      result = CStateGame::Rand(g_pGame);
      if ( result < 0x4000 )
        continue;
    }
    v8 = a2 + CSpiralOffsets::DeltaX(i);
    v9 = a3 + CSpiralOffsets::DeltaY(i);
    result = CWorldManager::FlagBits(v8, v9, 4u);
    if ( !result )
    {
      v5 = CWorldManager::Ground(v8, v9);
      result = CLandscapeProperties::IsBlockedLand((CLandscapeProperties *)&g_cLandscapeProperties, v5);
      if ( !(_BYTE)result )
      {
        result = CWorldManager::Ground(v8, v9) & 0xF0;
        if ( result != 32 )
        {
          CDarkTribe::ChangeElementToDarkOrGreen(this, v8, v9, 1, 0);
          CDarkTribe::SetHolesDarkOrGreen(this, v8, v9, 1, 0);
        }
      }
    }
  }
  return result;
}


// address=[0x141cca0]
// Decompiled from void __thiscall CDarkTribe::ChangePositionToGreenLand(CDarkTribe *this, int a2, int a3, int a4)

void  CDarkTribe::ChangePositionToGreenLand(int,int,int) {
  
  CDarkTribe::ChangeElementToDarkOrGreen(this, a2, a3, 0, a4);
  CDarkTribe::SetHolesDarkOrGreen(this, a2, a3, 0, a4);
}


// address=[0x141cce0]
// Decompiled from char __thiscall CDarkTribe::IsMushroomFarmPositionValid(CDarkTribe *this, int a2, int a3, int a4)

bool  CDarkTribe::IsMushroomFarmPositionValid(int,int,int) {
  
  int v5; // [esp+8h] [ebp-38h]
  int v6; // [esp+Ch] [ebp-34h]
  int v7; // [esp+14h] [ebp-2Ch]
  int v8; // [esp+18h] [ebp-28h]
  int PlayerId; // [esp+1Ch] [ebp-24h]
  int v10; // [esp+20h] [ebp-20h]
  int v11; // [esp+28h] [ebp-18h]
  int v12; // [esp+2Ch] [ebp-14h]
  unsigned __int8 *v13; // [esp+30h] [ebp-10h]
  unsigned __int8 *BuildingPtr; // [esp+34h] [ebp-Ch]
  int j; // [esp+38h] [ebp-8h]
  int k; // [esp+38h] [ebp-8h]
  int i; // [esp+3Ch] [ebp-4h]

  if ( !CWorldManager::InInnerWorld16(a3, a4) )
    return 0;
  PlayerId = CPlayerManager::LastPlayerId();
  for ( i = 1; i <= PlayerId; ++i )
  {
    if ( CPlayerManager::Race(i) == 3 )
    {
      if ( i == a2 )
        v12 = 40;
      else
        v12 = 60;
      for ( j = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, i, 50); j; j = v11 )
      {
        BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, j);
        if ( BuildingPtr )
        {
          if ( IEntity::FlagBits(BuildingPtr, (EntityFlag)&loc_3000000) )
          {
            v7 = IEntity::X(BuildingPtr);
            v8 = IEntity::Y(BuildingPtr);
            if ( Grid::Distance((Grid *)(a3 - v7), a4 - v8) < v12 )
              return 0;
          }
        }
        if ( BuildingPtr )
          v11 = IAnimatedEntity::Next(BuildingPtr);
        else
          v11 = 0;
      }
      for ( k = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, i, 51); k; k = v10 )
      {
        v13 = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, k);
        if ( v13 )
        {
          if ( IEntity::FlagBits(v13, (EntityFlag)&loc_3000000) )
          {
            v5 = IEntity::X(v13);
            v6 = IEntity::Y(v13);
            if ( Grid::Distance((Grid *)(a3 - v5), a4 - v6) < v12 )
              return 0;
          }
        }
        if ( v13 )
          v10 = IAnimatedEntity::Next(v13);
        else
          v10 = 0;
      }
    }
  }
  return 1;
}


// address=[0x141cec0]
// Decompiled from bool __thiscall CDarkTribe::IsObjectSurrounded(CDarkTribe *this, int a2, bool a3)

bool  CDarkTribe::IsObjectSurrounded(int,bool) {
  
  int v4; // [esp+1Ch] [ebp-40h]
  unsigned int v5; // [esp+20h] [ebp-3Ch]
  unsigned int v6; // [esp+28h] [ebp-34h]
  int v7; // [esp+2Ch] [ebp-30h]
  int v8; // [esp+30h] [ebp-2Ch]
  int v9; // [esp+34h] [ebp-28h]
  int v10; // [esp+38h] [ebp-24h]
  int v11; // [esp+3Ch] [ebp-20h]
  int j; // [esp+40h] [ebp-1Ch]
  int v13; // [esp+44h] [ebp-18h]
  Grid *v14; // [esp+48h] [ebp-14h]
  int i; // [esp+4Ch] [ebp-10h]
  char IsBlockedLand; // [esp+53h] [ebp-9h]
  bool v17; // [esp+54h] [ebp-8h]
  bool IsWater; // [esp+55h] [ebp-7h]
  bool v19; // [esp+57h] [ebp-5h]
  bool v20; // [esp+5Bh] [ebp-1h]

  v19 = 0;
  if ( a3 )
    v5 = 64;
  else
    v5 = 72;
  if ( a3 )
    v4 = 4;
  else
    v4 = 0;
  v10 = a2;
  if ( !CWorldManager::FlagBits(a2, v5) )
    return v19;
  v7 = -1;
  v8 = 0;
  v20 = CWorldManager::FlagBits(a2, 0x40u) == 0;
  for ( i = 0; i < 6; ++i )
  {
    v9 = a2 + CWorldManager::NeighborRelIndex(i);
    if ( (unsigned __int8)CWorldManager::IsBlockedLand(v9) )
    {
      ++v8;
      IsWater = CWorldManager::IsWater(v9);
      v17 = CWorldManager::FlagBits(v9, 8u) == 8;
      if ( !IsWater && (!v20 || v17) )
        v7 = i;
    }
  }
  if ( v8 >= 6 || v7 < 0 )
    return v19;
  v13 = 1;
  v14 = (Grid *)Grid::TurnRight((Grid *)v7);
  CWorldManager::X(a2);
  CWorldManager::Y(a2);
  for ( j = 0; j < 0x4000; ++j )
  {
    v11 = a2 + CWorldManager::NeighborRelIndex(v14);
    v6 = CWorldManager::Flags(v11);
    IsBlockedLand = CWorldManager::IsBlockedLand(v11);
    if ( v20 )
      CWorldManager::FlagBits(v11, 8u);
    if ( IsBlockedLand )
    {
      if ( (v5 & v6) == 0 )
        break;
      ++v13;
      v14 = (Grid *)Grid::TurnRight(v14);
    }
    else
    {
      if ( (v6 & 4) != v4 || (v5 & v6) == 0 )
        break;
      --v13;
      v14 = (Grid *)Grid::TurnLeft(v14);
      a2 = v11;
      if ( v11 == v10 )
      {
        v19 = v13 < 0;
        break;
      }
    }
  }
  if ( j > 0x4000 && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 903, "16384 >= iCounter") == 1 )
    __debugbreak();
  return v19;
}


// address=[0x141d760]
// Decompiled from CDarkTribe *__thiscall CDarkTribe::CDarkTribe(CDarkTribe *this)

 CDarkTribe::CDarkTribe(void) {
  
  IDarkTribe::IDarkTribe(this);
  *(_DWORD *)this = &CDarkTribe::_vftable_;
  return this;
}


// address=[0x141bf00]
// Decompiled from int __thiscall CDarkTribe::GetDarkTempleId(CDarkTribe *this, int a2)

int  CDarkTribe::GetDarkTempleId(int) {
  
  int FirstBuildingId; // [esp+4h] [ebp-4h]

  FirstBuildingId = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, a2, 50);
  if ( !FirstBuildingId )
    return CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, a2, 51);
  return FirstBuildingId;
}


// address=[0x141bf40]
// Decompiled from char __thiscall CDarkTribe::GetDarkTempleIfReady(CDarkTribe *this, int a2, struct CBuilding **a3, void ***a4)

bool  CDarkTribe::GetDarkTempleIfReady(int,class CBuilding * &,class CDarkTempleRole * &) {
  
  int DarkTempleId; // [esp+0h] [ebp-10h]
  void **v6; // [esp+8h] [ebp-8h]
  unsigned __int8 *BuildingPtr; // [esp+Ch] [ebp-4h]

  DarkTempleId = CDarkTribe::GetDarkTempleId(this, a2);
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, DarkTempleId);
  if ( BuildingPtr && IEntity::FlagBits(BuildingPtr, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
  {
    v6 = (void **)CBuilding::Role(BuildingPtr);
    if ( !j____RTDynamicCast(v6, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CDarkTempleRole__RTTI_Type_Descriptor_, 0)
      && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 149, "dynamic_cast<CDarkTempleRole*>(pBuildingRole) != 0") == 1 )
    {
      __debugbreak();
    }
    *a3 = (struct CBuilding *)BuildingPtr;
    *a4 = v6;
    return 1;
  }
  else
  {
    *a3 = 0;
    *a4 = 0;
    return 0;
  }
}


// address=[0x141c000]
// Decompiled from int __thiscall CDarkTribe::FindMushroomFarmForServant(CDarkTribe *this, int a2)

int  CDarkTribe::FindMushroomFarmForServant(int) {
  
  void **v2; // eax
  CMFCVisualManagerOffice2003 *v4; // [esp+4h] [ebp-44h]
  int v5; // [esp+Ch] [ebp-3Ch]
  int v6; // [esp+10h] [ebp-38h]
  int v7; // [esp+14h] [ebp-34h]
  int v8; // [esp+18h] [ebp-30h]
  int v9; // [esp+1Ch] [ebp-2Ch]
  int v10; // [esp+20h] [ebp-28h]
  int v11; // [esp+24h] [ebp-24h]
  int v12; // [esp+28h] [ebp-20h]
  int v13; // [esp+2Ch] [ebp-1Ch]
  int v14; // [esp+30h] [ebp-18h]
  int v15; // [esp+34h] [ebp-14h]
  int v16; // [esp+38h] [ebp-10h]
  int i; // [esp+3Ch] [ebp-Ch]
  unsigned __int16 *v18; // [esp+40h] [ebp-8h]
  unsigned __int8 *v19; // [esp+44h] [ebp-4h]

  v6 = 0;
  if ( a2 <= 0 && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 174, "_iServantId > 0") == 1 )
    __debugbreak();
  v18 = (unsigned __int16 *)CSettlerMgr::operator[](a2);
  if ( IEntity::Type(v18) != 55
    && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 178, "rSettler.Type() == SETTLER_SLAVED_SETTLER") == 1 )
  {
    __debugbreak();
  }
  v5 = IEntity::OwnerId((unsigned __int8 *)v18);
  v10 = IEntity::X(v18);
  v12 = IEntity::Y(v18);
  v14 = CWorldManager::SectorId(v10, v12);
  if ( v14 <= 0 && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 187, "iServantSectorId > 0") == 1 )
    __debugbreak();
  v9 = 5;
  v7 = 0x4000;
  for ( i = CBuildingMgr::GetFirstBuildingId((CBuildingMgr *)g_cBuildingMgr, v5, 49); i; i = IAnimatedEntity::Next(v19) )
  {
    v19 = CBuildingMgr::Building((CBuildingMgr *)g_cBuildingMgr, i);
    if ( IEntity::Type((unsigned __int16 *)v19) != 49
      && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 198, "rMushroomFarm.Type() == BUILDING_MUSHROOMFARM") == 1 )
    {
      __debugbreak();
    }
    if ( IEntity::FlagBits(v19, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
    {
      v11 = CBuilding::EnsignX(v19);
      v13 = CBuilding::EnsignY(v19);
      if ( CWorldManager::SectorId(v11, v13) == v14 )
      {
        v2 = (void **)CBuilding::Role(v19);
        if ( !j____RTDynamicCast(
                v2,
                0,
                &IBuildingRole__RTTI_Type_Descriptor_,
                &CDarkMushroomFarmRole__RTTI_Type_Descriptor_,
                0)
          && BBSupportDbgReport(
               2,
               "Logic\\DarkTribe.cpp",
               209,
               "dynamic_cast<CDarkMushroomFarmRole*>(&rMushroomFarm.Role()) != 0") == 1 )
        {
          __debugbreak();
        }
        v4 = (CMFCVisualManagerOffice2003 *)CBuilding::Role(v19);
        v15 = CDarkMushroomFarmRole::NumberOfAssociatedServants(v4);
        v8 = Grid::Distance((Grid *)(v11 - v10), v13 - v12);
        if ( v15 < 5 )
        {
          v16 = v15 - v9;
          if ( v15 - v9 < -1 || v16 <= 1 && v8 + 50 * v16 < v7 )
          {
            v6 = i;
            v9 = v15;
            v7 = v8;
          }
        }
      }
    }
  }
  return v6;
}


// address=[0x141c250]
// Decompiled from int __thiscall CDarkTribe::OrderServantToMushroomFarm(CDarkTribe *this, int a2, int a3)

void  CDarkTribe::OrderServantToMushroomFarm(int,int) {
  
  unsigned __int16 *v3; // eax
  unsigned __int16 *v4; // eax
  void **v5; // eax
  _BYTE v7[24]; // [esp+4h] [ebp-3Ch] BYREF
  CDarkTribe *v8; // [esp+1Ch] [ebp-24h]
  CEntityEvent *v9; // [esp+20h] [ebp-20h]
  CEntityEvent *v10; // [esp+24h] [ebp-1Ch]
  CDarkMushroomFarmRole *v11; // [esp+28h] [ebp-18h]
  unsigned __int8 *SettlerPtr; // [esp+2Ch] [ebp-14h]
  unsigned __int8 *BuildingPtr; // [esp+30h] [ebp-10h]
  int v14; // [esp+3Ch] [ebp-4h]

  v8 = this;
  if ( a2 <= 0 && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 250, "_iServantId > 0") == 1 )
    __debugbreak();
  if ( a3 <= 0 && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 251, "_iMushroomFarmId > 0") == 1 )
    __debugbreak();
  if ( !CSettlerMgr::GetSettlerPtr(a2)
    && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 252, "g_cSettlerMgr.GetSettlerPtr(_iServantId) != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a3)
    && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 253, "g_cBuildingMgr.GetBuildingPtr(_iMushroomFarmId) != 0") == 1 )
  {
    __debugbreak();
  }
  v3 = (unsigned __int16 *)CMapObjectMgr::Entity(a2);
  if ( IEntity::Type(v3) != 55
    && BBSupportDbgReport(
         2,
         "Logic\\DarkTribe.cpp",
         254,
         "g_pMapObjectMgr->Entity(_iServantId).Type() == SETTLER_SLAVED_SETTLER") == 1 )
  {
    __debugbreak();
  }
  v4 = (unsigned __int16 *)CMapObjectMgr::Entity(a3);
  if ( IEntity::Type(v4) != 49
    && BBSupportDbgReport(
         2,
         "Logic\\DarkTribe.cpp",
         255,
         "g_pMapObjectMgr->Entity(_iMushroomFarmId).Type() == BUILDING_MUSHROOMFARM") == 1 )
  {
    __debugbreak();
  }
  SettlerPtr = CSettlerMgr::GetSettlerPtr(a2);
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a3);
  v5 = (void **)CBuilding::Role(BuildingPtr);
  if ( !j____RTDynamicCast(
          v5,
          0,
          &IBuildingRole__RTTI_Type_Descriptor_,
          &CDarkMushroomFarmRole__RTTI_Type_Descriptor_,
          0)
    && BBSupportDbgReport(
         2,
         "Logic\\DarkTribe.cpp",
         260,
         "dynamic_cast<CDarkMushroomFarmRole*>(&pMushroomFarm->Role()) != 0") == 1 )
  {
    __debugbreak();
  }
  v11 = (CDarkMushroomFarmRole *)CBuilding::Role(BuildingPtr);
  CDarkMushroomFarmRole::AttachServant(v11, (struct CBuilding *)BuildingPtr, a2);
  v10 = CEntityEvent::CEntityEvent((CEntityEvent *)v7, 1u, 0, a3, 0, 0);
  v9 = v10;
  v14 = 0;
  (*(void (__thiscall **)(unsigned __int8 *, CEntityEvent *))(*(_DWORD *)SettlerPtr + 80))(SettlerPtr, v10);
  v14 = -1;
  return CEntityEvent::~CEntityEvent(v7);
}


// address=[0x141c470]
// Decompiled from int __thiscall CDarkTribe::ChangeElementToDarkOrGreen(CDarkTribe *this, int a2, int a3, bool a4, int a5)

void  CDarkTribe::ChangeElementToDarkOrGreen(int,int,bool,int) {
  
  int result; // eax
  int v6; // [esp+0h] [ebp-28h]
  int ThisDecoObj; // [esp+4h] [ebp-24h]
  int v8; // [esp+8h] [ebp-20h] BYREF
  int v9; // [esp+Ch] [ebp-1Ch] BYREF
  int v10; // [esp+10h] [ebp-18h]
  int v11; // [esp+14h] [ebp-14h]
  CDarkTribe *v12; // [esp+18h] [ebp-10h]
  int v13; // [esp+1Ch] [ebp-Ch]
  bool v14; // [esp+23h] [ebp-5h]
  bool v16; // [esp+25h] [ebp-3h]
  bool v17; // [esp+26h] [ebp-2h]
  bool v18; // [esp+27h] [ebp-1h]

  v12 = this;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 486, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  v13 = CWorldManager::Index(a2, a3);
  v18 = CWorldManager::FlagBits(v13, 4u) != 0;
  v16 = v18;
  result = v18;
  if ( a4 == v18 )
    return result;
  if ( a4 )
    CWorldManager::SetFlagBits(v13, 4u);
  else
    CWorldManager::ClearFlagBits(v13, 4);
  IGfxEngine::SetDarkLand((IGfxEngine *)g_pGfxEngine, a2, a3, a4);
  v11 = CWorldManager::ObjectId(v13);
  if ( v11 <= 0 )
  {
    v17 = CWorldManager::FlagBits(v13, 0x40u) == 0;
    v14 = v17;
    if ( a4 )
      v10 = 4;
    else
      v10 = 0;
    v6 = v10;
    if ( (*(unsigned __int8 (__thiscall **)(CDarkTribe *, int, bool))(*(_DWORD *)v12 + 28))(v12, v13, a4) )
    {
      if ( v14 )
      {
        if ( !a4 && a5 > 0 )
          CBuildingMgr::DestroyBuilding((CBuildingMgr *)g_cBuildingMgr, a2, a3, a5);
      }
      else
      {
        ThisDecoObj = CDecoObjMgr::GetThisDecoObj(a2, a3, 3, &v8, &v9);
        if ( ThisDecoObj && CWorldManager::FlagBits(v8, v9, 4u) != v6 )
          CDarkTribe::ChangeObjectToDarkOrGreen(v12, ThisDecoObj, v8, v9, a4);
      }
    }
  }
  else
  {
    CDarkTribe::ChangeObjectToDarkOrGreen(v12, v11, a2, a3, a4);
  }
  return (*(int (__thiscall **)(void *, int, int, int, bool))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 29, a2, a3, a4);
}


// address=[0x141c680]
// Decompiled from void __thiscall CDarkTribe::ChangeObjectToDarkOrGreen(CDarkTribe *this, int a2, int a3, int a4, bool a5)

void  CDarkTribe::ChangeObjectToDarkOrGreen(int,int,int,bool) {
  
  int v5; // eax
  int v7; // [esp+4h] [ebp-18h]
  int v8; // [esp+Ch] [ebp-10h]
  int DarkObject; // [esp+10h] [ebp-Ch]
  unsigned __int16 *DecoObjPtr; // [esp+14h] [ebp-8h]
  char v11; // [esp+1Bh] [ebp-1h]

  DecoObjPtr = (unsigned __int16 *)CDecoObjMgr::GetDecoObjPtr(a2);
  if ( DecoObjPtr && IEntity::Type(DecoObjPtr) != 216 )
  {
    v8 = IEntity::Type(DecoObjPtr);
    v7 = (*(int (__thiscall **)(unsigned __int16 *, CDarkTribe *))(*(_DWORD *)DecoObjPtr + 40))(DecoObjPtr, this);
    if ( a5 )
      DarkObject = CDarkConvert::GetDarkObject(v8);
    else
      DarkObject = CDarkConvert::GetGreenObject(v8);
    CDecoObjMgr::RemoveDecoObject((CDecoObjMgr *)&g_cDecoObjMgr, a3, a4, 0);
    if ( CWorldManager::ObjectId(a3, a4)
      && BBSupportDbgReport(2, "Logic\\DarkTribe.cpp", 592, "g_cWorld.ObjectId( _iX, _iY ) == 0") == 1 )
    {
      __debugbreak();
    }
    v11 = 0;
    if ( DarkObject > 0 && CDecoObjMgr::IsAddDecoObjOk((CDecoObjMgr *)&g_cDecoObjMgr, a3, a4, DarkObject, 0, 0) )
    {
      CDecoObjMgr::AddDecoObj((CDecoObjMgr *)&g_cDecoObjMgr, a3, a4, DarkObject, v7, 1);
      v11 = 1;
    }
    if ( !v11 )
    {
      v5 = CLogic::Effects((DWORD *)g_pLogic);
      (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v5 + 16))(
        v5,
        64,
        69,
        a3,
        a4,
        0,
        0,
        0);
    }
    if ( (CWorldManager::FlagBits(a3, a4, 4u) != 0) != a5 )
    {
      if ( a5 )
        CWorldManager::SetFlagBits(a3, a4, 4);
      else
        CWorldManager::ClearFlagBits(a3, a4, 4);
      IGfxEngine::SetDarkLand((IGfxEngine *)g_pGfxEngine, a3, a4, a5);
    }
  }
}


// address=[0x141c840]
// Decompiled from void __thiscall CDarkTribe::FillUnderObject(CDarkTribe *this, int a2, int a3, bool a4)

void  CDarkTribe::FillUnderObject(int,int,bool) {
  
  int v5; // [esp+Ch] [ebp-10h]
  int v6; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]

  if ( (CWorldManager::FlagBits(a2, a3, 4u) == 4) != a4 )
  {
    if ( a4 )
      CWorldManager::SetFlagBits(a2, a3, 4);
    else
      CWorldManager::ClearFlagBits(a2, a3, 4);
    IGfxEngine::SetDarkLand((IGfxEngine *)g_pGfxEngine, a2, a3, a4);
    for ( i = 1; i < 7; ++i )
    {
      v5 = a2 + CSpiralOffsets::DeltaX(i);
      v6 = a3 + CSpiralOffsets::DeltaY(i);
      if ( (unsigned __int8)CWorldManager::InWorld(v5, v6) )
      {
        if ( CWorldManager::FlagBits(v5, v6, 0x40u) )
          return;
        if ( (CWorldManager::FlagBits(v5, v6, 4u) == 4) != a4 )
          CDarkTribe::FillUnderObject(this, v5, v6, a4);
      }
    }
  }
}


// address=[0x141c9a0]
// Decompiled from void __thiscall CDarkTribe::SetHolesDarkOrGreen(CDarkTribe *this, int a2, int a3, bool a4, int a5)

void  CDarkTribe::SetHolesDarkOrGreen(int,int,bool,int) {
  
  int v6; // [esp+8h] [ebp-1Ch]
  int v7; // [esp+Ch] [ebp-18h]
  int v8; // [esp+10h] [ebp-14h]
  int v9; // [esp+14h] [ebp-10h]
  int j; // [esp+18h] [ebp-Ch]
  int i; // [esp+1Ch] [ebp-8h]
  char v12; // [esp+22h] [ebp-2h]

  for ( i = 1; i < 7; ++i )
  {
    v8 = a2 + CSpiralOffsets::DeltaX(i);
    v9 = a3 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v8, v9) && (CWorldManager::FlagBits(v8, v9, 4u) != 0) != a4 )
    {
      v12 = 1;
      for ( j = 1; j < 7; ++j )
      {
        v6 = v8 + CSpiralOffsets::DeltaX(j);
        v7 = v9 + CSpiralOffsets::DeltaY(j);
        if ( (unsigned __int8)CWorldManager::InWorld(v6, v7) && (CWorldManager::FlagBits(v6, v7, 4u) == 4) != a4 )
        {
          v12 = 0;
          break;
        }
      }
      if ( v12 )
        CDarkTribe::ChangeElementToDarkOrGreen(this, v8, v9, a4, a5);
    }
  }
}


