#include "CSurfaceV3.h"

// Definitions for class CSurfaceV3

// address=[0x2f86ec0]
// Decompiled from CSurfaceV3 *__thiscall CSurfaceV3::CSurfaceV3(CSurfaceV3 *this)
 CSurfaceV3::CSurfaceV3(void) {
  
  CSurface::CSurface(this);
  *(_DWORD *)this = &CSurfaceV3::_vftable_;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_BYTE *)this + 12) = 0;
  return this;
}


// address=[0x2f86f00]
// Decompiled from CSurfaceV3 *__thiscall CSurfaceV3::Release(CSurfaceV3 *this)
void  CSurfaceV3::Release(void) {
  
  CSurfaceV3 *result; // eax

  result = this;
  if ( *((_DWORD *)this + 2) )
    return (CSurfaceV3 *)(*(int (__stdcall **)(_DWORD))(**((_DWORD **)this + 2) + 8))(*((_DWORD *)this + 2));
  return result;
}


// address=[0x2f86f30]
// Decompiled from int __thiscall CSurfaceV3::Restore(CSurfaceV3 *this)
long  CSurfaceV3::Restore(void) {
  
  return (*(int (__stdcall **)(_DWORD))(**((_DWORD **)this + 2) + 108))(*((_DWORD *)this + 2));
}


// address=[0x2f86f50]
// Decompiled from int __thiscall CSurfaceV3::IsLost(CSurfaceV3 *this)
long  CSurfaceV3::IsLost(void) {
  
  return (*(int (__stdcall **)(_DWORD))(**((_DWORD **)this + 2) + 96))(*((_DWORD *)this + 2));
}


// address=[0x2f86f70]
// Decompiled from int __thiscall CSurfaceV3::ClearSurface(CSurfaceV3 *this, struct CBlitFX *a2)
long  CSurfaceV3::ClearSurface(class CBlitFX * a2) {
  
  CBlitFX *BlitStructPtr; // eax
  CBlitFX *v3; // eax
  int v6; // [esp+4h] [ebp-4h]

  if ( a2 )
  {
    do
    {
      do
      {
        BlitStructPtr = CBlitFX::GetBlitStructPtr(a2);
        v6 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, int, CBlitFX *))(**((_DWORD **)this + 2) + 20))(
               *((_DWORD *)this + 2),
               0,
               0,
               0,
               1536,
               BlitStructPtr);
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
        v3 = CBlitFX::GetBlitStructPtr((CBlitFX *)&s_cBlitFx);
        v6 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, int, CBlitFX *))(**((_DWORD **)this + 2) + 20))(
               *((_DWORD *)this + 2),
               0,
               0,
               0,
               1536,
               v3);
      }
      while ( v6 == -2005532132 );
    }
    while ( v6 == -2005532242 );
  }
  return v6;
}


// address=[0x2f87010]
// Decompiled from int __thiscall CSurfaceV3::ClearSurface(CSurfaceV3 *this, struct tagRECT a2, struct CBlitFX *a3)
long  CSurfaceV3::ClearSurface(struct tagRECT a2, class CBlitFX * a3) {
  
  CBlitFX *BlitStructPtr; // eax
  CBlitFX *v4; // eax
  int v7; // [esp+4h] [ebp-4h]

  if ( a3 )
  {
    do
    {
      do
      {
        BlitStructPtr = CBlitFX::GetBlitStructPtr(a3);
        v7 = (*(int (__stdcall **)(_DWORD, struct tagRECT *, _DWORD, _DWORD, int, CBlitFX *))(**((_DWORD **)this + 2)
                                                                                            + 20))(
               *((_DWORD *)this + 2),
               &a2,
               0,
               0,
               1536,
               BlitStructPtr);
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
        v4 = CBlitFX::GetBlitStructPtr((CBlitFX *)&s_cBlitFx);
        v7 = (*(int (__stdcall **)(_DWORD, struct tagRECT *, _DWORD, _DWORD, int, CBlitFX *))(**((_DWORD **)this + 2)
                                                                                            + 20))(
               *((_DWORD *)this + 2),
               &a2,
               0,
               0,
               1536,
               v4);
      }
      while ( v7 == -2005532132 );
    }
    while ( v7 == -2005532242 );
  }
  return v7;
}


// address=[0x2f870b0]
// Decompiled from int __thiscall CSurfaceV3::Blt(  CSurfaceV3 *this,  struct tagRECT *a2,  struct CSurface *a3,  struct tagRECT *a4,  unsigned int a5,  struct _DDBLTFX *a6)
long  CSurfaceV3::Blt(struct tagRECT * a2, class CSurface * a3, struct tagRECT * a4, unsigned long a5, struct _DDBLTFX * a6) {
  
  int v8; // [esp+4h] [ebp-4h]

  do
  {
    do
      v8 = (*(int (__stdcall **)(_DWORD, struct tagRECT *, _DWORD, struct tagRECT *, unsigned int, struct _DDBLTFX *))(**((_DWORD **)this + 2) + 20))(
             *((_DWORD *)this + 2),
             a2,
             *((_DWORD *)a3 + 2),
             a4,
             a5,
             a6);
    while ( v8 == -2005532132 );
  }
  while ( v8 == -2005532242 );
  return v8;
}


// address=[0x2f87110]
// Decompiled from int __thiscall CSurfaceV3::Flip(CSurfaceV3 *this)
long  CSurfaceV3::Flip(void) {
  
  return (*(int (__stdcall **)(_DWORD, _DWORD, int))(**((_DWORD **)this + 2) + 44))(*((_DWORD *)this + 2), 0, 1);
}


// address=[0x2f87140]
// Decompiled from int __thiscall CSurfaceV3::Lock(CSurfaceV3 *this, unsigned int *a2, void **a3, bool a4)
long  CSurfaceV3::Lock(unsigned int & a2, void * & a3, bool a4) {
  
  int v6; // [esp+8h] [ebp-4h]

  do
  {
    do
      v6 = (*(int (__stdcall **)(_DWORD, _DWORD, void *, int, _DWORD))(**((_DWORD **)this + 2) + 100))(
             *((_DWORD *)this + 2),
             0,
             &unk_46C678C,
             33,
             0);
    while ( v6 == -2005532132 );
  }
  while ( v6 == -2005532242 );
  *a2 = dword_46C679C;
  *a3 = (void *)dword_46C67B0;
  return v6;
}


// address=[0x2f871b0]
// Decompiled from int __thiscall CSurfaceV3::Unlock(CSurfaceV3 *this)
long  CSurfaceV3::Unlock(void) {
  
  return (*(int (__stdcall **)(_DWORD, _DWORD))(**((_DWORD **)this + 2) + 128))(*((_DWORD *)this + 2), 0);
}


// address=[0x2f871e0]
// Decompiled from int __thiscall CSurfaceV3::GetDC(CSurfaceV3 *this, HDC *a2)
long  CSurfaceV3::GetDC(struct HDC__ * * a2) {
  
  int v4; // [esp+4h] [ebp-4h]

  do
  {
    do
      v4 = (*(int (__stdcall **)(_DWORD, HDC *))(**((_DWORD **)this + 2) + 68))(*((_DWORD *)this + 2), a2);
    while ( v4 == -2005532132 );
  }
  while ( v4 == -2005532242 );
  return v4;
}


// address=[0x2f87220]
// Decompiled from int __thiscall CSurfaceV3::ReleaseDC(CSurfaceV3 *this, HDC a2)
long  CSurfaceV3::ReleaseDC(struct HDC__ * a2) {
  
  return (*(int (__thiscall **)(_DWORD, _DWORD, HDC))(**((_DWORD **)this + 2) + 104))(
           *((_DWORD *)this + 2),
           *((_DWORD *)this + 2),
           a2);
}


// address=[0x2f87250]
// Decompiled from int __thiscall CSurfaceV3::CreateSurface(  CSurfaceV3 *this,  void *a2,  int a3,  int a4,  bool a5,  bool a6,  bool a7,  int a8,  bool a9,  bool a10,  bool a11)
long  CSurfaceV3::CreateSurface(void * a2, int a3, int a4, bool a5, bool a6, bool a7, int a8, bool a9, bool a10, bool a11) {
  
  dword_46C6790 = 1;
  if ( a9 )
  {
    dword_46C67F4 = 512;
    if ( a11 )
    {
      dword_46C67F4 |= 0x4018u;
      dword_46C6790 |= 0x20u;
      dword_46C67A0 = 1;
    }
  }
  else
  {
    dword_46C6790 |= 0x1000u;
    dword_46C6790 |= 4u;
    dword_46C6790 |= 2u;
    dword_46C6798 = a3;
    dword_46C6794 = a4;
    dword_46C67D8 = 64;
    dword_46C67DC = 0;
    dword_46C67E0 = 16;
    if ( a8 == 1 )
    {
      dword_46C67E4 = 31744;
      dword_46C67E8 = 992;
    }
    else
    {
      dword_46C67E4 = 63488;
      dword_46C67E8 = 2016;
    }
    dword_46C67EC = 31;
    dword_46C67F0 = 0;
    if ( a7 )
    {
      if ( a8 == 2 )
      {
        dword_46C67E4 = 3840;
        dword_46C67E8 = 240;
        dword_46C67EC = 15;
        dword_46C67F0 = 61440;
        dword_46C67D8 |= 1u;
      }
      dword_46C67F4 = 4096;
    }
    else
    {
      dword_46C67F4 = 64;
    }
    if ( a5 )
      dword_46C67F4 |= 0x4000u;
    else
      dword_46C67F4 |= 0x800u;
    if ( a6 && !a7 )
      dword_46C67F4 |= 0x2000u;
    if ( a10 && a11 )
    {
      dword_46C67F4 |= 0x4018u;
      dword_46C6790 |= 0x20u;
      dword_46C67A0 = 1;
    }
  }
  return (*(int (__stdcall **)(void *, void *, char *, _DWORD))(*(_DWORD *)a2 + 24))(
           a2,
           &unk_46C678C,
           (char *)this + 8,
           0);
}


// address=[0x2f87470]
// Decompiled from int __thiscall CSurfaceV3::SetColorKey(CSurfaceV3 *this, unsigned int a2, struct _DDCOLORKEY *a3)
long  CSurfaceV3::SetColorKey(unsigned long a2, struct _DDCOLORKEY * a3) {
  
  return (*(int (__stdcall **)(_DWORD, unsigned int, struct _DDCOLORKEY *))(**((_DWORD **)this + 2) + 116))(
           *((_DWORD *)this + 2),
           a2,
           a3);
}


// address=[0x2f874a0]
// Decompiled from int __thiscall CSurfaceV3::GetPixelFormat(CSurfaceV3 *this, bool *a2)
long  CSurfaceV3::GetPixelFormat(bool & a2) {
  
  int v3; // [esp+0h] [ebp-30h]
  _DWORD v5[8]; // [esp+Ch] [ebp-24h] BYREF

  memset(v5, 0, sizeof(v5));
  v5[0] = 32;
  v3 = (*(int (__stdcall **)(_DWORD, _DWORD *))(**((_DWORD **)this + 2) + 84))(*((_DWORD *)this + 2), v5);
  *a2 = v5[5] == 992;
  CBlitFX::SetFillColor((CBlitFX *)&s_cBlitFx, 0, 0, 0, *a2);
  CBlitFX::SetFillColorAlpha((CBlitFX *)&s_cBlitFxAlpha, 0, 0, 0, 0);
  CBlitFX::SetFillColorAlpha((CBlitFX *)&s_cBlitFxAlphaDebug, 0, 255, 0, 255);
  return v3;
}


// address=[0x2f87560]
// Decompiled from int __thiscall CSurfaceV3::GetBitDepth(CSurfaceV3 *this, int *a2)
long  CSurfaceV3::GetBitDepth(int & a2) {
  
  int result; // eax
  _DWORD v4[8]; // [esp+8h] [ebp-24h] BYREF

  memset(v4, 0, sizeof(v4));
  v4[0] = 32;
  result = (*(int (__stdcall **)(_DWORD, _DWORD *))(**((_DWORD **)this + 2) + 84))(*((_DWORD *)this + 2), v4);
  *a2 = v4[3];
  return result;
}


// address=[0x2f875c0]
// Decompiled from int __thiscall CSurfaceV3::GetSurfaceSize(CSurfaceV3 *this, int *a2, int *a3)
long  CSurfaceV3::GetSurfaceSize(int & a2, int & a3) {
  
  int result; // eax

  result = (*(int (__stdcall **)(_DWORD, void *))(**((_DWORD **)this + 2) + 88))(*((_DWORD *)this + 2), &unk_46C678C);
  *a2 = dword_46C6798;
  *a3 = dword_46C6794;
  return result;
}


// address=[0x2f87610]
// Decompiled from int __thiscall CSurfaceV3::SetClipper(CSurfaceV3 *this, struct IDirectDrawClipper *a2)
long  CSurfaceV3::SetClipper(struct IDirectDrawClipper * a2) {
  
  return (*(int (__thiscall **)(_DWORD, _DWORD, struct IDirectDrawClipper *))(**((_DWORD **)this + 2) + 112))(
           *((_DWORD *)this + 2),
           *((_DWORD *)this + 2),
           a2);
}


// address=[0x2f87640]
// Decompiled from int __thiscall CSurfaceV3::GetSurfacePtr(CSurfaceV3 *this)
void *  CSurfaceV3::GetSurfacePtr(void) {
  
  return *((_DWORD *)this + 2);
}


// address=[0x2f87660]
// Decompiled from CSurfaceV3 *__thiscall CSurfaceV3::SetSurfacePtr(CSurfaceV3 *this, void *a2)
void  CSurfaceV3::SetSurfacePtr(void * a2) {
  
  CSurfaceV3 *result; // eax

  result = this;
  *((_BYTE *)this + 12) = 1;
  *((_DWORD *)this + 2) = a2;
  return result;
}


// address=[0x2f87680]
// Decompiled from int __thiscall CSurfaceV3::GetAttachedSurfacePtr(CSurfaceV3 *this)
void *  CSurfaceV3::GetAttachedSurfacePtr(void) {
  
  int v2; // [esp+0h] [ebp-10h] BYREF
  _DWORD v4[2]; // [esp+8h] [ebp-8h] BYREF

  v4[1] = this;
  v4[0] = 4;
  if ( (*(int (__stdcall **)(_DWORD, _DWORD *, int *))(**((_DWORD **)this + 2) + 48))(*((_DWORD *)this + 2), v4, &v2) )
    return 0;
  else
    return v2;
}


// address=[0x2f876c0]
// Decompiled from char __thiscall CSurfaceV3::IsBackBufferReference(CSurfaceV3 *this)
bool  CSurfaceV3::IsBackBufferReference(void) {
  
  return *((_BYTE *)this + 12);
}


// address=[0x2f876e0]
// Decompiled from int __thiscall CSurfaceV3::SetAsRenderTarget(CSurfaceV3 *this, struct IDirect3DDevice7 *a2)
long  CSurfaceV3::SetAsRenderTarget(struct IDirect3DDevice7 * a2) {
  
  return -2147467259;
}


// address=[0x2f8a320]
// Decompiled from void __thiscall CSurfaceV3::~CSurfaceV3(CSurfaceV3 *this)
 CSurfaceV3::~CSurfaceV3(void) {
  
  CSurface::~CSurface(this);
}


