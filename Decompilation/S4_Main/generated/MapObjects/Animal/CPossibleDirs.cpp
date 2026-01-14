#include "all_headers.h"

// Definitions for class CPossibleDirs

// address=[0x14e2730]
// Decompiled from CPossibleDirs *__thiscall CPossibleDirs::Init(CPossibleDirs *this)
void  CPossibleDirs::Init(void) {
  
  CPossibleDirs *result; // eax

  result = this;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  return result;
}


// address=[0x14e2750]
// Decompiled from CPossibleDirs *__thiscall CPossibleDirs::PushDir(CPossibleDirs *this, unsigned int a2)
void  CPossibleDirs::PushDir(int) {
  
  CPossibleDirs *result; // eax

  if ( a2 >= 6
    && BBSupportDbgReport(2, "MapObjects\\Animal\\LandAnimal.cpp", 640, "(_iDir >= 0) && (_iDir < NEIGHBORS_MAX)") == 1 )
  {
    __debugbreak();
  }
  result = this;
  if ( ((1 << a2) & *((_DWORD *)this + 1)) != 0 )
    return result;
  *((_DWORD *)this + 1) |= 1 << a2;
  *((_DWORD *)this + *(_DWORD *)this + 2) = a2;
  result = this;
  ++*(_DWORD *)this;
  return result;
}


// address=[0x14e2e40]
// Decompiled from CPossibleDirs *__thiscall CPossibleDirs::CPossibleDirs(CPossibleDirs *this)
 CPossibleDirs::CPossibleDirs(void) {
  
  CPossibleDirs::Init(this);
  return this;
}


// address=[0x14e2ff0]
// Decompiled from bool __thiscall CPossibleDirs::Search(CPossibleDirs *this, char a2)
bool  CPossibleDirs::Search(int) {
  
  return ((1 << a2) & *((_DWORD *)this + 1)) != 0;
}


