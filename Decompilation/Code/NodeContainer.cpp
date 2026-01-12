#include "NodeContainer.h"

// Definitions for class NodeContainer

// address=[0x14f3c60]
// Decompiled from _DWORD *__thiscall AdvXMLParser::NodeContainer::Begin(void *this, _DWORD *a2)

struct AdvXMLParser::Node::ConstIteratorRef  AdvXMLParser::NodeContainer::Begin(void)const {
  
  char v3; // [esp-Ch] [ebp-20h] BYREF
  int v4; // [esp-8h] [ebp-1Ch]
  int v5; // [esp-4h] [ebp-18h]
  int v6; // [esp+4h] [ebp-10h]
  char *v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+Ch] [ebp-8h]
  void *v9; // [esp+10h] [ebp-4h]

  v9 = this;
  v8 = 0;
  v7 = &v3;
  v6 = std::vector<AdvXMLParser::Node *>::begin(&v3);
  AdvXMLParser::Node::ConstIteratorRef::ConstIteratorRef(a2, (int)v9 + 36, v3, v4, v5);
  return a2;
}


// address=[0x14f3d40]
// Decompiled from _DWORD *__thiscall AdvXMLParser::NodeContainer::End(void *this, _DWORD *a2)

struct AdvXMLParser::Node::ConstIteratorRef  AdvXMLParser::NodeContainer::End(void)const {
  
  char v3; // [esp-Ch] [ebp-20h] BYREF
  int v4; // [esp-8h] [ebp-1Ch]
  int v5; // [esp-4h] [ebp-18h]
  int v6; // [esp+4h] [ebp-10h]
  char *v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+Ch] [ebp-8h]
  void *v9; // [esp+10h] [ebp-4h]

  v9 = this;
  v8 = 0;
  v7 = &v3;
  v6 = std::vector<AdvXMLParser::Node *>::end(&v3);
  AdvXMLParser::Node::ConstIteratorRef::ConstIteratorRef(a2, (int)v9 + 36, v3, v4, v5);
  return a2;
}


// address=[0x2f13750]
// Decompiled from int __thiscall AdvXMLParser::NodeContainer::NodeContainer(_DWORD *this, int a2, int a3)

 AdvXMLParser::NodeContainer::NodeContainer(class AdvXMLParser::NodeContainer &,std::string const &) {
  
  int v5; // [esp+0h] [ebp-4h]

  AdvXMLParser::Node::Node(a2, a3);
  *this = &AdvXMLParser::NodeContainer::_vftable_;
  std::vector<AdvXMLParser::Node *>::vector<AdvXMLParser::Node *>(this);
  *(_DWORD *)(v5 + 52) = 0;
  return v5;
}


// address=[0x2f13790]
// Decompiled from void __thiscall AdvXMLParser::NodeContainer::~NodeContainer(AdvXMLParser::NodeContainer *this)

 AdvXMLParser::NodeContainer::~NodeContainer(void) {
  
  std::_Iterator_base12 *v1; // eax
  _BYTE v2[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-2Ch] BYREF
  int v4; // [esp+1Ch] [ebp-20h]
  int (__thiscall ***v5)(_DWORD, int); // [esp+20h] [ebp-1Ch]
  int (__thiscall ***v6)(_DWORD, int); // [esp+24h] [ebp-18h]
  boost::exception *v7; // [esp+28h] [ebp-14h]
  char v8; // [esp+2Fh] [ebp-Dh]

  v7 = this;
  *(_DWORD *)this = &AdvXMLParser::NodeContainer::_vftable_;
  std::vector<AdvXMLParser::Node *>::begin(v3);
  while ( 1 )
  {
    v1 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v2);
    v8 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v1);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v2);
    if ( !v8 )
      break;
    v5 = *(int (__thiscall ****)(_DWORD, int))std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v3);
    v6 = v5;
    if ( v5 )
      v4 = (**v6)(v6, 1);
    else
      v4 = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(v3);
  }
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
  std::vector<AdvXMLParser::Node *>::~vector<AdvXMLParser::Node *>();
  AdvXMLParser::Node::~Node(v7);
}


// address=[0x2f13870]
// Decompiled from // public: bool __thiscall AdvXMLParser::NodeContainer::IsEmpty(void)const 
int __thiscall AdvXMLParser::NodeContainer::IsEmpty(char *this)

bool  AdvXMLParser::NodeContainer::IsEmpty(void)const {
  
  return std::vector<AdvXMLParser::Node *>::empty(this + 36);
}


// address=[0x2f13890]
// Decompiled from void __thiscall AdvXMLParser::NodeContainer::AddText(AdvXMLParser::NodeContainer *this, int a2)

void  AdvXMLParser::NodeContainer::AddText(std::string const &) {
  
  struct Node *v2; // [esp+8h] [ebp-18h]

  if ( *((_DWORD *)this + 13) )
  {
    AdvXMLParser::Text::Concatenate(a2);
  }
  else
  {
    if ( operator new(0x40u) )
      v2 = (struct Node *)AdvXMLParser::Text::Text(this, a2);
    else
      v2 = 0;
    AdvXMLParser::NodeContainer::Add(this, v2);
  }
}


// address=[0x2f13940]
// Decompiled from void __thiscall AdvXMLParser::NodeContainer::AddText(
        AdvXMLParser::NodeContainer *this,
        struct AdvXMLParser::Bookmark *a2,
        int a3)

void  AdvXMLParser::NodeContainer::AddText(class AdvXMLParser::Bookmark &,int) {
  
  _BYTE v4[28]; // [esp+8h] [ebp-2Ch] BYREF
  int v5; // [esp+30h] [ebp-4h]

  std::string::string();
  v5 = 0;
  AdvXMLParser::Bookmark::GetSubString(v4, a3);
  AdvXMLParser::Bookmark::Reset(a2);
  AdvXMLParser::NodeContainer::AddText(this, (int)v4);
  v5 = -1;
  std::string::~string(v4);
}


// address=[0x2f139d0]
// Decompiled from int __thiscall AdvXMLParser::NodeContainer::DeleteChildren(AdvXMLParser::NodeContainer *this)

void  AdvXMLParser::NodeContainer::DeleteChildren(void) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-40h] BYREF
  _BYTE v3[12]; // [esp+10h] [ebp-34h] BYREF
  int v4; // [esp+1Ch] [ebp-28h]
  int (__thiscall ***v5)(_DWORD, int); // [esp+20h] [ebp-24h]
  std::_Iterator_base12 *v6; // [esp+24h] [ebp-20h]
  std::_Iterator_base12 *v7; // [esp+28h] [ebp-1Ch]
  AdvXMLParser::NodeContainer *v8; // [esp+2Ch] [ebp-18h]
  int (__thiscall ***v9)(_DWORD, int); // [esp+30h] [ebp-14h]
  char v10; // [esp+37h] [ebp-Dh]
  int v11; // [esp+40h] [ebp-4h]

  v8 = this;
  std::vector<AdvXMLParser::Node *>::begin(v3);
  v11 = 0;
  while ( 1 )
  {
    v7 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v2);
    v6 = v7;
    LOBYTE(v11) = 1;
    v10 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v7);
    LOBYTE(v11) = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v2);
    if ( !v10 )
      break;
    v5 = *(int (__thiscall ****)(_DWORD, int))std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v3);
    v9 = v5;
    if ( v5 )
      v4 = (**v9)(v9, 1);
    else
      v4 = 0;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(v3);
  }
  v11 = -1;
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
  return std::vector<AdvXMLParser::Node *>::clear();
}


// address=[0x2f13ac0]
// Decompiled from int __thiscall AdvXMLParser::NodeContainer::DeleteChild(AdvXMLParser::NodeContainer *this, const struct Node *a2)

void  AdvXMLParser::NodeContainer::DeleteChild(class AdvXMLParser::Node const &) {
  
  char v3; // [esp-Ch] [ebp-34h] BYREF
  int v4; // [esp-8h] [ebp-30h]
  int v5; // [esp-4h] [ebp-2Ch]
  _BYTE v6[12]; // [esp+4h] [ebp-24h] BYREF
  int v7; // [esp+10h] [ebp-18h]
  char *v8; // [esp+14h] [ebp-14h]
  AdvXMLParser::NodeContainer *v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+24h] [ebp-4h]

  v9 = this;
  std::vector<AdvXMLParser::Node *>::begin(v6);
  v10 = 0;
  if ( (unsigned __int8)AdvXMLParser::NodeContainer::FindChild(a2, v6) )
  {
    v8 = &v3;
    v7 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v6);
    AdvXMLParser::NodeContainer::DeleteChild(v3, v4, v5);
    v10 = -1;
    return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v6);
  }
  else
  {
    if ( BBSupportDbgReport(2, "Source\\Xml\\elements.cpp", 265, "false") == 1 )
      __debugbreak();
    v10 = -1;
    return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v6);
  }
}


// address=[0x2f13b90]
// Decompiled from // protected: class AdvXMLParser::Node & __thiscall AdvXMLParser::NodeContainer::GetChild(int)const 
void *__thiscall AdvXMLParser::NodeContainer::GetChild(char *this, int a2)

class AdvXMLParser::Node &  AdvXMLParser::NodeContainer::GetChild(int)const {
  
  if ( a2 >= 0 && a2 < (unsigned int)std::vector<AdvXMLParser::Node *>::size(this + 36) )
    return *(void **)std::vector<AdvXMLParser::Node *>::operator[](a2);
  else
    return AdvXMLParser::Node::null;
}


// address=[0x2f13bd0]
// Decompiled from void *__thiscall AdvXMLParser::NodeContainer::GetChild(AdvXMLParser::NodeContainer *this, int a2, int a3)

class AdvXMLParser::Node &  AdvXMLParser::NodeContainer::GetChild(int,int)const {
  
  _BYTE v4[12]; // [esp+4h] [ebp-2Ch] BYREF
  int v5; // [esp+10h] [ebp-20h]
  void *v6; // [esp+14h] [ebp-1Ch]
  void *v7; // [esp+18h] [ebp-18h]
  AdvXMLParser::NodeContainer *v8; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  int v10; // [esp+2Ch] [ebp-4h]

  v8 = this;
  std::vector<AdvXMLParser::Node *>::begin(v4);
  v10 = 0;
  for ( i = 0; i < a2; ++i )
  {
    if ( !(unsigned __int8)AdvXMLParser::NodeContainer::FindChild(a3, v4) )
    {
      v7 = AdvXMLParser::Node::null;
      v10 = -1;
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
      return v7;
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(v4);
  }
  if ( (unsigned __int8)AdvXMLParser::NodeContainer::FindChild(a3, v4) )
  {
    v5 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v4);
    v10 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
    return (void *)v5;
  }
  else
  {
    v6 = AdvXMLParser::Node::null;
    v10 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
    return v6;
  }
}


// address=[0x2f13cd0]
// Decompiled from void *__thiscall AdvXMLParser::NodeContainer::GetChild(AdvXMLParser::NodeContainer *this, char *a2, int a3, int a4)

class AdvXMLParser::Node &  AdvXMLParser::NodeContainer::GetChild(char const *,int,int)const {
  
  _BYTE v5[12]; // [esp+4h] [ebp-2Ch] BYREF
  int v6; // [esp+10h] [ebp-20h]
  void *v7; // [esp+14h] [ebp-1Ch]
  void *v8; // [esp+18h] [ebp-18h]
  AdvXMLParser::NodeContainer *v9; // [esp+1Ch] [ebp-14h]
  int i; // [esp+20h] [ebp-10h]
  int v11; // [esp+2Ch] [ebp-4h]

  v9 = this;
  std::vector<AdvXMLParser::Node *>::begin(v5);
  v11 = 0;
  for ( i = 0; i < a3; ++i )
  {
    if ( !(unsigned __int8)AdvXMLParser::NodeContainer::FindChild(a2, a4, v5) )
    {
      v8 = AdvXMLParser::Node::null;
      v11 = -1;
      std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v5);
      return v8;
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(v5);
  }
  if ( (unsigned __int8)AdvXMLParser::NodeContainer::FindChild(a2, a4, v5) )
  {
    v6 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v5);
    v11 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v5);
    return (void *)v6;
  }
  else
  {
    v7 = AdvXMLParser::Node::null;
    v11 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v5);
    return v7;
  }
}


// address=[0x2f13de0]
// Decompiled from int __thiscall AdvXMLParser::NodeContainer::Add(AdvXMLParser::NodeContainer *this, struct Node *a2)

void  AdvXMLParser::NodeContainer::Add(class AdvXMLParser::Node *) {
  
  int result; // eax

  if ( this != AdvXMLParser::Node::GetParent((AdvXMLParser::Node *)a2)
    && BBSupportDbgReport(2, "Source\\Xml\\elements.cpp", 198, "this == &pNode->GetParent()") == 1 )
  {
    __debugbreak();
  }
  std::vector<AdvXMLParser::Node *>::push_back(&a2);
  result = ((unsigned __int8 (__thiscall *)(struct Node *, int))a2->lpVtbl->GetTypeInfoCount)(a2, 3);
  if ( !(_BYTE)result )
    *((_DWORD *)this + 13) = 0;
  return result;
}


// address=[0x2f13e50]
// Decompiled from int __thiscall AdvXMLParser::NodeContainer::InsertBefore(
        AdvXMLParser::NodeContainer *this,
        const struct Node *a2,
        struct Node *a3)

void  AdvXMLParser::NodeContainer::InsertBefore(class AdvXMLParser::Node const &,class AdvXMLParser::Node *) {
  
  char v4; // [esp-10h] [ebp-48h] BYREF
  int v5; // [esp-Ch] [ebp-44h]
  int v6; // [esp-8h] [ebp-40h]
  struct Node **v7; // [esp-4h] [ebp-3Ch]
  _BYTE v8[12]; // [esp+4h] [ebp-34h] BYREF
  _BYTE v9[12]; // [esp+10h] [ebp-28h] BYREF
  int v10; // [esp+1Ch] [ebp-1Ch]
  int v11; // [esp+20h] [ebp-18h]
  char *v12; // [esp+24h] [ebp-14h]
  AdvXMLParser::NodeContainer *v13; // [esp+28h] [ebp-10h]
  int v14; // [esp+34h] [ebp-4h]

  v13 = this;
  std::vector<AdvXMLParser::Node *>::begin(v9);
  v14 = 0;
  if ( (unsigned __int8)AdvXMLParser::NodeContainer::FindChild(a2, v9) )
  {
    v7 = &a3;
    v12 = &v4;
    v11 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>((struct std::_Iterator_base12 *)v9);
    v10 = std::vector<AdvXMLParser::Node *>::insert(v8, v4, v5, v6, v7);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v8);
    v14 = -1;
    return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v9);
  }
  else
  {
    if ( BBSupportDbgReport(2, "Source\\Xml\\elements.cpp", 233, "false") == 1 )
      __debugbreak();
    v14 = -1;
    return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v9);
  }
}


// address=[0x2f13f40]
// Decompiled from int __thiscall AdvXMLParser::NodeContainer::InsertAfter(
        AdvXMLParser::NodeContainer *this,
        const struct Node *a2,
        struct Node *a3)

void  AdvXMLParser::NodeContainer::InsertAfter(class AdvXMLParser::Node const &,class AdvXMLParser::Node *) {
  
  struct std::_Iterator_base12 *v4; // eax
  char v5; // [esp-10h] [ebp-68h] BYREF
  int v6; // [esp-Ch] [ebp-64h]
  int v7; // [esp-8h] [ebp-60h]
  struct Node **v8; // [esp-4h] [ebp-5Ch]
  _BYTE v9[12]; // [esp+4h] [ebp-54h] BYREF
  _BYTE v10[12]; // [esp+10h] [ebp-48h] BYREF
  _BYTE v11[12]; // [esp+1Ch] [ebp-3Ch] BYREF
  int v12; // [esp+28h] [ebp-30h]
  int v13; // [esp+2Ch] [ebp-2Ch]
  char *v14; // [esp+30h] [ebp-28h]
  std::_Iterator_base12 *v15; // [esp+34h] [ebp-24h]
  std::_Iterator_base12 *v16; // [esp+38h] [ebp-20h]
  BOOL v17; // [esp+3Ch] [ebp-1Ch]
  AdvXMLParser::NodeContainer *v18; // [esp+40h] [ebp-18h]
  int v19; // [esp+44h] [ebp-14h]
  bool v20; // [esp+4Bh] [ebp-Dh]
  int v21; // [esp+54h] [ebp-4h]

  v18 = this;
  v19 = 0;
  std::vector<AdvXMLParser::Node *>::begin(v11);
  v21 = 0;
  if ( (unsigned __int8)AdvXMLParser::NodeContainer::FindChild(a2, v11) )
  {
    v16 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v10);
    v15 = v16;
    LOBYTE(v21) = 1;
    v19 |= 1u;
    v17 = !(unsigned __int8)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator!=(v16)
       && BBSupportDbgReport(2, "Source\\Xml\\elements.cpp", 249, "it != m_children.end()") == 1;
    v20 = v17;
    v21 = 0;
    if ( (v19 & 1) != 0 )
    {
      v19 &= ~1u;
      std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v10);
    }
    if ( v20 )
      __debugbreak();
    v8 = &a3;
    v4 = (struct std::_Iterator_base12 *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(v11);
    v14 = &v5;
    v13 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
    v12 = std::vector<AdvXMLParser::Node *>::insert(v9, v5, v6, v7, v8);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v9);
    v21 = -1;
    return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v11);
  }
  else
  {
    if ( BBSupportDbgReport(2, "Source\\Xml\\elements.cpp", 245, "false") == 1 )
      __debugbreak();
    v21 = -1;
    return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v11);
  }
}


// address=[0x2f140d0]
// Decompiled from int __thiscall AdvXMLParser::NodeContainer::CloneChildren(
        AdvXMLParser::NodeContainer *this,
        struct AdvXMLParser::NodeContainer *a2)

void  AdvXMLParser::NodeContainer::CloneChildren(class AdvXMLParser::NodeContainer &)const {
  
  struct Node *v2; // eax
  _BYTE v4[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v5[12]; // [esp+10h] [ebp-2Ch] BYREF
  std::_Iterator_base12 *v6; // [esp+1Ch] [ebp-20h]
  std::_Iterator_base12 *v7; // [esp+20h] [ebp-1Ch]
  int v8; // [esp+24h] [ebp-18h]
  AdvXMLParser::NodeContainer *v9; // [esp+28h] [ebp-14h]
  char v10; // [esp+2Fh] [ebp-Dh]
  int v11; // [esp+38h] [ebp-4h]

  v9 = this;
  std::vector<AdvXMLParser::Node *>::begin(v5);
  v11 = 0;
  while ( 1 )
  {
    v7 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v4);
    v6 = v7;
    LOBYTE(v11) = 1;
    v10 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v7);
    LOBYTE(v11) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
    if ( !v10 )
      break;
    v8 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v5);
    v2 = (struct Node *)(*(int (__thiscall **)(int, struct AdvXMLParser::NodeContainer *))(*(_DWORD *)v8 + 16))(v8, a2);
    AdvXMLParser::NodeContainer::Add(a2, v2);
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(v5);
  }
  v11 = -1;
  return std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v5);
}


// address=[0x2f141a0]
// Decompiled from int __thiscall AdvXMLParser::NodeContainer::DeleteChild(void *this, char a2, int a3, int a4)

void  AdvXMLParser::NodeContainer::DeleteChild(class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > >) {
  
  _DWORD v5[4]; // [esp-Ch] [ebp-64h] BYREF
  _BYTE v6[12]; // [esp+4h] [ebp-54h] BYREF
  _BYTE v7[12]; // [esp+10h] [ebp-48h] BYREF
  int v8; // [esp+1Ch] [ebp-3Ch]
  int v9; // [esp+20h] [ebp-38h]
  _DWORD *v10; // [esp+24h] [ebp-34h]
  int v11; // [esp+28h] [ebp-30h]
  int (__thiscall ***v12)(_DWORD, int); // [esp+2Ch] [ebp-2Ch]
  std::_Iterator_base12 *v13; // [esp+30h] [ebp-28h]
  std::_Iterator_base12 *v14; // [esp+34h] [ebp-24h]
  void *v15; // [esp+38h] [ebp-20h]
  BOOL v16; // [esp+3Ch] [ebp-1Ch]
  int (__thiscall ***v17)(_DWORD, int); // [esp+40h] [ebp-18h]
  int v18; // [esp+44h] [ebp-14h]
  bool v19; // [esp+4Bh] [ebp-Dh]
  int v20; // [esp+54h] [ebp-4h]

  v15 = this;
  v18 = 0;
  v20 = 0;
  v14 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v7);
  v13 = v14;
  LOBYTE(v20) = 1;
  v18 |= 1u;
  v16 = !(unsigned __int8)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator!=(v14)
     && BBSupportDbgReport(2, "Source\\Xml\\elements.cpp", 255, "it != m_children.end()") == 1;
  v19 = v16;
  v20 = 0;
  if ( (v18 & 1) != 0 )
  {
    v18 &= ~1u;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v7);
  }
  if ( v19 )
    __debugbreak();
  v12 = *(int (__thiscall ****)(_DWORD, int))std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(&a2);
  v17 = v12;
  if ( v12 )
    v11 = (**v17)(v17, 1);
  else
    v11 = 0;
  v10 = v5;
  v9 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>((struct std::_Iterator_base12 *)&a2);
  v8 = std::vector<AdvXMLParser::Node *>::erase(v6, v5[0], v5[1], v5[2]);
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v6);
  v20 = -1;
  return std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(&a2);
}


// address=[0x2f142f0]
// Decompiled from char __thiscall AdvXMLParser::NodeContainer::FindChild(void *this, int a2, int a3)

bool  AdvXMLParser::NodeContainer::FindChild(int,class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > &)const {
  
  _BYTE v4[12]; // [esp+4h] [ebp-2Ch] BYREF
  std::_Iterator_base12 *v5; // [esp+10h] [ebp-20h]
  std::_Iterator_base12 *v6; // [esp+14h] [ebp-1Ch]
  void *v7; // [esp+18h] [ebp-18h]
  int v8; // [esp+1Ch] [ebp-14h]
  char v9; // [esp+23h] [ebp-Dh]
  int v10; // [esp+2Ch] [ebp-4h]

  v7 = this;
  while ( 1 )
  {
    v6 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v4);
    v5 = v6;
    v10 = 0;
    v9 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v6);
    v10 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
    if ( !v9 )
      break;
    v8 = *(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(a3);
    if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v8 + 12))(v8, a2) )
      return 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(a3);
  }
  return 0;
}


// address=[0x2f143b0]
// Decompiled from char __thiscall AdvXMLParser::NodeContainer::FindChild(void *this, char *Str, int a3)

bool  AdvXMLParser::NodeContainer::FindChild(char const *,class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > &)const {
  
  _DWORD *v3; // eax
  int Name; // eax
  _BYTE v6[12]; // [esp+4h] [ebp-28h] BYREF
  std::_Iterator_base12 *v7; // [esp+10h] [ebp-1Ch]
  std::_Iterator_base12 *v8; // [esp+14h] [ebp-18h]
  void *v9; // [esp+18h] [ebp-14h]
  char v10; // [esp+1Fh] [ebp-Dh]
  int v11; // [esp+28h] [ebp-4h]

  v9 = this;
  while ( 1 )
  {
    v8 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v6);
    v7 = v8;
    v11 = 0;
    v10 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v8);
    v11 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v6);
    if ( !v10 )
      break;
    v3 = (_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(a3);
    Name = AdvXMLParser::Node::GetName(*v3);
    if ( std::operator==<char>(Name, Str) )
      return 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(a3);
  }
  return 0;
}


// address=[0x2f14470]
// Decompiled from char __thiscall AdvXMLParser::NodeContainer::FindChild(void *this, char *Str, int a3, int a4)

bool  AdvXMLParser::NodeContainer::FindChild(char const *,int,class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > &)const {
  
  _DWORD *v4; // eax
  int Name; // eax
  _BYTE v7[12]; // [esp+4h] [ebp-2Ch] BYREF
  std::_Iterator_base12 *v8; // [esp+10h] [ebp-20h]
  std::_Iterator_base12 *v9; // [esp+14h] [ebp-1Ch]
  void *v10; // [esp+18h] [ebp-18h]
  int v11; // [esp+1Ch] [ebp-14h]
  char v12; // [esp+23h] [ebp-Dh]
  int v13; // [esp+2Ch] [ebp-4h]

  v10 = this;
  while ( 1 )
  {
    v9 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v7);
    v8 = v9;
    v13 = 0;
    v12 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v9);
    v13 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v7);
    if ( !v12 )
      break;
    v4 = (_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(a4);
    Name = AdvXMLParser::Node::GetName(*v4);
    if ( std::operator==<char>(Name, Str) )
    {
      v11 = *(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(a4);
      if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v11 + 12))(v11, a3) )
        return 1;
    }
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(a4);
  }
  return 0;
}


// address=[0x2f14550]
// Decompiled from char __thiscall AdvXMLParser::NodeContainer::FindChild(void *this, int a2, int a3)

bool  AdvXMLParser::NodeContainer::FindChild(class AdvXMLParser::Node const &,class std::_Vector_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > &)const {
  
  _BYTE v4[12]; // [esp+4h] [ebp-28h] BYREF
  std::_Iterator_base12 *v5; // [esp+10h] [ebp-1Ch]
  std::_Iterator_base12 *v6; // [esp+14h] [ebp-18h]
  void *v7; // [esp+18h] [ebp-14h]
  char v8; // [esp+1Fh] [ebp-Dh]
  int v9; // [esp+28h] [ebp-4h]

  v7 = this;
  while ( 1 )
  {
    v6 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v4);
    v5 = v6;
    v9 = 0;
    v8 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v6);
    v9 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
    if ( !v8 )
      break;
    if ( *(_DWORD *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(a3) == a2 )
      return 1;
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(a3);
  }
  return 0;
}


// address=[0x2f145f0]
// Decompiled from char __thiscall AdvXMLParser::NodeContainer::FindChild(void *this, int a2, int a3)

bool  AdvXMLParser::NodeContainer::FindChild(int,class std::_Vector_const_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > &)const {
  
  _BYTE v4[12]; // [esp+4h] [ebp-2Ch] BYREF
  std::_Iterator_base12 *v5; // [esp+10h] [ebp-20h]
  std::_Iterator_base12 *v6; // [esp+14h] [ebp-1Ch]
  void *v7; // [esp+18h] [ebp-18h]
  int v8; // [esp+1Ch] [ebp-14h]
  char v9; // [esp+23h] [ebp-Dh]
  int v10; // [esp+2Ch] [ebp-4h]

  v7 = this;
  while ( 1 )
  {
    v6 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v4);
    v5 = v6;
    v10 = 0;
    v9 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v6);
    v10 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
    if ( !v9 )
      break;
    v8 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(a3);
    if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v8 + 12))(v8, a2) )
      return 1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(a3);
  }
  return 0;
}


// address=[0x2f146b0]
// Decompiled from char __thiscall AdvXMLParser::NodeContainer::FindChild(void *this, char *Str, int a3)

bool  AdvXMLParser::NodeContainer::FindChild(char const *,class std::_Vector_const_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > &)const {
  
  _DWORD *v3; // eax
  int Name; // eax
  _BYTE v6[12]; // [esp+4h] [ebp-28h] BYREF
  std::_Iterator_base12 *v7; // [esp+10h] [ebp-1Ch]
  std::_Iterator_base12 *v8; // [esp+14h] [ebp-18h]
  void *v9; // [esp+18h] [ebp-14h]
  char v10; // [esp+1Fh] [ebp-Dh]
  int v11; // [esp+28h] [ebp-4h]

  v9 = this;
  while ( 1 )
  {
    v8 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v6);
    v7 = v8;
    v11 = 0;
    v10 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v8);
    v11 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v6);
    if ( !v10 )
      break;
    v3 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(a3);
    Name = AdvXMLParser::Node::GetName(*v3);
    if ( std::operator==<char>(Name, Str) )
      return 1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(a3);
  }
  return 0;
}


// address=[0x2f14770]
// Decompiled from char __thiscall AdvXMLParser::NodeContainer::FindChild(void *this, char *Str, int a3, int a4)

bool  AdvXMLParser::NodeContainer::FindChild(char const *,int,class std::_Vector_const_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > &)const {
  
  _DWORD *v4; // eax
  int Name; // eax
  _BYTE v7[12]; // [esp+4h] [ebp-2Ch] BYREF
  std::_Iterator_base12 *v8; // [esp+10h] [ebp-20h]
  std::_Iterator_base12 *v9; // [esp+14h] [ebp-1Ch]
  void *v10; // [esp+18h] [ebp-18h]
  int v11; // [esp+1Ch] [ebp-14h]
  char v12; // [esp+23h] [ebp-Dh]
  int v13; // [esp+2Ch] [ebp-4h]

  v10 = this;
  while ( 1 )
  {
    v9 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v7);
    v8 = v9;
    v13 = 0;
    v12 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v9);
    v13 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v7);
    if ( !v12 )
      break;
    v4 = (_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(a4);
    Name = AdvXMLParser::Node::GetName(*v4);
    if ( std::operator==<char>(Name, Str) )
    {
      v11 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(a4);
      if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v11 + 12))(v11, a3) )
        return 1;
    }
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(a4);
  }
  return 0;
}


// address=[0x2f14850]
// Decompiled from char __thiscall AdvXMLParser::NodeContainer::FindChild(void *this, int a2, int a3)

bool  AdvXMLParser::NodeContainer::FindChild(class AdvXMLParser::Node const &,class std::_Vector_const_iterator<class std::_Vector_val<struct std::_Simple_types<class AdvXMLParser::Node *> > > &)const {
  
  _BYTE v4[12]; // [esp+4h] [ebp-28h] BYREF
  std::_Iterator_base12 *v5; // [esp+10h] [ebp-1Ch]
  std::_Iterator_base12 *v6; // [esp+14h] [ebp-18h]
  void *v7; // [esp+18h] [ebp-14h]
  char v8; // [esp+1Fh] [ebp-Dh]
  int v9; // [esp+28h] [ebp-4h]

  v7 = this;
  while ( 1 )
  {
    v6 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v4);
    v5 = v6;
    v9 = 0;
    v8 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v6);
    v9 = -1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
    if ( !v8 )
      break;
    if ( *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(a3) == a2 )
      return 1;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(a3);
  }
  return 0;
}


// address=[0x2f2ce60]
// Decompiled from int __thiscall AdvXMLParser::NodeContainer::GenerateXML(
        AdvXMLParser::NodeContainer *this,
        struct AdvXMLParser::GenerateContext *a2)

void  AdvXMLParser::NodeContainer::GenerateXML(class AdvXMLParser::GenerateContext &)const {
  
  _BYTE v3[12]; // [esp+4h] [ebp-38h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-2Ch] BYREF
  std::_Iterator_base12 *v5; // [esp+1Ch] [ebp-20h]
  std::_Iterator_base12 *v6; // [esp+20h] [ebp-1Ch]
  int v7; // [esp+24h] [ebp-18h]
  AdvXMLParser::NodeContainer *v8; // [esp+28h] [ebp-14h]
  char v9; // [esp+2Fh] [ebp-Dh]
  int v10; // [esp+38h] [ebp-4h]

  v8 = this;
  std::vector<AdvXMLParser::Node *>::begin(v4);
  v10 = 0;
  while ( 1 )
  {
    v6 = (std::_Iterator_base12 *)std::vector<AdvXMLParser::Node *>::end(v3);
    v5 = v6;
    LOBYTE(v10) = 1;
    v9 = std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator<(v6);
    LOBYTE(v10) = 0;
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v3);
    if ( !v9 )
      break;
    v7 = *(_DWORD *)std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator*(v4);
    (*(void (__thiscall **)(int, struct AdvXMLParser::GenerateContext *))(*(_DWORD *)v7 + 20))(v7, a2);
    std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::operator++(v4);
  }
  v10 = -1;
  return std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>::~_Vector_const_iterator<std::_Vector_val<std::_Simple_types<AdvXMLParser::Node *>>>(v4);
}


