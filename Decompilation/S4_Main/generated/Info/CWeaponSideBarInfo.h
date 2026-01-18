#ifndef CWEAPONSIDEBARINFO_H
#define CWEAPONSIDEBARINFO_H

#include "defines.h"

class CWeaponSideBarInfo : public CInfoExchange {
public:
    // address=[0x1454a50]
     CWeaponSideBarInfo(void);

    // address=[0x1454ed0]
    virtual unsigned int  Size(void)const;

};


#endif // CWEAPONSIDEBARINFO_H
