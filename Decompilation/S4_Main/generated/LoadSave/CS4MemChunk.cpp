#include "CS4MemChunk.h"

// Definitions for class CS4MemChunk

// address=[0x13e6540]
// Decompiled from int __thiscall CS4MemChunk::Data(pairNode *this)
void const *  CS4MemChunk::Data(void)const {
  
  return *((_DWORD *)this + 3);
}


// address=[0x13e6890]
// Decompiled from int __thiscall CS4MemChunk::Size(CS4MemChunk *this)
unsigned int  CS4MemChunk::Size(void)const {
  
  return *((_DWORD *)this + 2);
}


// address=[0x13eca00]
// Decompiled from CS4MemChunk *__thiscall CS4MemChunk::CS4MemChunk(CS4MemChunk *this)
 CS4MemChunk::CS4MemChunk(void) {
  
  IS4Chunk::IS4Chunk(this);
  *(_DWORD *)this = &CS4MemChunk::_vftable_;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = j_CS4MemChunk::SaveFuncNOP;
  *((_DWORD *)this + 6) = CS4MemChunk::SaveUnsigned32NOP;
  return this;
}


// address=[0x13eca60]
// Decompiled from void __thiscall CS4MemChunk::~CS4MemChunk(CS4MemChunk *this)
 CS4MemChunk::~CS4MemChunk(void) {
  
  *(_DWORD *)this = &CS4MemChunk::_vftable_;
  CS4MemChunk::Done(this);
}


// address=[0x13ecab0]
// Decompiled from CS4MemChunk *__thiscall CS4MemChunk::InitLoadData(CS4MemChunk *this, const void *chunkData, unsigned int chunkSize)
void  CS4MemChunk::InitLoadData(void const * chunkData, unsigned int chunkSize) {
  
  CS4MemChunk *result; // eax

  if ( !chunkData && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 66, "_pChunkData != 0") == 1 )
    __debugbreak();
  if ( !chunkSize && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 67, "_uChunkSize > 0") == 1 )
    __debugbreak();
  if ( *((_DWORD *)this + 1) && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 69, "m_tMode == CHUNK_MODE_NONE") == 1 )
    __debugbreak();
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = chunkSize;
  *((_DWORD *)this + 3) = chunkData;
  *((_DWORD *)this + 4) = *((_DWORD *)this + 3);
  result = this;
  *((_DWORD *)this + 5) = j_CS4MemChunk::SaveFuncNOP;
  *((_DWORD *)this + 6) = CS4MemChunk::SaveUnsigned32NOP;
  return result;
}


// address=[0x13ecb70]
// Decompiled from CS4MemChunk *__thiscall CS4MemChunk::InitSaveCalcSize(CS4MemChunk *this)
void  CS4MemChunk::InitSaveCalcSize(void) {
  
  CS4MemChunk *result; // eax

  if ( *((_DWORD *)this + 1) && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 87, "m_tMode == CHUNK_MODE_NONE") == 1 )
    __debugbreak();
  *((_DWORD *)this + 1) = 2;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  result = this;
  *((_DWORD *)this + 5) = CS4MemChunk::SaveFuncCalcSize;
  *((_DWORD *)this + 6) = j_CS4MemChunk::SaveUnsigned32CalcSize;
  return result;
}


// address=[0x13ecbe0]
// Decompiled from CS4MemChunk *__thiscall CS4MemChunk::InitSaveData(CS4MemChunk *this, bool a2)
void  CS4MemChunk::InitSaveData(bool a2) {
  
  CS4MemChunk *result; // eax
  int v3; // [esp+4h] [ebp-8h]

  if ( *((_DWORD *)this + 1) != 2
    && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 105, "m_tMode == CHUNK_MODE_CALC_SIZE") == 1 )
  {
    __debugbreak();
  }
  if ( a2 )
    v3 = 4;
  else
    v3 = 3;
  *((_DWORD *)this + 1) = v3;
  *((_DWORD *)this + 3) = operator new[](*((_DWORD *)this + 2));
  *((_DWORD *)this + 4) = *((_DWORD *)this + 3);
  result = this;
  *((_DWORD *)this + 5) = CS4MemChunk::SaveFuncSaveData;
  *((_DWORD *)this + 6) = CS4MemChunk::SaveUnsigned32SaveData;
  return result;
}


// address=[0x13ecc80]
// Decompiled from void **__thiscall CS4MemChunk::Done(void **this)
void  CS4MemChunk::Done(void) {
  
  void **result; // eax

  if ( this[1] == (void *)4 && this[3] )
    operator delete(this[3]);
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  result = this;
  this[5] = j_CS4MemChunk::SaveFuncNOP;
  this[6] = CS4MemChunk::SaveUnsigned32NOP;
  return result;
}


// address=[0x13ecd00]
// Decompiled from int __thiscall CS4MemChunk::Load(void *this, void *a2, size_t Size)
void  CS4MemChunk::Load(void * a2, unsigned int Size) {
  
  int result; // eax
  int pExceptionObject; // [esp+0h] [ebp-8h] BYREF
  int v5; // [esp+4h] [ebp-4h]

  v5 = (int)this;
  if ( !a2 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 146, "_pData != 0") == 1 )
    __debugbreak();
  if ( !Size && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 147, "_uSize > 0") == 1 )
    __debugbreak();
  if ( *(_DWORD *)(v5 + 4) != 1
    && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 149, "m_tMode == CHUNK_MODE_LOAD_DATA") == 1 )
  {
    __debugbreak();
  }
  if ( !*(_DWORD *)(v5 + 16) && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 150, "m_pCurrent != 0") == 1 )
    __debugbreak();
  if ( Size + *(_DWORD *)(v5 + 16) - *(_DWORD *)(v5 + 12) > *(_DWORD *)(v5 + 8) )
  {
    BBSupportDbgReport(3, "LoadSave\\MemChunk.cpp", 154, "CS4MemChunk::Load() failed!");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  j__memcpy(a2, *(const void **)(v5 + 16), Size);
  result = v5;
  *(_DWORD *)(v5 + 16) += Size;
  return result;
}


// address=[0x13ece20]
// Decompiled from unsigned int __thiscall CS4MemChunk::LoadUnsigned32(CS4MemChunk *this)
unsigned int  CS4MemChunk::LoadUnsigned32(void) {
  
  return CS4MemChunk::LoadUnsigned32Inline(this);
}


// address=[0x13ece40]
// Decompiled from unsigned int __thiscall CS4MemChunk::LoadUnsigned32(CS4MemChunk *this, unsigned int a2, unsigned int a3)
unsigned int  CS4MemChunk::LoadUnsigned32(unsigned int a2, unsigned int a3) {
  
  int v4; // [esp+4h] [ebp-Ch] BYREF
  int pExceptionObject; // [esp+8h] [ebp-8h] BYREF
  unsigned int Unsigned32Inline; // [esp+Ch] [ebp-4h]

  Unsigned32Inline = CS4MemChunk::LoadUnsigned32Inline(this);
  if ( Unsigned32Inline < a2 )
  {
    Unsigned32Inline = a2;
    BBSupportDbgReport(3, "LoadSave\\MemChunk.cpp", 211, "CS4MemChunk::LoadUnsigned32() failed!");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  if ( Unsigned32Inline <= a3 )
    return Unsigned32Inline;
  Unsigned32Inline = a3;
  BBSupportDbgReport(3, "LoadSave\\MemChunk.cpp", 219, "CS4MemChunk::LoadUnsigned32() failed!");
  v4 = 0;
  CS4InvalidMapException::CS4InvalidMapException(&v4);
  _CxxThrowException(&v4, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  return Unsigned32Inline;
}


// address=[0x13ecee0]
// Decompiled from unsigned int __thiscall CS4MemChunk::LoadSignature(CS4MemChunk *this, unsigned int a2)
void  CS4MemChunk::LoadSignature(unsigned int a2) {
  
  unsigned int result; // eax
  int pExceptionObject; // [esp+8h] [ebp-4h] BYREF

  result = CS4MemChunk::LoadUnsigned32Inline(this);
  if ( result == a2 )
    return result;
  BBSupportDbgReport(3, "LoadSave\\MemChunk.cpp", 238, "CS4MemChunk::LoadSignature() failed!");
  pExceptionObject = 0;
  CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
  _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  return result;
}


// address=[0x13ecf40]
// Decompiled from int __thiscall CS4MemChunk::Save(  int (__fastcall **this)(CS4MemChunk *, const void *, unsigned int),  const void *a2,  unsigned int a3)
void  CS4MemChunk::Save(void const * a2, unsigned int a3) {
  
  return this[5]((CS4MemChunk *)this, a2, a3);
}


// address=[0x13ecf60]
// Decompiled from int __thiscall CS4MemChunk::SaveUnsigned32(CS4MemChunk *this, unsigned int a2)
void  CS4MemChunk::SaveUnsigned32(unsigned int a2) {
  
  return (*((int (__fastcall **)(CS4MemChunk *, unsigned int, CS4MemChunk *))this + 6))(this, a2, this);
}


// address=[0x13ecf80]
// Decompiled from int __thiscall CS4MemChunk::SaveSignature(CS4MemChunk *this, unsigned int a2)
void  CS4MemChunk::SaveSignature(unsigned int a2) {
  
  return (*((int (__fastcall **)(CS4MemChunk *, unsigned int, CS4MemChunk *))this + 6))(this, a2, this);
}


// address=[0x13ecfa0]
// Decompiled from unsigned int __thiscall CS4MemChunk::Adler32(CS4MemChunk *this, unsigned int a2)
unsigned int  CS4MemChunk::Adler32(unsigned int a2) {
  
  return Adler32(*((const void **)this + 3), *((_DWORD *)this + 2), a2);
}


// address=[0x13ecfd0]
// Decompiled from void __cdecl CS4MemChunk::ObjectLoad(struct IS4ChunkObject *a1, const void *a2, unsigned int a3)
void __cdecl CS4MemChunk::ObjectLoad(class IS4ChunkObject & a1, void const * a2, unsigned int a3) {
  
  _BYTE v3[28]; // [esp+4h] [ebp-28h] BYREF
  int v4; // [esp+28h] [ebp-4h]

  CS4MemChunk::CS4MemChunk((CS4MemChunk *)v3);
  v4 = 0;
  CS4MemChunk::InitLoadData((CS4MemChunk *)v3, a2, a3);
  (**(void (__thiscall ***)(struct IS4ChunkObject *, _BYTE *))a1)(a1, v3);
  v4 = -1;
  CS4MemChunk::~CS4MemChunk((CS4MemChunk *)v3);
}


// address=[0x13ed050]
// Decompiled from void __cdecl CS4MemChunk::ObjectSave(struct IS4ChunkObject *a1, void **a2, unsigned int *a3)
void __cdecl CS4MemChunk::ObjectSave(class IS4ChunkObject & a1, void * * a2, unsigned int * a3) {
  
  _BYTE v3[8]; // [esp+4h] [ebp-28h] BYREF
  unsigned int v4; // [esp+Ch] [ebp-20h]
  void *v5; // [esp+10h] [ebp-1Ch]
  int v6; // [esp+28h] [ebp-4h]

  CS4MemChunk::CS4MemChunk((CS4MemChunk *)v3);
  v6 = 0;
  CS4MemChunk::InitSaveCalcSize((CS4MemChunk *)v3);
  (*(void (__thiscall **)(struct IS4ChunkObject *, _BYTE *))(*(_DWORD *)a1 + 4))(a1, v3);
  CS4MemChunk::InitSaveData((CS4MemChunk *)v3, 0);
  (*(void (__thiscall **)(struct IS4ChunkObject *, _BYTE *))(*(_DWORD *)a1 + 4))(a1, v3);
  *a2 = v5;
  *a3 = v4;
  v6 = -1;
  CS4MemChunk::~CS4MemChunk((CS4MemChunk *)v3);
}


// address=[0x13ed0f0]
// Decompiled from int __stdcall CS4MemChunk::SaveFuncNOP(int a1)
void __fastcall CS4MemChunk::SaveFuncNOP(void const * a1, unsigned int a2) {
  
  if ( BBSupportDbgReport(0, "LoadSave\\MemChunk.cpp", 291, "CS4MemChunk::SaveFuncNOP() should never be called!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x13ed130]
// Decompiled from CS4MemChunk *__fastcall CS4MemChunk::SaveFuncCalcSize(CS4MemChunk *this, const void *a2, unsigned int a3)
void __fastcall CS4MemChunk::SaveFuncCalcSize(void const * a2, unsigned int a3) {
  
  CS4MemChunk *result; // eax

  if ( !a2 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 301, "_pData != 0") == 1 )
    __debugbreak();
  if ( !a3 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 302, "_uSize > 0") == 1 )
    __debugbreak();
  if ( *((_DWORD *)this + 1) != 2
    && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 304, "m_tMode == CHUNK_MODE_CALC_SIZE") == 1 )
  {
    __debugbreak();
  }
  result = this;
  *((_DWORD *)this + 2) += a3;
  return result;
}


// address=[0x13ed1d0]
// Decompiled from int __fastcall CS4MemChunk::SaveFuncSaveData(int a1, const void *a2, size_t Size)
void __fastcall CS4MemChunk::SaveFuncSaveData(void const * a1, unsigned int a2) {
  
  int result; // eax
  __int64 v5; // [esp+4h] [ebp-Ch]

  if ( !a2 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 316, "_pData != 0") == 1 )
    __debugbreak();
  if ( !Size && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 317, "_uSize > 0") == 1 )
    __debugbreak();
  HIDWORD(v5) = *(_DWORD *)(a1 + 4) == 3;
  LODWORD(v5) = *(_DWORD *)(a1 + 4) == 4;
  if ( !v5
    && BBSupportDbgReport(
         2,
         "LoadSave\\MemChunk.cpp",
         319,
         "(m_tMode == CHUNK_MODE_SAVE_DATA) | (m_tMode == CHUNK_MODE_SAVE_DATA_AUTO_PTR)") == 1 )
  {
    __debugbreak();
  }
  if ( !*(_DWORD *)(a1 + 16) && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 321, "m_pCurrent != 0") == 1 )
    __debugbreak();
  if ( Size + *(_DWORD *)(a1 + 16) - *(_DWORD *)(a1 + 12) > *(_DWORD *)(a1 + 8)
    && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 322, "(m_pCurrent - m_pData + _uSize) <= m_uSize") == 1 )
  {
    __debugbreak();
  }
  j__memcpy(*(void **)(a1 + 16), a2, Size);
  result = Size + *(_DWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 16) = result;
  return result;
}


// address=[0x13ed310]
// Decompiled from int CS4MemChunk::SaveUnsigned32NOP()
void __fastcall CS4MemChunk::SaveUnsigned32NOP(unsigned int) {
  
  if ( BBSupportDbgReport(0, "LoadSave\\MemChunk.cpp", 336, "CS4MemChunk::SaveUnsigned32NOP() should never be called!") == 1 )
    __debugbreak();
  return 0;
}


// address=[0x13ed340]
// Decompiled from int __thiscall CS4MemChunk::SaveUnsigned32CalcSize(_DWORD *this)
void __fastcall CS4MemChunk::SaveUnsigned32CalcSize(unsigned int) {
  
  int result; // eax

  if ( this[1] != 2 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 346, "m_tMode == CHUNK_MODE_CALC_SIZE") == 1 )
    __debugbreak();
  result = this[2] + 4;
  this[2] = result;
  return result;
}


// address=[0x13ed390]
// Decompiled from int __fastcall CS4MemChunk::SaveUnsigned32SaveData(CS4MemChunk *this, unsigned int a2)
void __fastcall CS4MemChunk::SaveUnsigned32SaveData(unsigned int a2) {
  
  int result; // eax
  __int64 v4; // [esp+4h] [ebp-Ch]

  HIDWORD(v4) = *((_DWORD *)this + 1) == 3;
  LODWORD(v4) = *((_DWORD *)this + 1) == 4;
  if ( !v4
    && BBSupportDbgReport(
         2,
         "LoadSave\\MemChunk.cpp",
         358,
         "(m_tMode == CHUNK_MODE_SAVE_DATA) | (m_tMode == CHUNK_MODE_SAVE_DATA_AUTO_PTR)") == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)this + 4) && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 360, "m_pCurrent != 0") == 1 )
    __debugbreak();
  if ( (unsigned int)(*((_DWORD *)this + 4) - *((_DWORD *)this + 3) + 4) > *((_DWORD *)this + 2)
    && BBSupportDbgReport(
         2,
         "LoadSave\\MemChunk.cpp",
         361,
         "static_cast<unsigned int>(m_pCurrent - m_pData + 4) <= m_uSize") == 1 )
  {
    __debugbreak();
  }
  **((_DWORD **)this + 4) = a2;
  result = *((_DWORD *)this + 4) + 4;
  *((_DWORD *)this + 4) = result;
  return result;
}


// address=[0x13ed740]
// Decompiled from int __thiscall CS4MemChunk::LoadUnsigned32Inline(CS4MemChunk *this)
unsigned int  CS4MemChunk::LoadUnsigned32Inline(void) {
  
  int v2; // [esp+0h] [ebp-Ch]
  int pExceptionObject; // [esp+4h] [ebp-8h] BYREF
  CS4MemChunk *v4; // [esp+8h] [ebp-4h]

  v4 = this;
  if ( *((_DWORD *)this + 1) != 1
    && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 171, (const char *)&dword_369B8D4[1]) == 1 )
  {
    __debugbreak();
  }
  if ( !*((_DWORD *)v4 + 4) && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 172, "m_pCurrent != 0") == 1 )
    __debugbreak();
  if ( (unsigned int)(*((_DWORD *)v4 + 4) - *((_DWORD *)v4 + 3) + 4) > *((_DWORD *)v4 + 2) )
  {
    BBSupportDbgReport(3, "LoadSave\\MemChunk.cpp", 176, "CS4MemChunk::LoadUnsigned32() failed!");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v2 = **((_DWORD **)v4 + 4);
  *((_DWORD *)v4 + 4) += 4;
  return v2;
}


