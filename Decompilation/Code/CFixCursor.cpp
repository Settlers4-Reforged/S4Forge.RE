#include "CFixCursor.h"

// Definitions for class CFixCursor

// address=[0x2f62430]
// Decompiled from CFixCursor *__thiscall CFixCursor::CFixCursor(CFixCursor *this)
 CFixCursor::CFixCursor(void) {
  
  *((_BYTE *)this + 36) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 8) = 0;
  *(_DWORD *)this = 0;
  return this;
}


// address=[0x2f624a0]
// Decompiled from int __thiscall CFixCursor::SetSurfacePtr(  CFixCursor *this,  unsigned __int16 a2,  struct CSurface *a3,  unsigned __int16 a4)
void  CFixCursor::SetSurfacePtr(unsigned short,class CSurface *,unsigned short) {
  
  unsigned int v5; // [esp+0h] [ebp-2Ch] BYREF
  COLORREF Pixel; // [esp+4h] [ebp-28h]
  HGDIOBJ h; // [esp+8h] [ebp-24h]
  int v8; // [esp+Ch] [ebp-20h] BYREF
  int y; // [esp+10h] [ebp-1Ch]
  int v10; // [esp+14h] [ebp-18h]
  CFixCursor *v11; // [esp+18h] [ebp-14h]
  int x; // [esp+1Ch] [ebp-10h]
  HGDIOBJ ho; // [esp+20h] [ebp-Ch]
  HDC hdc; // [esp+24h] [ebp-8h]
  unsigned __int16 v15; // [esp+28h] [ebp-4h]

  v11 = this;
  *(_DWORD *)this = a3;
  ho = LoadBitmapA(g_hInstance, (LPCSTR)a2);
  if ( !ho )
    return BBSupportTracePrintF(1, "GFX ENGINE: Cannot open resource bitmap!");
  hdc = CreateCompatibleDC(0);
  if ( hdc )
  {
    h = SelectObject(hdc, ho);
    if ( h )
    {
      v10 = (*(int (__thiscall **)(_DWORD, unsigned int *, int *, int))(**(_DWORD **)v11 + 32))(
              *(_DWORD *)v11,
              &v5,
              &v8,
              1);
      if ( v10 )
      {
        WriteError(v10, "LockCursorSurface");
        SelectObject(hdc, h);
        DeleteDC(hdc);
        return DeleteObject(ho);
      }
      else
      {
        for ( y = 0; y < 32; ++y )
        {
          for ( x = 0; x < 32; ++x )
          {
            Pixel = GetPixel(hdc, x, y);
            v15 = a4;
            if ( (unsigned __int8)Pixel == 255 )
            {
              v15 = -1;
            }
            else if ( !(_BYTE)Pixel )
            {
              v15 = 0;
            }
            *(_WORD *)(v8 + 2 * x) = v15;
          }
          v8 += 2 * (v5 >> 1);
        }
        v10 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)v11 + 36))(*(_DWORD *)v11);
        if ( v10 )
          WriteError(v10, "UnlockCursorSurface");
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
// Decompiled from CFixCursor *__thiscall CFixCursor::SetFixCursor(CFixCursor *this, int a2, int a3, bool a4)
void  CFixCursor::SetFixCursor(int,int,bool) {
  
  CFixCursor *result; // eax
  int v5; // eax
  int v6; // edx
  int v7; // [esp+0h] [ebp-8h]
  int v8; // [esp+0h] [ebp-8h]
  int v9; // [esp+0h] [ebp-8h]

  *((_BYTE *)this + 36) = a4;
  *((_DWORD *)this + 1) = a2 - 8;
  *((_DWORD *)this + 2) = a3 - 8;
  *((_DWORD *)this + 3) = a2 + 24;
  *((_DWORD *)this + 4) = a3 + 24;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 32;
  *((_DWORD *)this + 8) = 32;
  if ( *((_DWORD *)this + 4) > OutputHeight )
  {
    v7 = *((_DWORD *)this + 4) - OutputHeight;
    *((_DWORD *)this + 4) -= v7;
    *((_DWORD *)this + 8) -= v7;
  }
  result = this;
  if ( *((_DWORD *)this + 3) > OutputWidth )
  {
    v8 = *((_DWORD *)this + 3) - OutputWidth;
    *((_DWORD *)this + 3) -= v8;
    result = this;
    *((_DWORD *)this + 7) -= v8;
  }
  if ( *((int *)this + 2) < 0 )
  {
    v9 = abs(*((_DWORD *)this + 2));
    *((_DWORD *)this + 2) += v9;
    result = this;
    *((_DWORD *)this + 6) += v9;
  }
  if ( *((int *)this + 1) >= 0 )
    return result;
  v5 = abs(*((_DWORD *)this + 1));
  *((_DWORD *)this + 1) += v5;
  v6 = v5 + *((_DWORD *)this + 5);
  result = this;
  *((_DWORD *)this + 5) = v6;
  return result;
}


// address=[0x2f62800]
// Decompiled from int __thiscall CFixCursor::Show(CFixCursor *this, struct CSurface *a2)
long  CFixCursor::Show(class CSurface *) {
  
  if ( !CFixCursor::IsVisible(this) )
    return 0;
  if ( *(_DWORD *)this && a2 )
    return (*(int (__thiscall **)(struct CSurface *, char *, _DWORD, char *, int, _DWORD))(*(_DWORD *)a2 + 24))(
             a2,
             (char *)this + 4,
             *(_DWORD *)this,
             (char *)this + 20,
             0x8000,
             0);
  return 0;
}


// address=[0x2f699a0]
// Decompiled from unsigned __int8 __thiscall CFixCursor::IsVisible(CMFCScanliner *this)
bool  CFixCursor::IsVisible(void) {
  
  return *((_BYTE *)this + 36);
}


