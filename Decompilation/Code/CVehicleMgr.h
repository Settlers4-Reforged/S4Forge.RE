#ifndef CVEHICLEMGR_H
#define CVEHICLEMGR_H

class CVehicleMgr {
public:
    // address=[0x130e530]
    class CVehicle &  operator[](int);

    // address=[0x130ec90]
    int  GetFirstVehicleId(int,int);

    // address=[0x130ed60]
    int  GetNumberOfVehicles(int,int,int);

    // address=[0x130eef0]
    static class CVehicle * __cdecl GetVehiclePtr(int);

    // address=[0x153a3f0]
    void *  Alloc(unsigned int);

    // address=[0x153a440]
    void  Dealloc(void *);

    // address=[0x15a8b20]
     CVehicleMgr(void);

    // address=[0x15a8c60]
     ~CVehicleMgr(void);

    // address=[0x15a8c80]
    void  Clear(void);

    // address=[0x15a8cd0]
    int  AddVehicle(int,int,int,int,int,bool);

    // address=[0x15a8e50]
    int  AddFoundationCart(int,int,int,int);

    // address=[0x15a8e90]
    void  DeleteVehicle(int);

    // address=[0x15a8fa0]
    bool  IsPositionFreeForVehicle(int,int,int);

    // address=[0x15a9100]
    int  GetNearestVehicle(int,int,int,int);

    // address=[0x15a9230]
    static class CFerryShip * __cdecl GetFerryShipAt(int,int);

    // address=[0x15a9330]
    static void __cdecl FillVehicleGroupMenu(class CInfoExchange *,bool,bool);

    // address=[0x15a9580]
    void  Store(class S4::CMapFile &);

    // address=[0x15a97e0]
    void  Load(class S4::CMapFile &);

    // address=[0x15a9b60]
    void  LoadInfo(void);

private:
    // address=[0x15a9b80]
    static int __cdecl Create(int,int,int,int,int,bool);

    // address=[0x15aa1b0]
    void  AttachVehicle(int,int,int);

    // address=[0x15aa2a0]
    void  DetachVehicle(int,int,int);

    // address=[0x15aa3f0]
    void  CheckOutVehicle(int);

};


#endif // CVEHICLEMGR_H
