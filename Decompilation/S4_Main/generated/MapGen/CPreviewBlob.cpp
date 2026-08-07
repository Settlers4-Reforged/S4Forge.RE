#include "CPreviewBlob.h"

// Definitions for class CPreviewBlob

// address=[0x2fcca60]
// Decompiled from CPreviewBlob *__thiscall CPreviewBlob::CPreviewBlob(  CPreviewBlob *this,  int a2,  int a3,  int a4,  int a5,  int a6,  int a7,  int a8,  struct CCheckLayer *a9)
 CPreviewBlob::CPreviewBlob(int a2, int a3, int a4, int a5, int a6, int a7, int a8, class CCheckLayer * a9) {
  
  CBlob::CBlob(this, a2, a3, a4, a5, a6, a7, a8, a9);
  this->__vftable = (CBlob_vtbl *)&CPreviewBlob::_vftable_;
  this->m_iU7 = (this->m_iMaxY - this->m_iMinY + this->m_iMaxX - this->m_iMinX) / 2;
  this->m_fU0 = 12.0 / (float)this->m_iU7;
  this->m_iU8 = this->m_iMinX + (this->m_iMaxX - this->m_iMinX) / 2;
  this->m_iU9 = this->m_iMinY + (this->m_iMaxY - this->m_iMinY) / 2;
  return this;
}


// address=[0x2fccb20]
// Decompiled from int __thiscall CPreviewBlob::processFillPoint(CCheckLayer **this, int a2, int a3)
void  CPreviewBlob::processFillPoint(int a2, int a3) {
  
  int result; // eax

  CCheckLayer::setPoint(this[8], a2 - (_DWORD)this[9], a3 - (_DWORD)this[10], 1u);
  result = a2 + (_DWORD)this[3] * a3;
  *(_WORD *)(g_pPreviewImage + 2 * result) = *((_WORD *)this + 2);
  return result;
}


