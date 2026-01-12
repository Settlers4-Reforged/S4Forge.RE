#include "SSettlerInfos.h"

// Definitions for class SSettlerInfos

// address=[0x1587b80]
// Decompiled from int __thiscall CSettlerMgr::SSettlerInfos::SSettlerInfos(CSettlerMgr::SSettlerInfos *this)
 CSettlerMgr::SSettlerInfos::SSettlerInfos(void) {
  
  int v2; // [esp+0h] [ebp-4h]

  std::vector<CSettlerMgr::SSearchInfos>::vector<CSettlerMgr::SSearchInfos>(this);
  std::vector<unsigned short>::vector<unsigned short>((void *)(v2 + 24));
  return v2;
}


// address=[0x1587cb0]
// Decompiled from int __thiscall CSettlerMgr::SSettlerInfos::~SSettlerInfos(CSettlerMgr::SSettlerInfos *this)
 CSettlerMgr::SSettlerInfos::~SSettlerInfos(void) {
  
  std::vector<unsigned short>::~vector<unsigned short>((char *)this + 24);
  return std::vector<CSettlerMgr::SSearchInfos>::~vector<CSettlerMgr::SSearchInfos>(this);
}


// address=[0x1588360]
// Decompiled from _BYTE *__thiscall CSettlerMgr::SSettlerInfos::operator=(_BYTE *this, _BYTE *a2)
struct CSettlerMgr::SSettlerInfos &  CSettlerMgr::SSettlerInfos::operator=(struct CSettlerMgr::SSettlerInfos const &) {
  
  *this = *a2;
  this[1] = a2[1];
  this[2] = a2[2];
  this[3] = a2[3];
  this[4] = a2[4];
  this[5] = a2[5];
  this[6] = a2[6];
  this[7] = a2[7];
  std::vector<CSettlerMgr::SSearchInfos>::operator=(a2 + 8);
  std::vector<unsigned short>::operator=(a2 + 24);
  this[40] = a2[40];
  this[41] = a2[41];
  return this;
}


