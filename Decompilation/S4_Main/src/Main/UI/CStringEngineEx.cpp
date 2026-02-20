#include "CStringEngineEx.h"

#include "CBB/CBBSupport.h"
#include "Main/CGameSettings.h"
#include "File/CFileEx.h"
#include "Main/CS4DefineNames.h"

// Definitions for class CStringEngineEx

const int STRINGID_MAX = 3837;
const int HACK_STRINGID_MAX = 3842;

// address=[0x14ce780]
// Decompiled from CStringEngineEx *__thiscall CStringEngineEx::CStringEngineEx(CStringEngineEx *this, WCHAR *languageId)
CStringEngineEx::CStringEngineEx(int languageId) : CStringEngine()
{

  WCHAR swTextPathFormat[20]; // [esp+1Ch] [ebp-78h] BYREF
  wchar_t swpTextPath[32];    // [esp+44h] [ebp-50h] BYREF
  int v6;                     // [esp+90h] [ebp-4h]

  auto swTextPathFormat = L"Txt\\S4_Texts.dat%d";

  BBSupportTracePrintF(1, "Init strings for language %i...", languageId);
  swprintf(swpTextPath, swTextPathFormat, languageId);
  this->m_swpTexts = 0;
  if (languageId != 1) // If language not DE
  {
    // Import language specific file:
    this->ImportFile(swpTextPath, 1);
 
    // Import 0/EN fallback
    swprintf(swpTextPath, swTextPathFormat, 0);
    this->ImportFile(swpTextPath, 1);

    // Import 1/DE fallback
    swprintf(swpTextPath, swTextPathFormat, 1); 
  }
  this->ImportFile(swpTextPath, 1);
  this->CreateTextForEmptyStrings();
}

// address=[0x14ce900]
// Decompiled from CStringEngine *__thiscall CStringEngineEx::~CStringEngineEx(CStringEngineEx *this)
CStringEngineEx::~CStringEngineEx(void)
{
  if (!this->m_swpTexts)
    CStringEngine::~CStringEngine();
    return;

  for (int i = 0; i < STRINGID_MAX; ++i)
  {
    if (this->m_swpTexts[i])
    {
      delete[] this->m_swpTexts[i];
      this->m_swpTexts[i] = 0;
    }
  }
  delete[] this->m_swpTexts;
  this->m_swpTexts = 0;
  CStringEngine::~CStringEngine();
}

// address=[0x14ce9a0]
// Decompiled from wchar_t *__thiscall CStringEngineEx::GetString(CStringEngineEx *this, int _iId)
char const *CStringEngineEx::GetString(int _iId)
{

  int Language; // [esp+0h] [ebp-8h]

  if (_iId > HACK_STRINGID_MAX && BBSupportDbgReport(
                         2,
                         "Main\\StringEngine.cpp",
                         394,
                         "_iId >= 0 && _iId < STRINGID_MAX || _iId < HACK_STRINGID_MAX") == 1)
  {
    __debugbreak();
  }
  if (_iId < STRINGID_MAX)
  {
    if (this->m_swpTexts)
    {
      if (_iId >= 0)
      {
        if (this->m_swpTexts[_iId])
          return this->m_swpTexts[_iId];
        else
          return "XXX";
      }
      else
      {
        return "XXX";
      }
    }
    else
    {
      return "XXX";
    }
  }
  else
  {
    Language = CGameSettings::GetLanguage();
    if (Language == 1)
    {
      return (wchar_t *)STRINGS_GER[_iId];
    }
    else if (Language == 2)
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
bool CStringEngineEx::ExtractStrings(char *sdTextFileData, int size, int _bFillEmptyStrings)
{

  int i;                // [esp+10h] [ebp-18h]
  int uTextSizePointer; // [esp+18h] [ebp-10h]
  int uTextPointer;     // [esp+18h] [ebp-10h]
  int readTxtIndex;     // [esp+1Ch] [ebp-Ch]
  int uTextSize;        // [esp+20h] [ebp-8h]
  bool v11;             // [esp+27h] [ebp-1h]

  BBSupportTracePrintF(1, "%i strings in file version %i expected. Data length is %i bytes.", STRINGID_MAX, 21, size);
  v11 = 1;
  if (sdTextFileData && size > 4)
  {
    if (*(_DWORD *)sdTextFileData != 0x15)
    {
      BBSupportTracePrintF(
          3,
          "Wrong version of text dat file! Version is %i, should be %i!",
          *(_DWORD *)sdTextFileData,
          0x15);
      if (BBSupportDbgReport(1, "Main\\StringEngine.cpp", 161, "Version mismatch in text header and dat file!") == 1)
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
  while (uTextSizePointer < size)
  {
    uTextSize = *(_DWORD *)&sdTextFileData[uTextSizePointer];
    if (uTextSize < 0)
      uTextSize = 0;
    uTextPointer = uTextSizePointer + 4;
    if (size - uTextPointer < uTextSize)
    {
      BBSupportTracePrintF(3, "Not enough data in text dat file!");
      uTextSize = size - uTextPointer;
      v11 = 0;
    }
    if (readTxtIndex < STRINGID_MAX && !this->m_swpTexts[readTxtIndex] && (uTextSize > 0 || (_bFillEmptyStrings & 1) == 0))
    {
      this->m_swpTexts[readTxtIndex] = (wchar_t *)operator new[](uTextSize + 1);
      if (uTextSize > 0)
        memcpy(this->m_swpTexts[readTxtIndex], &sdTextFileData[uTextPointer], uTextSize);
      *((_BYTE *)this->m_swpTexts[readTxtIndex] + uTextSize) = 0;
    }
    uTextSizePointer = uTextSize + uTextPointer;
    ++readTxtIndex;
  }
  if (readTxtIndex != STRINGID_MAX)
  {
    BBSupportTracePrintF(3, "Number of strings mismatch! Got %i, expected %i!", readTxtIndex, STRINGID_MAX);
    if (BBSupportDbgReport(1, "Main\\StringEngine.cpp", 216, "Version mismatch in text header and dat file!") == 1)
      __debugbreak();
    v11 = 0;
  }
  if ((_bFillEmptyStrings & 1) == 0)
  {
    for (i = readTxtIndex; i < STRINGID_MAX; ++i)
    {
      this->m_swpTexts[i] = new char[1] {0};
    }
  }
  if (!v11 && BBSupportDbgReportF(2, "Main\\StringEngine.cpp", 230, "Invalid text dat file!") == 1)
    __debugbreak();
  return v11;
}

// address=[0x14ced10]
// Decompiled from char __thiscall CStringEngineEx::ImportFile(CStringEngineEx *this, wchar_t *FileName, char a3)
bool CStringEngineEx::ImportFile(wchar_t const *FileName, int a3)
{

  int v4;                // [esp+0h] [ebp-B4h] BYREF
  int uReadBytes;        // [esp+18h] [ebp-9Ch]
  char *pLangFileBuffer; // [esp+24h] [ebp-90h] MAPDST
  size_t uLangFileSize;  // [esp+2Ch] [ebp-88h]
  char Strings;          // [esp+31h] [ebp-83h] MAPDST
  char v15;              // [esp+32h] [ebp-82h]
  int *v17;              // [esp+A4h] [ebp-10h]
  int exceptionBlock;    // [esp+B0h] [ebp-4h]

  CFileEx pFile{};
  pFile.Open(FileName, CFile::CFile_BINARY | CFile::CFile_READ, 0, CFileLog);
  
  if (!this->m_swpTexts)
  {
    this->m_swpTexts = new char*[STRINGID_MAX];// 3837 entries;
    memset(this->m_swpTexts, 0, STRINGID_MAX * sizeof(char *));
  }
  uLangFileSize = pFile.Size();
  pLangFileBuffer = new char[uLangFileSize];
  uReadBytes = pFile.Read(
      pLangFileBuffer,
      1,
      uLangFileSize,
      CFileLog);
  pFile.Close(CFileLog);
  if (uReadBytes >= (int)uLangFileSize)
  {
    Strings = this->ExtractStrings(pLangFileBuffer, uLangFileSize, a3);
    delete[] pLangFileBuffer;
    return Strings;
  }
  else
  {
    BBSupportTracePrintF(0, "CStringEngineEx::ImportFile : Couldn't read file %s. completely", (const char *)FileName);
    delete[] pLangFileBuffer;
    return 0;
  }
}

// address=[0x14cef30]
// Decompiled from void __thiscall CStringEngineEx::CreateTextForEmptyStrings(CStringEngineEx *this)
void CStringEngineEx::CreateTextForEmptyStrings(void)
{

  const char *StringName; // eax
  size_t v2;              // [esp+4h] [ebp-418h]
  int v3;                 // [esp+Ch] [ebp-410h]
  int i;                  // [esp+14h] [ebp-408h]
  char Src[1024];         // [esp+18h] [ebp-404h] BYREF

  if (this->m_swpTexts)
  {
    v3 = 0;
    for (i = 0; i < 3837; ++i)
    {
      if (!this->m_swpTexts[i])
      {
        StringName = CS4DefineNames::GetStringName(i);
        snprintf(Src, 0x3FFu, "<%s>", StringName);
        Src[1023] = 0;
        v2 = strlen(Src);
        this->m_swpTexts[i] = new char[v2 + 1];
        memcpy(this->m_swpTexts[i], Src, v2 + 1);
        ++v3;
      }
    }
    BBSupportTracePrintF(1, "%i empty strings.", v3);
  }
}
