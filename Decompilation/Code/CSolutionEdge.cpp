#include "CSolutionEdge.h"

// Definitions for class CSolutionEdge

// address=[0x2f3e7e0]
// Decompiled from CSolutionEdge *__thiscall CSolutionEdge::CSolutionEdge(CSolutionEdge *this, int a2, int a3)

 CSolutionEdge::CSolutionEdge(int,int) {
  
  CDynListEntry::CDynListEntry(this);
  *(_DWORD *)this = &CSolutionEdge::_vftable_;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = a3;
  return this;
}


// address=[0x2f3e820]
// Decompiled from void __thiscall CSolutionEdge::~CSolutionEdge(CSolutionEdge *this)

 CSolutionEdge::~CSolutionEdge(void) {
  
  *(_DWORD *)this = &CSolutionEdge::_vftable_;
  CDynListEntry::~CDynListEntry(this);
}


// address=[0x2f3e840]
// Decompiled from // public: void __thiscall CSolutionEdge::show(void)
int __thiscall CSolutionEdge::show(_DWORD *this)

void  CSolutionEdge::show(void) {
  
  int v1; // eax
  int v2; // eax
  int v4; // [esp-10h] [ebp-14h]
  int v5; // [esp-8h] [ebp-Ch]

  v5 = this[4];
  v4 = this[3];
  std::operator<<<std::char_traits<char>>((int)&std::cout, "ActionId = ");
  v1 = std::ostream::operator<<(v4);
  std::operator<<<std::char_traits<char>>(v1, ",PrNr = ");
  v2 = std::ostream::operator<<(v5);
  return std::operator<<<std::char_traits<char>>(v2, "\n");
}


