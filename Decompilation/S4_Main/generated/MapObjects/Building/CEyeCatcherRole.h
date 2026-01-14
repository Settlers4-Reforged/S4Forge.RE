#ifndef CEYECATCHERROLE_H
#define CEYECATCHERROLE_H

class CEyeCatcherRole : public IBuildingRole {
public:
    // address=[0x1400860]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14fc970]
     CEyeCatcherRole(void);

    // address=[0x14fcbf0]
    virtual  ~CEyeCatcherRole(void);

    // address=[0x14fd0a0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd340]
    virtual int  GetBuildingNeed(int)const;

    // address=[0x14fd480]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd5e0]
    virtual int  GetPileIdWithGood(int)const;

    // address=[0x14fd6f0]
    virtual void  GoodArrive(int);

    // address=[0x14fd9b0]
    static class CEyeCatcherRole * __cdecl Load(std::istream &);

    // address=[0x150a110]
    virtual void  LogicUpdate(class CBuilding *);

    // address=[0x150a120]
    virtual void  FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &);

    // address=[0x150a240]
    virtual void  Init(class CBuilding *);

    // address=[0x150a280]
    virtual void  PostLoadInit(class CBuilding *);

    // address=[0x150a2b0]
    virtual void  FillDialog(class CBuilding *,bool);

    // address=[0x150a400]
     CEyeCatcherRole(std::istream &);

    // address=[0x150a4b0]
    virtual void  Store(std::ostream &);

    // address=[0x3d8b12c]
    static unsigned long m_iClassID;

private:
    // address=[0x14fd1f0]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x14fd270]
    virtual bool  CrushBuilding(void);

    // address=[0x14fde20]
    virtual bool  TryCrushBuilding(void);

};


#endif // CEYECATCHERROLE_H
