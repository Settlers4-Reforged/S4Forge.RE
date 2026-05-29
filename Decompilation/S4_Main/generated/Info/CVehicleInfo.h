#ifndef CVEHICLEINFO_H
#define CVEHICLEINFO_H

#include "defines.h"

class CVehicleInfo : public CInfoExchange {
public:
    // address=[0x14549c0]
     CVehicleInfo(void);

    // address=[0x1454e70]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    BYTE[92] gap_0;

};


#endif // CVEHICLEINFO_H
