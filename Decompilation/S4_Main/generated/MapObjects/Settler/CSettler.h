#ifndef CSETTLER_H
#define CSETTLER_H

class CSettler : public IMovingEntity {
public:
    // address=[0x130f340]
    class ISettlerRole &  Role(void);

    // address=[0x1401bc0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x1439aa0]
    int  GetNextSettlerType(void);

    // address=[0x1439e70]
    bool  SetNextSettlerType(int);

    // address=[0x1439f80]
    bool  Strike(void)const;

    // address=[0x15081e0]
    void  SetFree(void);

    // address=[0x1513ad0]
    void  SetBuilding(int);

    // address=[0x1513b30]
    void  SetOffset(float,float);

    // address=[0x157d1f0]
    virtual void  Delete(void);

    // address=[0x157d3f0]
    virtual void  LogicUpdate(void);

    // address=[0x157d4b0]
    virtual struct SGfxObjectInfo *  GetGfxInfos(void);

    // address=[0x157dae0]
    void  GetPatchGfx(struct SGfxPatchObject &);

    // address=[0x157db70]
    void  NewRole(class std::auto_ptr<class ISettlerRole>);

    // address=[0x157dca0]
    virtual void  NewToDoList(class std::list<class CEntityTask,class std::allocator<class CEntityTask> > *,int);

    // address=[0x157dda0]
    void  TakeWaitList(void);

    // address=[0x157dde0]
    void  TakeAnimList(int);

    // address=[0x157ded0]
    void  AttachToBuilding(int);

    // address=[0x157df70]
    void  CheckFlee(int);

    // address=[0x157df90]
    void  ChangeType(int,bool,bool);

    // address=[0x157e450]
    void  ChangeTypeComeToBuilding(int,int);

    // address=[0x157e500]
    static void * __cdecl operator new(unsigned int);

    // address=[0x157e520]
    static void __cdecl operator delete(void *);

    // address=[0x157e560]
    virtual void  SetObserverTarget(enum T_OBSERVER_TARGET,int);

    // address=[0x157e5c0]
    virtual int  GetObserverTarget(enum T_OBSERVER_TARGET);

    // address=[0x157e5f0]
    virtual int  Increase(int);

    // address=[0x157e680]
    void  MarkSourcePile2AsUnused(void);

    // address=[0x157e6a0]
    void  MarkSourcePile3AsUnused(void);

    // address=[0x157e6c0]
    virtual int  MaxHitpoints(void)const;

    // address=[0x157e700]
     CSettler(std::istream &);

    // address=[0x157ea60]
    virtual void  Store(std::ostream &);

    // address=[0x157ff80]
    virtual unsigned long  ClassID(void)const;

    // address=[0x157ffa0]
    virtual int  ClearGroupFlagBits(int);

    // address=[0x1580040]
    virtual int  GetGroupFlags(void)const;

    // address=[0x1580080]
    virtual class CWarriorBehavior *  GetWarriorBehavior(void)const;

    // address=[0x15800c0]
    virtual bool  IsUnEmployed(void)const;

    // address=[0x1580130]
    virtual int  SetGroupFlagBits(int);

    // address=[0x1580170]
    virtual int  SetGroupFlags(int);

    // address=[0x3d8befc]
    static unsigned long m_iClassID;

protected:
    // address=[0x157ec10]
     CSettler(int,int,int,int,class std::auto_ptr<class ISettlerRole>,int);

    // address=[0x157eec0]
     CSettler(int,int);

    // address=[0x157ef70]
     CSettler(int,int,int,class std::auto_ptr<class ISettlerRole>,int);

    // address=[0x157f0e0]
    virtual  ~CSettler(void);

    // address=[0x157f110]
    int  Walk(void);

    // address=[0x157f190]
    int  WalkDir(int);

    // address=[0x157f570]
    virtual void  Decrease(int);

    // address=[0x157ffe0]
    virtual void  ConvertEventIntoGoal(class CEntityEvent *);

    // Type information members
private:
    ISettlerRole * role;

};


#endif // CSETTLER_H
