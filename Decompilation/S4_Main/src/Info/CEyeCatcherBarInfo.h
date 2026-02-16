#ifndef CEYECATCHERBARINFO_H
#define CEYECATCHERBARINFO_H

#include "defines.h"
#include "Logic/CInfoExchange.h"

class CEyeCatcherBarInfo : public CInfoExchange
{
public:
    // address=[0x1454590]
    CEyeCatcherBarInfo(void);

    // address=[0x1454bb0]
    virtual unsigned int Size(void) const;

private:
    struct EyeCatcher
    {
        DWORD m_uBuildingId;
        DWORD m_uCountBuilt;
        DWORD m_uCountTotal;
        BYTE m_cBuildingInfo1;
        BYTE m_cBuildingInfo2;
        BYTE m_cBuildingInfo3;
    };

    // Type information members
public:
    CEyeCatcherBarInfo::EyeCatcher m_sEyeCatcher[12];
};

#endif // CEYECATCHERBARINFO_H
