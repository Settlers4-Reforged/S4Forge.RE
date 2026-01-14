#ifndef CDECOOBJMGR_H
#define CDECOOBJMGR_H

class CDecoObjMgr {
public:
    // address=[0x1326ec0]
    static class IDecoObject * __cdecl GetDecoObjPtr(int);

    // address=[0x1486f90]
    int  GetXMLVersion(void)const;

    // address=[0x15423a0]
    void *  Alloc(unsigned int);

    // address=[0x1542400]
    void  Dealloc(void *);

    // address=[0x1542430]
    int  GetTotalBuildingRings(int);

    // address=[0x1542490]
     CDecoObjMgr(void);

    // address=[0x15425c0]
     ~CDecoObjMgr(void);

    // address=[0x15425e0]
    void  Clear(void);

    // address=[0x1542610]
    void  LoadInfo(void);

    // address=[0x1542640]
    bool  IsAddDecoObjOk(int,int,int,bool,int);

    // address=[0x15428b0]
    int  AddDecoObj(int,int,int,int,enum CDecoObjMgr::TGROWN_STATE);

    // address=[0x1542970]
    int  AddReef(int,int,int,int,enum CDecoObjMgr::TGROWN_STATE);

    // address=[0x1542a80]
    int  AddDecoObjWithoutFlags(int,int,int,int,enum CDecoObjMgr::TGROWN_STATE);

    // address=[0x1542b50]
    int  AddLoadedDecoObj(int,int,int,int,int,bool,std::istream *);

    // address=[0x1542c20]
    void  Delete(int);

    // address=[0x1542cf0]
    void  DeleteWithoutFlags(int);

    // address=[0x1542da0]
    int  RemoveDecoObject(int,int,bool);

    // address=[0x1542ed0]
    int  RemoveReef(int,int,bool);

    // address=[0x1543000]
    void  GetDecoObjectFlagsInfo(int,bool &,int &,int &);

    // address=[0x1543080]
    void  SetFlagsForObject(int,int,int,bool);

    // address=[0x15434b0]
    void  ClearFlagsForObject(int,int,int,bool);

    // address=[0x15438a0]
    int  GetObjectType(int,int,int);

    // address=[0x1543a60]
    void  ChangeToStaticInstance(int,int,int,int);

    // address=[0x1543c20]
    int  ConvertGreenToDark(int)const;

    // address=[0x1543c40]
    int  ConvertDarkToGreen(int)const;

    // address=[0x1543c60]
    int  GetThisDecoObj(int,int,int,int &,int &);

    // address=[0x1543dd0]
    bool  IsFlower(int);

    // address=[0x1543e20]
    bool  IsGeologistSign(int);

    // address=[0x1543e90]
    void  Rod(int,bool);

    // address=[0x1544590]
    void  Store(class S4::CMapFile &);

    // address=[0x1544810]
    void  Load(class S4::CMapFile &);

private:
    // address=[0x1544b00]
    int  Create(int,int,int,int,enum CDecoObjMgr::TGROWN_STATE,int,std::istream *);

    // address=[0x1546340]
    void  ReadObjectInfos(void);

};


#endif // CDECOOBJMGR_H
