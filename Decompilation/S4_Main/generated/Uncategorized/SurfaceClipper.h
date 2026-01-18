#ifndef SURFACECLIPPER_H
#define SURFACECLIPPER_H

#include "defines.h"

class SurfaceClipper {
public:
    // address=[0x2f5f370]
    struct IDirectDrawClipper *  GetClipper(void);

    // address=[0x2f8a460]
     SurfaceClipper(void);

    // address=[0x2f8a490]
     ~SurfaceClipper(void);

    // address=[0x2f8a4e0]
    long  InitClipper(struct IDirectDraw7 * a2);

    // address=[0x2f8a510]
    long  InitClipper(struct IDirectDraw * a2);

    // address=[0x2f8a540]
    void  ReleaseClipper(void);

    // address=[0x2f8a570]
    long  SetClipRect(struct tagRECT const & Src);

    // address=[0x2f8a620]
    long  SetClipWindow(struct HWND__ * a2);

};


#endif // SURFACECLIPPER_H
