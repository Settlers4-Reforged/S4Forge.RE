#ifndef CMAGICSPELLSIDEBARINFO_H
#define CMAGICSPELLSIDEBARINFO_H

#include "defines.h"

class CMagicSpellSideBarInfo : public CInfoExchange {
public:
    // address=[0x14546e0]
     CMagicSpellSideBarInfo(void);

    // address=[0x1454c90]
    virtual unsigned int  Size(void)const;

    // Type information members
public:
    CMagicSpellSideBarInfo::SpellInfo[8] m_aSpells;

};


#endif // CMAGICSPELLSIDEBARINFO_H
