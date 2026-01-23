#ifndef CADDVEHICLEBARINFO_H
#define CADDVEHICLEBARINFO_H

#include "defines.h"

class CAddVehicleBarInfo : public CInfoExchange {
public:
    // address=[0x1454440]
     CAddVehicleBarInfo(void);

    // address=[0x1454af0]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    CAddVehicleBarInfo::Info[3] m_aVehicleInfos;

};


#endif // CADDVEHICLEBARINFO_H
