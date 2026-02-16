#include "CConfigManager.h"

// Definitions for class CConfigManager

#include "CConfigManager/CConfigFile.h"
#include "CConfigSection.h"
#include "./Var/CConfigVar.h"

#include "CBB/CBBSupport.h"

// address=[0x2ef1280]
// Decompiled from int __thiscall sub_32F1280(_DWORD *this)
CConfigManager::~CConfigManager(void)
{
  for (CConfigSection *section : m_lSections)
  {
    if (section)
      delete section;
  }
  m_lSections.clear();
  m_mSectionIdMap.clear();
}

// address=[0x2ef1390]
// Decompiled from int __thiscall CConfigManager::AddConfigFile(CConfigManager *this, const wchar_t *a2)
bool CConfigManager::AddConfigFile(wchar_t const *a2)
{

  return this->AddConfigFileEx(a2, 0);
}

// address=[0x2ef13b0]
// Decompiled from void __thiscall CConfigManager::AddConfigFileEx(CConfigManager *this, wchar_t *FileName, char *String2)
bool CConfigManager::AddConfigFileEx(wchar_t const *FileName, char const *String2)
{

  DWORD v3;           // [esp+0h] [ebp-54h] BYREF
  CConfigFile *v4;    // [esp+10h] [ebp-44h]
  char v6;            // [esp+19h] [ebp-3Bh]
  char v7;            // [esp+1Ah] [ebp-3Ah]
  char v8;            // [esp+1Bh] [ebp-39h]
  DWORD v9;           // [esp+1Ch] [ebp-38h] BYREF
  DWORD *v10;         // [esp+44h] [ebp-10h]
  int exceptionBlock; // [esp+50h] [ebp-4h]

  return this->Parse(&CConfigFile(FileName), String2);

  // v10 = &v3;
  // exceptionBlock = 0;
  // v4 = CConfigFile::CConfigFile((CConfigFile *)&v9, FileName);
  // LOBYTE(exceptionBlock) = 1;
  // v8 = CConfigManager::Parse(this, (CConfigFile *)&v9, String2);
  // v7 = v8;
  // v6 = v8;
  // LOBYTE(exceptionBlock) = 0;
  // CConfigFile::~CConfigFile((void **)&v9);
  // JUMPOUT(0x2EF144F);
}

// address=[0x2ef1470]
// Decompiled from bool __thiscall CConfigManager::AddCommandLine(CConfigManager *this, char *groupName, int argc, char **const argv)
bool CConfigManager::AddCommandLine(char const *groupName, int argc, char **const argv)
{

  size_t v4;     // eax
  char *Str;     // [esp+8h] [ebp-54h]
  int i;         // [esp+Ch] [ebp-50h]
  bool v9;       // [esp+13h] [ebp-49h]
  _BYTE v10[28]; // [esp+14h] [ebp-48h] BYREF
  _BYTE v11[28]; // [esp+30h] [ebp-2Ch] BYREF
  int v12;       // [esp+58h] [ebp-4h]

  std::string sCommandConfig;
  std::string sNewLine = "\r\n";

  sCommandConfig = "[" + std::string(groupName) + "]" + sNewLine + "{" + sNewLine;
  for (i = 0; i < argc; ++i)
  {
    sCommandConfig += argv[i];
    sCommandConfig += sNewLine;
  }
  sCommandConfig += "}";
  sCommandConfig += sNewLine;

  return this->ParseData((char *)sCommandConfig.c_str(), sCommandConfig.length());
}

// address=[0x2ef15c0]
// Decompiled from int __stdcall CConfigManager::GetIntValue(char *Str, char *a2, int a3)
int CConfigManager::GetIntValue(char const *_spSection, char const *_spVarName, int _iDefault)
{
  CConfigSection *Section = this->GetSection(_spSection, 1);
  if (!Section)
    return _iDefault;

  CConfigVar *Var = Section->GetVar(_spVarName);
  if (Var)
    return Var->GetIntValue();

  Section->AddVar(_spVarName, _iDefault);
  return _iDefault;
}

// address=[0x2ef16d0]
// Decompiled from int __stdcall CConfigManager::GetIntValueNoAdd(char *Str, char *a2, int a3)
int CConfigManager::GetIntValueNoAdd(char const *_spSection, char const *_spVarName, int _iDefault)
{
  CConfigSection *Section = this->GetSection(_spSection, 1);
  if (!Section)
    return _iDefault;

  CConfigVar *Var = Section->GetVar(_spVarName);
  if (Var)
    return Var->GetIntValue();
  else
    return _iDefault;
}

// address=[0x2ef17a0]
// Decompiled from double __stdcall CConfigManager::GetFloatValue(char *Str, char *a2, int a3)
float CConfigManager::GetFloatValue(char const *_spSection, char const *_spVarName, float _fDefault)
{
  CConfigSection *Section = this->GetSection(_spSection, 1);
  if (!Section)
    return _fDefault;
  CConfigVar *Var = Section->GetVar(_spVarName);
  if (Var)
    return Var->GetFloatValue();

  Section->AddVar(_spVarName, _fDefault);
  return _fDefault;
}

// address=[0x2ef18b0]
// Decompiled from double __stdcall CConfigManager::GetFloatValueNoAdd(char *Str, char *a2, float a3)
float CConfigManager::GetFloatValueNoAdd(char const *_spSection, char const *_spVarName, float _fDefault)
{
  CConfigSection *Section = this->GetSection(_spSection, 1);
  if (!Section)
    return _fDefault;

  CConfigVar *Var = Section->GetVar(_spVarName);
  if (Var)
    return Var->GetFloatValue();
  else
    return _fDefault;
}

// address=[0x2ef1990]
// Decompiled from std::string *__thiscall CConfigManager::GetStringValue(void *this, std::string *arg0, char *Str, char *a4, int a2)
std::string CConfigManager::GetStringValue(char const *_spSection, char const *_spVarName, std::string const &_sDefault)
{
  CConfigSection *Section = this->GetSection(_spSection, 1);
  if (!Section)
    return _sDefault;
  CConfigVar *Var = Section->GetVar(_spVarName);
  if (Var)
    return Var->GetStringValue();

  Section->AddVar(_spVarName, _sDefault);
  return _sDefault;
}

// address=[0x2ef1ae0]
// Decompiled from int __stdcall CConfigManager::GetStringValueNoAdd(int a1, char *Str, char *a3, int a4)
std::string CConfigManager::GetStringValueNoAdd(char const *_spSection, char const *_spVarName, std::string const &_sDefault)
{
  CConfigSection *Section = this->GetSection(_spSection, 1);
  if (!Section)
    return _sDefault;

  CConfigVar *Var = Section->GetVar(_spVarName);
  if (Var)
    return Var->GetStringValue();
  else
    return _sDefault;
}

// address=[0x2ef1c00]
// Decompiled from int __stdcall CConfigManager::GetConfigVar(char *Str, char *a2)
class CConfigVar *CConfigManager::GetConfigVar(char const *_spSection, char const *_spVarName)
{
  CConfigSection *Section = this->GetSection(_spSection, 1);
  if (!Section)
    return nullptr;

  return Section->GetVar(_spVarName);
}

// address=[0x2ef1cc0]
// Decompiled from void __thiscall CConfigManager::AddDefines(CConfigManager *this, char **a2, int a3)
void CConfigManager::AddDefines(struct SConfigTypeString const *_pDefineList, int _iDefineCount)
{
  if (_pDefineList)
  {
    for (int i = 0; i < _iDefineCount; ++i)
    {
      this->m_mSectionIdMap[_pDefineList[i].m_spName] = _pDefineList[i].m_iId;
    }
  }
}

// address=[0x2ef1d70]
// Decompiled from int __thiscall CConfigManager::GetDefineValue(CConfigManager *this, char *_spDefineName)
int CConfigManager::GetDefineValue(char const *_spDefineName)
{

  _BYTE v3[12];              // [esp+4h] [ebp-70h] BYREF
  _BYTE v4[12];              // [esp+10h] [ebp-64h] BYREF
  _BYTE v5[12];              // [esp+1Ch] [ebp-58h] BYREF
  int v6;                    // [esp+28h] [ebp-4Ch]
  std::_Iterator_base12 *v7; // [esp+2Ch] [ebp-48h]
  std::_Iterator_base12 *v8; // [esp+30h] [ebp-44h]
  int v9;                    // [esp+34h] [ebp-40h]
  int v10;                   // [esp+38h] [ebp-3Ch]
  int v12;                   // [esp+40h] [ebp-34h]
  char v13;                  // [esp+47h] [ebp-2Dh]
  std::string v14;           // [esp+48h] [ebp-2Ch] BYREF
  int v15;                   // [esp+70h] [ebp-4h]

  if (!_spDefineName || !*_spDefineName)
    return -1;

  auto it = this->m_mSectionIdMap.find(_spDefineName);
  if (it != this->m_mSectionIdMap.end())
    return it->second;
  else
    return -1;
}

// address=[0x2ef1eb0]
// Decompiled from void __thiscall CConfigManager::AddStaticConfigVar(CConfigManager *this, char *Str, char *a3, int a4)
void CConfigManager::AddStaticConfigVar(char const *_spSection, char const *_spVarName, CConfigVar &_pConfig)
{
  CConfigSection *Section = this->GetSection(_spSection, 1);
  if (Section)
    Section->AddStaticConfigVar(_spVarName, _pConfig);
}

// address=[0x2ef1f70]
// Decompiled from char __stdcall CConfigManager::SaveSection(char *Str, wchar_t *FileName)
bool CConfigManager::SaveSection(char const *_spSection, wchar_t const *FileName)
{
  CConfigSection *Section = this->GetSection(_spSection, 1);
  if (Section)
    return Section->Save(FileName);

  BBSupportTracePrintF(2, "CConfigManager::SaveSection : Section \"%s\" not found!", _spSection);
  return 0;
}

// address=[0x2ef2020]
// Decompiled from int __stdcall CConfigManager::GetSectionEntryCount(char *Str)
int CConfigManager::GetSectionEntryCount(char const *_spSection)
{
  CConfigSection *Section = this->GetSection(_spSection, 1);
  if (Section)
    return Section->NumberOfEntries();
  else
    return 0;
}

// address=[0x2ef20b0]
// Decompiled from bool __stdcall CConfigManager::DoesExist(char *Str, char *a2)
bool CConfigManager::DoesExist(char const *_spSection, char const *_spVarName)
{
  CConfigSection *Section = this->GetSection(_spSection, 1);
  if (Section)
    return Section->GetVar(_spVarName) != nullptr;
  else
    return false;
}

// address=[0x2ef8610]
// Decompiled from CConfigManager *__thiscall CConfigManager::CConfigManager(CConfigManager *this)
CConfigManager::CConfigManager(void) : IConfigManager(), m_mSectionIdMap(), m_lSections()
{
}

// address=[0x2eefee0]
// Decompiled from char __thiscall CConfigManager::ParseData(CConfigManager *this, char *a2, int a3)
bool CConfigManager::ParseData(char *_spData, int _iSections)
{
  // [esp+4h] [ebp-5Ch]
  int i; // [esp+10h] [ebp-50h] BYREF

  if (!_spData)
    return 0;

  i = 0;
  while (i < _iSections)
  {
    std::string sSectionText = CConfigManager::ParseFindSection(_spData, i, _iSections);
    if (sSectionText.length())
    {
      CConfigSection *sSection = this->GetSection(sSectionText, 1);
      if (sSection)
        this->ParseAddSectionVars(sSection, _spData, i, _iSections);
    }
  }

  return true;
}

// address=[0x2eeffe0]
// Decompiled from char __thiscall CConfigManager::Parse(CConfigManager *this, CConfigFile *a2, char *String2)
bool CConfigManager::Parse(class CConfigFile *a2, char const *String2)
{
  char *spConfig = a2->GetConfig();
  if (!spConfig)
    return 0;
  int iConfigSize = a2->GetSize();

  int i = 0;
  while (i < iConfigSize)
  {
    std::string sSectionText = CConfigManager::ParseFindSection(spConfig, i, iConfigSize);
    if (sSectionText.length())
    {
      if (!String2 || !sSectionText.compare(String2)) // TODO: find out if case insensitive compare is needed here, as .compare is case sensitive and the original _stricmp is not
      {
        CConfigSection *sSection = this->GetSection(sSectionText.c_str(), 1);
        if (sSection)
          this->ParseAddSectionVars(sSection, spConfig, i, iConfigSize);
      }
    }
  }

  return true;
}

// address=[0x2ef0120]
// Decompiled from std::string *__stdcall CConfigManager::ParseFindSection(std::string *a1, char *a2, int *a3, const int *a4)
std::string CConfigManager::ParseFindSection(char *a2, int &a3, int const &a4)
{
  std::string Line; // [esp+4h] [ebp-5Ch]
  int v6;           // [esp+Ch] [ebp-54h]
  int v7;           // [esp+14h] [ebp-4Ch]
  std::string v8;   // [esp+18h] [ebp-48h] BYREF
  std::string v9;   // [esp+34h] [ebp-2Ch] BYREF
  int v10;          // [esp+5Ch] [ebp-4h]

  v9 = "";
  v10 = 0;
  while (a3 < a4)
  {
    Line = this->ParseGetLine(a2, a3, a4);
    if (Line.length())
    {
      v7 = Line.find("[", 0);
      v6 = Line.find("]", 0);
      if (v7 >= 0 && v6 >= 0 && v7 < v6)
      {
        return Line.substr(v7 + 1, v6 - v7 - 1);
      }
    }
  }

  return "";
}

// address=[0x2ef0270]
// Decompiled from void __fastcall CConfigManager::ParseAddSectionVars(  CConfigManager *this,  int a2,  struct CConfigSection *pSection,  char *a4,  int *a5,  int *a6)
void CConfigManager::ParseAddSectionVars(class CConfigSection *pSection, char *a4, int &a5, int const &a6)
{

  char *v6;               // eax
  int DefineVar;          // eax
  char *v8;               // eax
  char *spValue;          // eax
  std::string v10;        // [esp+Ch] [ebp-4E8h]
  float v11;              // [esp+10h] [ebp-4E4h]
  int iVarType;           // [esp+14h] [ebp-4E0h]
  std::string *v13;       // [esp+18h] [ebp-4DCh]
  std::string Line;       // [esp+1Ch] [ebp-4D8h]
  int v15;                // [esp+24h] [ebp-4D0h]
  int v16;                // [esp+28h] [ebp-4CCh] BYREF
  int v17;                // [esp+2Ch] [ebp-4C8h]
  CConfigManager *v18;    // [esp+30h] [ebp-4C4h]
  int iSize;              // [esp+34h] [ebp-4C0h] BYREF
  char v20;               // [esp+3Bh] [ebp-4B9h]
  std::string v21;        // [esp+3Ch] [ebp-4B8h] BYREF
  std::string v22;        // [esp+58h] [ebp-49Ch] BYREF
  std::string v23;        // [esp+74h] [ebp-480h] BYREF
  std::string spVarName;  // [esp+90h] [ebp-464h] BYREF
  std::string spVarValue; // [esp+ACh] [ebp-448h] BYREF
  std::string v26;        // [esp+C8h] [ebp-42Ch] BYREF
  int pArrayBuffer[256];  // [esp+E4h] [ebp-410h] BYREF
  int v28;                // [esp+4F0h] [ebp-4h]

  bool bFoundSection = false;
  while (a5 < a6)
  {
    Line = this->ParseGetLine(a4, a5, a6);
    if (Line.length())
    {
      if (!Line.find("}", 0) || !Line.find("[", 0))
      {
        return;
      }
      if (!Line.find("{", 0))
      {
        bFoundSection = true;
        break;
      }
    }
  }
  if (bFoundSection)
  {
    while (a5 < a6)
    {
      Line = this->ParseGetLine(a4, a5, a6);
      if (Line.length())
      {
        if (!Line.find("}", 0))
          break;
        iVarType = this->ParseGetVar(Line, spVarName, spVarValue);
        switch (iVarType)
        {
        case T_CFGVAR_TYPE_INT:
          if (Line.find('<', 0) >= 0)
          {
            DefineVar = this->ParseGetDefineVar(spVarValue);
          }
          else
          {
            DefineVar = atoi(spVarValue.c_str());
          }
          pSection->AddVar(spVarName, DefineVar);
          break;
        case T_CFGVAR_TYPE_INT_ARRAY:
          iSize = atoi(spVarValue.c_str());
          if (iSize <= 0)
          {
            if (BBSupportDbgReport(
                    1,
                    "Source\\ConfigManager\\ConfigManager.cpp",
                    802,
                    "CConfigManager::ParseAddSectionVars(): Invalid array size!") == 1)
              __debugbreak();
          }
          else
          {
            if (iSize > 255)
            {
              iSize = 255;
              if (BBSupportDbgReport(
                      1,
                      "Source\\ConfigManager\\ConfigManager.cpp",
                      785,
                      "CConfigManager::ParseAddSectionVars(): Array size too large!") == 1)
                __debugbreak();
            }
            int iArrayIndex = 0;
            this->ParseGetArrayVars(v26, pArrayBuffer, iArrayIndex, iSize);
            while (iArrayIndex < iSize && a5 < a6)
            {
              Line = this->ParseGetLine(a4, a5, a6);
              if (Line.length())
                this->ParseGetArrayVars(v26, pArrayBuffer, iArrayIndex, iSize);
            }
            pSection->AddVar(spVarName, pArrayBuffer, iSize);
          }
          break;
        case T_CFGVAR_TYPE_FLOAT:
          pSection->AddVar(spVarName, (float)atof(spVarValue.c_str()));
          break;
        case T_CFGVAR_TYPE_STRING:
          pSection->AddVar(spVarName, spVarValue);
          break;
        default:
          continue;
        }
      }
    }
  }
}

// address=[0x2ef07d0]
// Decompiled from std::string *__stdcall CConfigManager::ParseGetLine(std::string *a1, int a2, _DWORD *a3, _DWORD *a4)
std::string CConfigManager::ParseGetLine(char *a2, int &a3, int const &a4)
{
  char v5;        // [esp+Fh] [ebp-2Dh]
  std::string v6; // [esp+10h] [ebp-2Ch] BYREF
  int v7;         // [esp+38h] [ebp-4h]

  std::string sLine = "";

  v7 = 0;
  v5 = 1;
  if (a2[a3] == ';')
  {
    while (a3 < a4 && a2[a3] != '\r')
      ++a3;
  }
  else
  {
    while (a3 < a4 && a2[a3] != '\r')
    {
      if (a2[a3] != ' ' && a2[a3] != '\t')
        v5 = 0;
      if (!v5)
        sLine += a2[a3];
      ++a3;
    }
  }
  a3 += 2; // Skip \r\n
  if (v5)
    return "";

  return sLine;
}

// address=[0x2ef0960]
// Decompiled from int __stdcall CConfigManager::ParseGetVar(void *a1, void *a2, void *a3)
enum T_CFGVAR_TYPE CConfigManager::ParseGetVar(std::string &arg0, std::string &_srVarName, std::string &_srVarValue)
{
  int v4;                                         // eax
  int v5;                                         // eax
  size_t v6;                                      // eax
  std::string v7;                                 // eax
  int v8;                                         // eax
  int v9;                                         // [esp+4h] [ebp-164h]
  std::string v12;                                // [esp+10h] [ebp-158h]
  std::string v13;                                // [esp+18h] [ebp-150h]
  std::string v14;                                // [esp+1Ch] [ebp-14Ch]
  std::string v15;                                // [esp+20h] [ebp-148h]
  std::string v16;                                // [esp+24h] [ebp-144h]
  std::string v17;                                // [esp+28h] [ebp-140h]
  int v18;                                        // [esp+2Ch] [ebp-13Ch]
  const char *v19;                                // [esp+30h] [ebp-138h]
  int iFirstWhitespace;                           // [esp+38h] [ebp-130h]
  int a3;                                         // [esp+3Ch] [ebp-12Ch]
  const char *spVarValue;                         // [esp+44h] [ebp-124h]
  int iBracketStart;                              // [esp+48h] [ebp-120h]
  enum T_CFGVAR_TYPE v24 = T_CFGVAR_TYPE_UNKNOWN; // [esp+4Ch] [ebp-11Ch]
  int iEqualsIndex;                               // [esp+50h] [ebp-118h]
  int iLastWhitespace;                            // [esp+54h] [ebp-114h]
  int iTab;                                       // [esp+58h] [ebp-110h]
  int iSpace;                                     // [esp+5Ch] [ebp-10Ch]
  unsigned int k;                                 // [esp+60h] [ebp-108h]
  unsigned int i;                                 // [esp+64h] [ebp-104h]
  signed int j;                                   // [esp+64h] [ebp-104h]
  std::string a2;                                 // [esp+68h] [ebp-100h] BYREF
  std::string v33;                                // [esp+84h] [ebp-E4h] BYREF
  std::string v34;                                // [esp+A0h] [ebp-C8h] BYREF
  std::string v35;                                // [esp+BCh] [ebp-ACh] BYREF
  std::string v36;                                // [esp+D8h] [ebp-90h] BYREF
  std::string v37;                                // [esp+F4h] [ebp-74h] BYREF
  std::string v38;                                // [esp+110h] [ebp-58h] BYREF
  std::string v39;                                // [esp+12Ch] [ebp-3Ch] BYREF
  std::string v40;                                // [esp+148h] [ebp-20h] BYREF

  iEqualsIndex = arg0.find("=", 0);
  if (iEqualsIndex < 0)
    return T_CFGVAR_TYPE_UNKNOWN;
  _srVarName = arg0.substr(0, iEqualsIndex);
  iSpace = _srVarName.find(" ", 0);
  iTab = _srVarName.find("\t", 0);
  iLastWhitespace = 0;
  if (iSpace <= 0 || iTab <= 0)
  {
    if (iSpace <= 0)
    {
      if (iTab > 0)
        iLastWhitespace = iTab;
    }
    else
    {
      iLastWhitespace = iSpace;
    }
  }
  else
  {
    if (iSpace >= iTab)
      iLastWhitespace = iTab;
    else
      iLastWhitespace = iSpace;
  }
  if (iLastWhitespace > 0)
  {
    _srVarName = _srVarName.substr(0, iLastWhitespace); // Trim whitespace from variable name
  }
  iBracketStart = _srVarName.find("[", 0);
  if (iBracketStart <= 0)
  {
    _srVarValue = arg0.substr(iEqualsIndex + 1, arg0.length() - (iEqualsIndex + 1));
    spVarValue = _srVarValue.c_str();
    iFirstWhitespace = 0;
    for (i = 0; i < _srVarValue.length(); ++i)
    {
      if (spVarValue[i] != ' ' && spVarValue[i] != '\t')
      {
        iFirstWhitespace = i;
        break;
      }
    }
    for (j = _srVarValue.length(); j > 0; --j)
    {
      if (spVarValue[j] != ' ' && spVarValue[j] != '\t')
      {
        v7 = _srVarValue.substr(iFirstWhitespace, j - iFirstWhitespace);
        goto LABEL_36;
      }
    }
    v7 = _srVarValue.substr(iFirstWhitespace, 0);
  LABEL_36:
    _srVarValue = v7;
    if (_srVarValue.find('"', 0) < 0)
    {
      if (_srVarValue.find('.', 0) < 0)
        return T_CFGVAR_TYPE_INT;
      else
        return T_CFGVAR_TYPE_FLOAT;
    }
    else
    {
      _srVarValue = _srVarValue.substr(1, _srVarValue.length() - 2);
      return T_CFGVAR_TYPE_STRING;
    }
  }
  else
  {
    _srVarValue = _srVarName.substr(iBracketStart + 1, _srVarName.find("]", 0) - (iBracketStart + 1));
    _srVarName = _srVarName.substr(0, iBracketStart);
    arg0 = arg0.substr(iEqualsIndex + 1, arg0.length() - (iEqualsIndex + 1));
    v19 = arg0.c_str();
    iFirstWhitespace = 0;
    for (k = 0; k < arg0.length(); ++k)
    {
      if (v19[k] != ' ' && v19[k] != '\t')
      {
        iFirstWhitespace = k;
        break;
      }
    }
    arg0 = arg0.substr(iFirstWhitespace, arg0.length() - iFirstWhitespace);
    return T_CFGVAR_TYPE_INT_ARRAY;
  }
}

// address=[0x2ef0ea0]
// Decompiled from void __stdcall CConfigManager::ParseGetArrayVars(int a1, int a2, _DWORD *a3, _DWORD *a4)
void CConfigManager::ParseGetArrayVars(std::string &a1, int *a3, int &a4, int &a5)
{
  char *v5;        // eax
  std::string *v7; // [esp+8h] [ebp-60h]
  int DefineVar;   // [esp+14h] [ebp-54h]
  int v9;          // [esp+18h] [ebp-50h]
  int v10;         // [esp+1Ch] [ebp-4Ch]
  std::string a2;  // [esp+20h] [ebp-48h] BYREF
  std::string v12; // [esp+3Ch] [ebp-2Ch] BYREF
  int v13;         // [esp+64h] [ebp-4h]

  v12 = "";

  do
  {
    v9 = a1.find(44, v10 + 1);
    if (v9 < 0)
      break;
    v12 = a1.substr(v10 + 1, v9 - (v10 + 1));

    if (v12.find('<', 0) >= 0)
    {
      DefineVar = this->ParseGetDefineVar(v12);
    }
    else
    {
      DefineVar = atoi(v12.c_str());
    }
    a3[a4++] = DefineVar;
    v10 = a1.find(',', v10 + 1);
    if (v10 < 0)
      break;
  } while (a4 < a5);
}

// address=[0x2ef1010]
// Decompiled from int __thiscall CConfigManager::ParseGetDefineVar(void *this, void *a2)
int CConfigManager::ParseGetDefineVar(std::string &a1)
{
  char *v2;        // eax
  std::string *v4; // [esp+4h] [ebp-2Ch]
  int v5;          // [esp+8h] [ebp-28h]
  std::string a2;  // [esp+10h] [ebp-20h] BYREF

  v5 = a1.find('>', 0);
  a1 = a1.substr(1, v5 - 1);
  return this->GetDefineValue(a1.c_str());
}

// address=[0x2ef1090]
// Decompiled from _DWORD *__stdcall CConfigManager::AddDefineVar(int a1, int a2)
void CConfigManager::AddDefineVar(std::string const &a1, int a2)
{
  this->m_mSectionIdMap[a1] = a2;
}

// address=[0x2ef10c0]
// Decompiled from CConfigSection *__thiscall CConfigManager::GetSection(CConfigManager *this, std::string *a2, char a3)
class CConfigSection *CConfigManager::GetSection(std::string const &_srSectionName, bool _bCreate)
{
  for (CConfigSection *Section : this->m_lSections)
  {
    if (!Section->Name().compare(_srSectionName)) // TODO: find out if case insensitive compare is needed here, as .compare is case sensitive and the original _stricmp is not
    {
      return Section;
    }
  }

  if (_bCreate)
  {
    CConfigSection *NewSection = new CConfigSection(_srSectionName);
    this->m_lSections.push_back(NewSection);
    return NewSection;
  }

  return nullptr;
}
