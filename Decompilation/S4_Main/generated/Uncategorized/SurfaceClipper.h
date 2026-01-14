#ifndef SURFACECLIPPER_H
#define SURFACECLIPPER_H

class SurfaceClipper {
public:
    // address=[0x2f5f370]
    struct IDirectDrawClipper *  GetClipper(void);

    // address=[0x2f8a460]
     SurfaceClipper(void);

    // address=[0x2f8a490]
     ~SurfaceClipper(void);

    // address=[0x2f8a4e0]
    long  InitClipper(struct IDirectDraw7 *);

    // address=[0x2f8a510]
    long  InitClipper(struct IDirectDraw *);

    // address=[0x2f8a540]
    void  ReleaseClipper(void);

    // address=[0x2f8a570]
    long  SetClipRect(struct tagRECT const &);

    // address=[0x2f8a620]
    long  SetClipWindow(struct HWND__ *);

};


#endif // SURFACECLIPPER_H
