#include "CConfigSection.h"

// Definitions for class CConfigSection

// address=[0x2eef260]
// Decompiled from char *__thiscall CConfigSection::CConfigSection(char *this, int a2)
 CConfigSection::CConfigSection(std::string const &) {
  
  std::string::string();
  std::map<std::string,CConfigVar *>::map<std::string,CConfigVar *>(this + 28);
  std::string::operator=(a2);
  return this;
}


// address=[0x2eef2d0]
// Decompiled from void __thiscall sub_32EF2D0(void *this)
 CConfigSection::~CConfigSection(void) {
  
  int v1; // eax
  std::_Iterator_base12 *v2; // eax
  _BYTE v3[12]; // [esp+4h] [ebp-48h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-3Ch] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-30h] BYREF
  int v6; // [esp+28h] [ebp-24h]
  int v7; // [esp+2Ch] [ebp-20h]
  int v8; // [esp+30h] [ebp-1Ch]
  int v9; // [esp+34h] [ebp-18h]
  void *v10; // [esp+38h] [ebp-14h]
  char v11; // [esp+3Fh] [ebp-Dh]

  v10 = this;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v5);
  v1 = std::_Tree<std::_Tmap_traits<std::string,CConfigVar *,std::less<std::string>,std::allocator<std::pair<std::string const,CConfigVar *>>,0>>::begin(v4);
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator=(v1);
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v4);
  while ( 1 )
  {
    v2 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<std::string,CConfigVar *,std::less<std::string>,std::allocator<std::pair<std::string const,CConfigVar *>>,0>>::end(v3);
    v11 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator!=(v2);
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v3);
    if ( !v11 )
      break;
    v9 = *(_DWORD *)(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator*(v5)
                   + 28);
    if ( v9 && !(unsigned __int8)CConfigVar::Static(v9) )
    {
      v7 = v9;
      v8 = v9;
      if ( v9 )
        v6 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v8 + 36))(v8, 1);
      else
        v6 = 0;
      *(_DWORD *)(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator*(v5)
                + 28) = 0;
    }
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator++(v5);
  }
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v5);
  std::_Tree<std::_Tmap_traits<std::string,CConfigVar *,std::less<std::string>,std::allocator<std::pair<std::string const,CConfigVar *>>,0>>::clear();
  std::map<std::string,CConfigVar *>::~map<std::string,CConfigVar *>((char *)v10 + 28);
  std::string::~string(v10);
}


// address=[0x2eef3f0]
// Decompiled from char __thiscall CConfigSection::VarExists(void *this, int a2)
bool  CConfigSection::VarExists(std::string const &) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-34h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-28h] BYREF
  std::_Iterator_base12 *v5; // [esp+1Ch] [ebp-1Ch]
  std::_Iterator_base12 *v6; // [esp+20h] [ebp-18h]
  void *v7; // [esp+24h] [ebp-14h]
  char v8; // [esp+2Bh] [ebp-Dh]
  int v9; // [esp+34h] [ebp-4h]

  v7 = this;
  std::_Tree<std::_Tmap_traits<std::string,CConfigVar *,std::less<std::string>,std::allocator<std::pair<std::string const,CConfigVar *>>,0>>::find(
    v4,
    a2);
  v9 = 0;
  v6 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<std::string,CConfigVar *,std::less<std::string>,std::allocator<std::pair<std::string const,CConfigVar *>>,0>>::end((int)v3);
  v5 = v6;
  LOBYTE(v9) = 1;
  v8 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator!=(v6);
  LOBYTE(v9) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v3);
  v9 = -1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v4);
  return v8;
}


// address=[0x2eef490]
// Decompiled from int *__stdcall CConfigSection::AddVar(int a1, void *Src, int a3)
void  CConfigSection::AddVar(std::string const &,int const *,int) {
  
  int *result; // eax
  int v4; // [esp+Ch] [ebp-1Ch]
  void *v5; // [esp+14h] [ebp-14h]
  CConfigVar *Var; // [esp+18h] [ebp-10h]

  Var = (CConfigVar *)CConfigSection::GetVar(a1);
  if ( Var )
  {
    if ( CConfigVar::Type(Var) == 2 && CConfigVar::Size(Var) == a3 )
    {
      v5 = (void *)(*(int (__thiscall **)(CConfigVar *))(*(_DWORD *)Var + 16))(Var);
      if ( v5 )
      {
        if ( Src )
          return (int *)j__memcpy(v5, Src, 4 * a3);
        else
          return (int *)memset(v5, 0, 4 * a3);
      }
      else
      {
        result = (int *)BBSupportDbgReport(
                          1,
                          "Source\\ConfigManager\\ConfigManager.cpp",
                          254,
                          "CConfigSection::AddVar() [int array]: Invalid int array pointer!");
        if ( result == (int *)1 )
          __debugbreak();
      }
    }
    else
    {
      if ( BBSupportDbgReport(
             1,
             "Source\\ConfigManager\\ConfigManager.cpp",
             259,
             "CConfigSection::AddVar() [int array]: Config var type / size mismatch!") == 1 )
        __debugbreak();
      return 0;
    }
  }
  else
  {
    if ( operator new(0xCu, 1, "Source\\ConfigManager\\ConfigManager.cpp", 231) )
      v4 = CConfigVarIntArray::CConfigVarIntArray(Src, a3);
    else
      v4 = 0;
    result = (int *)std::map<std::string,CConfigVar *>::operator[](a1);
    *result = v4;
  }
  return result;
}


// address=[0x2eef600]
// Decompiled from CConfigVarInt **__stdcall CConfigSection::AddVar(int a1, int a2)
void  CConfigSection::AddVar(std::string const &,int) {
  
  CConfigVarInt **result; // eax
  CConfigVarInt *v3; // [esp+Ch] [ebp-18h]
  CConfigVarInt *C; // [esp+10h] [ebp-14h]
  int Var; // [esp+14h] [ebp-10h]

  Var = CConfigSection::GetVar(a1);
  if ( Var )
    return (CConfigVarInt **)(*(int (__thiscall **)(int, int))(*(_DWORD *)Var + 32))(Var, a2);
  C = (CConfigVarInt *)operator new(0xCu, 1, "Source\\ConfigManager\\ConfigManager.cpp", 277);
  if ( C )
    v3 = CConfigVarInt::CConfigVarInt(C, a2);
  else
    v3 = 0;
  result = (CConfigVarInt **)std::map<std::string,CConfigVar *>::operator[](a1);
  *result = v3;
  return result;
}


// address=[0x2eef6d0]
// Decompiled from CConfigVarFloat **__stdcall CConfigSection::AddVar(int a1, float a2)
void  CConfigSection::AddVar(std::string const &,float) {
  
  CConfigVarFloat **result; // eax
  CConfigVarFloat *v3; // [esp+10h] [ebp-18h]
  CConfigVarFloat *C; // [esp+14h] [ebp-14h]
  int Var; // [esp+18h] [ebp-10h]

  Var = CConfigSection::GetVar(a1);
  if ( Var )
    return (CConfigVarFloat **)(*(int (__thiscall **)(int, float))(*(_DWORD *)Var + 28))(Var, COERCE_FLOAT(LODWORD(a2)));
  C = (CConfigVarFloat *)operator new(0xCu, 1, "Source\\ConfigManager\\ConfigManager.cpp", 300);
  if ( C )
    v3 = CConfigVarFloat::CConfigVarFloat(C, a2);
  else
    v3 = 0;
  result = (CConfigVarFloat **)std::map<std::string,CConfigVar *>::operator[](a1);
  *result = v3;
  return result;
}


// address=[0x2eef7b0]
// Decompiled from _DWORD *__stdcall CConfigSection::AddVar(int a1, int a2)
void  CConfigSection::AddVar(std::string const &,std::string const &) {
  
  _DWORD *result; // eax
  int v3; // [esp+Ch] [ebp-18h]
  int Var; // [esp+14h] [ebp-10h]

  Var = CConfigSection::GetVar(a1);
  if ( Var )
    return (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)Var + 20))(Var, a2);
  if ( operator new(0x24u, 1, "Source\\ConfigManager\\ConfigManager.cpp", 323) )
    v3 = CConfigVarString::CConfigVarString(a2);
  else
    v3 = 0;
  result = (_DWORD *)std::map<std::string,CConfigVar *>::operator[](a1);
  *result = v3;
  return result;
}


// address=[0x2eef880]
// Decompiled from _DWORD *__stdcall CConfigSection::AddStaticConfigVar(int a1, int a2)
void  CConfigSection::AddStaticConfigVar(std::string const &,class CConfigVar &) {
  
  _DWORD *result; // eax

  if ( CConfigSection::GetVar(a1) )
  {
    if ( BBSupportDbgReport(
           1,
           "Source\\ConfigManager\\ConfigManager.cpp",
           348,
           "CConfigSection::AddStaticConfigVar(): Static config var already exists!") == 1 )
      __debugbreak();
    return 0;
  }
  else
  {
    result = (_DWORD *)std::map<std::string,CConfigVar *>::operator[](a1);
    *result = a2;
  }
  return result;
}


// address=[0x2eef8e0]
// Decompiled from char __thiscall CConfigSection::Save(void *this, wchar_t *FileName)
bool  CConfigSection::Save(wchar_t const *) {
  
  size_t v2; // eax
  const char *v3; // eax
  size_t v4; // eax
  int v5; // eax
  void *v6; // eax
  const char *v7; // eax
  void *v8; // eax
  const char *v9; // eax
  size_t v10; // eax
  size_t v11; // eax
  size_t v12; // eax
  void *v13; // eax
  const char *v14; // eax
  void *v15; // eax
  const char *v16; // eax
  size_t v17; // eax
  double v19; // [esp+0h] [ebp-310h]
  int v20; // [esp+4h] [ebp-30Ch]
  int v21; // [esp+4h] [ebp-30Ch]
  const char *v22; // [esp+4h] [ebp-30Ch]
  int v23; // [esp+8h] [ebp-308h] BYREF
  _BYTE v24[12]; // [esp+18h] [ebp-2F8h] BYREF
  _BYTE v25[12]; // [esp+24h] [ebp-2ECh] BYREF
  _BYTE v26[12]; // [esp+30h] [ebp-2E0h] BYREF
  void *v27; // [esp+3Ch] [ebp-2D4h]
  std::_Iterator_base12 *v28; // [esp+40h] [ebp-2D0h]
  std::_Iterator_base12 *v29; // [esp+44h] [ebp-2CCh]
  int v30; // [esp+48h] [ebp-2C8h]
  int v31; // [esp+4Ch] [ebp-2C4h]
  _BYTE v32[12]; // [esp+50h] [ebp-2C0h] BYREF
  int v33; // [esp+5Ch] [ebp-2B4h]
  void *v34; // [esp+60h] [ebp-2B0h]
  int v35; // [esp+64h] [ebp-2ACh]
  int i; // [esp+68h] [ebp-2A8h]
  int v37; // [esp+6Ch] [ebp-2A4h]
  size_t ElementSize; // [esp+70h] [ebp-2A0h]
  char v39; // [esp+75h] [ebp-29Bh]
  char v40; // [esp+76h] [ebp-29Ah]
  CConfigVar *v41; // [esp+78h] [ebp-298h]
  _BYTE v42[28]; // [esp+7Ch] [ebp-294h] BYREF
  _BYTE v43[28]; // [esp+98h] [ebp-278h] BYREF
  char v44[72]; // [esp+B4h] [ebp-25Ch] BYREF
  char Str[512]; // [esp+FCh] [ebp-214h] BYREF
  int *v46; // [esp+300h] [ebp-10h]
  int v47; // [esp+30Ch] [ebp-4h]

  v46 = &v23;
  v34 = this;
  CFile::CFile((CFile *)v44);
  v47 = 1;
  ElementSize = 1;
  CFile::Open(FileName, 10, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h", 0);
  v47 = 0;
  j__sprintf(Str, "//\r\n// Automatically generated file. Do not edit!\r\n// \r\n\r\n");
  v2 = j__strlen(Str);
  CFile::Write(Str, ElementSize, v2, (int)"D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h", 0);
  v3 = (const char *)std::string::c_str(v34);
  j___snprintf(Str, 0x1FFu, "[%s]\r\n{\r\n", v3);
  v4 = j__strlen(Str);
  CFile::Write(Str, ElementSize, v4, (int)"D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h", 0);
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v32);
  LOBYTE(v47) = 3;
  v31 = std::_Tree<std::_Tmap_traits<std::string,CConfigVar *,std::less<std::string>,std::allocator<std::pair<std::string const,CConfigVar *>>,0>>::begin((int)v26);
  v30 = v31;
  LOBYTE(v47) = 4;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator=(v31);
  LOBYTE(v47) = 3;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v26);
  std::string::string();
  LOBYTE(v47) = 5;
  while ( 1 )
  {
    v29 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<std::string,CConfigVar *,std::less<std::string>,std::allocator<std::pair<std::string const,CConfigVar *>>,0>>::end((int)v25);
    v28 = v29;
    LOBYTE(v47) = 6;
    v40 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator!=(v29);
    LOBYTE(v47) = 5;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v25);
    if ( !v40 )
      break;
    v41 = *(CConfigVar **)(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator*(v32)
                         + 28);
    v5 = CConfigVar::Type(v41);
    v37 = v5 - 1;
    switch ( v5 )
    {
      case 1:
        v20 = (**(int (__thiscall ***)(CConfigVar *))v41)(v41);
        v6 = (void *)std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator*(v32);
        v7 = (const char *)std::string::c_str(v6);
        j__sprintf(Str, "    %s = %d\r\n", v7, v20);
        break;
      case 2:
        v33 = (*(int (__thiscall **)(CConfigVar *))(*(_DWORD *)v41 + 16))(v41);
        v35 = CConfigVar::Size(v41);
        if ( v33 && v35 > 0 )
        {
          v21 = v35;
          v8 = (void *)std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator*(v32);
          v9 = (const char *)std::string::c_str(v8);
          j__sprintf(Str, "    %s[%d] = ", v9, v21);
          v10 = j__strlen(Str);
          CFile::Write(
            Str,
            ElementSize,
            v10,
            (int)"D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h",
            0);
          for ( i = 0; i < v35 - 1; ++i )
          {
            j__sprintf(Str, "%d,", *(_DWORD *)(v33 + 4 * i));
            v11 = j__strlen(Str);
            CFile::Write(
              Str,
              ElementSize,
              v11,
              (int)"D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h",
              0);
          }
          j__sprintf(Str, "%d", *(_DWORD *)(v33 + 4 * v35 - 4));
          v12 = j__strlen(Str);
          CFile::Write(
            Str,
            ElementSize,
            v12,
            (int)"D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h",
            0);
          j__sprintf(Str, "\r\n");
        }
        break;
      case 3:
        v19 = ((double (__thiscall *)(CConfigVar *))*(_DWORD *)(*(_DWORD *)v41 + 4))(v41);
        v13 = (void *)std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator*(v32);
        v14 = (const char *)std::string::c_str(v13);
        j__sprintf(Str, "    %s = %f\r\n", v14, v19);
        break;
      case 4:
        v27 = (void *)(*(int (__thiscall **)(CConfigVar *, _BYTE *))(*(_DWORD *)v41 + 8))(v41, v42);
        std::string::operator=(v43, v27);
        std::string::~string(v42);
        v22 = (const char *)std::string::c_str(v43);
        v15 = (void *)std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator*(v32);
        v16 = (const char *)std::string::c_str(v15);
        j__sprintf(Str, "    %s = \"%s\"\r\n", v16, v22);
        break;
      default:
        j__sprintf(Str, &byte_3AB2CAF);
        break;
    }
    v17 = j__strlen(Str);
    CFile::Write(Str, ElementSize, v17, (int)"D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h", 0);
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator++(
      v24,
      0);
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v24);
  }
  CFile::Write("}\r\n", ElementSize, 1u, (int)"D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h", 0);
  CFile::Close((CFile *)v44, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h", 0);
  v39 = 1;
  LOBYTE(v47) = 3;
  std::string::~string(v43);
  LOBYTE(v47) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v32);
  v47 = -1;
  CFile::~CFile();
  return v39;
}


// address=[0x2efa130]
// Decompiled from int __thiscall CConfigSection::GetVar(void *this, int a2)
class CConfigVar *  CConfigSection::GetVar(std::string const &) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-3Ch] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-30h] BYREF
  int v5; // [esp+1Ch] [ebp-24h]
  int v6; // [esp+20h] [ebp-20h]
  std::_Iterator_base12 *v7; // [esp+24h] [ebp-1Ch]
  std::_Iterator_base12 *v8; // [esp+28h] [ebp-18h]
  void *v9; // [esp+2Ch] [ebp-14h]
  char v10; // [esp+33h] [ebp-Dh]
  int v11; // [esp+3Ch] [ebp-4h]

  v9 = this;
  std::_Tree<std::_Tmap_traits<std::string,CConfigVar *,std::less<std::string>,std::allocator<std::pair<std::string const,CConfigVar *>>,0>>::find(
    v4,
    a2);
  v11 = 0;
  v8 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<std::string,CConfigVar *,std::less<std::string>,std::allocator<std::pair<std::string const,CConfigVar *>>,0>>::end((int)v3);
  v7 = v8;
  LOBYTE(v11) = 1;
  v10 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator!=(v8);
  LOBYTE(v11) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v3);
  if ( v10 )
  {
    v6 = *(_DWORD *)(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::operator*(v4)
                   + 28);
    v11 = -1;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v4);
    return v6;
  }
  else
  {
    v5 = 0;
    v11 = -1;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,CConfigVar *>>>>(v4);
    return v5;
  }
}


// address=[0x2efa250]
// Decompiled from void *__thiscall CConfigSection::Name(void *this)
std::string const &  CConfigSection::Name(void) {
  
  return this;
}


// address=[0x2efa270]
// Decompiled from int __thiscall CConfigSection::NumberOfEntries(CConfigSection *this)
int  CConfigSection::NumberOfEntries(void) {
  
  return std::_Tree<std::_Tmap_traits<std::string,CConfigVar *,std::less<std::string>,std::allocator<std::pair<std::string const,CConfigVar *>>,0>>::size(
           (char *)this + 28,
           this);
}


