#include "CToolTipExt.h"

#include "CBB/CBBSupport.h"
#include "GuiEngine/GuiEngine.h"
#include "GuiEngine/GuiMenu.h"
#include "GuiEngine/SGuiControl.h"

// Definitions for class CToolTipExt

// address=[0x2f9fe20]
// Decompiled from void __thiscall CToolTipExt::ResetActiveText(CToolTipExt *this)
void CToolTipExt::ResetActiveText(void) {
    this->m_sText[0] = 0;
    CToolTipExt::UpdateText();
}

// address=[0x2fa35e0]
// Decompiled from CToolTipExt *__thiscall CToolTipExt::CToolTipExt(CToolTipExt *this)
CToolTipExt::CToolTipExt(void) : CToolTip() {
    memset(this->m_sText, 0, sizeof(this->m_sText));
    this->m_iSurfaceType = 7;
    this->m_sSurfaceDescription.m_uU18 = 1;
    this->m_iContainerId = -1;
    this->m_bLocked = 0;
    this->m_bOpen = 0;
}

// address=[0x2fa3640]
// Decompiled from char __thiscall CToolTipExt::OpenTooltip(CToolTipExt *this)
bool CToolTipExt::OpenTooltip(void) {

    // ecx
    SGuiControl sControl;               // [esp+0h] [ebp-60h] BYREF
    unsigned int uStride;               // [esp+30h] [ebp-30h] BYREF
    HDC hdc;                            // [esp+4Ch] [ebp-14h] BYREF
    GUI_MENU_DIALOG_HEADER *pContainer; // [esp+54h] [ebp-Ch]

    if(!this->m_bEnableStatus) {
        return 1;
    }
    if(this->m_bOpen) {
        CToolTip::CloseTooltip();
    }
    if(!g_pGfxEngine) {
        return 0;
    }
    if(!this->m_sText[0]) {
        return 0;
    }
    if(this->m_iContainerId < 0) {
        for(int i = g_pFileHeader->m_iContainerCount - 1; i >= 0; --i) {
            pContainer = GetContainerPtr(i);
            if((pContainer->m_iTransparency & 7) == 7) {
                this->m_iContainerId = i;
                break;
            }
        }
    }
    if(this->m_iContainerId == -1) {
        return 0;
    }
    pContainer = GetContainerPtr(this->m_iContainerId);
    int v4 = pContainer->m_iWidth;
    int v5 = pContainer->m_iHeight;
    CToolTipExt *v2 = this;
    this->m_sSurfaceDescription.m_iWidth = v4;
    v2->m_sSurfaceDescription.m_iHeight = v5;
    this->m_sSurfaceDescription.m_sDestinationRect.left = pContainer->m_iY;
    this->m_sSurfaceDescription.m_sDestinationRect.top = pContainer->m_iWidth;
    this->m_sSurfaceDescription.m_sDestinationRect.right = pContainer->m_iHeight + pContainer->m_iY;
    this->m_sSurfaceDescription.m_sDestinationRect.bottom = pContainer->m_iMainTexture + pContainer->m_iWidth;
    int OutputWidth = g_pGfxEngine->GetOutputWidth();
    int OutputHeight = g_pGfxEngine->GetOutputHeight();
    if(this->m_sSurfaceDescription.m_sDestinationRect.right > OutputWidth) {
        int iWidth = this->m_sSurfaceDescription.m_sDestinationRect.right - OutputWidth;
        this->m_sSurfaceDescription.m_sDestinationRect.right -= iWidth;
        this->m_sSurfaceDescription.m_sDestinationRect.left -= iWidth;
    }
    if(this->m_sSurfaceDescription.m_sDestinationRect.left < 0) {
        int iLeft = abs(this->m_sSurfaceDescription.m_sDestinationRect.left);
        this->m_sSurfaceDescription.m_sDestinationRect.right += iLeft;
        this->m_sSurfaceDescription.m_sDestinationRect.left += iLeft;
    }
    if(this->m_sSurfaceDescription.m_sDestinationRect.bottom > OutputHeight) {
        int iHeight = this->m_sSurfaceDescription.m_sDestinationRect.bottom - OutputHeight;
        this->m_sSurfaceDescription.m_sDestinationRect.top -= iHeight;
        this->m_sSurfaceDescription.m_sDestinationRect.bottom -= iHeight;
    }
    if(g_pGfxEngine->CreateGuiSurface(this->m_iSurfaceType, &this->m_sSurfaceDescription) == -1) {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot create tooltip surface!");
        return 0;
    }

    if(!g_pGfxEngine->SolidColorFillGuiSurface(this->m_iSurfaceType, 0, 0, 0)) {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot clear tooltip surface!");
        return 0;
    }

    sControl.m_bDirty = 1;
    sControl.m_iTextStyle = 6;
    sControl.m_iX = 0x2;
    sControl.m_iY = 0x2;
    sControl.m_iTextFormat = 6;
    sControl.m_iControlType = GUI_CNTRL_TOOLTIP_EXTRA;
    sControl.m_iWidth = pContainer->m_iHeight;
    sControl.m_iHeight = pContainer->m_iMainTexture;
    sControl.m_iParam = 0;
    sControl.m_iEffects = 0;
    unsigned __int16 *pSurface = g_pGfxEngine->BeginWriteToSurface(this->m_iSurfaceType, uStride);
    if(!pSurface) {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot lock tooltip surface!");
        return 0;
    } else {
        FastRaster(pSurface, uStride, 0, 0, pContainer->m_iHeight, pContainer->m_iMainTexture, 31);
        g_pGfxEngine->EndWriteToSurface(this->m_iSurfaceType);
        sControl.m_iX += 2;
        sControl.m_iWidth -= 4;
        if(!g_pGfxEngine->GetGuiSurfaceDC(this->m_iSurfaceType, &hdc)) {
            BBSupportTracePrintF(0, "GUI ENGINE: Cannot render text into tooltip surface!");
            return 0;
        } else {
            SetBkMode(hdc, 1);
            DrawControlText(hdc, &sControl);
            g_pGfxEngine->ReleaseGuiSurfaceDC(this->m_iSurfaceType, hdc);
            if(!g_pGfxEngine->SetVisibilityOfGuiSurface(this->m_iSurfaceType, 1)) {
                BBSupportTracePrintF(0, "GUI ENGINE: Error while set tooltip visible!");
                return 0;
            } else {
                this->m_bOpen = 1;
                return 1;
            }
        }
    }
}

// address=[0x2fa3a70]
// Decompiled from char __thiscall CToolTipExt::UpdateText(CToolTipExt *this)
bool CToolTipExt::UpdateText(void) {

    SGuiControl sControl; // [esp+0h] [ebp-3Ch] BYREF
    unsigned int uStride; // [esp+24h] [ebp-18h] BYREF
                          // [esp+28h] [ebp-14h]
    HDC hdc;              // [esp+2Ch] [ebp-10h] BYREF
                          // [esp+30h] [ebp-Ch]

    if(!this->m_bEnableStatus) {
        return 1;
    }
    if(!this->m_bOpen) {
        return 0;
    }
    if(!g_pGfxEngine) {
        return 0;
    }
    if(this->m_iContainerId < 0) {
        return 0;
    }
    GUI_MENU_DIALOG_HEADER *pControl = GetContainerPtr(this->m_iContainerId);
    if(!g_pGfxEngine->SolidColorFillGuiSurface(this->m_iSurfaceType, 0, 0, 0)) {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot clear tooltip surface!");
        return 0;
    }

    sControl.m_bDirty = 1;
    sControl.m_iTextStyle = 6;
    sControl.m_iX = 0x2;
    sControl.m_iY = 0x2;
    sControl.m_iTextFormat = 6;
    sControl.m_iControlType = GUI_CNTRL_TOOLTIP_EXTRA;
    sControl.m_iWidth = pControl->m_iWidth;
    sControl.m_iHeight = pControl->m_iHeight;
    sControl.m_iParam = 0;
    sControl.m_iEffects = 0;
    unsigned __int16 *pSurface = g_pGfxEngine->BeginWriteToSurface(this->m_iSurfaceType, uStride);
    if(!pSurface) {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot lock tooltip surface!");
        return 0;
    }
    FastRaster(pSurface, uStride, 0, 0, pControl->m_iHeight, pControl->m_iMainTexture, 31);
    g_pGfxEngine->EndWriteToSurface(this->m_iSurfaceType);
    if(!this->m_sText[0]) {
        return 0;
    }
    if(!g_pGfxEngine->GetGuiSurfaceDC(this->m_iSurfaceType, &hdc)) {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot render text into tooltip surface!");
        return 0;
    }
    SetBkMode(hdc, 1);
    DrawControlText(hdc, &sControl);
    g_pGfxEngine->ReleaseGuiSurfaceDC(this->m_iSurfaceType, hdc);
    if(!g_pGfxEngine->SetVisibilityOfGuiSurface(this->m_iSurfaceType, 1)) {
        BBSupportTracePrintF(0, "GUI ENGINE: Error while set tooltip visible!");
        return 0;
    }

    return 1;
}

// address=[0x2fa4000]
// Decompiled from bool __thiscall CToolTipExt::~CToolTipExt(CToolTipExt *this)
CToolTipExt::~CToolTipExt(void) = default;
