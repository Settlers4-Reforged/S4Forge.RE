#ifndef CSIMPLEBUILDINGROLE_H
#define CSIMPLEBUILDINGROLE_H

class CSimpleBuildingRole : public IBuildingRole {
public:
    // address=[0x1401da0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14fcb10]
     CSimpleBuildingRole(void);

    // address=[0x14fcd20]
    virtual  ~CSimpleBuildingRole(void);

    // address=[0x14fd180]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd400]
    virtual int  GetBuildingNeed(int)const;

    // address=[0x14fd560]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd6a0]
    virtual int  GetPileIdWithGood(int)const;

    // address=[0x14fd750]
    virtual void  GoodArrive(int);

    // address=[0x14fdbf0]
    static class CSimpleBuildingRole * __cdecl Load(std::istream &);

    // address=[0x151ab50]
    virtual void  LogicUpdate(class CBuilding *);

    // address=[0x151b270]
    virtual void  FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &);

    // address=[0x151b340]
    virtual void  Init(class CBuilding *);

    // address=[0x151b420]
    virtual void  PostLoadInit(class CBuilding *);

    // address=[0x151b4d0]
    virtual bool  SettlerEnter(class CBuilding *,int);

    // address=[0x151b740]
    virtual void  FillDialog(class CBuilding *,bool);

    // address=[0x151ba20]
     CSimpleBuildingRole(std::istream &);

    // address=[0x151bae0]
    virtual void  Store(std::ostream &);

    // address=[0x3d8b798]
    static unsigned long m_iClassID;

private:
    // address=[0x14fd250]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x14fd2b0]
    virtual bool  CrushBuilding(void);

    // address=[0x14fde80]
    virtual bool  TryCrushBuilding(void);

};


#endif // CSIMPLEBUILDINGROLE_H
