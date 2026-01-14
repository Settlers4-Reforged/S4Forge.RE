#include "all_headers.h"

// Definitions for class CSavedPlayer

// address=[0x13eb720]
// Decompiled from int __thiscall CSavedPlayer::Load(CSavedPlayer *this, struct IS4Chunk *a2)
void  CSavedPlayer::Load(class IS4Chunk &) {
  
  int result; // eax
  int v3; // [esp+0h] [ebp-8h] BYREF
  CSavedPlayer *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  v3 = 0;
  result = (**(int (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v3, 4);
  if ( v3 != 1 )
  {
    result = BBSupportDbgReport(2, "LoadSave\\GeneralChunk.cpp", 38, "VERSION==1");
    if ( result == 1 )
      __debugbreak();
  }
  if ( v3 != 1 )
    return result;
  (**(void (__thiscall ***)(struct IS4Chunk *, CSavedPlayer *, int))a2)(a2, v4, 4);
  (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v4 + 4, 64);
  (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v4 + 68, 4);
  (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v4 + 72, 4);
  (**(void (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v4 + 76, 4);
  return (**(int (__thiscall ***)(struct IS4Chunk *, int, int))a2)(a2, (int)v4 + 80, 1);
}


// address=[0x13eb7f0]
// Decompiled from int __thiscall CSavedPlayer::Save(CSavedPlayer *this, struct IS4Chunk *a2)
void  CSavedPlayer::Save(class IS4Chunk &) {
  
  int v3; // [esp+0h] [ebp-8h] BYREF
  CSavedPlayer *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  v3 = 1;
  (*(void (__thiscall **)(struct IS4Chunk *, int *, int))(*(_DWORD *)a2 + 16))(a2, &v3, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, CSavedPlayer *, int))(*(_DWORD *)a2 + 16))(a2, v4, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, (int)v4 + 4, 64);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, (int)v4 + 68, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, (int)v4 + 72, 4);
  (*(void (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, (int)v4 + 76, 4);
  return (*(int (__thiscall **)(struct IS4Chunk *, int, int))(*(_DWORD *)a2 + 16))(a2, (int)v4 + 80, 1);
}


