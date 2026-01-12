#include "CClassNetGameIniBuffer.h"

// Definitions for class CClassNetGameIniBuffer

// address=[0x15bf230]
// Decompiled from int __thiscall CClassNetGameIniBuffer::GetIntValue(char *this, char *SubStr, int a3)

int  CClassNetGameIniBuffer::GetIntValue(char const *,int) {
  
  char *EndPtr[2]; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+8h] [ebp-8h]
  char *String; // [esp+Ch] [ebp-4h]

  EndPtr[1] = this;
  v5 = a3;
  String = (char *)CClassNetGameIniBuffer::GetStartOfEntry(SubStr);
  if ( String )
    return j__strtol(String, EndPtr, 10);
  return v5;
}


// address=[0x15bf280]
// Decompiled from const char *__thiscall CClassNetGameIniBuffer::GetStartOfEntry(const char **this, char *SubStr)

char const *  CClassNetGameIniBuffer::GetStartOfEntry(char const *) {
  
  const char *Str; // [esp+4h] [ebp-4h]

  if ( !SubStr || !*SubStr )
    return 0;
  Str = j__strstr(*this, SubStr);
  if ( !Str )
    return Str;
  Str = j__strstr(Str, "=");
  if ( Str )
    ++Str;
  return Str;
}


// address=[0x15c3880]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
CClassNetGameIniBuffer *__thiscall CClassNetGameIniBuffer::CClassNetGameIniBuffer(
        CClassNetGameIniBuffer *this,
        const char *a2,
        unsigned int a3)

 CClassNetGameIniBuffer::CClassNetGameIniBuffer(char const *,unsigned int) {
  
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  return this;
}


