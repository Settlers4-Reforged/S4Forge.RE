#include "all_headers.h"

// Definitions for class SurfaceClipper

// address=[0x2f5f370]
// Decompiled from int __thiscall SurfaceClipper::GetClipper(SurfaceClipper *this)
struct IDirectDrawClipper *  SurfaceClipper::GetClipper(void) {
  
  return *(_DWORD *)this;
}


// address=[0x2f8a460]
// Decompiled from SurfaceClipper *__thiscall SurfaceClipper::SurfaceClipper(SurfaceClipper *this)
 SurfaceClipper::SurfaceClipper(void) {
  
  SurfaceClipper *v2; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h]

  *(_DWORD *)this = 0;
  std::vector<char>::vector<char>((int)this, savedregs);
  return v2;
}


// address=[0x2f8a490]
// Decompiled from int __thiscall SurfaceClipper::~SurfaceClipper(SurfaceClipper *this)
 SurfaceClipper::~SurfaceClipper(void) {
  
  SurfaceClipper::ReleaseClipper(this);
  return std::vector<char>::~vector<char>();
}


// address=[0x2f8a4e0]
// Decompiled from HRESULT __thiscall SurfaceClipper::InitClipper(SurfaceClipper *this, struct IDirectDraw7 *a2)
long  SurfaceClipper::InitClipper(struct IDirectDraw7 *) {
  
  SurfaceClipper::ReleaseClipper(this);
  return a2->lpVtbl->CreateClipper(a2, 0, (LPDIRECTDRAWCLIPPER *)this, 0);
}


// address=[0x2f8a510]
// Decompiled from int __thiscall SurfaceClipper::InitClipper_0(SurfaceClipper *this, int a2)
long  SurfaceClipper::InitClipper(struct IDirectDraw *) {
  
  SurfaceClipper::ReleaseClipper(this);
  return (*(int (__stdcall **)(int, _DWORD, SurfaceClipper *, _DWORD))(*(_DWORD *)a2 + 16))(a2, 0, this, 0);
}


// address=[0x2f8a540]
// Decompiled from SurfaceClipper *__thiscall SurfaceClipper::ReleaseClipper(SurfaceClipper *this)
void  SurfaceClipper::ReleaseClipper(void) {
  
  SurfaceClipper *result; // eax

  result = this;
  if ( !*(_DWORD *)this )
    return result;
  result = (SurfaceClipper *)(*(int (__stdcall **)(_DWORD))(**(_DWORD **)this + 8))(*(_DWORD *)this);
  *(_DWORD *)this = 0;
  return result;
}


// address=[0x2f8a570]
// Decompiled from int __thiscall SurfaceClipper::SetClipRect(_DWORD *this, _DWORD *Src)
long  SurfaceClipper::SetClipRect(struct tagRECT const &) {
  
  _DWORD *v4; // [esp+8h] [ebp-4h]

  std::vector<char>::resize(52);
  v4 = (_DWORD *)std::vector<char>::front();
  *v4 = 32;
  v4[1] = 1;
  v4[2] = 1;
  v4[3] = 16;
  v4[4] = *Src;
  v4[5] = Src[1];
  v4[6] = Src[2];
  v4[7] = Src[3];
  j__memcpy(v4 + 8, Src, 0x10u);
  return (*(int (__stdcall **)(_DWORD, _DWORD *, _DWORD))(*(_DWORD *)*this + 28))(*this, v4, 0);
}


// address=[0x2f8a620]
// Decompiled from int __thiscall SurfaceClipper::SetClipWindow(SurfaceClipper *this, HWND a2)
long  SurfaceClipper::SetClipWindow(struct HWND__ *) {
  
  return (*(int (__thiscall **)(_DWORD, _DWORD, _DWORD, HWND))(**(_DWORD **)this + 32))(
           *(_DWORD *)this,
           *(_DWORD *)this,
           0,
           a2);
}


