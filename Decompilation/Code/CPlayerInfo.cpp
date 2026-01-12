#include "CPlayerInfo.h"

// Definitions for class CPlayerInfo

// address=[0x1373730]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CPlayerInfo::Race(CPlayerInfo *this)

int  CPlayerInfo::Race(void)const {
  
  return *((_DWORD *)this + 1);
}


// address=[0x1397b20]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
int __thiscall CPlayerInfo::StartX(CPlayerInfo *this)

int  CPlayerInfo::StartX(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x1397b40]
// Decompiled from int __thiscall CPlayerInfo::StartY(pairNode *this)

int  CPlayerInfo::StartY(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x13d1290]
// Decompiled from int __thiscall CPlayerInfo::Name(void *this, int a2)

std::wstring  CPlayerInfo::Name(void)const {
  
  std::wstring::wstring((int)this + 28);
  return a2;
}


// address=[0x14972c0]
// Decompiled from void *__thiscall CPlayerInfo::Clear(CPlayerInfo *this)

void  CPlayerInfo::Clear(void) {
  
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  return std::wstring::operator=((char *)this + 28, (wchar_t *)&word_3702DA4);
}


// address=[0x1497320]
// Decompiled from int __thiscall CPlayerInfo::Load(CPlayerInfo *this, struct IS4Chunk *a2)

void  CPlayerInfo::Load(class IS4Chunk &) {
  
  (**(void (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 4, 4);
  return (**(int (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 24, 4);
}


// address=[0x1497360]
// Decompiled from int __thiscall CPlayerInfo::Save(CPlayerInfo *this, struct IS4Chunk *a2)

void  CPlayerInfo::Save(class IS4Chunk &) {
  
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 4, 4);
  return (*(int (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 24, 4);
}


// address=[0x14980c0]
// Decompiled from CPlayerInfo *__thiscall CPlayerInfo::CPlayerInfo(CPlayerInfo *this)

 CPlayerInfo::CPlayerInfo(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  *(_DWORD *)this = CPlayerInfo::_vftable_;
  std::wstring::wstring((char *)this + 28);
  CPlayerInfo::Clear(this);
  return this;
}


// address=[0x14982e0]
// Decompiled from void __thiscall CPlayerInfo::~CPlayerInfo(CPlayerInfo *this)

 CPlayerInfo::~CPlayerInfo(void) {
  
  std::wstring::~wstring((char *)this + 28);
}


