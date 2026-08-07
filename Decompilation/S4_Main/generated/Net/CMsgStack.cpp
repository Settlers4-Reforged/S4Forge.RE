#if FALSE
#include "CMsgStack.h"

// Definitions for class CMsgStack

// address=[0x15c49f0]
// Decompiled from bool __thiscall CMsgStack::GetAI(CMsgStack *this)
bool  CMsgStack::GetAI(void) {
  
  return this->m_iAI;
}


// address=[0x15c9d30]
// Decompiled from CMsgStack *__thiscall CMsgStack::CMsgStack(CMsgStack *this)
 CMsgStack::CMsgStack(void) {
  
  std::list<CNet_Event>::list<CNet_Event>(&this->this_list);
  this->__vftable = &CMsgStack::_vftable_;
  this->m_iExpectedSize = -1;
  this->m_iAI = 0;
  this->m_iChangeTime = 0;
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

  while ( 1 )
  {
    result = (unsigned __int8)std::list<CNet_Event>::empty(&this->this_list, this);
    if ( (_BYTE)result )
    {
      break;
    }
    std::list<CNet_Event>::pop_front(&this->this_list);
  }
  return result;
}


// address=[0x15c9dc0]
// Decompiled from struct CNet_Event *__thiscall CMsgStack::GetMsg(CMsgStack *this, struct CNet_Event *__return_ptr retstr)
class CNet_Event  CMsgStack::GetMsg(void retstr) {
  
  struct boost::exception_detail::clone_base *v2; // eax
  CNet_Event v5; // [esp+Ch] [ebp-30h] BYREF
  int v6; // [esp+38h] [ebp-4h]

  v2 = (struct boost::exception_detail::clone_base *)std::list<CNet_Event>::front(&this->this_list);
  CNet_Event::CNet_Event(v2);
  v6 = 0;
  std::list<CNet_Event>::pop_front(&this->this_list);
  CNet_Event::CNet_Event((struct boost::exception_detail::clone_base *)&v5);
  v6 = -1;
  CNet_Event::~CNet_Event(&v5);
  return retstr;
}


// address=[0x15c9e60]
// Decompiled from void __thiscall CMsgStack::AddMsg(CMsgStack *this, struct CNet_Event *a2)
void  CMsgStack::AddMsg(class CNet_Event & a2) {
  
  std::list<CNet_Event>::push_back(a2);
  this->m_iChangeTime = timeGetTime();
}


// address=[0x15c9e90]
// Decompiled from bool __thiscall CMsgStack::IsValid(CMsgStack *this)
bool  CMsgStack::IsValid(void) {
  
  int v2; // [esp+4h] [ebp-8h]

  if ( !CMsgStack::IsSizeAlreadySet(this) )
  {
    return 0;
  }
  v2 = std::list<CNet_Event>::size(&this->this_list);
  if ( v2 > this->m_iExpectedSize )
  {
    CTrace::Print("MsgStacks.cpp: Message stack is: %d expected: %d!", v2, this->m_iExpectedSize);
  }
  return this->m_iExpectedSize == v2;
}


// address=[0x15c9f00]
// Decompiled from void __thiscall CMsgStack::SetExpectedSize(CMsgStack *this, int a2)
void  CMsgStack::SetExpectedSize(int a2) {
  
  this->m_iExpectedSize = a2;
  this->m_iChangeTime = timeGetTime();
}


// address=[0x15c9f30]
// Decompiled from void __thiscall CMsgStack::Sort(CMsgStack *this)
void  CMsgStack::Sort(void) {
  
  std::list<CNet_Event>::sort(&this->this_list, this);
}


// address=[0x15c9f50]
// Decompiled from char __thiscall CMsgStack::IsInStack(CMsgStack *this, unsigned __int8 _iId)
bool  CMsgStack::IsInStack(unsigned char _iId) {
  
  _BYTE v3[12]; // [esp+4h] [ebp-40h] BYREF
  _BYTE v4[12]; // [esp+10h] [ebp-34h] BYREF
  std::_Iterator_base12 *v5[4]; // [esp+1Ch] [ebp-28h] BYREF
  std::_Iterator_base12 *v6; // [esp+2Ch] [ebp-18h]
  char v8; // [esp+35h] [ebp-Fh]
  char v9; // [esp+36h] [ebp-Eh]
  char v10; // [esp+37h] [ebp-Dh]
  int v11; // [esp+40h] [ebp-4h]

  std::list<CNet_Event>::begin((int)v5);
  v11 = 0;
  while ( 1 )
  {
    v6 = (std::_Iterator_base12 *)std::list<CNet_Event>::end(v4);
    v5[3] = v6;
    LOBYTE(v11) = 1;
    v10 = std::_List_const_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::operator!=(v6);
    LOBYTE(v11) = 0;
    std::_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>(v4);
    if ( !v10 )
    {
      break;
    }
    if ( std::_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::operator*(v5)->m_iMsgNr == _iId )
    {
      v9 = 1;
      v11 = -1;
      std::_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>(v5);
      return v9;
    }
    std::_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::operator++(v3, 0);
    std::_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>(v3);
  }
  v8 = 0;
  v11 = -1;
  std::_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>::~_List_iterator<std::_List_val<std::_List_simple_types<CNet_Event>>>(v5);
  return v8;
}


// address=[0x15cadc0]
// Decompiled from bool __thiscall CMsgStack::IsSizeAlreadySet(CMsgStack *this)
bool  CMsgStack::IsSizeAlreadySet(void) {
  
  return this->m_iExpectedSize != -1;
}


// address=[0x15cc590]
// Decompiled from int __thiscall CMsgStack::ClearAndValidate(CMsgStack *this)
void  CMsgStack::ClearAndValidate(void) {
  
  this->m_iExpectedSize = 0;
  return CMsgStack::Clear(this);
}


// address=[0x15cc5c0]
// Decompiled from int __thiscall CMsgStack::GetExpectedSize(CMsgStack *this)
int  CMsgStack::GetExpectedSize(void) {
  
  return this->m_iExpectedSize;
}


// address=[0x15cc5e0]
// Decompiled from int __thiscall CMsgStack::Invalidate(CMsgStack *this)
void  CMsgStack::Invalidate(void) {
  
  this->m_iExpectedSize = -1;
  return CMsgStack::Clear(this);
}


// address=[0x15cc610]
// Decompiled from bool __thiscall CMsgStack::IsEmpty(CMsgStack *this)
bool  CMsgStack::IsEmpty(void) {
  
  return std::list<CNet_Event>::size(&this->this_list) == 0;
}


// address=[0x15cc650]
// Decompiled from void __thiscall CMsgStack::SetAI(CMsgStack *this, bool a2)
void  CMsgStack::SetAI(bool a2) {
  
  this->m_iAI = a2;
}


#endif // Already implemented
