#ifndef IFLYINGENTITY_H
#define IFLYINGENTITY_H

#include "defines.h"

class IFlyingEntity : public IAnimatedEntity {
public:
    // address=[0x12fd150]
    int  FlyingFlagBits(int a2)const;

    // address=[0x154ee80]
     IFlyingEntity(int a2, int a3, int a4, int a5);

    // address=[0x154ef70]
     IFlyingEntity(std::istream & a2);

    // address=[0x154f080]
    virtual void  Store(std::ostream & a2);

    // address=[0x154f140]
    void  FlyTo(int a2, int a3);

    // address=[0x154f180]
    virtual void  Delete(void);

    // address=[0x154f230]
    virtual void  Attach(int a2);

    // address=[0x154f260]
    virtual void  Detach(int a2);

    // address=[0x154f290]
    virtual void  Notify(class CEntityEvent const & a2)const;

    // address=[0x154f3e0]
    virtual  ~IFlyingEntity(void);

    // address=[0x154f460]
    void  SetFlyingFlagBits(int a2);

    // address=[0x1554fe0]
    void  ClearFlyingFlagBits(int a2);

protected:
    // address=[0x154f2b0]
    void  DetachWithoutNotify(int a2);

private:
    // address=[0x154f450]
    virtual void  NotifyDetach(int a2);

};


#endif // IFLYINGENTITY_H
