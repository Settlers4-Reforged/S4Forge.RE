#ifndef CBLITFX_H
#define CBLITFX_H

#include "defines.h"

#include <ddraw.h>

class CBlitFX {
  public:
    // address=[0x2f69900]
    _DDBLTFX *GetBlitStructPtr(void);

    // address=[0x2f86400]
    CBlitFX(void);

    // address=[0x2f86430]
    void SetFillColor(int _iRed, int _iGreen, int _iBlue, bool _bIs555);

    // address=[0x2f864e0]
    void SetFillColorAlpha(int _iRed, int _iGreen, int _iBlue, int _iAlpha);

    // Type information members
  public:
    _DDBLTFX m_sBlitFX;
};

#endif // CBLITFX_H
