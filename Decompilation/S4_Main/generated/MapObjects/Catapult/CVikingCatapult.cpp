#include "CVikingCatapult.h"

// Definitions for class CVikingCatapult

// address=[0x14027a0]
// Decompiled from int __cdecl CVikingCatapult::New(int a1)
class CPersistence * __cdecl CVikingCatapult::New(std::istream & a1) {
  
  if ( CVikingCatapult::operator new(0xD8u) )
    return CVikingCatapult::CVikingCatapult(a1);
  else
    return 0;
}


// address=[0x153eeb0]
// Decompiled from unsigned int __cdecl CVikingCatapult::operator new(unsigned int a1)
void * __cdecl CVikingCatapult::operator new(unsigned int a1) {
  
  return CVehicleMgr::Alloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x153eed0]
// Decompiled from void __cdecl CVikingCatapult::operator delete(void *a1)
void __cdecl CVikingCatapult::operator delete(void * a1) {
  
  CVehicleMgr::Dealloc((CVehicleMgr *)&g_cVehicleMgr, a1);
}


// address=[0x153ef10]
// Decompiled from _DWORD *__thiscall CVikingCatapult::CVikingCatapult(_DWORD *this, int a2)
 CVikingCatapult::CVikingCatapult(std::istream & a2) {
  
  int v3; // [esp+8h] [ebp-18h] BYREF
  int pExceptionObject; // [esp+Ch] [ebp-14h] BYREF
  _DWORD *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v5 = this;
  CCatapult::CCatapult(a2);
  v6 = 0;
  *v5 = &CVikingCatapult::_vftable_;
  v5[45] = &CVikingCatapult::`vftable';
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CVikingCatapult");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v6 = -1;
  return v5;
}


// address=[0x153efd0]
// Decompiled from int __thiscall CVikingCatapult::Store(void *this, struct std::ostream *a2)
void  CVikingCatapult::Store(std::ostream & a2) {
  
  int v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = (int)this;
  CCatapult::Store(a2);
  v3[0] = 1;
  return operator^<unsigned int>(a2, v3);
}


// address=[0x153fb00]
// Decompiled from void __thiscall CVikingCatapult::~CVikingCatapult(CVikingCatapult *this)
 CVikingCatapult::~CVikingCatapult(void) {
  
  CCatapult::~CCatapult(this);
}


// address=[0x153fd80]
// Decompiled from int __thiscall CVikingCatapult::ClassID(CVikingCatapult *this)
unsigned long  CVikingCatapult::ClassID(void)const {
  
  return CVikingCatapult::m_iClassID;
}


// address=[0x153fdf0]
// Decompiled from void __thiscall CVikingCatapult::IncreaseAmmo(CVikingCatapult *this, int a2)
void  CVikingCatapult::IncreaseAmmo(int a2) {
  
  ;
}


// address=[0x3d8b874]
// [Decompilation failed for static unsigned long CVikingCatapult::m_iClassID]

// address=[0x153f010]
// Decompiled from CVikingCatapult *__thiscall CVikingCatapult::CVikingCatapult(  CVikingCatapult *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  bool a8)
 CVikingCatapult::CVikingCatapult(int a2, int a3, int a4, int a5, int a6, int a7, bool a8) {
  
  CCatapult::CCatapult(this, a2, a3, a4, a5, a6, a7, a8);
  *(_DWORD *)this = &CVikingCatapult::_vftable_;
  *((_DWORD *)this + 45) = &CVikingCatapult::`vftable';
  return this;
}


// address=[0x153f060]
// Decompiled from bool __thiscall CVikingCatapult::EnoughAmmo(CVikingCatapult *this)
bool  CVikingCatapult::EnoughAmmo(void)const {
  
  int v1; // eax
  unsigned int v4; // [esp+10h] [ebp-8h]

  if ( CStaticConfigVarInt::operator int(g_pMagicVikingWarmachineShotCost) <= 0 )
    v4 = 1;
  else
    v4 = CStaticConfigVarInt::operator int(g_pMagicVikingWarmachineShotCost);
  v1 = IEntity::OwnerId((unsigned __int8 *)this);
  return CMagic::GetCurrentManaAmount(v1) >= v4;
}


// address=[0x153f0d0]
// Decompiled from int __thiscall CVikingCatapult::AmmoAmount(CVikingCatapult *this)
unsigned int  CVikingCatapult::AmmoAmount(void)const {
  
  int v1; // eax
  unsigned int v4; // [esp+10h] [ebp-4h]

  if ( CStaticConfigVarInt::operator int(g_pMagicVikingWarmachineShotCost) <= 0 )
    v4 = 1;
  else
    v4 = CStaticConfigVarInt::operator int(g_pMagicVikingWarmachineShotCost);
  v1 = IEntity::OwnerId((unsigned __int8 *)this);
  return CMagic::GetCurrentManaAmount(v1) / v4;
}


// address=[0x153f130]
// Decompiled from void __thiscall CVikingCatapult::DecreaseAmmo(CVikingCatapult *this)
void  CVikingCatapult::DecreaseAmmo(void) {
  
  int v1; // eax

  v1 = IEntity::OwnerId((unsigned __int8 *)this);
  CMagic::DecreaseManaAfterWarmachineShot(v1);
}


