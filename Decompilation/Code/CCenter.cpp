#include "CCenter.h"

// Definitions for class CCenter

// address=[0x15f4100]
// Decompiled from int __thiscall CCenter::Add(CCenter *this, int a2, int a3)

void  CCenter::Add(int,int) {
  
  int result; // eax

  *(_DWORD *)this += a2 + 0x100000;
  result = a3 + *((_DWORD *)this + 1);
  *((_DWORD *)this + 1) = result;
  return result;
}


// address=[0x15f4340]
// Decompiled from int __thiscall CCenter::Count(CCenter *this)

int  CCenter::Count(void)const {
  
  return *(int *)this >> 20;
}


// address=[0x15f60b0]
// Decompiled from int __thiscall CCenter::X(CCenter *this)

int  CCenter::X(void)const {
  
  return *(_DWORD *)this & 0xFFFFF;
}


// address=[0x15f60d0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CCenter::Y(CCenter *this)

int  CCenter::Y(void)const {
  
  return *((_DWORD *)this + 1);
}


