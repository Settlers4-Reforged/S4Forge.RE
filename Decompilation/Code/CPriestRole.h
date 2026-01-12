#ifndef CPRIESTROLE_H
#define CPRIESTROLE_H

class CPriestRole : public ISelectableSettlerRole {
public:
    // address=[0x1401760]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x157b260]
    virtual class CWalking *  InitWalking(class CSettler *);

    // address=[0x157b2a0]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x157b3c0]
    virtual void  PostLoadInit(class CSettler *);

    // address=[0x157b3e0]
     CPriestRole(std::istream &);

    // address=[0x157b500]
    virtual void  Store(std::ostream &);

    // address=[0x157c450]
    virtual unsigned long  ClassID(void)const;

    // address=[0x157c470]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1588800]
    static class CPriestRole * __cdecl Load(std::istream &);

    // address=[0x3d8bef4]
    static unsigned long m_iClassID;

private:
    // address=[0x157b620]
    virtual int  GetKindOfSelection(class CSettler *)const;

    // address=[0x157b640]
    virtual  ~CPriestRole(void);

    // address=[0x157b730]
    virtual void  GetNextJob(class CSettler *);

    // address=[0x157b7a0]
    virtual void  TakeJob(class CSettler *);

    // address=[0x157bbc0]
    virtual void  Init(class CSettler *);

    // address=[0x157bc00]
    virtual void  ConvertEventIntoGoal(class CSettler *,class CEntityEvent *);

    // address=[0x1587b00]
     CPriestRole(void);

};


#endif // CPRIESTROLE_H
