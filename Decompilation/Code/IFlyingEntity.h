#ifndef IFLYINGENTITY_H
#define IFLYINGENTITY_H

class IFlyingEntity : public IAnimatedEntity {
public:
    // address=[0x12fd150]
    int  FlyingFlagBits(int)const;

    // address=[0x154ee80]
     IFlyingEntity(int,int,int,int);

    // address=[0x154ef70]
     IFlyingEntity(std::istream &);

    // address=[0x154f080]
    virtual void  Store(std::ostream &);

    // address=[0x154f140]
    void  FlyTo(int,int);

    // address=[0x154f180]
    virtual void  Delete(void);

    // address=[0x154f230]
    virtual void  Attach(int);

    // address=[0x154f260]
    virtual void  Detach(int);

    // address=[0x154f290]
    virtual void  Notify(class CEntityEvent const &)const;

    // address=[0x154f3e0]
    virtual  ~IFlyingEntity(void);

    // address=[0x154f460]
    void  SetFlyingFlagBits(int);

    // address=[0x1554fe0]
    void  ClearFlyingFlagBits(int);

protected:
    // address=[0x154f2b0]
    void  DetachWithoutNotify(int);

private:
    // address=[0x154f450]
    virtual void  NotifyDetach(int);

};


#endif // IFLYINGENTITY_H
