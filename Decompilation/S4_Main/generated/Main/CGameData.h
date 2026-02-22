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
    _DWORD dword0;
    _DWORD dword4;
    _DWORD dword8;
    _DWORD dwordC;
    _DWORD dword10;
    _DWORD dword14;
    _DWORD dword18;
    _DWORD dword1C;
    _DWORD dword20;
    _DWORD dword24;
    _BYTE byte28;
    _BYTE byte29;
    _BYTE[2] gap2A;
    int m_sRandom;
    _BYTE[4] gap30;
    _BYTE byte34;
    _BYTE[3] gap35;
    _DWORD dword38;
    _DWORD m_iType;
    std::string std__string40;
    _DWORD m_iMode;
    std::string std__string60;
    _WORD word7C;
    _BYTE byte7E;
    _BYTE byte7F;
    char char80;

};


#endif // CGAMEDATA_H
