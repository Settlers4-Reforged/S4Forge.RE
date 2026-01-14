#ifndef CANIMALEFFECT_H
#define CANIMALEFFECT_H

class CAnimalEffect {
public:
    // address=[0x14d9390]
     CAnimalEffect(void);

    // address=[0x14d9480]
     ~CAnimalEffect(void);

    // address=[0x14d94c0]
    void  Update(unsigned int,unsigned int,unsigned int,unsigned int);

    // address=[0x14d97b0]
    void  SetCurrentAmoutButterflies(int);

    // address=[0x14d97d0]
    void  SetMaxAmountButterflies(int);

    // address=[0x14d97f0]
    int  AddButterfly(int,int);

    // address=[0x14d9880]
    void  SetCurrentAmoutBirds(int);

    // address=[0x14d98a0]
    void  SetMaxAmountBirds(int);

    // address=[0x14d98c0]
    int  AddBird(int,int);

    // address=[0x14d9930]
    void  SetCurrentAmoutSeagulls(int);

    // address=[0x14d9950]
    void  SetMaxAmountSeagulls(int);

    // address=[0x14d9970]
    int  AddSeagull(int,int);

    // address=[0x14d99e0]
    void  SetCurrentAmoutDucks(int);

    // address=[0x14d9a00]
    void  SetMaxAmountDucks(int);

    // address=[0x14d9a20]
    int  AddDuck(int,int);

private:
    // address=[0x14d9a90]
    bool  UpdateButterfly(int,int,int,int,int);

    // address=[0x14d9ea0]
    bool  UpdateBird(int,int,int,int);

    // address=[0x14da2a0]
    bool  UpdateSeagull(int,int,int,int);

    // address=[0x14da790]
    bool  UpdateDuck(int,int,int,int);

};


#endif // CANIMALEFFECT_H
