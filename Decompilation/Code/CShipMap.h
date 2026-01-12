#ifndef CSHIPMAP_H
#define CSHIPMAP_H

class CShipMap {
public:
    // address=[0x15fd4f0]
    static bool __cdecl InShipList(int);

    // address=[0x15fe7e0]
    static int (& __cdecl ShipListVW(int,int))[4];

protected:
    // address=[0x15fd1e0]
    static void __cdecl Init(void);

    // address=[0x15fd210]
    static void __cdecl Done(void);

    // address=[0x15fd220]
    static bool __cdecl PlaceShip(int);

    // address=[0x15fd280]
    static int * __cdecl GetEntryForPlaceShip(int);

    // address=[0x15fd420]
    static bool __cdecl RemoveShip(int);

private:
    // address=[0x4617aac]
    static int m_iInitialized;

    // address=[0x4617ab0]
    static int (* m_tShipLists)[64][4];

};


#endif // CSHIPMAP_H
