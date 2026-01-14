#include "all_headers.h"

// Definitions for class CSurfaceV7

// address=[0x2f86620]
// Decompiled from CSurfaceV7 *__thiscall CSurfaceV7::CSurfaceV7(CSurfaceV7 *this)
 CSurfaceV7::CSurfaceV7(void) {
  
  CSurface::CSurface((CSurface *)this);
  this->__vftable = (CSurfaceV7_vtbl *)&CSurfaceV7::_vftable_;
  this->field_8 = 0;
  this->innerSurface = 0;
  this->field_C = 0;
  return this;
}


// address=[0x2f86660]
// Decompiled from CSurfaceV7 *__thiscall CSurfaceV7::Release(CSurfaceV7 *this)
void  CSurfaceV7::Release(void) {
  
  CSurfaceV7 *result; // eax

  result = this;
  if ( this->innerSurface )
    return (CSurfaceV7 *)this->innerSurface->lpVtbl->Release(this->innerSurface);
  return result;
}


// address=[0x2f86690]
// Decompiled from HRESULT __thiscall CSurfaceV7::Restore(CSurfaceV7 *this)
long  CSurfaceV7::Restore(void) {
  
  return this->innerSurface->lpVtbl->Restore(this->innerSurface);
}


// address=[0x2f866b0]
// Decompiled from HRESULT __thiscall CSurfaceV7::IsLost(CSurfaceV7 *this)
long  CSurfaceV7::IsLost(void) {
  
  return this->innerSurface->lpVtbl->IsLost(this->innerSurface);
}


// address=[0x2f866d0]
// Decompiled from HRESULT __thiscall CSurfaceV7::ClearSurface(CSurfaceV7 *this, struct CBlitFX *a2)
long  CSurfaceV7::ClearSurface(class CBlitFX *) {
  
  DDBLTFX *BlitStructPtr; // eax
  DDBLTFX *v3; // eax
  HRESULT v6; // [esp+4h] [ebp-4h]

  if ( a2 )
  {
    do
    {
      do
      {
        BlitStructPtr = (DDBLTFX *)CBlitFX::GetBlitStructPtr(a2);
        v6 = this->innerSurface->lpVtbl->Blt(this->innerSurface, 0, 0, 0, 1536, BlitStructPtr);
      }
      while ( v6 == -2005532132 );
    }
    while ( v6 == -2005532242 );
  }
  else
  {
    do
    {
      do
      {
        v3 = (DDBLTFX *)CBlitFX::GetBlitStructPtr((CBlitFX *)&s_cBlitFx);
        v6 = this->innerSurface->lpVtbl->Blt(this->innerSurface, 0, 0, 0, 1536, v3);
      }
      while ( v6 == -2005532132 );
    }
    while ( v6 == -2005532242 );
  }
  return v6;
}


// address=[0x2f86770]
// Decompiled from HRESULT __thiscall CSurfaceV7::ClearSurface(CSurfaceV7 *this, struct tagRECT a2, struct CBlitFX *a3)
long  CSurfaceV7::ClearSurface(struct tagRECT,class CBlitFX *) {
  
  DDBLTFX *BlitStructPtr; // eax
  DDBLTFX *v4; // eax
  HRESULT v7; // [esp+4h] [ebp-4h]

  if ( a3 )
  {
    do
    {
      do
      {
        BlitStructPtr = (DDBLTFX *)CBlitFX::GetBlitStructPtr(a3);
        v7 = this->innerSurface->lpVtbl->Blt(this->innerSurface, &a2, 0, 0, 1536, BlitStructPtr);
      }
      while ( v7 == -2005532132 );
    }
    while ( v7 == -2005532242 );
  }
  else
  {
    do
    {
      do
      {
        v4 = (DDBLTFX *)CBlitFX::GetBlitStructPtr((CBlitFX *)&s_cBlitFx);
        v7 = this->innerSurface->lpVtbl->Blt(this->innerSurface, &a2, 0, 0, 1536, v4);
      }
      while ( v7 == -2005532132 );
    }
    while ( v7 == -2005532242 );
  }
  return v7;
}


// address=[0x2f86810]
// Decompiled from HRESULT __thiscall CSurfaceV7::Blt(  CSurfaceV7 *this,  struct tagRECT *a2,  CSurfaceV7 *a3,  struct tagRECT *a4,  DWORD a5,  struct _DDBLTFX *a6)
long  CSurfaceV7::Blt(struct tagRECT *,class CSurface *,struct tagRECT *,unsigned long,struct _DDBLTFX *) {
  
  HRESULT v8; // [esp+4h] [ebp-4h]

  do
  {
    do
      v8 = this->innerSurface->lpVtbl->Blt(this->innerSurface, a2, a3->innerSurface, a4, a5, a6);
    while ( v8 == -2005532132 );
  }
  while ( v8 == -2005532242 );
  return v8;
}


// address=[0x2f86870]
// Decompiled from HRESULT __thiscall CSurfaceV7::Flip(CSurfaceV7 *this)
long  CSurfaceV7::Flip(void) {
  
  return this->innerSurface->lpVtbl->Flip(this->innerSurface, 0, 1);
}


// address=[0x2f868a0]
// Decompiled from HRESULT __thiscall CSurfaceV7::Lock(CSurfaceV7 *this, unsigned int *a2, void **a3, bool a4)
long  CSurfaceV7::Lock(unsigned int &,void * &,bool) {
  
  HRESULT v6; // [esp+4h] [ebp-8h]
  DWORD v7; // [esp+8h] [ebp-4h]

  v7 = 1;
  if ( a4 )
    v7 = 2049;
  do
  {
    do
      v6 = this->innerSurface->lpVtbl->Lock(this->innerSurface, 0, &s_cSurfaceDescription, v7, 0);
    while ( v6 == -2005532132 );
  }
  while ( v6 == -2005532242 );
  *a2 = s_cSurfaceDescription.dwLinearSize;
  *a3 = s_cSurfaceDescription.lpSurface;
  return v6;
}


// address=[0x2f86920]
// Decompiled from HRESULT __thiscall CSurfaceV7::Unlock(CSurfaceV7 *this)
long  CSurfaceV7::Unlock(void) {
  
  return this->innerSurface->lpVtbl->Unlock(this->innerSurface, 0);
}


// address=[0x2f86950]
// Decompiled from HRESULT __thiscall CSurfaceV7::GetDC(CSurfaceV7 *this, HDC *a2)
long  CSurfaceV7::GetDC(struct HDC__ * *) {
  
  HRESULT v4; // [esp+4h] [ebp-4h]

  do
  {
    do
      v4 = this->innerSurface->lpVtbl->GetDC(this->innerSurface, a2);
    while ( v4 == -2005532132 );
  }
  while ( v4 == -2005532242 );
  return v4;
}


// address=[0x2f86990]
// Decompiled from int __thiscall CSurfaceV7::ReleaseDC(CSurfaceV7 *this, HDC a2)
long  CSurfaceV7::ReleaseDC(struct HDC__ *) {
  
  return ((int (__thiscall *)(LPDIRECTDRAWSURFACE7, LPDIRECTDRAWSURFACE7, HDC))this->innerSurface->lpVtbl->ReleaseDC)(
           this->innerSurface,
           this->innerSurface,
           a2);
}


// address=[0x2f869c0]
// Decompiled from int __thiscall CSurfaceV7::CreateSurface(  CSurfaceV7 *this,  void *a2,  int a3,  int a4,  bool a5,  bool a6,  bool a7,  int a8,  bool a9,  bool a10,  bool a11)
long  CSurfaceV7::CreateSurface(void *,int,int,bool,bool,bool,int,bool,bool,bool) {
  
  MEMORY[0x46C6714] = 1;
  if ( a9 )
  {
    MEMORY[0x46C6778] = 512;
    if ( a11 )
    {
      MEMORY[0x46C6778] |= 0x18u;
      MEMORY[0x46C6714] |= 0x20u;
      MEMORY[0x46C6724] = 1;
      if ( a6 )
        MEMORY[0x46C6778] |= 0x2000u;
    }
  }
  else
  {
    MEMORY[0x46C6714] |= 0x1000u;
    MEMORY[0x46C6714] |= 4u;
    MEMORY[0x46C6714] |= 2u;
    MEMORY[0x46C671C] = a3;
    MEMORY[0x46C6718] = a4;
    MEMORY[0x46C675C] = 64;
    MEMORY[0x46C6760] = 0;
    MEMORY[0x46C6764] = 16;
    if ( a8 == 1 )
    {
      MEMORY[0x46C6768] = 31744;
      MEMORY[0x46C676C] = 992;
    }
    else
    {
      MEMORY[0x46C6768] = 63488;
      MEMORY[0x46C676C] = 2016;
    }
    MEMORY[0x46C6770] = 31;
    MEMORY[0x46C6774] = 0;
    if ( a7 )
    {
      if ( a8 == 2 )
      {
        MEMORY[0x46C6768] = 3840;
        MEMORY[0x46C676C] = 240;
        MEMORY[0x46C6770] = 15;
        MEMORY[0x46C6774] = 61440;
        MEMORY[0x46C675C] |= 1u;
      }
      MEMORY[0x46C6778] = 4096;
    }
    else
    {
      MEMORY[0x46C6778] = 64;
    }
    if ( a5 )
      MEMORY[0x46C6778] |= 0x4000u;
    else
      MEMORY[0x46C6778] |= 0x800u;
    if ( a6 && !a7 )
      MEMORY[0x46C6778] |= 0x2000u;
    if ( a10 && a11 )
    {
      MEMORY[0x46C6778] |= 0x4018u;
      MEMORY[0x46C6714] |= 0x20u;
      MEMORY[0x46C6724] = 1;
    }
  }
  return (*(int (__stdcall **)(void *, void *, LPDIRECTDRAWSURFACE7 *, _DWORD))(*(_DWORD *)a2 + 24))(
           a2,
           &s_cSurfaceDescription,
           &this->innerSurface,
           0);
}


// address=[0x2f86bf0]
// Decompiled from HRESULT __thiscall CSurfaceV7::SetColorKey(CSurfaceV7 *this, DWORD a2, struct _DDCOLORKEY *a3)
long  CSurfaceV7::SetColorKey(unsigned long,struct _DDCOLORKEY *) {
  
  return this->innerSurface->lpVtbl->SetColorKey(this->innerSurface, a2, a3);
}


// address=[0x2f86c20]
// Decompiled from HRESULT __thiscall CSurfaceV7::GetPixelFormat(CSurfaceV7 *this, bool *a2)
long  CSurfaceV7::GetPixelFormat(bool &) {
  
  HRESULT v3; // [esp+0h] [ebp-2Ch]
  _DWORD v5[8]; // [esp+8h] [ebp-24h] BYREF

  memset(v5, 0, sizeof(v5));
  v5[0] = 32;
  v3 = this->innerSurface->lpVtbl->GetPixelFormat(this->innerSurface, (LPDDPIXELFORMAT)v5);
  *a2 = 0;
  CBlitFX::SetFillColor((CBlitFX *)&s_cBlitFx, 0, 0, 0, *a2);
  CBlitFX::SetFillColorAlpha((CBlitFX *)&s_cBlitFxAlpha, 0, 0, 0, 0);
  CBlitFX::SetFillColorAlpha((CBlitFX *)&s_cBlitFxAlphaDebug, 0, 255, 0, 255);
  return v3;
}


// address=[0x2f86cc0]
// Decompiled from HRESULT __thiscall CSurfaceV7::GetBitDepth(CSurfaceV7 *this, int *a2)
long  CSurfaceV7::GetBitDepth(int &) {
  
  HRESULT result; // eax
  _DWORD v4[8]; // [esp+8h] [ebp-24h] BYREF

  memset(v4, 0, sizeof(v4));
  v4[0] = 32;
  result = this->innerSurface->lpVtbl->GetPixelFormat(this->innerSurface, (LPDDPIXELFORMAT)v4);
  *a2 = v4[3];
  return result;
}


// address=[0x2f86d20]
// Decompiled from HRESULT __thiscall CSurfaceV7::GetSurfaceSize(CSurfaceV7 *this, DWORD *a2, DWORD *a3)
long  CSurfaceV7::GetSurfaceSize(int &,int &) {
  
  HRESULT result; // eax

  result = this->innerSurface->lpVtbl->GetSurfaceDesc(this->innerSurface, &s_cSurfaceDescription);
  *a2 = s_cSurfaceDescription.dwWidth;
  *a3 = s_cSurfaceDescription.dwHeight;
  return result;
}


// address=[0x2f86d70]
// Decompiled from int __thiscall CSurfaceV7::SetClipper(CSurfaceV7 *this, struct IDirectDrawClipper *a2)
long  CSurfaceV7::SetClipper(struct IDirectDrawClipper *) {
  
  return ((int (__thiscall *)(LPDIRECTDRAWSURFACE7, LPDIRECTDRAWSURFACE7, struct IDirectDrawClipper *))this->innerSurface->lpVtbl->SetClipper)(
           this->innerSurface,
           this->innerSurface,
           a2);
}


// address=[0x2f86da0]
// Decompiled from LPDIRECTDRAWSURFACE7 __thiscall CSurfaceV7::GetSurfacePtr(CSurfaceV7 *this)
void *  CSurfaceV7::GetSurfacePtr(void) {
  
  return this->innerSurface;
}


// address=[0x2f86dc0]
// Decompiled from CSurfaceV7 *__thiscall CSurfaceV7::SetSurfacePtr(CSurfaceV7 *this, struct IDirectDrawSurface7 *a2)
void  CSurfaceV7::SetSurfacePtr(void *) {
  
  CSurfaceV7 *result; // eax

  result = this;
  this->field_C = 1;
  this->innerSurface = a2;
  return result;
}


// address=[0x2f86de0]
// Decompiled from int __thiscall CSurfaceV7::GetAttachedSurfacePtr(CSurfaceV7 *this)
void *  CSurfaceV7::GetAttachedSurfacePtr(void) {
  
  int v2; // [esp+0h] [ebp-20h] BYREF
  CSurfaceV7 *v4; // [esp+8h] [ebp-18h]
  _DWORD v5[4]; // [esp+Ch] [ebp-14h] BYREF

  v4 = this;
  v5[0] = 4;
  memset(&v5[1], 0, 12);
  if ( ((int (__thiscall *)(LPDIRECTDRAWSURFACE7, LPDIRECTDRAWSURFACE7, _DWORD *, int *))this->innerSurface->lpVtbl->GetAttachedSurface)(
         this->innerSurface,
         this->innerSurface,
         v5,
         &v2) )
  {
    return 0;
  }
  else
  {
    return v2;
  }
}


// address=[0x2f86e50]
// Decompiled from char __thiscall CSurfaceV7::IsBackBufferReference(CSurfaceV7 *this)
bool  CSurfaceV7::IsBackBufferReference(void) {
  
  return this->field_C;
}


// address=[0x2f86e70]
// Decompiled from int __thiscall CSurfaceV7::SetAsRenderTarget(CSurfaceV7 *this, struct IDirect3DDevice7 *a2)
long  CSurfaceV7::SetAsRenderTarget(struct IDirect3DDevice7 *) {
  
  if ( !this->innerSurface )
    j___wassert(L"m_pSurfaceV7 != nullptr", L"DirectXHelperClasses.cpp", 0x56Au);
  return (*(int (__stdcall **)(struct IDirect3DDevice7 *, LPDIRECTDRAWSURFACE7, _DWORD))(*(_DWORD *)a2 + 32))(
           a2,
           this->innerSurface,
           0);
}


// address=[0x2f8a340]
// Decompiled from void __thiscall CSurfaceV7::~CSurfaceV7(CSurfaceV7 *this)
 CSurfaceV7::~CSurfaceV7(void) {
  
  CSurface::~CSurface((CSurface *)this);
}


