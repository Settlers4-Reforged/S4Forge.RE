#ifndef CGAMEDATA_H
#define CGAMEDATA_H

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
    std::string  GetModeString(void);

    // address=[0x14aad60]
    std::string  GetTypeString(void);

    // address=[0x14aaf30]
    void  SetLastFrameRendered(bool);

    // address=[0x14b4a60]
    void  TeamWon(int);

};


#endif // CGAMEDATA_H
