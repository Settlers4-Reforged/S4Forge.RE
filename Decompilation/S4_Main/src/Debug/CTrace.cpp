#include "CTrace.h"

#include <varargs.h>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>

#include <windows.h>

#include "CBBSupport.h"

// Definitions for class CTrace

// address=[0x14d3520]
// Decompiled from CTrace *__thiscall CTrace::CTrace(CTrace *this, const struct boost::exception_detail::clone_base *a2)
CTrace::CTrace(char const *_spType) : m_iId(0), spType(_spType), m_pPrev(nullptr) {}

// address=[0x14d3540]
// Decompiled from CTrace *__thiscall CTrace::CTrace(CTrace *this, const struct boost::exception_detail::clone_base *a2)
CTrace::CTrace(CTrace const &a2) = default;

// address=[0x14d3560]
// Decompiled from CTrace *__thiscall CTrace::~CTrace(CTrace *this)
CTrace::~CTrace(void) = default;

// address=[0x14d3580]
// Decompiled from _DWORD *__thiscall CTrace::operator_(_DWORD *this, int a2)
class CTrace &CTrace::operator=(class CTrace const &a2)
{
  this->spType = a2.spType;
  return *this;
}

// address=[0x14d35a0]
// Decompiled from void CTrace::Print(char *Format, ...)
void __cdecl CTrace::Print(char const *Format, ...)
{

  char Source[2048]; // [esp+4h] [ebp-804h] BYREF
  va_list va;        // [esp+814h] [ebp+Ch] BYREF

  va_start(va, Format);
  _vsnprintf(Source, 0x7FFu, Format, va);
  BBSupportTracePrint(0, Source);
}

// address=[0x14d3610]
// Decompiled from void CTrace::TextEinfuegen(char *Format, ...)
void __cdecl CTrace::TextEinfuegen(char const *Format, ...)
{

  char Buffer[2048]; // [esp+4h] [ebp-804h] BYREF
  va_list va;        // [esp+814h] [ebp+Ch] BYREF

  va_start(va, Format);
  _vsnprintf(Buffer, 0x7FFu, Format, va);
  BBSupportTracePrint(0, Buffer);
}

// address=[0x40329D0]
int s_uLatestTraceId = 0;
// address=[0x40329D4]
int s_uTraces = 0;
// address=[0x40329D8]
CTrace *pActiveTrace = nullptr;

// address=[0x14d3680]
// Decompiled from void __thiscall CTrace::TraceInitObject(CTrace *this, char const *a2)
void CTrace::TraceInitObject(char const *_spType)
{
  this->m_iId = ++s_uLatestTraceId;
  ++s_uTraces;
  this->spType = _spType;
  this->m_pPrev = pActiveTrace;
  pActiveTrace = this;
}

// address=[0x40329E0]
std::ofstream s_sTraceFileStream{}; //TODO: this seems to be unused in the game - nothing points to the object and I don't know what file this is supposed to be. Maybe the traceXXX.txt files, but not sure

// address=[0x14d36e0]
// Decompiled from int __thiscall CTrace::TracePrintHeader(CTrace *this)
void CTrace::TracePrintHeader(void)
{
  s_sTraceFileStream
      << std::setw(8LL) << timeGetTime()
      << std::hex << std::setw(9LL) << _threadid
      << std::dec << std::setw(6LL) << this->m_iId
      << std::setw(6LL) << s_uTraces
      << "  " << (this->spType ? this->spType : "<unknown object type>");

  // void *v1;                // eax
  // struct std::ostream *v2; // eax
  // int v3;                  // eax
  // struct std::ostream *v4; // eax
  // int v5;                  // eax
  // int v6;                  // eax
  // int v7;                  // eax
  // DWORD Time;              // [esp-28h] [ebp-6Ch]
  // void *v10;               // [esp-20h] [ebp-64h]
  // unsigned int uThreadId;  // [esp-1Ch] [ebp-60h]
  // void *v12;               // [esp-14h] [ebp-58h]
  // int iId;                 // [esp-10h] [ebp-54h]
  // void *v14;               // [esp-Ch] [ebp-50h]
  // int uTraces;             // [esp-8h] [ebp-4Ch]
  // _BYTE v16[16];           // [esp+0h] [ebp-44h] BYREF
  // _BYTE v17[16];           // [esp+10h] [ebp-34h] BYREF
  // _BYTE v18[16];           // [esp+20h] [ebp-24h] BYREF
  // _BYTE v19[16];           // [esp+30h] [ebp-14h] BYREF
  // uTraces = s_uTraces;
  // v14 = std::setw(6LL);
  // iId = this->m_iId;
  // v12 = std::setw(v18, 6LL);
  // uThreadId = j____threadid();
  // v10 = std::setw(v17, 9LL);
  // Time = timeGetTime();
  // v1 = std::setw(v16, 8LL);
  // v2 = (struct std::ostream *)std::operator<< <char, std::char_traits<char>, __int64>(byte_40329E0, v1);
  // std::ostream::operator<<(v2, Time);
  // v3 = std::ostream::operator<<(std::hex);
  // v4 = (struct std::ostream *)std::operator<< <char, std::char_traits<char>, __int64>(v3, v10);
  // std::ostream::operator<<(v4, uThreadId);
  // v5 = std::ostream::operator<<(std::dec);
  // std::operator<< <char, std::char_traits<char>, __int64>(v5, v12);
  // v6 = std::ostream::operator<<(iId);
  // std::operator<< <char, std::char_traits<char>, __int64>(v6, v14);
  // v7 = std::ostream::operator<<(uTraces);
  // std::operator<< <std::char_traits<char>>(v7, "  ");
  // if (this->spType)
  //   return std::operator<< <std::char_traits<char>>((int)byte_40329E0, this->spType);
  // else
  //   return std::operator<< <std::char_traits<char>>((int)byte_40329E0, "<unknown object type>");
}
