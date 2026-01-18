#include "CMineRole.h"

// Definitions for class CMineRole

// address=[0x1401440]
// Decompiled from int __cdecl CMineRole::New(int a1)
class CPersistence * __cdecl CMineRole::New(std::istream & a1) {
  
  if ( operator new(0x1BCu) )
    return CMineRole::CMineRole(a1);
  else
    return 0;
}


// address=[0x14fdb30]
// Decompiled from int __cdecl CMineRole::Load(int a1)
class CMineRole * __cdecl CMineRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CMineRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x1513d90]
// Decompiled from CMineRole *__thiscall CMineRole::CMineRole(CMineRole *this)
 CMineRole::CMineRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CMineRole::_vftable_;
  *((_BYTE *)this + 380) = 0;
  *((_BYTE *)this + 381) = 0;
  *((_WORD *)this + 191) = 0;
  *((_WORD *)this + 192) = 0;
  *((_WORD *)this + 193) = 0;
  *((_WORD *)this + 194) = 0;
  std::vector<unsigned short>::vector<unsigned short>((char *)this + 392);
  std::vector<unsigned short>::vector<unsigned short>((char *)this + 408);
  *((_DWORD *)this + 110) = 0;
  std::vector<unsigned short>::clear();
  std::vector<unsigned short>::clear();
  memset((char *)this + 424, 0, 0xFu);
  return this;
}


// address=[0x1513e50]
// Decompiled from void __thiscall CMineRole::LogicUpdate(CMineRole *this, struct CBuilding *a2)
void  CMineRole::LogicUpdate(class CBuilding * a2) {
  
  int v2; // esi
  int v3; // eax
  int v4; // [esp-8h] [ebp-24h]
  int v5; // [esp-4h] [ebp-20h]
  unsigned __int8 *v6; // [esp+Ch] [ebp-10h]
  int v7; // [esp+10h] [ebp-Ch]
  char v8; // [esp+14h] [ebp-8h]

  if ( IEntity::FlagBits(a2, EntityFlag_Selected) )
    (*(void (__thiscall **)(CMineRole *, struct CBuilding *, int))(*(_DWORD *)this + 88))(this, a2, 1);
  v8 = *((_BYTE *)this + 4);
  if ( v8 == 1 )
  {
    if ( (*(unsigned __int8 (__thiscall **)(CMineRole *, struct CBuilding *))(*(_DWORD *)this + 120))(this, a2) )
    {
      *((_BYTE *)this + 4) = 3;
      *((_BYTE *)this + 5) = 0;
      return;
    }
    goto LABEL_27;
  }
  if ( v8 == 2 )
  {
    if ( *(unsigned __int8 *)(*((_DWORD *)this + 94) + 480) < 4u )
      v7 = 4;
    else
      v7 = *(unsigned __int8 *)(*((_DWORD *)this + 94) + 480);
    if ( *((unsigned __int8 *)this + 5) > v7 )
    {
      *((_BYTE *)this + 4) = 3;
      *((_BYTE *)this + 5) = 0;
      IAnimatedEntity::RegisterForLogicUpdate(1);
    }
    else
    {
      ++*((_BYTE *)this + 5);
      IAnimatedEntity::RegisterForLogicUpdate(14);
    }
    return;
  }
  if ( v8 != 3 )
    return;
  if ( !*((_BYTE *)this + 29)
    || !IEntity::FlagBits(a2, (EntityFlag)0x1000u)
    || (v6 = CPileMgr::operator[](*((unsigned __int16 *)this + 191)),
        (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v6 + 40))(v6) >= 8) )
  {
LABEL_27:
    IAnimatedEntity::RegisterForLogicUpdate(31);
    return;
  }
  if ( (int)CMineRole::GetProductivity(this, a2) <= 0 )
    ++*((_DWORD *)this + 110);
  else
    *((_DWORD *)this + 110) = 0;
  if ( *((int *)this + 110) > 15 )
  {
    v2 = IEntity::OwnerId((unsigned __int8 *)a2);
    if ( v2 == CPlayerManager::GetLocalPlayerId() )
    {
      v5 = IEntity::Y(a2);
      v4 = IEntity::X(a2);
      v3 = IEntity::OwnerId((unsigned __int8 *)a2);
      CTextMsgHandler::AddWarningMsg(2526, v3, v4, v5);
    }
    *((_DWORD *)this + 110) = 0;
  }
  CMineRole::Work(this, a2);
}


// address=[0x1514060]
// Decompiled from unsigned int __thiscall CMineRole::FillGfxInfo(CMineRole *this, struct CBuilding *a2, struct SGfxObjectInfo *a3)
void  CMineRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  CSettler *v6; // eax
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned int result; // eax
  unsigned __int16 *v10; // eax
  unsigned __int8 *v11; // eax
  unsigned __int16 *v12; // eax
  unsigned __int8 *v13; // eax
  int v14; // [esp-Ch] [ebp-1Ch]
  unsigned int i; // [esp+4h] [ebp-Ch]
  int v16; // [esp+8h] [ebp-8h]

  (*(void (__thiscall **)(CMineRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v14 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo((int)a3, v3, v14, 1, (int)this + 76);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  *((_BYTE *)a3 + 715) = CPlayerManager::Color(v4);
  v5 = IEntity::OwnerId((unsigned __int8 *)a2);
  IBuildingRole::MiniFlag(this, a3, v5);
  if ( *((_BYTE *)this + 29) == 1 )
  {
    v6 = (CSettler *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 4));
    CSettler::GetPatchGfx(v6, (struct SGfxObjectInfo *)((char *)a3 + 200));
  }
  v16 = 0;
  v7 = CPileMgr::operator[](*((unsigned __int16 *)this + 191));
  if ( (unsigned __int8)CPile::IsPatchPile(v7) )
  {
    v8 = CPileMgr::operator[](*((unsigned __int16 *)this + 191));
    CPile::GetPatchGfx((CPile *)v8, (struct SGfxObjectInfo *)((char *)a3 + 536));
    v16 = 1;
  }
  for ( i = 0; ; ++i )
  {
    result = std::vector<unsigned short>::size((char *)this + 392);
    if ( i >= result )
      break;
    v10 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 392, i);
    v11 = CPileMgr::operator[](*v10);
    if ( (unsigned __int8)CPile::IsPatchPile(v11) )
    {
      v12 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 392, i);
      v13 = CPileMgr::operator[](*v12);
      CPile::GetPatchGfx((CPile *)v13, (struct SGfxObjectInfo *)((char *)a3 + 16 * v16++ + 536));
    }
  }
  return result;
}


// address=[0x1514210]
// Decompiled from int __thiscall CMineRole::Init(CMineRole *this, struct CBuilding *a2)
void  CMineRole::Init(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  int result; // eax
  int v7; // [esp-4h] [ebp-20h]
  int v8; // [esp+0h] [ebp-1Ch]
  int v9; // [esp+4h] [ebp-18h]
  char v10; // [esp+8h] [ebp-14h]
  int v11; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  __int16 v14; // [esp+1Ah] [ebp-2h] BYREF

  IBuildingRole::InitCommon((int)a2);
  *((_BYTE *)this + 4) = 1;
  *((_BYTE *)this + 5) = 0;
  IAnimatedEntity::RegisterForLogicUpdate(2);
  *((_WORD *)this + 191) = 0;
  std::vector<unsigned short>::clear();
  memset((char *)this + 424, 0, 0xFu);
  for ( i = 0; i < *(char *)(*((_DWORD *)this + 94) + 57); ++i )
  {
    v2 = IEntity::WorldIdx();
    v8 = *(char *)(*((_DWORD *)this + 94) + 16 * i + 60) + CWorldManager::X(v2);
    v3 = IEntity::WorldIdx();
    v9 = *(char *)(*((_DWORD *)this + 94) + 16 * i + 61) + CWorldManager::Y(v3);
    v11 = CPileMgr::AddPile(
            (CPileMgr *)&g_cPileMgr,
            v8,
            v9,
            *(char *)(*((_DWORD *)this + 94) + 16 * i + 62),
            0,
            *(char *)(*((_DWORD *)this + 94) + 16 * i + 63),
            *(char *)(*((_DWORD *)this + 94) + 16 * i + 64),
            *(char *)(*((_DWORD *)this + 94) + 16 * i + 65),
            *(_DWORD *)(*((_DWORD *)this + 94) + 16 * i + 68),
            *(_DWORD *)(*((_DWORD *)this + 94) + 16 * i + 72));
    v7 = IEntity::ID();
    v4 = CPileMgr::operator[](v11);
    CPile::SetBuildingId((CPile *)v4, v7);
    if ( *(_BYTE *)(*((_DWORD *)this + 94) + 16 * i + 65) == 1 )
    {
      v5 = CPileMgr::operator[](v11);
      IEntity::ClearFlagBits(v5, EntityFlag_Visible);
    }
    v10 = *(_BYTE *)(*((_DWORD *)this + 94) + 16 * i + 63);
    if ( v10 )
    {
      if ( v10 == 1 )
      {
        v14 = v11;
        std::vector<unsigned short>::push_back(&v14);
      }
    }
    else
    {
      if ( *((_WORD *)this + 191)
        && BBSupportDbgReport(2, "MapObjects\\Building\\MineRole.cpp", 227, "m_uProdPileId == 0") == 1 )
      {
        __debugbreak();
      }
      *((_WORD *)this + 191) = v11;
    }
  }
  if ( !*((_WORD *)this + 191)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MineRole.cpp", 243, "m_uProdPileId != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !std::vector<unsigned short>::size((char *)this + 392)
    && BBSupportDbgReport(2, "MapObjects\\Building\\MineRole.cpp", 244, "m_vDeliverPileId.size()>0") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 381) = 10;
  std::vector<unsigned short>::clear();
  *((_BYTE *)this + 380) = 0;
  byte_3F1E50A = 0;
  CMineRole::InitMine(this, a2);
  result = IEntity::FlagBits(a2, EntityFlag_Selected);
  if ( result )
    result = (*(int (__thiscall **)(CMineRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 88))(this, a2, 0);
  *((_DWORD *)this + 110) = 0;
  return result;
}


// address=[0x1514520]
// Decompiled from int __thiscall CMineRole::PostLoadInit(CMineRole *this, struct CBuilding *a2)
void  CMineRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  result = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  *((_DWORD *)this + 94) = result;
  return result;
}


// address=[0x1514550]
// Decompiled from char __thiscall CMineRole::SettlerEnter(CMineRole *this, struct CBuilding *a2, int a3)
bool  CMineRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  float v7; // xmm0_4
  int v8; // eax
  void *v9; // eax
  int v10; // eax
  const char *BuildingName; // eax
  const char *v13; // [esp+0h] [ebp-58h]
  const char *RaceName; // [esp+4h] [ebp-54h]
  _BYTE v15[24]; // [esp+Ch] [ebp-4Ch] BYREF
  float v16; // [esp+24h] [ebp-34h]
  float v17; // [esp+28h] [ebp-30h]
  int v18; // [esp+2Ch] [ebp-2Ch]
  int v19; // [esp+30h] [ebp-28h]
  int v20; // [esp+34h] [ebp-24h]
  _BYTE *v21; // [esp+38h] [ebp-20h]
  int v22; // [esp+3Ch] [ebp-1Ch]
  CMFCToolBarButton *v23; // [esp+40h] [ebp-18h]
  CSettler *v24; // [esp+44h] [ebp-14h]
  _DWORD *v25; // [esp+48h] [ebp-10h]
  int v26; // [esp+54h] [ebp-4h]

  v25 = this;
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\MineRole.cpp", 273, "_iSettlerId > 0") == 1 )
    __debugbreak();
  v24 = (CSettler *)CSettlerMgr::operator[](a3);
  if ( *((_BYTE *)v25 + 29) )
  {
    if ( *((unsigned __int16 *)v25 + 4) != a3
      && BBSupportDbgReport(2, "MapObjects\\Building\\MineRole.cpp", 307, "m_uSettlerId == _iSettlerId") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    *((_BYTE *)v25 + 29) = 1;
    *((_WORD *)v25 + 4) = a3;
    if ( IEntity::FlagBits(a2, (EntityFlag)0x1000u) )
    {
      CEntityEvent::CEntityEvent((CEntityEvent *)v15, 8u, 0, *((unsigned __int16 *)v25 + 3), 0, 0);
      v26 = 0;
      v21 = v15;
      (*(void (__thiscall **)(struct CBuilding *, _BYTE *))(*(_DWORD *)a2 + 124))(a2, v15);
      v26 = -1;
      CEntityEvent::~CEntityEvent(v15);
    }
  }
  if ( IEntity::Race(a2) )
  {
    v23 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((unsigned __int16 *)v25 + 3));
    v3 = CBuilding::DoorPackedXY(v23);
    v20 = Y16X16::UnpackXFast(v3);
    v4 = CBuilding::DoorPackedXY(v23);
    v19 = Y16X16::UnpackYFast(v4);
    v5 = IEntity::X(v23);
    v18 = v20 - v5;
    v6 = IEntity::Y(v23);
    v22 = v19 - v6;
    v16 = (float)((float)v18 + (float)((float)((float)(v19 - v6) * -1.0) / 2.0)) * 24.0;
    v7 = (float)((float)(v19 - v6) * 24.0) / 2.0;
    v17 = v7;
    CSettler::SetOffset(v24, v16, v7);
  }
  else
  {
    CSettler::SetOffset(v24, 0.0, 0.0);
  }
  IEntity::ClearFlagBits(v24, EntityFlag_Visible);
  IEntity::SetFlagBits(v24, EntityFlag_MagicInvisible);
  IMovingEntity::SetDisplacementCosts(10);
  *((_BYTE *)v25 + 4) = 2;
  *((_BYTE *)v25 + 5) = 0;
  IAnimatedEntity::RegisterForLogicUpdate(14);
  if ( *(_BYTE *)(v25[94] + 480) )
    return 1;
  v8 = IEntity::Race(a2);
  RaceName = CS4DefineNames::GetRaceName(v8);
  v9 = (void *)typeid(v25);
  v13 = (const char *)type_info::name(v9);
  v10 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
  BuildingName = CS4DefineNames::GetBuildingName(v10);
  BBSupportTracePrintF(
    2,
    "WARNING: Building %s (role %s) of race %s has no production delay!",
    BuildingName,
    v13,
    RaceName);
  return 1;
}


// address=[0x15147f0]
// Decompiled from int __thiscall CMineRole::GetPileIdWithGood(CMineRole *this, int a2)
int  CMineRole::GetPileIdWithGood(int a2)const {
  
  unsigned __int16 *v2; // eax
  unsigned __int16 *v4; // eax
  int v5; // eax
  int v6; // [esp+0h] [ebp-14h]
  unsigned __int8 *v7; // [esp+4h] [ebp-10h]
  unsigned __int8 *v8; // [esp+8h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-8h]

  v6 = std::vector<unsigned short>::size((char *)this + 392);
  for ( i = 0; i < v6; ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[](i);
    v8 = CPileMgr::operator[](*v2);
    if ( a2 == (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v8 + 60))(v8) )
      return *(unsigned __int16 *)std::vector<unsigned short>::operator[](i);
  }
  v7 = CPileMgr::operator[](*((unsigned __int16 *)this + 191));
  if ( a2 == (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v7 + 60))(v7) )
    return *((unsigned __int16 *)this + 191);
  v4 = (unsigned __int16 *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v5 = IEntity::Type(v4);
  if ( BBSupportDbgReportF(2, "MapObjects\\Building\\MineRole.cpp", 567, "illegal goodcheck %u at building %u ", a2, v5) == 1 )
    __debugbreak();
  return 0;
}


// address=[0x1514900]
// Decompiled from int __thiscall CMineRole::GoodArrive(CMineRole *this, int a2)
void  CMineRole::GoodArrive(int a2) {
  
  _DWORD *v2; // eax
  int result; // eax

  CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  v2 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  result = IEntity::FlagBits(v2, EntityFlag_Registered);
  if ( result )
    return result;
  CBuildingMgr::operator[](*((unsigned __int16 *)this + 3));
  return IAnimatedEntity::RegisterForLogicUpdate(16);
}


// address=[0x1514970]
// Decompiled from struct CPile *__thiscall CMineRole::RestockFavouriteFood(CMineRole *this)
void  CMineRole::RestockFavouriteFood(void) {
  
  struct CPile *result; // eax
  int v2; // esi
  int v3; // [esp+8h] [ebp-10h]
  int v4; // [esp+Ch] [ebp-Ch]
  CPile *v6; // [esp+14h] [ebp-4h]

  if ( std::vector<unsigned short>::size((char *)this + 408) )
    v4 = *(unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 408, 0);
  else
    v4 = 0;
  result = CPileMgr::GetPilePtr(v4);
  v6 = result;
  if ( !result )
    return result;
  v2 = (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)result + 40))(result);
  result = (struct CPile *)CPile::AmountComing(v6);
  v3 = 8 - ((_DWORD)result + v2);
  if ( v3 > 0 )
    return (struct CPile *)CPile::IncreaseUnforeseen(v6, v3);
  return result;
}


// address=[0x1514a00]
// Decompiled from _DWORD *__thiscall CMineRole::FillDialog(CMineRole *this, struct CBuilding *a2, bool a3)
void  CMineRole::FillDialog(class CBuilding * a2, bool a3) {
  
  int v3; // eax
  int v4; // eax
  unsigned __int16 *v5; // eax
  unsigned __int16 *v6; // eax
  unsigned __int8 *v7; // eax
  int v9; // [esp-8h] [ebp-54h]
  int v10; // [esp-8h] [ebp-54h]
  unsigned int v11; // [esp+4h] [ebp-48h]
  unsigned __int8 *v12; // [esp+Ch] [ebp-40h]
  unsigned __int8 *v13; // [esp+10h] [ebp-3Ch]
  unsigned __int8 *v14; // [esp+14h] [ebp-38h]
  unsigned int i; // [esp+1Ch] [ebp-30h]
  CEvn_Event v17; // [esp+24h] [ebp-28h] BYREF
  int v18; // [esp+48h] [ebp-4h]

  dword_3F1E500 = 3;
  memset(byte_3F1E510, 0, 0xAu);
  memset(&byte_3F1E51A, 0, 0x14u);
  byte_3F1E505 = IEntity::Race(a2);
  byte_3F1E504 = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E507 = 1;
  byte_3F1E508 = IEntity::FlagBits(a2, (EntityFlag)0x1000u) != 0;
  byte_3F1E509 = 0;
  v9 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E50B = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v9, 0);
  v10 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E50C = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v10, 1u);
  byte_3F1E506 = *((_BYTE *)this + 29);
  if ( *((_BYTE *)this + 29) )
    byte_3F1E50D = *(_BYTE *)(*((_DWORD *)this + 94) + 478);
  byte_3F1E50A = CMineRole::GetProductivity(this, a2);
  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 392); ++i )
  {
    v5 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 392, i);
    v14 = CPileMgr::operator[](*v5);
    byte_3F1E511[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v14 + 40))(v14);
    v6 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 392, i);
    v13 = CPileMgr::operator[](*v6);
    byte_3F1E510[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v13 + 60))(v13);
  }
  v12 = CPileMgr::operator[](*((unsigned __int16 *)this + 191));
  byte_3F1E51B = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v12 + 40))(v12);
  v7 = CPileMgr::operator[](*((unsigned __int16 *)this + 191));
  byte_3F1E51A = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v7 + 60))(v7);
  v11 = 604;
  if ( !a3 )
    v11 = 602;
  CEvn_Event::CEvn_Event(&v17, v11, 0, (unsigned int)&g_cResourceUpgradeInfo, 0);
  v18 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v17);
  v18 = -1;
  return CEvn_Event::~CEvn_Event(&v17);
}


// address=[0x1514ca0]
// Decompiled from char *__thiscall CMineRole::CMineRole(char *this, int a2)
 CMineRole::CMineRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-24h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  unsigned int v5; // [esp+10h] [ebp-1Ch] BYREF
  int i; // [esp+14h] [ebp-18h]
  char *v7; // [esp+18h] [ebp-14h]
  _BYTE v8[4]; // [esp+1Ch] [ebp-10h] BYREF
  int v9; // [esp+28h] [ebp-4h]

  v7 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v9 = 0;
  *(_DWORD *)v7 = &CMineRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>(v7 + 392);
  std::vector<unsigned short>::vector<unsigned short>(v7 + 408);
  LOBYTE(v9) = 2;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CMineRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, v7 + 380);
  operator^<unsigned char>(a2, v7 + 381);
  operator^<unsigned short>(a2, v7 + 382);
  operator^<unsigned short>(a2, v7 + 384);
  operator^<unsigned short>(a2, v7 + 386);
  operator^<unsigned short>(a2, v7 + 388);
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
  for ( i = 0; i < 15; ++i )
    operator^<char>(a2, &v7[i + 424]);
  *((_DWORD *)v7 + 110) = 0;
  v9 = -1;
  return v7;
}


// address=[0x1514ed0]
// Decompiled from unsigned int __thiscall CMineRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CMineRole::Store(std::ostream & a2) {
  
  __int16 *v2; // eax
  unsigned int result; // eax
  __int16 *v4; // eax
  int v5; // [esp+0h] [ebp-10h] BYREF
  int v6; // [esp+4h] [ebp-Ch] BYREF
  __int16 *v7; // [esp+8h] [ebp-8h]
  unsigned int i; // [esp+Ch] [ebp-4h]

  v7 = (__int16 *)this;
  IBuildingRole::Store(this, a2);
  v5 = 1;
  operator^<unsigned int>(a2, &v5);
  operator^<unsigned char>(a2, (int)(v7 + 190));
  operator^<unsigned char>(a2, (int)v7 + 381);
  operator^<unsigned short>((int)a2, v7 + 191);
  operator^<unsigned short>((int)a2, v7 + 192);
  operator^<unsigned short>((int)a2, v7 + 193);
  operator^<unsigned short>((int)a2, v7 + 194);
  v6 = std::vector<unsigned short>::size(v7 + 196);
  operator^<unsigned int>(a2, &v6);
  for ( i = 0; i < v6; ++i )
  {
    v2 = (__int16 *)std::vector<unsigned short>::operator[](v7 + 196, i);
    operator^<unsigned short>((int)a2, v2);
  }
  v6 = std::vector<unsigned short>::size(v7 + 204);
  operator^<unsigned int>(a2, &v6);
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= v6 )
      break;
    v4 = (__int16 *)std::vector<unsigned short>::operator[](v7 + 204, i);
    operator^<unsigned short>((int)a2, v4);
  }
  for ( i = 0; (int)i < 15; ++i )
  {
    operator^<char>(a2, (char *)v7 + i + 424);
    result = i + 1;
  }
  return result;
}


// address=[0x1516030]
// Decompiled from int __thiscall CMineRole::~CMineRole(CMineRole *this)
 CMineRole::~CMineRole(void) {
  
  std::vector<unsigned short>::~vector<unsigned short>((char *)this + 408);
  std::vector<unsigned short>::~vector<unsigned short>((char *)this + 392);
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x15160b0]
// Decompiled from int __thiscall CMineRole::ClassID(CMineRole *this)
unsigned long  CMineRole::ClassID(void)const {
  
  return CMineRole::m_iClassID;
}


// address=[0x15160d0]
// Decompiled from void *__thiscall CMineRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)
int  CMineRole::GetBuildingNeed(int a2)const {
  
  return 0;
}


// address=[0x15160f0]
// Decompiled from int __thiscall CMineRole::GetBuildingRole(CMineRole *this)
int  CMineRole::GetBuildingRole(void) {
  
  return 7;
}


// address=[0x3d8b584]
// [Decompilation failed for static unsigned long CMineRole::m_iClassID]

// address=[0x1515070]
// Decompiled from char __thiscall CMineRole::CrushBuilding(CMineRole *this)
bool  CMineRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x1515080]
// Decompiled from void __thiscall CMineRole::ConvertEventIntoGoal(CMineRole *this, struct CBuilding *a2, struct CEntityEvent *a3)
void  CMineRole::ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3) {
  
  ;
}


// address=[0x1515090]
// Decompiled from int __thiscall CMineRole::RememberProductivity(CMineRole *this, struct CBuilding *a2, bool a3)
void  CMineRole::RememberProductivity(class CBuilding * a2, bool a3) {
  
  int result; // eax
  char v4; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < 14; ++i )
    *((_BYTE *)this + i + 424) = *((_BYTE *)this + i + 425);
  if ( a3 )
    v4 = 100;
  else
    v4 = 0;
  result = 14;
  *((_BYTE *)this + 438) = v4;
  return result;
}


// address=[0x1515100]
// Decompiled from int __thiscall CMineRole::GetProductivity(CMineRole *this, struct CBuilding *a2)
int  CMineRole::GetProductivity(class CBuilding * a2) {
  
  int v4; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v4 = 0;
  for ( i = 0; i < 15; ++i )
  {
    if ( *((_BYTE *)this + i + 424) != 100
      && *((_BYTE *)this + i + 424)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Building\\MineRole.cpp",
           956,
           "m_caProductionHistory[i] == 100 || m_caProductionHistory[i] == 0") == 1 )
    {
      __debugbreak();
    }
    v4 += *((char *)this + i + 424);
  }
  return v4 / 15;
}


// address=[0x15151a0]
// Decompiled from int __thiscall CMineRole::InitMine(CMineRole *this, struct CBuilding *a2)
void  CMineRole::InitMine(class CBuilding * a2) {
  
  int result; // eax
  __int16 v4; // [esp+Ah] [ebp-1Eh] BYREF
  __int16 v5; // [esp+Ch] [ebp-1Ch] BYREF
  __int16 v6; // [esp+Eh] [ebp-1Ah] BYREF
  __int16 v7; // [esp+10h] [ebp-18h] BYREF
  __int16 v8; // [esp+12h] [ebp-16h] BYREF
  __int16 v9; // [esp+14h] [ebp-14h] BYREF
  __int16 v10; // [esp+16h] [ebp-12h] BYREF
  __int16 v11; // [esp+18h] [ebp-10h] BYREF
  __int16 v12; // [esp+1Ah] [ebp-Eh] BYREF
  __int16 v13; // [esp+1Ch] [ebp-Ch] BYREF
  __int16 v14; // [esp+1Eh] [ebp-Ah] BYREF
  __int16 v15; // [esp+20h] [ebp-8h] BYREF
  __int16 v16; // [esp+22h] [ebp-6h] BYREF
  __int16 v17; // [esp+24h] [ebp-4h] BYREF
  __int16 v18; // [esp+26h] [ebp-2h] BYREF

  result = IEntity::Type((unsigned __int16 *)a2) - 14;
  switch ( result )
  {
    case 0:
      v9 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 9);
      std::vector<unsigned short>::push_back(&v9);
      v8 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 24);
      std::vector<unsigned short>::push_back(&v8);
      v7 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 11);
      result = std::vector<unsigned short>::push_back(&v7);
      *((_BYTE *)this + 380) = 80;
      break;
    case 1:
      v15 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 24);
      std::vector<unsigned short>::push_back(&v15);
      v14 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 9);
      std::vector<unsigned short>::push_back(&v14);
      v13 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 11);
      result = std::vector<unsigned short>::push_back(&v13);
      *((_BYTE *)this + 380) = 32;
      break;
    case 2:
      v12 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 11);
      std::vector<unsigned short>::push_back(&v12);
      v11 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 9);
      std::vector<unsigned short>::push_back(&v11);
      v10 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 24);
      result = std::vector<unsigned short>::push_back(&v10);
      *((_BYTE *)this + 380) = 48;
      break;
    case 3:
      v18 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 9);
      std::vector<unsigned short>::push_back(&v18);
      v17 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 24);
      std::vector<unsigned short>::push_back(&v17);
      v16 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 11);
      result = std::vector<unsigned short>::push_back(&v16);
      *((_BYTE *)this + 380) = 16;
      break;
    case 4:
      v6 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 24);
      std::vector<unsigned short>::push_back(&v6);
      v5 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 9);
      std::vector<unsigned short>::push_back(&v5);
      v4 = (*(int (__thiscall **)(CMineRole *, int))(*(_DWORD *)this + 56))(this, 11);
      result = std::vector<unsigned short>::push_back(&v4);
      *((_BYTE *)this + 380) = 64;
      break;
    default:
      return result;
  }
  return result;
}


// address=[0x1515460]
// Decompiled from CMineRole *__thiscall CMineRole::Work(CMineRole *this, struct CBuilding *a2)
void  CMineRole::Work(class CBuilding * a2) {
  
  CMineRole *result; // eax
  unsigned __int8 *v3; // eax
  _BYTE v4[24]; // [esp+4h] [ebp-34h] BYREF
  CEntityEvent *v5; // [esp+1Ch] [ebp-1Ch]
  CEntityEvent *v6; // [esp+20h] [ebp-18h]
  int v7; // [esp+24h] [ebp-14h]
  CMineRole *v8; // [esp+28h] [ebp-10h]
  int v9; // [esp+34h] [ebp-4h]

  v8 = this;
  if ( !*((_BYTE *)this + 381) )
    CMineRole::TakeNextFood(v8, a2);
  result = v8;
  if ( !*((_BYTE *)v8 + 381) )
    return result;
  --*((_BYTE *)v8 + 381);
  if ( CMineRole::SearchResource(v8, a2) )
  {
    if ( !*(_BYTE *)std::vector<unsigned char>::operator[](0)
      && BBSupportDbgReport(2, "MapObjects\\Building\\MineRole.cpp", 686, "m_pBuildingInfo->vAnimListId[0] != 0") == 1 )
    {
      __debugbreak();
    }
    v7 = CSettlerMgr::operator[](*((unsigned __int16 *)v8 + 4));
    v3 = (unsigned __int8 *)std::vector<unsigned char>::operator[](0);
    v6 = CEntityEvent::CEntityEvent((CEntityEvent *)v4, 3u, 0, 0, *v3, 0);
    v5 = v6;
    v9 = 0;
    (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v7 + 80))(v7, v6);
    v9 = -1;
    CEntityEvent::~CEntityEvent(v4);
    CMineRole::RememberProductivity(v8, a2, 1);
  }
  else
  {
    CMineRole::RememberProductivity(v8, a2, 0);
    IAnimatedEntity::RegisterForLogicUpdate(14);
  }
  result = v8;
  *((_BYTE *)v8 + 4) = 2;
  *((_BYTE *)v8 + 5) = 0;
  return result;
}


// address=[0x15155e0]
// Decompiled from int __thiscall CMineRole::TakeNextFood(CMineRole *this, struct CBuilding *a2)
void  CMineRole::TakeNextFood(class CBuilding * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // esi
  int result; // eax
  int v7; // [esp+4h] [ebp-24h]
  int v8; // [esp+8h] [ebp-20h]
  int v9; // [esp+10h] [ebp-18h]
  unsigned __int8 *v10; // [esp+14h] [ebp-14h]
  int DifficultyLevel; // [esp+1Ch] [ebp-Ch]
  unsigned int i; // [esp+20h] [ebp-8h]
  int v14; // [esp+24h] [ebp-4h]

  v14 = 0;
  for ( i = 0; i < std::vector<unsigned short>::size((char *)this + 408); ++i )
  {
    v2 = (unsigned __int16 *)std::vector<unsigned short>::operator[]((char *)this + 408, i);
    v10 = CPileMgr::operator[](*v2);
    if ( (unsigned __int8)CPile::GoodAvailable(v10) )
    {
      CPile::DecreaseUnforeseen((CPile *)v10, 1);
      if ( i )
        v9 = 2;
      else
        v9 = 10;
      v14 = v9;
      break;
    }
  }
  v7 = IEntity::OwnerId((unsigned __int8 *)a2);
  DifficultyLevel = IAIDifficultyLevels::GetDifficultyLevel(v7);
  if ( DifficultyLevel > 1 )
  {
    v3 = CPileMgr::operator[](*((unsigned __int16 *)this + 191));
    v8 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v3 + 40))(v3);
    if ( v14 <= 0 )
    {
      if ( v8 < 2 )
      {
        if ( DifficultyLevel < 3 )
        {
          v5 = CStateGame::Rand(g_pGame);
          if ( v5 < CRandom16::PercentValue(5u) )
            v14 = DifficultyLevel + 3;
        }
        else
        {
          v4 = CStateGame::Rand(g_pGame);
          if ( v4 < CRandom16::PercentValue(0x19u) )
            v14 = 10;
        }
      }
    }
    else if ( v8 >= 4 )
    {
      v14 += DifficultyLevel;
    }
    else
    {
      v14 += DifficultyLevel + 3;
    }
  }
  result = v14 + *((unsigned __int8 *)this + 381);
  *((_BYTE *)this + 381) = result;
  return result;
}


// address=[0x1515760]
// Decompiled from char __thiscall CMineRole::SearchResource(CMineRole *this, struct CBuilding *a2)
bool  CMineRole::SearchResource(class CBuilding * a2) {
  
  int v2; // esi
  int v3; // esi
  int v4; // eax
  int v6; // [esp+10h] [ebp-3Ch]
  int v8; // [esp+18h] [ebp-34h]
  char v9; // [esp+20h] [ebp-2Ch]
  unsigned int v10; // [esp+24h] [ebp-28h]
  int v11; // [esp+2Ch] [ebp-20h]
  int v12; // [esp+30h] [ebp-1Ch]
  int v13; // [esp+34h] [ebp-18h]
  int v14; // [esp+38h] [ebp-14h]
  signed int v15; // [esp+3Ch] [ebp-10h]
  int i; // [esp+40h] [ebp-Ch]
  int v17; // [esp+44h] [ebp-8h]
  int DifficultyLevel; // [esp+48h] [ebp-4h]

  v6 = IEntity::OwnerId((unsigned __int8 *)a2);
  DifficultyLevel = IAIDifficultyLevels::GetDifficultyLevel(v6);
  if ( DifficultyLevel > 1 )
    v11 = DifficultyLevel;
  else
    v11 = 1;
  v17 = 3;
  if ( DifficultyLevel < 3 )
  {
    if ( DifficultyLevel > 1 )
      v17 = 3 - DifficultyLevel;
  }
  else
  {
    v17 = 0;
  }
  for ( i = 0; ; ++i )
  {
    if ( i >= v11 )
      return 0;
    v10 = (unsigned int)CGameData::Rand(g_pGameData) & 0x3F;
    v2 = IEntity::X(a2);
    v12 = CSpiralOffsets::DeltaX(v10) + v2;
    v3 = IEntity::Y(a2);
    v13 = CSpiralOffsets::DeltaY(v10) + v3;
    if ( (unsigned __int8)CWorldManager::InWorld(v12, v13) )
    {
      v4 = CWorldManager::Index(v12, v13);
      v9 = CWorldManager::Resource(v4);
      if ( (v9 & 0xF0) == *((unsigned __int8 *)this + 380) )
      {
        v15 = (unsigned int)CGameData::Rand(g_pGameData) & 3;
        if ( v15 > v17 )
          v15 = v17;
        v14 = v9 & 0xF;
        if ( v15 < v14 )
          break;
      }
    }
  }
  if ( v14 <= (DifficultyLevel != 0) )
    v8 = DifficultyLevel != 0;
  else
    v8 = v14 - 1;
  CWorldManager::SetResource(v12, v13, *((unsigned __int8 *)this + 380), v8);
  return 1;
}


// address=[0x1516140]
// Decompiled from char __thiscall CMineRole::TryCrushBuilding(CMineRole *this)
bool  CMineRole::TryCrushBuilding(void) {
  
  return 1;
}


