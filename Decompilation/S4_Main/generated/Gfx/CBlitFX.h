#ifndef CBLITFX_H
#define CBLITFX_H

#include "defines.h"

class CBlitFX {
public:
    // address=[0x2f69900]
    struct _DDBLTFX *  GetBlitStructPtr(void);

    // address=[0x2f86400]
     CBlitFX(void);

    // address=[0x2f86430]
    void  SetFillColor(int a2, int a3, int a4, bool a5);

    // address=[0x2f864e0]
    void  SetFillColorAlpha(int a2, int a3, int a4, int a5);

};


#endif // CBLITFX_H
