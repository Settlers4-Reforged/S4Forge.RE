#include "SBUILDINFODATA.h"

// Definitions for class SBUILDINFODATA

// address=[0x1345840]
// Decompiled from _DWORD *__thiscall SBUILDINFODATA::SBUILDINFODATA(_DWORD *this, _DWORD *a2)

 SBUILDINFODATA::SBUILDINFODATA(struct SBUILDINFODATA &&) {
  
  *this = *a2;
  this[1] = a2[1];
  this[2] = a2[2];
  this[3] = a2[3];
  qmemcpy(this + 4, a2 + 4, 0x2Cu);
  std::vector<SPOSS_BUILD_PLACE>::vector<SPOSS_BUILD_PLACE>(a2 + 15);
  return this;
}


// address=[0x13458f0]
// Decompiled from SBUILDINFODATA *__thiscall SBUILDINFODATA::SBUILDINFODATA(SBUILDINFODATA *this, const struct SBUILDINFODATA *a2)

 SBUILDINFODATA::SBUILDINFODATA(struct SBUILDINFODATA const &) {
  
  *(_DWORD *)this = *(_DWORD *)a2;
  *((_DWORD *)this + 1) = *((_DWORD *)a2 + 1);
  *((_DWORD *)this + 2) = *((_DWORD *)a2 + 2);
  *((_DWORD *)this + 3) = *((_DWORD *)a2 + 3);
  qmemcpy((char *)this + 16, (char *)a2 + 16, 0x2Cu);
  std::vector<SPOSS_BUILD_PLACE>::vector<SPOSS_BUILD_PLACE>((char *)a2 + 60);
  return this;
}


// address=[0x13459a0]
// Decompiled from SBUILDINFODATA *__thiscall SBUILDINFODATA::SBUILDINFODATA(SBUILDINFODATA *this)

 SBUILDINFODATA::SBUILDINFODATA(void) {
  
  std::vector<SPOSS_BUILD_PLACE>::vector<SPOSS_BUILD_PLACE>((char *)this + 60);
  return this;
}


// address=[0x1345e70]
// Decompiled from void __thiscall SBUILDINFODATA::~SBUILDINFODATA(SBUILDINFODATA *this)

 SBUILDINFODATA::~SBUILDINFODATA(void) {
  
  std::vector<SPOSS_BUILD_PLACE>::~vector<SPOSS_BUILD_PLACE>((char *)this + 60);
}


// address=[0x13461d0]
// Decompiled from _DWORD *__thiscall SBUILDINFODATA::operator=(_DWORD *this, _DWORD *a2)

struct SBUILDINFODATA &  SBUILDINFODATA::operator=(struct SBUILDINFODATA const &) {
  
  unsigned int j; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-8h]

  *this = *a2;
  this[1] = a2[1];
  this[2] = a2[2];
  this[3] = a2[3];
  for ( i = 0; i < 7; ++i )
    this[i + 4] = a2[i + 4];
  for ( j = 0; j < 8; ++j )
    *((_WORD *)this + j + 22) = *((_WORD *)a2 + j + 22);
  std::vector<SPOSS_BUILD_PLACE>::operator=(a2 + 15);
  return this;
}


