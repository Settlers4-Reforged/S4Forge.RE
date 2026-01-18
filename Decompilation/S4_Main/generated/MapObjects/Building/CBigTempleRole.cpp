#include "CBigTempleRole.h"

// Definitions for class CBigTempleRole

// address=[0x13ffbe0]
// Decompiled from int __cdecl CBigTempleRole::New(int a1)
class CPersistence * __cdecl CBigTempleRole::New(std::istream & a1) {
  
  if ( operator new(0x180u) )
    return CBigTempleRole::CBigTempleRole(a1);
  else
    return 0;
}


// address=[0x14e8200]
// Decompiled from int __thiscall CBigTempleRole::LogicUpdate(int this, CMFCToolBarButton *a2)
void  CBigTempleRole::LogicUpdate(class CBuilding * a2) {
  
  int result; // eax
  int v3; // eax
  void *v4; // eax
  int v5; // eax
  const char *BuildingName; // eax
  const char *v7; // [esp-8h] [ebp-10h]
  const char *RaceName; // [esp-4h] [ebp-Ch]
  char v9; // [esp+0h] [ebp-8h]

  result = IEntity::FlagBits(a2, Selected);
  if ( result )
    result = (*(int (__thiscall **)(int, CMFCToolBarButton *, int))(*(_DWORD *)this + 88))(this, a2, 1);
  v9 = *(_BYTE *)(this + 4);
  if ( v9 == 2 )
  {
    if ( *(unsigned __int8 *)(this + 5) > (int)*(unsigned __int8 *)(*(_DWORD *)(this + 376) + 480) )
    {
      *(_BYTE *)(this + 5) = 0;
      *(_BYTE *)(this + 4) = 3;
      return IAnimatedEntity::RegisterForLogicUpdate(1);
    }
    else
    {
      ++*(_BYTE *)(this + 5);
      return IAnimatedEntity::RegisterForLogicUpdate(14);
    }
  }
  else if ( v9 == 3 )
  {
    if ( IEntity::FlagBits(a2, (EntityFlag)0x1000u) )
      CBigTempleRole::ThrowOutPriest(a2);
    result = this;
    if ( *(unsigned __int8 *)(this + 380) < 0xAu )
    {
      if ( *(_BYTE *)(*(_DWORD *)(this + 376) + 480) )
      {
        *(_BYTE *)(this + 5) = 0;
        IAnimatedEntity::RegisterForLogicUpdate(14);
        result = this;
        *(_BYTE *)(this + 4) = 2;
      }
      else
      {
        IAnimatedEntity::RegisterForLogicUpdate(31);
        v3 = IEntity::Race(a2);
        RaceName = CS4DefineNames::GetRaceName(v3);
        v4 = (void *)typeid((_DWORD *)this);
        v7 = (const char *)type_info::name(v4);
        v5 = CBuilding::BuildingTypeEx((unsigned __int8 *)a2);
        BuildingName = CS4DefineNames::GetBuildingName(v5);
        return BBSupportTracePrintF(
                 2,
                 "WARNING: Building %s (role %s) of race %s has no production delay!",
                 BuildingName,
                 v7,
                 RaceName);
      }
    }
  }
  return result;
}


// address=[0x14e8350]
// Decompiled from int __thiscall CBigTempleRole::FillGfxInfo(CBigTempleRole *this, struct CBuilding *a2, struct SGfxObjectInfo *a3)
void  CBigTempleRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  int v3; // eax
  int v5; // [esp-Ch] [ebp-10h]

  (*(void (__thiscall **)(CBigTempleRole *, struct CBuilding *))(*(_DWORD *)this + 16))(this, a2);
  v5 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::Race(a2);
  return CGfxManager::GetBuildingGfxInfo((int)a3, v3, v5, 1, (int)this + 76);
}


// address=[0x14e83a0]
// Decompiled from int __thiscall CBigTempleRole::Init(CBigTempleRole *this, struct CBuilding *a2)
void  CBigTempleRole::Init(class CBuilding * a2) {
  
  int v2; // eax

  IBuildingRole::InitCommon((int)a2);
  *((_BYTE *)this + 4) = 3;
  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  CMagic::IncreaseManaByBigTemple(v2);
  if ( IEntity::FlagBits(a2, Selected) )
    (*(void (__thiscall **)(CBigTempleRole *, struct CBuilding *, _DWORD))(*(_DWORD *)this + 88))(this, a2, 0);
  return IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x14e8400]
// Decompiled from int __thiscall CBigTempleRole::PostLoadInit(CBigTempleRole *this, struct CBuilding *a2)
void  CBigTempleRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-8h]

  v4 = IEntity::Type((unsigned __int16 *)a2);
  v2 = IEntity::Race(a2);
  result = CBuildingInfoMgr::GetBuildingInfo(v2, v4);
  *((_DWORD *)this + 94) = result;
  return result;
}


// address=[0x14e8430]
// Decompiled from _DWORD *__thiscall CBigTempleRole::FillDialog(CBigTempleRole *this, struct CBuilding *a2, bool a3)
void  CBigTempleRole::FillDialog(class CBuilding * a2, bool a3) {
  
  int v3; // eax
  int v4; // eax
  int v6; // [esp-8h] [ebp-3Ch]
  int v7; // [esp-8h] [ebp-3Ch]
  unsigned int v9; // [esp+8h] [ebp-2Ch]
  CEvn_Event v10; // [esp+Ch] [ebp-28h] BYREF
  int v11; // [esp+30h] [ebp-4h]

  dword_3F1E4B0 = 0;
  byte_3F1E4B5 = IEntity::Race(a2);
  byte_3F1E4B4 = IEntity::Type((unsigned __int16 *)a2);
  byte_3F1E4B8 = 1;
  byte_3F1E4B7 = 0;
  byte_3F1E4B9 = 0;
  v6 = IEntity::Type((unsigned __int16 *)a2);
  v3 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4BB = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v3, v6, 0);
  v7 = IEntity::Type((unsigned __int16 *)a2);
  v4 = IEntity::OwnerId((unsigned __int8 *)a2);
  byte_3F1E4BC = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, v4, v7, 1u);
  byte_3F1E4B6 = *((_BYTE *)this + 29);
  v9 = 604;
  if ( !a3 )
    v9 = 602;
  CEvn_Event::CEvn_Event(&v10, v9, 0, (unsigned int)&g_cBuildingInfo, 0);
  v11 = 0;
  IEventEngine::SendAMessage(g_pEvnEngine, &v10);
  v11 = -1;
  return CEvn_Event::~CEvn_Event(&v10);
}


// address=[0x14e8560]
// Decompiled from char *__thiscall CBigTempleRole::CBigTempleRole(char *this, int a2)
 CBigTempleRole::CBigTempleRole(std::istream & a2) {
  
  int v3; // [esp+4h] [ebp-1Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-18h] BYREF
  int v5; // [esp+Ch] [ebp-14h]
  char *v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-4h]

  v6 = this;
  IBuildingRole::IBuildingRole(this, a2);
  v7 = 0;
  *(_DWORD *)v6 = &CBigTempleRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  v5 = v3;
  if ( v3 == 1 )
  {
    v6[380] = 0;
  }
  else
  {
    if ( v5 != 2 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBigTempleRole");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    operator^<unsigned char>(a2, v6 + 380);
  }
  return v6;
}


// address=[0x14e8630]
// Decompiled from int __thiscall CBigTempleRole::Store(struct IBuildingRole *this, struct std::ostream *a2)
void  CBigTempleRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct IBuildingRole *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  IBuildingRole::Store(this, a2);
  v3 = 2;
  operator^<unsigned int>(a2, &v3);
  return operator^<unsigned char>(a2, (int)v4 + 380);
}


// address=[0x14e8850]
// Decompiled from int __thiscall CBigTempleRole::~CBigTempleRole(CBigTempleRole *this)
 CBigTempleRole::~CBigTempleRole(void) {
  
  return IBuildingRole::~IBuildingRole(this);
}


// address=[0x14e88d0]
// Decompiled from int __thiscall CBigTempleRole::ClassID(CBigTempleRole *this)
unsigned long  CBigTempleRole::ClassID(void)const {
  
  return CBigTempleRole::m_iClassID;
}


// address=[0x14e8930]
// Decompiled from void *__thiscall CBigTempleRole::GetBuildingNeed(std::_Ref_count_base *this, const struct type_info *a2)
int  CBigTempleRole::GetBuildingNeed(int a2)const {
  
  return 0;
}


// address=[0x14e8950]
// Decompiled from int __thiscall CBigTempleRole::GetBuildingRole(CBigTempleRole *this)
int  CBigTempleRole::GetBuildingRole(void) {
  
  return 17;
}


// address=[0x14e8970]
// Decompiled from void *__thiscall CBigTempleRole::GetPileIdWithGood(std::_Ref_count_base *this, const struct type_info *a2)
int  CBigTempleRole::GetPileIdWithGood(int a2)const {
  
  return 0;
}


// address=[0x14e8990]
// Decompiled from void __thiscall CBigTempleRole::GoodArrive(CBigTempleRole *this, int a2)
void  CBigTempleRole::GoodArrive(int a2) {
  
  ;
}


// address=[0x14fc8d0]
// Decompiled from CBigTempleRole *__thiscall CBigTempleRole::CBigTempleRole(CBigTempleRole *this)
 CBigTempleRole::CBigTempleRole(void) {
  
  IBuildingRole::IBuildingRole(this);
  *(_DWORD *)this = &CBigTempleRole::_vftable_;
  *((_BYTE *)this + 380) = 0;
  return this;
}


// address=[0x14fd870]
// Decompiled from int __cdecl CBigTempleRole::Load(int a1)
class CBigTempleRole * __cdecl CBigTempleRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CBigTempleRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8b08c]
// [Decompilation failed for static unsigned long CBigTempleRole::m_iClassID]

// address=[0x14e8680]
// Decompiled from BOOL __thiscall CBigTempleRole::ThrowOutPriest(int this, CMFCToolBarButton *a2)
void  CBigTempleRole::ThrowOutPriest(class CBuilding * a2) {
  
  int v2; // eax
  BOOL result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // [esp-14h] [ebp-18h]
  int v8; // [esp-10h] [ebp-14h]
  int v9; // [esp-Ch] [ebp-10h]

  v2 = CBuilding::DoorWorldIdx(a2);
  result = CWorldManager::IsPositionFreeForSettler(v2);
  if ( !result )
    return result;
  v9 = *(char *)(*(_DWORD *)(this + 376) + 478);
  v8 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CBuilding::DoorPackedXY(a2);
  v7 = Y16X16::UnpackYFast(v4);
  v5 = CBuilding::DoorPackedXY(a2);
  v6 = Y16X16::UnpackXFast(v5);
  CSettlerMgr::AddSettlers((CSettlerMgr *)g_cSettlerMgr, v6, v7, v8, v9, 1, 2);
  result = this;
  ++*(_BYTE *)(this + 380);
  return result;
}


// address=[0x14e88f0]
// Decompiled from void __thiscall CBigTempleRole::ConvertEventIntoGoal(  CBigTempleRole *this,  struct CBuilding *a2,  struct CEntityEvent *a3)
void  CBigTempleRole::ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *) {
  
  ;
}


// address=[0x14e8900]
// Decompiled from char __thiscall CBigTempleRole::CrushBuilding(CBigTempleRole *this)
bool  CBigTempleRole::CrushBuilding(void) {
  
  return 1;
}


// address=[0x14e89a0]
// Decompiled from char __thiscall CBigTempleRole::TryCrushBuilding(CBigTempleRole *this)
bool  CBigTempleRole::TryCrushBuilding(void) {
  
  return 1;
}


