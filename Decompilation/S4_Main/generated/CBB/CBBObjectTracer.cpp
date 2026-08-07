#if FALSE
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
// Decompiled from void __cdecl CBBObjectTracer::InitObject(CBBObject *target, char *_sType, bool _bFirst)
void __cdecl CBBObjectTracer::InitObject(class CBBObject & target, char const * _sType, bool _bFirst) {
  
  char *type; // [esp+0h] [ebp-4h]

  if ( _sType && *_sType )
  {
    type = _sType;
  }
  else
  {
    type = "Object of unknown type";
  }
  target->m_spType = type;
  if ( _bFirst )
  {
    target->m_uSerialNumber = CBBObjectTracer::m_uCurrentSerialNumber;
    target->m_pFirst = CBBObjectTracer::m_pObjectFirst;
    ++CBBObjectTracer::m_uCurrentSerialNumber;
    ++CBBObjectTracer::m_iNumberOfObjects;
    CBBObjectTracer::m_pObjectFirst = target;
  }
  else
  {
    target->m_uSerialNumber = -1;
    target->m_pFirst = 0;
  }
}


// address=[0x2f33b70]
// Decompiled from bool __cdecl CBBObjectTracer::IsObjectInList(unsigned int _uSerialNumber, struct CBBObject **_pObject)
bool __cdecl CBBObjectTracer::IsObjectInList(unsigned int _uSerialNumber, class CBBObject * & _pObject) {
  
  struct CBBObject *v3; // [esp+0h] [ebp-8h]
  CBBObject *pIterator; // [esp+4h] [ebp-4h]

  pIterator = CBBObjectTracer::m_pObjectFirst;
  v3 = 0;
  while ( pIterator )
  {
    if ( pIterator->m_uSerialNumber == _uSerialNumber )
    {
      *_pObject = v3;
      return 1;
    }
    v3 = pIterator;
    pIterator = pIterator->m_pFirst;
  }
  *_pObject = 0;
  return 0;
}


// address=[0x2f33bd0]
// Decompiled from void CBBObjectTracer::DumpObjects()
void __cdecl CBBObjectTracer::DumpObjects(void) {
  
  const char *m_spType; // [esp+4h] [ebp-8h]
  CBBObject *i; // [esp+8h] [ebp-4h]

  if ( CBBObjectTracer::m_iNumberOfObjects == 1 )
  {
    BBSupportTracePrint(0, "Object list (1 entry):");
  }
  else
  {
    BBSupportTracePrintF(0, "Object list (%i entries):", CBBObjectTracer::m_iNumberOfObjects);
  }
  BBSupportTracePrint(0, (char *)&sEmpty7);
  for ( i = CBBObjectTracer::m_pObjectFirst;
        i;
        i = i->m_pFirst )
  {
    if ( i->m_spType )
    {
      m_spType = i->m_spType;
    }
    else
    {
      m_spType = "Object of unknown type";
    }
    BBSupportTracePrintF(0, "  %06x-%08x %s", i->m_uSerialNumber, i, m_spType);
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

#endif // Already implemented
