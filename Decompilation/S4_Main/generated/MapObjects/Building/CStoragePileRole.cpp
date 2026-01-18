#include "CStoragePileRole.h"

// Definitions for class CStoragePileRole

// address=[0x1402200]
// Decompiled from void __cdecl CStoragePileRole::New(struct std::_Facet_base *a1)
class CPersistence * __cdecl CStoragePileRole::New(std::istream & a1) {
  
  if ( operator new(8u) )
    CStoragePileRole::CStoragePileRole(a1);
}


// address=[0x1560260]
// Decompiled from void __thiscall CStoragePileRole::~CStoragePileRole(CStoragePileRole *this)
 CStoragePileRole::~CStoragePileRole(void) {
  
  IPileRole::~IPileRole(this);
}


// address=[0x1560320]
// Decompiled from int __thiscall CStoragePileRole::ClassID(CStoragePileRole *this)
unsigned long  CStoragePileRole::ClassID(void)const {
  
  return CStoragePileRole::m_iClassID;
}


// address=[0x1560440]
// Decompiled from int __cdecl CStoragePileRole::Load(int a1)
class CStoragePileRole * __cdecl CStoragePileRole::Load(std::istream & a1) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CStoragePileRole__RTTI_Type_Descriptor_, 1);
}


// address=[0x1561900]
// Decompiled from void __thiscall CStoragePileRole::Init(CStoragePileRole *this, struct CPile *a2)
void  CStoragePileRole::Init(class CPile *) {
  
  IPileRole::Init(this, a2);
  CPile::SetRoleType(a2, 2);
  CPile::SetOfferFlag(a2, 1);
  CPile::OfferCompletePileIfPossible(a2, 0);
}


// address=[0x1561940]
// Decompiled from _DWORD *__thiscall CStoragePileRole::CStoragePileRole(_DWORD *this, int a2)
 CStoragePileRole::CStoragePileRole(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  IPileRole::IPileRole(a2);
  v6 = 0;
  *v5 = &CStoragePileRole::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CStoragePileRole");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x15619f0]
// Decompiled from int __thiscall CStoragePileRole::Store(void *this, struct std::ostream *a2)
void  CStoragePileRole::Store(std::ostream & a2) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  IPileRole::Store(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x3d8be9c]
// [Decompilation failed for static unsigned long CStoragePileRole::m_iClassID]

// address=[0x15601d0]
// Decompiled from CStoragePileRole *__thiscall CStoragePileRole::CStoragePileRole(CStoragePileRole *this)
 CStoragePileRole::CStoragePileRole(void) {
  
  IPileRole::IPileRole(this);
  *(_DWORD *)this = &CStoragePileRole::_vftable_;
  return this;
}


