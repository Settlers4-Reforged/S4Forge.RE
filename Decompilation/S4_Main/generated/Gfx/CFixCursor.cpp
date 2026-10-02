#if FALSE
#include "CFixCursor.h"

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
  return this;
}


// address=[0x2f624a0]
// Decompiled from int __thiscall CFixCursor::SetSurfacePtr(CFixCursor *this, unsigned __int16 a2, CSurface *a3, WORD a4)
void  CFixCursor::SetSurfacePtr(unsigned short a2, class CSurface * a3, unsigned short a4) {
  
  unsigned int iPitch; // [esp+0h] [ebp-2Ch] BYREF
  COLORREF Pixel; // [esp+4h] [ebp-28h]
  HGDIOBJ h; // [esp+8h] [ebp-24h]
  WORD *pSurfaceData; // [esp+Ch] [ebp-20h] BYREF
  int y; // [esp+10h] [ebp-1Ch]
  int v10; // [esp+14h] [ebp-18h]
  int x; // [esp+1Ch] [ebp-10h]
  HGDIOBJ ho; // [esp+20h] [ebp-Ch]
  HDC hdc; // [esp+24h] [ebp-8h]
  WORD v15; // [esp+28h] [ebp-4h]

  this->m_pSurface = a3;
  ho = LoadBitmapA(g_hInstance, (LPCSTR)a2);
  if ( ho == nullptr )
  {
    return BBSupportTracePrintF(1, "GFX ENGINE: Cannot open resource bitmap!");
  }
  hdc = CreateCompatibleDC(nullptr);
  if ( hdc != nullptr )
  {
    h = SelectObject(hdc, ho);
    if ( h != nullptr )
    {
      v10 = this->m_pSurface->Lock((CSurfaceV7 *)this->m_pSurface, &iPitch, (void **)&pSurfaceData, 1u);
      if ( v10 != 0 )
      {
        WriteError(v10, "LockCursorSurface");
        SelectObject(hdc, h);
        DeleteDC(hdc);
        return DeleteObject(ho);
      }
      else
      {
        for ( y = 0;
              y < 32;
              ++y )
        {
          for ( x = 0;
                x < 32;
                ++x )
          {
            Pixel = GetPixel(hdc, x, y);
            v15 = a4;
            if ( (unsigned __int8)Pixel == 255 )
            {
              v15 = -1;
            }
            else if ( (_BYTE)Pixel == 0 )
            {
              v15 = 0;
            }
            pSurfaceData[x] = v15;
          }
          pSurfaceData += iPitch >> 1;
        }
        v10 = this->m_pSurface->Unlock((CSurfaceV7 *)this->m_pSurface);
        if ( v10 != 0 )
        {
          WriteError(v10, "UnlockCursorSurface");
        }
        SelectObject(hdc, h);
        DeleteDC(hdc);
        return DeleteObject(ho);
      }
    }
    else
    {
      BBSupportTracePrintF(1, "GFX ENGINE: Cannot open select bitmap in move cursor dc!");
      DeleteDC(hdc);
      return DeleteObject(ho);
    }
  }
  else
  {
    BBSupportTracePrintF(1, "GFX ENGINE: Cannot open DC for move cursor!");
    return DeleteObject(ho);
  }
}


// address=[0x2f626a0]
// Decompiled from void __thiscall CFixCursor::SetFixCursor(CFixCursor *this, int a2, int a3, bool a4)
void  CFixCursor::SetFixCursor(int a2, int a3, bool a4) {
  
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
  if ( this->m_sRect.bottom > GfxEngineSetup.sRenderSetup.m_uHeight )
  {
    v5 = this->m_sRect.bottom - GfxEngineSetup.sRenderSetup.m_uHeight;
    this->m_sRect.bottom -= v5;
    this->m_sOffset.bottom -= v5;
  }
  if ( this->m_sRect.right > GfxEngineSetup.sRenderSetup.m_uWidth )
  {
    v6 = this->m_sRect.right - GfxEngineSetup.sRenderSetup.m_uWidth;
    this->m_sRect.right -= v6;
    this->m_sOffset.right -= v6;
  }
  if ( this->m_sRect.top < 0 )
  {
    v7 = abs(this->m_sRect.top);
    this->m_sRect.top += v7;
    this->m_sOffset.top += v7;
  }
  if ( this->m_sRect.left < 0 )
  {
    v4 = abs(this->m_sRect.left);
    this->m_sRect.left += v4;
    this->m_sOffset.left += v4;
  }
}


// address=[0x2f62800]
// Decompiled from HRESULT __thiscall CFixCursor::Show(CFixCursor *this, CSurface *a2)
long  CFixCursor::Show(class CSurface * a2) {
  
  if ( CFixCursor::IsVisible(this) == 0 )
  {
    return 0;
  }
  if ( this->m_pSurface != nullptr && a2 != nullptr )
  {
    return a2->Blt(a2, &this->m_sRect, this->m_pSurface, &this->m_sOffset, 0x8000u, nullptr);
  }
  return 0;
}


// address=[0x2f699a0]
// Decompiled from unsigned __int8 __thiscall CFixCursor::IsVisible(CFixCursor *this)
bool  CFixCursor::IsVisible(void) {
  
  return this->m_bVisible;
}


#endif // Already implemented
