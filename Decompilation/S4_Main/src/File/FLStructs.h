#ifndef FLSTRUCTS_H
#define FLSTRUCTS_H

enum FileFlags : __int16
{
  FLFF_Compressed = 0x1,
  FLFF_Encrypted = 0x2,
};

struct FLPathListStruct
{
  wchar_t *m_swpPath;
  wchar_t *m_swpSearch;
  wchar_t *m_swpUnknown;
  int field_C;
  int field_10;
};

struct FLDirListStruct
{
  wchar_t *m_swpPath;
  int field_4;
  int field_8;
  FLDirListStruct *m_pNext;
};

struct FLFileListStruct
{
  wchar_t *m_swpFileName;
  int m_uU4;
  int m_uFlags;
  int m_uFileSize;
  FLDirListStruct *m_pContainingDir;
  FLFileListStruct *m_pNext;
};

struct FLFHandleStruct
{
  int m_uId;
  FLFHandleStruct *m_pFileHandle;
  FLFHandleStruct *m_pNext;
};

struct FLMemFileStruct
{
  const wchar_t *m_pswName;
  FileFlags m_iFlags;
  int m_iFileOffset;
  int m_iFileSize;
  int m_iDecompressedSize;
  __int16 m_iLibraryIndex;
  int m_iCRC;
  char *m_pFileData;
};

struct FLMemDirStruct
{
  const wchar_t *m_swpDirectoryName;
  __int16 m_uFlags;
  __int16 m_iFileCount;
  __int16 m_iReadFileCount;
  __int16 field_A;
  FLMemFileStruct *m_pFiles;
};

struct FLIntHandleStruct
{
  int m_iSeekPosition;
  unsigned __int16 m_iDataSize;
  int field_8;
  char *m_pData;
  int m_iLibraryIndex;
  FLMemFileStruct *m_pLibraryFile;
  FLIntHandleStruct *m_pNextHandle;
};

static_assert(sizeof(FLLibraryFileStruct) == 0x18, "sizeof(FLLibraryFileStruct) != 0x18");
struct FLLibraryFileStruct
{
  wchar_t *m_swpFileName;
  void *m_hFile;
  void *m_pFileData;
  void *m_hFileMap;
  int m_bFileMapped;
  int m_uFileSize;
};

static_assert(sizeof(FLHeaderStruct) == 0x18, "sizeof(FLHeaderStruct) != 0x18");
struct FLHeaderStruct
{
  int field_0;
  int m_iVersion;
  int m_iDirectoryNamesSize;
  int m_iDirectoryNameCount;
  int m_iFileNamesSize;
  int m_iFileHeaderCount;
};

static_assert(sizeof(FLHeaderFileStruct) == 0x18, "sizeof(FLHeaderFileStruct) != 0x18");
struct FLHeaderFileStruct
{
  int field_0;
  int field_4;
  int field_8;
  __int16 field_C;
  int m_uFlags;
  int field_14;
};

struct FLCopyProgressStruct
{
  int m_uU0;
  int m_uExpectedFileSize;
  int m_uU8;
  int m_uFileSize;
  int m_uU10;
  int m_uHeaderCount;
  int m_uFlags;
  int m_uU1C;
  unsigned int m_uCRC;
};


#endif // FLSTRUCTS_H