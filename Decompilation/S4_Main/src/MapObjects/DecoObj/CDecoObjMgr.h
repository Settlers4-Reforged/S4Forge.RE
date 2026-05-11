#ifndef CDECOOBJMGR_H
#define CDECOOBJMGR_H

#include "defines.h"
#include "Collections/allocmem.h"
#include "LoadSave/CMapFile.h"

// address=[0x40f2320]
extern class CDecoObjMgr g_cDecoObjMgr;

class CDecoObjMgr {
public:
    enum TGROWN_STATE {
        GROW1,
        GROW2,
    };

    // address=[0x1326ec0]
    static class IDecoObject * __cdecl GetDecoObjPtr(int a1);

    // address=[0x1486f90]
    int GetXMLVersion(void) const;

    // address=[0x15423a0]
    void *Alloc(unsigned int a2);

    // address=[0x1542400]
    void Dealloc(void *a2);

    // address=[0x1542430]
    int GetTotalBuildingRings(int a2);

    // address=[0x1542490]
    CDecoObjMgr(void);

    // address=[0x15425c0]
    ~CDecoObjMgr(void);

    // address=[0x15425e0]
    void Clear(void);

    // address=[0x1542610]
    void LoadInfo(void);

    // address=[0x1542640]
    bool IsAddDecoObjOk(int _iX, int _iY, int _iDecoType, bool a5, int _iExtraBuildingRings);

    // address=[0x15428b0]
    int AddDecoObj(int _iX, int _iY, int _iDecoType, int _iAmount, TGROWN_STATE _iGrownState);

    // address=[0x1542970]
    int AddReef(int _iX, int _iY, int _iDecoType, int _iAmount, TGROWN_STATE _iGrownState);

    // address=[0x1542a80]
    int AddDecoObjWithoutFlags(int _iX, int _iY, int _iType, int _iAmount, TGROWN_STATE _iGrownState);

    // address=[0x1542b50]
    int AddLoadedDecoObj(int _iX, int _iY, int _iDecoType, int _iAmount, int _iSlot, bool bIsStaticInstance, std::istream *_pInStream);

    // address=[0x1542c20]
    void Delete(int _iEntityId);

    // address=[0x1542cf0]
    void DeleteWithoutFlags(int _iEntityId);

    // address=[0x1542da0]
    int RemoveDecoObject(int _iX, int _iY, bool a4);

    // address=[0x1542ed0]
    int RemoveReef(int _iX, int _iY, bool a4);

    // address=[0x1543000]
    void GetDecoObjectFlagsInfo(int _iDecoType, bool &a3, int &_rTotalBlockingOrRepellingRing, int &_rTotalRings);

    // address=[0x1543080]
    void SetFlagsForObject(int _iX, int _iY, int _iDecoType, bool _bReefs);

    // address=[0x15434b0]
    void ClearFlagsForObject(int _iX, int _iY, int _iDecoType, bool a5);

    // address=[0x15438a0]
    int GetObjectType(int _iFarmerType, int _iRace, int _iGround);

    // address=[0x1543a60]
    void ChangeToStaticInstance(int _iX, int _iY, int _iDecoType, int a5);

    // address=[0x1543c20]
    int ConvertGreenToDark(int a1) const;

    // address=[0x1543c40]
    int ConvertDarkToGreen(int a1) const;

    // address=[0x1543c60]
    int GetThisDecoObj(int _iX, int _iY, int _iRadius, int &_rX, int &_rY);

    // address=[0x1543dd0]
    bool IsFlower(int _iDecoType);

    // address=[0x1543e20]
    bool IsGeologistSign(int a2);

    // address=[0x1543e90]
    void Rod(int a2, bool a3);

    // address=[0x1544590]
    void Store(class S4::CMapFile &a2);

    // address=[0x1544810]
    void Load(class S4::CMapFile &a2);

private:
    // address=[0x1544b00]
    int Create(int _iX, int _iY, int _iDecoType, int _iAmount, TGROWN_STATE _iGrownState, int _iSlot, std::istream *_pInStream);

    // address=[0x1546340]
    void ReadObjectInfos(void);

    // Type information members
public:
    struct Object {
        BYTE  m_uFrameCount;
        char  m_uCurrentFrame;
        BYTE  count;
        BYTE  m_uU3;
        DWORD id[32];
    };

    struct Ring {
        BYTE m_uUnknown;
        BYTE m_uTotalBlockingRings;
        BYTE m_uRepellingRings;
        BYTE m_uTotalBlockingOrRepellingRings;
        BYTE m_uTotalRings;
        BYTE m_uU5;
        BYTE m_uU6;
        BYTE m_bHasPingPong;
    };

    MemoryAllocator m_cAllocator;
    int             m_iXmlVersion;
    bool            m_bHasLoaded;
    Object          m_vInstanceId[291];
    Ring            m_aBuildingRings[291];
};


#endif // CDECOOBJMGR_H
