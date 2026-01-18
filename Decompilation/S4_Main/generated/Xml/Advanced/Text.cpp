#include "Text.h"

// Definitions for class Text

// address=[0x2f134b0]
// Decompiled from _DWORD *__thiscall AdvXMLParser::Text::Text(_DWORD *this, int a2)
 AdvXMLParser::Text::Text(std::string const & a2) {
  
  _BYTE v4[28]; // [esp+8h] [ebp-2Ch] BYREF
  int v5; // [esp+30h] [ebp-4h]

  std::string::string(v4, "#text");
  v5 = 0;
  AdvXMLParser::Node::Node(AdvXMLParser::Node::null, v4);
  LOBYTE(v5) = 2;
  std::string::~string(v4);
  *this = &AdvXMLParser::Text::_vftable_;
  std::string::string(a2);
  return this;
}


// address=[0x2f13550]
// Decompiled from _DWORD *__thiscall AdvXMLParser::Text::Text(_DWORD *this, int a2, int a3)
 AdvXMLParser::Text::Text(class AdvXMLParser::NodeContainer & a2, std::string const & a3) {
  
  _BYTE v5[28]; // [esp+8h] [ebp-2Ch] BYREF
  int v6; // [esp+30h] [ebp-4h]

  std::string::string(v5, "#text");
  v6 = 0;
  AdvXMLParser::Node::Node(a2, v5);
  LOBYTE(v6) = 2;
  std::string::~string(v5);
  *this = &AdvXMLParser::Text::_vftable_;
  std::string::string(a3);
  return this;
}


// address=[0x2f135f0]
// Decompiled from int __thiscall AdvXMLParser::Text::Clone(AdvXMLParser::Text *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Text *  AdvXMLParser::Text::Clone(class AdvXMLParser::NodeContainer & a2)const {
  
  if ( operator new(0x40u) )
    return AdvXMLParser::Text::Text(a2, (char *)this + 36);
  else
    return 0;
}


// address=[0x2f13680]
// Decompiled from int __thiscall AdvXMLParser::Text::GetData(char *this, int a2)
std::string  AdvXMLParser::Text::GetData(void a2)const {
  
  std::string::string(this + 36);
  return a2;
}


// address=[0x2f136c0]
// Decompiled from int __thiscall AdvXMLParser::Text::GetValue(char *this, int a2)
std::string  AdvXMLParser::Text::GetValue(void a2)const {
  
  std::string::string(this + 36);
  return a2;
}


// address=[0x2f13700]
// Decompiled from bool __thiscall AdvXMLParser::Text::IsKindOf(AdvXMLParser::Text *this, int a2)
bool  AdvXMLParser::Text::IsKindOf(int a2)const {
  
  return a2 == 3 || AdvXMLParser::Node::IsKindOf(this, a2);
}


// address=[0x2f13730]
// Decompiled from int __thiscall AdvXMLParser::Text::CloneNode(AdvXMLParser::Text *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Node *  AdvXMLParser::Text::CloneNode(class AdvXMLParser::NodeContainer & a2)const {
  
  return AdvXMLParser::Text::Clone(this, a2);
}


// address=[0x2f1ce60]
// Decompiled from void __thiscall AdvXMLParser::Text::~Text(AdvXMLParser::Text *this)
 AdvXMLParser::Text::~Text(void) {
  
  std::string::~string((char *)this + 36);
  AdvXMLParser::Node::~Node(this);
}


// address=[0x2f1e480]
// Decompiled from int __stdcall AdvXMLParser::Text::Concatenate(int a1)
void  AdvXMLParser::Text::Concatenate(std::string const & a1) {
  
  return std::string::operator+=(a1);
}


// address=[0x2f2cca0]
// Decompiled from void __thiscall AdvXMLParser::Text::GenerateXML(AdvXMLParser::Text *this, struct AdvXMLParser::GenerateContext *a2)
void  AdvXMLParser::Text::GenerateXML(class AdvXMLParser::GenerateContext &)const {
  
  int v2; // [esp+4h] [ebp-8Ch]
  int v3; // [esp+Ch] [ebp-84h]
  char *v4; // [esp+18h] [ebp-78h]
  int i; // [esp+20h] [ebp-70h]
  int v7; // [esp+28h] [ebp-68h]
  _BYTE v8[28]; // [esp+2Ch] [ebp-64h] BYREF
  _BYTE v9[28]; // [esp+48h] [ebp-48h] BYREF
  _BYTE v10[28]; // [esp+64h] [ebp-2Ch] BYREF
  int v11; // [esp+8Ch] [ebp-4h]

  std::string::string();
  v11 = 0;
  if ( !AdvXMLParser::GenerateContext::MustPreserve(a2) )
  {
    std::string::operator=((int)this + 36);
    AdvXMLParser::Element::Normalize((int)v10);
  }
  if ( AdvXMLParser::GenerateContext::MustPreserve(a2) )
    v4 = (char *)this + 36;
  else
    v4 = v10;
  v7 = 0;
  for ( i = std::string::find(34, 0);
        i != std::basic_string_char_std::char_traits_char__std::allocator_char___::npos;
        i = std::string::find(34, i + 1) )
  {
    v3 = std::string::substr(v9, v7, i - v7);
    LOBYTE(v11) = 1;
    AdvXMLParser::GenerateContext::operator+=(v3);
    LOBYTE(v11) = 0;
    std::string::~string(v9);
    AdvXMLParser::GenerateContext::operator+=("&quote;");
    v7 = i + 1;
  }
  if ( AdvXMLParser::GenerateContext::MustPreserve(a2) || (unsigned __int8)std::operator!=<char>(v4, " ") )
  {
    v2 = std::string::substr(v8, v7, std::basic_string_char_std::char_traits_char__std::allocator_char___::npos);
    LOBYTE(v11) = 2;
    AdvXMLParser::GenerateContext::operator+=(v2);
    LOBYTE(v11) = 0;
    std::string::~string(v8);
  }
  v11 = -1;
  std::string::~string(v10);
}


