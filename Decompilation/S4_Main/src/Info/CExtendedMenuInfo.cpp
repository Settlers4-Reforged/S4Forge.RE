#include "CExtendedMenuInfo.h"

// Definitions for class CExtendedMenuInfo

CExtendedMenuInfo g_cExtendedMenuInfo{};

// address=[0x1454560]
// Decompiled from CExtendedMenuInfo *__thiscall CExtendedMenuInfo::CExtendedMenuInfo(CExtendedMenuInfo *this)
CExtendedMenuInfo::CExtendedMenuInfo(void) : CInfoExchange() {}

// address=[0x1454b90]
// Decompiled from int __thiscall CExtendedMenuInfo::Size(CExtendedMenuInfo *this)
unsigned int CExtendedMenuInfo::Size(void) const {
    return 0x34;
}
