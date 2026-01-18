#ifndef CSCANNER_H
#define CSCANNER_H

#include "defines.h"

class CScanner {
public:
    // address=[0x1301390]
    static bool __cdecl FindNearestEnemyTowerInSector(struct SFindNearestResult & a1, int a2, int a3, int a4, int a5);

    // address=[0x13065f0]
    static int __cdecl FindNearestOwnTowerInSector(int a1, int a2, int a3, int a4);

    // address=[0x15df090]
    static bool __cdecl CheckIfAEnemyUnitMayBeInRange(int a1, int a2, int a3, int a4);

    // address=[0x15df200]
    static int __cdecl CountCiviliansAndFindNearestInSector(int a1, int a2, int a3, int a4, int * a5);

    // address=[0x15df4f0]
    static void __cdecl CountFighters(struct SCountFightersResult & a1, int a2, int a3, int a4, int a5);

    // address=[0x15df900]
    static void __cdecl EvaluateFighters(struct SEvalFightersResult & a1, int a2, int a3, int a4, int a5);

    // address=[0x15dfdc0]
    static void __cdecl EvaluateTowers(struct SEvalTowersResult & a1, int a2, int a3, int a4, int a5);

    // address=[0x15e0530]
    static bool __cdecl FindNearestTowerInSector(struct SFindNearestResult & a1, int a2, int a3, int a4, int a5);

    // address=[0x15e08a0]
    static int __cdecl FindNearestFighter(int a1, int a2, int a3, int a4, int a5);

    // address=[0x15e0af0]
    static int __cdecl FindNearestAnimal(int a1, int a2, int a3, bool a4, int a5);

    // address=[0x15e0d40]
    static int __cdecl FindNearestEnemyBowman(int a1, int a2, int a3, int a4);

    // address=[0x15e0d70]
    static int __cdecl FindNearestEnemySwordsman(int a1, int a2, int a3, int a4);

    // address=[0x15e0da0]
    static int __cdecl FindNearestEnemyFighter(int a1, int a2, int a3, int a4);

    // address=[0x15e0dd0]
    static int __cdecl FindNearestOwnFighter(int a1, int a2, int a3, int a4);

    // address=[0x15e0e00]
    static int __cdecl FindNearestAllyFighter(int a1, int a2, int a3, int a4);

    // address=[0x15e0e30]
    static int __cdecl CountSettlers(int a1, int a2, int a3, int const * a4, int const * a5, int a6, int a7);

    // address=[0x15e1070]
    static int __cdecl IsNearMyLand(int a1, int a2, int a3);

    // address=[0x15e13a0]
    static bool __cdecl FindNearestPlayerLand(int a1, int & a2, int & a3);

    // address=[0x15e1460]
    static bool __cdecl FindAnyEnemyFighter(int a1, int a2, int a3, int a4, int a5);

    // address=[0x15e1710]
    static bool __cdecl FindAnySettlerOrVehicle(int a1, int a2, int a3, int a4);

    // address=[0x15e19d0]
    static bool __cdecl IsAreaCompletelyOwned(int a1, int a2, int a3, int a4);

    // address=[0x15e1b40]
    static bool __cdecl IsAreaCompletelyGreen(int a1, int a2, int a3);

    // address=[0x15e1c30]
    static bool __cdecl IsAreaCompletelyDarkLand(int a1, int a2, int a3);

};


#endif // CSCANNER_H
