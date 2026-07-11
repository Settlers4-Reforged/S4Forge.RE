#include "CSettlerStatisticInfo.h"

// Definitions for class CSettlerStatisticInfo

// address=[0x1454860]
// Decompiled from CSettlerStatisticInfo *__thiscall CSettlerStatisticInfo::CSettlerStatisticInfo(CSettlerStatisticInfo *this)
CSettlerStatisticInfo::CSettlerStatisticInfo(void) : CInfoExchange() {}

// address=[0x1454d90]
// Decompiled from int __thiscall CSettlerStatisticInfo::Size(CSettlerStatisticInfo *this)
unsigned int CSettlerStatisticInfo::Size(void) const {
    return sizeof(CSettlerStatisticInfo);
    static_assert(sizeof(CSettlerStatisticInfo) == 328, "sizeof(CSettlerStatisticInfo) != 328");
}
