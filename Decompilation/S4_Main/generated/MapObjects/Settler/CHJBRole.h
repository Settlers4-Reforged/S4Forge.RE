#ifndef CHJBROLE_H
#define CHJBROLE_H

class CHJBRole : public CSquadLeaderRole {
public:
    // address=[0x1400e00]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1574e20]
     CHJBRole(std::istream &);

    // address=[0x1574f10]
    virtual void  Store(std::ostream &);

    // address=[0x1575030]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x1575310]
    virtual int  Decrease(int);

    // address=[0x1575b90]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1575c10]
    virtual bool  IsHJB(void);

    // address=[0x15886c0]
    static class CHJBRole * __cdecl Load(std::istream &);

    // address=[0x3d8bee0]
    static unsigned long m_iClassID;

protected:
    // address=[0x1574dd0]
     CHJBRole(void);

    // address=[0x1574f70]
    virtual void  PostLoadInit(class CSettler *);

    // address=[0x15753b0]
    int  FindNewHJBPosition(class CSettler *);

    // address=[0x15755d0]
    int  FindNearFreePositionInSector(int,int,int);

    // address=[0x15756a0]
    void  ExecuteAttackSpell(class CSettler *,int,int);

    // address=[0x1575a80]
    virtual  ~CHJBRole(void);

};


#endif // CHJBROLE_H
