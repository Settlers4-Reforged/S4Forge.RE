#ifndef CSHIPLIST_H
#define CSHIPLIST_H

#include "defines.h"

class CShipList {
public:
    // address=[0x15fd5b0]
    void  PushNeighborShips(int a2);

    // address=[0x15fd6e0]
    int  Nearest(int a2);

    // address=[0x15fe630]
     CShipList(int a2);

    // address=[0x15fe6a0]
    int  NumberOfShips(void)const;

    // address=[0x15fe6c0]
    void  PushShip(int a2);

    // address=[0x15fe700]
    void  PushSquareVW(int a2, int a3, int a4);

    // address=[0x15fe7c0]
    class CShipInfo const &  ShipInfo(int a2)const;

};


#endif // CSHIPLIST_H
