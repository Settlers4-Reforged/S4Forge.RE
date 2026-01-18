#include "Element.h"

// Definitions for class Element

// address=[0x14f3890]
// Decompiled from const struct AdvXMLParser::Attribute *__thiscall AdvXMLParser::Element::operator[](  AdvXMLParser::Element *this,  const char *a2)
class AdvXMLParser::Attribute const &  AdvXMLParser::Element::operator[](char const * a2)const {
  
  return AdvXMLParser::Element::GetAttribute(this, a2);
}


// address=[0x14f3c30]
// Decompiled from const struct AdvXMLParser::Element *__thiscall AdvXMLParser::Element::operator()(  AdvXMLParser::Element *this,  const char *a2,  int a3)
class AdvXMLParser::Element const &  AdvXMLParser::Element::operator()(char const * a2, int a3)const {
  
  return AdvXMLParser::Element::GetElement(this, a2, a3);
}


// address=[0x14f3e90]
// Decompiled from AdvXMLParser::Node *__thiscall AdvXMLParser::Element::GetElement(AdvXMLParser::Element *this, const char *a2, int a3)
class AdvXMLParser::Element const &  AdvXMLParser::Element::GetElement(char const * a2, int a3)const {
  
  AdvXMLParser::Node *Child; // [esp+Ch] [ebp-4h]

  Child = (AdvXMLParser::Node *)AdvXMLParser::NodeContainer::GetChild(this, a2, a3, 1);
  if ( AdvXMLParser::Node::IsNull(Child) )
    return (AdvXMLParser::Node *)&AdvXMLParser::Element::null;
  else
    return Child;
}


// address=[0x2f15200]
// Decompiled from int __thiscall AdvXMLParser::Element::Element(_DWORD *this, int a2)
 AdvXMLParser::Element::Element(std::string const & a2) {
  
  int v4; // [esp+0h] [ebp-4h]

  AdvXMLParser::NodeContainer::NodeContainer(AdvXMLParser::Node::null, a2);
  *this = &AdvXMLParser::Element::_vftable_;
  std::vector<AdvXMLParser::Attribute *>::vector<AdvXMLParser::Attribute *>(this);
  *(_BYTE *)(v4 + 72) = 0;
  return v4;
}


// address=[0x2f15240]
// Decompiled from int __thiscall AdvXMLParser::Element::Element(_DWORD *this, int a2, int a3)
 AdvXMLParser::Element::Element(class AdvXMLParser::NodeContainer & a2, std::string const & a3) {
  
  int v5; // [esp+0h] [ebp-4h]

  AdvXMLParser::NodeContainer::NodeContainer(a2, a3);
  *this = &AdvXMLParser::Element::_vftable_;
  std::vector<AdvXMLParser::Attribute *>::vector<AdvXMLParser::Attribute *>(this);
  *(_BYTE *)(v5 + 72) = 0;
  return v5;
}


// address=[0x2f15280]
// Decompiled from void __thiscall AdvXMLParser::Element::~Element(AdvXMLParser::Element *this)
 AdvXMLParser::Element::~Element(void) {
  
  std::_Iterator_base12 *v1; // eax
  _BYTE v2[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-2Ch] BYREF
  int v4; // [esp+1Ch] [ebp-20h]
  int (__thiscall ***v5)(_DWORD, int); // [esp+20h] [ebp-1Ch]
  int (__thiscall ***v6)(_DWORD, int); // [esp+24h] [ebp-18h]
  AdvXMLParser::NodeContainer *v7; // [esp+28h] [ebp-14h]
  char v8; // [esp+2Fh] [ebp-Dh]

  v7 = this;
  *(_DWORD *)this = &AdvXMLParser::Element::_vftable_;
  std::vector<AdvXMLParser::Attribute *>::begin(v3);
  while ( 1 )
  {
    v1 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Attribute *>::end(v2);
    v8 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator<(v1);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>(v2);
    if ( !v8 )
      break;
    v5 = *(int (__thiscall ****)(_DWORD, int))std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator*(v3);
    v6 = v5;
    if ( v5 )
      v4 = (**v6)(v6, 1);
    else
      v4 = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator++(v3);
  }
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>(v3);
  std::vector<AdvXMLParser::Attribute *>::~vector<AdvXMLParser::Attribute *>();
  AdvXMLParser::NodeContainer::~NodeContainer(v7);
}


// address=[0x2f15360]
// Decompiled from int __thiscall AdvXMLParser::Element::Clone(AdvXMLParser::Element *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Element *  AdvXMLParser::Element::Clone(class AdvXMLParser::NodeContainer & a2)const {
  
  int Name; // eax
  struct AdvXMLParser::NodeContainer *v3; // eax
  int v5; // [esp+4h] [ebp-24h]
  int v7; // [esp+10h] [ebp-18h]
  _DWORD *C; // [esp+14h] [ebp-14h]
  _BYTE v9[4]; // [esp+18h] [ebp-10h] BYREF
  int v10; // [esp+24h] [ebp-4h]

  C = operator new(0x4Cu);
  v10 = 0;
  if ( C )
  {
    Name = AdvXMLParser::Node::GetName(this);
    v7 = AdvXMLParser::Element::Element(C, (int)a2, Name);
  }
  else
  {
    v7 = 0;
  }
  std::auto_ptr<AdvXMLParser::Element>::auto_ptr<AdvXMLParser::Element>(v7);
  v10 = 1;
  v3 = (struct AdvXMLParser::NodeContainer *)std::auto_ptr<AdvXMLParser::Element>::operator*();
  AdvXMLParser::NodeContainer::CloneChildren(this, v3);
  v5 = std::auto_ptr<AdvXMLParser::Element>::release(v9);
  v10 = -1;
  std::auto_ptr<AdvXMLParser::Element>::~auto_ptr<AdvXMLParser::Element>(v9);
  return v5;
}


// address=[0x2f15430]
// Decompiled from int __cdecl AdvXMLParser::Element::Normalize(int a1)
void __cdecl AdvXMLParser::Element::Normalize(std::string & a1) {
  
  AdvXMLParser::NormalizeWhiteSpaces(a1);
  return AdvXMLParser::TrimSpaces(a1);
}


// address=[0x2f15450]
// Decompiled from AdvXMLParser::Node *__thiscall AdvXMLParser::Element::CreateElement(AdvXMLParser::Node *this, char *Str, int a3)
class AdvXMLParser::Element &  AdvXMLParser::Element::CreateElement(char const * Str, int a3) {
  
  struct Node *v4; // [esp+8h] [ebp-40h]
  _DWORD *C; // [esp+Ch] [ebp-3Ch]
  AdvXMLParser::Node *Element; // [esp+10h] [ebp-38h]
  int v8; // [esp+18h] [ebp-30h]
  _BYTE v9[28]; // [esp+1Ch] [ebp-2Ch] BYREF
  int v10; // [esp+44h] [ebp-4h]

  v8 = 0;
  if ( AdvXMLParser::Node::IsNull(this) )
    return (AdvXMLParser::Node *)&AdvXMLParser::Element::null;
  while ( 1 )
  {
    Element = AdvXMLParser::Element::GetElement(this, Str, a3);
    if ( !AdvXMLParser::Node::IsNull(Element) )
      break;
    C = operator new(0x4Cu);
    v10 = 0;
    if ( C )
    {
      std::string::string(v9, Str);
      LOBYTE(v10) = 1;
      v8 |= 1u;
      v4 = (struct Node *)AdvXMLParser::Element::Element(C, (int)this, (int)v9);
    }
    else
    {
      v4 = 0;
    }
    v10 = 2;
    AdvXMLParser::NodeContainer::Add(this, v4);
    v10 = -1;
    if ( (v8 & 1) != 0 )
    {
      v8 &= ~1u;
      std::string::~string(v9);
    }
  }
  return Element;
}


// address=[0x2f15570]
// Decompiled from struct Node *__thiscall AdvXMLParser::Element::AddElementInto(AdvXMLParser::Node *this, char *Str)
class AdvXMLParser::Element &  AdvXMLParser::Element::AddElementInto(char const * Str) {
  
  struct Node *v3; // [esp+Ch] [ebp-3Ch]
  _DWORD *C; // [esp+10h] [ebp-38h]
  char v6; // [esp+18h] [ebp-30h]
  _BYTE v7[28]; // [esp+1Ch] [ebp-2Ch] BYREF
  int v8; // [esp+44h] [ebp-4h]

  v6 = 0;
  if ( AdvXMLParser::Node::IsNull(this) )
    return (struct Node *)&AdvXMLParser::Element::null;
  C = operator new(0x4Cu);
  v8 = 0;
  if ( C )
  {
    std::string::string(v7, Str);
    LOBYTE(v8) = 1;
    v6 = 1;
    v3 = (struct Node *)AdvXMLParser::Element::Element(C, (int)this, (int)v7);
  }
  else
  {
    v3 = 0;
  }
  v8 = -1;
  if ( (v6 & 1) != 0 )
    std::string::~string(v7);
  AdvXMLParser::NodeContainer::Add(this, v3);
  return v3;
}


// address=[0x2f15670]
// Decompiled from struct Node *__thiscall AdvXMLParser::Element::AppendElement(AdvXMLParser::Node *this, char *Str)
class AdvXMLParser::Element &  AdvXMLParser::Element::AppendElement(char const * Str) {
  
  struct Node *v3; // [esp+Ch] [ebp-40h]
  _DWORD *C; // [esp+10h] [ebp-3Ch]
  AdvXMLParser::Node *Parent; // [esp+18h] [ebp-34h]
  char v7; // [esp+1Ch] [ebp-30h]
  _BYTE v8[28]; // [esp+20h] [ebp-2Ch] BYREF
  int v9; // [esp+48h] [ebp-4h]

  v7 = 0;
  if ( AdvXMLParser::Node::IsNull(this) )
    return (struct Node *)&AdvXMLParser::Element::null;
  Parent = AdvXMLParser::Node::GetParent(this);
  if ( AdvXMLParser::Node::IsNull(Parent)
    && BBSupportDbgReport(2, "Source\\Xml\\elements.cpp", 751, "!parent.IsNull()") == 1 )
  {
    __debugbreak();
  }
  C = operator new(0x4Cu);
  v9 = 0;
  if ( C )
  {
    std::string::string(v8, Str);
    LOBYTE(v9) = 1;
    v7 = 1;
    v3 = (struct Node *)AdvXMLParser::Element::Element(C, (int)Parent, (int)v8);
  }
  else
  {
    v3 = 0;
  }
  v9 = -1;
  if ( (v7 & 1) != 0 )
    std::string::~string(v8);
  AdvXMLParser::NodeContainer::Add(Parent, v3);
  return v3;
}


// address=[0x2f157a0]
// Decompiled from struct Node *__thiscall AdvXMLParser::Element::InsertElementAfter(AdvXMLParser::Node *this, char *Str)
class AdvXMLParser::Element &  AdvXMLParser::Element::InsertElementAfter(char const * Str) {
  
  struct Node *v3; // [esp+Ch] [ebp-40h]
  _DWORD *C; // [esp+10h] [ebp-3Ch]
  AdvXMLParser::Node *Parent; // [esp+14h] [ebp-38h]
  char v7; // [esp+1Ch] [ebp-30h]
  _BYTE v8[28]; // [esp+20h] [ebp-2Ch] BYREF
  int v9; // [esp+48h] [ebp-4h]

  v7 = 0;
  if ( AdvXMLParser::Node::IsNull(this) )
    return (struct Node *)&AdvXMLParser::Element::null;
  Parent = AdvXMLParser::Node::GetParent(this);
  if ( AdvXMLParser::Node::IsNull(Parent)
    && BBSupportDbgReport(2, "Source\\Xml\\elements.cpp", 779, "!parent.IsNull()") == 1 )
  {
    __debugbreak();
  }
  C = operator new(0x4Cu);
  v9 = 0;
  if ( C )
  {
    std::string::string(v8, Str);
    LOBYTE(v9) = 1;
    v7 = 1;
    v3 = (struct Node *)AdvXMLParser::Element::Element(C, (int)Parent, (int)v8);
  }
  else
  {
    v3 = 0;
  }
  v9 = -1;
  if ( (v7 & 1) != 0 )
    std::string::~string(v8);
  AdvXMLParser::NodeContainer::InsertAfter(Parent, (const struct Node *)this, v3);
  return v3;
}


// address=[0x2f158d0]
// Decompiled from struct Node *__thiscall AdvXMLParser::Element::InsertElementBefore(AdvXMLParser::Node *this, char *Str)
class AdvXMLParser::Element &  AdvXMLParser::Element::InsertElementBefore(char const * Str) {
  
  struct Node *v3; // [esp+Ch] [ebp-40h]
  _DWORD *C; // [esp+10h] [ebp-3Ch]
  AdvXMLParser::Node *Parent; // [esp+14h] [ebp-38h]
  char v7; // [esp+1Ch] [ebp-30h]
  _BYTE v8[28]; // [esp+20h] [ebp-2Ch] BYREF
  int v9; // [esp+48h] [ebp-4h]

  v7 = 0;
  if ( AdvXMLParser::Node::IsNull(this) )
    return (struct Node *)&AdvXMLParser::Element::null;
  Parent = AdvXMLParser::Node::GetParent(this);
  if ( AdvXMLParser::Node::IsNull(Parent)
    && BBSupportDbgReport(2, "Source\\Xml\\elements.cpp", 765, "!parent.IsNull()") == 1 )
  {
    __debugbreak();
  }
  C = operator new(0x4Cu);
  v9 = 0;
  if ( C )
  {
    std::string::string(v8, Str);
    LOBYTE(v9) = 1;
    v7 = 1;
    v3 = (struct Node *)AdvXMLParser::Element::Element(C, (int)Parent, (int)v8);
  }
  else
  {
    v3 = 0;
  }
  v9 = -1;
  if ( (v7 & 1) != 0 )
    std::string::~string(v8);
  AdvXMLParser::NodeContainer::InsertBefore(Parent, (const struct Node *)this, v3);
  return v3;
}


// address=[0x2f15a00]
// Decompiled from char __thiscall AdvXMLParser::Element::DeleteChildElement(AdvXMLParser::Element *this, char *a2, int a3)
bool  AdvXMLParser::Element::DeleteChildElement(char const * a2, int a3) {
  
  char v4; // [esp-Ch] [ebp-3Ch] BYREF
  int v5; // [esp-8h] [ebp-38h]
  int v6; // [esp-4h] [ebp-34h]
  _BYTE v7[12]; // [esp+4h] [ebp-2Ch] BYREF
  int v8; // [esp+10h] [ebp-20h]
  char *v9; // [esp+14h] [ebp-1Ch]
  AdvXMLParser::Element *v10; // [esp+18h] [ebp-18h]
  int i; // [esp+1Ch] [ebp-14h]
  char v12; // [esp+22h] [ebp-Eh]
  char v13; // [esp+23h] [ebp-Dh]
  int v14; // [esp+2Ch] [ebp-4h]

  v10 = this;
  std::vector<AdvXMLParser::Node *>::begin(v7);
  v14 = 0;
  for ( i = 0; i <= a3; ++i )
  {
    if ( !(unsigned __int8)AdvXMLParser::NodeContainer::FindChild(a2, 1, v7) )
    {
      v13 = 0;
      v14 = -1;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v7);
      return v13;
    }
  }
  v9 = &v4;
  v8 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v7);
  AdvXMLParser::NodeContainer::DeleteChild(v4, v5, v6);
  v12 = 1;
  v14 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v7);
  return v12;
}


// address=[0x2f15ad0]
// Decompiled from void *__thiscall AdvXMLParser::Element::GetAttribute(AdvXMLParser::Element *this, char *Str)
class AdvXMLParser::Attribute const &  AdvXMLParser::Element::GetAttribute(char const * Str)const {
  
  _DWORD *v2; // eax
  int Name; // eax
  _BYTE v5[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-2Ch] BYREF
  int v7; // [esp+1Ch] [ebp-20h]
  std::_Iterator_base12 *v8; // [esp+20h] [ebp-1Ch]
  std::_Iterator_base12 *v9; // [esp+24h] [ebp-18h]
  AdvXMLParser::Element *v10; // [esp+28h] [ebp-14h]
  char v11; // [esp+2Fh] [ebp-Dh]
  int v12; // [esp+38h] [ebp-4h]

  v10 = this;
  std::vector<AdvXMLParser::Attribute *>::begin(v6);
  v12 = 0;
  while ( 1 )
  {
    v9 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Attribute *>::end(v5);
    v8 = v9;
    LOBYTE(v12) = 1;
    v11 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator<(v9);
    LOBYTE(v12) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>(v5);
    if ( !v11 )
      break;
    v2 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator*(v6);
    Name = AdvXMLParser::Node::GetName(*v2);
    if ( std::operator==<char>(Name, Str) )
    {
      v7 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator*(v6);
      v12 = -1;
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>(v6);
      return (void *)v7;
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator++(v6);
  }
  v12 = -1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>(v6);
  return &AdvXMLParser::Attribute::null;
}


// address=[0x2f15bd0]
// Decompiled from void *__thiscall AdvXMLParser::Element::GetAttribute_0(char *this, int a2)
class AdvXMLParser::Attribute const &  AdvXMLParser::Element::GetAttribute(int a2)const {
  
  if ( a2 >= 0 && a2 < (unsigned int)std::vector<AdvXMLParser::Attribute *>::size(this + 56) )
    return *(void **)std::vector<AdvXMLParser::Attribute *>::operator[](a2);
  else
    return &AdvXMLParser::Attribute::null;
}


// address=[0x2f15c10]
// Decompiled from void *__thiscall AdvXMLParser::Element::GetAttribute(AdvXMLParser::Element *this, char *Str)
class AdvXMLParser::Attribute &  AdvXMLParser::Element::GetAttribute(char const * Str) {
  
  _DWORD *v2; // eax
  int Name; // eax
  _BYTE v5[12]; // [esp+4h] [ebp-4Ch] BYREF
  _BYTE v6[12]; // [esp+10h] [ebp-40h] BYREF
  _BYTE v7[12]; // [esp+1Ch] [ebp-34h] BYREF
  int v8; // [esp+28h] [ebp-28h]
  std::_Iterator_base12 *v9; // [esp+2Ch] [ebp-24h]
  std::_Iterator_base12 *v10; // [esp+30h] [ebp-20h]
  struct std::_Iterator_base12 *v11; // [esp+34h] [ebp-1Ch]
  struct std::_Iterator_base12 *v12; // [esp+38h] [ebp-18h]
  AdvXMLParser::Element *v13; // [esp+3Ch] [ebp-14h]
  char v14; // [esp+43h] [ebp-Dh]
  int v15; // [esp+4Ch] [ebp-4h]

  v13 = this;
  v12 = (struct std::_Iterator_base12 *)std::vector<AdvXMLParser::Attribute *>::begin(v6);
  v11 = v12;
  v15 = 0;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>(v12);
  LOBYTE(v15) = 2;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>(v6);
  while ( 1 )
  {
    v10 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Attribute *>::end(v5);
    v9 = v10;
    LOBYTE(v15) = 3;
    v14 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator<(v10);
    LOBYTE(v15) = 2;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>(v5);
    if ( !v14 )
      break;
    v2 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator*(v7);
    Name = AdvXMLParser::Node::GetName(*v2);
    if ( std::operator==<char>(Name, Str) )
    {
      v8 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator*(v7);
      v15 = -1;
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>(v7);
      return (void *)v8;
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator++(v7);
  }
  v15 = -1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>(v7);
  return &AdvXMLParser::Attribute::null;
}


// address=[0x2f15d30]
// Decompiled from void *__thiscall AdvXMLParser::Element::GetAttribute_2(char *this, int a2)
class AdvXMLParser::Attribute &  AdvXMLParser::Element::GetAttribute(int a2) {
  
  if ( a2 >= 0 && a2 < (unsigned int)std::vector<AdvXMLParser::Attribute *>::size(this + 56) )
    return *(void **)std::vector<AdvXMLParser::Attribute *>::operator[](a2);
  else
    return &AdvXMLParser::Attribute::null;
}


// address=[0x2f15d70]
// Decompiled from AdvXMLParser::Node *__thiscall AdvXMLParser::Element::CreateAttribute(AdvXMLParser::Element *this, char *Str)
class AdvXMLParser::Attribute &  AdvXMLParser::Element::CreateAttribute(char const * Str) {
  
  int v3; // [esp+8h] [ebp-50h]
  _DWORD v4[2]; // [esp+Ch] [ebp-4Ch] BYREF
  int v5; // [esp+14h] [ebp-44h]
  void *C; // [esp+18h] [ebp-40h]
  AdvXMLParser::Node *Attribute; // [esp+1Ch] [ebp-3Ch]
  _BYTE v8[4]; // [esp+20h] [ebp-38h] BYREF
  AdvXMLParser::Element *v9; // [esp+24h] [ebp-34h]
  int v10; // [esp+28h] [ebp-30h]
  _BYTE v11[28]; // [esp+2Ch] [ebp-2Ch] BYREF
  int v12; // [esp+54h] [ebp-4h]

  v9 = this;
  v10 = 0;
  if ( AdvXMLParser::Node::IsNull(this) )
    return (AdvXMLParser::Node *)&AdvXMLParser::Attribute::null;
  Attribute = (AdvXMLParser::Node *)AdvXMLParser::Element::GetAttribute(v9, Str);
  if ( !AdvXMLParser::Node::IsNull(Attribute) )
    return Attribute;
  C = operator new(0x38u);
  v12 = 0;
  if ( C )
  {
    std::string::string(v11, Str);
    LOBYTE(v12) = 1;
    v10 |= 1u;
    v5 = AdvXMLParser::Attribute::Attribute(v9, v11);
  }
  else
  {
    v5 = 0;
  }
  v4[1] = v5;
  v12 = 2;
  std::auto_ptr<AdvXMLParser::Attribute>::auto_ptr<AdvXMLParser::Attribute>(v5);
  v12 = 4;
  if ( (v10 & 1) != 0 )
  {
    v10 &= ~1u;
    std::string::~string(v11);
  }
  v3 = std::auto_ptr<AdvXMLParser::Attribute>::get(v8);
  v4[0] = std::auto_ptr<AdvXMLParser::Attribute>::release(v8);
  std::vector<AdvXMLParser::Attribute *>::push_back(v4);
  v12 = -1;
  std::auto_ptr<AdvXMLParser::Attribute>::~auto_ptr<AdvXMLParser::Attribute>(v8);
  return (AdvXMLParser::Node *)v3;
}


// address=[0x2f15ec0]
// Decompiled from void *__thiscall AdvXMLParser::Element::GetComment(AdvXMLParser::Element *this, int a2)
class AdvXMLParser::Comment const &  AdvXMLParser::Element::GetComment(int a2)const {
  
  _BYTE v3[12]; // [esp+4h] [ebp-28h] BYREF
  int v4; // [esp+10h] [ebp-1Ch]
  void *v5; // [esp+14h] [ebp-18h]
  AdvXMLParser::Element *v6; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int v8; // [esp+28h] [ebp-4h]

  v6 = this;
  std::vector<AdvXMLParser::Node *>::begin(v3);
  v8 = 0;
  for ( i = 0; i <= a2; ++i )
  {
    if ( !(unsigned __int8)AdvXMLParser::NodeContainer::FindChild(8, v3) )
    {
      v5 = &AdvXMLParser::Comment::null;
      v8 = -1;
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
      return v5;
    }
  }
  v4 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v3);
  v8 = -1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
  return (void *)v4;
}


// address=[0x2f15f80]
// Decompiled from void *__thiscall AdvXMLParser::Element::GetComment(AdvXMLParser::Element *this, int a2)
class AdvXMLParser::Comment &  AdvXMLParser::Element::GetComment(int a2) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-28h] BYREF
  int v4; // [esp+10h] [ebp-1Ch]
  void *v5; // [esp+14h] [ebp-18h]
  AdvXMLParser::Element *v6; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int v8; // [esp+28h] [ebp-4h]

  v6 = this;
  std::vector<AdvXMLParser::Node *>::begin(v3);
  v8 = 0;
  for ( i = 0; i <= a2; ++i )
  {
    if ( !(unsigned __int8)AdvXMLParser::NodeContainer::FindChild(8, v3) )
    {
      v5 = &AdvXMLParser::Comment::null;
      v8 = -1;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
      return v5;
    }
  }
  v4 = *(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v3);
  v8 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
  return (void *)v4;
}


// address=[0x2f16040]
// Decompiled from void *__thiscall AdvXMLParser::Element::GetCData(AdvXMLParser::Element *this, int a2)
class AdvXMLParser::CData const &  AdvXMLParser::Element::GetCData(int a2)const {
  
  _BYTE v3[12]; // [esp+4h] [ebp-28h] BYREF
  int v4; // [esp+10h] [ebp-1Ch]
  void *v5; // [esp+14h] [ebp-18h]
  AdvXMLParser::Element *v6; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int v8; // [esp+28h] [ebp-4h]

  v6 = this;
  std::vector<AdvXMLParser::Node *>::begin(v3);
  v8 = 0;
  for ( i = 0; i <= a2; ++i )
  {
    if ( !(unsigned __int8)AdvXMLParser::NodeContainer::FindChild(4, v3) )
    {
      v5 = &AdvXMLParser::CData::null;
      v8 = -1;
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
      return v5;
    }
  }
  v4 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v3);
  v8 = -1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
  return (void *)v4;
}


// address=[0x2f16100]
// Decompiled from void *__thiscall AdvXMLParser::Element::GetCData(AdvXMLParser::Element *this, int a2)
class AdvXMLParser::CData &  AdvXMLParser::Element::GetCData(int a2) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-28h] BYREF
  int v4; // [esp+10h] [ebp-1Ch]
  void *v5; // [esp+14h] [ebp-18h]
  AdvXMLParser::Element *v6; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int v8; // [esp+28h] [ebp-4h]

  v6 = this;
  std::vector<AdvXMLParser::Node *>::begin(v3);
  v8 = 0;
  for ( i = 0; i <= a2; ++i )
  {
    if ( !(unsigned __int8)AdvXMLParser::NodeContainer::FindChild(4, v3) )
    {
      v5 = &AdvXMLParser::CData::null;
      v8 = -1;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
      return v5;
    }
  }
  v4 = *(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v3);
  v8 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
  return (void *)v4;
}


// address=[0x2f161c0]
// Decompiled from void *__thiscall AdvXMLParser::Element::GetPi(AdvXMLParser::Element *this, char *a2, int a3)
class AdvXMLParser::Pi const &  AdvXMLParser::Element::GetPi(char const * a2, int a3)const {
  
  _BYTE v4[12]; // [esp+4h] [ebp-28h] BYREF
  int v5; // [esp+10h] [ebp-1Ch]
  void *v6; // [esp+14h] [ebp-18h]
  AdvXMLParser::Element *v7; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v7 = this;
  std::vector<AdvXMLParser::Node *>::begin(v4);
  v9 = 0;
  for ( i = 0; i <= a3; ++i )
  {
    if ( !(unsigned __int8)AdvXMLParser::NodeContainer::FindChild(a2, 7, v4) )
    {
      v6 = &AdvXMLParser::Pi::null;
      v9 = -1;
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
      return v6;
    }
  }
  v5 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v4);
  v9 = -1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
  return (void *)v5;
}


// address=[0x2f16280]
// Decompiled from void *__thiscall AdvXMLParser::Element::GetPi(AdvXMLParser::Element *this, int a2)
class AdvXMLParser::Pi const &  AdvXMLParser::Element::GetPi(int a2)const {
  
  _BYTE v3[12]; // [esp+4h] [ebp-28h] BYREF
  int v4; // [esp+10h] [ebp-1Ch]
  void *v5; // [esp+14h] [ebp-18h]
  AdvXMLParser::Element *v6; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int v8; // [esp+28h] [ebp-4h]

  v6 = this;
  std::vector<AdvXMLParser::Node *>::begin(v3);
  v8 = 0;
  for ( i = 0; i <= a2; ++i )
  {
    if ( !(unsigned __int8)AdvXMLParser::NodeContainer::FindChild(7, v3) )
    {
      v5 = &AdvXMLParser::Pi::null;
      v8 = -1;
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
      return v5;
    }
  }
  v4 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v3);
  v8 = -1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
  return (void *)v4;
}


// address=[0x2f16340]
// Decompiled from void *__thiscall AdvXMLParser::Element::GetPi(AdvXMLParser::Element *this, char *a2, int a3)
class AdvXMLParser::Pi &  AdvXMLParser::Element::GetPi(char const * a2, int a3) {
  
  _BYTE v4[12]; // [esp+4h] [ebp-28h] BYREF
  int v5; // [esp+10h] [ebp-1Ch]
  void *v6; // [esp+14h] [ebp-18h]
  AdvXMLParser::Element *v7; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v7 = this;
  std::vector<AdvXMLParser::Node *>::begin(v4);
  v9 = 0;
  for ( i = 0; i <= a3; ++i )
  {
    if ( !(unsigned __int8)AdvXMLParser::NodeContainer::FindChild(a2, 7, v4) )
    {
      v6 = &AdvXMLParser::Pi::null;
      v9 = -1;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
      return v6;
    }
  }
  v5 = *(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v4);
  v9 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
  return (void *)v5;
}


// address=[0x2f16400]
// Decompiled from void *__thiscall AdvXMLParser::Element::GetPi(AdvXMLParser::Element *this, int a2)
class AdvXMLParser::Pi &  AdvXMLParser::Element::GetPi(int a2) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-28h] BYREF
  int v4; // [esp+10h] [ebp-1Ch]
  void *v5; // [esp+14h] [ebp-18h]
  AdvXMLParser::Element *v6; // [esp+18h] [ebp-14h]
  int i; // [esp+1Ch] [ebp-10h]
  int v8; // [esp+28h] [ebp-4h]

  v6 = this;
  std::vector<AdvXMLParser::Node *>::begin(v3);
  v8 = 0;
  for ( i = 0; i <= a2; ++i )
  {
    if ( !(unsigned __int8)AdvXMLParser::NodeContainer::FindChild(7, v3) )
    {
      v5 = &AdvXMLParser::Pi::null;
      v8 = -1;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
      return v5;
    }
  }
  v4 = *(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v3);
  v8 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
  return (void *)v4;
}


// address=[0x2f164c0]
// Decompiled from void *__stdcall AdvXMLParser::Element::GetData(void *a1)
std::string  AdvXMLParser::Element::GetData(void a1)const {
  
  std::string::string(a1, (char *)&byte_3AB74EA);
  return a1;
}


// address=[0x2f164f0]
// Decompiled from int __thiscall AdvXMLParser::Element::GetValue(_BYTE *this, int a2)
std::string  AdvXMLParser::Element::GetValue(void a2)const {
  
  _BYTE v3[12]; // [esp+4h] [ebp-80h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-74h] BYREF
  int v5; // [esp+1Ch] [ebp-68h]
  int v6; // [esp+20h] [ebp-64h]
  std::_Iterator_base12 *v7; // [esp+24h] [ebp-60h]
  std::_Iterator_base12 *v8; // [esp+28h] [ebp-5Ch]
  int v9; // [esp+2Ch] [ebp-58h]
  int v10; // [esp+30h] [ebp-54h]
  _BYTE *v11; // [esp+34h] [ebp-50h]
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
  if ( !v11[72] )
    AdvXMLParser::Element::Normalize((int)v14);
  std::string::string(v14);
  v9 |= 1u;
  v15 = -1;
  std::string::~string(v14);
  return a2;
}


// address=[0x2f16640]
// Decompiled from bool __thiscall AdvXMLParser::Element::IsKindOf(AdvXMLParser::Element *this, int a2)
bool  AdvXMLParser::Element::IsKindOf(int a2)const {
  
  return a2 == 1 || AdvXMLParser::Node::IsKindOf(this, a2);
}


// address=[0x2f16670]
// Decompiled from int __thiscall AdvXMLParser::Element::CloneNode(AdvXMLParser::Element *this, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Node *  AdvXMLParser::Element::CloneNode(class AdvXMLParser::NodeContainer & a2)const {
  
  return AdvXMLParser::Element::Clone(this, a2);
}


// address=[0x2f1e4b0]
// Decompiled from AdvXMLParser::Node *__thiscall AdvXMLParser::Element::GetElement(AdvXMLParser::Element *this, const char *a2, int a3)
class AdvXMLParser::Element &  AdvXMLParser::Element::GetElement(char const * a2, int a3) {
  
  AdvXMLParser::Node *Child; // [esp+Ch] [ebp-4h]

  Child = (AdvXMLParser::Node *)AdvXMLParser::NodeContainer::GetChild(this, a2, a3, 1);
  if ( AdvXMLParser::Node::IsNull(Child) )
    return (AdvXMLParser::Node *)&AdvXMLParser::Element::null;
  else
    return Child;
}


// address=[0x2f23c70]
// Decompiled from int __cdecl AdvXMLParser::Element::Parse(struct AdvXMLParser::Parser *a1, struct AdvXMLParser::NodeContainer *a2)
class AdvXMLParser::Element * __cdecl AdvXMLParser::Element::Parse(class AdvXMLParser::Parser & a1, class AdvXMLParser::NodeContainer & a2) {
  
  struct AdvXMLParser::Element *v2; // eax
  AdvXMLParser::Element *v4; // eax
  struct AdvXMLParser::Parser *v5; // [esp-4h] [ebp-28h]
  int v6; // [esp+4h] [ebp-20h]
  int v7; // [esp+8h] [ebp-1Ch]
  _BYTE v8[7]; // [esp+10h] [ebp-14h] BYREF
  bool v9; // [esp+17h] [ebp-Dh] BYREF
  int v10; // [esp+20h] [ebp-4h]

  v9 = 0;
  v2 = AdvXMLParser::Element::ParseTagBegining(a1, &v9, a2);
  std::auto_ptr<AdvXMLParser::Element>::auto_ptr<AdvXMLParser::Element>(v2);
  v10 = 0;
  if ( std::auto_ptr<AdvXMLParser::Element>::get(v8) )
  {
    if ( v9 )
    {
      v7 = std::auto_ptr<AdvXMLParser::Element>::release(v8);
      v10 = -1;
      std::auto_ptr<AdvXMLParser::Element>::~auto_ptr<AdvXMLParser::Element>(v8);
      return v7;
    }
    else
    {
      v4 = (AdvXMLParser::Element *)std::auto_ptr<AdvXMLParser::Element>::operator->(a1);
      AdvXMLParser::Element::ParseContentETag(v4, v5);
      v6 = std::auto_ptr<AdvXMLParser::Element>::release(v8);
      v10 = -1;
      std::auto_ptr<AdvXMLParser::Element>::~auto_ptr<AdvXMLParser::Element>(v8);
      return v6;
    }
  }
  else
  {
    v10 = -1;
    std::auto_ptr<AdvXMLParser::Element>::~auto_ptr<AdvXMLParser::Element>(v8);
    return 0;
  }
}


// address=[0x2f2d020]
// Decompiled from void __thiscall AdvXMLParser::Element::GenerateXML(  AdvXMLParser::Element *this,  struct AdvXMLParser::GenerateContext *a2)
void  AdvXMLParser::Element::GenerateXML(class AdvXMLParser::GenerateContext & a2)const {
  
  int Name; // eax
  int v3; // eax
  _BYTE v4[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-2Ch] BYREF
  std::_Iterator_base12 *v6; // [esp+1Ch] [ebp-20h]
  std::_Iterator_base12 *v7; // [esp+20h] [ebp-1Ch]
  int v8; // [esp+24h] [ebp-18h]
  AdvXMLParser::NodeContainer *v9; // [esp+28h] [ebp-14h]
  char v10; // [esp+2Fh] [ebp-Dh]
  int v11; // [esp+38h] [ebp-4h]

  v9 = this;
  AdvXMLParser::GenerateContext::GenerateStartTagIndentation(a2);
  AdvXMLParser::GenerateContext::operator+=(60);
  Name = AdvXMLParser::Node::GetName(v9);
  AdvXMLParser::GenerateContext::operator+=(Name);
  std::vector<AdvXMLParser::Attribute *>::begin(v5);
  v11 = 0;
  while ( 1 )
  {
    v7 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Attribute *>::end(v4);
    v6 = v7;
    LOBYTE(v11) = 1;
    v10 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator<(v7);
    LOBYTE(v11) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>(v4);
    if ( !v10 )
      break;
    AdvXMLParser::GenerateContext::operator+=(32);
    v8 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator*(v5);
    (*(void (__thiscall **)(int, struct AdvXMLParser::GenerateContext *))(*(_DWORD *)v8 + 20))(v8, a2);
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::operator++(v5);
  }
  v11 = -1;
  std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Attribute *>>>(v5);
  if ( (unsigned __int8)std::vector<AdvXMLParser::Node *>::empty((char *)v9 + 36) )
  {
    AdvXMLParser::GenerateContext::operator+=("/>");
    AdvXMLParser::GenerateContext::EndTag(a2);
  }
  else
  {
    AdvXMLParser::GenerateContext::operator+=(62);
    AdvXMLParser::NodeContainer::GenerateXML(v9, a2);
    AdvXMLParser::GenerateContext::GenerateEndTagIndentation(a2);
    AdvXMLParser::GenerateContext::operator+=("</");
    v3 = AdvXMLParser::Node::GetName(v9);
    AdvXMLParser::GenerateContext::operator+=(v3);
    AdvXMLParser::GenerateContext::operator+=(62);
  }
}


// address=[0x4685658]
// [Decompilation failed for static class AdvXMLParser::Element AdvXMLParser::Element::null]

// address=[0x2f23d50]
// Decompiled from int __cdecl AdvXMLParser::Element::ParseTagBegining(  struct AdvXMLParser::Parser *a1,  bool *a2,  struct AdvXMLParser::NodeContainer *a3)
class AdvXMLParser::Element * __cdecl AdvXMLParser::Element::ParseTagBegining(class AdvXMLParser::Parser & a1, bool & a2, class AdvXMLParser::NodeContainer & a3) {
  
  struct AdvXMLParser::Element *v4; // eax
  struct AdvXMLParser::Attribute *v5; // eax
  int v6; // eax
  AdvXMLParser::Element *v7; // eax
  const struct AdvXMLParser::Attribute *v8; // [esp-4h] [ebp-58h]
  int v9; // [esp-4h] [ebp-58h]
  int v10; // [esp+4h] [ebp-50h]
  int v11; // [esp+8h] [ebp-4Ch]
  _DWORD v12[2]; // [esp+Ch] [ebp-48h] BYREF
  int v13; // [esp+14h] [ebp-40h]
  void *C; // [esp+18h] [ebp-3Ch]
  _BYTE v15[4]; // [esp+1Ch] [ebp-38h] BYREF
  _BYTE v16[7]; // [esp+20h] [ebp-34h] BYREF
  char Char; // [esp+27h] [ebp-2Dh]
  _BYTE v18[28]; // [esp+28h] [ebp-2Ch] BYREF
  int v19; // [esp+50h] [ebp-4h]

  *a2 = 0;
  if ( !AdvXMLParser::Parser::ParseChar(a1, 60) )
    return 0;
  std::string::string();
  v19 = 0;
  if ( !(unsigned __int8)AdvXMLParser::Parser::ParseName(v18) )
    AdvXMLParser::Parser::SyntaxError(a1, 10);
  C = operator new(0x4Cu);
  LOBYTE(v19) = 1;
  if ( C )
    v13 = AdvXMLParser::Element::Element(C, (int)a3, (int)v18);
  else
    v13 = 0;
  v12[1] = v13;
  LOBYTE(v19) = 0;
  std::auto_ptr<AdvXMLParser::Element>::auto_ptr<AdvXMLParser::Element>(v13);
  LOBYTE(v19) = 2;
  while ( AdvXMLParser::Parser::ParseSpaces(a1) )
  {
    v4 = (struct AdvXMLParser::Element *)std::auto_ptr<AdvXMLParser::Element>::operator*();
    v5 = AdvXMLParser::Attribute::Parse(a1, v4);
    std::auto_ptr<AdvXMLParser::Attribute>::auto_ptr<AdvXMLParser::Attribute>(v5);
    LOBYTE(v19) = 3;
    if ( !std::auto_ptr<AdvXMLParser::Attribute>::get(v15) )
    {
      LOBYTE(v19) = 2;
      std::auto_ptr<AdvXMLParser::Attribute>::~auto_ptr<AdvXMLParser::Attribute>(v15);
      break;
    }
    v6 = std::auto_ptr<AdvXMLParser::Attribute>::get(v15);
    v7 = (AdvXMLParser::Element *)std::auto_ptr<AdvXMLParser::Element>::operator->(v6);
    AdvXMLParser::Element::HandleSpecialAttributes(v7, v8);
    v12[0] = std::auto_ptr<AdvXMLParser::Attribute>::release(v15);
    std::auto_ptr<AdvXMLParser::Element>::operator->(v12);
    std::vector<AdvXMLParser::Attribute *>::push_back(v9);
    LOBYTE(v19) = 2;
    std::auto_ptr<AdvXMLParser::Attribute>::~auto_ptr<AdvXMLParser::Attribute>(v15);
  }
  Char = AdvXMLParser::Parser::NextChar(a1);
  if ( Char == 47 )
  {
    if ( AdvXMLParser::Parser::NextChar(a1) != 62 )
      AdvXMLParser::Parser::SyntaxError(a1, 11);
    *a2 = 1;
    v11 = std::auto_ptr<AdvXMLParser::Element>::release(v16);
    LOBYTE(v19) = 0;
    std::auto_ptr<AdvXMLParser::Element>::~auto_ptr<AdvXMLParser::Element>(v16);
    v19 = -1;
    std::string::~string(v18);
    return v11;
  }
  else
  {
    if ( Char != 62 )
      AdvXMLParser::Parser::SyntaxError(a1, 12);
    v10 = std::auto_ptr<AdvXMLParser::Element>::release(v16);
    LOBYTE(v19) = 0;
    std::auto_ptr<AdvXMLParser::Element>::~auto_ptr<AdvXMLParser::Element>(v16);
    v19 = -1;
    std::string::~string(v18);
    return v10;
  }
}


// address=[0x2f23f60]
// Decompiled from char __thiscall AdvXMLParser::Element::ParseETag(AdvXMLParser::Element *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Element::ParseETag(class AdvXMLParser::Parser & a2) {
  
  int Name; // eax
  _BYTE v5[28]; // [esp+Ch] [ebp-2Ch] BYREF
  int v6; // [esp+34h] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseString(a2, "</") )
    return 0;
  std::string::string();
  v6 = 0;
  if ( !(unsigned __int8)AdvXMLParser::Parser::ParseName(v5) )
    AdvXMLParser::Parser::SyntaxError(a2, 10);
  Name = AdvXMLParser::Node::GetName(this);
  if ( (unsigned __int8)std::operator!=<char>(v5, Name) )
    AdvXMLParser::Parser::SyntaxError(a2, 13);
  AdvXMLParser::Parser::ParseSpaces(a2);
  if ( !AdvXMLParser::Parser::ParseChar(a2, 62) )
    AdvXMLParser::Parser::SyntaxError(a2, 12);
  v6 = -1;
  std::string::~string(v5);
  return 1;
}


// address=[0x2f24050]
// Decompiled from int __thiscall AdvXMLParser::Element::ParseContentETag(AdvXMLParser::Element *this, struct AdvXMLParser::Parser *a2)
void  AdvXMLParser::Element::ParseContentETag(class AdvXMLParser::Parser & a2) {
  
  int result; // eax
  char v3[16]; // [esp+0h] [ebp-1Ch] BYREF
  int v4; // [esp+10h] [ebp-Ch]
  AdvXMLParser::Element *v5; // [esp+14h] [ebp-8h]
  char Char; // [esp+1Bh] [ebp-1h]

  v5 = this;
  AdvXMLParser::Bookmark::Bookmark((AdvXMLParser::Bookmark *)v3, a2);
  Char = AdvXMLParser::Parser::NextChar(a2);
  while ( 2 )
  {
    v4 = Char;
    switch ( Char )
    {
      case 0:
        AdvXMLParser::Parser::SyntaxError(a2, 1);
      case 38:
        AdvXMLParser::Parser::PreviousChar(a2);
        AdvXMLParser::NodeContainer::AddText(v5, (struct AdvXMLParser::Bookmark *)v3, 0);
        AdvXMLParser::Element::ParseReference(v5, a2);
        AdvXMLParser::Bookmark::Reset((AdvXMLParser::Bookmark *)v3);
        goto LABEL_12;
      case 60:
        AdvXMLParser::Parser::PreviousChar(a2);
        AdvXMLParser::NodeContainer::AddText(v5, (struct AdvXMLParser::Bookmark *)v3, 0);
        LOBYTE(result) = AdvXMLParser::Element::ParseMarkup(v5, a2);
        if ( (_BYTE)result )
          return result;
        AdvXMLParser::Bookmark::Reset((AdvXMLParser::Bookmark *)v3);
LABEL_12:
        Char = AdvXMLParser::Parser::NextChar(a2);
        continue;
        return result;
      case 93:
        if ( AdvXMLParser::Parser::ParseString(a2, "]>") )
          AdvXMLParser::Parser::SyntaxError(a2, 15);
        goto LABEL_12;
      default:
        if ( !AdvXMLParser::IsXmlChar((AdvXMLParser *)(unsigned __int8)Char, v3[0]) )
          AdvXMLParser::Parser::SyntaxError(a2, 2);
        goto LABEL_12;
    }
  }
}


// address=[0x2f241d0]
// Decompiled from int __thiscall AdvXMLParser::Element::ParseReference(AdvXMLParser::Element *this, struct AdvXMLParser::Parser *a2)
void  AdvXMLParser::Element::ParseReference(class AdvXMLParser::Parser & a2) {
  
  struct AdvXMLParser::Reference *v2; // eax
  struct Node *v3; // eax
  _BYTE v6[4]; // [esp+8h] [ebp-10h] BYREF
  int v7; // [esp+14h] [ebp-4h]

  v2 = AdvXMLParser::Reference::Parse(a2, this);
  std::auto_ptr<AdvXMLParser::Reference>::auto_ptr<AdvXMLParser::Reference>(v2);
  v7 = 0;
  if ( !std::auto_ptr<AdvXMLParser::Reference>::get(v6) )
    AdvXMLParser::Parser::SyntaxError(a2, 6);
  v3 = (struct Node *)std::auto_ptr<AdvXMLParser::Reference>::release(v6);
  AdvXMLParser::NodeContainer::Add(this, v3);
  v7 = -1;
  return std::auto_ptr<AdvXMLParser::Reference>::~auto_ptr<AdvXMLParser::Reference>(v6);
}


// address=[0x2f24260]
// Decompiled from char __thiscall AdvXMLParser::Element::ParseMarkup(AdvXMLParser::Element *this, struct AdvXMLParser::Parser *a2)
bool  AdvXMLParser::Element::ParseMarkup(class AdvXMLParser::Parser & a2) {
  
  struct AdvXMLParser::Comment *v3; // eax
  struct Node *v4; // eax
  struct AdvXMLParser::CData *v5; // eax
  struct Node *v6; // eax
  struct AdvXMLParser::Pi *v7; // eax
  struct Node *v8; // eax
  int v9; // eax
  struct Node *v10; // eax
  _BYTE v11[4]; // [esp+4h] [ebp-28h] BYREF
  _BYTE v12[4]; // [esp+8h] [ebp-24h] BYREF
  _BYTE v13[4]; // [esp+Ch] [ebp-20h] BYREF
  _BYTE v14[4]; // [esp+10h] [ebp-1Ch] BYREF
  struct AdvXMLParser::NodeContainer *v15; // [esp+14h] [ebp-18h]
  char v16; // [esp+1Ch] [ebp-10h]
  char v17; // [esp+1Dh] [ebp-Fh]
  char v18; // [esp+1Eh] [ebp-Eh]
  char v19; // [esp+1Fh] [ebp-Dh]
  int v20; // [esp+28h] [ebp-4h]

  v15 = this;
  if ( AdvXMLParser::Element::ParseETag(this, a2) )
    return 1;
  v3 = AdvXMLParser::Comment::Parse(a2, v15);
  std::auto_ptr<AdvXMLParser::Comment>::auto_ptr<AdvXMLParser::Comment>(v3);
  v20 = 0;
  if ( std::auto_ptr<AdvXMLParser::Comment>::get(v14) )
  {
    v4 = (struct Node *)std::auto_ptr<AdvXMLParser::Comment>::release(v14);
    AdvXMLParser::NodeContainer::Add(v15, v4);
    v19 = 0;
    v20 = -1;
    std::auto_ptr<AdvXMLParser::Comment>::~auto_ptr<AdvXMLParser::Comment>(v14);
    return v19;
  }
  else
  {
    v5 = AdvXMLParser::CData::Parse(a2, v15);
    std::auto_ptr<AdvXMLParser::CData>::auto_ptr<AdvXMLParser::CData>(v5);
    LOBYTE(v20) = 1;
    if ( std::auto_ptr<AdvXMLParser::CData>::get(v13) )
    {
      v6 = (struct Node *)std::auto_ptr<AdvXMLParser::CData>::release(v13);
      AdvXMLParser::NodeContainer::Add(v15, v6);
      v18 = 0;
      LOBYTE(v20) = 0;
      std::auto_ptr<AdvXMLParser::CData>::~auto_ptr<AdvXMLParser::CData>(v13);
      v20 = -1;
      std::auto_ptr<AdvXMLParser::Comment>::~auto_ptr<AdvXMLParser::Comment>(v14);
      return v18;
    }
    else
    {
      v7 = AdvXMLParser::Pi::Parse(a2, v15);
      std::auto_ptr<AdvXMLParser::Pi>::auto_ptr<AdvXMLParser::Pi>(v7);
      LOBYTE(v20) = 2;
      if ( std::auto_ptr<AdvXMLParser::Pi>::get(v12) )
      {
        v8 = (struct Node *)std::auto_ptr<AdvXMLParser::Pi>::release(v12);
        AdvXMLParser::NodeContainer::Add(v15, v8);
        v17 = 0;
        LOBYTE(v20) = 1;
        std::auto_ptr<AdvXMLParser::Pi>::~auto_ptr<AdvXMLParser::Pi>(v12);
        LOBYTE(v20) = 0;
        std::auto_ptr<AdvXMLParser::CData>::~auto_ptr<AdvXMLParser::CData>(v13);
        v20 = -1;
        std::auto_ptr<AdvXMLParser::Comment>::~auto_ptr<AdvXMLParser::Comment>(v14);
        return v17;
      }
      else
      {
        v9 = AdvXMLParser::Element::Parse(a2, v15);
        std::auto_ptr<AdvXMLParser::Element>::auto_ptr<AdvXMLParser::Element>(v9);
        LOBYTE(v20) = 3;
        if ( !std::auto_ptr<AdvXMLParser::Element>::get(v11) )
          AdvXMLParser::Parser::SyntaxError(a2, 14);
        v10 = (struct Node *)std::auto_ptr<AdvXMLParser::Element>::release(v11);
        AdvXMLParser::NodeContainer::Add(v15, v10);
        v16 = 0;
        LOBYTE(v20) = 2;
        std::auto_ptr<AdvXMLParser::Element>::~auto_ptr<AdvXMLParser::Element>(v11);
        LOBYTE(v20) = 1;
        std::auto_ptr<AdvXMLParser::Pi>::~auto_ptr<AdvXMLParser::Pi>(v12);
        LOBYTE(v20) = 0;
        std::auto_ptr<AdvXMLParser::CData>::~auto_ptr<AdvXMLParser::CData>(v13);
        v20 = -1;
        std::auto_ptr<AdvXMLParser::Comment>::~auto_ptr<AdvXMLParser::Comment>(v14);
        return v16;
      }
    }
  }
}


// address=[0x2f244a0]
// Decompiled from void __thiscall AdvXMLParser::Element::HandleSpecialAttributes(  AdvXMLParser::Element *this,  const struct AdvXMLParser::Attribute *a2)
void  AdvXMLParser::Element::HandleSpecialAttributes(class AdvXMLParser::Attribute const *) {
  
  _BYTE v3[28]; // [esp+14h] [ebp-2Ch] BYREF
  int v4; // [esp+3Ch] [ebp-4h]

  AdvXMLParser::Node::GetName(a2);
  if ( !std::string::compare("xml:space") )
  {
    (*(void (__thiscall **)(const struct AdvXMLParser::Attribute *, _BYTE *))(*(_DWORD *)a2 + 8))(a2, v3);
    v4 = 0;
    *((_BYTE *)this + 72) = std::string::compare("preserve") == 0;
    v4 = -1;
    std::string::~string(v3);
  }
}


