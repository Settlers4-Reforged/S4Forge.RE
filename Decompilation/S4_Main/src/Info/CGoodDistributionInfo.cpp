#include "CGoodDistributionInfo.h"

// Definitions for class CGoodDistributionInfo

// address=[0x14151e0]
// Decompiled from CGoodDistributionInfo *__thiscall CGoodDistributionInfo::CGoodDistributionInfo(CGoodDistributionInfo *this)
CGoodDistributionInfo::CGoodDistributionInfo(void) : CInfoExchange()
{
  this->m_bU4 = 0;
  this->m_uEcoSectorId = -1;
}

// address=[0x1417170]
// Decompiled from int __thiscall CGoodDistributionInfo::Size(CGoodDistributionInfo *this)
unsigned int CGoodDistributionInfo::Size(void) const
{
  return 68;
}
