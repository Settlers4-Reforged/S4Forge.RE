#if FALSE
#include "CS4MemChunk.h"

// Definitions for class CS4MemChunk

// address=[0x13e6540]
// Decompiled from const void *__thiscall CS4MemChunk::Data(CS4MemChunk *this)
void const *  CS4MemChunk::Data(void)const {
  
  return this->m_pData;
}


// address=[0x13e6890]
// Decompiled from int __thiscall CS4MemChunk::Size(CS4MemChunk *this)
unsigned int  CS4MemChunk::Size(void)const {
  
  return this->m_uSize;
}


// address=[0x13eca00]
// Decompiled from CS4MemChunk *__thiscall CS4MemChunk::CS4MemChunk(CS4MemChunk *this)
 CS4MemChunk::CS4MemChunk(void) {
  
  IS4Chunk::IS4Chunk(this);
  this->__vftable = (IS4Chunk_vtbl *)&CS4MemChunk::_vftable_;
  this->m_tMode = CHUNK_MODE_NONE;
  this->m_uSize = 0;
  this->m_pData = 0;
  this->m_pCurrent = 0;
  this->m_pSaveFunc = (void (__fastcall *)(CS4MemChunk *, const void *, unsigned int))j_CS4MemChunk::SaveFuncNOP;
  this->m_pSaveUnsigned32 = (void (__fastcall *)(CS4MemChunk *, unsigned int))CS4MemChunk::SaveUnsigned32NOP;
  return this;
}


// address=[0x13eca60]
// Decompiled from CS4MemChunk *__thiscall CS4MemChunk::~CS4MemChunk(CS4MemChunk *this)
 CS4MemChunk::~CS4MemChunk(void) {
  
  this->__vftable = (IS4Chunk_vtbl *)&CS4MemChunk::_vftable_;
  return CS4MemChunk::Done(this);
}


// address=[0x13ecab0]
// Decompiled from CS4MemChunk *__thiscall CS4MemChunk::InitLoadData(CS4MemChunk *this, const void *chunkData, unsigned int chunkSize)
void  CS4MemChunk::InitLoadData(void const * chunkData, unsigned int chunkSize) {
  
  CS4MemChunk *result; // eax

  if ( !chunkData && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 66, "_pChunkData != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !chunkSize && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 67, "_uChunkSize > 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_tMode && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 69, "m_tMode == CHUNK_MODE_NONE") == 1 )
  {
    __debugbreak();
  }
  this->m_tMode = 1;
  this->m_uSize = chunkSize;
  this->m_pData = chunkData;
  this->m_pCurrent = this->m_pData;
  result = this;
  this->m_pSaveFunc = (void (__fastcall *)(CS4MemChunk *, const void *, unsigned int))j_CS4MemChunk::SaveFuncNOP;
  this->m_pSaveUnsigned32 = (void (__fastcall *)(CS4MemChunk *, unsigned int))CS4MemChunk::SaveUnsigned32NOP;
  return result;
}


// address=[0x13ecb70]
// Decompiled from void __thiscall CS4MemChunk::InitSaveCalcSize(CS4MemChunk *this)
void  CS4MemChunk::InitSaveCalcSize(void) {
  
  if ( this->m_tMode && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 87, "m_tMode == CHUNK_MODE_NONE") == 1 )
  {
    __debugbreak();
  }
  this->m_tMode = 2;
  this->m_uSize = 0;
  this->m_pData = 0;
  this->m_pCurrent = 0;
  this->m_pSaveFunc = CS4MemChunk::SaveFuncCalcSize;
  this->m_pSaveUnsigned32 = j_CS4MemChunk::SaveUnsigned32CalcSize;
}


// address=[0x13ecbe0]
// Decompiled from void __thiscall CS4MemChunk::InitSaveData(CS4MemChunk *this, bool a2)
void  CS4MemChunk::InitSaveData(bool a2) {
  
  T_S4_CHUNK_MODE v2; // [esp+4h] [ebp-8h]

  if ( this->m_tMode != 2 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 105, "m_tMode == CHUNK_MODE_CALC_SIZE") == 1 )
  {
    __debugbreak();
  }
  if ( a2 )
  {
    v2 = CHUNK_MODE_SAVE_DATA_AUTO_PTR;
  }
  else
  {
    v2 = CHUNK_MODE_SAVE_DATA;
  }
  this->m_tMode = v2;
  this->m_pData = operator new[](this->m_uSize);
  this->m_pCurrent = this->m_pData;
  this->m_pSaveFunc = CS4MemChunk::SaveFuncSaveData;
  this->m_pSaveUnsigned32 = CS4MemChunk::SaveUnsigned32SaveData;
}


// address=[0x13ecc80]
// Decompiled from CS4MemChunk *__thiscall CS4MemChunk::Done(CS4MemChunk *this)
void  CS4MemChunk::Done(void) {
  
  CS4MemChunk *result; // eax

  if ( this->m_tMode == CHUNK_MODE_SAVE_DATA_AUTO_PTR && this->m_pData )
  {
    operator delete((void *)this->m_pData);
  }
  this->m_tMode = CHUNK_MODE_NONE;
  this->m_uSize = 0;
  this->m_pData = 0;
  this->m_pCurrent = 0;
  result = this;
  this->m_pSaveFunc = (void (__fastcall *)(CS4MemChunk *, const void *, unsigned int))j_CS4MemChunk::SaveFuncNOP;
  this->m_pSaveUnsigned32 = (void (__fastcall *)(CS4MemChunk *, unsigned int))CS4MemChunk::SaveUnsigned32NOP;
  return result;
}


// address=[0x13ecd00]
// Decompiled from void __thiscall CS4MemChunk::Load(CS4MemChunk *this, void *a2, size_t Size)
void  CS4MemChunk::Load(void * a2, unsigned int Size) {
  
  int pExceptionObject; // [esp+0h] [ebp-8h] BYREF
  CS4MemChunk *v4; // [esp+4h] [ebp-4h]

  v4 = this;
  if ( !a2 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 146, "_pData != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !Size && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 147, "_uSize > 0") == 1 )
  {
    __debugbreak();
  }
  if ( v4->m_tMode != 1 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 149, "m_tMode == CHUNK_MODE_LOAD_DATA") == 1 )
  {
    __debugbreak();
  }
  if ( !v4->m_pCurrent && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 150, "m_pCurrent != 0") == 1 )
  {
    __debugbreak();
  }
  if ( Size + (char *)v4->m_pCurrent - (char *)v4->m_pData > v4->m_uSize )
  {
    BBSupportDbgReport(3, "LoadSave\\MemChunk.cpp", 154, "CS4MemChunk::Load() failed!");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  memcpy(a2, v4->m_pCurrent, Size);
  v4->m_pCurrent = (char *)v4->m_pCurrent + Size;
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
  {
    return Unsigned32Inline;
  }
  Unsigned32Inline = a3;
  BBSupportDbgReport(3, "LoadSave\\MemChunk.cpp", 219, "CS4MemChunk::LoadUnsigned32() failed!");
  v4 = 0;
  CS4InvalidMapException::CS4InvalidMapException(&v4);
  _CxxThrowException(&v4, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  return Unsigned32Inline;
}


// address=[0x13ecee0]
// Decompiled from void __thiscall CS4MemChunk::LoadSignature(CS4MemChunk *this, unsigned int a2)
void  CS4MemChunk::LoadSignature(unsigned int a2) {
  
  int pExceptionObject; // [esp+8h] [ebp-4h] BYREF

  if ( CS4MemChunk::LoadUnsigned32Inline(this) != a2 )
  {
    BBSupportDbgReport(3, "LoadSave\\MemChunk.cpp", 238, "CS4MemChunk::LoadSignature() failed!");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
}


// address=[0x13ecf40]
// Decompiled from int __thiscall CS4MemChunk::Save(CS4MemChunk *this, const void *a2, unsigned int a3)
void  CS4MemChunk::Save(void const * a2, unsigned int a3) {
  
  return ((int (__fastcall *)(CS4MemChunk *, const void *, unsigned int))this->m_pSaveFunc)(this, a2, a3);
}


// address=[0x13ecf60]
// Decompiled from int __thiscall CS4MemChunk::SaveUnsigned32(CS4MemChunk *this, unsigned int a2)
void  CS4MemChunk::SaveUnsigned32(unsigned int a2) {
  
  return ((int (__fastcall *)(CS4MemChunk *, unsigned int, CS4MemChunk *))this->m_pSaveUnsigned32)(this, a2, this);
}


// address=[0x13ecf80]
// Decompiled from int __thiscall CS4MemChunk::SaveSignature(CS4MemChunk *this, unsigned int a2)
void  CS4MemChunk::SaveSignature(unsigned int a2) {
  
  return ((int (__fastcall *)(CS4MemChunk *, unsigned int, CS4MemChunk *))this->m_pSaveUnsigned32)(this, a2, this);
}


// address=[0x13ecfa0]
// Decompiled from int __thiscall CS4MemChunk::Adler32(CS4MemChunk *this, unsigned int a2)
unsigned int  CS4MemChunk::Adler32(unsigned int a2) {
  
  return Adler32((unsigned __int8 *)this->m_pData, this->m_uSize, a2);
}


// address=[0x13ecfd0]
// Decompiled from CS4MemChunk *__cdecl CS4MemChunk::ObjectLoad(struct IS4ChunkObject *a1, const void *a2, unsigned int a3)
void __cdecl CS4MemChunk::ObjectLoad(class IS4ChunkObject & a1, void const * a2, unsigned int a3) {
  
  CS4MemChunk v4; // [esp+4h] [ebp-28h] BYREF
  int v5; // [esp+28h] [ebp-4h]

  CS4MemChunk::CS4MemChunk(&v4);
  v5 = 0;
  CS4MemChunk::InitLoadData(&v4, a2, a3);
  a1->Load(a1, &v4);
  v5 = -1;
  return CS4MemChunk::~CS4MemChunk(&v4);
}


// address=[0x13ed050]
// Decompiled from CS4MemChunk *__cdecl CS4MemChunk::ObjectSave(struct IS4ChunkObject *a1, const void **a2, unsigned int *a3)
void __cdecl CS4MemChunk::ObjectSave(class IS4ChunkObject & a1, void * * a2, unsigned int * a3) {
  
  CS4MemChunk v4; // [esp+4h] [ebp-28h] BYREF
  int v5; // [esp+28h] [ebp-4h]

  CS4MemChunk::CS4MemChunk(&v4);
  v5 = 0;
  CS4MemChunk::InitSaveCalcSize(&v4);
  a1->Save(a1, &v4);
  CS4MemChunk::InitSaveData(&v4, 0);
  a1->Save(a1, &v4);
  *a2 = v4.m_pData;
  *a3 = v4.m_uSize;
  v5 = -1;
  return CS4MemChunk::~CS4MemChunk(&v4);
}


// address=[0x13ed0f0]
// Decompiled from int __stdcall CS4MemChunk::SaveFuncNOP(int a1)
void __fastcall CS4MemChunk::SaveFuncNOP(void const * a1, unsigned int a2) {
  
  if ( BBSupportDbgReport(0, "LoadSave\\MemChunk.cpp", 291, "CS4MemChunk::SaveFuncNOP() should never be called!") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x13ed130]
// Decompiled from void __fastcall CS4MemChunk::SaveFuncCalcSize(CS4MemChunk *this, const void *_pData, unsigned int _uSize)
void __fastcall CS4MemChunk::SaveFuncCalcSize(void const * _pData, unsigned int _uSize) {
  
  if ( !_pData && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 301, "_pData != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !_uSize && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 302, "_uSize > 0") == 1 )
  {
    __debugbreak();
  }
  if ( this->m_tMode != 2 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 304, "m_tMode == CHUNK_MODE_CALC_SIZE") == 1 )
  {
    __debugbreak();
  }
  this->m_uSize += _uSize;
}


// address=[0x13ed1d0]
// Decompiled from void __fastcall CS4MemChunk::SaveFuncSaveData(CS4MemChunk *this, const void *a2, size_t Size)
void __fastcall CS4MemChunk::SaveFuncSaveData(void const * a2, unsigned int Size) {
  
  __int64 v4; // [esp+4h] [ebp-Ch]

  if ( !a2 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 316, "_pData != 0") == 1 )
  {
    __debugbreak();
  }
  if ( !Size && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 317, "_uSize > 0") == 1 )
  {
    __debugbreak();
  }
  HIDWORD(v4) = this->m_tMode == CHUNK_MODE_SAVE_DATA;
  LODWORD(v4) = this->m_tMode == CHUNK_MODE_SAVE_DATA_AUTO_PTR;
  if ( !v4 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 319, "(m_tMode == CHUNK_MODE_SAVE_DATA) | (m_tMode == CHUNK_MODE_SAVE_DATA_AUTO_PTR)") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pCurrent && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 321, "m_pCurrent != 0") == 1 )
  {
    __debugbreak();
  }
  if ( Size + (char *)this->m_pCurrent - (char *)this->m_pData > this->m_uSize && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 322, "(m_pCurrent - m_pData + _uSize) <= m_uSize") == 1 )
  {
    __debugbreak();
  }
  memcpy((void *)this->m_pCurrent, a2, Size);
  this->m_pCurrent = (char *)this->m_pCurrent + Size;
}


// address=[0x13ed310]
// Decompiled from int CS4MemChunk::SaveUnsigned32NOP()
void __fastcall CS4MemChunk::SaveUnsigned32NOP(unsigned int) {
  
  if ( BBSupportDbgReport(0, "LoadSave\\MemChunk.cpp", 336, "CS4MemChunk::SaveUnsigned32NOP() should never be called!") == 1 )
  {
    __debugbreak();
  }
  return 0;
}


// address=[0x13ed340]
// Decompiled from void __thiscall CS4MemChunk::SaveUnsigned32CalcSize(CS4MemChunk *this, unsigned int a2)
void __fastcall CS4MemChunk::SaveUnsigned32CalcSize(unsigned int a2) {
  
  if ( this->m_tMode != 2 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 346, "m_tMode == CHUNK_MODE_CALC_SIZE") == 1 )
  {
    __debugbreak();
  }
  this->m_uSize += 4;
}


// address=[0x13ed390]
// Decompiled from void __fastcall CS4MemChunk::SaveUnsigned32SaveData(CS4MemChunk *this, unsigned int a2)
void __fastcall CS4MemChunk::SaveUnsigned32SaveData(unsigned int a2) {
  
  __int64 v3; // [esp+4h] [ebp-Ch]

  HIDWORD(v3) = this->m_tMode == CHUNK_MODE_SAVE_DATA;
  LODWORD(v3) = this->m_tMode == CHUNK_MODE_SAVE_DATA_AUTO_PTR;
  if ( !v3 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 358, "(m_tMode == CHUNK_MODE_SAVE_DATA) | (m_tMode == CHUNK_MODE_SAVE_DATA_AUTO_PTR)") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pCurrent && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 360, "m_pCurrent != 0") == 1 )
  {
    __debugbreak();
  }
  if ( (unsigned int)((char *)this->m_pCurrent - (char *)this->m_pData + 4) > this->m_uSize && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 361, "static_cast<unsigned int>(m_pCurrent - m_pData + 4) <= m_uSize") == 1 )
  {
    __debugbreak();
  }
  *(_DWORD *)this->m_pCurrent = a2;
  this->m_pCurrent = (char *)this->m_pCurrent + 4;
}


// address=[0x13ed740]
// Decompiled from int __thiscall CS4MemChunk::LoadUnsigned32Inline(CS4MemChunk *this)
unsigned int  CS4MemChunk::LoadUnsigned32Inline(void) {
  
  int v2; // [esp+0h] [ebp-Ch]
  int pExceptionObject; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_tMode != 1 && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 171, "m_tMode == CHUNK_MODE_LOAD_DATA") == 1 )
  {
    __debugbreak();
  }
  if ( !this->m_pCurrent && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 172, "m_pCurrent != 0") == 1 )
  {
    __debugbreak();
  }
  if ( (unsigned int)((char *)this->m_pCurrent - (char *)this->m_pData + 4) > this->m_uSize )
  {
    BBSupportDbgReport(3, "LoadSave\\MemChunk.cpp", 176, "CS4MemChunk::LoadUnsigned32() failed!");
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
  }
  v2 = *(_DWORD *)this->m_pCurrent;
  this->m_pCurrent = (char *)this->m_pCurrent + 4;
  return v2;
}


#endif // Already implemented
