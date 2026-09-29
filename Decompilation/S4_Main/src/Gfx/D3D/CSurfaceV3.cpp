#include "CSurfaceV3.h"

#include "CSurfaceDescription.h"
#include "Gfx/CBlitFX.h"

#include <ddraw.h>

// Definitions for class CSurfaceV3

// address=[0x2f86ec0]
// Decompiled from CSurfaceV3 *__thiscall CSurfaceV3::CSurfaceV3(CSurfaceV3 *this)
CSurfaceV3::CSurfaceV3(void) : CSurface() {
    this->m_pSurfaceV7 = nullptr;
    this->m_pSurfaceV3 = nullptr;
    this->m_bBackbuffer = 0;
}

// address=[0x2f86f00]
// Decompiled from CSurfaceV3 *__thiscall CSurfaceV3::Release(CSurfaceV3 *this)
void CSurfaceV3::Release(void) {
    if(this->m_pSurfaceV3 != nullptr) {
        this->m_pSurfaceV3->Release();
    }
}

// address=[0x2f86f30]
// Decompiled from HRESULT __thiscall CSurfaceV3::Restore(CSurfaceV3 *this)
long CSurfaceV3::Restore(void) {

    return this->m_pSurfaceV3->Restore();
}

// address=[0x2f86f50]
// Decompiled from HRESULT __thiscall CSurfaceV3::IsLost(CSurfaceV3 *this)
long CSurfaceV3::IsLost(void) {

    return this->m_pSurfaceV3->IsLost();
}

// address=[0x2f86f70]
// Decompiled from HRESULT __thiscall CSurfaceV3::ClearSurface(CSurfaceV3 *this, struct CBlitFX *a2)
long CSurfaceV3::ClearSurface(class CBlitFX *_pBlitFx) {
    HRESULT hResult; // [esp+4h] [ebp-4h]

    if(_pBlitFx != nullptr) {
        do {
            do {
                hResult = this->m_pSurfaceV3->Blt(nullptr, nullptr, nullptr, 1536, _pBlitFx->GetBlitStructPtr());
            } while(hResult == DDERR_WASSTILLDRAWING);
        } while(hResult == DDERR_SURFACEBUSY);
    } else {
        do {
            do {
                hResult = this->m_pSurfaceV3->Blt(nullptr, nullptr, nullptr, 1536, s_cBlitFx.GetBlitStructPtr());
            } while(hResult == DDERR_WASSTILLDRAWING);
        } while(hResult == DDERR_SURFACEBUSY);
    }
    return hResult;
}

// address=[0x2f87010]
// Decompiled from HRESULT __thiscall CSurfaceV3::ClearSurface(CSurfaceV3 *this, struct tagRECT a2, struct CBlitFX *a3)
long CSurfaceV3::ClearSurface(struct tagRECT a2, class CBlitFX *_pBlitFx) {
    HRESULT hResult; // [esp+4h] [ebp-4h]

    if(_pBlitFx != nullptr) {
        do {
            do {
                hResult = this->m_pSurfaceV3->Blt(&a2, nullptr, nullptr, 1536, _pBlitFx->GetBlitStructPtr());
            } while(hResult == DDERR_WASSTILLDRAWING);
        } while(hResult == DDERR_SURFACEBUSY);
    } else {
        do {
            do {
                hResult = this->m_pSurfaceV3->Blt(&a2, nullptr, nullptr, 1536, s_cBlitFx.GetBlitStructPtr());
            } while(hResult == DDERR_WASSTILLDRAWING);
        } while(hResult == DDERR_SURFACEBUSY);
    }
    return hResult;
}

// address=[0x2f870b0]
// Decompiled from HRESULT __thiscall CSurfaceV3::Blt(CSurfaceV3 *this, struct tagRECT *a2, struct CSurface *a3, struct tagRECT *a4, DWORD a5, struct _DDBLTFX *a6)
long CSurfaceV3::Blt(struct tagRECT *a2, class CSurface *a3, struct tagRECT *a4, unsigned long a5, struct _DDBLTFX *a6) {

    HRESULT hResult; // [esp+4h] [ebp-4h]

    do {
        do {
            hResult = this->m_pSurfaceV3->Blt(a2, a3->m_pSurfaceV3, a4, a5, a6);
        } while(hResult == DDERR_WASSTILLDRAWING);
    } while(hResult == DDERR_SURFACEBUSY);
    return hResult;
}

// address=[0x2f87110]
// Decompiled from HRESULT __thiscall CSurfaceV3::Flip(CSurfaceV3 *this)
long CSurfaceV3::Flip(void) {
    return this->m_pSurfaceV3->Flip(nullptr, 1);
}

// address=[0x2f87140]
// Decompiled from HRESULT __thiscall CSurfaceV3::Lock(CSurfaceV3 *this, unsigned int *a2, void **a3, bool a4)
long CSurfaceV3::Lock(unsigned int &_rPitch, void *&_rSurface, bool a4) {

    HRESULT hResult; // [esp+8h] [ebp-4h]

    do {
        do {
            hResult = this->m_pSurfaceV3->Lock(nullptr, &s_cSurfaceDescription.m_sSurfaceDescriptionOld, 33, nullptr);
        } while(hResult == DDERR_WASSTILLDRAWING);
    } while(hResult == DDERR_SURFACEBUSY);
    _rPitch = s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwLinearSize;
    _rSurface = s_cSurfaceDescription.m_sSurfaceDescriptionOld.lpSurface;
    return hResult;
}

// address=[0x2f871b0]
// Decompiled from HRESULT __thiscall CSurfaceV3::Unlock(CSurfaceV3 *this)
long CSurfaceV3::Unlock(void) {
    return this->m_pSurfaceV3->Unlock(nullptr);
}

// address=[0x2f871e0]
// Decompiled from HRESULT __thiscall CSurfaceV3::GetDC(CSurfaceV3 *this, HDC *a2)
long CSurfaceV3::GetDC(struct HDC__ **a2) {
    HRESULT hResult; // [esp+4h] [ebp-4h]
    do {
        do {
            hResult = this->m_pSurfaceV3->GetDC(a2);
        } while(hResult == DDERR_WASSTILLDRAWING);
    } while(hResult == DDERR_SURFACEBUSY);
    return hResult;
}

// address=[0x2f87220]
// Decompiled from int __thiscall CSurfaceV3::ReleaseDC(CSurfaceV3 *this, HDC *a2)
long CSurfaceV3::ReleaseDC(HDC a2) {
    return this->m_pSurfaceV3->ReleaseDC(a2);
}

// address=[0x2f87250]
// Decompiled from int __thiscall CSurfaceV3::CreateSurface(CSurfaceV3 *this, void *a2, DWORD a3, DWORD a4, bool a5, bool a6, bool a7, int a8, bool a9, bool a10, bool a11)
long CSurfaceV3::CreateSurface(void *a2, int a3, int a4, bool a5, bool a6, bool a7, int a8, bool a9, bool a10, bool a11) {

    s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwFlags = 1;
    if(a9) {
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps = 512;
        if(a11) {
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps |= 0x4018u;
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwFlags |= 0x20u;
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwBackBufferCount = 1;
        }
    } else {
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwFlags |= 0x1000u;
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwFlags |= 4u;
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwFlags |= 2u;
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwWidth = a3;
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwHeight = a4;
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwFlags = 64;
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwFourCC = 0;
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwRGBBitCount = 16;
        if(a8 == 1) {
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwRBitMask = 31744;
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwGBitMask = 992;
        } else {
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwRBitMask = 63488;
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwGBitMask = 2016;
        }
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwBBitMask = 31;
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwRGBAlphaBitMask = 0;
        if(a7) {
            if(a8 == 2) {
                s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwRBitMask = 3840;
                s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwGBitMask = 240;
                s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwBBitMask = 15;
                s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwRGBAlphaBitMask = 61440;
                s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwFlags |= 1u;
            }
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps = 4096;
        } else {
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps = 64;
        }
        if(a5) {
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps |= 0x4000u;
        } else {
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps |= 0x800u;
        }
        if(a6 && !a7) {
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps |= 0x2000u;
        }
        if(a10 && a11) {
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps |= 0x4018u;
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwFlags |= 0x20u;
            s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwBackBufferCount = 1;
        }
    }

    return static_cast<IDirectDraw *>(a2)->CreateSurface(&s_cSurfaceDescription.m_sSurfaceDescriptionOld, &this->m_pSurfaceV3, 0);
}

// address=[0x2f87470]
// Decompiled from HRESULT __thiscall CSurfaceV3::SetColorKey(CSurfaceV3 *this, DWORD a2, struct _DDCOLORKEY *a3)
long CSurfaceV3::SetColorKey(unsigned long a2, struct _DDCOLORKEY *a3) {

    return this->m_pSurfaceV3->SetColorKey(a2, a3);
}

// address=[0x2f874a0]
// Decompiled from HRESULT __thiscall CSurfaceV3::GetPixelFormat(CSurfaceV3 *this, bool *a2)
long CSurfaceV3::GetPixelFormat(bool &a2) {
    DDPIXELFORMAT sPixelFormat{}; // [esp+Ch] [ebp-24h] BYREF
    sPixelFormat.dwSize = 32;
    HRESULT v3 = this->m_pSurfaceV3->GetPixelFormat(&sPixelFormat);
    a2 = sPixelFormat.dwGBitMask == 992;
    s_cBlitFx.SetFillColor(0, 0, 0, a2);
    s_cBlitFxAlpha.SetFillColorAlpha(0, 0, 0, 0);
    s_cBlitFxAlphaDebug.SetFillColorAlpha(0, 255, 0, 255);
    return v3;
}

// address=[0x2f87560]
// Decompiled from HRESULT __thiscall CSurfaceV3::GetBitDepth(CSurfaceV3 *this, DWORD *a2)
long CSurfaceV3::GetBitDepth(int &_rBitDepth) {
    DDPIXELFORMAT sPixelFormat{}; // [esp+8h] [ebp-24h] BYREF
    sPixelFormat.dwSize = 32;
    HRESULT hResult = this->m_pSurfaceV3->GetPixelFormat(&sPixelFormat);
    _rBitDepth = sPixelFormat.dwRGBBitCount;
    return hResult;
}

// address=[0x2f875c0]
// Decompiled from HRESULT __thiscall CSurfaceV3::GetSurfaceSize(CSurfaceV3 *this, DWORD *a2, DWORD *a3)
long CSurfaceV3::GetSurfaceSize(int &a2, int &a3) {
    HRESULT hResult = this->m_pSurfaceV3->GetSurfaceDesc(&s_cSurfaceDescription.m_sSurfaceDescriptionOld);
    a2 = s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwWidth;
    a3 = s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwHeight;
    return hResult;
}

// address=[0x2f87610]
// Decompiled from int __thiscall CSurfaceV3::SetClipper(CSurfaceV3 *this, struct IDirectDrawClipper *a2)
long CSurfaceV3::SetClipper(struct IDirectDrawClipper *a2) {
    return this->m_pSurfaceV3->SetClipper(a2);
}

// address=[0x2f87640]
// Decompiled from IDirectDrawSurface *__thiscall CSurfaceV3::GetSurfacePtr(CSurfaceV3 *this)
void *CSurfaceV3::GetSurfacePtr(void) {
    return this->m_pSurfaceV3;
}

// address=[0x2f87660]
// Decompiled from CSurfaceV3 *__thiscall CSurfaceV3::SetSurfacePtr(CSurfaceV3 *this, IDirectDrawSurface *a2)
void CSurfaceV3::SetSurfacePtr(void *a2) {
    this->m_bBackbuffer = 1;
    this->m_pSurfaceV3 = static_cast<struct IDirectDrawSurface *>(a2);
}

// address=[0x2f87680]
// Decompiled from LPDIRECTDRAWSURFACE __thiscall CSurfaceV3::GetAttachedSurfacePtr(CSurfaceV3 *this)
void *CSurfaceV3::GetAttachedSurfacePtr(void) {

    LPDIRECTDRAWSURFACE v2; // [esp+0h] [ebp-10h] BYREF
                            // [esp+4h] [ebp-Ch]
    DDSCAPS v4;             // [esp+8h] [ebp-8h] BYREF

    v4.dwCaps = 4;
    HRESULT v3 = this->m_pSurfaceV3->GetAttachedSurface(&v4, &v2);
    if(v3 != 0) {
        return nullptr;
    } else {
        return v2;
    }
}

// address=[0x2f876c0]
// Decompiled from char __thiscall CSurfaceV3::IsBackBufferReference(CSurfaceV3 *this)
bool CSurfaceV3::IsBackBufferReference(void) {

    return this->m_bBackbuffer;
}

// address=[0x2f876e0]
// Decompiled from MACRO_DDERR __thiscall CSurfaceV3::SetAsRenderTarget(CSurfaceV3 *this, struct IDirect3DDevice7 *a2)
long CSurfaceV3::SetAsRenderTarget(struct IDirect3DDevice7 *a2) {

    return DDERR_GENERIC;
}

// address=[0x2f8a320]
// Decompiled from void __thiscall CSurfaceV3::~CSurfaceV3(CSurface *this)
CSurfaceV3::~CSurfaceV3(void) = default;
