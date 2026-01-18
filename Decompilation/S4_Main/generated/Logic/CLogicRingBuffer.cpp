#include "CLogicRingBuffer.h"

// Definitions for class CLogicRingBuffer

// address=[0x1486a00]
// Decompiled from CLogicRingBuffer *__thiscall CLogicRingBuffer::CLogicRingBuffer(CLogicRingBuffer *this, int a2)
 CLogicRingBuffer::CLogicRingBuffer(int a2) {
  
  CRingBuffer<CEvn_Logic>::CRingBuffer<CEvn_Logic>(a2);
  IS4ChunkObject::IS4ChunkObject((CLogicRingBuffer *)((char *)this + 24));
  *(_DWORD *)this = &CLogicRingBuffer::_vftable_;
  *((_DWORD *)this + 6) = &CLogicRingBuffer::`vftable';
  return this;
}


// address=[0x1486b10]
// Decompiled from int __thiscall CLogicRingBuffer::~CLogicRingBuffer(CLogicRingBuffer *this)
 CLogicRingBuffer::~CLogicRingBuffer(void) {
  
  return CRingBuffer<CEvn_Logic>::~CRingBuffer<CEvn_Logic>(this, this);
}


// address=[0x14870b0]
// Decompiled from void __thiscall CLogicRingBuffer::Load(CLogicRingBuffer *this, struct IS4Chunk *a2)
void  CLogicRingBuffer::Load(class IS4Chunk &) {
  
  unsigned int v2; // [esp+4h] [ebp-40h]
  unsigned int i; // [esp+8h] [ebp-3Ch]
  _BYTE v5[32]; // [esp+14h] [ebp-30h] BYREF
  int v6; // [esp+40h] [ebp-4h]

  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 6) + 12))((char *)this - 24)
    && BBSupportDbgReport(
         2,
         "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Main\\LogicRingBuffer.h",
         33,
         (const char *)&dword_36C2338[1]) == 1 )
  {
    __debugbreak();
  }
  CEvn_Logic::CEvn_Logic(v5);
  v6 = 0;
  v2 = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
  for ( i = 0; i < v2; ++i )
  {
    if ( !(*(unsigned __int8 (__thiscall **)(char *, _BYTE *))(*((_DWORD *)this - 6) + 4))((char *)this - 24, v5) )
    {
      BBSupportTracePrint(3, "FATAL ERROR: Can't write to logic ringbuffer during load!");
      BBSupportTracePrintF(3, "->          Event#: %d", i);
      if ( BBSupportDbgReport(
             1,
             "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\S4_Main\\Main\\LogicRingBuffer.h",
             48,
             "Internal error (L0)- aborting!\nInterner Fehler (L0) aufgetreten! Programm wird abgebrochen!") == 1 )
        __debugbreak();
    }
  }
  v6 = -1;
  CEvn_Logic::~CEvn_Logic(v5);
}


// address=[0x14872e0]
// Decompiled from int __thiscall CLogicRingBuffer::Save(CLogicRingBuffer *this, struct IS4Chunk *a2)
void  CLogicRingBuffer::Save(class IS4Chunk & a2) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-Ch]
  int v4; // [esp+4h] [ebp-8h]

  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 6) + 16))((char *)this - 24);
  v4 = 0;
  while ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 6) + 20))((char *)this - 24) )
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 6) + 24))((char *)this - 24);
    ++v4;
  }
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 20))(a2, v4);
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 6) + 16))((char *)this - 24);
  while ( 1 )
  {
    result = (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 6) + 20))((char *)this - 24);
    if ( !(_BYTE)result )
      break;
    v3 = (*(int (__thiscall **)(char *))(*((_DWORD *)this - 6) + 24))((char *)this - 24);
    (*(void (__thiscall **)(int, struct IS4Chunk *))(*(_DWORD *)v3 + 4))(v3, a2);
  }
  return result;
}


