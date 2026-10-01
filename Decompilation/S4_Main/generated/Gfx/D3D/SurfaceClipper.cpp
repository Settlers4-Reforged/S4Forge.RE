#if FALSE
#include "SurfaceClipper.h"

// Definitions for class SurfaceClipper

// address=[0x2f5f370]
// Decompiled from LPDIRECTDRAWCLIPPER __thiscall SurfaceClipper::GetClipper(SurfaceClipper *this)
struct IDirectDrawClipper *  SurfaceClipper::GetClipper(void) {
  
  return this->m_pClipper;
}


// address=[0x2f8a460]
// Decompiled from SurfaceClipper *__thiscall SurfaceClipper::SurfaceClipper(SurfaceClipper *this)
 SurfaceClipper::SurfaceClipper(void) {
  
  this->m_pClipper = 0;
  std::vector<char>::vector<char>(&this->m_vChar);
  return this;
}


// address=[0x2f8a490]
// Decompiled from int __thiscall SurfaceClipper::~SurfaceClipper(SurfaceClipper *this)
 SurfaceClipper::~SurfaceClipper(void) {
  
  SurfaceClipper::ReleaseClipper(this);
  return std::vector<char>::~vector<char>();
}


// address=[0x2f8a4e0]
// Decompiled from HRESULT __thiscall SurfaceClipper::InitClipper(SurfaceClipper *this, struct IDirectDraw7 *a2)
long  SurfaceClipper::InitClipper(struct IDirectDraw7 * a2) {
  
  SurfaceClipper::ReleaseClipper(this);
  return a2->lpVtbl->CreateClipper(a2, 0, (LPDIRECTDRAWCLIPPER *)this, nullptr);
}


// address=[0x2f8a510]
// Decompiled from HRESULT __thiscall SurfaceClipper::InitClipper_0(SurfaceClipper *this, IDirectDraw *a2)
long  SurfaceClipper::InitClipper(struct IDirectDraw * a2) {
  
  SurfaceClipper::ReleaseClipper(this);
  return a2->lpVtbl->CreateClipper(a2, 0, (LPDIRECTDRAWCLIPPER *)this, nullptr);
}


// address=[0x2f8a540]
// Decompiled from void __thiscall SurfaceClipper::ReleaseClipper(SurfaceClipper *this)
void  SurfaceClipper::ReleaseClipper(void) {
  
  if ( this->m_pClipper != nullptr )
  {
    this->m_pClipper->lpVtbl->Release(this->m_pClipper);
    this->m_pClipper = nullptr;
  }
}


// address=[0x2f8a570]
// Decompiled from HRESULT __thiscall SurfaceClipper::SetClipRect(SurfaceClipper *this, const tagRECT *Src)
long  SurfaceClipper::SetClipRect(struct tagRECT const & Src) {
  
  LPRGNDATA v4; // [esp+8h] [ebp-4h]

  std::vector<char>::resize(&this->m_vChar, 0x34u);
  v4 = (LPRGNDATA)std::vector<char>::front(&this->m_vChar);
  v4->rdh.dwSize = 32;
  v4->rdh.iType = 1;
  v4->rdh.nCount = 1;
  v4->rdh.nRgnSize = 16;
  v4->rdh.rcBound = *Src;
  *(tagRECT *)v4->Buffer = *Src;
  return this->m_pClipper->lpVtbl->SetClipList(this->m_pClipper, v4, 0);
}


// address=[0x2f8a620]
// Decompiled from HRESULT __thiscall SurfaceClipper::SetClipWindow(SurfaceClipper *this, HWND *a2)
long  SurfaceClipper::SetClipWindow(struct HWND__ * a2) {
  
  return this->m_pClipper->lpVtbl->SetHWnd(this->m_pClipper, 0, (HWND)a2);
}


#endif // Already implemented
