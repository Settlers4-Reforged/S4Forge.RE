#include "CToolTip.h"

#include "CBB/CBBSupport.h"
#include "GuiEngine/GuiEngine.h"
#include "GuiEngine/SGuiControl.h"

// Definitions for class CToolTip

// address=[0x2f9fd80]
// Decompiled from size_t __thiscall CToolTip::GetCurrentLengthOfTooltip(CToolTip *this)
int CToolTip::GetCurrentLengthOfTooltip(void) {

    return _mbstrlen(this->m_sText);
}

// address=[0x2f9fda0]
// Decompiled from char *__thiscall CToolTip::GetTooltipStringPtr(CToolTip *this)
char *CToolTip::GetTooltipStringPtr(void) {

    return this->m_sText;
}

// address=[0x2f9fdc0]
// Decompiled from bool __thiscall CToolTip::IsLocked(CToolTip *this)
bool CToolTip::IsLocked(void) {

    return this->m_bLocked;
}

// address=[0x2f9fde0]
// Decompiled from bool __thiscall CToolTip::IsOpen(CToolTip *this)
bool CToolTip::IsOpen(void) {

    return this->m_bOpen;
}

// address=[0x2f9fe00]
// Decompiled from void __thiscall CToolTip::Lock(CToolTip *this)
void CToolTip::Lock(void) {

    this->m_bLocked = 1;
}

// address=[0x2f9fe50]
// Decompiled from void __thiscall CToolTip::SetSourceDialogSurfaceID(CToolTip *this, int a2)
void CToolTip::SetSourceDialogSurfaceID(int a2) {

    this->m_iSourceDialogSurfaceId = a2;
}

// address=[0x2f9fe70]
// Decompiled from void __thiscall CToolTip::Unlock(CToolTip *this)
void CToolTip::Unlock(void) {

    this->m_bLocked = 0;
}

// address=[0x2fa0fa0]
// Decompiled from int __thiscall CToolTip::GetSourceDialogSurfaceID(CToolTip *this)
int CToolTip::GetSourceDialogSurfaceID(void) {

    return this->m_iSourceDialogSurfaceId;
}

// address=[0x2fa2f70]
// Decompiled from void __thiscall CToolTip::SetEnableStatus(CToolTip *this, bool a2)
void CToolTip::SetEnableStatus(bool a2) {

    this->m_bEnableStatus = a2;
}

// address=[0x2fa3070]
// Decompiled from CToolTip *__thiscall CToolTip::CToolTip(CToolTip *this)
CToolTip::CToolTip(void) {
    memset(this->m_sText, 0, sizeof(this->m_sText));
    this->m_iSurfaceType = 10;
    this->m_sSurfaceDescription.m_uU18 = 1;
    this->m_bLocked = 0;
    this->m_bOpen = 0;
    this->m_bEnableStatus = 1;
    this->m_iSourceDialogSurfaceId = -1;
}

// address=[0x2fa30d0]
// Decompiled from void __thiscall CToolTip::SetTooltipText(CToolTip *this, char *Str)
void CToolTip::SetTooltipText(char const *Str) {
    int iLen = strlen(Str);
    if(iLen >= this->GetMaxLengthOfTooltip() - 1) {
        iLen = this->GetMaxLengthOfTooltip() - 1;
    }
    strncpy(this->m_sText, Str, iLen);
    this->m_sText[iLen] = 0;
}

// address=[0x2fa3130]
// Decompiled from char __thiscall CToolTip::OpenTooltip(CToolTip *this, LONG a2, int a3)
bool CToolTip::OpenTooltip(int a2, int a3) {
    RECT sDestRect;       // [esp-10h] [ebp-80h]
    SGuiControl sControl; // [esp+0h] [ebp-70h] BYREF
    int v9;               // [esp+2Ch] [ebp-44h] BYREF
    HDC hdc;              // [esp+48h] [ebp-28h] BYREF
    struct tagSIZE psizl; // [esp+4Ch] [ebp-24h] BYREF
    if(!this->m_bEnableStatus) {
        return 1;
    }
    if(this->m_bOpen) {
        this->CloseTooltip();
    }
    if(!g_pGfxEngine) {
        return 0;
    }
    if(!this->m_sText[0]) {
        return 0;
    }
    CalcTextSize(8, this->m_sText, psizl, 0, -1);
    int v7 = psizl.cx + 4;
    int v8 = psizl.cy + 4;
    CToolTip *v4 = this;
    this->m_sSurfaceDescription.m_iWidth = psizl.cx + 4;
    v4->m_sSurfaceDescription.m_iHeight = v8;
    this->m_sSurfaceDescription.m_sDestinationRect.left = a2;
    this->m_sSurfaceDescription.m_sDestinationRect.top = a3 + 18;
    this->m_sSurfaceDescription.m_sDestinationRect.right = this->m_sSurfaceDescription.m_iWidth + this->m_sSurfaceDescription.m_sDestinationRect.left;
    this->m_sSurfaceDescription.m_sDestinationRect.bottom = this->m_sSurfaceDescription.m_iHeight + this->m_sSurfaceDescription.m_sDestinationRect.top;
    int OutputWidth = g_pGfxEngine->GetOutputWidth();
    int OutputHeight = g_pGfxEngine->GetOutputHeight();
    if(this->m_sSurfaceDescription.m_sDestinationRect.right > OutputWidth) {
        int v14 = this->m_sSurfaceDescription.m_sDestinationRect.right - OutputWidth;
        this->m_sSurfaceDescription.m_sDestinationRect.right -= v14;
        this->m_sSurfaceDescription.m_sDestinationRect.left -= v14;
    }
    if(this->m_sSurfaceDescription.m_sDestinationRect.left < 0) {
        int v13 = abs(this->m_sSurfaceDescription.m_sDestinationRect.left);
        this->m_sSurfaceDescription.m_sDestinationRect.right += v13;
        this->m_sSurfaceDescription.m_sDestinationRect.left += v13;
    }
    if(this->m_sSurfaceDescription.m_sDestinationRect.bottom > OutputHeight) {
        int v11 = this->m_sSurfaceDescription.m_sDestinationRect.bottom - OutputHeight;
        this->m_sSurfaceDescription.m_sDestinationRect.top -= v11;
        this->m_sSurfaceDescription.m_sDestinationRect.bottom -= v11;
    }
    if(g_pGfxEngine->CreateGuiSurface(this->m_iSurfaceType, &this->m_sSurfaceDescription) == -1) {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot create tooltip surface!");
        return 0;
    }
    char v18 = g_pGfxEngine->SolidColorFillGuiSurface(this->m_iSurfaceType, 0, 0, 0xFFu);
    if(!v18) {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot clear tooltip surface!");
        return 0;
    }

    int v21 = 0;
    int v20 = 0;
    int v22 = psizl.cx + 3;
    int v23 = psizl.cy + 3;
    sDestRect.left = 0;
    sDestRect.top = 0;
    sDestRect.right = psizl.cx + 3;
    sDestRect.bottom = psizl.cy + 3;
    v18 = g_pGfxEngine->SolidColorFillGuiSurface(this->m_iSurfaceType, 255, 0xFFu, 180, sDestRect);
    if(!v18) {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot set tooltip surface!");
        return 0;
    }

    sControl.m_bDirty = 1;
    sControl.m_iFontTemplate = 8;
    sControl.m_iX = 0x2;
    sControl.m_iY = 0x2;
    sControl.m_iTextFormat = 4;
    sControl.m_iControlType = GUI_CNTRL_TOOLTIP;
    sControl.m_iWidth = psizl.cx;
    sControl.m_iHeight = psizl.cy;
    sControl.m_iParam2 = 0;
    sControl.m_iEffects = 0;
    unsigned __int16 *v10 = g_pGfxEngine->BeginWriteToSurface(this->m_iSurfaceType, (unsigned int *)&v9);
    if(!v10) {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot lock tooltip surface!");
        return 0;
    }

    FastRectangle(v10, v9, 0, 0, psizl.cx + 3, psizl.cy + 3, 0);
    g_pGfxEngine->EndWriteToSurface(this->m_iSurfaceType);
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

    this->m_bOpen = 1;
    return 1;
}

// address=[0x2fa3560]
// Decompiled from char __thiscall CToolTip::CloseTooltip(CToolTip *this)
bool CToolTip::CloseTooltip(void) {
    if(!this->m_bOpen) {
        return 0;
    }
    if(!g_pGfxEngine) {
        return 0;
    }
    g_pGfxEngine->SetVisibilityOfGuiSurface(this->m_iSurfaceType, 0);
    if(!g_pGfxEngine->DestroyGuiSurface(this->m_iSurfaceType)) {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot delete tooltip surface!");
        return 0;
    }

    this->m_bOpen = 0;
    return 1;
}

// address=[0x2fa3fb0]
// Decompiled from char __thiscall CToolTip::~CToolTip(CToolTip *this)
CToolTip::~CToolTip(void) {
    this->CloseTooltip();
}

// address=[0x2fa4020]
// Decompiled from int __thiscall CToolTip::GetMaxLengthOfTooltip(CToolTip *this)
int CToolTip::GetMaxLengthOfTooltip(void) {
    return 300;
}
