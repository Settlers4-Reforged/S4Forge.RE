#include "Document.h"

// Definitions for class Document

// address=[0x14f3f30]
// Decompiled from void *__thiscall AdvXMLParser::Document::GetRoot(AdvXMLParser::Document *this)

class AdvXMLParser::Element &  AdvXMLParser::Document::GetRoot(void)const {
  
  if ( *((_DWORD *)this + 29) )
    return (void *)*((_DWORD *)this + 29);
  else
    return &AdvXMLParser::Element::null;
}


// address=[0x2f16f20]
// Decompiled from AdvXMLParser::Document *__thiscall AdvXMLParser::Document::Document(AdvXMLParser::Document *this)

 AdvXMLParser::Document::Document(void) {
  
  _BYTE v3[28]; // [esp+8h] [ebp-2Ch] BYREF
  int v4; // [esp+30h] [ebp-4h]

  std::string::string(v3, "#document");
  v4 = 0;
  AdvXMLParser::NodeContainer::NodeContainer(AdvXMLParser::Node::null, v3);
  LOBYTE(v4) = 2;
  std::string::~string(v3);
  *(_DWORD *)this = &AdvXMLParser::Document::_vftable_;
  std::string::string((char *)this + 56, "1.0");
  LOBYTE(v4) = 3;
  std::string::string((char *)this + 84, "UTF-8");
  LOBYTE(v4) = 4;
  *((_BYTE *)this + 112) = 1;
  *((_DWORD *)this + 29) = 0;
  AdvXMLParser::Dtd::Dtd((AdvXMLParser::Document *)((char *)this + 120), (struct Document *)this);
  return this;
}


// address=[0x2f17000]
// Decompiled from int __thiscall AdvXMLParser::Document::Document(int this, char *Str)

 AdvXMLParser::Document::Document(char const *) {
  
  int v3; // [esp+8h] [ebp-58h]
  _DWORD *C; // [esp+Ch] [ebp-54h]
  char v5; // [esp+10h] [ebp-50h]
  _BYTE v7[28]; // [esp+18h] [ebp-48h] BYREF
  _BYTE v8[28]; // [esp+34h] [ebp-2Ch] BYREF
  int v9; // [esp+5Ch] [ebp-4h]

  v5 = 0;
  std::string::string(v8, "#document");
  v9 = 0;
  AdvXMLParser::NodeContainer::NodeContainer(AdvXMLParser::Node::null, v8);
  LOBYTE(v9) = 2;
  std::string::~string(v8);
  *(_DWORD *)this = &AdvXMLParser::Document::_vftable_;
  std::string::string((void *)(this + 56), "1.0");
  LOBYTE(v9) = 3;
  std::string::string((void *)(this + 84), "UTF-8");
  LOBYTE(v9) = 4;
  *(_BYTE *)(this + 112) = 1;
  C = operator new(0x4Cu);
  LOBYTE(v9) = 5;
  if ( C )
  {
    std::string::string(v7, Str);
    LOBYTE(v9) = 6;
    v5 = 1;
    v3 = AdvXMLParser::Element::Element(C, this, (int)v7);
  }
  else
  {
    v3 = 0;
  }
  *(_DWORD *)(this + 116) = v3;
  v9 = 4;
  if ( (v5 & 1) != 0 )
    std::string::~string(v7);
  AdvXMLParser::Dtd::Dtd((AdvXMLParser::Dtd *)(this + 120), (struct Document *)this);
  AdvXMLParser::NodeContainer::Add((AdvXMLParser::NodeContainer *)this, *(struct Node **)(this + 116));
  return this;
}


// address=[0x2f17160]
// Decompiled from int __thiscall AdvXMLParser::Document::Clone(AdvXMLParser::Document *this)

class AdvXMLParser::Document *  AdvXMLParser::Document::Clone(void)const {
  
  struct AdvXMLParser::NodeContainer *v1; // eax
  int v3; // [esp+4h] [ebp-24h]
  int v5; // [esp+10h] [ebp-18h]
  AdvXMLParser::Document *C; // [esp+14h] [ebp-14h]
  _BYTE v7[4]; // [esp+18h] [ebp-10h] BYREF
  int v8; // [esp+24h] [ebp-4h]

  C = (AdvXMLParser::Document *)operator new(0x7Cu);
  v8 = 0;
  if ( C )
    v5 = AdvXMLParser::Document::Document(C);
  else
    v5 = 0;
  std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v5);
  v8 = 1;
  v1 = (struct AdvXMLParser::NodeContainer *)std::auto_ptr<AdvXMLParser::Document>::operator*();
  AdvXMLParser::NodeContainer::CloneChildren(this, v1);
  v3 = std::auto_ptr<AdvXMLParser::Document>::release(v7);
  v8 = -1;
  std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v7);
  return v3;
}


// address=[0x2f17220]
// Decompiled from void *__stdcall AdvXMLParser::Document::GetData(void *a1)

std::string  AdvXMLParser::Document::GetData(void)const {
  
  std::string::string(a1, (char *)byte_3AB75C2);
  return a1;
}


// address=[0x2f17250]
// Decompiled from int __thiscall AdvXMLParser::Document::GetValue(void *this, int a2)

std::string  AdvXMLParser::Document::GetValue(void)const {
  
  _BYTE v3[12]; // [esp+4h] [ebp-80h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-74h] BYREF
  int v5; // [esp+1Ch] [ebp-68h]
  int v6; // [esp+20h] [ebp-64h]
  std::_Iterator_base12 *v7; // [esp+24h] [ebp-60h]
  std::_Iterator_base12 *v8; // [esp+28h] [ebp-5Ch]
  int v9; // [esp+2Ch] [ebp-58h]
  int v10; // [esp+30h] [ebp-54h]
  void *v11; // [esp+34h] [ebp-50h]
  char v12; // [esp+3Bh] [ebp-49h]
  _BYTE v13[28]; // [esp+3Ch] [ebp-48h] BYREF
  _BYTE v14[28]; // [esp+58h] [ebp-2Ch] BYREF
  int v15; // [esp+80h] [ebp-4h]

  v11 = this;
  v9 = 0;
  std::string::string();
  v15 = 0;
  std::vector<AdvXMLParser::Node *>::begin(v4);
  LOBYTE(v15) = 1;
  while ( 1 )
  {
    v8 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v3);
    v7 = v8;
    LOBYTE(v15) = 2;
    v12 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v8);
    LOBYTE(v15) = 1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
    if ( !v12 )
      break;
    v10 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v4);
    v6 = (*(int (__thiscall **)(int, _BYTE *))(*(_DWORD *)v10 + 8))(v10, v13);
    v5 = v6;
    LOBYTE(v15) = 3;
    std::string::operator+=(v6);
    LOBYTE(v15) = 1;
    std::string::~string(v13);
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(v4);
  }
  LOBYTE(v15) = 0;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
  AdvXMLParser::NormalizeWhiteSpaces(v14);
  AdvXMLParser::TrimSpaces(v14);
  std::string::string(v14);
  v9 |= 1u;
  v15 = -1;
  std::string::~string(v14);
  return a2;
}


// address=[0x2f173a0]
// Decompiled from bool __thiscall AdvXMLParser::Document::IsKindOf(AdvXMLParser::Document *this, int a2)

bool  AdvXMLParser::Document::IsKindOf(int)const {
  
  return a2 == 9 || AdvXMLParser::Node::IsKindOf(this, a2);
}


// address=[0x2f173d0]
// Decompiled from int __thiscall AdvXMLParser::Document::CloneNode(AdvXMLParser::Document *this, struct AdvXMLParser::NodeContainer *a2)

class AdvXMLParser::Node *  AdvXMLParser::Document::CloneNode(class AdvXMLParser::NodeContainer &)const {
  
  if ( !AdvXMLParser::Node::IsNull(a2)
    && BBSupportDbgReport(2, "Source\\Xml\\elements.cpp", 1107, "parent.IsNull()") == 1 )
  {
    __debugbreak();
  }
  return AdvXMLParser::Document::Clone(this);
}


// address=[0x2f1cd80]
// Decompiled from void __thiscall AdvXMLParser::Document::~Document(AdvXMLParser::Document *this)

 AdvXMLParser::Document::~Document(void) {
  
  std::string::~string((char *)this + 84);
  std::string::~string((char *)this + 56);
  AdvXMLParser::NodeContainer::~NodeContainer(this);
}


// address=[0x2f25fc0]
// Decompiled from int __cdecl AdvXMLParser::Document::Parse(struct AdvXMLParser::Parser *a1)

static class AdvXMLParser::Document * __cdecl AdvXMLParser::Document::Parse(class AdvXMLParser::Parser &) {
  
  AdvXMLParser::Document *v1; // eax
  AdvXMLParser::Document *v2; // eax
  AdvXMLParser::Document *v3; // eax
  struct AdvXMLParser::Parser *v5; // [esp-4h] [ebp-28h]
  struct AdvXMLParser::Parser *v6; // [esp-4h] [ebp-28h]
  struct AdvXMLParser::Parser *v7; // [esp-4h] [ebp-28h]
  int v8; // [esp+4h] [ebp-20h]
  int v9; // [esp+Ch] [ebp-18h]
  AdvXMLParser::Document *C; // [esp+10h] [ebp-14h]
  _BYTE v11[4]; // [esp+14h] [ebp-10h] BYREF
  int v12; // [esp+20h] [ebp-4h]

  C = (AdvXMLParser::Document *)operator new(0x7Cu);
  v12 = 0;
  if ( C )
    v9 = AdvXMLParser::Document::Document(C);
  else
    v9 = 0;
  std::auto_ptr<AdvXMLParser::Document>::auto_ptr<AdvXMLParser::Document>(v9);
  v12 = 1;
  v1 = (AdvXMLParser::Document *)std::auto_ptr<AdvXMLParser::Document>::operator->(a1);
  AdvXMLParser::Document::ParseProlog(v1, v5);
  v2 = (AdvXMLParser::Document *)std::auto_ptr<AdvXMLParser::Document>::operator->(a1);
  AdvXMLParser::Document::ParseRootElement(v2, v6);
  v3 = (AdvXMLParser::Document *)std::auto_ptr<AdvXMLParser::Document>::operator->(a1);
  AdvXMLParser::Document::ParseMiscs(v3, v7);
  if ( AdvXMLParser::Parser::NextChar(a1) )
    AdvXMLParser::Parser::SyntaxError(a1, 43);
  v8 = std::auto_ptr<AdvXMLParser::Document>::release(v11);
  v12 = -1;
  std::auto_ptr<AdvXMLParser::Document>::~auto_ptr<AdvXMLParser::Document>(v11);
  return v8;
}


// address=[0x2f260c0]
// Decompiled from void __thiscall AdvXMLParser::Document::ParseProlog(AdvXMLParser::Document *this, struct AdvXMLParser::Parser *a2)

void  AdvXMLParser::Document::ParseProlog(class AdvXMLParser::Parser &) {
  
  AdvXMLParser::Document::ParseXMLDecl(this, a2);
  AdvXMLParser::Document::ParseMiscs(this, a2);
  if ( AdvXMLParser::Dtd::ParseDoctypedecl((AdvXMLParser::Document *)((char *)this + 120), a2) )
    AdvXMLParser::Document::ParseMiscs(this, a2);
}


// address=[0x2f26110]
// Decompiled from char __thiscall AdvXMLParser::Document::ParseXMLDecl(AdvXMLParser::Document *this, struct AdvXMLParser::Parser *a2)

bool  AdvXMLParser::Document::ParseXMLDecl(class AdvXMLParser::Parser &) {
  
  if ( !AdvXMLParser::Parser::ParseString(a2, "<?xml") )
    return 0;
  if ( !(unsigned __int8)AdvXMLParser::Document::ParseVersionInfo(a2, (char *)this + 56) )
    AdvXMLParser::Parser::SyntaxError(a2, 17);
  AdvXMLParser::Document::ParseEncodingDecl(a2, (char *)this + 84);
  AdvXMLParser::Document::ParseSDDecl(this, a2, (bool *)this + 112);
  AdvXMLParser::Parser::ParseSpaces(a2);
  if ( !AdvXMLParser::Parser::ParseString(a2, "?>") )
    AdvXMLParser::Parser::SyntaxError(a2, 18);
  return 1;
}


// address=[0x2f261b0]
// Decompiled from char __stdcall AdvXMLParser::Document::ParseVersionInfo(AdvXMLParser::Parser *a1, int a2)

bool  AdvXMLParser::Document::ParseVersionInfo(class AdvXMLParser::Parser &,std::string &) {
  
  char Char; // [esp+7h] [ebp-1h]

  if ( !AdvXMLParser::Parser::ParseDeclBegining(a1, "version") )
    return 0;
  Char = AdvXMLParser::Parser::NextChar(a1);
  if ( Char != 39 && Char != 34 )
    AdvXMLParser::Parser::SyntaxError(a1, 17);
  if ( !(unsigned __int8)AdvXMLParser::Document::ParseVersionNum(a1, a2) || AdvXMLParser::Parser::NextChar(a1) != Char )
    AdvXMLParser::Parser::SyntaxError(a1, 17);
  return 1;
}


// address=[0x2f26240]
// Decompiled from char __thiscall AdvXMLParser::Document::ParseVersionNum(void *this, struct AdvXMLParser::Parser *a2, int a3)

bool  AdvXMLParser::Document::ParseVersionNum(class AdvXMLParser::Parser &,std::string &) {
  
  char v4[16]; // [esp+0h] [ebp-18h] BYREF
  void *v5; // [esp+10h] [ebp-8h]
  unsigned __int8 Char; // [esp+17h] [ebp-1h]

  v5 = this;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v4, a2);
  Char = AdvXMLParser::Parser::NextChar(a2);
  if ( AdvXMLParser::IsAlphaDigit((AdvXMLParser *)Char, v4[0]) || Char == 95 || Char == 46 || Char == 58 || Char == 45 )
  {
    do
    {
      do
        Char = AdvXMLParser::Parser::NextChar(a2);
      while ( AdvXMLParser::IsAlphaDigit((AdvXMLParser *)Char, v4[0]) );
    }
    while ( Char == 95 || Char == 46 || Char == 58 || Char == 45 );
    AdvXMLParser::Parser::PreviousChar(a2);
    AdvXMLParser::Bookmark::GetSubString(a3, 0);
    return 1;
  }
  else
  {
    AdvXMLParser::Parser::PreviousChar(a2);
    return 0;
  }
}


// address=[0x2f26320]
// Decompiled from char __stdcall AdvXMLParser::Document::ParseEncodingDecl(AdvXMLParser::Parser *a1, int a2)

bool  AdvXMLParser::Document::ParseEncodingDecl(class AdvXMLParser::Parser &,std::string &) {
  
  char Char; // [esp+7h] [ebp-1h]

  if ( !AdvXMLParser::Parser::ParseDeclBegining(a1, "encoding") )
    return 0;
  Char = AdvXMLParser::Parser::NextChar(a1);
  if ( Char != 39 && Char != 34 )
    AdvXMLParser::Parser::SyntaxError(a1, 19);
  if ( !(unsigned __int8)AdvXMLParser::Document::ParseEncName(a1, a2) || AdvXMLParser::Parser::NextChar(a1) != Char )
    AdvXMLParser::Parser::SyntaxError(a1, 20);
  return 1;
}


// address=[0x2f263b0]
// Decompiled from char __thiscall AdvXMLParser::Document::ParseEncName(void *this, struct AdvXMLParser::Parser *a2, int a3)

bool  AdvXMLParser::Document::ParseEncName(class AdvXMLParser::Parser &,std::string &) {
  
  char v4[16]; // [esp+0h] [ebp-18h] BYREF
  void *v5; // [esp+10h] [ebp-8h]
  unsigned __int8 Char; // [esp+17h] [ebp-1h]

  v5 = this;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v4, a2);
  Char = AdvXMLParser::Parser::NextChar(a2);
  if ( AdvXMLParser::IsAlpha((AdvXMLParser *)Char, v4[0]) )
  {
    do
    {
      do
        Char = AdvXMLParser::Parser::NextChar(a2);
      while ( AdvXMLParser::IsAlphaDigit((AdvXMLParser *)Char, v4[0]) );
    }
    while ( Char == 95 || Char == 46 || Char == 45 );
    AdvXMLParser::Parser::PreviousChar(a2);
    AdvXMLParser::Bookmark::GetSubString(a3, 0);
    return 1;
  }
  else
  {
    AdvXMLParser::Parser::PreviousChar(a2);
    return 0;
  }
}


// address=[0x2f26460]
// Decompiled from char __thiscall AdvXMLParser::Document::ParseSDDecl(
        AdvXMLParser::Document *this,
        struct AdvXMLParser::Parser *a2,
        bool *a3)

bool  AdvXMLParser::Document::ParseSDDecl(class AdvXMLParser::Parser &,bool &) {
  
  char Char; // [esp+7h] [ebp-1h]

  if ( !AdvXMLParser::Parser::ParseDeclBegining(a2, "standalone") )
    return 0;
  Char = AdvXMLParser::Parser::NextChar(a2);
  if ( Char != 39 && Char != 34 )
    AdvXMLParser::Parser::SyntaxError(a2, 21);
  if ( AdvXMLParser::Parser::ParseString(a2, "yes") )
  {
    *a3 = 1;
  }
  else
  {
    if ( !AdvXMLParser::Parser::ParseString(a2, "no") )
      AdvXMLParser::Parser::SyntaxError(a2, 22);
    *a3 = 0;
  }
  if ( AdvXMLParser::Parser::NextChar(a2) != Char )
    AdvXMLParser::Parser::SyntaxError(a2, 22);
  return 1;
}


// address=[0x2f26520]
// Decompiled from char __thiscall AdvXMLParser::Document::ParseMisc(AdvXMLParser::Document *this, struct AdvXMLParser::Parser *a2)

bool  AdvXMLParser::Document::ParseMisc(class AdvXMLParser::Parser &) {
  
  struct AdvXMLParser::Comment *v2; // eax
  struct Node *v3; // eax
  struct AdvXMLParser::Pi *v5; // eax
  struct Node *v6; // eax
  _BYTE v7[4]; // [esp+4h] [ebp-1Ch] BYREF
  AdvXMLParser::NodeContainer *v8; // [esp+8h] [ebp-18h]
  _BYTE v9[5]; // [esp+Ch] [ebp-14h] BYREF
  bool v10; // [esp+11h] [ebp-Fh]
  char v11; // [esp+12h] [ebp-Eh]
  char v12; // [esp+13h] [ebp-Dh]
  int v13; // [esp+1Ch] [ebp-4h]

  v8 = this;
  v2 = AdvXMLParser::Comment::Parse(a2, this);
  std::auto_ptr<AdvXMLParser::Comment>::auto_ptr<AdvXMLParser::Comment>(v2);
  v13 = 0;
  if ( std::auto_ptr<AdvXMLParser::Comment>::get(v9) )
  {
    v3 = (struct Node *)std::auto_ptr<AdvXMLParser::Comment>::release(v9);
    AdvXMLParser::NodeContainer::Add(v8, v3);
    v12 = 1;
    v13 = -1;
    std::auto_ptr<AdvXMLParser::Comment>::~auto_ptr<AdvXMLParser::Comment>(v9);
    return v12;
  }
  else
  {
    v5 = AdvXMLParser::Pi::Parse(a2, v8);
    std::auto_ptr<AdvXMLParser::Pi>::auto_ptr<AdvXMLParser::Pi>(v5);
    LOBYTE(v13) = 1;
    if ( std::auto_ptr<AdvXMLParser::Pi>::get(v7) )
    {
      v6 = (struct Node *)std::auto_ptr<AdvXMLParser::Pi>::release(v7);
      AdvXMLParser::NodeContainer::Add(v8, v6);
      v11 = 1;
      LOBYTE(v13) = 0;
      std::auto_ptr<AdvXMLParser::Pi>::~auto_ptr<AdvXMLParser::Pi>(v7);
      v13 = -1;
      std::auto_ptr<AdvXMLParser::Comment>::~auto_ptr<AdvXMLParser::Comment>(v9);
      return v11;
    }
    else
    {
      v10 = AdvXMLParser::Parser::ParseSpaces(a2);
      LOBYTE(v13) = 0;
      std::auto_ptr<AdvXMLParser::Pi>::~auto_ptr<AdvXMLParser::Pi>(v7);
      v13 = -1;
      std::auto_ptr<AdvXMLParser::Comment>::~auto_ptr<AdvXMLParser::Comment>(v9);
      return v10;
    }
  }
}


// address=[0x2f26640]
// Decompiled from char __thiscall AdvXMLParser::Document::ParseMiscs(AdvXMLParser::Document *this, struct AdvXMLParser::Parser *a2)

void  AdvXMLParser::Document::ParseMiscs(class AdvXMLParser::Parser &) {
  
  char result; // al

  do
    result = AdvXMLParser::Document::ParseMisc(this, a2);
  while ( result );
  return result;
}


// address=[0x2f2d2b0]
// Decompiled from void __thiscall AdvXMLParser::Document::GenerateXML(
        AdvXMLParser::Document *this,
        struct AdvXMLParser::GenerateContext *a2)

void  AdvXMLParser::Document::GenerateXML(class AdvXMLParser::GenerateContext &)const {
  
  AdvXMLParser::GenerateContext::operator+=("<?xml version=\"");
  AdvXMLParser::GenerateContext::operator+=((char *)this + 56);
  AdvXMLParser::GenerateContext::operator+=("\" encoding=\"");
  AdvXMLParser::GenerateContext::operator+=((char *)this + 84);
  AdvXMLParser::GenerateContext::operator+=("\"?>");
  AdvXMLParser::GenerateContext::GenerateNewLine(a2);
  AdvXMLParser::NodeContainer::GenerateXML(this, a2);
}


// address=[0x2f26670]
// Decompiled from int __thiscall AdvXMLParser::Document::ParseRootElement(AdvXMLParser::Document *this, struct AdvXMLParser::Parser *a2)

void  AdvXMLParser::Document::ParseRootElement(class AdvXMLParser::Parser &) {
  
  int v2; // eax
  struct Node *v3; // eax
  _BYTE v6[4]; // [esp+8h] [ebp-10h] BYREF
  int v7; // [esp+14h] [ebp-4h]

  v2 = AdvXMLParser::Element::Parse(a2, this);
  std::auto_ptr<AdvXMLParser::Element>::auto_ptr<AdvXMLParser::Element>(v2);
  v7 = 0;
  if ( !std::auto_ptr<AdvXMLParser::Element>::get(v6) )
    AdvXMLParser::Parser::SyntaxError(a2, 16);
  *((_DWORD *)this + 29) = std::auto_ptr<AdvXMLParser::Element>::get(v6);
  v3 = (struct Node *)std::auto_ptr<AdvXMLParser::Element>::release(v6);
  AdvXMLParser::NodeContainer::Add(this, v3);
  v7 = -1;
  return std::auto_ptr<AdvXMLParser::Element>::~auto_ptr<AdvXMLParser::Element>(v6);
}


