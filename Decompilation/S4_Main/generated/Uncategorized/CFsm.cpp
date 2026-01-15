#include "CFsm.h"

// Definitions for class CFsm

// address=[0x1460490]
// Decompiled from int __thiscall CFsm::CurrentState(CFsm *this)
int  CFsm::CurrentState(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x2f05d80]
// Decompiled from CFsm *__thiscall CFsm::CFsm(CFsm *this, struct IEventHandler *a2, int a3, int a4)
 CFsm::CFsm(class IEventHandler *,int,int) {
  
  *(_DWORD *)this = a3;
  std::list<CFsm::SEvent *>::list<CFsm::SEvent *>((char *)this + 12);
  *((_DWORD *)this + 6) = a2;
  *((_DWORD *)this + 2) = a4;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 1) = operator new[](16 * *(_DWORD *)this);
  memset(*((void **)this + 1), -1, 16 * *(_DWORD *)this);
  return this;
}


// address=[0x2f05e40]
// Decompiled from int __thiscall CFsm::~CFsm(CFsm *this)
 CFsm::~CFsm(void) {
  
  void *C; // [esp+0h] [ebp-8h]

  if ( !*((_DWORD *)this + 1) )
    return std::list<CFsm::SEvent *>::~list<CFsm::SEvent *>(C, this);
  C = (void *)*((_DWORD *)this + 1);
  operator delete[](C);
  return std::list<CFsm::SEvent *>::~list<CFsm::SEvent *>(C, this);
}


// address=[0x2f05e80]
// Decompiled from int __thiscall CFsm::DefineTransition(CFsm *this, int a2, int a3, int a4, int a5)
int  CFsm::DefineTransition(int,int,int,int) {
  
  int v7; // [esp+4h] [ebp-4h]

  v7 = CFsm::Hash(this, a2, a4);
  if ( v7 == -1 )
    return v7;
  *(_DWORD *)(*((_DWORD *)this + 1) + 16 * v7) = a2;
  *(_DWORD *)(*((_DWORD *)this + 1) + 16 * v7 + 4) = a3;
  *(_DWORD *)(*((_DWORD *)this + 1) + 16 * v7 + 8) = a4;
  *(_DWORD *)(*((_DWORD *)this + 1) + 16 * v7 + 12) = a5;
  return v7;
}


// address=[0x2f05f00]
// Decompiled from int __thiscall CFsm::Control(CFsm *this, int a2, int a3)
int  CFsm::Control(int,void *) {
  
  void *C; // [esp+0h] [ebp-14h]
  int v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+4h] [ebp-10h]
  int v7; // [esp+8h] [ebp-Ch]
  _DWORD *v8; // [esp+Ch] [ebp-8h]

  v5 = 0;
  CFsm::InsertInQueue(a2, a3);
  v8 = *(_DWORD **)std::list<CFsm::SEvent *>::front();
  while ( v8 )
  {
    v7 = CFsm::Hash(this, *v8);
    if ( v7 < 0 || *(_DWORD *)(*((_DWORD *)this + 1) + 16 * v7 + 12) == -1 )
    {
      v6 = (**(unsigned __int8 (__thiscall ***)(_DWORD, _DWORD))(*((_DWORD *)this + 6) + 4))(*((_DWORD *)this + 6), *v8);
    }
    else
    {
      v6 = (*(unsigned __int8 (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)(*((_DWORD *)this + 6) + 4)
                                                             + 4 * *(_DWORD *)(*((_DWORD *)this + 1) + 16 * v7 + 12)))(
             *((_DWORD *)this + 6),
             v8[1]);
      *((_DWORD *)this + 2) = *(_DWORD *)(*((_DWORD *)this + 1) + 16 * v7 + 4);
    }
    std::list<CFsm::SEvent *>::pop_front(C, v6);
    C = v8;
    operator delete(v8);
    if ( std::list<CFsm::SEvent *>::size((char *)this + 12) )
      v8 = *(_DWORD **)std::list<CFsm::SEvent *>::front();
    else
      v8 = 0;
  }
  return v5;
}


// address=[0x2f06060]
// Decompiled from _DWORD *__stdcall CFsm::GenerateEvent(int a1, int a2)
void  CFsm::GenerateEvent(int,void *) {
  
  return CFsm::InsertInQueue(a1, a2);
}


// address=[0x2f06080]
// Decompiled from _DWORD *__stdcall CFsm::InsertInQueue(int a1, int a2)
void  CFsm::InsertInQueue(int,void *) {
  
  _DWORD *result; // eax
  _DWORD *v3; // [esp+4h] [ebp-Ch]
  _DWORD *v4; // [esp+8h] [ebp-8h]
  _DWORD *v5; // [esp+Ch] [ebp-4h] BYREF

  v4 = operator new(8u);
  if ( v4 )
  {
    *v4 = 0;
    v4[1] = 0;
    v3 = v4;
  }
  else
  {
    v3 = 0;
  }
  result = v3;
  v5 = v3;
  if ( !v3 )
    return result;
  *v5 = a1;
  v5[1] = a2;
  return (_DWORD *)std::list<CFsm::SEvent *>::push_back((int)&v5);
}


// address=[0x2f060f0]
// Decompiled from int __thiscall CFsm::Hash(CFsm *this, int a2, int a3)
int  CFsm::Hash(int,int) {
  
  int v4; // [esp+0h] [ebp-Ch]
  int v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  v4 = (a2 + (a3 << 8)) % *(_DWORD *)this;
  while ( *(_DWORD *)(*((_DWORD *)this + 1) + 16 * ((v5 + v4) % *(_DWORD *)this) + 12) != -1 && v5 < *(_DWORD *)this )
    ++v5;
  if ( v5 < *(_DWORD *)this )
    return (v5 + v4) % *(_DWORD *)this;
  else
    return -1;
}


// address=[0x2f06170]
// Decompiled from int __thiscall CFsm::Hash(CFsm *this, int a2)
int  CFsm::Hash(int) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  v4 = 0;
  v3 = (*((_DWORD *)this + 2) + (a2 << 8)) % *(_DWORD *)this;
  while ( (*(_DWORD *)(*((_DWORD *)this + 1) + 16 * ((v4 + v3) % *(_DWORD *)this)) != *((_DWORD *)this + 2)
        || *(_DWORD *)(*((_DWORD *)this + 1) + 16 * ((v4 + v3) % *(_DWORD *)this) + 8) != a2)
       && v4 < *(_DWORD *)this )
    ++v4;
  if ( v4 < *(_DWORD *)this )
    return (v4 + v3) % *(_DWORD *)this;
  else
    return -1;
}


