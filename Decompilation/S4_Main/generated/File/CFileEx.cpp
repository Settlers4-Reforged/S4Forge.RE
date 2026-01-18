#include "CFileEx.h"

// Definitions for class CFileEx

// address=[0x135cb10]
// Decompiled from CFileEx *__thiscall CFileEx::CFileEx(CFileEx *this, int a2)
 CFileEx::CFileEx(void a2) {
  
  if ( a2 )
  {
    *((_DWORD *)this + 18) = &CFileEx::_vbtable_;
    IFileEx::IFileEx((char *)this + 104);
  }
  CFile::CFile(this);
  *(_DWORD *)this = CFileEx::_vftable_;
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this + 18) + 4) + 72) = &CFileEx::`vftable';
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this + 18) + 4) + 68) = *(_DWORD *)(*((_DWORD *)this + 18) + 4)
                                                                           - 32;
  *((_DWORD *)this + 8) = 1;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_BYTE *)this + 80) = 0;
  *((_BYTE *)this + 81) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 19) = 0;
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
// Decompiled from char __thiscall CFileEx::InLibrary(CFileEx *this)
bool  CFileEx::InLibrary(void)const {
  
  return *((_BYTE *)this + 80);
}


// address=[0x2f01710]
// Decompiled from _DWORD *__thiscall CFileEx::CFileEx(_DWORD *this, _Cnd_internal_imp_t *a2, int a3, unsigned __int8 a4, int a5)
 CFileEx::CFileEx(std::wstring const & a2, unsigned int a3, bool a4) {
  
  wchar_t *v5; // eax
  _DWORD v8[31]; // [esp+8h] [ebp-7Ch] BYREF

  if ( a5 )
  {
    this[18] = &CFileEx::_vbtable_;
    IFileEx::IFileEx(this + 26);
  }
  CFile::CFile((CFile *)this);
  v8[30] = 0;
  *this = CFileEx::_vftable_;
  *(_DWORD *)((char *)this + *(_DWORD *)(this[18] + 4) + 72) = &CFileEx::`vftable';
  *(_DWORD *)((char *)this + *(_DWORD *)(this[18] + 4) + 68) = *(_DWORD *)(this[18] + 4) - 32;
  v5 = (wchar_t *)std::wstring::c_str(a2);
  CFileEx::CFileEx(v5, a3, a4, 1);
  CFileEx::~CFileEx(v8);
  return this;
}


// address=[0x2f017f0]
// Decompiled from CFileEx *__thiscall CFileEx::CFileEx(CFileEx *this, wchar_t *FileName, int a2, char a4, int a5)
 CFileEx::CFileEx(wchar_t const * FileName, unsigned int a3, bool a4) {
  
  if ( a5 )
  {
    *((_DWORD *)this + 18) = &CFileEx::_vbtable_;
    IFileEx::IFileEx((char *)this + 104);
  }
  CFile::CFile(this);
  *(_DWORD *)this = CFileEx::_vftable_;
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this + 18) + 4) + 72) = &CFileEx::`vftable';
  *(_DWORD *)((char *)this + *(_DWORD *)(*((_DWORD *)this + 18) + 4) + 68) = *(_DWORD *)(*((_DWORD *)this + 18) + 4)
                                                                           - 32;
  if ( !a2 )
    return this;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_BYTE *)this + 80) = 0;
  *((_BYTE *)this + 81) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 19) = 0;
  CFileEx::Open((_DWORD *)this + 26, FileName, a2, a4, UNUSED_ARG(), UNUSED_ARG());
  return this;
}


// address=[0x2f01900]
// Decompiled from int __thiscall CFileEx::Open(_DWORD *this, _Cnd_internal_imp_t *a2, int a3, unsigned __int8 a4, int a5, int a6)
void  CFileEx::Open(std::wstring const & a2, unsigned int a3, bool a4, char * a5, int a6) {
  
  _DWORD *v6; // eax

  v6 = std::wstring::c_str(a2);
  return (**(int (__thiscall ***)(int, _DWORD *, int, _DWORD, int, int))((char *)this + *(_DWORD *)(*(this - 8) + 4)
                                                                                      - 32))(
           (int)this + *(_DWORD *)(*(this - 8) + 4) - 32,
           v6,
           a3,
           a4,
           a5,
           a6);
}


// address=[0x2f01950]
// Decompiled from void __thiscall CFileEx::Open(_DWORD *this, wchar_t *FileName, char a3, char a4, char *Str, int a6)
void  CFileEx::Open(wchar_t const * FileName, unsigned int a3, bool a4, char * Str, int a6) {
  
  wchar_t *v6; // eax
  _BYTE pExceptionObject[552]; // [esp+8h] [ebp-254h] BYREF
  _BYTE v9[28]; // [esp+230h] [ebp-2Ch] BYREF
  int v10; // [esp+258h] [ebp-4h]

  *((_BYTE *)this - 24) = 0;
  if ( a4 )
  {
    (*(void (__thiscall **)(char *, wchar_t *, char *, int))(*(_DWORD *)((char *)this + *(_DWORD *)(*(this - 8) + 4)
                                                                                      - 32)
                                                           + 8))(
      (char *)this + *(_DWORD *)(*(this - 8) + 4) - 32,
      FileName,
      Str,
      a6);
  }
  else
  {
    std::wstring::wstring(v9);
    v10 = 0;
    CFile::OpenMaskToCWStr(this - 26, a3, (int)v9);
    v6 = (wchar_t *)std::wstring::c_str((_Cnd_internal_imp_t *)v9);
    *(this - 9) = CFileMgr::Open(FileName, v6, Str, a6);
    if ( !*(this - 9) )
    {
      *(this - 5) = CFileLibrary::FileOpen(FileName, 0);
      if ( *(this - 5) == -1 )
      {
        CBBFileException::CBBFileException((CBBFileException *)pExceptionObject, 2, FileName);
        _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVCBBFileException__);
      }
      *((_BYTE *)this - 24) = 1;
      *(this - 4) = CFileLibrary::FileSize((CFileLibrary *)&g_cFileLibrary, *(this - 5));
    }
    v10 = -1;
    std::wstring::~wstring(v9);
  }
}


// address=[0x2f01ad0]
// Decompiled from int __thiscall CFileEx::MapFile(_DWORD *this, WCHAR *lpFileName, const char *a3, int a4)
int  CFileEx::MapFile(wchar_t const * lpFileName, char * a3, int a4) {
  
  DWORD LastError; // eax
  DWORD v6; // eax
  unsigned int v7; // [esp+0h] [ebp-33Ch]
  HANDLE hFileMappingObject; // [esp+4h] [ebp-338h]
  HANDLE hFile; // [esp+8h] [ebp-334h]
  char pExceptionObject[552]; // [esp+10h] [ebp-32Ch] BYREF
  char v12[128]; // [esp+238h] [ebp-104h] BYREF
  char Buffer[128]; // [esp+2B8h] [ebp-84h] BYREF

  *((_BYTE *)this - 24) = 0;
  hFile = CreateFileW(lpFileName, 0x80000000, 1u, 0, 3u, 0, 0);
  if ( hFile == (HANDLE)-1 )
  {
    v7 = CFileLibrary::FileOpen(lpFileName, 0);
    if ( v7 == -1 )
    {
      sub_2F02260("CFile::MapFile can't open file `%s'", a3, a4, lpFileName);
      CBBFileException::CBBFileException((CBBFileException *)pExceptionObject, 2, lpFileName);
      _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVCBBFileException__);
    }
    *(this - 4) = CFileLibrary::FileSize((CFileLibrary *)&g_cFileLibrary, v7);
    *(this - 2) = CFileLibrary::MapFile((CFileLibrary *)&g_cFileLibrary, v7);
    CFileLibrary::FileClose((CFileLibrary *)&g_cFileLibrary, v7);
    *((_BYTE *)this - 24) = 1;
    *((_BYTE *)this - 23) = 1;
    return 1;
  }
  else
  {
    *(this - 4) = GetFileSize(hFile, 0);
    hFileMappingObject = CreateFileMappingA(hFile, 0, 2u, 0, 0, 0);
    if ( hFileMappingObject == (HANDLE)-1 )
    {
      LastError = GetLastError();
      j___snprintf(Buffer, 0x80u, "Unable map file . LastError was: %d", LastError);
      sub_2F02260(Buffer, a3, a4);
      CloseHandle(hFile);
      return 0;
    }
    else
    {
      *(this - 2) = MapViewOfFile(hFileMappingObject, 4u, 0, 0, 0);
      if ( *(this - 2) )
      {
        *(this - 3) = hFileMappingObject;
        *((_BYTE *)this - 23) = 1;
        CloseHandle(hFile);
        return 1;
      }
      else
      {
        v6 = GetLastError();
        j___snprintf(v12, 0x80u, "Unable map view of file. LastError was: %d", v6);
        sub_2F02260(v12, a3, a4);
        CloseHandle(hFileMappingObject);
        CloseHandle(hFile);
        return 0;
      }
    }
  }
}


// address=[0x2f01d30]
// Decompiled from int __thiscall CFileEx::GetMapFilePtr(CFileEx *this)
void *  CFileEx::GetMapFilePtr(void) {
  
  return *((_DWORD *)this - 2);
}


// address=[0x2f01d50]
// Decompiled from int __thiscall CFileEx::Read_0(_DWORD *this, void *Buffer, int ElementSize, int ElementCount, const char *a5, int a6)
unsigned int  CFileEx::Read(void * Buffer, int ElementSize, int ElementCount, char * a5, int a6) {
  
  int v7; // [esp+0h] [ebp-238h]
  int Size; // [esp+4h] [ebp-234h]
  _BYTE pExceptionObject[552]; // [esp+Ch] [ebp-22Ch] BYREF

  Size = ElementCount * ElementSize;
  if ( *((_BYTE *)this - 23) )
  {
    if ( Size + *(this - 7) > *(this - 4) )
    {
      sub_2F02260(
        "CFileEx::Read : Read in filemapping exceeds map size. Offset %d, to read %d, size %d ",
        a5,
        a6,
        *(this - 7),
        Size,
        *(this - 4));
      Size = *(this - 4) - *(this - 7);
      ElementCount = Size / ElementSize;
    }
    j__memcpy(Buffer, (const void *)(*(this - 7) + *(this - 2)), Size);
    *(this - 7) += Size;
  }
  if ( !*((_BYTE *)this - 24) )
    return CFile::Read(Buffer, ElementSize, ElementCount, (int)a5, a6);
  v7 = CFileLibrary::FileRead(*(this - 5), Buffer, Size);
  if ( v7 == -1 )
  {
    CBBFileException::CBBFileException(3, 0);
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVCBBFileException__);
  }
  if ( v7 != Size )
    return v7 / ElementSize;
  return ElementCount;
}


// address=[0x2f01ef0]
// Decompiled from int __thiscall CFileEx::Write(char *this, void *Buffer, size_t ElementSize, size_t ElementCount, int a5, int a6)
unsigned int  CFileEx::Write(void const * Buffer, int ElementSize, int ElementCount, char * a5, int a6) {
  
  if ( *(this - 24) || *(this - 23) )
    return 0;
  else
    return CFile::Write(Buffer, ElementSize, ElementCount, a5, a6);
}


// address=[0x2f01f40]
// Decompiled from int __thiscall CFileEx::Seek(_DWORD *this, int Offset, int Origin, const char *a4, int a5)
int  CFileEx::Seek(int Offset, int Origin, char * a4, int a5) {
  
  if ( *((_BYTE *)this - 23) )
  {
    if ( Origin )
    {
      if ( Origin == 1 )
      {
        *(this - 7) += Offset;
        if ( *(this - 7) < *(this - 4) )
        {
          return 0;
        }
        else
        {
          sub_2F02260("fseek offset (%ld) lies beyond file, mode SEEK_CUR", a4, a5, *(this - 7));
          return 1;
        }
      }
      else if ( Origin == 2 )
      {
        *(this - 7) = *(this - 4) + Offset - 1;
        if ( (int)*(this - 7) >= 0 )
        {
          if ( *(this - 7) < *(this - 4) )
          {
            return 0;
          }
          else
          {
            sub_2F02260("fseek offset (%ld) lies beyond file, mode SEEK_END", a4, a5, *(this - 7));
            return 1;
          }
        }
        else
        {
          sub_2F02260("Negative fseek offset (%ld) with mode SEEK_END", a4, a5, *(this - 7));
          return 1;
        }
      }
      else
      {
        sub_2F02260("Unknown fseek origin (%d)", a4, a5, Origin);
        return 1;
      }
    }
    else if ( Offset >= 0 )
    {
      if ( Offset < *(this - 4) )
      {
        *(this - 7) = Offset;
        return 0;
      }
      else
      {
        sub_2F02260("fseek offset (%ld) lies beyond file, mode SEEK_SET", a4, a5, Offset);
        return 1;
      }
    }
    else
    {
      sub_2F02260("Negative fseek offset (%ld) with mode SEEK_SET", a4, a5, Offset);
      return 1;
    }
  }
  else if ( *((_BYTE *)this - 24) )
  {
    return CFileLibrary::FileSeek((CFileLibrary *)&g_cFileLibrary, *(this - 5), Offset, Origin);
  }
  else
  {
    return CFile::Seek(Offset, Origin, (int)a4, a5);
  }
}


// address=[0x2f02120]
// Decompiled from int __thiscall CFileEx::Size_0(int this)
int  CFileEx::Size(void)const {
  
  if ( *(_BYTE *)(this + 80) || *(_BYTE *)(this + 81) )
    return *(_DWORD *)(this + 88);
  else
    return CFile::Size(this);
}


// address=[0x2f02160]
// Decompiled from int __thiscall CFileEx::Close(void **this, char *a2, int a3)
int  CFileEx::Close(char * a2, int a3) {
  
  if ( *((_BYTE *)this - 24) )
  {
    if ( *((_BYTE *)this - 23) )
    {
      CFileLibrary::UnmapFile((CFileLibrary *)&g_cFileLibrary, *(this - 2));
      *(this - 2) = 0;
      *((_BYTE *)this - 23) = 0;
    }
    else
    {
      CFileLibrary::FileClose((CFileLibrary *)&g_cFileLibrary, (unsigned int)*(this - 5));
    }
    return 0;
  }
  else if ( *((_BYTE *)this - 23) )
  {
    UnmapViewOfFile(*(this - 2));
    CloseHandle(*(this - 3));
    *(this - 3) = 0;
    *(this - 2) = 0;
    *((_BYTE *)this - 23) = 0;
    return 0;
  }
  else
  {
    return CFile::Close((CFile *)(this - 26), a2, a3);
  }
}


// address=[0x2f02220]
// Decompiled from char *__thiscall CFileEx::Release(CFileEx *this)
void  CFileEx::Release(void) {
  
  char *result; // eax

  result = (char *)this - 104;
  if ( this != (CFileEx *)104 )
    return (char *)(*(int (__thiscall **)(char *, int))(*((_DWORD *)this - 26) + 24))((char *)this - 104, 1);
  return result;
}


