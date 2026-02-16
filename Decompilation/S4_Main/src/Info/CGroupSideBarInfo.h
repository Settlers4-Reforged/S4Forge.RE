#ifndef CGROUPSIDEBARINFO_H
#define CGROUPSIDEBARINFO_H

#include "defines.h"
#include "Logic/CInfoExchange.h"

class CGroupSideBarInfo : public CInfoExchange
{
public:
    // address=[0x1454650]
    CGroupSideBarInfo(void);

    // address=[0x1454c30]
    virtual unsigned int Size(void) const;

    // Type information members
public:
    DWORD m_aGroupLevel[9];
};

#endif // CGROUPSIDEBARINFO_H
