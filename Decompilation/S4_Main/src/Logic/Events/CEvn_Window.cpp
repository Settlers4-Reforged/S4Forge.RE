#include "CEvn_Window.h"

// Definitions for class CEvn_Window

// address=[0x1355090]
// Decompiled from CEvn_Window *__thiscall CEvn_Window::CEvn_Window(  CEvn_Window *this,  struct HNWD *a2,  unsigned int a3,  unsigned int a4,  unsigned int a5)
CEvn_Window::CEvn_Window(HWND *a2, unsigned int a3, unsigned int a4, long a5) : CEvn_Event(a3, a4, a5, 0)
{
  this->m_hWnd = a2;
}

// address=[0x1355160]
// Decompiled from _DWORD *__thiscall CEvn_Window::~CEvn_Window(CEvn_Window *this)
//  CEvn_Window::~CEvn_Window(void) {

//   return CEvn_Event::~CEvn_Event(this);
// }
