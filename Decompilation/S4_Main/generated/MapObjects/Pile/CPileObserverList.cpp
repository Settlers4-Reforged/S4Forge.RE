#include "CPileObserverList.h"

// Definitions for class CPileObserverList

// address=[0x155e620]
// Decompiled from CPileObserverList *__thiscall CPileObserverList::CPileObserverList(CPileObserverList *this)
 CPileObserverList::CPileObserverList(void) {
  
  CPileObserverList::Clear(this);
  return this;
}


// address=[0x155e7f0]
// Decompiled from void __thiscall CPileObserverList::NotifyAndDetachAllObservers(CPileObserverList *this, const struct CEntityEvent *a2)
void  CPileObserverList::NotifyAndDetachAllObservers(class CEntityEvent const & a2) {
  
  CPileObserverList::NotifyAllObservers(this, a2);
  CPileObserverList::DetachAllObservers(this);
}


// address=[0x155e820]
// Decompiled from int __thiscall CPileObserverList::NumberOfObservers(CPileObserverList *this)
int  CPileObserverList::NumberOfObservers(void)const {
  
  return *((unsigned __int8 *)this + 32);
}


// address=[0x155e840]
// Decompiled from CPileObserverList *__thiscall CPileObserverList::Observers(CPileObserverList *this)
struct SPileObserver const *  CPileObserverList::Observers(void)const {
  
  return this;
}


// address=[0x1560500]
// Decompiled from int __thiscall CPileObserverList::Attach(unsigned __int8 *this, int a2, int a3, int a4, int a5)
void  CPileObserverList::Attach(enum T_OBSERVER_TARGET a2, int a3, int a4, int a5) {
  
  int v6; // [esp+0h] [ebp-8h]

  if ( a3 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 28, "_iTargetId > 0") == 1 )
    __debugbreak();
  if ( a4 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 29, "_iObserverId > 0") == 1 )
    __debugbreak();
  if ( a4 > 0xFFFF && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 30, "_iObserverId <= 0xFFFF") == 1 )
    __debugbreak();
  if ( (a5 < -8 || a5 > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\PileObserverList.cpp",
         32,
         "(_iDeltaAmount >= -8) && (_iDeltaAmount <= 8)") == 1 )
  {
    __debugbreak();
  }
  if ( !a5 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 33, "_iDeltaAmount != 0") == 1 )
    __debugbreak();
  if ( (int)CPileObserverList::GetIndex((CPileObserverList *)this, a4) >= 0
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 35, "GetIndex(_iObserverId) < 0") == 1 )
  {
    __debugbreak();
  }
  if ( this[32] >= 8u
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 37, "m_uNumberOfObservers < PILE_OBSERVERS_MAX") == 1 )
  {
    __debugbreak();
  }
  *(_WORD *)&this[4 * this[32]] = a4;
  this[4 * this[32] + 2] = a5;
  this[4 * this[32]++ + 3] = a2;
  v6 = CMapObjectMgr::EntityPtr(a4);
  if ( !v6 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 47, "pObserver != 0") == 1 )
    __debugbreak();
  if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 72))(v6, a2)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\PileObserverList.cpp",
         49,
         "pObserver->GetObserverTarget(_tTargetType) == 0") == 1 )
  {
    __debugbreak();
  }
  (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v6 + 68))(v6, a2, a3);
  if ( !(*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 72))(v6, a2)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\PileObserverList.cpp",
         53,
         "pObserver->GetObserverTarget(_tTargetType) != 0") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x1560710]
// Decompiled from int __thiscall CPileObserverList::Detach(CPileObserverList *this, int a2)
int  CPileObserverList::Detach(int a2) {
  
  int v3; // [esp+0h] [ebp-1Ch]
  int v4; // [esp+4h] [ebp-18h]
  int Index; // [esp+Ch] [ebp-10h]
  int v6; // [esp+10h] [ebp-Ch]
  unsigned __int8 v8; // [esp+1Bh] [ebp-1h]

  if ( a2 <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 63, "_iObserverId > 0") == 1 )
    __debugbreak();
  v3 = 0;
  Index = CPileObserverList::GetIndex(this, a2);
  if ( Index < 0 )
  {
    if ( BBSupportDbgReportF(
           1,
           "MapObjects\\Pile\\PileObserverList.cpp",
           98,
           "CPileObserverList::Detach(): Observer %i not in list!",
           a2) == 1 )
      __debugbreak();
  }
  else
  {
    if ( !*((_BYTE *)this + 32)
      && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 71, "m_uNumberOfObservers > 0") == 1 )
    {
      __debugbreak();
    }
    v8 = *((_BYTE *)this + 32) - 1;
    *((_BYTE *)this + 32) = v8;
    if ( Index > v8
      && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 75, "iIndex <= iNewNumberOfObservers") == 1 )
    {
      __debugbreak();
    }
    v3 = *((char *)this + 4 * Index + 2);
    v4 = *((unsigned __int8 *)this + 4 * Index + 3);
    if ( Index < v8 )
      *((_DWORD *)this + Index) = *((_DWORD *)this + v8);
    v6 = CMapObjectMgr::EntityPtr(a2);
    if ( !v6 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 88, "pObserver != 0") == 1 )
      __debugbreak();
    if ( !(*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 72))(v6, v4)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Pile\\PileObserverList.cpp",
           90,
           "pObserver->GetObserverTarget(tTargetType) != 0") == 1 )
    {
      __debugbreak();
    }
    (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v6 + 68))(v6, v4, 0);
    if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 72))(v6, v4)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Pile\\PileObserverList.cpp",
           94,
           "pObserver->GetObserverTarget(tTargetType) == 0") == 1 )
    {
      __debugbreak();
    }
  }
  return v3;
}


// address=[0x15608e0]
// Decompiled from int __thiscall CPileObserverList::NotifyAllObservers(CPileObserverList *this, const struct CEntityEvent *a2)
void  CPileObserverList::NotifyAllObservers(class CEntityEvent const & a2)const {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-18h]
  int v4; // [esp+4h] [ebp-14h]
  int v6; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  v3 = *((unsigned __int8 *)this + 32);
  for ( i = 0; ; ++i )
  {
    result = i;
    if ( i >= v3 )
      break;
    v6 = *((unsigned __int16 *)this + 2 * i);
    if ( *((_WORD *)this + 2 * i) )
      v4 = CMapObjectMgr::EntityPtr(v6);
    else
      v4 = 0;
    if ( v4 )
    {
      (*(void (__thiscall **)(int, const struct CEntityEvent *))(*(_DWORD *)v4 + 80))(v4, a2);
    }
    else if ( BBSupportDbgReportF(
                1,
                "MapObjects\\Pile\\PileObserverList.cpp",
                125,
                "CPileObserverList::NotifyAllObservers(): Invalid observer %i in list!",
                v6) == 1 )
    {
      __debugbreak();
    }
  }
  return result;
}


// address=[0x1560990]
// Decompiled from void __thiscall CPileObserverList::DetachAllObservers(CPileObserverList *this)
void  CPileObserverList::DetachAllObservers(void) {
  
  int v1; // [esp+0h] [ebp-1Ch]
  int v2; // [esp+4h] [ebp-18h]
  int v3; // [esp+8h] [ebp-14h]
  int v4; // [esp+Ch] [ebp-10h]
  int i; // [esp+14h] [ebp-8h]

  v1 = *((unsigned __int8 *)this + 32);
  for ( i = 0; i < v1; ++i )
  {
    v3 = *((unsigned __int16 *)this + 2 * i);
    if ( *((_WORD *)this + 2 * i) )
      v2 = CMapObjectMgr::EntityPtr(v3);
    else
      v2 = 0;
    if ( v2 )
    {
      v4 = *((unsigned __int8 *)this + 4 * i + 3);
      if ( !(*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 72))(v2, v4)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Pile\\PileObserverList.cpp",
             149,
             "pObserver->GetObserverTarget(tTargetType) != 0") == 1 )
      {
        __debugbreak();
      }
      (*(void (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v2 + 68))(v2, v4, 0);
      if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 72))(v2, v4) )
      {
        if ( BBSupportDbgReport(
               2,
               "MapObjects\\Pile\\PileObserverList.cpp",
               153,
               "pObserver->GetObserverTarget(tTargetType) == 0") == 1 )
          __debugbreak();
      }
    }
    else if ( BBSupportDbgReportF(
                1,
                "MapObjects\\Pile\\PileObserverList.cpp",
                157,
                "CPileObserverList::DetachAllObservers(): Invalid observer %i in list!",
                v3) == 1 )
    {
      __debugbreak();
    }
  }
  CPileObserverList::Clear(this);
}


// address=[0x1560b50]
// Decompiled from CPileObserverList *__thiscall CPileObserverList::CPileObserverList(CPileObserverList *this, int a2)
 CPileObserverList::CPileObserverList(std::istream & a2) {
  
  int v3; // [esp+4h] [ebp-10h] BYREF
  int pExceptionObject; // [esp+8h] [ebp-Ch] BYREF
  unsigned int i; // [esp+Ch] [ebp-8h]
  CPileObserverList *v6; // [esp+10h] [ebp-4h]

  v6 = this;
  CPileObserverList::Clear(this);
  operator^<unsigned int>(a2, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPileObserverList");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(a2, (char *)v6 + 32);
  if ( *((unsigned __int8 *)v6 + 32) > 8u
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\PileObserverList.cpp",
         215,
         "m_uNumberOfObservers <= PILE_OBSERVERS_MAX") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0; i < *((unsigned __int8 *)v6 + 32); ++i )
  {
    operator^<unsigned short>(a2, (char *)v6 + 4 * i);
    operator^<signed char>(a2, (char *)v6 + 4 * i + 2);
    operator^<unsigned char>(a2, (char *)v6 + 4 * i + 3);
  }
  return v6;
}


// address=[0x1560c60]
// Decompiled from unsigned int __thiscall CPileObserverList::Store(__int16 *this, struct std::ostream *a2)
void  CPileObserverList::Store(std::ostream & a2) {
  
  unsigned int result; // eax
  int v3; // [esp+0h] [ebp-Ch] BYREF
  __int16 *v4; // [esp+4h] [ebp-8h]
  unsigned int i; // [esp+8h] [ebp-4h]

  v4 = this;
  v3 = 1;
  operator^<unsigned int>(a2, &v3);
  operator^<unsigned char>(a2, (int)(v4 + 16));
  for ( i = 0; ; ++i )
  {
    result = *((unsigned __int8 *)v4 + 32);
    if ( i >= result )
      break;
    operator^<unsigned short>((int)a2, &v4[2 * i]);
    operator^<signed char>(a2, &v4[2 * i + 1]);
    operator^<unsigned char>(a2, (int)&v4[2 * i + 1] + 1);
  }
  return result;
}


// address=[0x1560ad0]
// Decompiled from void *__thiscall CPileObserverList::Clear(CPileObserverList *this)
void  CPileObserverList::Clear(void) {
  
  void *result; // eax

  result = memset(this, 0, 0x20u);
  *((_BYTE *)this + 32) = 0;
  return result;
}


// address=[0x1560b00]
// Decompiled from int __thiscall CPileObserverList::GetIndex(CPileObserverList *this, int a2)
int  CPileObserverList::GetIndex(int a2)const {
  
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < *((unsigned __int8 *)this + 32); ++i )
  {
    if ( *((unsigned __int16 *)this + 2 * i) == a2 )
      return i;
  }
  return -1;
}


