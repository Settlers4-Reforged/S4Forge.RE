#ifndef IAIECOMANAGER_H
#define IAIECOMANAGER_H

#include "defines.h"

class IAIEcoManager {
public:
    // address=[0x133ae70]
    static class IAIEcoManager * __cdecl CreateEcoManager(int a1, class IAISectorAI * a2, class IAIEventQueue * a3);

    // address=[0x1345700]
     IAIEcoManager(void);

    // address=[0x1345e20]
    virtual  ~IAIEcoManager(void);

};


#endif // IAIECOMANAGER_H
