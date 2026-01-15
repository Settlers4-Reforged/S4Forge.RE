#include "CBuildingMgr.h"

// Definitions for class CBuildingMgr

// address=[0x12fcb90]
// Decompiled from CBuilding *__stdcall CBuildingMgr::operator[](int a1)
class CBuilding &  CBuildingMgr::operator[](int) {
  
  IEntity *v2; // [esp+4h] [ebp-4h]

  v2 = CMapObjectMgr::EntityPtr(a1);
  if ( !v2
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Building\\BuildingMgr.h",
         408,
         "pEntity != 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::ObjType(v2) != 8
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Building\\BuildingMgr.h",
         409,
         "pEntity->ObjType() == BUILDING_OBJ") == 1 )
  {
    __debugbreak();
  }
  return (CBuilding *)v2;
}


// address=[0x130e930]
// Decompiled from unsigned __int8 *__thiscall CBuildingMgr::Building(CBuildingMgr *this, int a2)
class CBuilding &  CBuildingMgr::Building(int) {
  
  unsigned __int8 *v3; // [esp+4h] [ebp-4h]

  v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a2);
  if ( !v3
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Building\\BuildingMgr.h",
         423,
         "pEntity != 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::ObjType(v3) != 8
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Building\\BuildingMgr.h",
         424,
         "pEntity->ObjType() == BUILDING_OBJ") == 1 )
  {
    __debugbreak();
  }
  return v3;
}


// address=[0x130eba0]
// Decompiled from unsigned __int8 *__thiscall CBuildingMgr::GetBuildingPtr(CBuildingMgr *this, int a2)
class CBuilding *  CBuildingMgr::GetBuildingPtr(int) {
  
  unsigned __int8 *v4; // [esp+Ch] [ebp-4h]

  v4 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a2);
  if ( v4 && IEntity::ObjType(v4) == 8 )
    return v4;
  else
    return 0;
}


// address=[0x13361b0]
// Decompiled from unsigned int __thiscall CBuildingMgr::GetTimeSinceHallDestruction(CBuildingMgr *this, int a2)
int  CBuildingMgr::GetTimeSinceHallDestruction(int) {
  
  return (CStateGame::GetTickCounter(g_pGame) - *((_DWORD *)this + a2 + 72884)) / 0xEu;
}


// address=[0x1336400]
// Decompiled from bool __thiscall CBuildingMgr::PlayerUsesManakopterHalls(CBuildingMgr *this, int a2)
bool  CBuildingMgr::PlayerUsesManakopterHalls(int) {
  
  return *((_DWORD *)this + a2 + 72875) > 0;
}


// address=[0x14eb500]
// Decompiled from bool __cdecl CBuildingMgr::IsMilitaryBuildingEx(int a1)
static bool __cdecl CBuildingMgr::IsMilitaryBuildingEx(int) {
  
  return a1 == 46 || a1 == 47 || a1 == 48 || a1 == 50 || a1 == 51;
}


// address=[0x14f42d0]
// Decompiled from CBuildingMgr *__thiscall CBuildingMgr::CBuildingMgr(CBuildingMgr *this)
 CBuildingMgr::CBuildingMgr(void) {
  
  MemoryAllocator::MemoryAllocator(this, 0x64u, 0x20u, 0);
  *((_DWORD *)this + 6) = 0;
  CBuildingMgr::Clear(this);
  *((_BYTE *)this + 11980) = 0;
  return this;
}


// address=[0x14f4340]
// Decompiled from void __thiscall CBuildingMgr::~CBuildingMgr(CBuildingMgr *this)
 CBuildingMgr::~CBuildingMgr(void) {
  
  MemoryAllocator::~MemoryAllocator(this);
}


// address=[0x14f4360]
// Decompiled from void *__thiscall CBuildingMgr::Clear(CBuildingMgr *this)
void  CBuildingMgr::Clear(void) {
  
  *((_DWORD *)this + 6) = 0;
  memset((char *)this + 28, 0, 0xBACu);
  memset((char *)this + 3016, 0, 0x1758u);
  memset((char *)this + 8992, 0, 0xBACu);
  memset((char *)this + 288731, 0, 0x400u);
  memset((char *)this + 289755, 0, 0x400u);
  memset((char *)this + 11981, 0, 0x4390Eu);
  memset((char *)this + 290780, 0, 0x2D0u);
  memset((char *)this + 291500, 0, 0x24u);
  return memset((char *)this + 291536, 0, 0x24u);
}


// address=[0x14f4450]
// Decompiled from void __thiscall CBuildingMgr::LoadInfo(CBuildingMgr *this)
void  CBuildingMgr::LoadInfo(void) {
  
  CBuildingInfoMgr::LoadInfo((CBuildingInfoMgr *)&g_cBuildingInfoMgr, 0);
}


// address=[0x14f4470]
// Decompiled from int __thiscall CBuildingMgr::LoadBuildingData(CBuildingMgr *this, struct S4::CMapFile *a2, unsigned __int16 a3)
void  CBuildingMgr::LoadBuildingData(class S4::CMapFile &,int) {
  
  int v3; // eax
  IBuildingRole *v4; // eax
  int result; // eax
  struct CBuilding *v6; // [esp-4h] [ebp-40h]
  int v7; // [esp+0h] [ebp-3Ch]
  int v8; // [esp+4h] [ebp-38h]
  int v9; // [esp+8h] [ebp-34h]
  char *v10; // [esp+10h] [ebp-2Ch]
  int v11; // [esp+14h] [ebp-28h] BYREF
  int v12; // [esp+18h] [ebp-24h]
  int k; // [esp+1Ch] [ebp-20h]
  int *v14; // [esp+20h] [ebp-1Ch]
  int v15; // [esp+24h] [ebp-18h]
  int i; // [esp+28h] [ebp-14h]
  int j; // [esp+2Ch] [ebp-10h]
  unsigned __int16 *v18; // [esp+30h] [ebp-Ch]
  char *v19; // [esp+34h] [ebp-8h]
  unsigned __int8 IsPort; // [esp+3Ah] [ebp-2h]
  bool IsShipyard; // [esp+3Bh] [ebp-1h]

  v14 = (int *)this;
  *((_BYTE *)this + 11980) = 1;
  v11 = 0;
  v10 = (char *)S4::CMapFile::LoadChunk(a2, a3, 0, &v11, 0);
  for ( i = 0; i < v11; ++i )
  {
    v19 = &v10[20 * i];
    v8 = *(unsigned __int16 *)v19;
    v9 = *((unsigned __int16 *)v19 + 1);
    v15 = (unsigned __int8)v19[4];
    if ( v15 )
    {
      v12 = CBuildingMgr::AddBuilding(v14, v8, v9, (unsigned __int8)v10[20 * i + 5], v15, 0);
      if ( v12 )
      {
        v18 = (unsigned __int16 *)CBuildingMgr::operator[](v12);
        v3 = IEntity::Type(v18);
        if ( (unsigned __int8)CBuildingMgr::IsMilitary(v3) && v19[6] )
        {
          v7 = CBuilding::Role(v18);
          for ( j = 0; j < 9; ++j )
          {
            for ( k = 0; k < (unsigned __int8)v19[j + 7]; ++k )
              CBuildingMgr::AddSoldierToStartTower(v12, j);
          }
        }
        IsPort = CBuildingMgr::IsPortEx(v15);
        IsShipyard = CBuildingMgr::IsShipyardEx(v15);
        if ( IsShipyard | IsPort )
        {
          v6 = (struct CBuilding *)v18;
          v4 = (IBuildingRole *)CBuilding::Role(v18);
          IBuildingRole::PostLoadSetWaterFlags(v4, v6);
          if ( IsShipyard )
            (*(void (__thiscall **)(unsigned __int16 *, int))(*(_DWORD *)v18 + 12))(v18, v7);
        }
      }
    }
  }
  S4::CMapFile::CloseChunk(a2, a3, 0);
  *((_BYTE *)v14 + 11980) = 0;
  return result;
}


// address=[0x14f4630]
// Decompiled from int __thiscall CBuildingMgr::AddBuilding(CBuildingMgr *this, int a2, int a3, int a4, int a5, bool a6)
int  CBuildingMgr::AddBuilding(int,int,int,int,bool) {
  
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v11; // [esp-8h] [ebp-5Ch] BYREF
  int v12; // [esp-4h] [ebp-58h]
  int v13; // [esp+4h] [ebp-50h]
  int *v14; // [esp+8h] [ebp-4Ch]
  int v15; // [esp+Ch] [ebp-48h]
  int v16; // [esp+10h] [ebp-44h]
  int v17; // [esp+14h] [ebp-40h]
  unsigned __int16 *v18; // [esp+18h] [ebp-3Ch]
  unsigned __int16 *v19; // [esp+1Ch] [ebp-38h]
  struct IBuildingRole *BuildingRole; // [esp+20h] [ebp-34h]
  int v21; // [esp+24h] [ebp-30h]
  unsigned __int16 *v22; // [esp+28h] [ebp-2Ch]
  int v23; // [esp+2Ch] [ebp-28h]
  char v24[4]; // [esp+30h] [ebp-24h] BYREF
  int FreeSlot; // [esp+34h] [ebp-20h]
  int v26; // [esp+38h] [ebp-1Ch]
  _DWORD *v27; // [esp+3Ch] [ebp-18h]
  CBuildingMgr *v28; // [esp+40h] [ebp-14h]
  bool v29; // [esp+47h] [ebp-Dh]
  int v30; // [esp+50h] [ebp-4h]

  v28 = this;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 441, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 442, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a5 <= 0 || a5 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         444,
         "(_iBuildingTypeEx > BUILDING_NO_BUILDING) && (_iBuildingTypeEx < BUILDING_MAX)") == 1 )
  {
    __debugbreak();
  }
  if ( a5 == 32
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 445, "_iBuildingTypeEx != BUILDING_PORT") == 1 )
  {
    __debugbreak();
  }
  if ( a5 == 31
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 446, "_iBuildingTypeEx != BUILDING_SHIPYARD") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)v28 + 6) >= 4000 )
    return 0;
  v29 = 0;
  if ( a5 == 80 )
  {
    v29 = CBuildingMgr::GetFirstBuildingId(v28, a4, 80) != 0;
    v6 = Y16X16::PackXYFast(a2, a3);
    if ( !CBuildingMgr::AddPositionToList(v28, v6, a4) )
      BBSupportTracePrintF(1, "Couldn't build ManakopterHall at pos %d,%d for player %d", a2, a3, a4);
  }
  ++*((_DWORD *)v28 + 6);
  v7 = CPlayerManager::Race(a4);
  BuildingRole = CBuildingMgr::CreateBuildingRole(a5, v7, a6);
  std::auto_ptr<IBuildingRole>::auto_ptr<IBuildingRole>(v24, (int)BuildingRole);
  v30 = 0;
  FreeSlot = CMapObjectMgr::GetFreeSlot();
  v23 = CBuilding::operator new(0x64u);
  LOBYTE(v30) = 1;
  if ( v23 )
  {
    v12 = FreeSlot;
    v11 = v8;
    v14 = &v11;
    v13 = std::auto_ptr<IBuildingRole>::auto_ptr<IBuildingRole>((int)v24);
    v19 = (unsigned __int16 *)CBuilding::CBuilding(v23, a2, a3, a5, a4, v11, v12);
    v22 = v19;
  }
  else
  {
    v22 = 0;
  }
  v18 = v22;
  LOBYTE(v30) = 0;
  v27 = v22;
  v26 = IEntity::Type(v22);
  v21 = 0;
  if ( !a6 )
  {
    v21 = 1;
    CBuilding::SetToWorld(v27);
    CStatistic::AddBuilding((CStatistic *)&g_cStatistic, a4, v26, 1);
    IEntity::SetFlagBits(v27, (EntityFlag)0x10000u);
    v12 = 1;
    v11 = IEntity::Y(v27);
    v9 = IEntity::X(v27);
    if ( !CWorldManager::FlagBits(v9, v11, v12)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingMgr.cpp",
           504,
           "g_cWorld.FlagBits(pBuilding->X(), pBuilding->Y(), FLAG_BLOCKED_LAND) != 0") == 1 )
    {
      __debugbreak();
    }
  }
  CBuildingMgr::AttachBuilding(v28, a4, v26, FreeSlot);
  CBuildingMgr::ChangeNumberOfBuildings(v28, a4, v26, v21, 1);
  if ( v29 )
  {
    v17 = *((_DWORD *)v28 + a4 + 72884);
    CBuildingMgr::DestroyBuilding(v28, a2, a3, a4);
    *((_DWORD *)v28 + a4 + 72884) = v17;
    v16 = 0;
    v30 = -1;
    std::auto_ptr<IBuildingRole>::~auto_ptr<IBuildingRole>(v24);
    return v16;
  }
  else
  {
    v15 = FreeSlot;
    v30 = -1;
    std::auto_ptr<IBuildingRole>::~auto_ptr<IBuildingRole>(v24);
    return v15;
  }
}


// address=[0x14f4990]
// Decompiled from int __thiscall CBuildingMgr::SearchSpaceForBuilding(  CBuildingMgr *this,  int a2,  int a3,  int a4,  int a5,  bool a6,  int a7)
int  CBuildingMgr::SearchSpaceForBuilding(int,int,int,int,bool,int) {
  
  int v8; // [esp+4h] [ebp-20h]
  int v9; // [esp+8h] [ebp-1Ch]
  int v10; // [esp+Ch] [ebp-18h]
  int v12; // [esp+14h] [ebp-10h]
  int v13; // [esp+18h] [ebp-Ch]
  int v14; // [esp+1Ch] [ebp-8h]
  char IsMilitary; // [esp+23h] [ebp-1h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 549, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 550, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a5 <= 0 || a5 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         551,
         "_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  v14 = 0;
  v10 = 0;
  if ( a7 >= 0 )
  {
    if ( a7 >= 75 )
      a7 = 74;
  }
  else
  {
    a7 = 24;
  }
  v8 = CSpiralOffsets::Last(a7);
  IsMilitary = CBuildingMgr::IsMilitary(a5);
  if ( IsMilitary )
    v9 = 2;
  else
    v9 = 0;
  while ( v14 < v8 )
  {
    v12 = a2 + CSpiralOffsets::DeltaX(v14);
    v13 = a3 + CSpiralOffsets::DeltaY(v14);
    if ( (unsigned __int8)CWorldManager::InWorld(v12, v13) && CBuildingMgr::CheckForBuild(this, v12, v13, a4, a5, v9) )
    {
      v10 = CBuildingMgr::AddBuilding((int *)this, v12, v13, a4, a5, 0);
      if ( IsMilitary )
        CBuildingMgr::AddSoldierToStartTower(v10, 0);
      return v10;
    }
    ++v14;
  }
  return v10;
}


// address=[0x14f4b50]
// Decompiled from void __thiscall CBuildingMgr::DestroyBuilding(CBuildingMgr *this, int a2, int a3, int a4)
void  CBuildingMgr::DestroyBuilding(int,int,int) {
  
  int TickCounter; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // [esp-10h] [ebp-78h]
  int v13; // [esp-10h] [ebp-78h]
  int v14; // [esp-Ch] [ebp-74h]
  int v15; // [esp-Ch] [ebp-74h]
  int v16; // [esp-8h] [ebp-70h]
  int v17; // [esp-8h] [ebp-70h]
  int v18; // [esp-4h] [ebp-6Ch]
  char *v19; // [esp-4h] [ebp-6Ch]
  char *v20; // [esp-4h] [ebp-6Ch]
  _DWORD v21[7]; // [esp+4h] [ebp-64h] BYREF
  _DWORD v22[8]; // [esp+20h] [ebp-48h] BYREF
  int v23; // [esp+40h] [ebp-28h]
  int v24; // [esp+44h] [ebp-24h]
  CBuildingMgr *v25; // [esp+48h] [ebp-20h]
  int v26; // [esp+4Ch] [ebp-1Ch]
  int v27; // [esp+50h] [ebp-18h]
  int v28; // [esp+54h] [ebp-14h]
  int i; // [esp+58h] [ebp-10h]
  char *BuildingInfo; // [esp+5Ch] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+60h] [ebp-8h]
  bool v32; // [esp+65h] [ebp-3h]
  bool v33; // [esp+66h] [ebp-2h]
  char v34; // [esp+67h] [ebp-1h]

  v25 = this;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1001, "g_cWorld.InWorld(_iX, _iY)") == 1 )
  {
    __debugbreak();
  }
  if ( a4 != -1
    && a4
    && !CPlayerManager::ValidUsedPlayerId(a4)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1002,
         "(_iGardenerPlayerIdEx == -1) || (_iGardenerPlayerIdEx == 0) || (g_cPlayerMgr.ValidUsedPlayerId(_iGardenerPlayerIdEx))") == 1 )
  {
    __debugbreak();
  }
  if ( !CWorldManager::FlagBits(a2, a3, 8u)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1004,
         "g_cWorld.FlagBits(_iX, _iY, FLAG_BUILDING)") == 1 )
  {
    __debugbreak();
  }
  if ( (unsigned __int8)CWorldManager::InWorld(a2, a3) && !CWorldManager::IsWater(a2, a3) )
  {
    for ( i = 0; i < 9900; ++i )
    {
      v28 = a2 + CSpiralOffsets::DeltaX(i);
      v27 = a3 + CSpiralOffsets::DeltaY(i);
      if ( (unsigned __int8)CWorldManager::InWorld(v28, v27) )
      {
        v26 = CWorldManager::MapObjectId(v28, v27);
        BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v26);
        if ( !BuildingPtr )
        {
          v26 = CWorldManager::ObjectId(v28, v27);
          BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v26);
        }
        if ( BuildingPtr )
        {
          if ( IEntity::Type((unsigned __int16 *)BuildingPtr) == 80 )
          {
            if ( !g_pGame && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1042, "g_pGame != 0") == 1 )
              __debugbreak();
            if ( g_pGame )
            {
              TickCounter = CStateGame::GetTickCounter(g_pGame);
              v5 = IEntity::OwnerId(BuildingPtr);
              *((_DWORD *)v25 + v5 + 72884) = TickCounter;
            }
            else
            {
              v6 = IEntity::OwnerId(BuildingPtr);
              *((_DWORD *)v25 + v6 + 72884) = 0;
            }
          }
          v7 = IEntity::X(BuildingPtr);
          if ( v28 != v7
            && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1055, "iCheckX == pBuilding->X()") == 1 )
          {
            __debugbreak();
          }
          v8 = IEntity::Y(BuildingPtr);
          if ( v27 != v8
            && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1056, "iCheckY == pBuilding->Y()") == 1 )
          {
            __debugbreak();
          }
          v34 = 0;
          v18 = CBuilding::BuildingTypeEx(BuildingPtr);
          v9 = IEntity::Race(BuildingPtr);
          BuildingInfo = (char *)CBuildingInfoMgr::GetBuildingInfo(v9, v18);
          v19 = BuildingInfo + 720;
          v16 = BuildingInfo[1];
          v14 = *BuildingInfo;
          v12 = IEntity::Y(BuildingPtr);
          v10 = IEntity::X(BuildingPtr);
          CBuildingFlagsWalk::CBuildingFlagsWalk(v10, v12, v14, v16, v19);
          while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v22) )
          {
            if ( CBuildingFlagsWalk::CurrentX(v22) == a2 && CBuildingFlagsWalk::CurrentY(v22) == a3 )
            {
              v34 = 1;
              break;
            }
          }
          if ( !v34 && BuildingInfo[6] )
          {
            v20 = BuildingInfo + 784;
            v17 = BuildingInfo[1];
            v15 = *BuildingInfo;
            v13 = IEntity::Y(BuildingPtr);
            v11 = IEntity::X(BuildingPtr);
            CBuildingFlagsWalk::CBuildingFlagsWalk(v11, v13, v15, v17, v20);
            while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v21) )
            {
              if ( CBuildingFlagsWalk::CurrentX(v21) == a2 && CBuildingFlagsWalk::CurrentY(v21) == a3 )
              {
                v34 = 1;
                break;
              }
            }
          }
          if ( v34 )
          {
            v23 = IEntity::Race(BuildingPtr);
            v33 = v23 == 3;
            v32 = v23 == 3;
            if ( a4 != -1 && (a4 || v32) && (a4 <= 0 || !v32) )
              return;
            if ( a4 >= 0 )
              v24 = a4;
            else
              v24 = 0;
            v22[7] = v24;
            CBuilding::DestroyBuilding((CBuilding *)BuildingPtr, v24);
            return;
          }
        }
      }
    }
    if ( BBSupportDbgReport(
           1,
           "MapObjects\\Building\\BuildingMgr.cpp",
           1122,
           "CBuildingMgr::DestroyBuilding(): Can't find building!") == 1 )
      __debugbreak();
  }
}


// address=[0x14f4f60]
// Decompiled from int __thiscall CBuildingMgr::GetFirstBuildingId(CBuildingMgr *this, int a2, int a3)
int  CBuildingMgr::GetFirstBuildingId(int,int)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1139, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1140,
         "_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  return *((_DWORD *)this + 83 * a2 + a3 + 7);
}


// address=[0x14f4fe0]
// Decompiled from int __thiscall CBuildingMgr::GetNextBuilding(CBuildingMgr *this, int a2, int a3)
class CBuilding *  CBuildingMgr::GetNextBuilding(int,int)const {
  
  int v5; // [esp+4h] [ebp-Ch]
  unsigned __int8 *BuildingPtr; // [esp+8h] [ebp-8h]
  int *v7; // [esp+Ch] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1176, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1177,
         "_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  v7 = (int *)((char *)this + 332 * a2 + 4 * a3 + 8992);
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *v7);
  if ( BuildingPtr )
    v5 = IAnimatedEntity::Next(BuildingPtr);
  else
    v5 = 0;
  *v7 = v5;
  if ( !*v7 )
    *v7 = *((_DWORD *)this + 83 * a2 + a3 + 7);
  if ( *v7 )
    return CBuildingMgr::operator[](*v7);
  else
    return 0;
}


// address=[0x14f50e0]
// Decompiled from int __thiscall CBuildingMgr::GetBuilding(CBuildingMgr *this, int a2, int a3)
class CBuilding *  CBuildingMgr::GetBuilding(int,int)const {
  
  _DWORD *v5; // [esp+4h] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1153, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1154,
         "_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  v5 = (_DWORD *)((char *)this + 332 * a2 + 4 * a3 + 8992);
  if ( !*v5 )
    CBuildingMgr::GetNextBuilding(this, a2, a3);
  if ( *v5 )
    return CBuildingMgr::operator[](*v5);
  else
    return 0;
}


// address=[0x14f51a0]
// Decompiled from int __thiscall CBuildingMgr::GetNumberOfBuildings(CBuildingMgr *this, int a2, int a3, unsigned int a4)
int  CBuildingMgr::GetNumberOfBuildings(int,int,int)const {
  
  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1287, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1288,
         "_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a4 > 2
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1289,
         "_iPeriod>=BUILDING_PERIOD_BIRTH && _iPeriod<=BUILDING_PERIOD_ALL") == 1 )
  {
    __debugbreak();
  }
  switch ( a4 )
  {
    case 0u:
      return *((_DWORD *)this + 166 * a2 + 2 * a3 + 754);
    case 1u:
      return *((_DWORD *)this + 166 * a2 + 2 * a3 + 755);
    case 2u:
      return *((_DWORD *)this + 166 * a2 + 2 * a3 + 755) + *((_DWORD *)this + 166 * a2 + 2 * a3 + 754);
  }
  return 0;
}


// address=[0x14f52f0]
// Decompiled from int __thiscall CBuildingMgr::ChangeNumberOfBuildings(CBuildingMgr *this, int a2, int a3, unsigned int a4, int a5)
void  CBuildingMgr::ChangeNumberOfBuildings(int,int,int,int) {
  
  int result; // eax

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1335, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1336,
         "_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a4 > 2
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1337,
         "_iPeriod>=BUILDING_PERIOD_BIRTH && _iPeriod<=BUILDING_PERIOD_ALL") == 1 )
  {
    __debugbreak();
  }
  if ( a4 == 2
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1338, "BUILDING_PERIOD_ALL != _iPeriod") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( a4 )
  {
    if ( a4 == 1 )
    {
      result = 4;
      *((_DWORD *)this + 166 * a2 + 2 * a3 + 755) += a5;
    }
  }
  else
  {
    result = a5 + *((_DWORD *)this + 166 * a2 + 2 * a3 + 754);
    *((_DWORD *)this + 166 * a2 + 2 * a3 + 754) = result;
  }
  return result;
}


// address=[0x14f5460]
// Decompiled from char __thiscall CBuildingMgr::CheckNumberOfOccupiedMilitaryBuildings(CBuildingMgr *this, int a2, int a3)
bool  CBuildingMgr::CheckNumberOfOccupiedMilitaryBuildings(int,int) {
  
  unsigned __int8 *v4; // [esp+4h] [ebp-18h]
  int v6; // [esp+Ch] [ebp-10h]
  int j; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h]
  int i; // [esp+18h] [ebp-4h]

  if ( !CPlayerManager::ValidUsedPlayerId(a2)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         3517,
         "g_cPlayerMgr.ValidUsedPlayerId(_iPlayerId)") == 1 )
  {
    __debugbreak();
  }
  if ( a3 <= 0 )
    return 1;
  v8 = 0;
  for ( i = 0; i < 5; ++i )
  {
    v6 = dword_377EE80[i];
    if ( !CBuildingMgr::IsMilitaryBuildingEx(v6)
      && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 3532, "IsMilitaryBuildingEx(iBuildingType)") == 1 )
    {
      __debugbreak();
    }
    for ( j = CBuildingMgr::GetFirstBuildingId(this, a2, v6); j; j = IAnimatedEntity::Next(v4) )
    {
      v4 = CBuildingMgr::Building(this, j);
      if ( CBuilding::IsOccupied((CBuilding *)v4) && ++v8 >= a3 )
        return 1;
    }
  }
  return 0;
}


// address=[0x14f5580]
// Decompiled from bool __cdecl CBuildingMgr::IsMine(int a1)
static bool __cdecl CBuildingMgr::IsMine(int) {
  
  if ( (a1 <= 0 || a1 >= 83)
    && BBSupportDbgReport(
         2,
         (int)"MapObjects\\Building\\BuildingMgr.cpp",
         1374,
         (int)"_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  return *(_BYTE *)(CBuildingInfoMgr::GetBuildingInfo(0, a1) + 477) == 7;
}


// address=[0x14f55e0]
// Decompiled from bool __cdecl CBuildingMgr::IsMilitary(int a1)
static bool __cdecl CBuildingMgr::IsMilitary(int) {
  
  int BuildingInfo; // [esp+4h] [ebp-4h]

  if ( (a1 <= 0 || a1 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1393,
         "_iBuildingType > 0 && _iBuildingType < BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  BuildingInfo = CBuildingInfoMgr::GetBuildingInfo(0, a1);
  return *(_BYTE *)(BuildingInfo + 477) == 10 || *(_BYTE *)(BuildingInfo + 477) == 15;
}


// address=[0x14f5660]
// Decompiled from bool __cdecl CBuildingMgr::IsPortEx(int a1)
static bool __cdecl CBuildingMgr::IsPortEx(int) {
  
  return a1 >= 52 && a1 <= 57 || a1 >= 78 && a1 <= 79;
}


// address=[0x14f56a0]
// Decompiled from bool __cdecl CBuildingMgr::IsShipyardEx(int a1)
static bool __cdecl CBuildingMgr::IsShipyardEx(int) {
  
  return a1 >= 58 && a1 <= 63 || a1 >= 76 && a1 <= 77;
}


// address=[0x14f56e0]
// Decompiled from int __thiscall CBuildingMgr::CheckForBuild(CBuildingMgr *this, int a2, int a3, int a4, int a5, int a6)
int  CBuildingMgr::CheckForBuild(int,int,int,int,int) {
  
  int result; // eax
  void *v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  _DWORD *v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // ecx
  int v21; // [esp-8h] [ebp-104h]
  int v22; // [esp-4h] [ebp-100h]
  int v23; // [esp-4h] [ebp-100h]
  int v24; // [esp-4h] [ebp-100h]
  int v25; // [esp-4h] [ebp-100h]
  _DWORD v26[7]; // [esp+4h] [ebp-F8h] BYREF
  _DWORD v27[16]; // [esp+20h] [ebp-DCh] BYREF
  int v28; // [esp+60h] [ebp-9Ch]
  int v29; // [esp+64h] [ebp-98h]
  int v30; // [esp+68h] [ebp-94h]
  int v31; // [esp+6Ch] [ebp-90h]
  int v32; // [esp+70h] [ebp-8Ch]
  int v33; // [esp+74h] [ebp-88h]
  int v34; // [esp+78h] [ebp-84h]
  int v35; // [esp+7Ch] [ebp-80h]
  int v36; // [esp+80h] [ebp-7Ch]
  int v37; // [esp+84h] [ebp-78h]
  int v38; // [esp+88h] [ebp-74h]
  int v39; // [esp+8Ch] [ebp-70h]
  __int64 v40; // [esp+90h] [ebp-6Ch]
  int v41; // [esp+98h] [ebp-64h]
  int v42; // [esp+9Ch] [ebp-60h]
  int v43; // [esp+A0h] [ebp-5Ch]
  int v44; // [esp+A4h] [ebp-58h]
  int v45; // [esp+A8h] [ebp-54h]
  int v46; // [esp+ACh] [ebp-50h]
  int v47; // [esp+B0h] [ebp-4Ch]
  int v48; // [esp+B4h] [ebp-48h]
  int j; // [esp+B8h] [ebp-44h]
  int i; // [esp+BCh] [ebp-40h]
  int v51; // [esp+C0h] [ebp-3Ch]
  _BYTE *v52; // [esp+C4h] [ebp-38h]
  CBuildingSiteRole *v53; // [esp+C8h] [ebp-34h]
  int v54; // [esp+CCh] [ebp-30h]
  int v55; // [esp+D0h] [ebp-2Ch]
  int v56; // [esp+D4h] [ebp-28h]
  int v57; // [esp+D8h] [ebp-24h]
  int v58; // [esp+DCh] [ebp-20h]
  int *v59; // [esp+E0h] [ebp-1Ch]
  int v60; // [esp+E4h] [ebp-18h]
  int k; // [esp+E8h] [ebp-14h]
  int m; // [esp+ECh] [ebp-10h]
  char v63; // [esp+F3h] [ebp-9h]
  unsigned int v64; // [esp+F4h] [ebp-8h]
  char *BuildingInfo; // [esp+F8h] [ebp-4h]
  int v66; // [esp+110h] [ebp+14h]

  v59 = (int *)this;
  if ( (a4 <= 0 || a4 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 2556, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a5 <= 0 || a5 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         2557,
         "_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  v41 = CWorldManager::Width(0);
  if ( v41 != CWorldManager::Height()
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 2561, "iWorldWidthHeight == g_cWorld.Height()") == 1 )
  {
    __debugbreak();
  }
  v63 = 0;
  if ( !Grid::InQuadrat((Grid *)(a2 - 16), a3 - 16, v41 - 32) )
    return -1;
  HIDWORD(v40) = a5 == 31;
  LODWORD(v40) = a5 == 32;
  if ( v40 )
  {
    if ( a5 == 31 )
      v66 = 58;
    else
      v66 = 52;
    a5 = CBuildingMgr::CheckForBuildInWater((CBuildingMgr *)v59, a2, a3, a4, v66);
    if ( !a5 )
      return -1;
    v63 = 1;
  }
  v54 = a4;
  if ( a6 >= 2 )
  {
    a6 -= 2;
    v54 = 0;
  }
  v7 = (void *)CPlayerManager::PlayerInfo(a4);
  v39 = CPlayerInfo::Race(v7);
  v27[15] = 95;
  v27[14] = 2;
  v27[13] = 8;
  v27[12] = 512;
  v27[11] = 16;
  v27[10] = 4;
  v60 = 0;
  v56 = 10;
  v51 = v39 - 1;
  switch ( v39 )
  {
    case 1:
      v60 = 2;
      v56 = 522;
      goto CBuildingMgr__CheckForBuild___def_18F58B2;
    case 2:
      v60 = 1;
      v56 = 26;
      goto CBuildingMgr__CheckForBuild___def_18F58B2;
    case 3:
      return CBuildingMgr::CheckForBuildDarkTribe((CBuildingMgr *)v59, a2, a3, a4, a5, a6);
    case 4:
      v60 = 4;
      v56 = 538;
      goto CBuildingMgr__CheckForBuild___def_18F58B2;
    default:
CBuildingMgr__CheckForBuild___def_18F58B2:
      if ( (unsigned __int8)CBuildingMgr::IsMine(a5) )
      {
        v60 = 3;
        v56 = 4;
      }
      BuildingInfo = (char *)CBuildingInfoMgr::GetBuildingInfo(v39, a5);
      if ( v63 )
        goto LABEL_71;
      v27[9] = 0;
      if ( a5 == 31
        && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 2686, "_iBuildingType != BUILDING_SHIPYARD") == 1 )
      {
        __debugbreak();
      }
      if ( a5 == 32
        && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 2687, "_iBuildingType != BUILDING_PORT") == 1 )
      {
        __debugbreak();
      }
      v27[8] = a2 + 32 - *BuildingInfo - 1;
      v27[7] = a3 - BuildingInfo[1] - 1;
      v38 = CWorldManager::Index(a2, a3);
      if ( CWorldManager::FlagBits(v38, 0x5Fu) || ITiling::OwnerId(v38) != v54 )
        return -1;
      v8 = std::vector<unsigned int>::operator[](0);
      v9 = std::vector<unsigned int>::size(BuildingInfo + 720, v8, 95);
      if ( !(*(unsigned __int8 (__thiscall **)(void *, int, int, int, int, int))(*(_DWORD *)g_pTiling + 64))(
              g_pTiling,
              a2 - *BuildingInfo,
              a3 - BuildingInfo[1],
              v9,
              v21,
              v22) )
        return -1;
      CBuildingFlagsWalk::CBuildingFlagsWalk(a2, a3, *BuildingInfo, BuildingInfo[1], BuildingInfo + 720);
      if ( v60 == 3 )
      {
        while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v27) )
        {
          v23 = CBuildingFlagsWalk::CurrentY(v27);
          v10 = CBuildingFlagsWalk::CurrentX(v27);
          v47 = CWorldManager::Index(v10, v23);
          v11 = ITiling::OwnerId(v47);
          if ( v11 != v54 )
            return -1;
          v48 = CWorldManager::Ground(v47);
          v34 = v48 & 0xF0;
          if ( v48 != 17 && v34 != 32 )
            return -1;
          if ( v48 != 32 )
          {
            for ( i = 0; i < 6; ++i )
            {
              v12 = CWorldManager::NeighborRelIndex(i);
              v33 = v47 + v12;
              if ( CWorldManager::FlagBits(v47 + v12, 1u) )
                return -1;
            }
          }
        }
      }
      else
      {
        while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v27) )
        {
          v24 = CBuildingFlagsWalk::CurrentY(v27);
          v13 = CBuildingFlagsWalk::CurrentX(v27);
          v46 = CWorldManager::Index(v13, v24);
          v14 = ITiling::OwnerId(v46);
          if ( v14 != v54 )
            return -1;
          v37 = CWorldManager::Ground(v46);
          v36 = v37 & 0xF0;
          if ( v37 == 21 )
            return -1;
          if ( v36 == 48 )
          {
            for ( j = 0; j < 6; ++j )
            {
              v15 = CWorldManager::NeighborRelIndex(j);
              v32 = v46 + v15;
              if ( CWorldManager::FlagBits(v46 + v15, 0x5Fu) )
                return -1;
            }
          }
          v31 = 1 << (v36 >> 4);
          if ( (v56 & v31) == 0 )
            return -1;
        }
      }
LABEL_71:
      if ( v60 == 3 )
      {
        v64 = 1;
      }
      else
      {
        v55 = 0;
        v45 = 0;
        CBuildingFlagsWalk::CBuildingFlagsWalk(a2, a3, *BuildingInfo, BuildingInfo[1], BuildingInfo + 736);
        while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v26) )
        {
          v25 = CBuildingFlagsWalk::CurrentY(v26);
          v16 = CBuildingFlagsWalk::CurrentX(v26);
          v30 = CWorldManager::Index(v16, v25);
          v29 = CWorldManager::GroundHeight(v30);
          ++v55;
          v45 += v29;
        }
        if ( v55 > 0 )
        {
          v28 = (v45 + (v55 >> 1)) / v55;
          v64 = CBuildingMgr::CheckForBuildCalc((CBuildingMgr *)v59, a2, a3, a4, v54, a5, v28);
        }
      }
      if ( v64 )
      {
        if ( a6 == 1 )
        {
          v57 = 0;
          if ( v60 != 3 )
          {
            while ( *((_BYTE *)v59 + 30750 * a4 + 1025 * v57 + 11981) && v57 != 30 )
              ++v57;
          }
          if ( v57 == 30 )
            return 0;
          v35 = CBuildingMgr::AddBuilding(v59, a2, a3, a4, a5, 1u);
          if ( !v35 )
            return 0;
          if ( v60 != 3 && v64 != 1 )
          {
            v17 = (_DWORD *)CBuildingMgr::operator[](v35);
            v53 = (CBuildingSiteRole *)CBuilding::Role(v17);
            CBuildingSiteRole::SetDiggingInfos(v53, v57, v64);
            v52 = (char *)v59 + 30750 * a4 + 1025 * v57 + 11981;
            *v52 = 1;
            for ( k = 0; k < 31; ++k )
            {
              v44 = a3 + k - 15;
              for ( m = 0; m < 31; ++m )
              {
                v43 = a2 + m - 15;
                v18 = CWorldManager::GroundHeight(v43, v44);
                if ( v18 == *((unsigned __int8 *)&v59[8 * m + 72182] + k + 3) )
                {
                  v52[32 * m + 1 + k] = 0;
                }
                else
                {
                  CWorldManager::SetFlagBits(v43, v44, 16);
                  v52[32 * m + 1 + k] = *((_BYTE *)&v59[8 * m + 72182] + k + 3);
                  if ( v52[32 * m + 1 + k] )
                  {
                    v19 = CWorldManager::GroundHeight(v43, v44);
                    v42 = v19 - (unsigned __int8)v52[32 * m + 1 + k];
                    if ( v42 <= 0 )
                      v20 = *((_DWORD *)v53 + 95) - v42;
                    else
                      v20 = v42 + *((_DWORD *)v53 + 95);
                    *((_DWORD *)v53 + 95) = v20;
                  }
                }
              }
            }
          }
        }
        if ( v64 && v64 < 0x28 )
        {
          v58 = 1;
        }
        else if ( v64 >= 0x5A )
        {
          if ( v64 >= 0x96 )
          {
            if ( v64 >= 0xDC )
            {
              if ( v64 >= 0x12C )
              {
                if ( v64 >= 0x186 )
                {
                  if ( v64 >= 0x1EA )
                    v58 = 8;
                  else
                    v58 = 7;
                }
                else
                {
                  v58 = 6;
                }
              }
              else
              {
                v58 = 5;
              }
            }
            else
            {
              v58 = 4;
            }
          }
          else
          {
            v58 = 3;
          }
        }
        else
        {
          v58 = 2;
        }
        result = v58;
      }
      else
      {
        result = 0;
      }
      break;
  }
  return result;
}


// address=[0x14f6050]
// Decompiled from int __thiscall CBuildingMgr::CheckForBuildInWater(CBuildingMgr *this, int a2, int a3, int a4, int a5)
int  CBuildingMgr::CheckForBuildInWater(int,int,int,int) {
  
  dword_40E3DD4 = 0;
  if ( a5 == 58 )
  {
    CBuildingMgr::CheckForBuildWater(this, a2, a3, a4, 31, 0);
  }
  else if ( a5 == 52 )
  {
    CBuildingMgr::CheckForBuildWater(this, a2, a3, a4, 32, 0);
  }
  return dword_40E3DD4;
}


// address=[0x14f60b0]
// Decompiled from BOOL __thiscall CBuildingMgr::CheckForBuildDarkTribe(CBuildingMgr *this, int a2, int a3, int a4, int a5, int a6)
int  CBuildingMgr::CheckForBuildDarkTribe(int,int,int,int,int) {
  
  int v6; // ecx
  int v7; // ecx
  _DWORD *v8; // eax
  _DWORD *v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  _BYTE v20[12]; // [esp+4h] [ebp-D0h] BYREF
  _BYTE v21[12]; // [esp+10h] [ebp-C4h] BYREF
  _BYTE v22[12]; // [esp+1Ch] [ebp-B8h] BYREF
  _BYTE v23[12]; // [esp+28h] [ebp-ACh] BYREF
  int v24; // [esp+34h] [ebp-A0h]
  int v25; // [esp+38h] [ebp-9Ch]
  int v26; // [esp+3Ch] [ebp-98h]
  signed int v28; // [esp+44h] [ebp-90h]
  std::_Iterator_base12 *v30; // [esp+4Ch] [ebp-88h]
  std::_Iterator_base12 *v31; // [esp+50h] [ebp-84h]
  int v32; // [esp+54h] [ebp-80h]
  int v33; // [esp+58h] [ebp-7Ch]
  int v34; // [esp+5Ch] [ebp-78h]
  int v35; // [esp+60h] [ebp-74h]
  int v36; // [esp+64h] [ebp-70h]
  std::_Iterator_base12 *v37; // [esp+68h] [ebp-6Ch]
  std::_Iterator_base12 *v38; // [esp+6Ch] [ebp-68h]
  int v39; // [esp+70h] [ebp-64h]
  int v40; // [esp+74h] [ebp-60h]
  int v41; // [esp+78h] [ebp-5Ch]
  int v42; // [esp+7Ch] [ebp-58h]
  _BYTE v43[12]; // [esp+80h] [ebp-54h] BYREF
  int *v44; // [esp+8Ch] [ebp-48h]
  unsigned int v45; // [esp+90h] [ebp-44h]
  int j; // [esp+94h] [ebp-40h]
  int v47; // [esp+98h] [ebp-3Ch]
  unsigned int v48; // [esp+9Ch] [ebp-38h]
  char *BuildingInfo; // [esp+A0h] [ebp-34h]
  int v50; // [esp+A4h] [ebp-30h]
  char v51; // [esp+AAh] [ebp-2Ah]
  char v52; // [esp+ABh] [ebp-29h]
  int i; // [esp+ACh] [ebp-28h]
  signed int v54; // [esp+B0h] [ebp-24h]
  int k; // [esp+B4h] [ebp-20h]
  int m; // [esp+B8h] [ebp-1Ch]
  int v57; // [esp+BCh] [ebp-18h]
  int v58; // [esp+C0h] [ebp-14h]
  char v59; // [esp+C7h] [ebp-Dh]
  int v60; // [esp+D0h] [ebp-4h]

  v44 = (int *)this;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 3286, "g_cWorld.InWorld(_iXPos, _iYPos)") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 3287, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  v6 = 0;
  if ( (a5 <= 0 || a5 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         3288,
         "_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  v24 = 0;
  v42 = a5;
  v25 = 95;
  v48 = 0;
  v45 = 0;
  if ( a2 < 15 || a2 > CWorldManager::Width(v6) - 16 || a3 < 15 || a3 > CWorldManager::Width(v7) - 16 )
    return 0;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v43);
  v60 = 0;
  BuildingInfo = (char *)CBuildingInfoMgr::GetBuildingInfo(3, v42);
  v40 = a2 + 32 - *BuildingInfo - 1;
  v41 = a3 - BuildingInfo[1] - 1;
  v50 = 0;
  v26 = std::vector<unsigned int>::begin(v23);
  v39 = v26;
  LOBYTE(v60) = 1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v26);
  LOBYTE(v60) = 0;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v23);
  while ( 1 )
  {
    v38 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(v22);
    v37 = v38;
    LOBYTE(v60) = 2;
    v52 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v38);
    LOBYTE(v60) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v22);
    if ( !v52 )
      break;
    ++v50;
    if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v43) )
    {
      k = v50 + v41;
      for ( i = 31; i >= 0; --i )
      {
        v8 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v43);
        if ( (*v8 & (1 << i)) != 0 )
        {
          m = v40 - i;
          if ( CWorldManager::FlagBits(v40 - i, k, 0x5Fu) != 4 )
          {
            v36 = i - 31;
            v60 = -1;
            std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v43);
            return v36;
          }
          v47 = CWorldManager::Ground(m, k);
          if ( v47 == 21 )
          {
            v35 = i - 31;
            v60 = -1;
            std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v43);
            return v35;
          }
          if ( (v47 & 0xF0) != 0x10 && (v47 & 0xF0) != 0x40 && (v47 & 0xF0) != 0x90 && v47 != 48 )
          {
            v34 = i - 31;
            v60 = -1;
            std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v43);
            return v34;
          }
        }
      }
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v43);
  }
  v50 = 0;
  v33 = std::vector<unsigned int>::begin(v21);
  v32 = v33;
  LOBYTE(v60) = 3;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v33);
  LOBYTE(v60) = 0;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v21);
  while ( 1 )
  {
    v31 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(v20);
    v30 = v31;
    LOBYTE(v60) = 4;
    v51 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v31);
    LOBYTE(v60) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v20);
    if ( !v51 )
      break;
    ++v50;
    if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v43) )
    {
      k = v50 + v41;
      for ( j = 31; j >= 0; --j )
      {
        v10 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v43);
        if ( (*v10 & (1 << j)) != 0 )
        {
          m = v40 - j;
          v11 = CWorldManager::GroundHeight(v40 - j, k);
          v48 += v11;
          ++v45;
        }
      }
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v43);
  }
  v60 = -1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v43);
  if ( v45 )
  {
    v48 = (v48 + (v45 >> 1)) / v45;
    if ( !CBuildingMgr::CheckForBuildCalc((CBuildingMgr *)v44, a2, a3, a4, a4, v42, v48) )
      return 0;
  }
  if ( a6 != 1 )
    return 1;
  v59 = 1;
  while ( v59 == 1 )
  {
    v59 = 0;
    for ( k = 0; k < 31; ++k )
    {
      v58 = a3 + k - 15;
      for ( m = 0; m < 31; ++m )
      {
        v57 = a2 + m - 15;
        v54 = CWorldManager::GroundHeight(v57, v58);
        v28 = v48;
        if ( *((_BYTE *)&v44[8 * m + 72182] + k + 3) && *((unsigned __int8 *)&v44[8 * m + 72182] + k + 3) != v54 )
        {
          if ( v54 <= v28 )
          {
            v16 = CWorldManager::GroundHeight(v57 - 1, v58 - 1);
            if ( v16 != v54 - 5 )
            {
              v17 = CWorldManager::GroundHeight(v57, v58 - 1);
              if ( v17 != v54 - 5 )
              {
                v18 = CWorldManager::GroundHeight(v57, v58 + 1);
                if ( v18 != v54 - 7 )
                {
                  v19 = CWorldManager::GroundHeight(v57 + 1, v58 + 1);
                  if ( v19 != v54 - 7 )
                  {
                    CWorldManager::IncreaseGroundHeight(v57, v58);
                    IGfxEngine::UpdateWorldPosition((IGfxEngine *)g_pGfxEngine, v57, v58);
                    v59 = 1;
                  }
                }
              }
            }
          }
          else
          {
            v12 = CWorldManager::GroundHeight(v57 - 1, v58 - 1);
            if ( v12 != v54 + 7 )
            {
              v13 = CWorldManager::GroundHeight(v57, v58 - 1);
              if ( v13 != v54 + 7 )
              {
                v14 = CWorldManager::GroundHeight(v57, v58 + 1);
                if ( v14 != v54 + 5 )
                {
                  v15 = CWorldManager::GroundHeight(v57 + 1, v58 + 1);
                  if ( v15 != v54 + 5 )
                  {
                    CWorldManager::DecreaseGroundHeight(v57, v58);
                    IGfxEngine::UpdateWorldPosition((IGfxEngine *)g_pGfxEngine, v57, v58);
                    v59 = 1;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return CBuildingMgr::AddBuilding(v44, a2, a3, a4, v42, 1u) != 0;
}


// address=[0x14f67f0]
// Decompiled from _DWORD *__thiscall CBuildingMgr::ShowWorkingArea(CBuildingMgr *this, int a2)
void  CBuildingMgr::ShowWorkingArea(int)const {
  
  int v2; // eax
  int v3; // eax
  _DWORD *result; // eax
  int v5; // [esp-4h] [ebp-4Ch]
  int v6; // [esp+4h] [ebp-44h]
  _DWORD *v7; // [esp+8h] [ebp-40h]
  int v8; // [esp+Ch] [ebp-3Ch]
  int v9; // [esp+10h] [ebp-38h]
  int v10; // [esp+14h] [ebp-34h]
  int v11; // [esp+1Ch] [ebp-2Ch]
  const char *v12; // [esp+20h] [ebp-28h]
  int WorkingAreaPackedXY; // [esp+24h] [ebp-24h]
  int v14; // [esp+28h] [ebp-20h]
  int v15; // [esp+2Ch] [ebp-1Ch]
  int v16; // [esp+30h] [ebp-18h]
  int v17; // [esp+34h] [ebp-14h]
  int v18; // [esp+38h] [ebp-10h]
  unsigned __int16 *v19; // [esp+3Ch] [ebp-Ch]
  int i; // [esp+40h] [ebp-8h]
  int j; // [esp+44h] [ebp-4h]

  v19 = (unsigned __int16 *)CBuildingMgr::operator[](a2);
  v2 = CBuilding::EnsignWorldIdx(v19);
  v6 = CWorldManager::EcoSectorId(v2);
  v5 = IEntity::Type(v19);
  v3 = IEntity::Race(v19);
  result = (_DWORD *)CBuildingInfoMgr::GetBuildingInfo(v3, v5);
  v17 = result[123];
  if ( v17 <= 0 )
    return result;
  WorkingAreaPackedXY = CBuilding::GetWorkingAreaPackedXY(v19);
  v8 = Y16X16::UnpackXFast(WorkingAreaPackedXY);
  result = (_DWORD *)Y16X16::UnpackYFast(WorkingAreaPackedXY);
  v7 = result;
  v11 = -1;
  if ( v17 <= 5 )
  {
    v16 = 3;
    v12 = "\n";
  }
  else
  {
    v16 = 4;
    result = &unk_377E808;
    v12 = (const char *)&unk_377E808;
  }
  for ( i = 0; i < v16; ++i )
  {
    v18 = v17 * (i + 1) / v16;
    if ( v18 > v11 )
    {
      v10 = CSpiralOffsets::First(v18);
      v9 = CSpiralOffsets::Last(v18);
      for ( j = v10; j <= v9; ++j )
      {
        v14 = v8 + CSpiralOffsets::DeltaX(j);
        v15 = (int)v7 + CSpiralOffsets::DeltaY(j);
        if ( (unsigned __int8)CWorldManager::InWorld(v14, v15) )
        {
          if ( CWorldManager::EcoSectorId(v14, v15) == v6 )
            CWorldManager::SetHelperObject(v14, v15, *(_DWORD *)&v12[4 * i]);
        }
      }
    }
    v11 = v17 * (i + 1) / v16;
    result = (_DWORD *)(i + 1);
  }
  return result;
}


// address=[0x14f69b0]
// Decompiled from char __thiscall CBuildingMgr::IsGoodWorkingAreaCenter(CBuildingMgr *this, int a2, int *a3, int *a4)
bool  CBuildingMgr::IsGoodWorkingAreaCenter(int,int &,int &)const {
  
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v8; // [esp-4h] [ebp-28h]
  int v9; // [esp+Ch] [ebp-18h]
  int v10; // [esp+10h] [ebp-14h]
  _DWORD *v11; // [esp+14h] [ebp-10h]
  int v12; // [esp+18h] [ebp-Ch]
  int v13; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]

  v11 = (_DWORD *)CBuildingMgr::operator[](a2);
  v10 = *a3;
  v9 = *a4;
  for ( i = 0; (int)CSpiralOffsets::Radius(i) < 5; ++i )
  {
    v13 = v10 + CSpiralOffsets::DeltaX(i);
    v12 = v9 + CSpiralOffsets::DeltaY(i);
    if ( (unsigned __int8)CWorldManager::InWorld(v13, v12) )
    {
      if ( CWorldManager::EcoSectorId(v13, v12) )
        break;
    }
  }
  v8 = v12 - IEntity::Y(v11);
  v4 = IEntity::X(v11);
  if ( (int)Grid::Distance((Grid *)(v13 - v4), v8) >= 60 )
    return 0;
  v5 = CBuilding::EnsignWorldIdx(v11);
  v6 = CWorldManager::EcoSectorId(v5);
  if ( v6 != CWorldManager::EcoSectorId(v13, v12) )
    return 0;
  *a3 = v13;
  *a4 = v12;
  return 1;
}


// address=[0x14f6ad0]
// Decompiled from _DWORD *__cdecl CBuildingMgr::FillBuildingAmount(void **a1, char a2, char a3)
static void __cdecl CBuildingMgr::FillBuildingAmount(class CInfoExchange *,bool,bool) {
  
  int v4; // [esp+8h] [ebp-5Ch]
  unsigned int v5; // [esp+Ch] [ebp-58h]
  int LocalPlayerEcoSectorIdAtCenter; // [esp+14h] [ebp-50h]
  int v7; // [esp+18h] [ebp-4Ch] BYREF
  int NumberOfBuildings; // [esp+1Ch] [ebp-48h] BYREF
  _BYTE *BuildingInfo; // [esp+20h] [ebp-44h]
  int v10; // [esp+24h] [ebp-40h]
  void **v11; // [esp+28h] [ebp-3Ch]
  int LocalPlayerId; // [esp+2Ch] [ebp-38h]
  int i; // [esp+30h] [ebp-34h]
  unsigned int v14; // [esp+34h] [ebp-30h]
  int v15; // [esp+38h] [ebp-2Ch]
  CEvn_Event v16; // [esp+3Ch] [ebp-28h] BYREF
  int v17; // [esp+60h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1581, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !j____RTDynamicCast(a1, 0, &CInfoExchange__RTTI_Type_Descriptor_, &SBuildingMenu__RTTI_Type_Descriptor_, 0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1582,
         "dynamic_cast<SBuildingMenu*>(_pInfoExchange) != 0") == 1 )
  {
    __debugbreak();
  }
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v4 = CPlayerManager::Race(LocalPlayerId);
  v11 = a1;
  *((_BYTE *)a1 + 9) = a3;
  if ( a3 )
    LocalPlayerEcoSectorIdAtCenter = CEcoSectorMgr::GetLocalPlayerEcoSectorIdAtCenter();
  else
    LocalPlayerEcoSectorIdAtCenter = -1;
  v10 = LocalPlayerEcoSectorIdAtCenter;
  for ( i = 0; i < 10; ++i )
  {
    v14 = (unsigned int)&v11[4 * i + 3];
    v15 = *(_DWORD *)v14;
    NumberOfBuildings = 0;
    v7 = 0;
    if ( v15 <= 0 || v15 >= 83 )
    {
      *(_BYTE *)(v14 + 12) = 0;
      *(_BYTE *)(v14 + 13) = 0;
      *(_BYTE *)(v14 + 14) = 0;
    }
    else
    {
      if ( v10 == -1 )
      {
        NumberOfBuildings = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, LocalPlayerId, v15, 0);
        v7 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, LocalPlayerId, v15, 1u);
      }
      else if ( v10 > 0 )
      {
        CBuildingMgr::CalculateNumberOfBuildingsInEcoSector(
          (CBuildingMgr *)g_cBuildingMgr,
          LocalPlayerId,
          v15,
          v10,
          &NumberOfBuildings,
          &v7);
      }
      if ( v15 == 31 )
      {
        v15 = 58;
      }
      else if ( v15 == 32 )
      {
        v15 = 52;
      }
      BuildingInfo = (_BYTE *)CBuildingInfoMgr::GetBuildingInfo(v4, v15);
      *(_BYTE *)(v14 + 12) = BuildingInfo[3];
      *(_BYTE *)(v14 + 13) = BuildingInfo[2];
      *(_BYTE *)(v14 + 14) = BuildingInfo[4];
    }
    *(_DWORD *)(v14 + 8) = NumberOfBuildings;
    *(_DWORD *)(v14 + 4) = v7;
  }
  v11[1] = (void *)28;
  if ( a2 )
    v5 = 604;
  else
    v5 = 602;
  CEvn_Event::CEvn_Event(&v16, v5, 0, (unsigned int)v11, 0);
  v17 = 0;
  if ( !g_pEvnEngine
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1659, "g_pEvnEngine != NULL") == 1 )
  {
    __debugbreak();
  }
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v16);
  v17 = -1;
  return CEvn_Event::~CEvn_Event(&v16);
}


// address=[0x14f6d90]
// Decompiled from void __cdecl CBuildingMgr::FillAddSoldierSideBar(struct CInfoExchange *a1, bool a2, int a3)
static void __cdecl CBuildingMgr::FillAddSoldierSideBar(class CInfoExchange *,bool,int) {
  
  CBarrackRole *v3; // [esp+0h] [ebp-Ch]
  _DWORD *v4; // [esp+8h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1680, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !a3 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1681, "_iEntityId != 0") == 1 )
    __debugbreak();
  v4 = (_DWORD *)CBuildingMgr::operator[](a3);
  v3 = (CBarrackRole *)CBuilding::Role(v4);
  CBarrackRole::FillAddSoldierSideBar(v3, a1, a2);
}


// address=[0x14f6e20]
// Decompiled from void __cdecl CBuildingMgr::FillToolSideBar(struct CInfoExchange *a1, bool a2, int a3)
static void __cdecl CBuildingMgr::FillToolSideBar(class CInfoExchange *,bool,int) {
  
  CProductionBuildingRole *v3; // [esp+0h] [ebp-Ch]
  _DWORD *v4; // [esp+8h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1704, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !a3 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1705, "_iEntityId != 0") == 1 )
    __debugbreak();
  v4 = (_DWORD *)CBuildingMgr::operator[](a3);
  v3 = (CProductionBuildingRole *)CBuilding::Role(v4);
  CProductionBuildingRole::FillToolSideBar(v3, a1, a2);
}


// address=[0x14f6eb0]
// Decompiled from int __cdecl CBuildingMgr::FillWeaponSideBar(int a1, char a2, int a3)
static void __cdecl CBuildingMgr::FillWeaponSideBar(class CInfoExchange *,bool,int) {
  
  _DWORD *v4; // [esp+8h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, (int)"MapObjects\\Building\\BuildingMgr.cpp", 1728, (int)"_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !a3 && BBSupportDbgReport(2, (int)"MapObjects\\Building\\BuildingMgr.cpp", 1729, (int)"_iEntityId != 0") == 1 )
    __debugbreak();
  v4 = (_DWORD *)CBuildingMgr::operator[](a3);
  CBuilding::Role(v4);
  return CProductionBuildingRole::FillWeaponSideBar(a1, a2);
}


// address=[0x14f6f40]
// Decompiled from void __cdecl CBuildingMgr::FillGoodsOutSideBar(struct CInfoExchange *a1, bool a2, int a3)
static void __cdecl CBuildingMgr::FillGoodsOutSideBar(class CInfoExchange *,bool,int) {
  
  CTradingBuildingRole *v3; // [esp+0h] [ebp-Ch]
  _DWORD *v4; // [esp+8h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1752, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !a3 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1753, "_iEntityId != 0") == 1 )
    __debugbreak();
  v4 = (_DWORD *)CBuildingMgr::operator[](a3);
  v3 = (CTradingBuildingRole *)CBuilding::Role(v4);
  CTradingBuildingRole::FillGoodsOutSideBar(v3, a1, a2);
}


// address=[0x14f6fd0]
// Decompiled from void __cdecl CBuildingMgr::FillTradeSideBar(struct CInfoExchange *a1, bool a2, int a3)
static void __cdecl CBuildingMgr::FillTradeSideBar(class CInfoExchange *,bool,int) {
  
  CTradingBuildingRole *v3; // [esp+0h] [ebp-Ch]
  _DWORD *v4; // [esp+8h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1776, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !a3 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1777, "_iEntityId != 0") == 1 )
    __debugbreak();
  v4 = (_DWORD *)CBuildingMgr::operator[](a3);
  v3 = (CTradingBuildingRole *)CBuilding::Role(v4);
  CTradingBuildingRole::FillTradeSideBar(v3, a1, a2);
}


// address=[0x14f7060]
// Decompiled from void __cdecl CBuildingMgr::FillStorageSideBar(struct CInfoExchange *a1, bool a2, int a3)
static void __cdecl CBuildingMgr::FillStorageSideBar(class CInfoExchange *,bool,int) {
  
  CStorageBuildingRole *v3; // [esp+0h] [ebp-Ch]
  _DWORD *v4; // [esp+8h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1800, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !a3 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1801, "_iEntityId != 0") == 1 )
    __debugbreak();
  v4 = (_DWORD *)CBuildingMgr::operator[](a3);
  v3 = (CStorageBuildingRole *)CBuilding::Role(v4);
  CStorageBuildingRole::FillStorageSideBar(v3, a1, a2);
}


// address=[0x14f70f0]
// Decompiled from _DWORD *__cdecl CBuildingMgr::FillEyeCatcherSideBar(struct CInfoExchange *a1, bool a2)
static void __cdecl CBuildingMgr::FillEyeCatcherSideBar(class CInfoExchange *,bool,int) {
  
  int LocalPlayerId; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  unsigned int v7; // [esp+4h] [ebp-3Ch]
  _BYTE *BuildingInfo; // [esp+8h] [ebp-38h]
  int v9; // [esp+Ch] [ebp-34h]
  int i; // [esp+14h] [ebp-2Ch]
  CEvn_Event v11; // [esp+18h] [ebp-28h] BYREF
  int v12; // [esp+3Ch] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1824, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  for ( i = 0; i < 12; ++i )
  {
    v9 = *((_DWORD *)a1 + 4 * i + 2);
    if ( v9 )
    {
      LocalPlayerId = CPlayerManager::GetLocalPlayerId();
      *((_DWORD *)a1 + 4 * i + 3) = CBuildingMgr::GetNumberOfBuildings(
                                      (CBuildingMgr *)g_cBuildingMgr,
                                      LocalPlayerId,
                                      v9,
                                      1u);
      v3 = CPlayerManager::GetLocalPlayerId();
      *((_DWORD *)a1 + 4 * i + 4) = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v9, 0);
      v4 = CPlayerManager::GetLocalPlayerId();
      v5 = CPlayerManager::Race(v4);
      BuildingInfo = (_BYTE *)CBuildingInfoMgr::GetBuildingInfo(v5, v9);
      *((_BYTE *)a1 + 16 * i + 20) = BuildingInfo[3];
      *((_BYTE *)a1 + 16 * i + 21) = BuildingInfo[2];
      *((_BYTE *)a1 + 16 * i + 22) = BuildingInfo[4];
    }
  }
  *((_DWORD *)a1 + 1) = 27;
  v7 = 606;
  if ( !a2 )
    v7 = 607;
  CEvn_Event::CEvn_Event(&v11, v7, 0, (unsigned int)a1, 0);
  v12 = 0;
  if ( !g_pEvnEngine
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1874, "g_pEvnEngine != NULL") == 1 )
  {
    __debugbreak();
  }
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v11);
  v12 = -1;
  return CEvn_Event::~CEvn_Event(&v11);
}


// address=[0x14f72c0]
// Decompiled from void __cdecl CBuildingMgr::FillAddVehicleSideBar(struct CInfoExchange *a1, bool a2, int a3)
static void __cdecl CBuildingMgr::FillAddVehicleSideBar(class CInfoExchange *,bool,int) {
  
  CWorkshopBuildingRole *v3; // [esp+4h] [ebp-8h]
  _DWORD *v4; // [esp+8h] [ebp-4h]

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1895, "_pInfoExchange != 0") == 1 )
    __debugbreak();
  if ( !a3 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1896, "_iEntityId != 0") == 1 )
    __debugbreak();
  v4 = (_DWORD *)CBuildingMgr::operator[](a3);
  v3 = (CWorkshopBuildingRole *)CBuilding::Role(v4);
  CWorkshopBuildingRole::FillAddVehicleSideBar(v3, (struct CAddVehicleBarInfo *)&g_cVehicleSideBarInfo, a2);
}


// address=[0x14f7350]
// Decompiled from void __thiscall CBuildingMgr::Store(CBuildingMgr *this, struct S4::CMapFile *a2)
void  CBuildingMgr::Store(class S4::CMapFile &) {
  
  std::strstreambuf *v2; // eax
  void *v3; // eax
  int v4; // [esp+0h] [ebp-124h] BYREF
  _DWORD v5[44]; // [esp+10h] [ebp-114h] BYREF
  _WORD *v6; // [esp+C0h] [ebp-64h]
  unsigned int v7; // [esp+C4h] [ebp-60h]
  size_t Size; // [esp+C8h] [ebp-5Ch]
  void *Src; // [esp+CCh] [ebp-58h]
  int v10; // [esp+D0h] [ebp-54h]
  int v11; // [esp+D4h] [ebp-50h]
  unsigned __int8 *v12; // [esp+D8h] [ebp-4Ch]
  int v13; // [esp+DCh] [ebp-48h]
  int v14; // [esp+E0h] [ebp-44h]
  unsigned __int8 *v15; // [esp+E4h] [ebp-40h]
  int UsedId; // [esp+E8h] [ebp-3Ch]
  int v17; // [esp+ECh] [ebp-38h] BYREF
  int v18; // [esp+F0h] [ebp-34h]
  int v19; // [esp+F4h] [ebp-30h] BYREF
  unsigned __int8 *v20; // [esp+F8h] [ebp-2Ch]
  unsigned __int8 *v21; // [esp+FCh] [ebp-28h]
  int k; // [esp+100h] [ebp-24h]
  void *v23; // [esp+104h] [ebp-20h]
  int *v24; // [esp+108h] [ebp-1Ch]
  int j; // [esp+10Ch] [ebp-18h]
  int i; // [esp+110h] [ebp-14h]
  int *v27; // [esp+114h] [ebp-10h]
  int v28; // [esp+120h] [ebp-4h]

  v27 = &v4;
  v24 = (int *)this;
  std::ostrstream::ostrstream(0, 0x40000, 0, 2, 1);
  v28 = 0;
  v7 = std::ios_base::exceptions((char *)v5 + *(_DWORD *)(v5[0] + 4));
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), 6);
  LOBYTE(v28) = 1;
  v17 = 2;
  operator^<unsigned int>((struct std::ostream *)v5, &v17);
  j = 0;
  k = 0;
  for ( i = 0; i < 9; ++i )
  {
    operator^<int>((int)v5, &v24[i + 72884]);
    operator^<int>((int)v5, &v24[i + 72875]);
    for ( j = 0; j < 20; ++j )
      operator^<int>((int)v5, &v24[20 * i + 72695 + j]);
  }
  operator^<int>((int)v5, v24 + 6);
  for ( i = 0; i < 9; ++i )
  {
    for ( j = 0; j < 83; ++j )
      operator^<unsigned int>((struct std::ostream *)v5, &v24[83 * i + 7 + j]);
  }
  for ( i = 0; i < 9; ++i )
  {
    for ( j = 0; j < 83; ++j )
    {
      for ( k = 0; k < 2; ++k )
        operator^<unsigned int>((struct std::ostream *)v5, &v24[166 * i + 754 + 2 * j + k]);
    }
  }
  for ( i = 0; i < 9; ++i )
  {
    for ( j = 0; j < 83; ++j )
      operator^<int>((int)v5, &v24[83 * i + 2248 + j]);
  }
  UsedId = CMapObjectMgr::LastUsedId();
  v18 = UsedId;
  v19 = 0;
  for ( i = 0; i <= v18; ++i )
  {
    v15 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(i);
    v20 = v15;
    if ( v15 )
    {
      v14 = IEntity::ObjType(v20);
      if ( v14 == 8 || (v13 = IEntity::ObjType(v20), v13 == 10) )
        ++v19;
    }
  }
  operator^<unsigned int>((struct std::ostream *)v5, &v19);
  for ( i = 0; i <= v18; ++i )
  {
    v12 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(i);
    v21 = v12;
    if ( v12 )
    {
      v11 = IEntity::ObjType(v21);
      if ( v11 == 8 || (v10 = IEntity::ObjType(v21), v10 == 10) )
        (*(void (__thiscall **)(unsigned __int8 *, _DWORD *))(*(_DWORD *)v21 + 4))(v21, v5);
    }
  }
  std::ostream::put(0);
  v28 = 0;
  std::ostrstream::freeze((std::ostrstream *)v5, 1);
  v2 = std::ostrstream::rdbuf((std::ostrstream *)v5);
  Size = std::strstreambuf::pcount(v2);
  std::ostrstream::str((CDaoIndexFieldInfo *)v5);
  Src = v3;
  S4::CMapFile::SaveChunk(162, 0, Size, v3, 0);
  std::ostrstream::freeze((std::ostrstream *)v5, 0);
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), v7);
  LOBYTE(v28) = 3;
  v6 = operator new(0x44112u);
  v5[43] = v6;
  v23 = v6;
  *v6 = 13379;
  *((_WORD *)v23 + 139400) = 20757;
  j__memcpy((char *)v23 + 2, (char *)v24 + 288731, 0x400u);
  j__memcpy((char *)v23 + 1026, (char *)v24 + 289755, 0x400u);
  j__memcpy((char *)v23 + 2050, (char *)v24 + 11981, 0x4390Eu);
  S4::CMapFile::SaveChunk(182, 0, 0x44112u, v23, 0);
  v5[42] = v23;
  operator delete(v23);
  v28 = -1;
  std::ostrstream::`vbase destructor'((std::ostrstream *)v5);
}


// address=[0x14f7890]
// Decompiled from void __thiscall CBuildingMgr::Load(CBuildingMgr *this, struct S4::CMapFile *a2)
void  CBuildingMgr::Load(class S4::CMapFile &) {
  
  int v2; // [esp+0h] [ebp-118h]
  _DWORD v3[42]; // [esp+4h] [ebp-114h] BYREF
  size_t v4; // [esp+ACh] [ebp-6Ch] BYREF
  unsigned int v5; // [esp+B0h] [ebp-68h]
  int v6; // [esp+B4h] [ebp-64h] BYREF
  int v7; // [esp+B8h] [ebp-60h] BYREF
  int pExceptionObject; // [esp+BCh] [ebp-5Ch] BYREF
  unsigned int v9; // [esp+C0h] [ebp-58h] BYREF
  int v10; // [esp+C4h] [ebp-54h]
  char *Str; // [esp+C8h] [ebp-50h]
  int v12; // [esp+CCh] [ebp-4Ch]
  int n; // [esp+D0h] [ebp-48h]
  int j; // [esp+D4h] [ebp-44h]
  _WORD *v15; // [esp+D8h] [ebp-40h]
  int i; // [esp+DCh] [ebp-3Ch]
  CBuildingMgr *v17; // [esp+E0h] [ebp-38h]
  int m; // [esp+E4h] [ebp-34h]
  int k; // [esp+E8h] [ebp-30h]
  _BYTE v20[28]; // [esp+ECh] [ebp-2Ch] BYREF
  int v21; // [esp+114h] [ebp-4h]

  v17 = this;
  CTrace::Print("BuildingMgr load");
  v7 = 0;
  Str = (char *)S4::CMapFile::LoadChunk(a2, 0xA2u, 0, &v7, 0);
  if ( Str )
  {
    std::string::string(v20, Str);
    v21 = 0;
    std::istringstream::istringstream(v20, 1, 1);
    LOBYTE(v21) = 1;
    v5 = std::ios_base::exceptions((char *)v3 + *(_DWORD *)(v3[0] + 4));
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), 6);
    operator^<unsigned int>(v3, &v6);
    v10 = v6;
    if ( v6 != 1 )
    {
      if ( v10 != 2 )
      {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBuildingMgr");
        pExceptionObject = 0;
        CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
        _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
      }
      j = 0;
      for ( i = 0; i < 9; ++i )
      {
        operator^<int>((int)v3, (int)v17 + 4 * i + 291536);
        operator^<int>((int)v3, (int)v17 + 4 * i + 291500);
        for ( j = 0; j < 20; ++j )
          operator^<int>((int)v3, (int)v17 + 80 * i + 4 * j + 290780);
      }
    }
    operator^<int>((int)v3, (int)v17 + 24);
    m = 0;
    n = 0;
    for ( k = 0; k < 9; ++k )
    {
      for ( m = 0; m < 83; ++m )
        operator^<unsigned int>(v3, (char *)v17 + 332 * k + 4 * m + 28);
    }
    for ( k = 0; k < 9; ++k )
    {
      for ( m = 0; m < 83; ++m )
      {
        for ( n = 0; n < 2; ++n )
          operator^<unsigned int>(v3, (char *)v17 + 664 * k + 8 * m + 4 * n + 3016);
      }
    }
    for ( k = 0; k < 9; ++k )
    {
      for ( m = 0; m < 83; ++m )
        operator^<int>((int)v3, (int)v17 + 332 * k + 4 * m + 8992);
    }
    v9 = 0;
    operator^<unsigned int>(v3, &v9);
    for ( k = 0; k < v9; ++k )
    {
      v12 = CPersistence::New(v3, v2);
      if ( !v12 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 377, "pNewBulding != NULL") == 1 )
        __debugbreak();
      if ( v12 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v12 + 12))(v12);
    }
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), v5);
    v4 = 0;
    v15 = S4::CMapFile::LoadChunk(a2, 0xB6u, 0, &v7, &v4);
    if ( !v15 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 404, "pDiggertab != NULL") == 1 )
      __debugbreak();
    if ( *v15 != 13379
      && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 405, "pDiggertab->iFirstSignatute == 0x3443") == 1 )
    {
      __debugbreak();
    }
    if ( v15[139400] != 20757
      && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 406, "pDiggertab->iLastSignature == 0x5115") == 1 )
    {
      __debugbreak();
    }
    j__memcpy((char *)v17 + 288731, v15 + 1, 0x400u);
    j__memcpy((char *)v17 + 289755, v15 + 513, 0x400u);
    j__memcpy((char *)v17 + 11981, v15 + 1025, 0x4390Eu);
    S4::CMapFile::CloseChunk(a2, 0xB6u, 0);
    LOBYTE(v21) = 0;
    std::istringstream::`vbase destructor'(v3);
    v21 = -1;
    std::string::~string(v20);
  }
}


// address=[0x14f7d90]
// Decompiled from void __thiscall CBuildingMgr::ChangeOwnerIdOfBuilding(CBuildingMgr *this, int a2, int a3)
void  CBuildingMgr::ChangeOwnerIdOfBuilding(int,int) {
  
  int v3; // [esp+0h] [ebp-10h]
  IEntity *BuildingPtr; // [esp+8h] [ebp-8h]
  int v6; // [esp+Ch] [ebp-4h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 3565, "_iBuildingId > 0") == 1 )
    __debugbreak();
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 3566, "_iNewOwnerId > 0") == 1 )
    __debugbreak();
  BuildingPtr = (IEntity *)CBuildingMgr::GetBuildingPtr(this, a2);
  if ( !BuildingPtr && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 3570, "pBuilding != 0") == 1 )
    __debugbreak();
  if ( !IEntity::FlagBits(BuildingPtr, (EntityFlag)((char *)&loc_1FFFFFF + 1))
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         3571,
         "pBuilding->FlagBits(ENTITY_FLAG_READY) != 0") == 1 )
  {
    __debugbreak();
  }
  v3 = IEntity::OwnerId((unsigned __int8 *)BuildingPtr);
  v6 = IEntity::Type((unsigned __int16 *)BuildingPtr);
  if ( v3 != a3 )
  {
    CBuildingMgr::ChangeNumberOfBuildings(this, v3, v6, 1, -1);
    CBuildingMgr::DetachBuilding(this, v3, v6, a2);
    CStatistic::DecBuilding((CStatistic *)&g_cStatistic, v3, v6, 1);
    IEntity::SetOwnerId(BuildingPtr, a3);
    CBuildingMgr::AttachBuilding(this, a3, v6, a2);
    CBuildingMgr::ChangeNumberOfBuildings(this, a3, v6, 1, 1);
    CStatistic::AddBuilding((CStatistic *)&g_cStatistic, a3, v6, 1);
  }
}


// address=[0x14f7f00]
// Decompiled from unsigned __int8 *__thiscall CBuildingMgr::CalculateNumberOfBuildingsInEcoSector(  CBuildingMgr *this,  int a2,  int a3,  int a4,  int *a5,  int *a6)
void  CBuildingMgr::CalculateNumberOfBuildingsInEcoSector(int,int,int,int &,int &) {
  
  unsigned __int8 *result; // eax
  int v7; // eax
  int v8; // [esp+4h] [ebp-10h]
  int v10; // [esp+Ch] [ebp-8h]
  unsigned __int8 *v11; // [esp+10h] [ebp-4h]

  if ( (a2 < 1 || a2 > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         3598,
         "_iPlayerId >= PLAYER_FIRST && _iPlayerId <= PLAYER_LAST") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         3599,
         "_iBuildingType > BUILDING_NO_BUILDING && _iBuildingType < BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  result = (unsigned __int8 *)CBuildingMgr::GetFirstBuildingId(this, a2, a3);
  v10 = (int)result;
  *a5 = 0;
  *a6 = 0;
  while ( v10 )
  {
    result = CBuildingMgr::GetBuildingPtr(this, v10);
    v11 = result;
    if ( result )
    {
      if ( IEntity::FlagBits(result, (EntityFlag)&loc_3000000) )
      {
        v7 = CBuilding::EnsignPackedXY(v11);
        v8 = CWorldManager::Index(v7);
        if ( ITiling::EcoSectorId(v8) == a4 )
        {
          if ( IEntity::FlagBits(v11, (EntityFlag)((char *)&loc_1FFFFFF + 1)) )
            ++*a6;
          else
            ++*a5;
        }
      }
      result = (unsigned __int8 *)IAnimatedEntity::Next(v11);
      v10 = (int)result;
    }
    else
    {
      v10 = 0;
    }
  }
  return result;
}


// address=[0x14fab40]
// Decompiled from int __thiscall CBuildingMgr::GetValidManakopterHallPosition(CBuildingMgr *this, int a2)
int  CBuildingMgr::GetValidManakopterHallPosition(int) {
  
  int i; // [esp+0h] [ebp-8h]

  for ( i = 0; i < *((_DWORD *)this + a2 + 72875); ++i )
  {
    if ( CBuildingMgr::IsValidManakopterHallPosition(this, *((_DWORD *)this + 20 * a2 + i + 72695), a2) )
    {
      CBuildingMgr::IsValidManakopterHallPosition(this, *((_DWORD *)this + 20 * a2 + i + 72695), a2);
      return *((_DWORD *)this + 20 * a2 + i + 72695);
    }
  }
  return 0;
}


// address=[0x14fabe0]
// Decompiled from char __thiscall CBuildingMgr::IsPositionNearMKHPosition(CBuildingMgr *this, int a2, int a3)
bool  CBuildingMgr::IsPositionNearMKHPosition(int,int) {
  
  Grid *v4; // [esp+0h] [ebp-18h]
  int v5; // [esp+4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-10h]
  int v7; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  if ( !*((_DWORD *)this + a3 + 72875) )
    return 0;
  v4 = (Grid *)Y16X16::UnpackXFast(a2);
  v5 = Y16X16::UnpackYFast(a2);
  for ( i = 0; i < *((_DWORD *)this + a3 + 72875); ++i )
  {
    v6 = Y16X16::UnpackXFast(*((_DWORD *)this + 20 * a3 + i + 72695));
    v7 = Y16X16::UnpackYFast(*((_DWORD *)this + 20 * a3 + i + 72695));
    if ( (int)Grid::Distance(v4, v5, v6, v7, v4) < 25 )
      return 1;
  }
  return 0;
}


// address=[0x15139f0]
// Decompiled from char __thiscall CBuildingMgr::InLoadBuildingData(CBuildingMgr *this)
bool  CBuildingMgr::InLoadBuildingData(void)const {
  
  return *((_BYTE *)this + 11980);
}


// address=[0x151fa20]
// Decompiled from int __thiscall CBuildingMgr::EcoSectorId(CBuildingMgr *this, int a2)
int  CBuildingMgr::EcoSectorId(int)const {
  
  unsigned __int8 *BuildingPtr; // eax

  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, a2);
  return CBuilding::EcoSectorId(BuildingPtr);
}


// address=[0x14eb280]
// Decompiled from unsigned int __thiscall CBuildingMgr::Alloc(unsigned int *this, unsigned int a2)
void *  CBuildingMgr::Alloc(unsigned int) {
  
  return MemoryAllocator::allocate(this, a2);
}


// address=[0x14eb3c0]
// Decompiled from void __thiscall CBuildingMgr::Dealloc(CBuildingMgr *this, void *a2)
void  CBuildingMgr::Dealloc(void *) {
  
  MemoryAllocator::deallocate(this, a2);
}


// address=[0x14f8030]
// Decompiled from int __thiscall CBuildingMgr::CheckForBuildWater(CBuildingMgr *this, int a2, int a3, int a4, int a5, int a6)
int  CBuildingMgr::CheckForBuildWater(int,int,int,int,int) {
  
  int v7; // ecx
  int v8; // ecx
  int v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // [esp-8h] [ebp-134h]
  int v18; // [esp-4h] [ebp-130h]
  int v19; // [esp-4h] [ebp-130h]
  int v20; // [esp-4h] [ebp-130h]
  int v21; // [esp-4h] [ebp-130h]
  int v22; // [esp-4h] [ebp-130h]
  _DWORD v23[7]; // [esp+4h] [ebp-128h] BYREF
  _DWORD v24[7]; // [esp+20h] [ebp-10Ch] BYREF
  _DWORD v25[7]; // [esp+3Ch] [ebp-F0h] BYREF
  _DWORD v26[10]; // [esp+58h] [ebp-D4h] BYREF
  CBuildingMgr *v27; // [esp+80h] [ebp-ACh]
  int v28; // [esp+84h] [ebp-A8h]
  int v29; // [esp+88h] [ebp-A4h]
  int v30; // [esp+8Ch] [ebp-A0h]
  int v31; // [esp+90h] [ebp-9Ch]
  int v32; // [esp+94h] [ebp-98h]
  int v33; // [esp+98h] [ebp-94h]
  unsigned int v34; // [esp+9Ch] [ebp-90h]
  int v35; // [esp+A0h] [ebp-8Ch]
  unsigned int v36; // [esp+A4h] [ebp-88h]
  int v37; // [esp+A8h] [ebp-84h]
  int v38; // [esp+ACh] [ebp-80h]
  int v39; // [esp+B0h] [ebp-7Ch]
  int v40; // [esp+B4h] [ebp-78h]
  int v41; // [esp+B8h] [ebp-74h]
  int v42; // [esp+BCh] [ebp-70h]
  int v43; // [esp+C0h] [ebp-6Ch]
  int v44; // [esp+C4h] [ebp-68h]
  unsigned int v45; // [esp+C8h] [ebp-64h]
  __int64 v46; // [esp+CCh] [ebp-60h]
  int v47; // [esp+D4h] [ebp-58h]
  int v48; // [esp+D8h] [ebp-54h]
  int v49; // [esp+DCh] [ebp-50h]
  int v50; // [esp+E0h] [ebp-4Ch]
  int v51; // [esp+E4h] [ebp-48h]
  int m; // [esp+E8h] [ebp-44h]
  int v53; // [esp+ECh] [ebp-40h]
  int v54; // [esp+F0h] [ebp-3Ch]
  int v55; // [esp+F4h] [ebp-38h]
  int v56; // [esp+F8h] [ebp-34h]
  int v57; // [esp+FCh] [ebp-30h]
  int k; // [esp+100h] [ebp-2Ch]
  int v59; // [esp+104h] [ebp-28h]
  int i; // [esp+108h] [ebp-24h]
  const char *v61; // [esp+10Ch] [ebp-20h]
  int v62; // [esp+110h] [ebp-1Ch]
  int j; // [esp+114h] [ebp-18h]
  int v64; // [esp+118h] [ebp-14h]
  int v65; // [esp+11Ch] [ebp-10h]
  char v66; // [esp+122h] [ebp-Ah]
  char v67; // [esp+123h] [ebp-9h]
  char *BuildingInfo; // [esp+124h] [ebp-8h]
  char v69; // [esp+12Bh] [ebp-1h]

  v27 = this;
  v59 = CWorldManager::Index(a2, a3);
  v26[9] = 95;
  if ( CWorldManager::FlagBits(v59, 0x5Fu) || ITiling::OwnerId(v59) != a4 )
    return -1;
  v51 = CWorldManager::Ground(v59) & 0xF0;
  if ( v51 == 48 )
  {
    for ( i = 0; i < 6; ++i )
    {
      v40 = v59 + CWorldManager::NeighborRelIndex(i);
      if ( CWorldManager::FlagBits(v40, 0x5Fu) )
        return -1;
    }
  }
  else if ( v51 != 16 )
  {
    return -1;
  }
  v61 = 0;
  if ( a5 == 31 )
  {
    v61 = ":";
  }
  else
  {
    if ( a5 != 32 )
      return -1;
    v7 = 4;
    v61 = "4";
  }
  if ( !v61 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 3731, "pCheckBuildingTypes != 0") == 1 )
    __debugbreak();
  v49 = CWorldManager::Width(v7) - 1;
  v9 = CWorldManager::Width(v8);
  if ( v9 != CWorldManager::Height()
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 3737, "g_cWorld.Width() == g_cWorld.Height()") == 1 )
  {
    __debugbreak();
  }
  v26[8] = 0;
  v38 = CPlayerManager::Race(a4);
  v65 = -1;
  v53 = 0;
  v57 = 0;
  v50 = 7;
  if ( a6 >= 10 )
  {
    v57 = a6 - 10;
    v50 = a6 - 10;
    if ( a6 - 10 >= 8
      && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 3754, "iFirstIdx < WATER_BUILDING_TYPES_MAX") == 1 )
    {
      __debugbreak();
    }
  }
  for ( j = v57; j <= v50; ++j )
  {
    v39 = *(_DWORD *)&v61[4 * j];
    BuildingInfo = (char *)CBuildingInfoMgr::GetBuildingInfo(v38, v39);
    if ( a2 + BuildingInfo[52] > 0
      && a2 + BuildingInfo[53] < v49
      && a3 + BuildingInfo[54] > 0
      && a3 + BuildingInfo[55] < v49 )
    {
      v47 = a2 + BuildingInfo[42];
      v48 = a3 + BuildingInfo[43];
      if ( !(unsigned __int8)CWorldManager::InWorld(v47, v48)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\BuildingMgr.cpp",
             3777,
             "g_cWorld.InWorld(iWorkPosX, iWorkPosY)") == 1 )
      {
        __debugbreak();
      }
      v37 = CWorldManager::Index(v47, v48);
      if ( !CWaterFlags::IsBlockedWater(v37) )
      {
        v10 = std::vector<unsigned int>::operator[](0);
        v11 = std::vector<unsigned int>::size(BuildingInfo + 720, v10, 95);
        if ( (*(unsigned __int8 (__thiscall **)(void *, int, int, int, int, int))(*(_DWORD *)g_pTiling + 64))(
               g_pTiling,
               a2 - *BuildingInfo,
               a3 - BuildingInfo[1],
               v11,
               v17,
               v18) )
        {
          v64 = 0;
          CBuildingFlagsWalk::CBuildingFlagsWalk(a2, a3, *BuildingInfo, BuildingInfo[1], BuildingInfo + 784);
          while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v26) )
          {
            v19 = CBuildingFlagsWalk::CurrentY(v26);
            v12 = CBuildingFlagsWalk::CurrentX(v26);
            v56 = CWorldManager::Index(v12, v19);
            LOBYTE(v55) = CWorldManager::Ground(v56) & 0xF0;
            v55 = (unsigned __int8)v55;
            v45 = CWorldManager::Flags(v56);
            if ( v55 )
            {
              HIDWORD(v46) = v55 == 48;
              LODWORD(v46) = v55 == 16;
              if ( !v46 || (v45 & 0x5F) != 0 )
              {
LABEL_50:
                v64 = -1;
                break;
              }
            }
            else
            {
              if ( (v45 & 8) != 0 || (CWaterFlags::WaterFlags(v56) & 0x200) != 0 )
                goto LABEL_50;
              ++v64;
            }
          }
          if ( v64 > v53 )
          {
            v67 = 1;
            CBuildingFlagsWalk::CBuildingFlagsWalk(a2, a3, *BuildingInfo, BuildingInfo[1], BuildingInfo + 800);
            while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v25) )
            {
              v20 = CBuildingFlagsWalk::CurrentY(v25);
              v13 = CBuildingFlagsWalk::CurrentX(v25);
              v44 = CWorldManager::Index(v13, v20);
              v36 = CWorldManager::Flags(v44);
              v35 = CWaterFlags::WaterFlags(v44);
              if ( (v36 & 8) != 0 || (v35 & 0xC200) != 0xC000 )
              {
                v67 = 0;
                break;
              }
            }
            if ( v67 )
            {
              v66 = 1;
              CBuildingFlagsWalk::CBuildingFlagsWalk(a2, a3, *BuildingInfo, BuildingInfo[1], BuildingInfo + 832);
              while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v24) )
              {
                v21 = CBuildingFlagsWalk::CurrentY(v24);
                v14 = CBuildingFlagsWalk::CurrentX(v24);
                v43 = CWorldManager::Index(v14, v21);
                v34 = CWorldManager::Flags(v43);
                v33 = CWaterFlags::WaterFlags(v43);
                if ( (v34 & 8) != 0 || !CWaterFlags::WaterFlagsIsFreeWater(v33) )
                {
                  v66 = 0;
                  break;
                }
              }
              if ( v66 )
              {
                v69 = 1;
                CBuildingFlagsWalk::CBuildingFlagsWalk(a2, a3, *BuildingInfo, BuildingInfo[1], BuildingInfo + 720);
                while ( (unsigned __int8)CBuildingFlagsWalk::NextPosition(v23) )
                {
                  v22 = CBuildingFlagsWalk::CurrentY(v23);
                  v15 = CBuildingFlagsWalk::CurrentX(v23);
                  v54 = CWorldManager::Index(v15, v22);
                  v32 = CWorldManager::OwnerId(v54);
                  if ( v32 != a4 )
                  {
                    v69 = 0;
                    break;
                  }
                  LOBYTE(v42) = CWorldManager::Ground(v54) & 0xF0;
                  v42 = (unsigned __int8)v42;
                  if ( (unsigned __int8)v42 != 16 )
                  {
                    if ( v42 != 48 )
                    {
                      v69 = 0;
                      break;
                    }
                    for ( k = 0; k < 6; ++k )
                    {
                      v16 = CWorldManager::NeighborRelIndex(k);
                      v31 = v54 + v16;
                      if ( CWorldManager::FlagBits(v54 + v16, 0x5Fu) )
                      {
                        v69 = 0;
                        break;
                      }
                    }
                    if ( !v69 )
                      break;
                  }
                }
                if ( v69 )
                {
                  if ( v64 > v53 )
                  {
                    v53 = v64;
                    v65 = j;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v65 >= 0 )
  {
    if ( g_bDbgDisableAdditionalWaterBuildingCheck )
      a6 = 100;
    if ( a6 < 10 )
    {
      v30 = v65 + 10;
      v62 = dword_377F53C[v65];
      v26[7] = 2;
      for ( m = 0; m < 2; ++m )
      {
        v28 = g_sNeighborPoints[2 * v62] + a2;
        v29 = dword_37D8C0C[2 * v62] + a3;
        if ( (int)CBuildingMgr::CheckForBuildWater(v27, v28, v29, a4, a5, v30) > 0 )
        {
          v65 = -1;
          break;
        }
        if ( v62 < 5 )
          v41 = v62 + 1;
        else
          v41 = 0;
        v62 = v41;
      }
    }
  }
  if ( v65 < 0 )
  {
    dword_40E3DD4 = 0;
    return -1;
  }
  else
  {
    dword_40E3DD4 = *(_DWORD *)&v61[4 * v65];
    return 1;
  }
}


// address=[0x14f8850]
// Decompiled from CBuildingSiteRole *__cdecl CBuildingMgr::CreateBuildingRole(int a1, int a2, bool a3)
static class IBuildingRole * __cdecl CBuildingMgr::CreateBuildingRole(int,int,bool) {
  
  CBuildingSiteRole *result; // eax
  const char *v4; // [esp+64h] [ebp-C8h]
  const char *BuildingName; // [esp+68h] [ebp-C4h]
  CManakopterHallRole *v6; // [esp+6Ch] [ebp-C0h]
  CManakopterHallRole *v7; // [esp+70h] [ebp-BCh]
  CDarkMushroomFarmRole *v8; // [esp+74h] [ebp-B8h]
  CDarkMushroomFarmRole *v9; // [esp+78h] [ebp-B4h]
  CEyeCatcherRole *v10; // [esp+7Ch] [ebp-B0h]
  CEyeCatcherRole *v11; // [esp+80h] [ebp-ACh]
  CDarkTempleRole *v12; // [esp+84h] [ebp-A8h]
  CDarkTempleRole *v13; // [esp+88h] [ebp-A4h]
  CBigTempleRole *v14; // [esp+8Ch] [ebp-A0h]
  CBigTempleRole *v15; // [esp+90h] [ebp-9Ch]
  CSmallTempleRole *v16; // [esp+94h] [ebp-98h]
  CSmallTempleRole *v17; // [esp+98h] [ebp-94h]
  CCastleRole *v18; // [esp+9Ch] [ebp-90h]
  CCastleRole *v19; // [esp+A0h] [ebp-8Ch]
  CResidenceBuildingRole *v20; // [esp+A4h] [ebp-88h]
  CResidenceBuildingRole *v21; // [esp+A8h] [ebp-84h]
  CTradingBuildingRole *v22; // [esp+ACh] [ebp-80h]
  CTradingBuildingRole *v23; // [esp+B0h] [ebp-7Ch]
  CStorageBuildingRole *v24; // [esp+B4h] [ebp-78h]
  CStorageBuildingRole *v25; // [esp+B8h] [ebp-74h]
  CBarrackRole *v26; // [esp+BCh] [ebp-70h]
  CBarrackRole *v27; // [esp+C0h] [ebp-6Ch]
  CMilitaryBuildingRole *v28; // [esp+C4h] [ebp-68h]
  CMilitaryBuildingRole *v29; // [esp+C8h] [ebp-64h]
  CLookoutTowerRole *v30; // [esp+CCh] [ebp-60h]
  CLookoutTowerRole *v31; // [esp+D0h] [ebp-5Ch]
  CFarmBuildingRole *v32; // [esp+D4h] [ebp-58h]
  CFarmBuildingRole *v33; // [esp+D8h] [ebp-54h]
  CMineRole *v34; // [esp+DCh] [ebp-50h]
  CMineRole *v35; // [esp+E0h] [ebp-4Ch]
  CGatherBuildingRole *v36; // [esp+E4h] [ebp-48h]
  CGatherBuildingRole *v37; // [esp+E8h] [ebp-44h]
  CWorkshopBuildingRole *v38; // [esp+ECh] [ebp-40h]
  CWorkshopBuildingRole *v39; // [esp+F0h] [ebp-3Ch]
  CProductionBuildingRole *v40; // [esp+F4h] [ebp-38h]
  CProductionBuildingRole *v41; // [esp+F8h] [ebp-34h]
  CAnimalRanchRole *v42; // [esp+FCh] [ebp-30h]
  CAnimalRanchRole *v43; // [esp+100h] [ebp-2Ch]
  CWorkUpBuildingRole *v44; // [esp+104h] [ebp-28h]
  CWorkUpBuildingRole *v45; // [esp+108h] [ebp-24h]
  CSimpleBuildingRole *v46; // [esp+10Ch] [ebp-20h]
  CSimpleBuildingRole *v47; // [esp+110h] [ebp-1Ch]
  CBuildingSiteRole *C; // [esp+118h] [ebp-14h]

  if ( (a1 <= 0 || a1 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         665,
         "_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a3 )
  {
    C = (CBuildingSiteRole *)operator new(0x1C8u);
    if ( C )
      return CBuildingSiteRole::CBuildingSiteRole(C);
    else
      return 0;
  }
  else
  {
    switch ( *(_BYTE *)(CBuildingInfoMgr::GetBuildingInfo(a2, a1) + 477) )
    {
      case 1:
        v47 = (CSimpleBuildingRole *)operator new(0x180u);
        if ( v47 )
          v46 = CSimpleBuildingRole::CSimpleBuildingRole(v47);
        else
          v46 = 0;
        result = v46;
        break;
      case 2:
        v45 = (CWorkUpBuildingRole *)operator new(0x190u);
        if ( v45 )
          v44 = CWorkUpBuildingRole::CWorkUpBuildingRole(v45);
        else
          v44 = 0;
        result = v44;
        break;
      case 3:
        v43 = (CAnimalRanchRole *)operator new(0x194u);
        if ( v43 )
          v42 = CAnimalRanchRole::CAnimalRanchRole(v43);
        else
          v42 = 0;
        result = v42;
        break;
      case 4:
        v41 = (CProductionBuildingRole *)operator new(0x1B0u);
        if ( v41 )
          v40 = CProductionBuildingRole::CProductionBuildingRole(v41);
        else
          v40 = 0;
        result = v40;
        break;
      case 5:
        v39 = (CWorkshopBuildingRole *)operator new(0x19Cu);
        if ( v39 )
          v38 = CWorkshopBuildingRole::CWorkshopBuildingRole(v39);
        else
          v38 = 0;
        result = v38;
        break;
      case 6:
        v37 = (CGatherBuildingRole *)operator new(0x180u);
        if ( v37 )
          v36 = CGatherBuildingRole::CGatherBuildingRole(v37);
        else
          v36 = 0;
        result = v36;
        break;
      case 7:
        v35 = (CMineRole *)operator new(0x1BCu);
        if ( v35 )
          v34 = CMineRole::CMineRole(v35);
        else
          v34 = 0;
        result = v34;
        break;
      case 8:
        v33 = (CFarmBuildingRole *)operator new(0x180u);
        if ( v33 )
          v32 = CFarmBuildingRole::CFarmBuildingRole(v33);
        else
          v32 = 0;
        result = v32;
        break;
      case 9:
        v31 = (CLookoutTowerRole *)operator new(0x180u);
        if ( v31 )
          v30 = CLookoutTowerRole::CLookoutTowerRole(v31);
        else
          v30 = 0;
        result = v30;
        break;
      case 0xA:
        v29 = (CMilitaryBuildingRole *)operator new(0x1B8u);
        if ( v29 )
          v28 = CMilitaryBuildingRole::CMilitaryBuildingRole(v29);
        else
          v28 = 0;
        result = v28;
        break;
      case 0xB:
        v27 = (CBarrackRole *)operator new(0x190u);
        if ( v27 )
          v26 = CBarrackRole::CBarrackRole(v27);
        else
          v26 = 0;
        result = v26;
        break;
      case 0xC:
        v25 = (CStorageBuildingRole *)operator new(0x1BCu);
        if ( v25 )
          v24 = CStorageBuildingRole::CStorageBuildingRole(v25);
        else
          v24 = 0;
        result = v24;
        break;
      case 0xD:
        v23 = (CTradingBuildingRole *)operator new(0x2B4u);
        if ( v23 )
          v22 = CTradingBuildingRole::CTradingBuildingRole(v23);
        else
          v22 = 0;
        result = v22;
        break;
      case 0xE:
        v21 = (CResidenceBuildingRole *)operator new(0x180u);
        if ( v21 )
          v20 = CResidenceBuildingRole::CResidenceBuildingRole(v21);
        else
          v20 = 0;
        result = v20;
        break;
      case 0xF:
        v19 = (CCastleRole *)operator new(0x1C0u);
        if ( v19 )
          v18 = CCastleRole::CCastleRole(v19);
        else
          v18 = 0;
        result = v18;
        break;
      case 0x10:
        v17 = (CSmallTempleRole *)operator new(0x184u);
        if ( v17 )
          v16 = CSmallTempleRole::CSmallTempleRole(v17);
        else
          v16 = 0;
        result = v16;
        break;
      case 0x11:
        v15 = (CBigTempleRole *)operator new(0x180u);
        if ( v15 )
          v14 = CBigTempleRole::CBigTempleRole(v15);
        else
          v14 = 0;
        result = v14;
        break;
      case 0x12:
        v13 = (CDarkTempleRole *)operator new(0x1B4u);
        if ( v13 )
          v12 = CDarkTempleRole::CDarkTempleRole(v13);
        else
          v12 = 0;
        result = v12;
        break;
      case 0x13:
        v11 = (CEyeCatcherRole *)operator new(0x17Cu);
        if ( v11 )
          v10 = CEyeCatcherRole::CEyeCatcherRole(v11);
        else
          v10 = 0;
        result = v10;
        break;
      case 0x14:
        v9 = (CDarkMushroomFarmRole *)operator new(0x19Cu);
        if ( v9 )
          v8 = CDarkMushroomFarmRole::CDarkMushroomFarmRole(v9);
        else
          v8 = 0;
        result = v8;
        break;
      case 0x15:
        v7 = (CManakopterHallRole *)operator new(0x198u);
        if ( v7 )
          v6 = CManakopterHallRole::CManakopterHallRole(v7);
        else
          v6 = 0;
        result = v6;
        break;
      default:
        BuildingName = CS4DefineNames::GetBuildingName(a1);
        if ( BuildingName )
          v4 = BuildingName;
        else
          v4 = "Unknown";
        BBSupportTracePrintF(3, "Building %i (%s) of race %i has no building role!", a1, v4, a2);
        if ( BBSupportDbgReportF(
               1,
               "MapObjects\\Building\\BuildingMgr.cpp",
               812,
               "Rainer: No building role for building %i (%s) of race %i!",
               a1,
               v4,
               a2) == 1 )
          __debugbreak();
        result = 0;
        break;
    }
  }
  return result;
}


// address=[0x14f9170]
// Decompiled from int __cdecl CBuildingMgr::LoadBuildingRole(int a1, int a2)
static class IBuildingRole * __cdecl CBuildingMgr::LoadBuildingRole(std::istream &,int) {
  
  int result; // eax
  _DWORD pExceptionObject[2]; // [esp+0h] [ebp-8h] BYREF

  pExceptionObject[1] = a2;
  switch ( a2 )
  {
    case 0:
      result = CBuildingSiteRole::Load(a1);
      break;
    case 1:
      result = CSimpleBuildingRole::Load(a1);
      break;
    case 2:
      result = CWorkUpBuildingRole::Load(a1);
      break;
    case 3:
      result = CAnimalRanchRole::Load(a1);
      break;
    case 4:
      result = CProductionBuildingRole::Load(a1);
      break;
    case 5:
      result = CWorkshopBuildingRole::Load(a1);
      break;
    case 6:
      result = CGatherBuildingRole::Load(a1);
      break;
    case 7:
      result = CMineRole::Load(a1);
      break;
    case 8:
      result = CFarmBuildingRole::Load(a1);
      break;
    case 9:
      result = CLookoutTowerRole::Load(a1);
      break;
    case 10:
      result = CMilitaryBuildingRole::Load(a1);
      break;
    case 11:
      result = CBarrackRole::Load(a1);
      break;
    case 12:
      result = CStorageBuildingRole::Load(a1);
      break;
    case 13:
      result = CTradingBuildingRole::Load(a1);
      break;
    case 14:
      result = CResidenceBuildingRole::Load(a1);
      break;
    case 15:
      result = CCastleRole::Load(a1);
      break;
    case 16:
      result = CSmallTempleRole::Load(a1);
      break;
    case 17:
      result = CBigTempleRole::Load(a1);
      break;
    case 18:
      result = CDarkTempleRole::Load(a1);
      break;
    case 19:
      result = CEyeCatcherRole::Load(a1);
      break;
    case 20:
      result = CDarkMushroomFarmRole::Load(a1);
      break;
    case 21:
      result = CManakopterHallRole::Load(a1);
      break;
    default:
      if ( BBSupportDbgReportF(
             2,
             "MapObjects\\Building\\BuildingMgr.cpp",
             968,
             "The programm can't load this building role at the moment!") == 1 )
        __debugbreak();
      pExceptionObject[0] = 0;
      CS4InvalidMapException::CS4InvalidMapException(pExceptionObject);
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  return result;
}


// address=[0x14f9410]
// Decompiled from int __thiscall CBuildingMgr::CheckForBuildCalc(  CBuildingMgr *this,  int a2,  int a3,  int a4,  int a5,  int a6,  unsigned int a7)
int  CBuildingMgr::CheckForBuildCalc(int,int,int,int,int,int) {
  
  int v7; // ecx
  int v8; // ecx
  void *v9; // eax
  _DWORD *v10; // eax
  int result; // eax
  _BYTE v12[12]; // [esp+8h] [ebp-C8h] BYREF
  _BYTE v13[12]; // [esp+14h] [ebp-BCh] BYREF
  int v14; // [esp+20h] [ebp-B0h]
  int v15; // [esp+24h] [ebp-ACh]
  int v16; // [esp+28h] [ebp-A8h]
  int v17; // [esp+2Ch] [ebp-A4h]
  int v18; // [esp+30h] [ebp-A0h]
  int v19; // [esp+34h] [ebp-9Ch]
  int v20; // [esp+38h] [ebp-98h]
  int v21; // [esp+3Ch] [ebp-94h]
  int v22; // [esp+40h] [ebp-90h]
  int v23; // [esp+44h] [ebp-8Ch]
  std::_Iterator_base12 *v24; // [esp+48h] [ebp-88h]
  std::_Iterator_base12 *v25; // [esp+4Ch] [ebp-84h]
  int v26; // [esp+50h] [ebp-80h]
  int v27; // [esp+54h] [ebp-7Ch]
  int v28; // [esp+58h] [ebp-78h]
  int v29; // [esp+5Ch] [ebp-74h]
  int v30; // [esp+60h] [ebp-70h]
  int v31; // [esp+64h] [ebp-6Ch]
  int v32; // [esp+68h] [ebp-68h]
  int v33; // [esp+6Ch] [ebp-64h]
  int v34; // [esp+70h] [ebp-60h]
  int v35; // [esp+74h] [ebp-5Ch]
  int v36; // [esp+78h] [ebp-58h]
  int v37; // [esp+7Ch] [ebp-54h]
  int v38; // [esp+80h] [ebp-50h]
  int v39; // [esp+84h] [ebp-4Ch]
  char *BuildingInfo; // [esp+88h] [ebp-48h]
  _BYTE v41[12]; // [esp+8Ch] [ebp-44h] BYREF
  int k; // [esp+98h] [ebp-38h]
  int v43; // [esp+9Ch] [ebp-34h]
  int v44; // [esp+A0h] [ebp-30h]
  int v45; // [esp+A4h] [ebp-2Ch]
  char v46; // [esp+ABh] [ebp-25h]
  int v47; // [esp+ACh] [ebp-24h]
  int v48; // [esp+B0h] [ebp-20h]
  int v49; // [esp+B4h] [ebp-1Ch]
  CBuildingMgr *v50; // [esp+B8h] [ebp-18h]
  int i; // [esp+BCh] [ebp-14h]
  int j; // [esp+C0h] [ebp-10h]
  int v53; // [esp+CCh] [ebp-4h]

  v50 = this;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 2208, "g_cWorld.InWorld(_iXPos, _iYPos)") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 2209, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a6 <= 0 || a6 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         2210,
         "_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a7 >= 0x100
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 2211, "_iHeight>=0 && _iHeight<256") == 1 )
  {
    __debugbreak();
  }
  v7 = a3 - 15;
  if ( a3 - 15 < 0
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 2212, "_iYPos-MAX_DIG_RANGE >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( a3 + 15 >= CWorldManager::Height(v7, 0)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 2213, "_iYPos+MAX_DIG_RANGE < g_cWorld.Height()") == 1 )
  {
    __debugbreak();
  }
  v8 = a2 - 15;
  if ( a2 - 15 < 0
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 2214, "_iXPos-MAX_DIG_RANGE >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( a2 + 15 >= CWorldManager::Width(v8)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 2215, "_iXPos+MAX_DIG_RANGE < g_cWorld.Width()") == 1 )
  {
    __debugbreak();
  }
  v47 = 31;
  for ( i = 0; i < v47; ++i )
  {
    v44 = a3 + i - 15;
    for ( j = 0; j < v47; ++j )
    {
      *((_BYTE *)v50 + 32 * j + i + 289755) = 0;
      v43 = a2 + j - 15;
      *((_BYTE *)v50 + 32 * j + i + 288731) = CWorldManager::GroundHeight(v43, v44);
      if ( j && i && j != v47 - 1 && i != v47 - 1 )
      {
        if ( CWorldManager::FlagBits(v43, v44, 0x10u) )
        {
          *((_BYTE *)v50 + 32 * j + i + 289755) = 100;
          *((_BYTE *)v50 + 32 * j + i + 289787) = 100;
          *((_BYTE *)v50 + 32 * j + i + 289723) = 100;
          *((_BYTE *)v50 + 32 * j + i + 289756) = 100;
          *((_BYTE *)v50 + 32 * j + i + 289754) = 100;
          *((_BYTE *)v50 + 32 * j + i + 289788) = 100;
          *((_BYTE *)v50 + 32 * j + i + 289722) = 100;
        }
        else if ( !CWorldManager::FlagBits(v43, v44, 0x49u) && CWorldManager::OwnerId(v43, v44) == a5 )
        {
          v14 = CWorldManager::Ground(v43, v44) & 0xF0;
          if ( v14 == 48 )
            *((_BYTE *)v50 + 32 * j + i + 289755) = 100;
        }
        else
        {
          *((_BYTE *)v50 + 32 * j + i + 289755) = 100;
        }
      }
      else
      {
        *((_BYTE *)v50 + 32 * j + i + 289755) = 100;
      }
    }
  }
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v41);
  v53 = 0;
  v9 = (void *)CPlayerManager::PlayerInfo(a4);
  v28 = CPlayerInfo::Race(v9);
  BuildingInfo = (char *)CBuildingInfoMgr::GetBuildingInfo(v28, a6);
  v39 = 0;
  v27 = std::vector<unsigned int>::begin(v13);
  v26 = v27;
  LOBYTE(v53) = 1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator=(v27);
  LOBYTE(v53) = 0;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v13);
  while ( 1 )
  {
    v25 = (std::_Iterator_base12 *)std::vector<unsigned int>::end(v12);
    v24 = v25;
    LOBYTE(v53) = 2;
    v46 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator!=(v25);
    LOBYTE(v53) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v12);
    if ( !v46 )
      break;
    ++v39;
    if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v41) )
    {
      v38 = v39 - BuildingInfo[1] - 1;
      for ( k = 31; k >= 0; --k )
      {
        v10 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator*(v41);
        if ( (*v10 & (1 << k)) != 0 )
        {
          v29 = 32 - k - *BuildingInfo - 1;
          *((_BYTE *)v50 + 32 * v29 + v38 + 289226) = a7;
          *((_BYTE *)v50 + 32 * v29 + v38 + 290250) = 1;
        }
      }
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::operator++(v41);
  }
  v48 = 1;
  while ( v48 == 1 )
  {
    v48 = 0;
    i = 1;
LABEL_59:
    if ( i < v47 - 1 )
    {
      for ( j = 1; ; ++j )
      {
        if ( j >= v47 - 1 )
        {
          ++i;
          goto LABEL_59;
        }
        if ( *((_BYTE *)v50 + 32 * j + i + 289755) == 1 )
        {
          *((_BYTE *)v50 + 32 * j + i + 289755) = 100;
          v49 = *((unsigned __int8 *)v50 + 32 * j + i + 288731);
          if ( *((unsigned __int8 *)v50 + 32 * j + i + 288698) + 5 < v49 )
          {
            v37 = *((unsigned __int8 *)v50 + 32 * j + i + 289722);
            switch ( v37 )
            {
              case 0:
                *((_BYTE *)v50 + 32 * j + i + 289722) = 1;
                *((_BYTE *)v50 + 32 * j + i + 288698) = v49 - 5;
                v48 = 1;
                goto CBuildingMgr__CheckForBuildCalc___def_18F9A61;
              case 1:
              case 2:
              case 100:
                v23 = 0;
                v53 = -1;
                std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v41);
                result = v23;
                break;
              default:
                goto CBuildingMgr__CheckForBuildCalc___def_18F9A61;
            }
            return result;
          }
CBuildingMgr__CheckForBuildCalc___def_18F9A61:
          if ( *((unsigned __int8 *)v50 + 32 * j + i + 288698) - 7 > v49 )
          {
            v36 = *((unsigned __int8 *)v50 + 32 * j + i + 289722);
            switch ( v36 )
            {
              case 0:
                *((_BYTE *)v50 + 32 * j + i + 289722) = 1;
                *((_BYTE *)v50 + 32 * j + i + 288698) = v49 + 7;
                v48 = 1;
                goto CBuildingMgr__CheckForBuildCalc___def_18F9B25;
              case 1:
              case 2:
              case 100:
                v22 = 0;
                v53 = -1;
                std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v41);
                result = v22;
                break;
              default:
                goto CBuildingMgr__CheckForBuildCalc___def_18F9B25;
            }
            return result;
          }
CBuildingMgr__CheckForBuildCalc___def_18F9B25:
          if ( *((unsigned __int8 *)v50 + 32 * j + i + 288730) + 5 < v49 )
          {
            v35 = *((unsigned __int8 *)v50 + 32 * j + i + 289754);
            switch ( v35 )
            {
              case 0:
                *((_BYTE *)v50 + 32 * j + i + 289754) = 1;
                *((_BYTE *)v50 + 32 * j + i + 288730) = v49 - 5;
                v48 = 1;
                goto CBuildingMgr__CheckForBuildCalc___def_18F9BE3;
              case 1:
              case 2:
              case 100:
                v21 = 0;
                v53 = -1;
                std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v41);
                result = v21;
                break;
              default:
                goto CBuildingMgr__CheckForBuildCalc___def_18F9BE3;
            }
            return result;
          }
CBuildingMgr__CheckForBuildCalc___def_18F9BE3:
          if ( *((unsigned __int8 *)v50 + 32 * j + i + 288730) - 7 > v49 )
          {
            v34 = *((unsigned __int8 *)v50 + 32 * j + i + 289754);
            switch ( v34 )
            {
              case 0:
                *((_BYTE *)v50 + 32 * j + i + 289754) = 1;
                *((_BYTE *)v50 + 32 * j + i + 288730) = v49 + 7;
                v48 = 1;
                goto CBuildingMgr__CheckForBuildCalc___def_18F9C9B;
              case 1:
              case 2:
              case 100:
                v20 = 0;
                v53 = -1;
                std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v41);
                result = v20;
                break;
              default:
                goto CBuildingMgr__CheckForBuildCalc___def_18F9C9B;
            }
            return result;
          }
CBuildingMgr__CheckForBuildCalc___def_18F9C9B:
          if ( *((unsigned __int8 *)v50 + 32 * j + i + 288764) + 7 < v49 )
          {
            v33 = *((unsigned __int8 *)v50 + 32 * j + i + 289788);
            switch ( v33 )
            {
              case 0:
                *((_BYTE *)v50 + 32 * j + i + 289788) = 1;
                *((_BYTE *)v50 + 32 * j + i + 288764) = v49 - 7;
                v48 = 1;
                goto CBuildingMgr__CheckForBuildCalc___def_18F9D59;
              case 1:
              case 2:
              case 100:
                v19 = 0;
                v53 = -1;
                std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v41);
                result = v19;
                break;
              default:
                goto CBuildingMgr__CheckForBuildCalc___def_18F9D59;
            }
            return result;
          }
CBuildingMgr__CheckForBuildCalc___def_18F9D59:
          if ( *((unsigned __int8 *)v50 + 32 * j + i + 288764) - 5 > v49 )
          {
            v32 = *((unsigned __int8 *)v50 + 32 * j + i + 289788);
            switch ( v32 )
            {
              case 0:
                *((_BYTE *)v50 + 32 * j + i + 289788) = 1;
                *((_BYTE *)v50 + 32 * j + i + 288764) = v49 + 5;
                v48 = 1;
                goto CBuildingMgr__CheckForBuildCalc___def_18F9E1D;
              case 1:
              case 2:
              case 100:
                v18 = 0;
                v53 = -1;
                std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v41);
                result = v18;
                break;
              default:
                goto CBuildingMgr__CheckForBuildCalc___def_18F9E1D;
            }
            return result;
          }
CBuildingMgr__CheckForBuildCalc___def_18F9E1D:
          if ( *((unsigned __int8 *)v50 + 32 * j + i + 288732) + 7 < v49 )
          {
            v31 = *((unsigned __int8 *)v50 + 32 * j + i + 289756);
            switch ( v31 )
            {
              case 0:
                *((_BYTE *)v50 + 32 * j + i + 289756) = 1;
                *((_BYTE *)v50 + 32 * j + i + 288732) = v49 - 7;
                v48 = 1;
                goto CBuildingMgr__CheckForBuildCalc___def_18F9EDB;
              case 1:
              case 2:
              case 100:
                v17 = 0;
                v53 = -1;
                std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v41);
                result = v17;
                break;
              default:
                goto CBuildingMgr__CheckForBuildCalc___def_18F9EDB;
            }
            return result;
          }
CBuildingMgr__CheckForBuildCalc___def_18F9EDB:
          if ( *((unsigned __int8 *)v50 + 32 * j + i + 288732) - 5 > v49 )
          {
            v30 = *((unsigned __int8 *)v50 + 32 * j + i + 289756);
            switch ( v30 )
            {
              case 0:
                *((_BYTE *)v50 + 32 * j + i + 289756) = 1;
                *((_BYTE *)v50 + 32 * j + i + 288732) = v49 + 5;
                v48 = 1;
                continue;
              case 1:
              case 2:
              case 100:
                v16 = 0;
                v53 = -1;
                std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v41);
                result = v16;
                break;
              default:
                continue;
            }
            return result;
          }
        }
      }
    }
    for ( i = 1; i < v47 - 1; ++i )
    {
      for ( j = 1; j < v47 - 1; ++j )
      {
        if ( *((_BYTE *)v50 + 32 * j + i + 289755) == 1 )
          *((_BYTE *)v50 + 32 * j + i + 289755) = 0;
      }
    }
  }
  v45 = 0;
  for ( i = 1; i < v47 - 1; ++i )
  {
    for ( j = 1; j < v47 - 1; ++j )
    {
      v49 = CWorldManager::GroundHeight(a2 + j - 15, a3 + i - 15);
      if ( *((unsigned __int8 *)v50 + 32 * j + i + 288731) > v49 )
        v45 += *((unsigned __int8 *)v50 + 32 * j + i + 288731) - v49;
      if ( *((unsigned __int8 *)v50 + 32 * j + i + 288731) < v49 )
        v45 += v49 - *((unsigned __int8 *)v50 + 32 * j + i + 288731);
    }
  }
  if ( !v45 )
    v45 = 1;
  v15 = v45;
  v53 = -1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<unsigned int>>>(v41);
  return v15;
}


// address=[0x14fa560]
// Decompiled from void __thiscall CBuildingMgr::AddSoldierToStartTower(void *this, int a2, int a3)
void  CBuildingMgr::AddSoldierToStartTower(int,int) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int LastLogicUpdateTick; // eax
  int v7; // eax
  int v8; // [esp-8h] [ebp-44h]
  int v9; // [esp-8h] [ebp-44h]
  int v10; // [esp-4h] [ebp-40h]
  _DWORD v11[5]; // [esp+0h] [ebp-3Ch] BYREF
  int v12; // [esp+14h] [ebp-28h]
  CMilitaryBuildingRole *v13; // [esp+18h] [ebp-24h]
  int v14; // [esp+1Ch] [ebp-20h] BYREF
  int v15; // [esp+20h] [ebp-1Ch] BYREF
  int v16; // [esp+24h] [ebp-18h]
  CPaneContainer *v17; // [esp+28h] [ebp-14h]
  unsigned __int8 *v18; // [esp+2Ch] [ebp-10h]
  int v19; // [esp+30h] [ebp-Ch]
  int v20; // [esp+34h] [ebp-8h]
  bool v21; // [esp+3Ah] [ebp-2h]

  v11[4] = this;
  v18 = (unsigned __int8 *)CBuildingMgr::operator[](a2);
  v13 = (CMilitaryBuildingRole *)CBuilding::Role(v18);
  v20 = a3 + 29;
  if ( a3
    && v20 != 30
    && v20 != 31
    && v20 != 32
    && v20 != 33
    && v20 != 34
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         2104,
         "(iSoldierType == SETTLER_SWORDSMAN_01) || (iSoldierType == SETTLER_SWORDSMAN_02) || (iSoldierType == SETTLER_SW"
         "ORDSMAN_03) || (iSoldierType == SETTLER_BOWMAN_01) || (iSoldierType == SETTLER_BOWMAN_02) || (iSoldierType == S"
         "ETTLER_BOWMAN_03)") == 1 )
  {
    __debugbreak();
  }
  v12 = CSettlerMgr::SettlerWarriorType(v20);
  if ( CMilitaryBuildingRole::IncWishAndOrder(v13, v12, 1) )
  {
    v19 = 0;
    v8 = Y16X16::UnpackYFast(*((_DWORD *)v18 + 19));
    v3 = Y16X16::UnpackXFast(*((_DWORD *)v18 + 19));
    CSpiralWalk::CSpiralWalk((CSpiralWalk *)v11, v3, v8, 15);
    while ( CSpiralWalk::NextXY(v11, &v14, &v15) )
    {
      v16 = CWorldManager::Index(v14, v15);
      if ( !(unsigned __int8)CWorldManager::IsBlockedLand(v16) && !CWorldManager::MapObjectId(v16) )
      {
        v9 = v20;
        v4 = IEntity::OwnerId(v18);
        v19 = CSettlerMgr::AddSettler((CSettlerMgr *)g_cSettlerMgr, v14, v15, v4, v9, 0);
        break;
      }
    }
    if ( !v19
      && BBSupportDbgReportF(2, "MapObjects\\Building\\BuildingMgr.cpp", 2149, "No soldier for military building") == 1 )
    {
      __debugbreak();
    }
    if ( v19 )
    {
      v17 = (CPaneContainer *)CSettlerMgr::operator[](v19);
      v5 = IEntity::WarriorType();
      v21 = CMilitaryBuildingRole::IncWishAndOrder(v13, v5, 0);
      if ( !v21 && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 2157, "bIncWishAndOrderOk") == 1 )
        __debugbreak();
      IEntity::ClearFlagBits(v17, Selectable);
      v10 = v19;
      LastLogicUpdateTick = IAnimatedEntity::GetLastLogicUpdateTick(v17);
      CMapObjectMgr::UnRegisterFromLogicUpdate(g_pMapObjectMgr, LastLogicUpdateTick, v10);
      CWarMap::RemoveEntity(v17);
      v7 = IEntity::WorldIdx();
      CWorldManager::SetSettlerId(v7, 0);
      IEntity::SetFlagBits(v17, OnBoard);
      (*(void (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v18 + 116))(v18, v19);
      CBuilding::SettlerEnter((CBuilding *)v18, v19);
    }
  }
  else
  {
    BBSupportTracePrintF(3, "CBuildingMgr::AddSoldierToStartTower(): IncWishAndOrder failed!");
  }
}


// address=[0x14fa7b0]
// Decompiled from CBuildingMgr *__thiscall CBuildingMgr::CheckOutBuilding(CBuildingMgr *this, int a2)
void  CBuildingMgr::CheckOutBuilding(int) {
  
  int v2; // eax
  CBuildingMgr *result; // eax
  BOOL v4; // [esp+4h] [ebp-14h]
  unsigned __int8 *v5; // [esp+8h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h]

  if ( (a2 <= 0 || a2 >= 0xFFFF)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         608,
         "_iBuildingId>0 && _iBuildingId<CMapObjectMgr::MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  v5 = (unsigned __int8 *)CBuildingMgr::operator[](a2);
  v6 = IEntity::OwnerId(v5);
  v7 = IEntity::Type((unsigned __int16 *)v5);
  if ( a2 == *((_DWORD *)this + 83 * v6 + v7 + 2248) )
  {
    CBuildingMgr::GetNextBuilding(this, v6, v7);
    if ( a2 == *((_DWORD *)this + 83 * v6 + v7 + 2248) )
      *((_DWORD *)this + 83 * v6 + v7 + 2248) = 0;
  }
  CBuildingMgr::DetachBuilding(this, v6, v7, a2);
  v2 = CBuilding::Role(v5);
  v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 112))(v2, v2) != 0;
  if ( v4 )
    CStatistic::DecBuilding((CStatistic *)&g_cStatistic, v6, v7, 1);
  CBuildingMgr::ChangeNumberOfBuildings(this, v6, v7, v4, -1);
  result = this;
  --*((_DWORD *)this + 6);
  return result;
}


// address=[0x14fa900]
// Decompiled from int __thiscall CBuildingMgr::AttachBuilding(CBuildingMgr *this, int a2, int a3, int a4)
void  CBuildingMgr::AttachBuilding(int,int,int) {
  
  IAnimatedEntity *v4; // eax
  IAnimatedEntity *v5; // eax
  _WORD *v6; // eax
  int result; // eax
  int v9; // [esp+4h] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1215, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1216,
         "_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  v4 = (IAnimatedEntity *)CBuildingMgr::operator[](a4);
  IAnimatedEntity::SetPrevious(v4, 0);
  v9 = *((_DWORD *)this + 83 * a2 + a3 + 7);
  if ( v9 )
  {
    v5 = (IAnimatedEntity *)CBuildingMgr::operator[](v9);
    IAnimatedEntity::SetPrevious(v5, a4);
  }
  v6 = (_WORD *)CBuildingMgr::operator[](a4);
  IAnimatedEntity::SetNext(v6, v9);
  result = a3;
  *((_DWORD *)this + 83 * a2 + a3 + 7) = a4;
  return result;
}


// address=[0x14fa9f0]
// Decompiled from void __thiscall CBuildingMgr::DetachBuilding(CBuildingMgr *this, int a2, int a3, int a4)
void  CBuildingMgr::DetachBuilding(int,int,int) {
  
  int v4; // eax
  _WORD *v5; // eax
  int v6; // eax
  IAnimatedEntity *v7; // eax
  int v8; // [esp-4h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-Ch]
  IAnimatedEntity *v11; // [esp+4h] [ebp-4h]

  if ( (a2 <= 0 || a2 >= 9)
    && BBSupportDbgReport(2, "MapObjects\\Building\\BuildingMgr.cpp", 1244, "_iOwnerId>0 && _iOwnerId<PLAYER_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 83)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         1245,
         "_iBuildingType>0 && _iBuildingType<BUILDING_MAX") == 1 )
  {
    __debugbreak();
  }
  v11 = (IAnimatedEntity *)CBuildingMgr::operator[](a4);
  if ( IAnimatedEntity::Previous(v11) )
  {
    v8 = IAnimatedEntity::Next(v11);
    v4 = IAnimatedEntity::Previous(v11);
    v5 = (_WORD *)CBuildingMgr::operator[](v4);
    IAnimatedEntity::SetNext(v5, v8);
  }
  else
  {
    if ( *((_DWORD *)this + 83 * a2 + a3 + 7) != a4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingMgr.cpp",
           1258,
           "m_vPlayerBuildings[_iOwnerId][_iBuildingType] == _iBuildingId") == 1 )
    {
      __debugbreak();
    }
    *((_DWORD *)this + 83 * a2 + a3 + 7) = IAnimatedEntity::Next(v11);
  }
  if ( IAnimatedEntity::Next(v11) )
  {
    v9 = IAnimatedEntity::Previous(v11);
    v6 = IAnimatedEntity::Next(v11);
    v7 = (IAnimatedEntity *)CBuildingMgr::operator[](v6);
    IAnimatedEntity::SetPrevious(v7, v9);
  }
  IAnimatedEntity::SetNext(v11, 0);
  IAnimatedEntity::SetPrevious(v11, 0);
}


// address=[0x14facb0]
// Decompiled from bool __thiscall CBuildingMgr::IsValidManakopterHallPosition(CBuildingMgr *this, int a2, int a3)
bool  CBuildingMgr::IsValidManakopterHallPosition(int,int) {
  
  int v3; // eax
  int v5; // [esp-10h] [ebp-18h]

  v5 = Y16X16::UnpackYFast(a2);
  v3 = Y16X16::UnpackXFast(a2);
  return CBuildingMgr::CheckForBuildDarkTribe(this, v3, v5, a3, 80, 0) > 0;
}


// address=[0x14fad00]
// Decompiled from char __thiscall CBuildingMgr::AddPositionToList(CBuildingMgr *this, int a2, int a3)
bool  CBuildingMgr::AddPositionToList(int,int) {
  
  if ( *((int *)this + a3 + 72875) < 0
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\BuildingMgr.cpp",
         4068,
         "m_vManakopterHallPositionsInUse[_iPlayerId] >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_DWORD *)this + a3 + 72875) == 20 )
  {
    BBSupportTracePrintF(2, "Too many ManakopterHallPositions. Player %d", a3);
    return 0;
  }
  else
  {
    if ( *((int *)this + a3 + 72875) >= 20
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\BuildingMgr.cpp",
           4078,
           "m_vManakopterHallPositionsInUse[_iPlayerId] < MAX_MANAKOPTERHALL_POS") == 1 )
    {
      __debugbreak();
    }
    *((_DWORD *)this + 20 * a3 + (*((_DWORD *)this + a3 + 72875))++ + 72695) = a2;
    return 1;
  }
}


