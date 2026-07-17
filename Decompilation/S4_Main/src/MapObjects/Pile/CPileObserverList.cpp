#include "CPileObserverList.h"

#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "MapObjects/CMapObjectMgr.h"
#include "MapObjects/IEntity.h"

#include <iostream>

// Definitions for class CPileObserverList

// address=[0x155e620]
// Decompiled from CPileObserverList *__thiscall CPileObserverList::CPileObserverList(CPileObserverList *this)
CPileObserverList::CPileObserverList(void) {
    CPileObserverList::Clear();
}

// address=[0x155e7f0]
// Decompiled from void __thiscall CPileObserverList::NotifyAndDetachAllObservers(CPileObserverList *this, const struct CEntityEvent *a2)
void CPileObserverList::NotifyAndDetachAllObservers(class CEntityEvent const &a2) {
    CPileObserverList::NotifyAllObservers(a2);
    CPileObserverList::DetachAllObservers();
}

// address=[0x155e820]
// Decompiled from int __thiscall CPileObserverList::NumberOfObservers(CPileObserverList *this)
int CPileObserverList::NumberOfObservers(void) const {

    return this->m_uNumberOfObservers;
}

// address=[0x155e840]
// Decompiled from const struct SPileObserver *__thiscall CPileObserverList::Observers(CPileObserverList *this)
SPileObserver const *CPileObserverList::Observers(void) const {

    return this->m_vPileObserver;
}

// address=[0x1560500]
// Decompiled from void __thiscall CPileObserverList::Attach(  CPileObserverList *this,  int _tTargetType,  int _iTargetId,  int _iObserverId,  int _iDeltaAmount)
void CPileObserverList::Attach(T_OBSERVER_TARGET _tTargetType, int _iTargetId, int _iObserverId, int _iDeltaAmount) {

    // [esp+0h] [ebp-8h]

    BB_ASSERT(_iTargetId > 0)
    BB_ASSERT(_iObserverId > 0)
    BB_ASSERT(_iObserverId <= 0xFFFF)
    BB_ASSERT((_iDeltaAmount >= -8) && (_iDeltaAmount <= 8))

    BB_ASSERT(_iDeltaAmount != 0)

    BB_ASSERT(GetIndex(_iObserverId) < 0)
    BB_ASSERT(m_uNumberOfObservers < PILE_OBSERVERS_MAX)
    this->m_vPileObserver[this->m_uNumberOfObservers].m_iObserverId = _iObserverId;
    this->m_vPileObserver[this->m_uNumberOfObservers].m_iDeltaAmount = _iDeltaAmount;
    this->m_vPileObserver[this->m_uNumberOfObservers++].m_tTargetType = _tTargetType;

    IEntity *pObserver = CMapObjectMgr::EntityPtr(_iObserverId);
    BB_ASSERT(pObserver != 0)
    BB_ASSERT(pObserver->GetObserverTarget(_tTargetType) == 0)
    pObserver->SetObserverTarget(_tTargetType, _iTargetId);
    BB_ASSERT(pObserver->GetObserverTarget(_tTargetType) != 0)
}

// address=[0x1560710]
// Decompiled from int __thiscall CPileObserverList::Detach(CPileObserverList *this, int _iObserverId)
int CPileObserverList::Detach(int _iObserverId) {

    // [esp+0h] [ebp-1Ch]
    // [esp+4h] [ebp-18h]
    // [esp+Ch] [ebp-10h]
    // [esp+10h] [ebp-Ch]
    // [esp+1Bh] [ebp-1h]

    BB_ASSERT(_iObserverId > 0)

    int iDeltaAmount = 0;
    int iIndex = CPileObserverList::GetIndex(_iObserverId);
    if(iIndex < 0) {
        BB_REPORTF("CPileObserverList::Detach(): Observer %i not in list!", _iObserverId)
    } else {
        BB_ASSERT(m_uNumberOfObservers > 0)

        unsigned __int8 iNewNumberOfObservers = this->m_uNumberOfObservers - 1;
        this->m_uNumberOfObservers = iNewNumberOfObservers;
        BB_ASSERT(iIndex <= iNewNumberOfObservers)

        iDeltaAmount = this->m_vPileObserver[iIndex].m_iDeltaAmount;
        T_OBSERVER_TARGET tTargetType = static_cast<T_OBSERVER_TARGET>(this->m_vPileObserver[iIndex].m_tTargetType);
        if(iIndex < iNewNumberOfObservers)
            this->m_vPileObserver[iIndex] = this->m_vPileObserver[iNewNumberOfObservers];
        IEntity *pObserver = CMapObjectMgr::EntityPtr(_iObserverId);
        BB_ASSERT(pObserver != 0)
        BB_ASSERT(pObserver->GetObserverTarget(tTargetType) != 0)

        pObserver->SetObserverTarget(tTargetType, 0);
        BB_ASSERT(pObserver->GetObserverTarget(tTargetType) == 0)
    }
    return iDeltaAmount;
}

// address=[0x15608e0]
// Decompiled from void __thiscall CPileObserverList::NotifyAllObservers(CPileObserverList *this, struct CEntityEvent *a2)
void CPileObserverList::NotifyAllObservers(class CEntityEvent const &_rEvent) const {

    int uNumberOfObservers = this->m_uNumberOfObservers;
    for(int i = 0; i < uNumberOfObservers; ++i) {
        int iObserverId = this->m_vPileObserver[i].m_iObserverId;

        IEntity *pObserver;
        if(this->m_vPileObserver[i].m_iObserverId)
            pObserver = CMapObjectMgr::EntityPtr(iObserverId);
        else
            pObserver = 0;

        if(pObserver)
            pObserver->SetEvent(_rEvent);
        else
            BB_REPORTF("CPileObserverList::NotifyAllObservers(): Invalid observer %i in list!", iObserverId)
    }
}

// address=[0x1560990]
// Decompiled from void __thiscall CPileObserverList::DetachAllObservers(CPileObserverList *this)
void CPileObserverList::DetachAllObservers(void) {

    // [esp+0h] [ebp-1Ch]
    IEntity *pObserver; // [esp+4h] [ebp-18h]
                        // [esp+8h] [ebp-14h]
                        // [esp+Ch] [ebp-10h]
                        // [esp+14h] [ebp-8h]

    int uNumberOfObservers = this->m_uNumberOfObservers;
    for(int i = 0; i < uNumberOfObservers; ++i) {
        int iObserverId = this->m_vPileObserver[i].m_iObserverId;
        if(this->m_vPileObserver[i].m_iObserverId)
            pObserver = CMapObjectMgr::EntityPtr(iObserverId);
        else
            pObserver = 0;
        if(pObserver) {
            T_OBSERVER_TARGET tTargetType = static_cast<T_OBSERVER_TARGET>(this->m_vPileObserver[i].m_tTargetType);
            BB_ASSERT(pObserver->GetObserverTarget(tTargetType) != 0)

            pObserver->SetObserverTarget(tTargetType, 0);
            BB_ASSERT(pObserver->GetObserverTarget(tTargetType) == 0)
        } else {
            BB_REPORTF("CPileObserverList::DetachAllObservers(): Invalid observer %i in list!", iObserverId)
        }
    }
    CPileObserverList::Clear();
}

// address=[0x1560b50]
// Decompiled from CPileObserverList *__thiscall CPileObserverList::CPileObserverList(CPileObserverList *this, int _rStream)
CPileObserverList::CPileObserverList(std::istream &_rStream) {

    CPileObserverList::Clear();

    unsigned int iFileFormatVersion;
    _rStream >> iFileFormatVersion;
    static_assert(std::is_same_v<decltype(iFileFormatVersion), unsigned int>, "types must be like original");
    if(iFileFormatVersion != 1) {
        BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CPileObserverList");
        throw new CS4InvalidMapException();
    }
    _rStream >> this->m_uNumberOfObservers;
    static_assert(std::is_same_v<decltype(this->m_uNumberOfObservers), unsigned char>, "types must be like original");
    BB_ASSERT(m_uNumberOfObservers <= PILE_OBSERVERS_MAX)

    for(unsigned int i = 0; i < this->m_uNumberOfObservers; ++i) {
        _rStream >> this->m_vPileObserver[i].m_iObserverId;
        static_assert(std::is_same_v<decltype(this->m_vPileObserver[i].m_iObserverId), unsigned short>, "types must be like original");
        _rStream >> this->m_vPileObserver[i].m_iDeltaAmount;
        static_assert(std::is_same_v<decltype(this->m_vPileObserver[i].m_iDeltaAmount), signed char>, "types must be like original");
        _rStream >> this->m_vPileObserver[i].m_tTargetType;
        static_assert(std::is_same_v<decltype(this->m_vPileObserver[i].m_tTargetType), unsigned char>, "types must be like original");
    }
}

// address=[0x1560c60]
// Decompiled from void __thiscall CPileObserverList::Store(CPileObserverList *this, struct std::ostream *_rStream)
void CPileObserverList::Store(std::ostream &_rStream) {
    unsigned int uFileFormatVersion = 1;
    _rStream << uFileFormatVersion;
    _rStream << this->m_uNumberOfObservers;
    for(unsigned int i = 0; i < this->m_uNumberOfObservers; ++i) {
        _rStream << this->m_vPileObserver[i].m_iObserverId;
        _rStream << this->m_vPileObserver[i].m_iDeltaAmount;
        _rStream << this->m_vPileObserver[i].m_tTargetType;
    }
}

// address=[0x1560ad0]
// Decompiled from void __thiscall CPileObserverList::Clear(CPileObserverList *this)
void CPileObserverList::Clear(void) {
    memset(this->m_vPileObserver, 0, sizeof(this->m_vPileObserver));
    this->m_uNumberOfObservers = 0;
}

// address=[0x1560b00]
// Decompiled from int __thiscall CPileObserverList::GetIndex(CPileObserverList *this, int _iObserverId)
int CPileObserverList::GetIndex(int _iObserverId) const {
    for(int i = 0; i < this->m_uNumberOfObservers; ++i) {
        if(this->m_vPileObserver[i].m_iObserverId == _iObserverId)
            return i;
    }
    return -1;
}
