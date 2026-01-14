#include "all_headers.h"

// Definitions for class Node

// address=[0x14f3f10]
// Decompiled from char *__thiscall AdvXMLParser::Node::GetName(char *this)
std::string const &  AdvXMLParser::Node::GetName(void)const {
  
  return this + 4;
}


// address=[0x14f3f90]
// Decompiled from bool __thiscall AdvXMLParser::Node::IsNull(AdvXMLParser::Node *this)
bool  AdvXMLParser::Node::IsNull(void)const {
  
  return this == (AdvXMLParser::Node *)&AdvXMLParser::Attribute::null
      || this == (AdvXMLParser::Node *)&AdvXMLParser::Element::null
      || this == (AdvXMLParser::Node *)&AdvXMLParser::Comment::null
      || this == (AdvXMLParser::Node *)&AdvXMLParser::Pi::null
      || this == (AdvXMLParser::Node *)&AdvXMLParser::CData::null;
}


// address=[0x2f13420]
// Decompiled from _DWORD *__thiscall AdvXMLParser::Node::Node(_DWORD *this, int a2, int a3)
 AdvXMLParser::Node::Node(class AdvXMLParser::NodeContainer &,std::string const &) {
  
  *this = &AdvXMLParser::Node::_vftable_;
  std::string::string(a3);
  this[8] = a2;
  return this;
}


// address=[0x2f13460]
// Decompiled from void __thiscall AdvXMLParser::Node::~Node(boost::exception *this)
 AdvXMLParser::Node::~Node(void) {
  
  *(_DWORD *)this = &AdvXMLParser::Node::_vftable_;
  std::string::~string((char *)this + 4);
}


// address=[0x2f13480]
// Decompiled from int __thiscall AdvXMLParser::Node::Delete(int this)
void  AdvXMLParser::Node::Delete(void) {
  
  return AdvXMLParser::NodeContainer::DeleteChild(
           *(AdvXMLParser::NodeContainer **)(this + 32),
           (const struct Node *)this);
}


// address=[0x2f134a0]
// Decompiled from char __thiscall AdvXMLParser::Node::IsKindOf(AdvXMLParser::Node *this, int a2)
bool  AdvXMLParser::Node::IsKindOf(int)const {
  
  return 0;
}


// address=[0x2f1e510]
// Decompiled from int __thiscall AdvXMLParser::Node::GetParent(AdvXMLParser::Node *this)
class AdvXMLParser::NodeContainer &  AdvXMLParser::Node::GetParent(void)const {
  
  return *((_DWORD *)this + 8);
}


// address=[0x3e2d2a8]
// [Decompilation failed for static class AdvXMLParser::NodeContainer & AdvXMLParser::Node::null]

