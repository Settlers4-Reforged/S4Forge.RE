#if FALSE
#include "CStdCargoCounter.h"

// Definitions for class CStdCargoCounter

// address=[0x15a3ad0]
// Decompiled from void *__thiscall CStdCargoCounter::Clear(CStdCargoCounter *this)
void  CStdCargoCounter::Clear(void) {
  
  return memset(this->m_aCounters, 0, sizeof(this->m_aCounters));
}


// address=[0x15a3af0]
// Decompiled from void __thiscall CStdCargoCounter::CountEntity(CStdCargoCounter *this, int a2, int _iCargoType)
void  CStdCargoCounter::CountEntity(int a2, int _iCargoType) {
  
  int v3; // [esp+0h] [ebp-Ch]

  ++this->m_aCounters[0];
  if ( a2 == 1 )
  {
    ++this->m_aCounters[1];
    v3 = CSettlerMgr::SettlerWarriorLevel(_iCargoType);
    if ( v3 )
    {
      ++this->m_aCounters[3];
      switch ( v3 )
      {
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
          if ( BBSupportDbgReport(1, "MapObjects\\Vehicle.cpp", 1704, "Invalid cargo type") == 1 )
            __debugbreak();
          break;
      }
    }
    else
    {
      ++this->m_aCounters[4];
    }
  }
  else if ( a2 == 4 )
  {
    ++this->m_aCounters[2];
    if ( _iCargoType == 5 )
    {
      ++this->m_aCounters[9];
    }
    else if ( _iCargoType != 4 && BBSupportDbgReport(1, "MapObjects\\Vehicle.cpp", 1725, "Invalid cargo type") == 1 )
    {
      __debugbreak();
    }
  }
  else if ( BBSupportDbgReport(1, "MapObjects\\Vehicle.cpp", 1730, "Invalid cargo type") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x160d8f0]
// Decompiled from CStdCargoCounter *__thiscall CStdCargoCounter::CStdCargoCounter(CStdCargoCounter *this)
 CStdCargoCounter::CStdCargoCounter(void) {
  
  ICargoCounter::ICargoCounter((ICargoCounter *)this);
  this->__vftable = (CStdCargoCounter_vtbl *)&CStdCargoCounter::_vftable_;
  CStdCargoCounter::Clear(this);
  return this;
}


#endif // Already implemented
