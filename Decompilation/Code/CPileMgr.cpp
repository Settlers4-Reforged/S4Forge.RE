#include "CPileMgr.h"

// Definitions for class CPileMgr

// address=[0x12fd1f0]
// Decompiled from unsigned __int8 *__cdecl CPileMgr::GetPilePtr(int a1)
static class CPile * __cdecl CPileMgr::GetPilePtr(int) {
  
  unsigned __int8 *v3; // [esp+8h] [ebp-4h]

  v3 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a1);
  if ( v3 && IEntity::ObjType(v3) == 16 )
    return v3;
  else
    return 0;
}


// address=[0x1438a40]
// Decompiled from unsigned __int8 *__stdcall CPileMgr::operator[](int a1)
class CPile &  CPileMgr::operator[](int) {
  
  unsigned __int8 *v2; // [esp+4h] [ebp-4h]

  v2 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(a1);
  if ( !v2
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Pile\\PileMgr.h",
         174,
         "pEntity != 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::ObjType(v2) != 16
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Pile\\PileMgr.h",
         175,
         "pEntity->ObjType() == PILE_OBJ") == 1 )
  {
    __debugbreak();
  }
  return v2;
}


// address=[0x155e900]
// Decompiled from CPileMgr *__thiscall CPileMgr::CPileMgr(CPileMgr *this)
 CPileMgr::CPileMgr(void) {
  
  MemoryAllocator::MemoryAllocator(this, 0x7Cu, 0x20u, 0);
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  return this;
}


// address=[0x155e930]
// Decompiled from void __thiscall CPileMgr::~CPileMgr(CPileMgr *this)
 CPileMgr::~CPileMgr(void) {
  
  MemoryAllocator::~MemoryAllocator(this);
}


// address=[0x155e950]
// Decompiled from CPileMgr *__thiscall CPileMgr::Clear(CPileMgr *this)
void  CPileMgr::Clear(void) {
  
  CPileMgr *result; // eax

  result = this;
  *((_DWORD *)this + 6) = 0;
  return result;
}


// address=[0x155e970]
// Decompiled from char *__thiscall CPileMgr::LoadPileData(CPileMgr *this, struct S4::CMapFile *a2, int a3)
void  CPileMgr::LoadPileData(class S4::CMapFile &,int) {
  
  char *result; // eax
  char *v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch] BYREF
  int i; // [esp+14h] [ebp-8h]
  char *v9; // [esp+18h] [ebp-4h]

  v7 = 0;
  result = (char *)S4::CMapFile::LoadChunk(a2, 9u, 0, &v7, 0);
  v5 = result;
  for ( i = 0; i < v7; ++i )
  {
    v9 = &v5[8 * i];
    if ( (unsigned __int8)v9[6] == 254 )
      v6 = 3;
    else
      v6 = 2;
    result = (char *)CPileMgr::AddPile(
                       this,
                       *(unsigned __int16 *)v9,
                       *((unsigned __int16 *)v9 + 1),
                       (unsigned __int8)v9[4],
                       (unsigned __int8)v9[5],
                       v6,
                       0,
                       0,
                       0,
                       0);
  }
  return result;
}


// address=[0x155ea20]
// Decompiled from int __thiscall CPileMgr::AddPile(  CPileMgr *this,  int a2,  int a3,  unsigned int a4,  unsigned int a5,  unsigned int a6,  int a7,  int a8,  int a9,  int a10)
int  CPileMgr::AddPile(int,int,int,int,int,int,int,int,int) {
  
  int v11; // [esp-18h] [ebp-54h] BYREF
  int v12; // [esp-14h] [ebp-50h]
  int v13; // [esp-10h] [ebp-4Ch]
  int v14; // [esp-Ch] [ebp-48h]
  int v15; // [esp-8h] [ebp-44h]
  int v16; // [esp-4h] [ebp-40h]
  int v17; // [esp+4h] [ebp-38h]
  int v18; // [esp+8h] [ebp-34h]
  int *v19; // [esp+Ch] [ebp-30h]
  int v20; // [esp+10h] [ebp-2Ch]
  int v21; // [esp+14h] [ebp-28h]
  struct IPileRole *PileRole; // [esp+18h] [ebp-24h]
  char v23[4]; // [esp+1Ch] [ebp-20h] BYREF
  int FreeSlot; // [esp+20h] [ebp-1Ch]
  int v25; // [esp+24h] [ebp-18h]
  CPileMgr *v27; // [esp+2Ch] [ebp-10h]
  int v28; // [esp+38h] [ebp-4h]

  v27 = this;
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 344, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( a4 > 0x2A && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 345, "_iGood>=0 && _iGood<GOOD_MAX") == 1 )
    __debugbreak();
  if ( a5 > 8
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 346, "_iAmount>=0 && _iAmount<=CPile::MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  if ( a6 >= 6
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 347, "_iType>=0 && _iType<=IPileRole::PILE_BUILDINGSITE") == 1 )
  {
    __debugbreak();
  }
  if ( debug && DEBUG_FLAGS[dword_415207C] )
    BBSupportTracePrintF(0, "New pile  at %u %u good %u type %u", a2, a3, a4, a6);
  if ( *((int *)v27 + 6) >= 20000 )
  {
    BBSupportTracePrintF(0, "NO more piles!!!");
    return 0;
  }
  else
  {
    ++*((_DWORD *)v27 + 6);
    PileRole = CPileMgr::CreatePileRole(a6);
    std::auto_ptr<IPileRole>::auto_ptr<IPileRole>(PileRole);
    v28 = 1;
    FreeSlot = CMapObjectMgr::GetFreeSlot();
    if ( CPile::operator new(0x7Cu) )
    {
      v16 = a10;
      v15 = a9;
      v14 = a8;
      v13 = a7;
      v12 = FreeSlot;
      v11 = FreeSlot;
      v19 = &v11;
      v18 = std::auto_ptr<IPileRole>::auto_ptr<IPileRole>(v23);
      v21 = CPile::CPile(a2, a3, a4, a5, v11, v12, v13, v14, v15, v16);
      v25 = v21;
    }
    else
    {
      v25 = 0;
    }
    v17 = v25;
    v20 = FreeSlot;
    v28 = -1;
    std::auto_ptr<IPileRole>::~auto_ptr<IPileRole>(v23);
    return v20;
  }
}


// address=[0x155ec40]
// Decompiled from void __thiscall CPileMgr::DeletePile(CPileMgr *this, int a2)
void  CPileMgr::DeletePile(int) {
  
  unsigned __int8 *v2; // eax
  unsigned __int8 *v3; // eax

  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 510, "_iPileId>0") == 1 )
    __debugbreak();
  v2 = CPileMgr::operator[](a2);
  if ( CPile::AmountLeaving((CPile *)v2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 511, "g_cPileMgr[_iPileId].AmountLeaving() == 0") == 1 )
  {
    __debugbreak();
  }
  v3 = CPileMgr::operator[](a2);
  if ( CPile::AmountComing((CPile *)v3)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 512, "g_cPileMgr[_iPileId].AmountComing() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( debug && DEBUG_FLAGS[dword_4152080] )
  {
    BBSupportTracePrintF(0, "DeletePile");
    CPileMgr::TracePile(this, a2);
  }
  if ( a2 )
  {
    --*((_DWORD *)this + 6);
    CMapObjectMgr::Kill(a2, 0);
  }
}


// address=[0x155ed50]
// Decompiled from void __thiscall CPileMgr::DeletePileUnforeseen(CPileMgr *this, int a2)
void  CPileMgr::DeletePileUnforeseen(int) {
  
  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 538, "_iPileId>0") == 1 )
    __debugbreak();
  if ( debug && DEBUG_FLAGS[dword_4152080] )
  {
    BBSupportTracePrintF(0, "DeletePile");
    CPileMgr::TracePile(this, a2);
  }
  if ( a2 )
  {
    --*((_DWORD *)this + 6);
    CMapObjectMgr::Kill(a2, 0);
  }
}


// address=[0x155ede0]
// Decompiled from int __thiscall CPileMgr::GetNearestPile(CPileMgr *this, int a2, int a3, int a4)
int  CPileMgr::GetNearestPile(int,int,int) {
  
  int v5; // esi
  int v6; // eax
  int v7; // [esp-4h] [ebp-20h]
  int v8; // [esp+8h] [ebp-14h]
  unsigned int v9; // [esp+Ch] [ebp-10h]
  unsigned int v10; // [esp+10h] [ebp-Ch] BYREF
  int v11; // [esp+14h] [ebp-8h]
  struct CPile *PilePtr; // [esp+18h] [ebp-4h]

  if ( !a2 )
    return 0;
  v11 = a2;
  v10 = 0;
  v8 = 0;
  v9 = -1;
  PilePtr = CPileMgr::GetPilePtr(a2);
  if ( !PilePtr && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 582, "pPile != 0") == 1 )
    __debugbreak();
  while ( PilePtr )
  {
    v5 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)PilePtr + 40))(PilePtr);
    if ( v5 != CPile::AmountLeaving(PilePtr) )
    {
      v7 = a4 - IEntity::Y(PilePtr);
      v6 = IEntity::X(PilePtr);
      v10 = Grid::Distance((Grid *)(a3 - v6), v7);
      CPile::ReassessDistance(PilePtr, (int *)&v10);
      if ( v10 < v9 )
      {
        v9 = v10;
        v8 = v11;
      }
    }
    v11 = IAnimatedEntity::Next(PilePtr);
    if ( v11 )
      PilePtr = CPileMgr::GetPilePtr(v11);
    else
      PilePtr = 0;
  }
  return v8;
}


// address=[0x155eef0]
// Decompiled from int __thiscall CPileMgr::SearchSpaceForGoods(CPileMgr *this, int a2, int a3, unsigned int a4, unsigned int a5)
void  CPileMgr::SearchSpaceForGoods(int,int,int,int) {
  
  int result; // eax
  int v6; // esi
  int v7; // esi
  int v8; // [esp+Ch] [ebp-38h]
  int v9; // [esp+10h] [ebp-34h]
  int v11; // [esp+18h] [ebp-2Ch]
  int v12; // [esp+18h] [ebp-2Ch]
  int v13; // [esp+1Ch] [ebp-28h]
  int v14; // [esp+20h] [ebp-24h]
  int v15; // [esp+24h] [ebp-20h]
  int v16; // [esp+28h] [ebp-1Ch]
  int v17; // [esp+28h] [ebp-1Ch]
  int v18; // [esp+2Ch] [ebp-18h]
  int v19; // [esp+30h] [ebp-14h]
  unsigned int v20; // [esp+34h] [ebp-10h]
  unsigned int v21; // [esp+34h] [ebp-10h]
  int v22; // [esp+38h] [ebp-Ch]
  int v23; // [esp+3Ch] [ebp-8h]
  unsigned __int8 *v24; // [esp+40h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 633, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( a4 > 0x2A && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 634, "_iGood>=0 && _iGood<GOOD_MAX") == 1 )
    __debugbreak();
  if ( a5 > 8
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 635, "_iAmount>=0 && _iAmount<=CPile::MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  v22 = 0;
  result = a5;
  v23 = a5;
  while ( v23 && v22 <= 9999 )
  {
    v13 = a2 + CSpiralOffsets::DeltaX(v22);
    v14 = a3 + CSpiralOffsets::DeltaY(v22);
    result = CWorldManager::InWorld(v13, v14);
    if ( (_BYTE)result )
    {
      result = CWorldManager::PileId(v13, v14);
      v15 = result;
      if ( result )
      {
        v20 = a4;
        v16 = CWorldManager::OwnerId(v13, v14);
        if ( v16 )
        {
          v11 = CPlayerManager::Race(v16);
          v20 = CPileMgr::ConvertGoodType(this, a4, v11);
        }
        v24 = CPileMgr::operator[](v15);
        result = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v24 + 60))(v24);
        if ( result == v20 )
        {
          result = CPile::GetRoleType((CPile *)v24);
          if ( result == 3 )
          {
            v6 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v24 + 40))(v24);
            result = CPile::AmountComing((CPile *)v24);
            if ( result + v6 < 8 )
            {
              v7 = 8 - (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v24 + 40))(v24);
              v9 = v7 - CPile::AmountComing((CPile *)v24);
              if ( v9 >= v23 )
                v8 = v23;
              else
                v8 = v9;
              CPile::IncreaseUnforeseen((CPile *)v24, v8);
              result = v23 - v8;
              v23 -= v8;
            }
          }
        }
      }
    }
    if ( v23 > 8 )
    {
      result = BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 684, "iAmount <= CPile::MAX_PILE_AMOUNT");
      if ( result == 1 )
        __debugbreak();
    }
    if ( v23 )
    {
      if ( v22 >= 50 )
      {
        v18 = a2 + CSpiralOffsets::DeltaX(v22 - 50);
        v19 = a3 + CSpiralOffsets::DeltaY(v22 - 50);
        result = (unsigned __int8)CWorldManager::InWorld(v18, v19);
        if ( (_BYTE)result )
        {
          result = CWorldManager::FlagBits(v18, v19, 0x39u);
          if ( !result )
          {
            result = CWorldManager::ObjectId(v18, v19);
            if ( !result )
            {
              result = CWorldManager::MapObjectId(v18, v19);
              if ( !result )
              {
                result = CWorldManager::SectorId(v18, v19);
                if ( result )
                {
                  v21 = a4;
                  v17 = CWorldManager::OwnerId(v18, v19);
                  if ( v17 )
                  {
                    v12 = CPlayerManager::Race(v17);
                    v21 = CPileMgr::ConvertGoodType(this, a4, v12);
                  }
                  result = CPileMgr::AddPile(this, v18, v19, v21, v23, 3, 0, 0, 0, 0);
                  if ( !result )
                  {
                    result = BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 717, "iActPileId != 0");
                    if ( result == 1 )
                      __debugbreak();
                  }
                  v23 = 0;
                }
              }
            }
          }
        }
      }
    }
    ++v22;
  }
  return result;
}


// address=[0x155f280]
// Decompiled from void __thiscall CPileMgr::Store(CPileMgr *this, struct S4::CMapFile *a2)
void  CPileMgr::Store(class S4::CMapFile &) {
  
  std::strstreambuf *v2; // eax
  void *v3; // eax
  int v4; // [esp+0h] [ebp-104h] BYREF
  _DWORD v5[43]; // [esp+10h] [ebp-F4h] BYREF
  unsigned int v6; // [esp+BCh] [ebp-48h]
  size_t Size; // [esp+C0h] [ebp-44h]
  void *Src; // [esp+C4h] [ebp-40h]
  int v9; // [esp+C8h] [ebp-3Ch]
  unsigned __int8 *v10; // [esp+CCh] [ebp-38h]
  int v11; // [esp+D0h] [ebp-34h]
  unsigned __int8 *v12; // [esp+D4h] [ebp-30h]
  int UsedId; // [esp+D8h] [ebp-2Ch]
  int v14; // [esp+DCh] [ebp-28h] BYREF
  int v15; // [esp+E0h] [ebp-24h]
  unsigned __int8 *v16; // [esp+E4h] [ebp-20h]
  int v17; // [esp+E8h] [ebp-1Ch] BYREF
  unsigned __int8 *v18; // [esp+ECh] [ebp-18h]
  int i; // [esp+F0h] [ebp-14h]
  int *v20; // [esp+F4h] [ebp-10h]
  int v21; // [esp+100h] [ebp-4h]

  v20 = &v4;
  v5[42] = this;
  std::ostrstream::ostrstream(0, 0x40000, 0, 2, 1);
  v21 = 0;
  v6 = std::ios_base::exceptions((char *)v5 + *(_DWORD *)(v5[0] + 4));
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), 6);
  LOBYTE(v21) = 1;
  v14 = 1;
  operator^<unsigned int>((struct std::ostream *)v5, &v14);
  UsedId = CMapObjectMgr::LastUsedId();
  v15 = UsedId;
  v17 = 0;
  for ( i = 0; i <= v15; ++i )
  {
    v12 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(i);
    v16 = v12;
    if ( v12 )
    {
      v11 = IEntity::ObjType(v16);
      if ( v11 == 16 )
        ++v17;
    }
  }
  operator^<unsigned int>((struct std::ostream *)v5, &v17);
  for ( i = 0; i <= v15; ++i )
  {
    v10 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(i);
    v18 = v10;
    if ( v10 )
    {
      v9 = IEntity::ObjType(v18);
      if ( v9 == 16 )
        (*(void (__thiscall **)(unsigned __int8 *, _DWORD *))(*(_DWORD *)v18 + 4))(v18, v5);
    }
  }
  std::ostream::put(0);
  v21 = 0;
  std::ostrstream::freeze((std::ostrstream *)v5, 1);
  v2 = std::ostrstream::rdbuf((std::ostrstream *)v5);
  Size = std::strstreambuf::pcount(v2);
  std::ostrstream::str((CDaoIndexFieldInfo *)v5);
  Src = v3;
  S4::CMapFile::SaveChunk(163, 0, Size, v3, 0);
  std::ostrstream::freeze((std::ostrstream *)v5, 0);
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), v6);
  v21 = -1;
  std::ostrstream::`vbase destructor'((std::ostrstream *)v5);
}


// address=[0x155f4c0]
// Decompiled from void __thiscall CPileMgr::Load(CPileMgr *this, struct S4::CMapFile *a2)
void  CPileMgr::Load(class S4::CMapFile &) {
  
  int v2; // [esp+0h] [ebp-FCh]
  _DWORD v3[42]; // [esp+4h] [ebp-F8h] BYREF
  unsigned int v4; // [esp+ACh] [ebp-50h]
  int v5; // [esp+B0h] [ebp-4Ch]
  int v6; // [esp+B4h] [ebp-48h] BYREF
  int v7; // [esp+B8h] [ebp-44h] BYREF
  CPileMgr *v8; // [esp+BCh] [ebp-40h]
  unsigned int v9; // [esp+C0h] [ebp-3Ch] BYREF
  int pExceptionObject; // [esp+C4h] [ebp-38h] BYREF
  char *Str; // [esp+C8h] [ebp-34h]
  unsigned int i; // [esp+CCh] [ebp-30h]
  _BYTE v13[28]; // [esp+D0h] [ebp-2Ch] BYREF
  int v14; // [esp+F8h] [ebp-4h]

  v8 = this;
  v7 = 0;
  Str = (char *)S4::CMapFile::LoadChunk(a2, 0xA3u, 0, &v7, 0);
  if ( Str )
  {
    std::string::string(v13, Str);
    v14 = 0;
    std::istringstream::istringstream(v13, 1, 1);
    LOBYTE(v14) = 1;
    v4 = std::ios_base::exceptions((char *)v3 + *(_DWORD *)(v3[0] + 4));
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), 6);
    operator^<unsigned int>(v3, &v6);
    v5 = v6;
    if ( v6 != 1 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPileMgr");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    v9 = 0;
    operator^<unsigned int>(v3, &v9);
    for ( i = 0; i < v9; ++i )
    {
      CPersistence::New(v3, v2);
      ++*((_DWORD *)v8 + 6);
    }
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), v4);
    LOBYTE(v14) = 0;
    std::istringstream::`vbase destructor'(v3);
    v14 = -1;
    std::string::~string(v13);
  }
}


// address=[0x155f670]
// Decompiled from int __thiscall CPileMgr::DbgCheckPiles(_DWORD *this, int a2)
int  CPileMgr::DbgCheckPiles(int) {
  
  int UsedId; // [esp+0h] [ebp-1Ch]
  struct CPile *PilePtr; // [esp+8h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-10h]
  int i; // [esp+14h] [ebp-8h]
  int v8; // [esp+18h] [ebp-4h]

  BBSupportTracePrintF(1, "CPileMgr::DbgCheckPiles()...");
  v8 = 0;
  v6 = 0;
  UsedId = CMapObjectMgr::LastUsedId();
  for ( i = 1; i <= UsedId; ++i )
  {
    PilePtr = CPileMgr::GetPilePtr(i);
    if ( PilePtr )
    {
      ++v6;
      IEntity::FlagBits(PilePtr, (EntityFlag)&loc_3000000);
    }
  }
  if ( this[6] )
  {
    v8 = 1;
    BBSupportTracePrintF(3, " Invalid number of piles: Is %i, should be %i!", this[6], 0);
  }
  BBSupportTracePrintF(1, " %i pile(s) checked.", 0);
  if ( v8 )
    BBSupportTracePrintF(1, " %i error(s).", v8);
  else
    BBSupportTracePrintF(1, " No errors.");
  return v8;
}


// address=[0x155f760]
// Decompiled from int __thiscall CPileMgr::ConvertGoodType(CPileMgr *this, int a2, int a3)
int  CPileMgr::ConvertGoodType(int,int) {
  
  int v4; // [esp+4h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-8h]
  char v6; // [esp+Fh] [ebp-1h]

  if ( a3 < 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 847, "_iTargetRace >= RACE_ROMAN") == 1 )
    __debugbreak();
  if ( a3 >= 5 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 848, "_iTargetRace < RACE_MAX") == 1 )
    __debugbreak();
  v5 = 0;
  v4 = a2;
  v6 = 0;
  while ( dword_3D8BBC8[30 * a3 + 2 * v5] && !v6 )
  {
    if ( dword_3D8BBC8[30 * a3 + 2 * v5] == a2 )
    {
      v4 = dword_3D8BBCC[30 * a3 + 2 * v5];
      v6 = 1;
    }
    else
    {
      ++v5;
    }
  }
  return v4;
}


// address=[0x155f820]
// Decompiled from CProductionPileRole *__cdecl CPileMgr::CreatePileRole(int a1)
static class IPileRole * __cdecl CPileMgr::CreatePileRole(int) {
  
  CProductionPileRole *result; // eax
  CBuildingSitePileRole *v2; // [esp+1Ch] [ebp-40h]
  CBuildingSitePileRole *v3; // [esp+20h] [ebp-3Ch]
  CTradePileRole *v4; // [esp+24h] [ebp-38h]
  CTradePileRole *v5; // [esp+28h] [ebp-34h]
  CStoragePileRole *v6; // [esp+2Ch] [ebp-30h]
  CStoragePileRole *v7; // [esp+30h] [ebp-2Ch]
  CDeliverPileRole *v8; // [esp+34h] [ebp-28h]
  CDeliverPileRole *v9; // [esp+38h] [ebp-24h]
  CProductionPileRole *v10; // [esp+3Ch] [ebp-20h]
  CProductionPileRole *v11; // [esp+40h] [ebp-1Ch]
  CAnyWherePileRole *v12; // [esp+44h] [ebp-18h]
  CAnyWherePileRole *C; // [esp+48h] [ebp-14h]

  switch ( a1 )
  {
    case 0:
      v11 = (CProductionPileRole *)operator new(8u);
      if ( v11 )
        v10 = CProductionPileRole::CProductionPileRole(v11);
      else
        v10 = 0;
      result = v10;
      break;
    case 1:
      v9 = (CDeliverPileRole *)operator new(8u);
      if ( v9 )
        v8 = CDeliverPileRole::CDeliverPileRole(v9);
      else
        v8 = 0;
      result = v8;
      break;
    case 2:
      v7 = (CStoragePileRole *)operator new(8u);
      if ( v7 )
        v6 = CStoragePileRole::CStoragePileRole(v7);
      else
        v6 = 0;
      result = v6;
      break;
    case 3:
      C = (CAnyWherePileRole *)operator new(8u);
      if ( C )
        v12 = CAnyWherePileRole::CAnyWherePileRole(C);
      else
        v12 = 0;
      result = v12;
      break;
    case 4:
      v5 = (CTradePileRole *)operator new(0x14u);
      if ( v5 )
        v4 = CTradePileRole::CTradePileRole(v5);
      else
        v4 = 0;
      result = v4;
      break;
    case 5:
      v3 = (CBuildingSitePileRole *)operator new(8u);
      if ( v3 )
        v2 = CBuildingSitePileRole::CBuildingSitePileRole(v3);
      else
        v2 = 0;
      result = v2;
      break;
    default:
      if ( BBSupportDbgReportF(
             2,
             "MapObjects\\Pile\\PileMgr.cpp",
             436,
             "The programm can't use this pile role at the moment (P0)!") == 1 )
        __debugbreak();
      if ( BBSupportDbgReport(
             1,
             "MapObjects\\Pile\\PileMgr.cpp",
             437,
             "Internal Error (P0)! Aborting!\nInterner Fehler (P0) aufgetreten! Programm wird beendet!") == 1 )
        __debugbreak();
      result = 0;
      break;
  }
  return result;
}


// address=[0x155e750]
// Decompiled from unsigned int __thiscall CPileMgr::Alloc(CPileMgr *this, unsigned int a2)
void *  CPileMgr::Alloc(unsigned int) {
  
  return MemoryAllocator::allocate((unsigned int *)this, a2);
}


// address=[0x155e7b0]
// Decompiled from void __thiscall CPileMgr::Dealloc(CPileMgr *this, void *a2)
void  CPileMgr::Dealloc(void *) {
  
  MemoryAllocator::deallocate(this, a2);
}


// address=[0x155fa90]
// Decompiled from int __thiscall CPileMgr::TracePile(CPileMgr *this, int a2)
void  CPileMgr::TracePile(int) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int RoleType; // eax
  int v7; // [esp-1Ch] [ebp-24h]
  int v8; // [esp-18h] [ebp-20h]
  int v9; // [esp-14h] [ebp-1Ch]
  int v10; // [esp-10h] [ebp-18h]
  int v11; // [esp-10h] [ebp-18h]
  int v12; // [esp-Ch] [ebp-14h]
  int v13; // [esp-Ch] [ebp-14h]
  int v14; // [esp-Ch] [ebp-14h]
  int v15; // [esp-8h] [ebp-10h]
  int v16; // [esp-8h] [ebp-10h]
  int v17; // [esp-4h] [ebp-Ch]
  int v18; // [esp-4h] [ebp-Ch]
  unsigned __int8 *v20; // [esp+4h] [ebp-4h]

  v20 = CPileMgr::operator[](a2);
  v17 = IAnimatedEntity::Next(v20);
  v15 = IAnimatedEntity::Previous(v20);
  v12 = IEntity::Y(v20);
  v2 = IEntity::X(v20);
  v13 = CWorldManager::EcoSectorId(v2, v12);
  v10 = CPile::AmountComing((CPile *)v20);
  v3 = CPile::AmountLeaving((CPile *)v20);
  v4 = (*(int (__thiscall **)(unsigned __int8 *, int, int, int, int, int, CPileMgr *))(*(_DWORD *)v20 + 40))(
         v20,
         v3,
         v10,
         v13,
         v15,
         v17,
         this);
  v7 = (*(int (__thiscall **)(unsigned __int8 *, int))(*(_DWORD *)v20 + 60))(v20, v4);
  RoleType = CPile::GetRoleType((CPile *)v20);
  return BBSupportTracePrintF(
           0,
           "Pile Nr: %u, Type: %u ,Good: %u, am: %u, aml: %u, amc: %u, es: %u, prev: %u, next: %u",
           a2,
           RoleType,
           v7,
           v8,
           v9,
           v11,
           v14,
           v16,
           v18);
}


// address=[0x155fb30]
// Decompiled from int __cdecl CPileMgr::LoadPileRole(int a1, int a2)
static class IPileRole * __cdecl CPileMgr::LoadPileRole(std::istream &,int) {
  
  int result; // eax
  _DWORD pExceptionObject[2]; // [esp+0h] [ebp-8h] BYREF

  pExceptionObject[1] = a2;
  switch ( a2 )
  {
    case 0:
      result = CProductionPileRole::Load(a1);
      break;
    case 1:
      result = CDeliverPileRole::Load(a1);
      break;
    case 2:
      result = CStoragePileRole::Load(a1);
      break;
    case 3:
      result = CAnyWherePileRole::Load(a1);
      break;
    case 4:
      result = CTradePileRole::Load(a1);
      break;
    case 5:
      result = CBuildingSitePileRole::Load(a1);
      break;
    default:
      if ( BBSupportDbgReportF(
             2,
             "MapObjects\\Pile\\PileMgr.cpp",
             492,
             "The programm can't use this pile role at the moment!") == 1 )
        __debugbreak();
      pExceptionObject[0] = 0;
      CS4InvalidMapException::CS4InvalidMapException(pExceptionObject);
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  return result;
}


// address=[0x155fc30]
// Decompiled from void __thiscall CPileMgr::CheckOutPile(CPileMgr *this, int a2)
void  CPileMgr::CheckOutPile(int) {
  
  ;
}


