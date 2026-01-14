#ifndef CSCANNER_H
#define CSCANNER_H

class CScanner {
public:
    // address=[0x1301390]
    static bool __cdecl FindNearestEnemyTowerInSector(struct SFindNearestResult &,int,int,int,int);

    // address=[0x13065f0]
    static int __cdecl FindNearestOwnTowerInSector(int,int,int,int);

    // address=[0x15df090]
    static bool __cdecl CheckIfAEnemyUnitMayBeInRange(int,int,int,int);

    // address=[0x15df200]
    static int __cdecl CountCiviliansAndFindNearestInSector(int,int,int,int,int *);

    // address=[0x15df4f0]
    static void __cdecl CountFighters(struct SCountFightersResult &,int,int,int,int);

    // address=[0x15df900]
    static void __cdecl EvaluateFighters(struct SEvalFightersResult &,int,int,int,int);

    // address=[0x15dfdc0]
    static void __cdecl EvaluateTowers(struct SEvalTowersResult &,int,int,int,int);

    // address=[0x15e0530]
    static bool __cdecl FindNearestTowerInSector(struct SFindNearestResult &,int,int,int,int);

    // address=[0x15e08a0]
    static int __cdecl FindNearestFighter(int,int,int,int,int);

    // address=[0x15e0af0]
    static int __cdecl FindNearestAnimal(int,int,int,bool,int);

    // address=[0x15e0d40]
    static int __cdecl FindNearestEnemyBowman(int,int,int,int);

    // address=[0x15e0d70]
    static int __cdecl FindNearestEnemySwordsman(int,int,int,int);

    // address=[0x15e0da0]
    static int __cdecl FindNearestEnemyFighter(int,int,int,int);

    // address=[0x15e0dd0]
    static int __cdecl FindNearestOwnFighter(int,int,int,int);

    // address=[0x15e0e00]
    static int __cdecl FindNearestAllyFighter(int,int,int,int);

    // address=[0x15e0e30]
    static int __cdecl CountSettlers(int,int,int,int const *,int const *,int,int);

    // address=[0x15e1070]
    static int __cdecl IsNearMyLand(int,int,int);

    // address=[0x15e13a0]
    static bool __cdecl FindNearestPlayerLand(int,int &,int &);

    // address=[0x15e1460]
    static bool __cdecl FindAnyEnemyFighter(int,int,int,int,int);

    // address=[0x15e1710]
    static bool __cdecl FindAnySettlerOrVehicle(int,int,int,int);

    // address=[0x15e19d0]
    static bool __cdecl IsAreaCompletelyOwned(int,int,int,int);

    // address=[0x15e1b40]
    static bool __cdecl IsAreaCompletelyGreen(int,int,int);

    // address=[0x15e1c30]
    static bool __cdecl IsAreaCompletelyDarkLand(int,int,int);

};


#endif // CSCANNER_H
