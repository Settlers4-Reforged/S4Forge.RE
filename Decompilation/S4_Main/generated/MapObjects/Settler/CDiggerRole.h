#ifndef CDIGGERROLE_H
#define CDIGGERROLE_H

class CDiggerRole : public ISettlerRole {
public:
    // address=[0x14004a0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1568910]
    virtual class CWalking *  InitWalking(class CSettler *);

    // address=[0x1568950]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x15689d0]
    virtual void  PostLoadInit(class CSettler *);

    // address=[0x15689f0]
    virtual bool  SetFree(class CSettler *,int);

    // address=[0x1568ae0]
     CDiggerRole(std::istream &);

    // address=[0x1568bb0]
    virtual void  Store(std::ostream &);

    // address=[0x1569d00]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1569d20]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1588500]
    static class CDiggerRole * __cdecl Load(std::istream &);

    // address=[0x3d8beb0]
    static unsigned long m_iClassID;

private:
    // address=[0x1568c10]
     CDiggerRole(void);

    // address=[0x1568c40]
    virtual  ~CDiggerRole(void);

    // address=[0x1568c60]
    virtual void  GetNextJob(class CSettler *);

    // address=[0x1568ca0]
    virtual void  TakeJob(class CSettler *);

    // address=[0x1568ee0]
    virtual void  Init(class CSettler *);

    // address=[0x1568f70]
    virtual void  ConvertEventIntoGoal(class CSettler *,class CEntityEvent *);

    // address=[0x1569130]
    void  SearchDig(class CSettler *);

    // address=[0x1569540]
    bool  CheckDig(class CSettler *);

};


#endif // CDIGGERROLE_H
