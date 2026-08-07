#if FALSE
#include "CConfigManager.h"

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
    {
      break;
    }
    v10 = *(_DWORD *)std::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::operator*(v6);
    if ( v10 )
    {
      v8 = v10;
      v9 = v10;
      v7 = delete 1);
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::operator++(v6);
  }
  std::_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(v6);
  std::list<CConfigSection *>::clear();
  std::list<CConfigSection *>::~list<CConfigSection *>();
  std::map<std::string;
  return IConfigManager::~IConfigManager(v11);
}


// address=[0x2ef1390]
// Decompiled from int __thiscall CConfigManager::AddConfigFile(CConfigManager *this, const wchar_t *a2)
bool  CConfigManager::AddConfigFile(wchar_t const * a2) {
  
  return this->AddConfigFileEx(this, a2, 0);
}


// address=[0x2ef13b0]
// Decompiled from void __thiscall CConfigManager::AddConfigFileEx(CConfigManager *this, wchar_t *FileName, char *String2)
bool  CConfigManager::AddConfigFileEx(wchar_t const * FileName, char const * String2) {
  
  DWORD v3; // [esp+0h] [ebp-54h] BYREF
  CConfigFile *v4; // [esp+10h] [ebp-44h]
  char v6; // [esp+19h] [ebp-3Bh]
  char v7; // [esp+1Ah] [ebp-3Ah]
  char v8; // [esp+1Bh] [ebp-39h]
  DWORD v9; // [esp+1Ch] [ebp-38h] BYREF
  DWORD *v10; // [esp+44h] [ebp-10h]
  int exceptionBlock; // [esp+50h] [ebp-4h]

  v10 = &v3;
  exceptionBlock = 0;
  v4 = CConfigFile::CConfigFile((CConfigFile *)&v9, FileName);
  LOBYTE(exceptionBlock) = 1;
  v8 = CConfigManager::Parse(this, (CConfigFile *)&v9, String2);
  v7 = v8;
  v6 = v8;
  LOBYTE(exceptionBlock) = 0;
  CConfigFile::~CConfigFile((void **)&v9);
  JUMPOUT(0x2EF144F);
}


// address=[0x2ef1470]
// Decompiled from char __thiscall CConfigManager::AddCommandLine(CConfigManager *this, char *groupName, int argc, char **const argv)
bool  CConfigManager::AddCommandLine(char const * groupName, int argc, char * * const argv) {
  
  size_t v4; // eax
  char *Str; // [esp+8h] [ebp-54h]
  int i; // [esp+Ch] [ebp-50h]
  char v9; // [esp+13h] [ebp-49h]
  std::string v10; // [esp+14h] [ebp-48h] BYREF
  std::string v11; // [esp+30h] [ebp-2Ch] BYREF
  int v12; // [esp+58h] [ebp-4h]

  std::string::string(&v11, (char *)&byte_3AB2C98);
  v12 = 0;
  std::string::string(&v10, "\r\n");
  LOBYTE(v12) = 1;
  std::string::operator=(&v11, "[");
  std::string::operator+=(groupName);
  std::string::operator+=("]");
  std::string::operator+=((int)&v10);
  std::string::operator+=("{");
  std::string::operator+=((int)&v10);
  for ( i = 0;
        i < argc;
        ++i )
  {
    std::string::operator+=(argv[i]);
    std::string::operator+=((int)&v10);
  }
  std::string::operator+=("}");
  std::string::operator+=((int)&v10);
  Str = std::string::c_str(&v11);
  v4 = strlen(Str);
  v9 = CConfigManager::ParseData(this, Str, v4);
  LOBYTE(v12) = 0;
  std::string::~string(&v10);
  v12 = -1;
  std::string::~string(&v11);
  return v9;
}


// address=[0x2ef15c0]
// Decompiled from int __thiscall CConfigManager::GetIntValue(CConfigManager *this, char *Str, char *a3, int a4)
int  CConfigManager::GetIntValue(char const * Str, char const * a3, int a4) {
  
  CConfigSection *Section; // [esp+8h] [ebp-6Ch]
  CConfigVar *Var; // [esp+Ch] [ebp-68h]
  std::string v8; // [esp+10h] [ebp-64h] BYREF
  std::string a2; // [esp+2Ch] [ebp-48h] BYREF
  std::string v10; // [esp+48h] [ebp-2Ch] BYREF
  int v11; // [esp+70h] [ebp-4h]

  std::string::string(&v10, Str);
  v11 = 0;
  Section = CConfigManager::GetSection(this, &v10, 1);
  v11 = -1;
  std::string::~string(&v10);
  if ( !Section )
  {
    return a4;
  }
  std::string::string(&a2, a3);
  v11 = 1;
  Var = CConfigSection::GetVar(Section, &a2);
  v11 = -1;
  std::string::~string(&a2);
  if ( Var )
  {
    return Var->GetIntValue(Var);
  }
  std::string::string(&v8, a3);
  v11 = 2;
  CConfigSection::AddVar(Section, &v8, a4);
  v11 = -1;
  std::string::~string(&v8);
  return a4;
}


// address=[0x2ef16d0]
// Decompiled from int __thiscall CConfigManager::GetIntValueNoAdd(CConfigManager *this, char *_spSection, char *_spVarName, int _iDefault)
int  CConfigManager::GetIntValueNoAdd(char const * _spSection, char const * _spVarName, int _iDefault) {
  
  CConfigSection *Section; // [esp+8h] [ebp-50h]
  CConfigVar *Var; // [esp+Ch] [ebp-4Ch]
  std::string a2; // [esp+10h] [ebp-48h] BYREF
  std::string spSection; // [esp+2Ch] [ebp-2Ch] BYREF
  int v10; // [esp+54h] [ebp-4h]

  std::string::string(&spSection, _spSection);
  v10 = 0;
  Section = CConfigManager::GetSection(this, &spSection, 1);
  v10 = -1;
  std::string::~string(&spSection);
  if ( !Section )
  {
    return _iDefault;
  }
  std::string::string(&a2, _spVarName);
  v10 = 1;
  Var = CConfigSection::GetVar(Section, &a2);
  v10 = -1;
  std::string::~string(&a2);
  if ( Var )
  {
    return Var->GetIntValue(Var);
  }
  else
  {
    return _iDefault;
  }
}


// address=[0x2ef17a0]
// Decompiled from double __thiscall CConfigManager::GetFloatValue(void *this, char *Str, char *a3, int a4)
float  CConfigManager::GetFloatValue(char const * Str, char const * a3, float a4) {
  
  double result; // st7
  CConfigSection *Section; // [esp+Ch] [ebp-6Ch]
  CConfigVar *Var; // [esp+10h] [ebp-68h]
  std::string v8; // [esp+14h] [ebp-64h] BYREF
  std::string a2; // [esp+30h] [ebp-48h] BYREF
  std::string v10; // [esp+4Ch] [ebp-2Ch] BYREF
  int v11; // [esp+74h] [ebp-4h]

  std::string::string(&v10, Str);
  v11 = 0;
  Section = CConfigManager::GetSection(this, &v10, 1);
  v11 = -1;
  std::string::~string(&v10);
  if ( !Section )
  {
    return *(float *)&a4;
  }
  std::string::string(&a2, a3);
  v11 = 1;
  Var = CConfigSection::GetVar(Section, &a2);
  v11 = -1;
  std::string::~string(&a2);
  if ( Var )
  {
    Var->GetFloatValue(Var);
  }
  else
  {
    std::string::string(&v8, a3);
    v11 = 2;
    CConfigSection::AddVar(Section, &v8, *(float *)&a4);
    v11 = -1;
    std::string::~string(&v8);
    return *(float *)&a4;
  }
  return result;
}


// address=[0x2ef18b0]
// Decompiled from double __stdcall CConfigManager::GetFloatValueNoAdd(char *Str, char *a2, float a3)
float  CConfigManager::GetFloatValueNoAdd(char const * Str, char const * a3, float a4) {
  
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
  {
    return a3;
  }
  std::string::string(v6, a2);
  v8 = 1;
  Var = CConfigSection::GetVar(v6);
  v8 = -1;
  std::string::~string(v6);
  if ( !Var )
  {
    return a3;
  }
  (*(void (__thiscall **)(int))(*(_DWORD *)Var + 4))(Var);
  return result;
}


// address=[0x2ef1990]
// Decompiled from std::string *__thiscall CConfigManager::GetStringValue(void *this, std::string *arg0, char *Str, char *a4, int a2)
std::string  CConfigManager::GetStringValue(char const * arg0, char const * Str, std::string const & a4) {
  
  CConfigSection *Section; // [esp+8h] [ebp-70h]
  int Var; // [esp+Ch] [ebp-6Ch]
  struct std::string v9; // [esp+14h] [ebp-64h] BYREF
  struct std::string v10; // [esp+30h] [ebp-48h] BYREF
  struct std::string v11; // [esp+4Ch] [ebp-2Ch] BYREF
  int v12; // [esp+74h] [ebp-4h]

  std::string::string(&v11, Str);
  v12 = 0;
  Section = CConfigManager::GetSection(this, (int)&v11, 1);
  v12 = -1;
  std::string::~string(&v11);
  if ( Section )
  {
    std::string::string(&v10, a4);
    v12 = 1;
    Var = CConfigSection::GetVar(Section, (int)&v10);
    v12 = -1;
    std::string::~string(&v10);
    if ( Var )
    {
      (*(void (__thiscall **)(int, std::string *))(*(_DWORD *)Var + 8))(Var, arg0);
    }
    else
    {
      std::string::string(&v9, a4);
      v12 = 2;
      CConfigSection::AddVar(Section, (int)&v9, a2);
      v12 = -1;
      std::string::~string(&v9);
      std::string::string(arg0, a2);
    }
    return arg0;
  }
  else
  {
    std::string::string(arg0, a2);
    return arg0;
  }
}


// address=[0x2ef1ae0]
// Decompiled from int __stdcall CConfigManager::GetStringValueNoAdd(int a1, char *Str, char *a3, int a4)
std::string  CConfigManager::GetStringValueNoAdd(char const * a2, char const * Str, std::string const & a4) {
  
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
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)Var + 8))(Var, a1);
    }
    else
    {
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


// address=[0x2ef1c00]
// Decompiled from CConfigVar *__thiscall CConfigManager::GetConfigVar(void *this, char *Str, char *a3)
class CConfigVar *  CConfigManager::GetConfigVar(char const * Str, char const * a3) {
  
  CConfigVar *Var; // [esp+4h] [ebp-54h]
  CConfigSection *Section; // [esp+Ch] [ebp-4Ch]
  std::string a2; // [esp+10h] [ebp-48h] BYREF
  std::string v8; // [esp+2Ch] [ebp-2Ch] BYREF
  int v9; // [esp+54h] [ebp-4h]

  std::string::string(&v8, Str);
  v9 = 0;
  Section = CConfigManager::GetSection(this, &v8, 1);
  v9 = -1;
  std::string::~string(&v8);
  if ( !Section )
  {
    return 0;
  }
  std::string::string(&a2, a3);
  v9 = 1;
  Var = CConfigSection::GetVar(Section, &a2);
  v9 = -1;
  std::string::~string(&a2);
  return Var;
}


// address=[0x2ef1cc0]
// Decompiled from void __thiscall CConfigManager::AddDefines(CConfigManager *this, char **a2, int a3)
void  CConfigManager::AddDefines(struct SConfigTypeString const * a2, int a3) {
  
  int i; // [esp+8h] [ebp-30h]
  std::string v4; // [esp+Ch] [ebp-2Ch] BYREF
  int v5; // [esp+34h] [ebp-4h]

  if ( a2 )
  {
    for ( i = 0;
          i < a3;
          ++i )
    {
      std::string::string(&v4, a2[2 * i + 1]);
      v5 = 0;
      *(_DWORD *)std::map<std::string,int>::operator[](&v4) = a2[2 * i];
      v5 = -1;
      std::string::~string(&v4);
    }
  }
}


// address=[0x2ef1d70]
// Decompiled from int __thiscall CConfigManager::GetDefineValue(CConfigManager *this, char *_spDefineName)
int  CConfigManager::GetDefineValue(char const * _spDefineName) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-70h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-64h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-58h] BYREF
  int v6; // [esp+28h] [ebp-4Ch]
  std::_Iterator_base12 *v7; // [esp+2Ch] [ebp-48h]
  std::_Iterator_base12 *v8; // [esp+30h] [ebp-44h]
  int v9; // [esp+34h] [ebp-40h]
  int v10; // [esp+38h] [ebp-3Ch]
  int v12; // [esp+40h] [ebp-34h]
  char v13; // [esp+47h] [ebp-2Dh]
  struct std::string v14; // [esp+48h] [ebp-2Ch] BYREF
  int v15; // [esp+70h] [ebp-4h]

  if ( !_spDefineName || !*_spDefineName )
  {
    return -1;
  }
  v12 = 0;
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>(v5);
  v15 = 0;
  std::string::string(&v14, _spDefineName);
  LOBYTE(v15) = 1;
  v10 = std::_Tree<std::_Tmap_traits<std::string,int,std::less<std::string>,std::allocator<std::pair<std::string const,int>>,0>>::find(v4, &v14);
  v9 = v10;
  LOBYTE(v15) = 2;
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::operator=(v10);
  LOBYTE(v15) = 1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>(v4);
  LOBYTE(v15) = 0;
  std::string::~string(&v14);
  v8 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<std::string,int,std::less<std::string>,std::allocator<std::pair<std::string const,int>>,0>>::end(v3);
  v7 = v8;
  LOBYTE(v15) = 3;
  v13 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::operator!=(v8);
  LOBYTE(v15) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>(v3);
  if ( v13 )
  {
    v12 = *(_DWORD *)(std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::operator*(v5) + 28);
  }
  else
  {
    v12 = -1;
  }
  v6 = v12;
  v15 = -1;
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>::~_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,int>>>>(v5);
  return v6;
}


// address=[0x2ef1eb0]
// Decompiled from void __thiscall CConfigManager::AddStaticConfigVar(CConfigManager *this, char *Str, char *a3, int a4)
void  CConfigManager::AddStaticConfigVar(char const * Str, char const * a3, class CConfigVar & a4) {
  
  CConfigSection *Section; // [esp+8h] [ebp-4Ch]
  std::string v6; // [esp+Ch] [ebp-48h] BYREF
  std::string v7; // [esp+28h] [ebp-2Ch] BYREF
  int v8; // [esp+50h] [ebp-4h]

  std::string::string(&v7, Str);
  v8 = 0;
  Section = CConfigManager::GetSection(this, &v7, 1);
  v8 = -1;
  std::string::~string(&v7);
  if ( Section )
  {
    std::string::string(&v6, a3);
    v8 = 1;
    CConfigSection::AddStaticConfigVar(Section, (int)&v6, a4);
    v8 = -1;
    std::string::~string(&v6);
  }
}


// address=[0x2ef1f70]
// Decompiled from char __stdcall CConfigManager::SaveSection(char *Str, wchar_t *FileName)
bool  CConfigManager::SaveSection(char const * Str, wchar_t const * FileName) {
  
  int Section; // [esp+8h] [ebp-30h]
  _BYTE v4[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v5; // [esp+34h] [ebp-4h]

  std::string::string(v4, Str);
  v5 = 0;
  Section = CConfigManager::GetSection(v4, 1);
  v5 = -1;
  std::string::~string(v4);
  if ( Section )
  {
    return CConfigSection::Save(FileName);
  }
  BBSupportTracePrintF(2, "CConfigManager::SaveSection : Section \"%s\" not found!", Str);
  return 0;
}


// address=[0x2ef2020]
// Decompiled from int __stdcall CConfigManager::GetSectionEntryCount(char *Str)
int  CConfigManager::GetSectionEntryCount(char const * Str) {
  
  CConfigSection *Section; // [esp+8h] [ebp-30h]
  _BYTE v3[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v4; // [esp+34h] [ebp-4h]

  std::string::string(v3, Str);
  v4 = 0;
  Section = (CConfigSection *)CConfigManager::GetSection(v3, 1);
  v4 = -1;
  std::string::~string(v3);
  if ( Section )
  {
    return CConfigSection::NumberOfEntries(Section);
  }
  else
  {
    return 0;
  }
}


// address=[0x2ef20b0]
// Decompiled from bool __stdcall CConfigManager::DoesExist(char *Str, char *a2)
bool  CConfigManager::DoesExist(char const * Str, char const * a3) {
  
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
  {
    return 0;
  }
  if ( !a2 )
  {
    return 1;
  }
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
  
  IConfigManager::IConfigManager(this);
  this->__vftable = (IConfigManager_vtbl *)&CConfigManager::_vftable_;
  std::map<std::string,int>::map<std::string,int>(&this->m_mSectionIdMap);
  std::list<CConfigSection *>::list<CConfigSection *>(&this->m_lSections);
  return this;
}


// address=[0x2eefee0]
// Decompiled from char __thiscall CConfigManager::ParseData(CConfigManager *this, char *a2, int a3)
bool  CConfigManager::ParseData(char * a2, int a3) {
  
  std::string *Section; // [esp+4h] [ebp-5Ch]
  struct CConfigSection *v6; // [esp+Ch] [ebp-54h]
  int v7; // [esp+10h] [ebp-50h] BYREF
  char v8; // [esp+17h] [ebp-49h]
  std::string v9; // [esp+18h] [ebp-48h] BYREF
  std::string v10; // [esp+34h] [ebp-2Ch] BYREF
  int v11; // [esp+5Ch] [ebp-4h]

  if ( !a2 )
  {
    return 0;
  }
  v7 = 0;
  std::string::string(&v10, (char *)&byte_3AB2C99);
  v11 = 0;
  while ( v7 < a3 )
  {
    Section = CConfigManager::ParseFindSection(&v9, a2, &v7, &a3);
    std::string::operator=(&v10, Section);
    std::string::~string(&v9);
    if ( std::string::length(&v10) )
    {
      v6 = CConfigManager::GetSection(this, &v10, 1);
      if ( v6 )
      {
        CConfigManager::ParseAddSectionVars(this, (int)&v7, v6, a2, &v7, &a3);
      }
    }
  }
  v8 = 1;
  v11 = -1;
  std::string::~string(&v10);
  return v8;
}


// address=[0x2eeffe0]
// Decompiled from char __thiscall CConfigManager::Parse(CConfigManager *this, CConfigFile *a2, char *String2)
bool  CConfigManager::Parse(class CConfigFile * a2, char const * String2) {
  
  char *v4; // eax
  std::string *Section; // [esp+4h] [ebp-64h]
  struct CConfigSection *v7; // [esp+Ch] [ebp-5Ch]
  char *Config; // [esp+10h] [ebp-58h]
  int v9; // [esp+14h] [ebp-54h] BYREF
  int Size; // [esp+18h] [ebp-50h] BYREF
  char v11; // [esp+1Fh] [ebp-49h]
  std::string v12; // [esp+20h] [ebp-48h] BYREF
  std::string v13; // [esp+3Ch] [ebp-2Ch] BYREF
  int v14; // [esp+64h] [ebp-4h]

  Config = (char *)CConfigFile::GetConfig(a2);
  if ( !Config )
  {
    return 0;
  }
  Size = CConfigFile::GetSize(a2);
  v9 = 0;
  std::string::string(&v13, (char *)&byte_3AB2C9A);
  v14 = 0;
  while ( v9 < Size )
  {
    Section = CConfigManager::ParseFindSection(&v12, Config, &v9, &Size);
    std::string::operator=(&v13, Section);
    std::string::~string(&v12);
    if ( std::string::length(&v13) )
    {
      if ( !String2 || (v4 = std::string::c_str(&v13), !stricmp(v4, String2)) )
      {
        v7 = CConfigManager::GetSection(this, &v13, 1);
        if ( v7 )
        {
          CConfigManager::ParseAddSectionVars(this, (int)v7, v7, Config, &v9, &Size);
        }
      }
    }
  }
  v11 = 1;
  v14 = -1;
  std::string::~string(&v13);
  return v11;
}


// address=[0x2ef0120]
// Decompiled from std::string *__stdcall CConfigManager::ParseFindSection(std::string *a1, char *a2, int *a3, const int *a4)
std::string  CConfigManager::ParseFindSection(char * a1, int & a2, int const & a3) {
  
  std::string *Line; // [esp+4h] [ebp-5Ch]
  int v6; // [esp+Ch] [ebp-54h]
  int v7; // [esp+14h] [ebp-4Ch]
  std::string v8; // [esp+18h] [ebp-48h] BYREF
  std::string v9; // [esp+34h] [ebp-2Ch] BYREF
  int v10; // [esp+5Ch] [ebp-4h]

  std::string::string(&v9, (char *)&byte_3AB2C9B);
  v10 = 0;
  while ( *a3 < *a4 )
  {
    Line = CConfigManager::ParseGetLine(&v8, (int)a2, a3, a4);
    std::string::operator=(&v9, Line);
    std::string::~string(&v8);
    if ( std::string::length(&v9) )
    {
      v7 = std::string::find(&v9, "[", 0);
      v6 = std::string::find(&v9, "]", 0);
      if ( v7 >= 0 && v6 >= 0 && v7 < v6 )
      {
        std::string::substr(&v9, a1, v7 + 1, v6 - v7 - 1);
        v10 = -1;
        std::string::~string(&v9);
        return a1;
      }
    }
  }
  std::string::string(a1, (char *)&byte_3AB2C9F);
  v10 = -1;
  std::string::~string(&v9);
  return a1;
}


// address=[0x2ef0270]
// Decompiled from void __thiscall CConfigManager::ParseAddSectionVars(CConfigManager *this, struct CConfigSection *pSection, char *a4, int *a5, int *a6)
void  CConfigManager::ParseAddSectionVars(class CConfigSection * pSection, char * a4, int & a5, int const & a6) {
  
  char *v5; // eax
  int DefineVar; // eax
  char *v7; // eax
  char *spValue; // eax
  std::string *v9; // [esp+Ch] [ebp-4E8h]
  float v10; // [esp+10h] [ebp-4E4h]
  int Var; // [esp+14h] [ebp-4E0h]
  std::string *v12; // [esp+18h] [ebp-4DCh]
  std::string *Line; // [esp+1Ch] [ebp-4D8h]
  int v14; // [esp+24h] [ebp-4D0h]
  DWORD v15; // [esp+28h] [ebp-4CCh] BYREF
  int v16; // [esp+2Ch] [ebp-4C8h]
  CConfigManager *v17; // [esp+30h] [ebp-4C4h]
  int iSize; // [esp+34h] [ebp-4C0h] BYREF
  char v19; // [esp+3Bh] [ebp-4B9h]
  std::string v20; // [esp+3Ch] [ebp-4B8h] BYREF
  std::string v21; // [esp+58h] [ebp-49Ch] BYREF
  std::string v22; // [esp+74h] [ebp-480h] BYREF
  std::string a2a; // [esp+90h] [ebp-464h] BYREF
  std::string a1; // [esp+ACh] [ebp-448h] BYREF
  std::string v25; // [esp+C8h] [ebp-42Ch] BYREF
  int Src[256]; // [esp+E4h] [ebp-410h] BYREF
  int v27; // [esp+4F0h] [ebp-4h]

  v17 = this;
  std::string::string(&v25, (char *)&byte_3AB2CA6);
  v27 = 0;
  std::string::string(&a2a, (char *)&byte_3AB2CA7);
  LOBYTE(v27) = 1;
  std::string::string(&a1, (char *)&byte_3AB2CAA);
  LOBYTE(v27) = 2;
  v19 = 0;
  iSize = 0;
  v15 = 0;
  while ( *a5 < *a6 )
  {
    v14 = *a5;
    Line = CConfigManager::ParseGetLine(&v22, (int)a4, a5, a6);
    std::string::operator=(&v25, Line);
    std::string::~string(&v22);
    if ( std::string::length(&v25) )
    {
      if ( !std::string::find(&v25, "}", 0) || !std::string::find(&v25, "[", 0) )
      {
        *a5 = v14;
        LOBYTE(v27) = 1;
        std::string::~string(&a1);
        LOBYTE(v27) = 0;
        std::string::~string(&a2a);
        v27 = -1;
        std::string::~string(&v25);
        return;
      }
      if ( !std::string::find(&v25, "{", 0) )
      {
        v19 = 1;
        break;
      }
    }
  }
  if ( v19 )
  {
    while ( *a5 < *a6 )
    {
      v12 = CConfigManager::ParseGetLine(&v21, (int)a4, a5, a6);
      std::string::operator=(&v25, v12);
      std::string::~string(&v21);
      if ( std::string::length(&v25) )
      {
        if ( !std::string::find(&v25, "}", 0) )
        {
          break;
        }
        Var = CConfigManager::ParseGetVar(&v25, &a2a, &a1);
        v16 = Var - 1;
        switch ( Var )
        {
          case CONFIGVAR_TYPE_INT:
            if ( std::string::find(&a1, '<', 0) >= 0 )
            {
              DefineVar = CConfigManager::ParseGetDefineVar(v17, &a1);
            }
            else
            {
              v5 = std::string::c_str(&a1);
              DefineVar = j__atoi(v5);
            }
            CConfigSection::AddVar(pSection, &a2a, DefineVar);
            break;
          case CONFIGVAR_TYPE_INT_ARRAY:
            spValue = std::string::c_str(&a1);
            iSize = j__atoi(spValue);
            if ( iSize <= 0 )
            {
              if ( BBSupportDbgReport(1, "Source\\ConfigManager\\ConfigManager.cpp", 802, "CConfigManager::ParseAddSectionVars(): Invalid array size!") == 1 )
              {
                __debugbreak();
              }
            }
            else
            {
              if ( iSize > 255 )
              {
                iSize = 255;
                if ( BBSupportDbgReport(1, "Source\\ConfigManager\\ConfigManager.cpp", 785, "CConfigManager::ParseAddSectionVars(): Array size too large!") == 1 )
                {
                  __debugbreak();
                }
              }
              v15 = 0;
              CConfigManager::ParseGetArrayVars(v17, (int)&v25, (int)Src, &v15, &iSize);
              while ( (int)v15 < iSize && *a5 < *a6 )
              {
                v9 = CConfigManager::ParseGetLine(&v20, (int)a4, a5, a6);
                std::string::operator=(&v25, v9);
                std::string::~string(&v20);
                if ( std::string::length(&v25) )
                {
                  CConfigManager::ParseGetArrayVars(v17, (int)&v25, (int)Src, &v15, &iSize);
                }
              }
              CConfigSection::AddVar(pSection, &a2a, Src, iSize);
            }
            break;
          case CONFIGVAR_TYPE_FLOAT:
            v7 = std::string::c_str(&a1);
            v10 = j__atof(v7);
            CConfigSection::AddVar(pSection, &a2a, v10);
            break;
          case CONFIGVAR_TYPE_STRING:
            CConfigSection::AddVar(pSection, &a2a, &a1);
            break;
          default:
            continue;
        }
      }
    }
  }
  LOBYTE(v27) = 1;
  std::string::~string(&a1);
  LOBYTE(v27) = 0;
  std::string::~string(&a2a);
  v27 = -1;
  std::string::~string(&v25);
}


// address=[0x2ef07d0]
// Decompiled from std::string *__stdcall CConfigManager::ParseGetLine(std::string *a1, char *a2, int *a3, const int *a4)
std::string  CConfigManager::ParseGetLine(char * a1, int & a2, int const & a3) {
  
  char v5; // [esp+Fh] [ebp-2Dh]
  std::string v6; // [esp+10h] [ebp-2Ch] BYREF
  int v7; // [esp+38h] [ebp-4h]

  std::string::string(&v6, (char *)&byte_3AB2CA2);
  v7 = 0;
  v5 = 1;
  if ( a2[*a3] == ';' )
  {
    while ( *a3 < *a4 && a2[*a3] != '\r' )
    {
      ++*a3;
    }
  }
  else
  {
    while ( *a3 < *a4 && a2[*a3] != '\r' )
    {
      if ( a2[*a3] != ' ' && a2[*a3] != '\t' )
      {
        v5 = 0;
      }
      if ( !v5 )
      {
        std::string::operator+=(&v6, a2[*a3]);
      }
      ++*a3;
    }
  }
  *a3 += 2;
  if ( v5 )
  {
    std::string::string(a1, (char *)&byte_3AB2CA3);
  }
  else
  {
    std::string::string(&v6);
  }
  v7 = -1;
  std::string::~string(&v6);
  return a1;
}


// address=[0x2ef0960]
// Decompiled from int __stdcall CConfigManager::ParseGetVar(std::string *arg0, std::string *a1, std::string *arg8)
enum T_CFGVAR_TYPE  CConfigManager::ParseGetVar(std::string & arg0, std::string & a2, std::string & arg8) {
  
  int v4; // eax
  int v5; // eax
  size_t v6; // eax
  std::string *v7; // eax
  int v8; // eax
  int v9; // [esp+4h] [ebp-164h]
  std::string *v10; // [esp+8h] [ebp-160h]
  std::string *v11; // [esp+Ch] [ebp-15Ch]
  std::string *v12; // [esp+10h] [ebp-158h]
  std::string *v13; // [esp+18h] [ebp-150h]
  std::string *v14; // [esp+1Ch] [ebp-14Ch]
  std::string *v15; // [esp+20h] [ebp-148h]
  std::string *v16; // [esp+24h] [ebp-144h]
  std::string *v17; // [esp+28h] [ebp-140h]
  int v18; // [esp+2Ch] [ebp-13Ch]
  char *v19; // [esp+30h] [ebp-138h]
  int v20; // [esp+38h] [ebp-130h]
  int a3; // [esp+3Ch] [ebp-12Ch]
  char *v22; // [esp+44h] [ebp-124h]
  int v23; // [esp+48h] [ebp-120h]
  int v24; // [esp+4Ch] [ebp-11Ch]
  int Size; // [esp+50h] [ebp-118h]
  int v26; // [esp+54h] [ebp-114h]
  int v27; // [esp+58h] [ebp-110h]
  int v28; // [esp+5Ch] [ebp-10Ch]
  unsigned int k; // [esp+60h] [ebp-108h]
  unsigned int i; // [esp+64h] [ebp-104h]
  signed int j; // [esp+64h] [ebp-104h]
  std::string a2; // [esp+68h] [ebp-100h] BYREF
  std::string v33; // [esp+84h] [ebp-E4h] BYREF
  std::string v34; // [esp+A0h] [ebp-C8h] BYREF
  std::string v35; // [esp+BCh] [ebp-ACh] BYREF
  std::string v36; // [esp+D8h] [ebp-90h] BYREF
  std::string v37; // [esp+F4h] [ebp-74h] BYREF
  std::string v38; // [esp+110h] [ebp-58h] BYREF
  std::string v39; // [esp+12Ch] [ebp-3Ch] BYREF
  std::string v40; // [esp+148h] [ebp-20h] BYREF

  Size = std::string::find(arg0, "=", 0);
  if ( Size < 0 )
  {
    return 0;
  }
  v10 = std::string::substr(arg0, &a2, 0, Size);
  std::string::operator=(a1, v10);
  std::string::~string(&a2);
  v28 = std::string::find(a1, " ", 0);
  v27 = std::string::find(a1, 9, 0);
  v26 = 0;
  if ( v28 <= 0 || v27 <= 0 )
  {
    if ( v28 <= 0 )
    {
      if ( v27 > 0 )
      {
        v26 = v27;
      }
    }
    else
    {
      v26 = v28;
    }
  }
  else
  {
    if ( v28 >= v27 )
    {
      v18 = v27;
    }
    else
    {
      v18 = v28;
    }
    v26 = v18;
  }
  if ( v26 > 0 )
  {
    v11 = std::string::substr(a1, &v33, 0, v26);
    std::string::operator=(a1, v11);
    std::string::~string(&v33);
  }
  v23 = std::string::find(a1, "[", 0);
  if ( v23 <= 0 )
  {
    v6 = std::string::length(arg0);
    v13 = std::string::substr(arg0, &v38, Size + 1, v6);
    std::string::operator=(arg8, v13);
    std::string::~string(&v38);
    v22 = std::string::c_str(arg8);
    v20 = 0;
    for ( i = 0;
          i < std::string::length(arg8);
          ++i )
    {
      if ( v22[i] != 32 && v22[i] != 9 )
      {
        v20 = i;
        break;
      }
    }
    for ( j = std::string::length(arg8);
          j > 0;
          --j )
    {
      if ( v22[j] != 32 && v22[j] != 9 )
      {
        v7 = std::string::substr(arg8, &v39, v20, j);
        goto LABEL_36;
      }
    }
    v7 = std::string::substr(arg8, &v39, v20, 0);
LABEL_36:
    std::string::operator=(arg8, v7);
    std::string::~string(&v39);
    if ( std::string::find(arg8, '"', 0) < 0 )
    {
      if ( std::string::find(arg8, '.', 0) < 0 )
      {
        return 1;
      }
      else
      {
        return 3;
      }
    }
    else
    {
      v24 = 4;
      v8 = std::string::length(arg8);
      v12 = std::string::substr(arg8, &v40, 1, v8 - 2);
      std::string::operator=(arg8, v12);
      std::string::~string(&v40);
    }
  }
  else
  {
    v9 = std::string::find(a1, "]", 0);
    v17 = std::string::substr(a1, &v34, v23 + 1, v9 - (v23 + 1));
    std::string::operator=(arg8, v17);
    std::string::~string(&v34);
    v16 = std::string::substr(a1, &v35, 0, v23);
    std::string::operator=(a1, v16);
    std::string::~string(&v35);
    v4 = std::string::length(arg0);
    v15 = std::string::substr(arg0, &v36, Size + 1, v4 - (Size + 1));
    std::string::operator=(arg0, v15);
    std::string::~string(&v36);
    v19 = std::string::c_str(arg0);
    a3 = 0;
    for ( k = 0;
          k < std::string::length(arg0);
          ++k )
    {
      if ( v19[k] != ' ' && v19[k] != '\t' )
      {
        a3 = k;
        break;
      }
    }
    v5 = std::string::length(arg0);
    v14 = std::string::substr(arg0, &v37, a3, v5 - a3);
    std::string::operator=(arg0, v14);
    std::string::~string(&v37);
    return 2;
  }
  return v24;
}


// address=[0x2ef0ea0]
// Decompiled from void __thiscall CConfigManager::ParseGetArrayVars(CConfigManager *this, std::string *a1, int *a3, _DWORD *a4, _DWORD *a5)
void  CConfigManager::ParseGetArrayVars(std::string & a1, int * a3, int & a4, int & a5) {
  
  char *v5; // eax
  std::string *v7; // [esp+8h] [ebp-60h]
  int DefineVar; // [esp+14h] [ebp-54h]
  int v9; // [esp+18h] [ebp-50h]
  int v10; // [esp+1Ch] [ebp-4Ch]
  std::string a2; // [esp+20h] [ebp-48h] BYREF
  std::string v12; // [esp+3Ch] [ebp-2Ch] BYREF
  int v13; // [esp+64h] [ebp-4h]

  v10 = -1;
  std::string::string(&v12, (char *)&byte_3AB2CAE);
  v13 = 0;
  do
  {
    v9 = std::string::find(a1, 44, v10 + 1);
    if ( v9 < 0 )
    {
      break;
    }
    v7 = std::string::substr(a1, &a2, v10 + 1, v9 - (v10 + 1));
    std::string::operator=(&v12, v7);
    std::string::~string(&a2);
    if ( std::string::find(&v12, '<', 0) >= 0 )
    {
      DefineVar = CConfigManager::ParseGetDefineVar(this, &v12);
    }
    else
    {
      v5 = std::string::c_str(&v12);
      DefineVar = j__atoi(v5);
    }
    a3[(*a4)++] = DefineVar;
    v10 = std::string::find(a1, ',', v10 + 1);
    if ( v10 < 0 )
    {
      break;
    }
  }
  while ( *a4 < *a5 );
  v13 = -1;
  std::string::~string(&v12);
}


// address=[0x2ef1010]
// Decompiled from int __thiscall CConfigManager::ParseGetDefineVar(CConfigManager *this, std::string *a1)
int  CConfigManager::ParseGetDefineVar(std::string & a1) {
  
  char *v2; // eax
  std::string *v4; // [esp+4h] [ebp-2Ch]
  int v5; // [esp+8h] [ebp-28h]
  std::string a2; // [esp+10h] [ebp-20h] BYREF

  v5 = std::string::find(a1, '>', 0);
  v4 = std::string::substr(a1, &a2, 1, v5 - 1);
  std::string::operator=(a1, v4);
  std::string::~string(&a2);
  v2 = std::string::c_str(a1);
  return this->GetDefineValue(this, v2);
}


// address=[0x2ef1090]
// Decompiled from void __thiscall CConfigManager::AddDefineVar(CConfigManager *this, int a1, int a2)
void  CConfigManager::AddDefineVar(std::string const & a1, int a2) {
  
  *(_DWORD *)std::map<std::string,int>::operator[](&this->m_mSectionIdMap, a1) = a2;
}


// address=[0x2ef10c0]
// Decompiled from CConfigSection *__thiscall CConfigManager::GetSection(CConfigManager *this, std::string *a2, char a3)
class CConfigSection *  CConfigManager::GetSection(std::string const & a2, bool a3) {
  
  void *v3; // eax
  int v5; // [esp+0h] [ebp-6Ch]
  _BYTE v6[12]; // [esp+4h] [ebp-68h] BYREF
  _BYTE v7[12]; // [esp+10h] [ebp-5Ch] BYREF
  _BYTE v8[12]; // [esp+1Ch] [ebp-50h] BYREF
  CConfigSection *v9; // [esp+28h] [ebp-44h]
  CConfigSection *v10; // [esp+2Ch] [ebp-40h]
  CConfigSection *v11; // [esp+30h] [ebp-3Ch]
  CConfigSection *v12; // [esp+34h] [ebp-38h]
  std::_Iterator_base12 *v13; // [esp+38h] [ebp-34h]
  std::_Iterator_base12 *v14; // [esp+3Ch] [ebp-30h]
  int v15; // [esp+40h] [ebp-2Ch]
  int v16; // [esp+44h] [ebp-28h]
  CConfigSection *v17; // [esp+48h] [ebp-24h] BYREF
  CConfigSection *v18; // [esp+4Ch] [ebp-20h]
  int C; // [esp+50h] [ebp-1Ch]
  void *v20; // [esp+54h] [ebp-18h]
  char v22; // [esp+5Fh] [ebp-Dh]
  int v23; // [esp+68h] [ebp-4h]

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
    {
      break;
    }
    v20 = *(void **)std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::operator*(v8, v5);
    v3 = CConfigSection::Name(v20);
    if ( (unsigned __int8)std::operator==<char>(v3, a2) )
    {
      v12 = (CConfigSection *)v20;
      v23 = -1;
      std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(v8);
      return v12;
    }
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::operator++(v8);
  }
  if ( a3 )
  {
    C = (int)operator new(0x28u, 1, "Source\\ConfigManager\\ConfigManager.cpp", 1058);
    LOBYTE(v23) = 3;
    if ( C )
    {
      v18 = CConfigSection::CConfigSection((CConfigSection *)C, (int)a2);
    }
    else
    {
      v18 = 0;
    }
    v11 = v18;
    LOBYTE(v23) = 0;
    v17 = v18;
    std::list<CConfigSection *>::push_back(&v17);
    v10 = v17;
    v23 = -1;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(v8);
    return v10;
  }
  else
  {
    v9 = 0;
    v23 = -1;
    std::_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>::~_List_const_iterator<std::_List_val<std::_List_simple_types<CConfigSection *>>>(v8);
    return v9;
  }
}


#endif // Already implemented
