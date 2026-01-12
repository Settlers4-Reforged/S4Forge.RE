#include "CLinkList.h"

// Definitions for class CLinkList

// address=[0x1346460]
// Decompiled from int __thiscall CLinkList::operator[](void *this, int a2)

unsigned short const &  CLinkList::operator[](int)const {
  
  return (int)this + 2 * a2 + 4;
}


// address=[0x13469a0]
// Decompiled from int __thiscall CLinkList::Size(unsigned __int8 *this)

int  CLinkList::Size(void)const {
  
  return *this;
}


// address=[0x15e2ec0]
// Decompiled from int __thiscall CLinkList::DbgPrint(CLinkList *this)

void  CLinkList::DbgPrint(void)const {
  
  int v2; // [esp+0h] [ebp-1010h]
  int i; // [esp+4h] [ebp-100Ch]
  char Destination[2048]; // [esp+Ch] [ebp-1004h] BYREF
  char Source[2048]; // [esp+80Ch] [ebp-804h] BYREF

  memset(Source, 0, sizeof(Source));
  j___snprintf(
    Source,
    0x800u,
    "LinkList %08x: Cnt %2i M %02x Own %4i",
    this,
    *(unsigned __int8 *)this,
    *((unsigned __int8 *)this + 1),
    *((unsigned __int16 *)this + 1));
  if ( !*(_BYTE *)this )
    return CTrace::Print(Source);
  j__strcpy_0(Destination, Source);
  j___snprintf(Source, 0x800u, "%s; %i", Destination, *((unsigned __int16 *)this + 2));
  v2 = *(unsigned __int8 *)this;
  for ( i = 1; i < v2; ++i )
  {
    j__strcpy_0(Destination, Source);
    j___snprintf(Source, 0x800u, "%s,%i", Destination, *((unsigned __int16 *)this + i + 2));
  }
  return CTrace::Print(Source);
}


// address=[0x15e6e60]
// Decompiled from _DWORD *__thiscall CLinkList::operator=(_DWORD *this, unsigned __int8 *a2)

class CLinkList &  CLinkList::operator=(class CLinkList const &) {
  
  int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  v3 = (*a2 + 3) / 2;
  for ( i = 0; i < v3; ++i )
    this[i] = *(_DWORD *)&a2[4 * i];
  return this;
}


// address=[0x15e6ed0]
// Decompiled from _BYTE *__thiscall CLinkList::operator=(_BYTE *this, CIntLinkList *a2)

class CLinkList &  CLinkList::operator=(class CIntLinkList const &) {
  
  int v3; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  v3 = CIntLinkList::Size(a2);
  *this = v3;
  this[1] = -3;
  *((_WORD *)this + 1) = CIntLinkList::OwnerTileId(a2);
  for ( i = 0; i < v3; ++i )
    *(_WORD *)&this[2 * i + 4] = *(_WORD *)CIntLinkList::operator[](i);
  return this;
}


// address=[0x15e7230]
// Decompiled from char *__thiscall CLinkList::Link(CLinkList *this, int a2)

class CLink const &  CLinkList::Link(int)const {
  
  return (char *)this + 2 * a2 + 4;
}


// address=[0x15e72e0]
// Decompiled from int __thiscall CLinkList::OwnerTileId(CLinkList *this)

int  CLinkList::OwnerTileId(void)const {
  
  return *((unsigned __int16 *)this + 1);
}


// address=[0x15e7300]
// Decompiled from char __thiscall CLinkList::SearchForLinkTileId(CLinkList *this, int a2)

bool  CLinkList::SearchForLinkTileId(int)const {
  
  int i; // eax
  int v5; // [esp+4h] [ebp-4h]

  v5 = 0;
  for ( i = CLinkList::Size((unsigned __int8 *)this); v5 < i; i = CLinkList::Size((unsigned __int8 *)this) )
  {
    if ( *((unsigned __int16 *)this + v5 + 2) == a2 )
      return 1;
    ++v5;
  }
  return 0;
}


// address=[0x15f49c0]
// Decompiled from int __thiscall CLinkList::Marker(CLinkList *this)

int  CLinkList::Marker(void)const {
  
  return *((unsigned __int8 *)this + 1);
}


