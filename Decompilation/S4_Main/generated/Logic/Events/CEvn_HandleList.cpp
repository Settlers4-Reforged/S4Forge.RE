#include "all_headers.h"

// Definitions for class CEvn_HandleList

// address=[0x1356900]
// Decompiled from CEvn_HandleList *__thiscall CEvn_HandleList::CEvn_HandleList(CEvn_HandleList *this)
 CEvn_HandleList::CEvn_HandleList(void) {
  
  std::list<IEvn_Handle *>::list<IEvn_Handle *>((char *)this + 4);
  *(_DWORD *)this = &CEvn_HandleList::_vftable_;
  return this;
}


// address=[0x1356930]
// Decompiled from int __thiscall CEvn_HandleList::~CEvn_HandleList(CEvn_HandleList *this)
 CEvn_HandleList::~CEvn_HandleList(void) {
  
  _BYTE v2[12]; // [esp+4h] [ebp-24h] BYREF
  void *C; // [esp+10h] [ebp-18h]
  void *v4; // [esp+14h] [ebp-14h] BYREF
  CEvn_HandleList *v5; // [esp+18h] [ebp-10h]

  v5 = this;
  *(_DWORD *)this = &CEvn_HandleList::_vftable_;
  while ( !(unsigned __int8)std::list<IEvn_Handle *>::empty((char *)v5 + 4) )
  {
    std::list<IEvn_Handle *>::begin(v2);
    v4 = *(void **)std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::operator*(v2);
    std::list<IEvn_Handle *>::remove(&v4);
    C = v4;
    operator delete(v4);
    std::_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>::~_List_iterator<std::_List_val<std::_List_simple_types<IEvn_Handle *>>>(v2);
  }
  return std::list<IEvn_Handle *>::~list<IEvn_Handle *>();
}


