#include "CPlayerInfo.h"

// Definitions for class CPlayerInfo

// address=[0x1373730]
// Decompiled from DWORD __thiscall CPlayerInfo::Race(CPlayerInfo *this)
int  CPlayerInfo::Race(void)const {
  
  return this->race;
}


// address=[0x1397b20]
// Decompiled from DWORD __thiscall CPlayerInfo::StartX(CPlayerInfo *this)
int  CPlayerInfo::StartX(void)const {
  
  return this->startX;
}


// address=[0x1397b40]
// Decompiled from DWORD __thiscall CPlayerInfo::StartY(CPlayerInfo *this)
int  CPlayerInfo::StartY(void)const {
  
  return this->startY;
}


// address=[0x13d1290]
// Decompiled from int __thiscall CPlayerInfo::Name(CPlayerInfo *this)
std::wstring  CPlayerInfo::Name(void)const {
  
  void *v2; // [esp+10h] [ebp+8h]

  std::wstring::wstring(v2, &this->name);
  return (int)v2;
}


// address=[0x14972c0]
// Decompiled from void *__thiscall CPlayerInfo::Clear(CPlayerInfo *this)
void  CPlayerInfo::Clear(void) {
  
  this->race = 0;
  this->startX = 0;
  this->startY = 0;
  this->unk_10 = 0;
  this->unk_14 = 0;
  this->unk_18 = 0;
  return std::wstring::operator=(&this->name, (wchar_t *)&word_3702DA4);
}


// address=[0x1497320]
// Decompiled from int __thiscall CPlayerInfo::Load(CPlayerInfo *this, struct IS4Chunk *a2)
void  CPlayerInfo::Load(class IS4Chunk & a2) {
  
  (**(void (__thiscall ***)(struct IS4Chunk *, DWORD *, int))a2)(a2, &this->race, 4);
  return (**(int (__thiscall ***)(struct IS4Chunk *, DWORD *, int))a2)(a2, &this->unk_18, 4);
}


// address=[0x1497360]
// Decompiled from int __thiscall CPlayerInfo::Save(CPlayerInfo *this, struct IS4Chunk *a2)
void  CPlayerInfo::Save(class IS4Chunk & a2) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, DWORD *, int))(*(_DWORD *)a2 + 16))(a2, &this->race, 4);
  return (*(int (__thiscall **)(struct IS4Chunk *, DWORD *, int))(*(_DWORD *)a2 + 16))(a2, &this->unk_18, 4);
}


// address=[0x14980c0]
// Decompiled from CPlayerInfo *__thiscall CPlayerInfo::CPlayerInfo(CPlayerInfo *this)
 CPlayerInfo::CPlayerInfo(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  this->__vftable = (CPlayerInfo_vtbl *)CPlayerInfo::_vftable_;
  std::wstring::wstring(&this->name);
  CPlayerInfo::Clear(this);
  return this;
}


// address=[0x14982e0]
// Decompiled from void __thiscall CPlayerInfo::~CPlayerInfo(CPlayerInfo *this)
 CPlayerInfo::~CPlayerInfo(void) {
  
  std::wstring::~wstring(&this->name);
}


