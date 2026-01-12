#include "CWarMapNode.h"

// Definitions for class CWarMapNode

// address=[0x13363e0]
// Decompiled from int __thiscall CWarMapNode::Next(CWarMapNode *this)

int  CWarMapNode::Next(void)const {
  
  return *((unsigned __int16 *)this + 1);
}


// address=[0x154c020]
// Decompiled from CWarMapNode *__thiscall CWarMapNode::CWarMapNode(CWarMapNode *this)

 CWarMapNode::CWarMapNode(void) {
  
  *(_DWORD *)this = 0xFFFF;
  return this;
}


// address=[0x154c0c0]
// Decompiled from bool __thiscall CWarMapNode::IsInWarMap(_anonymous_namespace_::_GetFileInfoByHandleEx *this)

bool  CWarMapNode::IsInWarMap(void)const {
  
  return *(_DWORD *)this != 0xFFFF;
}


// address=[0x15fb590]
// Decompiled from CWarMapNode *__thiscall CWarMapNode::~CWarMapNode(CWarMapNode *this)

 CWarMapNode::~CWarMapNode(void) {
  
  CWarMapNode *result; // eax

  result = this;
  if ( *(_DWORD *)this == 0xFFFF )
    return result;
  result = (CWarMapNode *)BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 173, "m_uNextPrev == NEXT_PREV_NOT_IN_LIST");
  if ( result == (CWarMapNode *)1 )
    __debugbreak();
  return result;
}


// address=[0x15fc730]
// Decompiled from int __thiscall CWarMapNode::Prev(CWarMapNode *this)

int  CWarMapNode::Prev(void)const {
  
  return *(unsigned __int16 *)this;
}


// address=[0x15fc750]
// Decompiled from void __thiscall CWarMapNode::SetNext(CPropertySet *this, unsigned __int16 a2)

void  CWarMapNode::SetNext(int) {
  
  *((_WORD *)this + 1) = a2;
}


// address=[0x15fc770]
// Decompiled from CWarMapNode *__thiscall CWarMapNode::SetPrev(CWarMapNode *this, __int16 a2)

void  CWarMapNode::SetPrev(int) {
  
  CWarMapNode *result; // eax

  result = this;
  *(_WORD *)this = a2;
  return result;
}


// address=[0x15fc790]
// Decompiled from int __thiscall CWarMapNode::SetPrevNext(CWarMapNode *this, int a2, int a3)

void  CWarMapNode::SetPrevNext(int,int) {
  
  int result; // eax

  result = a2 | (a3 << 16);
  *(_DWORD *)this = result;
  return result;
}


