#if FALSE
#include "CEvn_Event.h"

// Definitions for class CEvn_Event

// address=[0x130e450]
// Decompiled from void __thiscall CEvn_Event::~CEvn_Event(CEvn_Event *this)
 CEvn_Event::~CEvn_Event(void) {
  
  this->__vftable = (CEvn_Event_vtbl *)CEvn_Event::_vftable_;
}


// address=[0x1334dc0]
// Decompiled from CEvn_Event *__thiscall CEvn_Event::CEvn_Event(CEvn_Event *this, int a2, int a3, int a4, BYTE a5)
 CEvn_Event::CEvn_Event(unsigned int a2, unsigned int a3, unsigned int a4, unsigned char a5) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  this->__vftable = (CEvn_Event_vtbl *)CEvn_Event::_vftable_;
  this->m_iEventId = a2;
  this->m_wParam = a3;
  this->m_lParam = a4;
  this->m_iFlags = a5;
  if ( g_pEvnEngine && g_pEvnEngine->m_pTick )
    this->m_iTick = *g_pEvnEngine->m_pTick;
  else
    this->m_iTick = 0;
  return this;
}


// address=[0x1352be0]
// Decompiled from void __thiscall CEvn_Event::Load(CEvn_Event *this, struct IS4Chunk *a2)
void  CEvn_Event::Load(class IS4Chunk & a2) {
  
  ;
}


// address=[0x1352bf0]
// Decompiled from void __thiscall CEvn_Event::Save(CEvn_Event *this, struct IS4Chunk *a2)
void  CEvn_Event::Save(class IS4Chunk & a2) {
  
  ;
}


// address=[0x145ff30]
// Decompiled from CEvn_Event *__thiscall CEvn_Event::CEvn_Event(CEvn_Event *this, CEvn_Event *a2)
 CEvn_Event::CEvn_Event(class CEvn_Event const & a2) {
  
  SEventStruct *v3; // [esp+0h] [ebp-8h]

  if ( a2 )
    v3 = &a2->SEventStruct;
  else
    v3 = 0;
  this->m_iEventId = v3->m_iEventId;
  this->m_wParam = v3->m_wParam;
  this->m_lParam = v3->m_lParam;
  this->m_iTick = v3->m_iTick;
  IS4ChunkObject::IS4ChunkObject(this, a2);
  this->__vftable = (CEvn_Event_vtbl *)CEvn_Event::_vftable_;
  this->m_iFlags = a2->m_iFlags;
  this->unk_15 = a2->unk_15;
  this->unk_16 = a2->unk_16;
  this->unk_17 = a2->unk_17;
  return this;
}


// address=[0x1486b30]
// Decompiled from CEvn_Event *__thiscall CEvn_Event::operator=(CEvn_Event *this, CEvn_Event *a2)
class CEvn_Event &  CEvn_Event::operator=(class CEvn_Event const & a2) {
  
  SEventStruct *v3; // [esp+0h] [ebp-8h]

  if ( a2 )
    v3 = &a2->SEventStruct;
  else
    v3 = 0;
  this->m_iEventId = v3->m_iEventId;
  this->m_wParam = v3->m_wParam;
  this->m_lParam = v3->m_lParam;
  this->m_iTick = v3->m_iTick;
  IS4ChunkObject::operator=(this, a2);
  this->m_iFlags = a2->m_iFlags;
  this->unk_15 = a2->unk_15;
  this->unk_16 = a2->unk_16;
  this->unk_17 = a2->unk_17;
  return this;
}


#endif // Already implemented
