#include "CTrojanWarShip.h"

// Definitions for class CTrojanWarShip

// address=[0x1402700]
// Decompiled from int __cdecl CTrojanWarShip::New(int a1)

static class CPersistence * __cdecl CTrojanWarShip::New(std::istream &) {
  
  if ( CWarShip::operator new(0xC8u) )
    return CTrojanWarShip::CTrojanWarShip(a1);
  else
    return 0;
}


// address=[0x15a1d70]
// Decompiled from _DWORD *__thiscall CTrojanWarShip::CTrojanWarShip(_DWORD *this, int a2)

 CTrojanWarShip::CTrojanWarShip(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CWarShip::CWarShip(a2);
  v6 = 0;
  *v5 = &CTrojanWarShip::_vftable_;
  v5[43] = &CTrojanWarShip::`vftable';
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CTrojanWarShip");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x15a1e30]
// Decompiled from int __thiscall CTrojanWarShip::Store(void *this, struct std::ostream *a2)

void  CTrojanWarShip::Store(std::ostream &) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  CWarShip::Store(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x15a2440]
// Decompiled from void __thiscall CTrojanWarShip::~CTrojanWarShip(CTrojanWarShip *this)

 CTrojanWarShip::~CTrojanWarShip(void) {
  
  CWarShip::~CWarShip(this);
}


// address=[0x15a26e0]
// Decompiled from int __thiscall CTrojanWarShip::ClassID(CTrojanWarShip *this)

unsigned long  CTrojanWarShip::ClassID(void)const {
  
  return CTrojanWarShip::m_iClassID;
}


// address=[0x3d8bff0]
// [Decompilation failed for static unsigned long CTrojanWarShip::m_iClassID]

// address=[0x15a1e70]
// Decompiled from CTrojanWarShip *__thiscall CTrojanWarShip::CTrojanWarShip(
        CTrojanWarShip *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        bool a8)

 CTrojanWarShip::CTrojanWarShip(int,int,int,int,int,int,bool) {
  
  CWarShip::CWarShip(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CTrojanWarShip::_vftable_;
  *((_DWORD *)this + 43) = &CTrojanWarShip::`vftable';
  return this;
}


