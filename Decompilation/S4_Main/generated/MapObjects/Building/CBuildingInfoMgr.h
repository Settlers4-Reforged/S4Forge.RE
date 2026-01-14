#ifndef CBUILDINGINFOMGR_H
#define CBUILDINGINFOMGR_H

class CBuildingInfoMgr {
public:
    // address=[0x133ac00]
    static struct SBuildingInfos const & __cdecl CBuildingInfoMgr::GetBuildingInfo(int,int);

    // address=[0x1486f70]
    int  GetXMLVersion(void)const;

    // address=[0x14eb8f0]
     CBuildingInfoMgr(void);

    // address=[0x14eb910]
     ~CBuildingInfoMgr(void);

    // address=[0x14eb930]
    void  LoadInfo(bool);

    // address=[0x14eb970]
    bool  DbgCheckBuildingBits(int,int);

    // address=[0x14ec5d0]
    void  DbgTraceProductionDelays(void);

    // address=[0x14f3cc0]
    static bool __cdecl BuildingTypeExIsPort(int);

    // address=[0x14f3d00]
    static bool __cdecl BuildingTypeExIsShipyard(int);

    // address=[0x1501110]
    static struct STriggerInfos const & __cdecl CBuildingInfoMgr::GetTriggerInfo(int,int);

private:
    // address=[0x14ec6c0]
    void  ClearInfo(void);

    // address=[0x14ec810]
    void  ReadBuildingInfo(void);

    // address=[0x4033188]
    static struct STriggerInfos (* CBuildingInfoMgr::m_vTriggerInfos)[47];

    // address=[0x4035294]
    static bool m_bInit;

    // address=[0x40352a0]
    static struct SBuildingInfos (* CBuildingInfoMgr::m_vBuildingInfos)[83];

};


#endif // CBUILDINGINFOMGR_H
