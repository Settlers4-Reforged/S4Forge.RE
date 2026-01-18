#include "CAnyWherePileRole.h"

// Definitions for class CAnyWherePileRole

// address=[0x13ffaa0]
// Decompiled from void __cdecl CAnyWherePileRole::New(struct std::_Facet_base *a1)
class CPersistence * __cdecl CAnyWherePileRole::New(std::istream & a1) {
  
  if ( operator new(8u) )
    CAnyWherePileRole::CAnyWherePileRole(a1);
}


// address=[0x155af40]
// Decompiled from void __thiscall CAnyWherePileRole::Init(CAnyWherePileRole *this, struct CPile *a2)
void  CAnyWherePileRole::Init(class CPile *) {
  
  IPileRole::Init(this, a2);
  (*(void (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 104))(a2);
  CPile::SetRoleType(a2, 3);
  CPile::SetOfferFlag(a2, 1);
  IEntity::SetFlagBits(a2, EntityFlag_Visible);
  if ( (*(int (__thiscall **)(struct CPile *))(*(_DWORD *)a2 + 40))(a2) )
  {
    CPile::OfferCompletePileIfPossible(a2, 0);
    IAnimatedEntity::RegisterForLogicUpdate(31);
  }
  else
  {
    CPileMgr::DeletePile((CPileMgr *)&g_cPileMgr, *((unsigned __int16 *)this + 2));
  }
}


// address=[0x155afc0]
// Decompiled from int __thiscall CAnyWherePileRole::LogicUpdate(CAnyWherePileRole *this, struct CPile *a2)
void  CAnyWherePileRole::LogicUpdate(class CPile * a2) {
  
  CPile::RequestSpaceIfPossible(a2);
  return IAnimatedEntity::RegisterForLogicUpdate(31);
}


// address=[0x155afe0]
// Decompiled from void __thiscall CAnyWherePileRole::Empty(CAnyWherePileRole *this, struct CPile *a2)
void  CAnyWherePileRole::Empty(class CPile * a2) {
  
  int v2; // eax

  v2 = IEntity::EntityId((unsigned __int16 *)a2);
  CPileMgr::DeletePile((CPileMgr *)&g_cPileMgr, v2);
}


// address=[0x155b000]
// Decompiled from bool __thiscall CAnyWherePileRole::ChangeGoodTypeUnforseen(CAnyWherePileRole *this, struct CPile *a2, int a3)
bool  CAnyWherePileRole::ChangeGoodTypeUnforseen(class CPile * a2, int a3) {
  
  return IPileRole::ExecuteChangeGoodTypeUnforseen(this, a2, a3);
}


// address=[0x155b020]
// Decompiled from void __thiscall CAnyWherePileRole::Occupied(CAnyWherePileRole *this, struct CPile *a2, int a3)
void  CAnyWherePileRole::Occupied(class CPile * a2, int a3) {
  
  CPile::OfferCompletePileIfPossible(a2, a3);
}


// address=[0x155b040]
// Decompiled from char __thiscall CAnyWherePileRole::SetFree(CAnyWherePileRole *this, struct CPile *a2, int a3)
bool  CAnyWherePileRole::SetFree(class CPile * a2, int a3) {
  
  CPile::CancelCompleteOfferIfInOfferList(a2, a3);
  return 0;
}


// address=[0x155b060]
// Decompiled from _DWORD *__thiscall CAnyWherePileRole::CAnyWherePileRole(_DWORD *this, int a2)
 CAnyWherePileRole::CAnyWherePileRole(std::istream & a2) {
  
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v4; // [esp+10h] [ebp-10h]
  int v5; // [esp+1Ch] [ebp-4h]

  v4 = this;
  IPileRole::IPileRole(a2);
  v5 = 0;
  *v4 = &CAnyWherePileRole::_vftable_;
  if ( Serial::LoadVersion(a2) != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CAnyWherePileRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v5 = -1;
  return v4;
}


// address=[0x155b110]
// Decompiled from int __stdcall CAnyWherePileRole::Store(struct std::ostream *a1)
void  CAnyWherePileRole::Store(std::ostream & a2) {
  
  IPileRole::Store(a1);
  return Serial::StoreVersion(a1, 1);
}


// address=[0x155b1c0]
// Decompiled from void __thiscall CAnyWherePileRole::~CAnyWherePileRole(CAnyWherePileRole *this)
 CAnyWherePileRole::~CAnyWherePileRole(void) {
  
  IPileRole::~IPileRole(this);
}


// address=[0x155b2a0]
// Decompiled from int __thiscall CAnyWherePileRole::ClassID(CAnyWherePileRole *this)
unsigned long  CAnyWherePileRole::ClassID(void)const {
  
  return CAnyWherePileRole::m_iClassID;
}


// address=[0x155b380]
// Decompiled from void __thiscall CAnyWherePileRole::SubjectDie(CAnyWherePileRole *this, struct CPile *a2, int a3)
void  CAnyWherePileRole::SubjectDie(class CPile * a2, int a3) {
  
  ;
}


// address=[0x155b390]
// Decompiled from void __thiscall CAnyWherePileRole::SubjectStarted(CAnyWherePileRole *this, struct CPile *a2)
void  CAnyWherePileRole::SubjectStarted(class CPile *) {
  
  ;
}


// address=[0x155b3a0]
// Decompiled from void __thiscall CAnyWherePileRole::SubjectStopped(CAnyWherePileRole *this, struct CPile *a2)
void  CAnyWherePileRole::SubjectStopped(class CPile *) {
  
  ;
}


// address=[0x1560340]
// Decompiled from int __cdecl CAnyWherePileRole::Load(int a1)
class CAnyWherePileRole * __cdecl CAnyWherePileRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CAnyWherePileRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bbb4]
// [Decompilation failed for static unsigned long CAnyWherePileRole::m_iClassID]

// address=[0x1560110]
// Decompiled from CAnyWherePileRole *__thiscall CAnyWherePileRole::CAnyWherePileRole(CAnyWherePileRole *this)
 CAnyWherePileRole::CAnyWherePileRole(void) {
  
  IPileRole::IPileRole(this);
  *(_DWORD *)this = &CAnyWherePileRole::_vftable_;
  return this;
}


