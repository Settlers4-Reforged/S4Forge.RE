#include "CAIEvent.h"

// Definitions for class CAIEvent

// address=[0x13095e0]
// Decompiled from unsigned int __cdecl CAIEvent::Pack(unsigned int a1, unsigned int a2)
int __cdecl CAIEvent::Pack(unsigned int a1, unsigned int a2) {
  
  if ( a1 > 0xFFFF
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\LibraryDistribution\\Include\\AI_Event.h",
         102,
         "_uDataA <= 0xFFFF") == 1 )
  {
    __debugbreak();
  }
  if ( a2 > 0xFFFF
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\LibraryDistribution\\Include\\AI_Event.h",
         103,
         "_uDataB <= 0xFFFF") == 1 )
  {
    __debugbreak();
  }
  return a1 | (a2 << 16);
}


// address=[0x1310220]
// Decompiled from CAIEvent *__thiscall CAIEvent::CAIEvent(CAIEvent *this, int a2, int a3, int a4, int a5)
 CAIEvent::CAIEvent(int a2, int a3, int a4, int a5) {
  
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a4;
  *((_DWORD *)this + 3) = a5;
  return this;
}


// address=[0x13140a0]
// Decompiled from int __cdecl CAIEvent::UnpackA(unsigned __int16 a1)
unsigned int __cdecl CAIEvent::UnpackA(int a1) {
  
  return a1;
}


// address=[0x13140b0]
// Decompiled from int __cdecl CAIEvent::UnpackB(int a1)
unsigned int __cdecl CAIEvent::UnpackB(int a1) {
  
  return a1 >> 16;
}


// address=[0x1319600]
// Decompiled from int __thiscall CAIEvent::Data1(CAIEvent *this)
int  CAIEvent::Data1(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x1319620]
// Decompiled from int __thiscall CAIEvent::Data2(CAIEvent *this)
int  CAIEvent::Data2(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x1319640]
// Decompiled from int __thiscall CAIEvent::Data3(pairNode *this)
int  CAIEvent::Data3(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x1319b30]
// Decompiled from int __thiscall CAIEvent::Type(CAIEvent *this)
int  CAIEvent::Type(void)const {
  
  return *(_DWORD *)this;
}


