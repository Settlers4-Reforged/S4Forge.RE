#include "CFarmBuildingRole.h"

// Definitions for class CFarmBuildingRole

// address=[0x1400900]
// Decompiled from int __cdecl CFarmBuildingRole::New(int a1)
class CPersistence * __cdecl CFarmBuildingRole::New(std::istream & a1) {
  
  if ( operator new(0x180u) )
    return CFarmBuildingRole::CFarmBuildingRole(a1);
  else
    return 0;
}


// address=[0x14fc9a0]
// Decompiled from CFarmBuildingRole *__thiscall CFarmBuildingRole::CFarmBuildingRole(CFarmBuildingRole *this)
 CFarmBuildingRole::CFarmBuildingRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CFarmBuildingRole::_vftable_;
  return this;
}


// address=[0x14fcc10]
// Decompiled from int __thiscall CFarmBuildingRole::~CFarmBuildingRole(CFarmBuildingRole *this)
 CFarmBuildingRole::~CFarmBuildingRole(void) {
  
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14fd0c0]
// Decompiled from int __thiscall CFarmBuildingRole::ClassID(CFarmBuildingRole *this)
unsigned long  CFarmBuildingRole::ClassID(void)const {
  
  return CFarmBuildingRole::m_iClassID;
}


// address=[0x14fd360]
// Decompiled from void *__thiscall CFarmBuildingRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)
int  CFarmBuildingRole::GetBuildingNeed(int a2)const {
  
  return 0;
}


// address=[0x14fd4a0]
// Decompiled from int __thiscall CFarmBuildingRole::GetBuildingRole(CFarmBuildingRole *this)
int  CFarmBuildingRole::GetBuildingRole(void) {
  
  return 8;
}


// address=[0x14fd600]
// Decompiled from int __thiscall CFarmBuildingRole::GetPileIdWithGood(CFarmBuildingRole *this, int a2)
int  CFarmBuildingRole::GetPileIdWithGood(int a2)const {
  
  return *((unsigned __int16 *)this + 190);
}


// address=[0x14fd700]
// Decompiled from void __thiscall CFarmBuildingRole::GoodArrive(CFarmBuildingRole *this, int a2)
void  CFarmBuildingRole::GoodArrive(int a2) {
  
  ;
}


// address=[0x14fd9f0]
// Decompiled from int __cdecl CFarmBuildingRole::Load(int a1)
class CFarmBuildingRole * __cdecl CFarmBuildingRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CFarmBuildingRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x150a5e0]
// Decompiled from int __thiscall CFarmBuildingRole::LogicUpdate(CFarmBuildingRole *this, struct CBuilding *a2)
void  CFarmBuildingRole::LogicUpdate(class CBuilding * a2) {
  
  int result; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // esi
  int v7; // esi
  int v8; // eax
  int v9; // [esp-8h] [ebp-84h]
  int v10; // [esp-8h] [ebp-84h]
  int v11; // [esp-4h] [ebp-80h]
  char v12; // [esp-4h] [ebp-80h]
  _BYTE v13[24]; // [esp+8h] [ebp-74h] BYREF
  _BYTE v14[24]; // [esp+20h] [ebp-5Ch] BYREF
  CEntityEvent *v15; // [esp+38h] [ebp-44h]
  CEntityEvent *v16; // [esp+3Ch] [ebp-40h]
  CEntityEvent *v17; // [esp+40h] [ebp-3Ch]
  CEntityEvent *v18; // [esp+44h] [ebp-38h]
  int v19; // [esp+48h] [ebp-34h]
  unsigned int ObjectType; // [esp+4Ch] [ebp-30h]
  int v21; // [esp+50h] [ebp-2Ch]
  int v22; // [esp+54h] [ebp-28h]
  unsigned __int8 *v23; // [esp+58h] [ebp-24h]
  int SettlerInfo; // [esp+5Ch] [ebp-20h]
  _DWORD *v25; // [esp+60h] [ebp-1Ch]
  char v26; // [esp+64h] [ebp-18h]
  unsigned __int16 *v27; // [esp+68h] [ebp-14h]
  CFarmBuildingRole *v28; // [esp+6Ch] [ebp-10h]
  int v29; // [esp+78h] [ebp-4h]

  v28 = this;
  result = IEntity::FlagBits(a2, Selected);
  if ( result )
    result = (*(int (__thiscall **)(CFarmBuildingRole *, struct CBuilding *, int))(*(_DWORD *)v28 + 88))(v28, a2, 1);
  v26 = *((_BYTE *)v28 + 4);
  if ( v26 == 1 )
  {
    result = (*(unsigned __int8 (__thiscall **)(CFarmBuildingRole *, struct CBuilding *))(*(_DWORD *)v28 + 120))(
               v28,
               a2);
    if ( !(_BYTE)result )
      return IAnimatedEntity::RegisterForLogicUpdate(31);
    *((_BYTE *)v28 + 4) = 3;
    return result;
  }
  if ( v26 != 2 )
  {
    if ( v26 != 3 )
      return result;
    if ( !*((_BYTE *)v28 + 29) || !IEntity::FlagBits(a2, (EntityFlag)0x1000u) )
      return IAnimatedEntity::RegisterForLogicUpdate(31);
    v9 = *(char *)(*((_DWORD *)v28 + 94) + 478);
    v3 = IEntity::Race(a2);
    CSettlerMgr::GetSettlerInfo(v3, v9);
    *((_DWORD *)v28 + 8) = *(_DWORD *)std::vector<CSettlerMgr::SSearchInfos>::operator[](0);
    if ( !*((_DWORD *)v28 + 8)
      && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 268, "m_pSearchFkt != 0") == 1 )
    {
      __debugbreak();
    }
    v23 = CPileMgr::operator[](*((unsigned __int16 *)v28 + 190));
    if ( (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v23 + 40))(v23) < 8
      && (*(unsigned __int8 (__thiscall **)(CFarmBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)v28 + 104))(
           v28,
           a2,
           0) )
    {
      v25 = (_DWORD *)CSettlerMgr::operator[](*((unsigned __int16 *)v28 + 4));
      IEntity::SetFlagBits(v25, Visible);
      v18 = CEntityEvent::CEntityEvent(
              (CEntityEvent *)v14,
              5u,
              0,
              0,
              *((unsigned __int16 *)v28 + 6),
              *((_DWORD *)v28 + 4));
      v17 = v18;
      v29 = 0;
      (*(void (__thiscall **)(_DWORD *, CEntityEvent *))(*v25 + 80))(v25, v18);
      v29 = -1;
      CEntityEvent::~CEntityEvent(v14);
      return (*(int (__thiscall **)(CFarmBuildingRole *, struct CBuilding *, int))(*(_DWORD *)v28 + 72))(v28, a2, 1);
    }
    v10 = *(char *)(*((_DWORD *)v28 + 94) + 478);
    v4 = IEntity::Race(a2);
    CSettlerMgr::GetSettlerInfo(v4, v10);
    *((_DWORD *)v28 + 8) = *(_DWORD *)std::vector<CSettlerMgr::SSearchInfos>::operator[](1);
    if ( !*((_DWORD *)v28 + 8)
      && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 297, "m_pSearchFkt != 0") == 1 )
    {
      __debugbreak();
    }
    if ( !(*(unsigned __int8 (__thiscall **)(CFarmBuildingRole *, struct CBuilding *, int))(*(_DWORD *)v28 + 104))(
            v28,
            a2,
            1) )
      return IAnimatedEntity::RegisterForLogicUpdate(31);
    v27 = (unsigned __int16 *)CSettlerMgr::operator[](*((unsigned __int16 *)v28 + 4));
    v11 = IEntity::Type(v27);
    v5 = IEntity::Race(v27);
    SettlerInfo = CSettlerMgr::GetSettlerInfo(v5, v11);
    v6 = Y16X16::UnpackXFast(*((_DWORD *)v28 + 4));
    v21 = v6 - *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 5);
    v7 = Y16X16::UnpackYFast(*((_DWORD *)v28 + 4));
    v22 = v7 - *(char *)(std::vector<CSettlerMgr::SSearchInfos>::operator[](1) + 6);
    v12 = CWorldManager::Ground(v21, v22);
    v8 = IEntity::Race(v27);
    ObjectType = CDecoObjMgr::GetObjectType(
                   (CDecoObjMgr *)&g_cDecoObjMgr,
                   *(unsigned __int8 *)(SettlerInfo + 6),
                   v8,
                   v12);
    CDecoObjMgr::SetFlagsForObject((CDecoObjMgr *)&g_cDecoObjMgr, v21, v22, ObjectType, 0);
    IEntity::SetFlagBits(v27, Visible);
    v19 = CSettlerMgr::operator[](*((unsigned __int16 *)v28 + 4));
    v16 = CEntityEvent::CEntityEvent((CEntityEvent *)v13, 6u, 0, 0, ObjectType, *((_DWORD *)v28 + 4));
    v15 = v16;
    v29 = 1;
    (*(void (__thiscall **)(int, CEntityEvent *))(*(_DWORD *)v19 + 80))(v19, v16);
    v29 = -1;
    CEntityEvent::~CEntityEvent(v13);
    return (*(int (__thiscall **)(CFarmBuildingRole *, struct CBuilding *, int))(*(_DWORD *)v28 + 72))(v28, a2, 1);
  }
  if ( *((unsigned __int8 *)v28 + 5) > (int)*(unsigned __int8 *)(*((_DWORD *)v28 + 94) + 480) )
  {
    *((_BYTE *)v28 + 5) = 0;
    *((_BYTE *)v28 + 4) = 3;
    return IAnimatedEntity::RegisterForLogicUpdate(1);
  }
  else
  {
    ++*((_BYTE *)v28 + 5);
    return IAnimatedEntity::RegisterForLogicUpdate(14);
  }
}


// address=[0x150aa20]
// Decompiled from int __thiscall CFarmBuildingRole::FillGfxInfo(CFarmBuildingRole *this, struct CBuilding *a2, struct SGfxObjectInfo *a3)
void  CFarmBuildingRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  int v3; // eax
  int v4; // eax
  unsigned __int8 *v5; // eax
  int result; // eax
  unsigned __int8 *v7; // eax
  int v8; // [esp-Ch] [ebp-14h]

  (*(void (__thiscall **)(CFarmBuildingRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v8 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo((int)a3, v3, v8, 1, (int)this + 76);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  IBuildingRole::MiniFlag(this, a3, v4);
  v5 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  result = (unsigned __int8)CPile::IsPatchPile(v5);
  if ( !(_BYTE)result )
    return result;
  v7 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  CPile::GetPatchGfx((CPile *)v7, (struct SGfxObjectInfo *)((char *)a3 + 536));
  return 1;
}


// address=[0x150aae0]
// Decompiled from int __thiscall CFarmBuildingRole::Init(_BYTE *this, _BYTE *a2)
void  CFarmBuildingRole::Init(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // eax
  int v8; // eax
  int result; // eax
  int v10; // [esp-8h] [ebp-14h]
  int v11; // [esp-8h] [ebp-14h]
  int v12; // [esp-4h] [ebp-10h]
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+4h] [ebp-8h]

  IBuildingRole::InitCommon((int)a2);
  this[4] = 1;
  this[28] = 0;
  *((_WORD *)this + 190) = 0;
  if ( *(_BYTE *)(*((_DWORD *)this + 94) + 57) != 1
    && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 133, "m_pBuildingInfo->iPilesNumber == 1") == 1 )
  {
    __debugbreak();
  }
  v2 = IEntity::WorldIdx();
  v13 = *(char *)(*((_DWORD *)this + 94) + 60) + CWorldManager::X(v2);
  v3 = IEntity::WorldIdx();
  v14 = *(char *)(*((_DWORD *)this + 94) + 61) + CWorldManager::Y(v3);
  *((_WORD *)this + 190) = CPileMgr::AddPile(
                             (CPileMgr *)&g_cPileMgr,
                             v13,
                             v14,
                             *(char *)(*((_DWORD *)this + 94) + 62),
                             0,
                             *(char *)(*((_DWORD *)this + 94) + 63),
                             *(char *)(*((_DWORD *)this + 94) + 64),
                             *(char *)(*((_DWORD *)this + 94) + 65),
                             *(_DWORD *)(*((_DWORD *)this + 94) + 68),
                             *(_DWORD *)(*((_DWORD *)this + 94) + 72));
  if ( !*((_WORD *)this + 190)
    && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 150, "m_uProdPileId != 0") == 1 )
  {
    __debugbreak();
  }
  v12 = IEntity::ID();
  v4 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  CPile::SetBuildingId((CPile *)v4, v12);
  v5 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  if ( (unsigned __int8)CPile::IsPatchPile(v5) )
  {
    v6 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
    IEntity::ClearFlagBits(v6, Visible);
  }
  v10 = *(char *)(*((_DWORD *)this + 94) + 478);
  v7 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v7, v10);
  *((_DWORD *)this + 8) = *(_DWORD *)std::vector<CSettlerMgr::SSearchInfos>::operator[](0);
  if ( !*((_DWORD *)this + 8)
    && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 162, "m_pSearchFkt != 0") == 1 )
  {
    __debugbreak();
  }
  v11 = *(char *)(*((_DWORD *)this + 94) + 478);
  v8 = IEntity::Race(a2);
  CSettlerMgr::GetSettlerInfo(v8, v11);
  *((_DWORD *)this + 8) = *(_DWORD *)std::vector<CSettlerMgr::SSearchInfos>::operator[](1);
  if ( !*((_DWORD *)this + 8)
    && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 165, "m_pSearchFkt != 0") == 1 )
  {
    __debugbreak();
  }
  IAnimatedEntity::RegisterForLogicUpdate(2);
  result = IEntity::FlagBits(a2, Selected);
  if ( result )
    return (*(int (__thiscall **)(_BYTE *, _BYTE *, _DWORD))(*(_DWORD *)this + 88))(this, a2, 0);
  return result;
}


// address=[0x150add0]
// Decompiled from int __thiscall CFarmBuildingRole::PostLoadInit(_DWORD *this, unsigned __int16 *a2)
void  CFarmBuildingRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type(a2);
  v2 = IEntity::Race(a2);
  result = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  this[94] = result;
  return result;
}


// address=[0x150ae00]
// Decompiled from _DWORD *__thiscall CFarmBuildingRole::LockPiles(CFarmBuildingRole *this, struct CBuilding *a2, bool a3)
void  CFarmBuildingRole::LockPiles(class CBuilding * a2, bool a3) {
  
  unsigned __int8 *v3; // eax

  v3 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  if ( a3 )
    return IEntity::SetFlagBits(v3, (EntityFlag)0x10u);
  else
    return (_DWORD *)IEntity::ClearFlagBits(v3, (EntityFlag)0x10u);
}


// address=[0x150ae60]
// Decompiled from char __thiscall CFarmBuildingRole::SettlerEnter(CFarmBuildingRole *this, struct CBuilding *a2, int a3)
bool  CFarmBuildingRole::SettlerEnter(class CBuilding * a2, int a3) {
  
  int v3; // eax
  void *v4; // eax
  int v5; // eax
  const char *BuildingName; // eax
  const char *v8; // [esp-8h] [ebp-10h]
  const char *RaceName; // [esp-4h] [ebp-Ch]
  _DWORD *v10; // [esp+0h] [ebp-8h]

  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 185, "_iSettlerId > 0") == 1 )
    __debugbreak();
  v10 = (_DWORD *)CSettlerMgr::operator[](a3);
  if ( *((_BYTE *)this + 29) )
  {
    if ( *((unsigned __int16 *)this + 4) != a3
      && BBSupportDbgReport(2, "MapObjects\\Building\\FarmBuildingRole.cpp", 196, "m_uSettlerId == _iSettlerId") == 1 )
    {
      __debugbreak();
    }
  }
  else
  {
    *((_BYTE *)this + 29) = 1;
    *((_WORD *)this + 4) = a3;
  }
  IEntity::ClearFlagBits(v10, Visible);
  IMovingEntity::SetDisplacementCosts(10);
  if ( *(_BYTE *)(*((_DWORD *)this + 94) + 480) )
  {
    *((_BYTE *)this + 5) = 0;
    IAnimatedEntity::RegisterForLogicUpdate(14);
  }
  else
  {
    IAnimatedEntity::RegisterForLogicUpdate(31);
    v3 = IEntity::Race(a2);
    RaceName = CS4DefineNames::GetRaceName(v3);
    v4 = (void *)typeid(this);
    v8 = (const char *)type_info::name(v4);
    v5 = IEntity::Type((unsigned __int16 *)a2);
    BuildingName = CS4DefineNames::GetBuildingName(v5);
    BBSupportTracePrintF(
      2,
      "WARNING: Building %s (role %s) of race %s has no production delay!",
      BuildingName,
      v8,
      RaceName);
  }
  *((_BYTE *)this + 4) = 2;
  (*(void (__thiscall **)(CFarmBuildingRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 72))(this, a2, 0);
  return 1;
}


// address=[0x150afa0]
// Decompiled from _DWORD *__thiscall CFarmBuildingRole::FillDialog(CFarmBuildingRole *this, struct CBuilding *a2, bool a3)
void  CFarmBuildingRole::FillDialog(class CBuilding * a2, bool a3) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp-8h] [ebp-48h]
  int v7; // [esp-8h] [ebp-48h]
  unsigned int v8; // [esp+4h] [ebp-3Ch]
  unsigned __int8 *v9; // [esp+8h] [ebp-38h]
  unsigned __int8 *v10; // [esp+Ch] [ebp-34h]
  CEvn_Event v12; // [esp+18h] [ebp-28h] BYREF
  int v13; // [esp+3Ch] [ebp-4h]

  dword_3F1E4E8 = 2;
  byte_3F1E4ED = IEntity::Race(a2);
  byte_3F1E4EC = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E4EF = 1;
  byte_3F1E4F0 = IEntity::FlagBits(a2, (EntityFlag)0x1000u) != 0;
  byte_3F1E4F1 = 1;
  v6 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4F3 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v6, 0);
  v7 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4F4 = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v7, 1u);
  byte_3F1E4EE = *((_BYTE *)this + 29);
  if ( *((_BYTE *)this + 29) )
    byte_3F1E4F5 = *(_BYTE *)(*((_DWORD *)this + 94) + 478);
  v10 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  byte_3F1E4F9 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v10 + 40))(v10);
  v9 = CPileMgr::operator[](*((unsigned __int16 *)this + 190));
  byte_3F1E4F8 = (*(int (__thiscall **)(unsigned __int8 *))(*(_DWORD *)v9 + 60))(v9);
  v8 = 604;
  if ( !a3 )
    v8 = 602;
  CEvn_Event::CEvn_Event(&v12, v8, 0, (unsigned int)&g_cResourceCollectorInfo, 0);
  v13 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v12);
  v13 = -1;
  return CEvn_Event::~CEvn_Event(&v12);
}


// address=[0x150b160]
// Decompiled from char *__thiscall CFarmBuildingRole::CFarmBuildingRole(char *this, int a2)
 CFarmBuildingRole::CFarmBuildingRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CFarmBuildingRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CFarmBuildingRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned short>(a2, v5 + 380);
  v6 = -1;
  return v5;
}


// address=[0x150b220]
// Decompiled from int __thiscall CFarmBuildingRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CFarmBuildingRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct IBuildingRole *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IBuildingRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  return operator^<unsigned short>((int)a2, (__int16 *)v4 + 190);
}


// address=[0x3d8b130]
// [Decompilation failed for static unsigned long CFarmBuildingRole::m_iClassID]

// address=[0x14fd200]
// Decompiled from void __stdcall CFarmBuildingRole::ConvertEventIntoGoal(int a1, int a2)
void  CFarmBuildingRole::ConvertEventIntoGoal(class CBuilding * a1, class CEntityEvent * a2) {
  
  ;
}


// address=[0x14fd280]
// Decompiled from char __thiscall CFarmBuildingRole::CrushBuilding(CFarmBuildingRole *this)
bool  CFarmBuildingRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x14fde30]
// Decompiled from char __thiscall CFarmBuildingRole::TryCrushBuilding(CFarmBuildingRole *this)
bool  CFarmBuildingRole::TryCrushBuilding(void) {
  
  return 1;
}


