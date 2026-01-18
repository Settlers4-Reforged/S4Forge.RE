#ifndef CPARAM_H
#define CPARAM_H

#include "defines.h"

class CParam : public CDynListEntry {
public:
    // address=[0x2f3e8a0]
     CParam(void);

    // address=[0x2f3e8f0]
     CParam(int a2, int a3, int a4, int a5);

    // address=[0x2f3e940]
     CParam(class CParam *);

    // address=[0x2f3e9a0]
    virtual  ~CParam(void);

    // address=[0x2f3e9c0]
    void  SetParameter(int a2, int a3, int a4, int a5);

    // address=[0x2f3ea00]
    void  SetParameterX(int a2, int a3);

    // address=[0x2f3ea70]
    int  ParamAreEqual(class CParam * a2);

};


#endif // CPARAM_H
