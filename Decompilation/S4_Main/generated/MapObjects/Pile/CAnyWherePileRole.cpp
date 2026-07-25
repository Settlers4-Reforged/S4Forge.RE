#if FALSE
#include "CAnyWherePileRole.h"

// Definitions for class CAnyWherePileRole

// address=[0x13ffaa0]
// Decompiled from void __cdecl CAnyWherePileRole::New(struct std::_Facet_base *a1)
class CPersistence * __cdecl CAnyWherePileRole::New(std::istream & a1) {
  
  CAnyWherePileRole *C; // [esp+Ch] [ebp-10h]

  C = (CAnyWherePileRole *)operator new(8u);
  if ( C )
    CAnyWherePileRole::CAnyWherePileRole(C, (int)a1);
}


// address=[0x155af40]
// Decompiled from void __thiscall CAnyWherePileRole::Init(IPileRole *this, struct CPile *a2)
void  CAnyWherePileRole::Init(class CPile * a2) {
  
  IPileRole::Init(this, a2);
  a2->ClearAllQueuedEvents(a2);
  CPile::SetRoleType(a2, 3u);
  CPile::SetOfferFlag(a2, 1u);
  IEntity::SetFlagBits(a2, ENTITY_FLAG_Visible);
  if ( a2->Amount(a2) )
  {
    CPile::OfferCompletePileIfPossible(a2, 0);
    IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
  }
  else
  {
    CPileMgr::DeletePile(&g_cPileMgr, this->m_uPileId);
  }
}


// address=[0x155afc0]
// Decompiled from int __thiscall CAnyWherePileRole::LogicUpdate(CAnyWherePileRole *this, struct CPile *a2)
void  CAnyWherePileRole::LogicUpdate(class CPile * a2) {
  
  CPile::RequestSpaceIfPossible(a2);
  return IAnimatedEntity::RegisterForLogicUpdate(a2, 31);
}


// address=[0x155afe0]
// Decompiled from void __thiscall CAnyWherePileRole::Empty(CAnyWherePileRole *this, IEntity *a2)
void  CAnyWherePileRole::Empty(class CPile * a2) {
  
  int v2; // eax

  v2 = IEntity::EntityId(a2);
  CPileMgr::DeletePile(&g_cPileMgr, v2);
}


// address=[0x155b000]
// Decompiled from char __thiscall CAnyWherePileRole::ChangeGoodTypeUnforseen(CAnyWherePileRole *this, struct CPile *a2, int a3)
bool  CAnyWherePileRole::ChangeGoodTypeUnforseen(class CPile * a2, int a3) {
  
  return IPileRole::ExecuteChangeGoodTypeUnforseen(this, a2, a3);
}


// address=[0x155b020]
// Decompiled from void __thiscall CAnyWherePileRole::Occupied(CAnyWherePileRole *this, struct CPile *a2, _DWORD *a3)
void  CAnyWherePileRole::Occupied(class CPile * a2, int a3) {
  
  CPile::OfferCompletePileIfPossible(a2, a3);
}


// address=[0x155b040]
// Decompiled from char __thiscall CAnyWherePileRole::SetFree(CAnyWherePileRole *this, CPile *a2, int a3)
bool  CAnyWherePileRole::SetFree(class CPile * a2, int a3) {
  
  CPile::CancelCompleteOfferIfInOfferList(a2, a3);
  return 0;
}


// address=[0x155b060]
// Decompiled from CAnyWherePileRole *__thiscall CAnyWherePileRole::CAnyWherePileRole(CAnyWherePileRole *this, int a2)
 CAnyWherePileRole::CAnyWherePileRole(std::istream & a2) {
  
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  int v5; // [esp+1Ch] [ebp-4h]

  IPileRole::IPileRole(this, a2);
  v5 = 0;
  this->__vftable = (IPileRole_vtbl *)&CAnyWherePileRole::_vftable_;
  if ( Serial::LoadVersion(a2) != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CAnyWherePileRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v5 = -1;
  return this;
}


// address=[0x155b110]
// Decompiled from int __thiscall CAnyWherePileRole::Store(struct CPersistence *this, struct std::ostream *a2)
void  CAnyWherePileRole::Store(std::ostream & a2) {
  
  IPileRole::Store(this, a2);
  return Serial::StoreVersion((int)a2, 1);
}


// address=[0x155b1c0]
// Decompiled from IPileRole *__thiscall CAnyWherePileRole::~CAnyWherePileRole(CAnyWherePileRole *this)
 CAnyWherePileRole::~CAnyWherePileRole(void) {
  
  return IPileRole::~IPileRole(this);
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
void  CAnyWherePileRole::SubjectStarted(class CPile * a2) {
  
  ;
}


// address=[0x155b3a0]
// Decompiled from void __thiscall CAnyWherePileRole::SubjectStopped(CAnyWherePileRole *this, struct CPile *a2)
void  CAnyWherePileRole::SubjectStopped(class CPile * a2) {
  
  ;
}


// address=[0x1560340]
// Decompiled from int __cdecl CAnyWherePileRole::Load(struct std::istream *a1)
class CAnyWherePileRole * __cdecl CAnyWherePileRole::Load(std::istream & a1) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New(a1);
  return j____RTDynamicCast(v1, 0, &CPersistence__RTTI_Type_Descriptor_, &CAnyWherePileRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x3d8bbb4]
// [Decompilation failed for static unsigned long CAnyWherePileRole::m_iClassID]

// address=[0x1560110]
// Decompiled from CAnyWherePileRole *__thiscall CAnyWherePileRole::CAnyWherePileRole(CAnyWherePileRole *this)
 CAnyWherePileRole::CAnyWherePileRole(void) {
  
  IPileRole::IPileRole(this);
  this->__vftable = (IPileRole_vtbl *)&CAnyWherePileRole::_vftable_;
  return this;
}


#endif // Already implemented
