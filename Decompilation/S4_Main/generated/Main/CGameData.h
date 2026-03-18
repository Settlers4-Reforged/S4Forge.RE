#ifndef CGAMEDATA_H
#define CGAMEDATA_H

#include "defines.h"

class CGameData {
public:
    // address=[0x1360fd0]
     CGameData(void);

    // address=[0x1361270]
    bool  IsTutorial(void);

    // address=[0x13612a0]
    bool  IsCampaign(void);

    // address=[0x13612d0]
    bool  IsLadder(void);

    // address=[0x1395840]
    int  GetMode(void);

    // address=[0x139fe80]
    bool  IsNetworkGame(void);

    // address=[0x144fe90]
    unsigned int  GetTickCounter(void)const;

    // address=[0x144feb0]
    bool  IsGameWon(void);

    // address=[0x144ff50]
    int  TeamWon(void);

    // address=[0x14606b0]
    bool  IsLastFrameRendered(void);

    // address=[0x146ae80]
    unsigned int  Rand(void);

    // address=[0x147a2f0]
    unsigned char *  GetEconomyGoodsArray(void);

    // address=[0x14aa9a0]
     ~CGameData(void);

    // address=[0x14aac40]
    std::string  GetModeString(void a2);

    // address=[0x14aad60]
    std::string  GetTypeString(void a2);

    // address=[0x14aaf30]
    void  SetLastFrameRendered(bool a2);

    // address=[0x14b4a60]
    void  TeamWon(int a2);

    // Type information members
public:
    _DWORD m_uTickCounter;
    _DWORD m_uVirtualTick;
    _DWORD m_iHeight;
    _DWORD m_iWidth;
    _DWORD dword10;
    _DWORD m_uCamX;
    _DWORD m_uCamY;
    _DWORD m_uZoom;
    _DWORD dword20;
    _DWORD dword24;
    _BYTE byte28;
    _BYTE m_bFixedStartCamera;
    _BYTE[2] gap2A;
    CRandom16Ex m_sRandom;
    _BYTE m_bIsGameWon;
    _BYTE[3] gap35;
    _DWORD m_iTeamWon;
    _DWORD m_iType;
    std::string m_swGameType;
    _DWORD m_iMode;
    std::string m_swMapMode;
    _BYTE m_bIsNetworkGame;
    _BYTE m_bIsLastFrameRendered;
    _BYTE byte7E;
    _BYTE m_bIsLadderGame;
    char[7] m_pEconomyGoodsArray;

};


#endif // CGAMEDATA_H
