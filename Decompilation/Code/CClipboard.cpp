#include "CClipboard.h"

// Definitions for class CClipboard

// address=[0x147f5e0]
// Decompiled from int __stdcall CClipboard::CopyTextToClipboard(char *Str)
void  CClipboard::CopyTextToClipboard(char const *) {
  
  int result; // eax
  LPVOID v2; // [esp+4h] [ebp-Ch]
  HGLOBAL hMem; // [esp+8h] [ebp-8h]
  int v4; // [esp+Ch] [ebp-4h]

  result = j__strlen(Str);
  v4 = result;
  if ( result <= 0 || result > 0x4000 )
    return result;
  result = OpenClipboard(0);
  if ( !result )
    return result;
  EmptyClipboard();
  hMem = GlobalAlloc(2u, v4 + 1);
  if ( !hMem )
    return CloseClipboard();
  v2 = GlobalLock(hMem);
  j__memcpy(v2, Str, v4 + 1);
  GlobalUnlock(hMem);
  SetClipboardData(1u, hMem);
  return CloseClipboard();
}


// address=[0x147f690]
// Decompiled from int __thiscall CClipboard::CopyTextToClipboard(void *this, void *a2)
void  CClipboard::CopyTextToClipboard(std::string const &) {
  
  int result; // eax
  int v3; // eax

  result = std::string::length(a2);
  if ( !result )
    return result;
  v3 = std::string::c_str(a2);
  return (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 4))(this, v3);
}


// address=[0x147f6c0]
// Decompiled from BOOL __stdcall CClipboard::GetTextFromClipboard(void *a1, int a2)
void  CClipboard::GetTextFromClipboard(std::string &,int) {
  
  BOOL result; // eax
  char *Str; // [esp+8h] [ebp-Ch]
  signed int v4; // [esp+Ch] [ebp-8h]
  signed int i; // [esp+10h] [ebp-4h]

  if ( (unsigned int)a2 > 0x4000 )
    a2 = 0x4000;
  std::string::operator=(a1, (char *)off_36BE524 + 2);
  result = OpenClipboard(0);
  if ( !result )
    return result;
  Str = (char *)GetClipboardData(1u);
  if ( !Str )
    return CloseClipboard();
  v4 = j__strlen(Str);
  if ( v4 > a2 )
    v4 = a2;
  std::string::resize(v4);
  for ( i = 0; i < v4; ++i )
    *(_BYTE *)std::string::operator[](i) = Str[i];
  return CloseClipboard();
}


// address=[0x147f7f0]
// Decompiled from CClipboard *__thiscall CClipboard::CClipboard(CClipboard *this)
 CClipboard::CClipboard(void) {
  
  IClipboard::IClipboard(this);
  *(_DWORD *)this = &CClipboard::_vftable_;
  return this;
}


