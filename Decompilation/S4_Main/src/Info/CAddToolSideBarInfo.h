#ifndef CADDTOOLSIDEBARINFO_H
#define CADDTOOLSIDEBARINFO_H

#include "defines.h"

#include "../Logic/CInfoExchange.h"

class CAddToolSideBarInfo : public CInfoExchange
{
public:
    // address=[0x1454410]
    CAddToolSideBarInfo(void);

    // address=[0x1454ad0]
    virtual unsigned int Size(void) const;

    // Type information members
public:
    unsigned char m_cAxeCount;
    unsigned char m_cHammerCount;
    unsigned char m_cPickaxeCount;
    unsigned char m_cRodCount;
    unsigned char m_cScytheCount;
    unsigned char m_cShovelCount;
    unsigned char m_cSawCount;
    unsigned char m_cUnknownF;
};

#endif // CADDTOOLSIDEBARINFO_H
