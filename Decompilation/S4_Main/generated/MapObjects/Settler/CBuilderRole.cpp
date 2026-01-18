#include "CBuilderRole.h"

// Definitions for class CBuilderRole

// address=[0x13ffc80]
// Decompiled from int __cdecl CBuilderRole::New(int a1)
class CPersistence * __cdecl CBuilderRole::New(std::istream & a1) {
  
  if ( operator new(0x30u) )
    return CBuilderRole::CBuilderRole(a1);
  else
    return 0;
}


// address=[0x1562d90]
// Decompiled from int __thiscall CBuilderRole::InitWalking(CBuilderRole *this, struct CSettler *a2)
class CWalking *  CBuilderRole::InitWalking(class CSettler * a2) {
  
  int v2; // eax
  int v4; // [esp+4h] [ebp-4h]

  v2 = IEntity::OwnerId((unsigned __int8 *)a2);
  v4 = CWalking::Create(1, v2);
  (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v4 + 8))(v4, -1, 0);
  return v4;
}


// address=[0x1562dd0]
// Decompiled from void __thiscall CBuilderRole::LogicUpdateJob(CBuilderRole *this, struct CSettler *a2)
void  CBuilderRole::LogicUpdateJob(class CSettler * a2) {
  
  _DWORD *v2; // eax
  CBuildingSiteRole *v3; // [esp+0h] [ebp-Ch]
  char v4; // [esp+4h] [ebp-8h]

  v4 = *((_BYTE *)this + 4);
  if ( v4 == 6 )
  {
    IMovingEntity::SetDistance(a2, 0);
    (*(void (__thiscall **)(CBuilderRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
  }
  else if ( v4 == 16
         && (*(unsigned __int8 (__thiscall **)(CBuilderRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2) )
  {
    *((_BYTE *)this + 7) = *(_BYTE *)(IMovingEntity::GetActualTask(a2) + 8);
    IAnimatedEntity::RegisterForLogicUpdate(*((unsigned __int8 *)this + 7));
    *((_BYTE *)this + 7) = 1;
    v2 = (_DWORD *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
    v3 = (CBuildingSiteRole *)CBuilding::Role(v2);
    if ( CBuildingSiteRole::HaveBuildingMaterial(v3) )
    {
      *((_BYTE *)this + 7) = *(_BYTE *)(IMovingEntity::GetActualTask(a2) + 8);
      CBuildingSiteRole::AddWork(v3, *((unsigned __int8 *)this + 7));
    }
    else
    {
      (*(void (__thiscall **)(CBuilderRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(this, a2, -1);
    }
  }
}


// address=[0x1562ec0]
// Decompiled from int __stdcall CBuilderRole::PostLoadInit(CPropertySet *a1)
void  CBuilderRole::PostLoadInit(class CSettler * a1) {
  
  return CWarMap::AddEntity(a1);
}


// address=[0x1562ee0]
// Decompiled from char __thiscall CBuilderRole::SetFree(CBuilderRole *this, struct CSettler *a2, int a3)
bool  CBuilderRole::SetFree(class CSettler * a2, int a3) {
  
  int v3; // eax
  void **v4; // eax
  int v5; // eax
  _DWORD *v7; // [esp+0h] [ebp-14h]
  CBuildingSiteRole *v8; // [esp+8h] [ebp-Ch]
  bool v10; // [esp+13h] [ebp-1h]

  if ( ISettlerRole::HomeEntityId(this) )
  {
    v3 = ISettlerRole::HomeEntityId(this);
    v7 = (_DWORD *)CBuildingMgr::operator[](v3);
    v4 = (void **)CBuilding::Role(v7);
    v8 = (CBuildingSiteRole *)j____RTDynamicCast(
                                v4,
                                0,
                                &IBuildingRole__RTTI_Type_Descriptor_,
                                &CBuildingSiteRole__RTTI_Type_Descriptor_,
                                0);
    if ( v8 )
    {
      v5 = IEntity::EntityId((unsigned __int16 *)a2);
      CBuildingSiteRole::BuilderLeft(v8, v5);
    }
  }
  v10 = *((_BYTE *)this + 45) == 1;
  if ( ISettlerRole::SetFree(this, a2, a3) )
    return 1;
  if ( v10
    && (*(unsigned __int8 (__thiscall **)(CBuilderRole *, struct CSettler *, int))(*(_DWORD *)this + 120))(this, a2, 3) )
  {
    IAnimatedEntity::SetFrame(1);
    IMovingEntity::WalkToXY(a2, *((_DWORD *)this + 7), 0x2000);
    *((_BYTE *)this + 4) = 6;
    IMovingEntity::SetDisplacementCosts(5);
    return 0;
  }
  else
  {
    IAnimatedEntity::SetFrame(1);
    *((_BYTE *)this + 4) = 17;
    return 0;
  }
}


// address=[0x1562ff0]
// Decompiled from _DWORD *__thiscall CBuilderRole::CBuilderRole(char *this, int a2)
 CBuilderRole::CBuilderRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ISettlerRole::ISettlerRole(this, a2);
  v6 = 0;
  *v5 = &CBuilderRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CBuilderRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<signed char>(a2, v5 + 11);
  operator^<signed char>(a2, (char *)v5 + 45);
  v6 = -1;
  return v5;
}


// address=[0x15630c0]
// Decompiled from int __thiscall CBuilderRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CBuilderRole::Store(std::ostream & a2) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  struct CPersistence *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  ISettlerRole::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<signed char>(a2, (char *)v4 + 44);
  return operator^<signed char>(a2, (char *)v4 + 45);
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
// Decompiled from CBuilderRole *__thiscall CBuilderRole::SetDir(CBuilderRole *this, char a2)
void  CBuilderRole::SetDir(char a2) {
  
  CBuilderRole *result; // eax

  result = this;
  *((_BYTE *)this + 44) = a2;
  return result;
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
  *(_DWORD *)this = &CBuilderRole::_vftable_;
  *((_BYTE *)this + 44) = 0;
  *((_BYTE *)this + 45) = 0;
  return this;
}


// address=[0x1563150]
// Decompiled from ISettlerRole *__thiscall CBuilderRole::~CBuilderRole(CBuilderRole *this)
 CBuilderRole::~CBuilderRole(void) {
  
  *(_DWORD *)this = &CBuilderRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x1563170]
// Decompiled from int __thiscall CBuilderRole::GetNextJob(CBuilderRole *this, struct CSettler *a2)
void  CBuilderRole::GetNextJob(class CSettler * a2) {
  
  CBuilderRole *v3; // [esp+0h] [ebp-4h]

  v3 = this;
  IMovingEntity::IncToDoListIter(a2);
  if ( IMovingEntity::IsEndIter(a2) )
    IMovingEntity::ResetToDoList(v3);
  return (*(int (__thiscall **)(CBuilderRole *, struct CSettler *))(*(_DWORD *)v3 + 40))(v3, a2);
}


// address=[0x15631b0]
// Decompiled from void __thiscall CBuilderRole::TakeJob(CBuilderRole *this, struct CSettler *a2)
void  CBuilderRole::TakeJob(class CSettler * a2) {
  
  const struct CEntityTask *ActualTask; // eax
  CBuilding *v3; // eax
  int v4; // [esp-4h] [ebp-Ch]
  char v5; // [esp+0h] [ebp-8h]

  ActualTask = (const struct CEntityTask *)IMovingEntity::GetActualTask(a2);
  ISettlerRole::InitCommonTaskValues(this, a2, ActualTask);
  v5 = *((_BYTE *)this + 4);
  switch ( v5 )
  {
    case 7:
      IAnimatedEntity::SetFrame(1);
      IMovingEntity::WalkToXY(a2, *((_DWORD *)this + 6), 0);
      *((_BYTE *)this + 4) = 6;
      IMovingEntity::SetDisplacementCosts(5);
      (*(void (__thiscall **)(CBuilderRole *, struct CSettler *))(*(_DWORD *)this + 16))(this, a2);
      break;
    case 16:
      if ( (*(unsigned __int8 (__thiscall **)(CBuilderRole *, struct CSettler *))(*(_DWORD *)this + 124))(this, a2) )
      {
        v4 = IEntity::ID();
        v3 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
        CBuilding::SettlerEnter(v3, v4);
        IMovingEntity::SetDisplacementCosts(10);
        IAnimatedEntity::RegisterForLogicUpdate(*((unsigned __int8 *)this + 7));
        IMovingEntity::SetDirection(a2, *((char *)this + 44));
        *((_BYTE *)this + 45) = 1;
      }
      break;
    case 17:
      IMovingEntity::SetDisplacementCosts(0);
      IAnimatedEntity::RegisterForLogicUpdate(1);
      break;
  }
}


// address=[0x15632c0]
// Decompiled from int __thiscall CBuilderRole::Init(int this, CPropertySet *a2)
void  CBuilderRole::Init(class CSettler * a2) {
  
  int result; // eax

  if ( IEntity::FlagBits(a2, 0x20)
    && BBSupportDbgReport(
         2,
         (int)"MapObjects\\Settler\\BuilderRole.cpp",
         140,
         (int)"!_pSettler->FlagBits( ENTITY_FLAG_ATTACHED )") == 1 )
  {
    __debugbreak();
  }
  if ( *(_WORD *)(this + 32)
    && BBSupportDbgReport(2, (int)"MapObjects\\Settler\\BuilderRole.cpp", 141, (int)"!m_uHomeEntityId") == 1 )
  {
    __debugbreak();
  }
  result = CWarMap::AddEntity(a2);
  *(_BYTE *)(this + 45) = 0;
  return result;
}


// address=[0x1563340]
// Decompiled from CBuilderRole *__thiscall CBuilderRole::ConvertEventIntoGoal(  CBuilderRole *this,  struct CSettler *a2,  struct CEntityEvent *a3)
void  CBuilderRole::ConvertEventIntoGoal(class CSettler * a2, class CEntityEvent * a3) {
  
  int v3; // eax
  CBuilderRole *result; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // [esp-4h] [ebp-24h]
  CBuildingSiteRole *v9; // [esp+0h] [ebp-20h]
  _DWORD *v10; // [esp+4h] [ebp-1Ch]
  int v11; // [esp+8h] [ebp-18h]
  int v13[2]; // [esp+10h] [ebp-10h] BYREF
  char v14; // [esp+18h] [ebp-8h]

  v11 = *((_DWORD *)a3 + 1);
  if ( v11 == 1 )
  {
    *((_BYTE *)this + 45) = 0;
    v10 = (_DWORD *)CBuildingMgr::operator[](*((_DWORD *)a3 + 3));
    if ( IEntity::FlagBits(v10, (EntityFlag)0x1000u) && ISettlerRole::HomeEntityId(this) )
    {
      if ( debug && DEBUG_FLAGS[dword_4152090] )
      {
        v8 = *((_DWORD *)a3 + 3);
        v5 = IEntity::ID();
        BBSupportTracePrintF(0, "Builder %u was orderd to buildingsite %u", v5, v8);
      }
      *((_DWORD *)this + 7) = IEntity::PackedXY(a2);
      v9 = (CBuildingSiteRole *)CBuilding::Role(v10);
      CBuildingSiteRole::GetBuilderPos(v9, (struct SBuilderPos *)v13);
      ISettlerRole::NewDestination(this, a2, v13[0], v13[1], 0);
      v6 = IEntity::Race(a2);
      v7 = CEntityToDoListMgr::SettlerJobList(v6, 149);
      (*(void (__thiscall **)(struct CSettler *, int, int))(*(_DWORD *)a2 + 112))(a2, v7, 149);
      return CBuilderRole::SetDir(this, v14);
    }
    else
    {
      return (CBuilderRole *)(*(int (__thiscall **)(CBuilderRole *, struct CSettler *, int))(*(_DWORD *)this + 64))(
                               this,
                               a2,
                               -1);
    }
  }
  else if ( v11 == 7 || v11 == 9 )
  {
    if ( !debug )
      return (CBuilderRole *)(*(int (__thiscall **)(CBuilderRole *, struct CSettler *, _DWORD))(*(_DWORD *)this + 64))(
                               this,
                               a2,
                               *((_DWORD *)a3 + 5));
    if ( !DEBUG_FLAGS[dword_4152090] )
      return (CBuilderRole *)(*(int (__thiscall **)(CBuilderRole *, struct CSettler *, _DWORD))(*(_DWORD *)this + 64))(
                               this,
                               a2,
                               *((_DWORD *)a3 + 5));
    v3 = IEntity::ID();
    BBSupportTracePrintF(0, "Building %u cancel order of builder %u", *((unsigned __int16 *)this + 16), v3);
    return (CBuilderRole *)(*(int (__thiscall **)(CBuilderRole *, struct CSettler *, _DWORD))(*(_DWORD *)this + 64))(
                             this,
                             a2,
                             *((_DWORD *)a3 + 5));
  }
  else
  {
    result = (CBuilderRole *)IEntity::FlagBits(a2, Registered);
    if ( !result )
    {
      if ( debug && DEBUG_FLAGS[dword_4152090] )
        BBSupportTracePrint(0, "ConvertEventIntoGoal BuilderRole - unknown event");
      return (CBuilderRole *)IAnimatedEntity::RegisterForLogicUpdate(1);
    }
  }
  return result;
}


