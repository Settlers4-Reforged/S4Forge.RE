#include "CSoldierInfo.h"

// Definitions for class CSoldierInfo

// address=[0x14548c0]
// Decompiled from CSoldierInfo *__thiscall CSoldierInfo::CSoldierInfo(CSoldierInfo *this)
CSoldierInfo::CSoldierInfo(void) : CInfoExchange() {}

// address=[0x1454dd0]
// Decompiled from int __thiscall CSoldierInfo::Size(CSoldierInfo *this)
unsigned int CSoldierInfo::Size(void) const {
    return sizeof(CSoldierInfo);
    static_assert(sizeof(CSoldierInfo) == 152, "sizeof(CSoldierInfo) != 152");
}
