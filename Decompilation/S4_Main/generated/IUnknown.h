#ifndef IUNKNOWN_H
#define IUNKNOWN_H

#include "defines.h"

class IUnknown {
public:
    // address=[0x2616650]
     IUnknown(void);

    // Type information members
public:
    struct IUnknownVtbl * lpVtbl;

};


#endif // IUNKNOWN_H
