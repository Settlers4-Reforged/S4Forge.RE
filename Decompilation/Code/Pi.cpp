#include "Pi.h"

// Definitions for class Pi

// address=[0x2f16980]
// Decompiled from _DWORD *__thiscall AdvXMLParser::Pi::Pi(_DWORD *this, int a2, int a3)
 AdvXMLParser::Pi::Pi(std::string const &,std::string const &) {
  
  AdvXMLParser::Node::Node(AdvXMLParser::Node::null, a2);
  *this = &AdvXMLParser::Pi::_vftable_;
  std::string::string(a3);
  return this;
}


// address=[0x2f16a00]
// Decompiled from _DWORD *__thiscall AdvXMLParser::Pi::Pi(_DWORD *this, int a2, int a3, int a4)
 AdvXMLParser::Pi::Pi(class AdvXMLParser::NodeContainer &,std::string const &,std::string const &) {
  
  AdvXMLParser::Node::Node(a2, a3);
  *this = &AdvXMLParser::Pi::_vftable_;
  std::string::string(a4);
  return this;
}


// address=[0x2f16a70]
// Decompiled from _DWORD *__thiscall AdvXMLParser::Pi::Clone(AdvXMLParser::Pi *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Pi *  AdvXMLParser::Pi::Clone(class AdvXMLParser::NodeContainer &)const {
  
  int Name; // eax
  int v4; // [esp+Ch] [ebp-44h]
  _DWORD *v5; // [esp+14h] [ebp-3Ch]
  _DWORD *C; // [esp+18h] [ebp-38h]
  char v8; // [esp+20h] [ebp-30h]
  _BYTE v9[28]; // [esp+24h] [ebp-2Ch] BYREF
  int v10; // [esp+4Ch] [ebp-4h]

  v8 = 0;
  C = operator new(0x40u);
  v10 = 0;
  if ( C )
  {
    v4 = (*(int (__thiscall **)(AdvXMLParser::Pi *, _BYTE *))(*(_DWORD *)this + 4))(this, v9);
    LOBYTE(v10) = 1;
    v8 = 1;
    Name = AdvXMLParser::Node::GetName(this);
    v5 = AdvXMLParser::Pi::Pi(C, (int)a2, Name, v4);
  }
  else
  {
    v5 = 0;
  }
  v10 = -1;
  if ( (v8 & 1) != 0 )
    std::string::~string(v9);
  return v5;
}


// address=[0x2f16b60]
// Decompiled from int __thiscall AdvXMLParser::Pi::GetData(char *this, int a2)
std::string  AdvXMLParser::Pi::GetData(void)const {
  
  std::string::string(this + 36);
  return a2;
}


// address=[0x2f16ba0]
// Decompiled from int __thiscall AdvXMLParser::Pi::GetValue(char *this, int a2)
std::string  AdvXMLParser::Pi::GetValue(void)const {
  
  std::string::string(this + 36);
  return a2;
}


// address=[0x2f16be0]
// Decompiled from bool __thiscall AdvXMLParser::Pi::IsKindOf(AdvXMLParser::Pi *this, int a2)
bool  AdvXMLParser::Pi::IsKindOf(int)const {
  
  return a2 == 7 || AdvXMLParser::Node::IsKindOf(this, a2);
}


// address=[0x2f16c10]
// Decompiled from _DWORD *__thiscall AdvXMLParser::Pi::CloneNode(AdvXMLParser::Pi *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Node *  AdvXMLParser::Pi::CloneNode(class AdvXMLParser::NodeContainer &)const {
  
  return AdvXMLParser::Pi::Clone(this, a2);
}


// address=[0x2f1ce10]
// Decompiled from void __thiscall AdvXMLParser::Pi::~Pi(AdvXMLParser::Pi *this)
 AdvXMLParser::Pi::~Pi(void) {
  
  std::string::~string((char *)this + 36);
  AdvXMLParser::Node::~Node(this);
}


// address=[0x2f246a0]
// Decompiled from _DWORD *__cdecl AdvXMLParser::Pi::Parse(struct AdvXMLParser::Parser *a1, struct AdvXMLParser::NodeContainer *a2)
static class AdvXMLParser::Pi * __cdecl AdvXMLParser::Pi::Parse(class AdvXMLParser::Parser &,class AdvXMLParser::NodeContainer &) {
  
  unsigned __int8 Char; // al
  char v4[16]; // [esp+4h] [ebp-68h] BYREF
  _DWORD *v5; // [esp+14h] [ebp-58h]
  _DWORD *v6; // [esp+18h] [ebp-54h]
  _DWORD *v7; // [esp+1Ch] [ebp-50h]
  void *C; // [esp+20h] [ebp-4Ch]
  _BYTE v9[28]; // [esp+24h] [ebp-48h] BYREF
  _BYTE v10[28]; // [esp+40h] [ebp-2Ch] BYREF
  int v11; // [esp+68h] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseString(a1, "<?") )
    return 0;
  std::string::string();
  v11 = 0;
  if ( !(unsigned __int8)AdvXMLParser::Pi::ParsePITarget(a1, v9) )
    AdvXMLParser::Parser::SyntaxError(a1, 24);
  AdvXMLParser::Parser::ParseSpaces(a1);
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v4, a1);
  while ( !AdvXMLParser::Parser::ParseString(a1, "?>") )
  {
    Char = AdvXMLParser::Parser::NextChar(a1);
    if ( !AdvXMLParser::IsXmlChar((AdvXMLParser *)Char) )
      AdvXMLParser::Parser::SyntaxError(a1, 2);
  }
  std::string::string();
  LOBYTE(v11) = 1;
  AdvXMLParser::Bookmark::GetSubString(v10, 2);
  C = operator new(0x40u);
  LOBYTE(v11) = 2;
  if ( C )
    v7 = AdvXMLParser::Pi::Pi(C, (int)a2, (int)v9, (int)v10);
  else
    v7 = 0;
  v6 = v7;
  v5 = v7;
  LOBYTE(v11) = 0;
  std::string::~string(v10);
  v11 = -1;
  std::string::~string(v9);
  return v5;
}


// address=[0x2f2d1e0]
// Decompiled from void __thiscall AdvXMLParser::Pi::GenerateXML(AdvXMLParser::Pi *this, struct AdvXMLParser::GenerateContext *a2)
void  AdvXMLParser::Pi::GenerateXML(class AdvXMLParser::GenerateContext &)const {
  
  int Name; // eax

  AdvXMLParser::GenerateContext::GenerateStartTagIndentation(a2);
  AdvXMLParser::GenerateContext::operator+=("<?");
  Name = AdvXMLParser::Node::GetName(this);
  AdvXMLParser::GenerateContext::operator+=(Name);
  if ( !(unsigned __int8)std::string::empty((char *)this + 36) )
  {
    AdvXMLParser::GenerateContext::operator+=(32);
    AdvXMLParser::GenerateContext::operator+=((char *)this + 36);
  }
  AdvXMLParser::GenerateContext::operator+=("?>");
  AdvXMLParser::GenerateContext::GenerateNewLine(a2);
  AdvXMLParser::GenerateContext::EndTag(a2);
}


// address=[0x4685618]
// [Decompilation failed for static class AdvXMLParser::Pi AdvXMLParser::Pi::null]

// address=[0x2f24800]
// Decompiled from char __cdecl AdvXMLParser::Pi::ParsePITarget(int a1, int a2)
static bool __cdecl AdvXMLParser::Pi::ParsePITarget(class AdvXMLParser::Parser &,std::string &) {
  
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // eax

  if ( !(unsigned __int8)AdvXMLParser::Parser::ParseName(a2) )
    return 0;
  if ( std::string::length(a2) != 3 )
    return 1;
  v3 = (unsigned __int8 *)std::string::operator[](0);
  if ( AdvXMLParser::LowCase((AdvXMLParser *)*v3) != 120 )
    return 1;
  v4 = (unsigned __int8 *)std::string::operator[](1);
  if ( AdvXMLParser::LowCase((AdvXMLParser *)*v4) != 109 )
    return 1;
  v5 = (unsigned __int8 *)std::string::operator[](2);
  if ( AdvXMLParser::LowCase((AdvXMLParser *)*v5) == 108 )
    AdvXMLParser::Parser::SyntaxError(a1, 25);
  return 1;
}


