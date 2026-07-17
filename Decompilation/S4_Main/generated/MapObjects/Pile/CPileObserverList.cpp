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
  
  return this->m_uNumberOfObservers;
}


// address=[0x155e840]
// Decompiled from const struct SPileObserver *__thiscall CPileObserverList::Observers(CPileObserverList *this)
struct SPileObserver const *  CPileObserverList::Observers(void)const {
  
  return this->m_vPileObserver;
}


// address=[0x1560500]
// Decompiled from void __thiscall CPileObserverList::Attach(  CPileObserverList *this,  int _tTargetType,  int _iTargetId,  int _iObserverId,  int _iDeltaAmount)
void  CPileObserverList::Attach(enum T_OBSERVER_TARGET _tTargetType, int _iTargetId, int _iObserverId, int _iDeltaAmount) {
  
  IEntity *pObserver; // [esp+0h] [ebp-8h]

  if ( _iTargetId <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 28, "_iTargetId > 0") == 1 )
    __debugbreak();
  if ( _iObserverId <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 29, "_iObserverId > 0") == 1 )
    __debugbreak();
  if ( _iObserverId > 0xFFFF
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 30, "_iObserverId <= 0xFFFF") == 1 )
  {
    __debugbreak();
  }
  if ( (_iDeltaAmount < -8 || _iDeltaAmount > 8)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\PileObserverList.cpp",
         32,
         "(_iDeltaAmount >= -8) && (_iDeltaAmount <= 8)") == 1 )
  {
    __debugbreak();
  }
  if ( !_iDeltaAmount && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 33, "_iDeltaAmount != 0") == 1 )
    __debugbreak();
  if ( CPileObserverList::GetIndex(this, _iObserverId) >= 0
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 35, "GetIndex(_iObserverId) < 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_uNumberOfObservers >= 8u
    && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 37, "m_uNumberOfObservers < PILE_OBSERVERS_MAX") == 1 )
  {
    __debugbreak();
  }
  this->m_vPileObserver[this->m_uNumberOfObservers].m_iObserverId = _iObserverId;
  this->m_vPileObserver[this->m_uNumberOfObservers].m_iDeltaAmount = _iDeltaAmount;
  this->m_vPileObserver[this->m_uNumberOfObservers++].m_tTargetType = _tTargetType;
  pObserver = CMapObjectMgr::EntityPtr(_iObserverId);
  if ( !pObserver && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 47, "pObserver != 0") == 1 )
    __debugbreak();
  if ( pObserver->GetObserverTarget(pObserver, _tTargetType)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\PileObserverList.cpp",
         49,
         "pObserver->GetObserverTarget(_tTargetType) == 0") == 1 )
  {
    __debugbreak();
  }
  pObserver->SetObserverTarget(pObserver, _tTargetType, _iTargetId);
  if ( !pObserver->GetObserverTarget(pObserver, _tTargetType)
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\PileObserverList.cpp",
         53,
         "pObserver->GetObserverTarget(_tTargetType) != 0") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x1560710]
// Decompiled from int __thiscall CPileObserverList::Detach(CPileObserverList *this, int _iObserverId)
int  CPileObserverList::Detach(int _iObserverId) {
  
  int iDeltaAmount; // [esp+0h] [ebp-1Ch]
  int tTargetType; // [esp+4h] [ebp-18h]
  int iIndex; // [esp+Ch] [ebp-10h]
  IEntity *pObserver; // [esp+10h] [ebp-Ch]
  unsigned __int8 iNewNumberOfObservers; // [esp+1Bh] [ebp-1h]

  if ( _iObserverId <= 0 && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 63, "_iObserverId > 0") == 1 )
    __debugbreak();
  iDeltaAmount = 0;
  iIndex = CPileObserverList::GetIndex(this, _iObserverId);
  if ( iIndex < 0 )
  {
    if ( BBSupportDbgReportF(
           1,
           "MapObjects\\Pile\\PileObserverList.cpp",
           98,
           "CPileObserverList::Detach(): Observer %i not in list!",
           _iObserverId) == 1 )
      __debugbreak();
  }
  else
  {
    if ( !this->m_uNumberOfObservers
      && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 71, "m_uNumberOfObservers > 0") == 1 )
    {
      __debugbreak();
    }
    iNewNumberOfObservers = this->m_uNumberOfObservers - 1;
    this->m_uNumberOfObservers = iNewNumberOfObservers;
    if ( iIndex > iNewNumberOfObservers
      && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 75, "iIndex <= iNewNumberOfObservers") == 1 )
    {
      __debugbreak();
    }
    iDeltaAmount = this->m_vPileObserver[iIndex].m_iDeltaAmount;
    tTargetType = this->m_vPileObserver[iIndex].m_tTargetType;
    if ( iIndex < iNewNumberOfObservers )
      this->m_vPileObserver[iIndex] = this->m_vPileObserver[iNewNumberOfObservers];
    pObserver = CMapObjectMgr::EntityPtr(_iObserverId);
    if ( !pObserver && BBSupportDbgReport(2, "MapObjects\\Pile\\PileObserverList.cpp", 88, "pObserver != 0") == 1 )
      __debugbreak();
    if ( !pObserver->GetObserverTarget(pObserver, tTargetType)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Pile\\PileObserverList.cpp",
           90,
           "pObserver->GetObserverTarget(tTargetType) != 0") == 1 )
    {
      __debugbreak();
    }
    pObserver->SetObserverTarget(pObserver, tTargetType, 0);
    if ( pObserver->GetObserverTarget(pObserver, tTargetType)
      && BBSupportDbgReport(
           2,
           "MapObjects\\Pile\\PileObserverList.cpp",
           94,
           "pObserver->GetObserverTarget(tTargetType) == 0") == 1 )
    {
      __debugbreak();
    }
  }
  return iDeltaAmount;
}


// address=[0x15608e0]
// Decompiled from void __thiscall CPileObserverList::NotifyAllObservers(CPileObserverList *this, struct CEntityEvent *a2)
void  CPileObserverList::NotifyAllObservers(class CEntityEvent const & a2)const {
  
  int uNumberOfObservers; // [esp+0h] [ebp-18h]
  IEntity *v3; // [esp+4h] [ebp-14h]
  int iObserverId; // [esp+Ch] [ebp-Ch]
  int i; // [esp+14h] [ebp-4h]

  uNumberOfObservers = this->m_uNumberOfObservers;
  for ( i = 0; i < uNumberOfObservers; ++i )
  {
    iObserverId = this->m_vPileObserver[i].m_iObserverId;
    if ( this->m_vPileObserver[i].m_iObserverId )
      v3 = CMapObjectMgr::EntityPtr(iObserverId);
    else
      v3 = 0;
    if ( v3 )
    {
      v3->SetEvent(v3, a2);
    }
    else if ( BBSupportDbgReportF(
                1,
                "MapObjects\\Pile\\PileObserverList.cpp",
                125,
                "CPileObserverList::NotifyAllObservers(): Invalid observer %i in list!",
                iObserverId) == 1 )
    {
      __debugbreak();
    }
  }
}


// address=[0x1560990]
// Decompiled from void __thiscall CPileObserverList::DetachAllObservers(CPileObserverList *this)
void  CPileObserverList::DetachAllObservers(void) {
  
  int uNumberOfObservers; // [esp+0h] [ebp-1Ch]
  IEntity *pObserver; // [esp+4h] [ebp-18h]
  int iObserverId; // [esp+8h] [ebp-14h]
  int tTargetType; // [esp+Ch] [ebp-10h]
  int i; // [esp+14h] [ebp-8h]

  uNumberOfObservers = this->m_uNumberOfObservers;
  for ( i = 0; i < uNumberOfObservers; ++i )
  {
    iObserverId = this->m_vPileObserver[i].m_iObserverId;
    if ( this->m_vPileObserver[i].m_iObserverId )
      pObserver = CMapObjectMgr::EntityPtr(iObserverId);
    else
      pObserver = 0;
    if ( pObserver )
    {
      tTargetType = this->m_vPileObserver[i].m_tTargetType;
      if ( !pObserver->GetObserverTarget(pObserver, tTargetType)
        && BBSupportDbgReport(
             2,
             "MapObjects\\Pile\\PileObserverList.cpp",
             149,
             "pObserver->GetObserverTarget(tTargetType) != 0") == 1 )
      {
        __debugbreak();
      }
      pObserver->SetObserverTarget(pObserver, tTargetType, 0);
      if ( pObserver->GetObserverTarget(pObserver, tTargetType) )
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
                iObserverId) == 1 )
    {
      __debugbreak();
    }
  }
  CPileObserverList::Clear(this);
}


// address=[0x1560b50]
// Decompiled from CPileObserverList *__thiscall CPileObserverList::CPileObserverList(CPileObserverList *this, int _rStream)
 CPileObserverList::CPileObserverList(std::istream & _rStream) {
  
  int v3; // [esp+4h] [ebp-10h] BYREF
  int pExceptionObject; // [esp+8h] [ebp-Ch] BYREF
  unsigned int i; // [esp+Ch] [ebp-8h]

  CPileObserverList::Clear(this);
  operator^<unsigned int>(_rStream, &v3);
  if ( v3 != 1 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPileObserverList");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  operator^<unsigned char>(_rStream, &this->m_uNumberOfObservers);
  if ( this->m_uNumberOfObservers > 8u
    && BBSupportDbgReport(
         2,
         "MapObjects\\Pile\\PileObserverList.cpp",
         215,
         "m_uNumberOfObservers <= PILE_OBSERVERS_MAX") == 1 )
  {
    __debugbreak();
  }
  for ( i = 0; i < this->m_uNumberOfObservers; ++i )
  {
    operator^<unsigned short>(_rStream, (unsigned __int16 *)&this->m_vPileObserver[i]);
    operator^<signed char>(_rStream, &this->m_vPileObserver[i].m_iDeltaAmount);
    operator^<unsigned char>(_rStream, &this->m_vPileObserver[i].m_tTargetType);
  }
  return this;
}


// address=[0x1560c60]
// Decompiled from void __thiscall CPileObserverList::Store(CPileObserverList *this, struct std::ostream *_rStream)
void  CPileObserverList::Store(std::ostream & _rStream) {
  
  int v2; // [esp+0h] [ebp-Ch] BYREF
  unsigned int i; // [esp+8h] [ebp-4h]

  v2 = 1;
  operator^<unsigned int>(_rStream, &v2);
  operator^<unsigned char>(_rStream, &this->m_uNumberOfObservers);
  for ( i = 0; i < this->m_uNumberOfObservers; ++i )
  {
    operator^<unsigned short>(_rStream, (WORD *)&this->m_vPileObserver[i]);
    operator^<signed char>(_rStream, &this->m_vPileObserver[i].m_iDeltaAmount);
    operator^<unsigned char>(_rStream, &this->m_vPileObserver[i].m_tTargetType);
  }
}


// address=[0x1560ad0]
// Decompiled from void __thiscall CPileObserverList::Clear(CPileObserverList *this)
void  CPileObserverList::Clear(void) {
  
  memset(this, 0, 32u);
  this->m_uNumberOfObservers = 0;
}


// address=[0x1560b00]
// Decompiled from int __thiscall CPileObserverList::GetIndex(CPileObserverList *this, int _iObserverId)
int  CPileObserverList::GetIndex(int _iObserverId)const {
  
  int i; // [esp+8h] [ebp-4h]

  for ( i = 0; i < this->m_uNumberOfObservers; ++i )
  {
    if ( this->m_vPileObserver[i].m_iObserverId == _iObserverId )
      return i;
  }
  return -1;
}


