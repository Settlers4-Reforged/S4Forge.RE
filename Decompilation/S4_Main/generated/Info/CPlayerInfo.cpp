#if FALSE
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
  
  std::wstring *v2; // [esp+10h] [ebp+8h]

  std::wstring::wstring(v2, &this->m_swName);
  return v2;
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
  return std::wstring::operator=(&this->m_swName, (wchar_t *)&word_3702DA4);
}


// address=[0x1497320]
// Decompiled from void __thiscall CPlayerInfo::Load(CPlayerInfo *this, struct IS4Chunk *a2)
void  CPlayerInfo::Load(class IS4Chunk & a2) {
  
  a2->Load(&this->m_iRace, 4);
  a2->Load(&this->m_iColor, 4);
}


// address=[0x1497360]
// Decompiled from void __thiscall CPlayerInfo::Save(CPlayerInfo *this, struct IS4Chunk *a2)
void  CPlayerInfo::Save(class IS4Chunk & a2) {
  
  a2->Save(&this->m_iRace, 4);
  a2->Save(&this->m_iColor, 4);
}


// address=[0x14980c0]
// Decompiled from CPlayerInfo *__thiscall CPlayerInfo::CPlayerInfo(CPlayerInfo *this)
 CPlayerInfo::CPlayerInfo(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  this->__vftable = (CPlayerInfo_vtbl *)CPlayerInfo::_vftable_;
  std::wstring::wstring(&this->m_swName);
  CPlayerInfo::Clear(this);
  return this;
}


// address=[0x14982e0]
// Decompiled from void __thiscall CPlayerInfo::~CPlayerInfo(CPlayerInfo *this)
 CPlayerInfo::~CPlayerInfo(void) {
  
  std::wstring::~wstring(&this->m_swName);
}


#endif // Already implemented
