#ifndef CMANAKOPTER_H
#define CMANAKOPTER_H

class CManakopter : public IFlyingEntity {
public:
    // address=[0x1401120]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1552980]
     CManakopter(int,int,int,int);

    // address=[0x1552c00]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x1552c10]
    virtual void  LogicUpdate(void);

    // address=[0x1553110]
    bool  SettlerEnter(int);

    // address=[0x1553300]
    void  UnloadSettlers(void);

    // address=[0x15534e0]
    virtual void  Attach(int);

    // address=[0x1553510]
    virtual void  Delete(void);

    // address=[0x1553670]
    virtual void  Decrease(int);

    // address=[0x15536c0]
     CManakopter(std::istream &);

    // address=[0x15538c0]
    virtual void  Store(std::ostream &);

    // address=[0x1554b30]
    virtual  ~CManakopter(void);

    // address=[0x1554fc0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x3d8bba0]
    static unsigned long m_iClassID;

protected:
    // address=[0x4105360]
    static class CAIConfigInt s_iManakopterHitPoints;

    // address=[0x410536c]
    static class CAIConfigInt s_iManakopterArmor;

};


#endif // CMANAKOPTER_H
