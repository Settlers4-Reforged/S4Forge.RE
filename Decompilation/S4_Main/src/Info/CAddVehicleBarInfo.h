#ifndef CADDVEHICLEBARINFO_H
#define CADDVEHICLEBARINFO_H

#include "defines.h"

#include "../Logic/CInfoExchange.h"

class CAddVehicleBarInfo : public CInfoExchange
{
public:
    // address=[0x1454440]
    CAddVehicleBarInfo(void);

    // address=[0x1454af0]
    virtual unsigned int Size(void) const;

private:
    struct VehicleInfo
    {
        unsigned char vehicleType;
        unsigned char m_cVehicleAmountBar;
        unsigned char m_cVehicleProperties1;
        unsigned char m_cVehicleProperties2;
    };

    // Type information members
public:
    VehicleInfo m_aVehicleInfos[3];
};

#endif // CADDVEHICLEBARINFO_H
