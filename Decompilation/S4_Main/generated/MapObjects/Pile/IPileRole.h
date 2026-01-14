#ifndef IPILEROLE_H
#define IPILEROLE_H

class IPileRole : public CPersistence {
public:
    // address=[0x155b1e0]
    virtual  ~IPileRole(void);

    // address=[0x155b280]
    virtual bool  ChangeGoodTypeUnforseen(class CPile *,int);

    // address=[0x155b2c0]
    virtual void  DecAmountComing(class CPile *);

    // address=[0x155b2d0]
    virtual void  Empty(class CPile *);

    // address=[0x155b2e0]
    virtual void  IncAmountComing(class CPile *);

    // address=[0x155b2f0]
    virtual void  LogicUpdate(class CPile *);

    // address=[0x155b330]
    virtual void  ReassessDistance(class CPile *,int &);

    // address=[0x1560f00]
    virtual void  Increase(class CPile *,int);

    // address=[0x1560fc0]
    virtual void  Decrease(class CPile *,int);

    // address=[0x1561050]
    virtual void  IncAmoutLeaving(class CPile *);

    // address=[0x15610b0]
    virtual void  DecAmountLeaving(class CPile *);

    // address=[0x1561140]
    virtual void  Init(class CPile *);

    // address=[0x1561160]
    virtual void  Occupied(class CPile *,int);

    // address=[0x1561190]
    virtual bool  SetFree(class CPile *,int);

    // address=[0x1561210]
    virtual void  NotifyChangeEcoSector(class CPile *,int,int);

    // address=[0x1561250]
    virtual void  SubjectDie(class CPile *,int);

    // address=[0x1561350]
    virtual void  SubjectStopped(class CPile *);

    // address=[0x1561360]
    virtual void  SubjectStarted(class CPile *);

    // address=[0x1561370]
     IPileRole(std::istream &);

    // address=[0x15613f0]
    virtual void  Store(std::ostream &);

    // address=[0x1561440]
    bool  ExecuteChangeGoodTypeUnforseen(class CPile *,int);

protected:
    // address=[0x1560200]
     IPileRole(void);

};


#endif // IPILEROLE_H
