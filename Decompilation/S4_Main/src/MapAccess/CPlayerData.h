#ifndef CPLAYERDATA_H
#define CPLAYERDATA_H

#include "defines.h"

// BEWARE!!! All player ids etc. are 1-based not 0-based!

class CPlayerData {
public:
    // address=[0x2fbefb0]
    CPlayerData(void);

    // address=[0x2fbefd0]
    void Init(void);

    // address=[0x2fbf0f0]
    int GetNumberOfPlayers(void);

    // address=[0x2fbf110]
    int GetNumberOfSetups(void);

    // address=[0x2fbf130]
    int AddPlayer(int _iRace, int _iX, int _iY, char *_spName);

    // address=[0x2fbf1e0]
    int DeletePlayer(int _Number);

    // address=[0x2fbf270]
    int AddSetup(void);

    // address=[0x2fbf300]
    int DeleteSetup(int a2);

    // address=[0x2fbf390]
    int GetRaceOfPlayer(int _Player);

    // address=[0x2fbf3d0]
    int GetXOfPlayer(int _Player);

    // address=[0x2fbf410]
    int GetYOfPlayer(int a2);

    // address=[0x2fbf450]
    void ChangePlayer(int _iSourcePlayer, int _iDestPlayer);

    // address=[0x2fbf560]
    char *GetNameOfPlayer(int a2);

    // address=[0x2fbf5a0]
    char *GetSetupName(int a2);

    // address=[0x2fbf5c0]
    int GetControlOfPlayer(int _Player, int _Setup);

    // address=[0x2fbf610]
    int GetTeamOfPlayer(int _Player, int _Setup);

    // address=[0x2fbf660]
    void SetRaceOfPlayer(int _Player, int _iValue);

    // address=[0x2fbf6a0]
    void SetXOfPlayer(int a2, int a3);

    // address=[0x2fbf6e0]
    void SetYOfPlayer(int a2, int a3);

    // address=[0x2fbf720]
    void SetNameOfPlayer(int _Player, char *_spName);

    // address=[0x2fbf770]
    void SetSetupName(int _iSetup, char *_spName);

    // address=[0x2fbf7a0]
    void SetControlOfPlayer(int _Player, int _iSetup, int _iControl);

    // address=[0x2fbf7f0]
    void SetTeamOfPlayer(int a2, int a3, int a4);

    // address=[0x2fbf840]
    int Save(unsigned char *a2);

    // address=[0x2fbf890]
    int SaveTeamData(unsigned char *a2, int _iSetup);

    // address=[0x2fbf900]
    int Load(unsigned char *lpBuffer, void *hFile, struct SMapChunkHeader a4);

    // address=[0x2fbf980]
    int LoadTeamData(unsigned char *a2, void *a3, struct SMapChunkHeader a4);

    // address=[0x2fbfa50]
    int GetSizeOfPlayerElement(void);

    // address=[0x2fbfa60]
    int GetSizeOfTeamElement(void);

    // address=[0x2fbfa70]
    int CheckTeams(void);

    // omitted everything with setStartPos_Basic - these seem to be part of the map generator CPlayerData that shares the same name with this class here
#pragma pack(push, 1)
    struct Player {
        DWORD m_uRace;
        DWORD m_uX;
        DWORD m_uY;
        char  m_sName[33];
    };

    struct Team {
        BYTE m_iTeam;
        BYTE m_iPlayerControl;
    };
#pragma pack(pop)
    // Type information members
public:
    char m_uSetupNames[10][33];

    CPlayerData::Player m_sPlayers[8];
    CPlayerData::Team   m_sSetups[10][8];

    _BYTE gap_352[2];

    _DWORD m_uNumberOfPlayers;
    int    m_iNumberOfSetups;
};


#endif // CPLAYERDATA_H
