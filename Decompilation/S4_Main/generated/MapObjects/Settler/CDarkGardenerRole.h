#ifndef CDARKGARDENERROLE_H
#define CDARKGARDENERROLE_H

class CDarkGardenerRole : public ISettlerRole {
public:
    // address=[0x1400180]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x15671c0]
    virtual class CWalking *  InitWalking(class CSettler *);

    // address=[0x1567200]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x1567360]
    virtual void  PostLoadInit(class CSettler *);

    // address=[0x15673d0]
     CDarkGardenerRole(std::istream &);

    // address=[0x1567560]
    virtual void  Store(std::ostream &);

    // address=[0x15686e0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15687d0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x15687f0]
    static bool __cdecl IsLandChangeable(int);

    // address=[0x15884c0]
    static class CDarkGardenerRole * __cdecl Load(std::istream &);

    // address=[0x3d8beac]
    static unsigned long m_iClassID;

private:
    // address=[0x1567840]
    virtual  ~CDarkGardenerRole(void);

    // address=[0x15678c0]
    virtual void  GetNextJob(class CSettler *);

    // address=[0x1567900]
    virtual void  TakeJob(class CSettler *);

    // address=[0x1567c90]
    virtual void  Init(class CSettler *);

    // address=[0x1567d10]
    virtual void  ConvertEventIntoGoal(class CSettler *,class CEntityEvent *);

    // address=[0x1567ee0]
    void  WorkIsDone(class CSettler *);

    // address=[0x1567f30]
    bool  CheckPosition(int,int,bool);

    // address=[0x1568020]
    bool  SearchPosition(class CSettler *);

    // address=[0x15879d0]
     CDarkGardenerRole(void);

};


#endif // CDARKGARDENERROLE_H
