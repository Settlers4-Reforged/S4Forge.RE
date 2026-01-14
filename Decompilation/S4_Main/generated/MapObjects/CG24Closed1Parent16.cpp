#include "all_headers.h"

// Definitions for class CG24Closed1Parent16

// address=[0x15d61b0]
// Decompiled from int __thiscall CG24Closed1Parent16::Closed(CG24Closed1Parent16 *this)
int  CG24Closed1Parent16::Closed(void)const {
  
  return *((unsigned __int8 *)this + 6);
}


// address=[0x15d6560]
// Decompiled from int __thiscall CG24Closed1Parent16::G(CG24Closed1Parent16 *this)
int  CG24Closed1Parent16::G(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x15d67e0]
// Decompiled from int __thiscall CG24Closed1Parent16::Parent(CG24Closed1Parent16 *this)
int  CG24Closed1Parent16::Parent(void)const {
  
  return *((unsigned __int16 *)this + 2);
}


// address=[0x15d6cb0]
// Decompiled from CG24Closed1Parent16 *__thiscall CG24Closed1Parent16::Set(  CG24Closed1Parent16 *this,  int a2,  __int16 a3,  bool a4,  char a5)
void  CG24Closed1Parent16::Set(int,int,bool,int) {
  
  CG24Closed1Parent16 *result; // eax

  *(_DWORD *)this = a2;
  *((_WORD *)this + 2) = a3;
  *((_BYTE *)this + 6) = a4;
  result = this;
  *((_BYTE *)this + 7) = a5;
  return result;
}


// address=[0x15d6d90]
// Decompiled from CG24Closed1Parent16 *__thiscall CG24Closed1Parent16::SetClosedFlag(CG24Closed1Parent16 *this)
void  CG24Closed1Parent16::SetClosedFlag(void) {
  
  CG24Closed1Parent16 *result; // eax

  result = this;
  *((_BYTE *)this + 6) = 1;
  return result;
}


// address=[0x15d6e50]
// Decompiled from int __thiscall CG24Closed1Parent16::State(CG24Closed1Parent16 *this)
int  CG24Closed1Parent16::State(void)const {
  
  return *((unsigned __int8 *)this + 7);
}


