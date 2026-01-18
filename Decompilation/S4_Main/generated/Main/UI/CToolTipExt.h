#ifndef CTOOLTIPEXT_H
#define CTOOLTIPEXT_H

#include "defines.h"

class CToolTipExt {
public:
    // address=[0x2f9fe20]
    void  ResetActiveText(void);

    // address=[0x2fa35e0]
     CToolTipExt(void);

    // address=[0x2fa3640]
    bool  OpenTooltip(void);

    // address=[0x2fa3a70]
    bool  UpdateText(void);

    // address=[0x2fa4000]
     ~CToolTipExt(void);

};


#endif // CTOOLTIPEXT_H
