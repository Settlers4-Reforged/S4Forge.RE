#include "CRomanCatapult.h"

// Definitions for class CRomanCatapult

// address=[0x14019e0]
// Decompiled from int __cdecl CRomanCatapult::New(int a1)
static class CPersistence * __cdecl CRomanCatapult::New(std::istream &) {
  
  if ( CRomanCatapult::operator new(0xD8u) )
    return CRomanCatapult::CRomanCatapult(a1);
  else
    return 0;
}


// address=[0x153eb50]
// Decompiled from unsigned int __cdecl CRomanCatapult::operator new(unsigned int a1)
static void * __cdecl CRomanCatapult::operator new(unsigned int) {
  
  return CVehicleMgr::Alloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x153eb70]
// Decompiled from void __cdecl CRomanCatapult::operator delete(void *a1)
static void __cdecl CRomanCatapult::operator delete(void *) {
  
  CVehicleMgr::Dealloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x153ebb0]
// Decompiled from _DWORD *__thiscall CRomanCatapult::CRomanCatapult(_DWORD *this, int a2)
 CRomanCatapult::CRomanCatapult(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CCatapult::CCatapult(a2);
  v6 = 0;
  *v5 = &CRomanCatapult::_vftable_;
  v5[45] = &CRomanCatapult::`vftable';
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CRomanCatapult");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x153ec70]
// Decompiled from int __thiscall CRomanCatapult::Store(void *this, struct std::ostream *a2)
void  CRomanCatapult::Store(std::ostream &) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  CCatapult::Store(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x153fac0]
// Decompiled from void __thiscall CRomanCatapult::~CRomanCatapult(CRomanCatapult *this)
 CRomanCatapult::~CRomanCatapult(void) {
  
  CCatapult::~CCatapult(this);
}


// address=[0x153fd40]
// Decompiled from int __thiscall CRomanCatapult::ClassID(CRomanCatapult *this)
unsigned long  CRomanCatapult::ClassID(void)const {
  
  return CRomanCatapult::m_iClassID;
}


// address=[0x3d8b838]
// [Decompilation failed for static unsigned long CRomanCatapult::m_iClassID]

// address=[0x153ecb0]
// Decompiled from CRomanCatapult *__thiscall CRomanCatapult::CRomanCatapult(  CRomanCatapult *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  bool a8)
 CRomanCatapult::CRomanCatapult(int,int,int,int,int,int,bool) {
  
  CCatapult::CCatapult(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CRomanCatapult::_vftable_;
  *((_DWORD *)this + 45) = &CRomanCatapult::`vftable';
  return this;
}


