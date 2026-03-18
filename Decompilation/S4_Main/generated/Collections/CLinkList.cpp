#if FALSE
#include "CLinkList.h"

// Definitions for class CLinkList

// address=[0x1346460]
// Decompiled from CLink *__thiscall CLinkList::operator[](struct CLinkList *this, int a2)
unsigned short const &  CLinkList::operator[](int a2)const {
  
  return &this->m_uOwnerTileId[a2 + 1];
}


// address=[0x13469a0]
// Decompiled from int __thiscall CLinkList::Size(struct CLinkList *this)
int  CLinkList::Size(void)const {
  
  return this->m_uSize;
}


// address=[0x15e2ec0]
// Decompiled from int __thiscall CLinkList::DbgPrint(CLinkList *this)
void  CLinkList::DbgPrint(void)const {
  
  int m_uSize; // [esp+0h] [ebp-1010h]
  int i; // [esp+4h] [ebp-100Ch]
  char Destination[2048]; // [esp+Ch] [ebp-1004h] BYREF
  char Source[2048]; // [esp+80Ch] [ebp-804h] BYREF

  memset(Source, 0, sizeof(Source));
  snprintf(
    Source,
    0x800u,
    "LinkList %08x: Cnt %2i M %02x Own %4i",
    this,
    this->m_uSize,
    this->m_uMarker,
    this->m_uOwnerTileId[0].m_uData);
  if ( !this->m_uSize )
    return CTrace::Print(Source);
  j__strcpy_0(Destination, Source);
  snprintf(Source, 2048u, "%s; %i", Destination, this->m_uOwnerTileId[1].m_uData);
  m_uSize = this->m_uSize;
  for ( i = 1; i < m_uSize; ++i )
  {
    j__strcpy_0(Destination, Source);
    snprintf(Source, 0x800u, "%s,%i", Destination, this->m_uOwnerTileId[i + 1].m_uData);
  }
  return CTrace::Print(Source);
}


// address=[0x15e6e60]
// Decompiled from struct CLinkList *__thiscall CLinkList::operator=(struct CLinkList *this, struct CLinkList *a2)
class CLinkList &  CLinkList::operator=(class CLinkList const & a2) {
  
  int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  v3 = (a2->m_uSize + 3) / 2;
  for ( i = 0; i < v3; ++i )
    this[i] = a2[i];
  return this;
}


// address=[0x15e6ed0]
// Decompiled from CLinkList *__thiscall CLinkList::operator=(CLinkList *this, CIntLinkList *a2)
class CLinkList &  CLinkList::operator=(class CIntLinkList const & a2) {
  
  int iSize; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  iSize = CIntLinkList::Size(a2);
  this->m_uSize = iSize;
  this->m_uMarker = -3;
  this->m_uOwnerTileId = CIntLinkList::OwnerTileId(a2);
  for ( i = 0; i < iSize; ++i )
    this->m_uLinkTileIds[i].m_uData = *(_WORD *)CIntLinkList::operator[](a2, i);
  return this;
}


// address=[0x15e7230]
// Decompiled from CLink *__thiscall CLinkList::Link(CLinkList *this, int a2)
class CLink const &  CLinkList::Link(int a2)const {
  
  return &this->m_uOwnerTileId[a2 + 1];
}


// address=[0x15e72e0]
// Decompiled from int __thiscall CLinkList::OwnerTileId(CLinkList *this)
int  CLinkList::OwnerTileId(void)const {
  
  return this->m_uOwnerTileId[0].m_uData;
}


// address=[0x15e7300]
// Decompiled from char __thiscall CLinkList::SearchForLinkTileId(CLinkList *this, int a2)
bool  CLinkList::SearchForLinkTileId(int a2)const {
  
  int i; // eax
  int v5; // [esp+4h] [ebp-4h]

  v5 = 0;
  for ( i = CLinkList::Size(this); v5 < i; i = CLinkList::Size(this) )
  {
    if ( this->m_uLinkTileIds[v5].m_uData == a2 )
      return 1;
    ++v5;
  }
  return 0;
}


// address=[0x15f49c0]
// Decompiled from int __thiscall CLinkList::Marker(CLinkList *this)
int  CLinkList::Marker(void)const {
  
  return this->m_uMarker;
}


#endif // Already implemented
