#ifndef IEVN_HANDLE_H
#define IEVN_HANDLE_H

#include "defines.h"

class IEvn_Handle {
public:
    // address=[0x139fe20]
     IEvn_Handle(void) = default;

     virtual bool __thiscall OnEvent(class CEvn_Event &) = 0;
};


#endif // IEVN_HANDLE_H
