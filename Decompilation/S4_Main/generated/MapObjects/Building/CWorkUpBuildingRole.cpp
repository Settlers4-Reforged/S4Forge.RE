#include "CWorkUpBuildingRole.h"

// Definitions for class CWorkUpBuildingRole

// address=[0x1402980]
// Decompiled from int __cdecl CWorkUpBuildingRole::New(int a1)
class CPersistence * __cdecl CWorkUpBuildingRole::New(std::istream & a1) {
  
  if ( operator new(0x190u) != 0 )
  {
    return ((_DWORD (__stdcall *)(int))CWorkUpBuildingRole::CWorkUpBuildingRole)(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x14e66b0]
// Decompiled from int __thiscall CWorkUpBuildingRole::~CWorkUpBuildingRole(CWorkUpBuildingRole *this)
 CWorkUpBuildingRole::~CWorkUpBuildingRole(void) {
  
  std::vector<unsigned short>::~vector<unsigned short>((char *)this + 384);
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14fcb70]
// Decompiled from CWorkUpBuildingRole *__thiscall CWorkUpBuildingRole::CWorkUpBuildingRole(CWorkUpBuildingRole *this)
 CWorkUpBuildingRole::CWorkUpBuildingRole(void) {
  
  IBuildingRole::IBuildingRole((IBuildingRole *)this);
  *(_DWORD *)this = &CWorkUpBuildingRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>((char *)this + 384);
  return this;
}


// address=[0x14fd1c0]
// Decompiled from int __thiscall CWorkUpBuildingRole::ClassID(CWorkUpBuildingRole *this)
unsigned long  CWorkUpBuildingRole::ClassID(void)const {
  
  return CWorkUpBuildingRole::m_iClassID;
}


// address=[0x14fd5a0]
// Decompiled from int __thiscall CWorkUpBuildingRole::GetBuildingRole(CWorkUpBuildingRole *this)
int  CWorkUpBuildingRole::GetBuildingRole(void) {
  
  return 2;
}


// address=[0x14fdcf0]
// Decompiled from int __cdecl CWorkUpBuildingRole::Load(struct std::istream *a1)
class CWorkUpBuildingRole * __cdecl CWorkUpBuildingRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)((void **(__cdecl *)(struct std::istream *, struct TypeDescriptor *))CPersistence::New)(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CWorkUpBuildingRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x152f370]
// Decompiled from int __thiscall CWorkUpBuildingRole::LogicUpdate(CWorkUpBuildingRole *this, struct CBuilding *a2)
void  CWorkUpBuildingRole::LogicUpdate(class CBuilding * a2) {
  
  int result; // eax
  unsigned __int16 *v3; // eax
  unsigned __int8 *v4; // eax
  CEntityEvent v5; // [esp+4h] [ebp-44h] BYREF
  int v6; // [esp+1Ch] [ebp-2Ch]
  CEntityEvent *v7; // [esp+20h] [ebp-28h]
  CEntityEvent *v8; // [esp+24h] [ebp-24h]
  CSettler *v9; // [esp+28h] [ebp-20h]
  unsigned __int8 *v10; // [esp+2Ch] [ebp-1Ch]
  int v11; // [esp+30h] [ebp-18h]
  char v12; // [esp+34h] [ebp-14h]
  CWorkUpBuildingRole *v13; // [esp+38h] [ebp-10h]
  int v14; // [esp+44h] [ebp-4h]

  v13 = this;
  result = IEntity::FlagBits(a2, ENTITY_FLAG_Selected);
  if ( result != 0 )
  {
    result = (*(int (__thiscall **)(CWorkUpBuildingRole *, struct CBuilding *, int))(*(_DWORD *)v13 + 88))(v13, a2, 1);
  }
  v12 = *((_BYTE *)v13 + 4);
  if ( v12 == 1 )
  {
    result = (*(int (__thiscall **)(CWorkUpBuildingRole *, struct CBuilding *))(*(_DWORD *)v13 + 120))(v13, a2);
    if ( (_BYTE)result != 0 )
    {
      *((_BYTE *)v13 + 4) = 3;
      return result;
    }
    return ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(31);
  }
  if ( v12 == 2 )
  {
    if ( *((unsigned __int8 *)v13 + 5) > (int)*(unsigned __int8 *)(*((_DWORD *)v13 + 94) + 480) )
    {
      *((_BYTE *)v13 + 5) = 0;
      *((_BYTE *)v13 + 4) = 3;
      return ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(1);
    }
    else
    {
      ++*((_BYTE *)v13 + 5);
      return ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(14);
    }
  }
  if ( v12 != 3 )
  {
    return result;
  }
  if ( *((_BYTE *)v13 + 29) == 0 )
  {
    return ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(31);
  }
  if ( IEntity::FlagBits(a2, (EntityFlag)4096) == 0 )
  {
    return ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(31);
  }
  v10 = (unsigned __int8 *)CPileMgr::operator[](*((unsigned __int16 *)v13 + 191));
  if ( (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v10 + 40))(v10) >= 8 || !CWorkUpBuildingRole::HaveMaterial(v13, a2) )
  {
    return ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(31);
  }
  v11 = 0;
  if ( *std::vector<unsigned char>::operator[](0) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\WorkUpBuilding.cpp", 365, "m_pBuildingInfo->vAnimListId[ iWorkList ] != 0") == 1 )
  {
    __debugbreak();
  }
  v3 = (unsigned __int16 *)CSettlerMgr::operator[](*((unsigned __int16 *)v13 + 4));
  if ( IEntity::Type((IEntity *)v3) == 21 )
  {
    v6 = 6;
    if ( *((unsigned __int8 *)v13 + 380) >= 5u )
    {
      *((_BYTE *)v13 + 380) = 0;
    }
    else
    {
      v11 = 1;
      ++*((_BYTE *)v13 + 380);
    }
  }
  v9 = CSettlerMgr::operator[](*((unsigned __int16 *)v13 + 4));
  v4 = std::vector<unsigned char>::operator[](v11);
  v8 = CEntityEvent::CEntityEvent(&v5, 3u, 0, 0, *v4, 0);
  v7 = v8;
  v14 = 0;
  v9->SetEvent(v9, v8);
  v14 = -1;
  CEntityEvent::~CEntityEvent(&v5);
  return (*(int (__thiscall **)(CWorkUpBuildingRole *, struct CBuilding *, int))(*(_DWORD *)v13 + 72))(v13, a2, 1);
}


// address=[0x152f610]
// Decompiled from unsigned int __thiscall CWorkUpBuildingRole::FillGfxInfo(CWorkUpBuildingRole *this, struct CBuilding *a2, struct SGfxObjectInfo *a3)
void  CWorkUpBuildingRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
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
  int v14; // [esp-Ch] [ebp-2F0h]
  unsigned int i; // [esp+4h] [ebp-2E0h]
  int v16; // [esp+8h] [ebp-2DCh]
  _DWORD v18[180]; // [esp+10h] [ebp-2D4h] BYREF

  (*(void (__thiscall **)(CWorkUpBuildingRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v14 = IEntity::Type(a2);
  v3 = IEntity::Race(a2);
  ((void (__stdcall *)(int, int, int, int, int))CGfxManager::GetBuildingGfxInfo)((int)a3, v3, v14, 1, (int)this + 76);
  v4 = IEntity::OwnerId(a2);
  a3->m_iColor = CPlayerManager::Color(v4);
  if ( *((_BYTE *)this + 356) != 0 )
  {
    CGfxManager::GetEffectGfxInfo(g_pGfxManager, (struct SGfxObjectInfo *)v18, *((unsigned __int8 *)this + 356), 0, *((unsigned __int8 *)this + 359));
    *(_DWORD *)&a3->gap_60[8] = v18[0];
    *(_DWORD *)&a3->gap_60[12] = v18[1];
    *(_DWORD *)&a3->gap_60[16] = *((__int16 *)this + 180);
    *(_DWORD *)&a3->gap_60[20] = *((__int16 *)this + 181);
  }
  v5 = IEntity::OwnerId(a2);
  IBuildingRole::MiniFlag((IBuildingRole *)this, a3, v5);
  if ( *((_BYTE *)this + 29) == 1 )
  {
    v6 = CSettlerMgr::operator[](*((unsigned __int16 *)this + 4));
    CSettler::GetPatchGfx(v6, a3->m_vPatches);
  }
  v16 = 0;
  v7 = (unsigned __int8 *)CPileMgr::operator[](*((unsigned __int16 *)this + 191));
  if ( CPile::IsPatchPile(v7) )
  {
    v8 = (unsigned __int8 *)CPileMgr::operator[](*((unsigned __int16 *)this + 191));
    CPile::GetPatchGfx((CPile *)v8, a3->m_vPatches2);
    v16 = 1;
  }
  for ( i = 0;
        ;
        ++i )
  {
    result = std::vector<unsigned short>::size((char *)this + 384);
    if ( i >= result )
    {
      break;
    }
    v10 = std::vector<unsigned short>::operator[]((char *)this + 384, i);
    v11 = (unsigned __int8 *)CPileMgr::operator[](*v10);
    if ( CPile::IsPatchPile(v11) )
    {
      v12 = std::vector<unsigned short>::operator[]((char *)this + 384, i);
      v13 = (unsigned __int8 *)CPileMgr::operator[](*v12);
      CPile::GetPatchGfx((CPile *)v13, &a3->m_vPatches2[v16++]);
    }
  }
  return result;
}


// address=[0x152f8e0]
// Decompiled from int __thiscall CWorkUpBuildingRole::Init(CWorkUpBuildingRole *this, struct CBuilding *a2)
void  CWorkUpBuildingRole::Init(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // eax
  int v9; // [esp-4h] [ebp-20h]
  int v10; // [esp+0h] [ebp-1Ch]
  char v11; // [esp+8h] [ebp-14h]
  int v12; // [esp+Ch] [ebp-10h]
  int i; // [esp+10h] [ebp-Ch]
  __int16 v15; // [esp+1Ah] [ebp-2h] BYREF

  IBuildingRole::InitCommon(a2);
  *((_BYTE *)this + 380) = 0;
  *((_WORD *)this + 191) = 0;
  ((void (__cdecl *)())std::vector<unsigned short>::clear)();
  for ( i = 0;
        i < *(char *)(*((_DWORD *)this + 94) + 57);
        ++i )
  {
    v2 = ((int (__stdcall *)())IEntity::WorldIdx)();
    v10 = *(char *)(*((_DWORD *)this + 94) + 16 * i + 60) + CWorldManager::X(v2);
    v3 = ((int (__stdcall *)())IEntity::WorldIdx)();
    v4 = CWorldManager::Y(v3);
    v12 = CPileMgr::AddPile(&g_cPileMgr, v10, *(char *)(*((_DWORD *)this + 94) + 16 * i + 61) + v4, *(char *)(*((_DWORD *)this + 94) + 16 * i + 62), 0, *(char *)(*((_DWORD *)this + 94) + 16 * i + 63), *(char *)(*((_DWORD *)this + 94) + 16 * i + 64), *(char *)(*((_DWORD *)this + 94) + 16 * i + 65), *(_DWORD *)(*((_DWORD *)this + 94) + 16 * i + 68), *(_DWORD *)(*((_DWORD *)this + 94) + 16 * i + 72));
    v9 = ((int (__stdcall *)())IEntity::ID)();
    v5 = (unsigned __int8 *)CPileMgr::operator[](v12);
    CPile::SetBuildingId((CPile *)v5, v9);
    if ( *(_BYTE *)(*((_DWORD *)this + 94) + 16 * i + 65) == 1 )
    {
      v6 = (unsigned __int8 *)CPileMgr::operator[](v12);
      IEntity::ClearFlagBits((IEntity *)v6, ENTITY_FLAG_Visible);
    }
    v11 = *(_BYTE *)(*((_DWORD *)this + 94) + 16 * i + 63);
    if ( v11 != 0 )
    {
      if ( v11 == 1 )
      {
        v15 = v12;
        ((void (__stdcall *)(__int16 *))std::vector<unsigned short>::push_back)(&v15);
      }
    }
    else
    {
      if ( *((_WORD *)this + 191) != 0 )
      {
        v7 = IEntity::Type(a2);
        if ( BBSupportDbgReportF(2, "MapObjects\\Building\\WorkUpBuilding.cpp", 195, "More than one production pile at %s", (&off_379821C)[2 * v7]) == 1 )
        {
          __debugbreak();
        }
      }
      *((_WORD *)this + 191) = v12;
    }
  }
  if ( std::vector<unsigned short>::size((char *)this + 384) == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\WorkUpBuilding.cpp", 215, "m_vDeliverPileId.size()>0") == 1 )
  {
    __debugbreak();
  }
  *((_BYTE *)this + 4) = 1;
  if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selected) != 0 )
  {
    (*(void (__thiscall **)(CWorkUpBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 88))(this, a2, 0);
  }
  return ((int (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(2);
}


// address=[0x152fb80]
// Decompiled from int __thiscall CWorkUpBuildingRole::PostLoadInit(CWorkUpBuildingRole *this, struct CBuilding *a2)
void  CWorkUpBuildingRole::PostLoadInit(class CBuilding * a2) {
  
  int result; // eax
  int v3; // eax
  int v4; // [esp-4h] [ebp-8h]

  if ( a2 == 0 && BBSupportDbgReport(2, "MapObjects\\Building\\WorkUpBuilding.cpp", 139, "_pBuilding!= NULL") == 1 )
  {
    __debugbreak();
  }
  result = 0;
  if ( a2 != 0 )
  {
    v4 = IEntity::Type(a2);
    v3 = IEntity::Race(a2);
    result = (int)CBuildingInfoMgr::GetBuildingInfo(v3, v4);
    *((_DWORD *)this + 94) = result;
  }
  return result;
}


// address=[0x152fbe0]
// Decompiled from char __thiscall CWorkUpBuildingRole::SettlerEnter(_DWORD *this, unsigned __int8 *a2, int a3)
bool  CWorkUpBuildingRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  float v7; // xmm0_4
  int v8; // eax
  struct type_info *v9; // eax
  int v10; // eax
  const char *BuildingName; // eax
  const char *v13; // [esp+0h] [ebp-58h]
  const char *RaceName; // [esp+4h] [ebp-54h]
  int v15[6]; // [esp+Ch] [ebp-4Ch] BYREF
  float v16; // [esp+24h] [ebp-34h]
  float v17; // [esp+28h] [ebp-30h]
  int v18; // [esp+2Ch] [ebp-2Ch]
  int v19; // [esp+30h] [ebp-28h]
  int v20; // [esp+34h] [ebp-24h]
  int *v21; // [esp+38h] [ebp-20h]
  int v22; // [esp+3Ch] [ebp-1Ch]
  CMFCToolBarButton *v23; // [esp+40h] [ebp-18h]
  CSettler *v24; // [esp+44h] [ebp-14h]
  _DWORD *v25; // [esp+48h] [ebp-10h]
  int v26; // [esp+54h] [ebp-4h]

  v25 = this;
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\WorkUpBuilding.cpp", 240, "_iSettlerId > 0") == 1 )
  {
    __debugbreak();
  }
  v24 = CSettlerMgr::operator[](a3);
  if ( IEntity::FlagBits(v24, ENTITY_FLAG_Visible) != 0 && BBSupportDbgReport(2, "MapObjects\\Building\\WorkUpBuilding.cpp", 243, "rSettler.FlagBits(ENTITY_FLAG_VISIBLE)==0") == 1 )
  {
    __debugbreak();
  }
  if ( *((_BYTE *)v25 + 29) != 0 )
  {
    if ( *((unsigned __int16 *)v25 + 4) != a3 && BBSupportDbgReport(2, "MapObjects\\Building\\WorkUpBuilding.cpp", 266, "m_uSettlerId == _iSettlerId") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    *((_BYTE *)v25 + 29) = 1;
    *((_WORD *)v25 + 4) = a3;
    if ( IEntity::FlagBits((IEntity *)a2, (EntityFlag)4096) != 0 )
    {
      CEntityEvent::CEntityEvent((CEntityEvent *)v15, 8u, 0, *((unsigned __int16 *)v25 + 3), 0, 0);
      v26 = 0;
      v21 = v15;
      (*(void (__thiscall **)(unsigned __int8 *, int *))(*(_DWORD *)a2 + 124))(a2, v15);
      v26 = -1;
      CEntityEvent::~CEntityEvent(v15);
    }
  }
  IEntity::ClearFlagBits(v24, ENTITY_FLAG_Visible);
  IEntity::SetFlagBits(v24, ENTITY_FLAG_MagicInvisible);
  ((void (__stdcall *)(char))IMovingEntity::SetDisplacementCosts)(10);
  v23 = (CMFCToolBarButton *)((CMFCToolBarButton *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)v25 + 3));
  v3 = CBuilding::DoorPackedXY((CBuilding *)v23);
  v20 = Y16X16::UnpackXFast(v3);
  v4 = CBuilding::DoorPackedXY((CBuilding *)v23);
  v19 = Y16X16::UnpackYFast(v4);
  v5 = IEntity::X(v23);
  v18 = v20 - v5;
  v6 = IEntity::Y(v23);
  v22 = v19 - v6;
  v16 = (float)((float)v18 + (float)((float)((float)(v19 - v6) * -1.0) / 2.0)) * 24.0;
  v7 = (float)((float)(v19 - v6) * 24.0) / 2.0;
  v17 = v7;
  CSettler::SetOffset(v24, v16, v7);
  if ( *(_BYTE *)(v25[94] + 480) != 0 )
  {
    *((_BYTE *)v25 + 5) = 0;
    ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(14);
    *((_BYTE *)v25 + 4) = 2;
  }
  else
  {
    ((void (__stdcall *)(int))IAnimatedEntity::RegisterForLogicUpdate)(31);
    v8 = IEntity::Race(a2);
    RaceName = CS4DefineNames::GetRaceName(v8);
    v9 = typeid(v25);
    v13 = type_info::name(v9);
    v10 = CBuilding::BuildingTypeEx((struct CBuilding *)a2);
    BuildingName = CS4DefineNames::GetBuildingName(v10);
    BBSupportTracePrintF(2, "WARNING: Building %s (role %s) of race %s has no production delay!", BuildingName, v13, RaceName);
  }
  (*(void (__cdecl **)(unsigned __int8 *))(*v25 + 72))(a2);
  return 1;
}


// address=[0x152feb0]
// Decompiled from int __thiscall CWorkUpBuildingRole::GetBuildingNeed(CWorkUpBuildingRole *this, int a2)
int  CWorkUpBuildingRole::GetBuildingNeed(int a2)const {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned int i; // [esp+8h] [ebp-4h]

  for ( i = 0;
        i < std::vector<unsigned short>::size((char *)this + 384);
        ++i )
  {
    v2 = (unsigned __int16 *)((unsigned __int16 *(__stdcall *)(unsigned int))std::vector<unsigned short>::operator[])(i);
    v3 = (unsigned __int8 *)CPileMgr::operator[](*v2);
    if ( (*(int (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)v3 + 60))(v3, v3) == a2 )
    {
      return *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(unsigned int))std::vector<unsigned short>::operator[])(i);
    }
  }
  BBSupportTracePrintF(0, "TROUBLE: illegal goodcheck good %u", a2);
  return 0;
}


// address=[0x152ff50]
// Decompiled from int __thiscall CWorkUpBuildingRole::GetPileIdWithGood(CWorkUpBuildingRole *this, int a2)
int  CWorkUpBuildingRole::GetPileIdWithGood(int a2)const {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v4; // eax
  unsigned __int16 *v5; // eax
  int v6; // eax
  const char *v7; // [esp-4h] [ebp-14h]
  unsigned __int8 *v8; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-8h]

  for ( i = 0;
        i < std::vector<unsigned short>::size((char *)this + 384);
        ++i )
  {
    v2 = (unsigned __int16 *)((unsigned __int16 *(__stdcall *)(unsigned int))std::vector<unsigned short>::operator[])(i);
    v8 = (unsigned __int8 *)CPileMgr::operator[](*v2);
    if ( (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v8 + 60))(v8) == a2 )
    {
      return *(unsigned __int16 *)((unsigned __int16 *(__stdcall *)(unsigned int))std::vector<unsigned short>::operator[])(i);
    }
  }
  v4 = (unsigned __int8 *)CPileMgr::operator[](*((unsigned __int16 *)this + 191));
  if ( (*(int (__thiscall **)(unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)v4 + 60))(v4, v4) == a2 )
  {
    return *((unsigned __int16 *)this + 191);
  }
  v7 = (&off_3797E74)[2 * a2];
  v5 = (unsigned __int16 *)((unsigned __int16 *(__stdcall *)(_DWORD))CBuildingMgr::operator[])(*((unsigned __int16 *)this + 3));
  v6 = IEntity::Type((IEntity *)v5);
  if ( BBSupportDbgReportF(2, "MapObjects\\Building\\WorkUpBuilding.cpp", 534, "Illegal goodcheck: buildingtype: %s, goodtype: %s", (&off_379821C)[2 * v6], v7) == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x1530070]
// Decompiled from void __thiscall CWorkUpBuildingRole::GoodArrive(CWorkUpBuildingRole *this, int a2)
void  CWorkUpBuildingRole::GoodArrive(int a2) {
  
  ;
}


// address=[0x1530080]
// Decompiled from unsigned int __thiscall CWorkUpBuildingRole::LockPiles(CWorkUpBuildingRole *this, struct CBuilding *a2, bool a3)
void  CWorkUpBuildingRole::LockPiles(class CBuilding * a2, bool a3) {
  
  unsigned int result; // eax
  unsigned __int16 *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned int i; // [esp+4h] [ebp-4h]

  for ( i = 0;
        ;
        ++i )
  {
    result = std::vector<unsigned short>::size((char *)this + 384);
    if ( i >= result )
    {
      break;
    }
    v4 = std::vector<unsigned short>::operator[]((char *)this + 384, i);
    v5 = (unsigned __int8 *)CPileMgr::operator[](*v4);
    if ( a3 )
    {
      IEntity::SetFlagBits(v5, (EntityFlag)16);
    }
    else
    {
      IEntity::ClearFlagBits((IEntity *)v5, (EntityFlag)16);
    }
  }
  return result;
}


// address=[0x1530120]
// Decompiled from char *__thiscall CWorkUpBuildingRole::CWorkUpBuildingRole(char *this, int a2)
 CWorkUpBuildingRole::CWorkUpBuildingRole(std::istream & a2) {
  
  unsigned int v3; // [esp+4h] [ebp-34h] BYREF
  unsigned int v4; // [esp+8h] [ebp-30h] BYREF
  unsigned int v5; // [esp+Ch] [ebp-2Ch] BYREF
  int pExceptionObject; // [esp+10h] [ebp-28h] BYREF
  unsigned int v7; // [esp+14h] [ebp-24h]
  unsigned int j; // [esp+18h] [ebp-20h]
  unsigned int i; // [esp+1Ch] [ebp-1Ch]
  char *v10; // [esp+20h] [ebp-18h]
  char v11[4]; // [esp+24h] [ebp-14h] BYREF
  char v12[4]; // [esp+28h] [ebp-10h] BYREF
  int v13; // [esp+34h] [ebp-4h]

  v10 = this;
  IBuildingRole::IBuildingRole((IBuildingRole *)this, (struct std::istream *)a2);
  v13 = 0;
  *(_DWORD *)v10 = &CWorkUpBuildingRole::_vftable_;
  std::vector<unsigned short>::vector<unsigned short>(v10 + 384);
  LOBYTE(v13) = 1;
  operator^<unsigned int>(a2, &v5);
  v7 = v5;
  if ( v5 == 1 )
  {
    v10[380] = 0;
    operator^<unsigned short>(a2, (unsigned __int16 *)v10 + 191);
    operator^<unsigned int>(a2, &v4);
    for ( i = 0;
          i < v4;
          ++i )
    {
      operator^<unsigned short>(a2, (unsigned __int16 *)v12);
      ((void (__stdcall *)(char *))std::vector<unsigned short>::push_back)(v12);
    }
  }
  else
  {
    if ( v7 != 2 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CWorkUpBuildingRole");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    operator^<unsigned char>(a2, (unsigned __int8 *)v10 + 380);
    operator^<unsigned short>(a2, (unsigned __int16 *)v10 + 191);
    operator^<unsigned int>(a2, &v3);
    for ( j = 0;
          j < v3;
          ++j )
    {
      operator^<unsigned short>(a2, (unsigned __int16 *)v11);
      ((void (__stdcall *)(char *))std::vector<unsigned short>::push_back)(v11);
    }
  }
  return v10;
}


// address=[0x15302d0]
// Decompiled from int __thiscall CWorkUpBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CWorkUpBuildingRole::Store(std::ostream & a2) {
  
  int result; // eax
  __int16 *v3; // eax
  int v4; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+4h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-8h]
  struct IBuildingRole *v7; // [esp+Ch] [ebp-4h]

  v7 = this;
  IBuildingRole::Store(this, a2);
  v4 = 2;
  operator^<unsigned int>(a2, (unsigned int *)&v4);
  operator^<unsigned char>(a2, (unsigned __int8 *)&v7[1]);
  operator^<unsigned short>(a2, (WORD *)&v7[1].__vftable + 1);
  v5 = std::vector<unsigned short>::size(&v7[1].m_uLogicState);
  result = operator^<unsigned int>(a2, (unsigned int *)&v5);
  for ( i = 0;
        i < v5;
        ++i )
  {
    v3 = (__int16 *)std::vector<unsigned short>::operator[](&v7[1].m_uLogicState, i);
    operator^<unsigned short>(a2, (WORD *)v3);
    result = i + 1;
  }
  return result;
}


// address=[0x3d8b830]
// [Decompilation failed for static unsigned long CWorkUpBuildingRole::m_iClassID]

// address=[0x14e67a0]
// Decompiled from void __thiscall CWorkUpBuildingRole::ConvertEventIntoGoal(CWorkUpBuildingRole *this, struct CBuilding *a2, struct CEntityEvent *a3)
void  CWorkUpBuildingRole::ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3) {
  
  ;
}


// address=[0x14e68f0]
// Decompiled from char __thiscall CWorkUpBuildingRole::TryCrushBuilding(CWorkUpBuildingRole *this)
bool  CWorkUpBuildingRole::TryCrushBuilding(void) {
  
  return 1;
}


// address=[0x1530390]
// Decompiled from char __thiscall CWorkUpBuildingRole::CrushBuilding(CWorkUpBuildingRole *this)
bool  CWorkUpBuildingRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x15303a0]
// Decompiled from char __thiscall CWorkUpBuildingRole::HaveMaterial(CWorkUpBuildingRole *this, struct CBuilding *a2)
bool  CWorkUpBuildingRole::HaveMaterial(class CBuilding * a2) {
  
  unsigned __int16 *v2; // eax
  unsigned __int8 *v3; // eax
  unsigned int i; // [esp+4h] [ebp-8h]
  char v7; // [esp+Bh] [ebp-1h]

  v7 = 1;
  for ( i = 0;
        i < std::vector<unsigned short>::size((char *)this + 384);
        ++i )
  {
    v2 = std::vector<unsigned short>::operator[]((char *)this + 384, i);
    v3 = (unsigned __int8 *)CPileMgr::operator[](*v2);
    if ( !CPile::GoodAvailable((CPile *)v3) )
    {
      v7 = 0;
    }
  }
  return v7;
}


// address=[0x1530410]
// Decompiled from _DWORD *__thiscall CWorkUpBuildingRole::FillDialog(CWorkUpBuildingRole *this, struct CBuilding *a2, bool a3)
void  CWorkUpBuildingRole::FillDialog(class CBuilding * a2, bool a3) {
  
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

  CInfoExchange::Clear((CInfoExchange *)&g_cResourceUpgradeInfo);
  dword_3F1E500 = 3;
  byte_3F1E505 = IEntity::Race(a2);
  byte_3F1E504 = IEntity::Type(a2);
  byte_3F1E507 = 1;
  byte_3F1E508 = IEntity::FlagBits(a2, (EntityFlag)4096) != 0;
  byte_3F1E509 = 0;
  v9 = IEntity::Type(a2);
  v3 = IEntity::OwnerId(a2);
  byte_3F1E50B = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, (S4_BUILDING_ENUM)v9, 0);
  v10 = IEntity::Type(a2);
  v4 = IEntity::OwnerId(a2);
  byte_3F1E50C = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, (S4_BUILDING_ENUM)v10, 1u);
  byte_3F1E50A = -1;
  byte_3F1E506 = *((_BYTE *)this + 29);
  if ( *((_BYTE *)this + 29) != 0 )
  {
    byte_3F1E50D = *(_BYTE *)(*((_DWORD *)this + 94) + 478);
  }
  for ( i = 0;
        i < std::vector<unsigned short>::size((char *)this + 384);
        ++i )
  {
    v5 = std::vector<unsigned short>::operator[]((char *)this + 384, i);
    v14 = (unsigned __int8 *)CPileMgr::operator[](*v5);
    byte_3F1E511[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v14 + 40))(v14);
    v6 = std::vector<unsigned short>::operator[]((char *)this + 384, i);
    v13 = (unsigned __int8 *)CPileMgr::operator[](*v6);
    byte_3F1E510[2 * i] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v13 + 60))(v13);
  }
  if ( *((_WORD *)this + 191) != 0 )
  {
    v12 = (unsigned __int8 *)CPileMgr::operator[](*((unsigned __int16 *)this + 191));
    byte_3F1E51B[0] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v12 + 40))(v12);
    v7 = (unsigned __int8 *)CPileMgr::operator[](*((unsigned __int16 *)this + 191));
    byte_3F1E51A[0] = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v7 + 60))(v7);
  }
  v11 = 604;
  if ( !a3 )
  {
    v11 = 602;
  }
  CEvn_Event::CEvn_Event(&v17, v11, 0, (unsigned int)&g_cResourceUpgradeInfo, 0);
  v18 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v17);
  v18 = -1;
  return CEvn_Event::~CEvn_Event(&v17);
}


