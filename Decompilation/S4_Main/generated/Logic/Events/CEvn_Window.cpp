#if FALSE
#include "CEvn_Window.h"

// Definitions for class CEvn_Window

// address=[0x1355090]
// Decompiled from CEvn_Window *__thiscall CEvn_Window::CEvn_Window(  CEvn_Window *this,  struct HNWD *a2,  unsigned int a3,  unsigned int a4,  unsigned int a5)
 CEvn_Window::CEvn_Window(struct HWND__ * a2, unsigned int a3, unsigned int a4, long a5) {
  
  CEvn_Event::CEvn_Event(this, a3, a4, a5, 0);
  this->__vftable = (CEvn_Event_vtbl *)CEvn_Window::_vftable_;
  this->m_hWnd = a2;
  return this;
}


// address=[0x1355160]
// Decompiled from _DWORD *__thiscall CEvn_Window::~CEvn_Window(CEvn_Window *this)
 CEvn_Window::~CEvn_Window(void) {
  
  return CEvn_Event::~CEvn_Event(this);
}


#endif // Already implemented
