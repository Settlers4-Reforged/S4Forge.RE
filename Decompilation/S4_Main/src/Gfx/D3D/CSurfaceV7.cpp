#include "CSurfaceV7.h"

#include "CSurfaceDescription.h"
#include "Gfx/CBlitFX.h"

#include <assert.h>
#include <d3d.h>
#include <ddraw.h>

// Definitions for class CSurfaceV7

// address=[0x2f86620]
// Decompiled from CSurfaceV7 *__thiscall CSurfaceV7::CSurfaceV7(CSurfaceV7 *this)
CSurfaceV7::CSurfaceV7(void) : CSurface() {
    this->m_pSurfaceV3 = nullptr;
    this->m_pSurfaceV7 = nullptr;
    this->m_bBackbuffer = 0;
}

// address=[0x2f86660]
// Decompiled from void __thiscall CSurfaceV7::Release(CSurfaceV7 *this)
void CSurfaceV7::Release(void) {

    if(this->m_pSurfaceV7 != nullptr) {
        this->m_pSurfaceV7->Release();
    }
}

// address=[0x2f86690]
// Decompiled from HRESULT __thiscall CSurfaceV7::Restore(CSurfaceV7 *this)
long CSurfaceV7::Restore(void) {

    return this->m_pSurfaceV7->Restore();
}

// address=[0x2f866b0]
// Decompiled from HRESULT __thiscall CSurfaceV7::IsLost(CSurfaceV7 *this)
long CSurfaceV7::IsLost(void) {

    return this->m_pSurfaceV7->IsLost();
}

// address=[0x2f866d0]
// Decompiled from HRESULT __thiscall CSurfaceV7::ClearSurface(CSurfaceV7 *this, struct CBlitFX *a2)
long CSurfaceV7::ClearSurface(class CBlitFX *_pBlitFx) {
    HRESULT hResult; // [esp+4h] [ebp-4h]

    if(_pBlitFx != nullptr) {
        do {
            do {
                hResult = this->m_pSurfaceV7->Blt(nullptr, nullptr, nullptr, 1536, _pBlitFx->GetBlitStructPtr());
            } while(hResult == DDERR_WASSTILLDRAWING);
        } while(hResult == DDERR_SURFACEBUSY);
    } else {
        do {
            do {
                hResult = this->m_pSurfaceV7->Blt(nullptr, nullptr, nullptr, 1536, s_cBlitFx.GetBlitStructPtr());
            } while(hResult == DDERR_WASSTILLDRAWING);
        } while(hResult == DDERR_SURFACEBUSY);
    }
    return hResult;
}

// address=[0x2f86770]
// Decompiled from HRESULT __thiscall CSurfaceV7::ClearSurface(CSurfaceV7 *this, struct tagRECT a2, struct CBlitFX *a3)
long CSurfaceV7::ClearSurface(struct tagRECT a2, class CBlitFX *_pBlitFx) {
    HRESULT hResult; // [esp+4h] [ebp-4h]

    if(_pBlitFx != nullptr) {
        do {
            do {
                hResult = this->m_pSurfaceV7->Blt(&a2, nullptr, nullptr, 1536, _pBlitFx->GetBlitStructPtr());
            } while(hResult == DDERR_WASSTILLDRAWING);
        } while(hResult == DDERR_SURFACEBUSY);
    } else {
        do {
            do {
                hResult = this->m_pSurfaceV7->Blt(&a2, nullptr, nullptr, 1536, s_cBlitFx.GetBlitStructPtr());
            } while(hResult == DDERR_WASSTILLDRAWING);
        } while(hResult == DDERR_SURFACEBUSY);
    }
    return hResult;
}

// address=[0x2f86810]
// Decompiled from HRESULT __thiscall CSurfaceV7::Blt(CSurfaceV7 *this, struct tagRECT *a2, CSurfaceV7 *a3, struct tagRECT *a4, DWORD a5, struct _DDBLTFX *a6)
long CSurfaceV7::Blt(struct tagRECT *a2, class CSurface *a3, struct tagRECT *a4, unsigned long a5, struct _DDBLTFX *a6) {
    HRESULT hResult; // [esp+4h] [ebp-4h]

    do {
        do {
            hResult = this->m_pSurfaceV7->Blt(a2, a3->m_pSurfaceV7, a4, a5, a6);
        } while(hResult == DDERR_WASSTILLDRAWING);
    } while(hResult == DDERR_SURFACEBUSY);
    return hResult;
}

// address=[0x2f86870]
// Decompiled from HRESULT __thiscall CSurfaceV7::Flip(CSurfaceV7 *this)
long CSurfaceV7::Flip(void) {
    return this->m_pSurfaceV7->Flip(nullptr, 1);
}

// address=[0x2f868a0]
// Decompiled from HRESULT __thiscall CSurfaceV7::Lock(CSurfaceV7 *this, unsigned int *a2, void **a3, bool a4)
long CSurfaceV7::Lock(unsigned int &_rPitch, void *&_rSurface, bool a4) {

    HRESULT hResult; // [esp+4h] [ebp-8h]
                     // [esp+8h] [ebp-4h]

    DWORD v7 = 1;
    if(a4) {
        v7 = 2049;
    }
    do {
        do {
            hResult = this->m_pSurfaceV7->Lock(nullptr, &s_cSurfaceDescription.m_sSurfaceDescription, v7, nullptr);
        } while(hResult == DDERR_WASSTILLDRAWING);
    } while(hResult == DDERR_SURFACEBUSY);
    _rPitch = s_cSurfaceDescription.m_sSurfaceDescription.dwLinearSize;
    _rSurface = s_cSurfaceDescription.m_sSurfaceDescription.lpSurface;
    return hResult;
}

// address=[0x2f86920]
// Decompiled from HRESULT __thiscall CSurfaceV7::Unlock(CSurfaceV7 *this)
long CSurfaceV7::Unlock(void) {

    return this->m_pSurfaceV7->Unlock(nullptr);
}

// address=[0x2f86950]
// Decompiled from HRESULT __thiscall CSurfaceV7::GetDC(CSurfaceV7 *this, HDC *a2)
long CSurfaceV7::GetDC(struct HDC__ **a2) {

    HRESULT v4; // [esp+4h] [ebp-4h]

    do {
        do {
            v4 = this->m_pSurfaceV7->GetDC(a2);
        } while(v4 == DDERR_WASSTILLDRAWING);
    } while(v4 == DDERR_SURFACEBUSY);
    return v4;
}

// address=[0x2f86990]
// Decompiled from int __thiscall CSurfaceV7::ReleaseDC(CSurfaceV7 *this, HDC a2)
long CSurfaceV7::ReleaseDC(HDC a2) {

    return this->m_pSurfaceV7->ReleaseDC(a2);
}

// address=[0x2f869c0]
// Decompiled from int __thiscall CSurfaceV7::CreateSurface(CSurfaceV7 *this, void *pDDInterface, unsigned int iWidth, unsigned int iHeight, unsigned __int8 bVideoMem, unsigned __int8 bHwAccess, unsigned __int8 bIsTexture, int iSurfaceFormat, unsigned __int8 bPrimary)
long CSurfaceV7::CreateSurface(void *pDDInterface, int iWidth, int iHeight, bool bVideoMem, bool bHwAccess, bool bIsTexture, int iSurfaceFormat, bool bPrimary, bool a9, bool a10) {

    char v10; // [esp+2Ch] [ebp+28h]
    char v11; // [esp+30h] [ebp+2Ch]

    s_cSurfaceDescription.m_sSurfaceDescription.dwFlags = 1;
    if(bPrimary != 0) {
        s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps = 512;
        if(v11 != 0) {
            s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps |= 0x18u;
            s_cSurfaceDescription.m_sSurfaceDescription.dwFlags |= 0x20u;
            s_cSurfaceDescription.m_sSurfaceDescription.dwBackBufferCount = 1;
            if(bHwAccess != 0) {
                s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps |= 0x2000u;
            }
        }
    } else {
        s_cSurfaceDescription.m_sSurfaceDescription.dwFlags |= 0x1000u;
        s_cSurfaceDescription.m_sSurfaceDescription.dwFlags |= 4u;
        s_cSurfaceDescription.m_sSurfaceDescription.dwFlags |= 2u;
        s_cSurfaceDescription.m_sSurfaceDescription.dwWidth = iWidth;
        s_cSurfaceDescription.m_sSurfaceDescription.dwHeight = iHeight;
        s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwFlags = 64;
        s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwFourCC = 0;
        s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwRGBBitCount = 16;
        if(iSurfaceFormat == 1) {
            s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwRBitMask = 0x7C00;
            s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwGBitMask = 0x3E0;
            s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwBBitMask = 0x1F;
            s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwRGBAlphaBitMask = 0;
        } else {
            s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwRBitMask = 0x0F800;
            s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwGBitMask = 0x7E0;
            s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwBBitMask = 0x1F;
            s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwRGBAlphaBitMask = 0;
        }

        if(bIsTexture != 0) {
            if(iSurfaceFormat == 2) {
                s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwRBitMask = 0xF00;
                s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwGBitMask = 0xF0;
                s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwBBitMask = 0xF;
                s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwRGBAlphaBitMask = 0xF000;
                s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwFlags |= 1u;
            }
            s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps = DDSCAPS_TEXTURE;
        } else {
            s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps = DDSCAPS_OFFSCREENPLAIN;
        }
        if(bVideoMem != 0) {
            s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps |= DDSCAPS_VIDEOMEMORY;
        } else {
            s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps |= DDSCAPS_SYSTEMMEMORY;
        }
        if(bHwAccess != 0 && bIsTexture == 0) {
            s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps |= DDSCAPS_3DDEVICE;
        }
        if(v10 != 0 && v11 != 0) {
            s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps |= DDSCAPS_COMPLEX | DDSCAPS_FLIP | DDSCAPS_VIDEOMEMORY; // 0x4018u;
            s_cSurfaceDescription.m_sSurfaceDescription.dwFlags |= DDSD_BACKBUFFERCOUNT;
            s_cSurfaceDescription.m_sSurfaceDescription.dwBackBufferCount = 1;
        }
    }
    return static_cast<IDirectDraw7 *>(pDDInterface)->CreateSurface(&s_cSurfaceDescription.m_sSurfaceDescription, &this->m_pSurfaceV7, 0);
}

// address=[0x2f86bf0]
// Decompiled from HRESULT __thiscall CSurfaceV7::SetColorKey(CSurfaceV7 *this, DWORD a2, struct _DDCOLORKEY *a3)
long CSurfaceV7::SetColorKey(unsigned long a2, struct _DDCOLORKEY *a3) {

    return this->m_pSurfaceV7->SetColorKey(a2, a3);
}

// address=[0x2f86c20]
// Decompiled from HRESULT __thiscall CSurfaceV7::GetPixelFormat(CSurfaceV7 *this, bool *a2)
long CSurfaceV7::GetPixelFormat(bool &_rIs555) {
    DDPIXELFORMAT sPixelFormat{}; // [esp+8h] [ebp-24h] BYREF
    sPixelFormat.dwSize = 32;
    HRESULT hResult = this->m_pSurfaceV7->GetPixelFormat(&sPixelFormat);
    _rIs555 = false;
    s_cBlitFx.SetFillColor(0, 0, 0, _rIs555);
    s_cBlitFxAlpha.SetFillColorAlpha(0, 0, 0, 0);
    s_cBlitFxAlphaDebug.SetFillColorAlpha(0, 255, 0, 255);
    return hResult;
}

// address=[0x2f86cc0]
// Decompiled from HRESULT __thiscall CSurfaceV7::GetBitDepth(CSurfaceV7 *this, DWORD *a2)
long CSurfaceV7::GetBitDepth(int &_rBitDepth) {
    DDPIXELFORMAT sPixelFormat; // [esp+8h] [ebp-24h] BYREF

    sPixelFormat.dwSize = 32;
    HRESULT hResult = this->m_pSurfaceV7->GetPixelFormat(&sPixelFormat);
    _rBitDepth = sPixelFormat.dwRGBBitCount;
    return hResult;
}

// address=[0x2f86d20]
// Decompiled from HRESULT __thiscall CSurfaceV7::GetSurfaceSize(CSurfaceV7 *this, DWORD *a2, DWORD *a3)
long CSurfaceV7::GetSurfaceSize(int &_rWidth, int &_rHeight) {
    HRESULT hResult = this->m_pSurfaceV7->GetSurfaceDesc(&s_cSurfaceDescription.m_sSurfaceDescription);
    _rWidth = s_cSurfaceDescription.m_sSurfaceDescription.dwWidth;
    _rHeight = s_cSurfaceDescription.m_sSurfaceDescription.dwHeight;
    return hResult;
}

// address=[0x2f86d70]
// Decompiled from int __thiscall CSurfaceV7::SetClipper(CSurfaceV7 *this, struct IDirectDrawClipper *a2)
long CSurfaceV7::SetClipper(struct IDirectDrawClipper *a2) {
    return this->m_pSurfaceV7->SetClipper(a2);
}

// address=[0x2f86da0]
// Decompiled from LPDIRECTDRAWSURFACE7 __thiscall CSurfaceV7::GetSurfacePtr(CSurfaceV7 *this)
void *CSurfaceV7::GetSurfacePtr(void) {

    return this->m_pSurfaceV7;
}

// address=[0x2f86dc0]
// Decompiled from void __thiscall CSurfaceV7::SetSurfacePtr(CSurfaceV7 *this, struct IDirectDrawSurface7 *a2)
void CSurfaceV7::SetSurfacePtr(void *a2) {
    this->m_bBackbuffer = 1;
    this->m_pSurfaceV7 = static_cast<IDirectDrawSurface7 *>(a2);
}

// address=[0x2f86de0]
// Decompiled from int __thiscall CSurfaceV7::GetAttachedSurfacePtr(CSurfaceV7 *this)
void *CSurfaceV7::GetAttachedSurfacePtr(void) {
    DDSCAPS2 sCaps; // [esp+Ch] [ebp-14h] BYREF
    sCaps.dwCaps = 4;
    memset(&sCaps.dwCaps2, 0, 12);

    IDirectDrawSurface7 *pAttachedSurface;
    HRESULT hResult = this->m_pSurfaceV7->GetAttachedSurface(&sCaps, &pAttachedSurface);
    if(hResult != 0) {
        return nullptr;
    }

    return pAttachedSurface;
}

// address=[0x2f86e50]
// Decompiled from char __thiscall CSurfaceV7::IsBackBufferReference(CSurfaceV7 *this)
bool CSurfaceV7::IsBackBufferReference(void) {

    return this->m_bBackbuffer;
}

// address=[0x2f86e70]
// Decompiled from HRESULT __thiscall CSurfaceV7::SetAsRenderTarget(CSurfaceV7 *this, struct IDirect3DDevice7 *a2)
long CSurfaceV7::SetAsRenderTarget(IDirect3DDevice7 *a2) {

    if(this->m_pSurfaceV7 == nullptr) {
        // TODO: replace with BBSupport...
        _wassert(L"m_pSurfaceV7 != nullptr", L"DirectXHelperClasses.cpp", 0x56Au);
    }
    return a2->SetRenderTarget(this->m_pSurfaceV7, 0);
}

// address=[0x2f8a340]
// Decompiled from void __thiscall CSurfaceV7::~CSurfaceV7(CSurfaceV7 *this)
CSurfaceV7::~CSurfaceV7(void) = default;