#include "all_headers.h"

// Definitions for class CStdCargoCounter

// address=[0x15a3ad0]
// Decompiled from void *__thiscall CStdCargoCounter::Clear(CStdCargoCounter *this)
void  CStdCargoCounter::Clear(void) {
  
  return memset((char *)this + 4, 0, 0x28u);
}


// address=[0x15a3af0]
// Decompiled from CStdCargoCounter *__thiscall CStdCargoCounter::CountEntity(CStdCargoCounter *this, int a2, int a3)
void  CStdCargoCounter::CountEntity(int,int) {
  
  CStdCargoCounter *result; // eax
  int v4; // [esp+0h] [ebp-Ch]

  ++*((_DWORD *)this + 1);
  if ( a2 == 1 )
  {
    ++*((_DWORD *)this + 2);
    v4 = CSettlerMgr::SettlerWarriorLevel(a3);
    if ( v4 )
    {
      ++*((_DWORD *)this + 4);
      switch ( v4 )
      {
        case 1:
          result = this;
          ++*((_DWORD *)this + 6);
          break;
        case 2:
          result = this;
          ++*((_DWORD *)this + 7);
          break;
        case 3:
          result = this;
          ++*((_DWORD *)this + 8);
          break;
        case 4:
          result = this;
          ++*((_DWORD *)this + 9);
          break;
        default:
          result = (CStdCargoCounter *)BBSupportDbgReport(1, "MapObjects\\Vehicle.cpp", 1704, "Invalid cargo type");
          if ( result == (CStdCargoCounter *)1 )
            __debugbreak();
          break;
      }
    }
    else
    {
      result = this;
      ++*((_DWORD *)this + 5);
    }
  }
  else if ( a2 == 4 )
  {
    result = (CStdCargoCounter *)(*((_DWORD *)this + 3) + 1);
    *((_DWORD *)this + 3) = result;
    if ( a3 == 5 )
    {
      result = (CStdCargoCounter *)(*((_DWORD *)this + 10) + 1);
      *((_DWORD *)this + 10) = result;
    }
    else if ( a3 != 4 )
    {
      result = (CStdCargoCounter *)BBSupportDbgReport(1, "MapObjects\\Vehicle.cpp", 1725, "Invalid cargo type");
      if ( result == (CStdCargoCounter *)1 )
        __debugbreak();
    }
  }
  else
  {
    if ( BBSupportDbgReport(1, "MapObjects\\Vehicle.cpp", 1730, "Invalid cargo type") == 1 )
      __debugbreak();
    return 0;
  }
  return result;
}


// address=[0x160d8f0]
// Decompiled from CStdCargoCounter *__thiscall CStdCargoCounter::CStdCargoCounter(CStdCargoCounter *this)
 CStdCargoCounter::CStdCargoCounter(void) {
  
  ICargoCounter::ICargoCounter(this);
  *(_DWORD *)this = &CStdCargoCounter::_vftable_;
  CStdCargoCounter::Clear(this);
  return this;
}


