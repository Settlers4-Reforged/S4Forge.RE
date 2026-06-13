#if FALSE
#include "CClassNetGameIniBuffer.h"

// Definitions for class CClassNetGameIniBuffer

// address=[0x15bf230]
// Decompiled from int __thiscall CClassNetGameIniBuffer::GetIntValue(CClassNetGameIniBuffer *this, char *SubStr, int a3)
int  CClassNetGameIniBuffer::GetIntValue(char const * SubStr, int a3) {
  
  int EndPtr; // [esp+0h] [ebp-10h] BYREF
  int v6; // [esp+8h] [ebp-8h]
  char *String; // [esp+Ch] [ebp-4h]

  v6 = a3;
  String = (char *)CClassNetGameIniBuffer::GetStartOfEntry(this, SubStr);
  if ( String )
    return j__strtol(String, (char **)&EndPtr, 10);
  return v6;
}


// address=[0x15bf280]
// Decompiled from const char *__thiscall CClassNetGameIniBuffer::GetStartOfEntry(CClassNetGameIniBuffer *this, char *SubStr)
char const *  CClassNetGameIniBuffer::GetStartOfEntry(char const * SubStr) {
  
  const char *Str; // [esp+4h] [ebp-4h]

  if ( !SubStr || !*SubStr )
    return 0;
  Str = j__strstr(this->m_spBuffer, SubStr);
  if ( !Str )
    return Str;
  Str = j__strstr(Str, "=");
  if ( Str )
    ++Str;
  return Str;
}


// address=[0x15c3880]
// Decompiled from CClassNetGameIniBuffer *__thiscall CClassNetGameIniBuffer::CClassNetGameIniBuffer(  CClassNetGameIniBuffer *this,  const char *a2,  unsigned int a3)
 CClassNetGameIniBuffer::CClassNetGameIniBuffer(char const * a2, unsigned int a3) {
  
  this->m_spBuffer = a2;
  this->m_uFileSize = a3;
  return this;
}


#endif // Already implemented
