#if FALSE
#include "CFileLibrary.h"

// Definitions for class CFileLibrary

// address=[0x2f099d0]
// Decompiled from int __thiscall CFileLibrary::FileSize(CFileLibrary *this, wchar_t *String)
unsigned int  CFileLibrary::FileSize(wchar_t const * String) {
  
  struct FLMemDirStruct *a2; // [esp+0h] [ebp-420h]
  FLMemFileStruct *File; // [esp+8h] [ebp-418h]
  wchar_t String1[260]; // [esp+Ch] [ebp-414h] BYREF
  wchar_t Destination[260]; // [esp+214h] [ebp-20Ch] BYREF

  if ( CFileLibrary::pCutPathAndFilename(String, Destination, String1) )
  {
    File = 0;
    a2 = CFileLibrary::pFindDirectory(this, Destination);
    if ( a2 )
      File = CFileLibrary::pFindFile(String1, a2);
    if ( File && File->m_iLibraryIndex != -4 )
    {
      if ( (File->m_iFlags & 1) != 0 )
        return File->m_iDecompressedSize;
      else
        return File->m_iFileSize;
    }
    else
    {
      BBSupportTracePrintF(3, "CFileLibrary::FileSize\t:\tFailed to get find file %s ", (const char *)String);
      return -1;
    }
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::FileSize\t:\tFailed to get file handle, %s ", (const char *)String);
    return -1;
  }
}


// address=[0x2f09ae0]
// Decompiled from int __thiscall CFileLibrary::FileSize(CFileLibrary *this, unsigned int a2)
unsigned int  CFileLibrary::FileSize(unsigned int a2) {
  
  FLIntHandleStruct *IntHandlePtr; // [esp+4h] [ebp-4h]

  IntHandlePtr = CFileLibrary::pGetIntHandlePtr(this, a2);
  if ( IntHandlePtr )
  {
    if ( (IntHandlePtr->m_pLibraryFile->m_iFlags & FLFF_Compressed) != 0 )
      return IntHandlePtr->m_pLibraryFile->m_iDecompressedSize;
    else
      return IntHandlePtr->m_pLibraryFile->m_iFileSize;
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::FileSize\t:\tFailed to get file handle");
    return -1;
  }
}


// address=[0x2f09b40]
// Decompiled from void __thiscall CFileLibrary::UnmapFile(CFileLibrary *this, void *a2)
void  CFileLibrary::UnmapFile(void * a2) {
  
  char *m_pFileData; // [esp+8h] [ebp-Ch]
  int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < this->m_iLibraryFilesCount; ++i )
  {
    m_pFileData = (char *)this->m_pLibraryFiles[i].m_pFileData;
    if ( a2 >= m_pFileData
      && a2 < &m_pFileData[this->m_pLibraryFiles[i].m_uFileSize]
      && !--this->m_pLibraryFiles[i].m_bFileMapped )
    {
      UnmapViewOfFile(this->m_pLibraryFiles[i].m_pFileData);
      this->m_pLibraryFiles[i].m_pFileData = 0;
      CloseHandle(this->m_pLibraryFiles[i].m_hFileMap);
      this->m_pLibraryFiles[i].m_hFileMap = 0;
      return;
    }
  }
}


// address=[0x2f09c70]
// Decompiled from bool __thiscall CFileLibrary::DoesFileExistInLib(CFileLibrary *this, wchar_t *String)
bool  CFileLibrary::DoesFileExistInLib(wchar_t const * String) {
  
  struct FLMemDirStruct *a2; // [esp+0h] [ebp-420h]
  FLMemFileStruct *File; // [esp+4h] [ebp-41Ch]
  wchar_t String1[260]; // [esp+Ch] [ebp-414h] BYREF
  wchar_t Destination[260]; // [esp+214h] [ebp-20Ch] BYREF

  if ( !CFileLibrary::pCutPathAndFilename(String, Destination, String1) )
    return 0;
  File = 0;
  a2 = CFileLibrary::pFindDirectory(this, Destination);
  if ( a2 )
    File = CFileLibrary::pFindFile(String1, a2);
  return File && File->m_iLibraryIndex != 0xFFFFFFFC;
}


// address=[0x2f09d30]
// Decompiled from void *__thiscall CFileLibrary::MapFile(CFileLibrary *this, unsigned int a2)
void *  CFileLibrary::MapFile(unsigned int a2) {
  
  DWORD LastError; // eax
  DWORD v4; // eax
  HANDLE hFile; // [esp+0h] [ebp-14h]
  HANDLE hFileMappingObject; // [esp+4h] [ebp-10h]
  BYTE *pFileData; // [esp+8h] [ebp-Ch]
  FLIntHandleStruct *IntHandlePtr; // [esp+Ch] [ebp-8h]

  IntHandlePtr = CFileLibrary::pGetIntHandlePtr(this, a2);
  if ( !IntHandlePtr )
    return 0;
  if ( this->m_pLibraryFiles[IntHandlePtr->m_pLibraryFile->m_iLibraryIndex].m_hFileMap )
  {
    ++this->m_pLibraryFiles[IntHandlePtr->m_pLibraryFile->m_iLibraryIndex].m_bFileMapped;
    return (char *)this->m_pLibraryFiles[IntHandlePtr->m_pLibraryFile->m_iLibraryIndex].m_pFileData
         + IntHandlePtr->m_pLibraryFile->m_iFileOffset;
  }
  else
  {
    hFile = (HANDLE)CFileLibrary::pGetFileLibraryHandle(this, IntHandlePtr->m_pLibraryFile->m_iLibraryIndex);
    hFileMappingObject = CreateFileMappingA(hFile, 0, 2u, 0, 0, 0);
    if ( hFileMappingObject == (HANDLE)-1 )
    {
      LastError = GetLastError();
      printf("Unable map file . LastError was: %d", LastError);
      CFileLibrary::FileClose(this, a2);
      return 0;
    }
    else
    {
      pFileData = (BYTE *)MapViewOfFile(hFileMappingObject, 4u, 0, 0, 0);
      if ( pFileData )
      {
        this->m_pLibraryFiles[IntHandlePtr->m_pLibraryFile->m_iLibraryIndex].m_pFileData = pFileData;
        this->m_pLibraryFiles[IntHandlePtr->m_pLibraryFile->m_iLibraryIndex].m_hFileMap = hFileMappingObject;
        this->m_pLibraryFiles[IntHandlePtr->m_pLibraryFile->m_iLibraryIndex].m_bFileMapped = 1;
        return &pFileData[IntHandlePtr->m_pLibraryFile->m_iFileOffset];
      }
      else
      {
        v4 = GetLastError();
        printf("Unable map view of file . LastError was: %d", v4);
        CloseHandle(hFileMappingObject);
        CFileLibrary::FileClose(this, a2);
        return 0;
      }
    }
  }
}


// address=[0x2f09ef0]
// Decompiled from unsigned int __thiscall CFileLibrary::FileOpen(CFileLibrary *this, wchar_t *_swpName, int Size)
unsigned int  CFileLibrary::FileOpen(wchar_t const * _swpName, int Size) {
  
  FLIntHandleStruct *pHandle; // [esp+10h] [ebp-44Ch] MAPDST
  FLIntHandleStruct *v5; // [esp+14h] [ebp-448h]
  FLIntHandleStruct *C; // [esp+20h] [ebp-43Ch]
  int bFoundHandle; // [esp+24h] [ebp-438h]
  struct FLMemDirStruct *a2; // [esp+28h] [ebp-434h]
  FLMemFileStruct *File; // [esp+2Ch] [ebp-430h]
  unsigned int v11; // [esp+30h] [ebp-42Ch]
  FLIntHandleStruct *i; // [esp+38h] [ebp-424h]
  FLIntHandleStruct *pHandlesEnd; // [esp+38h] [ebp-424h]
  wchar_t swpFileName[260]; // [esp+3Ch] [ebp-420h] BYREF
  wchar_t swpPath[260]; // [esp+244h] [ebp-218h] BYREF
  int exceptionBlock; // [esp+458h] [ebp-4h]

  if ( !CFileLibrary::pCutPathAndFilename(_swpName, swpPath, swpFileName) )
    return -1;
  File = 0;
  a2 = CFileLibrary::pFindDirectory(this, swpPath);
  if ( a2 )
    File = CFileLibrary::pFindFile(swpFileName, a2);
  if ( !File || File->m_iLibraryIndex == 0xFFFFFFFC )
    return -1;
  ++this->m_iRefCount;
  bFoundHandle = 0;
  do
  {
    v11 = this->m_uHandleCount;
    this->m_uHandleCount = v11 + 1;
    if ( v11 == -1 )
    {
      v11 = this->m_uHandleCount;
      this->m_uHandleCount = v11 + 1;
    }
    for ( i = this->m_pFLIntHandle[v11 % 0x64]; i && i->m_iLibraryIndex != v11; i = i->m_pNextHandle )
    {
      if ( !i->m_pNextHandle )
      {
        bFoundHandle = 1;
        break;
      }
    }
  }
  while ( !bFoundHandle && i );
  if ( i )
  {
    v5 = (FLIntHandleStruct *)operator new(0x1Cu);
    exceptionBlock = 1;
    if ( v5 )
      pHandle = FLIntHandleStruct::FLIntHandleStruct(v5);
    else
      pHandle = 0;
    exceptionBlock = -1;
    i->m_pNextHandle = pHandle;
    pHandlesEnd = i->m_pNextHandle;
  }
  else
  {
    C = (FLIntHandleStruct *)operator new(0x1Cu);
    exceptionBlock = 0;
    if ( C )
      pHandle = FLIntHandleStruct::FLIntHandleStruct(C);
    else
      pHandle = 0;
    exceptionBlock = -1;
    pHandlesEnd = pHandle;
    this->m_pFLIntHandle[v11 % 0x64] = pHandle;
  }
  if ( Size > 0 )
  {
    pHandlesEnd->m_pData = (int)operator new[](Size);
    pHandlesEnd->m_iDataSize = Size;
  }
  else
  {
    pHandlesEnd->m_iDataSize = 0;
  }
  pHandlesEnd->m_pLibraryFile = File;
  pHandlesEnd->m_iLibraryIndex = v11;
  return v11;
}


// address=[0x2f0a220]
// Decompiled from void __thiscall CFileLibrary::FileClose(CFileLibrary *this, unsigned int _iId)
void  CFileLibrary::FileClose(unsigned int _iId) {
  
  FLIntHandleStruct *i; // [esp+18h] [ebp-4h] MAPDST

  ++this->m_iFileInteractions;
  i = this->m_pFLIntHandle[_iId % 0x64];
  if ( i )
  {
    for ( i = 0; i; i = i->m_pNextHandle )
    {
      if ( i->m_iLibraryIndex == _iId )
      {
        if ( i )
          i->m_pNextHandle = i->m_pNextHandle;
        else
          this->m_pFLIntHandle[_iId % 0x64] = i->m_pNextHandle;
        delete i;
        return;
      }
    }
  }
}


// address=[0x2f0a2e0]
// Decompiled from int __thiscall CFileLibrary::FileSeek(CFileLibrary *this, unsigned int _iLibraryIndex, int _iOffset, int _iSeekStart)
unsigned int  CFileLibrary::FileSeek(unsigned int _iLibraryIndex, long _iOffset, int _iSeekStart) {
  
  int iTotalSize; // [esp+10h] [ebp-Ch]
  int filePosition; // [esp+14h] [ebp-8h]
  FLIntHandleStruct *pHandle; // [esp+18h] [ebp-4h]

  ++this->m_iFileSeeks;
  pHandle = this->m_pFLIntHandle[_iLibraryIndex % 0x64];
  if ( pHandle )
  {
    while ( 1 )
    {
      if ( !pHandle )
      {
        BBSupportTracePrintF(3, "CFileLibrary::FileSeek\t:\tFailed to seek in %s", *MEMORY[0x14]);// Hm.. is handle->m_pLibraryFile->m_pswName
        return -1;
      }
      if ( pHandle->m_iLibraryIndex == _iLibraryIndex )
        break;
      pHandle = pHandle->m_pNextHandle;
    }
    filePosition = pHandle->m_iSeekPosition;
    if ( (pHandle->m_pLibraryFile->m_iFlags & FLFF_Compressed) != 0 )
      iTotalSize = pHandle->m_pLibraryFile->m_iDecompressedSize;
    else
      iTotalSize = pHandle->m_pLibraryFile->m_iFileSize;
    if ( _iSeekStart )
    {
      if ( _iSeekStart == 1 )                   // From beginning
      {
        filePosition += _iOffset;
      }
      else if ( _iSeekStart == 2 )              // From end and then negative offset
      {
        filePosition = _iOffset + iTotalSize;
      }
    }
    else
    {
      filePosition = _iOffset;
    }
    if ( filePosition < 0 )
      filePosition = 0;
    if ( filePosition > iTotalSize )
      filePosition = iTotalSize;
    pHandle->m_iSeekPosition = filePosition;
    return filePosition;
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::FileSeek\t:\tFailed to get file handle");
    return -1;
  }
}


// address=[0x2f0a420]
// Decompiled from size_t __thiscall CFileLibrary::FileRead(CFileLibrary *this, unsigned int a2, char *_pData, size_t Size)
unsigned int  CFileLibrary::FileRead(unsigned int a2, void * _pData, unsigned int Size) {
  
  DWORD v5; // [esp+4h] [ebp-48h] BYREF
  LONG lDistanceToMove; // [esp+8h] [ebp-44h]
  unsigned int v7; // [esp+Ch] [ebp-40h]
  BYTE *v8; // [esp+10h] [ebp-3Ch]
  size_t m_iDecompressedSize; // [esp+14h] [ebp-38h]
  signed int v11; // [esp+1Ch] [ebp-30h]
  int v12; // [esp+20h] [ebp-2Ch]
  DWORD NumberOfBytesRead; // [esp+24h] [ebp-28h] BYREF
  DWORD v14; // [esp+28h] [ebp-24h]
  size_t v15; // [esp+2Ch] [ebp-20h]
  unsigned int v16; // [esp+30h] [ebp-1Ch]
  DWORD v17; // [esp+34h] [ebp-18h] BYREF
  HANDLE hFile; // [esp+3Ch] [ebp-10h]
  int v20; // [esp+40h] [ebp-Ch]
  DWORD nNumberOfBytesToRead; // [esp+44h] [ebp-8h]
  FLIntHandleStruct *IntHandlePtr; // [esp+48h] [ebp-4h]

  ++this->field_C;
  this->m_iDecompressedBytesRead += Size;
  IntHandlePtr = CFileLibrary::pGetIntHandlePtr(this, a2);
  if ( !IntHandlePtr )
    return -1;
  hFile = CFileLibrary::pGetFileLibraryHandle(this, IntHandlePtr->m_pLibraryFile->m_iLibraryIndex);
  if ( hFile == (HANDLE)-1 )
  {
    BBSupportTracePrintF(3, "CFileLibrary::FileRead\t:\tfailed to get lib handle");
    return -1;
  }
  if ( (IntHandlePtr->m_pLibraryFile->m_iFlags & FLFF_Compressed) != 0 )
  {
    nNumberOfBytesToRead = IntHandlePtr->m_pLibraryFile->m_iDecompressedSize - IntHandlePtr->m_iSeekPosition;
    if ( nNumberOfBytesToRead )
    {
      if ( nNumberOfBytesToRead >= Size )
      {
        if ( IntHandlePtr->m_pLibraryFile->m_pFileData
          || (m_iDecompressedSize = IntHandlePtr->m_pLibraryFile->m_iDecompressedSize,
              v8 = (BYTE *)operator new[](m_iDecompressedSize),
              IntHandlePtr->m_pLibraryFile->m_pFileData = v8,
              CFileLibrary::LoadEntireFile(
                this,
                a2,
                (char *)IntHandlePtr->m_pLibraryFile->m_pFileData,
                IntHandlePtr->m_pLibraryFile->m_iCRC,
                0) != -1) )
        {
          memcpy(_pData, &IntHandlePtr->m_pLibraryFile->m_pFileData[IntHandlePtr->m_iSeekPosition], Size);
          IntHandlePtr->m_iSeekPosition += Size;
          return Size;
        }
        else
        {
          BBSupportTracePrintF(
            3,
            "CFileLibrary::FileRead\t:\tUnable to load entire file %s ",
            IntHandlePtr->m_pLibraryFile->m_pswName);
          return -1;
        }
      }
      else
      {
        BBSupportTracePrintF(3, "CFileLibrary::FileRead\t:\tnot enough data");
        return -1;
      }
    }
    else
    {
      BBSupportTracePrintF(3, "CFileLibrary::FileRead\t:\tEOF");
      return -2;
    }
  }
  else
  {
    nNumberOfBytesToRead = IntHandlePtr->m_pLibraryFile->m_iFileSize - IntHandlePtr->m_iSeekPosition;
    if ( nNumberOfBytesToRead > Size )
      nNumberOfBytesToRead = Size;
    if ( !nNumberOfBytesToRead )
      return -2;
    if ( IntHandlePtr->m_iDataSize )
    {
      v20 = 0;
      v16 = IntHandlePtr->m_iSeekPosition / (unsigned int)IntHandlePtr->m_iDataSize;
      v7 = IntHandlePtr->m_iSeekPosition % (unsigned int)IntHandlePtr->m_iDataSize;
      if ( v16 != IntHandlePtr->field_8 && v7 )
      {
        lDistanceToMove = IntHandlePtr->m_pLibraryFile->m_iFileOffset + v16 * IntHandlePtr->m_iDataSize;
        v14 = SetFilePointer(hFile, lDistanceToMove, 0, FILE_BEGIN);
        if ( v14 == -1 )
        {
          BBSupportTracePrintF(
            3,
            "CFileLibrary::FileRead\t:\tfailed set file pointer on FILE_BEGIN, %s ",
            IntHandlePtr->m_pLibraryFile->m_pswName);
          return -1;
        }
        ReadFile(hFile, (LPVOID)IntHandlePtr->m_pData, IntHandlePtr->m_iDataSize, &v5, 0);
        if ( v5 != IntHandlePtr->m_iDataSize )
        {
          BBSupportTracePrintF(
            3,
            "CFileLibrary::FileRead\t:\tfailed to read file%s ",
            IntHandlePtr->m_pLibraryFile->m_pswName);
          return -1;
        }
        IntHandlePtr->field_8 = v16;
      }
      if ( v16 == IntHandlePtr->field_8 )
      {
        v12 = IntHandlePtr->m_iSeekPosition - v16 * IntHandlePtr->m_iDataSize;
        v15 = IntHandlePtr->m_iDataSize - v12;
        if ( v15 >= nNumberOfBytesToRead )
        {
          memmove(_pData, (const void *)(v12 + IntHandlePtr->m_pData), nNumberOfBytesToRead);
          IntHandlePtr->m_iSeekPosition += nNumberOfBytesToRead;
          return nNumberOfBytesToRead;
        }
        if ( (int)v15 > 0 )
        {
          memmove(_pData, (const void *)(v12 + IntHandlePtr->m_pData), v15);
          v20 += v15;
          nNumberOfBytesToRead -= v15;
        }
      }
      v11 = nNumberOfBytesToRead / IntHandlePtr->m_iDataSize;
      v14 = SetFilePointer(
              hFile,
              IntHandlePtr->m_pLibraryFile->m_iFileOffset + v20 + IntHandlePtr->m_iSeekPosition,
              0,
              FILE_BEGIN);
      if ( v14 == -1 )
      {
        BBSupportTracePrintF(
          3,
          "CFileLibrary::FileRead\t:\tfailed set file pointer on FILE_BEGIN, %s ",
          IntHandlePtr->m_pLibraryFile->m_pswName);
        return -1;
      }
      if ( v11 > 0 )
      {
        ReadFile(hFile, &_pData[v20], v11 * IntHandlePtr->m_iDataSize, &v17, 0);
        if ( v17 != v11 * IntHandlePtr->m_iDataSize )
          return -1;
        nNumberOfBytesToRead -= v17;
        v20 += v17;
      }
      v16 = (v20 + IntHandlePtr->m_iSeekPosition) / (unsigned int)IntHandlePtr->m_iDataSize;
      ReadFile(hFile, (LPVOID)IntHandlePtr->m_pData, IntHandlePtr->m_iDataSize, &v17, 0);
      if ( v17 == IntHandlePtr->m_iDataSize )
      {
        ReadFile(hFile, (LPVOID)IntHandlePtr->m_pData, IntHandlePtr->m_iDataSize, &v17, 0);
        if ( v17 == IntHandlePtr->m_iDataSize )
        {
          memmove(&_pData[v20], (const void *)IntHandlePtr->m_pData, nNumberOfBytesToRead);
          v20 += nNumberOfBytesToRead;
          IntHandlePtr->field_8 = v16;
          IntHandlePtr->m_iSeekPosition += v20;
          return v20;
        }
        else
        {
          BBSupportTracePrintF(
            3,
            "CFileLibrary::FileRead\t:\tfailed to read file%s ",
            IntHandlePtr->m_pLibraryFile->m_pswName);
          return -1;
        }
      }
      else
      {
        BBSupportTracePrintF(
          3,
          "CFileLibrary::FileRead\t:\tfailed to read file%s ",
          IntHandlePtr->m_pLibraryFile->m_pswName);
        return -1;
      }
    }
    else
    {
      v14 = SetFilePointer(
              hFile,
              IntHandlePtr->m_iSeekPosition + IntHandlePtr->m_pLibraryFile->m_iFileOffset,
              0,
              FILE_BEGIN);
      if ( v14 == -1 )
      {
        BBSupportTracePrintF(
          3,
          "CFileLibrary::FileRead\t:\tfailed set file pointer on FILE_BEGIN, %s ",
          IntHandlePtr->m_pLibraryFile->m_pswName);
        return -1;
      }
      else
      {
        ReadFile(hFile, _pData, nNumberOfBytesToRead, &NumberOfBytesRead, 0);
        if ( nNumberOfBytesToRead == NumberOfBytesRead )
        {
          IntHandlePtr->m_iSeekPosition += NumberOfBytesRead;
          return NumberOfBytesRead;
        }
        else
        {
          BBSupportTracePrintF(
            3,
            "CFileLibrary::FileRead\t:\tfailed to read file%s ",
            IntHandlePtr->m_pLibraryFile->m_pswName);
          return -1;
        }
      }
    }
  }
}


// address=[0x2f0a9d0]
// Decompiled from int __thiscall CFileLibrary::AddFileLibrary(CFileLibrary *this, LPCWSTR sFileName, int a3)
int  CFileLibrary::AddFileLibrary(wchar_t const * sFileName, int a3) {
  
  size_t iFileNameLength; // eax
  wchar_t *v5; // eax
  wchar_t *v6; // eax
  wchar_t *v7; // eax
  int v8; // eax
  __int16 v11; // [esp-8h] [ebp-290h]
  __int16 v12; // [esp-8h] [ebp-290h]
  int v14; // [esp-4h] [ebp-28Ch]
  char v15[8]; // [esp+8h] [ebp-280h] BYREF
  wchar_t *v16; // [esp+10h] [ebp-278h]
  wchar_t *swFileName; // [esp+24h] [ebp-264h]
  int v22; // [esp+28h] [ebp-260h]
  LONG Buffer; // [esp+44h] [ebp-244h] BYREF
  wchar_t *String; // [esp+48h] [ebp-240h]
  wchar_t *v31; // [esp+4Ch] [ebp-23Ch]
  const char *pswFileNames; // [esp+50h] [ebp-238h] MAPDST
  const char *pswDirectoryNames; // [esp+54h] [ebp-234h] MAPDST
  unsigned int iHeaderCount; // [esp+7Ch] [ebp-20Ch]
  FLLibraryFileStruct *v45; // [esp+84h] [ebp-204h]
  unsigned int v47; // [esp+8Ch] [ebp-1FCh]
  FLHeaderStruct sHeader; // [esp+90h] [ebp-1F8h] BYREF
  FLHeaderFileStruct *pFileHeaders; // [esp+A8h] [ebp-1E0h] MAPDST
  DWORD hError; // [esp+ACh] [ebp-1DCh]
  FLLibraryFileStruct *pFLLibraryFileList; // [esp+B4h] [ebp-1D4h] MAPDST
  DWORD v54; // [esp+BCh] [ebp-1CCh] BYREF
  struct FLMemDirStruct *pDir; // [esp+C4h] [ebp-1C4h]
  int j; // [esp+C8h] [ebp-1C0h]
  LPVOID pFileNames; // [esp+D0h] [ebp-1B8h] MAPDST
  LPVOID pDirectoryNames; // [esp+D4h] [ebp-1B4h] MAPDST
  DWORD NumberOfBytesRead; // [esp+E0h] [ebp-1A8h] BYREF
  DWORD nNumberOfBytesToRead; // [esp+E4h] [ebp-1A4h]
  BOOL bSucceeded; // [esp+E8h] [ebp-1A0h]
  _BYTE *pCopyBuffer; // [esp+ECh] [ebp-19Ch]
  HANDLE hFile; // [esp+F0h] [ebp-198h]
  int i; // [esp+F4h] [ebp-194h]
  char v70[88]; // [esp+FCh] [ebp-18Ch] BYREF
  char v71[88]; // [esp+154h] [ebp-134h] BYREF
  char v72[88]; // [esp+1ACh] [ebp-DCh] BYREF
  int v73[8]; // [esp+204h] [ebp-84h] BYREF
  int v74[7]; // [esp+224h] [ebp-64h] BYREF
  int v75[7]; // [esp+240h] [ebp-48h] BYREF
  int v76[7]; // [esp+25Ch] [ebp-2Ch] BYREF
  int exceptionBlock; // [esp+284h] [ebp-4h]

  hFile = CreateFileW(sFileName, 0x80000000, 1u, 0, 3u, 0x80u, 0);
  if ( hFile == (HANDLE)-1 )
  {
    BBSupportTracePrintF(3, "CFileLibrary::AddFileLibrary\t:\tFailed to add %s to library.", (const char *)sFileName);
    return 6;
  }
  else
  {
    if ( this->m_iLibraryFilesCount == this->m_iLibraryFilesCapacity )
    {
      v47 = this->m_iLibraryFilesCapacity + 8;
      pFLLibraryFileList = (FLLibraryFileStruct *)operator new[](0x18 * v47);
      exceptionBlock = 0;
      if ( pFLLibraryFileList )
        _vec_ctor_no(
          pFLLibraryFileList,
          0x18u,
          v47,
          (void *(__thiscall *)(void *))FLLibraryFileStruct::FLLibraryFileStruct);
      else
        pFLLibraryFileList = 0;
      exceptionBlock = -1;
      memset(pFLLibraryFileList, 0, 24 * (this->m_iLibraryFilesCapacity + 8));
      if ( this->m_iLibraryFilesCapacity > 0 )
      {
        memmove(pFLLibraryFileList, this->m_pLibraryFiles, 24 * this->m_iLibraryFilesCapacity);
        pswFileNames = (const char *)this->m_pLibraryFiles;
        operator delete[]((void *)pswFileNames);
      }
      this->m_iLibraryFilesCapacity += 8;
      this->m_pLibraryFiles = pFLLibraryFileList;
    }
    v45 = &this->m_pLibraryFiles[this->m_iLibraryFilesCount++];
    iFileNameLength = wcslen(sFileName);
    swFileName = (wchar_t *)operator new[](2 * (iFileNameLength + 1));
    v45->m_swpFileName = swFileName;
    wcscpy(v45->m_swpFileName, sFileName);
    v22 = 4;
    hError = SetFilePointer(hFile, -4, 0, FILE_END);
    if ( hError == -1 )
    {
      CloseHandle(hFile);
      BBSupportTracePrintF(
        3,
        "CFileLibrary::AddFileLibrary\t:\tFailed to set file ptr on FILE_END, %s",
        (const char *)sFileName);
      return 6;
    }
    else
    {
      bSucceeded = ReadFile(hFile, &Buffer, 4u, &NumberOfBytesRead, 0);
      if ( bSucceeded )
      {
        hError = SetFilePointer(hFile, Buffer, 0, FILE_BEGIN);
        if ( hError == -1 )
        {
          CloseHandle(hFile);
          BBSupportTracePrintF(
            3,
            "CFileLibrary::AddFileLibrary\t:\tFailed to set file ptr on FILE_BEGIN, %s",
            (const char *)sFileName);
          return 6;
        }
        else
        {
          FLHeaderStruct::FLHeaderStruct(&sHeader);
          bSucceeded = ReadFile(hFile, &sHeader, 0x18u, &NumberOfBytesRead, 0);
          if ( bSucceeded )
          {
            if ( sHeader.m_iVersion == 4097 || sHeader.m_iVersion == 256 )
            {
              pDirectoryNames = operator new[](sHeader.m_iDirectoryNamesSize);
              pFileNames = operator new[](sHeader.m_iFileNamesSize);
              iHeaderCount = sHeader.m_iFileHeaderCount;
              pFileHeaders = (FLHeaderFileStruct *)operator new[](24 * sHeader.m_iFileHeaderCount);
              exceptionBlock = 1;
              if ( pFileHeaders )
                _vec_ctor_no(
                  pFileHeaders,
                  0x18u,
                  iHeaderCount,
                  (void *(__thiscall *)(void *))FLHeaderFileStruct::FLHeaderFileStruct);
              else
                pFileHeaders = 0;
              exceptionBlock = -1;
              nNumberOfBytesToRead = sHeader.m_iDirectoryNamesSize;
              bSucceeded = ReadFile(hFile, pDirectoryNames, sHeader.m_iDirectoryNamesSize, &NumberOfBytesRead, 0);
              if ( bSucceeded && NumberOfBytesRead == nNumberOfBytesToRead )
              {
                nNumberOfBytesToRead = sHeader.m_iFileNamesSize;
                bSucceeded = ReadFile(hFile, pFileNames, sHeader.m_iFileNamesSize, &NumberOfBytesRead, 0);
                if ( bSucceeded && NumberOfBytesRead == nNumberOfBytesToRead )
                {
                  nNumberOfBytesToRead = 24 * sHeader.m_iFileHeaderCount;
                  bSucceeded = ReadFile(hFile, pFileHeaders, 24 * sHeader.m_iFileHeaderCount, &NumberOfBytesRead, 0);
                  if ( bSucceeded && NumberOfBytesRead == nNumberOfBytesToRead )
                  {
                    v54 = this->m_iLibraryFilesCount - 1;
                    pswDirectoryNames = (const char *)operator new[](4 * sHeader.m_iDirectoryNameCount);
                    pCopyBuffer = pDirectoryNames;
                    for ( i = 0; i < sHeader.m_iDirectoryNameCount; ++i )
                    {
                      *(_DWORD *)&pswDirectoryNames[4 * i] = pCopyBuffer;
                      while ( *pCopyBuffer )
                        ++pCopyBuffer;
                      ++pCopyBuffer;
                    }
                    pswFileNames = (const char *)operator new[](4 * sHeader.m_iFileHeaderCount);
                    pCopyBuffer = pFileNames;
                    for ( i = 0; i < sHeader.m_iFileHeaderCount; ++i )
                    {
                      *(_DWORD *)&pswFileNames[4 * i] = pCopyBuffer;
                      while ( *pCopyBuffer )
                        ++pCopyBuffer;
                      ++pCopyBuffer;
                    }
                    pDir = CFileLibrary::pAddDirectory(this, 0);
                    for ( i = 0; i < sHeader.m_iFileHeaderCount; ++i )
                    {
                      if ( pFileHeaders->field_C == -1 )
                      {
                        if ( sHeader.m_iVersion == 256 )
                        {
                          std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v70);
                          exceptionBlock = 2;
                          std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
                            (int)v75,
                            *(char **)&pswFileNames[4 * i]);
                          LOBYTE(exceptionBlock) = 3;
                          v11 = v54;
                          v5 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v75);
                          CFileLibrary::pAddFile(pDir, v5, pFileHeaders, v11, a3);
                          LOBYTE(exceptionBlock) = 2;
                          std::wstring::~wstring(v75);
                          exceptionBlock = -1;
                          std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v70);
                        }
                        else
                        {
                          v31 = *(wchar_t **)&pswFileNames[4 * i];
                          CFileLibrary::pAddFile(pDir, v31, pFileHeaders, v54, a3);
                        }
                      }
                      ++pFileHeaders;
                    }
                    for ( i = 0; i < sHeader.m_iDirectoryNameCount; ++i )
                    {
                      if ( sHeader.m_iVersion == 256 )
                      {
                        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v71);
                        exceptionBlock = 4;
                        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
                          (int)v76,
                          *(char **)&pswDirectoryNames[4 * i]);
                        LOBYTE(exceptionBlock) = 5;
                        v6 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v76);
                        CFileLibrary::pAddDirectory(this, v6);
                        LOBYTE(exceptionBlock) = 4;
                        std::wstring::~wstring(v76);
                        exceptionBlock = -1;
                        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v71);
                      }
                      else
                      {
                        String = *(wchar_t **)&pswDirectoryNames[4 * i];
                        pDir = CFileLibrary::pAddDirectory(this, String);
                      }
                      for ( j = 0; j < sHeader.m_iFileHeaderCount; ++j )
                      {
                        if ( pFileHeaders->field_C == i )
                        {
                          if ( sHeader.m_iVersion == 256 )
                          {
                            std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v72);
                            exceptionBlock = 6;
                            std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::from_bytes(
                              (int)v74,
                              *(char **)&pswFileNames[4 * j]);
                            LOBYTE(exceptionBlock) = 7;
                            v14 = a3;
                            v12 = v54;
                            v7 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v74);
                            CFileLibrary::pAddFile(pDir, v7, pFileHeaders, v12, v14);
                            LOBYTE(exceptionBlock) = 6;
                            std::wstring::~wstring(v74);
                            exceptionBlock = -1;
                            std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v72);
                          }
                          else
                          {
                            v16 = *(wchar_t **)&pswFileNames[4 * j];
                            CFileLibrary::pAddFile(pDir, v16, pFileHeaders, v54, a3);
                          }
                        }
                        ++pFileHeaders;
                      }
                    }
                    v8 = std::make_pair<wchar_t const * &,int &>(v15, &sFileName, &v54);
                    std::pair<std::wstring,int>::pair<std::wstring,int>(v73, v8);
                    exceptionBlock = 8;
                    std::vector<std::pair<std::wstring,int>>::push_back(&this->m_vFileIdPairs, (int)v73);
                    exceptionBlock = -1;
                    std::pair<std::wstring,int>::~pair<std::wstring,int>(v73);
                    operator delete[]((void *)pswFileNames);
                    operator delete[]((void *)pswDirectoryNames);
                    operator delete[](pDirectoryNames);
                    operator delete[](pFileNames);
                    operator delete[](pFileHeaders);
                    CloseHandle(hFile);
                    CFileLibrary::pOptimize(this);
                    return 1;
                  }
                  else
                  {
                    CloseHandle(hFile);
                    operator delete[](pDirectoryNames);
                    operator delete[](pFileNames);
                    operator delete[](pFileHeaders);
                    BBSupportTracePrintF(
                      3,
                      "CFileLibrary::AddFileLibrary\t:\tFailed to read file info, %s",
                      (const char *)sFileName);
                    return 6;
                  }
                }
                else
                {
                  CloseHandle(hFile);
                  operator delete[](pDirectoryNames);
                  operator delete[](pFileNames);
                  operator delete[](pFileHeaders);
                  BBSupportTracePrintF(
                    3,
                    "CFileLibrary::AddFileLibrary\t:\tFailed to read file names, %s",
                    (const char *)sFileName);
                  return 6;
                }
              }
              else
              {
                CloseHandle(hFile);
                operator delete[](pDirectoryNames);
                operator delete[](pFileNames);
                operator delete[](pFileHeaders);
                BBSupportTracePrintF(
                  3,
                  "CFileLibrary::AddFileLibrary\t:\tFailed to read directory names, %s",
                  (const char *)sFileName);
                return 6;
              }
            }
            else
            {
              CloseHandle(hFile);
              BBSupportTracePrintF(3, "CFileLibrary::AddFileLibrary\t:\tWrong version, %s", (const char *)sFileName);
              return 7;
            }
          }
          else
          {
            CloseHandle(hFile);
            BBSupportTracePrintF(
              3,
              "CFileLibrary::AddFileLibrary\t:\tFailed to read file data, %s",
              (const char *)sFileName);
            return 6;
          }
        }
      }
      else
      {
        CloseHandle(hFile);
        BBSupportTracePrintF(
          3,
          "CFileLibrary::AddFileLibrary\t:\tFailed to read file data, %s",
          (const char *)sFileName);
        return 6;
      }
    }
  }
}


// address=[0x2f0b6c0]
// Decompiled from int __thiscall CFileLibrary::ListFilesInLib(CFileLibrary *this, const wchar_t *a2)
class std::vector<struct std::pair<std::wstring,std::wstring >,class std::allocator<struct std::pair<std::wstring,std::wstring > > >  CFileLibrary::ListFilesInLib(wchar_t const * a2) {
  
  char v3; // [esp-1Ch] [ebp-94h] BYREF
  int v4; // [esp-18h] [ebp-90h]
  int v5; // [esp-14h] [ebp-8Ch]
  _DWORD v6[3]; // [esp-10h] [ebp-88h] BYREF
  int v7; // [esp-4h] [ebp-7Ch]
  int v8[4]; // [esp+4h] [ebp-74h] BYREF
  _BYTE v9[12]; // [esp+14h] [ebp-64h] BYREF
  _BYTE v10[12]; // [esp+20h] [ebp-58h] BYREF
  int v11; // [esp+2Ch] [ebp-4Ch]
  int v12; // [esp+30h] [ebp-48h]
  char *v13; // [esp+34h] [ebp-44h]
  int v14; // [esp+38h] [ebp-40h]
  _DWORD *v15; // [esp+3Ch] [ebp-3Ch]
  int v16; // [esp+44h] [ebp-34h]
  std::_Iterator_base12 *v17; // [esp+48h] [ebp-30h]
  std::_Iterator_base12 *v18; // [esp+4Ch] [ebp-2Ch]
  int j; // [esp+50h] [ebp-28h]
  int i; // [esp+54h] [ebp-24h]
  int v21; // [esp+58h] [ebp-20h]
  FLMemFileStruct *m_pFiles; // [esp+5Ch] [ebp-1Ch]
  struct FLMemDirStruct *m_pDirectories; // [esp+64h] [ebp-14h]
  char v25; // [esp+6Bh] [ebp-Dh]
  int v26; // [esp+74h] [ebp-4h]
  char v27; // [esp+84h] [ebp+Ch] BYREF

  v21 = 0;
  BBSupportTracePrintF(1, "Starting listing");
  v7 = *(_DWORD *)std::_Iterator_base12::operator=(&v27);
  v15 = v6;
  v14 = std::vector<std::pair<std::wstring,int>>::end(v6);
  v13 = &v3;
  v12 = std::vector<std::pair<std::wstring,int>>::begin(&v3);
  v11 = std::find_if<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>,_lambda_2ccfe65c9d4fa599f75d5b3f0ed0c104_>(
          v10,
          v3,
          v4,
          v5,
          v6[0],
          v6[1],
          v6[2],
          v7);
  v26 = 0;
  v18 = (std::_Iterator_base12 *)std::vector<std::pair<std::wstring,int>>::end(v9);
  v17 = v18;
  LOBYTE(v26) = 1;
  v25 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>::operator==(v18);
  LOBYTE(v26) = 0;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>(v9);
  if ( v25 )
  {
    std::vector<std::pair<std::wstring,std::wstring>>::vector<std::pair<std::wstring,std::wstring>>((void *)a2);
    v21 |= 1u;
    v26 = -1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>(v10);
    return (int)a2;
  }
  else
  {
    v16 = *(_DWORD *)(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>::operator->(v10)
                    + 28);
    m_pDirectories = this->m_pDirectories;
    std::vector<std::pair<std::wstring,std::wstring>>::vector<std::pair<std::wstring,std::wstring>>(v8);
    LOBYTE(v26) = 2;
    for ( i = 0; i < this->m_iDirectoryCount; ++i )
    {
      m_pFiles = m_pDirectories->m_pFiles;
      for ( j = 0; j < m_pDirectories->m_iFileCount; ++j )
      {
        if ( m_pFiles->m_iLibraryIndex == v16 )
        {
          std::vector<std::pair<std::wstring,std::wstring>>::emplace_back<wchar_t * &,wchar_t * &>(
            v8,
            (int)m_pDirectories,
            (int)m_pFiles);
          BBSupportTracePrintF(
            1,
            "File: %s\\%s",
            (const char *)m_pDirectories->m_swpDirectoryName,
            (const char *)m_pFiles->m_pswName);
        }
        ++m_pFiles;
      }
      ++m_pDirectories;
    }
    std::vector<std::pair<std::wstring,std::wstring>>::vector<std::pair<std::wstring,std::wstring>>(v8);
    v21 |= 1u;
    LOBYTE(v26) = 0;
    std::vector<std::pair<std::wstring,std::wstring>>::~vector<std::pair<std::wstring,std::wstring>>();
    v26 = -1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,int>>>>(v10);
    return (int)a2;
  }
}


// address=[0x2f0b8c0]
// Decompiled from int __thiscall CFileLibrary::DumpFilesInLib(CFileLibrary *this, const wchar_t *a3, wchar_t *String)
void  CFileLibrary::DumpFilesInLib(wchar_t const * a3, wchar_t const * String) {
  
  wchar_t *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  wchar_t *v7; // eax
  const char *v8; // eax
  _Cnd_internal_imp_t *v9; // [esp-4h] [ebp-18Ch]
  _Cnd_internal_imp_t *v10; // [esp-4h] [ebp-18Ch]
  _Cnd_internal_imp_t *v11; // [esp-4h] [ebp-18Ch]
  _BYTE v12[12]; // [esp+4h] [ebp-184h] BYREF
  wchar_t a2[8]; // [esp+10h] [ebp-178h] BYREF
  _BYTE v14[12]; // [esp+20h] [ebp-168h] BYREF
  void *C; // [esp+2Ch] [ebp-15Ch]
  int v16; // [esp+30h] [ebp-158h]
  void *v17; // [esp+34h] [ebp-154h]
  void *v18; // [esp+38h] [ebp-150h]
  int v19; // [esp+3Ch] [ebp-14Ch]
  void *v20; // [esp+40h] [ebp-148h]
  void *v21; // [esp+44h] [ebp-144h]
  void *v22; // [esp+48h] [ebp-140h]
  void *v23; // [esp+4Ch] [ebp-13Ch]
  void *v24; // [esp+50h] [ebp-138h]
  int *v26; // [esp+58h] [ebp-130h]
  int v27; // [esp+5Ch] [ebp-12Ch]
  void *Buffer; // [esp+60h] [ebp-128h]
  int v29; // [esp+64h] [ebp-124h]
  size_t Size; // [esp+68h] [ebp-120h]
  _BYTE v31[72]; // [esp+6Ch] [ebp-11Ch] BYREF
  int v32[7]; // [esp+B4h] [ebp-D4h] BYREF
  int v33[7]; // [esp+D0h] [ebp-B8h] BYREF
  int v34[7]; // [esp+ECh] [ebp-9Ch] BYREF
  _BYTE v35[28]; // [esp+108h] [ebp-80h] BYREF
  int v36[7]; // [esp+124h] [ebp-64h] BYREF
  int v37[7]; // [esp+140h] [ebp-48h] BYREF
  _BYTE v38[28]; // [esp+15Ch] [ebp-2Ch] BYREF
  int v39; // [esp+184h] [ebp-4h]

  CFileLibrary::ListFilesInLib(this, a2);
  v39 = 0;
  if ( (unsigned __int8)std::vector<std::pair<std::wstring,std::wstring>>::empty(a2) )
  {
    v39 = -1;
    return std::vector<std::pair<std::wstring,std::wstring>>::~vector<std::pair<std::wstring,std::wstring>>();
  }
  else
  {
    std::wstring::wstring(v36, String);
    LOBYTE(v39) = 1;
    if ( !(unsigned __int8)sub_2F0D990(v36) )
      sub_2F0D9D0(v36);
    v26 = (int *)a2;
    std::vector<std::pair<std::wstring,std::wstring>>::begin(v14);
    LOBYTE(v39) = 2;
    std::vector<std::pair<std::wstring,std::wstring>>::end(v12);
    LOBYTE(v39) = 3;
    while ( (unsigned __int8)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>::operator!=((std::_Iterator_base12 *)v12) )
    {
      v29 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>::operator*(v14);
      v9 = (_Cnd_internal_imp_t *)v29;
      v24 = (void *)std::operator+<wchar_t>((int)v34, (int)v36, (wchar_t *)L"\\");
      v23 = v24;
      LOBYTE(v39) = 4;
      std::operator+<wchar_t>(v37, v24, v9);
      LOBYTE(v39) = 6;
      std::wstring::~wstring(v34);
      if ( !(unsigned __int8)sub_2F0D990(v37) )
        sub_2F0D9D0(v37);
      v10 = (_Cnd_internal_imp_t *)(v29 + 28);
      v22 = (void *)std::operator+<wchar_t>((int)v33, v29, (wchar_t *)L"\\");
      v21 = v22;
      LOBYTE(v39) = 7;
      std::operator+<wchar_t>(v38, v22, v10);
      LOBYTE(v39) = 9;
      std::wstring::~wstring(v33);
      v4 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v38);
      v27 = CFileLibrary::FileOpen(&g_cFileLibrary, v4, 0);
      Size = 0;
      if ( v27 == -1 )
      {
        v5 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v38);
        BBSupportTracePrintF(1, "can't open file `%s'", v5);
      }
      else
      {
        Size = CFileLibrary::FileSize(&g_cFileLibrary, v27);
      }
      v20 = operator new[](Size);
      Buffer = v20;
      memset(v20, 0, Size);
      v19 = CFileLibrary::FileRead(&g_cFileLibrary, v27, (char *)Buffer, Size);
      if ( v19 == -1 )
      {
        v6 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v38);
        BBSupportTracePrintF(1, "cannot read `%s'", v6);
      }
      else
      {
        v11 = (_Cnd_internal_imp_t *)(v29 + 28);
        v18 = (void *)std::operator+<wchar_t>((int)v32, (int)v37, (wchar_t *)asc_3AB56DC);
        v17 = v18;
        LOBYTE(v39) = 10;
        std::operator+<wchar_t>(v35, v18, v11);
        LOBYTE(v39) = 12;
        std::wstring::~wstring(v32);
        CFile::CFile((CFile *)v31);
        LOBYTE(v39) = 13;
        v7 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v35);
        CFile::Open(v7, 10, "D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\File.h", 0);
        v16 = CFile::Write(Buffer, 1u, Size, UNUSED_ARG(), UNUSED_ARG());
        if ( v16 < (int)Size )
        {
          v8 = (const char *)std::wstring::c_str((_Cnd_internal_imp_t *)v35);
          BBSupportTracePrintF(1, "short write `%s'", v8);
        }
        CFile::Close((CFile *)v31, UNUSED_ARG(), UNUSED_ARG());
        LOBYTE(v39) = 12;
        CFile::~CFile();
        LOBYTE(v39) = 9;
        std::wstring::~wstring(v35);
      }
      C = Buffer;
      operator delete[](Buffer);
      CFileLibrary::FileClose(&g_cFileLibrary, v27);
      LOBYTE(v39) = 6;
      std::wstring::~wstring(v38);
      LOBYTE(v39) = 3;
      std::wstring::~wstring(v37);
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>::operator++(v14);
    }
    LOBYTE(v39) = 2;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>(v12);
    LOBYTE(v39) = 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<std::pair<std::wstring,std::wstring>>>>(v14);
    LOBYTE(v39) = 0;
    std::wstring::~wstring(v36);
    v39 = -1;
    return std::vector<std::pair<std::wstring,std::wstring>>::~vector<std::pair<std::wstring,std::wstring>>();
  }
}


// address=[0x2f0bd30]
// Decompiled from void __thiscall CFileLibrary::InitFileLibraries(CFileLibrary *this)
void  CFileLibrary::InitFileLibraries(void) {
  
  CFileLibrary::pFreeFLData(this);
}


// address=[0x2f0bd50]
// Decompiled from void __thiscall CFileLibrary::C_Init(CFileLibrary *this)
void  CFileLibrary::C_Init(void) {
  
  CFileLibrary::pFreeFLCreationData(this);
}


// address=[0x2f0bd70]
// Decompiled from void __thiscall CFileLibrary::C_AddPath(CFileLibrary *this, wchar_t *_swpPath, int a3, wchar_t *Source, wchar_t *a5)
void  CFileLibrary::C_AddPath(wchar_t const * _swpPath, int a3, wchar_t const * Source, wchar_t const * a5) {
  
  size_t v5; // eax
  size_t v6; // eax
  FLPathListStruct *v7; // [esp+1Ch] [ebp-24h]
  FLPathListStruct *C; // [esp+20h] [ebp-20h]
  FLPathListStruct *i; // [esp+28h] [ebp-18h]
  size_t Count; // [esp+2Ch] [ebp-14h]

  C = (FLPathListStruct *)operator new(0x14u);
  if ( C )
    v7 = FLPathListStruct::FLPathListStruct(C);
  else
    v7 = 0;
  Count = wcslen(_swpPath);
  if ( Count )
  {
    if ( _swpPath[Count - 1] == '\\' )
    {
      v7->m_swpPath = (wchar_t *)operator new[](2 * Count);
      wcsncpy(v7->m_swpPath, _swpPath, Count);
      v7->m_swpPath[Count - 1] = 0;
    }
    else
    {
      v7->m_swpPath = (wchar_t *)operator new[](2 * (Count + 1));
      wcscpy(v7->m_swpPath, _swpPath);
    }
    if ( Source )
    {
      v5 = wcslen(Source);
      v7->m_swpSearch = (wchar_t *)operator new[](2 * (v5 + 1));
      wcscpy(v7->m_swpSearch, Source);
    }
    else
    {
      v7->m_swpSearch = (wchar_t *)operator new[](4u);
      wcscpy(v7->m_swpSearch, asc_3AB57EC);
    }
    v7->field_C = a3;
    if ( a5 )
    {
      v6 = wcslen(a5);
      v7->m_swpUnknown = (wchar_t *)operator new[](2 * (v6 + 1));
      wcscpy(v7->m_swpUnknown, a5);
    }
    if ( this->m_pPathList )
    {
      for ( i = this->m_pPathList; i->field_10; i = (FLPathListStruct *)i->field_10 )
        ;
      i->field_10 = (int)v7;
    }
    else
    {
      this->m_pPathList = v7;
    }
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::C_AddPath : No path specified.");
  }
}


// address=[0x2f0bfc0]
// Decompiled from int __thiscall CFileLibrary::C_CreateFileLibrary(  CFileLibrary *this,  WCHAR *lpFileName,  CHAR *_spCommentFile,  char a4,  DWORD nNumberOfBytesToRead)
int  CFileLibrary::C_CreateFileLibrary(wchar_t const * lpFileName, char * _spCommentFile, int a4, int nNumberOfBytesToRead) {
  
  size_t v6; // eax
  size_t v7; // eax
  size_t v8; // eax
  size_t v9; // eax
  const char *v10; // eax
  size_t v11; // eax
  size_t v12; // eax
  size_t v13; // eax
  size_t v14; // eax
  const char *v15; // eax
  const char *v16; // [esp-Ch] [ebp-2D48h]
  const char *v17; // [esp-8h] [ebp-2D44h]
  const char *v18; // [esp-4h] [ebp-2D40h]
  DWORD NumberOfBytesRead; // [esp+24h] [ebp-2D18h] BYREF
  WCHAR *v21; // [esp+28h] [ebp-2D14h]
  FLDirListStruct *v22; // [esp+2Ch] [ebp-2D10h]
  FLDirListStruct *v23; // [esp+30h] [ebp-2D0Ch]
  FLDirListStruct *v24; // [esp+34h] [ebp-2D08h]
  BOOL NextFileW; // [esp+38h] [ebp-2D04h]
  wchar_t *v26; // [esp+3Ch] [ebp-2D00h]
  int v28; // [esp+44h] [ebp-2CF8h]
  WCHAR *v29; // [esp+48h] [ebp-2CF4h]
  FLDirListStruct *v30; // [esp+4Ch] [ebp-2CF0h]
  void *v31; // [esp+50h] [ebp-2CECh]
  FLDirListStruct *v33; // [esp+58h] [ebp-2CE4h]
  int v35; // [esp+60h] [ebp-2CDCh]
  unsigned int v36; // [esp+64h] [ebp-2CD8h]
  FLDirListStruct *v37; // [esp+68h] [ebp-2CD4h] MAPDST
  FLDirListStruct *v39; // [esp+70h] [ebp-2CCCh]
  FLDirListStruct *m_pContainingDir; // [esp+74h] [ebp-2CC8h]
  FLDirListStruct *v41; // [esp+78h] [ebp-2CC4h]
  signed int v42; // [esp+7Ch] [ebp-2CC0h]
  FLDirListStruct *v43; // [esp+80h] [ebp-2CBCh]
  FLDirListStruct *v44; // [esp+84h] [ebp-2CB8h]
  BOOL v45; // [esp+88h] [ebp-2CB4h]
  unsigned int m_iFileHeaderCount; // [esp+9Ch] [ebp-2CA0h]
  DWORD v51; // [esp+A0h] [ebp-2C9Ch]
  CHAR *v52; // [esp+A4h] [ebp-2C98h]
  int v53; // [esp+A8h] [ebp-2C94h]
  FLDirListStruct *v54; // [esp+ACh] [ebp-2C90h]
  FLFileListStruct *v55; // [esp+B0h] [ebp-2C8Ch] MAPDST
  FLFileListStruct *v56; // [esp+B4h] [ebp-2C88h]
  FLHeaderStruct v57; // [esp+B8h] [ebp-2C84h] BYREF
  int v58; // [esp+D0h] [ebp-2C6Ch]
  FLHeaderFileStruct *pFileHeaders; // [esp+D8h] [ebp-2C64h] MAPDST
  int v61; // [esp+DCh] [ebp-2C60h]
  HANDLE hFile; // [esp+E0h] [ebp-2C5Ch]
  HANDLE hFindFile; // [esp+E4h] [ebp-2C58h]
  FLFileListStruct *pPrevFileList; // [esp+E8h] [ebp-2C54h]
  FLDirListStruct *v65; // [esp+ECh] [ebp-2C50h]
  signed int iUnknownLength; // [esp+F0h] [ebp-2C4Ch]
  int v67; // [esp+F4h] [ebp-2C48h] BYREF
  char *Str; // [esp+F8h] [ebp-2C44h]
  int v69; // [esp+FCh] [ebp-2C40h]
  int v70; // [esp+100h] [ebp-2C3Ch]
  int v71; // [esp+104h] [ebp-2C38h]
  wchar_t *Source; // [esp+108h] [ebp-2C34h]
  DWORD NumberOfBytesWritten; // [esp+10Ch] [ebp-2C30h] BYREF
  int v74; // [esp+110h] [ebp-2C2Ch]
  int v75; // [esp+114h] [ebp-2C28h]
  BOOL v76; // [esp+118h] [ebp-2C24h]
  FLDirListStruct *m_pDirList; // [esp+11Ch] [ebp-2C20h]
  int v78; // [esp+120h] [ebp-2C1Ch]
  int i; // [esp+124h] [ebp-2C18h] MAPDST
  int uFailReason; // [esp+128h] [ebp-2C14h]
  FLDirListStruct *pDirList; // [esp+12Ch] [ebp-2C10h] MAPDST
  FLDirListStruct *j; // [esp+134h] [ebp-2C08h]
  HANDLE hObject; // [esp+138h] [ebp-2C04h]
  FLDirListStruct *m; // [esp+13Ch] [ebp-2C00h]
  FLDirListStruct *v87; // [esp+144h] [ebp-2BF8h]
  FLPathListStruct *m_pPathList; // [esp+148h] [ebp-2BF4h]
  FLDirListStruct *pDirListIterator; // [esp+14Ch] [ebp-2BF0h] MAPDST
  FLFileListStruct *k; // [esp+150h] [ebp-2BECh]
  FLFileListStruct *n; // [esp+154h] [ebp-2BE8h]
  char bCanceled; // [esp+15Bh] [ebp-2BE1h]
  struct _WIN32_FIND_DATAW FindFileData; // [esp+15Ch] [ebp-2BE0h] BYREF
  _DWORD v94[22]; // [esp+3ACh] [ebp-2990h] BYREF
  _DWORD v95[22]; // [esp+404h] [ebp-2938h] BYREF
  _BYTE v96[28]; // [esp+45Ch] [ebp-28E0h] BYREF
  _BYTE v97[28]; // [esp+478h] [ebp-28C4h] BYREF
  _BYTE v98[28]; // [esp+494h] [ebp-28A8h] BYREF
  _BYTE v99[28]; // [esp+4B0h] [ebp-288Ch] BYREF
  _BYTE v100[28]; // [esp+4CCh] [ebp-2870h] BYREF
  struct FLCopyProgressStruct pCopyProgress; // [esp+4E8h] [ebp-2854h] BYREF
  CHAR Text[2048]; // [esp+50Ch] [ebp-2830h] BYREF
  CHAR v103[1024]; // [esp+D0Ch] [ebp-2030h] BYREF
  CHAR v104[1024]; // [esp+110Ch] [ebp-1C30h] BYREF
  char v105[4096]; // [esp+150Ch] [ebp-1830h] BYREF
  WCHAR FileName[260]; // [esp+250Ch] [ebp-830h] BYREF
  WCHAR Buffer[260]; // [esp+2714h] [ebp-628h] BYREF
  wchar_t Destination[260]; // [esp+291Ch] [ebp-420h] BYREF
  wchar_t String[260]; // [esp+2B24h] [ebp-218h] BYREF
  int exceptionBlock; // [esp+2D38h] [ebp-4h]

  if ( !this->m_pPathList )
    return 1;
  m_pPathList = this->m_pPathList;
  v65 = 0;
  pDirList = 0;
  pPrevFileList = 0;
  v71 = 0;
  uFailReason = 0;
  bCanceled = 0;
  while ( m_pPathList && !bCanceled )
  {
    pDirListIterator = (FLDirListStruct *)operator new(0x10u);
    exceptionBlock = 0;
    if ( pDirListIterator )
      pDirListIterator = FLDirListStruct::FLDirListStruct(pDirListIterator);
    else
      pDirListIterator = 0;
    v33 = pDirListIterator;
    exceptionBlock = -1;
    v74 = m_pPathList->field_C;
    while ( pDirListIterator )
    {
      v35 = 0;
      Destination[0] = 0;
      if ( m_pPathList->m_swpUnknown )
      {
        Source = m_pPathList->m_swpUnknown;
        if ( *Source == '\\' )
          ++Source;
        wcscpy(Destination, Source);
        iUnknownLength = wcslen(Destination) - 1;
        if ( iUnknownLength > 0 && Destination[iUnknownLength] == '\\' )
        {
          v36 = 2 * iUnknownLength;
          if ( (unsigned int)(2 * iUnknownLength) >= 520 )
            report_rangecheckfailure();
          Destination[v36 / 2] = 0;
        }
      }
      for ( i = 0; i < 2; ++i )
      {
        if ( !bCanceled )
        {
          v75 = -1;
          if ( i )
          {
            if ( i == 1 )
            {
              if ( pDirListIterator->m_swpPath )
              {
                swprintf(
                  Buffer,
                  L"%s\\%s\\%s",
                  m_pPathList->m_swpPath,
                  pDirListIterator->m_swpPath,
                  m_pPathList->m_swpSearch);
                v78 = 0;
              }
              else
              {
                swprintf(Buffer, L"%s\\%s", m_pPathList->m_swpPath, m_pPathList->m_swpSearch);
                v78 = 1;
              }
            }
          }
          else if ( pDirListIterator->m_swpPath )
          {
            swprintf(Buffer, L"%s\\%s\\*", m_pPathList->m_swpPath, pDirListIterator->m_swpPath);
            v78 = 0;
          }
          else
          {
            swprintf(Buffer, L"%s\\*", m_pPathList->m_swpPath);
            v78 = 1;
          }
          if ( Destination[0] )
            v78 = 0;
          hFindFile = FindFirstFileW(Buffer, &FindFileData);
          if ( hFindFile != (HANDLE)-1 )
          {
            if ( pDirListIterator->m_swpPath )
              swprintf(String, L"%s\\%s", m_pPathList->m_swpPath, pDirListIterator->m_swpPath);
            else
              swprintf(String, L"%s", m_pPathList->m_swpPath);
            v37 = (FLDirListStruct *)operator new(0x10u);
            exceptionBlock = 1;
            if ( v37 )
              v37 = FLDirListStruct::FLDirListStruct(v37);
            else
              v37 = 0;
            exceptionBlock = -1;
            v87 = v37;
            v6 = wcslen(String);
            v37->m_swpPath = (WCHAR *)operator new[](2 * (v6 + 1));
            wcscpy(v87->m_swpPath, String);
            if ( pDirListIterator->m_swpPath )
              swprintf(
                String,
                L"Root: \"%s\"\n  Directory: \"\\%s\\%s\"",
                m_pPathList->m_swpPath,
                Destination,
                pDirListIterator->m_swpPath);
            else
              swprintf(String, L"Root: \"%s\"\n  Directory: \"\\%s\\\"", m_pPathList->m_swpPath, Destination);
            v7 = wcslen(String);
            v87->field_4 = (char *)operator new[](2 * (v7 + 1));
            wcscpy((wchar_t *)v87->field_4, String);
            v87->m_pNext = pDirList;
            pDirList = v87;
            if ( !v78 )
            {
              m_pDirList = this->m_pDirList;
              if ( pDirListIterator->m_swpPath )
              {
                if ( Destination[0] )
                  swprintf(String, L"%s\\%s", Destination, pDirListIterator->m_swpPath);
                else
                  swprintf(String, L"%s", pDirListIterator->m_swpPath);
              }
              else
              {
                swprintf(String, L"%s", Destination);
              }
              while ( m_pDirList )
              {
                if ( !wcsicmp(String, m_pDirList->m_swpPath) )
                {
                  v75 = m_pDirList->field_8;
                  break;
                }
                m_pDirList = m_pDirList->m_pNext;
              }
              if ( v75 == -1 )
              {
                v39 = (FLDirListStruct *)operator new(0x10u);
                exceptionBlock = 2;
                if ( v39 )
                  v41 = FLDirListStruct::FLDirListStruct(v39);
                else
                  v41 = 0;
                v30 = v41;
                exceptionBlock = -1;
                v87 = v41;
                v8 = wcslen(String);
                v21 = (WCHAR *)operator new[](2 * (v8 + 1));
                v41->m_swpPath = v21;
                v87->field_8 = v71;
                wcscpy(v87->m_swpPath, String);
                if ( v65 )
                  v65->m_pNext = v87;
                else
                  this->m_pDirList = v87;
                v65 = v87;
                v75 = v71++;
              }
            }
            do
            {
              if ( (FindFileData.dwFileAttributes & 0x10) != 0 )
              {
                if ( !i )
                {
                  v76 = (v74 & 1) != 0;
                  if ( (v74 & 2) != 0 && FindFileData.cFileName[0] == 33 )
                    v76 = 1;
                  v42 = wcslen(FindFileData.cFileName);
                  if ( v42 >= 6 && !wcsicmp((const wchar_t *)&FindFileData.nFileSizeLow + v42 + 1, L".work") )
                    v76 = 1;
                  if ( !j__wcscmp(FindFileData.cFileName, L".") || !j__wcscmp(FindFileData.cFileName, L"..") )
                    v76 = 1;
                  if ( !v76 )
                  {
                    for ( j = pDirListIterator; j->m_pNext; j = j->m_pNext )
                      ;
                    if ( pDirListIterator->m_swpPath )
                      swprintf(String, L"%s\\%s", pDirListIterator->m_swpPath, FindFileData.cFileName);
                    else
                      swprintf(String, L"%s", FindFileData.cFileName);
                    v43 = (FLDirListStruct *)operator new(0x10u);
                    exceptionBlock = 3;
                    if ( v43 )
                      v44 = FLDirListStruct::FLDirListStruct(v43);
                    else
                      v44 = 0;
                    v22 = v44;
                    exceptionBlock = -1;
                    j->m_pNext = v44;
                    j = j->m_pNext;
                    v9 = wcslen(String);
                    v29 = (WCHAR *)operator new[](2 * (v9 + 1));
                    j->m_swpPath = v29;
                    wcscpy(j->m_swpPath, String);
                  }
                }
              }
              else if ( i == 1 )
              {
                v45 = 0;
                if ( (v74 & 2) != 0 )
                  v45 = FindFileData.cFileName[0] == '!';
                if ( !v45 )
                {
                  for ( k = this->m_FileList; k; k = k->m_pNext )
                  {
                    if ( !wcsicmp(k->m_swpFileName, FindFileData.cFileName) && k->m_uU4 == v75 )
                    {
                      uFailReason = 4;
                      m_pContainingDir = k->m_pContainingDir;
                      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>((char *)v95);
                      exceptionBlock = 4;
                      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
                        v95,
                        (int)v98,
                        m_pContainingDir->field_4);
                      LOBYTE(exceptionBlock) = 5;
                      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
                        v95,
                        (int)v97,
                        (char *)m_pContainingDir->m_swpPath);
                      LOBYTE(exceptionBlock) = 6;
                      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
                        v95,
                        (int)v100,
                        pDirList->field_4);
                      LOBYTE(exceptionBlock) = 7;
                      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
                        v95,
                        (int)v99,
                        (char *)FindFileData.cFileName);
                      v18 = (const char *)std::string::c_str(v99);
                      v17 = (const char *)std::string::c_str(v100);
                      v16 = (const char *)std::string::c_str(v97);
                      v10 = (const char *)std::string::c_str(v98);
                      sprintf(
                        Text,
                        "The same file names were found:\n\n%s\n  File: \"%s\"\n\n%s\n  File: \"%s\"\n",
                        v10,
                        v16,
                        v17,
                        v18);
                      v28 = MessageBoxA(0, Text, "Error Creating File Library", 0x31u);
                      if ( v28 == 2 )
                        bCanceled = 1;
                      std::string::~string(v99);
                      LOBYTE(exceptionBlock) = 6;
                      std::string::~string(v100);
                      LOBYTE(exceptionBlock) = 5;
                      std::string::~string(v97);
                      LOBYTE(exceptionBlock) = 4;
                      std::string::~string(v98);
                      exceptionBlock = -1;
                      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v95);
                      break;
                    }
                  }
                  v56 = (FLFileListStruct *)operator new(0x18u);
                  exceptionBlock = 8;
                  if ( v56 )
                    v55 = FLFileListStruct::FLFileListStruct(v56);
                  else
                    v55 = 0;
                  exceptionBlock = -1;
                  k = v55;
                  v11 = wcslen(FindFileData.cFileName);
                  v26 = (wchar_t *)operator new[](2 * (v11 + 1));
                  v55->m_swpFileName = v26;
                  wcscpy(k->m_swpFileName, FindFileData.cFileName);
                  k->m_uU4 = v75;
                  k->m_uFileSize = FindFileData.nFileSizeLow;
                  if ( (v74 & 4) != 0 )
                    k->m_uFlags = FLFF_Compressed;
                  if ( (v74 & 8) != 0 )
                    k->m_uFlags |= FLFF_Encrypted;
                  k->m_pContainingDir = pDirList;
                  if ( pPrevFileList )
                    pPrevFileList->m_pNext = k;
                  else
                    this->m_FileList = k;
                  pPrevFileList = k;
                }
              }
              NextFileW = FindNextFileW(hFindFile, &FindFileData);
            }
            while ( NextFileW && !bCanceled );
            FindClose(hFindFile);
          }
        }
      }
      v24 = pDirListIterator;
      pDirListIterator = pDirListIterator->m_pNext;
      v23 = v24;

      v54 = v24;
      if ( v24 )
        delete v54;
    }
    m_pPathList = (FLPathListStruct *)m_pPathList->field_10;
  }
  if ( !uFailReason && !bCanceled )
  {
    hObject = CreateFileW(lpFileName, 0xC0000000, 0, 0, 2u, 0x80u, 0);
    if ( hObject == (HANDLE)-1 )
    {
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>((char *)v94);
      exceptionBlock = 10;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::to_bytes(
        v94,
        (int)v96,
        (char *)lpFileName);
      v15 = (const char *)std::string::c_str(v96);
      sprintf(v104, "Error Creating File Library file: \"%s\"", v15);
      MessageBoxA(0, v104, "Error Creating File Library", 0x10u);
      uFailReason = 3;
      std::string::~string(v96);
      exceptionBlock = -1;
      std::wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>::~wstring_convert<std::codecvt_utf8_utf16<wchar_t,1114111,0>,wchar_t,std::allocator<wchar_t>,std::allocator<char>>(v94);
    }
    else
    {
      FLHeaderStruct::FLHeaderStruct(&v57);
      v57.m_iVersion = 4097;
      v53 = 0;
      v105[0] = 0;
      if ( _spCommentFile )
        v52 = _spCommentFile;
      else
        v52 = v105;
      Str = v52;
      if ( (a4 & 1) != 0 )
      {
        Str = v105;
        hFile = CreateFileA(_spCommentFile, 0x80000000, 0, 0, 3u, 0x80u, 0);
        if ( hFile == (HANDLE)-1 )
        {
          j__strcpy_0(v105, "\n\nComment File Not Found !!!!\n\n");
        }
        else
        {
          ReadFile(hFile, v105, 0xFFFu, &NumberOfBytesRead, 0);
          v51 = NumberOfBytesRead;
          if ( NumberOfBytesRead >= 0x1000 )
            report_rangecheckfailure();
          v105[v51] = 0;
          CloseHandle(hFile);
        }
      }
      v69 = 0;
      v57.m_iDirectoryNameCount = 0;
      for ( m = this->m_pDirList; m; m = m->m_pNext )
      {
        ++v57.m_iDirectoryNameCount;
        v69 += wcslen(m->m_swpPath) + 1;
      }
      v70 = 0;
      v57.m_iFileHeaderCount = 0;
      for ( n = this->m_FileList; n; n = n->m_pNext )
      {
        ++v57.m_iFileHeaderCount;
        v70 += wcslen(n->m_swpFileName) + 1;
      }
      v61 = 0;
      for ( n = this->m_FileList; n; n = n->m_pNext )
        v61 += n->m_uFileSize;
      v57.field_0 = v70 + v69 + 24;
      v57.field_0 += 24 * v57.m_iFileHeaderCount;
      v57.m_iFileNamesSize = v70;
      v57.m_iDirectoryNamesSize = v69;
      pCopyProgress.m_uFileSize = v61;
      pCopyProgress.m_uU8 = 0;
      pCopyProgress.m_uHeaderCount = v57.m_iFileHeaderCount;
      pCopyProgress.m_uU10 = 0;
      v12 = strlen(Str);
      WriteFile(hObject, Str, v12 + 1, &NumberOfBytesWritten, 0);
      v67 = strlen(Str) + 1;
      n = this->m_FileList;
      m_iFileHeaderCount = v57.m_iFileHeaderCount;
      pFileHeaders = (FLHeaderFileStruct *)operator new[](0x18 * v57.m_iFileHeaderCount);
      exceptionBlock = 9;
      if ( pFileHeaders )
        _vec_ctor_no(
          pFileHeaders,
          0x18u,
          m_iFileHeaderCount,
          (void *(__thiscall *)(void *))FLHeaderFileStruct::FLHeaderFileStruct);
      else
        pFileHeaders = 0;
      exceptionBlock = -1;
      while ( n )
      {
        pFileHeaders->field_0 = v67;
        pFileHeaders->field_C = n->m_uU4;
        pFileHeaders->m_uFlags = n->m_uFlags;
        swprintf(FileName, L"%s\\%s", n->m_pContainingDir->m_swpPath, n->m_swpFileName);
        pCopyProgress.m_uExpectedFileSize = n->m_uFileSize;
        pCopyProgress.m_uFlags = n->m_uFlags;
        v58 = CFileLibrary::pC_CopyFile(this, FileName, hObject, nNumberOfBytesToRead, &pCopyProgress);
        if ( v58 )
        {
          if ( v58 == 5 )
          {
            sprintf(v103, "Error copying file data into a file library.\nThere is not enough space on the disk !!!!");
            MessageBoxA(0, v103, "Error Creating File Library", 0x10u);
          }
          uFailReason = v58;
          break;
        }
        pFileHeaders->field_8 = n->m_uFileSize;
        pFileHeaders->field_4 = pCopyProgress.m_uU1C;
        pFileHeaders->field_14 = pCopyProgress.m_uCRC;
        v67 += pCopyProgress.m_uU1C;
        n = n->m_pNext;
        ++pFileHeaders;
      }
      WriteFile(hObject, &v57, 0x18u, &NumberOfBytesWritten, 0);
      for ( m = this->m_pDirList; m; m = m->m_pNext )
      {
        v13 = wcslen(m->m_swpPath);
        WriteFile(hObject, m->m_swpPath, v13 + 1, &NumberOfBytesWritten, 0);
      }
      for ( n = this->m_FileList; n; n = n->m_pNext )
      {
        v14 = wcslen(n->m_swpFileName);
        WriteFile(hObject, n->m_swpFileName, v14 + 1, &NumberOfBytesWritten, 0);
      }
      WriteFile(hObject, pFileHeaders, 24 * v57.m_iFileHeaderCount, &NumberOfBytesWritten, 0);
      operator delete[](pFileHeaders);
      WriteFile(hObject, &v67, 4u, &NumberOfBytesWritten, 0);
      CloseHandle(hObject);
    }
  }
  while ( pDirList )
  {
    pDirList = pDirList->m_pNext;
    v31 = delete pDirList;
  }
  if ( bCanceled )
  {
    BBSupportTracePrintF(3, "CFileLibrary::C_CreateFileLibrary\t:\tFailed to create lib %s", (const char *)lpFileName);
    return 2;
  }
  else if ( uFailReason )
  {
    BBSupportTracePrintF(
      3,
      "CFileLibrary::C_CreateFileLibrary\t:\tFailed to create lib %s, %i",
      (const char *)lpFileName,
      uFailReason);
    return uFailReason;
  }
  else
  {
    return 0;
  }
}


// address=[0x2f0d650]
// Decompiled from CFileLibrary *__thiscall CFileLibrary::CFileLibrary(CFileLibrary *this, int a2)
 CFileLibrary::CFileLibrary(int a2) {
  
  FLFHandleStruct *v3; // [esp+Ch] [ebp-28h]
  FLFHandleStruct *v4; // [esp+10h] [ebp-24h]
  struct FLFHandleStruct *v5; // [esp+14h] [ebp-20h]
  FLFHandleStruct *C; // [esp+18h] [ebp-1Ch]
  int i; // [esp+1Ch] [ebp-18h] MAPDST
  struct FLFHandleStruct *pFLFHandle; // [esp+20h] [ebp-14h]

  std::vector<std::pair<std::wstring,int>>::vector<std::pair<std::wstring,int>>(&this->m_vFileIdPairs);
  this->m_pPathList = 0;
  this->m_pDirList = 0;
  this->m_FileList = 0;
  this->m_iLibraryFilesCount = 0;
  this->m_iLibraryFilesCapacity = 0;
  this->m_pLibraryFiles = 0;
  this->m_pDirectories = 0;
  this->m_iDirectoryCount = 0;
  this->field_30 = 0;
  this->field_1D8 = 0;
  this->m_uHandleCount = 0;
  if ( a2 >= 2 )
    this->m_iFLFHandleCount = a2;
  else
    this->m_iFLFHandleCount = 4;
  i = a2;
  pFLFHandle = 0;
  while ( i )
  {
    if ( pFLFHandle )
    {
      v4 = (FLFHandleStruct *)operator new(0xCu);
      if ( v4 )
        v3 = FLFHandleStruct::FLFHandleStruct(v4);
      else
        v3 = 0;
      pFLFHandle->m_pNext = v3;
      pFLFHandle->m_pNext->m_pFileHandle = pFLFHandle;
      pFLFHandle = pFLFHandle->m_pNext;
    }
    else
    {
      C = (FLFHandleStruct *)operator new(0xCu);
      if ( C )
        v5 = FLFHandleStruct::FLFHandleStruct(C);
      else
        v5 = 0;
      this->m_pFLFHandleStart = v5;
      pFLFHandle = this->m_pFLFHandleStart;
    }
    --i;
  }
  this->m_pFLFHandleEnd = pFLFHandle;
  for ( i = 0; i < 100; ++i )
    this->m_pFLIntHandle[i] = 0;
  this->m_iRefCount = 0;
  this->m_iFileInteractions = 0;
  this->m_iFileSeeks = 0;
  this->field_C = 0;
  this->m_iDecompressedBytesRead = 0;
  CFileLibrary::InitFileLibraries(this);
  return this;
}


// address=[0x2f0d880]
// Decompiled from int __thiscall CFileLibrary::~CFileLibrary(CFileLibrary *this)
 CFileLibrary::~CFileLibrary(void) {
  
  struct FLFHandleStruct **m_pFLFHandleStart; // [esp+8h] [ebp-18h]
  int i; // [esp+Ch] [ebp-14h]

  for ( i = 0; i < this->m_iLibraryFilesCount; ++i )
  {
    if ( this->m_pLibraryFiles[i].m_pFileData )
    {
      UnmapViewOfFile(this->m_pLibraryFiles[i].m_pFileData);
      CloseHandle(this->m_pLibraryFiles[i].m_hFileMap);
      this->m_pLibraryFiles[i].m_pFileData = 0;
    }
  }
  CFileLibrary::pFreeFLCreationData(this);
  CFileLibrary::pFreeFLData(this);
  while ( this->m_pFLFHandleStart )
  {
    m_pFLFHandleStart = (struct FLFHandleStruct **)this->m_pFLFHandleStart;
    this->m_pFLFHandleStart = m_pFLFHandleStart[2];
    operator delete(m_pFLFHandleStart);
  }
  return std::vector<std::pair<std::wstring,int>>::~vector<std::pair<std::wstring,int>>();
}


// address=[0x2f08050]
// Decompiled from bool __stdcall CFileLibrary::pCutPathAndFilename(wchar_t *String, wchar_t *_swpPath, wchar_t *_swpName)
bool  CFileLibrary::pCutPathAndFilename(wchar_t const * String, wchar_t * _swpPath, wchar_t * _swpName) {
  
  int v4; // [esp+8h] [ebp-8h]
  signed int i; // [esp+Ch] [ebp-4h]
  int v6; // [esp+Ch] [ebp-4h]

  wcslen(String);
  if ( *String == '\\' )
    wcscpy(_swpPath, String + 1);
  else
    wcscpy(_swpPath, String);
  v4 = 0;
  for ( i = wcslen(_swpPath) - 1; i >= 0 && _swpPath[i] != 92; --i )
    ++v4;
  if ( v4 )
  {
    v6 = wcslen(_swpPath) - v4;
    if ( v6 > 1 )
    {
      memmove(_swpName, &_swpPath[v6], v4 + 1);
      _swpPath[v6 - 1] = 0;
    }
    else
    {
      wcscpy(_swpName, _swpPath);
      *_swpPath = 0;
    }
    return 1;
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::pCutPathAndFilename\t:\tcouldn't get file name, %s", (const char *)String);
    return 0;
  }
}


// address=[0x2f08230]
// Decompiled from void *__thiscall CFileLibrary::pGetFileLibraryHandle(CFileLibrary *this, int a2)
void *  CFileLibrary::pGetFileLibraryHandle(int a2) {
  
  struct FLFHandleStruct *j; // [esp+4h] [ebp-10h]
  struct FLFHandleStruct *i; // [esp+8h] [ebp-Ch]
  void *hFile; // [esp+Ch] [ebp-8h]
  HANDLE hFilea; // [esp+Ch] [ebp-8h]
  HANDLE hFileb; // [esp+Ch] [ebp-8h]

  if ( a2 < 0 || a2 >= this->m_iLibraryFilesCount )
    return (void *)-1;
  if ( this->m_pLibraryFiles[a2].m_hFile )
    hFile = this->m_pLibraryFiles[a2].m_hFile;
  else
    hFile = (void *)-1;
  if ( hFile == (void *)-1 )
  {
    if ( this->m_iFLFHandleCount )
    {
      for ( i = this->m_pFLFHandleStart; i && i->m_uId != -1; i = i->m_pNext )
        ;
      if ( i->m_uId == -1 )
      {
        hFilea = CreateFileW(this->m_pLibraryFiles[a2].m_swpFileName, 0x80000000, 1u, 0, 3u, 0x80u, 0);
        if ( hFilea == (HANDLE)-1 )
        {
          BBSupportTracePrintF(
            3,
            "CFileLibrary::pGetFileLibraryHandle\t:\tFailed to open lib file %s ",
            (const char *)this->m_pLibraryFiles[a2].m_swpFileName);
          return (void *)-1;
        }
        else
        {
          this->m_pLibraryFiles[a2].m_hFile = hFilea;
          this->m_pLibraryFiles[a2].m_uFileSize = GetFileSize(hFilea, 0);
          i->m_uId = a2;
          --this->m_iFLFHandleCount;
          CFileLibrary::pMoveHandleToBeginning(this, i);
          return hFilea;
        }
      }
      else
      {
        return (void *)-1;
      }
    }
    else
    {
      hFileb = CreateFileW(this->m_pLibraryFiles[a2].m_swpFileName, 0x80000000, 1u, 0, 3u, 0x80u, 0);
      if ( hFileb == (HANDLE)-1 )
      {
        BBSupportTracePrintF(
          3,
          "CFileLibrary::pGetFileLibraryHandle\t:\tFailed to open lib file %s ",
          (const char *)this->m_pLibraryFiles[a2].m_swpFileName);
        return (void *)-1;
      }
      else
      {
        CloseHandle(this->m_pLibraryFiles[this->m_pFLFHandleEnd->m_uId].m_hFile);
        this->m_pFLFHandleEnd->m_uId = a2;
        this->m_pLibraryFiles[a2].m_hFile = hFileb;
        CFileLibrary::pMoveHandleToBeginning(this, this->m_pFLFHandleEnd);
        return hFileb;
      }
    }
  }
  else
  {
    for ( j = this->m_pFLFHandleStart; j && j->m_uId != a2; j = j->m_pNext )
      ;
    CFileLibrary::pMoveHandleToBeginning(this, j);
    return hFile;
  }
}


// address=[0x2f08480]
// Decompiled from int __thiscall CFileLibrary::pC_CopyFile(  CFileLibrary *this,  LPCWSTR lpFileName,  HANDLE a2,  signed int nNumberOfBytesToRead,  struct FLCopyProgressStruct *_pCopyProgress)
int  CFileLibrary::pC_CopyFile(wchar_t const * lpFileName, void * a2, int nNumberOfBytesToRead, struct FLCopyProgressStruct * _pCopyProgress) {
  
  DWORD NumberOfBytesRead; // [esp+14h] [ebp-14h] BYREF
  int success; // [esp+18h] [ebp-10h]
  LPVOID lpBuffer; // [esp+1Ch] [ebp-Ch]
  HANDLE hFile; // [esp+20h] [ebp-8h]
  DWORD NumberOfBytesWritten; // [esp+24h] [ebp-4h] BYREF

  hFile = CreateFileW(lpFileName, 0x80000000, 1u, 0, 3u, 0x80u, 0);
  if ( hFile == (HANDLE)-1 )
  {
    BBSupportTracePrintF(3, "CFileLibrary::pC_CopyFile\t:\tFile not found %s", (const char *)lpFileName);
    return 6;
  }
  success = 6;
  if ( (_pCopyProgress->m_uFlags & FLFF_Compressed) != 0 )
  {                                             // Compression
    if ( (_pCopyProgress->m_uFlags & FLFF_Encrypted) != 0 )
      NumberOfBytesWritten = CFileLibrary::pC_PackFile(this, a2, hFile, &_pCopyProgress->m_uCRC, 1);
    else
      NumberOfBytesWritten = CFileLibrary::pC_PackFile(this, a2, hFile, &_pCopyProgress->m_uCRC, 0);
    if ( !NumberOfBytesWritten )
      return 6;
    _pCopyProgress->m_uU1C = NumberOfBytesWritten;
    _pCopyProgress->m_uU0 = NumberOfBytesWritten;
    _pCopyProgress->m_uU8 += NumberOfBytesWritten;
    ++_pCopyProgress->m_uU10;
    success = 0;
  }
  else
  {                                             // Straight copy over buffer
    if ( nNumberOfBytesToRead >= 0x4000 )
      lpBuffer = operator new[](nNumberOfBytesToRead);
    else
      lpBuffer = operator new[](0x4000u);
    _pCopyProgress->m_uU0 = 0;
    _pCopyProgress->m_uU1C = 0;
    while ( ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, &NumberOfBytesRead, 0) )
    {
      if ( !NumberOfBytesRead )
      {
        ++_pCopyProgress->m_uU10;
        success = 0;
        break;
      }
      WriteFile(a2, lpBuffer, NumberOfBytesRead, &NumberOfBytesWritten, 0);
      if ( NumberOfBytesWritten < NumberOfBytesRead )
      {
        success = 5;
        break;
      }
      _pCopyProgress->m_uU1C += NumberOfBytesWritten;
      _pCopyProgress->m_uU0 += NumberOfBytesWritten;
      _pCopyProgress->m_uU8 += NumberOfBytesWritten;
    }
    _pCopyProgress->m_uCRC = 0;
    operator delete[](lpBuffer);
  }
  CloseHandle(hFile);
  return success;
}


// address=[0x2f08690]
// Decompiled from DWORD __thiscall CFileLibrary::pC_PackFile(CFileLibrary *this, HANDLE a2, HANDLE hFile, unsigned int *_pCRC, char a5)
int  CFileLibrary::pC_PackFile(void * a2, void * hFile, unsigned int * _pCRC, bool a5) {
  
  DWORD NumberOfBytesWritten; // [esp+8h] [ebp-2Ch] BYREF
  char *pWriteBuffer; // [esp+10h] [ebp-24h] MAPDST
  size_t uCompressedSize; // [esp+14h] [ebp-20h]
  LPVOID pReadBuffer; // [esp+18h] [ebp-1Ch] MAPDST
  LZHLCompressor *pCompressor; // [esp+1Ch] [ebp-18h]
  DWORD uAcutallyReadSize; // [esp+20h] [ebp-14h] BYREF
  DWORD uReadSize; // [esp+28h] [ebp-Ch]
  DWORD nNumberOfBytesToWrite; // [esp+30h] [ebp-4h]

  pCompressor = j__LZHLCreateCompressor();
  nNumberOfBytesToWrite = 0;
  uReadSize = GetFileSize(hFile, 0);
  uCompressedSize = j__LZHLCompressorCalcMaxBuf(uReadSize);
  pReadBuffer = operator new[](uReadSize);
  pWriteBuffer = (char *)operator new[](uCompressedSize);
  ReadFile(hFile, pReadBuffer, uReadSize, &uAcutallyReadSize, 0);
  if ( uAcutallyReadSize == uReadSize )
  {
    nNumberOfBytesToWrite = 0;
    nNumberOfBytesToWrite = j__LZHLCompress(pCompressor, pWriteBuffer, pReadBuffer, uAcutallyReadSize);
    if ( a5 )
      CFileLibrary::DataCryptor(pWriteBuffer, nNumberOfBytesToWrite);
    *_pCRC = CFileLibrary::CRC(this, pWriteBuffer, nNumberOfBytesToWrite);
    WriteFile(a2, pWriteBuffer, nNumberOfBytesToWrite, &NumberOfBytesWritten, 0);
    if ( NumberOfBytesWritten == nNumberOfBytesToWrite )
    {
      j__LZHLDestroyCompressor(pCompressor);
      operator delete[](pReadBuffer);
      operator delete[](pWriteBuffer);
      return nNumberOfBytesToWrite;
    }
    else
    {
      BBSupportTracePrintF(3, "CFileLibrary::pC_PackFile : Could't write complete file.");
      return 0;
    }
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::pC_PackFile : Could't read complete file.");
    return 0;
  }
}


// address=[0x2f087f0]
// Decompiled from int __thiscall CFileLibrary::UnpackData(  CFileLibrary *this,  char *_pDst,  int _uDstSize,  char *_pSrc,  int _uSrcSize,  bool isEncrypted)
int  CFileLibrary::UnpackData(char * _pDst, int _uDstSize, char * _pSrc, int _uSrcSize, bool isEncrypted) {
  
  DWORD v7; // [esp+0h] [ebp-38h] BYREF
  int bSucceeded; // [esp+14h] [ebp-24h]
  int pDecompressor; // [esp+24h] [ebp-14h]
  DWORD *v13; // [esp+28h] [ebp-10h]
  int exceptionBlock; // [esp+34h] [ebp-4h]

  v13 = &v7;
  if ( isEncrypted )
    CFileLibrary::DataCryptor(_pSrc, _uSrcSize);
  pDecompressor = j__LZHLCreateDecompressor();
  exceptionBlock = 0;
  bSucceeded = j__LZHLDecompress(pDecompressor, _pDst, &_uDstSize, _pSrc, &_uSrcSize);
  exceptionBlock = -1;
  j__LZHLDestroyDecompressor(pDecompressor);
  if ( bSucceeded )
    return _uDstSize;
  BBSupportTracePrintF(3, "CStringEngine::ImportFile : Error during decompressing text file. No strings loaded. ");
  return 0;
}


// address=[0x2f08fb0]
// Decompiled from void __thiscall CFileLibrary::pFreeFLCreationData(CFileLibrary *this)
void  CFileLibrary::pFreeFLCreationData(void) {
  
  FLFileListStruct *m_FileList; // [esp+8h] [ebp-2Ch]
  FLDirListStruct *m_pDirList; // [esp+14h] [ebp-20h]
  FLPathListStruct *m_pPathList; // [esp+20h] [ebp-14h]

  while ( this->m_pPathList )
  {
    m_pPathList = this->m_pPathList;
    this->m_pPathList = (FLPathListStruct *)m_pPathList->field_10;
    if ( m_pPathList )
      delete m_pPathList;
  }
  while ( this->m_pDirList )
  {
    m_pDirList = this->m_pDirList;
    this->m_pDirList = m_pDirList->m_pNext;
    if ( m_pDirList )
      delete m_pDirList;
  }
  while ( this->m_FileList )
  {
    m_FileList = this->m_FileList;
    this->m_FileList = m_FileList->m_pNext;
    if ( m_FileList )
      delete m_FileList;
  }
}


// address=[0x2f090a0]
// Decompiled from void __thiscall CFileLibrary::pFreeFLData(CFileLibrary *this)
void  CFileLibrary::pFreeFLData(void) {
  
  HANDLE hObject; // [esp+2Ch] [ebp-24h]
  int k; // [esp+30h] [ebp-20h]
  FLIntHandleStruct *o; // [esp+34h] [ebp-1Ch] MAPDST
  struct FLFHandleStruct *m; // [esp+38h] [ebp-18h]
  FLMemFileStruct *m_pFiles; // [esp+3Ch] [ebp-14h]
  struct FLMemDirStruct *m_pDirectories; // [esp+40h] [ebp-10h]
  FLLibraryFileStruct *m_pLibraryFiles; // [esp+44h] [ebp-Ch]
  int i; // [esp+48h] [ebp-8h]
  int j; // [esp+48h] [ebp-8h]
  int n; // [esp+48h] [ebp-8h]

  m_pLibraryFiles = this->m_pLibraryFiles;
  for ( i = 0; i < this->m_iLibraryFilesCount; ++i )
  {
    if ( m_pLibraryFiles->m_swpFileName )
      operator delete(m_pLibraryFiles->m_swpFileName);
    m_pLibraryFiles->m_swpFileName = 0;
    if ( m_pLibraryFiles->m_hFile )
    {
      hObject = m_pLibraryFiles->m_hFile;
      if ( hObject != (HANDLE)-1 )
        CloseHandle(hObject);
      m_pLibraryFiles->m_hFile = (void *)-1;
    }
    ++m_pLibraryFiles;
  }
  if ( this->m_pLibraryFiles )
    operator delete[](this->m_pLibraryFiles);
  this->m_pLibraryFiles = 0;
  this->m_iLibraryFilesCapacity = 0;
  this->m_iLibraryFilesCount = 0;
  m_pDirectories = this->m_pDirectories;
  for ( j = 0; j < this->m_iDirectoryCount; ++j )
  {
    if ( m_pDirectories->m_swpDirectoryName )
      operator delete[]((void *)m_pDirectories->m_swpDirectoryName);
    m_pFiles = m_pDirectories->m_pFiles;
    for ( k = 0; k < m_pDirectories->m_iFileCount; ++k )
    {
      if ( m_pFiles->m_pswName )
        operator delete[]((void *)m_pFiles->m_pswName);
      if ( m_pFiles->m_pFileData )
      {
        operator delete[](m_pFiles->m_pFileData);
        m_pFiles->m_pFileData = 0;
      }
      ++m_pFiles;
    }
    if ( m_pDirectories->m_pFiles )
      operator delete[](m_pDirectories->m_pFiles);
    ++m_pDirectories;
  }
  if ( this->m_pDirectories )
    operator delete[](this->m_pDirectories);
  this->m_pDirectories = 0;
  this->m_iDirectoryCount = 0;
  this->field_30 = 0;
  for ( m = this->m_pFLFHandleStart; m; m = m->m_pNext )
    m->m_uId = -1;
  for ( n = 0; n < 100; ++n )
  {
    for ( o = this->m_pFLIntHandle[n]; o; delete o
      o = o->m_pNextHandle;
    this->m_pFLIntHandle[n] = 0;
  }
  this->m_uHandleCount = 0;
}


// address=[0x2f09350]
// Decompiled from void __thiscall CFileLibrary::pOptimize(CFileLibrary *this)
void  CFileLibrary::pOptimize(void) {
  
  unsigned int m_iFileCount; // [esp+24h] [ebp-30h]
  struct FLMemDirStruct *v3; // [esp+2Ch] [ebp-28h]
  unsigned int m_iDirectoryCount; // [esp+30h] [ebp-24h]
  FLMemFileStruct *pMemFiles; // [esp+34h] [ebp-20h] MAPDST
  int i; // [esp+38h] [ebp-1Ch]
  struct FLMemDirStruct *v7; // [esp+3Ch] [ebp-18h]
  struct FLMemDirStruct *m_pDirectories; // [esp+40h] [ebp-14h]

  if ( this->m_pDirectories )
  {
    if ( this->m_iDirectoryCount != this->field_30 )
    {
      m_iDirectoryCount = this->m_iDirectoryCount;
      v7 = (struct FLMemDirStruct *)operator new[](16 * m_iDirectoryCount);
      if ( v7 )
      {
        _vec_ctor_no(v7, 0x10u, m_iDirectoryCount, (void *(__thiscall *)(void *))FLMemDirStruct::FLMemDirStruct);
        v3 = v7;
      }
      else
      {
        v3 = 0;
      }
      memmove(v3, this->m_pDirectories, 16 * this->m_iDirectoryCount);
      operator delete[](this->m_pDirectories);
      this->m_pDirectories = v3;
      this->field_30 = this->m_iDirectoryCount;
    }
    qsort(
      this->m_pDirectories,
      this->m_iDirectoryCount,
      0x10u,
      (_CoreCrtNonSecureSearchSortCompareFunction)CFileLibrary::sDirCompare_qsort);
    this->field_1D8 |= 1u;
    m_pDirectories = this->m_pDirectories;
    for ( i = 0; i < this->m_iDirectoryCount; ++i )
    {
      if ( m_pDirectories->m_pFiles )
      {
        if ( m_pDirectories->m_iReadFileCount != m_pDirectories->m_iFileCount )
        {
          m_iFileCount = m_pDirectories->m_iFileCount;
          pMemFiles = (FLMemFileStruct *)operator new[](32 * m_iFileCount);
          if ( pMemFiles )
            _vec_ctor_no(pMemFiles, 0x20u, m_iFileCount, (void *(__thiscall *)(void *))FLMemFileStruct::FLMemFileStruct);
          else
            pMemFiles = 0;
          memmove(pMemFiles, m_pDirectories->m_pFiles, 32 * m_pDirectories->m_iFileCount);
          operator delete[](m_pDirectories->m_pFiles);
          m_pDirectories->m_pFiles = pMemFiles;
          m_pDirectories->m_iReadFileCount = m_pDirectories->m_iFileCount;
        }
        qsort(m_pDirectories->m_pFiles, m_pDirectories->m_iFileCount, 0x20u, CFileLibrary::sFileCompare_qsort);
        m_pDirectories->m_uFlags |= FLFF_Compressed;
      }
      ++m_pDirectories;
    }
  }
}


// address=[0x2f095f0]
// Decompiled from DWORD __thiscall CFileLibrary::LoadEntireFile(  CFileLibrary *this,  unsigned int a2,  char *_pData,  int _iCRC,  bool _bDisableEncryption)
int  CFileLibrary::LoadEntireFile(unsigned int a2, void * _pData, unsigned int _iCRC, int _bDisableEncryption) {
  
  FLMemFileStruct::FileFlags m_iFlags; // [esp+14h] [ebp-1Ch]
  HANDLE hFile; // [esp+18h] [ebp-18h]
  int v8; // [esp+1Ch] [ebp-14h]
  DWORD NumberOfBytesRead; // [esp+20h] [ebp-10h] BYREF
  LPVOID compressedData; // [esp+24h] [ebp-Ch]
  FLIntHandleStruct *IntHandlePtr; // [esp+2Ch] [ebp-4h]

  ++this->m_iRefCount;
  ++this->m_iFileInteractions;
  IntHandlePtr = CFileLibrary::pGetIntHandlePtr(this, a2);
  if ( IntHandlePtr )
  {
    hFile = CFileLibrary::pGetFileLibraryHandle(this, IntHandlePtr->m_pLibraryFile->m_iLibraryIndex);
    if ( hFile == (HANDLE)-1 )
    {
      BBSupportTracePrintF(3, "CFileLibrary::LoadEntireFile\t:\tInvalid lib file handle");
      return -1;
    }
    else if ( SetFilePointer(hFile, IntHandlePtr->m_pLibraryFile->m_iFileOffset, 0, FILE_BEGIN) == -1 )
    {
      BBSupportTracePrintF(3, "CFileLibrary::LoadEntireFile\t:\tfailed to set file ptr");
      return -1;
    }
    else
    {
      m_iFlags = IntHandlePtr->m_pLibraryFile->m_iFlags;
      if ( _bDisableEncryption )
        LOBYTE(m_iFlags) = 0;
      if ( (m_iFlags & FLFF_Compressed) != 0 )
      {
        compressedData = operator new[](IntHandlePtr->m_pLibraryFile->m_iFileSize);
        ReadFile(hFile, compressedData, IntHandlePtr->m_pLibraryFile->m_iFileSize, &NumberOfBytesRead, 0);
        if ( IntHandlePtr->m_pLibraryFile->m_iFileSize == NumberOfBytesRead )
        {
          if ( CFileLibrary::CRC(this, compressedData, IntHandlePtr->m_pLibraryFile->m_iFileSize) == _iCRC )
          {
            if ( (m_iFlags & FLFF_Encrypted) != 0 )
              v8 = CFileLibrary::UnpackData(
                     this,
                     _pData,
                     IntHandlePtr->m_pLibraryFile->m_iDecompressedSize,
                     (char *)compressedData,
                     NumberOfBytesRead,
                     1);
            else
              v8 = CFileLibrary::UnpackData(
                     this,
                     _pData,
                     IntHandlePtr->m_pLibraryFile->m_iDecompressedSize,
                     (char *)compressedData,
                     NumberOfBytesRead,
                     0);
            operator delete[](compressedData);
            if ( v8 )
            {
              this->m_iDecompressedBytesRead += v8;
              return v8;
            }
            else
            {
              BBSupportTracePrintF(3, "CFileLibrary::LoadEntireFile\t:\tFailed to unpack data");
              return -1;
            }
          }
          else
          {
            operator delete[](compressedData);
            BBSupportTracePrintF(
              3,
              "CFileLibrary::LoadEntireFile\t:\tCRC error in %s",
              IntHandlePtr->m_pLibraryFile->m_pswName);
            return -1;
          }
        }
        else
        {
          operator delete[](compressedData);
          BBSupportTracePrintF(3, "CFileLibrary::LoadEntireFile\t:\tFailed to read file for decompressing");
          return -1;
        }
      }
      else
      {
        ReadFile(hFile, _pData, IntHandlePtr->m_pLibraryFile->m_iFileSize, &NumberOfBytesRead, 0);
        if ( (m_iFlags & FLFF_Encrypted) != 0 )
          CFileLibrary::DataCryptor(_pData, IntHandlePtr->m_pLibraryFile->m_iFileSize);
        this->m_iDecompressedBytesRead += NumberOfBytesRead;
        return NumberOfBytesRead;
      }
    }
  }
  else
  {
    BBSupportTracePrintF(3, "CFileLibrary::LoadEntireFile\t:\tNo file with this handle");
    return -1;
  }
}


// address=[0x2f09890]
// Decompiled from void __cdecl CFileLibrary::DataCryptor(char *_pData, int _iDataSize)
void __cdecl CFileLibrary::DataCryptor(void * _pData, int _iDataSize) {
  
  int i; // [esp+8h] [ebp-7Ch]
  _DWORD v3[19]; // [esp+Ch] [ebp-78h] BYREF
  _BYTE v4[28]; // [esp+58h] [ebp-2Ch] BYREF
  int exceptionBlock; // [esp+80h] [ebp-4h]

  Cryptor::Cryptor((Cryptor *)v3);
  exceptionBlock = 0;
  std::string::string((struct std::string *)v4, "01234567890123456789");
  LOBYTE(exceptionBlock) = 1;
  Cryptor::Set_Key(v3, (int)v4);
  for ( i = 0; i < _iDataSize; ++i )
    Cryptor::Transform_Char((Cryptor *)v3, (unsigned __int8 *)&_pData[i]);
  LOBYTE(exceptionBlock) = 0;
  std::string::~string(v4);
  exceptionBlock = -1;
  Cryptor::~Cryptor((Cryptor *)v3);
}


// address=[0x2f09950]
// Decompiled from unsigned int __thiscall CFileLibrary::CRC(CFileLibrary *this, _BYTE *a2, int a3)
unsigned int  CFileLibrary::CRC(void * a2, int a3) {
  
  unsigned int NormalCRC; // [esp+Ch] [ebp-Ch]
  int v5; // [esp+10h] [ebp-8h] BYREF
  int i; // [esp+14h] [ebp-4h]

  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::CRCGenerator<16,32773,0,0,1,1>(&v5);
  cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Reset((std::_Basic_container_proxy_ptr12 *)&v5);
  for ( i = 0; i < a3; ++i )
    cdm_crc::CRCGenerator<16,32773,0,0,1,1>::Process(&v5, a2[i]);
  NormalCRC = cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetNormalCRC(&v5);
  return NormalCRC >> (32 - cdm_crc::CRCGenerator<16,32773,0,0,1,1>::GetWidth(&v5));
}


#endif // Already implemented
