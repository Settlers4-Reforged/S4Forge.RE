#if FALSE
#include "CToolTip.h"

// Definitions for class CToolTip

// address=[0x2f9fd80]
// Decompiled from size_t __thiscall CToolTip::GetCurrentLengthOfTooltip(CToolTip *this)
int  CToolTip::GetCurrentLengthOfTooltip(void) {
  
  return j___mbstrlen(this->m_sText);
}


// address=[0x2f9fda0]
// Decompiled from char *__thiscall CToolTip::GetTooltipStringPtr(CToolTip *this)
char *  CToolTip::GetTooltipStringPtr(void) {
  
  return this->m_sText;
}


// address=[0x2f9fdc0]
// Decompiled from bool __thiscall CToolTip::IsLocked(CToolTip *this)
bool  CToolTip::IsLocked(void) {
  
  return this->m_bLocked;
}


// address=[0x2f9fde0]
// Decompiled from bool __thiscall CToolTip::IsOpen(CToolTip *this)
bool  CToolTip::IsOpen(void) {
  
  return this->m_bOpen;
}


// address=[0x2f9fe00]
// Decompiled from void __thiscall CToolTip::Lock(CToolTip *this)
void  CToolTip::Lock(void) {
  
  this->m_bLocked = 1;
}


// address=[0x2f9fe50]
// Decompiled from void __thiscall CToolTip::SetSourceDialogSurfaceID(CToolTip *this, int a2)
void  CToolTip::SetSourceDialogSurfaceID(int a2) {
  
  this->m_iSourceDialogSurfaceId = a2;
}


// address=[0x2f9fe70]
// Decompiled from void __thiscall CToolTip::Unlock(CToolTip *this)
void  CToolTip::Unlock(void) {
  
  this->m_bLocked = 0;
}


// address=[0x2fa0fa0]
// Decompiled from int __thiscall CToolTip::GetSourceDialogSurfaceID(CToolTip *this)
int  CToolTip::GetSourceDialogSurfaceID(void) {
  
  return this->m_iSourceDialogSurfaceId;
}


// address=[0x2fa2f70]
// Decompiled from void __thiscall CToolTip::SetEnableStatus(CToolTip *this, bool a2)
void  CToolTip::SetEnableStatus(bool a2) {
  
  this->m_bEnableStatus = a2;
}


// address=[0x2fa3070]
// Decompiled from CToolTip *__thiscall CToolTip::CToolTip(CToolTip *this)
 CToolTip::CToolTip(void) {
  
  memset(this->m_sText, 0, sizeof(this->m_sText));
  this->m_iSurfaceType = 10;
  this->m_sSurfaceDescription.m_bDirty = 1;
  this->m_bLocked = 0;
  this->m_bOpen = 0;
  this->m_bEnableStatus = 1;
  this->m_iSourceDialogSurfaceId = -1;
  return this;
}


// address=[0x2fa30d0]
// Decompiled from void __thiscall CToolTip::SetTooltipText(CToolTip *this, const char *Str)
void  CToolTip::SetTooltipText(char const * Str) {
  
  int Count; // [esp+0h] [ebp-8h]

  Count = strlen(Str);
  if ( Count >= CToolTip::GetMaxLengthOfTooltip(this) - 1 )
  {
    Count = CToolTip::GetMaxLengthOfTooltip(this) - 1;
  }
  j__strncpy(this->m_sText, Str, Count);
  this->m_sText[Count] = 0;
}


// address=[0x2fa3130]
// Decompiled from char __thiscall CToolTip::OpenTooltip(CToolTip *this, LONG a2, int a3)
bool  CToolTip::OpenTooltip(int a2, int a3) {
  
  CToolTip *v4; // eax
  struct tagRECT v5; // [esp-10h] [ebp-80h]
  struct SGuiControl v6; // [esp+0h] [ebp-70h] BYREF
  int v7; // [esp+24h] [ebp-4Ch]
  int v8; // [esp+28h] [ebp-48h]
  int v9; // [esp+2Ch] [ebp-44h] BYREF
  unsigned __int16 *v10; // [esp+30h] [ebp-40h]
  int v11; // [esp+34h] [ebp-3Ch]
  int OutputHeight; // [esp+38h] [ebp-38h]
  int v13; // [esp+3Ch] [ebp-34h]
  int v14; // [esp+40h] [ebp-30h]
  int OutputWidth; // [esp+44h] [ebp-2Ch]
  HDC hdc; // [esp+48h] [ebp-28h] BYREF
  struct tagSIZE psizl; // [esp+4Ch] [ebp-24h] BYREF
  char v18; // [esp+57h] [ebp-19h]
  int v20; // [esp+5Ch] [ebp-14h]
  int v21; // [esp+60h] [ebp-10h]
  int v22; // [esp+64h] [ebp-Ch]
  int v23; // [esp+68h] [ebp-8h]

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
  CalcTextSize(8, this->m_sText, &psizl, 0, -1);
  v7 = psizl.cx + 4;
  v8 = psizl.cy + 4;
  v4 = this;
  this->m_sSurfaceDescription.m_iWidth = psizl.cx + 4;
  v4->m_sSurfaceDescription.m_iHeight = v8;
  this->m_sSurfaceDescription.m_sDestinationRect.left = a2;
  this->m_sSurfaceDescription.m_sDestinationRect.top = a3 + 18;
  this->m_sSurfaceDescription.m_sDestinationRect.right = this->m_sSurfaceDescription.m_iWidth + this->m_sSurfaceDescription.m_sDestinationRect.left;
  this->m_sSurfaceDescription.m_sDestinationRect.bottom = this->m_sSurfaceDescription.m_iHeight + this->m_sSurfaceDescription.m_sDestinationRect.top;
  OutputWidth = IGfxEngine::GetOutputWidth(g_pGfxEngine);
  OutputHeight = IGfxEngine::GetOutputHeight(g_pGfxEngine);
  if ( this->m_sSurfaceDescription.m_sDestinationRect.right > OutputWidth )
  {
    v14 = this->m_sSurfaceDescription.m_sDestinationRect.right - OutputWidth;
    this->m_sSurfaceDescription.m_sDestinationRect.right -= v14;
    this->m_sSurfaceDescription.m_sDestinationRect.left -= v14;
  }
  if ( this->m_sSurfaceDescription.m_sDestinationRect.left < 0 )
  {
    v13 = abs(this->m_sSurfaceDescription.m_sDestinationRect.left);
    this->m_sSurfaceDescription.m_sDestinationRect.right += v13;
    this->m_sSurfaceDescription.m_sDestinationRect.left += v13;
  }
  if ( this->m_sSurfaceDescription.m_sDestinationRect.bottom > OutputHeight )
  {
    v11 = this->m_sSurfaceDescription.m_sDestinationRect.bottom - OutputHeight;
    this->m_sSurfaceDescription.m_sDestinationRect.top -= v11;
    this->m_sSurfaceDescription.m_sDestinationRect.bottom -= v11;
  }
  if ( IGfxEngine::CreateGuiSurface(g_pGfxEngine, this->m_iSurfaceType, &this->m_sSurfaceDescription) == -1 )
  {
    BBSupportTracePrintF(0, "GUI ENGINE: Cannot create tooltip surface!");
    return 0;
  }
  else
  {
    v18 = IGfxEngine::SolidColorFillGuiSurface(g_pGfxEngine, this->m_iSurfaceType, 0, 0, 0xFFu);
    if ( !v18 )
    {
      BBSupportTracePrintF(0, "GUI ENGINE: Cannot clear tooltip surface!");
      return 0;
    }
    else
    {
      v21 = 0;
      v20 = 0;
      v22 = psizl.cx + 3;
      v23 = psizl.cy + 3;
      *(_QWORD *)&v5.left = 0LL;
      v5.right = psizl.cx + 3;
      v5.bottom = psizl.cy + 3;
      v18 = IGfxEngine::SolidColorFillGuiSurface(g_pGfxEngine, this->m_iSurfaceType, 255, 0xFFu, 180, v5);
      if ( !v18 )
      {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot set tooltip surface!");
        return 0;
      }
      else
      {
        v6.m_bDirty = 1;
        v6.m_iFontTemplate = 8;
        *(_DWORD *)&v6.m_iX = 0x20002;
        v6.m_iTextFormat = 4;
        v6.m_iControlType = GUI_CNTRL_TOOLTIP;
        v6.m_iWidth = psizl.cx;
        v6.m_iHeight = psizl.cy;
        v6.m_iParam2 = 0;
        v6.m_iEffects = 0;
        v10 = IGfxEngine::BeginWriteToSurface(g_pGfxEngine, this->m_iSurfaceType, (unsigned int *)&v9);
        if ( !v10 )
        {
          BBSupportTracePrintF(0, "GUI ENGINE: Cannot lock tooltip surface!");
          return 0;
        }
        else
        {
          FastRectangle(v10, v9, 0, 0, psizl.cx + 3, psizl.cy + 3, 0);
          IGfxEngine::EndWriteToSurface(g_pGfxEngine, this->m_iSurfaceType);
          if ( !IGfxEngine::GetGuiSurfaceDC(g_pGfxEngine, this->m_iSurfaceType, &hdc) )
          {
            BBSupportTracePrintF(0, "GUI ENGINE: Cannot render text into tooltip surface!");
            return 0;
          }
          else
          {
            SetBkMode(hdc, 1);
            DrawControlText(hdc, &v6);
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
  }
}


// address=[0x2fa3560]
// Decompiled from char __thiscall CToolTip::CloseTooltip(CToolTip *this)
bool  CToolTip::CloseTooltip(void) {
  
  if ( !this->m_bOpen )
  {
    return 0;
  }
  if ( !g_pGfxEngine )
  {
    return 0;
  }
  IGfxEngine::SetVisibilityOfGuiSurface(g_pGfxEngine, this->m_iSurfaceType, 0);
  if ( IGfxEngine::DestroyGuiSurface(g_pGfxEngine, this->m_iSurfaceType) )
  {
    this->m_bOpen = 0;
    return 1;
  }
  else
  {
    BBSupportTracePrintF(0, "GUI ENGINE: Cannot delete tooltip surface!");
    return 0;
  }
}


// address=[0x2fa3fb0]
// Decompiled from char __thiscall CToolTip::~CToolTip(CToolTip *this)
 CToolTip::~CToolTip(void) {
  
  return CToolTip::CloseTooltip(this);
}


// address=[0x2fa4020]
// Decompiled from int __thiscall CToolTip::GetMaxLengthOfTooltip(CToolTip *this)
int  CToolTip::GetMaxLengthOfTooltip(void) {
  
  return 300;
}


#endif // Already implemented
