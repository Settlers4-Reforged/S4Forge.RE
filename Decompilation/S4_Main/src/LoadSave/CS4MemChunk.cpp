#include "CS4MemChunk.h"

#include <functional>

#include "IS4ChunkObject.h"
#include "CBB/CBBSupport.h"

// Definitions for class CS4MemChunk

// address=[0x13e6540]
// Decompiled from const void *__thiscall CS4MemChunk::Data(CS4MemChunk *this)
void const *CS4MemChunk::Data(void) const {
  return this->m_pData;
}


// address=[0x13e6890]
// Decompiled from int __thiscall CS4MemChunk::Size(CS4MemChunk *this)
unsigned int CS4MemChunk::Size(void) const {
  return this->m_uSize;
}

// address=[0x13eca00]
// Decompiled from CS4MemChunk *__thiscall CS4MemChunk::CS4MemChunk(CS4MemChunk *this)
CS4MemChunk::CS4MemChunk(void) : IS4Chunk() {
  this->m_tMode = CHUNK_MODE_NONE;
  this->m_uSize = 0;
  this->m_pData = 0;
  this->m_pCurrent = 0;
  this->m_pSaveFunc = &CS4MemChunk::SaveFuncNOP;
  this->m_pSaveUnsigned32 = &CS4MemChunk::SaveUnsigned32NOP;
}


// address=[0x13eca60]
// Decompiled from CS4MemChunk *__thiscall CS4MemChunk::~CS4MemChunk(CS4MemChunk *this)
CS4MemChunk::~CS4MemChunk(void) {
  this->Done();
}


// address=[0x13ecab0]
// Decompiled from CS4MemChunk *__thiscall CS4MemChunk::InitLoadData(CS4MemChunk *this, const void *chunkData, unsigned int chunkSize)
void CS4MemChunk::InitLoadData(void const *chunkData, unsigned int chunkSize) {
  CS4MemChunk *result; // eax

  if(!chunkData && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 66, "_pChunkData != 0") == 1)
    __debugbreak();
  if(!chunkSize && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 67, "_uChunkSize > 0") == 1)
    __debugbreak();
  if(this->m_tMode && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 69, "m_tMode == CHUNK_MODE_NONE") == 1)
    __debugbreak();
  this->m_tMode = CHUNK_MODE_LOAD_DATA;
  this->m_uSize = chunkSize;
  this->m_pData = (uint8_t *) chunkData;
  this->m_pCurrent = this->m_pData;
  this->m_pSaveFunc = &CS4MemChunk::SaveFuncNOP;
  this->m_pSaveUnsigned32 = &CS4MemChunk::SaveUnsigned32NOP;
}


// address=[0x13ecb70]
// Decompiled from void __thiscall CS4MemChunk::InitSaveCalcSize(CS4MemChunk *this)
void CS4MemChunk::InitSaveCalcSize(void) {
  if(this->m_tMode && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 87, "m_tMode == CHUNK_MODE_NONE") == 1)
    __debugbreak();
  this->m_tMode = CHUNK_MODE_CALC_SIZE;
  this->m_uSize = 0;
  this->m_pData = 0;
  this->m_pCurrent = 0;
  this->m_pSaveFunc = &CS4MemChunk::SaveFuncCalcSize;
  this->m_pSaveUnsigned32 = &CS4MemChunk::SaveUnsigned32CalcSize;
}


// address=[0x13ecbe0]
// Decompiled from void __thiscall CS4MemChunk::InitSaveData(CS4MemChunk *this, bool a2)
void CS4MemChunk::InitSaveData(bool a2) {
  T_S4_CHUNK_MODE v2; // [esp+4h] [ebp-8h]

  if(this->m_tMode != CHUNK_MODE_CALC_SIZE
     && BBSupportDbgReport(2, "LoadSave\\MemChunk.cpp", 105, "m_tMode == CHUNK_MODE_CALC_SIZE") == 1) {
    __debugbreak();
  }
  if(a2)
    v2 = CHUNK_MODE_SAVE_DATA_AUTO_PTR;
  else
    v2 = CHUNK_MODE_SAVE_DATA;
  this->m_tMode = v2;
  this->m_pData = new uint8_t[this->m_uSize];
  this->m_pCurrent = this->m_pData;
  this->m_pSaveFunc = &CS4MemChunk::SaveFuncSaveData;
  this->m_pSaveUnsigned32 = &CS4MemChunk::SaveUnsigned32SaveData;
}


// address=[0x13ecc80]
// Decompiled from CS4MemChunk *__thiscall CS4MemChunk::Done(CS4MemChunk *this)
void CS4MemChunk::Done(void) {
  if(this->m_tMode == CHUNK_MODE_SAVE_DATA_AUTO_PTR && this->m_pData)
    operator delete((void *) this->m_pData);
  this->m_tMode = CHUNK_MODE_NONE;
  this->m_uSize = 0;
  this->m_pData = 0;
  this->m_pCurrent = 0;
  this->m_pSaveFunc = &CS4MemChunk::SaveFuncNOP;
  this->m_pSaveUnsigned32 = &CS4MemChunk::SaveUnsigned32NOP;
}


// address=[0x13ecd00]
// Decompiled from int __thiscall CS4MemChunk::Load(void *this, void *a2, size_t Size)
void CS4MemChunk::Load(void *_pData, unsigned int _uSize) {
  BB_ASSERT(_pData != 0);
  BB_ASSERT(_uSize > 0);
  BB_ASSERT(m_tMode == CHUNK_MODE_LOAD_DATA);
  BB_ASSERT(m_pCurrent != 0);

  if(_uSize + (char *) this->m_pCurrent - (char *) this->m_pData > this->m_uSize) {
    BB_REPORT("CS4MemChunk::Load() failed!")
    throw new CS4InvalidMapException();
  }
  memcpy(_pData, this->m_pCurrent, _uSize);
  this->m_pCurrent = this->m_pCurrent + _uSize;
}


// address=[0x13ece20]
// Decompiled from unsigned int __thiscall CS4MemChunk::LoadUnsigned32(CS4MemChunk *this)
unsigned int CS4MemChunk::LoadUnsigned32(void) {
  return this->LoadUnsigned32Inline();
}


// address=[0x13ece40]
// Decompiled from unsigned int __thiscall CS4MemChunk::LoadUnsigned32(CS4MemChunk *this, unsigned int a2, unsigned int a3)
unsigned int CS4MemChunk::LoadUnsigned32(unsigned int _uMin, unsigned int _uMax) {
  unsigned int uLoadedData = this->LoadUnsigned32Inline();
  if(uLoadedData < _uMin) {
    uLoadedData = _uMin;
    BB_REPORT("CS4MemChunk::LoadUnsigned32() failed!")
    throw new CS4InvalidMapException();
  }
  if(uLoadedData <= _uMax)
    return uLoadedData;
  uLoadedData = _uMax;
  BB_REPORT("CS4MemChunk::LoadUnsigned32() failed!")
  throw new CS4InvalidMapException();
}


// address=[0x13ecee0]
// Decompiled from unsigned int __thiscall CS4MemChunk::LoadSignature(CS4MemChunk *this, unsigned int a2)
void CS4MemChunk::LoadSignature(unsigned int _uSignature) {
  if(this->LoadUnsigned32Inline() != _uSignature) {
    BB_REPORT("CS4MemChunk::LoadSignature() failed!")
    throw new CS4InvalidMapException();
  }
}


// address=[0x13ecf40]
// Decompiled from int __thiscall CS4MemChunk::Save(  int (__fastcall **this)(CS4MemChunk *, const void *, unsigned int),  const void *a2,  unsigned int a3)
void CS4MemChunk::Save(void const *_pTarget, unsigned int _uValue) {
  return (this->*m_pSaveFunc)(_pTarget, _uValue);
}

// address=[0x13ecf60]
// Decompiled from int __thiscall CS4MemChunk::SaveUnsigned32(CS4MemChunk *this, unsigned int a2)
void CS4MemChunk::SaveUnsigned32(unsigned int _uValue) {
  return (this->*m_pSaveUnsigned32)(_uValue);
}


// address=[0x13ecf80]
// Decompiled from int __thiscall CS4MemChunk::SaveSignature(CS4MemChunk *this, unsigned int a2)
void CS4MemChunk::SaveSignature(unsigned int _uSignature) {
  return (this->*m_pSaveUnsigned32)(_uSignature);
}


// address=[0x13ecfa0]
// Decompiled from unsigned int __thiscall CS4MemChunk::Adler32(CS4MemChunk *this, unsigned int a2)
unsigned int CS4MemChunk::Adler32(unsigned int a2) {
  return ::Adler32((unsigned __int8 *) this->m_pData, this->m_uSize, a2);
}


// address=[0x13ecfd0]
// Decompiled from void __cdecl CS4MemChunk::ObjectLoad(struct IS4ChunkObject *a1, const void *a2, unsigned int a3)
void __cdecl CS4MemChunk::ObjectLoad(class IS4ChunkObject &_rChunk, void const *_pTarget, unsigned int _uSize) {
  CS4MemChunk cTempChunk = CS4MemChunk();
  cTempChunk.InitLoadData(_pTarget, _uSize);
  _rChunk.Load(cTempChunk);
}


// address=[0x13ed050]
// Decompiled from void __cdecl CS4MemChunk::ObjectSave(struct IS4ChunkObject *a1, void **a2, unsigned int *a3)
void __cdecl CS4MemChunk::ObjectSave(class IS4ChunkObject &_rChunk, void **_pSource, unsigned int *_pSize) {
  CS4MemChunk cTempChunk = CS4MemChunk();
  cTempChunk.InitSaveCalcSize();
  _rChunk.Save(cTempChunk);
  cTempChunk.InitSaveData(false);
  _rChunk.Save(cTempChunk);
  *_pSource = cTempChunk.m_pData;
  *_pSize = cTempChunk.m_uSize;
}


// address=[0x13ed0f0]
// Decompiled from int __stdcall CS4MemChunk::SaveFuncNOP(int a1)
void __fastcall CS4MemChunk::SaveFuncNOP(void const *a1, unsigned int a2) {
  BB_REPORT("CS4MemChunk::SaveFuncNOP() should never be called!");
}


// address=[0x13ed130]
// Decompiled from void __fastcall CS4MemChunk::SaveFuncCalcSize(CS4MemChunk *this, const void *_pData, unsigned int _uSize)
void __fastcall CS4MemChunk::SaveFuncCalcSize(void const *_pData, unsigned int _uSize) {
  BB_ASSERT(_pData != 0)
  BB_ASSERT(_uSize > 0)
  BB_ASSERT(_uSize > CHUNK_MODE_CALC_SIZE)

  this->m_uSize += _uSize;
}


// address=[0x13ed1d0]
// Decompiled from void __fastcall CS4MemChunk::SaveFuncSaveData(CS4MemChunk *a1, const void *a2, size_t Size)
void __fastcall CS4MemChunk::SaveFuncSaveData(void const *_pData, unsigned int _uSize) {
  __int64 v4; // [esp+4h] [ebp-Ch]

  BB_ASSERT(_pData != 0);
  BB_ASSERT(_uSize > 0);
  BB_ASSERT(m_tMode == CHUNK_MODE_SAVE_DATA || m_tMode == CHUNK_MODE_SAVE_DATA_AUTO_PTR);
  BB_ASSERT(this->m_pCurrent != 0);

  BB_ASSERT((m_pCurrent - m_pData + _uSize) <= m_uSize)
  memcpy(this->m_pCurrent, _pData, _uSize);
  this->m_pCurrent = this->m_pCurrent + _uSize;
}


// address=[0x13ed310]
// Decompiled from int CS4MemChunk::SaveUnsigned32NOP()
void __fastcall CS4MemChunk::SaveUnsigned32NOP(unsigned int) {
  BB_REPORT("CS4MemChunk::SaveUnsigned32NOP() should never be called!");
}


// address=[0x13ed340]
// Decompiled from void __thiscall CS4MemChunk::SaveUnsigned32CalcSize(CS4MemChunk *this, unsigned int a2)
void __fastcall CS4MemChunk::SaveUnsigned32CalcSize(unsigned int a2) {
  BB_ASSERT(m_tMode == CHUNK_MODE_CALC_SIZE)
  this->m_uSize += 4;
}


// address=[0x13ed390]
// Decompiled from void __fastcall CS4MemChunk::SaveUnsigned32SaveData(CS4MemChunk *this, unsigned int a2)
void __fastcall CS4MemChunk::SaveUnsigned32SaveData(unsigned int a2) {
  BB_ASSERT(m_tMode == CHUNK_MODE_SAVE_DATA || m_tMode == CHUNK_MODE_SAVE_DATA_AUTO_PTR);
  BB_ASSERT(this->m_pCurrent != 0);
  BB_ASSERT(static_cast<unsigned int>(m_pCurrent - m_pData + 4) <= m_uSize)

  *reinterpret_cast<uint32_t *>(this->m_pCurrent) = a2;
  this->m_pCurrent = this->m_pCurrent + 4;
}


// address=[0x13ed740]
// Decompiled from int __thiscall CS4MemChunk::LoadUnsigned32Inline(CS4MemChunk *this)
unsigned int CS4MemChunk::LoadUnsigned32Inline(void) {
  // [esp+0h] [ebp-Ch]
  int pExceptionObject; // [esp+4h] [ebp-8h] BYREF

  BB_ASSERT(this->m_tMode == CHUNK_MODE_LOAD_DATA)
  BB_ASSERT(this->m_pCurrent != 0);

  if(static_cast<unsigned int>((this->m_pCurrent - this->m_pData + 4) > this->m_uSize)) {
    BB_REPORT("CS4MemChunk::LoadUnsigned32() failed!")
    throw new CS4InvalidMapException();
  }
  int uVal = *reinterpret_cast<uint32_t *>(this->m_pCurrent);
  this->m_pCurrent = this->m_pCurrent + 4;
  return uVal;
}


