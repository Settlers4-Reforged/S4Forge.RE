#include "CPlayerInfo.h"

// Definitions for class CPlayerInfo

// address=[0x1373730]
// Decompiled from DWORD __thiscall CPlayerInfo::Race(CPlayerInfo *this)
int  CPlayerInfo::Race(void)const {
  
  return this->m_iRace;
}


// address=[0x1397b20]
// Decompiled from DWORD __thiscall CPlayerInfo::StartX(CPlayerInfo *this)
int  CPlayerInfo::StartX(void)const {
  
  return this->m_iStartX;
}


// address=[0x1397b40]
// Decompiled from DWORD __thiscall CPlayerInfo::StartY(CPlayerInfo *this)
int  CPlayerInfo::StartY(void)const {
  
  return this->m_iStartY;
}


// address=[0x13d1290]
// Decompiled from std::wstring *__thiscall CPlayerInfo::Name(CPlayerInfo *this)
std::wstring  CPlayerInfo::Name(void)const {
  return this->m_swName;
}


// address=[0x14972c0]
// Decompiled from void *__thiscall CPlayerInfo::Clear(CPlayerInfo *this)
void  CPlayerInfo::Clear(void) {
  
  this->m_iRace = 0;
  this->m_iStartX = 0;
  this->m_iStartY = 0;
  this->m_iIp = 0;
  this->m_iPeerId = 0;
  this->m_iColor = 0;
  this->m_swName = L"";
}


// address=[0x1497320]
// Decompiled from void __thiscall CPlayerInfo::Load(CPlayerInfo *this, struct IS4Chunk *a2)
void  CPlayerInfo::Load(class IS4Chunk & a2) {
  
  a2.Load(&this->m_iRace, 4);
  a2.Load(&this->m_iColor, 4);
}


// address=[0x1497360]
// Decompiled from void __thiscall CPlayerInfo::Save(CPlayerInfo *this, struct IS4Chunk *a2)
void  CPlayerInfo::Save(class IS4Chunk & a2) {
  
  a2.Save(&this->m_iRace, 4);
  a2.Save(&this->m_iColor, 4);
}


// address=[0x14980c0]
// Decompiled from CPlayerInfo *__thiscall CPlayerInfo::CPlayerInfo(CPlayerInfo *this)
 CPlayerInfo::CPlayerInfo(void) : IS4ChunkObject(), m_swName() {
  CPlayerInfo::Clear();
}


// address=[0x14982e0]
// Decompiled from void __thiscall CPlayerInfo::~CPlayerInfo(CPlayerInfo *this)
 CPlayerInfo::~CPlayerInfo(void) = default;
