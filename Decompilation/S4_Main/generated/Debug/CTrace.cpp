#include "CTrace.h"

// Definitions for class CTrace

// address=[0x14d3520]
// Decompiled from CTrace *__thiscall CTrace::CTrace(CTrace *this, const struct boost::exception_detail::clone_base *a2)
 CTrace::CTrace(char const *) {
  
  *(_DWORD *)this = &CTrace::_vftable_;
  return this;
}


// address=[0x14d3540]
// Decompiled from CTrace *__thiscall CTrace::CTrace(CTrace *this, const struct boost::exception_detail::clone_base *a2)
 CTrace::CTrace(class CTrace const &) {
  
  *(_DWORD *)this = &CTrace::_vftable_;
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
// Decompiled from _DWORD *__thiscall CTrace::operator_(_DWORD *this, int a2)
class CTrace &  CTrace::operator=(class CTrace const &) {
  
  this[2] = *(_DWORD *)(a2 + 8);
  return this;
}


// address=[0x14d35a0]
// Decompiled from void CTrace::Print(char *Format, ...)
static void __cdecl CTrace::Print(char const *,...) {
  
  char Source[2048]; // [esp+4h] [ebp-804h] BYREF
  va_list va; // [esp+814h] [ebp+Ch] BYREF

  va_start(va, Format);
  __vcrt_va_start_verify_argument_type<char const *>();
  j___vsnprintf(Source, 0x7FFu, Format, va);
  BBSupportTracePrint(0, Source);
}


// address=[0x14d3610]
// Decompiled from void CTrace::TextEinfuegen(char *Format, ...)
static void __cdecl CTrace::TextEinfuegen(char const *,...) {
  
  char Buffer[2048]; // [esp+4h] [ebp-804h] BYREF
  va_list va; // [esp+814h] [ebp+Ch] BYREF

  va_start(va, Format);
  __vcrt_va_start_verify_argument_type<char const *>();
  j___vsnprintf(Buffer, 0x7FFu, Format, va);
  BBSupportTracePrint(0, Buffer);
}


// address=[0x14d3680]
// Decompiled from _DWORD *__thiscall CTrace::TraceInitObject(_DWORD *this, int a2)
void  CTrace::TraceInitObject(char const *) {
  
  _DWORD *result; // eax

  this[1] = ++dword_40329D0;
  ++dword_40329D4;
  this[2] = a2;
  result = this;
  this[3] = dword_40329D8;
  dword_40329D8 = (int)this;
  return result;
}


// address=[0x14d36e0]
// Decompiled from int __thiscall CTrace::TracePrintHeader(void *this)
void  CTrace::TracePrintHeader(void) {
  
  int v1; // eax
  struct std::ostream *v2; // eax
  int v3; // eax
  struct std::ostream *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  DWORD Time; // [esp-28h] [ebp-6Ch]
  int v10; // [esp-20h] [ebp-64h]
  unsigned int v11; // [esp-1Ch] [ebp-60h]
  int v12; // [esp-14h] [ebp-58h]
  int v13; // [esp-10h] [ebp-54h]
  int v14; // [esp-Ch] [ebp-50h]
  int v15; // [esp-8h] [ebp-4Ch]
  _BYTE v16[16]; // [esp+0h] [ebp-44h] BYREF
  _BYTE v17[16]; // [esp+10h] [ebp-34h] BYREF
  _BYTE v18[16]; // [esp+20h] [ebp-24h] BYREF
  _BYTE v19[16]; // [esp+30h] [ebp-14h] BYREF
  void *v20; // [esp+40h] [ebp-4h]

  v20 = this;
  v15 = dword_40329D4;
  v14 = std::setw(v19, 6, 0);
  v13 = *((_DWORD *)v20 + 1);
  v12 = std::setw(v18, 6, 0);
  v11 = j____threadid();
  v10 = std::setw(v17, 9, 0);
  Time = timeGetTime();
  v1 = std::setw(v16, 8, 0);
  v2 = (struct std::ostream *)std::operator<<<char,std::char_traits<char>,__int64>(&unk_40329E0, v1);
  std::ostream::operator<<(v2, Time);
  v3 = std::ostream::operator<<(std::hex);
  v4 = (struct std::ostream *)std::operator<<<char,std::char_traits<char>,__int64>(v3, v10);
  std::ostream::operator<<(v4, v11);
  v5 = std::ostream::operator<<(std::dec);
  std::operator<<<char,std::char_traits<char>,__int64>(v5, v12);
  v6 = std::ostream::operator<<(v13);
  std::operator<<<char,std::char_traits<char>,__int64>(v6, v14);
  v7 = std::ostream::operator<<(v15);
  std::operator<<<std::char_traits<char>>(v7, "  ");
  if ( *((_DWORD *)v20 + 2) )
    return std::operator<<<std::char_traits<char>>((int)&unk_40329E0, *((char **)v20 + 2));
  else
    return std::operator<<<std::char_traits<char>>((int)&unk_40329E0, "<unknown object type>");
}


