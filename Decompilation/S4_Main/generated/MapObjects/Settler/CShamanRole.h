#ifndef CSHAMANROLE_H
#define CSHAMANROLE_H

class CShamanRole : public CSoldierRole {
public:
    // address=[0x130f0f0]
    bool  IsManaPoolEmpty(void);

    // address=[0x1401d00]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1588880]
    static class CShamanRole * __cdecl Load(std::istream &);

    // address=[0x158be00]
    virtual void  LogicUpdateJob(class CSettler *);

    // address=[0x158c090]
    virtual void  WarriorTaskAttack(class IMovingEntity &,int,enum T_WARRIOR_ATTACK);

    // address=[0x158c340]
    virtual void  ConvertEventIntoGoal(class CSettler *,class CEntityEvent *);

    // address=[0x158c430]
     CShamanRole(std::istream &);

    // address=[0x158c580]
    virtual void  Store(std::ostream &);

    // address=[0x158ca60]
    virtual unsigned long  ClassID(void)const;

    // address=[0x158ca80]
    virtual int  GetSettlerRole(void)const;

    // address=[0x3d8bf98]
    static unsigned long m_iClassID;

private:
    // address=[0x158c600]
     CShamanRole(void);

    // address=[0x158c690]
    int  CheckForManakopter(class CSettler *);

    // address=[0x158c9f0]
    virtual  ~CShamanRole(void);

    // address=[0x4158c4c]
    static class CAIConfigInt s_iManaCostRot;

    // address=[0x4158c58]
    static class CAIConfigInt s_iManaCostTeleport;

    // address=[0x4158c64]
    static class CAIConfigInt s_iManaCostEnslave;

    // address=[0x4158c70]
    static class CAIConfigInt s_iShamanManaPool;

};


#endif // CSHAMANROLE_H
