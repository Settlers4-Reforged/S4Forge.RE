#include "CWorkshopBuildingRole.h"

// Definitions for class CWorkshopBuildingRole

// address=[0x1402a20]
// Decompiled from int __cdecl CWorkshopBuildingRole::New(int a1)
static class CPersistence * __cdecl CWorkshopBuildingRole::New(std::istream &) {
  
  if ( operator new(0x19Cu) )
    return CWorkshopBuildingRole::CWorkshopBuildingRole(a1);
  else
    return 0;
}


// address=[0x14fdd30]
// Decompiled from int __cdecl CWorkshopBuildingRole::Load(int a1)
static class CWorkshopBuildingRole * __cdecl CWorkshopBuildingRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CWorkshopBuildingRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x152cc10]
// Decompiled from CWorkshopBuildingRole *__thiscall CWorkshopBuildingRole::CWorkshopBuildingRole(CWorkshopBuildingRole *this)
 CWorkshopBuildingRole::CWorkshopBuildingRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CWorkshopBuildingRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>((char *)this + 388);
  CWorkshopBuildingRole::Clear(this);
  return this;
}


// address=[0x152cc90]
// Decompiled from int __thiscall CWorkshopBuildingRole::LogicUpdate(CWorkshopBuildingRole *this, struct CBuilding *a2)
void  CWorkshopBuildingRole::LogicUpdate(class CBuilding *) {
  
  int result; // eax
  int v3; // eax
  __int16 v4; // ax
  CVehicle *v5; // eax
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // eax
  _DWORD *v8; // eax
  int v9; // [esp-Ch] [ebp-60h]
  int v10; // [esp-8h] [ebp-5Ch]
  int v11; // [esp-4h] [ebp-58h]
  _BYTE v12[24]; // [esp+4h] [ebp-50h] BYREF
  CEntityEvent *v13; // [esp+1Ch] [ebp-38h]
  CEntityEvent *v14; // [esp+20h] [ebp-34h]
  int v15; // [esp+24h] [ebp-30h]
  int v16; // [esp+28h] [ebp-2Ch] BYREF
  int v17; // [esp+2Ch] [ebp-28h] BYREF
  int DirectionForNewVehicle; // [esp+30h] [ebp-24h]
  int v19; // [esp+34h] [ebp-20h]
  int v20; // [esp+38h] [ebp-1Ch]
  char v21; // [esp+3Ch] [ebp-18h]
  int i; // [esp+40h] [ebp-14h]
  CWorkshopBuildingRole *v23; // [esp+44h] [ebp-10h]
  int v24; // [esp+50h] [ebp-4h]

  v23 = this;
  result = IEntity::FlagBits(a2, Selected);
  if ( result )
    result = (*(int (__thiscall **)(CWorkshopBuildingRole *, struct CBuilding *, int))(*(_DWORD *)v23 + 88))(v23, a2, 1);
  v21 = *((_BYTE *)v23 + 4);
  switch ( v21 )
  {
    case 1:
      result = (*(int (__thiscall **)(CWorkshopBuildingRole *, struct CBuilding *))(*(_DWORD *)v23 + 120))(v23, a2);
      if ( (_BYTE)result )
        *((_BYTE *)v23 + 4) = 3;
      else
        return IAnimatedEntity::RegisterForLogicUpdate(31);
      break;
    case 2:
      if ( *((unsigned __int8 *)v23 + 5) > (int)*(unsigned __int8 *)(*((_DWORD *)v23 + 94) + 480) )
      {
        *((_BYTE *)v23 + 5) = 0;
        *((_BYTE *)v23 + 4) = 3;
        return IAnimatedEntity::RegisterForLogicUpdate(1);
      }
      else
      {
        ++*((_BYTE *)v23 + 5);
        return IAnimatedEntity::RegisterForLogicUpdate(14);
      }
    case 3:
      if ( !*((_BYTE *)v23 + 29) || !IEntity::FlagBits(a2, (EntityFlag)0x1000u) )
        return IAnimatedEntity::RegisterForLogicUpdate(31);
      if ( *((_WORD *)v23 + 191) )
      {
        for ( i = 0; i < *(char *)(*((_DWORD *)v23 + 94) + 57); ++i )
        {
          v20 = *(char *)(*((_DWORD *)v23 + 94) + 16 * i + 62);
          v5 = (CVehicle *)CVehicleMgr::operator[](*((unsigned __int16 *)v23 + 191));
          if ( CVehicle::NeedForBuildingMaterial(v5, v20) )
          {
            v15 = (*(int (__thiscall **)(CWorkshopBuildingRole *, int))(*(_DWORD *)v23 + 56))(v23, v20);
            v6 = CPileMgr::operator[](v15);
            if ( (unsigned __int8)CPile::GoodAvailable(v6) )
            {
              v19 = CSettlerMgr::operator[](*((unsigned __int16 *)v23 + 4));
              v11 = *((unsigned __int16 *)v23 + 191);
              v7 = (unsigned __int8 *)std::vector<unsigned char>::operator[](i);
              v14 = CEntityEvent::CEntityEvent((CEntityEvent *)v12, 4u, 0, 0, *v7, v11);
              v13 = v14;
              v24 = 0;
              (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v19 + 80))(v19, v14);
              v24 = -1;
              CEntityEvent::~CEntityEvent(v12);
              return (*(int (__thiscall **)(CWorkshopBuildingRole *, struct CBuilding *, int))(*(_DWORD *)v23 + 72))(
                       v23,
                       a2,
                       1);
            }
          }
        }
        v8 = (_DWORD *)CVehicleMgr::operator[](*((unsigned __int16 *)v23 + 191));
        if ( !IEntity::FlagBits(v8, (EntityFlag)&dword_F29144[220079]) )
          *((_WORD *)v23 + 191) = 0;
      }
      else if ( CWorkshopBuildingRole::HaveProductionOrder(v23)
             && CWorkshopBuildingRole::IsSpaceForVehicleAvailable(v23, a2, *((unsigned __int8 *)v23 + 380)) )
      {
        CWorkshopBuildingRole::GetPositionForNewVehicle(v23, a2, &v16, &v17);
        DirectionForNewVehicle = CWorkshopBuildingRole::GetDirectionForNewVehicle(v23, a2);
        v10 = DirectionForNewVehicle;
        v9 = *((unsigned __int8 *)v23 + 380);
        v3 = IEntity::OwnerId((unsigned __int8 *)a2);
        v4 = CVehicleMgr::AddVehicle((CVehicleMgr *)&g_cVehicleMgr, v16, v17, v3, v9, v10, 1);
        *((_WORD *)v23 + 191) = v4;
        if ( *((_WORD *)v23 + 191) )
          CWorkshopBuildingRole::TakeOrder(v23, *((unsigned __int8 *)v23 + 380), -1);
      }
      return IAnimatedEntity::RegisterForLogicUpdate(31);
  }
  return result;
}


// address=[0x152cff0]
// Decompiled from unsigned int __thiscall CWorkshopBuildingRole::FillGfxInfo(  CWorkshopBuildingRole *this,  struct CBuilding *a2,  struct SGfxObjectInfo *a3)
void  CWorkshopBuildingRole::FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  unsigned int result; // eax
  unsigned __int16 *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int16 *v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // [esp-Ch] [ebp-2F0h]
  CSettler *v12; // [esp+0h] [ebp-2E4h]
  int v13; // [esp+4h] [ebp-2E0h]
  unsigned int i; // [esp+8h] [ebp-2DCh]
  _DWORD v16[180]; // [esp+10h] [ebp-2D4h] BYREF

  (*(void (__thiscall **)(CWorkshopBuildingRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v11 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo((int)a3, v3, v11, 1, (int)this + 76);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  *((_BYTE *)a3 + 715) = CPlayerManager::Color(v4);
  if ( *((_BYTE *)this + 356) )
  {
    CGfxManager::GetEffectGfxInfo(
      (CGfxManager *)g_pGfxManager,
      (struct SGfxObjectInfo *)v16,
      *((unsigned __int8 *)this + 356),
      0,
      *((unsigned __int8 *)this + 359));
    *((_DWORD *)a3 + 26) = v16[0];
    *((_DWORD *)a3 + 27) = v16[1];
    *((_DWORD *)a3 + 28) = *((__int16 *)this + 180);
    *((_DWORD *)a3 + 29) = *((__int16 *)this + 181);
  }
  v5 = IEntity::OwnerId((unsigned __int8 *)a2);
  IBuildingRole::MiniFlag(this, a3, v5);
  if ( *((_BYTE *)this + 29) == 1 )
  {
    v12 = (CSettler *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 4));
    CSettler::GetPatchGfx(
      v12,
      (struct SGfxObjectInfo *)((char *)a3 + 16 * *(char *)(*((_DWORD *)this + 94) + 476) + 200));
  }
  v13 = 0;
  for ( i = 0; ; ++i )
  {
    result = std::vector<unsigned short>::size((char *)this + 388);
    if ( i >= result )
      break;
    v7 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 388, i);
    v8 = CPileMgr::operator[](*v7);
    if ( (unsigned __int8)CPile::IsPatchPile(v8) )
    {
      v9 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 388, i);
      v10 = CPileMgr::operator[](*v9);
      CPile::GetPatchGfx((CPile *)v10, (struct SGfxObjectInfo *)((char *)a3 + 16 * v13++ + 536));
    }
  }
  return result;
}


// address=[0x152d260]
// Decompiled from unsigned int __thiscall CWorkshopBuildingRole::Init(CWorkshopBuildingRole *this, struct CBuilding *a2)
void  CWorkshopBuildingRole::Init(class CBuilding *) {
  
  int v2; // eax
  int v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v11; // [esp-4h] [ebp-20h]
  int v12; // [esp-4h] [ebp-20h]
  int v13; // [esp+0h] [ebp-1Ch]
  int v14; // [esp+4h] [ebp-18h]
  int v15; // [esp+8h] [ebp-14h]
  int v16; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  __int16 v19; // [esp+1Ah] [ebp-2h] BYREF

  IBuildingRole::InitCommon((int)a2);
  CWorkshopBuildingRole::Clear(this);
  *((_BYTE *)this + 4) = 1;
  for ( i = 0; i < *(char *)(*((_DWORD *)this + 94) + 57); ++i )
  {
    v2 = IEntity::WorldIdx();
    v14 = *(char *)(*((_DWORD *)this + 94) + 16 * i + 60) + CWorldManager::X(v2);
    v3 = IEntity::WorldIdx();
    v15 = *(char *)(*((_DWORD *)this + 94) + 16 * i + 61) + CWorldManager::Y(v3);
    v16 = CPileMgr::AddPile(
            (CPileMgr *)&g_cPileMgr,
            v14,
            v15,
            *(char *)(*((_DWORD *)this + 94) + 16 * i + 62),
            0,
            *(char *)(*((_DWORD *)this + 94) + 16 * i + 63),
            *(char *)(*((_DWORD *)this + 94) + 16 * i + 64),
            *(char *)(*((_DWORD *)this + 94) + 16 * i + 65),
            *(_DWORD *)(*((_DWORD *)this + 94) + 16 * i + 68),
            *(_DWORD *)(*((_DWORD *)this + 94) + 16 * i + 72));
    v11 = *((unsigned __int16 *)this + 3);
    v4 = CPileMgr::operator[](v16);
    CPile::SetBuildingId((CPile *)v4, v11);
    if ( *(_BYTE *)(*((_DWORD *)this + 94) + 16 * i + 65) == 1 )
    {
      v5 = CPileMgr::operator[](v16);
      IEntity::ClearFlagBits(v5, Visible);
    }
    if ( *(_BYTE *)(*((_DWORD *)this + 94) + 16 * i + 63) != 1
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\WorkshopBuildingRole.cpp",
           302,
           "m_pBuildingInfo->piles[p].type == IPileRole::PILE_DELIVER") == 1 )
    {
      __debugbreak();
    }
    v19 = v16;
    std::vector<unsigned short>::push_back(&v19);
  }
  if ( !std::vector<unsigned short>::size((char *)this + 388) )
  {
    IEntity::ID();
    v6 = IEntity::Type((unsigned __int16 *)a2);
    if ( BBSupportDbgReportF(
           2,
           "MapObjects\\Building\\WorkshopBuildingRole.cpp",
           311,
           "No deliverPile for %s nr %u",
           (const char *)dword_3791D18[2 * v6],
           (&off_3791D1C)[2 * v6]) == 1 )
      __debugbreak();
  }
  IAnimatedEntity::RegisterForLogicUpdate(2);
  if ( IEntity::FlagBits(a2, Selected) )
    (*(void (__thiscall **)(CWorkshopBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 88))(this, a2, 0);
  v12 = *(char *)(*((_DWORD *)this + 94) + 43) + IEntity::Y(a2);
  v7 = IEntity::X(a2);
  v13 = Y16X16::PackXYFast(*(char *)(*((_DWORD *)this + 94) + 42) + v7, v12);
  CBuilding::SetWorkingAreaPackedXY(a2, v13);
  v8 = CBuilding::EnsignWorldIdx(a2);
  CWorldManager::SetMoveCostsBits(v8, 7);
  v9 = CBuilding::EnsignWorldIdx(a2);
  return CWorldManager::SetFlagBits(v9, 2u);
}


// address=[0x152d540]
// Decompiled from char __thiscall CWorkshopBuildingRole::PostLoadInit(CWorkshopBuildingRole *this, struct CBuilding *a2)
void  CWorkshopBuildingRole::PostLoadInit(class CBuilding *) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp-4h] [ebp-14h]
  int v8; // [esp+0h] [ebp-10h]
  int v9; // [esp+8h] [ebp-8h]

  v7 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
  v2 = IEntity::Race(a2);
  *((_DWORD *)this + 94) = CBuildingInfoMgr::GetBuildingInfo(v2, v7);
  v3 = *((_DWORD *)this + 94);
  if ( !*(_BYTE *)(v3 + 6) )
    return v3;
  v8 = *(char *)(*((_DWORD *)this + 94) + 42) + IEntity::X(a2);
  v4 = IEntity::Y(a2);
  v9 = CWorldManager::Index(v8, *(char *)(*((_DWORD *)this + 94) + 43) + v4);
  LOBYTE(v3) = CWaterFlags::IsWater(v9);
  if ( !(_BYTE)v3 )
    return v3;
  v5 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
  LOBYTE(v3) = CBuildingMgr::IsShipyardEx(v5);
  if ( (_BYTE)v3 )
    LOBYTE(v3) = CWaterFlags::SetWaterFlagBitRepelling(v9);
  return v3;
}


// address=[0x152d610]
// Decompiled from char __thiscall CWorkshopBuildingRole::SettlerEnter(CWorkshopBuildingRole *this, struct CBuilding *a2, int a3)
bool  CWorkshopBuildingRole::SettlerEnter(class CBuilding *,int) {
  
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
  int v14; // [esp+4h] [ebp-5Ch]
  const char *v15; // [esp+4h] [ebp-5Ch]
  const char *RaceName; // [esp+8h] [ebp-58h]
  _BYTE v17[24]; // [esp+10h] [ebp-50h] BYREF
  float v18; // [esp+28h] [ebp-38h]
  float v19; // [esp+2Ch] [ebp-34h]
  int v20; // [esp+30h] [ebp-30h]
  int v21; // [esp+34h] [ebp-2Ch]
  int v22; // [esp+38h] [ebp-28h]
  _BYTE *v23; // [esp+3Ch] [ebp-24h]
  struct CVehicle *VehiclePtr; // [esp+40h] [ebp-20h]
  int v25; // [esp+44h] [ebp-1Ch]
  CSettler *v26; // [esp+48h] [ebp-18h]
  CMFCToolBarButton *v27; // [esp+4Ch] [ebp-14h]
  _DWORD *v28; // [esp+50h] [ebp-10h]
  int v29; // [esp+5Ch] [ebp-4h]

  v28 = this;
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\WorkshopBuildingRole.cpp", 345, "_iSettlerId > 0") == 1 )
    __debugbreak();
  v26 = (CSettler *)CSettlerMgr::operator[](a3);
  if ( !*((_BYTE *)v28 + 29) )
  {
    *((_BYTE *)v28 + 29) = 1;
    *((_WORD *)v28 + 4) = a3;
    if ( IEntity::FlagBits(a2, (EntityFlag)0x1000u) )
    {
      CEntityEvent::CEntityEvent((CEntityEvent *)v17, 8u, 0, *((unsigned __int16 *)v28 + 3), 0, 0);
      v29 = 0;
      v23 = v17;
      (*(void (__thiscall **)(struct CBuilding *, _BYTE *))(*(_DWORD *)a2 + 124))(a2, v17);
      v29 = -1;
      CEntityEvent::~CEntityEvent(v17);
    }
  }
  IEntity::ClearFlagBits(v26, Visible);
  IEntity::SetFlagBits(v26, MagicInvisible);
  IMovingEntity::SetDisplacementCosts(10);
  v27 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((unsigned __int16 *)v28 + 3));
  v3 = CBuilding::DoorPackedXY(v27);
  v22 = Y16X16::UnpackXFast(v3);
  v4 = CBuilding::DoorPackedXY(v27);
  v21 = Y16X16::UnpackYFast(v4);
  v5 = IEntity::X(v27);
  v20 = v22 - v5;
  v6 = IEntity::Y(v27);
  v25 = v21 - v6;
  v18 = (float)((float)v20 + (float)((float)((float)(v21 - v6) * -1.0) / 2.0)) * 24.0;
  v7 = (float)((float)(v21 - v6) * 24.0) / 2.0;
  v19 = v7;
  CSettler::SetOffset(v26, v18, v7);
  if ( *((_WORD *)v28 + 191) )
  {
    if ( !CVehicleMgr::GetVehiclePtr(*((unsigned __int16 *)v28 + 191))
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\WorkshopBuildingRole.cpp",
           395,
           "dynamic_cast<CVehicle*>(g_cVehicleMgr.GetVehiclePtr( m_uProductId ))!=NULL") == 1 )
    {
      __debugbreak();
    }
    VehiclePtr = CVehicleMgr::GetVehiclePtr(*((unsigned __int16 *)v28 + 191));
    if ( VehiclePtr && !IEntity::FlagBits(VehiclePtr, (EntityFlag)&dword_F29144[220079]) )
    {
      *((_WORD *)v28 + 191) = 0;
      *((_BYTE *)v28 + 380) = 0;
    }
  }
  if ( !CWorkshopBuildingRole::HaveStillOrders((CWorkshopBuildingRole *)v28) )
  {
    v14 = IEntity::ID();
    v8 = IEntity::OwnerId((unsigned __int8 *)a2);
    (*(void (__thiscall **)(void *, int, int, int, _DWORD))(*(_DWORD *)off_3D7A3D8 + 44))(off_3D7A3D8, 7, v8, v14, 0);
  }
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
    v10 = (void *)j____RTtypeid(v28);
    v15 = (const char *)type_info::name(v10);
    v11 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
    BuildingName = CS4DefineNames::GetBuildingName(v11);
    BBSupportTracePrintF(
      2,
      "WARNING: Building %s (role %s) of race %s has no production delay!",
      BuildingName,
      v15,
      RaceName);
  }
  (*(void (__cdecl **)(struct CBuilding *))(*v28 + 72))(a2);
  return 1;
}


// address=[0x152d940]
// Decompiled from int __thiscall CWorkshopBuildingRole::GetBuildingNeed(CWorkshopBuildingRole *this, int a2)
int  CWorkshopBuildingRole::GetBuildingNeed(int)const {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 388); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    v3 = CPileMgr::operator[](*v2);
    if ( (*(int (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)v3 + 60))(v3, v3) == a2 )
      return *(unsigned __int16 *)std::vector<unsigned short>::operator[](i);
  }
  BBSupportTracePrintF(0, "TROUBLE: illegal goodcheck good %u", a2);
  return 0;
}


// address=[0x152d9e0]
// Decompiled from int __thiscall CWorkshopBuildingRole::GetPileIdWithGood(CWorkshopBuildingRole *this, int a2)
int  CWorkshopBuildingRole::GetPileIdWithGood(int)const {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 388); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    v3 = CPileMgr::operator[](*v2);
    if ( (*(int (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)v3 + 60))(v3, v3) == a2 )
      return *(unsigned __int16 *)std::vector<unsigned short>::operator[](i);
  }
  if ( BBSupportDbgReport(
         1,
         "MapObjects\\Building\\WorkshopBuildingRole.cpp",
         955,
         "CWorkshopBuildingRole::GetPileIdWithGood() failed!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x152da90]
// Decompiled from char __thiscall CWorkshopBuildingRole::HasShipAmmo(CWorkshopBuildingRole *this, int a2)
bool  CWorkshopBuildingRole::HasShipAmmo(int)const {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 388); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    v3 = CPileMgr::operator[](*v2);
    if ( (*(int (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)v3 + 60))(v3, v3) == a2 )
      return 1;
  }
  return 0;
}


// address=[0x152db10]
// Decompiled from int __thiscall CWorkshopBuildingRole::GetPileIdWithNeedForGood(CWorkshopBuildingRole *this, int a2)
int  CWorkshopBuildingRole::GetPileIdWithNeedForGood(int)const {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v5; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 388); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    v5 = CPileMgr::operator[](*v2);
    if ( (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v5 + 60))(v5) == a2 && CPile::HasSpace((CPile *)v5) )
      return *(unsigned __int16 *)std::vector<unsigned short>::operator[](i);
  }
  if ( BBSupportDbgReport(
         1,
         "MapObjects\\Building\\WorkshopBuildingRole.cpp",
         996,
         "CWorkshopBuildingRole::GetPileIdWithNeedForGood() failed!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x152dbd0]
// Decompiled from void __thiscall CWorkshopBuildingRole::GoodArrive(CWorkshopBuildingRole *this, int a2)
void  CWorkshopBuildingRole::GoodArrive(int) {
  
  ;
}


// address=[0x152dbe0]
// Decompiled from char __thiscall CWorkshopBuildingRole::HaveStillOrders(CWorkshopBuildingRole *this)
bool  CWorkshopBuildingRole::HaveStillOrders(void)const {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 5; ++i )
  {
    if ( *((_BYTE *)this + i + 404) )
      return 1;
  }
  return 0;
}


// address=[0x152dc20]
// Decompiled from char __thiscall CWorkshopBuildingRole::HaveSpecialOrder(_BYTE *this, int a2)
bool  CWorkshopBuildingRole::HaveSpecialOrder(int)const {
  
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 5; ++i )
  {
    if ( a2 == dword_3D8B800[i] && this[i + 404] )
      return 1;
  }
  return 0;
}


// address=[0x152dc70]
// Decompiled from unsigned int __thiscall CWorkshopBuildingRole::LockPiles(CWorkshopBuildingRole *this, struct CBuilding *a2, bool a3)
void  CWorkshopBuildingRole::LockPiles(class CBuilding *,bool) {
  
  unsigned int result; // eax
  unsigned __int16 *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; ; ++i )
  {
    result = std::vector<unsigned short>::size((char *)this + 388);
    if ( i >= result )
      break;
    v4 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 388, i);
    v5 = CPileMgr::operator[](*v4);
    if ( a3 )
      IEntity::SetFlagBits(v5, (EntityFlag)0x10u);
    else
      IEntity::ClearFlagBits(v5, (EntityFlag)0x10u);
  }
  return result;
}


// address=[0x152dd10]
// Decompiled from CWorkshopBuildingRole *__thiscall CWorkshopBuildingRole::TakeOrder(CWorkshopBuildingRole *this, int a2, int a3)
void  CWorkshopBuildingRole::TakeOrder(int,int) {
  
  CWorkshopBuildingRole *result; // eax
  CWorkshopBuildingRole *i; // [esp+4h] [ebp-8h]
  int v5; // [esp+8h] [ebp-4h]

  for ( i = 0; ; i = (CWorkshopBuildingRole *)((char *)i + 1) )
  {
    result = i;
    if ( !dword_3D8B7A8[2 * (_DWORD)i] || dword_3D8B7A8[2 * (_DWORD)i] == a2 )
      break;
  }
  if ( dword_3D8B7A8[2 * (_DWORD)i] == -1 )
    return result;
  if ( a3 )
  {
    if ( a3 == 100 )
    {
      LOBYTE(v5) = 100;
    }
    else if ( *((unsigned __int8 *)this + dword_3D8B7AC[2 * (_DWORD)i] + 404) >= 0x64u )
    {
      LOBYTE(v5) = 100;
    }
    else
    {
      v5 = a3 + *((unsigned __int8 *)this + dword_3D8B7AC[2 * (_DWORD)i] + 404);
      if ( v5 >= 0 )
      {
        if ( v5 >= 100 )
          LOBYTE(v5) = 99;
      }
      else
      {
        LOBYTE(v5) = 0;
      }
    }
  }
  else
  {
    LOBYTE(v5) = 0;
  }
  result = this;
  *((_BYTE *)this + dword_3D8B7AC[2 * (_DWORD)i] + 404) = v5;
  return result;
}


// address=[0x152dde0]
// Decompiled from _DWORD *__thiscall CWorkshopBuildingRole::FillAddVehicleSideBar(  CWorkshopBuildingRole *this,  struct CAddVehicleBarInfo *a2,  bool a3)
void  CWorkshopBuildingRole::FillAddVehicleSideBar(class CAddVehicleBarInfo *,bool) {
  
  unsigned __int16 *v3; // eax
  int LocalPlayerId; // eax
  unsigned int v5; // eax
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v9; // [esp+4h] [ebp-3Ch]
  int j; // [esp+Ch] [ebp-34h]
  unsigned int v12; // [esp+10h] [ebp-30h]
  int i; // [esp+14h] [ebp-2Ch]
  CEvn_Event v14; // [esp+18h] [ebp-28h] BYREF
  int v15; // [esp+3Ch] [ebp-4h]

  for ( i = 0; i < 3; ++i )
  {
    v3 = (unsigned __int16 *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
    if ( IEntity::Type(v3) == 23 )
      v12 = dword_3D8B7EC[i];
    else
      v12 = dword_3D8B7D8[i];
    for ( j = 0; dword_3D8B7A8[2 * j] && dword_3D8B7A8[2 * j] != v12; ++j )
      ;
    if ( dword_3D8B7A8[2 * j] != -1 )
    {
      *((_BYTE *)a2 + 4 * i + 8) = v12;
      *((_BYTE *)a2 + 4 * i + 9) = *((_BYTE *)this + j + 404);
      if ( v12 )
      {
        LocalPlayerId = CPlayerManager::GetLocalPlayerId();
        v5 = CPlayerManager::Race(LocalPlayerId);
        *((_BYTE *)a2 + 4 * i + 10) = *(_BYTE *)IVehicleInfoMgr::VehicleProperties(v5, v12);
        v6 = CPlayerManager::GetLocalPlayerId();
        v7 = CPlayerManager::Race(v6);
        *((_BYTE *)a2 + 4 * i + 11) = *((_BYTE *)IVehicleInfoMgr::VehicleProperties(v7, v12) + 4);
      }
    }
  }
  *((_DWORD *)a2 + 1) = 17;
  v9 = 606;
  if ( !a3 )
    v9 = 607;
  CEvn_Event::CEvn_Event(&v14, v9, 0, (unsigned int)a2, 0);
  v15 = 0;
  if ( !g_pEvnEngine
    && BBSupportDbgReport(2, "MapObjects\\Building\\WorkshopBuildingRole.cpp", 1171, "g_pEvnEngine != NULL") == 1 )
  {
    __debugbreak();
  }
  if ( g_pEvnEngine )
    IEventEngine::SendAMessage(g_pEvnEngine, &v14);
  v15 = -1;
  return CEvn_Event::~CEvn_Event(&v14);
}


// address=[0x152dfd0]
// Decompiled from char __thiscall CWorkshopBuildingRole::CancelCurrentProduction(CWorkshopBuildingRole *this)
bool  CWorkshopBuildingRole::CancelCurrentProduction(void) {
  
  void *v1; // eax
  _DWORD *v2; // eax
  int v3; // eax
  int v5; // [esp-10h] [ebp-18h]
  int v6; // [esp+0h] [ebp-8h]

  if ( !*((_WORD *)this + 191)
    && BBSupportDbgReport(2, "MapObjects\\Building\\WorkshopBuildingRole.cpp", 1078, "m_uProductId>0") == 1 )
  {
    __debugbreak();
  }
  if ( !CMapObjectMgr::ValidEntityId(*((unsigned __int16 *)this + 191))
    && BBSupportDbgReport(
         2,
         "MapObjects\\Building\\WorkshopBuildingRole.cpp",
         1079,
         "g_pMapObjectMgr->ValidEntityId( m_uProductId )") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_WORD *)this + 191) )
    return 0;
  v6 = CLogic::Effects((DWORD *)g_pLogic);
  v1 = (void *)CVehicleMgr::operator[](*((unsigned __int16 *)this + 191));
  v5 = IEntity::Y(v1);
  v2 = (_DWORD *)CVehicleMgr::operator[](*((unsigned __int16 *)this + 191));
  v3 = IEntity::X(v2);
  (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 16))(
    v6,
    62,
    3,
    v3,
    v5,
    0,
    0,
    0);
  CVehicleMgr::DeleteVehicle((CVehicleMgr *)&g_cVehicleMgr, *((unsigned __int16 *)this + 191));
  *((_WORD *)this + 191) = 0;
  CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  IAnimatedEntity::RegisterForLogicUpdate(1);
  return 0;
}


// address=[0x152e100]
// Decompiled from char *__thiscall CWorkshopBuildingRole::CWorkshopBuildingRole(char *this, int a2)
 CWorkshopBuildingRole::CWorkshopBuildingRole(std::istream &) {
  
  int v3; // [esp+8h] [ebp-24h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  unsigned int v5; // [esp+10h] [ebp-1Ch] BYREF
  unsigned int i; // [esp+14h] [ebp-18h]
  char *v7; // [esp+18h] [ebp-14h]
  _BYTE v8[4]; // [esp+1Ch] [ebp-10h] BYREF
  int v9; // [esp+28h] [ebp-4h]

  v7 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v9 = 0;
  *(_DWORD *)v7 = &CWorkshopBuildingRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>(v7 + 388);
  LOBYTE(v9) = 1;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CWorkshopBuildingRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v7 + 381);
  operator^<unsigned char>(a2, v7 + 380);
  operator^<unsigned short>(a2, v7 + 382);
  operator^<unsigned int>(a2, v7 + 384);
  operator^<unsigned int>(a2, &v5);
  for ( i = 0; i < v5; ++i )
  {
    operator^<unsigned short>(a2, v8);
    std::vector<unsigned short>::push_back(v8);
  }
  operator^<unsigned int>(a2, &v5);
  for ( i = 0; i < v5; ++i )
    operator^<unsigned char>(a2, &v7[i + 404]);
  v9 = -1;
  return v7;
}


// address=[0x152e2b0]
// Decompiled from int __thiscall CWorkshopBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CWorkshopBuildingRole::Store(std::ostream &) {
  
  __int16 *v2; // eax
  int result; // eax
  int v4; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+4h] [ebp-Ch] BYREF
  struct IBuildingRole *v6; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  v6 = this;
  IBuildingRole::Store(this, a2);
  v4 = 1;
  operator^<unsigned int>(a2, &v4);
  operator^<unsigned char>(a2, (int)v6 + 381);
  operator^<unsigned char>(a2, (int)v6 + 380);
  operator^<unsigned short>((int)a2, (__int16 *)v6 + 191);
  operator^<unsigned int>(a2, (int *)v6 + 96);
  v5 = std::vector<unsigned short>::size((char *)v6 + 388);
  operator^<unsigned int>(a2, &v5);
  for ( i = 0; i < v5; ++i )
  {
    v2 = (__int16 *)std::vector<unsigned short>::operator[]((char *)v6 + 388, i);
    operator^<unsigned short>((int)a2, v2);
  }
  v5 = 5;
  result = operator^<unsigned int>(a2, &v5);
  for ( i = 0; i < v5; ++i )
    result = operator^<unsigned char>(a2, (int)v6 + i + 404);
  return result;
}


// address=[0x152f150]
// Decompiled from int __thiscall CWorkshopBuildingRole::~CWorkshopBuildingRole(CWorkshopBuildingRole *this)
 CWorkshopBuildingRole::~CWorkshopBuildingRole(void) {
  
  std::vector<unsigned short>::~vector<unsigned short>((char *)this + 388);
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x152f1c0]
// Decompiled from int __thiscall CWorkshopBuildingRole::ClassID(CWorkshopBuildingRole *this)
unsigned long  CWorkshopBuildingRole::ClassID(void)const {
  
  return CWorkshopBuildingRole::m_iClassID;
}


// address=[0x152f1f0]
// Decompiled from int __thiscall CWorkshopBuildingRole::GetBuildingRole(CWorkshopBuildingRole *this)
int  CWorkshopBuildingRole::GetBuildingRole(void) {
  
  return 5;
}


// address=[0x3d8b814]
// [Decompilation failed for static unsigned long CWorkshopBuildingRole::m_iClassID]

// address=[0x152e3f0]
// Decompiled from char __thiscall CWorkshopBuildingRole::CrushBuilding(CWorkshopBuildingRole *this)
bool  CWorkshopBuildingRole::CrushBuilding(void) {
  
  void *v1; // eax
  _DWORD *v2; // eax
  int v3; // eax
  int v5; // [esp-10h] [ebp-18h]
  int v6; // [esp+0h] [ebp-8h]

  if ( !*((_WORD *)this + 191) )
    return 1;
  v6 = CLogic::Effects((DWORD *)g_pLogic);
  v1 = (void *)CVehicleMgr::operator[](*((unsigned __int16 *)this + 191));
  v5 = IEntity::Y(v1);
  v2 = (_DWORD *)CVehicleMgr::operator[](*((unsigned __int16 *)this + 191));
  v3 = IEntity::X(v2);
  (*(void (__thiscall **)(int, int, int, int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v6 + 16))(
    v6,
    62,
    3,
    v3,
    v5,
    0,
    0,
    0);
  CVehicleMgr::DeleteVehicle((CVehicleMgr *)&g_cVehicleMgr, *((unsigned __int16 *)this + 191));
  *((_WORD *)this + 191) = 0;
  return 1;
}


// address=[0x152e4a0]
// Decompiled from char __thiscall CWorkshopBuildingRole::HaveMaterial(int this, int a2)
bool  CWorkshopBuildingRole::HaveMaterial(class CBuilding *) {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < std::vector<unsigned short>::size(this + 388); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((void *)(this + 388), i);
    v3 = CPileMgr::operator[](*v2);
    if ( !(unsigned __int8)CPile::GoodAvailable(v3) )
      return 0;
  }
  return 1;
}


// address=[0x152e510]
// Decompiled from char __thiscall CWorkshopBuildingRole::HaveProductionOrder(CWorkshopBuildingRole *this)
bool  CWorkshopBuildingRole::HaveProductionOrder(void) {
  
  unsigned int i; // [esp+4h] [ebp-Ch]
  unsigned int v3; // [esp+Ch] [ebp-4h]

  v3 = *((unsigned __int8 *)this + 381) % 5u;
  for ( i = 0; i < 5; ++i )
  {
    if ( *((_BYTE *)this + v3 + 404) )
    {
      *((_BYTE *)this + 380) = dword_3D8B800[v3];
      *((_BYTE *)this + 381) = (v3 + 1) % 5;
      return 1;
    }
    if ( ++v3 >= 5 )
      v3 = 0;
  }
  *((_BYTE *)this + 380) = 0;
  return 0;
}


// address=[0x152e5c0]
// Decompiled from int __thiscall CWorkshopBuildingRole::GetPositionForNewVehicle(  CWorkshopBuildingRole *this,  struct CBuilding *a2,  int *a3,  int *a4)
void  CWorkshopBuildingRole::GetPositionForNewVehicle(class CBuilding *,int &,int &) {
  
  int result; // eax

  *a3 = *(char *)(*((_DWORD *)this + 94) + 42) + IEntity::X(a2);
  result = *(char *)(*((_DWORD *)this + 94) + 43) + IEntity::Y(a2);
  *a4 = result;
  return result;
}


// address=[0x152e610]
// Decompiled from int __thiscall CWorkshopBuildingRole::GetDirectionForNewVehicle(CWorkshopBuildingRole *this, struct CBuilding *a2)
int  CWorkshopBuildingRole::GetDirectionForNewVehicle(class CBuilding *) {
  
  int result; // eax

  switch ( CBuilding::BuildingTypeEx((unsigned __int8 *)a2) )
  {
    case ':':
      result = 4;
      break;
    case ';':
      result = -1;
      break;
    case '<':
      result = 5;
      break;
    case '=':
      result = 1;
      break;
    case '>':
      result = -1;
      break;
    case '?':
      result = 2;
      break;
    case 'L':
      result = 0;
      break;
    case 'M':
      result = 3;
      break;
    default:
      result = 2;
      break;
  }
  return result;
}


// address=[0x152e6c0]
// Decompiled from bool __thiscall CWorkshopBuildingRole::IsSpaceForVehicleAvailable(  CWorkshopBuildingRole *this,  struct CBuilding *a2,  int a3)
bool  CWorkshopBuildingRole::IsSpaceForVehicleAvailable(class CBuilding *,int) {
  
  int v4; // [esp+0h] [ebp-Ch] BYREF
  int v5; // [esp+4h] [ebp-8h] BYREF
  CWorkshopBuildingRole *v6; // [esp+8h] [ebp-4h]

  v6 = this;
  if ( a3 <= 0 || a3 >= 6 )
    return 0;
  CWorkshopBuildingRole::GetPositionForNewVehicle(v6, a2, &v4, &v5);
  return CVehicleMgr::IsPositionFreeForVehicle((CVehicleMgr *)&g_cVehicleMgr, v4, v5, a3);
}


// address=[0x152e710]
// Decompiled from _DWORD *__thiscall CWorkshopBuildingRole::FillDialog(CWorkshopBuildingRole *this, struct CBuilding *a2, bool a3)
void  CWorkshopBuildingRole::FillDialog(class CBuilding *,bool) {
  
  int v3; // eax
  int v4; // eax
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // eax
  CVehicle *v7; // eax
  int v9; // [esp-8h] [ebp-4Ch]
  int v10; // [esp-8h] [ebp-4Ch]
  unsigned int v11; // [esp+4h] [ebp-40h]
  unsigned __int8 *v12; // [esp+8h] [ebp-3Ch]
  unsigned __int8 *v13; // [esp+Ch] [ebp-38h]
  unsigned int i; // [esp+14h] [ebp-30h]
  CEvn_Event v16; // [esp+1Ch] [ebp-28h] BYREF
  int v17; // [esp+40h] [ebp-4h]

  CInfoExchange::Clear(&g_cVehicleProductionInfo);
  dword_3F1E608 = 9;
  byte_3F1E60D = IEntity::Race(a2);
  byte_3F1E60C = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E60F = 1;
  byte_3F1E610 = IEntity::FlagBits(a2, (EntityFlag)0x1000u) != 0;
  byte_3F1E611 = 0;
  v9 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E613 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v9, 0);
  v10 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E614 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v10, 1u);
  byte_3F1E60E = *((_BYTE *)this + 29);
  if ( *((_BYTE *)this + 29) )
    byte_3F1E615 = *(_BYTE *)(*((_DWORD *)this + 94) + 478);
  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 388); ++i )
  {
    v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 388, i);
    v13 = CPileMgr::operator[](*v5);
    byte_3F1E619[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v13 + 40))(v13);
    v6 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 388, i);
    v12 = CPileMgr::operator[](*v6);
    byte_3F1E618[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v12 + 60))(v12);
  }
  if ( *((_WORD *)this + 191) && CMapObjectMgr::ValidEntityId(*((unsigned __int16 *)this + 191)) )
  {
    v7 = (CVehicle *)CVehicleMgr::operator[](*((unsigned __int16 *)this + 191));
    dword_3F1E624 = CVehicle::BuildingProgress(v7);
    dword_3F1E628 = *((unsigned __int8 *)this + 380);
  }
  v11 = 604;
  if ( !a3 )
    v11 = 602;
  CEvn_Event::CEvn_Event(&v16, v11, 0, (unsigned int)&g_cVehicleProductionInfo, 0);
  v17 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v16);
  v17 = -1;
  return CEvn_Event::~CEvn_Event(&v16);
}


// address=[0x152e980]
// Decompiled from void *__thiscall CWorkshopBuildingRole::Clear(CWorkshopBuildingRole *this)
void  CWorkshopBuildingRole::Clear(void) {
  
  *((_BYTE *)this + 380) = 0;
  *((_BYTE *)this + 381) = 0;
  *((_WORD *)this + 191) = 0;
  *((_DWORD *)this + 96) = 0;
  std::vector<unsigned short>::clear();
  return j__memset((char *)this + 404, 0, 5u);
}


// address=[0x152f1e0]
// Decompiled from void __thiscall CWorkshopBuildingRole::ConvertEventIntoGoal(  CWorkshopBuildingRole *this,  struct CBuilding *a2,  struct CEntityEvent *a3)
void  CWorkshopBuildingRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
  ;
}


// address=[0x152f260]
// Decompiled from char __thiscall CWorkshopBuildingRole::TryCrushBuilding(CWorkshopBuildingRole *this)
bool  CWorkshopBuildingRole::TryCrushBuilding(void) {
  
  return 1;
}


