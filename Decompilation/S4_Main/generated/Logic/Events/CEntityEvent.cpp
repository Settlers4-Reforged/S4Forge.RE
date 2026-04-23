#if FALSE
#include "CEntityEvent.h"

// Definitions for class CEntityEvent

// address=[0x130e350]
// Decompiled from void __thiscall CEntityEvent::CEntityEvent(CEntityEvent *this, unsigned __int8 a2, int a3, int a4, int a5, int a6)
 CEntityEvent::CEntityEvent(unsigned char a2, int a3, int a4, int a5, int a6) {
  
  CPersistence::CPersistence(&this->CPersistence);
  this->__vftable = (CEntityEvent_vtbl *)&CEntityEvent::_vftable_;
  this->m_iEvent = a2;
  this->m_iType = a3;
  this->m_iDataA = a4;
  this->m_iDataB = a5;
  this->m_iDataC = a6;
}


// address=[0x130e430]
// Decompiled from void __thiscall CEntityEvent::~CEntityEvent(CEntityEvent *this)
 CEntityEvent::~CEntityEvent(void) {
  
  this->__vftable = (CPersistence_vtbl *)&CEntityEvent::_vftable_;
}


// address=[0x130e9d0]
// Decompiled from int __thiscall CEntityEvent::ClassID(CEntityEvent *this)
unsigned long  CEntityEvent::ClassID(void)const {
  
  return CEntityEvent::m_iClassID;
}


// address=[0x1400720]
// Decompiled from CEntityEvent *__cdecl CEntityEvent::New(int a1)
class CPersistence * __cdecl CEntityEvent::New(std::istream & a1) {
  
  CEntityEvent *C; // [esp+Ch] [ebp-10h]

  C = (CEntityEvent *)operator new(0x18u);
  if ( C )
    return CEntityEvent::CEntityEvent(C, a1);
  else
    return 0;
}


// address=[0x14e44e0]
// Decompiled from CEntityEvent *__thiscall CEntityEvent::CEntityEvent(CEntityEvent *this, CEntityEvent *a2)
 CEntityEvent::CEntityEvent(class CEntityEvent const & a2) {
  
  CPersistence::CPersistence(this);
  this->__vftable = (CPersistence_vtbl *)&CEntityEvent::_vftable_;
  this->m_iEvent = a2->m_iEvent;
  this->m_iType = a2->m_iType;
  this->m_iDataA = a2->m_iDataA;
  this->m_iDataB = a2->m_iDataB;
  this->m_iDataC = a2->m_iDataC;
  return this;
}


// address=[0x14e46f0]
// Decompiled from _DWORD *__thiscall CEntityEvent::operator=(_DWORD *this, _DWORD *a2)
class CEntityEvent &  CEntityEvent::operator=(class CEntityEvent const & a2) {
  
  CPersistence::operator=(a2);
  this[1] = a2[1];
  this[2] = a2[2];
  this[3] = a2[3];
  this[4] = a2[4];
  this[5] = a2[5];
  return this;
}


// address=[0x14e4b20]
// Decompiled from int __cdecl CEntityEvent::Load(struct std::istream *a1)
class CEntityEvent * __cdecl CEntityEvent::Load(std::istream & a1) {
  
  void **v1; // eax

  v1 = (void **)CPersistence::New(a1);
  return j____RTDynamicCast(v1, 0, &CPersistence__RTTI_Type_Descriptor_, &CEntityEvent__RTTI_Type_Descriptor_, 1);
}


// address=[0x154c110]
// Decompiled from CEntityEvent *__thiscall CEntityEvent::CEntityEvent(CEntityEvent *this, struct std::istream *a1)
 CEntityEvent::CEntityEvent(std::istream & a2) {
  
  int v3; // [esp+4h] [ebp-Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-8h] BYREF

  CPersistence::CPersistence(this);
  this->__vftable = (CPersistence_vtbl *)&CEntityEvent::_vftable_;
  operator^<unsigned int>(a1, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CEntityEvent");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<int>(a1, &this->m_iEvent);
  operator^<int>(a1, &this->m_iType);
  operator^<int>(a1, &this->m_iDataA);
  operator^<int>(a1, &this->m_iDataB);
  operator^<int>(a1, &this->m_iDataC);
  return this;
}


// address=[0x154c1e0]
// Decompiled from void __thiscall CEntityEvent::Store(CEntityEvent *this, struct std::ostream *a2)
void  CEntityEvent::Store(std::ostream & a2) {
  
  int fileVersion; // [esp+0h] [ebp-8h] BYREF

  CPersistence::Store(this, a2);
  fileVersion = 1;
  operator^<unsigned int>(a2, &fileVersion);
  operator^<int>(a2, &this->m_iEvent);
  operator^<int>(a2, &this->m_iType);
  operator^<int>(a2, &this->m_iDataA);
  operator^<int>(a2, &this->m_iDataB);
  operator^<int>(a2, &this->m_iDataC);
}


// address=[0x3d8bb20]
// [Decompilation failed for static unsigned long CEntityEvent::m_iClassID]

#endif // Already implemented
