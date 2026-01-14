#ifndef CPIONEERROLE_H
#define CPIONEERROLE_H

class CPioneerRole : public ISelectableSettlerRole {
public:
    // address=[0x1401620]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x15796d0]
    virtual class CWalking *  InitWalking(class CSettler *);

    // address=[0x1579710]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x1579880]
    virtual void  PostLoadInit(class CSettler *);

    // address=[0x15798f0]
     CPioneerRole(std::istream &);

    // address=[0x1579a50]
    virtual void  Store(std::ostream &);

    // address=[0x157b220]
    virtual unsigned long  ClassID(void)const;

    // address=[0x157b240]
    virtual int  GetSettlerRole(void)const;

    // address=[0x15887c0]
    static class CPioneerRole * __cdecl Load(std::istream &);

    // address=[0x3d8bef0]
    static unsigned long m_iClassID;

private:
    // address=[0x1579cb0]
     CPioneerRole(void);

    // address=[0x1579d50]
    virtual  ~CPioneerRole(void);

    // address=[0x1579e70]
    virtual void  GetNextJob(class CSettler *);

    // address=[0x1579eb0]
    virtual void  TakeJob(class CSettler *);

    // address=[0x157a330]
    virtual void  Init(class CSettler *);

    // address=[0x157a3c0]
    void  WorkIsDone(class CSettler *);

    // address=[0x157a410]
    virtual void  ConvertEventIntoGoal(class CSettler *,class CEntityEvent *);

    // address=[0x157a8b0]
    bool  SearchPosition(class CSettler *);

    // address=[0x157aaa0]
    bool  CheckLand(int,int,class CSettler *,bool);

    // address=[0x157abe0]
    void  TakeLand(class CSettler *);

};


#endif // CPIONEERROLE_H
