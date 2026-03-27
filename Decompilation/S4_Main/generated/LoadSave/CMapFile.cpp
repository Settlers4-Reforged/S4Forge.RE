#if FALSE
#include "CMapFile.h"

// Definitions for class CMapFile

// address=[0x13da7f0]
// Decompiled from struct CMapFile *__thiscall S4::CMapFile::CMapFile(S4::CMapFile *this, bool a2)
 S4::CMapFile::CMapFile(bool a2) {
  
  this->vftable = &S4::CMapFile::_vftable_;
  this->m_bVirtual = 0;
  this->m_b5 = 0;
  S4::CSaveFile::CSaveFile(&this->m_cSaveFile, a2);
  std::wstring::wstring(&this->m_swName);
  this->unk_74 = 0;
  this->m_iChecksum = 0;
  std::map<unsigned int,void *>::map<unsigned int,void *>(&this->m_vLoadedChunks);
  std::map<unsigned int,int>::map<unsigned int,int>(&this->m_vRefCounts);
  memset(this->m_uData, 0, sizeof(this->m_uData));
  this->m_bCompress = 0;
  return (struct CMapFile *)this;
}


// address=[0x13da8d0]
// Decompiled from void __thiscall S4::CMapFile::~CMapFile(S4::CMapFile *this)
 S4::CMapFile::~CMapFile(void) {
  
  this->vftable = &S4::CMapFile::_vftable_;
  if ( this->m_b5 )
    S4::CMapFile::Close(this);
  std::map<unsigned int,int>::~map<unsigned int,int>(&this->m_vRefCounts);
  std::map<unsigned int,void *>::~map<unsigned int,void *>(&this->m_vLoadedChunks);
  std::wstring::~wstring(&this->m_swName);
  S4::CSaveFile::~CSaveFile(&this->m_cSaveFile);
}


// address=[0x13da960]
// Decompiled from void __thiscall S4::CMapFile::Open(S4::CMapFile *this, std::wstring *a2, int a3, char a4)
void  S4::CMapFile::Open(std::wstring const & a2, int a3, bool a4) {
  
  int FileSize; // [esp+0h] [ebp-18h]
  int v5; // [esp+4h] [ebp-14h] BYREF
  unsigned int v6; // [esp+8h] [ebp-10h]
  int pExceptionObject; // [esp+Ch] [ebp-Ch] BYREF
  int Buffer; // [esp+10h] [ebp-8h] BYREF

  v6 = 0;
  if ( this->m_bVirtual && BBSupportDbgReport(2, "LoadSave\\CMapFile.cpp", 143, "! m_bVirtual") == 1 )
    __debugbreak();
  std::wstring::operator=(&this->m_swName, a2);
  this->unk_78 = a3;
  this->m_b5 = 1;
  if ( (a3 & 1) != 0 )
  {
    S4::CSaveFile::Open(&this->m_cSaveFile, a2, a3);
    this->unk_74 = S4::CSaveFile::GetFilePos(&this->m_cSaveFile);
    S4::CSaveFile::Read(&this->m_iChecksum, 4u);
    S4::CSaveFile::Read(&Buffer, 4u);
    if ( Buffer != 0x1F && Buffer != 0x28 )
    {
      S4::CSaveFile::Close(&this->m_cSaveFile);
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    FileSize = S4::CSaveFile::GetFileSize(&this->m_cSaveFile);
    S4::CSaveFile::SetFilePos(this->unk_74 + 8, 0);
    if ( a4 )
    {
      v6 = S4::CMapFile::FileCRC(this, this->unk_74 + 8, FileSize);
      if ( v6 != this->m_iChecksum )
      {
        S4::CSaveFile::Close(&this->m_cSaveFile);
        v5 = 0;
        CS4InvalidMapException::CS4InvalidMapException(&v5);
        _CxxThrowException(&v5, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
      }
    }
  }
  else if ( (a3 & 2) != 0 )
  {
    S4::CSaveFile::Open(&this->m_cSaveFile, a2, 3);
    Buffer = 31;
    this->unk_74 = S4::CSaveFile::GetFileSize(&this->m_cSaveFile);
    S4::CSaveFile::Write(&this->m_iChecksum, 4u);
    S4::CSaveFile::Write(&Buffer, 4u);
  }
}


// address=[0x13dab20]
// Decompiled from int __thiscall S4::CMapFile::Close(S4::CMapFile *this)
void  S4::CMapFile::Close(void) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-54h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-48h] BYREF
  _BYTE v4[12]; // [esp+1Ch] [ebp-3Ch] BYREF
  unsigned int Buffer; // [esp+28h] [ebp-30h] BYREF
  int FileSize; // [esp+2Ch] [ebp-2Ch]
  void *C; // [esp+30h] [ebp-28h]
  std::_Iterator_base12 *v8; // [esp+34h] [ebp-24h]
  std::_Iterator_base12 *v9; // [esp+38h] [ebp-20h]
  int v10; // [esp+3Ch] [ebp-1Ch]
  int v11; // [esp+40h] [ebp-18h]
  bool v13; // [esp+4Bh] [ebp-Dh]
  int v14; // [esp+54h] [ebp-4h]

  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v4);
  v14 = 0;
  v11 = std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::begin(
          &this->m_vLoadedChunks,
          (int)v3);
  v10 = v11;
  LOBYTE(v14) = 1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator=(v11);
  LOBYTE(v14) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v3);
  while ( 1 )
  {
    v9 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::end(
                                    &this->m_vLoadedChunks,
                                    (int)v2);
    v8 = v9;
    LOBYTE(v14) = 2;
    v13 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator!=(
            (std::_Iterator_base12 *)v4,
            v9);
    LOBYTE(v14) = 0;
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v2);
    if ( !v13 )
      break;
    C = *(void **)(std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator->(v4)
                 + 4);
    operator delete[](C);
    std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator++(v4);
  }
  std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::clear();
  std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::clear();
  if ( this->unk_78 == 2 )
  {
    FileSize = S4::CSaveFile::GetFileSize(&this->m_cSaveFile);
    S4::CSaveFile::SetFilePos(this->unk_74 + 8, 0);
    Buffer = S4::CMapFile::FileCRC(this, this->unk_74 + 8, FileSize);
    S4::CSaveFile::SetFilePos(this->unk_74, 0);
    S4::CSaveFile::Write(&Buffer, 4u);
  }
  S4::CSaveFile::Close(&this->m_cSaveFile);
  this->m_bVirtual = 0;
  this->m_iChecksum = 0;
  this->m_b5 = 0;
  memset(this->m_uData, 0, sizeof(this->m_uData));
  v14 = -1;
  return std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v4);
}


// address=[0x13dace0]
// Decompiled from void __thiscall S4::CMapFile::Virtualize(S4::CMapFile *this)
void  S4::CMapFile::Virtualize(void) {
  
  if ( this->m_bVirtual && BBSupportDbgReport(2, "LoadSave\\CMapFile.cpp", 243, "! m_bVirtual") == 1 )
    __debugbreak();
  this->m_bVirtual = 1;
}


// address=[0x13dad20]
// Decompiled from int __thiscall S4::CMapFile::GetChecksum(S4::CMapFile *this)
unsigned int  S4::CMapFile::GetChecksum(void)const {
  
  return this->m_iChecksum;
}


// address=[0x13dad40]
// Decompiled from void *__thiscall S4::CMapFile::LoadChunk(S4::CMapFile *this, unsigned __int16 a2, unsigned __int16 a3)
void const *  S4::CMapFile::LoadChunk(unsigned int a2, unsigned int a3) {
  
  int v4; // [esp+4h] [ebp-4h] BYREF

  v4 = 0;
  return S4::CMapFile::LoadChunk(this, a2, a3, &v4, 0);
}


// address=[0x13dad70]
// Decompiled from void *__thiscall S4::CMapFile::LoadChunk(  S4::CMapFile *this,  unsigned __int16 a2,  unsigned __int16 a3,  int *a4,  size_t *_uReadSize)
void const *  S4::CMapFile::LoadChunk(unsigned short a2, unsigned short a3, int & a4, int * _uReadSize) {
  
  void **v6; // eax
  std::_Iterator_base12 *v8; // [esp-4h] [ebp-11Ch]
  std::_Iterator_base12 *v9; // [esp-4h] [ebp-11Ch]
  _BYTE v10[12]; // [esp+4h] [ebp-114h] BYREF
  _BYTE v11[12]; // [esp+10h] [ebp-108h] BYREF
  _BYTE v12[12]; // [esp+1Ch] [ebp-FCh] BYREF
  _BYTE v13[12]; // [esp+28h] [ebp-F0h] BYREF
  _BYTE v14[12]; // [esp+34h] [ebp-E4h] BYREF
  _BYTE v15[12]; // [esp+40h] [ebp-D8h] BYREF
  void *v16; // [esp+4Ch] [ebp-CCh]
  void *v17; // [esp+50h] [ebp-C8h]
  void *v18; // [esp+54h] [ebp-C4h]
  char *v20; // [esp+5Ch] [ebp-BCh]
  char *v21; // [esp+60h] [ebp-B8h]
  std::_Iterator_base12 *itEnd; // [esp+64h] [ebp-B4h] MAPDST
  char *v23; // [esp+68h] [ebp-B0h]
  unsigned int uCalcCRC; // [esp+6Ch] [ebp-ACh]
  void *C; // [esp+70h] [ebp-A8h]
  int v26; // [esp+74h] [ebp-A4h]
  void *v27; // [esp+78h] [ebp-A0h]
  std::_Iterator_base12 *v28; // [esp+7Ch] [ebp-9Ch]
  std::_Iterator_base12 *v29; // [esp+80h] [ebp-98h]
  std::_Iterator_base12 *v30; // [esp+84h] [ebp-94h]
  std::_Iterator_base12 *v31; // [esp+88h] [ebp-90h]
  std::_Iterator_base12 *v32; // [esp+90h] [ebp-88h]
  std::_Iterator_base12 *v33; // [esp+94h] [ebp-84h]
  std::_Iterator_base12 *v34; // [esp+98h] [ebp-80h]
  std::_Iterator_base12 *v35; // [esp+9Ch] [ebp-7Ch]
  std::_Iterator_base12 *itFound; // [esp+A4h] [ebp-74h] MAPDST
  int v39; // [esp+ACh] [ebp-6Ch]
  int v40; // [esp+B0h] [ebp-68h] BYREF
  int m_uCompressedSize; // [esp+B4h] [ebp-64h] BYREF
  int pExceptionObject; // [esp+B8h] [ebp-60h] BYREF
  BOOL v43; // [esp+BCh] [ebp-5Ch]
  _DWORD *v44; // [esp+C0h] [ebp-58h]
  BOOL v45; // [esp+C4h] [ebp-54h]
  int m_uChunkSize; // [esp+C8h] [ebp-50h] BYREF
  int uChunkType; // [esp+CCh] [ebp-4Ch]
  int uReadSize; // [esp+D0h] [ebp-48h]
  void *v49; // [esp+D4h] [ebp-44h]
  size_t Size; // [esp+D8h] [ebp-40h]
  bool refFound; // [esp+DDh] [ebp-3Bh]
  bool v52; // [esp+DEh] [ebp-3Ah]
  bool v53; // [esp+DFh] [ebp-39h]
  int uRequestedType; // [esp+E0h] [ebp-38h] BYREF
  void *Src; // [esp+E4h] [ebp-34h]
  int v57; // [esp+ECh] [ebp-2Ch]
  SSaveFileChunk Buffer; // [esp+F0h] [ebp-28h] BYREF
  int exceptionBlock; // [esp+114h] [ebp-4h]

  v57 = 0;
  uRequestedType = a2 + (a3 << 16);
  itEnd = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::end(
                                     &this->m_vRefCounts,
                                     (int)v15);
  exceptionBlock = 0;
  itFound = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::find(
                                       &this->m_vRefCounts,
                                       (int)v10,
                                       (int)&uRequestedType);
  LOBYTE(exceptionBlock) = 1;
  refFound = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::operator!=(
               itFound,
               itEnd);
  LOBYTE(exceptionBlock) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>(v10);
  exceptionBlock = -1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>(v15);
  if ( refFound )
  {
    v35 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::end(
                                     &this->m_vLoadedChunks,
                                     (int)v13);
    v34 = v35;
    exceptionBlock = 2;
    v57 |= 1u;
    v8 = v35;
    v33 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::find(
                                     &this->m_vLoadedChunks,
                                     (int)v14,
                                     (int)&uRequestedType);
    v32 = v33;
    exceptionBlock = 3;
    v57 |= 2u;
    v45 = !std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator!=(
             v33,
             v8)
       && BBSupportDbgReport(
            2,
            "LoadSave\\CMapFile.cpp",
            269,
            "vLoadedChunks.find(uRequestedType) != vLoadedChunks.end()") == 1;
    v53 = v45;
    exceptionBlock = 2;
    if ( (v57 & 2) != 0 )
    {
      v57 &= ~2u;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v14);
    }
    exceptionBlock = -1;
    if ( (v57 & 1) != 0 )
    {
      v57 &= ~1u;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v13);
    }
    if ( v53 )
      __debugbreak();
    v44 = (_DWORD *)std::map<unsigned int,int>::operator[](&this->m_vRefCounts, (int)&uRequestedType);
    ++*v44;
    if ( a2 < 0x100u && !a3 )
      *a4 = *(_DWORD *)&this->m_uData[4 * a2];
    return *(void **)std::map<unsigned int,void *>::operator[]((int)&uRequestedType);
  }
  else
  {
    v49 = 0;
    if ( this->m_bVirtual )
      return v49;
    v31 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::end(
                                     &this->m_vLoadedChunks,
                                     (int)v11);
    v30 = v31;
    exceptionBlock = 4;
    v57 |= 4u;
    v9 = v31;
    v29 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::find(
                                     &this->m_vLoadedChunks,
                                     (int)v12,
                                     (int)&uRequestedType);
    v28 = v29;
    exceptionBlock = 5;
    v57 |= 8u;
    v43 = !std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator==(
             v29,
             v9)
       && BBSupportDbgReport(
            2,
            "LoadSave\\CMapFile.cpp",
            287,
            "vLoadedChunks.find(uRequestedType) == vLoadedChunks.end()") == 1;
    v52 = v43;
    exceptionBlock = 4;
    if ( (v57 & 8) != 0 )
    {
      v57 &= ~8u;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v12);
    }
    exceptionBlock = -1;
    if ( (v57 & 4) != 0 )
    {
      v57 &= ~4u;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v11);
    }
    if ( v52 )
      __debugbreak();
    Src = 0;
    uReadSize = 0;
    uChunkType = 0;
    S4::CSaveFile::SetFilePos(this->unk_74 + 8, 0);
    do
    {
      uReadSize = S4::CSaveFile::Read(&Buffer, 0x18u);
      S4::CMapFile::Cryption(this, (unsigned __int8 *)&Buffer, 0x18u);
      uChunkType = Buffer.m_uChunkTypeA + (Buffer.m_uChunkTypeB << 16);
      if ( uReadSize == 0x18 && uChunkType == uRequestedType )
      {
        v27 = operator new[](Buffer.m_uChunkSizeInFile);
        Src = v27;
        v26 = S4::CSaveFile::Read(v27, Buffer.m_uChunkSizeInFile);
        if ( v26 != Buffer.m_uChunkSizeInFile )
        {
          C = Src;
          operator delete[](Src);
          Src = 0;
        }
      }
      else if ( uReadSize == 0x18 )
      {
        S4::CSaveFile::SetFilePos(Buffer.m_uChunkSizeInFile, 1);
      }
    }
    while ( !S4::CSaveFile::Eof(&this->m_cSaveFile) && uReadSize == 24 && uChunkType != uRequestedType );
    if ( !Src )
      return 0;
    *a4 = Buffer.m_uSaveIdentifier;
    uCalcCRC = S4::CMapFile::Crc(this, (char *)Src, Buffer.m_uChunkSizeInFile);
    if ( uCalcCRC != Buffer.m_uChunkCRC )
    {
      BBSupportTracePrintF(3, "Invalid chunk CRC!");
      pExceptionObject = 0;
      CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    }
    Size = 0;
    if ( Buffer.m_uUncompressedSize == -1 )
    {
      Size = Buffer.m_uChunkSizeInFile;
      v18 = operator new[](Buffer.m_uChunkSizeInFile);
      v49 = v18;
      memcpy(v18, Src, Size);
    }
    else
    {
      Size = Buffer.m_uUncompressedSize;
      v23 = (char *)operator new[](Buffer.m_uUncompressedSize);
      v49 = v23;
      v16 = Src;
      m_uCompressedSize = Buffer.m_uUncompressedSize;
      m_uChunkSize = Buffer.m_uChunkSizeInFile;
      v20 = &v23[Buffer.m_uUncompressedSize];
      v21 = (char *)Src + Buffer.m_uChunkSizeInFile;
      v39 = j__LZHLCreateDecompressor();
      do
      {
        if ( !j__LZHLDecompress(v39, &v20[-m_uCompressedSize], &m_uCompressedSize, &v21[-m_uChunkSize], &m_uChunkSize) )
        {
          BBSupportTracePrintF(3, "Decompression of chunk failed!");
          v40 = 0;
          CS4InvalidMapException::CS4InvalidMapException(&v40);
          _CxxThrowException(&v40, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
        }
      }
      while ( m_uChunkSize );
      j__LZHLDestroyDecompressor(v39);
    }
    if ( _uReadSize )
      *_uReadSize = Size;
    if ( Src )
    {
      v17 = Src;
      operator delete[](Src);
      Src = 0;
    }
    v6 = (void **)std::map<unsigned int,void *>::operator[]((int)&uRequestedType);
    *v6 = v49;
    *(_DWORD *)std::map<unsigned int,int>::operator[](&this->m_vRefCounts, (int)&uRequestedType) = 1;
    return v49;
  }
}


// address=[0x13db3e0]
// Decompiled from void __thiscall S4::CMapFile::CloseChunk(S4::CMapFile *this, unsigned __int16 a2, unsigned __int16 a3)
void  S4::CMapFile::CloseChunk(unsigned short a2, unsigned short a3) {
  
  std::_Iterator_base12 *v3; // [esp-4h] [ebp-80h]
  std::_Iterator_base12 *v4; // [esp-4h] [ebp-80h]
  _BYTE v5[12]; // [esp+4h] [ebp-78h] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-6Ch] BYREF
  _BYTE v7[12]; // [esp+1Ch] [ebp-60h] BYREF
  _BYTE v8[12]; // [esp+28h] [ebp-54h] BYREF
  void *C; // [esp+34h] [ebp-48h]
  std::_Iterator_base12 *v10; // [esp+38h] [ebp-44h]
  std::_Iterator_base12 *v11; // [esp+3Ch] [ebp-40h]
  std::_Iterator_base12 *v12; // [esp+40h] [ebp-3Ch]
  std::_Iterator_base12 *v13; // [esp+44h] [ebp-38h]
  std::_Iterator_base12 *v14; // [esp+48h] [ebp-34h]
  std::_Iterator_base12 *v15; // [esp+4Ch] [ebp-30h]
  std::_Iterator_base12 *v16; // [esp+50h] [ebp-2Ch]
  std::_Iterator_base12 *v17; // [esp+54h] [ebp-28h]
  _DWORD *v18; // [esp+58h] [ebp-24h]
  BOOL v19; // [esp+5Ch] [ebp-20h]
  int requestedtype; // [esp+60h] [ebp-1Ch] BYREF
  int v22; // [esp+68h] [ebp-14h]
  bool v23; // [esp+6Eh] [ebp-Eh]
  bool v24; // [esp+6Fh] [ebp-Dh]
  int v25; // [esp+78h] [ebp-4h]

  v22 = 0;
  requestedtype = a2 + (a3 << 16);
  v17 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::end(
                                   &this->m_vRefCounts,
                                   (int)v7);
  v16 = v17;
  v25 = 0;
  v3 = v17;
  v15 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::find(
                                   &this->m_vRefCounts,
                                   (int)v8,
                                   (int)&requestedtype);
  v14 = v15;
  LOBYTE(v25) = 1;
  v24 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::operator!=(
          v15,
          v3);
  LOBYTE(v25) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>(v8);
  v25 = -1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>(v7);
  if ( v24 )
  {
    v13 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::end(
                                     &this->m_vLoadedChunks,
                                     (int)v5);
    v12 = v13;
    v25 = 2;
    v22 |= 1u;
    v4 = v13;
    v11 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::find(
                                     &this->m_vLoadedChunks,
                                     (int)v6,
                                     (int)&requestedtype);
    v10 = v11;
    v25 = 3;
    v22 |= 2u;
    v19 = !std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::operator!=(
             v11,
             v4)
       && BBSupportDbgReport(
            2,
            "LoadSave\\CMapFile.cpp",
            446,
            "vLoadedChunks.find(requestedtype) != vLoadedChunks.end()") == 1;
    v23 = v19;
    v25 = 2;
    if ( (v22 & 2) != 0 )
    {
      v22 &= ~2u;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v6);
    }
    v25 = -1;
    if ( (v22 & 1) != 0 )
    {
      v22 &= ~1u;
      std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>(v5);
    }
    if ( v23 )
      __debugbreak();
    if ( *(int *)std::map<unsigned int,int>::operator[](&this->m_vRefCounts, (int)&requestedtype) < 1
      && BBSupportDbgReport(2, "LoadSave\\CMapFile.cpp", 447, "vRefCounts [requestedtype] >= 1") == 1 )
    {
      __debugbreak();
    }
    v18 = (_DWORD *)std::map<unsigned int,int>::operator[](&this->m_vRefCounts, (int)&requestedtype);
    --*v18;
    if ( !*(_DWORD *)std::map<unsigned int,int>::operator[](&this->m_vRefCounts, (int)&requestedtype) )
    {
      C = *(void **)std::map<unsigned int,void *>::operator[](&requestedtype);
      operator delete[](C);
      std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::erase(&requestedtype);
      std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::erase(&requestedtype);
    }
  }
}


// address=[0x13db650]
// Decompiled from void __thiscall S4::CMapFile::UploadBuffer(S4::CMapFile *this, unsigned int a2, int a3, void *Src, size_t Size, int a6)
void  S4::CMapFile::UploadBuffer(unsigned int a2, unsigned int a3, void const * Src, unsigned int Size, int a6) {
  
  void *v6; // eax
  int v7; // eax
  int v8; // eax
  std::_Iterator_base12 *v9; // [esp-4h] [ebp-8Ch]
  _BYTE v10[16]; // [esp+4h] [ebp-84h] BYREF
  _BYTE v11[16]; // [esp+14h] [ebp-74h] BYREF
  _BYTE v12[12]; // [esp+24h] [ebp-64h] BYREF
  _BYTE v13[12]; // [esp+30h] [ebp-58h] BYREF
  int v14; // [esp+4Ch] [ebp-3Ch] BYREF
  void *C; // [esp+50h] [ebp-38h]
  std::_Iterator_base12 *v16; // [esp+54h] [ebp-34h]
  std::_Iterator_base12 *v17; // [esp+58h] [ebp-30h]
  std::_Iterator_base12 *v18; // [esp+5Ch] [ebp-2Ch]
  std::_Iterator_base12 *v19; // [esp+60h] [ebp-28h]
  void *v20; // [esp+64h] [ebp-24h]
  _DWORD *v21; // [esp+68h] [ebp-20h]
  void *v22; // [esp+6Ch] [ebp-1Ch] BYREF
  unsigned int v23; // [esp+70h] [ebp-18h] BYREF
  bool v25; // [esp+7Bh] [ebp-Dh]
  int v26; // [esp+84h] [ebp-4h]

  v23 = a2 + (a3 << 16);
  v20 = operator new[](Size);
  v22 = v20;
  memcpy(v20, Src, Size);
  v19 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::end(
                                   &this->m_vRefCounts,
                                   (int)v12);
  v18 = v19;
  v26 = 0;
  v9 = v19;
  v17 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::find(
                                   &this->m_vRefCounts,
                                   (int)v13,
                                   (int)&v23);
  v16 = v17;
  LOBYTE(v26) = 1;
  v25 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::operator!=(
          v17,
          v9);
  LOBYTE(v26) = 0;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>(v13);
  v26 = -1;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>(v12);
  if ( v25 )
  {
    C = *(void **)std::map<unsigned int,void *>::operator[]((int)&v23);
    operator delete[](C);
    v21 = (_DWORD *)std::map<unsigned int,int>::operator[](&this->m_vRefCounts, (int)&v23);
    ++*v21;
    v6 = (void *)std::map<unsigned int,void *>::operator[]((int)&v23);
    *(_DWORD *)v6 = v22;
    if ( a2 < 0x100 && !a3 )
      this->m_uData[a2] = a6;
  }
  else
  {
    v14 = 1;
    v7 = std::pair<unsigned int const,int>::pair<unsigned int const,int>((int)&v23, (int)&v14);
    std::_Tree<std::_Tmap_traits<unsigned int,int,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,int>>,0>>::insert<0,0>(
      (int)v11,
      v7);
    std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,int>>>>,bool>(v11);
    v8 = std::pair<unsigned int const,void *>::pair<unsigned int const,void *>((int)&v23, (int)&v22);
    std::_Tree<std::_Tmap_traits<unsigned int,void *,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,void *>>,0>>::insert<0,0>(
      &this->m_vLoadedChunks,
      (int)v10,
      v8);
    std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>,bool>::~pair<std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const,void *>>>>,bool>(v10);
  }
}


// address=[0x13db820]
// Decompiled from int __thiscall S4::CMapFile::SaveChunk(  S4::CMapFile *this,  unsigned __int16 a2,  unsigned __int16 a3,  unsigned int Size,  const void *Src,  bool a6)
void  S4::CMapFile::SaveChunk(unsigned short a2, unsigned short a3, unsigned int a4, void const * a5, bool a6) {
  
  unsigned int v6; // eax
  int v8; // [esp+10h] [ebp-34h]
  unsigned int v9; // [esp+14h] [ebp-30h]
  unsigned int ElementSize; // [esp+18h] [ebp-2Ch]
  char *v12; // [esp+20h] [ebp-24h]
  SSaveFileChunk Buffer; // [esp+28h] [ebp-1Ch] BYREF

  if ( !Src )
  {
    Size = 0;
    Src = &unk_369A12A;
  }
  if ( a6 | this->m_bCompress )
  {
    v8 = j__LZHLCompressorCalcMaxBuf(Size) + 32;
    v12 = (char *)operator new[](v8);
    ElementSize = sub_13DBDF0(v12, (void *)Src, Size);
    v9 = Size;
    v6 = S4::CMapFile::Crc(this, v12, ElementSize);
  }
  else
  {
    v12 = (char *)operator new[](Size);
    memcpy(v12, Src, Size);
    ElementSize = Size;
    v9 = -1;
    v6 = S4::CMapFile::Crc(this, v12, Size);
  }
  Buffer.m_uChunkTypeA = a2;
  Buffer.m_uChunkTypeB = a3;
  Buffer.m_uChunkSizeInFile = ElementSize;
  Buffer.m_uUncompressedSize = v9;
  Buffer.m_uChunkCRC = v6;
  Buffer.x = 0;
  S4::CMapFile::Cryption(this, (unsigned __int8 *)&Buffer, 0x18u);
  S4::CSaveFile::SetFilePos(0, 2);
  S4::CSaveFile::Write(&Buffer, 0x18u);
  S4::CSaveFile::Write(v12, ElementSize);
  return operator delete[](v12);
}


// address=[0x13db990]
// Decompiled from char __thiscall S4::CMapFile::LoadChunkObject(  S4::CMapFile *this,  unsigned __int16 a2,  unsigned __int16 a3,  struct IS4ChunkObject *a4,  int a5)
bool  S4::CMapFile::LoadChunkObject(unsigned short a2, unsigned short a3, class IS4ChunkObject & a4, enum T_S4_MAP_CHUNK_STATUS a5) {
  
  CS4MemChunk v6; // [esp+4h] [ebp-48h] BYREF
  int v7; // [esp+24h] [ebp-28h] BYREF
  int pExceptionObject; // [esp+28h] [ebp-24h] BYREF
  void *chunkData; // [esp+2Ch] [ebp-20h]
  BOOL v10; // [esp+30h] [ebp-1Ch]
  BOOL v11; // [esp+34h] [ebp-18h]
  int chunkSize; // [esp+38h] [ebp-14h] BYREF
  char v13; // [esp+3Fh] [ebp-Dh]
  int v14; // [esp+48h] [ebp-4h]

  v6.m_pMapFile = this;
  v7 = 0;
  chunkSize = 0;
  chunkData = S4::CMapFile::LoadChunk(this, a2, a3, &v7, (size_t *)&chunkSize);
  v11 = chunkData != 0;
  v10 = chunkSize > 0;
  if ( v10 && v11 )
  {
    CS4MemChunk::CS4MemChunk(&v6);
    v14 = 0;
    CS4MemChunk::InitLoadData(&v6, chunkData, chunkSize);
    a4->Load(a4, &v6);
    v13 = 1;
    v14 = -1;
    CS4MemChunk::~CS4MemChunk(&v6);
    return v13;
  }
  else
  {
    if ( a5 )
      return 0;
    pExceptionObject = 0;
    CS4InvalidMapException::CS4InvalidMapException(&pExceptionObject);
    _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVCS4InvalidMapException__);
    return 0;
  }
}


// address=[0x13dbaa0]
// Decompiled from void __thiscall S4::CMapFile::SaveChunkObject(  S4::CMapFile *this,  unsigned __int16 a2,  unsigned __int16 a3,  struct IS4ChunkObject *a4,  bool a5)
void  S4::CMapFile::SaveChunkObject(unsigned short a2, unsigned short a3, class IS4ChunkObject & a4, bool a5) {
  
  unsigned int iSize; // eax
  const void *pData; // [esp-Ch] [ebp-3Ch]
  CS4MemChunk v7; // [esp+4h] [ebp-2Ch] BYREF
  int v8; // [esp+2Ch] [ebp-4h]

  v7.m_pMapFile = this;
  CS4MemChunk::CS4MemChunk(&v7);
  v8 = 0;
  CS4MemChunk::InitSaveCalcSize(&v7);
  a4->Save(a4, &v7);
  CS4MemChunk::InitSaveData(&v7, 1);
  a4->Save(a4, &v7);
  pData = CS4MemChunk::Data(&v7);
  iSize = CS4MemChunk::Size(&v7);
  S4::CMapFile::SaveChunk(v7.m_pMapFile, a2, a3, iSize, pData, a5);
  v8 = -1;
  CS4MemChunk::~CS4MemChunk(&v7);
}


// address=[0x13dbb60]
// Decompiled from int __thiscall S4::CMapFile::SaveDbgInfoChunk(S4::CMapFile *this, const char *a2)
void  S4::CMapFile::SaveDbgInfoChunk(char const * a2) {
  
  int i; // [esp+8h] [ebp-28h]
  _BYTE Src[32]; // [esp+Ch] [ebp-24h] BYREF

  memset(Src, 32, sizeof(Src));
  memset(Src, 33, 4);
  if ( a2 )
  {
    for ( i = 0; i < 20 && a2[i]; ++i )
      Src[i + 8] = a2[i];
  }
  return S4::CMapFile::SaveChunk(this, 0xFAu, 0, 0x20u, Src, 0);
}


// address=[0x13dbc20]
// Decompiled from void __thiscall S4::CMapFile::Cryption(S4::CMapFile *this, void *a2, unsigned int a3)
void  S4::CMapFile::Cryption(void * a2, unsigned int a3) {
  
  unsigned int i; // [esp+14h] [ebp-7Ch]
  _DWORD v4[19]; // [esp+18h] [ebp-78h] BYREF
  std::string v5; // [esp+64h] [ebp-2Ch] BYREF
  int v6; // [esp+8Ch] [ebp-4h]

  Cryptor::Cryptor((Cryptor *)v4);
  v6 = 0;
  std::string::string(&v5, "01234567890123456789");
  LOBYTE(v6) = 1;
  Cryptor::Set_Key(v4, (int)&v5);
  for ( i = 0; i < a3; ++i )
    Cryptor::Transform_Char((Cryptor *)v4, (unsigned __int8 *)a2 + i);
  LOBYTE(v6) = 0;
  std::string::~string(&v5);
  v6 = -1;
  Cryptor::~Cryptor((Cryptor *)v4);
}


// address=[0x13dbd00]
// Decompiled from unsigned int __thiscall S4::CMapFile::Crc(S4::CMapFile *this, char *a2, int a3)
unsigned int  S4::CMapFile::Crc(void * a2, unsigned int a3) {
  
  unsigned int NormalCRC; // [esp+8h] [ebp-8h]
  int v5; // [esp+Ch] [ebp-4h] BYREF

  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCGenerator<16,32773,0,0,1,1>(&v5);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process(&v5, a2, a3);
  NormalCRC = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetNormalCRC(&v5);
  return NormalCRC >> (32 - cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetWidth(&v5));
}


// address=[0x13dbd60]
// Decompiled from unsigned int __thiscall S4::CMapFile::FileCRC(S4::CMapFile *this, int a2, int a3)
unsigned int  S4::CMapFile::FileCRC(int a2, int a3) {
  
  unsigned int NormalCRC; // [esp+0h] [ebp-10h]
  int v5; // [esp+4h] [ebp-Ch] BYREF
  char Buffer; // [esp+Fh] [ebp-1h] BYREF

  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCGenerator<16,32773,0,0,1,1>(&v5);
  while ( a2 < a3 )
  {
    S4::CSaveFile::Read(&Buffer, 1u);
    ++a2;
    cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process(&v5, Buffer);
  }
  S4::CSaveFile::SetFilePos(this->unk_74, 0);
  NormalCRC = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetNormalCRC(&v5);
  return NormalCRC >> (32 - cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetWidth(&v5));
}


#endif // Already implemented
