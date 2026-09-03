#ifndef CFINDENEMYBUILDINGS_H
#define CFINDENEMYBUILDINGS_H

#include "Pathing/CVWList.h"
#include "defines.h"

class CFindEnemyBuildings {
  public:
    // address=[0x15af9c0]
    int BuildingId(void) const;

    // address=[0x15af9e0]
    class CBuilding *BuildingPtr(void) const;

    // address=[0x15dee30]
    CFindEnemyBuildings(int _iX, int _iY, int _iMaxDistance, int _iOwner, bool _bOnlyTowers);

    // address=[0x15deec0]
    bool NextBuilding(void);

    // Type information members
  public:
    CVWList m_cVWList;
    int m_iCenterX;
    int m_iCenterY;
    int m_iMaxDistance;
    int m_iEnemyBits;
    bool m_bOnlyTowers;
    int m_iVWIndex;
    int m_iBuildingId;
    class CBuilding *m_pBuilding;
};

#endif // CFINDENEMYBUILDINGS_H
