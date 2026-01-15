#include "CData.h"

// Definitions for class CData

// address=[0x2f16c30]
// Decompiled from _DWORD *__thiscall AdvXMLParser::CData::CData(_DWORD *this, int a2)
 AdvXMLParser::CData::CData(std::string const &) {
  
  _BYTE v4[28]; // [esp+8h] [ebp-2Ch] BYREF
  int v5; // [esp+30h] [ebp-4h]

  std::string::string(v4, "#cdata-section");
  v5 = 0;
  AdvXMLParser::Node::Node(this, (int)AdvXMLParser::Node::null, (int)v4);
  LOBYTE(v5) = 2;
  std::string::~string(v4);
  *this = &AdvXMLParser::CData::_vftable_;
  std::string::string(a2);
  return this;
}


// address=[0x2f16cd0]
// Decompiled from _DWORD *__thiscall AdvXMLParser::CData::CData(_DWORD *this, int a2, int a3)
 AdvXMLParser::CData::CData(class AdvXMLParser::NodeContainer &,std::string const &) {
  
  _BYTE v5[28]; // [esp+8h] [ebp-2Ch] BYREF
  int v6; // [esp+30h] [ebp-4h]

  std::string::string(v5, "#cdata-section");
  v6 = 0;
  AdvXMLParser::Node::Node(a2, v5);
  LOBYTE(v6) = 2;
  std::string::~string(v5);
  *this = &AdvXMLParser::CData::_vftable_;
  std::string::string(a3);
  return this;
}


// address=[0x2f16d70]
// Decompiled from int __thiscall AdvXMLParser::CData::Clone(AdvXMLParser::CData *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::CData *  AdvXMLParser::CData::Clone(class AdvXMLParser::NodeContainer &)const {
  
  int v3; // [esp+Ch] [ebp-44h]
  int v4; // [esp+14h] [ebp-3Ch]
  char v6; // [esp+20h] [ebp-30h]
  _BYTE v7[28]; // [esp+24h] [ebp-2Ch] BYREF
  int v8; // [esp+4Ch] [ebp-4h]

  v6 = 0;
  v8 = 0;
  if ( operator new(0x40u) )
  {
    v3 = (*(int (__thiscall **)(AdvXMLParser::CData *, _BYTE *))(*(_DWORD *)this + 4))(this, v7);
    LOBYTE(v8) = 1;
    v6 = 1;
    v4 = AdvXMLParser::CData::CData(a2, v3);
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


// address=[0x2f16e50]
// Decompiled from int __thiscall AdvXMLParser::CData::GetData(char *this, int a2)
std::string  AdvXMLParser::CData::GetData(void)const {
  
  std::string::string(this + 36);
  return a2;
}


// address=[0x2f16e90]
// Decompiled from int __thiscall AdvXMLParser::CData::GetValue(char *this, int a2)
std::string  AdvXMLParser::CData::GetValue(void)const {
  
  std::string::string(this + 36);
  return a2;
}


// address=[0x2f16ed0]
// Decompiled from bool __thiscall AdvXMLParser::CData::IsKindOf(AdvXMLParser::CData *this, int a2)
bool  AdvXMLParser::CData::IsKindOf(int)const {
  
  return a2 == 4 || AdvXMLParser::Node::IsKindOf(this, a2);
}


// address=[0x2f16f00]
// Decompiled from int __thiscall AdvXMLParser::CData::CloneNode(AdvXMLParser::CData *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Node *  AdvXMLParser::CData::CloneNode(class AdvXMLParser::NodeContainer &)const {
  
  return AdvXMLParser::CData::Clone(this, a2);
}


// address=[0x2f1cd00]
// Decompiled from void __thiscall AdvXMLParser::CData::~CData(AdvXMLParser::CData *this)
 AdvXMLParser::CData::~CData(void) {
  
  std::string::~string((char *)this + 36);
  AdvXMLParser::Node::~Node(this);
}


// address=[0x2f248a0]
// Decompiled from int __cdecl AdvXMLParser::CData::Parse(struct AdvXMLParser::Parser *a1, struct AdvXMLParser::NodeContainer *a2)
static class AdvXMLParser::CData * __cdecl AdvXMLParser::CData::Parse(class AdvXMLParser::Parser &,class AdvXMLParser::NodeContainer &) {
  
  unsigned __int8 Char; // al
  _BYTE v4[16]; // [esp+4h] [ebp-4Ch] BYREF
  int v5; // [esp+14h] [ebp-3Ch]
  int v6; // [esp+18h] [ebp-38h]
  int v7; // [esp+1Ch] [ebp-34h]
  void *C; // [esp+20h] [ebp-30h]
  _BYTE v9[28]; // [esp+24h] [ebp-2Ch] BYREF
  int v10; // [esp+4Ch] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseString(a1, "<![CDATA[") )
    return 0;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v4, a1);
  while ( !AdvXMLParser::Parser::ParseString(a1, "]]>") )
  {
    Char = AdvXMLParser::Parser::NextChar(a1);
    if ( !AdvXMLParser::IsXmlChar((AdvXMLParser *)Char) )
      AdvXMLParser::Parser::SyntaxError(a1, 2);
  }
  std::string::string();
  v10 = 0;
  AdvXMLParser::Bookmark::GetSubString(v9, 3);
  C = operator new(0x40u);
  LOBYTE(v10) = 1;
  if ( C )
    v7 = AdvXMLParser::CData::CData(a2, v9);
  else
    v7 = 0;
  v6 = v7;
  v5 = v7;
  v10 = -1;
  std::string::~string(v9);
  return v5;
}


// address=[0x2f2d260]
// Decompiled from void __thiscall AdvXMLParser::CData::GenerateXML(AdvXMLParser::CData *this, struct AdvXMLParser::GenerateContext *a2)
void  AdvXMLParser::CData::GenerateXML(class AdvXMLParser::GenerateContext &)const {
  
  AdvXMLParser::GenerateContext::GenerateStartTagIndentation(a2);
  AdvXMLParser::GenerateContext::operator+=("<![CDATA[");
  AdvXMLParser::GenerateContext::operator+=((char *)this + 36);
  AdvXMLParser::GenerateContext::operator+=("]]>");
  AdvXMLParser::GenerateContext::GenerateNewLine(a2);
  AdvXMLParser::GenerateContext::EndTag(a2);
}


// address=[0x46856e8]
// [Decompilation failed for static class AdvXMLParser::CData AdvXMLParser::CData::null]

