#include "CFileEx.h"

#include "CFileMgr.h"
#include "CFileLibrary.h"
#include "CBB/CBBFileException.h"
#include "CBB/CBBSupport.h"

// Definitions for class CFileEx

// address=[0x135cb10]
// Decompiled from CFileEx *__thiscall CFileEx::CFileEx(CFileEx *this, int a2)
CFileEx::CFileEx(void) : IFileEx(), CFile()
{

  this->m_bTextMode = 1;
  this->m_hFileMemoryHandle = 0;
  this->m_pFileMemoryMap = 0;
  this->m_bFileLibraryHandled = false;
  this->m_bMemoryMapped = false;
  this->m_hFile = 0;
  this->m_uSize = 0;
  this->m_uReadOffset = 0;
}

// address=[0x135d430]
// Decompiled from int __thiscall CFileEx::_CFileEx(_DWORD *this)
CFileEx::~CFileEx(void)
{
  this->Close(CFileLog);
}

// address=[0x1496960]
// Decompiled from bool __thiscall CFileEx::InLibrary(CFileEx *this)
bool CFileEx::InLibrary(void) const
{
  return this->m_bFileLibraryHandled;
}

// address=[0x2f01710]
// Decompiled from CFileEx *__thiscall CFileEx::CFileEx(CFileEx *this, std::wstring *a2, int a3, char a4, int a5)
CFileEx::CFileEx(std::wstring const &a2, unsigned int a3, bool a4) : CFileEx(a2.c_str(), a3, a4) {}

// address=[0x2f017f0]
// Decompiled from CFileEx *__thiscall CFileEx::CFileEx(CFileEx *this, wchar_t *FileName, int a2, char a4, int a5)
CFileEx::CFileEx(wchar_t const *FileName, unsigned int a3, bool a4) : CFile(), IFileEx()
{
  if (!a3)
    return;
  this->m_hFileMemoryHandle = 0;
  this->m_pFileMemoryMap = 0;
  this->m_bFileLibraryHandled = 0;
  this->m_bMemoryMapped = 0;
  this->m_hFile = 0;
  this->m_uSize = 0;
  this->m_uReadOffset = 0;
  this->Open(FileName, (CFile::Mode)a3, a4, CFileLog);
}

// address=[0x2f01900]
// Decompiled from int __thiscall CFileEx::Open(  IFileEx *__shifted(CFileEx,0x68) this,  std::wstring *a2,  int a3,  unsigned __int8 a4,  int a5,  int a6)
void CFileEx::Open(std::wstring const &a2, unsigned int _uFileMask, bool bUseMemoryMap, CFileLogAttributes)
{
  CFileEx::Open(a2.c_str(), _uFileMask, bUseMemoryMap, CFileLogFwd);
}

// address=[0x2f01950]
// Decompiled from void __thiscall CFileEx::Open(  IFileEx *__shifted(CFileEx,0x68) this,  wchar_t *FileName,  CFile::Mode _uFileMask,  char a4,  char *Str,  int a6)
void CFileEx::Open(wchar_t const *FileName, unsigned int _uFileMask, bool _bUseMemoryMap, CFileLogAttributes)
{

  wchar_t *v6;                 // eax
  _BYTE pExceptionObject[552]; // [esp+8h] [ebp-254h] BYREF
  std::wstring v9;             // [esp+230h] [ebp-2Ch] BYREF
  int v10;                     // [esp+258h] [ebp-4h]

  this->m_bFileLibraryHandled = 0;
  if (_bUseMemoryMap)
  { // ->MapFile (?)
    this->MapFile(FileName, CFileLog);
  }
  else
  {
    std::wstring swOpenMask{};
    this->OpenMaskToCWStr(_uFileMask, swOpenMask);
    this->m_hFile = CFileMgr::Open(FileName, swOpenMask.c_str(), CFileLog);
    if (!this->m_hFile)
    {
      this->m_uFileLibraryHandle = g_cFileLibrary->FileOpen(FileName, 0);
      if (this->m_uFileLibraryHandle == -1)
      {
        throw new CBBFileException(2, FileName);
      }
      this->m_bFileLibraryHandled = 1;
      this->m_uSize = g_cFileLibrary->FileSize(this->m_uFileLibraryHandle);
    }
  }
}

// address=[0x2f01ad0]
// Decompiled from int __thiscall CFileEx::MapFile(IFileEx *__shifted(CFileEx,0x68) this, WCHAR *lpFileName, const char *a3, int a4)
int CFileEx::MapFile(wchar_t const *lpFileName, CFileLogAttributes)
{

  DWORD LastError;            // eax
  DWORD v6;                   // eax
  unsigned int v7;            // [esp+0h] [ebp-33Ch]
  HANDLE hFileMappingObject;  // [esp+4h] [ebp-338h]
  HANDLE hFile;               // [esp+8h] [ebp-334h]
  char pExceptionObject[552]; // [esp+10h] [ebp-32Ch] BYREF
  char v12[128];              // [esp+238h] [ebp-104h] BYREF
  char Buffer[128];           // [esp+2B8h] [ebp-84h] BYREF

  this->m_bFileLibraryHandled = 0;
  hFile = CreateFileW(lpFileName, 0x80000000, 1u, 0, 3u, 0, 0);
  if (hFile == (HANDLE)-1)
  {
    v7 = g_cFileLibrary->FileOpen(lpFileName, 0);
    if (v7 == -1)
    {
      BBSupportTracePrintF(0, "CFile::MapFile can't open file `%s'", lpFileName);
      throw new CBBFileException(2, lpFileName);
    }
    this->m_uSize = g_cFileLibrary->FileSize(v7);
    this->m_pFileMemoryMap = (char *)g_cFileLibrary->MapFile(v7);
    g_cFileLibrary->FileClose(v7);
    this->m_bFileLibraryHandled = 1;
    this->m_bMemoryMapped = 1;
    return 1;
  }
  else
  {
    this->m_uSize = GetFileSize(hFile, 0);
    hFileMappingObject = CreateFileMappingA(hFile, 0, 2u, 0, 0, 0);
    if (hFileMappingObject == (HANDLE)-1)
    {
      LastError = GetLastError();
      snprintf(Buffer, 0x80u, "Unable map file . LastError was: %d", LastError);
      BBSupportTracePrintF(0, Buffer);
      CloseHandle(hFile);
      return 0;
    }
    else
    {
      this->m_pFileMemoryMap = (char *)MapViewOfFile(hFileMappingObject, 4u, 0, 0, 0);
      if (this->m_pFileMemoryMap)
      {
        this->m_hFileMemoryHandle = (int)hFileMappingObject;
        this->m_bMemoryMapped = 1;
        CloseHandle(hFile);
        return 1;
      }
      else
      {
        v6 = GetLastError();
        snprintf(v12, 0x80u, "Unable map view of file. LastError was: %d", v6);
        BBSupportTracePrintF(0, v12);
        CloseHandle(hFileMappingObject);
        CloseHandle(hFile);
        return 0;
      }
    }
  }
}

// address=[0x2f01d30]
// Decompiled from char *__thiscall CFileEx::GetMapFilePtr(IFileEx *__shifted(CFileEx,0x68) this)
void *CFileEx::GetMapFilePtr(void)
{

  return this->m_pFileMemoryMap;
}

// address=[0x2f01d50]
// Decompiled from size_t __thiscall CFileEx::Read(  IFileEx *__shifted(CFileEx,0x68) this,  void *Buffer,  int ElementSize,  int ElementCount,  const char *a5,  int a6)
unsigned int CFileEx::Read(void *Buffer, int ElementSize, int ElementCount, CFileLogAttributes)
{

  int uBytesRead;              // [esp+0h] [ebp-238h]
  int uSizeToRead;             // [esp+4h] [ebp-234h]
  _BYTE pExceptionObject[552]; // [esp+Ch] [ebp-22Ch] BYREF

  uSizeToRead = ElementCount * ElementSize;
  if (this->m_bMemoryMapped)
  {
    if (uSizeToRead + this->m_uReadOffset > this->m_uSize)
    {
      BBSupportTracePrintF(0,
                           "CFileEx::Read : Read in filemapping exceeds map size. Offset %d, to read %d, size %d ",
                           this->m_uReadOffset,
                           uSizeToRead,
                           this->m_uSize);
      uSizeToRead = this->m_uSize - this->m_uReadOffset;
      ElementCount = uSizeToRead / ElementSize;
    }
    memcpy(Buffer, &this->m_pFileMemoryMap[this->m_uReadOffset], uSizeToRead);
    this->m_uReadOffset += uSizeToRead;
  }
  if (!this->m_bFileLibraryHandled)
    return this->Read(Buffer, ElementSize, ElementCount, CFileLog);
  uBytesRead = g_cFileLibrary->FileRead(this->m_uFileLibraryHandle, (char *)Buffer, uSizeToRead);
  if (uBytesRead == -1)
  {
    throw new CBBFileException(3, nullptr);
  }
  if (uBytesRead != uSizeToRead)
    return uBytesRead / ElementSize;
  return ElementCount;
}

// address=[0x2f01ef0]
// Decompiled from unsigned int __thiscall CFileEx::Write(  IFileEx *__shifted(CFileEx,0x68) this,  void *Buffer,  size_t ElementSize,  size_t ElementCount,  char *a5,  int a6)
unsigned int CFileEx::Write(void const *Buffer, int ElementSize, int ElementCount, CFileLogAttributes)
{

  if (this->m_bFileLibraryHandled || this->m_bMemoryMapped)
    return 0;
  else
    return CFile::Write(Buffer, ElementSize, ElementCount, CFileLog);
}

// address=[0x2f01f40]
// Decompiled from int __thiscall CFileEx::Seek(IFileEx *__shifted(CFileEx,0x68) this, int Offset, int Origin, const char *a4, int a5)
int CFileEx::Seek(int Offset, int Origin, CFileLogAttributes)
{

  if (this->m_bMemoryMapped)
  {
    if (Origin)
    {
      if (Origin == 1)
      {
        this->m_uReadOffset += Offset;
        if (this->m_uReadOffset < this->m_uSize)
        {
          return 0;
        }
        else
        {
          BBSupportTracePrintF(0, "fseek offset (%ld) lies beyond file, mode SEEK_CUR", this->m_uReadOffset);
          return 1;
        }
      }
      else if (Origin == 2)
      {
        this->m_uReadOffset = this->m_uSize + Offset - 1;
        if (this->m_uReadOffset >= 0)
        {
          if (this->m_uReadOffset < this->m_uSize)
          {
            return 0;
          }
          else
          {
            BBSupportTracePrintF(0, "fseek offset (%ld) lies beyond file, mode SEEK_END", this->m_uReadOffset);
            return 1;
          }
        }
        else
        {
          BBSupportTracePrintF(0, "Negative fseek offset (%ld) with mode SEEK_END", this->m_uReadOffset);
          return 1;
        }
      }
      else
      {
        BBSupportTracePrintF(0, "Unknown fseek origin (%d)", Origin);
        return 1;
      }
    }
    else if (Offset >= 0)
    {
      if (Offset < this->m_uSize)
      {
        this->m_uReadOffset = Offset;
        return 0;
      }
      else
      {
        BBSupportTracePrintF(0, "fseek offset (%ld) lies beyond file, mode SEEK_SET", Offset);
        return 1;
      }
    }
    else
    {
      BBSupportTracePrintF(0, "Negative fseek offset (%ld) with mode SEEK_SET", Offset);
      return 1;
    }
  }
  else if (this->m_bFileLibraryHandled)
  {
    return g_cFileLibrary->FileSeek(this->m_uFileLibraryHandle, Offset, Origin);
  }
  else
  {
    return CFile::Seek(Offset, Origin, CFileLog);
  }
}

// address=[0x2f02120]
// Decompiled from int __thiscall CFileEx::Size(CFileEx *this)
int CFileEx::Size(void) const
{

  if (this->m_bFileLibraryHandled || this->m_bMemoryMapped)
    return this->m_uSize;
  else
    return CFile::Size();
}

// address=[0x2f02160]
// Decompiled from int __thiscall CFileEx::Close(IFileEx *__shifted(CFileEx,0x68) this, char *a2, int a3)
int CFileEx::Close(CFileLogAttributes)
{

  if (this->m_bFileLibraryHandled)
  {
    if (this->m_bMemoryMapped)
    {
      g_cFileLibrary->UnmapFile(this->m_pFileMemoryMap);
      this->m_pFileMemoryMap = 0;
      this->m_bMemoryMapped = 0;
    }
    else
    {
      g_cFileLibrary->FileClose(this->m_uFileLibraryHandle);
    }
    return 0;
  }
  else if (this->m_bMemoryMapped)
  {
    UnmapViewOfFile(this->m_pFileMemoryMap);
    CloseHandle((HANDLE)this->m_hFileMemoryHandle);
    this->m_hFileMemoryHandle = 0;
    this->m_pFileMemoryMap = 0;
    this->m_bMemoryMapped = 0;
    return 0;
  }
  else
  {
    return CFile::Close(CFileLog);
  }
}

// address=[0x2f02220]
// Decompiled from void __thiscall CFileEx::Release(IFileEx *__shifted(CFileEx,0x68) this)
void CFileEx::Release(void)
{
  CFile::~CFile();
}
