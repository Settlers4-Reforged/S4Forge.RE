#ifndef CWATER_H
#define CWATER_H

#include "defines.h"

class CWater {
public:
    // address=[0x15fc7f0]
     CWater(void);

    // address=[0x15fc860]
     ~CWater(void);

    // address=[0x15fc8d0]
    static void __cdecl Init(unsigned short * a1);

    // address=[0x15fc900]
    static void __cdecl Done(void);

    // address=[0x15fc930]
    static bool __cdecl PlaceShip(int a1);

    // address=[0x15fc9b0]
    static bool __cdecl IsPlaceShipOk(int a1);

    // address=[0x15fca50]
    static bool __cdecl RemoveShip(int a1);

    // address=[0x15fca80]
    static bool __cdecl MoveShip(int a1, int a2);

    // address=[0x15fcbf0]
    static bool __cdecl PlacePseudoShip(int a1);

    // address=[0x15fcca0]
    static bool __cdecl RemovePseudoShip(int a1);

private:
    // address=[0x4617a9c]
    static int m_iInstanceCounter;

    // address=[0x4617aa0]
    static int m_iInitialized;

};


#endif // CWATER_H
