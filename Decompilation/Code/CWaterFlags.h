#ifndef CWATERFLAGS_H
#define CWATERFLAGS_H

class CWaterFlags {
public:
    // address=[0x1351d70]
    static int __cdecl WaterFlags(int);

    // address=[0x14dff20]
    static bool __cdecl IsBlockedWater(int);

    // address=[0x14dfff0]
    static bool __cdecl IsWater(int);

    // address=[0x14e0080]
    static int __cdecl WaterFlagsGetDistanceToNearestShip(int);

    // address=[0x14eb310]
    static void __cdecl ClearWaterFlagBitRepelling(int);

    // address=[0x14fdea0]
    static bool __cdecl WaterFlagsIsFreeWater(int);

    // address=[0x15067a0]
    static void __cdecl SetWaterFlagBitRepelling(int);

    // address=[0x15f48a0]
    static bool __cdecl IsFreeWater(int);

    // address=[0x15fe810]
    static bool __cdecl WaterFlagsValid(int);

protected:
    // address=[0x15f42f0]
    static void __cdecl ClearWaterFlagBits(int,int);

    // address=[0x15f58d0]
    static void __cdecl SetWaterFlagBits(int,int);

    // address=[0x15fcd50]
    static void __cdecl Init(unsigned short *);

    // address=[0x15fcdc0]
    static void __cdecl Done(void);

    // address=[0x15fcde0]
    static void __cdecl PlaceShip(int);

    // address=[0x15fcfc0]
    static void __cdecl RemoveShip(int);

    // address=[0x15fe7a0]
    static void __cdecl SetWaterFlags(int,int);

    // address=[0x4617aa4]
    static int m_iInitialized;

    // address=[0x4617aa8]
    static unsigned short * m_pWaterFlagsLayer;

};


#endif // CWATERFLAGS_H
