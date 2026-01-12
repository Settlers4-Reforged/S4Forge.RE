#include "EntityRef.h"

// Definitions for class EntityRef

// address=[0x2f14e80]
// Decompiled from AdvXMLParser::EntityRef *__thiscall AdvXMLParser::EntityRef::EntityRef(AdvXMLParser::EntityRef *this, int a2)

 AdvXMLParser::EntityRef::EntityRef(std::string const &) {
  
  _BYTE pExceptionObject[32]; // [esp+8h] [ebp-30h] BYREF
  int v5; // [esp+34h] [ebp-4h]

  AdvXMLParser::Reference::Reference(AdvXMLParser::Node::null, a2);
  v5 = 0;
  *(_DWORD *)this = &AdvXMLParser::EntityRef::_vftable_;
  *((_BYTE *)this + 36) = 0;
  if ( AdvXMLParser::EntityRef::MapReferenceName(this) )
    return this;
  AdvXMLParser::InvalidRefException::InvalidRefException(a2);
  _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVInvalidRefException_AdvXMLParser__);
  return this;
}


// address=[0x2f14f30]
// Decompiled from AdvXMLParser::EntityRef *__thiscall AdvXMLParser::EntityRef::EntityRef(AdvXMLParser::EntityRef *this, int a2, int a3)

 AdvXMLParser::EntityRef::EntityRef(class AdvXMLParser::NodeContainer &,std::string const &) {
  
  AdvXMLParser::Reference::Reference(a2, a3);
  *(_DWORD *)this = &AdvXMLParser::EntityRef::_vftable_;
  *((_BYTE *)this + 36) = 0;
  AdvXMLParser::EntityRef::MapReferenceName(this);
  return this;
}


// address=[0x2f14fa0]
// Decompiled from int __thiscall AdvXMLParser::EntityRef::Clone(AdvXMLParser::EntityRef *this, struct AdvXMLParser::NodeContainer *a2)

class AdvXMLParser::EntityRef *  AdvXMLParser::EntityRef::Clone(class AdvXMLParser::NodeContainer &)const {
  
  int Name; // eax
  int v4; // [esp+4h] [ebp-24h]
  AdvXMLParser::EntityRef *v6; // [esp+10h] [ebp-18h]
  AdvXMLParser::EntityRef *C; // [esp+14h] [ebp-14h]
  _BYTE v8[4]; // [esp+18h] [ebp-10h] BYREF
  int v9; // [esp+24h] [ebp-4h]

  C = (AdvXMLParser::EntityRef *)operator new(0x28u);
  v9 = 0;
  if ( C )
  {
    Name = AdvXMLParser::Node::GetName(this);
    v6 = AdvXMLParser::EntityRef::EntityRef(C, Name);
  }
  else
  {
    v6 = 0;
  }
  v9 = -1;
  std::auto_ptr<AdvXMLParser::EntityRef>::auto_ptr<AdvXMLParser::EntityRef>(v6);
  *(_BYTE *)(std::auto_ptr<AdvXMLParser::EntityRef>::operator->() + 36) = *((_BYTE *)this + 36);
  v4 = std::auto_ptr<AdvXMLParser::EntityRef>::release(v8);
  std::auto_ptr<AdvXMLParser::EntityRef>::~auto_ptr<AdvXMLParser::EntityRef>(v8);
  return v4;
}


// address=[0x2f15050]
// Decompiled from int __thiscall AdvXMLParser::EntityRef::GetData(char *this, int a2)

std::string  AdvXMLParser::EntityRef::GetData(void)const {
  
  std::string::string(1u, this[36]);
  return a2;
}


// address=[0x2f15090]
// Decompiled from int __thiscall AdvXMLParser::EntityRef::GetValue(char *this, int a2)

std::string  AdvXMLParser::EntityRef::GetValue(void)const {
  
  std::string::string(1u, this[36]);
  return a2;
}


// address=[0x2f150d0]
// Decompiled from int __thiscall AdvXMLParser::EntityRef::CloneNode(
        AdvXMLParser::EntityRef *this,
        struct AdvXMLParser::NodeContainer *a2)

class AdvXMLParser::Node *  AdvXMLParser::EntityRef::CloneNode(class AdvXMLParser::NodeContainer &)const {
  
  return AdvXMLParser::EntityRef::Clone(this, a2);
}


// address=[0x2f1cdc0]
// Decompiled from void __thiscall AdvXMLParser::EntityRef::~EntityRef(AdvXMLParser::EntityRef *this)

 AdvXMLParser::EntityRef::~EntityRef(void) {
  
  AdvXMLParser::Reference::~Reference(this);
}


// address=[0x2f23b40]
// Decompiled from int __cdecl AdvXMLParser::EntityRef::Parse(struct AdvXMLParser::Parser *a1, struct AdvXMLParser::NodeContainer *a2)

static class AdvXMLParser::EntityRef * __cdecl AdvXMLParser::EntityRef::Parse(class AdvXMLParser::Parser &,class AdvXMLParser::NodeContainer &) {
  
  AdvXMLParser::EntityRef *v3; // eax
  int v4; // [esp+4h] [ebp-40h]
  AdvXMLParser::EntityRef *v5; // [esp+Ch] [ebp-38h]
  AdvXMLParser::EntityRef *C; // [esp+10h] [ebp-34h]
  _BYTE v7[4]; // [esp+14h] [ebp-30h] BYREF
  _BYTE v8[28]; // [esp+18h] [ebp-2Ch] BYREF
  int v9; // [esp+40h] [ebp-4h]

  if ( !AdvXMLParser::Parser::ParseChar(a1, 38) )
    return 0;
  std::string::string();
  v9 = 0;
  if ( !(unsigned __int8)AdvXMLParser::Parser::ParseName(v8) || !AdvXMLParser::Parser::ParseChar(a1, 59) )
    AdvXMLParser::Parser::SyntaxError(a1, 6);
  C = (AdvXMLParser::EntityRef *)operator new(0x28u);
  LOBYTE(v9) = 1;
  if ( C )
    v5 = AdvXMLParser::EntityRef::EntityRef(C, (int)a2, (int)v8);
  else
    v5 = 0;
  LOBYTE(v9) = 0;
  std::auto_ptr<AdvXMLParser::EntityRef>::auto_ptr<AdvXMLParser::EntityRef>(v5);
  LOBYTE(v9) = 2;
  v3 = (AdvXMLParser::EntityRef *)std::auto_ptr<AdvXMLParser::EntityRef>::operator->();
  if ( !AdvXMLParser::EntityRef::MapReferenceName(v3) )
    AdvXMLParser::Parser::SyntaxError(a1, 9);
  v4 = std::auto_ptr<AdvXMLParser::EntityRef>::release(v7);
  LOBYTE(v9) = 0;
  std::auto_ptr<AdvXMLParser::EntityRef>::~auto_ptr<AdvXMLParser::EntityRef>(v7);
  v9 = -1;
  std::string::~string(v8);
  return v4;
}


// address=[0x2f2cfe0]
// Decompiled from int __thiscall AdvXMLParser::EntityRef::GenerateXML(
        AdvXMLParser::EntityRef *this,
        struct AdvXMLParser::GenerateContext *a2)

void  AdvXMLParser::EntityRef::GenerateXML(class AdvXMLParser::GenerateContext &)const {
  
  int Name; // eax

  AdvXMLParser::GenerateContext::operator+=(38);
  Name = AdvXMLParser::Node::GetName(this);
  AdvXMLParser::GenerateContext::operator+=(Name);
  return AdvXMLParser::GenerateContext::operator+=(59);
}


// address=[0x2f150f0]
// Decompiled from char __thiscall AdvXMLParser::EntityRef::MapReferenceName(AdvXMLParser::EntityRef *this)

bool  AdvXMLParser::EntityRef::MapReferenceName(void) {
  
  int v2; // eax
  _BYTE v3[12]; // [esp+4h] [ebp-48h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-3Ch] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-30h] BYREF
  std::_Iterator_base12 *v6; // [esp+28h] [ebp-24h]
  std::_Iterator_base12 *v7; // [esp+2Ch] [ebp-20h]
  int v8; // [esp+30h] [ebp-1Ch]
  int v9; // [esp+34h] [ebp-18h]
  AdvXMLParser::EntityRef *v10; // [esp+38h] [ebp-14h]
  char v11; // [esp+3Dh] [ebp-Fh]
  char v12; // [esp+3Eh] [ebp-Eh]
  char v13; // [esp+3Fh] [ebp-Dh]
  int v14; // [esp+48h] [ebp-4h]

  v10 = this;
  if ( (unsigned __int8)std::_Tree<std::_Tmap_traits<std::string,char,std::less<std::string>,std::allocator<std::pair<std::string const,char>>,0>>::empty(&AdvXMLParser::s_mapReferences) )
    AdvXMLParser::FillMap();
  v9 = std::_Tree<std::_Tmap_traits<std::string,char,std::less<std::string>,std::allocator<std::pair<std::string const,char>>,0>>::find(
         v4,
         (char *)v10 + 4);
  v8 = v9;
  v14 = 0;
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,char>>>>::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,char>>>>(v9);
  LOBYTE(v14) = 2;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,char>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,char>>>>(v4);
  v7 = (std::_Iterator_base12 *)std::_Tree<std::_Tmap_traits<std::string,char,std::less<std::string>,std::allocator<std::pair<std::string const,char>>,0>>::end(v3);
  v6 = v7;
  LOBYTE(v14) = 3;
  v13 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,char>>>>::operator==(v7);
  LOBYTE(v14) = 2;
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,char>>>>::~_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,char>>>>(v3);
  if ( v13 )
  {
    v12 = 0;
    v14 = -1;
    std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,char>>>>::~_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,char>>>>(v5);
    return v12;
  }
  else
  {
    v2 = std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,char>>>>::operator*(v5);
    *((_BYTE *)v10 + 36) = *(_BYTE *)(v2 + 28);
    v11 = 1;
    v14 = -1;
    std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,char>>>>::~_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const,char>>>>(v5);
    return v11;
  }
}


