#include "all_headers.h"

// Definitions for class Attribute

// address=[0x2f148f0]
// Decompiled from _DWORD *__thiscall AdvXMLParser::Attribute::Attribute(_DWORD *this, int a2, int a3)
 AdvXMLParser::Attribute::Attribute(class AdvXMLParser::NodeContainer &,std::string const &) {
  
  AdvXMLParser::NodeContainer::NodeContainer(a2, a3);
  *this = &AdvXMLParser::Attribute::_vftable_;
  return this;
}


// address=[0x2f14920]
// Decompiled from int __thiscall AdvXMLParser::Attribute::Clone(AdvXMLParser::Attribute *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Attribute *  AdvXMLParser::Attribute::Clone(class AdvXMLParser::NodeContainer &)const {
  
  int Name; // eax
  struct AdvXMLParser::NodeContainer *v3; // eax
  int v5; // [esp+4h] [ebp-24h]
  int v7; // [esp+10h] [ebp-18h]
  _BYTE v8[4]; // [esp+18h] [ebp-10h] BYREF
  int v9; // [esp+24h] [ebp-4h]

  v9 = 0;
  if ( operator new(0x38u) )
  {
    Name = AdvXMLParser::Node::GetName(this);
    v7 = AdvXMLParser::Attribute::Attribute(a2, Name);
  }
  else
  {
    v7 = 0;
  }
  std::auto_ptr<AdvXMLParser::Attribute>::auto_ptr<AdvXMLParser::Attribute>(v7);
  v9 = 1;
  v3 = (struct AdvXMLParser::NodeContainer *)std::auto_ptr<AdvXMLParser::Attribute>::operator*();
  AdvXMLParser::NodeContainer::CloneChildren(this, v3);
  v5 = std::auto_ptr<AdvXMLParser::Attribute>::release(v8);
  v9 = -1;
  std::auto_ptr<AdvXMLParser::Attribute>::~auto_ptr<AdvXMLParser::Attribute>(v8);
  return v5;
}


// address=[0x2f149f0]
// Decompiled from int __thiscall AdvXMLParser::Attribute::GetData(void *this, int a2)
std::string  AdvXMLParser::Attribute::GetData(void)const {
  
  (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 8))(this, a2);
  return a2;
}


// address=[0x2f14a30]
// Decompiled from int __thiscall AdvXMLParser::Attribute::GetValue(void *this, int a2)
std::string  AdvXMLParser::Attribute::GetValue(void)const {
  
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
  AdvXMLParser::TrimSpaces(v14);
  std::string::string(v14);
  v9 |= 1u;
  v15 = -1;
  std::string::~string(v14);
  return a2;
}


// address=[0x2f14b70]
// Decompiled from bool __thiscall AdvXMLParser::Attribute::IsKindOf(AdvXMLParser::Attribute *this, int a2)
bool  AdvXMLParser::Attribute::IsKindOf(int)const {
  
  return a2 == 2 || AdvXMLParser::Node::IsKindOf(this, a2);
}


// address=[0x2f14ba0]
// Decompiled from int __thiscall AdvXMLParser::Attribute::CloneNode(  AdvXMLParser::Attribute *this,  struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Node *  AdvXMLParser::Attribute::CloneNode(class AdvXMLParser::NodeContainer &)const {
  
  return AdvXMLParser::Attribute::Clone(this, a2);
}


// address=[0x2f1cce0]
// Decompiled from void __thiscall AdvXMLParser::Attribute::~Attribute(AdvXMLParser::Attribute *this)
 AdvXMLParser::Attribute::~Attribute(void) {
  
  AdvXMLParser::NodeContainer::~NodeContainer(this);
}


// address=[0x2f23650]
// Decompiled from int __cdecl AdvXMLParser::Attribute::Parse(struct AdvXMLParser::Parser *a1, struct AdvXMLParser::Element *a2)
static class AdvXMLParser::Attribute * __cdecl AdvXMLParser::Attribute::Parse(class AdvXMLParser::Parser &,class AdvXMLParser::Element &) {
  
  AdvXMLParser::Attribute *v3; // eax
  struct AdvXMLParser::Parser *v4; // [esp-4h] [ebp-4Ch]
  int v5; // [esp+4h] [ebp-44h]
  int v6; // [esp+10h] [ebp-38h]
  void *C; // [esp+14h] [ebp-34h]
  _BYTE v8[4]; // [esp+18h] [ebp-30h] BYREF
  _BYTE v9[28]; // [esp+1Ch] [ebp-2Ch] BYREF
  int v10; // [esp+44h] [ebp-4h]

  std::string::string();
  v10 = 0;
  if ( (unsigned __int8)AdvXMLParser::Parser::ParseName(v9) )
  {
    if ( !AdvXMLParser::Parser::ParseEq(a1) )
      AdvXMLParser::Parser::SyntaxError(a1, 3);
    C = operator new(0x38u);
    LOBYTE(v10) = 1;
    if ( C )
      v6 = AdvXMLParser::Attribute::Attribute(a2, v9);
    else
      v6 = 0;
    LOBYTE(v10) = 0;
    std::auto_ptr<AdvXMLParser::Attribute>::auto_ptr<AdvXMLParser::Attribute>(v6);
    LOBYTE(v10) = 2;
    v3 = (AdvXMLParser::Attribute *)std::auto_ptr<AdvXMLParser::Attribute>::operator->(a1);
    if ( !AdvXMLParser::Attribute::ParseAttValue(v3, v4) )
      AdvXMLParser::Parser::SyntaxError(a1, 4);
    v5 = std::auto_ptr<AdvXMLParser::Attribute>::release(v8);
    LOBYTE(v10) = 0;
    std::auto_ptr<AdvXMLParser::Attribute>::~auto_ptr<AdvXMLParser::Attribute>(v8);
    v10 = -1;
    std::string::~string(v9);
    return v5;
  }
  else
  {
    v10 = -1;
    std::string::~string(v9);
    return 0;
  }
}


// address=[0x2f23790]
// Decompiled from char __thiscall AdvXMLParser::Attribute::ParseAttValue(AdvXMLParser::Attribute *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Attribute::ParseAttValue(class AdvXMLParser::Parser &) {
  
  struct AdvXMLParser::Reference *v3; // eax
  struct Node *v4; // eax
  char v6; // [esp+0h] [ebp-50h]
  _BYTE v7[16]; // [esp+4h] [ebp-4Ch] BYREF
  _BYTE v8[4]; // [esp+14h] [ebp-3Ch] BYREF
  unsigned __int8 v9; // [esp+18h] [ebp-38h]
  AdvXMLParser::NodeContainer *v10; // [esp+1Ch] [ebp-34h]
  char v11; // [esp+21h] [ebp-2Fh]
  char Char; // [esp+22h] [ebp-2Eh]
  unsigned __int8 i; // [esp+23h] [ebp-2Dh]
  _BYTE v14[28]; // [esp+24h] [ebp-2Ch] BYREF
  int v15; // [esp+4Ch] [ebp-4h]

  v10 = this;
  Char = AdvXMLParser::Parser::NextChar(a2);
  if ( Char == 39 || Char == 34 )
  {
    std::string::string();
    v15 = 0;
    AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v7, a2);
    for ( i = AdvXMLParser::Parser::NextChar(a2); (char)i != Char; i = AdvXMLParser::Parser::NextChar(a2) )
    {
      v9 = i;
      if ( !i )
        AdvXMLParser::Parser::SyntaxError(a2, 1);
      if ( v9 == 38 )
      {
        AdvXMLParser::Parser::PreviousChar(a2);
        AdvXMLParser::NodeContainer::AddText(v10, (struct AdvXMLParser::Bookmark *)v7, 0);
        v3 = AdvXMLParser::Reference::Parse(a2, v10);
        std::auto_ptr<AdvXMLParser::Reference>::auto_ptr<AdvXMLParser::Reference>(v3);
        LOBYTE(v15) = 1;
        if ( !std::auto_ptr<AdvXMLParser::Reference>::get(v8) )
          AdvXMLParser::Parser::SyntaxError(a2, 6);
        v4 = (struct Node *)std::auto_ptr<AdvXMLParser::Reference>::release(v8);
        AdvXMLParser::NodeContainer::Add(v10, v4);
        AdvXMLParser::Bookmark::Reset((AdvXMLParser::Bookmark *)v7);
        LOBYTE(v15) = 0;
        std::auto_ptr<AdvXMLParser::Reference>::~auto_ptr<AdvXMLParser::Reference>(v8);
      }
      else
      {
        if ( v9 == 60 )
          AdvXMLParser::Parser::SyntaxError(a2, 5);
        if ( !AdvXMLParser::IsXmlChar((AdvXMLParser *)i, v6) )
          AdvXMLParser::Parser::SyntaxError(a2, 2);
      }
    }
    AdvXMLParser::NodeContainer::AddText(v10, (struct AdvXMLParser::Bookmark *)v7, 1);
    v11 = 1;
    v15 = -1;
    std::string::~string(v14);
    return v11;
  }
  else
  {
    AdvXMLParser::Parser::PreviousChar(a2);
    return 0;
  }
}


// address=[0x2f2cf30]
// Decompiled from int __thiscall AdvXMLParser::Attribute::GenerateXML(  AdvXMLParser::Attribute *this,  struct AdvXMLParser::GenerateContext *a2)
void  AdvXMLParser::Attribute::GenerateXML(class AdvXMLParser::GenerateContext &)const {
  
  int Name; // eax

  Name = AdvXMLParser::Node::GetName(this);
  AdvXMLParser::GenerateContext::operator+=(Name);
  AdvXMLParser::GenerateContext::operator+=("=\"");
  AdvXMLParser::NodeContainer::GenerateXML(this, a2);
  return AdvXMLParser::GenerateContext::operator+=("\"");
}


// address=[0x46856a4]
// [Decompilation failed for static class AdvXMLParser::Attribute AdvXMLParser::Attribute::null]

