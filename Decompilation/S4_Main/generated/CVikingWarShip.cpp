#include "all_headers.h"

// Definitions for class CVikingWarShip

// address=[0x1402840]
// Decompiled from int __cdecl CVikingWarShip::New(int a1)
static class CPersistence * __cdecl CVikingWarShip::New(std::istream &) {
  
  if ( CWarShip::operator new(0xC8u) )
    return CVikingWarShip::CVikingWarShip(a1);
  else
    return 0;
}


// address=[0x15a1b30]
// Decompiled from _DWORD *__thiscall CVikingWarShip::CVikingWarShip(_DWORD *this, int a2)
 CVikingWarShip::CVikingWarShip(std::istream &) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CWarShip::CWarShip(a2);
  v6 = 0;
  *v5 = &CVikingWarShip::_vftable_;
  v5[43] = &CVikingWarShip::`vftable';
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CVikingWarShip");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x15a1bf0]
// Decompiled from int __thiscall CVikingWarShip::Store(void *this, struct std::ostream *a2)
void  CVikingWarShip::Store(std::ostream &) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  CWarShip::Store(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x15a2460]
// Decompiled from void __thiscall CVikingWarShip::~CVikingWarShip(CVikingWarShip *this)
 CVikingWarShip::~CVikingWarShip(void) {
  
  CWarShip::~CWarShip(this);
}


// address=[0x15a2700]
// Decompiled from int __thiscall CVikingWarShip::ClassID(CVikingWarShip *this)
unsigned long  CVikingWarShip::ClassID(void)const {
  
  return CVikingWarShip::m_iClassID;
}


// address=[0x15a2740]
// Decompiled from void __thiscall CVikingWarShip::IncreaseAmmo(CVikingWarShip *this, int a2)
void  CVikingWarShip::IncreaseAmmo(int) {
  
  ;
}


// address=[0x3d8bfec]
// [Decompilation failed for static unsigned long CVikingWarShip::m_iClassID]

// address=[0x15a1c30]
// Decompiled from CVikingWarShip *__thiscall CVikingWarShip::CVikingWarShip(  CVikingWarShip *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  bool a8)
 CVikingWarShip::CVikingWarShip(int,int,int,int,int,int,bool) {
  
  CWarShip::CWarShip(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CVikingWarShip::_vftable_;
  *((_DWORD *)this + 43) = &CVikingWarShip::`vftable';
  return this;
}


// address=[0x15a1c80]
// Decompiled from bool __thiscall CVikingWarShip::EnoughAmmo(CVikingWarShip *this)
bool  CVikingWarShip::EnoughAmmo(void)const {
  
  int v1; // eax
  unsigned int v4; // [esp+10h] [ebp-8h]

  if ( CStaticConfigVarInt::operator int(g_pMagicVikingWarmachineShotCost) <= 0 )
    v4 = 1;
  else
    v4 = CStaticConfigVarInt::operator int(g_pMagicVikingWarmachineShotCost);
  v1 = IEntity::OwnerId((unsigned __int8 *)this);
  return CMagic::GetCurrentManaAmount(v1) >= v4;
}


// address=[0x15a1cf0]
// Decompiled from int __thiscall CVikingWarShip::AmmoAmount(CVikingWarShip *this)
unsigned int  CVikingWarShip::AmmoAmount(void)const {
  
  int v1; // eax
  unsigned int v4; // [esp+10h] [ebp-4h]

  if ( CStaticConfigVarInt::operator int(g_pMagicVikingWarmachineShotCost) <= 0 )
    v4 = 1;
  else
    v4 = CStaticConfigVarInt::operator int(g_pMagicVikingWarmachineShotCost);
  v1 = IEntity::OwnerId((unsigned __int8 *)this);
  return CMagic::GetCurrentManaAmount(v1) / v4;
}


// address=[0x15a1d50]
// Decompiled from void __thiscall CVikingWarShip::DecreaseAmmo(CVikingWarShip *this)
void  CVikingWarShip::DecreaseAmmo(void) {
  
  int v1; // eax

  v1 = IEntity::OwnerId((unsigned __int8 *)this);
  CMagic::DecreaseManaAfterWarmachineShot(v1);
}


