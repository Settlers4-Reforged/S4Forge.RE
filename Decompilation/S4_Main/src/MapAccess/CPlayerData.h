#ifndef CPLAYERDATA_H
#define CPLAYERDATA_H

#include "defines.h"

// This is distinct from Main/Player/CPlayerData and only really used by the Map Generator

class CPlayerData {
public:
    // address=[0x2fc5330]
    CPlayerData(int a2, bool a3);

    // address=[0x2fc5390]
    void setStartPos_Basic(int a2, int a3);

    // address=[0x2fc53b0]
    void getStartPos_Basic(int &a2, int &a3);

    // address=[0x2fc53e0]
    void setStartPos_Real(int a2, int a3);

    // address=[0x2fc5400]
    void getStartPos_Real(int &a2, int &a3);

    // address=[0x2fc5430]
    void getNearestMountain(int &a2, int &a3);

    // address=[0x2fc5460]
    void setNearestMountain(int a2, int a3);

    // address=[0x2fc5480]
    int getRace(void);

    // address=[0x2fc54a0]
    bool isAI(void);

    // Type information members
public:
    int  m_iBasicX;
    int  m_iBasicY;
    int  m_iRealX;
    int  m_iRealY;
    int  m_iNearestMountainX;
    int  m_iNearestMountainY;
    int  m_iRace;
    bool m_bIsAI;
};


#endif // CPLAYERDATA_H
