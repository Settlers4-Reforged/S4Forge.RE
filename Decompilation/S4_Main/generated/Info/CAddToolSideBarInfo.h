#ifndef CADDTOOLSIDEBARINFO_H
#define CADDTOOLSIDEBARINFO_H

#include "defines.h"

class CAddToolSideBarInfo : public CInfoExchange {
public:
    // address=[0x1454410]
     CAddToolSideBarInfo(void);

    // address=[0x1454ad0]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    BYTE m_cAxeCount;
    BYTE m_cHammerCount;
    BYTE m_cPickaxeCount;
    BYTE m_cRodCount;
    BYTE m_cScytheCount;
    BYTE m_cShovelCount;
    BYTE m_cSawCount;
    BYTE m_cUnknownF;

};


#endif // CADDTOOLSIDEBARINFO_H
