#ifndef CBUILDINGINFOEX_H
#define CBUILDINGINFOEX_H

#include "defines.h"

#include "CBuildingInfo.h"

class CBuildingInfoEx : public CBuildingInfo {
public:
    // address=[0x14544d0]
     CBuildingInfoEx(void);

    // address=[0x1454b30]
    virtual unsigned int  Size(void)const;
};

extern CBuildingInfoEx g_cBuildingInfoEx;

#endif // CBUILDINGINFOEX_H
