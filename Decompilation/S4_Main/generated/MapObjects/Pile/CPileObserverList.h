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
    void  Attach(enum T_OBSERVER_TARGET a2, int a3, int a4, int a5);

    // address=[0x1560710]
    int  Detach(int a2);

    // address=[0x15608e0]
    void  NotifyAllObservers(class CEntityEvent const & a2)const;

    // address=[0x1560990]
    void  DetachAllObservers(void);

    // address=[0x1560b50]
     CPileObserverList(std::istream & a2);

    // address=[0x1560c60]
    void  Store(std::ostream & a2);

protected:
    // address=[0x1560ad0]
    void  Clear(void);

    // address=[0x1560b00]
    int  GetIndex(int a2)const;

};


#endif // CPILEOBSERVERLIST_H
