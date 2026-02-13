#include "CBBObject.h"
#include "./CBBObjectTracer.h"

#include "CBBSupport.h"

// Definitions for class CBBObject

// address=[0x2f337e0]
// Decompiled from CBBObject *__thiscall CBBObject::CBBObject(CBBObject *this, int a2, char a3)
CBBObject::CBBObject(char const *_spType, bool _bFirst)
{
  CBBObjectTracer::Enter();
  CBBObjectTracer::InitObject(*this, _spType, _bFirst);
  if (CBBObjectTracer::m_iNumberOfObjects == 1)
    BBSupportTracePrintF(
        0,
        "%06x-%08x: %s created (%i object%s).",
        this->m_uSerialNumber,
        this,
        this->m_spType,
        1,
        "");
  else
    BBSupportTracePrintF(
        0,
        "%06x-%08x: %s created (%i object%s).",
        this->m_uSerialNumber,
        this,
        this->m_spType,
        CBBObjectTracer::m_iNumberOfObjects,
        "s");
  CBBObjectTracer::Leave();
}

// address=[0x2f33860]
// Decompiled from _DWORD *__thiscall CBBObject::CBBObject_0(_DWORD *this, int a2)
CBBObject::CBBObject(class CBBObject const &a2)
{
  CBBObjectTracer::Enter();
  CBBObjectTracer::InitObject(*this, a2.m_spType, a2.m_uSerialNumber != -1);
  if (CBBObjectTracer::m_iNumberOfObjects == 1)
    BBSupportTracePrintF(
        0,
        "%06x-%08x: %s created as copy of %06x-%08x (%i object%s).",
        this->m_uSerialNumber,
        this,
        this->m_spType,
        a2.m_uSerialNumber,
        &a2,
        1,
        "");
  else
    BBSupportTracePrintF(
        0,
        "%06x-%08x: %s created as copy of %06x-%08x (%i object%s).",
        this->m_uSerialNumber,
        this,
        this->m_spType,
        a2.m_uSerialNumber,
        &a2,
        CBBObjectTracer::m_iNumberOfObjects,
        "s");
  CBBObjectTracer::Leave();
}

// address=[0x2f33900]
// Decompiled from CBBObject *__thiscall CBBObject::~CBBObject(CBBObject *this)
CBBObject::~CBBObject(void)
{
  struct CBBObject *pInList; // [esp+8h] [ebp-18h] BYREF

  if (this->m_uSerialNumber == -1)
    return;

  CBBObjectTracer::Enter();
  pInList = 0;
  if (CBBObjectTracer::IsObjectInList(this->m_uSerialNumber, pInList))
  {
    if (pInList)
      pInList->m_pFirst = this->m_pFirst;
    else
      CBBObjectTracer::m_pObjectFirst = this->m_pFirst;
    if (--CBBObjectTracer::m_iNumberOfObjects == 1)
      BBSupportTracePrintF(
          0,
          "%06x-%08x: %s deleted (%i object%s remaining).",
          this->m_uSerialNumber,
          this,
          this->m_spType,
          1,
          "");
    else
      BBSupportTracePrintF(
          0,
          "%06x-%08x: %s deleted (%i object%s remaining).",
          this->m_uSerialNumber,
          this,
          this->m_spType,
          CBBObjectTracer::m_iNumberOfObjects,
          "s");
    if (!this->m_uSerialNumber)
    {
      if (CBBObjectTracer::m_iNumberOfObjects)
      {
        BBSupportTracePrint(0, "");
        BBSupportTracePrint(0, "Warning: Missing delete!");
        BBSupportTracePrint(0, "");
        CBBObjectTracer::DumpObjects();
        BBSupportTracePrint(0, "");
      }
      else
      {
        BBSupportTracePrint(0, "Object balance ok.");
      }
    }
  }
  else
  {
    BBSupportTracePrintF(0, "%06x-%08x: Illegal object delete!", this->m_uSerialNumber, this);
    if (BBSupportDbgReport(1, "ObjectTracer.cpp", 251, "Somebody tried to delete a none existing object!") == 1)
      __debugbreak();
  }
  CBBObjectTracer::Leave();
}
