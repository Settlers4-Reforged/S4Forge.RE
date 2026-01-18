#ifndef CPLAYERDATA_H
#define CPLAYERDATA_H

#include "defines.h"

class CPlayerData {
public:
    // address=[0x2fbefb0]
     CPlayerData(void);

    // address=[0x2fbefd0]
    void  Init(void);

    // address=[0x2fbf0f0]
    int  GetNumberOfPlayers(void);

    // address=[0x2fbf110]
    int  GetNumberOfSetups(void);

    // address=[0x2fbf130]
    int  AddPlayer(int a2, int a3, int a4, char * Source);

    // address=[0x2fbf1e0]
    int  DeletePlayer(int a2);

    // address=[0x2fbf270]
    int  AddSetup(void);

    // address=[0x2fbf300]
    int  DeleteSetup(int a2);

    // address=[0x2fbf390]
    int  GetRaceOfPlayer(int a2);

    // address=[0x2fbf3d0]
    int  GetXOfPlayer(int a2);

    // address=[0x2fbf410]
    int  GetYOfPlayer(int a2);

    // address=[0x2fbf450]
    void  ChangePlayer(int a2, int a3);

    // address=[0x2fbf560]
    char *  GetNameOfPlayer(int a2);

    // address=[0x2fbf5a0]
    char *  GetSetupName(int a2);

    // address=[0x2fbf5c0]
    int  GetControlOfPlayer(int a2, int a3);

    // address=[0x2fbf610]
    int  GetTeamOfPlayer(int a2, int a3);

    // address=[0x2fbf660]
    void  SetRaceOfPlayer(int a2, int a3);

    // address=[0x2fbf6a0]
    void  SetXOfPlayer(int a2, int a3);

    // address=[0x2fbf6e0]
    void  SetYOfPlayer(int a2, int a3);

    // address=[0x2fbf720]
    void  SetNameOfPlayer(int a2, char * Source);

    // address=[0x2fbf770]
    void  SetSetupName(int a2, char * Source);

    // address=[0x2fbf7a0]
    void  SetControlOfPlayer(int a2, int a3, int a4);

    // address=[0x2fbf7f0]
    void  SetTeamOfPlayer(int a2, int a3, int a4);

    // address=[0x2fbf840]
    int  Save(unsigned char * a2);

    // address=[0x2fbf890]
    int  SaveTeamData(unsigned char * a2, int a3);

    // address=[0x2fbf900]
    int  Load(unsigned char * lpBuffer, void * hFile, struct SMapChunkHeader a4);

    // address=[0x2fbf980]
    int  LoadTeamData(unsigned char * lpBuffer, void * hFile, struct SMapChunkHeader a4);

    // address=[0x2fbfa50]
    int  GetSizeOfPlayerElement(void);

    // address=[0x2fbfa60]
    int  GetSizeOfTeamElement(void);

    // address=[0x2fbfa70]
    int  CheckTeams(void);

    // address=[0x2fc5330]
     CPlayerData(int a2, bool a3);

    // address=[0x2fc5390]
    void  setStartPos_Basic(int a2, int a3);

    // address=[0x2fc53b0]
    void  getStartPos_Basic(int & a2, int & a3);

    // address=[0x2fc53e0]
    void  setStartPos_Real(int a2, int a3);

    // address=[0x2fc5400]
    void  getStartPos_Real(int & a2, int & a3);

    // address=[0x2fc5430]
    void  getNearestMountain(int & a2, int & a3);

    // address=[0x2fc5460]
    void  setNearestMountain(int a2, int a3);

    // address=[0x2fc5480]
    int  getRace(void);

    // address=[0x2fc54a0]
    bool  isAI(void);

};


#endif // CPLAYERDATA_H
