#include "CFixCursor.h"

#include "./D3D/CSurface.h"
#include "CBB/CBBSupport.h"
#include "D3D/CInterfaceD3D.h"
#include "Framework.h"

// Definitions for class CFixCursor

// address=[0x2f62430]
// Decompiled from CFixCursor *__thiscall CFixCursor::CFixCursor(CFixCursor *this)
CFixCursor::CFixCursor(void) {
    this->m_bVisible = 0;
    this->m_sRect.right = 0;
    this->m_sRect.left = 0;
    this->m_sRect.top = 0;
    this->m_sRect.bottom = 0;
    this->m_sOffset.right = 0;
    this->m_sOffset.left = 0;
    this->m_sOffset.top = 0;
    this->m_sOffset.bottom = 0;
    this->m_pSurface = nullptr;
}

// address=[0x2f624a0]
// Decompiled from int __thiscall CFixCursor::SetSurfacePtr(CFixCursor *this, unsigned __int16 a2, CSurface *a3, WORD a4)
void CFixCursor::SetSurfacePtr(unsigned short a2, class CSurface *a3, unsigned short a4) {

    unsigned int iPitch;   // [esp+0h] [ebp-2Ch] BYREF
    COLORREF Pixel;        // [esp+4h] [ebp-28h]
    HGDIOBJ hCursorObject; // [esp+8h] [ebp-24h]
    int y;                 // [esp+10h] [ebp-1Ch]
    int hResult;           // [esp+14h] [ebp-18h]
    int x;                 // [esp+1Ch] [ebp-10h]
    HGDIOBJ hCursorBitmap; // [esp+20h] [ebp-Ch]
    HDC hDC;               // [esp+24h] [ebp-8h]
    WORD v15;              // [esp+28h] [ebp-4h]

    this->m_pSurface = a3;
    hCursorBitmap = LoadBitmapA(g_hInstance, reinterpret_cast<LPCSTR>(a2));
    if(hCursorBitmap == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Cannot open resource bitmap!");
        return;
    }

    hDC = CreateCompatibleDC(nullptr);
    if(hDC == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Cannot open DC for move cursor!");
        DeleteObject(hCursorBitmap);
        return;
    }

    hCursorObject = SelectObject(hDC, hCursorBitmap);
    if(hCursorObject == nullptr) {
        BBSupportTracePrintF(1, "GFX ENGINE: Cannot open select bitmap in move cursor dc!");
        DeleteDC(hDC);
        DeleteObject(hCursorBitmap);
        return;
    }

    void *pData;
    hResult = this->m_pSurface->Lock(iPitch, pData, 1u);
    if(hResult != 0) {
        WriteError(hResult, "LockCursorSurface");
        SelectObject(hDC, hCursorObject);
        DeleteDC(hDC);
        DeleteObject(hCursorBitmap);
        return;
    }

    WORD *pSurfaceData = reinterpret_cast<WORD *>(pData);
    for(y = 0;
        y < 32;
        ++y) {
        for(x = 0;
            x < 32;
            ++x) {
            Pixel = GetPixel(hDC, x, y);
            v15 = a4;
            if((unsigned __int8)Pixel == 255) {
                v15 = -1;
            } else if((_BYTE)Pixel == 0) {
                v15 = 0;
            }
            pSurfaceData[x] = v15;
        }
        pSurfaceData += iPitch >> 1;
    }

    hResult = this->m_pSurface->Unlock();
    if(hResult != 0) {
        WriteError(hResult, "UnlockCursorSurface");
    }

    SelectObject(hDC, hCursorObject);
    DeleteDC(hDC);
    DeleteObject(hCursorBitmap);
}

// address=[0x2f626a0]
// Decompiled from void __thiscall CFixCursor::SetFixCursor(CFixCursor *this, int a2, int a3, bool a4)
void CFixCursor::SetFixCursor(int a2, int a3, bool a4) {

    int v4; // eax
    int v5; // [esp+0h] [ebp-8h]
    int v6; // [esp+0h] [ebp-8h]
    int v7; // [esp+0h] [ebp-8h]

    this->m_bVisible = a4;
    this->m_sRect.left = a2 - 8;
    this->m_sRect.top = a3 - 8;
    this->m_sRect.right = a2 + 24;
    this->m_sRect.bottom = a3 + 24;
    this->m_sOffset.left = 0;
    this->m_sOffset.top = 0;
    this->m_sOffset.right = 32;
    this->m_sOffset.bottom = 32;
    if(this->m_sRect.bottom > GfxEngineSetup.sRenderSetup.m_uHeight) {
        v5 = this->m_sRect.bottom - GfxEngineSetup.sRenderSetup.m_uHeight;
        this->m_sRect.bottom -= v5;
        this->m_sOffset.bottom -= v5;
    }
    if(this->m_sRect.right > GfxEngineSetup.sRenderSetup.m_uWidth) {
        v6 = this->m_sRect.right - GfxEngineSetup.sRenderSetup.m_uWidth;
        this->m_sRect.right -= v6;
        this->m_sOffset.right -= v6;
    }
    if(this->m_sRect.top < 0) {
        v7 = abs(this->m_sRect.top);
        this->m_sRect.top += v7;
        this->m_sOffset.top += v7;
    }
    if(this->m_sRect.left < 0) {
        v4 = abs(this->m_sRect.left);
        this->m_sRect.left += v4;
        this->m_sOffset.left += v4;
    }
}

// address=[0x2f62800]
// Decompiled from HRESULT __thiscall CFixCursor::Show(CFixCursor *this, CSurface *a2)
long CFixCursor::Show(class CSurface *_pSurface) {
    if(CFixCursor::IsVisible() == 0) {
        return 0;
    }
    if(this->m_pSurface != nullptr && _pSurface != nullptr) {
        return _pSurface->Blt(&this->m_sRect, this->m_pSurface, &this->m_sOffset, 0x8000u, nullptr);
    }
    return 0;
}

// address=[0x2f699a0]
// Decompiled from unsigned __int8 __thiscall CFixCursor::IsVisible(CFixCursor *this)
bool CFixCursor::IsVisible(void) {
    return this->m_bVisible;
}
