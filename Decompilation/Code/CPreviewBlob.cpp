#include "CPreviewBlob.h"

// Definitions for class CPreviewBlob

// address=[0x2fcca60]
// Decompiled from CPreviewBlob *__thiscall CPreviewBlob::CPreviewBlob(
        CPreviewBlob *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        struct CCheckLayer *a9)

 CPreviewBlob::CPreviewBlob(int,int,int,int,int,int,int,class CCheckLayer *) {
  
  CBlob::CBlob(this, a2, a3, a4, a5, a6, a7, a8, a9);
  *(_DWORD *)this = &CPreviewBlob::_vftable_;
  *((_DWORD *)this + 11) = (*((_DWORD *)this + 7) - *((_DWORD *)this + 5) + *((_DWORD *)this + 6)
                                                                          - *((_DWORD *)this + 4))
                         / 2;
  *((float *)this + 14) = 12.0 / (float)*((int *)this + 11);
  *((_DWORD *)this + 12) = *((_DWORD *)this + 4) + (*((_DWORD *)this + 6) - *((_DWORD *)this + 4)) / 2;
  *((_DWORD *)this + 13) = *((_DWORD *)this + 5) + (*((_DWORD *)this + 7) - *((_DWORD *)this + 5)) / 2;
  return this;
}


// address=[0x2fccb20]
// Decompiled from int __thiscall CPreviewBlob::processFillPoint(CCheckLayer **this, int a2, int a3)

void  CPreviewBlob::processFillPoint(int,int) {
  
  int result; // eax

  CCheckLayer::setPoint(this[8], a2 - (_DWORD)this[9], a3 - (_DWORD)this[10], 1u);
  result = a2 + (_DWORD)this[3] * a3;
  *(_WORD *)(g_pPreviewImage + 2 * result) = *((_WORD *)this + 2);
  return result;
}


