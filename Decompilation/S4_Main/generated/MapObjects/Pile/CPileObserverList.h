#ifndef CPILEOBSERVERLIST_H
#define CPILEOBSERVERLIST_H

#include "defines.h"

class CPileObserverList {
public:
    // address=[0x155e620]
     CPileObserverList(void);

    // address=[0x155e7f0]
    void  NotifyAndDetachAllObservers(class CEntityEvent const & a2);

    // address=[0x155e820]
    int  NumberOfObservers(void)const;

    // address=[0x155e840]
    struct SPileObserver const *  Observers(void)const;

    // address=[0x1560500]
    void  Attach(enum T_OBSERVER_TARGET _tTargetType, int _iTargetId, int _iObserverId, int _iDeltaAmount);

    // address=[0x1560710]
    int  Detach(int _iObserverId);

    // address=[0x15608e0]
    void  NotifyAllObservers(class CEntityEvent const & a2)const;

    // address=[0x1560990]
    void  DetachAllObservers(void);

    // address=[0x1560b50]
     CPileObserverList(std::istream & _rStream);

    // address=[0x1560c60]
    void  Store(std::ostream & _rStream);

protected:
    // address=[0x1560ad0]
    void  Clear(void);

    // address=[0x1560b00]
    int  GetIndex(int _iObserverId)const;

    // Type information members
public:
    struct SPileObserver[8] m_vPileObserver;
    unsigned __int8 m_uNumberOfObservers;

};


#endif // CPILEOBSERVERLIST_H
