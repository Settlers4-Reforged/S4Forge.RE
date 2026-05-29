#ifndef IGFXEFFECTS_H
#define IGFXEFFECTS_H

#include "defines.h"

class IGfxEffects {
public:
    // address=[0x144f2d0]
    IGfxEffects(void);

    virtual void SetEffectsViewport(int a2, int a3, int a4, int a5, int a6) = 0;

    virtual struct SGfxObjectInfo *FirstEffect(int a2) = 0;

    virtual struct SGfxObjectInfo *NextEffect(void) = 0;
};


#endif // IGFXEFFECTS_H
