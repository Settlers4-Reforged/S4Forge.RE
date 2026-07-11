#include "CSettlerProductionInfo.h"

// Definitions for class CSettlerProductionInfo

// address=[0x1454830]
// Decompiled from CSettlerProductionInfo *__thiscall CSettlerProductionInfo::CSettlerProductionInfo(CSettlerProductionInfo *this)
CSettlerProductionInfo::CSettlerProductionInfo(void) : CInfoExchange() {}

// address=[0x1454d70]
// Decompiled from int __thiscall CSettlerProductionInfo::Size(CSettlerProductionInfo *this)
unsigned int CSettlerProductionInfo::Size(void) const {
    return sizeof(CSettlerProductionInfo);
    static_assert(sizeof(CSettlerProductionInfo) == 160, "Size of CSettlerProductionInfo is not correct.");
}
