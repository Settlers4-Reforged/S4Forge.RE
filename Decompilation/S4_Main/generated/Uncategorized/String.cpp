#include "String.h"

// Definitions for class String

// address=[0x13512a0]
// Decompiled from void *__thiscall String::String(void *this, int a2)
 String::String(std::string const & a2) {
  
  ((void (__stdcall *)(int))std::string::string)(a2);
  return this;
}


// address=[0x13512d0]
// Decompiled from void *__thiscall String::String(void *this, char *Str, size_t Size)
 String::String(char const * Str, unsigned int Size) {
  
  void *v4; // [esp+4h] [ebp-58h]
  struct std::string *v5; // [esp+8h] [ebp-54h]
  std::string v7; // [esp+14h] [ebp-48h] BYREF
  _BYTE v8[28]; // [esp+30h] [ebp-2Ch] BYREF
  int v9; // [esp+58h] [ebp-4h]

  ((void (__cdecl *)())std::string::string)();
  v9 = 0;
  if ( Str != 0 )
  {
    v5 = std::string::string(&v7, Str);
    LOBYTE(v9) = 1;
    v4 = (void *)std::string::string((int)v5, 0, Size);
    std::string::operator=(this, v4);
    std::string::~string(v8);
    LOBYTE(v9) = 0;
    std::string::~string(&v7);
  }
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
class String &  String::operator=(class String const & a2) {
  
  ((void (__stdcall *)(int))std::string::operator=)(a2);
  return this;
}


// address=[0x1351700]
// Decompiled from std::string *__thiscall String::operator=(std::string *this, char *Str)
class String &  String::operator=(char const * Str) {
  
  struct std::string *v3; // [esp+0h] [ebp-28h]
  std::string v5; // [esp+8h] [ebp-20h] BYREF

  if ( Str != 0 )
  {
    v3 = std::string::string(&v5, Str);
    std::string::operator=(this, v3);
    std::string::~string(&v5);
  }
  else
  {
    std::string::operator=(this, (char *)&off_366DCF4);
  }
  return this;
}


// address=[0x1352200]
// Decompiled from int __thiscall String::c_str(std::string *this)
char const *  String::c_str(void)const {
  
  return (int)std::string::c_str(this);
}


// address=[0x1369f20]
// Decompiled from String *__thiscall String::String(String *this, const struct String *a2, int a3, size_t Size)
 String::String(class String const & a2, unsigned int a3, unsigned int Size) {
  
  std::string::string((int)a2, a3, Size);
  return this;
}


// address=[0x1369f50]
// Decompiled from String *__thiscall String::String(String *this)
 String::String(void) {
  
  ((void (__cdecl *)())std::string::string)();
  return this;
}


// address=[0x136a1b0]
// Decompiled from void *__thiscall String::operator+=(void *this, char *Str)
class String &  String::operator+=(char const * Str) {
  
  if ( Str != 0 )
  {
    std::string::operator+=(Str);
  }
  return this;
}


