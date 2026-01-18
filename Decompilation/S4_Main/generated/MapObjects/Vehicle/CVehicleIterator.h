#ifndef CVEHICLEITERATOR_H
#define CVEHICLEITERATOR_H

#include "defines.h"

class CVehicleIterator {
public:
    // address=[0x15aa510]
    class CVehicle *  FirstVehicle(void);

    // address=[0x15aad90]
    class CVehicle *  NextVehicle(void);

    // address=[0x160d920]
     CVehicleIterator(int a2, int a3);

protected:
    // address=[0x15aad50]
    static bool __cdecl IsEntityNullOrValid(class IEntity *);

    // address=[0x15aade0]
    class CVehicle *  NextVehicleEx(class CVehicle * a2);

};


#endif // CVEHICLEITERATOR_H
