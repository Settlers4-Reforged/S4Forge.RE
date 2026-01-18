#ifndef COBSERVERLIST_H
#define COBSERVERLIST_H

#include "defines.h"

class CObserverList {
public:
    // address=[0x14eafe0]
     CObserverList(void);

    // address=[0x14eb0e0]
     ~CObserverList(void);

    // address=[0x14eb6c0]
    void  NotifyAndDetachAllObservers(class CEntityEvent const & a2);

    // address=[0x1559aa0]
    void  Attach(int a2, int a3);

    // address=[0x1559c20]
    void  Detach(int a2);

    // address=[0x1559d80]
    void  NotifyAllObservers(class CEntityEvent const & a2)const;

    // address=[0x1559e90]
    void  NotifyAllObservers(class CEntityEvent const & a2, class INotifyFilter & a3)const;

    // address=[0x1559fb0]
    void  DetachAllObservers(void);

    // address=[0x155a1e0]
    void  DetachAllNonePileObservers(void);

    // address=[0x155a420]
    bool  IsInList(int a2)const;

    // address=[0x155a6b0]
     CObserverList(std::istream & a2);

    // address=[0x155a7a0]
    void  Store(std::ostream & a2);

protected:
    // address=[0x155a570]
    bool  Remove(int a2);

};


#endif // COBSERVERLIST_H
