#include "CEvn_Window.h"

// Definitions for class CEvn_Window

// address=[0x1355090]
// Decompiled from CEvn_Window *__thiscall CEvn_Window::CEvn_Window(
        CEvn_Window *this,
        HWND a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)

 CEvn_Window::CEvn_Window(struct HWND__ *,unsigned int,unsigned int,long) {
  
  CEvn_Event::CEvn_Event((CEvn_Event *)this, a3, a4, a5, 0);
  *(_DWORD *)this = CEvn_Window::_vftable_;
  *((_DWORD *)this + 6) = a2;
  return this;
}


// address=[0x1355160]
// Decompiled from _DWORD *__thiscall CEvn_Window::~CEvn_Window(CEvn_Window *this)

 CEvn_Window::~CEvn_Window(void) {
  
  return CEvn_Event::~CEvn_Event(this);
}


