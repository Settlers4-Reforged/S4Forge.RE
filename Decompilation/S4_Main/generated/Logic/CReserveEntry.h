#ifndef CRESERVEENTRY_H
#define CRESERVEENTRY_H

#include "defines.h"

class CReserveEntry : public CDynListEntry {
public:
    // address=[0x2f416b0]
     CReserveEntry(void);

    // address=[0x2f416d0]
     CReserveEntry(enum BUILDING_TYPES a2, int a3, int a4);

    // address=[0x2f41710]
    virtual  ~CReserveEntry(void);

};


#endif // CRESERVEENTRY_H
