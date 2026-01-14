#include "all_headers.h"

// Definitions for class Reference

// address=[0x2f14bc0]
// Decompiled from _DWORD *__thiscall AdvXMLParser::Reference::Reference(_DWORD *this, int a2, int a3)
 AdvXMLParser::Reference::Reference(class AdvXMLParser::NodeContainer &,std::string const &) {
  
  AdvXMLParser::Node::Node(a2, a3);
  *this = &AdvXMLParser::Reference::_vftable_;
  return this;
}


// address=[0x2f14bf0]
// Decompiled from bool __thiscall AdvXMLParser::Reference::IsKindOf(AdvXMLParser::Reference *this, int a2)
bool  AdvXMLParser::Reference::IsKindOf(int)const {
  
  return a2 == 5 || AdvXMLParser::Node::IsKindOf(this, a2);
}


// address=[0x2f1ce40]
// Decompiled from void __thiscall AdvXMLParser::Reference::~Reference(AdvXMLParser::Reference *this)
 AdvXMLParser::Reference::~Reference(void) {
  
  AdvXMLParser::Node::~Node(this);
}


// address=[0x2f23940]
// Decompiled from struct AdvXMLParser::EntityRef *__cdecl AdvXMLParser::Reference::Parse(  struct AdvXMLParser::Parser *a1,  struct AdvXMLParser::NodeContainer *a2)
static class AdvXMLParser::Reference * __cdecl AdvXMLParser::Reference::Parse(class AdvXMLParser::Parser &,class AdvXMLParser::NodeContainer &) {
  
  struct AdvXMLParser::CharRef *v3; // eax
  struct AdvXMLParser::EntityRef *v4; // [esp+4h] [ebp-18h]
  int v5; // [esp+8h] [ebp-14h]
  _BYTE v6[4]; // [esp+Ch] [ebp-10h] BYREF
  int v7; // [esp+18h] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseChar(a1, 38) )
    return 0;
  AdvXMLParser::Parser::PreviousChar(a1);
  v3 = AdvXMLParser::CharRef::Parse(a1, a2);
  std::auto_ptr<AdvXMLParser::Reference>::auto_ptr<AdvXMLParser::Reference>(v3);
  v7 = 0;
  if ( std::auto_ptr<AdvXMLParser::Reference>::get(v6) )
  {
    v5 = std::auto_ptr<AdvXMLParser::Reference>::release(v6);
    v7 = -1;
    std::auto_ptr<AdvXMLParser::Reference>::~auto_ptr<AdvXMLParser::Reference>(v6);
    return (struct AdvXMLParser::EntityRef *)v5;
  }
  else
  {
    v4 = AdvXMLParser::EntityRef::Parse(a1, a2);
    v7 = -1;
    std::auto_ptr<AdvXMLParser::Reference>::~auto_ptr<AdvXMLParser::Reference>(v6);
    return v4;
  }
}


