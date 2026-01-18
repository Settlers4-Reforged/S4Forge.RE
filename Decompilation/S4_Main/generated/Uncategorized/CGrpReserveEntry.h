#ifndef CGRPRESERVEENTRY_H
#define CGRPRESERVEENTRY_H

#include "defines.h"

class CGrpReserveEntry : public CReserveEntry {
public:
    // address=[0x2f41730]
     CGrpReserveEntry(enum BUILDING_TYPES a2, int a3, int a4, int a5);

    // address=[0x2f417f0]
    virtual  ~CGrpReserveEntry(void);

};


#endif // CGRPRESERVEENTRY_H
