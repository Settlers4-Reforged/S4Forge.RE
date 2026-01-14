#ifndef CTRADEPILEROLE_H
#define CTRADEPILEROLE_H

class CTradePileRole : public IPileRole {
public:
    // address=[0x14023e0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1560480]
    static class CTradePileRole * __cdecl Load(std::istream &);

    // address=[0x1561a70]
    virtual void  Increase(class CPile *,int);

    // address=[0x1561b70]
    virtual void  Decrease(class CPile *,int);

    // address=[0x1561c90]
    virtual void  Empty(class CPile *);

    // address=[0x1561d60]
    virtual void  Init(class CPile *);

    // address=[0x1561de0]
    virtual void  LogicUpdate(class CPile *);

    // address=[0x1561f40]
    virtual void  Occupied(class CPile *,int);

    // address=[0x1561fc0]
    virtual bool  SetFree(class CPile *,int);

    // address=[0x1562050]
    virtual void  NotifyChangeEcoSector(class CPile *,int,int);

    // address=[0x15620c0]
    virtual void  SubjectDie(class CPile *,int);

    // address=[0x15621c0]
    virtual void  SubjectStopped(class CPile *);

    // address=[0x1562230]
    virtual void  SubjectStarted(class CPile *);

    // address=[0x1562290]
    virtual bool  ChangeGoodTypeUnforseen(class CPile *,int);

    // address=[0x1562340]
    void  SetTradeRoleType(enum CTradePileRole::TRADEPILE_ROLE);

    // address=[0x1562440]
    int  GetTradeRoleType(void);

    // address=[0x1562460]
    void  SetExpectedAmount(int);

    // address=[0x1562480]
    int  GetExpectedAmount(void);

    // address=[0x15624a0]
    virtual void  IncAmoutLeaving(class CPile *);

    // address=[0x1562500]
    virtual void  DecAmountLeaving(class CPile *);

    // address=[0x1562560]
    virtual void  IncAmountComing(class CPile *);

    // address=[0x1562590]
    virtual void  DecAmountComing(class CPile *);

    // address=[0x15625e0]
    int  ReservesGood(int,enum PILE_TYPES,class CPile *);

    // address=[0x15626d0]
    int  GetReserveAmount(void);

    // address=[0x1562710]
     CTradePileRole(std::istream &);

    // address=[0x1562810]
    virtual void  Store(std::ostream &);

    // address=[0x1562d70]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bea0]
    static unsigned long m_iClassID;

private:
    // address=[0x1562890]
     CTradePileRole(void);

    // address=[0x1562920]
    virtual  ~CTradePileRole(void);

};


#endif // CTRADEPILEROLE_H
