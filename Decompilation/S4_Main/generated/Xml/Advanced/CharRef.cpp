#include "all_headers.h"

// Definitions for class CharRef

// address=[0x2f14c20]
// Decompiled from AdvXMLParser::CharRef *__thiscall AdvXMLParser::CharRef::CharRef(AdvXMLParser::CharRef *this, char a2)
 AdvXMLParser::CharRef::CharRef(int) {
  
  _BYTE v4[28]; // [esp+8h] [ebp-2Ch] BYREF
  int v5; // [esp+30h] [ebp-4h]

  std::string::string(v4, (char *)&byte_3AB74EB);
  v5 = 0;
  AdvXMLParser::Reference::Reference(AdvXMLParser::Node::null, v4);
  v5 = -1;
  std::string::~string(v4);
  *(_DWORD *)this = &AdvXMLParser::CharRef::_vftable_;
  *((_BYTE *)this + 36) = a2;
  return this;
}


// address=[0x2f14cc0]
// Decompiled from AdvXMLParser::CharRef *__thiscall AdvXMLParser::CharRef::CharRef(  AdvXMLParser::CharRef *this,  struct AdvXMLParser::NodeContainer *a2,  char a3)
 AdvXMLParser::CharRef::CharRef(class AdvXMLParser::NodeContainer &,int) {
  
  _BYTE v5[28]; // [esp+8h] [ebp-2Ch] BYREF
  int v6; // [esp+30h] [ebp-4h]

  std::string::string(v5, (char *)&byte_3AB751B);
  v6 = 0;
  AdvXMLParser::Reference::Reference(a2, v5);
  v6 = -1;
  std::string::~string(v5);
  *(_DWORD *)this = &AdvXMLParser::CharRef::_vftable_;
  *((_BYTE *)this + 36) = a3;
  return this;
}


// address=[0x2f14d50]
// Decompiled from int __thiscall AdvXMLParser::CharRef::Clone(AdvXMLParser::CharRef *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::CharRef *  AdvXMLParser::CharRef::Clone(class AdvXMLParser::NodeContainer &)const {
  
  AdvXMLParser::CharRef *C; // [esp+10h] [ebp-10h]

  C = (AdvXMLParser::CharRef *)operator new(0x28u);
  if ( C )
    return AdvXMLParser::CharRef::CharRef(C, a2, *((char *)this + 36));
  else
    return 0;
}


// address=[0x2f14de0]
// Decompiled from int __thiscall AdvXMLParser::CharRef::GetData(char *this, int a2)
std::string  AdvXMLParser::CharRef::GetData(void)const {
  
  std::string::string(1u, this[36]);
  return a2;
}


// address=[0x2f14e20]
// Decompiled from int __thiscall AdvXMLParser::CharRef::GetValue(char *this, int a2)
std::string  AdvXMLParser::CharRef::GetValue(void)const {
  
  std::string::string(1u, this[36]);
  return a2;
}


// address=[0x2f14e60]
// Decompiled from int __thiscall AdvXMLParser::CharRef::CloneNode(AdvXMLParser::CharRef *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Node *  AdvXMLParser::CharRef::CloneNode(class AdvXMLParser::NodeContainer &)const {
  
  return AdvXMLParser::CharRef::Clone(this, a2);
}


// address=[0x2f1cd30]
// Decompiled from void __thiscall AdvXMLParser::CharRef::~CharRef(AdvXMLParser::CharRef *this)
 AdvXMLParser::CharRef::~CharRef(void) {
  
  AdvXMLParser::Reference::~Reference(this);
}


// address=[0x2f23a10]
// Decompiled from int __cdecl AdvXMLParser::CharRef::Parse(struct AdvXMLParser::Parser *a1, struct AdvXMLParser::NodeContainer *a2)
static class AdvXMLParser::CharRef * __cdecl AdvXMLParser::CharRef::Parse(class AdvXMLParser::Parser &,class AdvXMLParser::NodeContainer &) {
  
  AdvXMLParser::CharRef *C; // [esp+Ch] [ebp-18h]
  int v5; // [esp+10h] [ebp-14h] BYREF
  char Char; // [esp+17h] [ebp-Dh]
  int v7; // [esp+20h] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseString(a1, "&#") )
    return 0;
  v5 = 0;
  Char = AdvXMLParser::Parser::NextChar(a1);
  if ( Char == 120 )
  {
    if ( !AdvXMLParser::Parser::ParseHexNumber(a1, &v5) )
      AdvXMLParser::Parser::SyntaxError(a1, 7);
  }
  else
  {
    AdvXMLParser::Parser::PreviousChar(a1);
    if ( !AdvXMLParser::Parser::ParseNumber(a1, &v5) )
      AdvXMLParser::Parser::SyntaxError(a1, 8);
  }
  if ( !AdvXMLParser::Parser::ParseChar(a1, 59) )
    AdvXMLParser::Parser::SyntaxError(a1, 6);
  if ( !AdvXMLParser::IsXmlChar((AdvXMLParser *)(unsigned __int8)v5) )
    AdvXMLParser::Parser::SyntaxError(a1, 2);
  C = (AdvXMLParser::CharRef *)operator new(0x28u);
  v7 = 0;
  if ( C )
    return AdvXMLParser::CharRef::CharRef(C, a2, v5);
  else
    return 0;
}


// address=[0x2f2cf80]
// Decompiled from int __thiscall AdvXMLParser::CharRef::GenerateXML(  AdvXMLParser::CharRef *this,  struct AdvXMLParser::GenerateContext *a2)
void  AdvXMLParser::CharRef::GenerateXML(class AdvXMLParser::GenerateContext &)const {
  
  char *v2; // eax
  _BYTE v5[12]; // [esp+4h] [ebp-10h] BYREF

  AdvXMLParser::GenerateContext::operator+=("&#x");
  v2 = AdvXMLParser::Int2Chars((AdvXMLParser *)*((char *)this + 36), v5, (char *)0xA, this);
  AdvXMLParser::GenerateContext::operator+=(v2);
  return AdvXMLParser::GenerateContext::operator+=(59);
}


