#ifndef CSQUADLEADERROLE_H
#define CSQUADLEADERROLE_H

class CSquadLeaderRole : public CSoldierRole {
public:
    // address=[0x1402020]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1575bb0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x1575bf0]
    virtual int  GetSettlerRole(void)const;

    // address=[0x1575c20]
    virtual bool  IsHJB(void);

    // address=[0x1592380]
    virtual void  Init(class CSettler *);

    // address=[0x15923d0]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x1592420]
    virtual void  WarriorInit(class IMovingEntity &,int,int);

    // address=[0x15929d0]
     CSquadLeaderRole(std::istream &);

    // address=[0x1592ac0]
    virtual void  Store(std::ostream &);

    // address=[0x3d8bfa4]
    static unsigned long m_iClassID;

protected:
    // address=[0x1575ab0]
    virtual  ~CSquadLeaderRole(void);

    // address=[0x1592470]
    virtual int  WarriorTaskWalkOneStep(class IMovingEntity &);

    // address=[0x15925a0]
    virtual int  WarriorTaskIdleWalk(class IMovingEntity &);

    // address=[0x15925d0]
    virtual void  WarriorTaskAttack(class IMovingEntity &,int,enum T_WARRIOR_ATTACK);

    // address=[0x1592600]
    virtual void  WarriorTaskFinished(class IMovingEntity &);

    // address=[0x1592b50]
     CSquadLeaderRole(void);

private:
    // address=[0x1592620]
    void  CommandGroupMembers(class IMovingEntity &);

    // address=[0x1592b20]
    static class CSquadLeaderRole * __cdecl Load_HACK_VERSION(std::istream &);

};


#endif // CSQUADLEADERROLE_H
