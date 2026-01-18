#ifndef CTRANSPORTMGR_H
#define CTRANSPORTMGR_H

#include "defines.h"

class CTransportMgr {
public:
    // address=[0x147cd30]
    static class IMovingEntity * __cdecl GetNearestEntity(int a1, int a2, int a3, int a4, int a5);

    // address=[0x147d080]
    static class IMovingEntity * __cdecl GetNearestTransportEntity(int a1, int a2, int a3, int a4, int a5, int a6, bool a7);

    // address=[0x147d210]
    static class CSettler * __cdecl GetNearestCarrier(int a1, int a2, int a3);

    // address=[0x147d2a0]
    static class IMovingEntity * __cdecl GetVehicleCargoLoader(int a1, int a2, int a3, int a4, int a5, int a6, int & a7);

private:
    // address=[0x36bab38]
    static int const MIN_DONKEY_AMOUNT;

    // address=[0x36bab3c]
    static int const MIN_CART_AMOUNT;

};


#endif // CTRANSPORTMGR_H
