#include "CBuilderRole.h"

// Definitions for class CBuilderRole

// address=[0x13ffc80]
// Decompiled from int __cdecl CBuilderRole::New(int a1)
class CPersistence * __cdecl CBuilderRole::New(std::istream & a1) {
  
  if ( operator new(0x30u) )
  {
    return CBuilderRole::CBuilderRole(a1);
  }
  else
  {
    return 0;
  }
}


// address=[0x1562d90]
// Decompiled from CWalkingNormal *__thiscall CBuilderRole::InitWalking(CBuilderRole *this, IEntity *a2)
class CWalking *  CBuilderRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  CWalkingNormal *v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId(a2);
  v4 = CWalking::Create(1, v2);
  v4->InitB(v4, -1, 0);
  return v4;
}


// address=[0x1562dd0]
// Decompiled from void __fastcall CBuilderRole::LogicUpdateJob(CBuilderRole *this, int a2, struct CSettler *a3)
void  CBuilderRole::LogicUpdateJob(class CSettler * a2) {
  
  CBuilding *v3; // eax
  CBuildingSiteRole *v4; // [esp+0h] [ebp-Ch]
  CHAR iTask; // [esp+4h] [ebp-8h]

  iTask = this->m_iTask;
  if ( iTask == 6 )
  {
    IMovingEntity::SetDistance(a3, 0);
    this->Go(this, a3);
  }
  else if ( iTask == 16 && this->CheckHome(this, a3) )
  {
    this->m_uCycleFrames = IMovingEntity::GetActualTask(a3)->m_iFrameCount;
    IAnimatedEntity::RegisterForLogicUpdate(a3, this->m_uCycleFrames);
    this->m_uCycleFrames = 1;
    v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
    v4 = (CBuildingSiteRole *)CBuilding::Role(v3);
    if ( CBuildingSiteRole::HaveBuildingMaterial(v4) )
    {
      this->m_uCycleFrames = IMovingEntity::GetActualTask(a3)->m_iFrameCount;
      CBuildingSiteRole::AddWork(v4, this->m_uCycleFrames);
    }
    else
    {
      this->SetFree(this, a3, -1);
    }
  }
}


// address=[0x1562ec0]
// Decompiled from void __stdcall CBuilderRole::PostLoadInit(IEntity *a1)
void  CBuilderRole::PostLoadInit(class CSettler * a1) {
  
  CWarMap::AddEntity(a1);
}


// address=[0x1562ee0]
// Decompiled from char __thiscall CBuilderRole::SetFree(CBuilderRole *this, CSettler *_pSettler, int a3)
bool  CBuilderRole::SetFree(class CSettler * _pSettler, int a3) {
  
  int v3; // eax
  IBuildingRole *v4; // eax
  int v5; // eax
  CBuilding *v7; // [esp+0h] [ebp-14h]
  CBuildingSiteRole *v8; // [esp+8h] [ebp-Ch]
  bool bNeedsRest; // [esp+13h] [ebp-1h]

  if ( ISettlerRole::HomeEntityId(this) )
  {
    v3 = ISettlerRole::HomeEntityId(this);
    v7 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, v3);
    v4 = CBuilding::Role(v7);
    v8 = (CBuildingSiteRole *)j____RTDynamicCast((void **)&v4->__vftable, 0, &IBuildingRole__RTTI_Type_Descriptor_, &CBuildingSiteRole__RTTI_Type_Descriptor_, 0);
    if ( v8 )
    {
      v5 = IEntity::EntityId(_pSettler);
      CBuildingSiteRole::BuilderLeft(v8, v5);
    }
  }
  bNeedsRest = this->m_iNeedsRest;
  if ( ISettlerRole::SetFree(this, _pSettler, a3) )
  {
    return 1;
  }
  if ( bNeedsRest && this->SearchRestingPlace(this, _pSettler, 3) )
  {
    IAnimatedEntity::SetFrame(_pSettler, 1u);
    IMovingEntity::WalkToXY(_pSettler, this->m_iStartPosition, 0x2000);
    this->m_iTask = 6;
    IMovingEntity::SetDisplacementCosts(_pSettler, 5);
    return 0;
  }
  else
  {
    IAnimatedEntity::SetFrame(_pSettler, 1u);
    this->m_iTask = 17;
    return 0;
  }
}


// address=[0x1562ff0]
// Decompiled from CBuilderRole *__thiscall CBuilderRole::CBuilderRole(CBuilderRole *this, struct std::istream *a2)
 CBuilderRole::CBuilderRole(std::istream & a2) {
  
  unsigned int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v6; // [esp+1Ch] [ebp-4h]

  ISettlerRole::ISettlerRole(this, a2);
  v6 = 0;
  this->__vftable = (CBuilderRole_vtbl *)&CBuilderRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBuilderRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<signed char>(a2, &this->m_iDir);
  operator^<signed char>(a2, &this->m_iNeedsRest);
  v6 = -1;
  return this;
}


// address=[0x15630c0]
// Decompiled from void __thiscall CBuilderRole::Store(CBuilderRole *this, struct std::ostream *a2)
void  CBuilderRole::Store(std::ostream & a2) {
  
  unsigned int v2; // [esp+0h] [ebp-8h] BYREF

  ISettlerRole::Store(this, a2);
  v2 = 1;
  operator^<unsigned int>(a2, &v2);
  operator^<signed char>(a2, &this->m_iDir);
  operator^<signed char>(a2, &this->m_iNeedsRest);
}


// address=[0x15637b0]
// Decompiled from int __thiscall CBuilderRole::ClassID(CBuilderRole *this)
unsigned long  CBuilderRole::ClassID(void)const {
  
  return CBuilderRole::m_iClassID;
}


// address=[0x1563820]
// Decompiled from int __thiscall CBuilderRole::GetSettlerRole(CBuilderRole *this)
int  CBuilderRole::GetSettlerRole(void)const {
  
  return 3;
}


// address=[0x1563960]
// Decompiled from void __thiscall CBuilderRole::SetDir(CBuilderRole *this, char a2)
void  CBuilderRole::SetDir(char a2) {
  
  this->m_iDir = a2;
}


// address=[0x1588440]
// Decompiled from int __cdecl CBuilderRole::Load(int a1)
class CBuilderRole * __cdecl CBuilderRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CBuilderRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bea4]
// [Decompilation failed for static unsigned long CBuilderRole::m_iClassID]

// address=[0x1563120]
// Decompiled from CBuilderRole *__thiscall CBuilderRole::CBuilderRole(CBuilderRole *this)
 CBuilderRole::CBuilderRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  this->__vftable = (CBuilderRole_vtbl *)&CBuilderRole::_vftable_;
  this->m_iDir = 0;
  this->m_iNeedsRest = 0;
  return this;
}


// address=[0x1563150]
// Decompiled from ISettlerRole *__thiscall CBuilderRole::~CBuilderRole(CBuilderRole *this)
 CBuilderRole::~CBuilderRole(void) {
  
  *(_DWORD *)this = &CBuilderRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x1563170]
// Decompiled from void __thiscall CBuilderRole::GetNextJob(CBuilderRole *this, struct CSettler *a2)
void  CBuilderRole::GetNextJob(class CSettler * a2) {
  
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
  {
    IMovingEntity::ResetToDoList(a2);
  }
  this->TakeJob(this, a2);
}


// address=[0x15631b0]
// Decompiled from void __thiscall CBuilderRole::TakeJob(CBuilderRole *this, struct CSettler *a2)
void  CBuilderRole::TakeJob(class CSettler * a2) {
  
  CEntityTask *ActualTask; // eax
  CBuilding *v3; // eax
  int v4; // [esp-4h] [ebp-Ch]
  CHAR m_iTask; // [esp+0h] [ebp-8h]

  ActualTask = IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(this, a2, ActualTask);
  m_iTask = this->m_iTask;
  switch ( m_iTask )
  {
    case 7:
      IAnimatedEntity::SetFrame(a2, 1u);
      IMovingEntity::WalkToXY(a2, this->m_iDestinationPosition, 0);
      this->m_iTask = 6;
      IMovingEntity::SetDisplacementCosts(a2, 5);
      this->Go(this, a2);
      break;
    case 16:
      if ( this->CheckHome(this, a2) )
      {
        v4 = IEntity::ID(a2);
        v3 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, this->m_uHomeEntityId);
        CBuilding::SettlerEnter(v3, v4);
        IMovingEntity::SetDisplacementCosts(a2, 10);
        IAnimatedEntity::RegisterForLogicUpdate(a2, this->m_uCycleFrames);
        IMovingEntity::SetDirection(a2, this->m_iDir);
        this->m_iNeedsRest = 1;
      }
      break;
    case 17:
      IMovingEntity::SetDisplacementCosts(a2, 0);
      IAnimatedEntity::RegisterForLogicUpdate(a2, 1);
      break;
  }
}


// address=[0x15632c0]
// Decompiled from void __thiscall CBuilderRole::Init(CBuilderRole *this, IEntity *a1)
void  CBuilderRole::Init(class CSettler * a1) {
  
  if ( IEntity::FlagBits(a1, ENTITY_FLAG_ATTACHED) && BBSupportDbgReport(2, "MapObjects\\Settler\\BuilderRole.cpp", 140, "!_pSettler->FlagBits( ENTITY_FLAG_ATTACHED )") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uHomeEntityId && BBSupportDbgReport(2, "MapObjects\\Settler\\BuilderRole.cpp", 141, "!m_uHomeEntityId") == 1 )
  {
    __debugbreak();
  }
  CWarMap::AddEntity(a1);
  this->m_iNeedsRest = 0;
}


// address=[0x1563340]
// Decompiled from void __thiscall CBuilderRole::ConvertEventIntoGoal(CBuilderRole *this, struct CSettler *a2, struct CEntityEvent *a3)
void  CBuilderRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int v3; // eax
  int v4; // eax
  unsigned int v5; // eax
  std::list *v6; // eax
  int m_iDataA; // [esp-4h] [ebp-24h]
  CBuildingSiteRole *v8; // [esp+0h] [ebp-20h]
  CBuilding *v9; // [esp+4h] [ebp-1Ch]
  int m_iEvent; // [esp+8h] [ebp-18h]
  struct SBuilderPos v12; // [esp+10h] [ebp-10h] BYREF

  m_iEvent = a3->m_iEvent;
  if ( m_iEvent == 1 )
  {
    this->m_iNeedsRest = 0;
    v9 = CBuildingMgr::operator[]((CBuildingMgr *)g_cBuildingMgr, a3->m_iDataA);
    if ( IEntity::FlagBits(v9, (EntityFlag)4096) && ISettlerRole::HomeEntityId(this) )
    {
      if ( debug && DEBUG_FLAGS[dword_4152090] )
      {
        m_iDataA = a3->m_iDataA;
        v4 = IEntity::ID(a2);
        BBSupportTracePrintF(0, "Builder %u was orderd to buildingsite %u", v4, m_iDataA);
      }
      this->m_iStartPosition = IEntity::PackedXY(a2);
      v8 = (CBuildingSiteRole *)CBuilding::Role(v9);
      CBuildingSiteRole::GetBuilderPos(v8, &v12);
      ISettlerRole::NewDestination(this, a2, v12.m_iOffsetX, v12.m_iOffsetY, 0);
      v5 = IEntity::Race(a2);
      v6 = CEntityToDoListMgr::SettlerJobList(g_pEntityToDoListMgr, v5, 0x95u);
      a2->NewToDoList(a2, (int)v6, 149);
      CBuilderRole::SetDir(this, v12.m_iDirection);
    }
    else
    {
      this->SetFree(this, a2, -1);
    }
  }
  else if ( m_iEvent == 7 || m_iEvent == 9 )
  {
    if ( debug )
    {
      if ( DEBUG_FLAGS[dword_4152090] )
      {
        v3 = IEntity::ID(a2);
        BBSupportTracePrintF(0, "Building %u cancel order of builder %u", this->m_uHomeEntityId, v3);
      }
    }
    this->SetFree(this, a2, a3->m_iDataC);
  }
  else if ( !IEntity::FlagBits(a2, ENTITY_FLAG_Registered) )
  {
    if ( debug && DEBUG_FLAGS[dword_4152090] )
    {
      BBSupportTracePrint(0, "ConvertEventIntoGoal BuilderRole - unknown event");
    }
    IAnimatedEntity::RegisterForLogicUpdate(a2, 1);
  }
}


