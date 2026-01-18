#ifndef IVEHICLEINFOMGR_H
#define IVEHICLEINFOMGR_H

#include "defines.h"

class IVehicleInfoMgr {
public:
    // address=[0x152f270]
    static struct SVehicleProperties const * __cdecl VehicleProperties(unsigned int a1, unsigned int a2);

    // address=[0x15ac380]
     IVehicleInfoMgr(void);

protected:
    // address=[0x4158f28]
    static bool m_bInitialized;

    // address=[0x4158f30]
    static struct SVehicleProperties (* m_sVehicleProperties)[6];

};


#endif // IVEHICLEINFOMGR_H
