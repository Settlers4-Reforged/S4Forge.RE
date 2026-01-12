#include "CBinkInterface.h"

// Definitions for class CBinkInterface

// address=[0x16a1c40]
// Decompiled from CBinkInterface *__thiscall CBinkInterface::CBinkInterface(CBinkInterface *this)
 CBinkInterface::CBinkInterface(void) {
  
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = -1;
  return this;
}


// address=[0x16a1c70]
// Decompiled from void __thiscall CBinkInterface::~CBinkInterface(CBinkInterface *this)
 CBinkInterface::~CBinkInterface(void) {
  
  CBinkInterface::CloseBink(this);
}


// address=[0x16a1cb0]
// Decompiled from char __thiscall CBinkInterface::OpenVideo(CBinkInterface *this, char *a2, unsigned int a3, unsigned int a4)
bool  CBinkInterface::OpenVideo(char *,unsigned int,unsigned int) {
  
  const char *Error; // eax

  *(_DWORD *)this = BinkOpen(a2, 0);
  if ( *(_DWORD *)this )
  {
    if ( **(_DWORD **)this <= a3 && *(_DWORD *)(*(_DWORD *)this + 4) <= a4 )
    {
      return 1;
    }
    else
    {
      BBSupportTracePrintF(
        0,
        "VideoEngine : CBinkInterface::OpenVideo : Wrong video size %dx%d",
        **(_DWORD **)this,
        *(_DWORD *)(*(_DWORD *)this + 4));
      return 0;
    }
  }
  else
  {
    Error = (const char *)BinkGetError();
    BBSupportTracePrintF(0, "VideoEngine : CBinkInterface::OpenVideo : %s %s", Error, a2);
    return 0;
  }
}


// address=[0x16a1d40]
// Decompiled from int __thiscall CBinkInterface::StartPause(CBinkInterface *this)
void  CBinkInterface::StartPause(void) {
  
  if ( !*(_DWORD *)this && BBSupportDbgReport(2, "VideoEngine\\VideoEngine.cpp", 80, "m_hBink") == 1 )
    __debugbreak();
  return BinkPause(*(_DWORD *)this, 1);
}


// address=[0x16a1d80]
// Decompiled from int __thiscall CBinkInterface::StopPause(CBinkInterface *this)
void  CBinkInterface::StopPause(void) {
  
  if ( !*(_DWORD *)this && BBSupportDbgReport(2, "VideoEngine\\VideoEngine.cpp", 89, "m_hBink") == 1 )
    __debugbreak();
  return BinkPause(*(_DWORD *)this, 0);
}


// address=[0x16a1dc0]
// Decompiled from int __thiscall CBinkInterface::GetHeight(CBinkInterface *this)
int  CBinkInterface::GetHeight(void) {
  
  if ( !*(_DWORD *)this && BBSupportDbgReport(2, "VideoEngine\\VideoEngine.cpp", 98, "m_hBink") == 1 )
    __debugbreak();
  return *(_DWORD *)(*(_DWORD *)this + 4);
}


// address=[0x16a1e00]
// Decompiled from int __thiscall CBinkInterface::GetWidth(CBinkInterface *this)
int  CBinkInterface::GetWidth(void) {
  
  if ( !*(_DWORD *)this && BBSupportDbgReport(2, "VideoEngine\\VideoEngine.cpp", 107, "m_hBink") == 1 )
    __debugbreak();
  return **(_DWORD **)this;
}


// address=[0x16a1e40]
// Decompiled from int __thiscall CBinkInterface::UseMiles(CBinkInterface *this, unsigned int a2)
void  CBinkInterface::UseMiles(unsigned long) {
  
  return BinkSetSoundSystem(BinkOpenMiles, a2);
}


// address=[0x16a1e60]
// Decompiled from CBinkInterface *__thiscall CBinkInterface::CloseBink(CBinkInterface *this)
void  CBinkInterface::CloseBink(void) {
  
  CBinkInterface *result; // eax

  result = this;
  if ( !*(_DWORD *)this )
    return result;
  BinkClose(*(_DWORD *)this);
  result = this;
  *(_DWORD *)this = 0;
  return result;
}


// address=[0x16a1e90]
// Decompiled from char __thiscall CBinkInterface::RenderToSurface(CBinkInterface *this, unsigned __int16 *a2, unsigned int a3)
bool  CBinkInterface::RenderToSurface(unsigned short *,unsigned int) {
  
  if ( !*(_DWORD *)this )
  {
    BBSupportTracePrintF(0, "VideoEngine : CBinkInterface::RenderToSurface : No Bink initialized.");
    return 0;
  }
  if ( *((int *)this + 1) < 0 )
  {
    BBSupportTracePrintF(0, "VideoEngine : CBinkInterface::RenderToSurface : Unknown GfxMode %i", *((_DWORD *)this + 1));
    return 0;
  }
  if ( BinkWait(*(_DWORD *)this) )
    return 1;
  BinkDoFrame(*(_DWORD *)this);
  BinkCopyToBuffer(*(_DWORD *)this, a2, a3, *(_DWORD *)(*(_DWORD *)this + 4), 0, 0, *((_DWORD *)this + 1));
  if ( *(_DWORD *)(*(_DWORD *)this + 12) == *(_DWORD *)(*(_DWORD *)this + 8) )
    return 0;
  BinkNextFrame(*(_DWORD *)this);
  return 1;
}


// address=[0x16a1f50]
// Decompiled from CBinkInterface *__thiscall CBinkInterface::Set_555_GfxMode(CBinkInterface *this)
void  CBinkInterface::Set_555_GfxMode(void) {
  
  CBinkInterface *result; // eax

  result = this;
  *((_DWORD *)this + 1) = 9;
  return result;
}


// address=[0x16a1f70]
// Decompiled from CBinkInterface *__thiscall CBinkInterface::Set_565_GfxMode(CBinkInterface *this)
void  CBinkInterface::Set_565_GfxMode(void) {
  
  CBinkInterface *result; // eax

  result = this;
  *((_DWORD *)this + 1) = 10;
  return result;
}


// address=[0x16a1f90]
// Decompiled from bool __thiscall CBinkInterface::IsReadyForNextFrame(CBinkInterface *this)
bool  CBinkInterface::IsReadyForNextFrame(void) {
  
  return BinkWait(*(_DWORD *)this) == 0;
}


