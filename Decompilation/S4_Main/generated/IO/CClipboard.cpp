#if FALSE
#include "CClipboard.h"

// Definitions for class CClipboard

// address=[0x147f5e0]
// Decompiled from void __stdcall CClipboard::CopyTextToClipboard(char *Str)
void  CClipboard::CopyTextToClipboard(char const * Str) {
  
  LPVOID v1; // [esp+4h] [ebp-Ch]
  HGLOBAL hMem; // [esp+8h] [ebp-8h]
  signed int v3; // [esp+Ch] [ebp-4h]

  v3 = strlen(Str);
  if ( v3 > 0 && v3 <= 0x4000 && OpenClipboard(0) )
  {
    EmptyClipboard();
    hMem = GlobalAlloc(2u, v3 + 1);
    if ( hMem )
    {
      v1 = GlobalLock(hMem);
      j__memcpy(v1, Str, v3 + 1);
      GlobalUnlock(hMem);
      SetClipboardData(1u, hMem);
    }
    CloseClipboard();
  }
}


// address=[0x147f690]
// Decompiled from void __thiscall CClipboard::CopyTextToClipboard(CClipboard *this, void *a2)
void  CClipboard::CopyTextToClipboard(std::string const & a2) {
  
  int v2; // eax

  if ( std::string::length(a2) )
  {
    v2 = std::string::c_str(a2);
    this->CopyTextToClipboard(this, v2);
  }
}


// address=[0x147f6c0]
// Decompiled from void __stdcall CClipboard::GetTextFromClipboard(void *a1, unsigned int a2)
void  CClipboard::GetTextFromClipboard(std::string & a1, int a2) {
  
  char *Str; // [esp+8h] [ebp-Ch]
  signed int v3; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]

  if ( a2 > 0x4000 )
    a2 = 0x4000;
  std::string::operator=(a1, (char *)&off_36BE524 + 2);
  if ( OpenClipboard(0) )
  {
    Str = (char *)GetClipboardData(CF_TEXT);
    if ( Str )
    {
      v3 = strlen(Str);
      if ( v3 > (int)a2 )
        v3 = a2;
      std::string::resize(a1, v3);
      for ( i = 0; i < v3; ++i )
        *(_BYTE *)std::string::operator[](i) = Str[i];
    }
    CloseClipboard();
  }
}


// address=[0x147f7f0]
// Decompiled from CClipboard *__thiscall CClipboard::CClipboard(CClipboard *this)
 CClipboard::CClipboard(void) {
  
  IClipboard::IClipboard(this);
  *(_DWORD *)this = &CClipboard::_vftable_;
  return this;
}


#endif // Already implemented
