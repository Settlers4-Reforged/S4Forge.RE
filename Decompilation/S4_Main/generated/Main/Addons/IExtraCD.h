#ifndef IEXTRACD_H
#define IEXTRACD_H

#include "defines.h"

class IExtraCD {
public:
    // address=[0x1481500]
    static class IExtraCD * __cdecl CreateMissionCDObject(void);

    // address=[0x1481580]
    static class IExtraCD * __cdecl CreateAddOnCDObject(void);

    // address=[0x1481600]
    static class IExtraCD * __cdecl CreateMissionCD2Object(void);

    // address=[0x1481680]
    static class IExtraCD * __cdecl CreateMissionCD3Object(void);

    // address=[0x1481fb0]
     IExtraCD(void);

    // address=[0x1482050]
    virtual  ~IExtraCD(void);

};


#endif // IEXTRACD_H
