#include "all_headers.h"

// Definitions for class Parser

// address=[0x2f26710]
// Decompiled from AdvXMLParser::Parser *__thiscall AdvXMLParser::Parser::Parser(AdvXMLParser::Parser *this)
 AdvXMLParser::Parser::Parser(void) {
  
  *(_DWORD *)this = &AdvXMLParser::Parser::_vftable_;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 4) = 1;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  return this;
}


// address=[0x2f26750]
// Decompiled from AdvXMLParser::Parser *__thiscall AdvXMLParser::Parser::~Parser(AdvXMLParser::Parser *this)
 AdvXMLParser::Parser::~Parser(void) {
  
  AdvXMLParser::Parser *result; // eax

  result = this;
  *(_DWORD *)this = &AdvXMLParser::Parser::_vftable_;
  return result;
}


// address=[0x2f26770]
// Decompiled from void *__cdecl AdvXMLParser::Parser::OpenXMLFile(wchar_t *FileName, int *a2)
static char * __cdecl AdvXMLParser::Parser::OpenXMLFile(wchar_t *,long &) {
  
  void *Buffer; // [esp+10h] [ebp-80h]
  _DWORD v4[26]; // [esp+14h] [ebp-7Ch] BYREF
  int v5; // [esp+7Ch] [ebp-14h] BYREF
  int v6; // [esp+8Ch] [ebp-4h]

  CFileEx::CFileEx(FileName, 6, 0, 1);
  v6 = 0;
  *a2 = CFileEx::Size(v4);
  Buffer = operator new[](*a2 + 1);
  CFileEx::Read(&v5, Buffer, 1, *a2, "Source\\Xml\\reader.cpp", 61);
  *((_BYTE *)Buffer + *a2) = 0;
  CFileEx::Close((CFileEx *)&v5, UNUSED_ARG(), UNUSED_ARG());
  v6 = -1;
  CFileEx::~CFileEx(v4);
  return Buffer;
}


// address=[0x2f26860]
// Decompiled from int __thiscall AdvXMLParser::Parser::Parse(AdvXMLParser::Parser *this, const char *a2, int a3)
class AdvXMLParser::Document *  AdvXMLParser::Parser::Parse(char const *,int) {
  
  int v3; // eax
  int v5; // [esp+0h] [ebp-Ch]
  _BYTE v6[4]; // [esp+4h] [ebp-8h] BYREF
  struct AdvXMLParser::Parser *v7; // [esp+8h] [ebp-4h]

  v7 = this;
  *((_DWORD *)this + 1) = a2;
  *((_DWORD *)v7 + 2) = *((_DWORD *)v7 + 1);
  *((_DWORD *)v7 + 3) = a3 + *((_DWORD *)v7 + 1);
  *((_DWORD *)v7 + 4) = 1;
  *((_DWORD *)v7 + 5) = 1;
  v3 = AdvXMLParser::Document::Parse(v7);
  std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v3);
  v5 = std::auto_ptr<AdvXMLParser::Document>::release(v6);
  std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v6);
  return v5;
}


// address=[0x2f268e0]
// Decompiled from void __thiscall __noreturn AdvXMLParser::Parser::SyntaxError(int *this, int a2)
void  AdvXMLParser::Parser::SyntaxError(enum AdvXMLParser::PARSER_ERROR) {
  
  _BYTE pExceptionObject[16]; // [esp+0h] [ebp-14h] BYREF
  int *v3; // [esp+10h] [ebp-4h]

  v3 = this;
  AdvXMLParser::ParsingException::ParsingException((AdvXMLParser::Exception *)pExceptionObject, a2, this[4], this[5]);
  _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVParsingException_AdvXMLParser__);
}


// address=[0x2f26920]
// Decompiled from char __thiscall AdvXMLParser::Parser::NextChar(AdvXMLParser::Parser *this)
char  AdvXMLParser::Parser::NextChar(void) {
  
  char v2; // [esp+7h] [ebp-1h]

  if ( *((_DWORD *)this + 2) < *((_DWORD *)this + 3) )
  {
    v2 = *(_BYTE *)(*((_DWORD *)this + 2))++;
    if ( v2 == 13 )
    {
      if ( *((_DWORD *)this + 2) < *((_DWORD *)this + 3) && **((_BYTE **)this + 2) == 10 )
        ++*((_DWORD *)this + 2);
      v2 = 10;
    }
    *((_DWORD *)this + 6) = *((_DWORD *)this + 5);
    if ( v2 == 10 )
    {
      ++*((_DWORD *)this + 4);
      *((_DWORD *)this + 5) = 0;
    }
    else
    {
      ++*((_DWORD *)this + 5);
    }
    return v2;
  }
  else
  {
    *((_DWORD *)this + 2) = *((_DWORD *)this + 3) + 1;
    return 0;
  }
}


// address=[0x2f269f0]
// Decompiled from AdvXMLParser::Parser *__thiscall AdvXMLParser::Parser::PreviousChar(AdvXMLParser::Parser **this)
void  AdvXMLParser::Parser::PreviousChar(void) {
  
  AdvXMLParser::Parser *result; // eax

  result = (AdvXMLParser::Parser *)this;
  if ( this[2] > this[3] )
    return result;
  if ( (AdvXMLParser::Parser *)((char *)this[2] - 1) >= this[1] )
  {
    this[2] = (AdvXMLParser::Parser *)((char *)this[2] - 1);
    if ( *(_BYTE *)this[2] == 10 )
    {
      if ( this[2] > this[1] && *((_BYTE *)this[2] - 1) == 13 )
        this[2] = (AdvXMLParser::Parser *)((char *)this[2] - 1);
      this[4] = (AdvXMLParser::Parser *)((char *)this[4] - 1);
      if ( (int)this[4] < 1 && BBSupportDbgReport(2, "Source\\Xml\\reader.cpp", 147, "m_nLine >= 1") == 1 )
        __debugbreak();
    }
    result = this[6];
    this[5] = result;
  }
  else
  {
    this[2] = this[1];
    result = (AdvXMLParser::Parser *)this;
    this[6] = (AdvXMLParser::Parser *)1;
    this[5] = (AdvXMLParser::Parser *)1;
    this[4] = (AdvXMLParser::Parser *)1;
  }
  return result;
}


// address=[0x2f26af0]
// Decompiled from char __thiscall AdvXMLParser::Parser::ParseChar(AdvXMLParser::Parser *this, char a2)
bool  AdvXMLParser::Parser::ParseChar(char) {
  
  if ( AdvXMLParser::Parser::NextChar(this) == a2 )
    return 1;
  AdvXMLParser::Parser::PreviousChar(this);
  return 0;
}


// address=[0x2f26b20]
// Decompiled from char __thiscall AdvXMLParser::Parser::ParseString(AdvXMLParser::Parser *this, const char *a2)
bool  AdvXMLParser::Parser::ParseString(char const *) {
  
  _BYTE v3[16]; // [esp+0h] [ebp-18h] BYREF
  AdvXMLParser::Parser *v4; // [esp+10h] [ebp-8h]
  char Char; // [esp+17h] [ebp-1h]

  v4 = this;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v3, this);
  while ( *a2 )
  {
    Char = AdvXMLParser::Parser::NextChar(v4);
    if ( Char != *a2 )
    {
      AdvXMLParser::Bookmark::Restore((AdvXMLParser::Bookmark *)v3);
      return 0;
    }
    ++a2;
  }
  return 1;
}


// address=[0x2f26b80]
// Decompiled from char __thiscall AdvXMLParser::Parser::ParseStringNoCase(AdvXMLParser::Parser *this, _BYTE *a2)
bool  AdvXMLParser::Parser::ParseStringNoCase(char const *) {
  
  int v2; // esi
  _BYTE v4[16]; // [esp+4h] [ebp-18h] BYREF
  AdvXMLParser::Parser *v5; // [esp+14h] [ebp-8h]
  unsigned __int8 Char; // [esp+1Bh] [ebp-1h]

  v5 = this;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v4, this);
  while ( *a2 )
  {
    Char = AdvXMLParser::Parser::NextChar(v5);
    v2 = AdvXMLParser::LowCase((AdvXMLParser *)Char);
    if ( v2 != AdvXMLParser::LowCase((AdvXMLParser *)(unsigned __int8)*a2) )
    {
      AdvXMLParser::Bookmark::Restore((AdvXMLParser::Bookmark *)v4);
      return 0;
    }
    ++a2;
  }
  return 1;
}


// address=[0x2f26c00]
// Decompiled from char __thiscall AdvXMLParser::Parser::ParseNumber(AdvXMLParser::Parser *this, int *a2)
bool  AdvXMLParser::Parser::ParseNumber(int &) {
  
  char v3; // [esp+0h] [ebp-8h]
  AdvXMLParser::Parser *v4; // [esp+0h] [ebp-8h]
  unsigned __int8 Char; // [esp+7h] [ebp-1h]

  v3 = (char)this;
  Char = AdvXMLParser::Parser::NextChar(this);
  if ( !AdvXMLParser::IsDigit((AdvXMLParser *)Char, v3) )
    return 0;
  *a2 = 0;
  while ( AdvXMLParser::IsDigit((AdvXMLParser *)Char, (char)v4) )
  {
    *a2 = 10 * *a2 + (char)Char - 48;
    Char = AdvXMLParser::Parser::NextChar(v4);
  }
  AdvXMLParser::Parser::PreviousChar(v4);
  return 1;
}


// address=[0x2f26c80]
// Decompiled from char __thiscall AdvXMLParser::Parser::ParseHexNumber(AdvXMLParser::Parser *this, int *a2)
bool  AdvXMLParser::Parser::ParseHexNumber(int &) {
  
  int v3; // esi
  char v4; // [esp+0h] [ebp-Ch]
  unsigned __int8 Char; // [esp+Bh] [ebp-1h]

  Char = AdvXMLParser::Parser::NextChar(this);
  if ( !AdvXMLParser::IsHexDigit((AdvXMLParser *)Char) )
    return 0;
  *a2 = 0;
  while ( AdvXMLParser::IsHexDigit((AdvXMLParser *)Char) )
  {
    v3 = 16 * *a2;
    *a2 = AdvXMLParser::HexDigitValue((AdvXMLParser *)Char, v4) + v3;
    Char = AdvXMLParser::Parser::NextChar(this);
  }
  AdvXMLParser::Parser::PreviousChar(this);
  return 1;
}


// address=[0x2f26d10]
// Decompiled from char __thiscall AdvXMLParser::Parser::ParseDeclBegining(AdvXMLParser::Parser *this, const char *a2)
bool  AdvXMLParser::Parser::ParseDeclBegining(char const *) {
  
  _BYTE v3[16]; // [esp+0h] [ebp-14h] BYREF
  AdvXMLParser::Parser *v4; // [esp+10h] [ebp-4h]

  v4 = this;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v3, this);
  if ( !AdvXMLParser::Parser::ParseSpaces(v4) )
    return 0;
  if ( AdvXMLParser::Parser::ParseString(v4, a2) )
  {
    if ( !AdvXMLParser::Parser::ParseEq(v4) )
      AdvXMLParser::Parser::SyntaxError(v4, 3);
    return 1;
  }
  else
  {
    AdvXMLParser::Bookmark::Restore((AdvXMLParser::Bookmark *)v3);
    return 0;
  }
}


// address=[0x2f26d80]
// Decompiled from char __thiscall AdvXMLParser::Parser::ParseSpaces(AdvXMLParser::Parser *this)
bool  AdvXMLParser::Parser::ParseSpaces(void) {
  
  char v2; // [esp+0h] [ebp-8h]
  AdvXMLParser::Parser *v3; // [esp+0h] [ebp-8h]
  unsigned __int8 Char; // [esp+7h] [ebp-1h]
  unsigned __int8 v5; // [esp+7h] [ebp-1h]

  v2 = (char)this;
  Char = AdvXMLParser::Parser::NextChar(this);
  if ( AdvXMLParser::IsSpace((AdvXMLParser *)Char, v2) )
  {
    do
      v5 = AdvXMLParser::Parser::NextChar(v3);
    while ( AdvXMLParser::IsSpace((AdvXMLParser *)v5, (char)v3) );
    AdvXMLParser::Parser::PreviousChar(v3);
    return 1;
  }
  else
  {
    AdvXMLParser::Parser::PreviousChar(v3);
    return 0;
  }
}


// address=[0x2f26df0]
// Decompiled from char __thiscall AdvXMLParser::Parser::ParseEq(AdvXMLParser::Parser *this)
bool  AdvXMLParser::Parser::ParseEq(void) {
  
  _BYTE v2[16]; // [esp+0h] [ebp-14h] BYREF
  AdvXMLParser::Parser *v3; // [esp+10h] [ebp-4h]

  v3 = this;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v2, this);
  AdvXMLParser::Parser::ParseSpaces(v3);
  if ( AdvXMLParser::Parser::ParseChar(v3, 61) )
  {
    AdvXMLParser::Parser::ParseSpaces(v3);
    return 1;
  }
  else
  {
    AdvXMLParser::Bookmark::Restore((AdvXMLParser::Bookmark *)v2);
    return 0;
  }
}


// address=[0x2f26e40]
// Decompiled from char __thiscall AdvXMLParser::Parser::ParseName(AdvXMLParser::Parser *this, int a2)
bool  AdvXMLParser::Parser::ParseName(std::string &) {
  
  char v3[16]; // [esp+0h] [ebp-18h] BYREF
  AdvXMLParser::Parser *v4; // [esp+10h] [ebp-8h]
  unsigned __int8 Char; // [esp+17h] [ebp-1h]

  v4 = this;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v3, this);
  Char = AdvXMLParser::Parser::NextChar(v4);
  if ( AdvXMLParser::IsAlpha((AdvXMLParser *)Char, v3[0]) || Char == 95 || Char == 58 )
  {
    while ( AdvXMLParser::IsNameChar((AdvXMLParser *)Char, v3[0]) )
      Char = AdvXMLParser::Parser::NextChar(v4);
    AdvXMLParser::Parser::PreviousChar(v4);
    AdvXMLParser::Bookmark::GetSubString(a2, 0);
    return 1;
  }
  else
  {
    AdvXMLParser::Parser::PreviousChar(v4);
    return 0;
  }
}


// address=[0x2f26ee0]
// Decompiled from char __thiscall AdvXMLParser::Parser::ParseNmtoken(AdvXMLParser::Parser *this, int a2)
bool  AdvXMLParser::Parser::ParseNmtoken(std::string &) {
  
  char v3[16]; // [esp+0h] [ebp-18h] BYREF
  AdvXMLParser::Parser *v4; // [esp+10h] [ebp-8h]
  unsigned __int8 Char; // [esp+17h] [ebp-1h]

  v4 = this;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v3, this);
  Char = AdvXMLParser::Parser::NextChar(v4);
  if ( AdvXMLParser::IsNameChar((AdvXMLParser *)Char, v3[0]) )
  {
    while ( AdvXMLParser::IsNameChar((AdvXMLParser *)Char, v3[0]) )
      Char = AdvXMLParser::Parser::NextChar(v4);
    AdvXMLParser::Parser::PreviousChar(v4);
    AdvXMLParser::Bookmark::GetSubString(a2, 0);
    return 1;
  }
  else
  {
    AdvXMLParser::Parser::PreviousChar(v4);
    return 0;
  }
}


