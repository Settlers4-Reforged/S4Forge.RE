#include "CBBObjectTracer.h"

// Definitions for class CBBObjectTracer

// address=[0x2f33a90]
// Decompiled from void CBBObjectTracer::Enter()
void __cdecl CBBObjectTracer::Enter(void) {
  
  if ( !CBBObjectTracer::m_uCurrentSerialNumber )
  {
    CBBObjectTracer::m_uCurrentSerialNumber = 1;
    InitializeCriticalSection(&CBBObjectTracer::m_sCriticalSection);
  }
  EnterCriticalSection(&CBBObjectTracer::m_sCriticalSection);
}


// address=[0x2f33ad0]
// Decompiled from void __cdecl CBBObjectTracer::InitObject(CBBObject *this, char *_sType, bool _bFirst)
void __cdecl CBBObjectTracer::InitObject(class CBBObject & _sType, char const * _bFirst, bool a3) {
  
  char *type; // [esp+0h] [ebp-4h]

  if ( _sType && *_sType )
    type = _sType;
  else
    type = "Object of unknown type";
  this->m_spType = type;
  if ( _bFirst )
  {
    this->m_uSerialNumber = CBBObjectTracer::m_uCurrentSerialNumber;
    this->m_pFirst = CBBObjectTracer::m_pObjectFirst;
    ++CBBObjectTracer::m_uCurrentSerialNumber;
    ++CBBObjectTracer::m_iNumberOfObjects;
    CBBObjectTracer::m_pObjectFirst = this;
  }
  else
  {
    this->m_uSerialNumber = -1;
    this->m_pFirst = 0;
  }
}


// address=[0x2f33b70]
// Decompiled from char __cdecl CBBObjectTracer::IsObjectInList(unsigned int a1, struct CBBObject **a2)
bool __cdecl CBBObjectTracer::IsObjectInList(unsigned int a1, class CBBObject * & a2) {
  
  struct CBBObject *v3; // [esp+0h] [ebp-8h]
  int v4; // [esp+4h] [ebp-4h]

  v4 = CBBObjectTracer::m_pObjectFirst;
  v3 = 0;
  while ( v4 )
  {
    if ( *(_DWORD *)(v4 + 4) == a1 )
    {
      *a2 = v3;
      return 1;
    }
    v3 = (struct CBBObject *)v4;
    v4 = *(_DWORD *)(v4 + 12);
  }
  *a2 = 0;
  return 0;
}


// address=[0x2f33bd0]
// Decompiled from void CBBObjectTracer::DumpObjects()
void __cdecl CBBObjectTracer::DumpObjects(void) {
  
  const char *v0; // [esp+4h] [ebp-8h]
  _DWORD *i; // [esp+8h] [ebp-4h]

  if ( CBBObjectTracer::m_iNumberOfObjects == 1 )
    BBSupportTracePrint(0, "Object list (1 entry):");
  else
    BBSupportTracePrintF(0, "Object list (%i entries):", CBBObjectTracer::m_iNumberOfObjects);
  BBSupportTracePrint(0, (char *)&byte_3ABA7DF);
  for ( i = (_DWORD *)CBBObjectTracer::m_pObjectFirst; i; i = (_DWORD *)i[3] )
  {
    if ( i[2] )
      v0 = (const char *)i[2];
    else
      v0 = "Object of unknown type";
    BBSupportTracePrintF(0, "  %06x-%08x %s", i[1], i, v0);
  }
}


// address=[0x2f33dd0]
// Decompiled from void CBBObjectTracer::Leave()
void __cdecl CBBObjectTracer::Leave(void) {
  
  LeaveCriticalSection(&CBBObjectTracer::m_sCriticalSection);
}


// address=[0x4687170]
// [Decompilation failed for static unsigned int CBBObjectTracer::m_uCurrentSerialNumber]

// address=[0x4687174]
// [Decompilation failed for static int CBBObjectTracer::m_iNumberOfObjects]

// address=[0x4687178]
// [Decompilation failed for static class CBBObject * CBBObjectTracer::m_pObjectFirst]

// address=[0x468717c]
// [Decompilation failed for static struct _RTL_CRITICAL_SECTION CBBObjectTracer::m_sCriticalSection]

