#if FALSE
#include "CTrace.h"

// Definitions for class CTrace

// address=[0x14d3520]
// Decompiled from CTrace *__thiscall CTrace::CTrace(CTrace *this, const struct boost::exception_detail::clone_base *a2)
 CTrace::CTrace(char const * a2) {
  
  this->vftable = &CTrace::_vftable_;
  return this;
}


// address=[0x14d3540]
// Decompiled from CTrace *__thiscall CTrace::CTrace(CTrace *this, const struct boost::exception_detail::clone_base *a2)
 CTrace::CTrace(class CTrace const & a2) {
  
  this->vftable = &CTrace::_vftable_;
  return this;
}


// address=[0x14d3560]
// Decompiled from CTrace *__thiscall CTrace::~CTrace(CTrace *this)
 CTrace::~CTrace(void) {
  
  CTrace *result; // eax

  result = this;
  *(_DWORD *)this = &CTrace::_vftable_;
  return result;
}


// address=[0x14d3580]
// Decompiled from CTrace *__thiscall CTrace::operator_(CTrace *this, CTrace *a2)
class CTrace &  CTrace::operator=(class CTrace const & a2) {
  
  this->spType = a2->spType;
  return this;
}


// address=[0x14d35a0]
// Decompiled from void CTrace::Print(char *Format, ...)
void __cdecl CTrace::Print(char const * Format, ... a2) {
  
  char Source[2048]; // [esp+4h] [ebp-804h] BYREF
  va_list va; // [esp+814h] [ebp+Ch] BYREF

  va_start(va, Format);
  __vcrt_va_start_verify_argument_type<char const *>();
  j___vsnprintf(Source, 0x7FFu, Format, va);
  BBSupportTracePrint(0, Source);
}


// address=[0x14d3610]
// Decompiled from void CTrace::TextEinfuegen(char *Format, ...)
void __cdecl CTrace::TextEinfuegen(char const * Format, ... a2) {
  
  char Buffer[2048]; // [esp+4h] [ebp-804h] BYREF
  va_list va; // [esp+814h] [ebp+Ch] BYREF

  va_start(va, Format);
  __vcrt_va_start_verify_argument_type<char const *>();
  j___vsnprintf(Buffer, 0x7FFu, Format, va);
  BBSupportTracePrint(0, Buffer);
}


// address=[0x14d3680]
// Decompiled from void __thiscall CTrace::TraceInitObject(CTrace *this, char *a2)
void  CTrace::TraceInitObject(char const * a2) {
  
  this->m_iId = ++s_uLatestTraceId;
  ++s_uTraces;
  this->spType = a2;
  this->m_pPrev = pActiveTrace;
  pActiveTrace = this;
}


// address=[0x14d36e0]
// Decompiled from int __thiscall CTrace::TracePrintHeader(CTrace *this)
void  CTrace::TracePrintHeader(void) {
  
  void *v1; // eax
  struct std::ostream *v2; // eax
  char *v3; // eax
  char *v4; // eax
  struct std::ostream *v5; // eax
  char *v6; // eax
  char *v7; // eax
  int v8; // eax
  int v9; // eax
  DWORD Time; // [esp-28h] [ebp-6Ch]
  void *v12; // [esp-20h] [ebp-64h]
  unsigned int uThreadId; // [esp-1Ch] [ebp-60h]
  void *v14; // [esp-14h] [ebp-58h]
  int iId; // [esp-10h] [ebp-54h]
  void *v16; // [esp-Ch] [ebp-50h]
  int uTraces; // [esp-8h] [ebp-4Ch]
  _BYTE v18[16]; // [esp+0h] [ebp-44h] BYREF
  _BYTE v19[16]; // [esp+10h] [ebp-34h] BYREF
  _BYTE v20[16]; // [esp+20h] [ebp-24h] BYREF
  _BYTE v21[16]; // [esp+30h] [ebp-14h] BYREF

  uTraces = s_uTraces;
  v16 = std::setw(v21, 6LL);
  iId = this->m_iId;
  v14 = std::setw(v20, 6LL);
  uThreadId = j____threadid();
  v12 = std::setw(v19, 9LL);
  Time = timeGetTime();
  v1 = std::setw(v18, 8LL);
  v2 = (struct std::ostream *)std::operator<<<char,std::char_traits<char>,__int64>((int)byte_40329E0, (int)v1);
  v3 = (char *)std::ostream::operator<<(v2, Time);
  v4 = std::ostream::operator<<(v3, (void (__cdecl *)(char *))std::hex);
  v5 = (struct std::ostream *)std::operator<<<char,std::char_traits<char>,__int64>((int)v4, (int)v12);
  v6 = (char *)std::ostream::operator<<(v5, uThreadId);
  v7 = std::ostream::operator<<(v6, (void (__cdecl *)(char *))std::dec);
  std::operator<<<char,std::char_traits<char>,__int64>((int)v7, (int)v14);
  v8 = std::ostream::operator<<(iId);
  std::operator<<<char,std::char_traits<char>,__int64>(v8, (int)v16);
  v9 = std::ostream::operator<<(uTraces);
  std::operator<<<std::char_traits<char>>(v9, "  ");
  if ( this->spType )
    return std::operator<<<std::char_traits<char>>((int)byte_40329E0, this->spType);
  else
    return std::operator<<<std::char_traits<char>>((int)byte_40329E0, "<unknown object type>");
}


#endif // Already implemented
