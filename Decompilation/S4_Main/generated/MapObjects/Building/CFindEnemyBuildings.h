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
     CFindEnemyBuildings(int a2, int a3, int a4, int a5, bool a6);

    // address=[0x15deec0]
    bool  NextBuilding(void);

};


#endif // CFINDENEMYBUILDINGS_H
