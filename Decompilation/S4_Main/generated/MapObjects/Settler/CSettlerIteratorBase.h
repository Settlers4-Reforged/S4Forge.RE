#ifndef CSETTLERITERATORBASE_H
#define CSETTLERITERATORBASE_H

#include "defines.h"

class CSettlerIteratorBase {
public:
    // address=[0x1317460]
    int  SettlerId(void)const;

    // address=[0x1317480]
    int  SettlerType(void)const;

protected:
    // address=[0x13173d0]
    void  Init(int a2);

    // address=[0x13174a0]
    bool  SettlerValid(int a2);

};


#endif // CSETTLERITERATORBASE_H
