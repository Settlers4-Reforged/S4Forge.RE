#include "CSpecialistsInfo.h"

// Definitions for class CSpecialistsInfo

// address=[0x14548f0]
// Decompiled from CSpecialistsInfo *__thiscall CSpecialistsInfo::CSpecialistsInfo(CSpecialistsInfo *this)
CSpecialistsInfo::CSpecialistsInfo(void) : CInfoExchange() {}

// address=[0x1454df0]
// Decompiled from int __thiscall CSpecialistsInfo::Size(CSpecialistsInfo *this)
unsigned int CSpecialistsInfo::Size(void) const {
    return sizeof(CSpecialistsInfo);
    static_assert(sizeof(CSpecialistsInfo) == 68, "sizeof(CSpecialistsInfo) != 68");
}
