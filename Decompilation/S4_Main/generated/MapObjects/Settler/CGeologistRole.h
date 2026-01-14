#ifndef CGEOLOGISTROLE_H
#define CGEOLOGISTROLE_H

class CGeologistRole : public ISelectableSettlerRole {
public:
    // address=[0x1400cc0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x15720a0]
    virtual class CWalking *  InitWalking(class CSettler *);

    // address=[0x15720e0]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x15722a0]
    virtual void  PostLoadInit(class CSettler *);

    // address=[0x1572310]
     CGeologistRole(std::istream &);

    // address=[0x1572490]
    virtual void  Store(std::ostream &);

    // address=[0x15744d0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15744f0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1588680]
    static class CGeologistRole * __cdecl Load(std::istream &);

    // address=[0x3d8bec8]
    static unsigned long m_iClassID;

private:
    // address=[0x1572700]
     CGeologistRole(void);

    // address=[0x1572770]
    virtual  ~CGeologistRole(void);

    // address=[0x1572860]
    virtual void  GetNextJob(class CSettler *);

    // address=[0x15728a0]
    virtual void  TakeJob(class CSettler *);

    // address=[0x1572d10]
    virtual void  Init(class CSettler *);

    // address=[0x1572df0]
    void  WorkIsDone(class CSettler *);

    // address=[0x1572e10]
    virtual void  ConvertEventIntoGoal(class CSettler *,class CEntityEvent *);

    // address=[0x15732d0]
    bool  SearchPosition(class CSettler *);

    // address=[0x1573530]
    bool  CheckResource(class CSettler *);

    // address=[0x15736b0]
    void  SetSign(class CSettler *);

    // address=[0x1573bc0]
    bool  CheckPosition(int,int,bool,bool);

};


#endif // CGEOLOGISTROLE_H
