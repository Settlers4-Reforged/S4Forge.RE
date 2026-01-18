#ifndef CSTATEMDRANDOMMAPPARAMETERS_H
#define CSTATEMDRANDOMMAPPARAMETERS_H

#include "defines.h"

class CStateMDRandomMapParameters : public CGuiGameState {
public:
    // address=[0x14c80e0]
    static class CGameState * __cdecl DynamicCreateFunc(void * a1);

    // address=[0x14c8180]
     CStateMDRandomMapParameters(void * a2);

    // address=[0x14c85d0]
    virtual  ~CStateMDRandomMapParameters(void);

    // address=[0x14c8630]
    virtual bool  Perform(void);

    // address=[0x14c86d0]
    virtual bool  OnEvent(class CEvn_Event & a2);

    // address=[0x14c96a0]
    static void __cdecl DrawMap(unsigned short * a1, unsigned short * a2, unsigned int a3, int a4, int a5);

    // address=[0x14c9c20]
    void  PaintMap(void);

private:
    // address=[0x14c8160]
    void  SetupGUI(void);

};


#endif // CSTATEMDRANDOMMAPPARAMETERS_H
