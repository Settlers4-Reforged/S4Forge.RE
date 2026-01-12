#include "CSurface.h"

// Definitions for class CSurface

// address=[0x2f86560]
// Decompiled from CSurfaceV7 *__cdecl CSurface::CreateSurfacePtr(bool a1)

static class CSurface * __cdecl CSurface::CreateSurfacePtr(bool) {
  
  CSurfaceV7 *v3; // [esp+10h] [ebp-18h]
  CSurfaceV3 *C; // [esp+18h] [ebp-10h]

  if ( a1 )
  {
    C = (CSurfaceV3 *)operator new(0x10u);
    if ( C )
      return (CSurfaceV7 *)CSurfaceV3::CSurfaceV3(C);
    else
      return 0;
  }
  else
  {
    v3 = (CSurfaceV7 *)operator new(0x10u);
    if ( v3 )
      return CSurfaceV7::CSurfaceV7(v3);
    else
      return 0;
  }
}


// address=[0x2f8a2f0]
// Decompiled from CSurface *__thiscall CSurface::CSurface(CSurface *this)

 CSurface::CSurface(void) {
  
  *(_DWORD *)this = &CSurface::_vftable_;
  return this;
}


// address=[0x2f8a310]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall CSurface::~CSurface(CSurface *this)

 CSurface::~CSurface(void) {
  
  ;
}


