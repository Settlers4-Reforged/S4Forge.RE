#ifndef CMINEROLE_H
#define CMINEROLE_H

class CMineRole : public IBuildingRole {
public:
    // address=[0x1401440]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14fdb30]
    static class CMineRole * __cdecl Load(std::istream &);

    // address=[0x1513d90]
     CMineRole(void);

    // address=[0x1513e50]
    virtual void  LogicUpdate(class CBuilding *);

    // address=[0x1514060]
    virtual void  FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &);

    // address=[0x1514210]
    virtual void  Init(class CBuilding *);

    // address=[0x1514520]
    virtual void  PostLoadInit(class CBuilding *);

    // address=[0x1514550]
    virtual bool  SettlerEnter(class CBuilding *,int);

    // address=[0x15147f0]
    virtual int  GetPileIdWithGood(int)const;

    // address=[0x1514900]
    virtual void  GoodArrive(int);

    // address=[0x1514970]
    void  RestockFavouriteFood(void);

    // address=[0x1514a00]
    virtual void  FillDialog(class CBuilding *,bool);

    // address=[0x1514ca0]
     CMineRole(std::istream &);

    // address=[0x1514ed0]
    virtual void  Store(std::ostream &);

    // address=[0x1516030]
    virtual  ~CMineRole(void);

    // address=[0x15160b0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x15160d0]
    virtual int  GetBuildingNeed(int)const;

    // address=[0x15160f0]
    virtual int  GetBuildingRole(void);

    // address=[0x3d8b584]
    static unsigned long m_iClassID;

private:
    // address=[0x1515070]
    virtual bool  CrushBuilding(void);

    // address=[0x1515080]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x1515090]
    void  RememberProductivity(class CBuilding *,bool);

    // address=[0x1515100]
    int  GetProductivity(class CBuilding *);

    // address=[0x15151a0]
    void  InitMine(class CBuilding *);

    // address=[0x1515460]
    void  Work(class CBuilding *);

    // address=[0x15155e0]
    void  TakeNextFood(class CBuilding *);

    // address=[0x1515760]
    bool  SearchResource(class CBuilding *);

    // address=[0x1516140]
    virtual bool  TryCrushBuilding(void);

};


#endif // CMINEROLE_H
