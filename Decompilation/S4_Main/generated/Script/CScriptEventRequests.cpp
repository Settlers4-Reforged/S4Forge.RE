#if FALSE
#include "CScriptEventRequests.h"

// Definitions for class CScriptEventRequests

// address=[0x1439f30]
// Decompiled from int __thiscall CScriptEventRequests::Size(CScriptEventRequests *this)
int  CScriptEventRequests::Size(void)const {
  
  return this->m_iSize;
}


// address=[0x15febd0]
// Decompiled from int __thiscall CScriptEventRequests::FindFunction(CScriptEventRequests *this, unsigned int a2)
int  CScriptEventRequests::FindFunction(int a2) {
  
  int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  if ( a2 >= 0x40
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         93,
         "static_cast<unsigned int>(_iScriptFuncId) < CScriptManager::REGISTERED_FUNCTION_MAX") == 1 )
  {
    __debugbreak();
  }
  v3 = -1;
  for ( i = 0; i < this->m_iSize; ++i )
  {
    if ( this->m_aScriptFunc[i] == a2 )
      return i;
  }
  return v3;
}


// address=[0x15fec50]
// Decompiled from void __thiscall CScriptEventRequests::AddFunction(CScriptEventRequests *this, char *_iScriptFuncId)
void  CScriptEventRequests::AddFunction(int _iScriptFuncId) {
  
  int m_iSize; // [esp+0h] [ebp-10h]
  int v3; // [esp+4h] [ebp-Ch]
  int i; // [esp+Ch] [ebp-4h]

  if ( (unsigned int)_iScriptFuncId >= 0x40
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         119,
         "static_cast<unsigned int>(_iScriptFuncId) < CScriptManager::REGISTERED_FUNCTION_MAX") == 1 )
  {
    __debugbreak();
  }
  v3 = -1;
  m_iSize = this->m_iSize;
  for ( i = 0; ; ++i )
  {
    if ( i >= m_iSize )
      goto LABEL_10;
    if ( (char *)this->m_aScriptFunc[i] == _iScriptFuncId )
      break;
    if ( this->m_aScriptFunc[i] == 255 )
    {
      v3 = i;
LABEL_10:
      while ( i < m_iSize )
      {
        if ( (char *)this->m_aScriptFunc[i] == _iScriptFuncId )
          return;
        ++i;
      }
      if ( v3 < 0 )
        v3 = this->m_iSize++;
      if ( this->m_iSize >= 0x40u
        && BBSupportDbgReport(
             2,
             "Script\\GameScriptManager.cpp",
             155,
             "static_cast<unsigned int>(m_iSize) < CScriptManager::REGISTERED_FUNCTION_MAX") == 1 )
      {
        __debugbreak();
      }
      this->m_aScriptFunc[v3] = (unsigned __int8)_iScriptFuncId;
      return;
    }
  }
}


// address=[0x15fed50]
// Decompiled from void __thiscall CScriptEventRequests::RemoveFunction(CScriptEventRequests *this, unsigned int a2)
void  CScriptEventRequests::RemoveFunction(int a2) {
  
  int Function; // [esp+0h] [ebp-Ch]
  int i; // [esp+8h] [ebp-4h]

  if ( a2 >= 0x40
    && BBSupportDbgReport(
         2,
         "Script\\GameScriptManager.cpp",
         167,
         "static_cast<unsigned int>(_iScriptFuncId) < CScriptManager::REGISTERED_FUNCTION_MAX") == 1 )
  {
    __debugbreak();
  }
  Function = CScriptEventRequests::FindFunction(this, a2);
  if ( Function >= 0 )
  {
    this->m_aScriptFunc[Function] = -1;
    for ( i = this->m_iSize - 1; i > 0 && this->m_aScriptFunc[i] == 255; --i )
      ;
    this->m_iSize = i + 1;
  }
}


// address=[0x15fede0]
// Decompiled from void __thiscall CScriptEventRequests::Load(CScriptEventRequests *this, struct IS4Chunk *a2)
void  CScriptEventRequests::Load(class IS4Chunk & a2) {
  
  a2->LoadSignature(72904784);
  a2->LoadUnsigned32(64, 64);
  this->m_iSize = a2->LoadUnsigned32(0, 64);
  a2->Load(this->m_aScriptFunc, 64);
}


// address=[0x15fee40]
// Decompiled from void __thiscall CScriptEventRequests::Save(CScriptEventRequests *this, struct IS4Chunk *a2)
void  CScriptEventRequests::Save(class IS4Chunk & a2) {
  
  a2->SaveSignature(72904784);
  a2->SaveUnsigned32(64);
  a2->SaveUnsigned32(this->m_iSize);
  a2->Save(this->m_aScriptFunc, 0x40u);
}


// address=[0x1601cf0]
// Decompiled from CScriptEventRequests *__thiscall CScriptEventRequests::CScriptEventRequests(CScriptEventRequests *this)
 CScriptEventRequests::CScriptEventRequests(void) {
  
  CScriptEventRequests::Clear(this);
  return this;
}


// address=[0x1601d30]
// Decompiled from int __thiscall CScriptEventRequests::operator[](CScriptEventRequests *this, unsigned int _iIdx)
int  CScriptEventRequests::operator[](int _iIdx)const {
  
  if ( _iIdx >= this->m_iSize
    && BBSupportDbgReport(
         2,
         "d:\\projects\\tshe\\purplelamp\\s4\\source\\s4_main\\script\\GameScriptManager.h",
         86,
         "static_cast<unsigned int>(_iIdx) < static_cast<unsigned int>(m_iSize)") == 1 )
  {
    __debugbreak();
  }
  return this->m_aScriptFunc[_iIdx];
}


// address=[0x16022d0]
// Decompiled from void *__thiscall CScriptEventRequests::Clear(CScriptEventRequests *this)
void  CScriptEventRequests::Clear(void) {
  
  this->m_iSize = 0;
  return memset(this->m_aScriptFunc, 255, sizeof(this->m_aScriptFunc));
}


#endif // Already implemented
