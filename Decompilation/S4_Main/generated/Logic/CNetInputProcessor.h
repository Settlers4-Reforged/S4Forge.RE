#ifndef CNETINPUTPROCESSOR_H
#define CNETINPUTPROCESSOR_H

#include "defines.h"

class CNetInputProcessor : public INetInputProcessor {
public:
    // address=[0x1471110]
    virtual void  Process(class CEvn_Logic & a2);

    // address=[0x1472fd0]
     CNetInputProcessor(void);

protected:
    // address=[0x1470e70]
    static char * __cdecl DbgMsgName(int a1);

    // address=[0x1470ec0]
    static class CSettler * __cdecl GetReadySettlerPtr(int a1);

    // address=[0x1470f00]
    static class CSettler * __cdecl GetReadySettlerPtrOfType(int a1, int a2);

    // address=[0x1470f50]
    static class CBuilding * __cdecl GetAliveBuildingPtr(int a1);

    // address=[0x1470f90]
    static class CBuilding * __cdecl GetAliveBuildingPtrOfPlayer(int a1, int a2);

    // address=[0x1470fe0]
    static class CVehicle * __cdecl GetReadyVehiclePtr(int a1);

    // address=[0x1471020]
    static class CCart * __cdecl GetReadyCartPtr(int a1);

    // address=[0x1471070]
    static class CEcoSector * __cdecl GetEcoSectorPtrOfPlayer(int a1, int a2);

    // address=[0x14710b0]
    static class CEcoSector * __cdecl GetBuildingEcoSectorPtr(class CBuilding * a1);

    // address=[0x1473020]
    static bool __cdecl IsReadyEntityOfPlayer(int a1, int a2);

    // address=[0x1473190]
    static unsigned int __cdecl UnpackHiValue(unsigned int a1);

    // address=[0x14731a0]
    static unsigned int __cdecl UnpackLoValue(unsigned int a1);

    // address=[0x14731b0]
    static int __cdecl UnpackSignedLoValue(unsigned int a1);

};


#endif // CNETINPUTPROCESSOR_H
