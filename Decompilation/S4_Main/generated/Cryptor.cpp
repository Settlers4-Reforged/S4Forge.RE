#include "all_headers.h"

// Definitions for class Cryptor

// address=[0x2f029a0]
// Decompiled from Cryptor *__thiscall Cryptor::Cryptor(Cryptor *this)
 Cryptor::Cryptor(void) {
  
  std::string::string();
  *((_DWORD *)this + 7) = 324508639;
  *((_DWORD *)this + 8) = 610839776;
  *((_DWORD *)this + 9) = -38177487;
  *((_DWORD *)this + 10) = -2147483550;
  *((_DWORD *)this + 11) = 1073741856;
  *((_DWORD *)this + 12) = 268435458;
  *((_DWORD *)this + 13) = 0x7FFFFFFF;
  *((_DWORD *)this + 14) = 0x3FFFFFFF;
  *((_DWORD *)this + 15) = 0xFFFFFFF;
  *((_DWORD *)this + 16) = 0x80000000;
  *((_DWORD *)this + 17) = -1073741824;
  *((_DWORD *)this + 18) = -268435456;
  return this;
}


// address=[0x2f02a30]
// Decompiled from void __thiscall Cryptor::~Cryptor(Cryptor *this)
 Cryptor::~Cryptor(void) {
  
  std::string::~string(this);
}


// address=[0x2f02a50]
// Decompiled from void __thiscall Cryptor::Set_Key(_DWORD *this, int a2)
void  Cryptor::Set_Key(std::string const &) {
  
  char *v2; // eax
  int v3; // [esp+4h] [ebp-40h]
  int v4; // [esp+8h] [ebp-3Ch]
  int v5; // [esp+Ch] [ebp-38h]
  int v6; // [esp+10h] [ebp-34h]
  int i; // [esp+10h] [ebp-34h]
  _BYTE v9[28]; // [esp+18h] [ebp-2Ch] BYREF
  int v10; // [esp+40h] [ebp-4h]

  std::string::operator=(a2);
  std::string::string(this);
  v10 = 0;
  if ( !std::string::length(v9) )
    std::string::operator=(v9, aDefaultSeed);
  v6 = 0;
  while ( (unsigned int)std::string::length(v9) < 0xC )
  {
    v2 = (char *)std::string::operator[](v6);
    std::string::operator+=(*v2);
    ++v6;
  }
  for ( i = 0; i < 4; ++i )
  {
    v5 = this[7] << 8;
    this[7] = v5;
    this[7] = v5 | *(char *)std::string::operator[](i);
    v4 = this[8] << 8;
    this[8] = v4;
    this[8] = v4 | *(char *)std::string::operator[](i + 4);
    v3 = this[9] << 8;
    this[9] = v3;
    this[9] = v3 | *(char *)std::string::operator[](i + 8);
  }
  if ( !this[7] )
    this[7] = 324508639;
  if ( !this[8] )
    this[8] = 610839776;
  if ( !this[9] )
    this[9] = -38177487;
  v10 = -1;
  std::string::~string(v9);
}


// address=[0x2f02c10]
// Decompiled from int __thiscall Cryptor::Transform_Char(Cryptor *this, unsigned __int8 *a2)
void  Cryptor::Transform_Char(unsigned char &) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-14h]
  int v4; // [esp+4h] [ebp-10h]
  int i; // [esp+8h] [ebp-Ch]
  unsigned __int8 v6; // [esp+13h] [ebp-1h]

  v6 = 0;
  v4 = *((_DWORD *)this + 8) & 1;
  v3 = *((_DWORD *)this + 9) & 1;
  for ( i = 0; i < 8; ++i )
  {
    if ( (*((_DWORD *)this + 7) & 1) != 0 )
    {
      *((_DWORD *)this + 7) = *((_DWORD *)this + 16) | ((unsigned int)(*((_DWORD *)this + 10) ^ *((_DWORD *)this + 7)) >> 1);
      if ( (*((_DWORD *)this + 8) & 1) != 0 )
      {
        *((_DWORD *)this + 8) = *((_DWORD *)this + 17) | ((unsigned int)(*((_DWORD *)this + 11) ^ *((_DWORD *)this + 8)) >> 1);
        LOBYTE(v4) = 1;
      }
      else
      {
        *((_DWORD *)this + 8) = *((_DWORD *)this + 14) & (*((_DWORD *)this + 8) >> 1);
        LOBYTE(v4) = 0;
      }
    }
    else
    {
      *((_DWORD *)this + 7) = *((_DWORD *)this + 13) & (*((_DWORD *)this + 7) >> 1);
      if ( (*((_DWORD *)this + 9) & 1) != 0 )
      {
        *((_DWORD *)this + 9) = *((_DWORD *)this + 18) | ((unsigned int)(*((_DWORD *)this + 12) ^ *((_DWORD *)this + 9)) >> 1);
        LOBYTE(v3) = 1;
      }
      else
      {
        *((_DWORD *)this + 9) = *((_DWORD *)this + 15) & (*((_DWORD *)this + 9) >> 1);
        LOBYTE(v3) = 0;
      }
    }
    v6 = v3 ^ v4 | (2 * v6);
  }
  result = v6;
  *a2 ^= v6;
  return result;
}


// address=[0x2f02d60]
// Decompiled from int __thiscall Cryptor::Transform_File(Cryptor *this, int a2, void *a3)
void  Cryptor::Transform_File(std::string const &,std::string const &) {
  
  char *v3; // eax
  int v4; // eax
  int v6; // [esp+0h] [ebp-154h]
  _DWORD v7[46]; // [esp+4h] [ebp-150h] BYREF
  _BYTE v8[24]; // [esp+BCh] [ebp-98h] BYREF
  _BYTE v9[24]; // [esp+D4h] [ebp-80h] BYREF
  _DWORD v10[20]; // [esp+ECh] [ebp-68h] BYREF
  Cryptor *v11; // [esp+13Ch] [ebp-18h]
  int v12; // [esp+140h] [ebp-14h] BYREF
  char v13; // [esp+147h] [ebp-Dh]
  int v14; // [esp+150h] [ebp-4h]

  v11 = this;
  v12 = 88;
  v13 = 1;
  v3 = (char *)std::string::c_str(a3);
  std::ifstream::ifstream(v3, 35, 64, 1);
  v14 = 0;
  v4 = std::ifstream::rdbuf(v7);
  std::ostream::ostream(v4, 0, 1);
  LOBYTE(v14) = 1;
  if ( v13 )
  {
    Cryptor::Set_Key(a2);
    while ( 1 )
    {
      v12 = std::istream::peek(v6, v7[0]);
      if ( v12 == -1 )
        break;
      std::ios::rdbuf((CUserToolsManager *)((char *)v10 + *(_DWORD *)(v10[0] + 4)));
      std::streambuf::pubseekoff(v9, 0, 0, 1, 3);
      Cryptor::Transform_Char(v11, (unsigned __int8 *)&v12);
      std::ostream::put(v12);
      std::ifstream::rdbuf(v7);
      std::streambuf::pubseekoff(v8, 0, 0, 1, 3);
    }
  }
  LOBYTE(v14) = 0;
  std::ostream::`vbase destructor'(v10);
  v14 = -1;
  return std::ifstream::`vbase destructor'(v7);
}


// address=[0x2f02e90]
// Decompiled from int __thiscall Cryptor::Transform_String(Cryptor *this, int a2, int a3)
void  Cryptor::Transform_String(std::string const &,std::string &) {
  
  int result; // eax
  unsigned __int8 *v4; // eax
  int v6; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  Cryptor::Set_Key(a2);
  result = std::string::length(a3);
  v6 = result;
  for ( i = 0; i < v6; ++i )
  {
    v4 = (unsigned __int8 *)std::string::operator[](i);
    Cryptor::Transform_Char(this, v4);
  }
  return result;
}


// address=[0x2f02f00]
// Decompiled from int __thiscall Cryptor::Weak_Transform_Char(_DWORD *this, _BYTE *a2)
void  Cryptor::Weak_Transform_Char(unsigned char &) {
  
  int result; // eax
  char v3; // [esp+0h] [ebp-10h]
  int i; // [esp+4h] [ebp-Ch]
  unsigned __int8 v5; // [esp+Fh] [ebp-1h]

  v5 = 0;
  for ( i = 0; i < 8; ++i )
  {
    if ( (this[7] & 1) != 0 )
    {
      this[7] = this[16] | ((unsigned int)(this[10] ^ this[7]) >> 1);
      v3 = 1;
    }
    else
    {
      this[7] = this[13] & (this[7] >> 1);
      v3 = 0;
    }
    v5 = v3 | (2 * v5);
  }
  result = v5;
  *a2 ^= v5;
  return result;
}


