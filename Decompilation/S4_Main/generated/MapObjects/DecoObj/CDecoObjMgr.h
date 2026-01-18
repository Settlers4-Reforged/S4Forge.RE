#ifndef CDECOOBJMGR_H
#define CDECOOBJMGR_H

#include "defines.h"

class CDecoObjMgr {
public:
    // address=[0x1326ec0]
    static class IDecoObject * __cdecl GetDecoObjPtr(int a1);

    // address=[0x1486f90]
    int  GetXMLVersion(void)const;

    // address=[0x15423a0]
    void *  Alloc(unsigned int a2);

    // address=[0x1542400]
    void  Dealloc(void * a2);

    // address=[0x1542430]
    int  GetTotalBuildingRings(int a2);

    // address=[0x1542490]
     CDecoObjMgr(void);

    // address=[0x15425c0]
     ~CDecoObjMgr(void);

    // address=[0x15425e0]
    void  Clear(void);

    // address=[0x1542610]
    void  LoadInfo(void);

    // address=[0x1542640]
    bool  IsAddDecoObjOk(int a2, int a3, int a4, bool a5, int a6);

    // address=[0x15428b0]
    int  AddDecoObj(int a2, int a3, int a4, int a5, enum CDecoObjMgr::TGROWN_STATE a6);

    // address=[0x1542970]
    int  AddReef(int a2, int a3, int a4, int a5, enum CDecoObjMgr::TGROWN_STATE a6);

    // address=[0x1542a80]
    int  AddDecoObjWithoutFlags(int a2, int a3, int a4, int a5, enum CDecoObjMgr::TGROWN_STATE a6);

    // address=[0x1542b50]
    int  AddLoadedDecoObj(int a2, int a3, int a4, int a5, int a6, bool a7, std::istream * a8);

    // address=[0x1542c20]
    void  Delete(int a2);

    // address=[0x1542cf0]
    void  DeleteWithoutFlags(int a2);

    // address=[0x1542da0]
    int  RemoveDecoObject(int a2, int a3, bool a4);

    // address=[0x1542ed0]
    int  RemoveReef(int a2, int a3, bool a4);

    // address=[0x1543000]
    void  GetDecoObjectFlagsInfo(int a2, bool & a3, int & a4, int & a5);

    // address=[0x1543080]
    void  SetFlagsForObject(int a2, int a3, int a4, bool a5);

    // address=[0x15434b0]
    void  ClearFlagsForObject(int a2, int a3, int a4, bool a5);

    // address=[0x15438a0]
    int  GetObjectType(int a2, int a3, int a4);

    // address=[0x1543a60]
    void  ChangeToStaticInstance(int a2, int a3, int a4, int a5);

    // address=[0x1543c20]
    int  ConvertGreenToDark(int a1)const;

    // address=[0x1543c40]
    int  ConvertDarkToGreen(int a1)const;

    // address=[0x1543c60]
    int  GetThisDecoObj(int a1, int a2, int a3, int & a4, int & a5);

    // address=[0x1543dd0]
    bool  IsFlower(int a2);

    // address=[0x1543e20]
    bool  IsGeologistSign(int a2);

    // address=[0x1543e90]
    void  Rod(int a2, bool a3);

    // address=[0x1544590]
    void  Store(class S4::CMapFile &);

    // address=[0x1544810]
    void  Load(class S4::CMapFile &);

private:
    // address=[0x1544b00]
    int  Create(int a2, int a3, int a4, int a5, enum CDecoObjMgr::TGROWN_STATE a6, int a7, std::istream * a8);

    // address=[0x1546340]
    void  ReadObjectInfos(void);

};


#endif // CDECOOBJMGR_H
