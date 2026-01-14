#include "all_headers.h"

// Definitions for class CConfigManager

// address=[0x2ef1280]
// Decompiled from int __thiscall sub_32F1280(_DWORD *this)
 CConfigManager::~CConfigManager(void) {
  
  int v1; // eax
  std::_Iterator_base12 *v2; // eax
  _BYTE v4[12]; // [esp+4h] [ebp-48h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-3Ch] BYREF
  _BYTE v6[12]; // [esp+1Ch] [ebp-30h] BYREF
  int v7; // [esp+28h] [ebp-24h]
  int v8; // [esp+2Ch] [ebp-20h]
  int v9; // [esp+30h] [ebp-1Ch]
  int v10; // [esp+34h] [ebp-18h]
  _DWORD *v11; // [esp+38h] [ebp-14h]
  char v12; // [esp+3Fh] [ebp-Dh]

  v11 = this;
  *this = &CConfigManager::_vftable_;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(v6);
  v1 = std::list<CConfigSection *>::begin(v5);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::operator=(v1);
  std::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(v5);
  while ( 1 )
  {
    v2 = (std::_Iterator_base12 *)std::list<CConfigSection *>::end(v4);
    v12 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::operator!=(v2);
    std::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(v4);
    if ( !v12 )
      break;
    v10 = *(_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::operator*(v6);
    if ( v10 )
    {
      v8 = v10;
      v9 = v10;
      v7 = CConfigSection::`scalar deleting destructor'(1);
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::operator++(v6);
  }
  std::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(v6);
  std::list<CConfigSection *>::clear();
  std::list<CConfigSection *>::~list<CConfigSection *>();
  std::map<std::string,int>::~map<std::string,int>(v11 + 1);
  return IConfigManager::~IConfigManager(v11);
}


// address=[0x2ef1390]
// Decompiled from int __thiscall CConfigManager::AddConfigFile(CConfigManager *this, const wchar_t *a2)
bool  CConfigManager::AddConfigFile(wchar_t const *) {
  
  return ((int (__thiscall *)(CConfigManager *, const wchar_t *, _DWORD))this->j_?AddConfigFileEx@CConfigManager@@UAE_NPB_WPBD@Z)(
           this,
           a2,
           0);
}


// address=[0x2ef13b0]
// Decompiled from void __thiscall CConfigManager::AddConfigFileEx(void *this, wchar_t *FileName, char *String2)
bool  CConfigManager::AddConfigFileEx(wchar_t const *,char const *) {
  
  _DWORD v3[6]; // [esp+0h] [ebp-54h] BYREF
  char v4; // [esp+19h] [ebp-3Bh]
  char v5; // [esp+1Ah] [ebp-3Ah]
  char v6; // [esp+1Bh] [ebp-39h]
  int v7[11]; // [esp+1Ch] [ebp-38h] BYREF
  int v8; // [esp+50h] [ebp-4h]

  v7[10] = (int)v3;
  v3[5] = this;
  v8 = 0;
  v3[4] = CConfigFile::CConfigFile(FileName);
  LOBYTE(v8) = 1;
  v6 = CConfigManager::Parse((int)v7, String2);
  v5 = v6;
  v4 = v6;
  LOBYTE(v8) = 0;
  CConfigFile::~CConfigFile((CConfigFile *)v7);
  JUMPOUT(0x2EF144F);
}


// address=[0x2ef1470]
// Decompiled from bool __thiscall CConfigManager::AddCommandLine(CConfigManager *this, char *groupName, int argc, char **const argv)
bool  CConfigManager::AddCommandLine(char const *,int,char * * const) {
  
  size_t v4; // eax
  char *Str; // [esp+8h] [ebp-54h]
  int i; // [esp+Ch] [ebp-50h]
  bool v9; // [esp+13h] [ebp-49h]
  _BYTE v10[28]; // [esp+14h] [ebp-48h] BYREF
  _BYTE v11[28]; // [esp+30h] [ebp-2Ch] BYREF
  int v12; // [esp+58h] [ebp-4h]

  std::string::string(v11, (char *)&byte_3AB2C98);
  v12 = 0;
  std::string::string(v10, "\r\n");
  LOBYTE(v12) = 1;
  std::string::operator=(v11, "[");
  std::string::operator+=(groupName);
  std::string::operator+=("]");
  std::string::operator+=((int)v10);
  std::string::operator+=("{");
  std::string::operator+=((int)v10);
  for ( i = 0; i < argc; ++i )
  {
    std::string::operator+=(argv[i]);
    std::string::operator+=((int)v10);
  }
  std::string::operator+=("}");
  std::string::operator+=((int)v10);
  Str = (char *)std::string::c_str(v11);
  v4 = j__strlen(Str);
  v9 = CConfigManager::ParseData(this, Str, v4);
  LOBYTE(v12) = 0;
  std::string::~string(v10);
  v12 = -1;
  std::string::~string(v11);
  return v9;
}


// address=[0x2ef15c0]
// Decompiled from int __stdcall CConfigManager::GetIntValue(char *Str, char *a2, int a3)
int  CConfigManager::GetIntValue(char const *,char const *,int) {
  
  int Section; // [esp+8h] [ebp-6Ch]
  int (__thiscall ***Var)(_DWORD); // [esp+Ch] [ebp-68h]
  _BYTE v6[28]; // [esp+10h] [ebp-64h] BYREF
  _BYTE v7[28]; // [esp+2Ch] [ebp-48h] BYREF
  _BYTE v8[28]; // [esp+48h] [ebp-2Ch] BYREF
  int v9; // [esp+70h] [ebp-4h]

  std::string::string(v8, Str);
  v9 = 0;
  Section = CConfigManager::GetSection(v8, 1);
  v9 = -1;
  std::string::~string(v8);
  if ( !Section )
    return a3;
  std::string::string(v7, a2);
  v9 = 1;
  Var = (int (__thiscall ***)(_DWORD))CConfigSection::GetVar(v7);
  v9 = -1;
  std::string::~string(v7);
  if ( Var )
    return (**Var)(Var);
  std::string::string(v6, a2);
  v9 = 2;
  CConfigSection::AddVar((int)v6, a3);
  v9 = -1;
  std::string::~string(v6);
  return a3;
}


// address=[0x2ef16d0]
// Decompiled from int __stdcall CConfigManager::GetIntValueNoAdd(char *Str, char *a2, int a3)
int  CConfigManager::GetIntValueNoAdd(char const *,char const *,int) {
  
  int Section; // [esp+8h] [ebp-50h]
  int (__thiscall ***Var)(_DWORD); // [esp+Ch] [ebp-4Ch]
  _BYTE v6[28]; // [esp+10h] [ebp-48h] BYREF
  _BYTE v7[28]; // [esp+2Ch] [ebp-2Ch] BYREF
  int v8; // [esp+54h] [ebp-4h]

  std::string::string(v7, Str);
  v8 = 0;
  Section = CConfigManager::GetSection(v7, 1);
  v8 = -1;
  std::string::~string(v7);
  if ( !Section )
    return a3;
  std::string::string(v6, a2);
  v8 = 1;
  Var = (int (__thiscall ***)(_DWORD))CConfigSection::GetVar(v6);
  v8 = -1;
  std::string::~string(v6);
  if ( Var )
    return (**Var)(Var);
  else
    return a3;
}


// address=[0x2ef17a0]
// Decompiled from double __stdcall CConfigManager::GetFloatValue(char *Str, char *a2, int a3)
float  CConfigManager::GetFloatValue(char const *,char const *,float) {
  
  double result; // st7
  int Section; // [esp+Ch] [ebp-6Ch]
  int Var; // [esp+10h] [ebp-68h]
  _BYTE v6[28]; // [esp+14h] [ebp-64h] BYREF
  _BYTE v7[28]; // [esp+30h] [ebp-48h] BYREF
  _BYTE v8[28]; // [esp+4Ch] [ebp-2Ch] BYREF
  int v9; // [esp+74h] [ebp-4h]

  std::string::string(v8, Str);
  v9 = 0;
  Section = CConfigManager::GetSection(v8, 1);
  v9 = -1;
  std::string::~string(v8);
  if ( !Section )
    return *(float *)&a3;
  std::string::string(v7, a2);
  v9 = 1;
  Var = CConfigSection::GetVar(v7);
  v9 = -1;
  std::string::~string(v7);
  if ( Var )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)Var + 4))(Var);
  }
  else
  {
    std::string::string(v6, a2);
    v9 = 2;
    CConfigSection::AddVar((int)v6, *(float *)&a3);
    v9 = -1;
    std::string::~string(v6);
    return *(float *)&a3;
  }
  return result;
}


// address=[0x2ef18b0]
// Decompiled from double __stdcall CConfigManager::GetFloatValueNoAdd(char *Str, char *a2, float a3)
float  CConfigManager::GetFloatValueNoAdd(char const *,char const *,float) {
  
  double result; // st7
  int Section; // [esp+8h] [ebp-50h]
  int Var; // [esp+Ch] [ebp-4Ch]
  _BYTE v6[28]; // [esp+10h] [ebp-48h] BYREF
  _BYTE v7[28]; // [esp+2Ch] [ebp-2Ch] BYREF
  int v8; // [esp+54h] [ebp-4h]

  std::string::string(v7, Str);
  v8 = 0;
  Section = CConfigManager::GetSection(v7, 1);
  v8 = -1;
  std::string::~string(v7);
  if ( !Section )
    return a3;
  std::string::string(v6, a2);
  v8 = 1;
  Var = CConfigSection::GetVar(v6);
  v8 = -1;
  std::string::~string(v6);
  if ( !Var )
    return a3;
  (*(void (__thiscall **)(int))(*(_DWORD *)Var + 4))(Var);
  return result;
}


// address=[0x2ef1990]
// Decompiled from int __stdcall CConfigManager::GetStringValue(int a1, char *Str, char *a3, int a4)
std::string  CConfigManager::GetStringValue(char const *,char const *,std::string const &) {
  
  int Section; // [esp+8h] [ebp-70h]
  int Var; // [esp+Ch] [ebp-6Ch]
  _BYTE v7[28]; // [esp+14h] [ebp-64h] BYREF
  _BYTE v8[28]; // [esp+30h] [ebp-48h] BYREF
  _BYTE v9[28]; // [esp+4Ch] [ebp-2Ch] BYREF
  int v10; // [esp+74h] [ebp-4h]

  std::string::string(v9, Str);
  v10 = 0;
  Section = CConfigManager::GetSection(v9, 1);
  v10 = -1;
  std::string::~string(v9);
  if ( Section )
  {
    std::string::string(v8, a3);
    v10 = 1;
    Var = CConfigSection::GetVar(v8);
    v10 = -1;
    std::string::~string(v8);
    if ( Var )
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)Var + 8))(Var, a1);
    }
    else
    {
      std::string::string(v7, a3);
      v10 = 2;
      CConfigSection::AddVar((int)v7, a4);
      v10 = -1;
      std::string::~string(v7);
      std::string::string(a4);
    }
    return a1;
  }
  else
  {
    std::string::string(a4);
    return a1;
  }
}


// address=[0x2ef1ae0]
// Decompiled from int __stdcall CConfigManager::GetStringValueNoAdd(int a1, char *Str, char *a3, int a4)
std::string  CConfigManager::GetStringValueNoAdd(char const *,char const *,std::string const &) {
  
  int Section; // [esp+8h] [ebp-54h]
  int Var; // [esp+Ch] [ebp-50h]
  _BYTE v7[28]; // [esp+14h] [ebp-48h] BYREF
  _BYTE v8[28]; // [esp+30h] [ebp-2Ch] BYREF
  int v9; // [esp+58h] [ebp-4h]

  std::string::string(v8, Str);
  v9 = 0;
  Section = CConfigManager::GetSection(v8, 1);
  v9 = -1;
  std::string::~string(v8);
  if ( Section )
  {
    std::string::string(v7, a3);
    v9 = 1;
    Var = CConfigSection::GetVar(v7);
    v9 = -1;
    std::string::~string(v7);
    if ( Var )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)Var + 8))(Var, a1);
    else
      std::string::string(a4);
    return a1;
  }
  else
  {
    std::string::string(a4);
    return a1;
  }
}


// address=[0x2ef1c00]
// Decompiled from int __stdcall CConfigManager::GetConfigVar(char *Str, char *a2)
class CConfigVar *  CConfigManager::GetConfigVar(char const *,char const *) {
  
  int Var; // [esp+4h] [ebp-54h]
  int Section; // [esp+Ch] [ebp-4Ch]
  _BYTE v5[28]; // [esp+10h] [ebp-48h] BYREF
  _BYTE v6[28]; // [esp+2Ch] [ebp-2Ch] BYREF
  int v7; // [esp+54h] [ebp-4h]

  std::string::string(v6, Str);
  v7 = 0;
  Section = CConfigManager::GetSection(v6, 1);
  v7 = -1;
  std::string::~string(v6);
  if ( !Section )
    return 0;
  std::string::string(v5, a2);
  v7 = 1;
  Var = CConfigSection::GetVar(v5);
  v7 = -1;
  std::string::~string(v5);
  return Var;
}


// address=[0x2ef1cc0]
// Decompiled from void __thiscall CConfigManager::AddDefines(CConfigManager *this, char **a2, int a3)
void  CConfigManager::AddDefines(struct SConfigTypeString const *,int) {
  
  int i; // [esp+8h] [ebp-30h]
  _BYTE v4[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v5; // [esp+34h] [ebp-4h]

  if ( a2 )
  {
    for ( i = 0; i < a3; ++i )
    {
      std::string::string(v4, a2[2 * i + 1]);
      v5 = 0;
      *(_DWORD *)std::map<std::string,int>::operator[](v4) = a2[2 * i];
      v5 = -1;
      std::string::~string(v4);
    }
  }
}


// address=[0x2ef1d70]
// Decompiled from int __thiscall CConfigManager::GetDefineValue(void *this, char *Str)
int  CConfigManager::GetDefineValue(char const *) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-70h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-64h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-58h] BYREF
  int v6; // [esp+28h] [ebp-4Ch]
  std::_Iterator_base12 *v7; // [esp+2Ch] [ebp-48h]
  std::_Iterator_base12 *v8; // [esp+30h] [ebp-44h]
  int v9; // [esp+34h] [ebp-40h]
  int v10; // [esp+38h] [ebp-3Ch]
  void *v11; // [esp+3Ch] [ebp-38h]
  int v12; // [esp+40h] [ebp-34h]
  char v13; // [esp+47h] [ebp-2Dh]
  _BYTE v14[28]; // [esp+48h] [ebp-2Ch] BYREF
  int v15; // [esp+70h] [ebp-4h]

  v11 = this;
  if ( !Str || !*Str )
    return -1;
  v12 = 0;
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>(v5);
  v15 = 0;
  std::string::string(v14, Str);
  LOBYTE(v15) = 1;
  v10 = std::_Tree<std::_Tmap_traits<std::string,int,std::less<std::string>,std::allocator<std::pair<std::string const,int>>,0>>::find(
          v4,
          v14);
  v9 = v10;
  LOBYTE(v15) = 2;
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::operator=(v10);
  LOBYTE(v15) = 1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>(v4);
  LOBYTE(v15) = 0;
  std::string::~string(v14);
  v8 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<std::string,int,std::less<std::string>,std::allocator<std::pair<std::string const,int>>,0>>::end(v3);
  v7 = v8;
  LOBYTE(v15) = 3;
  v13 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::operator!=(v8);
  LOBYTE(v15) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>(v3);
  if ( v13 )
    v12 = *(_DWORD *)(std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::operator*(v5)
                    + 28);
  else
    v12 = -1;
  v6 = v12;
  v15 = -1;
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::~_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>(v5);
  return v6;
}


// address=[0x2ef1eb0]
// Decompiled from void __stdcall CConfigManager::AddStaticConfigVar(char *Str, char *a2, int a3)
void  CConfigManager::AddStaticConfigVar(char const *,char const *,class CConfigVar &) {
  
  int Section; // [esp+8h] [ebp-4Ch]
  _BYTE v4[28]; // [esp+Ch] [ebp-48h] BYREF
  _BYTE v5[28]; // [esp+28h] [ebp-2Ch] BYREF
  int v6; // [esp+50h] [ebp-4h]

  std::string::string(v5, Str);
  v6 = 0;
  Section = CConfigManager::GetSection(v5, 1);
  v6 = -1;
  std::string::~string(v5);
  if ( Section )
  {
    std::string::string(v4, a2);
    v6 = 1;
    CConfigSection::AddStaticConfigVar((int)v4, a3);
    v6 = -1;
    std::string::~string(v4);
  }
}


// address=[0x2ef1f70]
// Decompiled from char __stdcall CConfigManager::SaveSection(char *Str, wchar_t *FileName)
bool  CConfigManager::SaveSection(char const *,wchar_t const *) {
  
  int Section; // [esp+8h] [ebp-30h]
  _BYTE v4[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v5; // [esp+34h] [ebp-4h]

  std::string::string(v4, Str);
  v5 = 0;
  Section = CConfigManager::GetSection(v4, 1);
  v5 = -1;
  std::string::~string(v4);
  if ( Section )
    return CConfigSection::Save(FileName);
  BBSupportTracePrintF(2, "CConfigManager::SaveSection : Section \"%s\" not found!", Str);
  return 0;
}


// address=[0x2ef2020]
// Decompiled from int __stdcall CConfigManager::GetSectionEntryCount(char *Str)
int  CConfigManager::GetSectionEntryCount(char const *) {
  
  CConfigSection *Section; // [esp+8h] [ebp-30h]
  _BYTE v3[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v4; // [esp+34h] [ebp-4h]

  std::string::string(v3, Str);
  v4 = 0;
  Section = (CConfigSection *)CConfigManager::GetSection(v3, 1);
  v4 = -1;
  std::string::~string(v3);
  if ( Section )
    return CConfigSection::NumberOfEntries(Section);
  else
    return 0;
}


// address=[0x2ef20b0]
// Decompiled from bool __stdcall CConfigManager::DoesExist(char *Str, char *a2)
bool  CConfigManager::DoesExist(char const *,char const *) {
  
  int Var; // [esp+4h] [ebp-58h]
  int Section; // [esp+10h] [ebp-4Ch]
  _BYTE v5[28]; // [esp+14h] [ebp-48h] BYREF
  _BYTE v6[28]; // [esp+30h] [ebp-2Ch] BYREF
  int v7; // [esp+58h] [ebp-4h]

  std::string::string(v6, Str);
  v7 = 0;
  Section = CConfigManager::GetSection(v6, 1);
  v7 = -1;
  std::string::~string(v6);
  if ( !Section )
    return 0;
  if ( !a2 )
    return 1;
  std::string::string(v5, a2);
  v7 = 1;
  Var = CConfigSection::GetVar(v5);
  v7 = -1;
  std::string::~string(v5);
  return Var != 0;
}


// address=[0x2ef8610]
// Decompiled from CConfigManager *__thiscall CConfigManager::CConfigManager(CConfigManager *this)
 CConfigManager::CConfigManager(void) {
  
  IConfigManager::IConfigManager((IConfigManager *)this);
  this->__vftable = (CConfigManager_vtbl *)&CConfigManager::_vftable_;
  std::map<std::string,int>::map<std::string,int>(&this[1]);
  std::list<CConfigSection *>::list<CConfigSection *>(&this[4]);
  return this;
}


// address=[0x2eefee0]
// Decompiled from char __thiscall CConfigManager::ParseData(CConfigManager *this, char *a2, int a3)
bool  CConfigManager::ParseData(char *,int) {
  
  void *Section; // [esp+4h] [ebp-5Ch]
  struct CConfigSection *v6; // [esp+Ch] [ebp-54h]
  int v7; // [esp+10h] [ebp-50h] BYREF
  char v8; // [esp+17h] [ebp-49h]
  _BYTE v9[28]; // [esp+18h] [ebp-48h] BYREF
  _BYTE v10[28]; // [esp+34h] [ebp-2Ch] BYREF
  int v11; // [esp+5Ch] [ebp-4h]

  if ( !a2 )
    return 0;
  v7 = 0;
  std::string::string(v10, (char *)&byte_3AB2C99);
  v11 = 0;
  while ( v7 < a3 )
  {
    Section = CConfigManager::ParseFindSection(v9, (int)a2, &v7, &a3);
    std::string::operator=(v10, Section);
    std::string::~string(v9);
    if ( std::string::length(v10) )
    {
      v6 = (struct CConfigSection *)CConfigManager::GetSection(v10, 1);
      if ( v6 )
        CConfigManager::ParseAddSectionVars(this, v6, a2, &v7, &a3);
    }
  }
  v8 = 1;
  v11 = -1;
  std::string::~string(v10);
  return v8;
}


// address=[0x2eeffe0]
// Decompiled from char __thiscall CConfigManager::Parse(CConfigManager *this, CConfigFile *a2, char *String2)
bool  CConfigManager::Parse(class CConfigFile *,char const *) {
  
  const char *v4; // eax
  void *Section; // [esp+4h] [ebp-64h]
  struct CConfigSection *v7; // [esp+Ch] [ebp-5Ch]
  char *Config; // [esp+10h] [ebp-58h]
  int v9; // [esp+14h] [ebp-54h] BYREF
  int Size; // [esp+18h] [ebp-50h] BYREF
  char v11; // [esp+1Fh] [ebp-49h]
  _BYTE v12[28]; // [esp+20h] [ebp-48h] BYREF
  _BYTE v13[28]; // [esp+3Ch] [ebp-2Ch] BYREF
  int v14; // [esp+64h] [ebp-4h]

  Config = CConfigFile::GetConfig(a2);
  if ( !Config )
    return 0;
  Size = CConfigFile::GetSize(a2);
  v9 = 0;
  std::string::string(v13, (char *)&byte_3AB2C9A);
  v14 = 0;
  while ( v9 < Size )
  {
    Section = CConfigManager::ParseFindSection(v12, (int)Config, &v9, &Size);
    std::string::operator=(v13, Section);
    std::string::~string(v12);
    if ( std::string::length(v13) )
    {
      if ( !String2 || (v4 = (const char *)std::string::c_str(v13), !j___stricmp(v4, String2)) )
      {
        v7 = (struct CConfigSection *)CConfigManager::GetSection(v13, 1);
        if ( v7 )
          CConfigManager::ParseAddSectionVars(this, v7, Config, &v9, &Size);
      }
    }
  }
  v11 = 1;
  v14 = -1;
  std::string::~string(v13);
  return v11;
}


// address=[0x2ef0120]
// Decompiled from void *__stdcall CConfigManager::ParseFindSection(void *a1, int a2, _DWORD *a3, _DWORD *a4)
std::string  CConfigManager::ParseFindSection(char *,int &,int const &) {
  
  void *Line; // [esp+4h] [ebp-5Ch]
  int v6; // [esp+Ch] [ebp-54h]
  int v7; // [esp+14h] [ebp-4Ch]
  _BYTE v8[28]; // [esp+18h] [ebp-48h] BYREF
  _BYTE v9[28]; // [esp+34h] [ebp-2Ch] BYREF
  int v10; // [esp+5Ch] [ebp-4h]

  std::string::string(v9, (char *)&byte_3AB2C9B);
  v10 = 0;
  while ( *a3 < *a4 )
  {
    Line = (void *)CConfigManager::ParseGetLine(v8, a2, a3, a4);
    std::string::operator=(v9, Line);
    std::string::~string(v8);
    if ( std::string::length(v9) )
    {
      v7 = std::string::find("[", 0);
      v6 = std::string::find("]", 0);
      if ( v7 >= 0 && v6 >= 0 && v7 < v6 )
      {
        std::string::substr(a1, v7 + 1, v6 - v7 - 1);
        v10 = -1;
        std::string::~string(v9);
        return a1;
      }
    }
  }
  std::string::string(a1, (char *)&byte_3AB2C9F);
  v10 = -1;
  std::string::~string(v9);
  return a1;
}


// address=[0x2ef0270]
// Decompiled from void __fastcall CConfigManager::ParseAddSectionVars(  CConfigManager *this,  int a2,  struct CConfigSection *a3,  char *a4,  int *a5,  const int *a6)
void  CConfigManager::ParseAddSectionVars(class CConfigSection *,char *,int &,int const &) {
  
  const char *v6; // eax
  int DefineVar; // eax
  const char *v8; // eax
  const char *v9; // eax
  void *v10; // [esp+Ch] [ebp-4E8h]
  float v11; // [esp+10h] [ebp-4E4h]
  int Var; // [esp+14h] [ebp-4E0h]
  void *v13; // [esp+18h] [ebp-4DCh]
  void *Line; // [esp+1Ch] [ebp-4D8h]
  int v15; // [esp+24h] [ebp-4D0h]
  _DWORD v16[3]; // [esp+28h] [ebp-4CCh] BYREF
  int v17; // [esp+34h] [ebp-4C0h] BYREF
  char v18; // [esp+3Bh] [ebp-4B9h]
  _BYTE v19[28]; // [esp+3Ch] [ebp-4B8h] BYREF
  _BYTE v20[28]; // [esp+58h] [ebp-49Ch] BYREF
  _BYTE v21[28]; // [esp+74h] [ebp-480h] BYREF
  int v22[7]; // [esp+90h] [ebp-464h] BYREF
  _BYTE v23[28]; // [esp+ACh] [ebp-448h] BYREF
  _BYTE v24[28]; // [esp+C8h] [ebp-42Ch] BYREF
  _BYTE Src[1024]; // [esp+E4h] [ebp-410h] BYREF
  int v26; // [esp+4F0h] [ebp-4h]

  v16[2] = this;
  std::string::string(v24, (char *)&byte_3AB2CA6);
  v26 = 0;
  std::string::string(v22, (char *)&byte_3AB2CA7);
  LOBYTE(v26) = 1;
  std::string::string(v23, (char *)&byte_3AB2CAA);
  LOBYTE(v26) = 2;
  v18 = 0;
  v17 = 0;
  v16[0] = 0;
  while ( *a5 < *a6 )
  {
    v15 = *a5;
    Line = (void *)CConfigManager::ParseGetLine(v21, a4, a5, a6);
    std::string::operator=(v24, Line);
    std::string::~string(v21);
    if ( std::string::length(v24) )
    {
      if ( !std::string::find("}", 0) || !std::string::find("[", 0) )
      {
        *a5 = v15;
        LOBYTE(v26) = 1;
        std::string::~string(v23);
        LOBYTE(v26) = 0;
        std::string::~string(v22);
        v26 = -1;
        std::string::~string(v24);
        return;
      }
      if ( !std::string::find("{", 0) )
      {
        v18 = 1;
        break;
      }
    }
  }
  if ( v18 )
  {
    while ( *a5 < *a6 )
    {
      v13 = (void *)CConfigManager::ParseGetLine(v20, a4, a5, a6);
      std::string::operator=(v24, v13);
      std::string::~string(v20);
      if ( std::string::length(v24) )
      {
        if ( !std::string::find("}", 0) )
          break;
        Var = CConfigManager::ParseGetVar(v24, v22, v23);
        v16[1] = Var - 1;
        switch ( Var )
        {
          case 1:
            if ( std::string::find(60, 0) >= 0 )
            {
              DefineVar = CConfigManager::ParseGetDefineVar(v23);
            }
            else
            {
              v6 = (const char *)std::string::c_str(v23);
              DefineVar = j__atoi(v6);
            }
            CConfigSection::AddVar((int)v22, DefineVar);
            break;
          case 2:
            v9 = (const char *)std::string::c_str(v23);
            v17 = j__atoi(v9);
            if ( v17 <= 0 )
            {
              if ( BBSupportDbgReport(
                     1,
                     "Source\\ConfigManager\\ConfigManager.cpp",
                     802,
                     "CConfigManager::ParseAddSectionVars(): Invalid array size!") == 1 )
                __debugbreak();
            }
            else
            {
              if ( v17 > 255 )
              {
                v17 = 255;
                if ( BBSupportDbgReport(
                       1,
                       "Source\\ConfigManager\\ConfigManager.cpp",
                       785,
                       "CConfigManager::ParseAddSectionVars(): Array size too large!") == 1 )
                  __debugbreak();
              }
              v16[0] = 0;
              CConfigManager::ParseGetArrayVars(v24, Src, v16, &v17);
              while ( v16[0] < v17 && *a5 < *a6 )
              {
                v10 = (void *)CConfigManager::ParseGetLine(v19, a4, a5, a6);
                std::string::operator=(v24, v10);
                std::string::~string(v19);
                if ( std::string::length(v24) )
                  CConfigManager::ParseGetArrayVars(v24, Src, v16, &v17);
              }
              CConfigSection::AddVar((int)v22, Src, v17);
            }
            break;
          case 3:
            v8 = (const char *)std::string::c_str(v23);
            v11 = j__atof(v8);
            CConfigSection::AddVar((int)v22, v11);
            break;
          case 4:
            CConfigSection::AddVar((int)v22, (int)v23);
            break;
          default:
            continue;
        }
      }
    }
  }
  LOBYTE(v26) = 1;
  std::string::~string(v23);
  LOBYTE(v26) = 0;
  std::string::~string(v22);
  v26 = -1;
  std::string::~string(v24);
}


// address=[0x2ef07d0]
// Decompiled from void *__stdcall CConfigManager::ParseGetLine(void *a1, int a2, _DWORD *a3, _DWORD *a4)
std::string  CConfigManager::ParseGetLine(char *,int &,int const &) {
  
  char v5; // [esp+Fh] [ebp-2Dh]
  _BYTE v6[28]; // [esp+10h] [ebp-2Ch] BYREF
  int v7; // [esp+38h] [ebp-4h]

  std::string::string(v6, (char *)&byte_3AB2CA2);
  v7 = 0;
  v5 = 1;
  if ( *(_BYTE *)(a2 + *a3) == 59 )
  {
    while ( *a3 < *a4 && *(_BYTE *)(a2 + *a3) != 13 )
      ++*a3;
  }
  else
  {
    while ( *a3 < *a4 && *(_BYTE *)(a2 + *a3) != 13 )
    {
      if ( *(_BYTE *)(a2 + *a3) != 32 && *(_BYTE *)(a2 + *a3) != 9 )
        v5 = 0;
      if ( !v5 )
        std::string::operator+=(*(_BYTE *)(a2 + *a3));
      ++*a3;
    }
  }
  *a3 += 2;
  if ( v5 )
    std::string::string(a1, (char *)&byte_3AB2CA3);
  else
    std::string::string(v6);
  v7 = -1;
  std::string::~string(v6);
  return a1;
}


// address=[0x2ef0960]
// Decompiled from int __stdcall CConfigManager::ParseGetVar(void *a1, void *a2, void *a3)
enum T_CFGVAR_TYPE  CConfigManager::ParseGetVar(std::string &,std::string &,std::string &) {
  
  int v4; // eax
  int v5; // eax
  size_t v6; // eax
  void *v7; // eax
  int v8; // eax
  int v9; // [esp+4h] [ebp-164h]
  void *v10; // [esp+8h] [ebp-160h]
  void *v11; // [esp+Ch] [ebp-15Ch]
  void *v12; // [esp+10h] [ebp-158h]
  void *v13; // [esp+18h] [ebp-150h]
  void *v14; // [esp+1Ch] [ebp-14Ch]
  void *v15; // [esp+20h] [ebp-148h]
  void *v16; // [esp+24h] [ebp-144h]
  void *v17; // [esp+28h] [ebp-140h]
  signed int v18; // [esp+2Ch] [ebp-13Ch]
  int v19; // [esp+30h] [ebp-138h]
  unsigned int v20; // [esp+38h] [ebp-130h]
  unsigned int v21; // [esp+3Ch] [ebp-12Ch]
  int v22; // [esp+44h] [ebp-124h]
  signed int v23; // [esp+48h] [ebp-120h]
  int v24; // [esp+4Ch] [ebp-11Ch]
  signed int v25; // [esp+50h] [ebp-118h]
  signed int v26; // [esp+54h] [ebp-114h]
  int v27; // [esp+58h] [ebp-110h]
  int v28; // [esp+5Ch] [ebp-10Ch]
  unsigned int k; // [esp+60h] [ebp-108h]
  unsigned int i; // [esp+64h] [ebp-104h]
  signed int j; // [esp+64h] [ebp-104h]
  _BYTE v32[28]; // [esp+68h] [ebp-100h] BYREF
  _BYTE v33[28]; // [esp+84h] [ebp-E4h] BYREF
  _BYTE v34[28]; // [esp+A0h] [ebp-C8h] BYREF
  _BYTE v35[28]; // [esp+BCh] [ebp-ACh] BYREF
  _BYTE v36[28]; // [esp+D8h] [ebp-90h] BYREF
  _BYTE v37[28]; // [esp+F4h] [ebp-74h] BYREF
  _BYTE v38[28]; // [esp+110h] [ebp-58h] BYREF
  _BYTE v39[28]; // [esp+12Ch] [ebp-3Ch] BYREF
  _BYTE v40[28]; // [esp+148h] [ebp-20h] BYREF

  v25 = std::string::find("=", 0);
  if ( v25 < 0 )
    return 0;
  v10 = (void *)std::string::substr(v32, 0, v25);
  std::string::operator=(a2, v10);
  std::string::~string(v32);
  v28 = std::string::find(" ", 0);
  v27 = std::string::find(9, 0);
  v26 = 0;
  if ( v28 <= 0 || v27 <= 0 )
  {
    if ( v28 <= 0 )
    {
      if ( v27 > 0 )
        v26 = v27;
    }
    else
    {
      v26 = v28;
    }
  }
  else
  {
    if ( v28 >= v27 )
      v18 = v27;
    else
      v18 = v28;
    v26 = v18;
  }
  if ( v26 > 0 )
  {
    v11 = (void *)std::string::substr(v33, 0, v26);
    std::string::operator=(a2, v11);
    std::string::~string(v33);
  }
  v23 = std::string::find("[", 0);
  if ( v23 <= 0 )
  {
    v6 = std::string::length(a1);
    v13 = (void *)std::string::substr(v38, v25 + 1, v6);
    std::string::operator=(a3, v13);
    std::string::~string(v38);
    v22 = std::string::c_str(a3);
    v20 = 0;
    for ( i = 0; i < std::string::length(a3); ++i )
    {
      if ( *(_BYTE *)(i + v22) != 32 && *(_BYTE *)(i + v22) != 9 )
      {
        v20 = i;
        break;
      }
    }
    for ( j = std::string::length(a3); j > 0; --j )
    {
      if ( *(_BYTE *)(j + v22) != 32 && *(_BYTE *)(j + v22) != 9 )
      {
        v7 = (void *)std::string::substr(v39, v20, j);
        goto LABEL_36;
      }
    }
    v7 = (void *)std::string::substr(v39, v20, 0);
LABEL_36:
    std::string::operator=(a3, v7);
    std::string::~string(v39);
    if ( std::string::find(34, 0) < 0 )
    {
      if ( std::string::find(46, 0) < 0 )
        return 1;
      else
        return 3;
    }
    else
    {
      v24 = 4;
      v8 = std::string::length(a3);
      v12 = (void *)std::string::substr(v40, 1, v8 - 2);
      std::string::operator=(a3, v12);
      std::string::~string(v40);
    }
  }
  else
  {
    v9 = std::string::find("]", 0);
    v17 = (void *)std::string::substr(v34, v23 + 1, v9 - (v23 + 1));
    std::string::operator=(a3, v17);
    std::string::~string(v34);
    v16 = (void *)std::string::substr(v35, 0, v23);
    std::string::operator=(a2, v16);
    std::string::~string(v35);
    v4 = std::string::length(a1);
    v15 = (void *)std::string::substr(v36, v25 + 1, v4 - (v25 + 1));
    std::string::operator=(a1, v15);
    std::string::~string(v36);
    v19 = std::string::c_str(a1);
    v21 = 0;
    for ( k = 0; k < std::string::length(a1); ++k )
    {
      if ( *(_BYTE *)(k + v19) != 32 && *(_BYTE *)(k + v19) != 9 )
      {
        v21 = k;
        break;
      }
    }
    v5 = std::string::length(a1);
    v14 = (void *)std::string::substr(v37, v21, v5 - v21);
    std::string::operator=(a1, v14);
    std::string::~string(v37);
    return 2;
  }
  return v24;
}


// address=[0x2ef0ea0]
// Decompiled from void __stdcall CConfigManager::ParseGetArrayVars(int a1, int a2, _DWORD *a3, _DWORD *a4)
void  CConfigManager::ParseGetArrayVars(std::string &,int *,int &,int &) {
  
  const char *v4; // eax
  void *v5; // [esp+8h] [ebp-60h]
  int DefineVar; // [esp+14h] [ebp-54h]
  int v7; // [esp+18h] [ebp-50h]
  int v8; // [esp+1Ch] [ebp-4Ch]
  _BYTE v9[28]; // [esp+20h] [ebp-48h] BYREF
  _BYTE v10[28]; // [esp+3Ch] [ebp-2Ch] BYREF
  int v11; // [esp+64h] [ebp-4h]

  v8 = -1;
  std::string::string(v10, (char *)&byte_3AB2CAE);
  v11 = 0;
  do
  {
    v7 = std::string::find(44, v8 + 1);
    if ( v7 < 0 )
      break;
    v5 = (void *)std::string::substr(v9, v8 + 1, v7 - (v8 + 1));
    std::string::operator=(v10, v5);
    std::string::~string(v9);
    if ( std::string::find(60, 0) >= 0 )
    {
      DefineVar = CConfigManager::ParseGetDefineVar(v10);
    }
    else
    {
      v4 = (const char *)std::string::c_str(v10);
      DefineVar = j__atoi(v4);
    }
    *(_DWORD *)(a2 + 4 * (*a3)++) = DefineVar;
    v8 = std::string::find(44, v8 + 1);
    if ( v8 < 0 )
      break;
  }
  while ( *a3 < *a4 );
  v11 = -1;
  std::string::~string(v10);
}


// address=[0x2ef1010]
// Decompiled from int __thiscall CConfigManager::ParseGetDefineVar(void *this, void *a2)
int  CConfigManager::ParseGetDefineVar(std::string &) {
  
  int v2; // eax
  void *v4; // [esp+4h] [ebp-2Ch]
  int v5; // [esp+8h] [ebp-28h]
  _BYTE v7[28]; // [esp+10h] [ebp-20h] BYREF

  v5 = std::string::find(62, 0);
  v4 = (void *)std::string::substr(v7, 1, v5 - 1);
  std::string::operator=(a2, v4);
  std::string::~string(v7);
  v2 = std::string::c_str(a2);
  return (*(int (__thiscall **)(void *, int))(*(_DWORD *)this + 32))(this, v2);
}


// address=[0x2ef1090]
// Decompiled from _DWORD *__stdcall CConfigManager::AddDefineVar(int a1, int a2)
void  CConfigManager::AddDefineVar(std::string const &,int) {
  
  _DWORD *result; // eax

  result = (_DWORD *)std::map<std::string,int>::operator[](a1);
  *result = a2;
  return result;
}


// address=[0x2ef10c0]
// Decompiled from char *__thiscall CConfigManager::GetSection(void *this, int a2, char a3)
class CConfigSection *  CConfigManager::GetSection(std::string const &,bool) {
  
  void *v3; // eax
  int v5; // [esp+0h] [ebp-6Ch]
  _BYTE v6[12]; // [esp+4h] [ebp-68h] BYREF
  _BYTE v7[12]; // [esp+10h] [ebp-5Ch] BYREF
  _BYTE v8[12]; // [esp+1Ch] [ebp-50h] BYREF
  int v9; // [esp+28h] [ebp-44h]
  char *v10; // [esp+2Ch] [ebp-40h]
  char *v11; // [esp+30h] [ebp-3Ch]
  void *v12; // [esp+34h] [ebp-38h]
  std::_Iterator_base12 *v13; // [esp+38h] [ebp-34h]
  std::_Iterator_base12 *v14; // [esp+3Ch] [ebp-30h]
  int v15; // [esp+40h] [ebp-2Ch]
  int v16; // [esp+44h] [ebp-28h]
  char *v17; // [esp+48h] [ebp-24h] BYREF
  char *v18; // [esp+4Ch] [ebp-20h]
  int C; // [esp+50h] [ebp-1Ch]
  void *v20; // [esp+54h] [ebp-18h]
  void *v21; // [esp+58h] [ebp-14h]
  char v22; // [esp+5Fh] [ebp-Dh]
  int v23; // [esp+68h] [ebp-4h]

  v21 = this;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(v8);
  v23 = 0;
  v16 = std::list<CConfigSection *>::begin(v7);
  v15 = v16;
  LOBYTE(v23) = 1;
  std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::operator=(v16);
  LOBYTE(v23) = 0;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(v7);
  while ( 1 )
  {
    v14 = (std::_Iterator_base12 *)std::list<CConfigSection *>::end((int)v6);
    v13 = v14;
    LOBYTE(v23) = 2;
    v22 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::operator!=(v14);
    LOBYTE(v23) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(v6);
    if ( !v22 )
      break;
    v20 = *(void **)std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::operator*(
                      v8,
                      v5);
    v3 = CConfigSection::Name(v20);
    if ( (unsigned __int8)std::operator==<char>(v3, a2) )
    {
      v12 = v20;
      v23 = -1;
      std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(
        v8,
        v5);
      return (char *)v12;
    }
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::operator++(v8);
  }
  if ( a3 )
  {
    C = (int)operator new(0x28u, 1, "Source\\ConfigManager\\ConfigManager.cpp", 1058);
    LOBYTE(v23) = 3;
    if ( C )
      v18 = CConfigSection::CConfigSection((char *)C, a2);
    else
      v18 = 0;
    v11 = v18;
    LOBYTE(v23) = 0;
    v17 = v18;
    std::list<CConfigSection *>::push_back(&v17);
    v10 = v17;
    v23 = -1;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(
      v8,
      v5);
    return v10;
  }
  else
  {
    v9 = 0;
    v23 = -1;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(
      v8,
      v5);
    return (char *)v9;
  }
}


