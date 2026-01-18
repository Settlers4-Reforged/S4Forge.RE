#ifndef IFUTUREEVENTS_H
#define IFUTUREEVENTS_H

#include "defines.h"

class IFutureEvents : public IS4ChunkObject {
public:
    // address=[0x144ff70]
    static class IFutureEvents * __cdecl CreateFutureEvents(void);

    // address=[0x14529b0]
     IFutureEvents(void);

    // address=[0x1470750]
    bool  AddFutureEvent16(enum T_FUTURE_EVENT a2, unsigned int a3, unsigned int a4, unsigned int a5, unsigned int a6, unsigned int a7, unsigned int a8);

};


#endif // IFUTUREEVENTS_H
