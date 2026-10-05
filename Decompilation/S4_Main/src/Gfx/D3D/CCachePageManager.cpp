#include "CCachePageManager.h"

#include "CBB/CBBSupport.h"
#include "Gfx/CBlitFX.h"
#include "Gfx/GfxEngineSetup.h"

#include <d3d.h>

// Definitions for class CCachePageManager

// address=[0x2f5f420]
// Decompiled from void __thiscall CCachePageManager::SetCurrentZoomFactor(CCachePageManager *this, float a2)
void CCachePageManager::SetCurrentZoomFactor(float a2) {

    CCachePageManager::sm_fZoomFactor = a2;
}

// address=[0x2f69960]
// Decompiled from unsigned __int8 __thiscall CCachePageManager::IsSourceSurfaceLocked(CCachePageManager *this)
bool CCachePageManager::IsSourceSurfaceLocked(void) {

    return this->m_bSoureSurfaceIsLocked;
}

// address=[0x2f69980]
// Decompiled from unsigned __int8 __thiscall CCachePageManager::IsVideoSurfaceLocked(CCachePageManager *this)
bool CCachePageManager::IsVideoSurfaceLocked(void) {

    return this->m_bVideoSurfaceIsLocked;
}

// address=[0x2f87760]
// Decompiled from CCachePageManager *__thiscall CCachePageManager::CCachePageManager(CCachePageManager *this, struct IDirectDrawSurface7 *a2, struct IDirectDrawSurface7 *a3, struct IDirect3DDevice7 *a4)
CCachePageManager::CCachePageManager(struct IDirectDrawSurface7 *a2, struct IDirectDrawSurface7 *a3, struct IDirect3DDevice7 *a4) {

    // [esp+4h] [ebp-8h]
    // [esp+4h] [ebp-8h]

    this->m_pVideoTexture = a2;
    this->m_pSystemTexture = a3;
    this->m_pRenderDevice = a4;
    this->m_iCurrentY = 0;
    this->m_iCurrentX = 0;
    this->m_iUploadHeight = 0;
    this->m_iUploadWidth = 0;
    this->m_iNumberOfObjects = 0;
    this->m_bVideoSurfaceIsLocked = 0;
    this->m_bSoureSurfaceIsLocked = 0;
    this->m_pRenderAdress = nullptr;
    this->m_iPitch = 0;
    this->m_sUploadRectangle.top = 0;
    this->m_sUploadRectangle.left = 0;
    this->m_sUploadRectangle.right = 511;
    this->m_sUploadRectangle.bottom = 511;
    this->m_sDestinationPoint.x = 0;
    this->m_sDestinationPoint.y = 0;
    for(int i = 0;
        i < 576;
        ++i) {
        sm_sVertexList[i].color = 0xFFFFFF;
        sm_sVertexList[i].sz = 0.5f;
        sm_sVertexList[i].rhw = 0.5f;
    }
    for(int j = 0;
        j < 512;
        ++j) {
        sm_fTextureCoordTable[j] = ((float)j / 512.0) + 0.0009765625;
    }
}

// address=[0x2f878f0]
// Decompiled from CCachePageManager *__thiscall CCachePageManager::~CCachePageManager(CCachePageManager *this)
CCachePageManager::~CCachePageManager(void) {
    if(this->m_bSoureSurfaceIsLocked == 0) {
        UnlockSourceSurface();
    }
}

// address=[0x2f87940]
// Decompiled from unsigned __int8 __thiscall CCachePageManager::GetPictureArea(CCachePageManager *this, int iBlitX, int iBlitY, int iWidth, int iHeight, int iShading, unsigned __int8 iShifting, int *iPosX, int *iPosY)
bool CCachePageManager::GetPictureArea(float _fBlitX, float _fBlitY, int _iWidth, int _iHeight, int _iShading, int _iShifting, int &_iPosX, int &_iPosY) {

    int iUploadHeight; // [esp+0h] [ebp-Ch]
    int iCurrentX;     // [esp+4h] [ebp-8h]

    if(this->m_iNumberOfObjects >= 96) {
        return 0;
    }
    if(_iHeight + this->m_iCurrentY >= 512) {
        return 0;
    }
    if(_iWidth + this->m_iCurrentX >= 512) {
        this->m_iCurrentX = 0;
        this->m_iCurrentY = this->m_iUploadHeight;
        if(_iHeight + this->m_iCurrentY >= 512) {
            return 0;
        }
        if(_iWidth + this->m_iCurrentX >= 512) {
            return 0;
        }
    }
    _iPosX = this->m_iCurrentX;
    _iPosY = this->m_iCurrentY;
    this->m_iCurrentX += _iWidth;
    if(this->m_iUploadWidth <= this->m_iCurrentX) {
        iCurrentX = this->m_iCurrentX;
    } else {
        iCurrentX = this->m_iUploadWidth;
    }
    this->m_iUploadWidth = iCurrentX;
    if(this->m_iUploadHeight <= _iHeight + this->m_iCurrentY) {
        iUploadHeight = _iHeight + this->m_iCurrentY;
    } else {
        iUploadHeight = this->m_iUploadHeight;
    }
    this->m_iUploadHeight = iUploadHeight;
    this->m_sRectangleList[this->m_iNumberOfObjects].left = static_cast<WORD>(_iPosX);
    this->m_sRectangleList[this->m_iNumberOfObjects].top = static_cast<WORD>(_iPosY);
    this->m_sRectangleList[this->m_iNumberOfObjects].right = _iWidth + _iPosX;
    this->m_sRectangleList[this->m_iNumberOfObjects].bottom = _iHeight + _iPosY;
    this->m_sBlitPosition[this->m_iNumberOfObjects].x = _fBlitX;
    this->m_sBlitPosition[this->m_iNumberOfObjects].y = _fBlitY;
    this->m_iShading[this->m_iNumberOfObjects] = _iShading;
    this->m_uShifting[this->m_iNumberOfObjects++] = _iShifting;
    return 1;
}

// address=[0x2f87b30]
// Decompiled from HRESULT __thiscall CCachePageManager::EraseExtensionAreas(CCachePageManager *this, int _iIndex, int a3, int a4, int a5, int a6, bool a7)
long CCachePageManager::EraseExtensionAreas(int _iIndex, int a3, int a4, int a5, int a6, bool a7) {

    // edx
    _DDBLTFX *sDDBltFx; // [esp+0h] [ebp-20h]
                        // [esp+4h] [ebp-1Ch]
    tagRECT sRect;      // [esp+Ch] [ebp-14h] BYREF

    HRESULT v10 = 0;
    if(a7) {
        sDDBltFx = s_cBlitFxAlphaDebug.GetBlitStructPtr();
    } else {
        sDDBltFx = s_cBlitFxAlpha.GetBlitStructPtr();
    }
    if(_iIndex >= this->m_iNumberOfObjects) {
        return v10;
    }
    if(a5 != 0) {
        sRect.top = this->m_sRectangleList[_iIndex].top;
        sRect.bottom = this->m_sRectangleList[_iIndex].bottom;
        sRect.left = this->m_sRectangleList[_iIndex].left;
        int right = this->m_sRectangleList[_iIndex].right;
        sRect.right = a5 + sRect.left;
        do {
            do {
                v10 = this->m_pSystemTexture->Blt(&sRect, nullptr, nullptr, 1536, sDDBltFx);
            } while(v10 == DDERR_WASSTILLDRAWING);
        } while(v10 == DDERR_SURFACEBUSY);
    }
    if(a6 != 0 && v10 == 0) {
        sRect.top = this->m_sRectangleList[_iIndex].top;
        sRect.bottom = this->m_sRectangleList[_iIndex].bottom;
        sRect.left = this->m_sRectangleList[_iIndex].left;
        sRect.right = this->m_sRectangleList[_iIndex].right;
        sRect.left = sRect.right - a6;
        do {
            do {
                v10 = this->m_pSystemTexture->Blt(&sRect, nullptr, nullptr, 1536, sDDBltFx);
            } while(v10 == DDERR_WASSTILLDRAWING);
        } while(v10 == DDERR_SURFACEBUSY);
    }
    if(a3 != 0 && v10 == 0) {
        sRect.top = this->m_sRectangleList[_iIndex].top;
        sRect.bottom = this->m_sRectangleList[_iIndex].bottom;
        sRect.left = this->m_sRectangleList[_iIndex].left;
        sRect.right = this->m_sRectangleList[_iIndex].right;
        sRect.bottom = a3 + sRect.top;
        do {
            do {
                v10 = this->m_pSystemTexture->Blt(&sRect, nullptr, nullptr, 1536, sDDBltFx);
            } while(v10 == DDERR_WASSTILLDRAWING);
        } while(v10 == DDERR_SURFACEBUSY);
    }
    if(a4 == 0 || v10 != 0) {
        return v10;
    }
    sRect.top = this->m_sRectangleList[_iIndex].top;
    sRect.bottom = this->m_sRectangleList[_iIndex].bottom;
    sRect.left = this->m_sRectangleList[_iIndex].left;
    sRect.right = this->m_sRectangleList[_iIndex].right;
    sRect.top = sRect.bottom - a4;
    do {
        do {
            v10 = this->m_pSystemTexture->Blt(&sRect, nullptr, nullptr, 1536, sDDBltFx);
        } while(v10 == DDERR_WASSTILLDRAWING);
    } while(v10 == DDERR_SURFACEBUSY);
    return v10;
}

// address=[0x2f87db0]
// Decompiled from bool __thiscall CCachePageManager::UploadData(CCachePageManager *this, int *hResult)
bool CCachePageManager::UploadData(long &_rResult) {
    if(!CCachePageManager::IsData()) {
        _rResult = 0;
        return false;
    }

    if(this->m_bSoureSurfaceIsLocked != 0 && (_rResult = CCachePageManager::UnlockSourceSurface(), _rResult != 0)) {
        return false;
    }
    this->m_sUploadRectangle.right = this->m_iUploadWidth;
    this->m_sUploadRectangle.bottom = this->m_iUploadHeight;
    _rResult = this->m_pRenderDevice->Load(this->m_pVideoTexture, &this->m_sDestinationPoint, this->m_pSystemTexture, &this->m_sUploadRectangle, 0);
    if(_rResult == DDERR_SURFACELOST) {
        this->m_pVideoTexture->Restore();
        CCachePageManager::ReleaseData();
        return false;
    }

    return _rResult == 0;
}

// address=[0x2f87ea0]
// Decompiled from char __thiscall CCachePageManager::UploadDataAndRender(CCachePageManager *this, int *a2)
bool CCachePageManager::UploadDataAndRender(long &_rResult) {

    // [esp+0h] [ebp-2Ch]
    // [esp+4h] [ebp-28h]
    // [esp+8h] [ebp-24h]
    // [esp+Ch] [ebp-20h]
    // [esp+10h] [ebp-1Ch]
    // [esp+14h] [ebp-18h]
    // [esp+18h] [ebp-14h]
    // [esp+1Ch] [ebp-10h]
    // [esp+20h] [ebp-Ch]
    // [esp+28h] [ebp-4h]

    if(!CCachePageManager::IsData()) {
        _rResult = 0;
        return 0;
    }
    _rResult = this->m_pRenderDevice->SetTexture(0, this->m_pVideoTexture);
    if(_rResult != 0)
        return 0;
    if(this->m_bSoureSurfaceIsLocked != 0 && (_rResult = CCachePageManager::UnlockSourceSurface(), _rResult != 0))
        return 0;

    this->m_sUploadRectangle.right = this->m_iUploadWidth;
    this->m_sUploadRectangle.bottom = this->m_iUploadHeight;
    _rResult = this->m_pRenderDevice->Load(this->m_pVideoTexture, &this->m_sDestinationPoint, this->m_pSystemTexture, &this->m_sUploadRectangle, 0);
    if(_rResult == DDERR_SURFACELOST) {
        this->m_pVideoTexture->Restore();
        CCachePageManager::ReleaseData();
        return 0;
    }
    if(_rResult != 0)
        return 0;

    for(int i = 0; i < this->m_iNumberOfObjects; ++i) {
        int v8 = this->m_sRectangleList[i].left + 1;
        int v7 = this->m_sRectangleList[i].top + 1;
        int v6 = this->m_sRectangleList[i].right - v8 - 1;
        int v5 = this->m_sRectangleList[i].bottom - v7 - 1;
        int v4 = static_cast<int>(v6 * CCachePageManager::sm_fZoomFactor) >> this->m_uShifting[i];
        int v3 = static_cast<int>(v5 * CCachePageManager::sm_fZoomFactor) >> this->m_uShifting[i];
        D3DVALUE v10 = s_iObjectOffsetX + this->m_sBlitPosition[i].x + CCachePageManager::sm_fZoomFactor;
        D3DVALUE v9 = s_iObjectOffsetY + this->m_sBlitPosition[i].y + CCachePageManager::sm_fZoomFactor;

        int iVertexGroup = 6 * i;

        CCachePageManager::sm_sVertexList[iVertexGroup].sx = v10;
        CCachePageManager::sm_sVertexList[iVertexGroup].sy = v9;
        CCachePageManager::sm_sVertexList[iVertexGroup].tu = CCachePageManager::sm_fTextureCoordTable[v8];
        CCachePageManager::sm_sVertexList[iVertexGroup].tv = CCachePageManager::sm_fTextureCoordTable[v7];

        CCachePageManager::sm_sVertexList[iVertexGroup + 1].sx = v4 + v10;
        CCachePageManager::sm_sVertexList[iVertexGroup + 1].sy = v3 + v9;
        CCachePageManager::sm_sVertexList[iVertexGroup + 1].tu = CCachePageManager::sm_fTextureCoordTable[v6 + v8];
        CCachePageManager::sm_sVertexList[iVertexGroup + 1].tv = CCachePageManager::sm_fTextureCoordTable[v5 + v7];

        CCachePageManager::sm_sVertexList[iVertexGroup + 2].sx = v10;
        CCachePageManager::sm_sVertexList[iVertexGroup + 2].sy = v3 + v9;
        CCachePageManager::sm_sVertexList[iVertexGroup + 2].tu = CCachePageManager::sm_fTextureCoordTable[v8];
        CCachePageManager::sm_sVertexList[iVertexGroup + 2].tv = CCachePageManager::sm_fTextureCoordTable[v5 + v7];

        CCachePageManager::sm_sVertexList[iVertexGroup + 3].sx = v10;
        CCachePageManager::sm_sVertexList[iVertexGroup + 3].sy = v9;
        CCachePageManager::sm_sVertexList[iVertexGroup + 3].tu = CCachePageManager::sm_fTextureCoordTable[v8];
        CCachePageManager::sm_sVertexList[iVertexGroup + 3].tv = CCachePageManager::sm_fTextureCoordTable[v7];

        CCachePageManager::sm_sVertexList[iVertexGroup + 4].sx = v4 + v10;
        CCachePageManager::sm_sVertexList[iVertexGroup + 4].sy = v9;
        CCachePageManager::sm_sVertexList[iVertexGroup + 4].tu = CCachePageManager::sm_fTextureCoordTable[v6 + v8];
        CCachePageManager::sm_sVertexList[iVertexGroup + 4].tv = CCachePageManager::sm_fTextureCoordTable[v7];

        CCachePageManager::sm_sVertexList[iVertexGroup + 5].sx = v4 + v10;
        CCachePageManager::sm_sVertexList[iVertexGroup + 5].sy = v3 + v9;
        CCachePageManager::sm_sVertexList[iVertexGroup + 5].tu = CCachePageManager::sm_fTextureCoordTable[v6 + v8];
        CCachePageManager::sm_sVertexList[iVertexGroup + 5].tv = CCachePageManager::sm_fTextureCoordTable[v5 + v7];

        CCachePageManager::sm_sVertexList[iVertexGroup + 5].color =
            CCachePageManager::sm_sVertexList[iVertexGroup + 4].color =
                CCachePageManager::sm_sVertexList[iVertexGroup + 3].color =
                    CCachePageManager::sm_sVertexList[iVertexGroup + 2].color =
                        CCachePageManager::sm_sVertexList[iVertexGroup + 1].color =
                            CCachePageManager::sm_sVertexList[iVertexGroup].color = this->m_iShading[i];
    }

    _rResult = this->m_pRenderDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 452, CCachePageManager::sm_sVertexList, 6 * this->m_iNumberOfObjects, 0);
    if(_rResult != 0)
        return 0;

    CCachePageManager::ReleaseData();
    return 1;
}

// address=[0x2f88440]
// Decompiled from bool __thiscall CCachePageManager::ShowPageContent(CCachePageManager *this, int *a2)
bool CCachePageManager::ShowPageContent(long &_rResult) {

    CBlitFX *BlitStructPtr; // eax
    HRESULT v4;             // [esp+0h] [ebp-28h]

    _rResult = this->m_pRenderDevice->SetTexture(0, this->m_pVideoTexture);
    if(_rResult != 0)
        return false;

    if(this->m_bSoureSurfaceIsLocked != 0) {
        _rResult = CCachePageManager::UnlockSourceSurface();
        if(_rResult != 0)
            return false;
    }

    this->m_sUploadRectangle.right = 511;
    this->m_sUploadRectangle.bottom = 511;
    if(this->m_pSystemTexture != nullptr) {
        _rResult = this->m_pRenderDevice->Load(this->m_pVideoTexture, &this->m_sDestinationPoint, this->m_pSystemTexture, &this->m_sUploadRectangle, 0);
        if(_rResult == DDERR_SURFACELOST) {
            this->m_pVideoTexture->Restore();
            CCachePageManager::ReleaseData();
            return false;
        }

        if(_rResult != 0)
            return false;
    }
    CCachePageManager::sm_sVertexList[0].sx = (float)300;
    CCachePageManager::sm_sVertexList[0].sy = (float)100;
    CCachePageManager::sm_sVertexList[0].tu = CCachePageManager::sm_fTextureCoordTable[0];
    CCachePageManager::sm_sVertexList[0].tv = CCachePageManager::sm_fTextureCoordTable[0];

    CCachePageManager::sm_sVertexList[1].sx = (float)812;
    CCachePageManager::sm_sVertexList[1].sy = (float)612;
    CCachePageManager::sm_sVertexList[1].tu = CCachePageManager::sm_fTextureCoordTable[511];
    CCachePageManager::sm_sVertexList[1].tv = CCachePageManager::sm_fTextureCoordTable[511];

    CCachePageManager::sm_sVertexList[2].sx = (float)300;
    CCachePageManager::sm_sVertexList[2].sy = (float)612;
    CCachePageManager::sm_sVertexList[2].tu = CCachePageManager::sm_fTextureCoordTable[0];
    CCachePageManager::sm_sVertexList[2].tv = CCachePageManager::sm_fTextureCoordTable[511];

    CCachePageManager::sm_sVertexList[3].sx = (float)300;
    CCachePageManager::sm_sVertexList[3].sy = (float)100;
    CCachePageManager::sm_sVertexList[3].tu = CCachePageManager::sm_fTextureCoordTable[0];
    CCachePageManager::sm_sVertexList[3].tv = CCachePageManager::sm_fTextureCoordTable[0];

    CCachePageManager::sm_sVertexList[4].sx = (float)812;
    CCachePageManager::sm_sVertexList[4].sy = (float)100;
    CCachePageManager::sm_sVertexList[4].tu = CCachePageManager::sm_fTextureCoordTable[511];
    CCachePageManager::sm_sVertexList[4].tv = CCachePageManager::sm_fTextureCoordTable[0];

    CCachePageManager::sm_sVertexList[5].sx = (float)812;
    CCachePageManager::sm_sVertexList[5].sy = (float)612;
    CCachePageManager::sm_sVertexList[5].tu = CCachePageManager::sm_fTextureCoordTable[511];
    CCachePageManager::sm_sVertexList[5].tv = CCachePageManager::sm_fTextureCoordTable[511];

    CCachePageManager::sm_sVertexList[5].color = 0xFFFFFF;
    CCachePageManager::sm_sVertexList[4].color = 0xFFFFFF;
    CCachePageManager::sm_sVertexList[3].color = 0xFFFFFF;
    CCachePageManager::sm_sVertexList[2].color = 0xFFFFFF;
    CCachePageManager::sm_sVertexList[1].color = 0xFFFFFF;
    CCachePageManager::sm_sVertexList[0].color = 0xFFFFFF;

    _rResult = this->m_pRenderDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 452, CCachePageManager::sm_sVertexList, 6, 0);
    if(this->m_pSystemTexture != nullptr) {
        do {
            do {
                v4 = this->m_pSystemTexture->Blt(nullptr, nullptr, nullptr, 1536, s_cBlitFx.GetBlitStructPtr());
            } while(v4 == DDERR_WASSTILLDRAWING);
        } while(v4 == DDERR_SURFACEBUSY);
    }
    return _rResult == 0;
}

// address=[0x2f888b0]
// Decompiled from CCachePageManager *__thiscall CCachePageManager::ReleaseData(CCachePageManager *this)
void CCachePageManager::ReleaseData(void) {
    this->m_iUploadWidth = 0;
    this->m_iUploadHeight = 0;
    this->m_iCurrentY = 0;
    this->m_iCurrentX = 0;
    this->m_iNumberOfObjects = 0;
}

// address=[0x2f888f0]
// Decompiled from HRESULT __thiscall CCachePageManager::RenderCacheObject(CCachePageManager *this, int _iIndex, float _fX, float _fY, int _iShading, int _iFlags, int _iShift, bool a8)
long CCachePageManager::RenderCacheObject(int _iIndex, float _fX, float _fY, int _iShading, int _iFlags, int _iShift, bool a8) {

    int v15 = 0; // [esp+48h] [ebp-30h]

    float iScaledWidth;  // [esp+54h] [ebp-24h]
    float iScaledHeight; // [esp+5Ch] [ebp-1Ch]

    if(!CCachePageManager::IsData()) {
        return 0;
    }
    HRESULT hResult = this->m_pRenderDevice->SetTexture(0, this->m_pVideoTexture);
    if(hResult != 0) {
        return hResult;
    }
    if(this->m_bVideoSurfaceIsLocked != 0) {
        hResult = CCachePageManager::UnlockVideoSurface();
        if(hResult != 0) {
            return hResult;
        }
    }
    int iX = this->m_sRectangleList[_iIndex].left + 1;
    int iY = this->m_sRectangleList[_iIndex].top + 1;
    int iWidth = this->m_sRectangleList[_iIndex].right - iX - 1;
    int iHeight = this->m_sRectangleList[_iIndex].bottom - iY - 1;
    if(a8) {
        iScaledWidth = (float)iWidth - 1.0;
        iScaledHeight = (float)iHeight - 1.0;
        iWidth = this->m_sRectangleList[_iIndex].right - iX - 2;
        iHeight = this->m_sRectangleList[_iIndex].bottom - iY - 2;
    } else {
        iScaledWidth = (float)iWidth * CCachePageManager::sm_fZoomFactor;
        iScaledHeight = (float)iHeight * CCachePageManager::sm_fZoomFactor;
    }
    if((_iFlags & 7) != 0) {
        iScaledWidth = iScaledWidth * 0.5;
        iScaledHeight = iScaledHeight * 0.5;
    }
    float v26 = _fY;
    if(_iShift != 0) {
        if(_iShift == 255) {
            return 0;
        }
        v15 = _iShift * iHeight / 256;
        float v12 = (float)v15 * CCachePageManager::sm_fZoomFactor;
        iY += v15;
        iHeight -= v15;
        v26 = _fY + v12;
        iScaledHeight = iScaledHeight - v12;
    }
    float v23 = (float)s_iObjectOffsetX + _fX;
    float v27 = (float)s_iObjectOffsetY + v26;
    CCachePageManager::sm_sVertexList[0].sx = v23;
    CCachePageManager::sm_sVertexList[0].sy = v27;
    CCachePageManager::sm_sVertexList[0].tu = CCachePageManager::sm_fTextureCoordTable[iX];
    CCachePageManager::sm_sVertexList[0].tv = CCachePageManager::sm_fTextureCoordTable[iY];

    CCachePageManager::sm_sVertexList[1].sx = v23 + iScaledWidth;
    CCachePageManager::sm_sVertexList[1].sy = v27 + iScaledHeight;
    CCachePageManager::sm_sVertexList[1].tu = CCachePageManager::sm_fTextureCoordTable[iWidth + iX];
    CCachePageManager::sm_sVertexList[1].tv = CCachePageManager::sm_fTextureCoordTable[iHeight + iY];

    CCachePageManager::sm_sVertexList[2].sx = v23;
    CCachePageManager::sm_sVertexList[2].sy = v27 + iScaledHeight;
    CCachePageManager::sm_sVertexList[2].tu = CCachePageManager::sm_fTextureCoordTable[iX];
    CCachePageManager::sm_sVertexList[2].tv = CCachePageManager::sm_fTextureCoordTable[iHeight + iY];

    CCachePageManager::sm_sVertexList[3].sx = v23;
    CCachePageManager::sm_sVertexList[3].sy = v27;
    CCachePageManager::sm_sVertexList[3].tu = CCachePageManager::sm_fTextureCoordTable[iX];
    CCachePageManager::sm_sVertexList[3].tv = CCachePageManager::sm_fTextureCoordTable[iY];

    CCachePageManager::sm_sVertexList[4].sx = v23 + iScaledWidth;
    CCachePageManager::sm_sVertexList[4].sy = v27;
    CCachePageManager::sm_sVertexList[4].tu = CCachePageManager::sm_fTextureCoordTable[iWidth + iX];
    CCachePageManager::sm_sVertexList[4].tv = CCachePageManager::sm_fTextureCoordTable[iY];

    CCachePageManager::sm_sVertexList[5].sx = v23 + iScaledWidth;
    CCachePageManager::sm_sVertexList[5].sy = v27 + iScaledHeight;
    CCachePageManager::sm_sVertexList[5].tu = CCachePageManager::sm_fTextureCoordTable[iWidth + iX];
    CCachePageManager::sm_sVertexList[5].tv = CCachePageManager::sm_fTextureCoordTable[iHeight + iY];

    CCachePageManager::sm_sVertexList[0].color = _iShading;
    CCachePageManager::sm_sVertexList[1].color = _iShading;
    CCachePageManager::sm_sVertexList[2].color = _iShading;
    CCachePageManager::sm_sVertexList[3].color = _iShading;
    CCachePageManager::sm_sVertexList[4].color = _iShading;
    CCachePageManager::sm_sVertexList[5].color = _iShading;

    if((_iFlags & 0x20) != 0) {
        BBSupportTracePrintF(0, "GFX ENGINE: ObjectTrace: %d ----------------------", _iIndex);
        BBSupportTracePrintF(0, "GFX ENGINE: X: %d Y: %d", iX, iY);
        BBSupportTracePrintF(0, "GFX ENGINE: Width: %d Height: %d ScaledWidth: %f ScaledHeight: %f", iWidth, iHeight, iScaledWidth, iScaledHeight);
        BBSupportTracePrintF(0, "GFX ENGINE: Vertex 0 : %f, %f, %f, %f", CCachePageManager::sm_sVertexList[0].sx, CCachePageManager::sm_sVertexList[0].sy, CCachePageManager::sm_sVertexList[0].tu, CCachePageManager::sm_sVertexList[0].tv);
        BBSupportTracePrintF(0, "GFX ENGINE: Vertex 1 : %f, %f, %f, %f", CCachePageManager::sm_sVertexList[1].sx, CCachePageManager::sm_sVertexList[1].sy, CCachePageManager::sm_sVertexList[1].tu, CCachePageManager::sm_sVertexList[1].tv);
        BBSupportTracePrintF(0, "GFX ENGINE: Vertex 2 : %f, %f, %f, %f", CCachePageManager::sm_sVertexList[2].sx, CCachePageManager::sm_sVertexList[2].sy, CCachePageManager::sm_sVertexList[2].tu, CCachePageManager::sm_sVertexList[2].tv);
        BBSupportTracePrintF(0, "GFX ENGINE: Vertex 3 : %f, %f, %f, %f", CCachePageManager::sm_sVertexList[3].sx, CCachePageManager::sm_sVertexList[3].sy, CCachePageManager::sm_sVertexList[3].tu, CCachePageManager::sm_sVertexList[3].tv);
        BBSupportTracePrintF(0, "GFX ENGINE: Vertex 4 : %f, %f, %f, %f", CCachePageManager::sm_sVertexList[4].sx, CCachePageManager::sm_sVertexList[4].sy, CCachePageManager::sm_sVertexList[4].tu, CCachePageManager::sm_sVertexList[4].tv);
        BBSupportTracePrintF(0, "GFX ENGINE: Vertex 5 : %f, %f, %f, %f", CCachePageManager::sm_sVertexList[5].sx, CCachePageManager::sm_sVertexList[5].sy, CCachePageManager::sm_sVertexList[5].tu, CCachePageManager::sm_sVertexList[5].tv);
    }
    if(_iShift == 0)
        return this->m_pRenderDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 452, CCachePageManager::sm_sVertexList, 6, 0);

    int iShiftCount = iWidth / 12;
    int v13 = 6;
    if(v15 < 6) {
        v13 = v15;
    }
    float v9 = (float)v13 * CCachePageManager::sm_fZoomFactor;

    int iVertexCount = 3 * iShiftCount;
    float v11 = 12.0 * CCachePageManager::sm_fZoomFactor;

    int iShiftedVertexStart = 6;
    while(--iShiftCount >= 0) {
        CCachePageManager::sm_sVertexList[iShiftedVertexStart].sx = v23;
        CCachePageManager::sm_sVertexList[iShiftedVertexStart].sy = v27;
        CCachePageManager::sm_sVertexList[iShiftedVertexStart].tu = CCachePageManager::sm_fTextureCoordTable[iX];
        CCachePageManager::sm_sVertexList[iShiftedVertexStart].tv = CCachePageManager::sm_fTextureCoordTable[iY];

        CCachePageManager::sm_sVertexList[iShiftedVertexStart + 1].sx = (float)(v11 * 0.5) + v23;
        CCachePageManager::sm_sVertexList[iShiftedVertexStart + 1].sy = v27 - v9;
        CCachePageManager::sm_sVertexList[iShiftedVertexStart + 1].tu = CCachePageManager::sm_fTextureCoordTable[iX + 6];
        CCachePageManager::sm_sVertexList[iShiftedVertexStart + 1].tv = CCachePageManager::sm_fTextureCoordTable[iY - v13];

        CCachePageManager::sm_sVertexList[iShiftedVertexStart + 2].sx = v23 + v11;
        CCachePageManager::sm_sVertexList[iShiftedVertexStart + 2].sy = v27;
        CCachePageManager::sm_sVertexList[iShiftedVertexStart + 2].tu = CCachePageManager::sm_fTextureCoordTable[iX + 12];
        CCachePageManager::sm_sVertexList[iShiftedVertexStart + 2].tv = CCachePageManager::sm_fTextureCoordTable[iY];

        CCachePageManager::sm_sVertexList[iShiftedVertexStart + 0].color = _iShading;
        CCachePageManager::sm_sVertexList[iShiftedVertexStart + 1].color = _iShading;
        CCachePageManager::sm_sVertexList[iShiftedVertexStart + 2].color = _iShading;
        iX += 12;
        v23 = (float)(12.0 * CCachePageManager::sm_fZoomFactor) + v23;
        iShiftedVertexStart += 3;
    }
    return this->m_pRenderDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 452, CCachePageManager::sm_sVertexList, iVertexCount + 6, 0);
}

// address=[0x2f89350]
// Decompiled from HRESULT __thiscall CCachePageManager::LockSourceSurface(CCachePageManager *this, int *_rPitch, ushort **_rRender)
long CCachePageManager::LockSourceSurface(int &_rPitch, unsigned short *&_rSurface) {
    if(this->m_bSoureSurfaceIsLocked != 0) {
        _rPitch = this->m_iPitch;
        _rSurface = static_cast<unsigned short *>(this->m_pRenderAdress);
        return 0;
    }

    HRESULT hResult = this->m_pSystemTexture->Lock(nullptr, &s_cSurfaceDescription.m_sSurfaceDescription, 33, nullptr);
    if(hResult != 0) {
        return hResult;
    }
    this->m_iPitch = s_cSurfaceDescription.m_sSurfaceDescription.lPitch;
    _rPitch = s_cSurfaceDescription.m_sSurfaceDescription.lPitch;
    this->m_pRenderAdress = s_cSurfaceDescription.m_sSurfaceDescription.lpSurface;
    _rSurface = static_cast<unsigned short *>(this->m_pRenderAdress);
    this->m_bSoureSurfaceIsLocked = 1;
    return hResult;
}

// address=[0x2f89400]
// Decompiled from HRESULT __thiscall CCachePageManager::LockVideoSurface(CCachePageManager *this, int *a2, unsigned __int16 **a3)
long CCachePageManager::LockVideoSurface(int &_rPitch, unsigned short *&_rSurface) {
    if(this->m_bVideoSurfaceIsLocked != 0) {
        _rPitch = this->m_iPitch;
        _rSurface = static_cast<unsigned short *>(this->m_pRenderAdress);
        return 0;
    } else {
        HRESULT hResult = this->m_pVideoTexture->Lock(nullptr, &s_cSurfaceDescription.m_sSurfaceDescription, 33, nullptr);
        if(hResult != 0) {
            return hResult;
        }
        this->m_iPitch = s_cSurfaceDescription.m_sSurfaceDescription.lPitch;
        _rPitch = s_cSurfaceDescription.m_sSurfaceDescription.lPitch;
        this->m_pRenderAdress = s_cSurfaceDescription.m_sSurfaceDescription.lpSurface;
        _rSurface = static_cast<unsigned __int16 *>(this->m_pRenderAdress);
        this->m_bVideoSurfaceIsLocked = 1;
        return hResult;
    }
}

// address=[0x2f894b0]
// Decompiled from HRESULT __thiscall CCachePageManager::UnlockSourceSurface(CCachePageManager *this)
long CCachePageManager::UnlockSourceSurface(void) {
    if(this->m_bSoureSurfaceIsLocked == 0) {
        return 0;
    }
    HRESULT hResult = this->m_pSystemTexture->Unlock(nullptr);
    this->m_bSoureSurfaceIsLocked = 0;
    return hResult;
}

// address=[0x2f89500]
// Decompiled from HRESULT __thiscall CCachePageManager::UnlockVideoSurface(CCachePageManager *this)
long CCachePageManager::UnlockVideoSurface(void) {
    if(this->m_bVideoSurfaceIsLocked == 0) {
        return 0;
    }
    HRESULT hResult = this->m_pVideoTexture->Unlock(nullptr);
    this->m_bVideoSurfaceIsLocked = 0;
    return hResult;
}

// address=[0x2f8a420]
// Decompiled from bool __thiscall CCachePageManager::IsData(CCachePageManager *this)
bool CCachePageManager::IsData(void) {

    return this->m_iNumberOfObjects > 0;
}

// address=[0x2f99770]
// Decompiled from int __thiscall CCachePageManager::GetLastCacheObjectNr(CCachePageManager *this)
int CCachePageManager::GetLastCacheObjectNr(void) {

    return this->m_iNumberOfObjects - 1;
}

// address=[0x46c1698]
// [Decompilation failed for static float CCachePageManager::sm_fZoomFactor]

// address=[0x46c16a0]
// [Decompilation failed for static float * CCachePageManager::sm_fTextureCoordTable]
