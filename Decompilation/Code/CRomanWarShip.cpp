#include "CRomanWarShip.h"

// Definitions for class CRomanWarShip

// address=[0x1401a80]
// Decompiled from int __cdecl CRomanWarShip::New(int a1)

static class CPersistence * __cdecl CRomanWarShip::New(std::istream &) {
  
  if ( CWarShip::operator new(0xC8u) )
    return CRomanWarShip::CRomanWarShip(a1);
  else
    return 0;
}


// address=[0x15a1890]
// Decompiled from _DWORD *__thiscall CRomanWarShip::CRomanWarShip(_DWORD *this, int a2)

 CRomanWarShip::CRomanWarShip(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CWarShip::CWarShip(a2);
  v6 = 0;
  *v5 = &CRomanWarShip::_vftable_;
  v5[43] = &CRomanWarShip::`vftable';
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CRomanWarShip");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x15a1950]
// Decompiled from int __thiscall CRomanWarShip::Store(void *this, struct std::ostream *a2)

void  CRomanWarShip::Store(std::ostream &) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  CWarShip::Store(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x15a2420]
// Decompiled from void __thiscall CRomanWarShip::~CRomanWarShip(CRomanWarShip *this)

 CRomanWarShip::~CRomanWarShip(void) {
  
  CWarShip::~CWarShip(this);
}


// address=[0x15a26c0]
// Decompiled from int __thiscall CRomanWarShip::ClassID(CRomanWarShip *this)

unsigned long  CRomanWarShip::ClassID(void)const {
  
  return CRomanWarShip::m_iClassID;
}


// address=[0x3d8bfe4]
// [Decompilation failed for static unsigned long CRomanWarShip::m_iClassID]

// address=[0x15a1990]
// Decompiled from CRomanWarShip *__thiscall CRomanWarShip::CRomanWarShip(
        CRomanWarShip *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        bool a8)

 CRomanWarShip::CRomanWarShip(int,int,int,int,int,int,bool) {
  
  CWarShip::CWarShip(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CRomanWarShip::_vftable_;
  *((_DWORD *)this + 43) = &CRomanWarShip::`vftable';
  return this;
}


