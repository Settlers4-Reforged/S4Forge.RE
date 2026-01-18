#include "Comment.h"

// Definitions for class Comment

// address=[0x2f16690]
// Decompiled from _DWORD *__thiscall AdvXMLParser::Comment::Comment(_DWORD *this, int a2)
 AdvXMLParser::Comment::Comment(std::string const & a2) {
  
  _BYTE v4[28]; // [esp+8h] [ebp-2Ch] BYREF
  int v5; // [esp+30h] [ebp-4h]

  std::string::string(v4, "#comment");
  v5 = 0;
  AdvXMLParser::Node::Node(AdvXMLParser::Node::null, v4);
  LOBYTE(v5) = 2;
  std::string::~string(v4);
  *this = &AdvXMLParser::Comment::_vftable_;
  std::string::string(a2);
  return this;
}


// address=[0x2f16730]
// Decompiled from _DWORD *__thiscall AdvXMLParser::Comment::Comment(_DWORD *this, int a2, int a3)
 AdvXMLParser::Comment::Comment(class AdvXMLParser::NodeContainer & a2, std::string const & a3) {
  
  _BYTE v5[28]; // [esp+8h] [ebp-2Ch] BYREF
  int v6; // [esp+30h] [ebp-4h]

  std::string::string(v5, "#comment");
  v6 = 0;
  AdvXMLParser::Node::Node(a2, v5);
  LOBYTE(v6) = 2;
  std::string::~string(v5);
  *this = &AdvXMLParser::Comment::_vftable_;
  std::string::string(a3);
  return this;
}


// address=[0x2f167d0]
// Decompiled from int __thiscall AdvXMLParser::Comment::Clone(AdvXMLParser::Comment *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Comment *  AdvXMLParser::Comment::Clone(class AdvXMLParser::NodeContainer & a2)const {
  
  int v3; // [esp+Ch] [ebp-44h]
  int v4; // [esp+14h] [ebp-3Ch]
  char v6; // [esp+20h] [ebp-30h]
  _BYTE v7[28]; // [esp+24h] [ebp-2Ch] BYREF
  int v8; // [esp+4Ch] [ebp-4h]

  v6 = 0;
  v8 = 0;
  if ( operator new(0x40u) )
  {
    v3 = (*(int (__thiscall **)(AdvXMLParser::Comment *, _BYTE *))(*(_DWORD *)this + 4))(this, v7);
    LOBYTE(v8) = 1;
    v6 = 1;
    v4 = AdvXMLParser::Comment::Comment(a2, v3);
  }
  else
  {
    v4 = 0;
  }
  v8 = -1;
  if ( (v6 & 1) != 0 )
    std::string::~string(v7);
  return v4;
}


// address=[0x2f168b0]
// Decompiled from int __thiscall AdvXMLParser::Comment::GetData(char *this, int a2)
std::string  AdvXMLParser::Comment::GetData(void a2)const {
  
  std::string::string(this + 36);
  return a2;
}


// address=[0x2f168f0]
// Decompiled from int __thiscall AdvXMLParser::Comment::GetValue(char *this, int a2)
std::string  AdvXMLParser::Comment::GetValue(void a2)const {
  
  std::string::string(this + 36);
  return a2;
}


// address=[0x2f16930]
// Decompiled from bool __thiscall AdvXMLParser::Comment::IsKindOf(AdvXMLParser::Comment *this, int a2)
bool  AdvXMLParser::Comment::IsKindOf(int a2)const {
  
  return a2 == 8 || AdvXMLParser::Node::IsKindOf(this, a2);
}


// address=[0x2f16960]
// Decompiled from int __thiscall AdvXMLParser::Comment::CloneNode(AdvXMLParser::Comment *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Node *  AdvXMLParser::Comment::CloneNode(class AdvXMLParser::NodeContainer & a2)const {
  
  return AdvXMLParser::Comment::Clone(this, a2);
}


// address=[0x2f1cd50]
// Decompiled from void __thiscall AdvXMLParser::Comment::~Comment(AdvXMLParser::Comment *this)
 AdvXMLParser::Comment::~Comment(void) {
  
  std::string::~string((char *)this + 36);
  AdvXMLParser::Node::~Node(this);
}


// address=[0x2f24560]
// Decompiled from int __cdecl AdvXMLParser::Comment::Parse(struct AdvXMLParser::Parser *a1, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Comment * __cdecl AdvXMLParser::Comment::Parse(class AdvXMLParser::Parser & a1, class AdvXMLParser::NodeContainer & a2) {
  
  unsigned __int8 Char; // al
  void *v4; // eax
  _BYTE v5[16]; // [esp+4h] [ebp-4Ch] BYREF
  int v6; // [esp+14h] [ebp-3Ch]
  int v7; // [esp+18h] [ebp-38h]
  int v8; // [esp+1Ch] [ebp-34h]
  void *C; // [esp+20h] [ebp-30h]
  _BYTE v10[28]; // [esp+24h] [ebp-2Ch] BYREF
  int v11; // [esp+4Ch] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseString(a1, "<!--") )
    return 0;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v5, a1);
  while ( !AdvXMLParser::Parser::ParseString(a1, "--") )
  {
    Char = AdvXMLParser::Parser::NextChar(a1);
    if ( !AdvXMLParser::IsXmlChar((AdvXMLParser *)Char) )
      AdvXMLParser::Parser::SyntaxError(a1, 2);
  }
  if ( !AdvXMLParser::Parser::ParseChar(a1, 62) )
    AdvXMLParser::Parser::SyntaxError(a1, 23);
  std::string::string();
  v11 = 0;
  AdvXMLParser::Bookmark::GetSubString(v10, 3);
  v4 = operator new(0x40u);
  C = v4;
  LOBYTE(v11) = 1;
  if ( v4 )
    v8 = AdvXMLParser::Comment::Comment(a2, v10);
  else
    v8 = 0;
  v7 = v8;
  v6 = v8;
  v11 = -1;
  std::string::~string(v10);
  return v6;
}


// address=[0x2f2d190]
// Decompiled from void __thiscall AdvXMLParser::Comment::GenerateXML(  AdvXMLParser::Comment *this,  struct AdvXMLParser::GenerateContext *a2)
void  AdvXMLParser::Comment::GenerateXML(class AdvXMLParser::GenerateContext & a2)const {
  
  AdvXMLParser::GenerateContext::GenerateStartTagIndentation(a2);
  AdvXMLParser::GenerateContext::operator+=("<!--");
  AdvXMLParser::GenerateContext::operator+=((char *)this + 36);
  AdvXMLParser::GenerateContext::operator+=("-->");
  AdvXMLParser::GenerateContext::GenerateNewLine(a2);
  AdvXMLParser::GenerateContext::EndTag(a2);
}


// address=[0x4685728]
// [Decompilation failed for static class AdvXMLParser::Comment AdvXMLParser::Comment::null]

