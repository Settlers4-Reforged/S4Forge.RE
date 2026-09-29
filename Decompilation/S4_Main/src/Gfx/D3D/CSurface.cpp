#include "CSurface.h"

#include "CSurfaceV3.h"
#include "CSurfaceV7.h"

// Definitions for class CSurface

// address=[0x2f86560]
// Decompiled from CSurfaceV7 *__cdecl CSurface::CreateSurfacePtr(bool a1)
class CSurface *__cdecl CSurface::CreateSurfacePtr(bool _bUseV3) {
    if(_bUseV3) {
        return new CSurfaceV3();
    } else {
        return new CSurfaceV7();
    }
}

// address=[0x2f8a2f0]
// Decompiled from CSurface *__thiscall CSurface::CSurface(CSurface *this)
CSurface::CSurface(void) = default;

// address=[0x2f8a310]
// Decompiled from void __thiscall CSurface::~CSurface(CSurface *this)
CSurface::~CSurface(void) = default;
