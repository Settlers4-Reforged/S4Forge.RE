#ifndef CRESIDENCEBUILDINGROLE_H
#define CRESIDENCEBUILDINGROLE_H

class CResidenceBuildingRole : public IBuildingRole {
public:
    // address=[0x1401940]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14fcae0]
     CResidenceBuildingRole(void);

    // address=[0x14fcd00]
    virtual  ~CResidenceBuildingRole(void);

    // address=[0x14fd160]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14fd3e0]
    virtual int  GetBuildingNeed(int)const;

    // address=[0x14fd540]
    virtual int  GetBuildingRole(void);

    // address=[0x14fd680]
    virtual int  GetPileIdWithGood(int)const;

    // address=[0x14fd740]
    virtual void  GoodArrive(int);

    // address=[0x14fdbb0]
    static class CResidenceBuildingRole * __cdecl Load(std::istream &);

    // address=[0x1518780]
    virtual void  LogicUpdate(class CBuilding *);

    // address=[0x1518af0]
    virtual void  FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &);

    // address=[0x1518b40]
    virtual void  Init(class CBuilding *);

    // address=[0x1518c80]
    virtual void  PostLoadInit(class CBuilding *);

    // address=[0x1518cb0]
    virtual void  FillDialog(class CBuilding *,bool);

    // address=[0x1518e10]
    int  ReturnRemainingSettlers(void);

    // address=[0x1518e50]
     CResidenceBuildingRole(std::istream &);

    // address=[0x1518f10]
    virtual void  Store(std::ostream &);

    // address=[0x3d8b58c]
    static unsigned long m_iClassID;

private:
    // address=[0x14fd240]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x14fde70]
    virtual bool  TryCrushBuilding(void);

    // address=[0x1518f60]
    virtual bool  CrushBuilding(void);

};


#endif // CRESIDENCEBUILDINGROLE_H
