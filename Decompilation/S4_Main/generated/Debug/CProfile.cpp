#include "CProfile.h"

// Definitions for class CProfile

// address=[0x2efd820]
// Decompiled from CProfile *__thiscall CProfile::CProfile(CProfile *this)
 CProfile::CProfile(void) {
  
  if ( !dword_46851B0 )
    sub_2EFDE40();
  CProfile::Clear(this);
  return this;
}


// address=[0x2efd850]
// Decompiled from BOOL __thiscall CProfile::Clear(LARGE_INTEGER *this)
void  CProfile::Clear(void) {
  
  BOOL result; // eax

  result = QueryPerformanceCounter(this);
  this[20].LowPart = 0;
  return result;
}


// address=[0x2efd880]
// Decompiled from BOOL __thiscall CProfile::Begin(LARGE_INTEGER *this)
void  CProfile::Begin(void) {
  
  return QueryPerformanceCounter(this + 2);
}


// address=[0x2efd8a0]
// Decompiled from LARGE_INTEGER *__thiscall CProfile::End(LARGE_INTEGER *this)
void  CProfile::End(void) {
  
  int v1; // eax
  unsigned int v2; // ecx
  LARGE_INTEGER *result; // eax

  QueryPerformanceCounter(this + 3);
  v2 = (unsigned __int64)(this[3].QuadPart - this[2].QuadPart) >> 32;
  v1 = this[3].LowPart - this[2].LowPart;
  this[1].QuadPart = __PAIR64__(this[1].HighPart, v1) + this[3].QuadPart - this[2].QuadPart;
  this[(this[20].LowPart & 0xF) + 4].QuadPart = __PAIR64__(v2, v1);
  result = this;
  ++this[20].LowPart;
  return result;
}


// address=[0x2efd920]
// Decompiled from double __thiscall CProfile::TimeMs(CProfile *this)
double  CProfile::TimeMs(void)const {
  
  if ( *((_DWORD *)this + 40) )
    return (double)*((__int64 *)this + 1) / (double)*((unsigned int *)this + 40) * *(double *)&qword_46851C0;
  else
    return 0.0;
}


// address=[0x2efd990]
// Decompiled from char *__thiscall CProfile::InfoStr(CProfile *this)
char const *  CProfile::InfoStr(void)const {
  
  double v1; // st7
  double v3; // [esp+8h] [ebp-2Ch]
  double v4; // [esp+10h] [ebp-24h]
  LARGE_INTEGER PerformanceCount; // [esp+20h] [ebp-14h] BYREF
  LONGLONG v6; // [esp+28h] [ebp-Ch]
  CProfile *v7; // [esp+30h] [ebp-4h]

  v7 = this;
  QueryPerformanceCounter(&PerformanceCount);
  v6 = PerformanceCount.QuadPart - *(_QWORD *)v7;
  if ( v6 <= 0 )
    v6 = 1LL;
  v4 = (double)*((__int64 *)v7 + 1) / (double)v6 * 100.0;
  v3 = (double)*((__int64 *)v7 + 1) * *(double *)&qword_46851C0;
  v1 = CProfile::TimeMs(v7);
  j___snprintf(byte_46851F8, 0x40u, "%5i x %6.3f ms = %9.1f ms, %5.2f%%", *((_DWORD *)v7 + 40), v1, v3, v4);
  return byte_46851F8;
}


// address=[0x2efda70]
// Decompiled from char *__thiscall CProfile::TraceStr(CProfile *this)
char const *  CProfile::TraceStr(void)const {
  
  double v1; // st7
  double v3; // [esp+8h] [ebp-ACh]
  double v4; // [esp+10h] [ebp-A4h]
  double v5; // [esp+18h] [ebp-9Ch]
  double v6; // [esp+20h] [ebp-94h]
  double v7; // [esp+28h] [ebp-8Ch]
  double v8; // [esp+30h] [ebp-84h]
  double v9; // [esp+38h] [ebp-7Ch]
  double v10; // [esp+40h] [ebp-74h]
  double v11; // [esp+48h] [ebp-6Ch]
  double v12; // [esp+50h] [ebp-64h]
  double v13; // [esp+58h] [ebp-5Ch]
  double v14; // [esp+60h] [ebp-54h]
  double v15; // [esp+68h] [ebp-4Ch]
  double v16; // [esp+70h] [ebp-44h]
  double v17; // [esp+78h] [ebp-3Ch]
  double v18; // [esp+80h] [ebp-34h]
  double v19; // [esp+88h] [ebp-2Ch]
  double v20; // [esp+90h] [ebp-24h]
  LARGE_INTEGER PerformanceCount; // [esp+A0h] [ebp-14h] BYREF
  LONGLONG v22; // [esp+A8h] [ebp-Ch]
  CProfile *v23; // [esp+B0h] [ebp-4h]

  v23 = this;
  QueryPerformanceCounter(&PerformanceCount);
  v22 = PerformanceCount.QuadPart - *(_QWORD *)v23;
  if ( v22 <= 0 )
    v22 = 1LL;
  v20 = (double)*((__int64 *)v23 + (*((_DWORD *)v23 + 40) & 0xF) + 4) * *(double *)&qword_46851C0;
  v19 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 1) & 0xF) + 4) * *(double *)&qword_46851C0;
  v18 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 2) & 0xF) + 4) * *(double *)&qword_46851C0;
  v17 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 3) & 0xF) + 4) * *(double *)&qword_46851C0;
  v16 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 4) & 0xF) + 4) * *(double *)&qword_46851C0;
  v15 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 5) & 0xF) + 4) * *(double *)&qword_46851C0;
  v14 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 6) & 0xF) + 4) * *(double *)&qword_46851C0;
  v13 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 7) & 0xF) + 4) * *(double *)&qword_46851C0;
  v12 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 8) & 0xF) + 4) * *(double *)&qword_46851C0;
  v11 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 9) & 0xF) + 4) * *(double *)&qword_46851C0;
  v10 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 10) & 0xF) + 4)
      * *(double *)&qword_46851C0;
  v9 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 11) & 0xF) + 4) * *(double *)&qword_46851C0;
  v8 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 12) & 0xF) + 4) * *(double *)&qword_46851C0;
  v7 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 13) & 0xF) + 4) * *(double *)&qword_46851C0;
  v6 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 14) & 0xF) + 4) * *(double *)&qword_46851C0;
  v5 = (double)*((__int64 *)v23 + (((unsigned __int8)*((_DWORD *)v23 + 40) + 15) & 0xF) + 4) * *(double *)&qword_46851C0;
  v4 = (double)*((__int64 *)v23 + 1) / (double)v22 * 100.0;
  v3 = (double)*((__int64 *)v23 + 1) * *(double *)&qword_46851C0;
  v1 = CProfile::TimeMs(v23);
  j___snprintf(
    byte_4685248,
    0x100u,
    "%i x %.3f ms = %.1f ms, %5.2f%% (%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f)",
    *((_DWORD *)v23 + 40),
    v1,
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20);
  return byte_4685248;
}


