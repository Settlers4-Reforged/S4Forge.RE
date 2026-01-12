#include "CTrojanCatapult.h"

// Definitions for class CTrojanCatapult

// address=[0x1402660]
// Decompiled from int __cdecl CTrojanCatapult::New(int a1)
static class CPersistence * __cdecl CTrojanCatapult::New(std::istream &) {
  
  if ( CTrojanCatapult::operator new(0xD8u) )
    return CTrojanCatapult::CTrojanCatapult(a1);
  else
    return 0;
}


// address=[0x153f150]
// Decompiled from unsigned int __cdecl CTrojanCatapult::operator new(unsigned int a1)
static void * __cdecl CTrojanCatapult::operator new(unsigned int) {
  
  return CVehicleMgr::Alloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x153f170]
// Decompiled from void __cdecl CTrojanCatapult::operator delete(void *a1)
static void __cdecl CTrojanCatapult::operator delete(void *) {
  
  CVehicleMgr::Dealloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x153f1b0]
// Decompiled from _DWORD *__thiscall CTrojanCatapult::CTrojanCatapult(_DWORD *this, int a2)
 CTrojanCatapult::CTrojanCatapult(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CCatapult::CCatapult(a2);
  v6 = 0;
  *v5 = &CTrojanCatapult::_vftable_;
  v5[45] = &CTrojanCatapult::`vftable';
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CTrojanCatapult");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x153f270]
// Decompiled from int __thiscall CTrojanCatapult::Store(void *this, struct std::ostream *a2)
void  CTrojanCatapult::Store(std::ostream &) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  CCatapult::Store(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x153fae0]
// Decompiled from void __thiscall CTrojanCatapult::~CTrojanCatapult(CTrojanCatapult *this)
 CTrojanCatapult::~CTrojanCatapult(void) {
  
  CCatapult::~CCatapult(this);
}


// address=[0x153fd60]
// Decompiled from int __thiscall CTrojanCatapult::ClassID(CTrojanCatapult *this)
unsigned long  CTrojanCatapult::ClassID(void)const {
  
  return CTrojanCatapult::m_iClassID;
}


// address=[0x3d8b878]
// [Decompilation failed for static unsigned long CTrojanCatapult::m_iClassID]

// address=[0x153f2b0]
// Decompiled from CTrojanCatapult *__thiscall CTrojanCatapult::CTrojanCatapult(  CTrojanCatapult *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  bool a8)
 CTrojanCatapult::CTrojanCatapult(int,int,int,int,int,int,bool) {
  
  CCatapult::CCatapult(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CTrojanCatapult::_vftable_;
  *((_DWORD *)this + 45) = &CTrojanCatapult::`vftable';
  return this;
}


