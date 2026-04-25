#include "CMapFile.h"

#include "Crc.h"
#include "Cryptor.h"
#include "CS4MemChunk.h"
#include "CSaveFile.h"
#include "IS4ChunkObject.h"
#include "CBB/CBBSupport.h"
#include "CBB/CS4InvalidMapException.h"
#include "Compression/LZHL.h"

// Definitions for class CMapFile

// address=[0x13da7f0]
// Decompiled from struct CMapFile *__thiscall S4::CMapFile::CMapFile(S4::CMapFile *this, bool a2)
S4::CMapFile::CMapFile(bool a2) : m_cSaveFile(a2), m_swName(), m_vLoadedChunks(), m_vRefCounts() {
  this->m_bVirtual = 0;
  this->m_b5 = 0;
  this->m_uFilePos = 0;
  this->m_iChecksum = 0;
  memset(this->m_uData, 0, sizeof(this->m_uData));
  this->m_bCompress = 0;
}


// address=[0x13da8d0]
// Decompiled from void __thiscall S4::CMapFile::~CMapFile(S4::CMapFile *this)
S4::CMapFile::~CMapFile(void) {
  if(this->m_b5)
    this->Close();
}


// address=[0x13da960]
// Decompiled from void __thiscall S4::CMapFile::Open(S4::CMapFile *this, std::wstring *a2, int a3, char a4)
void S4::CMapFile::Open(std::wstring const &a2, int a3, bool a4) {
  int Buffer; // [esp+10h] [ebp-8h] BYREF

  unsigned int iFileCRC = 0;
  BB_ASSERT(!m_bVirtual);

  this->m_swName = a2;

  this->unk_78 = a3;
  this->m_b5 = 1;
  if((a3 & 1) != 0) {
    m_cSaveFile.Open(a2, a3);
    this->m_uFilePos = this->m_cSaveFile.GetFilePos();
    this->m_cSaveFile.Read(&this->m_iChecksum, 4u);
    this->m_cSaveFile.Read(&Buffer, 4u);
    if(Buffer != 31 && Buffer != 40) {
      this->m_cSaveFile.Close();
      throw new CS4InvalidMapException();
    }
    unsigned int uFileSize = this->m_cSaveFile.GetFileSize();
    this->m_cSaveFile.SetFilePos(this->m_uFilePos + 8, 0);
    if(a4) {
      iFileCRC = this->FileCRC(this->m_uFilePos + 8, uFileSize);
      if(iFileCRC != this->m_iChecksum) {
        this->m_cSaveFile.Close();
        throw new CS4InvalidMapException();
      }
    }
  } else if((a3 & 2) != 0) {
    this->m_cSaveFile.Open(a2, 3);
    Buffer = 31;
    this->m_uFilePos = this->m_cSaveFile.GetFileSize();
    this->m_cSaveFile.Write(&this->m_iChecksum, 4u);
    this->m_cSaveFile.Write(&Buffer, 4u);
  }
}


// address=[0x13dab20]
// Decompiled from int __thiscall S4::CMapFile::Close(S4::CMapFile *this)
void S4::CMapFile::Close(void) {
  // [esp+2Ch] [ebp-2Ch]
  // [esp+30h] [ebp-28h]
  // [esp+34h] [ebp-24h]
  // [esp+38h] [ebp-20h]
  // [esp+3Ch] [ebp-1Ch]
  // [esp+40h] [ebp-18h]
  // [esp+4Bh] [ebp-Dh]
  // [esp+54h] [ebp-4h]

  for(auto &[uId, pData]: m_vLoadedChunks) {
    operator delete[](pData);
  }
  m_vLoadedChunks.clear();
  m_vRefCounts.clear();

  if(this->unk_78 == 2) {
    unsigned int uFileSize = this->m_cSaveFile.GetFileSize();
    this->m_cSaveFile.SetFilePos(this->m_uFilePos + 8, 0);
    unsigned int Buffer = this->FileCRC(this->m_uFilePos + 8, uFileSize);
    this->m_cSaveFile.SetFilePos(this->m_uFilePos, 0);
    this->m_cSaveFile.Write(&Buffer, 4u);
  }
  this->m_cSaveFile.Close();
  this->m_bVirtual = 0;
  this->m_iChecksum = 0;
  this->m_b5 = 0;
  memset(this->m_uData, 0, sizeof(this->m_uData));
}


// address=[0x13dace0]
// Decompiled from void __thiscall S4::CMapFile::Virtualize(S4::CMapFile *this)
void S4::CMapFile::Virtualize(void) {
  BB_ASSERT(!this->m_bVirtual);
  this->m_bVirtual = 1;
}


// address=[0x13dad20]
// Decompiled from int __thiscall S4::CMapFile::GetChecksum(S4::CMapFile *this)
unsigned int S4::CMapFile::GetChecksum(void) const {
  return this->m_iChecksum;
}


// address=[0x13dad40]
// Decompiled from void *__thiscall S4::CMapFile::LoadChunk(S4::CMapFile *this, unsigned __int16 a2, unsigned __int16 a3)
void const *S4::CMapFile::LoadChunk(unsigned int a2, unsigned int a3) {
  int v4 = 0;
  return LoadChunk(a2, a3, v4, 0);
}

struct SSaveFileChunk {
  WORD m_uChunkTypeA;
  WORD m_uChunkTypeB;
  int  m_uChunkSizeInFile;
  int  m_uUncompressedSize;
  int  m_uChunkCRC;
  int  x;
  int  m_uSaveIdentifier;
};

static_assert(sizeof(SSaveFileChunk) == 0x18, "Size of SSaveFileChunk is not 24 bytes!");


// address=[0x13dad70]
// Decompiled from void *__thiscall S4::CMapFile::LoadChunk(  S4::CMapFile *this,  unsigned __int16 a2,  unsigned __int16 a3,  int *a4,  size_t *a5)
void const *S4::CMapFile::LoadChunk(unsigned short a2, unsigned short a3, int &a4, int *_uReadSize) {
  char *pChunkFileEnd; // [esp+5Ch] [ebp-BCh]
  char *pChunkCompressedEnd; // [esp+60h] [ebp-B8h]
  char *pChunkDataBuffer; // [esp+D4h] [ebp-44h]
  char *pReadChunkData; // [esp+E4h] [ebp-34h]

  int  uRequestedType = a2 + (a3 << 16);
  auto itFoundRef = m_vRefCounts.find(uRequestedType);
  if(itFoundRef != m_vRefCounts.end()) {
    BB_ASSERT(m_vLoadedChunks.find(uRequestedType) != m_vLoadedChunks.end())
    m_vRefCounts[uRequestedType]++;
    if(a2 < 0x100u && !a3)
      a4 = *(_DWORD *) &this->m_uData[4 * a2];
    return m_vLoadedChunks[uRequestedType];
    // Technically return type seems to be:
    // Probably a dereference of the operator
    //    return *(void **)std::map<unsigned int,void *>::operator[](&uRequestedType);
  } else {
    if(this->m_bVirtual)
      return nullptr;

    BB_ASSERT(m_vLoadedChunks.find(uRequestedType) != m_vLoadedChunks.end())
    pReadChunkData = 0;
    SSaveFileChunk sChunk{}; // [esp+F0h] [ebp-28h] BYREF
    unsigned int   uReadSize = 0;
    unsigned int   uChunkType = 0;
    this->m_cSaveFile.SetFilePos(this->m_uFilePos + 8, 0);
    do {
      uReadSize = this->m_cSaveFile.Read(&sChunk, 0x18u);
      S4::CMapFile::Cryption(&sChunk, 0x18u);
      uChunkType = sChunk.m_uChunkTypeA + (sChunk.m_uChunkTypeB << 16);
      if(uReadSize == 0x18 && uChunkType == uRequestedType) {
        pReadChunkData = new char[sChunk.m_uChunkSizeInFile];
        int uReadChunkSize = this->m_cSaveFile.Read(pReadChunkData, sChunk.m_uChunkSizeInFile);
        if(uReadChunkSize != sChunk.m_uChunkSizeInFile) {
          delete[] pReadChunkData;
          //TODO: thats it here? Maybe add a BB_REPORT here or something
        }
      } else if(uReadSize == 0x18) {
        this->m_cSaveFile.SetFilePos(sChunk.m_uChunkSizeInFile, 1);
      }
    } while(!this->m_cSaveFile.Eof() && uReadSize == 24 && uChunkType != uRequestedType);
    if(!pReadChunkData)
      return 0;
    a4 = sChunk.m_uSaveIdentifier;
    unsigned int uCalcCRC = this->Crc(pReadChunkData, sChunk.m_uChunkSizeInFile);
    if(uCalcCRC != sChunk.m_uChunkCRC) {
      BBSupportTracePrintF(3, "Invalid chunk CRC!");
      throw new CS4InvalidMapException();
    }
    size_t uSize = 0;
    if(sChunk.m_uUncompressedSize == -1) {
      uSize = sChunk.m_uChunkSizeInFile;
      pChunkDataBuffer = new char[sChunk.m_uChunkSizeInFile];
      memcpy(pChunkDataBuffer, pReadChunkData, uSize);
    } else {
      uSize = sChunk.m_uUncompressedSize;
      pChunkDataBuffer = new char[sChunk.m_uUncompressedSize];
      size_t uCompressedSize = sChunk.m_uUncompressedSize;
      size_t uChunkSize = sChunk.m_uChunkSizeInFile;
      pChunkFileEnd = &pChunkDataBuffer[sChunk.m_uUncompressedSize];
      pChunkCompressedEnd = &pReadChunkData[sChunk.m_uChunkSizeInFile];
      LZHLDecompressor *rDecompressor = LZHLCreateDecompressor();
      do {
        if(!LZHLDecompress(rDecompressor, reinterpret_cast<uint8_t *>(&pChunkFileEnd[-uCompressedSize]), &uCompressedSize, reinterpret_cast<const uint8_t *>(&pChunkCompressedEnd[-uChunkSize]), &uChunkSize)) {
          BBSupportTracePrintF(3, "Decompression of chunk failed!");
          throw new CS4InvalidMapException();
        }
      } while(uChunkSize);
      LZHLDestroyDecompressor(rDecompressor);
    }
    if(_uReadSize)
      *_uReadSize = uSize;
    if(pReadChunkData) {
      delete[] pReadChunkData;
      pReadChunkData = 0;
    }
    m_vLoadedChunks[uRequestedType] = pChunkDataBuffer;
    m_vRefCounts[uRequestedType] = 1;
    return pChunkDataBuffer;
  }

  return nullptr;
}


// address=[0x13db3e0]
// Decompiled from void __thiscall S4::CMapFile::CloseChunk(S4::CMapFile *this, unsigned __int16 a2, unsigned __int16 a3)
void S4::CMapFile::CloseChunk(unsigned short a2, unsigned short a3) {
  // [esp-4h] [ebp-80h]
  // [esp-4h] [ebp-80h]
  _BYTE v5[12]; // [esp+4h] [ebp-78h] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-6Ch] BYREF
  _BYTE v7[12]; // [esp+1Ch] [ebp-60h] BYREF
  _BYTE v8[12]; // [esp+28h] [ebp-54h] BYREF
  // [esp+34h] [ebp-48h]
  // [esp+38h] [ebp-44h]
  // [esp+3Ch] [ebp-40h]
  // [esp+40h] [ebp-3Ch]
  // [esp+44h] [ebp-38h]
  // [esp+48h] [ebp-34h]
  // [esp+4Ch] [ebp-30h]
  // [esp+50h] [ebp-2Ch]
  // [esp+54h] [ebp-28h]
  // [esp+58h] [ebp-24h]
  // [esp+5Ch] [ebp-20h]
  int requestedtype; // [esp+60h] [ebp-1Ch] BYREF
  // [esp+68h] [ebp-14h]
  // [esp+6Eh] [ebp-Eh]
  // [esp+6Fh] [ebp-Dh]
  // [esp+78h] [ebp-4h]

  int uRequestedType = a2 + (a3 << 16);
  if(m_vRefCounts.find(uRequestedType) != m_vRefCounts.end()) {
    BB_ASSERT(m_vLoadedChunks.find(uRequestedType) != m_vLoadedChunks.end())
    BB_ASSERT(m_vRefCounts[uRequestedType] >= 1)

    m_vRefCounts[uRequestedType]--;
    if(m_vRefCounts[uRequestedType] == 0) {
      delete[] m_vLoadedChunks[uRequestedType]; //TODO: UB... fun times
      m_vLoadedChunks.erase(uRequestedType);
      m_vRefCounts.erase(uRequestedType);
    }
  }
}


// address=[0x13db650]
// Decompiled from S4::CMapFile *__thiscall S4::CMapFile::UploadBuffer(  S4::CMapFile *this,  unsigned int a2,  int a3,  void *Src,  size_t Size,  int a6)
void S4::CMapFile::UploadBuffer(unsigned int a2, unsigned int a3, void const *_pBuffer, unsigned int _uSize, int a6) {
  unsigned int uRequestedType = a2 + (a3 << 16);

  void *pChunkDataBuffer = new char[_uSize];
  memcpy(pChunkDataBuffer, _pBuffer, _uSize);

  if(m_vRefCounts.find(uRequestedType) != m_vRefCounts.end()) {
    BB_ASSERT(m_vLoadedChunks.find(uRequestedType) != m_vLoadedChunks.end())

    delete []m_vLoadedChunks[uRequestedType]; // TODO: More UB! find way to make it not use void*! Probably just std::array
    m_vLoadedChunks[uRequestedType] = pChunkDataBuffer;

    m_vRefCounts[uRequestedType]++;
    if(a2 < 0x100u && !a3)
      *(_DWORD *) &this->m_uData[4 * a2] = a6;
    return;
  } else {
    m_vLoadedChunks.insert({uRequestedType, pChunkDataBuffer});
  }
}


// address=[0x13db820]
// Decompiled from int __thiscall S4::CMapFile::SaveChunk(  S4::CMapFile *this,  unsigned __int16 a2,  unsigned __int16 a3,  unsigned int Size,  const void *Src,  bool a6)
void S4::CMapFile::SaveChunk(unsigned short a2, unsigned short a3, unsigned int _uSize, void const *Src, bool a6) {
  unsigned int uCRC; // eax
  // [esp+10h] [ebp-34h]
  unsigned int uUncompressedSize; // [esp+14h] [ebp-30h]
  unsigned int uSize; // [esp+18h] [ebp-2Ch]
  char *       pCompressedOutputBuffer; // [esp+20h] [ebp-24h]
  // [esp+2Ch] [ebp-18h]
  // [esp+30h] [ebp-14h]
  // [esp+34h] [ebp-10h]
  // [esp+38h] [ebp-Ch]

  if(!Src) {
    _uSize = 0;
    Src = {}; // unk_369A12A
  }
  if(a6 | this->m_bCompress) {
    int uCompressedSize = LZHLCompressorCalcMaxBuf(_uSize) + 32;
    pCompressedOutputBuffer = new char[uCompressedSize];

    // [esp+14h] [ebp-14h]
    unsigned int uRemainingCompressSize; // [esp+18h] [ebp-10h]
    unsigned int uCompressedBufferSize = 0;
    char *       pCompressorIntBuffer = (char *) operator new[](_uSize + 256);
    memcpy(pCompressorIntBuffer, Src, _uSize);
    memset(&pCompressorIntBuffer[_uSize], 0, 0x100u);
    LZHLCompressor *pCompressor = LZHLCreateCompressor();
    for(size_t i = 0; i < _uSize; i += 4000000) {
      if(_uSize - i <= 0x3D0900)
        uRemainingCompressSize = _uSize - i;
      else
        uRemainingCompressSize = 4000000;
      uCompressedBufferSize += LZHLCompress(
        pCompressor,
        &pCompressedOutputBuffer[uCompressedBufferSize],
        &pCompressorIntBuffer[i],
        uRemainingCompressSize);
    }
    LZHLDestroyCompressor(pCompressor);
    operator delete[](pCompressorIntBuffer);
    uUncompressedSize = _uSize;
    uSize = uCompressedBufferSize;
    uCRC = S4::CMapFile::Crc(pCompressedOutputBuffer, uSize);
  } else {
    pCompressedOutputBuffer = (char *) operator new[](_uSize);
    memcpy(pCompressedOutputBuffer, Src, _uSize);
    uSize = _uSize;
    uUncompressedSize = -1;
    uCRC = S4::CMapFile::Crc(pCompressedOutputBuffer, _uSize);
  }

  SSaveFileChunk Buffer{};
  Buffer.m_uChunkTypeA = a2;
  Buffer.m_uChunkTypeB = a3;
  Buffer.m_uChunkSizeInFile = uSize;
  Buffer.m_uUncompressedSize = uUncompressedSize;
  Buffer.m_uChunkCRC = uCRC;
  Buffer.x = 0;
  S4::CMapFile::Cryption(&Buffer, sizeof(Buffer));
  this->m_cSaveFile.SetFilePos(0, 2);
  this->m_cSaveFile.Write(&Buffer, sizeof(Buffer));
  this->m_cSaveFile.Write(pCompressedOutputBuffer, uSize);
  return operator delete[](pCompressedOutputBuffer);
}


// address=[0x13db990]
// Decompiled from char __thiscall S4::CMapFile::LoadChunkObject(  S4::CMapFile *this,  unsigned __int16 a2,  unsigned __int16 a3,  void (__thiscall ***a4)(_DWORD, void **),  int a5)
bool S4::CMapFile::LoadChunkObject(unsigned short a2, unsigned short a3, IS4ChunkObject &a4, T_S4_MAP_CHUNK_STATUS a5) {
  // [esp+24h] [ebp-28h] BYREF

  // [esp+2Ch] [ebp-20h]
  // [esp+30h] [ebp-1Ch]
  // [esp+34h] [ebp-18h]
  int chunkSize; // [esp+38h] [ebp-14h] BYREF
  // [esp+3Fh] [ebp-Dh]
  // [esp+48h] [ebp-4h]

  CS4MemChunk v6{}; // [esp+4h] [ebp-48h] BYREF
  v6.m_pMapFile = this;
  int v7 = 0;
  chunkSize = 0;
  void const *chunkData = S4::CMapFile::LoadChunk(a2, a3, v7, &chunkSize);
  BOOL        v11 = chunkData != 0;
  BOOL        v10 = chunkSize > 0;
  if(v10 && v11) {
    v6.InitLoadData(chunkData, chunkSize);
    a4.Load(v6);
    return 1;
  } else {
    if(a5)
      return 0;
    throw new CS4InvalidMapException();
    return 0;
  }
}


// address=[0x13dbaa0]
// Decompiled from void __thiscall S4::CMapFile::SaveChunkObject(  S4::CMapFile *this,  unsigned __int16 a2,  unsigned __int16 a3,  struct IS4ChunkObject *a4,  bool a5)
void S4::CMapFile::SaveChunkObject(unsigned short a2, unsigned short a3, IS4ChunkObject &a4, bool a5) {
  CS4MemChunk v7{};
  v7.m_pMapFile = this;

  v7.InitSaveCalcSize();
  a4.Save(v7);
  v7.InitSaveData(1);
  a4.Save(v7);
  this->SaveChunk(a2, a3, v7.Size(), v7.Data(), a5);
}


// address=[0x13dbb60]
// Decompiled from int __thiscall S4::CMapFile::SaveDbgInfoChunk(S4::CMapFile *this, const char *a2)
void S4::CMapFile::SaveDbgInfoChunk(char const *a2) {
  // [esp+8h] [ebp-28h]
  _BYTE Src[32]; // [esp+Ch] [ebp-24h] BYREF

  memset(Src, 32, sizeof(Src));
  memset(Src, 33, 4);
  if(a2) {
    for(int i = 0; i < 20 && a2[i]; ++i)
      Src[i + 8] = a2[i];
  }
  S4::CMapFile::SaveChunk(0xFAu, 0, 0x20u, Src, 0);
}


// address=[0x13dbc20]
// Decompiled from void __thiscall S4::CMapFile::Cryption(S4::CMapFile *this, unsigned __int8 *a2, unsigned int a3)
void S4::CMapFile::Cryption(void *a2, unsigned int a3) {
  // [esp+14h] [ebp-7Ch]
  std::string v5; // [esp+64h] [ebp-2Ch] BYREF
  // [esp+8Ch] [ebp-4h]

  Cryptor v4{};

  v4.Set_Key("01234567890123456789");
  for(unsigned int i = 0; i < a3; ++i)
    v4.Transform_Char(static_cast<unsigned char *>(a2)[i]);
}


// address=[0x13dbd00]
// Decompiled from unsigned int __thiscall S4::CMapFile::Crc(S4::CMapFile *this, char *a2, int a3)
unsigned int S4::CMapFile::Crc(void *a2, unsigned int a3) {
  // [esp+8h] [ebp-8h]
  cdm_crc::CRCGenerator<16, 32773, 0, 0, 1, 1> v5{};
  v5.Process(static_cast<unsigned char *>(a2), a3);
  unsigned int NormalCRC = v5.GetNormalCRC();
  return NormalCRC >> (32 - v5.GetWidth());
}


// address=[0x13dbd60]
// Decompiled from unsigned int __thiscall S4::CMapFile::FileCRC(S4::CMapFile *this, int a2, int a3)
unsigned int S4::CMapFile::FileCRC(int a2, int a3) {
  unsigned int NormalCRC; // [esp+0h] [ebp-10h]

  char Buffer; // [esp+Fh] [ebp-1h] BYREF

  cdm_crc::CRCGenerator<16, 32773, 0, 0, 1, 1> v5{};
  while(a2 < a3) {
    this->m_cSaveFile.Read(&Buffer, 1u);
    ++a2;
    v5.Process(Buffer);
  }
  this->m_cSaveFile.SetFilePos(this->m_uFilePos, 0);
  NormalCRC = v5.GetNormalCRC();
  return NormalCRC >> (32 - v5.GetWidth());
}


