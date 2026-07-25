#ifndef IBUILDINGROLE_H
#define IBUILDINGROLE_H

#include "defines.h"

class IBuildingRole : public CPersistence {
public:
    // address=[0x130f040]
    bool  HaveInhabitant(void)const;

    // address=[0x14e66e0]
    virtual  ~IBuildingRole(void);

    // address=[0x14e67d0]
    virtual int  GetPileIdWithNeedForGood(int a2)const;

    // address=[0x14e6800]
    virtual bool  HasShipAmmo(int a1)const;

    // address=[0x14e6820]
    virtual void  LockPiles(class CBuilding * a2, bool a3);

    // address=[0x14e6840]
    virtual void  NotifySelected(void);

    // address=[0x14e6850]
    virtual void  OrderInhabitantCancelled(class CBuilding * a2);

    // address=[0x14e68b0]
    virtual bool  SettlerEnter(class CBuilding * a2, int a3);

    // address=[0x14e68e0]
    virtual void  SwitchPriority(void);

    // address=[0x14fdee0]
     IBuildingRole(void);

    // address=[0x14fdfb0]
    virtual void  Update(class CBuilding * _pBuilding);

    // address=[0x14fe560]
    virtual void  Switch(void);

    // address=[0x14fe6b0]
    virtual void  InhabitantFlee(int _iSettlerId);

    // address=[0x14fe750]
    virtual void  ReturnBuildingMaterial(class CBuilding * a2);

    // address=[0x14fe8d0]
    virtual void  RemoveInhabitant(class CBuilding * a2);

    // address=[0x14feaf0]
    virtual bool  SearchInWorkingArea(class CBuilding * _pBuilding, int a3);

    // address=[0x14ff140]
    virtual int  Decrease(int a2);

    // address=[0x14ff180]
    void  TakeJobTrigger(int a2);

    // address=[0x14ff580]
    void  PostLoadSetWaterFlags(class CBuilding * a2);

    // address=[0x14ff650]
     IBuildingRole(std::istream & a2);

    // address=[0x14ffaa0]
    virtual void  Store(std::ostream & _rStream);

protected:
    // address=[0x14ffe90]
    virtual void  KillInhabitant(class CBuilding * a2);

    // address=[0x14ffea0]
    void  InitCommon(class CBuilding * a2);

    // address=[0x14fff70]
    void  InitHousePatches(void);

    // address=[0x1500310]
    virtual bool  OrderInhabitant(class CBuilding * a2);

    // address=[0x15003d0]
    void  MiniFlag(struct SGfxObjectInfo & _rGfxInfo, int _iPlayer);

    // address=[0x1500590]
    void  WorkingAreaChanged(void);

    // address=[0x1500620]
    void  DetachWithoutNotify(class CBuilding * a2, int a3);

    // address=[0x40f21a4]
    static int m_iLastMiniFlagUpdateTick;

private:
    // address=[0x14e6830]
    virtual void  NotifyDetach(class CBuilding * a2, int a3);

    // Type information members
public:
    unsigned __int8 m_uLogicState;
    unsigned __int8 m_iDelayTick;
    unsigned __int16 m_iEntityId;
    unsigned __int16 m_uSettlerId;
    __int16 m_iLastTick;
    unsigned __int16 m_iFoundSearch;
    _BYTE[2] gap_E;
    int m_iFoundWorkAreaItemXY;
    unsigned __int16[4] m_vWorkingArea;
    bool m_bHasWarnedAboutEmptyWA;
    _BYTE m_bInhabitants;
    _BYTE[2] gap_1E;
    int (__cdecl *)(unsigned int, unsigned int, _DWORD) m_pSearchFkt;
    _BYTE[40] gap_24;
    IBuildingRole::SPair[10] m_vPatchPairs;
    IBuildingRole::SGroup[10] m_vPatches;
    unsigned __int8 m_uEffectId;
    unsigned __int8 m_uEffectDuration;
    unsigned __int8 m_uMilitaryTick;
    unsigned __int8 m_iEffectFrame;
    __int16 m_uEffectX;
    __int16 m_uEffectY;
    unsigned __int8 m_uEffectSmoke;
    unsigned __int8 byte16D;
    int m_iEffectSoundId;
    unsigned __int8 m_iEffectSoundRandomness;
    unsigned __int8 m_iEffectSoundFrame;
    const CBuildingInfoMgr::SBuildingInfos * m_pBuildingInfo;

};


#endif // IBUILDINGROLE_H
