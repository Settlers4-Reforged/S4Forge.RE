#include "CProductionBuildingRole.h"

// Definitions for class CProductionBuildingRole

// address=[0x1401800]
// Decompiled from int __cdecl CProductionBuildingRole::New(int a1)
static class CPersistence * __cdecl CProductionBuildingRole::New(std::istream &) {
  
  if ( operator new(0x1B0u) )
    return CProductionBuildingRole::CProductionBuildingRole(a1);
  else
    return 0;
}


// address=[0x14fca80]
// Decompiled from CProductionBuildingRole *__thiscall CProductionBuildingRole::CProductionBuildingRole(CProductionBuildingRole *this)
 CProductionBuildingRole::CProductionBuildingRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CProductionBuildingRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>((char *)this + 384);
  std::vector<unsigned short>::vector<unsigned short>((char *)this + 400);
  std::vector<unsigned char>::vector<unsigned char>();
  return this;
}


// address=[0x14fccb0]
// Decompiled from int __thiscall CProductionBuildingRole::~CProductionBuildingRole(CProductionBuildingRole *this)
 CProductionBuildingRole::~CProductionBuildingRole(void) {
  
  std::vector<unsigned char>::~vector<unsigned char>();
  std::vector<unsigned short>::~vector<unsigned short>((char *)this + 400);
  std::vector<unsigned short>::~vector<unsigned short>((char *)this + 384);
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14fd140]
// Decompiled from int __thiscall CProductionBuildingRole::ClassID(CProductionBuildingRole *this)
unsigned long  CProductionBuildingRole::ClassID(void)const {
  
  return CProductionBuildingRole::m_iClassID;
}


// address=[0x14fd520]
// Decompiled from int __thiscall CProductionBuildingRole::GetBuildingRole(CProductionBuildingRole *this)
int  CProductionBuildingRole::GetBuildingRole(void) {
  
  return 4;
}


// address=[0x14fdb70]
// Decompiled from int __cdecl CProductionBuildingRole::Load(int a1)
static class CProductionBuildingRole * __cdecl CProductionBuildingRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CProductionBuildingRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x1516150]
// Decompiled from int __thiscall CProductionBuildingRole::LogicUpdate(_BYTE *this, _DWORD *a2)
void  CProductionBuildingRole::LogicUpdate(class CBuilding *) {
  
  int result; // eax
  unsigned __int8 *v3; // eax
  char v4[24]; // [esp+4h] [ebp-3Ch] BYREF
  int v5; // [esp+1Ch] [ebp-24h]
  int v6; // [esp+20h] [ebp-20h]
  _DWORD *SettlerPtr; // [esp+24h] [ebp-1Ch]
  int v8; // [esp+28h] [ebp-18h]
  char v9; // [esp+2Ch] [ebp-14h]
  _BYTE *v10; // [esp+30h] [ebp-10h]
  int v11; // [esp+3Ch] [ebp-4h]

  v10 = this;
  result = IEntity::FlagBits(a2, Selected);
  if ( result )
    result = (*(int (__thiscall **)(_BYTE *, _DWORD *, int))(*(_DWORD *)v10 + 88))(v10, a2, 1);
  v9 = v10[4];
  if ( v9 == 1 )
  {
    result = (*(int (__thiscall **)(_BYTE *, _DWORD *))(*(_DWORD *)v10 + 120))(v10, a2);
    if ( !(_BYTE)result )
      return IAnimatedEntity::RegisterForLogicUpdate(31);
    v10[4] = 3;
    return result;
  }
  if ( v9 == 2 )
  {
    if ( (unsigned __int8)v10[5] > (int)*(unsigned __int8 *)(*((_DWORD *)v10 + 94) + 480) )
    {
      v10[5] = 0;
      v10[4] = 3;
      return IAnimatedEntity::RegisterForLogicUpdate(1);
    }
    else
    {
      ++v10[5];
      return IAnimatedEntity::RegisterForLogicUpdate(14);
    }
  }
  if ( v9 != 3 )
    return result;
  if ( !v10[29]
    || !IEntity::FlagBits(a2, (EntityFlag)0x1000u)
    || !(unsigned __int8)CProductionBuildingRole::HaveFreeSlotForProduct(a2)
    || !(unsigned __int8)CProductionBuildingRole::HaveMaterial(a2)
    || !(unsigned __int8)CProductionBuildingRole::HaveProductionOrder(v10) )
  {
    return IAnimatedEntity::RegisterForLogicUpdate(31);
  }
  SettlerPtr = (_DWORD *)CSettlerMgr::GetSettlerPtr(*((unsigned __int16 *)v10 + 4));
  if ( IEntity::FlagBits(SettlerPtr, Visible) )
  {
    if ( BBSupportDbgReport(
           2,
           (int)"MapObjects\\Building\\ProductionBuilding.cpp",
           384,
           (int)"pSettler->FlagBits(ENTITY_FLAG_VISIBLE)==0") == 1 )
      __debugbreak();
  }
  v8 = CSettlerMgr::operator[](*((unsigned __int16 *)v10 + 4));
  v3 = (unsigned __int8 *)std::vector<unsigned char>::operator[](0);
  v6 = CEntityEvent::CEntityEvent(3, 0, 0, *v3, 0);
  v5 = v6;
  v11 = 0;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 80))(v8, v6);
  v11 = -1;
  CEntityEvent::~CEntityEvent(v4);
  return (*(int (__thiscall **)(_BYTE *, _DWORD *, int))(*(_DWORD *)v10 + 72))(v10, a2, 1);
}


// address=[0x1516390]
// Decompiled from unsigned int __thiscall CProductionBuildingRole::FillGfxInfo(  CProductionBuildingRole *this,  struct CBuilding *a2,  struct SGfxObjectInfo *a3)
void  CProductionBuildingRole::FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  CSettler *v6; // eax
  unsigned __int16 *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int16 *v9; // eax
  unsigned __int8 *v10; // eax
  unsigned int result; // eax
  unsigned __int16 *v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int16 *v14; // eax
  unsigned __int8 *v15; // eax
  int v16; // [esp-Ch] [ebp-2F0h]
  int v17; // [esp+4h] [ebp-2E0h]
  unsigned int i; // [esp+8h] [ebp-2DCh]
  unsigned int j; // [esp+8h] [ebp-2DCh]
  _DWORD v21[180]; // [esp+10h] [ebp-2D4h] BYREF

  (*(void (__thiscall **)(CProductionBuildingRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v16 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo((int)a3, v3, v16, 1, (int)this + 76);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  *((_BYTE *)a3 + 715) = CPlayerManager::Color(v4);
  if ( *((_BYTE *)this + 356) )
  {
    CGfxManager::GetEffectGfxInfo(
      (CGfxManager *)g_pGfxManager,
      (struct SGfxObjectInfo *)v21,
      *((unsigned __int8 *)this + 356),
      0,
      *((unsigned __int8 *)this + 359));
    *((_DWORD *)a3 + 26) = v21[0];
    *((_DWORD *)a3 + 27) = v21[1];
    *((_DWORD *)a3 + 28) = *((__int16 *)this + 180);
    *((_DWORD *)a3 + 29) = *((__int16 *)this + 181);
  }
  v5 = IEntity::OwnerId((unsigned __int8 *)a2);
  IBuildingRole::MiniFlag(this, a3, v5);
  if ( *((_BYTE *)this + 29) == 1 )
  {
    v6 = (CSettler *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 4));
    CSettler::GetPatchGfx(v6, (struct SGfxObjectInfo *)((char *)a3 + 200));
  }
  v17 = 0;
  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 384); ++i )
  {
    v7 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 384, i);
    v8 = CPileMgr::operator[](*v7);
    if ( (unsigned __int8)CPile::IsPatchPile(v8) )
    {
      v9 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 384, i);
      v10 = CPileMgr::operator[](*v9);
      CPile::GetPatchGfx((CPile *)v10, (struct SGfxObjectInfo *)((char *)a3 + 16 * v17++ + 536));
    }
  }
  for ( j = 0; ; ++j )
  {
    result = std::vector<unsigned short>::size((char *)this + 400);
    if ( j >= result )
      break;
    v12 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 400, j);
    v13 = CPileMgr::operator[](*v12);
    if ( (unsigned __int8)CPile::IsPatchPile(v13) )
    {
      v14 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 400, j);
      v15 = CPileMgr::operator[](*v14);
      CPile::GetPatchGfx((CPile *)v15, (struct SGfxObjectInfo *)((char *)a3 + 16 * v17++ + 536));
    }
  }
  return result;
}


// address=[0x15166b0]
// Decompiled from int __thiscall CProductionBuildingRole::Init(CProductionBuildingRole *this, struct CBuilding *a2)
void  CProductionBuildingRole::Init(class CBuilding *) {
  
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // esi
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // eax
  int result; // eax
  int v9; // [esp-4h] [ebp-38h]
  int v10; // [esp-4h] [ebp-38h]
  int v11; // [esp+4h] [ebp-30h]
  int v12; // [esp+8h] [ebp-2Ch]
  int v13; // [esp+Ch] [ebp-28h]
  int v14; // [esp+10h] [ebp-24h]
  int v15; // [esp+14h] [ebp-20h]
  int v16; // [esp+18h] [ebp-1Ch]
  char v17; // [esp+1Ch] [ebp-18h]
  int v18; // [esp+20h] [ebp-14h]
  int i; // [esp+24h] [ebp-10h]
  __int16 v21; // [esp+2Eh] [ebp-6h] BYREF
  __int16 v22; // [esp+30h] [ebp-4h] BYREF
  char v23; // [esp+33h] [ebp-1h] BYREF

  IBuildingRole::InitCommon((int)a2);
  *((_BYTE *)this + 4) = 1;
  v18 = 0;
  for ( i = 0; i < *(char *)(*((_DWORD *)this + 94) + 57); ++i )
  {
    v17 = *(_BYTE *)(*((_DWORD *)this + 94) + 16 * i + 63);
    if ( v17 )
    {
      if ( v17 == 1 )
      {
        v11 = *(char *)(*((_DWORD *)this + 94) + 16 * i + 60) + IEntity::X(a2);
        v12 = *(char *)(*((_DWORD *)this + 94) + 16 * i + 61) + IEntity::Y(a2);
        v15 = CPileMgr::AddPile(
                (CPileMgr *)&g_cPileMgr,
                v11,
                v12,
                *(char *)(*((_DWORD *)this + 94) + 16 * i + 62),
                0,
                *(char *)(*((_DWORD *)this + 94) + 16 * i + 63),
                0,
                0,
                0,
                0);
        v10 = IEntity::ID();
        v7 = CPileMgr::operator[](v15);
        CPile::SetBuildingId((CPile *)v7, v10);
        v21 = v15;
        std::vector<unsigned short>::push_back(&v21);
      }
    }
    else
    {
      v2 = CBuilding::EnsignPackedXY(a2);
      v3 = Y16X16::UnpackXFast(v2);
      v13 = CSpiralOffsets::DeltaX(v18) + v3;
      v4 = CBuilding::EnsignPackedXY(a2);
      v5 = Y16X16::UnpackYFast(v4);
      v14 = CSpiralOffsets::DeltaY(v18) + v5;
      v16 = CPileMgr::AddPile(
              (CPileMgr *)&g_cPileMgr,
              v13,
              v14,
              *(char *)(*((_DWORD *)this + 94) + 16 * i + 62),
              0,
              *(char *)(*((_DWORD *)this + 94) + 16 * i + 63),
              0,
              0,
              0,
              0);
      v9 = IEntity::ID();
      v6 = CPileMgr::operator[](v16);
      CPile::SetBuildingId((CPile *)v6, v9);
      v22 = v16;
      std::vector<unsigned short>::push_back(&v22);
      v23 = *(_BYTE *)(*((_DWORD *)this + 94) + 16 * i + 62);
      std::vector<unsigned char>::push_back(&v23);
      ++v18;
    }
  }
  if ( !std::vector<unsigned short>::size((char *)this + 384)
    && BBSupportDbgReport(2, "MapObjects\\Building\\ProductionBuilding.cpp", 232, "m_vProdPileId.size() > 0") == 1 )
  {
    __debugbreak();
  }
  if ( !std::vector<unsigned short>::size((char *)this + 400)
    && BBSupportDbgReport(2, "MapObjects\\Building\\ProductionBuilding.cpp", 233, "m_vDeliverPileId.size() > 0") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 380) = 0;
  *((_BYTE *)this + 381) = 0;
  IAnimatedEntity::RegisterForLogicUpdate(2);
  result = IEntity::FlagBits(a2, Selected);
  if ( result )
    return (*(int (__thiscall **)(CProductionBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 88))(
             this,
             a2,
             0);
  return result;
}


// address=[0x15169a0]
// Decompiled from int __thiscall CProductionBuildingRole::PostLoadInit(CProductionBuildingRole *this, struct CBuilding *a2)
void  CProductionBuildingRole::PostLoadInit(class CBuilding *) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  result = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  *((_DWORD *)this + 94) = result;
  return result;
}


// address=[0x15169d0]
// Decompiled from unsigned int __thiscall CProductionBuildingRole::LockPiles(  CProductionBuildingRole *this,  struct CBuilding *a2,  bool a3)
void  CProductionBuildingRole::LockPiles(class CBuilding *,bool) {
  
  unsigned __int16 *v3; // eax
  unsigned __int8 *v4; // eax
  unsigned int result; // eax
  unsigned __int16 *v6; // eax
  unsigned __int8 *v7; // eax
  unsigned int i; // [esp+4h] [ebp-4h]
  unsigned int j; // [esp+4h] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 384); ++i )
  {
    v3 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 384, i);
    v4 = CPileMgr::operator[](*v3);
    if ( a3 )
      IEntity::SetFlagBits(v4, (EntityFlag)0x10u);
    else
      IEntity::ClearFlagBits(v4, (EntityFlag)0x10u);
  }
  for ( j = 0; ; ++j )
  {
    result = std::vector<unsigned short>::size((char *)this + 400);
    if ( j >= result )
      break;
    v6 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 400, j);
    v7 = CPileMgr::operator[](*v6);
    if ( a3 )
      IEntity::SetFlagBits(v7, (EntityFlag)0x10u);
    else
      IEntity::ClearFlagBits(v7, (EntityFlag)0x10u);
  }
  return result;
}


// address=[0x1516af0]
// Decompiled from char __thiscall CProductionBuildingRole::SettlerEnter(_DWORD *this, unsigned __int8 *a2, int a3)
bool  CProductionBuildingRole::SettlerEnter(class CBuilding *,int) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  float v7; // xmm0_4
  int v8; // eax
  int v9; // eax
  void *v10; // eax
  int v11; // eax
  const char *BuildingName; // eax
  const char *v14; // [esp+0h] [ebp-60h]
  const char *RaceName; // [esp+4h] [ebp-5Ch]
  _BYTE v16[24]; // [esp+Ch] [ebp-54h] BYREF
  int v17; // [esp+24h] [ebp-3Ch]
  int v18; // [esp+28h] [ebp-38h]
  float v19; // [esp+2Ch] [ebp-34h]
  float v20; // [esp+30h] [ebp-30h]
  int v21; // [esp+34h] [ebp-2Ch]
  int v22; // [esp+38h] [ebp-28h]
  int v23; // [esp+3Ch] [ebp-24h]
  _BYTE *v24; // [esp+40h] [ebp-20h]
  int v25; // [esp+44h] [ebp-1Ch]
  CMFCToolBarButton *v26; // [esp+48h] [ebp-18h]
  CSettler *v27; // [esp+4Ch] [ebp-14h]
  _DWORD *v28; // [esp+50h] [ebp-10h]
  int v29; // [esp+5Ch] [ebp-4h]

  v28 = this;
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\ProductionBuilding.cpp", 254, "_iSettlerId > 0") == 1 )
    __debugbreak();
  v27 = (CSettler *)CSettlerMgr::operator[](a3);
  if ( IEntity::FlagBits(v27, Visible) == 256
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\ProductionBuilding.cpp",
         258,
         "rSettler.FlagBits(ENTITY_FLAG_VISIBLE)!=ENTITY_FLAG_VISIBLE") == 1 )
  {
    __debugbreak();
  }
  if ( *((_BYTE *)v28 + 29) )
  {
    if ( *((unsigned __int16 *)v28 + 4) != a3
      && BBSupportDbgReport(2, "MapObjects\\Building\\ProductionBuilding.cpp", 275, "m_uSettlerId == _iSettlerId") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    *((_BYTE *)v28 + 29) = 1;
    *((_WORD *)v28 + 4) = a3;
    if ( IEntity::FlagBits(a2, (EntityFlag)0x1000u) )
    {
      CEntityEvent::CEntityEvent((CEntityEvent *)v16, 8u, 0, *((unsigned __int16 *)v28 + 3), 0, 0);
      v29 = 0;
      v24 = v16;
      (*(void (__thiscall **)(unsigned __int8 *, _BYTE *))(*(_DWORD *)a2 + 124))(a2, v16);
      v29 = -1;
      CEntityEvent::~CEntityEvent(v16);
    }
  }
  IEntity::ClearFlagBits(v27, Visible);
  IEntity::SetFlagBits(v27, MagicInvisible);
  IMovingEntity::SetDisplacementCosts(10);
  v26 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((unsigned __int16 *)v28 + 3));
  v3 = CBuilding::DoorPackedXY(v26);
  v23 = Y16X16::UnpackXFast(v3);
  v4 = CBuilding::DoorPackedXY(v26);
  v22 = Y16X16::UnpackYFast(v4);
  v5 = IEntity::X(v26);
  v21 = v23 - v5;
  v6 = IEntity::Y(v26);
  v25 = v22 - v6;
  v19 = (float)((float)v21 + (float)((float)((float)(v22 - v6) * -1.0) / 2.0)) * 24.0;
  v7 = (float)((float)(v22 - v6) * 24.0) / 2.0;
  v20 = v7;
  CSettler::SetOffset(v27, v19, v7);
  v8 = CBuilding::EnsignWorldIdx(a2);
  v18 = CWorldManager::EcoSectorId(v8);
  v17 = CEcoSectorMgr::operator[](v18);
  if ( *(_BYTE *)(v28[94] + 480) )
  {
    *((_BYTE *)v28 + 5) = 0;
    IAnimatedEntity::RegisterForLogicUpdate(14);
    *((_BYTE *)v28 + 4) = 2;
  }
  else
  {
    IAnimatedEntity::RegisterForLogicUpdate(31);
    v9 = IEntity::Race(a2);
    RaceName = CS4DefineNames::GetRaceName(v9);
    v10 = (void *)typeid(v28);
    v14 = (const char *)type_info::name(v10);
    v11 = CBuilding::BuildingTypeEx(a2);
    BuildingName = CS4DefineNames::GetBuildingName(v11);
    BBSupportTracePrintF(
      2,
      "WARNING: Building %s (role %s) of race %s has no production delay!",
      BuildingName,
      v14,
      RaceName);
  }
  (*(void (__cdecl **)(unsigned __int8 *))(*v28 + 72))(a2);
  return 1;
}


// address=[0x1516de0]
// Decompiled from int __thiscall CProductionBuildingRole::GetBuildingNeed(CProductionBuildingRole *this, int a2)
int  CProductionBuildingRole::GetBuildingNeed(int)const {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 400); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    v3 = CPileMgr::operator[](*v2);
    if ( (*(int (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)v3 + 60))(v3, v3) == a2 )
      return *(unsigned __int16 *)std::vector<unsigned short>::operator[](i);
  }
  BBSupportTracePrintF(0, "TROUBLE: illegal goodcheck good %u", a2);
  return 0;
}


// address=[0x1516e80]
// Decompiled from int __thiscall CProductionBuildingRole::GetPileIdWithGood(CProductionBuildingRole *this, int a2)
int  CProductionBuildingRole::GetPileIdWithGood(int)const {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int16 *v6; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-14h]
  unsigned __int8 *v9; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 400); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    v9 = CPileMgr::operator[](*v2);
    if ( (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v9 + 60))(v9) == a2 )
      return *(unsigned __int16 *)std::vector<unsigned short>::operator[](i);
  }
  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 384); ++i )
  {
    v4 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    v5 = CPileMgr::operator[](*v4);
    if ( (*(int (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)v5 + 60))(v5, v5) == a2 )
      return *(unsigned __int16 *)std::vector<unsigned short>::operator[](i);
  }
  v8 = *((unsigned __int16 *)this + 3);
  v6 = (unsigned __int16 *)CBuildingMgr::operator[](v8);
  v7 = IEntity::Type(v6);
  BBSupportTracePrintF(
    0,
    "Wrong good check: look for %s at %s nr %u",
    (&off_378B694)[2 * a2],
    (&off_378BA3C)[2 * v7],
    v8);
  return 0;
}


// address=[0x1516fc0]
// Decompiled from void __thiscall CProductionBuildingRole::GoodArrive(CProductionBuildingRole *this, int a2)
void  CProductionBuildingRole::GoodArrive(int) {
  
  ;
}


// address=[0x1516fd0]
// Decompiled from _DWORD *__thiscall CProductionBuildingRole::FillToolSideBar(  CProductionBuildingRole *this,  struct CAddToolSideBarInfo *a2,  bool a3)
void  CProductionBuildingRole::FillToolSideBar(class CAddToolSideBarInfo *,bool) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp+4h] [ebp-40h]
  unsigned int v7; // [esp+8h] [ebp-3Ch]
  CEcoSector *v9; // [esp+14h] [ebp-30h]
  unsigned int i; // [esp+18h] [ebp-2Ch]
  CEvn_Event v11; // [esp+1Ch] [ebp-28h] BYREF
  int v12; // [esp+40h] [ebp-4h]

  v3 = CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v4 = CBuilding::EnsignWorldIdx(v3);
  v6 = CWorldManager::EcoSectorId(v4);
  v9 = (CEcoSector *)CEcoSectorMgr::operator[](v6);
  *((_DWORD *)a2 + 1) = 12;
  for ( i = 0; i < std::vector<unsigned char>::size((char *)this + 416); ++i )
  {
    switch ( *(_BYTE *)std::vector<unsigned char>::operator[](i) )
    {
      case 4:
        *((_BYTE *)a2 + 8) = CEcoSector::GetNrOfToolOrder(v9, i);
        break;
      case 0x12:
        *((_BYTE *)a2 + 9) = CEcoSector::GetNrOfToolOrder(v9, i);
        break;
      case 0x19:
        *((_BYTE *)a2 + 10) = CEcoSector::GetNrOfToolOrder(v9, i);
        break;
      case 0x1B:
        *((_BYTE *)a2 + 11) = CEcoSector::GetNrOfToolOrder(v9, i);
        break;
      case 0x1C:
        *((_BYTE *)a2 + 14) = CEcoSector::GetNrOfToolOrder(v9, i);
        break;
      case 0x1D:
        *((_BYTE *)a2 + 12) = CEcoSector::GetNrOfToolOrder(v9, i);
        break;
      case 0x1F:
        *((_BYTE *)a2 + 13) = CEcoSector::GetNrOfToolOrder(v9, i);
        break;
      default:
        continue;
    }
  }
  v7 = 606;
  if ( !a3 )
    v7 = 607;
  CEvn_Event::CEvn_Event(&v11, v7, 0, (unsigned int)a2, 0);
  v12 = 0;
  if ( !g_pEvnEngine
    && BBSupportDbgReport(2, "MapObjects\\Building\\ProductionBuilding.cpp", 818, "g_pEvnEngine != NULL") == 1 )
  {
    __debugbreak();
  }
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v11);
  v12 = -1;
  return CEvn_Event::~CEvn_Event(&v11);
}


// address=[0x1517210]
// Decompiled from int __thiscall CProductionBuildingRole::FillWeaponSideBar(unsigned __int16 *this, int a2, char a3)
void  CProductionBuildingRole::FillWeaponSideBar(class CWeaponSideBarInfo *,bool) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp+4h] [ebp-40h]
  int v7; // [esp+8h] [ebp-3Ch]
  int v8; // [esp+10h] [ebp-34h]
  unsigned int i; // [esp+18h] [ebp-2Ch]
  _BYTE v11[24]; // [esp+1Ch] [ebp-28h] BYREF
  int v12; // [esp+40h] [ebp-4h]

  v3 = CBuildingMgr::operator[](this[3]);
  v4 = CBuilding::EnsignWorldIdx(v3);
  v6 = CWorldManager::EcoSectorId(v4);
  v8 = CEcoSectorMgr::operator[](v6);
  for ( i = 0; i < std::vector<unsigned char>::size(this + 208); ++i )
  {
    *(_BYTE *)(a2 + 12 * i + 12) = *(_BYTE *)std::vector<unsigned char>::operator[](i);
    *(_DWORD *)(a2 + 12 * i + 16) = CEcoSector::GetNrOfWeaponOrder(i);
    *(_BYTE *)(a2 + 12 * i + 20) = CEcoSector::WeaponPercentage(i);
  }
  *(_DWORD *)(a2 + 4) = 11;
  *(_BYTE *)(a2 + 8) = CEcoSector::WeaponAutoProduction(v8) == 100;
  v7 = 606;
  if ( !a3 )
    v7 = 607;
  CEvn_Event::CEvn_Event(v7, 0, a2, 0);
  v12 = 0;
  if ( !g_pEvnEngine
    && BBSupportDbgReport(2, (int)"MapObjects\\Building\\ProductionBuilding.cpp", 860, (int)"g_pEvnEngine != NULL") == 1 )
  {
    __debugbreak();
  }
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage((int)v11);
  v12 = -1;
  return CEvn_Event::~CEvn_Event(v11);
}


// address=[0x15173c0]
// Decompiled from char *__thiscall CProductionBuildingRole::CProductionBuildingRole(char *this, int a2)
 CProductionBuildingRole::CProductionBuildingRole(std::istream &) {
  
  int v3; // [esp+8h] [ebp-28h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-24h] BYREF
  unsigned int v5; // [esp+10h] [ebp-20h] BYREF
  char *v6; // [esp+14h] [ebp-1Ch]
  unsigned int i; // [esp+18h] [ebp-18h]
  _BYTE v8[7]; // [esp+1Ch] [ebp-14h] BYREF
  char v9; // [esp+23h] [ebp-Dh] BYREF
  int v10; // [esp+2Ch] [ebp-4h]

  v6 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v10 = 0;
  *(_DWORD *)v6 = &CProductionBuildingRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>(v6 + 384);
  std::vector<unsigned short>::vector<unsigned short>(v6 + 400);
  std::vector<unsigned char>::vector<unsigned char>();
  LOBYTE(v10) = 3;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 2 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CProductionBuildingRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v6 + 380);
  operator^<unsigned char>(a2, v6 + 381);
  operator^<unsigned int>(a2, &v5);
  for ( i = 0; i < v5; ++i )
  {
    operator^<unsigned short>(a2, v8);
    std::vector<unsigned short>::push_back(v8);
  }
  operator^<unsigned int>(a2, &v5);
  for ( i = 0; i < v5; ++i )
  {
    operator^<unsigned short>(a2, v8);
    std::vector<unsigned short>::push_back(v8);
  }
  operator^<unsigned int>(a2, &v5);
  for ( i = 0; i < v5; ++i )
  {
    operator^<unsigned char>(a2, &v9);
    std::vector<unsigned char>::push_back(&v9);
  }
  v10 = -1;
  return v6;
}


// address=[0x15175c0]
// Decompiled from int __thiscall CProductionBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CProductionBuildingRole::Store(std::ostream &) {
  
  __int16 *v2; // eax
  __int16 *v3; // eax
  int result; // eax
  int v5; // eax
  int v6; // [esp+0h] [ebp-10h] BYREF
  int v7; // [esp+4h] [ebp-Ch] BYREF
  struct IBuildingRole *v8; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  v8 = this;
  IBuildingRole::Store(this, a2);
  v6 = 2;
  operator^<unsigned int>(a2, &v6);
  operator^<unsigned char>(a2, (int)v8 + 380);
  operator^<unsigned char>(a2, (int)v8 + 381);
  v7 = std::vector<unsigned short>::size((char *)v8 + 384);
  operator^<unsigned int>(a2, &v7);
  for ( i = 0; i < v7; ++i )
  {
    v2 = (__int16 *)std::vector<unsigned short>::operator[]((char *)v8 + 384, i);
    operator^<unsigned short>((int)a2, v2);
  }
  v7 = std::vector<unsigned short>::size((char *)v8 + 400);
  operator^<unsigned int>(a2, &v7);
  for ( i = 0; i < v7; ++i )
  {
    v3 = (__int16 *)std::vector<unsigned short>::operator[]((char *)v8 + 400, i);
    operator^<unsigned short>((int)a2, v3);
  }
  v7 = std::vector<unsigned char>::size((char *)v8 + 416);
  result = operator^<unsigned int>(a2, &v7);
  for ( i = 0; i < v7; ++i )
  {
    v5 = std::vector<unsigned char>::operator[](i);
    operator^<unsigned char>(a2, v5);
    result = i + 1;
  }
  return result;
}


// address=[0x3d8b588]
// [Decompilation failed for static unsigned long CProductionBuildingRole::m_iClassID]

// address=[0x14fd230]
// Decompiled from void __thiscall CProductionBuildingRole::ConvertEventIntoGoal(  CProductionBuildingRole *this,  struct CBuilding *a2,  struct CEntityEvent *a3)
void  CProductionBuildingRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
  ;
}


// address=[0x14fd2a0]
// Decompiled from char __thiscall CProductionBuildingRole::CrushBuilding(CProductionBuildingRole *this)
bool  CProductionBuildingRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x14fde60]
// Decompiled from char __thiscall CProductionBuildingRole::TryCrushBuilding(CProductionBuildingRole *this)
bool  CProductionBuildingRole::TryCrushBuilding(void) {
  
  return 1;
}


// address=[0x1517740]
// Decompiled from char __thiscall CProductionBuildingRole::HaveMaterial(CProductionBuildingRole *this, struct CBuilding *a2)
bool  CProductionBuildingRole::HaveMaterial(class CBuilding *) {
  
  int v3; // [esp+0h] [ebp-10h]
  unsigned __int8 *v4; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+Ch] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 400); ++i )
  {
    v3 = *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 400, i);
    v4 = CPileMgr::operator[](v3);
    if ( !(*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v4 + 40))(v4) )
      return 0;
  }
  return 1;
}


// address=[0x15177c0]
// Decompiled from bool __thiscall CProductionBuildingRole::HaveFreeSlotForProduct(CProductionBuildingRole *this, struct CBuilding *a2)
bool  CProductionBuildingRole::HaveFreeSlotForProduct(class CBuilding *) {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  int v6; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  v6 = 0;
  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 384); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 384, i);
    v3 = CPileMgr::operator[](*v2);
    v6 += (*(int (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)v3 + 40))(v3, v3);
  }
  return v6 < 8;
}


// address=[0x1517840]
// Decompiled from char __thiscall CProductionBuildingRole::HaveProductionOrder(CProductionBuildingRole *this)
bool  CProductionBuildingRole::HaveProductionOrder(void) {
  
  int v1; // eax
  int v2; // eax
  unsigned __int16 *v3; // eax
  unsigned __int16 *v5; // eax
  int v6; // [esp+4h] [ebp-30h]
  unsigned int ArmorsCounter; // [esp+8h] [ebp-2Ch]
  unsigned int BowsCounter; // [esp+Ch] [ebp-28h]
  unsigned int SwordsCounter; // [esp+10h] [ebp-24h]
  int v10; // [esp+14h] [ebp-20h]
  int v11; // [esp+18h] [ebp-1Ch]
  int j; // [esp+1Ch] [ebp-18h]
  int i; // [esp+20h] [ebp-14h]
  int v14; // [esp+24h] [ebp-10h]
  int v15; // [esp+28h] [ebp-Ch]
  CMFCTasksPane *v17; // [esp+30h] [ebp-4h]

  v1 = CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v2 = CBuilding::EnsignWorldIdx(v1);
  v6 = CWorldManager::EcoSectorId(v2);
  v17 = (CMFCTasksPane *)CEcoSectorMgr::operator[](v6);
  v11 = std::vector<unsigned char>::size((char *)this + 416);
  v3 = (unsigned __int16 *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  if ( IEntity::Type(v3) == 22 )
  {
    for ( i = 1; i < v11 + 1; ++i )
    {
      v15 = (i + *((unsigned __int8 *)this + 381)) % v11;
      if ( (int)CEcoSector::GetNrOfWeaponOrder(v17, v15) > 0 )
      {
        *((_BYTE *)this + 380) = *(_BYTE *)std::vector<unsigned char>::operator[](v15);
        if ( CEcoSector::GetNrOfWeaponOrder(v17, v15) != 100 )
          CEcoSector::DecNrOfWeaponOrder(v17, v15);
        *((_BYTE *)this + 381) = v15;
        return 1;
      }
    }
    if ( CEcoSector::WeaponAutoProduction(v17) != 100 )
      return 0;
    SwordsCounter = CEcoSector::GetSwordsCounter(v17);
    BowsCounter = CEcoSector::GetBowsCounter(v17);
    ArmorsCounter = CEcoSector::GetArmorsCounter(v17);
    v10 = CEcoSector::GetSpecialCounter(v17) + ArmorsCounter + BowsCounter + SwordsCounter;
    if ( CEcoSector::WeaponPercentage(v17, 0) <= 0 || SwordsCounter > v10 * CEcoSector::WeaponPercentage(v17, 0) / 0x64u )
    {
      if ( CEcoSector::WeaponPercentage(v17, 1) <= 0 || BowsCounter > v10 * CEcoSector::WeaponPercentage(v17, 1) / 0x64u )
      {
        if ( CEcoSector::WeaponPercentage(v17, 2) <= 0
          || ArmorsCounter > v10 * CEcoSector::WeaponPercentage(v17, 2) / 0x64u )
        {
          if ( std::vector<unsigned char>::size((char *)this + 416) != 4 || CEcoSector::WeaponPercentage(v17, 3) <= 0 )
            return 1;
          *((_BYTE *)this + 380) = *(_BYTE *)std::vector<unsigned char>::operator[](3);
          CEcoSector::IncSpecialCounter(v17);
          return 1;
        }
        else
        {
          *((_BYTE *)this + 380) = *(_BYTE *)std::vector<unsigned char>::operator[](2);
          CEcoSector::IncArmorsCounter(v17);
          return 1;
        }
      }
      else
      {
        *((_BYTE *)this + 380) = *(_BYTE *)std::vector<unsigned char>::operator[](1);
        CEcoSector::IncBowsCounter(v17);
        return 1;
      }
    }
    else
    {
      *((_BYTE *)this + 380) = *(_BYTE *)std::vector<unsigned char>::operator[](0);
      CEcoSector::IncSwordsCounter(v17);
      return 1;
    }
  }
  else
  {
    v5 = (unsigned __int16 *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
    if ( IEntity::Type(v5) == 21 )
    {
      for ( j = 1; j < v11 + 1; ++j )
      {
        v14 = (j + *((unsigned __int8 *)this + 381)) % v11;
        if ( (int)CEcoSector::GetNrOfToolOrder(v17, v14) > 0 )
        {
          *((_BYTE *)this + 380) = *(_BYTE *)std::vector<unsigned char>::operator[](v14);
          if ( CEcoSector::GetNrOfToolOrder(v17, v14) != 100 )
            CEcoSector::DecNrOfToolOrder(v17, v14);
          *((_BYTE *)this + 381) = v14;
          return 1;
        }
      }
    }
    return 0;
  }
}


// address=[0x1517bb0]
// Decompiled from _DWORD *__thiscall CProductionBuildingRole::FillDialog(CProductionBuildingRole *this, struct CBuilding *a2, bool a3)
void  CProductionBuildingRole::FillDialog(class CBuilding *,bool) {
  
  int v3; // eax
  int v4; // eax
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // eax
  unsigned __int16 *v7; // eax
  unsigned __int16 *v8; // eax
  int v10; // [esp-8h] [ebp-54h]
  int v11; // [esp-8h] [ebp-54h]
  unsigned int v12; // [esp+4h] [ebp-48h]
  unsigned __int8 *v13; // [esp+8h] [ebp-44h]
  unsigned __int8 *v14; // [esp+Ch] [ebp-40h]
  unsigned __int8 *v15; // [esp+10h] [ebp-3Ch]
  unsigned __int8 *v16; // [esp+14h] [ebp-38h]
  unsigned int i; // [esp+20h] [ebp-2Ch]
  unsigned int j; // [esp+20h] [ebp-2Ch]
  CEvn_Event v20; // [esp+24h] [ebp-28h] BYREF
  int v21; // [esp+48h] [ebp-4h]

  CInfoExchange::Clear(&g_cResourceUpgradeInfo);
  dword_3F1E500 = 3;
  byte_3F1E505 = IEntity::Race(a2);
  byte_3F1E504 = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E507 = 1;
  byte_3F1E508 = IEntity::FlagBits(a2, (EntityFlag)0x1000u) != 0;
  byte_3F1E509 = 0;
  v10 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E50B = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v10, 0);
  v11 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E50C = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v11, 1u);
  byte_3F1E506 = *((_BYTE *)this + 29);
  if ( *((_BYTE *)this + 29) )
    byte_3F1E50D = *(_BYTE *)(*((_DWORD *)this + 94) + 478);
  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 400); ++i )
  {
    v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 400, i);
    v16 = CPileMgr::operator[](*v5);
    byte_3F1E511[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v16 + 40))(v16);
    v6 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 400, i);
    v15 = CPileMgr::operator[](*v6);
    byte_3F1E510[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v15 + 60))(v15);
  }
  for ( j = 0; j < std::vector<unsigned short>::size((char *)this + 384); ++j )
  {
    v7 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 384, j);
    v14 = CPileMgr::operator[](*v7);
    byte_3F1E51B[2 * j] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v14 + 40))(v14);
    v8 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 384, j);
    v13 = CPileMgr::operator[](*v8);
    byte_3F1E51A[2 * j] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v13 + 60))(v13);
  }
  v12 = 604;
  if ( !a3 )
    v12 = 602;
  CEvn_Event::CEvn_Event(&v20, v12, 0, (unsigned int)&g_cResourceUpgradeInfo, 0);
  v21 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v20);
  v21 = -1;
  return CEvn_Event::~CEvn_Event(&v20);
}


// address=[0x1577240]
// Decompiled from int __thiscall CProductionBuildingRole::GetProductType(CProductionBuildingRole *this)
int  CProductionBuildingRole::GetProductType(void)const {
  
  return *((unsigned __int8 *)this + 380);
}


