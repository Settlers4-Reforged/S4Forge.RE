#if FALSE
#include "CFileEx.h"

// Definitions for class CFileEx

// address=[0x135cb10]
// Decompiled from CFileEx *__thiscall CFileEx::CFileEx(CFileEx *this, int a2)
 CFileEx::CFileEx(void a2) {
  
  if ( a2 )
  {
    this->m_pVbtable = (vbtable *)&CFileEx::_vbtable_;
    IFileEx::IFileEx(&this->IFileEx);
  }
  CFile::CFile(&this->CFile);
  this->CFile.__vftable = (IFSNode_vtbl *)&CFileEx::_vftable_;
  *(vbtable **)((char *)&this->m_pVbtable + this->m_pVbtable->virtualBaseOffsets[0]) = (vbtable *)&CFileEx::`vftable';
  *(FILE **)((char *)&this->CFile.m_hFile + this->m_pVbtable->virtualBaseOffsets[0]) = (FILE *)(this->m_pVbtable->virtualBaseOffsets[0]
                                                                                              - 32);
  this->CFile.m_bTextMode = 1;
  this->m_hFileMemoryHandle = 0;
  this->m_pFileMemoryMap = 0;
  this->m_bFileLibraryHandled = 0;
  this->m_bMemoryMapped = 0;
  this->CFile.m_hFile = 0;
  this->m_uSize = 0;
  this->m_uReadOffset = 0;
  return this;
}


// address=[0x135d430]
// Decompiled from int __thiscall CFileEx::_CFileEx(_DWORD *this)
 CFileEx::~CFileEx(void) {
  
  *this = CFileEx::_vftable_;
  *(_DWORD *)((char *)this + *(_DWORD *)(this[18] + 4) + 72) = &CFileEx::`vftable';
  *(_DWORD *)((char *)this + *(_DWORD *)(this[18] + 4) + 68) = *(_DWORD *)(this[18] + 4) - 32;
  CFileEx::Close("D:\\Projects\\TSHE\\PurpleLamp\\S4\\source\\BaseLib\\Include\\FileEx.h", 146);
  return CFile::~CFile();
}


// address=[0x1496960]
// Decompiled from bool __thiscall CFileEx::InLibrary(CFileEx *this)
bool  CFileEx::InLibrary(void)const {
  
  return this->m_bFileLibraryHandled;
}


// address=[0x2f01710]
// Decompiled from CFileEx *__thiscall CFileEx::CFileEx(CFileEx *this, std::wstring *a2, int a3, char a4, int a5)
 CFileEx::CFileEx(std::wstring const & a2, unsigned int a3, bool a4) {
  
  wchar_t *v5; // eax
  CFileEx v8; // [esp+8h] [ebp-7Ch] BYREF
  int v9; // [esp+80h] [ebp-4h]

  if ( a5 )
  {
    this->m_pVbtable = (vbtable *)&CFileEx::_vbtable_;
    IFileEx::IFileEx(&this->IFileEx);
  }
  CFile::CFile(&this->CFile);
  v9 = 0;
  this->CFile.__vftable = (IFSNode_vtbl *)&CFileEx::_vftable_;
  *(vbtable **)((char *)&this->m_pVbtable + this->m_pVbtable->virtualBaseOffsets[0]) = (vbtable *)&CFileEx::`vftable';
  *(FILE **)((char *)&this->CFile.m_hFile + this->m_pVbtable->virtualBaseOffsets[0]) = (FILE *)(this->m_pVbtable->virtualBaseOffsets[0]
                                                                                              - 32);
  v5 = std::wstring::c_str(a2);
  CFileEx::CFileEx(&v8, v5, a3, a4, 1);
  CFileEx::~CFileEx(&v8);
  return this;
}


// address=[0x2f017f0]
// Decompiled from CFileEx *__thiscall CFileEx::CFileEx(CFileEx *this, wchar_t *FileName, int a2, char a4, __unused int a5)
 CFileEx::CFileEx(wchar_t const * FileName, unsigned int a2, bool a4) {
  
  if ( a5 )
  {
    this->m_pVbtable = (vbtable *)&CFileEx::_vbtable_;
    IFileEx::IFileEx(&this->IFileEx);
  }
  CFile::CFile(&this->CFile);
  this->CFile.__vftable = (IFSNode_vtbl *)&CFileEx::_vftable_;
  *(vbtable **)((char *)&this->m_pVbtable + this->m_pVbtable->virtualBaseOffsets[0]) = (vbtable *)&CFileEx::`vftable';
  *(FILE **)((char *)&this->CFile.m_hFile + this->m_pVbtable->virtualBaseOffsets[0]) = (FILE *)(this->m_pVbtable->virtualBaseOffsets[0]
                                                                                              - 32);
  if ( !a2 )
    return this;
  this->m_hFileMemoryHandle = 0;
  this->m_pFileMemoryMap = 0;
  this->m_bFileLibraryHandled = 0;
  this->m_bMemoryMapped = 0;
  this->CFile.m_hFile = 0;
  this->m_uSize = 0;
  this->m_uReadOffset = 0;
  CFileEx::Open(&this->IFileEx, FileName, (CFile::Mode)a2, a4, UNUSED_ARG(), UNUSED_ARG());
  return this;
}


// address=[0x2f01900]
// Decompiled from int __thiscall CFileEx::Open(  IFileEx *__shifted(CFileEx,0x68) this,  std::wstring *a2,  int a3,  unsigned __int8 a4,  int a5,  int a6)
void  CFileEx::Open(std::wstring const & a2, unsigned int a3, bool a4, char * a5, int a6) {
  
  wchar_t *v6; // eax

  v6 = std::wstring::c_str(a2);                 // Call to CFileEx->Open with wchar_t*
  return (**(int (__thiscall ***)(char *, wchar_t *, int, _DWORD, int, int))((char *)&ADJ(this)->m_pVbtable
                                                                           + ADJ(this)->m_pVbtable->virtualBaseOffsets[offsetof(vbtable, topOffset)]))(
           (char *)&ADJ(this)->m_pVbtable + ADJ(this)->m_pVbtable->virtualBaseOffsets[offsetof(vbtable, topOffset)],
           v6,
           a3,
           a4,
           a5,
           a6);
}


// address=[0x2f01950]
// Decompiled from void __thiscall CFileEx::Open(  IFileEx *__shifted(CFileEx,0x68) this,  wchar_t *FileName,  CFile::Mode _uFileMask,  char a4,  char *Str,  int a6)
void  CFileEx::Open(wchar_t const * FileName, unsigned int _uFileMask, bool a4, char * Str, int a6) {
  
  wchar_t *v6; // eax
  _BYTE pExceptionObject[552]; // [esp+8h] [ebp-254h] BYREF
  std::wstring v9; // [esp+230h] [ebp-2Ch] BYREF
  int v10; // [esp+258h] [ebp-4h]

  ADJ(this)->m_bFileLibraryHandled = 0;
  if ( a4 )
  {                                             // ->MapFile (?)
    ((void (__thiscall *)(char *, wchar_t *, char *, int))(*(vbtable **)((char *)&ADJ(this)->m_pVbtable
                                                                       + ADJ(this)->m_pVbtable->virtualBaseOffsets[offsetof(vbtable, topOffset)]))->virtualBaseOffsets[1])(
      (char *)&ADJ(this)->m_pVbtable + ADJ(this)->m_pVbtable->virtualBaseOffsets[offsetof(vbtable, topOffset)],
      FileName,
      Str,
      a6);
  }
  else
  {
    std::wstring::wstring(&v9);
    v10 = 0;
    CFile::OpenMaskToCWStr(&ADJ(this)->CFile, _uFileMask, (char *)&v9);
    v6 = std::wstring::c_str(&v9);
    ADJ(this)->CFile.m_hFile = (FILE *)CFileMgr::Open(FileName, v6, Str, a6);
    if ( !ADJ(this)->CFile.m_hFile )
    {
      ADJ(this)->m_uFileLibraryHandle = CFileLibrary::FileOpen(&g_cFileLibrary, FileName, 0);
      if ( ADJ(this)->m_uFileLibraryHandle == -1 )
      {
        CBBFileException::CBBFileException((CBBFileException *)pExceptionObject, 2, FileName);
        _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVCBBFileException__);
      }
      ADJ(this)->m_bFileLibraryHandled = 1;
      ADJ(this)->m_uSize = CFileLibrary::FileSize(&g_cFileLibrary, ADJ(this)->m_uFileLibraryHandle);
    }
    v10 = -1;
    std::wstring::~wstring(&v9);
  }
}


// address=[0x2f01ad0]
// Decompiled from int __thiscall CFileEx::MapFile(IFileEx *__shifted(CFileEx,0x68) this, WCHAR *lpFileName, const char *a3, int a4)
int  CFileEx::MapFile(wchar_t const * lpFileName, char * a3, int a4) {
  
  DWORD LastError; // eax
  DWORD v6; // eax
  unsigned int v7; // [esp+0h] [ebp-33Ch]
  HANDLE hFileMappingObject; // [esp+4h] [ebp-338h]
  HANDLE hFile; // [esp+8h] [ebp-334h]
  char pExceptionObject[552]; // [esp+10h] [ebp-32Ch] BYREF
  char v12[128]; // [esp+238h] [ebp-104h] BYREF
  char Buffer[128]; // [esp+2B8h] [ebp-84h] BYREF

  ADJ(this)->m_bFileLibraryHandled = 0;
  hFile = CreateFileW(lpFileName, 0x80000000, 1u, 0, 3u, 0, 0);
  if ( hFile == (HANDLE)-1 )
  {
    v7 = CFileLibrary::FileOpen(&g_cFileLibrary, lpFileName, 0);
    if ( v7 == -1 )
    {
      DEBUGLIB::Error("CFile::MapFile can't open file `%s'", a3, a4, lpFileName);
      CBBFileException::CBBFileException((CBBFileException *)pExceptionObject, 2, lpFileName);
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVCBBFileException__);
    }
    ADJ(this)->m_uSize = CFileLibrary::FileSize(&g_cFileLibrary, v7);
    ADJ(this)->m_pFileMemoryMap = (char *)CFileLibrary::MapFile(&g_cFileLibrary, v7);
    CFileLibrary::FileClose(&g_cFileLibrary, v7);
    ADJ(this)->m_bFileLibraryHandled = 1;
    ADJ(this)->m_bMemoryMapped = 1;
    return 1;
  }
  else
  {
    ADJ(this)->m_uSize = GetFileSize(hFile, 0);
    hFileMappingObject = CreateFileMappingA(hFile, 0, 2u, 0, 0, 0);
    if ( hFileMappingObject == (HANDLE)-1 )
    {
      LastError = GetLastError();
      snprintf(Buffer, 0x80u, "Unable map file . LastError was: %d", LastError);
      DEBUGLIB::Error(Buffer, a3, a4);
      CloseHandle(hFile);
      return 0;
    }
    else
    {
      ADJ(this)->m_pFileMemoryMap = (char *)MapViewOfFile(hFileMappingObject, 4u, 0, 0, 0);
      if ( ADJ(this)->m_pFileMemoryMap )
      {
        ADJ(this)->m_hFileMemoryHandle = (int)hFileMappingObject;
        ADJ(this)->m_bMemoryMapped = 1;
        CloseHandle(hFile);
        return 1;
      }
      else
      {
        v6 = GetLastError();
        snprintf(v12, 0x80u, "Unable map view of file. LastError was: %d", v6);
        DEBUGLIB::Error(v12, a3, a4);
        CloseHandle(hFileMappingObject);
        CloseHandle(hFile);
        return 0;
      }
    }
  }
}


// address=[0x2f01d30]
// Decompiled from char *__thiscall CFileEx::GetMapFilePtr(IFileEx *__shifted(CFileEx,0x68) this)
void *  CFileEx::GetMapFilePtr(void) {
  
  return ADJ(this)->m_pFileMemoryMap;
}


// address=[0x2f01d50]
// Decompiled from size_t __thiscall CFileEx::Read(  IFileEx *__shifted(CFileEx,0x68) this,  void *Buffer,  int ElementSize,  int ElementCount,  const char *a5,  int a6)
unsigned int  CFileEx::Read(void * Buffer, int ElementSize, int ElementCount, char * a5, int a6) {
  
  int uBytesRead; // [esp+0h] [ebp-238h]
  int uSizeToRead; // [esp+4h] [ebp-234h]
  _BYTE pExceptionObject[552]; // [esp+Ch] [ebp-22Ch] BYREF

  uSizeToRead = ElementCount * ElementSize;
  if ( ADJ(this)->m_bMemoryMapped )
  {
    if ( uSizeToRead + ADJ(this)->m_uReadOffset > ADJ(this)->m_uSize )
    {
      DEBUGLIB::Error(
        "CFileEx::Read : Read in filemapping exceeds map size. Offset %d, to read %d, size %d ",
        a5,
        a6,
        ADJ(this)->m_uReadOffset,
        uSizeToRead,
        ADJ(this)->m_uSize);
      uSizeToRead = ADJ(this)->m_uSize - ADJ(this)->m_uReadOffset;
      ElementCount = uSizeToRead / ElementSize;
    }
    memcpy(Buffer, &ADJ(this)->m_pFileMemoryMap[ADJ(this)->m_uReadOffset], uSizeToRead);
    ADJ(this)->m_uReadOffset += uSizeToRead;
  }
  if ( !ADJ(this)->m_bFileLibraryHandled )
    return CFile::Read(&ADJ(this)->CFile, Buffer, ElementSize, ElementCount, UNUSED_ARG(), UNUSED_ARG());
  uBytesRead = CFileLibrary::FileRead(&g_cFileLibrary, ADJ(this)->m_uFileLibraryHandle, (char *)Buffer, uSizeToRead);
  if ( uBytesRead == -1 )
  {
    CBBFileException::CBBFileException((CBBFileException *)pExceptionObject, 3, 0);
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVCBBFileException__);
  }
  if ( uBytesRead != uSizeToRead )
    return uBytesRead / ElementSize;
  return ElementCount;
}


// address=[0x2f01ef0]
// Decompiled from unsigned int __thiscall CFileEx::Write(  IFileEx *__shifted(CFileEx,0x68) this,  void *Buffer,  size_t ElementSize,  size_t ElementCount,  char *a5,  int a6)
unsigned int  CFileEx::Write(void const * Buffer, int ElementSize, int ElementCount, char * a5, int a6) {
  
  if ( ADJ(this)->m_bFileLibraryHandled || ADJ(this)->m_bMemoryMapped )
    return 0;
  else
    return CFile::Write(&ADJ(this)->CFile, Buffer, ElementSize, ElementCount, UNUSED_ARG(), UNUSED_ARG());
}


// address=[0x2f01f40]
// Decompiled from int __thiscall CFileEx::Seek(IFileEx *__shifted(CFileEx,0x68) this, int Offset, int Origin, const char *a4, int a5)
int  CFileEx::Seek(int Offset, int Origin, char * a4, int a5) {
  
  if ( ADJ(this)->m_bMemoryMapped )
  {
    if ( Origin )
    {
      if ( Origin == 1 )
      {
        ADJ(this)->m_uReadOffset += Offset;
        if ( ADJ(this)->m_uReadOffset < ADJ(this)->m_uSize )
        {
          return 0;
        }
        else
        {
          DEBUGLIB::Error("fseek offset (%ld) lies beyond file, mode SEEK_CUR", a4, a5, ADJ(this)->m_uReadOffset);
          return 1;
        }
      }
      else if ( Origin == 2 )
      {
        ADJ(this)->m_uReadOffset = ADJ(this)->m_uSize + Offset - 1;
        if ( ADJ(this)->m_uReadOffset >= 0 )
        {
          if ( ADJ(this)->m_uReadOffset < ADJ(this)->m_uSize )
          {
            return 0;
          }
          else
          {
            DEBUGLIB::Error("fseek offset (%ld) lies beyond file, mode SEEK_END", a4, a5, ADJ(this)->m_uReadOffset);
            return 1;
          }
        }
        else
        {
          DEBUGLIB::Error("Negative fseek offset (%ld) with mode SEEK_END", a4, a5, ADJ(this)->m_uReadOffset);
          return 1;
        }
      }
      else
      {
        DEBUGLIB::Error("Unknown fseek origin (%d)", a4, a5, Origin);
        return 1;
      }
    }
    else if ( Offset >= 0 )
    {
      if ( Offset < ADJ(this)->m_uSize )
      {
        ADJ(this)->m_uReadOffset = Offset;
        return 0;
      }
      else
      {
        DEBUGLIB::Error("fseek offset (%ld) lies beyond file, mode SEEK_SET", a4, a5, Offset);
        return 1;
      }
    }
    else
    {
      DEBUGLIB::Error("Negative fseek offset (%ld) with mode SEEK_SET", a4, a5, Offset);
      return 1;
    }
  }
  else if ( ADJ(this)->m_bFileLibraryHandled )
  {
    return CFileLibrary::FileSeek(&g_cFileLibrary, ADJ(this)->m_uFileLibraryHandle, Offset, Origin);
  }
  else
  {
    return CFile::Seek(Offset, Origin, (int)a4, a5);
  }
}


// address=[0x2f02120]
// Decompiled from int __thiscall CFileEx::Size(CFileEx *this)
int  CFileEx::Size(void)const {
  
  if ( this->m_bFileLibraryHandled || this->m_bMemoryMapped )
    return this->m_uSize;
  else
    return CFile::Size(this);
}


// address=[0x2f02160]
// Decompiled from int __thiscall CFileEx::Close(IFileEx *__shifted(CFileEx,0x68) this, char *a2, int a3)
int  CFileEx::Close(char * a2, int a3) {
  
  if ( ADJ(this)->m_bFileLibraryHandled )
  {
    if ( ADJ(this)->m_bMemoryMapped )
    {
      CFileLibrary::UnmapFile(&g_cFileLibrary, ADJ(this)->m_pFileMemoryMap);
      ADJ(this)->m_pFileMemoryMap = 0;
      ADJ(this)->m_bMemoryMapped = 0;
    }
    else
    {
      CFileLibrary::FileClose(&g_cFileLibrary, ADJ(this)->m_uFileLibraryHandle);
    }
    return 0;
  }
  else if ( ADJ(this)->m_bMemoryMapped )
  {
    UnmapViewOfFile(ADJ(this)->m_pFileMemoryMap);
    CloseHandle((HANDLE)ADJ(this)->m_hFileMemoryHandle);
    ADJ(this)->m_hFileMemoryHandle = 0;
    ADJ(this)->m_pFileMemoryMap = 0;
    ADJ(this)->m_bMemoryMapped = 0;
    return 0;
  }
  else
  {
    return CFile::Close(&ADJ(this)->CFile, UNUSED_ARG(), UNUSED_ARG());
  }
}


// address=[0x2f02220]
// Decompiled from void __thiscall CFileEx::Release(IFileEx *__shifted(CFileEx,0x68) this)
void  CFileEx::Release(void) {
  
  if ( this != (IFileEx *__shifted(CFileEx,0x68))0x68 )
    ADJ(this)->CFile.dtor(ADJ(this), 1);
}


#endif // Already implemented
