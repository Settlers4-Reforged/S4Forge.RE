#ifndef CSHIPLIST_H
#define CSHIPLIST_H

class CShipList {
public:
    // address=[0x15fd5b0]
    void  PushNeighborShips(int);

    // address=[0x15fd6e0]
    int  Nearest(int);

    // address=[0x15fe630]
     CShipList(int);

    // address=[0x15fe6a0]
    int  NumberOfShips(void)const;

    // address=[0x15fe6c0]
    void  PushShip(int);

    // address=[0x15fe700]
    void  PushSquareVW(int,int,int);

    // address=[0x15fe7c0]
    class CShipInfo const &  ShipInfo(int)const;

};


#endif // CSHIPLIST_H
