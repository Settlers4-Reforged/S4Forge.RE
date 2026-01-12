#include "CSmallTempleRole.h"

// Definitions for class CSmallTempleRole

// address=[0x1401ee0]
// Decompiled from int __cdecl CSmallTempleRole::New(int a1)
static class CPersistence * __cdecl CSmallTempleRole::New(std::istream &) {
  
  if ( operator new(0x184u) )
    return CSmallTempleRole::CSmallTempleRole(a1);
  else
    return 0;
}


// address=[0x14fcb40]
// Decompiled from CSmallTempleRole *__thiscall CSmallTempleRole::CSmallTempleRole(CSmallTempleRole *this)
 CSmallTempleRole::CSmallTempleRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CSmallTempleRole::_vftable_;
  return this;
}


// address=[0x14fcd40]
// Decompiled from int __thiscall CSmallTempleRole::~CSmallTempleRole(CSmallTempleRole *this)
 CSmallTempleRole::~CSmallTempleRole(void) {
  
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14fd1a0]
// Decompiled from int __thiscall CSmallTempleRole::ClassID(CSmallTempleRole *this)
unsigned long  CSmallTempleRole::ClassID(void)const {
  
  return CSmallTempleRole::m_iClassID;
}


// address=[0x14fd420]
// Decompiled from void *__thiscall CSmallTempleRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)
int  CSmallTempleRole::GetBuildingNeed(int)const {
  
  return 0;
}


// address=[0x14fd580]
// Decompiled from int __thiscall CSmallTempleRole::GetBuildingRole(CSmallTempleRole *this)
int  CSmallTempleRole::GetBuildingRole(void) {
  
  return 16;
}


// address=[0x14fd6c0]
// Decompiled from int __thiscall CSmallTempleRole::GetPileIdWithGood(CSmallTempleRole *this, int a2)
int  CSmallTempleRole::GetPileIdWithGood(int)const {
  
  return *((unsigned __int16 *)this + 190);
}


// address=[0x14fd760]
// Decompiled from void __thiscall CSmallTempleRole::GoodArrive(CSmallTempleRole *this, int a2)
void  CSmallTempleRole::GoodArrive(int) {
  
  ;
}


// address=[0x14fdc30]
// Decompiled from int __cdecl CSmallTempleRole::Load(int a1)
static class CSmallTempleRole * __cdecl CSmallTempleRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CSmallTempleRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x151bf20]
// Decompiled from int __thiscall CSmallTempleRole::LogicUpdate(CSmallTempleRole *this, struct CBuilding *a2)
void  CSmallTempleRole::LogicUpdate(class CBuilding *) {
  
  int result; // eax
  unsigned __int8 *v3; // eax
  _BYTE v4[24]; // [esp+4h] [ebp-38h] BYREF
  CEntityEvent *v5; // [esp+1Ch] [ebp-20h]
  CEntityEvent *v6; // [esp+20h] [ebp-1Ch]
  int v7; // [esp+24h] [ebp-18h]
  char v8; // [esp+28h] [ebp-14h]
  CSmallTempleRole *v9; // [esp+2Ch] [ebp-10h]
  int v10; // [esp+38h] [ebp-4h]

  v9 = this;
  result = IEntity::FlagBits(a2, Selected);
  if ( result )
    result = (*(int (__thiscall **)(CSmallTempleRole *, struct CBuilding *, int))(*(_DWORD *)v9 + 88))(v9, a2, 1);
  v8 = *((_BYTE *)v9 + 4);
  if ( v8 == 1 )
  {
    result = (*(int (__thiscall **)(CSmallTempleRole *, struct CBuilding *))(*(_DWORD *)v9 + 120))(v9, a2);
    if ( !(_BYTE)result )
      return IAnimatedEntity::RegisterForLogicUpdate(31);
    *((_BYTE *)v9 + 4) = 3;
    return result;
  }
  if ( v8 == 2 )
  {
    if ( *((unsigned __int8 *)v9 + 5) > (int)*(unsigned __int8 *)(*((_DWORD *)v9 + 94) + 480) )
    {
      *((_BYTE *)v9 + 5) = 0;
      *((_BYTE *)v9 + 4) = 3;
      return IAnimatedEntity::RegisterForLogicUpdate(1);
    }
    else
    {
      ++*((_BYTE *)v9 + 5);
      return IAnimatedEntity::RegisterForLogicUpdate(14);
    }
  }
  if ( v8 != 3 )
    return result;
  if ( !*((_BYTE *)v9 + 29) || !IEntity::FlagBits(a2, (EntityFlag)0x1000u) || !CSmallTempleRole::HaveMaterial(v9, a2) )
    return IAnimatedEntity::RegisterForLogicUpdate(31);
  if ( !*(_BYTE *)std::vector<unsigned char>::operator[](0)
    && BBSupportDbgReport(2, "MapObjects\\Building\\SmallTemple.cpp", 300, "m_pBuildingInfo->vAnimListId[ 0 ] != 0") == 1 )
  {
    __debugbreak();
  }
  v7 = CSettlerMgr::operator[](*((unsigned __int16 *)v9 + 4));
  v3 = (unsigned __int8 *)std::vector<unsigned char>::operator[](0);
  v6 = CEntityEvent::CEntityEvent((CEntityEvent *)v4, 3u, 0, 0, *v3, 0);
  v5 = v6;
  v10 = 0;
  (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v7 + 80))(v7, v6);
  v10 = -1;
  CEntityEvent::~CEntityEvent(v4);
  return (*(int (__thiscall **)(CSmallTempleRole *, struct CBuilding *, int))(*(_DWORD *)v9 + 72))(v9, a2, 1);
}


// address=[0x151c130]
// Decompiled from CPile *__thiscall CSmallTempleRole::FillGfxInfo(  CSmallTempleRole *this,  struct CBuilding *a2,  struct SGfxObjectInfo *a3)
void  CSmallTempleRole::FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  CSettler *v6; // eax
  unsigned __int8 *v7; // eax
  CPile *result; // eax
  unsigned __int8 *v9; // eax
  int v10; // [esp-Ch] [ebp-2E8h]
  _DWORD v12[180]; // [esp+8h] [ebp-2D4h] BYREF

  (*(void (__thiscall **)(CSmallTempleRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v10 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo((int)a3, v3, v10, 1, (int)this + 76);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  *((_BYTE *)a3 + 715) = CPlayerManager::Color(v4);
  if ( *((_BYTE *)this + 356) )
  {
    CGfxManager::GetEffectGfxInfo(
      (CGfxManager *)g_pGfxManager,
      (struct SGfxObjectInfo *)v12,
      *((unsigned __int8 *)this + 356),
      0,
      *((unsigned __int8 *)this + 359));
    *((_DWORD *)a3 + 26) = v12[0];
    *((_DWORD *)a3 + 27) = v12[1];
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
  v7 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  result = (CPile *)CPile::IsPatchPile(v7);
  if ( !(_BYTE)result )
    return result;
  v9 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  return CPile::GetPatchGfx((CPile *)v9, (struct SGfxObjectInfo *)((char *)a3 + 536));
}


// address=[0x151c320]
// Decompiled from int __thiscall CSmallTempleRole::Init(CSmallTempleRole *this, struct CBuilding *a2)
void  CSmallTempleRole::Init(class CBuilding *) {
  
  int v2; // eax
  int v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  int result; // eax
  int v7; // [esp-4h] [ebp-1Ch]
  int v8; // [esp+0h] [ebp-18h]
  int v9; // [esp+4h] [ebp-14h]
  char v10; // [esp+8h] [ebp-10h]
  int v11; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]

  IBuildingRole::InitCommon((int)a2);
  *((_DWORD *)this + 96) = 0;
  *((_BYTE *)this + 4) = 1;
  *((_WORD *)this + 190) = 0;
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
      IEntity::ClearFlagBits(v5, Visible);
    }
    v10 = *(_BYTE *)(*((_DWORD *)this + 94) + 16 * i + 63);
    if ( v10 )
    {
      if ( v10 == 1 )
      {
        if ( *((_WORD *)this + 190) )
        {
          if ( BBSupportDbgReport(2, "MapObjects\\Building\\SmallTemple.cpp", 153, "m_uDeliverPileId == 0") == 1 )
            __debugbreak();
        }
        *((_WORD *)this + 190) = v11;
      }
    }
    else if ( BBSupportDbgReport(2, "MapObjects\\Building\\SmallTemple.cpp", 147, "1 == 0") == 1 )
    {
      __debugbreak();
    }
  }
  if ( !*((_WORD *)this + 190)
    && BBSupportDbgReport(2, "MapObjects\\Building\\SmallTemple.cpp", 163, "m_uDeliverPileId != 0") == 1 )
  {
    __debugbreak();
  }
  (*(void (__thiscall **)(CSmallTempleRole *, struct CBuilding *))(*(_DWORD *)this + 120))(this, a2);
  result = IEntity::FlagBits(a2, Selected);
  if ( result )
    return (*(int (__thiscall **)(CSmallTempleRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 88))(this, a2, 0);
  return result;
}


// address=[0x151c5b0]
// Decompiled from int __thiscall CSmallTempleRole::PostLoadInit(CSmallTempleRole *this, struct CBuilding *a2)
void  CSmallTempleRole::PostLoadInit(class CBuilding *) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  result = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  *((_DWORD *)this + 94) = result;
  return result;
}


// address=[0x151c5e0]
// Decompiled from char __thiscall CSmallTempleRole::SettlerEnter(CSmallTempleRole *this, struct CBuilding *a2, int a3)
bool  CSmallTempleRole::SettlerEnter(class CBuilding *,int) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  float v8; // xmm0_4
  int v9; // eax
  void *v10; // eax
  int v11; // eax
  const char *BuildingName; // eax
  const char *v14; // [esp+8h] [ebp-58h]
  const char *RaceName; // [esp+Ch] [ebp-54h]
  _BYTE v16[24]; // [esp+14h] [ebp-4Ch] BYREF
  float v17; // [esp+2Ch] [ebp-34h]
  float v18; // [esp+30h] [ebp-30h]
  int v19; // [esp+34h] [ebp-2Ch]
  int v20; // [esp+38h] [ebp-28h]
  int v21; // [esp+3Ch] [ebp-24h]
  _BYTE *v22; // [esp+40h] [ebp-20h]
  int v23; // [esp+44h] [ebp-1Ch]
  CSettler *v24; // [esp+48h] [ebp-18h]
  CMFCToolBarButton *v25; // [esp+4Ch] [ebp-14h]
  _DWORD *v26; // [esp+50h] [ebp-10h]
  int v27; // [esp+5Ch] [ebp-4h]

  v26 = this;
  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\SmallTemple.cpp", 182, "_iSettlerId > 0") == 1 )
    __debugbreak();
  v24 = (CSettler *)CSettlerMgr::operator[](a3);
  (*(void (__thiscall **)(_DWORD *, struct CBuilding *, _DWORD))(*v26 + 72))(v26, a2, 0);
  if ( *((_BYTE *)v26 + 29) )
  {
    if ( *((unsigned __int16 *)v26 + 4) != a3
      && BBSupportDbgReport(2, "MapObjects\\Building\\SmallTemple.cpp", 213, "m_uSettlerId == _iSettlerId") == 1 )
    {
      __debugbreak();
    }
    v3 = IEntity::OwnerId((unsigned __int8 *)a2);
    CMagic::IncreaseManaByDonation(v3);
  }
  else
  {
    *((_BYTE *)v26 + 29) = 1;
    *((_WORD *)v26 + 4) = a3;
    if ( IEntity::FlagBits(a2, (EntityFlag)0x1000u) )
    {
      CEntityEvent::CEntityEvent((CEntityEvent *)v16, 8u, 0, *((unsigned __int16 *)v26 + 3), 0, 0);
      v27 = 0;
      v22 = v16;
      (*(void (__thiscall **)(struct CBuilding *, _BYTE *))(*(_DWORD *)a2 + 124))(a2, v16);
      v27 = -1;
      CEntityEvent::~CEntityEvent(v16);
    }
  }
  IEntity::ClearFlagBits(v24, Visible);
  IEntity::SetFlagBits(v24, MagicInvisible);
  IMovingEntity::SetDisplacementCosts(10);
  v25 = (CMFCToolBarButton *)CBuildingMgr::operator[](*((unsigned __int16 *)v26 + 3));
  v4 = CBuilding::DoorPackedXY(v25);
  v21 = Y16X16::UnpackXFast(v4);
  v5 = CBuilding::DoorPackedXY(v25);
  v20 = Y16X16::UnpackYFast(v5);
  v6 = IEntity::X(v25);
  v19 = v21 - v6;
  v7 = IEntity::Y(v25);
  v23 = v20 - v7;
  v17 = (float)((float)v19 + (float)((float)((float)(v20 - v7) * -1.0) / 2.0)) * 24.0;
  v8 = (float)((float)(v20 - v7) * 24.0) / 2.0;
  v18 = v8;
  CSettler::SetOffset(v24, v17, v8);
  if ( *(_BYTE *)(v26[94] + 480) )
  {
    *((_BYTE *)v26 + 5) = 0;
    IAnimatedEntity::RegisterForLogicUpdate(14);
    *((_BYTE *)v26 + 4) = 2;
  }
  else
  {
    IAnimatedEntity::RegisterForLogicUpdate(31);
    v9 = IEntity::Race(a2);
    RaceName = CS4DefineNames::GetRaceName(v9);
    v10 = (void *)j____RTtypeid(v26);
    v14 = (const char *)type_info::name(v10);
    v11 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
    BuildingName = CS4DefineNames::GetBuildingName(v11);
    BBSupportTracePrintF(
      2,
      "WARNING: Building %s (role %s) of race %s has no production delay!",
      BuildingName,
      v14,
      RaceName);
  }
  return 1;
}


// address=[0x151c890]
// Decompiled from _DWORD *__thiscall CSmallTempleRole::FillDialog(CSmallTempleRole *this, struct CBuilding *a2, bool a3)
void  CSmallTempleRole::FillDialog(class CBuilding *,bool) {
  
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v7; // [esp-8h] [ebp-48h]
  int v8; // [esp-8h] [ebp-48h]
  unsigned int v9; // [esp+4h] [ebp-3Ch]
  unsigned __int8 *v10; // [esp+8h] [ebp-38h]
  unsigned __int8 *v11; // [esp+Ch] [ebp-34h]
  CEvn_Event v13; // [esp+18h] [ebp-28h] BYREF
  int v14; // [esp+3Ch] [ebp-4h]

  dword_3F1E5CC = 8;
  byte_3F1E5D1 = IEntity::Race(a2);
  byte_3F1E5D0 = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E5D3 = 1;
  byte_3F1E5D4 = IEntity::FlagBits(a2, (EntityFlag)0x1000u) != 0;
  byte_3F1E5D5 = *(_DWORD *)(*((_DWORD *)this + 94) + 492) > 0;
  v7 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E5D7 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v7, 0);
  v8 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E5D8 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v8, 1u);
  byte_3F1E5D2 = *((_BYTE *)this + 29);
  v11 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  byte_3F1E5DD = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v11 + 40))(v11);
  v10 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  byte_3F1E5DC = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v10 + 60))(v10);
  v5 = IEntity::OwnerId((unsigned __int8 *)a2);
  dword_3F1E5E0 = CMagic::GetCurrentManaAmount(v5);
  if ( *((_BYTE *)this + 29) )
    byte_3F1E5D9 = *(_BYTE *)(*((_DWORD *)this + 94) + 478);
  v9 = 604;
  if ( !a3 )
    v9 = 602;
  CEvn_Event::CEvn_Event(&v13, v9, 0, (unsigned int)&g_cSmallTempleInfo, 0);
  v14 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v13);
  v14 = -1;
  return CEvn_Event::~CEvn_Event(&v13);
}


// address=[0x151ca80]
// Decompiled from _DWORD *__thiscall CSmallTempleRole::LockPiles(CSmallTempleRole *this, struct CBuilding *a2, bool a3)
void  CSmallTempleRole::LockPiles(class CBuilding *,bool) {
  
  unsigned __int8 *v3; // eax

  if ( !*((_WORD *)this + 190)
    && BBSupportDbgReport(2, "MapObjects\\Building\\SmallTemple.cpp", 488, "m_uDeliverPileId") == 1 )
  {
    __debugbreak();
  }
  v3 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  if ( a3 )
    return IEntity::SetFlagBits(v3, (EntityFlag)0x10u);
  else
    return (_DWORD *)IEntity::ClearFlagBits(v3, (EntityFlag)0x10u);
}


// address=[0x151cb10]
// Decompiled from char *__thiscall CSmallTempleRole::CSmallTempleRole(char *this, int a2)
 CSmallTempleRole::CSmallTempleRole(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CSmallTempleRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CSmallTempleRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned short>(a2, v5 + 380);
  operator^<unsigned int>(a2, v5 + 384);
  v6 = -1;
  return v5;
}


// address=[0x151cbf0]
// Decompiled from int __thiscall CSmallTempleRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CSmallTempleRole::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct IBuildingRole *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IBuildingRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<unsigned short>((int)a2, (__int16 *)v4 + 190);
  return operator^<unsigned int>(a2, (int *)v4 + 96);
}


// address=[0x3d8b79c]
// [Decompilation failed for static unsigned long CSmallTempleRole::m_iClassID]

// address=[0x14fd260]
// Decompiled from void __thiscall CSmallTempleRole::ConvertEventIntoGoal(  CSmallTempleRole *this,  struct CBuilding *a2,  struct CEntityEvent *a3)
void  CSmallTempleRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
  ;
}


// address=[0x14fd2c0]
// Decompiled from char __thiscall CSmallTempleRole::CrushBuilding(CSmallTempleRole *this)
bool  CSmallTempleRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x14fde90]
// Decompiled from char __thiscall CSmallTempleRole::TryCrushBuilding(CSmallTempleRole *this)
bool  CSmallTempleRole::TryCrushBuilding(void) {
  
  return 1;
}


// address=[0x151cc50]
// Decompiled from bool __thiscall CSmallTempleRole::HaveMaterial(CSmallTempleRole *this, struct CBuilding *a2)
bool  CSmallTempleRole::HaveMaterial(class CBuilding *) {
  
  unsigned __int8 *v2; // eax

  v2 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  return (*(int (__thiscall **)(unsigned __int8 *, CSmallTempleRole *, unsigned __int8 *))(*(_DWORD *)v2 + 40))(
           v2,
           this,
           v2) != 0;
}


