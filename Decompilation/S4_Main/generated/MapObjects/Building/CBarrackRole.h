#ifndef CBARRACKROLE_H
#define CBARRACKROLE_H

class CBarrackRole : public IBuildingRole {
public:
    // address=[0x13ffb40]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14e6900]
     CBarrackRole(void);

    // address=[0x14e6940]
    virtual void  LogicUpdate(class CBuilding *);

    // address=[0x14e6f50]
    virtual void  FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &);

    // address=[0x14e7040]
    virtual void  Init(class CBuilding *);

    // address=[0x14e72e0]
    virtual void  PostLoadInit(class CBuilding *);

    // address=[0x14e7310]
    virtual bool  SettlerEnter(class CBuilding *,int);

    // address=[0x14e7320]
    virtual int  GetBuildingNeed(int)const;

    // address=[0x14e73c0]
    virtual int  GetPileIdWithGood(int)const;

    // address=[0x14e7450]
    virtual void  InhabitantFlee(int);

    // address=[0x14e7460]
    void  FillAddSoldierSideBar(class CAddSoldierSideBarInfo *,bool);

    // address=[0x14e76c0]
     CBarrackRole(std::istream &);

    // address=[0x14e77f0]
    virtual void  Store(std::ostream &);

    // address=[0x14e8030]
    virtual  ~CBarrackRole(void);

    // address=[0x14e80a0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14e8120]
    virtual int  GetBuildingRole(void);

    // address=[0x14e8140]
    virtual void  GoodArrive(int);

    // address=[0x14fd830]
    static class CBarrackRole * __cdecl Load(std::istream &);

    // address=[0x3d8af58]
    static unsigned long m_iClassID;

private:
    // address=[0x14e78a0]
    virtual void  FillDialog(class CBuilding *,bool);

    // address=[0x14e80c0]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x14e80d0]
    virtual bool  CrushBuilding(void);

    // address=[0x14e81f0]
    virtual bool  TryCrushBuilding(void);

};


#endif // CBARRACKROLE_H
