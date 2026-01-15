#include "CIntLinkList.h"

// Definitions for class CIntLinkList

// address=[0x15e2e50]
// Decompiled from CIntLinkList *__thiscall CIntLinkList::Init(CIntLinkList *this, int a2)
void  CIntLinkList::Init(int) {
  
  CIntLinkList *result; // eax

  result = this;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = a2;
  return result;
}


// address=[0x15e2e70]
// Decompiled from char __thiscall CIntLinkList::SearchBackwards(CIntLinkList *this, int a2)
bool  CIntLinkList::SearchBackwards(int) {
  
  int i; // [esp+8h] [ebp-4h]

  for ( i = *(_DWORD *)this - 1; i >= 0; --i )
  {
    if ( *((_DWORD *)this + i + 2) == a2 )
      return 1;
  }
  return 0;
}


// address=[0x15e6f60]
// Decompiled from int __thiscall CIntLinkList::operator[](void *this, int a2)
int const &  CIntLinkList::operator[](int)const {
  
  return (int)this + 4 * a2 + 8;
}


// address=[0x15e72c0]
// Decompiled from int __thiscall CIntLinkList::OwnerTileId(CIntLinkList *this)
int  CIntLinkList::OwnerTileId(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x15e7430]
// Decompiled from int __thiscall CIntLinkList::Size(CIntLinkList *this)
int  CIntLinkList::Size(void)const {
  
  return *(_DWORD *)this;
}


// address=[0x15f3ea0]
// Decompiled from CIntLinkList *__thiscall CIntLinkList::CIntLinkList(CIntLinkList *this, int a2)
 CIntLinkList::CIntLinkList(int) {
  
  CIntLinkList::Init(this, a2);
  return this;
}


// address=[0x15f4010]
// Decompiled from int __thiscall CIntLinkList::operator[](void *this, int a2)
int &  CIntLinkList::operator[](int) {
  
  return (int)this + 4 * a2 + 8;
}


// address=[0x15f40e0]
// Decompiled from CIntLinkList *__thiscall CIntLinkList::`default constructor closure'(CIntLinkList *this)
void  CIntLinkList::`default constructor closure'(void) {
  
  return CIntLinkList::CIntLinkList(this, 0);
}


// address=[0x15f5620]
// Decompiled from CIntLinkList *__thiscall CIntLinkList::PushBack(CIntLinkList *this, int a2)
void  CIntLinkList::PushBack(int) {
  
  CIntLinkList *result; // eax

  *((_DWORD *)this + *(_DWORD *)this + 2) = a2;
  result = this;
  ++*(_DWORD *)this;
  return result;
}


// address=[0x15f5820]
// Decompiled from CIntLinkList *__thiscall CIntLinkList::SetOwnerTileId(CIntLinkList *this, int a2)
void  CIntLinkList::SetOwnerTileId(int) {
  
  CIntLinkList *result; // eax

  result = this;
  *((_DWORD *)this + 1) = a2;
  return result;
}


