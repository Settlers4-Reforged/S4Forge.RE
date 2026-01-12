#include "CAnimalMgr.h"

// Definitions for class CAnimalMgr

// address=[0x14dacb0]
// Decompiled from CAnimalMgr *__thiscall CAnimalMgr::CAnimalMgr(CAnimalMgr *this)

 CAnimalMgr::CAnimalMgr(void) {
  
  int i; // [esp+4h] [ebp-14h]

  MemoryAllocator::MemoryAllocator(this, 0xB0u, 0x20u, 0);
  std::vector<unsigned int>::vector<unsigned int>();
  std::vector<unsigned int>::vector<unsigned int>();
  std::vector<unsigned int>::vector<unsigned int>();
  std::vector<unsigned int>::vector<unsigned int>();
  std::vector<unsigned int>::vector<unsigned int>();
  CRandom16Ex::CRandom16Ex((CAnimalMgr *)((char *)this + 380), 0);
  CAnimalMgr::Clear(this);
  for ( i = 0; i < 17; ++i )
  {
    *((_DWORD *)this + i + 24) = 0;
    *((_DWORD *)this + i + 41) = 0;
  }
  *((_DWORD *)this + 97) = 0;
  CRandom16Ex::Init((CAnimalMgr *)((char *)this + 380), 0x29061971u, 0);
  return this;
}


// address=[0x14dade0]
// Decompiled from void __thiscall CAnimalMgr::~CAnimalMgr(CAnimalMgr *this)

 CAnimalMgr::~CAnimalMgr(void) {
  
  CAnimalMgr::ShutDown(this);
  std::vector<unsigned int>::~vector<unsigned int>();
  std::vector<unsigned int>::~vector<unsigned int>();
  std::vector<unsigned int>::~vector<unsigned int>();
  std::vector<unsigned int>::~vector<unsigned int>();
  std::vector<unsigned int>::~vector<unsigned int>();
  MemoryAllocator::~MemoryAllocator(this);
}


// address=[0x14dae70]
// Decompiled from int __thiscall CAnimalMgr::Init(CAnimalEffect **this)

void  CAnimalMgr::Init(void) {
  
  Squares *v1; // eax
  CAnimalEffect *v2; // eax
  CAnimalMgr *v3; // ecx
  int v4; // edx
  Squares *v5; // eax
  int v6; // esi
  int v7; // ecx
  int v8; // edi
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int result; // eax
  int v13; // [esp+Ch] [ebp-74h]
  int v14; // [esp+10h] [ebp-70h]
  int v15; // [esp+18h] [ebp-68h] BYREF
  int v16; // [esp+1Ch] [ebp-64h] BYREF
  int v17; // [esp+20h] [ebp-60h] BYREF
  int v18; // [esp+24h] [ebp-5Ch]
  int v19; // [esp+28h] [ebp-58h] BYREF
  int v20; // [esp+2Ch] [ebp-54h]
  int v21; // [esp+30h] [ebp-50h]
  unsigned __int16 *v22; // [esp+34h] [ebp-4Ch]
  CAnimalEffect *v23; // [esp+38h] [ebp-48h]
  void *C; // [esp+3Ch] [ebp-44h]
  unsigned __int16 *v25; // [esp+40h] [ebp-40h]
  int v26; // [esp+44h] [ebp-3Ch]
  int v27; // [esp+48h] [ebp-38h]
  unsigned __int16 *v28; // [esp+4Ch] [ebp-34h]
  int v29; // [esp+50h] [ebp-30h]
  int v30; // [esp+54h] [ebp-2Ch]
  int v31; // [esp+58h] [ebp-28h]
  int n; // [esp+5Ch] [ebp-24h]
  int k; // [esp+60h] [ebp-20h]
  int m; // [esp+64h] [ebp-1Ch]
  int i; // [esp+68h] [ebp-18h]
  int j; // [esp+6Ch] [ebp-14h]
  CAnimalEffect **v37; // [esp+70h] [ebp-10h]
  int v38; // [esp+7Ch] [ebp-4h]

  v37 = this;
  v1 = (Squares *)CWorldManager::Width(this);
  v2 = (CAnimalEffect *)Squares::XYToVW(v1);
  v3 = (CAnimalMgr *)v37;
  v37[71] = v2;
  v5 = (Squares *)CWorldManager::Height(v3, v4);
  v37[72] = (CAnimalEffect *)Squares::XYToVW(v5);
  v37[93] = 0;
  v37[62] = 0;
  v37[63] = 0;
  v37[94] = (CAnimalEffect *)2;
  CAnimalMgr::LoadAnimalData((CAnimalMgr *)v37);
  v21 = (_DWORD)v37[72] * (_DWORD)v37[71];
  v6 = 100 * (*(int (__thiscall **)(void *))(*(_DWORD *)g_pTiling + 52))(g_pTiling);
  v8 = CWorldManager::Width(v7);
  v31 = v6 / (CWorldManager::Height(v10, v9) * v8);
  if ( !v31 )
    v31 = 1;
  v27 = (int)v37[61] * v31 * v21 / 10000;
  if ( v27 < (int)v37[64] )
    v37[64] = (CAnimalEffect *)v27;
  v20 = 100
      - ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
          g_pCfgMgr,
          "ANIMAL_DATA",
          "HUNT_PERCENT",
          50);
  v37[65] = (CAnimalEffect *)(v20 * (int)v37[64] / 100);
  std::vector<unsigned int>::clear();
  std::vector<unsigned int>::clear();
  std::vector<unsigned int>::clear();
  std::vector<unsigned int>::clear();
  std::vector<unsigned int>::clear();
  for ( i = 0; i < (int)v37[71]; ++i )
  {
    for ( j = 0; j < (int)v37[72]; ++j )
    {
      if ( CAIResourceMap::IsOfLandtype(12, (Squares *)i, (Squares *)j) )
      {
        v19 = Y16X16::PackXYFast(i, j);
        std::vector<unsigned int>::push_back(&v19);
        v29 = 16 * i;
        v30 = 16 * j;
        for ( k = 0; k < 16; ++k )
        {
          for ( m = 0; m < 16; ++m )
          {
            v26 = CWorldManager::ObjectId(k + v29, m + v30);
            if ( v26 )
            {
              v25 = (unsigned __int16 *)CMapObjectMgr::EntityPtr(v26);
              if ( v25 )
              {
                v11 = IEntity::Type(v25);
                if ( CDecoObjMgr::IsFlower((CDecoObjMgr *)&g_cDecoObjMgr, v11)
                  && CAnimalMgr::CheckButterflyUnderground((CAnimalMgr *)v37, k + v29, m + v30) )
                {
                  v18 = Y16X16::PackXYFast(k + v29, m + v30);
                  v17 = v18;
                  std::vector<unsigned int>::push_back(&v17);
                }
              }
            }
          }
        }
      }
      if ( CAIResourceMap::IsOfLandtype(2, (Squares *)i, (Squares *)j) )
      {
        v16 = Y16X16::PackXYFast(i, j);
        std::vector<unsigned int>::push_back(&v16);
      }
      if ( CAIResourceMap::IsOfLandtype(7, (Squares *)i, (Squares *)j)
        && (unsigned __int8)CAnimalMgr::IsLandscapeAround(v37, 13, i, j)
        || CAIResourceMap::IsOfLandtype(13, (Squares *)i, (Squares *)j) )
      {
        v15 = Y16X16::PackXYFast(i, j);
        std::vector<unsigned int>::push_back(&v15);
      }
    }
  }
  C = operator new(0x38u);
  v38 = 0;
  if ( C )
    v23 = CAnimalEffect::CAnimalEffect((CAnimalEffect *)C);
  else
    v23 = 0;
  v38 = -1;
  v37[97] = v23;
  CAnimalEffect::SetMaxAmountButterflies(v37[97], (int)v37[67] + 1);
  CAnimalEffect::SetMaxAmountBirds(v37[97], (CAnimalEffect *)((char *)v37[68] + 1));
  CAnimalEffect::SetMaxAmountSeagulls(v37[97], (int)v37[69] + 1);
  result = CMapObjectMgr::LastUsedId();
  v14 = result;
  for ( n = 1; n <= v14; ++n )
  {
    v28 = (unsigned __int16 *)CMapObjectMgr::EntityPtr(n);
    if ( v28 )
    {
      if ( IEntity::ObjType((unsigned __int8 *)v28) == 128 )
      {
        v22 = v28;
        if ( !IEntity::FlagBits(v28, (EntityFlag)&unk_4000000) )
        {
          v37[62] = (CAnimalEffect *)((char *)v37[62] + 1);
          v13 = IEntity::Type(v22);
          if ( !CAnimalMgr::IsHuntable((CAnimalMgr *)v37, v13) )
            v37[63] = (CAnimalEffect *)((char *)v37[63] + 1);
        }
      }
    }
    result = n + 1;
  }
  return result;
}


// address=[0x14db3b0]
// Decompiled from CAnimalMgr *__thiscall CAnimalMgr::ShutDown(CAnimalMgr **this)

void  CAnimalMgr::ShutDown(void) {
  
  CAnimalMgr *result; // eax
  int i; // [esp+28h] [ebp-4h]

  result = (CAnimalMgr *)this;
  if ( this[97] )
  {
    result = this[97];
    if ( result )
      result = (CAnimalMgr *)CAnimalEffect::`scalar deleting destructor'(this[97], 1u);
    this[97] = 0;
  }
  for ( i = 0; i < 17; ++i )
  {
    if ( this[i + 24] )
    {
      std::vector<int>::`scalar deleting destructor'(1);
      this[i + 24] = 0;
    }
    result = (CAnimalMgr *)this;
    if ( this[i + 41] )
    {
      std::vector<int>::`scalar deleting destructor'(1);
      result = (CAnimalMgr *)this;
      this[i + 41] = 0;
    }
  }
  return result;
}


// address=[0x14db4d0]
// Decompiled from void *__thiscall CAnimalMgr::Clear(CAnimalMgr *this)

void  CAnimalMgr::Clear(void) {
  
  j__memset((char *)this + 24, 0, 0x24u);
  return j__memset((char *)this + 60, 0, 0x24u);
}


// address=[0x14db510]
// Decompiled from int __thiscall CAnimalMgr::AddAnimal(CAnimalMgr *this, int a2, int a3, int a4)

int  CAnimalMgr::AddAnimal(int,int,int) {
  
  int v5; // [esp+0h] [ebp-Ch]
  int v6; // [esp+4h] [ebp-8h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalMgr.cpp", 447, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (a4 <= 0 || a4 >= 18)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalMgr.cpp", 448, "_iAnimalType>0 && _iAnimalType<ANIMAL_MAX") == 1 )
  {
    __debugbreak();
  }
  v6 = CWorldManager::Index(a2, a3);
  if ( !CAnimalMgr::IsTileFree(this, v6) )
    return 0;
  v5 = CAnimalMgr::Create(a2, a3, a4);
  ++*((_DWORD *)this + 62);
  if ( byte_4032AD4[40 * a4] )
    return v5;
  ++*((_DWORD *)this + 63);
  if ( dword_4032AE4[10 * a4] >= 0 )
    ++dword_4032AEC[10 * a4];
  return v5;
}


// address=[0x14db630]
// Decompiled from int __thiscall CAnimalMgr::AddAnimalAsEffect(CAnimalMgr *this, int a2, int a3, int a4, signed int a5)

int  CAnimalMgr::AddAnimalAsEffect(int,int,int,int) {
  
  unsigned int AnimalFirstJob; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  if ( (a5 <= 0 || a5 >= 42)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalMgr.cpp", 486, "_iAnimalJob>0 && _iAnimalJob<SIV_ANIMAL_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3) )
    return 0;
  AnimalFirstJob = CGfxManager::GetAnimalFirstJob((CGfxManager *)g_pGfxManager, a5);
  v7 = CLogic::Effects((DWORD *)g_pLogic);
  return (*(int (__thiscall **)(int, unsigned int, _DWORD, int, int, int, _DWORD))(*(_DWORD *)v7 + 32))(
           v7,
           AnimalFirstJob,
           0,
           a2,
           a3,
           a4,
           0);
}


// address=[0x14db6d0]
// Decompiled from int __thiscall CAnimalMgr::DeleteAnimal(CAnimalMgr *this, int a2)

void  CAnimalMgr::DeleteAnimal(int) {
  
  int result; // eax
  unsigned __int16 *v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  if ( (a2 <= 0 || a2 >= 0xFFFF)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Animal\\AnimalMgr.cpp",
         507,
         "_iAnimalId>0 && _iAnimalId<CMapObjectMgr::MAX_ENTRIES") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( !a2 )
    return result;
  --*((_DWORD *)this + 62);
  v3 = (unsigned __int16 *)CAnimalMgr::Animal(a2);
  v4 = IEntity::Type(v3);
  if ( CAnimalMgr::IsHuntable(this, v4) )
    return CMapObjectMgr::Kill(a2, 0);
  --*((_DWORD *)this + 63);
  if ( dword_4032AE4[10 * v4] >= 0 )
    --dword_4032AEC[10 * v4];
  return CMapObjectMgr::Kill(a2, 0);
}


// address=[0x14db7b0]
// Decompiled from char __thiscall CAnimalMgr::SpawnAnimalBehindTree(CAnimalMgr *this, int a2, int a3, int a4)

void  CAnimalMgr::SpawnAnimalBehindTree(int,int,int) {
  
  unsigned int v4; // eax
  int v5; // eax
  unsigned int v6; // et2
  int v9; // [esp+Ch] [ebp-18h]
  int v10; // [esp+10h] [ebp-14h]
  int j; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  int v13; // [esp+1Ch] [ebp-8h]
  signed int v14; // [esp+20h] [ebp-4h]

  v10 = CWorldManager::Width(this);
  v9 = v10 * 16 * a4 + 16 * a3;
  v14 = CStateGame::Rand(g_pGame) % 0x10u;
  v4 = CStateGame::Rand(g_pGame);
  v6 = v4 % 0x10;
  v5 = v4 / 0x10;
  v13 = v6;
  for ( i = 2; i < 16; ++i )
  {
    if ( v13 < 16 )
    {
      if ( v13 < 2 )
        v13 = 2;
    }
    else
    {
      LOBYTE(v5) = v13 - 16;
      v13 -= 16;
    }
    for ( j = 1; j < 16; ++j )
    {
      if ( v14 < 16 )
      {
        if ( v14 < 1 )
          v14 = 1;
      }
      else
      {
        v14 -= 16;
      }
      v5 = CWorldManager::ResourceAmount(v10 * v13 + v14 + v9, 112);
      if ( v5 > 0 )
      {
        LOBYTE(v5) = CAnimalMgr::IsTileFree(this, v14 + v9 + v10 * (v13 - 2) - 1);
        if ( (_BYTE)v5 )
        {
          LOBYTE(v5) = CWorldManager::IsPositionFreeForSettler(16 * a3 + v14 - 1, 16 * a4 + v13 - 2);
          if ( (_BYTE)v5 )
          {
            LOBYTE(v5) = CAnimalMgr::AddAnimal(this, 16 * a3 + v14 - 1, 16 * a4 + v13 - 2, a2);
            return v5;
          }
        }
      }
      ++v14;
    }
    ++v13;
  }
  return v5;
}


// address=[0x14db940]
// Decompiled from char __thiscall CAnimalMgr::SpawnAnimalInTown(CAnimalMgr *this, int a2, int a3, int a4)

void  CAnimalMgr::SpawnAnimalInTown(int,int,int) {
  
  int v4; // eax
  struct CPtrList *v5; // eax
  Y16X16 *v6; // eax
  Y16X16 *v7; // eax
  int v9; // [esp+4h] [ebp-28h] BYREF
  int v10; // [esp+8h] [ebp-24h] BYREF
  int EntityIdVW; // [esp+Ch] [ebp-20h]
  CAnimalMgr *v12; // [esp+10h] [ebp-1Ch]
  int v13; // [esp+14h] [ebp-18h]
  CPropertySet *BuildingPtr; // [esp+18h] [ebp-14h]
  int v15; // [esp+1Ch] [ebp-10h] BYREF
  int v16; // [esp+20h] [ebp-Ch] BYREF
  int v17; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  v12 = this;
  v4 = CAnimalMgr::CountBuildingSquares(this, a3, a4);
  if ( v4 < 3 )
    return v4;
  EntityIdVW = CWarMap::FirstEntityIdVW(2, a3, a4);
  BuildingPtr = (CPropertySet *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, EntityIdVW);
  v5 = IEntity::WarMapNode(BuildingPtr);
  v4 = CWarMapNode::Next(v5);
  v17 = v4;
  if ( !v4 )
  {
    for ( i = 0; i < 6; ++i )
    {
      v4 = CWarMap::FirstEntityIdVW(2, g_sNeighborPoints[2 * i] + a3, dword_37D8C0C[2 * i] + a4);
      v17 = v4;
      if ( v4 > 0 )
        break;
    }
  }
  if ( !v17 )
    return v4;
  v6 = (Y16X16 *)IEntity::PackedXY(BuildingPtr);
  Y16X16::UnpackXYFast(v6, &v15, &v16);
  BuildingPtr = (CPropertySet *)CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, v17);
  v7 = (Y16X16 *)IEntity::PackedXY(BuildingPtr);
  Y16X16::UnpackXYFast(v7, &v10, &v9);
  v15 += (v10 - v15) / 2;
  v16 += (v9 - v16) / 2;
  v13 = CWorldManager::Index(v15, v16);
  LOBYTE(v4) = CAnimalMgr::IsTileFree(v12, v13);
  if ( !(_BYTE)v4 )
    return v4;
  v4 = CWorldManager::Ground(v13) & 0xF0;
  if ( v4 != 16 )
    return v4;
  v4 = CWorldManager::FlagBits(v13, 4u);
  if ( v4 )
    return v4;
  LOBYTE(v4) = CWorldManager::IsPositionFreeForSettler(v13);
  if ( (_BYTE)v4 )
    LOBYTE(v4) = CAnimalMgr::AddAnimal(v12, v15, v16, a2);
  return v4;
}


// address=[0x14dbae0]
// Decompiled from int __thiscall CAnimalMgr::SpawnAnimalOnGround(CAnimalMgr *this, int a2, int a3, int a4, int a5)

void  CAnimalMgr::SpawnAnimalOnGround(int,int,int,int) {
  
  int result; // eax
  int v6; // [esp+0h] [ebp-18h]
  int v8; // [esp+8h] [ebp-10h]
  int v9; // [esp+Ch] [ebp-Ch]
  int j; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v8 = CWorldManager::Width(this);
  result = v8 * 16 * a5 + 16 * a4;
  v6 = result;
  for ( i = 1; i < 15; ++i )
  {
    for ( j = 1; j < 15; ++j )
    {
      v9 = v8 * i + j + v6;
      if ( (CWorldManager::Ground(v9) & 0xF0) == a3
        && CAnimalMgr::IsTileFree(this, v9)
        && CWorldManager::IsPositionFreeForSettler(v9) )
      {
        return CAnimalMgr::AddAnimal(this, j + 16 * a4, i + 16 * a5, a2);
      }
      result = j + 1;
    }
  }
  return result;
}


// address=[0x14dbbc0]
// Decompiled from int __thiscall CAnimalMgr::SpawnAnimalOnDarkLand(CAnimalMgr *this, int a2, int a3, int a4)

void  CAnimalMgr::SpawnAnimalOnDarkLand(int,int,int) {
  
  int result; // eax
  int v5; // [esp+0h] [ebp-18h]
  int v7; // [esp+8h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-Ch]
  int j; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v7 = CWorldManager::Width(this);
  result = v7 * 16 * a4 + 16 * a3;
  v5 = result;
  for ( i = 1; i < 15; ++i )
  {
    for ( j = 1; j < 15; ++j )
    {
      v8 = v7 * i + j + v5;
      if ( CWorldManager::FlagBits(v8, 4u)
        && CAnimalMgr::IsTileFree(this, v8)
        && CWorldManager::IsPositionFreeForSettler(v8) )
      {
        return CAnimalMgr::AddAnimal(this, j + 16 * a3, i + 16 * a4, a2);
      }
      result = j + 1;
    }
  }
  return result;
}


// address=[0x14dbca0]
// Decompiled from void __thiscall CAnimalMgr::Update(CAnimalMgr *this)

void  CAnimalMgr::Update(void) {
  
  unsigned int v1; // eax
  unsigned int v2; // [esp+0h] [ebp-28h]
  int v3; // [esp+8h] [ebp-20h]
  int v4; // [esp+Ch] [ebp-1Ch]
  int v5; // [esp+10h] [ebp-18h]
  int v6; // [esp+14h] [ebp-14h]
  int v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-Ch]
  int v9; // [esp+20h] [ebp-8h]

  ++*((_DWORD *)this + 93);
  if ( *((_DWORD *)this + 62) < *((_DWORD *)this + 64) )
  {
    v2 = (unsigned int)CStateGame::Rand(g_pGame) % *((_DWORD *)this + 71);
    v1 = CStateGame::Rand(g_pGame);
    CAnimalMgr::SpawnAnimal(this, v2, v1 % *((_DWORD *)this + 72));
  }
  if ( *((int *)this + 93) > 10 )
  {
    *((_DWORD *)this + 93) = 0;
    CAnimalMgr::ShowEffect(this);
  }
  if ( !(*((_DWORD *)this + 93) % 3) )
    CAnimalMgr::ShowFishResources(this);
  v9 = CLogic::Effects((DWORD *)g_pLogic);
  if ( !(*(int (__thiscall **)(int, int))(*(_DWORD *)v9 + 48))(v9, 11) )
  {
    v8 = CLogic::Effects((DWORD *)g_pLogic);
    if ( !(*(int (__thiscall **)(int, int))(*(_DWORD *)v8 + 48))(v8, 12) )
    {
      v7 = CLogic::Effects((DWORD *)g_pLogic);
      if ( !(*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 48))(v7, 13) )
        CAnimalMgr::AddButterflies(this);
    }
  }
  v6 = CLogic::Effects((DWORD *)g_pLogic);
  if ( !(*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 48))(v6, 14) )
    CAnimalMgr::AddBirds(this);
  v5 = CLogic::Effects((DWORD *)g_pLogic);
  if ( !(*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 48))(v5, 15) )
  {
    v4 = CLogic::Effects((DWORD *)g_pLogic);
    if ( !(*(int (__thiscall **)(int, int))(*(_DWORD *)v4 + 48))(v4, 16) )
      CAnimalMgr::AddSeagulls(this);
  }
  v3 = CLogic::Effects((DWORD *)g_pLogic);
  if ( !(*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 48))(v3, 17) )
    CAnimalMgr::AddDucks(this);
}


// address=[0x14dbe60]
// Decompiled from char __thiscall CAnimalMgr::UpdateMovingEffect(
        CAnimalEffect **this,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)

void  CAnimalMgr::UpdateMovingEffect(unsigned int,unsigned int,unsigned int,unsigned int) {
  
  return CAnimalEffect::Update(this[97], a2, a3, a4, a5);
}


// address=[0x14dbe90]
// Decompiled from CAnimalMgr *__thiscall CAnimalMgr::AddButterfly(CRandom16 ***this, unsigned int a2, unsigned int a3)

void  CAnimalMgr::AddButterfly(int,int) {
  
  CAnimalMgr *result; // eax
  void *v4; // eax
  unsigned int v5; // [esp+0h] [ebp-Ch]

  result = (CAnimalMgr *)this;
  if ( !this[97] )
    return result;
  v5 = CAnimalEffect::AddButterfly(this[97], a2, a3);
  v4 = (void *)CLogic::FutureEvents(g_pLogic);
  return (CAnimalMgr *)IFutureEvents::AddFutureEvent16(v4, 7, 1, 0, v5, a2, a3, 0);
}


// address=[0x14dbef0]
// Decompiled from // public: bool __thiscall CAnimalMgr::IsButterflyLand(int,int)
char __thiscall CAnimalMgr::IsButterflyLand(char *this, int a2, int a3)

bool  CAnimalMgr::IsButterflyLand(int,int) {
  
  int v4; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-4h]

  v4 = Y16X16::PackXYFast(a2, a3);
  for ( i = 0; i < std::vector<unsigned int>::size(this + 308); ++i )
  {
    if ( *(_DWORD *)std::vector<unsigned int>::operator[](i) == v4 )
      return 1;
  }
  return 0;
}


// address=[0x14dbf60]
// Decompiled from char __thiscall CAnimalMgr::CheckButterflyUnderground(CAnimalMgr *this, int a2, int a3)

bool  CAnimalMgr::CheckButterflyUnderground(int,int) {
  
  int v4; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalMgr.cpp", 854, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( !CAnimalMgr::CheckButterflyUndergroundFast(this, a2, a3) )
    return 0;
  for ( i = 0; i < 12; ++i )
  {
    v4 = a2 + CSpiralOffsets::DeltaX(i + 7);
    v5 = a3 + CSpiralOffsets::DeltaY(i + 7);
    if ( (CWorldManager::Ground(v4, v5) & 0xF0) == 0x10 )
      return 1;
  }
  return 0;
}


// address=[0x14dc030]
// Decompiled from bool __thiscall CAnimalMgr::CheckButterflyUndergroundFast(CAnimalMgr *this, int a2, int a3)

bool  CAnimalMgr::CheckButterflyUndergroundFast(int,int) {
  
  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalMgr.cpp", 878, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  return (CWorldManager::Ground(a2, a3) & 0xF0) == 16;
}


// address=[0x14dc0a0]
// Decompiled from // public: bool __thiscall CAnimalMgr::IsBirdLand(int,int)
char __thiscall CAnimalMgr::IsBirdLand(char *this, int a2, int a3)

bool  CAnimalMgr::IsBirdLand(int,int) {
  
  int v4; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-4h]

  v4 = Y16X16::PackXYFast(a2, a3);
  for ( i = 0; i < std::vector<unsigned int>::size(this + 324); ++i )
  {
    if ( *(_DWORD *)std::vector<unsigned int>::operator[](i) == v4 )
      return 1;
  }
  return 0;
}


// address=[0x14dc110]
// Decompiled from char __thiscall CAnimalMgr::CheckBirdUnderground(CAnimalMgr *this, int a2, int a3)

bool  CAnimalMgr::CheckBirdUnderground(int,int) {
  
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalMgr.cpp", 916, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  v4 = CWorldManager::Index(a2, a3);
  if ( CWorldManager::FlagBits(v4, 4u) )
    return 0;
  if ( (CWorldManager::Ground(a2, a3) & 0xF0) != 0x10
    && (CWorldManager::Ground(a2, a3) & 0xF0) != 0x20
    && (CWorldManager::Ground(a2, a3) & 0xF0) != 0x70 )
  {
    return 0;
  }
  for ( i = 0; i < 12; ++i )
  {
    v5 = a2 + CSpiralOffsets::DeltaX(i + 7);
    v6 = a3 + CSpiralOffsets::DeltaY(i + 7);
    if ( (unsigned __int8)CWorldManager::InWorld(v5, v6)
      && ((CWorldManager::Ground(v5, v6) & 0xF0) == 0x10
       || (CWorldManager::Ground(v5, v6) & 0xF0) == 0x20
       || (CWorldManager::Ground(v5, v6) & 0xF0) == 0x70) )
    {
      return 1;
    }
  }
  return 0;
}


// address=[0x14dc290]
// Decompiled from char __thiscall CAnimalMgr::IsSeagullLand(CAnimalMgr *this, int a2, int a3)

bool  CAnimalMgr::IsSeagullLand(int,int) {
  
  unsigned int i; // eax
  int v5; // [esp+0h] [ebp-Ch]
  int v6; // [esp+0h] [ebp-Ch]
  int v8; // [esp+4h] [ebp-8h]
  unsigned int v9; // [esp+8h] [ebp-4h]

  v5 = Y16X16::PackXYFast(a2, a3);
  v9 = 0;
  for ( i = std::vector<unsigned int>::size((char *)this + 340, v5, this);
        v9 < i;
        i = std::vector<unsigned int>::size(v8 + 340, v6, v8) )
  {
    if ( *(_DWORD *)std::vector<unsigned int>::operator[](v9) == v6 )
      return 1;
    ++v9;
  }
  return 0;
}


// address=[0x14dc300]
// Decompiled from // public: bool __thiscall CAnimalMgr::CheckSeagullUnderground(int,int)
char __stdcall CAnimalMgr::CheckSeagullUnderground(int a1, int a2)

bool  CAnimalMgr::CheckSeagullUnderground(int,int) {
  
  int v3; // [esp+4h] [ebp-14h]
  int v4; // [esp+8h] [ebp-10h]
  int LandscapePtr; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v7; // [esp+14h] [ebp-4h]
  int v8; // [esp+14h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalMgr.cpp", 980, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  v7 = CWorldManager::Index(a1, a2);
  LandscapePtr = CWorldManager::GetLandscapePtr();
  if ( (CWorldManager::Ground(v7) & 0xF0) != 0x30 && (CWorldManager::Ground(v7) & 0xF0) != 0 )
    return 0;
  if ( (*(_BYTE *)(LandscapePtr + 4 * v7 + 2) & 0x20) != 0 )
    return 0;
  for ( i = 0; i < 12; ++i )
  {
    v3 = a1 + CSpiralOffsets::DeltaX(i + 7);
    v4 = a2 + CSpiralOffsets::DeltaY(i + 7);
    v8 = CWorldManager::Index(v3, v4);
    if ( CWorldManager::InWorld(v8)
      && ((CWorldManager::Ground(v8) & 0xF0) == 0x30 || (CWorldManager::Ground(v8) & 0xF0) == 0)
      && (*(_BYTE *)(LandscapePtr + 4 * v8 + 2) & 0x20) == 0 )
    {
      return 1;
    }
  }
  return 0;
}


// address=[0x14dc460]
// Decompiled from char __thiscall CAnimalMgr::CheckSeagullUndergroundAddPosition(CAnimalMgr *this, int a2, int a3)

bool  CAnimalMgr::CheckSeagullUndergroundAddPosition(int,int) {
  
  int v4; // [esp+4h] [ebp-14h]
  int v5; // [esp+8h] [ebp-10h]
  int LandscapePtr; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v8; // [esp+14h] [ebp-4h]
  int v9; // [esp+14h] [ebp-4h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a2, a3)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalMgr.cpp", 1026, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  LandscapePtr = CWorldManager::GetLandscapePtr();
  v8 = CWorldManager::Index(a2, a3);
  if ( (CWorldManager::Ground(v8) & 0xF0) != 0 || (*(_BYTE *)(LandscapePtr + 4 * v8 + 2) & 0x20) != 0 )
    return 0;
  for ( i = 0; i < 12; ++i )
  {
    v4 = a2 + CSpiralOffsets::DeltaX(i + 7);
    v5 = a3 + CSpiralOffsets::DeltaY(i + 7);
    v9 = CWorldManager::Index(v4, v5);
    if ( CWorldManager::InWorld(v9)
      && (CWorldManager::Ground(v9) & 0xF0) == 0
      && (*(_BYTE *)(LandscapePtr + 4 * v9 + 2) & 0x20) == 0 )
    {
      return 1;
    }
  }
  return 0;
}


// address=[0x14dc590]
// Decompiled from void __thiscall CAnimalMgr::Store(CAnimalMgr *this, struct S4::CMapFile *a2)

void  CAnimalMgr::Store(class S4::CMapFile &) {
  
  std::strstreambuf *v2; // eax
  void *v3; // eax
  int v4; // [esp+0h] [ebp-32Ch] BYREF
  _DWORD v5[43]; // [esp+10h] [ebp-31Ch] BYREF
  size_t Size; // [esp+BCh] [ebp-270h]
  void *Src; // [esp+C0h] [ebp-26Ch]
  int v8; // [esp+C4h] [ebp-268h]
  unsigned __int8 *v9; // [esp+C8h] [ebp-264h]
  int v10; // [esp+CCh] [ebp-260h]
  unsigned __int8 *v11; // [esp+D0h] [ebp-25Ch]
  int UsedId; // [esp+D4h] [ebp-258h]
  int v13; // [esp+D8h] [ebp-254h] BYREF
  int v14; // [esp+DCh] [ebp-250h]
  unsigned __int8 *v15; // [esp+E0h] [ebp-24Ch]
  int v16; // [esp+E4h] [ebp-248h] BYREF
  unsigned __int8 *v17; // [esp+E8h] [ebp-244h]
  int i; // [esp+ECh] [ebp-240h]
  int *v19; // [esp+31Ch] [ebp-10h]
  int v20; // [esp+328h] [ebp-4h]

  v19 = &v4;
  v5[42] = this;
  std::ostrstream::ostrstream(0, 0x40000, 0, 2, 1);
  v20 = 0;
  std::ios_base::exceptions((std::ios_base *)((char *)v5 + *(_DWORD *)(v5[0] + 4)), 6);
  LOBYTE(v20) = 1;
  v13 = 1;
  operator^<unsigned int>((struct std::ostream *)v5, &v13);
  UsedId = CMapObjectMgr::LastUsedId();
  v14 = UsedId;
  v16 = 0;
  for ( i = 0; i <= v14; ++i )
  {
    v11 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(i);
    v15 = v11;
    if ( v11 )
    {
      v10 = IEntity::ObjType(v15);
      if ( v10 == 128 )
        ++v16;
    }
  }
  operator^<unsigned int>((struct std::ostream *)v5, &v16);
  for ( i = 0; i <= v14; ++i )
  {
    v9 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(i);
    v17 = v9;
    if ( v9 )
    {
      v8 = IEntity::ObjType(v17);
      if ( v8 == 128 )
        (*(void (__thiscall **)(unsigned __int8 *, _DWORD *))(*(_DWORD *)v17 + 4))(v17, v5);
    }
  }
  std::ostream::put(0);
  v20 = 0;
  std::ostrstream::freeze((std::ostrstream *)v5, 1);
  v2 = std::ostrstream::rdbuf((std::ostrstream *)v5);
  Size = std::strstreambuf::pcount(v2);
  std::ostrstream::str((CDaoIndexFieldInfo *)v5);
  Src = v3;
  S4::CMapFile::SaveChunk(165, 0, Size, v3, 0);
  std::ostrstream::freeze((std::ostrstream *)v5, 0);
  v20 = -1;
  std::ostrstream::`vbase destructor'((std::ostrstream *)v5);
}


// address=[0x14dc840]
// Decompiled from void __thiscall CAnimalMgr::Load(CAnimalMgr *this, struct S4::CMapFile *a2)

void  CAnimalMgr::Load(class S4::CMapFile &) {
  
  int v2; // [esp+0h] [ebp-FCh]
  _DWORD v3[42]; // [esp+4h] [ebp-F8h] BYREF
  unsigned int v4; // [esp+ACh] [ebp-50h]
  int v5; // [esp+B0h] [ebp-4Ch]
  int v6; // [esp+B4h] [ebp-48h] BYREF
  int v7[2]; // [esp+B8h] [ebp-44h] BYREF
  unsigned int v8; // [esp+C0h] [ebp-3Ch] BYREF
  int pExceptionObject; // [esp+C4h] [ebp-38h] BYREF
  char *Str; // [esp+C8h] [ebp-34h]
  unsigned int i; // [esp+CCh] [ebp-30h]
  _BYTE v12[28]; // [esp+D0h] [ebp-2Ch] BYREF
  int v13; // [esp+F8h] [ebp-4h]

  v7[1] = (int)this;
  CAnimalMgr::Clear(this);
  CTrace::Print("DecoObjMgr load");
  v7[0] = 0;
  Str = (char *)S4::CMapFile::LoadChunk(a2, 0xA5u, 0, v7, 0);
  if ( Str )
  {
    std::string::string(v12, Str);
    v13 = 0;
    std::istringstream::istringstream(v12, 1, 1);
    LOBYTE(v13) = 1;
    v4 = std::ios_base::exceptions((char *)v3 + *(_DWORD *)(v3[0] + 4));
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), 6);
    operator^<unsigned int>(v3, &v6);
    v5 = v6;
    if ( v6 != 1 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CAnimalMgr");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    v8 = 0;
    operator^<unsigned int>(v3, &v8);
    for ( i = 0; i < v8; ++i )
      CPersistence::New(v3, v2);
    std::ios_base::exceptions((std::ios_base *)((char *)v3 + *(_DWORD *)(v3[0] + 4)), v4);
    LOBYTE(v13) = 0;
    std::istringstream::`vbase destructor'(v3);
    v13 = -1;
    std::string::~string(v12);
  }
}


// address=[0x14dc9f0]
// Decompiled from char __thiscall CAnimalMgr::IsHuntable(CAnimalMgr *this, int a2)

bool  CAnimalMgr::IsHuntable(int) {
  
  struct SAnimalData *AnimalDataPtr; // [esp+4h] [ebp-4h]

  AnimalDataPtr = CAnimalMgr::GetAnimalDataPtr(this, a2);
  if ( AnimalDataPtr )
    return *((_BYTE *)AnimalDataPtr + 4);
  else
    return 0;
}


// address=[0x14dca20]
// Decompiled from int *__thiscall CAnimalMgr::GetAnimalDataPtr(CAnimalMgr *this, unsigned int a2)

struct SAnimalData *  CAnimalMgr::GetAnimalDataPtr(int) {
  
  if ( a2 < 0x12 )
    return &CAnimalMgr::m_asAnimalData[10 * a2];
  else
    return 0;
}


// address=[0x14dca50]
// Decompiled from int *__thiscall CAnimalMgr::GetAnimalEffectDataPtr(CAnimalMgr *this, unsigned int a2)

struct SAnimalData *  CAnimalMgr::GetAnimalEffectDataPtr(int) {
  
  if ( a2 < 8 )
    return &CAnimalMgr::m_asAnimalEffectData[10 * a2];
  else
    return 0;
}


// address=[0x14dfeb0]
// Decompiled from int __cdecl CAnimalMgr::Animal(int a1)

static class CAnimal & __cdecl CAnimalMgr::Animal(int) {
  
  return CMapObjectMgr::EntityPtr(a1);
}


// address=[0x15787b0]
// Decompiled from int __cdecl CAnimalMgr::GetAnimalPtr(int a1)

static class CAnimal * __cdecl CAnimalMgr::GetAnimalPtr(int) {
  
  return CMapObjectMgr::EntityPtr(a1);
}


// address=[0x14dca80]
// Decompiled from int __thiscall CAnimalMgr::LoadAnimalData(CAnimalMgr *this)

void  CAnimalMgr::LoadAnimalData(void) {
  
  int result; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  char v6; // al
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  char v11; // al
  int v12; // [esp+10h] [ebp-48h]
  bool v13; // [esp+14h] [ebp-44h]
  bool v14; // [esp+18h] [ebp-40h]
  bool v15; // [esp+1Ch] [ebp-3Ch]
  bool v16; // [esp+20h] [ebp-38h]
  void *v17; // [esp+24h] [ebp-34h]
  void *v18; // [esp+28h] [ebp-30h]
  void *v19; // [esp+2Ch] [ebp-2Ch]
  void *v20; // [esp+30h] [ebp-28h]
  int v21; // [esp+34h] [ebp-24h]
  int v22; // [esp+38h] [ebp-20h]
  int k; // [esp+3Ch] [ebp-1Ch]
  int j; // [esp+40h] [ebp-18h]
  int v25; // [esp+44h] [ebp-14h]
  const char *AnimalName; // [esp+48h] [ebp-10h]
  const char *v27; // [esp+48h] [ebp-10h]
  int i; // [esp+50h] [ebp-8h] BYREF
  char v30; // [esp+56h] [ebp-2h]
  char v31; // [esp+57h] [ebp-1h]

  j__memset(CAnimalMgr::m_asAnimalData, 0, 0x2D0u);
  j__memset(CAnimalMgr::m_asAnimalEffectData, 0, 0x140u);
  *((_DWORD *)this + 64) = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
                             g_pCfgMgr,
                             "ANIMAL_DATA",
                             "MAX_ANIMALS",
                             1000);
  *((_DWORD *)this + 66) = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
                             g_pCfgMgr,
                             "ANIMAL_DATA",
                             "MAX_MYSTIC",
                             4);
  *((_DWORD *)this + 94) = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
                             g_pCfgMgr,
                             "ANIMAL_DATA",
                             "FISH_MIN",
                             2);
  *((_DWORD *)this + 58) = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
                             g_pCfgMgr,
                             "ANIMAL_DATA",
                             "PLAIN_TREES",
                             1);
  *((_DWORD *)this + 59) = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
                             g_pCfgMgr,
                             "ANIMAL_DATA",
                             "LIGHT_TREES",
                             4);
  *((_DWORD *)this + 60) = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
                             g_pCfgMgr,
                             "ANIMAL_DATA",
                             "DEEP_TREES",
                             8);
  *((_DWORD *)this + 61) = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
                             g_pCfgMgr,
                             "ANIMAL_DATA",
                             "LAND_POP",
                             8);
  *((_DWORD *)this + 67) = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
                             g_pCfgMgr,
                             "ANIMAL_DATA",
                             "AMOUNT_BUTTERFLY",
                             0);
  *((_DWORD *)this + 68) = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
                             g_pCfgMgr,
                             "ANIMAL_DATA",
                             "AMOUNT_BIRDS",
                             0);
  *((_DWORD *)this + 69) = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
                             g_pCfgMgr,
                             "ANIMAL_DATA",
                             "AMOUNT_SEAGULL",
                             0);
  *((_DWORD *)this + 70) = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
                             g_pCfgMgr,
                             "ANIMAL_DATA",
                             "AMOUNT_DUCK",
                             0);
  v25 = (*(int (__thiscall **)(void *))(*(_DWORD *)g_pTiling + 52))(g_pTiling) / 25600;
  if ( !v25 )
    v25 = 1;
  *((_DWORD *)this + 67) *= v25;
  *((_DWORD *)this + 68) *= v25;
  *((_DWORD *)this + 69) *= v25;
  result = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
             g_pCfgMgr,
             "ANIMAL_DATA",
             "SEARCH_RAD",
             10);
  v12 = result;
  for ( i = 0; i < 17; ++i )
  {
    v20 = operator new(0x10u);
    if ( v20 )
      v19 = std::vector<int>::vector<int>(v20);
    else
      v19 = 0;
    *((_DWORD *)this + i + 24) = v19;
    v18 = operator new(0x10u);
    if ( v18 )
      v17 = std::vector<int>::vector<int>(v18);
    else
      v17 = 0;
    *((_DWORD *)this + i + 41) = v17;
    result = i + 1;
  }
  for ( i = 1; i < 18; ++i )
  {
    AnimalName = CS4DefineNames::GetAnimalName(i);
    if ( ((unsigned __int8 (__thiscall *)(CConfigManager *, const char *, _DWORD))g_pCfgMgr->j_?DoesExist@CConfigManager@@UAE_NPBD0@Z)(
           g_pCfgMgr,
           AnimalName,
           0) )
    {
      j__memset(&CAnimalMgr::m_asAnimalData[10 * i], 0, 0x28u);
      v2 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
             g_pCfgMgr,
             AnimalName,
             "RACE",
             -1);
      dword_4032AE4[10 * i] = v2;
      if ( dword_4032AE4[10 * i] <= -1 )
        goto LABEL_23;
      result = CPlayerManager::LastPlayerId();
      v31 = 0;
      for ( j = result; j >= 1; --j )
      {
        result = CPlayerManager::Race(j);
        if ( result == dword_4032AE4[10 * i] )
        {
          v31 = 1;
          break;
        }
      }
      if ( v31 )
      {
LABEL_23:
        v3 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
               g_pCfgMgr,
               AnimalName,
               "LAND_TYPE",
               0);
        CAnimalMgr::m_asAnimalData[10 * i] = v3;
        v16 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
                g_pCfgMgr,
                AnimalName,
                "HUNTABLE",
                0) != 0;
        byte_4032AD4[40 * i] = v16;
        v15 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
                g_pCfgMgr,
                AnimalName,
                "RUNAWAY",
                0) != 0;
        byte_4032AD5[40 * i] = v15;
        v4 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
               g_pCfgMgr,
               AnimalName,
               "SPEED_DIVIDER",
               0);
        dword_4032AE0[10 * i] = v4;
        v5 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
               g_pCfgMgr,
               AnimalName,
               "SOUND",
               0);
        dword_4032AF0[10 * i] = v5;
        if ( dword_4032AF0[10 * i] == -1 )
          dword_4032AF0[10 * i] = 0;
        v6 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
               g_pCfgMgr,
               AnimalName,
               "SOUND_INTERVAL",
               100);
        byte_4032AF4[40 * i] = v6;
        dword_4032AE8[10 * i] = v12;
        std::vector<int>::push_back(&i);
        v22 = CAnimalMgr::m_asAnimalData[10 * i];
        switch ( v22 )
        {
          case 2:
            dword_4032AD8[10 * i] = *((_DWORD *)this + 58);
            result = 40 * i;
            dword_4032ADC[10 * i] = *((_DWORD *)this + 59) - 1;
            break;
          case 3:
            dword_4032AD8[10 * i] = *((_DWORD *)this + 59) - 1;
            result = 40 * i;
            dword_4032ADC[10 * i] = *((_DWORD *)this + 60) - 1;
            break;
          case 4:
            result = *((_DWORD *)this + 60);
            dword_4032AD8[10 * i] = result;
            dword_4032ADC[10 * i] = 255;
            break;
          default:
            dword_4032AD8[10 * i] = 0;
            result = 40 * i;
            dword_4032ADC[10 * i] = 0;
            break;
        }
      }
    }
    else
    {
      result = CTrace::Print("CAnimalMgr::LoadAnimalData : No config data for animal %s available", AnimalName);
    }
  }
  for ( i = 0; i < 8; ++i )
  {
    v27 = (&off_3775B54)[2 * i];
    if ( ((unsigned __int8 (__thiscall *)(CConfigManager *, const char *, _DWORD))g_pCfgMgr->j_?DoesExist@CConfigManager@@UAE_NPBD0@Z)(
           g_pCfgMgr,
           v27,
           0) )
    {
      j__memset(&CAnimalMgr::m_asAnimalEffectData[10 * i], 0, 0x28u);
      v7 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
             g_pCfgMgr,
             v27,
             "RACE",
             -1);
      dword_4032DB4[10 * i] = v7;
      if ( dword_4032DB4[10 * i] <= -1 )
        goto LABEL_44;
      result = CPlayerManager::LastPlayerId();
      v30 = 0;
      for ( k = result; k >= 1; --k )
      {
        result = CPlayerManager::Race(k);
        if ( result == dword_4032DB4[10 * i] )
        {
          v30 = 1;
          break;
        }
      }
      if ( v30 )
      {
LABEL_44:
        v8 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
               g_pCfgMgr,
               v27,
               "LAND_TYPE",
               0);
        CAnimalMgr::m_asAnimalEffectData[10 * i] = v8;
        v14 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
                g_pCfgMgr,
                v27,
                "HUNTABLE",
                0) != 0;
        byte_4032DA4[40 * i] = v14;
        v13 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
                g_pCfgMgr,
                v27,
                "RUNAWAY",
                0) != 0;
        byte_4032DA5[40 * i] = v13;
        v9 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
               g_pCfgMgr,
               v27,
               "SPEED_DIVIDER",
               0);
        dword_4032DB0[10 * i] = v9;
        v10 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, _DWORD))g_pCfgMgr->GetIntValueNoAdd)(
                g_pCfgMgr,
                v27,
                "SOUND",
                0);
        dword_4032DC0[10 * i] = v10;
        if ( dword_4032DC0[10 * i] == -1 )
          dword_4032DC0[10 * i] = 0;
        v11 = ((int (__thiscall *)(CConfigManager *, const char *, const char *, int))g_pCfgMgr->GetIntValueNoAdd)(
                g_pCfgMgr,
                v27,
                "SOUND_INTERVAL",
                100);
        byte_4032DC4[40 * i] = v11;
        dword_4032DB8[10 * i] = v12;
        std::vector<int>::push_back(&i);
        v21 = CAnimalMgr::m_asAnimalEffectData[10 * i];
        switch ( v21 )
        {
          case 2:
            dword_4032DA8[10 * i] = *((_DWORD *)this + 58);
            result = 40 * i;
            dword_4032DAC[10 * i] = *((_DWORD *)this + 59) - 1;
            break;
          case 3:
            dword_4032DA8[10 * i] = *((_DWORD *)this + 59) - 1;
            result = 40 * i;
            dword_4032DAC[10 * i] = *((_DWORD *)this + 60) - 1;
            break;
          case 4:
            result = *((_DWORD *)this + 60);
            dword_4032DA8[10 * i] = result;
            dword_4032DAC[10 * i] = 255;
            break;
          default:
            dword_4032DA8[10 * i] = 0;
            result = 40 * i;
            dword_4032DAC[10 * i] = 0;
            break;
        }
      }
    }
    else
    {
      result = CTrace::Print("CAnimalMgr::LoadAnimalData : No config data for animal effect %s available", v27);
    }
  }
  return result;
}


// address=[0x14dd3d0]
// Decompiled from int __cdecl CAnimalMgr::InitAnimalJobs(struct CAnimal *a1, int a2)

static void __cdecl CAnimalMgr::InitAnimalJobs(class CAnimal *,int) {
  
  struct CEntityTask *v2; // eax
  char AnimalFrameCount; // al
  struct CEntityTask *v4; // eax
  char v5; // al
  struct CEntityTask *v6; // eax
  char v7; // al
  struct CEntityTask *v8; // eax
  int result; // eax
  char v10; // al
  struct CEntityTask *v11; // eax
  _BYTE v12[24]; // [esp+0h] [ebp-8Ch] BYREF
  _BYTE v13[24]; // [esp+18h] [ebp-74h] BYREF
  _BYTE v14[24]; // [esp+30h] [ebp-5Ch] BYREF
  _BYTE v15[24]; // [esp+48h] [ebp-44h] BYREF
  _BYTE v16[24]; // [esp+60h] [ebp-2Ch] BYREF
  int v17; // [esp+78h] [ebp-14h]
  unsigned int v18; // [esp+7Ch] [ebp-10h]
  unsigned int v19; // [esp+80h] [ebp-Ch]
  unsigned int v20; // [esp+84h] [ebp-8h]
  unsigned int v21; // [esp+88h] [ebp-4h]

  v21 = -1;
  v17 = a2 - 1;
  switch ( a2 )
  {
    case 1:
      v20 = 2;
      v19 = 1;
      v18 = 2;
      v21 = 3;
      break;
    case 2:
      v20 = 5;
      v19 = 4;
      v18 = 5;
      v21 = -1;
      break;
    case 3:
      v20 = 7;
      v19 = 6;
      v18 = 7;
      v21 = -1;
      break;
    case 4:
      v20 = 9;
      v19 = 8;
      v18 = 9;
      v21 = 11;
      break;
    case 5:
      v20 = 13;
      v19 = 12;
      v18 = 13;
      v21 = 15;
      break;
    case 6:
      v20 = 17;
      v19 = 16;
      v18 = 17;
      v21 = -1;
      break;
    case 7:
      v20 = 19;
      v19 = 18;
      v18 = 19;
      v21 = -1;
      break;
    case 8:
      v20 = 21;
      v19 = 20;
      v18 = 21;
      v21 = -1;
      break;
    case 9:
      v20 = 23;
      v19 = 22;
      v18 = 23;
      v21 = 24;
      break;
    case 13:
      v20 = 29;
      v19 = 30;
      v18 = 29;
      v21 = -1;
      break;
    case 14:
      v20 = 34;
      v19 = 35;
      v18 = 34;
      v21 = -1;
      break;
    case 16:
      v20 = 38;
      v19 = 37;
      v18 = 38;
      v21 = 39;
      break;
    case 17:
      v20 = 40;
      v19 = 41;
      v18 = 40;
      v21 = -1;
      break;
    default:
      break;
  }
  v2 = CEntityTask::CEntityTask((CEntityTask *)v16, 17, v20, 0, 0, -1, 1, -1, 1, 1, 0, 0, 0, 0);
  CAnimal::AddTask(a1, v2);
  AnimalFrameCount = CGfxManager::GetAnimalFrameCount((CGfxManager *)g_pGfxManager, v19);
  v4 = CEntityTask::CEntityTask((CEntityTask *)v15, 16, v19, 0, 0, -1, AnimalFrameCount, -1, 1, 1, 0, 0, 0, 0);
  CAnimal::AddTask(a1, v4);
  v5 = CGfxManager::GetAnimalFrameCount((CGfxManager *)g_pGfxManager, v20);
  v6 = CEntityTask::CEntityTask((CEntityTask *)v14, 6, v20, 0, 0, -1, v5, -1, 1, 1, 0, 0, 0, 0);
  CAnimal::AddTask(a1, v6);
  v7 = CGfxManager::GetAnimalFrameCount((CGfxManager *)g_pGfxManager, v18);
  v8 = CEntityTask::CEntityTask((CEntityTask *)v13, 6, v18, 0, 0, -1, v7, -1, 1, 1, 0, 0, 0, 0);
  result = CAnimal::AddTask(a1, v8);
  if ( v21 == -1 )
    return result;
  v10 = CGfxManager::GetAnimalFrameCount((CGfxManager *)g_pGfxManager, v21);
  v11 = CEntityTask::CEntityTask((CEntityTask *)v12, 27, v21, 0, 0, -1, v10, -1, 1, 1, 0, 0, 0, 0);
  return CAnimal::AddTask(a1, v11);
}


// address=[0x14dd710]
// Decompiled from char __thiscall CAnimalMgr::SpawnAnimal(CAnimalMgr *this, int a2, int a3)

void  CAnimalMgr::SpawnAnimal(int,int) {
  
  int v3; // edx
  int EntityIdVW; // eax
  unsigned int v5; // eax
  int v7; // [esp+8h] [ebp-1Ch]
  CAIResourceData *v8; // [esp+Ch] [ebp-18h]
  unsigned int v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+18h] [ebp-Ch]
  int v11; // [esp+1Ch] [ebp-8h]

  v11 = -1;
  v3 = 100 * CWarMap::NumberOfEntitiesVW(3, a2, a3);
  LOBYTE(EntityIdVW) = (_BYTE)this;
  if ( v3 > *((_DWORD *)this + 61) )
    return EntityIdVW;
  v8 = CAIResourceMap::ResourceDataVW(a2, a3);
  EntityIdVW = CWarMap::FirstEntityIdVW(2, a2, a3);
  if ( EntityIdVW <= 0 )
  {
    EntityIdVW = CAIResourceData::GroundInfo1(v8, 0);
    if ( EntityIdVW <= 100 )
    {
      EntityIdVW = CAIResourceData::GroundInfo1(v8, 1);
      if ( EntityIdVW > 100 )
      {
        EntityIdVW = CAIResourceData::ResourceAmount1(v8, 7);
        v7 = EntityIdVW;
        if ( EntityIdVW < *((_DWORD *)this + 60) )
        {
          if ( EntityIdVW < *((_DWORD *)this + 59) )
          {
            LOBYTE(EntityIdVW) = (_BYTE)this;
            if ( v7 < *((_DWORD *)this + 58) )
              v11 = 1;
            else
              v11 = 2;
          }
          else
          {
            v11 = 3;
          }
        }
        else
        {
          v11 = 4;
        }
      }
    }
    else
    {
      v11 = 8;
    }
  }
  else
  {
    v11 = 9;
  }
  if ( v11 < 0 )
    return EntityIdVW;
  EntityIdVW = std::vector<int>::size(*((_DWORD *)this + v11 + 24));
  v9 = EntityIdVW;
  if ( !EntityIdVW )
    return EntityIdVW;
  v5 = CStateGame::Rand(g_pGame);
  v10 = *(_DWORD *)std::vector<int>::operator[](v5 % v9);
  if ( v10 == 9 && (int)(CStateGame::Rand(g_pGame) % 0xAu) < 5 )
    v10 = 16;
  if ( !byte_4032AD4[40 * v10] )
  {
    EntityIdVW = *((_DWORD *)this + 63);
    if ( EntityIdVW >= *((_DWORD *)this + 65) )
      return EntityIdVW;
    if ( dword_4032AE4[10 * v10] >= 0 )
    {
      LOBYTE(EntityIdVW) = (_BYTE)this;
      if ( dword_4032AEC[10 * v10] >= *((_DWORD *)this + 66) )
        return EntityIdVW;
    }
  }
  LOBYTE(EntityIdVW) = v11 - 1;
  switch ( v11 )
  {
    case 2:
    case 3:
    case 4:
      LOBYTE(EntityIdVW) = CAnimalMgr::SpawnAnimalBehindTree(this, v10, a2, a3);
      break;
    case 8:
      LOBYTE(EntityIdVW) = CAnimalMgr::SpawnAnimalOnDarkLand(this, v10, a2, a3);
      break;
    case 9:
      LOBYTE(EntityIdVW) = CAnimalMgr::SpawnAnimalInTown(this, v10, a2, a3);
      break;
    default:
      return EntityIdVW;
  }
  return EntityIdVW;
}


// address=[0x14dd980]
// Decompiled from int __cdecl CAnimalMgr::Create(int a1, int a2, int a3)

static int __cdecl CAnimalMgr::Create(int,int,int) {
  
  int FreeSlot; // [esp+8h] [ebp-1Ch]
  CLandAnimal *v5; // [esp+10h] [ebp-14h]
  CLandAnimal *v6; // [esp+14h] [ebp-10h]

  if ( !(unsigned __int8)CWorldManager::InWorld(a1, a2)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalMgr.cpp", 1670, "g_cWorld.InWorld( _iX, _iY )") == 1 )
  {
    __debugbreak();
  }
  if ( (a3 <= 0 || a3 >= 18)
    && BBSupportDbgReport(2, "MapObjects\\Animal\\AnimalMgr.cpp", 1671, "_iAnimalType>0 && _iAnimalType<ANIMAL_MAX") == 1 )
  {
    __debugbreak();
  }
  FreeSlot = CMapObjectMgr::GetFreeSlot(0);
  v6 = (CLandAnimal *)CLandAnimal::operator new(0xB0u);
  if ( v6 )
    v5 = CLandAnimal::CLandAnimal(v6, a1, a2, a3, FreeSlot);
  else
    v5 = 0;
  CAnimalMgr::InitAnimalJobs(v5, a3);
  CLandAnimal::Init(v5, (struct SAnimalData *)&CAnimalMgr::m_asAnimalData[10 * a3]);
  return FreeSlot;
}


// address=[0x14ddaa0]
// Decompiled from void __thiscall CAnimalMgr::ShowEffect(CAnimalMgr *this)

void  CAnimalMgr::ShowEffect(void) {
  
  int OutputWidth; // eax
  unsigned int v2; // eax
  unsigned int v3; // et2
  int v4; // [esp-Ch] [ebp-28h]
  Squares *v5; // [esp+8h] [ebp-14h] BYREF
  Squares *v6; // [esp+Ch] [ebp-10h] BYREF
  CAnimalMgr *v7; // [esp+10h] [ebp-Ch]
  int v8; // [esp+14h] [ebp-8h]
  int v9; // [esp+18h] [ebp-4h]

  v7 = this;
  v4 = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine) / 2;
  OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
  IGfxEngine::GetClosestMapPoint((IGfxEngine *)g_pGfxEngine, OutputWidth / 2, v4, (int *)&v6, (int *)&v5);
  v8 = Squares::XYToVW(v6) - 4;
  v9 = Squares::XYToVW(v5) - 4;
  v2 = CAnimalMgr::EffectRandomNumber(v7);
  v8 += v2 % 8;
  v3 = CAnimalMgr::EffectRandomNumber(v7) % 8;
  v9 += v3;
  if ( v8 >= 0
    && v8 < *((_DWORD *)v7 + 71)
    && v9 >= 0
    && v9 < *((_DWORD *)v7 + 72)
    && 2 * ITiling::NumberOfWaterElementsDiv2VW(v8, v9) > 200 )
  {
    CAnimalMgr::ShowWaterEffect(v7, v8, v9);
  }
}


// address=[0x14ddba0]
// Decompiled from char __thiscall CAnimalMgr::ShowWaterEffect(CAnimalMgr *this, int a2, int a3)

void  CAnimalMgr::ShowWaterEffect(int,int) {
  
  unsigned int v3; // esi
  int DistanceToNearestShip; // eax
  unsigned int v5; // eax
  int v6; // ecx
  char v7; // al
  unsigned int v9; // [esp+8h] [ebp-24h]
  unsigned int v10; // [esp+Ch] [ebp-20h]
  unsigned int v11; // [esp+10h] [ebp-1Ch]
  int v12; // [esp+14h] [ebp-18h]
  int v13; // [esp+18h] [ebp-14h]
  unsigned int v14; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int j; // [esp+20h] [ebp-Ch]
  signed int v17; // [esp+24h] [ebp-8h]
  unsigned int v18; // [esp+24h] [ebp-8h]

  v13 = CWorldManager::Width(this) * 16 * a3 + 16 * a2;
  v3 = CAnimalMgr::EffectRandomNumber(this);
  if ( v3 >= CRandom16::PercentValue(1u) )
  {
    DistanceToNearestShip = std::vector<int>::size(*((_DWORD *)this + 31));
    v18 = DistanceToNearestShip;
    if ( !DistanceToNearestShip )
      return DistanceToNearestShip;
    v5 = CAnimalMgr::EffectRandomNumber(this);
    v17 = *(_DWORD *)std::vector<int>::operator[](v5 % v18);
    v11 = CAnimalMgr::EffectRandomNumber(this) % 6;
  }
  else
  {
    v17 = 11;
    v11 = 2;
  }
  v9 = CAnimalMgr::EffectRandomNumber(this) % 0x10;
  v10 = CAnimalMgr::EffectRandomNumber(this) % 0x10;
  v14 = v13 + v9 + v10 * CWorldManager::Width(16);
  for ( i = 0; i < 5; ++i )
  {
    for ( j = 0; j < 5; ++j )
    {
      v12 = i * CWorldManager::Width(v6) + j + v14;
      LOBYTE(DistanceToNearestShip) = CWaterFlags::IsWater(v12);
      if ( !(_BYTE)DistanceToNearestShip )
        return DistanceToNearestShip;
      LOBYTE(DistanceToNearestShip) = CWaterFlags::IsBlockedWater(v12);
      if ( (_BYTE)DistanceToNearestShip )
        return DistanceToNearestShip;
      v7 = CWaterFlags::WaterFlags(v12);
      DistanceToNearestShip = CWaterFlags::WaterFlagsGetDistanceToNearestShip(v7);
      if ( DistanceToNearestShip != -1 )
        return DistanceToNearestShip;
    }
  }
  LOBYTE(DistanceToNearestShip) = CAnimalMgr::AddAnimalAsEffect(this, 16 * a2 + v9 + 2, 16 * a3 + v10 + 2, v11, v17);
  return DistanceToNearestShip;
}


// address=[0x14ddd50]
// Decompiled from int __thiscall CAnimalMgr::ShowFishResources(CAnimalMgr *this)

void  CAnimalMgr::ShowFishResources(void) {
  
  int OutputWidth; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  int result; // eax
  unsigned int v5; // et2
  int v6; // [esp-Ch] [ebp-3Ch]
  unsigned int v7; // [esp+4h] [ebp-2Ch]
  int v8; // [esp+8h] [ebp-28h]
  CAIResourceData *v9; // [esp+10h] [ebp-20h]
  char *v10; // [esp+14h] [ebp-1Ch]
  int v11; // [esp+18h] [ebp-18h]
  int j; // [esp+20h] [ebp-10h] BYREF
  int v14; // [esp+24h] [ebp-Ch]
  int i; // [esp+28h] [ebp-8h] BYREF
  int v16; // [esp+2Ch] [ebp-4h]

  v11 = CWorldManager::Width(this);
  v6 = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine) / 2;
  OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
  IGfxEngine::GetClosestMapPoint((IGfxEngine *)g_pGfxEngine, OutputWidth / 2, v6, &j, &i);
  v14 = Squares::XYToVW((Squares *)j) - 2;
  v16 = Squares::XYToVW((Squares *)i) - 2;
  v2 = CAnimalMgr::EffectRandomNumber(this);
  v14 += v2 % 4;
  v3 = CAnimalMgr::EffectRandomNumber(this);
  v5 = v3 % 4;
  result = v3 / 4;
  v16 += v5;
  if ( v14 < 0 )
    return result;
  result = v14;
  if ( v14 >= *((_DWORD *)this + 71) || v16 < 0 || v16 >= *((_DWORD *)this + 72) )
    return result;
  v9 = CAIResourceMap::ResourceDataVW(v14, v16);
  result = CAIResourceData::ResourceAmount1(v9, 0);
  if ( result <= 0 )
    return result;
  result = v11 * 16 * v16;
  v8 = result + 16 * v14;
  for ( i = 0; i < 16; ++i )
  {
    for ( j = 0; j < 16; ++j )
    {
      v10 = (char *)(v11 * i + j + v8);
      v7 = CAnimalMgr::EffectRandomNumber(this) % 6;
      result = CWorldManager::ResourceAmount((int)v10, 0);
      if ( result > *((_DWORD *)this + 94) )
      {
        result = CWorldManager::FlagBits(v10, 4u);
        if ( !result )
          return CAnimalMgr::AddAnimalAsEffect(this, j + 16 * v14, i + 16 * v16, v7, 15);
      }
    }
  }
  return result;
}


// address=[0x14ddf20]
// Decompiled from int __thiscall CAnimalMgr::CountBuildingSquares(CAnimalMgr *this, int a2, int a3)

int  CAnimalMgr::CountBuildingSquares(int,int) {
  
  int i; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  for ( i = -1; i < 2; ++i )
  {
    if ( CWarMap::FirstEntityIdVW(2, i + a2, a3 - 1) > 0 )
      ++v5;
    if ( CWarMap::FirstEntityIdVW(2, i + a2, a3) > 0 )
      ++v5;
    if ( CWarMap::FirstEntityIdVW(2, i + a2, a3 + 1) > 0 )
      ++v5;
  }
  return v5;
}


// address=[0x14ddfc0]
// Decompiled from bool __thiscall CAnimalMgr::IsTileFree(CAnimalMgr *this, int a2)

bool  CAnimalMgr::IsTileFree(int) {
  
  return !(unsigned __int8)CWorldManager::IsBlockedLand(a2)
      && CWorldManager::ObjectId(a2) <= 0
      && CWorldManager::MapObjectId(a2) <= 0;
}


// address=[0x14de020]
// Decompiled from char __thiscall CAnimalMgr::IsLandscapeAround(_DWORD *this, int a2, int a3, int a4)

bool  CAnimalMgr::IsLandscapeAround(enum T_RESOURCE_LANDTYPE,int,int) {
  
  Squares *v6; // [esp+4h] [ebp-Ch]
  Squares *v7; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 6; ++i )
  {
    v6 = (Squares *)(g_sNeighborPoints[2 * i] + a3);
    v7 = (Squares *)(dword_37D8C0C[2 * i] + a4);
    if ( (int)v7 >= 0
      && (int)v7 <= this[71]
      && (int)v6 >= 0
      && (int)v6 <= this[72]
      && CAIResourceMap::IsOfLandtype(a2, v6, v7) )
    {
      return 1;
    }
  }
  return 0;
}


// address=[0x14de0b0]
// Decompiled from int __thiscall CAnimalMgr::AddButterflies(CAnimalMgr *this)

void  CAnimalMgr::AddButterflies(void) {
  
  int result; // eax
  unsigned int v2; // esi
  Y16X16 **v3; // eax
  void *v4; // eax
  unsigned int v5; // [esp-Ch] [ebp-3Ch]
  unsigned int v6; // [esp-8h] [ebp-38h]
  unsigned int v7; // [esp+4h] [ebp-2Ch]
  unsigned int v8; // [esp+Ch] [ebp-24h]
  int v9; // [esp+10h] [ebp-20h]
  unsigned int v10; // [esp+14h] [ebp-1Ch]
  unsigned int v11; // [esp+18h] [ebp-18h] BYREF
  unsigned int v12; // [esp+1Ch] [ebp-14h] BYREF
  int v13; // [esp+20h] [ebp-10h]
  int i; // [esp+24h] [ebp-Ch]
  CAnimalMgr *v15; // [esp+28h] [ebp-8h]
  char v16; // [esp+2Fh] [ebp-1h]

  v15 = this;
  if ( *((_DWORD *)this + 67) >= (unsigned int)std::vector<unsigned int>::size((char *)this + 292) )
    v13 = std::vector<unsigned int>::size((char *)v15 + 292);
  else
    v13 = *((_DWORD *)v15 + 67);
  v9 = v13;
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= v9 )
      break;
    v2 = CAnimalMgr::EffectRandomNumber(v15);
    v8 = v2 % std::vector<unsigned int>::size((char *)v15 + 292);
    v3 = (Y16X16 **)std::vector<unsigned int>::operator[](v8);
    Y16X16::UnpackXYFast(*v3, &v11, (int *)&v12);
    v10 = CAnimalEffect::AddButterfly(*((CRandom16 ***)v15 + 97), v11, v12);
    if ( v10 )
    {
      v7 = CAnimalMgr::EffectRandomNumber(v15) % 0x14;
      v6 = v12;
      v5 = v11;
      v4 = (void *)CLogic::FutureEvents(g_pLogic);
      v16 = IFutureEvents::AddFutureEvent16(v4, 7, v7, 0, v10, v5, v6, 0);
    }
  }
  return result;
}


// address=[0x14de1d0]
// Decompiled from int __thiscall CAnimalMgr::AddBirds(CAnimalEffect **this)

void  CAnimalMgr::AddBirds(void) {
  
  int result; // eax
  unsigned int v2; // esi
  int v3; // eax
  int v4; // eax
  void *v5; // eax
  unsigned int v6; // [esp-10h] [ebp-44h]
  unsigned int v7; // [esp-Ch] [ebp-40h]
  unsigned int v8; // [esp-8h] [ebp-3Ch]
  unsigned int v9; // [esp+4h] [ebp-30h]
  Squares *v10; // [esp+8h] [ebp-2Ch] BYREF
  Squares *v11; // [esp+Ch] [ebp-28h] BYREF
  Y16X16 *v12; // [esp+10h] [ebp-24h]
  unsigned int v13; // [esp+14h] [ebp-20h]
  int v14; // [esp+18h] [ebp-1Ch]
  int i; // [esp+1Ch] [ebp-18h]
  int v16; // [esp+20h] [ebp-14h]
  int v17; // [esp+24h] [ebp-10h]
  int j; // [esp+28h] [ebp-Ch]
  CAnimalEffect **v19; // [esp+2Ch] [ebp-8h]
  char v20; // [esp+32h] [ebp-2h]
  char v21; // [esp+33h] [ebp-1h]

  v19 = this;
  result = std::vector<unsigned int>::size(this + 81);
  if ( result )
  {
    for ( i = 0; i < (int)v19[68]; ++i )
    {
      v21 = 0;
LABEL_5:
      while ( !v21 )
      {
        v2 = CAnimalMgr::EffectRandomNumber((CAnimalMgr *)v19);
        v13 = v2 % std::vector<unsigned int>::size(v19 + 81);
        v12 = *(Y16X16 **)std::vector<unsigned int>::operator[](v13);
        Y16X16::UnpackXYFast(v12, &v11, (int *)&v10);
        for ( j = 0; j < 256; ++j )
        {
          v17 = j >> 4;
          v16 = j & 0xF;
          v3 = Squares::VWToXY(v11);
          v16 += v3;
          v4 = Squares::VWToXY(v10);
          v17 += v4;
          if ( CAnimalMgr::CheckBirdUnderground((CAnimalMgr *)v19, v16, v17) )
          {
            v21 = 1;
            goto LABEL_5;
          }
        }
      }
      v14 = CAnimalEffect::AddBird(v19[97], v16, v17);
      if ( v14 )
      {
        v9 = CAnimalMgr::EffectRandomNumber((CAnimalMgr *)v19) % 0x14;
        v8 = v17;
        v7 = v16;
        v6 = v14;
        v5 = (void *)CLogic::FutureEvents(g_pLogic);
        v20 = IFutureEvents::AddFutureEvent16(v5, 7, v9, 0, v6, v7, v8, 0);
      }
      result = i + 1;
    }
  }
  return result;
}


// address=[0x14de350]
// Decompiled from int __thiscall CAnimalMgr::AddSeagulls(CAnimalEffect **this)

void  CAnimalMgr::AddSeagulls(void) {
  
  int result; // eax
  unsigned int v2; // esi
  int v3; // eax
  int v4; // eax
  void *v5; // eax
  unsigned int v6; // [esp-10h] [ebp-44h]
  unsigned int v7; // [esp-Ch] [ebp-40h]
  unsigned int v8; // [esp-8h] [ebp-3Ch]
  unsigned int v9; // [esp+4h] [ebp-30h]
  Squares *v10; // [esp+8h] [ebp-2Ch] BYREF
  Squares *v11; // [esp+Ch] [ebp-28h] BYREF
  Y16X16 *v12; // [esp+10h] [ebp-24h]
  unsigned int v13; // [esp+14h] [ebp-20h]
  int v14; // [esp+18h] [ebp-1Ch]
  int i; // [esp+1Ch] [ebp-18h]
  int v16; // [esp+20h] [ebp-14h]
  int v17; // [esp+24h] [ebp-10h]
  int j; // [esp+28h] [ebp-Ch]
  CAnimalEffect **v19; // [esp+2Ch] [ebp-8h]
  char v20; // [esp+32h] [ebp-2h]
  char v21; // [esp+33h] [ebp-1h]

  v19 = this;
  result = std::vector<unsigned int>::size(this + 85);
  if ( result )
  {
    for ( i = 0; i < (int)v19[69]; ++i )
    {
      v21 = 0;
LABEL_5:
      while ( !v21 )
      {
        v2 = CAnimalMgr::EffectRandomNumber((CAnimalMgr *)v19);
        v13 = v2 % std::vector<unsigned int>::size(v19 + 85);
        v12 = *(Y16X16 **)std::vector<unsigned int>::operator[](v13);
        Y16X16::UnpackXYFast(v12, &v11, (int *)&v10);
        for ( j = 0; j < 256; ++j )
        {
          v17 = j >> 4;
          v16 = j & 0xF;
          v3 = Squares::VWToXY(v11);
          v16 += v3;
          v4 = Squares::VWToXY(v10);
          v17 += v4;
          if ( CAnimalMgr::CheckSeagullUndergroundAddPosition((CAnimalMgr *)v19, v16, v17) )
          {
            v21 = 1;
            goto LABEL_5;
          }
        }
      }
      v14 = CAnimalEffect::AddSeagull(v19[97], v16, v17);
      if ( v14 )
      {
        v9 = CAnimalMgr::EffectRandomNumber((CAnimalMgr *)v19) % 0x14;
        v8 = v17;
        v7 = v16;
        v6 = v14;
        v5 = (void *)CLogic::FutureEvents(g_pLogic);
        v20 = IFutureEvents::AddFutureEvent16(v5, 7, v9, 0, v6, v7, v8, 0);
      }
      result = i + 1;
    }
  }
  return result;
}


// address=[0x14de4d0]
// Decompiled from int __thiscall CAnimalMgr::AddDucks(CAnimalEffect **this)

void  CAnimalMgr::AddDucks(void) {
  
  int result; // eax
  unsigned int v2; // esi
  int v3; // eax
  int v4; // eax
  void *v5; // eax
  unsigned int v6; // [esp-10h] [ebp-40h]
  unsigned int v7; // [esp-Ch] [ebp-3Ch]
  unsigned int v8; // [esp-8h] [ebp-38h]
  unsigned int v9; // [esp+4h] [ebp-2Ch]
  Squares *v10; // [esp+8h] [ebp-28h] BYREF
  Squares *v11; // [esp+Ch] [ebp-24h] BYREF
  Y16X16 *v12; // [esp+10h] [ebp-20h]
  unsigned int v13; // [esp+14h] [ebp-1Ch]
  int v14; // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h]
  unsigned int v16; // [esp+20h] [ebp-10h]
  unsigned int v17; // [esp+24h] [ebp-Ch]
  CAnimalEffect **v18; // [esp+28h] [ebp-8h]
  char v19; // [esp+2Fh] [ebp-1h]

  v18 = this;
  result = std::vector<unsigned int>::size(this + 89);
  if ( result )
  {
    for ( i = 0; i < (int)v18[70]; ++i )
    {
      v2 = CAnimalMgr::EffectRandomNumber((CAnimalMgr *)v18);
      v13 = v2 % std::vector<unsigned int>::size(v18 + 89);
      v12 = *(Y16X16 **)std::vector<unsigned int>::operator[](v13);
      Y16X16::UnpackXYFast(v12, &v11, (int *)&v10);
      v16 = CAnimalMgr::EffectRandomNumber((CAnimalMgr *)v18) % 0x10;
      v3 = Squares::VWToXY(v11);
      v16 += v3;
      v17 = CAnimalMgr::EffectRandomNumber((CAnimalMgr *)v18) % 0x10;
      v4 = Squares::VWToXY(v10);
      v17 += v4;
      v14 = CAnimalEffect::AddDuck(v18[97], v16, v17);
      if ( v14 )
      {
        v9 = CAnimalMgr::EffectRandomNumber((CAnimalMgr *)v18) % 0x14;
        v8 = v17;
        v7 = v16;
        v6 = v14;
        v5 = (void *)CLogic::FutureEvents(g_pLogic);
        v19 = IFutureEvents::AddFutureEvent16(v5, 7, v9, 0, v6, v7, v8, 0);
      }
      result = i + 1;
    }
  }
  return result;
}


// address=[0x14dfed0]
// Decompiled from unsigned int __thiscall CAnimalMgr::EffectRandomNumber(CAnimalMgr *this)

unsigned int  CAnimalMgr::EffectRandomNumber(void) {
  
  return CRandom16::Rand((CAnimalMgr *)((char *)this + 380));
}


// address=[0x14e2f70]
// Decompiled from unsigned int __thiscall CAnimalMgr::Alloc(CAnimalMgr *this, unsigned int a2)

void *  CAnimalMgr::Alloc(unsigned int) {
  
  return MemoryAllocator::allocate((unsigned int *)this, a2);
}


// address=[0x14e2fb0]
// Decompiled from void __thiscall CAnimalMgr::Dealloc(CAnimalMgr *this, void *a2)

void  CAnimalMgr::Dealloc(void *) {
  
  MemoryAllocator::deallocate(this, a2);
}


// address=[0x4032ad0]
// [Decompilation failed for static struct SAnimalData * CAnimalMgr::m_asAnimalData]

// address=[0x4032da0]
// [Decompilation failed for static struct SAnimalData * CAnimalMgr::m_asAnimalEffectData]

