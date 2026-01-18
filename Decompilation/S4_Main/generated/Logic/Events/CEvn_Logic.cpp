#include "CEvn_Logic.h"

// Definitions for class CEvn_Logic

// address=[0x130e470]
// Decompiled from _DWORD *__thiscall CEvn_Logic::~CEvn_Logic(CEvn_Logic *this)
 CEvn_Logic::~CEvn_Logic(void) {
  
  return CEvn_Event::~CEvn_Event(this);
}


// address=[0x1334e60]
// Decompiled from CEvn_Logic *__thiscall CEvn_Logic::CEvn_Logic(  CEvn_Logic *this,  unsigned int a2,  unsigned int a3,  unsigned int a4,  char a5,  unsigned int a6,  unsigned __int16 a7)
 CEvn_Logic::CEvn_Logic(unsigned int,unsigned int,unsigned int,unsigned char,unsigned int,unsigned short) {
  
  CEvn_Event::CEvn_Event((CEvn_Event *)this, a2, a3, a4, 0);
  *(_DWORD *)this = CEvn_Logic::_vftable_;
  *((_BYTE *)this + 30) = a5;
  *((_DWORD *)this + 6) = a6;
  *((_WORD *)this + 14) = a7;
  return this;
}


// address=[0x1355030]
// Decompiled from CEvn_Logic *__thiscall CEvn_Logic::CEvn_Logic(CEvn_Logic *this)
 CEvn_Logic::CEvn_Logic(void) {
  
  CEvn_Event::CEvn_Event((CEvn_Event *)this, 0, 0, 0, 0);
  *(_DWORD *)this = CEvn_Logic::_vftable_;
  *((_BYTE *)this + 30) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_WORD *)this + 14) = 0;
  return this;
}


// address=[0x13570f0]
// Decompiled from int __thiscall CEvn_Logic::Load(CEvn_Logic *this, struct IS4Chunk *a2)
void  CEvn_Logic::Load(class IS4Chunk & a2) {
  
  int result; // eax

  (**(void (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 16, 4);
  (**(void (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 30, 1);
  (**(void (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 12, 4);
  (**(void (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 4, 4);
  result = (**(int (__thiscall ***)(struct IS4Chunk *, char *, int))a2)(a2, (char *)this + 8, 4);
  if ( !*((_WORD *)this + 14) )
    return result;
  *((_DWORD *)this + 6) = operator new[](*((unsigned __int16 *)this + 14));
  return (**(int (__thiscall ***)(struct IS4Chunk *, _DWORD, _DWORD))a2)(
           a2,
           *((_DWORD *)this + 6),
           *((unsigned __int16 *)this + 14));
}


// address=[0x13571b0]
// Decompiled from int __thiscall CEvn_Logic::Save(CEvn_Logic *this, struct IS4Chunk *a2)
void  CEvn_Logic::Save(class IS4Chunk & a2) {
  
  int result; // eax

  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 16, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 30, 1);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 12, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 4, 4);
  result = (*(int (__thiscall **)(struct IS4Chunk *, char *, int))(*(_DWORD *)a2 + 16))(a2, (char *)this + 8, 4);
  if ( !*((_WORD *)this + 14) )
    return result;
  if ( !*((_DWORD *)this + 6)
    && BBSupportDbgReportF(
         2,
         &unk_368335C,
         27,
         "m_iData != 0: m_iOwner: 0x%x, m_lParam: 0x%x, m_Message: 0x%x, m_wParam: 0x%x, m_iDataSize: 0x%x",
         *((unsigned __int8 *)this + 30),
         *((_DWORD *)this + 3),
         *((_DWORD *)this + 1),
         *((_DWORD *)this + 2),
         *((unsigned __int16 *)this + 14)) == 1 )
  {
    __debugbreak();
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, _DWORD, _DWORD))(*(_DWORD *)a2 + 16))(
           a2,
           *((_DWORD *)this + 6),
           *((unsigned __int16 *)this + 14));
}


// address=[0x145fff0]
// Decompiled from _DWORD *__thiscall CEvn_Logic::CEvn_Logic(_DWORD *this, struct boost::exception_detail::clone_base *a2)
 CEvn_Logic::CEvn_Logic(class CEvn_Logic const & a2) {
  
  CEvn_Event::CEvn_Event(a2);
  *this = CEvn_Logic::_vftable_;
  this[6] = *((_DWORD *)a2 + 6);
  *((_WORD *)this + 14) = *((_WORD *)a2 + 14);
  *((_BYTE *)this + 30) = *((_BYTE *)a2 + 30);
  *((_BYTE *)this + 31) = *((_BYTE *)a2 + 31);
  return this;
}


// address=[0x1486be0]
// Decompiled from int __thiscall CEvn_Logic::operator=(int this, int a2)
class CEvn_Logic &  CEvn_Logic::operator=(class CEvn_Logic const & a2) {
  
  CEvn_Event::operator=(this, (_BYTE *)a2);
  *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
  *(_WORD *)(this + 28) = *(_WORD *)(a2 + 28);
  *(_BYTE *)(this + 30) = *(_BYTE *)(a2 + 30);
  *(_BYTE *)(this + 31) = *(_BYTE *)(a2 + 31);
  return this;
}


