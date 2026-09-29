#if FALSE
#include "CSurfaceV3.h"

// Definitions for class CSurfaceV3

// address=[0x2f86ec0]
// Decompiled from CSurfaceV3 *__thiscall CSurfaceV3::CSurfaceV3(CSurfaceV3 *this)
 CSurfaceV3::CSurfaceV3(void) {
  
  CSurface::CSurface(this);
  this->__vftable = (CSurfaceV7_vtbl *)&CSurfaceV3::_vftable_;
  this->m_pSurfaceV7 = nullptr;
  this->m_pSurfaceV3 = nullptr;
  this->m_bBackbuffer = 0;
  return this;
}


// address=[0x2f86f00]
// Decompiled from CSurfaceV3 *__thiscall CSurfaceV3::Release(CSurfaceV3 *this)
void  CSurfaceV3::Release(void) {
  
  CSurfaceV3 *result; // eax

  result = this;
  if ( this->m_pSurfaceV3 != nullptr )
  {
    return (CSurfaceV3 *)this->m_pSurfaceV3->lpVtbl->Release(this->m_pSurfaceV3);
  }
  return result;
}


// address=[0x2f86f30]
// Decompiled from HRESULT __thiscall CSurfaceV3::Restore(CSurfaceV3 *this)
long  CSurfaceV3::Restore(void) {
  
  return this->m_pSurfaceV3->lpVtbl->Restore(this->m_pSurfaceV3);
}


// address=[0x2f86f50]
// Decompiled from HRESULT __thiscall CSurfaceV3::IsLost(CSurfaceV3 *this)
long  CSurfaceV3::IsLost(void) {
  
  return this->m_pSurfaceV3->lpVtbl->IsLost(this->m_pSurfaceV3);
}


// address=[0x2f86f70]
// Decompiled from HRESULT __thiscall CSurfaceV3::ClearSurface(CSurfaceV3 *this, struct CBlitFX *a2)
long  CSurfaceV3::ClearSurface(class CBlitFX * a2) {
  
  CBlitFX *BlitStructPtr; // eax
  CBlitFX *v3; // eax
  HRESULT v6; // [esp+4h] [ebp-4h]

  if ( a2 != nullptr )
  {
    do
    {
      do
      {
        BlitStructPtr = CBlitFX::GetBlitStructPtr(a2);
        v6 = this->m_pSurfaceV3->lpVtbl->Blt(this->m_pSurfaceV3, nullptr, nullptr, nullptr, 1536, (LPDDBLTFX)BlitStructPtr);
      }
      while ( v6 == DDERR_WASSTILLDRAWING );
    }
    while ( v6 == DDERR_SURFACEBUSY );
  }
  else
  {
    do
    {
      do
      {
        v3 = CBlitFX::GetBlitStructPtr(&s_cBlitFx);
        v6 = this->m_pSurfaceV3->lpVtbl->Blt(this->m_pSurfaceV3, nullptr, nullptr, nullptr, 1536, (LPDDBLTFX)v3);
      }
      while ( v6 == DDERR_WASSTILLDRAWING );
    }
    while ( v6 == DDERR_SURFACEBUSY );
  }
  return v6;
}


// address=[0x2f87010]
// Decompiled from HRESULT __thiscall CSurfaceV3::ClearSurface(CSurfaceV3 *this, struct tagRECT a2, struct CBlitFX *a3)
long  CSurfaceV3::ClearSurface(struct tagRECT a2, class CBlitFX * a3) {
  
  CBlitFX *BlitStructPtr; // eax
  CBlitFX *v4; // eax
  HRESULT v7; // [esp+4h] [ebp-4h]

  if ( a3 != nullptr )
  {
    do
    {
      do
      {
        BlitStructPtr = CBlitFX::GetBlitStructPtr(a3);
        v7 = this->m_pSurfaceV3->lpVtbl->Blt(this->m_pSurfaceV3, &a2, nullptr, nullptr, 1536, (LPDDBLTFX)BlitStructPtr);
      }
      while ( v7 == DDERR_WASSTILLDRAWING );
    }
    while ( v7 == DDERR_SURFACEBUSY );
  }
  else
  {
    do
    {
      do
      {
        v4 = CBlitFX::GetBlitStructPtr(&s_cBlitFx);
        v7 = this->m_pSurfaceV3->lpVtbl->Blt(this->m_pSurfaceV3, &a2, nullptr, nullptr, 1536, (LPDDBLTFX)v4);
      }
      while ( v7 == DDERR_WASSTILLDRAWING );
    }
    while ( v7 == DDERR_SURFACEBUSY );
  }
  return v7;
}


// address=[0x2f870b0]
// Decompiled from HRESULT __thiscall CSurfaceV3::Blt(CSurfaceV3 *this, struct tagRECT *a2, struct CSurface *a3, struct tagRECT *a4, DWORD a5, struct _DDBLTFX *a6)
long  CSurfaceV3::Blt(struct tagRECT * a2, class CSurface * a3, struct tagRECT * a4, unsigned long a5, struct _DDBLTFX * a6) {
  
  HRESULT v8; // [esp+4h] [ebp-4h]

  do
  {
    do
    {
      v8 = this->m_pSurfaceV3->lpVtbl->Blt(this->m_pSurfaceV3, a2, a3->m_pSurfaceV3, a4, a5, a6);
    }
    while ( v8 == DDERR_WASSTILLDRAWING );
  }
  while ( v8 == DDERR_SURFACEBUSY );
  return v8;
}


// address=[0x2f87110]
// Decompiled from HRESULT __thiscall CSurfaceV3::Flip(CSurfaceV3 *this)
long  CSurfaceV3::Flip(void) {
  
  return this->m_pSurfaceV3->lpVtbl->Flip(this->m_pSurfaceV3, nullptr, 1);
}


// address=[0x2f87140]
// Decompiled from HRESULT __thiscall CSurfaceV3::Lock(CSurfaceV3 *this, unsigned int *a2, void **a3, bool a4)
long  CSurfaceV3::Lock(unsigned int & a2, void * & a3, bool a4) {
  
  HRESULT v6; // [esp+8h] [ebp-4h]

  do
  {
    do
    {
      v6 = this->m_pSurfaceV3->lpVtbl->Lock(this->m_pSurfaceV3, nullptr, &s_cSurfaceDescription.m_sSurfaceDescriptionOld, 33, nullptr);
    }
    while ( v6 == DDERR_WASSTILLDRAWING );
  }
  while ( v6 == DDERR_SURFACEBUSY );
  *a2 = s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwLinearSize;
  *a3 = s_cSurfaceDescription.m_sSurfaceDescriptionOld.lpSurface;
  return v6;
}


// address=[0x2f871b0]
// Decompiled from HRESULT __thiscall CSurfaceV3::Unlock(CSurfaceV3 *this)
long  CSurfaceV3::Unlock(void) {
  
  return this->m_pSurfaceV3->lpVtbl->Unlock(this->m_pSurfaceV3, nullptr);
}


// address=[0x2f871e0]
// Decompiled from HRESULT __thiscall CSurfaceV3::GetDC(CSurfaceV3 *this, HDC *a2)
long  CSurfaceV3::GetDC(struct HDC__ * * a2) {
  
  HRESULT v4; // [esp+4h] [ebp-4h]

  do
  {
    do
    {
      v4 = this->m_pSurfaceV3->lpVtbl->GetDC(this->m_pSurfaceV3, a2);
    }
    while ( v4 == DDERR_WASSTILLDRAWING );
  }
  while ( v4 == DDERR_SURFACEBUSY );
  return v4;
}


// address=[0x2f87220]
// Decompiled from int __thiscall CSurfaceV3::ReleaseDC(CSurfaceV3 *this, HDC *a2)
long  CSurfaceV3::ReleaseDC(struct HDC__ * a2) {
  
  return ((int (__thiscall *)(IDirectDrawSurface *, IDirectDrawSurface *, HDC *))this->m_pSurfaceV3->lpVtbl->ReleaseDC)(this->m_pSurfaceV3, this->m_pSurfaceV3, a2);
}


// address=[0x2f87250]
// Decompiled from int __thiscall CSurfaceV3::CreateSurface(CSurfaceV3 *this, void *a2, DWORD a3, DWORD a4, bool a5, bool a6, bool a7, int a8, bool a9, bool a10, bool a11)
long  CSurfaceV3::CreateSurface(void * a2, int a3, int a4, bool a5, bool a6, bool a7, int a8, bool a9, bool a10, bool a11) {
  
  s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwFlags = 1;
  if ( a9 )
  {
    s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps = 512;
    if ( a11 )
    {
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps |= 0x4018u;
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwFlags |= 0x20u;
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwBackBufferCount = 1;
    }
  }
  else
  {
    s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwFlags |= 0x1000u;
    s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwFlags |= 4u;
    s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwFlags |= 2u;
    s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwWidth = a3;
    s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwHeight = a4;
    s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwFlags = 64;
    s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwFourCC = 0;
    s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwRGBBitCount = 16;
    if ( a8 == 1 )
    {
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwRBitMask = 31744;
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwGBitMask = 992;
    }
    else
    {
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwRBitMask = 63488;
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwGBitMask = 2016;
    }
    s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwBBitMask = 31;
    s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwRGBAlphaBitMask = 0;
    if ( a7 )
    {
      if ( a8 == 2 )
      {
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwRBitMask = 3840;
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwGBitMask = 240;
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwBBitMask = 15;
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwRGBAlphaBitMask = 61440;
        s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddpfPixelFormat.dwFlags |= 1u;
      }
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps = 4096;
    }
    else
    {
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps = 64;
    }
    if ( a5 )
    {
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps |= 0x4000u;
    }
    else
    {
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps |= 0x800u;
    }
    if ( a6 && !a7 )
    {
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps |= 0x2000u;
    }
    if ( a10 && a11 )
    {
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.ddsCaps.dwCaps |= 0x4018u;
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwFlags |= 0x20u;
      s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwBackBufferCount = 1;
    }
  }
  return (*(int (__stdcall **)(void *, _DDSURFACEDESC *, IDirectDrawSurface **, _DWORD))(*(_DWORD *)a2 + 24))(a2, &s_cSurfaceDescription.m_sSurfaceDescriptionOld, &this->m_pSurfaceV3, 0);
}


// address=[0x2f87470]
// Decompiled from HRESULT __thiscall CSurfaceV3::SetColorKey(CSurfaceV3 *this, DWORD a2, struct _DDCOLORKEY *a3)
long  CSurfaceV3::SetColorKey(unsigned long a2, struct _DDCOLORKEY * a3) {
  
  return this->m_pSurfaceV3->lpVtbl->SetColorKey(this->m_pSurfaceV3, a2, a3);
}


// address=[0x2f874a0]
// Decompiled from HRESULT __thiscall CSurfaceV3::GetPixelFormat(CSurfaceV3 *this, bool *a2)
long  CSurfaceV3::GetPixelFormat(bool & a2) {
  
  HRESULT v3; // [esp+0h] [ebp-30h]
  DDPIXELFORMAT v5; // [esp+Ch] [ebp-24h] BYREF

  memset(&v5, 0, sizeof(v5));
  v5.dwSize = 32;
  v3 = this->m_pSurfaceV3->lpVtbl->GetPixelFormat(this->m_pSurfaceV3, &v5);
  *a2 = v5.dwGBitMask == 992;
  CBlitFX::SetFillColor(&s_cBlitFx, 0, 0, 0, *a2);
  CBlitFX::SetFillColorAlpha(&s_cBlitFxAlpha, 0, 0, 0, 0);
  CBlitFX::SetFillColorAlpha(&s_cBlitFxAlphaDebug, 0, 255, 0, 255);
  return v3;
}


// address=[0x2f87560]
// Decompiled from HRESULT __thiscall CSurfaceV3::GetBitDepth(CSurfaceV3 *this, DWORD *a2)
long  CSurfaceV3::GetBitDepth(int & a2) {
  
  HRESULT result; // eax
  DDPIXELFORMAT v4; // [esp+8h] [ebp-24h] BYREF

  memset(&v4, 0, sizeof(v4));
  v4.dwSize = 32;
  result = this->m_pSurfaceV3->lpVtbl->GetPixelFormat(this->m_pSurfaceV3, &v4);
  *a2 = v4.dwRGBBitCount;
  return result;
}


// address=[0x2f875c0]
// Decompiled from HRESULT __thiscall CSurfaceV3::GetSurfaceSize(CSurfaceV3 *this, DWORD *a2, DWORD *a3)
long  CSurfaceV3::GetSurfaceSize(int & a2, int & a3) {
  
  HRESULT result; // eax

  result = this->m_pSurfaceV3->lpVtbl->GetSurfaceDesc(this->m_pSurfaceV3, &s_cSurfaceDescription.m_sSurfaceDescriptionOld);
  *a2 = s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwWidth;
  *a3 = s_cSurfaceDescription.m_sSurfaceDescriptionOld.dwHeight;
  return result;
}


// address=[0x2f87610]
// Decompiled from int __thiscall CSurfaceV3::SetClipper(CSurfaceV3 *this, struct IDirectDrawClipper *a2)
long  CSurfaceV3::SetClipper(struct IDirectDrawClipper * a2) {
  
  return ((int (__thiscall *)(IDirectDrawSurface *, IDirectDrawSurface *, struct IDirectDrawClipper *))this->m_pSurfaceV3->lpVtbl->SetClipper)(this->m_pSurfaceV3, this->m_pSurfaceV3, a2);
}


// address=[0x2f87640]
// Decompiled from IDirectDrawSurface *__thiscall CSurfaceV3::GetSurfacePtr(CSurfaceV3 *this)
void *  CSurfaceV3::GetSurfacePtr(void) {
  
  return this->m_pSurfaceV3;
}


// address=[0x2f87660]
// Decompiled from CSurfaceV3 *__thiscall CSurfaceV3::SetSurfacePtr(CSurfaceV3 *this, IDirectDrawSurface *a2)
void  CSurfaceV3::SetSurfacePtr(void * a2) {
  
  this->m_bBackbuffer = 1;
  this->m_pSurfaceV3 = a2;
  return this;
}


// address=[0x2f87680]
// Decompiled from LPDIRECTDRAWSURFACE __thiscall CSurfaceV3::GetAttachedSurfacePtr(CSurfaceV3 *this)
void *  CSurfaceV3::GetAttachedSurfacePtr(void) {
  
  LPDIRECTDRAWSURFACE v2; // [esp+0h] [ebp-10h] BYREF
  HRESULT v3; // [esp+4h] [ebp-Ch]
  DDSCAPS v4; // [esp+8h] [ebp-8h] BYREF

  v4.dwCaps = 4;
  v3 = this->m_pSurfaceV3->lpVtbl->GetAttachedSurface(this->m_pSurfaceV3, &v4, &v2);
  if ( v3 != 0 )
  {
    return nullptr;
  }
  else
  {
    return v2;
  }
}


// address=[0x2f876c0]
// Decompiled from char __thiscall CSurfaceV3::IsBackBufferReference(CSurfaceV3 *this)
bool  CSurfaceV3::IsBackBufferReference(void) {
  
  return this->m_bBackbuffer;
}


// address=[0x2f876e0]
// Decompiled from MACRO_DDERR __thiscall CSurfaceV3::SetAsRenderTarget(CSurfaceV3 *this, struct IDirect3DDevice7 *a2)
long  CSurfaceV3::SetAsRenderTarget(struct IDirect3DDevice7 * a2) {
  
  return DDERR_GENERIC;
}


// address=[0x2f8a320]
// Decompiled from void __thiscall CSurfaceV3::~CSurfaceV3(CSurface *this)
 CSurfaceV3::~CSurfaceV3(void) {
  
  CSurface::~CSurface(this);
}


#endif // Already implemented
