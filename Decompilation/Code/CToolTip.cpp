#include "CToolTip.h"

// Definitions for class CToolTip

// address=[0x2f9fd80]
// Decompiled from size_t __thiscall CToolTip::GetCurrentLengthOfTooltip(CToolTip *this)
int  CToolTip::GetCurrentLengthOfTooltip(void) {
  
  return j___mbstrlen((const char *)this + 8);
}


// address=[0x2f9fda0]
// Decompiled from char *__thiscall CToolTip::GetTooltipStringPtr(CToolTip *this)
char *  CToolTip::GetTooltipStringPtr(void) {
  
  return (char *)this + 8;
}


// address=[0x2f9fdc0]
// Decompiled from char __thiscall CToolTip::IsLocked(CToolTip *this)
bool  CToolTip::IsLocked(void) {
  
  return *((_BYTE *)this + 337);
}


// address=[0x2f9fde0]
// Decompiled from char __thiscall CToolTip::IsOpen(CToolTip *this)
bool  CToolTip::IsOpen(void) {
  
  return *((_BYTE *)this + 336);
}


// address=[0x2f9fe00]
// Decompiled from CToolTip *__thiscall CToolTip::Lock(CToolTip *this)
void  CToolTip::Lock(void) {
  
  CToolTip *result; // eax

  result = this;
  *((_BYTE *)this + 337) = 1;
  return result;
}


// address=[0x2f9fe50]
// Decompiled from CToolTip *__thiscall CToolTip::SetSourceDialogSurfaceID(CToolTip *this, int a2)
void  CToolTip::SetSourceDialogSurfaceID(int) {
  
  CToolTip *result; // eax

  result = this;
  *((_DWORD *)this + 1) = a2;
  return result;
}


// address=[0x2f9fe70]
// Decompiled from CToolTip *__thiscall CToolTip::Unlock(CToolTip *this)
void  CToolTip::Unlock(void) {
  
  CToolTip *result; // eax

  result = this;
  *((_BYTE *)this + 337) = 0;
  return result;
}


// address=[0x2fa0fa0]
// Decompiled from int __thiscall CToolTip::GetSourceDialogSurfaceID(CToolTip *this)
int  CToolTip::GetSourceDialogSurfaceID(void) {
  
  return *((_DWORD *)this + 1);
}


// address=[0x2fa2f70]
// Decompiled from CToolTip *__thiscall CToolTip::SetEnableStatus(CToolTip *this, bool a2)
void  CToolTip::SetEnableStatus(bool) {
  
  CToolTip *result; // eax

  result = this;
  *((_BYTE *)this + 338) = a2;
  return result;
}


// address=[0x2fa3070]
// Decompiled from CToolTip *__thiscall CToolTip::CToolTip(CToolTip *this)
 CToolTip::CToolTip(void) {
  
  memset((char *)this + 8, 0, 0x12Cu);
  *(_DWORD *)this = 10;
  *((_BYTE *)this + 332) = 1;
  *((_BYTE *)this + 337) = 0;
  *((_BYTE *)this + 336) = 0;
  *((_BYTE *)this + 338) = 1;
  *((_DWORD *)this + 1) = -1;
  return this;
}


// address=[0x2fa30d0]
// Decompiled from char *__thiscall CToolTip::SetTooltipText(char *this, char *Str)
void  CToolTip::SetTooltipText(char const *) {
  
  char *result; // eax
  int Count; // [esp+0h] [ebp-8h]

  Count = j__strlen(Str);
  if ( Count >= CToolTip::GetMaxLengthOfTooltip((CToolTip *)this) - 1 )
    Count = CToolTip::GetMaxLengthOfTooltip((CToolTip *)this) - 1;
  result = j__strncpy(this + 8, Str, Count);
  this[Count + 8] = 0;
  return result;
}


// address=[0x2fa3130]
// Decompiled from char __thiscall CToolTip::OpenTooltip(CToolTip *this, int a2, int a3)
bool  CToolTip::OpenTooltip(int,int) {
  
  CToolTip *v4; // eax
  struct tagRECT v5; // [esp-10h] [ebp-80h]
  int v6; // [esp+0h] [ebp-70h] BYREF
  __int16 cx; // [esp+4h] [ebp-6Ch]
  __int16 cy; // [esp+6h] [ebp-6Ah]
  char v9; // [esp+18h] [ebp-58h]
  char v10; // [esp+1Ah] [ebp-56h]
  char v11; // [esp+1Bh] [ebp-55h]
  char v12; // [esp+1Eh] [ebp-52h]
  char v13; // [esp+20h] [ebp-50h]
  char v14; // [esp+23h] [ebp-4Dh]
  int v15; // [esp+24h] [ebp-4Ch]
  int v16; // [esp+28h] [ebp-48h]
  unsigned int v17; // [esp+2Ch] [ebp-44h] BYREF
  unsigned __int16 *v18; // [esp+30h] [ebp-40h]
  int v19; // [esp+34h] [ebp-3Ch]
  int OutputHeight; // [esp+38h] [ebp-38h]
  int v21; // [esp+3Ch] [ebp-34h]
  int v22; // [esp+40h] [ebp-30h]
  int OutputWidth; // [esp+44h] [ebp-2Ch]
  HDC hdc; // [esp+48h] [ebp-28h] BYREF
  struct tagSIZE psizl; // [esp+4Ch] [ebp-24h] BYREF
  char v26; // [esp+57h] [ebp-19h]
  int v28; // [esp+5Ch] [ebp-14h]
  int v29; // [esp+60h] [ebp-10h]
  int v30; // [esp+64h] [ebp-Ch]
  int v31; // [esp+68h] [ebp-8h]

  if ( !*((_BYTE *)this + 338) )
    return 1;
  if ( *((_BYTE *)this + 336) )
    CToolTip::CloseTooltip(this);
  if ( !g_pGfxEngine )
    return 0;
  if ( !*((_BYTE *)this + 8) )
    return 0;
  CalcTextSize(8, (const unsigned __int8 *)this + 8, &psizl, 0, -1);
  v15 = psizl.cx + 4;
  v16 = psizl.cy + 4;
  v4 = this;
  *((_DWORD *)this + 77) = psizl.cx + 4;
  *((_DWORD *)v4 + 78) = v16;
  *((_DWORD *)this + 79) = a2;
  *((_DWORD *)this + 80) = a3 + 18;
  *((_DWORD *)this + 81) = *((_DWORD *)this + 77) + *((_DWORD *)this + 79);
  *((_DWORD *)this + 82) = *((_DWORD *)this + 78) + *((_DWORD *)this + 80);
  OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
  OutputHeight = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
  if ( *((_DWORD *)this + 81) > OutputWidth )
  {
    v22 = *((_DWORD *)this + 81) - OutputWidth;
    *((_DWORD *)this + 81) -= v22;
    *((_DWORD *)this + 79) -= v22;
  }
  if ( *((int *)this + 79) < 0 )
  {
    v21 = abs(*((_DWORD *)this + 79));
    *((_DWORD *)this + 81) += v21;
    *((_DWORD *)this + 79) += v21;
  }
  if ( *((_DWORD *)this + 82) > OutputHeight )
  {
    v19 = *((_DWORD *)this + 82) - OutputHeight;
    *((_DWORD *)this + 80) -= v19;
    *((_DWORD *)this + 82) -= v19;
  }
  if ( IGfxEngine::CreateGuiSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)this, (CToolTip *)((char *)this + 308)) == -1 )
  {
    BBSupportTracePrintF(0, "GUI ENGINE: Cannot create tooltip surface!");
    return 0;
  }
  else
  {
    v26 = IGfxEngine::SolidColorFillGuiSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)this, 0, 0, 0xFFu);
    if ( v26 )
    {
      v29 = 0;
      v28 = 0;
      v30 = psizl.cx + 3;
      v31 = psizl.cy + 3;
      *(_QWORD *)&v5.left = 0LL;
      v5.right = psizl.cx + 3;
      v5.bottom = psizl.cy + 3;
      v26 = IGfxEngine::SolidColorFillGuiSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)this, 255, 0xFFu, 180, v5);
      if ( v26 )
      {
        v14 = 1;
        v10 = 8;
        v6 = 131074;
        v13 = 4;
        v9 = 14;
        cx = psizl.cx;
        cy = psizl.cy;
        v12 = 0;
        v11 = 0;
        v18 = IGfxEngine::BeginWriteToSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)this, &v17);
        if ( v18 )
        {
          FastRectangle(v18, v17, 0, 0, psizl.cx + 3, psizl.cy + 3, 0);
          IGfxEngine::EndWriteToSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)this);
          if ( IGfxEngine::GetGuiSurfaceDC((IGfxEngine *)g_pGfxEngine, *(_DWORD *)this, &hdc) )
          {
            SetBkMode(hdc, 1);
            DrawControlText(hdc, (int)&v6);
            IGfxEngine::ReleaseGuiSurfaceDC((IGfxEngine *)g_pGfxEngine, *(_DWORD *)this, hdc);
            if ( IGfxEngine::SetVisibilityOfGuiSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)this, 1) )
            {
              *((_BYTE *)this + 336) = 1;
              return 1;
            }
            else
            {
              BBSupportTracePrintF(0, "GUI ENGINE: Error while set tooltip visible!");
              return 0;
            }
          }
          else
          {
            BBSupportTracePrintF(0, "GUI ENGINE: Cannot render text into tooltip surface!");
            return 0;
          }
        }
        else
        {
          BBSupportTracePrintF(0, "GUI ENGINE: Cannot lock tooltip surface!");
          return 0;
        }
      }
      else
      {
        BBSupportTracePrintF(0, "GUI ENGINE: Cannot set tooltip surface!");
        return 0;
      }
    }
    else
    {
      BBSupportTracePrintF(0, "GUI ENGINE: Cannot clear tooltip surface!");
      return 0;
    }
  }
}


// address=[0x2fa3560]
// Decompiled from char __thiscall CToolTip::CloseTooltip(CToolTip *this)
bool  CToolTip::CloseTooltip(void) {
  
  if ( !*((_BYTE *)this + 336) )
    return 0;
  if ( !g_pGfxEngine )
    return 0;
  IGfxEngine::SetVisibilityOfGuiSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)this, 0);
  if ( IGfxEngine::DestroyGuiSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)this) )
  {
    *((_BYTE *)this + 336) = 0;
    return 1;
  }
  else
  {
    BBSupportTracePrintF(0, "GUI ENGINE: Cannot delete tooltip surface!");
    return 0;
  }
}


// address=[0x2fa3fb0]
// Decompiled from bool __thiscall CToolTip::~CToolTip(CToolTip *this)
 CToolTip::~CToolTip(void) {
  
  return CToolTip::CloseTooltip(this);
}


// address=[0x2fa4020]
// Decompiled from int __thiscall CToolTip::GetMaxLengthOfTooltip(CToolTip *this)
int  CToolTip::GetMaxLengthOfTooltip(void) {
  
  return 300;
}


