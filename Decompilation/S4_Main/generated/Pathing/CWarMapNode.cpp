#if FALSE
#include "CWarMapNode.h"

// Definitions for class CWarMapNode

// address=[0x13363e0]
// Decompiled from int __thiscall CWarMapNode::Next(CWarMapNode *this)
int  CWarMapNode::Next(void)const {
  
  return this->?;
}


// address=[0x154c020]
// Decompiled from CWarMapNode *__thiscall CWarMapNode::CWarMapNode(CWarMapNode *this)
 CWarMapNode::CWarMapNode(void) {
  
  *this = (CWarMapNode)0xFFFF;
  return this;
}


// address=[0x154c0c0]
// Decompiled from bool __thiscall CWarMapNode::IsInWarMap(CWarMapNode *this)
bool  CWarMapNode::IsInWarMap(void)const {
  
  return this->m_uNextPrev != 0xFFFF;
}


// address=[0x15fb590]
// Decompiled from void __thiscall CWarMapNode::~CWarMapNode(CWarMapNode *this)
 CWarMapNode::~CWarMapNode(void) {
  
  if ( this->m_uNextPrev != 0xFFFF && BBSupportDbgReport(2, "Pathing\\WarMap.cpp", 173, "m_uNextPrev == NEXT_PREV_NOT_IN_LIST") == 1 )
  {
    __debugbreak();
  }
}


// address=[0x15fc730]
// Decompiled from int __thiscall CWarMapNode::Prev(CWarMapNode *this)
int  CWarMapNode::Prev(void)const {
  
  return LOWORD(this->m_uNextPrev);
}


// address=[0x15fc750]
// Decompiled from void __thiscall CWarMapNode::SetNext(CWarMapNode *this, WORD a2)
void  CWarMapNode::SetNext(int a2) {
  
  HIWORD(this->m_uNextPrev) = a2;
}


// address=[0x15fc770]
// Decompiled from void __thiscall CWarMapNode::SetPrev(CWarMapNode *this, __int16 a2)
void  CWarMapNode::SetPrev(int a2) {
  
  LOWORD(this->m_uNextPrev) = a2;
}


// address=[0x15fc790]
// Decompiled from void __thiscall CWarMapNode::SetPrevNext(CWarMapNode *this, int a2, int a3)
void  CWarMapNode::SetPrevNext(int a2, int a3) {
  
  this->m_uNextPrev = a2 | (a3 << 16);
}


#endif // Already implemented
