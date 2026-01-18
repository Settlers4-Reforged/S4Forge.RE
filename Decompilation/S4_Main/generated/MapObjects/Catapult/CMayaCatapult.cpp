#include "CMayaCatapult.h"

// Definitions for class CMayaCatapult

// address=[0x1401260]
// Decompiled from int __cdecl CMayaCatapult::New(int a1)
class CPersistence * __cdecl CMayaCatapult::New(std::istream & a1) {
  
  if ( CMayaCatapult::operator new(0xD8u) )
    return CMayaCatapult::CMayaCatapult(a1);
  else
    return 0;
}


// address=[0x153ed00]
// Decompiled from unsigned int __cdecl CMayaCatapult::operator new(unsigned int a1)
void * __cdecl CMayaCatapult::operator new(unsigned int a1) {
  
  return CVehicleMgr::Alloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x153ed20]
// Decompiled from void __cdecl CMayaCatapult::operator delete(void *a1)
void __cdecl CMayaCatapult::operator delete(void * a1) {
  
  CVehicleMgr::Dealloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x153ed60]
// Decompiled from _DWORD *__thiscall CMayaCatapult::CMayaCatapult(_DWORD *this, int a2)
 CMayaCatapult::CMayaCatapult(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CCatapult::CCatapult(a2);
  v6 = 0;
  *v5 = &CMayaCatapult::_vftable_;
  v5[45] = &CMayaCatapult::`vftable';
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CMayaCatapult");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x153ee20]
// Decompiled from int __thiscall CMayaCatapult::Store(void *this, struct std::ostream *a2)
void  CMayaCatapult::Store(std::ostream & a2) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  CCatapult::Store(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x153faa0]
// Decompiled from void __thiscall CMayaCatapult::~CMayaCatapult(CMayaCatapult *this)
 CMayaCatapult::~CMayaCatapult(void) {
  
  CCatapult::~CCatapult(this);
}


// address=[0x153fd20]
// Decompiled from int __thiscall CMayaCatapult::ClassID(CMayaCatapult *this)
unsigned long  CMayaCatapult::ClassID(void)const {
  
  return CMayaCatapult::m_iClassID;
}


// address=[0x3d8b83c]
// [Decompilation failed for static unsigned long CMayaCatapult::m_iClassID]

// address=[0x153ee60]
// Decompiled from CMayaCatapult *__thiscall CMayaCatapult::CMayaCatapult(  CMayaCatapult *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  bool a8)
 CMayaCatapult::CMayaCatapult(int a2, int a3, int a4, int a5, int a6, int a7, bool a8) {
  
  CCatapult::CCatapult(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CMayaCatapult::_vftable_;
  *((_DWORD *)this + 45) = &CMayaCatapult::`vftable';
  return this;
}


// address=[0x153fd00]
// Decompiled from int __thiscall CMayaCatapult::AmmoPerPile(CMayaCatapult *this)
int const  CMayaCatapult::AmmoPerPile(void) {
  
  return 8;
}


