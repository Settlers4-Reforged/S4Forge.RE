#ifndef CATTACKMSGFILTER_H
#define CATTACKMSGFILTER_H

class CAttackMsgFilter {
private:
    // address=[0x140a760]
    bool  IsInRadius(int,int);

    // address=[0x140a7b0]
    bool  Activate(int,int,int);

    // address=[0x140a9a0]
     CAttackMsgFilter(void);

    // address=[0x140a9f0]
     ~CAttackMsgFilter(void);

    // address=[0x140aa60]
    void  Deactivate(void);

    // address=[0x140aa80]
    bool  IsActive(void);

    // address=[0x140aaa0]
    bool  IsOld(int);

};


#endif // CATTACKMSGFILTER_H
