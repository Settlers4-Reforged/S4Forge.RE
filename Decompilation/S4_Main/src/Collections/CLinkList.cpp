#include "CLinkList.h"

#include "Collections/CIntLinkList.h"
#include "Debug/CTrace.h"

// Definitions for class CLinkList

// address=[0x1346460]
// Decompiled from CLink *__thiscall CLinkList::operator[](struct CLinkList *this, int a2)
unsigned short const &CLinkList::operator[](int a2) const {
  return this->m_uLinkTileIds[a2].m_uData;
}


// address=[0x13469a0]
// Decompiled from int __thiscall CLinkList::Size(struct CLinkList *this)
int CLinkList::Size(void) const {
  return this->m_uSize;
}


// address=[0x15e2ec0]
// Decompiled from int __thiscall CLinkList::DbgPrint(CLinkList *this)
void CLinkList::DbgPrint(void) const {
  int  m_uSize; // [esp+0h] [ebp-1010h]
  int  i; // [esp+4h] [ebp-100Ch]
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
    this->m_uOwnerTileId);
  if(!this->m_uSize)
    return CTrace::Print(Source);
  strcpy(Destination, Source);
  snprintf(Source, 2048u, "%s; %i", Destination, LOWORD(this->m_uLinkTileIds));
  m_uSize = this->m_uSize;
  for(i = 1; i < m_uSize; ++i) {
    strcpy(Destination, Source);
    snprintf(Source, 0x800u, "%s,%i", Destination, *((unsigned __int16 *) &this->m_uLinkTileIds + i));
  }
  return CTrace::Print(Source);
}


// address=[0x15e6e60]
// Decompiled from struct CLinkList *__thiscall CLinkList::operator=(struct CLinkList *this, struct CLinkList *a2)
class CLinkList &CLinkList::operator=(class CLinkList const &a2) {
  // [esp+4h] [ebp-Ch]
  // [esp+Ch] [ebp-4h]

  // v3 = (a2.m_uSize + 3) / 2;
  for(int i = 0; i < a2.m_uSize; ++i)
    this->m_uLinkTileIds[i] = a2.m_uLinkTileIds[i];
  return *this;
}


// address=[0x15e6ed0]
// Decompiled from _BYTE *__thiscall CLinkList::operator=(_BYTE *this, CIntLinkList *a2)
class CLinkList &CLinkList::operator=(CIntLinkList const &a2) {
  // [esp+0h] [ebp-Ch]
  // [esp+8h] [ebp-4h]

  int iSize = a2.Size();
  this->m_uSize = iSize;
  this->m_uMarker = -3;
  this->m_uOwnerTileId = a2.OwnerTileId();
  for(int i = 0; i < iSize; ++i)
    this->m_uLinkTileIds[i].m_uData = a2[i];
  return *this;
}


// address=[0x15e7230]
// Decompiled from CLink *__thiscall CLinkList::Link(CLinkList *this, int a2)
class CLink const &CLinkList::Link(int a2) const {
  return this->m_uLinkTileIds[a2];
}


// address=[0x15e72e0]
// Decompiled from int __thiscall CLinkList::OwnerTileId(CLinkList *this)
int CLinkList::OwnerTileId(void) const {
  return this->m_uOwnerTileId;
}


// address=[0x15e7300]
// Decompiled from char __thiscall CLinkList::SearchForLinkTileId(CLinkList *this, int a2)
bool CLinkList::SearchForLinkTileId(int a2) const {
  int i; // eax
  int v5; // [esp+4h] [ebp-4h]

  v5 = 0;
  for(i = this->Size(); v5 < i; i = this->Size()) {
    if(this->m_uLinkTileIds[v5].m_uData == a2)
      return 1;
    ++v5;
  }
  return 0;
}


// address=[0x15f49c0]
// Decompiled from int __thiscall CLinkList::Marker(CLinkList *this)
int CLinkList::Marker(void) const {
  return this->m_uMarker;
}


