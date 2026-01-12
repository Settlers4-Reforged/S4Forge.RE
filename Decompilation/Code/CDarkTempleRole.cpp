#include "CDarkTempleRole.h"

// Definitions for class CDarkTempleRole

// address=[0x14002c0]
// Decompiled from int __cdecl CDarkTempleRole::New(int a1)

static class CPersistence * __cdecl CDarkTempleRole::New(std::istream &) {
  
  if ( operator new(0x1B4u) )
    return CDarkTempleRole::CDarkTempleRole(a1);
  else
    return 0;
}


// address=[0x14fd970]
// Decompiled from int __cdecl CDarkTempleRole::Load(int a1)

static class CDarkTempleRole * __cdecl CDarkTempleRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CDarkTempleRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x1508260]
// Decompiled from CDarkTempleRole *__thiscall CDarkTempleRole::CDarkTempleRole(CDarkTempleRole *this)

 CDarkTempleRole::CDarkTempleRole(void) {
  
  int v2; // [esp+4h] [ebp-18h]
  int i; // [esp+Ch] [ebp-10h]

  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CDarkTempleRole::_vftable_;
  std::vector<int>::vector<int>((char *)this + 420);
  if ( byte_40F2218 )
    return this;
  byte_40F2218 = 1;
  j__memset(byte_40F2220, 0, 0x43u);
  j__memset(dword_40F2264, 0, 0x18u);
  for ( i = 0; i < 6; ++i )
  {
    v2 = dword_378588C[i];
    if ( v2 > 0 )
    {
      byte_40F2220[v2] = i;
      dword_40F2264[i] = (*(int (__thiscall **)(void *, int))(*(_DWORD *)off_3D7A3D8 + 52))(off_3D7A3D8, v2);
    }
  }
  return this;
}


// address=[0x1508360]
// Decompiled from int __thiscall CDarkTempleRole::LogicUpdate(CDarkTempleRole *this, struct CBuilding *a2)

void  CDarkTempleRole::LogicUpdate(class CBuilding *) {
  
  _DWORD *v2; // eax
  int v3; // eax
  int v4; // eax
  int v6; // [esp-8h] [ebp-10h]
  int v7; // [esp-4h] [ebp-Ch]
  CPaneContainer *v8; // [esp+0h] [ebp-8h]

  if ( IEntity::FlagBits(a2, (EntityFlag)dword_800000) )
    IEntity::ClearFlagBits(a2, (EntityFlag)dword_800000);
  else
    IEntity::ClearFlagBits(a2, (EntityFlag)0x200000u);
  CDarkTempleRole::Produce(this, a2);
  if ( std::vector<int>::size((char *)this + 420) )
  {
    v2 = (_DWORD *)std::vector<int>::back();
    v8 = (CPaneContainer *)CSettlerMgr::operator[](*v2);
    if ( !CWorldManager::IsPositionFreeForSettler(*((_DWORD *)this + 95))
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\DarkTemple.cpp",
           321,
           "g_cWorld.IsPositionFreeForSettler( m_iAddDoorPackedXY ) == true") == 1 )
    {
      __debugbreak();
    }
    IEntity::SetPosition(v8, *((struct CPaneContainer **)this + 95));
    CWorldManager::SetSettlerId(*((_DWORD *)this + 95), *((unsigned __int16 *)this + 4));
    IEntity::SetFlagBits(v8, Visible);
    v7 = IEntity::Type((unsigned __int16 *)v8);
    v6 = IEntity::Type((unsigned __int16 *)v8);
    v3 = IEntity::Race(v8);
    v4 = CEntityToDoListMgr::SettlerJobList(v3, v6);
    (*(void (__thiscall **)(CPaneContainer *, int, int))(*(_DWORD *)v8 + 112))(v8, v4, v7);
    std::vector<int>::pop_back((char *)this + 420);
  }
  CDarkTempleRole::AttackEnemies(this, a2);
  CDarkTempleRole::ServantManagement(this, a2);
  return IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x15084c0]
// Decompiled from int __thiscall CDarkTempleRole::FillGfxInfo(CDarkTempleRole *this, struct CBuilding *a2, struct SGfxObjectInfo *a3)

void  CDarkTempleRole::FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &) {
  
  int v3; // eax
  int v5; // [esp-Ch] [ebp-10h]

  (*(void (__thiscall **)(CDarkTempleRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v5 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  return CGfxManager::GetBuildingGfxInfo((int)a3, v3, v5, 1, (int)this + 76);
}


// address=[0x1508510]
// Decompiled from int __thiscall CDarkTempleRole::Init(CDarkTempleRole *this, struct CBuilding *a2)

void  CDarkTempleRole::Init(class CBuilding *) {
  
  int v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-8h]

  IBuildingRole::InitCommon((int)a2);
  *((_BYTE *)this + 29) = 1;
  v4 = CBuilding::DoorX(a2) + 1;
  v5 = CBuilding::DoorY(a2) + 1;
  v3 = CWorldManager::Index(v4, v5);
  *((_DWORD *)this + 95) = Y16X16::PackXYFast(v4, v5);
  if ( (unsigned __int8)CWorldManager::IsBlockedLand(v3)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\DarkTemple.cpp",
         277,
         "! g_cWorld.IsBlockedLand( iAddDoorPackedWorldIdx )") == 1 )
  {
    __debugbreak();
  }
  j__memset((char *)this + 384, 0, 0x18u);
  *((_DWORD *)this + 102) = 0;
  *((_DWORD *)this + 103) = -1024;
  *((_DWORD *)this + 104) = 0;
  std::vector<int>::clear();
  return IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x1508610]
// Decompiled from int __thiscall CDarkTempleRole::PostLoadInit(CDarkTempleRole *this, struct CBuilding *a2)

void  CDarkTempleRole::PostLoadInit(class CBuilding *) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-14h]
  int v6; // [esp+8h] [ebp-8h]
  int v7; // [esp+Ch] [ebp-4h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  *((_DWORD *)this + 94) = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  v6 = CBuilding::DoorX(a2) + 1;
  v7 = CBuilding::DoorY(a2) + 1;
  CWorldManager::Index(v6, v7);
  result = Y16X16::PackXYFast(v6, v7);
  *((_DWORD *)this + 95) = result;
  return result;
}


// address=[0x1508690]
// Decompiled from char __thiscall CDarkTempleRole::SettlerEnter(CDarkTempleRole *this, struct CBuilding *a2, int a3)

bool  CDarkTempleRole::SettlerEnter(class CBuilding *,int) {
  
  int v3; // eax
  struct CPaneContainer *v4; // eax
  int v5; // eax
  int v7; // [esp+0h] [ebp-10h] BYREF
  int v8; // [esp+4h] [ebp-Ch]
  IBuildingRole *v9; // [esp+8h] [ebp-8h]
  CPaneContainer *v10; // [esp+Ch] [ebp-4h]

  v9 = this;
  v10 = (CPaneContainer *)CSettlerMgr::operator[](a3);
  v8 = IEntity::Type((unsigned __int16 *)v10);
  if ( v8 == 52 )
  {
    IEntity::ClearFlagBits(v10, Visible);
    v3 = IEntity::WorldIdx();
    CWorldManager::SetSettlerId(v3, 0);
    v4 = (struct CPaneContainer *)IEntity::PackedXY(a2);
    IEntity::SetPosition(v10, v4);
    v7 = IEntity::ID();
    std::vector<int>::push_back(&v7);
  }
  else
  {
    if ( v8 == 53 )
    {
      v5 = IEntity::OwnerId((unsigned __int8 *)a2);
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)off_3D7A3D8 + 48))(off_3D7A3D8, v5);
      IBuildingRole::DetachWithoutNotify(v9, a2, a3);
      IEntity::ClearFlagBits(v10, Visible);
      if ( IEntity::FlagBits(v10, OnBoard)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\DarkTemple.cpp",
             697,
             "rSettler.FlagBits(ENTITY_FLAG_ON_BOARD) == 0") == 1 )
      {
        __debugbreak();
      }
    }
    else
    {
      if ( v8 != 55 )
        return 1;
      ++*((_DWORD *)v9 + 104);
      IBuildingRole::DetachWithoutNotify(v9, a2, a3);
      IEntity::ClearFlagBits(v10, Visible);
      if ( IEntity::FlagBits(v10, OnBoard)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\DarkTemple.cpp",
             709,
             "rSettler.FlagBits(ENTITY_FLAG_ON_BOARD) == 0") == 1 )
      {
        __debugbreak();
      }
    }
    CMapObjectMgr::Kill(a3, 0);
  }
  return 1;
}


// address=[0x1508820]
// Decompiled from int __thiscall CDarkTempleRole::TakeOrder(CDarkTempleRole *this, int a2, int a3)

void  CDarkTempleRole::TakeOrder(int,int) {
  
  int result; // eax
  int *v4; // [esp+8h] [ebp-4h]

  if ( a2 > 0 && a2 < 67 )
  {
    if ( byte_40F2220[a2] )
    {
      v4 = (int *)((char *)this + 4 * (unsigned __int8)byte_40F2220[a2] + 384);
      if ( a3 >= 10000 )
      {
        a3 -= 10000;
        *v4 = 0;
      }
      if ( a3 < -100
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\DarkTemple.cpp",
             766,
             "_iDeltaAmountEx >= PRODUCTION_NO_PRODUCTION") == 1 )
      {
        __debugbreak();
      }
      if ( a3 > 100
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\DarkTemple.cpp",
             767,
             "_iDeltaAmountEx <= PRODUCTION_ENDLESS_PRODUCTION") == 1 )
      {
        __debugbreak();
      }
      if ( a3 > -100 )
      {
        if ( a3 < 100 )
        {
          if ( *v4 >= 100 )
          {
            *v4 = 100;
          }
          else
          {
            *v4 += a3;
            if ( *v4 >= 0 )
            {
              if ( *v4 >= 100 )
                *v4 = 99;
            }
            else
            {
              *v4 = 0;
            }
          }
        }
        else
        {
          *v4 = 100;
        }
      }
      else
      {
        *v4 = 0;
      }
      if ( (unsigned int)*v4 > 0x64
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\DarkTemple.cpp",
             798,
             "( rOrder >= 0 ) && ( rOrder <= PRODUCTION_ENDLESS_PRODUCTION )") == 1 )
      {
        __debugbreak();
      }
      return 0;
    }
    else
    {
      result = BBSupportDbgReportF(
                 1,
                 "MapObjects\\Building\\DarkTemple.cpp",
                 802,
                 "CDarkTempleRole::TakeOrder(): Settler type %i not supported!",
                 a2);
      if ( result == 1 )
        __debugbreak();
    }
  }
  else
  {
    result = BBSupportDbgReportF(
               1,
               "MapObjects\\Building\\DarkTemple.cpp",
               748,
               "CDarkTempleRole::TakeOrder(): Invalid settler type %i!",
               a2);
    if ( result == 1 )
      __debugbreak();
  }
  return result;
}


// address=[0x15089c0]
// Decompiled from int __thiscall CDarkTempleRole::ProduceMushroomFarmer(CDarkTempleRole *this, struct CBuilding *a2)

int  CDarkTempleRole::ProduceMushroomFarmer(class CBuilding *) {
  
  int v2; // eax

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  return CDarkTempleRole::AddSettlerToWorld(this, v2, 53, 0);
}


// address=[0x15089f0]
// Decompiled from char *__thiscall CDarkTempleRole::CDarkTempleRole(char *this, int a2)

 CDarkTempleRole::CDarkTempleRole(std::istream &) {
  
  int v2; // eax
  int v3; // eax
  int v5; // [esp+8h] [ebp-2Ch] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-28h] BYREF
  unsigned int v7; // [esp+10h] [ebp-24h] BYREF
  int v8; // [esp+14h] [ebp-20h]
  unsigned int j; // [esp+18h] [ebp-1Ch]
  int i; // [esp+1Ch] [ebp-18h]
  int k; // [esp+20h] [ebp-14h]
  char *v12; // [esp+24h] [ebp-10h]
  int v13; // [esp+30h] [ebp-4h]

  v12 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v13 = 0;
  *(_DWORD *)v12 = &CDarkTempleRole::_vftable_;
  std::vector<int>::vector<int>(v12 + 420);
  LOBYTE(v13) = 1;
  operator^<unsigned int>(a2, &v5);
  if ( v5 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDarkTempleRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  for ( i = 0; i < 6; ++i )
    operator^<int>(a2, (int)&v12[4 * i + 384]);
  operator^<int>(a2, (int)(v12 + 408));
  operator^<int>(a2, (int)(v12 + 412));
  operator^<int>(a2, (int)(v12 + 416));
  v7 = 0;
  operator^<unsigned int>(a2, &v7);
  for ( j = 0; j < v7; ++j )
  {
    v2 = std::vector<int>::operator[](j);
    operator^<int>(a2, v2);
  }
  for ( k = 0; k < 6; ++k )
  {
    v8 = dword_378588C[k];
    if ( v8 > 0 )
    {
      byte_40F2220[v8] = k;
      v3 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)off_3D7A3D8 + 52))(off_3D7A3D8, v8);
      dword_40F2264[k] = v3;
    }
  }
  return v12;
}


// address=[0x1508bd0]
// Decompiled from int __thiscall CDarkTempleRole::Store(struct IBuildingRole *this, struct std::ostream *a2)

void  CDarkTempleRole::Store(std::ostream &) {
  
  int result; // eax
  int *v3; // eax
  int v4; // [esp+0h] [ebp-14h] BYREF
  int v5; // [esp+4h] [ebp-10h] BYREF
  unsigned int j; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]
  int *v8; // [esp+10h] [ebp-4h]

  v8 = (int *)this;
  IBuildingRole::Store(this, a2);
  v4 = 1;
  operator^<unsigned int>(a2, &v4);
  for ( i = 0; i < 6; ++i )
    operator^<int>((int)a2, &v8[i + 96]);
  operator^<int>((int)a2, v8 + 102);
  operator^<int>((int)a2, v8 + 103);
  operator^<int>((int)a2, v8 + 104);
  v5 = std::vector<int>::size(v8 + 105);
  result = operator^<unsigned int>(a2, &v5);
  for ( j = 0; j < v5; ++j )
  {
    v3 = (int *)std::vector<int>::operator[](j);
    result = operator^<int>((int)a2, v3);
  }
  return result;
}


// address=[0x1509b60]
// Decompiled from int __thiscall CDarkTempleRole::~CDarkTempleRole(CDarkTempleRole *this)

 CDarkTempleRole::~CDarkTempleRole(void) {
  
  std::vector<int>::~vector<int>();
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x1509ef0]
// Decompiled from int __thiscall CDarkTempleRole::ClassID(CDarkTempleRole *this)

unsigned long  CDarkTempleRole::ClassID(void)const {
  
  return CDarkTempleRole::m_iClassID;
}


// address=[0x1509f50]
// Decompiled from void __thiscall CDarkTempleRole::FillDialog(CDarkTempleRole *this, struct CBuilding *a2, bool a3)

void  CDarkTempleRole::FillDialog(class CBuilding *,bool) {
  
  ;
}


// address=[0x1509f60]
// Decompiled from void *__thiscall CDarkTempleRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)

int  CDarkTempleRole::GetBuildingNeed(int)const {
  
  return 0;
}


// address=[0x1509f80]
// Decompiled from int __thiscall CDarkTempleRole::GetBuildingRole(CDarkTempleRole *this)

int  CDarkTempleRole::GetBuildingRole(void) {
  
  return 18;
}


// address=[0x1509fa0]
// Decompiled from void *__thiscall CDarkTempleRole::GetPileIdWithGood(std::_Ref_count_base *this, const struct type_info *a2)

int  CDarkTempleRole::GetPileIdWithGood(int)const {
  
  return 0;
}


// address=[0x1509fc0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall CDarkTempleRole::GoodArrive(CDarkTempleRole *this, int a2)

void  CDarkTempleRole::GoodArrive(int) {
  
  ;
}


// address=[0x3d8b128]
// [Decompilation failed for static unsigned long CDarkTempleRole::m_iClassID]

// address=[0x1508ce0]
// Decompiled from int __thiscall CDarkTempleRole::Produce(CDarkTempleRole *this, struct CBuilding *a2)

void  CDarkTempleRole::Produce(class CBuilding *) {
  
  type_info *v2; // eax
  CPlayerMagicData *v3; // eax
  int result; // eax
  int TickCounter; // [esp+0h] [ebp-20h]
  int v6; // [esp+4h] [ebp-1Ch]
  int v7; // [esp+8h] [ebp-18h]
  int i; // [esp+Ch] [ebp-14h]
  int v9; // [esp+10h] [ebp-10h]
  unsigned int v10; // [esp+14h] [ebp-Ch]
  BOOL v11; // [esp+18h] [ebp-8h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Building\\DarkTemple.cpp", 388, "_pBuilding != 0") == 1 )
    __debugbreak();
  v9 = IEntity::OwnerId((unsigned __int8 *)a2);
  v2 = CPlayerManager::PlayerGameData(v9);
  v3 = (CPlayerMagicData *)CPlayerGameData::MagicData(v2);
  result = CPlayerMagicData::ManaAmount(v3);
  if ( result < 10 )
    return result;
  v11 = 0;
  TickCounter = CStateGame::GetTickCounter(g_pGame);
  if ( TickCounter - *((_DWORD *)this + 103) > 30 )
    v11 = *((_DWORD *)this + 97) > 0;
  if ( *((int *)this + 102) < 0
    && BBSupportDbgReport(2, "MapObjects\\Building\\DarkTemple.cpp", 419, "m_iOrderIdx >= 0") == 1 )
  {
    __debugbreak();
  }
  if ( *((int *)this + 102) >= 6
    && BBSupportDbgReport(2, "MapObjects\\Building\\DarkTemple.cpp", 420, "m_iOrderIdx < DARK_ORDER_MAX") == 1 )
  {
    __debugbreak();
  }
  result = *((_DWORD *)this + 102);
  v10 = result;
  for ( i = 0; i < 6; ++i )
  {
    if ( v10 >= 2 )
    {
      result = (int)this;
      if ( *((int *)this + v10 + 96) > 0 )
      {
        v11 = v10;
        break;
      }
    }
    result = (int)(v10 + 1) / 6;
    v10 = (int)(v10 + 1) % 6;
  }
  if ( !v11 )
    return result;
  if ( *((int *)this + v11 + 96) <= 0
    && BBSupportDbgReport(2, "MapObjects\\Building\\DarkTemple.cpp", 444, "m_vOrder[ iOrderIdx ] > 0") == 1 )
  {
    __debugbreak();
  }
  v7 = CStaticConfigVarInt::operator int(dword_40F2264[v11]);
  if ( v7 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\DarkTemple.cpp", 448, "iOrderManaCost > 0") == 1 )
    __debugbreak();
  result = CMagic::CheckAndDecreaseMana(v9, v7);
  if ( (_BYTE)result )
  {
    if ( *((int *)this + v11 + 96) < 100 )
      --*((_DWORD *)this + v11 + 96);
    v6 = dword_378588C[v11];
    CDarkTempleRole::AddSettlerToWorld(this, v9, v6, 1);
    CStatistic::AddProducedSettler((CStatistic *)&g_cStatistic, v9, v6);
    if ( v11 )
      *((_DWORD *)this + 103) = TickCounter;
    result = (int)this;
    *((_DWORD *)this + 102) = (v11 + 1) % 6;
  }
  else
  {
    *((_DWORD *)this + 102) = v11;
  }
  return result;
}


// address=[0x1508f70]
// Decompiled from int __thiscall CDarkTempleRole::AttackEnemies(CDarkTempleRole *this, _DWORD *a2)

void  CDarkTempleRole::AttackEnemies(class CBuilding *) {
  
  int result; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  int v10; // [esp-4h] [ebp-98h]
  char v11[16]; // [esp+0h] [ebp-94h] BYREF
  int v12; // [esp+10h] [ebp-84h]
  int v13; // [esp+14h] [ebp-80h]
  int v14; // [esp+18h] [ebp-7Ch]
  int v15; // [esp+1Ch] [ebp-78h]
  int v16; // [esp+20h] [ebp-74h]
  int LocalPlayerId; // [esp+24h] [ebp-70h]
  unsigned int v18; // [esp+28h] [ebp-6Ch]
  signed int v19; // [esp+2Ch] [ebp-68h]
  unsigned int v20; // [esp+30h] [ebp-64h]
  int v21; // [esp+34h] [ebp-60h]
  int v22; // [esp+38h] [ebp-5Ch]
  CDarkTempleRole *v23; // [esp+3Ch] [ebp-58h]
  int v24; // [esp+40h] [ebp-54h]
  int v25; // [esp+44h] [ebp-50h]
  int v26; // [esp+48h] [ebp-4Ch]
  int v27; // [esp+4Ch] [ebp-48h] BYREF
  int v28; // [esp+50h] [ebp-44h] BYREF
  int v29; // [esp+54h] [ebp-40h]
  BOOL v30; // [esp+58h] [ebp-3Ch]
  int v31; // [esp+5Ch] [ebp-38h]
  int v32; // [esp+60h] [ebp-34h]
  int v33; // [esp+64h] [ebp-30h]
  int v34; // [esp+68h] [ebp-2Ch]
  int v35; // [esp+6Ch] [ebp-28h]
  unsigned int v36; // [esp+70h] [ebp-24h]
  int v37; // [esp+74h] [ebp-20h]
  int v38; // [esp+78h] [ebp-1Ch]
  int v39; // [esp+7Ch] [ebp-18h]
  signed int v40; // [esp+80h] [ebp-14h]
  int v41; // [esp+84h] [ebp-10h]
  unsigned __int8 *v42; // [esp+88h] [ebp-Ch]
  int v43; // [esp+8Ch] [ebp-8h]
  bool v44; // [esp+93h] [ebp-1h]

  v23 = this;
  LocalPlayerId = CPlayerManager::GetLocalPlayerId();
  v15 = 16;
  v14 = 24;
  v13 = 8;
  v12 = 15;
  v32 = IEntity::X(a2) + 1;
  v33 = IEntity::Y(a2) + 2;
  v34 = IEntity::OwnerId((unsigned __int8 *)a2);
  result = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v34, 49, 1u);
  v43 = result;
  if ( result <= 0 )
    return result;
  if ( v43 < 4 )
    v37 = v43 * 16 * v43;
  else
    v37 = 0x4000;
  v16 = v37;
  if ( v43 < 4 )
    v36 = CRandom16::PercentValue(25 * v43);
  else
    v36 = CRandom16::PercentValue(0x64u);
  v20 = v36;
  if ( v43 < 4 )
    v35 = 24 - 2 * (4 - v43);
  else
    v35 = 24;
  v22 = v35;
  v19 = CStateGame::Rand(g_pGame) % 8u + 8;
  v10 = CBuilding::EnsignY(a2);
  v3 = CBuilding::EnsignX(a2);
  v31 = CWorldManager::SectorId(v3, v10);
  if ( !v31 && BBSupportDbgReport(2, "MapObjects\\Building\\DarkTemple.cpp", 514, "iTempleSectorId != 0") == 1 )
    __debugbreak();
  CDarkTempleRole::ShowFireRing(v23, v43, v32, v33, 16);
  v21 = CAlliances::PlayerEnemyBits(v34);
  CSpiralWalk::CSpiralWalk((CSpiralWalk *)v11, v32, v33, v22);
  v38 = 0;
  v40 = 0;
  while ( 1 )
  {
    result = (unsigned __int8)CSpiralWalk::NextXY(v11, &v27, &v28);
    if ( !(_BYTE)result )
      break;
    v41 = CWorldManager::Index(v27, v28);
    if ( CWorldManager::FlagBits(v41, 5u) == 4 )
    {
      v39 = CWorldManager::MapObjectId(v41);
      if ( v39 )
      {
        v4 = ITiling::SectorId(v41);
        if ( v4 == v31 )
        {
          v42 = (unsigned __int8 *)CMapObjectMgr::EntityPtr(v39);
          if ( !v42 && BBSupportDbgReport(2, "MapObjects\\Building\\DarkTemple.cpp", 557, "pEntity != 0") == 1 )
            __debugbreak();
          if ( v42 )
          {
            if ( (IEntity::UniqueId(v42) & 0x20000000) == 0 )
            {
              v5 = IEntity::OwnerId(v42);
              v6 = CAlliances::PlayerBit(v5);
              if ( (v21 & v6) != 0 && (IEntity::ObjType(v42) == 1 || IEntity::ObjType(v42) == 4) )
              {
                if ( IEntity::WarriorType() )
                {
                  v7 = CStateGame::Rand(g_pGame);
                  v30 = v7 < v20;
                  v44 = v7 < v20;
                  v29 = CSpiralWalk::CurrentRadius(v11);
                  if ( v29 > 16 )
                  {
                    result = ++v40;
                    if ( v40 > v19 )
                      return result;
                    if ( v44 )
                    {
                      v18 = (24 - v29 - 16) << 13;
                      v8 = CStateGame::Rand(g_pGame);
                      if ( v8 >= v18 )
                        v44 = 0;
                    }
                  }
                  if ( v44 )
                  {
                    LOBYTE(v25) = CStateGame::Rand(g_pGame) & 0xF;
                    v25 = (unsigned __int8)v25;
                    v26 = CLogic::Effects((DWORD *)g_pLogic);
                    (*(void (__thiscall **)(int, int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v26 + 16))(
                      v26,
                      78,
                      48,
                      v27,
                      v28,
                      v25,
                      0,
                      0);
                    v24 = CLogic::FutureEvents(g_pLogic);
                    (*(void (__thiscall **)(int, int, int, int, int, _DWORD))(*(_DWORD *)v24 + 12))(
                      v24,
                      2,
                      v25 + 6,
                      v39,
                      255,
                      0);
                    v9 = IEntity::OwnerId(v42);
                    if ( v9 == LocalPlayerId )
                      IEntity::SetFlagBits(a2, (EntityFlag)0xA00000u);
                  }
                  result = ++v38;
                  if ( v38 >= v16 )
                    break;
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}


// address=[0x1509350]
// Decompiled from int __thiscall CDarkTempleRole::ShowFireRing(CDarkTempleRole *this, int a2, int a3, int a4, int a5)

void  CDarkTempleRole::ShowFireRing(int,int,int,int) {
  
  int result; // eax
  int v6; // eax
  int v7; // [esp-10h] [ebp-38h]
  unsigned int v8; // [esp+8h] [ebp-20h]
  int v9; // [esp+10h] [ebp-18h]
  int v10; // [esp+14h] [ebp-14h]
  int v11; // [esp+18h] [ebp-10h]
  int v12; // [esp+1Ch] [ebp-Ch]
  int v13; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  v12 = CSpiralOffsets::First(a5);
  v8 = CSpiralOffsets::Last(a5) - v12;
  result = 3 * a2;
  v13 = 3 * a2;
  if ( 3 * a2 > 40 )
    v13 = 40;
  for ( i = 0; i < v13; ++i )
  {
    v10 = v12 + CRandom16::Rand((CUserToolsManager *)((char *)g_pGameData + 44)) % v8;
    if ( i % a2 )
      v11 = 0;
    else
      v11 = 48;
    v9 = CLogic::Effects((DWORD *)g_pLogic);
    v7 = a4 + CSpiralOffsets::DeltaY(v10);
    v6 = CSpiralOffsets::DeltaX(v10);
    result = (*(int (__thiscall **)(int, int, int, int, int, int, _DWORD, _DWORD))(*(_DWORD *)v9 + 16))(
               v9,
               78,
               v11,
               a3 + v6,
               v7,
               2 * i,
               0,
               0);
  }
  return result;
}


// address=[0x1509450]
// Decompiled from int __thiscall CDarkTempleRole::ServantManagement(CDarkTempleRole *this, struct CBuilding *a2)

void  CDarkTempleRole::ServantManagement(class CBuilding *) {
  
  int result; // eax
  CDarkTempleRole *v3; // [esp+0h] [ebp-14h]
  int v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+8h] [ebp-Ch]
  int v6; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v3 = this;
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  v6 = 0;
  result = CSettlerMgr::GetFirstSettlerId((CSettlerMgr *)g_cSettlerMgr, v4, 55);
  for ( i = result; i; i = result )
  {
    v5 = CSettlerMgr::operator[](i);
    if ( (*(unsigned __int8 (__thiscall **)(int, CDarkTempleRole *, int))(*(_DWORD *)v5 + 116))(v5, v3, v4) )
    {
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)g_pDarkTribe + 8))(g_pDarkTribe, i);
      result = ++v6;
      if ( v6 >= 3 )
        break;
    }
    result = IAnimatedEntity::Next(v5);
  }
  return result;
}


// address=[0x15094f0]
// Decompiled from int __thiscall CDarkTempleRole::AddSettlerToWorld(CDarkTempleRole *this, int a2, int a3, int a4)

int  CDarkTempleRole::AddSettlerToWorld(int,int,int) {
  
  int v5; // [esp+0h] [ebp-14h]
  int v6; // [esp+4h] [ebp-10h]
  int v8; // [esp+Ch] [ebp-8h] BYREF
  int v9; // [esp+10h] [ebp-4h] BYREF

  if ( (a3 <= 0 || a3 >= 67)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\DarkTemple.cpp",
         350,
         "( _iSettlerType > 0 ) && ( _iSettlerType < SETTLER_MAX )") == 1 )
  {
    __debugbreak();
  }
  v5 = 0;
  v8 = Y16X16::UnpackXFast(*((_DWORD *)this + 95));
  v9 = Y16X16::UnpackYFast(*((_DWORD *)this + 95));
  v6 = CWorldManager::SectorId(v8, v9);
  if ( v6 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\DarkTemple.cpp", 359, "iSectorId > 0") == 1 )
    __debugbreak();
  if ( CSettlerMgr::IsAddSettlerOk((CSettlerMgr *)g_cSettlerMgr, v8, v9, 0)
    || CSettlerMgr::SearchFreePositionInSector((CSettlerMgr *)g_cSettlerMgr, &v8, &v9, v6, 34) )
  {
    return CSettlerMgr::AddSettler((CSettlerMgr *)g_cSettlerMgr, v8, v9, a2, a3, a4);
  }
  return v5;
}


// address=[0x1509f10]
// Decompiled from void __thiscall CDarkTempleRole::ConvertEventIntoGoal(
        CDarkTempleRole *this,
        struct CBuilding *a2,
        struct CEntityEvent *a3)

void  CDarkTempleRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
  ;
}


// address=[0x1509f20]
// Decompiled from char __thiscall CDarkTempleRole::CrushBuilding(CDarkTempleRole *this)

bool  CDarkTempleRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x1509fd0]
// Decompiled from char __thiscall CDarkTempleRole::TryCrushBuilding(CDarkTempleRole *this)

bool  CDarkTempleRole::TryCrushBuilding(void) {
  
  return 1;
}


