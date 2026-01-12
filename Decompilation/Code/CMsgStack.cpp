#include "CMsgStack.h"

// Definitions for class CMsgStack

// address=[0x15c49f0]
// Decompiled from char __thiscall CMsgStack::GetAI(CMsgStack *this)
bool  CMsgStack::GetAI(void) {
  
  return *((_BYTE *)this + 20);
}


// address=[0x15c9d30]
// Decompiled from _DWORD *__thiscall sub_19C9D30(_DWORD *this)
 CMsgStack::CMsgStack(void) {
  
  std::list<CNet_Event>::list<CNet_Event>(this + 1);
  *this = &CMsgStack::_vftable_;
  this[4] = -1;
  *((_BYTE *)this + 20) = 0;
  this[6] = 0;
  return this;
}


// address=[0x15c9d70]
// Decompiled from void __thiscall CMsgStack::~CMsgStack(boost::exception *this)
 CMsgStack::~CMsgStack(void) {
  
  *(_DWORD *)this = &CMsgStack::_vftable_;
  std::list<CNet_Event>::~list<CNet_Event>();
}


// address=[0x15c9d90]
// Decompiled from int __thiscall CMsgStack::Clear(CMsgStack *this)
void  CMsgStack::Clear(void) {
  
  int result; // eax
  CMsgStack *v2; // [esp+0h] [ebp-4h]
  int v3; // [esp+0h] [ebp-4h]
  int savedregs; // [esp+4h] [ebp+0h]

  v2 = this;
  while ( 1 )
  {
    result = (unsigned __int8)std::list<CNet_Event>::empty((char *)v2 + 4, v2);
    if ( (_BYTE)result )
      break;
    std::list<CNet_Event>::pop_front(v3, savedregs);
  }
  return result;
}


// address=[0x15c9dc0]
// Decompiled from int __stdcall CMsgStack::GetMsg(int a1)
class CNet_Event  CMsgStack::GetMsg(void) {
  
  struct boost::exception_detail::clone_base *v1; // eax
  _BYTE v3[32]; // [esp+Ch] [ebp-30h] BYREF
  int v4; // [esp+38h] [ebp-4h]

  v1 = (struct boost::exception_detail::clone_base *)std::list<CNet_Event>::front();
  CNet_Event::CNet_Event(v1);
  v4 = 0;
  std::list<CNet_Event>::pop_front();
  CNet_Event::CNet_Event((struct boost::exception_detail::clone_base *)v3);
  v4 = -1;
  CNet_Event::~CNet_Event((CNet_Event *)v3);
  return a1;
}


// address=[0x15c9e60]
// Decompiled from DWORD __thiscall CMsgStack::AddMsg(CMsgStack *this, struct CNet_Event *a2)
void  CMsgStack::AddMsg(class CNet_Event &) {
  
  DWORD result; // eax

  std::list<CNet_Event>::push_back(a2);
  result = timeGetTime();
  *((_DWORD *)this + 6) = result;
  return result;
}


// address=[0x15c9e90]
// Decompiled from bool __thiscall CMsgStack::IsValid(CMsgStack *this)
bool  CMsgStack::IsValid(void) {
  
  int v2; // [esp+4h] [ebp-8h]

  if ( !CMsgStack::IsSizeAlreadySet(this) )
    return 0;
  v2 = std::list<CNet_Event>::size((char *)this + 4);
  if ( v2 > *((_DWORD *)this + 4) )
    CTrace::Print("MsgStacks.cpp: Message stack is: %d expected: %d!", v2, *((_DWORD *)this + 4));
  return *((_DWORD *)this + 4) == v2;
}


// address=[0x15c9f00]
// Decompiled from DWORD __thiscall sub_19C9F00(_DWORD *this, int a2)
void  CMsgStack::SetExpectedSize(int) {
  
  DWORD result; // eax

  this[4] = a2;
  result = timeGetTime();
  this[6] = result;
  return result;
}


// address=[0x15c9f30]
// Decompiled from void __thiscall CMsgStack::Sort(CDaoIndexFieldInfo *this)
void  CMsgStack::Sort(void) {
  
  std::list<CNet_Event>::sort((char *)this + 4, this);
}


// address=[0x15c9f50]
// Decompiled from char __thiscall CMsgStack::IsInStack(CMsgStack *this, unsigned __int8 a2)
bool  CMsgStack::IsInStack(unsigned char) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-40h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-34h] BYREF
  _BYTE v5[12]; // [esp+1Ch] [ebp-28h] BYREF
  std::_Iterator_base12 *v6; // [esp+28h] [ebp-1Ch]
  std::_Iterator_base12 *v7; // [esp+2Ch] [ebp-18h]
  CMsgStack *v8; // [esp+30h] [ebp-14h]
  char v9; // [esp+35h] [ebp-Fh]
  char v10; // [esp+36h] [ebp-Eh]
  char v11; // [esp+37h] [ebp-Dh]
  int v12; // [esp+40h] [ebp-4h]

  v8 = this;
  std::list<CNet_Event>::begin(v5);
  v12 = 0;
  while ( 1 )
  {
    v7 = (std::_Iterator_base12 *)std::list<CNet_Event>::end(v4);
    v6 = v7;
    LOBYTE(v12) = 1;
    v11 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::operator!=(v7);
    LOBYTE(v12) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>(v4);
    if ( !v11 )
      break;
    if ( *(unsigned __int8 *)(std::_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::operator*(v5)
                            + 20) == a2 )
    {
      v10 = 1;
      v12 = -1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>(v5);
      return v10;
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::operator++(v3, 0);
    std::_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>(v3);
  }
  v9 = 0;
  v12 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>(v5);
  return v9;
}


// address=[0x15cadc0]
// Decompiled from bool __thiscall CMsgStack::IsSizeAlreadySet(CMsgStack *this)
bool  CMsgStack::IsSizeAlreadySet(void) {
  
  return *((_DWORD *)this + 4) != -1;
}


// address=[0x15cc590]
// Decompiled from int __thiscall CMsgStack::ClearAndValidate(CMsgStack *this)
void  CMsgStack::ClearAndValidate(void) {
  
  *((_DWORD *)this + 4) = 0;
  return CMsgStack::Clear(this);
}


// address=[0x15cc5c0]
// Decompiled from int __thiscall CMsgStack::GetExpectedSize(CMsgStack *this)
int  CMsgStack::GetExpectedSize(void) {
  
  return *((_DWORD *)this + 4);
}


// address=[0x15cc5e0]
// Decompiled from int __thiscall CMsgStack::Invalidate(CMsgStack *this)
void  CMsgStack::Invalidate(void) {
  
  *((_DWORD *)this + 4) = -1;
  return CMsgStack::Clear(this);
}


// address=[0x15cc610]
// Decompiled from bool __thiscall CMsgStack::IsEmpty(CMsgStack *this)
bool  CMsgStack::IsEmpty(void) {
  
  return std::list<CNet_Event>::size((char *)this + 4) == 0;
}


// address=[0x15cc650]
// Decompiled from CMsgStack *__thiscall CMsgStack::SetAI(CMsgStack *this, bool a2)
void  CMsgStack::SetAI(bool) {
  
  CMsgStack *result; // eax

  result = this;
  *((_BYTE *)this + 20) = a2;
  return result;
}


