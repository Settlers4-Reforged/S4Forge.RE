#ifndef CAIPLAYEREVALUATION_H
#define CAIPLAYEREVALUATION_H

#include "defines.h"

class CAIPlayerEvaluation {
public:
    // address=[0x1310d40]
    void  Clear(void);

    // address=[0x1310e30]
    void  EvaluatePlayer(int a2);

    // address=[0x1310ea0]
    void  DbgPrint(void);

protected:
    // address=[0x1310f40]
    void  EvaluateGoods(int a2);

    // address=[0x1311060]
    void  EvaluateWarriors(int _iPlayerId);

    // address=[0x1311400]
    void  EvaluateBuildings(int a2);

    // Type information members
public:
    _DWORD m_uAITick;
    _DWORD m_uSwordCount;
    _DWORD m_uBowCount;
    _DWORD m_uSpecialWeaponCount;
    _DWORD m_uTotalWeaponCount;
    _DWORD m_uGoldCount;
    _DWORD m_uOfferedSwordmen;
    _DWORD m_uOfferedBowmen;
    _DWORD m_uTotalSwordmen;
    _DWORD m_uTotalBowmen;
    _DWORD m_uSpecialistsCount;
    _DWORD m_uLeadersCount;
    _DWORD m_uPriestsCount;
    _DWORD m_uTotalUnitCount;
    _DWORD m_uTotalFighterCount;
    _DWORD m_uTotalUnitCountEx;
    _DWORD m_uTotalUnitValueEx;
    _DWORD m_uSmallTowerCount;
    _DWORD m_uBigTowerCount;
    _DWORD m_uCastleCount;
    _DWORD m_uTotalWarBuildingCount;
    _DWORD m_uTotalWarBuildingValue;

};


#endif // CAIPLAYEREVALUATION_H
