#include "CBBObject.h"

// Definitions for class CBBObject

// address=[0x2f337e0]
// Decompiled from CBBObject *__thiscall CBBObject::CBBObject(CBBObject *this, int a2, char a3)

 CBBObject::CBBObject(char const *,bool) {
  
  *(_DWORD *)this = &CBBObject::_vftable_;
  CBBObjectTracer::Enter();
  CBBObjectTracer::InitObject((int)this, a2, a3);
  if ( CBBObjectTracer::m_iNumberOfObjects == 1 )
    BBSupportTracePrintF(
      0,
      "%06x-%08x: %s created (%i object%s).",
      *((_DWORD *)this + 1),
      this,
      *((const char **)this + 2),
      1,
      (const char *)&unk_3ABA7F7);
  else
    BBSupportTracePrintF(
      0,
      "%06x-%08x: %s created (%i object%s).",
      *((_DWORD *)this + 1),
      this,
      *((const char **)this + 2),
      CBBObjectTracer::m_iNumberOfObjects,
      "s");
  CBBObjectTracer::Leave();
  return this;
}


// address=[0x2f33860]
// Decompiled from // public: __thiscall CBBObject::CBBObject(class CBBObject const &)
_DWORD *__thiscall CBBObject::CBBObject_0(_DWORD *this, int a2)

 CBBObject::CBBObject(class CBBObject const &) {
  
  int v2; // ecx

  *this = &CBBObject::_vftable_;
  CBBObjectTracer::Enter();
  CBBObjectTracer::InitObject((int)this, *(_DWORD *)(a2 + 8), *(_DWORD *)(a2 + 4) != -1);
  if ( CBBObjectTracer::m_iNumberOfObjects == 1 )
    BBSupportTracePrintF(
      0,
      "%06x-%08x: %s created as copy of %06x-%08x (%i object%s).",
      this[1],
      this,
      (const char *)this[2],
      *(_DWORD *)(a2 + 4),
      a2,
      1,
      (const char *)&unk_3ABA812);
  else
    BBSupportTracePrintF(
      0,
      "%06x-%08x: %s created as copy of %06x-%08x (%i object%s).",
      this[1],
      this,
      (const char *)this[2],
      *(_DWORD *)(a2 + 4),
      a2,
      CBBObjectTracer::m_iNumberOfObjects,
      "s");
  CBBObjectTracer::Leave(v2);
  return this;
}


// address=[0x2f33900]
// Decompiled from CBBObject *__thiscall CBBObject::~CBBObject(CBBObject *this)

 CBBObject::~CBBObject(void) {
  
  CBBObject *result; // eax
  int v2; // ecx
  struct CBBObject *v3; // [esp+8h] [ebp-18h] BYREF
  CBBObject *v4; // [esp+Ch] [ebp-14h]

  v4 = this;
  result = this;
  *(_DWORD *)this = &CBBObject::_vftable_;
  if ( *((_DWORD *)v4 + 1) == -1 )
    return result;
  CBBObjectTracer::Enter();
  v3 = 0;
  if ( CBBObjectTracer::IsObjectInList(*((_DWORD *)v4 + 1), &v3) )
  {
    if ( v3 )
      *((_DWORD *)v3 + 3) = *((_DWORD *)v4 + 3);
    else
      CBBObjectTracer::m_pObjectFirst = *((_DWORD *)v4 + 3);
    if ( --CBBObjectTracer::m_iNumberOfObjects == 1 )
      BBSupportTracePrintF(
        0,
        "%06x-%08x: %s deleted (%i object%s remaining).",
        *((_DWORD *)v4 + 1),
        v4,
        *((const char **)v4 + 2),
        1,
        (const char *)&unk_3ABA813);
    else
      BBSupportTracePrintF(
        0,
        "%06x-%08x: %s deleted (%i object%s remaining).",
        *((_DWORD *)v4 + 1),
        v4,
        *((const char **)v4 + 2),
        CBBObjectTracer::m_iNumberOfObjects,
        "s");
    if ( !*((_DWORD *)v4 + 1) )
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
    BBSupportTracePrintF(0, "%06x-%08x: Illegal object delete!", *((_DWORD *)v4 + 1), v4);
    if ( BBSupportDbgReport(1, "ObjectTracer.cpp", 251, "Somebody tried to delete a none existing object!") == 1 )
      __debugbreak();
    v2 = 0;
  }
  return (CBBObject *)CBBObjectTracer::Leave(v2);
}


