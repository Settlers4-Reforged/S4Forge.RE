#include "CPlayerStatisticData.h"

// Definitions for class CPlayerStatisticData

// address=[0x1508170]
// Decompiled from void __thiscall CPlayerStatisticData::IncreaseMushroomFarmsDestroyed(CPlayerStatisticData *this)
void  CPlayerStatisticData::IncreaseMushroomFarmsDestroyed(void) {
  
  ++this->m_iMushroomFarmsDestroyed;
}


// address=[0x160daa0]
// Decompiled from int __thiscall CPlayerStatisticData::MushroomFarmsDestroyed(CPlayerStatisticData *this)
int  CPlayerStatisticData::MushroomFarmsDestroyed(void)const {
  
  return this->m_iMushroomFarmsDestroyed;
}


// address=[0x160db50]
// Decompiled from int __thiscall CPlayerStatisticData::ServantsFreed(CPlayerStatisticData *this)
int  CPlayerStatisticData::ServantsFreed(void)const {
  
  return this->m_iServantsFreed;
}


// address=[0x1474c70]
// Decompiled from void *__thiscall CPlayerStatisticData::Clear(CPlayerStatisticData *this)
void  CPlayerStatisticData::Clear(void) {
  
  return memset(this, 0, sizeof(CPlayerStatisticData));
}


