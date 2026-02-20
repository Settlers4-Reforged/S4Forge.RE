#include "CStringEngineEx.h"

// Definitions for class CStringEngineEx

// address=[0x14ce780]
// Decompiled from CStringEngineEx *__thiscall CStringEngineEx::CStringEngineEx(CStringEngineEx *this, WCHAR *languageId)
 CStringEngineEx::CStringEngineEx(int languageId) {
  
  WCHAR swTextPathFormat[20]; // [esp+1Ch] [ebp-78h] BYREF
  wchar_t swpTextPath[32]; // [esp+44h] [ebp-50h] BYREF
  int v6; // [esp+90h] [ebp-4h]

  CStringEngine::CStringEngine((CStringEngine *)this);
  v6 = 0;
  this->__vftable = (CStringEngineEx_vtbl *)&CStringEngineEx::_vftable_;
  qmemcpy(swTextPathFormat, L"Txt\\S4_Texts.dat%d", 0x26u);
  BBSupportTracePrintF(1, "Init strings for language %i...", languageId);
  swprintf(swpTextPath, swTextPathFormat, languageId);
  this->m_swpTexts = 0;
  if ( languageId != (WCHAR *)1 )               // If language not DE
  {
    CStringEngineEx::ImportFile(this, swpTextPath, 1);
    swprintf(swpTextPath, swTextPathFormat, 0); // Import 0/EN fallback
    CStringEngineEx::ImportFile(this, swpTextPath, 1);
    swprintf(swpTextPath, swTextPathFormat, (WCHAR *)1);// Import 1/DE fallback
  }
  CStringEngineEx::ImportFile(this, swpTextPath, 1);
  CStringEngineEx::CreateTextForEmptyStrings(this);
  return this;
}


// address=[0x14ce900]
// Decompiled from CStringEngine *__thiscall CStringEngineEx::~CStringEngineEx(CStringEngineEx *this)
 CStringEngineEx::~CStringEngineEx(void) {
  
  int i; // [esp+8h] [ebp-8h]

  this->__vftable = (CStringEngineEx_vtbl *)&CStringEngineEx::_vftable_;
  if ( !this->m_swpTexts )
    return CStringEngine::~CStringEngine((CStringEngine *)this);
  for ( i = 0; i < 3837; ++i )
  {
    if ( this->m_swpTexts[i] )
    {
      operator delete[](this->m_swpTexts[i]);
      this->m_swpTexts[i] = 0;
    }
  }
  operator delete[](this->m_swpTexts);
  this->m_swpTexts = 0;
  return CStringEngine::~CStringEngine((CStringEngine *)this);
}


// address=[0x14ce9a0]
// Decompiled from wchar_t *__thiscall CStringEngineEx::GetString(CStringEngineEx *this, int _iId)
char const *  CStringEngineEx::GetString(int _iId) {
  
  int Language; // [esp+0h] [ebp-8h]

  if ( _iId > 3842
    && BBSupportDbgReport(
         2,
         "Main\\StringEngine.cpp",
         394,
         "_iId >= 0 && _iId < STRINGID_MAX || _iId < HACK_STRINGID_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( _iId < 3837 )
  {
    if ( this->m_swpTexts )
    {
      if ( _iId >= 0 )
      {
        if ( this->m_swpTexts[_iId] )
          return this->m_swpTexts[_iId];
        else
          return (wchar_t *)&unk_4032214;
      }
      else
      {
        return (wchar_t *)&unk_4032214;
      }
    }
    else
    {
      return (wchar_t *)&unk_4032214;
    }
  }
  else
  {
    Language = CGameSettings::GetLanguage();
    if ( Language == 1 )
    {
      return (wchar_t *)STRINGS_GER[_iId];
    }
    else if ( Language == 2 )
    {
      return (wchar_t *)STRINGS_FRE[_iId];
    }
    else
    {
      return STRINGS_EN[_iId];
    }
  }
}


// address=[0x14cea80]
// Decompiled from bool __thiscall CStringEngineEx::ExtractStrings(  CStringEngineEx *this,  char *sdTextFileData,  int size,  char _bFillEmptyStrings)
bool  CStringEngineEx::ExtractStrings(char * sdTextFileData, int size, int _bFillEmptyStrings) {
  
  int i; // [esp+10h] [ebp-18h]
  int uTextSizePointer; // [esp+18h] [ebp-10h]
  int uTextPointer; // [esp+18h] [ebp-10h]
  int readTxtIndex; // [esp+1Ch] [ebp-Ch]
  int uTextSize; // [esp+20h] [ebp-8h]
  bool v11; // [esp+27h] [ebp-1h]

  BBSupportTracePrintF(1, "%i strings in file version %i expected. Data length is %i bytes.", 3837, 21, size);
  v11 = 1;
  if ( sdTextFileData && size > 4 )
  {
    if ( *(_DWORD *)sdTextFileData != 0x15 )
    {
      BBSupportTracePrintF(
        3,
        "Wrong version of text dat file! Version is %i, should be %i!",
        *(_DWORD *)sdTextFileData,
        0x15);
      if ( BBSupportDbgReport(1, "Main\\StringEngine.cpp", 161, "Version mismatch in text header and dat file!") == 1 )
        __debugbreak();
      v11 = 0;
    }
  }
  else
  {
    BBSupportTracePrintF(3, "Invalid parameters for ExtractStrings!");
    size = 0;
    v11 = 0;
  }
  readTxtIndex = 0;
  uTextSizePointer = 4;
  while ( uTextSizePointer < size )
  {
    uTextSize = *(_DWORD *)&sdTextFileData[uTextSizePointer];
    if ( uTextSize < 0 )
      uTextSize = 0;
    uTextPointer = uTextSizePointer + 4;
    if ( size - uTextPointer < uTextSize )
    {
      BBSupportTracePrintF(3, "Not enough data in text dat file!");
      uTextSize = size - uTextPointer;
      v11 = 0;
    }
    if ( readTxtIndex < 3837 && !this->m_swpTexts[readTxtIndex] && (uTextSize > 0 || (_bFillEmptyStrings & 1) == 0) )
    {
      this->m_swpTexts[readTxtIndex] = (wchar_t *)operator new[](uTextSize + 1);
      if ( uTextSize > 0 )
        memcpy(this->m_swpTexts[readTxtIndex], &sdTextFileData[uTextPointer], uTextSize);
      *((_BYTE *)this->m_swpTexts[readTxtIndex] + uTextSize) = 0;
    }
    uTextSizePointer = uTextSize + uTextPointer;
    ++readTxtIndex;
  }
  if ( readTxtIndex != 3837 )
  {
    BBSupportTracePrintF(3, "Number of strings mismatch! Got %i, expected %i!", readTxtIndex, 3837);
    if ( BBSupportDbgReport(1, "Main\\StringEngine.cpp", 216, "Version mismatch in text header and dat file!") == 1 )
      __debugbreak();
    v11 = 0;
  }
  if ( (_bFillEmptyStrings & 1) == 0 )
  {
    for ( i = readTxtIndex; i < 3837; ++i )
    {
      this->m_swpTexts[i] = (wchar_t *)operator new[](1u);
      *(_BYTE *)this->m_swpTexts[i] = 0;
    }
  }
  if ( !v11 && BBSupportDbgReportF(2, "Main\\StringEngine.cpp", 230, "Invalid text dat file!") == 1 )
    __debugbreak();
  return v11;
}


// address=[0x14ced10]
// Decompiled from char __thiscall CStringEngineEx::ImportFile(CStringEngineEx *this, wchar_t *FileName, char a3)
bool  CStringEngineEx::ImportFile(wchar_t const * FileName, int a3) {
  
  int v4; // [esp+0h] [ebp-B4h] BYREF
  void *C; // [esp+14h] [ebp-A0h]
  int uReadBytes; // [esp+18h] [ebp-9Ch]
  wchar_t **v9; // [esp+20h] [ebp-94h]
  void *pLangFileBuffer; // [esp+24h] [ebp-90h] MAPDST
  size_t uLangFileSize; // [esp+2Ch] [ebp-88h]
  char Strings; // [esp+31h] [ebp-83h] MAPDST
  char v15; // [esp+32h] [ebp-82h]
  CFileEx pFile; // [esp+34h] [ebp-80h] BYREF
  int *v17; // [esp+A4h] [ebp-10h]
  int exceptionBlock; // [esp+B0h] [ebp-4h]

  v17 = &v4;
  CFileEx::CFileEx(&pFile, 1);
  exceptionBlock = 1;
  CFileEx::Open(&pFile.IFileEx, FileName, CFile_BINARY|CFile_READ, 0, UNUSED_ARG(), UNUSED_ARG());
  exceptionBlock = 0;
  if ( !this->m_swpTexts )
  {
    v9 = (wchar_t **)operator new[](15348u);    // 3837 entries
    this->m_swpTexts = v9;
    memset(this->m_swpTexts, 0, 15348u);
  }
  uLangFileSize = CFileEx::Size(&pFile);
  pLangFileBuffer = operator new[](uLangFileSize);
  uReadBytes = CFileEx::Read(
                 &pFile.IFileEx.__vftable,
                 pLangFileBuffer,
                 1,
                 uLangFileSize,
                 (const char *)UNUSED_ARG(),
                 UNUSED_ARG());
  CFileEx::Close(&pFile.IFileEx, UNUSED_ARG(), UNUSED_ARG());
  if ( uReadBytes >= (int)uLangFileSize )
  {
    Strings = CStringEngineEx::ExtractStrings(this, pLangFileBuffer, uLangFileSize, a3);
    operator delete[](pLangFileBuffer);
    exceptionBlock = -1;
    CFileEx::~CFileEx(&pFile);
    return Strings;
  }
  else
  {
    BBSupportTracePrintF(0, "CStringEngineEx::ImportFile : Couldn't read file %s. completely", (const char *)FileName);
    C = pLangFileBuffer;
    operator delete[](pLangFileBuffer);
    v15 = 0;
    exceptionBlock = -1;
    CFileEx::~CFileEx(&pFile);
    return v15;
  }
}


// address=[0x14cef30]
// Decompiled from _DWORD *__thiscall CStringEngineEx::CreateTextForEmptyStrings(_DWORD *this)
void  CStringEngineEx::CreateTextForEmptyStrings(void) {
  
  _DWORD *result; // eax
  const char *StringName; // eax
  size_t v3; // [esp+4h] [ebp-418h]
  int v4; // [esp+Ch] [ebp-410h]
  int i; // [esp+14h] [ebp-408h]
  char Src[1024]; // [esp+18h] [ebp-404h] BYREF

  result = this;
  if ( !this[1] )
    return result;
  v4 = 0;
  for ( i = 0; i < 3837; ++i )
  {
    if ( !*(_DWORD *)(this[1] + 4 * i) )
    {
      StringName = (const char *)CS4DefineNames::GetStringName(i);
      snprintf(Src, 0x3FFu, "<%s>", StringName);
      Src[1023] = 0;
      v3 = strlen(Src);
      *(_DWORD *)(this[1] + 4 * i) = operator new[](v3 + 1);
      memcpy(*(void **)(this[1] + 4 * i), Src, v3 + 1);
      ++v4;
    }
  }
  return (_DWORD *)BBSupportTracePrintF(1, "%i empty strings.", v4);
}


