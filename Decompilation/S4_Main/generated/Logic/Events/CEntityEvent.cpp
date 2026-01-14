#include "all_headers.h"

// Definitions for class CEntityEvent

// address=[0x130e350]
// Decompiled from CEntityEvent *__thiscall CEntityEvent::CEntityEvent(  CEntityEvent *this,  unsigned __int8 a2,  int a3,  int a4,  int a5,  int a6)
 CEntityEvent::CEntityEvent(unsigned char,int,int,int,int) {
  
  CPersistence::CPersistence(this);
  *(_DWORD *)this = &CEntityEvent::_vftable_;
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 2) = a3;
  *((_DWORD *)this + 3) = a4;
  *((_DWORD *)this + 4) = a5;
  *((_DWORD *)this + 5) = a6;
  return this;
}


// address=[0x130e430]
// Decompiled from CEntityEvent *__thiscall CEntityEvent::~CEntityEvent(CEntityEvent *this)
 CEntityEvent::~CEntityEvent(void) {
  
  CEntityEvent *result; // eax

  result = this;
  *(_DWORD *)this = &CEntityEvent::_vftable_;
  return result;
}


// address=[0x130e9d0]
// Decompiled from int __thiscall CEntityEvent::ClassID(CEntityEvent *this)
unsigned long  CEntityEvent::ClassID(void)const {
  
  return CEntityEvent::m_iClassID;
}


// address=[0x1400720]
// Decompiled from int __cdecl CEntityEvent::New(int a1)
static class CPersistence * __cdecl CEntityEvent::New(std::istream &) {
  
  if ( operator new(0x18u) )
    return CEntityEvent::CEntityEvent(a1);
  else
    return 0;
}


// address=[0x14e44e0]
// Decompiled from boost::exception_detail::clone_base *__thiscall CEntityEvent::CEntityEvent(  boost::exception_detail::clone_base *this,  struct boost::exception_detail::clone_base *a2)
 CEntityEvent::CEntityEvent(class CEntityEvent const &) {
  
  CPersistence::CPersistence(this, a2);
  *(_DWORD *)this = &CEntityEvent::_vftable_;
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 3);
  *((_DWORD *)this + 4) = *((_DWORD *)a2 + 4);
  *((_DWORD *)this + 5) = *((_DWORD *)a2 + 5);
  return this;
}


// address=[0x14e46f0]
// Decompiled from _DWORD *__thiscall CEntityEvent::operator=(_DWORD *this, _DWORD *a2)
class CEntityEvent &  CEntityEvent::operator=(class CEntityEvent const &) {
  
  CPersistence::operator=(a2);
  this[1] = a2[1];
  this[2] = a2[2];
  this[3] = a2[3];
  this[4] = a2[4];
  this[5] = a2[5];
  return this;
}


// address=[0x14e4b20]
// Decompiled from int __cdecl CEntityEvent::Load(int a1)
static class CEntityEvent * __cdecl CEntityEvent::Load(std::istream &) {
  
  void **v1; // eax
  struct TypeDescriptor *v3; // [esp-Ch] [ebp-Ch]

  v1 = (void **)CPersistence::New(a1, &CPersistence__RTTI_Type_Descriptor_);
  return j____RTDynamicCast(v1, 0, v3, &CEntityEvent__RTTI_Type_Descriptor_, 1);
}


// address=[0x154c110]
// Decompiled from _DWORD *__thiscall CEntityEvent::CEntityEvent(_DWORD *this, int a2)
 CEntityEvent::CEntityEvent(std::istream &) {
  
  int v3; // [esp+4h] [ebp-Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-8h] BYREF
  _DWORD *v5; // [esp+Ch] [ebp-4h]

  v5 = this;
  CPersistence::CPersistence(this);
  *v5 = &CEntityEvent::_vftable_;
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CEntityEvent");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a2, (int)(v5 + 1));
  operator^<int>(a2, (int)(v5 + 2));
  operator^<int>(a2, (int)(v5 + 3));
  operator^<int>(a2, (int)(v5 + 4));
  operator^<int>(a2, (int)(v5 + 5));
  return v5;
}


// address=[0x154c1e0]
// Decompiled from int __thiscall CEntityEvent::Store(struct CPersistence *this, struct std::ostream *a2)
void  CEntityEvent::Store(std::ostream &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  int *v4; // [esp+4h] [ebp-4h]

  v4 = (int *)this;
  CPersistence::Store(this, a2);
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<int>((int)a2, v4 + 1);
  operator^<int>((int)a2, v4 + 2);
  operator^<int>((int)a2, v4 + 3);
  operator^<int>((int)a2, v4 + 4);
  return operator^<int>((int)a2, v4 + 5);
}


// address=[0x3d8bb20]
// [Decompilation failed for static unsigned long CEntityEvent::m_iClassID]

