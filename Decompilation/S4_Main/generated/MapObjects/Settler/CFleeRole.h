#ifndef CFLEEROLE_H
#define CFLEEROLE_H

class CFleeRole : public ISettlerRole {
public:
    // address=[0x1400a40]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x156d370]
    virtual class CWalking *  InitWalking(class CSettler *);

    // address=[0x156d3b0]
    virtual void  LogicUpdate(class CSettler *);

    // address=[0x156d730]
    virtual void  UpdateJob(class CSettler *);

    // address=[0x156d740]
    virtual void  PostLoadInit(class CSettler *);

    // address=[0x156d760]
    virtual bool  SetFree(class CSettler *,int);

    // address=[0x156d770]
    virtual bool  ESChanged(class CSettler *);

    // address=[0x156d780]
     CFleeRole(std::istream &);

    // address=[0x156d830]
    virtual void  Store(std::ostream &);

    // address=[0x156dbc0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x156dbe0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x156dc00]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x15885c0]
    static class CFleeRole * __cdecl Load(std::istream &);

    // address=[0x3d8bebc]
    static unsigned long m_iClassID;

private:
    // address=[0x156d870]
     CFleeRole(void);

    // address=[0x156d890]
    virtual  ~CFleeRole(void);

    // address=[0x156d8b0]
    virtual void  GetNextJob(class CSettler *);

    // address=[0x156d8d0]
    virtual void  TakeJob(class CSettler *);

    // address=[0x156d910]
    virtual void  Init(class CSettler *);

    // address=[0x156d9b0]
    virtual void  ConvertEventIntoGoal(class CSettler *,class CEntityEvent *);

};


#endif // CFLEEROLE_H
