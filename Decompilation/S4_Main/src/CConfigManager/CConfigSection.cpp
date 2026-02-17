#include "CConfigSection.h"

#include "./Var/CConfigVarFloat.h"
#include "./Var/CConfigVarInt.h"
#include "./Var/CConfigVarIntArray.h"
#include "./Var/CConfigVarString.h"

#include "CBB/CBBSupport.h"
#include "../File/CFile.h"

#include <cstdio>
#include <cstring>

// Definitions for class CConfigSection

// address=[0x2eef260]
// Decompiled from CConfigSection *__thiscall CConfigSection::CConfigSection(CConfigSection *this, std::string *a2)
CConfigSection::CConfigSection(std::string const &a2) : m_spName(a2) {}

// address=[0x2eef2d0]
// Decompiled from void __thiscall sub_32EF2D0(void *this)
CConfigSection::~CConfigSection(void)
{
  for (auto &entry : this->m_mConfigs)
  {
    CConfigVar *var = entry.second;
    if (var && !var->Static())
    {
      delete var;
      entry.second = nullptr;
    }
  }

  this->m_mConfigs.clear();
}

// address=[0x2eef3f0]
// Decompiled from bool __thiscall CConfigSection::VarExists(CConfigSection *this, std::string *a2)
bool CConfigSection::VarExists(std::string const &a2)
{
  return this->m_mConfigs.find(a2) != this->m_mConfigs.end();
}

// address=[0x2eef490]
// Decompiled from int *__thiscall CConfigSection::AddVar(CConfigSection *this, std::string *a2, const int *Src, int a4)
void CConfigSection::AddVar(std::string const &a2, int const *Src, int a4)
{
  CConfigVar *var = this->GetVar(a2);
  if (var)
  {
    if (var->Type() == T_CFGVAR_TYPE_INT_ARRAY && var->Size() == a4)
    {
      int *dst = var->GetIntArray();
      if (dst)
      {
        if (Src)
          memcpy(dst, Src, 4 * a4);
        else
          memset(dst, 0, 4 * a4);
      }
      else
      {
        if (BBSupportDbgReport(
                1,
                "Source\\ConfigManager\\ConfigManager.cpp",
                254,
                "CConfigSection::AddVar() [int array]: Invalid int array pointer!") == 1)
        {
          __debugbreak();
        }
      }
    }
    else
    {
      if (BBSupportDbgReport(
              1,
              "Source\\ConfigManager\\ConfigManager.cpp",
              259,
              "CConfigSection::AddVar() [int array]: Config var type / size mismatch!") == 1)
      {
        __debugbreak();
      }
    }
    return;
  }

  this->m_mConfigs[a2] = new CConfigVarIntArray(Src, a4);
}

// address=[0x2eef600]
// Decompiled from void __thiscall CConfigSection::AddVar(CConfigSection *this, std::string *a2, int a3)
void CConfigSection::AddVar(std::string const &a2, int a3)
{
  CConfigVar *var = this->GetVar(a2);
  if (var)
  {
    var->SetValue(a3);
    return;
  }

  this->m_mConfigs[a2] = new CConfigVarInt(a3);
}

// address=[0x2eef6d0]
// Decompiled from void __thiscall CConfigSection::AddVar(CConfigSection *this, std::string *a2, float a3)
void CConfigSection::AddVar(std::string const &a2, float a3)
{
  CConfigVar *var = this->GetVar(a2);
  if (var)
  {
    var->SetValue(a3);
    return;
  }

  this->m_mConfigs[a2] = new CConfigVarFloat(a3);
}

// address=[0x2eef7b0]
// Decompiled from void __thiscall CConfigSection::AddVar(CConfigSection *this, std::string *a2, std::string *a3)
void CConfigSection::AddVar(std::string const &a2, std::string const &a3)
{
  CConfigVar *var = this->GetVar(a2);
  if (var)
  {
    var->SetValue(a3);
    return;
  }

  this->m_mConfigs[a2] = new CConfigVarString(a3);
}

// address=[0x2eef880]
// Decompiled from void __thiscall CConfigSection::AddStaticConfigVar(CConfigSection *this, std::string *a2, int a3)
void CConfigSection::AddStaticConfigVar(std::string const &a2, class CConfigVar &a3)
{
  if (this->GetVar(a2))
  {
    if (BBSupportDbgReport(
            1,
            "Source\\ConfigManager\\ConfigManager.cpp",
            348,
            "CConfigSection::AddStaticConfigVar(): Static config var already exists!") == 1)
    {
      __debugbreak();
    }
    return;
  }

  this->m_mConfigs[a2] = &a3;
}

// address=[0x2eef8e0]
// Decompiled from char __thiscall CConfigSection::Save(CConfigSection *this, wchar_t *FileName)
bool CConfigSection::Save(wchar_t const *FileName)
{
  CFile pConfigFile;
  constexpr size_t ElementSize = 1;
  char spFileContentBuffer[512] = {};

  pConfigFile.Open(FileName, 10, CFileLog);

  sprintf(spFileContentBuffer, "//\r\n// Automatically generated file. Do not edit!\r\n// \r\n\r\n");
  pConfigFile.Write(spFileContentBuffer, ElementSize, strlen(spFileContentBuffer), CFileLog);

  snprintf(spFileContentBuffer, 511u, "[%s]\r\n{\r\n", this->m_spName.c_str());
  pConfigFile.Write(spFileContentBuffer, ElementSize, strlen(spFileContentBuffer), CFileLog);

  for (auto it = this->m_mConfigs.begin(); it != this->m_mConfigs.end(); ++it)
  {
    CConfigVar *var = it->second;
    switch (var->Type())
    {
    case T_CFGVAR_TYPE_INT:
      sprintf(spFileContentBuffer, "    %s = %d\r\n", it->first.c_str(), var->GetIntValue());
      break;

    case T_CFGVAR_TYPE_INT_ARRAY:
    {
      const int *array = var->GetIntArray();
      const int count = var->Size();
      if (array && count > 0)
      {
        sprintf(spFileContentBuffer, "    %s[%d] = ", it->first.c_str(), count);
        pConfigFile.Write(spFileContentBuffer, ElementSize, strlen(spFileContentBuffer), CFileLog);

        for (int i = 0; i < count - 1; ++i)
        {
          sprintf(spFileContentBuffer, "%d,", array[i]);
          pConfigFile.Write(spFileContentBuffer, ElementSize, strlen(spFileContentBuffer), CFileLog);
        }

        sprintf(spFileContentBuffer, "%d", array[count - 1]);
        pConfigFile.Write(spFileContentBuffer, ElementSize, strlen(spFileContentBuffer), CFileLog);
        sprintf(spFileContentBuffer, "\r\n");
      }
      break;
    }

    case T_CFGVAR_TYPE_FLOAT:
      sprintf(spFileContentBuffer, "    %s = %f\r\n", it->first.c_str(), var->GetFloatValue());
      break;

    case T_CFGVAR_TYPE_STRING:
      sprintf(spFileContentBuffer, "    %s = \"%s\"\r\n", it->first.c_str(), var->GetStringValue().c_str());
      break;

    default:
      spFileContentBuffer[0] = '\0';
      break;
    }

    pConfigFile.Write(spFileContentBuffer, ElementSize, strlen(spFileContentBuffer), CFileLog);
  }

  // NOTE: IDA output shows element-count=1 for this write call.
  pConfigFile.Write("}\r\n", ElementSize, 1, CFileLog);
  pConfigFile.Close(CFileLog);
  return true;
}

// address=[0x2efa130]
// Decompiled from CConfigVar *__thiscall CConfigSection::GetVar(CConfigSection *this, std::string *a2)
class CConfigVar *CConfigSection::GetVar(std::string const &a2)
{
  auto it = this->m_mConfigs.find(a2);
  if (it != this->m_mConfigs.end())
    return it->second;
  return nullptr;
}

// address=[0x2efa250]
// Decompiled from std::string *__thiscall CConfigSection::Name(CConfigSection *this)
std::string const &CConfigSection::Name(void)
{
  return this->m_spName;
}

// address=[0x2efa270]
// Decompiled from int __thiscall CConfigSection::NumberOfEntries(CConfigSection *this)
int CConfigSection::NumberOfEntries(void)
{
  return (int)this->m_mConfigs.size();
}
