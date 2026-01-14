#ifndef COBSERVERLIST_H
#define COBSERVERLIST_H

class CObserverList {
public:
    // address=[0x14eafe0]
     CObserverList(void);

    // address=[0x14eb0e0]
     ~CObserverList(void);

    // address=[0x14eb6c0]
    void  NotifyAndDetachAllObservers(class CEntityEvent const &);

    // address=[0x1559aa0]
    void  Attach(int,int);

    // address=[0x1559c20]
    void  Detach(int);

    // address=[0x1559d80]
    void  NotifyAllObservers(class CEntityEvent const &)const;

    // address=[0x1559e90]
    void  NotifyAllObservers(class CEntityEvent const &,class INotifyFilter &)const;

    // address=[0x1559fb0]
    void  DetachAllObservers(void);

    // address=[0x155a1e0]
    void  DetachAllNonePileObservers(void);

    // address=[0x155a420]
    bool  IsInList(int)const;

    // address=[0x155a6b0]
     CObserverList(std::istream &);

    // address=[0x155a7a0]
    void  Store(std::ostream &);

protected:
    // address=[0x155a570]
    bool  Remove(int);

};


#endif // COBSERVERLIST_H
