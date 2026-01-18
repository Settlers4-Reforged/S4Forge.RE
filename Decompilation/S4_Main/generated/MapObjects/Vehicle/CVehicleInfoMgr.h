#ifndef CVEHICLEINFOMGR_H
#define CVEHICLEINFOMGR_H

#include "defines.h"

class CVehicleInfoMgr : public IVehicleInfoMgr {
public:
    // address=[0x15aae80]
    virtual void  InitializeVehicleProperties(bool a2, bool a3);

    // address=[0x15ac350]
     CVehicleInfoMgr(void);

protected:
    // address=[0x15aafc0]
    void  ReadXMLFile(void);

};


#endif // CVEHICLEINFOMGR_H
