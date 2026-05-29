#include "CStdCargoCounter.h"

#include "CBB/CBBSupport.h"

// Definitions for class CStdCargoCounter

// address=[0x15a3ad0]
// Decompiled from void *__thiscall CStdCargoCounter::Clear(CStdCargoCounter *this)
void CStdCargoCounter::Clear(void) {
  memset(this->m_aCounters, 0, sizeof(this->m_aCounters));
}


// address=[0x15a3af0]
// Decompiled from void __thiscall CStdCargoCounter::CountEntity(CStdCargoCounter *this, int a2, int _iCargoType)
void CStdCargoCounter::CountEntity(int a2, int _iCargoType) {
  ++this->m_aCounters[0];
  if(a2 == 1) {
    ++this->m_aCounters[1];
    int v3 = g_cSettlerMgr.SettlerWarriorLevel(_iCargoType);
    if(v3) {
      ++this->m_aCounters[3];
      switch(v3) {
        case 1:
          ++this->m_aCounters[5];
          break;
        case 2:
          ++this->m_aCounters[6];
          break;
        case 3:
          ++this->m_aCounters[7];
          break;
        case 4:
          ++this->m_aCounters[8];
          break;
        default:
          BB_REPORT("Invalid cargo type")
          break;
      }
    } else {
      ++this->m_aCounters[4];
    }
  } else if(a2 == 4) {
    ++this->m_aCounters[2];
    if(_iCargoType == 5) {
      ++this->m_aCounters[9];
    } else if(_iCargoType != 4) {
      BB_REPORT("Invalid cargo type")
    }
  } else {
    BB_REPORT("Invalid cargo type")
  }
}


// address=[0x160d8f0]
// Decompiled from CStdCargoCounter *__thiscall CStdCargoCounter::CStdCargoCounter(CStdCargoCounter *this)
CStdCargoCounter::CStdCargoCounter(void) : ICargoCounter() {
  CStdCargoCounter::Clear();
}


