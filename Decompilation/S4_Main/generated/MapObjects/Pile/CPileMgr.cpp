#include "CPileMgr.h"

// Definitions for class CPileMgr

// address=[0x12fd1f0]
// Decompiled from IEntity *__cdecl CPileMgr::GetPilePtr(int _iPileId)
class CPile * __cdecl CPileMgr::GetPilePtr(int _iPileId) {
  
  IEntity *v3; // [esp+8h] [ebp-4h]

  v3 = CMapObjectMgr::EntityPtr(_iPileId);
  if ( v3 && IEntity::ObjType(v3) == PILE_OBJ )
    return v3;
  else
    return 0;
}


// address=[0x1438a40]
// Decompiled from IEntity *__stdcall CPileMgr::operator[](int _iPileId)
class CPile &  CPileMgr::operator[](int _iPileId) {
  
  IEntity *pEntity; // [esp+4h] [ebp-4h]

  pEntity = CMapObjectMgr::EntityPtr(_iPileId);
  if ( !pEntity
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Pile\\PileMgr.h",
         174,
         "pEntity != 0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::ObjType(pEntity) != PILE_OBJ
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\MapObjects\\Pile\\PileMgr.h",
         175,
         "pEntity->ObjType() == PILE_OBJ") == 1 )
  {
    __debugbreak();
  }
  return pEntity;
}


// address=[0x155e900]
// Decompiled from CPileMgr *__thiscall CPileMgr::CPileMgr(CPileMgr *this)
 CPileMgr::CPileMgr(void) {
  
  MemoryAllocator::MemoryAllocator(&this->m_cAllocator, 0x7Cu, 0x20u, 0);
  this->m_iPileCount = 0;
  this->m_iU1 = 0;
  return this;
}


// address=[0x155e930]
// Decompiled from void __thiscall CPileMgr::~CPileMgr(CPileMgr *this)
 CPileMgr::~CPileMgr(void) {
  
  MemoryAllocator::~MemoryAllocator(&this->m_cAllocator);
}


// address=[0x155e950]
// Decompiled from void __thiscall CPileMgr::Clear(CPileMgr *this)
void  CPileMgr::Clear(void) {
  
  this->m_iPileCount = 0;
}


// address=[0x155e970]
// Decompiled from void __thiscall CPileMgr::LoadPileData(CPileMgr *this, struct S4::CMapFile *a2, int a3)
void  CPileMgr::LoadPileData(class S4::CMapFile & a2, int a3) {
  
  CPileMgr::SPileData *pChunks; // [esp+8h] [ebp-14h]
  int iType; // [esp+Ch] [ebp-10h]
  int iChunkCount; // [esp+10h] [ebp-Ch] BYREF
  int i; // [esp+14h] [ebp-8h]
  CPileMgr::SPileData *pPile; // [esp+18h] [ebp-4h]

  iChunkCount = 0;
  pChunks = (CPileMgr::SPileData *)S4::CMapFile::LoadChunk(a2, MAP_CHUNK_PILES, 0, &iChunkCount, 0);
  for ( i = 0; i < iChunkCount; ++i )
  {
    pPile = &pChunks[i];
    if ( pPile->m_uPileType == 254 )
      iType = 3;
    else
      iType = 2;
    CPileMgr::AddPile(
      this,
      pPile->m_iX,
      pPile->m_iY,
      pPile->m_iGood,
      (unsigned __int8)pPile->m_iAmount,
      iType,
      0,
      0,
      0,
      0);
  }
}


// address=[0x155ea20]
// Decompiled from int __thiscall CPileMgr::AddPile(  CPileMgr *this,  int _iX,  int _iY,  int _iGood,  int _iAmount,  int _iType,  int a7,  int a8,  int a9,  int a11)
int  CPileMgr::AddPile(int _iX, int _iY, int _iGood, int _iAmount, int _iType, int a7, int a8, int a9, int a11) {
  
  int _pRole1; // [esp-18h] [ebp-54h] BYREF
  int iSlot; // [esp-14h] [ebp-50h]
  int v13; // [esp-10h] [ebp-4Ch]
  int v14; // [esp-Ch] [ebp-48h]
  int v15; // [esp-8h] [ebp-44h]
  int v16; // [esp-4h] [ebp-40h]
  CPile *v17; // [esp+4h] [ebp-38h]
  _DWORD *v18; // [esp+8h] [ebp-34h]
  int *v19; // [esp+Ch] [ebp-30h]
  int v20; // [esp+10h] [ebp-2Ch]
  CPile *v21; // [esp+14h] [ebp-28h]
  CProductionPileRole *PileRole; // [esp+18h] [ebp-24h]
  char v23[4]; // [esp+1Ch] [ebp-20h] BYREF
  int _pRole; // [esp+20h] [ebp-1Ch]
  CPile *v25; // [esp+24h] [ebp-18h]
  CPile *v26; // [esp+28h] [ebp-14h]
  int v28; // [esp+38h] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 344, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (unsigned int)_iGood > 0x2A
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 345, "_iGood>=0 && _iGood<GOOD_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( (unsigned int)_iAmount > 8
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 346, "_iAmount>=0 && _iAmount<=CPile::MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  if ( (unsigned int)_iType >= 6
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 347, "_iType>=0 && _iType<=IPileRole::PILE_BUILDINGSITE") == 1 )
  {
    __debugbreak();
  }
  if ( debug && DEBUG_FLAGS[dword_415207C] )
    BBSupportTracePrintF(0, "New pile  at %u %u good %u type %u", _iX, _iY, _iGood, _iType);
  if ( this->m_iPileCount >= 20000 )
  {
    BBSupportTracePrintF(0, "NO more piles!!!");
    return 0;
  }
  else
  {
    ++this->m_iPileCount;
    PileRole = CPileMgr::CreatePileRole(_iType);
    std::auto_ptr<IPileRole>::auto_ptr<IPileRole>(PileRole);
    v28 = 1;
    _pRole = CMapObjectMgr::GetFreeSlot();
    v26 = (CPile *)CPile::operator new(0x7Cu);
    if ( v26 )
    {
      v16 = a11;
      v15 = a9;
      v14 = a8;
      v13 = a7;
      iSlot = _pRole;
      _pRole1 = _pRole;
      v19 = &_pRole1;
      v18 = std::auto_ptr<IPileRole>::auto_ptr<IPileRole>(&_pRole1, (int)v23);
      v21 = CPile::CPile(v26, _iX, _iY, (S4_GOOD_ENUM)_iGood, _iAmount, _pRole1, iSlot, v13, v14, v15, v16);
      v25 = v21;
    }
    else
    {
      v25 = 0;
    }
    v17 = v25;
    v20 = _pRole;
    v28 = -1;
    std::auto_ptr<IPileRole>::~auto_ptr<IPileRole>(v23);
    return v20;
  }
}


// address=[0x155ec40]
// Decompiled from void __thiscall CPileMgr::DeletePile(CPileMgr *this, int _iPileId)
void  CPileMgr::DeletePile(int _iPileId) {
  
  CPile *v2; // eax
  CPile *v3; // eax

  if ( _iPileId <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 510, "_iPileId>0") == 1 )
    __debugbreak();
  v2 = (CPile *)CPileMgr::operator[](_iPileId);
  if ( CPile::AmountLeaving(v2)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 511, "g_cPileMgr[_iPileId].AmountLeaving() == 0") == 1 )
  {
    __debugbreak();
  }
  v3 = (CPile *)CPileMgr::operator[](_iPileId);
  if ( CPile::AmountComing(v3)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 512, "g_cPileMgr[_iPileId].AmountComing() == 0") == 1 )
  {
    __debugbreak();
  }
  if ( debug && DEBUG_FLAGS[dword_4152080] )
  {
    BBSupportTracePrintF(0, "DeletePile");
    CPileMgr::TracePile(this, _iPileId);
  }
  if ( _iPileId )
  {
    --this->m_iPileCount;
    CMapObjectMgr::Kill(g_pMapObjectMgr, _iPileId, 0);
  }
}


// address=[0x155ed50]
// Decompiled from void __thiscall CPileMgr::DeletePileUnforeseen(CPileMgr *this, int _iPileId)
void  CPileMgr::DeletePileUnforeseen(int _iPileId) {
  
  if ( _iPileId <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 538, "_iPileId>0") == 1 )
    __debugbreak();
  if ( debug && DEBUG_FLAGS[dword_4152080] )
  {
    BBSupportTracePrintF(0, "DeletePile");
    CPileMgr::TracePile(this, _iPileId);
  }
  if ( _iPileId )
  {
    --this->m_iPileCount;
    CMapObjectMgr::Kill(g_pMapObjectMgr, _iPileId, 0);
  }
}


// address=[0x155ede0]
// Decompiled from int __thiscall CPileMgr::GetNearestPile(CPileMgr *this, int a2, int a3, int a4)
int  CPileMgr::GetNearestPile(int a2, int a3, int a4) {
  
  int v5; // esi
  int v6; // eax
  int v7; // [esp-4h] [ebp-20h]
  int v8; // [esp+8h] [ebp-14h]
  unsigned int v9; // [esp+Ch] [ebp-10h]
  unsigned int v10; // [esp+10h] [ebp-Ch] BYREF
  int v11; // [esp+14h] [ebp-8h]
  CPile *pPile; // [esp+18h] [ebp-4h]

  if ( !a2 )
    return 0;
  v11 = a2;
  v10 = 0;
  v8 = 0;
  v9 = -1;
  pPile = (CPile *)CPileMgr::GetPilePtr(a2);
  if ( !pPile && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 582, "pPile != 0") == 1 )
    __debugbreak();
  while ( pPile )
  {
    v5 = pPile->Amount(pPile);
    if ( v5 != CPile::AmountLeaving(pPile) )
    {
      v7 = a4 - IEntity::Y(pPile);
      v6 = IEntity::X(pPile);
      v10 = Grid::Distance(a3 - v6, v7);
      CPile::ReassessDistance(pPile, (int *)&v10);
      if ( v10 < v9 )
      {
        v9 = v10;
        v8 = v11;
      }
    }
    v11 = IAnimatedEntity::Next(pPile);
    if ( v11 )
      pPile = (CPile *)CPileMgr::GetPilePtr(v11);
    else
      pPile = 0;
  }
  return v8;
}


// address=[0x155eef0]
// Decompiled from void __thiscall CPileMgr::SearchSpaceForGoods(  CPileMgr *this,  unsigned int _iX,  unsigned int _iY,  unsigned int _iGood,  unsigned int _iAmount)
void  CPileMgr::SearchSpaceForGoods(int _iX, int _iY, int _iGood, int _iAmount) {
  
  int v5; // esi
  int v6; // esi
  int v7; // [esp+Ch] [ebp-38h]
  signed int v8; // [esp+10h] [ebp-34h]
  unsigned int v10; // [esp+1Ch] [ebp-28h]
  unsigned int v11; // [esp+20h] [ebp-24h]
  int v12; // [esp+24h] [ebp-20h]
  int v13; // [esp+28h] [ebp-1Ch]
  int v14; // [esp+28h] [ebp-1Ch]
  unsigned int v15; // [esp+2Ch] [ebp-18h]
  unsigned int v16; // [esp+30h] [ebp-14h]
  unsigned int v17; // [esp+34h] [ebp-10h]
  unsigned int v18; // [esp+34h] [ebp-10h]
  int v19; // [esp+38h] [ebp-Ch]
  signed int iAmount; // [esp+3Ch] [ebp-8h]
  CPile *v21; // [esp+40h] [ebp-4h]

  if ( !CWorldManager::InWorld(_iX, _iY)
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 633, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( _iGood > 0x2A && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 634, "_iGood>=0 && _iGood<GOOD_MAX") == 1 )
    __debugbreak();
  if ( _iAmount > 8
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 635, "_iAmount>=0 && _iAmount<=CPile::MAX_PILE_AMOUNT") == 1 )
  {
    __debugbreak();
  }
  v19 = 0;
  iAmount = _iAmount;
  while ( iAmount && v19 <= 9999 )
  {
    v10 = _iX + CSpiralOffsets::DeltaX(v19);
    v11 = _iY + CSpiralOffsets::DeltaY(v19);
    if ( CWorldManager::InWorld(v10, v11) )
    {
      v12 = CWorldManager::PileId(v10, v11);
      if ( v12 )
      {
        v17 = _iGood;
        v13 = CWorldManager::OwnerId(v10, v11);
        if ( v13 )
        {
          CPlayerManager::Race(v13);
          v17 = CPileMgr::ConvertGoodType(this, _iGood);
        }
        v21 = (CPile *)CPileMgr::operator[](v12);
        if ( v21->GetGoodType() == v17 && CPile::GetRoleType(v21) == 3 )
        {
          v5 = v21->Amount(v21);
          if ( CPile::AmountComing(v21) + v5 < 8 )
          {
            v6 = 8 - v21->Amount(v21);
            v8 = v6 - CPile::AmountComing(v21);
            if ( v8 >= iAmount )
              v7 = iAmount;
            else
              v7 = v8;
            CPile::IncreaseUnforeseen(v21, v7);
            iAmount -= v7;
          }
        }
      }
    }
    if ( iAmount > 8
      && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 684, "iAmount <= CPile::MAX_PILE_AMOUNT") == 1 )
    {
      __debugbreak();
    }
    if ( iAmount )
    {
      if ( v19 >= 50 )
      {
        v15 = _iX + CSpiralOffsets::DeltaX(v19 - 50);
        v16 = _iY + CSpiralOffsets::DeltaY(v19 - 50);
        if ( CWorldManager::InWorld(v15, v16)
          && !CWorldManager::FlagBits(v15, v16, 0x39u)
          && !CWorldManager::ObjectId(v15, v16)
          && !CWorldManager::MapObjectId(v15, v16)
          && CWorldManager::SectorId(v15, v16) )
        {
          v18 = _iGood;
          v14 = CWorldManager::OwnerId(v15, v16);
          if ( v14 )
          {
            CPlayerManager::Race(v14);
            v18 = CPileMgr::ConvertGoodType(this, _iGood);
          }
          if ( !CPileMgr::AddPile(this, v15, v16, v18, iAmount, 3, 0, 0, 0, 0)
            && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 717, "iActPileId != 0") == 1 )
          {
            __debugbreak();
          }
          iAmount = 0;
        }
      }
    }
    ++v19;
  }
}


// address=[0x155f280]
// Decompiled from void __thiscall CPileMgr::Store(CPileMgr *this, struct S4::CMapFile *_rMapFile)
void  CPileMgr::Store(class S4::CMapFile & _rMapFile) {
  
  char *v2; // eax
  int v3; // [esp+0h] [ebp-104h] BYREF
  std::ostrstream v4; // [esp+10h] [ebp-F4h] BYREF
  unsigned int v5; // [esp+BCh] [ebp-48h]
  size_t Size; // [esp+C0h] [ebp-44h]
  void *Src; // [esp+C4h] [ebp-40h]
  T_SETTLER_OBJ_TYPE v8; // [esp+C8h] [ebp-3Ch]
  IEntity *v9; // [esp+CCh] [ebp-38h]
  T_SETTLER_OBJ_TYPE v10; // [esp+D0h] [ebp-34h]
  IEntity *v11; // [esp+D4h] [ebp-30h]
  int UsedId; // [esp+D8h] [ebp-2Ch]
  int v13; // [esp+DCh] [ebp-28h] BYREF
  int v14; // [esp+E0h] [ebp-24h]
  IEntity *v15; // [esp+E4h] [ebp-20h]
  int v16; // [esp+E8h] [ebp-1Ch] BYREF
  IEntity *v17; // [esp+ECh] [ebp-18h]
  int i; // [esp+F0h] [ebp-14h]
  int *v19; // [esp+F4h] [ebp-10h]
  int v20; // [esp+100h] [ebp-4h]

  v19 = &v3;
  v4.v4[42] = (DWORD)this;
  std::ostrstream::ostrstream(v4.v4, 0, 0x40000LL, 2, 1);
  v20 = 0;
  v5 = std::ios_base::exceptions((char *)&v4 + *(_DWORD *)(v4.v4[0] + 4));
  std::ios_base::exceptions((std::ios_base *)((char *)&v4 + *(_DWORD *)(v4.v4[0] + 4)), 6);
  LOBYTE(v20) = 1;
  v13 = 1;
  operator^<unsigned int>(&v4, &v13);
  UsedId = CMapObjectMgr::LastUsedId();
  v14 = UsedId;
  v16 = 0;
  for ( i = 0; i <= v14; ++i )
  {
    v11 = CMapObjectMgr::EntityPtr(i);
    v15 = v11;
    if ( v11 )
    {
      v10 = IEntity::ObjType(v15);
      if ( v10 == PILE_OBJ )
        ++v16;
    }
  }
  operator^<unsigned int>(&v4, &v16);
  for ( i = 0; i <= v14; ++i )
  {
    v9 = CMapObjectMgr::EntityPtr(i);
    v17 = v9;
    if ( v9 )
    {
      v8 = IEntity::ObjType(v17);
      if ( v8 == PILE_OBJ )
        v17->Store(v17, &v4);
    }
  }
  std::ostream::put(0);
  v20 = 0;
  std::ostrstream::freeze(&v4, 1);
  v2 = std::ostrstream::rdbuf(&v4);
  Size = std::strstreambuf::pcount((std::strstreambuf *)v2);
  Src = std::ostrstream::str(&v4);
  S4::CMapFile::SaveChunk(_rMapFile, 0xA3u, 0, Size, Src, 0);
  std::ostrstream::freeze(&v4, 0);
  std::ios_base::exceptions((std::ios_base *)((char *)&v4 + *(_DWORD *)(v4.v4[0] + 4)), v5);
  v20 = -1;
  std::ostrstream::`vbase destructor'(&v4);
}


// address=[0x155f4c0]
// Decompiled from void __thiscall CPileMgr::Load(CPileMgr *this, struct S4::CMapFile *_rMapFile)
void  CPileMgr::Load(class S4::CMapFile & _rMapFile) {
  
  _DWORD v2[42]; // [esp+4h] [ebp-F8h] BYREF
  unsigned int v3; // [esp+ACh] [ebp-50h]
  int v4; // [esp+B0h] [ebp-4Ch]
  int v5; // [esp+B4h] [ebp-48h] BYREF
  int a4; // [esp+B8h] [ebp-44h] BYREF
  unsigned int v8; // [esp+C0h] [ebp-3Ch] BYREF
  int pExceptionObject; // [esp+C4h] [ebp-38h] BYREF
  char *Str; // [esp+C8h] [ebp-34h]
  unsigned int i; // [esp+CCh] [ebp-30h]
  std::string v12; // [esp+D0h] [ebp-2Ch] BYREF
  int v13; // [esp+F8h] [ebp-4h]

  a4 = 0;
  Str = (char *)S4::CMapFile::LoadChunk(_rMapFile, MAP_CHUNK_SAVE_PILES, 0, &a4, 0);
  if ( Str )
  {
    std::string::string(&v12, Str);
    v13 = 0;
    std::istringstream::istringstream(&v12, 1, 1);
    LOBYTE(v13) = 1;
    v3 = std::ios_base::exceptions((char *)v2 + *(_DWORD *)(v2[0] + 4));
    std::ios_base::exceptions((std::ios_base *)((char *)v2 + *(_DWORD *)(v2[0] + 4)), 6);
    operator^<unsigned int>(v2, &v5);
    v4 = v5;
    if ( v5 != 1 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPileMgr");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    v8 = 0;
    operator^<unsigned int>(v2, &v8);
    for ( i = 0; i < v8; ++i )
    {
      CPersistence::New((struct std::istream *)v2);
      ++this->m_iPileCount;
    }
    std::ios_base::exceptions((std::ios_base *)((char *)v2 + *(_DWORD *)(v2[0] + 4)), v3);
    LOBYTE(v13) = 0;
    std::istringstream::`vbase destructor'(v2);
    v13 = -1;
    std::string::~string(&v12);
  }
}


// address=[0x155f670]
// Decompiled from int __thiscall CPileMgr::DbgCheckPiles(CPileMgr *this, int a2)
int  CPileMgr::DbgCheckPiles(int a2) {
  
  int UsedId; // [esp+0h] [ebp-1Ch]
  IEntity *PilePtr; // [esp+8h] [ebp-14h]
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
      IEntity::FlagBits(PilePtr, ENTITY_FLAG_AliveMask);
    }
  }
  if ( this->m_iPileCount )
  {
    v8 = 1;
    BBSupportTracePrintF(3, " Invalid number of piles: Is %i, should be %i!", this->m_iPileCount, 0);
  }
  BBSupportTracePrintF(1, " %i pile(s) checked.", 0);
  if ( v8 )
    BBSupportTracePrintF(1, " %i error(s).", v8);
  else
    BBSupportTracePrintF(1, " No errors.");
  return v8;
}


// address=[0x155f760]
// Decompiled from int __thiscall CPileMgr::ConvertGoodType(CPileMgr *this, int a2, int _iTargetRace)
int  CPileMgr::ConvertGoodType(int a2, int _iTargetRace) {
  
  int iNewGoodType; // [esp+4h] [ebp-Ch]
  int iGood; // [esp+8h] [ebp-8h]
  char bFoundCustomGoodConversion; // [esp+Fh] [ebp-1h]

  if ( _iTargetRace < 0
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 847, "_iTargetRace >= RACE_ROMAN") == 1 )
  {
    __debugbreak();
  }
  if ( _iTargetRace >= 5 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileMgr.cpp", 848, "_iTargetRace < RACE_MAX") == 1 )
    __debugbreak();
  iGood = 0;
  iNewGoodType = a2;
  bFoundCustomGoodConversion = 0;
  while ( s_sGoodConversionMap[_iTargetRace][iGood].m_iFromGood && !bFoundCustomGoodConversion )
  {
    if ( s_sGoodConversionMap[_iTargetRace][iGood].m_iFromGood == a2 )
    {
      iNewGoodType = s_sGoodConversionMap[_iTargetRace][iGood].m_iToGood;
      bFoundCustomGoodConversion = 1;
    }
    else
    {
      ++iGood;
    }
  }
  return iNewGoodType;
}


// address=[0x155f820]
// Decompiled from CProductionPileRole *__cdecl CPileMgr::CreatePileRole(int _iRole)
class IPileRole * __cdecl CPileMgr::CreatePileRole(int _iRole) {
  
  CProductionPileRole *result; // eax
  CProductionPileRole *v2; // [esp+1Ch] [ebp-40h]
  CBuildingSitePileRole *v3; // [esp+20h] [ebp-3Ch]
  CProductionPileRole *v4; // [esp+24h] [ebp-38h]
  CTradePileRole *v5; // [esp+28h] [ebp-34h]
  CProductionPileRole *v6; // [esp+2Ch] [ebp-30h]
  CStoragePileRole *v7; // [esp+30h] [ebp-2Ch]
  CProductionPileRole *v8; // [esp+34h] [ebp-28h]
  CDeliverPileRole *v9; // [esp+38h] [ebp-24h]
  CProductionPileRole *v10; // [esp+3Ch] [ebp-20h]
  CProductionPileRole *v11; // [esp+40h] [ebp-1Ch]
  CProductionPileRole *v12; // [esp+44h] [ebp-18h]
  CAnyWherePileRole *C; // [esp+48h] [ebp-14h]

  switch ( _iRole )
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
// Decompiled from uint __thiscall CPileMgr::Alloc(CPileMgr *this, uint a2)
void *  CPileMgr::Alloc(unsigned int a2) {
  
  return MemoryAllocator::allocate(&this->m_cAllocator, a2);
}


// address=[0x155e7b0]
// Decompiled from void __thiscall CPileMgr::Dealloc(CPileMgr *this, uint *a2)
void  CPileMgr::Dealloc(void * a2) {
  
  MemoryAllocator::deallocate(&this->m_cAllocator, a2);
}


// address=[0x155fa90]
// Decompiled from void __thiscall CPileMgr::TracePile(CPileMgr *this, int iPileId)
void  CPileMgr::TracePile(int iPileId) {
  
  int v2; // eax
  int RoleType; // eax
  int iGood; // [esp-1Ch] [ebp-24h]
  int iAmount; // [esp-18h] [ebp-20h]
  int iAmountLeaving; // [esp-14h] [ebp-1Ch]
  int iAmountComing; // [esp-10h] [ebp-18h]
  int v8; // [esp-Ch] [ebp-14h]
  int iES; // [esp-Ch] [ebp-14h]
  int iPrev; // [esp-8h] [ebp-10h]
  int iNext; // [esp-4h] [ebp-Ch]
  CPile *v12; // [esp+4h] [ebp-4h]

  v12 = (CPile *)CPileMgr::operator[](iPileId);
  iNext = IAnimatedEntity::Next(v12);
  iPrev = IAnimatedEntity::Previous(v12);
  v8 = IEntity::Y(v12);
  v2 = IEntity::X(v12);
  iES = CWorldManager::EcoSectorId(v2, v8);
  iAmountComing = CPile::AmountComing(v12);
  iAmountLeaving = CPile::AmountLeaving(v12);
  iAmount = v12->Amount(v12);
  iGood = v12->GetGoodType();
  RoleType = CPile::GetRoleType(v12);
  BBSupportTracePrintF(
    0,
    "Pile Nr: %u, Type: %u ,Good: %u, am: %u, aml: %u, amc: %u, es: %u, prev: %u, next: %u",
    iPileId,
    RoleType,
    iGood,
    iAmount,
    iAmountLeaving,
    iAmountComing,
    iES,
    iPrev,
    iNext);
}


// address=[0x155fb30]
// Decompiled from int __cdecl CPileMgr::LoadPileRole(int _rStream, int _iRole)
class IPileRole * __cdecl CPileMgr::LoadPileRole(std::istream & _rStream, int _iRole) {
  
  int result; // eax
  _DWORD pExceptionObject[2]; // [esp+0h] [ebp-8h] BYREF

  pExceptionObject[1] = _iRole;
  switch ( _iRole )
  {
    case 0:
      result = CProductionPileRole::Load(_rStream);
      break;
    case 1:
      result = CDeliverPileRole::Load(_rStream);
      break;
    case 2:
      result = CStoragePileRole::Load(_rStream);
      break;
    case 3:
      result = CAnyWherePileRole::Load(_rStream);
      break;
    case 4:
      result = CTradePileRole::Load(_rStream);
      break;
    case 5:
      result = CBuildingSitePileRole::Load(_rStream);
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
void  CPileMgr::CheckOutPile(int a2) {
  
  ;
}


