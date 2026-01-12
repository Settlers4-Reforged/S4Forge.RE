#ifndef CTRANSPORTMGR_H
#define CTRANSPORTMGR_H

class CTransportMgr {
public:
    // address=[0x147cd30]
    static class IMovingEntity * __cdecl GetNearestEntity(int,int,int,int,int);

    // address=[0x147d080]
    static class IMovingEntity * __cdecl GetNearestTransportEntity(int,int,int,int,int,int,bool);

    // address=[0x147d210]
    static class CSettler * __cdecl GetNearestCarrier(int,int,int);

    // address=[0x147d2a0]
    static class IMovingEntity * __cdecl GetVehicleCargoLoader(int,int,int,int,int,int,int &);

private:
    // address=[0x36bab38]
    static int const MIN_DONKEY_AMOUNT;

    // address=[0x36bab3c]
    static int const MIN_CART_AMOUNT;

};


#endif // CTRANSPORTMGR_H
