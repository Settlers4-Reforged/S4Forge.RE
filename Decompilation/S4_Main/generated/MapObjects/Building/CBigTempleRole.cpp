#include "CBigTempleRole.h"

// Definitions for class CBigTempleRole

// address=[0x13ffbe0]
// Decompiled from CBigTempleRole *__cdecl CBigTempleRole::New(int a1)
class CPersistence * __cdecl CBigTempleRole::New(std::istream & a1) {
  
  CBigTempleRole *C; // [esp+Ch] [ebp-10h]

  C = (CBigTempleRole *)operator new(0x180u);
  if ( C )
    return CBigTempleRole::CBigTempleRole(C, a1);
  else
    return 0;
}


// address=[0x14e8200]
// Decompiled from void __thiscall CBigTempleRole::LogicUpdate(CBigTempleRole *this, struct CBuilding *a2)
void  CBigTempleRole::LogicUpdate(class CBuilding * a2) {
  
  unsigned int v2; // eax
  struct type_info *v3; // eax
  unsigned int v4; // eax
  const char *BuildingName; // eax
  const char *v6; // [esp-8h] [ebp-10h]
  const char *RaceName; // [esp-4h] [ebp-Ch]
  unsigned __int8 uLogicState; // [esp+0h] [ebp-8h]

  if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selected) )
    this->FillDialog(this, a2, 1);
  uLogicState = this->m_uLogicState;
  if ( uLogicState == 2 )
  {
    if ( this->m_iDelayTick > (int)this->m_pBuildingInfo->m_iProductionDelay )
    {
      this->m_iDelayTick = 0;
      this->m_uLogicState = 3;
      IAnimatedEntity::RegisterForLogicUpdate(a2, 1);
    }
    else
    {
      ++this->m_iDelayTick;
      IAnimatedEntity::RegisterForLogicUpdate(a2, 14);
    }
  }
  else if ( uLogicState == 3 )
  {
    if ( IEntity::FlagBits(a2, (EntityFlag)4096) )
      CBigTempleRole::ThrowOutPriest(a2);
    if ( this->m_uThrownOutPriests < 10u )
    {
      if ( this->m_pBuildingInfo->m_iProductionDelay )
      {
        this->m_iDelayTick = 0;
        IAnimatedEntity::RegisterForLogicUpdate(a2, 14);
        this->m_uLogicState = 2;
      }
      else
      {
        IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
        v2 = IEntity::Race(a2);
        RaceName = CS4DefineNames::GetRaceName(v2);
        v3 = typeid(this);
        v6 = type_info::name(v3);
        v4 = CBuilding::BuildingTypeEx(a2);
        BuildingName = CS4DefineNames::GetBuildingName(v4);
        BBSupportTracePrintF(
          2,
          "WARNING: Building %s (role %s) of race %s has no production delay!",
          BuildingName,
          v6,
          RaceName);
      }
    }
  }
}


// address=[0x14e8350]
// Decompiled from void __thiscall CBigTempleRole::FillGfxInfo(CBigTempleRole *this, IEntity *a2, struct SGfxObjectInfo *a3)
void  CBigTempleRole::FillGfxInfo(class CBuilding * a2, struct SGfxObjectInfo & a3) {
  
  unsigned int v3; // eax
  unsigned int v4; // [esp-Ch] [ebp-10h]

  this->Update(this, a2);
  v4 = IEntity::Type(a2);
  v3 = IEntity::Race(a2);
  CGfxManager::GetBuildingGfxInfo(g_pGfxManager, a3, v3, v4, 1, (int)this->m_vPatchPairs);
}


// address=[0x14e83a0]
// Decompiled from int __thiscall CBigTempleRole::Init(CBigTempleRole *this, struct CBuilding *a2)
void  CBigTempleRole::Init(class CBuilding * a2) {
  
  int v2; // eax

  IBuildingRole::InitCommon(a2);
  this->m_uLogicState = 3;
  v2 = IEntity::OwnerId(a2);
  CMagic::IncreaseManaByBigTemple(v2);
  if ( IEntity::FlagBits(a2, ENTITY_FLAG_Selected) )
    this->FillDialog(this, a2, 0);
  return IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
}


// address=[0x14e8400]
// Decompiled from void __thiscall CBigTempleRole::PostLoadInit(CBigTempleRole *this, IEntity *a2)
void  CBigTempleRole::PostLoadInit(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  v3 = IEntity::Type(a2);
  v2 = IEntity::Race(a2);
  this->m_pBuildingInfo = CBuildingInfoMgr::GetBuildingInfo(v2, v3);
}


// address=[0x14e8430]
// Decompiled from _DWORD *__thiscall CBigTempleRole::FillDialog(CBigTempleRole *this, IEntity *a2, bool a3)
void  CBigTempleRole::FillDialog(class CBuilding * a2, bool a3) {
  
  int ownerId; // eax MAPDST
  S4_BUILDING_ENUM type; // [esp-8h] [ebp-3Ch] MAPDST
  unsigned int v9; // [esp+8h] [ebp-2Ch]
  CEvn_Event v10; // [esp+Ch] [ebp-28h] BYREF
  int v11; // [esp+30h] [ebp-4h]

  g_cBuildingInfo.m_iUnknown = 0;
  g_cBuildingInfo.m_cRace = IEntity::Race(a2);
  g_cBuildingInfo.m_cType = IEntity::Type(a2);
  g_cBuildingInfo.m_bSomeFlagBits = 1;
  g_cBuildingInfo.m_unknownB = 0;
  g_cBuildingInfo.m_bHasWorkingArea = 0;
  type = IEntity::Type(a2);
  ownerId = IEntity::OwnerId(a2);
  g_cBuildingInfo.m_cTotalCount = CBuildingMgr::GetNumberOfBuildings((CBuildingMgr *)g_cBuildingMgr, ownerId, type, 0);
  type = IEntity::Type(a2);
  ownerId = IEntity::OwnerId(a2);
  g_cBuildingInfo.m_cTotalBuiltCount = CBuildingMgr::GetNumberOfBuildings(
                                         (CBuildingMgr *)g_cBuildingMgr,
                                         ownerId,
                                         type,
                                         1u);
  g_cBuildingInfo.m_bInhabitants = this->m_bInhabitants;
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
// Decompiled from CBigTempleRole *__thiscall CBigTempleRole::CBigTempleRole(CBigTempleRole *this, struct std::istream *a2)
 CBigTempleRole::CBigTempleRole(std::istream & a2) {
  
  unsigned int iFileVersion; // [esp+4h] [ebp-1Ch] MAPDST BYREF
  int pExceptionObject; // [esp+8h] [ebp-18h] BYREF
  int v7; // [esp+1Ch] [ebp-4h]

  IBuildingRole::IBuildingRole(this, a2);
  v7 = 0;
  this->__vftable = (IBuildingRole_vtbl *)&CBigTempleRole::_vftable_;
  operator^<unsigned int>(a2, &iFileVersion);
  if ( iFileVersion == 1 )
  {
    this->m_uThrownOutPriests = 0;
  }
  else
  {
    if ( iFileVersion != 2 )
    {
      BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBigTempleRole");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    operator^<unsigned char>(a2, &this->m_uThrownOutPriests);
  }
  return this;
}


// address=[0x14e8630]
// Decompiled from void __thiscall CBigTempleRole::Store(CBigTempleRole *this, struct std::ostream *_rStream)
void  CBigTempleRole::Store(std::ostream & _rStream) {
  
  unsigned int v2; // [esp+0h] [ebp-8h] BYREF

  IBuildingRole::Store(this, _rStream);
  v2 = 2;
  operator^<unsigned int>(_rStream, &v2);
  operator^<unsigned char>(_rStream, &this->m_uThrownOutPriests);
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
  this->__vftable = (IBuildingRole_vtbl *)&CBigTempleRole::_vftable_;
  this->m_uThrownOutPriests = 0;
  return this;
}


// address=[0x14fd870]
// Decompiled from int __cdecl CBigTempleRole::Load(struct std::istream *a1)
class CBigTempleRole * __cdecl CBigTempleRole::Load(std::istream & a1) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New(a1);
  return j____RTDynamicCast(v1, 0, &CPersistence__RTTI_Type_Descriptor_, &CBigTempleRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8b08c]
// [Decompilation failed for static unsigned long CBigTempleRole::m_iClassID]

// address=[0x14e8680]
// Decompiled from void __thiscall CBigTempleRole::ThrowOutPriest(CBigTempleRole *this, CBuilding *a2)
void  CBigTempleRole::ThrowOutPriest(class CBuilding * a2) {
  
  int v2; // eax
  int v3; // eax
  int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // [esp-14h] [ebp-18h]
  int v7; // [esp-10h] [ebp-14h]
  int m_iBuildingInhabitant; // [esp-Ch] [ebp-10h]

  v2 = CBuilding::DoorWorldIdx(a2);
  if ( CWorldManager::IsPositionFreeForSettler(v2) )
  {
    m_iBuildingInhabitant = (char)this->m_pBuildingInfo->m_iBuildingInhabitant;
    v7 = IEntity::OwnerId(a2);
    v3 = CBuilding::DoorPackedXY(a2);
    v6 = Y16X16::UnpackYFast(v3);
    v4 = CBuilding::DoorPackedXY(a2);
    v5 = Y16X16::UnpackXFast(v4);
    CSettlerMgr::AddSettlers(&g_cSettlerMgr, v5, v6, v7, m_iBuildingInhabitant, 1, 2);
    ++this->m_uThrownOutPriests;
  }
}


// address=[0x14e88f0]
// Decompiled from void __thiscall CBigTempleRole::ConvertEventIntoGoal(  CBigTempleRole *this,  struct CBuilding *a2,  struct CEntityEvent *a3)
void  CBigTempleRole::ConvertEventIntoGoal(class CBuilding * a2, class CEntityEvent * a3) {
  
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


