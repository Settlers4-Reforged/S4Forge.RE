#ifndef IFUTUREEVENTS_H
#define IFUTUREEVENTS_H

class IFutureEvents : public IS4ChunkObject {
public:
    // address=[0x144ff70]
    static class IFutureEvents * __cdecl CreateFutureEvents(void);

    // address=[0x14529b0]
     IFutureEvents(void);

    // address=[0x1470750]
    bool  AddFutureEvent16(enum T_FUTURE_EVENT,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);

};


#endif // IFUTUREEVENTS_H
