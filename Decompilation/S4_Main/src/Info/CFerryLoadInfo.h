#ifndef CFERRYLOADINFO_H
#define CFERRYLOADINFO_H

#include "defines.h"
#include "CInfoExchange.h"

class CFerryLoadInfo : public CInfoExchange
{
public:
    // address=[0x14545c0]
    CFerryLoadInfo(void);

    // address=[0x1454bd0]
    virtual unsigned int Size(void) const;

    // Type information members
public:
    DWORD m_uCargpCount3[5];
    DWORD m_uCargpCount2[5];
    DWORD m_uCargpCount1[2];
};

#endif // CFERRYLOADINFO_H
