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
// Decompiled from CSettlerMgr::SSettlerInfos *__thiscall CSettlerMgr::SSettlerInfos::operator=(  CSettlerMgr::SSettlerInfos *this,  CSettlerMgr::SSettlerInfos *a2)
struct CSettlerMgr::SSettlerInfos &  CSettlerMgr::SSettlerInfos::operator=(struct CSettlerMgr::SSettlerInfos const &) {
  
  this->m_uRole = a2->m_uRole;
  this->m_bSpeed = a2->m_bSpeed;
  this->m_bHealth = a2->m_bHealth;
  this->m_bDamage = a2->m_bDamage;
  this->m_bArmor = a2->m_bArmor;
  this->m_uTool = a2->m_uTool;
  this->m_uOther = a2->m_uOther;
  this->m_bMisc = a2->m_bMisc;
  std::vector<CSettlerMgr::SSearchInfos>::operator=(this->m_vSearches, a2->m_vSearches);
  std::vector<unsigned short>::operator=(this->g_vAnimLists, a2->g_vAnimLists);
  this->m_bDamage2 = a2->m_bDamage2;
  this->m_bDamage3 = a2->m_bDamage3;
  return this;
}


