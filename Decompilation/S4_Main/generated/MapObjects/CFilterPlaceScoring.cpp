#include "all_headers.h"

// Definitions for class CFilterPlaceScoring

// address=[0x2f39700]
// Decompiled from IFilterEntry *__thiscall CFilterPlaceScoring::CFilterPlaceScoring(IFilterEntry *this)
 CFilterPlaceScoring::CFilterPlaceScoring(void) {
  
  IFilterEntry::IFilterEntry(this);
  *(_DWORD *)this = &CFilterPlaceScoring::_vftable_;
  return this;
}


// address=[0x2f39720]
// Decompiled from CFilterPlaceScoring *__thiscall CFilterPlaceScoring::CFilterPlaceScoring(  CFilterPlaceScoring *this,  struct CSchedule *a2,  struct SBUILDINFODATA *a3,  int a4,  int a5,  int a6)
 CFilterPlaceScoring::CFilterPlaceScoring(class CSchedule *,struct SBUILDINFODATA *,int,int,int) {
  
  IFilterEntry::IFilterEntry(this);
  *(_DWORD *)this = &CFilterPlaceScoring::_vftable_;
  *((_DWORD *)this + 3) = a2;
  *((_DWORD *)this + 4) = *((_DWORD *)a3 + 2);
  *((_DWORD *)this + 5) = *(_DWORD *)a3;
  *((_DWORD *)this + 6) = *((_DWORD *)a3 + 1);
  if ( *((_DWORD *)this + 4) == 46 )
    *((_DWORD *)this + 11) = a5;
  *((_DWORD *)this + 10) = *(_DWORD *)std::vector<SPOSS_BUILD_PLACE>::operator[](a4);
  *((_BYTE *)this + 48) = *(_BYTE *)(std::vector<SPOSS_BUILD_PLACE>::operator[](a4) + 4);
  *((_DWORD *)this + 13) = a5;
  *((double *)this + 4) = (double)a6;
  return this;
}


// address=[0x2f39800]
// Decompiled from void __thiscall CFilterPlaceScoring::~CFilterPlaceScoring(CFilterPlaceScoring *this)
 CFilterPlaceScoring::~CFilterPlaceScoring(void) {
  
  *(_DWORD *)this = &CFilterPlaceScoring::_vftable_;
  IFilterEntry::~IFilterEntry(this);
}


// address=[0x2f39820]
// Decompiled from double __thiscall CFilterPlaceScoring::GetFilterValue(CFilterPlaceScoring *this)
float  CFilterPlaceScoring::GetFilterValue(void) {
  
  return (float)*((double *)this + 4);
}


