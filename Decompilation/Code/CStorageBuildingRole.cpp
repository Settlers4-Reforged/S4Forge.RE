#include "CStorageBuildingRole.h"

// Definitions for class CStorageBuildingRole

// address=[0x1402160]
// Decompiled from int __cdecl CStorageBuildingRole::New(int a1)

static class CPersistence * __cdecl CStorageBuildingRole::New(std::istream &) {
  
  if ( operator new(0x1BCu) )
    return CStorageBuildingRole::CStorageBuildingRole(a1);
  else
    return 0;
}


// address=[0x14fdc70]
// Decompiled from int __cdecl CStorageBuildingRole::Load(int a1)

static class CStorageBuildingRole * __cdecl CStorageBuildingRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CStorageBuildingRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x151cff0]
// Decompiled from CStorageBuildingRole *__thiscall CStorageBuildingRole::CStorageBuildingRole(CStorageBuildingRole *this)

 CStorageBuildingRole::CStorageBuildingRole(void) {
  
  int i; // [esp+0h] [ebp-8h]

  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CStorageBuildingRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>((char *)this + 428);
  for ( i = 0; i < 43; ++i )
    *((_BYTE *)this + i + 384) = 0;
  *((_DWORD *)this + 95) = 0;
  std::vector<unsigned short>::clear();
  return this;
}


// address=[0x151d070]
// Decompiled from char *__thiscall CStorageBuildingRole::CStorageBuildingRole(char *this, int a2)

 CStorageBuildingRole::CStorageBuildingRole(std::istream &) {
  
  _DWORD v3[2]; // [esp+4h] [ebp-28h] BYREF
  int v4; // [esp+Ch] [ebp-20h] BYREF
  int pExceptionObject; // [esp+10h] [ebp-1Ch] BYREF
  unsigned int i; // [esp+14h] [ebp-18h]
  char *v7; // [esp+18h] [ebp-14h]
  _BYTE v8[4]; // [esp+1Ch] [ebp-10h] BYREF
  int v9; // [esp+28h] [ebp-4h]

  v7 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v9 = 0;
  *(_DWORD *)v7 = &CStorageBuildingRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>(v7 + 428);
  LOBYTE(v9) = 1;
  operator^<unsigned int>(a2, &v4);
  v3[1] = v4;
  if ( v4 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CStorageBuildingRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a2, (int)(v7 + 380));
  LoadArray<unsigned char>(a2, v7 + 384, 43);
  operator^<unsigned int>(a2, v3);
  for ( i = 0; i < v3[0]; ++i )
  {
    operator^<unsigned short>(a2, v8);
    std::vector<unsigned short>::push_back(v8);
  }
  v9 = -1;
  return v7;
}


// address=[0x151d1b0]
// Decompiled from int __thiscall CStorageBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)

void  CStorageBuildingRole::Store(std::ostream &) {
  
  int result; // eax
  __int16 *v3; // eax
  int v4; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h]
  struct IBuildingRole *v7; // [esp+Ch] [ebp-4h]

  v7 = this;
  IBuildingRole::Store(this, a2);
  v4 = 1;
  operator^<unsigned int>(a2, &v4);
  operator^<int>((int)a2, (int *)v7 + 95);
  StoreArray<unsigned char>(a2, (char *)v7 + 384, 43);
  v5 = std::vector<unsigned short>::size((char *)v7 + 428);
  result = operator^<unsigned int>(a2, &v5);
  for ( i = 0; i < v5; ++i )
  {
    v3 = (__int16 *)std::vector<unsigned short>::operator[]((char *)v7 + 428, i);
    operator^<unsigned short>((int)a2, v3);
    result = i + 1;
  }
  return result;
}


// address=[0x151d270]
// Decompiled from int __thiscall CStorageBuildingRole::Init(CStorageBuildingRole *this, struct CBuilding *a2)

void  CStorageBuildingRole::Init(class CBuilding *) {
  
  int v2; // eax
  int v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // eax
  int v8; // [esp-4h] [ebp-20h]
  int v9; // [esp+0h] [ebp-1Ch]
  int v10; // [esp+4h] [ebp-18h]
  int v11; // [esp+8h] [ebp-14h]
  int i; // [esp+Ch] [ebp-10h]
  int j; // [esp+10h] [ebp-Ch]
  __int16 v15; // [esp+1Ah] [ebp-2h] BYREF

  IBuildingRole::InitCommon((int)a2);
  for ( i = 0; i < 43; ++i )
    *((_BYTE *)this + i + 384) = 0;
  std::vector<unsigned short>::clear();
  for ( j = 0; j < *(char *)(*((_DWORD *)this + 94) + 57); ++j )
  {
    if ( *(_BYTE *)(*((_DWORD *)this + 94) + 16 * j + 63) != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\StorageBuilding.cpp",
           192,
           "m_pBuildingInfo->piles[p].type == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v2 = IEntity::WorldIdx();
    v9 = *(char *)(*((_DWORD *)this + 94) + 16 * j + 60) + CWorldManager::X(v2);
    v3 = IEntity::WorldIdx();
    v10 = *(char *)(*((_DWORD *)this + 94) + 16 * j + 61) + CWorldManager::Y(v3);
    v11 = CPileMgr::AddPile(
            (CPileMgr *)&g_cPileMgr,
            v9,
            v10,
            *(char *)(*((_DWORD *)this + 94) + 16 * j + 62),
            0,
            *(char *)(*((_DWORD *)this + 94) + 16 * j + 63),
            *(char *)(*((_DWORD *)this + 94) + 16 * j + 64),
            *(char *)(*((_DWORD *)this + 94) + 16 * j + 65),
            *(_DWORD *)(*((_DWORD *)this + 94) + 16 * j + 68),
            *(_DWORD *)(*((_DWORD *)this + 94) + 16 * j + 72));
    v8 = IEntity::ID();
    v4 = CPileMgr::operator[](v11);
    CPile::SetBuildingId((CPile *)v4, v8);
    if ( *(_BYTE *)(*((_DWORD *)this + 94) + 16 * j + 65) == 1 )
    {
      v5 = CPileMgr::operator[](v11);
      IEntity::ClearFlagBits(v5, Visible);
    }
    v15 = v11;
    std::vector<unsigned short>::push_back(&v15);
  }
  if ( !std::vector<unsigned short>::size((char *)this + 428)
    && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 217, "m_vPileId.size()>0") == 1 )
  {
    __debugbreak();
  }
  if ( IEntity::FlagBits(a2, Selected) )
    (*(void (__thiscall **)(CStorageBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 88))(this, a2, 0);
  v6 = CBuilding::EcoSectorId(a2);
  CStorageBuildingRole::RegisterPilesAndStorageAtEcosector(this, v6);
  return IAnimatedEntity::RegisterForLogicUpdate(14);
}


// address=[0x151d4f0]
// Decompiled from void __thiscall CStorageBuildingRole::PostLoadInit(CStorageBuildingRole *this, struct CBuilding *a2)

void  CStorageBuildingRole::PostLoadInit(class CBuilding *) {
  
  int v2; // eax
  int v3; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  *((_DWORD *)this + 94) = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  v3 = CBuilding::EcoSectorId(a2);
  CStorageBuildingRole::RegisterPilesAndStorageAtEcosector(this, v3);
}


// address=[0x151d540]
// Decompiled from char __thiscall CStorageBuildingRole::Switch(CStorageBuildingRole *this)

void  CStorageBuildingRole::Switch(void) {
  
  unsigned __int8 *BuildingPtr; // eax
  int v2; // eax
  _DWORD *v3; // eax
  int v4; // eax
  int v6; // [esp+0h] [ebp-10h]
  struct CEcoSector *EcoSectorPtr; // [esp+4h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-4h]
  int i; // [esp+Ch] [ebp-4h]

  IBuildingRole::Switch((unsigned __int16 *)this);
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  v2 = CBuilding::EnsignWorldIdx(BuildingPtr);
  v6 = CWorldManager::EcoSectorId(v2);
  EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, v6);
  if ( !EcoSectorPtr && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 252, "pEcosector") == 1 )
    __debugbreak();
  CEcoSector::CleanUpBuildingNeed(EcoSectorPtr, *((unsigned __int16 *)this + 3));
  v3 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v4 = IEntity::FlagBits(v3, (EntityFlag)0x1000u);
  if ( v4 )
  {
    for ( i = 1; i < 43; ++i )
    {
      LOBYTE(v4) = i + (_BYTE)this;
      if ( *((_BYTE *)this + i + 384) )
        LOBYTE(v4) = CEcoSector::RegisterGoodStorage(EcoSectorPtr, *((unsigned __int16 *)this + 3), i);
    }
  }
  else
  {
    for ( j = 1; j < 43; ++j )
    {
      LOBYTE(v4) = j + (_BYTE)this;
      if ( *((_BYTE *)this + j + 384) )
        LOBYTE(v4) = CEcoSector::UnregisterGoodStorage(EcoSectorPtr, *((unsigned __int16 *)this + 3), j);
    }
  }
  return v4;
}


// address=[0x151d670]
// Decompiled from int __thiscall CStorageBuildingRole::LogicUpdate(CStorageBuildingRole *this, struct CBuilding *a2)

void  CStorageBuildingRole::LogicUpdate(class CBuilding *) {
  
  if ( IEntity::FlagBits(a2, Selected) )
    (*(void (__thiscall **)(CStorageBuildingRole *, struct CBuilding *, int))(*(_DWORD *)this + 88))(this, a2, 1);
  return IAnimatedEntity::RegisterForLogicUpdate(14);
}


// address=[0x151d6b0]
// Decompiled from unsigned int __thiscall CStorageBuildingRole::FillGfxInfo(
        CStorageBuildingRole *this,
        struct CBuilding *a2,
        struct SGfxObjectInfo *a3)

void  CStorageBuildingRole::FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &) {
  
  int v3; // eax
  unsigned int result; // eax
  unsigned __int16 *v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int16 *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // [esp-Ch] [ebp-18h]
  int v10; // [esp+0h] [ebp-Ch]
  unsigned int i; // [esp+4h] [ebp-8h]

  (*(void (__thiscall **)(CStorageBuildingRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v9 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo((int)a3, v3, v9, 1, (int)this + 76);
  v10 = 0;
  for ( i = 0; ; ++i )
  {
    result = std::vector<unsigned short>::size((char *)this + 428);
    if ( i >= result )
      break;
    v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
    v6 = CPileMgr::operator[](*v5);
    if ( (unsigned __int8)CPile::IsPatchPile(v6) )
    {
      v7 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
      v8 = CPileMgr::operator[](*v7);
      CPile::GetPatchGfx((CPile *)v8, (struct SGfxObjectInfo *)((char *)a3 + 16 * v10++ + 536));
    }
  }
  return result;
}


// address=[0x151d7a0]
// Decompiled from _DWORD *__thiscall CStorageBuildingRole::FillDialog(CStorageBuildingRole *this, struct CBuilding *a2, bool a3)

void  CStorageBuildingRole::FillDialog(class CBuilding *,bool) {
  
  int v3; // eax
  int v4; // eax
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // eax
  unsigned __int16 *v7; // eax
  int v9; // [esp-8h] [ebp-50h]
  int v10; // [esp-8h] [ebp-50h]
  unsigned int v11; // [esp+4h] [ebp-44h]
  unsigned __int8 *v12; // [esp+8h] [ebp-40h]
  unsigned __int8 *v13; // [esp+Ch] [ebp-3Ch]
  unsigned __int8 *v14; // [esp+10h] [ebp-38h]
  unsigned int i; // [esp+1Ch] [ebp-2Ch]
  CEvn_Event v17; // [esp+20h] [ebp-28h] BYREF
  int v18; // [esp+44h] [ebp-4h]

  dword_3F1E5A4 = 6;
  byte_3F1E5A9 = IEntity::Race(a2);
  byte_3F1E5A8 = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E5AB = 1;
  byte_3F1E5AC = IEntity::FlagBits(a2, (EntityFlag)0x1000u) != 0;
  byte_3F1E5AD = 0;
  v9 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E5AF = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v9, 0);
  v10 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E5B0 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v10, 1u);
  byte_3F1E5AA = 0;
  byte_3F1E5B1 = 0;
  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 428); ++i )
  {
    v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
    v14 = CPileMgr::operator[](*v5);
    if ( (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v14 + 40))(v14) )
    {
      v6 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
      v13 = CPileMgr::operator[](*v6);
      byte_3F1E5B5[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v13 + 40))(v13);
      v7 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
      v12 = CPileMgr::operator[](*v7);
      byte_3F1E5B4[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v12 + 60))(v12);
    }
    else
    {
      byte_3F1E5B5[2 * i] = 0;
      byte_3F1E5B4[2 * i] = 0;
    }
  }
  v11 = 604;
  if ( !a3 )
    v11 = 602;
  CEvn_Event::CEvn_Event(&v17, v11, 0, (unsigned int)&g_cStorageInfo, 0);
  v18 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v17);
  v18 = -1;
  return CEvn_Event::~CEvn_Event(&v17);
}


// address=[0x151d9e0]
// Decompiled from _DWORD *__thiscall CStorageBuildingRole::FillStorageSideBar(
        CStorageBuildingRole *this,
        struct CStorageSideBarInfo *a2,
        bool a3)

void  CStorageBuildingRole::FillStorageSideBar(class CStorageSideBarInfo *,bool) {
  
  unsigned int v4; // [esp+8h] [ebp-30h]
  int i; // [esp+Ch] [ebp-2Ch]
  CEvn_Event v6; // [esp+10h] [ebp-28h] BYREF
  int v7; // [esp+34h] [ebp-4h]

  *((_DWORD *)a2 + 1) = 15;
  for ( i = 0; i < 43; ++i )
  {
    *((_BYTE *)a2 + 2 * i + 8) = i;
    *((_BYTE *)a2 + 2 * i + 9) = *((_BYTE *)this + i + 384);
  }
  v4 = 606;
  if ( !a3 )
    v4 = 607;
  CEvn_Event::CEvn_Event(&v6, v4, 0, (unsigned int)a2, 0);
  v7 = 0;
  if ( !g_pEvnEngine
    && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 396, "g_pEvnEngine != NULL") == 1 )
  {
    __debugbreak();
  }
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v6);
  v7 = -1;
  return CEvn_Event::~CEvn_Event(&v6);
}


// address=[0x151daf0]
// Decompiled from int __thiscall CStorageBuildingRole::GetPileIdWithGood(CStorageBuildingRole *this, unsigned int a2)

int  CStorageBuildingRole::GetPileIdWithGood(int)const {
  
  unsigned __int16 *v3; // eax
  int v4; // esi
  int i; // [esp+8h] [ebp-8h]
  CPile *PilePtr; // [esp+Ch] [ebp-4h]

  if ( a2 > 0x2A )
    return 0;
  for ( i = 0; i < *(char *)(*((_DWORD *)this + 94) + 57); ++i )
  {
    v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    PilePtr = CPileMgr::GetPilePtr(*v3);
    if ( CPile::GetRoleType(PilePtr) != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\StorageBuilding.cpp",
           426,
           "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    if ( (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 60))(PilePtr) == a2
      && (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 40))(PilePtr) < 8 )
    {
      v4 = CPile::AmountComing(PilePtr);
      if ( v4 < 8 - (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 40))(PilePtr) )
        return *(unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    }
  }
  return 0;
}


// address=[0x151dbf0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall CStorageBuildingRole::GoodArrive(CStorageBuildingRole *this, int a2)

void  CStorageBuildingRole::GoodArrive(int) {
  
  ;
}


// address=[0x151dc00]
// Decompiled from int __thiscall CStorageBuildingRole::GetNextFreePile(CStorageBuildingRole *this)

int  CStorageBuildingRole::GetNextFreePile(void) {
  
  unsigned __int16 *v1; // eax
  void *v3; // [esp+0h] [ebp-10h]
  CPile *PilePtr; // [esp+4h] [ebp-Ch]
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < *(char *)(*((_DWORD *)this + 94) + 57); ++i )
  {
    v1 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
    PilePtr = CPileMgr::GetPilePtr(*v1);
    if ( CPile::GetRoleType(PilePtr) != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\StorageBuilding.cpp",
           800,
           "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v3 = (void *)CPile::Role(PilePtr);
    if ( !CTradePileRole::GetTradeRoleType(v3) )
      return *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
  }
  return 0;
}


// address=[0x151dcc0]
// Decompiled from // public: int __thiscall CStorageBuildingRole::ReserveNextFreePile(int)
int __thiscall CStorageBuildingRole::ReserveNextFreePile(_DWORD *this, char a2)

int  CStorageBuildingRole::ReserveNextFreePile(int) {
  
  unsigned __int16 *v2; // eax
  void *v4; // [esp+0h] [ebp-10h]
  CPile *PilePtr; // [esp+8h] [ebp-8h]
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < *(char *)(this[94] + 57); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](this + 107, i);
    PilePtr = CPileMgr::GetPilePtr(*v2);
    if ( CPile::GetRoleType(PilePtr) != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\StorageBuilding.cpp",
           742,
           "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v4 = (void *)CPile::Role(PilePtr);
    if ( !CTradePileRole::GetTradeRoleType(v4) )
    {
      CTradePileRole::SetTradeRoleType(v4, 2);
      CPile::SetGoodType(PilePtr, a2);
      return *(unsigned __int16 *)std::vector<unsigned short>::operator[](this + 107, i);
    }
  }
  return 0;
}


// address=[0x151dd90]
// Decompiled from char __thiscall CStorageBuildingRole::ReserveFreePile(CStorageBuildingRole *this, char a2, int a3)

bool  CStorageBuildingRole::ReserveFreePile(int,int) {
  
  unsigned __int16 *v3; // eax
  void *v5; // [esp+0h] [ebp-10h]
  CPile *PilePtr; // [esp+4h] [ebp-Ch]
  signed int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    if ( i >= *(char *)(*((_DWORD *)this + 94) + 57) )
      return 0;
    if ( *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i) == a3 )
      break;
  }
  v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
  PilePtr = CPileMgr::GetPilePtr(*v3);
  if ( CPile::GetRoleType(PilePtr) != 4
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\StorageBuilding.cpp",
         773,
         "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
  {
    __debugbreak();
  }
  v5 = (void *)CPile::Role(PilePtr);
  if ( CTradePileRole::GetTradeRoleType(v5) )
  {
    if ( BBSupportDbgReport(
           2,
           "MapObjects\\Building\\StorageBuilding.cpp",
           776,
           "rTradePileRole.GetTradeRoleType() == CTradePileRole::TRADEPILE_FREE") == 1 )
      __debugbreak();
  }
  CTradePileRole::SetTradeRoleType(v5, 2);
  CPile::SetGoodType(PilePtr, a2);
  return 1;
}


// address=[0x151de90]
// Decompiled from int __thiscall CStorageBuildingRole::GetSpaceAmount(CStorageBuildingRole *this, int a2)

int  CStorageBuildingRole::GetSpaceAmount(int) {
  
  unsigned __int16 *v2; // eax
  int v3; // esi
  void *v6; // [esp+8h] [ebp-10h]
  signed int i; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+10h] [ebp-8h]
  CPile *PilePtr; // [esp+14h] [ebp-4h]

  v8 = 0;
  for ( i = 0; i < *(char *)(*((_DWORD *)this + 94) + 57); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
    PilePtr = CPileMgr::GetPilePtr(*v2);
    if ( CPile::GetRoleType(PilePtr) != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\StorageBuilding.cpp",
           825,
           "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v6 = (void *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetTradeRoleType(v6) )
    {
      if ( (CTradePileRole::GetTradeRoleType(v6) == 1 || CTradePileRole::GetTradeRoleType(v6) == 2)
        && (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 60))(PilePtr) == a2 )
      {
        v3 = 8 - (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 40))(PilePtr);
        v8 += v3 - CPile::AmountComing(PilePtr);
      }
    }
    else
    {
      v8 += 8;
    }
  }
  return v8;
}


// address=[0x151dfa0]
// Decompiled from int __thiscall CStorageBuildingRole::RegisterPilesAndStorageAtEcosector(CStorageBuildingRole *this, int a2)

void  CStorageBuildingRole::RegisterPilesAndStorageAtEcosector(int) {
  
  int result; // eax
  unsigned __int16 *v3; // eax
  unsigned __int16 *v4; // eax
  unsigned __int16 *v5; // eax
  int v6; // [esp+0h] [ebp-18h]
  void *v7; // [esp+4h] [ebp-14h]
  CEcoSector *v8; // [esp+8h] [ebp-10h]
  CPile *PilePtr; // [esp+Ch] [ebp-Ch]
  signed int i; // [esp+14h] [ebp-4h]
  int j; // [esp+14h] [ebp-4h]

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 855, "_iESID") == 1 )
    __debugbreak();
  v8 = (CEcoSector *)CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, a2);
  if ( !v8 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 857, "pEcosector") == 1 )
    __debugbreak();
  for ( i = 0; ; ++i )
  {
    result = *(char *)(*((_DWORD *)this + 94) + 57);
    if ( i >= result )
      break;
    v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
    PilePtr = CPileMgr::GetPilePtr(*v3);
    if ( CPile::GetRoleType(PilePtr) != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\StorageBuilding.cpp",
           864,
           "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v6 = (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 60))(PilePtr);
    v7 = (void *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetTradeRoleType(v7) )
    {
      if ( CTradePileRole::GetTradeRoleType(v7) == 1 || CTradePileRole::GetTradeRoleType(v7) == 2 )
      {
        if ( !v6 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 876, "iGoodType") == 1 )
          __debugbreak();
        v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
        CEcoSector::RegisterGoodStoragePile(v8, *((unsigned __int16 *)this + 3), *v5, v6);
      }
    }
    else
    {
      v4 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
      CEcoSector::RegisterFreeStoragePile(v8, *((unsigned __int16 *)this + 3), *v4);
    }
  }
  for ( j = 1; j < 43; ++j )
  {
    result = (int)this + j;
    if ( *((_BYTE *)this + j + 384) )
      LOBYTE(result) = CEcoSector::RegisterGoodStorage(v8, *((unsigned __int16 *)this + 3), j);
  }
  return result;
}


// address=[0x151e180]
// Decompiled from void __thiscall CStorageBuildingRole::ExecuteUnforseenGoodTypeChange(
        CStorageBuildingRole *this,
        int a2,
        int a3,
        int a4)

void  CStorageBuildingRole::ExecuteUnforseenGoodTypeChange(int,int,int) {
  
  CPile *PilePtr; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch]
  CEcoSector *EcoSectorPtr; // [esp+8h] [ebp-8h]

  if ( a3 )
  {
    PilePtr = CPileMgr::GetPilePtr(a2);
    if ( CPile::GetRoleType(PilePtr) != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\StorageBuilding.cpp",
           903,
           "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v5 = CBuildingMgr::EcoSectorId((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
    if ( !v5 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 906, "iESID") == 1 )
      __debugbreak();
    EcoSectorPtr = CEcoSectorMgr::GetEcoSectorPtr((CEcoSectorMgr *)g_cESMgr, v5);
    if ( !EcoSectorPtr && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 908, "pEcosector") == 1 )
      __debugbreak();
    CEcoSector::UnregisterGoodStoragePile(EcoSectorPtr, *((unsigned __int16 *)this + 3), a2, a3);
    if ( *((_BYTE *)this + a4 + 384) )
      CEcoSector::RegisterGoodStoragePile(EcoSectorPtr, *((unsigned __int16 *)this + 3), a2, a4);
  }
}


// address=[0x151e290]
// Decompiled from char __thiscall CStorageBuildingRole::UnregisterPile(CStorageBuildingRole *this, int a2)

void  CStorageBuildingRole::UnregisterPile(int) {
  
  int TradeRoleType; // eax
  int v3; // eax
  unsigned __int16 *v4; // eax
  int v6; // [esp+0h] [ebp-1Ch]
  int v7; // [esp+4h] [ebp-18h]
  CEcoSector *v8; // [esp+8h] [ebp-14h]
  struct CPile *PilePtr; // [esp+Ch] [ebp-10h]
  void *v10; // [esp+10h] [ebp-Ch]
  signed int i; // [esp+14h] [ebp-8h]

  LOBYTE(TradeRoleType) = (_BYTE)this;
  if ( !*((_WORD *)this + 3) )
    return TradeRoleType;
  v3 = CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v7 = CBuilding::EcoSectorId(v3);
  if ( !v7 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 933, "iESID") == 1 )
    __debugbreak();
  v8 = (CEcoSector *)CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, v7);
  if ( !v8 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 935, "pEcosector") == 1 )
    __debugbreak();
  for ( i = 0; ; ++i )
  {
    TradeRoleType = *((_DWORD *)this + 94);
    if ( i >= *(char *)(TradeRoleType + 57) )
      break;
    if ( a2 == *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i) )
    {
      v4 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
      PilePtr = CPileMgr::GetPilePtr(*v4);
      v10 = (void *)CPile::Role(PilePtr);
      if ( CTradePileRole::GetTradeRoleType(v10) )
      {
        if ( CTradePileRole::GetTradeRoleType(v10) == 1
          || (TradeRoleType = CTradePileRole::GetTradeRoleType(v10), TradeRoleType == 2) )
        {
          v6 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)PilePtr + 60))(PilePtr);
          if ( !v6 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 955, "iGoodType") == 1 )
            __debugbreak();
          LOBYTE(TradeRoleType) = CEcoSector::UnregisterGoodStoragePile(v8, *((unsigned __int16 *)this + 3), a2, v6);
        }
      }
      else
      {
        LOBYTE(TradeRoleType) = CEcoSector::UnregisterFreeStoragePile(v8, *((unsigned __int16 *)this + 3), a2);
      }
      return TradeRoleType;
    }
  }
  return TradeRoleType;
}


// address=[0x151e430]
// Decompiled from void __thiscall CStorageBuildingRole::SwitchGood(CStorageBuildingRole *this, int a2, int a3)

void  CStorageBuildingRole::SwitchGood(int,int) {
  
  unsigned __int16 *v3; // eax
  _DWORD *v4; // eax
  int v5; // esi
  int v6; // [esp+4h] [ebp-1Ch]
  CEcoSector *v7; // [esp+8h] [ebp-18h]
  unsigned __int8 *BuildingPtr; // [esp+Ch] [ebp-14h]
  int j; // [esp+10h] [ebp-10h]
  signed int i; // [esp+14h] [ebp-Ch]
  CPile *PilePtr; // [esp+18h] [ebp-8h]

  if ( (a2 <= 0 || a2 >= 43)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\StorageBuilding.cpp",
         458,
         "0 < _iGoodType && _iGoodType < GOOD_MAX") == 1 )
  {
    __debugbreak();
  }
  v6 = CBuildingMgr::EcoSectorId((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  if ( !v6 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 461, "iESID") == 1 )
    __debugbreak();
  v7 = (CEcoSector *)CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, v6);
  if ( !v7 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 463, "pEcosector") == 1 )
    __debugbreak();
  if ( a3 )
  {
    v4 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
    if ( IEntity::FlagBits(v4, (EntityFlag)0x1000u) )
      CEcoSector::RegisterGoodStorage(v7, *((unsigned __int16 *)this + 3), a2);
  }
  else
  {
    CEcoSector::UnregisterGoodStorage(v7, *((unsigned __int16 *)this + 3), a2);
    for ( i = 0; i < *(char *)(*((_DWORD *)this + 94) + 57); ++i )
    {
      v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
      PilePtr = CPileMgr::GetPilePtr(*v3);
      if ( CPile::GetRoleType(PilePtr) != 4
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\StorageBuilding.cpp",
             474,
             "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
      {
        __debugbreak();
      }
      if ( (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 60))(PilePtr) == a2 )
        CPile::NotifyTargetDieAndDetachAllObservers(PilePtr);
    }
    for ( j = CStorageBuildingRole::GetReservedPile(this, a2); j; j = CStorageBuildingRole::GetReservedPile(this, a2) )
    {
      CStorageBuildingRole::CheckEmptyPile(this, j);
      CPileMgr::GetPilePtr(j);
    }
  }
  *((_BYTE *)this + a2 + 384) = a3;
  BuildingPtr = CBuildingMgr::GetBuildingPtr((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  if ( !BuildingPtr
    && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 503, "pTradingBuilding!=NULL") == 1 )
  {
    __debugbreak();
  }
  if ( BuildingPtr )
  {
    v5 = IEntity::OwnerId(BuildingPtr);
    if ( v5 == CPlayerManager::GetLocalPlayerId() && IEntity::IsSelected((IEntity *)BuildingPtr) )
      CStorageBuildingRole::FillStorageSideBar(this, (struct CStorageSideBarInfo *)&g_cStorageSideBarInfo, 1);
  }
}


// address=[0x151e690]
// Decompiled from char __thiscall CStorageBuildingRole::NotifyChangeEcoSector(
        CStorageBuildingRole *this,
        struct CPile *a2,
        int a3,
        int a4)

void  CStorageBuildingRole::NotifyChangeEcoSector(class CPile *,int,int) {
  
  int TradeRoleType; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v10; // [esp+0h] [ebp-18h]
  void *v11; // [esp+4h] [ebp-14h]
  CEcoSector *v12; // [esp+8h] [ebp-10h]
  CEcoSector *v13; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  if ( CPile::GetRoleType(a2) != 4
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\StorageBuilding.cpp",
         525,
         "_pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
  {
    __debugbreak();
  }
  LOBYTE(TradeRoleType) = 0;
  if ( a3 == a4 )
    return TradeRoleType;
  v13 = (CEcoSector *)CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, a3);
  if ( !v13 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 530, "pOldEcosector") == 1 )
    __debugbreak();
  v12 = (CEcoSector *)CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, a4);
  if ( !v12 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 532, "pNewEcosector") == 1 )
    __debugbreak();
  v10 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 60))(a2);
  v11 = (void *)CPile::Role(a2);
  if ( CTradePileRole::GetTradeRoleType(v11) )
  {
    if ( CTradePileRole::GetTradeRoleType(v11) == 1
      || (TradeRoleType = CTradePileRole::GetTradeRoleType(v11), TradeRoleType == 2) )
    {
      if ( !v10 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 546, "iGoodType") == 1 )
        __debugbreak();
      v7 = IEntity::ID();
      CEcoSector::UnregisterGoodStoragePile(v13, *((unsigned __int16 *)this + 3), v7, v10);
      v8 = IEntity::ID();
      LOBYTE(TradeRoleType) = CEcoSector::RegisterGoodStoragePile(v12, *((unsigned __int16 *)this + 3), v8, v10);
    }
  }
  else
  {
    v5 = IEntity::ID();
    CEcoSector::UnregisterFreeStoragePile(v13, *((unsigned __int16 *)this + 3), v5);
    v6 = IEntity::ID();
    LOBYTE(TradeRoleType) = CEcoSector::RegisterFreeStoragePile(v12, *((unsigned __int16 *)this + 3), v6);
  }
  for ( i = 1; i < 43; ++i )
  {
    if ( *((_BYTE *)this + i + 384) )
    {
      CEcoSector::UnregisterGoodStorage(v13, *((unsigned __int16 *)this + 3), i);
      CEcoSector::RegisterGoodStorage(v12, *((unsigned __int16 *)this + 3), i);
    }
    LOBYTE(TradeRoleType) = i + 1;
  }
  return TradeRoleType;
}


// address=[0x151f900]
// Decompiled from int __thiscall CStorageBuildingRole::~CStorageBuildingRole(CStorageBuildingRole *this)

 CStorageBuildingRole::~CStorageBuildingRole(void) {
  
  std::vector<unsigned short>::~vector<unsigned short>((char *)this + 428);
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x151f9f0]
// Decompiled from int __thiscall CStorageBuildingRole::ClassID(CStorageBuildingRole *this)

unsigned long  CStorageBuildingRole::ClassID(void)const {
  
  return CStorageBuildingRole::m_iClassID;
}


// address=[0x151fa50]
// Decompiled from void *__thiscall CStorageBuildingRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)

int  CStorageBuildingRole::GetBuildingNeed(int)const {
  
  return 0;
}


// address=[0x151fa70]
// Decompiled from int __thiscall CStorageBuildingRole::GetBuildingRole(CStorageBuildingRole *this)

int  CStorageBuildingRole::GetBuildingRole(void) {
  
  return 12;
}


// address=[0x3d8b7a0]
// [Decompilation failed for static unsigned long CStorageBuildingRole::m_iClassID]

// address=[0x151e870]
// Decompiled from int __thiscall CStorageBuildingRole::NrSelectedStores(CStorageBuildingRole *this)

int  CStorageBuildingRole::NrSelectedStores(void) {
  
  int v2; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = 0;
  for ( i = 0; i < 43; ++i )
  {
    if ( *((_BYTE *)this + i + 384) )
      ++v2;
  }
  return v2;
}


// address=[0x151e8c0]
// Decompiled from int __thiscall CStorageBuildingRole::NrUsedPiles(CStorageBuildingRole *this)

int  CStorageBuildingRole::NrUsedPiles(void) {
  
  unsigned __int16 *v1; // eax
  void *v3; // [esp+0h] [ebp-14h]
  CPile *PilePtr; // [esp+4h] [ebp-10h]
  int v6; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]

  v6 = 0;
  for ( i = 0; i < *(char *)(*((_DWORD *)this + 94) + 57); ++i )
  {
    v1 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
    PilePtr = CPileMgr::GetPilePtr(*v1);
    if ( CPile::GetRoleType(PilePtr) != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\StorageBuilding.cpp",
           592,
           "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    v3 = (void *)CPile::Role(PilePtr);
    if ( CTradePileRole::GetTradeRoleType(v3) )
      ++v6;
  }
  return v6;
}


// address=[0x151e970]
// Decompiled from // private: void __thiscall CStorageBuildingRole::CheckGoodToStore(void)
char __thiscall CStorageBuildingRole::CheckGoodToStore(int this)

void  CStorageBuildingRole::CheckGoodToStore(void) {
  
  int FullPile; // eax
  int v2; // esi
  unsigned __int16 *v3; // eax
  int v5; // [esp+4h] [ebp-20h]
  void *v6; // [esp+8h] [ebp-1Ch]
  int v7; // [esp+Ch] [ebp-18h]
  int v8; // [esp+10h] [ebp-14h]
  CEcoSector *v9; // [esp+14h] [ebp-10h]
  signed int i; // [esp+18h] [ebp-Ch]
  CPile *PilePtr; // [esp+1Ch] [ebp-8h]
  CPile *v12; // [esp+1Ch] [ebp-8h]

  FullPile = CStorageBuildingRole::NrSelectedStores((CStorageBuildingRole *)this);
  if ( !FullPile )
    return FullPile;
  FullPile = CStorageBuildingRole::NrUsedPiles((CStorageBuildingRole *)this);
  if ( FullPile == *(char *)(*(_DWORD *)(this + 376) + 57) )
    return FullPile;
  v5 = CBuildingMgr::EcoSectorId((CBuildingMgr *)g_cBuildingMgr, *(unsigned __int16 *)(this + 6));
  v9 = (CEcoSector *)CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, v5);
  LOBYTE(FullPile) = CEcoSector::HaveFreeCarrier(v9);
  if ( !(_BYTE)FullPile )
    return FullPile;
  *(_DWORD *)(this + 380) = CStorageBuildingRole::GetNextGoodToCheck(
                              (CStorageBuildingRole *)this,
                              *(_DWORD *)(this + 380));
  LOBYTE(FullPile) = *(_BYTE *)(this + *(_DWORD *)(this + 380) + 384);
  if ( !(_BYTE)FullPile )
    return FullPile;
  FullPile = CEcoSector::GetFullPile(v9, *(_DWORD *)(this + 380));
  v8 = FullPile;
  if ( !FullPile )
    return FullPile;
  v7 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)this + 56))(this, *(_DWORD *)(this + 380));
  if ( v7 )
  {
    PilePtr = CPileMgr::GetPilePtr(v7);
    FullPile = (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 40))(PilePtr);
    if ( FullPile != 8 )
    {
      v2 = (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 40))(PilePtr);
      FullPile = CPile::AmountComing(PilePtr);
      if ( FullPile + v2 < 8 )
        LOBYTE(FullPile) = CEcoSector::TransportGood(v9, v8, *(unsigned __int16 *)(this + 6));
    }
  }
  else
  {
    for ( i = 0; ; ++i )
    {
      FullPile = *(_DWORD *)(this + 376);
      if ( i >= *(char *)(FullPile + 57) )
        break;
      v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((void *)(this + 428), i);
      v12 = CPileMgr::GetPilePtr(*v3);
      if ( CPile::GetRoleType(v12) != 4
        && BBSupportDbgReport(
             2,
             "MapObjects\\Building\\StorageBuilding.cpp",
             657,
             "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
      {
        __debugbreak();
      }
      v6 = (void *)CPile::Role(v12);
      if ( !CTradePileRole::GetTradeRoleType(v6) )
      {
        CPile::SetGoodType(v12, *(_DWORD *)(this + 380));
        CTradePileRole::SetTradeRoleType(v6, 1);
        CEcoSector::TransportGood(v9, v8, *(unsigned __int16 *)(this + 6));
        IAnimatedEntity::RegisterForLogicUpdate(1);
      }
    }
  }
  return FullPile;
}


// address=[0x151eb90]
// Decompiled from int __thiscall CStorageBuildingRole::GetNextGoodToCheck(CStorageBuildingRole *this, int a2)

int  CStorageBuildingRole::GetNextGoodToCheck(int) {
  
  int v3; // [esp+4h] [ebp-4h]

  v3 = a2 + 1;
  if ( a2 == 42 )
    v3 = 1;
  while ( !*((_BYTE *)this + v3 + 384) && v3 != a2 )
  {
    if ( ++v3 == 43 )
      v3 = 1;
  }
  return v3;
}


// address=[0x151ebf0]
// Decompiled from int __thiscall CStorageBuildingRole::GetReservedPile(CStorageBuildingRole *this, int a2)

int  CStorageBuildingRole::GetReservedPile(int) {
  
  unsigned __int16 *v2; // eax
  signed int i; // [esp+4h] [ebp-8h]
  CPile *PilePtr; // [esp+8h] [ebp-4h]

  for ( i = 0; i < *(char *)(*((_DWORD *)this + 94) + 57); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
    PilePtr = CPileMgr::GetPilePtr(*v2);
    if ( CPile::GetRoleType(PilePtr) != 4
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\StorageBuilding.cpp",
           715,
           "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
    {
      __debugbreak();
    }
    if ( (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 60))(PilePtr) == a2
      && !(*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 40))(PilePtr) )
    {
      return *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 428, i);
    }
  }
  return 0;
}


// address=[0x151ecc0]
// Decompiled from int __thiscall CStorageBuildingRole::CheckEmptyPile(CStorageBuildingRole *this, int a2)

void  CStorageBuildingRole::CheckEmptyPile(int) {
  
  int result; // eax
  int v3; // eax
  CPaneContainer *v4; // [esp+0h] [ebp-14h]
  int v5; // [esp+4h] [ebp-10h]
  CEcoSector *v6; // [esp+8h] [ebp-Ch]
  CPile *PilePtr; // [esp+10h] [ebp-4h]

  PilePtr = CPileMgr::GetPilePtr(a2);
  if ( CPile::GetRoleType(PilePtr) != 4
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\StorageBuilding.cpp",
         979,
         "pPile->GetRoleType() == IPileRole::PILE_TRADE") == 1 )
  {
    __debugbreak();
  }
  result = (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 40))(PilePtr);
  if ( result )
    return result;
  v5 = CBuildingMgr::EcoSectorId((CBuildingMgr *)g_cBuildingMgr, *((unsigned __int16 *)this + 3));
  if ( !v5 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 983, "iESID") == 1 )
    __debugbreak();
  v6 = (CEcoSector *)CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, v5);
  if ( !v6 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 985, "pEcosector") == 1 )
    __debugbreak();
  v3 = (*(int (__thiscall **)(CPile *))(*(_DWORD *)PilePtr + 60))(PilePtr);
  CEcoSector::UnregisterGoodStoragePile(v6, *((unsigned __int16 *)this + 3), a2, v3);
  CEcoSector::RegisterFreeStoragePile(v6, *((unsigned __int16 *)this + 3), a2);
  CPile::SetGoodType(PilePtr, 0);
  v4 = (CPaneContainer *)CPile::Role(PilePtr);
  CTradePileRole::SetExpectedAmount(v4, 0);
  return CTradePileRole::SetTradeRoleType(v4, 0);
}


// address=[0x151ee00]
// Decompiled from char __thiscall CStorageBuildingRole::CrushBuilding(CStorageBuildingRole *this)

bool  CStorageBuildingRole::CrushBuilding(void) {
  
  int v1; // eax
  CEcoSector *v3; // [esp+0h] [ebp-10h]
  int v4; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  if ( !*((_WORD *)this + 3) )
    return 1;
  v1 = CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v4 = CBuilding::EcoSectorId(v1);
  if ( !v4 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 103, "iESID") == 1 )
    __debugbreak();
  v3 = (CEcoSector *)CEcoSectorMgr::EntryPtr((CEcoSectorMgr *)g_cESMgr, v4);
  if ( !v3 && BBSupportDbgReport(2, "MapObjects\\Building\\StorageBuilding.cpp", 105, "pEcosector") == 1 )
    __debugbreak();
  for ( i = 1; i < 43; ++i )
    CEcoSector::UnregisterGoodStorage(v3, *((unsigned __int16 *)this + 3), i);
  return 1;
}


// address=[0x151fa10]
// Decompiled from void __thiscall CStorageBuildingRole::ConvertEventIntoGoal(
        CStorageBuildingRole *this,
        struct CBuilding *a2,
        struct CEntityEvent *a3)

void  CStorageBuildingRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
  ;
}


// address=[0x151faf0]
// Decompiled from char __thiscall CStorageBuildingRole::TryCrushBuilding(CStorageBuildingRole *this)

bool  CStorageBuildingRole::TryCrushBuilding(void) {
  
  return 1;
}


