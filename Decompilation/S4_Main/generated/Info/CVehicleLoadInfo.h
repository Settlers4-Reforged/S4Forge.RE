#ifndef CVEHICLELOADINFO_H
#define CVEHICLELOADINFO_H

#include "defines.h"

class CVehicleLoadInfo : public CInfoExchange {
public:
    // address=[0x14549f0]
     CVehicleLoadInfo(void);

    // address=[0x1454e90]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    CVehicleLoadInfo::SSlot[2] m_vSlots;

};


#endif // CVEHICLELOADINFO_H
