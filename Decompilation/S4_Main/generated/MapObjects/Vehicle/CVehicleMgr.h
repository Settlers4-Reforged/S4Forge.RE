#ifndef CVEHICLEMGR_H
#define CVEHICLEMGR_H

#include "defines.h"

class CVehicleMgr {
public:
    // address=[0x130e530]
    class CVehicle &  operator[](int a1);

    // address=[0x130ec90]
    int  GetFirstVehicleId(int a2, int a3);

    // address=[0x130ed60]
    int  GetNumberOfVehicles(int a2, int a3, int a4);

    // address=[0x130eef0]
    static class CVehicle * __cdecl GetVehiclePtr(int a1);

    // address=[0x153a3f0]
    void *  Alloc(unsigned int a2);

    // address=[0x153a440]
    void  Dealloc(void * a2);

    // address=[0x15a8b20]
     CVehicleMgr(void);

    // address=[0x15a8c60]
     ~CVehicleMgr(void);

    // address=[0x15a8c80]
    void  Clear(void);

    // address=[0x15a8cd0]
    int  AddVehicle(int a2, int a3, int a4, int a5, int a6, bool a7);

    // address=[0x15a8e50]
    int  AddFoundationCart(int a2, int a3, int a4, int a5);

    // address=[0x15a8e90]
    void  DeleteVehicle(int a2);

    // address=[0x15a8fa0]
    bool  IsPositionFreeForVehicle(int a2, int a3, int a4);

    // address=[0x15a9100]
    int  GetNearestVehicle(int a2, int a3, int a4, int a5);

    // address=[0x15a9230]
    static class CFerryShip * __cdecl GetFerryShipAt(int a1, int a2);

    // address=[0x15a9330]
    static void __cdecl FillVehicleGroupMenu(class CInfoExchange * a1, bool a2, bool a3);

    // address=[0x15a9580]
    void  Store(class S4::CMapFile &);

    // address=[0x15a97e0]
    void  Load(class S4::CMapFile &);

    // address=[0x15a9b60]
    void  LoadInfo(void);

private:
    // address=[0x15a9b80]
    static int __cdecl Create(int a1, int a2, int a3, int a4, int a5, bool a6);

    // address=[0x15aa1b0]
    void  AttachVehicle(int a2, int a3, int a4);

    // address=[0x15aa2a0]
    void  DetachVehicle(int a2, int a3, int a4);

    // address=[0x15aa3f0]
    void  CheckOutVehicle(int a2);

};


#endif // CVEHICLEMGR_H
