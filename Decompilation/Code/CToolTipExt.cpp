#include "CToolTipExt.h"

// Definitions for class CToolTipExt

// address=[0x2f9fe20]
// Decompiled from char __thiscall CToolTipExt::ResetActiveText(CToolTipExt *this)
void  CToolTipExt::ResetActiveText(void) {
  
  *((_BYTE *)this + 8) = 0;
  return CToolTipExt::UpdateText(this);
}


// address=[0x2fa35e0]
// Decompiled from CToolTipExt *__thiscall CToolTipExt::CToolTipExt(CToolTipExt *this)
 CToolTipExt::CToolTipExt(void) {
  
  CToolTip::CToolTip(this);
  j__memset((char *)this + 8, 0, 0x12Cu);
  *(_DWORD *)this = 7;
  *((_BYTE *)this + 332) = 1;
  *((_DWORD *)this + 85) = -1;
  *((_BYTE *)this + 337) = 0;
  *((_BYTE *)this + 336) = 0;
  return this;
}


// address=[0x2fa3640]
// Decompiled from char __thiscall CToolTipExt::OpenTooltip(CToolTipExt *this)
bool  CToolTipExt::OpenTooltip(void) {
  
  CToolTip *v2; // ecx
  int v3; // [esp+0h] [ebp-60h] BYREF
  unsigned __int16 v4; // [esp+4h] [ebp-5Ch]
  unsigned __int16 v5; // [esp+6h] [ebp-5Ah]
  char v6; // [esp+18h] [ebp-48h]
  char v7; // [esp+1Ah] [ebp-46h]
  char v8; // [esp+1Bh] [ebp-45h]
  char v9; // [esp+1Eh] [ebp-42h]
  char v10; // [esp+20h] [ebp-40h]
  char v11; // [esp+23h] [ebp-3Dh]
  int v12; // [esp+24h] [ebp-3Ch]
  int v13; // [esp+28h] [ebp-38h]
  int v14; // [esp+2Ch] [ebp-34h]
  unsigned int v15; // [esp+30h] [ebp-30h] BYREF
  unsigned __int16 *v16; // [esp+34h] [ebp-2Ch]
  int v17; // [esp+38h] [ebp-28h]
  int OutputHeight; // [esp+3Ch] [ebp-24h]
  int v19; // [esp+40h] [ebp-20h]
  int v20; // [esp+44h] [ebp-1Ch]
  int OutputWidth; // [esp+48h] [ebp-18h]
  HDC hdc; // [esp+4Ch] [ebp-14h] BYREF
  int i; // [esp+50h] [ebp-10h]
  unsigned __int16 *v24; // [esp+54h] [ebp-Ch]
  CToolTip *v25; // [esp+58h] [ebp-8h]

  v25 = this;
  if ( !*((_BYTE *)this + 338) )
    return 1;
  if ( *((_BYTE *)v25 + 336) )
    CToolTip::CloseTooltip(v25);
  if ( !g_pGfxEngine )
    return 0;
  if ( !*((_BYTE *)v25 + 8) )
    return 0;
  if ( *((int *)v25 + 85) < 0 )
  {
    for ( i = *(_DWORD *)(g_pFileHeader + 4) - 1; i >= 0; --i )
    {
      v24 = (unsigned __int16 *)(*(_DWORD *)(g_pFileHeader + 4 * i + 16) + g_pFileHeader);
      v14 = 7;
      if ( (v24[7] & 7) == 7 )
      {
        *((_DWORD *)v25 + 85) = i;
        break;
      }
    }
  }
  if ( *((_DWORD *)v25 + 85) == -1 )
    return 0;
  v24 = (unsigned __int16 *)(*(_DWORD *)(g_pFileHeader + 4 * *((_DWORD *)v25 + 85) + 16) + g_pFileHeader);
  v12 = v24[3];
  v13 = v24[4];
  v2 = v25;
  *((_DWORD *)v25 + 77) = v12;
  *((_DWORD *)v2 + 78) = v13;
  *((_DWORD *)v25 + 79) = v24[1];
  *((_DWORD *)v25 + 80) = v24[2];
  *((_DWORD *)v25 + 81) = v24[3] + v24[1];
  *((_DWORD *)v25 + 82) = v24[4] + v24[2];
  OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
  OutputHeight = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
  if ( *((_DWORD *)v25 + 81) > OutputWidth )
  {
    v20 = *((_DWORD *)v25 + 81) - OutputWidth;
    *((_DWORD *)v25 + 81) -= v20;
    *((_DWORD *)v25 + 79) -= v20;
  }
  if ( *((int *)v25 + 79) < 0 )
  {
    v19 = abs(*((_DWORD *)v25 + 79));
    *((_DWORD *)v25 + 81) += v19;
    *((_DWORD *)v25 + 79) += v19;
  }
  if ( *((_DWORD *)v25 + 82) > OutputHeight )
  {
    v17 = *((_DWORD *)v25 + 82) - OutputHeight;
    *((_DWORD *)v25 + 80) -= v17;
    *((_DWORD *)v25 + 82) -= v17;
  }
  if ( IGfxEngine::CreateGuiSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)v25, (CToolTip *)((char *)v25 + 308)) == -1 )
  {
    BBSupportTracePrintF(0, "GUI ENGINE: Cannot create tooltip surface!");
    return 0;
  }
  else if ( IGfxEngine::SolidColorFillGuiSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)v25, 0, 0, 0) )
  {
    v11 = 1;
    v7 = 6;
    v3 = 131074;
    v10 = 6;
    v6 = 15;
    v4 = v24[3];
    v5 = v24[4];
    v9 = 0;
    v8 = 0;
    v16 = IGfxEngine::BeginWriteToSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)v25, &v15);
    if ( v16 )
    {
      FastRaster(v16, v15, 0, 0, v24[3], v24[4], 31);
      IGfxEngine::EndWriteToSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)v25);
      LOWORD(v3) = v3 + 2;
      v4 -= 4;
      if ( IGfxEngine::GetGuiSurfaceDC((IGfxEngine *)g_pGfxEngine, *(_DWORD *)v25, &hdc) )
      {
        SetBkMode(hdc, 1);
        DrawControlText(hdc, (int)&v3);
        IGfxEngine::ReleaseGuiSurfaceDC((IGfxEngine *)g_pGfxEngine, *(_DWORD *)v25, hdc);
        if ( IGfxEngine::SetVisibilityOfGuiSurface((IGfxEngine *)g_pGfxEngine, *(_DWORD *)v25, 1) )
        {
          *((_BYTE *)v25 + 336) = 1;
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
    BBSupportTracePrintF(0, "GUI ENGINE: Cannot clear tooltip surface!");
    return 0;
  }
}


// address=[0x2fa3a70]
// Decompiled from char __thiscall CToolTipExt::UpdateText(CToolTipExt *this)
bool  CToolTipExt::UpdateText(void) {
  
  int v2; // [esp+0h] [ebp-3Ch] BYREF
  __int16 v3; // [esp+4h] [ebp-38h]
  __int16 v4; // [esp+6h] [ebp-36h]
  char v5; // [esp+18h] [ebp-24h]
  char v6; // [esp+1Ah] [ebp-22h]
  char v7; // [esp+1Bh] [ebp-21h]
  char v8; // [esp+1Eh] [ebp-1Eh]
  char v9; // [esp+20h] [ebp-1Ch]
  char v10; // [esp+23h] [ebp-19h]
  unsigned int v11; // [esp+24h] [ebp-18h] BYREF
  unsigned __int16 *v12; // [esp+28h] [ebp-14h]
  HDC hdc; // [esp+2Ch] [ebp-10h] BYREF
  int v14; // [esp+30h] [ebp-Ch]
  unsigned int *v15; // [esp+34h] [ebp-8h]

  v15 = (unsigned int *)this;
  if ( !*((_BYTE *)this + 338) )
    return 1;
  if ( !*((_BYTE *)v15 + 336) )
    return 0;
  if ( !g_pGfxEngine )
    return 0;
  if ( (v15[85] & 0x80000000) != 0 )
    return 0;
  v14 = *(_DWORD *)(g_pFileHeader + 4 * v15[85] + 16) + g_pFileHeader;
  if ( IGfxEngine::SolidColorFillGuiSurface((IGfxEngine *)g_pGfxEngine, *v15, 0, 0, 0) )
  {
    v10 = 1;
    v6 = 6;
    v2 = 131074;
    v9 = 6;
    v5 = 15;
    v3 = *(_WORD *)(v14 + 6);
    v4 = *(_WORD *)(v14 + 8);
    v8 = 0;
    v7 = 0;
    v12 = IGfxEngine::BeginWriteToSurface((IGfxEngine *)g_pGfxEngine, *v15, &v11);
    if ( v12 )
    {
      FastRaster(v12, v11, 0, 0, *(unsigned __int16 *)(v14 + 6), *(unsigned __int16 *)(v14 + 8), 31);
      IGfxEngine::EndWriteToSurface((IGfxEngine *)g_pGfxEngine, *v15);
      if ( *((_BYTE *)v15 + 8) )
      {
        if ( IGfxEngine::GetGuiSurfaceDC((IGfxEngine *)g_pGfxEngine, *v15, &hdc) )
        {
          SetBkMode(hdc, 1);
          DrawControlText(hdc, (int)&v2);
          IGfxEngine::ReleaseGuiSurfaceDC((IGfxEngine *)g_pGfxEngine, *v15, hdc);
          if ( IGfxEngine::SetVisibilityOfGuiSurface((IGfxEngine *)g_pGfxEngine, *v15, 1) )
          {
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
    BBSupportTracePrintF(0, "GUI ENGINE: Cannot clear tooltip surface!");
    return 0;
  }
}


// address=[0x2fa4000]
// Decompiled from bool __thiscall CToolTipExt::~CToolTipExt(CToolTipExt *this)
 CToolTipExt::~CToolTipExt(void) {
  
  return CToolTip::~CToolTip(this);
}


