#ifndef CVEHICLEITERATOR_H
#define CVEHICLEITERATOR_H

class CVehicleIterator {
public:
    // address=[0x15aa510]
    class CVehicle *  FirstVehicle(void);

    // address=[0x15aad90]
    class CVehicle *  NextVehicle(void);

    // address=[0x160d920]
     CVehicleIterator(int,int);

protected:
    // address=[0x15aad50]
    static bool __cdecl IsEntityNullOrValid(class IEntity *);

    // address=[0x15aade0]
    class CVehicle *  NextVehicleEx(class CVehicle *);

};


#endif // CVEHICLEITERATOR_H
