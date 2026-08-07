#ifndef CFINDENEMYBUILDINGS_H
#define CFINDENEMYBUILDINGS_H

#include "defines.h"

class CFindEnemyBuildings {
public:
    // address=[0x15af9c0]
    int  BuildingId(void)const;

    // address=[0x15af9e0]
    class CBuilding *  BuildingPtr(void)const;

    // address=[0x15dee30]
     CFindEnemyBuildings(int _iX, int _iY, int _iMaxDistance, int _iOwner, bool _bOnlyTowers);

    // address=[0x15deec0]
    bool  NextBuilding(void);

    // Type information members
public:
    CVWList m_cVWList;
    _DWORD m_iCenterX;
    _DWORD m_iCenterY;
    _DWORD m_iMaxDistance;
    _DWORD m_iEnemyBits;
    _BYTE m_bOnlyTowers;
    _DWORD m_iVWIndex;
    _DWORD m_iBuildingId;
    IEntity * m_pBuilding;

};


#endif // CFINDENEMYBUILDINGS_H
