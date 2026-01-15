#include "CUserLogoChunk.h"

// Definitions for class CUserLogoChunk

// address=[0x140a250]
// Decompiled from int __thiscall CUserLogoChunk::Load(CUserLogoChunk *this, struct IS4Chunk *a2)
void  CUserLogoChunk::Load(class IS4Chunk &) {
  
  int pExceptionObject; // [esp+10h] [ebp-290h] BYREF
  int v4; // [esp+14h] [ebp-28Ch] BYREF
  void *Buffer; // [esp+18h] [ebp-288h]
  size_t ElementCount; // [esp+1Ch] [ebp-284h]
  int v7; // [esp+20h] [ebp-280h]
  _DWORD v8[26]; // [esp+24h] [ebp-27Ch] BYREF
  int v9; // [esp+8Ch] [ebp-214h] BYREF
  wchar_t FileName[256]; // [esp+90h] [ebp-210h] BYREF
  int v11; // [esp+29Ch] [ebp-4h]

  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 778316700);
  v4 = 0;
  (**(void (__thiscall ***)(struct IS4Chunk *, int *, int))a2)(a2, &v4, 4);
  if ( v4 )
  {
    BBSupportTracePrintF(3, "load output defect Unknown fileFormatVersion for CUserLogoChunk");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v7 = 0;
  while ( g_szExt[5 * v7] )
  {
    swprintf((char *)FileName, (char *)L"Gfx\\%d%s", 1);
    CFileEx::CFileEx((CFileEx *)v8, 1);
    v11 = 0;
    CFileEx::Open(&v9, FileName, 10, 0, UNUSED_ARG(), UNUSED_ARG());
    ElementCount = (*(int (__thiscall **)(struct IS4Chunk *))(*(_DWORD *)a2 + 8))(a2);
    Buffer = operator new[](ElementCount);
    (**(void (__thiscall ***)(struct IS4Chunk *, void *, size_t))a2)(a2, Buffer, ElementCount);
    CFileEx::Write(Buffer, 1u, ElementCount, UNUSED_ARG(), UNUSED_ARG());
    CFileEx::Close((CFileEx *)&v9, UNUSED_ARG(), UNUSED_ARG());
    operator delete[](Buffer);
    ++v7;
    v11 = -1;
    CFileEx::~CFileEx(v8);
  }
  return (*(int (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 12))(a2, 761539485);
}


// address=[0x140a470]
// Decompiled from int __thiscall CUserLogoChunk::Save(CUserLogoChunk *this, struct IS4Chunk *a2)
void  CUserLogoChunk::Save(class IS4Chunk &) {
  
  int v3; // [esp+10h] [ebp-28Ch] BYREF
  void *v4; // [esp+14h] [ebp-288h]
  int v5; // [esp+18h] [ebp-284h]
  size_t Size; // [esp+1Ch] [ebp-280h]
  _DWORD v7[26]; // [esp+20h] [ebp-27Ch] BYREF
  int v8; // [esp+88h] [ebp-214h] BYREF
  wchar_t Buffer[256]; // [esp+8Ch] [ebp-210h] BYREF
  int v10; // [esp+298h] [ebp-4h]

  v3 = 0;
  (*(void (__thiscall **)(struct IS4Chunk *, int))(*(_DWORD *)a2 + 24))(a2, 778316700);
  (*(void (__thiscall **)(struct IS4Chunk *, int *, int))(*(_DWORD *)a2 + 16))(a2, &v3, 4);
  v5 = 0;
  while ( g_szExt[5 * v5] )
  {
    swprintf((char *)Buffer, (char *)L"Gfx\\%d%s", 1);
    CFileEx::CFileEx((CFileEx *)v7, 1);
    v10 = 0;
    CFileEx::Open(&v8, Buffer, 6, 0, UNUSED_ARG(), UNUSED_ARG());
    Size = CFileEx::Size(v7);
    v4 = operator new[](Size);
    CFileEx::Read(&v8, v4, 1, Size, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h", 110);
    CFileEx::Close((CFileEx *)&v8, UNUSED_ARG(), UNUSED_ARG());
    (*(void (__thiscall **)(struct IS4Chunk *, size_t))(*(_DWORD *)a2 + 20))(a2, Size);
    (*(void (__thiscall **)(struct IS4Chunk *, void *, size_t))(*(_DWORD *)a2 + 16))(a2, v4, Size);
    operator delete[](v4);
    ++v5;
    v10 = -1;
    CFileEx::~CFileEx(v7);
  }
  return (*(int (__cdecl **)(int))(*(_DWORD *)a2 + 24))(761539485);
}


// address=[0x1486a50]
// Decompiled from CUserLogoChunk *__thiscall CUserLogoChunk::CUserLogoChunk(CUserLogoChunk *this)
 CUserLogoChunk::CUserLogoChunk(void) {
  
  IS4ChunkObject::IS4ChunkObject(this);
  *(_DWORD *)this = CUserLogoChunk::_vftable_;
  return this;
}


