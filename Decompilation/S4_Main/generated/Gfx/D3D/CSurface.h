#ifndef CSURFACE_H
#define CSURFACE_H

#include "defines.h"

class CSurface {
public:
    // address=[0x2f86560]
    static class CSurface * __cdecl CreateSurfacePtr(bool a1);

    // address=[0x2f8a2f0]
     CSurface(void);

    // address=[0x2f8a310]
    virtual  ~CSurface(void);

};


#endif // CSURFACE_H
