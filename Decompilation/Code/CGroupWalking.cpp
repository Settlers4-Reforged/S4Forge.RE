#include "CGroupWalking.h"

// Definitions for class CGroupWalking

// address=[0x15f65e0]
// Decompiled from CGroupWalking *__thiscall CGroupWalking::CGroupWalking(CGroupWalking *this)

 CGroupWalking::CGroupWalking(void) {
  
  BB::ZeroMemPtr(this, 0x10u);
  return this;
}


// address=[0x15f6600]
// Decompiled from // public: void __thiscall CGroupWalking::SetFast(void)
int CGroupWalking::SetFast()

void  CGroupWalking::SetFast(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 4; ++i )
    result = i + 1;
  return result;
}


// address=[0x15f6630]
// Decompiled from // public: void __thiscall CGroupWalking::SetNormal(void)
int CGroupWalking::SetNormal()

void  CGroupWalking::SetNormal(void) {
  
  int result; // eax
  int i; // [esp+4h] [ebp-4h]

  for ( i = 0; i < 4; ++i )
    result = i + 1;
  return result;
}


