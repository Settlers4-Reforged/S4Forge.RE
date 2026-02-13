#if FALSE
#include "CBBObject.h"

// Definitions for class CBBObject

// address=[0x2f337e0]
// Decompiled from CBBObject *__thiscall CBBObject::CBBObject(CBBObject *this, int a2, char a3)
 CBBObject::CBBObject(char const * a2, bool a3) {
  
  this->vtable = &CBBObject::_vftable_;
  CBBObjectTracer::Enter();
  CBBObjectTracer::InitObject(this, a2, a3);
  if ( CBBObjectTracer::m_iNumberOfObjects == 1 )
    BBSupportTracePrintF(
      0,
      "%06x-%08x: %s created (%i object%s).",
      this->m_uSerialNumber,
      this,
      this->m_spType,
      1,
      (const char *)&sEmpty6);
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
  return this;
}


// address=[0x2f33860]
// Decompiled from CBBObject *__thiscall CBBObject::CBBObject_0(CBBObject *this, const struct CBBObject *a2)
 CBBObject::CBBObject(class CBBObject const & a2) {
  
  this->vtable = &CBBObject::_vftable_;
  CBBObjectTracer::Enter();
  CBBObjectTracer::InitObject(this, (int)a2->m_spType, a2->m_uSerialNumber != -1);
  if ( CBBObjectTracer::m_iNumberOfObjects == 1 )
    BBSupportTracePrintF(
      0,
      "%06x-%08x: %s created as copy of %06x-%08x (%i object%s).",
      this->m_uSerialNumber,
      this,
      this->m_spType,
      a2->m_uSerialNumber,
      a2,
      1,
      (const char *)&unk_3ABA812);
  else
    BBSupportTracePrintF(
      0,
      "%06x-%08x: %s created as copy of %06x-%08x (%i object%s).",
      this->m_uSerialNumber,
      this,
      this->m_spType,
      a2->m_uSerialNumber,
      a2,
      CBBObjectTracer::m_iNumberOfObjects,
      "s");
  CBBObjectTracer::Leave();
  return this;
}


// address=[0x2f33900]
// Decompiled from void __thiscall CBBObject::~CBBObject(CBBObject *this)
 CBBObject::~CBBObject(void) {
  
  struct CBBObject *v1; // [esp+8h] [ebp-18h] BYREF

  this->vtable = &CBBObject::_vftable_;
  if ( this->m_uSerialNumber != -1 )
  {
    CBBObjectTracer::Enter();
    v1 = 0;
    if ( CBBObjectTracer::IsObjectInList(this->m_uSerialNumber, &v1) )
    {
      if ( v1 )
        v1->m_pFirst = this->m_pFirst;
      else
        CBBObjectTracer::m_pObjectFirst = this->m_pFirst;
      if ( --CBBObjectTracer::m_iNumberOfObjects == 1 )
        BBSupportTracePrintF(
          0,
          "%06x-%08x: %s deleted (%i object%s remaining).",
          this->m_uSerialNumber,
          this,
          this->m_spType,
          1,
          (const char *)&unk_3ABA813);
      else
        BBSupportTracePrintF(
          0,
          "%06x-%08x: %s deleted (%i object%s remaining).",
          this->m_uSerialNumber,
          this,
          this->m_spType,
          CBBObjectTracer::m_iNumberOfObjects,
          "s");
      if ( !this->m_uSerialNumber )
      {
        if ( CBBObjectTracer::m_iNumberOfObjects )
        {
          BBSupportTracePrint(0, (char *)&byte_3ABA823);
          BBSupportTracePrint(0, "Warning: Missing delete!");
          BBSupportTracePrint(0, (char *)&byte_3ABA826);
          CBBObjectTracer::DumpObjects();
          BBSupportTracePrint(0, (char *)&byte_3ABA827);
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
      if ( BBSupportDbgReport(1, "ObjectTracer.cpp", 251, "Somebody tried to delete a none existing object!") == 1 )
        __debugbreak();
    }
    CBBObjectTracer::Leave();
  }
}


#endif // Already implemented
