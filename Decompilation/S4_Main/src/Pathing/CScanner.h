#ifndef CSCANNER_H
#define CSCANNER_H

#include "defines.h"

struct SFindNearestResult {
    int m_iNearestFoundId;
    int m_iDistance;
};

struct SCountFightersResult {
    int m_uOwnedBowmen;
    int m_uOwnedSoldiers;
    int m_uAllyBowmen;
    int m_uAllySoldiers;
    int m_uEnemyBowmen;
    int m_uEnemySoldiers;
};

struct SEvalFightersResult {
    int m_iOwnUnits;
    int m_iAlliedUnits;
    int m_iEnemyUnits;
    int m_iOwnValue;
    int m_iAllyValue;
    int m_iEnemyValue;
};

struct SEvalTowersResult {
    int m_iEnemyTowerCount;
    int m_iEnemyStationedSwordmen;
    int m_iEnemyStationedBowmen;
    int m_iEnemyEvalScore;
};

class CScanner {
public:
    // address=[0x1301390]
    static bool __cdecl FindNearestEnemyTowerInSector(struct SFindNearestResult &a1, int a2, int a3, int a4, int _iPlayerId);

    // address=[0x13065f0]
    static int __cdecl FindNearestOwnTowerInSector(int a1, int a2, int a3, int _iPlayerId);

    // address=[0x15df090]
    static bool __cdecl CheckIfAEnemyUnitMayBeInRange(int _iX, int _iY, int _iRadius, int _iPlayerId);

    // address=[0x15df200]
    static int __cdecl CountCiviliansAndFindNearestInSector(int _iX, int _iY, int _iRadius, int a4, int *a5);

    // address=[0x15df4f0]
    static void __cdecl CountFighters(struct SCountFightersResult &a1, int _iX, int _iY, int _iRadius, int _iPlayerId);

    // address=[0x15df900]
    static void __cdecl EvaluateFighters(struct SEvalFightersResult &_rResults, int _iX, int _iY, int _iRadius, int _iPlayerId);

    // address=[0x15dfdc0]
    static void __cdecl EvaluateTowers(struct SEvalTowersResult &arg0, int _iX, int _iY, int _iRadius, int _iPlayerId);

    // address=[0x15e0530]
    static bool __cdecl FindNearestTowerInSector(struct SFindNearestResult &_rResult, int iX, int iY, int _iRadius, int a5);

    // address=[0x15e08a0]
    static int __cdecl FindNearestFighter(int _iX, int _iY, int _iRadius, int _iFighterSearchMask, int _iOwnerBitMask);

    // address=[0x15e0af0]
    static int __cdecl FindNearestAnimal(int _iX, int _iY, int _iRadius, bool a4, int a5);

    // address=[0x15e0d40]
    static int __cdecl FindNearestEnemyBowman(int _iY, int _iX, int _iRadius, int _iPlayerId);

    // address=[0x15e0d70]
    static int __cdecl FindNearestEnemySwordsman(int _iX, int _iY, int _iRadius, int _iPlayerId);

    // address=[0x15e0da0]
    static int __cdecl FindNearestEnemyFighter(int _iX, int _iY, int _iRadius, int _iPlayerId);

    // address=[0x15e0dd0]
    static int __cdecl FindNearestOwnFighter(int _iX, int _iY, int _iRadius, int _iPlayerId);

    // address=[0x15e0e00]
    static int __cdecl FindNearestAllyFighter(int a1, int a2, int a3, int a4);

    // address=[0x15e0e30]
    static int __cdecl CountSettlers(int _iX, int _iY, int _iRadius, int const *_pPlayerIds, int const *_pSettlerTypes, int _iSectorId, int _iLimit);

    // address=[0x15e1070]
    static int __cdecl IsNearMyLand(int _iPlayerId, int _iX, int _iY);

    // address=[0x15e13a0]
    static bool __cdecl FindNearestPlayerLand(int _iOwnerId, int &_rX, int &_rY);

    // address=[0x15e1460]
    static bool __cdecl FindAnyEnemyFighter(int _iX, int _iY, int _iRadius, int a4, int a5);

    // address=[0x15e1710]
    static bool __cdecl FindAnySettlerOrVehicle(int _iX, int _iY, int _iRadius, int _iPlayerId);

    // address=[0x15e19d0]
    static bool __cdecl IsAreaCompletelyOwned(int _iX, int _iY, int _iRadius, int _iPlayerId);

    // address=[0x15e1b40]
    static bool __cdecl IsAreaCompletelyGreen(int _iX, int _iY, int _iRadius);

    // address=[0x15e1c30]
    static bool __cdecl IsAreaCompletelyDarkLand(int _iX, int _iY, int _iRadius);
};


#endif // CSCANNER_H
