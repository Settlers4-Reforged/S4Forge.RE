#ifndef CTHIEFROLE_H
#define CTHIEFROLE_H

class CThiefRole : public ISelectableSettlerRole {
public:
    // address=[0x14022a0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1588940]
    static class CThiefRole * __cdecl Load(std::istream &);

    // address=[0x1592e30]
    virtual class CWalking *  InitWalking(class CSettler *);

    // address=[0x1592e70]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x1593050]
    virtual void  LogicUpdate(class CSettler *);

    // address=[0x15930a0]
    virtual void  UpdateJob(class CSettler *);

    // address=[0x1593160]
    virtual void  PostLoadInit(class CSettler *);

    // address=[0x15931e0]
    virtual bool  SetFree(class CSettler *,int);

    // address=[0x1593240]
     CThiefRole(std::istream &);

    // address=[0x1593370]
    virtual void  Store(std::ostream &);

    // address=[0x1594890]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15948b0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x3d8bfa8]
    static unsigned long m_iClassID;

private:
    // address=[0x1593590]
     CThiefRole(void);

    // address=[0x1593610]
    virtual  ~CThiefRole(void);

    // address=[0x1593640]
    virtual void  GetNextJob(class CSettler *);

    // address=[0x1593680]
    virtual void  TakeJob(class CSettler *);

    // address=[0x1593b40]
    virtual void  Init(class CSettler *);

    // address=[0x1593c00]
    bool  CheckGoodInSurrounding(class CSettler *);

    // address=[0x1593da0]
    bool  IsAllyOwner(class CSettler *,int);

    // address=[0x1593e10]
    virtual void  ConvertEventIntoGoal(class CSettler *,class CEntityEvent *);

};


#endif // CTHIEFROLE_H
