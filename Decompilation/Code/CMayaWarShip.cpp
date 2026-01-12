#include "CMayaWarShip.h"

// Definitions for class CMayaWarShip

// address=[0x1401300]
// Decompiled from int __cdecl CMayaWarShip::New(int a1)

static class CPersistence * __cdecl CMayaWarShip::New(std::istream &) {
  
  if ( CWarShip::operator new(0xC8u) )
    return CMayaWarShip::CMayaWarShip(a1);
  else
    return 0;
}


// address=[0x15a19e0]
// Decompiled from _DWORD *__thiscall CMayaWarShip::CMayaWarShip(_DWORD *this, int a2)

 CMayaWarShip::CMayaWarShip(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CWarShip::CWarShip(a2);
  v6 = 0;
  *v5 = &CMayaWarShip::_vftable_;
  v5[43] = &CMayaWarShip::`vftable';
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CMayaWarShip");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x15a1aa0]
// Decompiled from int __thiscall CMayaWarShip::Store(void *this, struct std::ostream *a2)

void  CMayaWarShip::Store(std::ostream &) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  CWarShip::Store(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x15a2400]
// Decompiled from void __thiscall CMayaWarShip::~CMayaWarShip(CMayaWarShip *this)

 CMayaWarShip::~CMayaWarShip(void) {
  
  CWarShip::~CWarShip(this);
}


// address=[0x15a26a0]
// Decompiled from int __thiscall CMayaWarShip::ClassID(CMayaWarShip *this)

unsigned long  CMayaWarShip::ClassID(void)const {
  
  return CMayaWarShip::m_iClassID;
}


// address=[0x3d8bfe8]
// [Decompilation failed for static unsigned long CMayaWarShip::m_iClassID]

// address=[0x15a1ae0]
// Decompiled from CMayaWarShip *__thiscall CMayaWarShip::CMayaWarShip(
        CMayaWarShip *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        bool a8)

 CMayaWarShip::CMayaWarShip(int,int,int,int,int,int,bool) {
  
  CWarShip::CWarShip(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CMayaWarShip::_vftable_;
  *((_DWORD *)this + 43) = &CMayaWarShip::`vftable';
  return this;
}


// address=[0x15a2660]
// Decompiled from int __thiscall CMayaWarShip::AmmoPerPile(CMayaWarShip *this)

int const  CMayaWarShip::AmmoPerPile(void) {
  
  return 8;
}


