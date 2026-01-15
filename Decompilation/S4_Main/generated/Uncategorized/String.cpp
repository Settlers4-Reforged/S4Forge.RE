#include "String.h"

// Definitions for class String

// address=[0x13512a0]
// Decompiled from void *__thiscall String::String(void *this, int a2)
 String::String(std::string const &) {
  
  std::string::string(a2);
  return this;
}


// address=[0x13512d0]
// Decompiled from void *__thiscall String::String(void *this, char *Str, size_t Size)
 String::String(char const *,unsigned int) {
  
  void *v4; // [esp+4h] [ebp-58h]
  void *v5; // [esp+8h] [ebp-54h]
  _BYTE v7[28]; // [esp+14h] [ebp-48h] BYREF
  _BYTE v8[28]; // [esp+30h] [ebp-2Ch] BYREF
  int v9; // [esp+58h] [ebp-4h]

  std::string::string();
  v9 = 0;
  if ( !Str )
    return this;
  v5 = std::string::string(v7, Str);
  LOBYTE(v9) = 1;
  v4 = (void *)std::string::string((int)v5, 0, Size);
  std::string::operator=(this, v4);
  std::string::~string(v8);
  LOBYTE(v9) = 0;
  std::string::~string(v7);
  return this;
}


// address=[0x1351470]
// Decompiled from void __thiscall String::~String(String *this)
 String::~String(void) {
  
  std::string::erase(0);
  std::string::~string(this);
}


// address=[0x13516d0]
// Decompiled from void *__thiscall String::operator=(void *this, int a2)
class String &  String::operator=(class String const &) {
  
  std::string::operator=(a2);
  return this;
}


// address=[0x1351700]
// Decompiled from void *__thiscall String::operator=(void *this, char *Str)
class String &  String::operator=(char const *) {
  
  void *v3; // [esp+0h] [ebp-28h]
  _BYTE v5[28]; // [esp+8h] [ebp-20h] BYREF

  if ( Str )
  {
    v3 = std::string::string(v5, Str);
    std::string::operator=(this, v3);
    std::string::~string(v5);
  }
  else
  {
    std::string::operator=(this, (char *)&off_366DCF4);
  }
  return this;
}


// address=[0x1352200]
// Decompiled from int __thiscall String::c_str(String *this)
char const *  String::c_str(void)const {
  
  return std::string::c_str(this);
}


// address=[0x1369f20]
// Decompiled from String *__thiscall String::String(String *this, const struct String *a2, int a3, size_t Size)
 String::String(class String const &,unsigned int,unsigned int) {
  
  std::string::string((int)a2, a3, Size);
  return this;
}


// address=[0x1369f50]
// Decompiled from String *__thiscall String::String(String *this)
 String::String(void) {
  
  std::string::string();
  return this;
}


// address=[0x136a1b0]
// Decompiled from void *__thiscall String::operator+=(void *this, char *Str)
class String &  String::operator+=(char const *) {
  
  if ( Str )
    std::string::operator+=(Str);
  return this;
}


