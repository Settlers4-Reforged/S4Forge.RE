#ifndef CBIGTEMPLEROLE_H
#define CBIGTEMPLEROLE_H

class CBigTempleRole : public IBuildingRole {
public:
    // address=[0x13ffbe0]
    static class CPersistence * __cdecl New(std::istream &);

    // address=[0x14e8200]
    virtual void  LogicUpdate(class CBuilding *);

    // address=[0x14e8350]
    virtual void  FillGfxInfo(class CBuilding *,struct SGfxObjectInfo &);

    // address=[0x14e83a0]
    virtual void  Init(class CBuilding *);

    // address=[0x14e8400]
    virtual void  PostLoadInit(class CBuilding *);

    // address=[0x14e8430]
    virtual void  FillDialog(class CBuilding *,bool);

    // address=[0x14e8560]
     CBigTempleRole(std::istream &);

    // address=[0x14e8630]
    virtual void  Store(std::ostream &);

    // address=[0x14e8850]
    virtual  ~CBigTempleRole(void);

    // address=[0x14e88d0]
    virtual unsigned long  ClassID(void)const;

    // address=[0x14e8930]
    virtual int  GetBuildingNeed(int)const;

    // address=[0x14e8950]
    virtual int  GetBuildingRole(void);

    // address=[0x14e8970]
    virtual int  GetPileIdWithGood(int)const;

    // address=[0x14e8990]
    virtual void  GoodArrive(int);

    // address=[0x14fc8d0]
     CBigTempleRole(void);

    // address=[0x14fd870]
    static class CBigTempleRole * __cdecl Load(std::istream &);

    // address=[0x3d8b08c]
    static unsigned long m_iClassID;

private:
    // address=[0x14e8680]
    void  ThrowOutPriest(class CBuilding *);

    // address=[0x14e88f0]
    virtual void  ConvertEventIntoGoal(class CBuilding *,class CEntityEvent *);

    // address=[0x14e8900]
    virtual bool  CrushBuilding(void);

    // address=[0x14e89a0]
    virtual bool  TryCrushBuilding(void);

};


#endif // CBIGTEMPLEROLE_H
