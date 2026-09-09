#include "CPlayerData.h"

// Definitions for class CPlayerData

// address=[0x2fc5330]
// Decompiled from CPlayerData *__thiscall CPlayerData::CPlayerData(CPlayerData *this, int a2, char a3)
CPlayerData::CPlayerData(int a2, bool a3) {
  this->m_iRace = a2;
  this->m_bIsAI = a3;
  this->m_iBasicX = 0;
  this->m_iBasicY = 0;
  this->m_iRealX = 0;
  this->m_iRealY = 0;
  this->m_iNearestMountainX = 0;
  this->m_iNearestMountainY = 0;
}


// address=[0x2fc5390]
// Decompiled from void __thiscall CPlayerData::setStartPos_Basic(CPlayerData *this, int a2, int a3)
void CPlayerData::setStartPos_Basic(int a2, int a3) {
  this->m_iBasicX = a2;
  this->m_iBasicY = a3;
}


// address=[0x2fc53b0]
// Decompiled from void __thiscall CPlayerData::getStartPos_Basic(CPlayerData *this, int *a2, int *a3)
void CPlayerData::getStartPos_Basic(int &a2, int &a3) {
  a2 = this->m_iBasicX;
  a3 = this->m_iBasicY;
}


// address=[0x2fc53e0]
// Decompiled from void __thiscall CPlayerData::setStartPos_Real(CPlayerData *this, int a2, int a3)
void CPlayerData::setStartPos_Real(int a2, int a3) {
  this->m_iRealX = a2;
  this->m_iRealY = a3;
}


// address=[0x2fc5400]
// Decompiled from void __thiscall CPlayerData::getStartPos_Real(CPlayerData *this, int *a2, int *a3)
void CPlayerData::getStartPos_Real(int &a2, int &a3) {
  a2 = this->m_iRealX;
  a3 = this->m_iRealY;
}


// address=[0x2fc5430]
// Decompiled from void __thiscall CPlayerData::getNearestMountain(CPlayerData *this, int *a2, int *a3)
void CPlayerData::getNearestMountain(int &a2, int &a3) {
  a2 = this->m_iNearestMountainX;
  a3 = this->m_iNearestMountainY;
}


// address=[0x2fc5460]
// Decompiled from void __thiscall CPlayerData::setNearestMountain(CPlayerData *this, int a2, int a3)
void CPlayerData::setNearestMountain(int a2, int a3) {
  this->m_iNearestMountainX = a2;
  this->m_iNearestMountainY = a3;
}


// address=[0x2fc5480]
// Decompiled from int __thiscall CPlayerData::getRace(CPlayerData *this)
int CPlayerData::getRace(void) {
  return this->m_iRace;
}


// address=[0x2fc54a0]
// Decompiled from char __thiscall CPlayerData::isAI(CPlayerData *this)
bool CPlayerData::isAI(void) {
  return this->m_bIsAI;
}


