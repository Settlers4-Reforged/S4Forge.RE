#include "all_headers.h"

// Definitions for class CDoorRole

// address=[0x14005e0]
// Decompiled from int __cdecl CDoorRole::New(int a1)
static class CPersistence * __cdecl CDoorRole::New(std::istream &) {
  
  if ( operator new(0x2Cu) )
    return CDoorRole::CDoorRole(a1);
  else
    return 0;
}


// address=[0x156ce70]
// Decompiled from int __thiscall CDoorRole::LogicUpdate(CDoorRole *this, IEntity *a2)
void  CDoorRole::LogicUpdate(class CSettler *) {
  
  int v2; // eax
  int result; // eax
  int v4; // [esp-4h] [ebp-10h]
  int SettlerInfo; // [esp+4h] [ebp-8h]
  unsigned int v6; // [esp+8h] [ebp-4h]

  v4 = IEntity::Type(a2);
  v2 = IEntity::Race(a2);
  SettlerInfo = CSettlerMgr::GetSettlerInfo(v2, v4);
  result = a2->Amount();
  if ( result >= *(unsigned __int8 *)(SettlerInfo + 2) )
    return result;
  v6 = IEntity::Hitpoints(a2);
  if ( v6 < CStaticConfigVarInt::operator int(&unk_41520B4) )
    IEntity::SetHitpoints(a2, v6 + 1);
  return IAnimatedEntity::RegisterForLogicUpdate(15);
}


// address=[0x156cef0]
// Decompiled from int __stdcall CDoorRole::PostLoadInit(CPropertySet *a1)
void  CDoorRole::PostLoadInit(class CSettler *) {
  
  int result; // eax

  if ( !a1 && BBSupportDbgReport(2, "MapObjects\\Settler\\DoorRole.cpp", 114, "_pSettler!=NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( a1 )
    return CWarMap::AddEntity(a1);
  return result;
}


// address=[0x156cf40]
// Decompiled from char __thiscall CDoorRole::SetFree(CDoorRole *this, struct CSettler *a2, int a3)
bool  CDoorRole::SetFree(class CSettler *,int) {
  
  void **v3; // eax
  int v5; // [esp+0h] [ebp-10h]
  CBuilding *v6; // [esp+8h] [ebp-8h]

  if ( !*((_WORD *)this + 16) )
    return 0;
  v6 = (CBuilding *)CBuildingMgr::operator[](*((unsigned __int16 *)this + 16));
  v3 = (void **)CBuilding::Role(v6);
  if ( !j____RTDynamicCast(
          v3,
          0,
          &IBuildingRole__RTTI_Type_Descriptor_,
          &CMilitaryBuildingRole__RTTI_Type_Descriptor_,
          0)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Settler\\DoorRole.cpp",
         183,
         "dynamic_cast<CMilitaryBuildingRole*>(&rBuilding.Role()) != 0") == 1 )
  {
    __debugbreak();
  }
  v5 = IEntity::EntityId((unsigned __int16 *)a2);
  CBuilding::InhabitantFlee(v6, v5);
  return 0;
}


// address=[0x156cfd0]
// Decompiled from int __thiscall CDoorRole::Decrease(CDoorRole *this, int a2)
int  CDoorRole::Decrease(int) {
  
  _DWORD *v3; // [esp+4h] [ebp-4h]

  if ( a2 <= 0 )
    return a2;
  v3 = (_DWORD *)CSettlerMgr::operator[](*((unsigned __int16 *)this + 9));
  if ( !IEntity::FlagBits(v3, Registered) )
    IAnimatedEntity::RegisterForLogicUpdate(15);
  return a2;
}


// address=[0x156d020]
// Decompiled from char *__thiscall CDoorRole::CDoorRole(char *this, int a2)
 CDoorRole::CDoorRole(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  char *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  ISettlerRole::ISettlerRole(this, a2);
  v6 = 0;
  *(_DWORD *)v5 = &CDoorRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CDoorRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x156d0d0]
// Decompiled from int __thiscall CDoorRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CDoorRole::Store(std::ostream &) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  ISettlerRole::Store(this, a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x156d2b0]
// Decompiled from int __thiscall CDoorRole::ClassID(CDoorRole *this)
unsigned long  CDoorRole::ClassID(void)const {
  
  return CDoorRole::m_iClassID;
}


// address=[0x156d2d0]
// Decompiled from void __thiscall CDoorRole::ConvertEventIntoGoal(CDoorRole *this, struct CSettler *a2, struct CEntityEvent *a3)
void  CDoorRole::ConvertEventIntoGoal(class CSettler *,class CEntityEvent *) {
  
  ;
}


// address=[0x156d2f0]
// Decompiled from int __thiscall CDoorRole::GetSettlerRole(CDoorRole *this)
int  CDoorRole::GetSettlerRole(void)const {
  
  return 21;
}


// address=[0x156d310]
// Decompiled from void *__thiscall CDoorRole::InitWalking(std::_Ref_count_base *this, const struct type_info *a2)
class CWalking *  CDoorRole::InitWalking(class CSettler *) {
  
  return 0;
}


// address=[0x156d330]
// Decompiled from void __thiscall CDoorRole::LogicUpdateJob(CDoorRole *this, struct CSettler *a2)
void  CDoorRole::LogicUpdateJob(class CSettler *) {
  
  ;
}


// address=[0x1588580]
// Decompiled from int __cdecl CDoorRole::Load(int a1)
static class CDoorRole * __cdecl CDoorRole::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CDoorRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8beb8]
// [Decompilation failed for static unsigned long CDoorRole::m_iClassID]

// address=[0x156d110]
// Decompiled from IEntity *__thiscall CDoorRole::Init(_WORD *this, CPropertySet *a2)
void  CDoorRole::Init(class CSettler *) {
  
  IEntity *result; // eax
  char v3; // al

  if ( !a2 && BBSupportDbgReport(2, "MapObjects\\Settler\\DoorRole.cpp", 97, "_pSettler!= NULL") == 1 )
    __debugbreak();
  result = 0;
  if ( !a2 )
    return result;
  this[9] = IEntity::EntityId((unsigned __int16 *)a2);
  CWarMap::AddEntity(a2);
  v3 = CStaticConfigVarInt::operator int(&unk_41520B4);
  return IEntity::SetHitpoints((IEntity *)a2, v3);
}


// address=[0x156d240]
// Decompiled from ISettlerRole *__thiscall CDoorRole::~CDoorRole(CDoorRole *this)
 CDoorRole::~CDoorRole(void) {
  
  *(_DWORD *)this = &CDoorRole::_vftable_;
  return ISettlerRole::~ISettlerRole(this);
}


// address=[0x156d2e0]
// Decompiled from void __thiscall CDoorRole::GetNextJob(CDoorRole *this, struct CSettler *a2)
void  CDoorRole::GetNextJob(class CSettler *) {
  
  ;
}


// address=[0x156d360]
// Decompiled from void __thiscall CDoorRole::TakeJob(CDoorRole *this, struct CSettler *a2)
void  CDoorRole::TakeJob(class CSettler *) {
  
  ;
}


// address=[0x1587a50]
// Decompiled from CDoorRole *__thiscall CDoorRole::CDoorRole(CDoorRole *this)
 CDoorRole::CDoorRole(void) {
  
  ISettlerRole::ISettlerRole(this);
  *(_DWORD *)this = &CDoorRole::_vftable_;
  return this;
}


