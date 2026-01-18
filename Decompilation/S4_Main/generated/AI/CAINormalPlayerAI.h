#ifndef CAINORMALPLAYERAI_H
#define CAINORMALPLAYERAI_H

#include "defines.h"

class CAINormalPlayerAI : public CAIPlayerAI {
protected:
    // address=[0x131a540]
     CAINormalPlayerAI(int a2);

    // address=[0x131a580]
    virtual void  Load(class IS4Chunk & a2);

    // address=[0x131a670]
    virtual void  Save(class IS4Chunk & a2);

    // address=[0x131a730]
    virtual void  Init(void);

};


#endif // CAINORMALPLAYERAI_H
