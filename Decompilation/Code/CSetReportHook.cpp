#include "CSetReportHook.h"

// Definitions for class CSetReportHook

// address=[0x14d3880]
// Decompiled from CSetReportHook *__thiscall CSetReportHook::CSetReportHook(CSetReportHook *this)
 CSetReportHook::CSetReportHook(void) {
  
  j___CrtSetReportHook(sub_14D37F0);
  j___CrtSetReportMode(0, 4);
  j___CrtSetReportMode(1, 4);
  j___CrtSetReportMode(2, 4);
  return this;
}


// address=[0x14d38c0]
// Decompiled from int __fastcall CSetReportHook::_CSetReportHook(char a1)
 CSetReportHook::~CSetReportHook(void) {
  
  int (__cdecl *v3)(int, int, int); // [esp+4h] [ebp-4h]

  v3 = (int (__cdecl *)(int, int, int))j___CrtSetReportHook(0);
  j___CrtSetReportMode(1, 4);
  if ( v3 != sub_14D37F0 )
    j___CrtDbgReport(1, (char)"Main\\Trace.cpp", 624, 0, "The CRT reporting function has been changed!", a1);
  j___CrtSetReportMode(0, 2);
  j___CrtSetReportMode(1, 2);
  return j___CrtSetReportMode(2, 2);
}


