#ifndef CSTATELOCALTYPE_H
#define CSTATELOCALTYPE_H

#include "defines.h"

class CStateLocalType : public CGuiGameState {
public:
    // address=[0x14c1100]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14c1180]
     CStateLocalType(void * a2);

    // address=[0x14c1200]
    virtual  ~CStateLocalType(void);

    // address=[0x14c1280]
    virtual bool  Perform(void);

    // address=[0x14c1320]
    virtual bool  OnEvent(class CEvn_Event & a2);

};


#endif // CSTATELOCALTYPE_H
