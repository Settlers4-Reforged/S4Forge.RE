#include "CFileMgr.h"

// Definitions for class CFileMgr

// address=[0x2f28a80]
// Decompiled from CFileMgr *__thiscall CFileMgr::CFileMgr(CFileMgr *this)
 CFileMgr::CFileMgr(void) {
  
  CFileMgr::m_vFileDesc = (int)j____acrt_iob_func(0);
  *(&CFileMgr::m_vFileDesc + 1) = (int)L"(stdin)";
  *(&CFileMgr::m_vFileDesc + 2) = (int)L"r";
  *(&CFileMgr::m_vFileDesc + 3) = -99;
  *(&CFileMgr::m_vFileDesc + 4) = (int)"(internal)";
  *(&CFileMgr::m_vFileDesc + 5) = 0;
  *(&CFileMgr::m_vFileDesc + 6) = 1;
  *(&CFileMgr::m_vFileDesc + 7) = 0;
  *(&CFileMgr::m_vFileDesc + 8) = 3;
  *(&CFileMgr::m_vFileDesc + 9) = (int)j____acrt_iob_func(1u);
  *(&CFileMgr::m_vFileDesc + 10) = (int)L"(stdout)";
  *(&CFileMgr::m_vFileDesc + 11) = (int)L"w";
  *(&CFileMgr::m_vFileDesc + 12) = -99;
  *(&CFileMgr::m_vFileDesc + 13) = (int)"(internal)";
  *(&CFileMgr::m_vFileDesc + 14) = 0;
  *(&CFileMgr::m_vFileDesc + 15) = 2;
  *(&CFileMgr::m_vFileDesc + 16) = 0;
  *(&CFileMgr::m_vFileDesc + 17) = 3;
  *(&CFileMgr::m_vFileDesc + 18) = (int)j____acrt_iob_func(2u);
  *(&CFileMgr::m_vFileDesc + 19) = (int)L"(stderr)";
  *(&CFileMgr::m_vFileDesc + 20) = (int)L"w";
  *(&CFileMgr::m_vFileDesc + 21) = -99;
  *(&CFileMgr::m_vFileDesc + 22) = (int)"(internal)";
  *(&CFileMgr::m_vFileDesc + 23) = 0;
  *(&CFileMgr::m_vFileDesc + 24) = 2;
  *(&CFileMgr::m_vFileDesc + 25) = 0;
  *(&CFileMgr::m_vFileDesc + 26) = 3;
  return this;
}


// address=[0x2f28be0]
// Decompiled from int __cdecl CFileMgr::Open(wchar_t *FileName, wchar_t *Mode, char *Str, int a4)
static struct _iobuf * __cdecl CFileMgr::Open(wchar_t const *,wchar_t const *,char *,int) {
  
  int v5; // [esp+0h] [ebp-Ch] BYREF
  int v6; // [esp+4h] [ebp-8h]
  _DWORD *IsFileOpen; // [esp+8h] [ebp-4h]

  if ( !FileName )
    sub_2F292E0("Filename argument to fopen is NULL", Str, a4, v5);
  if ( !Mode )
    sub_2F292E0("Mode argument to fopen is NULL", Str, a4, v5);
  CFileMgr::CheckOpenMode(0, a4, (int)Str, (int)FileName, Mode, (int)&v5);
  IsFileOpen = (_DWORD *)CFileMgr::IsFileOpen(FileName);
  if ( IsFileOpen )
    sub_2F292E0(
      "File `%s' is already open in fopen (due to earlier %s on line %d, file `%s')",
      Str,
      a4,
      FileName,
      CFileMgr::fnames[IsFileOpen[5]],
      IsFileOpen[3],
      IsFileOpen[4]);
  v6 = (int)j___wfopen(FileName, Mode);
  if ( !v6 )
    return 0;
  CFileMgr::AddNewFileDesc(v6, 0, a4, Str, FileName, Mode, v5);
  return v6;
}


// address=[0x2f28cd0]
// Decompiled from int __cdecl CFileMgr::RemoveFromList(struct SFileDesc *a1)
static void __cdecl CFileMgr::RemoveFromList(struct SFileDesc *) {
  
  int result; // eax

  if ( !a1 && BBSupportDbgReport(2, "Source\\File\\FileMgr.cpp", 342, "_pFileDesc != NULL") == 1 )
    __debugbreak();
  CFileMgr::DisposeNode(a1);
  --CFileMgr::m_iOpenFiles;
  qmemcpy(a1, &CFileMgr::m_vFileDesc[9 * CFileMgr::m_iOpenFiles], 0x24u);
  return result;
}


// address=[0x2f28d40]
// Decompiled from struct SFileDesc *__cdecl CFileMgr::CheckValidFilePtr(struct _iobuf *a1, char *a2, char *a3, int a4)
static struct SFileDesc * __cdecl CFileMgr::CheckValidFilePtr(struct _iobuf *,char *,char *,int) {
  
  struct SFileDesc *v5; // [esp+0h] [ebp-4h]

  if ( a1 )
  {
    v5 = CFileMgr::LookupFilePtr(a1);
    if ( !v5 )
      sub_2F292E0("FILE* pointer passed to `%s' was not previously opened", a3, a4, a2);
    return v5;
  }
  else
  {
    sub_2F292E0("FILE* pointer passed to `%s' is NULL", a3, a4, a2);
    return 0;
  }
}


// address=[0x2f28da0]
// Decompiled from int CFileMgr::ReportOpenFiles()
static void __cdecl CFileMgr::ReportOpenFiles(void) {
  
  struct _iobuf *v0; // eax
  struct _iobuf *v1; // eax
  struct _iobuf *v2; // eax
  int i; // [esp+0h] [ebp-Ch]
  int v5; // [esp+4h] [ebp-8h]
  int *v6; // [esp+8h] [ebp-4h]

  v5 = 0;
  BBSupportTracePrintF(2, "----------DEBUGLIB FILE REPORT----------");
  for ( i = 0; i < CFileMgr::m_iOpenFiles; ++i )
  {
    v6 = &CFileMgr::m_vFileDesc[9 * i];
    if ( (FILE *)*v6 != j____acrt_iob_func(0)
      && (FILE *)*v6 != j____acrt_iob_func(1u)
      && (FILE *)*v6 != j____acrt_iob_func(2u) )
    {
      ++v5;
      BBSupportTracePrintF(
        2,
        "File `%s' opened by %s at line %ld in file %s\n",
        (const char *)v6[1],
        CFileMgr::fnames[v6[5]],
        v6[3],
        (const char *)v6[4]);
    }
  }
  v0 = j____acrt_iob_func(0);
  if ( !CFileMgr::LookupFilePtr(v0) )
    BBSupportTracePrintF(2, "(stdin) has been closed");
  v1 = j____acrt_iob_func(1u);
  if ( !CFileMgr::LookupFilePtr(v1) )
    BBSupportTracePrintF(2, "(stdout) has been closed");
  v2 = j____acrt_iob_func(2u);
  if ( !CFileMgr::LookupFilePtr(v2) )
    BBSupportTracePrintF(2, "(stderr) has been closed");
  if ( v5 )
  {
    if ( v5 == 1 )
      BBSupportTracePrintF(2, "There is 1 file open\n");
    else
      BBSupportTracePrintF(2, "There are %d files open", v5);
  }
  else
  {
    BBSupportTracePrintF(2, "There are no files open");
  }
  return BBSupportTracePrintF(2, "----------------------------------------");
}


// address=[0x2f28f30]
// Decompiled from _DWORD *__cdecl CFileMgr::CheckOpenMode(int a1, int a2, int a3, int a4, wchar_t *String2, _DWORD *a6)
static void __cdecl CFileMgr::CheckOpenMode(int,int,char *,wchar_t const *,wchar_t const *,int *) {
  
  size_t v6; // eax
  _DWORD *result; // eax
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0; (&CFileMgr::m_sModes)[2 * i]; ++i )
  {
    v6 = j__wcslen((&CFileMgr::m_sModes)[2 * i]);
    if ( !j__wcsncmp(String2, (&CFileMgr::m_sModes)[2 * i], v6) )
      break;
  }
  if ( (&CFileMgr::m_sModes)[2 * i] )
  {
    *a6 = dword_3E2D2CC[2 * i];
    if ( !j__wcscmp(L"rw", String2)
      || !j__wcscmp(L"wr", String2)
      || !j__wcscmp(L"rwb", String2)
      || !j__wcscmp(L"wrb", String2) )
    {
      return (_DWORD *)sub_2F292E0(
                         "mode \"%s\" is obsolete (use \"rb+\") -- was supplied to %s to open file `%s'",
                         a3,
                         a2,
                         String2,
                         CFileMgr::fnames[a1],
                         a4);
    }
    else
    {
      result = (_DWORD *)j__wcscmp((&CFileMgr::m_sModes)[2 * i], String2);
      if ( (*a6 & 1) != 0 )
      {
        result = a6;
        if ( (*a6 & 2) != 0 )
        {
          result = (_DWORD *)(*a6 & 8);
          if ( !result )
            return (_DWORD *)sub_2F292E0(
                               "Update mode \"%s\" specifies text file; \"%sb\" is probably intended -- was supplied to %"
                               "s to open file `%s'",
                               a3,
                               a2,
                               (&CFileMgr::m_sModes)[2 * i],
                               (&CFileMgr::m_sModes)[2 * i],
                               CFileMgr::fnames[a1],
                               a4);
        }
      }
    }
  }
  else
  {
    result = (_DWORD *)sub_2F292E0(
                         "Bad mode \"%s\" supplied to %s to open file `%s'",
                         a3,
                         a2,
                         String2,
                         CFileMgr::fnames[a1],
                         a4);
    *a6 = 1;
  }
  return result;
}


// address=[0x2f290d0]
// Decompiled from int *__cdecl CFileMgr::AddNewFileDesc(int a1, int a2, int a3, char *Str, wchar_t *String, wchar_t *a6, int a7)
static struct SFileDesc * __cdecl CFileMgr::AddNewFileDesc(struct _iobuf *,int,int,char const *,wchar_t const *,wchar_t const *,int) {
  
  int *v8; // [esp+0h] [ebp-230h]
  _BYTE pExceptionObject[552]; // [esp+4h] [ebp-22Ch] BYREF

  if ( CFileMgr::m_iOpenFiles >= 128 )
  {
    CBBFileException::CBBFileException((CBBFileException *)pExceptionObject, 1, 0);
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVCBBFileException__);
  }
  v8 = &CFileMgr::m_vFileDesc[9 * CFileMgr::m_iOpenFiles++];
  *v8 = a1;
  v8[1] = sub_2F293A0(String);
  v8[2] = sub_2F293A0(a6);
  v8[3] = a3;
  v8[4] = sub_2F29360(Str);
  v8[5] = a2;
  v8[6] = a7;
  v8[7] = 0;
  return v8;
}


// address=[0x2f291c0]
// Decompiled from FILE *__cdecl CFileMgr::DisposeNode(void **a1)
static void __cdecl CFileMgr::DisposeNode(struct SFileDesc *) {
  
  FILE *result; // eax

  result = j____acrt_iob_func(0);
  if ( *a1 == result )
    return result;
  result = j____acrt_iob_func(1u);
  if ( *a1 == result )
    return result;
  result = j____acrt_iob_func(2u);
  if ( *a1 == result )
    return result;
  operator delete[](a1[4]);
  operator delete[](a1[1]);
  return (FILE *)operator delete[](a1[2]);
}


// address=[0x2f29240]
// Decompiled from int *__cdecl CFileMgr::IsFileOpen(wchar_t *String2)
static struct SFileDesc * __cdecl CFileMgr::IsFileOpen(wchar_t const *) {
  
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0; i < CFileMgr::m_iOpenFiles; ++i )
  {
    if ( !j__wcscmp((const wchar_t *)dword_46857B4[9 * i], String2) )
      return &CFileMgr::m_vFileDesc[9 * i];
  }
  return 0;
}


// address=[0x2f29290]
// Decompiled from int *__cdecl CFileMgr::LookupFilePtr(struct _iobuf *a1)
static struct SFileDesc * __cdecl CFileMgr::LookupFilePtr(struct _iobuf *) {
  
  int i; // [esp+0h] [ebp-4h]

  for ( i = 0; i < CFileMgr::m_iOpenFiles; ++i )
  {
    if ( (struct _iobuf *)CFileMgr::m_vFileDesc[9 * i] == a1 )
      return &CFileMgr::m_vFileDesc[9 * i];
  }
  return 0;
}


// address=[0x3e2d2b0]
// [Decompilation failed for static char * * CFileMgr::fnames]

// address=[0x3e2d2c4]
// [Decompilation failed for static int CFileMgr::m_iOpenFiles]

// address=[0x3e2d2c8]
// [Decompilation failed for static struct CFileMgr::SModes * CFileMgr::m_sModes]

// address=[0x46857b0]
// [Decompilation failed for static struct SFileDesc * CFileMgr::m_vFileDesc]

