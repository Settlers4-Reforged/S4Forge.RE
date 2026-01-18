#ifndef CMSGSTACK_H
#define CMSGSTACK_H

#include "defines.h"

class CMsgStack : public ?$list@VCNet_Event@@V?$allocator@VCNet_Event@@@std@@@std {
public:
    // address=[0x15c49f0]
    bool  GetAI(void);

    // address=[0x15c9d30]
     CMsgStack(void);

    // address=[0x15c9d70]
    virtual  ~CMsgStack(void);

    // address=[0x15c9d90]
    void  Clear(void);

    // address=[0x15c9dc0]
    class CNet_Event  GetMsg(void a1);

    // address=[0x15c9e60]
    void  AddMsg(class CNet_Event & a2);

    // address=[0x15c9e90]
    bool  IsValid(void);

    // address=[0x15c9f00]
    void  SetExpectedSize(int a2);

    // address=[0x15c9f30]
    void  Sort(void);

    // address=[0x15c9f50]
    bool  IsInStack(unsigned char a2);

    // address=[0x15cadc0]
    bool  IsSizeAlreadySet(void);

    // address=[0x15cc590]
    void  ClearAndValidate(void);

    // address=[0x15cc5c0]
    int  GetExpectedSize(void);

    // address=[0x15cc5e0]
    void  Invalidate(void);

    // address=[0x15cc610]
    bool  IsEmpty(void);

    // address=[0x15cc650]
    void  SetAI(bool a2);

};


#endif // CMSGSTACK_H
