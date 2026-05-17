#ifndef CBUILDINGINFOMGR_H
#define CBUILDINGINFOMGR_H

#include "defines.h"
#include "Defines/Buildings.h"
#include "Defines/Races.h"
#include "Defines/Triggers.h"

class CBuildingInfoMgr {
public:
    struct SBuildingInfos {
        char m_iHotSpotX;
        char m_iHotSpotY;
        BYTE m_iStone;
        BYTE m_iBoards;
        BYTE m_iGold;

        _BYTE m_iLines;

        BYTE m_bIsPort;

        _BYTE m_iBuilderNumber;

        struct SBuilder {
            BYTE m_iXOffset;
            BYTE m_iYOffset;
            BYTE m_iDirection;
        } m_vBuilder[10];

        BYTE m_iFlagX;
        BYTE m_iFlagY;

        BYTE m_iDoorXOffset;
        BYTE m_iDoorYOffset;

        char   m_iWorkPosXOffset;
        char   m_iWorkPosYOffset;
        _DWORD m_iMiniFlagXOffset;
        _DWORD m_iMiniFlagYOffset;

        char m_iBBRMinX;
        char m_iBBRMaY;
        char m_iBBRMinY;
        char m_iBBRMaxY;

        BYTE m_iMaxDistance;

        char m_iPileNumber;

        struct SPileSpot {
            char   m_uXOffset;
            char   m_uYOffset;
            char   m_iGood;
            _BYTE  m_iType;
            _BYTE  m_iAppearance;
            _BYTE  m_iPatch;
            DWORD  m_iXPixelOffset;
            _DWORD m_iYPixelOffset;
        } m_vPileSpots[10];

        BYTE  m_uWarriorNumber;
        _BYTE m_uSwordsmanNumber;
        BYTE  m_uBowmanNumber;
        BYTE  m_uU0;

        struct SSettlerSpot {
            DWORD m_iXOffset;
            DWORD m_iYOffset;
            _BYTE m_iDirection;
            bool  m_bTop;
            _BYTE gap_B;
            _BYTE gap_0;
        } m_vSettlerSpots[21];

        BYTE   m_iPatchSettlerSlot;
        _BYTE  m_iBuildingKind;
        BYTE   m_iBuildingInhabitant;
        _BYTE  m_iTool;
        BYTE   m_iProductionDelay;
        _BYTE  m_iSearchType;
        _DWORD m_iInfluenceRadius;
        _DWORD m_iExplorerRadius;
        _DWORD m_iWorkingAreaRadius;
        DWORD  m_iDummyValue;
        BYTE   m_iHealth;
        _BYTE  m_iArmor;

        struct SPatch {
            DWORD m_iJob;
            BYTE  m_iSlot;
            BYTE  m_iType;
            BYTE  m_iTicks;
            DWORD m_iSound;
            BYTE  m_iSoundRandomness;
            BYTE  m_iSoundFrame;
        } m_vPatches[10];

        DWORD m_vTriggers[10];

        std::vector<unsigned char> m_vAnimationList;
        std::vector<unsigned int>  m_vBuildingPosLines;
        std::vector<unsigned int>  m_vDigPosLines;
        std::vector<unsigned int>  m_vBlockPosLines;
        std::vector<unsigned int>  m_vRepealingPosLines;
        std::vector<unsigned int>  m_vWaterPosLines;
        std::vector<unsigned int>  m_vWaterBlockPosLines;
        std::vector<unsigned int>  m_vWaterRepealingPosLines;
        std::vector<unsigned int>  m_vWaterFreePosLines;
    };

    struct STriggerInfos {
        _DWORD m_iPatchDefine;
        BYTE   m_iSlot;
        BYTE   m_iType;
        BYTE   m_iDuration;
        _DWORD m_iPatchSoundId;
        BYTE   m_iPatchSoundRandomness;
        BYTE   m_iPatchSoundFrame;
        _DWORD m_iEffectId;
        WORD   m_iEffectX;
        WORD   m_iEffectY;
        BYTE   m_iEffectDuration;
        BYTE   m_bSmoke;
        _DWORD m_iEffectSoundId;
        BYTE   m_iEffectSoundRandomness;
    };


    // address=[0x133ac00]
    static struct SBuildingInfos const & __cdecl CBuildingInfoMgr::GetBuildingInfo(int a1, int a2);

    // address=[0x1486f70]
    int GetXMLVersion(void) const;

    // address=[0x14eb8f0]
    CBuildingInfoMgr(void);

    // address=[0x14eb910]
    ~CBuildingInfoMgr(void);

    // address=[0x14eb930]
    void LoadInfo(bool a2);

    // address=[0x14eb970]
    bool DbgCheckBuildingBits(int _iRace, int _iBuildingType);

    // address=[0x14ec5d0]
    void DbgTraceProductionDelays(void);

    // address=[0x14f3cc0]
    static bool __cdecl BuildingTypeExIsPort(int a1);

    // address=[0x14f3d00]
    static bool __cdecl BuildingTypeExIsShipyard(int a1);

    // address=[0x1501110]
    static STriggerInfos const & __cdecl CBuildingInfoMgr::GetTriggerInfo(int a1, int a2);

private:
    // address=[0x14ec6c0]
    void ClearInfo(void);

    // address=[0x14ec810]
    void ReadBuildingInfo(void);

    // address=[0x4033188]
    // static struct STriggerInfos (*CBuildingInfoMgr::m_vTriggerInfos)[47];
    static STriggerInfos m_vTriggerInfos[RACE_MAX][MAX_TRIGGERS];

    // address=[0x4035294]
    static bool m_bInit;

    // address=[0x40352a0]
    //static struct SBuildingInfos (*CBuildingInfoMgr::m_vBuildingInfos)[83];
    static SBuildingInfos m_vBuildingInfos[RACE_MAX][BUILDING_MAX];

    // Type information members
public:
    int m_iXmlVersion;
};


#endif // CBUILDINGINFOMGR_H
