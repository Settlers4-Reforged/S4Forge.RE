#ifndef CCARRIERROLE_H
#define CCARRIERROLE_H

class CCarrierRole : public ISettlerRole {
public:
    // address=[0x13fffa0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1563a30]
    virtual class CWalking *  InitWalking(class CSettler *);

    // address=[0x1563a70]
    virtual void  LogicUpdate(class CSettler *);

    // address=[0x1563b90]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x1564340]
    virtual void  UpdateJob(class CSettler *);

    // address=[0x1564420]
    virtual void  PostLoadInit(class CSettler *);

    // address=[0x1564440]
    virtual void  SetObserverTarget(enum T_OBSERVER_TARGET,int);

    // address=[0x15644e0]
    virtual int  GetObserverTarget(enum T_OBSERVER_TARGET);

    // address=[0x1564550]
    void  UpdateCatapultPosition(int);

    // address=[0x15645c0]
     CCarrierRole(std::istream &);

    // address=[0x15647e0]
    virtual void  Store(std::ostream &);

    // address=[0x1567060]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15670c0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1588480]
    static class CCarrierRole * __cdecl Load(std::istream &);

    // address=[0x3d8bea8]
    static unsigned long m_iClassID;

private:
    // address=[0x15648b0]
    virtual int  GetNextSettlerType(void);

    // address=[0x15648d0]
    virtual bool  SetNextSettlerType(int);

    // address=[0x15648f0]
    void  ChangeToNextType(class CSettler *,bool,bool);

    // address=[0x15649c0]
     CCarrierRole(void);

    // address=[0x1564a80]
    virtual  ~CCarrierRole(void);

    // address=[0x1564aa0]
    virtual void  GetNextJob(class CSettler *);

    // address=[0x1564af0]
    virtual void  TakeJob(class CSettler *);

    // address=[0x1565510]
    virtual void  Init(class CSettler *);

    // address=[0x1565660]
    virtual void  ConvertEventIntoGoal(class CSettler *,class CEntityEvent *);

    // address=[0x1566220]
    virtual bool  SetFree(class CSettler *,int);

    // address=[0x15664c0]
    void  TryToGoHome(class CSettler *);

    // address=[0x1567080]
    int  DestinationPileId(void)const;

    // address=[0x1567120]
    int  NextSettlerType(void);

    // address=[0x1567160]
    int  SourcePileId2(void)const;

    // address=[0x1567180]
    int  SourcePileId3(void)const;

};


#endif // CCARRIERROLE_H
