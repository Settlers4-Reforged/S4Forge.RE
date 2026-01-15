#include "IFutureEvents.h"

// Definitions for class IFutureEvents

// address=[0x144ff70]
// Decompiled from CFutureEvents *IFutureEvents::CreateFutureEvents()
static class IFutureEvents * __cdecl IFutureEvents::CreateFutureEvents(void) {
  
  CFutureEvents *C; // [esp+Ch] [ebp-10h]

  C = (CFutureEvents *)operator new(0x6001Cu);
  if ( C )
    return CFutureEvents::CFutureEvents(C);
  else
    return 0;
}


// address=[0x14529b0]
// Decompiled from IFutureEvents *__thiscall IFutureEvents::IFutureEvents(IFutureEvents *this)
 IFutureEvents::IFutureEvents(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  *(_DWORD *)this = IFutureEvents::_vftable_;
  return this;
}


// address=[0x1470750]
// Decompiled from int __thiscall IFutureEvents::AddFutureEvent16(  void *this,  int a2,  int a3,  int a4,  unsigned int a5,  unsigned int a6,  unsigned int a7,  unsigned int a8)
bool  IFutureEvents::AddFutureEvent16(enum T_FUTURE_EVENT,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int) {
  
  if ( a5 > 0xFFFF
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\FutureEvents.h",
         136,
         "_uDataA1 <= 0xFFFF") == 1 )
  {
    __debugbreak();
  }
  if ( a6 > 0xFFFF
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\FutureEvents.h",
         137,
         "_uDataA2 <= 0xFFFF") == 1 )
  {
    __debugbreak();
  }
  if ( a7 > 0xFFFF
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\FutureEvents.h",
         138,
         "_uDataB1 <= 0xFFFF") == 1 )
  {
    __debugbreak();
  }
  if ( a8 > 0xFFFF
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\logic\\FutureEvents.h",
         139,
         "_uDataB2 <= 0xFFFF") == 1 )
  {
    __debugbreak();
  }
  return (*(int (__thiscall **)(void *, int, int, int, unsigned int, unsigned int))(*(_DWORD *)this + 12))(
           this,
           a2,
           a3,
           a4,
           a5 | (a6 << 16),
           a7 | (a8 << 16));
}


