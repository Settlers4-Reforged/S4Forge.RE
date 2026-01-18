#ifndef CALLIANCES_H
#define CALLIANCES_H

#include "defines.h"

class CAlliances {
public:
    // address=[0x1301120]
    static int __cdecl AllianceId(int a1);

    // address=[0x1301520]
    static bool __cdecl IsValidUsedPlayerId(int a1);

    // address=[0x1301620]
    static int __cdecl PlayerAllyBits(int a1);

    // address=[0x1301640]
    static int __cdecl PlayerBit(int a1);

    // address=[0x1301660]
    static int __cdecl PlayerEnemyBits(int a1);

    // address=[0x1303c80]
    static int __cdecl LastPlayerId(void);

    // address=[0x13094a0]
    static int const * __cdecl EnemyPlayerIds(int a1);

    // address=[0x130e8e0]
    static int const * __cdecl AllyPlayerIds(int a1);

    // address=[0x13172d0]
    static int __cdecl AllPlayersBits(void);

    // address=[0x1317430]
    static int __cdecl LastAllianceId(void);

    // address=[0x15d2fc0]
    static void __cdecl Init(void);

    // address=[0x15d3010]
    static void __cdecl Done(void);

    // address=[0x15d3040]
    static bool __cdecl AddPlayer(int a1, int a2);

    // address=[0x15d31c0]
    static bool __cdecl Lock(void);

    // address=[0x15d37e0]
    static int __cdecl NumberOfAllies(int a1);

    // address=[0x15d3800]
    static int __cdecl NumberOfEnemies(int a1);

    // address=[0x15db1f0]
    static int __cdecl NumberOfPlayers(void);

    // address=[0x160dac0]
    static int __cdecl NumberOfAlliances(void);

private:
    // address=[0x415c3b4]
    static int m_iInitialized;

    // address=[0x415c3b8]
    static int m_iLocked;

    // address=[0x415c3c0]
    static struct SAlliancesData CAlliances::m_sData;

};


#endif // CALLIANCES_H
