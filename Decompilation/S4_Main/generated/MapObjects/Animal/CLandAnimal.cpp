#include "CLandAnimal.h"

// Definitions for class CLandAnimal

// address=[0x1400fe0]
// Decompiled from int __cdecl CLandAnimal::New(int a1)
static class CPersistence * __cdecl CLandAnimal::New(std::istream &) {
  
  if ( CLandAnimal::operator new(0xB0u) )
    return CLandAnimal::CLandAnimal(a1);
  else
    return 0;
}


// address=[0x14e0eb0]
// Decompiled from int __thiscall CLandAnimal::Init(CLandAnimal *this, struct SAnimalData *a2)
void  CLandAnimal::Init(struct SAnimalData *) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  unsigned int v5; // eax
  int v7; // [esp-Ch] [ebp-3Ch]
  __int16 v8; // [esp-8h] [ebp-38h]
  int v9; // [esp+0h] [ebp-30h]
  _BYTE v10[12]; // [esp+4h] [ebp-2Ch] BYREF
  int v11; // [esp+10h] [ebp-20h]
  int v12; // [esp+14h] [ebp-1Ch]
  _BYTE v13[4]; // [esp+18h] [ebp-18h] BYREF
  int v14; // [esp+1Ch] [ebp-14h]
  CPropertySet *v15; // [esp+20h] [ebp-10h]
  int v16; // [esp+2Ch] [ebp-4h]

  v15 = this;
  *((_DWORD *)this + 29) = a2;
  if ( *(_BYTE *)(*((_DWORD *)v15 + 29) + 4) )
    IEntity::SetFlagBits(v15, (EntityFlag)((char *)&loc_20200FC + 4));
  else
    IEntity::SetFlagBits(v15, (EntityFlag)&byte_20000CA[54]);
  *((_BYTE *)v15 + 70) = 0;
  v2 = CWalking::Create(0, 0);
  std::auto_ptr<CWalking>::auto_ptr<CWalking>(v2);
  v16 = 0;
  std::auto_ptr<CWalking>::operator=(v13);
  v14 = std::auto_ptr<CWalking>::operator->(v9);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v14 + 8))(v14, -1);
  v8 = *((_WORD *)v15 + 4);
  v7 = IEntity::Y(v15);
  v3 = IEntity::X(v15);
  CWorldManager::SetSettlerId(v3, v7, v8);
  CWarMap::AddEntity(v15);
  v4 = IEntity::PackedXY(v15);
  *((_DWORD *)v15 + 41) = v4;
  v12 = std::list<CEntityTask>::begin(v10);
  v11 = v12;
  LOBYTE(v16) = 1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(v12);
  LOBYTE(v16) = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v10);
  v5 = CStateGame::Rand(g_pGame);
  *((_BYTE *)v15 + 68) = v5 % 6;
  *((_DWORD *)v15 + 25) = 0;
  (*(void (__thiscall **)(CPropertySet *, int))(*(_DWORD *)v15 + 128))(v15, 1);
  v16 = -1;
  return std::auto_ptr<CWalking>::~auto_ptr<CWalking>(v13);
}


// address=[0x14e1030]
// Decompiled from void *__cdecl CLandAnimal::operator new(unsigned int a1)
static void * __cdecl CLandAnimal::operator new(unsigned int) {
  
  return CAnimalMgr::Alloc((CAnimalMgr *)&g_cAnimalMgr, a1);
}


// address=[0x14e1050]
// Decompiled from void __cdecl CLandAnimal::operator delete(void *a1)
static void __cdecl CLandAnimal::operator delete(void *) {
  
  CAnimalMgr::Dealloc((CAnimalMgr *)&g_cAnimalMgr, a1);
}


// address=[0x14e1090]
// Decompiled from int __thiscall CLandAnimal::GetGoodType(CLandAnimal *this)
int  CLandAnimal::GetGoodType(void)const {
  
  return 24;
}


// address=[0x14e10a0]
// Decompiled from void __thiscall CLandAnimal::Decrease(CLandAnimal *this, int a2)
void  CLandAnimal::Decrease(int) {
  
  if ( *((_DWORD *)this + 25) != 5 )
  {
    IEntity::ClearFlagBits(this, (EntityFlag)&loc_3000000);
    CAnimal::TakeDieJob(this);
  }
}


// address=[0x14e10d0]
// Decompiled from void __thiscall CLandAnimal::Take(CLandAnimal *this, int a2)
void  CLandAnimal::Take(int) {
  
  int v2; // eax

  v2 = IEntity::ID();
  CAnimalMgr::DeleteAnimal((CAnimalMgr *)&g_cAnimalMgr, v2);
}


// address=[0x14e10f0]
// Decompiled from unsigned __int16 *__thiscall CLandAnimal::CLandAnimal(unsigned __int16 *this, int a2)
 CLandAnimal::CLandAnimal(std::istream &) {
  
  int v2; // eax
  int v3; // eax
  int v5; // [esp-4h] [ebp-24h]
  unsigned int v6; // [esp+8h] [ebp-18h] BYREF
  unsigned __int16 *v7; // [esp+Ch] [ebp-14h]
  unsigned __int8 v8; // [esp+13h] [ebp-Dh] BYREF
  int v9; // [esp+1Ch] [ebp-4h]

  v7 = this;
  CAnimal::CAnimal(a2);
  v9 = 0;
  *(_DWORD *)v7 = &CLandAnimal::_vftable_;
  operator^<unsigned int>(a2, &v6);
  if ( v6 )
  {
    operator^<int>(a2, (int)(v7 + 70));
    operator^<int>(a2, (int)(v7 + 72));
    operator^<int>(a2, (int)(v7 + 74));
    operator^<int>(a2, (int)(v7 + 80));
    operator^<int>(a2, (int)(v7 + 82));
    operator^<int>(a2, (int)(v7 + 84));
    *((_DWORD *)v7 + 43) = -1;
    *((_DWORD *)v7 + 39) = 0;
    *((_DWORD *)v7 + 38) = 0;
  }
  if ( v6 >= 2 )
  {
    operator^<int>(a2, (int)(v7 + 86));
    operator^<unsigned char>(a2, &v8);
  }
  if ( v6 >= 3 )
  {
    operator^<int>(a2, (int)(v7 + 78));
    operator^<int>(a2, (int)(v7 + 76));
  }
  std::list<CEntityTask>::clear();
  *((_DWORD *)v7 + 21) = v7 + 52;
  v2 = IEntity::Type(v7);
  CAnimalMgr::InitAnimalJobs((struct CAnimal *)v7, v2);
  v5 = v8;
  v3 = IEntity::Type(v7);
  CLandAnimal::PostLoadInit((CLandAnimal *)v7, (struct SAnimalData *)&CAnimalMgr::m_asAnimalData[10 * v3], v5);
  return v7;
}


// address=[0x14e12f0]
// Decompiled from int __thiscall CLandAnimal::Store(int *this, struct std::ostream *a2)
void  CLandAnimal::Store(std::ostream &) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-2Ch] BYREF
  std::_Iterator_base12 *v5; // [esp+1Ch] [ebp-20h]
  std::_Iterator_base12 *v6; // [esp+20h] [ebp-1Ch]
  int v7; // [esp+24h] [ebp-18h] BYREF
  int *v8; // [esp+28h] [ebp-14h]
  char v9; // [esp+2Eh] [ebp-Eh]
  int v10; // [esp+2Fh] [ebp-Dh] BYREF
  int v11; // [esp+38h] [ebp-4h]

  v8 = this;
  CAnimal::Store((int)a2);
  v7 = 3;
  operator^<unsigned int>(a2, &v7);
  operator^<int>((int)a2, v8 + 35);
  operator^<int>((int)a2, v8 + 36);
  operator^<int>((int)a2, v8 + 37);
  operator^<int>((int)a2, v8 + 40);
  operator^<int>((int)a2, v8 + 41);
  operator^<int>((int)a2, v8 + 42);
  operator^<int>((int)a2, v8 + 43);
  LOBYTE(v10) = 0;
  std::list<CEntityTask>::begin(v4);
  v11 = 0;
  while ( 1 )
  {
    v6 = (std::_Iterator_base12 *)std::list<CEntityTask>::end(v3);
    v5 = v6;
    LOBYTE(v11) = 1;
    v9 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator!=(v6);
    LOBYTE(v11) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v3);
    if ( !v9
      || (unsigned __int8)std::_List_const_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator==((std::_Iterator_base12 *)(v8 + 22)) )
    {
      break;
    }
    LOBYTE(v10) = v10 + 1;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator++(v4);
  }
  v11 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v4);
  operator^<unsigned char>(a2, (int)&v10);
  operator^<int>((int)a2, v8 + 39);
  return operator^<int>((int)a2, v8 + 38);
}


// address=[0x14e2f90]
// Decompiled from int __thiscall CLandAnimal::ClassID(CLandAnimal *this)
unsigned long  CLandAnimal::ClassID(void)const {
  
  return CLandAnimal::m_iClassID;
}


// address=[0x3d8a960]
// [Decompilation failed for static unsigned long CLandAnimal::m_iClassID]

// address=[0x14e14c0]
// Decompiled from CLandAnimal *__thiscall CLandAnimal::CLandAnimal(CLandAnimal *this, int a2, int a3, int a4, int a5)
 CLandAnimal::CLandAnimal(int,int,int,int) {
  
  CAnimal::CAnimal(this, a2, a3, a4, a5);
  *(_DWORD *)this = &CLandAnimal::_vftable_;
  *((_DWORD *)this + 43) = 0;
  std::list<CEntityTask>::clear();
  *((_DWORD *)this + 21) = (char *)this + 104;
  *((_DWORD *)this + 36) = 0;
  *((_DWORD *)this + 37) = 0;
  *((_DWORD *)this + 42) = -1;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 40) = 0;
  return this;
}


// address=[0x14e1570]
// Decompiled from int __thiscall CLandAnimal::~CLandAnimal(CLandAnimal *this)
 CLandAnimal::~CLandAnimal(void) {
  
  *(_DWORD *)this = &CLandAnimal::_vftable_;
  return CAnimal::~CAnimal(this);
}


// address=[0x14e1590]
// Decompiled from int __thiscall CLandAnimal::PostLoadInit(CLandAnimal *this, struct SAnimalData *a2, int a3)
void  CLandAnimal::PostLoadInit(struct SAnimalData *,int) {
  
  int v3; // eax
  int v5; // [esp+0h] [ebp-30h]
  _BYTE v6[12]; // [esp+4h] [ebp-2Ch] BYREF
  int v7; // [esp+10h] [ebp-20h]
  int v8; // [esp+14h] [ebp-1Ch]
  _BYTE v9[4]; // [esp+18h] [ebp-18h] BYREF
  int v10; // [esp+1Ch] [ebp-14h]
  CPropertySet *v11; // [esp+20h] [ebp-10h]
  int v12; // [esp+2Ch] [ebp-4h]

  v11 = this;
  *((_DWORD *)this + 29) = a2;
  v3 = CWalking::Create(0, 0);
  std::auto_ptr<CWalking>::auto_ptr<CWalking>(v3);
  v12 = 0;
  std::auto_ptr<CWalking>::operator=(v9);
  v10 = std::auto_ptr<CWalking>::operator->(v5);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v10 + 8))(v10, -1, 0);
  CWarMap::AddEntity(v11);
  v8 = std::list<CEntityTask>::begin(v6);
  v7 = v8;
  LOBYTE(v12) = 1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::operator=(v8);
  LOBYTE(v12) = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CEntityTask>>>(v6);
  while ( a3 )
  {
    IMovingEntity::IncToDoListIter(v11);
    --a3;
  }
  v12 = -1;
  return std::auto_ptr<CWalking>::~auto_ptr<CWalking>(v9);
}


// address=[0x14e1690]
// Decompiled from void __thiscall CLandAnimal::LogicUpdateSpec(CLandAnimal *this)
void  CLandAnimal::LogicUpdateSpec(void) {
  
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  char v8; // al
  int v9; // eax
  int v10; // [esp-10h] [ebp-28h]
  int v11; // [esp-10h] [ebp-28h]
  unsigned int v12; // [esp+0h] [ebp-18h]
  int v13; // [esp+4h] [ebp-14h]
  int v14; // [esp+8h] [ebp-10h]
  int v15; // [esp+Ch] [ebp-Ch]
  int MoveDir; // [esp+10h] [ebp-8h]
  int v17; // [esp+10h] [ebp-8h]

  if ( *((_DWORD *)this + 25) == 4 )
  {
    CAnimal::TakeDeadJob(this);
    return;
  }
  v1 = IEntity::PackedXY(this);
  v14 = CWorldManager::Index(v1);
  if ( IEntity::Type((unsigned __int16 *)this) == 2 || IEntity::Type((unsigned __int16 *)this) == 3 )
  {
    if ( CWorldManager::FlagBits(v14, 4u) )
    {
      *((_DWORD *)this + 38) = 0;
    }
    else if ( (int)++*((_DWORD *)this + 38) > 0 )
    {
      v4 = IEntity::ID();
      CAnimalMgr::DeleteAnimal((CAnimalMgr *)&g_cAnimalMgr, v4);
      v13 = CLogic::Effects((DWORD *)g_pLogic);
      v11 = IEntity::Y(this);
      v5 = IEntity::X(this);
      (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v13 + 16))(
        v13,
        64,
        69,
        v5,
        v11,
        0,
        0,
        0);
      return;
    }
  }
  else if ( CWorldManager::FlagBits(v14, 4u) )
  {
    if ( (int)++*((_DWORD *)this + 38) > 0 )
    {
      v2 = IEntity::ID();
      CAnimalMgr::DeleteAnimal((CAnimalMgr *)&g_cAnimalMgr, v2);
      v15 = CLogic::Effects((DWORD *)g_pLogic);
      v10 = IEntity::Y(this);
      v3 = IEntity::X(this);
      (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v15 + 16))(
        v15,
        64,
        69,
        v3,
        v10,
        0,
        0,
        0);
      return;
    }
  }
  else
  {
    *((_DWORD *)this + 38) = 0;
  }
  if ( *(_BYTE *)(*((_DWORD *)this + 29) + 5) )
  {
    ++*((_DWORD *)this + 35);
    if ( *((_DWORD *)this + 25) == 3 || *((int *)this + 35) > 1 )
    {
      if ( CLandAnimal::CheckForEnemies(this) )
        *((_DWORD *)this + 25) = 3;
      else
        *((_DWORD *)this + 25) = 2;
      *((_DWORD *)this + 35) = 0;
    }
    if ( *((_DWORD *)this + 25) == 3 )
    {
      MoveDir = CLandAnimal::GetMoveDir(this);
      if ( MoveDir >= 0 )
      {
        CAnimal::TakeFleeJob(this, 0);
        CAnimal::WalkDirAndRegister(this, MoveDir);
        return;
      }
    }
  }
  v6 = IEntity::PackedXY(this);
  v7 = CWorldManager::Index(v6);
  if ( !CLandAnimal::CheckGround(this, v7) )
  {
    v17 = CLandAnimal::GetMoveDir(this);
    if ( v17 >= 0 )
      goto LABEL_27;
  }
  v12 = CStateGame::Rand(g_pGame);
  if ( v12 >= CRandom16::PercentValue(0x1Eu) )
  {
    if ( v12 >= CRandom16::PercentValue(0x46u) )
    {
      v17 = CLandAnimal::GetMoveDir(this);
      if ( v17 >= 0 )
      {
LABEL_27:
        CAnimal::TakeWalkJobAndWalkDir(this, v17);
        ++*((_DWORD *)this + 36);
        return;
      }
      CAnimal::TakeWaitJobAndDoNothing(this, 5);
    }
    else
    {
      v8 = CStateGame::Rand(g_pGame);
      CAnimal::TakeWaitJobAndDoNothing(this, (v8 & 3) + 10);
    }
  }
  else
  {
    CAnimal::TakeEatJob(this, 1);
  }
  if ( *((_DWORD *)this + 43) == *((_DWORD *)this + 6) )
  {
    if ( (int)++*((_DWORD *)this + 39) > 150 )
    {
      v9 = IEntity::ID();
      CAnimalMgr::DeleteAnimal((CAnimalMgr *)&g_cAnimalMgr, v9);
    }
  }
  else
  {
    *((_DWORD *)this + 39) = 0;
  }
  *((_DWORD *)this + 43) = *((_DWORD *)this + 6);
}


// address=[0x14e1a10]
// Decompiled from int __thiscall CLandAnimal::GetMoveDir(CLandAnimal *this)
int  CLandAnimal::GetMoveDir(void) {
  
  Squares *v1; // eax
  Squares *v2; // eax
  int v3; // eax
  int v4; // esi
  int v5; // esi
  int v6; // esi
  int v7; // eax
  int v9; // esi
  CWalking *v10; // eax
  int v11; // esi
  int v12; // eax
  int v13; // [esp-4h] [ebp-98h]
  int v14; // [esp+Ch] [ebp-88h]
  int v15; // [esp+10h] [ebp-84h]
  int v16; // [esp+14h] [ebp-80h]
  int v17; // [esp+18h] [ebp-7Ch]
  int v18; // [esp+1Ch] [ebp-78h]
  Y16X16 *v19; // [esp+20h] [ebp-74h]
  unsigned int v20; // [esp+24h] [ebp-70h]
  Y16X16 *v21; // [esp+30h] [ebp-64h]
  int v22; // [esp+34h] [ebp-60h]
  Y16X16 *v23; // [esp+38h] [ebp-5Ch]
  Grid *v24; // [esp+3Ch] [ebp-58h]
  int v25; // [esp+40h] [ebp-54h]
  int v26; // [esp+40h] [ebp-54h]
  int v27; // [esp+40h] [ebp-54h]
  int i; // [esp+44h] [ebp-50h]
  int j; // [esp+48h] [ebp-4Ch]
  int k; // [esp+48h] [ebp-4Ch]
  int v31; // [esp+4Ch] [ebp-48h]
  int v32; // [esp+4Ch] [ebp-48h]
  int v33; // [esp+4Ch] [ebp-48h]
  int v34; // [esp+4Ch] [ebp-48h]
  int v35; // [esp+4Ch] [ebp-48h]
  int TerritoryDir; // [esp+50h] [ebp-44h]
  _DWORD v38[14]; // [esp+58h] [ebp-3Ch] BYREF

  v1 = (Squares *)IEntity::X(this);
  v15 = Squares::XYToVW(v1);
  v2 = (Squares *)IEntity::Y(this);
  v16 = Squares::XYToVW(v2);
  Y16X16::PackXYFast(v15, v16);
  CPossibleDirs::CPossibleDirs((CPossibleDirs *)v38);
  v3 = IEntity::PackedXY(this);
  v14 = CWorldManager::Index(v3);
  for ( i = 0; i < 6; ++i )
  {
    v22 = v14 + CWorldManager::NeighborRelIndex(i);
    if ( CWorldManager::FlagBits(v22, 1u) )
    {
      v38[i + 8] = 3;
    }
    else if ( CWorldManager::MapObjectId(v22) )
    {
      v38[i + 8] = 2;
    }
    else
    {
      v38[i + 8] = CWorldManager::MoveCostsBits(v22) >= 7;
    }
  }
  TerritoryDir = -1;
  if ( *((_DWORD *)this + 25) == 3 )
  {
    if ( *((int *)this + 37) < 0 || *((_DWORD *)this + 42) == -1 )
      *((_DWORD *)this + 42) = CLandAnimal::GetFleeDir(this);
    TerritoryDir = *((_DWORD *)this + 42);
    if ( (int)++*((_DWORD *)this + 37) > 4 )
      *((_DWORD *)this + 37) = -1;
  }
  else if ( *((int *)this + 36) > 8 )
  {
    if ( CLandAnimal::CheckTerritory(this) )
    {
      *((_DWORD *)this + 41) = IEntity::PackedXY(this);
    }
    else
    {
      TerritoryDir = CLandAnimal::GetTerritoryDir(this);
      if ( TerritoryDir < 0 )
        TerritoryDir = CLandAnimal::GetDirection(this, *((_DWORD *)this + 41));
    }
    *((_DWORD *)this + 36) = 0;
  }
  v18 = IEntity::X(this);
  v17 = IEntity::Y(this);
  if ( TerritoryDir == -1 )
    TerritoryDir = *((char *)this + 68);
  v19 = (Y16X16 *)Grid::TurnLeft((Grid *)TerritoryDir);
  v21 = (Y16X16 *)Grid::TurnRight((Grid *)TerritoryDir);
  v20 = CStateGame::Rand(g_pGame);
  v4 = IEntity::PackedXY(this);
  v25 = Y16X16::NeighborModifier(v19) + v4;
  v31 = CWorldManager::Index(v25);
  if ( CLandAnimal::CheckTile(this, v31) && !CLandAnimal::IsSettlerAroundTile(this, v25) )
    CPossibleDirs::PushDir((CPossibleDirs *)v38, v19);
  v5 = IEntity::PackedXY(this);
  v26 = Y16X16::NeighborModifier((Y16X16 *)TerritoryDir) + v5;
  v32 = CWorldManager::Index(v26);
  if ( CLandAnimal::CheckTile(this, v32)
    && !CLandAnimal::IsSettlerAroundTile(this, v26)
    && v20 < CRandom16::PercentValue(0x46u) )
  {
    v6 = IEntity::PackedXY(this);
    v7 = Y16X16::NeighborModifier((Y16X16 *)TerritoryDir);
    if ( !CLandAnimal::IsSettlerAroundTile(this, v7 + v6) )
    {
      if ( !v38[TerritoryDir + 8] )
        return TerritoryDir;
      CPossibleDirs::PushDir((CPossibleDirs *)v38, TerritoryDir);
    }
  }
  v9 = IEntity::PackedXY(this);
  v27 = Y16X16::NeighborModifier(v21) + v9;
  v33 = CWorldManager::Index(v27);
  if ( CLandAnimal::CheckTile(this, v33) && !CLandAnimal::IsSettlerAroundTile(this, v27) )
    CPossibleDirs::PushDir((CPossibleDirs *)v38, v21);
  if ( !v38[0] )
  {
    v24 = v21;
    for ( j = 0; j < 3; ++j )
    {
      v24 = (Grid *)Grid::TurnRight(v24);
      v34 = CWorldManager::Index(g_sNeighborPoints[2 * (_DWORD)v24] + v18, dword_37D8C0C[2 * (_DWORD)v24] + v17);
      if ( CLandAnimal::CheckTile(this, v34) )
        CPossibleDirs::PushDir((CPossibleDirs *)v38, v24);
    }
  }
  if ( !v38[0] )
  {
    for ( k = 0; k < 6; ++k )
    {
      v35 = CWorldManager::Index(g_sNeighborPoints[2 * k] + v18, dword_37D8C0C[2 * k] + v17);
      if ( CLandAnimal::IsTileFree(this, v35) )
      {
        v10 = (CWalking *)std::auto_ptr<CWalking>::operator->(v35);
        if ( CWalking::IsFree(v10, v13) )
          CPossibleDirs::PushDir((CPossibleDirs *)v38, k);
      }
    }
  }
  if ( v38[0] <= 0 )
    return -1;
  v23 = (Y16X16 *)(v20 < CRandom16::PercentValue(0x46u) && CPossibleDirs::Search((CPossibleDirs *)v38, TerritoryDir)
                 ? TerritoryDir
                 : v38[v20 % v38[0] + 2]);
  v11 = IEntity::PackedXY(this);
  v12 = Y16X16::NeighborModifier(v23);
  if ( CLandAnimal::IsSettlerAroundTile(this, v12 + v11) )
    return -1;
  else
    return (int)v23;
}


// address=[0x14e1f60]
// Decompiled from Y16X16 *__thiscall CLandAnimal::GetFleeDir(CLandAnimal *this)
int  CLandAnimal::GetFleeDir(void) {
  
  int v1; // esi
  int v2; // esi
  int v3; // esi
  Y16X16 *v5; // [esp+8h] [ebp-38h]
  int v6; // [esp+Ch] [ebp-34h]
  int v7; // [esp+Ch] [ebp-34h]
  int v8; // [esp+Ch] [ebp-34h]
  int v9; // [esp+10h] [ebp-30h]
  int v10; // [esp+10h] [ebp-30h]
  int v11; // [esp+10h] [ebp-30h]
  Y16X16 *v12; // [esp+14h] [ebp-2Ch]
  int v14; // [esp+1Ch] [ebp-24h]
  Y16X16 *v15; // [esp+1Ch] [ebp-24h]
  unsigned int v16; // [esp+20h] [ebp-20h]
  _DWORD v17[6]; // [esp+24h] [ebp-1Ch]

  v16 = 0;
  v14 = CLandAnimal::GetDirection(this, *((_DWORD *)this + 40)) - 3;
  v15 = (Y16X16 *)(v14 + (v14 < 0 ? 6 : 0));
  v12 = (Y16X16 *)((char *)v15 + ((int)v15 - 1 < 0 ? 6 : 0) - 1);
  v5 = (Y16X16 *)((char *)v15 + 1);
  if ( (int)v15 + 1 >= 6 )
    v5 = (Y16X16 *)((char *)v15 - 5);
  v1 = IEntity::PackedXY(this);
  v9 = Y16X16::NeighborModifier(v15) + v1;
  v6 = CWorldManager::Index(v9);
  if ( CLandAnimal::IsTileFree(this, v6) )
  {
    v17[0] = v15;
    v16 = 1;
  }
  v2 = IEntity::PackedXY(this);
  v10 = Y16X16::NeighborModifier(v12) + v2;
  v7 = CWorldManager::Index(v10);
  if ( CLandAnimal::IsTileFree(this, v7) )
    v17[v16++] = v12;
  v3 = IEntity::PackedXY(this);
  v11 = Y16X16::NeighborModifier(v5) + v3;
  v8 = CWorldManager::Index(v11);
  if ( CLandAnimal::IsTileFree(this, v8) )
    v17[v16++] = v5;
  if ( v16 )
    return (Y16X16 *)v17[CStateGame::Rand(g_pGame) % v16];
  else
    return v15;
}


// address=[0x14e2100]
// Decompiled from int __thiscall CLandAnimal::GetTerritoryDir(CLandAnimal *this)
int  CLandAnimal::GetTerritoryDir(void) {
  
  Squares *v1; // eax
  Squares *v2; // eax
  int v4; // [esp+0h] [ebp-34h]
  int v5; // [esp+4h] [ebp-30h]
  int v7; // [esp+Ch] [ebp-28h]
  int i; // [esp+10h] [ebp-24h]
  _DWORD v9[7]; // [esp+14h] [ebp-20h]

  v1 = (Squares *)IEntity::X(this);
  v4 = Squares::XYToVW(v1);
  v2 = (Squares *)IEntity::Y(this);
  v5 = Squares::XYToVW(v2);
  v7 = 0;
  for ( i = 0; i < 6; ++i )
  {
    if ( CLandAnimal::IsValidSquare(this, g_sNeighborPoints[2 * i] + v4, dword_37D8C0C[2 * i] + v5) )
      v9[++v7] = i;
  }
  if ( v7 <= 0 )
    return -1;
  else
    return v9[CStateGame::Rand(g_pGame) % (unsigned int)v7 + 1];
}


// address=[0x14e21d0]
// Decompiled from int __thiscall CLandAnimal::GetDirection(CLandAnimal *this, Y16X16 *a2)
int  CLandAnimal::GetDirection(int) {
  
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  int i; // [esp+Ch] [ebp-Ch]
  int v7; // [esp+10h] [ebp-8h] BYREF
  int v8; // [esp+14h] [ebp-4h] BYREF

  v4 = IEntity::X(this);
  v3 = IEntity::Y(this);
  Y16X16::UnpackXYFast(a2, &v8, &v7);
  if ( v8 >= v4 )
    v8 = v8 > v4;
  else
    v8 = -1;
  if ( v7 >= v3 )
    v7 = v7 > v3;
  else
    v7 = -1;
  if ( v8 == -1 && v7 == 1 )
    return 3;
  if ( v8 == 1 && v7 == -1 )
    return 0;
  for ( i = 0; i < 6; ++i )
  {
    if ( v8 == g_sNeighborPoints[2 * i] && v7 == dword_37D8C0C[2 * i] )
      return i;
  }
  return -1;
}


// address=[0x14e22d0]
// Decompiled from bool __thiscall CLandAnimal::CheckForEnemies(CLandAnimal *this)
bool  CLandAnimal::CheckForEnemies(void) {
  
  int v1; // eax
  int v3; // [esp-10h] [ebp-28h]
  int v4; // [esp-Ch] [ebp-24h]
  int i; // [esp+Ch] [ebp-Ch]
  int v6; // [esp+10h] [ebp-8h]

  v6 = 0;
  if ( *(int *)(*((_DWORD *)this + 29) + 20) < 0 )
  {
    v6 = 255;
  }
  else
  {
    for ( i = CPlayerManager::LastPlayerId(); i >= 1; --i )
    {
      v6 *= 2;
      if ( CPlayerManager::Race(i) != *(_DWORD *)(*((_DWORD *)this + 29) + 20) )
        ++v6;
    }
  }
  v4 = *(_DWORD *)(*((_DWORD *)this + 29) + 24);
  v3 = IEntity::Y(this);
  v1 = IEntity::X(this);
  *((_DWORD *)this + 40) = CScanner::FindNearestFighter(v1, v3, v4, 255, v6);
  return *((_DWORD *)this + 40) != -1;
}


// address=[0x14e23a0]
// Decompiled from bool __thiscall CLandAnimal::CheckTerritory(CLandAnimal *this)
bool  CLandAnimal::CheckTerritory(void) {
  
  Squares *v1; // eax
  Squares *v2; // eax
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]

  v1 = (Squares *)IEntity::X(this);
  v4 = Squares::XYToVW(v1);
  v2 = (Squares *)IEntity::Y(this);
  v5 = Squares::XYToVW(v2);
  return CLandAnimal::IsValidSquare(this, v4, v5);
}


// address=[0x14e23f0]
// Decompiled from bool __thiscall CLandAnimal::IsValidSquare(CLandAnimal *this, int a2, int a3)
bool  CLandAnimal::IsValidSquare(int,int) {
  
  int v4; // [esp+8h] [ebp-18h]
  CAIResourceData *v5; // [esp+14h] [ebp-Ch]
  bool v7; // [esp+1Fh] [ebp-1h]

  v5 = CAIResourceMap::ResourceDataVW(a2, a3);
  if ( **((_DWORD **)this + 29) == 9 )
  {
    v7 = CWarMap::FirstEntityIdVW(2, a2, a3) > 0;
    return CAIResourceData::GroundInfo1(v5, 0) == 0 && v7;
  }
  else if ( *(int *)(*((_DWORD *)this + 29) + 8) <= 0
         || (v4 = CAIResourceData::ResourceAmount1(v5, 7), v4 >= *(_DWORD *)(*((_DWORD *)this + 29) + 8))
         && v4 < *(_DWORD *)(*((_DWORD *)this + 29) + 12) )
  {
    if ( **((_DWORD **)this + 29) == 8 )
      return CAIResourceData::GroundInfo1(v5, 0) > 120;
    else
      return CAIResourceData::GroundInfo1(v5, 1) > 120;
  }
  else
  {
    return 0;
  }
}


// address=[0x14e2510]
// Decompiled from bool __thiscall CLandAnimal::CheckTile(CLandAnimal *this, int a2)
bool  CLandAnimal::CheckTile(int) {
  
  return CLandAnimal::IsTileFree(this, a2) && CLandAnimal::CheckGround(this, a2);
}


// address=[0x14e2540]
// Decompiled from bool __thiscall CLandAnimal::IsTileFree(CLandAnimal *this, int a2)
bool  CLandAnimal::IsTileFree(int) {
  
  return !(unsigned __int8)CWorldManager::IsBlockedLand(a2)
      && CWorldManager::ObjectId(a2) <= 0
      && CWorldManager::MapObjectId(a2) <= 0;
}


// address=[0x14e25a0]
// Decompiled from bool __thiscall CLandAnimal::CheckGround(CLandAnimal *this, int a2)
bool  CLandAnimal::CheckGround(int) {
  
  bool result; // al
  bool v3; // [esp+10h] [ebp-8h]

  switch ( **((_DWORD **)this + 29) )
  {
    case 1:
    case 2:
    case 3:
    case 4:
      v3 = (CWorldManager::Ground(a2) & 0xF0) == 0x10 && !CWorldManager::FlagBits(a2, 4u);
      result = v3;
      break;
    case 8:
      result = CWorldManager::FlagBits(a2, 4u) != 0;
      break;
    case 9:
      result = CWorldManager::FlagBits(a2, 4u) == 0;
      break;
    default:
      result = (CWorldManager::Ground(a2) & 0xF0) == 16;
      break;
  }
  return result;
}


// address=[0x14e26c0]
// Decompiled from char __thiscall CLandAnimal::IsSettlerAroundTile(CLandAnimal *this, int a2)
bool  CLandAnimal::IsSettlerAroundTile(int) {
  
  int v3; // [esp+0h] [ebp-10h]
  int v5; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < 6; ++i )
  {
    v5 = a2 + Y16X16::NeighborModifier((Y16X16 *)i);
    if ( v5 != IEntity::PackedXY(this) )
    {
      v3 = CWorldManager::Index(v5);
      if ( CWorldManager::MapObjectId(v3) > 0 )
        return 1;
    }
  }
  return 0;
}


