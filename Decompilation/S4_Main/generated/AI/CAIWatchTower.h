#ifndef CAIWATCHTOWER_H
#define CAIWATCHTOWER_H

#include "defines.h"

class CAIWatchTower {
public:
    // address=[0x132eec0]
    void  Init(int a2, int a3, int a4);

    // address=[0x132ef30]
    void  Done(void);

    // address=[0x132f820]
    int  AllianceId(void)const;

    // address=[0x132f8a0]
    int  PackedXY(void)const;

    // address=[0x132f940]
    bool  Used(void)const;

    // address=[0x132f9f0]
    int  Value(void)const;

protected:
    // address=[0x132ef50]
    void  SetValue(int a2);

private:
    // address=[0x132f8c0]
    void  SetAllianceIdAndClearValue(int a2);

};


#endif // CAIWATCHTOWER_H
