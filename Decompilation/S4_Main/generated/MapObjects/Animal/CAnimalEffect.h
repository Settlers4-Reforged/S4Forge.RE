#ifndef CANIMALEFFECT_H
#define CANIMALEFFECT_H

#include "defines.h"

class CAnimalEffect {
public:
    // address=[0x14d9390]
     CAnimalEffect(void);

    // address=[0x14d9480]
     ~CAnimalEffect(void);

    // address=[0x14d94c0]
    void  Update(unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5);

    // address=[0x14d97b0]
    void  SetCurrentAmoutButterflies(int a2);

    // address=[0x14d97d0]
    void  SetMaxAmountButterflies(int a2);

    // address=[0x14d97f0]
    int  AddButterfly(int a2, int a3);

    // address=[0x14d9880]
    void  SetCurrentAmoutBirds(int a2);

    // address=[0x14d98a0]
    void  SetMaxAmountBirds(int a2);

    // address=[0x14d98c0]
    int  AddBird(int a2, int a3);

    // address=[0x14d9930]
    void  SetCurrentAmoutSeagulls(int a2);

    // address=[0x14d9950]
    void  SetMaxAmountSeagulls(int a2);

    // address=[0x14d9970]
    int  AddSeagull(int a2, int a3);

    // address=[0x14d99e0]
    void  SetCurrentAmoutDucks(int a2);

    // address=[0x14d9a00]
    void  SetMaxAmountDucks(int a2);

    // address=[0x14d9a20]
    int  AddDuck(int a2, int a3);

private:
    // address=[0x14d9a90]
    bool  UpdateButterfly(int a2, int a3, int a4, int a5, int a5);

    // address=[0x14d9ea0]
    bool  UpdateBird(int a2, int a3, int a4, int a4);

    // address=[0x14da2a0]
    bool  UpdateSeagull(int a2, int a3, int a4, int a4);

    // address=[0x14da790]
    bool  UpdateDuck(int a2, int a3, int a4, int a5);

};


#endif // CANIMALEFFECT_H
