#include "all_headers.h"

// Definitions for class CStringEngineEx

// address=[0x14ce780]
// Decompiled from CStringEngineEx *__thiscall CStringEngineEx::CStringEngineEx(CStringEngineEx *this, int languageId)
 CStringEngineEx::CStringEngineEx(int) {
  
  char Format[40]; // [esp+1Ch] [ebp-78h] BYREF
  wchar_t Buffer[32]; // [esp+44h] [ebp-50h] BYREF
  int v6; // [esp+90h] [ebp-4h]

  CStringEngine::CStringEngine((CStringEngine *)this);
  v6 = 0;
  this->__vftable = (CStringEngineEx_vtbl *)&CStringEngineEx::_vftable_;
  qmemcpy(Format, L"Txt\\S4_Texts.dat%d", 0x26u);
  BBSupportTracePrintF(1, "Init strings for language %i...", languageId);
  swprintf((char *)Buffer, Format, languageId);
  this->strings = 0;
  if ( languageId != 1 )                        // If language not DE
  {
    CStringEngineEx::ImportFile(this, Buffer, 1);
    swprintf((char *)Buffer, Format, 0);        // Import 0/EN fallback
    CStringEngineEx::ImportFile(this, Buffer, 1);
    swprintf((char *)Buffer, Format, 1);        // Import 1/DE fallback
  }
  CStringEngineEx::ImportFile(this, Buffer, 1);
  CStringEngineEx::CreateTextForEmptyStrings(this);
  return this;
}


// address=[0x14ce900]
// Decompiled from CStringEngine *__thiscall CStringEngineEx::~CStringEngineEx(CStringEngineEx *this)
 CStringEngineEx::~CStringEngineEx(void) {
  
  int i; // [esp+8h] [ebp-8h]

  this->__vftable = (CStringEngineEx_vtbl *)&CStringEngineEx::_vftable_;
  if ( !this->strings )
    return CStringEngine::~CStringEngine((CStringEngine *)this);
  for ( i = 0; i < 3837; ++i )
  {
    if ( this->strings[i] )
    {
      operator delete[](this->strings[i]);
      this->strings[i] = 0;
    }
  }
  operator delete[](this->strings);
  this->strings = 0;
  return CStringEngine::~CStringEngine((CStringEngine *)this);
}


// address=[0x14ce9a0]
// Decompiled from wchar_t *__thiscall CStringEngineEx::GetString(CStringEngineEx *this, int a2)
char const *  CStringEngineEx::GetString(int) {
  
  int Language; // [esp+0h] [ebp-8h]

  if ( a2 > 3842
    && BBSupportDbgReport(
         2,
         "Main\\StringEngine.cpp",
         394,
         "_iId >= 0 && _iId < STRINGID_MAX || _iId < HACK_STRINGID_MAX") == 1 )
  {
    __debugbreak();
  }
  if ( a2 < 3837 )
  {
    if ( this->strings )
    {
      if ( a2 >= 0 )
      {
        if ( this->strings[a2] )
          return this->strings[a2];
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
      return (wchar_t *)STRINGS_GER[a2];
    }
    else if ( Language == 2 )
    {
      return (wchar_t *)STRINGS_FRE[a2];
    }
    else
    {
      return STRINGS_EN[a2];
    }
  }
}


// address=[0x14cea80]
// Decompiled from char __thiscall CStringEngineEx::ExtractStrings(CStringEngineEx *this, _DWORD *buffer, int size, char a4)
bool  CStringEngineEx::ExtractStrings(char *,int,int) {
  
  int i; // [esp+10h] [ebp-18h]
  int pointer; // [esp+18h] [ebp-10h]
  int pointera; // [esp+18h] [ebp-10h]
  int readTxtIndex; // [esp+1Ch] [ebp-Ch]
  int Size; // [esp+20h] [ebp-8h]
  char v11; // [esp+27h] [ebp-1h]

  BBSupportTracePrintF(1, "%i strings in file version %i expected. Data length is %i bytes.", 3837, 21, size);
  v11 = 1;
  if ( buffer && size > 4 )
  {
    if ( *buffer != 21 )
    {
      BBSupportTracePrintF(3, "Wrong version of text dat file! Version is %i, should be %i!", *buffer, 21);
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
  pointer = 4;
  while ( pointer < size )
  {
    Size = *(_DWORD *)((char *)buffer + pointer);
    if ( Size < 0 )
      Size = 0;
    pointera = pointer + 4;
    if ( size - pointera < Size )
    {
      BBSupportTracePrintF(3, "Not enough data in text dat file!");
      Size = size - pointera;
      v11 = 0;
    }
    if ( readTxtIndex < 3837 && !this->strings[readTxtIndex] && (Size > 0 || (a4 & 1) == 0) )
    {
      this->strings[readTxtIndex] = (wchar_t *)operator new[](Size + 1);
      if ( Size > 0 )
        j__memcpy(this->strings[readTxtIndex], (char *)buffer + pointera, Size);
      *((_BYTE *)this->strings[readTxtIndex] + Size) = 0;
    }
    pointer = Size + pointera;
    ++readTxtIndex;
  }
  if ( readTxtIndex != 3837 )
  {
    BBSupportTracePrintF(3, "Number of strings mismatch! Got %i, expected %i!", readTxtIndex, 3837);
    if ( BBSupportDbgReport(1, "Main\\StringEngine.cpp", 216, "Version mismatch in text header and dat file!") == 1 )
      __debugbreak();
    v11 = 0;
  }
  if ( (a4 & 1) == 0 )
  {
    for ( i = readTxtIndex; i < 3837; ++i )
    {
      this->strings[i] = (wchar_t *)operator new[](1u);
      *(_BYTE *)this->strings[i] = 0;
    }
  }
  if ( !v11 && BBSupportDbgReportF(2, "Main\\StringEngine.cpp", 230, "Invalid text dat file!") == 1 )
    __debugbreak();
  return v11;
}


// address=[0x14ced10]
// Decompiled from char __thiscall CStringEngineEx::ImportFile(CStringEngineEx *this, wchar_t *FileName, char a3)
bool  CStringEngineEx::ImportFile(wchar_t const *,int) {
  
  int v4; // [esp+0h] [ebp-B4h] BYREF
  void *C; // [esp+14h] [ebp-A0h]
  int v7; // [esp+18h] [ebp-9Ch]
  wchar_t **v9; // [esp+20h] [ebp-94h]
  void *Buffer; // [esp+24h] [ebp-90h] MAPDST
  size_t Size; // [esp+2Ch] [ebp-88h]
  char Strings; // [esp+31h] [ebp-83h] MAPDST
  char v15; // [esp+32h] [ebp-82h]
  _DWORD v16[26]; // [esp+34h] [ebp-80h] BYREF
  _DWORD v17[3]; // [esp+9Ch] [ebp-18h] BYREF
  int v18; // [esp+B0h] [ebp-4h]

  v17[2] = &v4;
  CFileEx::CFileEx((CFileEx *)v16, 1);
  v18 = 1;
  CFileEx::Open(v17, FileName, 6, 0, UNUSED_ARG(), UNUSED_ARG());
  v18 = 0;
  if ( !this->strings )
  {
    v9 = (wchar_t **)operator new[](15348u);    // 3837 entries
    this->strings = v9;
    memset(this->strings, 0, 15348u);
  }
  Size = CFileEx::Size(v16);
  Buffer = operator new[](Size);
  v7 = CFileEx::Read(v17, Buffer, 1, Size, (const char *)UNUSED_ARG(), UNUSED_ARG());
  ((void (__stdcall *)(const char *, int))CFileEx::Close)(UNUSED_ARG(), UNUSED_ARG());
  if ( v7 >= (int)Size )
  {
    Strings = CStringEngineEx::ExtractStrings(this, Buffer, Size, a3);
    operator delete[](Buffer);
    v18 = -1;
    CFileEx::~CFileEx(v16);
    return Strings;
  }
  else
  {
    BBSupportTracePrintF(0, "CStringEngineEx::ImportFile : Couldn't read file %s. completely", (const char *)FileName);
    C = Buffer;
    operator delete[](Buffer);
    v15 = 0;
    v18 = -1;
    CFileEx::~CFileEx(v16);
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
      j___snprintf(Src, 0x3FFu, "<%s>", StringName);
      Src[1023] = 0;
      v3 = j__strlen(Src);
      *(_DWORD *)(this[1] + 4 * i) = operator new[](v3 + 1);
      j__memcpy(*(void **)(this[1] + 4 * i), Src, v3 + 1);
      ++v4;
    }
  }
  return (_DWORD *)BBSupportTracePrintF(1, "%i empty strings.", v4);
}


