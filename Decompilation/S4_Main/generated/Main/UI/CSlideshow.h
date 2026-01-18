#ifndef CSLIDESHOW_H
#define CSLIDESHOW_H

#include "defines.h"

class CSlideshow {
public:
    // address=[0x149ada0]
     CSlideshow(int a2);

    // address=[0x149aec0]
     ~CSlideshow(void);

    // address=[0x149af20]
    bool  Advance(void);

private:
    // address=[0x149af50]
    bool  ShowPicture(void);

    // address=[0x149b240]
    bool  HasDisplaySurface(void)const;

};


#endif // CSLIDESHOW_H
