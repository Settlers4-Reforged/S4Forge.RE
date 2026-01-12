#include "CEvn_Event.h"

// Definitions for class CEvn_Event

// address=[0x130e450]
// Decompiled from _DWORD *__thiscall sub_170E450(_DWORD *this)

 CEvn_Event::~CEvn_Event(void) {
  
  _DWORD *result; // eax

  result = this;
  *this = &CEvn_Event::_vftable_;
  return result;
}


// address=[0x1334dc0]
// Decompiled from CEvn_Event *__thiscall CEvn_Event::CEvn_Event(
        CEvn_Event *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned __int8 a5)

 CEvn_Event::CEvn_Event(unsigned int,unsigned int,unsigned int,unsigned char) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  *(_DWORD *)this = CEvn_Event::_vftable_;
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)this + 2) = a3;
  *((_DWORD *)this + 3) = a4;
  *((_BYTE *)this + 20) = a5;
  if ( g_pEvnEngine && g_pEvnEngine->tick )
    *((_DWORD *)this + 4) = *(_DWORD *)g_pEvnEngine->tick;
  else
    *((_DWORD *)this + 4) = 0;
  return this;
}


// address=[0x1352be0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall CEvn_Event::Load(CEvn_Event *this, struct IS4Chunk *a2)

void  CEvn_Event::Load(class IS4Chunk &) {
  
  ;
}


// address=[0x1352bf0]
// Decompiled from // Microsoft VisualC 14/net runtime
// MFC 3.1-14.0 32bit
void __thiscall CEvn_Event::Save(CEvn_Event *this, struct IS4Chunk *a2)

void  CEvn_Event::Save(class IS4Chunk &) {
  
  ;
}


// address=[0x145ff30]
// Decompiled from int __thiscall CEvn_Event::CEvn_Event(int this, struct boost::exception_detail::clone_base *a2)

 CEvn_Event::CEvn_Event(class CEvn_Event const &) {
  
  _DWORD *v3; // [esp+0h] [ebp-8h]

  if ( a2 )
    v3 = (_DWORD *)((char *)a2 + 4);
  else
    v3 = 0;
  *(_DWORD *)(this + 4) = *v3;
  *(_DWORD *)(this + 8) = v3[1];
  *(_DWORD *)(this + 12) = v3[2];
  *(_DWORD *)(this + 16) = v3[3];
  IS4ChunkObject::IS4ChunkObject((boost::exception_detail::clone_base *)this, a2);
  *(_DWORD *)this = CEvn_Event::_vftable_;
  *(_BYTE *)(this + 20) = *((_BYTE *)a2 + 20);
  *(_BYTE *)(this + 21) = *((_BYTE *)a2 + 21);
  *(_BYTE *)(this + 22) = *((_BYTE *)a2 + 22);
  *(_BYTE *)(this + 23) = *((_BYTE *)a2 + 23);
  return this;
}


// address=[0x1486b30]
// Decompiled from int __thiscall CEvn_Event::operator=(int this, _BYTE *a2)

class CEvn_Event &  CEvn_Event::operator=(class CEvn_Event const &) {
  
  _DWORD *v3; // [esp+0h] [ebp-8h]

  if ( a2 )
    v3 = a2 + 4;
  else
    v3 = 0;
  *(_DWORD *)(this + 4) = *v3;
  *(_DWORD *)(this + 8) = v3[1];
  *(_DWORD *)(this + 12) = v3[2];
  *(_DWORD *)(this + 16) = v3[3];
  IS4ChunkObject::operator=(a2);
  *(_BYTE *)(this + 20) = a2[20];
  *(_BYTE *)(this + 21) = a2[21];
  *(_BYTE *)(this + 22) = a2[22];
  *(_BYTE *)(this + 23) = a2[23];
  return this;
}


