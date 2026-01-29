#ifndef CMAGICSPELLSIDEBARINFO_H
#define CMAGICSPELLSIDEBARINFO_H

#include "defines.h"
#include "CInfoExchange.h"

class CMagicSpellSideBarInfo : public CInfoExchange
{
public:
    // address=[0x14546e0]
    CMagicSpellSideBarInfo(void);

    // address=[0x1454c90]
    virtual unsigned int Size(void) const;

private:
    struct SpellInfo
    {
        DWORD m_uSpellId;
        DWORD m_uPossibleNumberOfCasts;
        DWORD m_uAvailableCastsPercent;
        DWORD m_uCost;
    };  

    // Type information members
public:
    SpellInfo m_aSpells[8];
};

#endif // CMAGICSPELLSIDEBARINFO_H
