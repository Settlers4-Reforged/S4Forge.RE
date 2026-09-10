#if FALSE
#include "CToolTipExt.h"

// Definitions for class CToolTipExt

// address=[0x2f9fe20]
// Decompiled from void __thiscall CToolTipExt::ResetActiveText(CToolTipExt *this)
void  CToolTipExt::ResetActiveText(void) {
  
  this->m_sText[0] = 0;
  CToolTipExt::UpdateText(this);
}


// address=[0x2fa35e0]
// Decompiled from CToolTipExt *__thiscall CToolTipExt::CToolTipExt(CToolTipExt *this)
 CToolTipExt::CToolTipExt(void) {
  
  CToolTip::CToolTip(this);
  memset(this->m_sText, 0, sizeof(this->m_sText));
  this->m_iSurfaceType = 7;
  this->m_sSurfaceDescription.m_bDirty = 1;
  this->m_iContainerId = -1;
  this->m_bLocked = 0;
  this->m_bOpen = 0;
  return this;
}


// address=[0x2fa3640]
// Decompiled from char __thiscall CToolTipExt::OpenTooltip(CToolTipExt *this)
bool  CToolTipExt::OpenTooltip(void) {
  
  CToolTipExt *v2; // ecx
  struct SGuiControl sControl; // [esp+0h] [ebp-60h] BYREF
  int m_iHeight; // [esp+24h] [ebp-3Ch]
  int m_iMainTexture; // [esp+28h] [ebp-38h]
  int v6; // [esp+2Ch] [ebp-34h]
  int v7; // [esp+30h] [ebp-30h] BYREF
  unsigned __int16 *v8; // [esp+34h] [ebp-2Ch]
  int iHeight; // [esp+38h] [ebp-28h]
  int OutputHeight; // [esp+3Ch] [ebp-24h]
  int iLeft; // [esp+40h] [ebp-20h]
  int iWidth; // [esp+44h] [ebp-1Ch]
  int OutputWidth; // [esp+48h] [ebp-18h]
  HDC hdc; // [esp+4Ch] [ebp-14h] BYREF
  int i; // [esp+50h] [ebp-10h]
  GUI_MENU_DIALOG_HEADER *v16; // [esp+54h] [ebp-Ch]

  if ( !this->m_bEnableStatus )
  {
    return 1;
  }
  if ( this->m_bOpen )
  {
    CToolTip::CloseTooltip(this);
  }
  if ( !g_pGfxEngine )
  {
    return 0;
  }
  if ( !this->m_sText[0] )
  {
    return 0;
  }
  if ( this->m_iContainerId < 0 )
  {
    for ( i = g_pFileHeader->m_iContainerCount - 1;
          i >= 0;
          --i )
    {
      v16 = (GUI_MENU_DIALOG_HEADER *)((char *)g_pFileHeader + g_pFileHeader->m_iContainerMap[i]);
      v6 = 7;
      if ( (v16->m_iTransparency & 7) == 7 )
      {
        this->m_iContainerId = i;
        break;
      }
    }
  }
  if ( this->m_iContainerId == -1 )
  {
    return 0;
  }
  v16 = (GUI_MENU_DIALOG_HEADER *)((char *)g_pFileHeader + g_pFileHeader->m_iContainerMap[this->m_iContainerId]);
  m_iHeight = v16->m_iWidth;
  m_iMainTexture = v16->m_iHeight;
  v2 = this;
  this->m_sSurfaceDescription.m_iWidth = m_iHeight;
  v2->m_sSurfaceDescription.m_iHeight = m_iMainTexture;
  this->m_sSurfaceDescription.m_sDestinationRect.left = v16->m_iX;
  this->m_sSurfaceDescription.m_sDestinationRect.top = v16->m_iY;
  this->m_sSurfaceDescription.m_sDestinationRect.right = v16->m_iWidth + v16->m_iX;
  this->m_sSurfaceDescription.m_sDestinationRect.bottom = v16->m_iHeight + v16->m_iY;
  OutputWidth = IGfxEngine::GetOutputWidth(g_pGfxEngine);
  OutputHeight = IGfxEngine::GetOutputHeight(g_pGfxEngine);
  if ( this->m_sSurfaceDescription.m_sDestinationRect.right > OutputWidth )
  {
    iWidth = this->m_sSurfaceDescription.m_sDestinationRect.right - OutputWidth;
    this->m_sSurfaceDescription.m_sDestinationRect.right -= iWidth;
    this->m_sSurfaceDescription.m_sDestinationRect.left -= iWidth;
  }
  if ( this->m_sSurfaceDescription.m_sDestinationRect.left < 0 )
  {
    iLeft = abs(this->m_sSurfaceDescription.m_sDestinationRect.left);
    this->m_sSurfaceDescription.m_sDestinationRect.right += iLeft;
    this->m_sSurfaceDescription.m_sDestinationRect.left += iLeft;
  }
  if ( this->m_sSurfaceDescription.m_sDestinationRect.bottom > OutputHeight )
  {
    iHeight = this->m_sSurfaceDescription.m_sDestinationRect.bottom - OutputHeight;
    this->m_sSurfaceDescription.m_sDestinationRect.top -= iHeight;
    this->m_sSurfaceDescription.m_sDestinationRect.bottom -= iHeight;
  }
  if ( IGfxEngine::CreateGuiSurface(g_pGfxEngine, this->m_iSurfaceType, &this->m_sSurfaceDescription) == -1 )
  {
    BBSupportTracePrintF(0, "GUI ENGINE: Cannot create tooltip surface!");
    return 0;
  }
  else if ( !IGfxEngine::SolidColorFillGuiSurface(g_pGfxEngine, this->m_iSurfaceType, 0, 0, 0) )
  {
    BBSupportTracePrintF(0, "GUI ENGINE: Cannot clear tooltip surface!");
    return 0;
  }
  else
  {
    sControl.m_bDirty = 1;
    sControl.m_iFontTemplate = 6;
    *(_DWORD *)&sControl.m_iX = 0x20002;
    sControl.m_iTextFormat = 6;
    sControl.m_iControlType = GUI_CNTRL_TOOLTIP_EXTRA;
    sControl.m_iWidth = v16->m_iWidth;
    sControl.m_iHeight = v16->m_iHeight;
    sControl.m_iParam2 = 0;
    sControl.m_iEffects = 0;
    v8 = IGfxEngine::BeginWriteToSurface(g_pGfxEngine, this->m_iSurfaceType, (unsigned int *)&v7);
    if ( !v8 )
    {
      BBSupportTracePrintF(0, "GUI ENGINE: Cannot lock tooltip surface!");
      return 0;
    }
    else
    {
      FastRaster(v8, v7, 0, 0, v16->m_iWidth, v16->m_iHeight, 31);
      IGfxEngine::EndWriteToSurface(g_pGfxEngine, this->m_iSurfaceType);
      sControl.m_iX += 2;
      sControl.m_iWidth -= 4;
      if ( !IGfxEngine::GetGuiSurfaceDC(g_pGfxEngine, this->m_iSurfaceType, &hdc) )
      {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot render text into tooltip surface!");
        return 0;
      }
      else
      {
        SetBkMode(hdc, 1);
        DrawControlText(hdc, &sControl);
        IGfxEngine::ReleaseGuiSurfaceDC(g_pGfxEngine, this->m_iSurfaceType, hdc);
        if ( !IGfxEngine::SetVisibilityOfGuiSurface(g_pGfxEngine, this->m_iSurfaceType, 1) )
        {
          BBSupportTracePrintF(0, "GUI ENGINE: Error while set tooltip visible!");
          return 0;
        }
        else
        {
          this->m_bOpen = 1;
          return 1;
        }
      }
    }
  }
}


// address=[0x2fa3a70]
// Decompiled from char __thiscall CToolTipExt::UpdateText(CToolTipExt *this)
bool  CToolTipExt::UpdateText(void) {
  
  struct SGuiControl v2; // [esp+0h] [ebp-3Ch] BYREF
  int v3; // [esp+24h] [ebp-18h] BYREF
  unsigned __int16 *v4; // [esp+28h] [ebp-14h]
  HDC hdc; // [esp+2Ch] [ebp-10h] BYREF
  GUI_MENU_DIALOG_HEADER *pContainer; // [esp+30h] [ebp-Ch]

  if ( !this->m_bEnableStatus )
  {
    return 1;
  }
  if ( !this->m_bOpen )
  {
    return 0;
  }
  if ( !g_pGfxEngine )
  {
    return 0;
  }
  if ( this->m_iContainerId < 0 )
  {
    return 0;
  }
  pContainer = (GUI_MENU_DIALOG_HEADER *)((char *)g_pFileHeader + g_pFileHeader->m_iContainerMap[this->m_iContainerId]);
  if ( !IGfxEngine::SolidColorFillGuiSurface(g_pGfxEngine, this->m_iSurfaceType, 0, 0, 0) )
  {
    BBSupportTracePrintF(0, "GUI ENGINE: Cannot clear tooltip surface!");
    return 0;
  }
  else
  {
    v2.m_bDirty = 1;
    v2.m_iFontTemplate = 6;
    *(_DWORD *)&v2.m_iX = 131074;
    v2.m_iTextFormat = 6;
    v2.m_iControlType = GUI_CNTRL_TOOLTIP_EXTRA;
    v2.m_iWidth = pContainer->m_iWidth;
    v2.m_iHeight = pContainer->m_iHeight;
    v2.m_iParam2 = 0;
    v2.m_iEffects = 0;
    v4 = IGfxEngine::BeginWriteToSurface(g_pGfxEngine, this->m_iSurfaceType, (unsigned int *)&v3);
    if ( !v4 )
    {
      BBSupportTracePrintF(0, "GUI ENGINE: Cannot lock tooltip surface!");
      return 0;
    }
    else
    {
      FastRaster(v4, v3, 0, 0, pContainer->m_iWidth, pContainer->m_iHeight, 31);
      IGfxEngine::EndWriteToSurface(g_pGfxEngine, this->m_iSurfaceType);
      if ( !this->m_sText[0] )
      {
        return 0;
      }
      else if ( !IGfxEngine::GetGuiSurfaceDC(g_pGfxEngine, this->m_iSurfaceType, &hdc) )
      {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot render text into tooltip surface!");
        return 0;
      }
      else
      {
        SetBkMode(hdc, 1);
        DrawControlText(hdc, &v2);
        IGfxEngine::ReleaseGuiSurfaceDC(g_pGfxEngine, this->m_iSurfaceType, hdc);
        if ( !IGfxEngine::SetVisibilityOfGuiSurface(g_pGfxEngine, this->m_iSurfaceType, 1) )
        {
          BBSupportTracePrintF(0, "GUI ENGINE: Error while set tooltip visible!");
          return 0;
        }
        else
        {
          return 1;
        }
      }
    }
  }
}


// address=[0x2fa4000]
// Decompiled from bool __thiscall CToolTipExt::~CToolTipExt(CToolTipExt *this)
 CToolTipExt::~CToolTipExt(void) {
  
  return CToolTip::~CToolTip(this);
}


#endif // Already implemented
