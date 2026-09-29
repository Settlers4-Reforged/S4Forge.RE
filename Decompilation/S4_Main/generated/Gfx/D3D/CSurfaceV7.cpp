#if FALSE
#include "CSurfaceV7.h"

// Definitions for class CSurfaceV7

// address=[0x2f86620]
// Decompiled from CSurfaceV7 *__thiscall CSurfaceV7::CSurfaceV7(CSurfaceV7 *this)
 CSurfaceV7::CSurfaceV7(void) {
  
  CSurface::CSurface(this);
  this->__vftable = (CSurfaceV7_vtbl *)&CSurfaceV7::_vftable_;
  this->m_pSurfaceV3 = nullptr;
  this->m_pSurfaceV7 = nullptr;
  this->m_bBackbuffer = 0;
  return this;
}


// address=[0x2f86660]
// Decompiled from void __thiscall CSurfaceV7::Release(CSurfaceV7 *this)
void  CSurfaceV7::Release(void) {
  
  if ( this->m_pSurfaceV7 != nullptr )
  {
    this->m_pSurfaceV7->lpVtbl->Release(this->m_pSurfaceV7);
  }
}


// address=[0x2f86690]
// Decompiled from HRESULT __thiscall CSurfaceV7::Restore(CSurfaceV7 *this)
long  CSurfaceV7::Restore(void) {
  
  return this->m_pSurfaceV7->lpVtbl->Restore(this->m_pSurfaceV7);
}


// address=[0x2f866b0]
// Decompiled from HRESULT __thiscall CSurfaceV7::IsLost(CSurfaceV7 *this)
long  CSurfaceV7::IsLost(void) {
  
  return this->m_pSurfaceV7->lpVtbl->IsLost(this->m_pSurfaceV7);
}


// address=[0x2f866d0]
// Decompiled from HRESULT __thiscall CSurfaceV7::ClearSurface(CSurfaceV7 *this, struct CBlitFX *a2)
long  CSurfaceV7::ClearSurface(class CBlitFX * a2) {
  
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
        v6 = this->m_pSurfaceV7->lpVtbl->Blt(this->m_pSurfaceV7, nullptr, nullptr, nullptr, 1536, (LPDDBLTFX)BlitStructPtr);
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
        v6 = this->m_pSurfaceV7->lpVtbl->Blt(this->m_pSurfaceV7, nullptr, nullptr, nullptr, 1536, (LPDDBLTFX)v3);
      }
      while ( v6 == DDERR_WASSTILLDRAWING );
    }
    while ( v6 == DDERR_SURFACEBUSY );
  }
  return v6;
}


// address=[0x2f86770]
// Decompiled from HRESULT __thiscall CSurfaceV7::ClearSurface(CSurfaceV7 *this, struct tagRECT a2, struct CBlitFX *a3)
long  CSurfaceV7::ClearSurface(struct tagRECT a2, class CBlitFX * a3) {
  
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
        v7 = this->m_pSurfaceV7->lpVtbl->Blt(this->m_pSurfaceV7, &a2, nullptr, nullptr, 1536, (LPDDBLTFX)BlitStructPtr);
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
        v7 = this->m_pSurfaceV7->lpVtbl->Blt(this->m_pSurfaceV7, &a2, nullptr, nullptr, 1536, (LPDDBLTFX)v4);
      }
      while ( v7 == DDERR_WASSTILLDRAWING );
    }
    while ( v7 == DDERR_SURFACEBUSY );
  }
  return v7;
}


// address=[0x2f86810]
// Decompiled from HRESULT __thiscall CSurfaceV7::Blt(CSurfaceV7 *this, struct tagRECT *a2, CSurfaceV7 *a3, struct tagRECT *a4, DWORD a5, struct _DDBLTFX *a6)
long  CSurfaceV7::Blt(struct tagRECT * a2, class CSurface * a3, struct tagRECT * a4, unsigned long a5, struct _DDBLTFX * a6) {
  
  HRESULT v8; // [esp+4h] [ebp-4h]

  do
  {
    do
    {
      v8 = this->m_pSurfaceV7->lpVtbl->Blt(this->m_pSurfaceV7, a2, a3->m_pSurfaceV7, a4, a5, a6);
    }
    while ( v8 == DDERR_WASSTILLDRAWING );
  }
  while ( v8 == DDERR_SURFACEBUSY );
  return v8;
}


// address=[0x2f86870]
// Decompiled from HRESULT __thiscall CSurfaceV7::Flip(CSurfaceV7 *this)
long  CSurfaceV7::Flip(void) {
  
  return this->m_pSurfaceV7->lpVtbl->Flip(this->m_pSurfaceV7, nullptr, 1);
}


// address=[0x2f868a0]
// Decompiled from HRESULT __thiscall CSurfaceV7::Lock(CSurfaceV7 *this, unsigned int *a2, void **a3, bool a4)
long  CSurfaceV7::Lock(unsigned int & a2, void * & a3, bool a4) {
  
  HRESULT v6; // [esp+4h] [ebp-8h]
  DWORD v7; // [esp+8h] [ebp-4h]

  v7 = 1;
  if ( a4 )
  {
    v7 = 2049;
  }
  do
  {
    do
    {
      v6 = this->m_pSurfaceV7->lpVtbl->Lock(this->m_pSurfaceV7, nullptr, (LPDDSURFACEDESC2)&s_cSurfaceDescription, v7, nullptr);
    }
    while ( v6 == DDERR_WASSTILLDRAWING );
  }
  while ( v6 == DDERR_SURFACEBUSY );
  *a2 = s_cSurfaceDescription.m_sSurfaceDescription.dwLinearSize;
  *a3 = s_cSurfaceDescription.m_sSurfaceDescription.lpSurface;
  return v6;
}


// address=[0x2f86920]
// Decompiled from HRESULT __thiscall CSurfaceV7::Unlock(CSurfaceV7 *this)
long  CSurfaceV7::Unlock(void) {
  
  return this->m_pSurfaceV7->lpVtbl->Unlock(this->m_pSurfaceV7, nullptr);
}


// address=[0x2f86950]
// Decompiled from HRESULT __thiscall CSurfaceV7::GetDC(CSurfaceV7 *this, HDC *a2)
long  CSurfaceV7::GetDC(struct HDC__ * * a2) {
  
  HRESULT v4; // [esp+4h] [ebp-4h]

  do
  {
    do
    {
      v4 = this->m_pSurfaceV7->lpVtbl->GetDC(this->m_pSurfaceV7, a2);
    }
    while ( v4 == DDERR_WASSTILLDRAWING );
  }
  while ( v4 == DDERR_SURFACEBUSY );
  return v4;
}


// address=[0x2f86990]
// Decompiled from int __thiscall CSurfaceV7::ReleaseDC(CSurfaceV7 *this, HDC a2)
long  CSurfaceV7::ReleaseDC(struct HDC__ * a2) {
  
  return ((int (__thiscall *)(IDirectDrawSurface7 *, IDirectDrawSurface7 *, HDC))this->m_pSurfaceV7->lpVtbl->ReleaseDC)(this->m_pSurfaceV7, this->m_pSurfaceV7, a2);
}


// address=[0x2f869c0]
// Decompiled from int __thiscall CSurfaceV7::CreateSurface(CSurfaceV7 *this, void *pDDInterface, unsigned int iWidth, unsigned int iHeight, unsigned __int8 bVideoMem, unsigned __int8 bHwAccess, unsigned __int8 bIsTexture, int iSurfaceFormat, unsigned __int8 bPrimary)
long  CSurfaceV7::CreateSurface(void * pDDInterface, int iWidth, int iHeight, bool bVideoMem, bool bHwAccess, bool bIsTexture, int iSurfaceFormat, bool bPrimary, bool a9, bool a10) {
  
  char v10; // [esp+2Ch] [ebp+28h]
  char v11; // [esp+30h] [ebp+2Ch]

  s_cSurfaceDescription.m_sSurfaceDescription.dwFlags = 1;
  if ( bPrimary != 0 )
  {
    s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps = 512;
    if ( v11 != 0 )
    {
      s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps |= 0x18u;
      s_cSurfaceDescription.m_sSurfaceDescription.dwFlags |= 0x20u;
      s_cSurfaceDescription.m_sSurfaceDescription.dwBackBufferCount = 1;
      if ( bHwAccess != 0 )
      {
        s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps |= 0x2000u;
      }
    }
  }
  else
  {
    s_cSurfaceDescription.m_sSurfaceDescription.dwFlags |= 0x1000u;
    s_cSurfaceDescription.m_sSurfaceDescription.dwFlags |= 4u;
    s_cSurfaceDescription.m_sSurfaceDescription.dwFlags |= 2u;
    s_cSurfaceDescription.m_sSurfaceDescription.dwWidth = iWidth;
    s_cSurfaceDescription.m_sSurfaceDescription.dwHeight = iHeight;
    *(_QWORD *)(&s_cSurfaceDescription.m_sSurfaceDescription.dwFVF + 1) = 64;
    s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwRGBBitCount = 16;
    if ( iSurfaceFormat == 1 )
    {
      *((_QWORD *)&s_cSurfaceDescription.m_sSurfaceDescription.dwFVF + 2) = 0x3E000007C00LL;
    }
    else
    {
      *((_QWORD *)&s_cSurfaceDescription.m_sSurfaceDescription.dwFVF + 2) = 0x7E00000F800LL;
    }
    *((_QWORD *)&s_cSurfaceDescription.m_sSurfaceDescription.dwFVF + 3) = 31;
    if ( bIsTexture != 0 )
    {
      if ( iSurfaceFormat == 2 )
      {
        *((_QWORD *)&s_cSurfaceDescription.m_sSurfaceDescription.dwFVF + 2) = 0xF000000F00LL;
        *((_QWORD *)&s_cSurfaceDescription.m_sSurfaceDescription.dwFVF + 3) = 0xF0000000000FLL;
        s_cSurfaceDescription.m_sSurfaceDescription.ddpfPixelFormat.dwFlags |= 1u;
      }
      s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps = 4096;
    }
    else
    {
      s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps = 64;
    }
    if ( bVideoMem != 0 )
    {
      s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps |= 0x4000u;
    }
    else
    {
      s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps |= 0x800u;
    }
    if ( bHwAccess != 0 && bIsTexture == 0 )
    {
      s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps |= 0x2000u;
    }
    if ( v10 != 0 && v11 != 0 )
    {
      s_cSurfaceDescription.m_sSurfaceDescription.ddsCaps.dwCaps |= 0x4018u;
      s_cSurfaceDescription.m_sSurfaceDescription.dwFlags |= 0x20u;
      s_cSurfaceDescription.m_sSurfaceDescription.dwBackBufferCount = 1;
    }
  }
  return (*(int (__stdcall **)(void *, CSurfaceDescription *, IDirectDrawSurface7 **, _DWORD))(*(_DWORD *)pDDInterface + offsetof(IDirectDrawVtbl, CreateSurface)))(pDDInterface, &s_cSurfaceDescription, &this->m_pSurfaceV7, 0);
}


// address=[0x2f86bf0]
// Decompiled from HRESULT __thiscall CSurfaceV7::SetColorKey(CSurfaceV7 *this, DWORD a2, struct _DDCOLORKEY *a3)
long  CSurfaceV7::SetColorKey(unsigned long a2, struct _DDCOLORKEY * a3) {
  
  return this->m_pSurfaceV7->lpVtbl->SetColorKey(this->m_pSurfaceV7, a2, a3);
}


// address=[0x2f86c20]
// Decompiled from HRESULT __thiscall CSurfaceV7::GetPixelFormat(CSurfaceV7 *this, bool *a2)
long  CSurfaceV7::GetPixelFormat(bool & a2) {
  
  HRESULT v3; // [esp+0h] [ebp-2Ch]
  DDPIXELFORMAT sPixelFormat; // [esp+8h] [ebp-24h] BYREF

  memset(&sPixelFormat, 0, sizeof(sPixelFormat));
  sPixelFormat.dwSize = 32;
  v3 = this->m_pSurfaceV7->lpVtbl->GetPixelFormat(this->m_pSurfaceV7, &sPixelFormat);
  *a2 = false;
  CBlitFX::SetFillColor(&s_cBlitFx, 0, 0, 0, *a2);
  CBlitFX::SetFillColorAlpha(&s_cBlitFxAlpha, 0, 0, 0, 0);
  CBlitFX::SetFillColorAlpha(&s_cBlitFxAlphaDebug, 0, 255, 0, 255);
  return v3;
}


// address=[0x2f86cc0]
// Decompiled from HRESULT __thiscall CSurfaceV7::GetBitDepth(CSurfaceV7 *this, DWORD *a2)
long  CSurfaceV7::GetBitDepth(int & a2) {
  
  HRESULT result; // eax
  DDPIXELFORMAT v4; // [esp+8h] [ebp-24h] BYREF

  memset(&v4, 0, sizeof(v4));
  v4.dwSize = 32;
  result = this->m_pSurfaceV7->lpVtbl->GetPixelFormat(this->m_pSurfaceV7, &v4);
  *a2 = v4.dwRGBBitCount;
  return result;
}


// address=[0x2f86d20]
// Decompiled from HRESULT __thiscall CSurfaceV7::GetSurfaceSize(CSurfaceV7 *this, DWORD *a2, DWORD *a3)
long  CSurfaceV7::GetSurfaceSize(int & a2, int & a3) {
  
  HRESULT result; // eax

  result = this->m_pSurfaceV7->lpVtbl->GetSurfaceDesc(this->m_pSurfaceV7, (LPDDSURFACEDESC2)&s_cSurfaceDescription);
  *a2 = s_cSurfaceDescription.m_sSurfaceDescription.dwWidth;
  *a3 = s_cSurfaceDescription.m_sSurfaceDescription.dwHeight;
  return result;
}


// address=[0x2f86d70]
// Decompiled from int __thiscall CSurfaceV7::SetClipper(CSurfaceV7 *this, struct IDirectDrawClipper *a2)
long  CSurfaceV7::SetClipper(struct IDirectDrawClipper * a2) {
  
  return ((int (__thiscall *)(IDirectDrawSurface7 *, IDirectDrawSurface7 *, struct IDirectDrawClipper *))this->m_pSurfaceV7->lpVtbl->SetClipper)(this->m_pSurfaceV7, this->m_pSurfaceV7, a2);
}


// address=[0x2f86da0]
// Decompiled from LPDIRECTDRAWSURFACE7 __thiscall CSurfaceV7::GetSurfacePtr(CSurfaceV7 *this)
void *  CSurfaceV7::GetSurfacePtr(void) {
  
  return this->m_pSurfaceV7;
}


// address=[0x2f86dc0]
// Decompiled from void __thiscall CSurfaceV7::SetSurfacePtr(CSurfaceV7 *this, struct IDirectDrawSurface7 *a2)
void  CSurfaceV7::SetSurfacePtr(void * a2) {
  
  this->m_bBackbuffer = 1;
  this->m_pSurfaceV7 = a2;
}


// address=[0x2f86de0]
// Decompiled from int __thiscall CSurfaceV7::GetAttachedSurfacePtr(CSurfaceV7 *this)
void *  CSurfaceV7::GetAttachedSurfacePtr(void) {
  
  int v2; // [esp+0h] [ebp-20h] BYREF
  int v3; // [esp+4h] [ebp-1Ch]
  DDSCAPS2 sCaps; // [esp+Ch] [ebp-14h] BYREF

  sCaps.dwCaps = 4;
  memset(&sCaps.dwCaps2, 0, 12);
  v3 = ((int (__thiscall *)(IDirectDrawSurface7 *, IDirectDrawSurface7 *, DDSCAPS2 *, int *))this->m_pSurfaceV7->lpVtbl->GetAttachedSurface)(this->m_pSurfaceV7, this->m_pSurfaceV7, &sCaps, &v2);
  if ( v3 != 0 )
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
  
  return this->m_bBackbuffer;
}


// address=[0x2f86e70]
// Decompiled from HRESULT __thiscall CSurfaceV7::SetAsRenderTarget(CSurfaceV7 *this, struct IDirect3DDevice7 *a2)
long  CSurfaceV7::SetAsRenderTarget(struct IDirect3DDevice7 * a2) {
  
  if ( this->m_pSurfaceV7 == nullptr )
  {
    j___wassert(L"m_pSurfaceV7 != nullptr", L"DirectXHelperClasses.cpp", 0x56Au);
  }
  return a2->SetRenderTarget(a2, this->m_pSurfaceV7, 0);
}


// address=[0x2f8a340]
// Decompiled from void __thiscall CSurfaceV7::~CSurfaceV7(CSurfaceV7 *this)
 CSurfaceV7::~CSurfaceV7(void) {
  
  CSurface::~CSurface(this);
}


#endif // Already implemented
