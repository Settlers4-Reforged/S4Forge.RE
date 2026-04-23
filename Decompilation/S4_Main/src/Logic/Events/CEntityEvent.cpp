#include "CEntityEvent.h"

#include <istream>
#include <ostream>

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"

// Definitions for class CEntityEvent

// address=[0x130e350]
// Decompiled from void __thiscall CEntityEvent::CEntityEvent(CEntityEvent *this, unsigned __int8 a2, int a3, int a4, int a5, int a6)
CEntityEvent::CEntityEvent(unsigned char a2, int a3, int a4, int a5, int a6) : CPersistence()
{
  this->m_iEvent = a2;
  this->m_iType = a3;
  this->m_iDataA = a4;
  this->m_iDataB = a5;
  this->m_iDataC = a6;
}

// address=[0x130e430]
// Decompiled from void __thiscall CEntityEvent::~CEntityEvent(CEntityEvent *this)
CEntityEvent::~CEntityEvent(void){}

// address=[0x130e9d0]
// Decompiled from int __thiscall CEntityEvent::ClassID(CEntityEvent *this)
unsigned long CEntityEvent::ClassID(void) const
{
  return CEntityEvent::m_iClassID;
}

// address=[0x1400720]
// Decompiled from CEntityEvent *__cdecl CEntityEvent::New(int a1)
class CPersistence *__cdecl CEntityEvent::New(std::istream &a1)
{
  return new CEntityEvent(a1);
}

// address=[0x14e44e0]
// Decompiled from CEntityEvent *__thiscall CEntityEvent::CEntityEvent(CEntityEvent *this, CEntityEvent *a2)
CEntityEvent::CEntityEvent(class CEntityEvent const &a2) : CPersistence()
{
  this->m_iEvent = a2.m_iEvent;
  this->m_iType = a2.m_iType;
  this->m_iDataA = a2.m_iDataA;
  this->m_iDataB = a2.m_iDataB;
  this->m_iDataC = a2.m_iDataC;
}

// address=[0x14e46f0]
// Decompiled from _DWORD *__thiscall CEntityEvent::operator=(_DWORD *this, _DWORD *a2)
class CEntityEvent &CEntityEvent::operator=(class CEntityEvent const &a2)
{
  CPersistence::operator=(a2);
  this->m_iEvent = a2.m_iEvent;
  this->m_iType = a2.m_iType;
  this->m_iDataA = a2.m_iDataA;
  this->m_iDataB = a2.m_iDataB;
  this->m_iDataC = a2.m_iDataC;
  return *this;
}

// address=[0x14e4b20]
// Decompiled from int __cdecl CEntityEvent::Load(struct std::istream *a1)
class CEntityEvent *__cdecl CEntityEvent::Load(std::istream &a1)
{
  return new CEntityEvent(a1);
}

// address=[0x154c110]
// Decompiled from CEntityEvent *__thiscall CEntityEvent::CEntityEvent(CEntityEvent *this, struct std::istream *a1)
CEntityEvent::CEntityEvent(std::istream &stream) : CPersistence()
{

  int v3;               // [esp+4h] [ebp-Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-8h] BYREF

  stream >> v3;
  if (v3 != 1)
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CEntityEvent");
    throw new CS4InvalidMapException();
  }
  stream >> this->m_iEvent;
  stream >> this->m_iType;
  stream >> this->m_iDataA;
  stream >> this->m_iDataB;
  stream >> this->m_iDataC;
}

// address=[0x154c1e0]
// Decompiled from void __thiscall CEntityEvent::Store(CEntityEvent *this, struct std::ostream *a2)
void CEntityEvent::Store(std::ostream &stream)
{

  int fileVersion; // [esp+0h] [ebp-8h] BYREF

  this->Store(stream);
  fileVersion = 1;
  stream << fileVersion;
  stream << this->m_iEvent;
  stream << this->m_iType;
  stream << this->m_iDataA;
  stream << this->m_iDataB;
  stream << this->m_iDataC;
}

// address=[0x3d8bb20]
// [Decompilation failed for static unsigned long CEntityEvent::m_iClassID]
