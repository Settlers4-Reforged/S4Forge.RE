#ifndef CSTATEVIDEO_H
#define CSTATEVIDEO_H

#include "defines.h"

class CStateVideo : public CGameState {
public:
    // address=[0x14cbb00]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14cbb80]
     CStateVideo(void *);

    // address=[0x14cbe60]
    virtual  ~CStateVideo(void);

    // address=[0x14cbec0]
    virtual bool  Perform(void);

    // address=[0x14cc060]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14cc150]
    bool  StartVideo(void * a2);

    // address=[0x14cc320]
    bool  EndVideo(void);

    // address=[0x14cc3b0]
    void  PauseVideo(void);

    // address=[0x14cc440]
    void  UnPauseVideo(void);

private:
    // address=[0x14cc4d0]
    void  AlignVideoSurface(void);

};


#endif // CSTATEVIDEO_H
