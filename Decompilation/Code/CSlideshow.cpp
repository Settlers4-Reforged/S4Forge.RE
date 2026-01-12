#include "CSlideshow.h"

// Definitions for class CSlideshow

// address=[0x149ada0]
// Decompiled from CSlideshow *__thiscall CSlideshow::CSlideshow(CSlideshow *this, int a2)

 CSlideshow::CSlideshow(int) {
  
  int OutputWidth; // [esp+0h] [ebp-3Ch]
  int OutputHeight; // [esp+4h] [ebp-38h]
  _DWORD v6[7]; // [esp+Ch] [ebp-30h] BYREF
  int v7; // [esp+28h] [ebp-14h]
  int v8; // [esp+2Ch] [ebp-10h]
  int v9; // [esp+30h] [ebp-Ch]
  int v10; // [esp+34h] [ebp-8h]

  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = -1;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = 0;
  j__memset(v6, 0, sizeof(v6));
  LOBYTE(v6[6]) = 0;
  OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
  OutputHeight = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
  v6[0] = OutputWidth;
  v6[1] = OutputHeight;
  v7 = 0;
  v8 = 0;
  v9 = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
  v10 = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
  v6[2] = v7;
  v6[3] = v8;
  v6[4] = v9;
  v6[5] = v10;
  *((_DWORD *)this + 2) = IGfxEngine::CreateGuiSurface(
                            (IGfxEngine *)g_pGfxEngine,
                            (struct GFX_ENGINE_GUI_SURFACE_DESCRIPTION *)v6);
  if ( CSlideshow::HasDisplaySurface(this) )
    IGfxEngine::SetVisibilityOfGuiSurface((IGfxEngine *)g_pGfxEngine, *((_DWORD *)this + 2), 1);
  else
    CTrace::Print("Slideshow.cpp: Error creating GUI Surface!");
  return this;
}


// address=[0x149aec0]
// Decompiled from bool __thiscall CSlideshow::~CSlideshow(CSlideshow *this)

 CSlideshow::~CSlideshow(void) {
  
  bool result; // al

  result = CSlideshow::HasDisplaySurface(this);
  if ( result )
    return IGfxEngine::DestroyGuiSurface((IGfxEngine *)g_pGfxEngine, *((_DWORD *)this + 2));
  return result;
}


// address=[0x149af20]
// Decompiled from bool __thiscall CSlideshow::Advance(CSlideshow *this)

bool  CSlideshow::Advance(void) {
  
  bool v3; // [esp+7h] [ebp-1h]

  v3 = CSlideshow::ShowPicture(this);
  ++*((_DWORD *)this + 1);
  return v3;
}


// address=[0x149af50]
// Decompiled from char __thiscall CSlideshow::ShowPicture(CSlideshow *this)

bool  CSlideshow::ShowPicture(void) {
  
  int OutputWidth; // eax
  int OutputHeight; // [esp-14h] [ebp-13Ch]
  HDC v4; // [esp-10h] [ebp-138h]
  HGDIOBJ v5; // [esp+Ch] [ebp-11Ch]
  HDC v6; // [esp+10h] [ebp-118h] BYREF
  HDC hdc; // [esp+14h] [ebp-114h]
  HGDIOBJ h; // [esp+18h] [ebp-110h]
  CSlideshow *v9; // [esp+1Ch] [ebp-10Ch]
  CHAR name[260]; // [esp+20h] [ebp-108h] BYREF

  v9 = this;
  if ( !CSlideshow::HasDisplaySurface(this) )
    return 0;
  h = 0;
  while ( *((int *)v9 + 1) < 10 )
  {
    if ( *(_DWORD *)v9 )
      j__sprintf(name, "downsell%d.bmp", *((_DWORD *)v9 + 1));
    else
      j__sprintf(name, "upsell%d.bmp", *((_DWORD *)v9 + 1));
    h = LoadImageA(0, name, 0, 0, 0, 0x10u);
    if ( h )
      break;
    ++*((_DWORD *)v9 + 1);
  }
  if ( !h )
    return 0;
  IGfxEngine::GetGuiSurfaceDC((IGfxEngine *)g_pGfxEngine, *((_DWORD *)v9 + 2), &v6);
  hdc = CreateCompatibleDC(0);
  v5 = SelectObject(hdc, h);
  IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
  IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
  v4 = hdc;
  OutputHeight = IGfxEngine::GetOutputHeight((IGfxEngine *)g_pGfxEngine);
  OutputWidth = IGfxEngine::GetOutputWidth((IGfxEngine *)g_pGfxEngine);
  if ( !BitBlt(v6, 0, 0, OutputWidth, OutputHeight, v4, 0, 0, (DWORD)&dword_C20408[163590]) )
    return 0;
  SelectObject(hdc, v5);
  if ( !DeleteDC(hdc) )
    CTrace::Print("SlideShow.cpp: Could not release compDC!");
  IGfxEngine::ReleaseGuiSurfaceDC((IGfxEngine *)g_pGfxEngine, *((_DWORD *)v9 + 2), v6);
  DeleteObject(h);
  return 1;
}


// address=[0x149b240]
// Decompiled from bool __thiscall CSlideshow::HasDisplaySurface(CSlideshow *this)

bool  CSlideshow::HasDisplaySurface(void)const {
  
  return *((_DWORD *)this + 2) != -1;
}


