#include "CClipboard.h"

#include <windows.h>

// Definitions for class CClipboard

// address=[0x147f5e0]
// Decompiled from int __stdcall CClipboard::CopyTextToClipboard(char *Str)
void CClipboard::CopyTextToClipboard(char const *Str)
{
  LPVOID v1;     // [esp+4h] [ebp-Ch]
  HGLOBAL hMem;  // [esp+8h] [ebp-8h]
  signed int v3; // [esp+Ch] [ebp-4h]

  v3 = strlen(Str);
  if (v3 > 0 && v3 <= 0x4000 && OpenClipboard(0))
  {
    EmptyClipboard();
    hMem = GlobalAlloc(2u, v3 + 1);
    if (hMem)
    {
      v1 = GlobalLock(hMem);
      memcpy(v1, Str, v3 + 1);
      GlobalUnlock(hMem);
      SetClipboardData(1u, hMem);
    }
    CloseClipboard();
  }
}

// address=[0x147f690]
// Decompiled from int __thiscall CClipboard::CopyTextToClipboard(void *this, void *a2)
void CClipboard::CopyTextToClipboard(std::string const &a2)
{
  if (a2.length() > 0)
  {
    this->CopyTextToClipboard(a2.c_str());
  }
}

// address=[0x147f6c0]
// Decompiled from BOOL __stdcall CClipboard::GetTextFromClipboard(void *a1, int a2)
void CClipboard::GetTextFromClipboard(std::string &a1, int a2)
{

  if ( a2 > 0x4000 )
    a2 = 0x4000;
  //std::string::operator=(a1, (char *)off_36BE524 + 2); ???
  if ( OpenClipboard(0) )
  {
    char *Str = static_cast<char*>(GetClipboardData(CF_TEXT));
    if ( Str )
    {
      int clipboardLength = strlen(Str);
      if ( clipboardLength > a2 )
        clipboardLength = a2;
      a1.resize(clipboardLength);
      for ( int i = 0; i < clipboardLength; ++i )
        a1[i] = Str[i];
    }
    CloseClipboard();
  }
}

// address=[0x147f7f0]
// Decompiled from CClipboard *__thiscall CClipboard::CClipboard(CClipboard *this)
CClipboard::CClipboard(void) : IClipboard() {}
