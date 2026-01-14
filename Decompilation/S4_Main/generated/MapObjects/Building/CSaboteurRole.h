#ifndef CSABOTEURROLE_H
#define CSABOTEURROLE_H

class CSaboteurRole : public CSoldierRole {
public:
    // address=[0x1401b20]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x157c490]
    virtual void  Init(class CSettler *);

    // address=[0x157c4c0]
    virtual void  LogicUpdate(class CSettler *);

    // address=[0x157c5f0]
     CSaboteurRole(std::istream &);

    // address=[0x157c6d0]
    virtual void  Store(std::ostream &);

    // address=[0x157c8f0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x157c910]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1588840]
    static class CSaboteurRole * __cdecl Load(std::istream &);

    // address=[0x3d8bef8]
    static unsigned long m_iClassID;

protected:
    // address=[0x157c720]
    virtual void  WarriorTaskAttack(class IMovingEntity &,int,enum T_WARRIOR_ATTACK);

private:
    // address=[0x157c780]
     CSaboteurRole(void);

    // address=[0x157c880]
    virtual  ~CSaboteurRole(void);

};


#endif // CSABOTEURROLE_H
