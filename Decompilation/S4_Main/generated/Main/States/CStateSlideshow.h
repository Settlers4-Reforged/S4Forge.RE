#ifndef CSTATESLIDESHOW_H
#define CSTATESLIDESHOW_H

#include "defines.h"

class CStateSlideshow : public CGameState {
public:
    // address=[0x14ca870]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14ca8f0]
     CStateSlideshow(void * a2);

    // address=[0x14ca9b0]
    virtual  ~CStateSlideshow(void);

    // address=[0x14caa60]
    virtual bool  Perform(void);

    // address=[0x14caba0]
    virtual bool  OnEvent(class CEvn_Event & a2);

};


#endif // CSTATESLIDESHOW_H
